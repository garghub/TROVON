static void
prepare_ldss_transfer_conv(ldss_broadcast_t *broadcast)
{
if (!find_conversation(broadcast->num, &broadcast->broadcaster->addr, &broadcast->broadcaster->addr,
PT_TCP, broadcast->broadcaster->port, broadcast->broadcaster->port, NO_ADDR2|NO_PORT2)) {
conversation_t *transfer_conv;
ldss_transfer_info_t *transfer_info;
transfer_info = wmem_new0(wmem_file_scope(), ldss_transfer_info_t);
transfer_info->broadcast = broadcast;
transfer_conv = conversation_new (broadcast->num, &broadcast->broadcaster->addr, &broadcast->broadcaster->addr,
PT_TCP, broadcast->broadcaster->port, broadcast->broadcaster->port, NO_ADDR2|NO_PORT2);
conversation_add_proto_data(transfer_conv, proto_ldss, transfer_info);
conversation_set_dissector(transfer_conv, ldss_tcp_handle);
}
}
static int
dissect_ldss_broadcast(tvbuff_t *tvb, packet_info *pinfo, proto_tree *tree)
{
guint16 messageID;
guint8 digest_type;
guint8 compression;
guint32 cookie;
guint8 *digest;
guint64 size;
guint64 offset;
guint32 targetTime;
guint16 port;
guint16 rate;
guint16 messageDetail = INFERRED_NONE;
proto_tree *ti, *ldss_tree;
const gchar *packet_type, *packet_detail;
messageID = tvb_get_ntohs (tvb, 0);
digest_type = tvb_get_guint8 (tvb, 2);
compression = tvb_get_guint8 (tvb, 3);
cookie = tvb_get_ntohl (tvb, 4);
digest = (guint8 *)tvb_memdup (wmem_file_scope(), tvb, 8, DIGEST_LEN);
size = tvb_get_ntoh64 (tvb, 40);
offset = tvb_get_ntoh64 (tvb, 48);
targetTime = tvb_get_ntohl (tvb, 56);
port = tvb_get_ntohs (tvb, 64);
rate = tvb_get_ntohs (tvb, 66);
packet_type = val_to_str_const(messageID, ldss_message_id_value, "unknown");
if (messageID == MESSAGE_ID_WILLSEND) {
if (cookie == 0) {
messageDetail = INFERRED_PEERSHUTDOWN;
}
else if (size == 0 && offset == 0) {
messageDetail = INFERRED_WANDOWNLOAD;
}
else if (size > 0) {
if (size == offset) {
messageDetail = INFERRED_OFFER;
}
else {
messageDetail = INFERRED_PROMISE;
}
}
}
else if (messageID == MESSAGE_ID_NEEDFILE) {
messageDetail = INFERRED_SEARCH;
}
packet_detail = val_to_str_const(messageDetail, ldss_inferred_info, "unknown");
col_add_fstr(pinfo->cinfo, COL_INFO, "LDSS Broadcast (%s%s)",
packet_type,
packet_detail);
ti = proto_tree_add_item(tree, proto_ldss,
tvb, 0, (tvb_captured_length(tvb) > 72) ? tvb_captured_length(tvb) : 72, ENC_NA);
ldss_tree = proto_item_add_subtree(ti, ett_ldss_broadcast);
proto_tree_add_item(ldss_tree, hf_ldss_message_id,
tvb, 0, 2, ENC_BIG_ENDIAN);
ti = proto_tree_add_uint(ldss_tree, hf_ldss_message_detail,
tvb, 0, 0, messageDetail);
PROTO_ITEM_SET_GENERATED(ti);
proto_tree_add_item(ldss_tree, hf_ldss_digest_type,
tvb, 2, 1, ENC_BIG_ENDIAN);
proto_tree_add_item(ldss_tree, hf_ldss_compression,
tvb, 3, 1, ENC_BIG_ENDIAN);
proto_tree_add_uint_format_value(ldss_tree, hf_ldss_cookie,
tvb, 4, 4, FALSE,
"0x%x%s",
cookie,
(cookie == 0)
? " - shutdown (promises from this peer are no longer valid)"
: "");
proto_tree_add_item(ldss_tree, hf_ldss_digest,
tvb, 8, DIGEST_LEN, ENC_NA);
proto_tree_add_item(ldss_tree, hf_ldss_size,
tvb, 40, 8, ENC_BIG_ENDIAN);
proto_tree_add_item(ldss_tree, hf_ldss_offset,
tvb, 48, 8, ENC_BIG_ENDIAN);
proto_tree_add_uint_format_value(ldss_tree, hf_ldss_target_time,
tvb, 56, 4, FALSE,
"%d:%02d:%02d",
(int)(targetTime / 3600),
(int)((targetTime / 60) % 60),
(int)(targetTime % 60));
proto_tree_add_item(ldss_tree, hf_ldss_reserved_1,
tvb, 60, 4, ENC_BIG_ENDIAN);
proto_tree_add_uint_format_value(ldss_tree, hf_ldss_port,
tvb, 64, 2, FALSE,
"%d%s",
port,
(messageID == MESSAGE_ID_WILLSEND &&
size > 0 &&
size == offset)
? " - file can be pulled at this TCP port"
: (messageID == MESSAGE_ID_NEEDFILE
? " - file can be pushed to this TCP port"
: ""));
proto_tree_add_uint_format_value(ldss_tree, hf_ldss_rate,
tvb, 66, 2, FALSE,
"%ld",
(rate > 0)
? (long)floor(exp(rate * G_LN2 / 2048))
: 0);
proto_tree_add_item(ldss_tree, hf_ldss_priority,
tvb, 68, 2, ENC_BIG_ENDIAN);
proto_tree_add_item(ldss_tree, hf_ldss_property_count,
tvb, 70, 2, ENC_BIG_ENDIAN);
if (tvb_reported_length(tvb) > 72) {
proto_tree_add_item(ldss_tree, hf_ldss_properties,
tvb, 72, tvb_captured_length(tvb) - 72, ENC_NA);
}
if ((messageDetail != INFERRED_PEERSHUTDOWN) &&
!PINFO_FD_VISITED(pinfo)) {
ldss_broadcast_t *data;
data = wmem_new0(wmem_file_scope(), ldss_broadcast_t);
data->num = pinfo->num;
data->ts = pinfo->abs_ts;
data->message_id = messageID;
data->message_detail = messageDetail;
data->port = port;
data->size = size;
data->offset = offset;
data->compression = compression;
data->file = wmem_new0(wmem_file_scope(), ldss_file_t);
data->file->digest = digest;
data->file->digest_type = digest_type;
data->broadcaster = wmem_new0(wmem_file_scope(), ldss_broadcaster_t);
copy_address_wmem(wmem_file_scope(), &data->broadcaster->addr, &pinfo->src);
data->broadcaster->port = port;
if (port > 0) {
prepare_ldss_transfer_conv(data);
}
}
return tvb_captured_length(tvb);
}
static int
dissect_ldss_transfer (tvbuff_t *tvb, packet_info *pinfo, proto_tree *tree, void* data)
{
conversation_t *transfer_conv;
ldss_transfer_info_t *transfer_info;
struct tcpinfo *transfer_tcpinfo;
proto_tree *ti, *line_tree = NULL, *ldss_tree = NULL;
nstime_t broadcast_response_time;
if (data == NULL)
return 0;
transfer_tcpinfo = (struct tcpinfo *)data;
col_set_str(pinfo->cinfo, COL_PROTOCOL, "LDSS");
transfer_conv = find_conversation (pinfo->num, &pinfo->src, &pinfo->dst,
PT_TCP, pinfo->srcport, pinfo->destport, 0);
DISSECTOR_ASSERT(transfer_conv);
transfer_info = (ldss_transfer_info_t *)conversation_get_proto_data(transfer_conv, proto_ldss);
DISSECTOR_ASSERT(transfer_info);
if (transfer_tcpinfo->seq == 1 &&
transfer_tcpinfo->lastackseq == 1 &&
transfer_info->broadcast->message_id == MESSAGE_ID_WILLSEND) {
guint offset = 0;
gboolean already_dissected = TRUE;
col_set_str(pinfo->cinfo, COL_INFO, "LDSS File Transfer (Requesting file - pull)");
if (transfer_info->req == NULL) {
already_dissected = FALSE;
transfer_info->req = wmem_new0(wmem_file_scope(), ldss_file_request_t);
transfer_info->req->file = wmem_new0(wmem_file_scope(), ldss_file_t);
}
ti = proto_tree_add_item(tree, proto_ldss,
tvb, 0, tvb_reported_length(tvb), ENC_NA);
ldss_tree = proto_item_add_subtree(ti, ett_ldss_transfer);
transfer_info->file = transfer_info->req->file;
while (tvb_offset_exists(tvb, offset)) {
gint next_offset;
const guint8 *line;
int linelen;
gboolean is_digest_line;
guint digest_type_len;
linelen = tvb_find_line_end(tvb, offset, -1, &next_offset, FALSE);
line = (guint8 *)tvb_memdup(wmem_packet_scope(), tvb, offset, linelen+1);
line_tree = proto_tree_add_subtree(ldss_tree, tvb, offset, linelen,
ett_ldss_transfer_req, NULL,
tvb_format_text(tvb, offset, next_offset-offset));
is_digest_line = FALSE;
if (strncmp(line,"md5:",4)==0) {
is_digest_line = TRUE;
digest_type_len = 4;
transfer_info->file->digest_type = DIGEST_TYPE_MD5;
}
else if (strncmp(line, "sha1:", 5)==0) {
is_digest_line = TRUE;
digest_type_len = 5;
transfer_info->file->digest_type = DIGEST_TYPE_SHA1;
}
else if (strncmp(line, "sha256:", 7)==0) {
is_digest_line = TRUE;
digest_type_len = 7;
transfer_info->file->digest_type = DIGEST_TYPE_SHA256;
}
else if (strncmp(line, "unknown:", 8)==0) {
is_digest_line = TRUE;
digest_type_len = 8;
transfer_info->file->digest_type = DIGEST_TYPE_UNKNOWN;
}
else if (strncmp(line, "Size: ", 6)==0) {
transfer_info->req->size = g_ascii_strtoull(line+6, NULL, 10);
ti = proto_tree_add_uint64(line_tree, hf_ldss_size,
tvb, offset+6, linelen-6, transfer_info->req->size);
PROTO_ITEM_SET_GENERATED(ti);
}
else if (strncmp(line, "Start: ", 7)==0) {
transfer_info->req->offset = g_ascii_strtoull(line+7, NULL, 10);
ti = proto_tree_add_uint64(line_tree, hf_ldss_offset,
tvb, offset+7, linelen-7, transfer_info->req->offset);
PROTO_ITEM_SET_GENERATED(ti);
}
else if (strncmp(line, "Compression: ", 13)==0) {
transfer_info->req->compression = (gint8)strtol(line+13, NULL, 10);
ti = proto_tree_add_uint(line_tree, hf_ldss_compression,
tvb, offset+13, linelen-13, transfer_info->req->compression);
PROTO_ITEM_SET_GENERATED(ti);
}
else {
proto_tree_add_expert(line_tree, pinfo, &ei_ldss_unrecognized_line, tvb, offset, linelen);
}
if (is_digest_line) {
proto_item *tii = NULL;
if (!already_dissected) {
GByteArray *digest_bytes;
digest_bytes = g_byte_array_new();
hex_str_to_bytes(
tvb_get_ptr(tvb, offset+digest_type_len, linelen-digest_type_len),
digest_bytes, FALSE);
if(digest_bytes->len >= DIGEST_LEN)
digest_bytes->len = (DIGEST_LEN-1);
transfer_info->file->digest = (guint8 *)wmem_alloc0(wmem_file_scope(), DIGEST_LEN);
memcpy(transfer_info->file->digest, digest_bytes->data, digest_bytes->len);
g_byte_array_free(digest_bytes, TRUE);
}
tii = proto_tree_add_uint(line_tree, hf_ldss_digest_type,
tvb, offset, digest_type_len, transfer_info->file->digest_type);
PROTO_ITEM_SET_GENERATED(tii);
tii = proto_tree_add_bytes(line_tree, hf_ldss_digest,
tvb, offset+digest_type_len, MIN(linelen-digest_type_len, DIGEST_LEN),
transfer_info->file->digest);
PROTO_ITEM_SET_GENERATED(tii);
}
offset = next_offset;
}
if (transfer_info->resp_num != 0) {
ti = proto_tree_add_uint(ldss_tree, hf_ldss_response_in,
tvb, 0, 0, transfer_info->resp_num);
PROTO_ITEM_SET_GENERATED(ti);
}
transfer_info->req->num = pinfo->num;
transfer_info->req->ts = pinfo->abs_ts;
}
else {
guint64 size;
guint64 offset;
guint8 compression;
if (transfer_info->broadcast->message_id == MESSAGE_ID_WILLSEND &&
transfer_info->req != NULL) {
transfer_info->file = transfer_info->req->file;
size = transfer_info->req->size;
offset = transfer_info->req->offset;
compression = transfer_info->req->compression;
}
else {
transfer_info->file = transfer_info->broadcast->file;
size = transfer_info->broadcast->size;
offset = transfer_info->broadcast->offset;
compression = transfer_info->broadcast->compression;
}
if (pinfo->can_desegment) {
if (size == 0 || tvb_captured_length(tvb) < size) {
pinfo->desegment_offset = 0;
pinfo->desegment_len = DESEGMENT_UNTIL_FIN;
return -1;
}
}
transfer_info->resp_num = pinfo->num;
transfer_info->resp_ts = pinfo->abs_ts;
col_add_fstr(pinfo->cinfo, COL_INFO, "LDSS File Transfer (Sending file - %s)",
transfer_info->broadcast->message_id == MESSAGE_ID_WILLSEND
? "pull"
: "push");
ti = proto_tree_add_item(tree, proto_ldss,
tvb, 0, tvb_reported_length(tvb), ENC_NA);
ldss_tree = proto_item_add_subtree(ti, ett_ldss_transfer);
proto_tree_add_bytes_format(ldss_tree, hf_ldss_file_data,
tvb, 0, tvb_captured_length(tvb), NULL,
compression == COMPRESSION_GZIP
? "Gzip compressed data: %d bytes"
: "File data: %d bytes",
tvb_captured_length(tvb));
#ifdef HAVE_ZLIB
if (compression == COMPRESSION_GZIP) {
tvbuff_t *uncomp_tvb;
uncomp_tvb = tvb_child_uncompress(tvb, tvb, 0, tvb_captured_length(tvb));
if (uncomp_tvb != NULL) {
add_new_data_source(pinfo, uncomp_tvb, "Uncompressed Data");
proto_tree_add_bytes_format_value(ldss_tree, hf_ldss_file_data,
uncomp_tvb, 0, tvb_captured_length(uncomp_tvb),
NULL, "Uncompressed data: %d bytes",
tvb_captured_length(uncomp_tvb));
}
}
#endif
ti = proto_tree_add_uint(ldss_tree, hf_ldss_digest_type,
tvb, 0, 0, transfer_info->file->digest_type);
PROTO_ITEM_SET_GENERATED(ti);
if (transfer_info->file->digest != NULL) {
ti = proto_tree_add_bytes(ldss_tree, hf_ldss_digest,
tvb, 0, DIGEST_LEN, transfer_info->file->digest);
}
PROTO_ITEM_SET_GENERATED(ti);
ti = proto_tree_add_uint64(ldss_tree, hf_ldss_size,
tvb, 0, 0, size);
PROTO_ITEM_SET_GENERATED(ti);
ti = proto_tree_add_uint64(ldss_tree, hf_ldss_offset,
tvb, 0, 0, offset);
PROTO_ITEM_SET_GENERATED(ti);
ti = proto_tree_add_uint(ldss_tree, hf_ldss_compression,
tvb, 0, 0, compression);
PROTO_ITEM_SET_GENERATED(ti);
if (transfer_info->broadcast->message_id == MESSAGE_ID_WILLSEND &&
transfer_info->req != NULL &&
transfer_info->req->num != 0) {
ti = proto_tree_add_uint(ldss_tree, hf_ldss_response_to,
tvb, 0, 0, transfer_info->req->num);
PROTO_ITEM_SET_GENERATED(ti);
}
}
if (transfer_info->broadcast->message_id == MESSAGE_ID_WILLSEND &&
transfer_info->req != NULL &&
transfer_info->resp_num != 0) {
nstime_t pull_response_time;
nstime_delta(&pull_response_time, &transfer_info->resp_ts,
&transfer_info->req->ts);
ti = proto_tree_add_time(ldss_tree, hf_ldss_transfer_response_time,
tvb, 0, 0, &pull_response_time);
PROTO_ITEM_SET_GENERATED(ti);
}
ti = proto_tree_add_uint(ldss_tree, hf_ldss_initiated_by,
tvb, 0, 0, transfer_info->broadcast->num);
PROTO_ITEM_SET_GENERATED(ti);
if (transfer_info->resp_num != 0) {
nstime_delta(&broadcast_response_time, &transfer_info->resp_ts,
&transfer_info->broadcast->ts);
ti = proto_tree_add_time(ldss_tree, hf_ldss_transfer_completed_in,
tvb, 0, 0, &broadcast_response_time);
PROTO_ITEM_SET_GENERATED(ti);
}
if (transfer_tcpinfo->seq == 1 &&
transfer_tcpinfo->lastackseq == 1) {
prepare_ldss_transfer_conv(transfer_info->broadcast);
}
return tvb_captured_length(tvb);
}
static gboolean
is_broadcast(address* addr)
{
static address broadcast_addr;
static const guint8 broadcast_addr_bytes[6] = {
0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF
};
set_address(&broadcast_addr, AT_ETHER, 6, broadcast_addr_bytes);
return addresses_equal(addr, &broadcast_addr);
}
static int
dissect_ldss (tvbuff_t *tvb, packet_info *pinfo, proto_tree *tree, void *data _U_)
{
if (is_broadcast(&pinfo->dl_dst)) {
col_set_str(pinfo->cinfo, COL_PROTOCOL, "LDSS");
return dissect_ldss_broadcast(tvb, pinfo, tree);
}
return 0;
}
void
proto_register_ldss (void) {
static hf_register_info hf[] = {
{ &hf_ldss_message_id,
{ "LDSS Message ID",
"ldss.message_id",
FT_UINT16, BASE_DEC, VALS(ldss_message_id_value), 0x0,
NULL, HFILL
}
},
{ &hf_ldss_message_detail,
{ "Inferred meaning",
"ldss.inferred_meaning",
FT_UINT16, BASE_DEC, VALS(ldss_inferred_value), 0x0,
"Inferred meaning of the packet", HFILL
}
},
{ &hf_ldss_digest_type,
{ "Digest Type",
"ldss.digest_type",
FT_UINT8, BASE_DEC, VALS(ldss_digest_type_value), 0x0,
NULL, HFILL
}
},
{ &hf_ldss_compression,
{ "Compressed Format",
"ldss.compression",
FT_UINT8, BASE_DEC, VALS(ldss_compression_value), 0x0,
NULL, HFILL
}
},
{ &hf_ldss_cookie,
{ "Cookie",
"ldss.cookie",
FT_UINT32, BASE_HEX, NULL, 0x0,
"Random value used for duplicate rejection", HFILL
}
},
{ &hf_ldss_digest,
{ "Digest",
"ldss.digest",
FT_BYTES, BASE_NONE, NULL, 0x0,
"Digest of file padded with 0x00", HFILL
}
},
{ &hf_ldss_size,
{ "Size",
"ldss.size",
FT_UINT64, BASE_DEC, NULL, 0x0,
"Size of complete file", HFILL
}
},
{ &hf_ldss_offset,
{ "Offset",
"ldss.offset",
FT_UINT64, BASE_DEC, NULL, 0x0,
"Size of currently available portion of file", HFILL
}
},
{ &hf_ldss_target_time,
{ "Target time (relative)",
"ldss.target_time",
FT_UINT32, BASE_DEC, NULL, 0x0,
"Time until file will be needed/available", HFILL
}
},
{ &hf_ldss_reserved_1,
{ "Reserved",
"ldss.reserved_1",
FT_UINT32, BASE_HEX, NULL, 0x0,
"Unused field - should be 0x00000000", HFILL
}
},
{ &hf_ldss_port,
{ "Port",
"ldss.port",
FT_UINT16, BASE_DEC, NULL, 0x0,
"TCP port for push (Need file) or pull (Will send)", HFILL
}
},
{ &hf_ldss_rate,
{ "Rate (B/s)",
"ldss.rate",
FT_UINT16, BASE_DEC, NULL, 0x0,
"Estimated current download rate", HFILL
}
},
{ &hf_ldss_priority,
{ "Priority",
"ldss.priority",
FT_UINT16, BASE_DEC, NULL, 0x0,
NULL, HFILL
}
},
{ &hf_ldss_property_count,
{ "Property Count",
"ldss.property_count",
FT_UINT16, BASE_DEC, NULL, 0x0,
NULL, HFILL
}
},
{ &hf_ldss_properties,
{ "Properties",
"ldss.properties",
FT_BYTES, BASE_NONE, NULL, 0x0,
NULL, HFILL
}
},
{ &hf_ldss_file_data,
{ "File data",
"ldss.file_data",
FT_BYTES, BASE_NONE, NULL, 0x0,
NULL, HFILL
}
},
{ &hf_ldss_response_in,
{ "Response In",
"ldss.response_in",
FT_FRAMENUM, BASE_NONE, NULL, 0x0,
"The response to this file pull request is in this frame", HFILL }
},
{ &hf_ldss_response_to,
{ "Request In",
"ldss.response_to",
FT_FRAMENUM, BASE_NONE, NULL, 0x0,
"This is a response to the file pull request in this frame", HFILL }
},
{ &hf_ldss_initiated_by,
{ "Initiated by",
"ldss.initiated_by",
FT_FRAMENUM, BASE_NONE, NULL, 0x0,
"The broadcast that initiated this file transfer", HFILL }
},
{ &hf_ldss_transfer_response_time,
{ "Transfer response time",
"ldss.transfer_response_time",
FT_RELATIVE_TIME, BASE_NONE, NULL, 0x0,
"The time between the request and the response for a pull transfer", HFILL }
},
{ &hf_ldss_transfer_completed_in,
{ "Transfer completed in",
"ldss.transfer_completed_in",
FT_RELATIVE_TIME, BASE_NONE, NULL, 0x0,
"The time between requesting the file and completion of the file transfer", HFILL }
}
};
static gint *ett[] = { &ett_ldss_broadcast, &ett_ldss_transfer, &ett_ldss_transfer_req };
static ei_register_info ei[] = {
{ &ei_ldss_unrecognized_line, { "ldss.unrecognized_line", PI_PROTOCOL, PI_WARN, "Unrecognized line ignored", EXPFILL }},
};
expert_module_t* expert_ldss;
proto_ldss = proto_register_protocol("Local Download Sharing Service", "LDSS", "ldss");
proto_register_field_array(proto_ldss, hf, array_length(hf));
proto_register_subtree_array(ett, array_length(ett));
expert_ldss = expert_register_protocol(proto_ldss);
expert_register_field_array(expert_ldss, ei, array_length(ei));
}
void
proto_reg_handoff_ldss (void)
{
ldss_udp_handle = create_dissector_handle(dissect_ldss, proto_ldss);
ldss_tcp_handle = create_dissector_handle(dissect_ldss_transfer, proto_ldss);
dissector_add_uint_with_preference("udp.port", UDP_PORT_LDSS, ldss_udp_handle);
}
