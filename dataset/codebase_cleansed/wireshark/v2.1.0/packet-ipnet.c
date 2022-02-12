static int
dissect_ipnet(tvbuff_t *tvb, packet_info *pinfo, proto_tree *tree, void* data _U_)
{
proto_tree *fh_tree;
proto_item *ti;
tvbuff_t *next_tvb;
guint32 pktlen;
guint8 family;
col_set_str(pinfo->cinfo, COL_PROTOCOL, "IPNET");
col_set_str(pinfo->cinfo, COL_INFO, "Solaris IPNET");
if(tree) {
ti = proto_tree_add_item (tree, proto_ipnet, tvb, 0, 24, ENC_NA);
fh_tree = proto_item_add_subtree(ti, ett_raw);
proto_tree_add_item(fh_tree, hf_version, tvb, 0, 1, ENC_BIG_ENDIAN);
proto_tree_add_item(fh_tree, hf_family, tvb, 1, 1, ENC_BIG_ENDIAN);
proto_tree_add_item(fh_tree, hf_htype, tvb, 2, 2, ENC_BIG_ENDIAN);
proto_tree_add_item(fh_tree, hf_pktlen, tvb, 4, 4, ENC_BIG_ENDIAN);
proto_tree_add_item(fh_tree, hf_ifindex, tvb, 8, 4, ENC_BIG_ENDIAN);
proto_tree_add_item(fh_tree, hf_grifindex, tvb, 12, 4, ENC_BIG_ENDIAN);
proto_tree_add_item(fh_tree, hf_zsrc, tvb, 16, 4, ENC_BIG_ENDIAN);
proto_tree_add_item(fh_tree, hf_zdst, tvb, 20, 4, ENC_BIG_ENDIAN);
}
pktlen = tvb_get_ntohl(tvb, 4);
next_tvb = tvb_new_subset_remaining(tvb, tvb_captured_length(tvb) - pktlen);
family = tvb_get_guint8(tvb, 1);
switch (family) {
case SOLARIS_AF_INET:
call_dissector(ip_handle, next_tvb, pinfo, tree);
break;
case SOLARIS_AF_INET6:
call_dissector(ipv6_handle, next_tvb, pinfo, tree);
break;
default:
break;
}
return tvb_captured_length(tvb);
}
void
proto_register_ipnet(void)
{
static hf_register_info hf[] = {
{ &hf_version, { "Header version", "ipnet.version",
FT_UINT8, BASE_DEC, NULL, 0x0, NULL, HFILL }},
{ &hf_family, { "Address family", "ipnet.family",
FT_UINT8, BASE_DEC, VALS(solaris_family_vals), 0x0, NULL, HFILL }},
{ &hf_htype, { "Hook type", "ipnet.htype",
FT_UINT16, BASE_DEC, VALS(htype_vals), 0x0, NULL, HFILL }},
{ &hf_pktlen, { "Data length", "ipnet.pktlen",
FT_UINT32, BASE_DEC, NULL, 0x0, NULL, HFILL }},
{ &hf_ifindex, { "Interface index", "ipnet.ifindex",
FT_UINT32, BASE_DEC, NULL, 0x0, NULL, HFILL }},
{ &hf_grifindex, { "Group interface index", "ipnet.grifindex",
FT_UINT32, BASE_DEC, NULL, 0x0, NULL, HFILL }},
{ &hf_zsrc, { "Source Zone ID", "ipnet.zsrc",
FT_UINT32, BASE_DEC, NULL, 0x0, NULL, HFILL }},
{ &hf_zdst, { "Destination Zone ID", "ipnet.zdst",
FT_UINT32, BASE_DEC, NULL, 0x0, NULL, HFILL }},
};
static gint *ett[] = {
&ett_raw,
};
proto_ipnet = proto_register_protocol("Solaris IPNET", "IPNET", "ipnet");
proto_register_field_array(proto_ipnet, hf, array_length(hf));
proto_register_subtree_array(ett, array_length(ett));
}
void
proto_reg_handoff_ipnet(void)
{
dissector_handle_t ipnet_handle;
ip_handle = find_dissector_add_dependency("ip", proto_ipnet);
ipv6_handle = find_dissector_add_dependency("ipv6", proto_ipnet);
ipnet_handle = create_dissector_handle(dissect_ipnet, proto_ipnet);
dissector_add_uint("wtap_encap", WTAP_ENCAP_IPNET, ipnet_handle);
}
