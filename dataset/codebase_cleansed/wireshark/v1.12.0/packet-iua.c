static void
dissect_int_interface_identifier_parameter(tvbuff_t *parameter_tvb, proto_tree *parameter_tree, proto_item *parameter_item)
{
guint16 number_of_ids, id_number;
gint offset;
number_of_ids= (tvb_get_ntohs(parameter_tvb, PARAMETER_LENGTH_OFFSET) - PARAMETER_HEADER_LENGTH) / INT_INTERFACE_ID_LENGTH;
offset = PARAMETER_VALUE_OFFSET;
proto_item_append_text(parameter_item, " (");
for (id_number = 0; id_number < number_of_ids; id_number++) {
proto_tree_add_item(parameter_tree, hf_int_interface_id, parameter_tvb, offset, INT_INTERFACE_ID_LENGTH, ENC_BIG_ENDIAN);
proto_item_append_text(parameter_item, (id_number > 0) ? ", %d" : "%d", tvb_get_ntohl(parameter_tvb, offset));
offset += INT_INTERFACE_ID_LENGTH;
}
proto_item_append_text(parameter_item, ")");
}
static void
dissect_text_interface_identifier_parameter(tvbuff_t *parameter_tvb, proto_tree *parameter_tree, proto_item *parameter_item)
{
guint16 interface_id_length;
interface_id_length = tvb_get_ntohs(parameter_tvb, PARAMETER_LENGTH_OFFSET) - PARAMETER_HEADER_LENGTH;
proto_tree_add_item(parameter_tree, hf_text_interface_id, parameter_tvb, TEXT_INTERFACE_ID_OFFSET, interface_id_length, ENC_ASCII|ENC_NA);
proto_item_append_text(parameter_item, " (%.*s)", interface_id_length,
tvb_get_string(wmem_packet_scope(), parameter_tvb, TEXT_INTERFACE_ID_OFFSET, interface_id_length));
}
static void
dissect_info_string_parameter(tvbuff_t *parameter_tvb, proto_tree *parameter_tree, proto_item *parameter_item)
{
guint16 info_string_length;
info_string_length = tvb_get_ntohs(parameter_tvb, PARAMETER_LENGTH_OFFSET) - PARAMETER_HEADER_LENGTH;
proto_tree_add_item(parameter_tree, hf_info_string, parameter_tvb, INFO_STRING_OFFSET, info_string_length, ENC_ASCII|ENC_NA);
proto_item_append_text(parameter_item, " (%.*s)", info_string_length,
tvb_get_string(wmem_packet_scope(), parameter_tvb, INFO_STRING_OFFSET, info_string_length));
}
static void
dissect_dlci_parameter(tvbuff_t *parameter_tvb, proto_tree *parameter_tree)
{
proto_tree_add_item(parameter_tree, hf_dlci_zero_bit, parameter_tvb, DLCI_SAPI_OFFSET, DLCI_SAPI_LENGTH, ENC_BIG_ENDIAN);
proto_tree_add_item(parameter_tree, hf_dlci_spare_bit, parameter_tvb, DLCI_SAPI_OFFSET, DLCI_SAPI_LENGTH, ENC_BIG_ENDIAN);
if(global_iua_gsm_sapis) {
proto_tree_add_item(parameter_tree, hf_dlci_gsm_sapi, parameter_tvb, DLCI_SAPI_OFFSET, DLCI_SAPI_LENGTH, ENC_BIG_ENDIAN);
} else {
proto_tree_add_item(parameter_tree, hf_dlci_sapi, parameter_tvb, DLCI_SAPI_OFFSET, DLCI_SAPI_LENGTH, ENC_BIG_ENDIAN);
}
sapi_val = (tvb_get_guint8(parameter_tvb, DLCI_SAPI_OFFSET) & SAPI_MASK) >> SAPI_SHIFT;
sapi_val_assigned = TRUE;
proto_tree_add_item(parameter_tree, hf_dlci_one_bit, parameter_tvb, DLCI_TEI_OFFSET, DLCI_TEI_LENGTH, ENC_BIG_ENDIAN);
proto_tree_add_item(parameter_tree, hf_dlci_tei, parameter_tvb, DLCI_TEI_OFFSET, DLCI_TEI_LENGTH, ENC_BIG_ENDIAN);
proto_tree_add_item(parameter_tree, hf_dlci_spare, parameter_tvb, DLCI_SPARE_OFFSET, DLCI_SPARE_LENGTH, ENC_BIG_ENDIAN);
}
static void
dissect_diagnostic_information_parameter(tvbuff_t *parameter_tvb, proto_tree *parameter_tree, proto_item *parameter_item)
{
guint16 diag_info_length;
diag_info_length = tvb_get_ntohs(parameter_tvb, PARAMETER_LENGTH_OFFSET) - PARAMETER_HEADER_LENGTH;
proto_tree_add_item(parameter_tree, hf_diag_info, parameter_tvb, PARAMETER_VALUE_OFFSET, diag_info_length, ENC_NA);
proto_item_append_text(parameter_item, " (%u byte%s)", diag_info_length, plurality(diag_info_length, "", "s"));
}
static void
dissect_integer_range_interface_identifier_parameter(tvbuff_t *parameter_tvb, proto_tree *parameter_tree, proto_item *parameter_item)
{
guint16 number_of_ranges, range_number;
gint offset;
number_of_ranges = (tvb_get_ntohs(parameter_tvb, PARAMETER_LENGTH_OFFSET) - PARAMETER_HEADER_LENGTH) / INTERVAL_LENGTH;
offset = PARAMETER_VALUE_OFFSET;
proto_item_append_text(parameter_item, " (");
for (range_number = 0; range_number < number_of_ranges; range_number++) {
proto_tree_add_item(parameter_tree, hf_interface_range_start, parameter_tvb, offset + START_OFFSET, START_LENGTH, ENC_BIG_ENDIAN);
proto_tree_add_item(parameter_tree, hf_interface_range_end, parameter_tvb, offset + END_OFFSET, END_LENGTH, ENC_BIG_ENDIAN);
proto_item_append_text(parameter_item, (range_number > 0) ? ", %d-%d" : "%d-%d",
tvb_get_ntohl(parameter_tvb, offset + START_OFFSET), tvb_get_ntohl(parameter_tvb, offset + END_OFFSET));
offset += INTERVAL_LENGTH;
}
proto_item_append_text(parameter_item, ")");
}
static void
dissect_heartbeat_data_parameter(tvbuff_t *parameter_tvb, proto_tree *parameter_tree, proto_item *parameter_item)
{
guint16 heartbeat_data_length;
heartbeat_data_length = tvb_get_ntohs(parameter_tvb, PARAMETER_LENGTH_OFFSET) - PARAMETER_HEADER_LENGTH;
proto_tree_add_item(parameter_tree, hf_heartbeat_data, parameter_tvb, HEARTBEAT_DATA_OFFSET, heartbeat_data_length, ENC_NA);
proto_item_append_text(parameter_item, " (%u byte%s)", heartbeat_data_length, plurality(heartbeat_data_length, "", "s"));
}
static void
dissect_asp_reason_parameter(tvbuff_t *parameter_tvb, proto_tree *parameter_tree, proto_item *parameter_item)
{
proto_tree_add_item(parameter_tree, hf_asp_reason, parameter_tvb, ASP_REASON_OFFSET, ASP_REASON_LENGTH, ENC_BIG_ENDIAN);
proto_item_append_text(parameter_item, " (%s)", val_to_str_const(tvb_get_ntohl(parameter_tvb, ASP_REASON_OFFSET), asp_reason_values, "unknown"));
}
static void
dissect_traffic_mode_type_parameter(tvbuff_t *parameter_tvb, proto_tree *parameter_tree, proto_item *parameter_item)
{
proto_tree_add_item(parameter_tree, hf_traffic_mode_type, parameter_tvb, TRAFFIC_MODE_TYPE_OFFSET, TRAFFIC_MODE_TYPE_LENGTH, ENC_BIG_ENDIAN);
proto_item_append_text(parameter_item, " (%s)",
val_to_str_const(tvb_get_ntohl(parameter_tvb, TRAFFIC_MODE_TYPE_OFFSET), traffic_mode_type_values, "unknown"));
}
static void
dissect_error_code_parameter(tvbuff_t *parameter_tvb, proto_tree *parameter_tree, proto_item *parameter_item)
{
proto_tree_add_item(parameter_tree, support_IG?hf_error_code_ig:hf_error_code, parameter_tvb, ERROR_CODE_OFFSET, ERROR_CODE_LENGTH, ENC_BIG_ENDIAN);
proto_item_append_text(parameter_item, " (%s)",
val_to_str_const(tvb_get_ntohl(parameter_tvb, ERROR_CODE_OFFSET), support_IG?error_code_ig_values:error_code_values, "unknown"));
}
static void
dissect_status_type_identification_parameter(tvbuff_t *parameter_tvb, proto_tree *parameter_tree, proto_item *parameter_item)
{
guint16 status_type, status_id;
status_type = tvb_get_ntohs(parameter_tvb, STATUS_TYPE_OFFSET);
status_id = tvb_get_ntohs(parameter_tvb, STATUS_IDENT_OFFSET);
proto_tree_add_item(parameter_tree, hf_status_type, parameter_tvb, STATUS_TYPE_OFFSET, STATUS_TYPE_LENGTH, ENC_BIG_ENDIAN);
proto_tree_add_uint_format_value(parameter_tree, hf_status_id, parameter_tvb, STATUS_IDENT_OFFSET, STATUS_IDENT_LENGTH,
status_id, "%u (%s)", status_id,
val_to_str_const(status_type * 256 * 256 + status_id, support_IG?status_type_id_ig_values:status_type_id_values, "unknown"));
proto_item_append_text(parameter_item, " (%s)",
val_to_str_const(status_type * 256 * 256 + status_id, support_IG?status_type_id_ig_values:status_type_id_values, "unknown status information"));
}
static void
dissect_protocol_data_parameter(tvbuff_t *parameter_tvb, proto_item *parameter_item, packet_info *pinfo, proto_tree *tree)
{
guint16 protocol_data_length;
tvbuff_t *protocol_data_tvb;
protocol_data_length = tvb_get_ntohs(parameter_tvb, PARAMETER_LENGTH_OFFSET) - PARAMETER_HEADER_LENGTH;
protocol_data_tvb = tvb_new_subset(parameter_tvb, PROTOCOL_DATA_OFFSET, protocol_data_length, protocol_data_length);
proto_item_append_text(parameter_item, " (%u byte%s)", protocol_data_length, plurality(protocol_data_length, "", "s"));
if(sapi_val_assigned == FALSE)
{
return;
}
if(global_iua_gsm_sapis) {
if (!dissector_try_uint(lapd_gsm_sapi_dissector_table, sapi_val, protocol_data_tvb, pinfo, tree))
call_dissector(data_handle, protocol_data_tvb, pinfo, tree);
return;
}
switch(sapi_val)
{
case SAPI_VAL_CALL_CONTROL:
case SAPI_VAL_Q931_PACKET:
call_dissector(q931_handle, protocol_data_tvb, pinfo, tree);
break;
case SAPI_VAL_X25:
call_dissector(x25_handle, protocol_data_tvb, pinfo, tree);
break;
default:
break;
}
}
static void
dissect_release_reason_parameter(tvbuff_t *parameter_tvb, proto_tree *parameter_tree, proto_item *parameter_item)
{
proto_tree_add_item(parameter_tree, hf_release_reason, parameter_tvb, RELEASE_REASON_OFFSET, RELEASE_REASON_LENGTH, ENC_BIG_ENDIAN);
proto_item_append_text(parameter_item, " (%s)",
val_to_str_const(tvb_get_ntohl(parameter_tvb, RELEASE_REASON_OFFSET), release_reason_values, "unknown"));
}
static void
dissect_tei_status_parameter(tvbuff_t *parameter_tvb, proto_tree *parameter_tree, proto_item *parameter_item)
{
proto_tree_add_item(parameter_tree, hf_tei_status, parameter_tvb, TEI_STATUS_OFFSET, TEI_STATUS_LENGTH, ENC_BIG_ENDIAN);
proto_item_append_text(parameter_item, " (%s)",
val_to_str_const(tvb_get_ntohl(parameter_tvb, TEI_STATUS_OFFSET), tei_status_values, "unknown"));
}
static void
dissect_asp_identifier_parameter(tvbuff_t *parameter_tvb, proto_tree *parameter_tree, proto_item *parameter_item)
{
proto_tree_add_item(parameter_tree, hf_asp_id, parameter_tvb, ASP_ID_OFFSET, ASP_ID_LENGTH, ENC_BIG_ENDIAN);
proto_item_append_text(parameter_item, " (%u)", tvb_get_ntohl(parameter_tvb, ASP_ID_OFFSET));
}
static void
dissect_unknown_parameter(tvbuff_t *parameter_tvb, proto_tree *parameter_tree, proto_item *parameter_item)
{
guint16 parameter_value_length;
parameter_value_length = tvb_get_ntohs(parameter_tvb, PARAMETER_LENGTH_OFFSET) - PARAMETER_HEADER_LENGTH;
if (parameter_value_length > 0)
proto_tree_add_item(parameter_tree, hf_parameter_value, parameter_tvb, PARAMETER_VALUE_OFFSET, parameter_value_length, ENC_NA);
proto_item_append_text(parameter_item, " with tag %u and %u byte%s value",
tvb_get_ntohs(parameter_tvb, PARAMETER_TAG_OFFSET), parameter_value_length, plurality(parameter_value_length, "", "s"));
}
static void
dissect_parameter(tvbuff_t *parameter_tvb, packet_info *pinfo, proto_tree *tree, proto_tree *iua_tree)
{
guint16 tag, length, padding_length;
proto_item *parameter_item;
proto_tree *parameter_tree;
tag = tvb_get_ntohs(parameter_tvb, PARAMETER_TAG_OFFSET);
length = tvb_get_ntohs(parameter_tvb, PARAMETER_LENGTH_OFFSET);
padding_length = tvb_length(parameter_tvb) - length;
parameter_item = proto_tree_add_text(iua_tree, parameter_tvb, PARAMETER_HEADER_OFFSET, tvb_length(parameter_tvb),
"%s parameter", val_to_str_const(tag, support_IG?parameter_tag_ig_values:parameter_tag_values, "Unknown"));
parameter_tree = proto_item_add_subtree(parameter_item, ett_iua_parameter);
proto_tree_add_item(parameter_tree, support_IG?hf_parameter_tag_ig:hf_parameter_tag, parameter_tvb, PARAMETER_TAG_OFFSET, PARAMETER_TAG_LENGTH, ENC_BIG_ENDIAN);
proto_tree_add_item(parameter_tree, hf_parameter_length, parameter_tvb, PARAMETER_LENGTH_OFFSET, PARAMETER_LENGTH_LENGTH, ENC_BIG_ENDIAN);
switch(tag) {
case INT_INTERFACE_IDENTIFIER_PARAMETER_TAG:
dissect_int_interface_identifier_parameter(parameter_tvb, parameter_tree, parameter_item);
break;
case TEXT_INTERFACE_IDENTIFIER_PARAMETER_TAG:
dissect_text_interface_identifier_parameter(parameter_tvb, parameter_tree, parameter_item);
break;
case INFO_PARAMETER_TAG:
dissect_info_string_parameter(parameter_tvb, parameter_tree, parameter_item);
break;
case DLCI_PARAMETER_TAG:
dissect_dlci_parameter(parameter_tvb, parameter_tree);
break;
case DIAGNOSTIC_INFORMATION_PARAMETER_TAG:
dissect_diagnostic_information_parameter(parameter_tvb, parameter_tree, parameter_item);
break;
case INTEGER_RANGE_INTERFACE_IDENTIFIER_PARAMETER_TAG:
dissect_integer_range_interface_identifier_parameter(parameter_tvb, parameter_tree, parameter_item);
break;
case HEARTBEAT_DATA_PARAMETER_TAG:
dissect_heartbeat_data_parameter(parameter_tvb, parameter_tree, parameter_item);
break;
case ASP_REASON_PARAMETER_TAG:
if (support_IG)
dissect_unknown_parameter(parameter_tvb, parameter_tree, parameter_item);
else
dissect_asp_reason_parameter(parameter_tvb, parameter_tree, parameter_item);
break;
case TRAFFIC_MODE_TYPE_PARAMETER_TAG:
dissect_traffic_mode_type_parameter(parameter_tvb, parameter_tree, parameter_item);
break;
case ERROR_CODE_PARAMETER_TAG:
dissect_error_code_parameter(parameter_tvb, parameter_tree, parameter_item);
break;
case STATUS_TYPE_INDENTIFICATION_PARAMETER_TAG:
dissect_status_type_identification_parameter(parameter_tvb, parameter_tree, parameter_item);
break;
case PROTOCOL_DATA_PARAMETER_TAG:
dissect_protocol_data_parameter(parameter_tvb, parameter_item, pinfo, tree);
break;
case RELEASE_REASON_PARAMETER_TAG:
dissect_release_reason_parameter(parameter_tvb, parameter_tree, parameter_item);
break;
case TEI_STATUS_PARAMETER_TAG:
dissect_tei_status_parameter(parameter_tvb, parameter_tree, parameter_item);
break;
case ASP_IDENTIFIER_PARAMETER_TAG:
if (support_IG)
dissect_asp_identifier_parameter(parameter_tvb, parameter_tree, parameter_item);
else
dissect_unknown_parameter(parameter_tvb, parameter_tree, parameter_item);
break;
default:
dissect_unknown_parameter(parameter_tvb, parameter_tree, parameter_item);
break;
};
if (padding_length > 0)
proto_tree_add_item(parameter_tree, hf_parameter_padding, parameter_tvb, PARAMETER_HEADER_OFFSET + length, padding_length, ENC_NA);
}
static void
dissect_parameters(tvbuff_t *parameters_tvb, packet_info *pinfo, proto_tree *tree, proto_tree *iua_tree)
{
gint offset, length, total_length, remaining_length;
tvbuff_t *parameter_tvb;
offset = 0;
while((remaining_length = tvb_length_remaining(parameters_tvb, offset))) {
length = tvb_get_ntohs(parameters_tvb, offset + PARAMETER_LENGTH_OFFSET);
total_length = ADD_PADDING(length);
if (remaining_length >= length)
total_length = MIN(total_length, remaining_length);
parameter_tvb = tvb_new_subset(parameters_tvb, offset, total_length, total_length);
dissect_parameter(parameter_tvb, pinfo, tree, iua_tree);
offset += total_length;
}
}
static void
dissect_common_header(tvbuff_t *common_header_tvb, packet_info *pinfo, proto_tree *iua_tree)
{
guint8 message_class, message_type;
message_class = tvb_get_guint8(common_header_tvb, MESSAGE_CLASS_OFFSET);
message_type = tvb_get_guint8(common_header_tvb, MESSAGE_TYPE_OFFSET);
col_add_fstr(pinfo->cinfo, COL_INFO, "%s ", val_to_str_const(message_class * 256 + message_type, support_IG?message_class_type_acro_ig_values:message_class_type_acro_values, "UNKNOWN"));
if (iua_tree) {
proto_tree_add_item(iua_tree, hf_version, common_header_tvb, VERSION_OFFSET, VERSION_LENGTH, ENC_BIG_ENDIAN);
proto_tree_add_item(iua_tree, hf_reserved, common_header_tvb, RESERVED_OFFSET, RESERVED_LENGTH, ENC_BIG_ENDIAN);
proto_tree_add_item(iua_tree, hf_message_class, common_header_tvb, MESSAGE_CLASS_OFFSET, MESSAGE_CLASS_LENGTH, ENC_BIG_ENDIAN);
proto_tree_add_uint_format_value(iua_tree, hf_message_type,
common_header_tvb, MESSAGE_TYPE_OFFSET, MESSAGE_TYPE_LENGTH,
message_type, "%u (%s)",
message_type, val_to_str_const(message_class * 256 + message_type, support_IG?message_class_type_ig_values:message_class_type_values, "reserved"));
proto_tree_add_item(iua_tree, hf_message_length, common_header_tvb, MESSAGE_LENGTH_OFFSET, MESSAGE_LENGTH_LENGTH, ENC_BIG_ENDIAN);
}
}
static void
dissect_iua_message(tvbuff_t *message_tvb, packet_info *pinfo, proto_tree *tree, proto_tree *iua_tree)
{
tvbuff_t *common_header_tvb, *parameters_tvb;
sapi_val_assigned = FALSE;
common_header_tvb = tvb_new_subset(message_tvb, COMMON_HEADER_OFFSET, COMMON_HEADER_LENGTH, COMMON_HEADER_LENGTH);
parameters_tvb = tvb_new_subset_remaining(message_tvb, PARAMETERS_OFFSET);
dissect_common_header(common_header_tvb, pinfo, iua_tree);
dissect_parameters(parameters_tvb, pinfo, tree, iua_tree);
}
static void
dissect_iua(tvbuff_t *message_tvb, packet_info *pinfo, proto_tree *tree)
{
proto_item *iua_item;
proto_tree *iua_tree;
col_set_str(pinfo->cinfo, COL_PROTOCOL, support_IG?"IUA (RFC 3057 + IG)":"IUA (RFC 3057)");
if (tree) {
iua_item = proto_tree_add_item(tree, proto_iua, message_tvb, 0, -1, ENC_NA);
iua_tree = proto_item_add_subtree(iua_item, ett_iua);
} else {
iua_tree = NULL;
};
dissect_iua_message(message_tvb, pinfo, tree, iua_tree);
}
void
proto_register_iua(void)
{
static hf_register_info hf[] = {
{ &hf_int_interface_id, { "Integer interface identifier", "iua.int_interface_identifier", FT_UINT32, BASE_HEX, NULL, 0x0, NULL, HFILL } },
{ &hf_text_interface_id, { "Text interface identifier", "iua.text_interface_identifier", FT_STRING, BASE_NONE, NULL, 0x0, NULL, HFILL } },
{ &hf_info_string, { "Info string", "iua.info_string", FT_STRING, BASE_NONE, NULL, 0x0, NULL, HFILL } },
{ &hf_dlci_zero_bit, { "Zero bit", "iua.dlci_zero_bit", FT_BOOLEAN, 8, NULL, ZERO_BIT_MASK, NULL, HFILL } },
{ &hf_dlci_spare_bit, { "Spare bit", "iua.dlci_spare_bit", FT_BOOLEAN, 8, NULL, SPARE_BIT_MASK, NULL, HFILL } },
{ &hf_dlci_sapi, { "SAPI", "iua.dlci_sapi", FT_UINT8, BASE_HEX, VALS(sapi_values), SAPI_MASK, NULL, HFILL } },
{ &hf_dlci_gsm_sapi, { "SAPI", "iua.dlci_gsm_sapi", FT_UINT8, BASE_HEX, VALS(gsm_sapi_vals), SAPI_MASK, NULL, HFILL } },
{ &hf_dlci_one_bit, { "One bit", "iua.dlci_one_bit", FT_BOOLEAN, 8, NULL, ONE_BIT_MASK, NULL, HFILL } },
{ &hf_dlci_tei, { "TEI", "iua.dlci_tei", FT_UINT8, BASE_HEX, NULL, TEI_MASK, NULL, HFILL } },
{ &hf_dlci_spare, { "Spare", "iua.dlci_spare", FT_UINT16, BASE_HEX, NULL, 0x0, NULL, HFILL } },
{ &hf_diag_info, { "Diagnostic information", "iua.diagnostic_information", FT_BYTES, BASE_NONE, NULL, 0x0, NULL, HFILL } },
{ &hf_interface_range_start, { "Start", "iua.interface_range_start", FT_UINT32, BASE_DEC, NULL, 0x0, NULL, HFILL } },
{ &hf_interface_range_end, { "End", "iua.interface_range_end", FT_UINT32, BASE_DEC, NULL, 0x0, NULL, HFILL } },
{ &hf_heartbeat_data, { "Heartbeat data", "iua.heartbeat_data", FT_BYTES, BASE_NONE, NULL, 0x0, NULL, HFILL } },
{ &hf_asp_reason, { "Reason", "iua.asp_reason", FT_UINT32, BASE_HEX, VALS(asp_reason_values), 0x0, NULL, HFILL } },
{ &hf_traffic_mode_type, { "Traffic mode type", "iua.traffic_mode_type", FT_UINT32, BASE_HEX, VALS(traffic_mode_type_values), 0x0, NULL, HFILL } },
{ &hf_error_code, { "Error code", "iua.error_code", FT_UINT32, BASE_DEC, VALS(error_code_values), 0x0, NULL, HFILL } },
{ &hf_error_code_ig, { "Error code", "iua.error_code", FT_UINT32, BASE_DEC, VALS(error_code_ig_values), 0x0, NULL, HFILL } },
{ &hf_status_type, { "Status type", "iua.status_type", FT_UINT16, BASE_DEC, VALS(status_type_values), 0x0, NULL, HFILL } },
{ &hf_status_id, { "Status identification", "iua.status_identification", FT_UINT16, BASE_DEC, NULL, 0x0, NULL, HFILL } },
{ &hf_release_reason, { "Reason", "iua.release_reason", FT_UINT32, BASE_HEX, VALS(release_reason_values), 0x0, NULL, HFILL } },
{ &hf_tei_status, { "TEI status", "iua.tei_status", FT_UINT32, BASE_HEX, VALS(tei_status_values), 0x0, NULL, HFILL } },
{ &hf_asp_id, { "ASP identifier", "iua.asp_identifier", FT_UINT32, BASE_HEX, NULL, 0x0, NULL, HFILL } },
{ &hf_parameter_tag, { "Parameter Tag", "iua.parameter_tag", FT_UINT16, BASE_DEC, VALS(parameter_tag_values), 0x0, NULL, HFILL } },
{ &hf_parameter_tag_ig, { "Parameter Tag", "iua.parameter_tag", FT_UINT16, BASE_DEC, VALS(parameter_tag_ig_values), 0x0, NULL, HFILL } },
{ &hf_parameter_length, { "Parameter length", "iua.parameter_length", FT_UINT16, BASE_DEC, NULL, 0x0, NULL, HFILL } },
{ &hf_parameter_value, { "Parameter value", "iua.parameter_value", FT_BYTES, BASE_NONE, NULL, 0x0, NULL, HFILL } },
{ &hf_parameter_padding, { "Parameter padding", "iua.parameter_padding", FT_BYTES, BASE_NONE, NULL, 0x0, NULL, HFILL } },
{ &hf_version, { "Version", "iua.version", FT_UINT8, BASE_DEC, VALS(protocol_version_values), 0x0, NULL, HFILL } },
{ &hf_reserved, { "Reserved", "iua.reserved", FT_UINT8, BASE_HEX, NULL, 0x0, NULL, HFILL } },
{ &hf_message_class, { "Message class", "iua.message_class", FT_UINT8, BASE_DEC, VALS(message_class_values), 0x0, NULL, HFILL } },
{ &hf_message_type, { "Message Type", "iua.message_type", FT_UINT8, BASE_DEC, NULL, 0x0, NULL, HFILL } },
{ &hf_message_length, { "Message length", "iua.message_length", FT_UINT32, BASE_DEC, NULL, 0x0, NULL, HFILL } },
};
static gint *ett[] = {
&ett_iua,
&ett_iua_parameter,
};
proto_iua = proto_register_protocol("ISDN Q.921-User Adaptation Layer", "IUA", "iua");
iua_module = prefs_register_protocol(proto_iua, NULL);
proto_register_field_array(proto_iua, hf, array_length(hf));
proto_register_subtree_array(ett, array_length(ett));
prefs_register_bool_preference(iua_module, "support_ig", "Support Implementers Guide", "Support Implementers Guide (version 01)", &support_IG);
prefs_register_bool_preference(iua_module, "use_gsm_sapi_values",
"Use GSM SAPI values",
"Use SAPI values as specified in TS 48 056",
&global_iua_gsm_sapis);
register_dissector("iua", dissect_iua, proto_iua);
}
void
proto_reg_handoff_iua(void)
{
dissector_handle_t iua_handle;
iua_handle = find_dissector("iua");
q931_handle = find_dissector("q931");
x25_handle = find_dissector("x.25");
dissector_add_uint("sctp.port", SCTP_PORT_IUA, iua_handle);
dissector_add_uint("sctp.ppi", IUA_PAYLOAD_PROTOCOL_ID, iua_handle);
lapd_gsm_sapi_dissector_table = find_dissector_table("lapd.gsm.sapi");
data_handle = find_dissector("data");
}
