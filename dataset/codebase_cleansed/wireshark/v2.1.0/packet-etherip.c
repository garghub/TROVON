static int
dissect_etherip(tvbuff_t *tvb, packet_info *pinfo, proto_tree *tree, void* data _U_)
{
tvbuff_t *next_tvb;
proto_tree *etherip_tree;
proto_item *ti;
guint16 field, version;
col_set_str(pinfo->cinfo, COL_PROTOCOL, "ETHERIP");
field = tvb_get_ntohs(tvb, 0);
version = (field & ETHERIP_VERS_MASK) >> 12;
if (tree) {
ti = proto_tree_add_protocol_format(tree, proto_etherip, tvb, 0,
2,
"EtherIP, Version %d",
version
);
etherip_tree = proto_item_add_subtree(ti, ett_etherip);
ti = proto_tree_add_item(etherip_tree, hf_etherip_ver, tvb,
0, 2, ENC_BIG_ENDIAN);
if (version != 3) {
expert_add_info(pinfo, ti, &ei_etherip_ver_3);
}
ti = proto_tree_add_item(etherip_tree, hf_etherip_reserved, tvb,
0, 2, ENC_BIG_ENDIAN);
if ((field & ETHERIP_RESERVE_MASK) != 0) {
expert_add_info(pinfo, ti, &ei_etherip_reserved_0);
}
}
next_tvb = tvb_new_subset_remaining(tvb, 2);
call_dissector(eth_withoutfcs_handle, next_tvb, pinfo, tree);
return tvb_captured_length(tvb);
}
void
proto_register_etherip(void)
{
static hf_register_info hf_etherip[] = {
{ &hf_etherip_ver,
{ "Version", "etherip.ver", FT_UINT16, BASE_DEC, NULL, ETHERIP_VERS_MASK,
NULL, HFILL }},
{ &hf_etherip_reserved,
{ "Reserved", "etherip.reserved", FT_UINT16, BASE_HEX, NULL, ETHERIP_RESERVE_MASK,
"Reserved (must be 0)", HFILL }},
};
static gint *ett[] = {
&ett_etherip,
};
static ei_register_info ei[] = {
{ &ei_etherip_ver_3, { "etherip.ver.not3", PI_PROTOCOL, PI_WARN, "Version must be 3", EXPFILL }},
{ &ei_etherip_reserved_0, { "etherip.reserved.not0", PI_PROTOCOL, PI_WARN, "Reserved field must be 0", EXPFILL }},
};
expert_module_t* expert_etherip;
proto_etherip = proto_register_protocol("Ethernet over IP",
"ETHERIP", "etherip");
proto_register_field_array(proto_etherip, hf_etherip, array_length(hf_etherip));
proto_register_subtree_array(ett, array_length(ett));
expert_etherip = expert_register_protocol(proto_etherip);
expert_register_field_array(expert_etherip, ei, array_length(ei));
register_dissector("etherip", dissect_etherip, proto_etherip);
}
void
proto_reg_handoff_etherip(void)
{
dissector_handle_t etherip_handle;
eth_withoutfcs_handle = find_dissector_add_dependency("eth_withoutfcs", proto_etherip);
etherip_handle = find_dissector("etherip");
dissector_add_uint("ip.proto", IP_PROTO_ETHERIP, etherip_handle);
}
