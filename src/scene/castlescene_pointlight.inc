{%MainUnit castlescene.pas}
{
  Copyright 2022-2024 Michalis Kamburelis.

  This file is part of "Castle Game Engine".

  "Castle Game Engine" is free software; see the file COPYING.txt,
  included in this distribution, for details about the copyright.

  "Castle Game Engine" is distributed in the hope that it will be useful,
  but WITHOUT ANY WARRANTY; without even the implied warranty of
  MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.

  ----------------------------------------------------------------------------
}

{ Point light. }

{$ifdef read_interface}

type
  { Point light is a point in 3D space that shines uniformly in all directions.
    The rotation of this transformation doesn't matter.

    See @url(https://www.web3d.org/documents/specifications/19775-1/V3.3/Part01/components/lighting.html#PointLight
    X3D PointLight specification) for various details. }
  TCastlePointLight = class(TCastlePunctualLight)
  strict private
    { Same thing as FLightNode, but with proper type. }
    FPointLight: TPointLightNode;

    FColor: TCastleColorRGB;
    FAttenuation: TVector3;
    FIntensity: Single;
    FRadius: Single;

    procedure SetColor(const Value: TCastleColorRGB);
    procedure SetAttenuation(const Value: TVector3);
    procedure SetIntensity(const Value: Single);
    procedure SetRadius(const Value: Single);
  public
    const
      DefaultRadius = 100.0;
      DefaultIntensity = 100.0;

    constructor Create(AOwner: TComponent); override;
    destructor Destroy; override;
    function PropertySections(const PropertyName: String): TPropertySections; override;

    { Light color shining over surface. By default white. }
    property Color: TCastleColorRGB read FColor write SetColor;

    { Attenuation determines how quickly light intensity falls off with distance.
      By default Vector3(0, 0, 1), which means light falls off according to inverse square law. }
    property Attenuation: TVector3 read FAttenuation write SetAttenuation;
  published
    { Intensity, multiplied by color. Can be anything >= 0.
      Intuitively, how bright is the light.

      Following @url(https://github.com/KhronosGroup/glTF/blob/main/extensions/2.0/Khronos/KHR_lights_punctual/README.md glTF lights specification),
      the point light's intensity physical unit
      is luminous intensity in candela (lm/sr).
      This is exactly like TCastleSpotLight, but different than TCastleDirectionalLight.

      The default intensity is 100.0, which is a reasonable value for a point/spot light,
      it remains bright for a few meters around the light source. }
    property Intensity: Single read FIntensity write SetIntensity {$ifdef FPC}default DefaultIntensity{$endif};

    { Light doesn't shine at all outside of a sphere with this radius.
      For performance reasons, set this as small as possible, to avoid even considering
      this light at further shapes.
      Set to -1 to have no limit. }
    property Radius: Single read FRadius write SetRadius {$ifdef FPC}default DefaultRadius{$endif};

  {$define read_interface_class}
  {$I auto_generated_persistent_vectors/tcastlepointlight_persistent_vectors.inc}
  {$undef read_interface_class}
  end;

{$endif read_interface}

{$ifdef read_implementation}

constructor TCastlePointLight.Create(AOwner: TComponent);
begin
  inherited;

  // defaults
  FIntensity := DefaultIntensity;
  FRadius := DefaultRadius;
  FAttenuation := Vector3(0, 0, 1);
  FColor := WhiteRGB;

  // initialize light node
  FPointLight := TPointLightNode.Create;
  LightNode := FPointLight;
  FPunctualLight := FPointLight;

  // apply TCastlePointLight defaults to FPointLight
  FPointLight.Color := FColor;
  FPointLight.Attenuation := FAttenuation;
  FPointLight.Intensity := FIntensity;
  FPointLight.Radius := FRadius;

  // initialize Gizmo
  if Gizmo <> nil then
    if InternalCastleDesignData <> '' then
      Gizmo.SetIconUrl(InternalCastleDesignData + 'gizmos/light/light_point.png');

  {$define read_implementation_constructor}
  {$I auto_generated_persistent_vectors/tcastlepointlight_persistent_vectors.inc}
  {$undef read_implementation_constructor}
end;

destructor TCastlePointLight.Destroy;
begin
  {$define read_implementation_destructor}
  {$I auto_generated_persistent_vectors/tcastlepointlight_persistent_vectors.inc}
  {$undef read_implementation_destructor}
  inherited;
end;

function TCastlePointLight.PropertySections(const PropertyName: String): TPropertySections;
begin
  if ArrayContainsString(PropertyName, ['ColorPersistent',
      'AttenuationPersistent', 'Intensity', 'Radius']) then
    Result := [psBasic]
  else
    Result := inherited PropertySections(PropertyName);
end;

procedure TCastlePointLight.SetColor(const Value: TCastleColorRGB);
begin
  if not TCastleColorRGB.PerfectlyEquals(FColor, Value) then
  begin
    FColor := Value;
    FPointLight.Color := Value;
  end;
end;

procedure TCastlePointLight.SetAttenuation(const Value: TVector3);
begin
  if not TVector3.PerfectlyEquals(FAttenuation, Value) then
  begin
    FAttenuation := Value;
    FPointLight.Attenuation := Value;
  end;
end;

procedure TCastlePointLight.SetIntensity(const Value: Single);
begin
  if FIntensity <> Value then
  begin
    FIntensity := Value;
    FPointLight.Intensity := Value;
  end;
end;

procedure TCastlePointLight.SetRadius(const Value: Single);
begin
  if FRadius <> Value then
  begin
    FRadius := Value;
    FPointLight.Radius := Value;
  end;
end;

{$define read_implementation_methods}
{$I auto_generated_persistent_vectors/tcastlepointlight_persistent_vectors.inc}
{$undef read_implementation_methods}

{$endif read_implementation}
