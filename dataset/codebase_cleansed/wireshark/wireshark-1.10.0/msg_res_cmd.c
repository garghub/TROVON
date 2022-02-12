void dissect_mac_mgmt_msg_res_cmd_decoder(tvbuff_t *tvb, packet_info *pinfo, proto_tree *tree)
{
guint offset = 0;
guint tvb_len, payload_type;
gint tlv_type, tlv_len, tlv_value_offset;
proto_item *res_cmd_item = NULL;
proto_tree *res_cmd_tree = NULL;
proto_tree *tlv_tree = NULL;
tlv_info_t tlv_info;
payload_type = tvb_get_guint8(tvb, offset);
if(payload_type != MAC_MGMT_MSG_RES_CMD)
{
return;
}
if(tree)
{
tvb_len = tvb_reported_length(tvb);
res_cmd_item = proto_tree_add_protocol_format(tree, proto_mac_mgmt_msg_res_cmd_decoder, tvb, offset, tvb_len, "Reset Command (RES-CMD) (%u bytes)", tvb_len);
res_cmd_tree = proto_item_add_subtree(res_cmd_item, ett_mac_mgmt_msg_res_cmd_decoder);
proto_tree_add_item(res_cmd_tree, hf_res_cmd_message_type, tvb, offset, 1, ENC_BIG_ENDIAN);
offset++;
while(offset < tvb_len)
{
init_tlv_info(&tlv_info, tvb, offset);
tlv_type = get_tlv_type(&tlv_info);
tlv_len = get_tlv_length(&tlv_info);
if(tlv_type == -1 || tlv_len > MAX_TLV_LEN || tlv_len < 1)
{
col_append_sep_str(pinfo->cinfo, COL_INFO, NULL, "RES-CMD TLV error");
proto_tree_add_item(res_cmd_tree, hf_res_cmd_invalid_tlv, tvb, offset, (tvb_len - offset), ENC_NA);
break;
}
tlv_value_offset = get_tlv_value_offset(&tlv_info);
#ifdef DEBUG
proto_tree_add_protocol_format(res_cmd_tree, proto_mac_mgmt_msg_res_cmd_decoder, tvb, offset, (tlv_len + tlv_value_offset), "RES-CMD Type: %u (%u bytes, offset=%u, tlv_len=%u, tvb_len=%u)", tlv_type, (tlv_len + tlv_value_offset), offset, tlv_len, tvb_len);
#endif
offset += tlv_value_offset;
switch (tlv_type)
{
case HMAC_TUPLE:
tlv_tree = add_protocol_subtree(&tlv_info, ett_mac_mgmt_msg_res_cmd_decoder, res_cmd_tree, proto_mac_mgmt_msg_res_cmd_decoder, tvb, offset, tlv_len, "HMAC Tuple (%u byte(s))", tlv_len);
wimax_hmac_tuple_decoder(tlv_tree, tvb, offset, tlv_len);
break;
case CMAC_TUPLE:
tlv_tree = add_protocol_subtree(&tlv_info, ett_mac_mgmt_msg_res_cmd_decoder, res_cmd_tree, proto_mac_mgmt_msg_res_cmd_decoder, tvb, offset, tlv_len, "CMAC Tuple (%u byte(s))", tlv_len);
wimax_cmac_tuple_decoder(tlv_tree, tvb, offset, tlv_len);
break;
default:
tlv_tree = add_tlv_subtree(&tlv_info, ett_mac_mgmt_msg_res_cmd_decoder, res_cmd_tree, hf_res_cmd_unknown_type, tvb, offset, tlv_len, FALSE);
proto_tree_add_item(tlv_tree, hf_res_cmd_unknown_type, tvb, offset, tlv_len, ENC_NA);
break;
}
offset += tlv_len;
}
}
}
void proto_register_mac_mgmt_msg_res_cmd(void)
{
static hf_register_info hf_res_cmd[] =
{
{
&hf_res_cmd_message_type,
{"MAC Management Message Type", "wmx.macmgtmsgtype.res_cmd", FT_UINT8, BASE_DEC, NULL, 0x0, NULL, HFILL}
},
{
&hf_res_cmd_invalid_tlv,
{"Invalid TLV", "wmx.res_cmd.invalid_tlv", FT_BYTES, BASE_NONE, NULL, 0, NULL, HFILL}
},
{
&hf_res_cmd_unknown_type,
{"Unknown TLV type", "wmx.res_cmd.unknown_tlv_type", FT_BYTES, BASE_NONE, NULL, 0x0, NULL, HFILL}
}
};
static gint *ett_res_cmd[] =
{
&ett_mac_mgmt_msg_res_cmd_decoder,
};
proto_mac_mgmt_msg_res_cmd_decoder = proto_register_protocol (
"WiMax RES-CMD Message",
"WiMax RES-CMD (res)",
"wmx.res"
);
proto_register_field_array(proto_mac_mgmt_msg_res_cmd_decoder, hf_res_cmd, array_length(hf_res_cmd));
proto_register_subtree_array(ett_res_cmd, array_length(ett_res_cmd));
}
