static
guint8 masked_guint8_value(const guint8 value, const guint8 mask)
{
return (value & mask) >> ws_ctz(mask);
}
static guint64
tvb_get_guintX(tvbuff_t *tvb, const gint offset, const gint size, const guint encoding) {
switch (size) {
case 1:
return tvb_get_guint8(tvb, offset);
case 2:
return tvb_get_guint16(tvb, offset, encoding);
case 3:
return tvb_get_guint24(tvb, offset, encoding);
case 4:
return tvb_get_guint32(tvb, offset, encoding);
case 5:
return tvb_get_guint40(tvb, offset, encoding);
case 6:
return tvb_get_guint48(tvb, offset, encoding);
case 7:
return tvb_get_guint56(tvb, offset, encoding);
case 8:
return tvb_get_guint64(tvb, offset, encoding);
}
return 0;
}
static int
dissect_uds(tvbuff_t *tvb, packet_info *pinfo, proto_tree *tree _U_, void* data _U_)
{
proto_tree *uds_tree, *subtree;
proto_item *ti;
guint8 sid, service;
guint32 enum_val;
const char *service_name;
guint32 data_length = tvb_reported_length(tvb);
col_set_str(pinfo->cinfo, COL_PROTOCOL, "UDS");
col_clear(pinfo->cinfo,COL_INFO);
sid = tvb_get_guint8(tvb, UDS_SID_OFFSET);
service = sid & UDS_SID_MASK;
service_name = val_to_str(service, uds_services, "Unknown (0x%02x)");
col_add_fstr(pinfo->cinfo, COL_INFO, "%-7s %-36s", (sid & UDS_REPLY_MASK)? "Reply": "Request", service_name);
ti = proto_tree_add_item(tree, proto_uds, tvb, 0, -1, ENC_NA);
uds_tree = proto_item_add_subtree(ti, ett_uds);
proto_tree_add_item(uds_tree, hf_uds_service, tvb, UDS_SID_OFFSET, UDS_SID_LEN, ENC_BIG_ENDIAN);
proto_tree_add_item(uds_tree, hf_uds_reply, tvb, UDS_SID_OFFSET, UDS_SID_LEN, ENC_BIG_ENDIAN);
switch (service) {
case UDS_SERVICES_DSC:
subtree = proto_tree_add_subtree(uds_tree, tvb, 0, -1, ett_uds_dsc, NULL, service_name);
proto_tree_add_item_ret_uint(subtree, hf_uds_dsc_type, tvb, UDS_DSC_TYPE_OFFSET, UDS_DSC_TYPE_LEN,
ENC_BIG_ENDIAN, &enum_val);
col_append_fstr(pinfo->cinfo, COL_INFO, " %s", val_to_str(enum_val, uds_dsc_types, "Unknown (0x%02x)"));
if (sid & UDS_REPLY_MASK) {
guint32 parameter_record_length = data_length - UDS_DSC_PARAMETER_RECORD_OFFSET;
proto_tree_add_item(subtree, hf_uds_dsc_parameter_record, tvb,
UDS_DSC_PARAMETER_RECORD_OFFSET, parameter_record_length, ENC_NA);
col_append_fstr(pinfo->cinfo, COL_INFO, " %s",
tvb_bytes_to_str_punct(wmem_packet_scope(), tvb, UDS_DSC_PARAMETER_RECORD_OFFSET,
parameter_record_length, ' '));
}
break;
case UDS_SERVICES_ER:
subtree = proto_tree_add_subtree(uds_tree, tvb, 0, -1, ett_uds_er, NULL, service_name);
proto_tree_add_item_ret_uint(subtree, hf_uds_er_type, tvb, UDS_ER_TYPE_OFFSET, UDS_ER_TYPE_LEN, ENC_BIG_ENDIAN, &enum_val);
col_append_fstr(pinfo->cinfo, COL_INFO, " %s", val_to_str(enum_val, uds_er_types, "Unknown (0x%02x)"));
break;
case UDS_SERVICES_RDTCI: {
guint32 record_length = data_length - UDS_RDTCI_RECORD_OFFSET;
subtree = proto_tree_add_subtree(uds_tree, tvb, 0, -1, ett_uds_rdtci, NULL, service_name);
proto_tree_add_item_ret_uint(subtree, hf_uds_rdtci_type, tvb, UDS_RDTCI_TYPE_OFFSET,
UDS_RDTCI_TYPE_LEN, ENC_BIG_ENDIAN, &enum_val);
proto_tree_add_item(subtree, hf_uds_rdtci_record, tvb,
UDS_RDTCI_RECORD_OFFSET, record_length, ENC_NA);
col_append_fstr(pinfo->cinfo, COL_INFO, " %s %s", val_to_str(enum_val, uds_rdtci_types, "Unknown (0x%02x)"),
tvb_bytes_to_str_punct(wmem_packet_scope(), tvb, UDS_RDTCI_RECORD_OFFSET, record_length, ' '));
break;
}
case UDS_SERVICES_RDBI:
subtree = proto_tree_add_subtree(uds_tree, tvb, 0, -1, ett_uds_rdbi, NULL, service_name);
if (sid & UDS_REPLY_MASK) {
guint32 record_length = data_length - UDS_RDBI_DATA_RECORD_OFFSET;
guint32 data_identifier;
proto_tree_add_item_ret_uint(subtree, hf_uds_rdbi_data_identifier, tvb, UDS_RDBI_DATA_IDENTIFIER_OFFSET,
UDS_RDBI_DATA_IDENTIFIER_LEN, ENC_BIG_ENDIAN, &data_identifier);
proto_tree_add_item(subtree, hf_uds_rdbi_data_record, tvb, UDS_RDBI_DATA_RECORD_OFFSET,
record_length, ENC_NA);
col_append_fstr(pinfo->cinfo, COL_INFO, " 0x%04x %s", data_identifier,
tvb_bytes_to_str_punct(wmem_packet_scope(), tvb, UDS_RDBI_DATA_RECORD_OFFSET,
record_length, ' '));
} else {
guint32 identifier_length = data_length - UDS_RDBI_DATA_IDENTIFIER_OFFSET;
guint32 offset = UDS_RDBI_DATA_IDENTIFIER_OFFSET;
while (identifier_length > 0) {
guint32 data_identifier;
proto_tree_add_item_ret_uint(subtree, hf_uds_rdbi_data_identifier, tvb, offset,
UDS_RDBI_DATA_IDENTIFIER_LEN, ENC_BIG_ENDIAN, &data_identifier);
col_append_fstr(pinfo->cinfo, COL_INFO, " 0x%04x", data_identifier);
offset += UDS_RDBI_DATA_IDENTIFIER_LEN;
identifier_length -= UDS_RDBI_DATA_IDENTIFIER_LEN;
}
}
break;
case UDS_SERVICES_SA:
subtree = proto_tree_add_subtree(uds_tree, tvb, 0, -1, ett_uds_sa, NULL, service_name);
proto_tree_add_item_ret_uint(subtree, hf_uds_sa_type, tvb, UDS_SA_TYPE_OFFSET,
UDS_SA_TYPE_LEN, ENC_BIG_ENDIAN, &enum_val);
col_append_fstr(pinfo->cinfo, COL_INFO, " %s",
val_to_str(enum_val, uds_sa_types, "Unknown (0x%02x)"));
if (sid & UDS_REPLY_MASK) {
guint32 seed_length = data_length - UDS_SA_SEED_OFFSET;
if (seed_length > 0) {
proto_tree_add_item(subtree, hf_uds_sa_seed, tvb, UDS_SA_SEED_OFFSET, seed_length, ENC_NA);
col_append_fstr(pinfo->cinfo, COL_INFO, " %s",
tvb_bytes_to_str_punct(wmem_packet_scope(), tvb, UDS_SA_SEED_OFFSET, seed_length,
' '));
}
} else {
guint32 key_length = data_length - UDS_SA_KEY_OFFSET;
if (key_length > 0) {
proto_tree_add_item(subtree, hf_uds_sa_key, tvb, UDS_SA_KEY_OFFSET, key_length, ENC_NA);
col_append_fstr(pinfo->cinfo, COL_INFO, " %s",
tvb_bytes_to_str_punct(wmem_packet_scope(), tvb, UDS_SA_KEY_OFFSET, key_length,
' '));
}
}
break;
case UDS_SERVICES_WDBI:
subtree = proto_tree_add_subtree(uds_tree, tvb, 0, -1, ett_uds_wdbi, NULL, service_name);
proto_tree_add_item_ret_uint(subtree, hf_uds_wdbi_data_identifier, tvb, UDS_WDBI_DATA_IDENTIFIER_OFFSET,
UDS_WDBI_DATA_IDENTIFIER_LEN, ENC_BIG_ENDIAN, &enum_val);
if (sid & UDS_REPLY_MASK) {
col_append_fstr(pinfo->cinfo, COL_INFO, " 0x%04x", enum_val);
} else {
guint32 record_length = data_length - UDS_WDBI_DATA_RECORD_OFFSET;
proto_tree_add_item(subtree, hf_uds_wdbi_data_record, tvb, UDS_WDBI_DATA_RECORD_OFFSET,
record_length, ENC_NA);
col_append_fstr(pinfo->cinfo, COL_INFO, " 0x%04x %s", enum_val,
tvb_bytes_to_str_punct(wmem_packet_scope(), tvb, UDS_WDBI_DATA_RECORD_OFFSET,
record_length, ' '));
}
break;
case UDS_SERVICES_IOCBI: {
guint32 data_identifier;
guint32 state_length = data_length - UDS_IOCBI_STATE_OFFSET;
subtree = proto_tree_add_subtree(uds_tree, tvb, 0, -1, ett_uds_iocbi, NULL, service_name);
proto_tree_add_item_ret_uint(subtree, hf_uds_iocbi_data_identifier, tvb, UDS_IOCBI_DATA_IDENTIFIER_OFFSET,
UDS_IOCBI_DATA_IDENTIFIER_LEN, ENC_BIG_ENDIAN, &data_identifier);
proto_tree_add_item_ret_uint(subtree, hf_uds_iocbi_parameter, tvb, UDS_IOCBI_PARAMETER_OFFSET,
UDS_IOCBI_PARAMETER_LEN, ENC_BIG_ENDIAN, &enum_val);
proto_tree_add_item(subtree, hf_uds_iocbi_state, tvb, UDS_IOCBI_STATE_OFFSET,
state_length, ENC_NA);
col_append_fstr(pinfo->cinfo, COL_INFO, " 0x%04x %s %s", data_identifier,
val_to_str(enum_val, uds_iocbi_parameters, "Unknown (0x%02x)"),
tvb_bytes_to_str_punct(wmem_packet_scope(), tvb, UDS_IOCBI_STATE_OFFSET,
state_length, ' '));
break;
}
case UDS_SERVICES_RC: {
guint32 identifier;
subtree = proto_tree_add_subtree(uds_tree, tvb, 0, -1, ett_uds_rc, NULL, service_name);
proto_tree_add_item_ret_uint(subtree, hf_uds_rc_type, tvb, UDS_RC_TYPE_OFFSET,
UDS_RC_TYPE_LEN, ENC_BIG_ENDIAN, &enum_val);
proto_tree_add_item_ret_uint(subtree, hf_uds_rc_identifier, tvb, UDS_RC_ROUTINE_OFFSET,
UDS_RC_ROUTINE_LEN, ENC_BIG_ENDIAN, &identifier);
col_append_fstr(pinfo->cinfo, COL_INFO, " %s 0x%04x",
val_to_str(enum_val, uds_rc_types, "Unknown (0x%02x)"), identifier);
if (sid & UDS_REPLY_MASK) {
guint32 rc_data_len = data_length - UDS_RC_INFO_OFFSET;
if (rc_data_len > 0) {
guint8 info = tvb_get_guint8(tvb, UDS_RC_INFO_OFFSET);
proto_tree_add_item(subtree, hf_uds_rc_info, tvb,
UDS_RC_INFO_OFFSET, UDS_RC_INFO_LEN, ENC_BIG_ENDIAN);
col_append_fstr(pinfo->cinfo, COL_INFO, " 0x%x", info);
if (rc_data_len > 1) {
guint32 status_record_len = data_length - UDS_RC_STATUS_RECORD_OFFSET;
proto_tree_add_item(subtree, hf_uds_rc_status_record, tvb,
UDS_RC_STATUS_RECORD_OFFSET, status_record_len, ENC_NA);
col_append_fstr(pinfo->cinfo, COL_INFO, " %s",
tvb_bytes_to_str_punct(wmem_packet_scope(), tvb,
UDS_RC_STATUS_RECORD_OFFSET, status_record_len, ' '));
}
}
} else {
guint32 option_record_len = data_length - UDS_RC_OPTION_RECORD_OFFSET;
if (option_record_len > 0) {
proto_tree_add_item(subtree, hf_uds_rc_option_record, tvb,
UDS_RC_OPTION_RECORD_OFFSET, option_record_len, ENC_NA);
col_append_fstr(pinfo->cinfo, COL_INFO, " %s",
tvb_bytes_to_str_punct(wmem_packet_scope(), tvb,
UDS_RC_OPTION_RECORD_OFFSET, option_record_len, ' '));
}
}
break;
}
case UDS_SERVICES_RD:
subtree = proto_tree_add_subtree(uds_tree, tvb, 0, -1, ett_uds_rd, NULL, service_name);
if (sid & UDS_REPLY_MASK) {
guint8 length_format_identifier, max_number_of_block_length_length;
guint64 max_number_of_block_length;
length_format_identifier = tvb_get_guint8(tvb, UDS_RD_LENGTH_FORMAT_IDENTIFIER_OFFSET);
max_number_of_block_length_length = masked_guint8_value(length_format_identifier,
UDS_RD_MAX_NUMBER_OF_BLOCK_LENGTH_LENGTH_MASK);
proto_tree_add_item(subtree, hf_uds_rd_max_number_of_block_length_length, tvb,
UDS_RD_LENGTH_FORMAT_IDENTIFIER_OFFSET,
UDS_RD_LENGTH_FORMAT_IDENTIFIER_LEN, ENC_BIG_ENDIAN);
max_number_of_block_length = tvb_get_guintX(tvb, UDS_RD_MAX_NUMBER_OF_BLOCK_LENGTH_OFFSET,
max_number_of_block_length_length, ENC_BIG_ENDIAN);
proto_tree_add_item(subtree, hf_uds_rd_max_number_of_block_length, tvb,
UDS_RD_MAX_NUMBER_OF_BLOCK_LENGTH_OFFSET,
max_number_of_block_length_length, ENC_BIG_ENDIAN);
col_append_fstr(pinfo->cinfo, COL_INFO, " Max Number Of Block Length 0x%" G_GINT64_MODIFIER "x",
max_number_of_block_length);
} else {
guint8 data_format_identifier, compression, encryting;
guint8 address_and_length_format_idenfifier, memory_size_length, memory_address_length;
guint64 memory_size, memory_address;
data_format_identifier = tvb_get_guint8(tvb, UDS_RD_DATA_FORMAT_IDENTIFIER_OFFSET);
compression = masked_guint8_value(data_format_identifier, UDS_RD_COMPRESSION_METHOD_MASK);
proto_tree_add_item(subtree, hf_uds_rd_compression_method, tvb,
UDS_RD_DATA_FORMAT_IDENTIFIER_OFFSET,
UDS_RD_DATA_FORMAT_IDENTIFIER_LEN, ENC_BIG_ENDIAN);
encryting = masked_guint8_value(data_format_identifier, UDS_RD_ENCRYPTING_METHOD_MASK);
proto_tree_add_item(subtree, hf_uds_rd_encrypting_method, tvb, UDS_RD_DATA_FORMAT_IDENTIFIER_OFFSET,
UDS_RD_DATA_FORMAT_IDENTIFIER_LEN, ENC_BIG_ENDIAN);
address_and_length_format_idenfifier = tvb_get_guint8(tvb, UDS_RD_ADDRESS_AND_LENGTH_FORMAT_IDENTIFIER_OFFSET);
memory_size_length = masked_guint8_value(address_and_length_format_idenfifier,
UDS_RD_COMPRESSION_METHOD_MASK);
proto_tree_add_item(subtree, hf_uds_rd_memory_size_length, tvb,
UDS_RD_ADDRESS_AND_LENGTH_FORMAT_IDENTIFIER_OFFSET,
UDS_RD_ADDRESS_AND_LENGTH_FORMAT_IDENTIFIER_LEN, ENC_BIG_ENDIAN);
memory_address_length = masked_guint8_value(address_and_length_format_idenfifier,
UDS_RD_ENCRYPTING_METHOD_MASK);
proto_tree_add_item(subtree, hf_uds_rd_memory_address_length, tvb,
UDS_RD_ADDRESS_AND_LENGTH_FORMAT_IDENTIFIER_OFFSET,
UDS_RD_ADDRESS_AND_LENGTH_FORMAT_IDENTIFIER_LEN, ENC_BIG_ENDIAN);
memory_address = tvb_get_guintX(tvb, UDS_RD_MEMORY_ADDRESS_OFFSET, memory_address_length,
ENC_BIG_ENDIAN);
proto_tree_add_item(subtree, hf_uds_rd_memory_address, tvb, UDS_RD_MEMORY_ADDRESS_OFFSET,
memory_address_length, ENC_BIG_ENDIAN);
memory_size = tvb_get_guintX(tvb, UDS_RD_MEMORY_ADDRESS_OFFSET + memory_address_length,
memory_size_length, ENC_BIG_ENDIAN);
proto_tree_add_item(subtree, hf_uds_rd_memory_size, tvb,
UDS_RD_MEMORY_ADDRESS_OFFSET + memory_address_length,
memory_size_length, ENC_BIG_ENDIAN);
col_append_fstr(pinfo->cinfo, COL_INFO, " 0x%" G_GINT64_MODIFIER "x bytes at 0x%" G_GINT64_MODIFIER "x", memory_size, memory_address);
col_append_fstr(pinfo->cinfo, COL_INFO, " (Compression:0x%x Encrypting:0x%x)", compression,
encryting);
}
break;
case UDS_SERVICES_TP: {
guint8 sub_function_a, sub_function;
subtree = proto_tree_add_subtree(uds_tree, tvb, 0, -1, ett_uds_tp, NULL, service_name);
sub_function_a = tvb_get_guint8(tvb, UDS_TP_SUB_FUNCTION_OFFSET);
sub_function = masked_guint8_value(sub_function_a, UDS_TP_SUB_FUNCTION_MASK);
proto_tree_add_item(subtree, hf_uds_tp_sub_function, tvb,
UDS_TP_SUB_FUNCTION_OFFSET, UDS_TP_SUB_FUNCTION_LEN, ENC_BIG_ENDIAN);
col_append_fstr(pinfo->cinfo, COL_INFO, " Sub-function %x", sub_function);
if (!(sid & UDS_REPLY_MASK)) {
guint8 suppress = masked_guint8_value(sub_function_a, UDS_TP_SUPPRESS_POS_RSP_MSG_INDIFICATION_MASK);
proto_tree_add_item(subtree, hf_uds_tp_suppress_pos_rsp_msg_indification, tvb,
UDS_TP_SUB_FUNCTION_OFFSET, UDS_TP_SUB_FUNCTION_LEN, ENC_BIG_ENDIAN);
if (suppress) {
col_append_fstr(pinfo->cinfo, COL_INFO, " (Reply suppressed)");
}
}
break;
}
case UDS_SERVICES_ERR: {
subtree = proto_tree_add_subtree(uds_tree, tvb, 0, -1, ett_uds_err, NULL, service_name);
proto_tree_add_item_ret_uint(subtree, hf_uds_err_sid, tvb, UDS_ERR_SID_OFFSET, UDS_ERR_SID_LEN, ENC_BIG_ENDIAN, &enum_val);
col_append_fstr(pinfo->cinfo, COL_INFO, " %s", val_to_str(enum_val, uds_services, "Unknown (0x%02x)"));
proto_tree_add_item_ret_uint(subtree, hf_uds_err_code, tvb, UDS_ERR_CODE_OFFSET, UDS_ERR_CODE_LEN,
ENC_BIG_ENDIAN, &enum_val);
col_append_fstr(pinfo->cinfo, COL_INFO, " (SID: %s)", val_to_str(enum_val, uds_response_codes, "Unknown (0x%02x)"));
break;
}
case UDS_SERVICES_CDTCS: {
subtree = proto_tree_add_subtree(uds_tree, tvb, 0, -1, ett_uds_cdtcs, NULL, service_name);
proto_tree_add_item_ret_uint(subtree, hf_uds_cdtcs_type, tvb,
UDS_CDTCS_TYPE_OFFSET, UDS_CDTCS_TYPE_LEN, ENC_BIG_ENDIAN, &enum_val);
col_append_fstr(pinfo->cinfo, COL_INFO, " %s",
val_to_str(enum_val, uds_cdtcs_types, "Unknown (0x%02x)"));
break;
}
}
return tvb_captured_length(tvb);
}
void
proto_register_uds(void)
{
static hf_register_info hf[] = {
{
&hf_uds_service,
{
"Service Identifier", "uds.sid",
FT_UINT8, BASE_HEX,
VALS(uds_services), UDS_SID_MASK,
NULL, HFILL
}
},
{
&hf_uds_reply,
{
"Reply Flag", "uds.reply",
FT_UINT8, BASE_HEX,
NULL, UDS_REPLY_MASK,
NULL, HFILL
}
},
{
&hf_uds_dsc_type,
{
"Type", "uds.dsc.type",
FT_UINT8, BASE_HEX,
VALS(uds_dsc_types), 0x0,
NULL, HFILL
}
},
{
&hf_uds_dsc_parameter_record,
{
"Parameter Record", "uds.dsc.paramter_record",
FT_BYTES, BASE_NONE,
NULL, 0x0,
NULL, HFILL
}
},
{
&hf_uds_er_type,
{
"Type", "uds.er.type",
FT_UINT8, BASE_HEX,
VALS(uds_er_types), 0x0,
NULL, HFILL
}
},
{
&hf_uds_rdtci_type,
{
"Type", "uds.rdtci.type",
FT_UINT8, BASE_HEX,
VALS(uds_rdtci_types), 0x0,
NULL, HFILL
}
},
{
&hf_uds_rdtci_record,
{
"Record", "uds.rdtci.record",
FT_BYTES, BASE_NONE,
NULL, 0x0,
NULL, HFILL
}
},
{
&hf_uds_rdbi_data_identifier,
{
"Data Identifier", "uds.rdbi.data_identifier",
FT_UINT8, BASE_HEX,
NULL, 0x0,
NULL, HFILL
}
},
{
&hf_uds_rdbi_data_record,
{
"Data Record", "uds.rdbi.data_record",
FT_BYTES, BASE_NONE,
NULL, 0x0,
NULL, HFILL
}
},
{
&hf_uds_sa_type,
{
"Type", "uds.sa.type",
FT_UINT8, BASE_HEX,
NULL, 0x0,
NULL, HFILL
}
},
{
&hf_uds_sa_key,
{
"Key", "uds.sa.key",
FT_BYTES, BASE_NONE,
NULL, 0x0,
NULL, HFILL
}
},
{
&hf_uds_sa_seed,
{
"Seed", "uds.sa.seed",
FT_BYTES, BASE_NONE,
NULL, 0x0,
NULL, HFILL
}
},
{
&hf_uds_wdbi_data_identifier,
{
"Data Identifier", "uds.wdbi.data_identifier",
FT_UINT8, BASE_HEX,
NULL, 0x0,
NULL, HFILL
}
},
{
&hf_uds_wdbi_data_record,
{
"Data Record", "uds.wdbi.data_record",
FT_BYTES, BASE_NONE,
NULL, 0x0,
NULL, HFILL
}
},
{
&hf_uds_iocbi_data_identifier,
{
"Data Identifier", "uds.iocbi.data_identifier",
FT_UINT8, BASE_HEX,
NULL, 0x0,
NULL, HFILL
}
},
{
&hf_uds_iocbi_parameter,
{
"Parameter", "uds.iocbi.parameter",
FT_UINT8, BASE_HEX,
VALS(uds_iocbi_parameters), 0x0,
NULL, HFILL
}
},
{
&hf_uds_iocbi_state,
{
"State", "uds.iocbi.state",
FT_BYTES, BASE_NONE,
NULL, 0x0,
NULL, HFILL
}
},
{
&hf_uds_rc_type,
{
"Type", "uds.rc.type",
FT_UINT8, BASE_HEX,
VALS(uds_rc_types), 0x0,
NULL, HFILL
}
},
{
&hf_uds_rc_identifier,
{
"Identifier", "uds.rc.identifier",
FT_UINT16, BASE_HEX,
NULL, 0x0,
NULL, HFILL
}
},
{
&hf_uds_rc_option_record,
{
"Option record", "uds.rc.option_record",
FT_BYTES, BASE_NONE,
NULL, 0x0,
NULL, HFILL
}
},
{
&hf_uds_rc_info,
{
"Info", "uds.rc.info",
FT_UINT8, BASE_HEX,
NULL, 0x0,
NULL, HFILL
}
},
{
&hf_uds_rc_status_record,
{
"Status Record", "uds.rc.status_record",
FT_BYTES, BASE_NONE,
NULL, 0x0,
NULL, HFILL
}
},
{
&hf_uds_rd_compression_method,
{
"Compression Method", "uds.rd.compression_method",
FT_UINT8, BASE_HEX,
NULL, UDS_RD_COMPRESSION_METHOD_MASK,
NULL, HFILL
}
},
{
&hf_uds_rd_encrypting_method,
{
"Encrypting Method", "uds.rd.encrypting_method",
FT_UINT8, BASE_HEX,
NULL, UDS_RD_ENCRYPTING_METHOD_MASK,
NULL, HFILL
}
},
{
&hf_uds_rd_memory_size_length,
{
"Memory size length", "uds.rd.memory_size_length",
FT_UINT8, BASE_HEX,
NULL, UDS_RD_MEMORY_SIZE_LENGTH_MASK,
NULL, HFILL
}
},
{
&hf_uds_rd_memory_address_length,
{
"Memory address length", "uds.rd.memory_address_length",
FT_UINT8, BASE_HEX,
NULL, UDS_RD_MEMORY_ADDRESS_LENGTH_MASK,
NULL, HFILL
}
},
{
&hf_uds_rd_memory_address,
{
"Memory Address", "uds.rd.memory_address",
FT_UINT64, BASE_HEX,
NULL, 0x0,
NULL, HFILL
}
},
{
&hf_uds_rd_memory_size,
{
"Memory Size", "uds.rd.memory_size",
FT_UINT64, BASE_HEX,
NULL, 0x0,
NULL, HFILL
}
},
{
&hf_uds_rd_max_number_of_block_length_length,
{
"Memory address length", "uds.rd.max_number_of_block_length_length",
FT_UINT8, BASE_HEX,
NULL, UDS_RD_MAX_NUMBER_OF_BLOCK_LENGTH_LENGTH_MASK,
NULL, HFILL
}
},
{
&hf_uds_rd_max_number_of_block_length,
{
"Memory Size", "uds.rd.max_number_of_block_length",
FT_UINT64, BASE_HEX,
NULL, 0x0,
NULL, HFILL
}
},
{
&hf_uds_tp_sub_function,
{
"Suppress reply", "uds.tp.suppress_reply",
FT_UINT8, BASE_HEX,
NULL, UDS_TP_SUB_FUNCTION_MASK,
NULL, HFILL
}
},
{
&hf_uds_tp_suppress_pos_rsp_msg_indification,
{
"Suppress reply", "uds.tp.suppress_reply.indification",
FT_BOOLEAN, 8,
NULL, UDS_TP_SUPPRESS_POS_RSP_MSG_INDIFICATION_MASK,
NULL, HFILL
}
},
{
&hf_uds_err_sid,
{
"Service Identifier", "uds.err.sid",
FT_UINT8, BASE_HEX,
VALS(uds_services), 0x0,
NULL, HFILL
}
},
{
&hf_uds_err_code,
{
"Code", "uds.err.code",
FT_UINT8, BASE_HEX,
VALS(uds_response_codes), 0x0,
NULL, HFILL
}
},
{
&hf_uds_cdtcs_type,
{
"Type", "uds.cdtcs.type",
FT_UINT8, BASE_HEX,
VALS(uds_cdtcs_types), 0x0,
NULL, HFILL
}
},
};
static gint *ett[] =
{
&ett_uds,
&ett_uds_dsc,
&ett_uds_er,
&ett_uds_rdtci,
&ett_uds_rdbi,
&ett_uds_sa,
&ett_uds_wdbi,
&ett_uds_iocbi,
&ett_uds_rc,
&ett_uds_rd,
&ett_uds_tp,
&ett_uds_err,
&ett_uds_cdtcs,
};
proto_uds = proto_register_protocol (
"Unified Diagnostic Services",
"UDS",
"uds"
);
proto_register_field_array(proto_uds, hf, array_length(hf));
proto_register_subtree_array(ett, array_length(ett));
}
void
proto_reg_handoff_uds(void)
{
static dissector_handle_t uds_handle;
uds_handle = create_dissector_handle(dissect_uds, proto_uds);
dissector_add_for_decode_as("iso15765.subdissector", uds_handle);
}
