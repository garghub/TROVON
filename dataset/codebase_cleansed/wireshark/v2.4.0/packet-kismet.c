static int
dissect_kismet(tvbuff_t * tvb, packet_info * pinfo, proto_tree * tree, void * data _U_)
{
gboolean is_request;
gboolean is_continuation;
proto_tree *kismet_tree=NULL, *reqresp_tree=NULL;
proto_item *ti;
proto_item *tmp_item;
gint offset = 0;
const guchar *line;
gint next_offset;
int linelen;
int tokenlen;
int i;
const guchar *next_token;
linelen = tvb_find_line_end(tvb, offset, -1, &next_offset, FALSE);
line = tvb_get_ptr(tvb, offset, linelen);
if (linelen < 8) {
return 0;
} else {
for (i = 0; i < 8; ++i) {
if (line[i] < 32 || line[i] > 128)
return 0;
}
}
col_set_str(pinfo->cinfo, COL_PROTOCOL, "kismet");
if (pinfo->match_uint == pinfo->destport) {
is_request = TRUE;
is_continuation = FALSE;
} else {
is_request = FALSE;
is_continuation = response_is_continuation (line);
}
if (is_continuation)
col_set_str(pinfo->cinfo, COL_INFO, "Continuation");
else
col_add_fstr(pinfo->cinfo, COL_INFO, "%s: %s",
is_request ? "Request" : "Response",
format_text(wmem_packet_scope(), line, linelen));
if (tree) {
ti = proto_tree_add_item(tree, proto_kismet, tvb, offset, -1, ENC_NA);
kismet_tree = proto_item_add_subtree(ti, ett_kismet);
}
if (is_continuation) {
call_data_dissector(tvb, pinfo, kismet_tree);
return tvb_captured_length(tvb);
}
if (is_request) {
tmp_item = proto_tree_add_boolean(kismet_tree,
hf_kismet_request, tvb, 0, 0, TRUE);
} else {
tmp_item = proto_tree_add_boolean(kismet_tree,
hf_kismet_response, tvb, 0, 0, TRUE);
}
PROTO_ITEM_SET_GENERATED (tmp_item);
while (tvb_offset_exists(tvb, offset)) {
linelen = tvb_find_line_end(tvb, offset, -1, &next_offset, FALSE);
if (linelen) {
reqresp_tree = proto_tree_add_subtree(kismet_tree, tvb, offset,
next_offset - offset, ett_kismet_reqresp, NULL,
tvb_format_text(tvb, offset,
next_offset - offset - 1));
tokenlen = get_token_len(line, line + linelen, &next_token);
if (tokenlen != 0) {
guint8 *reqresp;
reqresp = tvb_get_string_enc(wmem_packet_scope(), tvb, offset, tokenlen, ENC_ASCII);
if (is_request) {
} else {
if (!strncmp(reqresp, "*KISMET", 7)) {
offset += (gint) (next_token - line);
linelen -= (int) (next_token - line);
line = next_token;
tokenlen = get_token_len(line, line + linelen, &next_token);
proto_tree_add_string(reqresp_tree, hf_kismet_version, tvb, offset,
tokenlen, format_text(wmem_packet_scope(), line, tokenlen));
offset += (gint) (next_token - line);
linelen -= (int) (next_token - line);
line = next_token;
tokenlen = get_token_len(line, line + linelen, &next_token);
proto_tree_add_string(reqresp_tree, hf_kismet_start_time, tvb, offset,
tokenlen, format_text(wmem_packet_scope(), line, tokenlen));
offset += (gint) (next_token - line);
linelen -= (int) (next_token - line);
line = next_token;
tokenlen = get_token_len(line, line + linelen, &next_token);
proto_tree_add_string(reqresp_tree, hf_kismet_server_name, tvb, offset,
tokenlen, format_text(wmem_packet_scope(), line + 1, tokenlen - 2));
offset += (gint) (next_token - line);
linelen -= (int) (next_token - line);
line = next_token;
tokenlen = get_token_len(line, line + linelen, &next_token);
proto_tree_add_string(reqresp_tree, hf_kismet_build_revision, tvb, offset,
tokenlen, format_text(wmem_packet_scope(), line, tokenlen));
offset += (gint) (next_token - line);
linelen -= (int) (next_token - line);
line = next_token;
tokenlen = get_token_len(line, line + linelen, &next_token);
proto_tree_add_string(reqresp_tree, hf_kismet_unknown_field, tvb, offset,
tokenlen, format_text(wmem_packet_scope(), line, tokenlen));
offset += (gint) (next_token - line);
linelen -= (int) (next_token - line);
line = next_token;
tokenlen = get_token_len(line, line + linelen, &next_token);
proto_tree_add_string(reqresp_tree, hf_kismet_extended_version_string, tvb, offset,
tokenlen, format_text(wmem_packet_scope(), line, tokenlen));
}
if (!strncmp(reqresp, "*TIME", 5)) {
nstime_t t;
char *ptr = NULL;
proto_tree* time_item;
t.nsecs = 0;
offset += (gint) (next_token - line);
linelen -= (int) (next_token - line);
line = next_token;
tokenlen = get_token_len(line, line + linelen, &next_token);
if (ws_strtou64(format_text(wmem_packet_scope(), line, tokenlen), NULL, (guint64*)&t.secs)) {
ptr = abs_time_secs_to_str(wmem_packet_scope(), t.secs, ABSOLUTE_TIME_LOCAL, TRUE);
}
time_item = proto_tree_add_time_format_value(reqresp_tree, hf_kismet_time, tvb, offset,
tokenlen, &t, "%s", ptr ? ptr : "");
if (!ptr)
expert_add_info(pinfo, time_item, &ei_time_invalid);
}
}
line = next_token;
}
}
offset = next_offset;
}
return tvb_captured_length(tvb);
}
static gboolean
response_is_continuation(const guchar * data)
{
if (!strncmp(data, "*", 1))
return FALSE;
if (!strncmp(data, "!", 1))
return FALSE;
return TRUE;
}
void
proto_register_kismet(void)
{
static hf_register_info hf[] = {
{&hf_kismet_response,
{"Response", "kismet.response", FT_BOOLEAN, BASE_NONE,
NULL, 0x0, "TRUE if kismet response", HFILL}},
{&hf_kismet_request,
{"Request", "kismet.request", FT_BOOLEAN, BASE_NONE,
NULL, 0x0, "TRUE if kismet request", HFILL}},
{&hf_kismet_version,
{"Version", "kismet.version", FT_STRING, BASE_NONE,
NULL, 0x0, NULL, HFILL}},
{&hf_kismet_start_time,
{"Start time", "kismet.start_time", FT_STRING, BASE_NONE,
NULL, 0x0, NULL, HFILL}},
{&hf_kismet_server_name,
{"Server name", "kismet.server_name", FT_STRING, BASE_NONE,
NULL, 0x0, NULL, HFILL}},
{&hf_kismet_build_revision,
{"Build revision", "kismet.build_revision", FT_STRING, BASE_NONE,
NULL, 0x0, NULL, HFILL}},
{&hf_kismet_unknown_field,
{"Unknown field", "kismet.unknown_field", FT_STRING, BASE_NONE,
NULL, 0x0, NULL, HFILL}},
{&hf_kismet_extended_version_string,
{"Extended version string", "kismet.extended_version_string", FT_STRING, BASE_NONE,
NULL, 0x0, NULL, HFILL}},
{&hf_kismet_time,
{"Time", "kismet.time", FT_ABSOLUTE_TIME, ABSOLUTE_TIME_LOCAL,
NULL, 0x0, NULL, HFILL}},
};
static ei_register_info ei[] = {
{ &ei_time_invalid, { "kismet.time.invalid", PI_PROTOCOL, PI_WARN, "Invalid time", EXPFILL }}
};
static gint *ett[] = {
&ett_kismet,
&ett_kismet_reqresp,
};
expert_module_t* expert_kismet;
proto_kismet = proto_register_protocol("Kismet Client/Server Protocol", "Kismet", "kismet");
proto_register_field_array(proto_kismet, hf, array_length (hf));
proto_register_subtree_array(ett, array_length (ett));
expert_kismet = expert_register_protocol(proto_kismet);
expert_register_field_array(expert_kismet, ei, array_length(ei));
}
void
proto_reg_handoff_kismet(void)
{
dissector_handle_t kismet_handle;
kismet_handle = create_dissector_handle(dissect_kismet, proto_kismet);
dissector_add_uint_with_preference("tcp.port", TCP_PORT_KISMET, kismet_handle);
}
