static guint32 XXH_read32(const void* memPtr)
{
guint32 val;
memcpy(&val, memPtr, sizeof(val));
return val;
}
static guint32 XXH_swap32(guint32 x)
{
return ((x << 24) & 0xff000000 ) |
((x << 8) & 0x00ff0000 ) |
((x >> 8) & 0x0000ff00 ) |
((x >> 24) & 0x000000ff );
}
static guint32 XXH32_round(guint32 seed, guint32 input)
{
seed += input * PRIME32_2;
seed = XXH_rotl32(seed, 13);
seed *= PRIME32_1;
return seed;
}
static guint32 XXH32_endian(const void* input, size_t len, guint32 seed, XXH_endianess endian)
{
const gint8* p = (const gint8*)input;
const gint8* bEnd = p + len;
guint32 h32;
#define XXH_get32bits(p) XXH_readLE32(p, endian)
if (len>=16) {
const gint8* const limit = bEnd - 16;
guint32 v1 = seed + PRIME32_1 + PRIME32_2;
guint32 v2 = seed + PRIME32_2;
guint32 v3 = seed + 0;
guint32 v4 = seed - PRIME32_1;
do {
v1 = XXH32_round(v1, XXH_get32bits(p)); p+=4;
v2 = XXH32_round(v2, XXH_get32bits(p)); p+=4;
v3 = XXH32_round(v3, XXH_get32bits(p)); p+=4;
v4 = XXH32_round(v4, XXH_get32bits(p)); p+=4;
} while (p<=limit);
h32 = XXH_rotl32(v1, 1) + XXH_rotl32(v2, 7) + XXH_rotl32(v3, 12) + XXH_rotl32(v4, 18);
} else {
h32 = seed + PRIME32_5;
}
h32 += (guint32) len;
while (p+4<=bEnd) {
h32 += XXH_get32bits(p) * PRIME32_3;
h32 = XXH_rotl32(h32, 17) * PRIME32_4 ;
p+=4;
}
while (p<bEnd) {
h32 += (*p) * PRIME32_5;
h32 = XXH_rotl32(h32, 11) * PRIME32_1 ;
p++;
}
h32 ^= h32 >> 15;
h32 *= PRIME32_2;
h32 ^= h32 >> 13;
h32 *= PRIME32_3;
h32 ^= h32 >> 16;
return h32;
}
static guint XXH32(const void* input, size_t len, guint seed)
{
XXH_endianess endian_detected = (XXH_endianess)XXH_CPU_LITTLE_ENDIAN;
if (endian_detected==XXH_littleEndian)
return XXH32_endian(input, len, seed, XXH_littleEndian);
else
return XXH32_endian(input, len, seed, XXH_bigEndian);
}
static const char *
kafka_error_to_str(kafka_error_t error)
{
return val_to_str(error, kafka_errors, "Unknown %d");
}
static const char *
kafka_api_key_to_str(kafka_api_key_t api_key)
{
return val_to_str(api_key, kafka_api_names, "Unknown %d");
}
static const kafka_api_info_t *
kafka_get_api_info(kafka_api_key_t api_key)
{
if ((api_key >= 0) && (api_key < ((kafka_api_key_t) array_length(kafka_apis)))) {
return &kafka_apis[api_key];
} else {
return NULL;
}
}
static gboolean
kafka_is_api_version_supported(const kafka_api_info_t *api_info, kafka_api_version_t api_version)
{
DISSECTOR_ASSERT(api_info);
return !(api_info->min_version == -1 ||
api_version < api_info->min_version ||
api_version > api_info->max_version);
}
static void
kafka_check_supported_api_key(packet_info *pinfo, proto_item *ti, kafka_query_response_t *matcher)
{
if (kafka_get_api_info(matcher->api_key) == NULL) {
col_append_fstr(pinfo->cinfo, COL_INFO, " [Unknown API key]");
expert_add_info_format(pinfo, ti, &ei_kafka_unknown_api_key,
"%s API key", kafka_api_key_to_str(matcher->api_key));
}
}
static void
kafka_check_supported_api_version(packet_info *pinfo, proto_item *ti, kafka_query_response_t *matcher)
{
const kafka_api_info_t *api_info;
api_info = kafka_get_api_info(matcher->api_key);
if (api_info != NULL && !kafka_is_api_version_supported(api_info, matcher->api_version)) {
col_append_fstr(pinfo->cinfo, COL_INFO, " [Unsupported API version]");
if (api_info->min_version == -1) {
expert_add_info_format(pinfo, ti, &ei_kafka_unsupported_api_version,
"Unsupported %s version.",
kafka_api_key_to_str(matcher->api_key));
}
else if (api_info->min_version == api_info->max_version) {
expert_add_info_format(pinfo, ti, &ei_kafka_unsupported_api_version,
"Unsupported %s version. Supports v%d.",
kafka_api_key_to_str(matcher->api_key), api_info->min_version);
} else {
expert_add_info_format(pinfo, ti, &ei_kafka_unsupported_api_version,
"Unsupported %s version. Supports v%d-%d.",
kafka_api_key_to_str(matcher->api_key),
api_info->min_version, api_info->max_version);
}
}
}
static guint
get_kafka_pdu_len(packet_info *pinfo _U_, tvbuff_t *tvb, int offset, void *data _U_)
{
return 4 + tvb_get_ntohl(tvb, offset);
}
static int
dissect_kafka_array(proto_tree *tree, tvbuff_t *tvb, packet_info *pinfo, int offset,
kafka_api_version_t api_version,
int(*func)(tvbuff_t*, packet_info*, proto_tree*, int, kafka_api_version_t))
{
gint32 count, i;
count = (gint32) tvb_get_ntohl(tvb, offset);
proto_tree_add_item(tree, hf_kafka_array_count, tvb, offset, 4, ENC_BIG_ENDIAN);
offset += 4;
for (i=0; i<count; i++) {
offset = func(tvb, pinfo, tree, offset, api_version);
}
return offset;
}
static int
dissect_kafka_string(proto_tree *tree, int hf_item, tvbuff_t *tvb, packet_info *pinfo, int offset,
int *p_string_offset, int *p_string_len)
{
gint16 len;
proto_item *pi;
len = (gint16) tvb_get_ntohs(tvb, offset);
pi = proto_tree_add_item(tree, hf_kafka_string_len, tvb, offset, 2, ENC_BIG_ENDIAN);
offset += 2;
if (p_string_offset != NULL) *p_string_offset = offset;
if (len < -1) {
expert_add_info(pinfo, pi, &ei_kafka_bad_string_length);
}
else {
if (!kafka_show_string_bytes_lengths) {
PROTO_ITEM_SET_HIDDEN(pi);
}
if (len == -1) {
proto_tree_add_string(tree, hf_item, tvb, offset, 0, NULL);
}
else {
proto_tree_add_item(tree, hf_item, tvb, offset, len, ENC_NA|ENC_ASCII);
offset += len;
}
}
if (p_string_len != NULL) *p_string_len = len;
return offset;
}
static int
dissect_kafka_bytes(proto_tree *tree, int hf_item, tvbuff_t *tvb, packet_info *pinfo, int offset,
int *p_bytes_offset, int *p_bytes_len)
{
gint32 len;
proto_item *pi;
len = (gint32) tvb_get_ntohl(tvb, offset);
pi = proto_tree_add_item(tree, hf_kafka_bytes_len, tvb, offset, 4, ENC_BIG_ENDIAN);
offset += 4;
if (p_bytes_offset != NULL) *p_bytes_offset = offset;
if (len < -1) {
expert_add_info(pinfo, pi, &ei_kafka_bad_bytes_length);
}
else {
if (!kafka_show_string_bytes_lengths) {
PROTO_ITEM_SET_HIDDEN(pi);
}
if (len == -1) {
proto_tree_add_bytes(tree, hf_item, tvb, offset, 0, NULL);
}
else {
proto_tree_add_item(tree, hf_item, tvb, offset, len, ENC_NA);
offset += len;
}
}
if (p_bytes_len != NULL) *p_bytes_len = len;
return offset;
}
static tvbuff_t *
kafka_get_bytes(proto_tree *tree, tvbuff_t *tvb, packet_info *pinfo, int offset)
{
gint32 len;
proto_item *pi;
len = (gint32) tvb_get_ntohl(tvb, offset);
pi = proto_tree_add_item(tree, hf_kafka_bytes_len, tvb, offset, 4, ENC_BIG_ENDIAN);
offset += 4;
if (len < -1) {
expert_add_info(pinfo, pi, &ei_kafka_bad_bytes_length);
return NULL;
}
else if (len == -1) {
return NULL;
}
else {
return tvb_new_subset_length(tvb, offset, len);
}
}
static int
dissect_kafka_timestamp(tvbuff_t *tvb, packet_info *pinfo _U_, proto_tree *tree, int hf_item, int offset)
{
nstime_t nstime;
guint64 milliseconds;
milliseconds = tvb_get_ntoh64(tvb, offset);
nstime.secs = (time_t) (milliseconds / 1000);
nstime.nsecs = ((int)milliseconds % 1000) * 1000000;
proto_tree_add_time(tree, hf_item, tvb, offset, 8, &nstime);
offset += 8;
return offset;
}
static void show_compression_reduction(tvbuff_t *tvb, proto_tree *tree, guint compressed_size, guint uncompressed_size)
{
proto_item *ti;
if (uncompressed_size != 0) {
ti = proto_tree_add_float(tree, hf_kafka_message_compression_reduction, tvb, 0, 0,
(float)compressed_size / (float)uncompressed_size);
PROTO_ITEM_SET_GENERATED(ti);
}
}
static int
dissect_kafka_message(tvbuff_t *tvb, packet_info *pinfo, proto_tree *tree, int start_offset)
{
proto_item *message_ti, *decrypt_item;
proto_tree *subtree;
tvbuff_t *raw, *payload;
int offset = start_offset;
gint8 magic_byte;
guint8 codec;
guint bytes_length = 0;
subtree = proto_tree_add_subtree(tree, tvb, offset, -1, ett_kafka_message, &message_ti, "Message");
proto_tree_add_item(subtree, hf_kafka_message_crc, tvb, offset, 4, ENC_BIG_ENDIAN);
offset += 4;
magic_byte = tvb_get_guint8(tvb, offset);
proto_tree_add_item(subtree, hf_kafka_message_magic, tvb, offset, 1, ENC_BIG_ENDIAN);
offset += 1;
proto_tree_add_item(subtree, hf_kafka_message_codec, tvb, offset, 1, ENC_BIG_ENDIAN);
codec = tvb_get_guint8(tvb, offset) & KAFKA_MESSAGE_CODEC_MASK;
proto_tree_add_item(subtree, hf_kafka_message_timestamp_type, tvb, offset, 1, ENC_BIG_ENDIAN);
offset += 1;
if (magic_byte >= 1) {
offset = dissect_kafka_timestamp(tvb, pinfo, subtree, hf_kafka_message_timestamp, offset);
}
offset = dissect_kafka_bytes(subtree, hf_kafka_message_key, tvb, pinfo, offset, NULL, &bytes_length);
switch (codec) {
case KAFKA_MESSAGE_CODEC_GZIP:
raw = kafka_get_bytes(subtree, tvb, pinfo, offset);
offset += 4;
if (raw) {
guint compressed_size = tvb_captured_length(raw);
proto_tree_add_item(subtree, hf_kafka_message_value_compressed, tvb, offset, compressed_size, ENC_NA);
payload = tvb_child_uncompress(tvb, raw, 0, compressed_size);
if (payload) {
show_compression_reduction(tvb, subtree, compressed_size, (guint)tvb_captured_length(payload));
add_new_data_source(pinfo, payload, "Uncompressed Message");
dissect_kafka_message_set(payload, pinfo, subtree, 0, FALSE, codec);
} else {
decrypt_item = proto_tree_add_item(subtree, hf_kafka_message_value, raw, 0, -1, ENC_NA);
expert_add_info(pinfo, decrypt_item, &ei_kafka_message_decompress);
}
offset += compressed_size;
col_append_fstr(pinfo->cinfo, COL_INFO, " [GZIPd message set]");
proto_item_append_text(message_ti, " (GZIPd message set)");
}
else {
proto_tree_add_bytes(subtree, hf_kafka_message_value, tvb, offset, 0, NULL);
}
break;
case KAFKA_MESSAGE_CODEC_SNAPPY:
#ifdef HAVE_SNAPPY
raw = kafka_get_bytes(subtree, tvb, pinfo, offset);
offset += 4;
if (raw) {
guint compressed_size = tvb_reported_length(raw);
guint8 *data = (guint8*)tvb_memdup(wmem_packet_scope(), raw, 0, compressed_size);
size_t uncompressed_size;
snappy_status ret = SNAPPY_INVALID_INPUT;
proto_tree_add_item(subtree, hf_kafka_message_value_compressed, tvb, offset, compressed_size, ENC_NA);
if (tvb_memeql(raw, 0, kafka_xerial_header, sizeof(kafka_xerial_header)) == 0) {
guint chunk_size, pos = 16;
payload = tvb_new_composite();
while (pos < compressed_size) {
chunk_size = tvb_get_ntohl(raw, pos);
pos += 4;
ret = snappy_uncompressed_length(&data[pos], chunk_size, &uncompressed_size);
if (ret == SNAPPY_OK) {
guint8 *decompressed_buffer = (guint8*)wmem_alloc(pinfo->pool, uncompressed_size);
ret = snappy_uncompress(&data[pos], chunk_size, decompressed_buffer, &uncompressed_size);
if (ret == SNAPPY_OK) {
tvb_composite_append(payload,
tvb_new_child_real_data(tvb, decompressed_buffer,
(guint32)uncompressed_size, (guint32)uncompressed_size));
} else {
wmem_free(pinfo->pool, decompressed_buffer);
break;
}
}
pos += chunk_size;
}
tvb_composite_finalize(payload);
} else {
ret = snappy_uncompressed_length(data, compressed_size, &uncompressed_size);
if (ret == SNAPPY_OK) {
guint8 *decompressed_buffer = (guint8*)wmem_alloc(pinfo->pool, uncompressed_size);
ret = snappy_uncompress(data, compressed_size, decompressed_buffer, &uncompressed_size);
if (ret == SNAPPY_OK) {
payload = tvb_new_child_real_data(tvb, decompressed_buffer,
(guint32)uncompressed_size, (guint32)uncompressed_size);
} else {
wmem_free(pinfo->pool, decompressed_buffer);
}
}
}
if (ret == SNAPPY_OK) {
show_compression_reduction(tvb, subtree, compressed_size, (guint)uncompressed_size);
add_new_data_source(pinfo, payload, "Uncompressed Message");
dissect_kafka_message_set(payload, pinfo, subtree, 0, FALSE, codec);
col_append_fstr(pinfo->cinfo, COL_INFO, " [Snappy-compressed message set]");
proto_item_append_text(message_ti, " (Snappy-compressed message set)");
} else {
decrypt_item = proto_tree_add_item(subtree, hf_kafka_message_value, raw, 0, -1, ENC_NA);
expert_add_info(pinfo, decrypt_item, &ei_kafka_message_decompress);
}
offset += tvb_captured_length(raw);
}
break;
#endif
case KAFKA_MESSAGE_CODEC_LZ4:
#if defined HAVE_LZ4 && LZ4_VERSION_NUMBER >= 10301
raw = kafka_get_bytes(subtree, tvb, pinfo, offset);
offset += 4;
if (raw) {
LZ4F_decompressionContext_t lz4_ctxt;
LZ4F_frameInfo_t lz4_info;
LZ4F_errorCode_t ret;
size_t src_offset, src_size, dst_size;
guchar *decompressed_buffer = NULL;
guint compressed_size = tvb_reported_length(raw);
guint8 *data = (guint8*)tvb_memdup(wmem_packet_scope(), raw, 0, compressed_size);
if (compressed_size > 7) {
guint hdr_end = 6;
if (data[4] & 0x08) {
hdr_end += 8;
}
if (hdr_end < compressed_size) {
data[hdr_end] = (XXH32(&data[4], hdr_end - 4, 0) >> 8) & 0xff;
}
}
proto_tree_add_item(subtree, hf_kafka_message_value_compressed, tvb, offset, compressed_size, ENC_NA);
ret = LZ4F_createDecompressionContext(&lz4_ctxt, LZ4F_VERSION);
if (LZ4F_isError(ret)) {
goto fail;
}
src_offset = compressed_size;
ret = LZ4F_getFrameInfo(lz4_ctxt, &lz4_info, data, &src_offset);
if (LZ4F_isError(ret)) {
LZ4F_freeDecompressionContext(lz4_ctxt);
goto fail;
}
switch (lz4_info.blockSizeID) {
case LZ4F_max64KB:
dst_size = 1 << 16;
break;
case LZ4F_max256KB:
dst_size = 1 << 18;
break;
case LZ4F_max1MB:
dst_size = 1 << 20;
break;
case LZ4F_max4MB:
dst_size = 1 << 22;
break;
default:
LZ4F_freeDecompressionContext(lz4_ctxt);
goto fail;
}
if (lz4_info.contentSize && lz4_info.contentSize < dst_size) {
dst_size = (size_t)lz4_info.contentSize;
}
decompressed_buffer = (guchar*)wmem_alloc(pinfo->pool, dst_size);
src_size = compressed_size - src_offset;
ret = LZ4F_decompress(lz4_ctxt, decompressed_buffer, &dst_size,
&data[src_offset], &src_size, NULL);
LZ4F_freeDecompressionContext(lz4_ctxt);
if (ret == 0) {
size_t uncompressed_size = dst_size;
show_compression_reduction(tvb, subtree, compressed_size, (guint)uncompressed_size);
payload = tvb_new_child_real_data(tvb, decompressed_buffer,
(guint32)uncompressed_size, (guint32)uncompressed_size);
add_new_data_source(pinfo, payload, "Uncompressed Message");
dissect_kafka_message_set(payload, pinfo, subtree, 0, FALSE, codec);
col_append_fstr(pinfo->cinfo, COL_INFO, " [LZ4-compressed message set]");
proto_item_append_text(message_ti, " (LZ4-compressed message set)");
} else {
fail:
decrypt_item = proto_tree_add_item(subtree, hf_kafka_message_value, raw, 0, -1, ENC_NA);
expert_add_info(pinfo, decrypt_item, &ei_kafka_message_decompress);
}
offset += compressed_size;
}
break;
#endif
case KAFKA_MESSAGE_CODEC_NONE:
default:
offset = dissect_kafka_bytes(subtree, hf_kafka_message_value, tvb, pinfo, offset, NULL, &bytes_length);
col_append_fstr(pinfo->cinfo, COL_INFO, " [%u bytes]", bytes_length);
proto_item_append_text(message_ti, " (%u bytes)", bytes_length);
}
proto_item_set_len(message_ti, offset - start_offset);
return offset;
}
static int
dissect_kafka_message_set(tvbuff_t *tvb, packet_info *pinfo, proto_tree *tree, int start_offset, gboolean has_length_field, guint8 codec)
{
proto_item *ti;
proto_tree *subtree;
gint len;
int offset = start_offset;
int messages = 0;
if (has_length_field) {
proto_tree_add_item(tree, hf_kafka_message_set_size, tvb, offset, 4, ENC_BIG_ENDIAN);
len = (gint)tvb_get_ntohl(tvb, offset);
offset += 4;
start_offset += 4;
}
else {
len = tvb_reported_length_remaining(tvb, offset);
}
if (len <= 0) {
return offset;
}
subtree = proto_tree_add_subtree(tree, tvb, offset, -1, ett_kafka_message_set, &ti, "Message Set");
if (codec != KAFKA_MESSAGE_CODEC_NONE) {
proto_item_append_text(subtree, " [from compressed %s message]", val_to_str_const(codec, kafka_message_codecs, "Unknown codec"));
}
while (offset - start_offset < len) {
proto_tree_add_item(subtree, hf_kafka_offset, tvb, offset, 8, ENC_BIG_ENDIAN);
offset += 8;
proto_tree_add_item(subtree, hf_kafka_message_size, tvb, offset, 4, ENC_BIG_ENDIAN);
offset += 4;
offset = dissect_kafka_message(tvb, pinfo, subtree, offset);
messages += 1;
}
proto_item_append_text(ti, " (%d Messages)", messages);
proto_item_set_len(ti, offset - start_offset);
return offset;
}
static int
dissect_kafka_partition_id(tvbuff_t *tvb, packet_info *pinfo _U_, proto_tree *tree, int offset,
kafka_api_version_t api_version _U_)
{
proto_tree_add_item(tree, hf_kafka_partition_id, tvb, offset, 4, ENC_BIG_ENDIAN);
offset += 4;
return offset;
}
static int
dissect_kafka_partition_id_get_value(tvbuff_t *tvb, packet_info *pinfo _U_, proto_tree *tree, int offset, kafka_packet_values_t* packet_values)
{
proto_tree_add_item(tree, hf_kafka_partition_id, tvb, offset, 4, ENC_BIG_ENDIAN);
if (packet_values != NULL) {
packet_values->partition_id = tvb_get_ntohl(tvb, offset);
}
offset += 4;
return offset;
}
static int
dissect_kafka_offset_get_value(tvbuff_t *tvb, packet_info *pinfo _U_, proto_tree *tree, int offset, kafka_packet_values_t* packet_values)
{
proto_tree_add_item(tree, hf_kafka_offset, tvb, offset, 8, ENC_BIG_ENDIAN);
if (packet_values != NULL) {
packet_values->offset = tvb_get_ntoh64(tvb, offset);
}
offset += 8;
return offset;
}
static int
dissect_kafka_offset(tvbuff_t *tvb, packet_info *pinfo _U_, proto_tree *tree, int offset,
kafka_api_version_t api_version _U_)
{
proto_tree_add_item(tree, hf_kafka_offset, tvb, offset, 8, ENC_BIG_ENDIAN);
offset += 8;
return offset;
}
static int
dissect_kafka_offset_time(tvbuff_t *tvb, packet_info *pinfo _U_, proto_tree *tree, int offset,
kafka_api_version_t api_version _U_)
{
proto_tree_add_item(tree, hf_kafka_offset_time, tvb, offset, 8, ENC_BIG_ENDIAN);
offset += 8;
return offset;
}
static int
dissect_kafka_offset_fetch_request_topic(tvbuff_t *tvb, packet_info *pinfo, proto_tree *tree, int start_offset,
kafka_api_version_t api_version)
{
proto_item *ti;
proto_tree *subtree;
int offset = start_offset;
guint32 count;
subtree = proto_tree_add_subtree(tree, tvb, offset, -1, ett_kafka_request_topic, &ti, "Offset Fetch Request Topic");
offset = dissect_kafka_string(subtree, hf_kafka_topic_name, tvb, pinfo, offset, NULL, NULL);
count = (gint32)tvb_get_ntohl(tvb, offset);
offset = dissect_kafka_array(subtree, tvb, pinfo, offset, api_version, &dissect_kafka_partition_id);
proto_item_set_len(ti, offset - start_offset);
proto_item_append_text(ti, " (%u partitions)", count);
return offset;
}
static int
dissect_kafka_offset_fetch_request(tvbuff_t *tvb, packet_info *pinfo, proto_tree *tree, int offset,
kafka_api_version_t api_version)
{
offset = dissect_kafka_string(tree, hf_kafka_consumer_group, tvb, pinfo, offset, NULL, NULL);
offset = dissect_kafka_array(tree, tvb, pinfo, offset, api_version,
&dissect_kafka_offset_fetch_request_topic);
return offset;
}
static int
dissect_kafka_error_ret(tvbuff_t *tvb, packet_info *pinfo, proto_tree *tree, int offset,
kafka_error_t *ret)
{
kafka_error_t error = (kafka_error_t) tvb_get_ntohs(tvb, offset);
proto_tree_add_item(tree, hf_kafka_error, tvb, offset, 2, ENC_BIG_ENDIAN);
offset += 2;
if (error != 0) {
col_append_fstr(pinfo->cinfo, COL_INFO,
" [%s] ", kafka_error_to_str(error));
}
if (ret) {
*ret = error;
}
return offset;
}
static int
dissect_kafka_error(tvbuff_t *tvb, packet_info *pinfo, proto_tree *tree, int offset)
{
return dissect_kafka_error_ret(tvb, pinfo, tree, offset, NULL);
}
static int
dissect_kafka_offset_fetch_response_partition(tvbuff_t *tvb, packet_info *pinfo, proto_tree *tree,
int start_offset, kafka_api_version_t api_version)
{
proto_item *ti;
proto_tree *subtree;
int offset = start_offset;
kafka_packet_values_t packet_values;
memset(&packet_values, 0, sizeof(packet_values));
subtree = proto_tree_add_subtree(tree, tvb, offset, -1, ett_kafka_request_partition, &ti, "Offset Fetch Response Partition");
offset = dissect_kafka_partition_id_get_value(tvb, pinfo, subtree, offset, &packet_values);
offset = dissect_kafka_offset(tvb, pinfo, subtree, offset, api_version);
offset = dissect_kafka_string(subtree, hf_kafka_metadata, tvb, pinfo, offset, NULL, NULL);
offset = dissect_kafka_error(tvb, pinfo, subtree, offset);
proto_item_append_text(ti, " (Partition-ID=%u, Offset=%" G_GINT64_MODIFIER "u)",
packet_values.partition_id, packet_values.offset);
proto_item_set_len(ti, offset - start_offset);
return offset;
}
static int
dissect_kafka_offset_fetch_response_topic(tvbuff_t *tvb, packet_info *pinfo, proto_tree *tree, int start_offset,
kafka_api_version_t api_version)
{
proto_item *ti;
proto_tree *subtree;
int offset = start_offset;
subtree = proto_tree_add_subtree(tree, tvb, offset, -1, ett_kafka_response_topic, &ti, "offset fetch response topic");
offset = dissect_kafka_string(subtree, hf_kafka_topic_name, tvb, pinfo, offset, NULL, NULL);
offset = dissect_kafka_array(subtree, tvb, pinfo, offset, api_version,
&dissect_kafka_offset_fetch_response_partition);
proto_item_set_len(ti, offset - start_offset);
return offset;
}
static int
dissect_kafka_offset_fetch_response(tvbuff_t *tvb, packet_info *pinfo, proto_tree *tree, int offset,
kafka_api_version_t api_version)
{
return dissect_kafka_array(tree, tvb, pinfo, offset, api_version,
&dissect_kafka_offset_fetch_response_topic);
}
static int
dissect_kafka_metadata_request_topic(tvbuff_t *tvb, packet_info *pinfo, proto_tree *tree, int offset,
kafka_api_version_t api_version _U_)
{
return dissect_kafka_string(tree, hf_kafka_topic_name, tvb, pinfo, offset, NULL, NULL);
}
static int
dissect_kafka_metadata_request(tvbuff_t *tvb, packet_info *pinfo, proto_tree *tree, int offset,
kafka_api_version_t api_version)
{
return dissect_kafka_array(tree, tvb, pinfo, offset, api_version,
&dissect_kafka_metadata_request_topic);
}
static int
dissect_kafka_metadata_broker(tvbuff_t *tvb, packet_info *pinfo, proto_tree *tree, int start_offset,
kafka_api_version_t api_version)
{
proto_item *ti;
proto_tree *subtree;
int offset = start_offset;
guint32 nodeid;
int host_start, host_len;
guint32 broker_port;
subtree = proto_tree_add_subtree(tree, tvb, offset, -1, ett_kafka_broker, &ti, "Broker");
nodeid = tvb_get_ntohl(tvb, offset);
proto_tree_add_item(subtree, hf_kafka_broker_nodeid, tvb, offset, 4, ENC_BIG_ENDIAN);
offset += 4;
offset = dissect_kafka_string(subtree, hf_kafka_broker_host, tvb, pinfo, offset, &host_start, &host_len);
broker_port = tvb_get_ntohl(tvb, offset);
proto_tree_add_item(subtree, hf_kafka_broker_port, tvb, offset, 4, ENC_BIG_ENDIAN);
offset += 4;
if (api_version >= 1) {
offset = dissect_kafka_string(subtree, hf_kafka_broker_rack, tvb, pinfo, offset, NULL, NULL);
}
proto_item_append_text(ti, " (node %u: %s:%u)",
nodeid,
tvb_get_string_enc(wmem_packet_scope(), tvb,
host_start, host_len, ENC_UTF_8|ENC_NA),
broker_port);
proto_item_set_len(ti, offset - start_offset);
return offset;
}
static int
dissect_kafka_metadata_replica(tvbuff_t *tvb, packet_info *pinfo _U_, proto_tree *tree, int offset,
kafka_api_version_t api_version _U_)
{
proto_tree_add_item(tree, hf_kafka_replica, tvb, offset, 4, ENC_BIG_ENDIAN);
return offset + 4;
}
static int
dissect_kafka_metadata_isr(tvbuff_t *tvb, packet_info *pinfo _U_, proto_tree *tree, int offset,
kafka_api_version_t api_version _U_)
{
proto_tree_add_item(tree, hf_kafka_isr, tvb, offset, 4, ENC_BIG_ENDIAN);
return offset + 4;
}
static int
dissect_kafka_metadata_partition(tvbuff_t *tvb, packet_info *pinfo, proto_tree *tree, int start_offset,
kafka_api_version_t api_version)
{
proto_item *ti, *subti;
proto_tree *subtree, *subsubtree;
int offset = start_offset;
int sub_start_offset;
subtree = proto_tree_add_subtree(tree, tvb, offset, -1, ett_kafka_response_partition, &ti, "Partition");
offset = dissect_kafka_error(tvb, pinfo, subtree, offset);
offset = dissect_kafka_partition_id(tvb, pinfo, subtree, offset, api_version);
proto_tree_add_item(subtree, hf_kafka_partition_leader, tvb, offset, 4, ENC_BIG_ENDIAN);
offset += 4;
sub_start_offset = offset;
subsubtree = proto_tree_add_subtree(subtree, tvb, offset, -1, ett_kafka_replicas, &subti, "Replicas");
offset = dissect_kafka_array(subsubtree, tvb, pinfo, offset, api_version, &dissect_kafka_metadata_replica);
proto_item_set_len(subti, offset - sub_start_offset);
sub_start_offset = offset;
subsubtree = proto_tree_add_subtree(subtree, tvb, offset, -1, ett_kafka_isrs, &subti, "Caught-Up Replicas");
offset = dissect_kafka_array(subsubtree, tvb, pinfo, offset, api_version, &dissect_kafka_metadata_isr);
proto_item_set_len(subti, offset - sub_start_offset);
proto_item_set_len(ti, offset - start_offset);
return offset;
}
static int
dissect_kafka_metadata_topic(tvbuff_t *tvb, packet_info *pinfo, proto_tree *tree, int start_offset,
kafka_api_version_t api_version)
{
proto_item *ti;
proto_tree *subtree;
int offset = start_offset;
int name_start, name_length;
subtree = proto_tree_add_subtree(tree, tvb, offset, -1, ett_kafka_response_topic, &ti, "Topic");
offset = dissect_kafka_error(tvb, pinfo, subtree, offset);
offset = dissect_kafka_string(subtree, hf_kafka_topic_name, tvb, pinfo, offset, &name_start, &name_length);
proto_item_append_text(ti, " (%s)",
tvb_get_string_enc(wmem_packet_scope(), tvb,
name_start, name_length, ENC_UTF_8|ENC_NA));
if (api_version >= 1) {
proto_tree_add_item(subtree, hf_kafka_is_internal, tvb, offset, 1, ENC_NA);
offset += 1;
}
offset = dissect_kafka_array(subtree, tvb, pinfo, offset, api_version, &dissect_kafka_metadata_partition);
proto_item_set_len(ti, offset - start_offset);
return offset;
}
static int
dissect_kafka_metadata_response(tvbuff_t *tvb, packet_info *pinfo, proto_tree *tree, int start_offset,
kafka_api_version_t api_version)
{
proto_item *ti;
proto_tree *subtree;
int offset = start_offset;
subtree = proto_tree_add_subtree(tree, tvb, offset, -1, ett_kafka_brokers, &ti, "Broker Metadata");
offset = dissect_kafka_array(subtree, tvb, pinfo, offset, api_version, &dissect_kafka_metadata_broker);
proto_item_set_len(ti, offset - start_offset);
if (api_version >= 2) {
offset = dissect_kafka_string(tree, hf_kafka_cluster_id, tvb, pinfo, offset, NULL, NULL);
}
if (api_version >= 1) {
proto_tree_add_item(tree, hf_kafka_controller_id, tvb, offset, 4, ENC_BIG_ENDIAN);
offset += 4;
}
start_offset = offset;
subtree = proto_tree_add_subtree(tree, tvb, offset, -1, ett_kafka_topics, &ti, "Topic Metadata");
offset = dissect_kafka_array(subtree, tvb, pinfo, offset, api_version, &dissect_kafka_metadata_topic);
proto_item_set_len(ti, offset - start_offset);
return offset;
}
static int
dissect_kafka_leader_and_isr_request_isr(tvbuff_t *tvb, packet_info *pinfo _U_, proto_tree *tree,
int offset, kafka_api_version_t api_version _U_)
{
proto_tree_add_item(tree, hf_kafka_isr, tvb, offset, 4, ENC_BIG_ENDIAN);
offset += 4;
return offset;
}
static int
dissect_kafka_leader_and_isr_request_replica(tvbuff_t *tvb, packet_info *pinfo _U_, proto_tree *tree,
int offset, kafka_api_version_t api_version _U_)
{
proto_tree_add_item(tree, hf_kafka_replica, tvb, offset, 4, ENC_BIG_ENDIAN);
offset += 4;
return offset;
}
static int
dissect_kafka_leader_and_isr_request_partition_state(tvbuff_t *tvb, packet_info *pinfo, proto_tree *tree,
int offset, kafka_api_version_t api_version)
{
proto_tree *subtree, *subsubtree;
proto_item *subti, *subsubti;
int topic_start, topic_len;
kafka_partition_t partition;
subtree = proto_tree_add_subtree(tree, tvb, offset, -1,
ett_kafka_request_partition,
&subti, "Partition State");
offset = dissect_kafka_string(subtree, hf_kafka_topic_name, tvb, pinfo, offset,
&topic_start, &topic_len);
partition = (kafka_partition_t) tvb_get_ntohl(tvb, offset);
proto_tree_add_item(subtree, hf_kafka_partition_id, tvb, offset, 4, ENC_BIG_ENDIAN);
offset += 4;
proto_tree_add_item(subtree, hf_kafka_controller_epoch, tvb, offset, 4, ENC_BIG_ENDIAN);
offset += 4;
proto_tree_add_item(subtree, hf_kafka_leader_id, tvb, offset, 4, ENC_BIG_ENDIAN);
offset += 4;
proto_tree_add_item(subtree, hf_kafka_leader_epoch, tvb, offset, 4, ENC_BIG_ENDIAN);
offset += 4;
subsubtree = proto_tree_add_subtree(subtree, tvb, offset, -1,
ett_kafka_isrs,
&subsubti, "ISRs");
offset = dissect_kafka_array(subsubtree, tvb, pinfo, offset, api_version,
&dissect_kafka_leader_and_isr_request_isr);
proto_item_set_end(subsubti, tvb, offset);
proto_tree_add_item(subtree, hf_kafka_zk_version, tvb, offset, 4, ENC_BIG_ENDIAN);
offset += 4;
subsubtree = proto_tree_add_subtree(subtree, tvb, offset, -1,
ett_kafka_replicas,
&subsubti, "Replicas");
offset = dissect_kafka_array(subsubtree, tvb, pinfo, offset, api_version,
&dissect_kafka_leader_and_isr_request_replica);
proto_item_set_end(subsubti, tvb, offset);
proto_item_set_end(subti, tvb, offset);
proto_item_append_text(subti, " (Topic=%s, Partition-ID=%u)",
tvb_get_string_enc(wmem_packet_scope(), tvb,
topic_start, topic_len, ENC_UTF_8|ENC_NA),
partition);
return offset;
}
static int
dissect_kafka_leader_and_isr_request_live_leader(tvbuff_t *tvb, packet_info *pinfo, proto_tree *tree,
int offset, kafka_api_version_t api_version _U_)
{
proto_item *subti;
proto_tree *subtree;
gint32 nodeid;
int host_start, host_len;
gint32 broker_port;
subtree = proto_tree_add_subtree(tree, tvb, offset, -1, ett_kafka_broker,
&subti, "Live Leader");
nodeid = (kafka_partition_t) tvb_get_ntohl(tvb, offset);
proto_tree_add_item(subtree, hf_kafka_broker_nodeid, tvb, offset, 4, ENC_BIG_ENDIAN);
offset += 4;
offset = dissect_kafka_string(subtree, hf_kafka_broker_host, tvb, pinfo, offset, &host_start, &host_len);
broker_port = (gint32) tvb_get_ntohl(tvb, offset);
proto_tree_add_item(subtree, hf_kafka_broker_port, tvb, offset, 4, ENC_BIG_ENDIAN);
offset += 4;
proto_item_set_end(subti, tvb, offset);
proto_item_append_text(subti, " (node %u: %s:%u)",
nodeid,
tvb_get_string_enc(wmem_packet_scope(), tvb, host_start, host_len, ENC_UTF_8|ENC_NA),
broker_port);
return offset;
}
static int
dissect_kafka_leader_and_isr_request(tvbuff_t *tvb, packet_info *pinfo, proto_tree *tree, int offset,
kafka_api_version_t api_version)
{
gint32 controller_id;
controller_id = (gint32) tvb_get_ntohl(tvb, offset);
proto_tree_add_item(tree, hf_kafka_controller_id, tvb, offset, 4, ENC_BIG_ENDIAN);
offset += 4;
proto_tree_add_item(tree, hf_kafka_controller_epoch, tvb, offset, 4, ENC_BIG_ENDIAN);
offset += 4;
offset = dissect_kafka_array(tree, tvb, pinfo, offset, api_version,
&dissect_kafka_leader_and_isr_request_partition_state);
offset = dissect_kafka_array(tree, tvb, pinfo, offset, api_version,
&dissect_kafka_leader_and_isr_request_live_leader);
col_append_fstr(pinfo->cinfo, COL_INFO, " (Controller-ID=%d)", controller_id);
return offset;
}
static int
dissect_kafka_leader_and_isr_response_partition(tvbuff_t *tvb, packet_info *pinfo, proto_tree *tree,
int offset, kafka_api_version_t api_version _U_)
{
proto_item *subti;
proto_tree *subtree;
int topic_start, topic_len;
kafka_partition_t partition;
kafka_error_t error;
subtree = proto_tree_add_subtree(tree, tvb, offset, -1,
ett_kafka_response_partition,
&subti, "Partition");
offset = dissect_kafka_string(subtree, hf_kafka_topic_name, tvb, pinfo, offset, &topic_start, &topic_len);
partition = (gint32) tvb_get_ntohl(tvb, offset);
proto_tree_add_item(subtree, hf_kafka_partition_id, tvb, offset, 4, ENC_BIG_ENDIAN);
offset += 4;
offset = dissect_kafka_error_ret(tvb, pinfo, subtree, offset, &error);
proto_item_set_end(subti, tvb, offset);
proto_item_append_text(subti, " (Topic=%s, Partition-ID=%u, Error=%s)",
tvb_get_string_enc(wmem_packet_scope(), tvb,
topic_start, topic_len, ENC_UTF_8|ENC_NA),
partition,
kafka_error_to_str(error));
return offset;
}
static int
dissect_kafka_leader_and_isr_response(tvbuff_t *tvb, packet_info *pinfo, proto_tree *tree, int offset,
kafka_api_version_t api_version)
{
offset = dissect_kafka_error(tvb, pinfo, tree, offset);
offset = dissect_kafka_array(tree, tvb, pinfo, offset, api_version,
&dissect_kafka_leader_and_isr_response_partition);
return offset;
}
static int
dissect_kafka_stop_replica_request_partition(tvbuff_t *tvb, packet_info *pinfo _U_, proto_tree *tree,
int offset, kafka_api_version_t api_version _U_)
{
proto_item *subti;
proto_tree *subtree;
int topic_start, topic_len;
kafka_partition_t partition;
subtree = proto_tree_add_subtree(tree, tvb, offset, -1,
ett_kafka_request_partition,
&subti, "Partition");
offset = dissect_kafka_string(subtree, hf_kafka_topic_name, tvb, pinfo, offset, &topic_start, &topic_len);
partition = (gint32) tvb_get_ntohl(tvb, offset);
proto_tree_add_item(subtree, hf_kafka_partition_id, tvb, offset, 4, ENC_BIG_ENDIAN);
offset += 4;
proto_item_set_end(subti, tvb, offset);
proto_item_append_text(subti, " (Topic=%s, Partition-ID=%u)",
tvb_get_string_enc(wmem_packet_scope(), tvb,
topic_start, topic_len, ENC_UTF_8|ENC_NA),
partition);
return offset;
}
static int
dissect_kafka_stop_replica_request(tvbuff_t *tvb, packet_info *pinfo, proto_tree *tree, int offset,
kafka_api_version_t api_version)
{
gint32 controller_id;
controller_id = (gint32) tvb_get_ntohl(tvb, offset);
proto_tree_add_item(tree, hf_kafka_controller_id, tvb, offset, 4, ENC_BIG_ENDIAN);
offset += 4;
proto_tree_add_item(tree, hf_kafka_controller_epoch, tvb, offset, 4, ENC_BIG_ENDIAN);
offset += 4;
proto_tree_add_item(tree, hf_kafka_delete_partitions, tvb, offset, 1, ENC_BIG_ENDIAN);
offset += 1;
offset = dissect_kafka_array(tree, tvb, pinfo, offset, api_version,
&dissect_kafka_stop_replica_request_partition);
col_append_fstr(pinfo->cinfo, COL_INFO, " (Controller-ID=%d)", controller_id);
return offset;
}
static int
dissect_kafka_stop_replica_response_partition(tvbuff_t *tvb, packet_info *pinfo, proto_tree *tree,
int offset, kafka_api_version_t api_version _U_)
{
proto_item *subti;
proto_tree *subtree;
int topic_start, topic_len;
kafka_error_t error;
kafka_partition_t partition;
subtree = proto_tree_add_subtree(tree, tvb, offset, -1,
ett_kafka_response_partition,
&subti, "Partition");
offset = dissect_kafka_string(subtree, hf_kafka_topic_name, tvb, pinfo, offset, &topic_start, &topic_len);
partition = (gint32) tvb_get_ntohl(tvb, offset);
proto_tree_add_item(subtree, hf_kafka_partition_id, tvb, offset, 4, ENC_BIG_ENDIAN);
offset += 4;
offset = dissect_kafka_error_ret(tvb, pinfo, subtree, offset, &error);
proto_item_set_end(subti, tvb, offset);
proto_item_append_text(subti, " (Topic=%s, Partition-ID=%u, Error=%s)",
tvb_get_string_enc(wmem_packet_scope(), tvb,
topic_start, topic_len, ENC_UTF_8|ENC_NA),
partition,
kafka_error_to_str(error));
return offset;
}
static int
dissect_kafka_stop_replica_response(tvbuff_t *tvb, packet_info *pinfo, proto_tree *tree, int offset,
kafka_api_version_t api_version)
{
offset = dissect_kafka_error(tvb, pinfo, tree, offset);
offset = dissect_kafka_array(tree, tvb, pinfo, offset, api_version,
&dissect_kafka_stop_replica_response_partition);
return offset;
}
static int
dissect_kafka_fetch_request_partition(tvbuff_t *tvb, packet_info *pinfo, proto_tree *tree, int offset,
kafka_api_version_t api_version _U_)
{
proto_item *ti;
proto_tree *subtree;
kafka_packet_values_t packet_values;
memset(&packet_values, 0, sizeof(packet_values));
subtree = proto_tree_add_subtree(tree, tvb, offset, 16, ett_kafka_request_partition, &ti, "Fetch Request Partition");
offset = dissect_kafka_partition_id_get_value(tvb, pinfo, subtree, offset, &packet_values);
offset = dissect_kafka_offset_get_value(tvb, pinfo, subtree, offset, &packet_values);
proto_tree_add_item(subtree, hf_kafka_max_bytes, tvb, offset, 4, ENC_BIG_ENDIAN);
offset += 4;
proto_item_append_text(ti, " (Partition-ID=%u, Offset=%" G_GINT64_MODIFIER "u)",
packet_values.partition_id, packet_values.offset);
return offset;
}
static int
dissect_kafka_fetch_request_topic(tvbuff_t *tvb, packet_info *pinfo, proto_tree *tree, int start_offset,
kafka_api_version_t api_version)
{
proto_item *ti;
proto_tree *subtree;
int offset = start_offset;
guint32 count;
int name_start, name_length;
subtree = proto_tree_add_subtree(tree, tvb, offset, -1, ett_kafka_request_topic, &ti, "Fetch Request Topic");
offset = dissect_kafka_string(subtree, hf_kafka_topic_name, tvb, pinfo, offset, &name_start, &name_length);
count = tvb_get_ntohl(tvb, offset);
offset = dissect_kafka_array(subtree, tvb, pinfo, offset, api_version,
&dissect_kafka_fetch_request_partition);
proto_item_set_len(ti, offset - start_offset);
proto_item_append_text(ti, " (%u partitions)", count);
return offset;
}
static int
dissect_kafka_fetch_request(tvbuff_t *tvb, packet_info *pinfo, proto_tree *tree, int offset,
kafka_api_version_t api_version)
{
proto_tree_add_item(tree, hf_kafka_replica, tvb, offset, 4, ENC_BIG_ENDIAN);
offset += 4;
proto_tree_add_item(tree, hf_kafka_max_wait_time, tvb, offset, 4, ENC_BIG_ENDIAN);
offset += 4;
proto_tree_add_item(tree, hf_kafka_min_bytes, tvb, offset, 4, ENC_BIG_ENDIAN);
offset += 4;
if (api_version >= 3) {
proto_tree_add_item(tree, hf_kafka_max_bytes, tvb, offset, 4, ENC_BIG_ENDIAN);
offset += 4;
}
offset = dissect_kafka_array(tree, tvb, pinfo, offset, api_version, &dissect_kafka_fetch_request_topic);
return offset;
}
static int
dissect_kafka_fetch_response_partition(tvbuff_t *tvb, packet_info *pinfo, proto_tree *tree, int start_offset,
kafka_api_version_t api_version _U_)
{
proto_item *ti;
proto_tree *subtree;
int offset = start_offset;
kafka_packet_values_t packet_values;
memset(&packet_values, 0, sizeof(packet_values));
subtree = proto_tree_add_subtree(tree, tvb, offset, -1, ett_kafka_response_partition, &ti, "Fetch Response Partition");
offset = dissect_kafka_partition_id_get_value(tvb, pinfo, subtree, offset, &packet_values);
offset = dissect_kafka_error(tvb, pinfo, subtree, offset);
offset = dissect_kafka_offset_get_value(tvb, pinfo, subtree, offset, &packet_values);
offset = dissect_kafka_message_set(tvb, pinfo, subtree, offset, TRUE, KAFKA_MESSAGE_CODEC_NONE);
proto_item_set_len(ti, offset - start_offset);
proto_item_append_text(ti, " (Partition-ID=%u, Offset=%" G_GINT64_MODIFIER "u)",
packet_values.partition_id, packet_values.offset);
return offset;
}
static int
dissect_kafka_fetch_response_topic(tvbuff_t *tvb, packet_info *pinfo, proto_tree *tree, int start_offset,
kafka_api_version_t api_version)
{
proto_item *ti;
proto_tree *subtree;
int offset = start_offset;
guint32 count;
subtree = proto_tree_add_subtree(tree, tvb, offset, -1, ett_kafka_response_topic, &ti, "Fetch Response Topic");
offset = dissect_kafka_string(subtree, hf_kafka_topic_name, tvb, pinfo, offset, NULL, NULL);
count = tvb_get_ntohl(tvb, offset);
offset = dissect_kafka_array(subtree, tvb, pinfo, offset, api_version,
&dissect_kafka_fetch_response_partition);
proto_item_set_len(ti, offset - start_offset);
proto_item_append_text(ti, " (%u partitions)", count);
return offset;
}
static int
dissect_kafka_fetch_response(tvbuff_t *tvb, packet_info *pinfo, proto_tree *tree, int offset,
kafka_api_version_t api_version)
{
if (api_version >= 1) {
proto_tree_add_item(tree, hf_kafka_throttle_time, tvb, offset, 4, ENC_BIG_ENDIAN);
offset += 4;
}
return dissect_kafka_array(tree, tvb, pinfo, offset, api_version, &dissect_kafka_fetch_response_topic);
}
static int
dissect_kafka_produce_request_partition(tvbuff_t *tvb, packet_info *pinfo, proto_tree *tree, int offset,
kafka_api_version_t api_version _U_)
{
proto_item *ti;
proto_tree *subtree;
kafka_packet_values_t packet_values;
memset(&packet_values, 0, sizeof(packet_values));
subtree = proto_tree_add_subtree(tree, tvb, offset, 14, ett_kafka_request_partition, &ti, "Produce Request Partition");
offset = dissect_kafka_partition_id_get_value(tvb, pinfo, subtree, offset, &packet_values);
offset = dissect_kafka_message_set(tvb, pinfo, subtree, offset, TRUE, KAFKA_MESSAGE_CODEC_NONE);
proto_item_append_text(ti, " (Partition-ID=%u)", packet_values.partition_id);
return offset;
}
static int
dissect_kafka_produce_request_topic(tvbuff_t *tvb, packet_info *pinfo, proto_tree *tree, int start_offset,
kafka_api_version_t api_version)
{
proto_item *ti;
proto_tree *subtree;
int offset = start_offset;
subtree = proto_tree_add_subtree(tree, tvb, offset, -1, ett_kafka_request_topic, &ti, "Produce Request Topic");
offset = dissect_kafka_string(subtree, hf_kafka_topic_name, tvb, pinfo, offset, NULL, NULL);
offset = dissect_kafka_array(subtree, tvb, pinfo, offset, api_version,
&dissect_kafka_produce_request_partition);
proto_item_set_len(ti, offset - start_offset);
return offset;
}
static int
dissect_kafka_produce_request(tvbuff_t *tvb, packet_info *pinfo, proto_tree *tree, int offset,
kafka_api_version_t api_version)
{
proto_tree_add_item(tree, hf_kafka_required_acks, tvb, offset, 2, ENC_BIG_ENDIAN);
offset += 2;
proto_tree_add_item(tree, hf_kafka_timeout, tvb, offset, 4, ENC_BIG_ENDIAN);
offset += 4;
offset = dissect_kafka_array(tree, tvb, pinfo, offset, api_version,
&dissect_kafka_produce_request_topic);
return offset;
}
static int
dissect_kafka_produce_response_partition(tvbuff_t *tvb, packet_info *pinfo, proto_tree *tree, int offset,
kafka_api_version_t api_version _U_)
{
proto_item *ti;
proto_tree *subtree;
kafka_packet_values_t packet_values;
memset(&packet_values, 0, sizeof(packet_values));
subtree = proto_tree_add_subtree(tree, tvb, offset, 14, ett_kafka_response_partition, &ti, "Produce Response Partition");
offset = dissect_kafka_partition_id_get_value(tvb, pinfo, subtree, offset, &packet_values);
offset = dissect_kafka_error(tvb, pinfo, subtree, offset);
offset = dissect_kafka_offset_get_value(tvb, pinfo, subtree, offset, &packet_values);
if (api_version >= 2) {
offset = dissect_kafka_offset_time(tvb, pinfo, subtree, offset, api_version);
}
proto_item_append_text(ti, " (Partition-ID=%u, Offset=%" G_GINT64_MODIFIER "u)",
packet_values.partition_id, packet_values.offset);
return offset;
}
static int
dissect_kafka_produce_response_topic(tvbuff_t *tvb, packet_info *pinfo, proto_tree *tree, int start_offset,
kafka_api_version_t api_version)
{
proto_item *ti;
proto_tree *subtree;
int offset = start_offset;
subtree = proto_tree_add_subtree(tree, tvb, offset, -1, ett_kafka_response_topic, &ti, "Produce Response Topic");
offset = dissect_kafka_string(subtree, hf_kafka_topic_name, tvb, pinfo, offset, NULL, NULL);
offset = dissect_kafka_array(subtree, tvb, pinfo, offset, api_version,
&dissect_kafka_produce_response_partition);
proto_item_set_len(ti, offset - start_offset);
return offset;
}
static int
dissect_kafka_produce_response(tvbuff_t *tvb, packet_info *pinfo, proto_tree *tree, int offset,
kafka_api_version_t api_version)
{
offset = dissect_kafka_array(tree, tvb, pinfo, offset, api_version, &dissect_kafka_produce_response_topic);
if (api_version >= 1) {
proto_tree_add_item(tree, hf_kafka_throttle_time, tvb, offset, 4, ENC_BIG_ENDIAN);
offset += 4;
}
return offset;
}
static int
dissect_kafka_offsets_request_partition(tvbuff_t *tvb, packet_info *pinfo, proto_tree *tree,
int start_offset, kafka_api_version_t api_version)
{
proto_item *ti;
proto_tree *subtree;
int offset = start_offset;
subtree = proto_tree_add_subtree(tree, tvb, offset, -1, ett_kafka_request_partition, &ti, "Offset Request Partition");
offset = dissect_kafka_partition_id(tvb, pinfo, subtree, offset, api_version);
offset = dissect_kafka_offset_time(tvb, pinfo, subtree, offset, api_version);
if (api_version == 0) {
proto_tree_add_item(subtree, hf_kafka_max_offsets, tvb, offset, 4, ENC_BIG_ENDIAN);
offset += 4;
}
proto_item_set_len(ti, offset - start_offset);
return offset;
}
static int
dissect_kafka_offsets_request_topic(tvbuff_t *tvb, packet_info *pinfo, proto_tree *tree, int start_offset,
kafka_api_version_t api_version)
{
proto_item *ti;
proto_tree *subtree;
int offset = start_offset;
subtree = proto_tree_add_subtree(tree, tvb, offset, -1, ett_kafka_request_topic, &ti, "Offset Request Topic");
offset = dissect_kafka_string(subtree, hf_kafka_topic_name, tvb, pinfo, offset, NULL, NULL);
offset = dissect_kafka_array(subtree, tvb, pinfo, offset, api_version,
&dissect_kafka_offsets_request_partition);
proto_item_set_len(ti, offset - start_offset);
return offset;
}
static int
dissect_kafka_offsets_request(tvbuff_t *tvb, packet_info *pinfo, proto_tree *tree, int offset,
kafka_api_version_t api_version)
{
proto_tree_add_item(tree, hf_kafka_replica, tvb, offset, 4, ENC_BIG_ENDIAN);
offset += 4;
offset = dissect_kafka_array(tree, tvb, pinfo, offset, api_version, &dissect_kafka_offsets_request_topic);
return offset;
}
static int
dissect_kafka_offsets_response_partition(tvbuff_t *tvb, packet_info *pinfo, proto_tree *tree,
int start_offset, kafka_api_version_t api_version)
{
proto_item *ti;
proto_tree *subtree;
int offset = start_offset;
subtree = proto_tree_add_subtree(tree, tvb, offset, -1, ett_kafka_response_partition, &ti, "Offset Response Partition");
offset = dissect_kafka_partition_id(tvb, pinfo, subtree, offset, api_version);
offset = dissect_kafka_error(tvb, pinfo, subtree, offset);
if (api_version == 0) {
offset = dissect_kafka_array(subtree, tvb, pinfo, offset, api_version, &dissect_kafka_offset);
}
else if (api_version >= 1) {
offset = dissect_kafka_offset_time(tvb, pinfo, subtree, offset, api_version);
offset = dissect_kafka_offset(tvb, pinfo, subtree, offset, api_version);
}
proto_item_set_len(ti, offset - start_offset);
return offset;
}
static int
dissect_kafka_offsets_response_topic(tvbuff_t *tvb, packet_info *pinfo, proto_tree *tree, int start_offset,
kafka_api_version_t api_version)
{
proto_item *ti;
proto_tree *subtree;
int offset = start_offset;
subtree = proto_tree_add_subtree(tree, tvb, offset, -1, ett_kafka_response_topic, &ti, "Offset Response Topic");
offset = dissect_kafka_string(subtree, hf_kafka_topic_name, tvb, pinfo, offset, NULL, NULL);
offset = dissect_kafka_array(subtree, tvb, pinfo, offset, api_version,
&dissect_kafka_offsets_response_partition);
proto_item_set_len(ti, offset - start_offset);
return offset;
}
static int
dissect_kafka_offsets_response(tvbuff_t *tvb, packet_info *pinfo, proto_tree *tree, int offset,
kafka_api_version_t api_version)
{
return dissect_kafka_array(tree, tvb, pinfo, offset, api_version, &dissect_kafka_offsets_response_topic);
}
static int
dissect_kafka_api_versions_request(tvbuff_t *tvb _U_, packet_info *pinfo _U_, proto_tree *tree _U_,
int offset _U_, kafka_api_version_t api_version _U_)
{
return offset;
}
static int
dissect_kafka_api_versions_response_api_version(tvbuff_t *tvb, packet_info *pinfo _U_, proto_tree *tree,
int offset, kafka_api_version_t api_version _U_)
{
proto_item *ti;
proto_tree *subtree;
kafka_api_key_t api_key;
kafka_api_version_t min_version, max_version;
const kafka_api_info_t *api_info;
subtree = proto_tree_add_subtree(tree, tvb, offset, -1, ett_kafka_api_version, &ti,
"API Version");
api_key = tvb_get_ntohs(tvb, offset);
proto_tree_add_item(subtree, hf_kafka_api_versions_api_key, tvb, offset, 2, ENC_BIG_ENDIAN);
offset += 2;
min_version = tvb_get_ntohs(tvb, offset);
proto_tree_add_item(subtree, hf_kafka_api_versions_min_version, tvb, offset, 2, ENC_BIG_ENDIAN);
offset += 2;
max_version = tvb_get_ntohs(tvb, offset);
proto_tree_add_item(subtree, hf_kafka_api_versions_max_version, tvb, offset, 2, ENC_BIG_ENDIAN);
offset += 2;
proto_item_set_end(ti, tvb, offset);
if (max_version != min_version) {
proto_item_append_text(subtree, " %s (v%d-%d)",
kafka_api_key_to_str(api_key),
min_version, max_version);
}
else {
proto_item_append_text(subtree, " %s (v%d)",
kafka_api_key_to_str(api_key),
min_version);
}
api_info = kafka_get_api_info(api_key);
if (api_info == NULL) {
proto_item_append_text(subtree, " [Unknown API key]");
expert_add_info_format(pinfo, ti, &ei_kafka_unknown_api_key,
"%s API key", kafka_api_key_to_str(api_key));
}
else if (!kafka_is_api_version_supported(api_info, min_version) ||
!kafka_is_api_version_supported(api_info, max_version)) {
if (api_info->min_version == -1) {
proto_item_append_text(subtree, " [Unsupported API version]");
expert_add_info_format(pinfo, ti, &ei_kafka_unsupported_api_version,
"Unsupported %s version.",
kafka_api_key_to_str(api_key));
}
else if (api_info->min_version == api_info->max_version) {
proto_item_append_text(subtree, " [Unsupported API version. Supports v%d]",
api_info->min_version);
expert_add_info_format(pinfo, ti, &ei_kafka_unsupported_api_version,
"Unsupported %s version. Supports v%d.",
kafka_api_key_to_str(api_key), api_info->min_version);
} else {
proto_item_append_text(subtree, " [Unsupported API version. Supports v%d-%d]",
api_info->min_version, api_info->max_version);
expert_add_info_format(pinfo, ti, &ei_kafka_unsupported_api_version,
"Unsupported %s version. Supports v%d-%d.",
kafka_api_key_to_str(api_key),
api_info->min_version, api_info->max_version);
}
}
return offset;
}
static int
dissect_kafka_api_versions_response(tvbuff_t *tvb, packet_info *pinfo, proto_tree *tree, int offset,
kafka_api_version_t api_version)
{
offset = dissect_kafka_error(tvb, pinfo, tree, offset);
offset = dissect_kafka_array(tree, tvb, pinfo, offset, api_version,
&dissect_kafka_api_versions_response_api_version);
return offset;
}
static int
dissect_kafka_update_metadata_request_isr(tvbuff_t *tvb, packet_info *pinfo _U_, proto_tree *tree,
int offset, kafka_api_version_t api_version _U_)
{
proto_tree_add_item(tree, hf_kafka_isr, tvb, offset, 4, ENC_BIG_ENDIAN);
offset += 4;
return offset;
}
static int
dissect_kafka_update_metadata_request_replica(tvbuff_t *tvb, packet_info *pinfo _U_, proto_tree *tree,
int offset, kafka_api_version_t api_version _U_)
{
proto_tree_add_item(tree, hf_kafka_replica, tvb, offset, 4, ENC_BIG_ENDIAN);
offset += 4;
return offset;
}
static int
dissect_kafka_update_metadata_request_partition_state(tvbuff_t *tvb, packet_info *pinfo, proto_tree *tree,
int offset, kafka_api_version_t api_version)
{
proto_tree *subtree, *subsubtree;
proto_item *subti, *subsubti;
int topic_start, topic_len;
kafka_partition_t partition;
subtree = proto_tree_add_subtree(tree, tvb, offset, -1,
ett_kafka_request_partition,
&subti, "Partition State");
offset = dissect_kafka_string(subtree, hf_kafka_topic_name, tvb, pinfo, offset,
&topic_start, &topic_len);
partition = (gint32) tvb_get_ntohl(tvb, offset);
proto_tree_add_item(subtree, hf_kafka_partition_id, tvb, offset, 4, ENC_BIG_ENDIAN);
offset += 4;
proto_tree_add_item(subtree, hf_kafka_controller_epoch, tvb, offset, 4, ENC_BIG_ENDIAN);
offset += 4;
proto_tree_add_item(subtree, hf_kafka_leader_id, tvb, offset, 4, ENC_BIG_ENDIAN);
offset += 4;
proto_tree_add_item(subtree, hf_kafka_leader_epoch, tvb, offset, 4, ENC_BIG_ENDIAN);
offset += 4;
subsubtree = proto_tree_add_subtree(subtree, tvb, offset, -1,
ett_kafka_isrs,
&subsubti, "ISRs");
offset = dissect_kafka_array(subsubtree, tvb, pinfo, offset, api_version,
&dissect_kafka_update_metadata_request_isr);
proto_item_set_end(subsubti, tvb, offset);
proto_tree_add_item(subtree, hf_kafka_zk_version, tvb, offset, 4, ENC_BIG_ENDIAN);
offset += 4;
subsubtree = proto_tree_add_subtree(subtree, tvb, offset, -1,
ett_kafka_replicas,
&subsubti, "Replicas");
offset = dissect_kafka_array(subsubtree, tvb, pinfo, offset, api_version,
&dissect_kafka_update_metadata_request_replica);
proto_item_set_end(subsubti, tvb, offset);
proto_item_set_end(subti, tvb, offset);
proto_item_append_text(subti, " (Topic=%s, Partition-ID=%u)",
tvb_get_string_enc(wmem_packet_scope(), tvb,
topic_start, topic_len, ENC_UTF_8|ENC_NA),
partition);
return offset;
}
static int
dissect_kafka_update_metadata_request_end_point(tvbuff_t *tvb, packet_info *pinfo, proto_tree *tree,
int offset, kafka_api_version_t api_version _U_)
{
proto_item *subti;
proto_tree *subtree;
int host_start, host_len;
gint32 broker_port;
gint16 security_protocol_type;
subtree = proto_tree_add_subtree(tree, tvb, offset, -1, ett_kafka_broker_end_point,
&subti, "End Point");
broker_port = (gint32) tvb_get_ntohl(tvb, offset);
proto_tree_add_item(subtree, hf_kafka_broker_port, tvb, offset, 4, ENC_BIG_ENDIAN);
offset += 4;
offset = dissect_kafka_string(subtree, hf_kafka_broker_host, tvb, pinfo, offset, &host_start, &host_len);
security_protocol_type = (gint16) tvb_get_ntohs(tvb, offset);
proto_tree_add_item(subtree, hf_kafka_broker_security_protocol_type, tvb, offset, 2, ENC_BIG_ENDIAN);
offset += 2;
proto_item_set_end(subti, tvb, offset);
proto_item_append_text(subti, " (%s://%s:%d)",
val_to_str_const(security_protocol_type,
kafka_security_protocol_types, "UNKNOWN"),
tvb_get_string_enc(wmem_packet_scope(), tvb, host_start, host_len,
ENC_UTF_8|ENC_NA),
broker_port);
return offset;
}
static int
dissect_kafka_update_metadata_request_live_leader(tvbuff_t *tvb, packet_info *pinfo, proto_tree *tree,
int offset, kafka_api_version_t api_version)
{
proto_item *subti;
proto_tree *subtree;
gint32 nodeid;
subtree = proto_tree_add_subtree(tree, tvb, offset, -1, ett_kafka_broker,
&subti, "Live Leader");
nodeid = (gint32) tvb_get_ntohl(tvb, offset);
proto_tree_add_item(subtree, hf_kafka_broker_nodeid, tvb, offset, 4, ENC_BIG_ENDIAN);
offset += 4;
if (api_version == 0) {
int host_start, host_len;
gint32 broker_port;
offset = dissect_kafka_string(subtree, hf_kafka_broker_host, tvb, pinfo, offset, &host_start, &host_len);
broker_port = (gint32) tvb_get_ntohl(tvb, offset);
proto_tree_add_item(subtree, hf_kafka_broker_port, tvb, offset, 4, ENC_BIG_ENDIAN);
offset += 4;
proto_item_append_text(subti, " (node %u: %s:%u)",
nodeid,
tvb_get_string_enc(wmem_packet_scope(), tvb, host_start, host_len,
ENC_UTF_8|ENC_NA),
broker_port);
} else if (api_version >= 1) {
offset = dissect_kafka_array(subtree, tvb, pinfo, offset, api_version,
&dissect_kafka_update_metadata_request_end_point);
if (api_version >= 2) {
offset = dissect_kafka_string(subtree, hf_kafka_broker_rack, tvb, pinfo, offset, NULL, NULL);
}
proto_item_append_text(subti, " (node %d)",
nodeid);
}
proto_item_set_end(subti, tvb, offset);
return offset;
}
static int
dissect_kafka_update_metadata_request(tvbuff_t *tvb, packet_info *pinfo, proto_tree *tree, int offset,
kafka_api_version_t api_version)
{
gint32 controller_id;
controller_id = (gint32) tvb_get_ntohl(tvb, offset);
proto_tree_add_item(tree, hf_kafka_controller_id, tvb, offset, 4, ENC_BIG_ENDIAN);
offset += 4;
proto_tree_add_item(tree, hf_kafka_controller_epoch, tvb, offset, 4, ENC_BIG_ENDIAN);
offset += 4;
offset = dissect_kafka_array(tree, tvb, pinfo, offset, api_version,
&dissect_kafka_update_metadata_request_partition_state);
offset = dissect_kafka_array(tree, tvb, pinfo, offset, api_version,
&dissect_kafka_update_metadata_request_live_leader);
col_append_fstr(pinfo->cinfo, COL_INFO, " (Controller-ID=%d)", controller_id);
return offset;
}
static int
dissect_kafka_update_metadata_response(tvbuff_t *tvb, packet_info *pinfo, proto_tree *tree, int offset,
kafka_api_version_t api_version _U_)
{
offset = dissect_kafka_error(tvb, pinfo, tree, offset);
return offset;
}
static int
dissect_kafka_controlled_shutdown_request(tvbuff_t *tvb, packet_info *pinfo, proto_tree *tree, int offset,
kafka_api_version_t api_version _U_)
{
gint32 broker_id;
broker_id = (gint32) tvb_get_ntohl(tvb, offset);
proto_tree_add_item(tree, hf_kafka_broker_nodeid, tvb, offset, 4, ENC_BIG_ENDIAN);
offset += 4;
col_append_fstr(pinfo->cinfo, COL_INFO, " (Broker-ID=%d)", broker_id);
return offset;
}
static int
dissect_kafka_controlled_shutdown_response_partition_remaining(tvbuff_t *tvb, packet_info *pinfo,
proto_tree *tree, int offset,
kafka_api_version_t api_version _U_)
{
proto_item *subti;
proto_tree *subtree;
int topic_start, topic_len;
kafka_partition_t partition;
subtree = proto_tree_add_subtree(tree, tvb, offset, -1, ett_kafka_response_topic, &subti,
"Partition Remaining");
offset = dissect_kafka_string(subtree, hf_kafka_topic_name, tvb, pinfo, offset,
&topic_start, &topic_len);
partition = (gint32) tvb_get_ntohl(tvb, offset);
proto_tree_add_item(subtree, hf_kafka_partition_id, tvb, offset, 4, ENC_BIG_ENDIAN);
offset += 4;
proto_item_set_end(subti, tvb, offset);
proto_item_append_text(subti, " (Topic=%s, Partition-ID=%d)",
tvb_get_string_enc(wmem_packet_scope(), tvb,
topic_start, topic_len, ENC_UTF_8|ENC_NA),
partition);
return offset;
}
static int
dissect_kafka_controlled_shutdown_response(tvbuff_t *tvb, packet_info *pinfo, proto_tree *tree, int offset,
kafka_api_version_t api_version)
{
offset = dissect_kafka_error(tvb, pinfo, tree, offset);
offset = dissect_kafka_array(tree, tvb, pinfo, offset, api_version,
&dissect_kafka_controlled_shutdown_response_partition_remaining);
return offset;
}
static int
dissect_kafka_offset_commit_request_partition(tvbuff_t *tvb, packet_info *pinfo, proto_tree *tree,
int offset, kafka_api_version_t api_version _U_)
{
proto_item *subti;
proto_tree *subtree;
kafka_partition_t partition_id;
kafka_offset_t partition_offset;
subtree = proto_tree_add_subtree(tree, tvb, offset, -1, ett_kafka_request_partition, &subti,
"Partition");
partition_id = (gint32) tvb_get_ntohl(tvb, offset);
proto_tree_add_item(subtree, hf_kafka_partition_id, tvb, offset, 4, ENC_BIG_ENDIAN);
offset += 4;
partition_offset = (gint64) tvb_get_ntoh64(tvb, offset);
proto_tree_add_item(subtree, hf_kafka_offset, tvb, offset, 8, ENC_BIG_ENDIAN);
offset += 8;
if (api_version == 1) {
offset = dissect_kafka_timestamp(tvb, pinfo, subtree, hf_kafka_commit_timestamp, offset);
}
offset = dissect_kafka_string(subtree, hf_kafka_metadata, tvb, pinfo, offset, NULL, NULL);
proto_item_set_end(subti, tvb, offset);
proto_item_append_text(subti, " (Partition-ID=%u, Offset=%" G_GINT64_MODIFIER "u)",
partition_id, partition_offset);
return offset;
}
static int
dissect_kafka_offset_commit_request_topic(tvbuff_t *tvb, packet_info *pinfo, proto_tree *tree,
int offset, kafka_api_version_t api_version)
{
proto_item *subti;
proto_tree *subtree;
int topic_start, topic_len;
subtree = proto_tree_add_subtree(tree, tvb, offset, -1, ett_kafka_request_topic, &subti, "Topic");
offset = dissect_kafka_string(subtree, hf_kafka_topic_name, tvb, pinfo, offset,
&topic_start, &topic_len);
offset = dissect_kafka_array(subtree, tvb, pinfo, offset, api_version,
&dissect_kafka_offset_commit_request_partition);
proto_item_set_end(subti, tvb, offset);
proto_item_append_text(subti, " (Topic=%s)",
tvb_get_string_enc(wmem_packet_scope(), tvb,
topic_start, topic_len, ENC_UTF_8|ENC_NA));
return offset;
}
static int
dissect_kafka_offset_commit_request(tvbuff_t *tvb, packet_info *pinfo, proto_tree *tree, int offset,
kafka_api_version_t api_version)
{
int group_start, group_len;
offset = dissect_kafka_string(tree, hf_kafka_consumer_group, tvb, pinfo, offset,
&group_start, &group_len);
if (api_version >= 1) {
proto_tree_add_item(tree, hf_kafka_generation_id, tvb, offset, 4, ENC_BIG_ENDIAN);
offset += 4;
offset = dissect_kafka_string(tree, hf_kafka_member_id, tvb, pinfo, offset, NULL, NULL);
if (api_version >= 2) {
proto_tree_add_item(tree, hf_kafka_retention_time, tvb, offset, 8, ENC_BIG_ENDIAN);
offset += 8;
}
}
offset = dissect_kafka_array(tree, tvb, pinfo, offset, api_version,
&dissect_kafka_offset_commit_request_topic);
col_append_fstr(pinfo->cinfo, COL_INFO,
" (Group=%s)",
tvb_get_string_enc(wmem_packet_scope(), tvb,
group_start, group_len, ENC_UTF_8|ENC_NA));
return offset;
}
static int
dissect_kafka_offset_commit_response_partition_response(tvbuff_t *tvb, packet_info *pinfo, proto_tree *tree,
int offset, kafka_api_version_t api_version _U_)
{
proto_item *subti;
proto_tree *subtree;
kafka_partition_t partition;
kafka_error_t error;
subtree = proto_tree_add_subtree(tree, tvb, offset, -1, ett_kafka_response_partition, &subti,
"Partition Response");
partition = (gint32) tvb_get_ntohl(tvb, offset);
proto_tree_add_item(subtree, hf_kafka_partition_id, tvb, offset, 4, ENC_BIG_ENDIAN);
offset += 4;
offset = dissect_kafka_error_ret(tvb, pinfo, subtree, offset, &error);
proto_item_set_end(subti, tvb, offset);
proto_item_append_text(subti, " (Partition-ID=%d, Error=%s)",
partition, kafka_error_to_str(error));
return offset;
}
static int
dissect_kafka_offset_commit_response_response(tvbuff_t *tvb, packet_info *pinfo, proto_tree *tree,
int offset, kafka_api_version_t api_version)
{
proto_item *subti;
proto_tree *subtree;
int topic_start, topic_len;
subtree = proto_tree_add_subtree(tree, tvb, offset, -1, ett_kafka_response_topic, &subti, "Response");
offset = dissect_kafka_string(subtree, hf_kafka_topic_name, tvb, pinfo, offset,
&topic_start, &topic_len);
offset = dissect_kafka_array(subtree, tvb, pinfo, offset, api_version,
&dissect_kafka_offset_commit_response_partition_response);
proto_item_set_end(subti, tvb, offset);
proto_item_append_text(subti, " (Topic=%s)",
tvb_get_string_enc(wmem_packet_scope(), tvb,
topic_start, topic_len, ENC_UTF_8|ENC_NA));
return offset;
}
static int
dissect_kafka_offset_commit_response(tvbuff_t *tvb, packet_info *pinfo, proto_tree *tree, int offset,
kafka_api_version_t api_version)
{
offset = dissect_kafka_array(tree, tvb, pinfo, offset, api_version,
&dissect_kafka_offset_commit_response_response);
return offset;
}
static int
dissect_kafka_group_coordinator_request(tvbuff_t *tvb, packet_info *pinfo, proto_tree *tree, int offset,
kafka_api_version_t api_version _U_)
{
int group_start, group_len;
offset = dissect_kafka_string(tree, hf_kafka_consumer_group, tvb, pinfo, offset,
&group_start, &group_len);
col_append_fstr(pinfo->cinfo, COL_INFO,
" (Group=%s)",
tvb_get_string_enc(wmem_packet_scope(), tvb,
group_start, group_len, ENC_UTF_8|ENC_NA));
return offset;
}
static int
dissect_kafka_group_coordinator_response_coordinator(tvbuff_t *tvb, packet_info *pinfo, proto_tree *tree,
int offset, kafka_api_version_t api_version _U_)
{
proto_item *subti;
proto_tree *subtree;
gint32 node_id;
int host_start, host_len;
gint32 port;
subtree = proto_tree_add_subtree(tree, tvb, offset, -1, ett_kafka_broker, &subti, "Coordinator");
node_id = (gint32) tvb_get_ntohl(tvb, offset);
proto_tree_add_item(subtree, hf_kafka_broker_nodeid, tvb, offset, 4, ENC_BIG_ENDIAN);
offset += 4;
offset = dissect_kafka_string(subtree, hf_kafka_broker_host, tvb, pinfo, offset,
&host_start, &host_len);
port = (gint32) tvb_get_ntohl(tvb, offset);
proto_tree_add_item(subtree, hf_kafka_broker_port, tvb, offset, 4, ENC_BIG_ENDIAN);
offset += 4;
proto_item_set_end(subti, tvb, offset);
proto_item_append_text(subti, " (node %u: %s:%u)",
node_id,
tvb_get_string_enc(wmem_packet_scope(), tvb,
host_start, host_len, ENC_UTF_8|ENC_NA),
port);
return offset;
}
static int
dissect_kafka_group_coordinator_response(tvbuff_t *tvb, packet_info *pinfo, proto_tree *tree, int offset,
kafka_api_version_t api_version)
{
offset = dissect_kafka_error(tvb, pinfo, tree, offset);
offset = dissect_kafka_group_coordinator_response_coordinator(tvb, pinfo, tree, offset, api_version);
return offset;
}
static int
dissect_kafka_join_group_request_group_protocols(tvbuff_t *tvb, packet_info *pinfo, proto_tree *tree,
int offset, kafka_api_version_t api_version _U_)
{
proto_item *subti;
proto_tree *subtree;
int protocol_start, protocol_len;
subtree = proto_tree_add_subtree(tree, tvb, offset, -1, ett_kafka_group_protocol, &subti,
"Group Protocol");
offset = dissect_kafka_string(subtree, hf_kafka_protocol_name, tvb, pinfo, offset,
&protocol_start, &protocol_len);
offset = dissect_kafka_bytes(subtree, hf_kafka_protocol_metadata, tvb, pinfo, offset, NULL, NULL);
proto_item_set_end(subti, tvb, offset);
proto_item_append_text(subti, " (Group-ID=%s)",
tvb_get_string_enc(wmem_packet_scope(), tvb,
protocol_start, protocol_len, ENC_UTF_8|ENC_NA));
return offset;
}
static int
dissect_kafka_join_group_request(tvbuff_t *tvb, packet_info *pinfo, proto_tree *tree, int offset,
kafka_api_version_t api_version)
{
proto_item *subti;
proto_tree *subtree;
int group_start, group_len;
int member_start, member_len;
offset = dissect_kafka_string(tree, hf_kafka_consumer_group, tvb, pinfo, offset,
&group_start, &group_len);
proto_tree_add_item(tree, hf_kafka_session_timeout, tvb, offset, 4, ENC_BIG_ENDIAN);
offset += 4;
if (api_version > 0) {
proto_tree_add_item(tree, hf_kafka_rebalance_timeout, tvb, offset, 4, ENC_BIG_ENDIAN);
offset += 4;
}
offset = dissect_kafka_string(tree, hf_kafka_member_id, tvb, pinfo, offset,
&member_start, &member_len);
offset = dissect_kafka_string(tree, hf_kafka_protocol_type, tvb, pinfo, offset, NULL, NULL);
subtree = proto_tree_add_subtree(tree, tvb, offset, -1, ett_kafka_group_protocols, &subti,
"Group Protocols");
offset = dissect_kafka_array(subtree, tvb, pinfo, offset, api_version,
&dissect_kafka_join_group_request_group_protocols);
proto_item_set_end(subti, tvb, offset);
col_append_fstr(pinfo->cinfo, COL_INFO,
" (Group=%s, Member=%s)",
tvb_get_string_enc(wmem_packet_scope(), tvb,
group_start, group_len, ENC_UTF_8|ENC_NA),
tvb_get_string_enc(wmem_packet_scope(), tvb,
member_start, member_len, ENC_UTF_8|ENC_NA));
return offset;
}
static int
dissect_kafka_join_group_response_member(tvbuff_t *tvb, packet_info *pinfo, proto_tree *tree,
int offset, kafka_api_version_t api_version _U_)
{
proto_item *subti;
proto_tree *subtree;
int member_start, member_len;
subtree = proto_tree_add_subtree(tree, tvb, offset, -1, ett_kafka_group_member, &subti, "Member");
offset = dissect_kafka_string(subtree, hf_kafka_member_id, tvb, pinfo, offset,
&member_start, &member_len);
offset = dissect_kafka_bytes(subtree, hf_kafka_member_metadata, tvb, pinfo, offset, NULL, NULL);
proto_item_set_end(subti, tvb, offset);
proto_item_append_text(subti, " (Member-ID=%s)",
tvb_get_string_enc(wmem_packet_scope(), tvb,
member_start, member_len, ENC_UTF_8|ENC_NA));
return offset;
}
static int
dissect_kafka_join_group_response(tvbuff_t *tvb, packet_info *pinfo, proto_tree *tree, int offset,
kafka_api_version_t api_version)
{
proto_item *subti;
proto_tree *subtree;
int member_start, member_len;
offset = dissect_kafka_error(tvb, pinfo, tree, offset);
proto_tree_add_item(tree, hf_kafka_generation_id, tvb, offset, 4, ENC_BIG_ENDIAN);
offset += 4;
offset = dissect_kafka_string(tree, hf_kafka_protocol_name, tvb, pinfo, offset, NULL, NULL);
offset = dissect_kafka_string(tree, hf_kafka_group_leader_id, tvb, pinfo, offset, NULL, NULL);
offset = dissect_kafka_string(tree, hf_kafka_member_id, tvb, pinfo, offset,
&member_start, &member_len);
subtree = proto_tree_add_subtree(tree, tvb, offset, -1, ett_kafka_group_members, &subti, "Members");
offset = dissect_kafka_array(subtree, tvb, pinfo, offset, api_version,
&dissect_kafka_join_group_response_member);
proto_item_set_end(subti, tvb, offset);
col_append_fstr(pinfo->cinfo, COL_INFO,
" (Member=%s)",
tvb_get_string_enc(wmem_packet_scope(), tvb,
member_start, member_len, ENC_UTF_8|ENC_NA));
return offset;
}
static int
dissect_kafka_heartbeat_request(tvbuff_t *tvb, packet_info *pinfo, proto_tree *tree, int offset,
kafka_api_version_t api_version _U_)
{
int group_start, group_len;
int member_start, member_len;
offset = dissect_kafka_string(tree, hf_kafka_consumer_group, tvb, pinfo, offset,
&group_start, &group_len);
proto_tree_add_item(tree, hf_kafka_generation_id, tvb, offset, 4, ENC_BIG_ENDIAN);
offset += 4;
offset = dissect_kafka_string(tree, hf_kafka_member_id, tvb, pinfo, offset,
&member_start, &member_len);
col_append_fstr(pinfo->cinfo, COL_INFO,
" (Group=%s, Member=%s)",
tvb_get_string_enc(wmem_packet_scope(), tvb,
group_start, group_len, ENC_UTF_8|ENC_NA),
tvb_get_string_enc(wmem_packet_scope(), tvb,
member_start, member_len, ENC_UTF_8|ENC_NA));
return offset;
}
static int
dissect_kafka_heartbeat_response(tvbuff_t *tvb, packet_info *pinfo, proto_tree *tree, int offset,
kafka_api_version_t api_version _U_)
{
offset = dissect_kafka_error(tvb, pinfo, tree, offset);
return offset;
}
static int
dissect_kafka_leave_group_request(tvbuff_t *tvb, packet_info *pinfo, proto_tree *tree, int offset,
kafka_api_version_t api_version _U_)
{
int group_start, group_len;
int member_start, member_len;
offset = dissect_kafka_string(tree, hf_kafka_consumer_group, tvb, pinfo, offset,
&group_start, &group_len);
offset = dissect_kafka_string(tree, hf_kafka_member_id, tvb, pinfo, offset,
&member_start, &member_len);
col_append_fstr(pinfo->cinfo, COL_INFO,
" (Group=%s, Member=%s)",
tvb_get_string_enc(wmem_packet_scope(), tvb,
group_start, group_len, ENC_UTF_8|ENC_NA),
tvb_get_string_enc(wmem_packet_scope(), tvb,
member_start, member_len, ENC_UTF_8|ENC_NA));
return offset;
}
static int
dissect_kafka_leave_group_response(tvbuff_t *tvb, packet_info *pinfo, proto_tree *tree, int offset,
kafka_api_version_t api_version _U_)
{
offset = dissect_kafka_error(tvb, pinfo, tree, offset);
return offset;
}
static int
dissect_kafka_sync_group_request_group_assignment(tvbuff_t *tvb, packet_info *pinfo, proto_tree *tree,
int offset, kafka_api_version_t api_version _U_)
{
proto_item *subti;
proto_tree *subtree;
int member_start, member_len;
subtree = proto_tree_add_subtree(tree, tvb, offset, -1, ett_kafka_group_assignment, &subti,
"Group Assignment");
offset = dissect_kafka_string(subtree, hf_kafka_member_id, tvb, pinfo, offset,
&member_start, &member_len);
offset = dissect_kafka_bytes(subtree, hf_kafka_member_assignment, tvb, pinfo, offset, NULL, NULL);
proto_item_set_end(subti, tvb, offset);
proto_item_append_text(subti, " (Member=%s)",
tvb_get_string_enc(wmem_packet_scope(), tvb,
member_start, member_len, ENC_UTF_8|ENC_NA));
return offset;
}
static int
dissect_kafka_sync_group_request(tvbuff_t *tvb, packet_info *pinfo, proto_tree *tree, int offset,
kafka_api_version_t api_version)
{
proto_item *subti;
proto_tree *subtree;
int group_start, group_len;
int member_start, member_len;
offset = dissect_kafka_string(tree, hf_kafka_consumer_group, tvb, pinfo, offset,
&group_start, &group_len);
proto_tree_add_item(tree, hf_kafka_generation_id, tvb, offset, 4, ENC_BIG_ENDIAN);
offset += 4;
offset = dissect_kafka_string(tree, hf_kafka_member_id, tvb, pinfo, offset,
&member_start, &member_len);
subtree = proto_tree_add_subtree(tree, tvb, offset, -1, ett_kafka_group_assignments, &subti,
"Group Assignments");
offset = dissect_kafka_array(subtree, tvb, pinfo, offset, api_version,
&dissect_kafka_sync_group_request_group_assignment);
proto_item_set_end(subti, tvb, offset);
col_append_fstr(pinfo->cinfo, COL_INFO,
" (Group=%s, Member=%s)",
tvb_get_string_enc(wmem_packet_scope(), tvb,
group_start, group_len, ENC_UTF_8|ENC_NA),
tvb_get_string_enc(wmem_packet_scope(), tvb,
member_start, member_len, ENC_UTF_8|ENC_NA));
return offset;
}
static int
dissect_kafka_sync_group_response(tvbuff_t *tvb, packet_info *pinfo, proto_tree *tree, int offset,
kafka_api_version_t api_version _U_)
{
offset = dissect_kafka_error(tvb, pinfo, tree, offset);
offset = dissect_kafka_bytes(tree, hf_kafka_member_assignment, tvb, pinfo, offset, NULL, NULL);
return offset;
}
static int
dissect_kafka_describe_groups_request_group_id(tvbuff_t *tvb, packet_info *pinfo, proto_tree *tree,
int offset, kafka_api_version_t api_version _U_)
{
offset = dissect_kafka_string(tree, hf_kafka_consumer_group, tvb, pinfo, offset, NULL, NULL);
return offset;
}
static int
dissect_kafka_describe_groups_request(tvbuff_t *tvb, packet_info *pinfo, proto_tree *tree, int offset,
kafka_api_version_t api_version)
{
offset = dissect_kafka_array(tree, tvb, pinfo, offset, api_version,
&dissect_kafka_describe_groups_request_group_id);
return offset;
}
static int
dissect_kafka_describe_groups_response_member(tvbuff_t *tvb, packet_info *pinfo, proto_tree *tree, int offset,
kafka_api_version_t api_version _U_)
{
proto_item *subti;
proto_tree *subtree;
int member_start, member_len;
subtree = proto_tree_add_subtree(tree, tvb, offset, -1, ett_kafka_group_member, &subti, "Member");
offset = dissect_kafka_string(subtree, hf_kafka_member_id, tvb, pinfo, offset,
&member_start, &member_len);
offset = dissect_kafka_string(subtree, hf_kafka_client_id, tvb, pinfo, offset, NULL, NULL);
offset = dissect_kafka_string(subtree, hf_kafka_client_host, tvb, pinfo, offset, NULL, NULL);
offset = dissect_kafka_bytes(subtree, hf_kafka_member_metadata, tvb, pinfo, offset, NULL, NULL);
offset = dissect_kafka_bytes(subtree, hf_kafka_member_assignment, tvb, pinfo, offset, NULL, NULL);
proto_item_set_end(subti, tvb, offset);
proto_item_append_text(subti, " (Member-ID=%s)",
tvb_get_string_enc(wmem_packet_scope(), tvb,
member_start, member_len, ENC_UTF_8|ENC_NA));
return offset;
}
static int
dissect_kafka_describe_groups_response_group(tvbuff_t *tvb, packet_info *pinfo, proto_tree *tree, int offset,
kafka_api_version_t api_version)
{
proto_item *subti, *subsubti;
proto_tree *subtree, *subsubtree;
int group_start, group_len;
subtree = proto_tree_add_subtree(tree, tvb, offset, -1, ett_kafka_group, &subti, "Group");
offset = dissect_kafka_error(tvb, pinfo, subtree, offset);
offset = dissect_kafka_string(subtree, hf_kafka_consumer_group, tvb, pinfo, offset,
&group_start, &group_len);
offset = dissect_kafka_string(subtree, hf_kafka_group_state, tvb, pinfo, offset, NULL, NULL);
offset = dissect_kafka_string(subtree, hf_kafka_protocol_type, tvb, pinfo, offset, NULL, NULL);
offset = dissect_kafka_string(subtree, hf_kafka_protocol_name, tvb, pinfo, offset, NULL, NULL);
subsubtree = proto_tree_add_subtree(subtree, tvb, offset, -1, ett_kafka_group_members,
&subsubti, "Members");
offset = dissect_kafka_array(subsubtree, tvb, pinfo, offset, api_version,
&dissect_kafka_describe_groups_response_member);
proto_item_set_end(subsubti, tvb, offset);
proto_item_set_end(subti, tvb, offset);
proto_item_append_text(subti, " (Group-ID=%s)",
tvb_get_string_enc(wmem_packet_scope(), tvb,
group_start, group_len, ENC_UTF_8|ENC_NA));
return offset;
}
static int
dissect_kafka_describe_groups_response(tvbuff_t *tvb, packet_info *pinfo, proto_tree *tree, int offset,
kafka_api_version_t api_version)
{
offset = dissect_kafka_array(tree, tvb, pinfo, offset, api_version,
&dissect_kafka_describe_groups_response_group);
return offset;
}
static int
dissect_kafka_list_groups_request(tvbuff_t *tvb _U_, packet_info *pinfo _U_, proto_tree *tree _U_, int offset,
kafka_api_version_t api_version _U_)
{
return offset;
}
static int
dissect_kafka_list_groups_response_group(tvbuff_t *tvb, packet_info *pinfo, proto_tree *tree, int offset,
kafka_api_version_t api_version _U_)
{
proto_item *subti;
proto_tree *subtree;
int group_start, group_len;
int protocol_type_start, protocol_type_len;
subtree = proto_tree_add_subtree(tree, tvb, offset, -1, ett_kafka_group, &subti, "Group");
offset = dissect_kafka_string(subtree, hf_kafka_consumer_group, tvb, pinfo, offset,
&group_start, &group_len);
offset = dissect_kafka_string(subtree, hf_kafka_protocol_type, tvb, pinfo, offset,
&protocol_type_start, &protocol_type_len);
proto_item_set_end(subti, tvb, offset);
proto_item_append_text(subti, " (Group-ID=%s, Protocol-Type=%s)",
tvb_get_string_enc(wmem_packet_scope(), tvb,
group_start, group_len, ENC_UTF_8|ENC_NA),
tvb_get_string_enc(wmem_packet_scope(), tvb,
protocol_type_start, protocol_type_len, ENC_UTF_8|ENC_NA));
return offset;
}
static int
dissect_kafka_list_groups_response(tvbuff_t *tvb, packet_info *pinfo, proto_tree *tree, int offset,
kafka_api_version_t api_version)
{
offset = dissect_kafka_error(tvb, pinfo, tree, offset);
offset = dissect_kafka_array(tree, tvb, pinfo, offset, api_version,
&dissect_kafka_list_groups_response_group);
return offset;
}
static int
dissect_kafka_sasl_handshake_request(tvbuff_t *tvb, packet_info *pinfo, proto_tree *tree, int offset,
kafka_api_version_t api_version _U_)
{
offset = dissect_kafka_string(tree, hf_kafka_sasl_mechanism, tvb, pinfo, offset, NULL, NULL);
return offset;
}
static int
dissect_kafka_sasl_handshake_response_enabled_mechanism(tvbuff_t *tvb, packet_info *pinfo, proto_tree *tree,
int offset, kafka_api_version_t api_version _U_)
{
offset = dissect_kafka_string(tree, hf_kafka_sasl_mechanism, tvb, pinfo, offset, NULL, NULL);
return offset;
}
static int
dissect_kafka_sasl_handshake_response(tvbuff_t *tvb, packet_info *pinfo, proto_tree *tree, int offset,
kafka_api_version_t api_version)
{
proto_item *subti;
proto_tree *subtree;
offset = dissect_kafka_error(tvb, pinfo, tree, offset);
subtree = proto_tree_add_subtree(tree, tvb, offset, -1,
ett_kafka_sasl_enabled_mechanisms,
&subti, "Enabled SASL Mechanisms");
offset = dissect_kafka_array(subtree, tvb, pinfo, offset, api_version,
&dissect_kafka_sasl_handshake_response_enabled_mechanism);
proto_item_set_end(subti, tvb, offset);
return offset;
}
static int
dissect_kafka_create_topics_request_replica(tvbuff_t *tvb, packet_info *pinfo _U_, proto_tree *tree,
int offset, kafka_api_version_t api_version _U_)
{
proto_tree_add_item(tree, hf_kafka_replica, tvb, offset, 4, ENC_BIG_ENDIAN);
offset += 4;
return offset;
}
static int
dissect_kafka_create_topics_request_replica_assignment(tvbuff_t *tvb, packet_info *pinfo, proto_tree *tree,
int offset, kafka_api_version_t api_version _U_)
{
proto_item *subti;
proto_tree *subtree;
kafka_partition_t partition;
subtree = proto_tree_add_subtree(tree, tvb, offset, -1,
ett_kafka_replica_assignment,
&subti, "Replica Assignment");
partition = (gint32) tvb_get_ntohl(tvb, offset);
proto_tree_add_item(subtree, hf_kafka_partition_id, tvb, offset, 4, ENC_BIG_ENDIAN);
offset += 4;
offset = dissect_kafka_array(subtree, tvb, pinfo, offset, api_version,
&dissect_kafka_create_topics_request_replica);
proto_item_set_end(subti, tvb, offset);
proto_item_append_text(subti, " (Partition-ID=%d)",
partition);
return offset;
}
static int
dissect_kafka_create_topics_request_config(tvbuff_t *tvb, packet_info *pinfo, proto_tree *tree,
int offset, kafka_api_version_t api_version _U_)
{
proto_item *subti;
proto_tree *subtree;
int key_start, key_len;
int val_start, val_len;
subtree = proto_tree_add_subtree(tree, tvb, offset, -1,
ett_kafka_config,
&subti, "Config");
offset = dissect_kafka_string(subtree, hf_kafka_config_key, tvb, pinfo, offset, &key_start, &key_len);
offset = dissect_kafka_string(subtree, hf_kafka_config_value, tvb, pinfo, offset, &val_start, &val_len);
proto_item_set_end(subti, tvb, offset);
proto_item_append_text(subti, " (Key=%s, Value=%s)",
tvb_get_string_enc(wmem_packet_scope(), tvb,
key_start, key_len, ENC_UTF_8|ENC_NA),
tvb_get_string_enc(wmem_packet_scope(), tvb,
val_start, val_len, ENC_UTF_8|ENC_NA));
return offset;
}
static int
dissect_kafka_create_topics_request_create_topic_request(tvbuff_t *tvb, packet_info *pinfo, proto_tree *tree,
int offset, kafka_api_version_t api_version)
{
proto_item *subti, *subsubti;
proto_tree *subtree, *subsubtree;
int topic_start, topic_len;
subtree = proto_tree_add_subtree(tree, tvb, offset, -1,
ett_kafka_topic,
&subti, "Create Topic Request");
offset = dissect_kafka_string(subtree, hf_kafka_topic_name, tvb, pinfo, offset, &topic_start, &topic_len);
proto_tree_add_item(subtree, hf_kafka_num_partitions, tvb, offset, 4, ENC_BIG_ENDIAN);
offset += 4;
proto_tree_add_item(subtree, hf_kafka_replication_factor, tvb, offset, 2, ENC_BIG_ENDIAN);
offset += 2;
subsubtree = proto_tree_add_subtree(subtree, tvb, offset, -1,
ett_kafka_replica_assignment,
&subsubti, "Replica Assignments");
offset = dissect_kafka_array(subsubtree, tvb, pinfo, offset, api_version,
&dissect_kafka_create_topics_request_replica_assignment);
proto_item_set_end(subsubti, tvb, offset);
subsubtree = proto_tree_add_subtree(subtree, tvb, offset, -1,
ett_kafka_config,
&subsubti, "Configs");
offset = dissect_kafka_array(subsubtree, tvb, pinfo, offset, api_version,
&dissect_kafka_create_topics_request_config);
proto_item_set_end(subsubti, tvb, offset);
proto_item_set_end(subti, tvb, offset);
proto_item_append_text(subti, " (Topic=%s)",
tvb_get_string_enc(wmem_packet_scope(), tvb,
topic_start, topic_len, ENC_UTF_8|ENC_NA));
return offset;
}
static int
dissect_kafka_create_topics_request(tvbuff_t *tvb, packet_info *pinfo, proto_tree *tree, int offset,
kafka_api_version_t api_version)
{
proto_item *subti;
proto_tree *subtree;
subtree = proto_tree_add_subtree(tree, tvb, offset, -1,
ett_kafka_topics,
&subti, "Create Topic Requests");
offset = dissect_kafka_array(subtree, tvb, pinfo, offset, api_version,
&dissect_kafka_create_topics_request_create_topic_request);
proto_item_set_end(subti, tvb, offset);
proto_tree_add_item(tree, hf_kafka_timeout, tvb, offset, 4, ENC_BIG_ENDIAN);
offset += 4;
return offset;
}
static int
dissect_kafka_create_topics_response_topic_error_code(tvbuff_t *tvb, packet_info *pinfo, proto_tree *tree,
int offset, kafka_api_version_t api_version _U_)
{
proto_item *subti;
proto_tree *subtree;
int topic_start, topic_len;
kafka_error_t error;
subtree = proto_tree_add_subtree(tree, tvb, offset, -1,
ett_kafka_topic,
&subti, "Topic Error Code");
offset = dissect_kafka_string(subtree, hf_kafka_topic_name, tvb, pinfo, offset, &topic_start, &topic_len);
offset = dissect_kafka_error_ret(tvb, pinfo, subtree, offset, &error);
proto_item_set_end(subti, tvb, offset);
proto_item_append_text(subti, " (Topic=%s, Error=%s)",
tvb_get_string_enc(wmem_packet_scope(), tvb,
topic_start, topic_len, ENC_UTF_8|ENC_NA),
kafka_error_to_str(error));
return offset;
}
static int
dissect_kafka_create_topics_response(tvbuff_t *tvb, packet_info *pinfo, proto_tree *tree, int offset,
kafka_api_version_t api_version)
{
proto_item *subti;
proto_tree *subtree;
subtree = proto_tree_add_subtree(tree, tvb, offset, -1,
ett_kafka_topics,
&subti, "Topic Error Codes");
offset = dissect_kafka_array(subtree, tvb, pinfo, offset, api_version,
&dissect_kafka_create_topics_response_topic_error_code);
proto_item_set_end(subti, tvb, offset);
return offset;
}
static int
dissect_kafka_delete_topics_request_topic(tvbuff_t *tvb, packet_info *pinfo, proto_tree *tree,
int offset, kafka_api_version_t api_version _U_)
{
offset = dissect_kafka_string(tree, hf_kafka_topic_name, tvb, pinfo, offset, NULL, NULL);
return offset;
}
static int
dissect_kafka_delete_topics_request(tvbuff_t *tvb, packet_info *pinfo, proto_tree *tree, int offset,
kafka_api_version_t api_version)
{
proto_item *subti;
proto_tree *subtree;
subtree = proto_tree_add_subtree(tree, tvb, offset, -1,
ett_kafka_topics,
&subti, "Topics");
offset = dissect_kafka_array(subtree, tvb, pinfo, offset, api_version,
&dissect_kafka_delete_topics_request_topic);
proto_item_set_end(subti, tvb, offset);
proto_tree_add_item(tree, hf_kafka_timeout, tvb, offset, 4, ENC_BIG_ENDIAN);
offset += 4;
return offset;
}
static int
dissect_kafka_delete_topics_response_topic_error_code(tvbuff_t *tvb, packet_info *pinfo, proto_tree *tree,
int offset, kafka_api_version_t api_version _U_)
{
proto_item *subti;
proto_tree *subtree;
int topic_start, topic_len;
kafka_error_t error;
subtree = proto_tree_add_subtree(tree, tvb, offset, -1,
ett_kafka_topic,
&subti, "Topic Error Code");
offset = dissect_kafka_string(subtree, hf_kafka_topic_name, tvb, pinfo, offset, &topic_start, &topic_len);
offset = dissect_kafka_error_ret(tvb, pinfo, subtree, offset, &error);
proto_item_set_end(subti, tvb, offset);
proto_item_append_text(subti, " (Topic=%s, Error=%s)",
tvb_get_string_enc(wmem_packet_scope(), tvb,
topic_start, topic_len, ENC_UTF_8|ENC_NA),
kafka_error_to_str(error));
return offset;
}
static int
dissect_kafka_delete_topics_response(tvbuff_t *tvb, packet_info *pinfo, proto_tree *tree, int offset,
kafka_api_version_t api_version)
{
proto_item *subti;
proto_tree *subtree;
subtree = proto_tree_add_subtree(tree, tvb, offset, -1,
ett_kafka_topics,
&subti, "Topic Error Codes");
offset = dissect_kafka_array(subtree, tvb, pinfo, offset, api_version,
&dissect_kafka_delete_topics_response_topic_error_code);
proto_item_set_end(subti, tvb, offset);
return offset;
}
static int
dissect_kafka(tvbuff_t *tvb, packet_info *pinfo, proto_tree *tree, void* data _U_)
{
proto_item *root_ti, *ti;
proto_tree *kafka_tree;
int offset = 0;
kafka_query_response_t *matcher = NULL;
conversation_t *conversation;
wmem_queue_t *match_queue;
col_set_str(pinfo->cinfo, COL_PROTOCOL, "Kafka");
col_clear(pinfo->cinfo, COL_INFO);
root_ti = proto_tree_add_item(tree, proto_kafka, tvb, 0, -1, ENC_NA);
kafka_tree = proto_item_add_subtree(root_ti, ett_kafka);
proto_tree_add_item(kafka_tree, hf_kafka_len, tvb, offset, 4, ENC_BIG_ENDIAN);
offset += 4;
conversation = find_or_create_conversation(pinfo);
match_queue = (wmem_queue_t *) conversation_get_proto_data(conversation, proto_kafka);
if (match_queue == NULL) {
match_queue = wmem_queue_new(wmem_file_scope());
conversation_add_proto_data(conversation, proto_kafka, match_queue);
}
if (PINFO_FD_VISITED(pinfo)) {
matcher = (kafka_query_response_t *) p_get_proto_data(wmem_file_scope(), pinfo, proto_kafka, 0);
}
if (value_is_in_range(current_kafka_tcp_range, pinfo->destport)) {
if (matcher == NULL) {
matcher = wmem_new(wmem_file_scope(), kafka_query_response_t);
matcher->api_key = tvb_get_ntohs(tvb, offset);
matcher->api_version = tvb_get_ntohs(tvb, offset+2);
matcher->request_frame = pinfo->num;
matcher->response_found = FALSE;
p_add_proto_data(wmem_file_scope(), pinfo, proto_kafka, 0, matcher);
if (matcher->api_key != KAFKA_PRODUCE) {
wmem_queue_push(match_queue, matcher);
}
}
col_add_fstr(pinfo->cinfo, COL_INFO, "Kafka %s v%d Request",
kafka_api_key_to_str(matcher->api_key),
matcher->api_version);
proto_item_append_text(root_ti, " (%s v%d Request)",
kafka_api_key_to_str(matcher->api_key),
matcher->api_version);
if (matcher->response_found) {
ti = proto_tree_add_uint(kafka_tree, hf_kafka_response_frame, tvb,
0, 0, matcher->response_frame);
PROTO_ITEM_SET_GENERATED(ti);
}
ti = proto_tree_add_item(kafka_tree, hf_kafka_request_api_key, tvb, offset, 2, ENC_BIG_ENDIAN);
offset += 2;
kafka_check_supported_api_key(pinfo, ti, matcher);
ti = proto_tree_add_item(kafka_tree, hf_kafka_request_api_version, tvb, offset, 2, ENC_BIG_ENDIAN);
offset += 2;
kafka_check_supported_api_version(pinfo, ti, matcher);
proto_tree_add_item(kafka_tree, hf_kafka_correlation_id, tvb, offset, 4, ENC_BIG_ENDIAN);
offset += 4;
offset = dissect_kafka_string(kafka_tree, hf_kafka_client_id, tvb, pinfo, offset, NULL, NULL);
switch (matcher->api_key) {
case KAFKA_PRODUCE:
if (tvb_get_ntohs(tvb, offset) != KAFKA_ACK_NOT_REQUIRED && !PINFO_FD_VISITED(pinfo)) {
wmem_queue_push(match_queue, matcher);
}
dissect_kafka_produce_request(tvb, pinfo, kafka_tree, offset, matcher->api_version);
break;
case KAFKA_FETCH:
dissect_kafka_fetch_request(tvb, pinfo, kafka_tree, offset, matcher->api_version);
break;
case KAFKA_OFFSETS:
dissect_kafka_offsets_request(tvb, pinfo, kafka_tree, offset, matcher->api_version);
break;
case KAFKA_METADATA:
dissect_kafka_metadata_request(tvb, pinfo, kafka_tree, offset, matcher->api_version);
break;
case KAFKA_LEADER_AND_ISR:
dissect_kafka_leader_and_isr_request(tvb, pinfo, kafka_tree, offset, matcher->api_version);
break;
case KAFKA_STOP_REPLICA:
dissect_kafka_stop_replica_request(tvb, pinfo, kafka_tree, offset, matcher->api_version);
break;
case KAFKA_UPDATE_METADATA:
dissect_kafka_update_metadata_request(tvb, pinfo, kafka_tree, offset, matcher->api_version);
break;
case KAFKA_CONTROLLED_SHUTDOWN:
dissect_kafka_controlled_shutdown_request(tvb, pinfo, kafka_tree, offset, matcher->api_version);
break;
case KAFKA_OFFSET_COMMIT:
dissect_kafka_offset_commit_request(tvb, pinfo, kafka_tree, offset, matcher->api_version);
break;
case KAFKA_OFFSET_FETCH:
dissect_kafka_offset_fetch_request(tvb, pinfo, kafka_tree, offset, matcher->api_version);
break;
case KAFKA_GROUP_COORDINATOR:
dissect_kafka_group_coordinator_request(tvb, pinfo, kafka_tree, offset, matcher->api_version);
break;
case KAFKA_JOIN_GROUP:
dissect_kafka_join_group_request(tvb, pinfo, kafka_tree, offset, matcher->api_version);
break;
case KAFKA_HEARTBEAT:
dissect_kafka_heartbeat_request(tvb, pinfo, kafka_tree, offset, matcher->api_version);
break;
case KAFKA_LEAVE_GROUP:
dissect_kafka_leave_group_request(tvb, pinfo, kafka_tree, offset, matcher->api_version);
break;
case KAFKA_SYNC_GROUP:
dissect_kafka_sync_group_request(tvb, pinfo, kafka_tree, offset, matcher->api_version);
break;
case KAFKA_DESCRIBE_GROUPS:
dissect_kafka_describe_groups_request(tvb, pinfo, kafka_tree, offset, matcher->api_version);
break;
case KAFKA_LIST_GROUPS:
dissect_kafka_list_groups_request(tvb, pinfo, kafka_tree, offset, matcher->api_version);
break;
case KAFKA_SASL_HANDSHAKE:
dissect_kafka_sasl_handshake_request(tvb, pinfo, kafka_tree, offset, matcher->api_version);
break;
case KAFKA_API_VERSIONS:
dissect_kafka_api_versions_request(tvb, pinfo, kafka_tree, offset, matcher->api_version);
break;
case KAFKA_CREATE_TOPICS:
dissect_kafka_create_topics_request(tvb, pinfo, kafka_tree, offset, matcher->api_version);
break;
case KAFKA_DELETE_TOPICS:
dissect_kafka_delete_topics_request(tvb, pinfo, kafka_tree, offset, matcher->api_version);
break;
}
}
else {
proto_tree_add_item(kafka_tree, hf_kafka_correlation_id, tvb, offset, 4, ENC_BIG_ENDIAN);
offset += 4;
if (matcher == NULL) {
if (wmem_queue_count(match_queue) > 0) {
matcher = (kafka_query_response_t *) wmem_queue_peek(match_queue);
}
if (matcher == NULL || matcher->request_frame >= pinfo->num) {
col_set_str(pinfo->cinfo, COL_INFO, "Kafka Response (Undecoded, Request Missing)");
expert_add_info(pinfo, root_ti, &ei_kafka_request_missing);
return tvb_captured_length(tvb);
}
wmem_queue_pop(match_queue);
matcher->response_frame = pinfo->num;
matcher->response_found = TRUE;
p_add_proto_data(wmem_file_scope(), pinfo, proto_kafka, 0, matcher);
}
col_add_fstr(pinfo->cinfo, COL_INFO, "Kafka %s v%d Response",
kafka_api_key_to_str(matcher->api_key),
matcher->api_version);
proto_item_append_text(root_ti, " (%s v%d Response)",
kafka_api_key_to_str(matcher->api_key),
matcher->api_version);
ti = proto_tree_add_uint(kafka_tree, hf_kafka_request_frame, tvb,
0, 0, matcher->request_frame);
PROTO_ITEM_SET_GENERATED(ti);
ti = proto_tree_add_int(kafka_tree, hf_kafka_response_api_key, tvb,
0, 0, matcher->api_key);
PROTO_ITEM_SET_GENERATED(ti);
kafka_check_supported_api_key(pinfo, ti, matcher);
ti = proto_tree_add_int(kafka_tree, hf_kafka_response_api_version, tvb,
0, 0, matcher->api_version);
PROTO_ITEM_SET_GENERATED(ti);
kafka_check_supported_api_version(pinfo, ti, matcher);
switch (matcher->api_key) {
case KAFKA_PRODUCE:
dissect_kafka_produce_response(tvb, pinfo, kafka_tree, offset, matcher->api_version);
break;
case KAFKA_FETCH:
dissect_kafka_fetch_response(tvb, pinfo, kafka_tree, offset, matcher->api_version);
break;
case KAFKA_OFFSETS:
dissect_kafka_offsets_response(tvb, pinfo, kafka_tree, offset, matcher->api_version);
break;
case KAFKA_METADATA:
dissect_kafka_metadata_response(tvb, pinfo, kafka_tree, offset, matcher->api_version);
break;
case KAFKA_LEADER_AND_ISR:
dissect_kafka_leader_and_isr_response(tvb, pinfo, kafka_tree, offset, matcher->api_version);
break;
case KAFKA_STOP_REPLICA:
dissect_kafka_stop_replica_response(tvb, pinfo, kafka_tree, offset, matcher->api_version);
break;
case KAFKA_UPDATE_METADATA:
dissect_kafka_update_metadata_response(tvb, pinfo, kafka_tree, offset, matcher->api_version);
break;
case KAFKA_CONTROLLED_SHUTDOWN:
dissect_kafka_controlled_shutdown_response(tvb, pinfo, kafka_tree, offset, matcher->api_version);
break;
case KAFKA_OFFSET_COMMIT:
dissect_kafka_offset_commit_response(tvb, pinfo, kafka_tree, offset, matcher->api_version);
break;
case KAFKA_OFFSET_FETCH:
dissect_kafka_offset_fetch_response(tvb, pinfo, kafka_tree, offset, matcher->api_version);
break;
case KAFKA_GROUP_COORDINATOR:
dissect_kafka_group_coordinator_response(tvb, pinfo, kafka_tree, offset, matcher->api_version);
break;
case KAFKA_JOIN_GROUP:
dissect_kafka_join_group_response(tvb, pinfo, kafka_tree, offset, matcher->api_version);
break;
case KAFKA_HEARTBEAT:
dissect_kafka_heartbeat_response(tvb, pinfo, kafka_tree, offset, matcher->api_version);
break;
case KAFKA_LEAVE_GROUP:
dissect_kafka_leave_group_response(tvb, pinfo, kafka_tree, offset, matcher->api_version);
break;
case KAFKA_SYNC_GROUP:
dissect_kafka_sync_group_response(tvb, pinfo, kafka_tree, offset, matcher->api_version);
break;
case KAFKA_DESCRIBE_GROUPS:
dissect_kafka_describe_groups_response(tvb, pinfo, kafka_tree, offset, matcher->api_version);
break;
case KAFKA_LIST_GROUPS:
dissect_kafka_list_groups_response(tvb, pinfo, kafka_tree, offset, matcher->api_version);
break;
case KAFKA_SASL_HANDSHAKE:
dissect_kafka_sasl_handshake_response(tvb, pinfo, kafka_tree, offset, matcher->api_version);
break;
case KAFKA_API_VERSIONS:
dissect_kafka_api_versions_response(tvb, pinfo, kafka_tree, offset, matcher->api_version);
break;
case KAFKA_CREATE_TOPICS:
dissect_kafka_create_topics_response(tvb, pinfo, kafka_tree, offset, matcher->api_version);
break;
case KAFKA_DELETE_TOPICS:
dissect_kafka_delete_topics_response(tvb, pinfo, kafka_tree, offset, matcher->api_version);
break;
}
}
return tvb_captured_length(tvb);
}
static int
dissect_kafka_tcp(tvbuff_t *tvb, packet_info *pinfo, proto_tree *tree,
void *data)
{
tcp_dissect_pdus(tvb, pinfo, tree, TRUE, 4,
get_kafka_pdu_len, dissect_kafka, data);
return tvb_captured_length(tvb);
}
static void
apply_kafka_prefs(void) {
current_kafka_tcp_range = prefs_get_range_value("kafka", "tcp.port");
}
static void
compute_kafka_api_names(void)
{
guint i;
guint len = array_length(kafka_apis);
for (i = 0; i < len; ++i) {
kafka_api_names[i].value = kafka_apis[i].api_key;
kafka_api_names[i].strptr = kafka_apis[i].name;
}
kafka_api_names[len].value = 0;
kafka_api_names[len].strptr = NULL;
}
void
proto_register_kafka(void)
{
static hf_register_info hf[] = {
{ &hf_kafka_len,
{ "Length", "kafka.len",
FT_INT32, BASE_DEC, 0, 0,
"The length of this Kafka packet.", HFILL }
},
{ &hf_kafka_offset,
{ "Offset", "kafka.offset",
FT_INT64, BASE_DEC, 0, 0,
NULL, HFILL }
},
{ &hf_kafka_offset_time,
{ "Time", "kafka.offset_time",
FT_INT64, BASE_DEC, 0, 0,
NULL, HFILL }
},
{ &hf_kafka_max_offsets,
{ "Max Offsets", "kafka.max_offsets",
FT_INT32, BASE_DEC, 0, 0,
NULL, HFILL }
},
{ &hf_kafka_metadata,
{ "Metadata", "kafka.metadata",
FT_STRING, BASE_NONE, 0, 0,
NULL, HFILL }
},
{ &hf_kafka_error,
{ "Error", "kafka.error",
FT_INT16, BASE_DEC, VALS(kafka_errors), 0,
NULL, HFILL }
},
{ &hf_kafka_request_api_key,
{ "API Key", "kafka.request_key",
FT_INT16, BASE_DEC, VALS(kafka_api_names), 0,
"Request API.", HFILL }
},
{ &hf_kafka_response_api_key,
{ "API Key", "kafka.response_key",
FT_INT16, BASE_DEC, VALS(kafka_api_names), 0,
"Response API.", HFILL }
},
{ &hf_kafka_request_api_version,
{ "API Version", "kafka.request.version",
FT_INT16, BASE_DEC, 0, 0,
"Request API Version.", HFILL }
},
{ &hf_kafka_response_api_version,
{ "API Version", "kafka.response.version",
FT_INT16, BASE_DEC, 0, 0,
"Response API Version.", HFILL }
},
{ &hf_kafka_correlation_id,
{ "Correlation ID", "kafka.correlation_id",
FT_INT32, BASE_DEC, 0, 0,
NULL, HFILL }
},
{ &hf_kafka_client_id,
{ "Client ID", "kafka.client_id",
FT_STRING, BASE_NONE, 0, 0,
"The ID of the sending client.", HFILL }
},
{ &hf_kafka_client_host,
{ "Client Host", "kafka.client_host",
FT_STRING, BASE_NONE, 0, 0,
NULL, HFILL }
},
{ &hf_kafka_string_len,
{ "String Length", "kafka.string_len",
FT_INT16, BASE_DEC, 0, 0,
"Generic length for kafka-encoded string.", HFILL }
},
{ &hf_kafka_bytes_len,
{ "Bytes Length", "kafka.bytes_len",
FT_INT32, BASE_DEC, 0, 0,
"Generic length for kafka-encoded bytes.", HFILL }
},
{ &hf_kafka_array_count,
{ "Array Count", "kafka.array_count",
FT_INT32, BASE_DEC, 0, 0,
NULL, HFILL }
},
{ &hf_kafka_required_acks,
{ "Required Acks", "kafka.required_acks",
FT_INT16, BASE_DEC, VALS(kafka_acks), 0,
NULL, HFILL }
},
{ &hf_kafka_timeout,
{ "Timeout", "kafka.timeout",
FT_INT32, BASE_DEC, 0, 0,
NULL, HFILL }
},
{ &hf_kafka_topic_name,
{ "Topic Name", "kafka.topic_name",
FT_STRING, BASE_NONE, 0, 0,
NULL, HFILL }
},
{ &hf_kafka_partition_id,
{ "Partition ID", "kafka.partition_id",
FT_INT32, BASE_DEC, 0, 0,
NULL, HFILL }
},
{ &hf_kafka_replica,
{ "Replica ID", "kafka.replica_id",
FT_INT32, BASE_DEC, 0, 0,
NULL, HFILL }
},
{ &hf_kafka_replication_factor,
{ "Replication Factor", "kafka.replication_factor",
FT_INT16, BASE_DEC, 0, 0,
NULL, HFILL }
},
{ &hf_kafka_isr,
{ "Caught-Up Replica ID", "kafka.isr_id",
FT_INT32, BASE_DEC, 0, 0,
NULL, HFILL }
},
{ &hf_kafka_partition_leader,
{ "Leader", "kafka.leader",
FT_INT32, BASE_DEC, 0, 0,
NULL, HFILL }
},
{ &hf_kafka_message_set_size,
{ "Message Set Size", "kafka.message_set_size",
FT_INT32, BASE_DEC, 0, 0,
NULL, HFILL }
},
{ &hf_kafka_message_size,
{ "Message Size", "kafka.message_size",
FT_INT32, BASE_DEC, 0, 0,
NULL, HFILL }
},
{ &hf_kafka_message_crc,
{ "CRC32", "kafka.message_crc",
FT_UINT32, BASE_HEX, 0, 0,
NULL, HFILL }
},
{ &hf_kafka_message_magic,
{ "Magic Byte", "kafka.message_magic",
FT_INT8, BASE_DEC, 0, 0,
NULL, HFILL }
},
{ &hf_kafka_message_codec,
{ "Compression Codec", "kafka.message_codec",
FT_UINT8, BASE_DEC, VALS(kafka_message_codecs), KAFKA_MESSAGE_CODEC_MASK,
NULL, HFILL }
},
{ &hf_kafka_message_timestamp_type,
{ "Timestamp Type", "kafka.message_timestamp_type",
FT_UINT8, BASE_DEC, VALS(kafka_message_timestamp_types), KAFKA_MESSAGE_TIMESTAMP_MASK,
NULL, HFILL }
},
{ &hf_kafka_message_timestamp,
{ "Timestamp", "kafka.message_timestamp",
FT_ABSOLUTE_TIME, ABSOLUTE_TIME_UTC, NULL, 0,
NULL, HFILL }
},
{ &hf_kafka_message_key,
{ "Key", "kafka.message_key",
FT_BYTES, BASE_NONE, 0, 0,
NULL, HFILL }
},
{ &hf_kafka_message_value,
{ "Value", "kafka.message_value",
FT_BYTES, BASE_NONE, 0, 0,
NULL, HFILL }
},
{ &hf_kafka_message_value_compressed,
{ "Compressed Value", "kafka.message_value_compressed",
FT_BYTES, BASE_NONE, 0, 0,
NULL, HFILL }
},
{ &hf_kafka_message_compression_reduction,
{ "Compression Reduction (compressed/uncompressed)", "kafka.message_compression_reduction",
FT_FLOAT, BASE_NONE, 0, 0,
NULL, HFILL }
},
{ &hf_kafka_consumer_group,
{ "Consumer Group", "kafka.consumer_group",
FT_STRING, BASE_NONE, 0, 0,
NULL, HFILL }
},
{ &hf_kafka_request_frame,
{ "Request Frame", "kafka.request_frame",
FT_FRAMENUM, BASE_NONE, FRAMENUM_TYPE(FT_FRAMENUM_REQUEST), 0,
NULL, HFILL }
},
{ &hf_kafka_broker_nodeid,
{ "Node ID", "kafka.node_id",
FT_INT32, BASE_DEC, 0, 0,
NULL, HFILL }
},
{ &hf_kafka_broker_host,
{ "Host", "kafka.host",
FT_STRING, BASE_NONE, 0, 0,
NULL, HFILL }
},
{ &hf_kafka_broker_port,
{ "Port", "kafka.port",
FT_INT32, BASE_DEC, 0, 0,
NULL, HFILL }
},
{ &hf_kafka_broker_rack,
{ "Rack", "kafka.rack",
FT_STRING, BASE_NONE, 0, 0,
NULL, HFILL }
},
{ &hf_kafka_broker_security_protocol_type,
{ "Security Protocol Type", "kafka.broker_security_protocol_type",
FT_INT16, BASE_DEC, VALS(kafka_security_protocol_types), 0,
NULL, HFILL }
},
{ &hf_kafka_cluster_id,
{ "Cluster ID", "kafka.cluster_id",
FT_STRING, BASE_NONE, 0, 0,
NULL, HFILL }
},
{ &hf_kafka_controller_id,
{ "Controller ID", "kafka.node_id",
FT_INT32, BASE_DEC, 0, 0,
NULL, HFILL }
},
{ &hf_kafka_controller_epoch,
{ "Controller Epoch", "kafka.controller_epoch",
FT_INT32, BASE_DEC, 0, 0,
NULL, HFILL }
},
{ &hf_kafka_delete_partitions,
{ "Delete Partitions", "kafka.delete_partitions",
FT_BOOLEAN, BASE_NONE, 0, 0,
NULL, HFILL }
},
{ &hf_kafka_group_leader_id,
{ "Leader ID", "kafka.group_leader_id",
FT_STRING, BASE_NONE, 0, 0,
NULL, HFILL }
},
{ &hf_kafka_leader_id,
{ "Leader ID", "kafka.leader_id",
FT_INT32, BASE_DEC, 0, 0,
NULL, HFILL }
},
{ &hf_kafka_leader_epoch,
{ "Leader Epoch", "kafka.leader_epoch",
FT_INT32, BASE_DEC, 0, 0,
NULL, HFILL }
},
{ &hf_kafka_is_internal,
{ "Is Internal", "kafka.is_internal",
FT_BOOLEAN, BASE_NONE, 0, 0,
NULL, HFILL }
},
{ &hf_kafka_min_bytes,
{ "Min Bytes", "kafka.min_bytes",
FT_INT32, BASE_DEC, 0, 0,
"The minimum number of bytes of messages that must be available"
" to give a response.",
HFILL }
},
{ &hf_kafka_max_bytes,
{ "Max Bytes", "kafka.max_bytes",
FT_INT32, BASE_DEC, 0, 0,
"The maximum bytes to include in the message set for this"
" partition. This helps bound the size of the response.",
HFILL }
},
{ &hf_kafka_max_wait_time,
{ "Max Wait Time", "kafka.max_wait_time",
FT_INT32, BASE_DEC, 0, 0,
"The maximum amount of time in milliseconds to block waiting if"
" insufficient data is available at the time the request is"
" issued.",
HFILL }
},
{ &hf_kafka_throttle_time,
{ "Throttle time", "kafka.throttle_time",
FT_INT32, BASE_DEC, 0, 0,
"Duration in milliseconds for which the request was throttled"
" due to quota violation."
" (Zero if the request did not violate any quota.)",
HFILL }
},
{ &hf_kafka_response_frame,
{ "Response Frame", "kafka.response_frame",
FT_FRAMENUM, BASE_NONE, FRAMENUM_TYPE(FT_FRAMENUM_RESPONSE), 0,
NULL, HFILL }
},
{ &hf_kafka_api_versions_api_key,
{ "API Key", "kafka.api_versions.api_key",
FT_INT16, BASE_DEC, VALS(kafka_api_names), 0,
"API Key.", HFILL }
},
{ &hf_kafka_api_versions_min_version,
{ "Min Version", "kafka.api_versions.min_version",
FT_INT16, BASE_DEC, 0, 0,
"Minimal version which supports api key.", HFILL }
},
{ &hf_kafka_api_versions_max_version,
{ "Max Version", "kafka.api_versions.max_version",
FT_INT16, BASE_DEC, 0, 0,
"Maximal version which supports api key.", HFILL }
},
{ &hf_kafka_session_timeout,
{ "Session Timeout", "kafka.session_timeout",
FT_INT32, BASE_DEC, 0, 0,
NULL, HFILL }
},
{ &hf_kafka_rebalance_timeout,
{ "Rebalance Timeout", "kafka.rebalance_timeout",
FT_INT32, BASE_DEC, 0, 0,
NULL, HFILL }
},
{ &hf_kafka_group_state,
{ "State", "kafka.group_state",
FT_STRING, BASE_NONE, 0, 0,
NULL, HFILL }
},
{ &hf_kafka_member_id,
{ "Consumer Group Member ID", "kafka.member_id",
FT_STRING, BASE_NONE, 0, 0,
NULL, HFILL }
},
{ &hf_kafka_protocol_type,
{ "Protocol Type", "kafka.protocol_type",
FT_STRING, BASE_NONE, 0, 0,
NULL, HFILL }
},
{ &hf_kafka_protocol_name,
{ "Protocol Name", "kafka.protocol_name",
FT_STRING, BASE_NONE, 0, 0,
NULL, HFILL }
},
{ &hf_kafka_protocol_metadata,
{ "Protocol Metadata", "kafka.protocol_metadata",
FT_BYTES, BASE_NONE, 0, 0,
NULL, HFILL }
},
{ &hf_kafka_member_metadata,
{ "Member Metadata", "kafka.member_metadata",
FT_BYTES, BASE_NONE, 0, 0,
NULL, HFILL }
},
{ &hf_kafka_generation_id,
{ "Generation ID", "kafka.generation_id",
FT_INT32, BASE_DEC, 0, 0,
NULL, HFILL }
},
{ &hf_kafka_member_assignment,
{ "Member Assignment", "kafka.member_assignment",
FT_BYTES, BASE_NONE, 0, 0,
NULL, HFILL }
},
{ &hf_kafka_sasl_mechanism,
{ "SASL Mechanism", "kafka.sasl_mechanism",
FT_STRING, BASE_NONE, 0, 0,
NULL, HFILL }
},
{ &hf_kafka_num_partitions,
{ "Number of Partitions", "kafka.num_partitions",
FT_INT32, BASE_DEC, 0, 0,
NULL, HFILL }
},
{ &hf_kafka_zk_version,
{ "Zookeeper Version", "kafka.zk_version",
FT_INT32, BASE_DEC, 0, 0,
NULL, HFILL }
},
{ &hf_kafka_config_key,
{ "Key", "kafka.config_key",
FT_STRING, BASE_NONE, 0, 0,
NULL, HFILL }
},
{ &hf_kafka_config_value,
{ "Key", "kafka.config_value",
FT_STRING, BASE_NONE, 0, 0,
NULL, HFILL }
},
{ &hf_kafka_commit_timestamp,
{ "Timestamp", "kafka.commit_timestamp",
FT_ABSOLUTE_TIME, ABSOLUTE_TIME_UTC, NULL, 0,
NULL, HFILL }
},
{ &hf_kafka_retention_time,
{ "Retention Time", "kafka.retention_time",
FT_INT64, BASE_DEC, 0, 0,
NULL, HFILL }
},
};
static int *ett[] = {
&ett_kafka,
&ett_kafka_message,
&ett_kafka_message_set,
&ett_kafka_isrs,
&ett_kafka_replicas,
&ett_kafka_broker,
&ett_kafka_brokers,
&ett_kafka_broker_end_point,
&ett_kafka_topics,
&ett_kafka_topic,
&ett_kafka_request_topic,
&ett_kafka_request_partition,
&ett_kafka_response_topic,
&ett_kafka_response_partition,
&ett_kafka_api_version,
&ett_kafka_group_protocols,
&ett_kafka_group_protocol,
&ett_kafka_group_members,
&ett_kafka_group_member,
&ett_kafka_group_assignments,
&ett_kafka_group_assignment,
&ett_kafka_group,
&ett_kafka_sasl_enabled_mechanisms,
&ett_kafka_replica_assignment,
&ett_kafka_configs,
&ett_kafka_config,
};
static ei_register_info ei[] = {
{ &ei_kafka_request_missing,
{ "kafka.request_missing", PI_UNDECODED, PI_WARN, "Request missing", EXPFILL }},
{ &ei_kafka_unknown_api_key,
{ "kafka.unknown_api_key", PI_UNDECODED, PI_WARN, "Unknown API key", EXPFILL }},
{ &ei_kafka_unsupported_api_version,
{ "kafka.unsupported_api_version", PI_UNDECODED, PI_WARN, "Unsupported API version", EXPFILL }},
{ &ei_kafka_message_decompress,
{ "kafka.decompress_failed", PI_UNDECODED, PI_WARN, "Failed to decompress message", EXPFILL }},
{ &ei_kafka_bad_string_length,
{ "kafka.bad_string_length", PI_MALFORMED, PI_WARN, "Invalid string length field", EXPFILL }},
{ &ei_kafka_bad_bytes_length,
{ "kafka.bad_bytes_length", PI_MALFORMED, PI_WARN, "Invalid byte length field", EXPFILL }},
};
module_t *kafka_module;
expert_module_t* expert_kafka;
proto_kafka = proto_register_protocol("Kafka", "Kafka", "kafka");
compute_kafka_api_names();
proto_register_field_array(proto_kafka, hf, array_length(hf));
proto_register_subtree_array(ett, array_length(ett));
expert_kafka = expert_register_protocol(proto_kafka);
expert_register_field_array(expert_kafka, ei, array_length(ei));
kafka_module = prefs_register_protocol(proto_kafka, apply_kafka_prefs);
prefs_register_bool_preference(kafka_module, "show_string_bytes_lengths",
"Show length for string and bytes fields in the protocol tree",
"",
&kafka_show_string_bytes_lengths);
}
void
proto_reg_handoff_kafka(void)
{
dissector_handle_t kafka_handle;
kafka_handle = create_dissector_handle(dissect_kafka_tcp, proto_kafka);
dissector_add_uint_range_with_preference("tcp.port", "", kafka_handle);
}
