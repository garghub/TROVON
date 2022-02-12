static int
dissect_xyplex(tvbuff_t *tvb, packet_info *pinfo, proto_tree *tree, void *data _U_)
{
proto_tree *xyplex_tree;
proto_item *ti;
conversation_t *conversation;
gint offset = 0;
guint8 prototype;
guint8 padding;
guint16 server_port;
guint16 return_port;
guint16 reserved;
guint16 reply;
col_set_str(pinfo->cinfo, COL_PROTOCOL, "XYPLEX");
ti = proto_tree_add_item(tree, proto_xyplex, tvb, offset, -1, ENC_NA);
xyplex_tree = proto_item_add_subtree(ti, ett_xyplex);
if (pinfo->destport == UDP_PORT_XYPLEX) {
prototype = tvb_get_guint8(tvb, offset);
padding = tvb_get_guint8(tvb, offset+1);
server_port = tvb_get_ntohs(tvb, offset+2);
return_port = tvb_get_ntohs(tvb, offset+4);
reserved = tvb_get_ntohs(tvb, offset+6);
col_add_fstr(pinfo->cinfo, COL_INFO,
"Registration Request: %d Return: %d",
server_port, return_port);
if (tree) {
proto_tree_add_uint(xyplex_tree, hf_xyplex_type, tvb,
offset, 1, prototype);
proto_tree_add_uint(xyplex_tree, hf_xyplex_pad, tvb,
offset+1, 1, padding);
proto_tree_add_uint(xyplex_tree, hf_xyplex_server_port, tvb,
offset+2, 2, server_port);
proto_tree_add_uint(xyplex_tree, hf_xyplex_return_port, tvb,
offset+4, 2, return_port);
proto_tree_add_uint(xyplex_tree, hf_xyplex_reserved, tvb,
offset+6, 2, reserved);
}
offset += 8;
conversation = find_conversation(pinfo->num, &pinfo->src, &pinfo->dst,
PT_TCP, return_port, 0, NO_PORT_B);
if (conversation == NULL) {
conversation = conversation_new(pinfo->num, &pinfo->src, &pinfo->dst,
PT_TCP, return_port, 0, NO_PORT2);
conversation_set_dissector(conversation, xyplex_handle);
}
return offset;
}
if (pinfo->srcport == UDP_PORT_XYPLEX) {
prototype = tvb_get_guint8(tvb, offset);
padding = tvb_get_guint8(tvb, offset+1);
reply = tvb_get_ntohs(tvb, offset+2);
col_add_fstr(pinfo->cinfo, COL_INFO, "Registration Reply: %s",
val_to_str(reply, xyplex_reg_vals, "Unknown (0x%02x)"));
if (tree) {
proto_tree_add_uint(xyplex_tree, hf_xyplex_type, tvb,
offset, 1, prototype);
proto_tree_add_uint(xyplex_tree, hf_xyplex_pad, tvb,
offset+1, 1, padding);
proto_tree_add_uint(xyplex_tree, hf_xyplex_reply, tvb,
offset+2, 2, reply);
}
offset += 4;
return offset;
}
col_add_fstr(pinfo->cinfo, COL_INFO, "%d > %d Data",
pinfo->srcport, pinfo->destport);
proto_tree_add_item(xyplex_tree, hf_xyplex_data, tvb, offset, -1, ENC_NA);
return tvb_reported_length_remaining(tvb, offset);
}
void
proto_register_xyplex(void)
{
static hf_register_info hf[] = {
{ &hf_xyplex_type,
{ "Type", "xyplex.type",
FT_UINT8, BASE_DEC, NULL, 0x0,
"Protocol type", HFILL }},
{ &hf_xyplex_pad,
{ "Pad", "xyplex.pad",
FT_UINT8, BASE_DEC, NULL, 0x0,
"Padding", HFILL }},
{ &hf_xyplex_server_port,
{ "Server Port", "xyplex.server_port",
FT_UINT16, BASE_DEC, NULL, 0x0,
NULL, HFILL }},
{ &hf_xyplex_return_port,
{ "Return Port", "xyplex.return_port",
FT_UINT16, BASE_DEC, NULL, 0x0,
NULL, HFILL }},
{ &hf_xyplex_reserved,
{ "Reserved field", "xyplex.reserved",
FT_UINT16, BASE_DEC, NULL, 0x0,
NULL, HFILL }},
{ &hf_xyplex_reply,
{ "Registration Reply", "xyplex.reply",
FT_UINT16, BASE_DEC, VALS(xyplex_reg_vals), 0x0,
NULL, HFILL }},
{ &hf_xyplex_data,
{ "Data", "xyplex.data",
FT_BYTES, BASE_NONE, NULL, 0x0,
NULL, HFILL }},
};
static gint *ett[] = {
&ett_xyplex,
};
proto_xyplex = proto_register_protocol("Xyplex", "XYPLEX", "xyplex");
proto_register_field_array(proto_xyplex, hf, array_length(hf));
proto_register_subtree_array(ett, array_length(ett));
}
void
proto_reg_handoff_xyplex(void)
{
xyplex_handle = create_dissector_handle(dissect_xyplex, proto_xyplex);
dissector_add_uint("udp.port", UDP_PORT_XYPLEX, xyplex_handle);
}
