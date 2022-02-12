static int dissect_mac_mgmt_msg_dsd_req_decoder(tvbuff_t *tvb, packet_info *pinfo, proto_tree *tree, void* data _U_)
{
guint offset = 0;
guint tvb_len, tlv_len, tlv_value_offset;
gint tlv_type;
proto_item *dsd_item;
proto_tree *dsd_tree;
proto_tree *tlv_tree = NULL;
tlv_info_t tlv_info;
{
tvb_len = tvb_reported_length(tvb);
dsd_item = proto_tree_add_protocol_format(tree, proto_mac_mgmt_msg_dsd_decoder, tvb, offset, -1,
"Dynamic Service Deletion Request (DSD-REQ)");
dsd_tree = proto_item_add_subtree(dsd_item, ett_mac_mgmt_msg_dsd_req_decoder);
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
switch (tlv_type)
{
case HMAC_TUPLE:
tlv_tree = add_protocol_subtree(&tlv_info, ett_mac_mgmt_msg_dsd_req_decoder, dsd_tree, proto_mac_mgmt_msg_dsd_decoder, tvb, offset, tlv_len, "HMAC Tuple");
wimax_hmac_tuple_decoder(tlv_tree, tvb, offset+tlv_value_offset, tlv_len);
break;
case CMAC_TUPLE:
tlv_tree = add_protocol_subtree(&tlv_info, ett_mac_mgmt_msg_dsd_req_decoder, dsd_tree, proto_mac_mgmt_msg_dsd_decoder, tvb, offset, tlv_len, "CMAC Tuple");
wimax_cmac_tuple_decoder(tlv_tree, tvb, offset+tlv_value_offset, tlv_len);
break;
default:
add_tlv_subtree(&tlv_info, dsd_tree, hf_dsd_unknown_type, tvb, offset, ENC_NA);
break;
}
offset += (tlv_len+tlv_value_offset);
}
}
return tvb_captured_length(tvb);
}
static int dissect_mac_mgmt_msg_dsd_rsp_decoder(tvbuff_t *tvb, packet_info *pinfo, proto_tree *tree, void* data _U_)
{
guint offset = 0;
guint tvb_len, tlv_len, tlv_value_offset;
gint tlv_type;
proto_item *dsd_item;
proto_tree *dsd_tree;
proto_tree *tlv_tree = NULL;
tlv_info_t tlv_info;
{
tvb_len = tvb_reported_length(tvb);
dsd_item = proto_tree_add_protocol_format(tree, proto_mac_mgmt_msg_dsd_decoder, tvb, offset, -1,
"Dynamic Service Deletion Response (DSD-RSP)");
dsd_tree = proto_item_add_subtree(dsd_item, ett_mac_mgmt_msg_dsd_rsp_decoder);
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
switch (tlv_type)
{
case HMAC_TUPLE:
tlv_tree = add_protocol_subtree(&tlv_info, ett_mac_mgmt_msg_dsd_req_decoder, dsd_tree, proto_mac_mgmt_msg_dsd_decoder, tvb, offset, tlv_len, "HMAC Tuple");
wimax_hmac_tuple_decoder(tlv_tree, tvb, offset+tlv_value_offset, tlv_len);
break;
case CMAC_TUPLE:
tlv_tree = add_protocol_subtree(&tlv_info, ett_mac_mgmt_msg_dsd_req_decoder, dsd_tree, proto_mac_mgmt_msg_dsd_decoder, tvb, offset, tlv_len, "CMAC Tuple");
wimax_cmac_tuple_decoder(tlv_tree, tvb, offset+tlv_value_offset, tlv_len);
break;
default:
add_tlv_subtree(&tlv_info, dsd_tree, hf_dsd_unknown_type, tvb, offset, ENC_NA);
break;
}
offset += (tlv_len+tlv_value_offset);
}
}
return tvb_captured_length(tvb);
}
void proto_register_mac_mgmt_msg_dsd(void)
{
static hf_register_info hf[] =
{
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
proto_mac_mgmt_msg_dsd_decoder = proto_register_protocol (
"WiMax DSD Messages",
"WiMax DSD",
"wmx.dsd"
);
proto_register_field_array(proto_mac_mgmt_msg_dsd_decoder, hf, array_length(hf));
proto_register_subtree_array(ett, array_length(ett));
}
void
proto_reg_handoff_mac_mgmt_msg_dsd(void)
{
dissector_handle_t dsd_handle;
dsd_handle = create_dissector_handle(dissect_mac_mgmt_msg_dsd_req_decoder, proto_mac_mgmt_msg_dsd_decoder);
dissector_add_uint("wmx.mgmtmsg", MAC_MGMT_MSG_DSD_REQ, dsd_handle);
dsd_handle = create_dissector_handle(dissect_mac_mgmt_msg_dsd_rsp_decoder, proto_mac_mgmt_msg_dsd_decoder);
dissector_add_uint("wmx.mgmtmsg", MAC_MGMT_MSG_DSD_RSP, dsd_handle);
}
