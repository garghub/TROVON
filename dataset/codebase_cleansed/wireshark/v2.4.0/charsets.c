guint8 *
get_ascii_string(wmem_allocator_t *scope, const guint8 *ptr, gint length)
{
wmem_strbuf_t *str;
str = wmem_strbuf_sized_new(scope, length+1, 0);
while (length > 0) {
guint8 ch = *ptr;
if (ch < 0x80)
wmem_strbuf_append_c(str, ch);
else
wmem_strbuf_append_unichar(str, UNREPL);
ptr++;
length--;
}
return (guint8 *) wmem_strbuf_finalize(str);
}
guint8 *
get_8859_1_string(wmem_allocator_t *scope, const guint8 *ptr, gint length)
{
wmem_strbuf_t *str;
str = wmem_strbuf_sized_new(scope, length+1, 0);
while (length > 0) {
guint8 ch = *ptr;
if (ch < 0x80)
wmem_strbuf_append_c(str, ch);
else {
wmem_strbuf_append_unichar(str, ch);
}
ptr++;
length--;
}
return (guint8 *) wmem_strbuf_finalize(str);
}
guint8 *
get_unichar2_string(wmem_allocator_t *scope, const guint8 *ptr, gint length, const gunichar2 table[0x80])
{
wmem_strbuf_t *str;
str = wmem_strbuf_sized_new(scope, length+1, 0);
while (length > 0) {
guint8 ch = *ptr;
if (ch < 0x80)
wmem_strbuf_append_c(str, ch);
else
wmem_strbuf_append_unichar(str, table[ch-0x80]);
ptr++;
length--;
}
return (guint8 *) wmem_strbuf_finalize(str);
}
guint8 *
get_ucs_2_string(wmem_allocator_t *scope, const guint8 *ptr, gint length, const guint encoding)
{
gunichar2 uchar;
gint i;
wmem_strbuf_t *strbuf;
strbuf = wmem_strbuf_sized_new(scope, length+1, 0);
for(i = 0; i + 1 < length; i += 2) {
if (encoding == ENC_BIG_ENDIAN){
uchar = pntoh16(ptr + i);
}else{
uchar = pletoh16(ptr + i);
}
wmem_strbuf_append_unichar(strbuf, uchar);
}
return (guint8 *) wmem_strbuf_finalize(strbuf);
}
guint8 *
get_utf_16_string(wmem_allocator_t *scope, const guint8 *ptr, gint length, const guint encoding)
{
wmem_strbuf_t *strbuf;
gunichar2 uchar2, lead_surrogate;
gunichar uchar;
gint i;
strbuf = wmem_strbuf_sized_new(scope, length+1, 0);
for(i = 0; i + 1 < length; i += 2) {
if (encoding == ENC_BIG_ENDIAN)
uchar2 = pntoh16(ptr + i);
else
uchar2 = pletoh16(ptr + i);
if (IS_LEAD_SURROGATE(uchar2)) {
i += 2;
if (i + 1 >= length) {
break;
}
lead_surrogate = uchar2;
if (encoding == ENC_BIG_ENDIAN)
uchar2 = pntoh16(ptr + i);
else
uchar2 = pletoh16(ptr + i);
if (IS_TRAIL_SURROGATE(uchar2)) {
uchar = SURROGATE_VALUE(lead_surrogate, uchar2);
wmem_strbuf_append_unichar(strbuf, uchar);
} else {
;
}
} else {
if (IS_TRAIL_SURROGATE(uchar2)) {
;
} else {
wmem_strbuf_append_unichar(strbuf, uchar2);
}
}
}
return (guint8 *) wmem_strbuf_finalize(strbuf);
}
guint8 *
get_ucs_4_string(wmem_allocator_t *scope, const guint8 *ptr, gint length, const guint encoding)
{
gunichar uchar;
gint i;
wmem_strbuf_t *strbuf;
strbuf = wmem_strbuf_sized_new(scope, length+1, 0);
for(i = 0; i + 3 < length; i += 4) {
if (encoding == ENC_BIG_ENDIAN)
uchar = pntoh32(ptr + i);
else
uchar = pletoh32(ptr + i);
wmem_strbuf_append_unichar(strbuf, uchar);
}
return (gchar *)wmem_strbuf_finalize(strbuf);
}
static gunichar
GSM_to_UNICHAR(guint8 c)
{
if (c < G_N_ELEMENTS(gsm_default_alphabet))
return gsm_default_alphabet[c];
return UNREPL;
}
static gunichar
GSMext_to_UNICHAR(guint8 c)
{
switch (c)
{
case 0x0a: return 0x0c;
case 0x14: return '^';
case 0x28: return '{';
case 0x29: return '}';
case 0x2f: return '\\';
case 0x3c: return '[';
case 0x3d: return '~';
case 0x3e: return ']';
case 0x40: return '|';
case 0x65: return 0x20ac;
}
return UNREPL;
}
static gboolean
char_is_escape(unsigned char value)
{
return (value == GN_CHAR_ESCAPE);
}
static gboolean
handle_ts_23_038_char(wmem_strbuf_t *strbuf, guint8 code_point,
gboolean saw_escape)
{
gunichar uchar;
if (char_is_escape(code_point)) {
saw_escape = TRUE;
} else {
if (saw_escape) {
saw_escape = FALSE;
uchar = GSMext_to_UNICHAR(code_point);
} else {
uchar = GSM_to_UNICHAR(code_point);
}
wmem_strbuf_append_unichar(strbuf, uchar);
}
return saw_escape;
}
guint8 *
get_ts_23_038_7bits_string(wmem_allocator_t *scope, const guint8 *ptr,
const gint bit_offset, gint no_of_chars)
{
wmem_strbuf_t *strbuf;
gint char_count;
guint8 in_byte, out_byte, rest = 0x00;
const guint8 *start_ptr = ptr;
gboolean saw_escape = FALSE;
int bits;
strbuf = wmem_strbuf_sized_new(scope, no_of_chars+1, 0);
bits = bit_offset & 0x07;
if (!bits) {
bits = 7;
}
for(char_count = 0; char_count < no_of_chars; ptr++) {
in_byte = *ptr;
out_byte = ((in_byte & GN_BYTE_MASK) << (7 - bits)) | rest;
rest = in_byte >> bits;
if ((start_ptr != ptr) || (bits == 7)) {
saw_escape = handle_ts_23_038_char(strbuf, out_byte,
saw_escape);
char_count++;
}
if ((bits == 1) && (char_count < no_of_chars)) {
saw_escape = handle_ts_23_038_char(strbuf, rest,
saw_escape);
char_count++;
bits = 7;
rest = 0x00;
} else {
bits--;
}
}
if (saw_escape) {
wmem_strbuf_append_unichar(strbuf, UNREPL);
}
return (guint8 *)wmem_strbuf_finalize(strbuf);
}
guint8 *
get_ascii_7bits_string(wmem_allocator_t *scope, const guint8 *ptr,
const gint bit_offset, gint no_of_chars)
{
wmem_strbuf_t *strbuf;
gint char_count;
guint8 in_byte, out_byte, rest = 0x00;
const guint8 *start_ptr = ptr;
int bits;
bits = bit_offset & 0x07;
if (!bits) {
bits = 7;
}
strbuf = wmem_strbuf_sized_new(scope, no_of_chars+1, 0);
for(char_count = 0; char_count < no_of_chars; ptr++) {
in_byte = *ptr;
out_byte = (in_byte >> (8 - bits)) | rest;
rest = (in_byte << (bits - 1)) & 0x7f;
if ((start_ptr != ptr) || (bits == 7)) {
wmem_strbuf_append_c(strbuf, out_byte);
char_count++;
}
if ((bits == 1) && (char_count < no_of_chars)) {
wmem_strbuf_append_c(strbuf, rest);
char_count++;
bits = 7;
rest = 0x00;
} else {
bits--;
}
}
return (guint8 *)wmem_strbuf_finalize(strbuf);
}
void
EBCDIC_to_ASCII(guint8 *buf, guint bytes)
{
guint i;
guint8 *bufptr;
bufptr = buf;
for (i = 0; i < bytes; i++, bufptr++) {
*bufptr = EBCDIC_translate_ASCII[*bufptr];
}
}
guint8
EBCDIC_to_ASCII1(guint8 c)
{
return EBCDIC_translate_ASCII[c];
}
guint8 *
get_nonascii_unichar2_string(wmem_allocator_t *scope, const guint8 *ptr, gint length, const gunichar2 table[256])
{
wmem_strbuf_t *str;
str = wmem_strbuf_sized_new(scope, length+1, 0);
while (length > 0) {
guint8 ch = *ptr;
wmem_strbuf_append_unichar(str, table[ch]);
ptr++;
length--;
}
return (guint8 *) wmem_strbuf_finalize(str);
}
guint8 *
get_t61_string(wmem_allocator_t *scope, const guint8 *ptr, gint length)
{
gint i;
guint8 *c;
wmem_strbuf_t *strbuf;
strbuf = wmem_strbuf_sized_new(scope, length+1, 0);
for (i = 0, c = (guint8 *)ptr; i < length; c++, i++) {
if (!t61_tab[*c]) {
wmem_strbuf_append_unichar(strbuf, UNREPL);
} else if ((*c & 0xf0) == 0xc0) {
gint j = *c & 0x0f;
if ((!c[1] || c[1] == 0x20) && accents[j]) {
wmem_strbuf_append_unichar(strbuf, accents[j]);
} else if (cx_tab[j] && cx_tab[j][c[1]>>5] &&
(*cx_tab[j][c[1]>>5])[c[1]&0x1f]) {
wmem_strbuf_append_unichar(strbuf, (*cx_tab[j][c[1]>>5])[c[1]&0x1f]);
} else {
wmem_strbuf_append_unichar(strbuf, c[1]);
wmem_strbuf_append_unichar(strbuf, t61_tab[*c]);
}
c++; i++;
continue;
} else {
wmem_strbuf_append_unichar(strbuf, t61_tab[*c]);
}
}
return (guint8 *)wmem_strbuf_finalize(strbuf);
}
