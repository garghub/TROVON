static int
dissect_dsareq (tvbuff_t * tvb, packet_info * pinfo, proto_tree * tree, void* data _U_)
{
proto_item *it;
proto_tree *dsareq_tree = NULL;
guint16 transid;
tvbuff_t *next_tvb;
transid = tvb_get_ntohs (tvb, 0);
col_add_fstr (pinfo->cinfo, COL_INFO,
"Dynamic Service Addition Request Tran-id = %u", transid);
if (tree)
{
it =
proto_tree_add_protocol_format (tree, proto_docsis_dsareq, tvb, 0, -1,
"DSA Request");
dsareq_tree = proto_item_add_subtree (it, ett_docsis_dsareq);
proto_tree_add_item (dsareq_tree, hf_docsis_dsareq_tranid, tvb, 0, 2,
ENC_BIG_ENDIAN);
}
next_tvb = tvb_new_subset_remaining (tvb, 2);
call_dissector (docsis_tlv_handle, next_tvb, pinfo, dsareq_tree);
return tvb_captured_length(tvb);
}
void
proto_register_docsis_dsareq (void)
{
static hf_register_info hf[] = {
{&hf_docsis_dsareq_tranid,
{"Transaction Id", "docsis_dsareq.tranid",
FT_UINT16, BASE_DEC, NULL, 0x0,
NULL, HFILL}
},
};
static gint *ett[] = {
&ett_docsis_dsareq,
};
proto_docsis_dsareq =
proto_register_protocol ("DOCSIS Dynamic Service Addition Request",
"DOCSIS DSA-REQ", "docsis_dsareq");
proto_register_field_array (proto_docsis_dsareq, hf, array_length (hf));
proto_register_subtree_array (ett, array_length (ett));
register_dissector ("docsis_dsareq", dissect_dsareq, proto_docsis_dsareq);
}
void
proto_reg_handoff_docsis_dsareq (void)
{
dissector_handle_t docsis_dsareq_handle;
docsis_dsareq_handle = find_dissector ("docsis_dsareq");
docsis_tlv_handle = find_dissector ("docsis_tlv");
dissector_add_uint ("docsis_mgmt", 0x0F, docsis_dsareq_handle);
}
