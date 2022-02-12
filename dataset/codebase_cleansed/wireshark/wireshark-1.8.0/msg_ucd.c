void dissect_mac_mgmt_msg_ucd_decoder(tvbuff_t *tvb, packet_info *pinfo, proto_tree *tree)
{
guint offset = 0;
guint tvb_len, payload_type, length;
gint tlv_type, tlv_len, tlv_offset, tlv_value_offset;
tlv_info_t tlv_info;
payload_type = tvb_get_guint8(tvb, offset);
if(payload_type != MAC_MGMT_MSG_UCD)
{
return;
}
if(tree)
{
proto_item *ucd_item;
proto_tree *ucd_tree;
guint ucd_config_change_count;
guint ucd_ranging_backoff_start;
guint ucd_ranging_backoff_end;
guint ucd_request_backoff_start;
guint ucd_request_backoff_end;
tvb_len = tvb_reported_length(tvb);
ucd_item = proto_tree_add_protocol_format(tree, proto_mac_mgmt_msg_ucd_decoder, tvb, offset, tvb_len, "Uplink Channel Descriptor (UCD) (%u bytes)", tvb_len);
ucd_tree = proto_item_add_subtree(ucd_item, ett_mac_mgmt_msg_ucd_decoder);
proto_tree_add_item(ucd_tree, hf_ucd_message_type, tvb, offset, 1, ENC_BIG_ENDIAN);
offset++;
ucd_config_change_count = tvb_get_guint8(tvb, offset);
proto_tree_add_text(ucd_tree, tvb, offset, 1, "Configuration Change Count: %u", ucd_config_change_count);
offset++;
ucd_ranging_backoff_start = tvb_get_guint8(tvb, offset);
proto_tree_add_text(ucd_tree, tvb, offset, 1, "Ranging Backoff Start: 2^%u = %u", ucd_ranging_backoff_start, (1 << ucd_ranging_backoff_start));
offset++;
ucd_ranging_backoff_end = tvb_get_guint8(tvb, offset);
proto_tree_add_text(ucd_tree, tvb, offset, 1, "Ranging Backoff End: 2^%u = %u", ucd_ranging_backoff_end, (1 << ucd_ranging_backoff_end));
offset++;
ucd_request_backoff_start = tvb_get_guint8(tvb, offset);
proto_tree_add_text(ucd_tree, tvb, offset, 1, "Request Backoff Start: 2^%u = %u", ucd_request_backoff_start, (1 << ucd_request_backoff_start));
offset++;
ucd_request_backoff_end = tvb_get_guint8(tvb, offset);
proto_tree_add_text(ucd_tree, tvb, offset, 1, "Request Backoff End: 2^%u = %u", ucd_request_backoff_end, (1 << ucd_request_backoff_end));
offset++;
while(offset < tvb_len)
{
init_tlv_info(&tlv_info, tvb, offset);
tlv_type = get_tlv_type(&tlv_info);
tlv_len = get_tlv_length(&tlv_info);
if(tlv_type == -1 || tlv_len > MAX_TLV_LEN || tlv_len < 1)
{
col_append_sep_str(pinfo->cinfo, COL_INFO, NULL, "UCD TLV error");
proto_tree_add_item(ucd_tree,hf_ucd_invalid_tlv, tvb, offset, (tvb_len - offset), ENC_NA);
break;
}
tlv_value_offset = get_tlv_value_offset(&tlv_info);
#ifdef DEBUG
proto_tree_add_protocol_format(ucd_tree, proto_mac_mgmt_msg_ucd_decoder, tvb, offset, (tlv_len + tlv_value_offset), "UCD Type: %u (%u bytes, offset=%u, tvb_len=%u)", tlv_type, tlv_len, offset, tvb_len);
#endif
offset += tlv_value_offset;
if (include_cor2_changes)
{
switch (tlv_type)
{
proto_tree *tlv_tree;
case UCD_TLV_T_203_UL_PUSC_SUBCHANNEL_ROTATION:
{
tlv_tree = add_tlv_subtree(&tlv_info, ett_mac_mgmt_msg_ucd_decoder, ucd_tree, hf_ucd_tlv_t_203_ul_pusc_subchannel_rotation, tvb, offset, tlv_len, FALSE);
proto_tree_add_item(tlv_tree, hf_ucd_tlv_t_203_ul_pusc_subchannel_rotation, tvb, offset, tlv_len, ENC_BIG_ENDIAN);
break;
}
case UCD_TLV_T_205_RELATIVE_POWER_OFFSET_UL_HARQ_BURST:
{
tlv_tree = add_tlv_subtree(&tlv_info, ett_mac_mgmt_msg_ucd_decoder, ucd_tree, hf_ucd_tlv_t_205_relative_power_offset_ul_harq_burst, tvb, offset, tlv_len, FALSE);
proto_tree_add_item(tlv_tree, hf_ucd_tlv_t_205_relative_power_offset_ul_harq_burst, tvb, offset, tlv_len, ENC_BIG_ENDIAN);
break;
}
case UCD_TLV_T_206_RELATIVE_POWER_OFFSET_UL_BURST_CONTAINING_MAC_MGMT_MSG:
{
tlv_tree = add_tlv_subtree(&tlv_info, ett_mac_mgmt_msg_ucd_decoder, ucd_tree, hf_ucd_tlv_t_206_relative_power_offset_ul_burst_containing_mac_mgmt_msg, tvb, offset, tlv_len, FALSE);
proto_tree_add_item(tlv_tree, hf_ucd_tlv_t_206_relative_power_offset_ul_burst_containing_mac_mgmt_msg, tvb, offset, tlv_len, ENC_BIG_ENDIAN);
break;
}
case UCD_TLV_T_207_UL_INITIAL_TRANSMIT_TIMING:
{
tlv_tree = add_tlv_subtree(&tlv_info, ett_mac_mgmt_msg_ucd_decoder, ucd_tree, hf_ucd_tlv_t_207_ul_initial_transmit_timing, tvb, offset, tlv_len, FALSE);
proto_tree_add_item(tlv_tree, hf_ucd_tlv_t_207_ul_initial_transmit_timing, tvb, offset, tlv_len, ENC_BIG_ENDIAN);
break;
}
case UCD_TLV_T_210_FAST_FEEDBACK_REGION:
{
tlv_tree = add_tlv_subtree(&tlv_info, ett_mac_mgmt_msg_ucd_decoder, ucd_tree, hf_ucd_tlv_t_210_fast_feedback_region, tvb, offset, tlv_len, FALSE);
proto_tree_add_item(tlv_tree, hf_ucd_tlv_t_210_fast_feedback_region, tvb, offset, tlv_len, ENC_NA);
break;
}
case UCD_TLV_T_211_HARQ_ACK_REGION:
{
tlv_tree = add_tlv_subtree(&tlv_info, ett_mac_mgmt_msg_ucd_decoder, ucd_tree, hf_ucd_tlv_t_211_harq_ack_region, tvb, offset, tlv_len, FALSE);
proto_tree_add_item(tlv_tree, hf_ucd_tlv_t_211_harq_ack_region, tvb, offset, tlv_len, ENC_NA);
break;
}
case UCD_TLV_T_212_RANGING_REGION:
{
tlv_tree = add_tlv_subtree(&tlv_info, ett_mac_mgmt_msg_ucd_decoder, ucd_tree, hf_ucd_tlv_t_212_ranging_region, tvb, offset, tlv_len, FALSE);
proto_tree_add_item(tlv_tree, hf_ucd_tlv_t_212_ranging_region, tvb, offset, tlv_len, ENC_NA);
break;
}
case UCD_TLV_T_213_SOUNDING_REGION:
{
tlv_tree = add_tlv_subtree(&tlv_info, ett_mac_mgmt_msg_ucd_decoder, ucd_tree, hf_ucd_tlv_t_213_sounding_region, tvb, offset, tlv_len, FALSE);
proto_tree_add_item(tlv_tree, hf_ucd_tlv_t_213_sounding_region, tvb, offset, tlv_len, ENC_NA);
break;
}
}
}
switch (tlv_type)
{
proto_tree *tlv_tree;
proto_item *tlv_item1;
guint ul_burst_uiuc;
guint utemp;
case UCD_UPLINK_BURST_PROFILE:
{
ul_burst_uiuc = tvb_get_guint8(tvb, offset) & 0x0F;
tlv_tree = add_protocol_subtree(&tlv_info, ett_mac_mgmt_msg_ucd_decoder, ucd_tree, proto_mac_mgmt_msg_ucd_decoder, tvb, offset, tlv_len, "Uplink Burst Profile (UIUC = %u) (%u bytes)", ul_burst_uiuc, tlv_len);
proto_tree_add_item(tlv_tree, hf_ucd_ul_burst_reserved, tvb, offset, 1, ENC_BIG_ENDIAN);
proto_tree_add_item(tlv_tree, hf_ucd_ul_burst_uiuc, tvb, offset, 1, ENC_BIG_ENDIAN);
for (tlv_offset = 1; tlv_offset < tlv_len;)
{
init_tlv_info(&tlv_info, tvb, (offset+tlv_offset));
tlv_type = get_tlv_type(&tlv_info);
if(tlv_type == -1)
{
col_append_sep_str(pinfo->cinfo, COL_INFO, NULL, "UL Burst Profile error");
proto_tree_add_item(tlv_tree, hf_ucd_invalid_tlv, tvb, offset, (tlv_len - offset - tlv_offset), ENC_NA);
break;
}
length = get_tlv_length(&tlv_info);
tlv_offset += get_tlv_value_offset(&tlv_info);
switch (tlv_type)
{
proto_tree *sub_tree;
proto_item *tlv_item2;
case UCD_BURST_FEC:
{
sub_tree = add_tlv_subtree(&tlv_info, ett_mac_mgmt_msg_ucd_decoder, tlv_tree, hf_ucd_burst_fec, tvb, (offset+tlv_offset), 1, FALSE);
proto_tree_add_item(sub_tree, hf_ucd_burst_fec, tvb, (offset+tlv_offset), 1, ENC_BIG_ENDIAN);
break;
}
case UCD_BURST_RANGING_DATA_RATIO:
{
sub_tree = add_tlv_subtree(&tlv_info, ett_mac_mgmt_msg_ucd_decoder, tlv_tree, hf_ucd_burst_ranging_data_ratio, tvb, (offset+tlv_offset), 1, FALSE);
tlv_item2 = proto_tree_add_item(sub_tree, hf_ucd_burst_ranging_data_ratio, tvb, (offset+tlv_offset), 1, ENC_BIG_ENDIAN);
proto_item_append_text(tlv_item2, " dB");
break;
}
#if 0
case UCD_BURST_POWER_BOOST:
{
sub_tree = add_tlv_subtree(&tlv_info, ett_mac_mgmt_msg_ucd_decoder, tlv_tree, hf_ucd_burst_power_boost, tvb, (offset+tlv_offset), 1, FALSE);
tlv_item2 = proto_tree_add_item(sub_tree, hf_ucd_burst_power_boost, tvb, (offset+tlv_offset), length, ENC_BIG_ENDIAN);
proto_item_append_text(tlv_item2, " dB");
break;
}
case UCD_BURST_TCS_ENABLE:
{
sub_tree = add_tlv_subtree(&tlv_info, ett_mac_mgmt_msg_ucd_decoder, tlv_tree, hf_ucd_burst_tcs_enable, tvb, (offset+tlv_offset), 1, FALSE);
proto_tree_add_item(sub_tree, hf_ucd_burst_tcs_enable, tvb, (offset+tlv_offset), 1, ENC_BIG_ENDIAN);
break;
}
#endif
default:
break;
}
tlv_offset += length;
}
break;
}
case UCD_RESERVATION_TIMEOUT:
{
tlv_tree = add_tlv_subtree(&tlv_info, ett_mac_mgmt_msg_ucd_decoder, ucd_tree, hf_ucd_res_timeout, tvb, offset, tlv_len, FALSE);
proto_tree_add_item(tlv_tree, hf_ucd_res_timeout, tvb, offset, tlv_len, ENC_BIG_ENDIAN);
break;
}
case UCD_BW_REQ_SIZE:
{
tlv_tree = add_tlv_subtree(&tlv_info, ett_mac_mgmt_msg_ucd_decoder, ucd_tree, hf_ucd_bw_req_size, tvb, offset, tlv_len, FALSE);
tlv_item1 = proto_tree_add_item(tlv_tree, hf_ucd_bw_req_size, tvb, offset, tlv_len, ENC_BIG_ENDIAN);
proto_item_append_text(tlv_item1, " PS");
break;
}
case UCD_RANGING_REQ_SIZE:
{
tlv_tree = add_tlv_subtree(&tlv_info, ett_mac_mgmt_msg_ucd_decoder, ucd_tree, hf_ucd_ranging_req_size, tvb, offset, tlv_len, FALSE);
tlv_item1 = proto_tree_add_item(tlv_tree, hf_ucd_ranging_req_size, tvb, offset, tlv_len, ENC_BIG_ENDIAN);
proto_item_append_text(tlv_item1, " PS");
break;
}
case UCD_FREQUENCY:
{
tlv_tree = add_tlv_subtree(&tlv_info, ett_mac_mgmt_msg_ucd_decoder, ucd_tree, hf_ucd_freq, tvb, offset, tlv_len, FALSE);
tlv_item1 = proto_tree_add_item(tlv_tree, hf_ucd_freq, tvb, offset, tlv_len, ENC_BIG_ENDIAN);
proto_item_append_text(tlv_item1, " kHz");
break;
}
case UCD_TLV_T_7_HO_RANGING_START:
{
tlv_tree = add_protocol_subtree(&tlv_info, ett_mac_mgmt_msg_ucd_decoder, ucd_tree, proto_mac_mgmt_msg_ucd_decoder, tvb, offset, tlv_len, "HO ranging start (SCa, OFDM, OFDMA (mobile only)) (%u byte(s))", tlv_len);
utemp = tvb_get_guint8(tvb, offset);
proto_tree_add_text(tlv_tree, tvb, offset, tvb_len, "Initial Backoff Window Size for MS Performing Initial During Handover Process: 2^%u = %u", utemp, (1 << utemp));
break;
}
case UCD_TLV_T_8_RANGING_HO_END:
{
tlv_tree = add_protocol_subtree(&tlv_info, ett_mac_mgmt_msg_ucd_decoder, ucd_tree, proto_mac_mgmt_msg_ucd_decoder, tvb, offset, tlv_len, "HO ranging end (SCa, OFDM, OFDMA (mobile only)) (%u byte(s))", tlv_len);
utemp = tvb_get_guint8(tvb, offset);
proto_tree_add_text(tlv_tree, tvb, offset, tvb_len, "Final Backoff Window Size for MS Performing Initial During Handover Process: 2^%u = %u", utemp, (1 << utemp));
break;
}
case UCD_TLV_T_158_OPTIONAL_PERMUTATION_UL_ALLOCATED_SUBCHANNELS_BITMAP:
{
tlv_tree = add_tlv_subtree(&tlv_info, ett_mac_mgmt_msg_ucd_decoder, ucd_tree, hf_ucd_tlv_t_158_optional_permutation_ul_allocated_subchannels_bitmap, tvb, offset, tlv_len, FALSE);
proto_tree_add_item(tlv_tree, hf_ucd_tlv_t_158_optional_permutation_ul_allocated_subchannels_bitmap, tvb, offset, tlv_len, ENC_NA);
break;
}
case UCD_TLV_T_159_BAND_AMC_ALLOCATION_THRESHHOLD:
{
tlv_tree = add_tlv_subtree(&tlv_info, ett_mac_mgmt_msg_ucd_decoder, ucd_tree, hf_ucd_tlv_t_159_band_amc_allocation_threshold, tvb, offset, tlv_len, FALSE);
tlv_item1 = proto_tree_add_item(tlv_tree, hf_ucd_tlv_t_159_band_amc_allocation_threshold, tvb, offset, tlv_len, ENC_BIG_ENDIAN);
proto_item_append_text(tlv_item1, " dB");
break;
}
case UCD_TLV_T_160_BAND_AMC_RELEASE_THRESHOLD:
{
tlv_tree = add_tlv_subtree(&tlv_info, ett_mac_mgmt_msg_ucd_decoder, ucd_tree, hf_ucd_tlv_t_160_band_amc_release_threshold, tvb, offset, tlv_len, FALSE);
tlv_item1 = proto_tree_add_item(tlv_tree, hf_ucd_tlv_t_160_band_amc_release_threshold, tvb, offset, tlv_len, ENC_BIG_ENDIAN);
proto_item_append_text(tlv_item1, " dB");
break;
}
case UCD_TLV_T_161_BAND_AMC_ALLOCATION_TIMER:
{
tlv_tree = add_tlv_subtree(&tlv_info, ett_mac_mgmt_msg_ucd_decoder, ucd_tree, hf_ucd_tlv_t_161_band_amc_allocation_timer, tvb, offset, tlv_len, FALSE);
tlv_item1 = proto_tree_add_item(tlv_tree, hf_ucd_tlv_t_161_band_amc_allocation_timer, tvb, offset, tlv_len, ENC_BIG_ENDIAN);
proto_item_append_text(tlv_item1, " frames");
break;
}
case UCD_TLV_T_162_BAND_AMC_RELEASE_TIMER:
{
tlv_tree = add_tlv_subtree(&tlv_info, ett_mac_mgmt_msg_ucd_decoder, ucd_tree, hf_ucd_tlv_t_161_band_amc_allocation_timer, tvb, offset, tlv_len, FALSE);
tlv_item1 = proto_tree_add_item(tlv_tree, hf_ucd_tlv_t_162_band_amc_release_timer, tvb, offset, tlv_len, ENC_BIG_ENDIAN);
proto_item_append_text(tlv_item1, " frames");
break;
}
case UCD_TLV_T_163_BAND_STATUS_REPORT_MAX_PERIOD:
{
tlv_tree = add_tlv_subtree(&tlv_info, ett_mac_mgmt_msg_ucd_decoder, ucd_tree, hf_ucd_tlv_t_163_band_status_report_max_period, tvb, offset, tlv_len, FALSE);
tlv_item1 = proto_tree_add_item(tlv_tree, hf_ucd_tlv_t_163_band_status_report_max_period, tvb, offset, tlv_len, ENC_BIG_ENDIAN);
proto_item_append_text(tlv_item1, " frames");
break;
}
case UCD_TLV_T_164_BAND_AMC_RETRY_TIMER:
{
tlv_tree = add_tlv_subtree(&tlv_info, ett_mac_mgmt_msg_ucd_decoder, ucd_tree, hf_ucd_tlv_t_164_band_amc_retry_timer, tvb, offset, tlv_len, FALSE);
tlv_item1 = proto_tree_add_item(tlv_tree, hf_ucd_tlv_t_164_band_amc_retry_timer, tvb, offset, tlv_len, ENC_BIG_ENDIAN);
proto_item_append_text(tlv_item1, " frames");
break;
}
case UCD_TLV_T_170_SAFETY_CHANNEL_RETRY_TIMER:
{
tlv_tree = add_tlv_subtree(&tlv_info, ett_mac_mgmt_msg_ucd_decoder, ucd_tree, hf_ucd_tlv_t_170_safety_channel_retry_timer, tvb, offset, tlv_len, FALSE);
tlv_item1 = proto_tree_add_item(tlv_tree, hf_ucd_tlv_t_170_safety_channel_retry_timer, tvb, offset, tlv_len, ENC_BIG_ENDIAN);
proto_item_append_text(tlv_item1, " frames");
break;
}
case UCD_TLV_T_171_HARQ_ACK_DELAY_FOR_DL_BURST:
{
tlv_tree = add_tlv_subtree(&tlv_info, ett_mac_mgmt_msg_ucd_decoder, ucd_tree, hf_ucd_tlv_t_171_harq_ack_delay_dl_burst, tvb, offset, tlv_len, FALSE);
tlv_item1 = proto_tree_add_item(tlv_tree, hf_ucd_tlv_t_171_harq_ack_delay_dl_burst, tvb, offset, tlv_len, ENC_BIG_ENDIAN);
proto_item_append_text(tlv_item1, " frames offset");
break;
}
case UCD_TLV_T_172_CQICH_BAND_AMC_TRANSITION_DELAY:
{
tlv_tree = add_tlv_subtree(&tlv_info, ett_mac_mgmt_msg_ucd_decoder, ucd_tree, hf_ucd_tlv_t_172_cqich_band_amc_transition_delay, tvb, offset, tlv_len, FALSE);
tlv_item1 = proto_tree_add_item(tlv_tree, hf_ucd_tlv_t_172_cqich_band_amc_transition_delay, tvb, offset, tlv_len, ENC_BIG_ENDIAN);
proto_item_append_text(tlv_item1, " frames");
break;
}
case UCD_TLV_T_174_MAXIMUM_RETRANSMISSION:
{
tlv_tree = add_tlv_subtree(&tlv_info, ett_mac_mgmt_msg_ucd_decoder, ucd_tree, hf_ucd_tlv_t_174_maximum_retransmission, tvb, offset, tlv_len, FALSE);
proto_tree_add_item(tlv_tree, hf_ucd_tlv_t_174_maximum_retransmission, tvb, offset, tlv_len, ENC_BIG_ENDIAN);
break;
}
case UCD_TLV_T_176_SIZE_OF_CQICH_ID_FIELD:
{
utemp = tvb_get_guint8(tvb, offset);
cqich_id_size = 0;
if (utemp && utemp < 8) {
cqich_id_size = utemp + 2;
}
tlv_tree = add_tlv_subtree(&tlv_info, ett_mac_mgmt_msg_ucd_decoder, ucd_tree, hf_ucd_tlv_t_176_size_of_cqich_id_field, tvb, offset, tlv_len, FALSE);
proto_tree_add_item(tlv_tree, hf_ucd_tlv_t_176_size_of_cqich_id_field, tvb, offset, tlv_len, ENC_BIG_ENDIAN);
break;
}
case UCD_TLV_T_177_NORMALIZED_CN_OVERRIDE_2:
{
tlv_tree = add_tlv_subtree(&tlv_info, ett_mac_mgmt_msg_ucd_decoder, ucd_tree, hf_ucd_tlv_t_177_normalized_cn_override2, tvb, offset, tlv_len, FALSE);
proto_tree_add_item(tlv_tree, hf_ucd_tlv_t_177_normalized_cn_override2_first_line, tvb, offset + 2, 1, ENC_BIG_ENDIAN);
proto_tree_add_item(tlv_tree, hf_ucd_tlv_t_177_normalized_cn_override2_list, tvb, offset + 3, 7, ENC_ASCII|ENC_NA);
break;
}
case UCD_TLV_T_186_UPPER_BOUND__AAS_PREAMBLE:
{
tlv_tree = add_tlv_subtree(&tlv_info, ett_mac_mgmt_msg_ucd_decoder, ucd_tree, hf_ucd_tlv_t_186_upper_bound_aas_preamble, tvb, offset, tlv_len, FALSE);
proto_tree_add_item(tlv_tree, hf_ucd_tlv_t_186_upper_bound_aas_preamble, tvb, offset, tlv_len, ENC_BIG_ENDIAN);
break;
}
case UCD_TLV_T_187_LOWER_BOUND_AAS_PREAMBLE:
{
tlv_tree = add_tlv_subtree(&tlv_info, ett_mac_mgmt_msg_ucd_decoder, ucd_tree, hf_ucd_tlv_t_187_lower_bound_aas_preamble, tvb, offset, tlv_len, FALSE);
proto_tree_add_item(tlv_tree, hf_ucd_tlv_t_187_lower_bound_aas_preamble, tvb, offset, tlv_len, ENC_BIG_ENDIAN);
break;
}
case UCD_TLV_T_188_ALLOW_AAS_BEAM_SELECT_MESSAGE:
{
tlv_tree = add_tlv_subtree(&tlv_info, ett_mac_mgmt_msg_ucd_decoder, ucd_tree, hf_ucd_tlv_t_188_allow_aas_beam_select_message, tvb, offset, tlv_len, FALSE);
proto_tree_add_item(tlv_tree, hf_ucd_tlv_t_188_allow_aas_beam_select_message, tvb, offset, tlv_len, ENC_BIG_ENDIAN);
break;
}
case UCD_TLV_T_189_USE_CQICH_INDICATION_FLAG:
{
tlv_tree = add_tlv_subtree(&tlv_info, ett_mac_mgmt_msg_ucd_decoder, ucd_tree, hf_ucd_tlv_t_189_use_cqich_indication_flag, tvb, offset, tlv_len, FALSE);
proto_tree_add_item(tlv_tree, hf_ucd_tlv_t_189_use_cqich_indication_flag, tvb, offset, tlv_len, ENC_BIG_ENDIAN);
break;
}
case UCD_TLV_T_190_MS_SPECIFIC_UP_POWER_OFFSET_ADJUSTMENT_STEP:
{
tlv_tree = add_tlv_subtree(&tlv_info, ett_mac_mgmt_msg_ucd_decoder, ucd_tree, hf_ucd_tlv_t_190_ms_specific_up_power_addjustment_step, tvb, offset, tlv_len, FALSE);
proto_tree_add_item(tlv_tree, hf_ucd_tlv_t_190_ms_specific_up_power_addjustment_step, tvb, offset, tlv_len, ENC_BIG_ENDIAN);
break;
}
case UCD_TLV_T_191_MS_SPECIFIC_DOWN_POWER_OFSET_ADJUSTMENT_STEP:
{
tlv_tree = add_tlv_subtree(&tlv_info, ett_mac_mgmt_msg_ucd_decoder, ucd_tree, hf_ucd_tlv_t_191_ms_specific_down_power_addjustment_step, tvb, offset, tlv_len, FALSE);
proto_tree_add_item(tlv_tree, hf_ucd_tlv_t_191_ms_specific_down_power_addjustment_step, tvb, offset, tlv_len, ENC_BIG_ENDIAN);
break;
}
case UCD_TLV_T_192_MIN_LEVEL_POWER_OFFSET_ADJUSTMENT:
{
tlv_tree = add_tlv_subtree(&tlv_info, ett_mac_mgmt_msg_ucd_decoder, ucd_tree, hf_ucd_tlv_t_192_min_level_power_offset_adjustment, tvb, offset, tlv_len, FALSE);
proto_tree_add_item(tlv_tree, hf_ucd_tlv_t_192_min_level_power_offset_adjustment, tvb, offset, tlv_len, ENC_BIG_ENDIAN);
break;
}
case UCD_TLV_T_193_MAX_LEVEL_POWER_OFFSETR_ADJUSTMENT:
{
tlv_tree = add_tlv_subtree(&tlv_info, ett_mac_mgmt_msg_ucd_decoder, ucd_tree, hf_ucd_tlv_t_193_max_level_power_offset_adjustment, tvb, offset, tlv_len, FALSE);
proto_tree_add_item(tlv_tree, hf_ucd_tlv_t_193_max_level_power_offset_adjustment, tvb, offset, tlv_len, ENC_BIG_ENDIAN);
break;
}
case UCD_TLV_T_194_HANDOVER_RANGING_CODES:
{
tlv_tree = add_tlv_subtree(&tlv_info, ett_mac_mgmt_msg_ucd_decoder, ucd_tree, hf_ucd_tlv_t_194_handover_ranging_codes, tvb, offset, tlv_len, FALSE);
proto_tree_add_item(tlv_tree, hf_ucd_tlv_t_194_handover_ranging_codes, tvb, offset, tlv_len, ENC_BIG_ENDIAN);
break;
}
case UCD_TLV_T_195_INITIAL_RANGING_INTERVAL:
{
tlv_tree = add_tlv_subtree(&tlv_info, ett_mac_mgmt_msg_ucd_decoder, ucd_tree, hf_ucd_tlv_t_195_initial_ranging_interval, tvb, offset, tlv_len, FALSE);
proto_tree_add_item(tlv_tree, hf_ucd_tlv_t_195_initial_ranging_interval, tvb, offset, tlv_len, ENC_BIG_ENDIAN);
break;
}
case UCD_TLV_T_196_TX_POWER_REPORT:
{
tlv_tree = add_protocol_subtree(&tlv_info, ett_mac_mgmt_msg_ucd_decoder, ucd_tree, proto_mac_mgmt_msg_ucd_decoder, tvb, offset, tlv_len, "Tx Power Report (%u bytes)", tlv_len);
proto_tree_add_item(tlv_tree, hf_ucd_tlv_t_196_tx_power_report_threshold, tvb, offset, 1, ENC_BIG_ENDIAN);
proto_tree_add_item(tlv_tree, hf_ucd_tlv_t_196_tx_power_report_interval, tvb , offset, 1, ENC_BIG_ENDIAN);
proto_tree_add_item(tlv_tree, hf_ucd_tlv_t_196_tx_power_report_a_p_avg, tvb, (offset + 1), 1, ENC_BIG_ENDIAN);
proto_tree_add_item(tlv_tree, hf_ucd_tlv_t_196_tx_power_report_threshold_icqch, tvb, (offset + 1), 1, ENC_BIG_ENDIAN);
proto_tree_add_item(tlv_tree, hf_ucd_tlv_t_196_tx_power_report_interval_icqch, tvb, (offset + 2), 1, ENC_BIG_ENDIAN);
proto_tree_add_item(tlv_tree, hf_ucd_tlv_t_196_tx_power_report_a_p_avg_icqch, tvb, (offset + 2), 1, ENC_BIG_ENDIAN);
break;
}
case UCD_TLV_T_197_NORMALIZED_CN_FOR_CHANNEL_SOUNDING:
{
tlv_tree = add_tlv_subtree(&tlv_info, ett_mac_mgmt_msg_ucd_decoder, ucd_tree, hf_ucd_tlv_t_195_initial_ranging_interval, tvb, offset, tlv_len, FALSE);
proto_tree_add_item(tlv_tree, hf_ucd_tlv_t_197_normalized_cn_channel_sounding, tvb, offset, tlv_len, ENC_BIG_ENDIAN);
break;
}
case UCD_TLV_T_198_INTIAL_RANGING_BACKOFF_START:
{
tlv_tree = add_protocol_subtree(&tlv_info, ett_mac_mgmt_msg_ucd_decoder, ucd_tree, proto_mac_mgmt_msg_ucd_decoder, tvb, offset, tlv_len, "Initial ranging backoff start (%u byte(s))", tlv_len);
utemp = tvb_get_guint8(tvb, offset);
proto_tree_add_text(tlv_tree, tvb, offset, tvb_len, "Initial Ranging Backoff Start: 2^%u = %u", utemp, (1 << utemp));
break;
}
case UCD_TLV_T_199_INITIAL_RANGING_BACKOFF_END:
{
tlv_tree = add_protocol_subtree(&tlv_info, ett_mac_mgmt_msg_ucd_decoder, ucd_tree, proto_mac_mgmt_msg_ucd_decoder, tvb, offset, tlv_len, "Initial ranging backoff end (%u byte(s))", tlv_len);
utemp = tvb_get_guint8(tvb, offset);
proto_tree_add_text(tlv_tree, tvb, offset, tvb_len, "Initial Ranging Backoff End: 2^%u = %u", utemp, (1 << utemp));
break;
}
case UCD_TLV_T_200_BANDWIDTH_REQUESET_BACKOFF_START:
{
tlv_tree = add_protocol_subtree(&tlv_info, ett_mac_mgmt_msg_ucd_decoder, ucd_tree, proto_mac_mgmt_msg_ucd_decoder, tvb, offset, tlv_len, "Bandwidth request backoff start (%u byte(s))", tlv_len);
utemp = tvb_get_guint8(tvb, offset);
proto_tree_add_text(tlv_tree, tvb, offset, tvb_len, "Bandwidth Request Backoff Start: 2^%u = %u", utemp, (1 << utemp));
break;
}
case UCD_TLV_T_201_BANDWIDTH_REQUEST_BACKOFF_END:
{
tlv_tree = add_protocol_subtree(&tlv_info, ett_mac_mgmt_msg_ucd_decoder, ucd_tree, proto_mac_mgmt_msg_ucd_decoder, tvb, offset, tlv_len, "Bandwidth request backoff end (%u byte(s))", tlv_len);
utemp = tvb_get_guint8(tvb, offset);
proto_tree_add_text(tlv_tree, tvb, offset, tvb_len, "Bandwidth Request Backoff End: 2^%u = %u", utemp, (1 << utemp));
break;
}
case UCD_TLV_T_202_UPLINK_BURST_PROFILE_FOR_MULTIPLE_FEC_TYPES:
{
tlv_tree = add_tlv_subtree(&tlv_info, ett_mac_mgmt_msg_ucd_decoder, ucd_tree, hf_ucd_tlv_t_202_uplink_burst_profile_for_multiple_fec_types, tvb, offset, tlv_len, FALSE);
proto_tree_add_item(tlv_tree, hf_ucd_tlv_t_202_uplink_burst_profile_for_multiple_fec_types, tvb, offset, tlv_len, ENC_BIG_ENDIAN);
break;
}
case UCD_INITIAL_RANGING_CODES:
{
tlv_tree = add_tlv_subtree(&tlv_info, ett_mac_mgmt_msg_ucd_decoder, ucd_tree, hf_ucd_tlv_t_150_initial_ranging_codes, tvb, offset, tlv_len, FALSE);
proto_tree_add_item(tlv_tree,hf_ucd_tlv_t_150_initial_ranging_codes, tvb, offset, tlv_len, ENC_BIG_ENDIAN);
break;
}
case UCD_PERIODIC_RANGING_CODES:
{
tlv_tree = add_tlv_subtree(&tlv_info, ett_mac_mgmt_msg_ucd_decoder, ucd_tree, hf_ucd_tlv_t_151_periodic_ranging_codes, tvb, offset, tlv_len, FALSE);
proto_tree_add_item(tlv_tree,hf_ucd_tlv_t_151_periodic_ranging_codes, tvb, offset, tlv_len, ENC_BIG_ENDIAN);
break;
}
case UCD_BANDWIDTH_REQUEST_CODES:
{
tlv_tree = add_tlv_subtree(&tlv_info, ett_mac_mgmt_msg_ucd_decoder, ucd_tree, hf_ucd_tlv_t_152_bandwidth_request_codes, tvb, offset, tlv_len, FALSE);
proto_tree_add_item(tlv_tree,hf_ucd_tlv_t_152_bandwidth_request_codes, tvb, offset, tlv_len, ENC_BIG_ENDIAN);
break;
}
case UCD_PERIODIC_RANGING_BACKOFF_START:
{
tlv_tree = add_protocol_subtree(&tlv_info, ett_mac_mgmt_msg_ucd_decoder, ucd_tree, proto_mac_mgmt_msg_ucd_decoder, tvb, offset, tlv_len, "Periodic ranging backoff start (%u byte(s))", tlv_len);
utemp = tvb_get_guint8(tvb, offset);
proto_tree_add_text(tlv_tree, tvb, offset, tlv_len, "Periodic Ranging Backoff Start: 2^%u = %u", utemp, (1 << utemp));
break;
}
case UCD_PERIODIC_RANGING_BACKOFF_END:
{
tlv_tree = add_protocol_subtree(&tlv_info, ett_mac_mgmt_msg_ucd_decoder, ucd_tree, proto_mac_mgmt_msg_ucd_decoder, tvb, offset, tlv_len, "Periodic ranging backoff end (%u bytes(s))", tlv_len);
utemp = tvb_get_guint8(tvb, offset);
proto_tree_add_text(tlv_tree, tvb, offset, tlv_len, "Periodic Ranging Backoff End: 2^%u = %u", utemp, (1 << utemp));
break;
}
case UCD_START_OF_RANGING_CODES_GROUP:
{
tlv_tree = add_tlv_subtree(&tlv_info, ett_mac_mgmt_msg_ucd_decoder, ucd_tree, hf_ucd_tlv_t_155_start_of_ranging_codes_group, tvb, offset, tlv_len, FALSE);
proto_tree_add_item(tlv_tree,hf_ucd_tlv_t_155_start_of_ranging_codes_group, tvb, offset, tlv_len, ENC_BIG_ENDIAN);
break;
}
case UCD_PERMUTATION_BASE:
{
tlv_tree = add_tlv_subtree(&tlv_info, ett_mac_mgmt_msg_ucd_decoder, ucd_tree, hf_ucd_tlv_t_156_permutation_base, tvb, offset, tlv_len, FALSE);
proto_tree_add_item(tlv_tree,hf_ucd_tlv_t_156_permutation_base, tvb, offset, tlv_len, ENC_BIG_ENDIAN);
break;
}
case UCD_UL_ALLOCATED_SUBCHANNELS_BITMAP:
{
tlv_tree = add_tlv_subtree(&tlv_info, ett_mac_mgmt_msg_ucd_decoder, ucd_tree, hf_ucd_ul_allocated_subchannles_bitmap, tvb, offset, tlv_len, FALSE);
proto_tree_add_item(tlv_tree, hf_ucd_ul_allocated_subchannles_bitmap, tvb, offset, tlv_len, ENC_NA);
break;
}
case UCD_TLV_T_203_UL_PUSC_SUBCHANNEL_ROTATION:
case UCD_TLV_T_205_RELATIVE_POWER_OFFSET_UL_HARQ_BURST:
case UCD_TLV_T_206_RELATIVE_POWER_OFFSET_UL_BURST_CONTAINING_MAC_MGMT_MSG:
case UCD_TLV_T_207_UL_INITIAL_TRANSMIT_TIMING:
case UCD_TLV_T_210_FAST_FEEDBACK_REGION:
case UCD_TLV_T_211_HARQ_ACK_REGION:
case UCD_TLV_T_212_RANGING_REGION:
case UCD_TLV_T_213_SOUNDING_REGION:
{
if (!include_cor2_changes)
{
proto_tree_add_protocol_format(ucd_tree, proto_mac_mgmt_msg_ucd_decoder, tvb, offset, tlv_len, "Unknown TLV Type");
}
break;
}
default:
{
proto_tree_add_protocol_format(ucd_tree, proto_mac_mgmt_msg_ucd_decoder, tvb, offset, tlv_len, "Unknown TLV Type");
}
}
offset += tlv_len;
}
}
}
void proto_register_mac_mgmt_msg_ucd(void)
{
static hf_register_info hf[] =
{
{
&hf_ucd_message_type,
{
"MAC Management Message Type", "wmx.macmgtmsgtype.ucd",
FT_UINT8, BASE_DEC, NULL, 0, NULL, HFILL
}
},
{
&hf_ucd_tlv_t_188_allow_aas_beam_select_message,
{
"Allow AAS Beam Select Message", "wmx.ucd.allow_aas_beam_select_message",
FT_INT8, BASE_DEC, VALS(vals_yes_no_str), 0, NULL, HFILL
}
},
{
&hf_ucd_tlv_t_159_band_amc_allocation_threshold,
{
"Band AMC Allocation Threshold", "wmx.ucd.band_amc.allocation_threshold",
FT_UINT8, BASE_HEX, NULL, 0, NULL, HFILL
}
},
{
&hf_ucd_tlv_t_161_band_amc_allocation_timer,
{
"Band AMC Allocation Timer", "wmx.ucd.band_amc.allocation_timer",
FT_UINT8, BASE_HEX, NULL, 0, NULL, HFILL
}
},
{
&hf_ucd_tlv_t_160_band_amc_release_threshold,
{
"Band AMC Release Threshold", "wmx.ucd.band_amc.release_threshold",
FT_UINT8, BASE_HEX, NULL, 0, NULL, HFILL
}
},
{
&hf_ucd_tlv_t_162_band_amc_release_timer,
{
"Band AMC Release Timer", "wmx.ucd.band_amc.release_timer",
FT_UINT8, BASE_HEX, NULL, 0, NULL, HFILL
}
},
{
&hf_ucd_tlv_t_164_band_amc_retry_timer,
{
"Band AMC Retry Timer", "wmx.ucd.band_amc.retry_timer",
FT_UINT8, BASE_HEX, NULL, 0, NULL, HFILL
}
},
{
&hf_ucd_tlv_t_163_band_status_report_max_period,
{
"Band Status Report MAC Period", "wmx.ucd.band_status.report_max_period",
FT_UINT8, BASE_DEC, NULL, 0, NULL, HFILL
}
},
{
&hf_ucd_tlv_t_152_bandwidth_request_codes,
{
"Bandwidth Request Codes", "wmx.ucd.bandwidth_request",
FT_UINT8, BASE_HEX, NULL, 0, NULL, HFILL
}
},
{
&hf_ucd_burst_fec,
{
"FEC Code Type", "wmx.ucd.burst.fec",
FT_UINT8, BASE_HEX, VALS(vals_dcd_burst_fec), 0, NULL, HFILL
}
},
{
&hf_ucd_burst_ranging_data_ratio,
{
"Ranging Data Ratio", "wmx.ucd.burst.ranging_data_ratio",
FT_UINT8, BASE_DEC, NULL, 0, NULL, HFILL
}
},
{
&hf_ucd_ul_burst_reserved,
{
"Reserved", "wmx.ucd.burst.reserved",
FT_UINT8, BASE_HEX, NULL, 0xF0, NULL, HFILL
}
},
{
&hf_ucd_ul_burst_uiuc,
{
"UIUC", "wmx.ucd.burst.uiuc",
FT_UINT8, BASE_DEC, NULL, 0x0F, NULL, HFILL
}
},
#if 0
{
&hf_ucd_burst_power_boost,
{"Focused Contention Power Boost", "wmx.ucd.burst.power_boost", FT_UINT8, BASE_HEX, NULL, 0, "", HFILL}
},
{
&hf_ucd_burst_tcs_enable,
{"TCS", "wmx.ucd.burst.tcs", FT_UINT8, BASE_DEC, VALS(vals_dcd_burst_tcs), 0, "", HFILL}
},
#endif
{
&hf_ucd_bw_req_size,
{
"Bandwidth Request Opportunity Size", "wmx.ucd.bw_req_size",
FT_UINT16, BASE_DEC, NULL, 0, NULL, HFILL
}
},
{
&hf_ucd_tlv_t_172_cqich_band_amc_transition_delay,
{
"CQICH Band AMC-Transition Delay", "wmx.ucd.cqich_band_amc_transition_delay",
FT_UINT8, BASE_DEC, NULL, 0, NULL, HFILL
}
},
{
&hf_ucd_freq,
{
"Frequency", "wmx.ucd.frequency",
FT_UINT32, BASE_DEC, NULL, 0, NULL, HFILL
}
},
{
&hf_ucd_tlv_t_194_handover_ranging_codes,
{
"Handover Ranging Codes", "wmx.ucd.handover_ranging_codes",
FT_INT8, BASE_DEC, NULL, 0, NULL, HFILL
}
},
{
&hf_ucd_tlv_t_171_harq_ack_delay_dl_burst,
{
"HARQ ACK Delay for DL Burst", "wmx.ucd.harq_ack_delay_dl_burst",
FT_UINT8, BASE_DEC, NULL, 0, NULL, HFILL
}
},
{
&hf_ucd_tlv_t_150_initial_ranging_codes,
{
"Initial Ranging Codes", "wmx.ucd.initial_ranging_codes",
FT_UINT8, BASE_HEX, NULL, 0, NULL, HFILL
}
},
{
&hf_ucd_tlv_t_195_initial_ranging_interval,
{
"Number of Frames Between Initial Ranging Interval Allocation", "wmx.ucd.initial_ranging_interval",
FT_INT8, BASE_DEC, NULL, 0, NULL, HFILL
}
},
{
&hf_ucd_invalid_tlv,
{
"Invalid TLV", "wmx.ucd.invalid_tlv",
FT_BYTES, BASE_NONE, NULL, 0, NULL, HFILL
}
},
{
&hf_ucd_tlv_t_187_lower_bound_aas_preamble,
{
"Lower Bound AAS Preamble (in units of 0.25 dB)", "wmx.ucd.lower_bound_aas_preamble",
FT_INT8, BASE_DEC, NULL, 0, NULL, HFILL
}
},
{
&hf_ucd_tlv_t_192_min_level_power_offset_adjustment,
{
"Minimum Level of Power Offset Adjustment (in units of 0.1 dB)", "wmx.ucd.min_level_power_offset_adjustment",
FT_INT8, BASE_DEC, NULL, 0, NULL, HFILL
}
},
{
&hf_ucd_tlv_t_193_max_level_power_offset_adjustment,
{
"Maximum Level of Power Offset Adjustment (in units of 0.1 dB)", "wmx.ucd.max_level_power_offset_adjustment",
FT_INT8, BASE_DEC, NULL, 0, NULL, HFILL
}
},
{
&hf_ucd_tlv_t_174_maximum_retransmission,
{
"Maximum Number of Retransmission in UL-HARQ", "wmx.ucd.max_number_of_retransmission_in_ul_harq",
FT_UINT8, BASE_DEC, NULL, 0, NULL, HFILL
}
},
{
&hf_ucd_tlv_t_191_ms_specific_down_power_addjustment_step,
{
"MS-specific Down Power Offset Adjustment Step (in units of 0.01 dB)", "wmx.ucd.ms_specific_down_power_offset_adjustment_step",
FT_UINT8, BASE_HEX, NULL, 0, NULL, HFILL
}
},
{
&hf_ucd_tlv_t_190_ms_specific_up_power_addjustment_step,
{
"MS-specific Up Power Offset Adjustment Step (in units of 0.01 dB)", "wmx.ucd.ms_specific_up_power_offset_adjustment_step",
FT_UINT8, BASE_HEX, NULL, 0, NULL, HFILL
}
},
{
&hf_ucd_tlv_t_197_normalized_cn_channel_sounding,
{
"Normalized C/N for Channel Sounding", "wmx.ucd.normalized_cn.channel_sounding",
FT_UINT8, BASE_HEX, NULL, 0, NULL, HFILL
}
},
{
&hf_ucd_tlv_t_177_normalized_cn_override2,
{
"Normalized C/N Override 2", "wmx.ucd.normalized_cn.override_2",
FT_STRING, BASE_NONE, NULL, 0, NULL, HFILL
}
},
{
&hf_ucd_tlv_t_177_normalized_cn_override2_first_line,
{
"Normalized C/N Value", "wmx.ucd.normalized_cn.override_first_line",
FT_UINT8, BASE_HEX, NULL, 0, NULL, HFILL
}
},
{
&hf_ucd_tlv_t_177_normalized_cn_override2_list,
{
"Normalized C/N Value List", "wmx.ucd.normalized_cn.override_list",
FT_STRING, BASE_NONE, NULL, 0, NULL, HFILL
}
},
{
&hf_ucd_tlv_t_158_optional_permutation_ul_allocated_subchannels_bitmap,
{
"Optional permutation UL allocated subchannels bitmap", "wmx.ucd.optional_permutation_ul_allocated_subchannels_bitmap",
FT_BYTES, BASE_NONE, NULL, 0, NULL, HFILL
}
},
{
&hf_ucd_tlv_t_151_periodic_ranging_codes,
{
"Periodic Ranging Codes", "wmx.ucd.periodic_ranging_codes",
FT_UINT8, BASE_HEX, NULL, 0, NULL, HFILL
}
},
{
&hf_ucd_tlv_t_156_permutation_base,
{
"Permutation Base", "wmx.ucd.permutation_base",
FT_UINT8, BASE_DEC, NULL, 0, NULL, HFILL
}
},
{
&hf_ucd_ranging_req_size,
{
"Ranging Request Opportunity Size", "wmx.ucd.ranging_req_size",
FT_UINT16, BASE_DEC, NULL, 0, NULL, HFILL
}
},
{
&hf_ucd_res_timeout,
{
"Contention-based Reservation Timeout", "wmx.ucd.res_timeout",
FT_UINT8, BASE_DEC, NULL, 0, NULL, HFILL
}
},
{
&hf_ucd_tlv_t_170_safety_channel_retry_timer,
{
"Safety Channel Release Timer", "wmx.ucd.safety_channel_release_timer",
FT_UINT8, BASE_HEX, NULL, 0, NULL, HFILL
}
},
{
&hf_ucd_tlv_t_176_size_of_cqich_id_field,
{
"Size of CQICH_ID Field", "wmx.ucd.size_of_cqich_id_field",
FT_UINT8, BASE_DEC, VALS(vals_ucd_cqich_size), 0, NULL, HFILL
}
},
{
&hf_ucd_tlv_t_155_start_of_ranging_codes_group,
{
"Start of Ranging Codes Group", "wmx.ucd.start_of_ranging_codes_group",
FT_UINT8, BASE_DEC, NULL, 0, NULL, HFILL
}
},
{
&hf_ucd_ul_allocated_subchannles_bitmap,
{
"UL Allocated Subchannels Bitmap", "wmx.ucd.subchan.bitmap",
FT_BYTES, BASE_NONE, NULL, 0, NULL, HFILL
}
},
{
&hf_ucd_subchan_codes,
{
"Periodic Ranging Codes", "wmx.ucd.subchan.codes",
FT_UINT8, BASE_HEX, NULL, 0, NULL, HFILL
}
},
{
&hf_ucd_subchan_params_num_chan,
{
"Number of Subchannels", "wmx.ucd.subchan.num_chan",
FT_UINT8, BASE_DEC, NULL, 0, NULL, HFILL
}
},
{
&hf_ucd_subchan_params_num_sym,
{
"Number of OFDMA Symbols", "wmx.ucd.subchan.num_sym",
FT_UINT8, BASE_DEC, NULL, 0, NULL, HFILL
}
},
{
&hf_ucd_tlv_t_196_tx_power_report,
{
"Tx Power Report", "wmx.ucd.tx_power_report",
FT_UINT24, BASE_HEX, NULL, 0, NULL, HFILL
}
},
{
&hf_ucd_tlv_t_196_tx_power_report_a_p_avg,
{
"A p_avg (in multiples of 1/16)", "wmx.ucd.tx_power_report.a_p_avg",
FT_UINT8, BASE_DEC, NULL, 0xF0, NULL, HFILL
}
},
{
&hf_ucd_tlv_t_196_tx_power_report_a_p_avg_icqch,
{
"A p_avg (in multiples of 1/16) when ICQCH is allocated", "wmx.ucd.tx_power_report.a_p_avg_icqch",
FT_UINT8, BASE_DEC, NULL, 0x0F, NULL, HFILL
}
},
{
&hf_ucd_tlv_t_196_tx_power_report_interval,
{
"Interval (expressed as power of 2)", "wmx.ucd.tx_power_report.interval",
FT_UINT8, BASE_DEC, NULL, 0x0F, NULL, HFILL
}
},
{
&hf_ucd_tlv_t_196_tx_power_report_interval_icqch,
{
"Interval When ICQCH is Allocated (expressed as power of 2)", "wmx.ucd.tx_power_report.interval_icqch",
FT_UINT8, BASE_DEC, NULL, 0xF0, NULL, HFILL
}
},
{
&hf_ucd_tlv_t_196_tx_power_report_threshold,
{
"Threshold", "wmx.ucd.tx_power_report.threshold",
FT_UINT8, BASE_DEC, NULL, 0xF0, NULL, HFILL
}
},
{
&hf_ucd_tlv_t_196_tx_power_report_threshold_icqch,
{
"Threshold When ICQCH is Allocated to SS (in dB)", "wmx.ucd.tx_power_report.threshold_icqch",
FT_UINT8, BASE_DEC, NULL, 0x0F, NULL, HFILL
}
},
{
&hf_ucd_unknown_type,
{
"Unknown UCD Type", "wmx.ucd.unknown_tlv_type",
FT_BYTES, BASE_NONE, NULL, 0, NULL, HFILL
}
},
{
&hf_ucd_tlv_t_202_uplink_burst_profile_for_multiple_fec_types,
{
"Uplink Burst Profile for Multiple FEC Types", "wmx.ucd.uplink_burst_profile.multiple_fec_types",
FT_UINT8, BASE_HEX, NULL, 0, NULL, HFILL
}
},
{
&hf_ucd_tlv_t_203_ul_pusc_subchannel_rotation,
{
"Uplink PUSC Subchannel Rotation", "wmx.ucd.uplink_burst_profile.ul_pusc_subchannel_rotation",
FT_UINT8, BASE_HEX, NULL, 0, NULL, HFILL
}
},
{
&hf_ucd_tlv_t_205_relative_power_offset_ul_harq_burst,
{
"Relative Power Offset UL HARQ Burst", "wmx.ucd.uplink_burst_profile.relative_power_offset_ul_harq_burst",
FT_UINT8, BASE_HEX, NULL, 0, NULL, HFILL
}
},
{
&hf_ucd_tlv_t_206_relative_power_offset_ul_burst_containing_mac_mgmt_msg,
{
"Relative Power Offset UL Burst Containing MAC Mgmt Msg", "wmx.ucd.uplink_burst_profile.relative_power_offset_ul_burst_mac_mgmt_msg",
FT_UINT8, BASE_HEX, NULL, 0, NULL, HFILL
}
},
{
&hf_ucd_tlv_t_207_ul_initial_transmit_timing,
{
"UL Initial Transmit Timing", "wmx.ucd.uplink_burst_profile.ul_initial_transmit_timing",
FT_UINT8, BASE_HEX, NULL, 0, NULL, HFILL
}
},
{
&hf_ucd_tlv_t_210_fast_feedback_region,
{
"Fast Feedback Region", "wmx.ucd.uplink_burst_profile.fast_feedback_region",
FT_BYTES, BASE_NONE, NULL, 0, NULL, HFILL
}
},
{
&hf_ucd_tlv_t_211_harq_ack_region,
{
"HARQ ACK Region", "wmx.ucd.uplink_burst_profile.harq_ack_region",
FT_BYTES, BASE_NONE, NULL, 0, NULL, HFILL
}
},
{
&hf_ucd_tlv_t_212_ranging_region,
{
"Ranging Region", "wmx.ucd.uplink_burst_profile.ranging_region",
FT_BYTES, BASE_NONE, NULL, 0, NULL, HFILL
}
},
{
&hf_ucd_tlv_t_213_sounding_region,
{
"Sounding Region", "wmx.ucd.uplink_burst_profile.sounding_region",
FT_BYTES, BASE_NONE, NULL, 0, NULL, HFILL
}
},
{
&hf_ucd_tlv_t_186_upper_bound_aas_preamble,
{
"Upper Bound AAS Preamble (in units of 0.25 dB)", "wmx.ucd.upper_bound_aas_preamble",
FT_INT8, BASE_DEC, NULL, 0, NULL, HFILL
}
},
{
&hf_ucd_tlv_t_189_use_cqich_indication_flag,
{
"Use CQICH Indication Flag", "wmx.ucd.use_cqich_indication_flag",
FT_UINT8, BASE_HEX, NULL, 0, NULL, HFILL
}
}
};
static gint *ett[] =
{
&ett_mac_mgmt_msg_ucd_decoder,
};
proto_mac_mgmt_msg_ucd_decoder = proto_mac_mgmt_msg_dcd_decoder;
proto_register_field_array(proto_mac_mgmt_msg_ucd_decoder, hf, array_length(hf));
proto_register_subtree_array(ett, array_length(ett));
}
