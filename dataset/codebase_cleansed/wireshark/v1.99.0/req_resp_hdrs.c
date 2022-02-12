gboolean
req_resp_hdrs_do_reassembly(tvbuff_t *tvb, const int offset, packet_info *pinfo,
const gboolean desegment_headers, const gboolean desegment_body)
{
gint next_offset;
gint next_offset_sav;
gint length_remaining, reported_length_remaining;
int linelen;
gchar *header_val;
int content_length;
gboolean content_length_found = FALSE;
gboolean content_type_found = FALSE;
gboolean chunked_encoding = FALSE;
gboolean keepalive_found = FALSE;
gchar *line;
gchar *content_type = NULL;
if (desegment_headers && pinfo->can_desegment) {
next_offset = offset;
for (;;) {
next_offset_sav = next_offset;
reported_length_remaining =
tvb_reported_length_remaining(tvb, next_offset);
if (reported_length_remaining < 1) {
pinfo->desegment_offset = offset;
pinfo->desegment_len = DESEGMENT_ONE_MORE_SEGMENT;
return FALSE;
}
length_remaining = tvb_captured_length_remaining(tvb,
next_offset);
linelen = tvb_find_line_end(tvb, next_offset,
length_remaining, &next_offset, TRUE);
if (linelen == -1 &&
length_remaining >= reported_length_remaining) {
pinfo->desegment_offset = offset;
pinfo->desegment_len = DESEGMENT_ONE_MORE_SEGMENT;
return FALSE;
}
if (linelen == 0) {
break;
}
if (desegment_body) {
guchar first_byte = tvb_get_guint8(tvb, next_offset_sav);
if (! (first_byte == 'c' || first_byte == 'C' ||
first_byte == 't' || first_byte == 'T')) {
continue;
}
line = tvb_get_string_enc(wmem_packet_scope(), tvb, next_offset_sav, linelen, ENC_UTF_8|ENC_NA);
if (g_ascii_strncasecmp(line, "Content-Length:", 15) == 0) {
if (sscanf(line+15,"%i", &content_length) == 1)
content_length_found = TRUE;
} else if (g_ascii_strncasecmp(line, "Content-Type:", 13) == 0) {
content_type_found = TRUE;
content_type = line+13;
while (*content_type == ' ') {
content_type++;
}
} else if (g_ascii_strncasecmp(line, "Connection:", 11) == 0) {
header_val = line+11;
if(header_val){
while(*header_val==' '){
header_val++;
}
if(!g_ascii_strncasecmp(header_val, "Keep-Alive", 10)){
keepalive_found = TRUE;
}
}
} else if (g_ascii_strncasecmp( line, "Transfer-Encoding:", 18) == 0) {
gchar *p;
guint len;
header_val = line+18;
p = header_val;
len = (guint) strlen(header_val);
while (p < header_val + len &&
(*p == ' ' || *p == '\t'))
p++;
if (p <= header_val + len) {
if (g_ascii_strncasecmp(p, "chunked", 7)
== 0) {
chunked_encoding = TRUE;
}
}
}
}
}
}
if (desegment_body) {
if (chunked_encoding) {
gboolean done_chunking = FALSE;
while (!done_chunking) {
guint chunk_size = 0;
gint chunk_offset = 0;
gchar *chunk_string = NULL;
gchar *c = NULL;
reported_length_remaining =
tvb_reported_length_remaining(tvb,
next_offset);
if (reported_length_remaining < 1) {
pinfo->desegment_offset = offset;
pinfo->desegment_len = DESEGMENT_ONE_MORE_SEGMENT;
return FALSE;
}
length_remaining = tvb_captured_length_remaining(tvb,
next_offset);
linelen = tvb_find_line_end(tvb, next_offset,
length_remaining, &chunk_offset, TRUE);
if (linelen == -1 &&
length_remaining >=
reported_length_remaining) {
pinfo->desegment_offset = offset;
pinfo->desegment_len = DESEGMENT_ONE_MORE_SEGMENT;
return FALSE;
}
chunk_string = tvb_get_string(wmem_packet_scope(), tvb, next_offset,
linelen);
c = chunk_string;
if ((c = strchr(c, ';'))) {
*c = '\0';
}
if (sscanf(chunk_string, "%x", &chunk_size) < 1) {
return TRUE;
}
if (chunk_size > (guint)1<<31) {
return TRUE;
}
if (chunk_size == 0) {
linelen = tvb_find_line_end(tvb,
chunk_offset, length_remaining, &chunk_offset, TRUE);
if (linelen == -1 &&
length_remaining >=
reported_length_remaining) {
pinfo->desegment_offset = offset;
pinfo->desegment_len = DESEGMENT_ONE_MORE_SEGMENT;
return FALSE;
}
pinfo->desegment_offset = chunk_offset;
pinfo->desegment_len = 0;
done_chunking = TRUE;
} else {
if (reported_length_remaining >
(gint) chunk_size) {
next_offset = chunk_offset
+ chunk_size + 2;
} else {
pinfo->desegment_offset = offset;
pinfo->desegment_len = DESEGMENT_ONE_MORE_SEGMENT;
return FALSE;
}
}
}
} else if (content_length_found) {
if (content_length >= 128*1024) {
gchar *tmp;
if (content_type_found &&
strncmp(content_type, "application/rpc", 15) == 0) {
return TRUE;
}
tmp = tvb_get_string(wmem_packet_scope(), tvb, 0, sizeof("RPC_OUT_DATA") - 1);
if ((strncmp(tmp, "RPC_IN_DATA", sizeof("RPC_IN_DATA") - 1) == 0) ||
(strncmp(tmp, "RPC_OUT_DATA", sizeof("RPC_OUT_DATA") - 1) == 0)) {
return TRUE;
}
}
if (!tvb_bytes_exist(tvb, next_offset, content_length)) {
length_remaining = tvb_captured_length_remaining(tvb,
next_offset);
reported_length_remaining =
tvb_reported_length_remaining(tvb, next_offset);
if (length_remaining < reported_length_remaining) {
return TRUE;
}
if (length_remaining == -1)
length_remaining = 0;
pinfo->desegment_offset = offset;
pinfo->desegment_len =
content_length - length_remaining;
return FALSE;
}
} else if (content_type_found && pinfo->can_desegment) {
length_remaining = tvb_captured_length_remaining(tvb, next_offset);
reported_length_remaining = tvb_reported_length_remaining(tvb, next_offset);
if (length_remaining < reported_length_remaining) {
return TRUE;
}
if (keepalive_found) {
return TRUE;
}
pinfo->desegment_offset = offset;
pinfo->desegment_len = DESEGMENT_UNTIL_FIN;
return FALSE;
}
}
return TRUE;
}
