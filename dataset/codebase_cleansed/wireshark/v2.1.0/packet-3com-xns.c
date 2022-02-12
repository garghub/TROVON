static int
dissect_3com_xns(tvbuff_t *tvb, packet_info *pinfo, proto_tree *tree, void* data _U_)
{
proto_tree *subtree;
proto_tree *ti;
guint16 type;
tvbuff_t *next_tvb;
col_set_str(pinfo->cinfo, COL_PROTOCOL, "3Com XNS");
col_clear(pinfo->cinfo, COL_INFO);
ti = proto_tree_add_item(tree, proto_3com_xns, tvb, 0, 4, ENC_NA);
subtree = proto_item_add_subtree(ti, ett_3com_xns);
type = tvb_get_ntohs(tvb, 0);
next_tvb = tvb_new_subset_remaining(tvb, 2);
if (type == 0x0004) {
proto_tree_add_uint(subtree, hf_3com_xns_type_retix_bpdu,
tvb, 0, 2, type);
call_dissector(retix_bpdu_handle, next_tvb, pinfo, tree);
} else {
proto_tree_add_uint(subtree, hf_3com_xns_type_ethertype,
tvb, 0, 2, type);
if (!dissector_try_uint(ethertype_subdissector_table,
type, next_tvb, pinfo, tree))
call_data_dissector(next_tvb, pinfo, tree);
}
return tvb_captured_length(tvb);
}
void
proto_register_3com_xns(void)
{
static hf_register_info hf[] = {
{ &hf_3com_xns_type_ethertype,
{ "Type", "3comxns.type", FT_UINT16, BASE_HEX,
VALS(etype_vals), 0x0, NULL, HFILL }},
{ &hf_3com_xns_type_retix_bpdu,
{ "Type", "3comxns.type", FT_UINT16, BASE_HEX,
VALS(retix_bpdu_type_vals), 0x0, NULL, HFILL }},
};
static gint *ett[] ={
&ett_3com_xns,
};
proto_3com_xns = proto_register_protocol("3Com XNS Encapsulation", "3COMXNS", "3comxns");
proto_register_field_array(proto_3com_xns, hf, array_length(hf));
proto_register_subtree_array(ett, array_length(ett));
}
void
proto_reg_handoff_3com_xns(void)
{
dissector_handle_t our_xns_handle;
retix_bpdu_handle = find_dissector_add_dependency("rbpdu", proto_3com_xns);
ethertype_subdissector_table = find_dissector_table("ethertype");
our_xns_handle = create_dissector_handle(dissect_3com_xns, proto_3com_xns);
dissector_add_uint("llc.dsap", 0x80, our_xns_handle);
}
