static void
dissect_sm(tvbuff_t *tvb, packet_info *pinfo, proto_tree *tree)
{
proto_item *ti;
proto_tree *sm_tree;
tvbuff_t *next_tvb = NULL;
guint32 sm_message_type;
guint32 bh_event_code = 0;
guint16 protocol;
guint16 msg_type = 0;
guint16 length;
guint16 tag;
int offset = 0;
sm_message_type = tvb_get_ntohl(tvb,offset);
col_set_str(pinfo->cinfo, COL_PROTOCOL, "SM");
col_add_fstr(pinfo->cinfo, COL_INFO, "Cisco SM Packet (%s)",
val_to_str_const(sm_message_type, sm_message_type_value_info,"reserved"));
ti = proto_tree_add_item(tree, proto_sm, tvb, offset, 0, ENC_NA);
sm_tree = proto_item_add_subtree(ti, ett_sm);
proto_tree_add_uint_format_value(sm_tree, hf_sm_sm_msg_type, tvb, offset, 4, sm_message_type,
"%s (0x%0x)", val_to_str_const(sm_message_type, sm_message_type_value, "reserved"), sm_message_type);
offset = offset + 4;
if (sm_message_type == MESSAGE_TYPE_PDU) {
proto_tree_add_item(sm_tree, hf_sm_protocol, tvb, offset, 2, ENC_BIG_ENDIAN);
protocol = tvb_get_ntohs(tvb,offset);
offset = offset + 2;
switch(protocol){
case SM_PROTOCOL_X004:
if (!tree)
return;
proto_tree_add_item(sm_tree, hf_sm_msg_id, tvb, offset, 2, ENC_BIG_ENDIAN);
offset = offset +2;
msg_type = tvb_get_ntohs(tvb,offset);
proto_tree_add_uint_format_value(sm_tree, hf_sm_msg_type, tvb, offset, 2, msg_type,
"%s (0x%0x)", val_to_str_const(msg_type, sm_pdu_type_value, "reserved"),
msg_type);
msg_type = tvb_get_ntohs(tvb,offset);
offset = offset + 2;
proto_tree_add_item(sm_tree, hf_sm_channel, tvb, offset, 2, ENC_BIG_ENDIAN);
offset = offset + 2;
proto_tree_add_item(sm_tree, hf_sm_bearer, tvb, offset, 2, ENC_BIG_ENDIAN);
offset = offset +2;
proto_tree_add_item(sm_tree, hf_sm_len, tvb, offset, 2, ENC_BIG_ENDIAN);
length = tvb_get_ntohs(tvb,offset);
offset = offset +2;
proto_item_set_len(ti, 16);
if (length > 0) {
next_tvb = tvb_new_subset_length(tvb, offset, length);
if ((msg_type == PDU_MTP3_TO_SLT || msg_type == PDU_MTP3_FROM_SLT)) {
call_dissector(q931_handle, next_tvb, pinfo, tree);
} else {
call_dissector(data_handle, next_tvb, pinfo, tree);
}
}
break;
case SM_PROTOCOL_X100:
case SM_PROTOCOL_X122:
if (!tree)
return;
proto_tree_add_item(sm_tree, hf_sm_len, tvb, offset, 2, ENC_BIG_ENDIAN);
length = tvb_get_ntohs(tvb,offset);
offset = offset + 2;
proto_item_set_len(ti, 8);
next_tvb = tvb_new_subset_length(tvb, offset, length);
call_dissector(data_handle, next_tvb, pinfo, sm_tree);
break;
case SM_PROTOCOL_X101:
if (!tree)
return;
proto_tree_add_item(sm_tree, hf_sm_len, tvb, offset, 2, ENC_BIG_ENDIAN);
length = tvb_get_ntohs(tvb,offset);
offset = offset + 2;
proto_item_set_len(ti, length + offset);
proto_tree_add_item(sm_tree, hf_sm_ip_addr, tvb, offset, 4, ENC_BIG_ENDIAN);
offset = offset + 4;
proto_tree_add_item(sm_tree, hf_sm_context, tvb, offset, 4, ENC_BIG_ENDIAN);
offset = offset +4;
proto_tree_add_item(sm_tree, hf_sm_eisup_msg_id, tvb, offset, 1, ENC_BIG_ENDIAN);
offset = offset + 1;
proto_tree_add_item(sm_tree, hf_sm_tag, tvb, offset, 2, ENC_BIG_ENDIAN);
tag = tvb_get_ntohs(tvb,offset);
offset = offset +2;
if (tag== 0x01ac) {
proto_tree_add_item(sm_tree, hf_sm_len, tvb, offset, 2, ENC_BIG_ENDIAN);
length = tvb_get_ntohs(tvb,offset);
offset = offset +2;
next_tvb = tvb_new_subset_length(tvb, offset, length);
call_dissector(sdp_handle, next_tvb, pinfo, sm_tree);
}
break;
case SM_PROTOCOL_X114:
if (!tree)
return;
proto_tree_add_item(sm_tree, hf_sm_len, tvb, offset, 2, ENC_BIG_ENDIAN);
length = tvb_get_ntohs(tvb,offset);
offset = offset + 2;
proto_item_set_len(ti, length + offset);
proto_tree_add_item(sm_tree, hf_sm_ip_addr, tvb, offset, 4, ENC_BIG_ENDIAN);
offset = offset + 4;
proto_tree_add_item(sm_tree, hf_sm_context, tvb, offset, 4, ENC_BIG_ENDIAN);
offset = offset +4;
proto_tree_add_item(sm_tree, hf_sm_eisup_msg_id, tvb, offset, 1, ENC_BIG_ENDIAN);
offset = offset + 1;
proto_tree_add_item(sm_tree, hf_sm_tag, tvb, offset, 2, ENC_BIG_ENDIAN);
tag = tvb_get_ntohs(tvb,offset);
offset = offset +2;
if (tag== 0x01ac) {
proto_tree_add_item(sm_tree, hf_sm_len, tvb, offset, 2, ENC_BIG_ENDIAN);
length = tvb_get_ntohs(tvb,offset);
offset = offset +2;
next_tvb = tvb_new_subset_length(tvb, offset, length);
call_dissector(sdp_handle, next_tvb, pinfo, sm_tree);
}
break;
default:
proto_tree_add_item(sm_tree, hf_sm_msg_id, tvb, offset, 2, ENC_BIG_ENDIAN);
offset = offset +2;
msg_type = tvb_get_ntohs(tvb,offset);
proto_tree_add_uint_format_value(sm_tree, hf_sm_msg_type, tvb, offset, 2, msg_type,
"%s (0x%0x)", val_to_str_const(msg_type, sm_pdu_type_value, "reserved"),
msg_type);
msg_type = tvb_get_ntohs(tvb,offset);
offset = offset + 2;
proto_tree_add_item(sm_tree, hf_sm_channel, tvb, offset, 2, ENC_BIG_ENDIAN);
offset = offset + 2;
proto_tree_add_item(sm_tree, hf_sm_bearer, tvb, offset, 2, ENC_BIG_ENDIAN);
offset = offset +2;
proto_tree_add_item(sm_tree, hf_sm_len, tvb, offset, 2, ENC_BIG_ENDIAN);
length = tvb_get_ntohs(tvb,offset);
offset = offset +2;
proto_item_set_len(ti, 16);
if (length > 0) {
next_tvb = tvb_new_subset_length(tvb, offset, length);
switch (msg_type) {
case PDU_MTP3_TO_SLT:
case PDU_MTP3_FROM_SLT:
call_dissector(mtp3_handle, next_tvb, pinfo, tree);
break;
case PDU_CONNECT_REQUEST:
case PDU_CONNECT_CONFIRM:
proto_tree_add_item(sm_tree, hf_sm_alignment_type, tvb, offset, 4, ENC_BIG_ENDIAN);
break;
case PDU_DISCONNECT_CONFIRM:
case PDU_DISCONNECT_INDICATION:
proto_tree_add_item(sm_tree, hf_sm_backhaul_reason_code, tvb, offset, 4, ENC_BIG_ENDIAN);
break;
case PDU_RETRIEVAL_REQUEST:
case PDU_RETRIEVAL_CONFIRM:
proto_tree_add_item(sm_tree, hf_sm_retrieval_type, tvb, offset, 4, ENC_BIG_ENDIAN);
if (msg_type == PDU_RETRIEVAL_CONFIRM && tvb_get_ntohl(tvb,offset) == 0x01) {
offset += 4;
proto_tree_add_item(sm_tree, hf_sm_bsn_num, tvb, offset, 4, ENC_BIG_ENDIAN);
}
break;
case PDU_LSC_REQUEST:
case PDU_LSC_CONFIRM:
proto_tree_add_item(sm_tree, hf_sm_lsc_state_type, tvb, offset, 4, ENC_BIG_ENDIAN);
break;
case PDU_LSC_INDICATION:
proto_tree_add_item(sm_tree, hf_sm_backhaul_event_code, tvb, offset, 4, ENC_BIG_ENDIAN);
bh_event_code = tvb_get_ntohl(tvb,offset);
if (bh_event_code == 0x02 || bh_event_code == 0x04) {
offset += 4;
proto_tree_add_item(sm_tree, hf_sm_linkdown_cause_code, tvb, offset, 4, ENC_BIG_ENDIAN);
} else if (bh_event_code == 0x06) {
offset += 4;
proto_tree_add_item(sm_tree, hf_sm_backhaul_cause_code, tvb, offset, 4, ENC_BIG_ENDIAN);
}
break;
case PDU_STAT_REQUEST:
proto_tree_add_item(sm_tree, hf_sm_stat_request_type, tvb, offset, 4, ENC_BIG_ENDIAN);
break;
default:
call_dissector(data_handle, next_tvb, pinfo, tree);
}
}
}
}
}
void
proto_register_sm(void)
{
static hf_register_info hf[] = {
{ &hf_sm_sm_msg_type,
{ "SM Message Type", "sm.sm_msg_type",
FT_UINT32, BASE_HEX, NULL, 0x0,
NULL, HFILL }
},
{ &hf_sm_protocol,
{ "Protocol Type", "sm.protocol",
FT_UINT16, BASE_HEX, NULL, 0x0,
NULL, HFILL }
},
{ &hf_sm_msg_id,
{ "Message ID", "sm.msgid",
FT_UINT16, BASE_HEX, NULL, 0x0,
NULL, HFILL }
},
{ &hf_sm_msg_type,
{ "Message Type", "sm.msg_type",
FT_UINT16, BASE_HEX, NULL, 0x0,
NULL, HFILL }
},
{ &hf_sm_channel,
{ "Channel ID", "sm.channel",
FT_UINT16, BASE_HEX, NULL, 0x0,
NULL, HFILL }
},
{ &hf_sm_bearer,
{ "Bearer ID", "sm.bearer",
FT_UINT16, BASE_HEX, NULL, 0x0,
NULL, HFILL }
},
{ &hf_sm_len,
{ "Length", "sm.len",
FT_UINT16, BASE_DEC, NULL, 0x0,
NULL, HFILL }
},
{ &hf_sm_ip_addr,
{ "IPv4 address","sm.ip_addr",
FT_IPv4,BASE_NONE, NULL, 0x0,
NULL, HFILL }
},
{ &hf_sm_context,
{ "Context","sm.context",
FT_UINT32, BASE_DEC, NULL, 0x0,
"Context(guesswork!)", HFILL }
},
{ &hf_sm_eisup_msg_id,
{ "Message id","sm.eisup_message_id",
FT_UINT8, BASE_DEC, NULL, 0x0,
"Message id(guesswork!)", HFILL }
},
{ &hf_sm_tag,
{ "Tag","sm.tag",
FT_UINT16, BASE_DEC, NULL, 0x0,
"Tag(guesswork!)", HFILL }
},
{ &hf_sm_alignment_type,
{ "Alignment type","sm.connect_type",
FT_UINT32, BASE_HEX, VALS(sm_alignment_type), 0x0,
NULL, HFILL }
},
{ &hf_sm_backhaul_reason_code,
{ "Backhaul reason code","sm.backhaul_reason",
FT_UINT32, BASE_HEX, VALS(sm_backhaul_reason_code), 0x0,
NULL, HFILL }
},
{ &hf_sm_backhaul_event_code,
{ "Backhaul event code","sm.backhaul_event",
FT_UINT32, BASE_HEX, VALS(sm_backhaul_event_code), 0x0,
NULL, HFILL }
},
{ &hf_sm_backhaul_cause_code,
{ "Backhaul cause code","sm.backhaul_cause",
FT_UINT32, BASE_HEX, VALS(sm_backhaul_cause_code), 0x0,
NULL, HFILL }
},
{ &hf_sm_linkdown_cause_code,
{ "Link down cause","sm.linkdown_reason",
FT_UINT32, BASE_HEX, VALS(sm_linkdown_cause_code), 0x0,
NULL, HFILL }
},
{ &hf_sm_retrieval_type,
{ "Retrieval type","sm.retrieval_type",
FT_UINT32, BASE_HEX, VALS(sm_retrieval_type), 0x0,
NULL, HFILL }
},
{ &hf_sm_lsc_state_type,
{ "LSC Request type","sm.lsc_state_type",
FT_UINT32, BASE_HEX, VALS(sm_lsc_state_type), 0x0,
NULL, HFILL }
},
{ &hf_sm_stat_request_type,
{ "Statistic request type","sm.stat_request_type",
FT_UINT32, BASE_HEX, VALS(sm_stat_request_type), 0x0,
NULL, HFILL }
},
{ &hf_sm_bsn_num,
{ "BSN","sm.bsn_num",
FT_UINT32, BASE_DEC, NULL, 0x0,
NULL, HFILL }
},
};
static gint *ett[] = {
&ett_sm,
};
proto_sm = proto_register_protocol("Cisco Session Management",
"SM", "sm");
register_dissector("sm", dissect_sm, proto_sm);
proto_register_field_array(proto_sm, hf, array_length(hf));
proto_register_subtree_array(ett, array_length(ett));
}
void
proto_reg_handoff_sm(void)
{
sdp_handle = find_dissector("sdp");
mtp3_handle = find_dissector("mtp3");
q931_handle = find_dissector("q931");
data_handle = find_dissector("data");
}
