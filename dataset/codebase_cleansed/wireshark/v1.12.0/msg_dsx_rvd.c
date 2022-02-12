static void dissect_mac_mgmt_msg_dsx_rvd_decoder(tvbuff_t *tvb, packet_info *pinfo _U_, proto_tree *tree)
{
guint offset = 0;
proto_item *dsx_rvd_item;
proto_tree *dsx_rvd_tree;
{
dsx_rvd_item = proto_tree_add_protocol_format(tree, proto_mac_mgmt_msg_dsx_rvd_decoder, tvb, offset, -1, "DSx Received (DSX-RVD)");
dsx_rvd_tree = proto_item_add_subtree(dsx_rvd_item, ett_mac_mgmt_msg_dsx_rvd_decoder);
proto_tree_add_item(dsx_rvd_tree, hf_dsx_rvd_transaction_id, tvb, offset, 2, ENC_BIG_ENDIAN);
offset += 2;
proto_tree_add_item(dsx_rvd_tree, hf_dsx_rvd_confirmation_code, tvb, offset, 1, ENC_BIG_ENDIAN);
}
}
void proto_register_mac_mgmt_msg_dsx_rvd(void)
{
static hf_register_info hf_dsx_rvd[] =
{
{
&hf_dsx_rvd_confirmation_code,
{ "Confirmation code", "wmx.dsx_rvd.confirmation_code", FT_UINT8, BASE_HEX, NULL, 0x0, NULL, HFILL}
},
{
&hf_dsx_rvd_transaction_id,
{ "Transaction ID", "wmx.dsx_rvd.transaction_id", FT_UINT16, BASE_HEX, NULL, 0x0, NULL, HFILL}
}
};
static gint *ett[] =
{
&ett_mac_mgmt_msg_dsx_rvd_decoder,
};
proto_mac_mgmt_msg_dsx_rvd_decoder = proto_register_protocol (
"WiMax DSX-RVD Message",
"WiMax DSX-RVD (dsx_rvd)",
"wmx.dsx_rvd"
);
proto_register_field_array(proto_mac_mgmt_msg_dsx_rvd_decoder, hf_dsx_rvd, array_length(hf_dsx_rvd));
proto_register_subtree_array(ett, array_length(ett));
}
void
proto_reg_handoff_mac_mgmt_msg_dsx_rvd(void)
{
dissector_handle_t handle;
handle = create_dissector_handle(dissect_mac_mgmt_msg_dsx_rvd_decoder, proto_mac_mgmt_msg_dsx_rvd_decoder);
dissector_add_uint("wmx.mgmtmsg", MAC_MGMT_MSG_DSX_RVD, handle);
}
