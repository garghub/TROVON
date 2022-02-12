static int dissect_mac_mgmt_msg_aas_fbck_req_decoder(tvbuff_t *tvb, packet_info *pinfo _U_, proto_tree *tree, void* data _U_)
{
guint offset = 0;
guint data_type;
proto_item *aas_fbck_item;
proto_tree *aas_fbck_tree;
{
aas_fbck_item = proto_tree_add_protocol_format(tree, proto_mac_mgmt_msg_aas_fbck_decoder, tvb, offset, -1, "AAS Channel Feedback Request (AAS-FBCK-REQ)");
aas_fbck_tree = proto_item_add_subtree(aas_fbck_item, ett_mac_mgmt_msg_aas_fbck_req_decoder);
proto_tree_add_item(aas_fbck_tree, hf_aas_fbck_frame_number, tvb, offset, 1, ENC_BIG_ENDIAN);
offset++;
data_type = tvb_get_guint8(tvb, offset);
proto_tree_add_item(aas_fbck_tree, hf_aas_fbck_number_of_frames, tvb, offset, 1, ENC_BIG_ENDIAN);
proto_tree_add_item(aas_fbck_tree, hf_aas_fbck_req_data_type, tvb, offset, 1, ENC_BIG_ENDIAN);
offset++;
proto_tree_add_item(aas_fbck_tree, hf_aas_fbck_req_counter, tvb, offset, 1, ENC_BIG_ENDIAN);
if(data_type & OFDMA_AAS_FBCK_REQ_DATA_TYPE_MASK)
proto_tree_add_item(aas_fbck_tree, hf_aas_fbck_req_resolution_1, tvb, offset, 1, ENC_BIG_ENDIAN);
else
proto_tree_add_item(aas_fbck_tree, hf_aas_fbck_req_resolution_0, tvb, offset, 1, ENC_BIG_ENDIAN);
proto_tree_add_item(aas_fbck_tree, hf_aas_fbck_req_reserved, tvb, offset, 1, ENC_BIG_ENDIAN);
}
return tvb_captured_length(tvb);
}
static int dissect_mac_mgmt_msg_aas_fbck_rsp_decoder(tvbuff_t *tvb, packet_info *pinfo _U_, proto_tree *tree, void* data _U_)
{
guint offset = 0;
guint tvb_len, data_type;
proto_item *aas_fbck_item;
proto_tree *aas_fbck_tree;
{
tvb_len = tvb_reported_length(tvb);
aas_fbck_item = proto_tree_add_protocol_format(tree, proto_mac_mgmt_msg_aas_fbck_decoder, tvb, offset, -1, "AAS Channel Feedback Response (AAS-FBCK-RSP)");
aas_fbck_tree = proto_item_add_subtree(aas_fbck_item, ett_mac_mgmt_msg_aas_fbck_rsp_decoder);
data_type = tvb_get_guint8(tvb, offset);
proto_tree_add_item(aas_fbck_tree, hf_aas_fbck_rsp_reserved, tvb, offset, 1, ENC_BIG_ENDIAN);
proto_tree_add_item(aas_fbck_tree, hf_aas_fbck_rsp_data_type, tvb, offset, 1, ENC_BIG_ENDIAN);
proto_tree_add_item(aas_fbck_tree, hf_aas_fbck_rsp_counter, tvb, offset, 1, ENC_BIG_ENDIAN);
if(data_type & OFDMA_AAS_FBCK_RSP_DATA_TYPE_MASK)
proto_tree_add_item(aas_fbck_tree, hf_aas_fbck_rsp_resolution_1, tvb, offset, 1, ENC_BIG_ENDIAN);
else
proto_tree_add_item(aas_fbck_tree, hf_aas_fbck_rsp_resolution_0, tvb, offset, 1, ENC_BIG_ENDIAN);
offset++;
for(; offset < (tvb_len - 2); )
{
proto_tree_add_item(aas_fbck_tree, hf_aas_fbck_freq_value_re, tvb, offset, 1, ENC_BIG_ENDIAN);
offset++;
proto_tree_add_item(aas_fbck_tree, hf_aas_fbck_freq_value_im, tvb, offset, 1, ENC_BIG_ENDIAN);
offset++;
}
proto_tree_add_item(aas_fbck_tree, hf_aas_fbck_rssi_value, tvb, offset, 1, ENC_BIG_ENDIAN);
offset++;
proto_tree_add_item(aas_fbck_tree, hf_aas_fbck_cinr_value, tvb, offset, 1, ENC_BIG_ENDIAN);
}
return tvb_captured_length(tvb);
}
void proto_register_mac_mgmt_msg_aas_fbck(void)
{
static hf_register_info hf_aas_fbck[] =
{
{
&hf_aas_fbck_cinr_value,
{
"CINR Mean Value", "wmx.aas_fbck.cinr_mean_value",
FT_UINT8, BASE_DEC, NULL, 0x0, NULL, HFILL
}
},
{
&hf_aas_fbck_req_counter,
{
"Feedback Request Counter", "wmx.aas_fbck.counter",
FT_UINT8, BASE_DEC, NULL, OFDMA_AAS_FBCK_REQ_FB_REQ_COUNTER_MASK, NULL, HFILL
}
},
{
&hf_aas_fbck_frame_number,
{
"Frame Number", "wmx.aas_fbck.frame_number",
FT_UINT8, BASE_DEC, NULL, 0x0, NULL, HFILL
}
},
{
&hf_aas_fbck_freq_value_re,
{
"Frequency Value (real part)", "wmx.aas_fbck.freq_value_re",
FT_UINT8, BASE_DEC, NULL, 0x0, NULL, HFILL
}
},
{
&hf_aas_fbck_freq_value_im,
{
"Frequency Value (imaginary part)", "wmx.aas_fbck.freq_value_im",
FT_UINT8, BASE_DEC, NULL, 0x0, NULL, HFILL
}
},
{
&hf_aas_fbck_number_of_frames,
{
"Number Of Frames", "wmx.aas_fbck.number_of_frames",
FT_UINT8, BASE_DEC, NULL, OFDMA_AAS_FBCK_REQ_NUMBER_OF_FRAME_MASK, NULL, HFILL
}
},
{
&hf_aas_fbck_req_resolution_0,
{
"Frequency Measurement Resolution", "wmx.aas_fbck.resolution",
FT_UINT8, BASE_DEC, VALS(vals_resolutions_0), OFDMA_AAS_FBCK_REQ_FB_REQ_RESOLUTION_MASK, NULL, HFILL
}
},
{
&hf_aas_fbck_req_resolution_1,
{
"Frequency Measurement Resolution", "wmx.aas_fbck.resolution",
FT_UINT8, BASE_DEC, VALS(vals_resolutions_1), OFDMA_AAS_FBCK_REQ_FB_REQ_RESOLUTION_MASK, NULL, HFILL
}
},
{
&hf_aas_fbck_rssi_value,
{
"RSSI Mean Value", "wmx.aas_fbck.rssi_mean_value",
FT_UINT8, BASE_DEC, NULL, 0x0, NULL, HFILL
}
},
#if 0
{
&hf_aas_fbck_unknown_type,
{
"Unknown TLV type", "wmx.aas_fbck.unknown_type",
FT_BYTES, BASE_NONE, NULL, 0x0, NULL, HFILL
}
},
#endif
{
&hf_aas_fbck_req_data_type,
{
"Measurement Data Type", "wmx.aas_fbck_req.data_type",
FT_UINT8, BASE_DEC, VALS(vals_data_types), OFDMA_AAS_FBCK_REQ_DATA_TYPE_MASK, NULL, HFILL
}
},
{
&hf_aas_fbck_req_reserved,
{
"Reserved", "wmx.aas_fbck_req.reserved",
FT_UINT8, BASE_HEX, NULL, OFDMA_AAS_FBCK_REQ_FB_REQ_RESERVED_MASK, NULL, HFILL
}
},
{
&hf_aas_fbck_rsp_counter,
{
"Feedback Request Counter", "wmx.aas_fbck_rsp.counter",
FT_UINT8, BASE_DEC, NULL, OFDMA_AAS_FBCK_REQ_FB_RSP_COUNTER_MASK, NULL, HFILL
}
},
{
&hf_aas_fbck_rsp_data_type,
{
"Measurement Data Type", "wmx.aas_fbck_rsp.data_type",
FT_UINT8, BASE_DEC, VALS(vals_data_types), OFDMA_AAS_FBCK_RSP_DATA_TYPE_MASK, NULL, HFILL
}
},
{
&hf_aas_fbck_rsp_reserved,
{
"Reserved", "wmx.aas_fbck_rsp.reserved",
FT_UINT8, BASE_HEX, NULL, OFDMA_AAS_FBCK_REQ_FB_RSP_RESERVED_MASK, NULL, HFILL
}
},
{
&hf_aas_fbck_rsp_resolution_0,
{
"Frequency Measurement Resolution", "wmx.aas_fbck_rsp.resolution",
FT_UINT8, BASE_DEC, VALS(vals_resolutions_0), OFDMA_AAS_FBCK_REQ_FB_RSP_RESOLUTION_MASK, NULL, HFILL
}
},
{
&hf_aas_fbck_rsp_resolution_1,
{
"Frequency Measurement Resolution", "wmx.aas_fbck_rsp.resolution",
FT_UINT8, BASE_DEC, VALS(vals_resolutions_1), OFDMA_AAS_FBCK_REQ_FB_RSP_RESOLUTION_MASK, NULL, HFILL
}
}
};
static gint *ett[] =
{
&ett_mac_mgmt_msg_aas_fbck_req_decoder,
&ett_mac_mgmt_msg_aas_fbck_rsp_decoder,
};
proto_mac_mgmt_msg_aas_fbck_decoder = proto_register_protocol (
"WiMax AAS-FEEDBACK Messages",
"WiMax AAS-FEEDBACK (aas)",
"wmx.aas"
);
proto_register_field_array(proto_mac_mgmt_msg_aas_fbck_decoder, hf_aas_fbck, array_length(hf_aas_fbck));
proto_register_subtree_array(ett, array_length(ett));
}
void
proto_reg_handoff_mac_mgmt_msg_aas(void)
{
dissector_handle_t aas_handle;
aas_handle = create_dissector_handle(dissect_mac_mgmt_msg_aas_fbck_req_decoder, proto_mac_mgmt_msg_aas_fbck_decoder);
dissector_add_uint("wmx.mgmtmsg", MAC_MGMT_MSG_AAS_FBCK_REQ, aas_handle);
aas_handle = create_dissector_handle(dissect_mac_mgmt_msg_aas_fbck_rsp_decoder, proto_mac_mgmt_msg_aas_fbck_decoder);
dissector_add_uint("wmx.mgmtmsg", MAC_MGMT_MSG_AAS_FBCK_RSP, aas_handle);
}
