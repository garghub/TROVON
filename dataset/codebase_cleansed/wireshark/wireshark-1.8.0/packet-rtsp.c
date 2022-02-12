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
st_node_other = stats_tree_create_node(st, st_str_other, st_node_packets,ENC_BIG_ENDIAN);
}
static int
rtsp_stats_tree_packet(stats_tree* st, packet_info* pinfo _U_, epan_dissect_t* edt _U_, const void* p)
{
const rtsp_info_value_t* v = p;
guint i = v->response_code;
int resp_grp;
const gchar *resp_str;
static gchar str[64];
tick_stat_node(st, st_str_packets, 0, ENC_BIG_ENDIAN);
if (i) {
tick_stat_node(st, st_str_responses, st_node_packets, ENC_BIG_ENDIAN);
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
tick_stat_node(st, resp_str, st_node_responses, ENC_BIG_ENDIAN);
g_snprintf(str, sizeof(str),"%u %s",i,val_to_str(i,rtsp_status_code_vals, "Unknown (%d)"));
tick_stat_node(st, str, resp_grp, ENC_BIG_ENDIAN);
} else if (v->request_method) {
stats_tree_tick_pivot(st,st_node_requests,v->request_method);
} else {
tick_stat_node(st, st_str_other, st_node_packets, ENC_BIG_ENDIAN);
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
guint8 rf_start;
guint8 rf_chan;
guint16 rf_len;
tvbuff_t *next_tvb;
conversation_t *conv;
rtsp_conversation_data_t *data;
dissector_handle_t dissector;
length_remaining = tvb_ensure_length_remaining(tvb, offset);
if (rtsp_desegment_headers && pinfo->can_desegment) {
if (length_remaining < 4) {
pinfo->desegment_offset = offset;
pinfo->desegment_len = DESEGMENT_ONE_MORE_SEGMENT;
return -1;
}
}
orig_offset = offset;
rf_start = tvb_get_guint8(tvb, offset);
rf_chan = tvb_get_guint8(tvb, offset+1);
rf_len = tvb_get_ntohs(tvb, offset+2);
if (rtsp_desegment_body && pinfo->can_desegment) {
if (length_remaining < 4U + rf_len) {
pinfo->desegment_offset = offset;
pinfo->desegment_len = 4U + rf_len - length_remaining;
return -1;
}
}
if (check_col(pinfo->cinfo, COL_INFO))
col_add_fstr(pinfo->cinfo, COL_INFO,
"Interleaved channel 0x%02x, %u bytes",
rf_chan, rf_len);
if (tree != NULL) {
ti = proto_tree_add_protocol_format(tree, proto_rtsp, tvb,
offset, 4,
"RTSP Interleaved Frame, Channel: 0x%02x, %u bytes",
rf_chan, rf_len);
rtspframe_tree = proto_item_add_subtree(ti, ett_rtspframe);
proto_tree_add_text(rtspframe_tree, tvb, offset, 1,
"Magic: 0x%02x",
rf_start);
}
offset += 1;
if (tree != NULL) {
proto_tree_add_text(rtspframe_tree, tvb, offset, 1,
"Channel: 0x%02x",
rf_chan);
}
offset += 1;
if (tree != NULL) {
proto_tree_add_text(rtspframe_tree, tvb, offset, 2,
"Length: %u bytes",
rf_len);
}
offset += 2;
if (length_remaining > rf_len)
length_remaining = rf_len;
next_tvb = tvb_new_subset(tvb, offset, length_remaining, rf_len);
conv = find_conversation(pinfo->fd->num, &pinfo->src, &pinfo->dst, pinfo->ptype,
pinfo->srcport, pinfo->destport, 0);
if (conv &&
(data = conversation_get_proto_data(conv, proto_rtsp)) &&
(dissector = data->interleaved[rf_chan].dissector)) {
call_dissector(dissector, next_tvb, pinfo, tree);
} else {
proto_tree_add_text(rtspframe_tree, tvb, offset, rf_len,
"Data (%u bytes)", rf_len);
}
offset += rf_len;
return offset - orig_offset;
}
static gboolean
is_rtsp_request_or_reply(const guchar *line, size_t linelen, rtsp_type_t *type)
{
unsigned ii;
const guchar *next_token;
int tokenlen;
gchar response_chars[4];
if (linelen >= 5 && g_ascii_strncasecmp("RTSP/", line, 5) == 0) {
*type = RTSP_REPLY;
tokenlen = get_token_len(line, line+5, &next_token);
if (tokenlen != 0) {
tokenlen = get_token_len(next_token, line+linelen, &next_token);
if (tokenlen >= 3) {
memcpy(response_chars, next_token, 3);
response_chars[3] = '\0';
rtsp_stat_info->response_code = strtoul(response_chars, NULL, 10);
}
}
return TRUE;
}
for (ii = 0; ii < RTSP_NMETHODS; ii++) {
size_t len = strlen(rtsp_methods[ii]);
if (linelen >= len &&
g_ascii_strncasecmp(rtsp_methods[ii], line, len) == 0 &&
(len == linelen || isspace(line[len])))
{
*type = RTSP_REQUEST;
rtsp_stat_info->request_method = ep_strndup(rtsp_methods[ii], len+1);
return TRUE;
}
}
*type = RTSP_NOT_FIRST_LINE;
return FALSE;
}
static void
rtsp_create_conversation(packet_info *pinfo, const guchar *line_begin,
size_t line_len, gint rdt_feature_level)
{
conversation_t *conv;
guchar buf[256];
guchar *tmp;
gboolean rtp_transport = FALSE;
gboolean rdt_transport = FALSE;
guint c_data_port, c_mon_port;
guint s_data_port, s_mon_port;
gboolean is_video = FALSE;
if (line_len > sizeof(buf) - 1)
{
line_len = sizeof(buf) - 1;
}
memcpy(buf, line_begin, line_len);
buf[line_len] = '\0';
tmp = buf + STRLEN_CONST(rtsp_transport);
while (*tmp && isspace(*tmp))
tmp++;
if (g_ascii_strncasecmp(tmp, rtsp_rtp, strlen(rtsp_rtp)) == 0)
rtp_transport = TRUE;
else
if (g_ascii_strncasecmp(tmp, rtsp_real_rdt, strlen(rtsp_real_rdt)) == 0 ||
g_ascii_strncasecmp(tmp, rtsp_real_tng, strlen(rtsp_real_tng)) == 0)
rdt_transport = TRUE;
else
{
return;
}
c_data_port = c_mon_port = 0;
s_data_port = s_mon_port = 0;
if ((tmp = strstr(buf, rtsp_sps))) {
tmp += strlen(rtsp_sps);
if (sscanf(tmp, "%u-%u", &s_data_port, &s_mon_port) < 1) {
g_warning("Frame %u: rtsp: bad server_port",
pinfo->fd->num);
return;
}
}
if ((tmp = strstr(buf, rtsp_cps))) {
tmp += strlen(rtsp_cps);
if (sscanf(tmp, "%u-%u", &c_data_port, &c_mon_port) < 1) {
g_warning("Frame %u: rtsp: bad client_port",
pinfo->fd->num);
return;
}
}
if (!c_data_port) {
rtsp_conversation_data_t *data;
guint s_data_chan, s_mon_chan;
int i;
if ((tmp = strstr(buf, rtsp_inter)) == NULL) {
return;
}
tmp += strlen(rtsp_inter);
i = sscanf(tmp, "%u-%u", &s_data_chan, &s_mon_chan);
if (i < 1)
{
g_warning("Frame %u: rtsp: bad interleaved", pinfo->fd->num);
return;
}
conv = find_or_create_conversation(pinfo);
data = conversation_get_proto_data(conv, proto_rtsp);
if (!data)
{
data = se_alloc0(sizeof(rtsp_conversation_data_t));
conversation_add_proto_data(conv, proto_rtsp, data);
}
if (rtp_transport)
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
if (rtp_transport)
{
rtp_add_address(pinfo, &pinfo->dst, c_data_port, s_data_port,
"RTSP", pinfo->fd->num, is_video, NULL);
if (c_mon_port)
{
rtcp_add_address(pinfo, &pinfo->dst, c_mon_port, s_mon_port,
"RTSP", pinfo->fd->num);
}
}
else
if (rdt_transport)
{
rdt_add_address(pinfo, &pinfo->dst, c_data_port, s_data_port,
"RTSP", rdt_feature_level);
}
}
static int
rtsp_get_content_length(const guchar *line_begin, size_t line_len)
{
guchar buf[256];
guchar *tmp;
long content_length;
char *p;
guchar *up;
if (line_len > sizeof(buf) - 1) {
line_len = sizeof(buf) - 1;
}
memcpy(buf, line_begin, line_len);
buf[line_len] = '\0';
tmp = buf + STRLEN_CONST(rtsp_content_length);
while (*tmp && isspace(*tmp))
tmp++;
content_length = strtol(tmp, &p, 10);
up = p;
if (up == tmp || (*up != '\0' && !isspace(*up)))
return -1;
return content_length;
}
static int
dissect_rtspmessage(tvbuff_t *tvb, int offset, packet_info *pinfo,
proto_tree *tree)
{
proto_tree *rtsp_tree = NULL;
proto_tree *sub_tree = NULL;
proto_item *ti = NULL;
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
rtsp_type_t rtsp_type;
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
rtsp_stat_info = ep_alloc(sizeof(rtsp_info_value_t));
rtsp_stat_info->framenum = pinfo->fd->num;
rtsp_stat_info->response_code = 0;
rtsp_stat_info->request_method = NULL;
rtsp_stat_info->request_uri = NULL;
rtsp_stat_info->rtsp_host = NULL;
first_linelen = tvb_find_line_end(tvb, offset,
tvb_ensure_length_remaining(tvb, offset), &next_offset,
ENC_BIG_ENDIAN);
line = tvb_get_ptr(tvb, offset, first_linelen);
is_request_or_reply = is_rtsp_request_or_reply(line, first_linelen,
&rtsp_type);
if (is_request_or_reply) {
if (!req_resp_hdrs_do_reassembly(tvb, offset, pinfo,
rtsp_desegment_headers, rtsp_desegment_body)) {
return -1;
}
}
if (rtsp_type == RTSP_REQUEST)
body_requires_content_len = TRUE;
else
body_requires_content_len = FALSE;
line = tvb_get_ptr(tvb, offset, first_linelen);
if (is_request_or_reply) {
if ( rtsp_type == RTSP_REPLY ) {
frame_label = ep_strdup_printf("Reply: %s", format_text(line, first_linelen));
}
else {
frame_label = ep_strdup(format_text(line, first_linelen));
}
}
col_set_str(pinfo->cinfo, COL_PROTOCOL, "RTSP");
if (check_col(pinfo->cinfo, COL_INFO)) {
if (is_request_or_reply)
if ( rtsp_type == RTSP_REPLY ) {
col_set_str(pinfo->cinfo, COL_INFO, "Reply: ");
col_append_str(pinfo->cinfo, COL_INFO,
format_text(line, first_linelen));
}
else {
col_add_str(pinfo->cinfo, COL_INFO,
format_text(line, first_linelen));
}
else
col_set_str(pinfo->cinfo, COL_INFO, "Continuation");
}
orig_offset = offset;
if (tree) {
ti = proto_tree_add_item(tree, proto_rtsp, tvb, offset, -1,
ENC_NA);
rtsp_tree = proto_item_add_subtree(ti, ett_rtsp);
}
content_length = -1;
saw_req_resp_or_header = FALSE;
while (tvb_reported_length_remaining(tvb, offset) != 0) {
is_header = FALSE;
linelen = tvb_find_line_end(tvb, offset,
tvb_ensure_length_remaining(tvb, offset), &next_offset,
ENC_BIG_ENDIAN);
if (linelen < 0)
return -1;
line_end_offset = offset + linelen;
colon_offset = tvb_find_guint8(tvb, offset, linelen, ':');
line = tvb_get_ptr(tvb, offset, linelen);
lineend = line + linelen;
is_request_or_reply = is_rtsp_request_or_reply(line, linelen, &rtsp_type);
if (is_request_or_reply)
goto is_rtsp;
if (linelen == 0)
goto is_rtsp;
linep = line;
while (linep < lineend) {
c = *linep++;
if (!isascii(c))
break;
if (iscntrl(c))
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
proto_tree_add_text(rtsp_tree, tvb, offset,
next_offset - offset, "%s",
tvb_format_text(tvb, offset, next_offset - offset));
offset = next_offset;
break;
}
saw_req_resp_or_header = TRUE;
if (rtsp_tree) {
switch (rtsp_type)
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
proto_tree_add_string(rtsp_tree, hf_rtsp_transport, tvb,
offset, linelen,
tvb_format_text(tvb, value_offset,
value_len));
rtsp_create_conversation(pinfo, line, linelen, rdt_feature_level);
} else if (HDR_MATCHES(rtsp_content_type))
{
proto_tree_add_string(rtsp_tree, hf_rtsp_content_type,
tvb, offset, linelen,
tvb_format_text(tvb, value_offset,
value_len));
offset = offset + STRLEN_CONST(rtsp_content_type);
offset = tvb_skip_wsp(tvb, offset, value_len);
semi_colon_offset = tvb_find_guint8(tvb, value_offset, value_len, ';');
if ( semi_colon_offset != -1) {
par_end_offset = tvb_skip_wsp_return(tvb, semi_colon_offset-1);
value_len = par_end_offset - offset;
}
media_type_str_lower_case = ascii_strdown_inplace(
(gchar *)tvb_get_ephemeral_string(tvb, offset, value_len));
} else if (HDR_MATCHES(rtsp_content_length))
{
proto_tree_add_uint(rtsp_tree, hf_rtsp_content_length,
tvb, offset, linelen,
atoi(tvb_format_text(tvb, value_offset,
value_len)));
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
ti = proto_tree_add_string(rtsp_tree, hf_rtsp_X_Vig_Msisdn,tvb,
offset, linelen ,
tvb_format_text(tvb, value_offset, value_len));
sub_tree = proto_item_add_subtree(ti, ett_rtsp_method);
e164_info.e164_number_type = CALLING_PARTY_NUMBER;
e164_info.nature_of_address = 0;
e164_info.E164_number_str = tvb_get_ephemeral_string(tvb, value_offset,
value_len);
e164_info.E164_number_length = value_len;
dissect_e164_number(tvb, sub_tree, value_offset,
value_len, e164_info);
}
} else if (HDR_MATCHES(rtsp_rdt_feature_level))
{
rdt_feature_level = atoi(tvb_format_text(tvb, value_offset,
value_len));
proto_tree_add_uint(rtsp_tree, hf_rtsp_rdtfeaturelevel,
tvb, offset, linelen,
atoi(tvb_format_text(tvb, value_offset,
value_len)));
}
else
{
proto_tree_add_text(rtsp_tree, tvb, offset,
next_offset - offset, "%s",
tvb_format_text(tvb, offset, next_offset - offset));
}
}
else if (rtsp_type == RTSP_NOT_FIRST_LINE)
{
proto_tree_add_text(rtsp_tree, tvb, offset,
next_offset - offset, "%s",
tvb_format_text(tvb, offset, next_offset - offset));
}
offset = next_offset;
}
if (session_id) {
stat_info = ep_alloc0(sizeof(voip_packet_info_t));
stat_info->protocol_name = ep_strdup("RTSP");
stat_info->call_id = session_id;
stat_info->frame_label = frame_label;
stat_info->call_state = VOIP_CALL_SETUP;
stat_info->call_active_state = VOIP_ACTIVE;
stat_info->frame_comment = frame_label;
tap_queue_packet(voip_tap, pinfo, stat_info);
}
datalen = tvb_length_remaining(tvb, offset);
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
new_tvb = tvb_new_subset(tvb, offset, datalen,
reported_datalen);
if (media_type_str_lower_case &&
dissector_try_string(media_type_dissector_table,
media_type_str_lower_case,
new_tvb, pinfo, rtsp_tree)){
}else {
if (ti != NULL)
proto_item_set_len(ti, offset);
if (tvb_get_guint8(tvb, offset) == RTSP_FRAMEHDR) {
datalen = 0;
} else {
proto_tree_add_text(rtsp_tree, tvb, offset,
datalen, "Data (%d bytes)",
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
proto_tree *sub_tree = NULL;
proto_item *ti = NULL;
const guchar *lineend = data + linelen;
unsigned ii;
const guchar *url;
const guchar *url_start;
guchar *tmp_url;
for (ii = 0; ii < RTSP_NMETHODS; ii++) {
size_t len = strlen(rtsp_methods[ii]);
if (linelen >= len &&
g_ascii_strncasecmp(rtsp_methods[ii], data, len) == 0 &&
(len == linelen || isspace(data[len])))
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
while (url < lineend && !isspace(*url))
url++;
while (url < lineend && isspace(*url))
url++;
url_start = url;
while (url < lineend && !isspace(*url))
url++;
tmp_url = ep_strndup(url_start, url - url_start);
proto_tree_add_string(sub_tree, hf_rtsp_url, tvb,
offset + (gint) (url_start - data), (gint) (url - url_start), tmp_url);
}
static void
process_rtsp_reply(tvbuff_t *tvb, int offset, const guchar *data,
size_t linelen, size_t next_line_offset, proto_tree *tree)
{
proto_tree *sub_tree = NULL;
proto_item *ti = NULL;
const guchar *lineend = data + linelen;
const guchar *status = data;
const guchar *status_start;
unsigned int status_i;
ti = proto_tree_add_string(tree, hf_rtsp_response, tvb, offset,
(gint) (next_line_offset - offset),
tvb_format_text(tvb, offset, (gint) (next_line_offset - offset)));
sub_tree = proto_item_add_subtree(ti, ett_rtsp_method);
while (status < lineend && !isspace(*status))
status++;
while (status < lineend && isspace(*status))
status++;
status_start = status;
status_i = 0;
while (status < lineend && isdigit(*status))
status_i = status_i * 10 + *status++ - '0';
proto_tree_add_uint(sub_tree, hf_rtsp_status, tvb,
offset + (gint) (status_start - data),
(gint) (status - status_start), status_i);
}
static void
dissect_rtsp(tvbuff_t *tvb, packet_info *pinfo, proto_tree *tree)
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
col_set_writable(pinfo->cinfo, ENC_BIG_ENDIAN);
}
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
};
module_t *rtsp_module;
proto_rtsp = proto_register_protocol("Real Time Streaming Protocol",
"RTSP", "rtsp");
proto_register_field_array(proto_rtsp, hf, array_length(hf));
proto_register_subtree_array(ett, array_length(ett));
register_dissector("rtsp", dissect_rtsp, proto_rtsp);
rtsp_module = prefs_register_protocol(proto_rtsp, proto_reg_handoff_rtsp);
prefs_register_uint_preference(rtsp_module, "tcp.port",
"RTSP TCP Port",
"Set the TCP port for RTSP messages",
10, &global_rtsp_tcp_port);
prefs_register_uint_preference(rtsp_module, "tcp.alternate_port",
"Alternate RTSP TCP Port",
"Set the alternate TCP port for RTSP messages",
10, &global_rtsp_tcp_alternate_port);
prefs_register_bool_preference(rtsp_module, "desegment_headers",
"Reassemble RTSP headers spanning multiple TCP segments",
"Whether the RTSP dissector should reassemble headers "
"of a request spanning multiple TCP segments. "
" To use this option, you must also enable \"Allow subdissectors to reassemble TCP streams\" in the TCP protocol settings.",
&rtsp_desegment_headers);
prefs_register_bool_preference(rtsp_module, "desegment_body",
"Trust the \"Content-length:\" header and\ndesegment RTSP "
"bodies\nspanning multiple TCP segments",
"Whether the RTSP dissector should use the "
"\"Content-length:\" value to desegment the body "
"of a request spanning multiple TCP segments",
&rtsp_desegment_body);
rtsp_tap = register_tap("rtsp");
}
void
proto_reg_handoff_rtsp(void)
{
static dissector_handle_t rtsp_handle;
static gboolean rtsp_prefs_initialized = FALSE;
static guint saved_rtsp_tcp_port;
static guint saved_rtsp_tcp_alternate_port;
if (!rtsp_prefs_initialized) {
rtsp_handle = find_dissector("rtsp");
rtp_handle = find_dissector("rtp");
rtcp_handle = find_dissector("rtcp");
rdt_handle = find_dissector("rdt");
media_type_dissector_table = find_dissector_table("media_type");
voip_tap = find_tap_id("voip");
rtsp_prefs_initialized = TRUE;
}
else {
dissector_delete_uint("tcp.port", saved_rtsp_tcp_port, rtsp_handle);
dissector_delete_uint("tcp.port", saved_rtsp_tcp_alternate_port, rtsp_handle);
}
dissector_add_uint("tcp.port", global_rtsp_tcp_port, rtsp_handle);
dissector_add_uint("tcp.port", global_rtsp_tcp_alternate_port, rtsp_handle);
saved_rtsp_tcp_port = global_rtsp_tcp_port;
saved_rtsp_tcp_alternate_port = global_rtsp_tcp_alternate_port;
stats_tree_register("rtsp","rtsp","RTSP/Packet Counter", 0, rtsp_stats_tree_packet, rtsp_stats_tree_init, NULL );
}
