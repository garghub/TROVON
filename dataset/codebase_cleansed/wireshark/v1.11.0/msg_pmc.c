void proto_register_mac_mgmt_msg_pmc_req(void)
{
static hf_register_info hf[] =
{
{
&hf_pmc_req_confirmation,
{
"Confirmation", "wmx.pmc_req.confirmation",
FT_UINT16, BASE_DEC, VALS(vals_pmc_req_confirmation), 0x0020, NULL, HFILL
}
},
{
&hf_pmc_req_pwr_control_mode_change,
{
"Power control mode change", "wmx.pmc_req.power_control_mode",
FT_UINT16, BASE_DEC, VALS(vals_pmc_req_pwr), 0xC000, NULL, HFILL
}
},
{
&hf_pmc_req_pwr_control_mode_change_cor2,
{
"Power control mode change", "wmx.pmc_req.power_control_mode",
FT_UINT16, BASE_DEC, VALS(vals_pmc_req_pwr_cor2), 0xC000, NULL, HFILL
}
},
{
&hf_pmc_req_reserved,
{
"Reserved", "wmx.pmc_req.reserved",
FT_UINT16, BASE_DEC, NULL, 0x001F, NULL, HFILL
}
},
{
&hf_pmc_req_tx_power_level,
{
"UL Tx power level for the burst that carries this header", "wmx.pmc_req.ul_tx_power_level",
FT_UINT16, BASE_DEC, NULL, 0x3FC0, "When the Tx power is different from slot to slot, the maximum value is reported", HFILL
}
},
{
&hf_pmc_rsp_offset_BS_per_MS,
{
"Offset_BS per MS", "wmx.pmc_rsp.offset_BS_per_MS",
FT_FLOAT, BASE_NONE, NULL, 0x0, "Signed change in power level (incr of 0.25 dB) that the MS shall apply to the open loop power control formula in 8.4.10.3.2", HFILL
}
},
{
&hf_pmc_rsp_power_adjust,
{
"Power adjust", "wmx.pmc_rsp.power_adjust",
FT_FLOAT, BASE_NONE, NULL, 0x0, "Signed change in power level (incr of 0.25 dB) that the MS shall apply to its current transmission power. When subchannelization is employed, the SS shall interpret as a required change to the Tx power density", HFILL
}
},
{
&hf_pmc_rsp_start_frame,
{
"Start frame", "wmx.pmc_rsp.start_frame",
FT_UINT16, BASE_HEX, NULL, 0x3F00, "Apply mode change from current frame when 6 LSBs of frame match this", HFILL
}
}
};
proto_mac_mgmt_msg_pmc_req_decoder = proto_register_protocol (
"WiMax PMC-REQ Messages",
"WiMax PMC-REQ",
"wmx.pmc_req"
);
proto_register_field_array(proto_mac_mgmt_msg_pmc_req_decoder, hf, array_length(hf));
proto_register_subtree_array(ett, array_length(ett));
}
void proto_register_mac_mgmt_msg_pmc_rsp(void)
{
proto_mac_mgmt_msg_pmc_rsp_decoder = proto_register_protocol (
"WiMax PMC-RSP Messages",
"WiMax PMC-RSP",
"wmx.pmc_rsp"
);
}
static void dissect_mac_mgmt_msg_pmc_req_decoder(tvbuff_t *tvb, packet_info *pinfo _U_, proto_tree *tree)
{
guint offset = 0;
proto_item *pmc_req_item;
proto_tree *pmc_req_tree;
{
pmc_req_item = proto_tree_add_protocol_format(tree, proto_mac_mgmt_msg_pmc_req_decoder, tvb, 0, -1, "MAC Management Message, PMC-REQ");
pmc_req_tree = proto_item_add_subtree(pmc_req_item, ett_mac_mgmt_msg_pmc_decoder);
proto_tree_add_item(pmc_req_tree, hf_pmc_req_pwr_control_mode_change, tvb, offset, 2, ENC_BIG_ENDIAN);
proto_tree_add_item(pmc_req_tree, hf_pmc_req_tx_power_level, tvb, offset, 2, ENC_BIG_ENDIAN);
proto_tree_add_item(pmc_req_tree, hf_pmc_req_confirmation, tvb, offset, 2, ENC_BIG_ENDIAN);
proto_tree_add_item(pmc_req_tree, hf_pmc_req_reserved, tvb, offset, 2, ENC_BIG_ENDIAN);
}
}
static void dissect_mac_mgmt_msg_pmc_rsp_decoder(tvbuff_t *tvb, packet_info *pinfo _U_, proto_tree *tree)
{
guint offset = 0;
proto_item *pmc_rsp_item;
proto_tree *pmc_rsp_tree;
guint8 pwr_control_mode;
gint8 value;
gfloat power_change;
{
pmc_rsp_item = proto_tree_add_protocol_format(tree, proto_mac_mgmt_msg_pmc_rsp_decoder, tvb, 0, -1, "MAC Management Message, PMC-RSP");
pmc_rsp_tree = proto_item_add_subtree(pmc_rsp_item, ett_mac_mgmt_msg_pmc_decoder);
if (include_cor2_changes)
proto_tree_add_item(pmc_rsp_tree, hf_pmc_req_pwr_control_mode_change_cor2, tvb, offset, 2, ENC_BIG_ENDIAN);
else
proto_tree_add_item(pmc_rsp_tree, hf_pmc_req_pwr_control_mode_change, tvb, offset, 2, ENC_BIG_ENDIAN);
proto_tree_add_item(pmc_rsp_tree, hf_pmc_rsp_start_frame, tvb, offset, 2, ENC_BIG_ENDIAN);
pwr_control_mode = 0xC0 & tvb_get_guint8(tvb, offset);
offset++;
value = (gint8)tvb_get_guint8(tvb, offset);
power_change = (float)0.25 * value;
if (pwr_control_mode == 0) {
proto_tree_add_float_format_value(pmc_rsp_tree, hf_pmc_rsp_power_adjust, tvb, offset, 1, power_change, " %.2f dB", power_change);
} else {
proto_tree_add_float_format_value(pmc_rsp_tree, hf_pmc_rsp_offset_BS_per_MS, tvb, offset, 1, power_change, " %.2f dB", power_change);
}
}
}
void
proto_reg_handoff_mac_mgmt_msg_pmc(void)
{
dissector_handle_t pmc_handle;
pmc_handle = create_dissector_handle(dissect_mac_mgmt_msg_pmc_req_decoder, proto_mac_mgmt_msg_pmc_req_decoder);
dissector_add_uint("wmx.mgmtmsg", MAC_MGMT_MSG_PMC_REQ, pmc_handle);
pmc_handle = create_dissector_handle(dissect_mac_mgmt_msg_pmc_rsp_decoder, proto_mac_mgmt_msg_pmc_rsp_decoder);
dissector_add_uint("wmx.mgmtmsg", MAC_MGMT_MSG_PMC_RSP, pmc_handle);
}
