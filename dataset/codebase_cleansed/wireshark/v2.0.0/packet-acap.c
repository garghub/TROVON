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
ti = proto_tree_add_item(tree, hfi_acap, tvb, offset, -1,
ENC_NA);
acap_tree = proto_item_add_subtree(ti, ett_acap);
if (is_request) {
hidden_item = proto_tree_add_boolean(acap_tree,
&hfi_acap_request, tvb, 0, 0, TRUE);
PROTO_ITEM_SET_HIDDEN(hidden_item);
} else {
hidden_item = proto_tree_add_boolean(acap_tree,
&hfi_acap_response, tvb, 0, 0, TRUE);
PROTO_ITEM_SET_HIDDEN(hidden_item);
}
ti = proto_tree_add_format_text(acap_tree, tvb, offset, next_offset - offset);
reqresp_tree = proto_item_add_subtree(ti, ett_acap_reqresp);
tokenlen = get_token_len(line, line + linelen, &next_token);
if (tokenlen != 0) {
if (is_request) {
proto_tree_add_string(reqresp_tree, &hfi_acap_request_tag, tvb, offset,
tokenlen, format_text(line, tokenlen));
} else {
proto_tree_add_string(reqresp_tree, &hfi_acap_response_tag, tvb, offset,
tokenlen, format_text(line, tokenlen));
}
offset += (int)(next_token - line);
linelen -= (int)(next_token - line);
line = next_token;
}
if (linelen != 0) {
if (is_request) {
proto_tree_add_string(reqresp_tree, &hfi_acap_request_data, tvb, offset,
linelen, format_text(line, linelen));
} else {
proto_tree_add_string(reqresp_tree, &hfi_acap_response_data, tvb, offset,
linelen, format_text(line, linelen));
}
}
}
}
void
proto_register_acap(void)
{
#ifndef HAVE_HFI_SECTION_INIT
static header_field_info *hfi[] = {
&hfi_acap_response,
&hfi_acap_request,
&hfi_acap_request_tag,
&hfi_acap_response_tag,
&hfi_acap_request_data,
&hfi_acap_response_data,
};
#endif
static gint *ett[] = {
&ett_acap,
&ett_acap_reqresp,
};
int proto_acap;
proto_acap = proto_register_protocol("Application Configuration Access Protocol",
"ACAP", "acap");
hfi_acap = proto_registrar_get_nth(proto_acap);
proto_register_fields(proto_acap, hfi, array_length(hfi));
proto_register_subtree_array(ett, array_length(ett));
acap_handle = create_dissector_handle(dissect_acap, proto_acap);
}
void
proto_reg_handoff_acap(void)
{
dissector_add_uint("tcp.port", TCP_PORT_ACAP, acap_handle);
}
