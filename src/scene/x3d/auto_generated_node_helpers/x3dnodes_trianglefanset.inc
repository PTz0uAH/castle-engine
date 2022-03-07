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

  public
    procedure CreateNode; override;
    class function ClassX3DType: string; override;

    strict private FFdFanCount: TMFInt32;
    { X3D field "fanCount". } { }
    public property FdFanCount: TMFInt32 read FFdFanCount;
    { Set X3D field "fanCount". } { }
    procedure SetFanCount(const Value: array of LongInt); overload;
    { Set X3D field "fanCount". } { }
    procedure SetFanCount(const Value: TLongIntList); overload;

{$endif read_interface}

{$ifdef read_implementation}

{ TTriangleFanSetNode ----------------------------------------------- }

procedure TTriangleFanSetNode.SetFanCount(const Value: array of LongInt);
begin
  FdFanCount.Send(Value);
end;

procedure TTriangleFanSetNode.SetFanCount(const Value: TLongIntList);
begin
  FdFanCount.Send(Value);
end;

class function TTriangleFanSetNode.ClassX3DType: String;
begin
  Result := 'TriangleFanSet';
end;

procedure TTriangleFanSetNode.CreateNode;
begin
  inherited;

  FFdFanCount := TMFInt32.Create(Self, True, 'fanCount', []);
   FdFanCount.ChangeAlways := chGeometry;
  AddField(FFdFanCount);
end;

{$endif read_implementation}