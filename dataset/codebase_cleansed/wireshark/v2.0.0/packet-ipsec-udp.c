static void
dissect_udpencap(tvbuff_t *tvb, packet_info *pinfo, proto_tree *tree)
{
tvbuff_t *next_tvb;
proto_tree *udpencap_tree;
proto_item *ti;
guint32 spi;
col_set_str(pinfo->cinfo, COL_PROTOCOL, "UDPENCAP");
col_clear(pinfo->cinfo, COL_INFO);
ti = proto_tree_add_item(tree, proto_udpencap, tvb, 0, -1, ENC_NA);
udpencap_tree = proto_item_add_subtree(ti, ett_udpencap);
if ((tvb_captured_length(tvb) == 1) && (tvb_get_guint8(tvb, 0) == 0xff)) {
col_set_str(pinfo->cinfo, COL_INFO, "NAT-keepalive");
proto_tree_add_item(udpencap_tree, hf_nat_keepalive, tvb, 0, 1, ENC_NA);
} else {
spi = tvb_get_ntohl(tvb, 0);
if (spi == 0) {
col_set_str(pinfo->cinfo, COL_INFO, "ISAKMP");
proto_tree_add_item(udpencap_tree, hf_non_esp_marker, tvb, 0, 4, ENC_NA);
proto_item_set_len(ti, 4);
next_tvb = tvb_new_subset_remaining(tvb, 4);
call_dissector(isakmp_handle, next_tvb, pinfo, tree);
} else {
col_set_str(pinfo->cinfo, COL_INFO, "ESP");
proto_item_set_len(ti, 0);
call_dissector(esp_handle, tvb, pinfo, tree);
}
}
}
void
proto_register_udpencap(void)
{
static hf_register_info hf[] = {
{ &hf_nat_keepalive, { "NAT-keepalive packet", "udpencap.nat_keepalive",
FT_NONE, BASE_NONE, NULL, 0, NULL, HFILL }},
{ &hf_non_esp_marker, { "Non-ESP Marker", "udpencap.non_esp_marker",
FT_NONE, BASE_NONE, NULL, 0, NULL, HFILL }},
};
static gint *ett[] = {
&ett_udpencap,
};
proto_udpencap = proto_register_protocol(
"UDP Encapsulation of IPsec Packets", "UDPENCAP", "udpencap");
proto_register_field_array(proto_udpencap, hf, array_length(hf));
proto_register_subtree_array(ett, array_length(ett));
}
void
proto_reg_handoff_udpencap(void)
{
dissector_handle_t udpencap_handle;
esp_handle = find_dissector("esp");
isakmp_handle = find_dissector("isakmp");
udpencap_handle = create_dissector_handle(dissect_udpencap, proto_udpencap);
dissector_add_uint("udp.port", 4500, udpencap_handle);
}
