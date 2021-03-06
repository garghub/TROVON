static int get_priority(const gchar *frame, const gchar *token, tvbuff_t *tvb,
proto_tree *maintree, gint start_offset, packet_info *pinfo _U_) {
int prio;
gchar *p = g_strstr_len(frame + start_offset, -1, token);
int offset = (int)(p - frame);
switch (*p) {
case 'I':
prio = 4;
break;
case 'V':
prio = 2;
break;
case 'D':
prio = 3;
break;
case 'W':
prio = 5;
break;
case 'E':
prio = 6;
break;
case 'F':
prio = 7;
break;
default:
prio = 0;
}
proto_tree_add_uint(maintree, hf_logcat_text_priority, tvb, offset, 1, prio);
return offset + 1;
}
static int get_tag(const gchar *frame, const gchar *token, tvbuff_t *tvb,
proto_tree *maintree, gint start_offset, packet_info *pinfo) {
gchar *p = g_strstr_len(frame + start_offset, -1, token);
int offset = (int)(p - frame);
guint8 *src_addr = wmem_strdup(wmem_packet_scope(), token);
gint tok_len = (gint)strlen(token);
proto_tree_add_string(maintree, hf_logcat_text_tag, tvb, offset, tok_len,
token);
SET_ADDRESS(&pinfo->src, AT_STRINGZ, tok_len + 1, src_addr);
SET_ADDRESS(&pinfo->dst, AT_STRINGZ, sizeof(dissector_name), dissector_name);
return offset + tok_len;
}
static int get_ptid(const gchar *frame, const gchar *token, tvbuff_t *tvb,
proto_tree *maintree, gint header_field, gint start_offset) {
gchar *p = g_strstr_len(frame + start_offset, -1, token);
int offset = (int)(p - frame);
proto_tree_add_uint(maintree, header_field, tvb, offset, (gint)strlen(token),
(guint32)g_ascii_strtoull(token, NULL, 10));
return offset + (int)strlen(token);
}
static int get_pid(const gchar *frame, const gchar *token, tvbuff_t *tvb,
proto_tree *maintree, gint start_offset, packet_info *pinfo _U_) {
return get_ptid(frame, token, tvb, maintree, hf_logcat_text_pid, start_offset);
}
static int get_tid(const gchar *frame, const gchar *token, tvbuff_t *tvb,
proto_tree *maintree, gint start_offset, packet_info *pinfo _U_) {
return get_ptid(frame, token, tvb, maintree, hf_logcat_text_tid, start_offset);
}
static int get_log(const gchar *frame, const gchar *token, tvbuff_t *tvb,
proto_tree *maintree, gint start_offset, packet_info *pinfo) {
gchar *p = g_strstr_len(frame + start_offset, -1, token);
int offset = (int)(p - frame);
proto_tree_add_string(maintree, hf_logcat_text_log, tvb, offset,
(int)strlen(token), token);
col_add_str(pinfo->cinfo, COL_INFO, token);
return offset + (int)strlen(token);
}
static int get_time(const gchar *frame, const gchar *token, tvbuff_t *tvb,
proto_tree *maintree, gint start_offset, packet_info *pinfo) {
gint offset;
gchar *p;
gint ms;
struct tm date;
time_t seconds;
nstime_t ts;
p = g_strstr_len(frame + start_offset, -1, token);
offset = (int)(p - frame);
if (6 == sscanf(token, "%d-%d %d:%d:%d.%d", &date.tm_mon, &date.tm_mday,
&date.tm_hour, &date.tm_min, &date.tm_sec, &ms)) {
date.tm_year = 70;
date.tm_mon -= 1;
seconds = mktime(&date);
ts.secs = seconds;
ts.nsecs = (int) (ms * 1e6);
proto_tree_add_time(maintree, hf_logcat_text_timestamp, tvb, offset,
(int)strlen(token), &ts);
} else {
proto_tree_add_expert(maintree, pinfo, &ei_malformed_time, tvb, offset, -1);
}
return offset + (int)strlen(token);
}
static int dissect_logcat_text(tvbuff_t *tvb, proto_tree *tree, packet_info *pinfo,
const dissect_info_t *dinfo) {
gchar **tokens;
guint i;
gchar *frame = tvb_get_string_enc(wmem_packet_scope(), tvb, 0, tvb_captured_length(tvb),
ENC_ASCII);
proto_item *mainitem = proto_tree_add_item(tree, proto_logcat_text, tvb, 0, -1, ENC_NA);
proto_tree *maintree = proto_item_add_subtree(mainitem, ett_logcat);
gint offset = 0;
col_set_str(pinfo->cinfo, COL_PROTOCOL, dissector_name);
if (!g_regex_match(special_regex, frame, G_REGEX_MATCH_NOTEMPTY, NULL)) {
tokens = g_regex_split(*dinfo->regex, frame, G_REGEX_MATCH_NOTEMPTY);
if (NULL == tokens) return 0;
if (g_strv_length(tokens) != dinfo->no_of_getters + 2) {
proto_tree_add_expert(maintree, pinfo, &ei_malformed_token, tvb, offset, -1);
g_strfreev(tokens);
return 0;
}
for (i = 0; i < dinfo->no_of_getters; ++i) {
offset = ((*dinfo->getters[i])(frame, tokens[i + 1], tvb, maintree, offset, pinfo));
}
} else {
tokens = g_regex_split(special_regex, frame, G_REGEX_MATCH_NOTEMPTY);
if (NULL == tokens) return 0;
offset = get_log(frame, tokens[1], tvb, maintree, 0, pinfo);
}
g_strfreev(tokens);
return offset;
}
static int dissect_logcat_text_brief(tvbuff_t *tvb, packet_info *pinfo, proto_tree *tree,
void *data _U_) {
static const tGETTER getters[] = { get_priority, get_tag, get_pid, get_log };
dissect_info_t dinfo = { &brief_regex, getters, array_length(getters) };
return dissect_logcat_text(tvb, tree, pinfo, &dinfo);
}
static int dissect_logcat_text_tag(tvbuff_t *tvb, packet_info *pinfo, proto_tree *tree,
void *data _U_) {
static const tGETTER getters[] = { get_priority, get_tag, get_log };
dissect_info_t dinfo = { &tag_regex, getters, array_length(getters) };
return dissect_logcat_text(tvb, tree, pinfo, &dinfo);
}
static int dissect_logcat_text_process(tvbuff_t *tvb, packet_info *pinfo, proto_tree *tree,
void *data _U_) {
static const tGETTER getters[] = { get_priority, get_pid, get_log };
dissect_info_t dinfo = { &process_regex, getters, array_length(getters) };
SET_ADDRESS(&pinfo->dst, AT_STRINGZ, 0, "");
SET_ADDRESS(&pinfo->src, AT_STRINGZ, 0, "");
return dissect_logcat_text(tvb, tree, pinfo, &dinfo);
}
static int dissect_logcat_text_time(tvbuff_t *tvb, packet_info *pinfo, proto_tree *tree,
void *data _U_) {
static const tGETTER getters[] = { get_time, get_priority, get_tag, get_pid, get_log };
dissect_info_t dinfo = { &time_regex, getters, array_length(getters) };
return dissect_logcat_text(tvb, tree, pinfo, &dinfo);
}
static int dissect_logcat_text_thread(tvbuff_t *tvb, packet_info *pinfo, proto_tree *tree,
void *data _U_) {
static const tGETTER getters[] = { get_priority, get_pid, get_tid, get_log };
dissect_info_t dinfo = { &thread_regex, getters, array_length(getters) };
SET_ADDRESS(&pinfo->dst, AT_STRINGZ, 0, "");
SET_ADDRESS(&pinfo->src, AT_STRINGZ, 0, "");
return dissect_logcat_text(tvb, tree, pinfo, &dinfo);
}
static int dissect_logcat_text_threadtime(tvbuff_t *tvb, packet_info *pinfo, proto_tree *tree,
void *data _U_) {
static const tGETTER getters[] = { get_time, get_pid, get_tid, get_priority, get_tag, get_log };
dissect_info_t dinfo = { &threadtime_regex, getters, array_length(getters) };
return dissect_logcat_text(tvb, tree, pinfo, &dinfo);
}
static int dissect_logcat_text_long(tvbuff_t *tvb, packet_info *pinfo, proto_tree *tree,
void *data _U_) {
static const tGETTER getters[] = { get_time, get_pid, get_tid, get_priority, get_tag, get_log };
dissect_info_t dinfo = { &long_regex, getters, array_length(getters) };
return dissect_logcat_text(tvb, tree, pinfo, &dinfo);
}
void proto_register_logcat_text(void) {
expert_module_t *expert_module;
static hf_register_info hf[] = {
{ &hf_logcat_text_timestamp,
{ "Timestamp", "logcat_text.timestamp",
FT_ABSOLUTE_TIME, ABSOLUTE_TIME_LOCAL, NULL, 0x00, NULL, HFILL
}
},
{ &hf_logcat_text_tag,
{ "Tag", "logcat_text.tag",
FT_STRING, STR_ASCII, NULL, 0x00, NULL, HFILL
}
},
{ &hf_logcat_text_log,
{ "Log", "logcat_text.log",
FT_STRING, STR_ASCII, NULL, 0x00, NULL, HFILL
}
},
{ &hf_logcat_text_priority,
{ "Priority", "logcat_text.priority",
FT_UINT8, BASE_DEC, VALS(priority_vals), 0x00, NULL, HFILL
}
},
{ &hf_logcat_text_pid,
{ "PID", "logcat_text.pid",
FT_UINT32, BASE_DEC, NULL, 0x00, "Process ID", HFILL
}
},
{ &hf_logcat_text_tid,
{ "TID", "logcat_text.tid",
FT_UINT32, BASE_DEC, NULL, 0x00, "Thread ID", HFILL
}
}
};
static ei_register_info ei[] = {
{ &ei_malformed_time, { "logcat_text.malformed_time", PI_PROTOCOL, PI_ERROR, "Malformed time data", EXPFILL }},
{ &ei_malformed_token, { "logcat_text.malformed_token", PI_PROTOCOL, PI_ERROR, "Failed to decode one or more tokens", EXPFILL }},
};
static gint *ett[] = { &ett_logcat};
proto_logcat_text = proto_register_protocol("Android Logcat Text", dissector_name,
"logcat_text");
proto_register_field_array(proto_logcat_text, hf, array_length(hf));
proto_register_subtree_array(ett, array_length(ett));
logcat_text_brief_handle = new_register_dissector("logcat_text_brief",
dissect_logcat_text_brief, proto_logcat_text);
logcat_text_tag_handle = new_register_dissector("logcat_text_tag",
dissect_logcat_text_tag, proto_logcat_text);
logcat_text_time_handle = new_register_dissector("logcat_text_time",
dissect_logcat_text_time, proto_logcat_text);
logcat_text_process_handle = new_register_dissector("logcat_text_process",
dissect_logcat_text_process, proto_logcat_text);
logcat_text_thread_handle = new_register_dissector("logcat_text_thread",
dissect_logcat_text_thread, proto_logcat_text);
logcat_text_threadtime_handle = new_register_dissector("logcat_text_threadtime",
dissect_logcat_text_threadtime, proto_logcat_text);
logcat_text_long_handle = new_register_dissector("logcat_text_long",
dissect_logcat_text_long, proto_logcat_text);
special_regex = g_regex_new(SPECIAL_STRING, G_REGEX_ANCHORED, G_REGEX_MATCH_NOTEMPTY, NULL);
brief_regex = g_regex_new(BRIEF_STRING, G_REGEX_ANCHORED, G_REGEX_MATCH_NOTEMPTY, NULL);
tag_regex = g_regex_new(TAG_STRING, G_REGEX_ANCHORED, G_REGEX_MATCH_NOTEMPTY, NULL);
time_regex = g_regex_new(TIME_STRING, G_REGEX_ANCHORED, G_REGEX_MATCH_NOTEMPTY, NULL);
thread_regex = g_regex_new(THREAD_STRING, G_REGEX_ANCHORED, G_REGEX_MATCH_NOTEMPTY, NULL);
threadtime_regex = g_regex_new(THREADTIME_STRING, G_REGEX_ANCHORED, G_REGEX_MATCH_NOTEMPTY, NULL);
process_regex = g_regex_new(PROCESS_STRING, G_REGEX_ANCHORED, G_REGEX_MATCH_NOTEMPTY, NULL);
long_regex = g_regex_new(LONG_STRING, G_REGEX_MULTILINE, G_REGEX_MATCH_NOTEMPTY, NULL);
expert_module = expert_register_protocol(proto_logcat_text);
expert_register_field_array(expert_module, ei, array_length(ei));
}
void proto_reg_handoff_logcat_text(void) {
dissector_add_uint("wtap_encap", WTAP_ENCAP_LOGCAT_BRIEF,
logcat_text_brief_handle);
dissector_add_uint("wtap_encap", WTAP_ENCAP_LOGCAT_TAG,
logcat_text_tag_handle);
dissector_add_uint("wtap_encap", WTAP_ENCAP_LOGCAT_TIME,
logcat_text_time_handle);
dissector_add_uint("wtap_encap", WTAP_ENCAP_LOGCAT_THREAD,
logcat_text_thread_handle);
dissector_add_uint("wtap_encap", WTAP_ENCAP_LOGCAT_THREADTIME,
logcat_text_threadtime_handle);
dissector_add_uint("wtap_encap", WTAP_ENCAP_LOGCAT_PROCESS,
logcat_text_process_handle);
dissector_add_uint("wtap_encap", WTAP_ENCAP_LOGCAT_LONG,
logcat_text_long_handle);
}
