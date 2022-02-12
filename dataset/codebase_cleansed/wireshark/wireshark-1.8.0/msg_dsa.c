void dissect_mac_mgmt_msg_dsa_req_decoder(tvbuff_t *tvb, packet_info *pinfo, proto_tree *tree)
{
guint offset = 0;
guint tvb_len, payload_type;
proto_item *dsa_item = NULL;
proto_tree *dsa_tree = NULL;
if(tree)
{
payload_type = tvb_get_guint8(tvb, offset);
if(payload_type != MAC_MGMT_MSG_DSA_REQ)
return;
tvb_len = tvb_reported_length(tvb);
dsa_item = proto_tree_add_protocol_format(tree, proto_mac_mgmt_msg_dsa_decoder, tvb, offset, tvb_len,
"%s (%u bytes)", val_to_str(payload_type, vals_dsa_msgs, "Unknown"), tvb_len);
dsa_tree = proto_item_add_subtree(dsa_item, ett_mac_mgmt_msg_dsa_req_decoder);
proto_tree_add_item(dsa_tree, hf_dsa_req_message_type, tvb, offset, 1, ENC_BIG_ENDIAN);
offset++;
proto_tree_add_item(dsa_tree, hf_dsa_transaction_id, tvb, offset, 2, ENC_BIG_ENDIAN);
offset += 2;
wimax_common_tlv_encoding_decoder(tvb_new_subset(tvb, offset, (tvb_len - offset), (tvb_len - offset)), pinfo, dsa_tree);
}
}
void dissect_mac_mgmt_msg_dsa_rsp_decoder(tvbuff_t *tvb, packet_info *pinfo, proto_tree *tree)
{
guint offset = 0;
guint tvb_len, payload_type;
proto_item *dsa_item = NULL;
proto_tree *dsa_tree = NULL;
if(tree)
{
payload_type = tvb_get_guint8(tvb, offset);
if(payload_type != MAC_MGMT_MSG_DSA_RSP)
return;
tvb_len = tvb_reported_length(tvb);
dsa_item = proto_tree_add_protocol_format(tree, proto_mac_mgmt_msg_dsa_decoder, tvb, offset, tvb_len,
"%s (%u bytes)", val_to_str(payload_type, vals_dsa_msgs, "Unknown"), tvb_len);
dsa_tree = proto_item_add_subtree(dsa_item, ett_mac_mgmt_msg_dsa_rsp_decoder);
proto_tree_add_item(dsa_tree, hf_dsa_rsp_message_type, tvb, offset, 1, ENC_BIG_ENDIAN);
offset++;
proto_tree_add_item(dsa_tree, hf_dsa_transaction_id, tvb, offset, 2, ENC_BIG_ENDIAN);
offset += 2;
proto_tree_add_item(dsa_tree, hf_dsa_confirmation_code, tvb, offset, 1, ENC_BIG_ENDIAN);
offset++;
wimax_common_tlv_encoding_decoder(tvb_new_subset(tvb, offset, (tvb_len - offset), (tvb_len - offset)), pinfo, dsa_tree);
}
}
void dissect_mac_mgmt_msg_dsa_ack_decoder(tvbuff_t *tvb, packet_info *pinfo, proto_tree *tree)
{
guint offset = 0;
guint tvb_len, payload_type;
proto_item *dsa_item = NULL;
proto_tree *dsa_tree = NULL;
if(tree)
{
payload_type = tvb_get_guint8(tvb, offset);
if(payload_type != MAC_MGMT_MSG_DSA_ACK)
return;
tvb_len = tvb_reported_length(tvb);
dsa_item = proto_tree_add_protocol_format(tree, proto_mac_mgmt_msg_dsa_decoder, tvb, offset, tvb_len,
"%s (%u bytes)", val_to_str(payload_type, vals_dsa_msgs, "Unknown"), tvb_len);
dsa_tree = proto_item_add_subtree(dsa_item, ett_mac_mgmt_msg_dsa_ack_decoder);
proto_tree_add_item(dsa_tree, hf_dsa_ack_message_type, tvb, offset, 1, ENC_BIG_ENDIAN);
offset++;
proto_tree_add_item(dsa_tree, hf_dsa_transaction_id, tvb, offset, 2, ENC_BIG_ENDIAN);
offset += 2;
proto_tree_add_item(dsa_tree, hf_dsa_confirmation_code, tvb, offset, 1, ENC_BIG_ENDIAN);
offset++;
wimax_common_tlv_encoding_decoder(tvb_new_subset(tvb, offset, (tvb_len - offset), (tvb_len - offset)), pinfo, dsa_tree);
}
}
void proto_register_mac_mgmt_msg_dsa(void)
{
static hf_register_info hf[] =
{
{
&hf_dsa_ack_message_type,
{
"MAC Management Message Type", "wmx.macmgtmsgtype.dsa_ack",
FT_UINT8, BASE_DEC, NULL, 0x0, NULL, HFILL
}
},
{
&hf_dsa_req_message_type,
{
"MAC Management Message Type", "wmx.macmgtmsgtype.dsa_req",
FT_UINT8, BASE_DEC, NULL, 0x0, NULL, HFILL
}
},
{
&hf_dsa_rsp_message_type,
{
"MAC Management Message Type", "wmx.macmgtmsgtype.dsa_rsp",
FT_UINT8, BASE_DEC, NULL, 0x0, NULL, HFILL
}
},
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
"WiMax DSA/C/D Messages",
"WiMax DSA/C/D (ds)",
"wmx.ds"
);
proto_register_field_array(proto_mac_mgmt_msg_dsa_decoder, hf, array_length(hf));
proto_register_subtree_array(ett, array_length(ett));
}
