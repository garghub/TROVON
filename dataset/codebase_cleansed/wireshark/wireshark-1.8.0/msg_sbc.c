void dissect_mac_mgmt_msg_sbc_req_decoder(tvbuff_t *tvb, packet_info *pinfo, proto_tree *tree)
{
guint offset = 0;
guint tvb_len, payload_type, value;
gint tlv_type, tlv_len, tlv_value_offset;
proto_item *sbc_item = NULL;
proto_tree *sbc_tree = NULL;
proto_item *tlv_item = NULL;
proto_tree *tlv_tree = NULL;
proto_item *ti = NULL;
tlv_info_t tlv_info;
gfloat power_bpsk;
gfloat power_qpsk;
gfloat power_qam16;
gfloat power_qam64;
gfloat current_power;
payload_type = tvb_get_guint8(tvb, offset);
if (payload_type != MAC_MGMT_MSG_SBC_REQ)
{
return;
}
if (tree)
{
tvb_len = tvb_reported_length(tvb);
sbc_item = proto_tree_add_protocol_format(tree, proto_mac_mgmt_msg_sbc_decoder, tvb, offset, tvb_len, "SS Basic Capability Request (SBC-REQ) (%u bytes)", tvb_len);
sbc_tree = proto_item_add_subtree(sbc_item, ett_mac_mgmt_msg_sbc_decoder);
proto_tree_add_item(sbc_tree, hf_sbc_req_message_type, tvb, offset, 1, ENC_BIG_ENDIAN);
offset++;
while(offset < tvb_len)
{
init_tlv_info(&tlv_info, tvb, offset);
tlv_type = get_tlv_type(&tlv_info);
tlv_len = get_tlv_length(&tlv_info);
if (tlv_type == -1 || tlv_len > MAX_TLV_LEN || tlv_len < 1)
{
col_append_sep_str(pinfo->cinfo, COL_INFO, NULL, "SBC-REQ TLV error");
proto_tree_add_item(sbc_tree, hf_sbc_invalid_tlv, tvb, offset, (tvb_len - offset), ENC_NA);
break;
}
if (tlv_type == 0)
{
col_append_sep_str(pinfo->cinfo, COL_INFO, NULL, "Invalid SBC TLV type");
proto_tree_add_item(sbc_tree, hf_sbc_unknown_type, tvb, offset, 1, ENC_NA);
offset++;
continue;
}
tlv_value_offset = get_tlv_value_offset(&tlv_info);
#ifdef DEBUG
proto_tree_add_protocol_format(sbc_tree, proto_mac_mgmt_msg_sbc_decoder, tvb, offset, (tlv_len + tlv_value_offset), "SBC-REQ Type: %u (%u bytes, offset=%u, tlv_len=%u, tvb_len=%u)", tlv_type, (tlv_len + tlv_value_offset), offset, tlv_len, tvb_len);
#endif
offset += tlv_value_offset;
switch (tlv_type)
{
case SBC_BW_ALLOC_SUPPORT:
tlv_tree = add_tlv_subtree(&tlv_info, ett_sbc_req_tlv_subtree, sbc_tree, hf_sbc_bw_alloc_support, tvb, offset, tlv_len, FALSE);
proto_tree_add_item(tlv_tree, hf_sbc_bw_alloc_support_rsvd0, tvb, offset, 1, ENC_BIG_ENDIAN);
proto_tree_add_item(tlv_tree, hf_sbc_bw_alloc_support_duplex, tvb, offset, 1, ENC_BIG_ENDIAN);
proto_tree_add_item(tlv_tree, hf_sbc_bw_alloc_support_rsvd1, tvb, offset, 1, ENC_BIG_ENDIAN);
break;
case SBC_TRANSITION_GAPS:
tlv_tree = add_tlv_subtree(&tlv_info, ett_sbc_req_tlv_subtree, sbc_tree, hf_sbc_transition_gaps, tvb, offset, tlv_len, FALSE);
ti = proto_tree_add_item(tlv_tree, hf_sbc_ssttg, tvb, offset, 1, ENC_BIG_ENDIAN);
proto_item_append_text(ti, " us (ranges: TDD 0-50; H-FDD 0-100)");
ti = proto_tree_add_item(tlv_tree, hf_sbc_ssrtg, tvb, (offset + 1), 1, ENC_BIG_ENDIAN);
proto_item_append_text(ti, " us (ranges: TDD 0-50; H-FDD 0-100)");
break;
case SBC_MAC_PDU:
tlv_tree = add_tlv_subtree(&tlv_info, ett_sbc_req_tlv_subtree, sbc_tree, hf_sbc_mac_pdu, tvb, offset, tlv_len, FALSE);
proto_tree_add_item(tlv_tree, hf_sbc_mac_pdu_piggybacked, tvb, offset, 1, ENC_BIG_ENDIAN);
proto_tree_add_item(tlv_tree, hf_sbc_mac_pdu_fsn, tvb, offset, 1, ENC_BIG_ENDIAN);
proto_tree_add_item(tlv_tree, hf_sbc_mac_pdu_rsvd, tvb, offset, 1, ENC_BIG_ENDIAN);
break;
case SBC_REQ_MAX_TRANSMIT_POWER:
tlv_tree = add_tlv_subtree(&tlv_info, ett_sbc_req_tlv_subtree, sbc_tree, hf_sbc_max_transmit_power, tvb, offset, tlv_len, FALSE);
power_bpsk = (gfloat)(tvb_get_guint8(tvb, offset) - 128) / 2;
power_qpsk = (gfloat)(tvb_get_guint8(tvb, (offset + 1)) - 128) / 2;
power_qam16 = (gfloat)(tvb_get_guint8(tvb, (offset + 2)) - 128) / 2;
power_qam64 = (gfloat)(tvb_get_guint8(tvb, (offset + 3)) - 128) / 2;
proto_tree_add_text(tlv_tree, tvb, offset, 1, "BPSK: %.2f dBm", (gdouble)power_bpsk);
proto_tree_add_text(tlv_tree, tvb, (offset + 1), 1, "QPSK: %.2f dBm", (gdouble)power_qpsk);
proto_tree_add_text(tlv_tree, tvb, (offset + 2), 1, "QAM16: %.2f dBm", (gdouble)power_qam16);
proto_tree_add_text(tlv_tree, tvb, (offset + 3), 1, "QAM64: %.2f dBm", (gdouble)power_qam64);
break;
case SBC_REQ_CURR_TRANSMITTED_POWER:
tlv_tree = add_tlv_subtree(&tlv_info, ett_sbc_req_tlv_subtree, sbc_tree, hf_sbc_curr_transmit_power, tvb, offset, tlv_len, FALSE);
value = tvb_get_guint8(tvb, offset);
current_power = (gfloat)(value - 128) / 2;
proto_tree_add_text(tlv_tree, tvb, offset, 1, "Current Transmitted Power: %.2f dBm (Value: 0x%x)", (gdouble)current_power, value);
break;
case SBC_SS_FFT_SIZES:
tlv_tree = add_tlv_subtree(&tlv_info, ett_sbc_req_tlv_subtree, sbc_tree, hf_sbc_ss_fft_sizes, tvb, offset, tlv_len, FALSE);
if (include_cor2_changes)
{
proto_tree_add_item(tlv_tree, hf_sbc_ss_fft_rsvd1, tvb, offset, 1, ENC_BIG_ENDIAN);
} else {
proto_tree_add_item(tlv_tree, hf_sbc_ss_fft_256, tvb, offset, 1, ENC_BIG_ENDIAN);
}
proto_tree_add_item(tlv_tree, hf_sbc_ss_fft_2048, tvb, offset, 1, ENC_BIG_ENDIAN);
proto_tree_add_item(tlv_tree, hf_sbc_ss_fft_128, tvb, offset, 1, ENC_BIG_ENDIAN);
proto_tree_add_item(tlv_tree, hf_sbc_ss_fft_512, tvb, offset, 1, ENC_BIG_ENDIAN);
proto_tree_add_item(tlv_tree, hf_sbc_ss_fft_1024, tvb, offset, 1, ENC_BIG_ENDIAN);
proto_tree_add_item(tlv_tree, hf_sbc_ss_fft_rsvd2, tvb, offset, 1, ENC_BIG_ENDIAN);
break;
case SBC_SS_DEMODULATOR:
tlv_tree = add_tlv_subtree(&tlv_info, ett_sbc_req_tlv_subtree, sbc_tree, hf_sbc_ss_demodulator, tvb, offset, tlv_len, FALSE);
if (tlv_len == 1)
{
proto_tree_add_item(tlv_tree, hf_sbc_ss_demodulator_64qam, tvb, offset, 1, ENC_BIG_ENDIAN);
proto_tree_add_item(tlv_tree, hf_sbc_ss_demodulator_btc, tvb, offset, 1, ENC_BIG_ENDIAN);
proto_tree_add_item(tlv_tree, hf_sbc_ss_demodulator_ctc, tvb, offset, 1, ENC_BIG_ENDIAN);
proto_tree_add_item(tlv_tree, hf_sbc_ss_demodulator_stc, tvb, offset, 1, ENC_BIG_ENDIAN);
proto_tree_add_item(tlv_tree, hf_sbc_ss_demodulator_cc_with_optional_interleaver, tvb, offset, 1, ENC_BIG_ENDIAN);
proto_tree_add_item(tlv_tree, hf_sbc_ss_demodulator_harq_chase, tvb, offset, 1, ENC_BIG_ENDIAN);
proto_tree_add_item(tlv_tree, hf_sbc_ss_demodulator_harq_ctc_ir, tvb, offset, 1, ENC_BIG_ENDIAN);
proto_tree_add_item(tlv_tree, hf_sbc_ss_demodulator_reserved, tvb, offset, 1, ENC_BIG_ENDIAN);
}
else
{
proto_tree_add_item(tlv_tree, hf_sbc_ss_demodulator_64qam_2, tvb, offset, 2, ENC_BIG_ENDIAN);
proto_tree_add_item(tlv_tree, hf_sbc_ss_demodulator_btc_2, tvb, offset, 2, ENC_BIG_ENDIAN);
proto_tree_add_item(tlv_tree, hf_sbc_ss_demodulator_ctc_2, tvb, offset, 2, ENC_BIG_ENDIAN);
proto_tree_add_item(tlv_tree, hf_sbc_ss_demodulator_stc_2, tvb, offset, 2, ENC_BIG_ENDIAN);
proto_tree_add_item(tlv_tree, hf_sbc_ss_demodulator_cc_with_optional_interleaver_2, tvb, offset, 2, ENC_BIG_ENDIAN);
proto_tree_add_item(tlv_tree, hf_sbc_ss_demodulator_harq_chase_2, tvb, offset, 2, ENC_BIG_ENDIAN);
proto_tree_add_item(tlv_tree, hf_sbc_ss_demodulator_harq_ctc_ir_2, tvb, offset, 2, ENC_BIG_ENDIAN);
proto_tree_add_item(tlv_tree, hf_sbc_ss_demodulator_reserved_2, tvb, offset, 2, ENC_BIG_ENDIAN);
#if 0
if (tlv_len == 1)
{
proto_tree_add_item(tlv_tree, hf_sbc_ss_demodulator_reserved1, tvb, offset, 2, ENC_BIG_ENDIAN);
}
else
#endif
{
proto_tree_add_item(tlv_tree, hf_sbc_ss_demodulator_harq_cc_ir_2, tvb, offset , 2, ENC_BIG_ENDIAN);
proto_tree_add_item(tlv_tree, hf_sbc_ss_demodulator_ldpc_2, tvb, offset, 2, ENC_BIG_ENDIAN);
proto_tree_add_item(tlv_tree, hf_sbc_ss_demodulator_dedicated_pilots_2, tvb, offset, 2, ENC_BIG_ENDIAN);
proto_tree_add_item(tlv_tree, hf_sbc_ss_demodulator_reserved1_2, tvb, offset, 2, ENC_BIG_ENDIAN);
}
}
break;
case SBC_SS_MODULATOR:
tlv_tree = add_tlv_subtree(&tlv_info, ett_sbc_req_tlv_subtree, sbc_tree, hf_sbc_ss_modulator, tvb, offset, tlv_len, FALSE);
proto_tree_add_item(tlv_tree, hf_sbc_ss_modulator_64qam, tvb, offset, 1, ENC_BIG_ENDIAN);
proto_tree_add_item(tlv_tree, hf_sbc_ss_modulator_btc, tvb, offset, 1, ENC_BIG_ENDIAN);
proto_tree_add_item(tlv_tree, hf_sbc_ss_modulator_ctc, tvb, offset, 1, ENC_BIG_ENDIAN);
proto_tree_add_item(tlv_tree, hf_sbc_ss_modulator_stc, tvb, offset, 1, ENC_BIG_ENDIAN);
proto_tree_add_item(tlv_tree, hf_sbc_ss_modulator_harq_chase, tvb, offset, 1, ENC_BIG_ENDIAN);
proto_tree_add_item(tlv_tree, hf_sbc_ss_modulator_ctc_ir, tvb, offset, 1, ENC_BIG_ENDIAN);
proto_tree_add_item(tlv_tree, hf_sbc_ss_modulator_cc_ir, tvb, offset, 1, ENC_BIG_ENDIAN);
proto_tree_add_item(tlv_tree, hf_sbc_ss_modulator_ldpc, tvb, offset, 1, ENC_BIG_ENDIAN);
break;
case SBC_SS_NUM_UL_ARQ_ACK_CHANNEL:
tlv_tree = add_tlv_subtree(&tlv_info, ett_sbc_req_tlv_subtree, sbc_tree, hf_sbc_number_ul_arq_ack_channel, tvb, offset, tlv_len, FALSE);
proto_tree_add_item(tlv_tree, hf_sbc_number_ul_arq_ack_channel, tvb, offset, tlv_len, ENC_BIG_ENDIAN);
break;
case SBC_SS_NUM_DL_ARQ_ACK_CHANNEL:
tlv_tree = add_tlv_subtree(&tlv_info, ett_sbc_req_tlv_subtree, sbc_tree, hf_sbc_number_dl_arq_ack_channel, tvb, offset, tlv_len, FALSE);
proto_tree_add_item(tlv_tree, hf_sbc_number_dl_arq_ack_channel, tvb, offset, tlv_len, ENC_BIG_ENDIAN);
break;
case SBC_SS_PERMUTATION_SUPPORT:
tlv_tree = add_tlv_subtree(&tlv_info, ett_sbc_req_tlv_subtree, sbc_tree, hf_sbc_ss_permutation_support, tvb, offset, tlv_len, FALSE);
proto_tree_add_item(tlv_tree, hf_sbc_ss_optimal_pusc, tvb, offset, 1, ENC_BIG_ENDIAN);
proto_tree_add_item(tlv_tree, hf_sbc_ss_optimal_fusc, tvb, offset, 1, ENC_BIG_ENDIAN);
proto_tree_add_item(tlv_tree, hf_sbc_ss_amc_1x6, tvb, offset, 1, ENC_BIG_ENDIAN);
proto_tree_add_item(tlv_tree, hf_sbc_ss_amc_2x3, tvb, offset, 1, ENC_BIG_ENDIAN);
proto_tree_add_item(tlv_tree, hf_sbc_ss_amc_3x2, tvb, offset, 1, ENC_BIG_ENDIAN);
proto_tree_add_item(tlv_tree, hf_sbc_ss_amc_with_harq_map, tvb, offset, 1, ENC_BIG_ENDIAN);
proto_tree_add_item(tlv_tree, hf_sbc_ss_tusc1_support, tvb, offset, 1, ENC_BIG_ENDIAN);
proto_tree_add_item(tlv_tree, hf_sbc_ss_tusc2_support, tvb, offset, 1, ENC_BIG_ENDIAN);
break;
case SBC_SS_DEMODULATOR_MIMO_SUPPORT:
tlv_tree = add_tlv_subtree(&tlv_info, ett_sbc_req_tlv_subtree, sbc_tree, hf_sbc_ss_demodulator_mimo_support, tvb, offset, 2, FALSE);
proto_tree_add_item(tlv_tree, hf_sbc_ss_demodulator_mimo_2_ann_stc_matrix_a, tvb, offset, 2, ENC_BIG_ENDIAN);
proto_tree_add_item(tlv_tree, hf_sbc_ss_demodulator_mimo_2_ann_stc_matrix_b_vertical, tvb, offset, 2, ENC_BIG_ENDIAN);
proto_tree_add_item(tlv_tree, hf_sbc_ss_demodulator_mimo_2_ann_stc_matrix_b_horizontal, tvb, offset, 2, ENC_BIG_ENDIAN);
proto_tree_add_item(tlv_tree, hf_sbc_ss_demodulator_mimo_4_ann_stc_matrix_a, tvb, offset, 2, ENC_BIG_ENDIAN);
proto_tree_add_item(tlv_tree, hf_sbc_ss_demodulator_mimo_4_ann_stc_matrix_b_vertical, tvb, offset, 2, ENC_BIG_ENDIAN);
proto_tree_add_item(tlv_tree, hf_sbc_ss_demodulator_mimo_4_ann_stc_matrix_b_horizontal, tvb, offset, 2, ENC_BIG_ENDIAN);
proto_tree_add_item(tlv_tree, hf_sbc_ss_demodulator_mimo_4_ann_stc_matrix_c_vertical, tvb, offset, 2, ENC_BIG_ENDIAN);
proto_tree_add_item(tlv_tree, hf_sbc_ss_demodulator_mimo_4_ann_stc_matrix_c_horizontal, tvb, offset, 2, ENC_BIG_ENDIAN);
proto_tree_add_item(tlv_tree, hf_sbc_ss_demodulator_mimo_rsvd, tvb, offset, 2, ENC_BIG_ENDIAN);
break;
case SBC_SS_MIMO_UPLINK_SUPPORT:
tlv_tree = add_tlv_subtree(&tlv_info, ett_sbc_req_tlv_subtree, sbc_tree, hf_sbc_ss_mimo_uplink_support, tvb, offset, tlv_len, FALSE);
proto_tree_add_item(tlv_tree, hf_sbc_ss_mimo_uplink_support_2_ann_sttd, tvb, offset, 1, ENC_BIG_ENDIAN);
proto_tree_add_item(tlv_tree, hf_sbc_ss_mimo_uplink_support_2_ann_sm_vertical, tvb, offset, 1, ENC_BIG_ENDIAN);
proto_tree_add_item(tlv_tree, hf_sbc_ss_mimo_uplink_support_1_ann_coop_sm, tvb, offset, 1, ENC_BIG_ENDIAN);
proto_tree_add_item(tlv_tree, hf_sbc_ss_mimo_uplink_support_rsvd, tvb, offset, 1, ENC_BIG_ENDIAN);
break;
case SBC_SS_OFDMA_AAS_PRIVATE_MAP_SUPPORT:
tlv_tree = add_tlv_subtree(&tlv_info, ett_sbc_req_tlv_subtree, sbc_tree, hf_sbc_ss_ofdma_aas_private, tvb, offset, tlv_len, FALSE);
proto_tree_add_item(tlv_tree, hf_sbc_ofdma_aas_harq_map_capability, tvb, offset, 1, ENC_BIG_ENDIAN);
proto_tree_add_item(tlv_tree, hf_sbc_ofdma_aas_private_map_support, tvb, offset, 1, ENC_BIG_ENDIAN);
proto_tree_add_item(tlv_tree, hf_sbc_ofdma_aas_reduced_private_map_support, tvb, offset, 1, ENC_BIG_ENDIAN);
proto_tree_add_item(tlv_tree, hf_sbc_ofdma_aas_private_chain_enable, tvb, offset, 1, ENC_BIG_ENDIAN);
proto_tree_add_item(tlv_tree, hf_sbc_ofdma_aas_private_map_dl_frame_offset, tvb, offset, 1, ENC_BIG_ENDIAN);
proto_tree_add_item(tlv_tree, hf_sbc_ofdma_aas_private_ul_frame_offset, tvb, offset, 1, ENC_BIG_ENDIAN);
proto_tree_add_item(tlv_tree, hf_sbc_ofdma_aas_private_map_concurrency, tvb, offset, 1, ENC_BIG_ENDIAN);
break;
case SBC_SS_OFDMA_AAS_CAPABILITIES:
tlv_tree = add_tlv_subtree(&tlv_info, ett_sbc_req_tlv_subtree, sbc_tree, hf_sbc_ofdma_aas_capabilities, tvb, offset, tlv_len, FALSE);
proto_tree_add_item(tlv_tree, hf_sbc_ss_ofdma_aas_zone, tvb, offset, 2, ENC_BIG_ENDIAN);
proto_tree_add_item(tlv_tree, hf_sbc_ss_ofdma_aas_diversity_map_scan, tvb, offset, 2, ENC_BIG_ENDIAN);
proto_tree_add_item(tlv_tree, hf_sbc_ss_ofdma_aas_fbck_rsp_support, tvb, offset, 2, ENC_BIG_ENDIAN);
proto_tree_add_item(tlv_tree, hf_sbc_ss_ofdma_downlink_aas_preamble, tvb, offset, 2, ENC_BIG_ENDIAN);
proto_tree_add_item(tlv_tree, hf_sbc_ss_ofdma_uplink_aas_preamble, tvb, offset, 2, ENC_BIG_ENDIAN);
proto_tree_add_item(tlv_tree, hf_sbc_ss_ofdma_aas_capabilities_rsvd, tvb, offset, 2, ENC_BIG_ENDIAN);
break;
case SBC_SS_CINR_MEASUREMENT_CAPABILITY:
tlv_tree = add_tlv_subtree(&tlv_info, ett_sbc_req_tlv_subtree, sbc_tree, hf_sbc_ss_cinr_measure_capability, tvb, offset, tlv_len, FALSE);
proto_tree_add_item(tlv_tree, hf_sbc_ss_phy_cinr_measurement_preamble, tvb, offset, 1, ENC_BIG_ENDIAN);
proto_tree_add_item(tlv_tree, hf_sbc_ss_phy_cinr_measurement_permutation_zone_from_pilot_subcarriers, tvb, offset, 1, ENC_BIG_ENDIAN);
proto_tree_add_item(tlv_tree, hf_sbc_ss_phy_cinr_measurement_permutation_zone_from_data_subcarriers, tvb, offset, 1, ENC_BIG_ENDIAN);
proto_tree_add_item(tlv_tree, hf_sbc_ss_effective_cinr_measurement_preamble, tvb, offset, 1, ENC_BIG_ENDIAN);
proto_tree_add_item(tlv_tree, hf_sbc_ss_effective_cinr_measurement_permutation_zone_from_pilot_subcarriers, tvb, offset, 1, ENC_BIG_ENDIAN);
proto_tree_add_item(tlv_tree, hf_sbc_ss_effective_cinr_measurement_permutation_zone_from_data_subcarriers, tvb, offset, 1, ENC_BIG_ENDIAN);
proto_tree_add_item(tlv_tree, hf_sbc_ss_support_2_concurrent_cqi_channels,tvb,offset, 1, ENC_BIG_ENDIAN);
proto_tree_add_item(tlv_tree, hf_sbc_ss_frequency_selectivity_characterization_report,tvb,offset, 1, ENC_BIG_ENDIAN);
break;
case SBC_PKM_FLOW_CONTROL:
if (!include_cor2_changes)
{
tlv_tree = add_tlv_subtree(&tlv_info, ett_sbc_req_tlv_subtree, sbc_tree, hf_sbc_pkm_flow_control, tvb, offset, tlv_len, FALSE);
tlv_item = proto_tree_add_item(tlv_tree, hf_sbc_pkm_flow_control, tvb, offset, tlv_len, ENC_BIG_ENDIAN);
if(tvb_get_guint8(tvb, offset) == 0)
proto_item_append_text(tlv_item, " (default - no limit)");
}
else
{
tlv_tree = add_tlv_subtree(&tlv_info, ett_sbc_req_tlv_subtree, sbc_tree, hf_sbc_power_save_class_types_capability, tvb, offset, tlv_len, FALSE);
proto_tree_add_item(tlv_tree, hf_sbc_unknown_type, tvb, offset, tlv_len, ENC_NA);
}
break;
case SBC_AUTH_POLICY_SUPPORT:
tlv_item = proto_tree_add_item(sbc_tree, hf_sbc_auth_policy, tvb, offset, tlv_len, ENC_BIG_ENDIAN);
tlv_tree = proto_item_add_subtree(tlv_item, ett_sbc_req_tlv_subtree);
proto_tree_add_item(tlv_tree, hf_sbc_privacy_802_16, tvb, offset, 1, ENC_BIG_ENDIAN);
proto_tree_add_item(tlv_tree, hf_sbc_privacy_rsvd, tvb, offset, 1, ENC_BIG_ENDIAN);
tlv_tree = add_tlv_subtree(&tlv_info, ett_sbc_req_tlv_subtree, sbc_tree, hf_sbc_auth_policy, tvb, offset, tlv_len, FALSE);
proto_tree_add_item(tlv_tree, hf_sbc_privacy_802_16, tvb, offset, 1, ENC_BIG_ENDIAN);
proto_tree_add_item(tlv_tree, hf_sbc_privacy_rsvd, tvb, offset, 1, ENC_BIG_ENDIAN);
if (!include_cor2_changes)
{
tlv_tree = add_tlv_subtree(&tlv_info, ett_sbc_req_tlv_subtree, sbc_tree, hf_sbc_auth_policy, tvb, offset, tlv_len, FALSE);
proto_tree_add_item(tlv_tree, hf_sbc_privacy_802_16, tvb, offset, 1, ENC_BIG_ENDIAN);
proto_tree_add_item(tlv_tree, hf_sbc_privacy_rsvd, tvb, offset, 1, ENC_BIG_ENDIAN);
}
else
{
tlv_tree = add_tlv_subtree(&tlv_info, ett_sbc_req_tlv_subtree, sbc_tree, hf_sbc_power_save_class_types_capability, tvb, offset, tlv_len, FALSE);
proto_tree_add_item(tlv_tree, hf_sbc_unknown_type, tvb, offset, tlv_len, ENC_NA);
}
break;
case SBC_MAX_SECURITY_ASSOCIATIONS:
if (!include_cor2_changes)
{
tlv_tree = add_tlv_subtree(&tlv_info, ett_sbc_req_tlv_subtree, sbc_tree, hf_sbc_max_security_associations, tvb, offset, tlv_len, FALSE);
proto_tree_add_item(tlv_tree, hf_sbc_max_security_associations, tvb, offset, tlv_len, ENC_BIG_ENDIAN);
}
else
{
tlv_tree = add_tlv_subtree(&tlv_info, ett_sbc_req_tlv_subtree, sbc_tree, hf_sbc_power_save_class_types_capability, tvb, offset, tlv_len, FALSE);
proto_tree_add_item(tlv_tree, hf_sbc_unknown_type, tvb, offset, tlv_len, ENC_NA);
}
break;
case SBC_TLV_T_27_EXTENSION_CAPABILITY:
tlv_tree = add_tlv_subtree(&tlv_info, ett_sbc_req_tlv_subtree, sbc_tree, hf_sbc_tlv_t_27_extension_capability, tvb, offset, tlv_len, FALSE);
proto_tree_add_item(tlv_tree, hf_sbc_tlv_t_27_extension_capability_bit0, tvb, offset, 1, ENC_BIG_ENDIAN);
proto_tree_add_item(tlv_tree, hf_sbc_tlv_t_27_extension_capability_reserved, tvb, offset, 1, ENC_BIG_ENDIAN);
break;
case SBC_TLV_T_28_HO_TRIGGER_METRIC_SUPPORT:
tlv_tree = add_tlv_subtree(&tlv_info, ett_sbc_req_tlv_subtree, sbc_tree, hf_sbc_tlv_t_28_ho_trigger_metric_support, tvb, offset, tlv_len, FALSE);
proto_tree_add_item(tlv_tree, hf_sbc_tlv_t_28_ho_trigger_metric_support_bit0, tvb, offset, 1, ENC_BIG_ENDIAN);
proto_tree_add_item(tlv_tree, hf_sbc_tlv_t_28_ho_trigger_metric_support_bit1, tvb, offset, 1, ENC_BIG_ENDIAN);
proto_tree_add_item(tlv_tree, hf_sbc_tlv_t_28_ho_trigger_metric_support_bit2, tvb, offset, 1, ENC_BIG_ENDIAN);
proto_tree_add_item(tlv_tree, hf_sbc_tlv_t_28_ho_trigger_metric_support_bit3, tvb, offset, 1, ENC_BIG_ENDIAN);
proto_tree_add_item(tlv_tree, hf_sbc_tlv_t_28_ho_trigger_metric_support_reserved, tvb, offset, 1, ENC_BIG_ENDIAN);
break;
case SBC_TLV_T_167_ASSOCIATION_SUPPORT:
tlv_tree = add_tlv_subtree(&tlv_info, ett_sbc_req_tlv_subtree, sbc_tree, hf_sbc_tlv_t_167_association_type_support, tvb, offset, tlv_len, FALSE);
proto_tree_add_item(tlv_tree, hf_sbc_tlv_t_167_association_type_support_bit0, tvb, offset, 1, ENC_BIG_ENDIAN);
proto_tree_add_item(tlv_tree, hf_sbc_tlv_t_167_association_type_support_bit1, tvb, offset, 1, ENC_BIG_ENDIAN);
proto_tree_add_item(tlv_tree, hf_sbc_tlv_t_167_association_type_support_bit2, tvb, offset, 1, ENC_BIG_ENDIAN);
proto_tree_add_item(tlv_tree, hf_sbc_tlv_t_167_association_type_support_bit3, tvb, offset, 1, ENC_BIG_ENDIAN);
proto_tree_add_item(tlv_tree, hf_sbc_tlv_t_167_association_type_support_bit4, tvb, offset, 1, ENC_BIG_ENDIAN);
proto_tree_add_item(tlv_tree, hf_sbc_tlv_t_167_association_type_support_reserved, tvb, offset, 1, ENC_BIG_ENDIAN);
break;
case SBC_TLV_T_170_UPLINK_POWER_CONTROL_SUPPORT:
tlv_tree = add_tlv_subtree(&tlv_info, ett_sbc_req_tlv_subtree, sbc_tree, hf_sbc_ofdma_ss_uplink_power_control_support, tvb, offset, tlv_len, FALSE);
proto_tree_add_item(tlv_tree, hf_sbc_ofdma_ss_uplink_power_control_support_open_loop, tvb, offset, 1, ENC_BIG_ENDIAN);
proto_tree_add_item(tlv_tree, hf_sbc_ofdma_ss_uplink_power_control_support_aas_preamble, tvb, offset, 1, ENC_BIG_ENDIAN);
proto_tree_add_item(tlv_tree, hf_sbc_ofdma_ss_uplink_power_control_support_rsvd, tvb, offset, 1, ENC_BIG_ENDIAN);
break;
case SBC_TLV_T_171_MINIMUM_NUM_OF_FRAMES:
tlv_tree = add_tlv_subtree(&tlv_info, ett_sbc_req_tlv_subtree, sbc_tree, hf_sbc_tlv_t_171_minimum_num_of_frames, tvb, offset, tlv_len, FALSE);
proto_tree_add_item(tlv_tree, hf_sbc_tlv_t_171_minimum_num_of_frames, tvb, offset, tlv_len, ENC_BIG_ENDIAN);
break;
case SBC_TLV_T_172:
tlv_tree = add_tlv_subtree(&tlv_info, ett_sbc_req_tlv_subtree, sbc_tree, hf_sbc_tlv_t_172, tvb, offset, tlv_len, FALSE);
proto_tree_add_item(tlv_tree, hf_sbc_tlv_t_172_harq_map_capability, tvb, offset, 1, ENC_BIG_ENDIAN);
proto_tree_add_item(tlv_tree, hf_sbc_tlv_t_172_extended_harq_ie_capability, tvb, offset, 1, ENC_BIG_ENDIAN);
proto_tree_add_item(tlv_tree, hf_sbc_tlv_t_172_sub_map_capability_first_zone, tvb, offset, 1, ENC_BIG_ENDIAN);
proto_tree_add_item(tlv_tree, hf_sbc_tlv_t_172_sub_map_capability_other_zones, tvb, offset, 1, ENC_BIG_ENDIAN);
proto_tree_add_item(tlv_tree, hf_sbc_tlv_t_172_dl_region_definition_support, tvb, offset, 1, ENC_BIG_ENDIAN);
proto_tree_add_item(tlv_tree, hf_sbc_tlv_t_172_reserved, tvb, offset, 1, ENC_BIG_ENDIAN);
break;
case SBC_TLV_T_173_UL_CONTROL_CHANNEL_SUPPORT:
tlv_tree = add_tlv_subtree(&tlv_info, ett_sbc_req_tlv_subtree, sbc_tree, hf_sbc_tlv_t_173_ul_ctl_channel_support, tvb, offset, tlv_len, FALSE);
proto_tree_add_item(tlv_tree, hf_sbc_tlv_t_173_3_bit_mimo_fast_feedback, tvb, offset, 1, ENC_BIG_ENDIAN);
proto_tree_add_item(tlv_tree, hf_sbc_tlv_t_173_enhanced_fast_feedback, tvb, offset, 1, ENC_BIG_ENDIAN);
proto_tree_add_item(tlv_tree, hf_sbc_tlv_t_173_ul_ack, tvb, offset, 1, ENC_BIG_ENDIAN);
proto_tree_add_item(tlv_tree, hf_sbc_tlv_t_173_reserved, tvb, offset, 1, ENC_BIG_ENDIAN);
proto_tree_add_item(tlv_tree, hf_sbc_tlv_t_173_uep_fast_feedback, tvb, offset, 1, ENC_BIG_ENDIAN);
proto_tree_add_item(tlv_tree, hf_sbc_tlv_t_173_measurement_report, tvb, offset, 1, ENC_BIG_ENDIAN);
proto_tree_add_item(tlv_tree, hf_sbc_tlv_t_173_primary_secondary_fast_feedback, tvb, offset, 1, ENC_BIG_ENDIAN);
proto_tree_add_item(tlv_tree, hf_sbc_tlv_t_173_diuc_cqi_fast_feedback, tvb, offset, 1, ENC_BIG_ENDIAN);
break;
case SBC_TLV_T_174_OFDMA_MS_CSIT_CAPABILITY:
tlv_tree = add_tlv_subtree(&tlv_info, ett_sbc_req_tlv_subtree, sbc_tree, hf_sbc_tlv_t_174_ofdma_ms_csit_capability, tvb, offset, tlv_len, FALSE);
proto_tree_add_item(tlv_tree, hf_sbc_tlv_t_174_csit_compatibility_type_a, tvb, offset, 2, ENC_BIG_ENDIAN);
proto_tree_add_item(tlv_tree, hf_sbc_tlv_t_174_csit_compatibility_type_b, tvb, offset, 2, ENC_BIG_ENDIAN);
proto_tree_add_item(tlv_tree, hf_sbc_tlv_t_174_power_assignment_capability, tvb, offset, 2, ENC_BIG_ENDIAN);
proto_tree_add_item(tlv_tree, hf_sbc_tlv_t_174_sounding_rsp_time_capability, tvb, offset, 2, ENC_BIG_ENDIAN);
proto_tree_add_item(tlv_tree, hf_sbc_tlv_t_174_max_num_simultanous_sounding_instructions, tvb, offset, 2, ENC_BIG_ENDIAN);
proto_tree_add_item(tlv_tree, hf_sbc_tlv_t_174_ss_csit_type_a_support, tvb, offset, 2, ENC_BIG_ENDIAN);
proto_tree_add_item(tlv_tree, hf_sbc_tlv_t_174_ss_csit_reserved, tvb, offset, 2, ENC_BIG_ENDIAN);
break;
case SBC_TLV_T_175_MAX_NUM_BST_PER_FRM_CAPABILITY_HARQ:
tlv_tree = add_tlv_subtree(&tlv_info, ett_sbc_req_tlv_subtree, sbc_tree, hf_sbc_tlv_t_175_max_num_bst_per_frm_capability_harq, tvb, offset, tlv_len, FALSE);
proto_tree_add_item(tlv_tree, hf_sbc_tlv_t_175_max_num_ul_harq_bst, tvb, offset, 1, ENC_BIG_ENDIAN);
proto_tree_add_item(tlv_tree, hf_sbc_tlv_t_175_max_num_ul_harq_per_frm_include_one_non_harq_bst, tvb, offset, 1, ENC_BIG_ENDIAN);
proto_tree_add_item(tlv_tree, hf_sbc_tlv_t_175_max_num_dl_harq_bst_per_harq_per_frm, tvb, offset, 1, ENC_BIG_ENDIAN);
break;
case SBC_TLV_T_176:
tlv_tree = add_tlv_subtree(&tlv_info, ett_sbc_req_tlv_subtree, sbc_tree, hf_sbc_tlv_t_176, tvb, offset, tlv_len, FALSE);
proto_tree_add_item(tlv_tree, hf_sbc_tlv_t_176_bit0, tvb, offset, 3, ENC_BIG_ENDIAN);
proto_tree_add_item(tlv_tree, hf_sbc_tlv_t_176_bit1, tvb, offset, 3, ENC_BIG_ENDIAN);
proto_tree_add_item(tlv_tree, hf_sbc_tlv_t_176_bit2, tvb, offset, 3, ENC_BIG_ENDIAN);
proto_tree_add_item(tlv_tree, hf_sbc_tlv_t_176_bit3, tvb, offset, 3, ENC_BIG_ENDIAN);
proto_tree_add_item(tlv_tree, hf_sbc_tlv_t_176_bit4, tvb, offset, 3, ENC_BIG_ENDIAN);
proto_tree_add_item(tlv_tree, hf_sbc_tlv_t_176_bit5, tvb, offset, 3, ENC_BIG_ENDIAN);
proto_tree_add_item(tlv_tree, hf_sbc_tlv_t_176_bit6, tvb, offset, 3, ENC_BIG_ENDIAN);
proto_tree_add_item(tlv_tree, hf_sbc_tlv_t_176_bit7, tvb, offset, 3, ENC_BIG_ENDIAN);
proto_tree_add_item(tlv_tree, hf_sbc_tlv_t_176_bit8, tvb, offset, 3, ENC_BIG_ENDIAN);
proto_tree_add_item(tlv_tree, hf_sbc_tlv_t_176_bit9, tvb, offset, 3, ENC_BIG_ENDIAN);
proto_tree_add_item(tlv_tree, hf_sbc_tlv_t_176_bit10, tvb, offset, 3, ENC_BIG_ENDIAN);
proto_tree_add_item(tlv_tree, hf_sbc_tlv_t_176_bit11, tvb, offset, 3, ENC_BIG_ENDIAN);
proto_tree_add_item(tlv_tree, hf_sbc_tlv_t_176_bit12, tvb, offset, 3, ENC_BIG_ENDIAN);
proto_tree_add_item(tlv_tree, hf_sbc_tlv_t_176_bit13, tvb, offset, 3, ENC_BIG_ENDIAN);
proto_tree_add_item(tlv_tree, hf_sbc_tlv_t_176_bit14, tvb, offset, 3, ENC_BIG_ENDIAN);
proto_tree_add_item(tlv_tree, hf_sbc_tlv_t_176_bit15, tvb, offset, 3, ENC_BIG_ENDIAN);
proto_tree_add_item(tlv_tree, hf_sbc_tlv_t_176_bit16, tvb, offset, 3, ENC_BIG_ENDIAN);
proto_tree_add_item(tlv_tree, hf_sbc_tlv_t_176_bit17, tvb, offset, 3, ENC_BIG_ENDIAN);
proto_tree_add_item(tlv_tree, hf_sbc_tlv_t_176_bit18, tvb, offset, 3, ENC_BIG_ENDIAN);
proto_tree_add_item(tlv_tree, hf_sbc_tlv_t_176_bit19, tvb, offset, 3, ENC_BIG_ENDIAN);
proto_tree_add_item(tlv_tree, hf_sbc_tlv_t_176_reserved, tvb, offset, 3, ENC_BIG_ENDIAN);
break;
case SBC_TLV_T_177_OFDMA_SS_MODULATOR_FOR_MIMO_SUPPORT:
tlv_tree = add_tlv_subtree(&tlv_info, ett_sbc_req_tlv_subtree, sbc_tree, hf_sbc_tlv_t_177_ofdma_ss_modulator_for_mimo_support, tvb, offset, tlv_len, FALSE);
if (include_cor2_changes)
{
proto_tree_add_item(tlv_tree, hf_sbc_tlv_t_177_stc_matrix_a, tvb, offset, 1, ENC_BIG_ENDIAN);
proto_tree_add_item(tlv_tree, hf_sbc_tlv_t_177_stc_matrix_b_vertical, tvb, offset, 1, ENC_BIG_ENDIAN);
proto_tree_add_item(tlv_tree, hf_sbc_tlv_t_177_stc_matrix_b_horizontal, tvb, offset, 1, ENC_BIG_ENDIAN);
} else {
proto_tree_add_item(tlv_tree, hf_sbc_tlv_t_177_two_transmit_antennas, tvb, offset, 1, ENC_BIG_ENDIAN);
proto_tree_add_item(tlv_tree, hf_sbc_tlv_t_177_capable_of_transmit_diversity, tvb, offset, 1, ENC_BIG_ENDIAN);
proto_tree_add_item(tlv_tree, hf_sbc_tlv_t_177_capable_of_spacial_multiplexing, tvb, offset, 1, ENC_BIG_ENDIAN);
}
proto_tree_add_item(tlv_tree, hf_sbc_tlv_t_177_beamforming, tvb, offset, 1, ENC_BIG_ENDIAN);
proto_tree_add_item(tlv_tree, hf_sbc_tlv_t_177_adaptive_rate_ctl, tvb, offset, 1, ENC_BIG_ENDIAN);
proto_tree_add_item(tlv_tree, hf_sbc_tlv_t_177_single_antenna, tvb, offset, 1, ENC_BIG_ENDIAN);
if (include_cor2_changes)
{
proto_tree_add_item(tlv_tree, hf_sbc_tlv_t_177_collaborative_sm_with_one_antenna, tvb, offset, 1, ENC_BIG_ENDIAN);
proto_tree_add_item(tlv_tree, hf_sbc_tlv_t_177_collaborative_sm_with_two_antennas, tvb, offset, 1, ENC_BIG_ENDIAN);
} else {
proto_tree_add_item(tlv_tree, hf_sbc_tlv_t_177_capable_of_two_antenna, tvb, offset, 1, ENC_BIG_ENDIAN);
proto_tree_add_item(tlv_tree, hf_sbc_tlv_t_177_rsvd, tvb, offset, 1, ENC_BIG_ENDIAN);
}
break;
case SBC_TLV_T_178_SDMA_PILOT_CAPABILITY:
tlv_tree = add_tlv_subtree(&tlv_info, ett_sbc_req_tlv_subtree, sbc_tree, hf_sbc_tlv_t_178_sdma_pilot_capability, tvb, offset, tlv_len, FALSE);
proto_tree_add_item(tlv_tree, hf_sbc_tlv_t_178_sdma_pilot_pattern_support_for_amc_zone, tvb, offset, 1, ENC_BIG_ENDIAN);
proto_tree_add_item(tlv_tree, hf_sbc_tlv_t_178_reserved, tvb, offset, 1, ENC_BIG_ENDIAN);
break;
case SBC_TLV_T_179_OFDMA_MULTIPLE_DL_BURST_PROFILE_CAPABILITY:
tlv_tree = add_tlv_subtree(&tlv_info, ett_sbc_req_tlv_subtree, sbc_tree, hf_sbc_tlv_t_179_ofdma_multiple_dl_burst_profile_support, tvb, offset, tlv_len, FALSE);
proto_tree_add_item(tlv_tree, hf_sbc_tlv_t_179_dl_bst_profile_for_multiple_fec, tvb, offset, 1, ENC_BIG_ENDIAN);
proto_tree_add_item(tlv_tree, hf_sbc_tlv_t_179_ul_bst_profile_for_multiple_fec, tvb, offset, 1, ENC_BIG_ENDIAN);
proto_tree_add_item(tlv_tree, hf_sbc_tlv_t_179_reserved, tvb, offset, 1, ENC_BIG_ENDIAN);
break;
case SBC_TLV_T_204_OFDMA_PARAMETERS_SETS:
if (include_cor2_changes)
{
tlv_tree = add_tlv_subtree(&tlv_info, ett_sbc_req_tlv_subtree, sbc_tree, hf_sbc_tlv_t_204_ofdma_parameters_sets, tvb, offset, tlv_len, FALSE);
proto_tree_add_item(tlv_tree, hf_sbc_tlv_t_204_ofdma_parameters_sets_phy_set_a, tvb, offset, 1, ENC_BIG_ENDIAN);
proto_tree_add_item(tlv_tree, hf_sbc_tlv_t_204_ofdma_parameters_sets_phy_set_b, tvb, offset, 1, ENC_BIG_ENDIAN);
proto_tree_add_item(tlv_tree, hf_sbc_tlv_t_204_ofdma_parameters_sets_harq_parameters_set, tvb, offset, 1, ENC_BIG_ENDIAN);
proto_tree_add_item(tlv_tree, hf_sbc_tlv_t_204_ofdma_parameters_sets_mac_set_a, tvb, offset, 1, ENC_BIG_ENDIAN);
proto_tree_add_item(tlv_tree, hf_sbc_tlv_t_204_ofdma_parameters_sets_mac_set_b, tvb, offset, 1, ENC_BIG_ENDIAN);
proto_tree_add_item(tlv_tree, hf_sbc_tlv_t_204_ofdma_parameters_sets_reserved, tvb, offset, 1, ENC_BIG_ENDIAN);
}
break;
case SBC_TLV_T_162_HARQ_INCREMENTAL_REDUNDANCY_BUFFER_CAPABILITY:
tlv_tree = add_tlv_subtree(&tlv_info, ett_sbc_req_tlv_subtree, sbc_tree, hf_sbc_tlv_t_162_harq_incremental_redundancy_buffer_capability, tvb, offset, tlv_len, FALSE);
proto_tree_add_item(tlv_tree, hf_sbc_tlv_t_162_harq_incremental_redundancy_buffer_capability_NEP, tvb, offset, 2, ENC_BIG_ENDIAN);
proto_tree_add_item(tlv_tree, hf_sbc_tlv_t_162_harq_incremental_redundancy_buffer_capability_aggregation_flag_for_dl, tvb, offset, 2, ENC_BIG_ENDIAN);
proto_tree_add_item(tlv_tree, hf_sbc_tlv_t_162_harq_incremental_redundancy_buffer_capability_reserved1, tvb, offset, 2, ENC_BIG_ENDIAN);
proto_tree_add_item(tlv_tree, hf_sbc_tlv_t_162_ul_harq_incremental_redundancy_buffer_capability_NEP, tvb, offset, 2, ENC_BIG_ENDIAN);
proto_tree_add_item(tlv_tree, hf_sbc_tlv_t_162_harq_incremental_redundancy_buffer_capability_aggregation_flag_for_ul, tvb, offset, 2, ENC_BIG_ENDIAN);
proto_tree_add_item(tlv_tree, hf_sbc_tlv_t_162_harq_incremental_redundancy_buffer_capability_reserved2, tvb, offset, 2, ENC_BIG_ENDIAN);
break;
case SBC_TLV_T_163_HARQ_CHASE_COMBINING_AND_CC_IR_BUFFER_CAPABILITY:
tlv_tree = add_tlv_subtree(&tlv_info, ett_sbc_req_tlv_subtree, sbc_tree, hf_sbc_tlv_t_163_harq_chase_combining_and_cc_ir_buffer_capability, tvb, offset, tlv_len, FALSE);
proto_tree_add_item(tlv_tree, hf_sbc_tlv_t_163_dl_harq_buffering_capability_for_chase_combining, tvb, offset, 2, ENC_BIG_ENDIAN);
proto_tree_add_item(tlv_tree, hf_sbc_tlv_t_163_harq_chase_combining_and_cc_ir_buffer_capability_aggregation_flag_dl, tvb, offset, 2, ENC_BIG_ENDIAN);
proto_tree_add_item(tlv_tree, hf_sbc_tlv_t_163_harq_chase_combining_and_cc_ir_buffer_capability_reserved1, tvb, offset, 2, ENC_BIG_ENDIAN);
proto_tree_add_item(tlv_tree, hf_sbc_tlv_t_163_ul_harq_buffering_capability_for_chase_combining, tvb, offset, 2, ENC_BIG_ENDIAN);
proto_tree_add_item(tlv_tree, hf_sbc_tlv_t_163_harq_chase_combining_and_cc_ir_buffer_capability_aggregation_flag_ul, tvb, offset, 2, ENC_BIG_ENDIAN);
proto_tree_add_item(tlv_tree, hf_sbc_tlv_t_163_harq_chase_combining_and_cc_ir_buffer_capability_reserved2, tvb, offset, 2, ENC_BIG_ENDIAN);
break;
case PKM_ATTR_SECURITY_NEGOTIATION_PARAMETERS:
tlv_tree = add_protocol_subtree(&tlv_info, ett_sbc_req_tlv_subtree, sbc_tree, proto_mac_mgmt_msg_sbc_decoder, tvb, offset, tlv_len, "Security Negotiation Parameters (%u bytes)", tlv_len);
wimax_security_negotiation_parameters_decoder(tvb_new_subset(tvb, offset, tlv_len, tlv_len), pinfo, tlv_tree);
break;
case SBC_TLV_T_26_POWER_SAVE_CLASS_TYPES_CAPABILITY:
tlv_tree = add_tlv_subtree(&tlv_info, ett_sbc_req_tlv_subtree, sbc_tree, hf_sbc_power_save_class_types_capability, tvb, offset, tlv_len, FALSE);
proto_tree_add_item(tlv_tree, hf_sbc_power_save_class_types_capability_bit0, tvb, offset, 1, ENC_BIG_ENDIAN);
proto_tree_add_item(tlv_tree, hf_sbc_power_save_class_types_capability_bit1, tvb, offset, 1, ENC_BIG_ENDIAN);
proto_tree_add_item(tlv_tree, hf_sbc_power_save_class_types_capability_bit2, tvb, offset, 1, ENC_BIG_ENDIAN);
proto_tree_add_item(tlv_tree, hf_sbc_power_save_class_types_capability_bits34, tvb, offset, 1, ENC_BIG_ENDIAN);
proto_tree_add_item(tlv_tree, hf_sbc_power_save_class_types_capability_bits567, tvb, offset, 1, ENC_BIG_ENDIAN);
break;
default:
tlv_tree = add_tlv_subtree(&tlv_info, ett_sbc_req_tlv_subtree, sbc_tree, hf_sbc_power_save_class_types_capability, tvb, offset, tlv_len, FALSE);
proto_tree_add_item(tlv_tree, hf_sbc_unknown_type, tvb, offset, tlv_len, ENC_NA);
break;
}
offset += tlv_len;
}
}
}
void dissect_mac_mgmt_msg_sbc_rsp_decoder(tvbuff_t *tvb, packet_info *pinfo, proto_tree *tree)
{
guint offset = 0;
guint tvb_len, payload_type, value;
gint tlv_type, tlv_len, tlv_value_offset;
proto_item *sbc_item = NULL;
proto_tree *sbc_tree = NULL;
proto_item *tlv_item = NULL;
proto_tree *tlv_tree = NULL;
proto_item *ti = NULL;
tlv_info_t tlv_info;
gfloat power_bpsk;
gfloat power_qpsk;
gfloat power_qam16;
gfloat power_qam64;
gfloat current_power;
payload_type = tvb_get_guint8(tvb, offset);
if (payload_type != MAC_MGMT_MSG_SBC_RSP)
{
return;
}
if (tree)
{
tvb_len = tvb_reported_length(tvb);
sbc_item = proto_tree_add_protocol_format(tree, proto_mac_mgmt_msg_sbc_decoder, tvb, offset, tvb_len, "SS Basic Capability Response (SBC-RSP) (%u bytes)", tvb_len);
sbc_tree = proto_item_add_subtree(sbc_item, ett_mac_mgmt_msg_sbc_decoder);
proto_tree_add_item(sbc_tree, hf_sbc_rsp_message_type, tvb, offset, 1, ENC_BIG_ENDIAN);
offset++;
while(offset < tvb_len)
{
init_tlv_info(&tlv_info, tvb, offset);
tlv_type = get_tlv_type(&tlv_info);
tlv_len = get_tlv_length(&tlv_info);
if (tlv_type == -1 || tlv_len > MAX_TLV_LEN || tlv_len < 1)
{
col_append_sep_str(pinfo->cinfo, COL_INFO, NULL, "SBC-RSP TLV error");
proto_tree_add_item(sbc_tree, hf_sbc_invalid_tlv, tvb, offset, (tvb_len - offset), ENC_NA);
break;
}
if (tlv_type == 0)
{
col_append_sep_str(pinfo->cinfo, COL_INFO, NULL, "Invalid SBC TLV type");
proto_tree_add_item(sbc_tree, hf_sbc_unknown_type, tvb, offset, 1, ENC_NA);
offset++;
continue;
}
tlv_value_offset = get_tlv_value_offset(&tlv_info);
#ifdef DEBUG
proto_tree_add_protocol_format(sbc_tree, proto_mac_mgmt_msg_sbc_decoder, tvb, offset, (tlv_len + tlv_value_offset), "SBC-RSP Type: %u (%u bytes, offset=%u, tlv_len=%u, tvb_len=%u)", tlv_type, (tlv_len + tlv_value_offset), offset, tlv_len, tvb_len);
#endif
offset += tlv_value_offset;
switch (tlv_type)
{
case SBC_BW_ALLOC_SUPPORT:
tlv_tree = add_tlv_subtree(&tlv_info, ett_sbc_rsp_tlv_subtree, sbc_tree, hf_sbc_bw_alloc_support, tvb, offset, tlv_len, FALSE);
proto_tree_add_item(tlv_tree, hf_sbc_bw_alloc_support_rsvd0, tvb, offset, 1, ENC_BIG_ENDIAN);
proto_tree_add_item(tlv_tree, hf_sbc_bw_alloc_support_duplex, tvb, offset, 1, ENC_BIG_ENDIAN);
proto_tree_add_item(tlv_tree, hf_sbc_bw_alloc_support_rsvd1, tvb, offset, 1, ENC_BIG_ENDIAN);
break;
case SBC_TRANSITION_GAPS:
tlv_tree = add_tlv_subtree(&tlv_info, ett_sbc_rsp_tlv_subtree, sbc_tree, hf_sbc_transition_gaps, tvb, offset, tlv_len, FALSE);
ti = proto_tree_add_item(tlv_tree, hf_sbc_ssttg, tvb, offset, 1, ENC_BIG_ENDIAN);
proto_item_append_text(ti, " us (ranges: TDD 0-50; H-FDD 0-100)");
ti = proto_tree_add_item(tlv_tree, hf_sbc_ssrtg, tvb, (offset + 1), 1, ENC_BIG_ENDIAN);
proto_item_append_text(ti, " us (ranges: TDD 0-50; H-FDD 0-100)");
break;
case SBC_MAC_PDU:
tlv_tree = add_tlv_subtree(&tlv_info, ett_sbc_rsp_tlv_subtree, sbc_tree, hf_sbc_mac_pdu, tvb, offset, tlv_len, FALSE);
proto_tree_add_item(tlv_tree, hf_sbc_mac_pdu_piggybacked, tvb, offset, 1, ENC_BIG_ENDIAN);
proto_tree_add_item(tlv_tree, hf_sbc_mac_pdu_fsn, tvb, offset, 1, ENC_BIG_ENDIAN);
proto_tree_add_item(tlv_tree, hf_sbc_mac_pdu_rsvd, tvb, offset, 1, ENC_BIG_ENDIAN);
break;
case SBC_REQ_MAX_TRANSMIT_POWER:
tlv_tree = add_tlv_subtree(&tlv_info, ett_sbc_rsp_tlv_subtree, sbc_tree, hf_sbc_max_transmit_power, tvb, offset, tlv_len, FALSE);
power_bpsk = (gfloat)(tvb_get_guint8(tvb, offset) - 128) / 2;
power_qpsk = (gfloat)(tvb_get_guint8(tvb, (offset + 1)) - 128) / 2;
power_qam16 = (gfloat)(tvb_get_guint8(tvb, (offset + 2)) - 128) / 2;
power_qam64 = (gfloat)(tvb_get_guint8(tvb, (offset + 3)) - 128) / 2;
proto_tree_add_text(tlv_tree, tvb, offset, 1, "BPSK: %.2f dBm", (gdouble)power_bpsk);
proto_tree_add_text(tlv_tree, tvb, (offset + 1), 1, "QPSK: %.2f dBm", (gdouble)power_qpsk);
proto_tree_add_text(tlv_tree, tvb, (offset + 2), 1, "QAM16: %.2f dBm", (gdouble)power_qam16);
proto_tree_add_text(tlv_tree, tvb, (offset + 3), 1, "QAM64: %.2f dBm", (gdouble)power_qam64);
break;
case SBC_REQ_CURR_TRANSMITTED_POWER:
tlv_tree = add_tlv_subtree(&tlv_info, ett_sbc_rsp_tlv_subtree, sbc_tree, hf_sbc_curr_transmit_power, tvb, offset, tlv_len, FALSE);
value = tvb_get_guint8(tvb, offset);
current_power = (gfloat)(value - 128) / 2;
proto_tree_add_text(tlv_tree, tvb, offset, 1, "Current Transmitted Power: %.2f dBm (Value: 0x%x)", (gdouble)current_power, value);
break;
case SBC_SS_FFT_SIZES:
tlv_tree = add_tlv_subtree(&tlv_info, ett_sbc_rsp_tlv_subtree, sbc_tree, hf_sbc_ss_fft_sizes, tvb, offset, tlv_len, FALSE);
if (include_cor2_changes)
{
proto_tree_add_item(tlv_tree, hf_sbc_ss_fft_rsvd1, tvb, offset, 1, ENC_BIG_ENDIAN);
} else {
proto_tree_add_item(tlv_tree, hf_sbc_ss_fft_256, tvb, offset, 1, ENC_BIG_ENDIAN);
}
proto_tree_add_item(tlv_tree, hf_sbc_ss_fft_2048, tvb, offset, 1, ENC_BIG_ENDIAN);
proto_tree_add_item(tlv_tree, hf_sbc_ss_fft_128, tvb, offset, 1, ENC_BIG_ENDIAN);
proto_tree_add_item(tlv_tree, hf_sbc_ss_fft_512, tvb, offset, 1, ENC_BIG_ENDIAN);
proto_tree_add_item(tlv_tree, hf_sbc_ss_fft_1024, tvb, offset, 1, ENC_BIG_ENDIAN);
proto_tree_add_item(tlv_tree, hf_sbc_ss_fft_rsvd2, tvb, offset, 1, ENC_BIG_ENDIAN);
break;
case SBC_SS_DEMODULATOR:
tlv_tree = add_tlv_subtree(&tlv_info, ett_sbc_rsp_tlv_subtree, sbc_tree, hf_sbc_ss_demodulator, tvb, offset, tlv_len, FALSE);
if (tlv_len == 1)
{
proto_tree_add_item(tlv_tree, hf_sbc_ss_demodulator_64qam, tvb, offset, 1, ENC_BIG_ENDIAN);
proto_tree_add_item(tlv_tree, hf_sbc_ss_demodulator_btc, tvb, offset, 1, ENC_BIG_ENDIAN);
proto_tree_add_item(tlv_tree, hf_sbc_ss_demodulator_ctc, tvb, offset, 1, ENC_BIG_ENDIAN);
proto_tree_add_item(tlv_tree, hf_sbc_ss_demodulator_stc, tvb, offset, 1, ENC_BIG_ENDIAN);
proto_tree_add_item(tlv_tree, hf_sbc_ss_demodulator_cc_with_optional_interleaver, tvb, offset, 1, ENC_BIG_ENDIAN);
proto_tree_add_item(tlv_tree, hf_sbc_ss_demodulator_harq_chase, tvb, offset, 1, ENC_BIG_ENDIAN);
proto_tree_add_item(tlv_tree, hf_sbc_ss_demodulator_harq_ctc_ir, tvb, offset, 1, ENC_BIG_ENDIAN);
proto_tree_add_item(tlv_tree, hf_sbc_ss_demodulator_reserved, tvb, offset, 1, ENC_BIG_ENDIAN);
}
else
{
proto_tree_add_item(tlv_tree, hf_sbc_ss_demodulator_64qam_2, tvb, offset, 2, ENC_BIG_ENDIAN);
proto_tree_add_item(tlv_tree, hf_sbc_ss_demodulator_btc_2, tvb, offset, 2, ENC_BIG_ENDIAN);
proto_tree_add_item(tlv_tree, hf_sbc_ss_demodulator_ctc_2, tvb, offset, 2, ENC_BIG_ENDIAN);
proto_tree_add_item(tlv_tree, hf_sbc_ss_demodulator_stc_2, tvb, offset, 2, ENC_BIG_ENDIAN);
proto_tree_add_item(tlv_tree, hf_sbc_ss_demodulator_cc_with_optional_interleaver_2, tvb, offset, 2, ENC_BIG_ENDIAN);
proto_tree_add_item(tlv_tree, hf_sbc_ss_demodulator_harq_chase_2, tvb, offset, 2, ENC_BIG_ENDIAN);
proto_tree_add_item(tlv_tree, hf_sbc_ss_demodulator_harq_ctc_ir_2, tvb, offset, 2, ENC_BIG_ENDIAN);
proto_tree_add_item(tlv_tree, hf_sbc_ss_demodulator_reserved_2, tvb, offset, 2, ENC_BIG_ENDIAN);
proto_tree_add_item(tlv_tree, hf_sbc_ss_demodulator_harq_cc_ir_2, tvb, offset , 2, ENC_BIG_ENDIAN);
proto_tree_add_item(tlv_tree, hf_sbc_ss_demodulator_ldpc_2, tvb, offset, 2, ENC_BIG_ENDIAN);
proto_tree_add_item(tlv_tree, hf_sbc_ss_demodulator_dedicated_pilots_2, tvb, offset, 2, ENC_BIG_ENDIAN);
proto_tree_add_item(tlv_tree, hf_sbc_ss_demodulator_reserved1_2, tvb, offset, 2, ENC_BIG_ENDIAN);
}
break;
case SBC_SS_MODULATOR:
tlv_tree = add_tlv_subtree(&tlv_info, ett_sbc_req_tlv_subtree, sbc_tree, hf_sbc_ss_modulator, tvb, offset, tlv_len, FALSE);
proto_tree_add_item(tlv_tree, hf_sbc_ss_modulator_64qam, tvb, offset, 1, ENC_BIG_ENDIAN);
proto_tree_add_item(tlv_tree, hf_sbc_ss_modulator_btc, tvb, offset, 1, ENC_BIG_ENDIAN);
proto_tree_add_item(tlv_tree, hf_sbc_ss_modulator_ctc, tvb, offset, 1, ENC_BIG_ENDIAN);
proto_tree_add_item(tlv_tree, hf_sbc_ss_modulator_stc, tvb, offset, 1, ENC_BIG_ENDIAN);
proto_tree_add_item(tlv_tree, hf_sbc_ss_modulator_harq_chase, tvb, offset, 1, ENC_BIG_ENDIAN);
proto_tree_add_item(tlv_tree, hf_sbc_ss_modulator_ctc_ir, tvb, offset, 1, ENC_BIG_ENDIAN);
proto_tree_add_item(tlv_tree, hf_sbc_ss_modulator_cc_ir, tvb, offset, 1, ENC_BIG_ENDIAN);
proto_tree_add_item(tlv_tree, hf_sbc_ss_modulator_ldpc, tvb, offset, 1, ENC_BIG_ENDIAN);
break;
case SBC_SS_NUM_UL_ARQ_ACK_CHANNEL:
tlv_tree = add_tlv_subtree(&tlv_info, ett_sbc_rsp_tlv_subtree, sbc_tree, hf_sbc_number_ul_arq_ack_channel, tvb, offset, tlv_len, FALSE);
proto_tree_add_item(tlv_tree, hf_sbc_number_ul_arq_ack_channel, tvb, offset, tlv_len, ENC_BIG_ENDIAN);
break;
case SBC_SS_NUM_DL_ARQ_ACK_CHANNEL:
tlv_tree = add_tlv_subtree(&tlv_info, ett_sbc_rsp_tlv_subtree, sbc_tree, hf_sbc_number_dl_arq_ack_channel, tvb, offset, tlv_len, FALSE);
proto_tree_add_item(tlv_tree, hf_sbc_number_dl_arq_ack_channel, tvb, offset, tlv_len, ENC_BIG_ENDIAN);
break;
case SBC_SS_PERMUTATION_SUPPORT:
tlv_tree = add_tlv_subtree(&tlv_info, ett_sbc_rsp_tlv_subtree, sbc_tree, hf_sbc_ss_permutation_support, tvb, offset, tlv_len, FALSE);
proto_tree_add_item(tlv_tree, hf_sbc_ss_optimal_pusc, tvb, offset, 1, ENC_BIG_ENDIAN);
proto_tree_add_item(tlv_tree, hf_sbc_ss_optimal_fusc, tvb, offset, 1, ENC_BIG_ENDIAN);
proto_tree_add_item(tlv_tree, hf_sbc_ss_amc_1x6, tvb, offset, 1, ENC_BIG_ENDIAN);
proto_tree_add_item(tlv_tree, hf_sbc_ss_amc_2x3, tvb, offset, 1, ENC_BIG_ENDIAN);
proto_tree_add_item(tlv_tree, hf_sbc_ss_amc_3x2, tvb, offset, 1, ENC_BIG_ENDIAN);
proto_tree_add_item(tlv_tree, hf_sbc_ss_amc_with_harq_map, tvb, offset, 1, ENC_BIG_ENDIAN);
proto_tree_add_item(tlv_tree, hf_sbc_ss_tusc1_support, tvb, offset, 1, ENC_BIG_ENDIAN);
proto_tree_add_item(tlv_tree, hf_sbc_ss_tusc2_support, tvb, offset, 1, ENC_BIG_ENDIAN);
break;
case SBC_SS_DEMODULATOR_MIMO_SUPPORT:
tlv_tree = add_tlv_subtree(&tlv_info, ett_sbc_rsp_tlv_subtree, sbc_tree, hf_sbc_ss_demodulator_mimo_support, tvb, offset, tlv_len, FALSE);
proto_tree_add_item(tlv_tree, hf_sbc_ss_demodulator_mimo_2_ann_stc_matrix_a, tvb, offset, 2, ENC_BIG_ENDIAN);
proto_tree_add_item(tlv_tree, hf_sbc_ss_demodulator_mimo_2_ann_stc_matrix_b_vertical, tvb, offset, 2, ENC_BIG_ENDIAN);
proto_tree_add_item(tlv_tree, hf_sbc_ss_demodulator_mimo_2_ann_stc_matrix_b_horizontal, tvb, offset, 2, ENC_BIG_ENDIAN);
proto_tree_add_item(tlv_tree, hf_sbc_ss_demodulator_mimo_4_ann_stc_matrix_a, tvb, offset, 2, ENC_BIG_ENDIAN);
proto_tree_add_item(tlv_tree, hf_sbc_ss_demodulator_mimo_4_ann_stc_matrix_b_vertical, tvb, offset, 2, ENC_BIG_ENDIAN);
proto_tree_add_item(tlv_tree, hf_sbc_ss_demodulator_mimo_4_ann_stc_matrix_b_horizontal, tvb, offset, 2, ENC_BIG_ENDIAN);
proto_tree_add_item(tlv_tree, hf_sbc_ss_demodulator_mimo_4_ann_stc_matrix_c_vertical, tvb, offset, 2, ENC_BIG_ENDIAN);
proto_tree_add_item(tlv_tree, hf_sbc_ss_demodulator_mimo_4_ann_stc_matrix_c_horizontal, tvb, offset, 2, ENC_BIG_ENDIAN);
proto_tree_add_item(tlv_tree, hf_sbc_ss_demodulator_mimo_rsvd, tvb, offset, 2, ENC_BIG_ENDIAN);
break;
case SBC_SS_MIMO_UPLINK_SUPPORT:
tlv_tree = add_tlv_subtree(&tlv_info, ett_sbc_rsp_tlv_subtree, sbc_tree, hf_sbc_ss_mimo_uplink_support, tvb, offset, tlv_len, FALSE);
proto_tree_add_item(tlv_tree, hf_sbc_ss_mimo_uplink_support_2_ann_sttd, tvb, offset, 1, ENC_BIG_ENDIAN);
proto_tree_add_item(tlv_tree, hf_sbc_ss_mimo_uplink_support_2_ann_sm_vertical, tvb, offset, 1, ENC_BIG_ENDIAN);
proto_tree_add_item(tlv_tree, hf_sbc_ss_mimo_uplink_support_1_ann_coop_sm, tvb, offset, 1, ENC_BIG_ENDIAN);
proto_tree_add_item(tlv_tree, hf_sbc_ss_mimo_uplink_support_rsvd, tvb, offset, 1, ENC_BIG_ENDIAN);
break;
case SBC_SS_OFDMA_AAS_PRIVATE_MAP_SUPPORT:
tlv_tree = add_tlv_subtree(&tlv_info, ett_sbc_rsp_tlv_subtree, sbc_tree, hf_sbc_ss_ofdma_aas_private, tvb, offset, tlv_len, FALSE);
proto_tree_add_item(tlv_tree, hf_sbc_ofdma_aas_harq_map_capability, tvb, offset, 1, ENC_BIG_ENDIAN);
proto_tree_add_item(tlv_tree, hf_sbc_ofdma_aas_private_map_support, tvb, offset, 1, ENC_BIG_ENDIAN);
proto_tree_add_item(tlv_tree, hf_sbc_ofdma_aas_reduced_private_map_support, tvb, offset, 1, ENC_BIG_ENDIAN);
proto_tree_add_item(tlv_tree, hf_sbc_ofdma_aas_private_chain_enable, tvb, offset, 1, ENC_BIG_ENDIAN);
proto_tree_add_item(tlv_tree, hf_sbc_ofdma_aas_private_map_dl_frame_offset, tvb, offset, 1, ENC_BIG_ENDIAN);
proto_tree_add_item(tlv_tree, hf_sbc_ofdma_aas_private_ul_frame_offset, tvb, offset, 1, ENC_BIG_ENDIAN);
proto_tree_add_item(tlv_tree, hf_sbc_ofdma_aas_private_map_concurrency, tvb, offset, 1, ENC_BIG_ENDIAN);
break;
case SBC_SS_OFDMA_AAS_CAPABILITIES:
tlv_tree = add_tlv_subtree(&tlv_info, ett_sbc_rsp_tlv_subtree, sbc_tree, hf_sbc_ofdma_aas_capabilities, tvb, offset, tlv_len, FALSE);
proto_tree_add_item(tlv_tree, hf_sbc_ss_ofdma_aas_zone, tvb, offset, 2, ENC_BIG_ENDIAN);
proto_tree_add_item(tlv_tree, hf_sbc_ss_ofdma_aas_diversity_map_scan, tvb, offset, 2, ENC_BIG_ENDIAN);
proto_tree_add_item(tlv_tree, hf_sbc_ss_ofdma_aas_fbck_rsp_support, tvb, offset, 2, ENC_BIG_ENDIAN);
proto_tree_add_item(tlv_tree, hf_sbc_ss_ofdma_downlink_aas_preamble, tvb, offset, 2, ENC_BIG_ENDIAN);
proto_tree_add_item(tlv_tree, hf_sbc_ss_ofdma_uplink_aas_preamble, tvb, offset, 2, ENC_BIG_ENDIAN);
proto_tree_add_item(tlv_tree, hf_sbc_ss_ofdma_aas_capabilities_rsvd, tvb, offset, 2, ENC_BIG_ENDIAN);
break;
case SBC_SS_CINR_MEASUREMENT_CAPABILITY:
tlv_tree = add_tlv_subtree(&tlv_info, ett_sbc_rsp_tlv_subtree, sbc_tree, hf_sbc_ss_cinr_measure_capability, tvb, offset, tlv_len, FALSE);
proto_tree_add_item(tlv_tree, hf_sbc_ss_phy_cinr_measurement_preamble, tvb, offset, 1, ENC_BIG_ENDIAN);
proto_tree_add_item(tlv_tree, hf_sbc_ss_phy_cinr_measurement_permutation_zone_from_pilot_subcarriers, tvb, offset, 1, ENC_BIG_ENDIAN);
proto_tree_add_item(tlv_tree, hf_sbc_ss_phy_cinr_measurement_permutation_zone_from_data_subcarriers, tvb, offset, 1, ENC_BIG_ENDIAN);
proto_tree_add_item(tlv_tree, hf_sbc_ss_effective_cinr_measurement_preamble, tvb, offset, 1, ENC_BIG_ENDIAN);
proto_tree_add_item(tlv_tree, hf_sbc_ss_effective_cinr_measurement_permutation_zone_from_pilot_subcarriers, tvb, offset, 1, ENC_BIG_ENDIAN);
proto_tree_add_item(tlv_tree, hf_sbc_ss_effective_cinr_measurement_permutation_zone_from_data_subcarriers, tvb, offset, 1, ENC_BIG_ENDIAN);
proto_tree_add_item(tlv_tree, hf_sbc_ss_support_2_concurrent_cqi_channels,tvb,offset, 1, ENC_BIG_ENDIAN);
proto_tree_add_item(tlv_tree, hf_sbc_ss_frequency_selectivity_characterization_report,tvb,offset, 1, ENC_BIG_ENDIAN);
break;
case SBC_PKM_FLOW_CONTROL:
tlv_tree = add_tlv_subtree(&tlv_info, ett_sbc_rsp_tlv_subtree, sbc_tree, hf_sbc_pkm_flow_control, tvb, offset, tlv_len, FALSE);
tlv_item = proto_tree_add_item(tlv_tree, hf_sbc_pkm_flow_control, tvb, offset, tlv_len, ENC_BIG_ENDIAN);
if (tvb_get_guint8(tvb, offset) == 0)
{
proto_item_append_text(tlv_item, " (default - no limit)");
}
break;
case SBC_AUTH_POLICY_SUPPORT:
tlv_tree = add_tlv_subtree(&tlv_info, ett_sbc_rsp_tlv_subtree, sbc_tree, hf_sbc_auth_policy, tvb, offset, tlv_len, FALSE);
proto_tree_add_item(tlv_tree, hf_sbc_privacy_802_16, tvb, offset, 1, ENC_BIG_ENDIAN);
proto_tree_add_item(tlv_tree, hf_sbc_privacy_rsvd, tvb, offset, 1, ENC_BIG_ENDIAN);
break;
case SBC_MAX_SECURITY_ASSOCIATIONS:
tlv_tree = add_tlv_subtree(&tlv_info, ett_sbc_rsp_tlv_subtree, sbc_tree, hf_sbc_max_security_associations, tvb, offset, tlv_len, FALSE);
proto_tree_add_item(tlv_tree, hf_sbc_max_security_associations, tvb, offset, tlv_len, ENC_BIG_ENDIAN);
break;
case SBC_TLV_T_27_EXTENSION_CAPABILITY:
tlv_tree = add_tlv_subtree(&tlv_info, ett_sbc_rsp_tlv_subtree, sbc_tree, hf_sbc_tlv_t_27_extension_capability, tvb, offset, tlv_len, FALSE);
proto_tree_add_item(tlv_tree, hf_sbc_tlv_t_27_extension_capability_bit0, tvb, offset, 1, ENC_BIG_ENDIAN);
proto_tree_add_item(tlv_tree, hf_sbc_tlv_t_27_extension_capability_reserved, tvb, offset, 1, ENC_BIG_ENDIAN);
break;
case SBC_TLV_T_28_HO_TRIGGER_METRIC_SUPPORT:
tlv_tree = add_tlv_subtree(&tlv_info, ett_sbc_rsp_tlv_subtree, sbc_tree, hf_sbc_tlv_t_28_ho_trigger_metric_support, tvb, offset, tlv_len, FALSE);
proto_tree_add_item(tlv_tree, hf_sbc_tlv_t_28_ho_trigger_metric_support_bit0, tvb, offset, 1, ENC_BIG_ENDIAN);
proto_tree_add_item(tlv_tree, hf_sbc_tlv_t_28_ho_trigger_metric_support_bit1, tvb, offset, 1, ENC_BIG_ENDIAN);
proto_tree_add_item(tlv_tree, hf_sbc_tlv_t_28_ho_trigger_metric_support_bit2, tvb, offset, 1, ENC_BIG_ENDIAN);
proto_tree_add_item(tlv_tree, hf_sbc_tlv_t_28_ho_trigger_metric_support_bit3, tvb, offset, 1, ENC_BIG_ENDIAN);
proto_tree_add_item(tlv_tree, hf_sbc_tlv_t_28_ho_trigger_metric_support_reserved, tvb, offset, 1, ENC_BIG_ENDIAN);
break;
case SBC_TLV_T_167_ASSOCIATION_SUPPORT:
tlv_tree = add_tlv_subtree(&tlv_info, ett_sbc_rsp_tlv_subtree, sbc_tree, hf_sbc_tlv_t_167_association_type_support, tvb, offset, tlv_len, FALSE);
proto_tree_add_item(tlv_tree, hf_sbc_tlv_t_167_association_type_support_bit0, tvb, offset, 1, ENC_BIG_ENDIAN);
proto_tree_add_item(tlv_tree, hf_sbc_tlv_t_167_association_type_support_bit1, tvb, offset, 1, ENC_BIG_ENDIAN);
proto_tree_add_item(tlv_tree, hf_sbc_tlv_t_167_association_type_support_bit2, tvb, offset, 1, ENC_BIG_ENDIAN);
proto_tree_add_item(tlv_tree, hf_sbc_tlv_t_167_association_type_support_bit3, tvb, offset, 1, ENC_BIG_ENDIAN);
proto_tree_add_item(tlv_tree, hf_sbc_tlv_t_167_association_type_support_bit4, tvb, offset, 1, ENC_BIG_ENDIAN);
proto_tree_add_item(tlv_tree, hf_sbc_tlv_t_167_association_type_support_reserved, tvb, offset, 1, ENC_BIG_ENDIAN);
break;
case SBC_TLV_T_170_UPLINK_POWER_CONTROL_SUPPORT:
tlv_tree = add_tlv_subtree(&tlv_info, ett_sbc_rsp_tlv_subtree, sbc_tree, hf_sbc_ofdma_ss_uplink_power_control_support, tvb, offset, tlv_len, FALSE);
proto_tree_add_item(tlv_tree, hf_sbc_ofdma_ss_uplink_power_control_support_open_loop, tvb, offset, 1, ENC_BIG_ENDIAN);
proto_tree_add_item(tlv_tree, hf_sbc_ofdma_ss_uplink_power_control_support_aas_preamble, tvb, offset, 1, ENC_BIG_ENDIAN);
proto_tree_add_item(tlv_tree, hf_sbc_ofdma_ss_uplink_power_control_support_rsvd, tvb, offset, 1, ENC_BIG_ENDIAN);
break;
case SBC_TLV_T_171_MINIMUM_NUM_OF_FRAMES:
tlv_tree = add_tlv_subtree(&tlv_info, ett_sbc_rsp_tlv_subtree, sbc_tree, hf_sbc_tlv_t_171_minimum_num_of_frames, tvb, offset, tlv_len, FALSE);
proto_tree_add_item(tlv_tree, hf_sbc_tlv_t_171_minimum_num_of_frames, tvb, offset, tlv_len, ENC_BIG_ENDIAN);
break;
case SBC_TLV_T_172:
tlv_tree = add_tlv_subtree(&tlv_info, ett_sbc_rsp_tlv_subtree, sbc_tree, hf_sbc_tlv_t_172, tvb, offset, tlv_len, FALSE);
proto_tree_add_item(tlv_tree, hf_sbc_tlv_t_172_harq_map_capability, tvb, offset, 1, ENC_BIG_ENDIAN);
proto_tree_add_item(tlv_tree, hf_sbc_tlv_t_172_extended_harq_ie_capability, tvb, offset, 1, ENC_BIG_ENDIAN);
proto_tree_add_item(tlv_tree, hf_sbc_tlv_t_172_sub_map_capability_first_zone, tvb, offset, 1, ENC_BIG_ENDIAN);
proto_tree_add_item(tlv_tree, hf_sbc_tlv_t_172_sub_map_capability_other_zones, tvb, offset, 1, ENC_BIG_ENDIAN);
proto_tree_add_item(tlv_tree, hf_sbc_tlv_t_172_dl_region_definition_support, tvb, offset, 1, ENC_BIG_ENDIAN);
proto_tree_add_item(tlv_tree, hf_sbc_tlv_t_172_reserved, tvb, offset, 1, ENC_BIG_ENDIAN);
break;
case SBC_TLV_T_173_UL_CONTROL_CHANNEL_SUPPORT:
tlv_tree = add_tlv_subtree(&tlv_info, ett_sbc_rsp_tlv_subtree, sbc_tree, hf_sbc_tlv_t_173_ul_ctl_channel_support, tvb, offset, tlv_len, FALSE);
proto_tree_add_item(tlv_tree, hf_sbc_tlv_t_173_3_bit_mimo_fast_feedback, tvb, offset, 1, ENC_BIG_ENDIAN);
proto_tree_add_item(tlv_tree, hf_sbc_tlv_t_173_enhanced_fast_feedback, tvb, offset, 1, ENC_BIG_ENDIAN);
proto_tree_add_item(tlv_tree, hf_sbc_tlv_t_173_ul_ack, tvb, offset, 1, ENC_BIG_ENDIAN);
proto_tree_add_item(tlv_tree, hf_sbc_tlv_t_173_reserved, tvb, offset, 1, ENC_BIG_ENDIAN);
proto_tree_add_item(tlv_tree, hf_sbc_tlv_t_173_uep_fast_feedback, tvb, offset, 1, ENC_BIG_ENDIAN);
proto_tree_add_item(tlv_tree, hf_sbc_tlv_t_173_measurement_report, tvb, offset, 1, ENC_BIG_ENDIAN);
proto_tree_add_item(tlv_tree, hf_sbc_tlv_t_173_primary_secondary_fast_feedback, tvb, offset, 1, ENC_BIG_ENDIAN);
proto_tree_add_item(tlv_tree, hf_sbc_tlv_t_173_diuc_cqi_fast_feedback, tvb, offset, 1, ENC_BIG_ENDIAN);
break;
case SBC_TLV_T_174_OFDMA_MS_CSIT_CAPABILITY:
tlv_tree = add_tlv_subtree(&tlv_info, ett_sbc_rsp_tlv_subtree, sbc_tree, hf_sbc_tlv_t_174_ofdma_ms_csit_capability, tvb, offset, tlv_len, FALSE);
proto_tree_add_item(tlv_tree, hf_sbc_tlv_t_174_csit_compatibility_type_a, tvb, offset, 2, ENC_BIG_ENDIAN);
proto_tree_add_item(tlv_tree, hf_sbc_tlv_t_174_csit_compatibility_type_b, tvb, offset, 2, ENC_BIG_ENDIAN);
proto_tree_add_item(tlv_tree, hf_sbc_tlv_t_174_power_assignment_capability, tvb, offset, 2, ENC_BIG_ENDIAN);
proto_tree_add_item(tlv_tree, hf_sbc_tlv_t_174_sounding_rsp_time_capability, tvb, offset, 2, ENC_BIG_ENDIAN);
proto_tree_add_item(tlv_tree, hf_sbc_tlv_t_174_max_num_simultanous_sounding_instructions, tvb, offset, 2, ENC_BIG_ENDIAN);
proto_tree_add_item(tlv_tree, hf_sbc_tlv_t_174_ss_csit_type_a_support, tvb, offset, 2, ENC_BIG_ENDIAN);
proto_tree_add_item(tlv_tree, hf_sbc_tlv_t_174_ss_csit_reserved, tvb, offset, 2, ENC_BIG_ENDIAN);
break;
case SBC_TLV_T_175_MAX_NUM_BST_PER_FRM_CAPABILITY_HARQ:
tlv_tree = add_tlv_subtree(&tlv_info, ett_sbc_rsp_tlv_subtree, sbc_tree, hf_sbc_tlv_t_175_max_num_bst_per_frm_capability_harq, tvb, offset, tlv_len, FALSE);
proto_tree_add_item(tlv_tree, hf_sbc_tlv_t_175_max_num_ul_harq_bst, tvb, offset, 1, ENC_BIG_ENDIAN);
proto_tree_add_item(tlv_tree, hf_sbc_tlv_t_175_max_num_ul_harq_per_frm_include_one_non_harq_bst, tvb, offset, 1, ENC_BIG_ENDIAN);
proto_tree_add_item(tlv_tree, hf_sbc_tlv_t_175_max_num_dl_harq_bst_per_harq_per_frm, tvb, offset, 1, ENC_BIG_ENDIAN);
break;
case SBC_TLV_T_176:
tlv_tree = add_tlv_subtree(&tlv_info, ett_sbc_rsp_tlv_subtree, sbc_tree, hf_sbc_tlv_t_176, tvb, offset, tlv_len, FALSE);
proto_tree_add_item(tlv_tree, hf_sbc_tlv_t_176_bit0, tvb, offset, 3, ENC_BIG_ENDIAN);
proto_tree_add_item(tlv_tree, hf_sbc_tlv_t_176_bit1, tvb, offset, 3, ENC_BIG_ENDIAN);
if (include_cor2_changes)
proto_tree_add_item(tlv_tree, hf_sbc_tlv_t_176_bit2_cor2, tvb, offset, 3, ENC_BIG_ENDIAN);
else
proto_tree_add_item(tlv_tree, hf_sbc_tlv_t_176_bit2, tvb, offset, 3, ENC_BIG_ENDIAN);
proto_tree_add_item(tlv_tree, hf_sbc_tlv_t_176_bit3, tvb, offset, 3, ENC_BIG_ENDIAN);
proto_tree_add_item(tlv_tree, hf_sbc_tlv_t_176_bit4, tvb, offset, 3, ENC_BIG_ENDIAN);
proto_tree_add_item(tlv_tree, hf_sbc_tlv_t_176_bit5, tvb, offset, 3, ENC_BIG_ENDIAN);
proto_tree_add_item(tlv_tree, hf_sbc_tlv_t_176_bit6, tvb, offset, 3, ENC_BIG_ENDIAN);
proto_tree_add_item(tlv_tree, hf_sbc_tlv_t_176_bit7, tvb, offset, 3, ENC_BIG_ENDIAN);
proto_tree_add_item(tlv_tree, hf_sbc_tlv_t_176_bit8, tvb, offset, 3, ENC_BIG_ENDIAN);
proto_tree_add_item(tlv_tree, hf_sbc_tlv_t_176_bit9, tvb, offset, 3, ENC_BIG_ENDIAN);
proto_tree_add_item(tlv_tree, hf_sbc_tlv_t_176_bit10, tvb, offset, 3, ENC_BIG_ENDIAN);
proto_tree_add_item(tlv_tree, hf_sbc_tlv_t_176_bit11, tvb, offset, 3, ENC_BIG_ENDIAN);
proto_tree_add_item(tlv_tree, hf_sbc_tlv_t_176_bit12, tvb, offset, 3, ENC_BIG_ENDIAN);
proto_tree_add_item(tlv_tree, hf_sbc_tlv_t_176_bit13, tvb, offset, 3, ENC_BIG_ENDIAN);
proto_tree_add_item(tlv_tree, hf_sbc_tlv_t_176_bit14, tvb, offset, 3, ENC_BIG_ENDIAN);
proto_tree_add_item(tlv_tree, hf_sbc_tlv_t_176_bit15, tvb, offset, 3, ENC_BIG_ENDIAN);
proto_tree_add_item(tlv_tree, hf_sbc_tlv_t_176_bit16, tvb, offset, 3, ENC_BIG_ENDIAN);
proto_tree_add_item(tlv_tree, hf_sbc_tlv_t_176_bit17, tvb, offset, 3, ENC_BIG_ENDIAN);
proto_tree_add_item(tlv_tree, hf_sbc_tlv_t_176_bit18, tvb, offset, 3, ENC_BIG_ENDIAN);
proto_tree_add_item(tlv_tree, hf_sbc_tlv_t_176_bit19, tvb, offset, 3, ENC_BIG_ENDIAN);
proto_tree_add_item(tlv_tree, hf_sbc_tlv_t_176_reserved, tvb, offset, 3, ENC_BIG_ENDIAN);
break;
case SBC_TLV_T_177_OFDMA_SS_MODULATOR_FOR_MIMO_SUPPORT:
tlv_tree = add_tlv_subtree(&tlv_info, ett_sbc_rsp_tlv_subtree, sbc_tree, hf_sbc_tlv_t_177_ofdma_ss_modulator_for_mimo_support, tvb, offset, tlv_len, FALSE);
if (include_cor2_changes)
{
proto_tree_add_item(tlv_tree, hf_sbc_tlv_t_177_stc_matrix_a, tvb, offset, 1, ENC_BIG_ENDIAN);
proto_tree_add_item(tlv_tree, hf_sbc_tlv_t_177_stc_matrix_b_vertical, tvb, offset, 1, ENC_BIG_ENDIAN);
proto_tree_add_item(tlv_tree, hf_sbc_tlv_t_177_stc_matrix_b_horizontal, tvb, offset, 1, ENC_BIG_ENDIAN);
} else {
proto_tree_add_item(tlv_tree, hf_sbc_tlv_t_177_two_transmit_antennas, tvb, offset, 1, ENC_BIG_ENDIAN);
proto_tree_add_item(tlv_tree, hf_sbc_tlv_t_177_capable_of_transmit_diversity, tvb, offset, 1, ENC_BIG_ENDIAN);
proto_tree_add_item(tlv_tree, hf_sbc_tlv_t_177_capable_of_spacial_multiplexing, tvb, offset, 1, ENC_BIG_ENDIAN);
}
proto_tree_add_item(tlv_tree, hf_sbc_tlv_t_177_beamforming, tvb, offset, 1, ENC_BIG_ENDIAN);
proto_tree_add_item(tlv_tree, hf_sbc_tlv_t_177_adaptive_rate_ctl, tvb, offset, 1, ENC_BIG_ENDIAN);
proto_tree_add_item(tlv_tree, hf_sbc_tlv_t_177_single_antenna, tvb, offset, 1, ENC_BIG_ENDIAN);
if (include_cor2_changes)
{
proto_tree_add_item(tlv_tree, hf_sbc_tlv_t_177_collaborative_sm_with_one_antenna, tvb, offset, 1, ENC_BIG_ENDIAN);
proto_tree_add_item(tlv_tree, hf_sbc_tlv_t_177_collaborative_sm_with_two_antennas, tvb, offset, 1, ENC_BIG_ENDIAN);
} else {
proto_tree_add_item(tlv_tree, hf_sbc_tlv_t_177_capable_of_two_antenna, tvb, offset, 1, ENC_BIG_ENDIAN);
proto_tree_add_item(tlv_tree, hf_sbc_tlv_t_177_rsvd, tvb, offset, 1, ENC_BIG_ENDIAN);
}
break;
case SBC_TLV_T_178_SDMA_PILOT_CAPABILITY:
tlv_tree = add_tlv_subtree(&tlv_info, ett_sbc_rsp_tlv_subtree, sbc_tree, hf_sbc_tlv_t_178_sdma_pilot_capability, tvb, offset, tlv_len, FALSE);
proto_tree_add_item(tlv_tree, hf_sbc_tlv_t_178_sdma_pilot_pattern_support_for_amc_zone, tvb, offset, 1, ENC_BIG_ENDIAN);
proto_tree_add_item(tlv_tree, hf_sbc_tlv_t_178_reserved, tvb, offset, 1, ENC_BIG_ENDIAN);
break;
case SBC_TLV_T_179_OFDMA_MULTIPLE_DL_BURST_PROFILE_CAPABILITY:
tlv_tree = add_tlv_subtree(&tlv_info, ett_sbc_rsp_tlv_subtree, sbc_tree, hf_sbc_tlv_t_179_ofdma_multiple_dl_burst_profile_support, tvb, offset, tlv_len, FALSE);
proto_tree_add_item(tlv_tree, hf_sbc_tlv_t_179_dl_bst_profile_for_multiple_fec, tvb, offset, 1, ENC_BIG_ENDIAN);
proto_tree_add_item(tlv_tree, hf_sbc_tlv_t_179_ul_bst_profile_for_multiple_fec, tvb, offset, 1, ENC_BIG_ENDIAN);
proto_tree_add_item(tlv_tree, hf_sbc_tlv_t_179_reserved, tvb, offset, 1, ENC_BIG_ENDIAN);
break;
case SBC_TLV_T_204_OFDMA_PARAMETERS_SETS:
if (include_cor2_changes)
{
tlv_tree = add_tlv_subtree(&tlv_info, ett_sbc_rsp_tlv_subtree, sbc_tree, hf_sbc_tlv_t_204_ofdma_parameters_sets, tvb, offset, tlv_len, FALSE);
proto_tree_add_item(tlv_tree, hf_sbc_tlv_t_204_ofdma_parameters_sets_phy_set_a, tvb, offset, 1, ENC_BIG_ENDIAN);
proto_tree_add_item(tlv_tree, hf_sbc_tlv_t_204_ofdma_parameters_sets_phy_set_b, tvb, offset, 1, ENC_BIG_ENDIAN);
proto_tree_add_item(tlv_tree, hf_sbc_tlv_t_204_ofdma_parameters_sets_harq_parameters_set, tvb, offset, 1, ENC_BIG_ENDIAN);
proto_tree_add_item(tlv_tree, hf_sbc_tlv_t_204_ofdma_parameters_sets_mac_set_a, tvb, offset, 1, ENC_BIG_ENDIAN);
proto_tree_add_item(tlv_tree, hf_sbc_tlv_t_204_ofdma_parameters_sets_mac_set_b, tvb, offset, 1, ENC_BIG_ENDIAN);
proto_tree_add_item(tlv_tree, hf_sbc_tlv_t_204_ofdma_parameters_sets_reserved, tvb, offset, 1, ENC_BIG_ENDIAN);
}
break;
case SBC_TLV_T_162_HARQ_INCREMENTAL_REDUNDANCY_BUFFER_CAPABILITY:
tlv_tree = add_tlv_subtree(&tlv_info, ett_sbc_rsp_tlv_subtree, sbc_tree, hf_sbc_tlv_t_162_harq_incremental_redundancy_buffer_capability, tvb, offset, tlv_len, FALSE);
proto_tree_add_item(tlv_tree, hf_sbc_tlv_t_162_harq_incremental_redundancy_buffer_capability_NEP, tvb, offset, 2, ENC_BIG_ENDIAN);
proto_tree_add_item(tlv_tree, hf_sbc_tlv_t_162_harq_incremental_redundancy_buffer_capability_aggregation_flag_for_dl, tvb, offset, 2, ENC_BIG_ENDIAN);
proto_tree_add_item(tlv_tree, hf_sbc_tlv_t_162_harq_incremental_redundancy_buffer_capability_reserved1, tvb, offset, 2, ENC_BIG_ENDIAN);
proto_tree_add_item(tlv_tree, hf_sbc_tlv_t_162_ul_harq_incremental_redundancy_buffer_capability_NEP, tvb, offset, 2, ENC_BIG_ENDIAN);
proto_tree_add_item(tlv_tree, hf_sbc_tlv_t_162_harq_incremental_redundancy_buffer_capability_aggregation_flag_for_ul, tvb, offset, 2, ENC_BIG_ENDIAN);
proto_tree_add_item(tlv_tree, hf_sbc_tlv_t_162_harq_incremental_redundancy_buffer_capability_reserved2, tvb, offset, 2, ENC_BIG_ENDIAN);
break;
case SBC_TLV_T_163_HARQ_CHASE_COMBINING_AND_CC_IR_BUFFER_CAPABILITY:
tlv_tree = add_tlv_subtree(&tlv_info, ett_sbc_rsp_tlv_subtree, sbc_tree, hf_sbc_tlv_t_163_harq_chase_combining_and_cc_ir_buffer_capability, tvb, offset, tlv_len, FALSE);
proto_tree_add_item(tlv_tree, hf_sbc_tlv_t_163_dl_harq_buffering_capability_for_chase_combining, tvb, offset, 2, ENC_BIG_ENDIAN);
proto_tree_add_item(tlv_tree, hf_sbc_tlv_t_163_harq_chase_combining_and_cc_ir_buffer_capability_aggregation_flag_dl, tvb, offset, 2, ENC_BIG_ENDIAN);
proto_tree_add_item(tlv_tree, hf_sbc_tlv_t_163_harq_chase_combining_and_cc_ir_buffer_capability_reserved1, tvb, offset, 2, ENC_BIG_ENDIAN);
proto_tree_add_item(tlv_tree, hf_sbc_tlv_t_163_ul_harq_buffering_capability_for_chase_combining, tvb, offset, 2, ENC_BIG_ENDIAN);
proto_tree_add_item(tlv_tree, hf_sbc_tlv_t_163_harq_chase_combining_and_cc_ir_buffer_capability_aggregation_flag_ul, tvb, offset, 2, ENC_BIG_ENDIAN);
proto_tree_add_item(tlv_tree, hf_sbc_tlv_t_163_harq_chase_combining_and_cc_ir_buffer_capability_reserved2, tvb, offset, 2, ENC_BIG_ENDIAN);
break;
case PKM_ATTR_SECURITY_NEGOTIATION_PARAMETERS:
tlv_item = proto_tree_add_protocol_format(sbc_tree, proto_mac_mgmt_msg_sbc_decoder, tvb, offset, tvb_len, "Security Negotiation Parameters (%u bytes)", tvb_len);
tlv_tree = proto_item_add_subtree(tlv_item, ett_sbc_rsp_tlv_subtree);
wimax_security_negotiation_parameters_decoder(tvb_new_subset(tvb, offset, tlv_len, tlv_len), pinfo, tlv_tree);
break;
case SBC_TLV_T_26_POWER_SAVE_CLASS_TYPES_CAPABILITY:
tlv_tree = add_tlv_subtree(&tlv_info, ett_sbc_rsp_tlv_subtree, sbc_tree, hf_sbc_power_save_class_types_capability, tvb, offset, tlv_len, FALSE);
proto_tree_add_item(tlv_tree, hf_sbc_power_save_class_types_capability_bit0, tvb, offset, 1, ENC_BIG_ENDIAN);
proto_tree_add_item(tlv_tree, hf_sbc_power_save_class_types_capability_bit1, tvb, offset, 1, ENC_BIG_ENDIAN);
proto_tree_add_item(tlv_tree, hf_sbc_power_save_class_types_capability_bit2, tvb, offset, 1, ENC_BIG_ENDIAN);
proto_tree_add_item(tlv_tree, hf_sbc_power_save_class_types_capability_bits34, tvb, offset, 1, ENC_BIG_ENDIAN);
proto_tree_add_item(tlv_tree, hf_sbc_power_save_class_types_capability_bits567, tvb, offset, 1, ENC_BIG_ENDIAN);
break;
default:
tlv_tree = add_tlv_subtree(&tlv_info, ett_sbc_rsp_tlv_subtree, sbc_tree, hf_sbc_unknown_type, tvb, offset, tlv_len, FALSE);
proto_tree_add_item(tlv_tree, hf_sbc_unknown_type, tvb, offset, tlv_len, ENC_NA);
break;
}
offset += tlv_len;
}
}
}
void proto_register_mac_mgmt_msg_sbc(void)
{
static hf_register_info hf_sbc[] =
{
{
&hf_sbc_tlv_t_167_association_type_support,
{
"Association Type Support", "wmx.sbc.association_type_support",
FT_UINT8, BASE_HEX, NULL, 0x0, NULL, HFILL
}
},
{
&hf_sbc_tlv_t_167_association_type_support_bit0,
{
"Scanning Without Association: association not supported", "wmx.sbc.association_type_support.bit0",
FT_BOOLEAN, 8, TFS(&tfs_yes_no_sbc), 0x1, NULL, HFILL
}
},
{
&hf_sbc_tlv_t_167_association_type_support_bit1,
{
"Association Level 0: scanning or association without coordination", "wmx.sbc.association_type_support.bit1",
FT_BOOLEAN, 8, TFS(&tfs_yes_no_sbc), 0x2, NULL, HFILL
}
},
{
&hf_sbc_tlv_t_167_association_type_support_bit2,
{
"Association Level 1: association with coordination", "wmx.sbc.association_type_support.bit2",
FT_BOOLEAN, 8, TFS(&tfs_yes_no_sbc), 0x4, NULL, HFILL
}
},
{
&hf_sbc_tlv_t_167_association_type_support_bit3,
{
"Association Level 2: network assisted association", "wmx.sbc.association_type_support.bit3",
FT_BOOLEAN, 8, TFS(&tfs_yes_no_sbc), 0x8, NULL, HFILL
}
},
{
&hf_sbc_tlv_t_167_association_type_support_bit4,
{
"Desired Association Support", "wmx.sbc.association_type_support.bit4",
FT_BOOLEAN, 8, TFS(&tfs_yes_no_sbc), 0x10, NULL, HFILL
}
},
{
&hf_sbc_tlv_t_167_association_type_support_reserved,
{
"Reserved", "wmx.sbc.association_type_support.reserved",
FT_UINT8, BASE_HEX, NULL, 0xE0, NULL, HFILL
}
},
{
&hf_sbc_auth_policy,
{
"Authorization Policy Support", "wmx.sbc.auth_policy",
FT_UINT8, BASE_HEX, NULL, 0x0, NULL, HFILL
}
},
{
&hf_sbc_privacy_802_16,
{
"IEEE 802.16 Privacy", "wmx.sbc.auth_policy.802_16",
FT_BOOLEAN, 8, TFS(&tfs_supported), 0x1, NULL, HFILL
}
},
{
&hf_sbc_privacy_rsvd,
{
"Reserved", "wmx.sbc.auth_policy.rsvd",
FT_UINT8, BASE_HEX, NULL, 0xFE, NULL, HFILL
}
},
{
&hf_sbc_bw_alloc_support,
{
"Bandwidth Allocation Support", "wmx.sbc.bw_alloc_support",
FT_UINT8, BASE_HEX, NULL, 0x00, NULL, HFILL
}
},
{
&hf_sbc_bw_alloc_support_duplex,
{
"Duplex", "wmx.sbc.bw_alloc_support.duplex",
FT_BOOLEAN, 8, TFS(&tfs_sbc_bw_alloc_support_duplex), 0x2, NULL, HFILL
}
},
{
&hf_sbc_bw_alloc_support_rsvd0,
{
"Reserved", "wmx.sbc.bw_alloc_support.rsvd0",
FT_UINT8, BASE_HEX, NULL, 0x1, NULL, HFILL
}
},
{
&hf_sbc_bw_alloc_support_rsvd1,
{
"Reserved", "wmx.sbc.bw_alloc_support.rsvd1",
FT_UINT8, BASE_HEX, NULL, 0xFC, NULL, HFILL
}
},
{
&hf_sbc_curr_transmit_power,
{
"Current transmitted power", "wmx.sbc.curr_transmit_power",
FT_UINT8, BASE_HEX, NULL, 0x00, NULL, HFILL
}
},
{
&hf_sbc_ss_effective_cinr_measurement_preamble,
{
"Effective CINR Measurement For A Permutation Zone From Preamble", "wmx.sbc.effective_cinr_measure_permutation_zone_preamble",
FT_BOOLEAN, 8, TFS(&tfs_supported), 0x8, NULL, HFILL
}
},
{
&hf_sbc_ss_effective_cinr_measurement_permutation_zone_from_pilot_subcarriers,
{
"Effective CINR Measurement For A Permutation Zone From Pilot Subcarriers", "wmx.sbc.effective_cinr_measure_permutation_zone.pilot_subcarriers",
FT_BOOLEAN, 8, TFS(&tfs_supported), 0x10, NULL, HFILL
}
},
{
&hf_sbc_ss_effective_cinr_measurement_permutation_zone_from_data_subcarriers,
{
"Effective CINR Measurement For A Permutation Zone From Data Subcarriers", "wmx.sbc.effective_cinr_measure_permutation_zone.data_subcarriers",
FT_BOOLEAN, 8, TFS(&tfs_supported), 0x20, NULL, HFILL
}
},
{
&hf_sbc_tlv_t_27_extension_capability,
{
"Extension Capability", "wmx.sbc.extension_capability",
FT_UINT8, BASE_HEX, NULL, 0x0, NULL, HFILL
}
},
{
&hf_sbc_tlv_t_27_extension_capability_bit0,
{
"Supported Extended Subheader Format", "wmx.sbc.extension_capability.bit0",
FT_BOOLEAN, 8, TFS(&tfs_yes_no_sbc), 0x1, NULL, HFILL
}
},
{
&hf_sbc_tlv_t_27_extension_capability_reserved,
{
"Reserved", "wmx.sbc.extension_capability.reserved",
FT_UINT8, BASE_HEX, NULL, 0xFE, NULL, HFILL
}
},
{
&hf_sbc_ss_frequency_selectivity_characterization_report,
{
"Frequency Selectivity Characterization Report", "wmx.sbc.frequency_selectivity_characterization_report",
FT_BOOLEAN, 8, TFS(&tfs_supported), 0x80, NULL, HFILL
}
},
{
&hf_sbc_tlv_t_163_harq_chase_combining_and_cc_ir_buffer_capability,
{
"HARQ Chase Combining And CC-IR Buffer Capability", "wmx.sbc.harq_chase_combining_and_cc_ir_buffer_capability",
FT_UINT16, BASE_HEX, NULL, 0x0, NULL, HFILL
}
},
{
&hf_sbc_tlv_t_163_harq_chase_combining_and_cc_ir_buffer_capability_aggregation_flag_dl,
{
"Aggregation Flag For DL", "wmx.sbc.harq_chase_combining_and_cc_ir_buffer_capability.aggregation_flag_dl",
FT_UINT16, BASE_HEX, NULL, 0x40, NULL, HFILL
}
},
{
&hf_sbc_tlv_t_163_harq_chase_combining_and_cc_ir_buffer_capability_aggregation_flag_ul,
{
"Aggregation Flag for UL", "wmx.sbc.harq_chase_combining_and_cc_ir_buffer_capability.aggregation_flag_ul",
FT_UINT16, BASE_HEX, NULL, 0x4000, NULL, HFILL
}
},
{
&hf_sbc_tlv_t_163_dl_harq_buffering_capability_for_chase_combining,
{
"Downlink HARQ Buffering Capability For Chase Combining (K)", "wmx.sbc.harq_chase_combining_and_cc_ir_buffer_capability.dl_harq_buffering_capability_for_chase_combining",
FT_UINT16, BASE_HEX, NULL, 0x3F, NULL, HFILL
}
},
{
&hf_sbc_tlv_t_163_harq_chase_combining_and_cc_ir_buffer_capability_reserved1,
{
"Reserved", "wmx.sbc.harq_chase_combining_and_cc_ir_buffer_capability.reserved1",
FT_UINT16, BASE_HEX, NULL, 0x80, NULL, HFILL
}
},
{
&hf_sbc_tlv_t_163_harq_chase_combining_and_cc_ir_buffer_capability_reserved2,
{
"Reserved", "wmx.sbc.harq_chase_combining_and_cc_ir_buffer_capability.reserved2",
FT_UINT16, BASE_HEX, NULL, 0x8000, NULL, HFILL
}
},
{
&hf_sbc_tlv_t_163_ul_harq_buffering_capability_for_chase_combining,
{
"Uplink HARQ buffering capability for chase combining (K)", "wmx.sbc.harq_chase_combining_and_cc_ir_buffer_capability.ul_harq_buffering_capability_for_chase_combining",
FT_UINT16, BASE_HEX, NULL, 0x3F00, NULL, HFILL
}
},
{
&hf_sbc_tlv_t_162_harq_incremental_redundancy_buffer_capability,
{
"HARQ Incremental Buffer Capability", "wmx.sbc.harq_incremental_redundancy_buffer_capability",
FT_UINT16, BASE_HEX, NULL, 0x0, NULL, HFILL
}
},
{
&hf_sbc_tlv_t_162_harq_incremental_redundancy_buffer_capability_aggregation_flag_for_dl,
{
"Aggregation Flag for DL", "wmx.sbc.harq_incremental_redundancy_buffer_capability.aggregation_flag_for_dl",
FT_UINT16, BASE_HEX, NULL, 0x10, NULL, HFILL
}
},
{
&hf_sbc_tlv_t_162_harq_incremental_redundancy_buffer_capability_aggregation_flag_for_ul,
{
"Aggregation Flag For UL", "wmx.sbc.harq_incremental_redundancy_buffer_capability.aggregation_flag_for_ul",
FT_UINT16, BASE_HEX, NULL, 0x1000, NULL, HFILL
}
},
{
&hf_sbc_tlv_t_162_harq_incremental_redundancy_buffer_capability_NEP,
{
"NEP Value Indicating Downlink HARQ Buffering Capability For Incremental Redundancy CTC", "wmx.sbc.harq_incremental_redundancy_buffer_capability.dl_incremental_redundancy_ctc",
FT_UINT16, BASE_HEX, NULL, 0xF, NULL, HFILL
}
},
{
&hf_sbc_tlv_t_162_harq_incremental_redundancy_buffer_capability_reserved1,
{
"Reserved", "wmx.sbc.harq_incremental_redundancy_buffer_capability.reserved",
FT_UINT16, BASE_HEX, NULL, 0xE0, NULL, HFILL
}
},
{
&hf_sbc_tlv_t_162_harq_incremental_redundancy_buffer_capability_reserved2,
{
"Reserved", "wmx.sbc.harq_incremental_redundancy_buffer_capability.reserved2",
FT_UINT16, BASE_HEX, NULL, 0xE000, NULL, HFILL
}
},
{
&hf_sbc_tlv_t_162_ul_harq_incremental_redundancy_buffer_capability_NEP,
{
"NEP Value Indicating Uplink HARQ Buffering Capability For Incremental Redundancy CTC", "wmx.sbc.harq_incremental_redundancy_buffer_capability.ul_incremental_redundancy_ctc",
FT_UINT16,BASE_HEX, NULL, 0xF00, NULL, HFILL
}
},
{
&hf_sbc_ofdma_aas_harq_map_capability,
{
"H-ARQ MAP Capability", "wmx.sbc.harq_map_capability",
FT_BOOLEAN, 8, TFS(&tfs_supported), 0x1, NULL, HFILL
}
},
{
&hf_sbc_tlv_t_28_ho_trigger_metric_support,
{
"HO Trigger Metric Support", "wmx.sbc.ho_trigger_metric_support",
FT_UINT8, BASE_HEX, NULL, 0x0, NULL, HFILL
}
},
{
&hf_sbc_tlv_t_28_ho_trigger_metric_support_bit0,
{
"BS CINR Mean", "wmx.sbc.ho_trigger_metric_support.bit0",
FT_BOOLEAN, 8, TFS(&tfs_supported), 0x1, NULL, HFILL
}
},
{
&hf_sbc_tlv_t_28_ho_trigger_metric_support_bit1,
{
"BS RSSI Mean", "wmx.sbc.ho_trigger_metric_support.bit1",
FT_BOOLEAN, 8, TFS(&tfs_supported), 0x2, NULL, HFILL
}
},
{
&hf_sbc_tlv_t_28_ho_trigger_metric_support_bit2,
{
"BS Relative Delay", "wmx.sbc.ho_trigger_metric_support.bit2",
FT_BOOLEAN, 8, TFS(&tfs_supported), 0x4, NULL, HFILL
}
},
{
&hf_sbc_tlv_t_28_ho_trigger_metric_support_bit3,
{
"BS RTD", "wmx.sbc.ho_trigger_metric_support.bit3",
FT_BOOLEAN, 8, TFS(&tfs_supported), 0x8, NULL, HFILL
}
},
{
&hf_sbc_tlv_t_28_ho_trigger_metric_support_reserved,
{
"Reserved", "wmx.sbc.ho_trigger_metric_support.reserved",
FT_UINT8, BASE_HEX, NULL, 0xF0, NULL, HFILL
}
},
{
&hf_sbc_invalid_tlv,
{
"Invalid TLV", "wmx.sbc.invalid_tlv",
FT_BYTES, BASE_NONE, NULL, 0x0, NULL, HFILL
}
},
{
&hf_sbc_mac_pdu,
{
"Capabilities For Construction And Transmission Of MAC PDUs", "wmx.sbc.mac_pdu",
FT_UINT8, BASE_HEX, NULL, 0x0, NULL, HFILL
}
},
{
&hf_sbc_mac_pdu_piggybacked,
{
"Ability To Receive Requests Piggybacked With Data", "wmx.sbc.mac_pdu.bit0",
FT_BOOLEAN, 8, TFS(&tfs_supported), 0x1, NULL, HFILL
}
},
{
&hf_sbc_mac_pdu_fsn,
{
"Ability To Use 3-bit FSN Values Used When Forming MAC PDUs On Non-ARQ Connections", "wmx.sbc.mac_pdu.bit1",
FT_BOOLEAN, 8, TFS(&tfs_supported), 0x2, NULL, HFILL
}
},
{
&hf_sbc_tlv_t_175_max_num_bst_per_frm_capability_harq,
{
"Maximum Number Of Burst Per Frame Capability In HARQ", "wmx.sbc.max_num_bst_per_frm_capability_harq",
FT_UINT8, BASE_HEX, NULL, 0x0, NULL, HFILL
}
},
{
&hf_sbc_tlv_t_175_max_num_dl_harq_bst_per_harq_per_frm,
{
"Maximum Numbers Of DL HARQ Bursts Per HARQ Enabled Of MS Per Frame (default(0)=1)", "wmx.sbc.max_num_bst_per_frm_capability_harq.max_num_dl_harq_bst_per_harq_per_frm",
FT_UINT8, BASE_DEC, NULL, 0xF0, NULL, HFILL
}
},
{
&hf_sbc_tlv_t_175_max_num_ul_harq_bst,
{
"Maximum Number Of UL HARQ Burst Per HARQ Enabled MS Per Frame (default(0)=1)", "wmx.sbc.max_num_bst_per_frm_capability_harq.max_num_ul_harq_bst",
FT_UINT8, BASE_DEC, NULL, 0x7, NULL, HFILL
}
},
{
&hf_sbc_tlv_t_175_max_num_ul_harq_per_frm_include_one_non_harq_bst,
{
"Whether The Maximum Number Of UL HARQ Bursts Per Frame (i.e. Bits# 2-0) Includes The One Non-HARQ Burst", "wmx.sbc.max_num_bst_per_frm_capability_harq.max_num_ul_harq_per_frm_include_one_non_harq_bst",
FT_BOOLEAN, 8, TFS(&tfs_yes_no_sbc), 0x8, NULL, HFILL
}
},
{
&hf_sbc_max_security_associations,
{
"Maximum Number Of Security Association Supported By The SS", "wmx.sbc.max_security_associations",
FT_UINT8, BASE_DEC, NULL, 0x0, NULL, HFILL
}
},
{
&hf_sbc_number_dl_arq_ack_channel,
{
"The Number Of DL HARQ ACK Channel", "wmx.sbc.number_dl_arq_ack_channel",
FT_UINT8, BASE_DEC, NULL, 0x0, NULL, HFILL
}
},
{
&hf_sbc_number_ul_arq_ack_channel,
{
"The Number Of UL HARQ ACK Channel", "wmx.sbc.number_ul_arq_ack_channel",
FT_UINT8, BASE_DEC, NULL, 0x0, NULL, HFILL
}
},
{
&hf_sbc_ofdma_aas_capabilities,
{
"OFDMA AAS Capability", "wmx.sbc.ofdma_aas_capability",
FT_UINT16, BASE_HEX, NULL, 0x0, NULL, HFILL
}
},
{
&hf_sbc_ss_ofdma_aas_capabilities_rsvd,
{
"Reserved", "wmx.sbc.ofdma_aas_capabilities.rsvd",
FT_UINT16, BASE_HEX, NULL, 0xFFE0, NULL, HFILL
}
},
{
&hf_sbc_ss_ofdma_aas_diversity_map_scan,
{
"AAS Diversity Map Scan (AAS DLFP)", "wmx.sbc.ofdma_aas_diversity_map_scan",
FT_BOOLEAN, 16, TFS(&tfs_supported), 0x2, NULL, HFILL
}
},
{
&hf_sbc_ss_ofdma_aas_fbck_rsp_support,
{
"AAS-FBCK-RSP Support", "wmx.sbc.ofdma_aas_fbck_rsp_support",
FT_BOOLEAN, 16, TFS(&tfs_supported), 0x4, NULL, HFILL
}
},
{
&hf_sbc_ss_ofdma_aas_zone,
{
"AAS Zone", "wmx.sbc.ofdma_aas_zone",
FT_BOOLEAN, 16, TFS(&tfs_supported), 0x1, NULL, HFILL
}
},
{
&hf_sbc_ss_ofdma_downlink_aas_preamble,
{
"Downlink AAS Preamble", "wmx.sbc.ofdma_downlink_aas_preamble",
FT_BOOLEAN, 16, TFS(&tfs_supported), 0x8, NULL, HFILL
}
},
{
&hf_sbc_tlv_t_176,
{
"OFDMA MS Demodulator For MIMO Support In DL", "wmx.sbc.ofdma_ms_demodulator_for_mimo_support_in_dl",
FT_BOOLEAN, BASE_NONE, TFS(&tfs_supported), 0x0, NULL, HFILL
}
},
{
&hf_sbc_tlv_t_176_bit0,
{
"2-antenna STC Matrix A", "wmx.sbc.ofdma_ms_demodulator_for_mimo_support_in_dl.bit0",
FT_BOOLEAN, 24, TFS(&tfs_supported), 0x1, NULL, HFILL
}
},
{
&hf_sbc_tlv_t_176_bit1,
{
"2-antenna STC Matrix B, vertical coding", "wmx.sbc.ofdma_ms_demodulator_for_mimo_support_in_dl.bit1",
FT_BOOLEAN, 24, TFS(&tfs_supported), 0x2, NULL, HFILL
}
},
{
&hf_sbc_tlv_t_176_bit2,
{
"Four Receive Antennas", "wmx.sbc.ofdma_ms_demodulator_for_mimo_support_in_dl.bit2",
FT_BOOLEAN, 24, TFS(&tfs_supported), 0x4, NULL, HFILL
}
},
{
&hf_sbc_tlv_t_176_bit2_cor2,
{
"2-antenna STC matrix B, horizontal coding", "wmx.sbc.ofdma_ms_demodulator_for_mimo_support_in_dl.bit2",
FT_BOOLEAN, 24, TFS(&tfs_supported), 0x4, NULL, HFILL
}
},
{
&hf_sbc_tlv_t_176_bit3,
{
"4-antenna STC Matrix A", "wmx.sbc.ofdma_ms_demodulator_for_mimo_support_in_dl.bit3",
FT_BOOLEAN, 24, TFS(&tfs_supported), 0x8, NULL, HFILL
}
},
{
&hf_sbc_tlv_t_176_bit4,
{
"4-antenna STC Matrix B, vertical coding", "wmx.sbc.ofdma_ms_demodulator_for_mimo_support_in_dl.bit4",
FT_BOOLEAN, 24, TFS(&tfs_supported), 0x10, NULL, HFILL
}
},
{
&hf_sbc_tlv_t_176_bit5,
{
"4-antenna STC Matrix B, horizontal coding", "wmx.sbc.ofdma_ms_demodulator_for_mimo_support_in_dl.bit5",
FT_BOOLEAN, 24, TFS(&tfs_supported), 0x20, NULL, HFILL
}
},
{
&hf_sbc_tlv_t_176_bit6,
{
"4-antenna STC Matrix C, vertical coding", "wmx.sbc.ofdma_ms_demodulator_for_mimo_support_in_dl.bit6",
FT_BOOLEAN, 24, TFS(&tfs_supported), 0x40, NULL, HFILL
}
},
{
&hf_sbc_tlv_t_176_bit7,
{
"4-antenna STC Matrix C, horizontal coding", "wmx.sbc.ofdma_ms_demodulator_for_mimo_support_in_dl.bit7",
FT_BOOLEAN, 24, TFS(&tfs_supported), 0x80, NULL, HFILL
}
},
{
&hf_sbc_tlv_t_176_bit8,
{
"3-antenna STC Matrix A", "wmx.sbc.ofdma_ms_demodulator_for_mimo_support_in_dl.bit8",
FT_BOOLEAN, 24, TFS(&tfs_supported), 0x100, NULL, HFILL
}
},
{
&hf_sbc_tlv_t_176_bit9,
{
"3-antenna STC Matrix B", "wmx.sbc.ofdma_ms_demodulator_for_mimo_support_in_dl.bit9",
FT_BOOLEAN, 24, TFS(&tfs_supported), 0x200, NULL, HFILL
}
},
{
&hf_sbc_tlv_t_176_bit10,
{
"3-antenna STC Matrix C, vertical coding", "wmx.sbc.ofdma_ms_demodulator_for_mimo_support_in_dl.bit10",
FT_BOOLEAN, 24, TFS(&tfs_supported), 0x400, NULL, HFILL
}
},
{
&hf_sbc_tlv_t_176_bit11,
{
"3-antenna STC Matrix C, horizontal coding", "wmx.sbc.ofdma_ms_demodulator_for_mimo_support_in_dl.bit11",
FT_BOOLEAN, 24, TFS(&tfs_supported), 0x800, NULL, HFILL
}
},
{
&hf_sbc_tlv_t_176_bit12,
{
"Capable Of Calculating Precoding Weight", "wmx.sbc.ofdma_ms_demodulator_for_mimo_support_in_dl.bit12",
FT_BOOLEAN, 24, TFS(&tfs_supported), 0x1000, NULL, HFILL
}
},
{
&hf_sbc_tlv_t_176_bit13,
{
"Capable Of Adaptive Rate Control", "wmx.sbc.ofdma_ms_demodulator_for_mimo_support_in_dl.bit13",
FT_BOOLEAN, 24, TFS(&tfs_supported), 0x2000, NULL, HFILL
}
},
{
&hf_sbc_tlv_t_176_bit14,
{
"Capable Of Calculating Channel Matrix", "wmx.sbc.ofdma_ms_demodulator_for_mimo_support_in_dl.bit14",
FT_BOOLEAN, 24, TFS(&tfs_supported), 0x4000, NULL, HFILL
}
},
{
&hf_sbc_tlv_t_176_bit15,
{
"Capable Of Antenna Grouping", "wmx.sbc.ofdma_ms_demodulator_for_mimo_support_in_dl.bit15",
FT_BOOLEAN, 24, TFS(&tfs_supported), 0x8000, NULL, HFILL
}
},
{
&hf_sbc_tlv_t_176_bit16,
{
"Capable Of Antenna Selection", "wmx.sbc.ofdma_ms_demodulator_for_mimo_support_in_dl.bit16",
FT_BOOLEAN, 24, TFS(&tfs_supported), 0x10000, NULL, HFILL
}
},
{
&hf_sbc_tlv_t_176_bit17,
{
"Capable Of Codebook Based Precoding", "wmx.sbc.ofdma_ms_demodulator_for_mimo_support_in_dl.bit17",
FT_BOOLEAN, 24, TFS(&tfs_supported), 0x20000, NULL, HFILL
}
},
{
&hf_sbc_tlv_t_176_bit18,
{
"Capable Of Long-term Precoding", "wmx.sbc.ofdma_ms_demodulator_for_mimo_support_in_dl.bit18",
FT_BOOLEAN, 24, TFS(&tfs_supported), 0x40000, NULL, HFILL
}
},
{
&hf_sbc_tlv_t_176_bit19,
{
"Capable Of MIMO Midamble", "wmx.sbc.ofdma_ms_demodulator_for_mimo_support_in_dl.bit19",
FT_BOOLEAN, 24, TFS(&tfs_supported), 0x80000, NULL, HFILL
}
},
{
&hf_sbc_tlv_t_176_reserved,
{
"Reserved", "wmx.sbc.ofdma_ms_demodulator_for_mimo_support_in_dl.reserved",
FT_UINT24, BASE_HEX, NULL, 0xF00000, NULL, HFILL
}
},
{
&hf_sbc_tlv_t_179_ofdma_multiple_dl_burst_profile_support,
{
"OFDMA Multiple Downlink Burst Profile Capability", "wmx.sbc.ofdma_multiple_dl_burst_profile_support",
FT_UINT8, BASE_HEX, NULL, 0x0, NULL, HFILL
}
},
{
&hf_sbc_tlv_t_179_dl_bst_profile_for_multiple_fec,
{
"Downlink burst profile for multiple FEC types", "wmx.sbc.ofdma_multiple_dl_burst_profile_support.dl_bst_profile_for_multiple_fec",
FT_BOOLEAN, 8, TFS(&tfs_supported), 0x1, NULL, HFILL
}
},
{
&hf_sbc_tlv_t_179_reserved,
{
"Reserved", "wmx.sbc.ofdma_multiple_dl_burst_profile_support.reserved",
FT_UINT8, BASE_HEX, NULL, 0xFC, NULL, HFILL
}
},
{
&hf_sbc_tlv_t_179_ul_bst_profile_for_multiple_fec,
{
"Uplink burst profile for multiple FEC types", "wmx.sbc.ofdma_multiple_dl_burst_profile_support.ul_burst_profile_for_multiple_fec_types",
FT_BOOLEAN, 8, TFS(&tfs_supported), 0x2, NULL, HFILL
}
},
{
&hf_sbc_ss_cinr_measure_capability,
{
"OFDMA SS CINR Measurement Capability", "wmx.sbc.ofdma_ss_cinr_measure_capability",
FT_UINT8, BASE_HEX, NULL, 0x0, NULL, HFILL
}
},
{
&hf_sbc_ss_mimo_uplink_support,
{
"OFDMA SS MIMO uplink support", "wmx.sbc.ofdma_ss_mimo_uplink_support",
FT_UINT8, BASE_HEX, NULL, 0x00, NULL, HFILL
}
},
{
&hf_sbc_ss_mimo_uplink_support_2_ann_sttd,
{
"2-antenna STTD", "wmx.sbc.ofdma_ss_mimo_uplink_support.2_antenna_sttd",
FT_UINT8, BASE_HEX, NULL, 0x01, NULL, HFILL
}
},
{
&hf_sbc_ss_mimo_uplink_support_2_ann_sm_vertical,
{
"2-antenna SM with vertical coding", "wmx.sbc.ofdma_ss_mimo_uplink_support.2_antenna_sm_with_vertical_coding",
FT_UINT8, BASE_HEX, NULL, 0x02, NULL, HFILL
}
},
{
&hf_sbc_ss_mimo_uplink_support_1_ann_coop_sm,
{
"Single-antenna cooperative SM", "wmx.sbc.ofdma_ss_mimo_uplink_support.single_antenna_coop_sm",
FT_UINT8, BASE_HEX, NULL, 0x04, NULL, HFILL
}
},
{
&hf_sbc_ss_ofdma_uplink_aas_preamble,
{
"Uplink AAS Preamble", "wmx.sbc.ofdma_uplink_aas_preamble",
FT_BOOLEAN, 16, TFS(&tfs_supported), 0x10, NULL, HFILL
}
},
{
&hf_sbc_ss_phy_cinr_measurement_preamble,
{
"Physical CINR Measurement From The Preamble", "wmx.sbc.phy_cinr_measure_preamble",
FT_BOOLEAN, 8, TFS(&tfs_supported), 0x1, NULL, HFILL
}
},
{
&hf_sbc_ss_phy_cinr_measurement_permutation_zone_from_pilot_subcarriers,
{
"Physical CINR Measurement For A Permutation Zone From Pilot Subcarriers", "wmx.sbc.phy_cinr_measure_permutation_zone.pilot_subcarriers",
FT_BOOLEAN, 8, TFS(&tfs_supported), 0x2, NULL, HFILL
}
},
{
&hf_sbc_ss_phy_cinr_measurement_permutation_zone_from_data_subcarriers,
{
"Physical CINR Measurement For A Permutation Zone From Data Subcarriers", "wmx.sbc.phy_cinr_measure_permutation_zone.data_subcarriers",
FT_BOOLEAN, 8, TFS(&tfs_supported), 0x4, NULL, HFILL
}
},
{
&hf_sbc_pkm_flow_control,
{
"PKM Flow Control", "wmx.sbc.pkm_flow_control",
FT_UINT8, BASE_DEC, NULL, 0x0, NULL, HFILL
}
},
{
&hf_sbc_power_save_class_types_capability,
{
"Power Save Class Types Capability", "wmx.sbc.power_save_class_types_capability",
FT_UINT8, BASE_HEX, NULL, 0x0, NULL, HFILL
}
},
{
&hf_sbc_power_save_class_types_capability_bit0,
{
"Power Save Class Type I", "wmx.sbc.power_save_class_types_capability.bit0",
FT_BOOLEAN, 8, TFS(&tfs_supported), 0x1, NULL, HFILL
}
},
{
&hf_sbc_power_save_class_types_capability_bit1,
{
"Power Save Class Type II", "wmx.sbc.power_save_class_types_capability.bit1",
FT_BOOLEAN, 8, TFS(&tfs_supported), 0x2, NULL, HFILL
}
},
{
&hf_sbc_power_save_class_types_capability_bit2,
{
"Power Save Class Type III", "wmx.sbc.power_save_class_types_capability.bit2",
FT_BOOLEAN, 8, TFS(&tfs_supported), 0x4, NULL, HFILL
}
},
{
&hf_sbc_power_save_class_types_capability_bits34,
{
"Number Of Power Save Class Type Instances Supported From Class Type I and II", "wmx.sbc.power_save_class_types_capability.bits34",
FT_UINT8, BASE_DEC, NULL, 0x18, NULL, HFILL
}
},
{
&hf_sbc_power_save_class_types_capability_bits567,
{
"Number Of Power Save Class Type Instances Supported From Class Type III", "wmx.sbc.power_save_class_types_capability.bits567",
FT_UINT8, BASE_DEC, NULL, 0xE0, NULL, HFILL
}
},
{
&hf_sbc_ofdma_aas_private_chain_enable,
{
"Private Map Chain Enable", "wmx.sbc.private_chain_enable",
FT_BOOLEAN, 8, TFS(&tfs_supported), 0x8, NULL, HFILL
}
},
{
&hf_sbc_ofdma_aas_private_map_concurrency,
{
"Private Map Chain Concurrency", "wmx.sbc.private_map_concurrency",
FT_UINT8, BASE_HEX, NULL, 0xC0, NULL, HFILL
}
},
{
&hf_sbc_ofdma_aas_private_map_dl_frame_offset,
{
"Private Map DL Frame Offset", "wmx.sbc.private_map_dl_frame_offset",
FT_BOOLEAN, 8, TFS(&tfs_supported), 0x10, NULL, HFILL
}
},
{
&hf_sbc_ofdma_aas_private_map_support,
{
"Private Map Support", "wmx.sbc.private_map_support",
FT_BOOLEAN, 8, TFS(&tfs_supported), 0x2, NULL, HFILL
}
},
{
&hf_sbc_ss_ofdma_aas_private,
{
"OFDMA AAS Private Map Support", "wmx.sbc.private_map_support.ofdma_aas",
FT_UINT8, BASE_HEX, NULL, 0x0, NULL, HFILL
}
},
{
&hf_sbc_ofdma_aas_reduced_private_map_support,
{
"Reduced Private Map Support", "wmx.sbc.private_map_support.reduced",
FT_BOOLEAN, 8, TFS(&tfs_supported), 0x4, NULL, HFILL
}
},
{
&hf_sbc_ofdma_aas_private_ul_frame_offset,
{
"Private Map UL Frame Offset", "wmx.sbc.private_ul_frame_offset",
FT_BOOLEAN, 8, TFS(&tfs_supported), 0x20, NULL, HFILL
}
},
{
&hf_sbc_mac_pdu_rsvd,
{
"Reserved", "wmx.sbc.mac_pdu.rsvd",
FT_UINT8, BASE_HEX, NULL, 0xFC, NULL, HFILL
}
},
{
&hf_sbc_max_transmit_power,
{
"Maximum Transmit Power", "wmx.sbc.max_transmit_power",
FT_UINT32, BASE_HEX, NULL, 0x00, NULL, HFILL
}
},
{
&hf_sbc_ss_demodulator_mimo_2_ann_stc_matrix_a,
{
"2-antenna STC Matrix A", "wmx.sbc.ss_demodulator.mimo.2.antenna.stc.matrix.a",
FT_BOOLEAN, 16, TFS(&tfs_supported), 0x1, NULL, HFILL
}
},
{
&hf_sbc_ss_demodulator_mimo_2_ann_stc_matrix_b_horizontal,
{
"2-antenna STC Matrix B, horizontal coding", "wmx.sbc.ss_demodulator.mimo.2.antenna.stc.matrix.b.horizontal",
FT_BOOLEAN, 16, TFS(&tfs_supported), 0x4, NULL, HFILL
}
},
{
&hf_sbc_ss_demodulator_mimo_2_ann_stc_matrix_b_vertical,
{
"2-antenna STC Matrix B, vertical coding", "wmx.sbc.ss_demodulator.mimo.2.antenna.stc.matrix.b.vertical",
FT_BOOLEAN, 16, TFS(&tfs_supported), 0x2, NULL, HFILL
}
},
{
&hf_sbc_ss_demodulator_mimo_4_ann_stc_matrix_a,
{
"4-antenna STC Matrix A", "wmx.sbc.ss_demodulator.mimo.4.antenna.stc.matrix.a",
FT_BOOLEAN, 16, TFS(&tfs_supported), 0x8, NULL, HFILL
}
},
{
&hf_sbc_ss_demodulator_mimo_4_ann_stc_matrix_b_horizontal,
{
"4-antenna STC Matrix B, horizontal coding", "wmx.sbc.ss_demodulator.mimo.4.antenna.stc.matrix.b.horizontal",
FT_BOOLEAN, 16, TFS(&tfs_supported), 0x20, NULL, HFILL
}
},
{
&hf_sbc_ss_demodulator_mimo_4_ann_stc_matrix_b_vertical,
{
"4-antenna STC Matrix B, vertical coding", "wmx.sbc.ss_demodulator.mimo.4.antenna.stc.matrix.b.vertical",
FT_BOOLEAN, 16, TFS(&tfs_supported), 0x10, NULL, HFILL
}
},
{
&hf_sbc_ss_demodulator_mimo_4_ann_stc_matrix_c_horizontal,
{
"4-antenna STC Matrix C, horizontal coding", "wmx.sbc.ss_demodulator.mimo.4.antenna.stc.matrix.c.horizontal",
FT_BOOLEAN, 16, TFS(&tfs_supported), 0x80, NULL, HFILL
}
},
{
&hf_sbc_ss_demodulator_mimo_4_ann_stc_matrix_c_vertical,
{
"4-antenna STC Matrix C, vertical coding", "wmx.sbc.ss_demodulator.mimo.4.antenna.stc.matrix.c.vertical",
FT_BOOLEAN, 16, TFS(&tfs_supported), 0x40, NULL, HFILL
}
},
{
&hf_sbc_ss_demodulator_mimo_rsvd,
{
"Reserved", "wmx.sbc.ss_demodulator.mimo.reserved",
FT_UINT16, BASE_HEX, NULL, 0xFF00, NULL, HFILL
}
},
{
&hf_sbc_ss_demodulator_mimo_support,
{
"OFDMA SS Demodulator For MIMO Support", "wmx.sbc.ss_demodulator.mimo.support",
FT_UINT16, BASE_HEX, NULL, 0x0, NULL, HFILL
}
},
{
&hf_sbc_ofdma_ss_uplink_power_control_support,
{
"OFDMA SS uplink power control support", "wmx.sbc.ofdma_ss_uplink_power_control_support",
FT_UINT8, BASE_HEX, NULL, 0x0, NULL, HFILL
}
},
{
&hf_sbc_ofdma_ss_uplink_power_control_support_open_loop,
{
"Open loop", "wmx.sbc.ofdma_ss_uplink_power_control_support.open_loop",
FT_UINT8, BASE_HEX, NULL, 0x01, NULL, HFILL
}
},
{
&hf_sbc_ofdma_ss_uplink_power_control_support_aas_preamble,
{
"AAS preamble", "wmx.sbc.ofdma_ss_uplink_power_control_support.aas_preamble",
FT_UINT8, BASE_HEX, NULL, 0x02, NULL, HFILL
}
},
{
&hf_sbc_ofdma_ss_uplink_power_control_support_rsvd,
{
"Reserved", "wmx.sbc.ofdma_ss_uplink_power_control_support.rsvd",
FT_UINT8, BASE_HEX, NULL, 0xFC, NULL, HFILL
}
},
{
&hf_sbc_tlv_t_172_dl_region_definition_support,
{
"DL Region Definition Support", "wmx.sbc.ofdma_map_capability.dl_region_definition_support",
FT_BOOLEAN, 8, TFS(&tfs_supported), 0x10, NULL, HFILL
}
},
{
&hf_sbc_tlv_t_172,
{
"Support For Extended HARQ", "wmx.sbc.ofdma_map_capability.extended_harq",
FT_UINT8, BASE_HEX, NULL, 0x0, NULL, HFILL
}
},
{
&hf_sbc_tlv_t_172_extended_harq_ie_capability,
{
"Extended HARQ IE Capability", "wmx.sbc.ofdma_map_capability.extended_harq_ie_capability",
FT_BOOLEAN, 8, TFS(&tfs_supported), 0x2, NULL, HFILL
}
},
{
&hf_sbc_tlv_t_172_harq_map_capability,
{
"HARQ MAP Capability", "wmx.sbc.ofdma_map_capability.harq_map_capability",
FT_BOOLEAN, 8, TFS(&tfs_supported), 0x1, NULL, HFILL
}
},
{
&hf_sbc_tlv_t_171_minimum_num_of_frames,
{
"The Minimum Number Of Frames That SS Takes To Switch From The Open Loop Power Control Scheme To The Closed Loop Power Control Scheme Or Vice Versa", "wmx.sbc.ofdma_ss_uplink_power_control_support.minimum_num_of_frames",
FT_UINT8, BASE_DEC, NULL, 0x0, NULL, HFILL
}
},
{
&hf_sbc_tlv_t_172_reserved,
{
"Reserved", "wmx.sbc.ofdma_map_capability.reserved",
FT_UINT8, BASE_HEX, NULL, 0xE0, NULL, HFILL
}
},
{
&hf_sbc_tlv_t_172_sub_map_capability_first_zone,
{
"Sub MAP Capability For First Zone", "wmx.sbc.ofdma_map_capability.sub_map_capability_first_zone",
FT_BOOLEAN, 8, TFS(&tfs_supported), 0x4, NULL, HFILL
}
},
{
&hf_sbc_tlv_t_172_sub_map_capability_other_zones,
{
"Sub MAP Capability For Other Zones", "wmx.sbc.ofdma_map_capability.sub_map_capability_other_zones",
FT_BOOLEAN, 8, TFS(&tfs_supported), 0x8, NULL, HFILL
}
},
{
&hf_sbc_tlv_t_174_ofdma_ms_csit_capability,
{
"OFDMA MS CSIT Capability", "wmx.sbc.ofdma_ms_csit_capability",
FT_UINT8, BASE_HEX, NULL, 0x0, NULL, HFILL
}
},
{
&hf_sbc_tlv_t_174_csit_compatibility_type_a,
{
"CSIT Compatibility Type A", "wmx.sbc.ofdma_ms_csit_capability.csit_compatibility_type_a",
FT_BOOLEAN, 16, TFS(&tfs_supported), 0x1, NULL, HFILL
}
},
{
&hf_sbc_tlv_t_174_csit_compatibility_type_b,
{
"CSIT Compatibility Type B", "wmx.sbc.ofdma_ms_csit_capability.csit_compatibility_type_b",
FT_BOOLEAN, 16, TFS(&tfs_supported), 0x2, NULL, HFILL
}
},
{
&hf_sbc_tlv_t_174_max_num_simultanous_sounding_instructions,
{
"Max Number Of Simultaneous Sounding Instructions", "wmx.sbc.ofdma_ms_csit_capability.max_num_simultaneous_sounding_instructions",
FT_UINT16, BASE_DEC, NULL, 0x03C0, NULL, HFILL
}
},
{
&hf_sbc_tlv_t_174_power_assignment_capability,
{
"Power Assignment Capability", "wmx.sbc.ofdma_ms_csit_capability.power_assignment_capability",
FT_BOOLEAN, 16, TFS(&tfs_supported), 0x4, NULL, HFILL
}
},
{
&hf_sbc_tlv_t_174_ss_csit_reserved,
{
"Reserved", "wmx.sbc.ofdma_ms_csit_capability.reserved",
FT_UINT16, BASE_HEX, NULL, 0xF800, NULL, HFILL
}
},
{
&hf_sbc_tlv_t_174_sounding_rsp_time_capability,
{
"Sounding Response Time Capability", "wmx.sbc.ofdma_ms_csit_capability.sounding_response_time_capability",
FT_UINT16, BASE_HEX, VALS(vals_sounding_rsp_time_cap_codings), 0x0038, NULL, HFILL
}
},
{
&hf_sbc_tlv_t_174_ss_csit_type_a_support,
{
"SS Does Not Support P Values Of 9 And 18 When Supporting CSIT Type A", "wmx.sbc.ofdma_ms_csit_capability.type_a_support",
FT_BOOLEAN, 16, TFS(&tfs_supported), 0x0400, NULL, HFILL
}
},
{
&hf_sbc_tlv_t_204_ofdma_parameters_sets,
{
"OFDMA parameters sets", "wmx.sbc.ofdma_parameters_sets",
FT_UINT8, BASE_HEX, NULL, 0x0, NULL, HFILL
}
},
{
&hf_sbc_tlv_t_204_ofdma_parameters_sets_phy_set_a,
{
"Support OFDMA PHY parameter set A", "wmx.sbc.ofdma_parameters_sets.phy_set_a",
FT_UINT8, BASE_HEX, NULL, 0x01, NULL, HFILL
}
},
{
&hf_sbc_tlv_t_204_ofdma_parameters_sets_phy_set_b,
{
"Support OFDMA PHY parameter set B", "wmx.sbc.ofdma_parameters_sets.phy_set_b",
FT_UINT8, BASE_HEX, NULL, 0x02, NULL, HFILL
}
},
{
&hf_sbc_tlv_t_204_ofdma_parameters_sets_harq_parameters_set,
{
"HARQ parameters set", "wmx.sbc.ofdma_parameters_sets.harq_parameters_set",
FT_UINT8, BASE_HEX, VALS(vals_sbc_harq_parameters_set), 0x1C, NULL, HFILL
}
},
{
&hf_sbc_tlv_t_204_ofdma_parameters_sets_mac_set_a,
{
"Support OFDMA MAC parameters set A", "wmx.sbc.ofdma_parameters_sets.mac_set_a",
FT_UINT8, BASE_HEX, NULL, 0x20, NULL, HFILL
}
},
{
&hf_sbc_tlv_t_204_ofdma_parameters_sets_mac_set_b,
{
"Support OFDMA MAC parameters set B", "wmx.sbc.ofdma_parameters_sets.mac_set_b",
FT_UINT8, BASE_HEX, NULL, 0x40, NULL, HFILL
}
},
{
&hf_sbc_tlv_t_204_ofdma_parameters_sets_reserved,
{
"Reserved", "wmx.sbc.ofdma_parameters_sets.reserved",
FT_UINT8, BASE_HEX, NULL, 0x80, NULL, HFILL
}
},
{
&hf_sbc_tlv_t_177_ofdma_ss_modulator_for_mimo_support,
{
"OFDMA SS Modulator For MIMO Support", "wmx.sbc.ofdma_ss_modulator_for_mimo_support",
FT_UINT8, BASE_HEX, NULL, 0x0, NULL, HFILL
}
},
{
&hf_sbc_tlv_t_177_adaptive_rate_ctl,
{
"Capable Of Adaptive Rate Control", "wmx.sbc.ofdma_ss_modulator_for_mimo_support.capable_adaptive_rate_control",
FT_BOOLEAN, 8, TFS(&tfs_supported), 0x10, NULL, HFILL
}
},
{
&hf_sbc_tlv_t_177_beamforming,
{
"Capable Of Beamforming", "wmx.sbc.ofdma_ss_modulator_for_mimo_support.capable_beamforming",
FT_BOOLEAN, 8, TFS(&tfs_supported), 0x8, NULL, HFILL
}
},
{
&hf_sbc_tlv_t_177_single_antenna,
{
"Capable of single antenna transmission", "wmx.sbc.ofdma_ss_modulator_for_mimo_support.capable_single_antenna",
FT_BOOLEAN, 8, TFS(&tfs_supported), 0x20, NULL, HFILL
}
},
{
&hf_sbc_tlv_t_177_stc_matrix_b_horizontal,
{
"Capable of 2-antenna STC Matrix B, Horizontal coding", "wmx.sbc.ofdma_ss_modulator_for_mimo_support.stc_matrix_b_horizontal",
FT_BOOLEAN, 8, TFS(&tfs_supported), 0x4, NULL, HFILL
}
},
{
&hf_sbc_tlv_t_177_two_transmit_antennas,
{
"Two transmit antennas", "wmx.sbc.ofdma_ss_modulator_for_mimo_support.two_transmit_antennas",
FT_BOOLEAN, 8, TFS(&tfs_supported), 0x1, NULL, HFILL
}
},
{
&hf_sbc_tlv_t_177_capable_of_transmit_diversity,
{
"Capable of transmit diversity", "wmx.sbc.ofdma_ss_modulator_for_mimo_support.capable_of_transmit_diversity",
FT_BOOLEAN, 8, TFS(&tfs_supported), 0x2, NULL, HFILL
}
},
{
&hf_sbc_tlv_t_177_capable_of_spacial_multiplexing,
{
"Capable of spatial multiplexing", "wmx.sbc.ofdma_ss_modulator_for_mimo_support.capable_of_spatial_multiplexing",
FT_BOOLEAN, 8, TFS(&tfs_supported), 0x4, NULL, HFILL
}
},
{
&hf_sbc_tlv_t_177_stc_matrix_b_vertical,
{
"Capable of 2-antenna STC Matrix B, Vertical coding", "wmx.sbc.ofdma_ss_modulator_for_mimo_support.stc_matrix_b_vertical",
FT_BOOLEAN, 8, TFS(&tfs_supported), 0x2, NULL, HFILL
}
},
{
&hf_sbc_tlv_t_177_collaborative_sm_with_one_antenna,
{
"Capable of collaborative SM with one antenna", "wmx.sbc.ofdma_ss_modulator_for_mimo_support.collaborative_sm_with_one_antenna",
FT_BOOLEAN, 8, TFS(&tfs_supported), 0x40, NULL, HFILL
}
},
{
&hf_sbc_tlv_t_177_collaborative_sm_with_two_antennas,
{
"Collaborative SM with two antennas", "wmx.sbc.ofdma_ss_modulator_for_mimo_support.collaborative_sm_with_two_antennas",
FT_UINT8, BASE_HEX, NULL, 0x80, NULL, HFILL
}
},
{
&hf_sbc_tlv_t_177_capable_of_two_antenna,
{
"Capable of two antenna", "wmx.sbc.ofdma_ss_modulator_for_mimo_support.capable_of_two_antenna",
FT_UINT8, BASE_HEX, NULL, 0x40, NULL, HFILL
}
},
{
&hf_sbc_tlv_t_177_rsvd,
{
"Reserved", "wmx.sbc.ofdma_ss_modulator_for_mimo_support.rsvd",
FT_UINT8, BASE_HEX, NULL, 0x80, NULL, HFILL
}
},
{
&hf_sbc_tlv_t_177_stc_matrix_a,
{
"Capable of 2-antenna STC Matrix A", "wmx.sbc.ofdma_ss_modulator_for_mimo_support.stc_matrix_a",
FT_BOOLEAN, 8, TFS(&tfs_supported), 0x1, NULL, HFILL
}
},
{
&hf_sbc_tlv_t_178_sdma_pilot_capability,
{
"SDMA Pilot Capability", "wmx.sbc.sdma_pilot_capability",
FT_UINT8, BASE_HEX, NULL, 0x0, NULL, HFILL
}
},
{
&hf_sbc_tlv_t_178_reserved,
{
"Reserved", "wmx.sbc.sdma_pilot_capability.reserved",
FT_UINT8, BASE_HEX, NULL, 0xFC, NULL, HFILL
}
},
{
&hf_sbc_tlv_t_178_sdma_pilot_pattern_support_for_amc_zone,
{
"SDMA Pilot Patterns Support For AMC Zone", "wmx.sbc.sdma_pilot_capability.sdma_pilot_pattern_support_for_amc_zone",
FT_UINT8, BASE_HEX, VALS(vals_sbc_sdma_str), 0x03, NULL, HFILL
}
},
{
&hf_sbc_ss_demodulator,
{
"OFDMA SS Demodulator", "wmx.sbc.ss_demodulator",
FT_BYTES, BASE_NONE, NULL, 0x0, NULL, HFILL
}
},
{
&hf_sbc_ss_demodulator_64qam,
{
"64-QAM", "wmx.sbc.ss_demodulator.64qam",
FT_BOOLEAN, 8, TFS(&tfs_supported), 0x1, NULL, HFILL
}
},
{
&hf_sbc_ss_demodulator_btc,
{
"BTC", "wmx.sbc.ss_demodulator.btc",
FT_BOOLEAN, 8, TFS(&tfs_supported), 0x2, NULL, HFILL
}
},
{
&hf_sbc_ss_demodulator_cc_with_optional_interleaver,
{
"CC with Optional Interleaver", "wmx.sbc.ss_demodulator.cc_with_optional_interleaver",
FT_BOOLEAN, 8, TFS(&tfs_supported), 0x10, NULL, HFILL
}
},
{
&hf_sbc_ss_demodulator_ctc,
{
"CTC", "wmx.sbc.ss_demodulator.ctc",
FT_BOOLEAN, 8, TFS(&tfs_supported), 0x4, NULL, HFILL
}
},
{
&hf_sbc_ss_demodulator_64qam_2,
{
"64-QAM", "wmx.sbc.ss_demodulator.64qam",
FT_BOOLEAN, 16, TFS(&tfs_supported), 0x1, NULL, HFILL
}
},
{
&hf_sbc_ss_demodulator_btc_2,
{
"BTC", "wmx.sbc.ss_demodulator.btc",
FT_BOOLEAN, 16, TFS(&tfs_supported), 0x2, NULL, HFILL
}
},
{
&hf_sbc_ss_demodulator_cc_with_optional_interleaver_2,
{
"CC with Optional Interleaver", "wmx.sbc.ss_demodulator.cc_with_optional_interleaver",
FT_BOOLEAN, 16, TFS(&tfs_supported), 0x10, NULL, HFILL
}
},
{
&hf_sbc_ss_demodulator_ctc_2,
{
"CTC", "wmx.sbc.ss_demodulator.ctc",
FT_BOOLEAN, 16, TFS(&tfs_supported), 0x4, NULL, HFILL
}
},
{
&hf_sbc_ss_demodulator_dedicated_pilots_2,
{
"Dedicated Pilots", "wmx.sbc.ss_demodulator.dedicated_pilots",
FT_BOOLEAN, 16, TFS(&tfs_supported), 0x400, NULL, HFILL
}
},
{
&hf_sbc_ss_demodulator_harq_cc_ir_2,
{
"HARQ CC_IR", "wmx.sbc.ss_demodulator.harq.cc.ir",
FT_BOOLEAN, 16, TFS(&tfs_supported), 0x100, NULL, HFILL
}
},
{
&hf_sbc_ss_demodulator_harq_chase,
{
"HARQ Chase", "wmx.sbc.ss_demodulator.harq.chase",
FT_BOOLEAN, 8, TFS(&tfs_supported), 0x20, NULL, HFILL
}
},
{
&hf_sbc_ss_demodulator_harq_chase_2,
{
"HARQ Chase", "wmx.sbc.ss_demodulator.harq.chase",
FT_BOOLEAN, 16, TFS(&tfs_supported), 0x20, NULL, HFILL
}
},
{
&hf_sbc_ss_demodulator_harq_ctc_ir,
{
"HARQ CTC_IR", "wmx.sbc.ss_demodulator.harq.ctc.ir",
FT_BOOLEAN, 8, TFS(&tfs_supported), 0x40, NULL, HFILL
}
},
{
&hf_sbc_ss_demodulator_harq_ctc_ir_2,
{
"HARQ CTC_IR", "wmx.sbc.ss_demodulator.harq.ctc.ir",
FT_BOOLEAN, 16, TFS(&tfs_supported), 0x40, NULL, HFILL
}
},
{
&hf_sbc_ss_demodulator_ldpc_2,
{
"LDPC", "wmx.sbc.ss_demodulator.ldpc",
FT_BOOLEAN, 16, TFS(&tfs_supported), 0x200, NULL, HFILL
}
},
{
&hf_sbc_ss_demodulator_reserved,
{
"Reserved", "wmx.sbc.ss_demodulator.reserved1",
FT_UINT8, BASE_HEX, NULL, 0x80, NULL, HFILL
}
},
{
&hf_sbc_ss_demodulator_reserved_2,
{
"Reserved", "wmx.sbc.ss_demodulator.reserved2",
FT_UINT16, BASE_HEX, NULL, 0x80, NULL, HFILL
}
},
{
&hf_sbc_ss_demodulator_reserved1_2,
{
"Reserved", "wmx.sbc.ss_demodulator.reserved2",
FT_UINT16, BASE_HEX, NULL, 0x800, NULL, HFILL
}
},
{
&hf_sbc_ss_demodulator_reserved1,
{
"Reserved", "wmx.sbc.ss_demodulator.reserved1",
FT_UINT16, BASE_HEX, NULL, 0xFFFF, NULL, HFILL
}
},
{
&hf_sbc_ss_demodulator_stc,
{
"STC", "wmx.sbc.ss_demodulator.stc",
FT_BOOLEAN, 8, TFS(&tfs_supported), 0x8, NULL, HFILL
}
},
{
&hf_sbc_ss_demodulator_stc_2,
{
"STC", "wmx.sbc.ss_demodulator.stc",
FT_BOOLEAN, 16, TFS(&tfs_supported), 0x8, NULL, HFILL
}
},
{
&hf_sbc_ss_fft_sizes,
{
"OFDMA SS FFT Sizes", "wmx.sbc.ss_fft_sizes",
FT_UINT8, BASE_HEX, NULL, 0x0, NULL, HFILL
}
},
{
&hf_sbc_ss_fft_128,
{
"FFT-128", "wmx.sbc.ss_fft_sizes.128",
FT_BOOLEAN, 8, TFS(&tfs_supported), 0x4, NULL, HFILL
}
},
{
&hf_sbc_ss_fft_256,
{
"FFT-256", "wmx.sbc.ss_fft_sizes.256",
FT_BOOLEAN, 8, TFS(&tfs_supported), 0x1, NULL, HFILL
}
},
{
&hf_sbc_ss_fft_512,
{
"FFT-512", "wmx.sbc.ss_fft_sizes.512",
FT_BOOLEAN, 8, TFS(&tfs_supported), 0x8, NULL, HFILL
}
},
{
&hf_sbc_ss_fft_1024,
{
"FFT-1024", "wmx.sbc.ss_fft_sizes.1024",
FT_BOOLEAN, 8, TFS(&tfs_supported), 0x10, NULL, HFILL
}
},
{
&hf_sbc_ss_fft_2048,
{
"FFT-2048", "wmx.sbc.ss_fft_sizes.2048",
FT_BOOLEAN, 8, TFS(&tfs_supported), 0x2, NULL, HFILL
}
},
{
&hf_sbc_ss_fft_rsvd1,
{
"Reserved", "wmx.sbc_ss_fft_sizes_rsvd1",
FT_UINT8, BASE_HEX, NULL, 0x01, NULL, HFILL
}
},
{
&hf_sbc_ss_fft_rsvd2,
{
"Reserved", "wmx.sbc.ss_fft_sizes.rsvd2",
FT_UINT8, BASE_HEX, NULL, 0xE0, NULL, HFILL
}
},
{
&hf_sbc_ofdm_ss_minimum_num_of_frames,
{
"SS minimum number of frames", "wmx.sbc.ss_minimum_num_of_frames",
FT_UINT8, BASE_HEX, NULL, 0x0, NULL, HFILL
}
},
{
&hf_sbc_ss_mimo_uplink_support_rsvd,
{
"Reserved", "wmx.sbc.ss_mimo_ul_support.rsvd",
FT_UINT8, BASE_HEX, NULL, 0xF8, NULL, HFILL
}
},
{
&hf_sbc_ss_modulator,
{
"OFDMA SS Modulator", "wmx.sbc.ss_modulator",
FT_UINT8, BASE_HEX, NULL, 0x0, NULL, HFILL
}
},
{
&hf_sbc_ss_modulator_64qam,
{
"64-QAM", "wmx.sbc.ss_modulator.64qam",
FT_BOOLEAN, 8, TFS(&tfs_supported), 0x1, NULL, HFILL
}
},
{
&hf_sbc_ss_modulator_btc,
{
"BTC", "wmx.sbc.ss_modulator.btc",
FT_BOOLEAN, 8, TFS(&tfs_supported), 0x2, NULL, HFILL
}
},
{
&hf_sbc_ss_modulator_cc_ir,
{
"CC_IR", "wmx.sbc.ss_modulator.cc_ir",
FT_BOOLEAN, 8, TFS(&tfs_supported), 0x40, NULL, HFILL
}
},
{
&hf_sbc_ss_modulator_ctc,
{
"CTC", "wmx.sbc.ss_modulator.ctc",
FT_BOOLEAN, 8, TFS(&tfs_supported), 0x4, NULL, HFILL
}
},
{
&hf_sbc_ss_modulator_ctc_ir,
{
"CTC_IR", "wmx.sbc.ss_modulator.ctc_ir",
FT_BOOLEAN, 8, TFS(&tfs_supported), 0x20, NULL, HFILL
}
},
{
&hf_sbc_ss_modulator_harq_chase,
{
"HARQ Chase", "wmx.sbc.ss_modulator.harq_chase",
FT_BOOLEAN, 8, TFS(&tfs_supported), 0x10, NULL, HFILL
}
},
{
&hf_sbc_ss_modulator_ldpc,
{
"LDPC", "wmx.sbc.ss_modulator.ldpc",
FT_BOOLEAN, 8, TFS(&tfs_supported), 0x80, NULL, HFILL
}
},
{
&hf_sbc_ss_modulator_stc,
{
"STC", "wmx.sbc.ss_modulator.stc",
FT_BOOLEAN, 8, TFS(&tfs_supported), 0x8, NULL, HFILL
}
},
{
&hf_sbc_ss_permutation_support,
{
"OFMDA SS Permutation Support", "wmx.sbc.ss_permutation_support",
FT_UINT8, BASE_HEX, NULL, 0x0, NULL, HFILL
}
},
{
&hf_sbc_ss_amc_1x6,
{
"AMC 1x6", "wmx.sbc.ss_permutation_support.amc_1x6",
FT_BOOLEAN, 8, TFS(&tfs_supported), 0x4, NULL, HFILL
}
},
{
&hf_sbc_ss_amc_2x3,
{
"AMC 2x3", "wmx.sbc.ss_permutation_support.amc_2x3",
FT_BOOLEAN, 8, TFS(&tfs_supported), 0x8, NULL, HFILL
}
},
{
&hf_sbc_ss_amc_3x2,
{
"AMC 3x2", "wmx.sbc.ss_permutation_support.amc_3x2",
FT_BOOLEAN, 8, TFS(&tfs_supported), 0x10, NULL, HFILL
}
},
{
&hf_sbc_ss_amc_with_harq_map,
{
"AMC Support With H-ARQ Map", "wmx.sbc.ss_permutation_support.amc_support_harq_map",
FT_BOOLEAN, 8, TFS(&tfs_supported), 0x20, NULL, HFILL
}
},
{
&hf_sbc_ss_optimal_fusc,
{
"Optional FUSC", "wmx.sbc.ss_permutation_support.optimal_fusc",
FT_BOOLEAN, 8, TFS(&tfs_supported), 0x2, NULL, HFILL
}
},
{
&hf_sbc_ss_optimal_pusc,
{
"Optional PUSC", "wmx.sbc.ss_permutation_support.optimal_pusc",
FT_BOOLEAN, 8, TFS(&tfs_supported), 0x1, NULL, HFILL
}
},
{
&hf_sbc_ss_tusc1_support,
{
"TUSC1", "wmx.sbc.ss_permutation_support.tusc1_support",
FT_BOOLEAN, 8, TFS(&tfs_supported), 0x40, NULL, HFILL
}
},
{
&hf_sbc_ss_tusc2_support,
{
"TUSC2", "wmx.sbc.ss_permutation_support.tusc2_support",
FT_BOOLEAN, 8, TFS(&tfs_supported), 0x80, NULL, HFILL
}
},
{
&hf_sbc_ssrtg,
{
"SSRTG", "wmx.sbc.ssrtg",
FT_UINT8, BASE_DEC, NULL, 0x0, NULL, HFILL
}
},
{
&hf_sbc_ssttg,
{
"SSTTG", "wmx.sbc.ssttg",
FT_UINT8, BASE_DEC, NULL, 0x0, NULL, HFILL
}
},
{
&hf_sbc_ss_support_2_concurrent_cqi_channels,
{
"Support for 2 Concurrent CQI Channels", "wmx.sbc.support_2_concurrent_cqi_channels",
FT_BOOLEAN, 8, TFS(&tfs_supported), 0x40, NULL, HFILL
}
},
{
&hf_sbc_transition_gaps,
{
"Subscriber Transition Gaps", "wmx.sbc.transition_gaps",
FT_UINT16, BASE_HEX, NULL, 0x00, NULL, HFILL
}
},
{
&hf_sbc_tlv_t_173_ul_ctl_channel_support,
{
"Uplink Control Channel Support", "wmx.sbc.ul_ctl_channel_support",
FT_UINT8, BASE_HEX, NULL, 0x0, NULL, HFILL
}
},
{
&hf_sbc_tlv_t_173_3_bit_mimo_fast_feedback,
{
"3-bit MIMO Fast-feedback", "wmx.sbc.ul_ctl_channel_support.3bit_mimo_fast_feedback",
FT_BOOLEAN, 8, TFS(&tfs_supported), 0x1, NULL, HFILL
}
},
{
&hf_sbc_tlv_t_173_diuc_cqi_fast_feedback,
{
"DIUC-CQI Fast-feedback", "wmx.sbc.ul_ctl_channel_support.diuc_cqi_fast_feedback",
FT_BOOLEAN, 8, TFS(&tfs_supported), 0x80, NULL, HFILL
}
},
{
&hf_sbc_tlv_t_173_enhanced_fast_feedback,
{
"Enhanced Fast_feedback", "wmx.sbc.ul_ctl_channel_support.enhanced_fast_feedback",
FT_BOOLEAN, 8, TFS(&tfs_supported), 0x2, NULL, HFILL
}
},
{
&hf_sbc_tlv_t_173_measurement_report,
{
"A Measurement Report Shall Be Performed On The Last DL Burst", "wmx.sbc.ul_ctl_channel_support.measurement_report",
FT_BOOLEAN, 8, TFS(&tfs_supported), 0x20, NULL, HFILL
}
},
{
&hf_sbc_tlv_t_173_primary_secondary_fast_feedback,
{
"Primary/Secondary FAST_FEEDBACK", "wmx.sbc.ul_ctl_channel_support.primary_secondary_fast_feedback",
FT_BOOLEAN, 8, TFS(&tfs_supported), 0x40, NULL, HFILL
}
},
{
&hf_sbc_tlv_t_173_reserved,
{
"Reserved", "wmx.sbc.ul_ctl_channel_support.reserved",
FT_UINT8, BASE_HEX, NULL, 0x8, NULL, HFILL
}
},
{
&hf_sbc_tlv_t_173_uep_fast_feedback,
{
"UEP Fast-feedback", "wmx.sbc.ul_ctl_channel_support.uep_fast_feedback",
FT_BOOLEAN, 8, TFS(&tfs_supported), 0x10, NULL, HFILL
}
},
{
&hf_sbc_tlv_t_173_ul_ack,
{
"UL ACK", "wmx.sbc.ul_ctl_channel_support.ul_ack",
FT_BOOLEAN, 8, TFS(&tfs_supported), 0x4, NULL, HFILL
}
},
{
&hf_sbc_req_message_type,
{
"MAC Management Message Type", "wmx.macmgtmsgtype.sbc_req",
FT_UINT8, BASE_DEC, NULL, 0x0, NULL, HFILL
}
},
{ &hf_sbc_rsp_message_type,
{
"MAC Management Message Type", "wmx.macmgtmsgtype.sbc_rsp",
FT_UINT8, BASE_DEC, NULL, 0x0, NULL, HFILL
}
},
{
&hf_sbc_unknown_type,
{
"Unknown SBC type", "wmx.sbc.unknown_tlv_type",
FT_BYTES, BASE_NONE, NULL, 0x0, NULL, HFILL
}
}
};
static gint *ett_sbc[] =
{
&ett_mac_mgmt_msg_sbc_decoder,
&ett_sbc_req_tlv_subtree,
&ett_sbc_rsp_tlv_subtree,
};
proto_mac_mgmt_msg_sbc_decoder = proto_register_protocol (
"WiMax SBC-REQ/RSP Messages",
"WiMax SBC-REQ/RSP (sbc)",
"wmx.sbc"
);
proto_register_field_array(proto_mac_mgmt_msg_sbc_decoder, hf_sbc, array_length(hf_sbc));
proto_register_subtree_array(ett_sbc, array_length(ett_sbc));
}
