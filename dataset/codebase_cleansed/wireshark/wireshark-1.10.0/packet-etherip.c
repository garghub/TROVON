static void
dissect_etherip(tvbuff_t *tvb, packet_info *pinfo, proto_tree *tree)
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
expert_add_info_format(pinfo, ti, PI_PROTOCOL, PI_WARN, "Version must be 3");
}
ti = proto_tree_add_item(etherip_tree, hf_etherip_reserved, tvb,
0, 2, ENC_BIG_ENDIAN);
if ((field & ETHERIP_RESERVE_MASK) != 0) {
expert_add_info_format(pinfo, ti, PI_PROTOCOL, PI_WARN, "Reserved field must be 0");
}
}
next_tvb = tvb_new_subset_remaining(tvb, 2);
call_dissector(eth_withoutfcs_handle, next_tvb, pinfo, tree);
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
proto_etherip = proto_register_protocol("Ethernet over IP",
"ETHERIP", "etherip");
proto_register_field_array(proto_etherip, hf_etherip, array_length(hf_etherip));
proto_register_subtree_array(ett, array_length(ett));
register_dissector("etherip", dissect_etherip, proto_etherip);
}
void
proto_reg_handoff_etherip(void)
{
dissector_handle_t etherip_handle;
eth_withoutfcs_handle = find_dissector("eth_withoutfcs");
etherip_handle = find_dissector("etherip");
dissector_add_uint("ip.proto", IP_PROTO_ETHERIP, etherip_handle);
}
