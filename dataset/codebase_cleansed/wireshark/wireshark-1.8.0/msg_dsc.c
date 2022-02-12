void dissect_mac_mgmt_msg_dsc_req_decoder(tvbuff_t *tvb, packet_info *pinfo, proto_tree *tree)
{
guint offset = 0;
guint tvb_len, payload_type;
proto_item *dsc_item = NULL;
proto_tree *dsc_tree = NULL;
if(tree)
{
payload_type = tvb_get_guint8(tvb, offset);
if(payload_type != MAC_MGMT_MSG_DSC_REQ)
return;
tvb_len = tvb_reported_length(tvb);
dsc_item = proto_tree_add_protocol_format(tree, proto_mac_mgmt_msg_dsc_decoder, tvb, offset, tvb_len,
"%s (%u bytes)", val_to_str(payload_type, vals_dsc_msgs, "Unknown"), tvb_len);
dsc_tree = proto_item_add_subtree(dsc_item, ett_mac_mgmt_msg_dsc_req_decoder);
proto_tree_add_item(dsc_tree, hf_dsc_req_message_type, tvb, offset, 1, ENC_BIG_ENDIAN);
offset++;
proto_tree_add_item(dsc_tree, hf_dsc_transaction_id, tvb, offset, 2, ENC_BIG_ENDIAN);
offset += 2;
wimax_common_tlv_encoding_decoder(tvb_new_subset(tvb, offset, (tvb_len - offset), (tvb_len - offset)), pinfo, dsc_tree);
}
}
void dissect_mac_mgmt_msg_dsc_rsp_decoder(tvbuff_t *tvb, packet_info *pinfo, proto_tree *tree)
{
guint offset = 0;
guint tvb_len, payload_type;
proto_item *dsc_item = NULL;
proto_tree *dsc_tree = NULL;
if(tree)
{
payload_type = tvb_get_guint8(tvb, offset);
if(payload_type != MAC_MGMT_MSG_DSC_RSP)
return;
tvb_len = tvb_reported_length(tvb);
dsc_item = proto_tree_add_protocol_format(tree, proto_mac_mgmt_msg_dsc_decoder, tvb, offset, tvb_len,
"%s (%u bytes)", val_to_str(payload_type, vals_dsc_msgs, "Unknown"), tvb_len);
dsc_tree = proto_item_add_subtree(dsc_item, ett_mac_mgmt_msg_dsc_rsp_decoder);
proto_tree_add_item(dsc_tree, hf_dsc_rsp_message_type, tvb, offset, 1, ENC_BIG_ENDIAN);
offset++;
proto_tree_add_item(dsc_tree, hf_dsc_transaction_id, tvb, offset, 2, ENC_BIG_ENDIAN);
offset += 2;
proto_tree_add_item(dsc_tree, hf_dsc_confirmation_code, tvb, offset, 1, ENC_BIG_ENDIAN);
offset++;
wimax_common_tlv_encoding_decoder(tvb_new_subset(tvb, offset, (tvb_len - offset), (tvb_len - offset)), pinfo, dsc_tree);
}
}
void dissect_mac_mgmt_msg_dsc_ack_decoder(tvbuff_t *tvb, packet_info *pinfo, proto_tree *tree)
{
guint offset = 0;
guint tvb_len, payload_type;
proto_item *dsc_item = NULL;
proto_tree *dsc_tree = NULL;
if(tree)
{
payload_type = tvb_get_guint8(tvb, offset);
if((payload_type < MAC_MGMT_MSG_DSC_REQ) || (payload_type > MAC_MGMT_MSG_DSC_ACK))
return;
tvb_len = tvb_reported_length(tvb);
dsc_item = proto_tree_add_protocol_format(tree, proto_mac_mgmt_msg_dsc_decoder, tvb, offset, tvb_len,
"%s (%u bytes)", val_to_str(payload_type, vals_dsc_msgs, "Unknown"), tvb_len);
dsc_tree = proto_item_add_subtree(dsc_item, ett_mac_mgmt_msg_dsc_ack_decoder);
proto_tree_add_item(dsc_tree, hf_dsc_ack_message_type, tvb, offset, 1, ENC_BIG_ENDIAN);
offset++;
proto_tree_add_item(dsc_tree, hf_dsc_transaction_id, tvb, offset, 2, ENC_BIG_ENDIAN);
offset += 2;
proto_tree_add_item(dsc_tree, hf_dsc_confirmation_code, tvb, offset, 1, ENC_BIG_ENDIAN);
offset++;
wimax_common_tlv_encoding_decoder(tvb_new_subset(tvb, offset, (tvb_len - offset), (tvb_len - offset)), pinfo, dsc_tree);
}
}
void proto_register_mac_mgmt_msg_dsc(void)
{
static hf_register_info hf[] =
{
{
&hf_dsc_ack_message_type,
{
"MAC Management Message Type", "wmx.macmgtmsgtype.dsc_ack",
FT_UINT8, BASE_DEC, NULL, 0x0, NULL, HFILL
}
},
{
&hf_dsc_req_message_type,
{
"MAC Management Message Type", "wmx.macmgtmsgtype.dsc_req",
FT_UINT8, BASE_DEC, NULL, 0x0, NULL, HFILL
}
},
{
&hf_dsc_rsp_message_type,
{
"MAC Management Message Type", "wmx.macmgtmsgtype.dsc_rsp",
FT_UINT8, BASE_DEC, NULL, 0x0, NULL, HFILL
}
},
{
&hf_dsc_confirmation_code,
{
"Confirmation code", "wmx.dsc.confirmation_code",
FT_UINT8, BASE_DEC, NULL, 0x0, NULL, HFILL
}
},
{
&hf_dsc_transaction_id,
{
"Transaction ID", "wmx.dsc.transaction_id",
FT_UINT16, BASE_DEC, NULL, 0x0, NULL, HFILL
}
}
};
static gint *ett[] =
{
&ett_mac_mgmt_msg_dsc_req_decoder,
&ett_mac_mgmt_msg_dsc_rsp_decoder,
&ett_mac_mgmt_msg_dsc_ack_decoder
};
proto_mac_mgmt_msg_dsc_decoder = proto_mac_mgmt_msg_dsa_decoder;
proto_register_field_array(proto_mac_mgmt_msg_dsc_decoder, hf, array_length(hf));
proto_register_subtree_array(ett, array_length(ett));
}
