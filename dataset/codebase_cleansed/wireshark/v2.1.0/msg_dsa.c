static int dissect_mac_mgmt_msg_dsa_req_decoder(tvbuff_t *tvb, packet_info *pinfo, proto_tree *tree, void* data _U_)
{
guint offset = 0;
proto_item *dsa_item;
proto_tree *dsa_tree;
{
dsa_item = proto_tree_add_protocol_format(tree, proto_mac_mgmt_msg_dsa_decoder, tvb, offset, -1,
"Dynamic Service Addition Request (DSA-REQ)");
dsa_tree = proto_item_add_subtree(dsa_item, ett_mac_mgmt_msg_dsa_req_decoder);
proto_tree_add_item(dsa_tree, hf_dsa_transaction_id, tvb, offset, 2, ENC_BIG_ENDIAN);
offset += 2;
wimax_common_tlv_encoding_decoder(tvb_new_subset_remaining(tvb, offset), pinfo, dsa_tree);
}
return tvb_captured_length(tvb);
}
static int dissect_mac_mgmt_msg_dsa_rsp_decoder(tvbuff_t *tvb, packet_info *pinfo, proto_tree *tree, void* data _U_)
{
guint offset = 0;
proto_item *dsa_item;
proto_tree *dsa_tree;
{
dsa_item = proto_tree_add_protocol_format(tree, proto_mac_mgmt_msg_dsa_decoder, tvb, offset, -1,
"Dynamic Service Addition Response (DSA-RSP)");
dsa_tree = proto_item_add_subtree(dsa_item, ett_mac_mgmt_msg_dsa_rsp_decoder);
proto_tree_add_item(dsa_tree, hf_dsa_transaction_id, tvb, offset, 2, ENC_BIG_ENDIAN);
offset += 2;
proto_tree_add_item(dsa_tree, hf_dsa_confirmation_code, tvb, offset, 1, ENC_BIG_ENDIAN);
offset++;
wimax_common_tlv_encoding_decoder(tvb_new_subset_remaining(tvb, offset), pinfo, dsa_tree);
}
return tvb_captured_length(tvb);
}
static int dissect_mac_mgmt_msg_dsa_ack_decoder(tvbuff_t *tvb, packet_info *pinfo, proto_tree *tree, void* data _U_)
{
guint offset = 0;
proto_item *dsa_item;
proto_tree *dsa_tree;
{
dsa_item = proto_tree_add_protocol_format(tree, proto_mac_mgmt_msg_dsa_decoder, tvb, offset, -1,
"Dynamic Service Addition Acknowledge (DSA-ACK)");
dsa_tree = proto_item_add_subtree(dsa_item, ett_mac_mgmt_msg_dsa_ack_decoder);
proto_tree_add_item(dsa_tree, hf_dsa_transaction_id, tvb, offset, 2, ENC_BIG_ENDIAN);
offset += 2;
proto_tree_add_item(dsa_tree, hf_dsa_confirmation_code, tvb, offset, 1, ENC_BIG_ENDIAN);
offset++;
wimax_common_tlv_encoding_decoder(tvb_new_subset_remaining(tvb, offset), pinfo, dsa_tree);
}
return tvb_captured_length(tvb);
}
void proto_register_mac_mgmt_msg_dsa(void)
{
static hf_register_info hf[] =
{
{
&hf_dsa_confirmation_code,
{
"Confirmation code", "wmx.dsa.confirmation_code",
FT_UINT8, BASE_HEX, NULL, 0x0, NULL, HFILL
}
},
{
&hf_dsa_transaction_id,
{
"Transaction ID", "wmx.dsa.transaction_id",
FT_UINT16, BASE_HEX, NULL, 0x0, NULL, HFILL
}
}
};
static gint *ett[] =
{
&ett_mac_mgmt_msg_dsa_req_decoder,
&ett_mac_mgmt_msg_dsa_rsp_decoder,
&ett_mac_mgmt_msg_dsa_ack_decoder,
};
proto_mac_mgmt_msg_dsa_decoder = proto_register_protocol (
"WiMax DSA Messages",
"WiMax DSA",
"wmx.dsa"
);
proto_register_field_array(proto_mac_mgmt_msg_dsa_decoder, hf, array_length(hf));
proto_register_subtree_array(ett, array_length(ett));
}
void
proto_reg_handoff_mac_mgmt_msg_dsa (void)
{
dissector_handle_t dsa_handle;
dsa_handle = create_dissector_handle(dissect_mac_mgmt_msg_dsa_req_decoder, proto_mac_mgmt_msg_dsa_decoder);
dissector_add_uint("wmx.mgmtmsg", MAC_MGMT_MSG_DSA_REQ, dsa_handle);
dsa_handle = create_dissector_handle(dissect_mac_mgmt_msg_dsa_rsp_decoder, proto_mac_mgmt_msg_dsa_decoder);
dissector_add_uint("wmx.mgmtmsg", MAC_MGMT_MSG_DSA_RSP, dsa_handle);
dsa_handle = create_dissector_handle(dissect_mac_mgmt_msg_dsa_ack_decoder, proto_mac_mgmt_msg_dsa_decoder);
dissector_add_uint("wmx.mgmtmsg", MAC_MGMT_MSG_DSA_ACK, dsa_handle);
}
