static int
packet_is_tcpencap(tvbuff_t *tvb, packet_info *pinfo, guint32 offset)
{
if (
tvb_get_ntohl(tvb, offset + 0) != 0 ||
(tvb_get_ntohs(tvb, offset + 6) & 0xfff) != 0 ||
(tvb_get_guint8(tvb, offset + 13) != 17 &&
tvb_get_guint8(tvb, offset + 13) != 50)
) {
return FALSE;
}
if(check_if_ndmp(tvb, pinfo)){
return FALSE;
}
return TRUE;
}
static int
dissect_tcpencap(tvbuff_t *tvb, packet_info *pinfo, proto_tree *tree, void *data _U_)
{
proto_tree *tcpencap_tree = NULL;
proto_tree *tcpencap_unknown_tree = NULL;
proto_item *tree_item = NULL;
proto_item *unknown_item = NULL;
tvbuff_t *next_tvb;
guint32 reported_length = tvb_reported_length(tvb);
guint32 offset;
guint8 protocol;
col_set_str(pinfo->cinfo, COL_PROTOCOL, "TCPENCAP");
col_clear(pinfo->cinfo, COL_INFO);
if (tvb_get_ntohl(tvb, 0) == 0x01f401f4) {
protocol = TCP_ENCAP_P_UDP;
} else {
protocol = TCP_ENCAP_P_ESP;
}
if (tree) {
tree_item = proto_tree_add_item(tree, proto_tcpencap, tvb, 0, -1, ENC_NA);
tcpencap_tree = proto_item_add_subtree(tree_item, ett_tcpencap);
offset = reported_length - TRAILERLENGTH;
unknown_item = proto_tree_add_item(tcpencap_tree, hf_tcpencap_unknown, tvb,
offset, TRAILERLENGTH, ENC_NA);
tcpencap_unknown_tree = proto_item_add_subtree(unknown_item, ett_tcpencap_unknown);
proto_tree_add_item(tcpencap_unknown_tree, hf_tcpencap_zero, tvb, offset + 0, 4, ENC_NA);
proto_tree_add_item(tcpencap_unknown_tree, hf_tcpencap_seq, tvb, offset + 4, 2, ENC_BIG_ENDIAN);
if (protocol == TCP_ENCAP_P_UDP) {
proto_tree_add_item(tcpencap_unknown_tree, hf_tcpencap_ike_direction, tvb, offset + 6, 2, ENC_BIG_ENDIAN);
} else {
proto_tree_add_item(tcpencap_unknown_tree, hf_tcpencap_esp_zero, tvb, offset + 6, 2, ENC_BIG_ENDIAN);
}
proto_tree_add_item(tcpencap_unknown_tree, hf_tcpencap_magic, tvb, offset + 8, 5, ENC_NA);
proto_tree_add_item(tcpencap_unknown_tree, hf_tcpencap_proto, tvb, offset + 13, 1, ENC_BIG_ENDIAN);
proto_tree_add_item(tcpencap_unknown_tree, hf_tcpencap_magic2, tvb, offset + 14, 2, ENC_NA);
}
next_tvb = tvb_new_subset(tvb, 0, reported_length - TRAILERLENGTH , -1);
if (protocol == TCP_ENCAP_P_UDP) {
call_dissector(udp_handle, next_tvb, pinfo, tree);
} else {
call_dissector(esp_handle, next_tvb, pinfo, tree);
}
return tvb_captured_length(tvb);
}
static gboolean
dissect_tcpencap_heur(tvbuff_t *tvb, packet_info *pinfo, proto_tree *tree, void *data)
{
guint32 reported_length = tvb_reported_length(tvb);
guint32 captured_length = tvb_captured_length(tvb);
if (reported_length <= TRAILERLENGTH + 8 ||
(reported_length - captured_length) > (TRAILERLENGTH - 13) ||
!packet_is_tcpencap(tvb, pinfo, reported_length - TRAILERLENGTH) ) {
return FALSE;
}
dissect_tcpencap(tvb, pinfo, tree, data);
return TRUE;
}
void
proto_register_tcpencap(void)
{
static hf_register_info hf[] = {
{ &hf_tcpencap_unknown,
{ "Unknown trailer", "tcpencap.unknown", FT_BYTES, BASE_NONE, NULL,
0x0, NULL, HFILL }},
{ &hf_tcpencap_zero,
{ "All zero", "tcpencap.zero", FT_BYTES, BASE_NONE, NULL,
0x0, NULL, HFILL }},
{ &hf_tcpencap_seq,
{ "Sequence number", "tcpencap.seq", FT_UINT16, BASE_HEX, NULL,
0x0, NULL, HFILL }},
{ &hf_tcpencap_esp_zero,
{ "ESP zero", "tcpencap.espzero", FT_UINT16, BASE_HEX, NULL,
0x0, NULL, HFILL }},
{ &hf_tcpencap_ike_direction,
{ "ISAKMP traffic direction", "tcpencap.ikedirection", FT_UINT16, BASE_HEX, VALS(tcpencap_ikedir_vals),
0x0, NULL, HFILL }},
{ &hf_tcpencap_magic,
{ "Magic number", "tcpencap.magic", FT_BYTES, BASE_NONE, NULL,
0x0, NULL, HFILL }},
{ &hf_tcpencap_proto,
{ "Protocol", "tcpencap.proto", FT_UINT8, BASE_HEX, VALS(tcpencap_proto_vals),
0x0, NULL, HFILL }},
{ &hf_tcpencap_magic2,
{ "Magic 2", "tcpencap.magic2", FT_BYTES, BASE_NONE, NULL,
0x0, NULL, HFILL }},
};
static gint *ett[] = {
&ett_tcpencap,
&ett_tcpencap_unknown,
};
module_t *tcpencap_module;
proto_tcpencap = proto_register_protocol(
"TCP Encapsulation of IPsec Packets", "TCPENCAP", "tcpencap");
proto_register_field_array(proto_tcpencap, hf, array_length(hf));
proto_register_subtree_array(ett, array_length(ett));
tcpencap_module = prefs_register_protocol(proto_tcpencap, proto_reg_handoff_tcpencap);
prefs_register_uint_preference(tcpencap_module, "tcp.port", "IPSEC TCP Port",
"Set the port for IPSEC/ISAKMP messages (typically 10000)",
10, &global_tcpencap_tcp_port);
}
void
proto_reg_handoff_tcpencap(void)
{
static dissector_handle_t tcpencap_handle;
static gboolean initialized = FALSE;
static guint tcpencap_tcp_port = 0;
if (!initialized) {
tcpencap_handle = create_dissector_handle(dissect_tcpencap, proto_tcpencap);
esp_handle = find_dissector_add_dependency("esp", proto_tcpencap);
udp_handle = find_dissector_add_dependency("udp", proto_tcpencap);
heur_dissector_add("tcp", dissect_tcpencap_heur, "TCP Encapsulation of IPsec Packets", "ipsec_tcp", proto_tcpencap, HEURISTIC_ENABLE);
initialized = TRUE;
}
if(tcpencap_tcp_port != 0 && tcpencap_tcp_port != global_tcpencap_tcp_port){
dissector_delete_uint("tcp.port", tcpencap_tcp_port, tcpencap_handle);
}
if(global_tcpencap_tcp_port != 0 && tcpencap_tcp_port != global_tcpencap_tcp_port) {
dissector_add_uint("tcp.port", global_tcpencap_tcp_port, tcpencap_handle);
}
}
