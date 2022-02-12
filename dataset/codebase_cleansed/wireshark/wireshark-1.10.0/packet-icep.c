static void dissect_ice_string(packet_info *pinfo, proto_tree *tree, proto_item *item, int hf_icep,
tvbuff_t *tvb, guint32 offset, gint32 *consumed, char **dest)
{
guint32 Size = 0;
char *s = NULL;
(*consumed) = 0;
if ( !tvb_bytes_exist(tvb, offset, 1) ) {
if (item)
expert_add_info_format(pinfo, item, PI_MALFORMED, PI_ERROR, "1st byte of Size missing");
col_append_str(mypinfo->cinfo, COL_INFO, " (1st byte of Size missing)");
(*consumed) = -1;
return;
}
Size = tvb_get_guint8(tvb, offset);
offset++;
(*consumed)++;
if ( Size == 255 ) {
if ( !tvb_bytes_exist(tvb, offset, 4) ) {
if (item)
expert_add_info_format(pinfo, item, PI_MALFORMED, PI_ERROR, "second field of Size missing");
col_append_str(mypinfo->cinfo, COL_INFO, " (second field of Size missing)");
(*consumed) = -1;
return;
}
Size = tvb_get_letohl(tvb, offset);
offset += 4;
(*consumed) += 4;
}
DBG1("string.Size --> %d\n", Size);
if ( !tvb_bytes_exist(tvb, offset, Size) ) {
if (item)
expert_add_info_format(pinfo, item, PI_MALFORMED, PI_ERROR, "missing or truncated string");
col_append_str(mypinfo->cinfo, COL_INFO, " (missing or truncated string)");
(*consumed) = -1;
return;
}
if ( Size > icep_max_ice_string_len ) {
if (item)
expert_add_info_format(pinfo, item, PI_PROTOCOL, PI_WARN, "string too long");
col_append_str(mypinfo->cinfo, COL_INFO, " (string too long)");
(*consumed) = -1;
return;
}
if ( Size != 0 ) {
s = tvb_get_ephemeral_string(tvb, offset, Size);
if (tree)
proto_tree_add_string(tree, hf_icep, tvb, offset, Size, s);
} else {
s = g_strdup("(empty)");
if (tree)
proto_tree_add_string(tree, hf_icep, tvb, offset - 1, 1, s);
}
if ( dest != NULL )
*dest = s;
(*consumed) += Size;
return;
}
static void dissect_ice_facet(packet_info *pinfo, proto_tree *tree, proto_item *item, int hf_icep,
tvbuff_t *tvb, guint32 offset, gint32 *consumed)
{
guint32 Size = 0;
(*consumed) = 0;
if ( !tvb_bytes_exist(tvb, offset, 1) ) {
if (item)
expert_add_info_format(pinfo, item, PI_MALFORMED, PI_ERROR, "facet field missing");
col_append_str(mypinfo->cinfo, COL_INFO,
" (facet field missing)");
(*consumed) = -1;
return;
}
Size = tvb_get_guint8(tvb, offset);
offset++;
(*consumed)++;
if ( Size == 0 ) {
if (tree) {
proto_tree_add_string(tree, hf_icep, tvb, offset - 1, 1, "(empty)");
}
return;
}
if ( Size == 1 ) {
gint32 consumed_facet = 0;
dissect_ice_string(pinfo, tree, item, hf_icep, tvb, offset, &consumed_facet, NULL);
if ( consumed_facet == -1 ) {
(*consumed) = -1;
return;
}
(*consumed) += consumed_facet;
return;
}
if (item)
expert_add_info_format(pinfo, item, PI_PROTOCOL, PI_WARN, "facet can be max one element");
col_append_str(mypinfo->cinfo, COL_INFO,
" (facet can be max one element)");
(*consumed) = -1;
return;
}
static void dissect_ice_context(packet_info *pinfo, proto_tree *tree, proto_item *item,
tvbuff_t *tvb, guint32 offset, gint32 *consumed)
{
guint32 Size = 0;
guint32 i = 0;
const char *s = NULL;
(*consumed) = 0;
if ( !tvb_bytes_exist(tvb, offset, 1) ) {
if (item)
expert_add_info_format(pinfo, item, PI_MALFORMED, PI_ERROR, "context missing");
col_append_str(mypinfo->cinfo, COL_INFO,
" (context missing)");
(*consumed) = -1;
return;
}
Size = tvb_get_guint8(tvb, offset);
offset++;
(*consumed)++;
if ( Size == 255 ) {
if ( !tvb_bytes_exist(tvb, offset, 4) ) {
if (item)
expert_add_info_format(pinfo, item, PI_MALFORMED, PI_ERROR, "second field of Size missing");
col_append_str(mypinfo->cinfo, COL_INFO, " (second field of Size missing)");
(*consumed) = -1;
return;
}
Size = tvb_get_letohl(tvb, offset);
offset += 4;
(*consumed) += 4;
}
DBG1("context.Size --> %d\n", Size);
if ( Size > icep_max_ice_context_pairs ) {
if (item)
expert_add_info_format(pinfo, item, PI_PROTOCOL, PI_WARN, "too long context");
col_append_str(mypinfo->cinfo, COL_INFO, " (too long context)");
(*consumed) = -1;
return;
}
if (Size == 0) {
s = "(empty)";
if (tree)
proto_tree_add_string(tree, hf_icep_context, tvb, offset - 1, 1, s);
return;
}
for ( i = 0; i < Size; i++ ) {
gint32 consumed_key = 0;
char *str_key = NULL;
gint32 consumed_value = 0;
char *str_value = NULL;
proto_item *ti = NULL;
DBG1("looping through context dictionary, loop #%d\n", i);
ti = proto_tree_add_text(tree, tvb, offset, -1, "Invocation Context");
dissect_ice_string(pinfo, tree, ti, hf_icep_invocation_key, tvb, offset, &consumed_key, &str_key);
if ( consumed_key == -1 ) {
(*consumed) = -1;
return;
}
offset += consumed_key;
(*consumed) += consumed_key;
dissect_ice_string(pinfo, tree, ti, hf_icep_invocation_value, tvb, offset, &consumed_value, &str_value);
if ( consumed_value == -1 ) {
(*consumed) = -1;
return;
}
offset += consumed_value;
(*consumed) += consumed_value;
if (ti)
proto_item_set_len(ti, (consumed_key + consumed_value) + 1);
}
}
static void dissect_ice_params(packet_info *pinfo, proto_tree *tree, proto_item *item, tvbuff_t *tvb,
guint32 offset, gint32 *consumed)
{
gint32 size = 0;
gint tvb_data_remained = 0;
(*consumed) = 0;
if ( !tvb_bytes_exist(tvb, offset, ICEP_MIN_PARAMS_SIZE) ) {
if (item)
expert_add_info_format(pinfo, item, PI_MALFORMED, PI_ERROR, "params missing");
col_append_str(mypinfo->cinfo, COL_INFO, " (params missing)");
(*consumed) = -1;
return;
}
size = tvb_get_letohl(tvb, offset);
DBG1("params.size --> %d\n", size);
if ( size < ICEP_MIN_PARAMS_SIZE ) {
if (item)
expert_add_info_format(pinfo, item, PI_PROTOCOL, PI_WARN, "params size too small");
col_append_str(mypinfo->cinfo, COL_INFO, " (params size too small)");
(*consumed) = -1;
return;
}
if ( tree ) {
proto_tree_add_item(tree, hf_icep_params_size, tvb, offset, 4, ENC_LITTLE_ENDIAN);
offset += 4;
(*consumed) += 4;
proto_tree_add_item(tree, hf_icep_params_major, tvb, offset, 1, ENC_LITTLE_ENDIAN);
offset += 1;
(*consumed)++;
proto_tree_add_item(tree, hf_icep_params_minor, tvb, offset, 1, ENC_LITTLE_ENDIAN);
offset += 1;
(*consumed)++;
} else {
offset += 6;
(*consumed) += 6;
}
if( size == ICEP_MIN_PARAMS_SIZE )
return;
tvb_data_remained = tvb_reported_length_remaining(tvb, offset);
if ( tvb_data_remained < ( size - ICEP_MIN_PARAMS_SIZE ) ) {
if (item)
expert_add_info_format(pinfo, item, PI_PROTOCOL, PI_WARN, "missing encapsulated data (%d bytes)",
size - ICEP_MIN_PARAMS_SIZE - tvb_data_remained);
if ( check_col(mypinfo->cinfo, COL_INFO) ) {
col_append_fstr(mypinfo->cinfo, COL_INFO,
" (missing encapsulated data (%d bytes))",
size
- ICEP_MIN_PARAMS_SIZE
- tvb_data_remained);
}
(*consumed) = -1;
return;
}
if (tree) {
proto_tree_add_item(tree, hf_icep_params_encapsulated, tvb, offset, (size - ICEP_MIN_PARAMS_SIZE), ENC_LITTLE_ENDIAN);
}
(*consumed) += (size - ICEP_MIN_PARAMS_SIZE);
}
static void dissect_icep_request_common(tvbuff_t *tvb, guint32 offset,
packet_info *pinfo, proto_tree *icep_sub_tree, proto_item* icep_sub_item, gint32 *total_consumed)
{
gint32 consumed = 0;
char *namestr = NULL;
char *opstr = NULL;
(*total_consumed) = 0;
if ( !tvb_bytes_exist(tvb, offset, ICEP_MIN_COMMON_REQ_HEADER_SIZE) ) {
if (icep_sub_item)
expert_add_info_format(pinfo, icep_sub_item, PI_MALFORMED, PI_ERROR, "too short header");
col_append_str(mypinfo->cinfo, COL_INFO,
" (too short header)");
goto error;
}
dissect_ice_string(pinfo, icep_sub_tree, icep_sub_item, hf_icep_id_name, tvb, offset, &consumed, &namestr);
if ( consumed == -1 )
goto error;
offset += consumed; DBG1("consumed --> %d\n", consumed);
(*total_consumed) += consumed;
dissect_ice_string(pinfo, icep_sub_tree, icep_sub_item, hf_icep_id_category, tvb, offset, &consumed, NULL);
if ( consumed == -1 )
goto error;
offset += consumed; DBG1("consumed --> %d\n", consumed);
(*total_consumed) += consumed;
dissect_ice_facet(pinfo, icep_sub_tree, icep_sub_item, hf_icep_facet, tvb, offset, &consumed);
if ( consumed == -1 )
goto error;
offset += consumed; DBG1("consumed --> %d\n", consumed);
(*total_consumed) += consumed;
dissect_ice_string(pinfo, icep_sub_tree, icep_sub_item, hf_icep_operation, tvb, offset, &consumed, &opstr);
if ( consumed == -1 )
goto error;
else {
offset += consumed; DBG1("consumed --> %d\n", consumed);
(*total_consumed) += consumed;
if ( opstr && namestr ) {
DBG2("operation --> %s.%s()\n", namestr, opstr);
if ( check_col(mypinfo->cinfo, COL_INFO) ) {
col_append_fstr(mypinfo->cinfo, COL_INFO, " %s.%s()",
namestr, opstr);
}
opstr = NULL;
namestr = NULL;
}
}
if ( !tvb_bytes_exist(tvb, offset, 1) ) {
if (icep_sub_item)
expert_add_info_format(pinfo, icep_sub_item, PI_MALFORMED, PI_ERROR, "mode field missing");
col_append_str(mypinfo->cinfo, COL_INFO, " (mode field missing)");
goto error;
}
if (icep_sub_tree)
proto_tree_add_item(icep_sub_tree, hf_icep_mode, tvb, offset, 1, ENC_LITTLE_ENDIAN);
offset++; DBG0("consumed --> 1\n");
(*total_consumed)++;
dissect_ice_context(pinfo, icep_sub_tree, icep_sub_item, tvb, offset, &consumed);
if ( consumed == -1 )
goto error;
offset += consumed; DBG1("consumed --> %d\n", consumed);
(*total_consumed) += consumed;
dissect_ice_params(pinfo, icep_sub_tree, icep_sub_item, tvb, offset, &consumed);
if ( consumed == -1 )
goto error;
DBG1("consumed --> %d\n", consumed);
(*total_consumed) += consumed;
return;
error:
(*total_consumed) = -1;
}
static void dissect_icep_request(tvbuff_t *tvb, guint32 offset,
packet_info *pinfo, proto_tree *icep_tree, proto_item* icep_item)
{
proto_item *ti = NULL;
proto_tree *icep_sub_tree = NULL;
gint32 consumed = 0;
guint32 reqid = 0;
DBG0("dissect request\n");
if ( !tvb_bytes_exist(tvb, offset, 4) ) {
if (icep_item)
expert_add_info_format(pinfo, icep_item, PI_MALFORMED, PI_ERROR, "too short header");
col_append_str(mypinfo->cinfo, COL_INFO, " (too short header)");
return;
}
reqid = tvb_get_letohl(tvb, offset);
if (icep_tree) {
ti = proto_tree_add_text(icep_tree, tvb, offset, -1,
"Request Message Body");
icep_sub_tree = proto_item_add_subtree(ti, ett_icep_msg);
proto_tree_add_item(icep_sub_tree, hf_icep_request_id, tvb, offset, 4,
ENC_LITTLE_ENDIAN);
}
if ( reqid != 0 ) {
if ( check_col(mypinfo->cinfo, COL_INFO) ) {
col_append_fstr(mypinfo->cinfo, COL_INFO, "(%d):",
tvb_get_letohl(tvb, offset));
}
} else
col_append_str(mypinfo->cinfo, COL_INFO, "(oneway):");
offset += 4;
DBG0("consumed --> 4\n");
dissect_icep_request_common(tvb, offset, pinfo, icep_sub_tree, ti, &consumed);
if ( consumed == -1 )
return;
DBG1("consumed --> %d\n", consumed);
}
static void dissect_icep_batch_request(tvbuff_t *tvb, guint32 offset,
packet_info *pinfo, proto_tree *icep_tree, proto_item* icep_item)
{
proto_item *ti = NULL;
proto_tree *icep_sub_tree = NULL;
guint32 num_reqs = 0;
guint32 i = 0;
gint32 consumed = 0;
DBG0("dissect batch request\n");
if ( !tvb_bytes_exist(tvb, offset, 4) ) {
if (icep_item)
expert_add_info_format(pinfo, icep_item, PI_MALFORMED, PI_ERROR, "counter of batch requests missing");
col_append_str(mypinfo->cinfo, COL_INFO,
" (counter of batch requests missing)");
return;
}
num_reqs = tvb_get_letohl(tvb, offset);
offset += 4;
DBG1("batch_requests.count --> %d\n", num_reqs);
if ( num_reqs > icep_max_batch_requests ) {
if (icep_item)
expert_add_info_format(pinfo, icep_item, PI_PROTOCOL, PI_WARN, "too many batch requests (%d)", num_reqs);
if ( check_col(mypinfo->cinfo, COL_INFO) ) {
col_append_fstr(mypinfo->cinfo, COL_INFO,
" (too many batch requests, %d)",
num_reqs);
}
return;
}
if ( num_reqs == 0 ) {
if (icep_tree)
proto_tree_add_text(icep_tree, tvb, offset, -1,
"empty batch requests sequence");
col_append_str(mypinfo->cinfo, COL_INFO,
" (empty batch requests sequence)");
return;
}
col_append_str(mypinfo->cinfo, COL_INFO,
":");
for ( i = 0; i < num_reqs; i++ ) {
DBG1("looping through sequence of batch requests, loop #%d\n", i);
if (icep_tree) {
ti = proto_tree_add_text(icep_tree, tvb, offset, -1,
"Batch Request Message Body: #%d", i);
icep_sub_tree = proto_item_add_subtree(ti, ett_icep_msg);
}
if ( check_col(mypinfo->cinfo, COL_INFO) && (i != 0) ) {
col_append_str(mypinfo->cinfo, COL_INFO,
",");
}
dissect_icep_request_common(tvb, offset, pinfo, icep_sub_tree, ti, &consumed);
if ( consumed == -1 )
return;
if ( icep_tree && ti )
proto_item_set_len(ti, consumed);
offset += consumed;
DBG1("consumed --> %d\n", consumed);
}
}
static void dissect_icep_reply(tvbuff_t *tvb, guint32 offset,
packet_info *pinfo, proto_tree *icep_tree, proto_item* icep_item)
{
gint32 messageSize = 0;
guint32 tvb_data_remained = 0;
guint32 reported_reply_data = 0;
proto_item *ti = NULL;
proto_tree *icep_sub_tree = NULL;
DBG0("dissect reply\n");
if ( !tvb_bytes_exist(tvb, offset, ICEP_MIN_REPLY_SIZE) ) {
if (icep_item)
expert_add_info_format(pinfo, icep_item, PI_MALFORMED, PI_ERROR, "too short header");
col_append_str(mypinfo->cinfo, COL_INFO, " (too short header)");
return;
}
if (icep_tree) {
ti = proto_tree_add_text(icep_tree, tvb, offset, -1,
"Reply Message Body");
icep_sub_tree = proto_item_add_subtree(ti, ett_icep_msg);
proto_tree_add_item(icep_sub_tree, hf_icep_request_id, tvb, offset, 4,
ENC_LITTLE_ENDIAN);
}
if ( check_col(mypinfo->cinfo, COL_INFO) ) {
col_append_fstr(mypinfo->cinfo, COL_INFO, "(%d):",
tvb_get_letohl(tvb, offset));
}
offset += 4;
if (icep_tree)
proto_tree_add_item(icep_sub_tree, hf_icep_reply_status, tvb, offset, 1,
ENC_LITTLE_ENDIAN);
if ( check_col(mypinfo->cinfo, COL_INFO) ) {
col_append_fstr(mypinfo->cinfo, COL_INFO, " %s",
val_to_str_const(tvb_get_guint8(tvb, offset),
icep_replystatus_vals,
"unknown reply status"));
}
offset++;
DBG1("consumed --> %d\n", 5);
tvb_data_remained = tvb_length_remaining(tvb, offset);
messageSize = tvb_get_letohl(tvb, 10);
reported_reply_data = messageSize - (ICEP_HEADER_SIZE + ICEP_MIN_REPLY_SIZE);
if ( tvb_data_remained < reported_reply_data ) {
if (icep_sub_tree)
expert_add_info_format(pinfo, ti, PI_MALFORMED, PI_ERROR, "Reply Data (missing %d bytes out of %d)",
reported_reply_data - tvb_data_remained,
reported_reply_data);
if ( check_col(mypinfo->cinfo, COL_INFO) ) {
col_append_fstr(mypinfo->cinfo, COL_INFO,
" (missing reply data, %d bytes)",
reported_reply_data - tvb_data_remained);
}
DBG1("consumed --> %d\n", tvb_data_remained);
return;
}
if (icep_sub_tree) {
proto_tree_add_item(icep_sub_tree, hf_icep_reply_data, tvb, offset, reported_reply_data, ENC_NA);
}
DBG1("consumed --> %d\n", reported_reply_data);
}
static guint get_icep_pdu_len(packet_info *pinfo _U_, tvbuff_t *tvb, int offset)
{
return tvb_get_letohl(tvb, offset + 10);
}
static void dissect_icep_pdu(tvbuff_t *tvb, packet_info *pinfo, proto_tree *tree)
{
proto_item *ti = NULL;
proto_tree *icep_tree = NULL;
guint32 offset = 0;
col_set_str(pinfo->cinfo, COL_PROTOCOL, "ICEP");
if ( check_col(pinfo->cinfo, COL_INFO) ) {
col_add_str(pinfo->cinfo, COL_INFO,
val_to_str(tvb_get_guint8(tvb, 8),
icep_msgtype_vals,
"Unknown Message Type: 0x%02x"));
}
mypinfo = pinfo;
if (tree) {
DBG0("got an icep msg, start analysis\n");
ti = proto_tree_add_item(tree, proto_icep, tvb, 0, -1, ENC_NA);
icep_tree = proto_item_add_subtree(ti, ett_icep);
proto_tree_add_text(icep_tree, tvb, offset, 4,
"Magic Number: 'I','c','e','P'");
offset += 4;
proto_tree_add_item(icep_tree, hf_icep_protocol_major,
tvb, offset, 1, ENC_LITTLE_ENDIAN);
offset++;
proto_tree_add_item(icep_tree, hf_icep_protocol_minor,
tvb, offset, 1, ENC_LITTLE_ENDIAN);
offset++;
proto_tree_add_item(icep_tree, hf_icep_encoding_major,
tvb, offset, 1, ENC_LITTLE_ENDIAN);
offset++;
proto_tree_add_item(icep_tree, hf_icep_encoding_minor,
tvb, offset, 1, ENC_LITTLE_ENDIAN);
offset++;
proto_tree_add_item(icep_tree, hf_icep_message_type,
tvb, offset, 1, ENC_LITTLE_ENDIAN);
offset++;
proto_tree_add_item(icep_tree, hf_icep_compression_status,
tvb, offset, 1, ENC_LITTLE_ENDIAN);
offset++;
proto_tree_add_item(icep_tree, hf_icep_message_size,
tvb, offset, 4, ENC_LITTLE_ENDIAN);
offset += 4;
} else {
offset += ICEP_HEADER_SIZE;
}
switch(tvb_get_guint8(tvb, 8)) {
case 0x0:
DBG1("request message body: parsing %d bytes\n",
tvb_length_remaining(tvb, offset));
dissect_icep_request(tvb, offset, pinfo, icep_tree, ti);
break;
case 0x1:
DBG1("batch request message body: parsing %d bytes\n",
tvb_length_remaining(tvb, offset));
dissect_icep_batch_request(tvb, offset, pinfo, icep_tree, ti);
break;
case 0x2:
DBG1("reply message body: parsing %d bytes\n",
tvb_length_remaining(tvb, offset));
dissect_icep_reply(tvb, offset, pinfo, icep_tree, ti);
break;
case 0x3:
case 0x4:
break;
default:
if (tree)
expert_add_info_format(pinfo, ti, PI_PROTOCOL, PI_WARN, "Unknown Message Type: 0x%02x", tvb_get_guint8(tvb, 8));
break;
}
}
static gboolean dissect_icep_tcp(tvbuff_t *tvb, packet_info *pinfo, proto_tree *tree, void *data _U_)
{
DBG0("triggered\n");
if ( tvb_memeql(tvb, 0, icep_magic, 4) == -1 ) {
return FALSE;
}
tcp_dissect_pdus(tvb, pinfo, tree, TRUE, ICEP_HEADER_SIZE,
get_icep_pdu_len, dissect_icep_pdu);
return TRUE;
}
static gboolean dissect_icep_udp(tvbuff_t *tvb, packet_info *pinfo, proto_tree *tree, void *data _U_)
{
DBG0("triggered\n");
if ( tvb_memeql(tvb, 0, icep_magic, 4) == -1 ) {
return FALSE;
}
dissect_icep_pdu(tvb, pinfo, tree);
return TRUE;
}
void proto_register_icep(void)
{
module_t *icep_module;
static hf_register_info hf[] = {
{ &hf_icep_protocol_major,
{
"Protocol Major", "icep.protocol_major",
FT_INT8, BASE_DEC, NULL, 0x0,
"The protocol major version number", HFILL
}
},
{ &hf_icep_protocol_minor,
{
"Protocol Minor", "icep.protocol_minor",
FT_INT8, BASE_DEC, NULL, 0x0,
"The protocol minor version number", HFILL
}
},
{ &hf_icep_encoding_major,
{
"Encoding Major", "icep.encoding_major",
FT_INT8, BASE_DEC, NULL, 0x0,
"The encoding major version number", HFILL
}
},
{ &hf_icep_encoding_minor,
{
"Encoding Minor", "icep.encoding_minor",
FT_INT8, BASE_DEC, NULL, 0x0,
"The encoding minor version number", HFILL
}
},
{ &hf_icep_message_type,
{
"Message Type", "icep.message_type",
FT_INT8, BASE_DEC, VALS(icep_msgtype_vals), 0x0,
"The message type", HFILL
}
},
{ &hf_icep_compression_status,
{
"Compression Status", "icep.compression_status",
FT_INT8, BASE_DEC, VALS(icep_zipstatus_vals), 0x0,
"The compression status of the message", HFILL
}
},
{ &hf_icep_message_size,
{
"Message Size", "icep.message_status",
FT_INT32, BASE_DEC, NULL, 0x0,
"The size of the message in bytes, including the header",
HFILL
}
},
{ &hf_icep_request_id,
{
"Request Identifier", "icep.request_id",
FT_INT32, BASE_DEC, NULL, 0x0,
"The request identifier",
HFILL
}
},
{ &hf_icep_reply_status,
{
"Reply Status", "icep.protocol_major",
FT_INT8, BASE_DEC, VALS(icep_replystatus_vals), 0x0,
"The reply status", HFILL
}
},
{ &hf_icep_id_name,
{
"Object Identity Name", "icep.id.name",
FT_STRINGZ, BASE_NONE, NULL, 0x0,
"The object identity name", HFILL
}
},
{ &hf_icep_id_category,
{
"Object Identity Content", "icep.id.content",
FT_STRINGZ, BASE_NONE, NULL, 0x0,
"The object identity content", HFILL
}
},
{ &hf_icep_facet,
{
"Facet Name", "icep.facet",
FT_STRINGZ, BASE_NONE, NULL, 0x0,
"The facet name", HFILL
}
},
{ &hf_icep_operation,
{
"Operation Name", "icep.operation",
FT_STRINGZ, BASE_NONE, NULL, 0x0,
"The operation name", HFILL
}
},
{ &hf_icep_mode,
{
"Ice::OperationMode", "icep.operation_mode",
FT_INT8, BASE_DEC, VALS(icep_mode_vals), 0x0,
"A byte representing Ice::OperationMode", HFILL
}
},
{ &hf_icep_context,
{
"Invocation Context", "icep.context",
FT_STRINGZ, BASE_NONE, NULL, 0x0,
"The invocation context", HFILL
}
},
{ &hf_icep_params_size,
{
"Input Parameters Size", "icep.params.size",
FT_INT32, BASE_DEC, NULL, 0x0,
"The encapsulated input parameters size",
HFILL
}
},
{ &hf_icep_params_major,
{
"Input Parameters Encoding Major",
"icep.params.major",
FT_INT8, BASE_DEC, NULL, 0x0,
"The major encoding version of encapsulated parameters",
HFILL
}
},
{ &hf_icep_params_minor,
{
"Input Parameters Encoding Minor",
"icep.params.minor",
FT_INT8, BASE_DEC, NULL, 0x0,
"The minor encoding version of encapsulated parameters",
HFILL
}
},
{ &hf_icep_params_encapsulated,
{
"Encapsulated parameters",
"icep.params.encapsulated",
FT_BYTES, BASE_NONE, NULL, 0x0,
"Remaining encapsulated parameters",
HFILL
}
},
{ &hf_icep_reply_data,
{
"Reported reply data",
"icep.params.reply_data",
FT_BYTES, BASE_NONE, NULL, 0x0, NULL, HFILL
}
},
{ &hf_icep_invocation_key,
{
"Key",
"icep.invocation_key",
FT_STRING, BASE_NONE, NULL, 0x0, NULL, HFILL
}
},
{ &hf_icep_invocation_value,
{
"Value",
"icep.invocation_value",
FT_STRING, BASE_NONE, NULL, 0x0, NULL, HFILL
}
},
};
static gint *ett[] = {
&ett_icep,
&ett_icep_msg,
};
proto_icep =
proto_register_protocol("Internet Communications Engine Protocol",
"ICEP", "icep");
proto_register_field_array(proto_icep, hf, array_length(hf));
proto_register_subtree_array(ett, array_length(ett));
icep_module = prefs_register_protocol(proto_icep, NULL);
prefs_register_uint_preference(icep_module, "tcp.port",
"ICEP TCP Port",
"ICEP TCP port",
10,
&icep_tcp_port);
prefs_register_uint_preference(icep_module, "udp.port",
"ICEP UDP Port",
"ICEP UDP port",
10,
&icep_udp_port);
prefs_register_uint_preference(icep_module, "max_batch_requests",
"Maximum batch requests",
"Maximum number of batch requests allowed",
10, &icep_max_batch_requests);
prefs_register_uint_preference(icep_module, "max_ice_string_len",
"Maximum string length",
"Maximum length allowed of an ICEP string",
10, &icep_max_ice_string_len);
prefs_register_uint_preference(icep_module, "max_ice_context_pairs",
"Maximum context pairs",
"Maximum number of context pairs allowed",
10, &icep_max_ice_context_pairs);
}
void proto_reg_handoff_icep(void)
{
static gboolean icep_prefs_initialized = FALSE;
static dissector_handle_t icep_tcp_handle, icep_udp_handle;
static guint old_icep_tcp_port = 0;
static guint old_icep_udp_port = 0;
if (icep_prefs_initialized == FALSE) {
icep_tcp_handle = new_create_dissector_handle(dissect_icep_tcp, proto_icep);
icep_udp_handle = new_create_dissector_handle(dissect_icep_udp, proto_icep);
heur_dissector_add("tcp", dissect_icep_tcp, proto_icep);
heur_dissector_add("udp", dissect_icep_udp, proto_icep);
icep_prefs_initialized = TRUE;
}
if(old_icep_tcp_port != 0 && old_icep_tcp_port != icep_tcp_port){
dissector_delete_uint("tcp.port", old_icep_tcp_port, icep_tcp_handle);
}
if(icep_tcp_port != 0 && old_icep_tcp_port != icep_tcp_port) {
dissector_add_uint("tcp.port", icep_tcp_port, icep_tcp_handle);
}
old_icep_tcp_port = icep_tcp_port;
if(old_icep_udp_port != 0 && old_icep_udp_port != icep_udp_port){
dissector_delete_uint("udp.port", old_icep_udp_port, icep_udp_handle);
}
if(icep_udp_port != 0 && old_icep_udp_port != icep_udp_port) {
dissector_add_uint("udp.port", old_icep_udp_port, icep_udp_handle);
}
old_icep_udp_port = icep_udp_port;
}
