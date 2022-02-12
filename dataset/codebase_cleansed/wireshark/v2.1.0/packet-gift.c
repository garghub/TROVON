static int
dissect_gift(tvbuff_t *tvb, packet_info *pinfo, proto_tree *tree, void* data _U_)
{
proto_item *ti, *hidden_item;
proto_tree *gift_tree, *cmd_tree;
gboolean is_request;
gint offset = 0;
const guchar *line;
gint next_offset;
int linelen;
int tokenlen;
const guchar *next_token;
col_set_str(pinfo->cinfo, COL_PROTOCOL, "giFT");
if (pinfo->match_uint == pinfo->destport)
is_request = TRUE;
else
is_request = FALSE;
linelen = tvb_find_line_end(tvb, offset, -1, &next_offset, FALSE);
line = tvb_get_ptr(tvb, offset, linelen);
col_add_fstr(pinfo->cinfo, COL_INFO, "%s: %s",
is_request ? "Request" : "Response",
format_text(line, linelen));
if (tree) {
ti = proto_tree_add_item(tree, proto_gift, tvb, 0, -1, ENC_NA);
gift_tree = proto_item_add_subtree(ti, ett_gift);
if (is_request) {
hidden_item = proto_tree_add_boolean(gift_tree, hf_gift_request, tvb, 0, 0, TRUE);
} else {
hidden_item = proto_tree_add_boolean(gift_tree, hf_gift_response, tvb, 0, 0, TRUE);
}
PROTO_ITEM_SET_HIDDEN(hidden_item);
ti = proto_tree_add_format_text(gift_tree, tvb, offset, next_offset - offset);
cmd_tree = proto_item_add_subtree(ti, ett_gift_cmd);
tokenlen = get_token_len(line, line + linelen, &next_token);
if (tokenlen != 0) {
if (is_request) {
proto_tree_add_string(cmd_tree, hf_gift_request_cmd, tvb, offset,
tokenlen, format_text(line, tokenlen));
} else {
proto_tree_add_string(cmd_tree, hf_gift_response_cmd, tvb, offset,
tokenlen, format_text(line, tokenlen));
}
offset += (gint) (next_token - line);
linelen -= (int) (next_token - line);
line = next_token;
}
if (linelen != 0) {
if (is_request) {
proto_tree_add_string(cmd_tree, hf_gift_request_arg, tvb, offset,
linelen, format_text(line, linelen));
} else {
proto_tree_add_string(cmd_tree, hf_gift_response_arg, tvb, offset,
linelen, format_text(line, linelen));
}
}
}
return tvb_captured_length(tvb);
}
void
proto_register_gift(void)
{
static hf_register_info hf[] = {
{ &hf_gift_response,
{ "Response", "gift.response", FT_BOOLEAN, BASE_NONE, NULL, 0x0, "TRUE if giFT response", HFILL }
},
{ &hf_gift_request,
{ "Request", "gift.request", FT_BOOLEAN, BASE_NONE, NULL, 0x0, "TRUE if giFT request", HFILL }
},
{ &hf_gift_response_cmd,
{ "Response Command", "gift.response_cmd", FT_STRING, BASE_NONE, NULL, 0x0, NULL, HFILL }
},
{ &hf_gift_response_arg,
{ "Response Arg", "gift.response_arg", FT_STRING, BASE_NONE, NULL, 0x0, NULL, HFILL }
},
{ &hf_gift_request_cmd,
{ "Request Command", "gift.request_cmd", FT_STRING, BASE_NONE, NULL, 0x0, NULL, HFILL }
},
{ &hf_gift_request_arg,
{ "Request Arg", "gift.request_arg", FT_STRING, BASE_NONE, NULL, 0x0, NULL, HFILL }
},
};
static gint *ett[] = {
&ett_gift,
&ett_gift_cmd,
};
proto_gift = proto_register_protocol("giFT Internet File Transfer",
"giFT", "gift");
proto_register_field_array(proto_gift, hf, array_length(hf));
proto_register_subtree_array(ett, array_length(ett));
}
void
proto_reg_handoff_gift(void)
{
dissector_handle_t gift_handle;
gift_handle = create_dissector_handle(dissect_gift, proto_gift);
dissector_add_uint("tcp.port", TCP_PORT_GIFT, gift_handle);
}
