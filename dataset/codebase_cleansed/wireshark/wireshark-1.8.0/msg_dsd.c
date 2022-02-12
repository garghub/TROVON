void dissect_mac_mgmt_msg_dsd_req_decoder(tvbuff_t *tvb, packet_info *pinfo, proto_tree *tree)
{
guint offset = 0;
guint tvb_len, payload_type, tlv_len, tlv_value_offset;
gint tlv_type;
proto_item *dsd_item = NULL;
proto_tree *dsd_tree = NULL;
proto_tree *tlv_tree = NULL;
tlv_info_t tlv_info;
if(tree)
{
payload_type = tvb_get_guint8(tvb, offset);
if(payload_type != MAC_MGMT_MSG_DSD_REQ)
return;
tvb_len = tvb_reported_length(tvb);
dsd_item = proto_tree_add_protocol_format(tree, proto_mac_mgmt_msg_dsd_decoder, tvb, offset, tvb_len,
"%s (%u bytes)", val_to_str(payload_type, vals_dsd_msgs, "Unknown"), tvb_len);
dsd_tree = proto_item_add_subtree(dsd_item, ett_mac_mgmt_msg_dsd_req_decoder);
proto_tree_add_item(dsd_tree, hf_dsd_req_message_type, tvb, offset, 1, ENC_BIG_ENDIAN);
offset++;
proto_tree_add_item(dsd_tree, hf_dsd_transaction_id, tvb, offset, 2, ENC_BIG_ENDIAN);
offset += 2;
proto_tree_add_item(dsd_tree, hf_dsd_service_flow_id, tvb, offset, 4, ENC_BIG_ENDIAN);
offset += 4;
while(offset < tvb_len)
{
init_tlv_info(&tlv_info, tvb, offset);
tlv_type = get_tlv_type(&tlv_info);
tlv_len = get_tlv_length(&tlv_info);
if(tlv_type == -1 || tlv_len > MAX_TLV_LEN || tlv_len < 1)
{
col_append_sep_str(pinfo->cinfo, COL_INFO, NULL, "DSD-REQ TLV error");
proto_tree_add_item(dsd_tree, hf_dsd_invalid_tlv, tvb, offset, (tvb_len - offset), ENC_NA);
break;
}
tlv_value_offset = get_tlv_value_offset(&tlv_info);
#ifdef DEBUG
proto_tree_add_protocol_format(dsd_tree, proto_mac_mgmt_msg_dsd_decoder, tvb, offset, tlv_len + tlv_value_offset, "DSD-REQ TLV Type: %u (%u bytes, offset=%u, tvb_len=%u)", tlv_type, tlv_len + tlv_value_offset, offset, tvb_len);
#endif
offset += tlv_value_offset;
switch (tlv_type)
{
case HMAC_TUPLE:
tlv_tree = add_protocol_subtree(&tlv_info, ett_mac_mgmt_msg_dsd_req_decoder, dsd_tree, proto_mac_mgmt_msg_dsd_decoder, tvb, offset, tlv_len, "HMAC Tuple (%u byte(s))", tlv_len);
wimax_hmac_tuple_decoder(tlv_tree, tvb, offset, tlv_len);
break;
case CMAC_TUPLE:
tlv_tree = add_protocol_subtree(&tlv_info, ett_mac_mgmt_msg_dsd_req_decoder, dsd_tree, proto_mac_mgmt_msg_dsd_decoder, tvb, offset, tlv_len, "CMAC Tuple (%u byte(s))", tlv_len);
wimax_cmac_tuple_decoder(tlv_tree, tvb, offset, tlv_len);
break;
default:
tlv_tree = add_protocol_subtree(&tlv_info, ett_mac_mgmt_msg_dsd_req_decoder, dsd_tree, proto_mac_mgmt_msg_dsd_decoder, tvb, offset, tlv_len, "Unknown TLV (%u byte(s))", tlv_len);
proto_tree_add_item(tlv_tree, hf_dsd_unknown_type, tvb, (offset - tlv_value_offset), (tlv_len + tlv_value_offset), ENC_NA);
break;
}
offset += tlv_len;
}
}
}
void dissect_mac_mgmt_msg_dsd_rsp_decoder(tvbuff_t *tvb, packet_info *pinfo, proto_tree *tree)
{
guint offset = 0;
guint tvb_len, payload_type, tlv_len, tlv_value_offset;
gint tlv_type;
proto_item *dsd_item = NULL;
proto_tree *dsd_tree = NULL;
proto_tree *tlv_tree = NULL;
tlv_info_t tlv_info;
if(tree)
{
payload_type = tvb_get_guint8(tvb, offset);
if(payload_type != MAC_MGMT_MSG_DSD_RSP)
return;
tvb_len = tvb_reported_length(tvb);
dsd_item = proto_tree_add_protocol_format(tree, proto_mac_mgmt_msg_dsd_decoder, tvb, offset, tvb_len,
"%s (%u bytes)", val_to_str(payload_type, vals_dsd_msgs, "Unknown"), tvb_len);
dsd_tree = proto_item_add_subtree(dsd_item, ett_mac_mgmt_msg_dsd_rsp_decoder);
proto_tree_add_item(dsd_tree, hf_dsd_rsp_message_type, tvb, offset, 1, ENC_NA);
offset++;
proto_tree_add_item(dsd_tree, hf_dsd_transaction_id, tvb, offset, 2, ENC_BIG_ENDIAN);
offset += 2;
proto_tree_add_item(dsd_tree, hf_dsd_confirmation_code, tvb, offset, 1, ENC_BIG_ENDIAN);
offset++;
proto_tree_add_item(dsd_tree, hf_dsd_service_flow_id, tvb, offset, 4, ENC_BIG_ENDIAN);
offset += 4;
while(offset < tvb_len)
{
init_tlv_info(&tlv_info, tvb, offset);
tlv_type = get_tlv_type(&tlv_info);
tlv_len = get_tlv_length(&tlv_info);
if(tlv_type == -1 || tlv_len > MAX_TLV_LEN || tlv_len < 1)
{
col_append_sep_str(pinfo->cinfo, COL_INFO, NULL, "DSD RSP TLV error");
proto_tree_add_item(dsd_tree, hf_dsd_invalid_tlv, tvb, offset, (tvb_len - offset), ENC_NA);
break;
}
tlv_value_offset = get_tlv_value_offset(&tlv_info);
#ifdef DEBUG
proto_tree_add_protocol_format(dsd_tree, proto_mac_mgmt_msg_dsd_decoder, tvb, offset, tlv_len + tlv_value_offset, "DSD-RSP TLV Type: %u (%u bytes, offset=%u, tvb_len=%u)", tlv_type, tlv_len + tlv_value_offset, offset, tvb_len);
#endif
offset += tlv_value_offset;
switch (tlv_type)
{
case HMAC_TUPLE:
tlv_tree = add_protocol_subtree(&tlv_info, ett_mac_mgmt_msg_dsd_req_decoder, dsd_tree, proto_mac_mgmt_msg_dsd_decoder, tvb, offset, tlv_len, "HMAC Tuple (%u byte(s))", tlv_len);
wimax_hmac_tuple_decoder(tlv_tree, tvb, offset, tlv_len);
break;
case CMAC_TUPLE:
tlv_tree = add_protocol_subtree(&tlv_info, ett_mac_mgmt_msg_dsd_req_decoder, dsd_tree, proto_mac_mgmt_msg_dsd_decoder, tvb, offset, tlv_len, "CMAC Tuple (%u byte(s))", tlv_len);
wimax_cmac_tuple_decoder(tlv_tree, tvb, offset, tlv_len);
break;
default:
tlv_tree = add_protocol_subtree(&tlv_info, ett_mac_mgmt_msg_dsd_req_decoder, dsd_tree, proto_mac_mgmt_msg_dsd_decoder, tvb, offset, tlv_len, "Unknown TLV (%u byte(s))", tlv_len);
proto_tree_add_item(tlv_tree, hf_dsd_unknown_type, tvb, (offset - tlv_value_offset), (tlv_len + tlv_value_offset), ENC_NA);
break;
}
offset += tlv_len;
}
}
}
void proto_register_mac_mgmt_msg_dsd(void)
{
static hf_register_info hf[] =
{
{
&hf_dsd_req_message_type,
{
"MAC Management Message Type", "wmx.macmgtmsgtype.dsd_req",
FT_UINT8, BASE_DEC, NULL, 0x0, NULL, HFILL
}
},
{
&hf_dsd_rsp_message_type,
{
"MAC Management Message Type", "wmx.macmgtmsgtype.dsd_rsp",
FT_BYTES, BASE_NONE, NULL, 0, NULL, HFILL
}
},
{
&hf_dsd_confirmation_code,
{
"Confirmation code", "wmx.dsd.confirmation_code",
FT_UINT8, BASE_HEX, NULL, 0x0, NULL, HFILL
}
},
{
&hf_dsd_service_flow_id,
{
"Service Flow ID", "wmx.dsd.service_flow_id",
FT_UINT32, BASE_HEX, NULL, 0x0, NULL, HFILL
}
},
{
&hf_dsd_transaction_id,
{
"Transaction ID", "wmx.dsd.transaction_id",
FT_UINT16, BASE_HEX, NULL, 0x0, NULL, HFILL
}
},
{
&hf_dsd_invalid_tlv,
{
"Invalid TLV", "wmx.dsd.invalid_tlv",
FT_BYTES, BASE_NONE, NULL, 0x0, NULL, HFILL
}
},
{
&hf_dsd_unknown_type,
{
"Unknown type", "wmx.dsd.unknown_type",
FT_BYTES, BASE_NONE, NULL, 0x0, NULL, HFILL
}
}
};
static gint *ett[] =
{
&ett_mac_mgmt_msg_dsd_req_decoder,
&ett_mac_mgmt_msg_dsd_rsp_decoder,
};
proto_mac_mgmt_msg_dsd_decoder = proto_mac_mgmt_msg_dsa_decoder;
proto_register_field_array(proto_mac_mgmt_msg_dsd_decoder, hf, array_length(hf));
proto_register_subtree_array(ett, array_length(ett));
}
