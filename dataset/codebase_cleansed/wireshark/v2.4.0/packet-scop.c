static int
dissect_scop(tvbuff_t *tvb, packet_info *pinfo, proto_tree *tree, void* data _U_)
{
tvbuff_t *next_tvb;
proto_item *proto_root;
proto_tree *scop_tree;
guint offset = 0;
scop_packet packet;
memset(&packet, 0, sizeof(packet));
col_set_str(pinfo->cinfo, COL_PROTOCOL, "SCoP");
col_clear(pinfo->cinfo, COL_INFO);
proto_root = proto_tree_add_protocol_format(tree, proto_scop, tvb, 0, tvb_captured_length(tvb),
"ZigBee SCoP");
scop_tree = proto_item_add_subtree(proto_root, ett_scop);
packet.transport = tvb_get_guint8(tvb, offset);
proto_tree_add_uint(scop_tree, hf_scop_transport, tvb, offset, 1, packet.transport);
offset += 1;
packet.version = tvb_get_guint8(tvb, offset);
proto_tree_add_uint(scop_tree, hf_scop_version, tvb, offset, 1, packet.version);
offset += 1;
packet.length = tvb_get_ntohs(tvb, offset);
proto_tree_add_uint(scop_tree, hf_scop_length, tvb, offset, 2, packet.length);
offset += 2;
if ( (packet.transport == SCOP_TRANSPORT_UDP_CCM)
|| (packet.transport == SCOP_TRANSPORT_TCP_CCM)) {
return offset;
}
next_tvb = tvb;
packet.service = tvb_get_guint8(next_tvb, offset);
proto_tree_add_uint(scop_tree, hf_scop_service, next_tvb, offset, 1, packet.service);
offset += 1;
switch (packet.service) {
case SCOP_SERVICE_SCOP:
dissect_scop_zip(tvb_new_subset_remaining(next_tvb, offset), pinfo, scop_tree);
break;
case SCOP_SERVICE_BRIDGE:
dissect_scop_bridge(tvb_new_subset_remaining(next_tvb, offset), pinfo, scop_tree);
break;
case SCOP_SERVICE_GATEWAY:
default:
call_data_dissector(tvb_new_subset_remaining(next_tvb, offset), pinfo, tree);
break;
}
return tvb_captured_length(tvb);
}
static guint
get_scop_length(packet_info *pinfo _U_, tvbuff_t *tvb, int offset, void *data _U_)
{
return tvb_get_ntohs(tvb, offset + SCOP_LENGTH_OFFSET);
}
static int
dissect_scop_tcp(tvbuff_t *tvb, packet_info *pinfo, proto_tree *tree, void* data)
{
tcp_dissect_pdus(tvb, pinfo, tree, TRUE, SCOP_HEADER_LENGTH, get_scop_length, dissect_scop, data);
return tvb_captured_length(tvb);
}
static void
dissect_scop_zip(tvbuff_t *tvb, packet_info *pinfo, proto_tree *tree)
{
guint offset = 0;
guint8 type = tvb_get_guint8(tvb, offset);
guint16 status;
proto_tree_add_uint(tree, hf_scop_type, tvb, offset, 1, type);
proto_item_append_text(tree, ", %s", val_to_str_const(type, scop_types, "Reserved Type"));
col_set_str(pinfo->cinfo, COL_INFO, val_to_str_const(type, scop_types, "Reserved Type"));
offset += 2;
if (type == SCOP_CMD_HELLO_RESP) {
status = tvb_get_ntohs(tvb, 1);
proto_tree_add_uint_format_value(tree, hf_scop_status, tvb, offset, 2, status, "%s", (status==0x0000)?"Success":"Failure");
offset += 2;
}
if (offset < tvb_reported_length(tvb)) {
tvbuff_t *payload_tvb = tvb_new_subset_remaining(tvb, offset);
proto_tree *root = proto_tree_get_root(tree);
call_data_dissector(payload_tvb, pinfo, root);
}
}
static void
dissect_scop_bridge(tvbuff_t *tvb, packet_info *pinfo, proto_tree *tree)
{
call_dissector(ieee802154_handle, tvb, pinfo, proto_tree_get_root(tree));
}
void proto_register_scop(void)
{
static hf_register_info hf[] = {
{ &hf_scop_transport,
{ "Transport Type", "scop.transport", FT_UINT8, BASE_DEC, VALS(scop_transports), 0x0,
"The type of transport used.", HFILL }},
{ &hf_scop_version,
{ "Version", "scop.version", FT_UINT8, BASE_DEC, NULL, 0x0,
"The version of the sniffer.", HFILL }},
{ &hf_scop_length,
{ "Length", "scop.length", FT_UINT16, BASE_DEC, NULL, 0x0,
NULL, HFILL }},
{ &hf_scop_service,
{ "Service Identifier", "scop.service", FT_UINT8, BASE_DEC, VALS(scop_services), 0x0,
NULL, HFILL }},
{ &hf_scop_type,
{ "Packet Type", "scop.type", FT_UINT8, BASE_DEC, VALS(scop_types), 0x0,
"Service-specific packet type.", HFILL }},
{ &hf_scop_status,
{ "Status", "scop.status", FT_UINT16, BASE_HEX, NULL, 0x0,
"Status of the SCoP Command.", HFILL }}
};
static gint *ett[] = {
&ett_scop
};
proto_scop = proto_register_protocol("ZigBee SCoP", "SCoP", "scop");
proto_register_field_array(proto_scop, hf, array_length(hf));
proto_register_subtree_array(ett, array_length(ett));
scop_udp_handle = register_dissector("scop.udp", dissect_scop, proto_scop);
scop_tcp_handle = register_dissector("scop.tcp", dissect_scop_tcp, proto_scop);
}
void proto_reg_handoff_scop(void)
{
ieee802154_handle = find_dissector_add_dependency("wpan_nofcs", proto_scop);
dissector_add_uint_range_with_preference("udp.port", SCOP_DEFAULT_PORT_RANGE, scop_udp_handle);
dissector_add_uint_range_with_preference("tcp.port", SCOP_DEFAULT_PORT_RANGE, scop_tcp_handle);
}
