static void
dissect_exec(tvbuff_t *tvb, packet_info *pinfo, proto_tree *tree)
{
proto_item *ti;
proto_tree *exec_tree=NULL;
guchar *field_stringz;
gint length;
guint offset = 0;
conversation_t *conversation;
exec_hash_entry_t *hash_info;
conversation = find_or_create_conversation(pinfo);
hash_info = (exec_hash_entry_t *)conversation_get_proto_data(conversation, proto_exec);
if(!hash_info){
hash_info = wmem_new(wmem_file_scope(), exec_hash_entry_t);
hash_info->first_packet_number = pinfo->fd->num;
hash_info->second_packet_number = 0;
hash_info->third_packet_number = 0;
hash_info->fourth_packet_number = 0;
hash_info->state = WAIT_FOR_STDERR_PORT;
hash_info->username=NULL;
hash_info->command=NULL;
hash_info->first_packet_state = NONE;
hash_info->second_packet_state = NONE;
hash_info->third_packet_state = NONE;
hash_info->fourth_packet_state = NONE;
conversation_add_proto_data(conversation, proto_exec, hash_info);
}
if(!hash_info->second_packet_number
&& pinfo->fd->num > hash_info->first_packet_number){
hash_info->second_packet_number = pinfo->fd->num;
} else if(hash_info->second_packet_number
&& !hash_info->third_packet_number
&& pinfo->fd->num > hash_info->second_packet_number) {
hash_info->third_packet_number = pinfo->fd->num;
} else if(hash_info->third_packet_number
&& !hash_info->fourth_packet_number
&& pinfo->fd->num > hash_info->third_packet_number) {
hash_info->fourth_packet_number = pinfo->fd->num;
}
if(pinfo->fd->num == hash_info->first_packet_number){
if(hash_info->first_packet_state == NONE){
hash_info->first_packet_state = hash_info->state;
} else {
hash_info->state = hash_info->first_packet_state;
}
}
if(pinfo->fd->num == hash_info->second_packet_number){
if(hash_info->second_packet_state == NONE){
hash_info->second_packet_state = hash_info->state;
} else {
hash_info->state = hash_info->second_packet_state;
}
}
if(pinfo->fd->num == hash_info->third_packet_number){
if(hash_info->third_packet_state == NONE){
hash_info->third_packet_state = hash_info->state;
} else {
hash_info->state = hash_info->third_packet_state;
}
}
if(pinfo->fd->num == hash_info->fourth_packet_number){
if(hash_info->fourth_packet_state == NONE){
hash_info->fourth_packet_state = hash_info->state;
} else {
hash_info->state = hash_info->fourth_packet_state;
}
}
col_set_str(pinfo->cinfo, COL_PROTOCOL, "EXEC");
col_clear(pinfo->cinfo, COL_INFO);
if(hash_info->username && preference_info_show_username == TRUE){
col_append_fstr(pinfo->cinfo, COL_INFO, "Username:%s ", hash_info->username);
}
if(hash_info->command && preference_info_show_command == TRUE){
col_append_fstr(pinfo->cinfo, COL_INFO, "Command:%s ", hash_info->command);
}
ti = proto_tree_add_item(tree, proto_exec, tvb, 0, -1, ENC_NA);
exec_tree = proto_item_add_subtree(ti, ett_exec);
if(tvb_find_guint8(tvb, tvb_captured_length(tvb)-1, 1, '\0') == -1){
hash_info->state = WAIT_FOR_DATA;
}
if(hash_info->state == WAIT_FOR_STDERR_PORT
&& tvb_reported_length_remaining(tvb, offset)){
field_stringz = tvb_get_stringz_enc(wmem_packet_scope(), tvb, offset, &length, ENC_ASCII);
if(length == 1 || (isdigit_string(field_stringz)
&& length <= EXEC_STDERR_PORT_LEN)){
proto_tree_add_string(exec_tree, hf_exec_stderr_port, tvb, offset, length, (gchar*)field_stringz);
hash_info->state = WAIT_FOR_USERNAME;
} else {
hash_info->state = WAIT_FOR_DATA;
}
offset += length;
}
if(hash_info->state == WAIT_FOR_USERNAME
&& tvb_reported_length_remaining(tvb, offset)){
field_stringz = tvb_get_stringz_enc(wmem_packet_scope(), tvb, offset, &length, ENC_ASCII);
if(length != 1 && length <= EXEC_USERNAME_LEN
&& isprint_string(field_stringz)){
proto_tree_add_string(exec_tree, hf_exec_username, tvb, offset, length, (gchar*)field_stringz);
if(!hash_info->username){
hash_info->username=wmem_strdup(wmem_file_scope(), (gchar*)field_stringz);
}
hash_info->state = WAIT_FOR_PASSWORD;
} else {
hash_info->state = WAIT_FOR_DATA;
}
offset += length;
}
if(hash_info->state == WAIT_FOR_PASSWORD
&& tvb_reported_length_remaining(tvb, offset)){
field_stringz = tvb_get_stringz_enc(wmem_packet_scope(), tvb, offset, &length, ENC_ASCII);
if(length != 1 && length <= EXEC_PASSWORD_LEN
&& isprint_string(field_stringz)){
proto_tree_add_string(exec_tree, hf_exec_password, tvb, offset, length, (gchar*)field_stringz);
hash_info->state = WAIT_FOR_COMMAND;
} else {
hash_info->state = WAIT_FOR_DATA;
}
offset += length;
hash_info->state = WAIT_FOR_COMMAND;
}
if(hash_info->state == WAIT_FOR_COMMAND
&& tvb_reported_length_remaining(tvb, offset)){
field_stringz = tvb_get_stringz_enc(wmem_packet_scope(), tvb, offset, &length, ENC_ASCII);
if(length != 1 && length <= EXEC_COMMAND_LEN
&& isprint_string(field_stringz)){
proto_tree_add_string(exec_tree, hf_exec_command, tvb, offset, length, (gchar*)field_stringz);
if(!hash_info->command){
hash_info->command=wmem_strdup(wmem_file_scope(), (gchar*)field_stringz);
}
} else {
hash_info->state = WAIT_FOR_DATA;
}
}
if(hash_info->state == WAIT_FOR_DATA
&& tvb_reported_length_remaining(tvb, offset)){
if(pinfo->destport == EXEC_PORT){
proto_tree_add_item(exec_tree, hf_exec_client_server_data, tvb, 0, -1, ENC_NA);
col_append_str(pinfo->cinfo, COL_INFO, "Client -> Server data");
} else {
proto_tree_add_item(exec_tree, hf_exec_server_client_data, tvb, 0, -1, ENC_NA);
col_append_str(pinfo->cinfo, COL_INFO, "Server -> Client Data");
}
}
if(hash_info->state < WAIT_FOR_DATA){
col_set_str(pinfo->cinfo, COL_INFO, "Session Establishment");
}
}
void
proto_register_exec(void)
{
static hf_register_info hf[] =
{
{ &hf_exec_stderr_port, { "Stderr port (optional)", "exec.stderr_port",
FT_STRINGZ, BASE_NONE, NULL, 0,
"Client port that is listening for stderr stream from server", HFILL } },
{ &hf_exec_username, { "Client username", "exec.username",
FT_STRINGZ, BASE_NONE, NULL, 0,
"Username client uses to log in to the server.", HFILL } },
{ &hf_exec_password, { "Client password", "exec.password",
FT_STRINGZ, BASE_NONE, NULL, 0,
"Password client uses to log in to the server.", HFILL } },
{ &hf_exec_command, { "Command to execute", "exec.command",
FT_STRINGZ, BASE_NONE, NULL, 0,
"Command client is requesting the server to run.", HFILL } },
{ &hf_exec_client_server_data, { "Client -> Server Data", "exec.client_server_data",
FT_BYTES, BASE_NONE, NULL, 0,
NULL, HFILL } },
{ &hf_exec_server_client_data, { "Server -> Client Data", "exec.server_client_data",
FT_BYTES, BASE_NONE, NULL, 0,
NULL, HFILL } },
};
static gint *ett[] =
{
&ett_exec
};
module_t *exec_module;
proto_exec = proto_register_protocol("Remote Process Execution", "EXEC", "exec");
proto_register_field_array(proto_exec, hf, array_length(hf));
proto_register_subtree_array(ett, array_length(ett));
exec_module = prefs_register_protocol(proto_exec, NULL);
prefs_register_bool_preference(exec_module, "info_show_username",
"Show username in info column",
"Controls the display of the session's username in the info column. This is only displayed if the packet containing it was seen during this capture session.", &preference_info_show_username);
prefs_register_bool_preference(exec_module, "info_show_command",
"Show command in info column",
"Controls the display of the command being run on the server by this session in the info column. This is only displayed if the packet containing it was seen during this capture session.", &preference_info_show_command);
}
void
proto_reg_handoff_exec(void)
{
dissector_handle_t exec_handle;
exec_handle = create_dissector_handle(dissect_exec, proto_exec);
dissector_add_uint("tcp.port", EXEC_PORT, exec_handle);
}
