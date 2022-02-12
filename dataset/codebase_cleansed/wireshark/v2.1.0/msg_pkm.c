static int dissect_mac_mgmt_msg_pkm_req_decoder(tvbuff_t *tvb, packet_info *pinfo, proto_tree *tree, void* data _U_)
{
guint offset = 0;
proto_item *pkm_item;
proto_tree *pkm_tree;
pkm_item = proto_tree_add_protocol_format(tree, proto_mac_mgmt_msg_pkm_decoder, tvb, offset, -1, "Privacy Key Management Request (PKM-REQ)");
pkm_tree = proto_item_add_subtree(pkm_item, ett_mac_mgmt_msg_pkm_req_decoder);
proto_tree_add_item(pkm_tree, hf_pkm_msg_code, tvb, offset, 1, ENC_BIG_ENDIAN);
offset++;
proto_tree_add_item(pkm_tree, hf_pkm_msg_pkm_id, tvb, offset, 1, ENC_BIG_ENDIAN);
offset++;
wimax_pkm_tlv_encoded_attributes_decoder(tvb_new_subset_remaining(tvb, offset), pinfo, pkm_tree);
return tvb_captured_length(tvb);
}
static int dissect_mac_mgmt_msg_pkm_rsp_decoder(tvbuff_t *tvb, packet_info *pinfo, proto_tree *tree, void* data _U_)
{
guint offset = 0;
proto_item *pkm_item;
proto_tree *pkm_tree;
pkm_item = proto_tree_add_protocol_format(tree, proto_mac_mgmt_msg_pkm_decoder, tvb, offset, -1, "Privacy Key Management Response (PKM-RSP)");
pkm_tree = proto_item_add_subtree(pkm_item, ett_mac_mgmt_msg_pkm_rsp_decoder);
proto_tree_add_item(pkm_tree, hf_pkm_msg_code, tvb, offset, 1, ENC_BIG_ENDIAN);
offset++;
proto_tree_add_item(pkm_tree, hf_pkm_msg_pkm_id, tvb, offset, 1, ENC_BIG_ENDIAN);
offset++;
wimax_pkm_tlv_encoded_attributes_decoder(tvb_new_subset_remaining(tvb, offset), pinfo, pkm_tree);
return tvb_captured_length(tvb);
}
void proto_register_mac_mgmt_msg_pkm(void)
{
static hf_register_info hf_pkm[] =
{
{
&hf_pkm_msg_code,
{"Code", "wmx.pkm.msg_code",FT_UINT8, BASE_DEC, VALS(vals_pkm_msg_code),0x0, NULL, HFILL}
},
{
&hf_pkm_msg_pkm_id,
{"PKM Identifier", "wmx.pkm.msg_pkm_identifier",FT_UINT8, BASE_DEC, NULL, 0x0, NULL, HFILL}
},
};
static gint *ett_pkm[] =
{
&ett_mac_mgmt_msg_pkm_req_decoder,
&ett_mac_mgmt_msg_pkm_rsp_decoder,
};
proto_mac_mgmt_msg_pkm_decoder = proto_register_protocol (
"WiMax PKM-REQ/RSP Messages",
"WiMax PKM-REQ/RSP (pkm)",
"wmx.pkm"
);
proto_register_field_array(proto_mac_mgmt_msg_pkm_decoder, hf_pkm, array_length(hf_pkm));
proto_register_subtree_array(ett_pkm, array_length(ett_pkm));
}
void proto_reg_handoff_mac_mgmt_msg_pkm(void)
{
dissector_handle_t mac_mgmt_msg_pkm_req_handle;
dissector_handle_t mac_mgmt_msg_pkm_rsp_handle;
mac_mgmt_msg_pkm_req_handle = create_dissector_handle(dissect_mac_mgmt_msg_pkm_req_decoder, proto_mac_mgmt_msg_pkm_decoder);
dissector_add_uint( "wmx.mgmtmsg", MAC_MGMT_MSG_PKM_REQ, mac_mgmt_msg_pkm_req_handle );
mac_mgmt_msg_pkm_rsp_handle = create_dissector_handle(dissect_mac_mgmt_msg_pkm_rsp_decoder, proto_mac_mgmt_msg_pkm_decoder);
dissector_add_uint( "wmx.mgmtmsg", MAC_MGMT_MSG_PKM_RSP, mac_mgmt_msg_pkm_rsp_handle );
}
