static void
dissect_v5_common_header(tvbuff_t *common_header_tvb, packet_info *pinfo, proto_tree *m3ua_tree)
{
guint8 message_class, message_type;
message_class = tvb_get_guint8(common_header_tvb, MESSAGE_CLASS_OFFSET);
message_type = tvb_get_guint8(common_header_tvb, MESSAGE_TYPE_OFFSET);
col_add_fstr(pinfo->cinfo, COL_INFO, "%s ", val_to_str_const(message_class * 256 + message_type, v5_message_class_type_acro_values, "reserved"));
if (m3ua_tree) {
proto_tree_add_item(m3ua_tree, hf_version, common_header_tvb, VERSION_OFFSET, VERSION_LENGTH, ENC_BIG_ENDIAN);
proto_tree_add_item(m3ua_tree, hf_reserved, common_header_tvb, RESERVED_OFFSET, RESERVED_LENGTH, ENC_BIG_ENDIAN);
proto_tree_add_item(m3ua_tree, hf_v5_message_class, common_header_tvb, MESSAGE_CLASS_OFFSET, MESSAGE_CLASS_LENGTH, ENC_BIG_ENDIAN);
proto_tree_add_uint_format_value(m3ua_tree, hf_message_type, common_header_tvb, MESSAGE_TYPE_OFFSET, MESSAGE_TYPE_LENGTH, message_type,
"%s (%u)", val_to_str_const(message_class * 256 + message_type, v5_message_class_type_values, "reserved"), message_type);
proto_tree_add_item(m3ua_tree, hf_message_length, common_header_tvb, MESSAGE_LENGTH_OFFSET, MESSAGE_LENGTH_LENGTH, ENC_BIG_ENDIAN);
}
}
static void
dissect_common_header(tvbuff_t *common_header_tvb, packet_info *pinfo, proto_tree *m3ua_tree)
{
guint8 message_class, message_type;
message_class = tvb_get_guint8(common_header_tvb, MESSAGE_CLASS_OFFSET);
message_type = tvb_get_guint8(common_header_tvb, MESSAGE_TYPE_OFFSET);
col_add_fstr(pinfo->cinfo, COL_INFO,"%s ", val_to_str_const(message_class * 256 + message_type, message_class_type_acro_values, "reserved"));
if (m3ua_tree) {
proto_tree_add_item(m3ua_tree, hf_version, common_header_tvb, VERSION_OFFSET, VERSION_LENGTH, ENC_BIG_ENDIAN);
proto_tree_add_item(m3ua_tree, hf_reserved, common_header_tvb, RESERVED_OFFSET, RESERVED_LENGTH, ENC_BIG_ENDIAN);
proto_tree_add_item(m3ua_tree, hf_message_class, common_header_tvb, MESSAGE_CLASS_OFFSET, MESSAGE_CLASS_LENGTH, ENC_BIG_ENDIAN);
proto_tree_add_uint_format_value(m3ua_tree, hf_message_type, common_header_tvb, MESSAGE_TYPE_OFFSET, MESSAGE_TYPE_LENGTH, message_type,
"%s (%u)", val_to_str_const(message_class * 256 + message_type, message_class_type_values, "reserved"), message_type);
proto_tree_add_item(m3ua_tree, hf_message_length, common_header_tvb, MESSAGE_LENGTH_OFFSET, MESSAGE_LENGTH_LENGTH, ENC_BIG_ENDIAN);
}
}
static void
dissect_network_appearance_parameter(tvbuff_t *parameter_tvb, proto_tree *parameter_tree, proto_item *parameter_item)
{
proto_tree_add_item(parameter_tree, hf_network_appearance, parameter_tvb, NETWORK_APPEARANCE_OFFSET, NETWORK_APPEARANCE_LENGTH, ENC_BIG_ENDIAN);
proto_item_append_text(parameter_item, " (%u)", tvb_get_ntohl(parameter_tvb, NETWORK_APPEARANCE_OFFSET));
}
static void
dissect_v5_protocol_data_parameter(tvbuff_t *parameter_tvb, packet_info *pinfo, proto_tree *tree, proto_item *parameter_item)
{
guint16 length, protocol_data_length;
tvbuff_t *payload_tvb;
length = tvb_get_ntohs(parameter_tvb, PARAMETER_LENGTH_OFFSET);
protocol_data_length = length - PARAMETER_HEADER_LENGTH;
payload_tvb = tvb_new_subset(parameter_tvb, V5_PROTOCOL_DATA_OFFSET, protocol_data_length, protocol_data_length);
proto_item_append_text(parameter_item, " (SS7 message of %u byte%s)", protocol_data_length, plurality(protocol_data_length, "", "s"));
proto_item_set_len(parameter_item, PARAMETER_HEADER_LENGTH);
call_dissector(mtp3_handle, payload_tvb, pinfo, tree);
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
dissect_affected_destinations_parameter(tvbuff_t *parameter_tvb, proto_tree *parameter_tree, proto_item *parameter_item)
{
guint16 number_of_destinations, destination_number;
gint destination_offset;
proto_item *item;
number_of_destinations = (tvb_get_ntohs(parameter_tvb, PARAMETER_LENGTH_OFFSET) - PARAMETER_HEADER_LENGTH) >> 2;
destination_offset = PARAMETER_VALUE_OFFSET;
for(destination_number=0; destination_number < number_of_destinations; destination_number++) {
proto_tree_add_item(parameter_tree, hf_affected_point_code_mask, parameter_tvb, destination_offset + AFFECTED_MASK_OFFSET, AFFECTED_MASK_LENGTH, ENC_BIG_ENDIAN);
item = proto_tree_add_item(parameter_tree, hf_affected_point_code_pc, parameter_tvb, destination_offset + AFFECTED_DPC_OFFSET, AFFECTED_DPC_LENGTH, ENC_BIG_ENDIAN);
if (mtp3_pc_structured())
proto_item_append_text(item, " (%s)", mtp3_pc_to_str(tvb_get_ntoh24(parameter_tvb, destination_offset + AFFECTED_DPC_OFFSET)));
destination_offset += AFFECTED_DESTINATION_LENGTH;
}
proto_item_append_text(parameter_item, " (%u destination%s)", number_of_destinations, plurality(number_of_destinations, "", "s"));
}
static void
dissect_routing_context_parameter(tvbuff_t *parameter_tvb, proto_tree *parameter_tree, proto_item *parameter_item)
{
guint16 number_of_contexts, context_number;
gint context_offset;
number_of_contexts = (tvb_get_ntohs(parameter_tvb, PARAMETER_LENGTH_OFFSET) - PARAMETER_HEADER_LENGTH) >> 2;
context_offset = PARAMETER_VALUE_OFFSET;
for(context_number=0; context_number < number_of_contexts; context_number++) {
proto_tree_add_item(parameter_tree, hf_routing_context, parameter_tvb, context_offset, ROUTING_CONTEXT_LENGTH, ENC_BIG_ENDIAN);
context_offset += ROUTING_CONTEXT_LENGTH;
};
proto_item_append_text(parameter_item, " (%u context%s)", number_of_contexts, plurality(number_of_contexts, "", "s"));
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
dissect_heartbeat_data_parameter(tvbuff_t *parameter_tvb, proto_tree *parameter_tree, proto_item *parameter_item)
{
guint16 heartbeat_data_length;
heartbeat_data_length = tvb_get_ntohs(parameter_tvb, PARAMETER_LENGTH_OFFSET) - PARAMETER_HEADER_LENGTH;
proto_tree_add_item(parameter_tree, hf_heartbeat_data, parameter_tvb, HEARTBEAT_DATA_OFFSET, heartbeat_data_length, ENC_NA);
proto_item_append_text(parameter_item, " (%u byte%s)", heartbeat_data_length, plurality(heartbeat_data_length, "", "s"));
}
static void
dissect_user_cause_parameter(tvbuff_t *parameter_tvb, proto_tree *parameter_tree, proto_item *parameter_item)
{
proto_tree_add_item(parameter_tree, hf_cause, parameter_tvb, CAUSE_OFFSET, CAUSE_LENGTH, ENC_BIG_ENDIAN);
proto_tree_add_item(parameter_tree, hf_user, parameter_tvb, USER_OFFSET, USER_LENGTH, ENC_BIG_ENDIAN);
proto_item_append_text(parameter_item, " (%s: %s)",
val_to_str_const(tvb_get_ntohs(parameter_tvb, USER_OFFSET), user_identity_values, "Unknown user"),
val_to_str_const(tvb_get_ntohs(parameter_tvb, CAUSE_OFFSET), unavailability_cause_values, "unknown cause"));
}
static void
dissect_reason_parameter(tvbuff_t *parameter_tvb, proto_tree *parameter_tree, proto_item *parameter_item)
{
proto_tree_add_item(parameter_tree, hf_reason, parameter_tvb, REASON_OFFSET, REASON_LENGTH, ENC_BIG_ENDIAN);
proto_item_append_text(parameter_item, " (%s)", val_to_str_const(tvb_get_ntohl(parameter_tvb, REASON_OFFSET), reason_values, "unknown"));
}
static void
dissect_v5_traffic_mode_type_parameter(tvbuff_t *parameter_tvb, proto_tree *parameter_tree, proto_item *parameter_item)
{
proto_tree_add_item(parameter_tree, hf_v5_traffic_mode_type, parameter_tvb, TRAFFIC_MODE_TYPE_OFFSET, TRAFFIC_MODE_TYPE_LENGTH, ENC_BIG_ENDIAN);
proto_item_append_text(parameter_item, " (%s)", val_to_str_const(tvb_get_ntohl(parameter_tvb, TRAFFIC_MODE_TYPE_OFFSET), v5_traffic_mode_type_values, "unknown"));
}
static void
dissect_v6_traffic_mode_type_parameter(tvbuff_t *parameter_tvb, proto_tree *parameter_tree, proto_item *parameter_item)
{
proto_tree_add_item(parameter_tree, hf_v6_traffic_mode_type, parameter_tvb, TRAFFIC_MODE_TYPE_OFFSET, TRAFFIC_MODE_TYPE_LENGTH, ENC_BIG_ENDIAN);
proto_item_append_text(parameter_item, " (%s)", val_to_str_const(tvb_get_ntohl(parameter_tvb, TRAFFIC_MODE_TYPE_OFFSET), v6_traffic_mode_type_values, "unknown"));
}
static void
dissect_v7_traffic_mode_type_parameter(tvbuff_t *parameter_tvb, proto_tree *parameter_tree, proto_item *parameter_item)
{
proto_tree_add_item(parameter_tree, hf_v7_traffic_mode_type, parameter_tvb, TRAFFIC_MODE_TYPE_OFFSET, TRAFFIC_MODE_TYPE_LENGTH, ENC_BIG_ENDIAN);
proto_item_append_text(parameter_item, " (%s)", val_to_str_const(tvb_get_ntohl(parameter_tvb, TRAFFIC_MODE_TYPE_OFFSET), v7_traffic_mode_type_values, "unknown"));
}
static void
dissect_traffic_mode_type_parameter(tvbuff_t *parameter_tvb, proto_tree *parameter_tree, proto_item *parameter_item)
{
proto_tree_add_item(parameter_tree, hf_traffic_mode_type, parameter_tvb, TRAFFIC_MODE_TYPE_OFFSET, TRAFFIC_MODE_TYPE_LENGTH, ENC_BIG_ENDIAN);
proto_item_append_text(parameter_item, " (%s)", val_to_str_const(tvb_get_ntohl(parameter_tvb, TRAFFIC_MODE_TYPE_OFFSET), traffic_mode_type_values, "unknown"));
}
static void
dissect_v5_error_code_parameter(tvbuff_t *parameter_tvb, proto_tree *parameter_tree, proto_item *parameter_item)
{
proto_tree_add_item(parameter_tree, hf_v5_error_code, parameter_tvb, ERROR_CODE_OFFSET, ERROR_CODE_LENGTH, ENC_BIG_ENDIAN);
proto_item_append_text(parameter_item, " (%s)", val_to_str_const(tvb_get_ntohl(parameter_tvb, ERROR_CODE_OFFSET), v5_error_code_values, "unknown"));
}
static void
dissect_v6_error_code_parameter(tvbuff_t *parameter_tvb, proto_tree *parameter_tree, proto_item *parameter_item)
{
proto_tree_add_item(parameter_tree, hf_v6_error_code, parameter_tvb, ERROR_CODE_OFFSET, ERROR_CODE_LENGTH, ENC_BIG_ENDIAN);
proto_item_append_text(parameter_item, " (%s)", val_to_str_const(tvb_get_ntohl(parameter_tvb, ERROR_CODE_OFFSET), v6_error_code_values, "unknown"));
}
static void
dissect_v7_error_code_parameter(tvbuff_t *parameter_tvb, proto_tree *parameter_tree, proto_item *parameter_item)
{
proto_tree_add_item(parameter_tree, hf_v7_error_code, parameter_tvb, ERROR_CODE_OFFSET, ERROR_CODE_LENGTH, ENC_BIG_ENDIAN);
proto_item_append_text(parameter_item, " (%s)", val_to_str_const(tvb_get_ntohl(parameter_tvb, ERROR_CODE_OFFSET), v7_error_code_values, "unknown"));
}
static void
dissect_error_code_parameter(tvbuff_t *parameter_tvb, proto_tree *parameter_tree, proto_item *parameter_item)
{
proto_tree_add_item(parameter_tree, hf_error_code, parameter_tvb, ERROR_CODE_OFFSET, ERROR_CODE_LENGTH, ENC_BIG_ENDIAN);
proto_item_append_text(parameter_item, " (%s)", val_to_str_const(tvb_get_ntohl(parameter_tvb, ERROR_CODE_OFFSET), error_code_values, "unknown"));
}
static void
dissect_v567_status_parameter(tvbuff_t *parameter_tvb, proto_tree *parameter_tree, proto_item *parameter_item)
{
guint16 status_type, status_info;
status_type = tvb_get_ntohs(parameter_tvb, STATUS_TYPE_OFFSET);
status_info = tvb_get_ntohs(parameter_tvb, STATUS_INFO_OFFSET);
proto_tree_add_item(parameter_tree, hf_status_type, parameter_tvb, STATUS_TYPE_OFFSET, STATUS_TYPE_LENGTH, ENC_BIG_ENDIAN);
proto_tree_add_uint_format_value(parameter_tree, hf_status_info, parameter_tvb, STATUS_INFO_OFFSET, STATUS_INFO_LENGTH, status_info,
"%s (%u)", val_to_str_const(status_type * 256 * 256 + status_info, v567_status_type_info_values, "unknown"), status_info);
proto_item_append_text(parameter_item, " (%s)", val_to_str_const(status_type * 256 * 256 + status_info, v567_status_type_info_values, "unknown status information"));
}
static void
dissect_status_parameter(tvbuff_t *parameter_tvb, proto_tree *parameter_tree, proto_item *parameter_item)
{
guint16 status_type, status_info;
status_type = tvb_get_ntohs(parameter_tvb, STATUS_TYPE_OFFSET);
status_info = tvb_get_ntohs(parameter_tvb, STATUS_INFO_OFFSET);
proto_tree_add_item(parameter_tree, hf_status_type, parameter_tvb, STATUS_TYPE_OFFSET, STATUS_TYPE_LENGTH, ENC_BIG_ENDIAN);
proto_tree_add_uint_format_value(parameter_tree, hf_status_info, parameter_tvb, STATUS_INFO_OFFSET, STATUS_INFO_LENGTH, status_info,
"%s (%u)", val_to_str_const(status_type * 256 * 256 + status_info, status_type_info_values, "unknown"), status_info);
proto_item_append_text(parameter_item, " (%s)", val_to_str_const(status_type * 256 * 256 + status_info, status_type_info_values, "unknown status information"));
}
static void
dissect_congestion_indication_parameter(tvbuff_t *parameter_tvb, proto_tree *parameter_tree, proto_item *parameter_item)
{
proto_tree_add_item(parameter_tree, hf_congestion_reserved, parameter_tvb, CONG_IND_RESERVED_OFFSET, CONG_IND_RESERVED_LENGTH, ENC_NA);
proto_tree_add_item(parameter_tree, hf_congestion_level, parameter_tvb, CONG_IND_LEVEL_OFFSET, CONG_IND_LEVEL_LENGTH, ENC_BIG_ENDIAN);
proto_item_append_text(parameter_item, " (%s)", val_to_str_const(tvb_get_guint8(parameter_tvb, CONG_IND_LEVEL_OFFSET), congestion_level_values, "unknown"));
}
static void
dissect_asp_identifier_parameter(tvbuff_t *parameter_tvb, proto_tree *parameter_tree, proto_item *parameter_item)
{
proto_tree_add_item(parameter_tree, hf_asp_identifier, parameter_tvb, ASP_IDENTIFIER_OFFSET, ASP_IDENTIFIER_LENGTH, ENC_BIG_ENDIAN);
proto_item_append_text(parameter_item, " (%u)", tvb_get_ntohl(parameter_tvb, ASP_IDENTIFIER_OFFSET));
}
static void
dissect_protocol_data_1_parameter(tvbuff_t *parameter_tvb, packet_info *pinfo, proto_tree *tree, proto_item *parameter_item)
{
guint16 protocol_data_length;
tvbuff_t *payload_tvb;
protocol_data_length = tvb_get_ntohs(parameter_tvb, PARAMETER_LENGTH_OFFSET) - PARAMETER_HEADER_LENGTH;
payload_tvb = tvb_new_subset(parameter_tvb, PROTOCOL_DATA_1_OFFSET, protocol_data_length, protocol_data_length);
proto_item_append_text(parameter_item, " (SS7 message of %u byte%s)", protocol_data_length, plurality(protocol_data_length, "", "s"));
proto_item_set_len(parameter_item, PARAMETER_HEADER_LENGTH);
call_dissector(mtp3_handle, payload_tvb, pinfo, tree);
}
static void
dissect_protocol_data_2_parameter(tvbuff_t *parameter_tvb, packet_info *pinfo, proto_tree *tree, proto_tree *parameter_tree, proto_item *parameter_item)
{
guint16 protocol_data_length;
tvbuff_t *payload_tvb;
protocol_data_length = tvb_get_ntohs(parameter_tvb, PARAMETER_LENGTH_OFFSET) - PARAMETER_HEADER_LENGTH - LI_OCTETT_LENGTH;
payload_tvb = tvb_new_subset(parameter_tvb, PROTOCOL_DATA_2_OFFSET, protocol_data_length, protocol_data_length);
proto_tree_add_item(parameter_tree, hf_li, parameter_tvb, LI_OCTETT_OFFSET, LI_OCTETT_LENGTH, ENC_BIG_ENDIAN);
proto_item_append_text(parameter_item, " (SS7 message of %u byte%s)", protocol_data_length, plurality(protocol_data_length, "", "s"));
proto_item_set_len(parameter_item, PARAMETER_HEADER_LENGTH + LI_OCTETT_LENGTH);
call_dissector(mtp3_handle, payload_tvb, pinfo, tree);
}
static void
dissect_concerned_destination_parameter(tvbuff_t *parameter_tvb, proto_tree *parameter_tree, proto_item *parameter_item)
{
proto_item *item;
proto_tree_add_item(parameter_tree, hf_concerned_dest_reserved, parameter_tvb, CON_DEST_RESERVED_OFFSET, CON_DEST_RESERVED_LENGTH, ENC_NA);
item = proto_tree_add_item(parameter_tree, hf_concerned_dest_pc, parameter_tvb, CON_DEST_PC_OFFSET, CON_DEST_PC_LENGTH, ENC_BIG_ENDIAN);
if (mtp3_pc_structured())
proto_item_append_text(item, " (%s)", mtp3_pc_to_str(tvb_get_ntoh24(parameter_tvb, CON_DEST_PC_OFFSET)));
proto_item_append_text(parameter_item, " (%s)", mtp3_pc_to_str(tvb_get_ntoh24(parameter_tvb, CON_DEST_PC_OFFSET)));
}
static void
dissect_routing_key_parameter(tvbuff_t *parameter_tvb, packet_info *pinfo, proto_tree *tree, proto_tree *parameter_tree)
{
tvbuff_t *parameters_tvb;
guint16 length, parameters_length;
length = tvb_get_ntohs(parameter_tvb, PARAMETER_LENGTH_OFFSET);
parameters_length = length - PARAMETER_HEADER_LENGTH;
parameters_tvb = tvb_new_subset(parameter_tvb, PARAMETER_VALUE_OFFSET, parameters_length, parameters_length);
dissect_parameters(parameters_tvb, pinfo, tree, parameter_tree);
}
static void
dissect_v67_registration_result_parameter(tvbuff_t *parameter_tvb, proto_tree *parameter_tree)
{
proto_tree_add_item(parameter_tree, hf_registration_result_identifier, parameter_tvb, REG_RES_IDENTIFIER_OFFSET, REG_RES_IDENTIFIER_LENGTH, ENC_BIG_ENDIAN);
proto_tree_add_item(parameter_tree, hf_registration_result_status, parameter_tvb, REG_RES_STATUS_OFFSET, REG_RES_STATUS_LENGTH, ENC_BIG_ENDIAN);
proto_tree_add_item(parameter_tree, hf_registration_result_context, parameter_tvb, REG_RES_CONTEXT_OFFSET, REG_RES_CONTEXT_LENGTH, ENC_BIG_ENDIAN);
}
static void
dissect_registration_result_parameter(tvbuff_t *parameter_tvb, packet_info *pinfo, proto_tree *tree, proto_tree *parameter_tree)
{
tvbuff_t *parameters_tvb;
guint16 length, parameters_length;
length = tvb_get_ntohs(parameter_tvb, PARAMETER_LENGTH_OFFSET);
parameters_length = length - PARAMETER_HEADER_LENGTH;
parameters_tvb = tvb_new_subset(parameter_tvb, PARAMETER_VALUE_OFFSET, parameters_length, parameters_length);
dissect_parameters(parameters_tvb, pinfo, tree, parameter_tree);
}
static void
dissect_v67_deregistration_result_parameter(tvbuff_t *parameter_tvb, proto_tree *parameter_tree)
{
proto_tree_add_item(parameter_tree, hf_v6_deregistration_result_context, parameter_tvb, DEREG_RES_CONTEXT_OFFSET, DEREG_RES_CONTEXT_LENGTH, ENC_BIG_ENDIAN);
proto_tree_add_item(parameter_tree, hf_v6_deregistration_result_status, parameter_tvb, DEREG_RES_STATUS_OFFSET, DEREG_RES_STATUS_LENGTH, ENC_BIG_ENDIAN);
}
static void
dissect_deregistration_result_parameter(tvbuff_t *parameter_tvb, packet_info *pinfo, proto_tree *tree, proto_tree *parameter_tree)
{
tvbuff_t *parameters_tvb;
guint16 length, parameters_length;
length = tvb_get_ntohs(parameter_tvb, PARAMETER_LENGTH_OFFSET);
parameters_length = length - PARAMETER_HEADER_LENGTH;
parameters_tvb = tvb_new_subset(parameter_tvb, PARAMETER_VALUE_OFFSET, parameters_length, parameters_length);
dissect_parameters(parameters_tvb, pinfo, tree, parameter_tree);
}
static void
dissect_local_routing_key_identifier_parameter(tvbuff_t *parameter_tvb, proto_tree *parameter_tree, proto_item *parameter_item)
{
proto_tree_add_item(parameter_tree, hf_local_rk_identifier, parameter_tvb, LOCAL_RK_IDENTIFIER_OFFSET, LOCAL_RK_IDENTIFIER_LENGTH, ENC_BIG_ENDIAN);
proto_item_append_text(parameter_item, " (%u)", tvb_get_ntohl(parameter_tvb, LOCAL_RK_IDENTIFIER_OFFSET));
}
static void
dissect_destination_point_code_parameter(tvbuff_t *parameter_tvb, proto_tree *parameter_tree, proto_item *parameter_item)
{
proto_item *item;
proto_tree_add_item(parameter_tree, hf_dpc_mask, parameter_tvb, DPC_MASK_OFFSET, DPC_MASK_LENGTH, ENC_BIG_ENDIAN);
item = proto_tree_add_item(parameter_tree, hf_dpc_pc, parameter_tvb, DPC_PC_OFFSET, DPC_PC_LENGTH, ENC_BIG_ENDIAN);
if (mtp3_pc_structured())
proto_item_append_text(item, " (%s)", mtp3_pc_to_str(tvb_get_ntoh24(parameter_tvb, DPC_PC_OFFSET)));
proto_item_append_text(parameter_item, " (%s)", mtp3_pc_to_str(tvb_get_ntoh24(parameter_tvb, DPC_PC_OFFSET)));
}
static void
dissect_service_indicators_parameter(tvbuff_t *parameter_tvb, proto_tree *parameter_tree, proto_item *parameter_item)
{
guint16 length, number_of_sis, si_number;
gint si_offset;
length = tvb_get_ntohs(parameter_tvb, PARAMETER_LENGTH_OFFSET);
number_of_sis = length - PARAMETER_HEADER_LENGTH;
si_offset = PARAMETER_VALUE_OFFSET;
for(si_number=0; si_number < number_of_sis; si_number++) {
proto_tree_add_item(parameter_tree, hf_si, parameter_tvb, si_offset, SI_LENGTH, ENC_BIG_ENDIAN);
si_offset += SI_LENGTH;
};
proto_item_append_text(parameter_item, " (%u indicator%s)", number_of_sis, plurality(number_of_sis, "", "s"));
}
static void
dissect_subsystem_numbers_parameter(tvbuff_t *parameter_tvb, proto_tree *parameter_tree, proto_item *parameter_item)
{
guint16 length, number_of_ssns, ssn_number;
gint ssn_offset;
length = tvb_get_ntohs(parameter_tvb, PARAMETER_LENGTH_OFFSET);
number_of_ssns = length - PARAMETER_HEADER_LENGTH;
ssn_offset = PARAMETER_VALUE_OFFSET;
for(ssn_number=0; ssn_number < number_of_ssns; ssn_number++) {
proto_tree_add_item(parameter_tree, hf_ssn, parameter_tvb, ssn_offset, SSN_LENGTH, ENC_BIG_ENDIAN);
ssn_offset += SSN_LENGTH;
};
proto_item_append_text(parameter_item, " (%u number%s)", number_of_ssns, plurality(number_of_ssns, "", "s"));
}
static void
dissect_originating_point_code_list_parameter(tvbuff_t *parameter_tvb, proto_tree *parameter_tree, proto_item *parameter_item)
{
guint16 length, number_of_point_codes, point_code_number;
gint point_code_offset;
proto_item *item;
length = tvb_get_ntohs(parameter_tvb, PARAMETER_LENGTH_OFFSET);
number_of_point_codes = (length - PARAMETER_HEADER_LENGTH) / 4;
point_code_offset = PARAMETER_VALUE_OFFSET;
for(point_code_number=0; point_code_number < number_of_point_codes; point_code_number++) {
proto_tree_add_item(parameter_tree, hf_opc_list_mask, parameter_tvb, point_code_offset + OPC_MASK_OFFSET, OPC_MASK_LENGTH, ENC_BIG_ENDIAN);
item = proto_tree_add_item(parameter_tree, hf_opc_list_pc, parameter_tvb, point_code_offset + OPC_PC_OFFSET, OPC_PC_LENGTH, ENC_BIG_ENDIAN);
if (mtp3_pc_structured())
proto_item_append_text(item, " (%s)", mtp3_pc_to_str(tvb_get_ntoh24(parameter_tvb, point_code_offset + OPC_PC_OFFSET)));
point_code_offset += OPC_LENGTH;
};
proto_item_append_text(parameter_item, " (%u point code%s)", number_of_point_codes, plurality(number_of_point_codes, "", "s"));
}
static void
dissect_circuit_range_parameter(tvbuff_t *parameter_tvb, proto_tree *parameter_tree, proto_item *parameter_item)
{
guint16 length, number_of_point_codes, point_code_number, cic_low, cic_high;
guint32 pc;
gint point_code_offset;
proto_item *pc_item, *cic_range_item;
proto_tree *cic_range_tree;
gchar *pc_string;
length = tvb_get_ntohs(parameter_tvb, PARAMETER_LENGTH_OFFSET);
number_of_point_codes = (length - PARAMETER_HEADER_LENGTH) / CIC_RANGE_LENGTH;
point_code_offset = PARAMETER_VALUE_OFFSET;
for(point_code_number = 0; point_code_number < number_of_point_codes; point_code_number++) {
cic_range_item = proto_tree_add_text(parameter_tree, parameter_tvb, point_code_offset + CIC_RANGE_MASK_OFFSET, CIC_RANGE_LENGTH, "CIC range");
cic_range_tree = proto_item_add_subtree(cic_range_item, ett_parameter);
proto_tree_add_item(cic_range_tree, hf_cic_range_mask, parameter_tvb, point_code_offset + CIC_RANGE_MASK_OFFSET, CIC_RANGE_MASK_LENGTH, ENC_BIG_ENDIAN);
pc = tvb_get_ntoh24(parameter_tvb, point_code_offset + CIC_RANGE_PC_OFFSET);
pc_string = mtp3_pc_to_str(pc);
pc_item = proto_tree_add_item(cic_range_tree, hf_cic_range_pc, parameter_tvb, point_code_offset + CIC_RANGE_PC_OFFSET, CIC_RANGE_PC_LENGTH, ENC_BIG_ENDIAN);
if (mtp3_pc_structured())
proto_item_append_text(pc_item, " (%s)", pc_string);
cic_low = tvb_get_ntohs(parameter_tvb, point_code_offset + CIC_RANGE_LOWER_OFFSET);
proto_tree_add_item(cic_range_tree, hf_cic_range_lower, parameter_tvb, point_code_offset + CIC_RANGE_LOWER_OFFSET, CIC_RANGE_LOWER_LENGTH, ENC_BIG_ENDIAN);
cic_high = tvb_get_ntohs(parameter_tvb, point_code_offset + CIC_RANGE_UPPER_OFFSET);
proto_tree_add_item(cic_range_tree, hf_cic_range_upper, parameter_tvb, point_code_offset + CIC_RANGE_UPPER_OFFSET, CIC_RANGE_UPPER_LENGTH, ENC_BIG_ENDIAN);
proto_item_append_text(cic_range_item, " (%s: %d-%d)", pc_string, cic_low, cic_high);
point_code_offset += CIC_RANGE_LENGTH;
};
proto_item_append_text(parameter_item, " (%u range%s)", number_of_point_codes, plurality(number_of_point_codes, "", "s"));
}
static guint
m3ua_heur_mtp3_standard(tvbuff_t *tvb, packet_info *pinfo, guint32 opc, guint32 dpc, guint8 si)
{
switch (si) {
case MTP_SI_SCCP:
{
if (opc < ITU_PC_MASK && dpc < ITU_PC_MASK &&
looks_like_valid_sccp(PINFO_FD_NUM(pinfo), tvb, ITU_STANDARD)) {
return ITU_STANDARD;
}
if ((opc & ANSI_NETWORK_MASK) > 0 && (dpc & ANSI_NETWORK_MASK) > 0 &&
looks_like_valid_sccp(PINFO_FD_NUM(pinfo), tvb, ANSI_STANDARD)) {
return ANSI_STANDARD;
}
if (looks_like_valid_sccp(PINFO_FD_NUM(pinfo), tvb, CHINESE_ITU_STANDARD)) {
return CHINESE_ITU_STANDARD;
}
if (opc < JAPAN_PC_MASK && dpc < JAPAN_PC_MASK &&
looks_like_valid_sccp(PINFO_FD_NUM(pinfo), tvb, JAPAN_STANDARD)) {
return JAPAN_STANDARD;
}
return HEURISTIC_FAILED_STANDARD;
}
default:
return HEURISTIC_FAILED_STANDARD;
}
}
static void
m3ua_reset_mtp3_standard(void)
{
mtp3_standard = m3ua_pref_mtp3_standard;
}
static void
dissect_protocol_data_parameter(tvbuff_t *parameter_tvb, packet_info *pinfo, proto_tree *tree, proto_tree *parameter_tree, proto_item *parameter_item)
{
guint16 ulp_length;
tvbuff_t *payload_tvb;
proto_item *item, *gen_item;
mtp3_tap_rec_t* mtp3_tap;
proto_tree *q708_tree;
gint heuristic_standard;
guint8 si;
guint32 opc, dpc;
mtp3_tap = wmem_new0(pinfo->pool, mtp3_tap_rec_t);
si = tvb_get_guint8(parameter_tvb, DATA_SI_OFFSET);
ulp_length = tvb_get_ntohs(parameter_tvb, PARAMETER_LENGTH_OFFSET) - PARAMETER_HEADER_LENGTH - DATA_HDR_LENGTH;
payload_tvb = tvb_new_subset(parameter_tvb, DATA_ULP_OFFSET, ulp_length, ulp_length);
dpc = tvb_get_ntohl(parameter_tvb, DATA_DPC_OFFSET);
opc = tvb_get_ntohl(parameter_tvb, DATA_OPC_OFFSET);
m3ua_pref_mtp3_standard = mtp3_standard;
if (mtp3_heuristic_standard) {
heuristic_standard = m3ua_heur_mtp3_standard(payload_tvb, pinfo, opc, dpc, si);
if (heuristic_standard == HEURISTIC_FAILED_STANDARD) {
gen_item = proto_tree_add_text(tree, parameter_tvb, 0, 0, "Could not determine Heuristic using %s", val_to_str_const(mtp3_standard, mtp3_standard_vals, "unknown"));
} else {
gen_item = proto_tree_add_text(tree, parameter_tvb, 0, 0, "%s", val_to_str_const(heuristic_standard, mtp3_standard_vals, "unknown"));
mtp3_standard = heuristic_standard;
register_frame_end_routine(pinfo, m3ua_reset_mtp3_standard);
}
PROTO_ITEM_SET_GENERATED(gen_item);
}
mtp3_tap->addr_dpc.type = (Standard_Type)mtp3_standard;
mtp3_tap->addr_dpc.pc = dpc;
mtp3_tap->addr_dpc.ni = tvb_get_guint8(parameter_tvb, DATA_NI_OFFSET);
SET_ADDRESS(&pinfo->dst, AT_SS7PC, sizeof(mtp3_addr_pc_t), (guint8 *) &mtp3_tap->addr_dpc);
mtp3_tap->addr_opc.type = (Standard_Type)mtp3_standard;
mtp3_tap->addr_opc.pc = opc;
mtp3_tap->addr_opc.ni = tvb_get_guint8(parameter_tvb, DATA_NI_OFFSET);
SET_ADDRESS(&pinfo->src, AT_SS7PC, sizeof(mtp3_addr_pc_t), (guint8 *) &mtp3_tap->addr_opc);
mtp3_tap->si_code = tvb_get_guint8(parameter_tvb, DATA_SI_OFFSET);
mtp3_tap->size = 0;
tap_queue_packet(m3ua_tap, pinfo, mtp3_tap);
ulp_length = tvb_get_ntohs(parameter_tvb, PARAMETER_LENGTH_OFFSET) - PARAMETER_HEADER_LENGTH - DATA_HDR_LENGTH;
if (parameter_tree) {
item = proto_tree_add_item(parameter_tree, hf_protocol_data_opc, parameter_tvb, DATA_OPC_OFFSET, DATA_OPC_LENGTH, ENC_BIG_ENDIAN);
if (mtp3_pc_structured())
proto_item_append_text(item, " (%s)", mtp3_pc_to_str(opc));
if(mtp3_tap->addr_opc.ni == MTP3_NI_INT0) {
q708_tree = proto_item_add_subtree(item,ett_q708_opc);
analyze_q708_ispc(parameter_tvb, q708_tree, DATA_OPC_OFFSET, DATA_OPC_LENGTH, opc);
}
item = proto_tree_add_item(parameter_tree, hf_protocol_data_dpc, parameter_tvb, DATA_DPC_OFFSET, DATA_DPC_LENGTH, ENC_BIG_ENDIAN);
if (mtp3_pc_structured())
proto_item_append_text(item, " (%s)", mtp3_pc_to_str(dpc));
if(mtp3_tap->addr_dpc.ni == MTP3_NI_INT0) {
q708_tree = proto_item_add_subtree(item,ett_q708_dpc);
analyze_q708_ispc(parameter_tvb, q708_tree, DATA_DPC_OFFSET, DATA_DPC_LENGTH, dpc);
}
proto_tree_add_item(parameter_tree, hf_protocol_data_si, parameter_tvb, DATA_SI_OFFSET, DATA_SI_LENGTH, ENC_BIG_ENDIAN);
proto_tree_add_item(parameter_tree, hf_protocol_data_ni, parameter_tvb, DATA_NI_OFFSET, DATA_NI_LENGTH, ENC_BIG_ENDIAN);
proto_tree_add_item(parameter_tree, hf_protocol_data_mp, parameter_tvb, DATA_MP_OFFSET, DATA_MP_LENGTH, ENC_BIG_ENDIAN);
proto_tree_add_item(parameter_tree, hf_protocol_data_sls, parameter_tvb, DATA_SLS_OFFSET, DATA_SLS_LENGTH, ENC_BIG_ENDIAN);
proto_item_append_text(parameter_item, " (SS7 message of %u byte%s)", ulp_length, plurality(ulp_length, "", "s"));
proto_item_set_len(parameter_item, PARAMETER_HEADER_LENGTH + DATA_HDR_LENGTH);
item = proto_tree_add_text(parameter_tree,parameter_tvb,0,0,"MTP3 equivalents");
PROTO_ITEM_SET_GENERATED(item);
parameter_tree = proto_item_add_subtree(item,ett_mtp3_equiv);
item = proto_tree_add_item(parameter_tree, hf_protocol_data_mtp3_opc, parameter_tvb, DATA_OPC_OFFSET, DATA_OPC_LENGTH, ENC_BIG_ENDIAN);
PROTO_ITEM_SET_GENERATED(item);
item = proto_tree_add_item(parameter_tree, hf_protocol_data_mtp3_dpc, parameter_tvb, DATA_DPC_OFFSET, DATA_OPC_LENGTH, ENC_BIG_ENDIAN);
PROTO_ITEM_SET_GENERATED(item);
item = proto_tree_add_item(parameter_tree, hf_protocol_data_mtp3_pc, parameter_tvb, DATA_OPC_OFFSET, DATA_OPC_LENGTH, ENC_BIG_ENDIAN);
PROTO_ITEM_SET_GENERATED(item);
item = proto_tree_add_item(parameter_tree, hf_protocol_data_mtp3_pc, parameter_tvb, DATA_DPC_OFFSET, DATA_OPC_LENGTH, ENC_BIG_ENDIAN);
PROTO_ITEM_SET_GENERATED(item);
item = proto_tree_add_item(parameter_tree, hf_protocol_data_mtp3_ni, parameter_tvb, DATA_NI_OFFSET, DATA_NI_LENGTH, ENC_BIG_ENDIAN);
PROTO_ITEM_SET_GENERATED(item);
item = proto_tree_add_item(parameter_tree, hf_protocol_data_mtp3_sls, parameter_tvb, DATA_SLS_OFFSET, DATA_SLS_LENGTH, ENC_BIG_ENDIAN);
PROTO_ITEM_SET_GENERATED(item);
}
payload_tvb = tvb_new_subset(parameter_tvb, DATA_ULP_OFFSET, ulp_length, ulp_length);
if (!dissector_try_uint(si_dissector_table, tvb_get_guint8(parameter_tvb, DATA_SI_OFFSET), payload_tvb, pinfo, tree))
call_dissector(data_handle, payload_tvb, pinfo, tree);
mtp3_standard = m3ua_pref_mtp3_standard;
}
static void
dissect_correlation_identifier_parameter(tvbuff_t *parameter_tvb, proto_tree *parameter_tree, proto_item *parameter_item)
{
proto_tree_add_item(parameter_tree, hf_correlation_identifier, parameter_tvb, CORR_ID_OFFSET, CORR_ID_LENGTH, ENC_BIG_ENDIAN);
proto_item_append_text(parameter_item, " (%u)", tvb_get_ntohl(parameter_tvb, CORR_ID_OFFSET));
}
static void
dissect_registration_status_parameter(tvbuff_t *parameter_tvb, proto_tree *parameter_tree, proto_item *parameter_item)
{
proto_tree_add_item(parameter_tree, hf_registration_status, parameter_tvb, REG_STATUS_OFFSET, REG_STATUS_LENGTH, ENC_BIG_ENDIAN);
proto_item_append_text(parameter_item, " (%s)", val_to_str_const(tvb_get_ntohl(parameter_tvb, REG_STATUS_OFFSET), registration_status_values, "unknown"));
}
static void
dissect_deregistration_status_parameter(tvbuff_t *parameter_tvb, proto_tree *parameter_tree, proto_item *parameter_item)
{
proto_tree_add_item(parameter_tree, hf_deregistration_status, parameter_tvb, DEREG_STATUS_OFFSET, DEREG_STATUS_LENGTH, ENC_BIG_ENDIAN);
proto_item_append_text(parameter_item, " (%s)", val_to_str_const(tvb_get_ntohl(parameter_tvb, DEREG_STATUS_OFFSET), deregistration_status_values, "unknown"));
}
static void
dissect_registration_results_parameter(tvbuff_t *parameter_tvb, packet_info *pinfo, proto_tree *tree, proto_tree *parameter_tree)
{
tvbuff_t *parameters_tvb;
guint16 parameters_length;
parameters_length = tvb_get_ntohs(parameter_tvb, PARAMETER_LENGTH_OFFSET) - PARAMETER_HEADER_LENGTH;
parameters_tvb = tvb_new_subset(parameter_tvb, PARAMETER_VALUE_OFFSET, parameters_length, parameters_length);
dissect_parameters(parameters_tvb, pinfo, tree, parameter_tree);
}
static void
dissect_deregistration_results_parameter(tvbuff_t *parameter_tvb, packet_info *pinfo, proto_tree *tree, proto_tree *parameter_tree)
{
tvbuff_t *parameters_tvb;
guint16 parameters_length;
parameters_length = tvb_get_ntohs(parameter_tvb, PARAMETER_LENGTH_OFFSET) - PARAMETER_HEADER_LENGTH;
parameters_tvb = tvb_new_subset(parameter_tvb, PARAMETER_VALUE_OFFSET, parameters_length, parameters_length);
dissect_parameters(parameters_tvb, pinfo, tree, parameter_tree);
}
static void
dissect_unknown_parameter(tvbuff_t *parameter_tvb, proto_tree *parameter_tree, proto_item *parameter_item)
{
guint16 tag, parameter_value_length;
tag = tvb_get_ntohs(parameter_tvb, PARAMETER_TAG_OFFSET);
parameter_value_length = tvb_get_ntohs(parameter_tvb, PARAMETER_LENGTH_OFFSET) - PARAMETER_HEADER_LENGTH;
proto_tree_add_item(parameter_tree, hf_parameter_value, parameter_tvb, PARAMETER_VALUE_OFFSET, parameter_value_length, ENC_NA);
proto_item_append_text(parameter_item, " (tag %u and %u byte%s value)", tag, parameter_value_length, plurality(parameter_value_length, "", "s"));
}
static void
dissect_v5_parameter(tvbuff_t *parameter_tvb, packet_info *pinfo, proto_tree *tree, proto_tree *m3ua_tree)
{
guint16 tag, length, padding_length;
proto_item *parameter_item;
proto_tree *parameter_tree;
tag = tvb_get_ntohs(parameter_tvb, PARAMETER_TAG_OFFSET);
length = tvb_get_ntohs(parameter_tvb, PARAMETER_LENGTH_OFFSET);
padding_length = tvb_length(parameter_tvb) - length;
if (!tree && tag != V5_PROTOCOL_DATA_PARAMETER_TAG)
return;
parameter_item = proto_tree_add_text(m3ua_tree, parameter_tvb, PARAMETER_HEADER_OFFSET, tvb_length(parameter_tvb), "%s", val_to_str_const(tag, v5_parameter_tag_values, "Unknown parameter"));
parameter_tree = proto_item_add_subtree(parameter_item, ett_parameter);
proto_tree_add_item(parameter_tree, hf_v5_parameter_tag, parameter_tvb, PARAMETER_TAG_OFFSET, PARAMETER_TAG_LENGTH, ENC_BIG_ENDIAN);
proto_tree_add_item(parameter_tree, hf_parameter_length, parameter_tvb, PARAMETER_LENGTH_OFFSET, PARAMETER_LENGTH_LENGTH, ENC_BIG_ENDIAN);
switch(tag) {
case V5_NETWORK_APPEARANCE_PARAMETER_TAG:
dissect_network_appearance_parameter(parameter_tvb, parameter_tree, parameter_item);
break;
case V5_PROTOCOL_DATA_PARAMETER_TAG:
dissect_v5_protocol_data_parameter(parameter_tvb, pinfo, tree, parameter_item);
break;
case V5_INFO_PARAMETER_TAG:
dissect_info_string_parameter(parameter_tvb, parameter_tree, parameter_item);
break;
case V5_AFFECTED_DESTINATIONS_PARAMETER_TAG:
dissect_affected_destinations_parameter(parameter_tvb, parameter_tree, parameter_item);
break;
case V5_ROUTING_CONTEXT_PARAMETER_TAG:
dissect_routing_context_parameter(parameter_tvb, parameter_tree, parameter_item);
break;
case V5_DIAGNOSTIC_INFORMATION_PARAMETER_TAG:
dissect_diagnostic_information_parameter(parameter_tvb, parameter_tree, parameter_item);
break;
case V5_HEARTBEAT_DATA_PARAMETER_TAG:
dissect_heartbeat_data_parameter(parameter_tvb, parameter_tree, parameter_item);
break;
case V5_USER_CAUSE_PARAMETER_TAG:
dissect_user_cause_parameter(parameter_tvb, parameter_tree, parameter_item);
break;
case V5_REASON_PARAMETER_TAG:
dissect_reason_parameter(parameter_tvb, parameter_tree, parameter_item);
break;
case V5_TRAFFIC_MODE_TYPE_PARAMETER_TAG:
dissect_v5_traffic_mode_type_parameter(parameter_tvb, parameter_tree, parameter_item);
break;
case V5_ERROR_CODE_PARAMETER_TAG:
dissect_v5_error_code_parameter(parameter_tvb, parameter_tree, parameter_item);
break;
case V5_STATUS_PARAMETER_TAG:
dissect_v567_status_parameter(parameter_tvb, parameter_tree, parameter_item);
break;
case V5_CONGESTION_INDICATION_PARAMETER_TAG:
dissect_congestion_indication_parameter(parameter_tvb, parameter_tree, parameter_item);
break;
default:
dissect_unknown_parameter(parameter_tvb, parameter_tree, parameter_item);
break;
};
if (padding_length > 0)
proto_tree_add_item(parameter_tree, hf_parameter_padding, parameter_tvb, PARAMETER_HEADER_OFFSET + length, padding_length, ENC_NA);
}
static void
dissect_v6_parameter(tvbuff_t *parameter_tvb, packet_info *pinfo, proto_tree *tree, proto_tree *m3ua_tree)
{
guint16 tag, length, padding_length;
proto_item *parameter_item;
proto_tree *parameter_tree;
tag = tvb_get_ntohs(parameter_tvb, PARAMETER_TAG_OFFSET);
length = tvb_get_ntohs(parameter_tvb, PARAMETER_LENGTH_OFFSET);
padding_length = tvb_length(parameter_tvb) - length;
if (!tree && tag != V6_PROTOCOL_DATA_1_PARAMETER_TAG && tag != V6_PROTOCOL_DATA_2_PARAMETER_TAG)
return;
parameter_item = proto_tree_add_text(m3ua_tree, parameter_tvb, PARAMETER_HEADER_OFFSET, tvb_length(parameter_tvb), "%s", val_to_str_const(tag, v6_parameter_tag_values, "Unknown parameter"));
parameter_tree = proto_item_add_subtree(parameter_item, ett_parameter);
proto_tree_add_item(parameter_tree, hf_v6_parameter_tag, parameter_tvb, PARAMETER_TAG_OFFSET, PARAMETER_TAG_LENGTH, ENC_BIG_ENDIAN);
proto_tree_add_item(parameter_tree, hf_parameter_length, parameter_tvb, PARAMETER_LENGTH_OFFSET, PARAMETER_LENGTH_LENGTH, ENC_BIG_ENDIAN);
switch(tag) {
case V6_NETWORK_APPEARANCE_PARAMETER_TAG:
dissect_network_appearance_parameter(parameter_tvb, parameter_tree, parameter_item);
break;
case V6_PROTOCOL_DATA_1_PARAMETER_TAG:
dissect_protocol_data_1_parameter(parameter_tvb, pinfo, tree, parameter_item);
break;
case V6_PROTOCOL_DATA_2_PARAMETER_TAG:
dissect_protocol_data_2_parameter(parameter_tvb, pinfo, tree, parameter_tree, parameter_item);
break;
case V6_INFO_PARAMETER_TAG:
dissect_info_string_parameter(parameter_tvb, parameter_tree, parameter_item);
break;
case V6_AFFECTED_DESTINATIONS_PARAMETER_TAG:
dissect_affected_destinations_parameter(parameter_tvb, parameter_tree, parameter_item);
break;
case V6_ROUTING_CONTEXT_PARAMETER_TAG:
dissect_routing_context_parameter(parameter_tvb, parameter_tree, parameter_item);
break;
case V6_DIAGNOSTIC_INFORMATION_PARAMETER_TAG:
dissect_diagnostic_information_parameter(parameter_tvb, parameter_tree, parameter_item);
break;
case V6_HEARTBEAT_DATA_PARAMETER_TAG:
dissect_heartbeat_data_parameter(parameter_tvb, parameter_tree, parameter_item);
break;
case V6_USER_CAUSE_PARAMETER_TAG:
dissect_user_cause_parameter(parameter_tvb, parameter_tree, parameter_item);
break;
case V6_REASON_PARAMETER_TAG:
dissect_reason_parameter(parameter_tvb, parameter_tree, parameter_item);
break;
case V6_TRAFFIC_MODE_TYPE_PARAMETER_TAG:
dissect_v6_traffic_mode_type_parameter(parameter_tvb, parameter_tree, parameter_item);
break;
case V6_ERROR_CODE_PARAMETER_TAG:
dissect_v6_error_code_parameter(parameter_tvb, parameter_tree, parameter_item);
break;
case V6_STATUS_PARAMETER_TAG:
dissect_v567_status_parameter(parameter_tvb, parameter_tree, parameter_item);
break;
case V6_CONGESTION_INDICATION_PARAMETER_TAG:
dissect_congestion_indication_parameter(parameter_tvb, parameter_tree, parameter_item);
break;
case V6_CONCERNED_DESTINATION_PARAMETER_TAG:
dissect_concerned_destination_parameter(parameter_tvb, parameter_tree, parameter_item);
break;
case V6_ROUTING_KEY_PARAMETER_TAG:
dissect_routing_key_parameter(parameter_tvb, pinfo, tree, parameter_tree);
break;
case V6_REGISTRATION_RESULT_PARAMETER_TAG:
dissect_v67_registration_result_parameter(parameter_tvb, parameter_tree);
break;
case V6_DEREGISTRATION_RESULT_PARAMETER_TAG:
dissect_v67_deregistration_result_parameter(parameter_tvb, parameter_tree);
break;
case V6_LOCAL_ROUTING_KEY_IDENTIFIER_PARAMETER_TAG:
dissect_local_routing_key_identifier_parameter(parameter_tvb, parameter_tree, parameter_item);
break;
case V6_DESTINATION_POINT_CODE_PARAMETER_TAG:
dissect_destination_point_code_parameter(parameter_tvb, parameter_tree, parameter_item);
break;
case V6_SERVICE_INDICATORS_PARAMETER_TAG:
dissect_service_indicators_parameter(parameter_tvb, parameter_tree, parameter_item);
break;
case V6_SUBSYSTEM_NUMBERS_PARAMETER_TAG:
dissect_subsystem_numbers_parameter(parameter_tvb, parameter_tree, parameter_item);
break;
case V6_ORIGINATING_POINT_CODE_LIST_PARAMETER_TAG:
dissect_originating_point_code_list_parameter(parameter_tvb, parameter_tree, parameter_item);
break;
case V6_CIRCUIT_RANGE_PARAMETER_TAG:
dissect_circuit_range_parameter(parameter_tvb, parameter_tree, parameter_item);
break;
case V6_REGISTRATION_RESULTS_PARAMETER_TAG:
dissect_registration_results_parameter(parameter_tvb, pinfo, tree, parameter_tree);
break;
case V6_DEREGISTRATION_RESULTS_PARAMETER_TAG:
dissect_deregistration_results_parameter(parameter_tvb, pinfo, tree, parameter_tree);
break;
default:
dissect_unknown_parameter(parameter_tvb, parameter_tree, parameter_item);
break;
};
if (padding_length > 0)
proto_tree_add_item(parameter_tree, hf_parameter_padding, parameter_tvb, PARAMETER_HEADER_OFFSET + length, padding_length, ENC_NA);
}
static void
dissect_v7_parameter(tvbuff_t *parameter_tvb, packet_info *pinfo, proto_tree *tree, proto_tree *m3ua_tree)
{
guint16 tag, length, padding_length;
proto_item *parameter_item;
proto_tree *parameter_tree;
tag = tvb_get_ntohs(parameter_tvb, PARAMETER_TAG_OFFSET);
length = tvb_get_ntohs(parameter_tvb, PARAMETER_LENGTH_OFFSET);
padding_length = tvb_length(parameter_tvb) - length;
if (!tree && tag != V7_PROTOCOL_DATA_1_PARAMETER_TAG && tag != V7_PROTOCOL_DATA_2_PARAMETER_TAG)
return;
parameter_item = proto_tree_add_text(m3ua_tree, parameter_tvb, PARAMETER_HEADER_OFFSET, tvb_length(parameter_tvb), "%s", val_to_str_const(tag, v7_parameter_tag_values, "Unknown parameter"));
parameter_tree = proto_item_add_subtree(parameter_item, ett_parameter);
proto_tree_add_item(parameter_tree, hf_v7_parameter_tag, parameter_tvb, PARAMETER_TAG_OFFSET, PARAMETER_TAG_LENGTH, ENC_BIG_ENDIAN);
proto_tree_add_item(parameter_tree, hf_parameter_length, parameter_tvb, PARAMETER_LENGTH_OFFSET, PARAMETER_LENGTH_LENGTH, ENC_BIG_ENDIAN);
switch(tag) {
case V7_NETWORK_APPEARANCE_PARAMETER_TAG:
dissect_network_appearance_parameter(parameter_tvb, parameter_tree, parameter_item);
break;
case V7_PROTOCOL_DATA_1_PARAMETER_TAG:
dissect_protocol_data_1_parameter(parameter_tvb, pinfo, tree, parameter_item);
break;
case V7_PROTOCOL_DATA_2_PARAMETER_TAG:
dissect_protocol_data_2_parameter(parameter_tvb, pinfo, tree, parameter_tree, parameter_item);
break;
case V7_INFO_PARAMETER_TAG:
dissect_info_string_parameter(parameter_tvb, parameter_tree, parameter_item);
break;
case V7_AFFECTED_DESTINATIONS_PARAMETER_TAG:
dissect_affected_destinations_parameter(parameter_tvb, parameter_tree, parameter_item);
break;
case V7_ROUTING_CONTEXT_PARAMETER_TAG:
dissect_routing_context_parameter(parameter_tvb, parameter_tree, parameter_item);
break;
case V7_DIAGNOSTIC_INFORMATION_PARAMETER_TAG:
dissect_diagnostic_information_parameter(parameter_tvb, parameter_tree, parameter_item);
break;
case V7_HEARTBEAT_DATA_PARAMETER_TAG:
dissect_heartbeat_data_parameter(parameter_tvb, parameter_tree, parameter_item);
break;
case V7_USER_CAUSE_PARAMETER_TAG:
dissect_user_cause_parameter(parameter_tvb, parameter_tree, parameter_item);
break;
case V7_REASON_PARAMETER_TAG:
dissect_reason_parameter(parameter_tvb, parameter_tree, parameter_item);
break;
case V7_TRAFFIC_MODE_TYPE_PARAMETER_TAG:
dissect_v7_traffic_mode_type_parameter(parameter_tvb, parameter_tree, parameter_item);
break;
case V7_ERROR_CODE_PARAMETER_TAG:
dissect_v7_error_code_parameter(parameter_tvb, parameter_tree, parameter_item);
break;
case V7_STATUS_PARAMETER_TAG:
dissect_v567_status_parameter(parameter_tvb, parameter_tree, parameter_item);
break;
case V7_CONGESTION_INDICATION_PARAMETER_TAG:
dissect_congestion_indication_parameter(parameter_tvb, parameter_tree, parameter_item);
break;
case V7_CONCERNED_DESTINATION_PARAMETER_TAG:
dissect_concerned_destination_parameter(parameter_tvb, parameter_tree, parameter_item);
break;
case V7_ROUTING_KEY_PARAMETER_TAG:
dissect_routing_key_parameter(parameter_tvb, pinfo, tree, parameter_tree);
break;
case V7_REGISTRATION_RESULT_PARAMETER_TAG:
dissect_v67_registration_result_parameter(parameter_tvb, parameter_tree);
break;
case V7_DEREGISTRATION_RESULT_PARAMETER_TAG:
dissect_v67_deregistration_result_parameter(parameter_tvb, parameter_tree);
break;
case V7_LOCAL_ROUTING_KEY_IDENTIFIER_PARAMETER_TAG:
dissect_local_routing_key_identifier_parameter(parameter_tvb, parameter_tree, parameter_item);
break;
case V7_DESTINATION_POINT_CODE_PARAMETER_TAG:
dissect_destination_point_code_parameter(parameter_tvb, parameter_tree, parameter_item);
break;
case V7_SERVICE_INDICATORS_PARAMETER_TAG:
dissect_service_indicators_parameter(parameter_tvb, parameter_tree, parameter_item);
break;
case V7_SUBSYSTEM_NUMBERS_PARAMETER_TAG:
dissect_subsystem_numbers_parameter(parameter_tvb, parameter_tree, parameter_item);
break;
case V7_ORIGINATING_POINT_CODE_LIST_PARAMETER_TAG:
dissect_originating_point_code_list_parameter(parameter_tvb, parameter_tree, parameter_item);
break;
case V7_CIRCUIT_RANGE_PARAMETER_TAG:
dissect_circuit_range_parameter(parameter_tvb, parameter_tree, parameter_item);
break;
case V7_REGISTRATION_RESULTS_PARAMETER_TAG:
dissect_registration_results_parameter(parameter_tvb, pinfo, tree, parameter_tree);
break;
case V7_DEREGISTRATION_RESULTS_PARAMETER_TAG:
dissect_deregistration_results_parameter(parameter_tvb, pinfo, tree, parameter_tree);
break;
default:
dissect_unknown_parameter(parameter_tvb, parameter_tree, parameter_item);
break;
};
if (padding_length > 0)
proto_tree_add_item(parameter_tree, hf_parameter_padding, parameter_tvb, PARAMETER_HEADER_OFFSET + length, padding_length, ENC_NA);
}
static void
dissect_parameter(tvbuff_t *parameter_tvb, packet_info *pinfo, proto_tree *tree, proto_tree *m3ua_tree)
{
guint16 tag, length, padding_length;
proto_item *parameter_item;
proto_tree *parameter_tree;
tag = tvb_get_ntohs(parameter_tvb, PARAMETER_TAG_OFFSET);
length = tvb_get_ntohs(parameter_tvb, PARAMETER_LENGTH_OFFSET);
padding_length = tvb_length(parameter_tvb) - length;
if (!tree && tag != PROTOCOL_DATA_PARAMETER_TAG)
return;
parameter_item = proto_tree_add_text(m3ua_tree, parameter_tvb, PARAMETER_HEADER_OFFSET, tvb_length(parameter_tvb), "%s", val_to_str_const(tag, parameter_tag_values, "Unknown parameter"));
parameter_tree = proto_item_add_subtree(parameter_item, ett_parameter);
proto_tree_add_item(parameter_tree, hf_parameter_tag, parameter_tvb, PARAMETER_TAG_OFFSET, PARAMETER_TAG_LENGTH, ENC_BIG_ENDIAN);
proto_tree_add_item(parameter_tree, hf_parameter_length, parameter_tvb, PARAMETER_LENGTH_OFFSET, PARAMETER_LENGTH_LENGTH, ENC_BIG_ENDIAN);
switch(tag) {
case INFO_STRING_PARAMETER_TAG:
dissect_info_string_parameter(parameter_tvb, parameter_tree, parameter_item);
break;
case ROUTING_CONTEXT_PARAMETER_TAG:
dissect_routing_context_parameter(parameter_tvb, parameter_tree, parameter_item);
break;
case DIAGNOSTIC_INFORMATION_PARAMETER_TAG:
dissect_diagnostic_information_parameter(parameter_tvb, parameter_tree, parameter_item);
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
case AFFECTED_POINT_CODE_PARAMETER_TAG:
dissect_affected_destinations_parameter(parameter_tvb, parameter_tree, parameter_item);
break;
case NETWORK_APPEARANCE_PARAMETER_TAG:
dissect_network_appearance_parameter(parameter_tvb, parameter_tree, parameter_item);
break;
case USER_CAUSE_PARAMETER_TAG:
dissect_user_cause_parameter(parameter_tvb, parameter_tree, parameter_item);
break;
case CONGESTION_INDICATIONS_PARAMETER_TAG:
dissect_congestion_indication_parameter(parameter_tvb, parameter_tree, parameter_item);
break;
case CONCERNED_DESTINATION_PARAMETER_TAG:
dissect_concerned_destination_parameter(parameter_tvb, parameter_tree, parameter_item);
break;
case ROUTING_KEY_PARAMETER_TAG:
dissect_routing_key_parameter(parameter_tvb, pinfo, tree, parameter_tree);
break;
case REGISTRATION_RESULT_PARAMETER_TAG:
dissect_registration_result_parameter(parameter_tvb, pinfo, tree, parameter_tree);
break;
case DEREGISTRATION_RESULT_PARAMETER_TAG:
dissect_deregistration_result_parameter(parameter_tvb, pinfo, tree, parameter_tree);
break;
case LOCAL_ROUTING_KEY_IDENTIFIER_PARAMETER_TAG:
dissect_local_routing_key_identifier_parameter(parameter_tvb, parameter_tree, parameter_item);
break;
case DESTINATION_POINT_CODE_PARAMETER_TAG:
dissect_destination_point_code_parameter(parameter_tvb, parameter_tree, parameter_item);
break;
case SERVICE_INDICATORS_PARAMETER_TAG:
dissect_service_indicators_parameter(parameter_tvb, parameter_tree, parameter_item);
break;
case ORIGINATING_POINT_CODE_LIST_PARAMETER_TAG:
dissect_originating_point_code_list_parameter(parameter_tvb, parameter_tree, parameter_item);
break;
case CIRCUIT_RANGE_PARAMETER_TAG:
dissect_circuit_range_parameter(parameter_tvb, parameter_tree, parameter_item);
break;
case PROTOCOL_DATA_PARAMETER_TAG:
dissect_protocol_data_parameter(parameter_tvb, pinfo, tree, parameter_tree, parameter_item);
break;
case CORRELATION_IDENTIFIER_PARAMETER_TAG:
dissect_correlation_identifier_parameter(parameter_tvb, parameter_tree, parameter_item);
break;
case REGISTRATION_STATUS_PARAMETER_TAG:
dissect_registration_status_parameter(parameter_tvb, parameter_tree, parameter_item);
break;
case DEREGISTRATION_STATUS_PARAMETER_TAG:
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
dissect_parameters(tvbuff_t *parameters_tvb, packet_info *pinfo, proto_tree *tree, proto_tree *m3ua_tree)
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
switch(version) {
case M3UA_V5:
dissect_v5_parameter(parameter_tvb, pinfo, tree, m3ua_tree);
break;
case M3UA_V6:
dissect_v6_parameter(parameter_tvb, pinfo, tree, m3ua_tree);
break;
case M3UA_V7:
dissect_v7_parameter(parameter_tvb, pinfo, tree, m3ua_tree);
break;
case M3UA_RFC:
dissect_parameter(parameter_tvb, pinfo, tree, m3ua_tree);
break;
}
offset += total_length;
}
}
static void
dissect_message(tvbuff_t *message_tvb, packet_info *pinfo, proto_tree *tree, proto_tree *m3ua_tree)
{
tvbuff_t *common_header_tvb, *parameters_tvb;
common_header_tvb = tvb_new_subset(message_tvb, 0, COMMON_HEADER_LENGTH, COMMON_HEADER_LENGTH);
parameters_tvb = tvb_new_subset_remaining(message_tvb, COMMON_HEADER_LENGTH);
if (version == M3UA_V5)
dissect_v5_common_header(common_header_tvb, pinfo, m3ua_tree);
else
dissect_common_header(common_header_tvb, pinfo, m3ua_tree);
dissect_parameters(parameters_tvb, pinfo, tree, m3ua_tree);
}
static void
dissect_m3ua(tvbuff_t *message_tvb, packet_info *pinfo, proto_tree *tree)
{
proto_item *m3ua_item;
proto_tree *m3ua_tree;
switch(version) {
case M3UA_V5:
col_set_str(pinfo->cinfo, COL_PROTOCOL, "M3UA (ID 05)");
break;
case M3UA_V6:
col_set_str(pinfo->cinfo, COL_PROTOCOL, "M3UA (ID 06)");
break;
case M3UA_V7:
col_set_str(pinfo->cinfo, COL_PROTOCOL, "M3UA (ID 07)");
break;
case M3UA_RFC:
col_set_str(pinfo->cinfo, COL_PROTOCOL, "M3UA (RFC 4666)");
break;
};
m3ua_item = proto_tree_add_item(tree, proto_m3ua, message_tvb, 0, -1, ENC_NA);
m3ua_tree = proto_item_add_subtree(m3ua_item, ett_m3ua);
dissect_message(message_tvb, pinfo, tree, m3ua_tree);
}
void
proto_register_m3ua(void)
{
static hf_register_info hf[] = {
{ &hf_version, { "Version", "m3ua.version", FT_UINT8, BASE_DEC, VALS(protocol_version_values), 0x0, NULL, HFILL } },
{ &hf_reserved, { "Reserved", "m3ua.reserved", FT_UINT8, BASE_HEX, NULL, 0x0, NULL, HFILL } },
{ &hf_v5_message_class, { "Message class", "m3ua.message_class", FT_UINT8, BASE_DEC, VALS(v5_message_class_values), 0x0, NULL, HFILL } },
{ &hf_message_class, { "Message class", "m3ua.message_class", FT_UINT8, BASE_DEC, VALS(message_class_values), 0x0, NULL, HFILL } },
{ &hf_message_type, { "Message Type", "m3ua.message_type", FT_UINT8, BASE_DEC, NULL, 0x0, NULL, HFILL } },
{ &hf_message_length, { "Message length", "m3ua.message_length", FT_UINT32, BASE_DEC, NULL, 0x0, NULL, HFILL } },
{ &hf_v5_parameter_tag, { "Parameter Tag", "m3ua.parameter_tag", FT_UINT16, BASE_DEC, VALS(v5_parameter_tag_values), 0x0, NULL, HFILL } },
{ &hf_v6_parameter_tag, { "Parameter Tag", "m3ua.parameter_tag", FT_UINT16, BASE_DEC, VALS(v6_parameter_tag_values), 0x0, NULL, HFILL } },
{ &hf_v7_parameter_tag, { "Parameter Tag", "m3ua.parameter_tag", FT_UINT16, BASE_DEC, VALS(v7_parameter_tag_values), 0x0, NULL, HFILL } },
{ &hf_parameter_tag, { "Parameter Tag", "m3ua.parameter_tag", FT_UINT16, BASE_DEC, VALS(parameter_tag_values), 0x0, NULL, HFILL } },
{ &hf_parameter_length, { "Parameter length", "m3ua.parameter_length", FT_UINT16, BASE_DEC, NULL, 0x0, NULL, HFILL } },
{ &hf_parameter_value, { "Parameter value", "m3ua.parameter_value", FT_BYTES, BASE_NONE, NULL, 0x0, NULL, HFILL } },
{ &hf_parameter_padding, { "Padding", "m3ua.parameter_padding", FT_BYTES, BASE_NONE, NULL, 0x0, NULL, HFILL } },
#if 0
{ &hf_parameter_trailer, { "Trailer", "m3ua.paramter_trailer", FT_BYTES, BASE_NONE, NULL, 0x0, NULL, HFILL } },
#endif
{ &hf_network_appearance, { "Network appearance", "m3ua.network_appearance", FT_UINT32, BASE_DEC, NULL, 0x0, NULL, HFILL } },
{ &hf_info_string, { "Info string", "m3ua.info_string", FT_STRING, BASE_NONE, NULL, 0x0, NULL, HFILL } },
{ &hf_routing_context, { "Routing context", "m3ua.routing_context", FT_UINT32, BASE_DEC, NULL, 0x0, NULL, HFILL } },
{ &hf_diagnostic_information, { "Diagnostic information", "m3ua.diagnostic_information", FT_BYTES, BASE_NONE, NULL, 0x0, NULL, HFILL } },
{ &hf_heartbeat_data, { "Heartbeat data", "m3ua.heartbeat_data", FT_BYTES, BASE_NONE, NULL, 0x0, NULL, HFILL } },
{ &hf_v5_error_code, { "Error code", "m3ua.error_code", FT_UINT32, BASE_DEC, VALS(v5_error_code_values), 0x0, NULL, HFILL } },
{ &hf_v6_error_code, { "Error code", "m3ua.error_code", FT_UINT32, BASE_DEC, VALS(v6_error_code_values), 0x0, NULL, HFILL } },
{ &hf_v7_error_code, { "Error code", "m3ua.error_code", FT_UINT32, BASE_DEC, VALS(v7_error_code_values), 0x0, NULL, HFILL } },
{ &hf_error_code, { "Error code", "m3ua.error_code", FT_UINT32, BASE_DEC, VALS(error_code_values), 0x0, NULL, HFILL } },
{ &hf_status_type, { "Status type", "m3ua.status_type", FT_UINT16, BASE_DEC, VALS(status_type_values), 0x0, NULL, HFILL } },
{ &hf_status_info, { "Status info", "m3ua.status_info", FT_UINT16, BASE_DEC, NULL, 0x0, NULL, HFILL } },
{ &hf_asp_identifier, { "ASP identifier", "m3ua.asp_identifier", FT_UINT32, BASE_DEC, NULL, 0x0, NULL, HFILL } },
{ &hf_affected_point_code_mask, { "Mask", "m3ua.affected_point_code_mask", FT_UINT8, BASE_DEC, NULL, 0x0, NULL, HFILL } },
{ &hf_affected_point_code_pc, { "Affected point code", "m3ua.affected_point_code_pc", FT_UINT24, BASE_DEC, NULL, 0x0, NULL, HFILL } },
{ &hf_cause, { "Unavailability cause", "m3ua.unavailability_cause", FT_UINT16, BASE_DEC, VALS(unavailability_cause_values), 0x0, NULL, HFILL } },
{ &hf_user, { "User Identity", "m3ua.user_identity", FT_UINT16, BASE_DEC, VALS(user_identity_values), 0x0, NULL, HFILL } },
{ &hf_reason, { "Reason", "m3ua.reason", FT_UINT32, BASE_DEC, VALS(reason_values), 0x0, NULL, HFILL } },
{ &hf_v5_traffic_mode_type, { "Traffic mode Type", "m3ua.traffic_mode_type", FT_UINT32, BASE_DEC, VALS(v5_traffic_mode_type_values), 0x0, NULL, HFILL } },
{ &hf_v6_traffic_mode_type, { "Traffic mode Type", "m3ua.traffic_mode_type", FT_UINT32, BASE_DEC, VALS(v6_traffic_mode_type_values), 0x0, NULL, HFILL } },
{ &hf_v7_traffic_mode_type, { "Traffic mode Type", "m3ua.traffic_mode_type", FT_UINT32, BASE_DEC, VALS(v7_traffic_mode_type_values), 0x0, NULL, HFILL } },
{ &hf_traffic_mode_type, { "Traffic mode Type", "m3ua.traffic_mode_type", FT_UINT32, BASE_DEC, VALS(traffic_mode_type_values), 0x0, NULL, HFILL } },
{ &hf_congestion_reserved, { "Reserved", "m3ua.congestion_reserved", FT_BYTES, BASE_NONE, NULL, 0x0, NULL, HFILL } },
{ &hf_congestion_level, { "Congestion level", "m3ua.congestion_level", FT_UINT8, BASE_DEC, VALS(congestion_level_values), 0x0, NULL, HFILL } },
{ &hf_concerned_dest_reserved, { "Reserved", "m3ua.concerned_reserved", FT_BYTES, BASE_NONE, NULL, 0x0, NULL, HFILL } },
{ &hf_concerned_dest_pc, { "Concerned DPC", "m3ua.concerned_dpc", FT_UINT24, BASE_DEC, NULL, 0x0, NULL, HFILL } },
{ &hf_local_rk_identifier, { "Local routing key identifier", "m3ua.local_rk_identifier", FT_UINT32, BASE_DEC, NULL, 0x0, NULL, HFILL } },
{ &hf_dpc_mask, { "Mask", "m3ua.dpc_mask", FT_UINT8, BASE_DEC, NULL, 0x0, NULL, HFILL } },
{ &hf_dpc_pc, { "Destination point code", "m3ua.dpc_pc", FT_UINT24, BASE_DEC, NULL, 0x0, NULL, HFILL } },
{ &hf_si, { "Service indicator", "m3ua.si", FT_UINT8, BASE_DEC, VALS(user_identity_values), 0x0, NULL, HFILL } },
{ &hf_ssn, { "Subsystem number", "m3ua.ssn", FT_UINT8, BASE_DEC, NULL, 0x0, NULL, HFILL } },
{ &hf_opc_list_mask, { "Mask", "m3ua.opc_list_mask", FT_UINT8, BASE_DEC, NULL, 0x0, NULL, HFILL } },
{ &hf_opc_list_pc, { "Originating point code", "m3ua.opc_list_pc", FT_UINT24, BASE_DEC, NULL, 0x0, NULL, HFILL } },
{ &hf_cic_range_mask, { "Mask", "m3ua.cic_range_mask", FT_UINT8, BASE_DEC, NULL, 0x0, NULL, HFILL } },
{ &hf_cic_range_pc, { "Originating point code", "m3ua.cic_range_pc", FT_UINT24, BASE_DEC, NULL, 0x0, NULL, HFILL } },
{ &hf_cic_range_lower, { "Lower CIC value", "m3ua.cic_range_lower", FT_UINT16, BASE_DEC, NULL, 0x0, NULL, HFILL } },
{ &hf_cic_range_upper, { "Upper CIC value", "m3ua.cic_range_upper", FT_UINT16, BASE_DEC, NULL, 0x0, NULL, HFILL } },
{ &hf_li, { "Length indicator", "m3ua.protocol_data_2_li", FT_UINT8, BASE_DEC, NULL, 0x0, NULL, HFILL } },
{ &hf_protocol_data_opc, { "OPC", "m3ua.protocol_data_opc", FT_UINT32, BASE_DEC, NULL, 0x0, "Originating Point Code", HFILL } },
{ &hf_protocol_data_dpc, { "DPC", "m3ua.protocol_data_dpc", FT_UINT32, BASE_DEC, NULL, 0x0, "Destination Point Code", HFILL } },
{ &hf_protocol_data_mtp3_opc, { "OPC", "mtp3.opc", FT_UINT32, BASE_DEC, NULL, 0x0, NULL, HFILL } },
{ &hf_protocol_data_mtp3_dpc, { "DPC", "mtp3.dpc", FT_UINT32, BASE_DEC, NULL, 0x0, NULL, HFILL } },
{ &hf_protocol_data_mtp3_pc, { "PC", "mtp3.pc", FT_UINT32, BASE_DEC, NULL, 0x0, NULL, HFILL } },
{ &hf_protocol_data_si, { "SI", "m3ua.protocol_data_si", FT_UINT8, BASE_DEC, VALS(mtp3_service_indicator_code_short_vals), 0x0, "Service Indicator", HFILL } },
{ &hf_protocol_data_ni, { "NI", "m3ua.protocol_data_ni", FT_UINT8, BASE_DEC, VALS(mtp3_network_indicator_vals), 0x0, "Network Indicator", HFILL } },
{ &hf_protocol_data_mtp3_ni, { "NI", "mtp3.ni", FT_UINT8, BASE_DEC, NULL, 0x0, NULL, HFILL } },
{ &hf_protocol_data_mp, { "MP", "m3ua.protocol_data_mp", FT_UINT8, BASE_DEC, NULL, 0x0, "Message Priority", HFILL } },
{ &hf_protocol_data_sls, { "SLS", "m3ua.protocol_data_sls", FT_UINT8, BASE_DEC, NULL, 0x0, "Signalling Link Selection", HFILL } },
{ &hf_protocol_data_mtp3_sls, { "SLS", "mtp3.sls", FT_UINT8, BASE_DEC, NULL, 0x0, NULL, HFILL } },
{ &hf_correlation_identifier, { "Correlation Identifier", "m3ua.correlation_identifier", FT_UINT32, BASE_DEC, NULL, 0x0, NULL, HFILL } },
{ &hf_registration_status, { "Registration status", "m3ua.registration_status", FT_UINT32, BASE_DEC, VALS(registration_status_values), 0x0, NULL, HFILL } },
{ &hf_deregistration_status, { "Deregistration status", "m3ua.deregistration_status", FT_UINT32, BASE_DEC, VALS(deregistration_status_values), 0x0, NULL, HFILL } },
{ &hf_registration_result_identifier, { "Local RK-identifier value", "m3ua.registration_result_identifier", FT_UINT32, BASE_DEC, NULL, 0x0, NULL, HFILL } },
{ &hf_registration_result_status, { "Registration status", "m3ua.registration_results_status", FT_UINT32, BASE_DEC, VALS(registration_result_status_values), 0x0, NULL, HFILL } },
{ &hf_registration_result_context, { "Routing context", "m3ua.registration_result_routing_context", FT_UINT32, BASE_DEC, NULL, 0x0, NULL, HFILL } },
{ &hf_v6_deregistration_result_status, { "De-Registration status", "m3ua.deregistration_results_status", FT_UINT32, BASE_DEC, VALS(v6_deregistration_result_status_values), 0x0, NULL, HFILL } },
{ &hf_v6_deregistration_result_context, { "Routing context", "m3ua.deregistration_result_routing_context", FT_UINT32, BASE_DEC, NULL, 0x0, NULL, HFILL } },
};
static gint *ett[] = {
&ett_m3ua,
&ett_parameter,
&ett_mtp3_equiv,
&ett_q708_opc,
&ett_q708_dpc,
};
static const enum_val_t options[] = {
{ "draft-5", "Internet Draft version 5", M3UA_V5 },
{ "draft-6", "Internet Draft version 6", M3UA_V6 },
{ "draft-7", "Internet Draft version 7", M3UA_V7 },
{ "rfc4666", "RFC 4666", M3UA_RFC },
{ NULL, NULL, 0 }
};
proto_m3ua = proto_register_protocol("MTP 3 User Adaptation Layer", "M3UA", "m3ua");
register_dissector("m3ua", dissect_m3ua, proto_m3ua);
m3ua_module = prefs_register_protocol(proto_m3ua, NULL);
prefs_register_enum_preference(m3ua_module, "version", "M3UA Version", "Version used by Wireshark", &version, options, FALSE);
proto_register_field_array(proto_m3ua, hf, array_length(hf));
proto_register_subtree_array(ett, array_length(ett));
m3ua_tap = register_tap("m3ua");
}
void
proto_reg_handoff_m3ua(void)
{
dissector_handle_t m3ua_handle;
mtp3_handle = find_dissector("mtp3");
data_handle = find_dissector("data");
m3ua_handle = find_dissector("m3ua");
dissector_add_uint("sctp.ppi", M3UA_PAYLOAD_PROTOCOL_ID, m3ua_handle);
dissector_add_uint("sctp.port", SCTP_PORT_M3UA, m3ua_handle);
si_dissector_table = find_dissector_table("mtp3.service_indicator");
}
