int display_ms_string(tvbuff_t *tvb, proto_tree *tree, int offset, int hf_index, char **data)
{
char *str;
gint len;
str = tvb_get_stringz_enc(wmem_packet_scope(), tvb, offset, &len, ENC_ASCII);
proto_tree_add_string(tree, hf_index, tvb, offset, len, str);
if (data)
*data = str;
return offset+len;
}
int display_unicode_string(tvbuff_t *tvb, proto_tree *tree, int offset, int hf_index, char **data)
{
char *str, *p;
int len;
int charoffset;
guint16 character;
len = 0;
while (tvb_get_letohs(tvb, offset + len) != '\0')
len += 2;
len += 2;
str = (char *)wmem_alloc(wmem_packet_scope(), len/2);
charoffset = offset;
p = str;
while ((character = tvb_get_letohs(tvb, charoffset)) != '\0') {
*p++ = (char) character;
charoffset += 2;
}
*p = '\0';
proto_tree_add_string(tree, hf_index, tvb, offset, len, str);
if (data)
*data = str;
return offset+len;
}
int dissect_ms_compressed_string(tvbuff_t *tvb, proto_tree *tree, int offset, int hf_index,
const char **data)
{
int compr_len;
const guchar *str = NULL;
compr_len = expand_dns_name(tvb, offset, MAX_UNICODE_STR_LEN+3+1, 0, &str);
proto_tree_add_string(tree, hf_index, tvb, offset, compr_len, str);
if (data)
*data = str;
return offset + compr_len;
}
static gchar *
unicode_to_str(tvbuff_t *tvb, int offset, int *us_lenp, gboolean exactlen,
guint16 bc)
{
gchar *cur;
gchar *p;
guint16 uchar;
int len;
int us_len;
gboolean overflow = FALSE;
cur=(gchar *)wmem_alloc(wmem_packet_scope(), MAX_UNICODE_STR_LEN+3+1);
p = cur;
len = MAX_UNICODE_STR_LEN;
us_len = 0;
for (;;) {
if (bc == 0)
break;
if (bc == 1) {
if (!exactlen)
us_len += 1;
break;
}
uchar = tvb_get_letohs(tvb, offset);
if (uchar == 0) {
us_len += 2;
break;
}
if (len > 0) {
if ((uchar & 0xFF00) == 0)
*p++ = (gchar) uchar;
else
*p++ = '?';
len--;
} else
overflow = TRUE;
offset += 2;
bc -= 2;
us_len += 2;
if(exactlen){
if(us_len>= *us_lenp){
break;
}
}
}
if (overflow) {
*p++ = '.';
*p++ = '.';
*p++ = '.';
}
*p = '\0';
*us_lenp = us_len;
return cur;
}
const gchar *
get_unicode_or_ascii_string(tvbuff_t *tvb, int *offsetp,
gboolean useunicode, int *len, gboolean nopad, gboolean exactlen,
guint16 *bcp)
{
gchar *cur;
const gchar *string;
int string_len = 0;
int copylen;
gboolean overflow = FALSE;
if (*bcp == 0) {
return NULL;
}
if (useunicode) {
if ((!nopad) && (*offsetp % 2)) {
(*offsetp)++;
(*bcp)--;
if (*bcp == 0) {
return NULL;
}
}
if(exactlen){
string_len = *len;
if (string_len < 0) {
string_len = INT_MAX;
}
}
string = unicode_to_str(tvb, *offsetp, &string_len, exactlen, *bcp);
} else {
if(exactlen){
cur=(gchar *)wmem_alloc(wmem_packet_scope(), MAX_UNICODE_STR_LEN+3+1);
copylen = *len;
if (copylen < 0) {
copylen = INT_MAX;
}
tvb_ensure_bytes_exist(tvb, *offsetp, copylen);
if (copylen > MAX_UNICODE_STR_LEN) {
copylen = MAX_UNICODE_STR_LEN;
overflow = TRUE;
}
tvb_memcpy(tvb, (guint8 *)cur, *offsetp, copylen);
cur[copylen] = '\0';
if (overflow)
g_strlcat(cur, "...",MAX_UNICODE_STR_LEN+3+1);
string_len = *len;
string = cur;
} else {
string = tvb_get_const_stringz(tvb, *offsetp, &string_len);
}
}
*len = string_len;
return string;
}
