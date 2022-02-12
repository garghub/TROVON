static void
dissect_rsync_encap(tvbuff_t *tvb, packet_info *pinfo, proto_tree *tree,
gboolean desegment _U_)
{
conversation_t *conversation;
struct rsync_conversation_data *conversation_data;
struct rsync_frame_data *rsync_frame_data_p;
proto_item *ti;
proto_tree *rsync_tree;
int offset = 0;
gchar version[5];
gchar auth_string[10];
guint buff_length;
gchar magic_string[14];
gchar *version_out;
col_set_str(pinfo->cinfo, COL_PROTOCOL, "RSYNC");
col_clear(pinfo->cinfo, COL_INFO);
conversation = find_or_create_conversation(pinfo);
conversation_data = conversation_get_proto_data(conversation, proto_rsync);
if (conversation_data == NULL) {
conversation_data = se_alloc(sizeof(struct rsync_conversation_data));
conversation_data->state = RSYNC_INIT;
conversation_add_proto_data(conversation, proto_rsync, conversation_data);
}
conversation_set_dissector(conversation, rsync_handle);
ti = proto_tree_add_item(tree, proto_rsync, tvb, 0, -1, ENC_NA);
rsync_tree = proto_item_add_subtree(ti, ett_rsync);
rsync_frame_data_p = p_get_proto_data(pinfo->fd, proto_rsync);
if (!rsync_frame_data_p) {
rsync_frame_data_p = se_alloc(sizeof(struct rsync_frame_data));
rsync_frame_data_p->state = conversation_data->state;
p_add_proto_data(pinfo->fd, proto_rsync, rsync_frame_data_p);
}
switch (rsync_frame_data_p->state) {
case RSYNC_INIT:
proto_tree_add_item(rsync_tree, hf_rsync_hdr_magic, tvb, offset, 8, ENC_ASCII|ENC_NA);
offset += 8;
proto_tree_add_item(rsync_tree, hf_rsync_hdr_version, tvb, offset, 4, ENC_ASCII|ENC_NA);
tvb_get_nstringz0(tvb, offset, sizeof(version), version);
offset += 4;
if (check_col(pinfo->cinfo, COL_INFO)) {
version_out = format_text(version, 4);
col_append_fstr(pinfo->cinfo, COL_INFO,
"Client Initialisation (Version %s)",
version_out);
}
conversation_data->state = RSYNC_SERV_INIT;
break;
case RSYNC_SERV_INIT:
proto_tree_add_item(rsync_tree, hf_rsync_hdr_magic, tvb, offset, 8, ENC_ASCII|ENC_NA);
offset += 8;
proto_tree_add_item(rsync_tree, hf_rsync_hdr_version, tvb, offset, 4, ENC_ASCII|ENC_NA);
tvb_get_nstringz0(tvb, offset, sizeof(version), version);
offset += 4;
if (check_col(pinfo->cinfo, COL_INFO)) {
version_out = format_text(version, 4);
col_append_fstr(pinfo->cinfo, COL_INFO,
"Server Initialisation (Version %s)",
version_out);
}
conversation_data->state = RSYNC_CLIENT_QUERY;
break;
case RSYNC_CLIENT_QUERY:
proto_tree_add_item(rsync_tree, hf_rsync_query_string, tvb, offset, -1, ENC_ASCII|ENC_NA);
col_append_str(pinfo->cinfo, COL_INFO, "Client Query");
conversation_data->state = RSYNC_SERV_MOTD;
break;
case RSYNC_SERV_MOTD:
proto_tree_add_item(rsync_tree, hf_rsync_motd_string, tvb, offset, -1, ENC_ASCII|ENC_NA);
col_append_str(pinfo->cinfo, COL_INFO, "Server MOTD");
conversation_data->state = RSYNC_SERV_RESPONSE;
break;
case RSYNC_SERV_RESPONSE:
tvb_get_nstringz0(tvb, offset, sizeof(auth_string), auth_string);
if (0 == strncmp("@RSYNCD:", auth_string, 8)) {
proto_tree_add_item(rsync_tree, hf_rsync_rsyncdok_string, tvb, offset, -1, ENC_ASCII|ENC_NA);
col_append_str(pinfo->cinfo, COL_INFO, "Authentication");
conversation_data->state = RSYNC_COMMAND;
} else {
proto_tree_add_item(rsync_tree, hf_rsync_response_string, tvb, offset, -1, ENC_ASCII|ENC_NA);
col_append_str(pinfo->cinfo, COL_INFO, "Module list");
buff_length = tvb_length_remaining(tvb, offset);
tvb_get_nstringz0(tvb, buff_length-14, sizeof(magic_string), magic_string);
if (0 == strncmp("@RSYNCD: EXIT", magic_string, 14)) {
conversation_data->state = RSYNC_COMMAND;
} else {
conversation_data->state = RSYNC_SERV_RESPONSE;
}
}
break;
case RSYNC_COMMAND:
if (pinfo->destport == glb_rsync_tcp_port) {
proto_tree_add_item(rsync_tree, hf_rsync_command_string, tvb, offset, -1, ENC_ASCII|ENC_NA);
col_append_str(pinfo->cinfo, COL_INFO, "Command");
conversation_data->state = RSYNC_COMMAND;
break;
}
case RSYNC_DATA:
proto_tree_add_item(rsync_tree, hf_rsync_data, tvb, offset, -1, ENC_NA);
col_append_str(pinfo->cinfo, COL_INFO, "Data");
conversation_data->state = RSYNC_DATA;
break;
}
}
static void
dissect_rsync(tvbuff_t *tvb, packet_info *pinfo, proto_tree *tree)
{
dissect_rsync_encap(tvb, pinfo, tree, rsync_desegment);
}
void
proto_register_rsync(void)
{
static hf_register_info hf[] = {
{&hf_rsync_hdr_magic,
{"Magic Header", "rsync.hdr_magic",
FT_STRING, BASE_NONE, NULL, 0x0, NULL, HFILL }
},
{&hf_rsync_hdr_version,
{"Header Version", "rsync.hdr_version",
FT_STRING, BASE_NONE, NULL, 0x0, NULL, HFILL }
},
{&hf_rsync_query_string,
{"Client Query String", "rsync.query",
FT_STRING, BASE_NONE, NULL, 0x0, NULL, HFILL }
},
{&hf_rsync_response_string,
{"Server Response String", "rsync.response",
FT_STRING, BASE_NONE, NULL, 0x0, NULL, HFILL }
},
{&hf_rsync_motd_string,
{"Server MOTD String", "rsync.motd",
FT_STRING, BASE_NONE, NULL, 0x0, NULL, HFILL }
},
{&hf_rsync_rsyncdok_string,
{"RSYNCD Response String", "rsync.response",
FT_STRING, BASE_NONE, NULL, 0x0, NULL, HFILL }
},
{&hf_rsync_command_string,
{"Command String", "rsync.command",
FT_STRING, BASE_NONE, NULL, 0x0, NULL, HFILL }
},
{&hf_rsync_data,
{"rsync data", "rsync.data",
FT_BYTES, BASE_NONE, NULL, 0x0, NULL, HFILL }
},
};
static gint *ett[] = {
&ett_rsync,
};
module_t *rsync_module;
proto_rsync = proto_register_protocol("RSYNC File Synchroniser",
"RSYNC", "rsync");
proto_register_field_array(proto_rsync, hf, array_length(hf));
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
" To use this option, you must also enable \"Allow subdissectors to reassemble TCP streams\" in the TCP protocol settings.",
&rsync_desegment);
}
void
proto_reg_handoff_rsync(void)
{
static gboolean initialized = FALSE;
static guint saved_rsync_tcp_port;
if (!initialized) {
rsync_handle = create_dissector_handle(dissect_rsync, proto_rsync);
initialized = TRUE;
} else {
dissector_delete_uint("tcp.port", saved_rsync_tcp_port, rsync_handle);
}
dissector_add_uint("tcp.port", glb_rsync_tcp_port, rsync_handle);
saved_rsync_tcp_port = glb_rsync_tcp_port;
}
