static void
dissect_rsync_version_header(tvbuff_t *tvb, packet_info *pinfo, proto_tree *rsync_tree, enum rsync_who me)
{
int offset = 0;
guint8 *version;
guint len;
proto_tree_add_item(rsync_tree, &hfi_rsync_hdr_magic, tvb, offset, RSYNCD_MAGIC_HEADER_LEN, ENC_ASCII|ENC_NA);
offset += RSYNCD_MAGIC_HEADER_LEN;
offset += 1;
proto_tree_add_item(rsync_tree, &hfi_rsync_hdr_version, tvb, offset, -1, ENC_ASCII|ENC_NA);
len = tvb_reported_length_remaining(tvb, offset);
version = tvb_get_string_enc(wmem_packet_scope(), tvb, offset, len, ENC_ASCII|ENC_NA);
if (len > 0 && version[len - 1] == '\n')
version[len - 1] = 0x0;
col_add_fstr(pinfo->cinfo, COL_INFO, "%s Initialisation (Version %s)", (me == SERVER ? "Server" : "Client"), version);
}
static int
dissect_rsync_encap(tvbuff_t *tvb, packet_info *pinfo, proto_tree *tree,
gboolean desegment _U_)
{
conversation_t *conversation;
struct rsync_conversation_data *conversation_data;
struct rsync_frame_data *rsync_frame_data_p;
proto_item *ti;
proto_tree *rsync_tree;
enum rsync_who me;
int offset = 0;
guint buff_length;
col_set_str(pinfo->cinfo, COL_PROTOCOL, "RSYNC");
col_clear(pinfo->cinfo, COL_INFO);
me = pinfo->srcport == glb_rsync_tcp_port ? SERVER : CLIENT;
conversation = find_or_create_conversation(pinfo);
conversation_data = (struct rsync_conversation_data *)conversation_get_proto_data(conversation, hfi_rsync->id);
if (conversation_data == NULL) {
conversation_data = wmem_new(wmem_file_scope(), struct rsync_conversation_data);
conversation_data->client_state = RSYNC_INIT;
conversation_data->server_state = RSYNC_SERV_INIT;
conversation_add_proto_data(conversation, hfi_rsync->id, conversation_data);
}
conversation_set_dissector(conversation, rsync_handle);
ti = proto_tree_add_item(tree, hfi_rsync, tvb, 0, -1, ENC_NA);
rsync_tree = proto_item_add_subtree(ti, ett_rsync);
rsync_frame_data_p = (struct rsync_frame_data *)p_get_proto_data(wmem_file_scope(), pinfo, hfi_rsync->id, 0);
if (!rsync_frame_data_p) {
rsync_frame_data_p = wmem_new(wmem_file_scope(), struct rsync_frame_data);
rsync_frame_data_p->state = (me == SERVER) ? conversation_data->server_state : conversation_data->client_state;
p_add_proto_data(wmem_file_scope(), pinfo, hfi_rsync->id, 0, rsync_frame_data_p);
}
if (me == SERVER) {
switch (rsync_frame_data_p->state) {
case RSYNC_SERV_INIT:
dissect_rsync_version_header(tvb, pinfo, rsync_tree, me);
conversation_data->server_state = RSYNC_SERV_MOTD;
break;
case RSYNC_SERV_MOTD:
proto_tree_add_item(rsync_tree, &hfi_rsync_motd_string, tvb, offset, -1, ENC_ASCII|ENC_NA);
col_set_str(pinfo->cinfo, COL_INFO, "Server MOTD");
conversation_data->server_state = RSYNC_SERV_MOTD;
break;
case RSYNC_MODULE_LIST:
if (0 == tvb_strneql(tvb, offset, RSYNCD_AUTHREQD, RSYNCD_AUTHREQD_LEN)) {
proto_tree_add_item(rsync_tree, &hfi_rsync_rsyncdok_string, tvb, offset, -1, ENC_ASCII|ENC_NA);
col_set_str(pinfo->cinfo, COL_INFO, "Authentication");
conversation_data->server_state = RSYNC_DATA;
} else {
proto_tree_add_item(rsync_tree, &hfi_rsync_module_list_string, tvb, offset, -1, ENC_ASCII|ENC_NA);
buff_length = tvb_captured_length_remaining(tvb, offset);
if (buff_length > RSYNCD_EXIT_LEN &&
0 == tvb_strneql(tvb, buff_length-RSYNCD_EXIT_LEN-1, RSYNCD_EXIT, RSYNCD_EXIT_LEN)) {
col_set_str(pinfo->cinfo, COL_INFO, "Final module list");
conversation_data->server_state = RSYNC_DATA;
} else {
col_set_str(pinfo->cinfo, COL_INFO, "Module list");
conversation_data->server_state = RSYNC_MODULE_LIST;
}
}
break;
case RSYNC_DATA:
proto_tree_add_item(rsync_tree, &hfi_rsync_data, tvb, offset, -1, ENC_NA);
col_set_str(pinfo->cinfo, COL_INFO, "Data");
conversation_data->server_state = RSYNC_DATA;
break;
default:
break;
}
} else {
switch (rsync_frame_data_p->state) {
case RSYNC_INIT:
dissect_rsync_version_header(tvb, pinfo, rsync_tree, me);
conversation_data->client_state = RSYNC_CLIENT_QUERY;
break;
case RSYNC_CLIENT_QUERY:
proto_tree_add_item(rsync_tree, &hfi_rsync_query_string, tvb, offset, -1, ENC_ASCII|ENC_NA);
col_set_str(pinfo->cinfo, COL_INFO, "Client Query");
conversation_data->client_state = RSYNC_COMMAND;
if (tvb_captured_length(tvb) == RSYNC_MODULE_LIST_QUERY_LEN &&
0 == tvb_strneql(tvb, offset, RSYNC_MODULE_LIST_QUERY, RSYNC_MODULE_LIST_QUERY_LEN)) {
conversation_data->server_state = RSYNC_MODULE_LIST;
} else {
conversation_data->server_state = RSYNC_DATA;
}
break;
case RSYNC_COMMAND:
proto_tree_add_item(rsync_tree, &hfi_rsync_command_string, tvb, offset, -1, ENC_ASCII|ENC_NA);
col_set_str(pinfo->cinfo, COL_INFO, "Client Command");
conversation_data->client_state = RSYNC_COMMAND;
break;
case RSYNC_DATA:
proto_tree_add_item(rsync_tree, &hfi_rsync_data, tvb, offset, -1, ENC_NA);
col_set_str(pinfo->cinfo, COL_INFO, "Data");
conversation_data->client_state = RSYNC_DATA;
break;
default:
break;
}
}
return tvb_captured_length(tvb);
}
static int
dissect_rsync(tvbuff_t *tvb, packet_info *pinfo, proto_tree *tree, void *data _U_)
{
return dissect_rsync_encap(tvb, pinfo, tree, rsync_desegment);
}
void
proto_register_rsync(void)
{
#ifndef HAVE_HFI_SECTION_INIT
static header_field_info *hfi[] = {
&hfi_rsync_hdr_magic,
&hfi_rsync_hdr_version,
&hfi_rsync_query_string,
&hfi_rsync_module_list_string,
&hfi_rsync_motd_string,
&hfi_rsync_rsyncdok_string,
&hfi_rsync_command_string,
&hfi_rsync_data,
};
#endif
static gint *ett[] = {
&ett_rsync,
};
module_t *rsync_module;
int proto_rsync;
proto_rsync = proto_register_protocol("RSYNC File Synchroniser",
"RSYNC", "rsync");
hfi_rsync = proto_registrar_get_nth(proto_rsync);
proto_register_fields(proto_rsync, hfi, array_length(hfi));
proto_register_subtree_array(ett, array_length(ett));
rsync_module = prefs_register_protocol(proto_rsync, proto_reg_handoff_rsync);
prefs_register_uint_preference(rsync_module, "tcp_port",
"rsync TCP Port",
"Set the TCP port for RSYNC messages",
10,
&glb_rsync_tcp_port);
prefs_register_bool_preference(rsync_module, "desegment",
"Reassemble RSYNC messages spanning multiple TCP segments",
"Whether the RSYNC dissector should reassemble messages spanning multiple TCP segments."
" To use this option, you must also enable"
" \"Allow subdissectors to reassemble TCP streams\" in the TCP protocol settings.",
&rsync_desegment);
rsync_handle = new_create_dissector_handle(dissect_rsync, proto_rsync);
}
void
proto_reg_handoff_rsync(void)
{
static gboolean initialized = FALSE;
static guint saved_rsync_tcp_port;
if (!initialized) {
initialized = TRUE;
} else {
dissector_delete_uint("tcp.port", saved_rsync_tcp_port, rsync_handle);
}
dissector_add_uint("tcp.port", glb_rsync_tcp_port, rsync_handle);
saved_rsync_tcp_port = glb_rsync_tcp_port;
}
