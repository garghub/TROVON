static void
dissect_dscreq (tvbuff_t * tvb, packet_info * pinfo, proto_tree * tree)
{
proto_item *it;
proto_tree *dscreq_tree = NULL;
guint16 transid;
tvbuff_t *next_tvb;
transid = tvb_get_ntohs (tvb, 0);
col_clear (pinfo->cinfo, COL_INFO);
col_add_fstr (pinfo->cinfo, COL_INFO,
"Dynamic Service Change Request Tran-id = %u", transid);
if (tree)
{
it =
proto_tree_add_protocol_format (tree, proto_docsis_dscreq, tvb, 0, -1,
"DSC Request");
dscreq_tree = proto_item_add_subtree (it, ett_docsis_dscreq);
proto_tree_add_item (dscreq_tree, hf_docsis_dscreq_tranid, tvb, 0, 2,
ENC_BIG_ENDIAN);
}
next_tvb = tvb_new_subset_remaining (tvb, 2);
call_dissector (docsis_tlv_handle, next_tvb, pinfo, dscreq_tree);
}
void
proto_register_docsis_dscreq (void)
{
static hf_register_info hf[] = {
{&hf_docsis_dscreq_tranid,
{"Transaction Id", "docsis_dscreq.tranid",
FT_UINT16, BASE_DEC, NULL, 0x0,
NULL, HFILL}
},
};
static gint *ett[] = {
&ett_docsis_dscreq,
};
proto_docsis_dscreq =
proto_register_protocol ("DOCSIS Dynamic Service Change Request",
"DOCSIS DSC-REQ", "docsis_dscreq");
proto_register_field_array (proto_docsis_dscreq, hf, array_length (hf));
proto_register_subtree_array (ett, array_length (ett));
register_dissector ("docsis_dscreq", dissect_dscreq, proto_docsis_dscreq);
}
void
proto_reg_handoff_docsis_dscreq (void)
{
dissector_handle_t docsis_dscreq_handle;
docsis_dscreq_handle = find_dissector ("docsis_dscreq");
docsis_tlv_handle = find_dissector ("docsis_tlv");
dissector_add_uint ("docsis_mgmt", 0x12, docsis_dscreq_handle);
}
