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
    function GetClosed: Boolean;
    procedure SetClosed(const Value: Boolean);
    function GetNormalizeVelocity: Boolean;
    procedure SetNormalizeVelocity(const Value: Boolean);
  public
    procedure CreateNode; override;
    class function ClassX3DType: string; override;

    strict private FFdClosed: TSFBool;
    { X3D field "closed". } { }
    public property FdClosed: TSFBool read FFdClosed;
    { X3D field "closed". } { }
    property Closed: Boolean read GetClosed write SetClosed;

    strict private FFdKeyValue: TMFVec3f;
    { X3D field "keyValue". } { }
    public property FdKeyValue: TMFVec3f read FFdKeyValue;
    { Set X3D field "keyValue". } { }
    procedure SetKeyValue(const Value: array of TVector3); overload;
    { Set X3D field "keyValue". } { }
    procedure SetKeyValue(const Value: TVector3List); overload;

    strict private FFdKeyVelocity: TMFVec3f;
    { X3D field "keyVelocity". } { }
    public property FdKeyVelocity: TMFVec3f read FFdKeyVelocity;
    { Set X3D field "keyVelocity". } { }
    procedure SetKeyVelocity(const Value: array of TVector3); overload;
    { Set X3D field "keyVelocity". } { }
    procedure SetKeyVelocity(const Value: TVector3List); overload;

    strict private FFdNormalizeVelocity: TSFBool;
    { X3D field "normalizeVelocity". } { }
    public property FdNormalizeVelocity: TSFBool read FFdNormalizeVelocity;
    { X3D field "normalizeVelocity". } { }
    property NormalizeVelocity: Boolean read GetNormalizeVelocity write SetNormalizeVelocity;

    strict private FEventValue_changed: TSFVec3fEvent;
    { X3D out event "value_changed". } { }
    public property EventValue_changed: TSFVec3fEvent read FEventValue_changed;

{$endif read_interface}

{$ifdef read_implementation}

{ TSplinePositionInterpolatorNode ----------------------------------------------- }

function TSplinePositionInterpolatorNode.GetClosed: Boolean;
begin
  Result := FdClosed.Value;
end;

procedure TSplinePositionInterpolatorNode.SetClosed(const Value: Boolean);
begin
  FdClosed.Send(Value);
end;

procedure TSplinePositionInterpolatorNode.SetKeyValue(const Value: array of TVector3);
begin
  FdKeyValue.Send(Value);
end;

procedure TSplinePositionInterpolatorNode.SetKeyValue(const Value: TVector3List);
begin
  FdKeyValue.Send(Value);
end;

procedure TSplinePositionInterpolatorNode.SetKeyVelocity(const Value: array of TVector3);
begin
  FdKeyVelocity.Send(Value);
end;

procedure TSplinePositionInterpolatorNode.SetKeyVelocity(const Value: TVector3List);
begin
  FdKeyVelocity.Send(Value);
end;

function TSplinePositionInterpolatorNode.GetNormalizeVelocity: Boolean;
begin
  Result := FdNormalizeVelocity.Value;
end;

procedure TSplinePositionInterpolatorNode.SetNormalizeVelocity(const Value: Boolean);
begin
  FdNormalizeVelocity.Send(Value);
end;

class function TSplinePositionInterpolatorNode.ClassX3DType: String;
begin
  Result := 'SplinePositionInterpolator';
end;

procedure TSplinePositionInterpolatorNode.CreateNode;
begin
  inherited;

  FFdClosed := TSFBool.Create(Self, True, 'closed', false);
   FdClosed.ChangeAlways := chNone;
  AddField(FFdClosed);

  FFdKeyValue := TMFVec3f.Create(Self, True, 'keyValue', []);
   FdKeyValue.ChangeAlways := chNone;
  AddField(FFdKeyValue);

  FFdKeyVelocity := TMFVec3f.Create(Self, True, 'keyVelocity', []);
   FdKeyVelocity.ChangeAlways := chNone;
  AddField(FFdKeyVelocity);

  FFdNormalizeVelocity := TSFBool.Create(Self, True, 'normalizeVelocity', false);
   FdNormalizeVelocity.ChangeAlways := chNone;
  AddField(FFdNormalizeVelocity);

  FEventValue_changed := TSFVec3fEvent.Create(Self, 'value_changed', false);
  AddEvent(FEventValue_changed);
end;

{$endif read_implementation}