static tvbuff_t *
mtp3_msu_present(tvbuff_t *tvb, packet_info *pinfo, gint fac, gint level, const char *msg_str, gint chars_truncated)
{
size_t nbytes;
size_t len;
gchar **split_string, *msu_hex_dump;
tvbuff_t *mtp3_tvb = NULL;
guint8 *byte_array;
if (!(fac == FAC_LOCAL0 && level == LEVEL_DEBUG))
return NULL;
if (strstr(msg_str, "msu=") == NULL)
return NULL;
split_string = g_strsplit(msg_str, "msu=", 2);
msu_hex_dump = split_string[1];
if (msu_hex_dump && (len = strlen(msu_hex_dump))) {
if (len % 2)
msu_hex_dump[len - 1] = '\0';
byte_array = convert_string_to_hex(msu_hex_dump, &nbytes);
if (byte_array) {
mtp3_tvb = tvb_new_child_real_data(tvb, byte_array, (guint)nbytes,
(guint)nbytes + chars_truncated / 2);
tvb_set_free_cb(mtp3_tvb, g_free);
add_new_data_source(pinfo, mtp3_tvb, "Encapsulated MSU");
}
}
g_strfreev(split_string);
return(mtp3_tvb);
}
static void
dissect_syslog(tvbuff_t *tvb, packet_info *pinfo, proto_tree *tree)
{
gint pri = -1, lev = -1, fac = -1;
gint msg_off = 0, msg_len, reported_msg_len;
proto_item *ti;
proto_tree *syslog_tree;
const char *msg_str;
tvbuff_t *mtp3_tvb;
col_set_str(pinfo->cinfo, COL_PROTOCOL, "Syslog");
col_clear(pinfo->cinfo, COL_INFO);
if (tvb_get_guint8(tvb, msg_off) == '<') {
msg_off++;
pri = 0;
while (tvb_bytes_exist(tvb, msg_off, 1) &&
isdigit(tvb_get_guint8(tvb, msg_off)) && msg_off <= MAX_DIGITS) {
pri = pri * 10 + (tvb_get_guint8(tvb, msg_off) - '0');
msg_off++;
}
if (tvb_get_guint8(tvb, msg_off) == '>')
msg_off++;
fac = (pri & FACILITY_MASK) >> 3;
lev = pri & PRIORITY_MASK;
}
msg_len = tvb_ensure_length_remaining(tvb, msg_off);
msg_str = tvb_format_text(tvb, msg_off, msg_len);
reported_msg_len = tvb_reported_length_remaining(tvb, msg_off);
mtp3_tvb = mtp3_msu_present(tvb, pinfo, fac, lev, msg_str,
(reported_msg_len - msg_len));
if (mtp3_tvb == NULL && check_col(pinfo->cinfo, COL_INFO)) {
if (pri >= 0) {
col_add_fstr(pinfo->cinfo, COL_INFO, "%s.%s: %s",
val_to_str_const(fac, short_fac, "UNKNOWN"),
val_to_str_const(lev, short_lev, "UNKNOWN"), msg_str);
} else {
col_add_str(pinfo->cinfo, COL_INFO, msg_str);
}
}
if (tree) {
if (pri >= 0) {
ti = proto_tree_add_protocol_format(tree, proto_syslog, tvb, 0, -1,
"Syslog message: %s.%s: %s",
val_to_str_const(fac, short_fac, "UNKNOWN"),
val_to_str_const(lev, short_lev, "UNKNOWN"), msg_str);
} else {
ti = proto_tree_add_protocol_format(tree, proto_syslog, tvb, 0, -1,
"Syslog message: (unknown): %s", msg_str);
}
syslog_tree = proto_item_add_subtree(ti, ett_syslog);
if (pri >= 0) {
proto_tree_add_uint(syslog_tree, hf_syslog_facility, tvb, 0,
msg_off, pri);
proto_tree_add_uint(syslog_tree, hf_syslog_level, tvb, 0,
msg_off, pri);
}
proto_tree_add_item(syslog_tree, hf_syslog_msg, tvb, msg_off,
msg_len, ENC_ASCII|ENC_NA);
if (mtp3_tvb) {
proto_item *mtp3_item;
mtp3_item = proto_tree_add_boolean(syslog_tree, hf_syslog_msu_present,
tvb, msg_off, msg_len, TRUE);
PROTO_ITEM_SET_GENERATED(mtp3_item);
}
}
if (mtp3_tvb) {
call_dissector(mtp_handle, mtp3_tvb, pinfo, tree);
}
return;
}
void proto_register_syslog(void)
{
static hf_register_info hf[] = {
{ &hf_syslog_facility,
{ "Facility", "syslog.facility",
FT_UINT8, BASE_DEC, VALS(long_fac), FACILITY_MASK,
"Message facility", HFILL }
},
{ &hf_syslog_level,
{ "Level", "syslog.level",
FT_UINT8, BASE_DEC, VALS(long_lev), PRIORITY_MASK,
"Message level", HFILL }
},
{ &hf_syslog_msg,
{ "Message", "syslog.msg",
FT_STRING, BASE_NONE, NULL, 0x0,
"Message Text", HFILL }
},
{ &hf_syslog_msu_present,
{ "SS7 MSU present", "syslog.msu_present",
FT_BOOLEAN, BASE_NONE, NULL, 0x0,
"True if an SS7 MSU was detected in the syslog message",
HFILL }
}
};
static gint *ett[] = {
&ett_syslog,
};
proto_syslog = proto_register_protocol("Syslog message", "Syslog", "syslog");
proto_register_field_array(proto_syslog, hf, array_length(hf));
proto_register_subtree_array(ett, array_length(ett));
register_dissector("syslog", dissect_syslog, proto_syslog);
}
void
proto_reg_handoff_syslog(void)
{
dissector_handle_t syslog_handle;
syslog_handle = create_dissector_handle(dissect_syslog, proto_syslog);
dissector_add_uint("udp.port", UDP_PORT_SYSLOG, syslog_handle);
dissector_add_handle("tcp.port", syslog_handle);
mtp_handle = find_dissector("mtp3");
}
