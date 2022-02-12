static int
dissect_symantec(tvbuff_t *tvb, packet_info *pinfo, proto_tree *tree, void* data _U_)
{
proto_item *ti;
proto_tree *symantec_tree;
guint16 etypev2, etypev3;
tvbuff_t *next_tvb;
etypev2 = tvb_get_ntohs(tvb, 6);
etypev3 = tvb_get_ntohs(tvb, 10);
if ((etypev2 == 0) == (etypev3 == 0))
return 12;
col_set_str(pinfo->cinfo, COL_PROTOCOL, "Symantec");
if (etypev3 == 0) {
col_set_str(pinfo->cinfo, COL_INFO, "Symantec Enterprise Firewall");
ti = proto_tree_add_protocol_format(tree, proto_symantec, tvb,
0, 44, "Symantec firewall");
symantec_tree = proto_item_add_subtree(ti, ett_symantec);
proto_tree_add_item(symantec_tree, hf_symantec_if, tvb,
0, 4, ENC_BIG_ENDIAN);
proto_tree_add_uint(symantec_tree, hf_symantec_etype, tvb,
6, 2, etypev2);
next_tvb = tvb_new_subset_remaining(tvb, 44);
dissector_try_uint(ethertype_dissector_table, etypev2, next_tvb, pinfo,
tree);
}
if (etypev2 == 0) {
col_set_str(pinfo->cinfo, COL_INFO, "Symantec SGS v3");
ti = proto_tree_add_protocol_format(tree, proto_symantec, tvb,
0, 56, "Symantec SGSv3");
symantec_tree = proto_item_add_subtree(ti, ett_symantec);
proto_tree_add_item(symantec_tree, hf_symantec_if, tvb,
0, 4, ENC_BIG_ENDIAN);
proto_tree_add_uint(symantec_tree, hf_symantec_etype, tvb,
10, 2, etypev3);
next_tvb = tvb_new_subset_remaining(tvb, 56);
dissector_try_uint(ethertype_dissector_table, etypev3, next_tvb, pinfo,
tree);
}
return tvb_captured_length(tvb);
}
void
proto_register_symantec(void)
{
static hf_register_info hf[] = {
{ &hf_symantec_if,
{ "Interface", "symantec.if", FT_IPv4, BASE_NONE, NULL, 0x0,
NULL, HFILL }},
{ &hf_symantec_etype,
{ "Type", "symantec.type", FT_UINT16, BASE_HEX, VALS(etype_vals), 0x0,
NULL, HFILL }},
};
static gint *ett[] = {
&ett_symantec,
};
proto_symantec = proto_register_protocol("Symantec Enterprise Firewall",
"Symantec", "symantec");
proto_register_field_array(proto_symantec, hf, array_length(hf));
proto_register_subtree_array(ett, array_length(ett));
}
void
proto_reg_handoff_symantec(void)
{
dissector_handle_t symantec_handle;
ethertype_dissector_table = find_dissector_table("ethertype");
symantec_handle = create_dissector_handle(dissect_symantec,
proto_symantec);
dissector_add_uint("wtap_encap", WTAP_ENCAP_SYMANTEC, symantec_handle);
}
