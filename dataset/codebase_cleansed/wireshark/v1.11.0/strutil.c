const guchar *
find_line_end(const guchar *data, const guchar *dataend, const guchar **eol)
{
const guchar *lineend;
lineend = (guchar *)memchr(data, '\n', dataend - data);
if (lineend == NULL) {
lineend = dataend;
*eol = dataend;
} else {
if (lineend > data) {
if (*(lineend - 1) == '\r') {
*eol = lineend - 1;
} else {
*eol = lineend;
if (lineend < (dataend - 1) && *(lineend + 1) == '\r') {
lineend++;
}
}
} else {
*eol = lineend;
}
lineend++;
}
return lineend;
}
int
get_token_len(const guchar *linep, const guchar *lineend,
const guchar **next_token)
{
const guchar *tokenp;
int token_len;
tokenp = linep;
while (linep < lineend && *linep != ' ' && *linep != '\r' && *linep != '\n')
linep++;
token_len = (int) (linep - tokenp);
while (linep < lineend && *linep == ' ')
linep++;
*next_token = linep;
return token_len;
}
gchar *
format_text(const guchar *string, size_t len)
{
static gchar *fmtbuf[3];
static int fmtbuf_len[3];
static int idx;
int column;
const guchar *stringend = string + len;
guchar c;
int i;
idx = (idx + 1) % 3;
if (fmtbuf[idx] == NULL) {
fmtbuf[idx] = (gchar *)g_malloc(INITIAL_FMTBUF_SIZE);
fmtbuf_len[idx] = INITIAL_FMTBUF_SIZE;
}
column = 0;
while (string < stringend) {
if (column+3+1 >= fmtbuf_len[idx]) {
fmtbuf_len[idx] = fmtbuf_len[idx] * 2;
fmtbuf[idx] = (gchar *)g_realloc(fmtbuf[idx], fmtbuf_len[idx]);
}
c = *string++;
if (isprint(c)) {
fmtbuf[idx][column] = c;
column++;
} else {
fmtbuf[idx][column] = '\\';
column++;
switch (c) {
case '\a':
fmtbuf[idx][column] = 'a';
column++;
break;
case '\b':
fmtbuf[idx][column] = 'b';
column++;
break;
case '\f':
fmtbuf[idx][column] = 'f';
column++;
break;
case '\n':
fmtbuf[idx][column] = 'n';
column++;
break;
case '\r':
fmtbuf[idx][column] = 'r';
column++;
break;
case '\t':
fmtbuf[idx][column] = 't';
column++;
break;
case '\v':
fmtbuf[idx][column] = 'v';
column++;
break;
default:
i = (c>>6)&03;
fmtbuf[idx][column] = i + '0';
column++;
i = (c>>3)&07;
fmtbuf[idx][column] = i + '0';
column++;
i = (c>>0)&07;
fmtbuf[idx][column] = i + '0';
column++;
break;
}
}
}
fmtbuf[idx][column] = '\0';
return fmtbuf[idx];
}
gchar *
format_text_wsp(const guchar *string, size_t len)
{
static gchar *fmtbuf[3];
static int fmtbuf_len[3];
static int idx;
int column;
const guchar *stringend = string + len;
guchar c;
int i;
idx = (idx + 1) % 3;
if (fmtbuf[idx] == NULL) {
fmtbuf[idx] = (gchar *)g_malloc(INITIAL_FMTBUF_SIZE);
fmtbuf_len[idx] = INITIAL_FMTBUF_SIZE;
}
column = 0;
while (string < stringend) {
if (column+3+1 >= fmtbuf_len[idx]) {
fmtbuf_len[idx] = fmtbuf_len[idx] * 2;
fmtbuf[idx] = (gchar *)g_realloc(fmtbuf[idx], fmtbuf_len[idx]);
}
c = *string++;
if (isprint(c)) {
fmtbuf[idx][column] = c;
column++;
} else if (isspace(c)) {
fmtbuf[idx][column] = ' ';
column++;
} else {
fmtbuf[idx][column] = '\\';
column++;
switch (c) {
case '\a':
fmtbuf[idx][column] = 'a';
column++;
break;
case '\b':
fmtbuf[idx][column] = 'b';
column++;
break;
case '\f':
fmtbuf[idx][column] = 'f';
column++;
break;
case '\n':
fmtbuf[idx][column] = 'n';
column++;
break;
case '\r':
fmtbuf[idx][column] = 'r';
column++;
break;
case '\t':
fmtbuf[idx][column] = 't';
column++;
break;
case '\v':
fmtbuf[idx][column] = 'v';
column++;
break;
default:
i = (c>>6)&03;
fmtbuf[idx][column] = i + '0';
column++;
i = (c>>3)&07;
fmtbuf[idx][column] = i + '0';
column++;
i = (c>>0)&07;
fmtbuf[idx][column] = i + '0';
column++;
break;
}
}
}
fmtbuf[idx][column] = '\0';
return fmtbuf[idx];
}
gchar *
format_text_chr(const guchar *string, const size_t len, const guchar chr)
{
static gchar *fmtbuf[3];
static int fmtbuf_len[3];
static int idx;
int column;
const guchar *stringend = string + len;
guchar c;
idx = (idx + 1) % 3;
if (fmtbuf[idx] == NULL) {
fmtbuf[idx] = (gchar *)g_malloc(INITIAL_FMTBUF_SIZE);
fmtbuf_len[idx] = INITIAL_FMTBUF_SIZE;
}
column = 0;
while (string < stringend)
{
if (column+1 >= fmtbuf_len[idx])
{
fmtbuf_len[idx] = fmtbuf_len[idx] * 2;
fmtbuf[idx] = (gchar *)g_realloc(fmtbuf[idx], fmtbuf_len[idx]);
}
c = *string++;
if (isprint(c))
{
fmtbuf[idx][column] = c;
column++;
}
else if (isspace(c))
{
fmtbuf[idx][column] = ' ';
column++;
}
else
{
fmtbuf[idx][column] = chr;
column++;
}
}
fmtbuf[idx][column] = '\0';
return fmtbuf[idx];
}
static gboolean
is_byte_sep(guint8 c)
{
return (c == '-' || c == ':' || c == '.');
}
gboolean
hex_str_to_bytes(const char *hex_str, GByteArray *bytes, gboolean force_separators) {
guint8 val;
const guchar *p, *q, *r, *s, *punct;
char four_digits_first_half[3];
char four_digits_second_half[3];
char two_digits[3];
char one_digit[2];
if (! hex_str || ! bytes) {
return FALSE;
}
g_byte_array_set_size(bytes, 0);
p = (const guchar *)hex_str;
while (*p) {
q = p+1;
r = p+2;
s = p+3;
if (*q && *r && *s
&& isxdigit(*p) && isxdigit(*q) &&
isxdigit(*r) && isxdigit(*s)) {
four_digits_first_half[0] = *p;
four_digits_first_half[1] = *q;
four_digits_first_half[2] = '\0';
four_digits_second_half[0] = *r;
four_digits_second_half[1] = *s;
four_digits_second_half[2] = '\0';
val = (guint8) strtoul(four_digits_first_half, NULL, 16);
g_byte_array_append(bytes, &val, 1);
val = (guint8) strtoul(four_digits_second_half, NULL, 16);
g_byte_array_append(bytes, &val, 1);
punct = s + 1;
if (*punct) {
if (is_byte_sep(*punct)) {
p = punct + 1;
continue;
}
else if (force_separators) {
return FALSE;
}
}
p = punct;
continue;
}
else if (*q && isxdigit(*p) && isxdigit(*q)) {
two_digits[0] = *p;
two_digits[1] = *q;
two_digits[2] = '\0';
val = (guint8) strtoul(two_digits, NULL, 16);
g_byte_array_append(bytes, &val, 1);
punct = q + 1;
if (*punct) {
if (is_byte_sep(*punct)) {
p = punct + 1;
continue;
}
else if (force_separators) {
return FALSE;
}
}
p = punct;
continue;
}
else if (*q && isxdigit(*p) && is_byte_sep(*q)) {
one_digit[0] = *p;
one_digit[1] = '\0';
val = (guint8) strtoul(one_digit, NULL, 16);
g_byte_array_append(bytes, &val, 1);
p = q + 1;
continue;
}
else if (!*q && isxdigit(*p)) {
one_digit[0] = *p;
one_digit[1] = '\0';
val = (guint8) strtoul(one_digit, NULL, 16);
g_byte_array_append(bytes, &val, 1);
p = q;
continue;
}
else {
return FALSE;
}
}
return TRUE;
}
gboolean
uri_str_to_bytes(const char *uri_str, GByteArray *bytes) {
guint8 val;
const guchar *p;
guchar hex_digit[HEX_DIGIT_BUF_LEN];
g_byte_array_set_size(bytes, 0);
if (! uri_str) {
return FALSE;
}
p = (const guchar *)uri_str;
while (*p) {
if (! isascii(*p) || ! isprint(*p))
return FALSE;
if (*p == '%') {
p++;
if (*p == '\0') return FALSE;
hex_digit[0] = *p;
p++;
if (*p == '\0') return FALSE;
hex_digit[1] = *p;
hex_digit[2] = '\0';
if (! isxdigit(hex_digit[0]) || ! isxdigit(hex_digit[1]))
return FALSE;
val = (guint8) strtoul((char *)hex_digit, NULL, 16);
g_byte_array_append(bytes, &val, 1);
} else {
g_byte_array_append(bytes, (const guint8 *) p, 1);
}
p++;
}
return TRUE;
}
const gchar *
format_uri(const GByteArray *bytes, const gchar *reserved_chars)
{
static gchar *fmtbuf[3];
static guint fmtbuf_len[3];
static guint idx;
static const guchar *reserved_def = ":/?#[]@!$&'()*+,;= ";
const guchar *reserved = reserved_def;
guint8 c;
guint column, i;
gboolean is_reserved = FALSE;
if (! bytes)
return "";
idx = (idx + 1) % 3;
if (reserved_chars)
reserved = reserved_chars;
if (fmtbuf[idx] == NULL) {
fmtbuf[idx] = (gchar *)g_malloc(INITIAL_FMTBUF_SIZE);
fmtbuf_len[idx] = INITIAL_FMTBUF_SIZE;
}
for (column = 0; column < bytes->len; column++) {
if (column+2+1 >= fmtbuf_len[idx]) {
fmtbuf_len[idx] = fmtbuf_len[idx] * 2;
fmtbuf[idx] = (gchar *)g_realloc(fmtbuf[idx], fmtbuf_len[idx]);
}
c = bytes->data[column];
if (!isascii(c) || !isprint(c) || c == '%') {
is_reserved = TRUE;
}
for (i = 0; reserved[i]; i++) {
if (c == reserved[i])
is_reserved = TRUE;
}
if (!is_reserved) {
fmtbuf[idx][column] = c;
} else {
fmtbuf[idx][column] = '%';
column++;
fmtbuf[idx][column] = hex[c >> 4];
column++;
fmtbuf[idx][column] = hex[c & 0xF];
}
}
fmtbuf[idx][column] = '\0';
return fmtbuf[idx];
}
GByteArray *
byte_array_dup(GByteArray *ba) {
GByteArray *new_ba;
if (!ba)
return NULL;
new_ba = g_byte_array_new();
g_byte_array_append(new_ba, ba->data, ba->len);
return new_ba;
}
gboolean
oid_str_to_bytes(const char *oid_str, GByteArray *bytes) {
return rel_oid_str_to_bytes(oid_str, bytes, TRUE);
}
gboolean
rel_oid_str_to_bytes(const char *oid_str, GByteArray *bytes, gboolean is_absolute) {
guint32 subid0, subid, sicnt, i;
const char *p, *dot;
guint8 buf[SUBID_BUF_LEN];
g_byte_array_set_size(bytes, 0);
p = oid_str;
dot = NULL;
while (*p) {
if (!isdigit((guchar)*p) && (*p != '.')) return FALSE;
if (*p == '.') {
if (p == oid_str && is_absolute) return FALSE;
if (!*(p+1)) return FALSE;
if ((p-1) == dot) return FALSE;
dot = p;
}
p++;
}
if (!dot) return FALSE;
p = oid_str;
sicnt = is_absolute ? 0 : 2;
if (!is_absolute) p++;
subid0 = 0;
while (*p) {
subid = 0;
while (isdigit((guchar)*p)) {
subid *= 10;
subid += *p - '0';
p++;
}
if (sicnt == 0) {
subid0 = subid;
if (subid0 > 2) return FALSE;
} else if (sicnt == 1) {
if ((subid0 < 2) && (subid > 39)) return FALSE;
subid += 40 * subid0;
}
if (sicnt) {
i = SUBID_BUF_LEN;
do {
i--;
buf[i] = 0x80 | (subid % 0x80);
subid >>= 7;
} while (subid && i);
buf[SUBID_BUF_LEN-1] &= 0x7F;
g_byte_array_append(bytes, buf + i, SUBID_BUF_LEN - i);
}
sicnt++;
if (*p) p++;
}
return TRUE;
}
gboolean
byte_array_equal(GByteArray *ba1, GByteArray *ba2) {
if (!ba1 || !ba2)
return FALSE;
if (ba1->len != ba2->len)
return FALSE;
if (memcmp(ba1->data, ba2->data, ba1->len) != 0)
return FALSE;
return TRUE;
}
gchar *
xml_escape(const gchar *unescaped)
{
GString *buffer = g_string_sized_new(128);
const gchar *p;
gchar c;
p = unescaped;
while ( (c = *p++) ) {
switch (c) {
case '<':
g_string_append(buffer, "&lt;");
break;
case '>':
g_string_append(buffer, "&gt;");
break;
case '&':
g_string_append(buffer, "&amp;");
break;
case '\'':
g_string_append(buffer, "&apos;");
break;
case '"':
g_string_append(buffer, "&quot;");
break;
default:
g_string_append_c(buffer, c);
break;
}
}
return g_string_free(buffer, FALSE);
}
const guint8 *
epan_memmem(const guint8 *haystack, guint haystack_len,
const guint8 *needle, guint needle_len)
{
const guint8 *begin;
const guint8 *const last_possible = haystack + haystack_len - needle_len;
if (needle_len == 0) {
return NULL;
}
if (needle_len > haystack_len) {
return NULL;
}
for (begin = haystack ; begin <= last_possible; ++begin) {
if (begin[0] == needle[0] &&
!memcmp(&begin[1], needle + 1,
needle_len - 1)) {
return begin;
}
}
return NULL;
}
guint8 *
convert_string_to_hex(const char *string, size_t *nbytes)
{
size_t n_bytes;
const char *p;
guchar c;
guint8 *bytes, *q, byte_val;
n_bytes = 0;
p = &string[0];
for (;;) {
c = *p++;
if (c == '\0')
break;
if (isspace(c))
continue;
if (c==':' || c=='.' || c=='-')
continue;
if (!isxdigit(c)) {
return NULL;
}
c = *p++;
if (!isxdigit(c))
return NULL;
n_bytes++;
}
if (n_bytes == 0) {
return NULL;
}
bytes = (guint8 *)g_malloc(n_bytes);
p = &string[0];
q = &bytes[0];
for (;;) {
c = *p++;
if (c == '\0')
break;
if (isspace(c))
continue;
if (c==':' || c=='.' || c=='-')
continue;
if (isdigit(c))
byte_val = c - '0';
else if (c >= 'a')
byte_val = (c - 'a') + 10;
else
byte_val = (c - 'A') + 10;
byte_val <<= 4;
c = *p++;
if (isdigit(c))
byte_val |= c - '0';
else if (c >= 'a')
byte_val |= (c - 'a') + 10;
else if (c >= 'A')
byte_val |= (c - 'A') + 10;
*q++ = byte_val;
}
*nbytes = n_bytes;
return bytes;
}
char *
convert_string_case(const char *string, gboolean case_insensitive)
{
if (case_insensitive) {
return g_utf8_strup(string, -1);
} else {
return g_strdup(string);
}
}
char *
epan_strcasestr(const char *haystack, const char *needle)
{
gsize hlen = strlen(haystack);
gsize nlen = strlen(needle);
while (hlen-- >= nlen) {
if (!g_ascii_strncasecmp(haystack, needle, nlen))
return (char*) haystack;
haystack++;
}
return NULL;
}
const char *
string_or_null(const char *string)
{
if (string)
return string;
return "[NULL]";
}
int
escape_string_len(const char *string)
{
const char *p;
gchar c;
int repr_len;
repr_len = 0;
for (p = string; (c = *p) != '\0'; p++) {
if (c == '\\' || c == '"') {
repr_len += 2;
}
else if (!isprint((unsigned char)c)) {
repr_len += 4;
}
else {
repr_len++;
}
}
return repr_len + 2;
}
char *
escape_string(char *buf, const char *string)
{
const gchar *p;
gchar c;
char *bufp;
char hexbuf[3];
bufp = buf;
*bufp++ = '"';
for (p = string; (c = *p) != '\0'; p++) {
if (c == '\\' || c == '"') {
*bufp++ = '\\';
*bufp++ = c;
}
else if (!isprint((unsigned char)c)) {
g_snprintf(hexbuf,sizeof(hexbuf), "%02x", (unsigned char) c);
*bufp++ = '\\';
*bufp++ = 'x';
*bufp++ = hexbuf[0];
*bufp++ = hexbuf[1];
}
else {
*bufp++ = c;
}
}
*bufp++ = '"';
*bufp = '\0';
return buf;
}
static gunichar
char_def_ia5_alphabet_decode(unsigned char value)
{
if (value < GN_CHAR_ALPHABET_SIZE) {
return IA5_default_alphabet[value];
}
else {
return '?';
}
}
void
IA5_7BIT_decode(unsigned char * dest, const unsigned char* src, int len)
{
int i, j;
gunichar buf;
for (i = 0, j = 0; j < len; j++) {
buf = char_def_ia5_alphabet_decode(src[j]);
i += g_unichar_to_utf8(buf,&(dest[i]));
}
dest[i]=0;
return;
}
gchar*
ws_strdup_escape_char (const gchar *str, const gchar chr)
{
const gchar *p;
gchar *q, *new_str;
if(!str)
return NULL;
p = str;
q = new_str = (gchar *)g_malloc (strlen(str) * 2 + 1);
while(*p != 0) {
if(*p == chr)
*q++ = chr;
*q++ = *p++;
}
*q = '\0';
return new_str;
}
gchar*
ws_strdup_unescape_char (const gchar *str, const char chr)
{
const gchar *p;
gchar *q, *new_str;
if(!str)
return NULL;
p = str;
q = new_str = (gchar *)g_malloc (strlen(str) + 1);
while(*p != 0) {
*q++ = *p;
if ((*p == chr) && (*(p+1) == chr))
p += 2;
else
p++;
}
*q = '\0';
return new_str;
}
gchar *string_replace(const gchar* str, const gchar *old_val, const gchar *new_val) {
gchar **str_parts;
gchar *new_str;
if (!str || !old_val) {
return NULL;
}
str_parts = g_strsplit(str, old_val, 0);
new_str = g_strjoinv(new_val, str_parts);
g_strfreev(str_parts);
return new_str;
}
