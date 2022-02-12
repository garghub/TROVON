static tvbuff_t *
base64_decode(packet_info *pinfo, tvbuff_t *b64_tvb, char *name)
{
char *data;
tvbuff_t *tvb;
data = tvb_get_string_enc(wmem_packet_scope(), b64_tvb, 0, tvb_length(b64_tvb), ENC_ASCII);
tvb = base64_to_tvb(b64_tvb, data);
add_new_data_source(pinfo, tvb, name);
return tvb;
}
static char *
unfold_and_compact_mime_header(const char *lines, gint *first_colon_offset)
{
const char *p = lines;
char c;
char *ret, *q;
char sep_seen = 0;
char lws = FALSE;
gint colon = -1;
if (! lines) return NULL;
c = *p;
ret = (char *)wmem_alloc(wmem_packet_scope(), strlen(lines) + 1);
q = ret;
while (c) {
if (c == ':') {
lws = FALSE;
if (colon == -1) {
colon = (gint) (q - ret);
}
*(q++) = sep_seen = c;
p++;
} else if (c == ';' || c == ',' || c == '=') {
lws = FALSE;
*(q++) = sep_seen = c;
p++;
} else if (c == ' ' || c == '\t') {
lws = TRUE;
p++;
} else if (c == '\n') {
lws = FALSE;
if ((c = *(p+1))) {
if (c == ' ' || c == '\t') {
lws = TRUE;
p += 2;
} else {
*q = c = 0;
}
}
} else if (c == '\r') {
lws = FALSE;
if ((c = *(p+1))) {
if (c == '\n') {
if ((c = *(p+2))) {
if (c == ' ' || c == '\t') {
lws = TRUE;
p += 3;
} else {
*q = c = 0;
}
}
} else if (c == ' ' || c == '\t') {
lws = TRUE;
p += 2;
} else {
*q = c = 0;
}
}
} else if (c == '"') {
lws = FALSE;
*(q++) = c;
while (c) {
c = *(q++) = *(++p);
if (c == '"') {
p++;
break;
}
}
if(c == 0) {
q--;
}
} else {
if (sep_seen) {
sep_seen = 0;
} else {
if (lws) {
*(q++) = ' ';
}
}
lws = FALSE;
*(q++) = c;
p++;
}
if (c) {
c = *p;
}
}
*q = 0;
*first_colon_offset = colon;
return (ret);
}
static gint
index_of_char(const char *str, const char c)
{
gint len = 0;
const char *p = str;
while (*p && *p != c) {
p++;
len++;
}
if (*p)
return len;
return -1;
}
static char *find_parameter(char *parameters, const char *key, int *retlen)
{
char *start, *p;
int keylen = 0;
int len = 0;
if(!parameters || !*parameters || !key || strlen(key) == 0)
return NULL;
keylen = (int) strlen(key);
p = parameters;
while (*p) {
while ((*p) && isspace((guchar)*p))
p++;
if (g_ascii_strncasecmp(p, key, keylen) == 0)
break;
p = strchr(p, ';');
if (p == NULL)
{
return NULL;
}
p++;
}
start = p + keylen;
if (start[0] == 0) {
return NULL;
}
if (start[0] == '"') {
start++;
len = index_of_char(start, '"');
if (len < 0) {
return NULL;
}
} else {
p = start;
while (*p) {
if (*p == ';' || isspace((guchar)*p))
break;
p++;
len++;
}
}
if(retlen)
(*retlen) = len;
return start;
}
static multipart_info_t *
get_multipart_info(packet_info *pinfo)
{
const char *start;
int len = 0;
multipart_info_t *m_info = NULL;
const char *type = pinfo->match_string;
char *parameters;
gint dummy;
if ((type == NULL) || (pinfo->private_data == NULL)) {
return NULL;
}
parameters = unfold_and_compact_mime_header((const char *)pinfo->private_data, &dummy);
start = find_parameter(parameters, "boundary=", &len);
if(!start) {
return NULL;
}
m_info = (multipart_info_t *)g_malloc(sizeof(multipart_info_t));
m_info->type = type;
m_info->boundary = g_strndup(start, len);
m_info->boundary_length = len;
return m_info;
}
static void
cleanup_multipart_info(void *data)
{
multipart_info_t *m_info = (multipart_info_t *)data;
if (m_info) {
g_free(m_info->boundary);
g_free(m_info);
}
}
static gint
find_first_boundary(tvbuff_t *tvb, gint start, const guint8 *boundary,
gint boundary_len, gint *boundary_line_len, gboolean *last_boundary)
{
gint offset = start, next_offset, line_len, boundary_start;
while (tvb_length_remaining(tvb, offset + 2 + boundary_len) > 0) {
boundary_start = offset;
if (((tvb_strneql(tvb, offset, (const guint8 *)"--", 2) == 0)
&& (tvb_strneql(tvb, offset + 2, boundary, boundary_len) == 0)))
{
if ((tvb_length_remaining(tvb, offset + 2 + boundary_len + 2) >= 0)
&& (tvb_strneql(tvb, offset + 2 + boundary_len,
(const guint8 *)"--", 2) == 0)) {
*last_boundary = TRUE;
} else {
*last_boundary = FALSE;
}
line_len = tvb_find_line_end(tvb, offset, -1, &offset, FALSE);
if (line_len == -1) {
*boundary_line_len = -1;
} else {
*boundary_line_len = offset - boundary_start;
}
return boundary_start;
}
line_len = tvb_find_line_end(tvb, offset, -1, &next_offset, FALSE);
if (line_len == -1) {
return -1;
}
offset = next_offset;
}
return -1;
}
static gint
find_next_boundary(tvbuff_t *tvb, gint start, const guint8 *boundary,
gint boundary_len, gint *boundary_line_len, gboolean *last_boundary)
{
gint offset = start, next_offset, line_len, boundary_start;
while (tvb_length_remaining(tvb, offset + 2 + boundary_len) > 0) {
line_len = tvb_find_line_end(tvb, offset, -1, &next_offset, FALSE);
if (line_len == -1) {
return -1;
}
boundary_start = offset + line_len;
if (((tvb_strneql(tvb, next_offset, (const guint8 *)"--", 2) == 0)
&& (tvb_strneql(tvb, next_offset + 2, boundary, boundary_len) == 0)))
{
if ((tvb_length_remaining(tvb, next_offset + 2 + boundary_len + 2) >= 0)
&& (tvb_strneql(tvb, next_offset + 2 + boundary_len,
(const guint8 *)"--", 2) == 0)) {
*last_boundary = TRUE;
} else {
*last_boundary = FALSE;
}
line_len = tvb_find_line_end(tvb, next_offset, -1, &offset, FALSE);
if (line_len == -1) {
*boundary_line_len = -1;
} else {
*boundary_line_len = offset - boundary_start;
}
return boundary_start;
}
offset = next_offset;
}
return -1;
}
static gint
process_preamble(proto_tree *tree, tvbuff_t *tvb, const guint8 *boundary,
gint boundary_len, gboolean *last_boundary)
{
gint boundary_start, boundary_line_len;
boundary_start = find_first_boundary(tvb, 0, boundary, boundary_len,
&boundary_line_len, last_boundary);
if (boundary_start == 0) {
proto_tree_add_text(tree, tvb, boundary_start, boundary_line_len,
"First boundary: %s",
tvb_format_text(tvb, boundary_start, boundary_line_len));
return boundary_start + boundary_line_len;
} else if (boundary_start > 0) {
if (boundary_line_len > 0) {
gint body_part_start = boundary_start + boundary_line_len;
if (body_part_start > 0) {
proto_tree_add_text(tree, tvb, 0, body_part_start,
"Preamble");
}
proto_tree_add_text(tree, tvb, boundary_start,
boundary_line_len, "First boundary: %s",
tvb_format_text(tvb, boundary_start,
boundary_line_len));
return body_part_start;
}
}
return -1;
}
static gint
process_body_part(proto_tree *tree, tvbuff_t *tvb, const guint8 *boundary,
gint boundary_len, packet_info *pinfo, gint start,
gboolean *last_boundary)
{
proto_tree *subtree;
proto_item *ti;
gint offset = start, next_offset = 0;
char *parameters = NULL;
gint body_start, boundary_start, boundary_line_len;
gchar *content_type_str = NULL;
gchar *content_encoding_str = NULL;
char *filename = NULL;
char *mimetypename = NULL;
int len = 0;
gboolean last_field = FALSE;
ti = proto_tree_add_item(tree, hf_multipart_part, tvb, start, 0, ENC_ASCII|ENC_NA);
subtree = proto_item_add_subtree(ti, ett_multipart_body);
while (!last_field)
{
gint colon_offset;
char *hdr_str;
char *header_str;
next_offset = imf_find_field_end(tvb, offset, tvb_length_remaining(tvb, offset)+offset, &last_field);
if (next_offset == offset) {
break;
}
hdr_str = tvb_get_string_enc(wmem_packet_scope(), tvb, offset, next_offset - offset, ENC_ASCII);
header_str = unfold_and_compact_mime_header(hdr_str, &colon_offset);
if (colon_offset <= 0) {
proto_tree_add_format_text(subtree, tvb, offset, next_offset - offset);
} else {
gint hf_index;
header_str[colon_offset] = '\0';
hf_index = is_known_multipart_header(header_str, colon_offset);
if (hf_index == -1) {
proto_tree_add_format_text(subtree, tvb, offset, next_offset - offset);
} else {
char *value_str = header_str + colon_offset + 1;
proto_tree_add_string_format(subtree,
hf_header_array[hf_index], tvb,
offset, next_offset - offset,
(const char *)value_str, "%s",
tvb_format_text(tvb, offset, next_offset - offset));
switch (hf_index) {
case POS_CONTENT_TYPE:
{
gint semicolon_offset = index_of_char(
value_str, ';');
if (semicolon_offset > 0) {
value_str[semicolon_offset] = '\0';
parameters = wmem_strdup(wmem_packet_scope(), value_str + semicolon_offset + 1);
} else {
parameters = NULL;
}
content_type_str = wmem_ascii_strdown(wmem_packet_scope(), value_str, -1);
proto_item_append_text(ti, " (%s)", content_type_str);
if((mimetypename = find_parameter(parameters, "name=", &len)) != NULL) {
mimetypename = g_strndup(mimetypename, len);
}
}
break;
case POS_CONTENT_TRANSFER_ENCODING:
{
gint cr_offset = index_of_char(value_str, '\r');
if (cr_offset > 0) {
value_str[cr_offset] = '\0';
}
content_encoding_str = wmem_ascii_strdown(wmem_packet_scope(), value_str, -1);
}
break;
case POS_CONTENT_DISPOSITION:
{
if((filename = find_parameter(value_str, "filename=", &len)) != NULL) {
filename = g_strndup(filename, len);
}
}
break;
default:
break;
}
}
}
offset = next_offset;
}
body_start = next_offset;
boundary_start = find_next_boundary(tvb, body_start, boundary, boundary_len,
&boundary_line_len, last_boundary);
if (boundary_start > 0) {
gint body_len = boundary_start - body_start;
tvbuff_t *tmp_tvb = tvb_new_subset_length(tvb, body_start, body_len);
if (content_type_str) {
void *save_private_data = pinfo->private_data;
gboolean dissected;
if(content_encoding_str && remove_base64_encoding) {
if(!g_ascii_strncasecmp(content_encoding_str, "base64", 6))
tmp_tvb = base64_decode(pinfo, tmp_tvb, filename ? filename : (mimetypename ? mimetypename : content_type_str));
}
pinfo->private_data = parameters;
dissected = dissector_try_string(multipart_media_subdissector_table,
content_type_str, tmp_tvb, pinfo, subtree, NULL);
if (! dissected) {
dissected = dissector_try_string(media_type_dissector_table,
content_type_str, tmp_tvb, pinfo, subtree, NULL);
}
if (! dissected) {
const char *save_match_string = pinfo->match_string;
pinfo->match_string = content_type_str;
call_dissector(media_handle, tmp_tvb, pinfo, subtree);
pinfo->match_string = save_match_string;
}
pinfo->private_data = save_private_data;
parameters = NULL;
} else {
call_dissector(data_handle, tmp_tvb, pinfo, subtree);
}
proto_item_set_len(ti, boundary_start - start);
if (*last_boundary == TRUE) {
proto_tree_add_text(tree, tvb,
boundary_start, boundary_line_len,
"Last boundary: %s",
tvb_format_text(tvb, boundary_start,
boundary_line_len));
} else {
proto_tree_add_text(tree, tvb,
boundary_start, boundary_line_len,
"Boundary: %s",
tvb_format_text(tvb, boundary_start,
boundary_line_len));
}
g_free(filename);
g_free(mimetypename);
return boundary_start + boundary_line_len;
}
g_free(filename);
g_free(mimetypename);
return -1;
}
static int dissect_multipart(tvbuff_t *tvb, packet_info *pinfo, proto_tree *tree, void* data _U_)
{
proto_tree *subtree;
proto_item *ti;
proto_item *type_ti;
multipart_info_t *m_info = get_multipart_info(pinfo);
gint header_start = 0;
guint8 *boundary;
gint boundary_len;
gboolean last_boundary = FALSE;
if (m_info == NULL) {
proto_tree_add_text(tree, tvb, 0, -1,
"The multipart dissector could not find "
"the required boundary parameter.");
call_dissector(data_handle, tvb, pinfo, tree);
return tvb_length(tvb);
}
boundary = (guint8 *)m_info->boundary;
boundary_len = m_info->boundary_length;
ti = proto_tree_add_item(tree, proto_multipart,
tvb, 0, -1, ENC_NA);
subtree = proto_item_add_subtree(ti, ett_multipart);
proto_item_append_text(ti, ", Type: %s, Boundary: \"%s\"",
m_info->type, m_info->boundary);
type_ti = proto_tree_add_string(subtree, hf_multipart_type,
tvb, 0, 0, pinfo->match_string);
PROTO_ITEM_SET_GENERATED(type_ti);
col_set_fence(pinfo->cinfo, COL_INFO);
header_start = process_preamble(subtree, tvb, boundary,
boundary_len, &last_boundary);
if (header_start == -1) {
call_dissector(data_handle, tvb, pinfo, subtree);
cleanup_multipart_info(m_info);
return tvb_length(tvb);
}
while (last_boundary == FALSE) {
header_start = process_body_part(subtree, tvb, boundary, boundary_len,
pinfo, header_start, &last_boundary);
if (header_start == -1) {
cleanup_multipart_info(m_info);
return tvb_length(tvb);
}
}
if (tvb_length_remaining(tvb, header_start) > 0) {
proto_tree_add_text(subtree, tvb, header_start, -1, "Trailer");
}
cleanup_multipart_info(m_info);
return tvb_length(tvb);
}
static gint
is_known_multipart_header(const char *header_str, guint len)
{
guint i;
for (i = 1; i < array_length(multipart_headers); i++) {
if (len == strlen(multipart_headers[i].name) &&
g_ascii_strncasecmp(header_str, multipart_headers[i].name, len) == 0)
return i;
if (multipart_headers[i].compact_name != NULL &&
len == strlen(multipart_headers[i].compact_name) &&
g_ascii_strncasecmp(header_str, multipart_headers[i].compact_name, len) == 0)
return i;
}
return -1;
}
void
proto_register_multipart(void)
{
static hf_register_info hf[] = {
{ &hf_multipart_type,
{ "Type",
"mime_multipart.type",
FT_STRING, BASE_NONE, NULL, 0x00,
"MIME multipart encapsulation type", HFILL
}
},
{ &hf_multipart_part,
{ "Encapsulated multipart part",
"mime_multipart.part",
FT_STRING, BASE_NONE, NULL, 0x00,
NULL, HFILL
}
},
{ &hf_header_array[POS_CONTENT_DISPOSITION],
{ "Content-Disposition",
"mime_multipart.header.content-disposition",
FT_STRING, BASE_NONE, NULL, 0x00,
"RFC 2183: Content-Disposition Header", HFILL
}
},
{ &hf_header_array[POS_CONTENT_ENCODING],
{ "Content-Encoding",
"mime_multipart.header.content-encoding",
FT_STRING, BASE_NONE, NULL, 0x00,
"Content-Encoding Header", HFILL
}
},
{ &hf_header_array[POS_CONTENT_ID],
{ "Content-Id",
"mime_multipart.header.content-id",
FT_STRING, BASE_NONE, NULL, 0x00,
"RFC 2045: Content-Id Header", HFILL
}
},
{ &hf_header_array[POS_CONTENT_LANGUAGE],
{ "Content-Language",
"mime_multipart.header.content-language",
FT_STRING, BASE_NONE, NULL, 0x00,
"Content-Language Header", HFILL
}
},
{ &hf_header_array[POS_CONTENT_LENGTH],
{ "Content-Length",
"mime_multipart.header.content-length",
FT_STRING, BASE_NONE, NULL, 0x0,
"Content-Length Header", HFILL
}
},
{ &hf_header_array[POS_CONTENT_TRANSFER_ENCODING],
{ "Content-Transfer-Encoding",
"mime_multipart.header.content-transfer-encoding",
FT_STRING, BASE_NONE, NULL, 0x00,
"RFC 2045: Content-Transfer-Encoding Header", HFILL
}
},
{ &hf_header_array[POS_CONTENT_TYPE],
{ "Content-Type",
"mime_multipart.header.content-type",
FT_STRING, BASE_NONE,NULL,0x0,
"Content-Type Header", HFILL
}
},
};
module_t *multipart_module;
static gint *ett[] = {
&ett_multipart,
&ett_multipart_main,
&ett_multipart_body,
};
proto_multipart = proto_register_protocol(
"MIME Multipart Media Encapsulation",
"MIME multipart",
"mime_multipart");
proto_register_field_array(proto_multipart, hf, array_length(hf));
proto_register_subtree_array(ett, array_length(ett));
multipart_module = prefs_register_protocol(proto_multipart, NULL);
prefs_register_bool_preference(multipart_module,
"display_unknown_body_as_text",
"Display bodies without media type as text",
"Display multipart bodies with no media type dissector"
" as raw text (may cause problems with binary data).",
&display_unknown_body_as_text);
prefs_register_bool_preference(multipart_module,
"remove_base64_encoding",
"Remove base64 encoding from bodies",
"Remove any base64 content-transfer encoding from bodies. "
"This supports export of the body and its further dissection.",
&remove_base64_encoding);
multipart_media_subdissector_table = register_dissector_table(
"multipart_media_type",
"Internet media type (for multipart processing)",
FT_STRING, BASE_NONE);
}
void
proto_reg_handoff_multipart(void)
{
dissector_handle_t multipart_handle;
data_handle = find_dissector("data");
media_handle = find_dissector("media");
media_type_dissector_table = find_dissector_table("media_type");
multipart_handle = new_create_dissector_handle(
dissect_multipart, proto_multipart);
dissector_add_string("media_type",
"multipart/mixed", multipart_handle);
dissector_add_string("media_type",
"multipart/related", multipart_handle);
dissector_add_string("media_type",
"multipart/alternative", multipart_handle);
dissector_add_string("media_type",
"multipart/form-data", multipart_handle);
dissector_add_string("media_type",
"multipart/report", multipart_handle);
dissector_add_string("media_type",
"multipart/", multipart_handle);
}
