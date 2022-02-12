static void
dissect_imap(tvbuff_t *tvb, packet_info *pinfo, proto_tree *tree)
{
gboolean is_request;
proto_tree *imap_tree, *reqresp_tree;
proto_item *ti, *hidden_item;
gint offset = 0;
gint uid_offset = 0;
gint folder_offset = 0;
const guchar *line;
const guchar *uid_line;
const guchar *folder_line;
gint next_offset;
int linelen;
int tokenlen;
int uid_tokenlen;
int folder_tokenlen;
const guchar *next_token;
const guchar *uid_next_token;
const guchar *folder_next_token;
guchar *tokenbuf;
guchar *command_token;
int iter;
int commandlen;
conversation_t *conversation;
imap_state_t *session_state;
conversation = find_or_create_conversation(pinfo);
session_state = (imap_state_t *)conversation_get_proto_data(conversation, proto_imap);
if (!session_state) {
session_state = wmem_new0(wmem_file_scope(), imap_state_t);
session_state->ssl_requested = FALSE;
conversation_add_proto_data(conversation, proto_imap, session_state);
}
tokenbuf = (guchar *)wmem_alloc0(wmem_packet_scope(), MAX_BUFFER);
command_token = (guchar *)wmem_alloc0(wmem_packet_scope(), MAX_BUFFER);
commandlen = 0;
folder_offset = 0;
folder_tokenlen = 0;
folder_line = NULL;
col_set_str(pinfo->cinfo, COL_PROTOCOL, "IMAP");
if (pinfo->match_uint == pinfo->destport)
is_request = TRUE;
else
is_request = FALSE;
linelen = tvb_find_line_end(tvb, offset, -1, &next_offset, FALSE);
line = tvb_get_ptr(tvb, offset, linelen);
col_add_fstr(pinfo->cinfo, COL_INFO, "%s: %s", is_request ? "Request" : "Response", format_text(line, linelen));
{
ti = proto_tree_add_item(tree, proto_imap, tvb, offset, -1, ENC_NA);
imap_tree = proto_item_add_subtree(ti, ett_imap);
hidden_item = proto_tree_add_boolean(imap_tree, hf_imap_isrequest, tvb, 0, 0, is_request);
PROTO_ITEM_SET_HIDDEN(hidden_item);
while(tvb_offset_exists(tvb, offset)) {
linelen = tvb_find_line_end(tvb, offset, -1, &next_offset, FALSE);
line = tvb_get_ptr(tvb, offset, linelen);
ti = proto_tree_add_item(imap_tree, hf_imap_line, tvb, offset, next_offset - offset, ENC_ASCII|ENC_NA);
reqresp_tree = proto_item_add_subtree(ti, ett_imap_reqresp);
if ( (line) && ((line[0] != '*') || (TRUE == is_request)) ) {
tokenlen = get_token_len(line, line + linelen, &next_token);
if (tokenlen != 0) {
proto_tree_add_item(reqresp_tree, (is_request) ? hf_imap_request_tag : hf_imap_response_tag, tvb, offset, tokenlen, ENC_ASCII|ENC_NA);
offset += (gint) (next_token - line);
linelen -= (int) (next_token - line);
line = next_token;
}
tokenlen = get_token_len(line, line + linelen, &next_token);
if (tokenlen != 0) {
for (iter = 0; iter < tokenlen && iter < MAX_BUFFER-1; iter++) {
tokenbuf[iter] = g_ascii_tolower(line[iter]);
}
if (tree && is_request && strncmp(tokenbuf, "uid", tokenlen) == 0) {
proto_tree_add_item(reqresp_tree, hf_imap_request_uid, tvb, offset, tokenlen, ENC_ASCII|ENC_NA);
uid_offset = offset;
uid_offset += (gint) (next_token - line);
uid_line = next_token;
uid_tokenlen = get_token_len(uid_line, uid_line + (linelen - tokenlen), &uid_next_token);
if (tokenlen != 0) {
proto_tree_add_item(reqresp_tree, hf_imap_request_command, tvb, uid_offset, uid_tokenlen, ENC_ASCII|ENC_NA);
for (iter = 0; iter < uid_tokenlen && iter < MAX_BUFFER-1; iter++) {
command_token[iter] = g_ascii_tolower(uid_line[iter]);
}
commandlen = uid_tokenlen;
folder_offset = uid_offset;
folder_offset += (gint) (uid_next_token - uid_line);
folder_line = uid_next_token;
folder_tokenlen = get_token_len(folder_line, folder_line + (linelen - tokenlen - uid_tokenlen), &folder_next_token);
}
} else {
proto_tree_add_item(reqresp_tree, (is_request) ? hf_imap_request_command : hf_imap_response_status, tvb, offset, tokenlen, ENC_ASCII|ENC_NA);
if (is_request) {
for (iter = 0; iter < tokenlen && iter < 256; iter++) {
command_token[iter] = g_ascii_tolower(line[iter]);
}
commandlen = tokenlen;
folder_offset = offset;
folder_offset += (gint) (next_token - line);
folder_line = next_token;
folder_tokenlen = get_token_len(folder_line, folder_line + (linelen - tokenlen - 1), &folder_next_token);
}
}
if (tree && commandlen > 0 && (
strncmp(command_token, "select", commandlen) == 0 ||
strncmp(command_token, "examine", commandlen) == 0 ||
strncmp(command_token, "create", commandlen) == 0 ||
strncmp(command_token, "delete", commandlen) == 0 ||
strncmp(command_token, "rename", commandlen) == 0 ||
strncmp(command_token, "subscribe", commandlen) == 0 ||
strncmp(command_token, "unsubscribe", commandlen) == 0 ||
strncmp(command_token, "status", commandlen) == 0 ||
strncmp(command_token, "append", commandlen) == 0 ||
strncmp(command_token, "search", commandlen) == 0)) {
if (folder_tokenlen != 0)
proto_tree_add_item(reqresp_tree, hf_imap_request_folder, tvb, folder_offset, folder_tokenlen, ENC_ASCII|ENC_NA);
}
if (tree && is_request && (NULL != folder_line) && strncmp(command_token, "copy", commandlen) == 0) {
folder_offset += (gint) (folder_next_token - folder_line);
folder_line = folder_next_token;
folder_tokenlen = get_token_len(folder_line, folder_line + (linelen - tokenlen), &folder_next_token);
if (folder_tokenlen != 0)
proto_tree_add_item(reqresp_tree, hf_imap_request_folder, tvb, folder_offset, folder_tokenlen, ENC_ASCII|ENC_NA);
}
if (session_state->ssl_requested) {
if (!is_request && session_state->ssl_requested &&
strncmp(tokenbuf, "ok", tokenlen) == 0) {
ssl_starttls_ack(ssl_handle, pinfo, imap_handle);
}
session_state->ssl_requested = FALSE;
}
if (is_request && commandlen > 0 &&
strncmp(command_token, "starttls", commandlen) == 0) {
session_state->ssl_requested = TRUE;
}
}
if (linelen != 0) {
proto_tree_add_item(reqresp_tree, (is_request) ? hf_imap_request : hf_imap_response, tvb, offset, linelen, ENC_ASCII|ENC_NA);
}
}
offset = next_offset;
}
}
}
void
proto_register_imap(void)
{
static hf_register_info hf[] = {
{ &hf_imap_isrequest,
{ "Request", "imap.isrequest",
FT_BOOLEAN, BASE_NONE, NULL, 0x0,
"TRUE if IMAP request, FALSE otherwise", HFILL }
},
{ &hf_imap_line,
{ "Line", "imap.line",
FT_STRINGZ, BASE_NONE, NULL, 0x0,
"A line of an IMAP message", HFILL }
},
{ &hf_imap_request,
{ "Request", "imap.request",
FT_STRINGZ, BASE_NONE, NULL, 0x0,
"Remainder of request line", HFILL }
},
{ &hf_imap_request_tag,
{ "Request Tag", "imap.request_tag",
FT_STRINGZ, BASE_NONE, NULL, 0x0,
"First token of request line", HFILL }
},
{ &hf_imap_response,
{ "Response", "imap.response",
FT_STRINGZ, BASE_NONE, NULL, 0x0,
"Remainder of response line", HFILL }
},
{ &hf_imap_response_tag,
{ "Response Tag", "imap.response_tag",
FT_STRINGZ, BASE_NONE, NULL, 0x0,
"First token of response line", HFILL }
},
{ &hf_imap_request_command,
{ "Request Command", "imap.request.command",
FT_STRINGZ, BASE_NONE, NULL, 0x0,
"Request command name", HFILL }
},
{ &hf_imap_response_status,
{ "Response Status", "imap.response.status",
FT_STRINGZ, BASE_NONE, NULL, 0x0,
"Response status code", HFILL }
},
{ &hf_imap_request_folder,
{ "Request Folder", "imap.request.folder",
FT_STRINGZ, BASE_NONE, NULL, 0x0,
"Request command folder", HFILL }
},
{ &hf_imap_request_uid,
{ "Request isUID", "imap.request.command.uid",
FT_BOOLEAN, BASE_NONE, NULL, 0x0,
"Request command uid", HFILL }
}
};
static gint *ett[] = {
&ett_imap,
&ett_imap_reqresp,
};
proto_imap = proto_register_protocol("Internet Message Access Protocol", "IMAP", "imap");
imap_handle = register_dissector("imap", dissect_imap, proto_imap);
proto_register_field_array(proto_imap, hf, array_length(hf));
proto_register_subtree_array(ett, array_length(ett));
}
void
proto_reg_handoff_imap(void)
{
dissector_add_uint("tcp.port", TCP_PORT_IMAP, imap_handle);
ssl_dissector_add(TCP_PORT_SSL_IMAP, "imap", TRUE);
ssl_handle = find_dissector("ssl");
}
