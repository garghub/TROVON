static int
dissect_regreqmp (tvbuff_t * tvb, packet_info * pinfo, proto_tree * tree, void* data _U_)
{
proto_item *it;
proto_tree *regreqmp_tree = NULL;
tvbuff_t *next_tvb;
col_set_str(pinfo->cinfo, COL_INFO, "REG-REQ-MP Message:");
if (tree)
{
it = proto_tree_add_protocol_format (tree, proto_docsis_regreqmp, tvb, 0, -1,"REG-REQ-MP Message");
regreqmp_tree = proto_item_add_subtree (it, ett_docsis_regreqmp);
proto_tree_add_item (regreqmp_tree, hf_docsis_regreqmp_sid, tvb, 0, 2, ENC_BIG_ENDIAN);
proto_tree_add_item (regreqmp_tree, hf_docsis_regreqmp_number_of_fragments, tvb, 2, 1, ENC_BIG_ENDIAN);
proto_tree_add_item (regreqmp_tree, hf_docsis_regreqmp_fragment_sequence_number, tvb, 3, 1, ENC_BIG_ENDIAN);
}
next_tvb = tvb_new_subset_remaining (tvb, 4);
call_dissector (docsis_tlv_handle, next_tvb, pinfo, regreqmp_tree);
return tvb_captured_length(tvb);
}
void
proto_register_docsis_regreqmp (void)
{
static hf_register_info hf[] = {
{&hf_docsis_regreqmp_sid,
{"Sid", "docsis_regreqmp.sid",
FT_UINT16, BASE_DEC, NULL, 0x0,
"Reg-Req-Mp Sid", HFILL}
},
{&hf_docsis_regreqmp_number_of_fragments,
{"Number of Fragments", "docsis_regreqmp.number_of_fragments",
FT_UINT8, BASE_DEC, NULL, 0x0,
"Reg-Req-Mp Number of Fragments", HFILL}
},
{&hf_docsis_regreqmp_fragment_sequence_number,
{"Fragment Sequence Number", "docsis_regreqmp.fragment_sequence_number",
FT_UINT8, BASE_DEC, NULL, 0x0,
"Reg-Req-Mp Fragment Sequence Number", HFILL}
},
};
static gint *ett[] = {
&ett_docsis_regreqmp,
};
proto_docsis_regreqmp =
proto_register_protocol ("DOCSIS Registration Request Multipart",
"DOCSIS Reg-Req-Mp", "docsis_regreqmp");
proto_register_field_array (proto_docsis_regreqmp, hf, array_length (hf));
proto_register_subtree_array (ett, array_length (ett));
register_dissector ("docsis_regreqmp", dissect_regreqmp, proto_docsis_regreqmp);
}
void
proto_reg_handoff_docsis_regreqmp (void)
{
dissector_handle_t docsis_regreqmp_handle;
docsis_tlv_handle = find_dissector ("docsis_tlv");
docsis_regreqmp_handle = find_dissector ("docsis_regreqmp");
dissector_add_uint ("docsis_mgmt", 44, docsis_regreqmp_handle);
}
