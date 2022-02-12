static int
dissect_pop(tvbuff_t *tvb, packet_info *pinfo, proto_tree *tree, void* data _U_)
{
struct pop_proto_data *frame_data_p;
gboolean is_request;
gboolean is_continuation;
proto_tree *pop_tree, *reqresp_tree;
proto_item *ti;
gint offset = 0;
const guchar *line;
gint next_offset;
int linelen;
int tokenlen;
const guchar *next_token;
fragment_head *frag_msg = NULL;
tvbuff_t *next_tvb = NULL;
conversation_t *conversation = NULL;
struct pop_data_val *data_val = NULL;
gint length_remaining;
col_set_str(pinfo->cinfo, COL_PROTOCOL, "POP");
frame_data_p = (struct pop_proto_data *)p_get_proto_data(wmem_file_scope(), pinfo, proto_pop, 0);
conversation = find_or_create_conversation(pinfo);
data_val = (struct pop_data_val *)conversation_get_proto_data(conversation, proto_pop);
if (!data_val) {
data_val = wmem_new0(wmem_file_scope(), struct pop_data_val);
conversation_add_proto_data(conversation, proto_pop, data_val);
}
linelen = tvb_find_line_end(tvb, offset, -1, &next_offset, FALSE);
line = tvb_get_ptr(tvb, offset, linelen);
if (pinfo->match_uint == pinfo->destport) {
is_request = TRUE;
is_continuation = FALSE;
} else {
is_request = FALSE;
is_continuation = response_is_continuation(line);
}
if (is_continuation) {
length_remaining = tvb_reported_length_remaining(tvb, offset);
col_add_fstr(pinfo->cinfo, COL_INFO, "S: DATA fragment, %d byte%s",
length_remaining, plurality (length_remaining, "", "s"));
}
else
col_add_fstr(pinfo->cinfo, COL_INFO, "%s: %s", is_request ? "C" : "S",
format_text(line, linelen));
ti = proto_tree_add_item(tree, proto_pop, tvb, offset, -1, ENC_NA);
pop_tree = proto_item_add_subtree(ti, ett_pop);
if (is_continuation) {
if (pop_data_desegment) {
if (!frame_data_p) {
data_val->msg_read_len += tvb_reported_length(tvb);
frame_data_p = wmem_new(wmem_file_scope(), struct pop_proto_data);
frame_data_p->conversation_id = conversation->conv_index;
frame_data_p->more_frags = data_val->msg_read_len < data_val->msg_tot_len;
p_add_proto_data(wmem_file_scope(), pinfo, proto_pop, 0, frame_data_p);
}
frag_msg = fragment_add_seq_next(&pop_data_reassembly_table, tvb, 0,
pinfo,
frame_data_p->conversation_id,
NULL,
tvb_reported_length(tvb),
frame_data_p->more_frags);
next_tvb = process_reassembled_data(tvb, offset, pinfo,
"Reassembled DATA",
frag_msg, &pop_data_frag_items,
NULL, pop_tree);
if (next_tvb) {
if (imf_handle)
call_dissector(imf_handle, next_tvb, pinfo, tree);
if (data_val) {
data_val->msg_read_len = 0;
data_val->msg_tot_len = 0;
}
pinfo->fragmented = FALSE;
} else {
pinfo->fragmented = TRUE;
}
} else {
call_data_dissector(tvb, pinfo, pop_tree);
}
return tvb_captured_length(tvb);
}
ti = proto_tree_add_string_format(pop_tree,
(is_request) ?
hf_pop_request :
hf_pop_response,
tvb, offset,
next_offset - offset,
"", "%s",
tvb_format_text(tvb, offset, next_offset - offset));
reqresp_tree = proto_item_add_subtree(ti, ett_pop_reqresp);
tokenlen = get_token_len(line, line + linelen, &next_token);
if (tokenlen != 0) {
proto_tree_add_item(reqresp_tree,
(is_request) ?
hf_pop_request_command :
hf_pop_response_indicator,
tvb, offset, tokenlen, ENC_ASCII|ENC_NA);
if (data_val) {
if (is_request) {
if (g_ascii_strncasecmp(line, "RETR", 4) == 0 ||
g_ascii_strncasecmp(line, "TOP", 3) == 0)
data_val->msg_request = TRUE;
if (g_ascii_strncasecmp(line, "STLS", 4) == 0) {
data_val->stls_request = TRUE;
}
} else {
if (data_val->msg_request) {
if (g_ascii_strncasecmp(line, "+OK ", 4) == 0) {
data_val->msg_read_len = 0;
data_val->msg_tot_len = atoi(line + 4);
}
data_val->msg_request = FALSE;
}
if (data_val->stls_request) {
if (g_ascii_strncasecmp(line, "+OK ", 4) == 0) {
ssl_starttls_ack(ssl_handle, pinfo, pop_handle);
}
data_val->stls_request = FALSE;
}
}
}
offset += (gint) (next_token - line);
linelen -= (int) (next_token - line);
}
if (tree) {
if (linelen != 0) {
proto_tree_add_item(reqresp_tree,
(is_request) ?
hf_pop_request_parameter :
hf_pop_response_description,
tvb, offset, linelen, ENC_ASCII|ENC_NA);
}
offset = next_offset;
while (tvb_offset_exists(tvb, offset)) {
tvb_find_line_end(tvb, offset, -1, &next_offset, FALSE);
proto_tree_add_string_format(pop_tree,
(is_request) ?
hf_pop_request_data :
hf_pop_response_data,
tvb, offset,
next_offset - offset,
"", "%s",
tvb_format_text(tvb, offset, next_offset - offset));
offset = next_offset;
}
}
return tvb_captured_length(tvb);
}
static gboolean response_is_continuation(const guchar *data)
{
if (strncmp(data, "+OK", strlen("+OK")) == 0)
return FALSE;
if (strncmp(data, "-ERR", strlen("-ERR")) == 0)
return FALSE;
return TRUE;
}
static void pop_data_reassemble_init (void)
{
reassembly_table_init (&pop_data_reassembly_table,
&addresses_ports_reassembly_table_functions);
}
static void pop_data_reassemble_cleanup (void)
{
reassembly_table_destroy(&pop_data_reassembly_table);
}
void
proto_register_pop(void)
{
static hf_register_info hf[] = {
{ &hf_pop_response,
{ "Response", "pop.response",
FT_STRING, BASE_NONE, NULL, 0x0, NULL, HFILL }},
{ &hf_pop_response_indicator,
{ "Response indicator", "pop.response.indicator",
FT_STRING, BASE_NONE, NULL, 0x0, NULL, HFILL }},
{ &hf_pop_response_description,
{ "Response description", "pop.response.description",
FT_STRING, BASE_NONE, NULL, 0x0, NULL, HFILL }},
{ &hf_pop_response_data,
{ "Data", "pop.response.data",
FT_STRING, BASE_NONE, NULL, 0x0, "Response Data", HFILL }},
{ &hf_pop_request,
{ "Request", "pop.request",
FT_STRING, BASE_NONE, NULL, 0x0, NULL, HFILL }},
{ &hf_pop_request_command,
{ "Request command", "pop.request.command",
FT_STRING, BASE_NONE, NULL, 0x0, NULL, HFILL }},
{ &hf_pop_request_parameter,
{ "Request parameter", "pop.request.parameter",
FT_STRING, BASE_NONE, NULL, 0x0, NULL, HFILL }},
{ &hf_pop_request_data,
{ "Data", "pop.request.data",
FT_STRING, BASE_NONE, NULL, 0x0, "Request data", HFILL }},
{ &hf_pop_data_fragments,
{ "DATA fragments", "pop.data.fragments", FT_NONE, BASE_NONE,
NULL, 0x00, "Message fragments", HFILL } },
{ &hf_pop_data_fragment,
{ "DATA fragment", "pop.data.fragment", FT_FRAMENUM, BASE_NONE,
NULL, 0x00, "Message fragment", HFILL } },
{ &hf_pop_data_fragment_overlap,
{ "DATA fragment overlap", "pop.data.fragment.overlap", FT_BOOLEAN,
BASE_NONE, NULL, 0x0, "Message fragment overlap", HFILL } },
{ &hf_pop_data_fragment_overlap_conflicts,
{ "DATA fragment overlapping with conflicting data",
"pop.data.fragment.overlap.conflicts", FT_BOOLEAN, BASE_NONE, NULL,
0x0, "Message fragment overlapping with conflicting data", HFILL } },
{ &hf_pop_data_fragment_multiple_tails,
{ "DATA has multiple tail fragments",
"pop.data.fragment.multiple_tails", FT_BOOLEAN, BASE_NONE,
NULL, 0x0, "Message has multiple tail fragments", HFILL } },
{ &hf_pop_data_fragment_too_long_fragment,
{ "DATA fragment too long", "pop.data.fragment.too_long_fragment",
FT_BOOLEAN, BASE_NONE, NULL, 0x0, "Message fragment too long",
HFILL } },
{ &hf_pop_data_fragment_error,
{ "DATA defragmentation error", "pop.data.fragment.error", FT_FRAMENUM,
BASE_NONE, NULL, 0x00, "Message defragmentation error", HFILL } },
{ &hf_pop_data_fragment_count,
{ "DATA fragment count", "pop.data.fragment.count", FT_UINT32, BASE_DEC,
NULL, 0x00, NULL, HFILL } },
{ &hf_pop_data_reassembled_in,
{ "Reassembled DATA in frame", "pop.data.reassembled.in", FT_FRAMENUM, BASE_NONE,
NULL, 0x00, "This DATA fragment is reassembled in this frame", HFILL } },
{ &hf_pop_data_reassembled_length,
{ "Reassembled DATA length", "pop.data.reassembled.length", FT_UINT32, BASE_DEC,
NULL, 0x00, "The total length of the reassembled payload", HFILL } },
};
static gint *ett[] = {
&ett_pop,
&ett_pop_reqresp,
&ett_pop_data_fragment,
&ett_pop_data_fragments
};
module_t *pop_module;
proto_pop = proto_register_protocol("Post Office Protocol", "POP", "pop");
register_dissector("pop", dissect_pop, proto_pop);
proto_register_field_array(proto_pop, hf, array_length(hf));
proto_register_subtree_array(ett, array_length(ett));
register_init_routine (&pop_data_reassemble_init);
register_cleanup_routine (&pop_data_reassemble_cleanup);
pop_module = prefs_register_protocol(proto_pop, NULL);
prefs_register_bool_preference(pop_module, "desegment_data",
"Reassemble POP RETR and TOP responses spanning multiple TCP segments",
"Whether the POP dissector should reassemble RETR and TOP responses and spanning multiple TCP segments."
" To use this option, you must also enable \"Allow subdissectors to reassemble TCP streams\" in the TCP protocol settings.",
&pop_data_desegment);
}
void
proto_reg_handoff_pop(void)
{
pop_handle = find_dissector("pop");
dissector_add_uint("tcp.port", TCP_PORT_POP, pop_handle);
ssl_dissector_add(TCP_PORT_SSL_POP, pop_handle);
imf_handle = find_dissector_add_dependency("imf", proto_pop);
ssl_handle = find_dissector_add_dependency("ssl", proto_pop);
}
