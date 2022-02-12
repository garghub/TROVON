static void dissect_dreg_tlv(proto_tree *dreg_tree, gint tlv_type, tvbuff_t *tvb, guint tlv_offset, guint tlv_len)
{
switch (tlv_type) {
case DREG_PAGING_INFO:
proto_tree_add_item(dreg_tree, hf_dreg_paging_cycle, tvb, tlv_offset, 2, ENC_BIG_ENDIAN);
proto_tree_add_item(dreg_tree, hf_dreg_paging_offset, tvb, tlv_offset + 2, 1, ENC_BIG_ENDIAN);
proto_tree_add_item(dreg_tree, hf_dreg_paging_group_id, tvb, tlv_offset + 3, 2, ENC_BIG_ENDIAN);
break;
case DREG_REQ_DURATION:
proto_tree_add_item(dreg_tree, hf_dreg_req_duration, tvb, tlv_offset, 1, ENC_BIG_ENDIAN);
break;
case DREG_PAGING_CONTROLLER_ID:
proto_tree_add_item(dreg_tree, hf_paging_controller_id, tvb, tlv_offset, 6, ENC_NA);
break;
case DREG_IDLE_MODE_RETAIN_INFO:
proto_tree_add_item(dreg_tree, hf_dreg_retain_ms_service_sbc, tvb, tlv_offset, 1, ENC_BIG_ENDIAN);
proto_tree_add_item(dreg_tree, hf_dreg_retain_ms_service_pkm, tvb, tlv_offset, 1, ENC_BIG_ENDIAN);
proto_tree_add_item(dreg_tree, hf_dreg_retain_ms_service_reg, tvb, tlv_offset, 1, ENC_BIG_ENDIAN);
proto_tree_add_item(dreg_tree, hf_dreg_retain_ms_service_network_address, tvb, tlv_offset, 1, ENC_BIG_ENDIAN);
proto_tree_add_item(dreg_tree, hf_dreg_retain_ms_service_tod, tvb, tlv_offset, 1, ENC_BIG_ENDIAN);
proto_tree_add_item(dreg_tree, hf_dreg_retain_ms_service_tftp, tvb, tlv_offset, 1, ENC_BIG_ENDIAN);
proto_tree_add_item(dreg_tree, hf_dreg_retain_ms_service_full_service, tvb, tlv_offset, 1, ENC_BIG_ENDIAN);
proto_tree_add_item(dreg_tree, hf_dreg_consider_paging_pref, tvb, tlv_offset, 1, ENC_BIG_ENDIAN);
break;
case DREG_MAC_HASH_SKIP_THRESHOLD:
proto_tree_add_item(dreg_tree, hf_mac_hash_skip_threshold, tvb, tlv_offset, 2, ENC_BIG_ENDIAN);
break;
case DREG_PAGING_CYCLE_REQUEST:
proto_tree_add_item(dreg_tree, hf_dreg_paging_cycle_request, tvb, tlv_offset, 2, ENC_BIG_ENDIAN);
break;
default:
proto_tree_add_item(dreg_tree, hf_tlv_value, tvb, tlv_offset, tlv_len, ENC_NA);
break;
}
}
void proto_register_mac_mgmt_msg_dreg_req(void)
{
static hf_register_info hf[] =
{
{
&hf_dreg_consider_paging_pref,
{
"Consider Paging Preference of each Service Flow in resource retention", "wmx.dreg.consider_paging_preference",
FT_UINT8, BASE_DEC, NULL, 0x80, NULL, HFILL
}
},
{
&hf_dreg_invalid_tlv,
{
"Invalid TLV", "wmx.dreg.invalid_tlv",
FT_BYTES, BASE_NONE, NULL, 0, NULL, HFILL
}
},
{
&hf_mac_hash_skip_threshold,
{
"MAC Hash Skip Threshold", "wmx.dreg.mac_hash_skip_threshold",
FT_UINT16, BASE_DEC, NULL, 0x0, NULL, HFILL
}
},
{
&hf_paging_controller_id,
{
"Paging Controller ID", "wmx.dreg.paging_controller_id",
FT_ETHER, BASE_NONE, NULL, 0x0, NULL, HFILL
}
},
{
&hf_dreg_paging_cycle,
{
"PAGING CYCLE", "wmx.dreg.paging_cycle",
FT_UINT16, BASE_DEC, NULL, 0x0, NULL, HFILL
}
},
{
&hf_dreg_paging_cycle_request,
{
"Paging Cycle Request", "wmx.dreg.paging_cycle_request",
FT_UINT16, BASE_DEC, NULL, 0x0, NULL, HFILL
}
},
{
&hf_dreg_paging_group_id,
{
"Paging-group-ID", "wmx.dreg.paging_group_id",
FT_UINT16, BASE_DEC, NULL, 0x0, NULL, HFILL
}
},
{
&hf_dreg_paging_offset,
{
"PAGING OFFSET", "wmx.dreg.paging_offset",
FT_UINT8, BASE_DEC, NULL, 0x0, NULL, HFILL
}
},
{
&hf_dreg_req_duration,
{
"REQ-duration (Waiting value for the DREG-REQ message re-transmission in frames)", "wmx.dreg.req_duration",
FT_UINT8, BASE_DEC, NULL, 0x0, NULL, HFILL
}
},
{
&hf_dreg_retain_ms_service_full_service,
{
"Retain MS service and operation information associated with Full service", "wmx.dreg.retain_ms_full_service",
FT_UINT8, BASE_DEC, NULL, 0x40, NULL, HFILL
}
},
{
&hf_dreg_retain_ms_service_network_address,
{
"Retain MS service and operational information associated with Network Address", "wmx.dreg.retain_ms_service_network_address",
FT_UINT8, BASE_DEC, NULL, 0x08, NULL, HFILL
}
},
{
&hf_dreg_retain_ms_service_pkm,
{
"Retain MS service and operational information associated with PKM-REQ/RSP", "wmx.dreg.retain_ms_service_pkm",
FT_UINT8, BASE_DEC, NULL, 0x02, NULL, HFILL
}
},
{
&hf_dreg_retain_ms_service_reg,
{
"Retain MS service and operational information associated with REG-REQ/RSP", "wmx.dreg.retain_ms_service_reg",
FT_UINT8, BASE_DEC, NULL, 0x04, NULL, HFILL
}
},
{
&hf_dreg_retain_ms_service_sbc,
{
"Retain MS service and operational information associated with SBC-REQ/RSP", "wmx.dreg.retain_ms_service_sbc",
FT_UINT8, BASE_DEC, NULL, 0x01, NULL, HFILL
}
},
{
&hf_dreg_retain_ms_service_tftp,
{
"Retain MS service and operational information associated with TFTP messages", "wmx.dreg.retain_ms_service_tftp",
FT_UINT8, BASE_DEC, NULL, 0x20, NULL, HFILL
}
},
{
&hf_dreg_retain_ms_service_tod,
{
"Retain MS service and operational information associated with Time of Day", "wmx.dreg.retain_ms_service_tod",
FT_UINT8, BASE_DEC, NULL, 0x10, NULL, HFILL
}
},
{
&hf_dreg_cmd_action,
{
"DREG-CMD Action code", "wmx.dreg_cmd.action",
FT_UINT8, BASE_DEC, VALS(vals_dreg_cmd_action), 0x07, NULL, HFILL
}
},
{
&hf_dreg_cmd_action_cor2,
{
"DREG-CMD Action code", "wmx.dreg_cmd.action",
FT_UINT8, BASE_DEC, VALS(vals_dreg_cmd_action_cor2), 0x07, NULL, HFILL
}
},
{
&hf_dreg_cmd_reserved,
{
"Reserved", "wmx.dreg_cmd.action_reserved",
FT_UINT8, BASE_DEC, NULL, 0xF8, NULL, HFILL
}
},
{
&hf_dreg_req_action,
{
"DREG-REQ Action code", "wmx.dreg_req.action",
FT_UINT8, BASE_DEC, VALS(vals_dreg_req_code), 0x03, NULL, HFILL
}
},
{
&hf_dreg_req_reserved,
{
"Reserved", "wmx.dreg_req.action_reserved",
FT_UINT8, BASE_DEC, NULL, 0xFC, NULL, HFILL
}
},
{
&hf_tlv_value,
{
"Value", "wmx.dreg.unknown_tlv_value",
FT_BYTES, BASE_NONE, NULL, 0x00, NULL, HFILL
}
},
#if 0
{
&hf_ack_type_reserved,
{
"Reserved", "wmx.ack_type_reserved",
FT_UINT8, BASE_DEC, NULL, 0x03, NULL, HFILL
}
}
#endif
};
proto_mac_mgmt_msg_dreg_req_decoder = proto_register_protocol (
"WiMax DREG-REQ Messages",
"WiMax DREG-REQ",
"wmx.dreg_req"
);
proto_register_field_array(proto_mac_mgmt_msg_dreg_req_decoder, hf, array_length(hf));
proto_register_subtree_array(ett, array_length(ett));
}
void proto_register_mac_mgmt_msg_dreg_cmd(void)
{
proto_mac_mgmt_msg_dreg_cmd_decoder = proto_register_protocol (
"WiMax DREG-CMD Messages",
"WiMax DREG-CMD",
"wmx.dreg_cmd"
);
}
static int dissect_mac_mgmt_msg_dreg_req_decoder(tvbuff_t *tvb, packet_info *pinfo, proto_tree *tree, void* data _U_)
{
guint offset = 0;
guint tlv_offset;
guint tvb_len;
proto_item *dreg_req_item;
proto_tree *dreg_req_tree;
proto_tree *tlv_tree = NULL;
tlv_info_t tlv_info;
gint tlv_type;
gint tlv_len;
gboolean hmac_found = FALSE;
{
tvb_len = tvb_reported_length(tvb);
dreg_req_item = proto_tree_add_protocol_format(tree, proto_mac_mgmt_msg_dreg_req_decoder, tvb, 0, -1, "MAC Management Message, DREG-REQ");
dreg_req_tree = proto_item_add_subtree(dreg_req_item, ett_mac_mgmt_msg_dreg_decoder);
proto_tree_add_item(dreg_req_tree, hf_dreg_req_action, tvb, offset, 1, ENC_BIG_ENDIAN);
proto_tree_add_item(dreg_req_tree, hf_dreg_req_reserved, tvb, offset, 1, ENC_BIG_ENDIAN);
offset++;
while(offset < tvb_len)
{
init_tlv_info(&tlv_info, tvb, offset);
tlv_type = get_tlv_type(&tlv_info);
tlv_len = get_tlv_length(&tlv_info);
if(tlv_type == -1 || tlv_len > MAX_TLV_LEN || tlv_len < 1)
{
col_append_sep_str(pinfo->cinfo, COL_INFO, NULL, "DREG-REQ TLV error");
proto_tree_add_item(dreg_req_tree, hf_dreg_invalid_tlv, tvb, offset, (tvb_len - offset), ENC_NA);
break;
}
tlv_offset = offset + get_tlv_value_offset(&tlv_info);
switch (tlv_type) {
case HMAC_TUPLE:
tlv_tree = add_protocol_subtree(&tlv_info, ett_mac_mgmt_msg_dreg_decoder, dreg_req_tree, proto_mac_mgmt_msg_dreg_req_decoder, tvb, offset, tlv_len, "HMAC Tuple");
wimax_hmac_tuple_decoder(tlv_tree, tvb, tlv_offset, tlv_len);
hmac_found = TRUE;
break;
case CMAC_TUPLE:
tlv_tree = add_protocol_subtree(&tlv_info, ett_mac_mgmt_msg_dreg_decoder, dreg_req_tree, proto_mac_mgmt_msg_dreg_req_decoder, tvb, offset, tlv_len, "CMAC Tuple");
wimax_cmac_tuple_decoder(tlv_tree, tvb, tlv_offset, tlv_len);
break;
default:
tlv_tree = add_protocol_subtree(&tlv_info, ett_mac_mgmt_msg_dreg_decoder, dreg_req_tree, proto_mac_mgmt_msg_dreg_req_decoder, tvb, offset, tlv_len, "DREG-REQ sub-TLV's");
dissect_dreg_tlv(tlv_tree, tlv_type, tvb, tlv_offset, tlv_len);
break;
}
offset = tlv_len + tlv_offset;
}
if (!hmac_found)
proto_item_append_text(dreg_req_tree, " (HMAC Tuple is missing !)");
}
return tvb_captured_length(tvb);
}
static int dissect_mac_mgmt_msg_dreg_cmd_decoder(tvbuff_t *tvb, packet_info *pinfo, proto_tree *tree, void* data _U_)
{
guint offset = 0;
guint tlv_offset;
guint tvb_len;
proto_item *dreg_cmd_item;
proto_tree *dreg_cmd_tree;
proto_tree *tlv_tree = NULL;
tlv_info_t tlv_info;
gint tlv_type;
gint tlv_len;
gboolean hmac_found = FALSE;
{
tvb_len = tvb_reported_length(tvb);
dreg_cmd_item = proto_tree_add_protocol_format(tree, proto_mac_mgmt_msg_dreg_cmd_decoder, tvb, 0, -1, "MAC Management Message, DREG-CMD");
dreg_cmd_tree = proto_item_add_subtree(dreg_cmd_item, ett_mac_mgmt_msg_dreg_decoder);
if (include_cor2_changes)
proto_tree_add_item(dreg_cmd_tree, hf_dreg_cmd_action_cor2, tvb, offset, 1, ENC_BIG_ENDIAN);
else
proto_tree_add_item(dreg_cmd_tree, hf_dreg_cmd_action, tvb, offset, 1, ENC_BIG_ENDIAN);
proto_tree_add_item(dreg_cmd_tree, hf_dreg_cmd_reserved, tvb, offset, 1, ENC_BIG_ENDIAN);
offset ++;
while(offset < tvb_len)
{
init_tlv_info(&tlv_info, tvb, offset);
tlv_type = get_tlv_type(&tlv_info);
tlv_len = get_tlv_length(&tlv_info);
if(tlv_type == -1 || tlv_len > MAX_TLV_LEN || tlv_len < 1)
{
col_append_sep_str(pinfo->cinfo, COL_INFO, NULL, "DREG-CMD TLV error");
proto_tree_add_item(dreg_cmd_tree, hf_dreg_invalid_tlv, tvb, offset, (tvb_len - offset), ENC_NA);
break;
}
tlv_offset = offset + get_tlv_value_offset(&tlv_info);
switch (tlv_type) {
case HMAC_TUPLE:
tlv_tree = add_protocol_subtree(&tlv_info, ett_mac_mgmt_msg_dreg_decoder, dreg_cmd_tree, proto_mac_mgmt_msg_dreg_cmd_decoder, tvb, offset, tlv_len, "HMAC Tuple");
wimax_hmac_tuple_decoder(tlv_tree, tvb, tlv_offset, tlv_len);
hmac_found = TRUE;
break;
case CMAC_TUPLE:
tlv_tree = add_protocol_subtree(&tlv_info, ett_mac_mgmt_msg_dreg_decoder, dreg_cmd_tree, proto_mac_mgmt_msg_dreg_cmd_decoder, tvb, offset, tlv_len, "CMAC Tuple");
wimax_cmac_tuple_decoder(tlv_tree, tvb, tlv_offset, tlv_len);
break;
default:
tlv_tree = add_protocol_subtree(&tlv_info, ett_mac_mgmt_msg_dreg_decoder, dreg_cmd_tree, proto_mac_mgmt_msg_dreg_cmd_decoder, tvb, offset, tlv_len, "DREG-CMD sub-TLV's");
dissect_dreg_tlv(tlv_tree, tlv_type, tvb, tlv_offset, tlv_len);
break;
}
offset = tlv_len + tlv_offset;
}
if (!hmac_found)
proto_item_append_text(dreg_cmd_tree, " (HMAC Tuple is missing !)");
}
return tvb_captured_length(tvb);
}
void
proto_reg_handoff_mac_mgmt_msg_dreg(void)
{
dissector_handle_t dreg_handle;
dreg_handle = create_dissector_handle(dissect_mac_mgmt_msg_dreg_req_decoder, proto_mac_mgmt_msg_dreg_req_decoder);
dissector_add_uint("wmx.mgmtmsg", MAC_MGMT_MSG_DREG_REQ, dreg_handle);
dreg_handle = create_dissector_handle(dissect_mac_mgmt_msg_dreg_cmd_decoder, proto_mac_mgmt_msg_dreg_cmd_decoder);
dissector_add_uint("wmx.mgmtmsg", MAC_MGMT_MSG_DREG_CMD, dreg_handle);
}
