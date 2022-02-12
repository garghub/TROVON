void dissect_mac_mgmt_msg_pkm_req_decoder(tvbuff_t *tvb, packet_info *pinfo, proto_tree *tree)
{
guint offset = 0;
guint tvb_len, payload_type, length;
proto_item *pkm_item = NULL;
proto_tree *pkm_tree = NULL;
payload_type = tvb_get_guint8(tvb, offset);
if(payload_type != MAC_MGMT_MSG_PKM_REQ)
{
return;
}
{
tvb_len = tvb_reported_length(tvb);
pkm_item = proto_tree_add_protocol_format(tree, proto_mac_mgmt_msg_pkm_decoder, tvb, offset, tvb_len, "Privacy Key Management Request (PKM-REQ) (%u bytes)", tvb_len);
pkm_tree = proto_item_add_subtree(pkm_item, ett_mac_mgmt_msg_pkm_req_decoder);
proto_tree_add_item(pkm_tree, hf_pkm_req_message_type, tvb, offset, 1, ENC_BIG_ENDIAN);
offset++;
proto_tree_add_item(pkm_tree, hf_pkm_msg_code, tvb, offset, 1, ENC_BIG_ENDIAN);
offset++;
proto_tree_add_item(pkm_tree, hf_pkm_msg_pkm_id, tvb, offset, 1, ENC_BIG_ENDIAN);
offset++;
length = tvb_len - offset;
wimax_pkm_tlv_encoded_attributes_decoder(tvb_new_subset(tvb, offset, length, length), pinfo, pkm_tree);
}
}
void dissect_mac_mgmt_msg_pkm_rsp_decoder(tvbuff_t *tvb, packet_info *pinfo, proto_tree *tree)
{
guint offset = 0;
guint tvb_len, payload_type, length;
proto_item *pkm_item = NULL;
proto_tree *pkm_tree = NULL;
payload_type = tvb_get_guint8(tvb, offset);
if(payload_type != MAC_MGMT_MSG_PKM_RSP)
{
return;
}
{
tvb_len = tvb_reported_length(tvb);
pkm_item = proto_tree_add_protocol_format(tree, proto_mac_mgmt_msg_pkm_decoder, tvb, offset, tvb_len, "Privacy Key Management Response (PKM-RSP) (%u bytes)", tvb_len);
pkm_tree = proto_item_add_subtree(pkm_item, ett_mac_mgmt_msg_pkm_rsp_decoder);
proto_tree_add_item(pkm_tree, hf_pkm_rsp_message_type, tvb, offset, 1, ENC_BIG_ENDIAN);
offset++;
proto_tree_add_item(pkm_tree, hf_pkm_msg_code, tvb, offset, 1, ENC_BIG_ENDIAN);
offset++;
proto_tree_add_item(pkm_tree, hf_pkm_msg_pkm_id, tvb, offset, 1, ENC_BIG_ENDIAN);
offset++;
length = tvb_len - offset;
wimax_pkm_tlv_encoded_attributes_decoder(tvb_new_subset(tvb, offset, length, length), pinfo, pkm_tree);
}
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
{
&hf_pkm_req_message_type,
{"MAC Management Message Type", "wmx.macmgtmsgtype.pkm_req", FT_UINT8, BASE_DEC, NULL, 0x0, NULL, HFILL}
},
{
&hf_pkm_rsp_message_type,
{"MAC Management Message Type", "wmx.macmgtmsgtype.pkm_rsp", FT_UINT8, BASE_DEC, NULL, 0x0, NULL, HFILL}
}
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
