static int
dissect_bpkmreq (tvbuff_t * tvb, packet_info * pinfo, proto_tree * tree, void* data _U_)
{
proto_item *it;
proto_tree *bpkmreq_tree;
guint8 code;
tvbuff_t *attrs_tvb;
code = tvb_get_guint8 (tvb, 0);
col_add_fstr (pinfo->cinfo, COL_INFO, "BPKM Request (%s)",
val_to_str (code, code_field_vals, "%d"));
if (tree)
{
it =
proto_tree_add_protocol_format (tree, proto_docsis_bpkmreq, tvb, 0, -1,
"BPKM Request Message");
bpkmreq_tree = proto_item_add_subtree (it, ett_docsis_bpkmreq);
proto_tree_add_item (bpkmreq_tree, hf_docsis_bpkmreq_code, tvb, 0, 1,
ENC_BIG_ENDIAN);
proto_tree_add_item (bpkmreq_tree, hf_docsis_bpkmreq_ident, tvb, 1, 1,
ENC_BIG_ENDIAN);
proto_tree_add_item (bpkmreq_tree, hf_docsis_bpkmreq_length, tvb, 2, 2,
ENC_BIG_ENDIAN);
}
attrs_tvb = tvb_new_subset_remaining (tvb, 4);
call_dissector (attrs_handle, attrs_tvb, pinfo, tree);
return tvb_captured_length(tvb);
}
void
proto_register_docsis_bpkmreq (void)
{
static hf_register_info hf[] = {
{&hf_docsis_bpkmreq_code,
{"BPKM Code", "docsis_bpkmreq.code",
FT_UINT8, BASE_DEC, VALS (code_field_vals), 0x0,
"BPKM Request Message", HFILL}
},
{&hf_docsis_bpkmreq_ident,
{"BPKM Identifier", "docsis_bpkmreq.ident",
FT_UINT8, BASE_DEC, NULL, 0x0,
NULL, HFILL}
},
{&hf_docsis_bpkmreq_length,
{"BPKM Length", "docsis_bpkmreq.length",
FT_UINT16, BASE_DEC, NULL, 0x0,
NULL, HFILL}
},
};
static gint *ett[] = {
&ett_docsis_bpkmreq,
};
proto_docsis_bpkmreq =
proto_register_protocol ("DOCSIS Baseline Privacy Key Management Request",
"DOCSIS BPKM-REQ", "docsis_bpkmreq");
proto_register_field_array (proto_docsis_bpkmreq, hf, array_length (hf));
proto_register_subtree_array (ett, array_length (ett));
register_dissector ("docsis_bpkmreq", dissect_bpkmreq,
proto_docsis_bpkmreq);
}
void
proto_reg_handoff_docsis_bpkmreq (void)
{
dissector_handle_t docsis_bpkmreq_handle;
docsis_bpkmreq_handle = find_dissector ("docsis_bpkmreq");
attrs_handle = find_dissector ("docsis_bpkmattr");
dissector_add_uint ("docsis_mgmt", 0x0C, docsis_bpkmreq_handle);
}
