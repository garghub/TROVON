static void
dissect_rsh(tvbuff_t *tvb, packet_info *pinfo, proto_tree *tree)
{
proto_item *ti;
proto_tree *rsh_tree=NULL;
guchar *field_stringz;
gint length;
guint offset = 0;
conversation_t *conversation;
rsh_hash_entry_t *hash_info;
conversation = find_or_create_conversation(pinfo);
hash_info = (rsh_hash_entry_t *)conversation_get_proto_data(conversation, proto_rsh);
if(!hash_info){
hash_info = se_new(rsh_hash_entry_t);
hash_info->first_packet_number = pinfo->fd->num;
hash_info->second_packet_number = 0;
hash_info->third_packet_number = 0;
hash_info->fourth_packet_number = 0;
hash_info->state = WAIT_FOR_STDERR_PORT;
hash_info->client_username=NULL;
hash_info->server_username=NULL;
hash_info->command=NULL;
hash_info->first_packet_state = NONE;
hash_info->second_packet_state = NONE;
hash_info->third_packet_state = NONE;
hash_info->fourth_packet_state = NONE;
conversation_add_proto_data(conversation, proto_rsh, hash_info);
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
col_set_str(pinfo->cinfo, COL_PROTOCOL, "RSH");
if(check_col(pinfo->cinfo, COL_INFO)){
col_clear(pinfo->cinfo, COL_INFO);
if(hash_info->client_username && preference_info_show_client_username == TRUE){
col_append_fstr(pinfo->cinfo, COL_INFO, "Client username:%s ", hash_info->client_username);
}
if(hash_info->server_username && preference_info_show_server_username == TRUE){
col_append_fstr(pinfo->cinfo, COL_INFO, "Server username:%s ", hash_info->server_username);
}
if(hash_info->command && preference_info_show_command == TRUE){
col_append_fstr(pinfo->cinfo, COL_INFO, "Command:%s ", hash_info->command);
}
}
ti = proto_tree_add_item(tree, proto_rsh, tvb, 0, -1, ENC_NA);
rsh_tree = proto_item_add_subtree(ti, ett_rsh);
if(tvb_find_guint8(tvb, tvb_length(tvb)-1, 1, '\0') == -1){
hash_info->state = WAIT_FOR_DATA;
}
if(hash_info->state == WAIT_FOR_STDERR_PORT
&& tvb_length_remaining(tvb, offset)){
field_stringz = tvb_get_ephemeral_stringz(tvb, offset, &length);
if(length == 1 || (isdigit_string(field_stringz)
&& length <= RSH_STDERR_PORT_LEN)){
proto_tree_add_string(rsh_tree, hf_rsh_stderr_port, tvb, offset, length, (gchar*)field_stringz);
hash_info->state = WAIT_FOR_CLIENT_USERNAME;
} else {
hash_info->state = WAIT_FOR_DATA;
}
offset += length;
}
if(hash_info->state == WAIT_FOR_CLIENT_USERNAME
&& tvb_length_remaining(tvb, offset)){
field_stringz = tvb_get_ephemeral_stringz(tvb, offset, &length);
if(length != 1 && length <= RSH_CLIENT_USERNAME_LEN
&& isprint_string(field_stringz)){
proto_tree_add_string(rsh_tree, hf_rsh_client_username, tvb, offset, length, (gchar*)field_stringz);
if(!hash_info->client_username){
hash_info->client_username=se_strdup((gchar*)field_stringz);
}
hash_info->state = WAIT_FOR_SERVER_USERNAME;
} else {
hash_info->state = WAIT_FOR_DATA;
}
offset += length;
}
if(hash_info->state == WAIT_FOR_SERVER_USERNAME
&& tvb_length_remaining(tvb, offset)){
field_stringz = tvb_get_ephemeral_stringz(tvb, offset, &length);
if(length != 1 && length <= RSH_SERVER_USERNAME_LEN
&& isprint_string(field_stringz)){
proto_tree_add_string(rsh_tree, hf_rsh_server_username, tvb, offset, length, (gchar*)field_stringz);
if(!hash_info->server_username){
hash_info->server_username=se_strdup((gchar*)field_stringz);
}
hash_info->state = WAIT_FOR_COMMAND;
} else {
hash_info->state = WAIT_FOR_DATA;
}
offset += length;
hash_info->state = WAIT_FOR_COMMAND;
}
if(hash_info->state == WAIT_FOR_COMMAND
&& tvb_length_remaining(tvb, offset)){
field_stringz = tvb_get_ephemeral_stringz(tvb, offset, &length);
if(length != 1 && length <= RSH_COMMAND_LEN
&& isprint_string(field_stringz)){
proto_tree_add_string(rsh_tree, hf_rsh_command, tvb, offset, length, (gchar*)field_stringz);
if(!hash_info->command){
hash_info->command=se_strdup((gchar*)field_stringz);
}
} else {
hash_info->state = WAIT_FOR_DATA;
}
}
if(hash_info->state == WAIT_FOR_DATA
&& tvb_length_remaining(tvb, offset)){
if(pinfo->destport == RSH_PORT){
proto_tree_add_text(rsh_tree, tvb, 0, -1, "Client -> Server Data");
col_append_str(pinfo->cinfo, COL_INFO, "Client -> Server data");
} else {
proto_tree_add_text(rsh_tree, tvb, 0, -1, "Server -> Client Data");
col_append_str(pinfo->cinfo, COL_INFO, "Server -> Client Data");
}
}
if(hash_info->state < WAIT_FOR_DATA){
col_set_str(pinfo->cinfo, COL_INFO, "Session Establishment");
}
}
void
proto_register_rsh(void)
{
static hf_register_info hf[] =
{
{ &hf_rsh_stderr_port, { "Stderr port (optional)", "rsh.stderr_port",
FT_STRINGZ, BASE_NONE, NULL, 0,
"Client port that is listening for stderr stream from server", HFILL } },
{ &hf_rsh_client_username, { "Client username", "rsh.client_username",
FT_STRINGZ, BASE_NONE, NULL, 0,
"User's identity on the client machine", HFILL } },
{ &hf_rsh_server_username, { "Server username", "rsh.server_username",
FT_STRINGZ, BASE_NONE, NULL, 0,
"User's identity on the server machine", HFILL } },
{ &hf_rsh_command, { "Command to execute", "rsh.command",
FT_STRINGZ, BASE_NONE, NULL, 0,
"Command client is requesting the server to run", HFILL } }
};
static gint *ett[] =
{
&ett_rsh
};
module_t *rsh_module;
proto_rsh = proto_register_protocol("Remote Shell", "RSH", "rsh");
proto_register_field_array(proto_rsh, hf, array_length(hf));
proto_register_subtree_array(ett, array_length(ett));
rsh_module = prefs_register_protocol(proto_rsh, NULL);
prefs_register_bool_preference(rsh_module, "info_show_client_username",
"Show client username in info column",
"Controls the display of the session's client username in the info column. This is only displayed if the packet containing it was seen during this capture session.", &preference_info_show_client_username);
prefs_register_bool_preference(rsh_module, "info_show_server_username",
"Show server username in info column",
"Controls the display of the session's server username in the info column. This is only displayed if the packet containing it was seen during this capture session.", &preference_info_show_server_username);
prefs_register_bool_preference(rsh_module, "info_show_command",
"Show command in info column",
"Controls the display of the command being run on the server by this session in the info column. This is only displayed if the packet containing it was seen during this capture session.", &preference_info_show_command);
}
void
proto_reg_handoff_rsh(void)
{
dissector_handle_t rsh_handle;
rsh_handle = create_dissector_handle(dissect_rsh, proto_rsh);
dissector_add_uint("tcp.port", RSH_PORT, rsh_handle);
}
