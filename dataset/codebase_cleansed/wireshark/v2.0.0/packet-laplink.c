static gint
dissect_laplink_udp(tvbuff_t *tvb, packet_info *pinfo, proto_tree *tree, void *data _U_)
{
int offset = 0;
proto_item *ti;
proto_tree *laplink_tree;
guint32 udp_ident;
const gchar *udp_ident_string;
if (!tvb_bytes_exist(tvb, offset, 4))
return 0;
udp_ident = tvb_get_ntohl(tvb, offset);
udp_ident_string = try_val_to_str(udp_ident, laplink_udp_magic);
if (udp_ident_string == NULL)
return 0;
col_set_str(pinfo->cinfo, COL_PROTOCOL, "Laplink");
col_add_str(pinfo->cinfo, COL_INFO, udp_ident_string);
if (tree){
ti = proto_tree_add_item(tree, proto_laplink, tvb, 0, -1, ENC_NA);
laplink_tree = proto_item_add_subtree(ti, ett_laplink);
proto_tree_add_uint(laplink_tree, hf_laplink_udp_ident, tvb, offset, 4, udp_ident);
offset += 4;
proto_tree_add_item(laplink_tree, hf_laplink_udp_name, tvb, offset, -1, ENC_ASCII|ENC_NA);
}
return tvb_captured_length(tvb);
}
static int
dissect_laplink_tcp_pdu(tvbuff_t *tvb, packet_info *pinfo, proto_tree *tree, void* data _U_)
{
int offset = 0;
int length = 0;
proto_item *ti;
proto_tree *laplink_tree;
guint32 tcp_ident;
col_set_str(pinfo->cinfo, COL_PROTOCOL, "Laplink");
tcp_ident = tvb_get_ntohl(tvb, offset);
col_add_str(pinfo->cinfo, COL_INFO,
val_to_str(tcp_ident, laplink_tcp_magic, "TCP TBA (%u)"));
if (tree){
ti = proto_tree_add_item(tree, proto_laplink, tvb, 0, -1, ENC_NA);
laplink_tree = proto_item_add_subtree(ti, ett_laplink);
proto_tree_add_item(laplink_tree, hf_laplink_tcp_ident, tvb, offset, 4, ENC_BIG_ENDIAN);
offset += 4;
length = tvb_get_ntohs(tvb, offset);
proto_tree_add_item(laplink_tree, hf_laplink_tcp_length, tvb, offset, 2, ENC_BIG_ENDIAN);
offset += 2;
proto_tree_add_item(laplink_tree, hf_laplink_tcp_data, tvb, offset, length, ENC_NA);
}
return tvb_captured_length(tvb);
}
static guint
get_laplink_pdu_len(packet_info *pinfo _U_, tvbuff_t *tvb, int offset, void *data _U_)
{
guint plen;
plen = (tvb_get_ntohs(tvb, offset+4) + 2 + 4);
return plen;
}
static int
dissect_laplink_tcp(tvbuff_t *tvb, packet_info *pinfo, proto_tree *tree, void* data)
{
tcp_dissect_pdus(tvb, pinfo, tree, laplink_desegment,
6, get_laplink_pdu_len,
dissect_laplink_tcp_pdu, data);
return tvb_captured_length(tvb);
}
void
proto_register_laplink(void)
{
static hf_register_info hf[] = {
{ &hf_laplink_udp_ident,
{ "UDP Ident", "laplink.udp_ident",
FT_UINT32, BASE_HEX, VALS(laplink_udp_magic), 0x0,
"Unknown magic", HFILL }
},
{ &hf_laplink_udp_name,
{ "UDP Name", "laplink.udp_name",
FT_STRINGZ, BASE_NONE, NULL, 0x0,
"Machine name", HFILL }
},
{ &hf_laplink_tcp_ident,
{ "TCP Ident", "laplink.tcp_ident",
FT_UINT32, BASE_HEX, VALS(laplink_tcp_magic), 0x0,
"Unknown magic", HFILL }
},
{ &hf_laplink_tcp_length,
{ "TCP Data payload length", "laplink.tcp_length",
FT_UINT16, BASE_DEC, NULL, 0x0,
"Length of remaining payload", HFILL }
},
{ &hf_laplink_tcp_data,
{ "Unknown TCP data", "laplink.tcp_data",
FT_BYTES, BASE_NONE, NULL, 0x0,
"TCP data", HFILL }
},
};
static gint *ett[] = {
&ett_laplink,
};
module_t *laplink_module;
proto_laplink = proto_register_protocol("Laplink",
"Laplink", "laplink");
proto_register_field_array(proto_laplink, hf, array_length(hf));
proto_register_subtree_array(ett, array_length(ett));
laplink_module = prefs_register_protocol(proto_laplink, NULL);
prefs_register_bool_preference(laplink_module, "desegment_laplink_over_tcp",
"Reassemble Laplink over TCP messages spanning multiple TCP segments",
"Whether the Laplink dissector should reassemble messages spanning multiple TCP segments."
" To use this option, you must also enable \"Allow subdissectors to reassemble TCP streams\" in the TCP protocol settings.",
&laplink_desegment);
}
void
proto_reg_handoff_laplink(void)
{
dissector_handle_t laplink_udp_handle;
dissector_handle_t laplink_tcp_handle;
laplink_tcp_handle = new_create_dissector_handle(dissect_laplink_tcp,
proto_laplink);
dissector_add_uint("tcp.port", TCP_PORT_LAPLINK, laplink_tcp_handle);
laplink_udp_handle = new_create_dissector_handle(dissect_laplink_udp,
proto_laplink);
dissector_add_uint("udp.port", UDP_PORT_LAPLINK, laplink_udp_handle);
}
