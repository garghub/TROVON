static void
dissect_imap(tvbuff_t *tvb, packet_info *pinfo, proto_tree *tree)
{
gboolean is_request;
proto_tree *imap_tree, *reqresp_tree;
proto_item *ti, *hidden_item;
gint offset = 0;
const guchar *line;
gint next_offset;
int linelen;
int tokenlen;
const guchar *next_token;
col_set_str(pinfo->cinfo, COL_PROTOCOL, "IMAP");
if (pinfo->match_uint == pinfo->destport)
is_request = TRUE;
else
is_request = FALSE;
if (check_col(pinfo->cinfo, COL_INFO)) {
linelen = tvb_find_line_end(tvb, offset, -1, &next_offset, FALSE);
line = tvb_get_ptr(tvb, offset, linelen);
col_add_fstr(pinfo->cinfo, COL_INFO, "%s: %s",
is_request ? "Request" : "Response",
format_text(line, linelen));
}
if (tree) {
ti = proto_tree_add_item(tree, proto_imap, tvb, offset, -1, ENC_NA);
imap_tree = proto_item_add_subtree(ti, ett_imap);
hidden_item = proto_tree_add_boolean(imap_tree, hf_imap_isrequest, tvb, 0, 0, is_request);
PROTO_ITEM_SET_HIDDEN(hidden_item);
while(tvb_length_remaining(tvb, offset) > 2) {
linelen = tvb_find_line_end(tvb, offset, -1, &next_offset, FALSE);
line = tvb_get_ptr(tvb, offset, linelen);
ti = proto_tree_add_item(imap_tree, hf_imap_line, tvb, offset,
next_offset - offset, ENC_ASCII|ENC_NA);
reqresp_tree = proto_item_add_subtree(ti, ett_imap_reqresp);
tokenlen = get_token_len(line, line + linelen, &next_token);
if (tokenlen != 0) {
proto_tree_add_item(reqresp_tree, (is_request) ? hf_imap_request_tag : hf_imap_response_tag,
tvb, offset, tokenlen, ENC_ASCII|ENC_NA);
offset += (gint) (next_token - line);
linelen -= (int) (next_token - line);
line = next_token;
}
if (linelen != 0) {
proto_tree_add_item(reqresp_tree, (is_request) ? hf_imap_request : hf_imap_response,
tvb, offset, linelen, ENC_ASCII|ENC_NA);
}
offset += linelen+2;
}
}
}
void
proto_register_imap(void)
{
static hf_register_info hf[] = {
{ &hf_imap_isrequest, { "Request", "imap.isrequest", FT_BOOLEAN, BASE_NONE, NULL, 0x0, "TRUE if IMAP request, FALSE otherwise", HFILL }},
{ &hf_imap_line, { "Line", "imap.line", FT_STRINGZ, BASE_NONE, NULL, 0x0, "A line of an IMAP message", HFILL }},
{ &hf_imap_request, { "Request", "imap.request", FT_STRINGZ, BASE_NONE, NULL, 0x0, "Remainder of request line", HFILL }},
{ &hf_imap_request_tag, { "Request Tag", "imap.request_tag", FT_STRINGZ, BASE_NONE, NULL, 0x0, "First token of request line", HFILL }},
{ &hf_imap_response, { "Response", "imap.response", FT_STRINGZ, BASE_NONE, NULL, 0x0, "Remainder of response line", HFILL }},
{ &hf_imap_response_tag, { "Response Tag", "imap.response_tag", FT_STRINGZ, BASE_NONE, NULL, 0x0, "First token of response line", HFILL }}
};
static gint *ett[] = {
&ett_imap,
&ett_imap_reqresp,
};
proto_imap = proto_register_protocol("Internet Message Access Protocol",
"IMAP", "imap");
register_dissector("imap", dissect_imap, proto_imap);
proto_register_field_array(proto_imap, hf, array_length(hf));
proto_register_subtree_array(ett, array_length(ett));
}
void
proto_reg_handoff_imap(void)
{
dissector_handle_t imap_handle;
imap_handle = create_dissector_handle(dissect_imap, proto_imap);
dissector_add_uint("tcp.port", TCP_PORT_IMAP, imap_handle);
ssl_dissector_add(TCP_PORT_SSL_IMAP, "imap", TRUE);
}
