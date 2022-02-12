static gboolean
hd_inflate_del_cb(wmem_allocator_t *allocator _U_, wmem_cb_event_t event _U_, void *user_data)
{
nghttp2_hd_inflate_del((nghttp2_hd_inflater*)user_data);
return FALSE;
}
static http2_session_t*
get_http2_session(packet_info *pinfo)
{
conversation_t *conversation;
http2_session_t *h2session;
conversation = find_or_create_conversation(pinfo);
h2session = (http2_session_t*)conversation_get_proto_data(conversation,
proto_http2);
if(!h2session) {
struct tcp_analysis *tcpd;
tcpd = get_tcp_conversation_data(NULL, pinfo);
h2session = wmem_new0(wmem_file_scope(), http2_session_t);
nghttp2_hd_inflate_new(&h2session->hd_inflater[0]);
nghttp2_hd_inflate_new(&h2session->hd_inflater[1]);
wmem_register_callback(wmem_file_scope(), hd_inflate_del_cb,
h2session->hd_inflater[0]);
wmem_register_callback(wmem_file_scope(), hd_inflate_del_cb,
h2session->hd_inflater[1]);
h2session->fwd_flow = tcpd->fwd;
h2session->settings_queue[0] = wmem_queue_new(wmem_file_scope());
h2session->settings_queue[1] = wmem_queue_new(wmem_file_scope());
conversation_add_proto_data(conversation, proto_http2, h2session);
}
return h2session;
}
static int
select_http2_flow_index(packet_info *pinfo, http2_session_t *h2session)
{
struct tcp_analysis *tcpd;
tcpd = get_tcp_conversation_data(NULL, pinfo);
if(tcpd->fwd == h2session->fwd_flow) {
return 0;
} else {
return 1;
}
}
static void
push_settings(packet_info *pinfo, http2_session_t *h2session,
http2_settings_t *settings)
{
wmem_queue_t *queue;
int flow_index;
flow_index = select_http2_flow_index(pinfo, h2session);
queue = h2session->settings_queue[flow_index];
wmem_queue_push(queue, settings);
}
static void
apply_and_pop_settings(packet_info *pinfo, http2_session_t *h2session)
{
wmem_queue_t *queue;
http2_settings_t *settings;
nghttp2_hd_inflater *inflater;
int flow_index;
flow_index = select_http2_flow_index(pinfo, h2session);
inflater = h2session->hd_inflater[flow_index];
queue = h2session->settings_queue[flow_index ^ 1];
if(wmem_queue_count(queue) == 0) {
return;
}
settings = (http2_settings_t*)wmem_queue_pop(queue);
if(settings->has_header_table_size) {
if(settings->min_header_table_size < settings->header_table_size) {
nghttp2_hd_inflate_change_table_size
(inflater, settings->min_header_table_size);
}
nghttp2_hd_inflate_change_table_size(inflater,
settings->header_table_size);
}
}
static guint read_integer(http2_header_repr_info_t *header_repr_info,
const guint8 *buf, guint len, guint p, guint prefix)
{
guint k = (1 << prefix) - 1;
guint n = header_repr_info->integer;
guint shift = header_repr_info->next_shift;
if(n == 0) {
DISSECTOR_ASSERT(p < len);
if((buf[p] & k) != k) {
header_repr_info->integer = buf[p] & k;
header_repr_info->complete = TRUE;
return p + 1;
}
n = k;
++p;
}
for(; p < len; ++p, shift += 7) {
DISSECTOR_ASSERT(p < len);
n += (buf[p] & 0x7F) << shift;
if((buf[p] & 0x80) == 0) {
header_repr_info->complete = TRUE;
++p;
break;
}
}
header_repr_info->integer = n;
header_repr_info->next_shift = shift;
return p;
}
static void
reset_http2_header_repr_info(http2_header_repr_info_t *header_repr_info)
{
header_repr_info->type = HTTP2_HD_NONE;
header_repr_info->integer = 0;
header_repr_info->next_shift = 0;
header_repr_info->complete = FALSE;
}
static guint
process_http2_header_repr_info(wmem_array_t *headers,
http2_header_repr_info_t *header_repr_info,
const guint8 *buf, guint len)
{
guint i;
guint start;
if(header_repr_info->type != HTTP2_HD_NONE &&
header_repr_info->type != HTTP2_HD_HEADER_TABLE_SIZE_UPDATE &&
header_repr_info->complete) {
return 0;
}
start = 0;
for(i = 0; i < len;) {
if(header_repr_info->type == HTTP2_HD_NONE) {
guchar c = buf[i];
if((c & 0xE0) == 0x20) {
header_repr_info->type = HTTP2_HD_HEADER_TABLE_SIZE_UPDATE;
i = read_integer(header_repr_info, buf, len, i, 5);
} else if(c & 0x80) {
header_repr_info->type = HTTP2_HD_INDEXED;
i = read_integer(header_repr_info, buf, len, i, 7);
} else if(c == 0x40 || c == 0 || c == 0x10) {
header_repr_info->complete = TRUE;
if(c & 0x40) {
header_repr_info->type = HTTP2_HD_LITERAL_INDEXING_NEW_NAME;
} else if((c & 0xF0) == 0x10) {
header_repr_info->type = HTTP2_HD_LITERAL_NEVER_INDEXING_NEW_NAME;
} else {
header_repr_info->type = HTTP2_HD_LITERAL_NEW_NAME;
}
} else {
if(c & 0x40) {
header_repr_info->type = HTTP2_HD_LITERAL_INDEXING_INDEXED_NAME;
i = read_integer(header_repr_info, buf, len, i, 6);
} else if((c & 0xF0) == 0x10) {
header_repr_info->type = HTTP2_HD_LITERAL_NEVER_INDEXING_INDEXED_NAME;
i = read_integer(header_repr_info, buf, len, i, 4);
} else {
header_repr_info->type = HTTP2_HD_LITERAL_INDEXED_NAME;
i = read_integer(header_repr_info, buf, len, i, 4);
}
}
} else {
i = read_integer(header_repr_info, buf, len, i, 8);
}
if(header_repr_info->complete) {
if(header_repr_info->type == HTTP2_HD_HEADER_TABLE_SIZE_UPDATE) {
http2_header_t *out;
out = wmem_new(wmem_file_scope(), http2_header_t);
out->type = header_repr_info->type;
out->length = i - start;
out->table.header_table_size = header_repr_info->integer;
wmem_array_append(headers, out, 1);
reset_http2_header_repr_info(header_repr_info);
start = i;
} else {
break;
}
}
}
return start;
}
static void
inflate_http2_header_block(tvbuff_t *tvb, packet_info *pinfo, guint offset,
proto_tree *tree, size_t headlen,
http2_session_t *h2session, guint8 flags)
{
guint8 *headbuf;
proto_tree *header_tree;
proto_item *header, *ti;
int header_name_length;
int header_value_length;
const gchar *header_name;
const gchar *header_value;
int hoffset = 0;
nghttp2_hd_inflater *hd_inflater;
tvbuff_t *header_tvb = tvb_new_composite();
int rv;
int header_len = 0;
int final;
int flow_index;
http2_header_data_t *header_data;
http2_header_repr_info_t *header_repr_info;
wmem_list_t *header_list;
wmem_array_t *headers;
guint i;
header_data = (http2_header_data_t*)p_get_proto_data(wmem_file_scope(), pinfo, proto_http2, 0);
header_list = header_data->header_list;
if(!PINFO_FD_VISITED(pinfo)) {
headbuf = (guint8*)wmem_alloc(wmem_packet_scope(), headlen);
tvb_memcpy(tvb, headbuf, offset, headlen);
flow_index = select_http2_flow_index(pinfo, h2session);
hd_inflater = h2session->hd_inflater[flow_index];
header_repr_info = &h2session->header_repr_info[flow_index];
final = flags & HTTP2_FLAGS_END_HEADERS;
headers = wmem_array_sized_new(wmem_file_scope(), sizeof(http2_header_t), 16);
for(;;) {
nghttp2_nv nv;
int inflate_flags = 0;
rv = (int)nghttp2_hd_inflate_hd(hd_inflater, &nv,
&inflate_flags, headbuf, headlen, final);
if(rv < 0) {
break;
}
headbuf += rv;
headlen -= rv;
rv -= process_http2_header_repr_info(headers, header_repr_info, headbuf - rv, rv);
if(inflate_flags & NGHTTP2_HD_INFLATE_EMIT) {
char *str;
guint32 len;
http2_header_t *out;
out = wmem_new(wmem_file_scope(), http2_header_t);
out->type = header_repr_info->type;
out->length = rv;
out->table.data.index = header_repr_info->integer;
out->table.data.datalen = (guint)(4 + nv.namelen + 4 + nv.valuelen);
str = wmem_alloc_array(wmem_file_scope(), char, out->table.data.datalen);
len = (guint32)nv.namelen;
memcpy(&str[0], (char *)&len, sizeof(len));
memcpy(&str[4], nv.name, nv.namelen);
len = (guint32)nv.valuelen;
memcpy(&str[4 + nv.namelen], (char *)&len, sizeof(len));
memcpy(&str[4 + nv.namelen + 4], nv.value, nv.valuelen);
out->table.data.data = str;
wmem_array_append(headers, out, 1);
reset_http2_header_repr_info(header_repr_info);
}
if(inflate_flags & NGHTTP2_HD_INFLATE_FINAL) {
nghttp2_hd_inflate_end_headers(hd_inflater);
break;
}
if((inflate_flags & NGHTTP2_HD_INFLATE_EMIT) == 0 &&
headlen == 0) {
break;
}
}
wmem_list_append(header_list, headers);
if(!header_data->current) {
header_data->current = wmem_list_head(header_list);
}
} else {
headers = (wmem_array_t*)wmem_list_frame_data(header_data->current);
header_data->current = wmem_list_frame_next(header_data->current);
if(!header_data->current) {
header_data->current = wmem_list_head(header_list);
}
}
if(wmem_array_get_count(headers) == 0) {
return;
}
for(i = 0; i < wmem_array_get_count(headers); ++i) {
http2_header_t *in;
tvbuff_t *next_tvb;
char *str;
in = (http2_header_t*)wmem_array_index(headers, i);
if(in->type == HTTP2_HD_HEADER_TABLE_SIZE_UPDATE) {
continue;
}
str = (char *)g_malloc(in->table.data.datalen);
memcpy(str, in->table.data.data, in->table.data.datalen);
header_len += in->table.data.datalen;
next_tvb = tvb_new_child_real_data(tvb, str, in->table.data.datalen, in->table.data.datalen);
tvb_set_free_cb(next_tvb, g_free);
tvb_composite_append(header_tvb, next_tvb);
}
tvb_composite_finalize(header_tvb);
add_new_data_source(pinfo, header_tvb, "Decompressed Header");
ti = proto_tree_add_uint(tree, hf_http2_header_length, header_tvb, hoffset, 1, header_len);
PROTO_ITEM_SET_GENERATED(ti);
for(i = 0; i < wmem_array_get_count(headers); ++i) {
http2_header_t *in = (http2_header_t*)wmem_array_index(headers, i);
if(in->type == HTTP2_HD_HEADER_TABLE_SIZE_UPDATE) {
header = proto_tree_add_item(tree, hf_http2_header_table_size_update, tvb, offset, in->length, ENC_NA);
header_tree = proto_item_add_subtree(header, ett_http2_headers);
proto_tree_add_uint(header_tree, hf_http2_header_table_size, tvb, offset, in->length, in->table.header_table_size);
offset += in->length;
continue;
}
header = proto_tree_add_item(tree, hf_http2_header, tvb, offset, in->length, ENC_NA);
header_tree = proto_item_add_subtree(header, ett_http2_headers);
header_name_length = tvb_get_letohl(header_tvb, hoffset);
proto_tree_add_uint(header_tree, hf_http2_header_name_length, tvb, offset, in->length, header_name_length);
hoffset += 4;
header_name = (gchar *)tvb_get_string_enc(wmem_packet_scope(), header_tvb, hoffset, header_name_length, ENC_ASCII|ENC_NA);
proto_tree_add_string(header_tree, hf_http2_header_name, tvb, offset, in->length, header_name);
hoffset += header_name_length;
header_value_length = tvb_get_letohl(header_tvb, hoffset);
proto_tree_add_uint(header_tree, hf_http2_header_value_length, tvb, offset, in->length, header_value_length);
hoffset += 4;
header_value = (gchar *)tvb_get_string_enc(wmem_packet_scope(),header_tvb, hoffset, header_value_length, ENC_ASCII|ENC_NA);
proto_tree_add_string(header_tree, hf_http2_header_value, tvb, offset, in->length, header_value);
hoffset += header_value_length;
proto_tree_add_string(header_tree, hf_http2_header_repr, tvb, offset, in->length, http2_header_repr_type[in->type].strptr);
if(in->type == HTTP2_HD_INDEXED ||
in->type == HTTP2_HD_LITERAL_INDEXING_INDEXED_NAME ||
in->type == HTTP2_HD_LITERAL_INDEXED_NAME ||
in->type == HTTP2_HD_LITERAL_NEVER_INDEXING_INDEXED_NAME) {
proto_tree_add_uint(header_tree, hf_http2_header_index, tvb, offset, in->length, in->table.data.index);
}
proto_item_append_text(header, ": %s: %s", header_name, header_value);
offset += in->length;
}
}
static guint8
dissect_http2_header_flags(tvbuff_t *tvb, packet_info *pinfo _U_, proto_tree *http2_tree, guint offset, guint8 type)
{
proto_item *ti_flags;
proto_tree *flags_tree;
guint8 flags;
ti_flags = proto_tree_add_item(http2_tree, hf_http2_flags, tvb, offset, 1, ENC_NA);
flags_tree = proto_item_add_subtree(ti_flags, ett_http2_flags);
flags = tvb_get_guint8(tvb, offset);
switch(type){
case HTTP2_DATA:
proto_tree_add_item(flags_tree, hf_http2_flags_end_stream, tvb, offset, 1, ENC_NA);
proto_tree_add_item(flags_tree, hf_http2_flags_padded, tvb, offset, 1, ENC_NA);
proto_tree_add_item(flags_tree, hf_http2_flags_unused_data, tvb, offset, 1, ENC_NA);
break;
case HTTP2_HEADERS:
proto_tree_add_item(flags_tree, hf_http2_flags_end_stream, tvb, offset, 1, ENC_NA);
proto_tree_add_item(flags_tree, hf_http2_flags_end_headers, tvb, offset, 1, ENC_NA);
proto_tree_add_item(flags_tree, hf_http2_flags_padded, tvb, offset, 1, ENC_NA);
proto_tree_add_item(flags_tree, hf_http2_flags_priority, tvb, offset, 1, ENC_NA);
proto_tree_add_item(flags_tree, hf_http2_flags_unused_headers, tvb, offset, 1, ENC_NA);
break;
case HTTP2_SETTINGS:
proto_tree_add_item(flags_tree, hf_http2_flags_settings_ack, tvb, offset, 1, ENC_NA);
proto_tree_add_item(flags_tree, hf_http2_flags_unused_settings, tvb, offset, 1, ENC_NA);
break;
case HTTP2_PUSH_PROMISE:
proto_tree_add_item(flags_tree, hf_http2_flags_end_headers, tvb, offset, 1, ENC_NA);
proto_tree_add_item(flags_tree, hf_http2_flags_padded, tvb, offset, 1, ENC_NA);
proto_tree_add_item(flags_tree, hf_http2_flags_unused_push_promise, tvb, offset, 1, ENC_NA);
break;
case HTTP2_CONTINUATION:
proto_tree_add_item(flags_tree, hf_http2_flags_end_headers, tvb, offset, 1, ENC_NA);
proto_tree_add_item(flags_tree, hf_http2_flags_unused_continuation, tvb, offset, 1, ENC_NA);
break;
case HTTP2_PING:
proto_tree_add_item(flags_tree, hf_http2_flags_ping_ack, tvb, offset, 1, ENC_NA);
proto_tree_add_item(flags_tree, hf_http2_flags_unused_ping, tvb, offset, 1, ENC_NA);
break;
case HTTP2_PRIORITY:
case HTTP2_RST_STREAM:
case HTTP2_GOAWAY:
case HTTP2_WINDOW_UPDATE:
case HTTP2_ALTSVC:
case HTTP2_BLOCKED:
default:
proto_tree_add_item(flags_tree, hf_http2_flags_unused, tvb, offset, 1, ENC_NA);
break;
}
return flags;
}
static guint
dissect_frame_padding(tvbuff_t *tvb, guint16 *padding, proto_tree *http2_tree,
guint offset, guint8 flags)
{
proto_item *ti;
guint pad_len = 0;
*padding = 0;
if(flags & HTTP2_FLAGS_PADDED)
{
*padding = tvb_get_guint8(tvb, offset);
proto_tree_add_item(http2_tree, hf_http2_padding, tvb, offset, 1, ENC_NA);
offset++;
pad_len ++;
}
ti = proto_tree_add_uint(http2_tree, hf_http2_pad_length, tvb, offset-pad_len, pad_len, *padding);
PROTO_ITEM_SET_GENERATED(ti);
return offset;
}
static guint
dissect_frame_prio(tvbuff_t *tvb, proto_tree *http2_tree, guint offset, guint8 flags)
{
proto_tree *ti;
guint8 weight;
if(flags & HTTP2_FLAGS_PRIORITY)
{
proto_tree_add_item(http2_tree, hf_http2_excl_dependency, tvb, offset, 4, ENC_NA);
proto_tree_add_item(http2_tree, hf_http2_stream_dependency, tvb, offset, 4, ENC_BIG_ENDIAN);
offset += 4;
proto_tree_add_item(http2_tree, hf_http2_weight, tvb, offset, 1, ENC_NA);
weight = tvb_get_guint8(tvb, offset);
ti = proto_tree_add_uint(http2_tree, hf_http2_weight_real, tvb, offset, 1, weight+1);
PROTO_ITEM_SET_GENERATED(ti);
offset++;
}
return offset;
}
static int
dissect_http2_data(tvbuff_t *tvb, packet_info *pinfo _U_, proto_tree *http2_tree,
guint offset, guint8 flags)
{
guint16 padding;
gint datalen;
offset = dissect_frame_padding(tvb, &padding, http2_tree, offset, flags);
datalen = tvb_reported_length_remaining(tvb, offset) - padding;
proto_tree_add_item(http2_tree, hf_http2_data_data, tvb, offset, datalen, ENC_NA);
offset += datalen;
proto_tree_add_item(http2_tree, hf_http2_data_padding, tvb, offset, padding, ENC_NA);
offset += padding;
return offset;
}
static int
dissect_http2_headers(tvbuff_t *tvb, packet_info *pinfo _U_, proto_tree *http2_tree,
guint offset, guint8 flags)
{
guint16 padding;
gint headlen;
http2_session_t *h2session;
h2session = get_http2_session(pinfo);
offset = dissect_frame_padding(tvb, &padding, http2_tree, offset, flags);
offset = dissect_frame_prio(tvb, http2_tree, offset, flags);
headlen = tvb_reported_length_remaining(tvb, offset) - padding;
proto_tree_add_item(http2_tree, hf_http2_headers, tvb, offset, headlen, ENC_NA);
inflate_http2_header_block(tvb, pinfo, offset, http2_tree, headlen, h2session, flags);
offset += headlen;
proto_tree_add_item(http2_tree, hf_http2_headers_padding, tvb, offset, padding, ENC_NA);
offset += padding;
return offset;
}
static int
dissect_http2_priority(tvbuff_t *tvb, packet_info *pinfo _U_, proto_tree *http2_tree,
guint offset, guint8 flags)
{
offset = dissect_frame_prio(tvb, http2_tree, offset,
flags | HTTP2_FLAGS_PRIORITY);
return offset;
}
static int
dissect_http2_rst_stream(tvbuff_t *tvb, packet_info *pinfo _U_, proto_tree *http2_tree, guint offset, guint8 flags _U_)
{
proto_tree_add_item(http2_tree, hf_http2_rst_stream_error, tvb, offset, 4, ENC_BIG_ENDIAN);
offset += 4;
return offset;
}
static int
dissect_http2_settings(tvbuff_t *tvb, packet_info *pinfo _U_, proto_tree *http2_tree, guint offset, guint8 flags)
{
guint32 settingsid;
proto_item *ti_settings;
proto_tree *settings_tree;
guint32 header_table_size;
guint32 min_header_table_size;
int header_table_size_found;
http2_session_t *h2session;
header_table_size_found = 0;
header_table_size = 0;
min_header_table_size = 0xFFFFFFFFu;
while(tvb_reported_length_remaining(tvb, offset) > 0){
ti_settings = proto_tree_add_item(http2_tree, hf_http2_settings, tvb, offset, 5, ENC_NA);
settings_tree = proto_item_add_subtree(ti_settings, ett_http2_settings);
proto_tree_add_item(settings_tree, hf_http2_settings_identifier, tvb, offset, 2, ENC_NA);
settingsid = tvb_get_ntohs(tvb, offset);
proto_item_append_text(ti_settings, " - %s",
val_to_str( settingsid, http2_settings_vals, "Unknown (%u)") );
offset += 2;
switch(settingsid){
case HTTP2_SETTINGS_HEADER_TABLE_SIZE:
proto_tree_add_item(settings_tree, hf_http2_settings_header_table_size, tvb, offset, 4, ENC_BIG_ENDIAN);
header_table_size_found = 1;
header_table_size = tvb_get_ntohl(tvb, offset);
if(min_header_table_size > header_table_size) {
min_header_table_size = header_table_size;
}
break;
case HTTP2_SETTINGS_ENABLE_PUSH:
proto_tree_add_item(settings_tree, hf_http2_settings_enable_push, tvb, offset, 4, ENC_BIG_ENDIAN);
break;
case HTTP2_SETTINGS_MAX_CONCURRENT_STREAMS:
proto_tree_add_item(settings_tree, hf_http2_settings_max_concurrent_streams, tvb, offset, 4, ENC_BIG_ENDIAN);
break;
case HTTP2_SETTINGS_INITIAL_WINDOW_SIZE:
proto_tree_add_item(settings_tree, hf_http2_settings_initial_window_size, tvb, offset, 4, ENC_BIG_ENDIAN);
break;
case HTTP2_SETTINGS_MAX_FRAME_SIZE:
proto_tree_add_item(settings_tree, hf_http2_settings_max_frame_size, tvb, offset, 4, ENC_BIG_ENDIAN);
break;
case HTTP2_SETTINGS_MAX_HEADER_LIST_SIZE:
proto_tree_add_item(settings_tree, hf_http2_settings_max_header_list_size, tvb, offset, 4, ENC_BIG_ENDIAN);
break;
default:
proto_tree_add_item(settings_tree, hf_http2_settings_unknown, tvb, offset, 4, ENC_BIG_ENDIAN);
break;
}
proto_item_append_text(ti_settings, " : %u", tvb_get_ntohl(tvb, offset));
offset += 4;
}
if(!PINFO_FD_VISITED(pinfo)) {
h2session = get_http2_session(pinfo);
if(flags & HTTP2_FLAGS_ACK) {
apply_and_pop_settings(pinfo, h2session);
} else {
http2_settings_t *settings;
settings = wmem_new(wmem_file_scope(), http2_settings_t);
settings->min_header_table_size = min_header_table_size;
settings->header_table_size = header_table_size;
settings->has_header_table_size = header_table_size_found;
push_settings(pinfo, h2session, settings);
}
}
return offset;
}
static int
dissect_http2_push_promise(tvbuff_t *tvb, packet_info *pinfo _U_, proto_tree *http2_tree,
guint offset, guint8 flags _U_)
{
guint16 padding;
gint headlen;
http2_session_t *h2session;
h2session = get_http2_session(pinfo);
offset = dissect_frame_padding(tvb, &padding, http2_tree, offset, flags);
proto_tree_add_item(http2_tree, hf_http2_push_promise_r, tvb, offset, 4, ENC_BIG_ENDIAN);
proto_tree_add_item(http2_tree, hf_http2_push_promise_promised_stream_id, tvb,
offset, 4, ENC_BIG_ENDIAN);
offset += 4;
headlen = tvb_reported_length_remaining(tvb, offset) - padding;
proto_tree_add_item(http2_tree, hf_http2_push_promise_header, tvb, offset, headlen,
ENC_ASCII|ENC_NA);
inflate_http2_header_block(tvb, pinfo, offset, http2_tree, headlen, h2session, flags);
offset += headlen;
proto_tree_add_item(http2_tree, hf_http2_push_promise_padding, tvb,
offset, padding, ENC_NA);
offset += tvb_reported_length_remaining(tvb, offset);
return offset;
}
static int
dissect_http2_ping(tvbuff_t *tvb, packet_info *pinfo _U_, proto_tree *http2_tree,
guint offset, guint8 flags)
{
if(flags & HTTP2_FLAGS_ACK)
{
proto_tree_add_item(http2_tree, hf_http2_pong, tvb, offset, 8, ENC_NA);
}else{
proto_tree_add_item(http2_tree, hf_http2_ping, tvb, offset, 8, ENC_NA);
}
offset += 8;
return offset;
}
static int
dissect_http2_goaway(tvbuff_t *tvb, packet_info *pinfo _U_, proto_tree *http2_tree, guint offset, guint8 flags _U_)
{
proto_tree_add_item(http2_tree, hf_http2_goaway_r, tvb, offset, 4, ENC_BIG_ENDIAN);
proto_tree_add_item(http2_tree, hf_http2_goaway_last_stream_id, tvb, offset, 4, ENC_BIG_ENDIAN);
offset += 4;
proto_tree_add_item(http2_tree, hf_http2_goaway_error, tvb, offset, 4, ENC_BIG_ENDIAN);
offset += 4;
if(tvb_reported_length_remaining(tvb, offset) > 0)
{
proto_tree_add_item(http2_tree, hf_http2_goaway_addata , tvb, offset, -1, ENC_NA);
offset += tvb_reported_length_remaining(tvb, offset);
}
return offset;
}
static int
dissect_http2_window_update(tvbuff_t *tvb, packet_info *pinfo _U_, proto_tree *http2_tree, guint offset, guint8 flags _U_)
{
proto_tree_add_item(http2_tree, hf_http2_window_update_r, tvb, offset, 4, ENC_BIG_ENDIAN);
proto_tree_add_item(http2_tree, hf_http2_window_update_window_size_increment, tvb, offset, 4, ENC_BIG_ENDIAN);
offset += 4;
return offset;
}
static int
dissect_http2_continuation(tvbuff_t *tvb, packet_info *pinfo _U_, proto_tree *http2_tree, guint offset, guint8 flags)
{
guint16 padding;
gint headlen;
http2_session_t *h2session;
h2session = get_http2_session(pinfo);
offset = dissect_frame_padding(tvb, &padding, http2_tree, offset, flags);
headlen = tvb_reported_length_remaining(tvb, offset) - padding;
proto_tree_add_item(http2_tree, hf_http2_continuation_header, tvb, offset, headlen, ENC_ASCII|ENC_NA);
inflate_http2_header_block(tvb, pinfo, offset, http2_tree, headlen, h2session, flags);
offset += headlen;
proto_tree_add_item(http2_tree, hf_http2_continuation_padding, tvb, offset, padding, ENC_NA);
offset += padding;
return offset;
}
static int
dissect_http2_altsvc(tvbuff_t *tvb, packet_info *pinfo _U_, proto_tree *http2_tree,
guint offset, guint8 flags _U_, guint16 length)
{
guint8 pidlen;
guint8 hostlen;
int remain;
proto_tree_add_item(http2_tree, hf_http2_altsvc_maxage, tvb, offset, 4, ENC_BIG_ENDIAN);
offset+=4;
proto_tree_add_item(http2_tree, hf_http2_altsvc_port, tvb, offset, 2, ENC_BIG_ENDIAN);
offset += 2;
proto_tree_add_item(http2_tree, hf_http2_altsvc_proto_len, tvb, offset, 1, ENC_NA);
pidlen = tvb_get_guint8(tvb, offset);
offset ++;
proto_tree_add_item(http2_tree, hf_http2_altsvc_protocol, tvb, offset, pidlen, ENC_ASCII|ENC_NA);
offset += pidlen;
proto_tree_add_item(http2_tree, hf_http2_altsvc_host_len, tvb, offset, 1, ENC_NA);
hostlen = tvb_get_guint8(tvb, offset);
offset ++;
proto_tree_add_item(http2_tree, hf_http2_altsvc_host, tvb, offset, hostlen, ENC_ASCII|ENC_NA);
offset += hostlen;
remain = length - offset;
if(remain > -8) {
proto_tree_add_item(http2_tree, hf_http2_altsvc_origin, tvb,
offset, remain + 8, ENC_ASCII|ENC_NA);
offset += remain;
}
return offset;
}
static int
dissect_http2_pdu(tvbuff_t *tvb, packet_info *pinfo, proto_tree *tree, void* data _U_ )
{
proto_item *ti;
proto_tree *http2_tree;
guint offset = 0;
guint8 type, flags;
guint16 length;
guint32 streamid;
if(!p_get_proto_data(wmem_file_scope(), pinfo, proto_http2, 0)) {
http2_header_data_t *header_data;
header_data = wmem_new(wmem_file_scope(), http2_header_data_t);
header_data->header_list = wmem_list_new(wmem_file_scope());
header_data->current = NULL;
p_add_proto_data(wmem_file_scope(), pinfo, proto_http2, 0, header_data);
}
ti = proto_tree_add_item(tree, hf_http2, tvb, 0, -1, ENC_NA);
http2_tree = proto_item_add_subtree(ti, ett_http2_header);
if (tvb_memeql(tvb, offset, kMagicHello, MAGIC_FRAME_LENGTH) == 0 )
{
col_append_sep_str( pinfo->cinfo, COL_INFO, ", ", "Magic" );
proto_item_set_len(ti, MAGIC_FRAME_LENGTH);
proto_item_append_text(ti, ": Magic");
proto_tree_add_item(http2_tree, hf_http2_magic, tvb, offset, MAGIC_FRAME_LENGTH, ENC_ASCII|ENC_NA);
return MAGIC_FRAME_LENGTH;
}
proto_tree_add_item(http2_tree, hf_http2_length, tvb, offset, 3, ENC_BIG_ENDIAN);
length = tvb_get_ntoh24(tvb, offset);
offset += 3;
proto_tree_add_item(http2_tree, hf_http2_type, tvb, offset, 1, ENC_NA);
type = tvb_get_guint8(tvb, offset);
col_append_sep_fstr( pinfo->cinfo, COL_INFO, ", ", "%s", val_to_str(type, http2_type_vals, "Unknown type (%d)"));
offset += 1;
flags = dissect_http2_header_flags(tvb, pinfo, http2_tree, offset, type);
offset += 1;
proto_tree_add_item(http2_tree, hf_http2_r, tvb, offset, 4, ENC_BIG_ENDIAN);
proto_tree_add_item(http2_tree, hf_http2_streamid, tvb, offset, 4, ENC_BIG_ENDIAN);
streamid = tvb_get_ntohl(tvb, offset) & MASK_HTTP2_STREAMID;
proto_item_append_text(ti, ": %s, Stream ID: %u, Length %u", val_to_str(type, http2_type_vals, "Unknown type (%d)"), streamid, length);
offset += 4;
switch(type){
case HTTP2_DATA:
dissect_http2_data(tvb, pinfo, http2_tree, offset, flags);
break;
case HTTP2_HEADERS:
dissect_http2_headers(tvb, pinfo, http2_tree, offset, flags);
break;
case HTTP2_PRIORITY:
dissect_http2_priority(tvb, pinfo, http2_tree, offset, flags);
break;
case HTTP2_RST_STREAM:
dissect_http2_rst_stream(tvb, pinfo, http2_tree, offset, flags);
break;
case HTTP2_SETTINGS:
dissect_http2_settings(tvb, pinfo, http2_tree, offset, flags);
break;
case HTTP2_PUSH_PROMISE:
dissect_http2_push_promise(tvb, pinfo, http2_tree, offset, flags);
break;
case HTTP2_PING:
dissect_http2_ping(tvb, pinfo, http2_tree, offset, flags);
break;
case HTTP2_GOAWAY:
dissect_http2_goaway(tvb, pinfo, http2_tree, offset, flags);
break;
case HTTP2_WINDOW_UPDATE:
dissect_http2_window_update(tvb, pinfo, http2_tree, offset, flags);
break;
case HTTP2_CONTINUATION:
dissect_http2_continuation(tvb, pinfo, http2_tree, offset, flags);
break;
case HTTP2_ALTSVC:
dissect_http2_altsvc(tvb, pinfo, http2_tree, offset, flags, length);
break;
case HTTP2_BLOCKED:
break;
default:
proto_tree_add_item(http2_tree, hf_http2_unknown, tvb, offset, -1, ENC_NA);
break;
}
return tvb_captured_length(tvb);
}
static guint get_http2_message_len( packet_info *pinfo _U_, tvbuff_t *tvb, int offset )
{
if ( tvb_memeql( tvb, offset, kMagicHello, MAGIC_FRAME_LENGTH ) == 0 ) {
return MAGIC_FRAME_LENGTH;
}
return (guint)tvb_get_ntoh24(tvb, offset) + FRAME_HEADER_LENGTH;
}
static int
dissect_http2(tvbuff_t *tvb, packet_info *pinfo, proto_tree *tree,
void *data)
{
proto_item *ti;
proto_tree *http2_tree;
if (tvb_captured_length(tvb) < FRAME_HEADER_LENGTH)
return 0;
col_set_str(pinfo->cinfo, COL_PROTOCOL, "HTTP2");
col_clear(pinfo->cinfo, COL_INFO);
ti = proto_tree_add_item(tree, proto_http2, tvb, 0, -1, ENC_NA);
proto_item_append_text(ti, " (draft-14)");
http2_tree = proto_item_add_subtree(ti, ett_http2);
tcp_dissect_pdus(tvb, pinfo, http2_tree, TRUE, FRAME_HEADER_LENGTH,
get_http2_message_len, dissect_http2_pdu, data);
return tvb_captured_length(tvb);
}
static gboolean
dissect_http2_heur(tvbuff_t *tvb, packet_info *pinfo, proto_tree *tree, void *data)
{
if (!global_http2_heur)
{
return FALSE;
}
if (tvb_memeql(tvb, 0, kMagicHello, MAGIC_FRAME_LENGTH) != 0) {
if (tvb_reported_length(tvb)<2 || tvb_get_guint8(tvb, 2)>HTTP2_BLOCKED)
return (FALSE);
}
dissect_http2(tvb, pinfo, tree, data);
return (TRUE);
}
void
proto_register_http2(void)
{
static hf_register_info hf[] = {
{ &hf_http2,
{ "Stream", "http2",
FT_NONE, BASE_NONE, NULL, 0x0,
NULL, HFILL }
},
{ &hf_http2_length,
{ "Length", "http2.length",
FT_UINT24, BASE_DEC, NULL, 0x0,
"The length (24 bits) of the frame payload (The 9 octets of the frame header are not included)", HFILL }
},
{ &hf_http2_type,
{ "Type", "http2.type",
FT_UINT8, BASE_DEC, VALS(http2_type_vals), 0x0,
"The frame type determines how the remainder of the frame header and payload are interpreted", HFILL }
},
{ &hf_http2_r,
{ "Reserved", "http2.r",
FT_UINT32, BASE_HEX, NULL, MASK_HTTP2_RESERVED,
"The semantics of this bit are undefined and the bit MUST remain unset (0) when sending and MUST be ignored when receiving", HFILL }
},
{ &hf_http2_weight,
{ "Weight", "http2.headers.weight",
FT_UINT8, BASE_DEC, NULL, 0x0,
"An 8-bit weight for the identified priority", HFILL }
},
{ &hf_http2_weight_real,
{ "Weight real", "http2.headers.weight_real",
FT_UINT8, BASE_DEC, NULL, 0x0,
"Real Weight value (Add one to value)", HFILL }
},
{ &hf_http2_streamid,
{ "Stream Identifier", "http2.streamid",
FT_UINT32, BASE_DEC, NULL, MASK_HTTP2_STREAMID,
"A 31-bit stream identifier", HFILL }
},
{ &hf_http2_magic,
{ "Magic", "http2.magic",
FT_STRING, BASE_NONE, NULL, 0x0,
NULL, HFILL }
},
{ &hf_http2_unknown,
{ "Unknown", "http2.unknown",
FT_BYTES, BASE_NONE, NULL, 0x0,
NULL, HFILL }
},
{ &hf_http2_flags,
{ "Flags", "http2.flags",
FT_UINT8, BASE_HEX, NULL, 0x0,
"Flags are assigned semantics specific to the indicated frame type", HFILL }
},
{ &hf_http2_flags_end_stream,
{ "End Stream", "http2.flags.end_stream",
FT_BOOLEAN, 8, NULL, HTTP2_FLAGS_END_STREAM,
"Indicates that this frame is the last that the endpoint will send for the identified stream", HFILL }
},
{ &hf_http2_flags_end_headers,
{ "End Headers", "http2.flags.eh",
FT_BOOLEAN, 8, NULL, HTTP2_FLAGS_END_HEADERS,
"Indicates that this frame contains an entire header block and is not followed by any CONTINUATION frames.", HFILL }
},
{ &hf_http2_flags_padded,
{ "Padded", "http2.flags.padded",
FT_BOOLEAN, 8, NULL, HTTP2_FLAGS_PADDED,
"Indicates that the Pad Length field is present", HFILL }
},
{ &hf_http2_flags_priority,
{ "Priority", "http2.flags.priority",
FT_BOOLEAN, 8, NULL, HTTP2_FLAGS_PRIORITY,
"Indicates that the Exclusive Flag (E), Stream Dependency, and Weight fields are present", HFILL }
},
{ &hf_http2_flags_ping_ack,
{ "ACK", "http2.flags.ack.ping",
FT_BOOLEAN, 8, NULL, HTTP2_FLAGS_ACK,
"Set indicates that this PING frame is a PING response", HFILL }
},
{ &hf_http2_flags_unused,
{ "Unused", "http2.flags.unused",
FT_UINT8, BASE_HEX, NULL, HTTP2_FLAGS_UNUSED,
"Must be zero", HFILL }
},
{ &hf_http2_flags_unused_settings,
{ "Unused", "http2.flags.unused_settings",
FT_UINT8, BASE_HEX, NULL, HTTP2_FLAGS_UNUSED_SETTINGS,
"Must be zero", HFILL }
},
{ &hf_http2_flags_unused_ping,
{ "Unused", "http2.flags.unused_ping",
FT_UINT8, BASE_HEX, NULL, HTTP2_FLAGS_UNUSED_PING,
"Must be zero", HFILL }
},
{ &hf_http2_flags_unused_continuation,
{ "Unused", "http2.flags.unused_continuation",
FT_UINT8, BASE_HEX, NULL, HTTP2_FLAGS_UNUSED_CONTINUATION,
"Must be zero", HFILL }
},
{ &hf_http2_flags_unused_push_promise,
{ "Unused", "http2.flags.unused_push_promise",
FT_UINT8, BASE_HEX, NULL, HTTP2_FLAGS_UNUSED_PUSH_PROMISE,
"Must be zero", HFILL }
},
{ &hf_http2_flags_unused_data,
{ "Unused", "http2.flags.unused_data",
FT_UINT8, BASE_HEX, NULL, HTTP2_FLAGS_UNUSED_DATA,
"Must be zero", HFILL }
},
{ &hf_http2_flags_unused_headers,
{ "Unused", "http2.flags.unused_headers",
FT_UINT8, BASE_HEX, NULL, HTTP2_FLAGS_UNUSED_HEADERS,
"Must be zero", HFILL }
},
{ &hf_http2_flags_settings_ack,
{ "ACK", "http2.flags.ack.settings",
FT_BOOLEAN, 8, NULL, HTTP2_FLAGS_ACK,
"Indicates that this frame acknowledges receipt and application of the peer's SETTINGS frame", HFILL }
},
{ &hf_http2_padding,
{ "Pad Length", "http2.padding",
FT_UINT8, BASE_HEX, NULL, 0x0,
"Padding size", HFILL }
},
{ &hf_http2_pad_length,
{ "Pad Length", "http2.pad_length",
FT_UINT16, BASE_DEC, NULL, 0x0,
NULL, HFILL }
},
{ &hf_http2_excl_dependency,
{ "Exclusive", "http2.exclusive",
FT_BOOLEAN, 32, NULL, 0x80000000,
"A single bit flag indicates that the stream dependency is exclusive", HFILL }
},
{ &hf_http2_stream_dependency,
{ "Stream Dependency", "http2.stream_dependency",
FT_UINT32, BASE_DEC, NULL, 0x7FFFFFFF,
"An identifier for the stream that this stream depends on", HFILL }
},
{ &hf_http2_data_data,
{ "Data", "http2.data.data",
FT_BYTES, BASE_NONE, NULL, 0x0,
"Application data", HFILL }
},
{ &hf_http2_data_padding,
{ "Padding", "http2.data.padding",
FT_BYTES, BASE_NONE, NULL, 0x0,
"Padding octets", HFILL }
},
{ &hf_http2_headers,
{ "Header Block Fragment", "http2.headers",
FT_BYTES, BASE_NONE, NULL, 0x0,
"A header block fragment", HFILL }
},
{ &hf_http2_headers_padding,
{ "Padding", "http2.headers.padding",
FT_BYTES, BASE_NONE, NULL, 0x0,
"Padding octets", HFILL }
},
{ &hf_http2_header,
{ "Header", "http2.header",
FT_NONE, BASE_NONE, NULL, 0x0,
NULL, HFILL }
},
{ &hf_http2_header_length,
{ "Header Length", "http2.header.length",
FT_UINT32, BASE_DEC, NULL, 0x0,
NULL, HFILL }
},
{ &hf_http2_header_name_length,
{ "Name Length", "http2.header.name.length",
FT_UINT32, BASE_DEC, NULL, 0x0,
NULL, HFILL }
},
{ &hf_http2_header_name,
{ "Name", "http2.header.name",
FT_STRING, BASE_NONE, NULL, 0x0,
NULL, HFILL }
},
{ &hf_http2_header_value_length,
{ "Value Length", "http2.header.value.length",
FT_UINT32, BASE_DEC, NULL, 0x0,
NULL, HFILL }
},
{ &hf_http2_header_value,
{ "Value", "http2.header.value",
FT_STRING, BASE_NONE, NULL, 0x0,
NULL, HFILL }
},
{ &hf_http2_header_repr,
{ "Representation", "http2.header.repr",
FT_STRING, BASE_NONE, NULL, 0x0,
NULL, HFILL }
},
{ &hf_http2_header_index,
{ "Index", "http2.header.index",
FT_UINT32, BASE_DEC, NULL, 0x0,
NULL, HFILL }
},
{ &hf_http2_header_table_size_update,
{ "Header table size update", "http2.header_table_size_update",
FT_NONE, BASE_NONE, NULL, 0x0,
NULL, HFILL }
},
{ &hf_http2_header_table_size,
{ "Header table size", "http2.header_table_size_update.header_table_size",
FT_UINT32, BASE_DEC, NULL, 0x0,
NULL, HFILL }
},
{ &hf_http2_rst_stream_error,
{ "Error", "http2.rst_stream.error",
FT_UINT32, BASE_DEC, VALS(http2_error_codes_vals), 0x0,
"The error code indicates why the stream is being terminated", HFILL }
},
{ &hf_http2_settings,
{ "Settings", "http2.settings",
FT_NONE, BASE_NONE, NULL, 0x0,
NULL, HFILL }
},
{ &hf_http2_settings_identifier,
{ "Settings Identifier", "http2.settings.id",
FT_UINT8, BASE_DEC, VALS(http2_settings_vals), 0x0,
NULL, HFILL }
},
{ &hf_http2_settings_header_table_size,
{ "Header table size", "http2.settings.header_table_size",
FT_UINT32, BASE_DEC, NULL, 0x0,
"Allows the sender to inform the remote endpoint of the size of the header compression table used to decode header blocks. The initial value is 4096 bytes", HFILL }
},
{ &hf_http2_settings_enable_push,
{ "Enable PUSH", "http2.settings.enable_push",
FT_UINT32, BASE_DEC, NULL, 0x0,
"The initial value is 1, which indicates that push is permitted", HFILL }
},
{ &hf_http2_settings_max_concurrent_streams,
{ "Max concurrent streams", "http2.settings.max_concurrent_streams",
FT_UINT32, BASE_DEC, NULL, 0x0,
"Indicates the maximum number of concurrent streams that the sender will allow", HFILL }
},
{ &hf_http2_settings_initial_window_size,
{ "Initial Windows Size", "http2.settings.initial_window_size",
FT_UINT32, BASE_DEC, NULL, 0x0,
"Indicates the sender's initial window size (in bytes) for stream level flow control", HFILL }
},
{ &hf_http2_settings_max_frame_size,
{ "Max frame size", "http2.settings.max_frame_size",
FT_UINT32, BASE_DEC, NULL, 0x0,
"Indicates the size of the largest frame payload that the sender will allow", HFILL }
},
{ &hf_http2_settings_max_header_list_size,
{ "Max header list size", "http2.settings.max_header_list_size",
FT_UINT32, BASE_DEC, NULL, 0x0,
"This advisory setting informs a peer of the maximum size of header list that the sender is prepared to accept.", HFILL }
},
{ &hf_http2_settings_unknown,
{ "Unknown Settings", "http2.settings.unknown",
FT_UINT32, BASE_DEC, NULL, 0x0,
NULL, HFILL }
},
{ &hf_http2_push_promise_r,
{ "Reserved", "http2.push_promise.r",
FT_UINT32, BASE_HEX, NULL, MASK_HTTP2_RESERVED,
"Must be zero", HFILL }
},
{ &hf_http2_push_promise_promised_stream_id,
{ "Promised-Stream-ID", "http2.push_promise.promised_stream_id",
FT_UINT32, BASE_DEC, NULL, MASK_HTTP2_PRIORITY,
"Identifies the stream the endpoint intends to start sending frames for", HFILL }
},
{ &hf_http2_push_promise_header,
{ "Header", "http2.push_promise.header",
FT_STRING, BASE_NONE, NULL, 0x0,
NULL, HFILL }
},
{ &hf_http2_push_promise_padding,
{ "Padding", "http2.push_promise.padding",
FT_BYTES, BASE_NONE, NULL, 0x0,
"Padding octets", HFILL }
},
{ &hf_http2_ping,
{ "Ping", "http2.ping",
FT_BYTES, BASE_NONE, NULL, 0x0,
NULL, HFILL }
},
{ &hf_http2_pong,
{ "Pong", "http2.pong",
FT_BYTES, BASE_NONE, NULL, 0x0,
NULL, HFILL }
},
{ &hf_http2_goaway_r,
{ "Reserved", "http2.goway.r",
FT_UINT32, BASE_HEX, NULL, MASK_HTTP2_RESERVED,
"Must be zero", HFILL }
},
{ &hf_http2_goaway_last_stream_id,
{ "Promised-Stream-ID", "http2.goaway.last_stream_id",
FT_UINT32, BASE_DEC, NULL, MASK_HTTP2_PRIORITY,
"Contains the highest numbered stream identifier for which the sender of the GOAWAY frame has received frames on and might have taken some action on", HFILL }
},
{ &hf_http2_goaway_error,
{ "Error", "http2.goaway.error",
FT_UINT32, BASE_DEC, VALS(http2_error_codes_vals), 0x0,
"The error code indicates the reason for closing the connection", HFILL }
},
{ &hf_http2_goaway_addata,
{ "Additional Debug Data", "http2.goaway.addata",
FT_BYTES, BASE_NONE, NULL, 0x0,
NULL, HFILL }
},
{ &hf_http2_window_update_r,
{ "Reserved", "http2.window_update.r",
FT_UINT32, BASE_HEX, NULL, MASK_HTTP2_RESERVED,
"Must be zero", HFILL }
},
{ &hf_http2_window_update_window_size_increment,
{ "Window Size Increment", "http2.window_update.window_size_increment",
FT_UINT32, BASE_DEC, NULL, MASK_HTTP2_PRIORITY,
"Indicating the number of bytes that the sender can transmit in addition to the existing flow control window", HFILL }
},
{ &hf_http2_continuation_header,
{ "Continuation Header", "http2.continuation.header",
FT_STRING, BASE_NONE, NULL, 0x0,
"Contains a header block fragment", HFILL }
},
{ &hf_http2_continuation_padding,
{ "Padding", "http2.continuation.padding",
FT_BYTES, BASE_NONE, NULL, 0x0,
"Padding octets", HFILL }
},
{ &hf_http2_altsvc_maxage,
{ "Max-Age", "http2.altsvc.max-age",
FT_UINT32, BASE_DEC, NULL, 0x0,
"An unsigned, 32-bit integer indicating the freshness lifetime of the alternative service association", HFILL }
},
{ &hf_http2_altsvc_port,
{ "Port", "http2.altsvc.port",
FT_UINT16, BASE_DEC, NULL, 0x0,
"An unsigned, 16-bit integer indicating the port that the alternative service is available upon", HFILL }
},
{ &hf_http2_altsvc_proto_len,
{ "Proto-Len", "http2.altsvc.proto_len",
FT_UINT8, BASE_DEC, NULL, 0x0,
"An unsigned, 8-bit integer indicating the length, in octets, of the PROTOCOL-ID field", HFILL }
},
{ &hf_http2_altsvc_protocol,
{ "Protocol-ID", "http2.altsvc.protocol",
FT_STRING, BASE_NONE, NULL, 0x0,
"A sequence of bytes containing the ALPN protocol identifier", HFILL }
},
{ &hf_http2_altsvc_host_len,
{ "Host-Len", "http2.altsvc.host_len",
FT_UINT8, BASE_DEC, NULL, 0x0,
"An unsigned, 8-bit integer indicating the length, in octets, of the Host field", HFILL }
},
{ &hf_http2_altsvc_host,
{ "Host", "http2.altsvc.host",
FT_STRING, BASE_NONE, NULL, 0x0,
"ASCII string indicating the host that the alternative service is available upon", HFILL }
},
{ &hf_http2_altsvc_origin,
{ "Origin", "http2.altsvc.origin",
FT_STRING, BASE_NONE, NULL, 0x0,
"A sequence of characters containing ASCII serialisation of an "
"origin that the alternate service is applicable to.", HFILL }
},
};
static gint *ett[] = {
&ett_http2,
&ett_http2_header,
&ett_http2_headers,
&ett_http2_flags,
&ett_http2_settings
};
module_t *http2_module;
proto_http2 = proto_register_protocol("HyperText Transfer Protocol 2", "HTTP2", "http2");
proto_register_field_array(proto_http2, hf, array_length(hf));
proto_register_subtree_array(ett, array_length(ett));
http2_module = prefs_register_protocol(proto_http2, NULL);
prefs_register_bool_preference(http2_module, "heuristic_http2",
"Enable HTTP2 heuristic (disabled by default)",
"The HTTP2 heuristic is weak and there are some false positives",
&global_http2_heur);
new_register_dissector("http2", dissect_http2, proto_http2);
}
void
proto_reg_handoff_http2(void)
{
data_handle = find_dissector("data");
http2_handle = new_create_dissector_handle(dissect_http2, proto_http2);
dissector_add_for_decode_as("tcp.port", http2_handle);
heur_dissector_add("ssl", dissect_http2_heur, proto_http2);
heur_dissector_add("http", dissect_http2_heur, proto_http2);
}
