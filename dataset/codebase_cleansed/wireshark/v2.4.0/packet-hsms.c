static int
dissect_secs_variable(tvbuff_t *tvb, packet_info *pinfo, proto_tree *tree, void *data, int *offset)
{
proto_item *hdr_stream_item;
proto_tree *hsms_data_item_tree, *hsms_data_item_header_tree;
proto_item *hdr_item = NULL;
guint item_format_code = -1;
guint length_bytes = -1;
guint length = 0;
guint *value_length = NULL;
int len = 0;
int itemLength = 0;
item_format_code = (tvb_get_guint8(tvb, *offset) & 0xFC) >> 2;
length_bytes = (tvb_get_guint8(tvb, *offset) & 0x3);
switch (length_bytes)
{
case 3:
length = tvb_get_ntoh24(tvb, *offset + 1);
break;
case 2:
length = tvb_get_ntohs(tvb, *offset + 1);
break;
case 1:
length = tvb_get_guint8(tvb, *offset + 1);
break;
default:
return -1;
}
if (item_format_code != 0)
{
value_length = (guint*)wmem_map_lookup(value_lengths, GUINT_TO_POINTER(item_format_code));
if (length % GPOINTER_TO_UINT(value_length) != 0)
return -1;
length = length / GPOINTER_TO_UINT(value_length);
}
hsms_data_item_tree = proto_tree_add_subtree_format(tree, tvb, *offset, -1, ett_hsms_data_item, &hdr_item, "%s (%d items)", val_to_str(item_format_code, item_format_names, "Unknown (%02o)"), length);
hsms_data_item_header_tree = proto_tree_add_subtree_format(hsms_data_item_tree, tvb, *offset, 1, ett_hsms_header, &hdr_stream_item, "Data format: %s, Length bytes: %d", val_to_str(item_format_code, item_format_names, "Unknown (%02o)"), length_bytes);
proto_tree_add_item(hsms_data_item_header_tree, hf_hsms_data_item_format, tvb, *offset, 1, ENC_BIG_ENDIAN);
proto_tree_add_item(hsms_data_item_header_tree, hf_hsms_data_item_length_bytes, tvb, *offset, 1, ENC_BIG_ENDIAN);
*offset += 1;
len = length_bytes;
proto_tree_add_item(hsms_data_item_tree, hf_hsms_data_item_length, tvb, *offset, len, ENC_BIG_ENDIAN);
*offset += len;
switch(item_format_code)
{
case FORMAT_CODE_BINARY:
value_length = (guint*)wmem_map_lookup(value_lengths, GUINT_TO_POINTER(item_format_code));
len = GPOINTER_TO_UINT(value_length) * length;
proto_tree_add_item(hsms_data_item_tree, hf_hsms_data_item_value_binary, tvb, *offset, len, ENC_NA);
itemLength = len;
*offset += len;
break;
case FORMAT_CODE_ASCII:
value_length = (guint*)wmem_map_lookup(value_lengths, GUINT_TO_POINTER(item_format_code));
len = GPOINTER_TO_UINT(value_length) * length;
proto_tree_add_item(hsms_data_item_tree, hf_hsms_data_item_value_string, tvb, *offset, len, ENC_ASCII|ENC_NA);
itemLength = len;
*offset += len;
break;
default:
for(unsigned int counter=0; counter<length; counter++)
{
if (item_format_code == 0)
{
int subItemLength = dissect_secs_variable(tvb, pinfo, hsms_data_item_tree, data, offset);
if (subItemLength == -1)
{
return -1;
}
itemLength += subItemLength;
}
else
{
value_length = (guint*)wmem_map_lookup(value_lengths, GUINT_TO_POINTER(item_format_code));
len = GPOINTER_TO_UINT(value_length);
switch(item_format_code)
{
case FORMAT_CODE_BOOLEAN:
proto_tree_add_item(hsms_data_item_tree, hf_hsms_data_item_value_boolean, tvb, *offset, len, ENC_BIG_ENDIAN);
break;
case FORMAT_CODE_I8:
proto_tree_add_item(hsms_data_item_tree, hf_hsms_data_item_value_i8, tvb, *offset, len, ENC_BIG_ENDIAN);
break;
case FORMAT_CODE_I1:
proto_tree_add_item(hsms_data_item_tree, hf_hsms_data_item_value_i1, tvb, *offset, len, ENC_BIG_ENDIAN);
break;
case FORMAT_CODE_I2:
proto_tree_add_item(hsms_data_item_tree, hf_hsms_data_item_value_i2, tvb, *offset, len, ENC_BIG_ENDIAN);
break;
case FORMAT_CODE_I4:
proto_tree_add_item(hsms_data_item_tree, hf_hsms_data_item_value_i4, tvb, *offset, len, ENC_BIG_ENDIAN);
break;
case FORMAT_CODE_F8:
proto_tree_add_item(hsms_data_item_tree, hf_hsms_data_item_value_f8, tvb, *offset, len, ENC_BIG_ENDIAN);
break;
case FORMAT_CODE_F4:
proto_tree_add_item(hsms_data_item_tree, hf_hsms_data_item_value_f4, tvb, *offset, len, ENC_BIG_ENDIAN);
break;
case FORMAT_CODE_U8:
proto_tree_add_item(hsms_data_item_tree, hf_hsms_data_item_value_u8, tvb, *offset, len, ENC_BIG_ENDIAN);
break;
case FORMAT_CODE_U1:
proto_tree_add_item(hsms_data_item_tree, hf_hsms_data_item_value_u1, tvb, *offset, len, ENC_BIG_ENDIAN);
break;
case FORMAT_CODE_U2:
proto_tree_add_item(hsms_data_item_tree, hf_hsms_data_item_value_u2, tvb, *offset, len, ENC_BIG_ENDIAN);
break;
case FORMAT_CODE_U4:
proto_tree_add_item(hsms_data_item_tree, hf_hsms_data_item_value_u4, tvb, *offset, len, ENC_BIG_ENDIAN);
break;
default:
return -1;
}
itemLength += len;
*offset += len;
}
}
}
proto_item_set_len(hsms_data_item_tree, itemLength + length_bytes + 1);
return 1 + length_bytes + itemLength;
}
static int
dissect_secs_message(tvbuff_t *tvb, packet_info *pinfo, proto_tree *tree, void *data, int *offset)
{
return dissect_secs_variable(tvb, pinfo, tree, data, offset);
}
static int
dissect_hsms_message(tvbuff_t *tvb, packet_info *pinfo, proto_tree *tree, void *data)
{
proto_item *hdr_item = NULL;
proto_item *ti;
proto_tree *hsms_tree, *hsms_header_tree, *hsms_header_stream_tree;
guint offset = 0;
guint sessionId = -1;
guint byte2 = -1;
guint byte3 = -1;
guint pType = -1;
guint sType = -1;
if (tvb_reported_length(tvb) < HSMS_MIN_LENGTH)
return 0;
if ((tvb_get_ntohl(tvb, 0) + 4) != tvb_reported_length(tvb))
return 0;
sessionId = tvb_get_ntohs(tvb, 4);
byte2 = tvb_get_guint8(tvb, 6);
byte3 = tvb_get_guint8(tvb, 7);
pType = tvb_get_guint8(tvb, 8);
sType = tvb_get_guint8(tvb, 9);
if ((sType == 8) || (sType == 10) || (sType > 127))
return 0;
switch (sType)
{
case STYPE_SECS_DATA:
if (byte2 == 0)
return 0;
break;
case STYPE_SELECT_REQ:
case STYPE_DESELECT_REQ:
case STYPE_SEPARATE_REQ:
if ((byte2 != 0) || (byte3 != 0))
return 0;
if (tvb_reported_length(tvb) > HSMS_MIN_LENGTH)
return 0;
break;
case STYPE_SELECT_RSP:
case STYPE_DESELECT_RSP:
if (byte2 != 0)
return 0;
if (tvb_reported_length(tvb) > HSMS_MIN_LENGTH)
return 0;
break;
case STYPE_LINKTEST_REQ:
case STYPE_LINKTEST_RSP:
if (sessionId != 0xFFFF)
return 0;
if (byte2 != 0)
return 0;
if (byte3 != 0)
return 0;
if (tvb_reported_length(tvb) > HSMS_MIN_LENGTH)
return 0;
break;
case STYPE_REJECT_REQ:
if (tvb_reported_length(tvb) > HSMS_MIN_LENGTH)
return 0;
break;
}
col_set_str(pinfo->cinfo, COL_PROTOCOL, "HSMS");
col_clear(pinfo->cinfo,COL_INFO);
if (sType == STYPE_SECS_DATA)
{
col_add_fstr(pinfo->cinfo, COL_INFO, "HSMS SECS Stream/Function S%02dF%02d",
byte2 & 0x7F, byte3);
}
else
{
col_add_fstr(pinfo->cinfo, COL_INFO, "HSMS Message %s",
val_to_str(sType, stype_names, "Unknown (%02d)"));
}
ti = proto_tree_add_item(tree, proto_hsms, tvb, 0, -1, ENC_NA);
hsms_tree = proto_item_add_subtree(ti, ett_hsms);
proto_tree_add_item(hsms_tree, hf_hsms_packet_length, tvb, offset, 4, ENC_BIG_ENDIAN);
offset += 4;
switch (sType)
{
case STYPE_SECS_DATA:
hsms_header_tree = proto_tree_add_subtree_format(hsms_tree, tvb, offset, 10, ett_hsms_header, &hdr_item, "Header (S%02dF%02d)", byte2 & 0x7F, byte3);
break;
default:
hsms_header_tree = proto_tree_add_subtree_format(hsms_tree, tvb, offset, 10, ett_hsms_header, &hdr_item, "Header (%s)", val_to_str(sType, stype_names, "Unknown (%02d)"));
break;
}
proto_tree_add_item(hsms_header_tree, hf_hsms_header_sessionid, tvb, offset, 2, ENC_BIG_ENDIAN);
offset += 2;
switch (sType)
{
case STYPE_SECS_DATA:
hsms_header_stream_tree = proto_tree_add_subtree_format(hsms_header_tree, tvb, offset, 1, ett_hsms_header, &hdr_item, "Stream %d, Response requested: %s", byte2 & 0x7F, ((byte2 & 0x80) > 0) ? "Yes" : "No");
proto_tree_add_item(hsms_header_stream_tree, hf_hsms_header_wbit, tvb, offset, 1, ENC_BIG_ENDIAN);
proto_tree_add_item(hsms_header_stream_tree, hf_hsms_header_stream, tvb, offset, 1, ENC_BIG_ENDIAN);
offset += 1;
proto_tree_add_item(hsms_header_tree, hf_hsms_header_function, tvb, offset, 1, ENC_BIG_ENDIAN);
offset += 1;
break;
default:
proto_tree_add_item(hsms_header_tree, hf_hsms_header_statusbyte2, tvb, offset, 1, ENC_BIG_ENDIAN);
offset += 1;
proto_tree_add_item(hsms_header_tree, hf_hsms_header_statusbyte3, tvb, offset, 1, ENC_BIG_ENDIAN);
offset += 1;
break;
}
ti = proto_tree_add_item(hsms_header_tree, hf_hsms_header_ptype, tvb, offset, 1, ENC_BIG_ENDIAN);
offset += 1;
if (pType != 0)
expert_add_info(pinfo, ti, &ei_hsms_ptype);
proto_tree_add_item(hsms_header_tree, hf_hsms_header_stype, tvb, offset, 1, ENC_BIG_ENDIAN);
offset += 1;
proto_tree_add_item(hsms_header_tree, hf_hsms_header_system, tvb, offset, 4, ENC_BIG_ENDIAN);
offset += 4;
if (tvb_reported_length(tvb) > HSMS_MIN_LENGTH)
{
if (pType == PTYPE_SECS)
dissect_secs_message(tvb, pinfo, hsms_tree, data, &offset);
}
return offset;
}
static guint
get_hsms_message_len(packet_info *pinfo _U_, tvbuff_t *tvb, int offset, void *data _U_)
{
return (guint)tvb_get_ntohl(tvb, offset) + 4;
}
static int
dissect_hsms(tvbuff_t *tvb, packet_info *pinfo, proto_tree *tree, void *data)
{
tcp_dissect_pdus(tvb, pinfo, tree, TRUE, 4,
get_hsms_message_len, dissect_hsms_message, data);
return tvb_captured_length(tvb);
}
static void
hsms_init(void)
{
value_lengths = wmem_map_new(wmem_epan_scope(), g_direct_hash, g_direct_equal);
wmem_map_insert(value_lengths, GINT_TO_POINTER(FORMAT_CODE_LIST), GINT_TO_POINTER(0));
wmem_map_insert(value_lengths, GINT_TO_POINTER(FORMAT_CODE_BINARY), GINT_TO_POINTER(1));
wmem_map_insert(value_lengths, GINT_TO_POINTER(FORMAT_CODE_BOOLEAN), GINT_TO_POINTER(1));
wmem_map_insert(value_lengths, GINT_TO_POINTER(FORMAT_CODE_ASCII), GINT_TO_POINTER(1));
wmem_map_insert(value_lengths, GINT_TO_POINTER(FORMAT_CODE_JIS8), GINT_TO_POINTER(2));
wmem_map_insert(value_lengths, GINT_TO_POINTER(FORMAT_CODE_2BYTE), GINT_TO_POINTER(2));
wmem_map_insert(value_lengths, GINT_TO_POINTER(FORMAT_CODE_I8), GINT_TO_POINTER(8));
wmem_map_insert(value_lengths, GINT_TO_POINTER(FORMAT_CODE_I1), GINT_TO_POINTER(1));
wmem_map_insert(value_lengths, GINT_TO_POINTER(FORMAT_CODE_I2), GINT_TO_POINTER(2));
wmem_map_insert(value_lengths, GINT_TO_POINTER(FORMAT_CODE_I4), GINT_TO_POINTER(4));
wmem_map_insert(value_lengths, GINT_TO_POINTER(FORMAT_CODE_F8), GINT_TO_POINTER(8));
wmem_map_insert(value_lengths, GINT_TO_POINTER(FORMAT_CODE_F4), GINT_TO_POINTER(4));
wmem_map_insert(value_lengths, GINT_TO_POINTER(FORMAT_CODE_U8), GINT_TO_POINTER(8));
wmem_map_insert(value_lengths, GINT_TO_POINTER(FORMAT_CODE_U1), GINT_TO_POINTER(1));
wmem_map_insert(value_lengths, GINT_TO_POINTER(FORMAT_CODE_U2), GINT_TO_POINTER(2));
wmem_map_insert(value_lengths, GINT_TO_POINTER(FORMAT_CODE_U4), GINT_TO_POINTER(4));
}
void
proto_register_hsms(void)
{
expert_module_t* expert_hsms;
static hf_register_info hf[] = {
{ &hf_hsms_packet_length,
{ "Packet length", "hsms.length",
FT_UINT32, BASE_DEC,
NULL, 0x0,
NULL, HFILL }
},
{ &hf_hsms_header_sessionid,
{ "Session ID", "hsms.header.sessionid",
FT_UINT16, BASE_DEC,
NULL, 0x0,
NULL, HFILL }
},
{ &hf_hsms_header_statusbyte2,
{ "Status byte 2", "hsms.header.statusbyte2",
FT_UINT8, BASE_DEC,
NULL, 0x0,
NULL, HFILL }
},
{ &hf_hsms_header_wbit,
{ "W-bit (Response required)", "hsms.header.wbit",
FT_BOOLEAN, 8,
NULL, 0x80,
NULL, HFILL }
},
{ &hf_hsms_header_stream,
{ "Stream", "hsms.header.stream",
FT_UINT8, BASE_DEC,
NULL, 0x7F,
NULL, HFILL }
},
{ &hf_hsms_header_statusbyte3,
{ "Status byte 3", "hsms.header.statusbyte3",
FT_UINT8, BASE_DEC,
NULL, 0x0,
NULL, HFILL }
},
{ &hf_hsms_header_function,
{ "Function", "hsms.header.function",
FT_UINT8, BASE_DEC,
NULL, 0x0,
NULL, HFILL }
},
{ &hf_hsms_header_ptype,
{ "PType (Presentation type)", "hsms.header.ptype",
FT_UINT8, BASE_DEC,
VALS(ptype_names), 0x0,
NULL, HFILL }
},
{ &hf_hsms_header_stype,
{ "SType (Session type)", "hsms.header.stype",
FT_UINT8, BASE_DEC,
VALS(stype_names), 0x0,
NULL, HFILL }
},
{ &hf_hsms_header_system,
{ "System Bytes", "hsms.header.system",
FT_UINT32, BASE_DEC,
NULL, 0x0,
NULL, HFILL }
},
{ &hf_hsms_data_item_format,
{ "Data type", "hsms.data.item.format",
FT_UINT8, BASE_OCT,
VALS(item_format_names), 0xFC,
NULL, HFILL }
},
{ &hf_hsms_data_item_length_bytes,
{ "Length bytes", "hsms.data.item.length_bytes",
FT_UINT8, BASE_OCT,
NULL, 0x03,
NULL, HFILL }
},
{ &hf_hsms_data_item_length,
{ "Length", "hsms.data.item.length",
FT_UINT32, BASE_DEC,
NULL, 0x00,
NULL, HFILL }
},
{ &hf_hsms_data_item_value_binary,
{ "Value", "hsms.data.item.value.binary",
FT_BYTES, SEP_COLON,
NULL, 0x00,
NULL, HFILL }
},
{ &hf_hsms_data_item_value_boolean,
{ "Value", "hsms.data.item.value.boolean",
FT_BOOLEAN, 8,
NULL, 0x01,
NULL, HFILL }
},
{ &hf_hsms_data_item_value_string,
{ "Value", "hsms.data.item.value.string",
FT_STRING, BASE_NONE,
NULL, 0x00,
NULL, HFILL }
},
{ &hf_hsms_data_item_value_i8,
{ "Value", "hsms.data.item.value.int64",
FT_INT64, BASE_DEC,
NULL, 0x00,
NULL, HFILL }
},
{ &hf_hsms_data_item_value_i1,
{ "Value", "hsms.data.item.value.int8",
FT_INT8, BASE_DEC,
NULL, 0x00,
NULL, HFILL }
},
{ &hf_hsms_data_item_value_i2,
{ "Value", "hsms.data.item.value.int16",
FT_INT16, BASE_DEC,
NULL, 0x00,
NULL, HFILL }
},
{ &hf_hsms_data_item_value_i4,
{ "Value", "hsms.data.item.value.int32",
FT_INT32, BASE_DEC,
NULL, 0x00,
NULL, HFILL }
},
{ &hf_hsms_data_item_value_f8,
{ "Value", "hsms.data.item.value.double",
FT_DOUBLE, BASE_NONE,
NULL, 0x00,
NULL, HFILL }
},
{ &hf_hsms_data_item_value_f4,
{ "Value", "hsms.data.item.value.float",
FT_FLOAT, BASE_NONE,
NULL, 0x00,
NULL, HFILL }
},
{ &hf_hsms_data_item_value_u8,
{ "Value", "hsms.data.item.value.uint64",
FT_UINT64, BASE_DEC,
NULL, 0x00,
NULL, HFILL }
},
{ &hf_hsms_data_item_value_u1,
{ "Value", "hsms.data.item.value.uint8",
FT_UINT8, BASE_DEC,
NULL, 0x00,
NULL, HFILL }
},
{ &hf_hsms_data_item_value_u2,
{ "Value", "hsms.data.item.value.uint16",
FT_UINT16, BASE_DEC,
NULL, 0x00,
NULL, HFILL }
},
{ &hf_hsms_data_item_value_u4,
{ "Value", "hsms.data.item.value.uint32",
FT_UINT32, BASE_DEC,
NULL, 0x00,
NULL, HFILL }
},
};
static gint *ett[] = {
&ett_hsms,
&ett_hsms_header,
&ett_hsms_data,
&ett_hsms_data_item
};
static ei_register_info ei[] = {
{ &ei_hsms_ptype,
{ "hsms.header.ptype.unknown",
PI_RESPONSE_CODE,
PI_NOTE,
"Unknown presentation type (ptype)",
EXPFILL }
}
};
proto_hsms = proto_register_protocol (
"High-speed SECS Message Service Protocol",
"HSMS",
"hsms"
);
proto_register_field_array(proto_hsms, hf, array_length(hf));
proto_register_subtree_array(ett, array_length(ett));
expert_hsms = expert_register_protocol(proto_hsms);
expert_register_field_array(expert_hsms, ei, array_length(ei));
hsms_init();
}
void
proto_reg_handoff_hsms(void)
{
static dissector_handle_t hsms_handle;
hsms_handle = create_dissector_handle(dissect_hsms, proto_hsms);
dissector_add_for_decode_as_with_preference("tcp.port", hsms_handle);
}
