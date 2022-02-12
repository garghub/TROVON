static gint
dissect_dsi_open_session(tvbuff_t *tvb, proto_tree *dsi_tree, gint offset, gint dsi_length)
{
proto_tree *tree;
proto_item *ti;
guint8 type;
guint8 len;
ti = proto_tree_add_text(dsi_tree, tvb, offset, -1, "Open Session");
tree = proto_item_add_subtree(ti, ett_dsi_open);
while( dsi_length >2 ) {
type = tvb_get_guint8(tvb, offset);
proto_tree_add_item(tree, hf_dsi_open_type, tvb, offset, 1, ENC_BIG_ENDIAN);
offset++;
len = tvb_get_guint8(tvb, offset);
proto_tree_add_item(tree, hf_dsi_open_len, tvb, offset, 1, ENC_BIG_ENDIAN);
offset++;
switch (type) {
case 0:
proto_tree_add_item(tree, hf_dsi_open_quantum, tvb, offset, 4, ENC_BIG_ENDIAN);
break;
case 1:
proto_tree_add_item(tree, hf_dsi_open_quantum, tvb, offset, 4, ENC_BIG_ENDIAN);
break;
case 2:
proto_tree_add_item(tree, hf_dsi_replay_cache_size, tvb, offset, 4, ENC_BIG_ENDIAN);
break;
default:
proto_tree_add_item(tree, hf_dsi_open_option, tvb, offset, len, ENC_NA);
}
dsi_length -= len + 2;
offset += len;
}
return offset;
}
static gint
dissect_dsi_attention(tvbuff_t *tvb, proto_tree *dsi_tree, gint offset)
{
proto_tree *tree;
proto_item *ti;
guint16 flag;
if (!tvb_reported_length_remaining(tvb,offset))
return offset;
flag = tvb_get_ntohs(tvb, offset);
ti = proto_tree_add_text(dsi_tree, tvb, offset, -1, "Attention");
tree = proto_item_add_subtree(ti, ett_dsi_attn);
ti = proto_tree_add_item(tree, hf_dsi_attn_flag, tvb, offset, 2, ENC_BIG_ENDIAN);
tree = proto_item_add_subtree(ti, ett_dsi_attn_flag);
proto_tree_add_item(tree, hf_dsi_attn_flag_shutdown, tvb, offset, 2, ENC_BIG_ENDIAN);
proto_tree_add_item(tree, hf_dsi_attn_flag_crash, tvb, offset, 2, ENC_BIG_ENDIAN);
proto_tree_add_item(tree, hf_dsi_attn_flag_msg, tvb, offset, 2, ENC_BIG_ENDIAN);
proto_tree_add_item(tree, hf_dsi_attn_flag_reconnect, tvb, offset, 2, ENC_BIG_ENDIAN);
if ((flag & 0xf000) != 0x3000)
proto_tree_add_item(tree, hf_dsi_attn_flag_time, tvb, offset, 2, ENC_BIG_ENDIAN);
else
proto_tree_add_item(tree, hf_dsi_attn_flag_bitmap, tvb, offset, 2, ENC_BIG_ENDIAN);
offset += 2;
return offset;
}
static int
dissect_dsi_packet(tvbuff_t *tvb, packet_info *pinfo, proto_tree *tree, void* data _U_)
{
proto_tree *dsi_tree;
proto_item *ti;
guint8 dsi_flags,dsi_command;
guint16 dsi_requestid;
gint32 dsi_code;
guint32 dsi_length;
guint32 dsi_reserved;
struct aspinfo aspinfo;
col_set_str(pinfo->cinfo, COL_PROTOCOL, "DSI");
col_clear(pinfo->cinfo, COL_INFO);
dsi_flags = tvb_get_guint8(tvb, 0);
dsi_command = tvb_get_guint8(tvb, 1);
dsi_requestid = tvb_get_ntohs(tvb, 2);
dsi_code = tvb_get_ntohl(tvb, 4);
dsi_length = tvb_get_ntohl(tvb, 8);
dsi_reserved = tvb_get_ntohl(tvb, 12);
col_add_fstr(pinfo->cinfo, COL_INFO, "%s %s (%u)",
val_to_str(dsi_flags, flag_vals,
"Unknown flag (0x%02x)"),
val_to_str_ext(dsi_command, &func_vals_ext,
"Unknown function (0x%02x)"),
dsi_requestid);
ti = proto_tree_add_item(tree, proto_dsi, tvb, 0, -1, ENC_NA);
dsi_tree = proto_item_add_subtree(ti, ett_dsi);
if (tree) {
proto_tree_add_uint(dsi_tree, hf_dsi_flags, tvb,
0, 1, dsi_flags);
proto_tree_add_uint(dsi_tree, hf_dsi_command, tvb,
1, 1, dsi_command);
proto_tree_add_uint(dsi_tree, hf_dsi_requestid, tvb,
2, 2, dsi_requestid);
switch (dsi_flags) {
case DSIFL_REQUEST:
proto_tree_add_int(dsi_tree, hf_dsi_offset, tvb,
4, 4, dsi_code);
break;
case DSIFL_REPLY:
proto_tree_add_int(dsi_tree, hf_dsi_error, tvb,
4, 4, dsi_code);
break;
}
proto_tree_add_uint_format_value(dsi_tree, hf_dsi_length, tvb,
8, 4, dsi_length,
"%u bytes", dsi_length);
proto_tree_add_uint(dsi_tree, hf_dsi_reserved, tvb,
12, 4, dsi_reserved);
}
switch (dsi_command) {
case DSIFUNC_OPEN:
if (tree) {
dissect_dsi_open_session(tvb, dsi_tree, DSI_BLOCKSIZ, dsi_length);
}
break;
case DSIFUNC_ATTN:
if (tree) {
dissect_dsi_attention(tvb, dsi_tree, DSI_BLOCKSIZ);
}
break;
case DSIFUNC_STAT:
if (tree && (dsi_flags == DSIFL_REPLY)) {
tvbuff_t *new_tvb;
new_tvb = tvb_new_subset_remaining(tvb, DSI_BLOCKSIZ);
call_dissector(afp_server_status_handle, new_tvb, pinfo, dsi_tree);
}
break;
case DSIFUNC_CMD:
case DSIFUNC_WRITE:
{
tvbuff_t *new_tvb;
aspinfo.reply = (dsi_flags == DSIFL_REPLY);
aspinfo.command = dsi_command;
aspinfo.seq = dsi_requestid;
aspinfo.code = dsi_code;
proto_item_set_len(dsi_tree, DSI_BLOCKSIZ);
new_tvb = tvb_new_subset_remaining(tvb, DSI_BLOCKSIZ);
call_dissector_with_data(afp_handle, new_tvb, pinfo, tree, &aspinfo);
}
break;
default:
call_dissector(data_handle,
tvb_new_subset_remaining(tvb, DSI_BLOCKSIZ),
pinfo, dsi_tree);
break;
}
return tvb_length(tvb);
}
static guint
get_dsi_pdu_len(packet_info *pinfo _U_, tvbuff_t *tvb, int offset)
{
guint32 plen;
guint8 dsi_flags,dsi_command;
dsi_flags = tvb_get_guint8(tvb, offset);
dsi_command = tvb_get_guint8(tvb, offset+ 1);
if ( dsi_flags > DSIFL_MAX || !dsi_command || dsi_command > DSIFUNC_MAX)
{
return tvb_length_remaining(tvb, offset);
}
plen = tvb_get_ntohl(tvb, offset+8);
return plen + 16;
}
static int
dissect_dsi(tvbuff_t *tvb, packet_info *pinfo, proto_tree *tree, void* data)
{
tcp_dissect_pdus(tvb, pinfo, tree, dsi_desegment, 12,
get_dsi_pdu_len, dissect_dsi_packet, data);
return tvb_length(tvb);
}
void
proto_register_dsi(void)
{
static hf_register_info hf[] = {
{ &hf_dsi_flags,
{ "Flags", "dsi.flags",
FT_UINT8, BASE_HEX, VALS(flag_vals), 0x0,
"Indicates request or reply.", HFILL }},
{ &hf_dsi_command,
{ "Command", "dsi.command",
FT_UINT8, BASE_DEC|BASE_EXT_STRING, &func_vals_ext, 0x0,
"Represents a DSI command.", HFILL }},
{ &hf_dsi_requestid,
{ "Request ID", "dsi.requestid",
FT_UINT16, BASE_DEC, NULL, 0x0,
"Keeps track of which request this is. Replies must match a Request. IDs must be generated in sequential order.", HFILL }},
{ &hf_dsi_offset,
{ "Data offset", "dsi.data_offset",
FT_INT32, BASE_DEC, NULL, 0x0,
NULL, HFILL }},
{ &hf_dsi_error,
{ "Error code", "dsi.error_code",
FT_INT32, BASE_DEC|BASE_EXT_STRING, &asp_error_vals_ext, 0x0,
NULL, HFILL }},
{ &hf_dsi_length,
{ "Length", "dsi.length",
FT_UINT32, BASE_DEC, NULL, 0x0,
"Total length of the data that follows the DSI header.", HFILL }},
{ &hf_dsi_reserved,
{ "Reserved", "dsi.reserved",
FT_UINT32, BASE_HEX, NULL, 0x0,
"Reserved for future use. Should be set to zero.", HFILL }},
{ &hf_dsi_open_type,
{ "Option", "dsi.open_type",
FT_UINT8, BASE_DEC, VALS(dsi_open_type_vals), 0x0,
"Open session option type.", HFILL }},
{ &hf_dsi_open_len,
{ "Length", "dsi.open_len",
FT_UINT8, BASE_DEC, NULL, 0x0,
"Open session option len", HFILL }},
{ &hf_dsi_open_quantum,
{ "Quantum", "dsi.open_quantum",
FT_UINT32, BASE_DEC, NULL, 0x0,
"Server/Attention quantum", HFILL }},
{ &hf_dsi_replay_cache_size,
{ "Replay", "dsi.replay_cache",
FT_UINT32, BASE_DEC, NULL, 0x0,
"Replay cache size", HFILL }},
{ &hf_dsi_open_option,
{ "Option", "dsi.open_option",
FT_BYTES, BASE_NONE, NULL, 0x0,
"Open session options (undecoded)", HFILL }},
{ &hf_dsi_attn_flag,
{ "Flags", "dsi.attn_flag",
FT_UINT16, BASE_HEX|BASE_EXT_STRING, &dsi_attn_flag_vals_ext, 0xf000,
"Server attention flag", HFILL }},
{ &hf_dsi_attn_flag_shutdown,
{ "Shutdown", "dsi.attn_flag.shutdown",
FT_BOOLEAN, 16, NULL, 1<<15,
"Attention flag, server is shutting down", HFILL }},
{ &hf_dsi_attn_flag_crash,
{ "Crash", "dsi.attn_flag.crash",
FT_BOOLEAN, 16, NULL, 1<<14,
"Attention flag, server crash bit", HFILL }},
{ &hf_dsi_attn_flag_msg,
{ "Message", "dsi.attn_flag.msg",
FT_BOOLEAN, 16, NULL, 1<<13,
"Attention flag, server message bit", HFILL }},
{ &hf_dsi_attn_flag_reconnect,
{ "Don't reconnect", "dsi.attn_flag.reconnect",
FT_BOOLEAN, 16, NULL, 1<<12,
"Attention flag, don't reconnect bit", HFILL }},
{ &hf_dsi_attn_flag_time,
{ "Minutes", "dsi.attn_flag.time",
FT_UINT16, BASE_DEC, NULL, 0xfff,
"Number of minutes", HFILL }},
{ &hf_dsi_attn_flag_bitmap,
{ "Bitmap", "dsi.attn_flag.bitmap",
FT_UINT16, BASE_HEX, NULL, 0xfff,
"Attention extended bitmap", HFILL }},
};
static gint *ett[] = {
&ett_dsi,
&ett_dsi_open,
&ett_dsi_attn,
&ett_dsi_attn_flag
};
module_t *dsi_module;
proto_dsi = proto_register_protocol("Data Stream Interface", "DSI", "dsi");
proto_register_field_array(proto_dsi, hf, array_length(hf));
proto_register_subtree_array(ett, array_length(ett));
dsi_module = prefs_register_protocol(proto_dsi, NULL);
prefs_register_bool_preference(dsi_module, "desegment",
"Reassemble DSI messages spanning multiple TCP segments",
"Whether the DSI dissector should reassemble messages spanning multiple TCP segments."
" To use this option, you must also enable \"Allow subdissectors to reassemble TCP streams\" in the TCP protocol settings.",
&dsi_desegment);
}
void
proto_reg_handoff_dsi(void)
{
dissector_handle_t dsi_handle;
dsi_handle = new_create_dissector_handle(dissect_dsi, proto_dsi);
dissector_add_uint("tcp.port", TCP_PORT_DSI, dsi_handle);
data_handle = find_dissector("data");
afp_handle = find_dissector("afp");
afp_server_status_handle = find_dissector("afp_server_status");
}
