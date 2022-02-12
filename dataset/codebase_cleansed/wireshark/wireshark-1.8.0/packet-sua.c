static sua_assoc_info_t *
new_assoc(guint32 calling, guint32 called)
{
sua_assoc_info_t* a = se_alloc0(sizeof(sua_assoc_info_t));
a->assoc_id = next_assoc_id++;
a->calling_routing_ind = 0;
a->called_routing_ind = 0;
a->calling_dpc = calling;
a->called_dpc = called;
a->calling_ssn = INVALID_SSN;
a->called_ssn = INVALID_SSN;
return a;
}
static sua_assoc_info_t*
sua_assoc(packet_info* pinfo, address* opc, address* dpc, guint src_rn, guint dst_rn)
{
guint32 opck, dpck;
if (!src_rn && !dst_rn)
{
return &no_sua_assoc;
}
opck = opc->type == AT_SS7PC ? mtp3_pc_hash(opc->data) : g_str_hash(address_to_str(opc));
dpck = dpc->type == AT_SS7PC ? mtp3_pc_hash(dpc->data) : g_str_hash(address_to_str(dpc));
switch (message_type)
{
case MESSAGE_TYPE_CORE:
{
emem_tree_key_t bw_key[] = {
{1,&dpck},
{1,&opck},
{1,&src_rn},
{0,NULL}
};
if (! ( assoc = se_tree_lookup32_array(assocs,bw_key) ) && ! pinfo->fd->flags.visited )
{
assoc = new_assoc(opck, dpck);
se_tree_insert32_array(assocs,bw_key,assoc);
assoc->has_bw_key = TRUE;
}
break;
}
case MESSAGE_TYPE_COAK:
{
emem_tree_key_t fw_key[] = {
{1,&dpck},
{1,&opck},
{1,&src_rn},
{0,NULL}
};
emem_tree_key_t bw_key[] = {
{1,&opck},
{1,&dpck},
{1,&dst_rn},
{0,NULL}
};
if ( ( assoc = se_tree_lookup32_array(assocs, bw_key) ) ) {
goto got_assoc;
}
if ( (assoc = se_tree_lookup32_array(assocs, fw_key) ) ) {
goto got_assoc;
}
assoc = new_assoc(dpck,opck);
got_assoc:
pinfo->p2p_dir = P2P_DIR_RECV;
if ( ! pinfo->fd->flags.visited && ! assoc->has_bw_key ) {
se_tree_insert32_array(assocs, bw_key, assoc);
assoc->has_bw_key = TRUE;
}
if ( ! pinfo->fd->flags.visited && ! assoc->has_fw_key ) {
se_tree_insert32_array(assocs, fw_key, assoc);
assoc->has_fw_key = TRUE;
}
break;
}
default:
{
emem_tree_key_t key[] = {
{1,&opck},
{1,&dpck},
{1,&dst_rn},
{0,NULL}
};
assoc = se_tree_lookup32_array(assocs,key);
break;
}
}
return assoc ? assoc : &no_sua_assoc;
}
static void
dissect_common_header(tvbuff_t *common_header_tvb, packet_info *pinfo, proto_tree *sua_tree)
{
message_class = tvb_get_guint8(common_header_tvb, MESSAGE_CLASS_OFFSET);
message_type = tvb_get_guint8(common_header_tvb, MESSAGE_TYPE_OFFSET);
col_add_fstr(pinfo->cinfo, COL_INFO, "%s ", val_to_str(message_class * 256 + message_type, message_class_type_acro_values, "reserved"));
if (sua_tree) {
proto_tree_add_item(sua_tree, hf_sua_version, common_header_tvb, VERSION_OFFSET, VERSION_LENGTH, ENC_BIG_ENDIAN);
proto_tree_add_item(sua_tree, hf_sua_reserved, common_header_tvb, RESERVED_OFFSET, RESERVED_LENGTH, ENC_NA);
proto_tree_add_item(sua_tree, hf_sua_message_class, common_header_tvb, MESSAGE_CLASS_OFFSET, MESSAGE_CLASS_LENGTH, ENC_BIG_ENDIAN);
proto_tree_add_uint_format(sua_tree, hf_sua_message_type, common_header_tvb, MESSAGE_TYPE_OFFSET, MESSAGE_TYPE_LENGTH, message_type, "Message Type: %s (%u)",
val_to_str(message_class * 256 + message_type, message_class_type_values, "reserved"), message_type);
proto_tree_add_item(sua_tree, hf_sua_message_length, common_header_tvb, MESSAGE_LENGTH_OFFSET, MESSAGE_LENGTH_LENGTH, ENC_BIG_ENDIAN);
};
}
static void
dissect_info_string_parameter(tvbuff_t *parameter_tvb, packet_info *pinfo, proto_tree *parameter_tree, proto_item *parameter_item)
{
guint16 info_string_length;
tvbuff_t *next_tvb;
info_string_length = tvb_get_ntohs(parameter_tvb, PARAMETER_LENGTH_OFFSET) - PARAMETER_HEADER_LENGTH;
if(sua_info_str_handle){
next_tvb = tvb_new_subset(parameter_tvb, INFO_STRING_OFFSET, info_string_length, info_string_length);
call_dissector(sua_info_str_handle, next_tvb, pinfo, parameter_tree);
return;
}
proto_tree_add_item(parameter_tree, hf_sua_info_string, parameter_tvb, INFO_STRING_OFFSET, info_string_length, ENC_ASCII|ENC_NA);
proto_item_append_text(parameter_item, " (%.*s)", info_string_length,
tvb_get_ephemeral_string(parameter_tvb, INFO_STRING_OFFSET, info_string_length));
}
static void
dissect_routing_context_parameter(tvbuff_t *parameter_tvb, proto_tree *parameter_tree, proto_item *parameter_item)
{
guint16 number_of_contexts, context_number;
gint context_offset;
number_of_contexts = (tvb_get_ntohs(parameter_tvb, PARAMETER_LENGTH_OFFSET) - PARAMETER_HEADER_LENGTH) / 4;
context_offset = PARAMETER_VALUE_OFFSET;
for(context_number=1; context_number <= number_of_contexts; context_number++) {
proto_tree_add_item(parameter_tree, hf_sua_routing_context, parameter_tvb, context_offset, ROUTING_CONTEXT_LENGTH, ENC_BIG_ENDIAN);
context_offset += ROUTING_CONTEXT_LENGTH;
};
proto_item_append_text(parameter_item, " (%u context%s)", number_of_contexts, plurality(number_of_contexts, "", "s"));
}
static void
dissect_diagnostic_information_parameter(tvbuff_t *parameter_tvb, proto_tree *parameter_tree, proto_item *parameter_item)
{
guint16 diag_info_length;
diag_info_length = tvb_get_ntohs(parameter_tvb, PARAMETER_LENGTH_OFFSET) - PARAMETER_HEADER_LENGTH;
proto_tree_add_item(parameter_tree, hf_sua_diagnostic_information_info, parameter_tvb, DIAGNOSTIC_INFO_OFFSET, diag_info_length, ENC_NA);
proto_item_append_text(parameter_item, " (%u byte%s)", diag_info_length, plurality(diag_info_length, "", "s"));
}
static void
dissect_heartbeat_data_parameter(tvbuff_t *parameter_tvb, proto_tree *parameter_tree, proto_item *parameter_item)
{
guint16 heartbeat_data_length;
heartbeat_data_length = tvb_get_ntohs(parameter_tvb, PARAMETER_LENGTH_OFFSET) - PARAMETER_HEADER_LENGTH;
proto_tree_add_item(parameter_tree, hf_sua_heartbeat_data, parameter_tvb, HEARTBEAT_DATA_OFFSET, heartbeat_data_length, ENC_NA);
proto_item_append_text(parameter_item, " (%u byte%s)", heartbeat_data_length, plurality(heartbeat_data_length, "", "s"));
}
static void
dissect_traffic_mode_type_parameter(tvbuff_t *parameter_tvb, proto_tree *parameter_tree, proto_item *parameter_item)
{
proto_tree_add_item(parameter_tree, hf_sua_traffic_mode_type, parameter_tvb, TRAFFIC_MODE_TYPE_OFFSET, TRAFFIC_MODE_TYPE_LENGTH, ENC_BIG_ENDIAN);
proto_item_append_text(parameter_item, " (%s)", val_to_str(tvb_get_ntohl(parameter_tvb, TRAFFIC_MODE_TYPE_OFFSET), traffic_mode_type_values, "unknown"));
}
static void
dissect_v8_error_code_parameter(tvbuff_t *parameter_tvb, proto_tree *parameter_tree, proto_item *parameter_item)
{
proto_tree_add_item(parameter_tree, hf_sua_v8_error_code, parameter_tvb, ERROR_CODE_OFFSET, ERROR_CODE_LENGTH, ENC_BIG_ENDIAN);
proto_item_append_text(parameter_item, " (%s)", val_to_str(tvb_get_ntohl(parameter_tvb, ERROR_CODE_OFFSET), v8_error_code_values, "unknown"));
}
static void
dissect_error_code_parameter(tvbuff_t *parameter_tvb, proto_tree *parameter_tree, proto_item *parameter_item)
{
proto_tree_add_item(parameter_tree, hf_sua_error_code, parameter_tvb, ERROR_CODE_OFFSET, ERROR_CODE_LENGTH, ENC_BIG_ENDIAN);
proto_item_append_text(parameter_item, " (%s)", val_to_str(tvb_get_ntohl(parameter_tvb, ERROR_CODE_OFFSET), error_code_values, "unknown"));
}
static void
dissect_status_type_parameter(tvbuff_t *parameter_tvb, proto_tree *parameter_tree, proto_item *parameter_item)
{
guint16 status_type, status_info;
status_type = tvb_get_ntohs(parameter_tvb, STATUS_TYPE_OFFSET);
status_info = tvb_get_ntohs(parameter_tvb, STATUS_INFO_OFFSET);
proto_tree_add_item(parameter_tree, hf_sua_status_type, parameter_tvb, STATUS_TYPE_OFFSET, STATUS_TYPE_LENGTH, ENC_BIG_ENDIAN);
proto_tree_add_uint_format(parameter_tree, hf_sua_status_info, parameter_tvb, STATUS_INFO_OFFSET, STATUS_INFO_LENGTH,
status_info, "Status info: %s (%u)", val_to_str(status_type * 256 * 256 + status_info, status_type_info_values, "unknown"), status_info);
proto_item_append_text(parameter_item, " (%s)", val_to_str(status_type * 256 * 256 + status_info, status_type_info_values, "unknown"));
}
static void
dissect_asp_identifier_parameter(tvbuff_t *parameter_tvb, proto_tree *parameter_tree, proto_item *parameter_item)
{
proto_tree_add_item(parameter_tree, hf_sua_asp_identifier, parameter_tvb, ASP_IDENTIFIER_OFFSET, ASP_IDENTIFIER_LENGTH, ENC_BIG_ENDIAN);
proto_item_append_text(parameter_item, " (%u)", tvb_get_ntohl(parameter_tvb, ASP_IDENTIFIER_OFFSET));
}
static void
dissect_affected_destinations_parameter(tvbuff_t *parameter_tvb, proto_tree *parameter_tree, proto_item *parameter_item)
{
guint16 number_of_destinations, destination_number;
gint destination_offset;
proto_item *dpc_item;
number_of_destinations= (tvb_get_ntohs(parameter_tvb, PARAMETER_LENGTH_OFFSET) - PARAMETER_HEADER_LENGTH) / 4;
destination_offset = PARAMETER_VALUE_OFFSET;
for(destination_number=1; destination_number <= number_of_destinations; destination_number++) {
proto_tree_add_item(parameter_tree, hf_sua_mask, parameter_tvb, destination_offset + AFFECTED_MASK_OFFSET, AFFECTED_MASK_LENGTH, ENC_BIG_ENDIAN);
dpc_item = proto_tree_add_item(parameter_tree, hf_sua_dpc, parameter_tvb, destination_offset + AFFECTED_DPC_OFFSET, AFFECTED_DPC_LENGTH, ENC_BIG_ENDIAN);
if (mtp3_pc_structured())
proto_item_append_text(dpc_item, " (%s)", mtp3_pc_to_str(tvb_get_ntoh24(parameter_tvb, destination_offset + AFFECTED_DPC_OFFSET)));
destination_offset += AFFECTED_DESTINATION_LENGTH;
}
proto_item_append_text(parameter_item, " (%u destination%s)", number_of_destinations, plurality(number_of_destinations, "", "s"));
}
static void
dissect_correlation_id_parameter(tvbuff_t *parameter_tvb, proto_tree *parameter_tree, proto_item *parameter_item)
{
proto_tree_add_item(parameter_tree, hf_sua_correlation_id, parameter_tvb, CORRELATION_ID_OFFSET, CORRELATION_ID_LENGTH, ENC_BIG_ENDIAN);
proto_item_append_text(parameter_item, " (%u)", tvb_get_ntohl(parameter_tvb, CORRELATION_ID_OFFSET));
}
static void
dissect_registration_result_parameter(tvbuff_t *parameter_tvb, packet_info *pinfo, proto_tree *parameter_tree)
{
tvbuff_t *parameters_tvb;
parameters_tvb = tvb_new_subset_remaining(parameter_tvb, PARAMETER_VALUE_OFFSET);
dissect_parameters(parameters_tvb, pinfo, parameter_tree, NULL, NULL, NULL);
}
static void
dissect_deregistration_result_parameter(tvbuff_t *parameter_tvb, packet_info *pinfo, proto_tree *parameter_tree)
{
tvbuff_t *parameters_tvb;
parameters_tvb = tvb_new_subset_remaining(parameter_tvb, PARAMETER_VALUE_OFFSET);
dissect_parameters(parameters_tvb, pinfo, parameter_tree, NULL, NULL, NULL);
}
static void
dissect_registration_status_parameter(tvbuff_t *parameter_tvb, proto_tree *parameter_tree, proto_item *parameter_item)
{
proto_tree_add_item(parameter_tree, hf_sua_registration_status, parameter_tvb, REGISTRATION_STATUS_OFFSET, REGISTRATION_STATUS_LENGTH, ENC_BIG_ENDIAN);
proto_item_append_text(parameter_item, " (%s)", val_to_str(tvb_get_ntohl(parameter_tvb, REGISTRATION_STATUS_OFFSET), registration_status_values, "unknown"));
}
static void
dissect_deregistration_status_parameter(tvbuff_t *parameter_tvb, proto_tree *parameter_tree, proto_item *parameter_item)
{
proto_tree_add_item(parameter_tree, hf_sua_deregistration_status, parameter_tvb, DEREGISTRATION_STATUS_OFFSET, DEREGISTRATION_STATUS_LENGTH, ENC_BIG_ENDIAN);
proto_item_append_text(parameter_item, " (%s)", val_to_str(tvb_get_ntohl(parameter_tvb, DEREGISTRATION_STATUS_OFFSET), deregistration_status_values, "unknown"));
}
static void
dissect_local_routing_key_identifier_parameter(tvbuff_t *parameter_tvb, proto_tree *parameter_tree, proto_item *parameter_item)
{
proto_tree_add_item(parameter_tree, hf_sua_local_routing_key_identifier, parameter_tvb, LOCAL_ROUTING_KEY_IDENTIFIER_OFFSET, LOCAL_ROUTING_KEY_IDENTIFIER_LENGTH, ENC_BIG_ENDIAN);
proto_item_append_text(parameter_item, " (%d)", tvb_get_ntohl(parameter_tvb, LOCAL_ROUTING_KEY_IDENTIFIER_OFFSET));
}
static void
dissect_ss7_hop_counter_parameter(tvbuff_t *parameter_tvb, proto_tree *parameter_tree, proto_item *parameter_item)
{
proto_tree_add_item(parameter_tree, hf_sua_ss7_hop_counter_reserved, parameter_tvb, PARAMETER_VALUE_OFFSET, RESERVED_3_LENGTH, ENC_NA);
proto_tree_add_item(parameter_tree, hf_sua_ss7_hop_counter_counter, parameter_tvb, SS7_HOP_COUNTER_OFFSET, SS7_HOP_COUNTER_LENGTH, ENC_BIG_ENDIAN);
proto_item_append_text(parameter_item, " (%u)", tvb_get_guint8(parameter_tvb, SS7_HOP_COUNTER_OFFSET));
}
static void
dissect_source_address_parameter(tvbuff_t *parameter_tvb, packet_info *pinfo, proto_tree *parameter_tree, guint8 *ssn)
{
proto_item *address_indicator_item;
proto_tree *address_indicator_tree;
tvbuff_t *parameters_tvb;
sua_ri = tvb_get_ntohs(parameter_tvb, ROUTING_INDICATOR_OFFSET);
if(parameter_tree) {
proto_tree_add_item(parameter_tree, hf_sua_source_address_routing_indicator, parameter_tvb, ROUTING_INDICATOR_OFFSET, ROUTING_INDICATOR_LENGTH, ENC_BIG_ENDIAN);
address_indicator_item = proto_tree_add_text(parameter_tree, parameter_tvb, ADDRESS_INDICATOR_OFFSET, ADDRESS_INDICATOR_LENGTH, "Address Indicator");
address_indicator_tree = proto_item_add_subtree(address_indicator_item, ett_sua_source_address_indicator);
proto_tree_add_item(address_indicator_tree, hf_sua_source_address_reserved_bits, parameter_tvb, ADDRESS_INDICATOR_OFFSET, ADDRESS_INDICATOR_LENGTH, ENC_BIG_ENDIAN);
proto_tree_add_item(address_indicator_tree, hf_sua_source_address_gt_bit, parameter_tvb, ADDRESS_INDICATOR_OFFSET, ADDRESS_INDICATOR_LENGTH, ENC_BIG_ENDIAN);
proto_tree_add_item(address_indicator_tree, hf_sua_source_address_pc_bit, parameter_tvb, ADDRESS_INDICATOR_OFFSET, ADDRESS_INDICATOR_LENGTH, ENC_BIG_ENDIAN);
proto_tree_add_item(address_indicator_tree, hf_sua_source_address_ssn_bit, parameter_tvb, ADDRESS_INDICATOR_OFFSET, ADDRESS_INDICATOR_LENGTH, ENC_BIG_ENDIAN);
}
parameters_tvb = tvb_new_subset_remaining(parameter_tvb, ADDRESS_PARAMETERS_OFFSET);
dissect_parameters(parameters_tvb, pinfo, parameter_tree, NULL, ssn, NULL);
}
static void
dissect_destination_address_parameter(tvbuff_t *parameter_tvb, packet_info *pinfo, proto_tree *parameter_tree, guint8 *ssn)
{
proto_item *address_indicator_item;
proto_tree *address_indicator_tree;
tvbuff_t *parameters_tvb;
sua_ri = tvb_get_ntohs(parameter_tvb, ROUTING_INDICATOR_OFFSET);
if(parameter_tree) {
proto_tree_add_item(parameter_tree, hf_sua_destination_address_routing_indicator, parameter_tvb, ROUTING_INDICATOR_OFFSET, ROUTING_INDICATOR_LENGTH, ENC_BIG_ENDIAN);
address_indicator_item = proto_tree_add_text(parameter_tree, parameter_tvb, ADDRESS_INDICATOR_OFFSET, ADDRESS_INDICATOR_LENGTH, "Address Indicator");
address_indicator_tree = proto_item_add_subtree(address_indicator_item, ett_sua_destination_address_indicator);
proto_tree_add_item(address_indicator_tree, hf_sua_destination_address_reserved_bits, parameter_tvb, ADDRESS_INDICATOR_OFFSET, ADDRESS_INDICATOR_LENGTH, ENC_BIG_ENDIAN);
proto_tree_add_item(address_indicator_tree, hf_sua_destination_address_gt_bit, parameter_tvb, ADDRESS_INDICATOR_OFFSET, ADDRESS_INDICATOR_LENGTH, ENC_BIG_ENDIAN);
proto_tree_add_item(address_indicator_tree, hf_sua_destination_address_pc_bit, parameter_tvb, ADDRESS_INDICATOR_OFFSET, ADDRESS_INDICATOR_LENGTH, ENC_BIG_ENDIAN);
proto_tree_add_item(address_indicator_tree, hf_sua_destination_address_ssn_bit, parameter_tvb, ADDRESS_INDICATOR_OFFSET, ADDRESS_INDICATOR_LENGTH, ENC_BIG_ENDIAN);
}
parameters_tvb = tvb_new_subset_remaining(parameter_tvb, ADDRESS_PARAMETERS_OFFSET);
dissect_parameters(parameters_tvb, pinfo, parameter_tree, NULL, NULL, ssn);
}
static void
dissect_source_reference_number_parameter(tvbuff_t *parameter_tvb, proto_tree *parameter_tree, proto_item *parameter_item)
{
srn = tvb_get_ntohl(parameter_tvb, SOURCE_REFERENCE_NUMBER_OFFSET);
proto_tree_add_item(parameter_tree, hf_sua_source_reference_number, parameter_tvb, SOURCE_REFERENCE_NUMBER_OFFSET, SOURCE_REFERENCE_NUMBER_LENGTH, ENC_BIG_ENDIAN);
proto_item_append_text(parameter_item, " (%u)", tvb_get_ntohl(parameter_tvb, SOURCE_REFERENCE_NUMBER_OFFSET));
}
static void
dissect_destination_reference_number_parameter(tvbuff_t *parameter_tvb, proto_tree *parameter_tree, proto_item *parameter_item)
{
drn = tvb_get_ntohl(parameter_tvb, DESTINATION_REFERENCE_NUMBER_OFFSET);
proto_tree_add_item(parameter_tree, hf_sua_destination_reference_number, parameter_tvb, DESTINATION_REFERENCE_NUMBER_OFFSET, DESTINATION_REFERENCE_NUMBER_LENGTH, ENC_BIG_ENDIAN);
proto_item_append_text(parameter_item, " (%u)", tvb_get_ntohl(parameter_tvb, DESTINATION_REFERENCE_NUMBER_OFFSET));
}
static void
dissect_sccp_cause_parameter(tvbuff_t *parameter_tvb, proto_tree *parameter_tree, proto_item *parameter_item)
{
guint8 cause_type, cause;
proto_item *pi;
const gchar *cause_string;
proto_tree_add_item(parameter_tree, hf_sua_cause_reserved, parameter_tvb, PARAMETER_VALUE_OFFSET, RESERVED_2_LENGTH, ENC_NA);
proto_tree_add_item(parameter_tree, hf_sua_cause_type, parameter_tvb, CAUSE_TYPE_OFFSET, CAUSE_TYPE_LENGTH, ENC_BIG_ENDIAN);
cause_type = tvb_get_guint8(parameter_tvb, CAUSE_TYPE_OFFSET);
pi = proto_tree_add_item(parameter_tree, hf_sua_cause_value, parameter_tvb, CAUSE_VALUE_OFFSET, CAUSE_VALUE_LENGTH, ENC_BIG_ENDIAN);
cause = tvb_get_guint8(parameter_tvb, CAUSE_VALUE_OFFSET);
switch (cause_type) {
case CAUSE_TYPE_RETURN:
cause_string = val_to_str(cause, sccp_return_cause_values, "unknown");
break;
case CAUSE_TYPE_REFUSAL:
cause_string = val_to_str(cause, sccp_refusal_cause_values, "unknown");
break;
case CAUSE_TYPE_RELEASE:
cause_string = val_to_str(cause, sccp_release_cause_values, "unknown");
break;
case CAUSE_TYPE_RESET:
cause_string = val_to_str(cause, sccp_reset_cause_values, "unknown");
break;
case CAUSE_TYPE_ERROR:
cause_string = val_to_str(cause, sccp_error_cause_values, "unknown");
break;
default:
cause_string = "unknown";
}
proto_item_append_text(pi, " (%s)", cause_string);
proto_item_append_text(parameter_item, " (%s: %s)", val_to_str(cause_type, cause_type_values, "unknown"), cause_string);
}
static void
dissect_sequence_number_parameter(tvbuff_t *parameter_tvb, proto_tree *parameter_tree)
{
proto_item *sent_sequence_number_item;
proto_tree *sent_sequence_number_tree;
proto_item *receive_sequence_number_item;
proto_tree *receive_sequence_number_tree;
proto_tree_add_item(parameter_tree, hf_sua_sequence_number_reserved, parameter_tvb, PARAMETER_VALUE_OFFSET, RESERVED_2_LENGTH, ENC_NA);
receive_sequence_number_item = proto_tree_add_text(parameter_tree, parameter_tvb, SEQUENCE_NUMBER_REC_SEQ_OFFSET, SEQUENCE_NUMBER_REC_SEQ_LENGTH, "Receive Sequence Number");
receive_sequence_number_tree = proto_item_add_subtree(receive_sequence_number_item, ett_sua_sequence_number_rec_number);
proto_tree_add_item(receive_sequence_number_tree, hf_sua_sequence_number_rec_number, parameter_tvb, SEQUENCE_NUMBER_REC_SEQ_OFFSET, SEQUENCE_NUMBER_REC_SEQ_LENGTH, ENC_BIG_ENDIAN);
proto_tree_add_item(receive_sequence_number_tree, hf_sua_sequence_number_more_data_bit, parameter_tvb, SEQUENCE_NUMBER_REC_SEQ_OFFSET, SEQUENCE_NUMBER_REC_SEQ_LENGTH, ENC_BIG_ENDIAN);
sent_sequence_number_item = proto_tree_add_text(parameter_tree, parameter_tvb, SEQUENCE_NUMBER_SENT_SEQ_OFFSET, SEQUENCE_NUMBER_SENT_SEQ_LENGTH, "Sent Sequence Number");
sent_sequence_number_tree = proto_item_add_subtree(sent_sequence_number_item, ett_sua_sequence_number_sent_number);
proto_tree_add_item(sent_sequence_number_tree, hf_sua_sequence_number_sent_number, parameter_tvb, SEQUENCE_NUMBER_SENT_SEQ_OFFSET, SEQUENCE_NUMBER_SENT_SEQ_LENGTH, ENC_BIG_ENDIAN);
proto_tree_add_item(sent_sequence_number_tree, hf_sua_sequence_number_spare_bit, parameter_tvb, SEQUENCE_NUMBER_SENT_SEQ_OFFSET, SEQUENCE_NUMBER_SENT_SEQ_LENGTH, ENC_BIG_ENDIAN);
}
static void
dissect_receive_sequence_number_parameter(tvbuff_t *parameter_tvb, proto_tree *parameter_tree)
{
proto_item *receive_sequence_number_item;
proto_tree *receive_sequence_number_tree;
proto_tree_add_item(parameter_tree, hf_sua_receive_sequence_number_reserved, parameter_tvb, PARAMETER_VALUE_OFFSET, RESERVED_3_LENGTH, ENC_NA);
receive_sequence_number_item = proto_tree_add_text(parameter_tree, parameter_tvb, RECEIVE_SEQUENCE_NUMBER_REC_SEQ_OFFSET, RECEIVE_SEQUENCE_NUMBER_REC_SEQ_LENGTH, "Receive Sequence Number");
receive_sequence_number_tree = proto_item_add_subtree(receive_sequence_number_item, ett_sua_receive_sequence_number_number);
proto_tree_add_item(receive_sequence_number_tree, hf_sua_receive_sequence_number_number, parameter_tvb, RECEIVE_SEQUENCE_NUMBER_REC_SEQ_OFFSET, RECEIVE_SEQUENCE_NUMBER_REC_SEQ_LENGTH, ENC_BIG_ENDIAN);
proto_tree_add_item(receive_sequence_number_tree, hf_sua_receive_sequence_number_spare_bit, parameter_tvb, RECEIVE_SEQUENCE_NUMBER_REC_SEQ_OFFSET, RECEIVE_SEQUENCE_NUMBER_REC_SEQ_LENGTH, ENC_BIG_ENDIAN);
}
static void
dissect_asp_capabilities_parameter(tvbuff_t *parameter_tvb, proto_tree *parameter_tree)
{
proto_item *protocol_classes_item;
proto_tree *protocol_classes_tree;
proto_tree_add_item(parameter_tree, hf_sua_asp_capabilities_reserved, parameter_tvb, PARAMETER_VALUE_OFFSET, RESERVED_2_LENGTH, ENC_NA);
protocol_classes_item = proto_tree_add_text(parameter_tree, parameter_tvb, PROTOCOL_CLASSES_OFFSET, PROTOCOL_CLASSES_LENGTH, "Protocol classes");
protocol_classes_tree = proto_item_add_subtree(protocol_classes_item, ett_sua_protcol_classes);
proto_tree_add_item(protocol_classes_tree, hf_sua_asp_capabilities_reserved_bits, parameter_tvb, PROTOCOL_CLASSES_OFFSET, PROTOCOL_CLASSES_LENGTH, ENC_BIG_ENDIAN);
proto_tree_add_item(protocol_classes_tree, hf_sua_asp_capabilities_a_bit, parameter_tvb, PROTOCOL_CLASSES_OFFSET, PROTOCOL_CLASSES_LENGTH, ENC_BIG_ENDIAN);
proto_tree_add_item(protocol_classes_tree, hf_sua_asp_capabilities_b_bit, parameter_tvb, PROTOCOL_CLASSES_OFFSET, PROTOCOL_CLASSES_LENGTH, ENC_BIG_ENDIAN);
proto_tree_add_item(protocol_classes_tree, hf_sua_asp_capabilities_c_bit, parameter_tvb, PROTOCOL_CLASSES_OFFSET, PROTOCOL_CLASSES_LENGTH, ENC_BIG_ENDIAN);
proto_tree_add_item(protocol_classes_tree, hf_sua_asp_capabilities_d_bit, parameter_tvb, PROTOCOL_CLASSES_OFFSET, PROTOCOL_CLASSES_LENGTH, ENC_BIG_ENDIAN);
proto_tree_add_item(parameter_tree, hf_sua_asp_capabilities_interworking, parameter_tvb, INTERWORKING_OFFSET, INTERWORKING_LENGTH, ENC_BIG_ENDIAN);
}
static void
dissect_credit_parameter(tvbuff_t *parameter_tvb, proto_tree *parameter_tree, proto_item *parameter_item)
{
proto_tree_add_item(parameter_tree, hf_sua_credit, parameter_tvb, CREDIT_OFFSET, CREDIT_LENGTH, ENC_BIG_ENDIAN);
proto_item_append_text(parameter_item, " (%u)", tvb_get_ntohl(parameter_tvb, CREDIT_OFFSET));
}
static void
dissect_data_parameter(tvbuff_t *parameter_tvb, proto_tree *parameter_tree, proto_item *parameter_item, tvbuff_t **data_tvb)
{
guint16 data_length;
data_length = tvb_get_ntohs(parameter_tvb, PARAMETER_LENGTH_OFFSET) - PARAMETER_HEADER_LENGTH;
if(parameter_tree) {
proto_tree_add_item(parameter_tree, hf_sua_data, parameter_tvb, DATA_PARAMETER_DATA_OFFSET, data_length, ENC_NA);
proto_item_append_text(parameter_item, " (SS7 message of %u byte%s)", data_length, plurality(data_length, "", "s"));
}
if(data_tvb)
{
*data_tvb = tvb_new_subset(parameter_tvb, PARAMETER_VALUE_OFFSET, data_length, data_length);
}
}
static void
dissect_user_cause_parameter(tvbuff_t *parameter_tvb, proto_tree *parameter_tree)
{
proto_tree_add_item(parameter_tree, hf_sua_cause, parameter_tvb, CAUSE_OFFSET, CAUSE_LENGTH, ENC_BIG_ENDIAN);
proto_tree_add_item(parameter_tree, hf_sua_user, parameter_tvb, USER_OFFSET, USER_LENGTH, ENC_BIG_ENDIAN);
}
static void
dissect_network_appearance_parameter(tvbuff_t *parameter_tvb, proto_tree *parameter_tree, proto_item *parameter_item)
{
proto_tree_add_item(parameter_tree, hf_sua_network_appearance, parameter_tvb, NETWORK_APPEARANCE_OFFSET, NETWORK_APPEARANCE_LENGTH, ENC_BIG_ENDIAN);
proto_item_append_text(parameter_item, " (%u)", tvb_get_ntohl(parameter_tvb, NETWORK_APPEARANCE_OFFSET));
}
static void
dissect_routing_key_parameter(tvbuff_t *parameter_tvb, packet_info *pinfo, proto_tree *parameter_tree)
{
tvbuff_t *parameters_tvb;
parameters_tvb = tvb_new_subset_remaining(parameter_tvb, PARAMETER_VALUE_OFFSET);
dissect_parameters(parameters_tvb, pinfo, parameter_tree, NULL, NULL, NULL);
}
static void
dissect_drn_label_parameter(tvbuff_t *parameter_tvb, proto_tree *parameter_tree)
{
proto_tree_add_item(parameter_tree, hf_sua_drn_label_start, parameter_tvb, DRN_START_OFFSET, DRN_START_LENGTH, ENC_BIG_ENDIAN);
proto_tree_add_item(parameter_tree, hf_sua_drn_label_end, parameter_tvb, DRN_END_OFFSET, DRN_END_LENGTH, ENC_BIG_ENDIAN);
proto_tree_add_item(parameter_tree, hf_sua_drn_label_value, parameter_tvb, DRN_VALUE_OFFSET, DRN_VALUE_LENGTH, ENC_BIG_ENDIAN);
}
static void
dissect_tid_label_parameter(tvbuff_t *parameter_tvb, proto_tree *parameter_tree)
{
proto_tree_add_item(parameter_tree, hf_sua_tid_label_start, parameter_tvb, TID_START_OFFSET, TID_START_LENGTH, ENC_BIG_ENDIAN);
proto_tree_add_item(parameter_tree, hf_sua_tid_label_end, parameter_tvb, TID_END_OFFSET, TID_END_LENGTH, ENC_BIG_ENDIAN);
proto_tree_add_item(parameter_tree, hf_sua_tid_label_value, parameter_tvb, TID_VALUE_OFFSET, TID_VALUE_LENGTH, ENC_BIG_ENDIAN);
}
static void
dissect_address_range_parameter(tvbuff_t *parameter_tvb, packet_info *pinfo, proto_tree *parameter_tree)
{
tvbuff_t *parameters_tvb;
parameters_tvb = tvb_new_subset_remaining(parameter_tvb, PARAMETER_VALUE_OFFSET);
dissect_parameters(parameters_tvb, pinfo, parameter_tree, NULL, NULL, NULL);
}
static void
dissect_smi_parameter(tvbuff_t *parameter_tvb, proto_tree *parameter_tree, proto_item *parameter_item)
{
proto_tree_add_item(parameter_tree, hf_sua_smi_reserved, parameter_tvb, PARAMETER_VALUE_OFFSET, RESERVED_3_LENGTH, ENC_NA);
proto_tree_add_item(parameter_tree, hf_sua_smi, parameter_tvb, SMI_OFFSET, SMI_LENGTH, ENC_BIG_ENDIAN);
proto_item_append_text(parameter_item, " (%u)", tvb_get_guint8(parameter_tvb, SMI_OFFSET));
}
static void
dissect_importance_parameter(tvbuff_t *parameter_tvb, proto_tree *parameter_tree, proto_item *parameter_item)
{
proto_tree_add_item(parameter_tree, hf_sua_importance_reserved, parameter_tvb, PARAMETER_VALUE_OFFSET, RESERVED_3_LENGTH, ENC_NA);
proto_tree_add_item(parameter_tree, hf_sua_importance, parameter_tvb, IMPORTANCE_OFFSET, IMPORTANCE_LENGTH, ENC_BIG_ENDIAN);
proto_item_append_text(parameter_item, " (%u)", tvb_get_guint8(parameter_tvb, IMPORTANCE_OFFSET));
}
static void
dissect_message_priority_parameter(tvbuff_t *parameter_tvb, proto_tree *parameter_tree, proto_item *parameter_item)
{
proto_tree_add_item(parameter_tree, hf_sua_message_priority_reserved, parameter_tvb, PARAMETER_VALUE_OFFSET, RESERVED_3_LENGTH, ENC_NA);
proto_tree_add_item(parameter_tree, hf_sua_message_priority, parameter_tvb, MESSAGE_PRIORITY_OFFSET, MESSAGE_PRIORITY_LENGTH, ENC_BIG_ENDIAN);
proto_item_append_text(parameter_item, " (%u)", tvb_get_guint8(parameter_tvb, MESSAGE_PRIORITY_OFFSET));
}
static void
dissect_protocol_class_parameter(tvbuff_t *parameter_tvb, proto_tree *parameter_tree, proto_item *parameter_item)
{
proto_item *protocol_class_item;
proto_tree *protocol_class_tree;
proto_tree_add_item(parameter_tree, hf_sua_protocol_class_reserved, parameter_tvb, PARAMETER_VALUE_OFFSET, RESERVED_3_LENGTH, ENC_NA);
protocol_class_item = proto_tree_add_text(parameter_tree, parameter_tvb, PROTOCOL_CLASS_OFFSET, PROTOCOL_CLASS_LENGTH, "Protocol Class");
protocol_class_tree = proto_item_add_subtree(protocol_class_item, ett_sua_return_on_error_bit_and_protocol_class);
proto_tree_add_item(protocol_class_tree, hf_sua_return_on_error_bit, parameter_tvb, PROTOCOL_CLASS_OFFSET, PROTOCOL_CLASS_LENGTH, ENC_BIG_ENDIAN);
proto_tree_add_item(protocol_class_tree, hf_sua_protocol_class, parameter_tvb, PROTOCOL_CLASS_OFFSET, PROTOCOL_CLASS_LENGTH, ENC_BIG_ENDIAN);
proto_item_append_text(parameter_item, " (%d)", tvb_get_guint8(parameter_tvb, PROTOCOL_CLASS_OFFSET) & PROTOCOL_CLASS_MASK);
}
static void
dissect_sequence_control_parameter(tvbuff_t *parameter_tvb, proto_tree *parameter_tree, proto_item *parameter_item)
{
proto_tree_add_item(parameter_tree, hf_sua_sequence_control, parameter_tvb, SEQUENCE_CONTROL_OFFSET, SEQUENCE_CONTROL_LENGTH, ENC_BIG_ENDIAN);
proto_item_append_text(parameter_item, " (%u)", tvb_get_ntohl(parameter_tvb, SEQUENCE_CONTROL_OFFSET));
}
static void
dissect_segmentation_parameter(tvbuff_t *parameter_tvb, proto_tree *parameter_tree)
{
proto_item *first_remaining_item;
proto_tree *first_remaining_tree;
first_remaining_item = proto_tree_add_text(parameter_tree, parameter_tvb, FIRST_REMAINING_OFFSET, FIRST_REMAINING_LENGTH, "First / Remaining");
first_remaining_tree = proto_item_add_subtree(first_remaining_item, ett_sua_first_remaining);
proto_tree_add_item(first_remaining_tree, hf_sua_first_bit, parameter_tvb, FIRST_REMAINING_OFFSET, FIRST_REMAINING_LENGTH, ENC_BIG_ENDIAN);
proto_tree_add_item(first_remaining_tree, hf_sua_number_of_remaining_segments, parameter_tvb, FIRST_REMAINING_OFFSET, FIRST_REMAINING_LENGTH, ENC_BIG_ENDIAN);
proto_tree_add_item(parameter_tree, hf_sua_segmentation_reference, parameter_tvb, SEGMENTATION_REFERENCE_OFFSET, SEGMENTATION_REFERENCE_LENGTH, ENC_BIG_ENDIAN);
}
static void
dissect_congestion_level_parameter(tvbuff_t *parameter_tvb, proto_tree *parameter_tree, proto_item *parameter_item)
{
proto_tree_add_item(parameter_tree, hf_sua_congestion_level, parameter_tvb, CONGESTION_LEVEL_OFFSET, CONGESTION_LEVEL_LENGTH, ENC_BIG_ENDIAN);
proto_item_append_text(parameter_item, " (%u)", tvb_get_ntohl(parameter_tvb, CONGESTION_LEVEL_OFFSET));
}
static void
dissect_global_title_parameter(tvbuff_t *parameter_tvb, proto_tree *parameter_tree, gboolean source)
{
guint16 global_title_length;
guint16 offset;
gboolean even_length;
guint8 odd_signal, even_signal;
guint8 number_of_digits;
char *gt_digits;
gt_digits = ep_alloc0(GT_MAX_SIGNALS+1);
global_title_length = tvb_get_ntohs(parameter_tvb, PARAMETER_LENGTH_OFFSET) -
(PARAMETER_HEADER_LENGTH + RESERVED_3_LENGTH + GTI_LENGTH + NO_OF_DIGITS_LENGTH + TRANSLATION_TYPE_LENGTH + NUMBERING_PLAN_LENGTH + NATURE_OF_ADDRESS_LENGTH);
proto_tree_add_item(parameter_tree, hf_sua_gt_reserved, parameter_tvb, PARAMETER_VALUE_OFFSET, RESERVED_3_LENGTH, ENC_NA);
proto_tree_add_item(parameter_tree, hf_sua_gti, parameter_tvb, GTI_OFFSET, GTI_LENGTH, ENC_BIG_ENDIAN);
proto_tree_add_item(parameter_tree, hf_sua_number_of_digits, parameter_tvb, NO_OF_DIGITS_OFFSET, NO_OF_DIGITS_LENGTH, ENC_BIG_ENDIAN);
proto_tree_add_item(parameter_tree, hf_sua_translation_type, parameter_tvb, TRANSLATION_TYPE_OFFSET, TRANSLATION_TYPE_LENGTH, ENC_BIG_ENDIAN);
proto_tree_add_item(parameter_tree, hf_sua_numbering_plan, parameter_tvb, NUMBERING_PLAN_OFFSET, NUMBERING_PLAN_LENGTH, ENC_BIG_ENDIAN);
proto_tree_add_item(parameter_tree, hf_sua_nature_of_address, parameter_tvb, NATURE_OF_ADDRESS_OFFSET, NATURE_OF_ADDRESS_LENGTH, ENC_BIG_ENDIAN);
number_of_digits = tvb_get_guint8(parameter_tvb, NO_OF_DIGITS_OFFSET);
even_length = !(number_of_digits % 2);
offset = GLOBAL_TITLE_OFFSET;
while(offset < GLOBAL_TITLE_OFFSET + global_title_length) {
odd_signal = tvb_get_guint8(parameter_tvb, offset) & GT_ODD_SIGNAL_MASK;
even_signal = tvb_get_guint8(parameter_tvb, offset) & GT_EVEN_SIGNAL_MASK;
even_signal >>= GT_EVEN_SIGNAL_SHIFT;
g_strlcat(gt_digits, val_to_str(odd_signal, sccp_address_signal_values,
"Unknown"), GT_MAX_SIGNALS+1);
if (offset != (GLOBAL_TITLE_OFFSET + global_title_length - 1) || even_length == TRUE)
g_strlcat(gt_digits, val_to_str(even_signal, sccp_address_signal_values,
"Unknown"), GT_MAX_SIGNALS+1);
offset += GT_SIGNAL_LENGTH;
}
proto_tree_add_string_format(parameter_tree, hf_sua_global_title_digits,
parameter_tvb, GLOBAL_TITLE_OFFSET,
global_title_length, gt_digits,
"Address information (digits): %s", gt_digits);
if (sua_ri == ROUTE_ON_GT_ROUTING_INDICATOR) {
if (source) {
sua_source_gt = gt_digits;
} else {
sua_destination_gt = gt_digits;
}
}
}
static void
dissect_point_code_parameter(tvbuff_t *parameter_tvb, proto_tree *parameter_tree, proto_item *parameter_item, gboolean source)
{
guint32 pc;
pc = tvb_get_ntohl(parameter_tvb, POINT_CODE_OFFSET);
if (sua_ri == ROUTE_ON_SSN_PC_ROUTING_INDICATOR) {
if (source) {
sua_opc->type = mtp3_standard;
sua_opc->pc = pc;
} else {
sua_dpc->type = mtp3_standard;
sua_dpc->pc = pc;
}
}
proto_tree_add_item(parameter_tree, hf_sua_point_code_dpc, parameter_tvb, POINT_CODE_OFFSET, POINT_CODE_LENGTH, ENC_BIG_ENDIAN);
proto_item_append_text(parameter_item, " (%s)", mtp3_pc_to_str(pc));
}
static void
dissect_ssn_parameter(tvbuff_t *parameter_tvb, proto_tree *parameter_tree, proto_item *parameter_item, guint8 *ssn)
{
*ssn = tvb_get_guint8(parameter_tvb, SSN_OFFSET);
if(parameter_tree) {
proto_tree_add_item(parameter_tree, hf_sua_ssn_reserved, parameter_tvb, PARAMETER_VALUE_OFFSET, RESERVED_3_LENGTH, ENC_NA);
proto_tree_add_item(parameter_tree, hf_sua_ssn_number, parameter_tvb, SSN_OFFSET, SSN_LENGTH, ENC_BIG_ENDIAN);
proto_item_append_text(parameter_item, " (%u)", *ssn);
}
}
static void
dissect_ipv4_parameter(tvbuff_t *parameter_tvb, proto_tree *parameter_tree, proto_item *parameter_item)
{
proto_tree_add_item(parameter_tree, hf_sua_ipv4, parameter_tvb, IPV4_ADDRESS_OFFSET, IPV4_ADDRESS_LENGTH, ENC_BIG_ENDIAN);
proto_item_append_text(parameter_item, " (%s)", tvb_ip_to_str(parameter_tvb, IPV4_ADDRESS_OFFSET));
}
static void
dissect_hostname_parameter(tvbuff_t *parameter_tvb, proto_tree *parameter_tree, proto_item *parameter_item)
{
guint16 hostname_length;
hostname_length = tvb_get_ntohs(parameter_tvb, PARAMETER_LENGTH_OFFSET) - PARAMETER_HEADER_LENGTH;
proto_tree_add_item(parameter_tree, hf_sua_hostname, parameter_tvb, HOSTNAME_OFFSET, hostname_length, ENC_ASCII|ENC_NA);
proto_item_append_text(parameter_item, " (%.*s)", hostname_length,
tvb_get_ephemeral_string(parameter_tvb, HOSTNAME_OFFSET, hostname_length));
}
static void
dissect_ipv6_parameter(tvbuff_t *parameter_tvb, proto_tree *parameter_tree, proto_item *parameter_item)
{
proto_tree_add_item(parameter_tree, hf_sua_ipv6, parameter_tvb, IPV6_ADDRESS_OFFSET, IPV6_ADDRESS_LENGTH, ENC_NA);
proto_item_append_text(parameter_item, " (%s)", tvb_ip6_to_str(parameter_tvb, IPV6_ADDRESS_OFFSET));
}
static void
dissect_unknown_parameter(tvbuff_t *parameter_tvb, proto_tree *parameter_tree, proto_item *parameter_item)
{
guint16 parameter_value_length;
parameter_value_length = tvb_get_ntohs(parameter_tvb, PARAMETER_LENGTH_OFFSET) - PARAMETER_HEADER_LENGTH;
proto_tree_add_item(parameter_tree, hf_sua_parameter_value, parameter_tvb, PARAMETER_VALUE_OFFSET, parameter_value_length, ENC_NA);
proto_item_append_text(parameter_item, "(tag %u and %u byte%s value)", tvb_get_ntohs(parameter_tvb, PARAMETER_TAG_OFFSET), parameter_value_length, plurality(parameter_value_length, "", "s"));
}
static void
dissect_v8_parameter(tvbuff_t *parameter_tvb, packet_info *pinfo, proto_tree *tree, tvbuff_t **data_tvb, guint8 *source_ssn, guint8 *dest_ssn)
{
guint16 tag, length, padding_length;
proto_item *parameter_item;
proto_tree *parameter_tree;
guint8 ssn = INVALID_SSN;
tag = tvb_get_ntohs(parameter_tvb, PARAMETER_TAG_OFFSET);
length = tvb_get_ntohs(parameter_tvb, PARAMETER_LENGTH_OFFSET);
padding_length = tvb_length(parameter_tvb) - length;
if (tree) {
parameter_item = proto_tree_add_text(tree, parameter_tvb, PARAMETER_HEADER_OFFSET, tvb_length(parameter_tvb), "%s", val_to_str(tag, v8_parameter_tag_values, "Unknown parameter"));
parameter_tree = proto_item_add_subtree(parameter_item, ett_sua_parameter);
proto_tree_add_item(parameter_tree, hf_sua_v8_parameter_tag, parameter_tvb, PARAMETER_TAG_OFFSET, PARAMETER_TAG_LENGTH, ENC_BIG_ENDIAN);
proto_tree_add_item(parameter_tree, hf_sua_parameter_length, parameter_tvb, PARAMETER_LENGTH_OFFSET, PARAMETER_LENGTH_LENGTH, ENC_BIG_ENDIAN);
} else {
parameter_tree = NULL;
parameter_item = NULL;
}
if (!tree && tag != V8_DATA_PARAMETER_TAG
&& tag != V8_SOURCE_ADDRESS_PARAMETER_TAG
&& tag != V8_DESTINATION_ADDRESS_PARAMETER_TAG
&& tag != V8_DESTINATION_REFERENCE_NUMBER_PARAMETER_TAG
&& tag != V8_SOURCE_REFERENCE_NUMBER_PARAMETER_TAG
&& tag != V8_SUBSYSTEM_NUMBER_PARAMETER_TAG)
return;
switch(tag) {
case V8_DATA_PARAMETER_TAG:
dissect_data_parameter(parameter_tvb, parameter_tree, parameter_item, data_tvb);
break;
case V8_INFO_STRING_PARAMETER_TAG:
dissect_info_string_parameter(parameter_tvb, pinfo, parameter_tree, parameter_item);
break;
case V8_ROUTING_CONTEXT_PARAMETER_TAG:
dissect_routing_context_parameter(parameter_tvb, parameter_tree, parameter_item);
break;
case V8_DIAGNOSTIC_INFO_PARAMETER_TAG:
dissect_diagnostic_information_parameter(parameter_tvb, parameter_tree, parameter_item);
break;
case V8_HEARTBEAT_DATA_PARAMETER_TAG:
dissect_heartbeat_data_parameter(parameter_tvb, parameter_tree, parameter_item);
break;
case V8_TRAFFIC_MODE_TYPE_PARAMETER_TAG:
dissect_traffic_mode_type_parameter(parameter_tvb, parameter_tree, parameter_item);
break;
case V8_ERROR_CODE_PARAMETER_TAG:
dissect_v8_error_code_parameter(parameter_tvb, parameter_tree, parameter_item);
break;
case V8_STATUS_PARAMETER_TAG:
dissect_status_type_parameter(parameter_tvb, parameter_tree, parameter_item);
break;
case V8_CONGESTION_LEVEL_PARAMETER_TAG:
dissect_congestion_level_parameter(parameter_tvb, parameter_tree, parameter_item);
break;
case V8_ASP_IDENTIFIER_PARAMETER_TAG:
dissect_asp_identifier_parameter(parameter_tvb, parameter_tree, parameter_item);
break;
case V8_AFFECTED_POINT_CODE_PARAMETER_TAG:
dissect_affected_destinations_parameter(parameter_tvb, parameter_tree, parameter_item);
break;
case V8_SS7_HOP_COUNTER_PARAMETER_TAG:
dissect_ss7_hop_counter_parameter(parameter_tvb, parameter_tree, parameter_item);
break;
case V8_SOURCE_ADDRESS_PARAMETER_TAG:
dissect_source_address_parameter(parameter_tvb, pinfo, parameter_tree, source_ssn);
break;
case V8_DESTINATION_ADDRESS_PARAMETER_TAG:
dissect_destination_address_parameter(parameter_tvb, pinfo, parameter_tree, dest_ssn);
break;
case V8_SOURCE_REFERENCE_NUMBER_PARAMETER_TAG:
dissect_source_reference_number_parameter(parameter_tvb, parameter_tree, parameter_item);
break;
case V8_DESTINATION_REFERENCE_NUMBER_PARAMETER_TAG:
dissect_destination_reference_number_parameter(parameter_tvb, parameter_tree, parameter_item);
break;
case V8_SCCP_CAUSE_PARAMETER_TAG:
dissect_sccp_cause_parameter(parameter_tvb, parameter_tree, parameter_item);
break;
case V8_SEQUENCE_NUMBER_PARAMETER_TAG:
dissect_sequence_number_parameter(parameter_tvb, parameter_tree);
break;
case V8_RECEIVE_SEQUENCE_NUMBER_PARAMETER_TAG:
dissect_receive_sequence_number_parameter(parameter_tvb, parameter_tree);
break;
case V8_ASP_CAPABILITIES_PARAMETER_TAG:
dissect_asp_capabilities_parameter(parameter_tvb, parameter_tree);
break;
case V8_CREDIT_PARAMETER_TAG:
dissect_credit_parameter(parameter_tvb, parameter_tree, parameter_item);
break;
case V8_USER_CAUSE_PARAMETER_TAG:
dissect_user_cause_parameter(parameter_tvb, parameter_tree);
break;
case V8_NETWORK_APPEARANCE_PARAMETER_TAG:
dissect_network_appearance_parameter(parameter_tvb, parameter_tree, parameter_item);
break;
case V8_ROUTING_KEY_PARAMETER_TAG:
dissect_routing_key_parameter(parameter_tvb, pinfo, parameter_tree);
break;
case V8_REGISTRATION_RESULT_PARAMETER_TAG:
dissect_registration_result_parameter(parameter_tvb, pinfo, parameter_tree);
break;
case V8_DEREGISTRATION_RESULT_PARAMETER_TAG:
dissect_deregistration_result_parameter(parameter_tvb, pinfo, parameter_tree);
break;
case V8_ADDRESS_RANGE_PARAMETER_TAG:
dissect_address_range_parameter(parameter_tvb, pinfo, parameter_tree);
break;
case V8_CORRELATION_ID_PARAMETER_TAG:
dissect_correlation_id_parameter(parameter_tvb, parameter_tree, parameter_item);
break;
case V8_IMPORTANCE_PARAMETER_TAG:
dissect_importance_parameter(parameter_tvb, parameter_tree, parameter_item);
break;
case V8_MESSAGE_PRIORITY_PARAMETER_TAG:
dissect_message_priority_parameter(parameter_tvb, parameter_tree, parameter_item);
break;
case V8_PROTOCOL_CLASS_PARAMETER_TAG:
dissect_protocol_class_parameter(parameter_tvb, parameter_tree, parameter_item);
break;
case V8_SEQUENCE_CONTROL_PARAMETER_TAG:
dissect_sequence_control_parameter(parameter_tvb, parameter_tree, parameter_item);
break;
case V8_SEGMENTATION_PARAMETER_TAG:
dissect_segmentation_parameter(parameter_tvb, parameter_tree);
break;
case V8_SMI_PARAMETER_TAG:
dissect_smi_parameter(parameter_tvb, parameter_tree, parameter_item);
break;
case V8_TID_LABEL_PARAMETER_TAG:
dissect_tid_label_parameter(parameter_tvb, parameter_tree);
break;
case V8_DRN_LABEL_PARAMETER_TAG:
dissect_drn_label_parameter(parameter_tvb, parameter_tree);
break;
case V8_GLOBAL_TITLE_PARAMETER_TAG:
dissect_global_title_parameter(parameter_tvb, parameter_tree, (source_ssn != NULL));
break;
case V8_POINT_CODE_PARAMETER_TAG:
dissect_point_code_parameter(parameter_tvb, parameter_tree, parameter_item, (source_ssn != NULL));
break;
case V8_SUBSYSTEM_NUMBER_PARAMETER_TAG:
dissect_ssn_parameter(parameter_tvb, parameter_tree, parameter_item, &ssn);
if(source_ssn)
{
*source_ssn = ssn;
}
if(dest_ssn)
{
*dest_ssn = ssn;
}
break;
case V8_IPV4_ADDRESS_PARAMETER_TAG:
dissect_ipv4_parameter(parameter_tvb, parameter_tree, parameter_item);
break;
case V8_HOSTNAME_PARAMETER_TAG:
dissect_hostname_parameter(parameter_tvb, parameter_tree, parameter_item);
break;
case V8_IPV6_ADDRESS_PARAMETER_TAG:
dissect_ipv6_parameter(parameter_tvb, parameter_tree, parameter_item);
break;
default:
dissect_unknown_parameter(parameter_tvb, parameter_tree, parameter_item);
break;
};
if (parameter_tree && (padding_length > 0))
proto_tree_add_item(parameter_tree, hf_sua_parameter_padding, parameter_tvb, PARAMETER_HEADER_OFFSET + length, padding_length, ENC_NA);
}
static void
dissect_parameter(tvbuff_t *parameter_tvb, packet_info *pinfo, proto_tree *tree, tvbuff_t **data_tvb, guint8 *source_ssn, guint8 *dest_ssn)
{
guint16 tag, length, padding_length;
proto_item *parameter_item;
proto_tree *parameter_tree;
guint8 ssn = INVALID_SSN;
const gchar *param_tag_str = NULL;
tag = tvb_get_ntohs(parameter_tvb, PARAMETER_TAG_OFFSET);
length = tvb_get_ntohs(parameter_tvb, PARAMETER_LENGTH_OFFSET);
padding_length = tvb_length(parameter_tvb) - length;
if (tree) {
param_tag_str = match_strval(tag, parameter_tag_values);
if(param_tag_str){
parameter_item = proto_tree_add_text(tree, parameter_tvb, PARAMETER_HEADER_OFFSET, tvb_length(parameter_tvb), "%s", param_tag_str);
}else{
if(dissector_try_uint(sua_parameter_table, tag, parameter_tvb, pinfo,tree)){
return;
}else{
parameter_item = proto_tree_add_text(tree, parameter_tvb, PARAMETER_HEADER_OFFSET, tvb_length(parameter_tvb), "Unknown parameter");
}
}
parameter_tree = proto_item_add_subtree(parameter_item, ett_sua_parameter);
proto_tree_add_item(parameter_tree, hf_sua_parameter_tag, parameter_tvb, PARAMETER_TAG_OFFSET, PARAMETER_TAG_LENGTH, ENC_BIG_ENDIAN);
proto_tree_add_item(parameter_tree, hf_sua_parameter_length, parameter_tvb, PARAMETER_LENGTH_OFFSET, PARAMETER_LENGTH_LENGTH, ENC_BIG_ENDIAN);
} else {
parameter_tree = NULL;
parameter_item = NULL;
}
if (!tree && tag != DATA_PARAMETER_TAG
&& tag != SOURCE_ADDRESS_PARAMETER_TAG
&& tag != DESTINATION_ADDRESS_PARAMETER_TAG
&& tag != POINT_CODE_PARAMETER_TAG
&& tag != GLOBAL_TITLE_PARAMETER_TAG
&& tag != DESTINATION_REFERENCE_NUMBER_PARAMETER_TAG
&& tag != SOURCE_REFERENCE_NUMBER_PARAMETER_TAG
&& tag != SUBSYSTEM_NUMBER_PARAMETER_TAG)
return;
switch(tag) {
case DATA_PARAMETER_TAG:
dissect_data_parameter(parameter_tvb, parameter_tree, parameter_item, data_tvb);
break;
case INFO_STRING_PARAMETER_TAG:
dissect_info_string_parameter(parameter_tvb, pinfo, parameter_tree, parameter_item);
break;
case ROUTING_CONTEXT_PARAMETER_TAG:
dissect_routing_context_parameter(parameter_tvb, parameter_tree, parameter_item);
break;
case DIAGNOSTIC_INFO_PARAMETER_TAG:
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
dissect_status_type_parameter(parameter_tvb, parameter_tree, parameter_item);
break;
case CONGESTION_LEVEL_PARAMETER_TAG:
dissect_congestion_level_parameter(parameter_tvb, parameter_tree, parameter_item);
break;
case ASP_IDENTIFIER_PARAMETER_TAG:
dissect_asp_identifier_parameter(parameter_tvb, parameter_tree, parameter_item);
break;
case AFFECTED_POINT_CODE_PARAMETER_TAG:
dissect_affected_destinations_parameter(parameter_tvb, parameter_tree, parameter_item);
break;
case REGISTRATION_STATUS_PARAMETER_TAG:
dissect_registration_status_parameter(parameter_tvb, parameter_tree, parameter_item);
break;
case DEREGISTRATION_STATUS_PARAMETER_TAG:
dissect_deregistration_status_parameter(parameter_tvb, parameter_tree, parameter_item);
break;
case LOCAL_ROUTING_KEY_IDENTIFIER_PARAMETER_TAG:
dissect_local_routing_key_identifier_parameter(parameter_tvb, parameter_tree, parameter_item);
break;
case SS7_HOP_COUNTER_PARAMETER_TAG:
dissect_ss7_hop_counter_parameter(parameter_tvb, parameter_tree, parameter_item);
break;
case SOURCE_ADDRESS_PARAMETER_TAG:
dissect_source_address_parameter(parameter_tvb, pinfo, parameter_tree, source_ssn);
break;
case DESTINATION_ADDRESS_PARAMETER_TAG:
dissect_destination_address_parameter(parameter_tvb, pinfo, parameter_tree, dest_ssn);
break;
case SOURCE_REFERENCE_NUMBER_PARAMETER_TAG:
dissect_source_reference_number_parameter(parameter_tvb, parameter_tree, parameter_item);
break;
case DESTINATION_REFERENCE_NUMBER_PARAMETER_TAG:
dissect_destination_reference_number_parameter(parameter_tvb, parameter_tree, parameter_item);
break;
case SCCP_CAUSE_PARAMETER_TAG:
dissect_sccp_cause_parameter(parameter_tvb, parameter_tree, parameter_item);
break;
case SEQUENCE_NUMBER_PARAMETER_TAG:
dissect_sequence_number_parameter(parameter_tvb, parameter_tree);
break;
case RECEIVE_SEQUENCE_NUMBER_PARAMETER_TAG:
dissect_receive_sequence_number_parameter(parameter_tvb, parameter_tree);
break;
case ASP_CAPABILITIES_PARAMETER_TAG:
dissect_asp_capabilities_parameter(parameter_tvb, parameter_tree);
break;
case CREDIT_PARAMETER_TAG:
dissect_credit_parameter(parameter_tvb, parameter_tree, parameter_item);
break;
case USER_CAUSE_PARAMETER_TAG:
dissect_user_cause_parameter(parameter_tvb, parameter_tree);
break;
case NETWORK_APPEARANCE_PARAMETER_TAG:
dissect_network_appearance_parameter(parameter_tvb, parameter_tree, parameter_item);
break;
case ROUTING_KEY_PARAMETER_TAG:
dissect_routing_key_parameter(parameter_tvb, pinfo, parameter_tree);
break;
case REGISTRATION_RESULT_PARAMETER_TAG:
dissect_registration_result_parameter(parameter_tvb, pinfo, parameter_tree);
break;
case DEREGISTRATION_RESULT_PARAMETER_TAG:
dissect_deregistration_result_parameter(parameter_tvb, pinfo, parameter_tree);
break;
case ADDRESS_RANGE_PARAMETER_TAG:
dissect_address_range_parameter(parameter_tvb, pinfo, parameter_tree);
break;
case CORRELATION_ID_PARAMETER_TAG:
dissect_correlation_id_parameter(parameter_tvb, parameter_tree, parameter_item);
break;
case IMPORTANCE_PARAMETER_TAG:
dissect_importance_parameter(parameter_tvb, parameter_tree, parameter_item);
break;
case MESSAGE_PRIORITY_PARAMETER_TAG:
dissect_message_priority_parameter(parameter_tvb, parameter_tree, parameter_item);
break;
case PROTOCOL_CLASS_PARAMETER_TAG:
dissect_protocol_class_parameter(parameter_tvb, parameter_tree, parameter_item);
break;
case SEQUENCE_CONTROL_PARAMETER_TAG:
dissect_sequence_control_parameter(parameter_tvb, parameter_tree, parameter_item);
break;
case SEGMENTATION_PARAMETER_TAG:
dissect_segmentation_parameter(parameter_tvb, parameter_tree);
break;
case SMI_PARAMETER_TAG:
dissect_smi_parameter(parameter_tvb, parameter_tree, parameter_item);
break;
case TID_LABEL_PARAMETER_TAG:
dissect_tid_label_parameter(parameter_tvb, parameter_tree);
break;
case DRN_LABEL_PARAMETER_TAG:
dissect_drn_label_parameter(parameter_tvb, parameter_tree);
break;
case GLOBAL_TITLE_PARAMETER_TAG:
dissect_global_title_parameter(parameter_tvb, parameter_tree, (source_ssn != NULL));
break;
case POINT_CODE_PARAMETER_TAG:
dissect_point_code_parameter(parameter_tvb, parameter_tree, parameter_item, (source_ssn != NULL));
break;
case SUBSYSTEM_NUMBER_PARAMETER_TAG:
dissect_ssn_parameter(parameter_tvb, parameter_tree, parameter_item, &ssn);
if(source_ssn)
{
*source_ssn = ssn;
}
if(dest_ssn)
{
*dest_ssn = ssn;
}
break;
case IPV4_ADDRESS_PARAMETER_TAG:
dissect_ipv4_parameter(parameter_tvb, parameter_tree, parameter_item);
break;
case HOSTNAME_PARAMETER_TAG:
dissect_hostname_parameter(parameter_tvb, parameter_tree, parameter_item);
break;
case IPV6_ADDRESS_PARAMETER_TAG:
dissect_ipv6_parameter(parameter_tvb, parameter_tree, parameter_item);
break;
default:
dissect_unknown_parameter(parameter_tvb, parameter_tree, parameter_item);
break;
};
if (parameter_tree && (padding_length > 0))
proto_tree_add_item(parameter_tree, hf_sua_parameter_padding, parameter_tvb, PARAMETER_HEADER_OFFSET + length, padding_length, ENC_NA);
}
static void
dissect_parameters(tvbuff_t *parameters_tvb, packet_info *pinfo, proto_tree *tree, tvbuff_t **data_tvb, guint8 *source_ssn, guint8 *dest_ssn)
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
case SUA_V08:
dissect_v8_parameter(parameter_tvb, pinfo, tree, data_tvb, source_ssn, dest_ssn);
break;
case SUA_RFC:
dissect_parameter(parameter_tvb, pinfo, tree, data_tvb, source_ssn, dest_ssn);
break;
}
offset += total_length;
}
}
static void
dissect_sua_message(tvbuff_t *message_tvb, packet_info *pinfo, proto_tree *sua_tree, proto_tree *tree)
{
tvbuff_t *common_header_tvb;
tvbuff_t *parameters_tvb;
tvbuff_t *data_tvb = NULL;
#if 0
proto_tree *assoc_tree;
#endif
guint8 source_ssn = INVALID_SSN;
guint8 dest_ssn = INVALID_SSN;
proto_item *assoc_item;
message_class = 0;
message_type = 0;
drn = 0;
srn = 0;
assoc = NULL;
no_sua_assoc.calling_dpc = 0;
no_sua_assoc.called_dpc = 0;
no_sua_assoc.calling_ssn = INVALID_SSN;
no_sua_assoc.called_ssn = INVALID_SSN;
no_sua_assoc.has_bw_key = FALSE;
no_sua_assoc.has_fw_key = FALSE;
sua_opc = ep_alloc0(sizeof(mtp3_addr_pc_t));
sua_dpc = ep_alloc0(sizeof(mtp3_addr_pc_t));
sua_source_gt = NULL;
sua_destination_gt = NULL;
common_header_tvb = tvb_new_subset(message_tvb, COMMON_HEADER_OFFSET, COMMON_HEADER_LENGTH, COMMON_HEADER_LENGTH);
dissect_common_header(common_header_tvb, pinfo, sua_tree);
parameters_tvb = tvb_new_subset_remaining(message_tvb, COMMON_HEADER_LENGTH);
dissect_parameters(parameters_tvb, pinfo, sua_tree, &data_tvb, &source_ssn, &dest_ssn);
if ( message_class == MESSAGE_CLASS_CO_MESSAGE) {
sccp_assoc_info_t* sccp_assoc;
reset_sccp_assoc();
switch (message_type){
case MESSAGE_TYPE_CORE:
assoc = sua_assoc(pinfo,&(pinfo->src),&(pinfo->dst), srn , drn);
if(assoc){
assoc->calling_routing_ind = sua_ri;
assoc->calling_ssn = source_ssn;
assoc->called_ssn = dest_ssn;
}
break;
case MESSAGE_TYPE_COAK:
assoc = sua_assoc(pinfo,&(pinfo->src),&(pinfo->dst), srn , drn);
if(assoc){
assoc->called_routing_ind = sua_ri;
if( (assoc->called_ssn != INVALID_SSN)&& (dest_ssn != INVALID_SSN)){
assoc->called_ssn = dest_ssn;
}
}
break;
default :
assoc = sua_assoc(pinfo,&(pinfo->src),&(pinfo->dst), srn , drn);
}
switch (message_type){
case MESSAGE_TYPE_CORE:
case MESSAGE_TYPE_COAK:
break;
default:
if( (assoc && assoc->called_ssn != INVALID_SSN)&& (dest_ssn != INVALID_SSN)){
dest_ssn = assoc->called_ssn;
}
if( (assoc && assoc->calling_ssn != INVALID_SSN)&& (source_ssn != INVALID_SSN)){
source_ssn = assoc->calling_ssn;
}
}
if (assoc && assoc->assoc_id !=0){
assoc_item = proto_tree_add_uint(tree, hf_sua_assoc_id, message_tvb, 0, 0, assoc->assoc_id);
PROTO_ITEM_SET_GENERATED(assoc_item);
#if 0
assoc_tree = proto_item_add_subtree(assoc_item, ett_sua_assoc);
proto_tree_add_text(assoc_tree, message_tvb, 0, 0, "routing_ind %u", assoc->calling_routing_ind);
proto_tree_add_text(assoc_tree, message_tvb, 0, 0, "routing_ind %u", assoc->called_routing_ind);
proto_tree_add_text(assoc_tree, message_tvb, 0, 0, "calling_ssn %u", assoc->calling_ssn);
proto_tree_add_text(assoc_tree, message_tvb, 0, 0, "called_ssn %u", assoc->called_ssn);
#endif
}
sccp_assoc = get_sccp_assoc(pinfo, tvb_offset_from_real_beginning(message_tvb), srn, drn, message_type);
if (sccp_assoc && sccp_assoc->curr_msg) {
pinfo->sccp_info = sccp_assoc->curr_msg;
tap_queue_packet(sua_tap,pinfo,sccp_assoc->curr_msg);
} else {
pinfo->sccp_info = NULL;
}
} else {
pinfo->sccp_info = NULL;
}
if (set_addresses) {
if (sua_opc->type)
SET_ADDRESS(&pinfo->src, AT_SS7PC, sizeof(mtp3_addr_pc_t), (guint8 *) sua_opc);
if (sua_dpc->type)
SET_ADDRESS(&pinfo->dst, AT_SS7PC, sizeof(mtp3_addr_pc_t), (guint8 *) sua_dpc);
if (sua_source_gt)
SET_ADDRESS(&pinfo->src, AT_STRINGZ, 1+(int)strlen(sua_source_gt), sua_source_gt);
if (sua_destination_gt)
SET_ADDRESS(&pinfo->dst, AT_STRINGZ, 1+(int)strlen(sua_destination_gt), sua_destination_gt);
}
if(data_tvb)
{
if ((dest_ssn == INVALID_SSN ||
!dissector_try_uint(sccp_ssn_dissector_table, dest_ssn, data_tvb, pinfo, tree))
&& (source_ssn == INVALID_SSN ||
!dissector_try_uint(sccp_ssn_dissector_table, source_ssn, data_tvb, pinfo, tree)))
{
if (dissector_try_heuristic(heur_subdissector_list, data_tvb, pinfo, tree)) {
return;
}
call_dissector(data_handle, data_tvb, pinfo, tree);
}
}
}
static void
dissect_sua(tvbuff_t *message_tvb, packet_info *pinfo, proto_tree *tree)
{
proto_item *sua_item;
proto_tree *sua_tree;
switch (version) {
case SUA_V08:
col_set_str(pinfo->cinfo, COL_PROTOCOL, "SUA (ID 08)");
break;
case SUA_RFC:
col_set_str(pinfo->cinfo, COL_PROTOCOL, "SUA (RFC 3868)");
break;
}
col_clear(pinfo->cinfo, COL_INFO);
if (tree) {
sua_item = proto_tree_add_item(tree, proto_sua, message_tvb, 0, -1, ENC_NA);
sua_tree = proto_item_add_subtree(sua_item, ett_sua);
} else {
sua_tree = NULL;
}
dissect_sua_message(message_tvb, pinfo, sua_tree, tree);
}
void
proto_register_sua(void)
{
static hf_register_info hf[] = {
{ &hf_sua_version, { "Version", "sua.version", FT_UINT8, BASE_DEC, VALS(protocol_version_values), 0x0, NULL, HFILL } },
{ &hf_sua_reserved, { "Reserved", "sua.reserved", FT_BYTES, BASE_NONE, NULL, 0x0, NULL, HFILL } },
{ &hf_sua_message_class, { "Message Class", "sua.message_class", FT_UINT8, BASE_DEC, VALS(message_class_values), 0x0, NULL, HFILL } },
{ &hf_sua_message_type, { "Message Type", "sua.message_type", FT_UINT8, BASE_DEC, NULL, 0x0, NULL, HFILL } },
{ &hf_sua_message_length, { "Message Length", "sua.message_length", FT_UINT32, BASE_DEC, NULL, 0x0, NULL, HFILL } },
{ &hf_sua_parameter_tag, { "Parameter Tag", "sua.parameter_tag", FT_UINT16, BASE_HEX, VALS(parameter_tag_values), 0x0, NULL, HFILL } },
{ &hf_sua_v8_parameter_tag, { "Parameter Tag", "sua.parameter_tag", FT_UINT16, BASE_HEX, VALS(v8_parameter_tag_values), 0x0, NULL, HFILL } },
{ &hf_sua_parameter_length, { "Parameter Length", "sua.parameter_length", FT_UINT16, BASE_DEC, NULL, 0x0, NULL, HFILL } },
{ &hf_sua_parameter_value, { "Parameter Value", "sua.parameter_value", FT_BYTES, BASE_NONE, NULL, 0x0, NULL, HFILL } },
{ &hf_sua_parameter_padding, { "Padding", "sua.parameter_padding", FT_BYTES, BASE_NONE, NULL, 0x0, NULL, HFILL } },
{ &hf_sua_info_string, { "Info string", "sua.info_string", FT_STRING, BASE_NONE, NULL, 0x0, NULL, HFILL } },
{ &hf_sua_routing_context, { "Routing context", "sua.routing_context", FT_UINT32, BASE_DEC, NULL, 0x0, NULL, HFILL } },
{ &hf_sua_diagnostic_information_info, { "Diagnostic Information", "sua.diagnostic_information", FT_BYTES, BASE_NONE, NULL, 0x0, NULL, HFILL } },
{ &hf_sua_heartbeat_data, { "Heartbeat Data", "sua.heartbeat_data", FT_BYTES, BASE_NONE, NULL, 0x0, NULL, HFILL } },
{ &hf_sua_traffic_mode_type, { "Traffic mode Type", "sua.traffic_mode_type", FT_UINT32, BASE_DEC, VALS(traffic_mode_type_values), 0x0, NULL, HFILL } },
{ &hf_sua_error_code, { "Error code", "sua.error_code", FT_UINT32, BASE_DEC, VALS(error_code_values), 0x0, NULL, HFILL } },
{ &hf_sua_v8_error_code, { "Error code", "sua.error_code", FT_UINT32, BASE_DEC, VALS(v8_error_code_values), 0x0, NULL, HFILL } },
{ &hf_sua_status_type, { "Status type", "sua.status_type", FT_UINT16, BASE_DEC, VALS(status_type_values), 0x0, NULL, HFILL } },
{ &hf_sua_status_info, { "Status info", "sua.status_info", FT_UINT16, BASE_DEC, NULL, 0x0, NULL, HFILL } },
{ &hf_sua_congestion_level, { "Congestion Level", "sua.congestion_level", FT_UINT32, BASE_DEC, NULL, 0x0, NULL, HFILL } },
{ &hf_sua_asp_identifier, { "ASP Identifier", "sua.asp_identifier", FT_UINT32, BASE_DEC, NULL, 0x0, NULL, HFILL } },
{ &hf_sua_mask, { "Mask", "sua.affected_point_code_mask", FT_UINT8, BASE_HEX, NULL, 0x0, NULL, HFILL } },
{ &hf_sua_dpc, { "Affected DPC", "sua.affected_pointcode_dpc", FT_UINT24, BASE_DEC, NULL, 0x0, NULL, HFILL } },
{ &hf_sua_registration_status, { "Registration status", "sua.registration_status", FT_UINT32, BASE_DEC, VALS(registration_status_values), 0x0, NULL, HFILL } },
{ &hf_sua_deregistration_status, { "Deregistration status", "sua.deregistration_status", FT_UINT32, BASE_DEC, VALS(deregistration_status_values), 0x0, NULL, HFILL } },
{ &hf_sua_local_routing_key_identifier, { "Local routing key identifier", "sua.local_routing_key_identifier", FT_UINT32, BASE_DEC, NULL, 0x0, NULL, HFILL } },
{ &hf_sua_source_address_routing_indicator, { "Routing Indicator", "sua.source_address_routing_indicator", FT_UINT16, BASE_DEC, VALS(routing_indicator_values), 0x0, NULL, HFILL } },
{ &hf_sua_source_address_reserved_bits, { "Reserved Bits", "sua.source_address_reserved_bits", FT_UINT16, BASE_DEC, NULL, ADDRESS_RESERVED_BITMASK, NULL, HFILL } },
{ &hf_sua_source_address_gt_bit, { "Include GT", "sua.source_address_gt_bit", FT_BOOLEAN, 16, NULL, ADDRESS_GT_BITMASK, NULL, HFILL } },
{ &hf_sua_source_address_pc_bit, { "Include PC", "sua.source_address_pc_bit", FT_BOOLEAN, 16, NULL, ADDRESS_PC_BITMASK, NULL, HFILL } },
{ &hf_sua_source_address_ssn_bit, { "Include SSN", "sua.source_address_ssn_bit", FT_BOOLEAN, 16, NULL, ADDRESS_SSN_BITMASK, NULL, HFILL } },
{ &hf_sua_destination_address_routing_indicator, { "Routing Indicator", "sua.destination_address_routing_indicator", FT_UINT16, BASE_DEC, VALS(routing_indicator_values), 0x0, NULL, HFILL } },
{ &hf_sua_destination_address_reserved_bits, { "Reserved Bits", "sua.destination_address_reserved_bits", FT_UINT16, BASE_DEC, NULL, ADDRESS_RESERVED_BITMASK, NULL, HFILL } },
{ &hf_sua_destination_address_gt_bit, { "Include GT", "sua.destination_address_gt_bit", FT_BOOLEAN, 16, NULL, ADDRESS_GT_BITMASK, NULL, HFILL } },
{ &hf_sua_destination_address_pc_bit, { "Include PC", "sua.destination_address_pc_bit", FT_BOOLEAN, 16, NULL, ADDRESS_PC_BITMASK, NULL, HFILL } },
{ &hf_sua_destination_address_ssn_bit, { "Include SSN", "sua.destination_address_ssn_bit", FT_BOOLEAN, 16, NULL, ADDRESS_SSN_BITMASK, NULL, HFILL } },
{ &hf_sua_ss7_hop_counter_counter, { "SS7 Hop Counter", "sua.ss7_hop_counter_counter", FT_UINT8, BASE_DEC, NULL, 0x0, NULL, HFILL } },
{ &hf_sua_ss7_hop_counter_reserved, { "Reserved", "sua.ss7_hop_counter_reserved", FT_BYTES, BASE_NONE, NULL, 0x0, NULL, HFILL } },
{ &hf_sua_destination_reference_number, { "Destination Reference Number", "sua.destination_reference_number", FT_UINT32, BASE_DEC, NULL, 0x0, NULL, HFILL } },
{ &hf_sua_source_reference_number, { "Source Reference Number", "sua.source_reference_number", FT_UINT32, BASE_DEC, NULL, 0x0, NULL, HFILL } },
{ &hf_sua_cause_reserved, { "Reserved", "sua.sccp_cause_reserved", FT_BYTES, BASE_NONE, NULL, 0x0, NULL, HFILL } },
{ &hf_sua_cause_type, { "Cause Type", "sua.sccp_cause_type", FT_UINT8, BASE_HEX, VALS(cause_type_values), 0x0, NULL, HFILL } },
{ &hf_sua_cause_value, { "Cause Value", "sua.sccp_cause_value", FT_UINT8, BASE_HEX, NULL, 0x0, NULL, HFILL } },
{ &hf_sua_sequence_number_reserved, { "Reserved", "sua.sequence_number_reserved", FT_BYTES, BASE_NONE, NULL, 0x0, NULL, HFILL } },
{ &hf_sua_sequence_number_rec_number, { "Receive Sequence Number P(R)", "sua.sequence_number_receive_sequence_number", FT_UINT8, BASE_DEC, NULL, SEQ_NUM_MASK, NULL, HFILL } },
{ &hf_sua_sequence_number_more_data_bit, { "More Data Bit", "sua.sequence_number_more_data_bit", FT_BOOLEAN, 8, TFS(&more_data_bit_value), MORE_DATA_BIT_MASK, NULL, HFILL } },
{ &hf_sua_sequence_number_sent_number, { "Sent Sequence Number P(S)", "sua.sequence_number_sent_sequence_number", FT_UINT8, BASE_DEC, NULL, SEQ_NUM_MASK, NULL, HFILL } },
{ &hf_sua_sequence_number_spare_bit, { "Spare Bit", "sua.sequence_number_spare_bit", FT_UINT8, BASE_DEC, NULL, SPARE_BIT_MASK, NULL, HFILL } },
{ &hf_sua_receive_sequence_number_reserved, { "Reserved", "sua.receive_sequence_number_reserved", FT_BYTES, BASE_NONE, NULL, 0x0, NULL, HFILL } },
{ &hf_sua_receive_sequence_number_number, { "Receive Sequence Number P(R)", "sua.receive_sequence_number_number", FT_UINT8, BASE_DEC, NULL, SEQ_NUM_MASK, NULL, HFILL } },
{ &hf_sua_receive_sequence_number_spare_bit, { "Spare Bit", "sua.receive_sequence_number_spare_bit", FT_UINT8, BASE_DEC, NULL, SPARE_BIT_MASK, NULL, HFILL } },
{ &hf_sua_asp_capabilities_reserved, { "Reserved", "sua.asp_capabilities_reserved", FT_BYTES, BASE_NONE, NULL, 0x0, NULL, HFILL } },
{ &hf_sua_asp_capabilities_reserved_bits, { "Reserved Bits", "sua.asp_capabilities_reserved_bits", FT_UINT8, BASE_HEX, NULL, RESERVED_BITS_MASK, NULL, HFILL } },
{ &hf_sua_asp_capabilities_a_bit, { "Protocol Class 3", "sua.asp_capabilities_a_bit", FT_BOOLEAN, 8, TFS(&tfs_supported_not_supported), A_BIT_MASK, NULL, HFILL } },
{ &hf_sua_asp_capabilities_b_bit, { "Protocol Class 2", "sua.asp_capabilities_b_bit", FT_BOOLEAN, 8, TFS(&tfs_supported_not_supported), B_BIT_MASK, NULL, HFILL } },
{ &hf_sua_asp_capabilities_c_bit, { "Protocol Class 1", "sua.asp_capabilities_c_bit", FT_BOOLEAN, 8, TFS(&tfs_supported_not_supported), C_BIT_MASK, NULL, HFILL } },
{ &hf_sua_asp_capabilities_d_bit, { "Protocol Class 0", "sua.asp_capabilities_d_bit", FT_BOOLEAN, 8, TFS(&tfs_supported_not_supported), D_BIT_MASK, NULL, HFILL } },
{ &hf_sua_asp_capabilities_interworking, { "Interworking", "sua.asp_capabilities_interworking", FT_UINT8, BASE_HEX, VALS(interworking_values), 0x0, NULL, HFILL } },
{ &hf_sua_credit, { "Credit", "sua.credit", FT_UINT32, BASE_DEC, NULL, 0x0, NULL, HFILL } },
{ &hf_sua_cause, { "Cause", "sua.cause_user_cause", FT_UINT16, BASE_DEC, VALS(cause_values), 0x0, NULL, HFILL } },
{ &hf_sua_user, { "User", "sua.cause_user_user", FT_UINT16, BASE_DEC, NULL, 0x0, NULL, HFILL } },
{ &hf_sua_data, { "Data", "sua.data", FT_BYTES, BASE_NONE, NULL, 0x0, NULL, HFILL } },
{ &hf_sua_network_appearance, { "Network Appearance", "sua.network_appearance", FT_UINT32, BASE_DEC, NULL, 0x0, NULL, HFILL } },
{ &hf_sua_routing_key_identifier, { "Local Routing Key Identifier", "sua.routing_key_identifier", FT_UINT32, BASE_HEX, NULL, 0x0, NULL, HFILL } },
{ &hf_sua_correlation_id, { "Correlation ID", "sua.correlation_id", FT_UINT32, BASE_DEC, NULL, 0x0, NULL, HFILL } },
{ &hf_sua_importance_reserved, { "Reserved", "sua.importance_reserved", FT_BYTES, BASE_NONE, NULL, 0x0, NULL, HFILL } },
{ &hf_sua_importance, { "Importance", "sua.importance_inportance", FT_UINT8, BASE_DEC, NULL, 0x0, NULL, HFILL } },
{ &hf_sua_message_priority_reserved, { "Reserved", "sua.message_priority_reserved", FT_BYTES, BASE_NONE, NULL, 0x0, NULL, HFILL } },
{ &hf_sua_message_priority, { "Message Priority", "sua.message_priority_priority", FT_UINT8, BASE_DEC, NULL, 0x0, NULL, HFILL } },
{ &hf_sua_protocol_class_reserved, { "Reserved", "sua.protcol_class_reserved", FT_BYTES, BASE_NONE, NULL, 0x0, NULL, HFILL } },
{ &hf_sua_return_on_error_bit, { "Return On Error Bit", "sua.protocol_class_return_on_error_bit", FT_BOOLEAN, 8, TFS(&return_on_error_bit_value), RETURN_ON_ERROR_BIT_MASK, NULL, HFILL } },
{ &hf_sua_protocol_class, { "Protocol Class", "sua.protocol_class_class", FT_UINT8, BASE_DEC, NULL, PROTOCOL_CLASS_MASK, NULL, HFILL } },
{ &hf_sua_sequence_control, { "Sequence Control", "sua.sequence_control_sequence_control", FT_UINT32, BASE_DEC, NULL, 0x0, NULL, HFILL } },
{ &hf_sua_first_bit, { "First Segment Bit", "sua.segmentation_first_bit", FT_BOOLEAN, 8, TFS(&first_bit_value), FIRST_BIT_MASK, NULL, HFILL } },
{ &hf_sua_number_of_remaining_segments, { "Number of Remaining Segments", "sua.segmentation_number_of_remaining_segments", FT_UINT8, BASE_DEC, NULL, NUMBER_OF_SEGMENTS_MASK, NULL, HFILL } },
{ &hf_sua_segmentation_reference, { "Segmentation Reference", "sua.segmentation_reference", FT_UINT24, BASE_DEC, NULL, 0x0, NULL, HFILL } },
{ &hf_sua_smi_reserved, { "Reserved", "sua.smi_reserved", FT_BYTES, BASE_NONE, NULL, 0x0, NULL, HFILL } },
{ &hf_sua_smi, { "SMI", "sua.smi_smi", FT_UINT8, BASE_DEC, NULL, 0x0, NULL, HFILL } },
{ &hf_sua_tid_label_start, { "Start", "sua.tid_label_start", FT_UINT8, BASE_DEC, NULL, 0x0, NULL, HFILL } },
{ &hf_sua_tid_label_end, { "End", "sua.tid_label_end", FT_UINT8, BASE_DEC, NULL, 0x0, NULL, HFILL } },
{ &hf_sua_tid_label_value, { "Label Value", "sua.tid_label_value", FT_UINT16, BASE_HEX, NULL, 0x0, NULL, HFILL } },
{ &hf_sua_drn_label_start, { "Start", "sua.drn_label_start", FT_UINT8, BASE_DEC, NULL, 0x0, NULL, HFILL } },
{ &hf_sua_drn_label_end, { "End", "sua.drn_label_end", FT_UINT8, BASE_DEC, NULL, 0x0, NULL, HFILL } },
{ &hf_sua_drn_label_value, { "Label Value", "sua.drn_label_value", FT_UINT16, BASE_HEX, NULL, 0x0, NULL, HFILL } },
{ &hf_sua_gt_reserved, { "Reserved", "sua.gt_reserved", FT_BYTES, BASE_NONE, NULL, 0x0, NULL, HFILL } },
{ &hf_sua_gti, { "GTI", "sua.gti", FT_UINT8, BASE_HEX, NULL, 0x0, NULL, HFILL } },
{ &hf_sua_number_of_digits, { "Number of Digits", "sua.global_title_number_of_digits", FT_UINT8, BASE_DEC, NULL, 0x0, NULL, HFILL } },
{ &hf_sua_translation_type, { "Translation Type", "sua.global_title_translation_type", FT_UINT8, BASE_HEX, NULL, 0x0, NULL, HFILL } },
{ &hf_sua_numbering_plan, { "Numbering Plan", "sua.global_title_numbering_plan", FT_UINT8, BASE_HEX, VALS(numbering_plan_values), 0x0, NULL, HFILL } },
{ &hf_sua_nature_of_address, { "Nature of Address", "sua.global_title_nature_of_address", FT_UINT8, BASE_HEX, VALS(nature_of_address_values), 0x0, NULL, HFILL } },
{ &hf_sua_global_title_digits, { "Global Title Digits", "sua.global_title_digits", FT_STRING, BASE_NONE, NULL, 0x0, NULL, HFILL } },
{ &hf_sua_point_code_dpc, { "Point Code", "sua.point_code", FT_UINT32, BASE_DEC, NULL, 0x0, NULL, HFILL } },
{ &hf_sua_ssn_reserved, { "Reserved", "sua.ssn_reserved", FT_BYTES, BASE_NONE, NULL, 0x0, NULL, HFILL } },
{ &hf_sua_ssn_number, { "Subsystem Number", "sua.ssn", FT_UINT8, BASE_DEC, NULL, 0x0, NULL, HFILL } },
{ &hf_sua_ipv4, { "IP Version 4 address", "sua.ipv4_address", FT_IPv4, BASE_NONE, NULL, 0x0, NULL, HFILL } },
{ &hf_sua_hostname, { "Hostname", "sua.hostname.name", FT_STRING, BASE_NONE, NULL, 0x0, NULL, HFILL } },
{ &hf_sua_ipv6, { "IP Version 6 address", "sua.ipv6_address", FT_IPv6, BASE_NONE, NULL, 0x0, NULL, HFILL } },
{ &hf_sua_assoc_id,
{ "Association ID", "sua.assoc.id",
FT_UINT32, BASE_DEC, NULL, 0x0, NULL, HFILL}},
{&hf_sua_assoc_msg,
{"Message in frame", "sua.assoc.msg",
FT_FRAMENUM, BASE_NONE, NULL, 0x00, NULL, HFILL }
},
};
static gint *ett[] = {
&ett_sua,
&ett_sua_parameter,
&ett_sua_source_address_indicator,
&ett_sua_destination_address_indicator,
&ett_sua_affected_destination,
&ett_sua_sequence_number_rec_number,
&ett_sua_sequence_number_sent_number,
&ett_sua_receive_sequence_number_number,
&ett_sua_protcol_classes,
&ett_sua_first_remaining,
&ett_sua_return_on_error_bit_and_protocol_class,
&ett_sua_assoc
};
module_t *sua_module;
static enum_val_t options[] = {
{ "draft-08", "Internet Draft version 08", SUA_V08 },
{ "rfc3868", "RFC 3868", SUA_RFC },
{ NULL, NULL, 0 }
};
proto_sua = proto_register_protocol("SS7 SCCP-User Adaptation Layer", "SUA", "sua");
register_dissector("sua", dissect_sua, proto_sua);
proto_register_field_array(proto_sua, hf, array_length(hf));
proto_register_subtree_array(ett, array_length(ett));
sua_module = prefs_register_protocol(proto_sua, NULL);
prefs_register_obsolete_preference(sua_module, "sua_version");
prefs_register_enum_preference(sua_module, "version", "SUA Version", "Version used by Wireshark", &version, options, FALSE);
prefs_register_bool_preference(sua_module, "set_addresses", "Set source and destination addresses",
"Set the source and destination addresses to the PC or GT digits, depending on the routing indicator."
" This may affect TCAP's ability to recognize which messages belong to which TCAP session.", &set_addresses);
register_heur_dissector_list("sua", &heur_subdissector_list);
sua_parameter_table = register_dissector_table("sua.prop.tags", "Proprietary SUA Tags", FT_UINT16, BASE_DEC);
sua_tap = register_tap("sua");
assocs = se_tree_create(EMEM_TREE_TYPE_RED_BLACK, "sua_associations");
}
void
proto_reg_handoff_sua(void)
{
dissector_handle_t sua_handle;
sua_handle = find_dissector("sua");
sua_info_str_handle = find_dissector("sua.infostring");
dissector_add_uint("sctp.ppi", SUA_PAYLOAD_PROTOCOL_ID, sua_handle);
dissector_add_uint("sctp.port", SCTP_PORT_SUA, sua_handle);
data_handle = find_dissector("data");
sccp_ssn_dissector_table = find_dissector_table("sccp.ssn");
}
