static void
dissect_udpencap(tvbuff_t *tvb, packet_info *pinfo, proto_tree *tree)
{
tvbuff_t *next_tvb;
proto_tree *udpencap_tree = NULL;
proto_item *ti = NULL;
guint32 spi;
col_set_str(pinfo->cinfo, COL_PROTOCOL, "UDPENCAP");
col_clear(pinfo->cinfo, COL_INFO);
if (tree) {
ti = proto_tree_add_item(tree, proto_udpencap, tvb, 0, -1, ENC_NA);
udpencap_tree = proto_item_add_subtree(ti, ett_udpencap);
}
if ((tvb_length(tvb) == 1) && (tvb_get_guint8(tvb, 0) == 0xff)) {
col_set_str(pinfo->cinfo, COL_INFO, "NAT-keepalive");
if (tree)
proto_tree_add_text(udpencap_tree, tvb, 0, 1, "NAT-keepalive packet");
} else {
tvb_memcpy(tvb, (guint8 *)&spi, 0, sizeof(spi));
if (spi == 0) {
col_set_str(pinfo->cinfo, COL_INFO, "ISAKMP");
if (tree) {
proto_tree_add_text(udpencap_tree, tvb, 0, sizeof(spi),
"Non-ESP Marker");
proto_item_set_len(ti, sizeof(spi));
}
next_tvb = tvb_new_subset_remaining(tvb, sizeof(spi));
call_dissector(isakmp_handle, next_tvb, pinfo, tree);
} else {
col_set_str(pinfo->cinfo, COL_INFO, "ESP");
if (tree)
proto_item_set_len(ti, 0);
call_dissector(esp_handle, tvb, pinfo, tree);
}
}
}
void
proto_register_udpencap(void)
{
static gint *ett[] = {
&ett_udpencap,
};
proto_udpencap = proto_register_protocol(
"UDP Encapsulation of IPsec Packets", "UDPENCAP", "udpencap");
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
