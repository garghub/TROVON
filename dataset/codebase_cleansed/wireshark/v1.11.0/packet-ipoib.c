static void
dissect_ipoib(tvbuff_t *tvb, packet_info *pinfo, proto_tree *tree)
{
proto_tree *fh_tree;
proto_item *ti;
tvbuff_t *next_tvb;
guint16 type;
col_set_str(pinfo->cinfo, COL_PROTOCOL, "IPoIB");
col_set_str(pinfo->cinfo, COL_INFO, "IP over Infiniband");
if (tree) {
ti = proto_tree_add_item (tree, proto_ipoib, tvb, 0, 4, ENC_NA);
fh_tree = proto_item_add_subtree(ti, ett_raw);
proto_tree_add_item(fh_tree, hf_type, tvb, 0, 2, ENC_BIG_ENDIAN);
proto_tree_add_item(fh_tree, hf_reserved, tvb, 2, 2, ENC_BIG_ENDIAN);
}
next_tvb = tvb_new_subset_remaining(tvb, 4);
type = tvb_get_ntohs(tvb, 0);
switch (type) {
case ETHERTYPE_IP:
call_dissector(ip_handle, next_tvb, pinfo, tree);
break;
case ETHERTYPE_IPv6:
call_dissector(ipv6_handle, next_tvb, pinfo, tree);
break;
case ETHERTYPE_ARP:
case ETHERTYPE_REVARP:
call_dissector(arp_handle, next_tvb, pinfo, tree);
break;
default:
break;
}
}
void
proto_register_ipoib(void)
{
static hf_register_info hf[] = {
{ &hf_type,
{ "Type", "ipoib.type",
FT_UINT16, BASE_HEX, VALS(etype_vals), 0x0,
NULL, HFILL }},
{ &hf_reserved,
{ "Reserved", "ipoib.reserved",
FT_UINT16, BASE_HEX, NULL, 0x0,
NULL, HFILL }}
};
static gint *ett[] = {
&ett_raw
};
proto_ipoib = proto_register_protocol("IP over Infiniband", "IPoIB", "ipoib");
proto_register_field_array(proto_ipoib, hf, array_length(hf));
proto_register_subtree_array(ett, array_length(ett));
}
void
proto_reg_handoff_ipoib(void)
{
dissector_handle_t ipoib_handle;
arp_handle = find_dissector("arp");
ip_handle = find_dissector("ip");
ipv6_handle = find_dissector("ipv6");
ipoib_handle = create_dissector_handle(dissect_ipoib, proto_ipoib);
dissector_add_uint("wtap_encap", WTAP_ENCAP_IP_OVER_IB, ipoib_handle);
}
