static void
dissect_etherip(tvbuff_t *tvb, packet_info *pinfo, proto_tree *tree)
{
struct etheriphdr etheriph;
tvbuff_t *next_tvb;
proto_tree *etherip_tree;
proto_item *ti;
col_set_str(pinfo->cinfo, COL_PROTOCOL, "ETHERIP");
tvb_memcpy(tvb, (guint8 *)&etheriph, 0, sizeof(etheriph));
etheriph.ver &= ETHERIP_VERS_MASK;
if (tree) {
ti = proto_tree_add_protocol_format(tree, proto_etherip, tvb, 0,
sizeof(etheriph),
"EtherIP, Version %d",
etheriph.ver
);
etherip_tree = proto_item_add_subtree(ti, ett_etherip);
proto_tree_add_uint(etherip_tree, hf_etherip_ver, tvb,
offsetof(struct etheriphdr, ver), sizeof(etheriph.ver),
etheriph.ver);
}
next_tvb = tvb_new_subset_remaining(tvb, sizeof(etheriph));
call_dissector(eth_withoutfcs_handle, next_tvb, pinfo, tree);
}
void
proto_register_etherip(void)
{
static hf_register_info hf_etherip[] = {
{ &hf_etherip_ver,
{ "Version", "etherip.ver", FT_UINT8, BASE_HEX, NULL, 0x0,
NULL, HFILL }},
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
