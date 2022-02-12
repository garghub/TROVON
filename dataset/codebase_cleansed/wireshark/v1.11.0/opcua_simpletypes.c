void registerSimpleTypes(int proto)
{
static hf_register_info hf[] =
{
{ &hf_opcua_diag_mask_symbolicflag,
{ "has symbolic id", "opcua.has_symbolic_id", FT_BOOLEAN, 8, NULL, DIAGNOSTICINFO_ENCODINGMASK_SYMBOLICID_FLAG, NULL, HFILL }
},
{ &hf_opcua_diag_mask_namespaceflag,
{ "has namespace", "opcua.has_namespace", FT_BOOLEAN, 8, NULL, DIAGNOSTICINFO_ENCODINGMASK_NAMESPACE_FLAG, NULL, HFILL }
},
{ &hf_opcua_diag_mask_localizedtextflag,
{ "has localizedtext", "opcua.has_localizedtext", FT_BOOLEAN, 8, NULL, DIAGNOSTICINFO_ENCODINGMASK_LOCALIZEDTEXT_FLAG, NULL, HFILL }
},
{ &hf_opcua_diag_mask_additionalinfoflag,
{ "has additional info", "opcua.has_additional_info", FT_BOOLEAN, 8, NULL, DIAGNOSTICINFO_ENCODINGMASK_ADDITIONALINFO_FLAG, NULL, HFILL }
},
{ &hf_opcua_diag_mask_innerstatuscodeflag,
{ "has inner statuscode", "opcua.has_inner_statuscode", FT_BOOLEAN, 8, NULL, DIAGNOSTICINFO_ENCODINGMASK_INNERSTATUSCODE_FLAG, NULL, HFILL }
},
{ &hf_opcua_diag_mask_innerdiaginfoflag,
{ "has inner diagnostic info", "opcua.has_inner_diagnostic_code", FT_BOOLEAN, 8, NULL, DIAGNOSTICINFO_ENCODINGMASK_INNERDIAGNOSTICINFO_FLAG, NULL, HFILL }
},
{ &hf_opcua_loctext_mask_localeflag,
{ "has locale information", "opcua.has_locale_information", FT_BOOLEAN, 8, NULL, LOCALIZEDTEXT_ENCODINGBYTE_LOCALE, NULL, HFILL }
},
{ &hf_opcua_loctext_mask_textflag,
{ "has text", "opcua.has_text", FT_BOOLEAN, 8, NULL, LOCALIZEDTEXT_ENCODINGBYTE_TEXT, NULL, HFILL }
},
{ &hf_opcua_nodeid_encodingmask,
{ "NodeId EncodingMask", "application.nodeid.encodingmask", FT_UINT8, BASE_HEX, VALS(g_nodeidmasks), 0x0, NULL, HFILL }
},
{ &hf_opcua_nodeid_nsid,
{ "NodeId Namespace Id", "application.nodeid.nsid", FT_UINT16, BASE_DEC, NULL, 0x0, NULL, HFILL }
},
{ &hf_opcua_nodeid_numeric,
{ "NodeId Identifier Numeric", "application.nodeid.numeric", FT_UINT32, BASE_DEC, NULL, 0x0, NULL, HFILL }
},
{ &hf_opcua_localizedtext_locale, { "Locale", "opcua.Locale", FT_STRING, BASE_NONE, NULL, 0x0, NULL, HFILL } },
{ &hf_opcua_localizedtext_text, { "Text", "opcua.Text", FT_STRING, BASE_NONE, NULL, 0x0, NULL, HFILL } },
{ &hf_opcua_qualifiedname_id, { "Id", "opcua.Id", FT_UINT16, BASE_DEC, NULL, 0x0, NULL, HFILL } },
{ &hf_opcua_qualifiedname_name, { "Name", "opcua.Name", FT_STRING, BASE_NONE, NULL, 0x0, NULL, HFILL } },
{ &hf_opcua_datavalue_mask_valueflag, { "has value", "opcua.has_value", FT_BOOLEAN, 8, NULL, DATAVALUE_ENCODINGBYTE_VALUE, NULL, HFILL } },
{ &hf_opcua_datavalue_mask_statuscodeflag, { "has statuscode", "opcua.has_statuscode", FT_BOOLEAN, 8, NULL, DATAVALUE_ENCODINGBYTE_STATUSCODE, NULL, HFILL } },
{ &hf_opcua_datavalue_mask_sourcetimestampflag, { "has source timestamp", "opcua.has_source_timestamp", FT_BOOLEAN, 8, NULL, DATAVALUE_ENCODINGBYTE_SOURCETIMESTAMP, NULL, HFILL } },
{ &hf_opcua_datavalue_mask_servertimestampflag, { "has server timestamp", "opcua.has_server_timestamp", FT_BOOLEAN, 8, NULL, DATAVALUE_ENCODINGBYTE_SERVERTIMESTAMP, NULL, HFILL } },
{ &hf_opcua_datavalue_mask_sourcepicoseconds, { "has source picoseconds", "opcua.has_source_picoseconds", FT_BOOLEAN, 8, NULL, DATAVALUE_ENCODINGBYTE_SOURCEPICOSECONDS, NULL, HFILL } },
{ &hf_opcua_datavalue_mask_serverpicoseconds, { "has server picoseconds", "opcua.has_server_picoseconds", FT_BOOLEAN, 8, NULL, DATAVALUE_ENCODINGBYTE_SERVERPICOSECONDS, NULL, HFILL } },
{ &hf_opcua_variant_encodingmask, { "Variant Type", "opcua.has_value", FT_UINT8, BASE_HEX, VALS(g_VariantTypes), 0x0, NULL, HFILL } },
{ &hf_opcua_SourceTimestamp, { "SourceTimestamp", "opcua.SourceTimestamp", FT_ABSOLUTE_TIME, ABSOLUTE_TIME_LOCAL, NULL, 0x0, NULL, HFILL } },
{ &hf_opcua_SourcePicoseconds, { "SourcePicoseconds", "opcua.SourcePicoseconds", FT_UINT16, BASE_DEC, NULL, 0x0, NULL, HFILL } },
{ &hf_opcua_ServerTimestamp, { "ServerTimestamp", "opcua.ServerTimestamp", FT_ABSOLUTE_TIME, ABSOLUTE_TIME_LOCAL, NULL, 0x0, NULL, HFILL } },
{ &hf_opcua_ServerPicoseconds, { "ServerPicoseconds", "opcua.ServerPicoseconds", FT_UINT16, BASE_DEC, NULL, 0x0, NULL, HFILL } },
{ &hf_opcua_diag_symbolicid, { "SymbolicId", "opcua.SymbolicId", FT_INT32, BASE_DEC, NULL, 0x0, NULL, HFILL } },
{ &hf_opcua_diag_namespace, { "Namespace", "opcua.Namespace", FT_INT32, BASE_DEC, NULL, 0x0, NULL, HFILL } },
{ &hf_opcua_diag_localizedtext, { "LocaliezdText", "opcua.LocaliezdText", FT_INT32, BASE_DEC, NULL, 0x0, NULL, HFILL } },
{ &hf_opcua_diag_additionalinfo, { "AdditionalInfo", "opcua.AdditionalInfo", FT_STRING, BASE_NONE, NULL, 0x0, NULL, HFILL } },
{ &hf_opcua_diag_innerstatuscode, { "InnerStatusCode", "opcua.InnerStatusCode", FT_UINT32, BASE_HEX, NULL, 0x0, NULL, HFILL } },
{ &hf_opcua_extobj_mask_binbodyflag, { "has binary body", "opcua.has_binary_body", FT_BOOLEAN, 8, NULL, EXTOBJ_ENCODINGMASK_BINBODY_FLAG, NULL, HFILL } },
{ &hf_opcua_extobj_mask_xmlbodyflag, { "has xml body", "opcua.has_xml_body", FT_BOOLEAN, 8, NULL, EXTOBJ_ENCODINGMASK_XMLBODY_FLAG, NULL, HFILL } },
{ &hf_opcua_ArraySize, { "ArraySize", "opcua.ArraySize", FT_INT32, BASE_DEC, NULL, 0x0, NULL, HFILL } },
{ &hf_opcua_Uri, { "Uri", "opcua.Uri", FT_STRING, BASE_NONE, NULL, 0x0, NULL, HFILL } },
{ &hf_opcua_ServerIndex, { "ServerIndex", "opcua.ServerIndex", FT_UINT32, BASE_DEC, NULL, 0x0, NULL, HFILL } }
};
proto_register_field_array(proto, hf, array_length(hf));
proto_register_subtree_array(ett, array_length(ett));
}
void parseBoolean(proto_tree *tree, tvbuff_t *tvb, gint *pOffset, int hfIndex)
{
proto_tree_add_item(tree, hfIndex, tvb, *pOffset, 1, ENC_LITTLE_ENDIAN); *pOffset+=1;
}
void parseByte(proto_tree *tree, tvbuff_t *tvb, gint *pOffset, int hfIndex)
{
proto_tree_add_item(tree, hfIndex, tvb, *pOffset, 1, ENC_LITTLE_ENDIAN); *pOffset+=1;
}
void parseSByte(proto_tree *tree, tvbuff_t *tvb, gint *pOffset, int hfIndex)
{
proto_tree_add_item(tree, hfIndex, tvb, *pOffset, 1, ENC_LITTLE_ENDIAN); *pOffset+=1;
}
void parseUInt16(proto_tree *tree, tvbuff_t *tvb, gint *pOffset, int hfIndex)
{
proto_tree_add_item(tree, hfIndex, tvb, *pOffset, 2, ENC_LITTLE_ENDIAN); *pOffset+=2;
}
void parseInt16(proto_tree *tree, tvbuff_t *tvb, gint *pOffset, int hfIndex)
{
proto_tree_add_item(tree, hfIndex, tvb, *pOffset, 2, ENC_LITTLE_ENDIAN); *pOffset+=2;
}
void parseUInt32(proto_tree *tree, tvbuff_t *tvb, gint *pOffset, int hfIndex)
{
proto_tree_add_item(tree, hfIndex, tvb, *pOffset, 4, ENC_LITTLE_ENDIAN); *pOffset+=4;
}
void parseInt32(proto_tree *tree, tvbuff_t *tvb, gint *pOffset, int hfIndex)
{
proto_tree_add_item(tree, hfIndex, tvb, *pOffset, 4, ENC_LITTLE_ENDIAN); *pOffset+=4;
}
void parseUInt64(proto_tree *tree, tvbuff_t *tvb, gint *pOffset, int hfIndex)
{
proto_tree_add_item(tree, hfIndex, tvb, *pOffset, 8, ENC_LITTLE_ENDIAN); *pOffset+=8;
}
void parseInt64(proto_tree *tree, tvbuff_t *tvb, gint *pOffset, int hfIndex)
{
proto_tree_add_item(tree, hfIndex, tvb, *pOffset, 8, ENC_LITTLE_ENDIAN); *pOffset+=8;
}
void parseString(proto_tree *tree, tvbuff_t *tvb, gint *pOffset, int hfIndex)
{
char *szValue;
gint iOffset = *pOffset;
gint32 iLen = tvb_get_letohl(tvb, *pOffset);
iOffset+=4;
if (iLen == -1)
{
proto_item *item = proto_tree_add_item(tree, hfIndex, tvb, *pOffset, 0, ENC_NA);
proto_item_append_text(item, "[OpcUa Null String]");
proto_item_set_end(item, tvb, *pOffset + 4);
}
else if (iLen == 0)
{
proto_item *item = proto_tree_add_item(tree, hfIndex, tvb, *pOffset, 0, ENC_NA);
proto_item_append_text(item, "[OpcUa Empty String]");
proto_item_set_end(item, tvb, *pOffset + 4);
}
else if (iLen > 0)
{
proto_tree_add_item(tree, hfIndex, tvb, iOffset, iLen, ENC_UTF_8|ENC_NA);
iOffset += iLen;
}
else
{
proto_item *item = proto_tree_add_item(tree, hfIndex, tvb, *pOffset, 0, ENC_NA);
szValue = wmem_strdup_printf(wmem_packet_scope(), "[Invalid String] Invalid length: %d", iLen);
proto_item_append_text(item, "%s", szValue);
proto_item_set_end(item, tvb, *pOffset + 4);
}
*pOffset = iOffset;
}
void parseStatusCode(proto_tree *tree, tvbuff_t *tvb, gint *pOffset, int hfIndex)
{
proto_tree_add_item(tree, hfIndex, tvb, *pOffset, 4, ENC_LITTLE_ENDIAN);
*pOffset += 4;
}
void parseLocalizedText(proto_tree *tree, tvbuff_t *tvb, gint *pOffset, const char *szFieldName)
{
gint iOffset = *pOffset;
guint8 EncodingMask;
proto_tree *mask_tree;
proto_tree *subtree;
proto_item *ti;
proto_item *ti_inner;
ti = proto_tree_add_text(tree, tvb, *pOffset, -1, "%s: LocalizedText", szFieldName);
subtree = proto_item_add_subtree(ti, ett_opcua_localizedtext);
EncodingMask = tvb_get_guint8(tvb, iOffset);
ti_inner = proto_tree_add_text(subtree, tvb, iOffset, 1, "EncodingMask");
mask_tree = proto_item_add_subtree(ti_inner, ett_opcua_localizedtext);
proto_tree_add_item(mask_tree, hf_opcua_loctext_mask_localeflag, tvb, iOffset, 1, ENC_LITTLE_ENDIAN);
proto_tree_add_item(mask_tree, hf_opcua_loctext_mask_textflag, tvb, iOffset, 1, ENC_LITTLE_ENDIAN);
iOffset++;
if (EncodingMask & LOCALIZEDTEXT_ENCODINGBYTE_LOCALE)
{
parseString(subtree, tvb, &iOffset, hf_opcua_localizedtext_locale);
}
if (EncodingMask & LOCALIZEDTEXT_ENCODINGBYTE_TEXT)
{
parseString(subtree, tvb, &iOffset, hf_opcua_localizedtext_text);
}
proto_item_set_end(ti, tvb, iOffset);
*pOffset = iOffset;
}
void parseGuid(proto_tree *tree, tvbuff_t *tvb, gint *pOffset, int hfIndex)
{
proto_tree_add_item(tree, hfIndex, tvb, *pOffset, GUID_LEN, ENC_NA); *pOffset+=GUID_LEN;
}
void parseByteString(proto_tree *tree, tvbuff_t *tvb, gint *pOffset, int hfIndex)
{
char *szValue;
int iOffset = *pOffset;
gint32 iLen = tvb_get_letohl(tvb, iOffset);
iOffset += 4;
if (iLen == -1)
{
proto_item *item = proto_tree_add_item(tree, hfIndex, tvb, *pOffset, 0, ENC_NA);
proto_item_append_text(item, "[OpcUa Null ByteString]");
proto_item_set_end(item, tvb, *pOffset + 4);
}
else if (iLen == 0)
{
proto_item *item = proto_tree_add_item(tree, hfIndex, tvb, *pOffset, 0, ENC_NA);
proto_item_append_text(item, "[OpcUa Empty ByteString]");
proto_item_set_end(item, tvb, *pOffset + 4);
}
else if (iLen > 0)
{
proto_tree_add_item(tree, hfIndex, tvb, iOffset, iLen, ENC_NA);
iOffset += iLen;
}
else
{
proto_item *item = proto_tree_add_item(tree, hfIndex, tvb, *pOffset, 0, ENC_NA);
szValue = wmem_strdup_printf(wmem_packet_scope(), "[Invalid ByteString] Invalid length: %d", iLen);
proto_item_append_text(item, "%s", szValue);
proto_item_set_end(item, tvb, *pOffset + 4);
}
*pOffset = iOffset;
}
void parseXmlElement(proto_tree *tree, tvbuff_t *tvb, gint *pOffset, int hfIndex)
{
parseByteString(tree, tvb, pOffset, hfIndex);
}
void parseFloat(proto_tree *tree, tvbuff_t *tvb, gint *pOffset, int hfIndex)
{
proto_tree_add_item(tree, hfIndex, tvb, *pOffset, (int)sizeof(gfloat), ENC_LITTLE_ENDIAN);
*pOffset += (int)sizeof(gfloat);
}
void parseDouble(proto_tree *tree, tvbuff_t *tvb, gint *pOffset, int hfIndex)
{
proto_tree_add_item(tree, hfIndex, tvb, *pOffset, (int)sizeof(gdouble), ENC_LITTLE_ENDIAN);
*pOffset += (int)sizeof(gdouble);
}
void parseDateTime(proto_tree *tree, tvbuff_t *tvb, gint *pOffset, int hfIndex)
{
*pOffset = dissect_nt_64bit_time(tvb, tree, *pOffset, hfIndex);
}
void parseDiagnosticInfo(proto_tree *tree, tvbuff_t *tvb, gint *pOffset, const char *szFieldName)
{
gint iOffset = *pOffset;
guint8 EncodingMask;
proto_tree *mask_tree;
proto_tree *subtree;
proto_item *ti;
proto_item *ti_inner;
ti = proto_tree_add_text(tree, tvb, *pOffset, -1, "%s: DiagnosticInfo", szFieldName);
subtree = proto_item_add_subtree(ti, ett_opcua_diagnosticinfo);
EncodingMask = tvb_get_guint8(tvb, iOffset);
ti_inner = proto_tree_add_text(subtree, tvb, iOffset, 1, "EncodingMask");
mask_tree = proto_item_add_subtree(ti_inner, ett_opcua_diagnosticinfo);
proto_tree_add_item(mask_tree, hf_opcua_diag_mask_symbolicflag, tvb, iOffset, 1, ENC_LITTLE_ENDIAN);
proto_tree_add_item(mask_tree, hf_opcua_diag_mask_namespaceflag, tvb, iOffset, 1, ENC_LITTLE_ENDIAN);
proto_tree_add_item(mask_tree, hf_opcua_diag_mask_localizedtextflag, tvb, iOffset, 1, ENC_LITTLE_ENDIAN);
proto_tree_add_item(mask_tree, hf_opcua_diag_mask_additionalinfoflag, tvb, iOffset, 1, ENC_LITTLE_ENDIAN);
proto_tree_add_item(mask_tree, hf_opcua_diag_mask_innerstatuscodeflag, tvb, iOffset, 1, ENC_LITTLE_ENDIAN);
proto_tree_add_item(mask_tree, hf_opcua_diag_mask_innerdiaginfoflag, tvb, iOffset, 1, ENC_LITTLE_ENDIAN);
iOffset++;
if (EncodingMask & DIAGNOSTICINFO_ENCODINGMASK_SYMBOLICID_FLAG)
{
parseInt32(subtree, tvb, &iOffset, hf_opcua_diag_symbolicid);
}
if (EncodingMask & DIAGNOSTICINFO_ENCODINGMASK_NAMESPACE_FLAG)
{
parseInt32(subtree, tvb, &iOffset, hf_opcua_diag_namespace);
}
if (EncodingMask & DIAGNOSTICINFO_ENCODINGMASK_LOCALIZEDTEXT_FLAG)
{
parseInt32(subtree, tvb, &iOffset, hf_opcua_diag_localizedtext);
}
if (EncodingMask & DIAGNOSTICINFO_ENCODINGMASK_ADDITIONALINFO_FLAG)
{
parseString(subtree, tvb, &iOffset, hf_opcua_diag_additionalinfo);
}
if (EncodingMask & DIAGNOSTICINFO_ENCODINGMASK_INNERSTATUSCODE_FLAG)
{
parseStatusCode(subtree, tvb, &iOffset, hf_opcua_diag_innerstatuscode);
}
if (EncodingMask & DIAGNOSTICINFO_ENCODINGMASK_INNERDIAGNOSTICINFO_FLAG)
{
parseDiagnosticInfo(subtree, tvb, &iOffset, "Inner DiagnosticInfo");
}
proto_item_set_end(ti, tvb, iOffset);
*pOffset = iOffset;
}
void parseQualifiedName(proto_tree *tree, tvbuff_t *tvb, gint *pOffset, const char *szFieldName)
{
proto_item *ti = proto_tree_add_text(tree, tvb, *pOffset, -1, "%s: QualifiedName", szFieldName);
proto_tree *subtree = proto_item_add_subtree(ti, ett_opcua_qualifiedname);
parseUInt16(subtree, tvb, pOffset, hf_opcua_qualifiedname_id);
parseString(subtree, tvb, pOffset, hf_opcua_qualifiedname_name);
proto_item_set_end(ti, tvb, *pOffset);
}
void parseDataValue(proto_tree *tree, tvbuff_t *tvb, gint *pOffset, const char *szFieldName)
{
proto_item *ti = proto_tree_add_text(tree, tvb, *pOffset, -1, "%s: DataValue", szFieldName);
proto_tree *subtree = proto_item_add_subtree(ti, ett_opcua_datavalue);
proto_tree *mask_tree;
gint iOffset = *pOffset;
guint8 EncodingMask;
proto_item *ti_inner;
EncodingMask = tvb_get_guint8(tvb, iOffset);
ti_inner = proto_tree_add_text(subtree, tvb, iOffset, 1, "EncodingMask");
mask_tree = proto_item_add_subtree(ti_inner, ett_opcua_datavalue);
proto_tree_add_item(mask_tree, hf_opcua_datavalue_mask_valueflag, tvb, iOffset, 1, ENC_LITTLE_ENDIAN);
proto_tree_add_item(mask_tree, hf_opcua_datavalue_mask_statuscodeflag, tvb, iOffset, 1, ENC_LITTLE_ENDIAN);
proto_tree_add_item(mask_tree, hf_opcua_datavalue_mask_sourcetimestampflag, tvb, iOffset, 1, ENC_LITTLE_ENDIAN);
proto_tree_add_item(mask_tree, hf_opcua_datavalue_mask_servertimestampflag, tvb, iOffset, 1, ENC_LITTLE_ENDIAN);
proto_tree_add_item(mask_tree, hf_opcua_datavalue_mask_sourcepicoseconds, tvb, iOffset, 1, ENC_LITTLE_ENDIAN);
proto_tree_add_item(mask_tree, hf_opcua_datavalue_mask_serverpicoseconds, tvb, iOffset, 1, ENC_LITTLE_ENDIAN);
iOffset++;
if (EncodingMask & DATAVALUE_ENCODINGBYTE_VALUE)
{
parseVariant(subtree, tvb, &iOffset, "Value");
}
if (EncodingMask & DATAVALUE_ENCODINGBYTE_STATUSCODE)
{
parseStatusCode(subtree, tvb, &iOffset, hf_opcua_StatusCode);
}
if (EncodingMask & DATAVALUE_ENCODINGBYTE_SOURCETIMESTAMP)
{
parseDateTime(subtree, tvb, &iOffset, hf_opcua_SourceTimestamp);
}
if (EncodingMask & DATAVALUE_ENCODINGBYTE_SOURCEPICOSECONDS)
{
parseUInt16(subtree, tvb, &iOffset, hf_opcua_SourcePicoseconds);
}
if (EncodingMask & DATAVALUE_ENCODINGBYTE_SERVERTIMESTAMP)
{
parseDateTime(subtree, tvb, &iOffset, hf_opcua_ServerTimestamp);
}
if (EncodingMask & DATAVALUE_ENCODINGBYTE_SERVERPICOSECONDS)
{
parseUInt16(subtree, tvb, &iOffset, hf_opcua_ServerPicoseconds);
}
proto_item_set_end(ti, tvb, iOffset);
*pOffset = iOffset;
}
void parseVariant(proto_tree *tree, tvbuff_t *tvb, gint *pOffset, const char *szFieldName)
{
proto_item *ti = proto_tree_add_text(tree, tvb, *pOffset, -1, "%s: Variant", szFieldName);
proto_tree *subtree = proto_item_add_subtree(ti, ett_opcua_variant);
gint iOffset = *pOffset;
guint8 EncodingMask;
gint32 ArrayDimensions = 0;
EncodingMask = tvb_get_guint8(tvb, iOffset);
proto_tree_add_item(subtree, hf_opcua_variant_encodingmask, tvb, iOffset, 1, ENC_LITTLE_ENDIAN);
iOffset++;
if (EncodingMask & VARIANT_ARRAYMASK)
{
switch(EncodingMask & 0x3f)
{
case OpcUaType_Null: break;
case OpcUaType_Boolean: parseArraySimple(subtree, tvb, &iOffset, hf_opcua_Boolean, parseBoolean); break;
case OpcUaType_SByte: parseArraySimple(subtree, tvb, &iOffset, hf_opcua_SByte, parseSByte); break;
case OpcUaType_Byte: parseArraySimple(subtree, tvb, &iOffset, hf_opcua_Byte, parseByte); break;
case OpcUaType_Int16: parseArraySimple(subtree, tvb, &iOffset, hf_opcua_Int16, parseInt16); break;
case OpcUaType_UInt16: parseArraySimple(subtree, tvb, &iOffset, hf_opcua_UInt16, parseUInt16); break;
case OpcUaType_Int32: parseArraySimple(subtree, tvb, &iOffset, hf_opcua_Int32, parseInt32); break;
case OpcUaType_UInt32: parseArraySimple(subtree, tvb, &iOffset, hf_opcua_UInt32, parseUInt32); break;
case OpcUaType_Int64: parseArraySimple(subtree, tvb, &iOffset, hf_opcua_Int64, parseInt64); break;
case OpcUaType_UInt64: parseArraySimple(subtree, tvb, &iOffset, hf_opcua_UInt64, parseUInt64); break;
case OpcUaType_Float: parseArraySimple(subtree, tvb, &iOffset, hf_opcua_Float, parseFloat); break;
case OpcUaType_Double: parseArraySimple(subtree, tvb, &iOffset, hf_opcua_Double, parseDouble); break;
case OpcUaType_String: parseArraySimple(subtree, tvb, &iOffset, hf_opcua_String, parseString); break;
case OpcUaType_DateTime: parseArraySimple(subtree, tvb, &iOffset, hf_opcua_DateTime, parseDateTime); break;
case OpcUaType_Guid: parseArraySimple(subtree, tvb, &iOffset, hf_opcua_Guid, parseGuid); break;
case OpcUaType_ByteString: parseArraySimple(subtree, tvb, &iOffset, hf_opcua_ByteString, parseByteString); break;
case OpcUaType_XmlElement: parseArraySimple(subtree, tvb, &iOffset, hf_opcua_XmlElement, parseXmlElement); break;
case OpcUaType_NodeId: parseArrayComplex(subtree, tvb, &iOffset, "NodeId", parseNodeId); break;
case OpcUaType_ExpandedNodeId: parseArrayComplex(subtree, tvb, &iOffset, "ExpandedNodeId", parseExpandedNodeId); break;
case OpcUaType_StatusCode: parseArraySimple(subtree, tvb, &iOffset, hf_opcua_StatusCode, parseStatusCode); break;
case OpcUaType_DiagnosticInfo: parseArrayComplex(subtree, tvb, &iOffset, "DiagnosticInfo", parseDiagnosticInfo); break;
case OpcUaType_QualifiedName: parseArrayComplex(subtree, tvb, &iOffset, "QualifiedName", parseQualifiedName); break;
case OpcUaType_LocalizedText: parseArrayComplex(subtree, tvb, &iOffset, "LocalizedText", parseLocalizedText); break;
case OpcUaType_ExtensionObject: parseArrayComplex(subtree, tvb, &iOffset, "ExtensionObject", parseExtensionObject); break;
case OpcUaType_DataValue: parseArrayComplex(subtree, tvb, &iOffset, "DataValue", parseDataValue); break;
case OpcUaType_Variant: parseArrayComplex(subtree, tvb, &iOffset, "Variant", parseVariant); break;
}
if (EncodingMask & VARIANT_ARRAYDIMENSIONS)
{
proto_item *ti_2 = proto_tree_add_text(subtree, tvb, iOffset, -1, "ArrayDimensions");
proto_tree *subtree_2 = proto_item_add_subtree(ti_2, ett_opcua_array);
int i;
ArrayDimensions = tvb_get_letohl(tvb, iOffset);
proto_tree_add_item(subtree_2, hf_opcua_ArraySize, tvb, iOffset, 4, ENC_LITTLE_ENDIAN);
if (ArrayDimensions > MAX_ARRAY_LEN)
{
proto_item *pi;
pi = proto_tree_add_text(subtree_2, tvb, iOffset, 4, "ArrayDimensions length %d too large to process", ArrayDimensions);
PROTO_ITEM_SET_GENERATED(pi);
return;
}
iOffset += 4;
for (i=0; i<ArrayDimensions; i++)
{
parseInt32(subtree_2, tvb, &iOffset, hf_opcua_Int32);
}
proto_item_set_end(ti_2, tvb, iOffset);
}
}
else
{
switch(EncodingMask & 0x3f)
{
case OpcUaType_Null: break;
case OpcUaType_Boolean: parseBoolean(subtree, tvb, &iOffset, hf_opcua_Boolean); break;
case OpcUaType_SByte: parseSByte(subtree, tvb, &iOffset, hf_opcua_SByte); break;
case OpcUaType_Byte: parseByte(subtree, tvb, &iOffset, hf_opcua_Byte); break;
case OpcUaType_Int16: parseInt16(subtree, tvb, &iOffset, hf_opcua_Int16); break;
case OpcUaType_UInt16: parseUInt16(subtree, tvb, &iOffset, hf_opcua_UInt16); break;
case OpcUaType_Int32: parseInt32(subtree, tvb, &iOffset, hf_opcua_Int32); break;
case OpcUaType_UInt32: parseUInt32(subtree, tvb, &iOffset, hf_opcua_UInt32); break;
case OpcUaType_Int64: parseInt64(subtree, tvb, &iOffset, hf_opcua_Int64); break;
case OpcUaType_UInt64: parseUInt64(subtree, tvb, &iOffset, hf_opcua_UInt64); break;
case OpcUaType_Float: parseFloat(subtree, tvb, &iOffset, hf_opcua_Float); break;
case OpcUaType_Double: parseDouble(subtree, tvb, &iOffset, hf_opcua_Double); break;
case OpcUaType_String: parseString(subtree, tvb, &iOffset, hf_opcua_String); break;
case OpcUaType_DateTime: parseDateTime(subtree, tvb, &iOffset, hf_opcua_DateTime); break;
case OpcUaType_Guid: parseGuid(subtree, tvb, &iOffset, hf_opcua_Guid); break;
case OpcUaType_ByteString: parseByteString(subtree, tvb, &iOffset, hf_opcua_ByteString); break;
case OpcUaType_XmlElement: parseXmlElement(subtree, tvb, &iOffset, hf_opcua_XmlElement); break;
case OpcUaType_NodeId: parseNodeId(subtree, tvb, &iOffset, "Value"); break;
case OpcUaType_ExpandedNodeId: parseExpandedNodeId(subtree, tvb, &iOffset, "Value"); break;
case OpcUaType_StatusCode: parseStatusCode(subtree, tvb, &iOffset, hf_opcua_StatusCode); break;
case OpcUaType_DiagnosticInfo: parseDiagnosticInfo(subtree, tvb, &iOffset, "Value"); break;
case OpcUaType_QualifiedName: parseQualifiedName(subtree, tvb, &iOffset, "Value"); break;
case OpcUaType_LocalizedText: parseLocalizedText(subtree, tvb, &iOffset, "Value"); break;
case OpcUaType_ExtensionObject: parseExtensionObject(subtree, tvb, &iOffset, "Value"); break;
case OpcUaType_DataValue: parseDataValue(subtree, tvb, &iOffset, "Value"); break;
case OpcUaType_Variant: parseVariant(subtree, tvb, &iOffset, "Value"); break;
}
}
proto_item_set_end(ti, tvb, iOffset);
*pOffset = iOffset;
}
void parseArraySimple(proto_tree *tree, tvbuff_t *tvb, gint *pOffset, int hfIndex, fctSimpleTypeParser pParserFunction)
{
static const char szFieldName[] = "Array of Simple Type";
proto_item *ti = proto_tree_add_text(tree, tvb, *pOffset, -1, "%s", szFieldName);
proto_tree *subtree = proto_item_add_subtree(ti, ett_opcua_array);
int i;
gint32 iLen;
iLen = tvb_get_letohl(tvb, *pOffset);
proto_tree_add_item(subtree, hf_opcua_ArraySize, tvb, *pOffset, 4, ENC_LITTLE_ENDIAN);
if (iLen > MAX_ARRAY_LEN)
{
proto_item *pi;
pi = proto_tree_add_text(tree, tvb, *pOffset, 4, "Array length %d too large to process", iLen);
PROTO_ITEM_SET_GENERATED(pi);
return;
}
*pOffset += 4;
for (i=0; i<iLen; i++)
{
(*pParserFunction)(subtree, tvb, pOffset, hfIndex);
}
proto_item_set_end(ti, tvb, *pOffset);
}
void parseArrayEnum(proto_tree *tree, tvbuff_t *tvb, gint *pOffset, fctEnumParser pParserFunction)
{
static const char szFieldName[] = "Array of Enum Type";
proto_item *ti = proto_tree_add_text(tree, tvb, *pOffset, -1, "%s", szFieldName);
proto_tree *subtree = proto_item_add_subtree(ti, ett_opcua_array);
int i;
gint32 iLen;
iLen = tvb_get_letohl(tvb, *pOffset);
proto_tree_add_item(subtree, hf_opcua_ArraySize, tvb, *pOffset, 4, ENC_LITTLE_ENDIAN);
if (iLen > MAX_ARRAY_LEN)
{
proto_item *pi;
pi = proto_tree_add_text(tree, tvb, *pOffset, 4, "Array length %d too large to process", iLen);
PROTO_ITEM_SET_GENERATED(pi);
return;
}
*pOffset += 4;
for (i=0; i<iLen; i++)
{
(*pParserFunction)(subtree, tvb, pOffset);
}
proto_item_set_end(ti, tvb, *pOffset);
}
void parseArrayComplex(proto_tree *tree, tvbuff_t *tvb, gint *pOffset, const char *szFieldName, fctComplexTypeParser pParserFunction)
{
proto_item *ti = proto_tree_add_text(tree, tvb, *pOffset, -1, "Array of %s", szFieldName);
proto_tree *subtree = proto_item_add_subtree(ti, ett_opcua_array);
int i;
gint32 iLen;
iLen = tvb_get_letohl(tvb, *pOffset);
proto_tree_add_item(subtree, hf_opcua_ArraySize, tvb, *pOffset, 4, ENC_LITTLE_ENDIAN);
if (iLen > MAX_ARRAY_LEN)
{
proto_item *pi;
pi = proto_tree_add_text(tree, tvb, *pOffset, 4, "Array length %d too large to process", iLen);
PROTO_ITEM_SET_GENERATED(pi);
return;
}
*pOffset += 4;
for (i=0; i<iLen; i++)
{
char szNum[20];
g_snprintf(szNum, 20, "[%i]", i);
(*pParserFunction)(subtree, tvb, pOffset, szNum);
}
proto_item_set_end(ti, tvb, *pOffset);
}
void parseNodeId(proto_tree *tree, tvbuff_t *tvb, gint *pOffset, const char *szFieldName)
{
proto_item *ti = proto_tree_add_text(tree, tvb, *pOffset, -1, "%s: NodeId", szFieldName);
proto_tree *subtree = proto_item_add_subtree(ti, ett_opcua_nodeid);
gint iOffset = *pOffset;
guint8 EncodingMask;
EncodingMask = tvb_get_guint8(tvb, iOffset);
proto_tree_add_item(subtree, hf_opcua_nodeid_encodingmask, tvb, iOffset, 1, ENC_LITTLE_ENDIAN);
iOffset++;
switch(EncodingMask)
{
case 0x00:
proto_tree_add_item(subtree, hf_opcua_nodeid_numeric, tvb, iOffset, 1, ENC_LITTLE_ENDIAN);
iOffset+=1;
break;
case 0x01:
proto_tree_add_item(subtree, hf_opcua_nodeid_nsid, tvb, iOffset, 1, ENC_LITTLE_ENDIAN);
iOffset+=1;
proto_tree_add_item(subtree, hf_opcua_nodeid_numeric, tvb, iOffset, 2, ENC_LITTLE_ENDIAN);
iOffset+=2;
break;
case 0x02:
proto_tree_add_item(subtree, hf_opcua_nodeid_nsid, tvb, iOffset, 2, ENC_LITTLE_ENDIAN);
iOffset+=2;
proto_tree_add_item(subtree, hf_opcua_nodeid_numeric, tvb, iOffset, 4, ENC_LITTLE_ENDIAN);
iOffset+=4;
break;
case 0x03:
proto_tree_add_item(subtree, hf_opcua_nodeid_nsid, tvb, iOffset, 2, ENC_LITTLE_ENDIAN);
iOffset+=2;
parseString(subtree, tvb, &iOffset, hf_opcua_String);
break;
case 0x04:
proto_tree_add_item(subtree, hf_opcua_nodeid_nsid, tvb, iOffset, 2, ENC_LITTLE_ENDIAN);
iOffset+=2;
parseGuid(subtree, tvb, &iOffset, hf_opcua_Guid);
break;
case 0x05:
proto_tree_add_item(subtree, hf_opcua_nodeid_nsid, tvb, iOffset, 2, ENC_LITTLE_ENDIAN);
iOffset+=2;
parseByteString(subtree, tvb, &iOffset, hf_opcua_ByteString);
break;
};
proto_item_set_end(ti, tvb, iOffset);
*pOffset = iOffset;
}
void parseExtensionObject(proto_tree *tree, tvbuff_t *tvb, gint *pOffset, const char *szFieldName)
{
gint iOffset = *pOffset;
guint8 EncodingMask;
guint32 TypeId;
proto_tree *extobj_tree;
proto_tree *mask_tree;
proto_item *ti;
proto_item *ti_inner;
ti = proto_tree_add_text(tree, tvb, *pOffset, -1, "%s : ExtensionObject", szFieldName);
extobj_tree = proto_item_add_subtree(ti, ett_opcua_extensionobject);
TypeId = getExtensionObjectType(tvb, &iOffset);
parseExpandedNodeId(extobj_tree, tvb, &iOffset, "TypeId");
EncodingMask = tvb_get_guint8(tvb, iOffset);
ti_inner = proto_tree_add_text(extobj_tree, tvb, iOffset, 1, "EncodingMask");
mask_tree = proto_item_add_subtree(ti_inner, ett_opcua_extobj_encodingmask);
proto_tree_add_item(mask_tree, hf_opcua_extobj_mask_binbodyflag, tvb, iOffset, 1, ENC_LITTLE_ENDIAN);
proto_tree_add_item(mask_tree, hf_opcua_extobj_mask_xmlbodyflag, tvb, iOffset, 1, ENC_LITTLE_ENDIAN);
iOffset++;
if (EncodingMask & EXTOBJ_ENCODINGMASK_BINBODY_FLAG)
{
dispatchExtensionObjectType(extobj_tree, tvb, &iOffset, TypeId);
}
proto_item_set_end(ti, tvb, iOffset);
*pOffset = iOffset;
}
void parseExpandedNodeId(proto_tree *tree, tvbuff_t *tvb, gint *pOffset, const char *szFieldName)
{
proto_item *ti = proto_tree_add_text(tree, tvb, *pOffset, -1, "%s: ExpandedNodeId", szFieldName);
proto_tree *subtree = proto_item_add_subtree(ti, ett_opcua_nodeid);
gint iOffset = *pOffset;
guint8 EncodingMask;
EncodingMask = tvb_get_guint8(tvb, iOffset);
proto_tree_add_item(subtree, hf_opcua_nodeid_encodingmask, tvb, iOffset, 1, ENC_LITTLE_ENDIAN);
iOffset++;
switch(EncodingMask)
{
case 0x00:
proto_tree_add_item(subtree, hf_opcua_nodeid_numeric, tvb, iOffset, 1, ENC_LITTLE_ENDIAN);
iOffset+=1;
break;
case 0x01:
proto_tree_add_item(subtree, hf_opcua_nodeid_nsid, tvb, iOffset, 1, ENC_LITTLE_ENDIAN);
iOffset+=1;
proto_tree_add_item(subtree, hf_opcua_nodeid_numeric, tvb, iOffset, 2, ENC_LITTLE_ENDIAN);
iOffset+=2;
break;
case 0x02:
proto_tree_add_item(subtree, hf_opcua_nodeid_nsid, tvb, iOffset, 2, ENC_LITTLE_ENDIAN);
iOffset+=2;
proto_tree_add_item(subtree, hf_opcua_nodeid_numeric, tvb, iOffset, 4, ENC_LITTLE_ENDIAN);
iOffset+=4;
break;
case 0x03:
proto_tree_add_item(subtree, hf_opcua_nodeid_nsid, tvb, iOffset, 2, ENC_LITTLE_ENDIAN);
iOffset+=2;
parseString(subtree, tvb, &iOffset, hf_opcua_String);
break;
case 0x04:
proto_tree_add_item(subtree, hf_opcua_nodeid_nsid, tvb, iOffset, 2, ENC_LITTLE_ENDIAN);
iOffset+=2;
parseGuid(subtree, tvb, &iOffset, hf_opcua_Guid);
break;
case 0x05:
proto_tree_add_item(subtree, hf_opcua_nodeid_nsid, tvb, iOffset, 2, ENC_LITTLE_ENDIAN);
iOffset+=2;
parseByteString(subtree, tvb, &iOffset, hf_opcua_ByteString);
break;
};
if (EncodingMask & NODEID_URIMASK)
{
parseString(subtree, tvb, &iOffset, hf_opcua_Uri);
}
if (EncodingMask & NODEID_SERVERINDEXFLAG)
{
parseUInt32(subtree, tvb, &iOffset, hf_opcua_ServerIndex);
}
proto_item_set_end(ti, tvb, iOffset);
*pOffset = iOffset;
}
guint32 getExtensionObjectType(tvbuff_t *tvb, gint *pOffset)
{
gint iOffset = *pOffset;
guint8 EncodingMask;
guint32 Numeric = 0;
EncodingMask = tvb_get_guint8(tvb, iOffset);
iOffset++;
switch(EncodingMask)
{
case 0x00:
Numeric = tvb_get_guint8(tvb, iOffset);
break;
case 0x01:
iOffset+=1;
Numeric = tvb_get_letohs(tvb, iOffset);
break;
case 0x02:
iOffset+=4;
Numeric = tvb_get_letohl(tvb, iOffset);
break;
case 0x03:
case 0x04:
case 0x05:
case 0x06:
break;
};
return Numeric;
}
