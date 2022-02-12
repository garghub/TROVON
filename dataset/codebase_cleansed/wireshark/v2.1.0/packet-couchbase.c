static guint
get_couchbase_pdu_len(packet_info *pinfo _U_, tvbuff_t *tvb,
int offset, void *data _U_)
{
guint32 bodylen;
bodylen = tvb_get_ntohl(tvb, offset + 8);
if ((bodylen + COUCHBASE_HEADER_LEN) > G_MAXUINT32) {
return G_MAXUINT32;
} else {
return bodylen + COUCHBASE_HEADER_LEN;
}
}
static gboolean
has_json_value(guint8 opcode)
{
switch (opcode) {
case PROTOCOL_BINARY_CMD_GET_CLUSTER_CONFIG:
case PROTOCOL_BINARY_CMD_SUBDOC_GET:
return TRUE;
default:
return FALSE;
}
}
static void
dissect_subdoc_spath_required_extras(tvbuff_t *tvb, proto_tree *extras_tree,
guint8 extlen, gboolean request, gint* offset,
guint16 *path_len, gboolean *illegal)
{
if (request) {
if (extlen >= 3) {
*path_len = tvb_get_ntohs(tvb, *offset);
proto_tree_add_item(extras_tree, hf_extras_pathlen, tvb, *offset, 2,
ENC_BIG_ENDIAN);
*offset += 2;
proto_tree_add_bitmask(extras_tree, tvb, *offset, hf_subdoc_flags,
ett_extras_flags, subdoc_flags, ENC_BIG_ENDIAN);
*offset += 1;
} else {
*illegal = TRUE;
}
}
}
static void
dissect_extras(tvbuff_t *tvb, packet_info *pinfo, proto_tree *tree,
gint offset, guint8 extlen, guint8 opcode, gboolean request,
guint16 *path_len)
{
proto_tree *extras_tree = NULL;
proto_item *extras_item = NULL;
gint save_offset = offset, ii;
guint bpos;
gboolean illegal = FALSE;
gboolean missing = FALSE;
gboolean first_flag;
guint32 flags;
proto_item *tf;
const gchar *tap_connect_flags[] = {
"BACKFILL", "DUMP", "LIST_VBUCKETS", "TAKEOVER_VBUCKETS",
"SUPPORT_ACK", "REQUEST_KEYS_ONLY", "CHECKPOINT", "REGISTERED_CLIENT"
};
*path_len = 0;
if (extlen) {
extras_item = proto_tree_add_item(tree, hf_extras, tvb, offset, extlen, ENC_NA);
extras_tree = proto_item_add_subtree(extras_item, ett_extras);
}
switch (opcode) {
case PROTOCOL_BINARY_CMD_GET:
case PROTOCOL_BINARY_CMD_GETQ:
case PROTOCOL_BINARY_CMD_GETK:
case PROTOCOL_BINARY_CMD_GETKQ:
if (extlen) {
if (request) {
illegal = TRUE;
} else {
proto_tree_add_item(extras_tree, hf_extras_flags, tvb, offset, 4, ENC_BIG_ENDIAN);
offset += 4;
}
} else if (!request) {
missing = TRUE;
}
break;
case PROTOCOL_BINARY_CMD_SET:
case PROTOCOL_BINARY_CMD_SETQ:
case PROTOCOL_BINARY_CMD_ADD:
case PROTOCOL_BINARY_CMD_ADDQ:
case PROTOCOL_BINARY_CMD_REPLACE:
case PROTOCOL_BINARY_CMD_REPLACEQ:
if (extlen) {
if (request) {
proto_tree_add_item(extras_tree, hf_extras_flags, tvb, offset, 4, ENC_BIG_ENDIAN);
offset += 4;
proto_tree_add_item(extras_tree, hf_extras_expiration, tvb, offset, 4, ENC_BIG_ENDIAN);
offset += 4;
} else {
illegal = TRUE;
}
} else if (request) {
missing = TRUE;
}
break;
case PROTOCOL_BINARY_CMD_INCREMENT:
case PROTOCOL_BINARY_CMD_INCREMENTQ:
case PROTOCOL_BINARY_CMD_DECREMENT:
case PROTOCOL_BINARY_CMD_DECREMENTQ:
if (extlen) {
if (request) {
proto_tree_add_item(extras_tree, hf_extras_delta, tvb, offset, 8, ENC_BIG_ENDIAN);
offset += 8;
proto_tree_add_item(extras_tree, hf_extras_initial, tvb, offset, 8, ENC_BIG_ENDIAN);
offset += 8;
proto_tree_add_item(extras_tree, hf_extras_expiration, tvb, offset, 4, ENC_BIG_ENDIAN);
offset += 4;
} else {
illegal = TRUE;
}
} else if (request) {
missing = TRUE;
}
break;
case PROTOCOL_BINARY_CMD_FLUSH:
case PROTOCOL_BINARY_CMD_FLUSHQ:
if (extlen) {
proto_tree_add_item(extras_tree, hf_extras_expiration, tvb, offset, 4, ENC_BIG_ENDIAN);
offset += 4;
}
break;
case PROTOCOL_BINARY_CMD_DELETE:
case PROTOCOL_BINARY_CMD_DELETEQ:
case PROTOCOL_BINARY_CMD_QUIT:
case PROTOCOL_BINARY_CMD_QUITQ:
case PROTOCOL_BINARY_CMD_VERSION:
case PROTOCOL_BINARY_CMD_APPEND:
case PROTOCOL_BINARY_CMD_APPENDQ:
case PROTOCOL_BINARY_CMD_PREPEND:
case PROTOCOL_BINARY_CMD_PREPENDQ:
case PROTOCOL_BINARY_CMD_STAT:
case PROTOCOL_BINARY_CMD_OBSERVE:
if (extlen) {
illegal = TRUE;
}
break;
case PROTOCOL_BINARY_CMD_GET_ALL_VB_SEQNOS:
if (extlen) {
if (request) {
proto_tree_add_item(extras_tree, hf_vbucket_states_state, tvb, offset, 4, ENC_BIG_ENDIAN);
offset += 4;
} else {
illegal = TRUE;
}
}
break;
case PROTOCOL_BINARY_CMD_TAP_CONNECT:
{
static const int * extra_flags[] = {
&hf_extras_flags_backfill,
&hf_extras_flags_dump,
&hf_extras_flags_list_vbuckets,
&hf_extras_flags_takeover_vbuckets,
&hf_extras_flags_support_ack,
&hf_extras_flags_request_keys_only,
&hf_extras_flags_checkpoint,
NULL
};
tf = proto_tree_add_bitmask(extras_tree, tvb, offset, hf_extras_flags, ett_extras_flags, extra_flags, ENC_BIG_ENDIAN);
flags = tvb_get_ntohl(tvb, offset);
first_flag = TRUE;
for (ii = 0; ii < 8; ii++) {
bpos = 1 << ii;
if (flags & bpos) {
if (first_flag) {
proto_item_append_text(tf, " (");
}
proto_item_append_text(tf, "%s%s",
first_flag ? "" : ", ",
tap_connect_flags[ii]);
first_flag = FALSE;
}
}
if (first_flag == TRUE) {
proto_item_append_text(tf, " <None>");
} else {
proto_item_append_text(tf, ")");
}
offset += 4;
}
break;
case PROTOCOL_BINARY_CMD_TAP_MUTATION:
case PROTOCOL_BINARY_CMD_TAP_DELETE:
case PROTOCOL_BINARY_CMD_TAP_FLUSH:
case PROTOCOL_BINARY_CMD_TAP_OPAQUE:
case PROTOCOL_BINARY_CMD_TAP_VBUCKET_SET:
case PROTOCOL_BINARY_CMD_TAP_CHECKPOINT_START:
case PROTOCOL_BINARY_CMD_TAP_CHECKPOINT_END:
break;
case PROTOCOL_BINARY_DCP_OPEN_CONNECTION:
if (extlen) {
if (request) {
static const int * extra_flags[] = {
&hf_extras_flags_dcp_connection_type,
NULL
};
proto_tree_add_item(extras_tree, hf_extras_seqno, tvb, offset, 4, ENC_BIG_ENDIAN);
offset += 4;
proto_tree_add_bitmask(extras_tree, tvb, offset, hf_extras_flags, ett_extras_flags, extra_flags, ENC_BIG_ENDIAN);
offset += 4;
} else {
illegal = TRUE;
}
} else if (request) {
missing = TRUE;
}
break;
case PROTOCOL_BINARY_DCP_ADD_STREAM:
if (extlen) {
if (request) {
static const int * extra_flags[] = {
&hf_extras_flags_dcp_add_stream_takeover,
&hf_extras_flags_dcp_add_stream_diskonly,
&hf_extras_flags_dcp_add_stream_latest,
NULL
};
proto_tree_add_bitmask(extras_tree, tvb, offset, hf_extras_flags, ett_extras_flags, extra_flags, ENC_BIG_ENDIAN);
offset += 4;
} else {
proto_tree_add_item(extras_tree, hf_extras_opaque, tvb, offset, 4, ENC_BIG_ENDIAN);
offset += 4;
}
} else {
missing = TRUE;
}
break;
case PROTOCOL_BINARY_DCP_STREAM_REQUEST:
if (extlen) {
if (request) {
static const int * extra_flags[] = {
NULL
};
proto_tree_add_bitmask(extras_tree, tvb, offset, hf_extras_flags, ett_extras_flags, extra_flags, ENC_BIG_ENDIAN);
offset += 4;
proto_tree_add_item(extras_tree, hf_extras_reserved, tvb, offset, 4, ENC_BIG_ENDIAN);
offset += 4;
proto_tree_add_item(extras_tree, hf_extras_start_seqno, tvb, offset, 8, ENC_BIG_ENDIAN);
offset += 8;
proto_tree_add_item(extras_tree, hf_extras_end_seqno, tvb, offset, 8, ENC_BIG_ENDIAN);
offset += 8;
proto_tree_add_item(extras_tree, hf_extras_vbucket_uuid, tvb, offset, 8, ENC_BIG_ENDIAN);
offset += 8;
proto_tree_add_item(extras_tree, hf_extras_snap_start_seqno, tvb, offset, 8, ENC_BIG_ENDIAN);
offset += 8;
proto_tree_add_item(extras_tree, hf_extras_snap_end_seqno, tvb, offset, 8, ENC_BIG_ENDIAN);
offset += 8;
}
} else if (request) {
missing = TRUE;
}
break;
case PROTOCOL_BINARY_DCP_SNAPSHOT_MARKER:
if (extlen) {
if (request) {
static const int * extra_flags[] = {
&hf_extras_flags_dcp_snapshot_marker_memory,
&hf_extras_flags_dcp_snapshot_marker_disk,
&hf_extras_flags_dcp_snapshot_marker_chk,
&hf_extras_flags_dcp_snapshot_marker_ack,
NULL
};
proto_tree_add_item(extras_tree, hf_extras_start_seqno, tvb, offset, 8, ENC_BIG_ENDIAN);
offset += 8;
proto_tree_add_item(extras_tree, hf_extras_end_seqno, tvb, offset, 8, ENC_BIG_ENDIAN);
offset += 8;
proto_tree_add_bitmask(extras_tree, tvb, offset, hf_extras_flags, ett_extras_flags, extra_flags, ENC_BIG_ENDIAN);
offset += 4;
} else {
illegal = TRUE;
}
} else if (request) {
missing = TRUE;
}
break;
case PROTOCOL_BINARY_DCP_MUTATION:
if (extlen) {
if (request) {
static const int * extra_flags[] = {
NULL
};
proto_tree_add_item(extras_tree, hf_extras_by_seqno, tvb, offset, 8, ENC_BIG_ENDIAN);
offset += 8;
proto_tree_add_item(extras_tree, hf_extras_rev_seqno, tvb, offset, 8, ENC_BIG_ENDIAN);
offset += 8;
proto_tree_add_bitmask(extras_tree, tvb, offset, hf_extras_flags, ett_extras_flags, extra_flags, ENC_BIG_ENDIAN);
offset += 4;
proto_tree_add_item(extras_tree, hf_extras_expiration, tvb, offset, 4, ENC_BIG_ENDIAN);
offset += 4;
proto_tree_add_item(extras_tree, hf_extras_lock_time, tvb, offset, 4, ENC_BIG_ENDIAN);
offset += 4;
proto_tree_add_item(extras_tree, hf_extras_nmeta, tvb, offset, 2, ENC_BIG_ENDIAN);
offset += 2;
proto_tree_add_item(extras_tree, hf_extras_nru, tvb, offset, 1, ENC_BIG_ENDIAN);
offset += 1;
} else {
illegal = TRUE;
}
} else if (request) {
missing = TRUE;
}
break;
case PROTOCOL_BINARY_DCP_DELETION:
case PROTOCOL_BINARY_DCP_EXPIRATION:
case PROTOCOL_BINARY_DCP_FLUSH:
if (extlen) {
if (request) {
proto_tree_add_item(extras_tree, hf_extras_by_seqno, tvb, offset, 8, ENC_BIG_ENDIAN);
offset += 8;
proto_tree_add_item(extras_tree, hf_extras_rev_seqno, tvb, offset, 8, ENC_BIG_ENDIAN);
offset += 8;
proto_tree_add_item(extras_tree, hf_extras_nmeta, tvb, offset, 2, ENC_BIG_ENDIAN);
offset += 2;
} else {
illegal = TRUE;
}
} else if (request) {
missing = TRUE;
}
break;
case PROTOCOL_BINARY_DCP_BUFFER_ACKNOWLEDGEMENT:
if (extlen) {
if (request) {
proto_tree_add_item(extras_tree, hf_extras_bytes_to_ack, tvb, offset, 4, ENC_BIG_ENDIAN);
offset += 4;
} else {
illegal = TRUE;
}
} else if (request) {
missing = TRUE;
}
break;
case PROTOCOL_BINARY_CMD_SUBDOC_GET:
case PROTOCOL_BINARY_CMD_SUBDOC_EXISTS:
dissect_subdoc_spath_required_extras(tvb, extras_tree, extlen, request,
&offset, path_len, &illegal);
break;
case PROTOCOL_BINARY_CMD_SUBDOC_DICT_ADD:
case PROTOCOL_BINARY_CMD_SUBDOC_DICT_UPSERT:
case PROTOCOL_BINARY_CMD_SUBDOC_DELETE:
case PROTOCOL_BINARY_CMD_SUBDOC_REPLACE:
case PROTOCOL_BINARY_CMD_SUBDOC_ARRAY_PUSH_LAST:
case PROTOCOL_BINARY_CMD_SUBDOC_ARRAY_PUSH_FIRST:
case PROTOCOL_BINARY_CMD_SUBDOC_ARRAY_INSERT:
case PROTOCOL_BINARY_CMD_SUBDOC_ARRAY_ADD_UNIQUE:
case PROTOCOL_BINARY_CMD_SUBDOC_COUNTER:
dissect_subdoc_spath_required_extras(tvb, extras_tree, extlen, request,
&offset, path_len, &illegal);
if (request) {
if (extlen == 7) {
proto_tree_add_item(extras_tree, hf_extras_expiration, tvb, offset, 4, ENC_BIG_ENDIAN);
offset += 4;
} else if (extlen != 3) {
illegal = TRUE;
}
}
break;
case PROTOCOL_BINARY_CMD_SUBDOC_MULTI_LOOKUP:
if (request) {
if (extlen) {
illegal = TRUE;
}
}
break;
default:
if (extlen) {
proto_tree_add_item(extras_tree, hf_extras_unknown, tvb, offset, extlen, ENC_NA);
offset += extlen;
}
break;
}
if (illegal) {
proto_tree_add_expert_format(extras_tree, pinfo, &ef_warn_shall_not_have_extras, tvb, offset, 0,
"%s %s should not have extras",
val_to_str_ext(opcode, &opcode_vals_ext, "Opcode 0x%x"),
request ? "Request" : "Response");
offset += extlen;
} else if (missing) {
proto_tree_add_expert_format(tree, pinfo, &ef_warn_must_have_extras, tvb, offset, 0,
"%s %s must have Extras",
val_to_str_ext(opcode, &opcode_vals_ext, "Opcode Ox%x"),
request ? "Request" : "Response");
}
if ((offset - save_offset) != extlen) {
expert_add_info_format(pinfo, extras_item, &ef_warn_illegal_extras_length,
"Illegal Extras length, should be %d", offset - save_offset);
}
}
static void
dissect_key(tvbuff_t *tvb, packet_info *pinfo, proto_tree *tree,
gint offset, int keylen, guint8 opcode, gboolean request)
{
proto_item *ti = NULL;
gboolean illegal = FALSE;
gboolean missing = FALSE;
if (keylen) {
ti = proto_tree_add_item(tree, hf_key, tvb, offset, keylen, ENC_ASCII | ENC_NA);
offset += keylen;
}
if (keylen) {
switch (opcode) {
case PROTOCOL_BINARY_CMD_QUIT:
case PROTOCOL_BINARY_CMD_QUITQ:
case PROTOCOL_BINARY_CMD_NOOP:
case PROTOCOL_BINARY_CMD_VERSION:
case PROTOCOL_BINARY_DCP_FAILOVER_LOG_REQUEST:
case PROTOCOL_BINARY_DCP_BUFFER_ACKNOWLEDGEMENT:
case PROTOCOL_BINARY_CMD_GET_ALL_VB_SEQNOS:
illegal = TRUE;
break;
case PROTOCOL_BINARY_CMD_SET:
case PROTOCOL_BINARY_CMD_ADD:
case PROTOCOL_BINARY_CMD_REPLACE:
case PROTOCOL_BINARY_CMD_DELETE:
case PROTOCOL_BINARY_CMD_SETQ:
case PROTOCOL_BINARY_CMD_ADDQ:
case PROTOCOL_BINARY_CMD_REPLACEQ:
case PROTOCOL_BINARY_CMD_DELETEQ:
case PROTOCOL_BINARY_CMD_FLUSH:
case PROTOCOL_BINARY_CMD_APPEND:
case PROTOCOL_BINARY_CMD_PREPEND:
case PROTOCOL_BINARY_CMD_FLUSHQ:
case PROTOCOL_BINARY_CMD_APPENDQ:
case PROTOCOL_BINARY_CMD_PREPENDQ:
if (!request) {
illegal = TRUE;
}
break;
case PROTOCOL_BINARY_DCP_ADD_STREAM:
case PROTOCOL_BINARY_DCP_CLOSE_STREAM:
case PROTOCOL_BINARY_DCP_STREAM_END:
case PROTOCOL_BINARY_DCP_SNAPSHOT_MARKER:
case PROTOCOL_BINARY_DCP_FLUSH:
case PROTOCOL_BINARY_DCP_SET_VBUCKET_STATE:
if (request) {
illegal = TRUE;
}
break;
}
} else {
switch (opcode) {
case PROTOCOL_BINARY_CMD_GET:
case PROTOCOL_BINARY_CMD_GETQ:
case PROTOCOL_BINARY_CMD_GETK:
case PROTOCOL_BINARY_CMD_GETKQ:
case PROTOCOL_BINARY_CMD_SET:
case PROTOCOL_BINARY_CMD_ADD:
case PROTOCOL_BINARY_CMD_REPLACE:
case PROTOCOL_BINARY_CMD_DELETE:
case PROTOCOL_BINARY_CMD_SETQ:
case PROTOCOL_BINARY_CMD_ADDQ:
case PROTOCOL_BINARY_CMD_REPLACEQ:
case PROTOCOL_BINARY_CMD_DELETEQ:
case PROTOCOL_BINARY_CMD_INCREMENT:
case PROTOCOL_BINARY_CMD_DECREMENT:
case PROTOCOL_BINARY_CMD_INCREMENTQ:
case PROTOCOL_BINARY_CMD_DECREMENTQ:
case PROTOCOL_BINARY_DCP_OPEN_CONNECTION:
case PROTOCOL_BINARY_DCP_MUTATION:
case PROTOCOL_BINARY_DCP_DELETION:
case PROTOCOL_BINARY_DCP_EXPIRATION:
if (request) {
missing = TRUE;
}
break;
}
}
if (illegal) {
expert_add_info_format(pinfo, ti, &ef_warn_shall_not_have_key, "%s %s shall not have Key",
val_to_str_ext(opcode, &opcode_vals_ext, "Opcode 0x%x"),
request ? "Request" : "Response");
} else if (missing) {
proto_tree_add_expert_format(tree, pinfo, &ef_warn_must_have_key, tvb, offset, 0,
"%s %s must have Key",
val_to_str_ext(opcode, &opcode_vals_ext, "Opcode Ox%x"),
request ? "Request" : "Response");
}
}
static void
dissect_multipath_lookup_response(tvbuff_t *tvb, packet_info *pinfo,
proto_tree *tree, gint offset, guint32 value_len)
{
gint end = offset + value_len;
int spec_idx = 0;
while (offset < end) {
proto_item *ti;
proto_tree *multipath_tree;
tvbuff_t *json_tvb;
guint32 result_len;
gint start_offset = offset;
ti = proto_tree_add_subtree_format(tree, tvb, offset, -1, ett_multipath,
&multipath_tree, "Lookup Result [ %u ]",
spec_idx);
proto_tree_add_item(multipath_tree, hf_status, tvb, offset, 2,
ENC_BIG_ENDIAN);
offset += 2;
proto_tree_add_item_ret_uint(multipath_tree, hf_value_length, tvb, offset,
4, ENC_BIG_ENDIAN, &result_len);
offset += 4;
proto_tree_add_item(multipath_tree, hf_value, tvb, offset, result_len,
ENC_ASCII | ENC_NA);
if (result_len > 0) {
json_tvb = tvb_new_subset(tvb, offset, result_len, result_len);
call_dissector(json_handle, json_tvb, pinfo, multipath_tree);
}
offset += result_len;
proto_item_set_len(ti, offset - start_offset);
spec_idx++;
}
}
static void
dissect_multipath_mutation_response(tvbuff_t *tvb, packet_info *pinfo,
proto_tree *tree, gint offset, guint32 value_len)
{
gint end = offset + value_len;
int spec_idx = 0;
while (offset < end) {
proto_item *ti;
proto_tree *multipath_tree;
tvbuff_t *json_tvb;
guint32 status;
gint start_offset = offset;
ti = proto_tree_add_subtree_format(tree, tvb, offset, -1, ett_multipath,
&multipath_tree, "Mutation Result [ %u ]",
spec_idx);
proto_tree_add_item(multipath_tree, hf_multipath_index, tvb, offset, 1,
ENC_BIG_ENDIAN);
offset += 1;
proto_tree_add_item_ret_uint(multipath_tree, hf_status, tvb, offset, 2,
ENC_BIG_ENDIAN, &status);
offset += 2;
if (status == PROTOCOL_BINARY_RESPONSE_SUCCESS) {
guint32 result_len;
proto_tree_add_item_ret_uint(multipath_tree, hf_value_length, tvb,
offset, 4, ENC_BIG_ENDIAN, &result_len);
offset += 4;
proto_tree_add_item(multipath_tree, hf_value, tvb, offset, result_len,
ENC_ASCII | ENC_NA);
if (result_len > 0) {
json_tvb = tvb_new_subset(tvb, offset, result_len, result_len);
call_dissector(json_handle, json_tvb, pinfo, multipath_tree);
}
offset += result_len;
}
proto_item_set_len(ti, offset - start_offset);
spec_idx++;
}
}
static void
dissect_multipath_value(tvbuff_t *tvb, packet_info *pinfo, proto_tree *tree,
gint offset, guint32 value_len, gboolean is_mutation,
gboolean request)
{
gint end = offset + value_len;
int spec_idx = 0;
proto_item *ti;
proto_tree *multipath_tree;
if (request) {
gint min_spec_size;
min_spec_size = (is_mutation ? 8 : 4) + 1;
while (offset + min_spec_size < end) {
guint32 path_len;
guint32 spec_value_len = 0;
gint start_offset = offset;
ti = proto_tree_add_subtree_format(tree, tvb, offset, -1, ett_multipath,
&multipath_tree,
(is_mutation ? "Mutation spec [ %u ]"
: "Lookup spec [ %u ]"),
spec_idx);
proto_tree_add_item(multipath_tree, hf_multipath_opcode, tvb, offset, 1,
ENC_BIG_ENDIAN);
offset += 1;
proto_tree_add_bitmask(multipath_tree, tvb, offset, hf_subdoc_flags,
ett_extras_flags, subdoc_flags, ENC_BIG_ENDIAN);
offset += 1;
proto_tree_add_item_ret_uint(multipath_tree, hf_multipath_pathlen, tvb,
offset, 2, ENC_BIG_ENDIAN, &path_len);
offset += 2;
if (is_mutation) {
proto_tree_add_item_ret_uint(multipath_tree, hf_multipath_valuelen,
tvb, offset, 4, ENC_BIG_ENDIAN,
&spec_value_len);
offset += 4;
}
proto_tree_add_item(multipath_tree, hf_multipath_path, tvb, offset, path_len,
ENC_ASCII | ENC_NA);
offset += path_len;
if (spec_value_len > 0) {
proto_tree_add_item(multipath_tree, hf_multipath_value, tvb, offset,
spec_value_len, ENC_ASCII | ENC_NA);
offset += spec_value_len;
}
proto_item_set_len(ti, offset - start_offset);
spec_idx++;
}
} else {
if (is_mutation) {
dissect_multipath_mutation_response(tvb, pinfo, tree, offset, value_len);
} else {
dissect_multipath_lookup_response(tvb, pinfo, tree, offset, value_len);
}
}
}
static void
dissect_value(tvbuff_t *tvb, packet_info *pinfo, proto_tree *tree,
gint offset, guint32 value_len, guint16 path_len, guint8 opcode,
gboolean request)
{
proto_item *ti = NULL;
gboolean illegal = FALSE;
gboolean missing = FALSE;
if (value_len > 0) {
if (opcode == PROTOCOL_BINARY_CMD_OBSERVE) {
proto_tree *observe_tree;
gint oo = offset, end = offset + value_len;
ti = proto_tree_add_item(tree, hf_observe, tvb, offset, value_len, ENC_ASCII|ENC_NA);
observe_tree = proto_item_add_subtree(ti, ett_observe);
while (oo < end) {
guint16 kl;
proto_tree_add_item(observe_tree, hf_observe_vbucket, tvb, oo, 2, ENC_BIG_ENDIAN);
oo += 2;
kl = tvb_get_ntohs(tvb, oo);
proto_tree_add_item(observe_tree, hf_observe_keylength, tvb, oo, 2, ENC_BIG_ENDIAN);
oo += 2;
proto_tree_add_item(observe_tree, hf_observe_key, tvb, oo, kl, ENC_ASCII|ENC_NA);
oo += kl;
if (!request) {
proto_tree_add_item(observe_tree, hf_observe_status, tvb, oo, 1, ENC_BIG_ENDIAN);
oo++;
proto_tree_add_item(observe_tree, hf_observe_cas, tvb, oo, 8, ENC_BIG_ENDIAN);
oo += 8;
}
}
} else if (!request && opcode == PROTOCOL_BINARY_DCP_STREAM_REQUEST) {
if (value_len % 16 != 0) {
expert_add_info_format(pinfo, ti, &ef_warn_illegal_value_length, "Response with bad failover log length");
} else {
proto_tree *failover_log_tree;
gint cur = offset, end = offset + value_len;
ti = proto_tree_add_item(tree, hf_failover_log, tvb, offset, value_len, ENC_ASCII|ENC_NA);
failover_log_tree = proto_item_add_subtree(ti, ett_failover_log);
ti = proto_tree_add_uint(failover_log_tree, hf_failover_log_size, tvb, offset, 0, (end - cur) / 16);
PROTO_ITEM_SET_GENERATED(ti);
while (cur < end) {
proto_tree_add_item(failover_log_tree, hf_failover_log_vbucket_uuid, tvb, cur, 8, ENC_BIG_ENDIAN);
cur += 8;
proto_tree_add_item(failover_log_tree, hf_failover_log_vbucket_seqno, tvb, cur, 8, ENC_BIG_ENDIAN);
cur += 8;
}
}
} else if (!request && opcode == PROTOCOL_BINARY_CMD_GET_ALL_VB_SEQNOS) {
if (value_len % 10 != 0) {
expert_add_info_format(pinfo, ti, &ef_warn_illegal_value_length, "Response with bad body length");
} else {
proto_tree *vbucket_states_tree;
gint cur = offset, end = offset + value_len;
ti = proto_tree_add_item(tree, hf_vbucket_states, tvb, offset, value_len, ENC_ASCII|ENC_NA);
vbucket_states_tree = proto_item_add_subtree(ti, ett_vbucket_states);
ti = proto_tree_add_uint(vbucket_states_tree, hf_vbucket_states_size, tvb, offset, 0, (end - cur) / 10);
PROTO_ITEM_SET_GENERATED(ti);
while (cur < end) {
proto_tree_add_item(vbucket_states_tree, hf_vbucket_states_id, tvb, cur, 2, ENC_BIG_ENDIAN);
cur += 2;
proto_tree_add_item(vbucket_states_tree, hf_vbucket_states_seqno, tvb, cur, 8, ENC_BIG_ENDIAN);
cur += 8;
}
}
} else if (!request && (opcode == PROTOCOL_BINARY_CMD_INCREMENT || opcode == PROTOCOL_BINARY_CMD_DECREMENT)) {
ti = proto_tree_add_item(tree, hf_uint64_response, tvb, offset, 8, ENC_BIG_ENDIAN);
if (value_len != 8) {
expert_add_info_format(pinfo, ti, &ef_warn_illegal_value_length, "Illegal Value length, should be 8");
}
} else if (!request && has_json_value(opcode)) {
tvbuff_t *json_tvb;
ti = proto_tree_add_item(tree, hf_value, tvb, offset, value_len, ENC_ASCII | ENC_NA);
json_tvb = tvb_new_subset(tvb, offset, value_len, value_len);
call_dissector(json_handle, json_tvb, pinfo, tree);
} else if (opcode == PROTOCOL_BINARY_CMD_SUBDOC_MULTI_LOOKUP ||
opcode == PROTOCOL_BINARY_CMD_SUBDOC_MULTI_MUTATION) {
dissect_multipath_value(tvb, pinfo, tree, offset, value_len,
(opcode == PROTOCOL_BINARY_CMD_SUBDOC_MULTI_MUTATION),
request);
} else if (path_len != 0) {
ti = proto_tree_add_item(tree, hf_path, tvb, offset, path_len, ENC_ASCII | ENC_NA);
value_len -= path_len;
if (value_len > 0) {
ti = proto_tree_add_item(tree, hf_value, tvb, offset + path_len,
value_len, ENC_ASCII | ENC_NA);
}
} else {
ti = proto_tree_add_item(tree, hf_value, tvb, offset, value_len, ENC_ASCII | ENC_NA);
}
}
if (value_len) {
switch (opcode) {
case PROTOCOL_BINARY_CMD_GET:
case PROTOCOL_BINARY_CMD_GETQ:
case PROTOCOL_BINARY_CMD_GETK:
case PROTOCOL_BINARY_CMD_GETKQ:
case PROTOCOL_BINARY_CMD_INCREMENT:
case PROTOCOL_BINARY_CMD_DECREMENT:
case PROTOCOL_BINARY_CMD_VERSION:
case PROTOCOL_BINARY_CMD_INCREMENTQ:
case PROTOCOL_BINARY_CMD_DECREMENTQ:
case PROTOCOL_BINARY_DCP_OPEN_CONNECTION:
case PROTOCOL_BINARY_DCP_ADD_STREAM:
case PROTOCOL_BINARY_DCP_CLOSE_STREAM:
case PROTOCOL_BINARY_DCP_FAILOVER_LOG_REQUEST:
case PROTOCOL_BINARY_DCP_STREAM_END:
case PROTOCOL_BINARY_DCP_SNAPSHOT_MARKER:
case PROTOCOL_BINARY_DCP_DELETION:
case PROTOCOL_BINARY_DCP_EXPIRATION:
case PROTOCOL_BINARY_DCP_FLUSH:
case PROTOCOL_BINARY_DCP_SET_VBUCKET_STATE:
if (request) {
illegal = TRUE;
}
break;
case PROTOCOL_BINARY_CMD_DELETE:
case PROTOCOL_BINARY_CMD_QUIT:
case PROTOCOL_BINARY_CMD_FLUSH:
case PROTOCOL_BINARY_CMD_NOOP:
case PROTOCOL_BINARY_CMD_DELETEQ:
case PROTOCOL_BINARY_CMD_QUITQ:
case PROTOCOL_BINARY_CMD_FLUSHQ:
illegal = TRUE;
break;
case PROTOCOL_BINARY_CMD_SET:
case PROTOCOL_BINARY_CMD_ADD:
case PROTOCOL_BINARY_CMD_REPLACE:
case PROTOCOL_BINARY_CMD_SETQ:
case PROTOCOL_BINARY_CMD_ADDQ:
case PROTOCOL_BINARY_CMD_REPLACEQ:
case PROTOCOL_BINARY_CMD_APPEND:
case PROTOCOL_BINARY_CMD_PREPEND:
case PROTOCOL_BINARY_CMD_APPENDQ:
case PROTOCOL_BINARY_CMD_PREPENDQ:
if (!request) {
illegal = TRUE;
}
break;
}
} else {
switch (opcode) {
case PROTOCOL_BINARY_DCP_FAILOVER_LOG_REQUEST:
if (!request) {
missing = TRUE;
}
break;
}
}
if (illegal) {
expert_add_info_format(pinfo, ti, &ef_warn_shall_not_have_value, "%s %s shall not have Value",
val_to_str_ext(opcode, &opcode_vals_ext, "Opcode 0x%x"),
request ? "Request" : "Response");
} else if (missing) {
expert_add_info_format(pinfo, ti, &ei_value_missing, "%s %s must have Value",
val_to_str_ext(opcode, &opcode_vals_ext, "Opcode 0x%x"),
request ? "Request" : "Response");
}
}
static int
dissect_couchbase(tvbuff_t *tvb, packet_info *pinfo, proto_tree *tree, void* data _U_)
{
proto_tree *couchbase_tree;
proto_item *couchbase_item, *ti;
gint offset = 0;
guint8 magic, opcode, extlen;
guint16 keylen, status = 0, vbucket;
guint32 bodylen, value_len;
gboolean request;
col_set_str(pinfo->cinfo, COL_PROTOCOL, PSNAME);
col_clear(pinfo->cinfo, COL_INFO);
couchbase_item = proto_tree_add_item(tree, proto_couchbase, tvb, offset, -1, ENC_NA);
couchbase_tree = proto_item_add_subtree(couchbase_item, ett_couchbase);
magic = tvb_get_guint8(tvb, offset);
ti = proto_tree_add_item(couchbase_tree, hf_magic, tvb, offset, 1, ENC_BIG_ENDIAN);
offset += 1;
if (try_val_to_str(magic, magic_vals) == NULL) {
expert_add_info_format(pinfo, ti, &ef_warn_unknown_magic_byte, "Unknown magic byte: 0x%x", magic);
}
opcode = tvb_get_guint8(tvb, offset);
ti = proto_tree_add_item(couchbase_tree, hf_opcode, tvb, offset, 1, ENC_BIG_ENDIAN);
offset += 1;
if (try_val_to_str_ext(opcode, &opcode_vals_ext) == NULL) {
expert_add_info_format(pinfo, ti, &ef_warn_unknown_opcode, "Unknown opcode: 0x%x", opcode);
}
proto_item_append_text(couchbase_item, ", %s %s, Opcode: 0x%x",
val_to_str_ext(opcode, &opcode_vals_ext, "Unknown opcode"),
val_to_str(magic, magic_vals, "Unknown magic (0x%x)"),
opcode);
col_append_fstr(pinfo->cinfo, COL_INFO, "%s %s, Opcode: 0x%x",
val_to_str_ext(opcode, &opcode_vals_ext, "Unknown opcode (0x%x)"),
val_to_str(magic, magic_vals, "Unknown magic (0x%x)"),
opcode);
keylen = tvb_get_ntohs(tvb, offset);
proto_tree_add_item(couchbase_tree, hf_keylength, tvb, offset, 2, ENC_BIG_ENDIAN);
offset += 2;
extlen = tvb_get_guint8(tvb, offset);
proto_tree_add_item(couchbase_tree, hf_extlength, tvb, offset, 1, ENC_BIG_ENDIAN);
offset += 1;
proto_tree_add_item(couchbase_tree, hf_datatype, tvb, offset, 1, ENC_BIG_ENDIAN);
offset += 1;
if (magic & 0x01) {
request = FALSE;
status = tvb_get_ntohs(tvb, offset);
ti = proto_tree_add_item(couchbase_tree, hf_status, tvb, offset, 2, ENC_BIG_ENDIAN);
if (status != 0) {
expert_add_info_format(pinfo, ti, &ef_warn_unknown_opcode, "%s: %s",
val_to_str_ext(opcode, &opcode_vals_ext, "Unknown opcode (0x%x)"),
val_to_str_ext(status, &status_vals_ext, "Status: 0x%x"));
}
} else {
request = TRUE;
vbucket = tvb_get_ntohs(tvb, offset);
proto_tree_add_item(couchbase_tree, hf_vbucket, tvb, offset, 2, ENC_BIG_ENDIAN);
if (opcode != PROTOCOL_BINARY_CMD_OBSERVE) {
proto_item_append_text(couchbase_item, ", VBucket: 0x%x", vbucket);
col_append_fstr(pinfo->cinfo, COL_INFO, ", VBucket: 0x%x", vbucket);
}
}
offset += 2;
bodylen = tvb_get_ntohl(tvb, offset);
value_len = bodylen - extlen - keylen;
ti = proto_tree_add_uint(couchbase_tree, hf_value_length, tvb, offset, 0, value_len);
PROTO_ITEM_SET_GENERATED(ti);
proto_tree_add_item(couchbase_tree, hf_total_bodylength, tvb, offset, 4, ENC_BIG_ENDIAN);
offset += 4;
proto_tree_add_item(couchbase_tree, hf_opaque, tvb, offset, 4, ENC_LITTLE_ENDIAN);
offset += 4;
if (opcode == PROTOCOL_BINARY_CMD_OBSERVE) {
proto_tree_add_item(couchbase_tree, hf_ttp, tvb, offset, 4, ENC_BIG_ENDIAN);
offset += 4;
proto_tree_add_item(couchbase_tree, hf_ttr, tvb, offset, 4, ENC_BIG_ENDIAN);
offset += 4;
} else {
proto_tree_add_item(couchbase_tree, hf_cas, tvb, offset, 8, ENC_BIG_ENDIAN);
offset += 8;
}
if (status == 0) {
guint16 path_len = 0;
dissect_extras(tvb, pinfo, couchbase_tree, offset, extlen, opcode, request,
&path_len);
offset += extlen;
dissect_key(tvb, pinfo, couchbase_tree, offset, keylen, opcode, request);
offset += keylen;
dissect_value(tvb, pinfo, couchbase_tree, offset, value_len, path_len,
opcode, request);
} else if (bodylen) {
proto_tree_add_item(couchbase_tree, hf_value, tvb, offset, bodylen,
ENC_ASCII | ENC_NA);
if (status == PROTOCOL_BINARY_RESPONSE_NOT_MY_VBUCKET) {
tvbuff_t *json_tvb;
json_tvb = tvb_new_subset(tvb, offset, bodylen, bodylen);
call_dissector(json_handle, json_tvb, pinfo, couchbase_tree);
} else if (opcode == PROTOCOL_BINARY_CMD_SUBDOC_MULTI_LOOKUP) {
dissect_multipath_lookup_response(tvb, pinfo, tree, offset, value_len);
} else if (opcode == PROTOCOL_BINARY_CMD_SUBDOC_MULTI_MUTATION) {
dissect_multipath_mutation_response(tvb, pinfo, tree, offset, value_len);
}
col_append_fstr(pinfo->cinfo, COL_INFO, ", %s",
val_to_str_ext(status, &status_vals_ext, "Unknown status: 0x%x"));
} else {
switch (opcode) {
case PROTOCOL_BINARY_CMD_SUBDOC_GET:
case PROTOCOL_BINARY_CMD_SUBDOC_EXISTS:
case PROTOCOL_BINARY_CMD_SUBDOC_DICT_ADD:
case PROTOCOL_BINARY_CMD_SUBDOC_DICT_UPSERT:
case PROTOCOL_BINARY_CMD_SUBDOC_DELETE:
case PROTOCOL_BINARY_CMD_SUBDOC_REPLACE:
case PROTOCOL_BINARY_CMD_SUBDOC_ARRAY_PUSH_LAST:
case PROTOCOL_BINARY_CMD_SUBDOC_ARRAY_PUSH_FIRST:
case PROTOCOL_BINARY_CMD_SUBDOC_ARRAY_INSERT:
case PROTOCOL_BINARY_CMD_SUBDOC_ARRAY_ADD_UNIQUE:
case PROTOCOL_BINARY_CMD_SUBDOC_COUNTER:
case PROTOCOL_BINARY_CMD_SUBDOC_MULTI_LOOKUP:
case PROTOCOL_BINARY_CMD_SUBDOC_MULTI_MUTATION:
break;
default:
ti = proto_tree_add_item(tree, hf_value, tvb, offset, 0,
ENC_ASCII | ENC_NA);
expert_add_info_format(pinfo, ti, &ei_value_missing,
"%s with status %s (0x%x) must have Value",
val_to_str_ext(opcode, &opcode_vals_ext, "Opcode 0x%x"),
val_to_str_ext(status, &status_vals_ext, "Unknown"),
status);
break;
}
}
return tvb_reported_length(tvb);
}
static int
dissect_couchbase_tcp(tvbuff_t *tvb, packet_info *pinfo, proto_tree *tree, void* data)
{
gint offset = 0;
guint8 magic;
magic = tvb_get_guint8(tvb, offset);
if (try_val_to_str(magic, magic_vals) == NULL)
return 0;
tcp_dissect_pdus(tvb, pinfo, tree, couchbase_desegment_body, 12,
get_couchbase_pdu_len, dissect_couchbase, data);
return tvb_captured_length(tvb);
}
void
proto_register_couchbase(void)
{
static hf_register_info hf[] = {
{ &hf_magic, { "Magic", "couchbase.magic", FT_UINT8, BASE_HEX, VALS(magic_vals), 0x0, "Magic number", HFILL } },
{ &hf_opcode, { "Opcode", "couchbase.opcode", FT_UINT8, BASE_HEX|BASE_EXT_STRING, &opcode_vals_ext, 0x0, "Command code", HFILL } },
{ &hf_extlength, { "Extras Length", "couchbase.extras.length", FT_UINT8, BASE_DEC, NULL, 0x0, "Length in bytes of the command extras", HFILL } },
{ &hf_keylength, { "Key Length", "couchbase.key.length", FT_UINT16, BASE_DEC, NULL, 0x0, "Length in bytes of the text key that follows the command extras", HFILL } },
{ &hf_value_length, { "Value Length", "couchbase.value.length", FT_UINT32, BASE_DEC, NULL, 0x0, "Length in bytes of the value that follows the key", HFILL } },
{ &hf_datatype, { "Data Type", "couchbase.datatype", FT_UINT8, BASE_HEX, VALS(datatype_vals), 0x0, NULL, HFILL } },
{ &hf_vbucket, { "VBucket", "couchbase.vbucket", FT_UINT16, BASE_DEC_HEX, NULL, 0x0, "VBucket ID", HFILL } },
{ &hf_status, { "Status", "couchbase.status", FT_UINT16, BASE_HEX|BASE_EXT_STRING, &status_vals_ext, 0x0, "Status of the response", HFILL } },
{ &hf_total_bodylength, { "Total Body Length", "couchbase.total_bodylength", FT_UINT32, BASE_DEC, NULL, 0x0, "Length in bytes of extra + key + value", HFILL } },
{ &hf_opaque, { "Opaque", "couchbase.opaque", FT_UINT32, BASE_HEX, NULL, 0x0, NULL, HFILL } },
{ &hf_cas, { "CAS", "couchbase.cas", FT_UINT64, BASE_HEX, NULL, 0x0, "Data version check", HFILL } },
{ &hf_ttp, { "Time to Persist", "couchbase.ttp", FT_UINT32, BASE_DEC, NULL, 0x0, "Approximate time needed to persist the key (milliseconds)", HFILL } },
{ &hf_ttr, { "Time to Replicate", "couchbase.ttr", FT_UINT32, BASE_DEC, NULL, 0x0, "Approximate time needed to replicate the key (milliseconds)", HFILL } },
{ &hf_extras, { "Extras", "couchbase.extras", FT_NONE, BASE_NONE, NULL, 0x0, NULL, HFILL } },
{ &hf_extras_flags, { "Flags", "couchbase.extras.flags", FT_UINT32, BASE_HEX, NULL, 0x0, NULL, HFILL } },
{ &hf_extras_flags_backfill, { "Backfill Age", "couchbase.extras.flags.backfill", FT_BOOLEAN, 16, TFS(&tfs_set_notset), 0x01, NULL, HFILL } },
{ &hf_extras_flags_dump, { "Dump", "couchbase.extras.flags.dump", FT_BOOLEAN, 16, TFS(&tfs_set_notset), 0x02, NULL, HFILL } },
{ &hf_extras_flags_list_vbuckets, { "List VBuckets", "couchbase.extras.flags.list_vbuckets", FT_BOOLEAN, 16, TFS(&tfs_set_notset), 0x04, NULL, HFILL } },
{ &hf_extras_flags_takeover_vbuckets, { "Takeover VBuckets", "couchbase.extras.flags.takeover_vbuckets", FT_BOOLEAN, 16, TFS(&tfs_set_notset), 0x08, NULL, HFILL } },
{ &hf_extras_flags_support_ack, { "Support ACK", "couchbase.extras.flags.support_ack", FT_BOOLEAN, 16, TFS(&tfs_set_notset), 0x10, NULL, HFILL } },
{ &hf_extras_flags_request_keys_only, { "Request Keys Only", "couchbase.extras.flags.request_keys_only", FT_BOOLEAN, 16, TFS(&tfs_set_notset), 0x20, NULL, HFILL } },
{ &hf_extras_flags_checkpoint, { "Checkpoint", "couchbase.extras.flags.checkpoint", FT_BOOLEAN, 16, TFS(&tfs_set_notset), 0x40, NULL, HFILL } },
{ &hf_subdoc_flags, {"Subdoc flags", "couchbase.extras.subdoc.flags", FT_UINT8, BASE_HEX, NULL, 0x0, NULL, HFILL} },
{ &hf_subdoc_flags_mkdirp, {"MKDIR_P", "couchbase.extras.subdoc.flags.mkdir_p", FT_BOOLEAN, 8, TFS(&tfs_set_notset), 0x01, "Create non-existent intermediate paths", HFILL} },
{ &hf_extras_pathlen, { "Path Length", "couchbase.extras.pathlen", FT_UINT16, BASE_DEC, NULL, 0x0, NULL, HFILL } },
{ &hf_extras_flags_dcp_connection_type, {"Connection Type", "couchbase.extras.flags.dcp_connection_type", FT_UINT32, BASE_HEX, VALS(dcp_connection_type_vals), 0x03, NULL, HFILL } },
{ &hf_extras_flags_dcp_add_stream_takeover, {"Take Over", "couchbase.extras.flags.dcp_add_stream_takeover", FT_BOOLEAN, 16, TFS(&tfs_set_notset), 0x01, NULL, HFILL } },
{ &hf_extras_flags_dcp_add_stream_diskonly, {"Disk Only", "couchbase.extras.flags.dcp_add_stream_diskonly", FT_BOOLEAN, 16, TFS(&tfs_set_notset), 0x02, NULL, HFILL } },
{ &hf_extras_flags_dcp_add_stream_latest, {"Latest", "couchbase.extras.flags.dcp_add_stream_latest", FT_BOOLEAN, 16, TFS(&tfs_set_notset), 0x04, NULL, HFILL } },
{ &hf_extras_flags_dcp_snapshot_marker_memory, {"Memory", "couchbase.extras.flags.dcp_snapshot_marker_memory", FT_BOOLEAN, 16, TFS(&tfs_set_notset), 0x01, NULL, HFILL } },
{ &hf_extras_flags_dcp_snapshot_marker_disk, {"Disk", "couchbase.extras.flags.dcp_snapshot_marker_disk", FT_BOOLEAN, 16, TFS(&tfs_set_notset), 0x02, NULL, HFILL } },
{ &hf_extras_flags_dcp_snapshot_marker_chk, {"Chk", "couchbase.extras.flags.dcp_snapshot_marker_chk", FT_BOOLEAN, 16, TFS(&tfs_set_notset), 0x04, NULL, HFILL } },
{ &hf_extras_flags_dcp_snapshot_marker_ack, {"Ack", "couchbase.extras.flags.dcp_snapshot_marker_ack", FT_BOOLEAN, 16, TFS(&tfs_set_notset), 0x08, NULL, HFILL } },
{ &hf_extras_seqno, { "Sequence number", "couchbase.extras.seqno", FT_UINT32, BASE_HEX, NULL, 0x0, NULL, HFILL } },
{ &hf_extras_opaque, { "Opaque (vBucket identifier)", "couchbase.extras.opaque", FT_UINT32, BASE_HEX, NULL, 0x0, NULL, HFILL } },
{ &hf_extras_reserved, { "Reserved", "couchbase.extras.reserved", FT_UINT32, BASE_HEX, NULL, 0x0, NULL, HFILL } },
{ &hf_extras_start_seqno, { "Start Sequence Number", "couchbase.extras.start_seqno", FT_UINT64, BASE_HEX, NULL, 0x0, NULL, HFILL } },
{ &hf_extras_end_seqno, { "End Sequence Number", "couchbase.extras.start_seqno", FT_UINT64, BASE_HEX, NULL, 0x0, NULL, HFILL } },
{ &hf_extras_vbucket_uuid, { "VBucket UUID", "couchbase.extras.vbucket_uuid", FT_UINT64, BASE_HEX, NULL, 0x0, NULL, HFILL } },
{ &hf_extras_snap_start_seqno, { "Snapshot Start Sequence Number", "couchbase.extras.snap_start_seqno", FT_UINT64, BASE_HEX, NULL, 0x0, NULL, HFILL } },
{ &hf_extras_snap_end_seqno, { "Snapshot End Sequence Number", "couchbase.extras.snap_start_seqno", FT_UINT64, BASE_HEX, NULL, 0x0, NULL, HFILL } },
{ &hf_extras_by_seqno, { "by_seqno", "couchbase.extras.by_seqno", FT_UINT64, BASE_HEX, NULL, 0x0, NULL, HFILL } },
{ &hf_extras_rev_seqno, { "rev_seqno", "couchbase.extras.rev_seqno", FT_UINT64, BASE_HEX, NULL, 0x0, NULL, HFILL } },
{ &hf_extras_lock_time, { "lock_time", "couchbase.extras.lock_time", FT_UINT32, BASE_DEC, NULL, 0x0, NULL, HFILL } },
{ &hf_extras_nmeta, { "nmeta", "couchbase.extras.nmeta", FT_UINT32, BASE_HEX, NULL, 0x0, NULL, HFILL } },
{ &hf_extras_nru, { "nru", "couchbase.extras.nru", FT_UINT16, BASE_HEX, NULL, 0x0, NULL, HFILL } },
{ &hf_extras_bytes_to_ack, { "bytes_to_ack", "couchbase.extras.bytes_to_ack", FT_UINT32, BASE_DEC, NULL, 0x0, NULL, HFILL } },
{ &hf_failover_log, { "Failover Log", "couchbase.dcp.failover_log", FT_STRING, BASE_NONE, NULL, 0x0, NULL, HFILL } },
{ &hf_failover_log_size, { "Size", "couchbase.dcp.failover_log.size", FT_UINT32, BASE_DEC, NULL, 0x0, NULL, HFILL } },
{ &hf_failover_log_vbucket_uuid, { "VBucket UUID", "couchbase.dcp.failover_log.vbucket_uuid", FT_UINT64, BASE_HEX, NULL, 0x0, NULL, HFILL } },
{ &hf_failover_log_vbucket_seqno, { "Sequence Number", "couchbase.dcp.failover_log.seqno", FT_UINT64, BASE_HEX, NULL, 0x0, NULL, HFILL } },
{ &hf_vbucket_states, { "VBucket States", "couchbase.vbucket_states", FT_STRING, BASE_NONE, NULL, 0x0, NULL, HFILL } },
{ &hf_vbucket_states_state, { "State", "couchbase.vbucket_states.state", FT_UINT32, BASE_HEX, VALS(vbucket_states_vals), 0x0, NULL, HFILL } },
{ &hf_vbucket_states_size, { "Size", "couchbase.vbucket_states.size", FT_UINT32, BASE_DEC, NULL, 0x0, NULL, HFILL } },
{ &hf_vbucket_states_id, { "VBucket", "couchbase.vbucket_states.id", FT_UINT16, BASE_DEC, NULL, 0x0, NULL, HFILL } },
{ &hf_vbucket_states_seqno, { "Sequence Number", "couchbase.vbucket_states.seqno", FT_UINT64, BASE_DEC, NULL, 0x0, NULL, HFILL } },
{ &hf_extras_expiration, { "Expiration", "couchbase.extras.expiration", FT_UINT32, BASE_DEC, NULL, 0x0, NULL, HFILL } },
{ &hf_extras_delta, { "Amount to Add", "couchbase.extras.delta", FT_UINT64, BASE_DEC, NULL, 0x0, NULL, HFILL } },
{ &hf_extras_initial, { "Initial Value", "couchbase.extras.initial", FT_UINT64, BASE_DEC, NULL, 0x0, NULL, HFILL } },
{ &hf_extras_unknown, { "Unknown", "couchbase.extras.unknown", FT_BYTES, BASE_NONE, NULL, 0x0, "Unknown Extras", HFILL } },
{ &hf_key, { "Key", "couchbase.key", FT_STRING, BASE_NONE, NULL, 0x0, NULL, HFILL } },
{ &hf_path, { "Path", "couchbase.path", FT_STRING, BASE_NONE, NULL, 0x0, NULL, HFILL } },
{ &hf_value, { "Value", "couchbase.value", FT_STRING, BASE_NONE, NULL, 0x0, NULL, HFILL } },
{ &hf_uint64_response, { "Response", "couchbase.extras.response", FT_UINT64, BASE_DEC, NULL, 0x0, NULL, HFILL } },
{ &hf_observe, { "Observe", "couchbase.observe", FT_STRING, BASE_NONE, NULL, 0x0, "The observe properties", HFILL } },
{ &hf_observe_key, { "Key", "couchbase.observe.key", FT_STRING, BASE_NONE, NULL, 0x0, "The observable key", HFILL } },
{ &hf_observe_keylength, { "Key Length", "couchbase.observe.keylength", FT_UINT16, BASE_DEC, NULL, 0x0, "The length of the observable key", HFILL } },
{ &hf_observe_vbucket, { "VBucket", "couchbase.observe.vbucket", FT_UINT16, BASE_HEX, NULL, 0x0, "VBucket of the observable key", HFILL } },
{ &hf_observe_status, { "Status", "couchbase.observe.status", FT_UINT8, BASE_HEX, NULL, 0x0, "Status of the observable key", HFILL } },
{ &hf_observe_cas, { "CAS", "couchbase.observe.cas", FT_UINT64, BASE_HEX, NULL, 0x0, "CAS value of the observable key", HFILL } },
{ &hf_multipath_opcode, { "Opcode", "couchbase.multipath.opcode", FT_UINT8, BASE_HEX|BASE_EXT_STRING, &opcode_vals_ext, 0x0, "Command code", HFILL } },
{ &hf_multipath_index, { "Index", "couchbase.multipath.index", FT_UINT8, BASE_DEC, NULL, 0x0, NULL, HFILL } },
{ &hf_multipath_pathlen, { "Path Length", "couchbase.multipath.path.length", FT_UINT16, BASE_DEC, NULL, 0x0, NULL, HFILL } },
{ &hf_multipath_path, { "Path", "couchbase.multipath.path", FT_STRING, BASE_NONE, NULL, 0x0, NULL, HFILL } },
{ &hf_multipath_valuelen, { "Value Length", "couchbase.multipath.value.length", FT_UINT32, BASE_DEC, NULL, 0x0, NULL, HFILL } },
{ &hf_multipath_value, { "Value", "couchbase.multipath.value", FT_STRING, BASE_NONE, NULL, 0x0, NULL, HFILL } },
};
static ei_register_info ei[] = {
{ &ei_value_missing, { "couchbase.value_missing", PI_PROTOCOL, PI_WARN, "Value is mandatory for this command", EXPFILL }},
{ &ef_warn_shall_not_have_value, { "couchbase.warn.shall_not_have_value", PI_UNDECODED, PI_WARN, "Packet shall not have value", EXPFILL }},
{ &ef_warn_shall_not_have_extras, { "couchbase.warn.shall_not_have_extras", PI_UNDECODED, PI_WARN, "Packet shall not have extras", EXPFILL }},
{ &ef_warn_shall_not_have_key, { "couchbase.warn.shall_not_have_key", PI_UNDECODED, PI_WARN, "Packet shall not have key", EXPFILL }},
{ &ef_warn_must_have_extras, { "couchbase.warn.must_have_extras", PI_UNDECODED, PI_WARN, "Packet must have extras", EXPFILL }},
{ &ef_warn_must_have_key, { "couchbase.warn.must_have_key", PI_UNDECODED, PI_WARN, "%s %s must have Key", EXPFILL }},
{ &ef_warn_illegal_extras_length, { "couchbase.warn.illegal_extras_length", PI_UNDECODED, PI_WARN, "Illegal Extras length", EXPFILL }},
{ &ef_warn_illegal_value_length, { "couchbase.warn.illegal_value_length", PI_UNDECODED, PI_WARN, "Illegal Value length", EXPFILL }},
{ &ef_warn_unknown_magic_byte, { "couchbase.warn.unknown_magic_byte", PI_UNDECODED, PI_WARN, "Unknown magic byte", EXPFILL }},
{ &ef_warn_unknown_opcode, { "couchbase.warn.unknown_opcode", PI_UNDECODED, PI_WARN, "Unknown opcode", EXPFILL }},
{ &ef_note_status_code, { "couchbase.note.status_code", PI_RESPONSE_CODE, PI_NOTE, "Status", EXPFILL }}
};
static gint *ett[] = {
&ett_couchbase,
&ett_extras,
&ett_extras_flags,
&ett_observe,
&ett_failover_log,
&ett_vbucket_states,
&ett_multipath
};
module_t *couchbase_module;
expert_module_t* expert_couchbase;
proto_couchbase = proto_register_protocol(PNAME, PSNAME, PFNAME);
proto_register_field_array(proto_couchbase, hf, array_length(hf));
proto_register_subtree_array(ett, array_length(ett));
expert_couchbase = expert_register_protocol(proto_couchbase);
expert_register_field_array(expert_couchbase, ei, array_length(ei));
range_convert_str(&couchbase_tcp_port_range, COUCHBASE_DEFAULT_PORT, MAX_TCP_PORT);
couchbase_module = prefs_register_protocol(proto_couchbase, NULL);
prefs_register_bool_preference(couchbase_module, "desegment_pdus",
"Reassemble PDUs spanning multiple TCP segments",
"Whether the memcache dissector should reassemble PDUs"
" spanning multiple TCP segments."
" To use this option, you must also enable \"Allow subdissectors"
" to reassemble TCP streams\" in the TCP protocol settings.",
&couchbase_desegment_body);
prefs_register_range_preference(couchbase_module, "tcp.ports", "Couchbase TCP ports",
"TCP ports to be decoded as Couchbase (default is "
COUCHBASE_DEFAULT_PORT ")",
&couchbase_tcp_port_range, MAX_TCP_PORT);
}
void
proto_reg_handoff_couchbase(void)
{
static range_t *tcp_port_range;
static gboolean initialized = FALSE;
if (initialized == FALSE) {
couchbase_tcp_handle = create_dissector_handle(dissect_couchbase_tcp, proto_couchbase);
initialized = TRUE;
}
else {
dissector_delete_uint_range("tcp.port", tcp_port_range, couchbase_tcp_handle);
g_free(tcp_port_range);
}
tcp_port_range = range_copy(couchbase_tcp_port_range);
dissector_add_uint_range("tcp.port", tcp_port_range, couchbase_tcp_handle);
json_handle = find_dissector_add_dependency("json", proto_couchbase);
}
