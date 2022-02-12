static int
dissect_ans(tvbuff_t *tvb, packet_info *pinfo, proto_tree *tree, void* data _U_)
{
proto_item *ti;
proto_tree *ans_tree = NULL;
guint16 sender_id;
guint32 seq_num;
col_set_str(pinfo->cinfo, COL_PROTOCOL, "Intel ANS probe");
seq_num = tvb_get_ntohl(tvb, 4);
sender_id = tvb_get_ntohs(tvb, 8);
col_add_fstr(pinfo->cinfo, COL_INFO, "Sequence: %u, Sender ID %u, Team ID %s",
seq_num, sender_id, tvb_ether_to_str(tvb, 10));
if (tree) {
ti = proto_tree_add_item(tree, proto_ans, tvb, 0, -1, ENC_NA);
ans_tree = proto_item_add_subtree(ti, ett_ans);
proto_tree_add_item(ans_tree, hf_ans_app_id, tvb, 0, 2, ENC_BIG_ENDIAN);
proto_tree_add_item(ans_tree, hf_ans_rev_id, tvb, 2, 2, ENC_BIG_ENDIAN);
proto_tree_add_item(ans_tree, hf_ans_seq_num, tvb, 4, 4, ENC_BIG_ENDIAN);
proto_tree_add_item(ans_tree, hf_ans_sender_id, tvb, 8, 2, ENC_BIG_ENDIAN);
proto_tree_add_item(ans_tree, hf_ans_team_id, tvb, 10, 6, ENC_NA);
}
return tvb_captured_length(tvb);
}
void
proto_register_ans(void)
{
static hf_register_info hf[] = {
{ &hf_ans_app_id,
{ "Application ID", "ans.app_id",
FT_UINT16, BASE_HEX, NULL, 0,
"Intel ANS Application ID", HFILL }
},
{ &hf_ans_rev_id,
{ "Revision ID", "ans.rev_id",
FT_UINT16, BASE_HEX, NULL, 0,
"Intel ANS Revision ID", HFILL }
},
{ &hf_ans_seq_num,
{ "Sequence Number", "ans.seq_num",
FT_UINT32, BASE_DEC, NULL, 0,
"Intel ANS Sequence Number", HFILL }
},
{ &hf_ans_sender_id,
{ "Sender ID", "ans.sender_id",
FT_UINT16, BASE_DEC, NULL, 0,
"Intel ANS Sender ID", HFILL }
},
{ &hf_ans_team_id,
{ "Team ID", "ans.team_id",
FT_ETHER, BASE_NONE, NULL, 0,
"Intel ANS Team ID", HFILL }
},
};
static gint *ett[] = {
&ett_ans,
};
proto_ans = proto_register_protocol("Intel ANS probe", "ANS", "ans");
proto_register_field_array(proto_ans, hf, array_length(hf));
proto_register_subtree_array(ett, array_length(ett));
}
void
proto_reg_handoff_ans(void)
{
dissector_handle_t ans_handle;
ans_handle = create_dissector_handle(dissect_ans, proto_ans);
dissector_add_uint("ethertype", ETHERTYPE_INTEL_ANS, ans_handle);
}
