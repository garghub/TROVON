static inline char *
byte_to_hex(char *out, guint32 dword) {
static const gchar hex_digits[16] =
{ '0', '1', '2', '3', '4', '5', '6', '7',
'8', '9', 'a', 'b', 'c', 'd', 'e', 'f' };
*out++ = hex_digits[(dword >> 4) & 0xF];
*out++ = hex_digits[dword & 0xF];
return out;
}
char *
word_to_hex(char *out, guint16 word) {
out = byte_to_hex(out, word >> 8);
out = byte_to_hex(out, word);
return out;
}
char *
word_to_hex_npad(char *out, guint16 word) {
static const gchar hex_digits[16] =
{ '0', '1', '2', '3', '4', '5', '6', '7',
'8', '9', 'a', 'b', 'c', 'd', 'e', 'f' };
if (word >= 0x1000)
*out++ = hex_digits[(word >> 12) & 0xF];
if (word >= 0x0100)
*out++ = hex_digits[(word >> 8) & 0xF];
if (word >= 0x0010)
*out++ = hex_digits[(word >> 4) & 0xF];
*out++ = hex_digits[word & 0xF];
return out;
}
char *
dword_to_hex(char *out, guint32 dword) {
out = byte_to_hex(out, dword >> 24);
out = byte_to_hex(out, dword >> 16);
out = byte_to_hex(out, dword >> 8);
out = byte_to_hex(out, dword);
return out;
}
char *
dword_to_hex_punct(char *out, guint32 dword, char punct) {
out = byte_to_hex(out, dword >> 24);
*out++ = punct;
out = byte_to_hex(out, dword >> 16);
*out++ = punct;
out = byte_to_hex(out, dword >> 8);
*out++ = punct;
out = byte_to_hex(out, dword);
return out;
}
char *
bytes_to_hexstr(char *out, const guint8 *ad, guint32 len) {
guint32 i;
if (!ad)
REPORT_DISSECTOR_BUG("Null pointer passed to bytes_to_hexstr()");
for (i = 0; i < len; i++)
out = byte_to_hex(out, ad[i]);
return out;
}
char *
bytes_to_hexstr_punct(char *out, const guint8 *ad, guint32 len, char punct) {
guint32 i;
if (!ad)
REPORT_DISSECTOR_BUG("Null pointer passed to bytes_to_hexstr_punct()");
out = byte_to_hex(out, ad[0]);
for (i = 1; i < len; i++) {
*out++ = punct;
out = byte_to_hex(out, ad[i]);
}
return out;
}
gchar *
bytestring_to_str(const guint8 *ad, const guint32 len, const char punct) {
gchar *buf;
size_t buflen;
if (!ad)
REPORT_DISSECTOR_BUG("Null pointer passed to bytestring_to_str()");
if ( ((int) len) < 0)
return "";
if (!len)
return "";
if (punct)
buflen=len*3;
else
buflen=len*2 + 1;
buf=ep_alloc(buflen);
if (punct)
bytes_to_hexstr_punct(buf, ad, len, punct);
else
bytes_to_hexstr(buf, ad, len);
buf[buflen-1] = '\0';
return buf;
}
gchar *
bytes_to_str(const guint8 *bd, int bd_len) {
gchar *cur;
gchar *cur_ptr;
int truncated = 0;
if (!bd)
REPORT_DISSECTOR_BUG("Null pointer passed to bytes_to_str()");
cur=ep_alloc(MAX_BYTE_STR_LEN+3+1);
if (bd_len <= 0) { cur[0] = '\0'; return cur; }
if (bd_len > MAX_BYTE_STR_LEN/2) {
truncated = 1;
bd_len = MAX_BYTE_STR_LEN/2;
}
cur_ptr = bytes_to_hexstr(cur, bd, bd_len);
if (truncated)
cur_ptr = g_stpcpy(cur_ptr, "...");
*cur_ptr = '\0';
return cur;
}
gchar *
bytes_to_str_punct(const guint8 *bd, int bd_len, gchar punct) {
gchar *cur;
gchar *cur_ptr;
int truncated = 0;
if (!punct)
return bytes_to_str(bd, bd_len);
cur=ep_alloc(MAX_BYTE_STR_LEN+3+1);
if (bd_len <= 0) { cur[0] = '\0'; return cur; }
if (bd_len > MAX_BYTE_STR_LEN/3) {
truncated = 1;
bd_len = MAX_BYTE_STR_LEN/3;
}
cur_ptr = bytes_to_hexstr_punct(cur, bd, bd_len, punct);
if (truncated) {
*cur_ptr++ = punct;
cur_ptr = g_stpcpy(cur_ptr, "...");
}
*cur_ptr = '\0';
return cur;
}
static int
guint32_to_str_buf_len(const guint32 u) {
if (u >= 1000000000)return 10;
if (u >= 100000000) return 9;
if (u >= 10000000) return 8;
if (u >= 1000000) return 7;
if (u >= 100000) return 6;
if (u >= 10000) return 5;
if (u >= 1000) return 4;
if (u >= 100) return 3;
if (u >= 10) return 2;
return 1;
}
void
guint32_to_str_buf(guint32 u, gchar *buf, int buf_len) {
int str_len = guint32_to_str_buf_len(u)+1;
gchar *bp = &buf[str_len];
gchar const *p;
if (buf_len < str_len) {
g_strlcpy(buf, BUF_TOO_SMALL_ERR, buf_len);
return;
}
*--bp = '\0';
while (u >= 10) {
p = fast_strings[100 + (u % 100)];
*--bp = p[2];
*--bp = p[1];
u /= 100;
}
if (bp != buf)
*--bp = (u % 10) | '0';
}
gchar *
guint32_to_str(const guint32 u) {
int str_len = 16;
gchar *bp = ep_alloc(str_len);
guint32_to_str_buf(u, bp, str_len);
return bp;
}
static void
time_secs_to_str_buf(gint32 time_val, const guint32 frac, const gboolean is_nsecs,
emem_strbuf_t *buf)
{
int hours, mins, secs;
const gchar *msign = "";
gboolean do_comma = FALSE;
if(time_val == G_MININT32) {
ep_strbuf_append_printf(buf, "Unable to cope with time value %d", time_val);
return;
}
if(time_val < 0){
time_val = -time_val;
msign = "-";
}
secs = time_val % 60;
time_val /= 60;
mins = time_val % 60;
time_val /= 60;
hours = time_val % 24;
time_val /= 24;
if (time_val != 0) {
ep_strbuf_append_printf(buf, "%s%u day%s", msign, time_val, PLURALIZE(time_val));
do_comma = TRUE;
msign="";
}
if (hours != 0) {
ep_strbuf_append_printf(buf, "%s%s%u hour%s", COMMA(do_comma), msign, hours, PLURALIZE(hours));
do_comma = TRUE;
msign="";
}
if (mins != 0) {
ep_strbuf_append_printf(buf, "%s%s%u minute%s", COMMA(do_comma), msign, mins, PLURALIZE(mins));
do_comma = TRUE;
msign="";
}
if (secs != 0 || frac != 0) {
if (frac != 0) {
if (is_nsecs)
ep_strbuf_append_printf(buf, "%s%s%u.%09u seconds", COMMA(do_comma), msign, secs, frac);
else
ep_strbuf_append_printf(buf, "%s%s%u.%03u seconds", COMMA(do_comma), msign, secs, frac);
} else
ep_strbuf_append_printf(buf, "%s%s%u second%s", COMMA(do_comma), msign, secs, PLURALIZE(secs));
}
}
gchar *
time_secs_to_str(const gint32 time_val)
{
emem_strbuf_t *buf;
buf=ep_strbuf_sized_new(TIME_SECS_LEN+1, TIME_SECS_LEN+1);
if (time_val == 0) {
ep_strbuf_append(buf, "0 seconds");
return buf->str;
}
time_secs_to_str_buf(time_val, 0, FALSE, buf);
return buf->str;
}
static void
time_secs_to_str_buf_unsigned(guint32 time_val, const guint32 frac, const gboolean is_nsecs,
emem_strbuf_t *buf)
{
int hours, mins, secs;
gboolean do_comma = FALSE;
secs = time_val % 60;
time_val /= 60;
mins = time_val % 60;
time_val /= 60;
hours = time_val % 24;
time_val /= 24;
if (time_val != 0) {
ep_strbuf_append_printf(buf, "%u day%s", time_val, PLURALIZE(time_val));
do_comma = TRUE;
}
if (hours != 0) {
ep_strbuf_append_printf(buf, "%s%u hour%s", COMMA(do_comma), hours, PLURALIZE(hours));
do_comma = TRUE;
}
if (mins != 0) {
ep_strbuf_append_printf(buf, "%s%u minute%s", COMMA(do_comma), mins, PLURALIZE(mins));
do_comma = TRUE;
}
if (secs != 0 || frac != 0) {
if (frac != 0) {
if (is_nsecs)
ep_strbuf_append_printf(buf, "%s%u.%09u seconds", COMMA(do_comma), secs, frac);
else
ep_strbuf_append_printf(buf, "%s%u.%03u seconds", COMMA(do_comma), secs, frac);
} else
ep_strbuf_append_printf(buf, "%s%u second%s", COMMA(do_comma), secs, PLURALIZE(secs));
}
}
gchar *
time_secs_to_str_unsigned(const guint32 time_val)
{
emem_strbuf_t *buf;
buf=ep_strbuf_sized_new(TIME_SECS_LEN+1, TIME_SECS_LEN+1);
if (time_val == 0) {
ep_strbuf_append(buf, "0 seconds");
return buf->str;
}
time_secs_to_str_buf_unsigned(time_val, 0, FALSE, buf);
return buf->str;
}
gchar *
time_msecs_to_str(gint32 time_val)
{
emem_strbuf_t *buf;
int msecs;
buf=ep_strbuf_sized_new(TIME_SECS_LEN+1+3+1, TIME_SECS_LEN+1+3+1);
if (time_val == 0) {
ep_strbuf_append(buf, "0 seconds");
return buf->str;
}
if(time_val<0){
time_val= -time_val;
msecs = time_val % 1000;
time_val /= 1000;
time_val= -time_val;
} else {
msecs = time_val % 1000;
time_val /= 1000;
}
time_secs_to_str_buf(time_val, msecs, FALSE, buf);
return buf->str;
}
static const gchar *get_zonename(struct tm *tmp) {
#if defined(HAVE_TM_ZONE)
return tmp->tm_zone;
#else
if ((tmp->tm_isdst != 0) && (tmp->tm_isdst != 1)) {
return "???";
}
# if defined(HAVE_TZNAME)
return tzname[tmp->tm_isdst];
# elif defined(_WIN32)
{
static char *ws_tzname[2] = {NULL, NULL};
if (ws_tzname[tmp->tm_isdst] == NULL) {
ws_tzname[tmp->tm_isdst] = g_locale_to_utf8(_tzname[tmp->tm_isdst], -1, NULL, NULL, NULL);
if (ws_tzname[tmp->tm_isdst] == NULL) {
ws_tzname[tmp->tm_isdst] = "???";
}
}
return ws_tzname[tmp->tm_isdst];
}
# else
return tmp->tm_isdst ? "?DT" : "?ST";
# endif
#endif
}
gchar *
abs_time_to_str(const nstime_t *abs_time, const absolute_time_display_e fmt,
gboolean show_zone)
{
struct tm *tmp = NULL;
const char *zonename = "???";
gchar *buf = NULL;
#ifdef _MSC_VER
if(abs_time->secs > 2000000000) {
tmp = NULL;
} else
#endif
switch (fmt) {
case ABSOLUTE_TIME_UTC:
case ABSOLUTE_TIME_DOY_UTC:
tmp = gmtime(&abs_time->secs);
zonename = "UTC";
break;
case ABSOLUTE_TIME_LOCAL:
tmp = localtime(&abs_time->secs);
if (tmp) {
zonename = get_zonename(tmp);
}
break;
}
if (tmp) {
switch (fmt) {
case ABSOLUTE_TIME_DOY_UTC:
if (show_zone) {
buf = ep_strdup_printf("%04d/%03d:%02d:%02d:%02d.%09ld %s",
tmp->tm_year + 1900,
tmp->tm_yday + 1,
tmp->tm_hour,
tmp->tm_min,
tmp->tm_sec,
(long)abs_time->nsecs,
zonename);
} else {
buf = ep_strdup_printf("%04d/%03d:%02d:%02d:%02d.%09ld",
tmp->tm_year + 1900,
tmp->tm_yday + 1,
tmp->tm_hour,
tmp->tm_min,
tmp->tm_sec,
(long)abs_time->nsecs);
}
break;
case ABSOLUTE_TIME_UTC:
case ABSOLUTE_TIME_LOCAL:
if (show_zone) {
buf = ep_strdup_printf("%s %2d, %d %02d:%02d:%02d.%09ld %s",
mon_names[tmp->tm_mon],
tmp->tm_mday,
tmp->tm_year + 1900,
tmp->tm_hour,
tmp->tm_min,
tmp->tm_sec,
(long)abs_time->nsecs,
zonename);
} else {
buf = ep_strdup_printf("%s %2d, %d %02d:%02d:%02d.%09ld",
mon_names[tmp->tm_mon],
tmp->tm_mday,
tmp->tm_year + 1900,
tmp->tm_hour,
tmp->tm_min,
tmp->tm_sec,
(long)abs_time->nsecs);
}
break;
}
} else
buf = ep_strdup("Not representable");
return buf;
}
gchar *
abs_time_secs_to_str(const time_t abs_time, const absolute_time_display_e fmt,
gboolean show_zone)
{
struct tm *tmp = NULL;
const char *zonename = "???";
gchar *buf = NULL;
#ifdef _MSC_VER
if(abs_time > 2000000000) {
tmp = NULL;
} else
#endif
switch (fmt) {
case ABSOLUTE_TIME_UTC:
case ABSOLUTE_TIME_DOY_UTC:
tmp = gmtime(&abs_time);
zonename = "UTC";
break;
case ABSOLUTE_TIME_LOCAL:
tmp = localtime(&abs_time);
if (tmp) {
zonename = get_zonename(tmp);
}
break;
}
if (tmp) {
switch (fmt) {
case ABSOLUTE_TIME_DOY_UTC:
if (show_zone) {
buf = ep_strdup_printf("%04d/%03d:%02d:%02d:%02d %s",
tmp->tm_year + 1900,
tmp->tm_yday + 1,
tmp->tm_hour,
tmp->tm_min,
tmp->tm_sec,
zonename);
} else {
buf = ep_strdup_printf("%04d/%03d:%02d:%02d:%02d",
tmp->tm_year + 1900,
tmp->tm_yday + 1,
tmp->tm_hour,
tmp->tm_min,
tmp->tm_sec);
}
break;
case ABSOLUTE_TIME_UTC:
case ABSOLUTE_TIME_LOCAL:
if (show_zone) {
buf = ep_strdup_printf("%s %2d, %d %02d:%02d:%02d %s",
mon_names[tmp->tm_mon],
tmp->tm_mday,
tmp->tm_year + 1900,
tmp->tm_hour,
tmp->tm_min,
tmp->tm_sec,
zonename);
} else {
buf = ep_strdup_printf("%s %2d, %d %02d:%02d:%02d",
mon_names[tmp->tm_mon],
tmp->tm_mday,
tmp->tm_year + 1900,
tmp->tm_hour,
tmp->tm_min,
tmp->tm_sec);
}
break;
}
} else
buf = ep_strdup("Not representable");
return buf;
}
void
display_signed_time(gchar *buf, int buflen, const gint32 sec, gint32 frac,
const to_str_time_res_t units)
{
if (frac < 0) {
frac = -frac;
if (sec >= 0) {
if (buflen < 1) {
return;
}
buf[0] = '-';
buf++;
buflen--;
}
}
switch (units) {
case TO_STR_TIME_RES_T_SECS:
g_snprintf(buf, buflen, "%d", sec);
break;
case TO_STR_TIME_RES_T_DSECS:
g_snprintf(buf, buflen, "%d.%01d", sec, frac);
break;
case TO_STR_TIME_RES_T_CSECS:
g_snprintf(buf, buflen, "%d.%02d", sec, frac);
break;
case TO_STR_TIME_RES_T_MSECS:
g_snprintf(buf, buflen, "%d.%03d", sec, frac);
break;
case TO_STR_TIME_RES_T_USECS:
g_snprintf(buf, buflen, "%d.%06d", sec, frac);
break;
case TO_STR_TIME_RES_T_NSECS:
g_snprintf(buf, buflen, "%d.%09d", sec, frac);
break;
}
}
void
display_epoch_time(gchar *buf, int buflen, const time_t sec, gint32 frac,
const to_str_time_res_t units)
{
double elapsed_secs;
elapsed_secs = difftime(sec,(time_t)0);
if (frac < 0) {
frac = -frac;
if (elapsed_secs >= 0) {
if (buflen < 1) {
return;
}
buf[0] = '-';
buf++;
buflen--;
}
}
switch (units) {
case TO_STR_TIME_RES_T_SECS:
g_snprintf(buf, buflen, "%0.0f", elapsed_secs);
break;
case TO_STR_TIME_RES_T_DSECS:
g_snprintf(buf, buflen, "%0.0f.%01d", elapsed_secs, frac);
break;
case TO_STR_TIME_RES_T_CSECS:
g_snprintf(buf, buflen, "%0.0f.%02d", elapsed_secs, frac);
break;
case TO_STR_TIME_RES_T_MSECS:
g_snprintf(buf, buflen, "%0.0f.%03d", elapsed_secs, frac);
break;
case TO_STR_TIME_RES_T_USECS:
g_snprintf(buf, buflen, "%0.0f.%06d", elapsed_secs, frac);
break;
case TO_STR_TIME_RES_T_NSECS:
g_snprintf(buf, buflen, "%0.0f.%09d", elapsed_secs, frac);
break;
}
}
gchar *
rel_time_to_str(const nstime_t *rel_time)
{
emem_strbuf_t *buf;
gint32 time_val;
gint32 nsec;
buf=ep_strbuf_sized_new(1+TIME_SECS_LEN+1+6+1, 1+TIME_SECS_LEN+1+6+1);
time_val = (gint) rel_time->secs;
nsec = rel_time->nsecs;
if (time_val == 0 && nsec == 0) {
ep_strbuf_append(buf, "0.000000000 seconds");
return buf->str;
}
if (nsec < 0) {
nsec = -nsec;
ep_strbuf_append_c(buf, '-');
time_val = (gint) -rel_time->secs;
}
time_secs_to_str_buf(time_val, nsec, TRUE, buf);
return buf->str;
}
gchar *
rel_time_to_secs_str(const nstime_t *rel_time)
{
gchar *buf;
buf=ep_alloc(REL_TIME_SECS_LEN);
display_signed_time(buf, REL_TIME_SECS_LEN, (gint32) rel_time->secs,
rel_time->nsecs, TO_STR_TIME_RES_T_NSECS);
return buf;
}
char *
decode_bits_in_field(const guint bit_offset, const gint no_of_bits, const guint64 value)
{
guint64 mask = 0,tmp;
char *str;
int bit;
int i;
mask = 1;
mask = mask << (no_of_bits-1);
str=ep_alloc(256);
str[0]='\0';
for(bit=0;bit<((int)(bit_offset&0x07));bit++){
if(bit&&(!(bit%4))){
g_strlcat(str, " ", 256);
}
g_strlcat(str, ".", 256);
}
for(i=0;i<no_of_bits;i++){
if(bit&&(!(bit%4))){
g_strlcat(str, " ", 256);
}
if(bit&&(!(bit%8))){
g_strlcat(str, " ", 256);
}
bit++;
tmp = value & mask;
if(tmp != 0){
g_strlcat(str, "1", 256);
} else {
g_strlcat(str, "0", 256);
}
mask = mask>>1;
}
for(;bit%8;bit++){
if(bit&&(!(bit%4))){
g_strlcat(str, " ", 256);
}
g_strlcat(str, ".", 256);
}
return str;
}
char *
other_decode_bitfield_value(char *buf, const guint32 val, const guint32 mask, const int width)
{
int i;
guint32 bit;
char *p;
i = 0;
p = buf;
bit = 1 << (width - 1);
for (;;) {
if (mask & bit) {
if (val & bit)
*p++ = '1';
else
*p++ = '0';
} else {
*p++ = '.';
}
bit >>= 1;
i++;
if (i >= width)
break;
if (i % 4 == 0)
*p++ = ' ';
}
*p = '\0';
return p;
}
char *
decode_bitfield_value(char *buf, const guint32 val, const guint32 mask, const int width)
{
char *p;
p = other_decode_bitfield_value(buf, val, mask, width);
strcpy(p, " = ");
p += 3;
return p;
}
const char *
decode_boolean_bitfield(const guint32 val, const guint32 mask, const int width,
const char *truedesc, const char *falsedesc)
{
char *buf;
char *p;
buf=ep_alloc(1025);
p = decode_bitfield_value(buf, val, mask, width);
if (val & mask)
strcpy(p, truedesc);
else
strcpy(p, falsedesc);
return buf;
}
const char *
decode_numeric_bitfield(const guint32 val, const guint32 mask, const int width,
const char *fmt)
{
char *buf;
char *p;
int shift = 0;
buf=ep_alloc(1025);
while ((mask & (1<<shift)) == 0)
shift++;
p = decode_bitfield_value(buf, val, mask, width);
g_snprintf(p, (gulong) (1025-(p-buf)), fmt, (val & mask) >> shift);
return buf;
}
void
ip_to_str_buf(const guint8 *ad, gchar *buf, const int buf_len)
{
register gchar const *p;
register gchar *b=buf;
if (buf_len < MAX_IP_STR_LEN) {
g_snprintf ( buf, buf_len, BUF_TOO_SMALL_ERR );
return;
}
p=fast_strings[*ad++];
do {
*b++=*p;
p++;
} while(*p);
*b++='.';
p=fast_strings[*ad++];
do {
*b++=*p;
p++;
} while(*p);
*b++='.';
p=fast_strings[*ad++];
do {
*b++=*p;
p++;
} while(*p);
*b++='.';
p=fast_strings[*ad];
do {
*b++=*p;
p++;
} while(*p);
*b=0;
}
gchar* guid_to_str(const e_guid_t *guid) {
gchar *buf;
buf=ep_alloc(GUID_STR_LEN);
return guid_to_str_buf(guid, buf, GUID_STR_LEN);
}
gchar* guid_to_str_buf(const e_guid_t *guid, gchar *buf, int buf_len) {
char *tempptr = buf;
if (buf_len < GUID_STR_LEN) {
g_strlcpy(buf, BUF_TOO_SMALL_ERR, buf_len);
return buf;
}
tempptr = dword_to_hex(tempptr, guid->data1);
*tempptr++ = '-';
tempptr = word_to_hex(tempptr, guid->data2);
*tempptr++ = '-';
tempptr = word_to_hex(tempptr, guid->data3);
*tempptr++ = '-';
tempptr = bytes_to_hexstr(tempptr, &guid->data4[0], 2);
*tempptr++ = '-';
tempptr = bytes_to_hexstr(tempptr, &guid->data4[2], 6);
*tempptr = '\0';
return buf;
}
