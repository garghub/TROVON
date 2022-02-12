static int dissect_aim_tlv_value_icq(proto_item *ti _U_, guint16 subtype _U_, tvbuff_t *tvb _U_, packet_info *pinfo)
{
int offset = 0;
int i;
proto_item *subtype_item;
guint16 req_type, req_subtype;
proto_tree *t = proto_item_add_subtree(ti, ett_aim_icq_tlv);
proto_tree_add_item(t, hf_icq_tlv_data_chunk_size, tvb, offset, 2, ENC_LITTLE_ENDIAN);
offset += 2;
proto_tree_add_item(t, hf_icq_tlv_request_owner_uid, tvb, offset, 4, ENC_LITTLE_ENDIAN);
offset += 4;
proto_tree_add_item(t, hf_icq_tlv_request_type, tvb, offset, 2, ENC_LITTLE_ENDIAN);
req_type = tvb_get_letohs(tvb, offset);
offset += 2;
proto_tree_add_item(t, hf_icq_tlv_request_seq_num, tvb, offset, 2, ENC_LITTLE_ENDIAN);
offset += 2;
switch(req_type) {
case ICQ_CLI_OFFLINE_MESSAGE_REQ: return offset;
case ICQ_CLI_DELETE_OFFLINE_MSGS: return offset;
case ICQ_SRV_OFFLINE_MSGS:
break;
case ICQ_SRV_END_OF_OFFLINE_MSGS:
proto_tree_add_item(t, hf_icq_dropped_msg_flag, tvb, offset, 1, ENC_LITTLE_ENDIAN);
return offset+1;
case ICQ_CLI_META_INFO_REQ:
case ICQ_SRV_META_INFO_REPL:
req_subtype = tvb_get_letohs(tvb, offset);
subtype_item = proto_tree_add_item(t, hf_icq_meta_subtype, tvb, offset, 2, ENC_LITTLE_ENDIAN); offset+=2;
for(i = 0; icq_calls[i].name; i++) {
if(icq_calls[i].subtype == req_subtype) break;
}
col_set_str(pinfo->cinfo, COL_INFO, icq_calls[i].name?icq_calls[i].name:"Unknown ICQ Meta Call");
proto_item_append_text(subtype_item, " (%s)", icq_calls[i].name?icq_calls[i].name:"Unknown");
if(icq_calls[i].dissector)
return icq_calls[i].dissector(tvb_new_subset_remaining(tvb, offset), pinfo, t);
default:
break;
}
return offset;
}
static int dissect_aim_icq_tlv(tvbuff_t *tvb, packet_info *pinfo, proto_tree *tree)
{
return dissect_aim_tlv(tvb, pinfo, 0, tree, icq_tlv);
}
void
proto_register_aim_icq(void)
{
static hf_register_info hf[] = {
{ &hf_icq_tlv_data_chunk_size,
{ "Data chunk size", "aim_icq.chunk_size", FT_UINT16, BASE_DEC, NULL, 0x0, NULL, HFILL },
},
{ &hf_icq_tlv_request_owner_uid,
{ "Owner UID", "aim_icq.owner_uid", FT_UINT32, BASE_DEC, NULL, 0x0, NULL, HFILL},
},
{ &hf_icq_tlv_request_type,
{"Request Type", "aim_icq.request_type", FT_UINT16, BASE_DEC, VALS(aim_icq_data_types), 0x0, NULL, HFILL},
},
{ &hf_icq_tlv_request_seq_num,
{"Request Sequence Number", "aim_icq.request_seq_number", FT_UINT16, BASE_DEC, NULL, 0x0, NULL, HFILL},
},
{ &hf_icq_dropped_msg_flag,
{"Dropped messages flag", "aim_icq.offline_msgs.dropped_flag", FT_UINT8, BASE_DEC, NULL, 0x0, NULL, HFILL },
},
{ &hf_icq_meta_subtype,
{"Meta Request Subtype", "aim_icq.subtype", FT_UINT16, BASE_HEX, NULL, 0x0, NULL, HFILL },
},
};
static gint *ett[] = {
&ett_aim_icq,
&ett_aim_icq_tlv
};
proto_aim_icq = proto_register_protocol("AIM ICQ", "AIM ICQ", "aim_icq");
proto_register_field_array(proto_aim_icq, hf, array_length(hf));
proto_register_subtree_array(ett, array_length(ett));
}
void
proto_reg_handoff_aim_icq(void)
{
aim_init_family(proto_aim_icq, ett_aim_icq, FAMILY_ICQ, aim_fnac_family_icq);
}
