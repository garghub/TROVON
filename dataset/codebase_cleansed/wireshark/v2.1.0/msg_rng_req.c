void dissect_power_saving_class(proto_tree *rng_req_tree, gint tlv_type, tvbuff_t *tvb, guint compound_tlv_len, packet_info *pinfo, guint offset)
{
proto_item *tlv_item;
proto_tree *tlv_tree;
proto_tree *power_saving_class_tree = NULL;
guint tlv_len;
guint tlv_offset;
tlv_info_t tlv_info;
tlv_item = proto_tree_add_protocol_format(rng_req_tree, proto_mac_mgmt_msg_rng_req_decoder, tvb, offset, compound_tlv_len, "Power saving class parameters (%u bytes)", compound_tlv_len);
power_saving_class_tree = proto_item_add_subtree(tlv_item, ett_mac_mgmt_msg_rng_req_decoder);
compound_tlv_len += offset;
while(offset < compound_tlv_len)
{
init_tlv_info(&tlv_info, tvb, offset);
tlv_type = get_tlv_type(&tlv_info);
tlv_len = get_tlv_length(&tlv_info);
if(tlv_type == -1 || tlv_len > MAX_TLV_LEN || tlv_len < 1)
{
col_append_sep_str(pinfo->cinfo, COL_INFO, NULL, "RNG-REQ TLV error");
proto_tree_add_item(power_saving_class_tree, hf_rng_invalid_tlv, tvb, offset, (compound_tlv_len - offset), ENC_NA);
break;
}
tlv_offset = offset + get_tlv_value_offset(&tlv_info);
switch (tlv_type) {
case RNG_POWER_SAVING_CLASS_FLAGS:
tlv_item = add_tlv_subtree(&tlv_info, power_saving_class_tree, hf_rng_power_saving_class_flags, tvb, offset, ENC_BIG_ENDIAN);
tlv_tree = proto_item_add_subtree(tlv_item, ett_mac_mgmt_msg_rng_req_decoder);
proto_tree_add_item(tlv_tree, hf_rng_definition_of_power_saving_class_present, tvb, tlv_offset, 1, ENC_BIG_ENDIAN);
proto_tree_add_item(tlv_tree, hf_rng_activation_of_power_saving_class, tvb, tlv_offset, 1, ENC_BIG_ENDIAN);
proto_tree_add_item(tlv_tree, hf_rng_trf_ind_required, tvb, tlv_offset, 1, ENC_BIG_ENDIAN);
proto_tree_add_item(tlv_tree, hf_rng_power_saving_class_reserved, tvb, tlv_offset, 1, ENC_BIG_ENDIAN);
break;
case RNG_POWER_SAVING_CLASS_ID:
add_tlv_subtree(&tlv_info, power_saving_class_tree, hf_rng_power_saving_class_id, tvb, offset, ENC_BIG_ENDIAN);
break;
case RNG_POWER_SAVING_CLASS_TYPE:
add_tlv_subtree(&tlv_info, power_saving_class_tree, hf_rng_power_saving_class_type, tvb, offset, ENC_BIG_ENDIAN);
break;
case RNG_START_FRAME_NUMBER:
add_tlv_subtree(&tlv_info, power_saving_class_tree, hf_rng_power_saving_first_sleep_window_frame, tvb, offset, ENC_BIG_ENDIAN);
break;
case RNG_INITIAL_SLEEP_WINDOW:
add_tlv_subtree(&tlv_info, power_saving_class_tree, hf_rng_power_saving_initial_sleep_window, tvb, offset, ENC_BIG_ENDIAN);
break;
case RNG_LISTENING_WINDOW:
add_tlv_subtree(&tlv_info, power_saving_class_tree, hf_rng_power_saving_listening_window, tvb, offset, ENC_BIG_ENDIAN);
break;
case RNG_FINAL_SLEEP_WINDOW_BASE:
add_tlv_subtree(&tlv_info, power_saving_class_tree, hf_rng_power_saving_final_sleep_window_base, tvb, offset, ENC_BIG_ENDIAN);
break;
case RNG_FINAL_SLEEP_WINDOW_EXPONENT:
add_tlv_subtree(&tlv_info, power_saving_class_tree, hf_rng_power_saving_final_sleep_window_exp, tvb, offset, ENC_BIG_ENDIAN);
break;
case RNG_SLPID:
add_tlv_subtree(&tlv_info, power_saving_class_tree, hf_rng_power_saving_slpid, tvb, offset, ENC_BIG_ENDIAN);
break;
case RNG_CID:
add_tlv_subtree(&tlv_info, power_saving_class_tree, hf_rng_power_saving_included_cid, tvb, offset, ENC_BIG_ENDIAN);
break;
case RNG_DIRECTION:
add_tlv_subtree(&tlv_info, power_saving_class_tree, hf_rng_power_saving_mgmt_connection_direction, tvb, offset, ENC_BIG_ENDIAN);
break;
default:
add_tlv_subtree(&tlv_info, power_saving_class_tree, hf_tlv_type, tvb, offset, ENC_NA);
break;
}
offset = tlv_len + tlv_offset;
}
}
static int dissect_mac_mgmt_msg_rng_req_decoder(tvbuff_t *tvb, packet_info *pinfo, proto_tree *tree, void* data _U_)
{
guint offset = 0;
guint tlv_offset;
guint tvb_len;
proto_item *rng_req_item, *tlv_item;
proto_tree *rng_req_tree, *tlv_tree;
tlv_info_t tlv_info;
gint tlv_type;
gint tlv_len;
{
tvb_len = tvb_reported_length(tvb);
rng_req_item = proto_tree_add_protocol_format(tree, proto_mac_mgmt_msg_rng_req_decoder, tvb, offset, tvb_len, "MAC Management Message, RNG-REQ");
rng_req_tree = proto_item_add_subtree(rng_req_item, ett_mac_mgmt_msg_rng_req_decoder);
proto_tree_add_item(rng_req_tree, hf_rng_req_reserved, tvb, 0, 1, ENC_BIG_ENDIAN);
offset += 1;
while(offset < tvb_len)
{
init_tlv_info(&tlv_info, tvb, offset);
tlv_type = get_tlv_type(&tlv_info);
tlv_len = get_tlv_length(&tlv_info);
if(tlv_type == -1 || tlv_len > MAX_TLV_LEN || tlv_len < 1)
{
col_append_sep_str(pinfo->cinfo, COL_INFO, NULL, "RNG-REQ TLV error");
proto_tree_add_item(rng_req_tree, hf_rng_invalid_tlv, tvb, offset, (tvb_len - offset), ENC_NA);
break;
}
tlv_offset = offset + get_tlv_value_offset(&tlv_info);
switch (tlv_type) {
case RNG_REQ_DL_BURST_PROFILE:
tlv_item = add_tlv_subtree(&tlv_info, rng_req_tree, hf_rng_req_dl_burst_profile, tvb, offset, ENC_BIG_ENDIAN);
tlv_tree = proto_item_add_subtree(tlv_item, ett_mac_mgmt_msg_rng_req_decoder);
proto_tree_add_item(tlv_tree, hf_rng_req_dl_burst_profile_diuc, tvb, tlv_offset, 1, ENC_BIG_ENDIAN);
proto_tree_add_item(tlv_tree, hf_rng_req_dl_burst_profile_lsb_ccc, tvb, tlv_offset, 1, ENC_BIG_ENDIAN);
break;
case RNG_REQ_SS_MAC_ADDRESS:
add_tlv_subtree(&tlv_info, rng_req_tree, hf_rng_req_ss_mac_address, tvb, offset, ENC_NA);
break;
case RNG_REQ_RANGING_ANOMALIES:
tlv_item = add_tlv_subtree(&tlv_info, rng_req_tree, hf_rng_req_ranging_anomalies, tvb, offset, ENC_BIG_ENDIAN);
tlv_tree = proto_item_add_subtree(tlv_item, ett_mac_mgmt_msg_rng_req_decoder);
proto_tree_add_item(tlv_tree, hf_rng_req_ranging_anomalies_max_power, tvb, tlv_offset, 1, ENC_BIG_ENDIAN);
proto_tree_add_item(tlv_tree, hf_rng_req_ranging_anomalies_min_power, tvb, tlv_offset, 1, ENC_BIG_ENDIAN);
proto_tree_add_item(tlv_tree, hf_rng_req_ranging_anomalies_timing_adj, tvb, tlv_offset, 1, ENC_BIG_ENDIAN);
break;
case RNG_REQ_AAS_BROADCAST:
add_tlv_subtree(&tlv_info, rng_req_tree, hf_rng_req_aas_broadcast, tvb, offset, ENC_BIG_ENDIAN);
break;
case RNG_REQ_SERVING_BS_ID:
add_tlv_subtree(&tlv_info, rng_req_tree, hf_rng_req_serving_bs_id, tvb, offset, ENC_NA);
break;
case RNG_REQ_RANGING_PURPOSE_INDICATION:
tlv_item = add_tlv_subtree(&tlv_info, rng_req_tree, hf_rng_req_ranging_purpose_indication, tvb, offset, ENC_BIG_ENDIAN);
tlv_tree = proto_item_add_subtree(tlv_item, ett_mac_mgmt_msg_rng_req_decoder);
proto_tree_add_item(tlv_tree, hf_rng_req_ranging_purpose_ho_indication, tvb, tlv_offset, 1, ENC_BIG_ENDIAN);
proto_tree_add_item(tlv_tree, hf_rng_req_ranging_purpose_location_update_request, tvb, tlv_offset, 1, ENC_BIG_ENDIAN);
proto_tree_add_item(tlv_tree, hf_rng_req_ranging_purpose_reserved, tvb, tlv_offset, 1, ENC_BIG_ENDIAN);
break;
case RNG_REQ_HO_ID:
add_tlv_subtree(&tlv_info, rng_req_tree, hf_rng_req_ho_id, tvb, offset, ENC_BIG_ENDIAN);
break;
case RNG_REQ_POWER_DOWN_INDICATOR:
add_tlv_subtree(&tlv_info, rng_req_tree, hf_rng_req_power_down_indicator, tvb, offset, ENC_BIG_ENDIAN);
break;
case RNG_REQ_REQUESTED_DNLK_REP_CODING_LEVEL:
tlv_item = add_tlv_subtree(&tlv_info, rng_req_tree, hf_rng_req_requested_rep_coding_level, tvb, offset, ENC_BIG_ENDIAN);
tlv_tree = proto_item_add_subtree(tlv_item, ett_mac_mgmt_msg_rng_req_decoder);
proto_tree_add_item(tlv_tree, hf_rng_req_repetition_coding_level, tvb, tlv_offset, 1, ENC_BIG_ENDIAN);
proto_tree_add_item(tlv_tree, hf_rng_req_requested_downlink_repetition_coding_level_reserved, tvb, tlv_offset, 1, ENC_BIG_ENDIAN);
break;
case RNG_REQ_CMAC_KEY_COUNT:
if (include_cor2_changes) {
add_tlv_subtree(&tlv_info, rng_req_tree, hf_rng_req_cmac_key_count, tvb, offset, ENC_BIG_ENDIAN);
} else {
add_tlv_subtree(&tlv_info, rng_req_tree, hf_tlv_type, tvb, offset, ENC_NA);
}
break;
case SHORT_HMAC_TUPLE:
case SHORT_HMAC_TUPLE_COR2:
if ((!include_cor2_changes && (tlv_type == SHORT_HMAC_TUPLE)) ||
(include_cor2_changes && (tlv_type == SHORT_HMAC_TUPLE_COR2))) {
tlv_tree = add_protocol_subtree(&tlv_info, ett_mac_mgmt_msg_rng_req_decoder, rng_req_tree, proto_mac_mgmt_msg_rng_req_decoder, tvb, offset, tlv_len, "Short HMAC Tuple");
wimax_short_hmac_tuple_decoder(tlv_tree, tvb, tlv_offset, tvb_len - offset);
} else {
add_tlv_subtree(&tlv_info, rng_req_tree, hf_tlv_type, tvb, offset, ENC_NA);
}
break;
case MAC_VERSION_ENCODING:
offset += wimax_common_tlv_encoding_decoder(tvb_new_subset_remaining(tvb, offset), pinfo, rng_req_tree);
continue;
break;
case RNG_REQ_POWER_SAVING_CLASS_PARAMETERS:
tlv_tree = add_protocol_subtree(&tlv_info, ett_mac_mgmt_msg_rng_req_decoder, rng_req_tree, proto_mac_mgmt_msg_rng_req_decoder, tvb, offset, tlv_len, "Power Saving Class Parameters");
dissect_power_saving_class(tlv_tree, tlv_type, tvb, tlv_len, pinfo, tlv_offset);
break;
default:
add_tlv_subtree(&tlv_info, rng_req_tree, hf_tlv_type, tvb, offset, ENC_NA);
break;
}
offset = tlv_len + tlv_offset;
}
}
return tvb_captured_length(tvb);
}
void proto_register_mac_mgmt_msg_rng_req(void)
{
static hf_register_info hf[] =
{
{
&hf_rng_activation_of_power_saving_class,
{
"Activation of Power Saving Class (Types 1 and 2 only)", "wmx.rng.power_save.activate",
FT_BOOLEAN, 8, TFS(&tfs_rng_activate), 0x02, NULL, HFILL
}
},
{
&hf_rng_power_saving_class_id,
{
"Power Saving Class ID", "wmx.rng.power_save.class_id",
FT_UINT8, BASE_DEC, NULL, 0x0, NULL, HFILL
}
},
{
&hf_rng_power_saving_class_type,
{
"Power Saving Class Type", "wmx.rng.power_save.class_type",
FT_UINT8, BASE_DEC, NULL, 0x0, NULL, HFILL
}
},
{
&hf_rng_definition_of_power_saving_class_present,
{
"Definition of Power Saving Class present", "wmx.rng.power_save.definition_present",
FT_UINT8, BASE_DEC, NULL, 0x01, NULL, HFILL
}
},
{
&hf_rng_power_saving_final_sleep_window_base,
{
"Final-sleep window base (measured in frames)", "wmx.rng.power_save.final_sleep_window_base",
FT_UINT8, BASE_DEC, NULL, 0x0, NULL, HFILL
}
},
{
&hf_rng_power_saving_final_sleep_window_exp,
{
"Final-sleep window exponent (measured in frames)", "wmx.rng.power_save.final_sleep_window_exp",
FT_UINT8, BASE_DEC, NULL, 0x0, NULL, HFILL
}
},
{
&hf_rng_power_saving_first_sleep_window_frame,
{
"Start frame number for first sleep window", "wmx.rng.power_save.first_sleep_window_frame",
FT_UINT8, BASE_DEC, NULL, 0x0, NULL, HFILL
}
},
{
&hf_rng_power_saving_included_cid,
{
"CID of connection to be included into the Power Saving Class.", "wmx.rng.power_save.included_cid",
FT_UINT16, BASE_DEC, NULL, 0x0, NULL, HFILL
}
},
{
&hf_rng_power_saving_initial_sleep_window,
{
"Initial-sleep window", "wmx.rng.power_save.initial_sleep_window",
FT_UINT8, BASE_DEC, NULL, 0x0, NULL, HFILL
}
},
{
&hf_rng_power_saving_listening_window,
{
"Listening window duration (measured in frames)", "wmx.rng.power_save.listening_window",
FT_UINT8, BASE_DEC, NULL, 0x0, NULL, HFILL
}
},
{
&hf_rng_power_saving_mgmt_connection_direction,
{
"Direction for management connection added to Power Saving Class", "wmx.rng.power_save.mgmt_connection_direction",
FT_UINT8, BASE_DEC, NULL, 0x0, NULL, HFILL
}
},
{
&hf_rng_power_saving_class_reserved,
{
"Reserved", "wmx.rng.power_save.reserved",
FT_UINT8, BASE_DEC, NULL, 0xF8, NULL, HFILL
}
},
{
&hf_rng_power_saving_slpid,
{
"SLPID assigned by the BS whenever an MS is instructed to enter sleep mode", "wmx.rng.power_save.slpid",
FT_UINT8, BASE_DEC, NULL, 0x0, NULL, HFILL
}
},
{
&hf_rng_trf_ind_required,
{
"BS shall transmit at least one TRF-IND message during each listening window of the Power Saving Class", "wmx.rng.power_save.trf_ind_required",
FT_BOOLEAN, 8, TFS(&tfs_rng_activate), 0x04, NULL, HFILL
}
},
{
&hf_rng_req_aas_broadcast,
{
"AAS broadcast capability", "wmx.rng_req.aas_broadcast",
FT_BOOLEAN, BASE_NONE, TFS(&tfs_rng_req_aas_broadcast), 0x0, NULL, HFILL
}
},
{
&hf_rng_req_ranging_anomalies_max_power,
{
"Meaning", "wmx.rng_req.anomalies.max_power",
FT_BOOLEAN, 8, TFS(&tfs_rng_max_power), 0x04, NULL, HFILL
}
},
{
&hf_rng_req_ranging_anomalies_min_power,
{
"Meaning", "wmx.rng_req.anomalies.min_power",
FT_BOOLEAN, 8, TFS(&tfs_rng_min_power), 0x02, NULL, HFILL
}
},
{
&hf_rng_req_ranging_anomalies_timing_adj,
{
"Meaning", "wmx.rng_req.anomalies.timing_adj",
FT_BOOLEAN, 8, TFS(&tfs_rng_timing_adj), 0x01, NULL, HFILL
}
},
{
&hf_rng_req_cmac_key_count,
{
"CMAC Key Count", "wmx.rng_req.cmac_key_count",
FT_UINT16, BASE_DEC, NULL, 0x00, NULL, HFILL
}
},
{
&hf_rng_req_dl_burst_profile_lsb_ccc,
{
"LSB of CCC of DCD associated with DIUC", "wmx.rng_req.dl_burst_profile.ccc",
FT_UINT8, BASE_DEC, NULL, 0xF0, NULL, HFILL
}
},
{
&hf_rng_req_dl_burst_profile_diuc,
{
"DIUC", "wmx.rng_req.dl_burst_profile.diuc",
FT_UINT8, BASE_DEC, NULL, 0x0F, NULL, HFILL
}
},
{
&hf_tlv_type,
{
"Unknown TLV Type", "wmx.rng_req.unknown_tlv_type",
FT_BYTES, BASE_NONE, NULL, 0, NULL, HFILL
}
},
{
&hf_rng_invalid_tlv,
{
"Invalid TLV", "wmx.rng_req.invalid_tlv",
FT_BYTES, BASE_NONE, NULL, 0, NULL, HFILL
}
},
{
&hf_rng_req_ho_id,
{
"ID from the target BS for use in initial ranging during MS handover to it", "wmx.rng_req.ho_id",
FT_UINT8, BASE_DEC, NULL, 0x0, NULL, HFILL
}
},
{
&hf_rng_req_power_down_indicator,
{
"Power down Indicator", "wmx.rng_req.power_down_indicator",
FT_UINT8, BASE_DEC, NULL, 0x00, NULL, HFILL
}
},
{
&hf_rng_req_ranging_purpose_ho_indication,
{
"MS HO indication", "wmx.rng_req.ranging_purpose.ho_indication",
FT_UINT8, BASE_DEC, NULL, 0x01, NULL, HFILL
}
},
{
&hf_rng_req_ranging_purpose_reserved,
{
"Reserved", "wmx.rng_req.ranging_purpose.reserved",
FT_UINT8, BASE_DEC, NULL, 0xFC, NULL, HFILL
}
},
{
&hf_rng_req_ranging_purpose_location_update_request,
{
"Location Update Request", "wmx.rng_req.ranging_purpose.loc_update_req",
FT_UINT8, BASE_DEC, VALS(vals_rng_req_ranging_purpose_location_update_request), 0x02, NULL, HFILL
}
},
{
&hf_rng_req_repetition_coding_level,
{
"Repetition coding level", "wmx.rng_req.repetition_coding_level",
FT_UINT8, BASE_DEC, VALS(vals_rng_req_repetition_coding_level), 0x03, NULL, HFILL
}
},
{
&hf_rng_req_requested_downlink_repetition_coding_level_reserved,
{
"Reserved", "wmx.rng_req.reserved",
FT_UINT8, BASE_DEC, NULL, 0xFC, NULL, HFILL
}
},
{
&hf_rng_req_reserved,
{
"Reserved", "wmx.rng_req.reserved",
FT_UINT8, BASE_DEC, NULL, 0x0, NULL, HFILL
}
},
{
&hf_rng_req_serving_bs_id,
{
"Former serving BS ID", "wmx.rng_req.serving_bs_id",
FT_ETHER, BASE_NONE, NULL, 0x00, NULL, HFILL
}
},
{
&hf_rng_req_ss_mac_address,
{
"SS MAC Address", "wmx.rng_req.ss_mac_address",
FT_ETHER, BASE_NONE, NULL, 0x00, NULL, HFILL
}
},
{
&hf_rng_power_saving_class_flags,
{
"Power Saving Class", "wmx.rng.power_save.flags",
FT_UINT8, BASE_HEX, NULL, 0x0, NULL, HFILL
}
},
{
&hf_rng_req_dl_burst_profile,
{
"Requested Downlink Burst Profile", "wmx.rng_req.dl_burst_profile",
FT_UINT8, BASE_HEX, NULL, 0x0, NULL, HFILL
}
},
{
&hf_rng_req_ranging_anomalies,
{
"Ranging Anomalies", "wmx.rng_req.anomalies",
FT_UINT8, BASE_DEC, NULL, 0x0, NULL, HFILL
}
},
{
&hf_rng_req_ranging_purpose_indication,
{
"Ranging Purpose Flags", "wmx.rng_req.ranging_purpose.indication",
FT_UINT8, BASE_HEX, NULL, 0x0, NULL, HFILL
}
},
{
&hf_rng_req_requested_rep_coding_level,
{
"Requested downlink repetition coding level", "wmx.rng_req.requested_rep_coding_level",
FT_UINT8, BASE_HEX, NULL, 0x0, NULL, HFILL
}
},
};
static gint *ett[] =
{
&ett_mac_mgmt_msg_rng_req_decoder,
};
proto_mac_mgmt_msg_rng_req_decoder = proto_register_protocol (
"WiMax RNG-REQ Messages",
"WiMax RNG-REQ",
"wmx.rng_req"
);
proto_register_field_array(proto_mac_mgmt_msg_rng_req_decoder, hf, array_length(hf));
proto_register_subtree_array(ett, array_length(ett));
}
void proto_reg_handoff_mac_mgmt_msg_rng_req(void)
{
dissector_handle_t rng_req_handle;
rng_req_handle = create_dissector_handle(dissect_mac_mgmt_msg_rng_req_decoder, proto_mac_mgmt_msg_rng_req_decoder);
dissector_add_uint("wmx.mgmtmsg", MAC_MGMT_MSG_RNG_REQ, rng_req_handle);
}
