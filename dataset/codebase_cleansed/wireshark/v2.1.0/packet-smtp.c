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
dissect_ntlm_auth(tvbuff_t *tvb, packet_info *pinfo, proto_tree *tree,
const char *line)
{
tvbuff_t *ntlm_tvb;
ntlm_tvb = base64_to_tvb(tvb, line);
if(tvb_strneql(ntlm_tvb, 0, "NTLMSSP", 7) == 0) {
add_new_data_source(pinfo, ntlm_tvb, "NTLMSSP Data");
call_dissector(ntlmssp_handle, ntlm_tvb, pinfo, tree);
}
}
static void
decode_plain_auth(tvbuff_t *tvb, packet_info *pinfo, proto_tree *tree,
gint a_offset, int a_linelen)
{
gint returncode;
gint length_user1;
gint length_user2;
gint length_pass;
guint8 *decrypt = NULL;
proto_item *ti;
decrypt = tvb_get_string_enc(wmem_packet_scope(), tvb, a_offset, a_linelen, ENC_ASCII);
if (smtp_auth_parameter_decoding_enabled) {
returncode = (gint)ws_base64_decode_inplace(decrypt);
if (returncode) {
length_user1 = (gint)strlen(decrypt);
if (returncode >= (length_user1 + 1)) {
length_user2 = (gint)strlen(decrypt + length_user1 + 1);
proto_tree_add_string(tree, hf_smtp_username, tvb,
a_offset, a_linelen, decrypt + length_user1 + 1);
col_append_fstr(pinfo->cinfo, COL_INFO, "User: %s",
format_text(decrypt + length_user1 + 1, length_user2));
if (returncode >= (length_user1 + 1 + length_user2 + 1)) {
length_pass = (gint)strlen(decrypt + length_user1 + length_user2 + 2);
proto_tree_add_string(tree, hf_smtp_password, tvb,
a_offset, length_pass, decrypt + length_user1 + length_user2 + 2);
col_append_str(pinfo->cinfo, COL_INFO, " ");
col_append_fstr(pinfo->cinfo, COL_INFO, " Pass: %s",
format_text(decrypt + length_user1 + length_user2 + 2, length_pass));
}
}
}
}
else {
ti = proto_tree_add_item(tree, hf_smtp_username_password, tvb,
a_offset, a_linelen, ENC_ASCII|ENC_NA);
expert_add_info(pinfo, ti, &ei_smtp_base64_decode);
col_append_str(pinfo->cinfo, COL_INFO, format_text(decrypt, a_linelen));
}
}
static int
dissect_smtp(tvbuff_t *tvb, packet_info *pinfo, proto_tree *tree, void* data _U_)
{
struct smtp_proto_data *spd_frame_data;
proto_tree *smtp_tree = NULL;
proto_tree *cmdresp_tree = NULL;
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
fragment_head *frag_msg = NULL;
tvbuff_t *next_tvb;
guint8 *decrypt = NULL;
size_t decrypt_len = 0;
guint8 *base64_string = NULL;
guint8 line_code[3];
conversation = find_or_create_conversation(pinfo);
session_state = (struct smtp_session_state *)conversation_get_proto_data(conversation, proto_smtp);
if (!session_state) {
session_state = (struct smtp_session_state *)wmem_alloc0(wmem_file_scope(), sizeof(struct smtp_session_state));
session_state->smtp_state = SMTP_STATE_READING_CMDS;
session_state->auth_state = SMTP_AUTH_STATE_NONE;
session_state->msg_last = TRUE;
conversation_add_proto_data(conversation, proto_smtp, session_state);
}
request = pinfo->destport == pinfo->match_uint;
spd_frame_data = (struct smtp_proto_data *)p_get_proto_data(wmem_file_scope(), pinfo, proto_smtp, 0);
if (!spd_frame_data) {
if (request) {
spd_frame_data = (struct smtp_proto_data *)wmem_alloc0(wmem_file_scope(), sizeof(struct smtp_proto_data));
spd_frame_data->conversation_id = conversation->index;
spd_frame_data->more_frags = TRUE;
p_add_proto_data(wmem_file_scope(), pinfo, proto_smtp, 0, spd_frame_data);
}
loffset = offset;
while (tvb_offset_exists(tvb, loffset)) {
linelen = tvb_find_line_end(tvb, loffset, -1, &next_offset,
smtp_desegment && pinfo->can_desegment);
if (linelen == -1) {
if (offset == loffset) {
pinfo->desegment_offset = loffset;
pinfo->desegment_len = DESEGMENT_ONE_MORE_SEGMENT;
return tvb_captured_length(tvb);
} else {
linelen = tvb_reported_length_remaining(tvb, loffset);
next_offset = loffset + linelen;
}
}
if (session_state->smtp_state == SMTP_STATE_READING_DATA) {
if ((session_state->crlf_seen && tvb_strneql(tvb, loffset, ".\r\n", 3) == 0) ||
tvb_strneql(tvb, loffset, "\r\n.\r\n", 5) == 0)
eom_seen = TRUE;
length_remaining = tvb_captured_length_remaining(tvb, loffset);
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
session_state->msg_read_len += tvb_reported_length_remaining(tvb, loffset);
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
if ((session_state->auth_state != SMTP_AUTH_STATE_NONE) &&
(pinfo->num >= session_state->first_auth_frame) &&
((session_state->last_auth_frame == 0) || (pinfo->num <= session_state->last_auth_frame))) {
decrypt = tvb_get_string_enc(wmem_packet_scope(), tvb, loffset, linelen, ENC_ASCII);
if ((smtp_auth_parameter_decoding_enabled) &&
((decrypt_len = ws_base64_decode_inplace(decrypt)) > 0)) {
line = decrypt;
linelen = (int)decrypt_len;
} else {
line = tvb_get_ptr(tvb, loffset, linelen);
decrypt_len = linelen;
}
} else {
line = tvb_get_ptr(tvb, loffset, linelen);
}
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
msg_len = (guint32)strtoul (line+5, NULL, 10);
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
} else if ((g_ascii_strncasecmp(line, "AUTH LOGIN", 10) == 0) && (linelen <= 11)) {
spd_frame_data->pdu_type = SMTP_PDU_CMD;
session_state->smtp_state = SMTP_STATE_READING_CMDS;
session_state->auth_state = SMTP_AUTH_STATE_START;
session_state->first_auth_frame = pinfo->num;
} else if ((g_ascii_strncasecmp(line, "AUTH LOGIN", 10) == 0) && (linelen > 11)) {
spd_frame_data->pdu_type = SMTP_PDU_CMD;
session_state->smtp_state = SMTP_STATE_READING_CMDS;
session_state->auth_state = SMTP_AUTH_STATE_USERNAME_RSP;
session_state->first_auth_frame = pinfo->num;
session_state->username_cmd_frame = pinfo->num;
} else if ((g_ascii_strncasecmp(line, "AUTH PLAIN", 10) == 0) && (linelen <= 11)) {
spd_frame_data->pdu_type = SMTP_PDU_CMD;
session_state->smtp_state = SMTP_STATE_READING_CMDS;
session_state->auth_state = SMTP_AUTH_STATE_PLAIN_START_REQ;
session_state->first_auth_frame = pinfo->num;
} else if ((g_ascii_strncasecmp(line, "AUTH PLAIN", 10) == 0) && (linelen > 11)) {
spd_frame_data->pdu_type = SMTP_PDU_CMD;
session_state->smtp_state = SMTP_STATE_READING_CMDS;
session_state->auth_state = SMTP_AUTH_STATE_PLAIN_CRED_REQ;
session_state->first_auth_frame = pinfo->num;
session_state->user_pass_cmd_frame = pinfo->num;
} else if ((g_ascii_strncasecmp(line, "AUTH NTLM", 9) == 0) && (linelen > 10)) {
spd_frame_data->pdu_type = SMTP_PDU_CMD;
session_state->smtp_state = SMTP_STATE_READING_CMDS;
session_state->auth_state = SMTP_AUTH_STATE_NTLM_REQ;
session_state->ntlm_req_frame = pinfo->num;
} else if (g_ascii_strncasecmp(line, "STARTTLS", 8) == 0) {
session_state->smtp_state = SMTP_STATE_AWAITING_STARTTLS_RESPONSE;
spd_frame_data->pdu_type = SMTP_PDU_CMD;
} else {
spd_frame_data->pdu_type = SMTP_PDU_CMD;
}
} else if (session_state->auth_state == SMTP_AUTH_STATE_USERNAME_REQ) {
session_state->auth_state = SMTP_AUTH_STATE_USERNAME_RSP;
session_state->username_frame = pinfo->num;
} else if (session_state->auth_state == SMTP_AUTH_STATE_PASSWORD_REQ) {
session_state->auth_state = SMTP_AUTH_STATE_PASSWORD_RSP;
session_state->password_frame = pinfo->num;
} else if (session_state->auth_state == SMTP_AUTH_STATE_PLAIN_REQ) {
session_state->auth_state = SMTP_AUTH_STATE_PLAIN_RSP;
session_state->user_pass_frame = pinfo->num;
} else if (session_state->auth_state == SMTP_AUTH_STATE_NTLM_CHALLANGE) {
session_state->auth_state = SMTP_AUTH_STATE_NTLM_RSP;
session_state->ntlm_rsp_frame = pinfo->num;
}
else {
spd_frame_data->pdu_type = session_state->data_seen ? SMTP_PDU_MESSAGE : SMTP_PDU_CMD;
}
}
}
loffset = next_offset;
}
}
col_set_str(pinfo->cinfo, COL_PROTOCOL, "SMTP");
col_clear(pinfo->cinfo, COL_INFO);
if (tree) {
ti = proto_tree_add_item(tree, proto_smtp, tvb, offset, -1, ENC_NA);
smtp_tree = proto_item_add_subtree(ti, ett_smtp);
}
if (request) {
switch (spd_frame_data->pdu_type) {
case SMTP_PDU_MESSAGE:
length_remaining = tvb_reported_length_remaining(tvb, offset);
col_set_str(pinfo->cinfo, COL_INFO, smtp_data_desegment ? "C: DATA fragment" : "C: Message Body");
col_append_fstr(pinfo->cinfo, COL_INFO, ", %d byte%s", length_remaining,
plurality (length_remaining, "", "s"));
if (smtp_data_desegment) {
frag_msg = fragment_add_seq_next(&smtp_data_reassembly_table, tvb, 0,
pinfo, spd_frame_data->conversation_id, NULL,
tvb_reported_length(tvb),
spd_frame_data->more_frags);
} else {
dissect_smtp_data(tvb, offset, smtp_tree);
}
break;
case SMTP_PDU_EOM:
col_set_str(pinfo->cinfo, COL_INFO, "C: .");
proto_tree_add_none_format(smtp_tree, hf_smtp_eom, tvb, offset, linelen, "C: .");
if (smtp_data_desegment) {
if (loffset)
fragment_add_seq_next(&smtp_data_reassembly_table, tvb, 0,
pinfo, spd_frame_data->conversation_id, NULL,
loffset, spd_frame_data->more_frags);
frag_msg = fragment_end_seq_next(&smtp_data_reassembly_table,
pinfo, spd_frame_data->conversation_id, NULL);
}
break;
case SMTP_PDU_CMD:
loffset = offset;
while (tvb_offset_exists(tvb, loffset)) {
linelen = tvb_find_line_end(tvb, loffset, -1, &next_offset, FALSE);
if (loffset == offset)
col_append_str(pinfo->cinfo, COL_INFO, "C: ");
else
col_append_str(pinfo->cinfo, COL_INFO, " | ");
hidden_item = proto_tree_add_boolean(smtp_tree, hf_smtp_req, tvb,
0, 0, TRUE);
PROTO_ITEM_SET_HIDDEN(hidden_item);
if (session_state->username_frame == pinfo->num) {
if (decrypt == NULL) {
decrypt = tvb_get_string_enc(wmem_packet_scope(), tvb, loffset, linelen, ENC_ASCII);
decrypt_len = linelen;
if (smtp_auth_parameter_decoding_enabled) {
if ((decrypt_len = ws_base64_decode_inplace(decrypt)) == 0) {
decrypt = tvb_get_string_enc(wmem_packet_scope(), tvb, loffset, linelen, ENC_ASCII);
decrypt_len = linelen;
}
}
}
proto_tree_add_string(smtp_tree, hf_smtp_username, tvb,
loffset, linelen, decrypt);
col_append_fstr(pinfo->cinfo, COL_INFO, "User: %s", format_text(decrypt, decrypt_len));
} else if (session_state->password_frame == pinfo->num) {
if (decrypt == NULL) {
decrypt = tvb_get_string_enc(wmem_packet_scope(), tvb, loffset, linelen, ENC_ASCII);
decrypt_len = linelen;
if (smtp_auth_parameter_decoding_enabled) {
if ((decrypt_len = ws_base64_decode_inplace(decrypt)) == 0) {
decrypt = tvb_get_string_enc(wmem_packet_scope(), tvb, loffset, linelen, ENC_ASCII);
decrypt_len = linelen;
}
}
}
proto_tree_add_string(smtp_tree, hf_smtp_password, tvb,
loffset, linelen, decrypt);
col_append_fstr(pinfo->cinfo, COL_INFO, "Pass: %s", format_text(decrypt, decrypt_len));
} else if (session_state->ntlm_rsp_frame == pinfo->num) {
decrypt = tvb_get_string_enc(wmem_packet_scope(), tvb, loffset, linelen, ENC_ASCII);
decrypt_len = linelen;
if (smtp_auth_parameter_decoding_enabled) {
if ((decrypt_len = ws_base64_decode_inplace(decrypt)) == 0) {
decrypt = tvb_get_string_enc(wmem_packet_scope(), tvb, loffset, linelen, ENC_ASCII);
decrypt_len = linelen;
col_append_str(pinfo->cinfo, COL_INFO, format_text(decrypt, linelen));
proto_tree_add_item(smtp_tree, hf_smtp_command_line, tvb,
loffset, linelen, ENC_ASCII|ENC_NA);
}
else {
base64_string = tvb_get_string_enc(wmem_packet_scope(), tvb, loffset, linelen, ENC_ASCII);
dissect_ntlm_auth(tvb, pinfo, smtp_tree, base64_string);
}
}
else {
col_append_str(pinfo->cinfo, COL_INFO, format_text(decrypt, linelen));
proto_tree_add_item(smtp_tree, hf_smtp_command_line, tvb,
loffset, linelen, ENC_ASCII|ENC_NA);
}
} else if (session_state->user_pass_frame == pinfo->num) {
decode_plain_auth(tvb, pinfo, smtp_tree, loffset, linelen);
} else {
if (linelen >= 4)
cmdlen = 4;
else
cmdlen = linelen;
ti = proto_tree_add_item(smtp_tree, hf_smtp_command_line, tvb,
loffset, next_offset - loffset, ENC_ASCII|ENC_NA);
cmdresp_tree = proto_item_add_subtree(ti, ett_smtp_cmdresp);
proto_tree_add_item(cmdresp_tree, hf_smtp_req_command, tvb,
loffset, cmdlen, ENC_ASCII|ENC_NA);
if ((linelen > 5) && (session_state->username_cmd_frame == pinfo->num) ) {
proto_tree_add_item(cmdresp_tree, hf_smtp_req_parameter, tvb,
loffset + 5, linelen - 5, ENC_ASCII|ENC_NA);
if (linelen >= 11) {
if (decrypt == NULL) {
decrypt = tvb_get_string_enc(wmem_packet_scope(), tvb, loffset + 11, linelen - 11, ENC_ASCII);
decrypt_len = linelen - 11;
if (smtp_auth_parameter_decoding_enabled) {
if ((decrypt_len = ws_base64_decode_inplace(decrypt)) == 0) {
decrypt = tvb_get_string_enc(wmem_packet_scope(), tvb, loffset + 11, linelen - 11, ENC_ASCII);
decrypt_len = linelen - 11;
}
}
}
proto_tree_add_string(cmdresp_tree, hf_smtp_username, tvb, loffset + 11, linelen - 11, decrypt);
col_append_str(pinfo->cinfo, COL_INFO,
format_text(tvb_get_string_enc(wmem_packet_scope(), tvb, loffset, 11, ENC_ASCII), 11));
col_append_fstr(pinfo->cinfo, COL_INFO, "User: %s", format_text(decrypt, decrypt_len));
}
}
else if ((linelen > 5) && (session_state->ntlm_req_frame == pinfo->num) ) {
proto_tree_add_item(cmdresp_tree, hf_smtp_req_parameter, tvb,
loffset + 5, linelen - 5, ENC_ASCII|ENC_NA);
if (linelen >= 10) {
decrypt = tvb_get_string_enc(wmem_packet_scope(), tvb, loffset + 10, linelen - 10, ENC_ASCII);
decrypt_len = linelen - 10;
if (smtp_auth_parameter_decoding_enabled) {
if ((decrypt_len = ws_base64_decode_inplace(decrypt)) == 0) {
decrypt = tvb_get_string_enc(wmem_packet_scope(), tvb, loffset + 10, linelen - 10, ENC_ASCII);
decrypt_len = linelen - 10;
col_append_str(pinfo->cinfo, COL_INFO,
format_text(tvb_get_string_enc(wmem_packet_scope(), tvb, loffset, 10, ENC_ASCII), 10));
col_append_str(pinfo->cinfo, COL_INFO, format_text(decrypt, linelen - 10));
}
else {
base64_string = tvb_get_string_enc(wmem_packet_scope(), tvb, loffset + 10, linelen - 10, ENC_ASCII);
col_append_str(pinfo->cinfo, COL_INFO,
format_text(tvb_get_string_enc(wmem_packet_scope(), tvb, loffset, 10, ENC_ASCII), linelen - 10));
dissect_ntlm_auth(tvb, pinfo, cmdresp_tree, format_text(base64_string, linelen - 10));
}
}
else {
col_append_str(pinfo->cinfo, COL_INFO,
format_text(tvb_get_string_enc(wmem_packet_scope(), tvb, loffset, 10, ENC_ASCII), 10));
col_append_str(pinfo->cinfo, COL_INFO, format_text(decrypt, linelen - 10));
}
}
}
else if ((linelen > 5) && (session_state->user_pass_cmd_frame == pinfo->num) ) {
proto_tree_add_item(cmdresp_tree, hf_smtp_req_parameter, tvb,
loffset + 5, linelen - 5, ENC_ASCII|ENC_NA);
col_append_str(pinfo->cinfo, COL_INFO,
format_text(tvb_get_string_enc(wmem_packet_scope(), tvb, loffset, 11, ENC_ASCII), 11));
decode_plain_auth(tvb, pinfo, cmdresp_tree, loffset + 11, linelen - 11);
}
else if (linelen > 5) {
proto_tree_add_item(cmdresp_tree, hf_smtp_req_parameter, tvb,
loffset + 5, linelen - 5, ENC_ASCII|ENC_NA);
col_append_str(pinfo->cinfo, COL_INFO,
format_text(tvb_get_string_enc(wmem_packet_scope(), tvb, loffset, linelen, ENC_ASCII), linelen));
}
else {
col_append_str(pinfo->cinfo, COL_INFO,
format_text(tvb_get_string_enc(wmem_packet_scope(), tvb, loffset, linelen, ENC_ASCII), linelen));
}
if (smtp_data_desegment && !spd_frame_data->more_frags) {
frag_msg = fragment_end_seq_next(&smtp_data_reassembly_table,
pinfo, spd_frame_data->conversation_id, NULL);
}
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
loffset = offset;
while (tvb_offset_exists(tvb, offset)) {
linelen = tvb_find_line_end(tvb, offset, -1, &next_offset, FALSE);
if (loffset == offset)
col_append_str(pinfo->cinfo, COL_INFO, "S: ");
else
col_append_str(pinfo->cinfo, COL_INFO, " | ");
if (tree) {
ti = proto_tree_add_item(smtp_tree, hf_smtp_response, tvb,
offset, next_offset - offset, ENC_ASCII|ENC_NA);
cmdresp_tree = proto_item_add_subtree(ti, ett_smtp_cmdresp);
} else
cmdresp_tree = NULL;
if (linelen >= 3) {
line_code[0] = tvb_get_guint8(tvb, offset);
line_code[1] = tvb_get_guint8(tvb, offset+1);
line_code[2] = tvb_get_guint8(tvb, offset+2);
if (g_ascii_isdigit(line_code[0]) && g_ascii_isdigit(line_code[1])
&& g_ascii_isdigit(line_code[2])) {
code = (line_code[0] - '0')*100 + (line_code[1] - '0')*10 + (line_code[2] - '0');
if (session_state->smtp_state == SMTP_STATE_AWAITING_STARTTLS_RESPONSE) {
if (code == 220) {
ssl_starttls_ack(ssl_handle, pinfo, smtp_handle);
}
session_state->smtp_state = SMTP_STATE_READING_CMDS;
}
if (code == 334) {
switch(session_state->auth_state)
{
case SMTP_AUTH_STATE_START:
session_state->auth_state = SMTP_AUTH_STATE_USERNAME_REQ;
break;
case SMTP_AUTH_STATE_USERNAME_RSP:
session_state->auth_state = SMTP_AUTH_STATE_PASSWORD_REQ;
break;
case SMTP_AUTH_STATE_PLAIN_REQ:
session_state->auth_state = SMTP_AUTH_STATE_PLAIN_RSP;
break;
case SMTP_AUTH_STATE_PLAIN_START_REQ:
session_state->auth_state = SMTP_AUTH_STATE_PLAIN_REQ;
break;
case SMTP_AUTH_STATE_NTLM_REQ:
session_state->auth_state = SMTP_AUTH_STATE_NTLM_CHALLANGE;
break;
case SMTP_AUTH_STATE_NONE:
case SMTP_AUTH_STATE_USERNAME_REQ:
case SMTP_AUTH_STATE_PASSWORD_REQ:
case SMTP_AUTH_STATE_PASSWORD_RSP:
case SMTP_AUTH_STATE_PLAIN_RSP:
case SMTP_AUTH_STATE_PLAIN_CRED_REQ:
case SMTP_AUTH_STATE_NTLM_RSP:
case SMTP_AUTH_STATE_NTLM_CHALLANGE:
case SMTP_AUTH_STATE_SUCCESS:
case SMTP_AUTH_STATE_FAILED:
break;
}
} else if ((session_state->auth_state == SMTP_AUTH_STATE_PASSWORD_RSP) ||
( session_state->auth_state == SMTP_AUTH_STATE_PLAIN_RSP) ||
( session_state->auth_state == SMTP_AUTH_STATE_NTLM_RSP) ||
( session_state->auth_state == SMTP_AUTH_STATE_PLAIN_CRED_REQ) ) {
if (code == 235) {
session_state->auth_state = SMTP_AUTH_STATE_SUCCESS;
} else {
session_state->auth_state = SMTP_AUTH_STATE_FAILED;
}
session_state->last_auth_frame = pinfo->num;
}
proto_tree_add_uint(cmdresp_tree, hf_smtp_rsp_code, tvb, offset, 3,
code);
decrypt = NULL;
if (linelen >= 4) {
if ((smtp_auth_parameter_decoding_enabled) && (code == 334)) {
decrypt = tvb_get_string_enc(wmem_packet_scope(), tvb, offset + 4, linelen - 4, ENC_ASCII);
if ((decrypt_len = ws_base64_decode_inplace(decrypt)) > 0) {
if (g_ascii_strncasecmp(decrypt, "NTLMSSP", 7) == 0) {
base64_string = tvb_get_string_enc(wmem_packet_scope(), tvb, loffset + 4, linelen - 4, ENC_ASCII);
col_append_fstr(pinfo->cinfo, COL_INFO, "%d ", code);
proto_tree_add_string(cmdresp_tree, hf_smtp_rsp_parameter, tvb,
offset + 4, linelen - 4, (const char*)base64_string);
dissect_ntlm_auth(tvb, pinfo, cmdresp_tree, base64_string);
}
else {
proto_tree_add_string(cmdresp_tree, hf_smtp_rsp_parameter, tvb,
offset + 4, linelen - 4, (const char*)decrypt);
col_append_fstr(pinfo->cinfo, COL_INFO, "%d %s", code, format_text(decrypt, decrypt_len));
}
} else {
decrypt = NULL;
}
}
if (decrypt == NULL) {
proto_tree_add_item(cmdresp_tree, hf_smtp_rsp_parameter, tvb,
offset + 4, linelen - 4, ENC_ASCII|ENC_NA);
col_append_fstr(pinfo->cinfo, COL_INFO, "%d %s", code,
format_text(tvb_get_string_enc(wmem_packet_scope(), tvb, offset + 4, linelen - 4, ENC_ASCII), linelen - 4));
}
} else {
col_append_str(pinfo->cinfo, COL_INFO,
format_text(tvb_get_string_enc(wmem_packet_scope(), tvb, offset, linelen, ENC_ASCII), linelen));
}
}
}
offset = next_offset;
}
}
return tvb_captured_length(tvb);
}
static void
smtp_data_reassemble_init (void)
{
reassembly_table_init(&smtp_data_reassembly_table,
&addresses_ports_reassembly_table_functions);
}
static void
smtp_data_reassemble_cleanup (void)
{
reassembly_table_destroy(&smtp_data_reassembly_table);
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
FT_UINT32, BASE_DEC|BASE_EXT_STRING, &response_codes_vs_ext, 0x0, NULL, HFILL }},
{ &hf_smtp_rsp_parameter,
{ "Response parameter", "smtp.rsp.parameter",
FT_STRING, BASE_NONE, NULL, 0x0, NULL, HFILL }},
{ &hf_smtp_username,
{ "Username", "smtp.auth.username",
FT_STRING, BASE_NONE, NULL, 0x0, NULL, HFILL }},
{ &hf_smtp_password,
{ "Password", "smtp.auth.password",
FT_STRING, BASE_NONE, NULL, 0x0, NULL, HFILL }},
{ &hf_smtp_username_password,
{ "Username/Password", "smtp.auth.username_password",
FT_STRING, BASE_NONE, NULL, 0x0, NULL, HFILL }},
{ &hf_smtp_eom,
{ "EOM", "smtp.eom",
FT_NONE, BASE_NONE, NULL, 0x00, NULL, HFILL } },
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
static ei_register_info ei[] = {
{ &ei_smtp_base64_decode, { "smtp.base64_decode", PI_PROTOCOL, PI_WARN, "base64 decode failed or is not enabled (check SMTP preferences)", EXPFILL }},
};
module_t *smtp_module;
expert_module_t* expert_smtp;
proto_smtp = proto_register_protocol("Simple Mail Transfer Protocol",
"SMTP", "smtp");
proto_register_field_array(proto_smtp, hf, array_length(hf));
proto_register_subtree_array(ett, array_length(ett));
expert_smtp = expert_register_protocol(proto_smtp);
expert_register_field_array(expert_smtp, ei, array_length(ei));
register_init_routine (&smtp_data_reassemble_init);
register_cleanup_routine (&smtp_data_reassemble_cleanup);
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
prefs_register_bool_preference(smtp_module, "decryption",
"Decode base-64-encoded AUTH parameters",
"Whether the SMTP dissector should decode base-64-encoded AUTH parameters",
&smtp_auth_parameter_decoding_enabled);
}
void
proto_reg_handoff_smtp(void)
{
smtp_handle = find_dissector("smtp");
dissector_add_uint("tcp.port", TCP_PORT_SMTP, smtp_handle);
ssl_dissector_add(TCP_PORT_SSL_SMTP, smtp_handle);
dissector_add_uint("tcp.port", TCP_PORT_SUBMISSION, smtp_handle);
imf_handle = find_dissector_add_dependency("imf", proto_smtp);
ssl_handle = find_dissector_add_dependency("ssl", proto_smtp);
ntlmssp_handle = find_dissector_add_dependency("ntlmssp", proto_smtp);
}
