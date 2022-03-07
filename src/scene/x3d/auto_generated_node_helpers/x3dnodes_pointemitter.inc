{ -*- buffer-read-only: t -*-

  Copyright 2015-2022 Michalis Kamburelis.

  This file is part of "Castle Game Engine".

  "Castle Game Engine" is free software; see the file COPYING.txt,
  included in this distribution, for details about the copyright.

  "Castle Game Engine" is distributed in the hope that it will be useful,
  but WITHOUT ANY WARRANTY; without even the implied warranty of
  MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.

  ----------------------------------------------------------------------------
}

{ Automatically generated node properties.

  Do not edit this file manually!
  To add new properties:
  - add them to the text files in tools/internal/x3d-nodes-to-pascal/nodes-specification/ ,
  - and regenerate include files by running x3d-nodes-to-pascal .

  The documentation for properties should go to x3dnodes_documentation.txt . }

{$ifdef read_interface}

  strict private
    function GetDirection: TVector3;
    procedure SetDirection(const Value: TVector3);
    function GetPosition: TVector3;
    procedure SetPosition(const Value: TVector3);
  public
    procedure CreateNode; override;
    class function ClassX3DType: string; override;

    strict private FFdDirection: TSFVec3f;
    { X3D field "direction". } { }
    public property FdDirection: TSFVec3f read FFdDirection;
    { X3D field "direction". } { }
    property Direction: TVector3 read GetDirection write SetDirection;

    strict private FFdPosition: TSFVec3f;
    { X3D field "position". } { }
    public property FdPosition: TSFVec3f read FFdPosition;
    { X3D field "position". } { }
    property Position: TVector3 read GetPosition write SetPosition;

{$endif read_interface}

{$ifdef read_implementation}

{ TPointEmitterNode ----------------------------------------------- }

function TPointEmitterNode.GetDirection: TVector3;
begin
  Result := FdDirection.Value;
end;

procedure TPointEmitterNode.SetDirection(const Value: TVector3);
begin
  FdDirection.Send(Value);
end;

function TPointEmitterNode.GetPosition: TVector3;
begin
  Result := FdPosition.Value;
end;

procedure TPointEmitterNode.SetPosition(const Value: TVector3);
begin
  FdPosition.Send(Value);
end;

class function TPointEmitterNode.ClassX3DType: String;
begin
  Result := 'PointEmitter';
end;

procedure TPointEmitterNode.CreateNode;
begin
  inherited;

  FFdDirection := TSFVec3f.Create(Self, True, 'direction', Vector3(0, 1, 0));
   FdDirection.ChangeAlways := chVisibleNonGeometry;
  AddField(FFdDirection);

  FFdPosition := TSFVec3f.Create(Self, True, 'position', Vector3(0, 0, 0));
   FdPosition.ChangeAlways := chVisibleNonGeometry;
  AddField(FFdPosition);
end;

{$endif read_implementation}