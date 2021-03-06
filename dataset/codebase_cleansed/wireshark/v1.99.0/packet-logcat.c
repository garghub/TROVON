static gint detect_version(tvbuff_t *tvb, gint offset) {
guint16 payload_length;
guint16 try_header_size;
payload_length = tvb_get_letohs(tvb, offset);
try_header_size = tvb_get_letohs(tvb, offset + 2);
if (try_header_size == 0 || try_header_size != 24)
return 1;
if (tvb_reported_length_remaining(tvb, offset + 24 + payload_length) >= 0)
return 2;
return 1;
}
static int
dissect_logcat(tvbuff_t *tvb, packet_info *pinfo, proto_tree *tree, void *data _U_)
{
gint offset = 0;
proto_tree *maintree;
proto_item *mainitem;
proto_tree *subtree;
proto_item *subitem;
guint16 length;
guint16 check_length;
guint32 string_length;
gint logger_version;
guint8 *log;
gchar *c;
tvbuff_t *next_tvb;
col_set_str(pinfo->cinfo, COL_PROTOCOL, "Logcat");
col_clear(pinfo->cinfo, COL_INFO);
mainitem = proto_tree_add_item(tree, proto_logcat, tvb, offset, -1, ENC_NA);
maintree = proto_item_add_subtree(mainitem, ett_logcat);
logger_version = detect_version(tvb, offset);
subitem = proto_tree_add_uint(maintree, hf_logcat_version, tvb, offset, 0, logger_version);
PROTO_ITEM_SET_GENERATED(subitem);
proto_tree_add_item(maintree, hf_logcat_length, tvb, offset, 2, ENC_LITTLE_ENDIAN);
length = tvb_get_letohs(tvb, offset);
offset += 2;
if (logger_version == 1) {
proto_tree_add_item(maintree, hf_logcat_padding, tvb, offset, 2, ENC_LITTLE_ENDIAN);
} else {
proto_tree_add_item(maintree, hf_logcat_header_size, tvb, offset, 2, ENC_LITTLE_ENDIAN);
}
offset += 2;
proto_tree_add_item(maintree, hf_logcat_pid, tvb, offset, 4, ENC_LITTLE_ENDIAN);
offset += 4;
proto_tree_add_item(maintree, hf_logcat_tid, tvb, offset, 4, ENC_LITTLE_ENDIAN);
offset += 4;
subitem = proto_tree_add_item(maintree, hf_logcat_timestamp, tvb, offset, 8, ENC_LITTLE_ENDIAN);
subtree = proto_item_add_subtree(subitem, ett_logcat_timestamp);
proto_tree_add_item(subtree, hf_logcat_timestamp_seconds, tvb, offset, 4, ENC_LITTLE_ENDIAN);
offset += 4;
proto_tree_add_item(subtree, hf_logcat_timestamp_nanoseconds, tvb, offset, 4, ENC_LITTLE_ENDIAN);
offset += 4;
if (logger_version >= 2) {
proto_tree_add_item(maintree, hf_logcat_euid, tvb, offset, 4, ENC_LITTLE_ENDIAN);
offset += 4;
}
proto_tree_add_item(maintree, hf_logcat_priority, tvb, offset, 1, ENC_LITTLE_ENDIAN);
offset += 1;
check_length = 1;
string_length = tvb_strsize(tvb, offset);
proto_tree_add_item(maintree, hf_logcat_tag, tvb, offset, string_length, ENC_ASCII | ENC_NA);
TVB_SET_ADDRESS(&pinfo->src, AT_STRINGZ, tvb, offset, string_length + 1);
SET_ADDRESS(&pinfo->dst, AT_STRINGZ, 7, "Logcat");
offset += string_length;
check_length += string_length;
string_length = length - string_length - 1;
log = tvb_get_string_enc(wmem_packet_scope(), tvb, offset, string_length, ENC_ASCII);
while ((c = g_utf8_strchr(log, string_length, '\n')))
*c = ' ';
while ((c = g_utf8_strchr(log, string_length, '\r')))
*c = ' ';
subitem = proto_tree_add_item(maintree, hf_logcat_log, tvb, offset, string_length, ENC_ASCII | ENC_NA);
subtree = proto_item_add_subtree(subitem, ett_logcat_log);
next_tvb = tvb_new_subset_length(tvb, offset, string_length - 1);
call_dissector(data_text_lines_handle, next_tvb, pinfo, subtree);
col_add_str(pinfo->cinfo, COL_INFO, log);
offset += string_length;
check_length += string_length;
if (length != check_length)
proto_tree_add_expert(maintree, pinfo, &ei_invalid_payload_length, tvb, offset, tvb_reported_length_remaining(tvb, offset));
if (have_tap_listener(exported_pdu_tap)) {
exp_pdu_data_t *exp_pdu_data;
exp_pdu_data = load_export_pdu_tags(pinfo, "logcat", -1, NULL, 0);
exp_pdu_data->tvb_captured_length = tvb_captured_length(tvb);
exp_pdu_data->tvb_reported_length = tvb_reported_length(tvb);
exp_pdu_data->pdu_tvb = tvb;
tap_queue_packet(exported_pdu_tap, pinfo, exp_pdu_data);
}
return offset;
}
void
proto_register_logcat(void)
{
expert_module_t *expert_module;
static hf_register_info hf[] = {
{ &hf_logcat_version,
{ "Logger Version", "logcat.logger_version",
FT_UINT8, BASE_DEC, NULL, 0x00,
NULL, HFILL }
},
{ &hf_logcat_length,
{ "Payload Length", "logcat.length",
FT_UINT16, BASE_DEC, NULL, 0x00,
"Payload start after nanoseconds or euid", HFILL }
},
{ &hf_logcat_padding,
{ "Padding", "logcat.padding",
FT_UINT16, BASE_HEX, NULL, 0x00,
"No matter what, we get 2 bytes of padding", HFILL }
},
{ &hf_logcat_header_size,
{ "Header Size", "logcat.header_size",
FT_UINT16, BASE_HEX, NULL, 0x00,
"Size of struct logger_entry_v2", HFILL }
},
{ &hf_logcat_pid,
{ "PID", "logcat.pid",
FT_INT32, BASE_DEC, NULL, 0x00,
"Process ID", HFILL }
},
{ &hf_logcat_tid,
{ "TID", "logcat.tid",
FT_INT32, BASE_DEC, NULL, 0x00,
"Thread ID", HFILL }
},
{ &hf_logcat_timestamp,
{ "Timestamp", "logcat.timestamp",
FT_ABSOLUTE_TIME, ABSOLUTE_TIME_LOCAL, NULL, 0x00,
NULL, HFILL }
},
{ &hf_logcat_timestamp_seconds,
{ "Timestamp in seconds", "logcat.timestamp.seconds",
FT_INT32, BASE_DEC, NULL, 0x00,
NULL, HFILL }
},
{ &hf_logcat_timestamp_nanoseconds,
{ "Nanoseconds Timestamp", "logcat.timestamp.nanoseconds",
FT_INT32, BASE_DEC, NULL, 0x00,
NULL, HFILL }
},
{ &hf_logcat_euid,
{ "EUID", "logcat.euid",
FT_UINT32, BASE_DEC, NULL, 0x00,
"Effective UID of logger", HFILL }
},
{ &hf_logcat_priority,
{ "Priority", "logcat.priority",
FT_UINT8, BASE_DEC, VALS(priority_vals), 0x00,
NULL, HFILL }
},
{ &hf_logcat_tag,
{ "Tag", "logcat.tag",
FT_STRINGZ, BASE_NONE, NULL, 0x00,
NULL, HFILL }
},
{ &hf_logcat_log,
{ "Log", "logcat.log",
FT_STRINGZ, BASE_NONE, NULL, 0x00,
NULL, HFILL }
}
};
static gint *ett[] = {
&ett_logcat,
&ett_logcat_timestamp,
&ett_logcat_log
};
static ei_register_info ei[] = {
{ &ei_invalid_payload_length, { "logcat.expert.invalid_payload_length", PI_PROTOCOL, PI_WARN, "Payload length does not meet sum of payload data length", EXPFILL }},
};
proto_logcat = proto_register_protocol("Android Logcat", "Logcat", "logcat");
proto_register_field_array(proto_logcat, hf, array_length(hf));
proto_register_subtree_array(ett, array_length(ett));
logcat_handle = new_register_dissector("logcat", dissect_logcat, proto_logcat);
expert_module = expert_register_protocol(proto_logcat);
expert_register_field_array(expert_module, ei, array_length(ei));
exported_pdu_tap = register_export_pdu_tap("Logcat");
}
void
proto_reg_handoff_logcat(void)
{
data_text_lines_handle = find_dissector("data-text-lines");
dissector_add_uint("wtap_encap", WTAP_ENCAP_LOGCAT, logcat_handle);
dissector_add_for_decode_as("tcp.port", logcat_handle);
}
