static void
dissect_common_header(tvbuff_t *common_header_tvb, packet_info *pinfo, proto_tree *m2ua_tree)
{
guint8 message_class, message_type;
message_class = tvb_get_guint8(common_header_tvb, MESSAGE_CLASS_OFFSET);
message_type = tvb_get_guint8(common_header_tvb, MESSAGE_TYPE_OFFSET);
col_add_fstr(pinfo->cinfo, COL_INFO, "%s ", val_to_str_const(message_class * 256 + message_type, message_class_type_acro_values, "reserved"));
if (m2ua_tree) {
proto_tree_add_item(m2ua_tree, hf_version, common_header_tvb, VERSION_OFFSET, VERSION_LENGTH, ENC_BIG_ENDIAN);
proto_tree_add_item(m2ua_tree, hf_reserved, common_header_tvb, RESERVED_OFFSET, RESERVED_LENGTH, ENC_BIG_ENDIAN);
proto_tree_add_item(m2ua_tree, hf_message_class, common_header_tvb, MESSAGE_CLASS_OFFSET, MESSAGE_CLASS_LENGTH, ENC_BIG_ENDIAN);
proto_tree_add_uint_format_value(m2ua_tree, hf_message_type, common_header_tvb, MESSAGE_TYPE_OFFSET, MESSAGE_TYPE_LENGTH, message_type,
"%s (%u)",
val_to_str_const(message_class * 256 + message_type, message_class_type_values, "reserved"), message_type);
proto_tree_add_item(m2ua_tree, hf_message_length, common_header_tvb, MESSAGE_LENGTH_OFFSET, MESSAGE_LENGTH_LENGTH, ENC_BIG_ENDIAN);
}
}
static void
dissect_interface_identifier_int_parameter(tvbuff_t *parameter_tvb, proto_tree *parameter_tree, proto_item *parameter_item)
{
proto_tree_add_item(parameter_tree, hf_interface_id_int, parameter_tvb, INT_INTERFACE_ID_OFFSET, INT_INTERFACE_ID_LENGTH, ENC_BIG_ENDIAN);
proto_item_append_text(parameter_item, " (%d)", tvb_get_ntohl(parameter_tvb, INT_INTERFACE_ID_OFFSET));
}
static void
dissect_interface_identifier_text_parameter(tvbuff_t *parameter_tvb, proto_tree *parameter_tree, proto_item *parameter_item)
{
guint16 interface_id_length;
interface_id_length = tvb_get_ntohs(parameter_tvb, PARAMETER_LENGTH_OFFSET) - PARAMETER_HEADER_LENGTH;
proto_tree_add_item(parameter_tree, hf_interface_id_text, parameter_tvb, TEXT_INTERFACE_ID_OFFSET, interface_id_length, ENC_ASCII|ENC_NA);
proto_item_append_text(parameter_item, " (%.*s)", interface_id_length,
tvb_format_text(parameter_tvb, TEXT_INTERFACE_ID_OFFSET, interface_id_length));
}
static void
dissect_info_string_parameter(tvbuff_t *parameter_tvb, proto_tree *parameter_tree, proto_item *parameter_item)
{
guint16 info_string_length;
info_string_length = tvb_get_ntohs(parameter_tvb, PARAMETER_LENGTH_OFFSET) - PARAMETER_HEADER_LENGTH;
proto_tree_add_item(parameter_tree, hf_info_string, parameter_tvb, INFO_STRING_OFFSET, info_string_length, ENC_ASCII|ENC_NA);
proto_item_append_text(parameter_item, " (%.*s)", info_string_length,
tvb_format_text(parameter_tvb, INFO_STRING_OFFSET, info_string_length));
}
static void
dissect_diagnostic_information_parameter(tvbuff_t *parameter_tvb, proto_tree *parameter_tree, proto_item *parameter_item)
{
guint16 diag_info_length;
diag_info_length = tvb_get_ntohs(parameter_tvb, PARAMETER_LENGTH_OFFSET) - PARAMETER_HEADER_LENGTH;
proto_tree_add_item(parameter_tree, hf_diagnostic_information, parameter_tvb, DIAGNOSTIC_INFO_OFFSET, diag_info_length, ENC_NA);
proto_item_append_text(parameter_item, " (%u byte%s)", diag_info_length, plurality(diag_info_length, "", "s"));
}
static void
dissect_interface_identifier_range_parameter(tvbuff_t *parameter_tvb, proto_tree *parameter_tree, proto_item *parameter_item)
{
guint16 number_of_ranges, range_number;
gint offset;
number_of_ranges = (tvb_get_ntohs(parameter_tvb, PARAMETER_LENGTH_OFFSET) - PARAMETER_HEADER_LENGTH) / INTERVAL_LENGTH;
offset = PARAMETER_VALUE_OFFSET;
for(range_number = 0; range_number < number_of_ranges; range_number++) {
proto_tree_add_item(parameter_tree, hf_interface_id_start, parameter_tvb, offset + START_OFFSET, START_LENGTH, ENC_BIG_ENDIAN);
proto_tree_add_item(parameter_tree, hf_interface_id_stop, parameter_tvb, offset + END_OFFSET, END_LENGTH, ENC_BIG_ENDIAN);
offset += INTERVAL_LENGTH;
};
proto_item_append_text(parameter_item, " (%u range%s)", number_of_ranges, plurality(number_of_ranges, "", "s"));
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
dissect_traffic_mode_type_parameter(tvbuff_t *parameter_tvb, proto_tree *parameter_tree, proto_item *parameter_item)
{
proto_tree_add_item(parameter_tree, hf_traffic_mode_type, parameter_tvb, TRAFFIC_MODE_TYPE_OFFSET, TRAFFIC_MODE_TYPE_LENGTH, ENC_BIG_ENDIAN);
proto_item_append_text(parameter_item, " (%s)",
val_to_str_const(tvb_get_ntohl(parameter_tvb, TRAFFIC_MODE_TYPE_OFFSET), traffic_mode_type_values, "unknown"));
}
static void
dissect_error_code_parameter(tvbuff_t *parameter_tvb, proto_tree *parameter_tree, proto_item *parameter_item)
{
proto_tree_add_item(parameter_tree, hf_error_code, parameter_tvb, ERROR_CODE_OFFSET, ERROR_CODE_LENGTH, ENC_BIG_ENDIAN);
proto_item_append_text(parameter_item, " (%s)",
val_to_str_const(tvb_get_ntohl(parameter_tvb, ERROR_CODE_OFFSET), error_code_values, "unknown"));
}
static void
dissect_status_parameter(tvbuff_t *parameter_tvb, proto_tree *parameter_tree, proto_item *parameter_item)
{
guint16 status_type, status_id;
status_type = tvb_get_ntohs(parameter_tvb, STATUS_TYPE_OFFSET);
status_id = tvb_get_ntohs(parameter_tvb, STATUS_IDENT_OFFSET);
proto_tree_add_item(parameter_tree, hf_status_type, parameter_tvb, STATUS_TYPE_OFFSET, STATUS_TYPE_LENGTH, ENC_BIG_ENDIAN);
proto_tree_add_uint_format(parameter_tree, hf_status_ident, parameter_tvb, STATUS_IDENT_OFFSET, STATUS_IDENT_LENGTH,
status_id, "Status identification: %u (%s)", status_id,
val_to_str_const(status_type * 256 * 256 + status_id, status_type_id_values, "unknown"));
proto_item_append_text(parameter_item, " (%s)",
val_to_str_const(status_type * 256 * 256 + status_id, status_type_id_values, "unknown status information"));
}
static void
dissect_asp_identifier_parameter(tvbuff_t *parameter_tvb, proto_tree *parameter_tree, proto_item *parameter_item)
{
proto_tree_add_item(parameter_tree, hf_asp_id, parameter_tvb, ASP_IDENTIFIER_OFFSET, ASP_IDENTIFIER_LENGTH, ENC_BIG_ENDIAN);
proto_item_append_text(parameter_item, " (%u)", tvb_get_ntohl(parameter_tvb, ASP_IDENTIFIER_OFFSET));
}
static void
dissect_correlation_identifier_parameter(tvbuff_t *parameter_tvb, proto_tree *parameter_tree, proto_item *parameter_item)
{
proto_tree_add_item(parameter_tree, hf_correlation_id, parameter_tvb, CORRELATION_ID_OFFSET, CORRELATION_ID_LENGTH, ENC_BIG_ENDIAN);
proto_item_append_text(parameter_item, " (%u)", tvb_get_ntohl(parameter_tvb, CORRELATION_ID_OFFSET));
}
static void
dissect_protocol_data_1_parameter(tvbuff_t *parameter_tvb, packet_info *pinfo, proto_tree *tree, proto_item *parameter_item)
{
tvbuff_t *payload_tvb;
guint32 payload_length;
payload_length = tvb_get_ntohs(parameter_tvb, PARAMETER_LENGTH_OFFSET) - PARAMETER_HEADER_LENGTH;
payload_tvb = tvb_new_subset_length(parameter_tvb, DATA_1_MTP3_OFFSET, payload_length);
proto_item_set_len(parameter_item, PARAMETER_HEADER_LENGTH);
call_dissector(mtp3_handle, payload_tvb, pinfo, tree);
proto_item_set_text(parameter_item, "Data 1 parameter");
}
static void
dissect_protocol_data_2_parameter(tvbuff_t *parameter_tvb, packet_info *pinfo, proto_tree *tree, proto_tree *parameter_tree, proto_item *parameter_item)
{
tvbuff_t *payload_tvb;
guint32 payload_length;
payload_length = tvb_get_ntohs(parameter_tvb, PARAMETER_LENGTH_OFFSET) - PARAMETER_HEADER_LENGTH - DATA_2_LI_LENGTH;
proto_tree_add_item(parameter_tree, hf_data_2_li, parameter_tvb, DATA_2_LI_OFFSET, DATA_2_LI_LENGTH, ENC_BIG_ENDIAN);
payload_tvb = tvb_new_subset_length(parameter_tvb, DATA_2_MTP3_OFFSET, payload_length);
proto_item_set_len(parameter_item, PARAMETER_HEADER_LENGTH + DATA_2_LI_LENGTH);
call_dissector(mtp3_handle, payload_tvb, pinfo, tree);
}
static void
dissect_state_request_parameter(tvbuff_t *parameter_tvb, proto_tree *parameter_tree, proto_item *parameter_item)
{
proto_tree_add_item(parameter_tree, hf_state, parameter_tvb, STATE_OFFSET, STATE_LENGTH, ENC_BIG_ENDIAN);
proto_item_append_text(parameter_item, " (%s)", val_to_str_const(tvb_get_ntohl(parameter_tvb, STATE_OFFSET), state_values, "unknown"));
}
static void
dissect_state_event_parameter(tvbuff_t *parameter_tvb, proto_tree *parameter_tree, proto_item *parameter_item)
{
proto_tree_add_item(parameter_tree, hf_event, parameter_tvb, EVENT_OFFSET, EVENT_LENGTH, ENC_BIG_ENDIAN);
proto_item_append_text(parameter_item, " (%s)", val_to_str_const(tvb_get_ntohl(parameter_tvb, STATE_OFFSET), event_values, "unknown"));
}
static void
dissect_congestion_status_parameter(tvbuff_t *parameter_tvb, proto_tree *parameter_tree, proto_item *parameter_item)
{
proto_tree_add_item(parameter_tree, hf_congestion_status, parameter_tvb, CONGESTION_STATUS_OFFSET, CONGESTION_STATUS_LENGTH, ENC_BIG_ENDIAN);
proto_item_append_text(parameter_item, " (%s)", val_to_str_const(tvb_get_ntohl(parameter_tvb, CONGESTION_STATUS_OFFSET), level_values, "unknown"));
}
static void
dissect_discard_status_parameter(tvbuff_t *parameter_tvb, proto_tree *parameter_tree, proto_item *parameter_item)
{
proto_tree_add_item(parameter_tree, hf_discard_status, parameter_tvb, DISCARD_STATUS_OFFSET, DISCARD_STATUS_LENGTH, ENC_BIG_ENDIAN);
proto_item_append_text(parameter_item, " (%s)", val_to_str_const(tvb_get_ntohl(parameter_tvb, DISCARD_STATUS_OFFSET), level_values, "unknown"));
}
static void
dissect_action_parameter(tvbuff_t *parameter_tvb, proto_tree *parameter_tree, proto_item *parameter_item)
{
proto_tree_add_item(parameter_tree, hf_action, parameter_tvb, ACTION_OFFSET, ACTION_LENGTH, ENC_BIG_ENDIAN);
proto_item_append_text(parameter_item, " (%s)", val_to_str_const(tvb_get_ntohl(parameter_tvb, ACTION_OFFSET), action_values, "unknown"));
}
static void
dissect_sequence_number_parameter(tvbuff_t *parameter_tvb, proto_tree *parameter_tree, proto_item *parameter_item)
{
proto_tree_add_item(parameter_tree, hf_sequence_number, parameter_tvb, SEQUENCE_NUMBER_OFFSET, SEQUENCE_NUMBER_LENGTH, ENC_BIG_ENDIAN);
proto_item_append_text(parameter_item, " (%u)", tvb_get_ntohl(parameter_tvb, SEQUENCE_NUMBER_OFFSET));
}
static void
dissect_retrieval_result_parameter(tvbuff_t *parameter_tvb, proto_tree *parameter_tree, proto_item *parameter_item)
{
proto_tree_add_item(parameter_tree, hf_retrieval_result, parameter_tvb, RETRIEVAL_RESULT_OFFSET, RETRIEVAL_RESULT_LENGTH, ENC_BIG_ENDIAN);
proto_item_append_text(parameter_item, " (%s)", val_to_str_const(tvb_get_ntohl(parameter_tvb, RETRIEVAL_RESULT_OFFSET), retrieval_result_values, "unknown"));
}
static void
dissect_link_key_parameter(tvbuff_t *parameter_tvb, packet_info *pinfo, proto_tree *tree, proto_tree *parameter_tree)
{
tvbuff_t *parameters_tvb;
guint16 parameters_length;
parameters_length = tvb_get_ntohs(parameter_tvb, PARAMETER_LENGTH_OFFSET) - PARAMETER_HEADER_LENGTH;
parameters_tvb = tvb_new_subset_length(parameter_tvb, PARAMETER_VALUE_OFFSET, parameters_length);
dissect_parameters(parameters_tvb, pinfo, tree, parameter_tree);
}
static void
dissect_local_lk_identifier_parameter(tvbuff_t *parameter_tvb, proto_tree *parameter_tree, proto_item *parameter_item)
{
proto_tree_add_item(parameter_tree, hf_local_lk_id, parameter_tvb, LOCAL_LK_ID_OFFSET, LOCAL_LK_ID_LENGTH, ENC_BIG_ENDIAN);
proto_item_append_text(parameter_item, " (%u)", tvb_get_ntohl(parameter_tvb, LOCAL_LK_ID_OFFSET));
}
static void
dissect_sdt_identifier_parameter(tvbuff_t *parameter_tvb, proto_tree *parameter_tree, proto_item *parameter_item)
{
proto_tree_add_item(parameter_tree, hf_sdt_reserved, parameter_tvb, SDT_RESERVED_OFFSET, SDT_RESERVED_LENGTH, ENC_BIG_ENDIAN);
proto_tree_add_item(parameter_tree, hf_sdt_id, parameter_tvb, SDT_ID_OFFSET, SDT_ID_LENGTH, ENC_BIG_ENDIAN);
proto_item_append_text(parameter_item, " (%u)", tvb_get_ntohs(parameter_tvb, SDT_ID_OFFSET));
}
static void
dissect_sdl_identifier_parameter(tvbuff_t *parameter_tvb, proto_tree *parameter_tree, proto_item *parameter_item)
{
proto_tree_add_item(parameter_tree, hf_sdl_reserved, parameter_tvb, SDL_RESERVED_OFFSET, SDL_RESERVED_LENGTH, ENC_BIG_ENDIAN);
proto_tree_add_item(parameter_tree, hf_sdl_id, parameter_tvb, SDL_ID_OFFSET, SDL_ID_LENGTH, ENC_BIG_ENDIAN);
proto_item_append_text(parameter_item, " (%u)", tvb_get_ntohs(parameter_tvb, SDL_ID_OFFSET));
}
static void
dissect_registration_result_parameter(tvbuff_t *parameter_tvb, packet_info *pinfo, proto_tree *tree, proto_tree *parameter_tree)
{
tvbuff_t *parameters_tvb;
guint16 parameters_length;
parameters_length = tvb_get_ntohs(parameter_tvb, PARAMETER_LENGTH_OFFSET) - PARAMETER_HEADER_LENGTH;
parameters_tvb = tvb_new_subset_length(parameter_tvb, PARAMETER_VALUE_OFFSET, parameters_length);
dissect_parameters(parameters_tvb, pinfo, tree, parameter_tree);
}
static void
dissect_registration_status_parameter(tvbuff_t *parameter_tvb, proto_tree *parameter_tree, proto_item *parameter_item)
{
proto_tree_add_item(parameter_tree, hf_registration_status, parameter_tvb, REGISTRATION_STATUS_OFFSET, REGISTRATION_STATUS_LENGTH, ENC_BIG_ENDIAN);
proto_item_append_text(parameter_item, " (%s)", val_to_str_const(tvb_get_ntohl(parameter_tvb, REGISTRATION_STATUS_OFFSET), registration_status_values, "unknown"));
}
static void
dissect_deregistration_result_parameter(tvbuff_t *parameter_tvb, packet_info *pinfo, proto_tree *tree, proto_tree *parameter_tree)
{
tvbuff_t *parameters_tvb;
guint16 parameters_length;
parameters_length = tvb_get_ntohs(parameter_tvb, PARAMETER_LENGTH_OFFSET) - PARAMETER_HEADER_LENGTH;
parameters_tvb = tvb_new_subset_length(parameter_tvb, PARAMETER_VALUE_OFFSET, parameters_length);
dissect_parameters(parameters_tvb, pinfo, tree, parameter_tree);
}
static void
dissect_deregistration_status_parameter(tvbuff_t *parameter_tvb, proto_tree *parameter_tree, proto_item *parameter_item)
{
proto_tree_add_item(parameter_tree, hf_deregistration_status, parameter_tvb, DEREGISTRATION_STATUS_OFFSET, DEREGISTRATION_STATUS_LENGTH, ENC_BIG_ENDIAN);
proto_item_append_text(parameter_item, " (%s)", val_to_str_const(tvb_get_ntohl(parameter_tvb, DEREGISTRATION_STATUS_OFFSET), deregistration_status_values, "unknown"));
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
dissect_parameter(tvbuff_t *parameter_tvb, packet_info *pinfo, proto_tree *tree, proto_tree *m2ua_tree)
{
guint16 tag, length, padding_length;
proto_item *parameter_item;
proto_tree *parameter_tree;
tag = tvb_get_ntohs(parameter_tvb, PARAMETER_TAG_OFFSET);
length = tvb_get_ntohs(parameter_tvb, PARAMETER_LENGTH_OFFSET);
padding_length = tvb_reported_length(parameter_tvb) - length;
parameter_tree = proto_tree_add_subtree(m2ua_tree, parameter_tvb, PARAMETER_HEADER_OFFSET, -1,
ett_m2ua_parameter, &parameter_item, val_to_str_const(tag, parameter_tag_values, "Unknown parameter"));
if ((protocol_data_1_global == PROTOCOL_DATA_1_DRAFT_7) &&
(tag == PROTOCOL_DATA_1_DRAFT_7))
{
proto_item *hidden_item;
hidden_item = proto_tree_add_uint(parameter_tree, hf_parameter_tag, parameter_tvb, PARAMETER_TAG_OFFSET, PARAMETER_TAG_LENGTH, tag);
PROTO_ITEM_SET_HIDDEN(hidden_item);
proto_tree_add_uint_format_value(parameter_tree, hf_parameter_tag, parameter_tvb, PARAMETER_TAG_OFFSET, PARAMETER_TAG_LENGTH,
tag, "Protocol data 1 (0x000e)");
proto_tree_add_item(parameter_tree, hf_parameter_length, parameter_tvb, PARAMETER_LENGTH_OFFSET, PARAMETER_LENGTH_LENGTH, ENC_BIG_ENDIAN);
tag = PROTOCOL_DATA_1_PARAMETER_TAG;
}
else
{
proto_tree_add_item(parameter_tree, hf_parameter_tag, parameter_tvb, PARAMETER_TAG_OFFSET, PARAMETER_TAG_LENGTH, ENC_BIG_ENDIAN);
proto_tree_add_item(parameter_tree, hf_parameter_length, parameter_tvb, PARAMETER_LENGTH_OFFSET, PARAMETER_LENGTH_LENGTH, ENC_BIG_ENDIAN);
}
switch(tag) {
case INTERFACE_IDENTIFIER_INT_PARAMETER_TAG:
dissect_interface_identifier_int_parameter(parameter_tvb, parameter_tree, parameter_item);
break;
case INTERFACE_IDENTIFIER_TEXT_PARAMETER_TAG:
dissect_interface_identifier_text_parameter(parameter_tvb, parameter_tree, parameter_item);
break;
case INFO_STRING_PARAMETER_TAG:
dissect_info_string_parameter(parameter_tvb, parameter_tree, parameter_item);
break;
case DIAGNOSTIC_INFORMATION_PARAMETER_TAG:
dissect_diagnostic_information_parameter(parameter_tvb, parameter_tree, parameter_item);
break;
case INTERFACE_IDENTIFIER_RANGE_PARAMETER_TAG:
dissect_interface_identifier_range_parameter(parameter_tvb, parameter_tree, parameter_item);
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
case STATUS_PARAMETER_TAG:
dissect_status_parameter(parameter_tvb, parameter_tree, parameter_item);
break;
case ASP_IDENTIFIER_PARAMETER_TAG:
dissect_asp_identifier_parameter(parameter_tvb, parameter_tree, parameter_item);
break;
case CORRELATION_IDENTIFIER_PARAMETER_TAG:
dissect_correlation_identifier_parameter(parameter_tvb, parameter_tree, parameter_item);
break;
case PROTOCOL_DATA_1_PARAMETER_TAG:
dissect_protocol_data_1_parameter(parameter_tvb, pinfo, tree, parameter_item);
break;
case PROTOCOL_DATA_2_PARAMETER_TAG:
dissect_protocol_data_2_parameter(parameter_tvb, pinfo, tree, parameter_tree, parameter_item);
break;
case STATE_REQUEST_PARAMETER_TAG:
dissect_state_request_parameter(parameter_tvb, parameter_tree, parameter_item);
break;
case STATE_EVENT_PARAMETER_TAG:
dissect_state_event_parameter(parameter_tvb, parameter_tree, parameter_item);
break;
case CONGESTION_STATUS_PARAMETER_TAG:
dissect_congestion_status_parameter(parameter_tvb, parameter_tree, parameter_item);
break;
case DISCARD_STATUS_PARAMETER_TAG:
dissect_discard_status_parameter(parameter_tvb, parameter_tree, parameter_item);
break;
case ACTION_PARAMETER_TAG:
dissect_action_parameter(parameter_tvb, parameter_tree, parameter_item);
break;
case SEQUENCE_NUMBER_PARAMETER_TAG:
dissect_sequence_number_parameter(parameter_tvb, parameter_tree, parameter_item);
break;
case RETRIEVAL_RESULT_PARAMETER_TAG:
dissect_retrieval_result_parameter(parameter_tvb, parameter_tree, parameter_item);
break;
case LINK_KEY_PARAMETER_TAG:
dissect_link_key_parameter(parameter_tvb, pinfo, tree, parameter_tree);
break;
case LOCAL_LK_IDENTIFIER_PARAMETER_TAG:
dissect_local_lk_identifier_parameter(parameter_tvb, parameter_tree, parameter_item);
break;
case SDT_IDENTIFIER_PARAMETER_TAG:
dissect_sdt_identifier_parameter(parameter_tvb, parameter_tree, parameter_item);
break;
case SDL_IDENTIFIER_PARAMETER_TAG:
dissect_sdl_identifier_parameter(parameter_tvb, parameter_tree, parameter_item);
break;
case REG_RESULT_PARAMETER_TAG:
dissect_registration_result_parameter(parameter_tvb, pinfo, tree, parameter_tree);
break;
case REG_STATUS_PARAMETER_TAG:
dissect_registration_status_parameter(parameter_tvb, parameter_tree, parameter_item);
break;
case DEREG_RESULT_PARAMETER_TAG:
dissect_deregistration_result_parameter(parameter_tvb, pinfo, tree, parameter_tree);
break;
case DEREG_STATUS_PARAMETER_TAG:
dissect_deregistration_status_parameter(parameter_tvb, parameter_tree, parameter_item);
break;
default:
dissect_unknown_parameter(parameter_tvb, parameter_tree, parameter_item);
break;
};
if (padding_length > 0)
proto_tree_add_item(parameter_tree, hf_parameter_padding, parameter_tvb, PARAMETER_HEADER_OFFSET + length, padding_length, ENC_NA);
}
static void
dissect_parameters(tvbuff_t *parameters_tvb, packet_info *pinfo, proto_tree *tree, proto_tree *m2ua_tree)
{
gint offset, length, total_length, remaining_length;
tvbuff_t *parameter_tvb;
offset = 0;
while((remaining_length = tvb_reported_length_remaining(parameters_tvb, offset))) {
length = tvb_get_ntohs(parameters_tvb, offset + PARAMETER_LENGTH_OFFSET);
total_length = ADD_PADDING(length);
if (remaining_length >= length)
total_length = MIN(total_length, remaining_length);
parameter_tvb = tvb_new_subset_length(parameters_tvb, offset, total_length);
dissect_parameter(parameter_tvb, pinfo, tree, m2ua_tree);
offset += total_length;
}
}
static void
dissect_message(tvbuff_t *message_tvb, packet_info *pinfo, proto_tree *tree, proto_tree *m2ua_tree)
{
tvbuff_t *common_header_tvb, *parameters_tvb;
common_header_tvb = tvb_new_subset_length(message_tvb, 0, COMMON_HEADER_LENGTH);
parameters_tvb = tvb_new_subset_remaining(message_tvb, COMMON_HEADER_LENGTH);
dissect_common_header(common_header_tvb, pinfo, m2ua_tree);
dissect_parameters(parameters_tvb, pinfo, tree, m2ua_tree);
}
static int
dissect_m2ua(tvbuff_t *message_tvb, packet_info *pinfo, proto_tree *tree, void* data _U_)
{
proto_item *m2ua_item;
proto_tree *m2ua_tree;
col_set_str(pinfo->cinfo, COL_PROTOCOL, "M2UA");
m2ua_item = proto_tree_add_item(tree, proto_m2ua, message_tvb, 0, -1, ENC_NA);
m2ua_tree = proto_item_add_subtree(m2ua_item, ett_m2ua);
dissect_message(message_tvb, pinfo, tree, m2ua_tree);
return tvb_captured_length(message_tvb);
}
void
proto_register_m2ua(void)
{
static hf_register_info hf[] = {
{ &hf_version, { "Version", "m2ua.version", FT_UINT8, BASE_DEC, VALS(protocol_version_values), 0x0, NULL, HFILL } },
{ &hf_reserved, { "Reserved", "m2ua.reserved", FT_UINT8, BASE_HEX, NULL, 0x0, NULL, HFILL } },
{ &hf_message_class, { "Message class", "m2ua.message_class", FT_UINT8, BASE_DEC, VALS(message_class_values), 0x0, NULL, HFILL } },
{ &hf_message_type, { "Message Type", "m2ua.message_type", FT_UINT8, BASE_DEC, NULL, 0x0, NULL, HFILL } },
{ &hf_message_length, { "Message length", "m2ua.message_length", FT_UINT32, BASE_DEC, NULL, 0x0, NULL, HFILL } },
{ &hf_parameter_tag, { "Parameter Tag", "m2ua.parameter_tag", FT_UINT16, BASE_HEX, VALS(parameter_tag_values), 0x0, NULL, HFILL } },
{ &hf_parameter_length, { "Parameter length", "m2ua.parameter_length", FT_UINT16, BASE_DEC, NULL, 0x0, NULL, HFILL } },
{ &hf_parameter_value, { "Parameter value", "m2ua.parameter_value", FT_BYTES, BASE_NONE, NULL, 0x0, NULL, HFILL } },
{ &hf_parameter_padding, { "Padding", "m2ua.parameter_padding", FT_BYTES, BASE_NONE, NULL, 0x0, NULL, HFILL } },
{ &hf_interface_id_int, { "Interface Identifier (integer)", "m2ua.interface_identifier_int", FT_UINT32, BASE_DEC, NULL, 0x0, NULL, HFILL } },
{ &hf_interface_id_text, { "Interface identifier (text)", "m2ua.interface_identifier_text", FT_STRING, BASE_NONE, NULL, 0x0, NULL, HFILL } },
{ &hf_info_string, { "Info string", "m2ua.info_string", FT_STRING, BASE_NONE, NULL, 0x0, NULL, HFILL } },
{ &hf_diagnostic_information, { "Diagnostic information", "m2ua.diagnostic_information", FT_BYTES, BASE_NONE, NULL, 0x0, NULL, HFILL } },
{ &hf_interface_id_start, { "Interface Identifier (start)", "m2ua.interface_identifier_start", FT_UINT32, BASE_DEC, NULL, 0x0, NULL, HFILL } },
{ &hf_interface_id_stop, { "Interface Identifier (stop)", "m2ua.interface_identifier_stop", FT_UINT32, BASE_DEC, NULL, 0x0, NULL, HFILL } },
{ &hf_heartbeat_data, { "Heartbeat data", "m2ua.heartbeat_data", FT_BYTES, BASE_NONE, NULL, 0x0, NULL, HFILL } },
{ &hf_traffic_mode_type, { "Traffic mode Type", "m2ua.traffic_mode_type", FT_UINT32, BASE_DEC, VALS(traffic_mode_type_values), 0x0, NULL, HFILL } },
{ &hf_error_code, { "Error code", "m2ua.error_code", FT_UINT32, BASE_DEC, VALS(error_code_values), 0x0, NULL, HFILL } },
{ &hf_status_type, { "Status type", "m2ua.status_type", FT_UINT16, BASE_DEC, VALS(status_type_values), 0x0, NULL, HFILL } },
{ &hf_status_ident, { "Status info", "m2ua.status_info", FT_UINT16, BASE_DEC, NULL, 0x0, NULL, HFILL } },
{ &hf_asp_id, { "ASP identifier", "m2ua.asp_identifier", FT_UINT32, BASE_DEC, NULL, 0x0, NULL, HFILL } },
{ &hf_correlation_id, { "Correlation identifier", "m2ua.correlation_identifier", FT_UINT32, BASE_DEC, NULL, 0x0, NULL, HFILL } },
{ &hf_data_2_li, { "Length indicator", "m2ua.data_2_li", FT_UINT8, BASE_DEC, NULL, 0x0, NULL, HFILL } },
{ &hf_state, { "State", "m2ua.state", FT_UINT32, BASE_DEC, VALS(state_values), 0x0, NULL, HFILL } },
{ &hf_event, { "Event", "m2ua.event", FT_UINT32, BASE_DEC, VALS(event_values), 0x0, NULL, HFILL } },
{ &hf_congestion_status, { "Congestion status", "m2ua.congestion_status", FT_UINT32, BASE_DEC, VALS(level_values), 0x0, NULL, HFILL } },
{ &hf_discard_status, { "Discard status", "m2ua.discard_status", FT_UINT32, BASE_DEC, VALS(level_values), 0x0, NULL, HFILL } },
{ &hf_action, { "Actions", "m2ua.action", FT_UINT32, BASE_DEC, VALS(action_values), 0x0, NULL, HFILL } },
{ &hf_sequence_number, { "Sequence number", "m2ua.sequence_number", FT_UINT32, BASE_DEC, NULL, 0x0, NULL, HFILL } },
{ &hf_retrieval_result, { "Retrieval result", "m2ua.retrieval_result", FT_UINT32, BASE_DEC, VALS(retrieval_result_values), 0x0, NULL, HFILL } },
{ &hf_local_lk_id, { "Local LK identifier", "m2ua.local_lk_identifier", FT_UINT32, BASE_DEC, NULL, 0x0, NULL, HFILL } },
{ &hf_sdt_reserved, { "Reserved", "m2ua.sdt_reserved", FT_UINT16, BASE_HEX, NULL, 0x0, NULL, HFILL } },
{ &hf_sdt_id, { "SDT identifier", "m2ua.sdt_identifier", FT_UINT16, BASE_DEC, NULL, 0x0, NULL, HFILL } },
{ &hf_sdl_reserved, { "Reserved", "m2ua.sdl_reserved", FT_UINT16, BASE_HEX, NULL, 0x0, NULL, HFILL } },
{ &hf_sdl_id, { "SDL identifier", "m2ua.sdl_identifier", FT_UINT16, BASE_DEC, NULL, 0x0, NULL, HFILL } },
{ &hf_registration_status, { "Registration status", "m2ua.registration_status", FT_UINT32, BASE_DEC, VALS(registration_status_values), 0x0, NULL, HFILL } },
{ &hf_deregistration_status, { "Deregistration status", "m2ua.deregistration_status", FT_UINT32, BASE_DEC, VALS(deregistration_status_values), 0x0, NULL, HFILL } },
};
static gint *ett[] = {
&ett_m2ua,
&ett_m2ua_parameter,
};
static const enum_val_t protocol_data_1_options[] = {
{ "draft-7", "0x000e (Draft 7)", PROTOCOL_DATA_1_DRAFT_7 },
{ "rfc3331", "0x0300 (RFC3331)", PROTOCOL_DATA_1_PARAMETER_TAG },
{ NULL, NULL, 0 }
};
module_t *m2ua_module;
proto_m2ua = proto_register_protocol("MTP 2 User Adaptation Layer", "M2UA", "m2ua");
proto_register_field_array(proto_m2ua, hf, array_length(hf));
proto_register_subtree_array(ett, array_length(ett));
m2ua_module = prefs_register_protocol(proto_m2ua, NULL);
prefs_register_enum_preference(m2ua_module,
"protocol_data_1_tag",
"Protocol Data 1 Parameter Tag",
"The value of the parameter tag for protocol data 1",
&protocol_data_1_global,
protocol_data_1_options,
FALSE);
}
void
proto_reg_handoff_m2ua(void)
{
dissector_handle_t m2ua_handle;
mtp3_handle = find_dissector_add_dependency("mtp3", proto_m2ua);
m2ua_handle = create_dissector_handle(dissect_m2ua, proto_m2ua);
dissector_add_uint("sctp.ppi", M2UA_PAYLOAD_PROTOCOL_ID, m2ua_handle);
dissector_add_uint("sctp.port", SCTP_PORT_M2UA, m2ua_handle);
}
