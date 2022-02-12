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
{ &hf_opcua_diag_mask_localeflag,
{ "has locale", "opcua.has_locale", FT_BOOLEAN, 8, NULL, DIAGNOSTICINFO_ENCODINGMASK_LOCALE_FLAG, NULL, HFILL }
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
{ "NodeId EncodingMask", "application.nodeid.encodingmask", FT_UINT8, BASE_HEX, VALS(g_nodeidmasks), 0x0F, NULL, HFILL }
},
{ &hf_opcua_nodeid_nsindex,
{ "NodeId Namespace Index", "application.nodeid.nsindex", FT_UINT16, BASE_DEC, NULL, 0x0, NULL, HFILL }
},
{ &hf_opcua_nodeid_numeric, { "NodeId Identifier Numeric", "application.nodeid.numeric", FT_UINT32, BASE_DEC, NULL, 0x0, NULL, HFILL } },
{ &hf_opcua_nodeid_string, { "NodeId Identifier String", "application.nodeid.string", FT_STRING, BASE_NONE, NULL, 0x0, NULL, HFILL } },
{ &hf_opcua_nodeid_guid, { "NodeId Identifier Guid", "application.nodeid.guid", FT_GUID, BASE_NONE, NULL, 0x0, NULL, HFILL } },
{ &hf_opcua_nodeid_bytestring, { "NodeId Identifier ByteString", "application.nodeid.bytestring", FT_BYTES, BASE_NONE, NULL, 0x0, NULL, HFILL } },
{ &hf_opcua_expandednodeid_mask_namespaceuri, { "has namespace uri", "opcua.has_namespace_uri", FT_BOOLEAN, 8, NULL, NODEID_NAMESPACEURIFLAG, NULL, HFILL } },
{ &hf_opcua_expandednodeid_mask_serverindex, { "has server index", "opcua.has_server_index", FT_BOOLEAN, 8, NULL, NODEID_SERVERINDEXFLAG, NULL, HFILL } },
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
{ &hf_opcua_diag_localizedtext, { "LocalizedText", "opcua.LocalizedText", FT_INT32, BASE_DEC, NULL, 0x0, NULL, HFILL } },
{ &hf_opcua_diag_locale, { "Locale", "opcua.Locale", FT_INT32, BASE_DEC, NULL, 0x0, NULL, HFILL } },
{ &hf_opcua_diag_additionalinfo, { "AdditionalInfo", "opcua.AdditionalInfo", FT_STRING, BASE_NONE, NULL, 0x0, NULL, HFILL } },
{ &hf_opcua_diag_innerstatuscode, { "InnerStatusCode", "opcua.InnerStatusCode", FT_UINT32, BASE_HEX, NULL, 0x0, NULL, HFILL } },
{ &hf_opcua_extobj_mask_binbodyflag, { "has binary body", "opcua.has_binary_body", FT_BOOLEAN, 8, NULL, EXTOBJ_ENCODINGMASK_BINBODY_FLAG, NULL, HFILL } },
{ &hf_opcua_extobj_mask_xmlbodyflag, { "has xml body", "opcua.has_xml_body", FT_BOOLEAN, 8, NULL, EXTOBJ_ENCODINGMASK_XMLBODY_FLAG, NULL, HFILL } },
{ &hf_opcua_ArraySize, { "ArraySize", "opcua.ArraySize", FT_INT32, BASE_DEC, NULL, 0x0, NULL, HFILL } },
{ &hf_opcua_ServerIndex, { "ServerIndex", "opcua.ServerIndex", FT_UINT32, BASE_DEC, NULL, 0x0, NULL, HFILL } },
{ &hf_opcua_status_StructureChanged, { "StructureChanged", "opcua.statuscode.structureChanged", FT_BOOLEAN, 16, NULL, STATUSCODE_STRUCTURECHANGED, NULL, HFILL } },
{ &hf_opcua_status_SemanticsChanged, { "SemanticsChanged", "opcua.statuscode.semanticsChanged", FT_BOOLEAN, 16, NULL, STATUSCODE_SEMANTICSCHANGED, NULL, HFILL } },
{ &hf_opcua_status_InfoBit_Limit_Overflow, { "Overflow", "opcua.statuscode.overflow", FT_BOOLEAN, 16, NULL, STATUSCODE_INFOBIT_OVERFLOW, NULL, HFILL } },
{ &hf_opcua_status_InfoBit_Historian_Partial, { "HistorianBit: Partial", "opcua.statuscode.historian.partial", FT_BOOLEAN, 16, NULL, STATUSCODE_INFOBIT_HISTORIAN_PARTIAL, NULL, HFILL } },
{ &hf_opcua_status_InfoBit_Historian_ExtraData, { "HistorianBit: ExtraData", "opcua.statuscode.historian.extraData", FT_BOOLEAN, 16, NULL, STATUSCODE_INFOBIT_HISTORIAN_EXTRADATA, NULL, HFILL } },
{ &hf_opcua_status_InfoBit_Historian_MultiValue, { "HistorianBit: MultiValue", "opcua.statuscode.historian.multiValue", FT_BOOLEAN, 16, NULL, STATUSCODE_INFOBIT_HISTORIAN_MULTIVALUE, NULL, HFILL } },
{ &hf_opcua_status_InfoType, { "InfoType", "opcua.statuscode.infoType", FT_UINT16, BASE_HEX, VALS(g_infotype), 0x0C00, NULL, HFILL } },
{ &hf_opcua_status_Limit, { "Limit", "opcua.statuscode.limit", FT_UINT16, BASE_HEX, VALS(g_limit), 0x0300, NULL, HFILL } },
{ &hf_opcua_status_Historian, { "Historian", "opcua.statuscode.historian", FT_UINT16, BASE_HEX, VALS(g_historian), 0x0003, NULL, HFILL } },
};
proto_register_field_array(proto, hf, array_length(hf));
proto_register_subtree_array(ett, array_length(ett));
}
proto_item* parseBoolean(proto_tree *tree, tvbuff_t *tvb, gint *pOffset, int hfIndex)
{
proto_item *item = proto_tree_add_item(tree, hfIndex, tvb, *pOffset, 1, ENC_LITTLE_ENDIAN);
*pOffset+=1;
return item;
}
proto_item* parseByte(proto_tree *tree, tvbuff_t *tvb, gint *pOffset, int hfIndex)
{
proto_item *item = proto_tree_add_item(tree, hfIndex, tvb, *pOffset, 1, ENC_LITTLE_ENDIAN);
*pOffset+=1;
return item;
}
proto_item* parseSByte(proto_tree *tree, tvbuff_t *tvb, gint *pOffset, int hfIndex)
{
proto_item *item = proto_tree_add_item(tree, hfIndex, tvb, *pOffset, 1, ENC_LITTLE_ENDIAN);
*pOffset+=1;
return item;
}
proto_item* parseUInt16(proto_tree *tree, tvbuff_t *tvb, gint *pOffset, int hfIndex)
{
proto_item *item = proto_tree_add_item(tree, hfIndex, tvb, *pOffset, 2, ENC_LITTLE_ENDIAN);
*pOffset+=2;
return item;
}
proto_item* parseInt16(proto_tree *tree, tvbuff_t *tvb, gint *pOffset, int hfIndex)
{
proto_item *item = proto_tree_add_item(tree, hfIndex, tvb, *pOffset, 2, ENC_LITTLE_ENDIAN);
*pOffset+=2;
return item;
}
proto_item* parseUInt32(proto_tree *tree, tvbuff_t *tvb, gint *pOffset, int hfIndex)
{
proto_item *item = proto_tree_add_item(tree, hfIndex, tvb, *pOffset, 4, ENC_LITTLE_ENDIAN);
*pOffset+=4;
return item;
}
proto_item* parseInt32(proto_tree *tree, tvbuff_t *tvb, gint *pOffset, int hfIndex)
{
proto_item *item = proto_tree_add_item(tree, hfIndex, tvb, *pOffset, 4, ENC_LITTLE_ENDIAN);
*pOffset+=4;
return item;
}
proto_item* parseUInt64(proto_tree *tree, tvbuff_t *tvb, gint *pOffset, int hfIndex)
{
proto_item *item = proto_tree_add_item(tree, hfIndex, tvb, *pOffset, 8, ENC_LITTLE_ENDIAN);
*pOffset+=8;
return item;
}
proto_item* parseInt64(proto_tree *tree, tvbuff_t *tvb, gint *pOffset, int hfIndex)
{
proto_item *item = proto_tree_add_item(tree, hfIndex, tvb, *pOffset, 8, ENC_LITTLE_ENDIAN);
*pOffset+=8;
return item;
}
proto_item* parseString(proto_tree *tree, tvbuff_t *tvb, gint *pOffset, int hfIndex)
{
proto_item *item = NULL;
char *szValue;
gint iOffset = *pOffset;
gint32 iLen = tvb_get_letohl(tvb, *pOffset);
iOffset+=4;
if (iLen == -1)
{
item = proto_tree_add_item(tree, hfIndex, tvb, *pOffset, 0, ENC_NA);
proto_item_append_text(item, "[OpcUa Null String]");
proto_item_set_end(item, tvb, *pOffset + 4);
}
else if (iLen == 0)
{
item = proto_tree_add_item(tree, hfIndex, tvb, *pOffset, 0, ENC_NA);
proto_item_append_text(item, "[OpcUa Empty String]");
proto_item_set_end(item, tvb, *pOffset + 4);
}
else if (iLen > 0)
{
item = proto_tree_add_item(tree, hfIndex, tvb, iOffset, iLen, ENC_UTF_8|ENC_NA);
iOffset += iLen;
}
else
{
item = proto_tree_add_item(tree, hfIndex, tvb, *pOffset, 0, ENC_NA);
szValue = wmem_strdup_printf(wmem_packet_scope(), "[Invalid String] Invalid length: %d", iLen);
proto_item_append_text(item, "%s", szValue);
proto_item_set_end(item, tvb, *pOffset + 4);
}
*pOffset = iOffset;
return item;
}
proto_item* parseStatusCode(proto_tree *tree, tvbuff_t *tvb, gint *pOffset, int hfIndex)
{
proto_item *item = NULL;
guint32 uStatusCode = 0;
const gchar *szStatusCode = NULL;
item = proto_tree_add_item(tree, hfIndex, tvb, *pOffset, 4, ENC_LITTLE_ENDIAN);
uStatusCode = tvb_get_letohl(tvb, *pOffset);
szStatusCode = val_to_str_const(uStatusCode & 0xFFFF0000, g_statusCodes, "Unknown Status Code");
proto_item_append_text(item, " [%s]", szStatusCode);
if (uStatusCode & 0x0000FFFF)
{
gint iOffset = *pOffset;
proto_tree *flags_tree;
proto_item *ti_inner;
flags_tree = proto_item_add_subtree(item, ett_opcua_statuscode);
proto_tree_add_item(flags_tree, hf_opcua_status_StructureChanged, tvb, iOffset, 2, ENC_LITTLE_ENDIAN);
proto_tree_add_item(flags_tree, hf_opcua_status_SemanticsChanged, tvb, iOffset, 2, ENC_LITTLE_ENDIAN);
ti_inner = proto_tree_add_item(flags_tree, hf_opcua_status_InfoType, tvb, iOffset, 2, ENC_LITTLE_ENDIAN);
switch (uStatusCode & 0x00000C00)
{
case STATUSCODE_INFOTYPE_DATAVALUE:
{
proto_tree *tree_inner;
tree_inner = proto_item_add_subtree(ti_inner, ett_opcua_statuscode_info);
proto_tree_add_item(tree_inner, hf_opcua_status_Limit, tvb, iOffset, 2, ENC_LITTLE_ENDIAN);
proto_tree_add_item(tree_inner, hf_opcua_status_InfoBit_Limit_Overflow, tvb, iOffset, 2, ENC_LITTLE_ENDIAN);
proto_tree_add_item(tree_inner, hf_opcua_status_InfoBit_Historian_MultiValue, tvb, iOffset, 2, ENC_LITTLE_ENDIAN);
proto_tree_add_item(tree_inner, hf_opcua_status_InfoBit_Historian_ExtraData, tvb, iOffset, 2, ENC_LITTLE_ENDIAN);
proto_tree_add_item(tree_inner, hf_opcua_status_InfoBit_Historian_Partial, tvb, iOffset, 2, ENC_LITTLE_ENDIAN);
proto_tree_add_item(tree_inner, hf_opcua_status_Historian, tvb, iOffset, 2, ENC_LITTLE_ENDIAN);
}
default:
break;
}
}
*pOffset += 4;
return item;
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
mask_tree = proto_item_add_subtree(ti_inner, ett_opcua_localizedtext_encodingmask);
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
proto_item* parseGuid(proto_tree *tree, tvbuff_t *tvb, gint *pOffset, int hfIndex)
{
proto_item *item = proto_tree_add_item(tree, hfIndex, tvb, *pOffset, GUID_LEN, ENC_NA);
*pOffset+=GUID_LEN;
return item;
}
proto_item* parseByteString(proto_tree *tree, tvbuff_t *tvb, gint *pOffset, int hfIndex)
{
proto_item *item = NULL;
char *szValue;
int iOffset = *pOffset;
gint32 iLen = tvb_get_letohl(tvb, iOffset);
iOffset += 4;
if (iLen == -1)
{
item = proto_tree_add_item(tree, hfIndex, tvb, *pOffset, 0, ENC_NA);
proto_item_append_text(item, "[OpcUa Null ByteString]");
proto_item_set_end(item, tvb, *pOffset + 4);
}
else if (iLen == 0)
{
item = proto_tree_add_item(tree, hfIndex, tvb, *pOffset, 0, ENC_NA);
proto_item_append_text(item, "[OpcUa Empty ByteString]");
proto_item_set_end(item, tvb, *pOffset + 4);
}
else if (iLen > 0)
{
item = proto_tree_add_item(tree, hfIndex, tvb, iOffset, iLen, ENC_NA);
iOffset += iLen;
}
else
{
item = proto_tree_add_item(tree, hfIndex, tvb, *pOffset, 0, ENC_NA);
szValue = wmem_strdup_printf(wmem_packet_scope(), "[Invalid ByteString] Invalid length: %d", iLen);
proto_item_append_text(item, "%s", szValue);
proto_item_set_end(item, tvb, *pOffset + 4);
}
*pOffset = iOffset;
return item;
}
proto_item* parseXmlElement(proto_tree *tree, tvbuff_t *tvb, gint *pOffset, int hfIndex)
{
return parseByteString(tree, tvb, pOffset, hfIndex);
}
proto_item* parseFloat(proto_tree *tree, tvbuff_t *tvb, gint *pOffset, int hfIndex)
{
proto_item *item = proto_tree_add_item(tree, hfIndex, tvb, *pOffset, (int)sizeof(gfloat), ENC_LITTLE_ENDIAN);
*pOffset += (int)sizeof(gfloat);
return item;
}
proto_item* parseDouble(proto_tree *tree, tvbuff_t *tvb, gint *pOffset, int hfIndex)
{
proto_item *item = proto_tree_add_item(tree, hfIndex, tvb, *pOffset, (int)sizeof(gdouble), ENC_LITTLE_ENDIAN);
*pOffset += (int)sizeof(gdouble);
return item;
}
proto_item* parseDateTime(proto_tree *tree, tvbuff_t *tvb, gint *pOffset, int hfIndex)
{
proto_item *item = NULL;
*pOffset = dissect_nt_64bit_time_ex(tvb, tree, *pOffset, hfIndex, &item);
return item;
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
mask_tree = proto_item_add_subtree(ti_inner, ett_opcua_diagnosticinfo_encodingmask);
proto_tree_add_item(mask_tree, hf_opcua_diag_mask_symbolicflag, tvb, iOffset, 1, ENC_LITTLE_ENDIAN);
proto_tree_add_item(mask_tree, hf_opcua_diag_mask_namespaceflag, tvb, iOffset, 1, ENC_LITTLE_ENDIAN);
proto_tree_add_item(mask_tree, hf_opcua_diag_mask_localizedtextflag, tvb, iOffset, 1, ENC_LITTLE_ENDIAN);
proto_tree_add_item(mask_tree, hf_opcua_diag_mask_localeflag, tvb, iOffset, 1, ENC_LITTLE_ENDIAN);
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
if (EncodingMask & DIAGNOSTICINFO_ENCODINGMASK_LOCALE_FLAG)
{
parseInt32(subtree, tvb, &iOffset, hf_opcua_diag_locale);
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
mask_tree = proto_item_add_subtree(ti_inner, ett_opcua_datavalue_encodingmask);
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
case OpcUaType_Boolean: parseArraySimple(subtree, tvb, &iOffset, "Boolean", "Boolean", hf_opcua_Boolean, parseBoolean, ett_opcua_array_Boolean); break;
case OpcUaType_SByte: parseArraySimple(subtree, tvb, &iOffset, "SByte", "SByte", hf_opcua_SByte, parseSByte, ett_opcua_array_SByte); break;
case OpcUaType_Byte: parseArraySimple(subtree, tvb, &iOffset, "Byte", "Byte", hf_opcua_Byte, parseByte, ett_opcua_array_Byte); break;
case OpcUaType_Int16: parseArraySimple(subtree, tvb, &iOffset, "Int16", "Int16", hf_opcua_Int16, parseInt16, ett_opcua_array_Int16); break;
case OpcUaType_UInt16: parseArraySimple(subtree, tvb, &iOffset, "UInt16", "UInt16", hf_opcua_UInt16, parseUInt16, ett_opcua_array_UInt16); break;
case OpcUaType_Int32: parseArraySimple(subtree, tvb, &iOffset, "Int32", "Int32", hf_opcua_Int32, parseInt32, ett_opcua_array_Int32); break;
case OpcUaType_UInt32: parseArraySimple(subtree, tvb, &iOffset, "UInt32", "UInt32", hf_opcua_UInt32, parseUInt32, ett_opcua_array_UInt32); break;
case OpcUaType_Int64: parseArraySimple(subtree, tvb, &iOffset, "Int64", "Int64", hf_opcua_Int64, parseInt64, ett_opcua_array_Int64); break;
case OpcUaType_UInt64: parseArraySimple(subtree, tvb, &iOffset, "UInt64", "UInt64", hf_opcua_UInt64, parseUInt64, ett_opcua_array_UInt64); break;
case OpcUaType_Float: parseArraySimple(subtree, tvb, &iOffset, "Float", "Float", hf_opcua_Float, parseFloat, ett_opcua_array_Float); break;
case OpcUaType_Double: parseArraySimple(subtree, tvb, &iOffset, "Double", "Double", hf_opcua_Double, parseDouble, ett_opcua_array_Double); break;
case OpcUaType_String: parseArraySimple(subtree, tvb, &iOffset, "String", "String", hf_opcua_String, parseString, ett_opcua_array_String); break;
case OpcUaType_DateTime: parseArraySimple(subtree, tvb, &iOffset, "DateTime", "DateTime", hf_opcua_DateTime, parseDateTime, ett_opcua_array_DateTime); break;
case OpcUaType_Guid: parseArraySimple(subtree, tvb, &iOffset, "Guid", "Guid", hf_opcua_Guid, parseGuid, ett_opcua_array_Guid); break;
case OpcUaType_ByteString: parseArraySimple(subtree, tvb, &iOffset, "ByteString", "ByteString", hf_opcua_ByteString, parseByteString, ett_opcua_array_ByteString); break;
case OpcUaType_XmlElement: parseArraySimple(subtree, tvb, &iOffset, "XmlElement", "XmlElement", hf_opcua_XmlElement, parseXmlElement, ett_opcua_array_XmlElement); break;
case OpcUaType_NodeId: parseArrayComplex(subtree, tvb, &iOffset, "NodeId", "NodeId", parseNodeId, ett_opcua_array_NodeId); break;
case OpcUaType_ExpandedNodeId: parseArrayComplex(subtree, tvb, &iOffset, "ExpandedNodeId", "ExpandedNodeId", parseExpandedNodeId, ett_opcua_array_ExpandedNodeId); break;
case OpcUaType_StatusCode: parseArraySimple(subtree, tvb, &iOffset, "StatusCode", "StatusCode", hf_opcua_StatusCode, parseStatusCode, ett_opcua_array_StatusCode); break;
case OpcUaType_DiagnosticInfo: parseArrayComplex(subtree, tvb, &iOffset, "DiagnosticInfo", "DiagnosticInfo", parseDiagnosticInfo, ett_opcua_array_DiagnosticInfo); break;
case OpcUaType_QualifiedName: parseArrayComplex(subtree, tvb, &iOffset, "QualifiedName", "QualifiedName", parseQualifiedName, ett_opcua_array_QualifiedName); break;
case OpcUaType_LocalizedText: parseArrayComplex(subtree, tvb, &iOffset, "LocalizedText", "LocalizedText", parseLocalizedText, ett_opcua_array_LocalizedText); break;
case OpcUaType_ExtensionObject: parseArrayComplex(subtree, tvb, &iOffset, "ExtensionObject", "ExtensionObject", parseExtensionObject, ett_opcua_array_ExtensionObject); break;
case OpcUaType_DataValue: parseArrayComplex(subtree, tvb, &iOffset, "DataValue", "DataValue", parseDataValue, ett_opcua_array_DataValue); break;
case OpcUaType_Variant: parseArrayComplex(subtree, tvb, &iOffset, "Variant", "Variant", parseVariant, ett_opcua_array_Variant); break;
}
if (EncodingMask & VARIANT_ARRAYDIMENSIONS)
{
proto_item *ti_2 = proto_tree_add_text(subtree, tvb, iOffset, -1, "ArrayDimensions");
proto_tree *subtree_2 = proto_item_add_subtree(ti_2, ett_opcua_variant_arraydims);
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
void parseArraySimple(proto_tree *tree, tvbuff_t *tvb, gint *pOffset, const char *szFieldName, const char *szTypeName, int hfIndex, fctSimpleTypeParser pParserFunction, const gint idx)
{
proto_item *ti = proto_tree_add_text(tree, tvb, *pOffset, -1, "%s: Array of %s", szFieldName, szTypeName);
proto_tree *subtree = proto_item_add_subtree(ti, idx);
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
proto_item *arrayItem = (*pParserFunction)(subtree, tvb, pOffset, hfIndex);
if (arrayItem != NULL)
{
proto_item_prepend_text(arrayItem, "[%i]: ", i);
}
}
proto_item_set_end(ti, tvb, *pOffset);
}
void parseArrayEnum(proto_tree *tree, tvbuff_t *tvb, gint *pOffset, const char *szFieldName, const char *szTypeName, fctEnumParser pParserFunction, const gint idx)
{
proto_item *ti = proto_tree_add_text(tree, tvb, *pOffset, -1, "%s: Array of %s", szFieldName, szTypeName);
proto_tree *subtree = proto_item_add_subtree(ti, idx);
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
void parseArrayComplex(proto_tree *tree, tvbuff_t *tvb, gint *pOffset, const char *szFieldName, const char *szTypeName, fctComplexTypeParser pParserFunction, const gint idx)
{
proto_item *ti = proto_tree_add_text(tree, tvb, *pOffset, -1, "%s: Array of %s", szFieldName, szTypeName);
proto_tree *subtree = proto_item_add_subtree(ti, idx);
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
proto_tree_add_item(subtree, hf_opcua_nodeid_nsindex, tvb, iOffset, 1, ENC_LITTLE_ENDIAN);
iOffset+=1;
proto_tree_add_item(subtree, hf_opcua_nodeid_numeric, tvb, iOffset, 2, ENC_LITTLE_ENDIAN);
iOffset+=2;
break;
case 0x02:
proto_tree_add_item(subtree, hf_opcua_nodeid_nsindex, tvb, iOffset, 2, ENC_LITTLE_ENDIAN);
iOffset+=2;
proto_tree_add_item(subtree, hf_opcua_nodeid_numeric, tvb, iOffset, 4, ENC_LITTLE_ENDIAN);
iOffset+=4;
break;
case 0x03:
proto_tree_add_item(subtree, hf_opcua_nodeid_nsindex, tvb, iOffset, 2, ENC_LITTLE_ENDIAN);
iOffset+=2;
parseString(subtree, tvb, &iOffset, hf_opcua_nodeid_string);
break;
case 0x04:
proto_tree_add_item(subtree, hf_opcua_nodeid_nsindex, tvb, iOffset, 2, ENC_LITTLE_ENDIAN);
iOffset+=2;
parseGuid(subtree, tvb, &iOffset, hf_opcua_nodeid_guid);
break;
case 0x05:
proto_tree_add_item(subtree, hf_opcua_nodeid_nsindex, tvb, iOffset, 2, ENC_LITTLE_ENDIAN);
iOffset+=2;
parseByteString(subtree, tvb, &iOffset, hf_opcua_nodeid_bytestring);
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
ti = proto_tree_add_text(tree, tvb, *pOffset, -1, "%s: ExtensionObject", szFieldName);
extobj_tree = proto_item_add_subtree(ti, ett_opcua_extensionobject);
TypeId = getExtensionObjectType(tvb, &iOffset);
parseExpandedNodeId(extobj_tree, tvb, &iOffset, "TypeId");
EncodingMask = tvb_get_guint8(tvb, iOffset);
ti_inner = proto_tree_add_text(extobj_tree, tvb, iOffset, 1, "EncodingMask");
mask_tree = proto_item_add_subtree(ti_inner, ett_opcua_extensionobject_encodingmask);
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
proto_tree *subtree = proto_item_add_subtree(ti, ett_opcua_expandednodeid);
gint iOffset = *pOffset;
guint8 EncodingMask;
EncodingMask = tvb_get_guint8(tvb, iOffset);
proto_tree_add_item(subtree, hf_opcua_nodeid_encodingmask, tvb, iOffset, 1, ENC_LITTLE_ENDIAN);
proto_tree_add_item(subtree, hf_opcua_expandednodeid_mask_namespaceuri, tvb, iOffset, 1, ENC_LITTLE_ENDIAN);
proto_tree_add_item(subtree, hf_opcua_expandednodeid_mask_serverindex, tvb, iOffset, 1, ENC_LITTLE_ENDIAN);
iOffset++;
switch(EncodingMask & 0x0F)
{
case 0x00:
proto_tree_add_item(subtree, hf_opcua_nodeid_numeric, tvb, iOffset, 1, ENC_LITTLE_ENDIAN);
iOffset+=1;
break;
case 0x01:
proto_tree_add_item(subtree, hf_opcua_nodeid_nsindex, tvb, iOffset, 1, ENC_LITTLE_ENDIAN);
iOffset+=1;
proto_tree_add_item(subtree, hf_opcua_nodeid_numeric, tvb, iOffset, 2, ENC_LITTLE_ENDIAN);
iOffset+=2;
break;
case 0x02:
proto_tree_add_item(subtree, hf_opcua_nodeid_nsindex, tvb, iOffset, 2, ENC_LITTLE_ENDIAN);
iOffset+=2;
proto_tree_add_item(subtree, hf_opcua_nodeid_numeric, tvb, iOffset, 4, ENC_LITTLE_ENDIAN);
iOffset+=4;
break;
case 0x03:
proto_tree_add_item(subtree, hf_opcua_nodeid_nsindex, tvb, iOffset, 2, ENC_LITTLE_ENDIAN);
iOffset+=2;
parseString(subtree, tvb, &iOffset, hf_opcua_nodeid_string);
break;
case 0x04:
proto_tree_add_item(subtree, hf_opcua_nodeid_nsindex, tvb, iOffset, 2, ENC_LITTLE_ENDIAN);
iOffset+=2;
parseGuid(subtree, tvb, &iOffset, hf_opcua_nodeid_guid);
break;
case 0x05:
proto_tree_add_item(subtree, hf_opcua_nodeid_nsindex, tvb, iOffset, 2, ENC_LITTLE_ENDIAN);
iOffset+=2;
parseByteString(subtree, tvb, &iOffset, hf_opcua_nodeid_bytestring);
break;
};
if (EncodingMask & NODEID_NAMESPACEURIFLAG)
{
parseString(subtree, tvb, &iOffset, hf_opcua_NamespaceUri);
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
