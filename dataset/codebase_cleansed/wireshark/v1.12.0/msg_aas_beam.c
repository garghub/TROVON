static void dissect_mac_mgmt_msg_aas_beam_select_decoder(tvbuff_t *tvb, packet_info *pinfo _U_, proto_tree *tree)
{
guint offset = 0;
proto_item *aas_beam_item;
proto_tree *aas_beam_tree;
{
aas_beam_item = proto_tree_add_protocol_format(tree, proto_mac_mgmt_msg_aas_beam_decoder, tvb, offset, -1, "AAS Beam Select (AAS-BEAM-SELECT)");
aas_beam_tree = proto_item_add_subtree(aas_beam_item, ett_mac_mgmt_msg_aas_beam_select_decoder);
proto_tree_add_item(aas_beam_tree, hf_aas_beam_select_index, tvb, offset, 1, ENC_BIG_ENDIAN);
proto_tree_add_item(aas_beam_tree, hf_aas_beam_select_reserved, tvb, offset, 1, ENC_BIG_ENDIAN);
}
}
static void dissect_mac_mgmt_msg_aas_beam_req_decoder(tvbuff_t *tvb, packet_info *pinfo _U_, proto_tree *tree)
{
guint offset = 0;
proto_item *aas_beam_item;
proto_tree *aas_beam_tree;
{
aas_beam_item = proto_tree_add_protocol_format(tree, proto_mac_mgmt_msg_aas_beam_decoder, tvb, offset, -1, "AAS Beam Request (AAS-BEAM-REQ)");
aas_beam_tree = proto_item_add_subtree(aas_beam_item, ett_mac_mgmt_msg_aas_beam_req_decoder);
proto_tree_add_item(aas_beam_tree, hf_aas_beam_frame_number, tvb, offset, 1, ENC_BIG_ENDIAN);
offset++;
proto_tree_add_item(aas_beam_tree, hf_aas_beam_feedback_request_number, tvb, offset, 1, ENC_BIG_ENDIAN);
proto_tree_add_item(aas_beam_tree, hf_aas_beam_measurement_report_type, tvb, offset, 1, ENC_BIG_ENDIAN);
proto_tree_add_item(aas_beam_tree, hf_aas_beam_resolution_parameter, tvb, offset, 1, ENC_BIG_ENDIAN);
offset++;
proto_tree_add_item(aas_beam_tree, hf_aas_beam_beam_bit_mask, tvb, offset, 1, ENC_BIG_ENDIAN);
proto_tree_add_item(aas_beam_tree, hf_aas_beam_select_reserved, tvb, offset, 1, ENC_BIG_ENDIAN);
}
}
static void dissect_mac_mgmt_msg_aas_beam_rsp_decoder(tvbuff_t *tvb, packet_info *pinfo _U_, proto_tree *tree)
{
guint offset = 0;
guint tvb_len, report_type;
guint number_of_frequencies, indx;
proto_item *aas_beam_item;
proto_tree *aas_beam_tree;
{
tvb_len = tvb_reported_length(tvb);
aas_beam_item = proto_tree_add_protocol_format(tree, proto_mac_mgmt_msg_aas_beam_decoder, tvb, offset, -1, "AAS Beam Response (AAS-BEAM-RSP)");
aas_beam_tree = proto_item_add_subtree(aas_beam_item, ett_mac_mgmt_msg_aas_beam_rsp_decoder);
proto_tree_add_item(aas_beam_tree, hf_aas_beam_frame_number, tvb, offset, 1, ENC_BIG_ENDIAN);
offset++;
report_type = tvb_get_guint8(tvb, offset);
proto_tree_add_item(aas_beam_tree, hf_aas_beam_feedback_request_number, tvb, offset, 1, ENC_BIG_ENDIAN);
proto_tree_add_item(aas_beam_tree, hf_aas_beam_measurement_report_type, tvb, offset, 1, ENC_BIG_ENDIAN);
proto_tree_add_item(aas_beam_tree, hf_aas_beam_resolution_parameter, tvb, offset, 1, ENC_BIG_ENDIAN);
offset++;
proto_tree_add_item(aas_beam_tree, hf_aas_beam_beam_bit_mask, tvb, offset, 1, ENC_BIG_ENDIAN);
proto_tree_add_item(aas_beam_tree, hf_aas_beam_select_reserved, tvb, offset, 1, ENC_BIG_ENDIAN);
offset++;
if((report_type & AAS_BEAM_MEASUREMENT_REPORT_TYPE_MASK) == 0)
{
number_of_frequencies = (tvb_len - offset) / 2 - 1;
for(indx = 0; indx < number_of_frequencies; indx++)
{
proto_tree_add_item(aas_beam_tree, hf_aas_beam_freq_value_re, tvb, offset, 1, ENC_BIG_ENDIAN);
offset++;
proto_tree_add_item(aas_beam_tree, hf_aas_beam_freq_value_im, tvb, offset, 1, ENC_BIG_ENDIAN);
offset++;
}
}
proto_tree_add_item(aas_beam_tree, hf_aas_beam_rssi_value, tvb, offset, 1, ENC_BIG_ENDIAN);
offset++;
proto_tree_add_item(aas_beam_tree, hf_aas_beam_cinr_value, tvb, offset, 1, ENC_BIG_ENDIAN);
}
}
void proto_register_mac_mgmt_msg_aas_beam(void)
{
static hf_register_info hf_aas_beam[] =
{
{
&hf_aas_beam_select_index,
{
"AAS Beam Index", "wmx.aas_beam.aas_beam_index",
FT_UINT8, BASE_DEC, NULL, AAS_BEAM_SELECT_AAS_BEAM_INDEX_MASK, NULL, HFILL
}
},
{
&hf_aas_beam_beam_bit_mask,
{
"Beam Bit Mask", "wmx.aas_beam.beam_bit_mask",
FT_UINT8, BASE_HEX, NULL, AAS_BEAM_BEAM_BIT_MASK_MASK, NULL, HFILL
}
},
#ifdef OFDM
{
&hf_aas_beam_cinr_value,
{
"CINR Mean Value", "wmx.aas_beam.cinr_mean_value",
FT_UINT8, BASE_DEC, NULL, 0x0, NULL, HFILL
}
},
{
&hf_aas_beam_feedback_request_number,
{
"Feedback Request Number", "wmx.aas_beam.feedback_request_number",
FT_UINT8, BASE_DEC, NULL, AAS_BEAM_FEEDBACK_REQUEST_NUMBER_MASK, NULL, HFILL
}
},
{
&hf_aas_beam_frame_number,
{
"Frame Number", "wmx.aas_beam.frame_number",
FT_UINT8, BASE_DEC, NULL, 0x0, NULL, HFILL
}
},
{
&hf_aas_beam_freq_value_im,
{
"Frequency Value (imaginary part)", "wmx.aas_beam.freq_value_im",
FT_UINT8, BASE_DEC, NULL, 0x0, NULL, HFILL
}
},
{
&hf_aas_beam_freq_value_re,
{
"Frequency Value (real part)", "wmx.aas_beam.freq_value_re",
FT_UINT8, BASE_DEC, NULL, 0x0, NULL, HFILL
}
},
{
&hf_aas_beam_measurement_report_type,
{
"Measurement Report Type", "wmx.aas_beam.measurement_report_type",
FT_UINT8, BASE_DEC, VALS(vals_report_types), AAS_BEAM_MEASUREMENT_REPORT_TYPE_MASK, NULL, HFILL
}
},
{
&hf_aas_beam_select_reserved,
{
"Reserved", "wmx.aas_beam.reserved",
FT_UINT8, BASE_HEX, NULL, AAS_BEAM_SELECT_RESERVED_MASK, NULL, HFILL
}
},
{
&hf_aas_beam_resolution_parameter,
{
"Resolution Parameter", "wmx.aas_beam.resolution_parameter",
FT_UINT8, BASE_DEC, VALS(vals_resolution_parameter), AAS_BEAM_RESOLUTION_PARAMETER_MASK, NULL, HFILL
}
},
{
&hf_aas_beam_rssi_value,
{
"RSSI Mean Value", "wmx.aas_beam.rssi_mean_value",
FT_UINT8, BASE_DEC, NULL, 0x0, NULL, HFILL
}
},
#endif
#if 0
{
&hf_aas_beam_unknown_type,
{
"Unknown TLV type", "wmx.aas_beam.unknown_type",
FT_BYTES, BASE_NONE, NULL, 0x0, NULL, HFILL
}
}
#endif
};
static gint *ett[] =
{
&ett_mac_mgmt_msg_aas_beam_select_decoder,
&ett_mac_mgmt_msg_aas_beam_req_decoder,
&ett_mac_mgmt_msg_aas_beam_rsp_decoder,
};
proto_mac_mgmt_msg_aas_beam_decoder = proto_register_protocol (
"WiMax AAS-BEAM Messages",
"WiMax AAS-BEAM",
"wmx.aas_beam"
);
proto_register_field_array(proto_mac_mgmt_msg_aas_beam_decoder, hf_aas_beam, array_length(hf_aas_beam));
proto_register_subtree_array(ett, array_length(ett));
register_dissector("mac_mgmt_msg_aas_beam_select_handler", dissect_mac_mgmt_msg_aas_beam_select_decoder, -1);
#ifdef OFDM
register_dissector("mac_mgmt_msg_aas_beam_req_handler", dissect_mac_mgmt_msg_aas_beam_req_decoder, -1);
register_dissector("mac_mgmt_msg_aas_beam_rsp_handler", dissect_mac_mgmt_msg_aas_beam_rsp_decoder, -1);
#endif
}
void
proto_reg_handoff_mac_mgmt_msg_aas_beam(void)
{
dissector_handle_t aas_handle;
aas_handle = create_dissector_handle(dissect_mac_mgmt_msg_aas_beam_select_decoder, proto_mac_mgmt_msg_aas_beam_decoder);
dissector_add_uint("wmx.mgmtmsg", MAC_MGMT_MSG_AAS_BEAM_SELECT, aas_handle);
}
