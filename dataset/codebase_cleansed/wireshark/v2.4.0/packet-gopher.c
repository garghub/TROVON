static gboolean
is_client(packet_info *pinfo) {
if (value_is_in_range(gopher_tcp_range, pinfo->destport)) {
return TRUE;
}
return FALSE;
}
static gboolean
find_dir_tokens(tvbuff_t *tvb, gint name_start, gint *sel_start, gint *host_start, gint *port_start, gint *line_len, gint *next_offset) {
gint remain;
if (tvb_captured_length_remaining(tvb, name_start) < MIN_DIR_LINE_LEN)
return FALSE;
if (! (sel_start && host_start && port_start && line_len && next_offset) )
return FALSE;
*line_len = tvb_find_line_end(tvb, name_start, MAX_DIR_LINE_LEN, next_offset, FALSE);
if (*line_len < MIN_DIR_LINE_LEN)
return FALSE;
remain = *line_len;
*sel_start = tvb_find_guint8(tvb, name_start, remain, '\t') + 1;
if (*sel_start < name_start + 1)
return FALSE;
remain -= *sel_start - name_start;
*host_start = tvb_find_guint8(tvb, *sel_start, remain, '\t') + 1;
if (*host_start < *sel_start + 1)
return FALSE;
remain -= *host_start - *sel_start;
*port_start = tvb_find_guint8(tvb, *host_start, remain, '\t') + 1;
if (*port_start < *host_start + 1)
return FALSE;
return TRUE;
}
static int
dissect_gopher(tvbuff_t *tvb, packet_info *pinfo, proto_tree *tree, void *data _U_) {
proto_item *ti;
proto_tree *gopher_tree, *dir_tree = NULL;
gboolean client = is_client(pinfo);
gint line_len;
const gchar *request = "[Invalid request]";
gboolean is_dir = FALSE;
gint offset = 0, next_offset;
gint sel_start, host_start, port_start;
gchar *name;
col_set_str(pinfo->cinfo, COL_PROTOCOL, "Gopher");
if (client) {
line_len = tvb_find_line_end(tvb, 0, -1, NULL, FALSE);
if (line_len == 0) {
request = "[Directory list]";
} else if (line_len > 0) {
request = tvb_get_string_enc(wmem_packet_scope(), tvb, 0, line_len, ENC_ASCII);
}
col_add_fstr(pinfo->cinfo, COL_INFO, "Request: %s", request);
} else {
col_add_fstr(pinfo->cinfo, COL_INFO, "Response");
}
if (tree) {
ti = proto_tree_add_item(tree, proto_gopher, tvb, 0, -1, ENC_NA);
gopher_tree = proto_item_add_subtree(ti, ett_gopher);
if (client) {
proto_item_append_text(ti, " request: %s", request);
proto_tree_add_string(gopher_tree, hf_gopher_request, tvb,
0, -1, request);
} else {
proto_item_append_text(ti, " response: ");
while (find_dir_tokens(tvb, offset + 1, &sel_start, &host_start, &port_start, &line_len, &next_offset)) {
if (!is_dir) {
proto_item_append_text(ti, "[Directory list]");
col_append_str(pinfo->cinfo, COL_INFO, ": [Directory list]");
}
name = tvb_get_string_enc(wmem_packet_scope(), tvb, offset + 1, sel_start - offset - 2, ENC_ASCII);
ti = proto_tree_add_string(gopher_tree, hf_gopher_dir_item, tvb,
offset, line_len + 1, name);
dir_tree = proto_item_add_subtree(ti, ett_dir_item);
proto_tree_add_item(dir_tree, hf_gopher_di_type, tvb, offset, 1, ENC_ASCII|ENC_NA);
proto_tree_add_item(dir_tree, hf_gopher_di_name, tvb, offset + 1,
sel_start - offset - 2, ENC_ASCII|ENC_NA);
proto_tree_add_item(dir_tree, hf_gopher_di_selector, tvb, sel_start,
host_start - sel_start - 1, ENC_ASCII|ENC_NA);
proto_tree_add_item(dir_tree, hf_gopher_di_host, tvb, host_start,
port_start - host_start - 1, ENC_ASCII|ENC_NA);
proto_tree_add_item(dir_tree, hf_gopher_di_port, tvb, port_start,
line_len - (port_start - offset - 1), ENC_ASCII|ENC_NA);
is_dir = TRUE;
offset = next_offset;
}
if (!is_dir) {
proto_item_append_text(ti, "[Unknown]");
proto_tree_add_item(gopher_tree, hf_gopher_unknown, tvb, 0, -1, ENC_ASCII|ENC_NA);
}
}
}
return tvb_captured_length(tvb);
}
static void
gopher_prefs_apply(void) {
gopher_tcp_range = prefs_get_range_value("gopher", "tcp.port");
}
void
proto_register_gopher(void)
{
static hf_register_info hf[] = {
{ &hf_gopher_request,
{ "Gopher client request", "gopher.request",
FT_STRING, BASE_NONE, NULL, 0,
NULL, HFILL }
},
{ &hf_gopher_dir_item,
{ "Directory item", "gopher.directory",
FT_STRING, BASE_NONE, NULL, 0,
NULL, HFILL }
},
{ &hf_gopher_di_type,
{ "Type", "gopher.directory.type",
FT_CHAR, BASE_HEX, VALS(item_types), 0,
NULL, HFILL }
},
{ &hf_gopher_di_name,
{ "Name", "gopher.directory.name",
FT_STRING, BASE_NONE, NULL, 0,
NULL, HFILL }
},
{ &hf_gopher_di_selector,
{ "Selector", "gopher.directory.selector",
FT_STRING, BASE_NONE, NULL, 0,
NULL, HFILL }
},
{ &hf_gopher_di_host,
{ "Host", "gopher.directory.host",
FT_STRING, BASE_NONE, NULL, 0,
NULL, HFILL }
},
{ &hf_gopher_di_port,
{ "Port", "gopher.directory.port",
FT_STRING, BASE_NONE, NULL, 0,
NULL, HFILL }
},
{ &hf_gopher_unknown,
{ "Unknown Gopher transaction data", "gopher.unknown",
FT_STRING, BASE_NONE, NULL, 0,
NULL, HFILL }
}
};
static gint *ett[] = {
&ett_gopher,
&ett_dir_item
};
proto_gopher = proto_register_protocol("Gopher", "Gopher", "gopher");
proto_register_field_array(proto_gopher, hf, array_length(hf));
proto_register_subtree_array(ett, array_length(ett));
prefs_register_protocol(proto_gopher, gopher_prefs_apply);
}
void
proto_reg_handoff_gopher(void)
{
gopher_handle = create_dissector_handle(dissect_gopher, proto_gopher);
dissector_add_uint_range_with_preference("tcp.port", TCP_DEFAULT_RANGE, gopher_handle);
}
