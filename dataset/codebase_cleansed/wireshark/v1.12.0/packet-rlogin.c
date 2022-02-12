static void
rlogin_state_machine(rlogin_hash_entry_t *hash_info, tvbuff_t *tvb, packet_info *pinfo)
{
guint length;
gint stringlen;
if (pinfo->fd->flags.visited)
{
return;
}
if (pinfo->destport != RLOGIN_PORT)
{
return;
}
if (hash_info->state == DONE)
{
return;
}
length = tvb_length(tvb);
if (length == 0)
{
return;
}
if (hash_info->state == NONE)
{
if (tvb_get_guint8(tvb, 0) != '\0')
{
hash_info->state = DONE;
return;
}
else
{
if (length <= 1)
{
hash_info->state = USER_INFO_WAIT;
}
else
{
hash_info->state = DONE;
hash_info->info_framenum = pinfo->fd->num;
}
}
}
else
if (hash_info->state == USER_INFO_WAIT)
{
hash_info->state = DONE;
hash_info->info_framenum = pinfo->fd->num;
stringlen = tvb_strnlen(tvb, 0, NAME_LEN);
if (stringlen == -1)
stringlen = NAME_LEN - 1;
else if (stringlen > NAME_LEN - 1)
stringlen = NAME_LEN - 1;
tvb_memcpy(tvb, (guint8 *)hash_info->user_name, 0, stringlen);
hash_info->user_name[stringlen] = '\0';
col_append_str(pinfo->cinfo, COL_INFO, ", (User information)");
}
}
static void rlogin_display(rlogin_hash_entry_t *hash_info,
tvbuff_t *tvb,
packet_info *pinfo,
proto_tree *tree,
struct tcpinfo *tcpinfo)
{
int offset = 0;
proto_tree *rlogin_tree, *user_info_tree, *window_tree;
proto_item *ti;
guint length;
int str_len;
gint ti_offset;
proto_item *user_info_item, *window_info_item;
ti = proto_tree_add_item(tree, proto_rlogin, tvb, 0, -1, ENC_NA);
rlogin_tree = proto_item_add_subtree(ti, ett_rlogin);
length = tvb_length(tvb);
if (length == 0)
{
return;
}
if (tcpinfo && tcpinfo->urgent &&
length >= tcpinfo->urgent_pointer)
{
int urgent_offset = tcpinfo->urgent_pointer - 1;
guint8 control_byte;
if (urgent_offset > offset)
{
proto_tree_add_item(rlogin_tree, hf_data, tvb, offset, urgent_offset, ENC_ASCII|ENC_NA);
}
proto_tree_add_item(rlogin_tree, hf_control_message, tvb,
urgent_offset, 1, ENC_BIG_ENDIAN);
control_byte = tvb_get_guint8(tvb, urgent_offset);
col_append_fstr(pinfo->cinfo, COL_INFO,
" (%s)", val_to_str_const(control_byte, control_message_vals, "Unknown"));
offset = urgent_offset + 1;
}
else
if (tvb_get_guint8(tvb, offset) == '\0')
{
if (pinfo->srcport == RLOGIN_PORT)
{
proto_tree_add_item(rlogin_tree, hf_startup_info_received_flag,
tvb, offset, 1, ENC_BIG_ENDIAN);
}
else
{
proto_tree_add_item(rlogin_tree, hf_client_startup_flag,
tvb, offset, 1, ENC_BIG_ENDIAN);
}
++offset;
}
if (!tvb_offset_exists(tvb, offset))
{
return;
}
if (hash_info->info_framenum == pinfo->fd->num)
{
gint info_len;
gint slash_offset;
info_len = tvb_length_remaining(tvb, offset);
if (info_len <= 0)
return;
user_info_item = proto_tree_add_string_format(rlogin_tree, hf_user_info, tvb,
offset, info_len, FALSE,
"User info (%s)",
tvb_format_text(tvb, offset, info_len));
user_info_tree = proto_item_add_subtree(user_info_item,
ett_rlogin_user_info);
str_len = tvb_strsize(tvb, offset);
proto_tree_add_item(user_info_tree, hf_user_info_client_user_name,
tvb, offset, str_len, ENC_ASCII|ENC_NA);
offset += str_len;
str_len = tvb_strsize(tvb, offset);
proto_tree_add_item(user_info_tree, hf_user_info_server_user_name,
tvb, offset, str_len, ENC_ASCII|ENC_NA);
offset += str_len;
slash_offset = tvb_find_guint8(tvb, offset, -1, '/');
if (slash_offset != -1)
{
proto_tree_add_item(user_info_tree, hf_user_info_terminal_type,
tvb, offset, slash_offset-offset, ENC_ASCII|ENC_NA);
offset = slash_offset + 1;
str_len = tvb_strsize(tvb, offset);
proto_tree_add_uint(user_info_tree, hf_user_info_terminal_speed,
tvb, offset, str_len,
atoi(tvb_format_text(tvb, offset, str_len)));
offset += str_len;
}
}
if (!tvb_offset_exists(tvb, offset))
{
return;
}
ti_offset = tvb_find_guint8(tvb, offset, -1, 0xff);
if (ti_offset != -1 &&
tvb_bytes_exist(tvb, ti_offset + 1, 1) &&
tvb_get_guint8(tvb, ti_offset + 1) == 0xff)
{
guint16 rows, columns;
if (ti_offset > offset)
{
proto_tree_add_item(rlogin_tree, hf_data, tvb,
offset, ti_offset - offset, ENC_ASCII|ENC_NA);
}
window_info_item =
proto_tree_add_item(rlogin_tree, hf_window_info, tvb, offset, 12, ENC_NA);
window_tree = proto_item_add_subtree(window_info_item, ett_rlogin_window);
proto_tree_add_text(window_tree, tvb, offset, 2, "Magic Cookie: (0xff, 0xff)");
offset += 2;
proto_tree_add_item(window_tree, hf_window_info_ss, tvb, offset, 2, ENC_ASCII|ENC_NA);
offset += 2;
rows = tvb_get_ntohs(tvb, offset);
proto_tree_add_item(window_tree, hf_window_info_rows, tvb,
offset, 2, ENC_BIG_ENDIAN);
offset += 2;
columns = tvb_get_ntohs(tvb, offset);
proto_tree_add_item(window_tree, hf_window_info_cols, tvb,
offset, 2, ENC_BIG_ENDIAN);
offset += 2;
proto_tree_add_item(window_tree, hf_window_info_x_pixels, tvb,
offset, 2, ENC_BIG_ENDIAN);
offset += 2;
proto_tree_add_item(window_tree, hf_window_info_y_pixels, tvb,
offset, 2, ENC_BIG_ENDIAN);
offset += 2;
col_append_fstr(pinfo->cinfo, COL_INFO, " (rows=%u, cols=%u)",
rows, columns);
}
if (tvb_offset_exists(tvb, offset))
{
proto_tree_add_item(rlogin_tree, hf_data, tvb, offset, -1, ENC_ASCII|ENC_NA);
}
}
static int
dissect_rlogin(tvbuff_t *tvb, packet_info *pinfo, proto_tree *tree, void* data)
{
struct tcpinfo *tcpinfo = (struct tcpinfo *)data;
conversation_t *conversation;
rlogin_hash_entry_t *hash_info;
guint length;
gint ti_offset;
conversation = find_or_create_conversation(pinfo);
hash_info = (rlogin_hash_entry_t *)conversation_get_proto_data(conversation, proto_rlogin);
if (!hash_info)
{
hash_info = wmem_new(wmem_file_scope(), rlogin_hash_entry_t);
hash_info->state = NONE;
hash_info->info_framenum = 0;
hash_info->user_name[0] = '\0';
conversation_add_proto_data(conversation, proto_rlogin, hash_info);
}
col_set_str(pinfo->cinfo, COL_PROTOCOL, "Rlogin");
if (hash_info->user_name[0])
{
col_add_fstr(pinfo->cinfo, COL_INFO,
"User name: %s, ", hash_info->user_name);
}
else
{
col_clear(pinfo->cinfo, COL_INFO);
}
length = tvb_length(tvb);
if (length != 0)
{
if (tvb_get_guint8(tvb, 0) == '\0')
{
col_append_str(pinfo->cinfo, COL_INFO,
(pinfo->destport == RLOGIN_PORT) ?
"Start Handshake" :
"Startup info received");
}
else
if (tcpinfo && tcpinfo->urgent && length >= tcpinfo->urgent_pointer)
{
col_append_str(pinfo->cinfo, COL_INFO, "Control Message");
}
else
{
ti_offset = tvb_find_guint8(tvb, 0, -1, 0xff);
if (ti_offset != -1 &&
tvb_bytes_exist(tvb, ti_offset + 1, 1) &&
tvb_get_guint8(tvb, ti_offset + 1) == 0xff)
{
col_append_str(pinfo->cinfo, COL_INFO, "Terminal Info");
}
else
{
int bytes_to_copy = tvb_length(tvb);
if (bytes_to_copy > 128)
{
bytes_to_copy = 128;
}
col_append_fstr(pinfo->cinfo, COL_INFO,
"Data: %s",
tvb_format_text(tvb, 0, bytes_to_copy));
}
}
}
rlogin_state_machine(hash_info, tvb, pinfo);
rlogin_display(hash_info, tvb, pinfo, tree, tcpinfo);
return tvb_length(tvb);
}
void proto_register_rlogin(void)
{
static gint *ett[] = {
&ett_rlogin,
&ett_rlogin_window,
&ett_rlogin_window_rows,
&ett_rlogin_window_cols,
&ett_rlogin_window_x_pixels,
&ett_rlogin_window_y_pixels,
&ett_rlogin_user_info
};
static hf_register_info hf[] =
{
{ &hf_user_info,
{ "User Info", "rlogin.user_info", FT_STRING, BASE_NONE,
NULL, 0x0, NULL, HFILL
}
},
{ &hf_client_startup_flag,
{ "Client startup flag", "rlogin.client_startup_flag", FT_UINT8, BASE_HEX,
NULL, 0x0, NULL, HFILL
}
},
{ &hf_startup_info_received_flag,
{ "Startup info received flag", "rlogin.startup_info_received_flag", FT_UINT8, BASE_HEX,
NULL, 0x0, NULL, HFILL
}
},
{ &hf_user_info_client_user_name,
{ "Client-user-name", "rlogin.client_user_name", FT_STRING, BASE_NONE,
NULL, 0x0, NULL, HFILL
}
},
{ &hf_user_info_server_user_name,
{ "Server-user-name", "rlogin.server_user_name", FT_STRING, BASE_NONE,
NULL, 0x0, NULL, HFILL
}
},
{ &hf_user_info_terminal_type,
{ "Terminal-type", "rlogin.terminal_type", FT_STRING, BASE_NONE,
NULL, 0x0, NULL, HFILL
}
},
{ &hf_user_info_terminal_speed,
{ "Terminal-speed", "rlogin.terminal_speed", FT_UINT32, BASE_DEC,
NULL, 0x0, NULL, HFILL
}
},
{ &hf_control_message,
{ "Control message", "rlogin.control_message", FT_UINT8, BASE_HEX,
VALS(control_message_vals), 0x0, NULL, HFILL
}
},
{ &hf_window_info,
{ "Window Info", "rlogin.window_size", FT_NONE, BASE_NONE,
NULL, 0x0, NULL, HFILL
}
},
{ &hf_window_info_ss,
{ "Window size marker", "rlogin.window_size.ss", FT_STRING, BASE_NONE,
NULL, 0x0, NULL, HFILL
}
},
{ &hf_window_info_rows,
{ "Rows", "rlogin.window_size.rows", FT_UINT16, BASE_DEC,
NULL, 0x0, NULL, HFILL
}
},
{ &hf_window_info_cols,
{ "Columns", "rlogin.window_size.cols", FT_UINT16, BASE_DEC,
NULL, 0x0, NULL, HFILL
}
},
{ &hf_window_info_x_pixels,
{ "X Pixels", "rlogin.window_size.x_pixels", FT_UINT16, BASE_DEC,
NULL, 0x0, NULL, HFILL
}
},
{ &hf_window_info_y_pixels,
{ "Y Pixels", "rlogin.window_size.y_pixels", FT_UINT16, BASE_DEC,
NULL, 0x0, NULL, HFILL
}
},
{ &hf_data,
{ "Data", "rlogin.data", FT_STRING, BASE_NONE,
NULL, 0x0, NULL, HFILL
}
}
};
proto_rlogin = proto_register_protocol("Rlogin Protocol", "Rlogin", "rlogin");
proto_register_field_array(proto_rlogin, hf, array_length(hf));
proto_register_subtree_array(ett, array_length(ett));
}
void proto_reg_handoff_rlogin(void)
{
dissector_handle_t rlogin_handle = new_create_dissector_handle(dissect_rlogin,proto_rlogin);
dissector_add_uint("tcp.port", RLOGIN_PORT, rlogin_handle);
}
