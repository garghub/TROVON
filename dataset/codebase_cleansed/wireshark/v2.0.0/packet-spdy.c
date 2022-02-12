static gboolean inflate_end_cb (wmem_allocator_t *allocator _U_,
wmem_cb_event_t event _U_, void *user_data) {
inflateEnd((z_streamp)user_data);
return FALSE;
}
static void
spdy_init_protocol(void)
{
header_info_list = NULL;
}
static spdy_conv_t * get_or_create_spdy_conversation_data(packet_info *pinfo) {
conversation_t *conversation;
spdy_conv_t *conv_data;
#ifdef HAVE_LIBZ
int retcode;
#endif
conversation = find_or_create_conversation(pinfo);
conv_data = (spdy_conv_t *)conversation_get_proto_data(conversation, proto_spdy);
if (!conv_data) {
conv_data = wmem_new0(wmem_file_scope(), spdy_conv_t);
conv_data->streams = NULL;
if (spdy_decompress_headers) {
#ifdef HAVE_LIBZ
conv_data->rqst_decompressor = wmem_new0(wmem_file_scope(), z_stream);
conv_data->rply_decompressor = wmem_new0(wmem_file_scope(), z_stream);
retcode = inflateInit(conv_data->rqst_decompressor);
if (retcode == Z_OK) {
wmem_register_callback(wmem_file_scope(), inflate_end_cb,
conv_data->rqst_decompressor);
retcode = inflateInit(conv_data->rply_decompressor);
if (retcode == Z_OK) {
wmem_register_callback(wmem_file_scope(), inflate_end_cb,
conv_data->rply_decompressor);
}
}
conv_data->dictionary_id = adler32(0L, Z_NULL, 0);
conv_data->dictionary_id = adler32(conv_data->dictionary_id,
spdy_dictionary,
(uInt)sizeof(spdy_dictionary));
#endif
}
conversation_add_proto_data(conversation, proto_spdy, conv_data);
}
return conv_data;
}
static void spdy_save_stream_info(spdy_conv_t *conv_data,
guint32 stream_id,
gchar *content_type,
gchar *content_type_params,
gchar *content_encoding) {
spdy_stream_info_t *si;
if (conv_data->streams == NULL) {
conv_data->streams = wmem_tree_new(wmem_file_scope());
}
si = (spdy_stream_info_t *)wmem_alloc(wmem_file_scope(), sizeof(spdy_stream_info_t));
si->content_type = content_type;
si->content_type_parameters = content_type_params;
si->content_encoding = content_encoding;
si->data_frames = wmem_list_new(wmem_file_scope());
si->num_data_frames = 0;
si->assembled_data = NULL;
wmem_tree_insert32(conv_data->streams, stream_id, si);
}
static spdy_stream_info_t* spdy_get_stream_info(spdy_conv_t *conv_data,
guint32 stream_id)
{
if (conv_data->streams == NULL)
return NULL;
return (spdy_stream_info_t*)wmem_tree_lookup32(conv_data->streams, stream_id);
}
static void spdy_add_data_chunk(spdy_conv_t *conv_data,
guint32 stream_id,
guint32 frame,
guint8 *data,
guint32 length)
{
spdy_stream_info_t *si = spdy_get_stream_info(conv_data, stream_id);
if (si != NULL) {
spdy_data_frame_t *df = (spdy_data_frame_t *)wmem_new(wmem_file_scope(), spdy_data_frame_t);
df->data = data;
df->length = length;
df->framenum = frame;
wmem_list_append(si->data_frames, df);
++si->num_data_frames;
}
}
static void spdy_increment_data_chunk_count(spdy_conv_t *conv_data,
guint32 stream_id) {
spdy_stream_info_t *si = spdy_get_stream_info(conv_data, stream_id);
if (si != NULL) {
++si->num_data_frames;
}
}
static guint spdy_get_num_data_frames(spdy_conv_t *conv_data,
guint32 stream_id) {
spdy_stream_info_t *si = spdy_get_stream_info(conv_data, stream_id);
return si == NULL ? 0 : si->num_data_frames;
}
static spdy_stream_info_t* spdy_assemble_data_frames(spdy_conv_t *conv_data,
guint32 stream_id) {
spdy_stream_info_t *si = spdy_get_stream_info(conv_data, stream_id);
tvbuff_t *tvb;
if (si == NULL) {
return NULL;
}
if (si->assembled_data == NULL) {
spdy_data_frame_t *df;
guint8 *data;
guint32 datalen;
guint32 offset;
wmem_list_t *dflist = si->data_frames;
wmem_list_frame_t *frame;
if (wmem_list_count(dflist) == 0) {
return si;
}
datalen = 0;
frame = wmem_list_frame_next(wmem_list_head(dflist));
while (frame != NULL) {
df = (spdy_data_frame_t *)wmem_list_frame_data(frame);
datalen += df->length;
frame = wmem_list_frame_next(frame);
}
if (datalen != 0) {
data = (guint8 *)wmem_alloc(wmem_file_scope(), datalen);
dflist = si->data_frames;
offset = 0;
frame = wmem_list_frame_next(wmem_list_head(dflist));
while (frame != NULL) {
df = (spdy_data_frame_t *)wmem_list_frame_data(frame);
memcpy(data+offset, df->data, df->length);
offset += df->length;
frame = wmem_list_frame_next(frame);
}
tvb = tvb_new_real_data(data, datalen, datalen);
si->assembled_data = tvb;
}
}
return si;
}
static void dissect_spdy_stream_id_field(tvbuff_t *tvb,
int offset,
packet_info *pinfo _U_,
proto_tree *frame_tree,
const int hfindex)
{
guint32 stream_id = tvb_get_ntohl(tvb, offset) & SPDY_STREAM_ID_MASK;
proto_tree_add_item(frame_tree, hfindex, tvb, offset, 4, ENC_BIG_ENDIAN);
if (hfindex == hf_spdy_streamid) {
proto_item_append_text(frame_tree, ", Stream: %u", stream_id);
}
}
static void dissect_spdy_flags(tvbuff_t *tvb,
int offset,
proto_tree *frame_tree,
const spdy_control_frame_info_t *frame) {
proto_item *flags_ti;
proto_tree *flags_tree;
flags_ti = proto_tree_add_item(frame_tree, hf_spdy_flags, tvb, offset, 1, ENC_BIG_ENDIAN);
flags_tree = proto_item_add_subtree(flags_ti, ett_spdy_flags);
if (frame->type == SPDY_DATA ||
frame->type == SPDY_SYN_STREAM ||
frame->type == SPDY_SYN_REPLY ||
frame->type == SPDY_HEADERS) {
proto_tree_add_item(flags_tree, hf_spdy_flags_fin, tvb, offset, 1, ENC_BIG_ENDIAN);
if (frame->flags & SPDY_FLAG_FIN) {
proto_item_append_text(frame_tree, " (FIN)");
proto_item_append_text(flags_ti, " (FIN)");
}
}
if (frame->type == SPDY_SYN_STREAM) {
proto_tree_add_item(flags_tree, hf_spdy_flags_unidirectional, tvb,
offset, 1, ENC_BIG_ENDIAN);
if (frame->flags & SPDY_FLAG_UNIDIRECTIONAL) {
proto_item_append_text(flags_ti, " (UNIDIRECTIONAL)");
}
}
if (frame->type == SPDY_SETTINGS) {
proto_tree_add_item(flags_tree, hf_spdy_flags_clear_settings, tvb,
offset, 1, ENC_BIG_ENDIAN);
if (frame->flags & SPDY_FLAG_SETTINGS_CLEAR_SETTINGS) {
proto_item_append_text(flags_ti, " (CLEAR)");
}
}
}
static int dissect_spdy_data_payload(tvbuff_t *tvb,
int offset,
packet_info *pinfo,
proto_tree *top_level_tree _U_,
proto_tree *spdy_tree,
proto_item *spdy_proto,
spdy_conv_t *conv_data,
guint32 stream_id,
const spdy_control_frame_info_t *frame)
{
dissector_handle_t handle;
guint num_data_frames;
gboolean dissected;
proto_item_append_text(spdy_proto, ", Stream: %d, Length: %d",
stream_id,
frame->length);
proto_tree_add_item(spdy_tree, hf_spdy_data, tvb, offset, frame->length, ENC_NA);
num_data_frames = spdy_get_num_data_frames(conv_data, stream_id);
if (frame->length != 0 || num_data_frames != 0) {
tvbuff_t *next_tvb = NULL;
tvbuff_t *data_tvb = NULL;
spdy_stream_info_t *si = NULL;
guint8 *copied_data;
gboolean is_single_chunk = FALSE;
gboolean have_entire_body;
char *media_str = NULL;
if (frame->length != 0) {
next_tvb = tvb_new_subset_length(tvb, offset, frame->length);
is_single_chunk = num_data_frames == 0 &&
(frame->flags & SPDY_FLAG_FIN) != 0;
if (!pinfo->fd->flags.visited) {
if (!is_single_chunk) {
if (spdy_assemble_entity_bodies) {
copied_data = (guint8 *)tvb_memdup(wmem_file_scope(),next_tvb, 0, frame->length);
spdy_add_data_chunk(conv_data, stream_id, pinfo->fd->num, copied_data, frame->length);
} else {
spdy_increment_data_chunk_count(conv_data, stream_id);
}
}
}
} else {
is_single_chunk = (num_data_frames == 1);
}
if (!(frame->flags & SPDY_FLAG_FIN)) {
col_set_fence(pinfo->cinfo, COL_INFO);
proto_item_append_text(spdy_proto, " (partial entity body)");
goto body_dissected;
}
have_entire_body = is_single_chunk;
si = spdy_assemble_data_frames(conv_data, stream_id);
if (si == NULL) {
goto body_dissected;
}
data_tvb = si->assembled_data;
if (spdy_assemble_entity_bodies) {
have_entire_body = TRUE;
}
if (!have_entire_body) {
goto body_dissected;
}
if (data_tvb == NULL) {
if (next_tvb == NULL)
goto body_dissected;
data_tvb = next_tvb;
} else {
add_new_data_source(pinfo, data_tvb, "Assembled entity body");
}
if (have_entire_body && si->content_encoding != NULL &&
g_ascii_strcasecmp(si->content_encoding, "identity") != 0) {
tvbuff_t *uncomp_tvb = NULL;
proto_item *e_ti = NULL;
proto_tree *e_tree = NULL;
if (spdy_decompress_body &&
(g_ascii_strcasecmp(si->content_encoding, "gzip") == 0 ||
g_ascii_strcasecmp(si->content_encoding, "deflate") == 0)) {
uncomp_tvb = tvb_child_uncompress(tvb, data_tvb, 0,
tvb_reported_length(data_tvb));
}
e_tree = proto_tree_add_subtree_format(spdy_tree, data_tvb,
0, tvb_reported_length(data_tvb), ett_spdy_encoded_entity, &e_ti,
"Content-encoded entity body (%s): %u bytes",
si->content_encoding,
tvb_reported_length(data_tvb));
if (si->num_data_frames > 1) {
wmem_list_t *dflist = si->data_frames;
wmem_list_frame_t *frame_item;
spdy_data_frame_t *df;
guint32 framenum = 0;
wmem_strbuf_t *str_frames = wmem_strbuf_new(wmem_packet_scope(), "");
frame_item = wmem_list_frame_next(wmem_list_head(dflist));
while (frame_item != NULL) {
df = (spdy_data_frame_t *)wmem_list_frame_data(frame_item);
if (framenum != df->framenum) {
wmem_strbuf_append_printf(str_frames, " #%u", df->framenum);
framenum = df->framenum;
}
frame_item = wmem_list_frame_next(frame_item);
}
proto_tree_add_expert_format(e_tree, pinfo, &ei_spdy_reassembly_info, data_tvb, 0,
tvb_reported_length(data_tvb),
"Assembled from %d frames in packet(s)%s",
si->num_data_frames, wmem_strbuf_get_str(str_frames));
}
if (uncomp_tvb != NULL) {
proto_item_append_text(e_ti, " -> %u bytes", tvb_reported_length(uncomp_tvb));
data_tvb = uncomp_tvb;
add_new_data_source(pinfo, data_tvb, "Uncompressed entity body");
} else {
if (spdy_decompress_body) {
proto_item_append_text(e_ti, " [Error: Decompression failed]");
}
call_dissector(data_handle, data_tvb, pinfo, e_tree);
goto body_dissected;
}
}
if (have_entire_body && port_subdissector_table != NULL) {
handle = dissector_get_uint_handle(port_subdissector_table,
pinfo->match_uint);
} else {
handle = NULL;
}
if (handle == NULL && have_entire_body && si->content_type != NULL &&
media_type_subdissector_table != NULL) {
if (si->content_type_parameters) {
media_str = wmem_strdup(wmem_packet_scope(), si->content_type_parameters);
}
pinfo->match_string = si->content_type;
handle = dissector_get_string_handle(media_type_subdissector_table,
si->content_type);
}
if (handle != NULL) {
dissected = call_dissector_with_data(handle, data_tvb, pinfo, spdy_tree, media_str);
} else {
dissected = FALSE;
}
if (!dissected && have_entire_body && si->content_type != NULL) {
call_dissector_with_data(media_handle, next_tvb, pinfo, spdy_tree, media_str);
} else {
call_dissector(data_handle, next_tvb, pinfo, spdy_tree);
}
body_dissected:
;
}
return frame->length;
}
static guint8* spdy_decompress_header_block(tvbuff_t *tvb,
z_streamp decomp,
uLong dictionary_id,
int offset,
guint32 length,
guint *uncomp_length) {
int retcode;
const guint8 *hptr = tvb_get_ptr(tvb, offset, length);
guint8 *uncomp_block = (guint8 *)wmem_alloc(wmem_packet_scope(), DECOMPRESS_BUFSIZE);
decomp->next_in = (Bytef *)hptr;
decomp->avail_in = length;
decomp->next_out = uncomp_block;
decomp->avail_out = DECOMPRESS_BUFSIZE;
retcode = inflate(decomp, Z_SYNC_FLUSH);
if (retcode == Z_NEED_DICT) {
if (decomp->adler == dictionary_id) {
retcode = inflateSetDictionary(decomp,
spdy_dictionary,
sizeof(spdy_dictionary));
if (retcode == Z_OK) {
retcode = inflate(decomp, Z_SYNC_FLUSH);
}
}
}
if (retcode != Z_OK) {
return NULL;
}
*uncomp_length = DECOMPRESS_BUFSIZE - decomp->avail_out;
return (guint8 *)wmem_memdup(wmem_file_scope(), uncomp_block, *uncomp_length);
}
static spdy_header_info_t* spdy_save_header_block(packet_info *pinfo _U_,
guint32 stream_id,
guint16 frame_type,
guint8 *header,
guint length) {
spdy_header_info_t *header_info;
if (header_info_list == NULL)
header_info_list = wmem_list_new(wmem_file_scope());
header_info = wmem_new(wmem_file_scope(), spdy_header_info_t);
header_info->stream_id = stream_id;
header_info->header_block = header;
header_info->header_block_len = length;
header_info->frame_type = frame_type;
wmem_list_append(header_info_list, header_info);
return header_info;
}
static spdy_header_info_t* spdy_find_saved_header_block(packet_info *pinfo _U_,
guint32 stream_id,
guint16 frame_type) {
wmem_list_frame_t *frame;
if ((header_info_list == NULL) || (wmem_list_head(header_info_list) == NULL))
return NULL;
frame = wmem_list_frame_next(wmem_list_head(header_info_list));
while (frame != NULL) {
spdy_header_info_t *hi = (spdy_header_info_t *)wmem_list_frame_data(frame);
if (hi->stream_id == stream_id && hi->frame_type == frame_type)
return hi;
frame = wmem_list_frame_next(frame);
}
return NULL;
}
static gchar* spdy_parse_content_type(gchar *content_type) {
gchar *cp = content_type;
while (*cp != '\0' && *cp != ';' && !g_ascii_isspace(*cp)) {
*cp = g_ascii_tolower(*cp);
++cp;
}
if (*cp == '\0') {
cp = NULL;
}
if (cp != NULL) {
*cp++ = '\0';
while (*cp == ';' || g_ascii_isspace(*cp)) {
++cp;
}
if (*cp != '\0') {
return cp;
}
}
return NULL;
}
static int dissect_spdy_header_payload(
tvbuff_t *tvb,
int offset,
packet_info *pinfo,
proto_tree *frame_tree,
const spdy_control_frame_info_t *frame,
spdy_conv_t *conv_data) {
guint32 stream_id;
int header_block_length = frame->length;
int hdr_offset = 0;
tvbuff_t *header_tvb = NULL;
const gchar *hdr_method = NULL;
const gchar *hdr_path = NULL;
const gchar *hdr_version = NULL;
const gchar *hdr_host = NULL;
const gchar *hdr_scheme = NULL;
const gchar *hdr_status = NULL;
gchar *content_type = NULL;
gchar *content_encoding = NULL;
guint32 num_headers = 0;
proto_item *header_block_item;
proto_tree *header_block_tree;
stream_id = tvb_get_ntohl(tvb, offset) & SPDY_STREAM_ID_MASK;
dissect_spdy_stream_id_field(tvb, offset, pinfo, frame_tree, hf_spdy_streamid);
offset += 4;
if (frame->type == SPDY_SYN_STREAM) {
dissect_spdy_stream_id_field(tvb, offset, pinfo, frame_tree, hf_spdy_associated_streamid);
offset += 4;
proto_tree_add_item(frame_tree, hf_spdy_priority, tvb, offset, 2, ENC_BIG_ENDIAN);
proto_tree_add_item(frame_tree, hf_spdy_unused, tvb, offset, 2, ENC_BIG_ENDIAN);
proto_tree_add_item(frame_tree, hf_spdy_slot, tvb, offset, 2, ENC_BIG_ENDIAN);
offset += 2;
}
switch (frame->type) {
case SPDY_SYN_STREAM:
header_block_length -= 10;
break;
case SPDY_SYN_REPLY:
case SPDY_HEADERS:
header_block_length -= 4;
break;
default:
DISSECTOR_ASSERT_NOT_REACHED();
}
header_block_item = proto_tree_add_item(frame_tree,
hf_spdy_header_block,
tvb,
offset,
header_block_length,
ENC_NA);
header_block_tree = proto_item_add_subtree(header_block_item,
ett_spdy_header_block);
if (!spdy_decompress_headers) {
header_tvb = tvb;
hdr_offset = offset;
} else {
spdy_header_info_t *header_info;
header_info = spdy_find_saved_header_block(pinfo,
stream_id,
frame->type);
if (header_info == NULL) {
guint8 *uncomp_ptr = NULL;
guint uncomp_length = 0;
#ifdef HAVE_LIBZ
z_streamp decomp;
if (stream_id % 2 == 0) {
decomp = conv_data->rply_decompressor;
} else if (frame->type == SPDY_HEADERS) {
decomp = conv_data->rply_decompressor;
} else if (frame->type == SPDY_SYN_STREAM) {
decomp = conv_data->rqst_decompressor;
} else if (frame->type == SPDY_SYN_REPLY) {
decomp = conv_data->rply_decompressor;
} else {
DISSECTOR_ASSERT_NOT_REACHED();
}
uncomp_ptr = spdy_decompress_header_block(tvb,
decomp,
conv_data->dictionary_id,
offset,
header_block_length,
&uncomp_length);
if (uncomp_ptr == NULL) {
expert_add_info(pinfo, frame_tree, &ei_spdy_inflation_failed);
proto_item_append_text(frame_tree, " [Error: Header decompression failed]");
return -1;
}
#endif
header_info = spdy_save_header_block(pinfo, stream_id, frame->type, uncomp_ptr, uncomp_length);
}
header_tvb = tvb_new_child_real_data(tvb, header_info->header_block,
header_info->header_block_len,
header_info->header_block_len);
add_new_data_source(pinfo, header_tvb, "Uncompressed headers");
hdr_offset = 0;
}
if (header_tvb == NULL || !spdy_decompress_headers) {
num_headers = 0;
} else {
num_headers = tvb_get_ntohl(header_tvb, hdr_offset);
proto_tree_add_item(header_block_tree,
hf_spdy_num_headers,
header_tvb,
hdr_offset,
4,
ENC_BIG_ENDIAN);
}
hdr_offset += 4;
while (num_headers--) {
gchar *header_name;
const gchar *header_value;
proto_tree *header_tree;
proto_item *header;
int header_name_offset;
int header_value_offset;
int header_name_length;
int header_value_length;
if (tvb_reported_length_remaining(header_tvb, hdr_offset) < 4) {
expert_add_info_format(pinfo, frame_tree, &ei_spdy_mal_frame_data,
"Not enough frame data for header name size.");
break;
}
header_name_offset = hdr_offset;
header_name_length = tvb_get_ntohl(header_tvb, hdr_offset);
hdr_offset += 4;
if (tvb_reported_length_remaining(header_tvb, hdr_offset) < header_name_length) {
expert_add_info_format(pinfo, frame_tree, &ei_spdy_mal_frame_data,
"Not enough frame data for header name.");
break;
}
header_name = (gchar *)tvb_get_string_enc(wmem_packet_scope(), header_tvb,
hdr_offset,
header_name_length, ENC_ASCII|ENC_NA);
hdr_offset += header_name_length;
if (tvb_reported_length_remaining(header_tvb, hdr_offset) < 4) {
expert_add_info_format(pinfo, frame_tree, &ei_spdy_mal_frame_data,
"Not enough frame data for header value size.");
break;
}
header_value_offset = hdr_offset;
header_value_length = tvb_get_ntohl(header_tvb, hdr_offset);
hdr_offset += 4;
if (tvb_reported_length_remaining(header_tvb, hdr_offset) < header_value_length) {
expert_add_info_format(pinfo, frame_tree, &ei_spdy_mal_frame_data,
"Not enough frame data for header value.");
break;
}
header_value = (gchar *)tvb_get_string_enc(wmem_packet_scope(),header_tvb,
hdr_offset,
header_value_length, ENC_ASCII|ENC_NA);
hdr_offset += header_value_length;
if (frame_tree) {
header = proto_tree_add_item(frame_tree,
hf_spdy_header,
header_tvb,
header_name_offset,
hdr_offset - header_name_offset,
ENC_NA);
proto_item_append_text(header, ": %s: %s", header_name, header_value);
header_tree = proto_item_add_subtree(header, ett_spdy_header);
proto_tree_add_item(header_tree, hf_spdy_header_name, header_tvb,
header_name_offset, 4, ENC_ASCII|ENC_BIG_ENDIAN);
proto_tree_add_item(header_tree, hf_spdy_header_value, header_tvb,
header_value_offset, 4, ENC_ASCII|ENC_BIG_ENDIAN);
}
if (g_strcmp0(header_name, ":method") == 0) {
hdr_method = header_value;
} else if (g_strcmp0(header_name, ":path") == 0) {
hdr_path = header_value;
} else if (g_strcmp0(header_name, ":version") == 0) {
hdr_version = header_value;
} else if (g_strcmp0(header_name, ":host") == 0) {
hdr_host = header_value;
} else if (g_strcmp0(header_name, ":scheme") == 0) {
hdr_scheme = header_value;
} else if (g_strcmp0(header_name, ":status") == 0) {
hdr_status = header_value;
} else if (g_strcmp0(header_name, "content-type") == 0) {
content_type = wmem_strdup(wmem_file_scope(), header_value);
} else if (g_strcmp0(header_name, "content-encoding") == 0) {
content_encoding = wmem_strdup(wmem_file_scope(), header_value);
}
}
if (hdr_version != NULL) {
if (hdr_status == NULL) {
proto_item_append_text(frame_tree, ", Request: %s %s://%s%s %s",
hdr_method, hdr_scheme, hdr_host, hdr_path, hdr_version);
} else {
proto_item_append_text(frame_tree, ", Response: %s %s",
hdr_status, hdr_version);
}
}
if (content_type != NULL && !pinfo->fd->flags.visited) {
gchar *content_type_params = spdy_parse_content_type(content_type);
spdy_save_stream_info(conv_data, stream_id, content_type,
content_type_params, content_encoding);
}
return frame->length;
}
static int dissect_spdy_rst_stream_payload(
tvbuff_t *tvb,
int offset,
packet_info *pinfo,
proto_tree *frame_tree,
const spdy_control_frame_info_t *frame) {
guint32 rst_status;
proto_item *ti;
const char* str;
dissect_spdy_stream_id_field(tvb, offset, pinfo, frame_tree, hf_spdy_streamid);
offset += 4;
ti = proto_tree_add_item(frame_tree, hf_spdy_rst_stream_status, tvb, offset, 4, ENC_BIG_ENDIAN);
rst_status = tvb_get_ntohl(tvb, offset);
if (try_val_to_str(rst_status, rst_stream_status_names) == NULL) {
expert_add_info_format(pinfo, ti, &ei_spdy_invalid_rst_stream,
"Invalid status code for RST_STREAM: %u", rst_status);
}
str = val_to_str(rst_status, rst_stream_status_names, "Unknown (%d)");
proto_item_append_text(frame_tree, ", Status: %s", str);
return frame->length;
}
static int dissect_spdy_settings_payload(
tvbuff_t *tvb,
int offset,
packet_info *pinfo,
proto_tree *frame_tree,
const spdy_control_frame_info_t *frame) {
guint32 num_entries;
proto_item *ti, *ti_setting;
proto_tree *setting_tree;
proto_tree *flags_tree;
if (frame->length < 4) {
expert_add_info(pinfo, frame_tree, &ei_spdy_mal_setting_frame);
return -1;
}
num_entries = tvb_get_ntohl(tvb, offset);
if (frame->length < num_entries * 8) {
expert_add_info_format(pinfo, frame_tree, &ei_spdy_mal_setting_frame,
"SETTINGS frame too small [num_entries=%d]", num_entries);
return -1;
}
proto_tree_add_item(frame_tree, hf_spdy_num_settings, tvb, offset, 4, ENC_BIG_ENDIAN);
offset += 4;
while (num_entries > 0) {
const gchar *setting_id_str;
guint32 setting_value;
ti_setting = proto_tree_add_item(frame_tree, hf_spdy_setting, tvb, offset, 8, ENC_NA);
setting_tree = proto_item_add_subtree(ti_setting, ett_spdy_setting);
if (setting_tree) {
ti = proto_tree_add_item(setting_tree, hf_spdy_flags, tvb, offset, 1, ENC_BIG_ENDIAN);
flags_tree = proto_item_add_subtree(ti, ett_spdy_flags);
proto_tree_add_item(flags_tree, hf_spdy_flags_persist_value, tvb, offset, 1, ENC_BIG_ENDIAN);
proto_tree_add_item(flags_tree, hf_spdy_flags_persisted, tvb, offset, 1, ENC_BIG_ENDIAN);
}
offset += 1;
setting_id_str = val_to_str(tvb_get_ntoh24(tvb, offset), setting_id_names, "Unknown(%d)");
proto_tree_add_item(setting_tree, hf_spdy_setting_id, tvb, offset, 3, ENC_BIG_ENDIAN);
offset += 3;
setting_value = tvb_get_ntohl(tvb, offset);
proto_tree_add_item(setting_tree, hf_spdy_setting_value, tvb, offset, 4, ENC_BIG_ENDIAN);
proto_item_append_text(ti_setting, ", %s: %u", setting_id_str, setting_value);
proto_item_append_text(frame_tree, ", %s: %u", setting_id_str, setting_value);
offset += 4;
--num_entries;
}
return frame->length;
}
static int dissect_spdy_ping_payload(tvbuff_t *tvb, int offset, packet_info *pinfo _U_,
proto_tree *frame_tree, const spdy_control_frame_info_t *frame)
{
guint32 ping_id = tvb_get_ntohl(tvb, offset);
proto_tree_add_item(frame_tree, hf_spdy_ping_id, tvb, offset, 4, ENC_BIG_ENDIAN);
proto_item_append_text(frame_tree, ", ID: %u", ping_id);
return frame->length;
}
static int dissect_spdy_goaway_payload(tvbuff_t *tvb,
int offset,
packet_info *pinfo,
proto_tree *frame_tree,
const spdy_control_frame_info_t *frame) {
guint32 goaway_status;
proto_item* ti;
dissect_spdy_stream_id_field(tvb, offset, pinfo, frame_tree, hf_spdy_goaway_last_good_stream_id);
offset += 4;
ti = proto_tree_add_item(frame_tree, hf_spdy_goaway_status, tvb, offset, 4, ENC_BIG_ENDIAN);
goaway_status = tvb_get_ntohl(tvb, offset);
if (try_val_to_str(goaway_status, goaway_status_names) == NULL) {
expert_add_info_format(pinfo, ti, &ei_spdy_invalid_go_away,
"Invalid status code for GOAWAY: %u", goaway_status);
}
proto_item_append_text(frame_tree, " Status=%s)",
val_to_str(goaway_status, rst_stream_status_names, "Unknown (%d)"));
return frame->length;
}
static int dissect_spdy_window_update_payload(
tvbuff_t *tvb,
int offset,
packet_info *pinfo,
proto_tree *frame_tree,
const spdy_control_frame_info_t *frame)
{
guint32 window_update_delta;
dissect_spdy_stream_id_field(tvb, offset, pinfo, frame_tree, hf_spdy_streamid);
offset += 4;
window_update_delta = tvb_get_ntohl(tvb, offset) & 0x7FFFFFFF;
proto_tree_add_item(frame_tree, hf_spdy_window_update_delta, tvb, offset, 4, ENC_BIG_ENDIAN);
proto_item_append_text(frame_tree, ", Delta: %u", window_update_delta);
return frame->length;
}
static int dissect_spdy_frame(tvbuff_t *tvb, packet_info *pinfo, proto_tree *tree, void* data _U_)
{
guint8 control_bit;
spdy_control_frame_info_t frame;
guint32 stream_id = 0;
const gchar *frame_type_name;
proto_tree *spdy_tree;
proto_item *spdy_item, *type_item = NULL;
int offset = 0;
spdy_conv_t *conv_data;
conv_data = get_or_create_spdy_conversation_data(pinfo);
col_set_str(pinfo->cinfo, COL_PROTOCOL, "SPDY");
spdy_item = proto_tree_add_item(tree, proto_spdy, tvb, offset, -1, ENC_NA);
spdy_tree = proto_item_add_subtree(spdy_item, ett_spdy);
control_bit = tvb_get_guint8(tvb, offset) & 0x80;
proto_tree_add_item(spdy_tree, hf_spdy_control_bit, tvb, offset, 2, ENC_NA);
if (control_bit) {
frame.version = tvb_get_ntohs(tvb, offset) & 0x7FFF;
proto_tree_add_item(spdy_tree, hf_spdy_version, tvb, offset, 2, ENC_BIG_ENDIAN);
offset += 2;
type_item = proto_tree_add_item(spdy_tree, hf_spdy_type, tvb, offset, 2, ENC_BIG_ENDIAN);
frame.type = tvb_get_ntohs(tvb, offset);
if (frame.type >= SPDY_INVALID) {
expert_add_info_format(pinfo, type_item, &ei_spdy_invalid_frame_type,
"Invalid SPDY control frame type: %d", frame.type);
return -1;
}
offset += 2;
} else {
frame.type = SPDY_DATA;
frame.version = 0;
stream_id = tvb_get_ntohl(tvb, offset) & SPDY_STREAM_ID_MASK;
proto_tree_add_item(spdy_tree, hf_spdy_streamid, tvb, offset, 4, ENC_BIG_ENDIAN);
offset += 4;
}
frame_type_name = val_to_str(frame.type, frame_type_names, "Unknown(%d)");
col_append_sep_str(pinfo->cinfo, COL_INFO, ", ", frame_type_name);
proto_item_append_text(spdy_tree, ": %s", frame_type_name);
frame.flags = tvb_get_guint8(tvb, offset);
if (spdy_tree) {
dissect_spdy_flags(tvb, offset, spdy_tree, &frame);
}
offset += 1;
frame.length = tvb_get_ntoh24(tvb, offset);
proto_item_set_len(spdy_item, frame.length + 8);
proto_tree_add_item(spdy_tree, hf_spdy_length, tvb, offset, 3, ENC_BIG_ENDIAN);
offset += 3;
if ((guint)tvb_reported_length_remaining(tvb, offset) < frame.length) {
expert_add_info_format(pinfo, tree, &ei_spdy_mal_frame_data,
"Not enough frame data: %d vs. %d",
frame.length, tvb_reported_length_remaining(tvb, offset));
return -1;
}
if (!control_bit) {
return offset + dissect_spdy_data_payload(tvb, offset, pinfo, tree, spdy_tree,
spdy_item, conv_data, stream_id, &frame);
}
if (frame.version < MIN_SPDY_VERSION) {
proto_item_append_text(spdy_item, " [Unsupported Version]");
return frame.length + 8;
}
switch (frame.type) {
case SPDY_SYN_STREAM:
case SPDY_SYN_REPLY:
case SPDY_HEADERS:
dissect_spdy_header_payload(tvb, offset, pinfo, spdy_tree, &frame, conv_data);
break;
case SPDY_RST_STREAM:
dissect_spdy_rst_stream_payload(tvb, offset, pinfo, spdy_tree, &frame);
break;
case SPDY_SETTINGS:
dissect_spdy_settings_payload(tvb, offset, pinfo, spdy_tree, &frame);
break;
case SPDY_PING:
dissect_spdy_ping_payload(tvb, offset, pinfo, spdy_tree, &frame);
break;
case SPDY_GOAWAY:
dissect_spdy_goaway_payload(tvb, offset, pinfo, spdy_tree, &frame);
break;
case SPDY_WINDOW_UPDATE:
dissect_spdy_window_update_payload(tvb, offset, pinfo, spdy_tree, &frame);
break;
case SPDY_CREDENTIAL:
break;
default:
expert_add_info_format(pinfo, type_item, &ei_spdy_invalid_frame_type,
"Unhandled SPDY frame type: %d", frame.type);
break;
}
col_set_fence(pinfo->cinfo, COL_INFO);
return 8 + frame.length;
}
static guint get_spdy_message_len(packet_info *pinfo _U_, tvbuff_t *tvb,
int offset, void *data _U_)
{
return (guint)tvb_get_ntoh24(tvb, offset + 5) + 8;
}
static int dissect_spdy(tvbuff_t *tvb, packet_info *pinfo, proto_tree *tree, void *data _U_)
{
col_clear(pinfo->cinfo, COL_INFO);
tcp_dissect_pdus(tvb, pinfo, tree, TRUE, 8, get_spdy_message_len, dissect_spdy_frame, data);
return tvb_captured_length(tvb);
}
static gboolean dissect_spdy_heur(tvbuff_t *tvb,
packet_info *pinfo,
proto_tree *tree,
void *data _U_)
{
guint8 first_byte = tvb_get_guint8(tvb, 0);
if (first_byte != 0x80 && first_byte != 0x0) {
return FALSE;
}
if (dissect_spdy(tvb, pinfo, tree, NULL) != 0) {
return TRUE;
}
return FALSE;
}
void proto_register_spdy(void)
{
static hf_register_info hf[] = {
{ &hf_spdy_data,
{ "Data", "spdy.data",
FT_BYTES, BASE_NONE, NULL, 0x0,
NULL, HFILL
}
},
{ &hf_spdy_control_bit,
{ "Control frame", "spdy.control_bit",
FT_BOOLEAN, 16, TFS(&tfs_yes_no), 0x8000,
"TRUE if SPDY control frame", HFILL
}
},
{ &hf_spdy_version,
{ "Version", "spdy.version",
FT_UINT16, BASE_DEC, NULL, 0x7FFF,
NULL, HFILL
}
},
{ &hf_spdy_type,
{ "Type", "spdy.type",
FT_UINT16, BASE_DEC,
VALS(frame_type_names), 0x0,
NULL, HFILL
}
},
{ &hf_spdy_flags,
{ "Flags", "spdy.flags",
FT_UINT8, BASE_HEX, NULL, 0x0,
NULL, HFILL
}
},
{ &hf_spdy_flags_fin,
{ "FIN", "spdy.flags.fin",
FT_BOOLEAN, 8,
TFS(&tfs_set_notset), SPDY_FLAG_FIN,
NULL, HFILL
}
},
{ &hf_spdy_flags_unidirectional,
{ "Unidirectional", "spdy.flags.fin",
FT_BOOLEAN, 8,
TFS(&tfs_set_notset), SPDY_FLAG_UNIDIRECTIONAL,
NULL, HFILL
}
},
{ &hf_spdy_flags_clear_settings,
{ "Persist Value", "spdy.flags.clear_settings",
FT_BOOLEAN, 8,
TFS(&tfs_set_notset), SPDY_FLAG_SETTINGS_CLEAR_SETTINGS,
NULL, HFILL
}
},
{ &hf_spdy_flags_persist_value,
{ "Persist Value", "spdy.flags.persist_value",
FT_BOOLEAN, 8,
TFS(&tfs_set_notset), SPDY_FLAG_SETTINGS_PERSIST_VALUE,
NULL, HFILL
}
},
{ &hf_spdy_flags_persisted,
{ "Persisted", "spdy.flags.persisted",
FT_BOOLEAN, 8,
TFS(&tfs_set_notset), SPDY_FLAG_SETTINGS_PERSISTED,
NULL, HFILL
}
},
{ &hf_spdy_length,
{ "Length", "spdy.length",
FT_UINT24, BASE_DEC, NULL, 0x0,
NULL, HFILL
}
},
{ &hf_spdy_header_block,
{ "Header block", "spdy.header_block",
FT_BYTES, BASE_NONE, NULL, 0x0,
NULL, HFILL
}
},
{ &hf_spdy_header,
{ "Header", "spdy.header",
FT_NONE, BASE_NONE, NULL, 0x0,
NULL, HFILL
}
},
{ &hf_spdy_header_name,
{ "Name", "spdy.header.name",
FT_UINT_STRING, BASE_NONE, NULL, 0x0,
NULL, HFILL
}
},
{ &hf_spdy_header_value,
{ "Value", "spdy.header.value",
FT_UINT_STRING, BASE_NONE, NULL, 0x0,
NULL, HFILL
}
},
{ &hf_spdy_streamid,
{ "Stream ID", "spdy.streamid",
FT_UINT32, BASE_DEC, NULL, SPDY_STREAM_ID_MASK,
NULL, HFILL
}
},
{ &hf_spdy_associated_streamid,
{ "Associated Stream ID", "spdy.associated.streamid",
FT_UINT32, BASE_DEC, NULL, SPDY_STREAM_ID_MASK,
NULL, HFILL
}
},
{ &hf_spdy_priority,
{ "Priority", "spdy.priority",
FT_UINT16, BASE_DEC, NULL, 0xE000,
NULL, HFILL
}
},
{ &hf_spdy_unused,
{ "Unused", "spdy.unused",
FT_UINT16, BASE_HEX, NULL, 0x1F00,
"Reserved for future use", HFILL
}
},
{ &hf_spdy_slot,
{ "Slot", "spdy.slot",
FT_UINT16, BASE_DEC, NULL, 0x00FF,
"Specifying the index in the server's CREDENTIAL vector of the client certificate to be used for this reques", HFILL
}
},
{ &hf_spdy_num_headers,
{ "Number of headers", "spdy.numheaders",
FT_UINT32, BASE_DEC, NULL, 0x0,
NULL, HFILL
}
},
{ &hf_spdy_rst_stream_status,
{ "Reset Status", "spdy.rst_stream_status",
FT_UINT32, BASE_DEC, VALS(rst_stream_status_names), 0x0,
NULL, HFILL
}
},
{ &hf_spdy_num_settings,
{ "Number of Settings", "spdy.num_settings",
FT_UINT32, BASE_DEC, NULL, 0x0,
NULL, HFILL
}
},
{ &hf_spdy_setting,
{ "Setting", "spdy.setting",
FT_NONE, BASE_NONE, NULL, 0x0,
NULL, HFILL
}
},
{ &hf_spdy_setting_id,
{ "ID", "spdy.setting.id",
FT_UINT24, BASE_DEC, VALS(setting_id_names), 0x0,
NULL, HFILL
}
},
{ &hf_spdy_setting_value,
{ "Value", "spdy.setting.value",
FT_UINT32, BASE_DEC, NULL, 0x0,
NULL, HFILL
}
},
{ &hf_spdy_ping_id,
{ "Ping ID", "spdy.ping_id",
FT_UINT24, BASE_DEC, NULL, 0x0,
NULL, HFILL
}
},
{ &hf_spdy_goaway_last_good_stream_id,
{ "Last Good Stream ID", "spdy.goaway_last_good_stream_id",
FT_UINT32, BASE_DEC, NULL, SPDY_STREAM_ID_MASK,
NULL, HFILL
}
},
{ &hf_spdy_goaway_status,
{ "Go Away Status", "spdy.goaway_status",
FT_UINT32, BASE_DEC, VALS(goaway_status_names), 0x0,
NULL, HFILL
}
},
{ &hf_spdy_window_update_delta,
{ "Window Update Delta", "spdy.window_update_delta",
FT_UINT32, BASE_DEC, NULL, 0x7FFFFFFF,
NULL, HFILL
}
},
};
static gint *ett[] = {
&ett_spdy,
&ett_spdy_flags,
&ett_spdy_header_block,
&ett_spdy_header,
&ett_spdy_setting,
&ett_spdy_encoded_entity,
};
static ei_register_info ei[] = {
{ &ei_spdy_inflation_failed, { "spdy.inflation_failed", PI_UNDECODED, PI_ERROR, "Inflation failed. Aborting.", EXPFILL }},
{ &ei_spdy_mal_frame_data, { "spdy.malformed.frame_data", PI_MALFORMED, PI_ERROR, "Not enough frame data", EXPFILL }},
{ &ei_spdy_mal_setting_frame, { "spdy.malformed.setting_frame", PI_MALFORMED, PI_ERROR, "SETTINGS frame too small for number of entries field.", EXPFILL }},
{ &ei_spdy_invalid_rst_stream, { "spdy.rst_stream.invalid", PI_PROTOCOL, PI_WARN, "Invalid status code for RST_STREAM", EXPFILL }},
{ &ei_spdy_invalid_go_away, { "spdy.goaway.invalid", PI_PROTOCOL, PI_WARN, "Invalid status code for GOAWAY", EXPFILL }},
{ &ei_spdy_invalid_frame_type, { "spdy.type.invalid", PI_PROTOCOL, PI_WARN, "Invalid SPDY frame type", EXPFILL }},
{ &ei_spdy_reassembly_info, { "spdy.reassembly_info", PI_REASSEMBLE, PI_CHAT, "Assembled from frames in packet(s)", EXPFILL }},
};
module_t *spdy_module;
expert_module_t* expert_spdy;
proto_spdy = proto_register_protocol("SPDY", "SPDY", "spdy");
proto_register_field_array(proto_spdy, hf, array_length(hf));
proto_register_subtree_array(ett, array_length(ett));
expert_spdy = expert_register_protocol(proto_spdy);
expert_register_field_array(expert_spdy, ei, array_length(ei));
new_register_dissector("spdy", dissect_spdy, proto_spdy);
spdy_module = prefs_register_protocol(proto_spdy, NULL);
prefs_register_bool_preference(spdy_module, "assemble_data_frames",
"Assemble SPDY bodies that consist of multiple DATA frames",
"Whether the SPDY dissector should reassemble multiple "
"data frames into an entity body.",
&spdy_assemble_entity_bodies);
prefs_register_bool_preference(spdy_module, "decompress_headers",
"Uncompress SPDY headers",
"Whether to uncompress SPDY headers.",
&spdy_decompress_headers);
prefs_register_bool_preference(spdy_module, "decompress_body",
"Uncompress entity bodies",
"Whether to uncompress entity bodies that are compressed "
"using \"Content-Encoding: \"",
&spdy_decompress_body);
spdy_handle = new_create_dissector_handle(dissect_spdy, proto_spdy);
register_init_routine(&spdy_init_protocol);
spdy_tap = register_tap("spdy");
spdy_eo_tap = register_tap("spdy_eo");
}
void proto_reg_handoff_spdy(void) {
dissector_add_uint("tcp.port", TCP_PORT_SPDY, spdy_handle);
ssl_dissector_add(0, "spdy", TRUE);
data_handle = find_dissector("data");
media_handle = find_dissector("media");
port_subdissector_table = find_dissector_table("http.port");
media_type_subdissector_table = find_dissector_table("media_type");
heur_dissector_add("tcp", dissect_spdy_heur, "SPDY over TCP", "spdy_tcp", proto_spdy, HEURISTIC_DISABLE);
}
