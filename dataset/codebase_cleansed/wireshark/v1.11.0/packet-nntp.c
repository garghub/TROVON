static void
dissect_nntp(tvbuff_t *tvb, packet_info *pinfo, proto_tree *tree)
{
const gchar *type;
proto_tree *nntp_tree;
proto_item *ti;
gint offset = 0;
gint next_offset;
int linelen;
if (pinfo->match_uint == pinfo->destport)
type = "Request";
else
type = "Response";
col_set_str(pinfo->cinfo, COL_PROTOCOL, "NNTP");
linelen = tvb_find_line_end(tvb, offset, -1, &next_offset, FALSE);
col_add_fstr(pinfo->cinfo, COL_INFO, "%s: %s", type,
tvb_format_text(tvb, offset, linelen));
if (tree) {
ti = proto_tree_add_item(tree, proto_nntp, tvb, offset, -1,
ENC_NA);
nntp_tree = proto_item_add_subtree(ti, ett_nntp);
if (pinfo->match_uint == pinfo->destport) {
ti = proto_tree_add_boolean(nntp_tree,
hf_nntp_request, tvb, 0, 0, TRUE);
} else {
ti = proto_tree_add_boolean(nntp_tree,
hf_nntp_response, tvb, 0, 0, TRUE);
}
PROTO_ITEM_SET_HIDDEN(ti);
while (tvb_offset_exists(tvb, offset)) {
tvb_find_line_end(tvb, offset, -1, &next_offset,
FALSE);
proto_tree_add_text(nntp_tree, tvb, offset,
next_offset - offset, "%s",
tvb_format_text(tvb, offset, next_offset - offset));
offset = next_offset;
}
}
}
void
proto_register_nntp(void)
{
static hf_register_info hf[] = {
{ &hf_nntp_response,
{ "Response", "nntp.response",
FT_BOOLEAN, BASE_NONE, NULL, 0x0,
"TRUE if NNTP response", HFILL }},
{ &hf_nntp_request,
{ "Request", "nntp.request",
FT_BOOLEAN, BASE_NONE, NULL, 0x0,
"TRUE if NNTP request", HFILL }}
};
static gint *ett[] = {
&ett_nntp,
};
proto_nntp = proto_register_protocol("Network News Transfer Protocol",
"NNTP", "nntp");
proto_register_field_array(proto_nntp, hf, array_length(hf));
proto_register_subtree_array(ett, array_length(ett));
}
void
proto_reg_handoff_nntp(void)
{
dissector_handle_t nntp_handle;
nntp_handle = create_dissector_handle(dissect_nntp, proto_nntp);
dissector_add_uint("tcp.port", TCP_PORT_NNTP, nntp_handle);
}
