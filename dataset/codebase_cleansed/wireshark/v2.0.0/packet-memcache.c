static guint
get_memcache_pdu_len (packet_info *pinfo _U_, tvbuff_t *tvb,
int offset, void *data _U_)
{
guint32 body_len;
body_len = tvb_get_ntohl(tvb, offset+8);
return body_len + MEMCACHE_HEADER_LEN;
}
static void
dissect_extras (tvbuff_t *tvb, packet_info *pinfo, proto_tree *tree,
gint offset, guint8 extras_len, guint8 opcode, gboolean request)
{
proto_tree *extras_tree = NULL;
proto_item *extras_item = NULL, *ti;
gint save_offset = offset;
gboolean illegal = FALSE;
gboolean missing = FALSE;
if (extras_len) {
extras_item = proto_tree_add_item (tree, hf_extras, tvb, offset, extras_len, ENC_NA);
extras_tree = proto_item_add_subtree (extras_item, ett_extras);
}
switch (opcode) {
case OP_GET:
case OP_GET_Q:
case OP_GET_K:
case OP_GET_K_Q:
if (extras_len) {
if (request) {
illegal = TRUE;
} else {
proto_tree_add_item (extras_tree, hf_extras_flags, tvb, offset, 4, ENC_BIG_ENDIAN);
offset += 4;
}
} else if (!request) {
missing = TRUE;
}
break;
case OP_SET:
case OP_SET_Q:
case OP_ADD:
case OP_ADD_Q:
case OP_REPLACE:
case OP_REPLACE_Q:
if (extras_len) {
if (request) {
proto_tree_add_item (extras_tree, hf_extras_flags, tvb, offset, 4, ENC_BIG_ENDIAN);
offset += 4;
proto_tree_add_item (extras_tree, hf_extras_expiration, tvb, offset, 4, ENC_BIG_ENDIAN);
offset += 4;
} else {
illegal = TRUE;
}
} else if (request) {
missing = TRUE;
}
break;
case OP_INCREMENT:
case OP_INCREMENT_Q:
case OP_DECREMENT:
case OP_DECREMENT_Q:
if (extras_len) {
if (request) {
proto_tree_add_item (extras_tree, hf_extras_delta, tvb, offset, 8, ENC_BIG_ENDIAN);
offset += 8;
proto_tree_add_item (extras_tree, hf_extras_initial, tvb, offset, 8, ENC_BIG_ENDIAN);
offset += 8;
proto_tree_add_item (extras_tree, hf_extras_expiration, tvb, offset, 4, ENC_BIG_ENDIAN);
offset += 4;
} else {
illegal = TRUE;
}
} else if (request) {
missing = TRUE;
}
break;
case OP_FLUSH:
case OP_FLUSH_Q:
if (extras_len) {
proto_tree_add_item (extras_tree, hf_extras_expiration, tvb, offset, 4, ENC_BIG_ENDIAN);
offset += 4;
}
break;
case OP_DELETE:
case OP_DELETE_Q:
case OP_QUIT:
case OP_QUIT_Q:
case OP_VERSION:
case OP_APPEND:
case OP_APPEND_Q:
case OP_PREPEND:
case OP_PREPEND_Q:
case OP_STAT:
if (extras_len) {
illegal = TRUE;
}
break;
default:
if (extras_len) {
proto_tree_add_item (extras_tree, hf_extras_unknown, tvb, offset, extras_len, ENC_NA);
offset += extras_len;
}
break;
}
if (illegal) {
ti = proto_tree_add_item (extras_tree, hf_extras_unknown, tvb, offset, extras_len, ENC_NA);
expert_add_info_format(pinfo, ti, &ei_extras_unknown, "%s %s shall not have Extras",
val_to_str (opcode, opcode_vals, "Opcode %d"),
request ? "Request" : "Response");
offset += extras_len;
} else if (missing) {
proto_tree_add_expert_format(tree, pinfo, &ei_extras_missing, tvb, offset, 0, "%s %s must have Extras",
val_to_str (opcode, opcode_vals, "Opcode %d"),
request ? "Request" : "Response");
}
if ((offset - save_offset) != extras_len) {
expert_add_info_format(pinfo, extras_item, &ei_extras_unknown, "Illegal Extras length, should be %d", offset - save_offset);
}
}
static void
dissect_key (tvbuff_t *tvb, packet_info *pinfo, proto_tree *tree,
gint offset, int key_len, guint8 opcode, gboolean request)
{
proto_item *ti = NULL;
gboolean illegal = FALSE;
gboolean missing = FALSE;
if (key_len) {
ti = proto_tree_add_item (tree, hf_key, tvb, offset, key_len, ENC_ASCII|ENC_NA);
offset += key_len;
if ((opcode == OP_QUIT) || (opcode == OP_QUIT_Q) || (opcode == OP_NO_OP) || (opcode == OP_VERSION)) {
illegal = TRUE;
}
if ((opcode == OP_SET) || (opcode == OP_ADD) || (opcode == OP_REPLACE) || (opcode == OP_DELETE) ||
(opcode == OP_SET_Q) || (opcode == OP_ADD_Q) || (opcode == OP_REPLACE_Q) || (opcode == OP_DELETE_Q) ||
(opcode == OP_FLUSH) || (opcode == OP_APPEND) || (opcode == OP_PREPEND) ||
(opcode == OP_FLUSH_Q) || (opcode == OP_APPEND_Q) || (opcode == OP_PREPEND_Q))
{
if (!request) {
illegal = TRUE;
}
}
} else {
if ((opcode == OP_GET) || (opcode == OP_GET_Q) || (opcode == OP_GET_K) || (opcode == OP_GET_K_Q) ||
(opcode == OP_SET) || (opcode == OP_ADD) || (opcode == OP_REPLACE) || (opcode == OP_DELETE) ||
(opcode == OP_SET_Q) || (opcode == OP_ADD_Q) || (opcode == OP_REPLACE_Q) || (opcode == OP_DELETE_Q) ||
(opcode == OP_INCREMENT) || (opcode == OP_DECREMENT) || (opcode == OP_INCREMENT_Q) || (opcode == OP_DECREMENT_Q))
{
if (request) {
missing = TRUE;
}
}
}
if (illegal) {
expert_add_info_format(pinfo, ti, &ei_key_unknown, "%s %s shall not have Key",
val_to_str (opcode, opcode_vals, "Opcode %d"),
request ? "Request" : "Response");
} else if (missing) {
proto_tree_add_expert_format(tree, pinfo, &ei_key_missing, tvb, offset, 0, "%s Request must have Key",
val_to_str (opcode, opcode_vals, "Opcode %d"));
}
}
static void
dissect_value (tvbuff_t *tvb, packet_info *pinfo, proto_tree *tree,
gint offset, guint32 value_len, guint8 opcode, gboolean request)
{
proto_item *ti = NULL;
gboolean illegal = FALSE;
gboolean missing = FALSE;
if (value_len > 0) {
if (!request && ((opcode == OP_INCREMENT) || (opcode == OP_DECREMENT))) {
ti = proto_tree_add_item (tree, hf_uint64_response, tvb, offset, 8, ENC_BIG_ENDIAN);
if (value_len != 8) {
expert_add_info_format(pinfo, ti, &ei_value_length, "Illegal Value length, should be 8");
}
} else {
ti = proto_tree_add_item (tree, hf_value, tvb, offset, value_len, ENC_ASCII|ENC_NA);
}
offset += value_len;
}
if (value_len) {
if ((opcode == OP_GET) || (opcode == OP_GET_Q) || (opcode == OP_GET_K) || (opcode == OP_GET_K_Q) ||
(opcode == OP_INCREMENT) || (opcode == OP_DECREMENT) || (opcode == OP_VERSION) ||
(opcode == OP_INCREMENT_Q) || (opcode == OP_DECREMENT_Q))
{
if (request) {
illegal = TRUE;
}
}
if ((opcode == OP_DELETE) || (opcode == OP_QUIT) || (opcode == OP_FLUSH) || (opcode == OP_NO_OP) ||
(opcode == OP_DELETE_Q) || (opcode == OP_QUIT_Q) || (opcode == OP_FLUSH_Q))
{
illegal = TRUE;
}
if ((opcode == OP_SET) || (opcode == OP_ADD) || (opcode == OP_REPLACE) ||
(opcode == OP_SET_Q) || (opcode == OP_ADD_Q) || (opcode == OP_REPLACE_Q) ||
(opcode == OP_APPEND) || (opcode == OP_PREPEND) || (opcode == OP_APPEND_Q) || (opcode == OP_PREPEND_Q))
{
if (!request) {
illegal = TRUE;
}
}
} else {
if ((opcode == OP_SET) || (opcode == OP_ADD) || (opcode == OP_REPLACE) ||
(opcode == OP_SET_Q) || (opcode == OP_ADD_Q) || (opcode == OP_REPLACE_Q) ||
(opcode == OP_APPEND) || (opcode == OP_PREPEND) || (opcode == OP_APPEND_Q) || (opcode == OP_PREPEND_Q))
{
if (request) {
missing = TRUE;
}
}
}
if (illegal) {
expert_add_info_format(pinfo, ti, &ei_value_unknown, "%s %s shall not have Value",
val_to_str (opcode, opcode_vals, "Opcode %d"),
request ? "Request" : "Response");
} else if (missing) {
proto_tree_add_expert_format(tree, pinfo, &ei_value_missing, tvb, offset, 0, "%s %s must have Value",
val_to_str (opcode, opcode_vals, "Opcode %d"),
request ? "Request" : "Response");
}
}
static int
dissect_memcache (tvbuff_t *tvb, packet_info *pinfo, proto_tree *tree, void* data _U_)
{
proto_tree *memcache_tree;
proto_item *memcache_item, *ti;
gint offset = 0;
guint8 magic, opcode, extras_len;
guint16 key_len, status = 0;
guint32 body_len, value_len;
gboolean request;
col_set_str (pinfo->cinfo, COL_PROTOCOL, PSNAME);
col_clear (pinfo->cinfo, COL_INFO);
memcache_item = proto_tree_add_item (tree, proto_memcache, tvb, offset, -1, ENC_NA);
memcache_tree = proto_item_add_subtree (memcache_item, ett_memcache);
magic = tvb_get_guint8 (tvb, offset);
ti = proto_tree_add_item (memcache_tree, hf_magic, tvb, offset, 1, ENC_BIG_ENDIAN);
offset += 1;
if (try_val_to_str (magic, magic_vals) == NULL) {
expert_add_info_format(pinfo, ti, &ei_magic_unknown, "Unknown magic byte: %d", magic);
}
opcode = tvb_get_guint8 (tvb, offset);
ti = proto_tree_add_item (memcache_tree, hf_opcode, tvb, offset, 1, ENC_BIG_ENDIAN);
offset += 1;
if (try_val_to_str (opcode, opcode_vals) == NULL) {
expert_add_info_format(pinfo, ti, &ei_opcode_unknown, "Unknown opcode: %d", opcode);
}
proto_item_append_text (memcache_item, ", %s %s", val_to_str (opcode, opcode_vals, "Unknown opcode (%d)"),
val_to_str (magic, magic_vals, "Unknown magic (%d)"));
col_append_fstr (pinfo->cinfo, COL_INFO, "%s %s",
val_to_str (opcode, opcode_vals, "Unknown opcode (%d)"),
val_to_str (magic, magic_vals, "Unknown magic (%d)"));
key_len = tvb_get_ntohs (tvb, offset);
proto_tree_add_item (memcache_tree, hf_key_length, tvb, offset, 2, ENC_BIG_ENDIAN);
offset += 2;
extras_len = tvb_get_guint8 (tvb, offset);
proto_tree_add_item (memcache_tree, hf_extras_length, tvb, offset, 1, ENC_BIG_ENDIAN);
offset += 1;
proto_tree_add_item (memcache_tree, hf_data_type, tvb, offset, 1, ENC_BIG_ENDIAN);
offset += 1;
status = tvb_get_ntohs (tvb, offset);
if (magic & 0x01) {
request = FALSE;
ti = proto_tree_add_item (memcache_tree, hf_status, tvb, offset, 2, ENC_BIG_ENDIAN);
if (status != 0) {
expert_add_info_format(pinfo, ti, &ei_status_response, "%s: %s",
val_to_str (opcode, opcode_vals, "Unknown opcode (%d)"),
val_to_str (status, status_vals, "Status: %d"));
}
} else {
request = TRUE;
ti = proto_tree_add_item (memcache_tree, hf_reserved, tvb, offset, 2, ENC_BIG_ENDIAN);
if (status != 0) {
expert_add_info_format(pinfo, ti, &ei_reserved_value, "Reserved value: %d", status);
}
}
offset += 2;
body_len = tvb_get_ntohl (tvb, offset);
value_len = body_len - extras_len - key_len;
ti = proto_tree_add_uint (memcache_tree, hf_value_length, tvb, offset, 0, value_len);
PROTO_ITEM_SET_GENERATED (ti);
proto_tree_add_item (memcache_tree, hf_total_body_length, tvb, offset, 4, ENC_BIG_ENDIAN);
offset += 4;
proto_tree_add_item (memcache_tree, hf_opaque, tvb, offset, 4, ENC_BIG_ENDIAN);
offset += 4;
proto_tree_add_item (memcache_tree, hf_cas, tvb, offset, 8, ENC_BIG_ENDIAN);
offset += 8;
if (status == 0) {
dissect_extras (tvb, pinfo, memcache_tree, offset, extras_len, opcode, request);
offset += extras_len;
dissect_key (tvb, pinfo, memcache_tree, offset, key_len, opcode, request);
offset += key_len;
dissect_value (tvb, pinfo, memcache_tree, offset, value_len, opcode, request);
} else if (body_len) {
proto_tree_add_item (memcache_tree, hf_value, tvb, offset, body_len, ENC_ASCII|ENC_NA);
col_append_fstr (pinfo->cinfo, COL_INFO, " (%s)",
val_to_str (status, status_vals, "Unknown status: %d"));
} else {
proto_tree_add_expert_format(memcache_tree, pinfo, &ei_value_missing, tvb, offset, 0, "%s with status %s (%d) must have Value",
val_to_str (opcode, opcode_vals, "Opcode %d"),
val_to_str_const (status, status_vals, "Unknown"), status);
}
return tvb_captured_length(tvb);
}
static gboolean
get_payload_length (tvbuff_t *tvb, const int token_number, int offset,
guint32 *bytes, gboolean *content_length_found)
{
const guchar *next_token;
const guchar *line, *lineend;
guchar *bytes_val;
int tokenlen, i = 0, linelen;
gint next_offset;
linelen = tvb_find_line_end (tvb, offset, -1, &next_offset,
FALSE);
if (linelen < 0) {
return FALSE;
}
line = tvb_get_ptr (tvb, offset, linelen);
lineend = line + linelen;
while (++i < token_number) {
tokenlen = get_token_len (line, lineend, &next_token);
if (tokenlen == 0) {
return FALSE;
}
offset += (int) (next_token - line);
line = next_token;
}
tokenlen = get_token_len (line, lineend, &next_token);
if (tokenlen == 0) {
return FALSE;
}
bytes_val = tvb_get_string_enc(wmem_packet_scope(), tvb, offset, tokenlen, ENC_ASCII);
if (bytes_val) {
if (sscanf (bytes_val, "%u", bytes) == 1) {
*content_length_found = TRUE;
} else {
return FALSE;
}
} else {
return FALSE;
}
return TRUE;
}
static gboolean
desegment_pdus (tvbuff_t *tvb, packet_info *pinfo, const int offset,
const int data_offset, guint32 content_length)
{
gint length_remaining, reported_length_remaining;
if (!tvb_bytes_exist (tvb, data_offset, content_length)) {
length_remaining = tvb_captured_length_remaining (tvb, data_offset);
reported_length_remaining = tvb_reported_length_remaining (tvb, data_offset);
if (length_remaining < reported_length_remaining) {
return FALSE;
}
if (length_remaining == -1) {
length_remaining = 0;
}
pinfo->desegment_offset = offset;
pinfo->desegment_len = (content_length + 2) - length_remaining;
return TRUE;
}
return FALSE;
}
static gboolean
memcache_req_resp_hdrs_do_reassembly (
tvbuff_t *tvb, const int offset, packet_info *pinfo,
const gboolean desegment_headers, const gboolean desegment_body,
const memcache_type_t type, const int expect_content_length)
{
int linelen;
gint next_offset;
gint length_remaining;
gint reported_length_remaining;
guint32 content_length = 0;
gboolean content_length_found = FALSE;
gboolean ret = FALSE;
if (desegment_headers && pinfo->can_desegment) {
next_offset = offset;
reported_length_remaining = tvb_reported_length_remaining (tvb, next_offset);
if (reported_length_remaining < 1) {
pinfo->desegment_offset = offset;
pinfo->desegment_len = DESEGMENT_ONE_MORE_SEGMENT;
return FALSE;
}
length_remaining = tvb_captured_length_remaining (tvb, next_offset);
linelen = tvb_find_line_end (tvb, next_offset, -1, &next_offset, TRUE);
if (linelen == -1 && length_remaining >= reported_length_remaining) {
pinfo->desegment_offset = offset;
pinfo->desegment_len = DESEGMENT_ONE_MORE_SEGMENT;
return FALSE;
}
if (expect_content_length == TRUE) {
switch (type) {
case MEMCACHE_REQUEST:
ret = get_payload_length (tvb, 5 , offset, &content_length, &content_length_found);
if (!ret) {
return FALSE;
}
break;
case MEMCACHE_RESPONSE:
ret = get_payload_length (tvb, 4 , offset, &content_length, &content_length_found);
if (!ret) {
return FALSE;
}
break;
default:
return FALSE;
}
}
}
if (desegment_body && content_length_found) {
return !desegment_pdus (tvb, pinfo, offset, next_offset, content_length);
}
return TRUE;
}
static int
dissect_memcache_message (tvbuff_t *tvb, int offset, packet_info *pinfo, proto_tree *tree)
{
const guchar *line;
const guchar *lineend;
int orig_offset;
int first_linelen;
int datalen;
int expect_content_length = FALSE;
gint next_offset;
gboolean is_request_or_reply;
memcache_type_t memcache_type;
ReqRespDissector reqresp_dissector = NULL;
proto_tree *memcache_tree = NULL;
proto_item *memcache_item = NULL;
guint8 opcode = 0xff;
first_linelen = tvb_find_line_end (tvb, offset, -1, &next_offset,
FALSE);
if (first_linelen < 0) {
return -1;
}
line = tvb_get_ptr (tvb, offset, first_linelen);
lineend = line + first_linelen;
memcache_type = MEMCACHE_UNKNOWN;
is_request_or_reply =
is_memcache_request_or_reply ((const gchar *)line,
first_linelen, &opcode, &memcache_type,
&expect_content_length, &reqresp_dissector);
if (is_request_or_reply) {
if (!memcache_req_resp_hdrs_do_reassembly (tvb, offset, pinfo, memcache_desegment_headers,
memcache_desegment_body, memcache_type,
expect_content_length))
{
return -1;
}
}
col_set_str (pinfo->cinfo, COL_PROTOCOL, PSNAME);
if (is_request_or_reply) {
line = tvb_get_ptr (tvb, offset, first_linelen);
col_add_fstr (pinfo->cinfo, COL_INFO, "%s ",
format_text (line, first_linelen));
} else {
col_set_str (pinfo->cinfo, COL_INFO, "MEMCACHE Continuation");
}
orig_offset = offset;
memcache_item = proto_tree_add_item (tree, proto_memcache, tvb, offset, -1, ENC_NA);
memcache_tree = proto_item_add_subtree (memcache_item, ett_memcache);
if (tvb_reported_length_remaining (tvb, offset) != 0) {
if (is_request_or_reply && reqresp_dissector) {
next_offset = reqresp_dissector (tvb, pinfo, memcache_tree,
offset, line, lineend, opcode);
if (next_offset == -1) {
return -1;
}
offset = next_offset;
}
}
datalen = tvb_captured_length_remaining (tvb, offset);
if (datalen > 0) {
offset += datalen;
}
return offset - orig_offset;
}
static int
content_data_dissector (tvbuff_t *tvb, packet_info *pinfo, proto_tree *tree, int offset,
int content_length, guint8 opcode)
{
gint datalen;
gboolean short_pkt = FALSE;
if (tvb_reported_length_remaining (tvb, offset) != 0) {
datalen = tvb_captured_length_remaining (tvb, offset);
if (content_length >= 0) {
if (datalen >= (content_length + 2)) {
datalen = content_length;
} else {
short_pkt = TRUE;
}
}
dissect_value (tvb, pinfo, tree, offset, datalen, opcode, TRUE);
if (datalen > 0) {
if (!short_pkt) {
offset += (datalen + 2);
} else {
offset += datalen;
}
}
}
return offset;
}
static guint
find_stat_colon (const guchar *line, const guchar *lineend,
const guchar **first_colon, const guchar **last_colon)
{
const guchar *linep, *temp;
guint occurrences = 0;
guchar c;
linep = line;
while (linep < lineend) {
temp = linep;
c = *linep++;
switch (c) {
case ':':
occurrences++;
if (occurrences == 1) {
*first_colon = temp;
} else if (occurrences == 2) {
*last_colon = temp;
} else {
return occurrences;
}
break;
default:
break;
}
}
return occurrences;
}
static int
incr_dissector (tvbuff_t *tvb, proto_tree *tree, int offset)
{
gint next_offset;
int linelen;
const guchar *line, *lineend;
const guchar *next_token;
int tokenlen;
if (tvb_offset_exists (tvb, offset)) {
linelen = tvb_find_line_end (tvb, offset, -1, &next_offset, FALSE);
if (linelen < 0) {
return -1;
}
line = tvb_get_ptr (tvb, offset, linelen);
lineend = line + linelen;
tokenlen = get_token_len (line, lineend, &next_token);
if (tokenlen == 0) {
return -1;
}
proto_tree_add_item (tree, hf_uint64_response, tvb, offset, tokenlen, ENC_BIG_ENDIAN);
tokenlen = get_token_len (line, lineend, &next_token);
if (tokenlen == 0) {
return next_offset;
} else {
return -1;
}
}
return offset;
}
static int
stat_dissector (tvbuff_t *tvb, proto_tree *tree, int offset)
{
guint occurrences = 0;
const guchar *first_colon = NULL, *last_colon = NULL;
int tokenlen, linelen;
gint next_offset;
const guchar *next_token;
const guchar *line, *lineend;
guint32 slabclass;
guchar response_chars[21];
while (tvb_offset_exists (tvb, offset)) {
linelen = tvb_find_line_end (tvb, offset, -1, &next_offset,
FALSE);
if (linelen < 0) {
return -1;
}
line = tvb_get_ptr (tvb, offset, linelen);
lineend = line + linelen;
tokenlen = get_token_len (line, lineend, &next_token);
if ((tokenlen == 4) && strncmp (line, "STAT", tokenlen) == 0) {
proto_tree_add_item (tree, hf_command, tvb, offset, tokenlen, ENC_ASCII|ENC_NA);
offset += (int) (next_token - line);
line = next_token;
occurrences = find_stat_colon (line, lineend, &first_colon, &last_colon);
} else if ((tokenlen == 3) && strncmp (line, "END", tokenlen) == 0) {
offset += (int) (next_token - line);
return offset;
} else {
return -1;
}
switch (occurrences) {
case 2:
tokenlen = (int) (first_colon - line);
proto_tree_add_item (tree, hf_subcommand, tvb, offset, tokenlen, ENC_ASCII|ENC_NA);
offset += tokenlen + 1;
tokenlen = (int) (last_colon - first_colon - 1);
if (tokenlen > 10 || tokenlen <= 0) {
return -1;
}
memcpy (response_chars, first_colon + 1, tokenlen);
response_chars[tokenlen] = '\0';
slabclass = (guint32) strtoul (response_chars, NULL, 10);
proto_tree_add_uint (tree, hf_slabclass, tvb, offset, tokenlen, slabclass);
offset += tokenlen + 1;
line = last_colon + 1;
break;
case 1:
tokenlen = (int) (first_colon - line);
if (tokenlen > 10 || tokenlen <= 0) {
return -1;
}
memcpy (response_chars, line, tokenlen);
response_chars[tokenlen] = '\0';
slabclass = (guint32) strtoul (response_chars, NULL, 10);
proto_tree_add_uint (tree, hf_slabclass, tvb, offset, tokenlen, slabclass);
offset += (int) (tokenlen + 1);
line = first_colon + 1;
break;
case 0:
break;
default:
return -1;
}
tokenlen = get_token_len (line, lineend, &next_token);
if (tokenlen == 0) {
return -1;
}
proto_tree_add_item (tree, hf_name, tvb, offset, tokenlen, ENC_ASCII|ENC_NA);
offset += (int) (next_token - line);
line = next_token;
tokenlen = get_token_len (line, lineend, &next_token);
if (tokenlen == 0) {
return -1;
}
proto_tree_add_item (tree, hf_name_value, tvb, offset, tokenlen, ENC_ASCII|ENC_NA);
offset = next_offset;
}
return offset;
}
static int
get_response_dissector (tvbuff_t *tvb, packet_info *pinfo, proto_tree *tree, int offset)
{
gint next_offset;
int linelen;
const guchar *line, *lineend;
const guchar *next_token;
int tokenlen;
guint16 flags;
guint32 bytes;
guint64 cas;
guint8 opcode = 0xff;
gchar response_chars[21];
while (tvb_offset_exists (tvb, offset)) {
linelen = tvb_find_line_end (tvb, offset, -1, &next_offset,
FALSE);
if (linelen < 0) {
return -1;
}
line = tvb_get_ptr (tvb, offset, linelen);
lineend = line + linelen;
tokenlen = get_token_len (line, lineend, &next_token);
if (tokenlen == 0) {
return -1;
}
if ((tokenlen == 5) && strncmp (line, "VALUE", tokenlen) == 0) {
} else if ((tokenlen == 3) && strncmp (line, "END", tokenlen) == 0) {
offset += (int) (next_token - line);
return offset;
} else {
return -1;
}
offset += (int) (next_token - line);
line = next_token;
tokenlen = get_token_len (line, lineend, &next_token);
if (tokenlen == 0) {
return -1;
}
dissect_key (tvb, pinfo, tree, offset, tokenlen, opcode, TRUE);
offset += (int) (next_token - line);
line = next_token;
tokenlen = get_token_len (line, lineend, &next_token);
if (tokenlen == 0 || tokenlen > 5) {
return -1;
}
memcpy (response_chars, line, tokenlen);
response_chars[tokenlen] = '\0';
flags = (guint16) strtoul (response_chars, NULL, 10);
proto_tree_add_uint (tree, hf_flags, tvb, offset, tokenlen, flags);
offset += (int) (next_token - line);
line = next_token;
tokenlen = get_token_len (line, lineend, &next_token);
if (tokenlen == 0 || tokenlen > 10) {
return -1;
}
memcpy (response_chars, line, tokenlen);
response_chars[tokenlen] = '\0';
bytes = (guint32) strtoul (response_chars, NULL, 10);
proto_tree_add_uint (tree, hf_value_length, tvb, offset, tokenlen, bytes);
offset += (int) (next_token - line);
line = next_token;
tokenlen = get_token_len (line, lineend, &next_token);
if (tokenlen > 20) {
return -1;
}
if (tokenlen != 0) {
memcpy (response_chars, line, tokenlen);
response_chars[tokenlen] = '\0';
cas = (guint64) strtoul (response_chars, NULL, 10);
proto_tree_add_uint64 (tree, hf_cas, tvb, offset, tokenlen, cas);
tokenlen = get_token_len (line, lineend, &next_token);
if (tokenlen != 0) {
return -1;
}
}
offset = next_offset;
offset = content_data_dissector (tvb, pinfo, tree, offset, bytes, opcode);
if (offset == -1) {
return offset;
}
}
return offset;
}
static int
memcache_response_dissector (tvbuff_t *tvb, packet_info *pinfo, proto_tree *tree, int offset,
const guchar *line, const guchar *lineend, guint8 opcode)
{
const guchar *next_token;
int tokenlen;
switch (opcode) {
case OP_GET:
case OP_GETS:
return get_response_dissector (tvb, pinfo, tree, offset);
case OP_VERSION:
tokenlen = get_token_len (line, lineend, &next_token);
if (tokenlen == 0) {
return -1;
}
if ((tokenlen == 7) && strncmp (line, "VERSION", tokenlen) == 0) {
offset += (int) (next_token - line);
line = next_token;
} else {
return -1;
}
tokenlen = get_token_len (line, lineend, &next_token);
if (tokenlen == 0) {
return -1;
}
proto_tree_add_item (tree, hf_version, tvb, offset, tokenlen, ENC_ASCII|ENC_NA);
offset += (int) (next_token - line);
line = next_token;
tokenlen = get_token_len (line, lineend, &next_token);
if (tokenlen != 0) {
return -1;
}
return offset;
case OP_STAT:
return stat_dissector (tvb, tree, offset);
default:
break;
}
tokenlen = get_token_len (line, lineend, &next_token);
if (tokenlen == 0) {
return -1;
}
if ((tokenlen == 6 && strncmp (line, "STORED", tokenlen) == 0) ||
(tokenlen == 10 && strncmp (line, "NOT_STORED", tokenlen) == 0) ||
(tokenlen == 6 && strncmp (line, "EXISTS", tokenlen) == 0) ||
(tokenlen == 9 && strncmp (line, "NOT_FOUND", tokenlen) == 0) ||
(tokenlen == 7 && strncmp (line, "DELETED", tokenlen) == 0) ||
(tokenlen == 2 && strncmp (line, "OK", tokenlen) == 0) ||
(tokenlen == 3 && strncmp (line, "END", tokenlen) == 0))
{
proto_tree_add_item (tree, hf_response, tvb, offset, tokenlen, ENC_ASCII|ENC_NA);
offset += (int) (next_token - line);
return offset;
}
if (opcode == OP_INCREMENT) {
return incr_dissector (tvb, tree, offset);
}
return offset;
}
static int
memcache_request_dissector (tvbuff_t *tvb, packet_info *pinfo, proto_tree *tree, int offset,
const guchar *line, const guchar *lineend, guint8 opcode)
{
const guchar *next_token;
int tokenlen;
guint16 flags;
guint32 expiration;
guint32 bytes;
guint64 cas;
gchar response_chars[21];
tokenlen = get_token_len (line, lineend, &next_token);
if (tokenlen == 0) {
return -1;
}
proto_tree_add_item (tree, hf_command, tvb, offset, tokenlen, ENC_ASCII|ENC_NA);
offset += (int) (next_token - line);
line = next_token;
switch (opcode) {
case OP_SET:
case OP_ADD:
case OP_REPLACE:
case OP_APPEND:
case OP_PREPEND:
case OP_CAS:
tokenlen = get_token_len (line, lineend, &next_token);
if (tokenlen == 0) {
return -1;
}
dissect_key (tvb, pinfo, tree, offset, tokenlen, opcode, TRUE);
offset += (int) (next_token - line);
line = next_token;
tokenlen = get_token_len (line, lineend, &next_token);
if (tokenlen == 0 || tokenlen > 5) {
return -1;
}
memcpy (response_chars, line, tokenlen);
response_chars[tokenlen] = '\0';
flags = (guint16) strtoul (response_chars, NULL, 10);
proto_tree_add_uint (tree, hf_flags, tvb, offset, tokenlen, flags);
offset += (int) (next_token - line);
line = next_token;
tokenlen = get_token_len (line, lineend, &next_token);
if (tokenlen == 0 || tokenlen > 10) {
return -1;
}
memcpy (response_chars, line, tokenlen);
response_chars[tokenlen] = '\0';
expiration = (guint32) strtoul (response_chars, NULL, 10);
proto_tree_add_uint (tree, hf_expiration, tvb, offset, tokenlen, expiration);
offset += (int) (next_token - line);
line = next_token;
tokenlen = get_token_len (line, lineend, &next_token);
if (tokenlen == 0 || tokenlen > 10) {
return -1;
}
memcpy (response_chars, line, tokenlen);
response_chars[tokenlen] = '\0';
bytes = (guint32) strtoul (response_chars, NULL, 10);
proto_tree_add_uint (tree, hf_value_length, tvb, offset, tokenlen, bytes);
offset += (int) (next_token - line);
line = next_token;
if (opcode == OP_CAS) {
tokenlen = get_token_len (line, lineend, &next_token);
if (tokenlen == 0 || tokenlen > 20) {
return -1;
}
memcpy (response_chars, line, tokenlen);
response_chars[tokenlen] = '\0';
cas = (guint64) strtoul (response_chars, NULL, 10);
proto_tree_add_uint64 (tree, hf_cas, tvb, offset, tokenlen, cas);
offset += (int) (next_token - line);
line = next_token;
}
tokenlen = get_token_len (line, lineend, &next_token);
if (tokenlen != 0) {
if (tokenlen == 7 && strncmp (line, "noreply", 7) == 0) {
proto_tree_add_item (tree, hf_noreply, tvb, offset, tokenlen, ENC_ASCII|ENC_NA);
}
offset += (int) (next_token - line);
}
offset += 2 ;
offset = content_data_dissector (tvb, pinfo, tree, offset, bytes, opcode);
if (offset == -1) {
return offset;
}
break;
case OP_INCREMENT:
case OP_DECREMENT:
tokenlen = get_token_len (line, lineend, &next_token);
if (tokenlen == 0) {
return -1;
}
dissect_key (tvb, pinfo, tree, offset, tokenlen, opcode, TRUE);
offset += (int) (next_token - line);
line = next_token;
tokenlen = get_token_len (line, lineend, &next_token);
if (tokenlen == 0) {
return -1;
}
proto_tree_add_item (tree, hf_value, tvb, offset, tokenlen, ENC_ASCII|ENC_NA);
offset += (int) (next_token - line);
line = next_token;
tokenlen = get_token_len (line, lineend, &next_token);
if (tokenlen == 0) {
return offset;
}
if (tokenlen == 7 && strncmp (line, "noreply", 7) == 0) {
proto_tree_add_item (tree, hf_noreply, tvb, offset, tokenlen, ENC_ASCII|ENC_NA);
offset += (int) (next_token - line);
line = next_token;
} else {
return -1;
}
tokenlen = get_token_len (line, lineend, &next_token);
if (tokenlen == 0) {
return offset;
} else {
return -1;
}
break;
case OP_DELETE:
tokenlen = get_token_len (line, lineend, &next_token);
if (tokenlen == 0) {
return -1;
}
dissect_key (tvb, pinfo, tree, offset, tokenlen, opcode, TRUE);
offset += (int) (next_token - line);
line = next_token;
tokenlen = get_token_len (line, lineend, &next_token);
if (tokenlen == 0) {
return offset;
}
if (tokenlen <= 10) {
if (tokenlen == 7 && strncmp (line, "noreply", 7) == 0) {
proto_tree_add_item (tree, hf_noreply, tvb, offset, tokenlen, ENC_ASCII|ENC_NA);
} else {
memcpy (response_chars, line, tokenlen);
response_chars[tokenlen] = '\0';
expiration = (guint32) strtoul (response_chars, NULL, 10);
proto_tree_add_uint (tree, hf_expiration, tvb, offset, tokenlen, expiration);
}
offset += (int) (next_token - line);
line = next_token;
} else {
return -1;
}
tokenlen = get_token_len (line, lineend, &next_token);
if (tokenlen == 0) {
return offset;
} else {
return -1;
}
break;
case OP_GET:
case OP_GETS:
while (tokenlen != 0) {
tokenlen = get_token_len (line, lineend, &next_token);
if (tokenlen == 0) {
return offset;
}
dissect_key (tvb, pinfo, tree, offset, tokenlen, opcode, TRUE);
offset += (int) (next_token - line);
line = next_token;
}
break;
case OP_STAT:
tokenlen = get_token_len (line, lineend, &next_token);
if (tokenlen == 0) {
return offset;
} else {
proto_tree_add_item (tree, hf_subcommand, tvb, offset, tokenlen, ENC_ASCII|ENC_NA);
offset += (int) (next_token - line);
line = next_token;
}
tokenlen = get_token_len (line, lineend, &next_token);
if (tokenlen == 0) {
return offset;
} else {
return -1;
}
break;
case OP_FLUSH:
tokenlen = get_token_len (line, lineend, &next_token);
if (tokenlen == 0) {
return offset;
}
if (tokenlen <= 10) {
if (tokenlen == 7 && strncmp (line, "noreply", 7) == 0) {
proto_tree_add_item (tree, hf_noreply, tvb, offset, tokenlen, ENC_ASCII|ENC_NA);
} else {
memcpy (response_chars, line, tokenlen);
response_chars[tokenlen] = '\0';
expiration = (guint32) strtoul (response_chars, NULL, 10);
proto_tree_add_uint (tree, hf_expiration, tvb, offset, tokenlen, expiration);
}
offset += (int) (next_token - line);
line = next_token;
} else {
return -1;
}
tokenlen = get_token_len (line, lineend, &next_token);
if (tokenlen == 0) {
return offset;
}
if (tokenlen == 7 && strncmp (line, "noreply", 7) == 0) {
proto_tree_add_item (tree, hf_noreply, tvb, offset, tokenlen, ENC_ASCII|ENC_NA);
offset += (int) (next_token - line);
} else {
return -1;
}
break;
case OP_VERBOSE:
break;
case OP_VERSION:
case OP_QUIT:
tokenlen = get_token_len (line, lineend, &next_token);
if (tokenlen == 0) {
return offset;
} else {
return -1;
}
default:
break;
}
return offset;
}
static int
is_memcache_request_or_reply (const gchar *data, int linelen, guint8 *opcode,
memcache_type_t *type, int *expect_content_length,
ReqRespDissector *reqresp_dissector)
{
const guchar *ptr = (const guchar *)data;
int is_request_or_response = FALSE;
int indx = 0;
while (indx < linelen) {
if (*ptr == ' ')
break;
ptr++;
indx++;
}
switch (indx) {
case 2:
if (strncmp (data, "OK", indx) == 0) {
*type = MEMCACHE_RESPONSE;
is_request_or_response = TRUE;
}
break;
case 3:
if (strncmp (data, "END", indx) == 0) {
*type = MEMCACHE_RESPONSE;
is_request_or_response = TRUE;
}
break;
case 4:
if (strncmp (data, "STAT", indx) == 0) {
*opcode = OP_STAT;
*type = MEMCACHE_RESPONSE;
is_request_or_response = TRUE;
}
break;
case 5:
if (strncmp (data, "VALUE", indx) == 0) {
*opcode = OP_GET;
*type = MEMCACHE_RESPONSE;
*expect_content_length = TRUE;
is_request_or_response = TRUE;
}
break;
case 6:
if (strncmp (data, "EXISTS", indx) == 0 ||
strncmp (data, "STORED", indx) == 0) {
*type = MEMCACHE_RESPONSE;
is_request_or_response = TRUE;
}
break;
case 7:
if (strncmp (data, "VERSION", indx) == 0) {
*opcode = OP_VERSION;
*type = MEMCACHE_RESPONSE;
is_request_or_response = TRUE;
} else if (strncmp (data, "DELETED", indx) == 0) {
*opcode = OP_DELETE;
*type = MEMCACHE_RESPONSE;
is_request_or_response = TRUE;
}
break;
case 9:
if (strncmp (data, "NOT_FOUND", indx) == 0) {
*type = MEMCACHE_RESPONSE;
is_request_or_response = TRUE;
}
break;
case 10:
if (strncmp (data, "NOT_STORED", indx) == 0) {
*type = MEMCACHE_RESPONSE;
is_request_or_response = TRUE;
}
break;
default:
break;
}
if (is_request_or_response && reqresp_dissector) {
*reqresp_dissector = memcache_response_dissector;
return is_request_or_response;
}
switch (indx) {
case 3:
if (strncmp (data, "get", indx) == 0) {
*opcode = OP_GET;
*type = MEMCACHE_REQUEST;
is_request_or_response = TRUE;
} else if (strncmp (data, "set", indx) == 0) {
*opcode = OP_SET;
*type = MEMCACHE_REQUEST;
*expect_content_length = TRUE;
is_request_or_response = TRUE;
} else if (strncmp (data, "add", indx) == 0) {
*opcode = OP_ADD;
*type = MEMCACHE_REQUEST;
*expect_content_length = TRUE;
is_request_or_response = TRUE;
} else if (strncmp (data, "cas", indx) == 0) {
*opcode = OP_CAS;
*type = MEMCACHE_REQUEST;
*expect_content_length = TRUE;
is_request_or_response = TRUE;
}
break;
case 4:
if (strncmp (data, "gets", indx) == 0) {
*opcode = OP_GETS;
*type = MEMCACHE_REQUEST;
is_request_or_response = TRUE;
} else if (strncmp (data, "incr", indx) == 0) {
*opcode = OP_INCREMENT;
*type = MEMCACHE_REQUEST;
is_request_or_response = TRUE;
} else if (strncmp (data, "decr", indx) == 0) {
*opcode = OP_DECREMENT;
*type = MEMCACHE_REQUEST;
is_request_or_response = TRUE;
} else if (strncmp (data, "quit", indx) == 0) {
*opcode = OP_QUIT;
*type = MEMCACHE_REQUEST;
is_request_or_response = TRUE;
}
break;
case 5:
if (strncmp (data, "stats", indx) == 0) {
*opcode = OP_STAT;
*type = MEMCACHE_REQUEST;
is_request_or_response = TRUE;
}
break;
case 6:
if (strncmp (data, "append", indx) == 0) {
*opcode = OP_APPEND;
*type = MEMCACHE_REQUEST;
*expect_content_length = TRUE;
is_request_or_response = TRUE;
} else if (strncmp (data, "delete", indx) == 0) {
*opcode = OP_DELETE;
*type = MEMCACHE_REQUEST;
is_request_or_response = TRUE;
}
break;
case 7:
if (strncmp (data, "replace", indx) == 0) {
*opcode = OP_REPLACE;
*type = MEMCACHE_REQUEST;
*expect_content_length = TRUE;
is_request_or_response = TRUE;
} else if (strncmp (data, "prepend", indx) == 0) {
*opcode = OP_PREPEND;
*type = MEMCACHE_REQUEST;
*expect_content_length = TRUE;
is_request_or_response = TRUE;
} else if (strncmp (data, "version", indx) == 0) {
*opcode = OP_VERSION;
*type = MEMCACHE_REQUEST;
is_request_or_response = TRUE;
}
break;
case 9:
if (strncmp (data, "flush_all", indx) == 0) {
*opcode = OP_FLUSH;
*type = MEMCACHE_REQUEST;
is_request_or_response = TRUE;
}
break;
default:
break;
}
if (is_request_or_response && reqresp_dissector) {
*reqresp_dissector = memcache_request_dissector;
return is_request_or_response;
}
return is_request_or_response;
}
static void
dissect_memcache_text (tvbuff_t *tvb, packet_info *pinfo, proto_tree *tree)
{
int offset = 0;
int len;
while (tvb_reported_length_remaining (tvb, offset) != 0) {
len = dissect_memcache_message (tvb, offset, pinfo, tree);
if (len == -1)
break;
offset += len;
col_set_fence (pinfo->cinfo, COL_INFO);
}
}
static int
dissect_memcache_tcp (tvbuff_t *tvb, packet_info *pinfo, proto_tree *tree, void* data)
{
gint offset = 0;
guint8 magic;
magic = tvb_get_guint8 (tvb, offset);
if (try_val_to_str (magic, magic_vals) != NULL) {
tcp_dissect_pdus (tvb, pinfo, tree, memcache_desegment_body, 12,
get_memcache_pdu_len, dissect_memcache, data);
} else {
dissect_memcache_text (tvb, pinfo, tree);
}
return tvb_captured_length(tvb);
}
static int
dissect_memcache_udp (tvbuff_t *tvb, packet_info *pinfo, proto_tree *tree, void* data)
{
gint offset = 0;
guint8 magic;
magic = tvb_get_guint8 (tvb, offset);
if (try_val_to_str (magic, magic_vals) != NULL) {
dissect_memcache (tvb, pinfo, tree, data);
} else {
dissect_memcache_message (tvb, 0, pinfo, tree);
}
return tvb_captured_length(tvb);
}
void
proto_register_memcache (void)
{
static hf_register_info hf[] = {
{ &hf_magic,
{ "Magic", "memcache.magic",
FT_UINT8, BASE_DEC, VALS (magic_vals), 0x0,
"Magic number", HFILL } },
{ &hf_opcode,
{ "Opcode", "memcache.opcode",
FT_UINT8, BASE_DEC, VALS (opcode_vals), 0x0,
"Command code", HFILL } },
{ &hf_extras_length,
{ "Extras length", "memcache.extras.length",
FT_UINT8, BASE_DEC, NULL, 0x0,
"Length in bytes of the command extras", HFILL } },
{ &hf_key_length,
{ "Key Length", "memcache.key.length",
FT_UINT16, BASE_DEC, NULL, 0x0,
"Length in bytes of the text key that follows the command extras", HFILL } },
{ &hf_value_length,
{ "Value length", "memcache.value.length",
FT_UINT32, BASE_DEC, NULL, 0x0,
"Length in bytes of the value that follows the key", HFILL } },
{ &hf_data_type,
{ "Data type", "memcache.data_type",
FT_UINT8, BASE_DEC, VALS (data_type_vals), 0x0,
NULL, HFILL } },
{ &hf_reserved,
{ "Reserved", "memcache.reserved",
FT_UINT16, BASE_DEC, NULL, 0x0,
"Reserved for future use", HFILL } },
{ &hf_status,
{ "Status", "memcache.status",
FT_UINT16, BASE_DEC, VALS (status_vals), 0x0,
"Status of the response", HFILL } },
{ &hf_total_body_length,
{ "Total body length", "memcache.total_body_length",
FT_UINT32, BASE_DEC, NULL, 0x0,
"Length in bytes of extra + key + value", HFILL } },
{ &hf_opaque,
{ "Opaque", "memcache.opaque",
FT_UINT32, BASE_DEC, NULL, 0x0,
NULL, HFILL } },
{ &hf_cas,
{ "CAS", "memcache.cas",
FT_UINT64, BASE_DEC, NULL, 0x0,
"Data version check", HFILL } },
{ &hf_extras,
{ "Extras", "memcache.extras",
FT_NONE, BASE_NONE, NULL, 0x0,
NULL, HFILL } },
{ &hf_extras_flags,
{ "Flags", "memcache.extras.flags",
FT_UINT32, BASE_HEX, NULL, 0x0,
NULL, HFILL } },
{ &hf_extras_expiration,
{ "Expiration", "memcache.extras.expiration",
FT_UINT32, BASE_DEC, NULL, 0x0,
NULL, HFILL } },
{ &hf_extras_delta,
{ "Amount to add", "memcache.extras.delta",
FT_UINT64, BASE_DEC, NULL, 0x0,
NULL, HFILL } },
{ &hf_extras_initial,
{ "Initial value", "memcache.extras.initial",
FT_UINT64, BASE_DEC, NULL, 0x0,
NULL, HFILL } },
{ &hf_extras_unknown,
{ "Unknown", "memcache.extras.unknown",
FT_BYTES, BASE_NONE, NULL, 0x0,
"Unknown Extras", HFILL } },
{ &hf_key,
{ "Key", "memcache.key",
FT_STRING, BASE_NONE, NULL, 0x0,
NULL, HFILL } },
{ &hf_value,
{ "Value", "memcache.value",
FT_STRING, BASE_NONE, NULL, 0x0,
NULL, HFILL } },
{ &hf_uint64_response,
{ "Response", "memcache.extras.response",
FT_UINT64, BASE_DEC, NULL, 0x0,
NULL, HFILL } },
{ &hf_command,
{ "Command", "memcache.command",
FT_STRING, BASE_NONE , NULL, 0x0,
NULL, HFILL } },
{ &hf_subcommand,
{ "Sub command", "memcache.subcommand",
FT_STRING, BASE_NONE, NULL, 0x0,
"Sub command if any", HFILL } },
{ &hf_flags,
{ "Flags", "memcache.flags",
FT_UINT16, BASE_DEC, NULL, 0x0,
NULL, HFILL } },
{ &hf_expiration,
{ "Expiration", "memcache.expiration",
FT_UINT32, BASE_DEC, NULL, 0x0,
NULL, HFILL } },
{ &hf_noreply,
{ "Noreply", "memcache.noreply",
FT_STRING, BASE_NONE, NULL, 0x0,
"Client does not expect a reply", HFILL } },
{ &hf_response,
{ "Response", "memcache.response",
FT_STRING, BASE_NONE, NULL, 0x0,
"Response command", HFILL } },
{ &hf_version,
{ "Version", "memcache.version",
FT_STRING, BASE_NONE, NULL, 0x0,
"Version of running memcache", HFILL } },
{ &hf_slabclass,
{ "Slab class", "memcache.slabclass",
FT_UINT32, BASE_DEC, NULL, 0x0,
"Slab class of a stat", HFILL } },
{ &hf_name,
{ "Stat name", "memcache.name",
FT_STRING, BASE_NONE, NULL, 0x0,
"Name of a stat", HFILL } },
{ &hf_name_value,
{ "Stat value", "memcache.name_value",
FT_STRING, BASE_NONE, NULL, 0x0,
"Value of a stat", HFILL } },
};
static gint *ett[] = {
&ett_memcache,
&ett_extras
};
static ei_register_info ei[] = {
{ &ei_extras_unknown, { "memcache.extras.notexpected", PI_UNDECODED, PI_WARN, "shall not have Extras", EXPFILL }},
{ &ei_extras_missing, { "memcache.extras.missing", PI_UNDECODED, PI_WARN, "must have Extras", EXPFILL }},
{ &ei_key_unknown, { "memcache.key.notexpected", PI_UNDECODED, PI_WARN, "shall not have Key", EXPFILL }},
{ &ei_key_missing, { "memcache.key.missing", PI_UNDECODED, PI_WARN, "must have Key", EXPFILL }},
{ &ei_value_length, { "memcache.value.invalid", PI_UNDECODED, PI_WARN, "Illegal Value length, should be 8", EXPFILL }},
{ &ei_value_unknown, { "memcache.value.notexpected", PI_UNDECODED, PI_WARN, "shall not have Value", EXPFILL }},
{ &ei_value_missing, { "memcache.value.missing", PI_UNDECODED, PI_WARN, "must have Value", EXPFILL }},
{ &ei_magic_unknown, { "memcache.magic.unknown", PI_UNDECODED, PI_WARN, "Unknown magic byte", EXPFILL }},
{ &ei_opcode_unknown, { "memcache.opcode.unknown", PI_UNDECODED, PI_WARN, "Unknown opcode", EXPFILL }},
{ &ei_status_response, { "memcache.status.response", PI_RESPONSE_CODE, PI_NOTE, "Error response", EXPFILL }},
{ &ei_reserved_value, { "memcache.reserved.expert", PI_UNDECODED, PI_WARN, "Reserved value", EXPFILL }},
};
module_t *memcache_module;
expert_module_t *expert_memcache;
proto_memcache = proto_register_protocol (PNAME, PSNAME, PFNAME);
memcache_tcp_handle = new_register_dissector ("memcache.tcp", dissect_memcache_tcp, proto_memcache);
memcache_udp_handle = new_register_dissector ("memcache.udp", dissect_memcache_udp, proto_memcache);
proto_register_field_array (proto_memcache, hf, array_length (hf));
proto_register_subtree_array (ett, array_length (ett));
expert_memcache = expert_register_protocol(proto_memcache);
expert_register_field_array(expert_memcache, ei, array_length(ei));
memcache_module = prefs_register_protocol (proto_memcache, proto_reg_handoff_memcache);
prefs_register_bool_preference (memcache_module, "desegment_headers",
"Reassemble MEMCACHE headers spanning multiple TCP segments",
"Whether the MEMCACHE dissector should reassemble headers "
"of a request spanning multiple TCP segments. "
"To use this option, you must also enable "
"\"Allow subdissectors to reassemble TCP streams\" in the TCP protocol settings.",
&memcache_desegment_headers);
prefs_register_bool_preference (memcache_module, "desegment_pdus",
"Reassemble PDUs spanning multiple TCP segments",
"Whether the memcache dissector should reassemble PDUs"
" spanning multiple TCP segments."
" To use this option, you must also enable \"Allow subdissectors"
" to reassemble TCP streams\" in the TCP protocol settings.",
&memcache_desegment_body);
range_convert_str(&memcache_tcp_port_range, MEMCACHE_DEFAULT_RANGE, 65535);
range_convert_str(&memcache_udp_port_range, MEMCACHE_DEFAULT_RANGE, 65535);
prefs_register_range_preference(memcache_module, "tcp.ports", \
"MEMCACHE TCP Port range", \
"MEMCACHE TCP Port range", \
&memcache_tcp_port_range, \
65535);
prefs_register_range_preference(memcache_module, "udp.ports", \
"MEMCACHE UDP Port range", \
"MEMCACHE UDP Port range", \
&memcache_udp_port_range, \
65535);
}
void
proto_reg_handoff_memcache (void)
{
static range_t *orig_memcache_tcp_port_range = NULL;
static range_t *orig_memcache_udp_port_range = NULL;
dissector_delete_uint_range("tcp.port", orig_memcache_tcp_port_range, memcache_tcp_handle);
dissector_delete_uint_range("udp.port", orig_memcache_udp_port_range, memcache_udp_handle);
g_free(orig_memcache_tcp_port_range);
g_free(orig_memcache_udp_port_range);
orig_memcache_tcp_port_range = range_copy(memcache_tcp_port_range);
orig_memcache_udp_port_range = range_copy(memcache_udp_port_range);
dissector_add_uint_range("tcp.port", orig_memcache_tcp_port_range, memcache_tcp_handle);
dissector_add_uint_range("udp.port", orig_memcache_udp_port_range, memcache_udp_handle);
}
