static void
header_fields_update_cb(void *r, const char **err)
{
header_field_t *rec = (header_field_t *)r;
char c;
if (rec->header_name == NULL) {
*err = g_strdup("Header name can't be empty");
return;
}
g_strstrip(rec->header_name);
if (rec->header_name[0] == 0) {
*err = g_strdup("Header name can't be empty");
return;
}
c = proto_check_field_name(rec->header_name);
if (c) {
*err = g_strdup_printf("Header name can't contain '%c'", c);
return;
}
*err = NULL;
}
static void *
header_fields_copy_cb(void* n, const void* o, size_t siz _U_)
{
header_field_t* new_rec = (header_field_t*)n;
const header_field_t* old_rec = (const header_field_t*)o;
if (old_rec->header_name) {
new_rec->header_name = g_strdup(old_rec->header_name);
} else {
new_rec->header_name = NULL;
}
if (old_rec->header_desc) {
new_rec->header_desc = g_strdup(old_rec->header_desc);
} else {
new_rec->header_desc = NULL;
}
return new_rec;
}
static void
header_fields_free_cb(void*r)
{
header_field_t* rec = (header_field_t*)r;
if (rec->header_name)
g_free(rec->header_name);
if (rec->header_desc)
g_free(rec->header_desc);
}
static void
http_reqs_stats_tree_init(stats_tree* st)
{
st_node_reqs = stats_tree_create_node(st, st_str_reqs, 0, TRUE);
st_node_reqs_by_srv_addr = stats_tree_create_node(st, st_str_reqs_by_srv_addr, st_node_reqs, TRUE);
st_node_reqs_by_http_host = stats_tree_create_node(st, st_str_reqs_by_http_host, st_node_reqs, TRUE);
st_node_resps_by_srv_addr = stats_tree_create_node(st, st_str_resps_by_srv_addr, 0, TRUE);
}
static int
http_reqs_stats_tree_packet(stats_tree* st, packet_info* pinfo, epan_dissect_t* edt _U_, const void* p)
{
const http_info_value_t* v = (const http_info_value_t*)p;
int reqs_by_this_host;
int reqs_by_this_addr;
int resps_by_this_addr;
int i = v->response_code;
gchar *ip_str;
if (v->request_method) {
ip_str = address_to_str(NULL, &pinfo->dst);
tick_stat_node(st, st_str_reqs, 0, FALSE);
tick_stat_node(st, st_str_reqs_by_srv_addr, st_node_reqs, TRUE);
tick_stat_node(st, st_str_reqs_by_http_host, st_node_reqs, TRUE);
reqs_by_this_addr = tick_stat_node(st, ip_str, st_node_reqs_by_srv_addr, TRUE);
if (v->http_host) {
reqs_by_this_host = tick_stat_node(st, v->http_host, st_node_reqs_by_http_host, TRUE);
tick_stat_node(st, ip_str, reqs_by_this_host, FALSE);
tick_stat_node(st, v->http_host, reqs_by_this_addr, FALSE);
}
wmem_free(NULL, ip_str);
return 1;
} else if (i != 0) {
ip_str = address_to_str(NULL, &pinfo->src);
tick_stat_node(st, st_str_resps_by_srv_addr, 0, FALSE);
resps_by_this_addr = tick_stat_node(st, ip_str, st_node_resps_by_srv_addr, TRUE);
if ( (i>100)&&(i<400) ) {
tick_stat_node(st, "OK", resps_by_this_addr, FALSE);
} else {
tick_stat_node(st, "KO", resps_by_this_addr, FALSE);
}
wmem_free(NULL, ip_str);
return 1;
}
return 0;
}
static void
http_req_stats_tree_init(stats_tree* st)
{
st_node_requests_by_host = stats_tree_create_node(st, st_str_requests_by_host, 0, TRUE);
}
static int
http_req_stats_tree_packet(stats_tree* st, packet_info* pinfo _U_, epan_dissect_t* edt _U_, const void* p)
{
const http_info_value_t* v = (const http_info_value_t*)p;
int reqs_by_this_host;
if (v->request_method) {
tick_stat_node(st, st_str_requests_by_host, 0, FALSE);
if (v->http_host) {
reqs_by_this_host = tick_stat_node(st, v->http_host, st_node_requests_by_host, TRUE);
if (v->request_uri) {
tick_stat_node(st, v->request_uri, reqs_by_this_host, TRUE);
}
}
return 1;
}
return 0;
}
static void
http_stats_tree_init(stats_tree* st)
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
st_node_other = stats_tree_create_node(st, st_str_other, st_node_packets,FALSE);
}
static int
http_stats_tree_packet(stats_tree* st, packet_info* pinfo _U_, epan_dissect_t* edt _U_, const void* p)
{
const http_info_value_t* v = (const http_info_value_t*)p;
guint i = v->response_code;
int resp_grp;
const gchar *resp_str;
gchar str[64];
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
g_snprintf(str, sizeof(str), "%u %s", i,
val_to_str(i, vals_status_code, "Unknown (%d)"));
tick_stat_node(st, str, resp_grp, FALSE);
} else if (v->request_method) {
stats_tree_tick_pivot(st,st_node_requests,v->request_method);
} else {
tick_stat_node(st, st_str_other, st_node_packets, FALSE);
}
return 1;
}
static void
dissect_http_ntlmssp(tvbuff_t *tvb, packet_info *pinfo, proto_tree *tree,
const char *line)
{
tvbuff_t *ntlmssp_tvb;
ntlmssp_tvb = base64_to_tvb(tvb, line);
add_new_data_source(pinfo, ntlmssp_tvb, "NTLMSSP / GSSAPI Data");
if (tvb_strneql(ntlmssp_tvb, 0, "NTLMSSP", 7) == 0)
call_dissector(ntlmssp_handle, ntlmssp_tvb, pinfo, tree);
else
call_dissector(gssapi_handle, ntlmssp_tvb, pinfo, tree);
}
static void
dissect_http_kerberos(tvbuff_t *tvb, packet_info *pinfo, proto_tree *tree,
const char *line)
{
tvbuff_t *kerberos_tvb;
kerberos_tvb = base64_to_tvb(tvb, line + 9);
add_new_data_source(pinfo, kerberos_tvb, "Kerberos Data");
call_dissector(gssapi_handle, kerberos_tvb, pinfo, tree);
}
static http_conv_t *
get_http_conversation_data(packet_info *pinfo)
{
conversation_t *conversation;
http_conv_t *conv_data;
conversation = find_or_create_conversation(pinfo);
conv_data = (http_conv_t *)conversation_get_proto_data(conversation, proto_http);
if(!conv_data) {
conv_data = (http_conv_t *)wmem_alloc0(wmem_file_scope(), sizeof(http_conv_t));
conversation_add_proto_data(conversation, proto_http,
conv_data);
}
return conv_data;
}
static http_req_res_t* push_req_res(http_conv_t *conv_data)
{
http_req_res_t *req_res = (http_req_res_t *)wmem_alloc0(wmem_file_scope(), sizeof(http_req_res_t));
nstime_set_unset(&(req_res->req_ts));
req_res->number = ++conv_data->req_res_num;
if (! conv_data->req_res_tail) {
conv_data->req_res_tail = req_res;
} else {
req_res->prev = conv_data->req_res_tail;
conv_data->req_res_tail->next = req_res;
conv_data->req_res_tail = req_res;
}
return req_res;
}
static void push_req(http_conv_t *conv_data, packet_info *pinfo)
{
http_req_res_t *req_res = push_req_res(conv_data);
req_res->req_framenum = pinfo->fd->num;
req_res->req_ts = pinfo->fd->abs_ts;
p_add_proto_data(wmem_file_scope(), pinfo, proto_http, 0, req_res);
}
static void push_res(http_conv_t *conv_data, packet_info *pinfo)
{
http_req_res_t *req_res = conv_data->req_res_tail;
if (!req_res || req_res->res_framenum > 0) {
req_res = push_req_res(conv_data);
}
req_res->res_framenum = pinfo->fd->num;
p_add_proto_data(wmem_file_scope(), pinfo, proto_http, 0, req_res);
}
static int
dissect_http_message(tvbuff_t *tvb, int offset, packet_info *pinfo,
proto_tree *tree, http_conv_t *conv_data)
{
const char *proto_tag;
proto_tree *http_tree = NULL;
proto_item *ti = NULL;
proto_item *hidden_item;
const guchar *line, *firstline;
gint next_offset;
const guchar *linep, *lineend;
int orig_offset;
int first_linelen, linelen;
gboolean is_request_or_reply, is_ssl = FALSE;
gboolean saw_req_resp_or_header;
guchar c;
http_type_t http_type;
proto_item *hdr_item = NULL;
ReqRespDissector reqresp_dissector;
proto_tree *req_tree;
int colon_offset;
headers_t headers;
int datalen;
int reported_datalen = -1;
dissector_handle_t handle;
gboolean dissected = FALSE;
gboolean first_loop = TRUE;
http_eo_t *eo_info;
heur_dtbl_entry_t *hdtbl_entry;
int reported_length;
guint16 word;
gboolean leading_crlf = FALSE;
reported_length = tvb_reported_length_remaining(tvb, offset);
if (reported_length < 1) {
return -1;
}
if(reported_length > 3){
word = tvb_get_ntohs(tvb,offset);
if(word == 0x0d0a){
leading_crlf = TRUE;
offset+=2;
}
}
if (!g_ascii_isprint(tvb_get_guint8(tvb, offset))) {
return -1;
}
first_linelen = tvb_find_line_end(tvb, offset,
tvb_ensure_captured_length_remaining(tvb, offset), &next_offset,
TRUE);
if (first_linelen == -1) {
if (!req_resp_hdrs_do_reassembly(tvb, offset, pinfo,
http_desegment_headers, http_desegment_body)) {
return -1;
}
}
firstline = tvb_get_ptr(tvb, offset, first_linelen);
http_type = HTTP_OTHERS;
is_request_or_reply = is_http_request_or_reply((const gchar *)firstline,
first_linelen, &http_type, NULL, conv_data);
if (is_request_or_reply) {
gboolean try_desegment_body = http_desegment_body &&
!(conv_data->request_method &&
g_str_equal(conv_data->request_method, "HEAD"));
if (!req_resp_hdrs_do_reassembly(tvb, offset, pinfo,
http_desegment_headers, try_desegment_body)) {
return -1;
}
}
proto_get_frame_protocols(pinfo->layers, NULL, NULL, NULL, NULL, &is_ssl);
stat_info = wmem_new(wmem_packet_scope(), http_info_value_t);
stat_info->framenum = pinfo->fd->num;
stat_info->response_code = 0;
stat_info->request_method = NULL;
stat_info->request_uri = NULL;
stat_info->http_host = NULL;
switch (pinfo->match_uint) {
case TCP_PORT_SSDP:
proto_tag = "SSDP";
break;
default:
proto_tag = "HTTP";
break;
}
orig_offset = offset;
http_type = HTTP_OTHERS;
headers.content_type = NULL;
headers.content_type_parameters = NULL;
headers.have_content_length = FALSE;
headers.content_length = 0;
headers.content_encoding = NULL;
headers.transfer_encoding = NULL;
headers.upgrade = 0;
saw_req_resp_or_header = FALSE;
while (tvb_reported_length_remaining(tvb, offset) > 0) {
linelen = tvb_find_line_end(tvb, offset,
tvb_ensure_captured_length_remaining(tvb, offset), &next_offset,
FALSE);
if (linelen < 0)
return -1;
line = tvb_get_ptr(tvb, offset, linelen);
lineend = line + linelen;
colon_offset = -1;
reqresp_dissector = NULL;
is_request_or_reply =
is_http_request_or_reply((const gchar *)line,
linelen, &http_type, &reqresp_dissector, conv_data);
if (is_request_or_reply)
goto is_http;
if (linelen == 0)
goto is_http;
linep = line;
colon_offset = offset;
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
case ' ':
goto not_http;
case ':':
goto is_http;
default:
colon_offset++;
break;
}
}
if (saw_req_resp_or_header)
tvb_ensure_bytes_exist(tvb, offset, linelen + 1);
not_http:
break;
is_http:
if (first_loop) {
col_set_str(pinfo->cinfo, COL_PROTOCOL, proto_tag);
if (is_request_or_reply)
col_add_fstr(pinfo->cinfo, COL_INFO, "%s ", format_text(firstline, first_linelen));
else
col_set_str(pinfo->cinfo, COL_INFO, "Continuation");
}
if ((tree) && (http_tree == NULL)) {
ti = proto_tree_add_item(tree, proto_http, tvb, orig_offset, -1, ENC_NA);
http_tree = proto_item_add_subtree(ti, ett_http);
if(leading_crlf){
proto_tree_add_expert(http_tree, pinfo, &ei_http_leading_crlf, tvb, orig_offset-2, 2);
}
}
if (first_loop && !is_ssl && pinfo->ptype == PT_TCP &&
(pinfo->srcport == 443 || pinfo->destport == 443)) {
expert_add_info(pinfo, ti, &ei_http_ssl_port);
}
first_loop = FALSE;
if (linelen == 0) {
proto_tree_add_format_text(http_tree, tvb, offset, next_offset - offset);
offset = next_offset;
break;
}
saw_req_resp_or_header = TRUE;
if (is_request_or_reply) {
char *text = tvb_format_text(tvb, offset, next_offset - offset);
req_tree = proto_tree_add_subtree(http_tree, tvb,
offset, next_offset - offset, ett_http_request, &hdr_item, text);
expert_add_info_format(pinfo, hdr_item, &ei_http_chat, "%s", text);
if (reqresp_dissector) {
reqresp_dissector(tvb, req_tree, offset, line,
lineend, conv_data);
}
} else {
process_header(tvb, offset, next_offset, line, linelen,
colon_offset, pinfo, http_tree, &headers, conv_data,
http_type);
}
offset = next_offset;
}
if (tree && stat_info->http_host && stat_info->request_uri) {
proto_item *e_ti;
gchar *uri;
uri = wmem_strdup_printf(wmem_packet_scope(), "%s://%s%s",
is_ssl ? "https" : "http",
g_strstrip(wmem_strdup(wmem_packet_scope(), stat_info->http_host)), stat_info->request_uri);
e_ti = proto_tree_add_string(http_tree,
hf_http_request_full_uri, tvb, 0,
0, uri);
PROTO_ITEM_SET_URL(e_ti);
PROTO_ITEM_SET_GENERATED(e_ti);
}
if (!PINFO_FD_VISITED(pinfo)) {
if (http_type == HTTP_REQUEST) {
push_req(conv_data, pinfo);
} else if (http_type == HTTP_RESPONSE) {
push_res(conv_data, pinfo);
}
}
if (tree) {
proto_item *pi;
http_req_res_t *curr = (http_req_res_t *)p_get_proto_data(wmem_file_scope(), pinfo, proto_http, 0);
http_req_res_t *prev = curr ? curr->prev : NULL;
http_req_res_t *next = curr ? curr->next : NULL;
switch (http_type) {
case HTTP_NOTIFICATION:
hidden_item = proto_tree_add_boolean(http_tree,
hf_http_notification, tvb, 0, 0, 1);
PROTO_ITEM_SET_HIDDEN(hidden_item);
break;
case HTTP_RESPONSE:
hidden_item = proto_tree_add_boolean(http_tree,
hf_http_response, tvb, 0, 0, 1);
PROTO_ITEM_SET_HIDDEN(hidden_item);
if (curr) {
nstime_t delta;
pi = proto_tree_add_text(http_tree, tvb, 0, 0, "HTTP response %u/%u", curr->number, conv_data->req_res_num);
PROTO_ITEM_SET_GENERATED(pi);
if (! nstime_is_unset(&(curr->req_ts))) {
nstime_delta(&delta, &pinfo->fd->abs_ts, &(curr->req_ts));
pi = proto_tree_add_time(http_tree, hf_http_time, tvb, 0, 0, &delta);
PROTO_ITEM_SET_GENERATED(pi);
}
}
if (prev && prev->req_framenum) {
pi = proto_tree_add_uint(http_tree, hf_http_prev_request_in, tvb, 0, 0, prev->req_framenum);
PROTO_ITEM_SET_GENERATED(pi);
}
if (prev && prev->res_framenum) {
pi = proto_tree_add_uint(http_tree, hf_http_prev_response_in, tvb, 0, 0, prev->res_framenum);
PROTO_ITEM_SET_GENERATED(pi);
}
if (curr && curr->req_framenum) {
pi = proto_tree_add_uint(http_tree, hf_http_request_in, tvb, 0, 0, curr->req_framenum);
PROTO_ITEM_SET_GENERATED(pi);
}
if (next && next->req_framenum) {
pi = proto_tree_add_uint(http_tree, hf_http_next_request_in, tvb, 0, 0, next->req_framenum);
PROTO_ITEM_SET_GENERATED(pi);
}
if (next && next->res_framenum) {
pi = proto_tree_add_uint(http_tree, hf_http_next_response_in, tvb, 0, 0, next->res_framenum);
PROTO_ITEM_SET_GENERATED(pi);
}
break;
case HTTP_REQUEST:
hidden_item = proto_tree_add_boolean(http_tree,
hf_http_request, tvb, 0, 0, 1);
PROTO_ITEM_SET_HIDDEN(hidden_item);
if (curr) {
pi = proto_tree_add_text(http_tree, tvb, 0, 0, "HTTP request %u/%u", curr->number, conv_data->req_res_num);
PROTO_ITEM_SET_GENERATED(pi);
}
if (prev && prev->req_framenum) {
pi = proto_tree_add_uint(http_tree, hf_http_prev_request_in, tvb, 0, 0, prev->req_framenum);
PROTO_ITEM_SET_GENERATED(pi);
}
if (curr && curr->res_framenum) {
pi = proto_tree_add_uint(http_tree, hf_http_response_in, tvb, 0, 0, curr->res_framenum);
PROTO_ITEM_SET_GENERATED(pi);
}
if (next && next->req_framenum) {
pi = proto_tree_add_uint(http_tree, hf_http_next_request_in, tvb, 0, 0, next->req_framenum);
PROTO_ITEM_SET_GENERATED(pi);
}
break;
case HTTP_OTHERS:
default:
break;
}
}
reported_datalen = tvb_reported_length_remaining(tvb, offset);
datalen = tvb_captured_length_remaining(tvb, offset);
if (headers.have_content_length &&
headers.content_length != -1 &&
headers.transfer_encoding == NULL) {
if (datalen > headers.content_length)
datalen = (int)headers.content_length;
if (reported_datalen > headers.content_length)
reported_datalen = (int)headers.content_length;
} else {
switch (http_type) {
case HTTP_REQUEST:
if (headers.transfer_encoding == NULL)
datalen = 0;
else
reported_datalen = -1;
break;
case HTTP_RESPONSE:
if ((stat_info->response_code/100) == 1 ||
stat_info->response_code == 204 ||
stat_info->response_code == 304)
datalen = 0;
else {
reported_datalen = -1;
}
break;
default:
reported_datalen = -1;
break;
}
}
if (datalen > 0) {
tvbuff_t *next_tvb;
void *save_private_data = NULL;
gboolean private_data_changed = FALSE;
gint chunks_decoded = 0;
next_tvb = tvb_new_subset(tvb, offset, datalen,
reported_datalen);
if (headers.transfer_encoding != NULL &&
g_ascii_strcasecmp(headers.transfer_encoding, "identity") != 0) {
if (http_dechunk_body &&
(g_ascii_strncasecmp(headers.transfer_encoding, "chunked", 7)
== 0)) {
chunks_decoded = chunked_encoding_dissector(
&next_tvb, pinfo, http_tree, 0);
if (chunks_decoded <= 0) {
goto body_dissected;
} else {
#if 0
tvb_set_child_real_data_tvbuff(tvb,
next_tvb);
#endif
add_new_data_source(pinfo, next_tvb,
"De-chunked entity body");
}
} else {
call_dissector(data_handle, next_tvb, pinfo,
http_tree);
goto body_dissected;
}
}
if (headers.content_encoding != NULL &&
g_ascii_strcasecmp(headers.content_encoding, "identity") != 0) {
tvbuff_t *uncomp_tvb = NULL;
proto_item *e_ti = NULL;
proto_tree *e_tree = NULL;
if (http_decompress_body &&
(g_ascii_strcasecmp(headers.content_encoding, "gzip") == 0 ||
g_ascii_strcasecmp(headers.content_encoding, "deflate") == 0 ||
g_ascii_strcasecmp(headers.content_encoding, "x-gzip") == 0 ||
g_ascii_strcasecmp(headers.content_encoding, "x-deflate") == 0))
{
uncomp_tvb = tvb_child_uncompress(tvb, next_tvb, 0,
tvb_captured_length(next_tvb));
}
e_tree = proto_tree_add_subtree_format(http_tree, next_tvb,
0, tvb_captured_length(next_tvb), ett_http_encoded_entity, &e_ti,
"Content-encoded entity body (%s): %u bytes",
headers.content_encoding,
tvb_captured_length(next_tvb));
if (uncomp_tvb != NULL) {
proto_item_append_text(e_ti, " -> %u bytes", tvb_captured_length(uncomp_tvb));
next_tvb = uncomp_tvb;
add_new_data_source(pinfo, next_tvb,
"Uncompressed entity body");
} else {
proto_item_append_text(e_ti, " [Error: Decompression failed]");
call_dissector(data_handle, next_tvb, pinfo,
e_tree);
goto body_dissected;
}
}
if(have_tap_listener(http_eo_tap)) {
eo_info = wmem_new(wmem_packet_scope(), http_eo_t);
eo_info->hostname = conv_data->http_host;
eo_info->filename = conv_data->request_uri;
eo_info->content_type = headers.content_type;
eo_info->payload_len = tvb_captured_length(next_tvb);
eo_info->payload_data = tvb_get_ptr(next_tvb, 0, eo_info->payload_len);
tap_queue_packet(http_eo_tap, pinfo, eo_info);
}
handle = NULL;
if (headers.content_type != NULL) {
save_private_data = pinfo->private_data;
private_data_changed = TRUE;
if (headers.content_type_parameters)
pinfo->private_data = wmem_strdup(wmem_packet_scope(), headers.content_type_parameters);
else
pinfo->private_data = NULL;
pinfo->match_string = headers.content_type;
handle = dissector_get_string_handle(
media_type_subdissector_table,
headers.content_type);
if (handle == NULL &&
strncmp(headers.content_type, "multipart/", sizeof("multipart/")-1) == 0) {
handle = dissector_get_string_handle(
media_type_subdissector_table,
"multipart/");
}
}
if (handle == NULL) {
handle = dissector_get_uint_handle(port_subdissector_table,
pinfo->match_uint);
}
if (handle != NULL) {
dissected = call_dissector_only(handle, next_tvb, pinfo, tree, NULL);
if (!dissected)
expert_add_info(pinfo, http_tree, &ei_http_subdissector_failed);
}
if (!dissected) {
dissected = dissector_try_heuristic(heur_subdissector_list,
next_tvb, pinfo, tree, &hdtbl_entry, NULL);
}
if (dissected) {
if (ti != NULL)
proto_item_set_len(ti, offset);
} else {
if (headers.content_type != NULL) {
call_dissector(media_handle, next_tvb, pinfo, tree);
} else {
call_dissector(data_handle, next_tvb, pinfo, http_tree);
}
}
body_dissected:
if (private_data_changed)
pinfo->private_data = save_private_data;
offset += datalen;
}
if (http_type == HTTP_RESPONSE && pinfo->desegment_offset<=0 && pinfo->desegment_len<=0) {
conv_data->upgrade = headers.upgrade;
conv_data->startframe = pinfo->fd->num + 1;
SE_COPY_ADDRESS(&conv_data->server_addr, &pinfo->src);
conv_data->server_port = pinfo->srcport;
}
tap_queue_packet(http_tap, pinfo, stat_info);
return offset - orig_offset;
}
static void
basic_request_dissector(tvbuff_t *tvb, proto_tree *tree, int offset,
const guchar *line, const guchar *lineend,
http_conv_t *conv_data)
{
const guchar *next_token;
const gchar *request_uri;
int tokenlen;
tokenlen = get_token_len(line, lineend, &next_token);
if (tokenlen == 0)
return;
proto_tree_add_item(tree, hf_http_request_method, tvb, offset, tokenlen,
ENC_ASCII|ENC_NA);
if ((next_token - line) > 2 && next_token[-1] == ' ' && next_token[-2] == ' ') {
next_token--;
}
offset += (int) (next_token - line);
line = next_token;
tokenlen = get_token_len(line, lineend, &next_token);
request_uri = tvb_get_string_enc(wmem_packet_scope(), tvb, offset, tokenlen, ENC_ASCII);
stat_info->request_uri = wmem_strdup(wmem_packet_scope(), request_uri);
conv_data->request_uri = wmem_strdup(wmem_file_scope(), request_uri);
proto_tree_add_string(tree, hf_http_request_uri, tvb, offset, tokenlen,
request_uri);
offset += (int) (next_token - line);
line = next_token;
tokenlen = (int) (lineend - line);
proto_tree_add_item(tree, hf_http_version, tvb, offset, tokenlen,
ENC_ASCII|ENC_NA);
}
static void
basic_response_dissector(tvbuff_t *tvb, proto_tree *tree, int offset,
const guchar *line, const guchar *lineend,
http_conv_t *conv_data _U_)
{
const guchar *next_token;
int tokenlen;
gchar response_code_chars[4];
tokenlen = get_token_len(line, lineend, &next_token);
if (tokenlen == 0)
return;
proto_tree_add_item(tree, hf_http_version, tvb, offset, tokenlen,
ENC_ASCII|ENC_NA);
offset += (int) (next_token - line);
line = next_token;
tokenlen = get_token_len(line, lineend, &next_token);
if (tokenlen < 3)
return;
memcpy(response_code_chars, line, 3);
response_code_chars[3] = '\0';
stat_info->response_code = conv_data->response_code =
(guint)strtoul(response_code_chars, NULL, 10);
proto_tree_add_uint(tree, hf_http_response_code, tvb, offset, 3,
stat_info->response_code);
offset += (int) (next_token - line);
line = next_token;
tokenlen = (int) (lineend - line);
if (tokenlen < 1)
return;
proto_tree_add_item(tree, hf_http_response_phrase, tvb, offset,
tokenlen, ENC_ASCII|ENC_NA);
}
static int
chunked_encoding_dissector(tvbuff_t **tvb_ptr, packet_info *pinfo,
proto_tree *tree, int offset)
{
tvbuff_t *tvb;
guint32 datalen;
guint32 orig_datalen;
gint chunks_decoded;
gint chunked_data_size;
proto_tree *subtree;
guint8 *raw_data;
gint raw_len;
if ((tvb_ptr == NULL) || (*tvb_ptr == NULL)) {
return 0;
}
tvb = *tvb_ptr;
datalen = tvb_reported_length_remaining(tvb, offset);
subtree = proto_tree_add_subtree(tree, tvb, offset, datalen,
ett_http_chunked_response, NULL, "HTTP chunked response");
orig_datalen = datalen;
raw_data = (guint8 *)wmem_alloc(pinfo->pool, datalen);
raw_len = 0;
chunks_decoded = 0;
chunked_data_size = 0;
while (datalen > 0) {
tvbuff_t *data_tvb;
guint32 chunk_size;
gint chunk_offset;
guint8 *chunk_string;
gint linelen;
gchar *c;
linelen = tvb_find_line_end(tvb, offset, -1, &chunk_offset, TRUE);
if (linelen <= 0) {
break;
}
chunk_string = tvb_get_string_enc(wmem_packet_scope(), tvb, offset, linelen, ENC_ASCII);
if (chunk_string == NULL) {
break;
}
c = (gchar*)chunk_string;
if ((c = strchr(c, ';'))) {
*c = '\0';
}
chunk_size = (guint32)strtol((gchar*)chunk_string, NULL, 16);
if (chunk_size > datalen) {
chunk_size = datalen;
}
chunked_data_size += chunk_size;
DISSECTOR_ASSERT((raw_len+chunk_size) <= orig_datalen);
tvb_memcpy(tvb, (guint8 *)(raw_data + raw_len), chunk_offset, chunk_size);
raw_len += chunk_size;
if (subtree) {
proto_tree *chunk_subtree;
if(chunk_size == 0) {
chunk_subtree = proto_tree_add_subtree(subtree, tvb,
offset,
chunk_offset - offset + chunk_size + 2,
ett_http_chunk_data, NULL,
"End of chunked encoding");
} else {
chunk_subtree = proto_tree_add_subtree_format(subtree, tvb,
offset,
chunk_offset - offset + chunk_size + 2,
ett_http_chunk_data, NULL,
"Data chunk (%u octets)", chunk_size);
}
proto_tree_add_text(chunk_subtree, tvb, offset,
chunk_offset - offset, "Chunk size: %u octets",
chunk_size);
data_tvb = tvb_new_subset(tvb, chunk_offset, chunk_size, datalen);
call_dissector(data_handle, data_tvb, pinfo,
chunk_subtree);
proto_tree_add_text(chunk_subtree, tvb, chunk_offset +
chunk_size, 2, "Chunk boundary");
}
chunks_decoded++;
offset = chunk_offset + 2 + chunk_size;
datalen = tvb_reported_length_remaining(tvb, offset);
}
if (chunked_data_size > 0) {
tvbuff_t *new_tvb;
new_tvb = tvb_new_child_real_data(tvb, raw_data, chunked_data_size, chunked_data_size);
*tvb_ptr = new_tvb;
} else {
chunks_decoded = -1;
}
return chunks_decoded;
}
static void
http_payload_subdissector(tvbuff_t *tvb, proto_tree *tree,
packet_info *pinfo, http_conv_t *conv_data, void* data)
{
guint32 *ptr = NULL;
guint32 uri_port, saved_port, srcport, destport;
gchar **strings;
proto_item *item;
proto_tree *proxy_tree;
conversation_t *conv;
gboolean from_server = pinfo->srcport == conv_data->server_port &&
addresses_equal(&conv_data->server_addr, &pinfo->src);
strings = g_strsplit(conv_data->request_uri, ":", 2);
if(strings[0] != NULL && strings[1] != NULL) {
if(tree) {
item = proto_tree_add_item(tree, proto_http, tvb, 0, -1, ENC_NA);
proxy_tree = proto_item_add_subtree(item, ett_http);
item = proto_tree_add_string(proxy_tree, hf_http_proxy_connect_host,
tvb, 0, 0, strings[0]);
PROTO_ITEM_SET_GENERATED(item);
item = proto_tree_add_uint(proxy_tree, hf_http_proxy_connect_port,
tvb, 0, 0, (guint32)strtol(strings[1], NULL, 10) );
PROTO_ITEM_SET_GENERATED(item);
}
uri_port = (int)strtol(strings[1], NULL, 10);
if (!from_server) {
srcport = pinfo->srcport;
destport = uri_port;
} else {
srcport = uri_port;
destport = pinfo->destport;
}
conv = find_conversation(PINFO_FD_NUM(pinfo), &pinfo->src, &pinfo->dst, PT_TCP, srcport, destport, 0);
if (value_is_in_range(http_tcp_range, uri_port) || (conv && conv->dissector_handle == http_handle)) {
call_dissector(data_handle, tvb, pinfo, tree);
} else {
if (!from_server)
ptr = &pinfo->destport;
else
ptr = &pinfo->srcport;
if( pinfo->can_desegment>0 )
pinfo->can_desegment++;
saved_port = *ptr;
*ptr = uri_port;
decode_tcp_ports(tvb, 0, pinfo, tree,
pinfo->srcport, pinfo->destport, NULL,
(struct tcpinfo *)data);
*ptr = saved_port;
}
}
g_strfreev(strings);
}
static int
is_http_request_or_reply(const gchar *data, int linelen, http_type_t *type,
ReqRespDissector *reqresp_dissector,
http_conv_t *conv_data)
{
int isHttpRequestOrReply = FALSE;
if (linelen >= 2 && strncmp(data, "M-", 2) == 0) {
data += 2;
linelen -= 2;
}
if (linelen >= 5 && strncmp(data, "HTTP/", 5) == 0) {
*type = HTTP_RESPONSE;
isHttpRequestOrReply = TRUE;
if (reqresp_dissector)
*reqresp_dissector = basic_response_dissector;
} else {
const guchar * ptr = (const guchar *)data;
int indx = 0;
while (indx < linelen) {
if (*ptr == ' ')
break;
else {
ptr++;
indx++;
}
}
switch (indx) {
case 3:
if (strncmp(data, "GET", indx) == 0 ||
strncmp(data, "PUT", indx) == 0) {
*type = HTTP_REQUEST;
isHttpRequestOrReply = TRUE;
}
else if (strncmp(data, "ICY", indx) == 0) {
*type = HTTP_RESPONSE;
isHttpRequestOrReply = TRUE;
}
break;
case 4:
if (strncmp(data, "COPY", indx) == 0 ||
strncmp(data, "HEAD", indx) == 0 ||
strncmp(data, "LOCK", indx) == 0 ||
strncmp(data, "MOVE", indx) == 0 ||
strncmp(data, "POLL", indx) == 0 ||
strncmp(data, "POST", indx) == 0) {
*type = HTTP_REQUEST;
isHttpRequestOrReply = TRUE;
}
break;
case 5:
if (strncmp(data, "BCOPY", indx) == 0 ||
strncmp(data, "BMOVE", indx) == 0 ||
strncmp(data, "MKCOL", indx) == 0 ||
strncmp(data, "TRACE", indx) == 0 ||
strncmp(data, "LABEL", indx) == 0 ||
strncmp(data, "MERGE", indx) == 0) {
*type = HTTP_REQUEST;
isHttpRequestOrReply = TRUE;
}
break;
case 6:
if (strncmp(data, "DELETE", indx) == 0 ||
strncmp(data, "SEARCH", indx) == 0 ||
strncmp(data, "UNLOCK", indx) == 0 ||
strncmp(data, "REPORT", indx) == 0 ||
strncmp(data, "UPDATE", indx) == 0) {
*type = HTTP_REQUEST;
isHttpRequestOrReply = TRUE;
}
else if (strncmp(data, "NOTIFY", indx) == 0) {
*type = HTTP_NOTIFICATION;
isHttpRequestOrReply = TRUE;
}
break;
case 7:
if (strncmp(data, "BDELETE", indx) == 0 ||
strncmp(data, "CONNECT", indx) == 0 ||
strncmp(data, "OPTIONS", indx) == 0 ||
strncmp(data, "CHECKIN", indx) == 0) {
*type = HTTP_REQUEST;
isHttpRequestOrReply = TRUE;
}
break;
case 8:
if (strncmp(data, "PROPFIND", indx) == 0 ||
strncmp(data, "CHECKOUT", indx) == 0 ||
strncmp(data, "CCM_POST", indx) == 0) {
*type = HTTP_REQUEST;
isHttpRequestOrReply = TRUE;
}
break;
case 9:
if (strncmp(data, "SUBSCRIBE", indx) == 0) {
*type = HTTP_NOTIFICATION;
isHttpRequestOrReply = TRUE;
} else if (strncmp(data, "PROPPATCH", indx) == 0 ||
strncmp(data, "BPROPFIND", indx) == 0) {
*type = HTTP_REQUEST;
isHttpRequestOrReply = TRUE;
}
break;
case 10:
if (strncmp(data, "BPROPPATCH", indx) == 0 ||
strncmp(data, "UNCHECKOUT", indx) == 0 ||
strncmp(data, "MKACTIVITY", indx) == 0) {
*type = HTTP_REQUEST;
isHttpRequestOrReply = TRUE;
}
break;
case 11:
if (strncmp(data, "MKWORKSPACE", indx) == 0 ||
strncmp(data, "RPC_CONNECT", indx) == 0 ||
strncmp(data, "RPC_IN_DATA", indx) == 0) {
*type = HTTP_REQUEST;
isHttpRequestOrReply = TRUE;
} else if (strncmp(data, "UNSUBSCRIBE", indx) == 0) {
*type = HTTP_NOTIFICATION;
isHttpRequestOrReply = TRUE;
}
break;
case 12:
if (strncmp(data, "RPC_OUT_DATA", indx) == 0) {
*type = HTTP_REQUEST;
isHttpRequestOrReply = TRUE;
}
break;
case 15:
if (strncmp(data, "VERSION-CONTROL", indx) == 0) {
*type = HTTP_REQUEST;
isHttpRequestOrReply = TRUE;
}
break;
case 16:
if (strncmp(data, "BASELINE-CONTROL", indx) == 0) {
*type = HTTP_REQUEST;
isHttpRequestOrReply = TRUE;
}
break;
default:
break;
}
if (isHttpRequestOrReply && reqresp_dissector) {
*reqresp_dissector = basic_request_dissector;
stat_info->request_method = wmem_strndup(wmem_packet_scope(), data, indx);
conv_data->request_method = wmem_strndup(wmem_file_scope(), data, indx);
}
}
return isHttpRequestOrReply;
}
static gint*
get_hf_for_header(char* header_name)
{
gint* hf_id = NULL;
if (header_fields_hash) {
hf_id = (gint*) g_hash_table_lookup(header_fields_hash, header_name);
} else {
hf_id = NULL;
}
return hf_id;
}
static void
header_fields_initialize_cb(void)
{
static hf_register_info* hf;
gint* hf_id;
guint i;
gchar* header_name;
if (header_fields_hash && hf) {
guint hf_size = g_hash_table_size (header_fields_hash);
for (i = 0; i < hf_size; i++) {
proto_unregister_field (proto_http, *(hf[i].p_id));
g_free (hf[i].p_id);
g_free ((char *) hf[i].hfinfo.name);
g_free ((char *) hf[i].hfinfo.abbrev);
g_free ((char *) hf[i].hfinfo.blurb);
}
g_hash_table_destroy (header_fields_hash);
g_free (hf);
header_fields_hash = NULL;
}
if (num_header_fields) {
header_fields_hash = g_hash_table_new(g_str_hash, g_str_equal);
hf = g_new0(hf_register_info, num_header_fields);
for (i = 0; i < num_header_fields; i++) {
hf_id = g_new(gint,1);
*hf_id = -1;
header_name = g_strdup(header_fields[i].header_name);
hf[i].p_id = hf_id;
hf[i].hfinfo.name = header_name;
hf[i].hfinfo.abbrev = g_strdup_printf("http.header.%s", header_name);
hf[i].hfinfo.type = FT_STRING;
hf[i].hfinfo.display = BASE_NONE;
hf[i].hfinfo.strings = NULL;
hf[i].hfinfo.blurb = g_strdup(header_fields[i].header_desc);
hf[i].hfinfo.same_name_prev_id = -1;
hf[i].hfinfo.same_name_next = NULL;
g_hash_table_insert(header_fields_hash, header_name, hf_id);
}
proto_register_field_array(proto_http, hf, num_header_fields);
}
}
static void
process_header(tvbuff_t *tvb, int offset, int next_offset,
const guchar *line, int linelen, int colon_offset,
packet_info *pinfo, proto_tree *tree, headers_t *eh_ptr,
http_conv_t *conv_data, int http_type)
{
int len;
int line_end_offset;
int header_len;
gint hf_index;
guchar c;
int value_offset;
int value_len;
char *value;
char *header_name;
char *p;
guchar *up;
proto_item *hdr_item, *it;
int i;
int* hf_id;
len = next_offset - offset;
line_end_offset = offset + linelen;
header_len = colon_offset - offset;
header_name = wmem_strndup(wmem_file_scope(), &line[0], header_len);
hf_index = find_header_hf_value(tvb, offset, header_len);
value_offset = colon_offset + 1;
while (value_offset < line_end_offset
&& ((c = line[value_offset - offset]) == ' ' || c == '\t'))
value_offset++;
value_len = line_end_offset - value_offset;
value = (char *)wmem_alloc(wmem_packet_scope(), value_len+1);
memcpy(value, &line[value_offset - offset], value_len);
value[value_len] = '\0';
if (hf_index == -1) {
hf_id = get_hf_for_header(header_name);
if (tree) {
if (!hf_id) {
if (http_type == HTTP_REQUEST ||
http_type == HTTP_RESPONSE) {
it = proto_tree_add_item(tree,
http_type == HTTP_RESPONSE ?
hf_http_response_line :
hf_http_request_line,
tvb, offset, len,
ENC_NA|ENC_ASCII);
proto_item_set_text(it, "%s",
format_text(line, len));
} else {
proto_tree_add_text(tree, tvb, offset,
len, "%s", format_text(line, len));
}
} else {
proto_tree_add_string_format(tree,
*hf_id, tvb, offset, len,
value, "%s", format_text(line, len));
if (http_type == HTTP_REQUEST ||
http_type == HTTP_RESPONSE) {
it = proto_tree_add_item(tree,
http_type == HTTP_RESPONSE ?
hf_http_response_line :
hf_http_request_line,
tvb, offset, len,
ENC_NA|ENC_ASCII);
proto_item_set_text(it, "%s",
format_text(line, len));
PROTO_ITEM_SET_HIDDEN(it);
}
}
}
} else {
if (tree) {
header_field_info *hfinfo;
guint32 tmp;
hfinfo = proto_registrar_get_nth(*headers[hf_index].hf);
switch(hfinfo->type){
case FT_UINT8:
case FT_UINT16:
case FT_UINT24:
case FT_UINT32:
case FT_INT8:
case FT_INT16:
case FT_INT24:
case FT_INT32:
tmp=(guint32)strtol(value, NULL, 10);
hdr_item = proto_tree_add_uint(tree, *headers[hf_index].hf, tvb, offset, len, tmp);
if (http_type == HTTP_REQUEST ||
http_type == HTTP_RESPONSE) {
it = proto_tree_add_item(tree,
http_type == HTTP_RESPONSE ?
hf_http_response_line :
hf_http_request_line,
tvb, offset, len,
ENC_NA|ENC_ASCII);
proto_item_set_text(it, "%d", tmp);
PROTO_ITEM_SET_HIDDEN(it);
}
break;
default:
hdr_item = proto_tree_add_string_format(tree,
*headers[hf_index].hf, tvb, offset, len,
value, "%s", format_text(line, len));
if (http_type == HTTP_REQUEST ||
http_type == HTTP_RESPONSE) {
it = proto_tree_add_item(tree,
http_type == HTTP_RESPONSE ?
hf_http_response_line :
hf_http_request_line,
tvb, offset, len,
ENC_NA|ENC_ASCII);
proto_item_set_text(it, "%s",
format_text(line, len));
PROTO_ITEM_SET_HIDDEN(it);
}
}
} else
hdr_item = NULL;
switch (headers[hf_index].special) {
case HDR_AUTHORIZATION:
if (check_auth_ntlmssp(hdr_item, tvb, pinfo, value))
break;
if (check_auth_basic(hdr_item, tvb, value))
break;
check_auth_kerberos(hdr_item, tvb, pinfo, value);
break;
case HDR_AUTHENTICATE:
if (check_auth_ntlmssp(hdr_item, tvb, pinfo, value))
break;
check_auth_kerberos(hdr_item, tvb, pinfo, value);
break;
case HDR_CONTENT_TYPE:
eh_ptr->content_type = (gchar*) wmem_memdup(wmem_packet_scope(), (guint8*)value,value_len + 1);
for (i = 0; i < value_len; i++) {
c = value[i];
if (c == ';' || g_ascii_isspace(c)) {
break;
}
eh_ptr->content_type[i] = g_ascii_tolower(eh_ptr->content_type[i]);
}
eh_ptr->content_type[i] = '\0';
i++;
while (i < value_len) {
c = eh_ptr->content_type[i];
if (c == ';' || g_ascii_isspace(c))
i++;
else
break;
}
if (i < value_len)
eh_ptr->content_type_parameters = eh_ptr->content_type + i;
else
eh_ptr->content_type_parameters = NULL;
break;
case HDR_CONTENT_LENGTH:
errno = 0;
eh_ptr->content_length = g_ascii_strtoll(value, &p, 10);
up = (guchar *)p;
if (eh_ptr->content_length < 0 ||
p == value ||
errno == ERANGE ||
(*up != '\0' && !isspace(*up))) {
eh_ptr->have_content_length = FALSE;
} else {
proto_tree *header_tree;
proto_item *tree_item;
eh_ptr->have_content_length = TRUE;
header_tree = proto_item_add_subtree(hdr_item, ett_http_header_item);
tree_item = proto_tree_add_uint64(header_tree, hf_http_content_length,
tvb, offset, len, eh_ptr->content_length);
PROTO_ITEM_SET_GENERATED(tree_item);
if (eh_ptr->transfer_encoding != NULL &&
g_ascii_strncasecmp(eh_ptr->transfer_encoding, "chunked", 7) == 0) {
expert_add_info(pinfo, hdr_item, &ei_http_chunked_and_length);
}
}
break;
case HDR_CONTENT_ENCODING:
eh_ptr->content_encoding = wmem_strndup(wmem_packet_scope(), value, value_len);
break;
case HDR_TRANSFER_ENCODING:
eh_ptr->transfer_encoding = wmem_strndup(wmem_packet_scope(), value, value_len);
if (eh_ptr->have_content_length &&
g_ascii_strncasecmp(eh_ptr->transfer_encoding, "chunked", 7) == 0) {
expert_add_info(pinfo, hdr_item, &ei_http_chunked_and_length);
}
break;
case HDR_HOST:
stat_info->http_host = wmem_strndup(wmem_packet_scope(), value, value_len);
conv_data->http_host = wmem_strndup(wmem_file_scope(), value, value_len);
break;
case HDR_UPGRADE:
if (g_ascii_strncasecmp(value, "WebSocket", value_len) == 0){
eh_ptr->upgrade = UPGRADE_WEBSOCKET;
}
if ( (g_str_has_prefix(value, "h2")) == 1){
eh_ptr->upgrade = UPGRADE_HTTP2;
}
break;
case HDR_COOKIE:
if (hdr_item) {
proto_tree *cookie_tree;
char *part, *part_end;
int part_len;
cookie_tree = proto_item_add_subtree(hdr_item, ett_http_header_item);
for (i = 0; i < value_len; ) {
c = value[i];
while (c == ';' || g_ascii_isspace(c))
c = value[++i];
if (i >= value_len)
break;
part = value + i;
part_end = (char *)memchr(part, ';', value_len - i);
if (part_end)
part_len =(int)(part_end - part);
else
part_len = value_len - i;
proto_tree_add_item(cookie_tree, hf_http_cookie_pair,
tvb, value_offset + i, part_len, ENC_NA|ENC_ASCII);
i += part_len;
}
}
break;
}
}
}
static gint
find_header_hf_value(tvbuff_t *tvb, int offset, guint header_len)
{
guint i;
for (i = 0; i < array_length(headers); i++) {
if (header_len == strlen(headers[i].name) &&
tvb_strncaseeql(tvb, offset,
headers[i].name, header_len) == 0)
return i;
}
return -1;
}
static gboolean
check_auth_ntlmssp(proto_item *hdr_item, tvbuff_t *tvb, packet_info *pinfo, gchar *value)
{
static const char *ntlm_headers[] = {
"NTLM ",
"Negotiate ",
NULL
};
const char **header;
size_t hdrlen;
proto_tree *hdr_tree;
for (header = &ntlm_headers[0]; *header != NULL; header++) {
hdrlen = strlen(*header);
if (strncmp(value, *header, hdrlen) == 0) {
if (hdr_item != NULL) {
hdr_tree = proto_item_add_subtree(hdr_item,
ett_http_ntlmssp);
} else
hdr_tree = NULL;
value += hdrlen;
dissect_http_ntlmssp(tvb, pinfo, hdr_tree, value);
return TRUE;
}
}
return FALSE;
}
static gboolean
check_auth_basic(proto_item *hdr_item, tvbuff_t *tvb, gchar *value)
{
static const char *basic_headers[] = {
"Basic ",
NULL
};
const char **header;
size_t hdrlen;
proto_tree *hdr_tree;
for (header = &basic_headers[0]; *header != NULL; header++) {
hdrlen = strlen(*header);
if (strncmp(value, *header, hdrlen) == 0) {
if (hdr_item != NULL) {
hdr_tree = proto_item_add_subtree(hdr_item,
ett_http_ntlmssp);
} else
hdr_tree = NULL;
value += hdrlen;
ws_base64_decode_inplace(value);
proto_tree_add_string(hdr_tree, hf_http_basic, tvb,
0, 0, value);
return TRUE;
}
}
return FALSE;
}
static gboolean
check_auth_kerberos(proto_item *hdr_item, tvbuff_t *tvb, packet_info *pinfo, const gchar *value)
{
proto_tree *hdr_tree;
if (strncmp(value, "Kerberos ", 9) == 0) {
if (hdr_item != NULL) {
hdr_tree = proto_item_add_subtree(hdr_item, ett_http_kerberos);
} else
hdr_tree = NULL;
dissect_http_kerberos(tvb, pinfo, hdr_tree, value);
return TRUE;
}
return FALSE;
}
static int
dissect_http(tvbuff_t *tvb, packet_info *pinfo, proto_tree *tree, void* data)
{
http_conv_t *conv_data;
int offset = 0;
int len;
conv_data = get_http_conversation_data(pinfo);
if(pinfo->fd->num >= conv_data->startframe &&
conv_data->response_code == 200 &&
conv_data->request_method &&
strncmp(conv_data->request_method, "CONNECT", 7) == 0 &&
conv_data->request_uri) {
if(conv_data->startframe == 0 && !pinfo->fd->flags.visited)
conv_data->startframe = pinfo->fd->num;
http_payload_subdissector(tvb, tree, pinfo, conv_data, data);
} else {
while (tvb_reported_length_remaining(tvb, offset) > 0) {
if (conv_data->upgrade == UPGRADE_WEBSOCKET && pinfo->fd->num >= conv_data->startframe) {
call_dissector_only(websocket_handle, tvb_new_subset_remaining(tvb, offset), pinfo, tree, NULL);
break;
}
if (conv_data->upgrade == UPGRADE_HTTP2 && pinfo->fd->num >= conv_data->startframe) {
call_dissector_only(http2_handle, tvb_new_subset_remaining(tvb, offset), pinfo, tree, NULL);
break;
}
len = dissect_http_message(tvb, offset, pinfo, tree, conv_data);
if (len == -1)
break;
offset += len;
col_set_fence(pinfo->cinfo, COL_INFO);
}
}
return tvb_captured_length(tvb);
}
static gboolean
dissect_http_heur_tcp(tvbuff_t *tvb, packet_info *pinfo, proto_tree *tree, void *data)
{
gint offset = 0, next_offset, linelen;
conversation_t *conversation;
linelen = tvb_find_line_end(tvb, offset, -1, &next_offset, TRUE);
if((linelen == -1)||(linelen == 8)){
return FALSE;
}
if((tvb_strncaseeql(tvb, linelen-8, "HTTP/1.1", 8) == 0)||(tvb_strncaseeql(tvb, 0, "HTTP/1.1", 8) == 0)){
conversation = find_or_create_conversation(pinfo);
conversation_set_dissector(conversation,http_handle);
dissect_http(tvb, pinfo, tree, data);
return TRUE;
}
return FALSE;
}
static void
dissect_http_udp(tvbuff_t *tvb, packet_info *pinfo, proto_tree *tree)
{
http_conv_t *conv_data;
conv_data = get_http_conversation_data(pinfo);
dissect_http_message(tvb, 0, pinfo, tree, conv_data);
}
static void
range_delete_http_ssl_callback(guint32 port) {
ssl_dissector_delete(port, "http", TRUE);
}
static void
range_add_http_ssl_callback(guint32 port) {
ssl_dissector_add(port, "http", TRUE);
}
static void reinit_http(void) {
dissector_delete_uint_range("tcp.port", http_tcp_range, http_handle);
g_free(http_tcp_range);
http_tcp_range = range_copy(global_http_tcp_range);
dissector_add_uint_range("tcp.port", http_tcp_range, http_handle);
range_foreach(http_ssl_range, range_delete_http_ssl_callback);
g_free(http_ssl_range);
http_ssl_range = range_copy(global_http_ssl_range);
range_foreach(http_ssl_range, range_add_http_ssl_callback);
}
void
proto_register_http(void)
{
static hf_register_info hf[] = {
{ &hf_http_notification,
{ "Notification", "http.notification",
FT_BOOLEAN, BASE_NONE, NULL, 0x0,
"TRUE if HTTP notification", HFILL }},
{ &hf_http_response,
{ "Response", "http.response",
FT_BOOLEAN, BASE_NONE, NULL, 0x0,
"TRUE if HTTP response", HFILL }},
{ &hf_http_request,
{ "Request", "http.request",
FT_BOOLEAN, BASE_NONE, NULL, 0x0,
"TRUE if HTTP request", HFILL }},
{ &hf_http_basic,
{ "Credentials", "http.authbasic",
FT_STRING, BASE_NONE, NULL, 0x0, NULL, HFILL }},
{ &hf_http_response_line,
{ "Response line", "http.response.line",
FT_STRING, BASE_NONE, NULL, 0x0, NULL, HFILL }},
{ &hf_http_request_line,
{ "Request line", "http.request.line",
FT_STRING, BASE_NONE, NULL, 0x0, NULL, HFILL }},
{ &hf_http_request_method,
{ "Request Method", "http.request.method",
FT_STRING, BASE_NONE, NULL, 0x0,
"HTTP Request Method", HFILL }},
{ &hf_http_request_uri,
{ "Request URI", "http.request.uri",
FT_STRING, BASE_NONE, NULL, 0x0,
"HTTP Request-URI", HFILL }},
{ &hf_http_version,
{ "Request Version", "http.request.version",
FT_STRING, BASE_NONE, NULL, 0x0,
"HTTP Request HTTP-Version", HFILL }},
{ &hf_http_request_full_uri,
{ "Full request URI", "http.request.full_uri",
FT_STRING, BASE_NONE, NULL, 0x0,
"The full requested URI (including host name)", HFILL }},
{ &hf_http_response_code,
{ "Status Code", "http.response.code",
FT_UINT16, BASE_DEC, NULL, 0x0,
"HTTP Response Status Code", HFILL }},
{ &hf_http_response_phrase,
{ "Response Phrase", "http.response.phrase",
FT_STRING, BASE_NONE, NULL, 0x0,
"HTTP Response Reason Phrase", HFILL }},
{ &hf_http_authorization,
{ "Authorization", "http.authorization",
FT_STRING, BASE_NONE, NULL, 0x0,
"HTTP Authorization header", HFILL }},
{ &hf_http_proxy_authenticate,
{ "Proxy-Authenticate", "http.proxy_authenticate",
FT_STRING, BASE_NONE, NULL, 0x0,
"HTTP Proxy-Authenticate header", HFILL }},
{ &hf_http_proxy_authorization,
{ "Proxy-Authorization", "http.proxy_authorization",
FT_STRING, BASE_NONE, NULL, 0x0,
"HTTP Proxy-Authorization header", HFILL }},
{ &hf_http_proxy_connect_host,
{ "Proxy-Connect-Hostname", "http.proxy_connect_host",
FT_STRING, BASE_NONE, NULL, 0x0,
"HTTP Proxy Connect Hostname", HFILL }},
{ &hf_http_proxy_connect_port,
{ "Proxy-Connect-Port", "http.proxy_connect_port",
FT_UINT16, BASE_DEC, NULL, 0x0,
"HTTP Proxy Connect Port", HFILL }},
{ &hf_http_www_authenticate,
{ "WWW-Authenticate", "http.www_authenticate",
FT_STRING, BASE_NONE, NULL, 0x0,
"HTTP WWW-Authenticate header", HFILL }},
{ &hf_http_content_type,
{ "Content-Type", "http.content_type",
FT_STRING, BASE_NONE, NULL, 0x0,
"HTTP Content-Type header", HFILL }},
{ &hf_http_content_length_header,
{ "Content-Length", "http.content_length_header",
FT_STRING, BASE_NONE, NULL, 0x0,
"HTTP Content-Length header", HFILL }},
{ &hf_http_content_length,
{ "Content length", "http.content_length",
FT_UINT64, BASE_DEC, NULL, 0x0,
NULL, HFILL }},
{ &hf_http_content_encoding,
{ "Content-Encoding", "http.content_encoding",
FT_STRING, BASE_NONE, NULL, 0x0,
"HTTP Content-Encoding header", HFILL }},
{ &hf_http_transfer_encoding,
{ "Transfer-Encoding", "http.transfer_encoding",
FT_STRING, BASE_NONE, NULL, 0x0,
"HTTP Transfer-Encoding header", HFILL }},
{ &hf_http_upgrade,
{ "Upgrade", "http.upgrade",
FT_STRING, BASE_NONE, NULL, 0x0,
"HTTP Upgrade header", HFILL }},
{ &hf_http_user_agent,
{ "User-Agent", "http.user_agent",
FT_STRING, BASE_NONE, NULL, 0x0,
"HTTP User-Agent header", HFILL }},
{ &hf_http_host,
{ "Host", "http.host",
FT_STRING, BASE_NONE, NULL, 0x0,
"HTTP Host", HFILL }},
{ &hf_http_connection,
{ "Connection", "http.connection",
FT_STRING, BASE_NONE, NULL, 0x0,
"HTTP Connection", HFILL }},
{ &hf_http_cookie,
{ "Cookie", "http.cookie",
FT_STRING, BASE_NONE, NULL, 0x0,
"HTTP Cookie", HFILL }},
{ &hf_http_cookie_pair,
{ "Cookie pair", "http.cookie_pair",
FT_STRING, BASE_NONE, NULL, 0x0,
"A name/value HTTP cookie pair", HFILL }},
{ &hf_http_accept,
{ "Accept", "http.accept",
FT_STRING, BASE_NONE, NULL, 0x0,
"HTTP Accept", HFILL }},
{ &hf_http_referer,
{ "Referer", "http.referer",
FT_STRING, BASE_NONE, NULL, 0x0,
"HTTP Referer", HFILL }},
{ &hf_http_accept_language,
{ "Accept-Language", "http.accept_language",
FT_STRING, BASE_NONE, NULL, 0x0,
"HTTP Accept Language", HFILL }},
{ &hf_http_accept_encoding,
{ "Accept Encoding", "http.accept_encoding",
FT_STRING, BASE_NONE, NULL, 0x0,
"HTTP Accept Encoding", HFILL }},
{ &hf_http_date,
{ "Date", "http.date",
FT_STRING, BASE_NONE, NULL, 0x0,
"HTTP Date", HFILL }},
{ &hf_http_cache_control,
{ "Cache-Control", "http.cache_control",
FT_STRING, BASE_NONE, NULL, 0x0,
"HTTP Cache Control", HFILL }},
{ &hf_http_server,
{ "Server", "http.server",
FT_STRING, BASE_NONE, NULL, 0x0,
"HTTP Server", HFILL }},
{ &hf_http_location,
{ "Location", "http.location",
FT_STRING, BASE_NONE, NULL, 0x0,
"HTTP Location", HFILL }},
{ &hf_http_sec_websocket_accept,
{ "Sec-WebSocket-Accept", "http.sec_websocket_accept",
FT_STRING, BASE_NONE, NULL, 0x0,
NULL, HFILL }},
{ &hf_http_sec_websocket_extensions,
{ "Sec-WebSocket-Extensions", "http.sec_websocket_extensions",
FT_STRING, BASE_NONE, NULL, 0x0,
NULL, HFILL }},
{ &hf_http_sec_websocket_key,
{ "Sec-WebSocket-Key", "http.sec_websocket_key",
FT_STRING, BASE_NONE, NULL, 0x0,
NULL, HFILL }},
{ &hf_http_sec_websocket_protocol,
{ "Sec-WebSocket-Protocol", "http.sec_websocket_protocol",
FT_STRING, BASE_NONE, NULL, 0x0,
NULL, HFILL }},
{ &hf_http_sec_websocket_version,
{ "Sec-WebSocket-Version", "http.sec_websocket_version",
FT_STRING, BASE_NONE, NULL, 0x0,
NULL, HFILL }},
{ &hf_http_set_cookie,
{ "Set-Cookie", "http.set_cookie",
FT_STRING, BASE_NONE, NULL, 0x0,
"HTTP Set Cookie", HFILL }},
{ &hf_http_last_modified,
{ "Last-Modified", "http.last_modified",
FT_STRING, BASE_NONE, NULL, 0x0,
"HTTP Last Modified", HFILL }},
{ &hf_http_x_forwarded_for,
{ "X-Forwarded-For", "http.x_forwarded_for",
FT_STRING, BASE_NONE, NULL, 0x0,
"HTTP X-Forwarded-For", HFILL }},
{ &hf_http_request_in,
{ "Request in frame", "http.request_in",
FT_FRAMENUM, BASE_NONE, NULL, 0,
"This packet is a response to the packet with this number", HFILL }},
{ &hf_http_response_in,
{ "Response in frame","http.response_in",
FT_FRAMENUM, BASE_NONE, NULL, 0,
"This packet will be responded in the packet with this number", HFILL }},
{ &hf_http_next_request_in,
{ "Next request in frame", "http.next_request_in",
FT_FRAMENUM, BASE_NONE, NULL, 0,
"The next HTTP request starts in packet number", HFILL }},
{ &hf_http_next_response_in,
{ "Next response in frame","http.next_response_in",
FT_FRAMENUM, BASE_NONE, NULL, 0,
"The next HTTP response starts in packet number", HFILL }},
{ &hf_http_prev_request_in,
{ "Prev request in frame", "http.prev_request_in",
FT_FRAMENUM, BASE_NONE, NULL, 0,
"The previous HTTP request starts in packet number", HFILL }},
{ &hf_http_prev_response_in,
{ "Prev response in frame","http.prev_response_in",
FT_FRAMENUM, BASE_NONE, NULL, 0,
"The previous HTTP response starts in packet number", HFILL }},
{ &hf_http_time,
{ "Time since request", "http.time",
FT_RELATIVE_TIME, BASE_NONE, NULL, 0,
"Time since the request was send", HFILL }},
};
static gint *ett[] = {
&ett_http,
&ett_http_ntlmssp,
&ett_http_kerberos,
&ett_http_request,
&ett_http_chunked_response,
&ett_http_chunk_data,
&ett_http_encoded_entity,
&ett_http_header_item
};
static ei_register_info ei[] = {
{ &ei_http_chat, { "http.chat", PI_SEQUENCE, PI_CHAT, "Formatted text", EXPFILL }},
{ &ei_http_chunked_and_length, { "http.chunkd_and_length", PI_MALFORMED, PI_WARN, "It is incorrect to specify a content-length header and chunked encoding together.", EXPFILL }},
{ &ei_http_subdissector_failed, { "http.subdissector_failed", PI_MALFORMED, PI_NOTE, "HTTP body subdissector failed, trying heuristic subdissector", EXPFILL }},
{ &ei_http_ssl_port, { "http.ssl_port", PI_SECURITY, PI_WARN, "Unencrypted HTTP protocol detected over encrypted port, could indicate a dangerous misconfiguration.", EXPFILL }},
{ &ei_http_leading_crlf, { "http.leading_crlf", PI_MALFORMED, PI_ERROR, "Leading CRLF previous message in the stream may have extra CRLF", EXPFILL }},
};
static uat_field_t custom_header_uat_fields[] = {
UAT_FLD_CSTRING(header_fields, header_name, "Header name", "HTTP header name"),
UAT_FLD_CSTRING(header_fields, header_desc, "Field desc", "Description of the value contained in the header"),
UAT_END_FIELDS
};
module_t *http_module;
expert_module_t* expert_http;
uat_t* headers_uat;
proto_http = proto_register_protocol("Hypertext Transfer Protocol",
"HTTP", "http");
proto_register_field_array(proto_http, hf, array_length(hf));
proto_register_subtree_array(ett, array_length(ett));
expert_http = expert_register_protocol(proto_http);
expert_register_field_array(expert_http, ei, array_length(ei));
http_handle = new_register_dissector("http", dissect_http, proto_http);
http_module = prefs_register_protocol(proto_http, reinit_http);
prefs_register_bool_preference(http_module, "desegment_headers",
"Reassemble HTTP headers spanning multiple TCP segments",
"Whether the HTTP dissector should reassemble headers "
"of a request spanning multiple TCP segments. "
"To use this option, you must also enable "
"\"Allow subdissectors to reassemble TCP streams\" in the TCP protocol settings.",
&http_desegment_headers);
prefs_register_bool_preference(http_module, "desegment_body",
"Reassemble HTTP bodies spanning multiple TCP segments",
"Whether the HTTP dissector should use the "
"\"Content-length:\" value, if present, to reassemble "
"the body of a request spanning multiple TCP segments, "
"and reassemble chunked data spanning multiple TCP segments. "
"To use this option, you must also enable "
"\"Allow subdissectors to reassemble TCP streams\" in the TCP protocol settings.",
&http_desegment_body);
prefs_register_bool_preference(http_module, "dechunk_body",
"Reassemble chunked transfer-coded bodies",
"Whether to reassemble bodies of entities that are transferred "
"using the \"Transfer-Encoding: chunked\" method",
&http_dechunk_body);
#ifdef HAVE_LIBZ
prefs_register_bool_preference(http_module, "decompress_body",
"Uncompress entity bodies",
"Whether to uncompress entity bodies that are compressed "
"using \"Content-Encoding: \"",
&http_decompress_body);
#endif
prefs_register_obsolete_preference(http_module, "tcp_alternate_port");
range_convert_str(&global_http_tcp_range, TCP_DEFAULT_RANGE, 65535);
http_tcp_range = range_empty();
prefs_register_range_preference(http_module, "tcp.port", "TCP Ports",
"TCP Ports range",
&global_http_tcp_range, 65535);
range_convert_str(&global_http_ssl_range, SSL_DEFAULT_RANGE, 65535);
http_ssl_range = range_empty();
prefs_register_range_preference(http_module, "ssl.port", "SSL/TLS Ports",
"SSL/TLS Ports range",
&global_http_ssl_range, 65535);
headers_uat = uat_new("Custom HTTP headers fields Table",
sizeof(header_field_t),
"custom_http_header_fields",
TRUE,
&header_fields,
&num_header_fields,
UAT_AFFECTS_DISSECTION|UAT_AFFECTS_FIELDS,
NULL,
header_fields_copy_cb,
header_fields_update_cb,
header_fields_free_cb,
header_fields_initialize_cb,
custom_header_uat_fields
);
prefs_register_uat_preference(http_module, "custom_http_header_fields", "Custom HTTP headers fields",
"A table to define custom HTTP header for which fields can be setup and used for filtering/data extraction etc.",
headers_uat);
port_subdissector_table = register_dissector_table("http.port",
"TCP port for protocols using HTTP", FT_UINT16, BASE_DEC);
media_type_subdissector_table =
register_dissector_table("media_type",
"Internet media type", FT_STRING, BASE_NONE);
register_heur_dissector_list("http", &heur_subdissector_list);
http_tap = register_tap("http");
http_eo_tap = register_tap("http_eo");
}
void
http_dissector_add(guint32 port, dissector_handle_t handle)
{
dissector_add_uint("tcp.port", port, http_handle);
dissector_add_uint("http.port", port, handle);
}
void
http_port_add(guint32 port)
{
dissector_add_uint("tcp.port", port, http_handle);
}
void
proto_reg_handoff_http(void)
{
dissector_handle_t http_udp_handle;
data_handle = find_dissector("data");
media_handle = find_dissector("media");
websocket_handle = find_dissector("websocket");
http2_handle = find_dissector("http2");
http_udp_handle = create_dissector_handle(dissect_http_udp, proto_http);
dissector_add_uint("udp.port", UDP_PORT_SSDP, http_udp_handle);
ntlmssp_handle = find_dissector("ntlmssp");
gssapi_handle = find_dissector("gssapi");
stats_tree_register("http", "http", "HTTP/Packet Counter", 0, http_stats_tree_packet, http_stats_tree_init, NULL );
stats_tree_register("http", "http_req", "HTTP/Requests", 0, http_req_stats_tree_packet, http_req_stats_tree_init, NULL );
stats_tree_register("http", "http_srv", "HTTP/Load Distribution",0, http_reqs_stats_tree_packet, http_reqs_stats_tree_init, NULL );
}
static void
dissect_message_http(tvbuff_t *tvb, packet_info *pinfo, proto_tree *tree)
{
proto_tree *subtree;
proto_item *ti;
gint offset = 0, next_offset;
gint len;
col_append_str(pinfo->cinfo, COL_INFO, " (message/http)");
if (tree) {
ti = proto_tree_add_item(tree, proto_message_http,
tvb, 0, -1, ENC_NA);
subtree = proto_item_add_subtree(ti, ett_message_http);
while (tvb_reported_length_remaining(tvb, offset) > 0) {
len = tvb_find_line_end(tvb, offset,
tvb_ensure_captured_length_remaining(tvb, offset),
&next_offset, FALSE);
if (len == -1)
break;
proto_tree_add_text(subtree, tvb, offset, next_offset - offset,
"%s", tvb_format_text(tvb, offset, len));
offset = next_offset;
}
}
}
void
proto_register_message_http(void)
{
static gint *ett[] = {
&ett_message_http,
};
proto_message_http = proto_register_protocol(
"Media Type: message/http",
"message/http",
"message-http"
);
proto_register_subtree_array(ett, array_length(ett));
}
void
proto_reg_handoff_message_http(void)
{
dissector_handle_t message_http_handle;
message_http_handle = create_dissector_handle(dissect_message_http,
proto_message_http);
dissector_add_string("media_type", "message/http", message_http_handle);
heur_dissector_add("tcp", dissect_http_heur_tcp, proto_http);
reinit_http();
}
