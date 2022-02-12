static guint dissect_llrp_utf8_parameter(tvbuff_t * const tvb, packet_info *pinfo,
proto_tree * const tree, const guint hfindex, const guint offset)
{
gint len;
len = tvb_get_ntohs(tvb, offset);
if(tvb_reported_length_remaining(tvb, offset) < len) {
expert_add_info_format(pinfo, tree, &ei_llrp_invalid_length,
"invalid length of string: claimed %u, available %u.",
len, tvb_reported_length_remaining(tvb, offset));
return offset + 2;
}
proto_tree_add_item(tree, hfindex, tvb,
offset, 2, ENC_BIG_ENDIAN | ENC_UTF_8);
return offset + len + 2;
}
static guint dissect_llrp_bit_field(tvbuff_t * const tvb,
proto_tree * const tree, const guint hfindex, const guint offset)
{
guint len;
len = tvb_get_ntohs(tvb, offset);
len = (len + 7) / 8;
proto_tree_add_item(tree, hf_llrp_length_bits, tvb,
offset, 2, ENC_BIG_ENDIAN);
proto_tree_add_item(tree, hfindex, tvb,
offset + 2, len, ENC_NA);
return offset + len + 2;
}
static guint dissect_llrp_word_array(tvbuff_t * const tvb,
proto_tree * const tree, const guint hfindex, const guint offset)
{
guint len;
len = tvb_get_ntohs(tvb, offset);
len *= 2;
proto_tree_add_item(tree, hf_llrp_length_words, tvb,
offset, 2, ENC_BIG_ENDIAN);
proto_tree_add_item(tree, hfindex, tvb,
offset + 2, len, ENC_NA);
return offset + len + 2;
}
static guint dissect_llrp_item_array(tvbuff_t * const tvb, packet_info *pinfo,
proto_tree * const tree, const guint hfindex_number,
const guint hfindex_item, const guint item_size, guint offset)
{
guint num;
num = tvb_get_ntohs(tvb, offset);
proto_tree_add_item(tree, hfindex_number, tvb,
offset, 2, ENC_BIG_ENDIAN);
offset += 2;
if(tvb_reported_length_remaining(tvb, offset) < ((gint)(num*item_size))) {
expert_add_info_format(pinfo, tree, &ei_llrp_invalid_length,
"Array longer than message");
return offset + tvb_reported_length_remaining(tvb, offset);
}
while(num--) {
proto_tree_add_item(tree, hfindex_item, tvb,
offset, item_size, item_size == 1 ? ENC_NA : ENC_BIG_ENDIAN);
offset += item_size;
}
return offset;
}
static guint
dissect_llrp_impinj_parameter(tvbuff_t *tvb, packet_info *pinfo, proto_tree *param_tree,
guint suboffset, const guint param_end)
{
guint32 subtype;
subtype = tvb_get_ntohl(tvb, suboffset);
proto_item_append_text(param_tree, " (Impinj - %s)",
val_to_str_ext(subtype, &impinj_param_type_ext, "Unknown Type: %d"));
proto_tree_add_item(param_tree, hf_llrp_impinj_param_type, tvb, suboffset, 4, ENC_BIG_ENDIAN);
suboffset += 4;
switch(subtype) {
case LLRP_IMPINJ_PARAM_TAG_INFORMATION:
case LLRP_IMPINJ_PARAM_FORKLIFT_CONFIGURATION:
case LLRP_IMPINJ_PARAM_ACCESS_SPEC_CONFIGURATION:
case LLRP_IMPINJ_PARAM_TAG_REPORT_CONTENT_SELECTOR:
case LLRP_IMPINJ_PARAM_GPS_NMEA_SENTENCES:
case LLRP_IMPINJ_PARAM_HUB_VERSIONS:
break;
case LLRP_IMPINJ_PARAM_REQUESTED_DATA:
PARAM_TREE_ADD(impinj_req_data, 4, ENC_BIG_ENDIAN);
break;
case LLRP_IMPINJ_PARAM_SUBREGULATORY_REGION:
PARAM_TREE_ADD(impinj_reg_region, 2, ENC_BIG_ENDIAN);
break;
case LLRP_IMPINJ_PARAM_INVENTORY_SEARCH_MODE:
PARAM_TREE_ADD(impinj_search_mode, 2, ENC_BIG_ENDIAN);
break;
case LLRP_IMPINJ_PARAM_TAG_DIRECTION_REPORTING:
PARAM_TREE_ADD(impinj_en_tag_dir, 2, ENC_NA);
PARAM_TREE_ADD(impinj_antenna_conf, 2, ENC_BIG_ENDIAN);
PARAM_TREE_ADD(rfu, 4, ENC_NA);
break;
case LLRP_IMPINJ_PARAM_TAG_DIRECTION:
PARAM_TREE_ADD(decision_time, 8, ENC_BIG_ENDIAN);
PARAM_TREE_ADD(impinj_tag_dir, 2, ENC_BIG_ENDIAN);
PARAM_TREE_ADD(confidence, 2, ENC_BIG_ENDIAN);
break;
case LLRP_IMPINJ_PARAM_FIXED_FREQUENCY_LIST:
PARAM_TREE_ADD(impinj_fix_freq_mode, 2, ENC_BIG_ENDIAN);
PARAM_TREE_ADD(rfu, 2, ENC_NA);
suboffset = dissect_llrp_item_array(tvb, pinfo, param_tree,
hf_llrp_num_channels, hf_llrp_channel, 2, suboffset);
break;
case LLRP_IMPINJ_PARAM_REDUCED_POWER_FREQUENCY_LIST:
PARAM_TREE_ADD(impinj_reduce_power_mode, 2, ENC_BIG_ENDIAN);
PARAM_TREE_ADD(rfu, 2, ENC_NA);
suboffset = dissect_llrp_item_array(tvb, pinfo, param_tree,
hf_llrp_num_channels, hf_llrp_channel, 2, suboffset);
break;
case LLRP_IMPINJ_PARAM_LOW_DUTY_CYCLE:
PARAM_TREE_ADD(impinj_low_duty_mode, 2, ENC_BIG_ENDIAN);
PARAM_TREE_ADD(empty_field_timeout, 2, ENC_BIG_ENDIAN);
PARAM_TREE_ADD(field_ping_interval, 2, ENC_BIG_ENDIAN);
break;
case LLRP_IMPINJ_PARAM_DETAILED_VERSION:
suboffset = dissect_llrp_utf8_parameter(tvb, pinfo, param_tree, hf_llrp_model_name, suboffset);
suboffset = dissect_llrp_utf8_parameter(tvb, pinfo, param_tree, hf_llrp_serial_number, suboffset);
suboffset = dissect_llrp_utf8_parameter(tvb, pinfo, param_tree, hf_llrp_soft_ver, suboffset);
suboffset = dissect_llrp_utf8_parameter(tvb, pinfo, param_tree, hf_llrp_firm_ver, suboffset);
suboffset = dissect_llrp_utf8_parameter(tvb, pinfo, param_tree, hf_llrp_fpga_ver, suboffset);
suboffset = dissect_llrp_utf8_parameter(tvb, pinfo, param_tree, hf_llrp_pcba_ver, suboffset);
break;
case LLRP_IMPINJ_PARAM_FREQUENCY_CAPABILITIES:
suboffset = dissect_llrp_item_array(tvb, pinfo, param_tree,
hf_llrp_num_freqs, hf_llrp_frequency, 4, suboffset);
break;
case LLRP_IMPINJ_PARAM_FORKLIFT_HEIGHT_THRESHOLD:
PARAM_TREE_ADD(height_thresh, 2, ENC_BIG_ENDIAN);
break;
case LLRP_IMPINJ_PARAM_FORKLIFT_ZEROMOTION_TIME_THRESHOLD:
PARAM_TREE_ADD(zero_motion_thresh, 2, ENC_BIG_ENDIAN);
break;
case LLRP_IMPINJ_PARAM_FORKLIFT_COMPANION_BOARD_INFO:
suboffset = dissect_llrp_utf8_parameter(tvb, pinfo, param_tree, hf_llrp_board_manufacturer, suboffset);
PARAM_TREE_ADD(fw_ver_hex, 2, ENC_BIG_ENDIAN);
PARAM_TREE_ADD(hw_ver_hex, 2, ENC_BIG_ENDIAN);
break;
case LLRP_IMPINJ_PARAM_GPI_DEBOUNCE_CONFIGURATION:
PARAM_TREE_ADD(gpi_port, 2, ENC_BIG_ENDIAN);
PARAM_TREE_ADD(gpi_debounce, 4, ENC_BIG_ENDIAN);
break;
case LLRP_IMPINJ_PARAM_READER_TEMPERATURE:
PARAM_TREE_ADD(temperature, 2, ENC_BIG_ENDIAN);
break;
case LLRP_IMPINJ_PARAM_LINK_MONITOR_CONFIGURATION:
PARAM_TREE_ADD(impinj_link_monitor_mode, 2, ENC_BIG_ENDIAN);
PARAM_TREE_ADD(link_down_thresh, 2, ENC_BIG_ENDIAN);
break;
case LLRP_IMPINJ_PARAM_REPORT_BUFFER_CONFIGURATION:
PARAM_TREE_ADD(impinj_report_buff_mode, 2, ENC_BIG_ENDIAN);
break;
case LLRP_IMPINJ_PARAM_BLOCK_WRITE_WORD_COUNT:
PARAM_TREE_ADD(word_count, 2, ENC_BIG_ENDIAN);
break;
case LLRP_IMPINJ_PARAM_BLOCK_PERMALOCK:
PARAM_TREE_ADD(opspec_id, 2, ENC_BIG_ENDIAN);
PARAM_TREE_ADD(access_pass, 4, ENC_BIG_ENDIAN);
PARAM_TREE_ADD(mb, 1, ENC_NA);
PARAM_TREE_ADD(block_pointer, 2, ENC_BIG_ENDIAN);
PARAM_TREE_ADD(block_mask, 2, ENC_BIG_ENDIAN);
break;
case LLRP_IMPINJ_PARAM_BLOCK_PERMALOCK_OPSPEC_RESULT:
PARAM_TREE_ADD(permalock_result, 1, ENC_NA);
PARAM_TREE_ADD(opspec_id, 2, ENC_BIG_ENDIAN);
break;
case LLRP_IMPINJ_PARAM_GET_BLOCK_PERMALOCK_STATUS:
PARAM_TREE_ADD(opspec_id, 2, ENC_BIG_ENDIAN);
PARAM_TREE_ADD(access_pass, 4, ENC_BIG_ENDIAN);
PARAM_TREE_ADD(mb, 1, ENC_NA);
PARAM_TREE_ADD(block_pointer, 2, ENC_BIG_ENDIAN);
PARAM_TREE_ADD(block_range, 2, ENC_BIG_ENDIAN);
break;
case LLRP_IMPINJ_PARAM_GET_BLOCK_PERMALOCK_STATUS_OPSPEC_RESULT:
PARAM_TREE_ADD(block_permalock_result, 1, ENC_NA);
PARAM_TREE_ADD(opspec_id, 2, ENC_BIG_ENDIAN);
break;
case LLRP_IMPINJ_PARAM_SET_QT_CONFIG:
PARAM_TREE_ADD(opspec_id, 2, ENC_BIG_ENDIAN);
PARAM_TREE_ADD(access_pass, 4, ENC_BIG_ENDIAN);
PARAM_TREE_ADD(impinj_data_profile, 1, ENC_NA);
PARAM_TREE_ADD(impinj_access_range, 1, ENC_NA);
PARAM_TREE_ADD(impinj_persistence, 1, ENC_NA);
PARAM_TREE_ADD(rfu, 4, ENC_BIG_ENDIAN);
break;
case LLRP_IMPINJ_PARAM_SET_QT_CONFIG_OPSPEC_RESULT:
PARAM_TREE_ADD(set_qt_config_result, 1, ENC_NA);
PARAM_TREE_ADD(opspec_id, 2, ENC_BIG_ENDIAN);
break;
case LLRP_IMPINJ_PARAM_GET_QT_CONFIG:
PARAM_TREE_ADD(opspec_id, 2, ENC_BIG_ENDIAN);
PARAM_TREE_ADD(access_pass, 4, ENC_BIG_ENDIAN);
break;
case LLRP_IMPINJ_PARAM_GET_QT_CONFIG_OPSPEC_RESULT:
PARAM_TREE_ADD(get_qt_config_result, 1, ENC_NA);
PARAM_TREE_ADD(opspec_id, 2, ENC_BIG_ENDIAN);
PARAM_TREE_ADD(impinj_data_profile, 1, ENC_NA);
PARAM_TREE_ADD(impinj_access_range, 1, ENC_NA);
PARAM_TREE_ADD(rfu, 4, ENC_BIG_ENDIAN);
break;
case LLRP_IMPINJ_PARAM_ENABLE_SERIALIZED_TID:
PARAM_TREE_ADD(impinj_serialized_tid_mode, 2, ENC_BIG_ENDIAN);
break;
case LLRP_IMPINJ_PARAM_ENABLE_RF_PHASE_ANGLE:
PARAM_TREE_ADD(impinj_rf_phase_mode, 2, ENC_BIG_ENDIAN);
break;
case LLRP_IMPINJ_PARAM_ENABLE_PEAK_RSSI:
PARAM_TREE_ADD(impinj_peak_rssi_mode, 2, ENC_BIG_ENDIAN);
break;
case LLRP_IMPINJ_PARAM_ENABLE_GPS_COORDINATES:
PARAM_TREE_ADD(impinj_gps_coordinates_mode, 2, ENC_BIG_ENDIAN);
break;
case LLRP_IMPINJ_PARAM_SERIALIZED_TID:
PARAM_TREE_ADD(impinj_tid, 2, ENC_BIG_ENDIAN);
break;
case LLRP_IMPINJ_PARAM_RF_PHASE_ANGLE:
PARAM_TREE_ADD(phase_angle, 2, ENC_BIG_ENDIAN);
break;
case LLRP_IMPINJ_PARAM_PEAK_RSSI:
PARAM_TREE_ADD(rssi, 2, ENC_BIG_ENDIAN);
break;
case LLRP_IMPINJ_PARAM_GPS_COORDINATES:
PARAM_TREE_ADD(latitude, 4, ENC_BIG_ENDIAN);
PARAM_TREE_ADD(longitude, 4, ENC_BIG_ENDIAN);
break;
case LLRP_IMPINJ_PARAM_LOOP_SPEC:
PARAM_TREE_ADD(loop_count, 4, ENC_BIG_ENDIAN);
break;
case LLRP_IMPINJ_PARAM_GGA_SENTENCE:
suboffset = dissect_llrp_utf8_parameter(tvb, pinfo, param_tree, hf_llrp_gga_sentence, suboffset);
break;
case LLRP_IMPINJ_PARAM_RMC_SENTENCE:
suboffset = dissect_llrp_utf8_parameter(tvb, pinfo, param_tree, hf_llrp_rmc_sentence, suboffset);
break;
case LLRP_IMPINJ_PARAM_OPSPEC_RETRY_COUNT:
PARAM_TREE_ADD(retry_count, 2, ENC_BIG_ENDIAN);
break;
case LLRP_IMPINJ_PARAM_ADVANCE_GPO_CONFIG:
PARAM_TREE_ADD(gpo_port, 2, ENC_BIG_ENDIAN);
PARAM_TREE_ADD(impinj_gpo_mode, 2, ENC_BIG_ENDIAN);
PARAM_TREE_ADD(gpo_pulse_dur, 4, ENC_BIG_ENDIAN);
break;
case LLRP_IMPINJ_PARAM_ENABLE_OPTIM_READ:
PARAM_TREE_ADD(impinj_optim_read_mode, 2, ENC_BIG_ENDIAN);
break;
case LLRP_IMPINJ_PARAM_ACCESS_SPEC_ORDERING:
PARAM_TREE_ADD(impinj_access_spec_ordering, 2, ENC_BIG_ENDIAN);
break;
case LLRP_IMPINJ_PARAM_ENABLE_RF_DOPPLER_FREQ:
PARAM_TREE_ADD(impinj_rf_doppler_mode, 2, ENC_BIG_ENDIAN);
break;
case LLRP_IMPINJ_PARAM_ARRAY_VERSION:
suboffset = dissect_llrp_utf8_parameter(tvb, pinfo, param_tree, hf_llrp_serial_number, suboffset);
suboffset = dissect_llrp_utf8_parameter(tvb, pinfo, param_tree, hf_llrp_firm_ver, suboffset);
suboffset = dissect_llrp_utf8_parameter(tvb, pinfo, param_tree, hf_llrp_pcba_ver, suboffset);
break;
case LLRP_IMPINJ_PARAM_HUB_CONFIGURATION:
PARAM_TREE_ADD(impinj_hub_id, 2, ENC_BIG_ENDIAN);
PARAM_TREE_ADD(impinj_hub_connected_type, 2, ENC_BIG_ENDIAN);
PARAM_TREE_ADD(impinj_hub_fault_type, 2, ENC_BIG_ENDIAN);
break;
default:
return suboffset;
break;
}
return dissect_llrp_parameters(tvb, pinfo, param_tree, suboffset, param_end);
}
static guint
dissect_llrp_parameters(tvbuff_t *tvb, packet_info *pinfo, proto_tree *tree,
guint offset, const guint end)
{
guint8 has_length;
guint16 len, type;
guint real_len, param_end;
guint suboffset;
guint num;
proto_item *ti;
proto_tree *param_tree;
while (((gint)(end - offset)) > 0)
{
has_length = !(tvb_get_guint8(tvb, offset) & 0x80);
if (has_length)
{
type = tvb_get_ntohs(tvb, offset);
len = tvb_get_ntohs(tvb, offset + 2);
if (len < LLRP_TLV_LEN_MIN)
real_len = LLRP_TLV_LEN_MIN;
else if (len > tvb_reported_length_remaining(tvb, offset))
real_len = tvb_reported_length_remaining(tvb, offset);
else
real_len = len;
param_end = offset + real_len;
ti = proto_tree_add_none_format(tree, hf_llrp_param, tvb,
offset, real_len, "TLV Parameter: %s",
val_to_str_ext(type, &tlv_type_ext, "Unknown Type: %d"));
param_tree = proto_item_add_subtree(ti, ett_llrp_param);
proto_tree_add_item(param_tree, hf_llrp_tlv_type, tvb,
offset, 2, ENC_BIG_ENDIAN);
offset += 2;
ti = proto_tree_add_item(param_tree, hf_llrp_tlv_len, tvb,
offset, 2, ENC_BIG_ENDIAN);
if (len != real_len)
expert_add_info_format(pinfo, ti, &ei_llrp_invalid_length,
"Invalid length field: claimed %u, should be %u.",
len, real_len);
offset += 2;
suboffset = offset;
switch(type) {
case LLRP_TLV_RO_BOUND_SPEC:
case LLRP_TLV_UHF_CAPABILITIES:
case LLRP_TLV_ACCESS_COMMAND:
case LLRP_TLV_TAG_REPORT_DATA:
case LLRP_TLV_RF_SURVEY_REPORT_DATA:
case LLRP_TLV_READER_EVENT_NOTI_SPEC:
case LLRP_TLV_READER_EVENT_NOTI_DATA:
case LLRP_TLV_C1G2_UHF_RF_MD_TBL:
case LLRP_TLV_C1G2_TAG_SPEC:
suboffset = dissect_llrp_parameters(tvb, pinfo, param_tree, suboffset, param_end);
break;
case LLRP_TLV_UTC_TIMESTAMP:
case LLRP_TLV_UPTIME:
PARAM_TREE_ADD(microseconds, 8, ENC_BIG_ENDIAN);
break;
case LLRP_TLV_GENERAL_DEVICE_CAP:
PARAM_TREE_ADD_STAY(max_supported_antenna, 2, ENC_BIG_ENDIAN);
PARAM_TREE_ADD(can_set_antenna_prop, 2, ENC_BIG_ENDIAN);
PARAM_TREE_ADD(has_utc_clock, 2, ENC_BIG_ENDIAN);
PARAM_TREE_ADD(device_manufacturer, 4, ENC_BIG_ENDIAN);
PARAM_TREE_ADD(model, 4, ENC_BIG_ENDIAN);
suboffset = dissect_llrp_utf8_parameter(tvb, pinfo, param_tree, hf_llrp_firmware_version, suboffset);
suboffset = dissect_llrp_parameters(tvb, pinfo, param_tree, suboffset, param_end);
break;
case LLRP_TLV_MAX_RECEIVE_SENSE:
PARAM_TREE_ADD(max_receive_sense, 2, ENC_BIG_ENDIAN);
break;
case LLRP_TLV_RECEIVE_SENSE_ENTRY:
PARAM_TREE_ADD(index, 2, ENC_BIG_ENDIAN);
PARAM_TREE_ADD(receive_sense, 2, ENC_BIG_ENDIAN);
break;
case LLRP_TLV_ANTENNA_RCV_SENSE_RANGE:
PARAM_TREE_ADD(antenna_id, 2, ENC_BIG_ENDIAN);
PARAM_TREE_ADD(receive_sense_index_min, 2, ENC_BIG_ENDIAN);
PARAM_TREE_ADD(receive_sense_index_max, 2, ENC_BIG_ENDIAN);
break;
case LLRP_TLV_ANTENNA_AIR_PROTO:
PARAM_TREE_ADD(antenna_id, 2, ENC_BIG_ENDIAN);
suboffset = dissect_llrp_item_array(tvb, pinfo, param_tree,
hf_llrp_num_protocols, hf_llrp_protocol_id, 1, suboffset);
break;
case LLRP_TLV_GPIO_CAPABILITIES:
PARAM_TREE_ADD(num_gpi, 2, ENC_BIG_ENDIAN);
PARAM_TREE_ADD(num_gpo, 2, ENC_BIG_ENDIAN);
break;
case LLRP_TLV_LLRP_CAPABILITIES:
PARAM_TREE_ADD_STAY(can_do_survey, 1, ENC_NA);
PARAM_TREE_ADD_STAY(can_report_buffer_warning, 1, ENC_NA);
PARAM_TREE_ADD_STAY(support_client_opspec, 1, ENC_NA);
PARAM_TREE_ADD_STAY(can_stateaware, 1, ENC_NA);
PARAM_TREE_ADD(support_holding, 1, ENC_NA);
PARAM_TREE_ADD(max_priority_supported, 1, ENC_NA);
PARAM_TREE_ADD(client_opspec_timeout, 2, ENC_BIG_ENDIAN);
num = tvb_get_ntohl(tvb, suboffset);
if(num == LLRP_NO_LIMIT)
PARAM_TREE_ADD_SPEC_STAY(uint_format_value, max_num_rospec, 4, num, "No limit (%u)");
else
PARAM_TREE_ADD_STAY(max_num_rospec, 4, ENC_BIG_ENDIAN);
suboffset += 4;
num = tvb_get_ntohl(tvb, suboffset);
if(num == LLRP_NO_LIMIT)
PARAM_TREE_ADD_SPEC_STAY(uint_format_value, max_num_spec_per_rospec, 4, num, "No limit (%u)");
else
PARAM_TREE_ADD_STAY(max_num_spec_per_rospec, 4, ENC_BIG_ENDIAN);
suboffset += 4;
num = tvb_get_ntohl(tvb, suboffset);
if(num == LLRP_NO_LIMIT)
PARAM_TREE_ADD_SPEC_STAY(uint_format_value, max_num_inventory_per_aispec, 4, num, "No limit (%u)");
else
PARAM_TREE_ADD_STAY(max_num_inventory_per_aispec, 4, ENC_BIG_ENDIAN);
suboffset += 4;
num = tvb_get_ntohl(tvb, suboffset);
if(num == LLRP_NO_LIMIT)
PARAM_TREE_ADD_SPEC_STAY(uint_format_value, max_num_accessspec, 4, num, "No limit (%u)");
else
PARAM_TREE_ADD_STAY(max_num_accessspec, 4, ENC_BIG_ENDIAN);
suboffset += 4;
num = tvb_get_ntohl(tvb, suboffset);
if(num == LLRP_NO_LIMIT)
PARAM_TREE_ADD_SPEC_STAY(uint_format_value, max_num_opspec_per_accressspec, 4, num, "No limit (%u)");
else
PARAM_TREE_ADD_STAY(max_num_opspec_per_accressspec, 4, ENC_BIG_ENDIAN);
suboffset += 4;
break;
case LLRP_TLV_REGU_CAPABILITIES:
PARAM_TREE_ADD(country_code, 2, ENC_BIG_ENDIAN);
PARAM_TREE_ADD(comm_standard, 2, ENC_BIG_ENDIAN);
suboffset = dissect_llrp_parameters(tvb, pinfo, param_tree, suboffset, param_end);
break;
case LLRP_TLV_XMIT_POWER_LEVEL_ENTRY:
PARAM_TREE_ADD(index, 2, ENC_BIG_ENDIAN);
PARAM_TREE_ADD(transmit_power, 2, ENC_BIG_ENDIAN);
break;
case LLRP_TLV_FREQ_INFORMATION:
PARAM_TREE_ADD(hopping, 1, ENC_NA);
suboffset = dissect_llrp_parameters(tvb, pinfo, param_tree, suboffset, param_end);
break;
case LLRP_TLV_FREQ_HOP_TABLE:
PARAM_TREE_ADD(hop_table_id, 1, ENC_NA);
PARAM_TREE_ADD(rfu, 1, ENC_NA);
suboffset = dissect_llrp_item_array(tvb, pinfo, param_tree,
hf_llrp_num_hops, hf_llrp_frequency, 4, suboffset);
break;
case LLRP_TLV_FIXED_FREQ_TABLE:
suboffset = dissect_llrp_item_array(tvb, pinfo, param_tree,
hf_llrp_num_freqs, hf_llrp_frequency, 4, suboffset);
break;
case LLRP_TLV_RF_SURVEY_FREQ_CAP:
PARAM_TREE_ADD(min_freq, 4, ENC_BIG_ENDIAN);
PARAM_TREE_ADD(max_freq, 4, ENC_BIG_ENDIAN);
break;
case LLRP_TLV_RO_SPEC:
PARAM_TREE_ADD(rospec_id, 4, ENC_BIG_ENDIAN);
PARAM_TREE_ADD(priority, 1, ENC_NA);
PARAM_TREE_ADD(cur_state, 1, ENC_NA);
suboffset = dissect_llrp_parameters(tvb, pinfo, param_tree, suboffset, param_end);
break;
case LLRP_TLV_RO_SPEC_START_TRIGGER:
PARAM_TREE_ADD(rospec_start_trig_type, 1, ENC_NA);
suboffset = dissect_llrp_parameters(tvb, pinfo, param_tree, suboffset, param_end);
break;
case LLRP_TLV_PER_TRIGGER_VAL:
PARAM_TREE_ADD(offset, 4, ENC_BIG_ENDIAN);
PARAM_TREE_ADD(period, 4, ENC_BIG_ENDIAN);
suboffset = dissect_llrp_parameters(tvb, pinfo, param_tree, suboffset, param_end);
break;
case LLRP_TLV_GPI_TRIGGER_VAL:
PARAM_TREE_ADD(gpi_port, 2, ENC_BIG_ENDIAN);
PARAM_TREE_ADD(gpi_event, 1, ENC_NA);
PARAM_TREE_ADD(timeout, 4, ENC_BIG_ENDIAN);
break;
case LLRP_TLV_RO_SPEC_STOP_TRIGGER:
PARAM_TREE_ADD(rospec_stop_trig_type, 1, ENC_NA);
PARAM_TREE_ADD(duration_trig, 4, ENC_BIG_ENDIAN);
suboffset = dissect_llrp_parameters(tvb, pinfo, param_tree, suboffset, param_end);
break;
case LLRP_TLV_AI_SPEC:
suboffset = dissect_llrp_item_array(tvb, pinfo, param_tree,
hf_llrp_antenna_count, hf_llrp_antenna, 2, suboffset);
suboffset = dissect_llrp_parameters(tvb, pinfo, param_tree, suboffset, param_end);
break;
case LLRP_TLV_AI_SPEC_STOP:
PARAM_TREE_ADD(aispec_stop_trig_type, 1, ENC_NA);
PARAM_TREE_ADD(duration_trig, 4, ENC_BIG_ENDIAN);
suboffset = dissect_llrp_parameters(tvb, pinfo, param_tree, suboffset, param_end);
break;
case LLRP_TLV_TAG_OBSERV_TRIGGER:
PARAM_TREE_ADD(trig_type, 1, ENC_NA);
PARAM_TREE_ADD(rfu, 1, ENC_NA);
PARAM_TREE_ADD(number_of_tags, 2, ENC_BIG_ENDIAN);
PARAM_TREE_ADD(number_of_attempts, 2, ENC_BIG_ENDIAN);
PARAM_TREE_ADD(t, 2, ENC_BIG_ENDIAN);
PARAM_TREE_ADD(timeout, 4, ENC_BIG_ENDIAN);
break;
case LLRP_TLV_INVENTORY_PARAM_SPEC:
PARAM_TREE_ADD(inventory_spec_id, 2, ENC_BIG_ENDIAN);
PARAM_TREE_ADD(protocol_id, 1, ENC_NA);
suboffset = dissect_llrp_parameters(tvb, pinfo, param_tree, suboffset, param_end);
break;
case LLRP_TLV_RF_SURVEY_SPEC:
PARAM_TREE_ADD(antenna_id, 2, ENC_BIG_ENDIAN);
PARAM_TREE_ADD(start_freq, 4, ENC_BIG_ENDIAN);
PARAM_TREE_ADD(stop_freq, 4, ENC_BIG_ENDIAN);
suboffset = dissect_llrp_parameters(tvb, pinfo, param_tree, suboffset, param_end);
break;
case LLRP_TLV_RF_SURVEY_SPEC_STOP_TR:
PARAM_TREE_ADD(stop_trig_type, 1, ENC_NA);
PARAM_TREE_ADD(duration, 4, ENC_BIG_ENDIAN);
PARAM_TREE_ADD(n_4, 4, ENC_BIG_ENDIAN);
break;
case LLRP_TLV_LOOP_SPEC:
PARAM_TREE_ADD(loop_count, 4, ENC_BIG_ENDIAN);
break;
case LLRP_TLV_ACCESS_SPEC:
PARAM_TREE_ADD(accessspec_id, 4, ENC_BIG_ENDIAN);
PARAM_TREE_ADD(antenna_id, 2, ENC_BIG_ENDIAN);
PARAM_TREE_ADD(protocol_id, 1, ENC_BIG_ENDIAN);
PARAM_TREE_ADD(access_cur_state, 1, ENC_NA);
PARAM_TREE_ADD(rospec_id, 4, ENC_BIG_ENDIAN);
suboffset = dissect_llrp_parameters(tvb, pinfo, param_tree, suboffset, param_end);
break;
case LLRP_TLV_ACCESS_SPEC_STOP_TRIG:
PARAM_TREE_ADD(access_stop_trig_type, 1, ENC_NA);
PARAM_TREE_ADD(operation_count, 2, ENC_BIG_ENDIAN);
break;
case LLRP_TLV_CLIENT_REQ_OP_SPEC:
PARAM_TREE_ADD(opspec_id, 2, ENC_BIG_ENDIAN);
break;
case LLRP_TLV_CLIENT_REQ_RESPONSE:
PARAM_TREE_ADD(accessspec_id, 2, ENC_BIG_ENDIAN);
suboffset = dissect_llrp_parameters(tvb, pinfo, param_tree, suboffset, param_end);
break;
case LLRP_TLV_LLRP_CONF_STATE_VAL:
PARAM_TREE_ADD(conf_value, 4, ENC_BIG_ENDIAN);
break;
case LLRP_TLV_IDENT:
PARAM_TREE_ADD(id_type, 1, ENC_NA);
num = tvb_get_ntohs(tvb, suboffset);
PARAM_TREE_ADD(reader_id, 2, ENC_BIG_ENDIAN);
suboffset += num;
break;
case LLRP_TLV_GPO_WRITE_DATA:
PARAM_TREE_ADD(gpo_port, 2, ENC_BIG_ENDIAN);
PARAM_TREE_ADD(gpo_data, 1, ENC_NA);
break;
case LLRP_TLV_KEEPALIVE_SPEC:
PARAM_TREE_ADD(keepalive_trig_type, 1, ENC_NA);
PARAM_TREE_ADD(time_iterval, 4, ENC_BIG_ENDIAN);
break;
case LLRP_TLV_ANTENNA_PROPS:
PARAM_TREE_ADD(antenna_connected, 1, ENC_NA);
PARAM_TREE_ADD(antenna_id, 2, ENC_BIG_ENDIAN);
PARAM_TREE_ADD(antenna_gain, 2, ENC_BIG_ENDIAN);
break;
case LLRP_TLV_ANTENNA_CONF:
PARAM_TREE_ADD(antenna_id, 2, ENC_BIG_ENDIAN);
suboffset = dissect_llrp_parameters(tvb, pinfo, param_tree, suboffset, param_end);
break;
case LLRP_TLV_RF_RECEIVER:
PARAM_TREE_ADD(receiver_sense, 2, ENC_BIG_ENDIAN);
break;
case LLRP_TLV_RF_TRANSMITTER:
PARAM_TREE_ADD(hop_table_id, 2, ENC_BIG_ENDIAN);
PARAM_TREE_ADD(channel_idx, 2, ENC_BIG_ENDIAN);
PARAM_TREE_ADD(transmit_power, 2, ENC_BIG_ENDIAN);
break;
case LLRP_TLV_GPI_PORT_CURRENT_STATE:
PARAM_TREE_ADD(gpi_port, 2, ENC_BIG_ENDIAN);
PARAM_TREE_ADD(gpi_config, 1, ENC_NA);
PARAM_TREE_ADD(gpi_state, 1, ENC_NA);
break;
case LLRP_TLV_EVENTS_AND_REPORTS:
PARAM_TREE_ADD(hold_events_and_reports, 1, ENC_NA);
break;
case LLRP_TLV_RO_REPORT_SPEC:
PARAM_TREE_ADD(ro_report_trig, 1, ENC_NA);
PARAM_TREE_ADD(n_2, 2, ENC_BIG_ENDIAN);
suboffset = dissect_llrp_parameters(tvb, pinfo, param_tree, suboffset, param_end);
break;
case LLRP_TLV_TAG_REPORT_CONTENT_SEL:
PARAM_TREE_ADD_STAY(enable_rospec_id, 2, ENC_BIG_ENDIAN);
PARAM_TREE_ADD_STAY(enable_spec_idx, 2, ENC_BIG_ENDIAN);
PARAM_TREE_ADD_STAY(enable_inv_spec_id, 2, ENC_BIG_ENDIAN);
PARAM_TREE_ADD_STAY(enable_antenna_id, 2, ENC_BIG_ENDIAN);
PARAM_TREE_ADD_STAY(enable_channel_idx, 2, ENC_BIG_ENDIAN);
PARAM_TREE_ADD_STAY(enable_peak_rssi, 2, ENC_BIG_ENDIAN);
PARAM_TREE_ADD_STAY(enable_first_seen, 2, ENC_BIG_ENDIAN);
PARAM_TREE_ADD_STAY(enable_last_seen, 2, ENC_BIG_ENDIAN);
PARAM_TREE_ADD_STAY(enable_seen_count, 2, ENC_BIG_ENDIAN);
PARAM_TREE_ADD(enable_accessspec_id, 2, ENC_BIG_ENDIAN);
suboffset = dissect_llrp_parameters(tvb, pinfo, param_tree, suboffset, param_end);
break;
case LLRP_TLV_ACCESS_REPORT_SPEC:
PARAM_TREE_ADD(access_report_trig, 1, ENC_NA);
break;
case LLRP_TLV_EPC_DATA:
suboffset = dissect_llrp_bit_field(tvb, param_tree, hf_llrp_epc, suboffset);
break;
case LLRP_TLV_FREQ_RSSI_LEVEL_ENTRY:
PARAM_TREE_ADD(frequency, 4, ENC_BIG_ENDIAN);
PARAM_TREE_ADD(bandwidth, 4, ENC_BIG_ENDIAN);
PARAM_TREE_ADD(average_rssi, 1, ENC_NA);
PARAM_TREE_ADD(peak_rssi, 1, ENC_NA);
suboffset = dissect_llrp_parameters(tvb, pinfo, param_tree, suboffset, param_end);
break;
case LLRP_TLV_EVENT_NOTIF_STATE:
PARAM_TREE_ADD(event_type, 2, ENC_BIG_ENDIAN);
PARAM_TREE_ADD(notif_state, 1, ENC_NA);
break;
case LLRP_TLV_HOPPING_EVENT:
PARAM_TREE_ADD(hop_table_id, 2, ENC_BIG_ENDIAN);
PARAM_TREE_ADD(next_chan_idx, 2, ENC_BIG_ENDIAN);
break;
case LLRP_TLV_GPI_EVENT:
PARAM_TREE_ADD(gpi_port, 2, ENC_BIG_ENDIAN);
PARAM_TREE_ADD(gpi_event, 1, ENC_NA);
break;
case LLRP_TLV_RO_SPEC_EVENT:
PARAM_TREE_ADD(roevent_type, 1, ENC_NA);
PARAM_TREE_ADD(rospec_id, 4, ENC_BIG_ENDIAN);
PARAM_TREE_ADD(prem_rospec_id, 4, ENC_BIG_ENDIAN);
break;
case LLRP_TLV_REPORT_BUF_LEVEL_WARN:
PARAM_TREE_ADD(buffer_full_percentage, 1, ENC_NA);
break;
case LLRP_TLV_REPORT_BUF_OVERFLOW_ERR:
break;
case LLRP_TLV_READER_EXCEPTION_EVENT:
suboffset = dissect_llrp_utf8_parameter(tvb, pinfo, param_tree, hf_llrp_message, suboffset);
suboffset = dissect_llrp_parameters(tvb, pinfo, param_tree, suboffset, param_end);
break;
case LLRP_TLV_RF_SURVEY_EVENT:
PARAM_TREE_ADD(rfevent_type, 1, ENC_NA);
PARAM_TREE_ADD(rospec_id, 4, ENC_BIG_ENDIAN);
PARAM_TREE_ADD(spec_idx, 2, ENC_BIG_ENDIAN);
break;
case LLRP_TLV_AI_SPEC_EVENT:
PARAM_TREE_ADD(aievent_type, 1, ENC_NA);
PARAM_TREE_ADD(rospec_id, 4, ENC_BIG_ENDIAN);
PARAM_TREE_ADD(spec_idx, 2, ENC_BIG_ENDIAN);
suboffset = dissect_llrp_parameters(tvb, pinfo, param_tree, suboffset, param_end);
break;
case LLRP_TLV_ANTENNA_EVENT:
PARAM_TREE_ADD(antenna_event_type, 1, ENC_NA);
PARAM_TREE_ADD(antenna_id, 2, ENC_BIG_ENDIAN);
break;
case LLRP_TLV_CONN_ATTEMPT_EVENT:
PARAM_TREE_ADD(conn_status, 2, ENC_BIG_ENDIAN);
break;
case LLRP_TLV_CONN_CLOSE_EVENT:
break;
case LLRP_TLV_SPEC_LOOP_EVENT:
PARAM_TREE_ADD(rospec_id, 4, ENC_BIG_ENDIAN);
PARAM_TREE_ADD(loop_count, 4, ENC_BIG_ENDIAN);
break;
case LLRP_TLV_LLRP_STATUS:
PARAM_TREE_ADD(status_code, 2, ENC_BIG_ENDIAN);
suboffset = dissect_llrp_utf8_parameter(tvb, pinfo, param_tree, hf_llrp_error_desc, suboffset);
suboffset = dissect_llrp_parameters(tvb, pinfo, param_tree, suboffset, param_end);
break;
case LLRP_TLV_FIELD_ERROR:
PARAM_TREE_ADD(field_num, 2, ENC_BIG_ENDIAN);
PARAM_TREE_ADD(error_code, 2, ENC_BIG_ENDIAN);
break;
case LLRP_TLV_PARAM_ERROR:
PARAM_TREE_ADD(parameter_type, 2, ENC_BIG_ENDIAN);
PARAM_TREE_ADD(error_code, 2, ENC_BIG_ENDIAN);
suboffset = dissect_llrp_parameters(tvb, pinfo, param_tree, suboffset, param_end);
break;
case LLRP_TLV_C1G2_LLRP_CAP:
PARAM_TREE_ADD_STAY(can_support_block_erase, 1, ENC_NA);
PARAM_TREE_ADD_STAY(can_support_block_write, 1, ENC_NA);
PARAM_TREE_ADD_STAY(can_support_block_permalock, 1, ENC_NA);
PARAM_TREE_ADD_STAY(can_support_tag_recomm, 1, ENC_NA);
PARAM_TREE_ADD_STAY(can_support_UMI_method2, 1, ENC_NA);
PARAM_TREE_ADD(can_support_XPC, 1, ENC_NA);
num = tvb_get_ntohs(tvb, suboffset);
if(num == LLRP_NO_LIMIT)
PARAM_TREE_ADD_SPEC_STAY(uint_format_value, max_num_filter_per_query, 2, num, "No limit (%u)");
else
PARAM_TREE_ADD_STAY(max_num_filter_per_query, 2, ENC_BIG_ENDIAN);
suboffset += 2;
break;
case LLRP_TLV_C1G2_UHF_RF_MD_TBL_ENT:
PARAM_TREE_ADD(mode_ident, 4, ENC_BIG_ENDIAN);
PARAM_TREE_ADD_STAY(DR, 1, ENC_NA);
PARAM_TREE_ADD(hag_conformance, 1, ENC_NA);
PARAM_TREE_ADD(mod, 1, ENC_NA);
PARAM_TREE_ADD(flm, 1, ENC_NA);
PARAM_TREE_ADD(m, 1, ENC_NA);
PARAM_TREE_ADD(bdr, 4, ENC_BIG_ENDIAN);
PARAM_TREE_ADD(pie, 4, ENC_BIG_ENDIAN);
PARAM_TREE_ADD(min_tari, 4, ENC_BIG_ENDIAN);
PARAM_TREE_ADD(max_tari, 4, ENC_BIG_ENDIAN);
PARAM_TREE_ADD(step_tari, 4, ENC_BIG_ENDIAN);
break;
case LLRP_TLV_C1G2_INVENTORY_COMMAND:
PARAM_TREE_ADD(inventory_state_aware, 1, ENC_NA);
suboffset = dissect_llrp_parameters(tvb, pinfo, param_tree, suboffset, param_end);
break;
case LLRP_TLV_C1G2_FILTER:
PARAM_TREE_ADD(trunc, 1, ENC_NA);
suboffset = dissect_llrp_parameters(tvb, pinfo, param_tree, suboffset, param_end);
break;
case LLRP_TLV_C1G2_TAG_INV_MASK:
PARAM_TREE_ADD(mb, 1, ENC_NA);
PARAM_TREE_ADD(pointer, 2, ENC_BIG_ENDIAN);
suboffset = dissect_llrp_bit_field(tvb, param_tree, hf_llrp_tag_mask, suboffset);
break;
case LLRP_TLV_C1G2_TAG_INV_AWARE_FLTR:
PARAM_TREE_ADD(aware_filter_target, 1, ENC_NA);
PARAM_TREE_ADD(aware_filter_action, 1, ENC_NA);
break;
case LLRP_TLV_C1G2_TAG_INV_UNAWR_FLTR:
PARAM_TREE_ADD(unaware_filter_action, 1, ENC_NA);
break;
case LLRP_TLV_C1G2_RF_CONTROL:
PARAM_TREE_ADD(mode_idx, 2, ENC_BIG_ENDIAN);
PARAM_TREE_ADD(tari, 2, ENC_BIG_ENDIAN);
break;
case LLRP_TLV_C1G2_SINGULATION_CTRL:
PARAM_TREE_ADD(session, 1, ENC_NA);
PARAM_TREE_ADD(tag_population, 2, ENC_BIG_ENDIAN);
PARAM_TREE_ADD(tag_transit_time, 4, ENC_BIG_ENDIAN);
suboffset = dissect_llrp_parameters(tvb, pinfo, param_tree, suboffset, param_end);
break;
case LLRP_TLV_C1G2_TAG_INV_AWARE_SING:
PARAM_TREE_ADD_STAY(sing_i, 1, ENC_NA);
PARAM_TREE_ADD_STAY(sing_s, 1, ENC_NA);
PARAM_TREE_ADD(sing_a, 1, ENC_NA);
break;
case LLRP_TLV_C1G2_TARGET_TAG:
PARAM_TREE_ADD_STAY(mb, 1, ENC_NA);
PARAM_TREE_ADD(match, 1, ENC_NA);
PARAM_TREE_ADD(pointer, 2, ENC_BIG_ENDIAN);
suboffset = dissect_llrp_bit_field(tvb, param_tree, hf_llrp_tag_mask, suboffset);
suboffset = dissect_llrp_bit_field(tvb, param_tree, hf_llrp_tag_data, suboffset);
break;
case LLRP_TLV_C1G2_READ:
case LLRP_TLV_C1G2_BLK_ERASE:
PARAM_TREE_ADD(opspec_id, 2, ENC_BIG_ENDIAN);
PARAM_TREE_ADD(access_pass, 4, ENC_BIG_ENDIAN);
PARAM_TREE_ADD(mb, 1, ENC_NA);
PARAM_TREE_ADD(word_pointer, 2, ENC_BIG_ENDIAN);
PARAM_TREE_ADD(word_count, 2, ENC_BIG_ENDIAN);
break;
case LLRP_TLV_C1G2_WRITE:
case LLRP_TLV_C1G2_BLK_WRITE:
PARAM_TREE_ADD(opspec_id, 2, ENC_BIG_ENDIAN);
PARAM_TREE_ADD(access_pass, 4, ENC_BIG_ENDIAN);
PARAM_TREE_ADD(mb, 1, ENC_NA);
PARAM_TREE_ADD(word_pointer, 2, ENC_BIG_ENDIAN);
suboffset = dissect_llrp_word_array(tvb, param_tree, hf_llrp_write_data, suboffset);
break;
case LLRP_TLV_C1G2_KILL:
PARAM_TREE_ADD(opspec_id, 2, ENC_BIG_ENDIAN);
PARAM_TREE_ADD(kill_pass, 4, ENC_BIG_ENDIAN);
break;
case LLRP_TLV_C1G2_RECOMMISSION:
PARAM_TREE_ADD(opspec_id, 2, ENC_BIG_ENDIAN);
PARAM_TREE_ADD(kill_pass, 4, ENC_BIG_ENDIAN);
PARAM_TREE_ADD_STAY(kill_3, 1, ENC_NA);
PARAM_TREE_ADD_STAY(kill_2, 1, ENC_NA);
PARAM_TREE_ADD(kill_l, 1, ENC_NA);
break;
case LLRP_TLV_C1G2_LOCK:
PARAM_TREE_ADD(opspec_id, 2, ENC_BIG_ENDIAN);
PARAM_TREE_ADD(access_pass, 4, ENC_BIG_ENDIAN);
suboffset = dissect_llrp_parameters(tvb, pinfo, param_tree, suboffset, param_end);
break;
case LLRP_TLV_C1G2_LOCK_PAYLOAD:
PARAM_TREE_ADD(privilege, 1, ENC_NA);
PARAM_TREE_ADD(data_field, 1, ENC_NA);
break;
case LLRP_TLV_C1G2_BLK_PERMALOCK:
PARAM_TREE_ADD(opspec_id, 2, ENC_BIG_ENDIAN);
PARAM_TREE_ADD(access_pass, 4, ENC_BIG_ENDIAN);
PARAM_TREE_ADD(mb, 1, ENC_NA);
PARAM_TREE_ADD(block_pointer, 2, ENC_BIG_ENDIAN);
suboffset = dissect_llrp_word_array(tvb, param_tree, hf_llrp_block_mask, suboffset);
break;
case LLRP_TLV_C1G2_GET_BLK_PERMALOCK:
PARAM_TREE_ADD(opspec_id, 2, ENC_BIG_ENDIAN);
PARAM_TREE_ADD(access_pass, 4, ENC_BIG_ENDIAN);
PARAM_TREE_ADD(mb, 1, ENC_NA);
PARAM_TREE_ADD(block_pointer, 2, ENC_BIG_ENDIAN);
PARAM_TREE_ADD(block_range, 2, ENC_BIG_ENDIAN);
break;
case LLRP_TLV_C1G2_EPC_MEMORY_SLCTOR:
PARAM_TREE_ADD_STAY(enable_crc, 1, ENC_NA);
PARAM_TREE_ADD_STAY(enable_pc, 1, ENC_NA);
PARAM_TREE_ADD(enable_xpc, 1, ENC_NA);
break;
case LLRP_TLV_C1G2_READ_OP_SPEC_RES:
PARAM_TREE_ADD(access_result, 1, ENC_NA);
PARAM_TREE_ADD(opspec_id, 2, ENC_BIG_ENDIAN);
suboffset = dissect_llrp_word_array(tvb, param_tree, hf_llrp_read_data, suboffset);
break;
case LLRP_TLV_C1G2_WRT_OP_SPEC_RES:
case LLRP_TLV_C1G2_BLK_WRT_OP_SPC_RES:
PARAM_TREE_ADD(access_result, 1, ENC_NA);
PARAM_TREE_ADD(opspec_id, 2, ENC_BIG_ENDIAN);
PARAM_TREE_ADD(num_words_written, 2, ENC_BIG_ENDIAN);
break;
case LLRP_TLV_C1G2_KILL_OP_SPEC_RES:
case LLRP_TLV_C1G2_RECOM_OP_SPEC_RES:
case LLRP_TLV_C1G2_LOCK_OP_SPEC_RES:
case LLRP_TLV_C1G2_BLK_ERS_OP_SPC_RES:
case LLRP_TLV_C1G2_BLK_PRL_OP_SPC_RES:
PARAM_TREE_ADD(access_result, 1, ENC_NA);
PARAM_TREE_ADD(opspec_id, 2, ENC_BIG_ENDIAN);
break;
case LLRP_TLV_C1G2_BLK_PRL_STAT_RES:
PARAM_TREE_ADD(access_result, 1, ENC_NA);
PARAM_TREE_ADD(opspec_id, 2, ENC_BIG_ENDIAN);
suboffset = dissect_llrp_word_array(tvb, param_tree, hf_llrp_permlock_status, suboffset);
break;
case LLRP_TLV_CUSTOM_PARAMETER:
num = tvb_get_ntohl(tvb, suboffset);
PARAM_TREE_ADD(vendor_id, 4, ENC_BIG_ENDIAN);
switch(num) {
case LLRP_VENDOR_IMPINJ:
suboffset = dissect_llrp_impinj_parameter(tvb, pinfo, param_tree, suboffset, param_end);
break;
}
break;
}
if(suboffset != param_end) {
expert_add_info_format(pinfo, param_tree, &ei_llrp_invalid_length,
"Incorrect length of parameter: %u bytes decoded, but %u bytes claimed.",
suboffset - offset + 4, real_len);
}
offset += real_len - 4;
}
else
{
type = tvb_get_guint8(tvb, offset) & 0x7F;
switch (type)
{
case LLRP_TV_ANTENNA_ID:
real_len = LLRP_TV_LEN_ANTENNA_ID; break;
case LLRP_TV_FIRST_SEEN_TIME_UTC:
real_len = LLRP_TV_LEN_FIRST_SEEN_TIME_UTC; break;
case LLRP_TV_FIRST_SEEN_TIME_UPTIME:
real_len = LLRP_TV_LEN_FIRST_SEEN_TIME_UPTIME; break;
case LLRP_TV_LAST_SEEN_TIME_UTC:
real_len = LLRP_TV_LEN_LAST_SEEN_TIME_UTC; break;
case LLRP_TV_LAST_SEEN_TIME_UPTIME:
real_len = LLRP_TV_LEN_LAST_SEEN_TIME_UPTIME; break;
case LLRP_TV_PEAK_RSSI:
real_len = LLRP_TV_LEN_PEAK_RSSI; break;
case LLRP_TV_CHANNEL_INDEX:
real_len = LLRP_TV_LEN_CHANNEL_INDEX; break;
case LLRP_TV_TAG_SEEN_COUNT:
real_len = LLRP_TV_LEN_TAG_SEEN_COUNT; break;
case LLRP_TV_RO_SPEC_ID:
real_len = LLRP_TV_LEN_RO_SPEC_ID; break;
case LLRP_TV_INVENTORY_PARAM_SPEC_ID:
real_len = LLRP_TV_LEN_INVENTORY_PARAM_SPEC_ID; break;
case LLRP_TV_C1G2_CRC:
real_len = LLRP_TV_LEN_C1G2_CRC; break;
case LLRP_TV_C1G2_PC:
real_len = LLRP_TV_LEN_C1G2_PC; break;
case LLRP_TV_EPC96:
real_len = LLRP_TV_LEN_EPC96; break;
case LLRP_TV_SPEC_INDEX:
real_len = LLRP_TV_LEN_SPEC_INDEX; break;
case LLRP_TV_CLIENT_REQ_OP_SPEC_RES:
real_len = LLRP_TV_LEN_CLIENT_REQ_OP_SPEC_RES; break;
case LLRP_TV_ACCESS_SPEC_ID:
real_len = LLRP_TV_LEN_ACCESS_SPEC_ID; break;
case LLRP_TV_OP_SPEC_ID:
real_len = LLRP_TV_LEN_OP_SPEC_ID; break;
case LLRP_TV_C1G2_SINGULATION_DET:
real_len = LLRP_TV_LEN_C1G2_SINGULATION_DET; break;
case LLRP_TV_C1G2_XPC_W1:
real_len = LLRP_TV_LEN_C1G2_XPC_W1; break;
case LLRP_TV_C1G2_XPC_W2:
real_len = LLRP_TV_LEN_C1G2_XPC_W2; break;
default:
real_len = 0;
break;
};
ti = proto_tree_add_none_format(tree, hf_llrp_param, tvb,
offset, real_len + 1, "TV Parameter : %s",
val_to_str_ext(type, &tv_type_ext, "Unknown Type: %d"));
param_tree = proto_item_add_subtree(ti, ett_llrp_param);
proto_tree_add_item(param_tree, hf_llrp_tv_type, tvb,
offset, 1, ENC_BIG_ENDIAN);
offset++;
suboffset = offset;
switch (type)
{
case LLRP_TV_ANTENNA_ID:
PARAM_TREE_ADD_STAY(antenna_id, 2, ENC_BIG_ENDIAN);
break;
case LLRP_TV_FIRST_SEEN_TIME_UTC:
case LLRP_TV_FIRST_SEEN_TIME_UPTIME:
case LLRP_TV_LAST_SEEN_TIME_UTC:
case LLRP_TV_LAST_SEEN_TIME_UPTIME:
PARAM_TREE_ADD_STAY(microseconds, 8, ENC_BIG_ENDIAN);
break;
case LLRP_TV_PEAK_RSSI:
PARAM_TREE_ADD_STAY(peak_rssi, 1, ENC_NA);
break;
case LLRP_TV_CHANNEL_INDEX:
PARAM_TREE_ADD_STAY(channel_idx, 2, ENC_BIG_ENDIAN);
break;
case LLRP_TV_TAG_SEEN_COUNT:
PARAM_TREE_ADD_STAY(tag_count, 2, ENC_BIG_ENDIAN);
break;
case LLRP_TV_RO_SPEC_ID:
PARAM_TREE_ADD_STAY(rospec_id, 4, ENC_BIG_ENDIAN);
break;
case LLRP_TV_INVENTORY_PARAM_SPEC_ID:
PARAM_TREE_ADD_STAY(inventory_spec_id, 2, ENC_BIG_ENDIAN);
break;
case LLRP_TV_C1G2_CRC:
PARAM_TREE_ADD_STAY(crc, 2, ENC_BIG_ENDIAN);
break;
case LLRP_TV_C1G2_PC:
PARAM_TREE_ADD_STAY(pc_bits, 2, ENC_BIG_ENDIAN);
break;
case LLRP_TV_EPC96:
PARAM_TREE_ADD_STAY(epc, 96/8, ENC_NA);
break;
case LLRP_TV_SPEC_INDEX:
PARAM_TREE_ADD_STAY(spec_idx, 2, ENC_BIG_ENDIAN);
break;
case LLRP_TV_CLIENT_REQ_OP_SPEC_RES:
PARAM_TREE_ADD_STAY(opspec_id, 2, ENC_BIG_ENDIAN);
break;
case LLRP_TV_ACCESS_SPEC_ID:
PARAM_TREE_ADD_STAY(accessspec_id, 4, ENC_BIG_ENDIAN);
break;
case LLRP_TV_OP_SPEC_ID:
PARAM_TREE_ADD_STAY(opspec_id, 2, ENC_BIG_ENDIAN);
break;
case LLRP_TV_C1G2_SINGULATION_DET:
PARAM_TREE_ADD_STAY(num_coll, 2, ENC_BIG_ENDIAN);
PARAM_TREE_ADD_STAY(num_empty, 2, ENC_BIG_ENDIAN);
break;
case LLRP_TV_C1G2_XPC_W1:
PARAM_TREE_ADD_STAY(xpc_w1, 2, ENC_BIG_ENDIAN);
break;
case LLRP_TV_C1G2_XPC_W2:
PARAM_TREE_ADD_STAY(xpc_w2, 2, ENC_BIG_ENDIAN);
break;
};
offset += real_len;
}
}
return offset;
}
static guint
dissect_llrp_impinj_message(tvbuff_t *tvb, packet_info *pinfo, proto_tree *tree, guint offset)
{
guint8 subtype;
subtype = tvb_get_guint8(tvb, offset);
col_append_fstr(pinfo->cinfo, COL_INFO, " (Impinj - %s)",
val_to_str_ext(subtype, &impinj_msg_subtype_ext, "Unknown Type: %d"));
proto_tree_add_item(tree, hf_llrp_impinj_msg_type, tvb, offset, 1, ENC_BIG_ENDIAN);
offset += 1;
switch(subtype) {
case LLRP_IMPINJ_TYPE_ENABLE_EXTENSIONS:
proto_tree_add_item(tree, hf_llrp_rfu, tvb, offset, 4, ENC_NA);
offset += 4;
break;
case LLRP_IMPINJ_TYPE_ENABLE_EXTENSIONS_RESPONSE:
break;
case LLRP_IMPINJ_TYPE_SAVE_SETTINGS:
proto_tree_add_item(tree, hf_llrp_save_config, tvb, offset, 1, ENC_NA);
offset += 1;
break;
case LLRP_IMPINJ_TYPE_SAVE_SETTINGS_RESPONSE:
break;
}
return offset;
}
static void
dissect_llrp_message(tvbuff_t *tvb, packet_info *pinfo, proto_tree *tree,
guint16 type, guint offset)
{
gboolean ends_with_parameters;
guint8 requested_data;
guint16 antenna_id, gpi_port, gpo_port;
guint32 spec_id, vendor;
proto_item *request_item, *antenna_item, *gpi_item, *gpo_item;
guint (*dissect_custom_message)(tvbuff_t *tvb,
packet_info *pinfo, proto_tree *tree, guint offset) = NULL;
ends_with_parameters = FALSE;
switch (type)
{
case LLRP_TYPE_CLOSE_CONNECTION_RESPONSE:
case LLRP_TYPE_GET_READER_CAPABILITIES_RESPONSE:
case LLRP_TYPE_ADD_ROSPEC:
case LLRP_TYPE_ADD_ROSPEC_RESPONSE:
case LLRP_TYPE_DELETE_ROSPEC_RESPONSE:
case LLRP_TYPE_START_ROSPEC_RESPONSE:
case LLRP_TYPE_STOP_ROSPEC_RESPONSE:
case LLRP_TYPE_ENABLE_ROSPEC_RESPONSE:
case LLRP_TYPE_DISABLE_ROSPEC_RESPONSE:
case LLRP_TYPE_GET_ROSPECS_RESPONSE:
case LLRP_TYPE_ADD_ACCESSSPEC:
case LLRP_TYPE_ADD_ACCESSSPEC_RESPONSE:
case LLRP_TYPE_DELETE_ACCESSSPEC_RESPONSE:
case LLRP_TYPE_ENABLE_ACCESSSPEC_RESPONSE:
case LLRP_TYPE_DISABLE_ACCESSSPEC_RESPONSE:
case LLRP_TYPE_GET_ACCESSSPECS:
case LLRP_TYPE_CLIENT_REQUEST_OP:
case LLRP_TYPE_CLIENT_RESQUEST_OP_RESPONSE:
case LLRP_TYPE_RO_ACCESS_REPORT:
case LLRP_TYPE_READER_EVENT_NOTIFICATION:
case LLRP_TYPE_ERROR_MESSAGE:
case LLRP_TYPE_GET_READER_CONFIG_RESPONSE:
case LLRP_TYPE_SET_READER_CONFIG_RESPONSE:
case LLRP_TYPE_SET_PROTOCOL_VERSION_RESPONSE:
case LLRP_TYPE_GET_ACCESSSPECS_RESPONSE:
case LLRP_TYPE_GET_REPORT:
case LLRP_TYPE_ENABLE_EVENTS_AND_REPORTS:
ends_with_parameters = TRUE;
break;
case LLRP_TYPE_START_ROSPEC:
case LLRP_TYPE_STOP_ROSPEC:
case LLRP_TYPE_ENABLE_ROSPEC:
case LLRP_TYPE_DISABLE_ROSPEC:
case LLRP_TYPE_DELETE_ROSPEC:
spec_id = tvb_get_ntohl(tvb, offset);
if (spec_id == LLRP_ROSPEC_ALL)
proto_tree_add_uint_format(tree, hf_llrp_rospec, tvb,
offset, 4, spec_id, "All ROSpecs (%u)", spec_id);
else
proto_tree_add_item(tree, hf_llrp_rospec, tvb,
offset, 4, ENC_BIG_ENDIAN);
offset += 4;
break;
case LLRP_TYPE_ENABLE_ACCESSSPEC:
case LLRP_TYPE_DELETE_ACCESSSPEC:
case LLRP_TYPE_DISABLE_ACCESSSPEC:
spec_id = tvb_get_ntohl(tvb, offset);
if (spec_id == LLRP_ACCESSSPEC_ALL)
proto_tree_add_uint_format(tree, hf_llrp_accessspec, tvb,
offset, 4, spec_id, "All Access Specs (%u)", spec_id);
else
proto_tree_add_item(tree, hf_llrp_accessspec, tvb,
offset, 4, ENC_BIG_ENDIAN);
offset += 4;
break;
case LLRP_TYPE_GET_READER_CAPABILITIES:
proto_tree_add_item(tree, hf_llrp_req_cap, tvb, offset, 1, ENC_BIG_ENDIAN);
offset++;
ends_with_parameters = TRUE;
break;
case LLRP_TYPE_GET_READER_CONFIG:
antenna_id = tvb_get_ntohs(tvb, offset);
if (antenna_id == LLRP_ANTENNA_ALL)
antenna_item = proto_tree_add_uint_format(tree, hf_llrp_antenna_id, tvb,
offset, 2, antenna_id, "All Antennas (%u)", antenna_id);
else
antenna_item = proto_tree_add_item(tree, hf_llrp_antenna_id, tvb,
offset, 2, ENC_BIG_ENDIAN);
offset += 2;
requested_data = tvb_get_guint8(tvb, offset);
request_item = proto_tree_add_item(tree, hf_llrp_req_conf, tvb,
offset, 1, ENC_BIG_ENDIAN);
offset++;
gpi_port = tvb_get_ntohs(tvb, offset);
if (gpi_port == LLRP_GPI_PORT_ALL)
gpi_item = proto_tree_add_uint_format(tree, hf_llrp_gpi_port, tvb,
offset, 2, gpi_port, "All GPI Ports (%u)", gpi_port);
else
gpi_item = proto_tree_add_item(tree, hf_llrp_gpi_port, tvb,
offset, 2, ENC_BIG_ENDIAN);
offset += 2;
gpo_port = tvb_get_ntohs(tvb, offset);
if (gpo_port == LLRP_GPO_PORT_ALL)
gpo_item = proto_tree_add_uint_format(tree, hf_llrp_gpo_port, tvb,
offset, 2, gpo_port, "All GPO Ports (%u)", gpo_port);
else
gpo_item = proto_tree_add_item(tree, hf_llrp_gpo_port, tvb,
offset, 2, ENC_BIG_ENDIAN);
offset += 2;
switch (requested_data)
{
case LLRP_CONF_ALL:
break;
case LLRP_CONF_ANTENNA_PROPERTIES:
case LLRP_CONF_ANTENNA_CONFIGURATION:
proto_item_append_text(gpi_item, " (Ignored)");
proto_item_append_text(gpo_item, " (Ignored)");
break;
case LLRP_CONF_IDENTIFICATION:
case LLRP_CONF_RO_REPORT_SPEC:
case LLRP_CONF_READER_EVENT_NOTIFICATION_SPEC:
case LLRP_CONF_ACCESS_REPORT_SPEC:
case LLRP_CONF_LLRP_CONFIGURATION_STATE:
case LLRP_CONF_KEEPALIVE_SPEC:
case LLRP_CONF_EVENTS_AND_REPORTS:
proto_item_append_text(antenna_item, " (Ignored)");
proto_item_append_text(gpi_item, " (Ignored)");
proto_item_append_text(gpo_item, " (Ignored)");
break;
case LLRP_CONF_GPI_PORT_CURRENT_STATE:
proto_item_append_text(antenna_item, " (Ignored)");
proto_item_append_text(gpo_item, " (Ignored)");
break;
case LLRP_CONF_GPO_WRITE_DATA:
proto_item_append_text(antenna_item, " (Ignored)");
proto_item_append_text(gpi_item, " (Ignored)");
break;
default:
proto_item_append_text(antenna_item, " (Ignored)");
expert_add_info_format(pinfo, request_item, &ei_llrp_req_conf,
"Unrecognized configuration request: %u",
requested_data);
proto_item_append_text(gpi_item, " (Ignored)");
proto_item_append_text(gpo_item, " (Ignored)");
break;
};
ends_with_parameters = TRUE;
break;
case LLRP_TYPE_SET_READER_CONFIG:
proto_tree_add_item(tree, hf_llrp_rest_fact, tvb, offset, 1, ENC_NA);
offset++;
ends_with_parameters = TRUE;
break;
case LLRP_TYPE_SET_PROTOCOL_VERSION:
proto_tree_add_item(tree, hf_llrp_version, tvb, offset, 1, ENC_BIG_ENDIAN);
break;
case LLRP_TYPE_GET_SUPPORTED_VERSION_RESPONSE:
proto_tree_add_item(tree, hf_llrp_cur_ver, tvb, offset, 1, ENC_BIG_ENDIAN);
offset++;
proto_tree_add_item(tree, hf_llrp_sup_ver, tvb, offset, 1, ENC_BIG_ENDIAN);
offset++;
ends_with_parameters = TRUE;
break;
case LLRP_TYPE_CUSTOM_MESSAGE:
vendor = tvb_get_ntohl(tvb, offset);
proto_tree_add_item(tree, hf_llrp_vendor, tvb, offset, 4, ENC_BIG_ENDIAN);
offset += 4;
switch(vendor) {
case LLRP_VENDOR_IMPINJ:
dissect_custom_message = dissect_llrp_impinj_message;
ends_with_parameters = TRUE;
break;
}
if (dissect_custom_message)
offset = dissect_custom_message(tvb, pinfo, tree, offset);
break;
case LLRP_TYPE_KEEPALIVE:
case LLRP_TYPE_KEEPALIVE_ACK:
case LLRP_TYPE_CLOSE_CONNECTION:
case LLRP_TYPE_GET_ROSPECS:
case LLRP_TYPE_GET_SUPPORTED_VERSION:
break;
default:
DISSECTOR_ASSERT_NOT_REACHED();
};
if(ends_with_parameters) {
offset = dissect_llrp_parameters(tvb, pinfo, tree, offset, tvb_reported_length(tvb));
}
if(tvb_reported_length_remaining(tvb, offset) != 0) {
expert_add_info_format(pinfo, tree, &ei_llrp_invalid_length,
"Incorrect length of message: %u bytes decoded, but %u bytes available.",
offset, tvb_reported_length(tvb));
}
}
static int
dissect_llrp_packet(tvbuff_t *tvb, packet_info *pinfo, proto_tree *tree, void* data _U_)
{
proto_item *ti;
proto_tree *llrp_tree;
guint16 type;
guint32 len;
guint offset = 0;
DISSECTOR_ASSERT(tvb_reported_length(tvb) >= LLRP_HEADER_LENGTH);
col_set_str(pinfo->cinfo, COL_PROTOCOL, "LLRP");
col_set_str(pinfo->cinfo, COL_INFO, "LLRP Message");
type = tvb_get_ntohs(tvb, offset) & 0x03FF;
col_append_fstr(pinfo->cinfo, COL_INFO, " (%s)",
val_to_str_ext(type, &message_types_ext, "Unknown Type: %d"));
ti = proto_tree_add_item(tree, proto_llrp, tvb, offset, -1, ENC_NA);
llrp_tree = proto_item_add_subtree(ti, ett_llrp);
proto_tree_add_item(llrp_tree, hf_llrp_version, tvb, offset, 1, ENC_BIG_ENDIAN);
proto_tree_add_item(llrp_tree, hf_llrp_type, tvb, offset, 2, ENC_BIG_ENDIAN);
offset += 2;
ti = proto_tree_add_item(llrp_tree, hf_llrp_length, tvb, offset, 4, ENC_BIG_ENDIAN);
len = tvb_get_ntohl(tvb, offset);
if (len != tvb_reported_length(tvb))
{
expert_add_info_format(pinfo, ti, &ei_llrp_invalid_length,
"Incorrect length field: claimed %u, but have %u.",
len, tvb_reported_length(tvb));
}
offset += 4;
proto_tree_add_item(llrp_tree, hf_llrp_id, tvb, offset, 4, ENC_BIG_ENDIAN);
offset += 4;
if (try_val_to_str_ext(type, &message_types_ext))
dissect_llrp_message(tvb, pinfo, llrp_tree, type, offset);
return tvb_captured_length(tvb);
}
static guint
get_llrp_message_len(packet_info *pinfo _U_, tvbuff_t *tvb, int offset, void *data _U_)
{
return (guint)tvb_get_ntohl(tvb, offset+2);
}
static int
dissect_llrp(tvbuff_t *tvb, packet_info *pinfo, proto_tree *tree, void* data)
{
tcp_dissect_pdus(tvb, pinfo, tree, TRUE, LLRP_HEADER_LENGTH,
get_llrp_message_len, dissect_llrp_packet, data);
return tvb_captured_length(tvb);
}
void
proto_register_llrp(void)
{
static hf_register_info hf[] = {
{ &hf_llrp_version,
{ "Version", "llrp.version", FT_UINT8, BASE_DEC, VALS(llrp_versions), 0x1C,
NULL, HFILL }},
{ &hf_llrp_type,
{ "Type", "llrp.type", FT_UINT16, BASE_DEC | BASE_EXT_STRING, &message_types_ext, 0x03FF,
NULL, HFILL }},
{ &hf_llrp_length,
{ "Length", "llrp.length", FT_UINT32, BASE_DEC, NULL, 0,
NULL, HFILL }},
{ &hf_llrp_id,
{ "ID", "llrp.id", FT_UINT32, BASE_DEC, NULL, 0,
NULL, HFILL }},
{ &hf_llrp_cur_ver,
{ "Current Version", "llrp.cur_ver", FT_UINT8, BASE_DEC, VALS(llrp_versions), 0,
NULL, HFILL }},
{ &hf_llrp_sup_ver,
{ "Supported Version", "llrp.sup_ver", FT_UINT8, BASE_DEC, VALS(llrp_versions), 0,
"The max supported protocol version.", HFILL }},
{ &hf_llrp_req_cap,
{ "Requested Capabilities", "llrp.req_cap", FT_UINT8, BASE_DEC, VALS(capabilities_request), 0,
NULL, HFILL }},
{ &hf_llrp_req_conf,
{ "Requested Configuration", "llrp.req_conf", FT_UINT8, BASE_DEC | BASE_EXT_STRING, &config_request_ext, 0,
NULL, HFILL }},
{ &hf_llrp_rospec,
{ "ROSpec ID", "llrp.rospec", FT_UINT32, BASE_DEC, NULL, 0,
NULL, HFILL }},
{ &hf_llrp_antenna_id,
{ "Antenna ID", "llrp.antenna_id", FT_UINT16, BASE_DEC, NULL, 0,
NULL, HFILL }},
{ &hf_llrp_gpi_port,
{ "GPI Port Number", "llrp.gpi_port", FT_UINT16, BASE_DEC, NULL, 0,
NULL, HFILL }},
{ &hf_llrp_gpo_port,
{ "GPO Port Number", "llrp.gpo_port", FT_UINT16, BASE_DEC, NULL, 0,
NULL, HFILL }},
{ &hf_llrp_rest_fact,
{ "Restore Factory Settings", "llrp.rest_fact", FT_BOOLEAN, 8, TFS(&tfs_yes_no), 0x80,
NULL, HFILL }},
{ &hf_llrp_accessspec,
{ "Access Spec ID", "llrp.accessspec", FT_UINT32, BASE_DEC, NULL, 0,
NULL, HFILL }},
{ &hf_llrp_vendor,
{ "Vendor ID", "llrp.vendor", FT_UINT32, BASE_DEC, VALS(llrp_vendors), 0,
NULL, HFILL }},
{ &hf_llrp_impinj_msg_type,
{ "Subtype", "llrp.impinj.type", FT_UINT8, BASE_DEC | BASE_EXT_STRING, &impinj_msg_subtype_ext, 0,
"Subtype specified by vendor", HFILL }},
{ &hf_llrp_tlv_type,
{ "Type", "llrp.tlv_type", FT_UINT16, BASE_DEC | BASE_EXT_STRING, &tlv_type_ext, 0x03FF,
"The type of TLV.", HFILL }},
{ &hf_llrp_tv_type,
{ "Type", "llrp.tv_type", FT_UINT8, BASE_DEC | BASE_EXT_STRING, &tv_type_ext, 0x7F,
"The type of TV.", HFILL }},
{ &hf_llrp_tlv_len,
{ "Length", "llrp.tlv_len", FT_UINT16, BASE_DEC, NULL, 0,
"The length of this TLV.", HFILL }},
{ &hf_llrp_param,
{ "Parameter", "llrp.param", FT_NONE, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_llrp_num_gpi,
{ "Number of GPI ports", "llrp.param.num_gpi", FT_UINT16, BASE_DEC, NULL, 0,
NULL, HFILL }},
{ &hf_llrp_num_gpo,
{ "Number of GPO ports", "llrp.param.num_gpo", FT_UINT16, BASE_DEC, NULL, 0,
NULL, HFILL }},
{ &hf_llrp_microseconds,
{ "Microseconds", "llrp.param.microseconds", FT_UINT64, BASE_DEC, NULL, 0,
NULL, HFILL }},
{ &hf_llrp_max_supported_antenna,
{ "Max number of antenna supported", "llrp.param.max_supported_antenna", FT_UINT16, BASE_DEC, NULL, 0,
NULL, HFILL }},
{ &hf_llrp_can_set_antenna_prop,
{ "Can set antenna properties", "llrp.param.can_set_antenna_prop", FT_BOOLEAN, 16, TFS(&tfs_yes_no), 0x8000,
NULL, HFILL }},
{ &hf_llrp_has_utc_clock,
{ "Has UTC clock capabilities", "llrp.param.has_utc_clock", FT_BOOLEAN, 16, TFS(&tfs_yes_no), 0x4000,
NULL, HFILL }},
{ &hf_llrp_device_manufacturer,
{ "Device manufacturer name", "llrp.param.device_manufacturer", FT_UINT32, BASE_DEC, NULL, 0,
NULL, HFILL }},
{ &hf_llrp_model,
{ "Model name", "llrp.param.model", FT_UINT32, BASE_DEC, NULL, 0,
NULL, HFILL }},
{ &hf_llrp_firmware_version,
{ "Reader firmware version", "llrp.param.firmware_version", FT_UINT_STRING, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_llrp_max_receive_sense,
{ "Maximum sensitivity value", "llrp.param.max_receive_sense", FT_UINT16, BASE_DEC, NULL, 0,
NULL, HFILL }},
{ &hf_llrp_index,
{ "Index", "llrp.param.index", FT_UINT16, BASE_DEC, NULL, 0,
NULL, HFILL }},
{ &hf_llrp_receive_sense,
{ "Receive sensitivity value", "llrp.param.receive_sense", FT_UINT16, BASE_DEC, NULL, 0,
NULL, HFILL }},
{ &hf_llrp_receive_sense_index_min,
{ "Receive sensitivity index min", "llrp.param.receive_sense_index_min", FT_UINT16, BASE_DEC, NULL, 0,
NULL, HFILL }},
{ &hf_llrp_receive_sense_index_max,
{ "Receive sensitivity index max", "llrp.param.receive_sense_index_max", FT_UINT16, BASE_DEC, NULL, 0,
NULL, HFILL }},
{ &hf_llrp_num_protocols,
{ "Number of protocols", "llrp.param.num_protocols", FT_UINT16, BASE_DEC, NULL, 0,
NULL, HFILL }},
{ &hf_llrp_protocol_id,
{ "Protocol ID", "llrp.param.protocol_id", FT_UINT8, BASE_DEC | BASE_RANGE_STRING, RVALS(protocol_id), 0,
NULL, HFILL }},
{ &hf_llrp_can_do_survey,
{ "Can do RF survey", "llrp.param.can_do_survey", FT_BOOLEAN, 8, TFS(&tfs_yes_no), 0x80,
NULL, HFILL }},
{ &hf_llrp_can_report_buffer_warning,
{ "Can report buffer fill warning", "llrp.param.can_report_buffer_warning", FT_BOOLEAN, 8, TFS(&tfs_yes_no), 0x40,
NULL, HFILL }},
{ &hf_llrp_support_client_opspec,
{ "Support client request OpSpec", "llrp.param.support_client_opspec", FT_BOOLEAN, 8, TFS(&tfs_yes_no), 0x20,
NULL, HFILL }},
{ &hf_llrp_can_stateaware,
{ "Can do tag inventory state aware singulation", "llrp.param.can_stateaware", FT_BOOLEAN, 8, TFS(&tfs_yes_no), 0x10,
NULL, HFILL }},
{ &hf_llrp_support_holding,
{ "Support event and report holding", "llrp.param.support_holding", FT_BOOLEAN, 8, TFS(&tfs_yes_no), 0x08,
NULL, HFILL }},
{ &hf_llrp_max_priority_supported,
{ "Max priority level supported", "llrp.param.max_priority_supported", FT_UINT8, BASE_DEC, NULL, 0,
NULL, HFILL }},
{ &hf_llrp_client_opspec_timeout,
{ "Client request OpSpec timeout", "llrp.param.client_opspec_timeout", FT_UINT16, BASE_DEC, NULL, 0,
NULL, HFILL }},
{ &hf_llrp_max_num_rospec,
{ "Maximum number of ROSpecs", "llrp.param.max_num_rospec", FT_UINT32, BASE_DEC, NULL, 0,
NULL, HFILL }},
{ &hf_llrp_max_num_spec_per_rospec,
{ "Maximum number of spec per ROSpec", "llrp.param.max_num_spec_per_rospec", FT_UINT32, BASE_DEC, NULL, 0,
NULL, HFILL }},
{ &hf_llrp_max_num_inventory_per_aispec,
{ "Maximum number of Inventory Spec per AISpec", "llrp.param.max_num_inventory_per_aispec", FT_UINT32, BASE_DEC, NULL, 0,
NULL, HFILL }},
{ &hf_llrp_max_num_accessspec,
{ "Maximum number of AccessSpec", "llrp.param.max_num_accessspec", FT_UINT32, BASE_DEC, NULL, 0,
NULL, HFILL }},
{ &hf_llrp_max_num_opspec_per_accressspec,
{ "Maximum number of OpSpec per AccessSpec", "llrp.param.max_num_opspec_per_accressspec", FT_UINT32, BASE_DEC, NULL, 0,
NULL, HFILL }},
{ &hf_llrp_country_code,
{ "Contry code", "llrp.param.country_code", FT_UINT16, BASE_DEC, NULL, 0,
NULL, HFILL }},
{ &hf_llrp_comm_standard,
{ "Communication standard", "llrp.param.comm_standard", FT_UINT16, BASE_DEC | BASE_EXT_STRING, &comm_standard_ext, 0,
NULL, HFILL }},
{ &hf_llrp_transmit_power,
{ "Transmit power value", "llrp.param.transmit_power", FT_UINT16, BASE_DEC, NULL, 0,
NULL, HFILL }},
{ &hf_llrp_hopping,
{ "Hopping", "llrp.param.hopping", FT_BOOLEAN, 8, TFS(&tfs_yes_no), 0x80,
NULL, HFILL }},
{ &hf_llrp_hop_table_id,
{ "Hop table ID", "llrp.param.hop_table_id", FT_UINT8, BASE_DEC, NULL, 0,
NULL, HFILL }},
{ &hf_llrp_rfu,
{ "Reserved for future use", "llrp.param.rfu", FT_BYTES, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_llrp_num_hops,
{ "Number of hops", "llrp.param.num_hops", FT_UINT16, BASE_DEC, NULL, 0,
NULL, HFILL }},
{ &hf_llrp_frequency,
{ "Frequency", "llrp.param.frequency", FT_UINT32, BASE_DEC, NULL, 0,
NULL, HFILL }},
{ &hf_llrp_num_freqs,
{ "Number of frequencies", "llrp.param.num_freqs", FT_UINT16, BASE_DEC, NULL, 0,
NULL, HFILL }},
{ &hf_llrp_min_freq,
{ "Minimum frequency", "llrp.param.min_freq", FT_UINT32, BASE_DEC, NULL, 0,
NULL, HFILL }},
{ &hf_llrp_max_freq,
{ "Maximum frequency", "llrp.param.max_freq", FT_UINT32, BASE_DEC, NULL, 0,
NULL, HFILL }},
{ &hf_llrp_rospec_id,
{ "ROSpec ID", "llrp.param.rospec_id", FT_UINT32, BASE_DEC, NULL, 0,
NULL, HFILL }},
{ &hf_llrp_priority,
{ "Priority", "llrp.param.priority", FT_UINT8, BASE_DEC, NULL, 0,
NULL, HFILL }},
{ &hf_llrp_cur_state,
{ "Current state", "llrp.param.cur_state", FT_UINT8, BASE_DEC, NULL, 0,
NULL, HFILL }},
{ &hf_llrp_rospec_start_trig_type,
{ "ROSpec start trigger type", "llrp.param.rospec_start_trig_type", FT_UINT8, BASE_DEC, NULL, 0,
NULL, HFILL }},
{ &hf_llrp_offset,
{ "Offset", "llrp.param.offset", FT_UINT32, BASE_DEC, NULL, 0,
NULL, HFILL }},
{ &hf_llrp_period,
{ "Period", "llrp.param.period", FT_UINT32, BASE_DEC, NULL, 0,
NULL, HFILL }},
{ &hf_llrp_gpi_event,
{ "GPI event", "llrp.param.gpi_event", FT_BOOLEAN, 8, TFS(&tfs_yes_no), 0x80,
NULL, HFILL }},
{ &hf_llrp_timeout,
{ "Timeout", "llrp.param.timeout", FT_UINT32, BASE_DEC, NULL, 0,
NULL, HFILL }},
{ &hf_llrp_rospec_stop_trig_type,
{ "ROSpec stop trigger type", "llrp.param.rospec_stop_trig_type", FT_UINT8, BASE_DEC, NULL, 0,
NULL, HFILL }},
{ &hf_llrp_duration_trig,
{ "Duration trigger value", "llrp.param.duration_trig", FT_UINT32, BASE_DEC, NULL, 0,
NULL, HFILL }},
{ &hf_llrp_antenna_count,
{ "Antenna count", "llrp.param.antenna_count", FT_UINT16, BASE_DEC, NULL, 0,
NULL, HFILL }},
{ &hf_llrp_antenna,
{ "Antenna ID", "llrp.param.antenna", FT_UINT16, BASE_DEC, NULL, 0,
NULL, HFILL }},
{ &hf_llrp_aispec_stop_trig_type,
{ "AISpec stop trigger type", "llrp.param.aispec_stop_trig_type", FT_UINT8, BASE_DEC, NULL, 0,
NULL, HFILL }},
{ &hf_llrp_trig_type,
{ "Trigger type", "llrp.param.trig_type", FT_UINT8, BASE_DEC, NULL, 0,
NULL, HFILL }},
{ &hf_llrp_number_of_tags,
{ "Number of tags", "llrp.param.number_of_tags", FT_UINT16, BASE_DEC, NULL, 0,
NULL, HFILL }},
{ &hf_llrp_number_of_attempts,
{ "Number of attempts", "llrp.param.number_of_attempts", FT_UINT16, BASE_DEC, NULL, 0,
NULL, HFILL }},
{ &hf_llrp_t,
{ "T", "llrp.param.t", FT_UINT16, BASE_DEC, NULL, 0,
NULL, HFILL }},
{ &hf_llrp_inventory_spec_id,
{ "Inventory parameter spec id", "llrp.param.inventory_spec_id", FT_UINT16, BASE_DEC, NULL, 0,
NULL, HFILL }},
{ &hf_llrp_start_freq,
{ "Start frequency", "llrp.param.start_freq", FT_UINT32, BASE_DEC, NULL, 0,
NULL, HFILL }},
{ &hf_llrp_stop_freq,
{ "Stop frequency", "llrp.param.stop_freq", FT_UINT32, BASE_DEC, NULL, 0,
NULL, HFILL }},
{ &hf_llrp_stop_trig_type,
{ "Stop trigger type", "llrp.param.stop_trig_type", FT_UINT8, BASE_DEC, NULL, 0,
NULL, HFILL }},
{ &hf_llrp_n_4,
{ "N", "llrp.param.n_4", FT_UINT32, BASE_DEC, NULL, 0,
NULL, HFILL }},
{ &hf_llrp_duration,
{ "Duration", "llrp.param.duration", FT_UINT32, BASE_DEC, NULL, 0,
NULL, HFILL }},
{ &hf_llrp_accessspec_id,
{ "AccessSpec ID", "llrp.param.accessspec_id", FT_UINT32, BASE_DEC, NULL, 0,
NULL, HFILL }},
{ &hf_llrp_access_cur_state,
{ "Current state", "llrp.param.access_cur_state", FT_BOOLEAN, 8, TFS(&tfs_yes_no), 0x80,
NULL, HFILL }},
{ &hf_llrp_access_stop_trig_type,
{ "AccessSpec Stop trigger", "llrp.param.access_stop_trig_type", FT_UINT8, BASE_DEC, NULL, 0,
NULL, HFILL }},
{ &hf_llrp_operation_count,
{ "Operation count value", "llrp.param.operation_count", FT_UINT16, BASE_DEC, NULL, 0,
NULL, HFILL }},
{ &hf_llrp_opspec_id,
{ "OpSpec ID", "llrp.param.opspec_id", FT_UINT16, BASE_DEC, NULL, 0,
NULL, HFILL }},
{ &hf_llrp_conf_value,
{ "Configuration value", "llrp.param.conf_value", FT_UINT32, BASE_DEC, NULL, 0,
NULL, HFILL }},
{ &hf_llrp_id_type,
{ "ID type", "llrp.param.id_type", FT_UINT8, BASE_DEC, VALS(id_type), 0,
NULL, HFILL }},
{ &hf_llrp_reader_id,
{ "Reader ID", "llrp.param.reader_id", FT_UINT_BYTES, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_llrp_gpo_data,
{ "GPO data", "llrp.param.gpo_data", FT_BOOLEAN, 8, TFS(&tfs_yes_no), 0x80,
NULL, HFILL }},
{ &hf_llrp_keepalive_trig_type,
{ "KeepAlive trigger type", "llrp.param.keepalive_trig_type", FT_UINT8, BASE_DEC, VALS(keepalive_type), 0,
NULL, HFILL }},
{ &hf_llrp_time_iterval,
{ "Time interval", "llrp.param.time_iterval", FT_UINT32, BASE_DEC, NULL, 0,
NULL, HFILL }},
{ &hf_llrp_antenna_connected,
{ "Antenna connected", "llrp.param.antenna_connected", FT_BOOLEAN, 8, TFS(&tfs_yes_no), 0x80,
NULL, HFILL }},
{ &hf_llrp_antenna_gain,
{ "Antenna gain", "llrp.param.antenna_gain", FT_UINT16, BASE_DEC, NULL, 0,
NULL, HFILL }},
{ &hf_llrp_receiver_sense,
{ "Receiver sensitivity", "llrp.param.receiver_sense", FT_UINT16, BASE_DEC, NULL, 0,
NULL, HFILL }},
{ &hf_llrp_channel_idx,
{ "Channel index", "llrp.param.channel_idx", FT_UINT16, BASE_DEC, NULL, 0,
NULL, HFILL }},
{ &hf_llrp_gpi_config,
{ "GPI config", "llrp.param.gpi_config", FT_BOOLEAN, 8, TFS(&tfs_yes_no), 0x80,
NULL, HFILL }},
{ &hf_llrp_gpi_state,
{ "GPI state", "llrp.param.gpi_state", FT_UINT16, BASE_DEC, NULL, 0,
NULL, HFILL }},
{ &hf_llrp_hold_events_and_reports,
{ "Hold events and reports upon reconnect", "llrp.param.hold_events_and_reports", FT_BOOLEAN, 8, TFS(&tfs_yes_no), 0x80,
NULL, HFILL }},
{ &hf_llrp_ro_report_trig,
{ "RO report trigger", "llrp.param.ro_report_trig", FT_UINT8, BASE_DEC, NULL, 0,
NULL, HFILL }},
{ &hf_llrp_n_2,
{ "N", "llrp.param.n_2", FT_UINT16, BASE_DEC, NULL, 0,
NULL, HFILL }},
{ &hf_llrp_enable_rospec_id,
{ "Enable ROSpec ID", "llrp.param.enable_rospec_id", FT_BOOLEAN, 16, TFS(&tfs_yes_no), 0x8000,
NULL, HFILL }},
{ &hf_llrp_enable_spec_idx,
{ "Enable spec index", "llrp.param.enable_spec_idx", FT_BOOLEAN, 16, TFS(&tfs_yes_no), 0x4000,
NULL, HFILL }},
{ &hf_llrp_enable_inv_spec_id,
{ "Enable inventory spec ID", "llrp.param.enable_inv_spec_id", FT_BOOLEAN, 16, TFS(&tfs_yes_no), 0x2000,
NULL, HFILL }},
{ &hf_llrp_enable_antenna_id,
{ "Enable antenna ID", "llrp.param.enable_antenna_id", FT_BOOLEAN, 16, TFS(&tfs_yes_no), 0x1000,
NULL, HFILL }},
{ &hf_llrp_enable_channel_idx,
{ "Enable channel index", "llrp.param.enable_channel_idx", FT_BOOLEAN, 16, TFS(&tfs_yes_no), 0x0800,
NULL, HFILL }},
{ &hf_llrp_enable_peak_rssi,
{ "Enable peak RSSI", "llrp.param.enable_peak_rssi", FT_BOOLEAN, 16, TFS(&tfs_yes_no), 0x0400,
NULL, HFILL }},
{ &hf_llrp_enable_first_seen,
{ "Enable first seen timestamp", "llrp.param.enable_first_seen", FT_BOOLEAN, 16, TFS(&tfs_yes_no), 0x0200,
NULL, HFILL }},
{ &hf_llrp_enable_last_seen,
{ "Enable last seen timestamp", "llrp.param.enable_last_seen", FT_BOOLEAN, 16, TFS(&tfs_yes_no), 0x0100,
NULL, HFILL }},
{ &hf_llrp_enable_seen_count,
{ "Enable tag seen count", "llrp.param.enable_seen_count", FT_BOOLEAN, 16, TFS(&tfs_yes_no), 0x0080,
NULL, HFILL }},
{ &hf_llrp_enable_accessspec_id,
{ "Enable AccessSpec ID", "llrp.param.enable_accessspec_id", FT_BOOLEAN, 16, TFS(&tfs_yes_no), 0x0040,
NULL, HFILL }},
{ &hf_llrp_access_report_trig,
{ "Access report trigger", "llrp.param.access_report_trig", FT_UINT8, BASE_DEC, NULL, 0,
NULL, HFILL }},
{ &hf_llrp_length_bits,
{ "Bit field length (bits)", "llrp.param.length_bits", FT_UINT16, BASE_DEC, NULL, 0,
NULL, HFILL }},
{ &hf_llrp_epc,
{ "EPC", "llrp.param.epc", FT_BYTES, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_llrp_spec_idx,
{ "Spec index", "llrp.param.spec_idx", FT_UINT16, BASE_DEC, NULL, 0,
NULL, HFILL }},
{ &hf_llrp_peak_rssi,
{ "Peak RSSI", "llrp.param.peak_rssi", FT_UINT8, BASE_DEC, NULL, 0,
NULL, HFILL }},
{ &hf_llrp_tag_count,
{ "Tag count", "llrp.param.tag_count", FT_UINT16, BASE_DEC, NULL, 0,
NULL, HFILL }},
{ &hf_llrp_bandwidth,
{ "Bandwidth", "llrp.param.bandwidth", FT_UINT32, BASE_DEC, NULL, 0,
NULL, HFILL }},
{ &hf_llrp_average_rssi,
{ "Average RSSI", "llrp.param.average_rssi", FT_UINT8, BASE_DEC, NULL, 0,
NULL, HFILL }},
{ &hf_llrp_notif_state,
{ "Notification state", "llrp.param.notif_state", FT_BOOLEAN, 8, TFS(&tfs_yes_no), 0x80,
NULL, HFILL }},
{ &hf_llrp_event_type,
{ "Event type", "llrp.param.event_type", FT_UINT16, BASE_DEC | BASE_EXT_STRING, &event_type_ext, 0,
NULL, HFILL }},
{ &hf_llrp_next_chan_idx,
{ "Next channel index", "llrp.param.next_chan_idx", FT_UINT16, BASE_DEC, NULL, 0,
NULL, HFILL }},
{ &hf_llrp_roevent_type,
{ "Event type", "llrp.param.roevent_type", FT_UINT8, BASE_DEC, VALS(roevent_type), 0,
NULL, HFILL }},
{ &hf_llrp_prem_rospec_id,
{ "Preempting ROSpec ID", "llrp.param.prem_rospec_id", FT_UINT32, BASE_DEC, NULL, 0,
NULL, HFILL }},
{ &hf_llrp_buffer_full_percentage,
{ "Report Buffer percentage full", "llrp.param.buffer_full_percentage", FT_UINT8, BASE_DEC, NULL, 0,
NULL, HFILL }},
{ &hf_llrp_message,
{ "Message", "llrp.param.message", FT_UINT_STRING, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_llrp_rfevent_type,
{ "Event type", "llrp.param.rfevent_type", FT_UINT8, BASE_DEC, VALS(rfevent_type), 0,
NULL, HFILL }},
{ &hf_llrp_aievent_type,
{ "Event type", "llrp.param.aievent_type", FT_UINT8, BASE_DEC, VALS(aievent_type), 0,
NULL, HFILL }},
{ &hf_llrp_antenna_event_type,
{ "Event type", "llrp.param.antenna_event_type", FT_UINT8, BASE_DEC, VALS(antenna_event_type), 0,
NULL, HFILL }},
{ &hf_llrp_conn_status,
{ "Status", "llrp.param.conn_status", FT_UINT16, BASE_DEC, VALS(connection_status), 0,
NULL, HFILL }},
{ &hf_llrp_loop_count,
{ "Loop count", "llrp.param.loop_count", FT_UINT32, BASE_DEC, NULL, 0,
NULL, HFILL }},
{ &hf_llrp_status_code,
{ "Status code", "llrp.param.status_code", FT_UINT16, BASE_DEC | BASE_EXT_STRING, &status_code_ext, 0,
NULL, HFILL }},
{ &hf_llrp_error_desc,
{ "Error Description", "llrp.param.error_desc", FT_UINT_STRING, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_llrp_field_num,
{ "Field number", "llrp.param.field_num", FT_UINT16, BASE_DEC, NULL, 0,
NULL, HFILL }},
{ &hf_llrp_error_code,
{ "Error code", "llrp.param.error_code", FT_UINT16, BASE_DEC | BASE_EXT_STRING, &status_code_ext, 0,
NULL, HFILL }},
{ &hf_llrp_parameter_type,
{ "Parameter type", "llrp.param.parameter_type", FT_UINT16, BASE_DEC | BASE_EXT_STRING, &tlv_type_ext, 0,
NULL, HFILL }},
{ &hf_llrp_can_support_block_erase,
{ "Can support block erase", "llrp.param.can_support_block_erase", FT_BOOLEAN, 8, TFS(&tfs_yes_no), 0x80,
NULL, HFILL }},
{ &hf_llrp_can_support_block_write,
{ "Can support block write", "llrp.param.can_support_block_write", FT_BOOLEAN, 8, TFS(&tfs_yes_no), 0x40,
NULL, HFILL }},
{ &hf_llrp_can_support_block_permalock,
{ "Can support block permalock", "llrp.param.can_support_block_permalock", FT_BOOLEAN, 8, TFS(&tfs_yes_no), 0x20,
NULL, HFILL }},
{ &hf_llrp_can_support_tag_recomm,
{ "Can support tag recommisioning", "llrp.param.can_support_tag_recomm", FT_BOOLEAN, 8, TFS(&tfs_yes_no), 0x10,
NULL, HFILL }},
{ &hf_llrp_can_support_UMI_method2,
{ "Can support UMI method 2", "llrp.param.can_support_UMI_method2", FT_BOOLEAN, 8, TFS(&tfs_yes_no), 0x08,
NULL, HFILL }},
{ &hf_llrp_can_support_XPC,
{ "Can support XPC", "llrp.param.can_support_XPC", FT_BOOLEAN, 8, TFS(&tfs_yes_no), 0x04,
NULL, HFILL }},
{ &hf_llrp_max_num_filter_per_query,
{ "Maximum number of select filters per query", "llrp.param.max_num_filter_per_query", FT_UINT16, BASE_DEC, NULL, 0,
NULL, HFILL }},
{ &hf_llrp_mode_ident,
{ "Mode identifier", "llrp.param.mode_ident", FT_UINT32, BASE_DEC, NULL, 0,
NULL, HFILL }},
{ &hf_llrp_DR,
{ "DR", "llrp.param.DR", FT_BOOLEAN, 8, TFS(&tfs_yes_no), 0x80,
NULL, HFILL }},
{ &hf_llrp_hag_conformance,
{ "EPC HAG T&C Conformance", "llrp.param.hag_conformance", FT_BOOLEAN, 8, TFS(&tfs_yes_no), 0x40,
NULL, HFILL }},
{ &hf_llrp_mod,
{ "M", "llrp.param.mod", FT_UINT8, BASE_DEC, NULL, 0,
NULL, HFILL }},
{ &hf_llrp_flm,
{ "Forward link modulation", "llrp.param.flm", FT_UINT8, BASE_DEC, NULL, 0,
NULL, HFILL }},
{ &hf_llrp_m,
{ "Spectral mask indicator", "llrp.param.m", FT_UINT8, BASE_DEC, NULL, 0,
NULL, HFILL }},
{ &hf_llrp_bdr,
{ "BDR", "llrp.param.bdr", FT_UINT32, BASE_DEC, NULL, 0,
NULL, HFILL }},
{ &hf_llrp_pie,
{ "PIE", "llrp.param.pie", FT_UINT32, BASE_DEC, NULL, 0,
NULL, HFILL }},
{ &hf_llrp_min_tari,
{ "Minimum tari", "llrp.param.min_tari", FT_UINT32, BASE_DEC, NULL, 0,
NULL, HFILL }},
{ &hf_llrp_max_tari,
{ "Maximum tari", "llrp.param.max_tari", FT_UINT32, BASE_DEC, NULL, 0,
NULL, HFILL }},
{ &hf_llrp_step_tari,
{ "Tari step", "llrp.param.step_tari", FT_UINT32, BASE_DEC, NULL, 0,
NULL, HFILL }},
{ &hf_llrp_inventory_state_aware,
{ "Tag inventory state aware", "llrp.param.inventory_state_aware", FT_BOOLEAN, 8, TFS(&tfs_yes_no), 0x80,
NULL, HFILL }},
{ &hf_llrp_trunc,
{ "T", "llrp.param.trunc", FT_UINT8, BASE_DEC, NULL, 0xC0,
NULL, HFILL }},
{ &hf_llrp_mb,
{ "MB", "llrp.param.mb", FT_UINT8, BASE_DEC, NULL, 0xC0,
NULL, HFILL }},
{ &hf_llrp_pointer,
{ "Pointer", "llrp.param.pointer", FT_UINT16, BASE_DEC_HEX, NULL, 0,
NULL, HFILL }},
{ &hf_llrp_tag_mask,
{ "Tag mask", "llrp.param.tag_mask", FT_BYTES, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_llrp_aware_filter_target,
{ "Target", "llrp.param.aware_filter_target", FT_UINT8, BASE_DEC, NULL, 0,
NULL, HFILL }},
{ &hf_llrp_aware_filter_action,
{ "Action", "llrp.param.aware_filter_action", FT_UINT8, BASE_DEC, NULL, 0,
NULL, HFILL }},
{ &hf_llrp_unaware_filter_action,
{ "Action", "llrp.param.unaware_filter_action", FT_UINT8, BASE_DEC, NULL, 0,
NULL, HFILL }},
{ &hf_llrp_mode_idx,
{ "Mode index", "llrp.param.mode_idx", FT_UINT16, BASE_DEC, NULL, 0,
NULL, HFILL }},
{ &hf_llrp_tari,
{ "Tari", "llrp.param.tari", FT_UINT16, BASE_DEC, NULL, 0,
NULL, HFILL }},
{ &hf_llrp_session,
{ "Session", "llrp.param.session", FT_UINT8, BASE_DEC, NULL, 0xC0,
NULL, HFILL }},
{ &hf_llrp_tag_population,
{ "Tag population", "llrp.param.tag_population", FT_UINT16, BASE_DEC, NULL, 0,
NULL, HFILL }},
{ &hf_llrp_tag_transit_time,
{ "Tag tranzit time", "llrp.param.tag_transit_time", FT_UINT32, BASE_DEC, NULL, 0,
NULL, HFILL }},
{ &hf_llrp_sing_i,
{ "I", "llrp.param.sing_i", FT_BOOLEAN, 8, TFS(&tfs_state_a_b), 0x80,
NULL, HFILL }},
{ &hf_llrp_sing_s,
{ "S", "llrp.param.sing_s", FT_BOOLEAN, 8, TFS(&tfs_sl), 0x40,
NULL, HFILL }},
{ &hf_llrp_sing_a,
{ "S_All", "llrp.param.sing_a", FT_BOOLEAN, 8, TFS(&tfs_all_no), 0x20,
NULL, HFILL }},
{ &hf_llrp_match,
{ "Match", "llrp.param.match", FT_BOOLEAN, 8, TFS(&tfs_yes_no), 0x20,
NULL, HFILL }},
{ &hf_llrp_tag_data,
{ "Tag data", "llrp.param.tag_data", FT_BYTES, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_llrp_access_pass,
{ "Access password", "llrp.param.access_pass", FT_UINT32, BASE_DEC_HEX, NULL, 0,
NULL, HFILL }},
{ &hf_llrp_word_pointer,
{ "Word pointer", "llrp.param.word_pointer", FT_UINT16, BASE_DEC_HEX, NULL, 0,
NULL, HFILL }},
{ &hf_llrp_word_count,
{ "Word count", "llrp.param.word_count", FT_UINT16, BASE_DEC, NULL, 0,
NULL, HFILL }},
{ &hf_llrp_write_data,
{ "Write data", "llrp.param.write_data", FT_BYTES, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_llrp_kill_pass,
{ "Killpassword", "llrp.param.kill_pass", FT_UINT32, BASE_DEC_HEX, NULL, 0,
NULL, HFILL }},
{ &hf_llrp_kill_3,
{ "3", "llrp.param.kill_3", FT_BOOLEAN, 8, TFS(&tfs_yes_no), 0x04,
NULL, HFILL }},
{ &hf_llrp_kill_2,
{ "2", "llrp.param.kill_2", FT_BOOLEAN, 8, TFS(&tfs_yes_no), 0x02,
NULL, HFILL }},
{ &hf_llrp_kill_l,
{ "L", "llrp.param.kill_l", FT_BOOLEAN, 8, TFS(&tfs_yes_no), 0x01,
NULL, HFILL }},
{ &hf_llrp_privilege,
{ "Privilege", "llrp.param.privilege", FT_UINT8, BASE_DEC, NULL, 0,
NULL, HFILL }},
{ &hf_llrp_data_field,
{ "Data field", "llrp.param.data_field", FT_UINT8, BASE_DEC, NULL, 0,
NULL, HFILL }},
{ &hf_llrp_block_pointer,
{ "Block pointer", "llrp.param.block_pointer", FT_UINT16, BASE_DEC_HEX, NULL, 0,
NULL, HFILL }},
{ &hf_llrp_block_mask,
{ "Block mask", "llrp.param.block_mask", FT_BYTES, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_llrp_length_words,
{ "Field Length (words)", "llrp.param.length_words", FT_UINT16, BASE_DEC, NULL, 0,
NULL, HFILL }},
{ &hf_llrp_block_range,
{ "Block range", "llrp.param.block_range", FT_UINT16, BASE_DEC, NULL, 0,
NULL, HFILL }},
{ &hf_llrp_enable_crc,
{ "Enable CRC", "llrp.param.enable_crc", FT_BOOLEAN, 8, TFS(&tfs_yes_no), 0x80,
NULL, HFILL }},
{ &hf_llrp_enable_pc,
{ "Enable PC bits", "llrp.param.enable_pc", FT_BOOLEAN, 8, TFS(&tfs_yes_no), 0x40,
NULL, HFILL }},
{ &hf_llrp_enable_xpc,
{ "Enable XPC bits", "llrp.param.enable_xpc", FT_BOOLEAN, 8, TFS(&tfs_yes_no), 0x20,
NULL, HFILL }},
{ &hf_llrp_pc_bits,
{ "PC bits", "llrp.param.pc_bits", FT_UINT16, BASE_HEX, NULL, 0,
NULL, HFILL }},
{ &hf_llrp_xpc_w1,
{ "XPC-W1", "llrp.param.xpc_w1", FT_UINT16, BASE_HEX, NULL, 0,
NULL, HFILL }},
{ &hf_llrp_xpc_w2,
{ "XPC-W2", "llrp.param.xpc_w2", FT_UINT16, BASE_HEX, NULL, 0,
NULL, HFILL }},
{ &hf_llrp_crc,
{ "CRC", "llrp.param.crc", FT_UINT16, BASE_HEX, NULL, 0,
NULL, HFILL }},
{ &hf_llrp_num_coll,
{ "Number of collisions", "llrp.param.num_coll", FT_UINT16, BASE_DEC, NULL, 0,
NULL, HFILL }},
{ &hf_llrp_num_empty,
{ "Number of empty slots", "llrp.param.num_empty", FT_UINT16, BASE_DEC, NULL, 0,
NULL, HFILL }},
{ &hf_llrp_access_result,
{ "Result", "llrp.param.access_result", FT_UINT8, BASE_DEC, NULL, 0,
NULL, HFILL }},
{ &hf_llrp_read_data,
{ "Read data", "llrp.param.read_data", FT_BYTES, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_llrp_num_words_written,
{ "Number of words written", "llrp.param.num_words_written", FT_UINT16, BASE_DEC, NULL, 0,
NULL, HFILL }},
{ &hf_llrp_permlock_status,
{ "Read data", "llrp.param.permlock_status", FT_BYTES, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_llrp_vendor_id,
{ "Vendor ID", "llrp.param.vendor_id", FT_UINT32, BASE_DEC, VALS(llrp_vendors), 0,
NULL, HFILL }},
{ &hf_llrp_impinj_param_type,
{ "Impinj parameter subtype", "llrp.param.impinj_param_type", FT_UINT32, BASE_DEC | BASE_EXT_STRING, &impinj_param_type_ext, 0,
NULL, HFILL }},
{ &hf_llrp_save_config,
{ "Save configuration", "llrp.param.save_config", FT_BOOLEAN, 8, TFS(&tfs_yes_no), 0x80,
NULL, HFILL }},
{ &hf_llrp_impinj_req_data,
{ "Requested data", "llrp.param.impinj_req_data", FT_UINT32, BASE_DEC | BASE_EXT_STRING, &impinj_req_data_ext, 0,
NULL, HFILL }},
{ &hf_llrp_impinj_reg_region,
{ "Regulatory region", "llrp.param.impinj_reg_region", FT_UINT16, BASE_DEC | BASE_EXT_STRING, &impinj_reg_region_ext, 0,
NULL, HFILL }},
{ &hf_llrp_impinj_search_mode,
{ "Inventory search mode", "llrp.param.impinj_search_mode", FT_UINT16, BASE_DEC, VALS(impinj_search_mode), 0,
NULL, HFILL }},
{ &hf_llrp_impinj_en_tag_dir,
{ "Enable tag direction", "llrp.param.impinj_en_tag_dir", FT_BOOLEAN, 16, TFS(&tfs_yes_no), 0x8000,
NULL, HFILL }},
{ &hf_llrp_impinj_antenna_conf,
{ "Antenna configuration", "llrp.param.impinj_antenna_conf", FT_UINT16, BASE_DEC, VALS(impinj_ant_conf), 0,
NULL, HFILL }},
{ &hf_llrp_decision_time,
{ "Decision timestamp", "llrp.param.decision_time", FT_UINT64, BASE_DEC, NULL, 0,
NULL, HFILL }},
{ &hf_llrp_impinj_tag_dir,
{ "Tag direction", "llrp.param.impinj_tag_dir", FT_UINT16, BASE_DEC, VALS(impinj_tag_dir), 0,
NULL, HFILL }},
{ &hf_llrp_confidence,
{ "Confidence", "llrp.param.confidence", FT_UINT16, BASE_DEC, NULL, 0,
NULL, HFILL }},
{ &hf_llrp_impinj_fix_freq_mode,
{ "Fixed frequency mode", "llrp.param.impinj_fix_freq_mode", FT_UINT16, BASE_DEC, VALS(impinj_fix_freq_mode), 0,
NULL, HFILL }},
{ &hf_llrp_num_channels,
{ "Number of channels", "llrp.param.num_channels", FT_UINT16, BASE_DEC, NULL, 0,
NULL, HFILL }},
{ &hf_llrp_channel,
{ "Channel", "llrp.param.channel", FT_UINT16, BASE_DEC, NULL, 0,
NULL, HFILL }},
{ &hf_llrp_impinj_reduce_power_mode,
{ "Recuced power mode", "llrp.param.impinj_reduce_power_mode", FT_UINT16, BASE_DEC, VALS(impinj_boolean), 0,
NULL, HFILL }},
{ &hf_llrp_impinj_low_duty_mode,
{ "Low duty cycle mode", "llrp.param.impinj_low_duty_mode", FT_UINT16, BASE_DEC, VALS(impinj_boolean), 0,
NULL, HFILL }},
{ &hf_llrp_empty_field_timeout,
{ "Empty field timeout", "llrp.param.empty_field_timeout", FT_UINT16, BASE_DEC, NULL, 0,
NULL, HFILL }},
{ &hf_llrp_field_ping_interval,
{ "Field ping interval", "llrp.param.field_ping_interval", FT_UINT16, BASE_DEC, NULL, 0,
NULL, HFILL }},
{ &hf_llrp_model_name,
{ "Model name", "llrp.param.model_name", FT_UINT_STRING, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_llrp_serial_number,
{ "Serial number", "llrp.param.serial_number", FT_UINT_STRING, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_llrp_soft_ver,
{ "Softwave version", "llrp.param.soft_ver", FT_UINT_STRING, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_llrp_firm_ver,
{ "Firmware version", "llrp.param.firm_ver", FT_UINT_STRING, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_llrp_fpga_ver,
{ "FPGA version", "llrp.param.fpga_ver", FT_UINT_STRING, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_llrp_pcba_ver,
{ "PCBA version", "llrp.param.pcba_ver", FT_UINT_STRING, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_llrp_height_thresh,
{ "Height threshold", "llrp.param.height_thresh", FT_UINT16, BASE_DEC, NULL, 0,
NULL, HFILL }},
{ &hf_llrp_zero_motion_thresh,
{ "Zero motion threshold", "llrp.param.zero_motion_thresh", FT_UINT16, BASE_DEC, NULL, 0,
NULL, HFILL }},
{ &hf_llrp_board_manufacturer,
{ "Board manufacturer", "llrp.param.board_manufacturer", FT_UINT_STRING, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_llrp_fw_ver_hex,
{ "Firmware version", "llrp.param.fw_ver_hex", FT_UINT_BYTES, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_llrp_hw_ver_hex,
{ "Hardware version", "llrp.param.hw_ver_hex", FT_UINT_BYTES, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_llrp_gpi_debounce,
{ "GPI debounce timer Msec", "llrp.param.gpi_debounce", FT_UINT16, BASE_DEC, NULL, 0,
NULL, HFILL }},
{ &hf_llrp_temperature,
{ "Temperature", "llrp.param.temperature", FT_INT16, BASE_DEC, NULL, 0,
NULL, HFILL }},
{ &hf_llrp_impinj_link_monitor_mode,
{ "Link monitor mode", "llrp.param.impinj_link_monitor_mode", FT_UINT16, BASE_DEC, VALS(impinj_boolean), 0,
NULL, HFILL }},
{ &hf_llrp_link_down_thresh,
{ "Link down threshold", "llrp.param.link_down_thresh", FT_UINT16, BASE_DEC, NULL, 0,
NULL, HFILL }},
{ &hf_llrp_impinj_report_buff_mode,
{ "Report buffer mode", "llrp.param.impinj_report_buff_mode", FT_UINT16, BASE_DEC, VALS(impinj_report_buff_mode), 0,
NULL, HFILL }},
{ &hf_llrp_permalock_result,
{ "Result", "llrp.param.permalock_result", FT_UINT8, BASE_DEC | BASE_EXT_STRING, &impinj_permalock_result_ext, 0,
NULL, HFILL }},
{ &hf_llrp_block_permalock_result,
{ "Result", "llrp.param.block_permalock_result", FT_UINT8, BASE_DEC | BASE_EXT_STRING, &impinj_block_permalock_result_ext, 0,
NULL, HFILL }},
{ &hf_llrp_impinj_data_profile,
{ "Data profile", "llrp.param.impinj_data_profile", FT_UINT8, BASE_DEC, VALS(impinj_data_profile), 0,
NULL, HFILL }},
{ &hf_llrp_impinj_access_range,
{ "Access range", "llrp.param.impinj_access_range", FT_UINT8, BASE_DEC, VALS(impinj_access_range), 0,
NULL, HFILL }},
{ &hf_llrp_impinj_persistence,
{ "Persistence", "llrp.param.impinj_persistence", FT_UINT8, BASE_DEC, VALS(impinj_persistence), 0,
NULL, HFILL }},
{ &hf_llrp_set_qt_config_result,
{ "Result", "llrp.param.set_qt_config_result", FT_UINT8, BASE_DEC | BASE_EXT_STRING, &impinj_set_qt_config_result_ext, 0,
NULL, HFILL }},
{ &hf_llrp_get_qt_config_result,
{ "Result", "llrp.param.get_qt_config_result", FT_UINT8, BASE_DEC | BASE_EXT_STRING, &impinj_get_qt_config_result_ext, 0,
NULL, HFILL }},
{ &hf_llrp_impinj_serialized_tid_mode,
{ "Serialized TID Mode", "llrp.param.impinj_serialized_tid_mode", FT_UINT16, BASE_DEC, VALS(impinj_boolean), 0,
NULL, HFILL }},
{ &hf_llrp_impinj_rf_phase_mode,
{ "RF phase angle mode", "llrp.param.impinj_rf_phase_mode", FT_UINT16, BASE_DEC, VALS(impinj_boolean), 0,
NULL, HFILL }},
{ &hf_llrp_impinj_peak_rssi_mode,
{ "Peak RSSI mode", "llrp.param.impinj_peak_rssi_mode", FT_UINT16, BASE_DEC, VALS(impinj_boolean), 0,
NULL, HFILL }},
{ &hf_llrp_impinj_gps_coordinates_mode,
{ "GPS coordinates mode", "llrp.param.impinj_gps_coordinates_mode", FT_UINT16, BASE_DEC, VALS(impinj_boolean), 0,
NULL, HFILL }},
{ &hf_llrp_impinj_tid,
{ "TID", "llrp.param.impinj_tid", FT_UINT_BYTES, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_llrp_phase_angle,
{ "Phase angle", "llrp.param.phase_angle", FT_UINT16, BASE_DEC, NULL, 0,
NULL, HFILL }},
{ &hf_llrp_rssi,
{ "RSSI", "llrp.param.rssi", FT_INT16, BASE_DEC, NULL, 0,
NULL, HFILL }},
{ &hf_llrp_latitude,
{ "Latitude", "llrp.param.latitude", FT_INT32, BASE_DEC, NULL, 0,
NULL, HFILL }},
{ &hf_llrp_longitude,
{ "Longitude", "llrp.param.longitude", FT_INT32, BASE_DEC, NULL, 0,
NULL, HFILL }},
{ &hf_llrp_gga_sentence,
{ "GGA sentence", "llrp.param.gga_sentence", FT_UINT_STRING, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_llrp_rmc_sentence,
{ "RMC sentence", "llrp.param.rmc_sentence", FT_UINT_STRING, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_llrp_impinj_optim_read_mode,
{ "Optimized read mode", "llrp.param.impinj_optim_read_mode", FT_UINT16, BASE_DEC, VALS(impinj_boolean), 0,
NULL, HFILL }},
{ &hf_llrp_impinj_rf_doppler_mode,
{ "RF doppler frequency mode", "llrp.param.impinj_rf_doppler_mode", FT_UINT16, BASE_DEC, VALS(impinj_boolean), 0,
NULL, HFILL }},
{ &hf_llrp_retry_count,
{ "Retry count", "llrp.param.retry_count", FT_UINT16, BASE_DEC, NULL, 0,
NULL, HFILL }},
{ &hf_llrp_impinj_access_spec_ordering,
{ "AccessSpec ordering", "llrp.param.impinj_access_spec_ordering", FT_UINT16, BASE_DEC, VALS(impinj_access_spec_ordering), 0,
NULL, HFILL }},
{ &hf_llrp_impinj_gpo_mode,
{ "GPO mode", "llrp.param.impinj_gpo_mode", FT_UINT16, BASE_DEC | BASE_EXT_STRING, &impinj_gpo_mode_ext, 0,
NULL, HFILL }},
{ &hf_llrp_gpo_pulse_dur,
{ "GPO pulse duration", "llrp.param.gpo_pulse_dur", FT_UINT32, BASE_DEC, NULL, 0,
NULL, HFILL }},
{ &hf_llrp_impinj_hub_id,
{ "Hub ID", "llrp.impinj_hub_id", FT_UINT16, BASE_DEC, NULL, 0,
NULL, HFILL }},
{ &hf_llrp_impinj_hub_fault_type,
{ "Hub fault type", "llrp.param.impinj_hub_fault_type", FT_UINT16, BASE_DEC | BASE_EXT_STRING, &impinj_hub_fault_type_ext, 0,
NULL, HFILL }},
{ &hf_llrp_impinj_hub_connected_type,
{ "Hub connected type", "llrp.param.impinj_hub_connected_type", FT_UINT16, BASE_DEC | BASE_EXT_STRING, &impinj_hub_connected_type_ext, 0,
NULL, HFILL }},
};
static gint *ett[] = {
&ett_llrp,
&ett_llrp_param
};
static ei_register_info ei[] = {
{ &ei_llrp_invalid_length, { "llrp.invalid_length_of_string_claimed", PI_MALFORMED, PI_ERROR, "invalid length of string: claimed %u, available %u.", EXPFILL }},
{ &ei_llrp_req_conf, { "llrp.req_conf.invalid", PI_PROTOCOL, PI_ERROR, "Unrecognized configuration request: %u", EXPFILL }},
};
expert_module_t* expert_llrp;
proto_llrp = proto_register_protocol("Low Level Reader Protocol",
"LLRP", "llrp");
proto_register_field_array(proto_llrp, hf, array_length(hf));
proto_register_subtree_array(ett, array_length(ett));
expert_llrp = expert_register_protocol(proto_llrp);
expert_register_field_array(expert_llrp, ei, array_length(ei));
}
void
proto_reg_handoff_llrp(void)
{
dissector_handle_t llrp_handle;
llrp_handle = new_create_dissector_handle(dissect_llrp, proto_llrp);
dissector_add_uint("tcp.port", LLRP_PORT, llrp_handle);
}
