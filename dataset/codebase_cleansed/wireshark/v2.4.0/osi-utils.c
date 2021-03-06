gchar *
print_nsap_net( tvbuff_t *tvb, const gint offset, int length )
{
gchar *cur;
cur = (gchar *)wmem_alloc(wmem_packet_scope(), MAX_NSAP_LEN * 3 + 50);
print_nsap_net_buf( tvb_get_ptr(tvb, offset, length), length, cur, MAX_NSAP_LEN * 3 + 50);
return( cur );
}
static void
print_nsap_net_buf( const guint8 *ad, int length, gchar *buf, int buf_len)
{
gchar *cur;
if ( (length <= 0 ) || ( length > MAX_NSAP_LEN ) ) {
g_strlcpy(buf, "<Invalid length of NSAP>", buf_len);
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
print_system_id(wmem_allocator_t* scope, const guint8 *ad, int length )
{
gchar *cur;
cur = (gchar *)wmem_alloc(scope, MAX_SYSTEMID_LEN * 3 + 5);
print_system_id_buf(ad, length, cur, MAX_SYSTEMID_LEN * 3 + 5);
return( cur );
}
gchar *
tvb_print_system_id( tvbuff_t *tvb, const gint offset, int length )
{
return( print_system_id(wmem_packet_scope(), tvb_get_ptr(tvb, offset, length), length) );
}
void
print_system_id_buf( const guint8 *ad, int length, gchar *buf, int buf_len)
{
gchar *cur;
int tmp;
if ( ( length <= 0 ) || ( length > MAX_SYSTEMID_LEN ) ) {
g_strlcpy(buf, "<Invalid length of SYSTEM ID>", buf_len);
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
print_area(tvbuff_t *tvb, const gint offset, int length)
{
gchar *cur;
cur = (gchar *)wmem_alloc(wmem_packet_scope(), MAX_AREA_LEN * 3 + 20);
print_area_buf(tvb_get_ptr(tvb, offset, length), length, cur, MAX_AREA_LEN * 3 + 20);
return cur;
}
gchar *
print_address_prefix(tvbuff_t *tvb, const gint offset, int length)
{
gchar *cur;
cur = (gchar *)wmem_alloc(wmem_packet_scope(), MAX_AREA_LEN * 3 + 20);
print_address_prefix_buf(tvb_get_ptr(tvb, offset, (length+1)/2), length, cur, MAX_AREA_LEN * 3 + 20);
return cur;
}
static void
print_area_buf(const guint8 *ad, int length, gchar *buf, int buf_len)
{
print_address_prefix_buf(ad, length*2, buf, buf_len);
}
static void
print_address_prefix_buf(const guint8 *ad, int length, gchar *buf, int buf_len)
{
gchar *cur;
int tmp = 0;
if (length <= 0 || length > MAX_AREA_LEN*2) {
g_strlcpy(buf, "<Invalid length of AREA>", buf_len);
return;
}
cur = buf;
if ( ( ( NSAP_IDI_ISO_DCC_BIN == *ad )
|| ( NSAP_IDI_ISO_6523_ICD_BIN == *ad )
)
&&
( ( RFC1237_FULLAREA_LEN*2 == length )
|| ( (RFC1237_FULLAREA_LEN + 1)*2 == length )
)
) {
cur += g_snprintf(cur, (gulong) (buf_len-(cur-buf)), "[%02x|%02x:%02x][%02x|%02x:%02x:%02x|%02x:%02x]",
ad[0], ad[1], ad[2], ad[3], ad[4],
ad[5], ad[6], ad[7], ad[8] );
cur += g_snprintf(cur, (gulong) (buf_len-(cur-buf)), "[%02x:%02x|%02x:%02x]",
ad[9], ad[10], ad[11], ad[12] );
if ( (RFC1237_FULLAREA_LEN + 1)*2 == length )
g_snprintf(cur, (gulong) (buf_len-(cur-buf)), "-[%02x]", ad[20] );
}
else {
if ( length == RFC1237_AREA_LEN*2 ) {
g_snprintf(buf, buf_len, "%02x.%02x%02x", ad[0], ad[1], ad[2] );
return;
}
if ( length == 4*2 ) {
g_snprintf(buf, buf_len, "%02x%02x%02x%02x", ad[0], ad[1], ad[2], ad[3] );
return;
}
while ( tmp < length / 8 ) {
cur += g_snprintf(cur, (gulong) (buf_len-(cur-buf)), "%02x", ad[tmp++] );
cur += g_snprintf(cur, (gulong) (buf_len-(cur-buf)), "%02x", ad[tmp++] );
cur += g_snprintf(cur, (gulong) (buf_len-(cur-buf)), "%02x", ad[tmp++] );
cur += g_snprintf(cur, (gulong) (buf_len-(cur-buf)), "%02x.", ad[tmp++] );
}
if ( 2 == tmp ) {
cur--;
g_snprintf(cur, (gulong) (buf_len-(cur-buf)), "-%02x", ad[tmp] );
}
else {
for ( ; tmp < length / 2; ) {
cur += g_snprintf(cur, (gulong) (buf_len-(cur-buf)), "%02x", ad[tmp++] );
}
if (length & 1) {
g_snprintf(cur, (gulong) (buf_len-(cur-buf)), "%x", (ad[tmp] & 0xF0)>>4 );
}
}
}
}
static int osi_address_to_str(const address* addr, gchar *buf, int buf_len)
{
print_nsap_net_buf((const guint8 *)addr->data, addr->len, buf, buf_len);
return (int)strlen(buf)+1;
}
static int osi_address_str_len(const address* addr _U_)
{
return MAX_NSAP_LEN * 3 + 50;
}
int get_osi_address_type(void)
{
return osi_address_type;
}
void register_osi_address_type(void)
{
if (osi_address_type != -1)
return;
osi_address_type = address_type_dissector_register("AT_OSI", "OSI Address", osi_address_to_str, osi_address_str_len, NULL, NULL, NULL, NULL, NULL);
}
