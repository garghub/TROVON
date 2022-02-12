static void
dissect_uccreq (tvbuff_t * tvb, packet_info * pinfo, proto_tree * tree)
{
proto_item *it;
proto_tree *uccreq_tree = NULL;
guint8 chid;
tvbuff_t *next_tvb;
chid = tvb_get_guint8 (tvb, 0);
col_add_fstr (pinfo->cinfo, COL_INFO,
"Upstream Channel Change request Channel ID = %u (U%u)",
chid, (chid > 0 ? chid - 1 : chid));
if (tree)
{
it =
proto_tree_add_protocol_format (tree, proto_docsis_uccreq, tvb, 0, -1,
"UCC Request");
uccreq_tree = proto_item_add_subtree (it, ett_docsis_uccreq);
proto_tree_add_item (uccreq_tree, hf_docsis_uccreq_upchid, tvb, 0, 1,
ENC_BIG_ENDIAN);
}
next_tvb = tvb_new_subset_remaining (tvb, 1);
call_dissector (docsis_tlv_handle, next_tvb, pinfo, uccreq_tree);
}
void
proto_register_docsis_uccreq (void)
{
static hf_register_info hf[] = {
{&hf_docsis_uccreq_upchid,
{"Upstream Channel Id", "docsis_uccreq.upchid",
FT_UINT8, BASE_DEC, NULL, 0x0,
NULL, HFILL}
},
};
static gint *ett[] = {
&ett_docsis_uccreq,
};
proto_docsis_uccreq =
proto_register_protocol ("DOCSIS Upstream Channel Change Request",
"DOCSIS UCC-REQ", "docsis_uccreq");
proto_register_field_array (proto_docsis_uccreq, hf, array_length (hf));
proto_register_subtree_array (ett, array_length (ett));
register_dissector ("docsis_uccreq", dissect_uccreq, proto_docsis_uccreq);
}
void
proto_reg_handoff_docsis_uccreq (void)
{
dissector_handle_t docsis_uccreq_handle;
docsis_uccreq_handle = find_dissector ("docsis_uccreq");
docsis_tlv_handle = find_dissector ("docsis_tlv");
dissector_add_uint ("docsis_mgmt", 0x08, docsis_uccreq_handle);
}
