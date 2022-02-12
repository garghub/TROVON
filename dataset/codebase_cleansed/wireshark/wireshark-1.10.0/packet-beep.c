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
#if defined(DEBUG_BEEP_HASH)
fprintf(stderr, "Initializing BEEP hashtable area\n");
#endif
if (beep_request_hash)
g_hash_table_destroy(beep_request_hash);
beep_request_hash = g_hash_table_new(beep_hash, beep_equal);
}
static int
dissect_beep_more(tvbuff_t *tvb, packet_info *pinfo, int offset,
proto_tree *tree)
{
proto_item *hidden_item;
int ret = 0;
guint8 more = tvb_get_guint8(tvb, offset);
hidden_item = proto_tree_add_item(tree, hf_beep_more, tvb, offset, 1, ENC_NA);
PROTO_ITEM_SET_HIDDEN(hidden_item);
switch(more) {
case '.':
ret = 0;
break;
case '*':
ret = 1;
break;
default:
expert_add_info_format(pinfo, hidden_item, PI_PROTOCOL, PI_WARN, "Expected More Flag (* or .)");
ret = -1;
break;
}
return ret;
}
static int num_len(tvbuff_t *tvb, int offset)
{
unsigned int i = 0;
while (isdigit(tvb_get_guint8(tvb, offset + i))) i++;
return i;
}
static int
check_term(tvbuff_t *tvb, packet_info *pinfo, int offset, proto_tree *tree)
{
proto_item *ti;
if ((tvb_get_guint8(tvb, offset) == 0x0d &&
tvb_get_guint8(tvb, offset + 1) == 0x0a)){
proto_tree_add_text(tree, tvb, offset, 2, "Terminator: CRLF");
return 2;
}
if ((tvb_get_guint8(tvb, offset) == 0x0d) && !global_beep_strict_term) {
ti = proto_tree_add_text(tree, tvb, offset, 1, "Terminator: CR");
expert_add_info_format(pinfo, ti, PI_PROTOCOL, PI_WARN, "Nonstandard Terminator: CR");
return 1;
}
if ((tvb_get_guint8(tvb, offset) == 0x0a) && !global_beep_strict_term) {
ti = proto_tree_add_text(tree, tvb, offset, 1, "Terminator: LF");
expert_add_info_format(pinfo, ti, PI_PROTOCOL, PI_WARN, "Nonstandard Terminator: LF");
return 1;
}
ti = proto_tree_add_text(tree, tvb, offset, 1, "Terminator: %s", tvb_format_text(tvb, offset, 2));
expert_add_info_format(pinfo, ti, PI_PROTOCOL, PI_WARN, "Invalid Terminator: %s", tvb_format_text(tvb, offset, 2));
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
proto_tree_add_text(mime_tree, tvb, offset, 0, "Default values");
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
unsigned int i = num_len(tvb, offset);
guint8 int_buff[100];
memset(int_buff, '\0', sizeof(int_buff));
tvb_memcpy(tvb, int_buff, offset, MIN(sizeof(int_buff) - 1, i));
if (sscanf((gchar*)int_buff, "%d", &ival) != 1)
ival = 0;
if (tree) {
proto_tree_add_uint(tree, hf, tvb, offset, i, ival);
}
while (hfa[ind]) {
hidden_item = proto_tree_add_uint(tree, *hfa[ind], tvb, offset, i, ival);
PROTO_ITEM_SET_HIDDEN(hidden_item);
ind++;
}
*val = ival;
return i;
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
ti = proto_tree_add_text(tree, tvb, offset, header_len(tvb, offset) + 2, "Header");
hdr = proto_item_add_subtree(ti, ett_header);
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
if (tree && (tvb_length_remaining(tvb, offset) > 0)) {
proto_tree_add_item(tree, hf_beep_payload_undissected, tvb, offset,
tvb_length_remaining(tvb, offset), ENC_NA|ENC_ASCII);
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
if (tree && (tvb_length_remaining(tvb, offset) > 0)) {
proto_tree_add_item(tree, hf_beep_payload_undissected, tvb, offset,
tvb_length_remaining(tvb, offset), ENC_NA|ENC_ASCII);
}
return -1;
}
offset += cc;
if (beep_frame_data && beep_frame_data->mime_hdr)
offset += dissect_beep_mime_header(tvb, pinfo, offset, beep_frame_data, hdr);
if (tvb_length_remaining(tvb, offset) > 0) {
int pl_size = MIN(size, tvb_length_remaining(tvb, offset));
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
if (tvb_length_remaining(tvb, offset) > 0)
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
if (tree && (tvb_length_remaining(tvb, offset) > 0)) {
proto_tree_add_item(tree, hf_beep_payload_undissected, tvb, offset,
tvb_length_remaining(tvb, offset), ENC_NA|ENC_ASCII);
}
return -1;
}
offset += cc;
} else if (tvb_strneql(tvb, offset, "END", 3) == 0) {
proto_tree *tr = NULL;
if (tree) {
ti = proto_tree_add_text(tree, tvb, offset, MIN(5, MAX(0, tvb_length_remaining(tvb, offset))), "Trailer");
tr = proto_item_add_subtree(ti, ett_trailer);
proto_tree_add_item(hdr, hf_beep_cmd, tvb, offset, 3, ENC_NA|ENC_ASCII);
}
offset += 3;
if ((cc = check_term(tvb, pinfo, offset, tr)) <= 0) {
if (tree && (tvb_length_remaining(tvb, offset) > 0)) {
proto_tree_add_item(tree, hf_beep_payload_undissected, tvb, offset,
tvb_length_remaining(tvb, offset), ENC_NA|ENC_ASCII);
}
return -1;
}
offset += cc;
}
if (tvb_length_remaining(tvb, offset) > 0) {
int pl_size = 0;
if (request_val) {
pl_size = MIN(request_val->size, tvb_length_remaining(tvb, offset));
if (pl_size == 0) {
pl_size = tvb_length_remaining(tvb, offset);
}
} else if (beep_frame_data) {
pl_size = MIN(beep_frame_data->pl_size, tvb_length_remaining(tvb, offset));
} else {
pl_size = tvb_length_remaining(tvb, offset);
}
if (pl_size == 0 && offset == st_offset)
pl_size = tvb_length_remaining(tvb, offset);
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
if (tvb_length_remaining(tvb, offset) > 0) {
offset += dissect_beep_tree(tvb, offset, pinfo, tree, request_val, beep_frame_data);
}
}
return offset - st_offset;
}
static void
dissect_beep(tvbuff_t *tvb, packet_info *pinfo, proto_tree *tree)
{
int offset;
struct beep_proto_data *beep_frame_data;
proto_tree *beep_tree = NULL, *ti = NULL;
conversation_t *conversation = NULL;
struct beep_request_key request_key, *new_request_key;
struct beep_request_val *request_val = NULL;
offset = 0;
beep_frame_data = (struct beep_proto_data *)p_get_proto_data(pinfo->fd, proto_beep, 0);
if (!beep_frame_data) {
conversation = find_or_create_conversation(pinfo);
request_key.conversation = conversation->index;
request_val = (struct beep_request_val *)g_hash_table_lookup(beep_request_hash, &request_key);
if (!request_val) {
new_request_key = (struct beep_request_key *)se_alloc(sizeof(struct beep_request_key));
new_request_key->conversation = conversation->index;
request_val = (struct beep_request_val *)se_alloc(sizeof(struct beep_request_val));
request_val->processed = 0;
request_val->size = 0;
g_hash_table_insert(beep_request_hash, new_request_key, request_val);
}
}
col_set_str(pinfo->cinfo, COL_PROTOCOL, "BEEP");
if (tvb_length_remaining(tvb, offset) > 0)
col_add_str(pinfo->cinfo, COL_INFO, tvb_format_text(tvb, offset, tvb_length_remaining(tvb, offset)));
if (tree) {
ti = proto_tree_add_item(tree, proto_beep, tvb, offset, -1, ENC_NA);
beep_tree = proto_item_add_subtree(ti, ett_beep);
}
if (beep_frame_data != NULL && beep_frame_data->pl_left > 0) {
int pl_left = beep_frame_data->pl_left;
pl_left = MIN(pl_left, MAX(0, tvb_length_remaining(tvb, offset)));
if (tree && (pl_left > 0)) {
proto_tree_add_item(tree, hf_beep_payload, tvb, offset, pl_left, ENC_NA|ENC_ASCII);
}
offset += pl_left;
}
else if (request_val && request_val->size > 0) {
int pl_left = request_val->size;
request_val->size = 0;
beep_frame_data = se_new(struct beep_proto_data);
beep_frame_data->pl_left = pl_left;
beep_frame_data->pl_size = 0;
beep_frame_data->mime_hdr = 0;
p_add_proto_data(pinfo->fd, proto_beep, 0, beep_frame_data);
}
if (beep_frame_data == NULL) {
beep_frame_data = (struct beep_proto_data *)se_alloc(sizeof(struct beep_proto_data));
beep_frame_data->pl_left = 0;
beep_frame_data->pl_size = 0;
beep_frame_data->mime_hdr = 0;
p_add_proto_data(pinfo->fd, proto_beep, 0, beep_frame_data);
}
if (tvb_length_remaining(tvb, offset) > 0) {
offset += dissect_beep_tree(tvb, offset, pinfo, beep_tree, request_val, beep_frame_data);
}
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
};
static gint *ett[] = {
&ett_beep,
&ett_mime_header,
&ett_header,
&ett_trailer,
};
module_t *beep_module;
proto_beep = proto_register_protocol("Blocks Extensible Exchange Protocol",
"BEEP", "beep");
proto_register_field_array(proto_beep, hf, array_length(hf));
proto_register_subtree_array(ett, array_length(ett));
register_init_routine(&beep_init_protocol);
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
