gchar *
print_nsap_net( const guint8 *ad, int length )
{
gchar *cur;
cur = ep_alloc(MAX_NSAP_LEN * 3 + 50);
print_nsap_net_buf( ad, length, cur, MAX_NSAP_LEN * 3 + 50);
return( cur );
}
void
print_nsap_net_buf( const guint8 *ad, int length, gchar *buf, int buf_len)
{
gchar *cur;
if ( (length <= 0 ) || ( length > MAX_NSAP_LEN ) ) {
g_snprintf(buf, buf_len, "<Invalid length of NSAP>");
return;
}
cur = buf;
if ( ( length == RFC1237_NSAP_LEN ) || ( length == RFC1237_NSAP_LEN + 1 ) ) {
print_area_buf(ad, RFC1237_FULLAREA_LEN, cur, buf_len);
cur += strlen( cur );
print_system_id_buf( ad + RFC1237_FULLAREA_LEN, RFC1237_SYSTEMID_LEN, cur, (int) (buf_len-(cur-buf)));
cur += strlen( cur );
cur += g_snprintf(cur, (gulong) (buf_len-(cur-buf)), "[%02x]",
ad[ RFC1237_FULLAREA_LEN + RFC1237_SYSTEMID_LEN ] );
if ( length == RFC1237_NSAP_LEN + 1 ) {
g_snprintf(cur, (int) (buf_len-(cur-buf)), "-%02x", ad[ length -1 ] );
}
}
else {
print_area_buf( ad, length, buf, buf_len);
}
}
gchar *
print_system_id( const guint8 *ad, int length )
{
gchar *cur;
cur = ep_alloc(MAX_SYSTEMID_LEN * 3 + 5);
print_system_id_buf(ad, length, cur, MAX_SYSTEMID_LEN * 3 + 5);
return( cur );
}
void
print_system_id_buf( const guint8 *ad, int length, gchar *buf, int buf_len)
{
gchar *cur;
int tmp;
if ( ( length <= 0 ) || ( length > MAX_SYSTEMID_LEN ) ) {
g_snprintf(buf, buf_len, "<Invalid length of SYSTEM ID>");
return;
}
cur = buf;
if ( ( 6 == length ) ||
( 7 == length ) ||
( 8 == length )) {
cur += g_snprintf(cur, buf_len, "%02x%02x.%02x%02x.%02x%02x", ad[0], ad[1],
ad[2], ad[3], ad[4], ad[5] );
if ( ( 7 == length ) ||
( 8 == length )) {
cur += g_snprintf(cur, (gulong) (buf_len-(cur-buf)), ".%02x", ad[6] );
}
if ( 8 == length ) {
g_snprintf(cur, (gulong) (buf_len-(cur-buf)), "-%02x", ad[7] );
}
}
else {
tmp = 0;
while ( tmp < length / 4 ) {
cur += g_snprintf(cur, (gulong) (buf_len-(cur-buf)), "%02x", ad[tmp++] );
cur += g_snprintf(cur, (gulong) (buf_len-(cur-buf)), "%02x", ad[tmp++] );
cur += g_snprintf(cur, (gulong) (buf_len-(cur-buf)), "%02x", ad[tmp++] );
cur += g_snprintf(cur, (gulong) (buf_len-(cur-buf)), "%02x.", ad[tmp++] );
}
if ( 1 == tmp ) {
cur--;
g_snprintf(cur, (gulong) (buf_len-(cur-buf)), ".%02x", ad[tmp] );
}
else {
for ( ; tmp < length; ) {
cur += g_snprintf(cur, (gulong) (buf_len-(cur-buf)), "%02x", ad[tmp++] );
}
}
}
}
gchar *
print_area(const guint8 *ad, int length)
{
gchar *cur;
cur = ep_alloc(MAX_AREA_LEN * 3 + 20);
print_area_buf(ad, length, cur, MAX_AREA_LEN * 3 + 20);
return cur;
}
void
print_area_buf(const guint8 *ad, int length, gchar *buf, int buf_len)
{
gchar *cur;
int tmp = 0;
if (length <= 0 || length > MAX_AREA_LEN) {
g_snprintf(buf, buf_len, "<Invalid length of AREA>");
return;
}
cur = buf;
if ( ( ( NSAP_IDI_ISODCC == *ad )
|| ( NSAP_IDI_GOSIP2 == *ad )
)
&&
( ( RFC1237_FULLAREA_LEN == length )
|| ( RFC1237_FULLAREA_LEN + 1 == length )
)
) {
cur += g_snprintf(cur, (gulong) (buf_len-(cur-buf)), "[%02x|%02x:%02x][%02x|%02x:%02x:%02x|%02x:%02x]",
ad[0], ad[1], ad[2], ad[3], ad[4],
ad[5], ad[6], ad[7], ad[8] );
cur += g_snprintf(cur, (gulong) (buf_len-(cur-buf)), "[%02x:%02x|%02x:%02x]",
ad[9], ad[10], ad[11], ad[12] );
if ( RFC1237_FULLAREA_LEN + 1 == length )
g_snprintf(cur, (gulong) (buf_len-(cur-buf)), "-[%02x]", ad[20] );
}
else {
if ( length == RFC1237_AREA_LEN ) {
g_snprintf(buf, buf_len, "%02x.%02x%02x", ad[0], ad[1], ad[2] );
return;
}
if(length == 4)
{
g_snprintf(buf, buf_len, "%02x%02x%02x%02x", ad[0], ad[1], ad[2], ad[3] );
}
if ( 4 < length )
{
while ( tmp < length / 4 ) {
cur += g_snprintf(cur, (gulong) (buf_len-(cur-buf)), "%02x", ad[tmp++] );
cur += g_snprintf(cur, (gulong) (buf_len-(cur-buf)), "%02x", ad[tmp++] );
cur += g_snprintf(cur, (gulong) (buf_len-(cur-buf)), "%02x", ad[tmp++] );
cur += g_snprintf(cur, (gulong) (buf_len-(cur-buf)), "%02x.", ad[tmp++] );
}
if ( 1 == tmp ) {
cur--;
g_snprintf(cur, (gulong) (buf_len-(cur-buf)), "-%02x", ad[tmp] );
}
else {
for ( ; tmp < length; ) {
cur += g_snprintf(cur, (gulong) (buf_len-(cur-buf)), "%02x", ad[tmp++] );
}
}
}
}
}
