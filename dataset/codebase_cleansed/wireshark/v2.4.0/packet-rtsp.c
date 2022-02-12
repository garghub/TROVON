static void
rtsp_stats_tree_init(stats_tree* st)
{
st_node_packets = stats_tree_create_node(st, st_str_packets, 0, TRUE);
st_node_requests = stats_tree_create_pivot(st, st_str_requests, st_node_packets);
st_node_responses = stats_tree_create_node(st, st_str_responses, st_node_packets, TRUE);
st_node_resp_broken = stats_tree_create_node(st, st_str_resp_broken, st_node_responses, TRUE);
st_node_resp_100 = stats_tree_create_node(st, st_str_resp_100, st_node_responses, TRUE);
st_node_resp_200 = stats_tree_create_node(st, st_str_resp_200, st_node_responses, TRUE);
st_node_resp_300 = stats_tree_create_node(st, st_str_resp_300, st_node_responses, TRUE);
st_node_resp_400 = stats_tree_create_node(st, st_str_resp_400, st_node_responses, TRUE);
st_node_resp_500 = stats_tree_create_node(st, st_str_resp_500, st_node_responses, TRUE);
st_node_other = stats_tree_create_node(st, st_str_other, st_node_packets, FALSE);
}
static int
rtsp_stats_tree_packet(stats_tree* st, packet_info* pinfo _U_, epan_dissect_t* edt _U_, const void* p)
{
const rtsp_info_value_t *v = (const rtsp_info_value_t *)p;
guint i = v->response_code;
int resp_grp;
const gchar *resp_str;
static gchar str[64];
tick_stat_node(st, st_str_packets, 0, FALSE);
if (i) {
tick_stat_node(st, st_str_responses, st_node_packets, FALSE);
if ( (i<100)||(i>=600) ) {
resp_grp = st_node_resp_broken;
resp_str = st_str_resp_broken;
} else if (i<200) {
resp_grp = st_node_resp_100;
resp_str = st_str_resp_100;
} else if (i<300) {
resp_grp = st_node_resp_200;
resp_str = st_str_resp_200;
} else if (i<400) {
resp_grp = st_node_resp_300;
resp_str = st_str_resp_300;
} else if (i<500) {
resp_grp = st_node_resp_400;
resp_str = st_str_resp_400;
} else {
resp_grp = st_node_resp_500;
resp_str = st_str_resp_500;
}
tick_stat_node(st, resp_str, st_node_responses, FALSE);
g_snprintf(str, sizeof(str),"%u %s",i,val_to_str(i,rtsp_status_code_vals, "Unknown (%d)"));
tick_stat_node(st, str, resp_grp, FALSE);
} else if (v->request_method) {
stats_tree_tick_pivot(st,st_node_requests,v->request_method);
} else {
tick_stat_node(st, st_str_other, st_node_packets, FALSE);
}
return 1;
}
static int
dissect_rtspinterleaved(tvbuff_t *tvb, int offset, packet_info *pinfo,
proto_tree *tree)
{
guint length_remaining;
proto_item *ti;
proto_tree *rtspframe_tree = NULL;
int orig_offset;
guint8 rf_chan;
guint16 rf_len;
tvbuff_t *next_tvb;
conversation_t *conv;
rtsp_conversation_data_t *data;
dissector_handle_t dissector;
length_remaining = tvb_ensure_captured_length_remaining(tvb, offset);
if (rtsp_desegment_headers && pinfo->can_desegment) {
if (length_remaining < 4) {
pinfo->desegment_offset = offset;
pinfo->desegment_len = DESEGMENT_ONE_MORE_SEGMENT;
return -1;
}
}
orig_offset = offset;
rf_chan = tvb_get_guint8(tvb, offset+1);
rf_len = tvb_get_ntohs(tvb, offset+2);
if (rtsp_desegment_body && pinfo->can_desegment) {
if (length_remaining < 4U + rf_len) {
pinfo->desegment_offset = offset;
pinfo->desegment_len = 4U + rf_len - length_remaining;
return -1;
}
}
col_add_fstr(pinfo->cinfo, COL_INFO,
"Interleaved channel 0x%02x, %u bytes",
rf_chan, rf_len);
ti = proto_tree_add_protocol_format(tree, proto_rtsp, tvb,
offset, 4,
"RTSP Interleaved Frame, Channel: 0x%02x, %u bytes",
rf_chan, rf_len);
rtspframe_tree = proto_item_add_subtree(ti, ett_rtspframe);
proto_tree_add_item(rtspframe_tree, hf_rtsp_magic, tvb, offset, 1, ENC_BIG_ENDIAN);
offset += 1;
proto_tree_add_item(rtspframe_tree, hf_rtsp_channel, tvb, offset, 1, ENC_BIG_ENDIAN);
offset += 1;
proto_tree_add_item(rtspframe_tree, hf_rtsp_length, tvb, offset, 2, ENC_BIG_ENDIAN);
offset += 2;
if (length_remaining > rf_len)
length_remaining = rf_len;
next_tvb = tvb_new_subset_length_caplen(tvb, offset, length_remaining, rf_len);
conv = find_conversation(pinfo->num, &pinfo->src, &pinfo->dst, pinfo->ptype,
pinfo->srcport, pinfo->destport, 0);
if (conv &&
(data = (rtsp_conversation_data_t *)conversation_get_proto_data(conv, proto_rtsp)) &&
(dissector = data->interleaved[rf_chan].dissector)) {
call_dissector(dissector, next_tvb, pinfo, tree);
} else {
gboolean dissected = FALSE;
heur_dtbl_entry_t *hdtbl_entry = NULL;
dissected = dissector_try_heuristic(heur_subdissector_list,
next_tvb, pinfo, tree, &hdtbl_entry, NULL);
if (!dissected) {
proto_tree_add_item(rtspframe_tree, hf_rtsp_data, tvb, offset, rf_len, ENC_NA);
}
}
offset += rf_len;
return offset - orig_offset;
}
static gboolean
is_rtsp_request_or_reply(const guchar *line, size_t linelen, rtsp_type_t *type)
{
guint ii;
const guchar *token, *next_token;
int tokenlen;
gchar response_chars[4];
if (linelen >= 5 && g_ascii_strncasecmp("RTSP/", line, 5) == 0) {
*type = RTSP_REPLY;
tokenlen = get_token_len(line, line+5, &token);
if (tokenlen != 0) {
tokenlen = get_token_len(token, line+linelen, &next_token);
if (tokenlen >= 3) {
memcpy(response_chars, token, 3);
response_chars[3] = '\0';
ws_strtou32(response_chars, NULL, &rtsp_stat_info->response_code);
}
}
return TRUE;
}
for (ii = 0; ii < RTSP_NMETHODS; ii++) {
size_t len = strlen(rtsp_methods[ii]);
if (linelen >= len &&
g_ascii_strncasecmp(rtsp_methods[ii], line, len) == 0 &&
(len == linelen || g_ascii_isspace(line[len])))
{
*type = RTSP_REQUEST;
rtsp_stat_info->request_method =
wmem_strndup(wmem_packet_scope(), rtsp_methods[ii], len+1);
return TRUE;
}
}
*type = RTSP_NOT_FIRST_LINE;
return FALSE;
}
static void
rtsp_create_conversation(packet_info *pinfo, proto_item *ti,
const guchar *line_begin, size_t line_len,
gint rdt_feature_level,
rtsp_type_t rtsp_type_packet)
{
conversation_t *conv;
guchar buf[256];
guchar *tmp;
gboolean rtp_udp_transport = FALSE;
gboolean rtp_tcp_transport = FALSE;
gboolean rdt_transport = FALSE;
guint c_data_port, c_mon_port;
guint s_data_port, s_mon_port;
guint ipv4_1, ipv4_2, ipv4_3, ipv4_4;
gboolean is_video = FALSE;
address src_addr;
address dst_addr;
if (rtsp_type_packet != RTSP_REPLY) {
return;
}
src_addr=pinfo->src;
dst_addr=pinfo->dst;
if (line_len > sizeof(buf) - 1)
{
line_len = sizeof(buf) - 1;
}
memcpy(buf, line_begin, line_len);
buf[line_len] = '\0';
tmp = buf + STRLEN_CONST(rtsp_transport);
while (*tmp && g_ascii_isspace(*tmp))
tmp++;
if (g_ascii_strncasecmp(tmp, rtsp_rtp_udp, strlen(rtsp_rtp_udp)) == 0)
{
rtp_udp_transport = TRUE;
}
else if (g_ascii_strncasecmp(tmp, rtsp_rtp_tcp, strlen(rtsp_rtp_tcp)) == 0)
{
rtp_tcp_transport = TRUE;
}
else if (g_ascii_strncasecmp(tmp, rtsp_rtp_udp_default, strlen(rtsp_rtp_udp_default)) == 0)
{
rtp_udp_transport = TRUE;
}
else if (g_ascii_strncasecmp(tmp, rtsp_real_rdt, strlen(rtsp_real_rdt)) == 0 ||
g_ascii_strncasecmp(tmp, rtsp_real_tng, strlen(rtsp_real_tng)) == 0)
{
rdt_transport = TRUE;
}
else
{
expert_add_info(pinfo, ti, &ei_rtsp_unknown_transport_type);
return;
}
c_data_port = c_mon_port = 0;
s_data_port = s_mon_port = 0;
if ((tmp = strstr(buf, rtsp_sps_server_port))) {
tmp += strlen(rtsp_sps_server_port);
if (sscanf(tmp, "%u-%u", &s_data_port, &s_mon_port) < 1) {
expert_add_info(pinfo, ti, &ei_rtsp_bad_server_port);
return;
}
}
else if ((tmp = strstr(buf, rtsp_sps_dest_addr))) {
tmp += strlen(rtsp_sps_dest_addr);
if (sscanf(tmp, "\":%u\"", &s_data_port) == 1) {
if (s_data_port == 9) {
s_data_port = 0;
}
}
else if (sscanf(tmp, "\"%u.%u.%u.%u:%u\"", &ipv4_1, &ipv4_2, &ipv4_3, &ipv4_4, &s_data_port) == 5) {
guchar *tmp2;
guchar *tmp3;
guint32 ip4_addr;
tmp++;
tmp2=strstr(tmp,":");
tmp3=g_strndup(tmp,tmp2-tmp);
if (!str_to_ip(tmp3, &ip4_addr)) {
g_free(tmp3);
expert_add_info(pinfo, ti, &ei_rtsp_bad_server_ip_address);
return;
}
set_address(&dst_addr, AT_IPv4, 4, &ip4_addr);
g_free(tmp3);
}
else if (sscanf(tmp, "\"%u.%u.%u.%u\"", &ipv4_1, &ipv4_2, &ipv4_3, &ipv4_4) == 4) {
guchar *tmp2;
guchar *tmp3;
guint32 ip4_addr;
tmp++;
tmp2=strstr(tmp,"\"");
tmp3=g_strndup(tmp,tmp2-tmp);
if (!str_to_ip(tmp3, &ip4_addr)) {
g_free(tmp3);
expert_add_info(pinfo, ti, &ei_rtsp_bad_server_ip_address);
return;
}
set_address(&dst_addr, AT_IPv4, 4, &ip4_addr);
g_free(tmp3);
}
else
{
expert_add_info(pinfo, ti, &ei_rtsp_bad_server_port);
return;
}
}
if ((tmp = strstr(buf, rtsp_cps_server_port))) {
tmp += strlen(rtsp_cps_server_port);
if (sscanf(tmp, "%u-%u", &c_data_port, &c_mon_port) < 1) {
expert_add_info(pinfo, ti, &ei_rtsp_bad_client_port);
return;
}
}
else if ((tmp = strstr(buf, rtsp_cps_src_addr))) {
tmp += strlen(rtsp_cps_src_addr);
if (sscanf(tmp, "\"%u.%u.%u.%u:%u\"", &ipv4_1, &ipv4_2, &ipv4_3, &ipv4_4, &c_data_port) == 5) {
guchar *tmp2;
guchar *tmp3;
guint32 ip4_addr;
tmp++;
tmp2=strstr(tmp,":");
tmp3=g_strndup(tmp,tmp2-tmp);
if (!str_to_ip(tmp3, &ip4_addr)) {
g_free(tmp3);
expert_add_info(pinfo, ti, &ei_rtsp_bad_client_ip_address);
return;
}
set_address(&src_addr, AT_IPv4, 4, &ip4_addr);
g_free(tmp3);
}
}
if (strstr(buf, rtsp_inter) != NULL) {
rtsp_conversation_data_t *data;
guint s_data_chan, s_mon_chan;
int i;
tmp = strstr(buf, rtsp_inter);
tmp += strlen(rtsp_inter);
i = sscanf(tmp, "%u-%u", &s_data_chan, &s_mon_chan);
if (i < 1)
{
expert_add_info(pinfo, ti, &ei_rtsp_bad_interleaved_channel);
return;
}
conv = find_or_create_conversation(pinfo);
data = (rtsp_conversation_data_t *)conversation_get_proto_data(conv, proto_rtsp);
if (!data)
{
data = wmem_new0(wmem_file_scope(), rtsp_conversation_data_t);
conversation_add_proto_data(conv, proto_rtsp, data);
}
if (rtp_tcp_transport)
{
if (s_data_chan < RTSP_MAX_INTERLEAVED) {
data->interleaved[s_data_chan].dissector =
rtp_handle;
}
if (i > 1 && s_mon_chan < RTSP_MAX_INTERLEAVED) {
data->interleaved[s_mon_chan].dissector =
rtcp_handle;
}
}
else if (rdt_transport)
{
if (s_data_chan < RTSP_MAX_INTERLEAVED) {
data->interleaved[s_data_chan].dissector =
rdt_handle;
}
}
return;
}
else if (rtp_udp_transport)
{
if (c_data_port)
{
rtp_add_address(pinfo, PT_UDP, &dst_addr, c_data_port, s_data_port,
"RTSP", pinfo->num, is_video, NULL);
}
if (c_mon_port)
{
rtcp_add_address(pinfo, &pinfo->dst, c_mon_port, s_mon_port,
"RTSP", pinfo->num);
}
}
else if (rtp_tcp_transport)
{
rtp_add_address(pinfo, PT_TCP, &src_addr, c_data_port, s_data_port,
"RTSP", pinfo->num, is_video, NULL);
}
else if (rdt_transport)
{
rdt_add_address(pinfo, &pinfo->dst, c_data_port, s_data_port,
"RTSP", rdt_feature_level);
}
return;
}
static int
rtsp_get_content_length(const guchar *line_begin, size_t line_len)
{
guchar buf[256];
guchar *tmp;
guint32 content_length;
const char *p;
const guchar *up;
if (line_len > sizeof(buf) - 1) {
line_len = sizeof(buf) - 1;
}
memcpy(buf, line_begin, line_len);
buf[line_len] = '\0';
tmp = buf + STRLEN_CONST(rtsp_content_length);
while (*tmp && g_ascii_isspace(*tmp))
tmp++;
ws_strtoi32(tmp, &p, &content_length);
up = p;
if (up == tmp || (*up != '\0' && !g_ascii_isspace(*up)))
return -1;
return (int)content_length;
}
static int
dissect_rtspmessage(tvbuff_t *tvb, int offset, packet_info *pinfo,
proto_tree *tree)
{
proto_tree *rtsp_tree = NULL;
proto_tree *sub_tree = NULL;
proto_item *ti_top = NULL;
const guchar *line;
gint next_offset;
const guchar *linep, *lineend;
int orig_offset;
int first_linelen, linelen;
int line_end_offset;
int colon_offset;
gboolean is_request_or_reply;
gboolean body_requires_content_len;
gboolean saw_req_resp_or_header;
guchar c;
rtsp_type_t rtsp_type_packet;
rtsp_type_t rtsp_type_line;
gboolean is_header;
int datalen;
int content_length;
int reported_datalen;
int value_offset;
int value_len;
e164_info_t e164_info;
gint rdt_feature_level = 0;
gchar *media_type_str_lower_case = NULL;
int semi_colon_offset;
int par_end_offset;
gchar *frame_label = NULL;
gchar *session_id = NULL;
voip_packet_info_t *stat_info = NULL;
rtsp_stat_info = wmem_new(wmem_packet_scope(), rtsp_info_value_t);
rtsp_stat_info->framenum = pinfo->num;
rtsp_stat_info->response_code = 0;
rtsp_stat_info->request_method = NULL;
rtsp_stat_info->request_uri = NULL;
rtsp_stat_info->rtsp_host = NULL;
first_linelen = tvb_find_line_end(tvb, offset, -1, &next_offset, FALSE);
line = tvb_get_ptr(tvb, offset, first_linelen);
is_request_or_reply = is_rtsp_request_or_reply(line, first_linelen,
&rtsp_type_packet);
if (is_request_or_reply) {
if (!req_resp_hdrs_do_reassembly(tvb, offset, pinfo,
rtsp_desegment_headers, rtsp_desegment_body)) {
return -1;
}
}
if (rtsp_type_packet == RTSP_REQUEST)
body_requires_content_len = TRUE;
else
body_requires_content_len = FALSE;
line = tvb_get_ptr(tvb, offset, first_linelen);
if (is_request_or_reply) {
if ( rtsp_type_packet == RTSP_REPLY ) {
frame_label = wmem_strdup_printf(wmem_packet_scope(),
"Reply: %s", format_text(wmem_packet_scope(), line, first_linelen));
}
else {
frame_label = format_text(wmem_packet_scope(), line, first_linelen);
}
}
col_set_str(pinfo->cinfo, COL_PROTOCOL, "RTSP");
if (is_request_or_reply)
if ( rtsp_type_packet == RTSP_REPLY ) {
col_set_str(pinfo->cinfo, COL_INFO, "Reply: ");
col_append_str(pinfo->cinfo, COL_INFO,
format_text(wmem_packet_scope(), line, first_linelen));
}
else {
col_add_str(pinfo->cinfo, COL_INFO,
format_text(wmem_packet_scope(), line, first_linelen));
}
else
col_set_str(pinfo->cinfo, COL_INFO, "Continuation");
orig_offset = offset;
if (tree) {
ti_top = proto_tree_add_item(tree, proto_rtsp, tvb, offset, -1,
ENC_NA);
rtsp_tree = proto_item_add_subtree(ti_top, ett_rtsp);
}
content_length = -1;
saw_req_resp_or_header = FALSE;
while (tvb_offset_exists(tvb, offset)) {
is_header = FALSE;
linelen = tvb_find_line_end(tvb, offset, -1, &next_offset, FALSE);
if (linelen < 0)
return -1;
line_end_offset = offset + linelen;
colon_offset = tvb_find_guint8(tvb, offset, linelen, ':');
line = tvb_get_ptr(tvb, offset, linelen);
lineend = line + linelen;
is_request_or_reply = is_rtsp_request_or_reply(line, linelen, &rtsp_type_line);
if (is_request_or_reply)
goto is_rtsp;
if (linelen == 0)
goto is_rtsp;
linep = line;
while (linep < lineend) {
c = *linep++;
if (!g_ascii_isprint(c))
break;
switch (c) {
case '(':
case ')':
case '<':
case '>':
case '@':
case ',':
case ';':
case '\\':
case '"':
case '/':
case '[':
case ']':
case '?':
case '=':
case '{':
case '}':
goto not_rtsp;
case ':':
is_header = TRUE;
goto is_rtsp;
case ' ':
case '\t':
goto is_rtsp;
}
}
if (saw_req_resp_or_header)
tvb_ensure_bytes_exist(tvb, offset, linelen + 1);
not_rtsp:
break;
is_rtsp:
if (linelen == 0) {
proto_tree_add_format_text(rtsp_tree, tvb, offset, next_offset - offset);
offset = next_offset;
break;
}
saw_req_resp_or_header = TRUE;
if (rtsp_tree) {
switch (rtsp_type_line)
{
case RTSP_REQUEST:
process_rtsp_request(tvb, offset, line, linelen, next_offset, rtsp_tree);
break;
case RTSP_REPLY:
process_rtsp_reply(tvb, offset, line, linelen, next_offset, rtsp_tree);
break;
case RTSP_NOT_FIRST_LINE:
break;
}
}
if (is_header)
{
value_offset = colon_offset + 1;
while ((value_offset < line_end_offset) &&
((c = tvb_get_guint8(tvb, value_offset)) == ' ' || c == '\t'))
{
value_offset++;
}
value_len = line_end_offset - value_offset;
#define HDR_MATCHES(header) \
( (size_t)linelen > STRLEN_CONST(header) && \
g_ascii_strncasecmp(line, (header), STRLEN_CONST(header)) == 0)
if (HDR_MATCHES(rtsp_transport))
{
proto_item *ti;
ti = proto_tree_add_string(rtsp_tree, hf_rtsp_transport, tvb,
offset, linelen,
tvb_format_text(tvb, value_offset,
value_len));
rtsp_create_conversation(pinfo, ti, line, linelen, rdt_feature_level, rtsp_type_packet);
} else if (HDR_MATCHES(rtsp_content_type))
{
proto_tree_add_string(rtsp_tree, hf_rtsp_content_type,
tvb, offset, linelen,
tvb_format_text(tvb, value_offset,
value_len));
offset = offset + (int)STRLEN_CONST(rtsp_content_type);
offset = tvb_skip_wsp(tvb, offset, value_len);
semi_colon_offset = tvb_find_guint8(tvb, value_offset, value_len, ';');
if ( semi_colon_offset != -1) {
par_end_offset = tvb_skip_wsp_return(tvb, semi_colon_offset-1);
value_len = par_end_offset - offset;
}
media_type_str_lower_case = ascii_strdown_inplace(
(gchar *)tvb_get_string_enc(wmem_packet_scope(), tvb, offset, value_len, ENC_ASCII));
} else if (HDR_MATCHES(rtsp_content_length))
{
guint32 clength;
gboolean clength_valid;
proto_item* pi;
clength_valid = ws_strtou32(tvb_format_text(tvb, value_offset, value_len),
NULL, &clength);
pi = proto_tree_add_uint(rtsp_tree, hf_rtsp_content_length,
tvb, offset, linelen, clength);
if (!clength_valid)
expert_add_info(pinfo, pi, &ei_rtsp_content_length_invalid);
content_length = rtsp_get_content_length(line, linelen);
} else if (HDR_MATCHES(rtsp_Session))
{
session_id = tvb_format_text(tvb, value_offset, value_len);
proto_tree_add_string(rtsp_tree, hf_rtsp_session, tvb,
offset, linelen,
session_id);
} else if (HDR_MATCHES(rtsp_X_Vig_Msisdn)) {
if (colon_offset != -1)
{
proto_item *ti;
ti = proto_tree_add_string(rtsp_tree, hf_rtsp_X_Vig_Msisdn,tvb,
offset, linelen ,
tvb_format_text(tvb, value_offset, value_len));
sub_tree = proto_item_add_subtree(ti, ett_rtsp_method);
e164_info.e164_number_type = CALLING_PARTY_NUMBER;
e164_info.nature_of_address = 0;
e164_info.E164_number_str = tvb_get_string_enc(wmem_packet_scope(), tvb, value_offset,
value_len, ENC_ASCII);
e164_info.E164_number_length = value_len;
dissect_e164_number(tvb, sub_tree, value_offset,
value_len, e164_info);
}
} else if (HDR_MATCHES(rtsp_rdt_feature_level))
{
gboolean rdt_feature_level_valid;
proto_item* pi;
rdt_feature_level_valid = ws_strtou32(tvb_format_text(tvb, value_offset, value_len),
NULL, &rdt_feature_level);
pi = proto_tree_add_uint(rtsp_tree, hf_rtsp_rdtfeaturelevel,
tvb, offset, linelen, rdt_feature_level);
if (!rdt_feature_level_valid)
expert_add_info(pinfo, pi, &ei_rtsp_rdtfeaturelevel_invalid);
}
else
{
proto_tree_add_format_text(rtsp_tree, tvb, offset, next_offset - offset);
}
}
else if (rtsp_type_line == RTSP_NOT_FIRST_LINE)
{
proto_tree_add_format_text(rtsp_tree, tvb, offset, next_offset - offset);
}
offset = next_offset;
}
if (session_id) {
stat_info = wmem_new0(wmem_packet_scope(), voip_packet_info_t);
stat_info->protocol_name = wmem_strdup(wmem_packet_scope(), "RTSP");
stat_info->call_id = session_id;
stat_info->frame_label = frame_label;
stat_info->call_state = VOIP_CALL_SETUP;
stat_info->call_active_state = VOIP_ACTIVE;
stat_info->frame_comment = frame_label;
tap_queue_packet(voip_tap, pinfo, stat_info);
}
datalen = tvb_captured_length_remaining(tvb, offset);
reported_datalen = tvb_reported_length_remaining(tvb, offset);
if (content_length != -1) {
if (datalen > content_length)
datalen = content_length;
if (reported_datalen > content_length)
reported_datalen = content_length;
} else {
if (body_requires_content_len)
datalen = 0;
}
if (datalen > 0) {
tvbuff_t *new_tvb;
new_tvb = tvb_new_subset_length_caplen(tvb, offset, datalen,
reported_datalen);
if (media_type_str_lower_case &&
dissector_try_string(media_type_dissector_table,
media_type_str_lower_case,
new_tvb, pinfo, rtsp_tree, NULL)){
}else {
if (ti_top != NULL)
proto_item_set_len(ti_top, offset);
if (tvb_get_guint8(tvb, offset) == RTSP_FRAMEHDR) {
datalen = 0;
} else {
proto_tree_add_bytes_format(rtsp_tree, hf_rtsp_data, tvb, offset,
datalen, NULL, "Data (%d bytes)",
reported_datalen);
}
}
offset += datalen;
}
tap_queue_packet(rtsp_tap, pinfo, rtsp_stat_info);
return offset - orig_offset;
}
static void
process_rtsp_request(tvbuff_t *tvb, int offset, const guchar *data,
size_t linelen, size_t next_line_offset, proto_tree *tree)
{
proto_tree *sub_tree;
proto_item *ti;
const guchar *lineend = data + linelen;
guint ii;
const guchar *url;
const guchar *url_start;
guchar *tmp_url;
for (ii = 0; ii < RTSP_NMETHODS; ii++) {
size_t len = strlen(rtsp_methods[ii]);
if (linelen >= len &&
g_ascii_strncasecmp(rtsp_methods[ii], data, len) == 0 &&
(len == linelen || g_ascii_isspace(data[len])))
break;
}
if (ii == RTSP_NMETHODS) {
DISSECTOR_ASSERT_NOT_REACHED();
}
ti = proto_tree_add_string(tree, hf_rtsp_request, tvb, offset,
(gint) (next_line_offset - offset),
tvb_format_text(tvb, offset, (gint) (next_line_offset - offset)));
sub_tree = proto_item_add_subtree(ti, ett_rtsp_method);
proto_tree_add_string(sub_tree, hf_rtsp_method, tvb, offset,
(gint) strlen(rtsp_methods[ii]), rtsp_methods[ii]);
url = data;
while (url < lineend && !g_ascii_isspace(*url))
url++;
while (url < lineend && g_ascii_isspace(*url))
url++;
url_start = url;
while (url < lineend && !g_ascii_isspace(*url))
url++;
tmp_url = wmem_strndup(wmem_packet_scope(), url_start, url - url_start);
proto_tree_add_string(sub_tree, hf_rtsp_url, tvb,
offset + (gint) (url_start - data), (gint) (url - url_start), tmp_url);
}
static void
process_rtsp_reply(tvbuff_t *tvb, int offset, const guchar *data,
size_t linelen, size_t next_line_offset, proto_tree *tree)
{
proto_tree *sub_tree;
proto_item *ti;
const guchar *lineend = data + linelen;
const guchar *status = data;
const guchar *status_start;
guint status_i;
ti = proto_tree_add_string(tree, hf_rtsp_response, tvb, offset,
(gint) (next_line_offset - offset),
tvb_format_text(tvb, offset, (gint) (next_line_offset - offset)));
sub_tree = proto_item_add_subtree(ti, ett_rtsp_method);
while (status < lineend && !g_ascii_isspace(*status))
status++;
while (status < lineend && g_ascii_isspace(*status))
status++;
status_start = status;
status_i = 0;
while (status < lineend && g_ascii_isdigit(*status))
status_i = status_i * 10 + *status++ - '0';
proto_tree_add_uint(sub_tree, hf_rtsp_status, tvb,
offset + (gint) (status_start - data),
(gint) (status - status_start), status_i);
}
static int
dissect_rtsp(tvbuff_t *tvb, packet_info *pinfo, proto_tree *tree, void* data _U_)
{
int offset = 0;
int len;
while (tvb_reported_length_remaining(tvb, offset) != 0) {
len = (tvb_get_guint8(tvb, offset) == RTSP_FRAMEHDR)
? dissect_rtspinterleaved(tvb, offset, pinfo, tree)
: dissect_rtspmessage(tvb, offset, pinfo, tree);
if (len == -1)
break;
offset += len;
col_set_fence(pinfo->cinfo, COL_INFO);
}
return tvb_captured_length(tvb);
}
void
proto_register_rtsp(void)
{
static gint *ett[] = {
&ett_rtspframe,
&ett_rtsp,
&ett_rtsp_method,
};
static hf_register_info hf[] = {
{ &hf_rtsp_request,
{ "Request", "rtsp.request", FT_STRING, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_rtsp_response,
{ "Response", "rtsp.response", FT_STRING, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_rtsp_method,
{ "Method", "rtsp.method", FT_STRING, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_rtsp_content_type,
{ "Content-type", "rtsp.content-type", FT_STRING, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_rtsp_content_length,
{ "Content-length", "rtsp.content-length", FT_UINT32, BASE_DEC, NULL, 0,
NULL, HFILL }},
{ &hf_rtsp_url,
{ "URL", "rtsp.url", FT_STRING, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_rtsp_status,
{ "Status", "rtsp.status", FT_UINT32, BASE_DEC, NULL, 0,
NULL, HFILL }},
{ &hf_rtsp_session,
{ "Session", "rtsp.session", FT_STRING, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_rtsp_transport,
{ "Transport", "rtsp.transport", FT_STRING, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_rtsp_rdtfeaturelevel,
{ "RDTFeatureLevel", "rtsp.rdt-feature-level", FT_UINT32, BASE_DEC, NULL, 0,
NULL, HFILL }},
{ &hf_rtsp_X_Vig_Msisdn,
{ "X-Vig-Msisdn", "rtsp.X_Vig_Msisdn", FT_STRING, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_rtsp_magic,
{ "Magic", "rtsp.magic", FT_UINT8, BASE_HEX, NULL, 0x0,
NULL, HFILL }},
{ &hf_rtsp_channel,
{ "Channel", "rtsp.channel", FT_UINT8, BASE_HEX, NULL, 0x0,
NULL, HFILL }},
{ &hf_rtsp_length,
{ "Length", "rtsp.length", FT_UINT16, BASE_DEC, NULL, 0x0,
NULL, HFILL }},
{ &hf_rtsp_data,
{ "Data", "rtsp.data", FT_BYTES, BASE_NONE, NULL, 0x0,
NULL, HFILL }},
};
static ei_register_info ei[] = {
{ &ei_rtsp_unknown_transport_type,
{ "rtsp.unknown_transport_type", PI_UNDECODED, PI_WARN, "Unknown transport type", EXPFILL }},
{ &ei_rtsp_bad_server_port,
{ "rtsp.bad_server_port", PI_UNDECODED, PI_WARN, "Bad server_port", EXPFILL }},
{ &ei_rtsp_bad_client_port,
{ "rtsp.bad_client_port", PI_UNDECODED, PI_WARN, "Bad client port", EXPFILL }},
{ &ei_rtsp_bad_interleaved_channel,
{ "rtsp.bad_interleaved_channel", PI_UNDECODED, PI_WARN, "Bad interleaved_channel", EXPFILL }},
{ &ei_rtsp_content_length_invalid,
{ "rtsp.content-length.invalid", PI_MALFORMED, PI_ERROR, "Invalid content length", EXPFILL }},
{ &ei_rtsp_rdtfeaturelevel_invalid,
{ "rtsp.rdt-feature-level.invalid", PI_MALFORMED, PI_ERROR, "Invalid RDTFeatureLevel", EXPFILL }},
{ &ei_rtsp_bad_server_ip_address,
{ "rtsp.bad_client_ip_address", PI_MALFORMED, PI_ERROR, "Bad server IP address", EXPFILL }},
{ &ei_rtsp_bad_client_ip_address,
{ "rtsp.bad_client_ip_address", PI_MALFORMED, PI_ERROR, "Bad client IP address", EXPFILL }}
};
module_t *rtsp_module;
expert_module_t *expert_rtsp;
proto_rtsp = proto_register_protocol("Real Time Streaming Protocol", "RTSP", "rtsp");
proto_register_field_array(proto_rtsp, hf, array_length(hf));
proto_register_subtree_array(ett, array_length(ett));
expert_rtsp = expert_register_protocol(proto_rtsp);
expert_register_field_array(expert_rtsp, ei, array_length(ei));
rtsp_handle = register_dissector("rtsp", dissect_rtsp, proto_rtsp);
rtsp_module = prefs_register_protocol(proto_rtsp, NULL);
prefs_register_obsolete_preference(rtsp_module, "tcp.alternate_port");
prefs_register_bool_preference(rtsp_module, "desegment_headers",
"Reassemble RTSP headers spanning multiple TCP segments",
"Whether the RTSP dissector should reassemble headers "
"of a request spanning multiple TCP segments. "
" To use this option, you must also enable \"Allow subdissectors to reassemble TCP streams\" in the TCP protocol settings.",
&rtsp_desegment_headers);
prefs_register_bool_preference(rtsp_module, "desegment_body",
"Trust the \"Content-length:\" header when desegmenting",
"Whether the RTSP dissector should use the "
"\"Content-length:\" value to desegment the body "
"of a request spanning multiple TCP segments",
&rtsp_desegment_body);
heur_subdissector_list = register_heur_dissector_list("rtsp", proto_rtsp);
rtsp_tap = register_tap("rtsp");
}
void
proto_reg_handoff_rtsp(void)
{
rtp_handle = find_dissector_add_dependency("rtp", proto_rtsp);
rtp_rfc4571_handle = find_dissector_add_dependency("rtp.rfc4571", proto_rtsp);
rtcp_handle = find_dissector_add_dependency("rtcp", proto_rtsp);
rdt_handle = find_dissector_add_dependency("rdt", proto_rtsp);
media_type_dissector_table = find_dissector_table("media_type");
voip_tap = find_tap_id("voip");
dissector_add_uint_range_with_preference("tcp.port", RTSP_TCP_PORT_RANGE, rtsp_handle);
stats_tree_register("rtsp","rtsp","RTSP/Packet Counter", 0, rtsp_stats_tree_packet, rtsp_stats_tree_init, NULL );
}
