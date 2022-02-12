static void add_alert_to_session_tree(guint frame_number, Alert_t *alert)
{
Alerts_t *alerts = (Alerts_t*)wmem_tree_lookup32(current_session.alerts_tree, frame_number);
if (alerts == NULL) {
alerts = (Alerts_t*)g_malloc(sizeof(Alerts_t));
alerts->alerts[0] = *alert;
alerts->num_alerts = 1;
wmem_tree_insert32(current_session.alerts_tree, frame_number, alerts);
}
else {
if (alerts->num_alerts < MAX_ALERTS_PER_FRAME) {
alerts->alerts[alerts->num_alerts++] = *alert;
}
}
}
static void fill_alert_config(SnortConfig_t *snort_config, Alert_t *alert)
{
guint global_match_number=0, rule_match_number=0;
alert->matched_rule = get_rule(snort_config, alert->sid);
if (pref_snort_alerts_source == FromUserComments) {
alert->classification = g_strdup(alert->matched_rule->classtype);
}
rule_set_alert(snort_config, alert->matched_rule,
&global_match_number, &rule_match_number);
alert->overall_match_number = global_match_number;
alert->rule_match_number = rule_match_number;
}
static gboolean content_compare_case_sensitive(const guint8* memory, const char* target, guint length)
{
return (memcmp(memory, target, length) == 0);
}
static gboolean content_compare_case_insensitive(const guint8* memory, const char* target, guint length)
{
for (guint n=0; n < length; n++) {
if (g_ascii_isalpha(target[n])) {
if (g_ascii_toupper(memory[n]) != g_ascii_toupper(target[n])) {
return FALSE;
}
}
else {
if ((guint8)memory[n] != (guint8)target[n]) {
return FALSE;
}
}
}
return TRUE;
}
static gboolean look_for_pcre(content_t *content, tvbuff_t *tvb, guint start_offset, guint *match_offset, guint *match_length)
{
GRegex *regex;
GMatchInfo *match_info;
gboolean match_found = FALSE;
GRegexCompileFlags regex_compile_flags = (GRegexCompileFlags)0;
if (!content_convert_pcre_for_regex(content)) {
return FALSE;
}
int length_remaining = tvb_captured_length_remaining(tvb, start_offset);
gchar *string = (gchar*)g_malloc(length_remaining + 1);
tvb_memcpy(tvb, (void*)string, start_offset, length_remaining);
string[length_remaining] = '\0';
if (content->pcre_case_insensitive) {
regex_compile_flags = (GRegexCompileFlags)(regex_compile_flags | G_REGEX_CASELESS);
}
if (content->pcre_dot_includes_newline) {
regex_compile_flags = (GRegexCompileFlags)(regex_compile_flags | G_REGEX_DOTALL);
}
if (content->pcre_raw) {
regex_compile_flags = (GRegexCompileFlags)(regex_compile_flags | G_REGEX_RAW);
}
if (content->pcre_multiline) {
regex_compile_flags = (GRegexCompileFlags)(regex_compile_flags | G_REGEX_MULTILINE);
}
regex = g_regex_new(content->translated_str,
regex_compile_flags,
(GRegexMatchFlags)0, NULL);
g_regex_match(regex, string, (GRegexMatchFlags)0, &match_info);
if (g_match_info_matches(match_info)) {
gint start_pos, end_pos;
g_match_info_fetch_pos(match_info,
0,
&start_pos, &end_pos);
*match_offset = start_offset + start_pos;
*match_length = end_pos - start_pos;
match_found = TRUE;
}
g_match_info_free(match_info);
g_regex_unref(regex);
g_free(string);
return match_found;
}
static gboolean look_for_content(content_t *content, tvbuff_t *tvb, guint start_offset, guint *match_offset, guint *match_length)
{
gint tvb_len = tvb_captured_length(tvb);
guint converted_content_length = content_convert_to_binary(content);
for (guint m=start_offset; m <= (tvb_len-converted_content_length); m++) {
const guint8 *ptr = tvb_get_ptr(tvb, m, converted_content_length);
if (content->nocase) {
if (content_compare_case_insensitive(ptr, content->translated_str, content->translated_length)) {
*match_offset = m;
*match_length = content->translated_length;
return TRUE;
}
}
else {
if (content_compare_case_sensitive(ptr, content->translated_str, content->translated_length)) {
*match_offset = m;
*match_length = content->translated_length;
return TRUE;
}
}
}
return FALSE;
}
static gboolean get_content_match(Alert_t *alert, guint content_idx,
tvbuff_t *tvb, guint content_start_match,
guint *match_offset, guint *match_length)
{
content_t *content;
Rule_t *rule = alert->matched_rule;
if (rule == NULL) {
return FALSE;
}
content = &(rule->contents[content_idx]);
if (content->content_type == Pcre) {
return look_for_pcre(content, tvb, content_start_match, match_offset, match_length);
}
else {
return look_for_content(content, tvb, content_start_match, match_offset, match_length);
}
}
static void snort_reaper(GPid pid, gint status _U_, gpointer data)
{
snort_session_t *session = (snort_session_t *)data;
if (session->running && session->pid == pid) {
session->working = session->running = FALSE;
} else {
g_print("Errrrmm snort_reaper() %d != %d\n", session->pid, pid);
}
g_spawn_close_pid(pid);
}
static const char* snort_parse_ts(const char *ts, guint32 *frame_number)
{
struct tm tm;
unsigned int usec;
memset(&tm, 0, sizeof(tm));
tm.tm_isdst = -1;
if (sscanf(ts, "%02d/%02d/%02d-%02d:%02d:%02d.%06u ",
&(tm.tm_mon), &(tm.tm_mday), &(tm.tm_year), &(tm.tm_hour), &(tm.tm_min), &(tm.tm_sec), &usec) != 7) {
return NULL;
}
tm.tm_mon -= 1;
tm.tm_year += 100;
*frame_number = usec;
return strchr(ts, ' ');
}
static gboolean snort_parse_fast_line(const char *line, Alert_t *alert)
{
static const char stars[] = " [**] ";
static const char classification[] = "[Classification: ";
static const char priority[] = "[Priority: ";
const char *tmp_msg;
if (!(line = snort_parse_ts(line, &(alert->original_frame)))) {
return FALSE;
}
if (!g_str_has_prefix(line+1, stars)) {
return FALSE;
}
line += sizeof(stars);
if (sscanf(line, "[%u:%u:%u] ", &(alert->gen), &(alert->sid), &(alert->rev)) != 3) {
return FALSE;
}
if (!(line = strchr(line, ' '))) {
return FALSE;
}
tmp_msg = line+1;
if (!(line = strstr(line, stars))) {
return FALSE;
}
alert->msg = g_strndup(tmp_msg, line - tmp_msg);
line += (sizeof(stars)-1);
if (g_str_has_prefix(line, classification)) {
char *tmp;
line += (sizeof(classification)-1);
if (!(tmp = (char*)strstr(line, "] [Priority: "))) {
return FALSE;
}
alert->classification = g_strndup(line, tmp - line);
line = tmp+2;
} else
alert->classification = NULL;
if (alert->classification || g_str_has_prefix(line, priority)) {
line += (sizeof(priority)-1);
if ((sscanf(line, "%d", &(alert->prio))) != 1) {
return FALSE;
}
if (!(line = strstr(line, "] "))) {
return FALSE;
}
} else {
alert->prio = -1;
}
return TRUE;
}
static gboolean snort_parse_user_comment(const char *line, Alert_t *alert)
{
if (sscanf(line, "%u:%u:%u", &(alert->gen), &(alert->sid), &(alert->rev)) != 3) {
return FALSE;
}
if (!(line = strstr(line, " - "))) {
return FALSE;
}
alert->msg = g_strdup(line);
return TRUE;
}
static gboolean snort_fast_output(GIOChannel *source, GIOCondition condition, gpointer data)
{
snort_session_t *session = (snort_session_t *)data;
while (condition & G_IO_IN) {
GIOStatus status;
char _buf[1024];
gsize len = 0;
char *old_buf = NULL;
char *buf = _buf;
char *line;
status = g_io_channel_read_chars(source, _buf, sizeof(_buf)-1, &len, NULL);
if (status != G_IO_STATUS_NORMAL) {
if (status == G_IO_STATUS_AGAIN) {
condition = (GIOCondition)(condition & ~G_IO_IN);
break;
}
return FALSE;
}
buf[len] = '\0';
if (session->buf) {
g_string_append(session->buf, buf);
buf = old_buf = g_string_free(session->buf, FALSE);
session->buf = NULL;
}
while ((line = strchr(buf, '\n'))) {
Alert_t alert;
memset(&alert, 0, sizeof(alert));
*line = '\0';
if (snort_parse_fast_line(buf, &alert)) {
#if 0
g_print("%ld.%lu [%u,%u,%u] %s {%s} [%d]\n",
alert.tv.tv_sec, alert.tv.tv_usec,
alert.gen, alert.sid, alert.rev,
alert.msg,
alert.classification ? alert.classification : "(null)",
alert.prio);
#endif
alert.raw_alert = g_strdup(buf);
fill_alert_config(g_snort_config, &alert);
add_alert_to_session_tree((guint)alert.original_frame, &alert);
}
else {
g_print("snort_fast_output() line: '%s'\n", buf);
}
buf = line+1;
}
if (buf[0]) {
session->buf = g_string_new(buf);
}
g_free(old_buf);
}
if (condition) {
return FALSE;
}
return TRUE;
}
static guint get_protocol_payload_start(const char *protocol, proto_tree *tree)
{
guint value = 0;
gboolean look_after_protocol = (strcmp(protocol, "icmp") != 0);
if (tree != NULL) {
GPtrArray *items = proto_all_finfos(tree);
if (items) {
guint i;
for (i=0; i< items->len; i++) {
field_info *field = (field_info *)g_ptr_array_index(items,i);
if (strcmp(field->hfinfo->abbrev, protocol) == 0) {
value = field->start;
if (look_after_protocol) {
value += field->length;
}
break;
}
}
g_ptr_array_free(items,TRUE);
}
}
return value;
}
static guint get_content_start_match(Rule_t *rule, proto_tree *tree)
{
return get_protocol_payload_start(rule->protocol, tree);
}
static guint get_reassembled_in_frame(proto_tree *tree)
{
guint value = 0;
if (tree != NULL) {
GPtrArray *items = proto_all_finfos(tree);
if (items) {
guint i;
for (i=0; i< items->len; i++) {
field_info *field = (field_info *)g_ptr_array_index(items,i);
if (strcmp(field->hfinfo->abbrev, "tcp.reassembled_in") == 0) {
value = field->value.value.uinteger;
break;
}
}
g_ptr_array_free(items,TRUE);
}
}
return value;
}
static void snort_show_alert(proto_tree *tree, tvbuff_t *tvb, packet_info *pinfo, Alert_t *alert)
{
proto_tree *snort_tree = NULL;
guint n;
proto_item *ti, *rule_ti;
proto_tree *rule_tree;
Rule_t *rule = alert->matched_rule;
if (snort_alert_in_reassembled_frame && pinfo->fd->flags.visited && (tree != NULL)) {
guint reassembled_frame = get_reassembled_in_frame(tree);
if (reassembled_frame && (reassembled_frame != pinfo->num)) {
Alerts_t *alerts;
alerts = (Alerts_t*)wmem_tree_lookup32(current_session.alerts_tree, pinfo->num);
if (!alerts->alerts[0].reassembled_frame) {
for (n=0; n < alerts->num_alerts; n++) {
alerts->alerts[n].original_frame = pinfo->num;
alerts->alerts[n].reassembled_frame = reassembled_frame;
add_alert_to_session_tree(reassembled_frame, &alerts->alerts[n]);
}
}
}
}
guint content_start_match = 0;
guint payload_start = 0;
if (rule) {
payload_start = content_start_match = get_content_start_match(rule, tree);
}
proto_item *alert_ti = proto_tree_add_protocol_format(tree, proto_snort, tvb,
content_start_match >= tvb_captured_length(tvb) ? 0 : content_start_match,
content_start_match >= tvb_captured_length(tvb) ? 0 : -1,
"Snort: (msg: \"%s\" sid: %u rev: %u) [from %s]",
alert->msg, alert->sid, alert->rev,
(pref_snort_alerts_source == FromUserComments) ?
"User Comment" :
"Running Snort");
snort_tree = proto_item_add_subtree(alert_ti, ett_snort);
if (snort_alert_in_reassembled_frame && (alert->reassembled_frame != 0)) {
if (alert->original_frame == pinfo->num) {
ti = proto_tree_add_uint(tree, hf_snort_reassembled_in, tvb, 0, 0,
alert->reassembled_frame);
PROTO_ITEM_SET_GENERATED(ti);
return;
}
else {
tvbuff_t *reassembled_tvb;
ti = proto_tree_add_uint(tree, hf_snort_reassembled_from, tvb, 0, 0,
alert->original_frame);
PROTO_ITEM_SET_GENERATED(ti);
reassembled_tvb = get_data_source_tvb_by_name(pinfo, "Reassembled TCP");
if (reassembled_tvb) {
tvb = reassembled_tvb;
}
}
}
if (snort_show_alert_expert_info) {
expert_add_info_format(pinfo, alert_ti, &ei_snort_alert, "Alert %u: \"%s\"", alert->sid, alert->msg);
}
if (rule) {
if (!alert->raw_alert_ts_fixed) {
char digits[7];
g_snprintf(digits, 7, "%06u", pinfo->abs_ts.nsecs / 1000);
memcpy(alert->raw_alert+18, digits, 6);
alert->raw_alert_ts_fixed = TRUE;
}
ti = proto_tree_add_string(snort_tree, hf_snort_raw_alert, tvb, 0, 0, alert->raw_alert);
PROTO_ITEM_SET_GENERATED(ti);
}
if (alert->classification) {
ti = proto_tree_add_string(snort_tree, hf_snort_classification, tvb, 0, 0, alert->classification);
PROTO_ITEM_SET_GENERATED(ti);
}
rule_ti = proto_tree_add_string_format(snort_tree, hf_snort_rule, tvb, 0, 0, "", "Rule");
PROTO_ITEM_SET_GENERATED(rule_ti);
rule_tree = proto_item_add_subtree(rule_ti, ett_snort_rule);
ti = proto_tree_add_string(rule_tree, hf_snort_msg, tvb, 0, 0, alert->msg);
PROTO_ITEM_SET_GENERATED(ti);
ti = proto_tree_add_uint(rule_tree, hf_snort_sid, tvb, 0, 0, alert->sid);
PROTO_ITEM_SET_GENERATED(ti);
ti = proto_tree_add_uint(rule_tree, hf_snort_rev, tvb, 0, 0, alert->rev);
PROTO_ITEM_SET_GENERATED(ti);
ti = proto_tree_add_uint(rule_tree, hf_snort_generator, tvb, 0, 0, alert->gen);
PROTO_ITEM_SET_GENERATED(ti);
ti = proto_tree_add_uint(rule_tree, hf_snort_priority, tvb, 0, 0, alert->prio);
PROTO_ITEM_SET_GENERATED(ti);
if (rule && rule->rule_string) {
size_t rule_string_length = strlen(rule->rule_string);
if (rule_string_length > 60) {
tvbuff_t *rule_string_tvb = tvb_new_child_real_data(tvb, rule->rule_string,
(guint)rule_string_length,
(guint)rule_string_length);
add_new_data_source(pinfo, rule_string_tvb, "Rule String");
ti = proto_tree_add_string(rule_tree, hf_snort_rule_string, rule_string_tvb, 0,
(gint)rule_string_length,
rule->rule_string);
}
else {
ti = proto_tree_add_string(rule_tree, hf_snort_rule_string, tvb, 0, 0,
rule->rule_string);
}
PROTO_ITEM_SET_GENERATED(ti);
ti = proto_tree_add_string(rule_tree, hf_snort_rule_protocol, tvb, 0, 0, rule->protocol);
PROTO_ITEM_SET_GENERATED(ti);
ti = proto_tree_add_string(rule_tree, hf_snort_rule_filename, tvb, 0, 0, rule->file);
PROTO_ITEM_SET_GENERATED(ti);
ti = proto_tree_add_uint(rule_tree, hf_snort_rule_line_number, tvb, 0, 0, rule->line_number);
PROTO_ITEM_SET_GENERATED(ti);
for (n=0; n < rule->relevant_vars.num_ip_vars; n++) {
ti = proto_tree_add_none_format(rule_tree, hf_snort_rule_ip_var, tvb, 0, 0, "IP Var: ($%s -> %s)",
rule->relevant_vars.ip_vars[n].name,
rule->relevant_vars.ip_vars[n].value);
PROTO_ITEM_SET_GENERATED(ti);
}
for (n=0; n < rule->relevant_vars.num_port_vars; n++) {
ti = proto_tree_add_none_format(rule_tree, hf_snort_rule_port_var, tvb, 0, 0, "Port Var: ($%s -> %s)",
rule->relevant_vars.port_vars[n].name,
rule->relevant_vars.port_vars[n].value);
PROTO_ITEM_SET_GENERATED(ti);
}
}
proto_item_append_text(rule_ti, " %s (sid=%u, rev=%u)",
alert->msg, alert->sid, alert->rev);
if (rule) {
guint content_last_match_end = 0;
rule_set_relevant_vars(g_snort_config, rule);
for (n=0; n < rule->number_contents; n++) {
unsigned int content_offset = 0;
gboolean match_found = FALSE;
unsigned int converted_content_length = 0;
int content_hf_item;
char *content_text_template;
gboolean attempt_match;
switch (rule->contents[n].content_type) {
case Content:
content_hf_item = hf_snort_content;
content_text_template = "Content: \"%s\"";
attempt_match = TRUE;
break;
case UriContent:
content_hf_item = hf_snort_uricontent;
content_text_template = "Uricontent: \"%s\"";
attempt_match = TRUE;
break;
case Pcre:
content_hf_item = hf_snort_pcre;
content_text_template = "Pcre: \"%s\"";
attempt_match = TRUE;
break;
default:
continue;
}
if (attempt_match && !rule->contents[n].negation) {
guint distance_to_add = 0;
if (rule->contents[n].offset_set) {
content_start_match = payload_start + rule->contents[n].offset;
}
else if (rule->contents[n].distance_set) {
distance_to_add = (content_last_match_end-content_start_match) + rule->contents[n].distance;
}
else {
content_start_match = payload_start;
}
match_found = get_content_match(alert, n,
tvb, content_start_match+distance_to_add,
&content_offset, &converted_content_length);
if (match_found) {
content_last_match_end = content_offset + converted_content_length;
}
}
ti = proto_tree_add_string_format(snort_tree, content_hf_item, tvb,
(match_found) ? content_offset : 0,
(match_found) ? converted_content_length : 0,
rule->contents[n].str,
content_text_template,
rule->contents[n].str);
if (match_found) {
content_start_match = content_last_match_end;
}
if (!attempt_match) {
proto_item_append_text(ti, " (no match attempt made)");
}
if (rule->contents[n].fastpattern) {
proto_item_append_text(ti, " (fast_pattern)");
}
if (rule->contents[n].rawbytes) {
proto_item_append_text(ti, " (rawbytes)");
}
if (rule->contents[n].nocase) {
proto_item_append_text(ti, " (nocase)");
}
if (rule->contents[n].negation) {
proto_item_append_text(ti, " (negated)");
}
if (rule->contents[n].offset_set) {
proto_item_append_text(ti, " (offset=%d)", rule->contents[n].offset);
}
if (rule->contents[n].depth != 0) {
proto_item_append_text(ti, " (depth=%u)", rule->contents[n].depth);
}
if (rule->contents[n].distance_set) {
proto_item_append_text(ti, " (distance=%d)", rule->contents[n].distance);
}
if (rule->contents[n].within != 0) {
proto_item_append_text(ti, " (within=%u)", rule->contents[n].within);
}
if (rule->contents[n].http_method != 0) {
proto_item_append_text(ti, " (http_method)");
}
if (rule->contents[n].http_client_body != 0) {
proto_item_append_text(ti, " (http_client_body)");
}
if (rule->contents[n].http_cookie != 0) {
proto_item_append_text(ti, " (http_cookie)");
}
if (rule->contents[n].http_user_agent != 0) {
proto_item_append_text(ti, " (http_user_agent)");
}
if (attempt_match && !rule->contents[n].negation && !match_found) {
proto_item_append_text(ti, " - not located");
expert_add_info_format(pinfo, ti, &ei_snort_content_not_matched,
"%s \"%s\" not found in frame",
rule->contents[n].content_type==Pcre ? "PCRE" : "Content",
rule->contents[n].str);
}
}
for (n=0; n < rule->number_references; n++) {
ti = proto_tree_add_string(snort_tree, hf_snort_reference, tvb, 0, 0,
expand_reference(g_snort_config, rule->references[n]));
PROTO_ITEM_SET_URL(ti);
PROTO_ITEM_SET_GENERATED(ti);
}
}
if (snort_show_rule_stats) {
unsigned int number_rule_files, number_rules, alerts_detected, this_rule_alerts_detected;
proto_item *stats_ti;
proto_tree *stats_tree;
stats_ti = proto_tree_add_string_format(snort_tree, hf_snort_global_stats, tvb, 0, 0, "", "Global Stats");
PROTO_ITEM_SET_GENERATED(rule_ti);
stats_tree = proto_item_add_subtree(stats_ti, ett_snort_global_stats);
get_global_rule_stats(g_snort_config, alert->sid, &number_rule_files, &number_rules, &alerts_detected,
&this_rule_alerts_detected);
ti = proto_tree_add_uint(stats_tree, hf_snort_global_stats_rule_file_count, tvb, 0, 0, number_rule_files);
PROTO_ITEM_SET_GENERATED(ti);
ti = proto_tree_add_uint(stats_tree, hf_snort_global_stats_rule_count, tvb, 0, 0, number_rules);
PROTO_ITEM_SET_GENERATED(ti);
ti = proto_tree_add_uint(stats_tree, hf_snort_global_stats_total_alerts_count, tvb, 0, 0, alerts_detected);
PROTO_ITEM_SET_GENERATED(ti);
ti = proto_tree_add_uint(stats_tree, hf_snort_global_stats_alert_match_number, tvb, 0, 0, alert->overall_match_number);
PROTO_ITEM_SET_GENERATED(ti);
if (rule) {
ti = proto_tree_add_uint(stats_tree, hf_snort_global_stats_rule_alerts_count, tvb, 0, 0, this_rule_alerts_detected);
PROTO_ITEM_SET_GENERATED(ti);
ti = proto_tree_add_uint(stats_tree, hf_snort_global_stats_rule_match_number, tvb, 0, 0, alert->rule_match_number);
PROTO_ITEM_SET_GENERATED(ti);
proto_item_append_text(stats_ti, " (%u rules from %u files, #%u of %u alerts seen (%u/%u for sid %u))",
number_rules, number_rule_files, alert->overall_match_number, alerts_detected,
alert->rule_match_number, this_rule_alerts_detected, alert->sid);
}
else {
proto_item_append_text(stats_ti, " (%u rules from %u files, #%u of %u alerts seen)",
number_rules, number_rule_files, alert->overall_match_number, alerts_detected);
}
}
}
static const char *get_user_comment_string(proto_tree *tree)
{
const char *value = NULL;
if (tree != NULL) {
GPtrArray *items = proto_all_finfos(tree);
if (items) {
guint i;
for (i=0; i< items->len; i++) {
field_info *field = (field_info *)g_ptr_array_index(items,i);
if (strcmp(field->hfinfo->abbrev, "frame.comment") == 0) {
value = field->value.value.string;
break;
}
if (strncmp(field->hfinfo->abbrev, "pkt_comment", 11) != 0) {
break;
}
}
g_ptr_array_free(items,TRUE);
}
}
return value;
}
static int
snort_dissector(tvbuff_t *tvb, packet_info *pinfo, proto_tree *tree, void *data _U_)
{
Alerts_t *alerts;
if (pref_snort_alerts_source == FromNowhere) {
return 0;
}
else if (pref_snort_alerts_source == FromUserComments) {
const char *alert_string = get_user_comment_string(tree);
if (alert_string) {
alerts = (Alerts_t*)wmem_tree_lookup32(current_session.alerts_tree, pinfo->num);
if (!alerts) {
Alert_t alert;
memset(&alert, 0, sizeof(alert));
if (snort_parse_user_comment(alert_string, &alert)) {
alert.raw_alert = g_strdup(alert_string);
fill_alert_config(g_snort_config, &alert);
add_alert_to_session_tree(pinfo->num, &alert);
}
}
}
}
else {
if (!pinfo->fd->flags.visited && current_session.working) {
int write_err = 0;
gchar *err_info;
struct wtap_pkthdr wtp;
if (!current_session.pdh) {
int open_err;
current_session.pdh = wtap_dump_fdopen(current_session.in,
WTAP_FILE_TYPE_SUBTYPE_PCAP,
pinfo->pkt_encap,
WTAP_MAX_PACKET_SIZE_STANDARD,
FALSE,
&open_err);
if (!current_session.pdh) {
current_session.working = FALSE;
return 0;
}
}
memcpy(&wtp, pinfo->phdr, sizeof(wtp));
wtp.ts = pinfo->fd->abs_ts;
wtp.ts.nsecs = pinfo->fd->num * 1000;
wtp.caplen = tvb_captured_length(tvb);
wtp.len = tvb_reported_length(tvb);
wtp.pkt_encap = pinfo->pkt_encap;
if (current_session.pdh->encap != wtp.pkt_encap) {
}
if (!wtap_dump(current_session.pdh, &wtp, tvb_get_ptr(tvb, 0, tvb_reported_length(tvb)), &write_err, &err_info)) {
current_session.working = FALSE;
return 0;
}
wtap_dump_flush(current_session.pdh);
}
}
if (current_session.alerts_tree && (alerts = (Alerts_t*)wmem_tree_lookup32(current_session.alerts_tree, pinfo->fd->num))) {
guint n;
for (n=0; n < alerts->num_alerts; n++) {
snort_show_alert(tree, tvb, pinfo, &(alerts->alerts[n]));
}
} else {
}
return tvb_reported_length(tvb);
}
static void snort_start(void)
{
GIOChannel *channel;
const gchar *argv[] = {
pref_snort_binary_filename, "-c", pref_snort_config_filename,
"-r", "-",
"-N",
"-A", "console", "-q",
"-y",
NULL
};
if ((pref_snort_alerts_source == FromNowhere) ||
!proto_is_protocol_enabled(find_protocol_by_id(proto_snort))) {
return;
}
current_session.alerts_tree = wmem_tree_new_autoreset(wmem_epan_scope(), wmem_file_scope());
if (g_snort_config) {
delete_config(&g_snort_config);
}
create_config(&g_snort_config, pref_snort_config_filename);
if (pref_snort_alerts_source == FromUserComments) {
return;
}
if (current_session.running) {
return;
}
current_session.running = TRUE;
reset_global_rule_stats(g_snort_config);
if (!snort_config_ok) {
current_session.running = FALSE;
return;
}
if (!g_spawn_async_with_pipes(NULL,
(char **)argv,
NULL,
(GSpawnFlags)( G_SPAWN_DO_NOT_REAP_CHILD),
NULL,
NULL,
&current_session.pid,
&current_session.in,
&current_session.out,
&current_session.err,
NULL))
{
current_session.running = FALSE;
current_session.working = FALSE;
return;
}
g_child_watch_add(current_session.pid, snort_reaper, &current_session);
channel = g_io_channel_unix_new(current_session.out);
current_session.channel = channel;
g_io_channel_set_encoding(channel, NULL, NULL);
g_io_channel_set_buffered(channel, FALSE);
g_io_channel_set_flags(channel, G_IO_FLAG_NONBLOCK, NULL);
g_io_channel_set_buffer_size(channel, 256000);
current_session.buf = NULL;
g_io_add_watch_full(channel,
G_PRIORITY_HIGH,
(GIOCondition)(G_IO_IN|G_IO_ERR|G_IO_HUP),
snort_fast_output,
&current_session,
NULL);
current_session.working = TRUE;
}
static void snort_cleanup(void)
{
if (!current_session.running) {
return;
}
if (current_session.pdh) {
int write_err;
if (!wtap_dump_close(current_session.pdh, &write_err)) {
}
current_session.pdh = NULL;
}
}
static void snort_file_cleanup(void)
{
if (g_snort_config) {
delete_config(&g_snort_config);
}
}
void
proto_reg_handoff_snort(void)
{
GArray *wanted_hfids = g_array_new(FALSE, FALSE, (guint)sizeof(int));
int id = proto_registrar_get_id_byname("tcp.reassembled_in");
g_array_append_val(wanted_hfids, id);
set_postdissector_wanted_hfids(snort_handle, wanted_hfids);
}
void
proto_register_snort(void)
{
static hf_register_info hf[] = {
{ &hf_snort_sid,
{ "Rule SID", "snort.sid", FT_UINT32, BASE_DEC, NULL, 0x00,
"Snort Rule identifier", HFILL }},
{ &hf_snort_raw_alert,
{ "Raw Alert", "snort.raw-alert", FT_STRING, BASE_NONE, NULL, 0x00,
"Full text of Snort alert", HFILL }},
{ &hf_snort_rule,
{ "Rule", "snort.rule", FT_STRING, BASE_NONE, NULL, 0x00,
"Entire Snort rule string", HFILL }},
{ &hf_snort_msg,
{ "Alert Message", "snort.msg", FT_STRINGZ, BASE_NONE, NULL, 0x00,
"Description of what the rule detects", HFILL }},
{ &hf_snort_classification,
{ "Alert Classification", "snort.class", FT_STRINGZ, BASE_NONE, NULL, 0x00,
NULL, HFILL }},
{ &hf_snort_priority,
{ "Alert Priority", "snort.priority", FT_UINT32, BASE_DEC, NULL, 0x00,
NULL, HFILL }},
{ &hf_snort_generator,
{ "Rule Generator", "snort.generator", FT_UINT32, BASE_DEC, NULL, 0x00,
NULL, HFILL }},
{ &hf_snort_rev,
{ "Rule Revision", "snort.rev", FT_UINT32, BASE_DEC, NULL, 0x00,
NULL, HFILL }},
{ &hf_snort_rule_string,
{ "Rule String", "snort.rule-string", FT_STRINGZ, BASE_NONE, NULL, 0x00,
"Full text of Snort rule", HFILL }},
{ &hf_snort_rule_protocol,
{ "Protocol", "snort.protocol", FT_STRINGZ, BASE_NONE, NULL, 0x00,
"Protocol name as given in the rule", HFILL }},
{ &hf_snort_rule_filename,
{ "Rule Filename", "snort.rule-filename", FT_STRINGZ, BASE_NONE, NULL, 0x00,
"Rules file where Snort rule was parsed from", HFILL }},
{ &hf_snort_rule_line_number,
{ "Line number within rules file where rule was parsed from", "snort.rule-line-number", FT_UINT32, BASE_DEC, NULL, 0x00,
NULL, HFILL }},
{ &hf_snort_rule_ip_var,
{ "IP variable", "snort.rule-ip-var", FT_NONE, BASE_NONE, NULL, 0x00,
"IP variable used in rule", HFILL }},
{ &hf_snort_rule_port_var,
{ "Port variable used in rule", "snort.rule-port-var", FT_NONE, BASE_NONE, NULL, 0x00,
NULL, HFILL }},
{ &hf_snort_reassembled_in,
{ "Reassembled frame where alert is shown", "snort.reassembled_in", FT_FRAMENUM, BASE_NONE, NULL, 0x00,
NULL, HFILL }},
{ &hf_snort_reassembled_from,
{ "Segment where alert was triggered", "snort.reassembled_from", FT_FRAMENUM, BASE_NONE, NULL, 0x00,
NULL, HFILL }},
{ &hf_snort_content,
{ "Content", "snort.content", FT_STRINGZ, BASE_NONE, NULL, 0x00,
"Snort content field", HFILL }},
{ &hf_snort_uricontent,
{ "URI Content", "snort.uricontent", FT_STRINGZ, BASE_NONE, NULL, 0x00,
"Snort URI content field", HFILL }},
{ &hf_snort_pcre,
{ "PCRE", "snort.pcre", FT_STRINGZ, BASE_NONE, NULL, 0x00,
"Perl Compatible Regular Expression", HFILL }},
{ &hf_snort_reference,
{ "Reference", "snort.reference", FT_STRINGZ, BASE_NONE, NULL, 0x00,
"Web reference provided as part of rule", HFILL }},
{ &hf_snort_global_stats,
{ "Global Stats", "snort.global-stats", FT_STRING, BASE_NONE, NULL, 0x00,
"Global statistics for rules and alerts", HFILL }},
{ &hf_snort_global_stats_rule_file_count,
{ "Number of rule files", "snort.global-stats.rule-file-count", FT_UINT32, BASE_DEC, NULL, 0x00,
"Total number of rules files found in Snort config", HFILL }},
{ &hf_snort_global_stats_rule_count,
{ "Number of rules", "snort.global-stats.rule-count", FT_UINT32, BASE_DEC, NULL, 0x00,
"Total number of rules found in Snort config", HFILL }},
{ &hf_snort_global_stats_total_alerts_count,
{ "Number of alerts detected", "snort.global-stats.total-alerts", FT_UINT32, BASE_DEC, NULL, 0x00,
"Total number of alerts detected in this capture", HFILL }},
{ &hf_snort_global_stats_alert_match_number,
{ "Match number", "snort.global-stats.match-number", FT_UINT32, BASE_DEC, NULL, 0x00,
"Number of match for this alert among all alerts", HFILL }},
{ &hf_snort_global_stats_rule_alerts_count,
{ "Number of alerts for this rule", "snort.global-stats.rule.match-number", FT_UINT32, BASE_DEC, NULL, 0x00,
"Number of alerts detected for this rule", HFILL }},
{ &hf_snort_global_stats_rule_match_number,
{ "Match number for this rule", "snort.global-stats.rule.match-number", FT_UINT32, BASE_DEC, NULL, 0x00,
"Number of match for this alert among those for this rule", HFILL }}
};
static gint *ett[] = {
&ett_snort,
&ett_snort_rule,
&ett_snort_global_stats
};
static const enum_val_t alerts_source_vals[] = {
{"from-nowhere", "Not looking for Snort alerts", FromNowhere},
{"from-running-snort", "From running Snort", FromRunningSnort},
{"from-user-comments", "From user comments", FromUserComments},
{NULL, NULL, -1}
};
static ei_register_info ei[] = {
{ &ei_snort_alert, { "snort.alert.expert", PI_SECURITY, PI_WARN, "Snort alert detected", EXPFILL }},
{ &ei_snort_content_not_matched, { "snort.content.not-matched", PI_PROTOCOL, PI_NOTE, "Failed to find content field of alert in frame", EXPFILL }},
};
expert_module_t* expert_snort;
module_t *snort_module;
proto_snort = proto_register_protocol("Snort Alerts", "Snort", "snort");
proto_register_field_array(proto_snort, hf, array_length(hf));
proto_register_subtree_array(ett, array_length(ett));
expert_snort = expert_register_protocol(proto_snort);
expert_register_field_array(expert_snort, ei, array_length(ei));
snort_module = prefs_register_protocol(proto_snort, NULL);
prefs_register_obsolete_preference(snort_module, "enable_snort_dissector");
prefs_register_enum_preference(snort_module, "alerts_source",
"Source of Snort alerts",
"Set whether dissector should run Snort itself or use user packet comments",
&pref_snort_alerts_source, alerts_source_vals, FALSE);
prefs_register_filename_preference(snort_module, "binary",
"Snort binary",
"The name of the snort binary file to run",
&pref_snort_binary_filename, FALSE);
prefs_register_filename_preference(snort_module, "config",
"Configuration filename",
"The name of the file containing the snort IDS configuration. Typically snort.conf",
&pref_snort_config_filename, FALSE);
prefs_register_bool_preference(snort_module, "show_rule_set_stats",
"Show rule stats in protocol tree",
"Whether or not information about the rule set and detected alerts should "
"be shown in the tree of every snort PDU tree",
&snort_show_rule_stats);
prefs_register_bool_preference(snort_module, "show_alert_expert_info",
"Show alerts in expert info",
"Whether or not expert info should be used to highlight fired alerts",
&snort_show_alert_expert_info);
prefs_register_bool_preference(snort_module, "show_alert_in_reassembled_frame",
"Try to show alerts in reassembled frame",
"Attempt to show alert in reassembled frame where possible",
&snort_alert_in_reassembled_frame);
snort_handle = create_dissector_handle(snort_dissector, proto_snort);
register_init_routine(snort_start);
register_postdissector(snort_handle);
register_postseq_cleanup_routine(snort_cleanup);
register_cleanup_routine(snort_file_cleanup);
}
