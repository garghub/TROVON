static int dissect_mac_mgmt_msg_prc_lt_ctrl_decoder(tvbuff_t *tvb, packet_info *pinfo _U_, proto_tree *tree, void* data _U_)
{
guint offset = 0;
proto_item *prc_lt_ctrl_item;
proto_tree *prc_lt_ctrl_tree;
{
prc_lt_ctrl_item = proto_tree_add_protocol_format(tree, proto_mac_mgmt_msg_prc_lt_ctrl_decoder, tvb, 0, -1, "MAC Management Message, PRC-LT-CTRL");
prc_lt_ctrl_tree = proto_item_add_subtree(prc_lt_ctrl_item, ett_mac_mgmt_msg_prc_lt_ctrl_decoder);
proto_tree_add_item(prc_lt_ctrl_tree, hf_prc_lt_ctrl_precoding, tvb, offset, 1, ENC_BIG_ENDIAN);
proto_tree_add_item(prc_lt_ctrl_tree, hf_prc_lt_ctrl_precoding_delay, tvb, offset, 1, ENC_BIG_ENDIAN);
}
return tvb_captured_length(tvb);
}
void proto_register_mac_mgmt_msg_prc_lt_ctrl(void)
{
static hf_register_info hf[] =
{
#if 0
{
&hf_prc_lt_ctrl_invalid_tlv,
{
"Invalid TLV", "wmx.prc_lt_ctrl.invalid_tlv",
FT_BYTES, BASE_NONE, NULL, 0, NULL, HFILL
}
},
#endif
{
&hf_prc_lt_ctrl_precoding,
{
"Setup/Tear-down long-term precoding with feedback",
"wimax.prc_lt_ctrl.precoding",
FT_UINT8, BASE_DEC, VALS(vals_turn_on), 0x80, NULL, HFILL
}
},
{
&hf_prc_lt_ctrl_precoding_delay,
{
"BS precoding application delay",
"wimax.prc_lt_ctrl.precoding_delay",
FT_UINT8, BASE_DEC, NULL, 0x60, NULL, HFILL
}
}
};
static gint *ett[] =
{
&ett_mac_mgmt_msg_prc_lt_ctrl_decoder,
};
proto_mac_mgmt_msg_prc_lt_ctrl_decoder = proto_register_protocol (
"WiMax PRC-LT-CTRL Message",
"WiMax PRC-LT-CTRL (prc)",
"wmx.prc"
);
proto_register_field_array(proto_mac_mgmt_msg_prc_lt_ctrl_decoder, hf, array_length(hf));
proto_register_subtree_array(ett, array_length(ett));
}
void
proto_reg_handoff_mac_mgmt_msg_prc_lt_ctrl(void)
{
dissector_handle_t handle;
handle = create_dissector_handle(dissect_mac_mgmt_msg_prc_lt_ctrl_decoder, proto_mac_mgmt_msg_prc_lt_ctrl_decoder);
dissector_add_uint("wmx.mgmtmsg", MAC_MGMT_MSG_PRC_LT_CTRL, handle);
}
