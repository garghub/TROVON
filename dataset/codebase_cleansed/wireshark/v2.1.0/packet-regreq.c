static int
dissect_regreq (tvbuff_t * tvb, packet_info * pinfo, proto_tree * tree, void* data _U_)
{
proto_item *it;
proto_tree *regreq_tree = NULL;
guint16 sid;
tvbuff_t *next_tvb;
sid = tvb_get_ntohs (tvb, 0);
col_add_fstr (pinfo->cinfo, COL_INFO, "Registration Request SID = %u",
sid);
if (tree)
{
it =
proto_tree_add_protocol_format (tree, proto_docsis_regreq, tvb, 0, -1,
"Registration Request");
regreq_tree = proto_item_add_subtree (it, ett_docsis_regreq);
proto_tree_add_item (regreq_tree, hf_docsis_regreq_sid, tvb, 0, 2,
ENC_BIG_ENDIAN);
}
next_tvb = tvb_new_subset_remaining (tvb, 2);
call_dissector (docsis_tlv_handle, next_tvb, pinfo, regreq_tree);
return tvb_captured_length(tvb);
}
void
proto_register_docsis_regreq (void)
{
static hf_register_info hf[] = {
{&hf_docsis_regreq_sid,
{"Service Identifier", "docsis_regreq.sid",
FT_UINT16, BASE_DEC, NULL, 0x0,
NULL, HFILL}
},
};
static gint *ett[] = {
&ett_docsis_regreq,
};
proto_docsis_regreq =
proto_register_protocol ("DOCSIS Registration Requests", "DOCSIS REG-REQ",
"docsis_regreq");
proto_register_field_array (proto_docsis_regreq, hf, array_length (hf));
proto_register_subtree_array (ett, array_length (ett));
register_dissector ("docsis_regreq", dissect_regreq, proto_docsis_regreq);
}
void
proto_reg_handoff_docsis_regreq (void)
{
dissector_handle_t docsis_regreq_handle;
docsis_regreq_handle = find_dissector ("docsis_regreq");
docsis_tlv_handle = find_dissector ("docsis_tlv");
dissector_add_uint ("docsis_mgmt", 0x06, docsis_regreq_handle);
}
