static gint
beep_equal(gconstpointer v, gconstpointer w)
{
const struct beep_request_key *v1 = (const struct beep_request_key *)v;
const struct beep_request_key *v2 = (const struct beep_request_key *)w;
#if defined(DEBUG_BEEP_HASH)
printf("Comparing %08X\n and %08X\n",
v1->conversation, v2->conversation);
#endif
if (v1->conversation == v2->conversation)
return 1;
return 0;
}
static guint
beep_hash(gconstpointer v)
{
const struct beep_request_key *key = (const struct beep_request_key *)v;
guint val;
val = key->conversation;
#if defined(DEBUG_BEEP_HASH)
printf("BEEP Hash calculated as %u\n", val);
#endif
return val;
}
static void
beep_init_protocol(void)
{
beep_request_hash = g_hash_table_new(beep_hash, beep_equal);
}
static void
beep_cleanup_protocol(void)
{
g_hash_table_destroy(beep_request_hash);
}
static int
dissect_beep_more(tvbuff_t *tvb, packet_info *pinfo, int offset,
proto_tree *tree)
{
proto_item *hidden_item;
int ret = 0;
guint8 more = tvb_get_guint8(tvb, offset);
hidden_item = proto_tree_add_item(tree, hf_beep_more, tvb, offset, 1, ENC_BIG_ENDIAN);
PROTO_ITEM_SET_HIDDEN(hidden_item);
switch(more) {
case '.':
ret = 0;
break;
case '*':
ret = 1;
break;
default:
expert_add_info(pinfo, hidden_item, &ei_beep_more);
ret = -1;
break;
}
return ret;
}
static int num_len(tvbuff_t *tvb, int offset)
{
unsigned int i = 0;
while (g_ascii_isdigit(tvb_get_guint8(tvb, offset + i))) i++;
return i;
}
static int
check_term(tvbuff_t *tvb, packet_info *pinfo, int offset, proto_tree *tree)
{
if ((tvb_get_guint8(tvb, offset) == 0x0d &&
tvb_get_guint8(tvb, offset + 1) == 0x0a)){
proto_tree_add_item(tree, hf_beep_crlf_terminator, tvb, offset, 2, ENC_NA);
return 2;
}
if ((tvb_get_guint8(tvb, offset) == 0x0d) && !global_beep_strict_term) {
proto_tree_add_expert(tree, pinfo, &ei_beep_cr_terminator, tvb, offset, 1);
return 1;
}
if ((tvb_get_guint8(tvb, offset) == 0x0a) && !global_beep_strict_term) {
proto_tree_add_expert(tree, pinfo, &ei_beep_lf_terminator, tvb, offset, 1);
return 1;
}
proto_tree_add_expert_format(tree, pinfo, &ei_beep_invalid_terminator, tvb,
offset, 1, "Terminator: %s", tvb_format_text(tvb, offset, 2));
return -1;
}
static int header_len(tvbuff_t *tvb, int offset)
{
int i = 0;
guint8 sc;
while (1) {
if ((sc = tvb_get_guint8(tvb, offset + i)) == 0x0d
&& tvb_get_guint8(tvb, offset + i + 1) == 0x0a)
return i;
if (!global_beep_strict_term && (sc == 0x0d || sc == 0x0a))
return i;
i++;
}
}
static int
dissect_beep_mime_header(tvbuff_t *tvb, packet_info *pinfo, int offset,
struct beep_proto_data *beep_frame_data,
proto_tree *tree)
{
proto_tree *ti = NULL, *mime_tree = NULL;
int mime_length = header_len(tvb, offset), cc = 0;
if (beep_frame_data && !beep_frame_data->mime_hdr) return 0;
if (tree) {
ti = proto_tree_add_item(tree, hf_beep_mime_header, tvb, offset, mime_length, ENC_NA|ENC_ASCII);
mime_tree = proto_item_add_subtree(ti, ett_mime_header);
}
if (mime_length == 0) {
if (tree) {
proto_tree_add_string_format(mime_tree, hf_beep_header, tvb, offset, 0, "", "Default values");
}
if ((cc = check_term(tvb, pinfo, offset, mime_tree)) <= 0) {
}
}
else {
if (tree) {
proto_tree_add_item(mime_tree, hf_beep_header, tvb, offset, mime_length, ENC_NA|ENC_ASCII);
}
if ((cc = check_term(tvb, pinfo, offset + mime_length, mime_tree)) <= 0) {
}
}
return mime_length + cc;
}
static int
dissect_beep_int(tvbuff_t *tvb, int offset,
proto_tree *tree, int hf, int *val, int *hfa[])
{
proto_item *hidden_item;
int ival, ind = 0;
unsigned int len = num_len(tvb, offset);
ival = (int)strtol(tvb_get_string_enc(wmem_packet_scope(), tvb, offset, len, ENC_ASCII), NULL, 10);
proto_tree_add_uint(tree, hf, tvb, offset, len, ival);
while (hfa[ind]) {
hidden_item = proto_tree_add_uint(tree, *hfa[ind], tvb, offset, len, ival);
PROTO_ITEM_SET_HIDDEN(hidden_item);
ind++;
}
*val = ival;
return len;
}
static void
set_mime_hdr_flags(int more, struct beep_request_val *request_val,
struct beep_proto_data *beep_frame_data, packet_info *pinfo)
{
if (!request_val) return;
if (pinfo->destport == global_beep_tcp_port) {
if (request_val->c_mime_hdr) {
beep_frame_data->mime_hdr = 0;
if (!more) request_val->c_mime_hdr = 0;
}
else {
beep_frame_data->mime_hdr = 1;
if (more) request_val->c_mime_hdr = 1;
}
}
else {
if (request_val->s_mime_hdr) {
beep_frame_data->mime_hdr = 0;
if (!more) request_val->s_mime_hdr = 0;
}
else {
beep_frame_data->mime_hdr = 1;
if (more) request_val->s_mime_hdr = 1;
}
}
}
static int
dissect_beep_tree(tvbuff_t *tvb, int offset, packet_info *pinfo,
proto_tree *tree, struct beep_request_val *request_val,
struct beep_proto_data *beep_frame_data)
{
proto_tree *ti = NULL, *hdr = NULL;
int st_offset, msgno, ansno, seqno, size, channel, ackno, window, cc,
more;
const char * cmd_temp = NULL;
int is_ANS = 0;
st_offset = offset;
if (tvb_strneql(tvb, offset, "MSG ", 4) == 0)
cmd_temp = "Command: MSG";
if (tvb_strneql(tvb, offset, "RPY ", 4) == 0)
cmd_temp = "Command: RPY";
if (tvb_strneql(tvb, offset, "ERR ", 4) == 0)
cmd_temp = "Command: ERR";
if (tvb_strneql(tvb, offset, "NUL ", 4) == 0)
cmd_temp = "Command: NUL";
if (tvb_strneql(tvb, offset, "ANS ", 4) == 0) {
cmd_temp = "Command: ANS";
is_ANS = 1;
}
if (cmd_temp != NULL) {
if (tree) {
hdr = proto_tree_add_subtree(tree, tvb, offset, header_len(tvb, offset) + 2,
ett_header, NULL, "Header");
ti = proto_tree_add_item(hdr, hf_beep_cmd, tvb, offset, 3, ENC_NA|ENC_ASCII);
proto_item_set_len(ti, 4);
proto_tree_add_boolean(hdr, hf_beep_req, tvb, offset, 3, TRUE);
}
offset += 4;
offset += dissect_beep_int(tvb, offset, hdr, hf_beep_channel, &channel, req_chan_hfa);
offset += 1;
offset += dissect_beep_int(tvb, offset, hdr, hf_beep_msgno, &msgno, req_msgno_hfa);
offset += 1;
if ((more = dissect_beep_more(tvb, pinfo, offset, hdr)) >= 0) {
set_mime_hdr_flags(more, request_val, beep_frame_data, pinfo);
}
else {
if (tree && (tvb_reported_length_remaining(tvb, offset) > 0)) {
proto_tree_add_item(tree, hf_beep_payload_undissected, tvb, offset,
tvb_reported_length_remaining(tvb, offset), ENC_NA|ENC_ASCII);
}
return -1;
}
offset += 2;
offset += dissect_beep_int(tvb, offset, hdr, hf_beep_seqno, &seqno, req_seqno_hfa);
offset += 1;
offset += dissect_beep_int(tvb, offset, hdr, hf_beep_size, &size, req_size_hfa);
if (request_val)
request_val -> size = size;
else if (beep_frame_data) {
beep_frame_data->pl_size = size;
if (beep_frame_data->pl_size < 0) beep_frame_data->pl_size = 0;
}
if (is_ANS) {
offset += 1;
offset += dissect_beep_int(tvb, offset, hdr, hf_beep_ansno, &ansno, req_ansno_hfa);
}
if ((cc = check_term(tvb, pinfo, offset, hdr)) <= 0) {
if (tree && (tvb_reported_length_remaining(tvb, offset) > 0)) {
proto_tree_add_item(tree, hf_beep_payload_undissected, tvb, offset,
tvb_reported_length_remaining(tvb, offset), ENC_NA|ENC_ASCII);
}
return -1;
}
offset += cc;
if (beep_frame_data && beep_frame_data->mime_hdr)
offset += dissect_beep_mime_header(tvb, pinfo, offset, beep_frame_data, hdr);
if (tvb_reported_length_remaining(tvb, offset) > 0) {
int pl_size = MIN(size, tvb_reported_length_remaining(tvb, offset));
if (tree) {
proto_tree_add_item(tree, hf_beep_payload, tvb, offset, pl_size, ENC_NA|ENC_ASCII);
}
offset += pl_size;
if (request_val) {
request_val->size -= pl_size;
if (request_val->size < 0) request_val->size = 0;
}
else if (beep_frame_data) {
beep_frame_data->pl_size -= pl_size;
if (beep_frame_data->pl_size < 0) beep_frame_data->pl_size = 0;
}
}
if (tvb_reported_length_remaining(tvb, offset) > 0)
offset += dissect_beep_tree(tvb, offset, pinfo, tree, request_val, beep_frame_data);
} else if (tvb_strneql(tvb, offset, "SEQ ", 4) == 0) {
if (tree) {
ti = proto_tree_add_item(hdr, hf_beep_cmd, tvb, offset, 3, ENC_NA|ENC_ASCII);
proto_item_set_len(ti, 4);
}
offset += 3;
offset += 1;
offset += dissect_beep_int(tvb, offset, tree, hf_beep_channel, &channel, seq_chan_hfa);
offset += 1;
offset += dissect_beep_int(tvb, offset, tree, hf_beep_ackno, &ackno, seq_ackno_hfa);
offset += 1;
offset += dissect_beep_int(tvb, offset, tree, hf_beep_window, &window, seq_window_hfa);
if ((cc = check_term(tvb, pinfo, offset, tree)) <= 0) {
if (tree && (tvb_reported_length_remaining(tvb, offset) > 0)) {
proto_tree_add_item(tree, hf_beep_payload_undissected, tvb, offset,
tvb_reported_length_remaining(tvb, offset), ENC_NA|ENC_ASCII);
}
return -1;
}
offset += cc;
} else if (tvb_strneql(tvb, offset, "END", 3) == 0) {
proto_tree *tr = NULL;
if (tree) {
tr = proto_tree_add_subtree(tree, tvb, offset, MIN(5, MAX(0, tvb_reported_length_remaining(tvb, offset))),
ett_trailer, NULL, "Trailer");
proto_tree_add_item(hdr, hf_beep_cmd, tvb, offset, 3, ENC_NA|ENC_ASCII);
}
offset += 3;
if ((cc = check_term(tvb, pinfo, offset, tr)) <= 0) {
if (tree && (tvb_reported_length_remaining(tvb, offset) > 0)) {
proto_tree_add_item(tree, hf_beep_payload_undissected, tvb, offset,
tvb_reported_length_remaining(tvb, offset), ENC_NA|ENC_ASCII);
}
return -1;
}
offset += cc;
}
if (tvb_reported_length_remaining(tvb, offset) > 0) {
int pl_size = 0;
if (request_val) {
pl_size = MIN(request_val->size, tvb_reported_length_remaining(tvb, offset));
if (pl_size == 0) {
pl_size = tvb_reported_length_remaining(tvb, offset);
}
} else if (beep_frame_data) {
pl_size = MIN(beep_frame_data->pl_size, tvb_reported_length_remaining(tvb, offset));
} else {
pl_size = tvb_reported_length_remaining(tvb, offset);
}
if (pl_size == 0 && offset == st_offset)
pl_size = tvb_reported_length_remaining(tvb, offset);
if (pl_size > 0) {
if (tree) {
proto_tree_add_item(tree, hf_beep_payload, tvb, offset, pl_size, ENC_NA|ENC_ASCII);
}
offset += pl_size;
if (request_val){
request_val->size -= pl_size;
if (request_val->size < 0) request_val->size = 0;
}
else if (beep_frame_data) {
beep_frame_data->pl_size -= pl_size;
if (beep_frame_data->pl_size < 0) beep_frame_data->pl_size = 0;
}
}
if (tvb_reported_length_remaining(tvb, offset) > 0) {
offset += dissect_beep_tree(tvb, offset, pinfo, tree, request_val, beep_frame_data);
}
}
return offset - st_offset;
}
static int
dissect_beep(tvbuff_t *tvb, packet_info *pinfo, proto_tree *tree, void* data _U_)
{
int offset;
struct beep_proto_data *beep_frame_data;
proto_tree *beep_tree = NULL, *ti = NULL;
conversation_t *conversation = NULL;
struct beep_request_key request_key, *new_request_key;
struct beep_request_val *request_val = NULL;
offset = 0;
beep_frame_data = (struct beep_proto_data *)p_get_proto_data(wmem_file_scope(), pinfo, proto_beep, 0);
if (!beep_frame_data) {
conversation = find_or_create_conversation(pinfo);
request_key.conversation = conversation->conv_index;
request_val = (struct beep_request_val *)g_hash_table_lookup(beep_request_hash, &request_key);
if (!request_val) {
new_request_key = wmem_new(wmem_file_scope(), struct beep_request_key);
new_request_key->conversation = conversation->conv_index;
request_val = wmem_new(wmem_file_scope(), struct beep_request_val);
request_val->processed = 0;
request_val->size = 0;
g_hash_table_insert(beep_request_hash, new_request_key, request_val);
}
}
col_set_str(pinfo->cinfo, COL_PROTOCOL, "BEEP");
if (tvb_reported_length_remaining(tvb, offset) > 0)
col_add_str(pinfo->cinfo, COL_INFO, tvb_format_text(tvb, offset, tvb_reported_length_remaining(tvb, offset)));
if (tree) {
ti = proto_tree_add_item(tree, proto_beep, tvb, offset, -1, ENC_NA);
beep_tree = proto_item_add_subtree(ti, ett_beep);
}
if (beep_frame_data != NULL && beep_frame_data->pl_left > 0) {
int pl_left = beep_frame_data->pl_left;
pl_left = MIN(pl_left, MAX(0, tvb_reported_length_remaining(tvb, offset)));
if (tree && (pl_left > 0)) {
proto_tree_add_item(tree, hf_beep_payload, tvb, offset, pl_left, ENC_NA|ENC_ASCII);
}
offset += pl_left;
}
else if (request_val && request_val->size > 0) {
int pl_left = request_val->size;
request_val->size = 0;
beep_frame_data = wmem_new(wmem_file_scope(), struct beep_proto_data);
beep_frame_data->pl_left = pl_left;
beep_frame_data->pl_size = 0;
beep_frame_data->mime_hdr = 0;
p_add_proto_data(wmem_file_scope(), pinfo, proto_beep, 0, beep_frame_data);
}
if (beep_frame_data == NULL) {
beep_frame_data = wmem_new(wmem_file_scope(), struct beep_proto_data);
beep_frame_data->pl_left = 0;
beep_frame_data->pl_size = 0;
beep_frame_data->mime_hdr = 0;
p_add_proto_data(wmem_file_scope(), pinfo, proto_beep, 0, beep_frame_data);
}
if (tvb_reported_length_remaining(tvb, offset) > 0) {
dissect_beep_tree(tvb, offset, pinfo, beep_tree, request_val, beep_frame_data);
}
return tvb_captured_length(tvb);
}
void
proto_register_beep(void)
{
static hf_register_info hf[] = {
{ &hf_beep_req,
{ "Request", "beep.req", FT_BOOLEAN, BASE_NONE, NULL, 0x0, NULL, HFILL }},
{ &hf_beep_cmd,
{ "Command", "beep.command", FT_STRING, BASE_NONE, NULL, 0x0, NULL, HFILL }},
{ &hf_beep_req_chan,
{ "Request Channel Number", "beep.req.channel", FT_UINT32, BASE_DEC, NULL, 0x0, NULL, HFILL }},
#if 0
{ &hf_beep_rsp,
{ "Response", "beep.rsp", FT_BOOLEAN, BASE_NONE, NULL, 0x0, NULL, HFILL }},
{ &hf_beep_rsp_chan,
{ "Response Channel Number", "beep.rsp.channel", FT_UINT32, BASE_DEC, NULL, 0x0, NULL, HFILL }},
#endif
{ &hf_beep_seq_chan,
{ "Sequence Channel Number", "beep.seq.channel", FT_UINT32, BASE_DEC, NULL, 0x0, NULL, HFILL }},
{ &hf_beep_more,
{ "More", "beep.more", FT_UINT8, BASE_HEX, VALS(beep_more_vals), 0x0, NULL, HFILL }},
{ &hf_beep_msgno,
{ "Msgno", "beep.msgno", FT_UINT32, BASE_DEC, NULL, 0x0, NULL, HFILL }},
{ &hf_beep_ansno,
{ "Ansno", "beep.ansno", FT_UINT32, BASE_DEC, NULL, 0x0, NULL, HFILL }},
{ &hf_beep_seqno,
{ "Seqno", "beep.seqno", FT_UINT32, BASE_DEC, NULL, 0x0, NULL, HFILL }},
{ &hf_beep_size,
{ "Size", "beep.size", FT_UINT32, BASE_DEC, NULL, 0x0, NULL, HFILL }},
{ &hf_beep_channel,
{ "Channel", "beep.channel", FT_UINT32, BASE_DEC, NULL, 0x0, NULL, HFILL }},
{ &hf_beep_mime_header,
{ "Mime header", "beep.mime_header", FT_STRING, BASE_NONE, NULL, 0x0, NULL, HFILL }},
{ &hf_beep_header,
{ "Header", "beep.header", FT_STRING, BASE_NONE, NULL, 0x0, NULL, HFILL }},
#if 0
{ &hf_beep_status,
{ "Status", "beep.status", FT_UINT8, BASE_HEX, VALS(beep_status_vals), 0x0, NULL, HFILL }},
#endif
{ &hf_beep_ackno,
{ "Ackno", "beep.seq.ackno", FT_UINT32, BASE_DEC, NULL, 0x0, NULL, HFILL }},
{ &hf_beep_window,
{ "Window", "beep.seq.window", FT_UINT32, BASE_DEC, NULL, 0x0, NULL, HFILL }},
{ &hf_beep_payload,
{ "Payload", "beep.payload", FT_STRING, BASE_NONE, NULL, 0x0, NULL, HFILL }},
{ &hf_beep_payload_undissected,
{ "Undissected Payload", "beep.payload_undissected", FT_STRING, BASE_NONE, NULL, 0x0, NULL, HFILL }},
{ &hf_beep_crlf_terminator,
{ "Terminator: CRLF", "beep.crlf_terminator", FT_NONE, BASE_NONE, NULL, 0x0, NULL, HFILL }},
};
static gint *ett[] = {
&ett_beep,
&ett_mime_header,
&ett_header,
&ett_trailer,
};
static ei_register_info ei[] = {
{ &ei_beep_more, { "beep.more.expected", PI_PROTOCOL, PI_WARN, "Expected More Flag (* or .)", EXPFILL }},
{ &ei_beep_cr_terminator, { "beep.cr_terminator", PI_PROTOCOL, PI_WARN, "Nonstandard Terminator: CR", EXPFILL }},
{ &ei_beep_lf_terminator, { "beep.lf_terminator", PI_PROTOCOL, PI_WARN, "Nonstandard Terminator: LF", EXPFILL }},
{ &ei_beep_invalid_terminator, { "beep.invalid_terminator", PI_PROTOCOL, PI_WARN, "Invalid Terminator", EXPFILL }},
};
module_t *beep_module;
expert_module_t* expert_beep;
proto_beep = proto_register_protocol("Blocks Extensible Exchange Protocol",
"BEEP", "beep");
proto_register_field_array(proto_beep, hf, array_length(hf));
proto_register_subtree_array(ett, array_length(ett));
expert_beep = expert_register_protocol(proto_beep);
expert_register_field_array(expert_beep, ei, array_length(ei));
register_init_routine(&beep_init_protocol);
register_cleanup_routine(&beep_cleanup_protocol);
beep_module = prefs_register_protocol(proto_beep, proto_reg_handoff_beep);
prefs_register_uint_preference(beep_module, "tcp.port", "BEEP TCP Port",
"Set the port for BEEP messages (if other"
" than the default of 10288)",
10, &global_beep_tcp_port);
prefs_register_bool_preference(beep_module, "strict_header_terminator",
"BEEP Header Requires CRLF",
"Specifies that BEEP requires CRLF as a "
"terminator, and not just CR or LF",
&global_beep_strict_term);
}
void
proto_reg_handoff_beep(void)
{
static gboolean beep_prefs_initialized = FALSE;
static dissector_handle_t beep_handle;
static guint beep_tcp_port;
if (!beep_prefs_initialized) {
beep_handle = create_dissector_handle(dissect_beep, proto_beep);
beep_prefs_initialized = TRUE;
}
else {
dissector_delete_uint("tcp.port", beep_tcp_port, beep_handle);
}
beep_tcp_port = global_beep_tcp_port;
dissector_add_uint("tcp.port", global_beep_tcp_port, beep_handle);
}
