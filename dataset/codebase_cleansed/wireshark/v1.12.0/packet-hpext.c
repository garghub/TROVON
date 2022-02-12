static void
dissect_hpext(tvbuff_t *tvb, packet_info *pinfo, proto_tree *tree)
{
proto_tree *hpext_tree = NULL;
proto_item *ti = NULL;
guint16 dxsap, sxsap;
tvbuff_t *next_tvb;
col_set_str(pinfo->cinfo, COL_PROTOCOL, "HPEXT");
dxsap = tvb_get_ntohs(tvb, 3);
sxsap = tvb_get_ntohs(tvb, 5);
if (tree) {
ti = proto_tree_add_item(tree, hfi_hpext, tvb, 0, 7, ENC_NA);
hpext_tree = proto_item_add_subtree(ti, ett_hpext);
proto_tree_add_text(hpext_tree, tvb, 0, 3, "Reserved");
proto_tree_add_uint(hpext_tree, &hfi_hpext_dxsap, tvb, 3,
2, dxsap);
proto_tree_add_uint(hpext_tree, &hfi_hpext_sxsap, tvb, 5,
2, sxsap);
}
col_append_fstr(pinfo->cinfo, COL_INFO,
"; HPEXT; DXSAP %s, SXSAP %s",
val_to_str(dxsap, xsap_vals, "%04x"),
val_to_str(sxsap, xsap_vals, "%04x"));
if (tvb_length_remaining(tvb, 7) > 0) {
next_tvb = tvb_new_subset_remaining(tvb, 7);
if (!dissector_try_uint(subdissector_table,
dxsap, next_tvb, pinfo, tree)) {
call_dissector(data_handle, next_tvb, pinfo, tree);
}
}
}
void
proto_register_hpext(void)
{
#ifndef HAVE_HFI_SECTION_INIT
static header_field_info *hfi[] = {
&hfi_hpext_dxsap,
&hfi_hpext_sxsap,
};
#endif
static gint *ett[] = {
&ett_hpext
};
int proto_hpext;
proto_hpext = proto_register_protocol(
"HP Extended Local-Link Control", "HPEXT", "hpext");
hfi_hpext = proto_registrar_get_nth(proto_hpext);
proto_register_fields(proto_hpext, hfi, array_length(hfi));
proto_register_subtree_array(ett, array_length(ett));
subdissector_table = register_dissector_table("hpext.dxsap",
"HPEXT XSAP", FT_UINT16, BASE_HEX);
hpext_handle = register_dissector("hpext", dissect_hpext, proto_hpext);
}
void
proto_reg_handoff_hpext(void)
{
data_handle = find_dissector("data");
dissector_add_uint("llc.dsap", SAP_HPEXT, hpext_handle);
}
