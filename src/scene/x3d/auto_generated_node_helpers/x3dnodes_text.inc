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
    function GetFontStyle: TAbstractFontStyleNode;
    procedure SetFontStyle(const Value: TAbstractFontStyleNode);
    function GetMaxExtent: Single;
    procedure SetMaxExtent(const Value: Single);
    function GetMaxDisplayChars: Integer;
    procedure SetMaxDisplayChars(const Value: Integer);
  public
    procedure CreateNode; override;
    class function ClassX3DType: string; override;

    strict private FFdFontStyle: TSFNode;
    { X3D field "fontStyle". } { }
    public property FdFontStyle: TSFNode read FFdFontStyle;
    { X3D field "fontStyle". } { }
    property FontStyle: TAbstractFontStyleNode read GetFontStyle write SetFontStyle;

    strict private FFdLength: TMFFloat;
    { X3D field "length". } { }
    public property FdLength: TMFFloat read FFdLength;
    { Set X3D field "length". } { }
    procedure SetLength(const Value: array of Single); overload;
    { Set X3D field "length". } { }
    procedure SetLength(const Value: TSingleList); overload;

    strict private FFdMaxExtent: TSFFloat;
    { X3D field "maxExtent". } { }
    public property FdMaxExtent: TSFFloat read FFdMaxExtent;
    { X3D field "maxExtent". } { }
    property MaxExtent: Single read GetMaxExtent write SetMaxExtent;

    strict private FFdMaxDisplayChars: TSFInt32;
    { X3D field "maxDisplayChars". } { }
    public property FdMaxDisplayChars: TSFInt32 read FFdMaxDisplayChars;
    { X3D field "maxDisplayChars". } { }
    property MaxDisplayChars: Integer read GetMaxDisplayChars write SetMaxDisplayChars;

    strict private FFdString: TMFString;
    { X3D field "string". } { }
    public property FdString: TMFString read FFdString;
    { Set X3D field "string". } { }
    procedure SetString(const Value: array of string); overload;
    { Set X3D field "string". } { }
    procedure SetString(const Value: TCastleStringList); overload;

    strict private FEventLineBounds: TMFVec2fEvent;
    { X3D out event "lineBounds". } { }
    public property EventLineBounds: TMFVec2fEvent read FEventLineBounds;

    strict private FEventOrigin: TSFVec3fEvent;
    { X3D out event "origin". } { }
    public property EventOrigin: TSFVec3fEvent read FEventOrigin;

    strict private FEventTextBounds: TSFVec2fEvent;
    { X3D out event "textBounds". } { }
    public property EventTextBounds: TSFVec2fEvent read FEventTextBounds;

    strict private FFdSolid: TSFBool;
    { X3D field "solid". } { }
    public property FdSolid: TSFBool read FFdSolid;

    strict private FFdTexCoord: TSFNode;
    { X3D field "texCoord". } { }
    public property FdTexCoord: TSFNode read FFdTexCoord;

{$endif read_interface}

{$ifdef read_implementation}

{ TTextNode ----------------------------------------------- }

function TTextNode.GetFontStyle: TAbstractFontStyleNode;
begin
  if FdFontStyle.Value is TAbstractFontStyleNode then
    Result := TAbstractFontStyleNode(FdFontStyle.Value)
  else
    Result := nil;
end;

procedure TTextNode.SetFontStyle(const Value: TAbstractFontStyleNode);
begin
  FdFontStyle.Send(Value);
end;

procedure TTextNode.SetLength(const Value: array of Single);
begin
  FdLength.Send(Value);
end;

procedure TTextNode.SetLength(const Value: TSingleList);
begin
  FdLength.Send(Value);
end;

function TTextNode.GetMaxExtent: Single;
begin
  Result := FdMaxExtent.Value;
end;

procedure TTextNode.SetMaxExtent(const Value: Single);
begin
  FdMaxExtent.Send(Value);
end;

function TTextNode.GetMaxDisplayChars: Integer;
begin
  Result := FdMaxDisplayChars.Value;
end;

procedure TTextNode.SetMaxDisplayChars(const Value: Integer);
begin
  FdMaxDisplayChars.Send(Value);
end;

procedure TTextNode.SetString(const Value: array of string);
begin
  FdString.Send(Value);
end;

procedure TTextNode.SetString(const Value: TCastleStringList);
begin
  FdString.Send(Value);
end;

class function TTextNode.ClassX3DType: String;
begin
  Result := 'Text';
end;

procedure TTextNode.CreateNode;
begin
  inherited;

  FFdFontStyle := TSFNode.Create(Self, True, 'fontStyle', [TAbstractFontStyleNode]);
   FdFontStyle.ChangeAlways := chGeometryFontChanged;
  AddField(FFdFontStyle);

  FFdLength := TMFFloat.Create(Self, True, 'length', []);
   FdLength.ChangeAlways := chGeometry;
  AddField(FFdLength);

  FFdMaxExtent := TSFFloat.Create(Self, True, 'maxExtent', 0.0);
   FdMaxExtent.ChangeAlways := chGeometry;
  AddField(FFdMaxExtent);

  FFdMaxDisplayChars := TSFInt32.Create(Self, True, 'maxDisplayChars', -1);
   FdMaxDisplayChars.ChangeAlways := chGeometry;
  AddField(FFdMaxDisplayChars);

  FFdString := TMFString.Create(Self, True, 'string', []);
   FdString.ChangeAlways := chGeometry;
  AddField(FFdString);

  FEventLineBounds := TMFVec2fEvent.Create(Self, 'lineBounds', false);
  AddEvent(FEventLineBounds);

  FEventOrigin := TSFVec3fEvent.Create(Self, 'origin', false);
  AddEvent(FEventOrigin);

  FEventTextBounds := TSFVec2fEvent.Create(Self, 'textBounds', false);
  AddEvent(FEventTextBounds);

  FFdSolid := TSFBool.Create(Self, False, 'solid', false);
   FdSolid.ChangeAlways := chGeometry;
  AddField(FFdSolid);

  FFdTexCoord := TSFNode.Create(Self, True, 'texCoord', [TTextureCoordinateGeneratorNode, TProjectedTextureCoordinateNode, TMultiGeneratedTextureCoordinateNode]);
   FdTexCoord.ChangeAlways := chGeometry;
  AddField(FFdTexCoord);
end;

{$endif read_implementation}