static inline char
low_nibble_of_octet_to_hex(guint8 oct)
{
static const gchar hex_digits[16] =
{ '0', '1', '2', '3', '4', '5', '6', '7',
'8', '9', 'a', 'b', 'c', 'd', 'e', 'f' };
return hex_digits[oct & 0xF];
}
static inline char *
byte_to_hex(char *out, guint32 dword)
{
*out++ = low_nibble_of_octet_to_hex(dword >> 4);
*out++ = low_nibble_of_octet_to_hex(dword);
return out;
}
char *
word_to_hex(char *out, guint16 word)
{
out = byte_to_hex(out, word >> 8);
out = byte_to_hex(out, word);
return out;
}
char *
word_to_hex_punct(char *out, guint16 word, char punct)
{
out = byte_to_hex(out, word >> 8);
*out++ = punct;
out = byte_to_hex(out, word);
return out;
}
char *
word_to_hex_npad(char *out, guint16 word)
{
if (word >= 0x1000)
*out++ = low_nibble_of_octet_to_hex((guint8)(word >> 12));
if (word >= 0x0100)
*out++ = low_nibble_of_octet_to_hex((guint8)(word >> 8));
if (word >= 0x0010)
*out++ = low_nibble_of_octet_to_hex((guint8)(word >> 4));
*out++ = low_nibble_of_octet_to_hex((guint8)(word >> 0));
return out;
}
char *
dword_to_hex(char *out, guint32 dword)
{
out = word_to_hex(out, dword >> 16);
out = word_to_hex(out, dword);
return out;
}
char *
dword_to_hex_punct(char *out, guint32 dword, char punct)
{
out = word_to_hex_punct(out, dword >> 16, punct);
*out++ = punct;
out = word_to_hex_punct(out, dword, punct);
return out;
}
char *
qword_to_hex(char *out, guint64 qword)
{
out = dword_to_hex(out, (guint32)(qword >> 32));
out = dword_to_hex(out, (guint32)(qword & 0xffffffff));
return out;
}
char *
qword_to_hex_punct(char *out, guint64 qword, char punct)
{
out = dword_to_hex_punct(out, (guint32)(qword >> 32), punct);
*out++ = punct;
out = dword_to_hex_punct(out, (guint32)(qword & 0xffffffff), punct);
return out;
}
char *
bytes_to_hexstr(char *out, const guint8 *ad, guint32 len)
{
guint32 i;
if (!ad)
REPORT_DISSECTOR_BUG("Null pointer passed to bytes_to_hexstr()");
for (i = 0; i < len; i++)
out = byte_to_hex(out, ad[i]);
return out;
}
char *
bytes_to_hexstr_punct(char *out, const guint8 *ad, guint32 len, char punct)
{
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
const gchar *
bytestring_to_str(wmem_allocator_t *scope, const guint8 *ad, const guint32 len, const char punct)
{
gchar *buf;
guint32 buflen = len;
gchar *buf_ptr;
int truncated = 0;
if (!punct)
return bytes_to_str(scope, ad, len);
if (!ad)
REPORT_DISSECTOR_BUG("Null pointer passed to bytestring_to_str()");
if (len == 0)
return wmem_strdup(scope, "");
buf=(gchar *)wmem_alloc(scope, MAX_BYTE_STR_LEN+3+1);
if (buflen > MAX_BYTE_STR_LEN/3) {
truncated = 1;
buflen = MAX_BYTE_STR_LEN/3;
}
buf_ptr = bytes_to_hexstr_punct(buf, ad, buflen, punct);
if (truncated) {
*buf_ptr++ = punct;
buf_ptr = g_stpcpy(buf_ptr, "...");
}
*buf_ptr = '\0';
return buf;
}
char *
bytes_to_str(wmem_allocator_t *scope, const guint8 *bd, int bd_len)
{
gchar *cur;
gchar *cur_ptr;
int truncated = 0;
if (!bd)
REPORT_DISSECTOR_BUG("Null pointer passed to bytes_to_str()");
cur=(gchar *)wmem_alloc(scope, MAX_BYTE_STR_LEN+3+1);
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
static int
guint32_to_str_buf_len(const guint32 u)
{
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
static int
guint64_to_str_buf_len(const guint64 u)
{
if (u >= G_GUINT64_CONSTANT(10000000000000000000)) return 20;
if (u >= G_GUINT64_CONSTANT(1000000000000000000)) return 19;
if (u >= G_GUINT64_CONSTANT(100000000000000000)) return 18;
if (u >= G_GUINT64_CONSTANT(10000000000000000)) return 17;
if (u >= G_GUINT64_CONSTANT(1000000000000000)) return 16;
if (u >= G_GUINT64_CONSTANT(100000000000000)) return 15;
if (u >= G_GUINT64_CONSTANT(10000000000000)) return 14;
if (u >= G_GUINT64_CONSTANT(1000000000000)) return 13;
if (u >= G_GUINT64_CONSTANT(100000000000)) return 12;
if (u >= G_GUINT64_CONSTANT(10000000000)) return 11;
if (u >= G_GUINT64_CONSTANT(1000000000)) return 10;
if (u >= G_GUINT64_CONSTANT(100000000)) return 9;
if (u >= G_GUINT64_CONSTANT(10000000)) return 8;
if (u >= G_GUINT64_CONSTANT(1000000)) return 7;
if (u >= G_GUINT64_CONSTANT(100000)) return 6;
if (u >= G_GUINT64_CONSTANT(10000)) return 5;
if (u >= G_GUINT64_CONSTANT(1000)) return 4;
if (u >= G_GUINT64_CONSTANT(100)) return 3;
if (u >= G_GUINT64_CONSTANT(10)) return 2;
return 1;
}
void
guint32_to_str_buf(guint32 u, gchar *buf, int buf_len)
{
int str_len = guint32_to_str_buf_len(u)+1;
gchar *bp = &buf[str_len];
if (buf_len < str_len) {
g_strlcpy(buf, BUF_TOO_SMALL_ERR, buf_len);
return;
}
*--bp = '\0';
uint_to_str_back(bp, u);
}
void
guint64_to_str_buf(guint64 u, gchar *buf, int buf_len)
{
int str_len = guint64_to_str_buf_len(u)+1;
gchar *bp = &buf[str_len];
if (buf_len < str_len) {
g_strlcpy(buf, BUF_TOO_SMALL_ERR, buf_len);
return;
}
*--bp = '\0';
uint64_to_str_back(bp, u);
}
static void
time_secs_to_str_buf(gint32 time_val, const guint32 frac, const gboolean is_nsecs,
wmem_strbuf_t *buf)
{
int hours, mins, secs;
const gchar *msign = "";
gboolean do_comma = FALSE;
if(time_val == G_MININT32) {
wmem_strbuf_append_printf(buf, "Unable to cope with time value %d", time_val);
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
wmem_strbuf_append_printf(buf, "%s%u day%s", msign, time_val, PLURALIZE(time_val));
do_comma = TRUE;
msign="";
}
if (hours != 0) {
wmem_strbuf_append_printf(buf, "%s%s%u hour%s", COMMA(do_comma), msign, hours, PLURALIZE(hours));
do_comma = TRUE;
msign="";
}
if (mins != 0) {
wmem_strbuf_append_printf(buf, "%s%s%u minute%s", COMMA(do_comma), msign, mins, PLURALIZE(mins));
do_comma = TRUE;
msign="";
}
if (secs != 0 || frac != 0) {
if (frac != 0) {
if (is_nsecs)
wmem_strbuf_append_printf(buf, "%s%s%u.%09u seconds", COMMA(do_comma), msign, secs, frac);
else
wmem_strbuf_append_printf(buf, "%s%s%u.%03u seconds", COMMA(do_comma), msign, secs, frac);
} else
wmem_strbuf_append_printf(buf, "%s%s%u second%s", COMMA(do_comma), msign, secs, PLURALIZE(secs));
}
}
gchar *
time_secs_to_str(wmem_allocator_t *scope, const gint32 time_val)
{
wmem_strbuf_t *buf;
if (time_val == 0) {
return wmem_strdup(scope, "0 seconds");
}
buf = wmem_strbuf_sized_new(scope, TIME_SECS_LEN+1, TIME_SECS_LEN+1);
time_secs_to_str_buf(time_val, 0, FALSE, buf);
return wmem_strbuf_finalize(buf);
}
static void
time_secs_to_str_buf_unsigned(guint32 time_val, const guint32 frac, const gboolean is_nsecs,
wmem_strbuf_t *buf)
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
wmem_strbuf_append_printf(buf, "%u day%s", time_val, PLURALIZE(time_val));
do_comma = TRUE;
}
if (hours != 0) {
wmem_strbuf_append_printf(buf, "%s%u hour%s", COMMA(do_comma), hours, PLURALIZE(hours));
do_comma = TRUE;
}
if (mins != 0) {
wmem_strbuf_append_printf(buf, "%s%u minute%s", COMMA(do_comma), mins, PLURALIZE(mins));
do_comma = TRUE;
}
if (secs != 0 || frac != 0) {
if (frac != 0) {
if (is_nsecs)
wmem_strbuf_append_printf(buf, "%s%u.%09u seconds", COMMA(do_comma), secs, frac);
else
wmem_strbuf_append_printf(buf, "%s%u.%03u seconds", COMMA(do_comma), secs, frac);
} else
wmem_strbuf_append_printf(buf, "%s%u second%s", COMMA(do_comma), secs, PLURALIZE(secs));
}
}
gchar *
time_secs_to_str_unsigned(wmem_allocator_t *scope, const guint32 time_val)
{
wmem_strbuf_t *buf;
if (time_val == 0) {
return wmem_strdup(scope, "0 seconds");
}
buf = wmem_strbuf_sized_new(scope, TIME_SECS_LEN+1, TIME_SECS_LEN+1);
time_secs_to_str_buf_unsigned(time_val, 0, FALSE, buf);
return wmem_strbuf_finalize(buf);
}
gchar *
time_msecs_to_str(wmem_allocator_t *scope, gint32 time_val)
{
wmem_strbuf_t *buf;
int msecs;
if (time_val == 0) {
return wmem_strdup(scope, "0 seconds");
}
buf = wmem_strbuf_sized_new(scope, TIME_SECS_LEN+1+3+1, TIME_SECS_LEN+1+3+1);
if (time_val<0) {
time_val= -time_val;
msecs = time_val % 1000;
time_val /= 1000;
time_val= -time_val;
} else {
msecs = time_val % 1000;
time_val /= 1000;
}
time_secs_to_str_buf(time_val, msecs, FALSE, buf);
return wmem_strbuf_finalize(buf);
}
static const gchar *
get_zonename(struct tm *tmp)
{
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
abs_time_to_str(wmem_allocator_t *scope, const nstime_t *abs_time, const absolute_time_display_e fmt,
gboolean show_zone)
{
struct tm *tmp = NULL;
const char *zonename = "???";
gchar *buf = NULL;
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
buf = wmem_strdup_printf(scope,
"%04d/%03d:%02d:%02d:%02d.%09ld %s",
tmp->tm_year + 1900,
tmp->tm_yday + 1,
tmp->tm_hour,
tmp->tm_min,
tmp->tm_sec,
(long)abs_time->nsecs,
zonename);
} else {
buf = wmem_strdup_printf(scope,
"%04d/%03d:%02d:%02d:%02d.%09ld",
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
buf = wmem_strdup_printf(scope,
"%s %2d, %d %02d:%02d:%02d.%09ld %s",
mon_names[tmp->tm_mon],
tmp->tm_mday,
tmp->tm_year + 1900,
tmp->tm_hour,
tmp->tm_min,
tmp->tm_sec,
(long)abs_time->nsecs,
zonename);
} else {
buf = wmem_strdup_printf(scope,
"%s %2d, %d %02d:%02d:%02d.%09ld",
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
buf = wmem_strdup(scope, "Not representable");
return buf;
}
gchar *
abs_time_secs_to_str(wmem_allocator_t *scope, const time_t abs_time, const absolute_time_display_e fmt,
gboolean show_zone)
{
struct tm *tmp = NULL;
const char *zonename = "???";
gchar *buf = NULL;
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
buf = wmem_strdup_printf(scope,
"%04d/%03d:%02d:%02d:%02d %s",
tmp->tm_year + 1900,
tmp->tm_yday + 1,
tmp->tm_hour,
tmp->tm_min,
tmp->tm_sec,
zonename);
} else {
buf = wmem_strdup_printf(scope,
"%04d/%03d:%02d:%02d:%02d",
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
buf = wmem_strdup_printf(scope,
"%s %2d, %d %02d:%02d:%02d %s",
mon_names[tmp->tm_mon],
tmp->tm_mday,
tmp->tm_year + 1900,
tmp->tm_hour,
tmp->tm_min,
tmp->tm_sec,
zonename);
} else {
buf = wmem_strdup_printf(scope,
"%s %2d, %d %02d:%02d:%02d",
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
buf = wmem_strdup(scope, "Not representable");
return buf;
}
void
display_signed_time(gchar *buf, int buflen, const gint32 sec, gint32 frac,
const to_str_time_res_t units)
{
gint8 num_buf[16];
gint8 *num_end = &num_buf[16];
gint8 *num_ptr;
int num_len;
if (buflen < 1)
return;
if (frac < 0) {
frac = -frac;
if (sec >= 0) {
buf[0] = '-';
buf++;
buflen--;
}
}
num_ptr = int_to_str_back(num_end, sec);
num_len = MIN((int) (num_end - num_ptr), buflen);
memcpy(buf, num_ptr, num_len);
buf += num_len;
buflen -= num_len;
switch (units) {
case TO_STR_TIME_RES_T_SECS:
default:
num_ptr = NULL;
break;
case TO_STR_TIME_RES_T_DSECS:
num_ptr = uint_to_str_back_len(num_end, frac, 1);
break;
case TO_STR_TIME_RES_T_CSECS:
num_ptr = uint_to_str_back_len(num_end, frac, 2);
break;
case TO_STR_TIME_RES_T_MSECS:
num_ptr = uint_to_str_back_len(num_end, frac, 3);
break;
case TO_STR_TIME_RES_T_USECS:
num_ptr = uint_to_str_back_len(num_end, frac, 6);
break;
case TO_STR_TIME_RES_T_NSECS:
num_ptr = uint_to_str_back_len(num_end, frac, 9);
break;
}
if (num_ptr != NULL)
{
*(--num_ptr) = '.';
num_len = MIN((int) (num_end - num_ptr), buflen);
memcpy(buf, num_ptr, num_len);
buf += num_len;
buflen -= num_len;
}
if (buflen == 0)
buf--;
*buf = '\0';
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
rel_time_to_str(wmem_allocator_t *scope, const nstime_t *rel_time)
{
wmem_strbuf_t *buf;
gint32 time_val;
gint32 nsec;
time_val = (gint) rel_time->secs;
nsec = rel_time->nsecs;
if (time_val == 0 && nsec == 0) {
return wmem_strdup(scope, "0.000000000 seconds");
}
buf = wmem_strbuf_sized_new(scope, 1+TIME_SECS_LEN+1+6+1, 1+TIME_SECS_LEN+1+6+1);
if (nsec < 0) {
nsec = -nsec;
wmem_strbuf_append_c(buf, '-');
time_val = (gint) -rel_time->secs;
}
time_secs_to_str_buf(time_val, nsec, TRUE, buf);
return wmem_strbuf_finalize(buf);
}
gchar *
rel_time_to_secs_str(wmem_allocator_t *scope, const nstime_t *rel_time)
{
gchar *buf;
buf=(gchar *)wmem_alloc(scope, REL_TIME_SECS_LEN);
display_signed_time(buf, REL_TIME_SECS_LEN, (gint32) rel_time->secs,
rel_time->nsecs, TO_STR_TIME_RES_T_NSECS);
return buf;
}
char *
decode_bits_in_field(const guint bit_offset, const gint no_of_bits, const guint64 value)
{
guint64 mask = 0,tmp;
char *str;
int bit, str_p = 0;
int i;
mask = 1;
mask = mask << (no_of_bits-1);
str=(char *)wmem_alloc0(wmem_packet_scope(), 256+64);
for(bit=0;bit<((int)(bit_offset&0x07));bit++){
if(bit&&(!(bit%4))){
str[str_p] = ' ';
str_p++;
}
str[str_p] = '.';
str_p++;
}
for(i=0;i<no_of_bits;i++){
if(bit&&(!(bit%4))){
str[str_p] = ' ';
str_p++;
}
if(bit&&(!(bit%8))){
str[str_p] = ' ';
str_p++;
}
bit++;
tmp = value & mask;
if(tmp != 0){
str[str_p] = '1';
str_p++;
} else {
str[str_p] = '0';
str_p++;
}
mask = mask>>1;
}
for(;bit%8;bit++){
if(bit&&(!(bit%4))){
str[str_p] = ' ';
str_p++;
}
str[str_p] = '.';
str_p++;
}
return str;
}
void
ip_to_str_buf(const guint8 *ad, gchar *buf, const int buf_len)
{
register gchar const *p;
register gchar *b=buf;
if (buf_len < MAX_IP_STR_LEN) {
g_strlcpy(buf, BUF_TOO_SMALL_ERR, buf_len);
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
gchar *
guid_to_str(wmem_allocator_t *scope, const e_guid_t *guid)
{
gchar *buf;
buf=(gchar *)wmem_alloc(scope, GUID_STR_LEN);
return guid_to_str_buf(guid, buf, GUID_STR_LEN);
}
gchar *
guid_to_str_buf(const e_guid_t *guid, gchar *buf, int buf_len)
{
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
gchar *
eui64_to_str(wmem_allocator_t *scope, const guint64 ad) {
gchar *buf, *tmp;
guint8 *p_eui64;
p_eui64=(guint8 *)wmem_alloc(NULL, 8);
buf=(gchar *)wmem_alloc(scope, EUI64_STR_LEN);
*(guint64 *)(void *)(p_eui64) = pntoh64(&(ad));
tmp = bytes_to_hexstr_punct(buf, p_eui64, 8, ':');
*tmp = '\0';
wmem_free(NULL, p_eui64);
return buf;
}
const gchar *
port_type_to_str (port_type type)
{
switch (type) {
case PT_NONE: return "NONE";
case PT_SCTP: return "SCTP";
case PT_TCP: return "TCP";
case PT_UDP: return "UDP";
case PT_DCCP: return "DCCP";
case PT_IPX: return "IPX";
case PT_NCP: return "NCP";
case PT_EXCHG: return "FC EXCHG";
case PT_DDP: return "DDP";
case PT_SBCCS: return "FICON SBCCS";
case PT_IDP: return "IDP";
case PT_TIPC: return "TIPC";
case PT_USB: return "USB";
case PT_I2C: return "I2C";
case PT_IBQP: return "IBQP";
case PT_BLUETOOTH: return "BLUETOOTH";
case PT_TDMOP: return "TDMOP";
default: return "[Unknown]";
}
}
char *
oct_to_str_back(char *ptr, guint32 value)
{
while (value) {
*(--ptr) = '0' + (value & 0x7);
value >>= 3;
}
*(--ptr) = '0';
return ptr;
}
char *
oct64_to_str_back(char *ptr, guint64 value)
{
while (value) {
*(--ptr) = '0' + (value & 0x7);
value >>= 3;
}
*(--ptr) = '0';
return ptr;
}
char *
hex_to_str_back(char *ptr, int len, guint32 value)
{
do {
*(--ptr) = low_nibble_of_octet_to_hex(value);
value >>= 4;
len--;
} while (value);
while (len > 0) {
*(--ptr) = '0';
len--;
}
*(--ptr) = 'x';
*(--ptr) = '0';
return ptr;
}
char *
hex64_to_str_back(char *ptr, int len, guint64 value)
{
do {
*(--ptr) = low_nibble_of_octet_to_hex(value & 0xF);
value >>= 4;
len--;
} while (value);
while (len > 0) {
*(--ptr) = '0';
len--;
}
*(--ptr) = 'x';
*(--ptr) = '0';
return ptr;
}
char *
uint_to_str_back(char *ptr, guint32 value)
{
char const *p;
if (value == 0)
*(--ptr) = '0';
while (value >= 10) {
p = fast_strings[100 + (value % 100)];
value /= 100;
*(--ptr) = p[2];
*(--ptr) = p[1];
}
if (value)
*(--ptr) = (value) | '0';
return ptr;
}
char *
uint64_to_str_back(char *ptr, guint64 value)
{
char const *p;
if (value == 0)
*(--ptr) = '0';
while (value >= 10) {
p = fast_strings[100 + (value % 100)];
value /= 100;
*(--ptr) = p[2];
*(--ptr) = p[1];
}
if (value)
*(--ptr) = (value & 0xF) | '0';
return ptr;
}
char *
uint_to_str_back_len(char *ptr, guint32 value, int len)
{
char *new_ptr;
new_ptr = uint_to_str_back(ptr, value);
len -= (int)(ptr - new_ptr);
while (len > 0)
{
*(--new_ptr) = '0';
len--;
}
return new_ptr;
}
char *
uint64_to_str_back_len(char *ptr, guint64 value, int len)
{
char *new_ptr;
new_ptr = uint64_to_str_back(ptr, value);
len -= (int)(ptr - new_ptr);
while (len > 0)
{
*(--new_ptr) = '0';
len--;
}
return new_ptr;
}
char *
int_to_str_back(char *ptr, gint32 value)
{
if (value < 0) {
ptr = uint_to_str_back(ptr, -value);
*(--ptr) = '-';
} else
ptr = uint_to_str_back(ptr, value);
return ptr;
}
char *
int64_to_str_back(char *ptr, gint64 value)
{
if (value < 0) {
ptr = uint64_to_str_back(ptr, -value);
*(--ptr) = '-';
} else
ptr = uint64_to_str_back(ptr, value);
return ptr;
}
