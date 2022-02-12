static gboolean
line_is_smtp_command(const guchar *command, int commandlen)
{
size_t i;
if (commandlen == 4 && g_ascii_isalpha(command[0]) &&
g_ascii_isalpha(command[1]) && g_ascii_isalpha(command[2]) &&
g_ascii_isalpha(command[3])) {
return TRUE;
}
for (i = 0; i < NCOMMANDS; i++) {
if (commandlen == commands[i].len &&
g_ascii_strncasecmp(command, commands[i].command, commands[i].len) == 0)
return TRUE;
}
return FALSE;
}
static void
dissect_smtp_data(tvbuff_t *tvb, int offset, proto_tree *smtp_tree)
{
gint next_offset;
if (smtp_tree) {
while (tvb_offset_exists(tvb, offset)) {
tvb_find_line_end(tvb, offset, -1, &next_offset, FALSE);
proto_tree_add_item(smtp_tree, hf_smtp_message, tvb,
offset, next_offset - offset, ENC_ASCII|ENC_NA);
offset = next_offset;
}
}
}
static void
dissect_smtp(tvbuff_t *tvb, packet_info *pinfo, proto_tree *tree)
{
struct smtp_proto_data *spd_frame_data;
proto_tree *smtp_tree = NULL;
proto_tree *cmdresp_tree;
proto_item *ti, *hidden_item;
int offset = 0;
int request = 0;
conversation_t *conversation;
struct smtp_session_state *session_state;
const guchar *line, *linep, *lineend;
guint32 code;
int linelen = 0;
gint length_remaining;
gboolean eom_seen = FALSE;
gint next_offset;
gint loffset = 0;
int cmdlen;
fragment_data *frag_msg = NULL;
tvbuff_t *next_tvb;
conversation = find_or_create_conversation(pinfo);
session_state = conversation_get_proto_data(conversation, proto_smtp);
if (!session_state) {
session_state = se_alloc(sizeof(struct smtp_session_state));
session_state->smtp_state = SMTP_STATE_READING_CMDS;
session_state->crlf_seen = FALSE;
session_state->data_seen = FALSE;
session_state->msg_read_len = 0;
session_state->msg_tot_len = 0;
session_state->msg_last = TRUE;
session_state->last_nontls_frame = 0;
conversation_add_proto_data(conversation, proto_smtp, session_state);
}
if (session_state->last_nontls_frame != 0 && pinfo->fd->num > session_state->last_nontls_frame) {
guint16 save_can_desegment;
guint32 save_last_nontls_frame;
save_can_desegment = pinfo->can_desegment;
pinfo->can_desegment = pinfo->saved_can_desegment;
save_last_nontls_frame = session_state->last_nontls_frame;
session_state->last_nontls_frame = 0;
call_dissector(ssl_handle, tvb, pinfo, tree);
pinfo->can_desegment = save_can_desegment;
session_state->last_nontls_frame = save_last_nontls_frame;
return;
}
request = pinfo->destport == pinfo->match_uint;
spd_frame_data = p_get_proto_data(pinfo->fd, proto_smtp);
if (!spd_frame_data) {
if(request) {
spd_frame_data = se_alloc0(sizeof(struct smtp_proto_data));
spd_frame_data->conversation_id = conversation->index;
spd_frame_data->more_frags = TRUE;
p_add_proto_data(pinfo->fd, proto_smtp, spd_frame_data);
}
loffset = offset;
while (tvb_offset_exists(tvb, loffset)) {
linelen = tvb_find_line_end(tvb, loffset, -1, &next_offset,
smtp_desegment && pinfo->can_desegment);
if (linelen == -1) {
if (offset == loffset) {
pinfo->desegment_offset = loffset;
pinfo->desegment_len = DESEGMENT_ONE_MORE_SEGMENT;
return;
} else {
linelen = tvb_length_remaining(tvb, loffset);
next_offset = loffset + linelen;
}
}
line = tvb_get_ptr(tvb, loffset, linelen);
if (session_state->smtp_state == SMTP_STATE_READING_DATA) {
if ((session_state->crlf_seen && tvb_strneql(tvb, loffset, ".\r\n", 3) == 0) ||
tvb_strneql(tvb, loffset, "\r\n.\r\n", 5) == 0)
eom_seen = TRUE;
length_remaining = tvb_length_remaining(tvb, loffset);
if (length_remaining == tvb_reported_length_remaining(tvb, loffset) &&
tvb_strneql(tvb, loffset + length_remaining - 2, "\r\n", 2) == 0)
session_state->crlf_seen = TRUE;
else
session_state->crlf_seen = FALSE;
}
if (request) {
if (session_state->smtp_state == SMTP_STATE_READING_DATA) {
if (eom_seen) {
spd_frame_data->pdu_type = SMTP_PDU_EOM;
session_state->smtp_state = SMTP_STATE_READING_CMDS;
break;
} else {
spd_frame_data->pdu_type = SMTP_PDU_MESSAGE;
if (session_state->msg_tot_len > 0) {
session_state->msg_read_len += tvb_length_remaining(tvb, loffset);
if (session_state->msg_read_len == session_state->msg_tot_len) {
session_state->smtp_state = SMTP_STATE_READING_CMDS;
if (session_state->msg_last) {
spd_frame_data->more_frags = FALSE;
}
break;
}
}
}
} else {
linep = line;
lineend = line + linelen;
while (linep < lineend && *linep != ' ')
linep++;
cmdlen = (int)(linep - line);
if (line_is_smtp_command(line, cmdlen)) {
if (g_ascii_strncasecmp(line, "DATA", 4) == 0) {
spd_frame_data->pdu_type = SMTP_PDU_CMD;
session_state->smtp_state = SMTP_STATE_READING_DATA;
session_state->data_seen = TRUE;
} else if (g_ascii_strncasecmp(line, "BDAT", 4) == 0) {
guint32 msg_len;
msg_len = strtoul (line+5, NULL, 10);
spd_frame_data->pdu_type = SMTP_PDU_CMD;
session_state->data_seen = TRUE;
session_state->msg_tot_len += msg_len;
if (msg_len == 0) {
session_state->smtp_state = SMTP_STATE_READING_CMDS;
} else {
session_state->smtp_state = SMTP_STATE_READING_DATA;
}
if (g_ascii_strncasecmp(line+linelen-4, "LAST", 4) == 0) {
session_state->msg_last = TRUE;
if (msg_len == 0) {
spd_frame_data->more_frags = FALSE;
}
} else {
session_state->msg_last = FALSE;
}
} else if (g_ascii_strncasecmp(line, "STARTTLS", 8) == 0) {
session_state->smtp_state = SMTP_STATE_AWAITING_STARTTLS_RESPONSE;
spd_frame_data->pdu_type = SMTP_PDU_CMD;
} else {
spd_frame_data->pdu_type = SMTP_PDU_CMD;
}
} else {
spd_frame_data->pdu_type = session_state->data_seen ? SMTP_PDU_MESSAGE : SMTP_PDU_CMD;
}
}
}
loffset = next_offset;
}
}
col_set_str(pinfo->cinfo, COL_PROTOCOL, "SMTP");
if (check_col(pinfo->cinfo, COL_INFO)) {
col_clear(pinfo->cinfo, COL_INFO);
if (request) {
switch (spd_frame_data->pdu_type) {
case SMTP_PDU_MESSAGE:
length_remaining = tvb_length_remaining(tvb, offset);
col_set_str(pinfo->cinfo, COL_INFO, smtp_data_desegment ? "C: DATA fragment" : "C: Message Body");
col_append_fstr(pinfo->cinfo, COL_INFO, ", %d byte%s", length_remaining,
plurality (length_remaining, "", "s"));
break;
case SMTP_PDU_EOM:
col_set_str(pinfo->cinfo, COL_INFO, "C: .");
break;
case SMTP_PDU_CMD:
loffset = offset;
while (tvb_offset_exists(tvb, loffset)) {
linelen = tvb_find_line_end(tvb, loffset, -1, &next_offset, FALSE);
line = tvb_get_ptr(tvb, loffset, linelen);
if(loffset == offset)
col_append_fstr(pinfo->cinfo, COL_INFO, "C: %s",
format_text(line, linelen));
else {
col_append_fstr(pinfo->cinfo, COL_INFO, " | %s",
format_text(line, linelen));
}
loffset = next_offset;
}
break;
}
} else {
loffset = offset;
while (tvb_offset_exists(tvb, loffset)) {
linelen = tvb_find_line_end(tvb, loffset, -1, &next_offset, FALSE);
line = tvb_get_ptr(tvb, loffset, linelen);
if (loffset == offset)
col_append_fstr(pinfo->cinfo, COL_INFO, "S: %s",
format_text(line, linelen));
else {
col_append_fstr(pinfo->cinfo, COL_INFO, " | %s",
format_text(line, linelen));
}
loffset = next_offset;
}
}
}
if (tree) {
ti = proto_tree_add_item(tree, proto_smtp, tvb, offset, -1, ENC_NA);
smtp_tree = proto_item_add_subtree(ti, ett_smtp);
}
if (request) {
switch (spd_frame_data->pdu_type) {
case SMTP_PDU_MESSAGE:
if (smtp_data_desegment) {
frag_msg = fragment_add_seq_next(tvb, 0, pinfo, spd_frame_data->conversation_id,
smtp_data_segment_table, smtp_data_reassembled_table,
tvb_length(tvb), spd_frame_data->more_frags);
} else {
dissect_smtp_data(tvb, offset, smtp_tree);
}
break;
case SMTP_PDU_EOM:
proto_tree_add_text(smtp_tree, tvb, offset, linelen, "C: .");
if (smtp_data_desegment) {
if (loffset)
fragment_add_seq_next(tvb, 0, pinfo, spd_frame_data->conversation_id,
smtp_data_segment_table, smtp_data_reassembled_table,
loffset, spd_frame_data->more_frags);
frag_msg = fragment_end_seq_next (pinfo, spd_frame_data->conversation_id, smtp_data_segment_table,
smtp_data_reassembled_table);
}
break;
case SMTP_PDU_CMD:
loffset = offset;
while (tvb_offset_exists(tvb, loffset)) {
linelen = tvb_find_line_end(tvb, loffset, -1, &next_offset, FALSE);
if (linelen >= 4)
cmdlen = 4;
else
cmdlen = linelen;
hidden_item = proto_tree_add_boolean(smtp_tree, hf_smtp_req, tvb,
0, 0, TRUE);
PROTO_ITEM_SET_HIDDEN(hidden_item);
ti = proto_tree_add_item(smtp_tree, hf_smtp_command_line, tvb,
loffset, next_offset - loffset, ENC_ASCII|ENC_NA);
cmdresp_tree = proto_item_add_subtree(ti, ett_smtp_cmdresp);
proto_tree_add_item(cmdresp_tree, hf_smtp_req_command, tvb,
loffset, cmdlen, ENC_ASCII|ENC_NA);
if (linelen > 5) {
proto_tree_add_item(cmdresp_tree, hf_smtp_req_parameter, tvb,
loffset + 5, linelen - 5, ENC_ASCII|ENC_NA);
}
if (smtp_data_desegment && !spd_frame_data->more_frags) {
frag_msg = fragment_end_seq_next (pinfo, spd_frame_data->conversation_id, smtp_data_segment_table,
smtp_data_reassembled_table);
}
loffset = next_offset;
}
}
if (smtp_data_desegment) {
next_tvb = process_reassembled_data(tvb, offset, pinfo, "Reassembled SMTP",
frag_msg, &smtp_data_frag_items, NULL, smtp_tree);
if (next_tvb) {
if (imf_handle) {
call_dissector(imf_handle, next_tvb, pinfo, tree);
} else {
dissect_smtp_data(tvb, offset, smtp_tree);
}
pinfo->fragmented = FALSE;
} else {
pinfo->fragmented = TRUE;
}
}
} else {
if (tree) {
hidden_item = proto_tree_add_boolean(smtp_tree, hf_smtp_rsp, tvb,
0, 0, TRUE);
PROTO_ITEM_SET_HIDDEN(hidden_item);
}
while (tvb_offset_exists(tvb, offset)) {
linelen = tvb_find_line_end(tvb, offset, -1, &next_offset, FALSE);
if (tree) {
ti = proto_tree_add_item(smtp_tree, hf_smtp_response, tvb,
offset, next_offset - offset, ENC_ASCII|ENC_NA);
cmdresp_tree = proto_item_add_subtree(ti, ett_smtp_cmdresp);
} else
cmdresp_tree = NULL;
line = tvb_get_ptr(tvb, offset, linelen);
if (linelen >= 3 && isdigit(line[0]) && isdigit(line[1])
&& isdigit(line[2])) {
code = (line[0] - '0')*100 + (line[1] - '0')*10 + (line[2] - '0');
if (session_state->smtp_state == SMTP_STATE_AWAITING_STARTTLS_RESPONSE) {
if (code == 220) {
session_state->last_nontls_frame = pinfo->fd->num;
}
session_state->smtp_state = SMTP_STATE_READING_CMDS;
}
if (tree) {
proto_tree_add_uint(cmdresp_tree, hf_smtp_rsp_code, tvb, offset, 3,
code);
if (linelen >= 4) {
proto_tree_add_item(cmdresp_tree, hf_smtp_rsp_parameter, tvb,
offset + 4, linelen - 4, ENC_ASCII|ENC_NA);
}
}
}
offset = next_offset;
}
}
}
static void smtp_data_reassemble_init (void)
{
fragment_table_init (&smtp_data_segment_table);
reassembled_table_init (&smtp_data_reassembled_table);
}
void
proto_register_smtp(void)
{
static hf_register_info hf[] = {
{ &hf_smtp_req,
{ "Request", "smtp.req",
FT_BOOLEAN, BASE_NONE, NULL, 0x0, NULL, HFILL }},
{ &hf_smtp_rsp,
{ "Response", "smtp.rsp",
FT_BOOLEAN, BASE_NONE, NULL, 0x0, NULL, HFILL }},
{ &hf_smtp_message,
{ "Message", "smtp.message",
FT_STRING, BASE_NONE, NULL, 0x0, NULL, HFILL }},
{ &hf_smtp_command_line,
{ "Command Line", "smtp.command_line",
FT_STRING, BASE_NONE, NULL, 0x0, NULL, HFILL }},
{ &hf_smtp_req_command,
{ "Command", "smtp.req.command",
FT_STRING, BASE_NONE, NULL, 0x0, NULL, HFILL }},
{ &hf_smtp_req_parameter,
{ "Request parameter", "smtp.req.parameter",
FT_STRING, BASE_NONE, NULL, 0x0, NULL, HFILL }},
{ &hf_smtp_response,
{ "Response", "smtp.response",
FT_STRING, BASE_NONE, NULL, 0x0, NULL, HFILL }},
{ &hf_smtp_rsp_code,
{ "Response code", "smtp.response.code",
FT_UINT32, BASE_DEC, VALS(response_codes_vs), 0x0, NULL, HFILL }},
{ &hf_smtp_rsp_parameter,
{ "Response parameter", "smtp.rsp.parameter",
FT_STRING, BASE_NONE, NULL, 0x0, NULL, HFILL }},
{ &hf_smtp_data_fragments,
{ "DATA fragments", "smtp.data.fragments",
FT_NONE, BASE_NONE, NULL, 0x00, "Message fragments", HFILL } },
{ &hf_smtp_data_fragment,
{ "DATA fragment", "smtp.data.fragment",
FT_FRAMENUM, BASE_NONE, NULL, 0x00, "Message fragment", HFILL } },
{ &hf_smtp_data_fragment_overlap,
{ "DATA fragment overlap", "smtp.data.fragment.overlap", FT_BOOLEAN,
BASE_NONE, NULL, 0x0, "Message fragment overlap", HFILL } },
{ &hf_smtp_data_fragment_overlap_conflicts,
{ "DATA fragment overlapping with conflicting data",
"smtp.data.fragment.overlap.conflicts", FT_BOOLEAN, BASE_NONE, NULL,
0x0, "Message fragment overlapping with conflicting data", HFILL } },
{ &hf_smtp_data_fragment_multiple_tails,
{ "DATA has multiple tail fragments", "smtp.data.fragment.multiple_tails",
FT_BOOLEAN, BASE_NONE, NULL, 0x0, "Message has multiple tail fragments", HFILL } },
{ &hf_smtp_data_fragment_too_long_fragment,
{ "DATA fragment too long", "smtp.data.fragment.too_long_fragment",
FT_BOOLEAN, BASE_NONE, NULL, 0x0, "Message fragment too long", HFILL } },
{ &hf_smtp_data_fragment_error,
{ "DATA defragmentation error", "smtp.data.fragment.error",
FT_FRAMENUM, BASE_NONE, NULL, 0x00, "Message defragmentation error", HFILL } },
{ &hf_smtp_data_fragment_count,
{ "DATA fragment count", "smtp.data.fragment.count",
FT_UINT32, BASE_DEC, NULL, 0x00, NULL, HFILL } },
{ &hf_smtp_data_reassembled_in,
{ "Reassembled DATA in frame", "smtp.data.reassembled.in",
FT_FRAMENUM, BASE_NONE, NULL, 0x00, "This DATA fragment is reassembled in this frame", HFILL } },
{ &hf_smtp_data_reassembled_length,
{ "Reassembled DATA length", "smtp.data.reassembled.length",
FT_UINT32, BASE_DEC, NULL, 0x00, "The total length of the reassembled payload", HFILL } },
};
static gint *ett[] = {
&ett_smtp,
&ett_smtp_cmdresp,
&ett_smtp_data_fragment,
&ett_smtp_data_fragments,
};
module_t *smtp_module;
proto_smtp = proto_register_protocol("Simple Mail Transfer Protocol",
"SMTP", "smtp");
proto_register_field_array(proto_smtp, hf, array_length(hf));
proto_register_subtree_array(ett, array_length(ett));
register_init_routine (&smtp_data_reassemble_init);
register_dissector("smtp", dissect_smtp, proto_smtp);
smtp_module = prefs_register_protocol(proto_smtp, NULL);
prefs_register_bool_preference(smtp_module, "desegment_lines",
"Reassemble SMTP command and response lines\nspanning multiple TCP segments",
"Whether the SMTP dissector should reassemble command and response lines"
" spanning multiple TCP segments. To use this option, you must also enable "
"\"Allow subdissectors to reassemble TCP streams\" in the TCP protocol settings.",
&smtp_desegment);
prefs_register_bool_preference(smtp_module, "desegment_data",
"Reassemble SMTP DATA commands spanning multiple TCP segments",
"Whether the SMTP dissector should reassemble DATA command and lines"
" spanning multiple TCP segments. To use this option, you must also enable "
"\"Allow subdissectors to reassemble TCP streams\" in the TCP protocol settings.",
&smtp_data_desegment);
}
void
proto_reg_handoff_smtp(void)
{
dissector_handle_t smtp_handle;
smtp_handle = find_dissector("smtp");
dissector_add_uint("tcp.port", TCP_PORT_SMTP, smtp_handle);
ssl_dissector_add(TCP_PORT_SSL_SMTP, "smtp", TRUE);
dissector_add_uint("tcp.port", TCP_PORT_SUBMISSION, smtp_handle);
imf_handle = find_dissector("imf");
ssl_handle = find_dissector("ssl");
}
