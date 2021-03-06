static void
dissect_acap(tvbuff_t *tvb, packet_info *pinfo, proto_tree *tree)
{
gboolean is_request;
proto_tree *acap_tree, *reqresp_tree;
proto_item *ti, *hidden_item;
gint offset = 0;
const guchar *line;
gint next_offset;
int linelen;
int tokenlen;
const guchar *next_token;
col_set_str(pinfo->cinfo, COL_PROTOCOL, "ACAP");
linelen = tvb_find_line_end(tvb, offset, -1, &next_offset, FALSE);
line = tvb_get_ptr(tvb, offset, linelen);
if (pinfo->match_uint == pinfo->destport)
is_request = TRUE;
else
is_request = FALSE;
col_add_fstr(pinfo->cinfo, COL_INFO, "%s: %s",
is_request ? "Request" : "Response",
format_text(line, linelen));
if (tree) {
ti = proto_tree_add_item(tree, proto_acap, tvb, offset, -1,
ENC_NA);
acap_tree = proto_item_add_subtree(ti, ett_acap);
if (is_request) {
hidden_item = proto_tree_add_boolean(acap_tree,
hf_acap_request, tvb, 0, 0, TRUE);
PROTO_ITEM_SET_HIDDEN(hidden_item);
} else {
hidden_item = proto_tree_add_boolean(acap_tree,
hf_acap_response, tvb, 0, 0, TRUE);
PROTO_ITEM_SET_HIDDEN(hidden_item);
}
ti = proto_tree_add_text(acap_tree, tvb, offset,
next_offset - offset, "%s",
tvb_format_text(tvb, offset, next_offset - offset));
reqresp_tree = proto_item_add_subtree(ti, ett_acap_reqresp);
tokenlen = get_token_len(line, line + linelen, &next_token);
if (tokenlen != 0) {
if (is_request) {
proto_tree_add_text(reqresp_tree, tvb, offset,
tokenlen, "Request Tag: %s",
format_text(line, tokenlen));
} else {
proto_tree_add_text(reqresp_tree, tvb, offset,
tokenlen, "Response Tag: %s",
format_text(line, tokenlen));
}
offset += (int)(next_token - line);
linelen -= (int)(next_token - line);
line = next_token;
}
if (linelen != 0) {
if (is_request) {
proto_tree_add_text(reqresp_tree, tvb, offset,
linelen, "Request: %s",
format_text(line, linelen));
} else {
proto_tree_add_text(reqresp_tree, tvb, offset,
linelen, "Response: %s",
format_text(line, linelen));
}
}
}
}
void
proto_register_acap(void)
{
static hf_register_info hf[] = {
{ &hf_acap_response,
{ "Response", "acap.response",
FT_BOOLEAN, BASE_NONE, NULL, 0x0,
"TRUE if ACAP response", HFILL }},
{ &hf_acap_request,
{ "Request", "acap.request",
FT_BOOLEAN, BASE_NONE, NULL, 0x0,
"TRUE if ACAP request", HFILL }}
};
static gint *ett[] = {
&ett_acap,
&ett_acap_reqresp,
};
proto_acap = proto_register_protocol("Application Configuration Access Protocol",
"ACAP", "acap");
proto_register_field_array(proto_acap, hf, array_length(hf));
proto_register_subtree_array(ett, array_length(ett));
}
void
proto_reg_handoff_acap(void)
{
dissector_handle_t acap_handle;
acap_handle = create_dissector_handle(dissect_acap, proto_acap);
dissector_add_uint("tcp.port", TCP_PORT_ACAP, acap_handle);
}
