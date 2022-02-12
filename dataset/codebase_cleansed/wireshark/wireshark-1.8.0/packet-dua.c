static void
dissect_int_interface_identifier_parameter(tvbuff_t *parameter_tvb, proto_tree *parameter_tree, proto_item *parameter_item)
{
proto_tree_add_item(parameter_tree, hf_int_interface_id,
parameter_tvb, INT_INTERFACE_ID_OFFSET, INT_INTERFACE_ID_LENGTH, ENC_BIG_ENDIAN);
proto_item_append_text(parameter_item, " (%d)", tvb_get_ntohl(parameter_tvb, INT_INTERFACE_ID_OFFSET));
}
static void
dissect_text_interface_identifier_parameter(tvbuff_t *parameter_tvb, proto_tree *parameter_tree, proto_item *parameter_item)
{
guint16 interface_id_length;
interface_id_length = tvb_get_ntohs(parameter_tvb, PARAMETER_LENGTH_OFFSET) - PARAMETER_HEADER_LENGTH;
proto_tree_add_item(parameter_tree, hf_text_interface_id,
parameter_tvb, TEXT_INTERFACE_ID_OFFSET, interface_id_length, ENC_ASCII|ENC_NA);
proto_item_append_text(parameter_item, " (%.*s)", interface_id_length,
tvb_get_ephemeral_string(parameter_tvb, TEXT_INTERFACE_ID_OFFSET, interface_id_length));
}
static void
dissect_info_string_parameter(tvbuff_t *parameter_tvb, proto_tree *parameter_tree, proto_item *parameter_item)
{
guint16 info_string_length;
info_string_length = tvb_get_ntohs(parameter_tvb, PARAMETER_LENGTH_OFFSET) - PARAMETER_HEADER_LENGTH;
proto_tree_add_item(parameter_tree, hf_info_string,
parameter_tvb, INFO_STRING_OFFSET, info_string_length, ENC_ASCII|ENC_NA);
proto_item_append_text(parameter_item, " (%.*s)", info_string_length,
tvb_get_ephemeral_string(parameter_tvb, INFO_STRING_OFFSET, info_string_length));
}
static void
dissect_dlci_parameter(tvbuff_t *parameter_tvb, proto_tree *parameter_tree)
{
proto_tree_add_item(parameter_tree, hf_dlci_reserved, parameter_tvb, DLCI_OFFSET, DLCI_LENGTH, ENC_BIG_ENDIAN);
proto_tree_add_item(parameter_tree, hf_dlci_v_bit, parameter_tvb, DLCI_OFFSET, DLCI_LENGTH, ENC_BIG_ENDIAN);
proto_tree_add_item(parameter_tree, hf_dlci_zero_bit, parameter_tvb, DLCI_OFFSET, DLCI_LENGTH, ENC_BIG_ENDIAN);
proto_tree_add_item(parameter_tree, hf_dlci_channel, parameter_tvb, DLCI_OFFSET, DLCI_LENGTH, ENC_BIG_ENDIAN);
proto_tree_add_item(parameter_tree, hf_dlci_one_bit, parameter_tvb, DLCI_OFFSET, DLCI_LENGTH, ENC_BIG_ENDIAN);
proto_tree_add_item(parameter_tree, hf_dlci_spare, parameter_tvb, SPARE_OFFSET, SPARE_LENGTH, ENC_BIG_ENDIAN);
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
for(range_number = 1; range_number <= number_of_ranges; range_number++) {
proto_tree_add_item(parameter_tree, hf_interface_range_start,
parameter_tvb, offset + START_OFFSET, START_LENGTH, ENC_BIG_ENDIAN);
proto_tree_add_item(parameter_tree, hf_interface_range_end,
parameter_tvb, offset + END_OFFSET, END_LENGTH, ENC_BIG_ENDIAN);
offset += INTERVAL_LENGTH;
};
proto_item_append_text(parameter_item, " (%u range%s)", number_of_ranges, plurality(number_of_ranges, "", "s"));
}
static void
dissect_heartbeat_data_parameter(tvbuff_t *parameter_tvb, proto_tree *parameter_tree, proto_item *parameter_item)
{
guint16 heartbeat_data_length;
heartbeat_data_length = tvb_get_ntohs(parameter_tvb, PARAMETER_LENGTH_OFFSET) - PARAMETER_HEADER_LENGTH;
proto_tree_add_item(parameter_tree, hf_heartbeat_data,
parameter_tvb, HEARTBEAT_DATA_OFFSET, heartbeat_data_length, ENC_NA);
proto_item_append_text(parameter_item, " (%u byte%s)", heartbeat_data_length, plurality(heartbeat_data_length, "", "s"));
}
static void
dissect_traffic_mode_type_parameter(tvbuff_t *parameter_tvb, proto_tree *parameter_tree, proto_item *parameter_item)
{
proto_tree_add_item(parameter_tree, hf_traffic_mode_type,
parameter_tvb, TRAFFIC_MODE_TYPE_OFFSET, TRAFFIC_MODE_TYPE_LENGTH, ENC_BIG_ENDIAN);
proto_item_append_text(parameter_item, " (%s)",
val_to_str_const(tvb_get_ntohl(parameter_tvb, TRAFFIC_MODE_TYPE_OFFSET),
traffic_mode_type_values, "unknown"));
}
static void
dissect_error_code_parameter(tvbuff_t *parameter_tvb, proto_tree *parameter_tree, proto_item *parameter_item)
{
proto_tree_add_item(parameter_tree, hf_error_code,
parameter_tvb, ERROR_CODE_OFFSET, ERROR_CODE_LENGTH, ENC_BIG_ENDIAN);
proto_item_append_text(parameter_item, " (%s)",
val_to_str_const(tvb_get_ntohl(parameter_tvb, ERROR_CODE_OFFSET),
error_code_values,
"unknown"));
}
static void
dissect_status_type_identification_parameter(tvbuff_t *parameter_tvb, proto_tree *parameter_tree, proto_item *parameter_item)
{
guint16 status_type, status_id;
status_type = tvb_get_ntohs(parameter_tvb, STATUS_TYPE_OFFSET);
status_id = tvb_get_ntohs(parameter_tvb, STATUS_IDENT_OFFSET);
proto_tree_add_item(parameter_tree, hf_status_type,
parameter_tvb, STATUS_TYPE_OFFSET, STATUS_TYPE_LENGTH, ENC_BIG_ENDIAN);
proto_tree_add_uint_format(parameter_tree, hf_status_id, parameter_tvb, STATUS_IDENT_OFFSET, STATUS_IDENT_LENGTH,
status_id, "Status identification: %u (%s)", status_id,
val_to_str_const(status_type * 256 * 256 + status_id, status_type_id_values, "unknown"));
proto_item_append_text(parameter_item, " (%s)",
val_to_str_const(status_type * 256 * 256 + status_id,
status_type_id_values,
"unknown status information"));
}
static void
dissect_protocol_data_parameter(tvbuff_t *parameter_tvb, proto_item *parameter_item, packet_info *pinfo, proto_tree *tree)
{
guint16 protocol_data_length;
tvbuff_t *protocol_data_tvb;
protocol_data_length = tvb_get_ntohs(parameter_tvb, PARAMETER_LENGTH_OFFSET) - PARAMETER_HEADER_LENGTH;
protocol_data_tvb = tvb_new_subset(parameter_tvb, PROTOCOL_DATA_OFFSET, protocol_data_length, protocol_data_length);
if(dpnss_handle){
call_dissector(dpnss_handle, protocol_data_tvb, pinfo, tree);
return;
}
call_dissector(data_handle, protocol_data_tvb, pinfo, tree);
proto_item_append_text(parameter_item, " (%u byte%s)", protocol_data_length, plurality(protocol_data_length, "", "s"));
}
static void
dissect_release_reason_parameter(tvbuff_t *parameter_tvb, proto_tree *parameter_tree, proto_item *parameter_item)
{
proto_tree_add_item(parameter_tree, hf_release_reason,
parameter_tvb, RELEASE_REASON_OFFSET, RELEASE_REASON_LENGTH, ENC_BIG_ENDIAN);
proto_item_append_text(parameter_item, " (%s)",
val_to_str_const(tvb_get_ntohl(parameter_tvb, RELEASE_REASON_OFFSET),
release_reason_values,
"unknown"));
}
static void
dissect_tei_status_parameter(tvbuff_t *parameter_tvb, proto_tree *parameter_tree, proto_item *parameter_item)
{
proto_tree_add_item(parameter_tree, hf_tei_status,
parameter_tvb, TEI_STATUS_OFFSET, TEI_STATUS_LENGTH, ENC_BIG_ENDIAN);
proto_item_append_text(parameter_item, " (%s)",
val_to_str_const(tvb_get_ntohl(parameter_tvb, TEI_STATUS_OFFSET),
tei_status_values,
"unknown"));
}
static void
dissect_asp_identifier_parameter(tvbuff_t *parameter_tvb, proto_tree *parameter_tree, proto_item *parameter_item)
{
proto_tree_add_item(parameter_tree, hf_asp_id, parameter_tvb, ASP_ID_OFFSET, ASP_ID_LENGTH, ENC_BIG_ENDIAN);
proto_item_append_text(parameter_item, " (%u)", tvb_get_ntohl(parameter_tvb, ASP_ID_OFFSET));
}
static void
dissect_dlc_status_parameter(tvbuff_t *parameter_tvb, proto_tree *parameter_tree, proto_item *parameter_item _U_)
{
guint16 parameter_value_length;
parameter_value_length = tvb_get_ntohs(parameter_tvb, PARAMETER_LENGTH_OFFSET) - PARAMETER_HEADER_LENGTH;
if (parameter_value_length > 0)
proto_tree_add_item(parameter_tree,
hf_states, parameter_tvb, PARAMETER_VALUE_OFFSET, parameter_value_length, ENC_NA);
}
static void
dissect_unknown_parameter(tvbuff_t *parameter_tvb, proto_tree *parameter_tree, proto_item *parameter_item)
{
guint16 parameter_value_length;
parameter_value_length = tvb_get_ntohs(parameter_tvb, PARAMETER_LENGTH_OFFSET) - PARAMETER_HEADER_LENGTH;
if (parameter_value_length > 0)
proto_tree_add_item(parameter_tree, hf_parameter_value,
parameter_tvb, PARAMETER_VALUE_OFFSET, parameter_value_length, ENC_NA);
proto_item_append_text(parameter_item, " with tag %u and %u byte%s value",
tvb_get_ntohs(parameter_tvb, PARAMETER_TAG_OFFSET),
parameter_value_length, plurality(parameter_value_length, "", "s"));
}
static void
dissect_parameter(tvbuff_t *parameter_tvb, packet_info *pinfo, proto_tree *tree, proto_tree *dua_tree)
{
guint16 tag, length, padding_length;
proto_item *parameter_item;
proto_tree *parameter_tree;
tag = tvb_get_ntohs(parameter_tvb, PARAMETER_TAG_OFFSET);
length = tvb_get_ntohs(parameter_tvb, PARAMETER_LENGTH_OFFSET);
padding_length = tvb_length(parameter_tvb) - length;
parameter_item = proto_tree_add_text(dua_tree, parameter_tvb, PARAMETER_HEADER_OFFSET,
tvb_length(parameter_tvb), "%s",
val_to_str_const(tag, parameter_tag_values, "Unknown parameter"));
parameter_tree = proto_item_add_subtree(parameter_item, ett_dua_parameter);
proto_tree_add_item(parameter_tree, hf_parameter_tag,
parameter_tvb, PARAMETER_TAG_OFFSET, PARAMETER_TAG_LENGTH, ENC_BIG_ENDIAN);
proto_tree_add_item(parameter_tree, hf_parameter_length,
parameter_tvb, PARAMETER_LENGTH_OFFSET, PARAMETER_LENGTH_LENGTH, ENC_BIG_ENDIAN);
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
dissect_asp_identifier_parameter(parameter_tvb, parameter_tree, parameter_item);
break;
case DLC_STATUS_PARAMETER_TAG:
dissect_dlc_status_parameter(parameter_tvb, parameter_tree, parameter_item);
break;
default:
dissect_unknown_parameter(parameter_tvb, parameter_tree, parameter_item);
break;
};
if (padding_length > 0)
proto_tree_add_item(parameter_tree, hf_parameter_padding,
parameter_tvb, PARAMETER_HEADER_OFFSET + length, padding_length, ENC_NA);
}
static void
dissect_parameters(tvbuff_t *parameters_tvb, packet_info *pinfo, proto_tree *tree, proto_tree *dua_tree)
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
dissect_parameter(parameter_tvb, pinfo, tree, dua_tree);
offset += total_length;
}
}
static void
dissect_common_header(tvbuff_t *common_header_tvb, packet_info *pinfo, proto_tree *dua_tree)
{
guint8 message_class, message_type;
message_class = tvb_get_guint8(common_header_tvb, MESSAGE_CLASS_OFFSET);
message_type = tvb_get_guint8(common_header_tvb, MESSAGE_TYPE_OFFSET);
if (check_col(pinfo->cinfo, COL_INFO))
col_add_fstr(pinfo->cinfo, COL_INFO, "%s ", val_to_str_const(message_class * 256 + message_type,
message_class_type_acro_values,
"Unknown"));
if (dua_tree) {
proto_tree_add_item(dua_tree, hf_version, common_header_tvb, VERSION_OFFSET, VERSION_LENGTH, ENC_BIG_ENDIAN);
proto_tree_add_item(dua_tree, hf_reserved, common_header_tvb, RESERVED_OFFSET, RESERVED_LENGTH, ENC_BIG_ENDIAN);
proto_tree_add_item(dua_tree, hf_message_class,
common_header_tvb, MESSAGE_CLASS_OFFSET, MESSAGE_CLASS_LENGTH, ENC_BIG_ENDIAN);
proto_tree_add_uint_format(dua_tree, hf_message_type,
common_header_tvb, MESSAGE_TYPE_OFFSET, MESSAGE_TYPE_LENGTH,
message_type, "Message type: %u (%s)",
message_type, val_to_str_const(message_class * 256 + message_type,
message_class_type_values,
"reserved"));
proto_tree_add_item(dua_tree, hf_message_length,
common_header_tvb, MESSAGE_LENGTH_OFFSET, MESSAGE_LENGTH_LENGTH, ENC_BIG_ENDIAN);
}
}
static void
dissect_dua_message(tvbuff_t *message_tvb, packet_info *pinfo, proto_tree *tree, proto_tree *dua_tree)
{
tvbuff_t *common_header_tvb, *parameters_tvb;
common_header_tvb = tvb_new_subset(message_tvb, COMMON_HEADER_OFFSET, COMMON_HEADER_LENGTH, COMMON_HEADER_LENGTH);
parameters_tvb = tvb_new_subset_remaining(message_tvb, PARAMETERS_OFFSET);
dissect_common_header(common_header_tvb, pinfo, dua_tree);
dissect_parameters(parameters_tvb, pinfo, tree, dua_tree);
}
static void
dissect_dua(tvbuff_t *message_tvb, packet_info *pinfo, proto_tree *tree)
{
proto_item *dua_item;
proto_tree *dua_tree;
col_set_str(pinfo->cinfo, COL_PROTOCOL, "DUA");
if (tree) {
dua_item = proto_tree_add_item(tree, proto_dua, message_tvb, 0, -1, ENC_NA);
dua_tree = proto_item_add_subtree(dua_item, ett_dua);
} else {
dua_tree = NULL;
};
dissect_dua_message(message_tvb, pinfo, tree, dua_tree);
}
void
proto_register_dua(void)
{
static hf_register_info hf[] = {
{ &hf_int_interface_id,
{ "Integer interface identifier", "dua.int_interface_identifier",
FT_UINT32, BASE_HEX, NULL, 0x0,
NULL, HFILL } },
{ &hf_text_interface_id,
{ "Text interface identifier", "dua.text_interface_identifier",
FT_STRING, BASE_NONE, NULL, 0x0,
NULL, HFILL } },
{ &hf_info_string,
{ "Info string", "dua.info_string",
FT_STRING, BASE_NONE, NULL, 0x0,
NULL, HFILL } },
{ &hf_dlci_reserved,
{ "Reserved", "dua.dlci_reserved",
FT_UINT16, BASE_DEC, NULL, RESERVED_BIT_MASK,
NULL, HFILL } },
{ &hf_dlci_v_bit,
{ "V-bit", "dua.dlci_v_bit",
FT_BOOLEAN, 16, NULL, V_BIT_MASK,
NULL, HFILL } },
{ &hf_dlci_zero_bit,
{ "Zero bit", "dua.dlci_zero_bit",
FT_BOOLEAN, 16, NULL, ZERO_BIT_MASK,
NULL, HFILL } },
{ &hf_dlci_channel,
{ "Channel", "dua.dlci_channel",
FT_UINT16, BASE_DEC, NULL, CHANNEL_BIT_MASK,
NULL, HFILL } },
{ &hf_dlci_one_bit,
{ "One bit", "dua.dlci_one_bit",
FT_BOOLEAN, 16, NULL, ONE_BIT_MASK,
NULL, HFILL } },
{ &hf_dlci_spare,
{ "Spare", "dua.dlci_spare",
FT_UINT16, BASE_DEC, NULL, 0x0,
NULL, HFILL } },
{ &hf_diag_info,
{ "Diagnostic information", "dua.diagnostic_information",
FT_BYTES, BASE_NONE, NULL, 0x0,
NULL, HFILL } },
{ &hf_interface_range_start,
{ "Start", "dua.interface_range_start",
FT_UINT32, BASE_DEC, NULL, 0x0,
NULL, HFILL } },
{ &hf_interface_range_end,
{ "End", "dua.interface_range_end",
FT_UINT32, BASE_DEC, NULL, 0x0,
NULL, HFILL } },
{ &hf_heartbeat_data,
{ "Heartbeat data", "dua.heartbeat_data",
FT_BYTES, BASE_NONE, NULL, 0x0,
NULL, HFILL } },
{ &hf_traffic_mode_type,
{ "Traffic mode type", "dua.traffic_mode_type",
FT_UINT32, BASE_HEX, VALS(traffic_mode_type_values), 0x0,
NULL, HFILL } },
{ &hf_error_code,
{ "Error code", "dua.error_code",
FT_UINT32, BASE_DEC, VALS(error_code_values), 0x0,
NULL, HFILL } },
{ &hf_status_type,
{ "Status type", "dua.status_type",
FT_UINT16, BASE_DEC, VALS(status_type_values), 0x0,
NULL, HFILL } },
{ &hf_status_id,
{ "Status identification", "dua.status_identification",
FT_UINT16, BASE_DEC, NULL, 0x0,
NULL, HFILL } },
{ &hf_release_reason,
{ "Reason", "dua.release_reason",
FT_UINT32, BASE_HEX, VALS(release_reason_values), 0x0,
NULL, HFILL } },
{ &hf_tei_status,
{ "TEI status", "dua.tei_status",
FT_UINT32, BASE_HEX, VALS(tei_status_values), 0x0,
NULL, HFILL } },
{ &hf_asp_id,
{ "ASP identifier", "dua.asp_identifier",
FT_UINT32, BASE_HEX, NULL, 0x0,
NULL, HFILL } },
{ &hf_states,
{ "States", "dua.states",
FT_BYTES, BASE_NONE, NULL, 0x0,
NULL, HFILL } },
{ &hf_parameter_tag,
{ "Parameter Tag", "dua.parameter_tag",
FT_UINT16, BASE_DEC, VALS(parameter_tag_values), 0x0,
NULL, HFILL } },
{ &hf_parameter_length,
{ "Parameter length", "dua.parameter_length",
FT_UINT16, BASE_DEC, NULL, 0x0,
NULL, HFILL } },
{ &hf_parameter_value,
{ "Parameter value", "dua.parameter_value",
FT_BYTES, BASE_NONE, NULL, 0x0,
NULL, HFILL } },
{ &hf_parameter_padding,
{ "Parameter padding", "dua.parameter_padding",
FT_BYTES, BASE_NONE, NULL, 0x0,
NULL, HFILL } },
{ &hf_version,
{ "Version", "dua.version",
FT_UINT8, BASE_DEC, VALS(protocol_version_values), 0x0,
NULL, HFILL } },
{ &hf_reserved,
{ "Reserved", "dua.reserved",
FT_UINT8, BASE_HEX, NULL, 0x0,
NULL, HFILL } },
{ &hf_message_class,
{ "Message class", "dua.message_class",
FT_UINT8, BASE_DEC, VALS(message_class_values), 0x0,
NULL, HFILL } },
{ &hf_message_type,
{ "Message Type", "dua.message_type",
FT_UINT8, BASE_DEC, NULL, 0x0,
NULL, HFILL } },
{ &hf_message_length,
{ "Message length", "dua.message_length",
FT_UINT32, BASE_DEC, NULL, 0x0,
NULL, HFILL } },
};
static gint *ett[] = {
&ett_dua,
&ett_dua_parameter,
};
proto_dua = proto_register_protocol("DPNSS/DASS2-User Adaptation Layer", "DUA", "dua");
proto_register_field_array(proto_dua, hf, array_length(hf));
proto_register_subtree_array(ett, array_length(ett));
register_dissector("dua", dissect_dua, proto_dua);
}
void
proto_reg_handoff_dua(void)
{
dissector_handle_t dua_handle;
dua_handle = find_dissector("dua");
data_handle = find_dissector("data");
dpnss_handle = find_dissector("dpnss");
dissector_add_uint("sctp.ppi", DUA_PAYLOAD_PROTOCOL_ID, dua_handle);
}
