uniform vec4 castle_MaterialDiffuseAlpha;
uniform vec3 castle_MaterialAmbient;
uniform vec3 castle_MaterialSpecular;
uniform float castle_MaterialShininess;
/* Color summed with all the lights:
   Material emissive color + material ambient color * global (light model) ambient.
   (similar to old gl_Front/BackLightModelProduct.sceneColor in deprecated GLSL versions.)
*/
uniform vec3 castle_SceneColor;
uniform vec4 castle_UnlitColor;

void calculate_lighting(out vec4 result, const in vec4 vertex_eye, const in vec3 normal_eye)
{
#ifdef LIT
  /* Two-sided lighting in Gouraud shading:
     flip the normal vector to correspond to the face side that we actually see.

     Note that we don't flip the normal_eye (we only flip the
     normal_for_lighting), as normal_eye may be useful also for other
     calculations, e.g. cubemap reflections, that don't want this flippping
     (testcase: demo-models/cube_environment_mapping/cubemap_generated_in_dynamic_world.x3dv )

     This is commented out, because it's not perfect, and I'm not sure can
     we efficiently do artifact-free version of two-sided lighting.
     Reproduction of the problem:
     - demo-models/cube_environment_mapping/cubemap_generated_in_dynamic_world.x3dv,
       look at the back side of the box.
     - demo-models/fog/fog_linear, rotate in Examine and look at the thin water
       edges.

     The problem: We base our flipping on normal_eye,
     which may be a smoothed (per-vertex) normal vector.

     - We cannot calculate here reliably per-face vector (fragment shaders
       can do a trick with dFdx, see
       https://makc3d.wordpress.com/2015/09/17/alternative-to-gl_frontfacing/ ,
       but dFdx is only available in fragment shader).

     - Fully-correct solutions are inefficient:
       - To pass to vertex shader a face_normal in a special uniform
         means that we have to pass extra data, and also that we have to
         split vertexes to not share vertexes across faces.
       - Calculating light 2x times and then letting fragment shader to choose
         which side to show (this is what fixed-function does, I think).

     - If you're OK with being correct (not fast), you can use Phong shading
       where two-sided lighting works easily.
  */
  /* vec3 normal_for_lighting = (normal_eye.z > 0.0 ? normal_eye : -normal_eye); */

  vec4 material_diffuse_alpha;

  #ifdef COLOR_PER_VERTEX
  material_diffuse_alpha = castle_ColorPerVertex;
  #else
  material_diffuse_alpha = castle_MaterialDiffuseAlpha;
  #endif

  result = vec4(castle_SceneColor, material_diffuse_alpha.a);

  /* PLUG: add_light (result, vertex_eye, normal_eye, material_diffuse_alpha) */

  /* Clamp sum of lights colors to be <= 1. See template_phong.fs for comments. */
  result.rgb = min(result.rgb, 1.0);
#else
  /* Unlit case.
     See shading_phong.fs for comments when this is used.
  */
  result = castle_UnlitColor;
#endif
}