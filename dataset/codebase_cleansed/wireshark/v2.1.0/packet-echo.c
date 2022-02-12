static int dissect_echo(tvbuff_t *tvb, packet_info *pinfo, proto_tree *tree, void* data _U_)
{
int offset = 0;
gboolean request = FALSE;
if (pinfo->destport == ECHO_PORT) {
request = TRUE;
}
col_set_str(pinfo->cinfo, COL_PROTOCOL, "ECHO");
col_set_str(pinfo->cinfo, COL_INFO,
(request) ? "Request" : "Response");
if (tree) {
proto_tree *echo_tree;
proto_item *ti, *hidden_item;
ti = proto_tree_add_item(tree, proto_echo, tvb, offset, -1, ENC_NA);
echo_tree = proto_item_add_subtree(ti, ett_echo);
if (request) {
hidden_item = proto_tree_add_boolean(echo_tree, hf_echo_request, tvb, 0, 0, 1);
} else {
hidden_item = proto_tree_add_boolean(echo_tree, hf_echo_response, tvb, 0, 0, 1);
}
PROTO_ITEM_SET_HIDDEN(hidden_item);
proto_tree_add_item(echo_tree, hf_echo_data, tvb, offset, -1, ENC_NA);
}
return tvb_captured_length(tvb);
}
void proto_register_echo(void)
{
static hf_register_info hf[] = {
{ &hf_echo_data,
{ "Echo data", "echo.data",
FT_BYTES, BASE_NONE, NULL, 0x0,
NULL, HFILL }},
{ &hf_echo_request,
{ "Echo request", "echo.request",
FT_BOOLEAN, BASE_NONE, NULL, 0x0,
"Echo data", HFILL }},
{ &hf_echo_response,
{ "Echo response","echo.response",
FT_BOOLEAN, BASE_NONE, NULL, 0x0,
"Echo data", HFILL }}
};
static gint *ett[] = {
&ett_echo
};
proto_echo = proto_register_protocol("Echo", "ECHO", "echo");
proto_register_field_array(proto_echo, hf, array_length(hf));
proto_register_subtree_array(ett, array_length(ett));
}
void proto_reg_handoff_echo(void)
{
dissector_handle_t echo_handle;
echo_handle = create_dissector_handle(dissect_echo, proto_echo);
dissector_add_uint("udp.port", ECHO_PORT, echo_handle);
dissector_add_uint("tcp.port", ECHO_PORT, echo_handle);
}
