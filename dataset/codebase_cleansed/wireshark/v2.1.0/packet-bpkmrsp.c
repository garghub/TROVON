static int
dissect_bpkmrsp (tvbuff_t * tvb, packet_info * pinfo, proto_tree * tree, void* data _U_)
{
proto_item *it;
proto_tree *bpkmrsp_tree;
guint8 code;
tvbuff_t *attrs_tvb;
code = tvb_get_guint8 (tvb, 0);
col_add_fstr (pinfo->cinfo, COL_INFO, "BPKM Response (%s)",
val_to_str (code, code_field_vals, "Unknown code %u"));
if (tree)
{
it =
proto_tree_add_protocol_format (tree, proto_docsis_bpkmrsp, tvb, 0, -1,
"BPKM Response Message");
bpkmrsp_tree = proto_item_add_subtree (it, ett_docsis_bpkmrsp);
proto_tree_add_item (bpkmrsp_tree, hf_docsis_bpkmrsp_code, tvb, 0, 1,
ENC_BIG_ENDIAN);
proto_tree_add_item (bpkmrsp_tree, hf_docsis_bpkmrsp_ident, tvb, 1, 1,
ENC_BIG_ENDIAN);
proto_tree_add_item (bpkmrsp_tree, hf_docsis_bpkmrsp_length, tvb, 2, 2,
ENC_BIG_ENDIAN);
}
attrs_tvb = tvb_new_subset_remaining (tvb, 4);
call_dissector (attrs_handle, attrs_tvb, pinfo, tree);
return tvb_captured_length(tvb);
}
void
proto_register_docsis_bpkmrsp (void)
{
static hf_register_info hf[] = {
{&hf_docsis_bpkmrsp_code,
{"BPKM Code", "docsis_bpkmrsp.code",
FT_UINT8, BASE_DEC, VALS (code_field_vals), 0x0,
"BPKM Response Message", HFILL}
},
{&hf_docsis_bpkmrsp_ident,
{"BPKM Identifier", "docsis_bpkmrsp.ident",
FT_UINT8, BASE_DEC, NULL, 0x0,
NULL, HFILL}
},
{&hf_docsis_bpkmrsp_length,
{"BPKM Length", "docsis_bpkmrsp.length",
FT_UINT16, BASE_DEC, NULL, 0x0,
NULL, HFILL}
},
};
static gint *ett[] = {
&ett_docsis_bpkmrsp,
};
proto_docsis_bpkmrsp =
proto_register_protocol
("DOCSIS Baseline Privacy Key Management Response", "DOCSIS BPKM-RSP",
"docsis_bpkmrsp");
proto_register_field_array (proto_docsis_bpkmrsp, hf, array_length (hf));
proto_register_subtree_array (ett, array_length (ett));
register_dissector ("docsis_bpkmrsp", dissect_bpkmrsp,
proto_docsis_bpkmrsp);
}
void
proto_reg_handoff_docsis_bpkmrsp (void)
{
dissector_handle_t docsis_bpkmrsp_handle;
docsis_bpkmrsp_handle = find_dissector ("docsis_bpkmrsp");
attrs_handle = find_dissector ("docsis_bpkmattr");
dissector_add_uint ("docsis_mgmt", 0x0D, docsis_bpkmrsp_handle);
}
