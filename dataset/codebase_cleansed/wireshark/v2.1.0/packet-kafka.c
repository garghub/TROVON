static guint
get_kafka_pdu_len(packet_info *pinfo _U_, tvbuff_t *tvb, int offset, void *data _U_)
{
return 4 + tvb_get_ntohl(tvb, offset);
}
static int
dissect_kafka_array(proto_tree *tree, tvbuff_t *tvb, packet_info *pinfo, int offset,
int(*func)(tvbuff_t*, packet_info*, proto_tree*, int))
{
gint32 count, i;
count = (gint32) tvb_get_ntohl(tvb, offset);
proto_tree_add_item(tree, hf_kafka_array_count, tvb, offset, 4, ENC_BIG_ENDIAN);
offset += 4;
for (i=0; i<count; i++) {
offset = func(tvb, pinfo, tree, offset);
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
else if (len == -1) {
proto_tree_add_string(tree, hf_item, tvb, offset, 0, NULL);
}
else {
proto_tree_add_item(tree, hf_item, tvb, offset, len, ENC_NA|ENC_ASCII);
offset += len;
}
if (p_string_len != NULL) *p_string_len = len;
return offset;
}
static int
dissect_kafka_bytes(proto_tree *tree, int hf_item, tvbuff_t *tvb, packet_info *pinfo, int offset,
int *p_string_offset, int *p_string_len)
{
gint32 len;
proto_item *pi;
len = (gint32) tvb_get_ntohl(tvb, offset);
pi = proto_tree_add_item(tree, hf_kafka_bytes_len, tvb, offset, 4, ENC_BIG_ENDIAN);
offset += 4;
if (p_string_offset != NULL) *p_string_offset = offset;
if (len < -1) {
expert_add_info(pinfo, pi, &ei_kafka_bad_bytes_length);
}
else if (len == -1) {
proto_tree_add_bytes(tree, hf_item, tvb, offset, 0, NULL);
}
else {
proto_tree_add_item(tree, hf_item, tvb, offset, len, ENC_NA);
offset += len;
}
if (p_string_len != NULL) *p_string_len = len;
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
dissect_kafka_message(tvbuff_t *tvb, packet_info *pinfo, proto_tree *tree, int start_offset)
{
proto_item *ti, *decrypt_item;
proto_tree *subtree;
tvbuff_t *raw, *payload;
int offset = start_offset;
guint8 codec;
guint bytes_length = 0;
subtree = proto_tree_add_subtree(tree, tvb, offset, -1, ett_kafka_message, &ti, "Message");
proto_tree_add_item(subtree, hf_kafka_message_crc, tvb, offset, 4, ENC_BIG_ENDIAN);
offset += 4;
proto_tree_add_item(subtree, hf_kafka_message_magic, tvb, offset, 1, ENC_BIG_ENDIAN);
offset += 1;
proto_tree_add_item(subtree, hf_kafka_message_codec, tvb, offset, 1, ENC_BIG_ENDIAN);
codec = tvb_get_guint8(tvb, offset) & 0x07;
offset += 1;
offset = dissect_kafka_bytes(subtree, hf_kafka_message_key, tvb, pinfo, offset, NULL, &bytes_length);
switch (codec) {
case KAFKA_COMPRESSION_GZIP:
raw = kafka_get_bytes(tree, tvb, pinfo, offset);
offset += 4;
if (raw) {
payload = tvb_child_uncompress(tvb, raw, 0, tvb_captured_length(raw));
if (payload) {
add_new_data_source(pinfo, payload, "Uncompressed Message");
dissect_kafka_message_set(payload, pinfo, subtree, 0, FALSE);
} else {
decrypt_item = proto_tree_add_item(subtree, hf_kafka_message_value, raw, 0, -1, ENC_NA);
expert_add_info(pinfo, decrypt_item, &ei_kafka_message_decompress);
}
offset += tvb_captured_length(raw);
}
else {
proto_tree_add_bytes(subtree, hf_kafka_message_value, tvb, offset, 0, NULL);
}
col_append_fstr(pinfo->cinfo, COL_INFO, " [%u bytes GZIPd]", bytes_length);
proto_item_append_text(ti, " (%u bytes GZIPd)", bytes_length);
break;
case KAFKA_COMPRESSION_SNAPPY:
case KAFKA_COMPRESSION_NONE:
default:
offset = dissect_kafka_bytes(subtree, hf_kafka_message_value, tvb, pinfo, offset, NULL, &bytes_length);
col_append_fstr(pinfo->cinfo, COL_INFO, " [%u bytes]", bytes_length);
proto_item_append_text(ti, " (%u bytes)", bytes_length);
}
proto_item_set_len(ti, offset - start_offset);
return offset;
}
static int
dissect_kafka_message_set(tvbuff_t *tvb, packet_info *pinfo, proto_tree *tree, int start_offset, gboolean has_length_field)
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
dissect_kafka_partition_id(tvbuff_t *tvb, packet_info *pinfo _U_, proto_tree *tree, int offset)
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
dissect_kafka_offset(tvbuff_t *tvb, packet_info *pinfo _U_, proto_tree *tree, int offset)
{
proto_tree_add_item(tree, hf_kafka_offset, tvb, offset, 8, ENC_BIG_ENDIAN);
offset += 8;
return offset;
}
static int
dissect_kafka_offset_fetch_request_topic(tvbuff_t *tvb, packet_info *pinfo, proto_tree *tree, int start_offset)
{
proto_item *ti;
proto_tree *subtree;
int offset = start_offset;
guint32 count;
subtree = proto_tree_add_subtree(tree, tvb, offset, -1, ett_kafka_request_topic, &ti, "Offset Fetch Request Topic");
offset = dissect_kafka_string(subtree, hf_kafka_topic_name, tvb, pinfo, offset, NULL, NULL);
count = (gint32)tvb_get_ntohl(tvb, offset);
offset = dissect_kafka_array(subtree, tvb, pinfo, offset, &dissect_kafka_partition_id);
proto_item_set_len(ti, offset - start_offset);
proto_item_append_text(ti, " (%u partitions)", count);
return offset;
}
static int
dissect_kafka_offset_fetch_request(tvbuff_t *tvb, packet_info *pinfo, proto_tree *tree, int offset)
{
offset = dissect_kafka_string(tree, hf_kafka_consumer_group, tvb, pinfo, offset, NULL, NULL);
offset = dissect_kafka_array(tree, tvb, pinfo, offset, &dissect_kafka_offset_fetch_request_topic);
return offset;
}
static int dissect_kafka_error(tvbuff_t *tvb, packet_info *pinfo _U_, proto_tree *tree, int offset)
{
guint16 error = tvb_get_ntohs(tvb, offset);
proto_tree_add_item(tree, hf_kafka_error, tvb, offset, 2, ENC_BIG_ENDIAN);
if (error != 0) {
col_append_fstr(pinfo->cinfo, COL_INFO,
" [%s] ", val_to_str_const(error, kafka_errors, "Unknown"));
}
offset += 2;
return offset;
}
static int
dissect_kafka_offset_fetch_response_partition(tvbuff_t *tvb, packet_info *pinfo _U_, proto_tree *tree, int start_offset)
{
proto_item *ti;
proto_tree *subtree;
int offset = start_offset;
kafka_packet_values_t packet_values;
memset(&packet_values, 0, sizeof(packet_values));
subtree = proto_tree_add_subtree(tree, tvb, offset, -1, ett_kafka_request_partition, &ti, "Offset Fetch Response Partition");
offset = dissect_kafka_partition_id_get_value(tvb, pinfo, subtree, offset, &packet_values);
offset = dissect_kafka_offset(tvb, pinfo, subtree, offset);
offset = dissect_kafka_string(subtree, hf_kafka_metadata, tvb, pinfo, offset, NULL, NULL);
offset = dissect_kafka_error(tvb, pinfo, subtree, offset);
proto_item_append_text(ti, " (Partition-ID=%u, Offset=%" G_GINT64_MODIFIER "u)",
packet_values.partition_id, packet_values.offset);
proto_item_set_len(ti, offset - start_offset);
return offset;
}
static int
dissect_kafka_offset_fetch_response_topic(tvbuff_t *tvb, packet_info *pinfo, proto_tree *tree, int start_offset)
{
proto_item *ti;
proto_tree *subtree;
int offset = start_offset;
subtree = proto_tree_add_subtree(tree, tvb, offset, -1, ett_kafka_response_topic, &ti, "offset fetch response topic");
offset = dissect_kafka_string(subtree, hf_kafka_topic_name, tvb, pinfo, offset, NULL, NULL);
offset = dissect_kafka_array(subtree, tvb, pinfo, offset, &dissect_kafka_offset_fetch_response_partition);
proto_item_set_len(ti, offset - start_offset);
return offset;
}
static int
dissect_kafka_offset_fetch_response(tvbuff_t *tvb, packet_info *pinfo, proto_tree *tree, int offset)
{
return dissect_kafka_array(tree, tvb, pinfo, offset, &dissect_kafka_offset_fetch_response_topic);
}
static int
dissect_kafka_metadata_request_topic(tvbuff_t *tvb, packet_info *pinfo, proto_tree *tree, int offset)
{
return dissect_kafka_string(tree, hf_kafka_topic_name, tvb, pinfo, offset, NULL, NULL);
}
static int
dissect_kafka_metadata_request(tvbuff_t *tvb, packet_info *pinfo, proto_tree *tree, int offset)
{
return dissect_kafka_array(tree, tvb, pinfo, offset, &dissect_kafka_metadata_request_topic);
}
static int
dissect_kafka_metadata_broker(tvbuff_t *tvb, packet_info *pinfo, proto_tree *tree, int start_offset)
{
proto_item *ti;
proto_tree *subtree;
int offset = start_offset;
guint32 nodeid;
int host_start, host_len;
guint32 broker_port;
subtree = proto_tree_add_subtree(tree, tvb, offset, 14, ett_kafka_metadata_broker, &ti, "Broker");
nodeid = tvb_get_ntohl(tvb, offset);
proto_tree_add_item(subtree, hf_kafka_broker_nodeid, tvb, offset, 4, ENC_BIG_ENDIAN);
offset += 4;
offset = dissect_kafka_string(subtree, hf_kafka_broker_host, tvb, pinfo, offset, &host_start, &host_len);
broker_port = tvb_get_ntohl(tvb, offset);
proto_tree_add_item(subtree, hf_kafka_broker_port, tvb, offset, 4, ENC_BIG_ENDIAN);
offset += 4;
proto_item_append_text(ti, " (node %u: %s:%u)",
nodeid,
tvb_get_string_enc(wmem_packet_scope(), tvb,
host_start, host_len, ENC_UTF_8|ENC_NA),
broker_port);
proto_item_set_len(ti, offset - start_offset);
return offset;
}
static int
dissect_kafka_metadata_replica(tvbuff_t *tvb, packet_info *pinfo _U_, proto_tree *tree, int offset)
{
proto_tree_add_item(tree, hf_kafka_replica, tvb, offset, 4, ENC_BIG_ENDIAN);
return offset + 4;
}
static int
dissect_kafka_metadata_isr(tvbuff_t *tvb, packet_info *pinfo _U_, proto_tree *tree, int offset)
{
proto_tree_add_item(tree, hf_kafka_isr, tvb, offset, 4, ENC_BIG_ENDIAN);
return offset + 4;
}
static int
dissect_kafka_metadata_partition(tvbuff_t *tvb, packet_info *pinfo _U_, proto_tree *tree, int start_offset)
{
proto_item *ti, *subti;
proto_tree *subtree, *subsubtree;
int offset = start_offset;
int sub_start_offset;
subtree = proto_tree_add_subtree(tree, tvb, offset, -1, ett_kafka_response_partition, &ti, "Partition");
offset = dissect_kafka_error(tvb, pinfo, subtree, offset);
offset = dissect_kafka_partition_id(tvb, pinfo, subtree, offset);
proto_tree_add_item(subtree, hf_kafka_partition_leader, tvb, offset, 4, ENC_BIG_ENDIAN);
offset += 4;
sub_start_offset = offset;
subsubtree = proto_tree_add_subtree(subtree, tvb, offset, -1, ett_kafka_metadata_replicas, &subti, "Replicas");
offset = dissect_kafka_array(subsubtree, tvb, pinfo, offset, &dissect_kafka_metadata_replica);
proto_item_set_len(subti, offset - sub_start_offset);
sub_start_offset = offset;
subsubtree = proto_tree_add_subtree(subtree, tvb, offset, -1, ett_kafka_metadata_isr, &subti, "Caught-Up Replicas");
offset = dissect_kafka_array(subsubtree, tvb, pinfo, offset, &dissect_kafka_metadata_isr);
proto_item_set_len(subti, offset - sub_start_offset);
proto_item_set_len(ti, offset - start_offset);
return offset;
}
static int
dissect_kafka_metadata_topic(tvbuff_t *tvb, packet_info *pinfo, proto_tree *tree, int start_offset)
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
offset = dissect_kafka_array(subtree, tvb, pinfo, offset, &dissect_kafka_metadata_partition);
proto_item_set_len(ti, offset - start_offset);
return offset;
}
static int
dissect_kafka_metadata_response(tvbuff_t *tvb, packet_info *pinfo, proto_tree *tree, int start_offset)
{
proto_item *ti;
proto_tree *subtree;
int offset = start_offset;
subtree = proto_tree_add_subtree(tree, tvb, offset, -1, ett_kafka_metadata_brokers, &ti, "Broker Metadata");
offset = dissect_kafka_array(subtree, tvb, pinfo, offset, &dissect_kafka_metadata_broker);
proto_item_set_len(ti, offset - start_offset);
start_offset = offset;
subtree = proto_tree_add_subtree(tree, tvb, offset, -1, ett_kafka_metadata_topics, &ti, "Topic Metadata");
offset = dissect_kafka_array(subtree, tvb, pinfo, offset, &dissect_kafka_metadata_topic);
proto_item_set_len(ti, offset - start_offset);
return offset;
}
static int
dissect_kafka_fetch_request_partition(tvbuff_t *tvb, packet_info *pinfo _U_, proto_tree *tree, int offset)
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
dissect_kafka_fetch_request_topic(tvbuff_t *tvb, packet_info *pinfo, proto_tree *tree, int start_offset)
{
proto_item *ti;
proto_tree *subtree;
int offset = start_offset;
guint32 count;
int name_start, name_length;
subtree = proto_tree_add_subtree(tree, tvb, offset, -1, ett_kafka_request_topic, &ti, "Fetch Request Topic");
offset = dissect_kafka_string(subtree, hf_kafka_topic_name, tvb, pinfo, offset, &name_start, &name_length);
count = tvb_get_ntohl(tvb, offset);
offset = dissect_kafka_array(subtree, tvb, pinfo, offset, &dissect_kafka_fetch_request_partition);
proto_item_set_len(ti, offset - start_offset);
proto_item_append_text(ti, " (%u partitions)", count);
return offset;
}
static int
dissect_kafka_fetch_request(tvbuff_t *tvb, packet_info *pinfo, proto_tree *tree, int offset)
{
proto_tree_add_item(tree, hf_kafka_replica, tvb, offset, 4, ENC_BIG_ENDIAN);
offset += 4;
proto_tree_add_item(tree, hf_kafka_max_wait_time, tvb, offset, 4, ENC_BIG_ENDIAN);
offset += 4;
proto_tree_add_item(tree, hf_kafka_min_bytes, tvb, offset, 4, ENC_BIG_ENDIAN);
offset += 4;
offset = dissect_kafka_array(tree, tvb, pinfo, offset, &dissect_kafka_fetch_request_topic);
return offset;
}
static int
dissect_kafka_fetch_response_partition(tvbuff_t *tvb, packet_info *pinfo _U_, proto_tree *tree, int start_offset)
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
offset = dissect_kafka_message_set(tvb, pinfo, subtree, offset, TRUE);
proto_item_set_len(ti, offset - start_offset);
proto_item_append_text(ti, " (Partition-ID=%u, Offset=%" G_GINT64_MODIFIER "u)",
packet_values.partition_id, packet_values.offset);
return offset;
}
static int
dissect_kafka_fetch_response_topic(tvbuff_t *tvb, packet_info *pinfo, proto_tree *tree, int start_offset)
{
proto_item *ti;
proto_tree *subtree;
int offset = start_offset;
guint32 count;
subtree = proto_tree_add_subtree(tree, tvb, offset, -1, ett_kafka_response_topic, &ti, "Fetch Response Topic");
offset = dissect_kafka_string(subtree, hf_kafka_topic_name, tvb, pinfo, offset, NULL, NULL);
count = tvb_get_ntohl(tvb, offset);
offset = dissect_kafka_array(subtree, tvb, pinfo, offset, &dissect_kafka_fetch_response_partition);
proto_item_set_len(ti, offset - start_offset);
proto_item_append_text(ti, " (%u partitions)", count);
return offset;
}
static int
dissect_kafka_fetch_response(tvbuff_t *tvb, packet_info *pinfo, proto_tree *tree, int offset, guint16 api_version)
{
if (api_version > 0) {
proto_tree_add_item(tree, hf_kafka_throttle_time, tvb, offset, 4, ENC_BIG_ENDIAN);
offset += 4;
}
return dissect_kafka_array(tree, tvb, pinfo, offset, &dissect_kafka_fetch_response_topic);
}
static int
dissect_kafka_produce_request_partition(tvbuff_t *tvb, packet_info *pinfo _U_, proto_tree *tree, int offset)
{
proto_item *ti;
proto_tree *subtree;
kafka_packet_values_t packet_values;
memset(&packet_values, 0, sizeof(packet_values));
subtree = proto_tree_add_subtree(tree, tvb, offset, 14, ett_kafka_request_partition, &ti, "Produce Request Partition");
offset = dissect_kafka_partition_id_get_value(tvb, pinfo, subtree, offset, &packet_values);
offset = dissect_kafka_message_set(tvb, pinfo, subtree, offset, TRUE);
proto_item_append_text(ti, " (Partition-ID=%u)", packet_values.partition_id);
return offset;
}
static int
dissect_kafka_produce_request_topic(tvbuff_t *tvb, packet_info *pinfo, proto_tree *tree, int start_offset)
{
proto_item *ti;
proto_tree *subtree;
int offset = start_offset;
subtree = proto_tree_add_subtree(tree, tvb, offset, -1, ett_kafka_request_topic, &ti, "Produce Request Topic");
offset = dissect_kafka_string(subtree, hf_kafka_topic_name, tvb, pinfo, offset, NULL, NULL);
offset = dissect_kafka_array(subtree, tvb, pinfo, offset, &dissect_kafka_produce_request_partition);
proto_item_set_len(ti, offset - start_offset);
return offset;
}
static int
dissect_kafka_produce_request(tvbuff_t *tvb, packet_info *pinfo, proto_tree *tree, int offset)
{
proto_tree_add_item(tree, hf_kafka_required_acks, tvb, offset, 2, ENC_BIG_ENDIAN);
offset += 2;
proto_tree_add_item(tree, hf_kafka_timeout, tvb, offset, 4, ENC_BIG_ENDIAN);
offset += 4;
offset = dissect_kafka_array(tree, tvb, pinfo, offset, &dissect_kafka_produce_request_topic);
return offset;
}
static int
dissect_kafka_produce_response_partition(tvbuff_t *tvb, packet_info *pinfo _U_, proto_tree *tree, int offset)
{
proto_item *ti;
proto_tree *subtree;
kafka_packet_values_t packet_values;
memset(&packet_values, 0, sizeof(packet_values));
subtree = proto_tree_add_subtree(tree, tvb, offset, 14, ett_kafka_response_partition, &ti, "Produce Response Partition");
offset = dissect_kafka_partition_id_get_value(tvb, pinfo, subtree, offset, &packet_values);
offset = dissect_kafka_error(tvb, pinfo, subtree, offset);
offset = dissect_kafka_offset_get_value(tvb, pinfo, subtree, offset, &packet_values);
proto_item_append_text(ti, " (Partition-ID=%u, Offset=%" G_GINT64_MODIFIER "u)",
packet_values.partition_id, packet_values.offset);
return offset;
}
static int
dissect_kafka_produce_response_topic(tvbuff_t *tvb, packet_info *pinfo, proto_tree *tree, int start_offset)
{
proto_item *ti;
proto_tree *subtree;
int offset = start_offset;
subtree = proto_tree_add_subtree(tree, tvb, offset, -1, ett_kafka_response_topic, &ti, "Produce Response Topic");
offset = dissect_kafka_string(subtree, hf_kafka_topic_name, tvb, pinfo, offset, NULL, NULL);
offset = dissect_kafka_array(subtree, tvb, pinfo, offset, &dissect_kafka_produce_response_partition);
proto_item_set_len(ti, offset - start_offset);
return offset;
}
static int
dissect_kafka_produce_response(tvbuff_t *tvb, packet_info *pinfo, proto_tree *tree, int offset, guint16 api_version)
{
offset = dissect_kafka_array(tree, tvb, pinfo, offset, &dissect_kafka_produce_response_topic);
if (api_version > 0) {
proto_tree_add_item(tree, hf_kafka_throttle_time, tvb, offset, 4, ENC_BIG_ENDIAN);
offset += 4;
}
return offset;
}
static int
dissect_kafka_offset_request_partition(tvbuff_t *tvb, packet_info *pinfo _U_, proto_tree *tree, int offset)
{
proto_item *ti;
proto_tree *subtree;
subtree = proto_tree_add_subtree(tree, tvb, offset, 16, ett_kafka_request_partition, &ti, "Offset Request Partition");
offset = dissect_kafka_partition_id(tvb, pinfo, subtree, offset);
proto_tree_add_item(subtree, hf_kafka_offset_time, tvb, offset, 8, ENC_BIG_ENDIAN);
offset += 8;
proto_tree_add_item(subtree, hf_kafka_max_offsets, tvb, offset, 4, ENC_BIG_ENDIAN);
offset += 4;
return offset;
}
static int
dissect_kafka_offset_request_topic(tvbuff_t *tvb, packet_info *pinfo, proto_tree *tree, int start_offset)
{
proto_item *ti;
proto_tree *subtree;
int offset = start_offset;
subtree = proto_tree_add_subtree(tree, tvb, offset, -1, ett_kafka_request_topic, &ti, "Offset Request Topic");
offset = dissect_kafka_string(subtree, hf_kafka_topic_name, tvb, pinfo, offset, NULL, NULL);
offset = dissect_kafka_array(subtree, tvb, pinfo, offset, &dissect_kafka_offset_request_partition);
proto_item_set_len(ti, offset - start_offset);
return offset;
}
static int
dissect_kafka_offset_request(tvbuff_t *tvb, packet_info *pinfo, proto_tree *tree, int offset)
{
proto_tree_add_item(tree, hf_kafka_replica, tvb, offset, 4, ENC_BIG_ENDIAN);
offset += 4;
offset = dissect_kafka_array(tree, tvb, pinfo, offset, &dissect_kafka_offset_request_topic);
return offset;
}
static int
dissect_kafka_offset_response_partition(tvbuff_t *tvb, packet_info *pinfo _U_, proto_tree *tree, int start_offset)
{
proto_item *ti;
proto_tree *subtree;
int offset = start_offset;
subtree = proto_tree_add_subtree(tree, tvb, offset, -1, ett_kafka_response_partition, &ti, "Offset Response Partition");
offset = dissect_kafka_partition_id(tvb, pinfo, subtree, offset);
offset = dissect_kafka_error(tvb, pinfo, subtree, offset);
offset = dissect_kafka_array(subtree, tvb, pinfo, offset, &dissect_kafka_offset);
proto_item_set_len(ti, offset - start_offset);
return offset;
}
static int
dissect_kafka_offset_response_topic(tvbuff_t *tvb, packet_info *pinfo, proto_tree *tree, int start_offset)
{
proto_item *ti;
proto_tree *subtree;
int offset = start_offset;
subtree = proto_tree_add_subtree(tree, tvb, offset, -1, ett_kafka_response_topic, &ti, "Offset Response Topic");
offset = dissect_kafka_string(subtree, hf_kafka_topic_name, tvb, pinfo, offset, NULL, NULL);
offset = dissect_kafka_array(subtree, tvb, pinfo, offset, &dissect_kafka_offset_response_partition);
proto_item_set_len(ti, offset - start_offset);
return offset;
}
static int
dissect_kafka_offset_response(tvbuff_t *tvb, packet_info *pinfo, proto_tree *tree, int offset)
{
return dissect_kafka_array(tree, tvb, pinfo, offset, &dissect_kafka_offset_response_topic);
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
col_add_fstr(pinfo->cinfo, COL_INFO, "Kafka %s Request",
val_to_str_const(matcher->api_key, kafka_apis, "Unknown"));
proto_item_append_text(root_ti, " (%s Request)",
val_to_str_const(matcher->api_key, kafka_apis, "Unknown"));
if (matcher->response_found) {
ti = proto_tree_add_uint(kafka_tree, hf_kafka_response_frame, tvb,
0, 0, matcher->response_frame);
PROTO_ITEM_SET_GENERATED(ti);
}
proto_tree_add_item(kafka_tree, hf_kafka_request_api_key, tvb, offset, 2, ENC_BIG_ENDIAN);
offset += 2;
proto_tree_add_item(kafka_tree, hf_kafka_request_api_version, tvb, offset, 2, ENC_BIG_ENDIAN);
offset += 2;
proto_tree_add_item(kafka_tree, hf_kafka_correlation_id, tvb, offset, 4, ENC_BIG_ENDIAN);
offset += 4;
offset = dissect_kafka_string(kafka_tree, hf_kafka_client_id, tvb, pinfo, offset, NULL, NULL);
switch (matcher->api_key) {
case KAFKA_PRODUCE:
if (tvb_get_ntohs(tvb, offset) != 0 && !PINFO_FD_VISITED(pinfo)) {
wmem_queue_push(match_queue, matcher);
}
dissect_kafka_produce_request(tvb, pinfo, kafka_tree, offset);
break;
case KAFKA_OFFSET_FETCH:
dissect_kafka_offset_fetch_request(tvb, pinfo, kafka_tree, offset);
break;
case KAFKA_METADATA:
dissect_kafka_metadata_request(tvb, pinfo, kafka_tree, offset);
break;
case KAFKA_FETCH:
dissect_kafka_fetch_request(tvb, pinfo, kafka_tree, offset);
break;
case KAFKA_OFFSET:
dissect_kafka_offset_request(tvb, pinfo, kafka_tree, offset);
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
col_set_str(pinfo->cinfo, COL_INFO, "Kafka Response (Unknown API, Missing Request)");
return tvb_captured_length(tvb);
}
wmem_queue_pop(match_queue);
matcher->response_frame = pinfo->num;
matcher->response_found = TRUE;
p_add_proto_data(wmem_file_scope(), pinfo, proto_kafka, 0, matcher);
}
col_add_fstr(pinfo->cinfo, COL_INFO, "Kafka %s Response",
val_to_str_const(matcher->api_key, kafka_apis, "Unknown"));
proto_item_append_text(root_ti, " (%s Response)",
val_to_str_const(matcher->api_key, kafka_apis, "Unknown"));
ti = proto_tree_add_uint(kafka_tree, hf_kafka_request_frame, tvb,
0, 0, matcher->request_frame);
PROTO_ITEM_SET_GENERATED(ti);
ti = proto_tree_add_int(kafka_tree, hf_kafka_response_api_key, tvb,
0, 0, matcher->api_key);
PROTO_ITEM_SET_GENERATED(ti);
ti = proto_tree_add_int(kafka_tree, hf_kafka_response_api_version, tvb,
0, 0, matcher->api_version);
PROTO_ITEM_SET_GENERATED(ti);
switch (matcher->api_key) {
case KAFKA_PRODUCE:
dissect_kafka_produce_response(tvb, pinfo, kafka_tree, offset, matcher->api_version);
break;
case KAFKA_OFFSET_FETCH:
dissect_kafka_offset_fetch_response(tvb, pinfo, kafka_tree, offset);
break;
case KAFKA_METADATA:
dissect_kafka_metadata_response(tvb, pinfo, kafka_tree, offset);
break;
case KAFKA_FETCH:
dissect_kafka_fetch_response(tvb, pinfo, kafka_tree, offset, matcher->api_version);
break;
case KAFKA_OFFSET:
dissect_kafka_offset_response(tvb, pinfo, kafka_tree, offset);
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
void
proto_register_kafka(void)
{
module_t *kafka_module;
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
FT_INT16, BASE_DEC, VALS(kafka_apis), 0,
"Request API.", HFILL }
},
{ &hf_kafka_response_api_key,
{ "API Key", "kafka.response_key",
FT_INT16, BASE_DEC, VALS(kafka_apis), 0,
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
FT_INT16, BASE_DEC, 0, 0,
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
FT_UINT8, BASE_DEC, VALS(kafka_codecs), 0x03,
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
{ "Response Frame", "kafka.reponse_frame",
FT_FRAMENUM, BASE_NONE, FRAMENUM_TYPE(FT_FRAMENUM_RESPONSE), 0,
NULL, HFILL }
}
};
static gint *ett[] = {
&ett_kafka,
&ett_kafka_message,
&ett_kafka_message_set,
&ett_kafka_metadata_isr,
&ett_kafka_metadata_replicas,
&ett_kafka_metadata_broker,
&ett_kafka_metadata_brokers,
&ett_kafka_metadata_topics,
&ett_kafka_request_topic,
&ett_kafka_request_partition,
&ett_kafka_response_topic,
&ett_kafka_response_partition
};
static ei_register_info ei[] = {
{ &ei_kafka_message_decompress, { "kafka.decompress_failed", PI_UNDECODED, PI_WARN, "Failed to decompress message", EXPFILL }},
{ &ei_kafka_bad_string_length, { "kafka.bad_string_length", PI_MALFORMED, PI_WARN, "Invalid string length field", EXPFILL }},
{ &ei_kafka_bad_bytes_length, { "kafka.bad_bytes_length", PI_MALFORMED, PI_WARN, "Invalid byte length field", EXPFILL }},
};
expert_module_t* expert_kafka;
proto_kafka = proto_register_protocol("Kafka",
"Kafka", "kafka");
proto_register_field_array(proto_kafka, hf, array_length(hf));
proto_register_subtree_array(ett, array_length(ett));
expert_kafka = expert_register_protocol(proto_kafka);
expert_register_field_array(expert_kafka, ei, array_length(ei));
kafka_module = prefs_register_protocol(proto_kafka,
proto_reg_handoff_kafka);
range_convert_str(&new_kafka_tcp_range, TCP_DEFAULT_RANGE, 65535);
new_kafka_tcp_range = range_empty();
prefs_register_range_preference(kafka_module, "tcp.ports", "Broker TCP Ports",
"TCP Ports range",
&new_kafka_tcp_range, 65535);
prefs_register_obsolete_preference(kafka_module, "tcp.port");
}
void
proto_reg_handoff_kafka(void)
{
static gboolean initialized = FALSE;
static dissector_handle_t kafka_handle;
if (!initialized) {
kafka_handle = create_dissector_handle(dissect_kafka_tcp,
proto_kafka);
initialized = TRUE;
}
dissector_delete_uint_range("tcp.port", current_kafka_tcp_range, kafka_handle);
g_free(current_kafka_tcp_range);
current_kafka_tcp_range = range_copy(new_kafka_tcp_range);
dissector_add_uint_range("tcp.port", new_kafka_tcp_range, kafka_handle);
}
