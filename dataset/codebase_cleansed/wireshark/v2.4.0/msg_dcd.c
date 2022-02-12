static int dissect_mac_mgmt_msg_dcd_decoder(tvbuff_t *tvb, packet_info *pinfo, proto_tree *tree, void* data _U_)
{
guint offset = 0;
guint tvb_len, length;
gint tlv_type, tlv_len, tlv_offset, tlv_value_offset;
guint dl_burst_diuc, dl_num_regions;
proto_item *dcd_item, *tlv_item, *sub_item;
proto_tree *dcd_tree, *tlv_tree, *sub_tree;
tlv_info_t tlv_info;
gchar* proto_str;
{
tvb_len = tvb_reported_length(tvb);
dcd_item = proto_tree_add_protocol_format(tree, proto_mac_mgmt_msg_dcd_decoder, tvb, offset, tvb_len, "Downlink Channel Descriptor (DCD)");
dcd_tree = proto_item_add_subtree(dcd_item, ett_mac_mgmt_msg_dcd_decoder);
proto_tree_add_item(dcd_tree, hf_dcd_downlink_channel_id, tvb, offset, 1, ENC_BIG_ENDIAN);
offset++;
proto_tree_add_item(dcd_tree, hf_dcd_config_change_count, tvb, offset, 1, ENC_BIG_ENDIAN);
offset++;
while(offset < tvb_len)
{
init_tlv_info(&tlv_info, tvb, offset);
tlv_type = get_tlv_type(&tlv_info);
tlv_len = get_tlv_length(&tlv_info);
if(tlv_type == -1 || tlv_len > MAX_TLV_LEN || tlv_len < 1)
{
col_append_sep_str(pinfo->cinfo, COL_INFO, NULL, "DCD TLV error");
proto_tree_add_item(dcd_tree, hf_dcd_invalid_tlv, tvb, offset, (tvb_len - offset), ENC_NA);
break;
}
tlv_value_offset = get_tlv_value_offset(&tlv_info);
#ifdef DEBUG
proto_tree_add_protocol_format(dcd_tree, proto_mac_mgmt_msg_dcd_decoder, tvb, offset, (tlv_len + tlv_value_offset), "DCD Type: %u (%u bytes, offset=%u, tvb_len=%u)", tlv_type, tlv_len, offset, tvb_len);
#endif
offset += tlv_value_offset;
switch (tlv_type)
{
case DCD_DOWNLINK_BURST_PROFILE:
{
dl_burst_diuc = (tvb_get_guint8(tvb, offset) & 0x0F);
proto_str = wmem_strdup_printf(wmem_packet_scope(), "Downlink_Burst_Profile (DIUC=%u)", dl_burst_diuc);
tlv_tree = add_protocol_subtree(&tlv_info, ett_mac_mgmt_msg_dcd_decoder, dcd_tree, proto_mac_mgmt_msg_dcd_decoder, tvb, offset-tlv_value_offset, tlv_len, proto_str);
proto_tree_add_item(tlv_tree, hf_dcd_dl_burst_profile_rsv, tvb, offset, 1, ENC_BIG_ENDIAN);
proto_tree_add_item(tlv_tree, hf_dcd_dl_burst_profile_diuc, tvb, offset, 1, ENC_BIG_ENDIAN);
for (tlv_offset = 1; tlv_offset < tlv_len; )
{
init_tlv_info(&tlv_info, tvb, (offset+tlv_offset));
tlv_type = get_tlv_type(&tlv_info);
length = get_tlv_length(&tlv_info);
if(tlv_type == -1 || length > MAX_TLV_LEN || length < 1)
{
col_append_sep_str(pinfo->cinfo, COL_INFO, NULL, "DL Burst Profile TLV error");
proto_tree_add_item(tlv_tree, hf_dcd_invalid_tlv, tvb, offset, (tlv_len - offset - tlv_offset), ENC_NA);
break;
}
switch (tlv_type)
{
case DCD_BURST_FREQUENCY:
{
add_tlv_subtree(&tlv_info, tlv_tree, hf_dcd_burst_freq, tvb, (offset+tlv_offset), ENC_BIG_ENDIAN);
break;
}
case DCD_BURST_FEC_CODE_TYPE:
{
add_tlv_subtree(&tlv_info, tlv_tree, hf_dcd_burst_fec, tvb, (offset+tlv_offset), ENC_BIG_ENDIAN);
break;
}
case DCD_BURST_DIUC_EXIT_THRESHOLD:
{
add_tlv_subtree(&tlv_info, tlv_tree, hf_dcd_burst_diuc_exit_threshold, tvb, (offset+tlv_offset), ENC_BIG_ENDIAN);
break;
}
case DCD_BURST_DIUC_ENTRY_THRESHOLD:
{
add_tlv_subtree(&tlv_info, tlv_tree, hf_dcd_burst_diuc_entry_threshold, tvb, (offset+tlv_offset), ENC_BIG_ENDIAN);
break;
}
case DCD_BURST_TCS_ENABLE:
{
add_tlv_subtree(&tlv_info, tlv_tree, hf_dcd_burst_tcs, tvb, (offset+tlv_offset), ENC_BIG_ENDIAN);
break;
}
default:
break;
}
tlv_offset += (length+get_tlv_value_offset(&tlv_info));
}
break;
}
case DCD_BS_EIRP:
{
add_tlv_subtree(&tlv_info, dcd_tree, hf_dcd_bs_eirp, tvb, offset-tlv_value_offset, ENC_BIG_ENDIAN);
break;
}
case DCD_FRAME_DURATION:
{
add_tlv_subtree(&tlv_info, dcd_tree, hf_dcd_frame_duration, tvb, offset-tlv_value_offset, ENC_BIG_ENDIAN);
break;
}
case DCD_PHY_TYPE:
{
add_tlv_subtree(&tlv_info, dcd_tree, hf_dcd_phy_type, tvb, offset-tlv_value_offset, ENC_BIG_ENDIAN);
break;
}
case DCD_POWER_ADJUSTMENT:
{
add_tlv_subtree(&tlv_info, dcd_tree, hf_dcd_power_adjustment, tvb, offset-tlv_value_offset, ENC_BIG_ENDIAN);
break;
}
case DCD_CHANNEL_NR:
{
add_tlv_subtree(&tlv_info, dcd_tree, hf_dcd_channel_nr, tvb, offset-tlv_value_offset, ENC_BIG_ENDIAN);
break;
}
case DCD_TTG:
{
add_tlv_subtree(&tlv_info, dcd_tree, hf_dcd_ttg, tvb, offset-tlv_value_offset, ENC_BIG_ENDIAN);
break;
}
case DCD_RTG:
{
add_tlv_subtree(&tlv_info, dcd_tree, hf_dcd_rtg, tvb, offset-tlv_value_offset, ENC_BIG_ENDIAN);
break;
}
#ifdef WIMAX_16D_2004
case DCD_RSS:
{
add_tlv_subtree(&tlv_info, dcd_tree, hf_dcd_rss, tvb, offset-tlv_value_offset, ENC_BIG_ENDIAN);
break;
}
#else
case DCD_EIRXP:
{
add_tlv_subtree(&tlv_info, dcd_tree, hf_dcd_eirxp, tvb, offset-tlv_value_offset, ENC_BIG_ENDIAN);
break;
}
#endif
case DCD_CHANNEL_SWITCH_FRAME_NR:
{
add_tlv_subtree(&tlv_info, dcd_tree, hf_dcd_channel_switch_frame_nr, tvb, offset-tlv_value_offset, ENC_BIG_ENDIAN);
break;
}
case DCD_FREQUENCY:
{
add_tlv_subtree(&tlv_info, dcd_tree, hf_dcd_frequency, tvb, offset-tlv_value_offset, ENC_BIG_ENDIAN);
break;
}
case DCD_BS_ID:
{
add_tlv_subtree(&tlv_info, dcd_tree, hf_dcd_bs_id, tvb, offset-tlv_value_offset, ENC_BIG_ENDIAN);
break;
}
case DCD_FRAME_DURATION_CODE:
{
add_tlv_subtree(&tlv_info, dcd_tree, hf_dcd_frame_duration_code, tvb, offset-tlv_value_offset, ENC_BIG_ENDIAN);
break;
}
case DCD_FRAME_NR:
{
add_tlv_subtree(&tlv_info, dcd_tree, hf_dcd_frame_nr, tvb, offset-tlv_value_offset, ENC_BIG_ENDIAN);
break;
}
#ifdef WIMAX_16D_2004
case DCD_SIZE_CQICH_ID:
{
add_tlv_subtree(&tlv_info, dcd_tree, hf_dcd_size_cqich_id, tvb, offset-tlv_value_offset, ENC_BIG_ENDIAN);
break;
}
#endif
case DCD_H_ARQ_ACK_DELAY:
{
add_tlv_subtree(&tlv_info, dcd_tree, hf_dcd_h_arq_ack_delay, tvb, offset-tlv_value_offset, ENC_BIG_ENDIAN);
break;
}
case DCD_MAC_VERSION:
{
add_tlv_subtree(&tlv_info, dcd_tree, hf_dcd_mac_version, tvb, offset-tlv_value_offset, ENC_BIG_ENDIAN);
break;
}
case DCD_TLV_T_19_PERMUTATION_TYPE_FOR_BROADCAST_REGION_IN_HARQ_ZONE:
{
add_tlv_subtree(&tlv_info, dcd_tree, hf_dcd_tlv_t_19_permutation_type_for_broadcast_regions_in_harq_zone, tvb, offset-tlv_value_offset, ENC_BIG_ENDIAN);
break;
}
case DCD_TLV_T_20_MAXIMUM_RETRANSMISSION:
{
add_tlv_subtree(&tlv_info, dcd_tree, hf_dcd_tlv_t_20_maximum_retransmission, tvb, offset-tlv_value_offset, ENC_BIG_ENDIAN);
break;
}
case DCD_TLV_T_21_DEFAULT_RSSI_AND_CINR_AVERAGING_PARAMETER:
{
tlv_item = add_tlv_subtree(&tlv_info, dcd_tree, hf_dcd_tlv_t_21_default_rssi_and_cinr_averaging_parameter, tvb, offset-tlv_value_offset, ENC_BIG_ENDIAN);
tlv_tree = proto_item_add_subtree(tlv_item, ett_mac_mgmt_msg_dcd_decoder);
proto_tree_add_item(tlv_tree, hf_dcd_tlv_t_21_default_rssi_and_cinr_averaging_parameter_physical_cinr_measurements, tvb, offset, 1, ENC_BIG_ENDIAN);
proto_tree_add_item(tlv_tree, hf_dcd_tlv_t_21_default_rssi_and_cinr_averaging_parameter_rssi_measurements, tvb, offset, 1, ENC_BIG_ENDIAN);
break;
}
case DCD_TLV_T_22_DL_AMC_ALLOCATED_PHYSICAL_BANDS_BITMAP:
{
add_tlv_subtree(&tlv_info, dcd_tree, hf_dcd_tlv_t_22_dl_amc_allocated_physical_bands_bitmap, tvb, offset-tlv_value_offset, ENC_NA);
break;
}
case DCD_TLV_T_34_DL_REGION_DEFINITION:
{
tlv_item = add_tlv_subtree(&tlv_info, dcd_tree, hf_dcd_tlv_t_34_dl_region_definition, tvb, offset-tlv_value_offset, ENC_NA);
tlv_tree = proto_item_add_subtree(tlv_item, ett_mac_mgmt_msg_dcd_decoder);
dl_num_regions = tvb_get_guint8(tvb, offset);
proto_tree_add_item(tlv_tree, hf_dcd_tlv_t_34_dl_region_definition_num_region, tvb, offset, 1, ENC_BIG_ENDIAN);
proto_tree_add_item(tlv_tree, hf_dcd_tlv_t_34_dl_region_definition_reserved, tvb, offset, 1, ENC_BIG_ENDIAN);
tlv_offset = offset;
for(length = 0; length < dl_num_regions; length++)
{
proto_tree_add_item(tlv_tree, hf_dcd_tlv_t_34_dl_region_definition_symbol_offset, tvb, tlv_offset, 1, ENC_BIG_ENDIAN);
proto_tree_add_item(tlv_tree, hf_dcd_tlv_t_34_dl_region_definition_subchannel_offset, tvb, (tlv_offset+1), 1, ENC_BIG_ENDIAN);
proto_tree_add_item(tlv_tree, hf_dcd_tlv_t_34_dl_region_definition_num_symbols, tvb, (tlv_offset+2), 1, ENC_BIG_ENDIAN);
proto_tree_add_item(tlv_tree, hf_dcd_tlv_t_34_dl_region_definition_num_subchannels, tvb, (tlv_offset+3), 1, ENC_BIG_ENDIAN);
tlv_offset += 4;
}
break;
}
case DCD_TLV_T_50_HO_TYPE_SUPPORT:
{
tlv_item = add_tlv_subtree(&tlv_info, dcd_tree, hf_dcd_tlv_t_50_ho_type_support, tvb, offset-tlv_value_offset, ENC_BIG_ENDIAN);
tlv_tree = proto_item_add_subtree(tlv_item, ett_mac_mgmt_msg_dcd_decoder);
proto_tree_add_item(tlv_tree, hf_dcd_tlv_t_50_ho_type_support_ho, tvb, offset, 1, ENC_BIG_ENDIAN);
proto_tree_add_item(tlv_tree, hf_dcd_tlv_t_50_ho_type_support_mdho, tvb, offset, 1, ENC_BIG_ENDIAN);
proto_tree_add_item(tlv_tree, hf_dcd_tlv_t_50_ho_type_support_fbss_ho, tvb, offset, 1, ENC_BIG_ENDIAN);
proto_tree_add_item(tlv_tree, hf_dcd_tlv_t_50_ho_type_support_reserved, tvb, offset, 1, ENC_BIG_ENDIAN);
break;
}
case DCD_TLV_T_31_H_ADD_THRESHOLD:
{
add_tlv_subtree(&tlv_info, dcd_tree, hf_dcd_tlv_t_31_h_add_threshold, tvb, offset-tlv_value_offset, ENC_BIG_ENDIAN);
break;
}
case DCD_TLV_T_32_H_DELETE_THRESHOLD:
{
add_tlv_subtree(&tlv_info, dcd_tree, hf_dcd_tlv_t_32_h_delete_threshold, tvb, offset-tlv_value_offset, ENC_BIG_ENDIAN);
break;
}
case DCD_TLV_T_33_ASR:
{
tlv_item = add_tlv_subtree(&tlv_info, dcd_tree, hf_dcd_tlv_t_33_asr, tvb, offset-tlv_value_offset, ENC_BIG_ENDIAN);
tlv_tree = proto_item_add_subtree(tlv_item, ett_mac_mgmt_msg_dcd_decoder);
proto_tree_add_item(tlv_tree, hf_dcd_tlv_t_33_asr_m, tvb, offset, 1, ENC_BIG_ENDIAN);
proto_tree_add_item(tlv_tree, hf_dcd_tlv_t_33_asr_l, tvb, offset, 1, ENC_BIG_ENDIAN);
break;
}
case DCD_TLV_T_35_PAGING_GROUP_ID:
{
add_tlv_subtree(&tlv_info, dcd_tree, hf_dcd_tlv_t_35_paging_group_id, tvb, offset-tlv_value_offset, ENC_BIG_ENDIAN);
break;
}
case DCD_TLV_T_36_TUSC1_PERMUTATION_ACTIVE_SUBCHANNELS_BITMAP:
{
add_tlv_subtree(&tlv_info, dcd_tree, hf_dcd_tlv_t_36_tusc1_permutation_active_subchannels_bitmap, tvb, offset-tlv_value_offset, ENC_BIG_ENDIAN);
break;
}
case DCD_TLV_T_37_TUSC2_PERMUTATION_ACTIVE_SUBCHANNELS_BITMAP:
{
add_tlv_subtree(&tlv_info, dcd_tree, hf_dcd_tlv_t_37_tusc2_permutation_active_subchannels_bitmap, tvb, offset-tlv_value_offset, ENC_BIG_ENDIAN);
break;
}
case DCD_TLV_T_51_HYSTERSIS_MARGIN:
{
add_tlv_subtree(&tlv_info, dcd_tree, hf_dcd_tlv_t_51_hysteresis_margin, tvb, offset-tlv_value_offset, ENC_BIG_ENDIAN);
break;
}
case DCD_TLV_T_52_TIME_TO_TRIGGER_DURATION:
{
add_tlv_subtree(&tlv_info, dcd_tree, hf_dcd_tlv_t_52_time_to_trigger_duration, tvb, offset-tlv_value_offset, ENC_BIG_ENDIAN);
break;
}
case DCD_TLV_T_54_TRIGGER:
{
tlv_tree = add_protocol_subtree(&tlv_info, ett_mac_mgmt_msg_dcd_decoder, dcd_tree, proto_mac_mgmt_msg_dcd_decoder, tvb, offset-tlv_value_offset, tlv_len, "DCD Trigger");
for (tlv_offset = 0; tlv_offset < tlv_len; )
{
init_tlv_info(&tlv_info, tvb, (offset + tlv_offset));
tlv_type = get_tlv_type(&tlv_info);
length = get_tlv_length(&tlv_info);
if(tlv_type == -1 || length > MAX_TLV_LEN || length < 1)
{
col_append_sep_str(pinfo->cinfo, COL_INFO, NULL, "Trigger TLV error");
proto_tree_add_item(tlv_tree, hf_dcd_invalid_tlv, tvb, offset, (tlv_len - offset - tlv_offset), ENC_NA);
break;
}
tlv_offset += get_tlv_value_offset(&tlv_info);
switch (tlv_type)
{
case DCD_TLV_T_541_TYPE_FUNCTION_ACTION:
{
sub_item = add_tlv_subtree(&tlv_info, tlv_tree, hf_dcd_tlv_t_541_type_function_action, tvb, (offset + tlv_offset)-get_tlv_value_offset(&tlv_info), ENC_BIG_ENDIAN);
sub_tree = proto_item_add_subtree(sub_item, ett_mac_mgmt_msg_dcd_decoder);
proto_tree_add_item(sub_tree, hf_dcd_tlv_t_541_type, tvb, (offset + tlv_offset), 1, ENC_BIG_ENDIAN);
proto_tree_add_item(sub_tree, hf_dcd_tlv_t_541_function, tvb, (offset + tlv_offset), 1, ENC_BIG_ENDIAN);
proto_tree_add_item(sub_tree, hf_dcd_tlv_t_541_action, tvb, (offset + tlv_offset), 1, ENC_BIG_ENDIAN);
}
break;
case DCD_TLV_T542_TRIGGER_VALUE:
add_tlv_subtree(&tlv_info, tlv_tree, hf_dcd_tlv_t_542_trigger_value, tvb, (offset + tlv_offset)-get_tlv_value_offset(&tlv_info), ENC_BIG_ENDIAN);
break;
case DCD_TLV_T_543_TRIGGER_AVERAGING_DURATION:
add_tlv_subtree(&tlv_info, tlv_tree, hf_dcd_tlv_t_543_trigger_averaging_duration, tvb, (offset + tlv_offset)-get_tlv_value_offset(&tlv_info), ENC_BIG_ENDIAN);
break;
}
tlv_offset += length;
}
break;
}
case DCD_TLV_T_60_NOISE_AND_INTERFERENCE:
{
add_tlv_subtree(&tlv_info, dcd_tree, hf_dcd_tlv_t_60_noise_interference, tvb, offset-tlv_value_offset, ENC_BIG_ENDIAN);
break;
}
case DCD_TLV_T_153_DOWNLINK_BURST_PROFILE_FOR_MULTIPLE_FEC_TYPES:
{
add_tlv_subtree(&tlv_info, dcd_tree, hf_dcd_tlv_t_153_downlink_burst_profile_for_mutiple_fec_types, tvb, offset-tlv_value_offset, ENC_BIG_ENDIAN);
break;
}
case DCD_RESTART_COUNT:
{
add_tlv_subtree(&tlv_info, dcd_tree, hf_dcd_restart_count, tvb, offset-tlv_value_offset, ENC_BIG_ENDIAN);
break;
}
case DCD_TLV_T_45_PAGING_INTERVAL_LENGTH:
{
if (include_cor2_changes) {
add_tlv_subtree(&tlv_info, dcd_tree, hf_dcd_tlv_t_45_paging_interval_reserved, tvb, offset-tlv_value_offset, ENC_NA);
} else {
add_tlv_subtree(&tlv_info, dcd_tree, hf_dcd_tlv_t_45_paging_interval_length, tvb, offset-tlv_value_offset, ENC_BIG_ENDIAN);
}
break;
}
default:
{
add_tlv_subtree(&tlv_info, dcd_tree, hf_dcd_unknown_type, tvb, offset-tlv_value_offset, ENC_NA);
break;
}
}
offset += tlv_len;
}
}
return tvb_captured_length(tvb);
}
void proto_register_mac_mgmt_msg_dcd(void)
{
static hf_register_info hf[] =
{
{
&hf_dcd_tlv_t_33_asr,
{
"ASR (Anchor Switch Report) Slot Length (M) and Switching Period (L)", "wmx.dcd.asr",
FT_UINT8, BASE_HEX, NULL, 0x0, NULL, HFILL
}
},
{
&hf_dcd_tlv_t_33_asr_l,
{
"ASR Switching Period (L)", "wmx.dcd.asr.l",
FT_UINT8, BASE_DEC|BASE_UNIT_STRING, &wimax_units_frame_frames, 0x0f, NULL, HFILL
}
},
{
&hf_dcd_tlv_t_33_asr_m,
{
"ASR Slot Length (M)", "wmx.dcd.asr.m",
FT_UINT8, BASE_DEC|BASE_UNIT_STRING, &wimax_units_frame_frames, 0xf0, NULL, HFILL
}
},
{
&hf_dcd_bs_eirp,
{
"BS EIRP", "wmx.dcd.bs_eirp",
FT_INT16, BASE_DEC|BASE_UNIT_STRING, &wimax_units_dbm, 0x00, NULL, HFILL
}
},
{
&hf_dcd_bs_id,
{
"Base Station ID", "wmx.dcd.bs_id",
FT_ETHER, BASE_NONE, NULL, 0x00, NULL, HFILL
}
},
{
&hf_dcd_restart_count,
{
"BS Restart Count", "wmx.dcd.bs_restart_count",
FT_UINT8, BASE_DEC, NULL, 0x00, NULL, HFILL
}
},
#if 0
{
&hf_dl_burst_diuc,
{
"DIUC", "wmx.dcd.burst.diuc",
FT_UINT8, BASE_DEC, NULL, 0x0F, NULL, HFILL
}
},
#endif
{
&hf_dcd_burst_diuc_entry_threshold,
{
"DIUC Minimum Entry Threshold (in 0.25 dB units)", "wmx.dcd.burst.diuc_entry_threshold",
FT_FLOAT, BASE_NONE, NULL, 0x00, NULL, HFILL
}
},
{
&hf_dcd_burst_diuc_exit_threshold,
{
"DIUC Mandatory Exit Threshold (in 0.25 dB units)", "wmx.dcd.burst.diuc_exit_threshold",
FT_FLOAT, BASE_NONE, NULL, 0x00, NULL, HFILL
}
},
{
&hf_dcd_burst_fec,
{
"FEC Code Type", "wmx.dcd.burst.fec",
FT_UINT8, BASE_DEC, VALS(vals_dcd_burst_fec_ofdma), 0x00, NULL, HFILL
}
},
{
&hf_dcd_burst_freq,
{
"Frequency", "wmx.dcd.burst.freq",
FT_UINT8, BASE_DEC|BASE_UNIT_STRING, &wimax_units_khz, 0x00, NULL, HFILL
}
},
#if 0
{
&hf_dl_burst_reserved,
{
"Reserved", "wmx.dcd.burst.reserved",
FT_UINT8, BASE_HEX, NULL, 0xF0, NULL, HFILL
}
},
#endif
{
&hf_dcd_burst_tcs,
{
"TCS", "wmx.dcd.burst.tcs",
FT_UINT8, BASE_DEC, VALS(vals_dcd_burst_tcs), 0x00, NULL, HFILL
}
},
{
&hf_dcd_channel_nr,
{
"Channel Nr", "wmx.dcd.channel_nr",
FT_UINT8, BASE_DEC, NULL, 0x00, NULL, HFILL
}
},
{
&hf_dcd_config_change_count,
{
"Configuration Change Count", "wmx.dcd.config_change_count",
FT_UINT8, BASE_DEC, NULL, 0x0, NULL, HFILL
}
},
{
&hf_dcd_tlv_t_21_default_rssi_and_cinr_averaging_parameter_physical_cinr_measurements,
{
"Default Averaging Parameter for Physical CINR Measurements (in multiples of 1/16)", "wmx.dcd.default_physical_cinr_meas_averaging_parameter",
FT_UINT8, BASE_HEX, NULL, 0xf0, NULL, HFILL
}
},
{
&hf_dcd_tlv_t_21_default_rssi_and_cinr_averaging_parameter,
{
"Default RSSI and CINR Averaging Parameter", "wmx.dcd.default_rssi_and_cinr_averaging_parameter",
FT_UINT8, BASE_HEX, NULL, 0x00, NULL, HFILL
}
},
{
&hf_dcd_tlv_t_21_default_rssi_and_cinr_averaging_parameter_rssi_measurements,
{
"Default Averaging Parameter for RSSI Measurements (in multiples of 1/16)", "wmx.dcd.default_rssi_meas_averaging_parameter",
FT_UINT8, BASE_HEX, NULL, 0x0f, NULL, HFILL
}
},
{
&hf_dcd_tlv_t_22_dl_amc_allocated_physical_bands_bitmap,
{
"DL AMC Allocated Physical Bands Bitmap", "wmx.dcd.dl_amc_allocated_phy_bands_bitmap",
FT_BYTES, BASE_NONE, NULL, 0x0, NULL, HFILL
}
},
{
&hf_dcd_dl_burst_profile_diuc,
{
"DIUC", "wmx.dcd.dl_burst_profile_diuc",
FT_UINT8, BASE_DEC, VALS(diuc_msgs), 0x0F, NULL, HFILL
}
},
{
&hf_dcd_dl_burst_profile_rsv,
{
"Reserved", "wmx.dcd.dl_burst_profile_rsv",
FT_UINT8, BASE_DEC, NULL, 0xF0, NULL, HFILL
}
},
{
&hf_dcd_downlink_channel_id,
{
"Reserved", "wmx.dcd.dl_channel_id",
FT_UINT8, BASE_DEC, NULL, 0x0, NULL, HFILL
}
},
{
&hf_dcd_tlv_t_153_downlink_burst_profile_for_mutiple_fec_types,
{
"Downlink Burst Profile for Multiple FEC Types","wimax.dcd.dl_burst_profile_multiple_fec_types",
FT_UINT8, BASE_HEX, NULL, 0x0, NULL, HFILL
}
},
{
&hf_dcd_tlv_t_34_dl_region_definition,
{
"DL Region Definition", "wmx.dcd.dl_region_definition",
FT_BYTES, BASE_NONE, NULL, 0x00, NULL, HFILL
}
},
{
&hf_dcd_tlv_t_34_dl_region_definition_num_region,
{
"Number of Regions", "wmx.dcd.dl_region_definition.num_region",
FT_UINT8, BASE_DEC, NULL, 0xFC, NULL, HFILL
}
},
{
&hf_dcd_tlv_t_34_dl_region_definition_num_subchannels,
{
"Number of Subchannels", "wmx.dcd.dl_region_definition.num_subchannels",
FT_UINT8, BASE_HEX, NULL, 0x00, NULL, HFILL
}
},
{
&hf_dcd_tlv_t_34_dl_region_definition_num_symbols,
{
"Number of OFDMA Symbols", "wmx.dcd.dl_region_definition.num_symbols",
FT_UINT8, BASE_HEX, NULL, 0x00, NULL, HFILL
}
},
{
&hf_dcd_tlv_t_34_dl_region_definition_reserved,
{
"Reserved", "wmx.dcd.dl_region_definition.reserved",
FT_UINT8, BASE_DEC, NULL, 0x03, NULL, HFILL
}
},
{
&hf_dcd_tlv_t_34_dl_region_definition_subchannel_offset,
{
"Subchannel Offset", "wmx.dcd.dl_region_definition.subchannel_offset",
FT_UINT8, BASE_HEX, NULL, 0x00, NULL, HFILL
}
},
{
&hf_dcd_tlv_t_34_dl_region_definition_symbol_offset,
{
"OFDMA Symbol Offset", "wmx.dcd.dl_region_definition.symbol_offset",
FT_UINT8, BASE_HEX, NULL, 0x00, NULL, HFILL
}
},
#ifndef WIMAX_16D_2004
{
&hf_dcd_eirxp,
{
"EIRXP (IR, max)", "wmx.dcd.eirxp",
FT_INT16, BASE_DEC|BASE_UNIT_STRING, &wimax_units_dbm, 0x00, NULL, HFILL
}
},
#endif
{
&hf_dcd_frame_duration,
{
"Frame Duration", "wmx.dcd.frame_duration",
FT_UINT32, BASE_HEX, NULL, 0x00, NULL, HFILL
}
},
{
&hf_dcd_frame_duration_code,
{
"Frame Duration Code", "wmx.dcd.frame_duration_code",
FT_UINT8, BASE_HEX, VALS(vals_dcd_frame_duration), 0x00, NULL, HFILL
}
},
{
&hf_dcd_frame_nr,
{
"Frame Number", "wmx.dcd.frame_nr",
FT_UINT24, BASE_DEC, NULL, 0x00, NULL, HFILL
}
},
{
&hf_dcd_frequency,
{
"Downlink Center Frequency", "wmx.dcd.frequency",
FT_UINT32, BASE_DEC|BASE_UNIT_STRING, &wimax_units_khz, 0x00, NULL, HFILL
}
},
{
&hf_dcd_tlv_t_31_h_add_threshold,
{
"H_add Threshold", "wmx.dcd.h_add_threshold",
FT_UINT8, BASE_DEC|BASE_UNIT_STRING, &wimax_units_db, 0x0, NULL, HFILL
}
},
#ifdef WIMAX_16D_2004
{
&hf_dcd_h_arq_ack_delay,
{
"H-ARQ ACK Delay for DL Burst", "wmx.dcd.h_arq_ack_delay_dl_burst",
FT_UINT8, BASE_DEC|BASE_UNIT_STRING, &wimax_units_frame_offset, 0x00, "", HFILL
}
},
#else
{
&hf_dcd_h_arq_ack_delay,
{
"H-ARQ ACK Delay for UL Burst", "wmx.dcd.h_arq_ack_delay_ul_burst",
FT_UINT8, BASE_DEC|BASE_UNIT_STRING, &wimax_units_frame_offset, 0x00, NULL, HFILL
}
},
#endif
{
&hf_dcd_tlv_t_32_h_delete_threshold,
{
"H_delete Threshold", "wmx.dcd.h_delete_threshold",
FT_UINT8, BASE_DEC|BASE_UNIT_STRING, &wimax_units_db, 0x0, NULL, HFILL
}
},
{
&hf_dcd_tlv_t_50_ho_type_support,
{
"HO Type Support", "wmx.dcd.ho_type_support",
FT_UINT8, BASE_HEX, NULL, 0x00, NULL, HFILL
}
},
{
&hf_dcd_tlv_t_50_ho_type_support_fbss_ho,
{
"FBSS HO", "wmx.dcd.ho_type_support.fbss_ho",
FT_UINT8, BASE_HEX, VALS(tfs_support), 0x20, NULL, HFILL
}
},
{
&hf_dcd_tlv_t_50_ho_type_support_ho,
{
"HO", "wmx.dcd.ho_type_support.ho",
FT_UINT8, BASE_HEX, VALS(tfs_support), 0x80, NULL, HFILL
}
},
{
&hf_dcd_tlv_t_50_ho_type_support_mdho,
{
"MDHO", "wmx.dcd.ho_type_support.mdho",
FT_UINT8, BASE_HEX, VALS(tfs_support), 0x40, NULL, HFILL
}
},
{
&hf_dcd_tlv_t_50_ho_type_support_reserved,
{
"Reserved", "wmx.dcd.ho_type_support.reserved",
FT_UINT8, BASE_HEX, NULL, 0x1f, NULL, HFILL
}
},
{
&hf_dcd_tlv_t_51_hysteresis_margin,
{
"Hysteresis Margin", "wmx.dcd.hysteresis_margin",
FT_UINT8, BASE_DEC|BASE_UNIT_STRING, &wimax_units_db, 0x0, NULL, HFILL
}
},
{
&hf_dcd_invalid_tlv,
{
"Invalid TLV", "wmx.dcd.invalid_tlv",
FT_BYTES, BASE_NONE, NULL, 0, NULL, HFILL
}
},
{
&hf_dcd_mac_version,
{
"MAC Version", "wmx.dcd.mac_version",
FT_UINT8, BASE_DEC, VALS(vals_dcd_mac_version), 0x00, NULL, HFILL
}
},
{
&hf_dcd_tlv_t_20_maximum_retransmission,
{
"Maximum Retransmission", "wmx.dcd.maximum_retransmission",
FT_UINT8, BASE_DEC, NULL, 0x00, NULL, HFILL
}
},
{
&hf_dcd_tlv_t_60_noise_interference,
{
"Noise and Interference", "wmx.dcd.noise_interference",
FT_UINT8, BASE_HEX, NULL, 0x0, NULL, HFILL
}
},
{
&hf_dcd_tlv_t_35_paging_group_id,
{
"Paging Group ID", "wmx.dcd.paging_group_id",
FT_UINT16, BASE_HEX, NULL, 0x0, NULL, HFILL
}
},
{
&hf_dcd_tlv_t_36_tusc1_permutation_active_subchannels_bitmap,
{
"TUSC1 permutation active subchannels bitmap", "wmx.dcd.tusc1",
FT_UINT16, BASE_HEX, NULL, 0xFF80, NULL, HFILL
}
},
{
&hf_dcd_tlv_t_37_tusc2_permutation_active_subchannels_bitmap,
{
"TUSC2 permutation active subchannels bitmap", "wmx.dcd.tusc2",
FT_UINT16, BASE_HEX, NULL, 0xFFF8, NULL, HFILL
}
},
{
&hf_dcd_tlv_t_45_paging_interval_length,
{
"Paging Interval Length", "wmx.dcd.paging_interval_length",
FT_UINT8, BASE_DEC, NULL, 0x0, NULL, HFILL
}
},
{
&hf_dcd_tlv_t_45_paging_interval_reserved,
{
"Reserved", "wmx.dcd.paging_interval_reserved",
FT_BYTES, BASE_NONE, NULL, 0x0, NULL, HFILL
}
},
{
&hf_dcd_tlv_t_19_permutation_type_for_broadcast_regions_in_harq_zone,
{
"Permutation Type for Broadcast Region in HARQ Zone", "wmx.dcd.permutation_type_broadcast_region_in_harq_zone",
FT_UINT8, BASE_DEC, VALS(vals_dcd_permutation_type), 0x00, NULL, HFILL
}
},
{
&hf_dcd_phy_type,
{
"PHY Type", "wmx.dcd.phy_type",
FT_UINT8, BASE_HEX, NULL, 0x00, NULL, HFILL
}
},
{
&hf_dcd_power_adjustment,
{
"Power Adjustment Rule", "wmx.dcd.power_adjustment",
FT_UINT8, BASE_HEX, VALS(vals_dcd_power_adjustmnt), 0x00, NULL, HFILL
}
},
#ifdef WIMAX_16D_2004
{
&hf_dcd_rss,
{
"RSS (IR, max)", "wmx.dcd.rss",
FT_INT16, BASE_DEC|BASE_UNIT_STRING, &wimax_units_dbm, 0x00, "", HFILL
}
},
#endif
{
&hf_dcd_rtg,
{
"RTG", "wmx.dcd.rtg",
FT_UINT8, BASE_HEX|BASE_UNIT_STRING, &wimax_units_ps, 0x00, NULL, HFILL
}
},
#ifdef WIMAX_16D_2004
{
&hf_dcd_size_cqich_id,
{
"Size of CQICH-ID Field", "wmx.dcd.size_cqich_id",
FT_UINT8, BASE_DEC, VALS(vals_dcd_size_of_cqich_id), 0x00, "", HFILL
}
},
#endif
{
&hf_dcd_channel_switch_frame_nr,
{
"Channel Switch Frame Number", "wmx.dcd.switch_frame",
FT_UINT24, BASE_DEC, NULL, 0x00, NULL, HFILL
}
},
{
&hf_dcd_tlv_t_52_time_to_trigger_duration,
{
"Time to Trigger Duration", "wmx.dcd.time_trigger_duration",
FT_UINT8, BASE_DEC|BASE_UNIT_STRING, &wimax_units_ms, 0x0, NULL, HFILL
}
},
{
&hf_dcd_tlv_t_543_trigger_averaging_duration,
{
"Trigger Averaging Duration", "wmx.dcd.trigger_averaging_duration",
FT_UINT8, BASE_DEC, NULL, 0x0, NULL, HFILL
}
},
{
&hf_dcd_tlv_t_542_trigger_value,
{
"Trigger Value", "wmx.dcd.trigger_value",
FT_UINT8, BASE_DEC, NULL, 0x0, NULL, HFILL
}
},
{
&hf_dcd_ttg,
{
"TTG", "wmx.dcd.ttg",
FT_UINT16, BASE_HEX|BASE_UNIT_STRING, &wimax_units_ps, 0x00, NULL, HFILL
}
},
{
&hf_dcd_tlv_t_541_type_function_action,
{
"Type/Function/Action", "wmx.dcd.type_function_action",
FT_UINT8, BASE_HEX, NULL, 0x0, NULL, HFILL
}
},
{
&hf_dcd_tlv_t_541_action,
{
"Action", "wmx.dcd.type_function_action.action",
FT_UINT8, BASE_HEX, VALS(vals_dcd_action), 0x7, NULL, HFILL
}
},
{
&hf_dcd_tlv_t_541_function,
{
"Function", "wmx.dcd.type_function_action.function",
FT_UINT8, BASE_HEX, VALS(vals_dcd_function), 0x38, NULL, HFILL
}
},
{
&hf_dcd_tlv_t_541_type,
{
"Type", "wmx.dcd.type_function_action.type",
FT_UINT8, BASE_HEX, VALS(vals_dcd_type), 0xC0, NULL, HFILL
}
},
{
&hf_dcd_unknown_type,
{
"Unknown DCD Type", "wmx.dcd.unknown_tlv_value",
FT_BYTES, BASE_NONE, NULL, 0x0, NULL, HFILL
}
}
};
static gint *ett[] =
{
&ett_mac_mgmt_msg_dcd_decoder,
};
proto_mac_mgmt_msg_dcd_decoder = proto_register_protocol (
"WiMax DCD Messages",
"WiMax DCD",
"wmx.dcd"
);
proto_register_field_array(proto_mac_mgmt_msg_dcd_decoder, hf, array_length(hf));
proto_register_subtree_array(ett, array_length(ett));
}
void proto_reg_handoff_mac_mgmt_msg_dcd(void)
{
dissector_handle_t dcd_handle;
dcd_handle = create_dissector_handle(dissect_mac_mgmt_msg_dcd_decoder, proto_mac_mgmt_msg_dcd_decoder);
dissector_add_uint("wmx.mgmtmsg", MAC_MGMT_MSG_DCD, dcd_handle);
}
