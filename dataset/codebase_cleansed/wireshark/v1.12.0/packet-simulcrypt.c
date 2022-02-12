static int
dissect_simulcrypt(tvbuff_t *tvb, packet_info *pinfo, proto_tree *tree, void* data)
{
tcp_dissect_pdus(tvb, pinfo, tree, TRUE, FRAME_HEADER_LEN,
get_simulcrypt_message_len, dissect_simulcrypt_message, data);
return tvb_length(tvb);
}
static guint16
get_interface (guint16 type)
{
int interface;
if (type >= 0x8000) {
return SIMULCRYPT_USER_DEFINED;
}
switch (type & 0xFFF0) {
case 0x0000:
case 0x0100:
case 0x0200:
interface = SIMULCRYPT_ECMG_SCS;
break;
case 0x0010:
case 0x0110:
case 0x0210:
interface = SIMULCRYPT_EMMG_MUX;
break;
case 0x0310:
case 0x0320:
interface = SIMULCRYPT_CPSIG_PSIG;
break;
case 0x0400:
interface = SIMULCRYPT_EIS_SCS;
break;
case 0x0410:
case 0x0420:
interface = SIMULCRYPT_PSIG_MUX;
break;
case 0x0430:
interface = SIMULCRYPT_MUX_CIM;
break;
case 0x0440:
interface = SIMULCRYPT_PSIG_CIP;
break;
default:
interface = SIMULCRYPT_RESERVED;
break;
}
return interface;
}
static void
dissect_ecmg_parameter_value (proto_tree *tree, tvbuff_t *tvb, packet_info *pinfo, guint32 offset,
guint16 plen, guint16 ptype, gchar *pvalue_char)
{
proto_item *simulcrypt_item;
proto_tree *simulcrypt_super_cas_id_tree;
proto_tree *simulcrypt_ecm_datagram_tree;
tvbuff_t *next_tvb;
guint32 pvaluedec;
int ca_system_id;
guint i;
switch (ptype) {
case SIMULCRYPT_ECMG_SUPER_CAS_ID:
simulcrypt_item = proto_tree_add_item(tree, hf_simulcrypt_super_cas_id, tvb, offset, plen, ENC_BIG_ENDIAN);
simulcrypt_super_cas_id_tree = proto_item_add_subtree(simulcrypt_item, ett_simulcrypt_super_cas_id);
simulcrypt_item = proto_tree_add_item(simulcrypt_super_cas_id_tree, hf_simulcrypt_ca_system_id, tvb, offset, 2, ENC_BIG_ENDIAN );
ca_system_id = tvb_get_ntohs(tvb,offset);
for(i=0;i<ECM_INTERPRETATION_SIZE;i++)
{
if(tab_ecm_inter[i].ca_system_id==ca_system_id)
{
tab_ecm_inter[i].ecmg_port=pinfo->destport;
proto_item_append_text(simulcrypt_item, ", Port %d, Protocol %s",tab_ecm_inter[i].ecmg_port, tab_ecm_inter[i].protocol_name);
break;
}
}
proto_tree_add_item(simulcrypt_super_cas_id_tree, hf_simulcrypt_ca_subsystem_id, tvb, offset+2, 2, ENC_BIG_ENDIAN );
break;
case SIMULCRYPT_ECMG_SECTION_TSPKT_FLAG:
proto_tree_add_item(tree, hf_simulcrypt_section_tspkt_flag, tvb, offset, plen, ENC_BIG_ENDIAN);
break;
case SIMULCRYPT_ECMG_ECM_CHANNEL_ID:
proto_tree_add_item(tree, hf_simulcrypt_ecm_channel_id, tvb, offset, plen, ENC_BIG_ENDIAN);
break;
case SIMULCRYPT_ECMG_DELAY_START:
simulcrypt_item = proto_tree_add_item(tree, hf_simulcrypt_delay_start, tvb, offset, plen, ENC_BIG_ENDIAN);
proto_item_append_text(simulcrypt_item, " ms");
break;
case SIMULCRYPT_ECMG_DELAY_STOP:
simulcrypt_item = proto_tree_add_item(tree, hf_simulcrypt_delay_stop, tvb, offset, plen, ENC_BIG_ENDIAN);
proto_item_append_text(simulcrypt_item, " ms");
break;
case SIMULCRYPT_ECMG_TRANSITION_DELAY_START:
simulcrypt_item = proto_tree_add_item(tree, hf_simulcrypt_transition_delay_start, tvb, offset, plen, ENC_BIG_ENDIAN);
proto_item_append_text(simulcrypt_item, " ms");
break;
case SIMULCRYPT_ECMG_TRANSITION_DELAY_STOP:
simulcrypt_item = proto_tree_add_item(tree, hf_simulcrypt_transition_delay_stop, tvb, offset, plen, ENC_BIG_ENDIAN);
proto_item_append_text(simulcrypt_item, " ms");
break;
case SIMULCRYPT_ECMG_AC_DELAY_START:
simulcrypt_item = proto_tree_add_item(tree, hf_simulcrypt_ac_delay_start, tvb, offset, plen, ENC_BIG_ENDIAN);
proto_item_append_text(simulcrypt_item, " ms");
break;
case SIMULCRYPT_ECMG_AC_DELAY_STOP:
simulcrypt_item = proto_tree_add_item(tree, hf_simulcrypt_ac_delay_stop, tvb, offset, plen, ENC_BIG_ENDIAN);
proto_item_append_text(simulcrypt_item, " ms");
break;
case SIMULCRYPT_ECMG_ECM_REP_PERIOD:
simulcrypt_item = proto_tree_add_item(tree, hf_simulcrypt_ecm_rep_period, tvb, offset, plen, ENC_BIG_ENDIAN);
proto_item_append_text(simulcrypt_item, " ms");
break;
case SIMULCRYPT_ECMG_MAX_STREAMS:
proto_tree_add_item(tree, hf_simulcrypt_max_streams, tvb, offset, plen, ENC_BIG_ENDIAN);
break;
case SIMULCRYPT_ECMG_MIN_CP_DURATION:
pvaluedec = tvb_get_ntohs(tvb, offset);
pvaluedec = pvaluedec*100;
simulcrypt_item = proto_tree_add_item(tree, hf_simulcrypt_min_cp_duration, tvb, offset, plen, ENC_BIG_ENDIAN);
proto_item_append_text(simulcrypt_item, " (%d ms)",pvaluedec);
break;
case SIMULCRYPT_ECMG_LEAD_CW:
proto_tree_add_item(tree, hf_simulcrypt_lead_cw, tvb, offset, plen, ENC_BIG_ENDIAN);
break;
case SIMULCRYPT_ECMG_CW_PER_MESSAGE:
proto_tree_add_item(tree, hf_simulcrypt_cw_per_msg, tvb, offset, plen, ENC_BIG_ENDIAN);
break;
case SIMULCRYPT_ECMG_MAX_COMP_TIME:
simulcrypt_item = proto_tree_add_item(tree, hf_simulcrypt_max_comp_time, tvb, offset, plen, ENC_BIG_ENDIAN);
proto_item_append_text(simulcrypt_item, " ms");
break;
case SIMULCRYPT_ECMG_ACCESS_CRITERIA:
proto_tree_add_item(tree, hf_simulcrypt_access_criteria, tvb, offset, plen, ENC_NA);
break;
case SIMULCRYPT_ECMG_ECM_STREAM_ID:
proto_tree_add_item(tree, hf_simulcrypt_ecm_stream_id, tvb, offset, plen, ENC_BIG_ENDIAN);
break;
case SIMULCRYPT_ECMG_NOMINAL_CP_DURATION:
pvaluedec = tvb_get_ntohs(tvb, offset);
pvaluedec = pvaluedec*100;
simulcrypt_item = proto_tree_add_item(tree, hf_simulcrypt_nominal_cp_duration, tvb, offset, plen, ENC_BIG_ENDIAN);
proto_item_append_text(simulcrypt_item, " (%d ms)", pvaluedec);
break;
case SIMULCRYPT_ECMG_ACCESS_CRITERIA_TRANSFER_MODE:
proto_tree_add_item(tree, hf_simulcrypt_access_criteria_transfer_mode, tvb, offset, plen, ENC_BIG_ENDIAN);
break;
case SIMULCRYPT_ECMG_CP_NUMBER:
proto_tree_add_item(tree, hf_simulcrypt_cp_number, tvb, offset, plen, ENC_BIG_ENDIAN);
break;
case SIMULCRYPT_ECMG_CP_DURATION:
pvaluedec = tvb_get_ntohs(tvb, offset);
pvaluedec = pvaluedec*100;
simulcrypt_item = proto_tree_add_item(tree, hf_simulcrypt_cp_duration, tvb, offset, plen, ENC_BIG_ENDIAN);
proto_item_append_text(simulcrypt_item, " (%d ms)", pvaluedec);
break;
case SIMULCRYPT_ECMG_CP_CW_COMBINATION:
proto_tree_add_item(tree, hf_simulcrypt_cp_cw_combination, tvb, offset, plen, ENC_NA);
break;
case SIMULCRYPT_ECMG_ECM_DATAGRAM:
simulcrypt_item = proto_tree_add_item(tree, hf_simulcrypt_ecm_datagram, tvb, offset, plen, ENC_NA);
for(i=0;i<ECM_INTERPRETATION_SIZE;i++)
{
if(tab_ecm_inter[i].ecmg_port==pinfo->srcport)
{
next_tvb = tvb_new_subset_remaining(tvb, offset);
simulcrypt_ecm_datagram_tree = proto_item_add_subtree(simulcrypt_item, ett_simulcrypt_ecm_datagram);
if(tab_ecm_inter[i].protocol_handle != NULL)
{
call_dissector(tab_ecm_inter[i].protocol_handle, next_tvb,pinfo, simulcrypt_ecm_datagram_tree);
}
break;
}
}
break;
case SIMULCRYPT_ECMG_CW_ENCRYPTION:
proto_tree_add_item(tree, hf_simulcrypt_cw_encryption, tvb, offset, plen, ENC_NA);
break;
case SIMULCRYPT_ECMG_ECM_ID:
proto_tree_add_item(tree, hf_simulcrypt_ecm_id, tvb, offset, plen, ENC_BIG_ENDIAN);
break;
case SIMULCRYPT_ECMG_ERROR_STATUS:
proto_tree_add_item(tree, hf_simulcrypt_ecmg_error_status, tvb, offset, plen, ENC_BIG_ENDIAN);
break;
case SIMULCRYPT_ECMG_ERROR_INFORMATION:
proto_tree_add_item(tree, hf_simulcrypt_error_information, tvb, offset, plen, ENC_NA);
break;
default:
proto_tree_add_text(tree, tvb, offset, plen, "Parameter Value: %s", pvalue_char);
break;
}
}
static void
dissect_emmg_parameter_value (proto_tree *tree, tvbuff_t *tvb, packet_info *pinfo _U_, guint32 offset,
guint16 plen, guint16 ptype, gchar *pvalue_char)
{
proto_item *simulcrypt_item;
switch (ptype) {
case SIMULCRYPT_EMMG_CLIENT_ID:
proto_tree_add_item(tree, hf_simulcrypt_client_id, tvb, offset, plen, ENC_BIG_ENDIAN);
break;
case SIMULCRYPT_EMMG_SECTION_TSPKT_FLAG:
proto_tree_add_item(tree, hf_simulcrypt_section_tspkt_flag, tvb, offset, plen, ENC_BIG_ENDIAN);
break;
case SIMULCRYPT_EMMG_DATA_CHANNEL_ID:
proto_tree_add_item(tree, hf_simulcrypt_data_channel_id, tvb, offset, plen, ENC_BIG_ENDIAN);
break;
case SIMULCRYPT_EMMG_DATA_STREAM_ID:
proto_tree_add_item(tree, hf_simulcrypt_data_stream_id, tvb, offset, plen, ENC_BIG_ENDIAN);
break;
case SIMULCRYPT_EMMG_DATAGRAM:
proto_tree_add_item(tree, hf_simulcrypt_datagram, tvb, offset, plen, ENC_NA);
break;
case SIMULCRYPT_EMMG_BANDWIDTH:
simulcrypt_item = proto_tree_add_item(tree, hf_simulcrypt_bandwidth, tvb, offset, plen, ENC_BIG_ENDIAN);
proto_item_append_text(simulcrypt_item, " kbit/s");
break;
case SIMULCRYPT_EMMG_DATA_TYPE:
proto_tree_add_item(tree, hf_simulcrypt_data_type, tvb, offset, plen, ENC_BIG_ENDIAN);
break;
case SIMULCRYPT_EMMG_DATA_ID:
proto_tree_add_item(tree, hf_simulcrypt_data_id, tvb, offset, plen, ENC_BIG_ENDIAN);
break;
case SIMULCRYPT_EMMG_ERROR_STATUS:
proto_tree_add_item(tree, hf_simulcrypt_emmg_error_status, tvb, offset, plen, ENC_BIG_ENDIAN);
break;
case SIMULCRYPT_EMMG_ERROR_INFORMATION:
proto_tree_add_item(tree, hf_simulcrypt_error_information, tvb, offset, plen, ENC_NA);
break;
default:
proto_tree_add_text(tree, tvb, offset, plen, "Parameter Value: %s", pvalue_char);
break;
}
}
static void
dissect_eis_parameter_value (proto_tree *tree, tvbuff_t *tvb, packet_info *pinfo _U_, guint32 offset,
guint16 plen, guint16 ptype, gchar *pvalue_char)
{
proto_item *simulcrypt_item;
proto_tree *simulcrypt_super_cas_id_tree;
proto_tree *simulcrypt_ecm_group_tree;
proto_tree *simulcrypt_activation_time_tree;
guint32 pvaluedec;
int ca_system_id;
guint i;
switch (ptype) {
case SIMULCRYPT_EIS_CHANNEL_ID:
proto_tree_add_item(tree, hf_simulcrypt_eis_channel_id, tvb, offset, plen, ENC_BIG_ENDIAN);
break;
case SIMULCRYPT_EIS_SERVICE_FLAG:
proto_tree_add_item(tree, hf_simulcrypt_service_flag, tvb, offset, plen, ENC_BIG_ENDIAN);
break;
case SIMULCRYPT_EIS_COMPONENT_FLAG:
proto_tree_add_item(tree, hf_simulcrypt_component_flag, tvb, offset, plen, ENC_BIG_ENDIAN);
break;
case SIMULCRYPT_EIS_MAX_SCG:
proto_tree_add_item(tree, hf_simulcrypt_max_scg, tvb, offset, plen, ENC_BIG_ENDIAN);
break;
case SIMULCRYPT_EIS_ECM_GROUP:
simulcrypt_item = proto_tree_add_item(tree, hf_simulcrypt_ecm_group, tvb, offset, plen, ENC_NA);
simulcrypt_ecm_group_tree = proto_item_add_subtree(simulcrypt_item, ett_simulcrypt_ecm_group);
dissect_simulcrypt_data(simulcrypt_ecm_group_tree, simulcrypt_item, pinfo, tvb, tree, offset, plen, SIMULCRYPT_EIS_SCS, TRUE);
break;
case SIMULCRYPT_EIS_SCG_ID:
proto_tree_add_item(tree, hf_simulcrypt_scg_id, tvb, offset, plen, ENC_BIG_ENDIAN);
break;
case SIMULCRYPT_EIS_SCG_REFERENCE_ID:
proto_tree_add_item(tree, hf_simulcrypt_scg_reference_id, tvb, offset, plen, ENC_BIG_ENDIAN);
break;
case SIMULCRYPT_EIS_SUPER_CAS_ID:
simulcrypt_item = proto_tree_add_item(tree, hf_simulcrypt_super_cas_id, tvb, offset, plen, ENC_BIG_ENDIAN);
simulcrypt_super_cas_id_tree = proto_item_add_subtree(simulcrypt_item, ett_simulcrypt_super_cas_id);
simulcrypt_item = proto_tree_add_item(simulcrypt_super_cas_id_tree, hf_simulcrypt_ca_system_id, tvb, offset, 2, ENC_BIG_ENDIAN );
ca_system_id = tvb_get_ntohs(tvb,offset);
for(i=0;i<ECM_INTERPRETATION_SIZE;i++)
{
if(tab_ecm_inter[i].ca_system_id==ca_system_id)
{
tab_ecm_inter[i].ecmg_port=pinfo->destport;
proto_item_append_text(simulcrypt_item, ", Port %d, Protocol %s",tab_ecm_inter[i].ecmg_port, tab_ecm_inter[i].protocol_name);
break;
}
}
proto_tree_add_item(simulcrypt_super_cas_id_tree, hf_simulcrypt_ca_subsystem_id, tvb, offset+2, 2, ENC_BIG_ENDIAN );
break;
case SIMULCRYPT_EIS_ECM_ID:
proto_tree_add_item(tree, hf_simulcrypt_ecm_id, tvb, offset, plen, ENC_BIG_ENDIAN);
break;
case SIMULCRYPT_EIS_ACCESS_CRITERIA:
proto_tree_add_item(tree, hf_simulcrypt_access_criteria, tvb, offset, plen, ENC_NA);
break;
case SIMULCRYPT_EIS_ACTIVATION_TIME:
simulcrypt_item = proto_tree_add_item(tree, hf_simulcrypt_activation_time, tvb, offset, plen, ENC_NA);
simulcrypt_activation_time_tree = proto_item_add_subtree(simulcrypt_item, ett_simulcrypt_activation_time);
proto_tree_add_item(simulcrypt_activation_time_tree, hf_simulcrypt_year, tvb, offset, 2, ENC_BIG_ENDIAN);
proto_tree_add_item(simulcrypt_activation_time_tree, hf_simulcrypt_month, tvb, offset+2, 1, ENC_BIG_ENDIAN);
proto_tree_add_item(simulcrypt_activation_time_tree, hf_simulcrypt_day, tvb, offset+3, 1, ENC_BIG_ENDIAN);
proto_tree_add_item(simulcrypt_activation_time_tree, hf_simulcrypt_hour, tvb, offset+4, 1, ENC_BIG_ENDIAN);
proto_tree_add_item(simulcrypt_activation_time_tree, hf_simulcrypt_minute, tvb, offset+5, 1, ENC_BIG_ENDIAN);
proto_tree_add_item(simulcrypt_activation_time_tree, hf_simulcrypt_second, tvb, offset+6, 1, ENC_BIG_ENDIAN);
proto_tree_add_item(simulcrypt_activation_time_tree, hf_simulcrypt_hundredth_second, tvb, offset+7, 1, ENC_BIG_ENDIAN);
break;
case SIMULCRYPT_EIS_ACTIVATION_PENDING_FLAG:
proto_tree_add_item(tree, hf_simulcrypt_activation_pending_flag, tvb, offset, plen, ENC_BIG_ENDIAN);
break;
case SIMULCRYPT_EIS_COMPONENT_ID:
proto_tree_add_item(tree, hf_simulcrypt_component_id, tvb, offset, plen, ENC_BIG_ENDIAN);
break;
case SIMULCRYPT_EIS_SERVICE_ID:
proto_tree_add_item(tree, hf_simulcrypt_service_id, tvb, offset, plen, ENC_BIG_ENDIAN);
break;
case SIMULCRYPT_EIS_TRANSPORT_STREAM_ID:
proto_tree_add_item(tree, hf_simulcrypt_transport_stream_id, tvb, offset, plen, ENC_BIG_ENDIAN);
break;
case SIMULCRYPT_EIS_AC_CHANGED_FLAG:
proto_tree_add_item(tree, hf_simulcrypt_ac_changed_flag, tvb, offset, plen, ENC_BIG_ENDIAN);
break;
case SIMULCRYPT_EIS_SCG_CURRENT_REFERENCE_ID:
proto_tree_add_item(tree, hf_simulcrypt_scg_current_reference_id, tvb, offset, plen, ENC_BIG_ENDIAN);
break;
case SIMULCRYPT_EIS_SCG_PENDING_REFERENCE_ID:
proto_tree_add_item(tree, hf_simulcrypt_scg_pending_reference_id, tvb, offset, plen, ENC_BIG_ENDIAN);
break;
case SIMULCRYPT_EIS_CP_DURATION_FLAG:
proto_tree_add_item(tree, hf_simulcrypt_cp_duration_flag, tvb, offset, plen, ENC_BIG_ENDIAN);
break;
case SIMULCRYPT_EIS_RECOMMENDED_CP_DURATION:
pvaluedec = tvb_get_ntohs(tvb, offset);
pvaluedec = pvaluedec*100;
simulcrypt_item = proto_tree_add_item(tree, hf_simulcrypt_recommended_cp_duration, tvb, offset, plen, ENC_BIG_ENDIAN);
proto_item_append_text(simulcrypt_item, " (%d ms)", pvaluedec);
break;
case SIMULCRYPT_EIS_SCG_NOMINAL_CP_DURATION:
pvaluedec = tvb_get_ntohs(tvb, offset);
pvaluedec = pvaluedec*100;
simulcrypt_item = proto_tree_add_item(tree, hf_simulcrypt_scg_nominal_cp_duration, tvb, offset, plen, ENC_BIG_ENDIAN);
proto_item_append_text(simulcrypt_item, " (%d ms)", pvaluedec);
break;
case SIMULCRYPT_EIS_ORIGINAL_NETWORK_ID:
proto_tree_add_item(tree, hf_simulcrypt_original_network_id, tvb, offset, plen, ENC_BIG_ENDIAN);
break;
case SIMULCRYPT_EIS_ERROR_STATUS:
proto_tree_add_item(tree, hf_simulcrypt_eis_error_status, tvb, offset, plen, ENC_BIG_ENDIAN);
break;
case SIMULCRYPT_EIS_ERROR_INFORMATION:
proto_tree_add_item(tree, hf_simulcrypt_error_information, tvb, offset, plen, ENC_NA);
break;
case SIMULCRYPT_EIS_ERROR_DESCRIPTION:
proto_tree_add_item(tree, hf_simulcrypt_error_description, tvb, offset, plen, ENC_ASCII|ENC_NA);
break;
default:
proto_tree_add_text(tree, tvb, offset, plen, "Parameter Value: %s", pvalue_char);
break;
}
}
static void
dissect_psig_parameter_value (proto_tree *tree, tvbuff_t *tvb, packet_info *pinfo _U_, guint32 offset,
guint16 plen, guint16 ptype, gchar *pvalue_char)
{
proto_tree *simulcrypt_psig_table_period_pair_tree;
proto_tree *simulcrypt_activation_time_tree;
proto_item *simulcrypt_item;
guint32 pvaluedec;
switch (ptype) {
case SIMULCRYPT_PSIG_PSIG_TYPE:
pvaluedec = tvb_get_guint8(tvb, offset);
simulcrypt_item = proto_tree_add_item(tree, hf_simulcrypt_psig_type, tvb, offset, plen, ENC_BIG_ENDIAN);
switch(pvaluedec){
case 1:
proto_item_append_text(simulcrypt_item, " (PSIG)");
break;
case 2:
proto_item_append_text(simulcrypt_item, " (SIG)");
break;
case 3:
proto_item_append_text(simulcrypt_item, " (PSISIG)");
break;
default:
break;
}
break;
case SIMULCRYPT_PSIG_CHANNEL_ID:
proto_tree_add_item(tree, hf_simulcrypt_channel_id, tvb, offset, plen, ENC_BIG_ENDIAN);
break;
case SIMULCRYPT_PSIG_STREAM_ID:
proto_tree_add_item(tree, hf_simulcrypt_stream_id, tvb, offset, plen, ENC_BIG_ENDIAN);
break;
case SIMULCRYPT_PSIG_TRANSPORT_STREAM_ID:
proto_tree_add_item(tree, hf_simulcrypt_transport_stream_id, tvb, offset, plen, ENC_BIG_ENDIAN);
break;
case SIMULCRYPT_PSIG_ORIGINAL_NETWORK_ID:
proto_tree_add_item(tree, hf_simulcrypt_original_network_id, tvb, offset, plen, ENC_BIG_ENDIAN);
break;
case SIMULCRYPT_PSIG_PACKET_ID:
proto_tree_add_item(tree, hf_simulcrypt_packet_id, tvb, offset, plen, ENC_BIG_ENDIAN);
break;
case SIMULCRYPT_PSIG_INTERFACE_MODE_CONFIGURATION:
proto_tree_add_item(tree, hf_simulcrypt_interface_mode_configuration, tvb, offset, plen, ENC_BIG_ENDIAN);
break;
case SIMULCRYPT_PSIG_MAX_STREAM:
proto_tree_add_item(tree, hf_simulcrypt_max_stream, tvb, offset, plen, ENC_BIG_ENDIAN);
break;
case SIMULCRYPT_PSIG_TABLE_PERIOD_PAIR:
simulcrypt_item = proto_tree_add_item(tree, hf_simulcrypt_table_period_pair, tvb, offset, plen, ENC_NA);
simulcrypt_psig_table_period_pair_tree = proto_item_add_subtree(simulcrypt_item, ett_simulcrypt_table_period_pair);
dissect_simulcrypt_data(simulcrypt_psig_table_period_pair_tree, simulcrypt_item, pinfo, tvb, tree, offset, plen, SIMULCRYPT_MUX_CIM, TRUE);
break;
case SIMULCRYPT_PSIG_MPEG_SECTION:
proto_tree_add_item(tree, hf_simulcrypt_mpeg_section, tvb, offset, plen, ENC_NA);
break;
case SIMULCRYPT_PSIG_REPETITION_RATE:
proto_tree_add_item(tree, hf_simulcrypt_repetition_rate, tvb, offset, plen, ENC_BIG_ENDIAN);
break;
case SIMULCRYPT_PSIG_ACTIVATION_TIME:
simulcrypt_item = proto_tree_add_item(tree, hf_simulcrypt_activation_time, tvb, offset, plen, ENC_NA);
simulcrypt_activation_time_tree = proto_item_add_subtree(simulcrypt_item, ett_simulcrypt_activation_time);
proto_tree_add_item(simulcrypt_activation_time_tree, hf_simulcrypt_year, tvb, offset, 2, ENC_BIG_ENDIAN);
proto_tree_add_item(simulcrypt_activation_time_tree, hf_simulcrypt_month, tvb, offset+2, 1, ENC_BIG_ENDIAN);
proto_tree_add_item(simulcrypt_activation_time_tree, hf_simulcrypt_day, tvb, offset+3, 1, ENC_BIG_ENDIAN);
proto_tree_add_item(simulcrypt_activation_time_tree, hf_simulcrypt_hour, tvb, offset+4, 1, ENC_BIG_ENDIAN);
proto_tree_add_item(simulcrypt_activation_time_tree, hf_simulcrypt_minute, tvb, offset+5, 1, ENC_BIG_ENDIAN);
proto_tree_add_item(simulcrypt_activation_time_tree, hf_simulcrypt_second, tvb, offset+6, 1, ENC_BIG_ENDIAN);
proto_tree_add_item(simulcrypt_activation_time_tree, hf_simulcrypt_hundredth_second, tvb, offset+7, 1, ENC_BIG_ENDIAN);
break;
case SIMULCRYPT_PSIG_DATAGRAM:
proto_tree_add_item(tree, hf_simulcrypt_datagram, tvb, offset, plen, ENC_NA);
break;
case SIMULCRYPT_PSIG_BANDWIDTH:
simulcrypt_item = proto_tree_add_item(tree, hf_simulcrypt_bandwidth, tvb, offset, plen, ENC_BIG_ENDIAN);
proto_item_append_text(simulcrypt_item, " kbit/s");
break;
case SIMULCRYPT_PSIG_INITIAL_BANDWIDTH:
simulcrypt_item = proto_tree_add_item(tree, hf_simulcrypt_initial_bandwidth, tvb, offset, plen, ENC_BIG_ENDIAN);
proto_item_append_text(simulcrypt_item, " kbit/s");
break;
case SIMULCRYPT_PSIG_MAX_COMP_TIME:
simulcrypt_item = proto_tree_add_item(tree, hf_simulcrypt_max_comp_time, tvb, offset, plen, ENC_BIG_ENDIAN);
proto_item_append_text(simulcrypt_item, " ms");
break;
case SIMULCRYPT_PSIG_ASI_INPUT_PACKET_ID:
proto_tree_add_item(tree, hf_simulcrypt_asi_input_packet_id, tvb, offset, plen, ENC_BIG_ENDIAN);
break;
case SIMULCRYPT_PSIG_ERROR_STATUS:
proto_tree_add_item(tree, hf_simulcrypt_psig_error_status, tvb, offset, plen, ENC_BIG_ENDIAN);
break;
case SIMULCRYPT_PSIG_ERROR_INFORMATION:
proto_tree_add_item(tree, hf_simulcrypt_error_information, tvb, offset, plen, ENC_NA);
break;
default:
proto_tree_add_text(tree, tvb, offset, plen, "Parameter Value: %s", pvalue_char);
break;
}
}
static int
dissect_simulcrypt_message(tvbuff_t *tvb, packet_info *pinfo, proto_tree *tree, void* data _U_)
{
proto_item *simulcrypt_item;
proto_tree *simulcrypt_tree;
proto_tree *simulcrypt_header_tree;
proto_tree *simulcrypt_message_tree;
guint16 type, iftype;
col_set_str(pinfo->cinfo, COL_PROTOCOL, PROTO_TAG_SIMULCRYPT);
col_clear(pinfo->cinfo,COL_INFO);
type = tvb_get_ntohs(tvb, 1);
iftype = get_interface (type);
col_add_fstr(pinfo->cinfo, COL_INFO, "%d > %d Info Type:[%s]",
pinfo->srcport, pinfo->destport,
val_to_str(type, messagetypenames, "Unknown Type:0x%02x"));
if (tree)
{
guint32 offset = 0;
guint32 msg_length;
simulcrypt_item = proto_tree_add_item(tree, proto_simulcrypt, tvb, 0, -1, ENC_NA);
simulcrypt_tree = proto_item_add_subtree(simulcrypt_item, ett_simulcrypt);
proto_item_append_text(simulcrypt_item, ", Interface: %s", val_to_str(iftype, interfacenames, "Unknown (0x%02x)"));
simulcrypt_item = proto_tree_add_item(simulcrypt_tree, hf_simulcrypt_header, tvb, offset, 5, ENC_NA );
simulcrypt_header_tree = proto_item_add_subtree(simulcrypt_item, ett_simulcrypt_header);
proto_item_append_text(simulcrypt_header_tree, ", Length: %s", "5 bytes");
proto_tree_add_item(simulcrypt_header_tree, hf_simulcrypt_version, tvb, offset, 1, ENC_BIG_ENDIAN);
offset+=1;
proto_tree_add_item(simulcrypt_header_tree, hf_simulcrypt_message_type, tvb, offset, 2, ENC_BIG_ENDIAN);
simulcrypt_item = proto_tree_add_uint_format_value(simulcrypt_header_tree, hf_simulcrypt_interface, tvb, offset, 2, iftype,
"%s", val_to_str_const(iftype, interfacenames, "Unknown"));
PROTO_ITEM_SET_GENERATED (simulcrypt_item);
offset+=2;
simulcrypt_item = proto_tree_add_item(simulcrypt_header_tree, hf_simulcrypt_message_length, tvb, offset, 2, ENC_BIG_ENDIAN);
proto_item_append_text(simulcrypt_item, " (bytes)");
msg_length = tvb_get_ntohs(tvb, offset);
offset+=2;
simulcrypt_item = proto_tree_add_item(simulcrypt_tree, hf_simulcrypt_message, tvb, offset, -1, ENC_NA );
simulcrypt_message_tree = proto_item_add_subtree(simulcrypt_item, ett_simulcrypt_message);
proto_item_append_text(simulcrypt_message_tree, " containing TLV parameters");
proto_item_append_text(simulcrypt_message_tree, ", Length: %d (bytes)", msg_length);
dissect_simulcrypt_data(simulcrypt_message_tree, simulcrypt_item, pinfo, tvb, tree, offset, (msg_length+5), iftype, FALSE);
}
return tvb_length(tvb);
}
static void
dissect_simulcrypt_data(proto_tree *simulcrypt_tree, proto_item *simulcrypt_item, packet_info *pinfo _U_,
tvbuff_t *tvb, proto_tree *tree, int offset,
int container_data_length, guint16 iftype, gboolean is_subtree)
{
int subtree_offset = 0;
proto_tree *simulcrypt_parameter_tree;
int applied_offset;
if(is_subtree)
{
applied_offset = subtree_offset;
}
else
{
applied_offset = offset;
}
while (applied_offset < container_data_length)
{
guint16 plen;
guint16 ptype;
gchar *pvalue_char;
ptype = tvb_get_ntohs(tvb, offset);
plen = tvb_get_ntohs(tvb, offset+2);
pvalue_char = tvb_bytes_to_ep_str(tvb, offset+4, plen);
simulcrypt_item = proto_tree_add_item(simulcrypt_tree, hf_simulcrypt_parameter, tvb, offset, plen+2+2, ENC_NA );
switch (iftype) {
case SIMULCRYPT_ECMG_SCS:
proto_item_append_text(simulcrypt_item, ": Type=%s", val_to_str(ptype, ecmg_parametertypenames, "Unknown Type:0x%02x"));
break;
case SIMULCRYPT_EMMG_MUX:
proto_item_append_text(simulcrypt_item, ": Type=%s", val_to_str(ptype, emmg_parametertypenames, "Unknown Type:0x%02x"));
break;
case SIMULCRYPT_EIS_SCS:
proto_item_append_text(simulcrypt_item, ": Type=%s", val_to_str(ptype, eis_parametertypenames, "Unknown Type:0x%02x"));
break;
case SIMULCRYPT_PSIG_MUX:
case SIMULCRYPT_MUX_CIM:
case SIMULCRYPT_PSIG_CIP:
proto_item_append_text(simulcrypt_item, ": Type=%s", val_to_str(ptype, psig_parametertypenames, "Unknown Type:0x%02x"));
break;
default:
proto_item_append_text(simulcrypt_item, ": Type=0x%02x", ptype);
break;
}
proto_item_append_text(simulcrypt_item, ", Value Length=%d (bytes)", plen);
proto_item_append_text(simulcrypt_item, ", Value=0x%s", pvalue_char);
simulcrypt_parameter_tree = proto_item_add_subtree(simulcrypt_item, ett_simulcrypt_parameter);
switch (iftype) {
case SIMULCRYPT_ECMG_SCS:
proto_tree_add_item(simulcrypt_parameter_tree, hf_simulcrypt_ecmg_parameter_type, tvb, offset, 2, ENC_BIG_ENDIAN);
break;
case SIMULCRYPT_EMMG_MUX:
proto_tree_add_item(simulcrypt_parameter_tree, hf_simulcrypt_emmg_parameter_type, tvb, offset, 2, ENC_BIG_ENDIAN);
break;
case SIMULCRYPT_EIS_SCS:
proto_tree_add_item(simulcrypt_parameter_tree, hf_simulcrypt_eis_parameter_type, tvb, offset, 2, ENC_BIG_ENDIAN);
break;
case SIMULCRYPT_PSIG_MUX:
case SIMULCRYPT_MUX_CIM:
case SIMULCRYPT_PSIG_CIP:
proto_tree_add_item(simulcrypt_parameter_tree, hf_simulcrypt_psig_parameter_type, tvb, offset, 2, ENC_BIG_ENDIAN);
break;
default:
proto_tree_add_item(simulcrypt_parameter_tree, hf_simulcrypt_parameter_type, tvb, offset, 2, ENC_BIG_ENDIAN);
break;
}
simulcrypt_item = proto_tree_add_item(simulcrypt_parameter_tree, hf_simulcrypt_parameter_length, tvb, offset+2, 2, ENC_BIG_ENDIAN);
proto_item_append_text(simulcrypt_item, " (bytes)");
offset += 2+2;
switch (iftype) {
case SIMULCRYPT_ECMG_SCS:
dissect_ecmg_parameter_value (simulcrypt_parameter_tree, tvb, pinfo, offset, plen, ptype, pvalue_char);
break;
case SIMULCRYPT_EMMG_MUX:
dissect_emmg_parameter_value (simulcrypt_parameter_tree, tvb, pinfo, offset, plen, ptype, pvalue_char);
break;
case SIMULCRYPT_EIS_SCS:
dissect_eis_parameter_value (simulcrypt_parameter_tree, tvb, pinfo, offset, plen, ptype, pvalue_char);
break;
case SIMULCRYPT_PSIG_MUX:
case SIMULCRYPT_MUX_CIM:
case SIMULCRYPT_PSIG_CIP:
dissect_psig_parameter_value (simulcrypt_parameter_tree, tvb, pinfo, offset, plen, ptype, pvalue_char);
break;
default:
proto_tree_add_text(tree, tvb, offset, plen, "Parameter Value: %s", pvalue_char);
break;
}
offset += plen;
subtree_offset += 2+2+plen;
if(is_subtree)
{
applied_offset = subtree_offset;
}
else
{
applied_offset = offset;
}
}
}
static guint
get_simulcrypt_message_len(packet_info *pinfo _U_, tvbuff_t *tvb, int offset)
{
guint iLg;
iLg = tvb_get_ntohs(tvb,offset+3);
iLg += 5;
return iLg;
}
static void
simulcrypt_init(void)
{
guint i;
for(i=0;i<ECM_INTERPRETATION_SIZE;i++)
{
tab_ecm_inter[i].ecmg_port = -1;
}
}
void
proto_register_simulcrypt (void)
{
static hf_register_info hf[] =
{
{ &hf_simulcrypt_header,
{ "Header", "simulcrypt.header", FT_NONE, BASE_NONE, NULL, 0x0,
NULL, HFILL }},
{ &hf_simulcrypt_version,
{ "Version", "simulcrypt.version", FT_UINT8, BASE_HEX, NULL, 0x0,
NULL, HFILL }},
{ &hf_simulcrypt_message_type,
{ "Message Type", "simulcrypt.message.type", FT_UINT16, BASE_HEX, VALS(messagetypenames), 0x0,
NULL, HFILL }},
{ &hf_simulcrypt_interface,
{ "Interface", "simulcrypt.message.interface", FT_UINT16, BASE_DEC, VALS(interfacenames), 0x0,
NULL, HFILL }},
{ &hf_simulcrypt_message_length,
{ "Message Length", "simulcrypt.message.len", FT_UINT16, BASE_DEC, NULL, 0x0,
NULL, HFILL }},
{ &hf_simulcrypt_message,
{ "Message", "simulcrypt.message", FT_NONE, BASE_NONE, NULL, 0x0,
NULL, HFILL }},
{ &hf_simulcrypt_parameter,
{ "Parameter", "simulcrypt.parameter", FT_NONE, BASE_NONE, NULL, 0x0,
NULL, HFILL }},
{ &hf_simulcrypt_parameter_type,
{ "Parameter Type", "simulcrypt.parameter.type", FT_UINT16, BASE_HEX, NULL, 0x0,
NULL, HFILL }},
{ &hf_simulcrypt_ecmg_parameter_type,
{ "Parameter Type", "simulcrypt.parameter.type", FT_UINT16, BASE_HEX, VALS(ecmg_parametertypenames), 0x0,
NULL, HFILL }},
{ &hf_simulcrypt_emmg_parameter_type,
{ "Parameter Type", "simulcrypt.parameter.type", FT_UINT16, BASE_HEX, VALS(emmg_parametertypenames), 0x0,
NULL, HFILL }},
{ &hf_simulcrypt_parameter_length,
{ "Parameter Length", "simulcrypt.parameter.len", FT_UINT16, BASE_DEC, NULL, 0x0,
NULL, HFILL }},
{ &hf_simulcrypt_ca_system_id,
{ "CA System ID", "simulcrypt.parameter.ca_system_id", FT_UINT16, BASE_DEC, NULL, 0x0,
NULL, HFILL }},
{ &hf_simulcrypt_ca_subsystem_id,
{ "CA Subsystem ID", "simulcrypt.parameter.ca_subsystem_id", FT_UINT16, BASE_DEC, NULL, 0x0,
NULL, HFILL }},
{ &hf_simulcrypt_super_cas_id,
{ "SuperCAS ID", "simulcrypt.super_cas_id", FT_UINT32, BASE_HEX, NULL, 0x0,
NULL, HFILL }},
{ &hf_simulcrypt_section_tspkt_flag,
{ "Section TS pkt flag", "simulcrypt.section_tspkt_flag", FT_UINT8, BASE_HEX, NULL, 0x0,
NULL, HFILL }},
{ &hf_simulcrypt_ecm_channel_id,
{ "ECM channel ID", "simulcrypt.ecm_channel_id", FT_UINT16, BASE_DEC, NULL, 0x0,
NULL, HFILL }},
{ &hf_simulcrypt_delay_start,
{ "Delay start", "simulcrypt.delay_start", FT_INT16, BASE_DEC, NULL, 0x0,
NULL, HFILL }},
{ &hf_simulcrypt_delay_stop,
{ "Delay stop", "simulcrypt.delay_stop", FT_INT16, BASE_DEC, NULL, 0x0,
NULL, HFILL }},
{ &hf_simulcrypt_ac_delay_start,
{ "AC delay start", "simulcrypt.ac_delay_start", FT_INT16, BASE_DEC, NULL, 0x0,
NULL, HFILL }},
{ &hf_simulcrypt_ac_delay_stop,
{ "AC delay stop", "simulcrypt.ac_delay_stop", FT_INT16, BASE_DEC, NULL, 0x0,
NULL, HFILL }},
{ &hf_simulcrypt_transition_delay_start,
{ "Transition delay start", "simulcrypt.transition_delay_start", FT_INT16, BASE_DEC, NULL, 0x0,
NULL, HFILL }},
{ &hf_simulcrypt_transition_delay_stop,
{ "Transition delay stop", "simulcrypt.transition_delay_stop", FT_INT16, BASE_DEC, NULL, 0x0,
NULL, HFILL }},
{ &hf_simulcrypt_ecm_rep_period,
{ "ECM repetition period", "simulcrypt.ecm_rep_period", FT_UINT16, BASE_DEC, NULL, 0x0,
NULL, HFILL }},
{ &hf_simulcrypt_max_streams,
{ "Max streams", "simulcrypt.max_streams", FT_UINT16, BASE_DEC, NULL, 0x0,
NULL, HFILL }},
{ &hf_simulcrypt_min_cp_duration,
{ "Min CP duration", "simulcrypt.min_cp_duration", FT_UINT16, BASE_DEC, NULL, 0x0,
NULL, HFILL }},
{ &hf_simulcrypt_lead_cw,
{ "Lead CW", "simulcrypt.lead_cw", FT_UINT8, BASE_DEC, NULL, 0x0,
NULL, HFILL }},
{ &hf_simulcrypt_cw_per_msg,
{ "CW per msg", "simulcrypt.cw_per_msg", FT_UINT8, BASE_DEC, NULL, 0x0,
NULL, HFILL }},
{ &hf_simulcrypt_max_comp_time,
{ "Max comp time", "simulcrypt.max_comp_time", FT_UINT16, BASE_DEC, NULL, 0x0,
NULL, HFILL }},
{ &hf_simulcrypt_access_criteria,
{ "Access criteria", "simulcrypt.access_criteria", FT_BYTES, BASE_NONE, NULL, 0x0,
NULL, HFILL }},
{ &hf_simulcrypt_ecm_stream_id,
{ "ECM stream ID", "simulcrypt.ecm_stream_id", FT_UINT16, BASE_DEC, NULL, 0x0,
NULL, HFILL }},
{ &hf_simulcrypt_nominal_cp_duration,
{ "Nominal CP duration", "simulcrypt.nominal_cp_duration", FT_UINT16, BASE_DEC, NULL, 0x0,
NULL, HFILL }},
{ &hf_simulcrypt_access_criteria_transfer_mode,
{ "AC transfer mode", "simulcrypt.access_criteria_transfer_mode", FT_BOOLEAN, BASE_NONE, NULL, 0x0,
NULL, HFILL }},
{ &hf_simulcrypt_cp_number,
{ "CP number", "simulcrypt.cp_number", FT_UINT16, BASE_DEC, NULL, 0x0,
NULL, HFILL }},
{ &hf_simulcrypt_cp_duration,
{ "CP duration", "simulcrypt.cp_duration", FT_UINT16, BASE_DEC, NULL, 0x0,
NULL, HFILL }},
{ &hf_simulcrypt_cp_cw_combination,
{ "CP CW combination", "simulcrypt.cp_cw_combination", FT_BYTES, BASE_NONE, NULL, 0x0,
NULL, HFILL }},
{ &hf_simulcrypt_ecm_datagram,
{ "ECM datagram", "simulcrypt.ecm_datagram", FT_BYTES, BASE_NONE, NULL, 0x0,
NULL, HFILL }},
{ &hf_simulcrypt_cw_encryption,
{ "CW encryption", "simulcrypt.cw_encryption", FT_NONE, BASE_NONE, NULL, 0x0,
NULL, HFILL }},
{ &hf_simulcrypt_ecm_id,
{ "ECM ID", "simulcrypt.ecm_id", FT_UINT16, BASE_DEC, NULL, 0x0,
NULL, HFILL }},
{ &hf_simulcrypt_client_id,
{ "Client ID", "simulcrypt.client_id", FT_UINT32, BASE_DEC, NULL, 0x0,
NULL, HFILL }},
{ &hf_simulcrypt_data_channel_id,
{ "Data Channel ID", "simulcrypt.data_channel_id", FT_UINT16, BASE_DEC, NULL, 0x0,
NULL, HFILL }},
{ &hf_simulcrypt_data_stream_id,
{ "Data Stream ID", "simulcrypt.data_stream_id", FT_UINT16, BASE_DEC, NULL, 0x0,
NULL, HFILL }},
{ &hf_simulcrypt_datagram,
{ "Datagram", "simulcrypt.datagram", FT_BYTES, BASE_NONE, NULL, 0x0,
NULL, HFILL }},
{ &hf_simulcrypt_bandwidth,
{ "Bandwidth", "simulcrypt.bandwidth", FT_UINT16, BASE_DEC, NULL, 0x0,
NULL, HFILL }},
{ &hf_simulcrypt_data_type,
{ "Data Type", "simulcrypt.data_type", FT_UINT8, BASE_DEC, NULL, 0x0,
NULL, HFILL }},
{ &hf_simulcrypt_data_id,
{ "Data ID", "simulcrypt.data_id", FT_UINT16, BASE_DEC, NULL, 0x0,
NULL, HFILL }},
{ &hf_simulcrypt_ecmg_error_status,
{ "Error status", "simulcrypt.error_status", FT_UINT16, BASE_DEC, VALS(ecmg_error_values), 0x0,
NULL, HFILL }},
{ &hf_simulcrypt_emmg_error_status,
{ "Error status", "simulcrypt.error_status", FT_UINT16, BASE_DEC, VALS(emmg_error_values), 0x0,
NULL, HFILL }},
{ &hf_simulcrypt_error_information,
{ "Error information", "simulcrypt.error_information", FT_BYTES, BASE_NONE, NULL, 0x0,
NULL, HFILL }},
{ &hf_simulcrypt_eis_parameter_type,
{ "Parameter Type", "simulcrypt.parameter.type", FT_UINT16, BASE_HEX, VALS(eis_parametertypenames), 0x0,
NULL, HFILL }},
{ &hf_simulcrypt_eis_channel_id,
{ "EIS channel ID", "simulcrypt.parameter.eis_channel_id", FT_UINT16, BASE_DEC, NULL, 0x0,
NULL, HFILL }},
{ &hf_simulcrypt_service_flag,
{ "Service flag", "simulcrypt.parameter.service_flag", FT_BOOLEAN, BASE_NONE, NULL, 0x0,
NULL, HFILL }},
{ &hf_simulcrypt_component_flag,
{ "Component flag", "simulcrypt.parameter.component_flag", FT_BOOLEAN, BASE_NONE, NULL, 0x0,
NULL, HFILL }},
{ &hf_simulcrypt_max_scg,
{ "Max SCG", "simulcrypt.parameter.max_scg", FT_UINT16, BASE_DEC, NULL, 0x0,
NULL, HFILL }},
{ &hf_simulcrypt_ecm_group,
{ "ECM group", "simulcrypt.parameter.ecm_group", FT_BYTES, BASE_NONE, NULL, 0x0,
NULL, HFILL }},
{ &hf_simulcrypt_scg_id,
{ "SCG ID", "simulcrypt.parameter.scg_id", FT_UINT16, BASE_DEC, NULL, 0x0,
NULL, HFILL }},
{ &hf_simulcrypt_scg_reference_id,
{ "SCG reference ID", "simulcrypt.parameter.scg_reference_id", FT_UINT32, BASE_DEC, NULL, 0x0,
NULL, HFILL }},
{ &hf_simulcrypt_activation_time,
{ "Activation time", "simulcrypt.parameter.activation_time", FT_BYTES, BASE_NONE, NULL, 0x0,
NULL, HFILL }},
{ &hf_simulcrypt_year,
{ "Year", "simulcrypt.parameter.year", FT_UINT16, BASE_DEC, NULL, 0x0,
NULL, HFILL }},
{ &hf_simulcrypt_month,
{ "Month", "simulcrypt.parameter.month", FT_UINT8, BASE_DEC, NULL, 0x0,
NULL, HFILL }},
{ &hf_simulcrypt_day,
{ "Day", "simulcrypt.parameter.day", FT_UINT8, BASE_DEC, NULL, 0x0,
NULL, HFILL }},
{ &hf_simulcrypt_hour,
{ "Hour", "simulcrypt.parameter.hour", FT_UINT8, BASE_DEC, NULL, 0x0,
NULL, HFILL }},
{ &hf_simulcrypt_minute,
{ "Minute", "simulcrypt.parameter.minute", FT_UINT8, BASE_DEC, NULL, 0x0,
NULL, HFILL }},
{ &hf_simulcrypt_second,
{ "Second", "simulcrypt.parameter.second", FT_UINT8, BASE_DEC, NULL, 0x0,
NULL, HFILL }},
{ &hf_simulcrypt_hundredth_second,
{ "Hundredth_second", "simulcrypt.parameter.hundredth_second", FT_UINT8, BASE_DEC, NULL, 0x0,
NULL, HFILL }},
{ &hf_simulcrypt_activation_pending_flag,
{ "Activation pending flag", "simulcrypt.parameter.activation_pending_flag", FT_BOOLEAN, BASE_NONE, NULL, 0x0,
NULL, HFILL }},
{ &hf_simulcrypt_component_id,
{ "Component ID", "simulcrypt.parameter.component_id", FT_UINT16, BASE_DEC, NULL, 0x0,
NULL, HFILL }},
{ &hf_simulcrypt_service_id,
{ "Service ID", "simulcrypt.parameter.service_id", FT_UINT16, BASE_DEC, NULL, 0x0,
NULL, HFILL }},
{ &hf_simulcrypt_transport_stream_id,
{ "Transport stream ID", "simulcrypt.parameter.transport_stream_id", FT_UINT16, BASE_DEC, NULL, 0x0,
NULL, HFILL }},
{ &hf_simulcrypt_ac_changed_flag,
{ "AC changed flag", "simulcrypt.parameter.ac_changed_flag", FT_BOOLEAN, BASE_NONE, NULL, 0x0,
NULL, HFILL }},
{ &hf_simulcrypt_scg_current_reference_id,
{ "SCG current reference ID", "simulcrypt.parameter.scg_current_reference_id", FT_UINT32, BASE_DEC, NULL, 0x0,
NULL, HFILL }},
{ &hf_simulcrypt_scg_pending_reference_id,
{ "SCG pending reference ID", "simulcrypt.parameter.scg_pending_reference_id", FT_UINT32, BASE_DEC, NULL, 0x0,
NULL, HFILL }},
{ &hf_simulcrypt_cp_duration_flag,
{ "CP duration flag", "simulcrypt.parameter.cp_duration_flag", FT_UINT8, BASE_DEC, NULL, 0x0,
NULL, HFILL }},
{ &hf_simulcrypt_recommended_cp_duration,
{ "Recommended CP duration", "simulcrypt.parameter.recommended_cp_duration", FT_UINT16, BASE_DEC, NULL, 0x0,
NULL, HFILL }},
{ &hf_simulcrypt_scg_nominal_cp_duration,
{ "SCG nominal CP duration", "simulcrypt.parameter.scg_nominal_cp_duration", FT_UINT16, BASE_DEC, NULL, 0x0,
NULL, HFILL }},
{ &hf_simulcrypt_original_network_id,
{ "Original network ID", "simulcrypt.parameter.original_network_id", FT_UINT16, BASE_DEC, NULL, 0x0,
NULL, HFILL }},
{ &hf_simulcrypt_eis_error_status,
{ "Error status", "simulcrypt.error_status", FT_UINT16, BASE_DEC, VALS(eis_error_values), 0x0,
NULL, HFILL }},
{ &hf_simulcrypt_error_description,
{ "Error status", "simulcrypt.error_description", FT_STRING, BASE_NONE, NULL, 0x0,
NULL, HFILL }},
{ &hf_simulcrypt_psig_parameter_type,
{ "Parameter Type", "simulcrypt.parameter.type", FT_UINT16, BASE_HEX, VALS(psig_parametertypenames), 0x0,
NULL, HFILL }},
{ &hf_simulcrypt_psig_type,
{ "PSIG type", "simulcrypt.parameter.psig_type", FT_UINT8, BASE_HEX, NULL, 0x0,
NULL, HFILL }},
{ &hf_simulcrypt_channel_id,
{ "Channel ID", "simulcrypt.parameter.channel_id", FT_UINT16, BASE_DEC, NULL, 0x0,
NULL, HFILL }},
{ &hf_simulcrypt_stream_id,
{ "Stream ID", "simulcrypt.parameter.stream_id", FT_UINT16, BASE_DEC, NULL, 0x0,
NULL, HFILL }},
{ &hf_simulcrypt_packet_id,
{ "Packet ID", "simulcrypt.parameter.packet_id", FT_UINT16, BASE_DEC, NULL, 0x0,
NULL, HFILL }},
{ &hf_simulcrypt_interface_mode_configuration,
{ "Interface mode configuration", "simulcrypt.parameter.interface_mode_configuration", FT_UINT8, BASE_HEX, NULL, 0x0,
NULL, HFILL }},
{ &hf_simulcrypt_max_stream,
{ "Max stream", "simulcrypt.parameter.max_stream", FT_UINT16, BASE_DEC, NULL, 0x0,
NULL, HFILL }},
{ &hf_simulcrypt_table_period_pair,
{ "Table period pair", "simulcrypt.parameter.table_period_pair", FT_BYTES, BASE_NONE, NULL, 0x0,
NULL, HFILL }},
{ &hf_simulcrypt_mpeg_section,
{ "MPEG section", "simulcrypt.parameter.mpeg_section", FT_BYTES, BASE_NONE, NULL, 0x0,
NULL, HFILL }},
{ &hf_simulcrypt_repetition_rate,
{ "Repetition rate", "simulcrypt.parameter.repetition_rate", FT_UINT32, BASE_DEC, NULL, 0x0,
NULL, HFILL }},
{ &hf_simulcrypt_initial_bandwidth,
{ "Initial bandwidth", "simulcrypt.parameter.initial_bandwidth", FT_UINT16, BASE_DEC, NULL, 0x0,
NULL, HFILL }},
{ &hf_simulcrypt_asi_input_packet_id,
{ "ASI input packet ID", "simulcrypt.parameter.asi_input_packet_id", FT_UINT16, BASE_DEC, NULL, 0x0,
NULL, HFILL }},
{ &hf_simulcrypt_psig_error_status,
{ "Error status", "simulcrypt.parameter.error_status", FT_UINT16, BASE_DEC, NULL, 0x0,
NULL, HFILL }}
};
static gint *ett[] =
{
&ett_simulcrypt,
&ett_simulcrypt_header,
&ett_simulcrypt_message,
&ett_simulcrypt_parameter,
&ett_simulcrypt_super_cas_id,
&ett_simulcrypt_ecm_datagram,
&ett_simulcrypt_ecm_group,
&ett_simulcrypt_activation_time,
&ett_simulcrypt_table_period_pair
};
module_t *simulcrypt_module;
proto_simulcrypt = proto_register_protocol ("SIMULCRYPT Protocol", "SIMULCRYPT", "simulcrypt");
proto_register_field_array (proto_simulcrypt, hf, array_length (hf));
proto_register_subtree_array (ett, array_length (ett));
register_init_routine(simulcrypt_init);
simulcrypt_module = prefs_register_protocol(proto_simulcrypt, proto_reg_handoff_simulcrypt);
prefs_register_uint_preference(simulcrypt_module, "tcp.port", "Simulcrypt TCP Port",
"Set the TCP port for Simulcrypt messages ('0' means no port is assigned)",
10, &global_simulcrypt_tcp_port);
prefs_register_uint_preference(simulcrypt_module, "udp.port", "Simulcrypt UDP Port",
"Set the UDP port for Simulcrypt messages ('0' means no port is assigned)",
10, &global_simulcrypt_udp_port);
prefs_register_uint_preference(simulcrypt_module, "ca_system_id_mikey","MIKEY ECM CA_system_ID (in hex)",
"Set the CA_system_ID used to decode ECM datagram as MIKEY", 16, &ca_system_id_mikey);
}
void
proto_reg_handoff_simulcrypt(void)
{
static gboolean initialized=FALSE;
static dissector_handle_t simulcrypt_handle;
static guint tcp_port, udp_port;
guint i;
if (!initialized) {
simulcrypt_handle = new_create_dissector_handle(dissect_simulcrypt, proto_simulcrypt);
for(i=0;i<ECM_INTERPRETATION_SIZE;i++)
{
tab_ecm_inter[i].protocol_handle = find_dissector(tab_ecm_inter[i].protocol_name);
}
dissector_add_handle("tcp.port", simulcrypt_handle);
dissector_add_handle("udp.port", simulcrypt_handle);
initialized = TRUE;
}
else {
dissector_delete_uint("tcp.port", tcp_port, simulcrypt_handle);
dissector_delete_uint("udp.port", udp_port, simulcrypt_handle);
}
if (global_simulcrypt_tcp_port != 0) {
dissector_add_uint("tcp.port", global_simulcrypt_tcp_port, simulcrypt_handle);
}
if (global_simulcrypt_udp_port != 0) {
dissector_add_uint("udp.port", global_simulcrypt_udp_port, simulcrypt_handle);
}
tcp_port = global_simulcrypt_tcp_port;
udp_port = global_simulcrypt_udp_port;
tab_ecm_inter[ECM_MIKEY_INDEX].ca_system_id=ca_system_id_mikey;
}
