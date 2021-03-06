const gchar *
ether_to_str(const guint8 *ad)
{
return bytestring_to_ep_str(ad, 6, ':');
}
const gchar *
tvb_ether_to_str(tvbuff_t *tvb, const gint offset)
{
return bytestring_to_ep_str(tvb_get_ptr(tvb, offset, 6), 6, ':');
}
const gchar *
ip_to_str(const guint8 *ad) {
gchar *buf;
buf=(gchar *)ep_alloc(MAX_IP_STR_LEN);
ip_to_str_buf(ad, buf, MAX_IP_STR_LEN);
return buf;
}
const gchar *
tvb_ip_to_str(tvbuff_t *tvb, const gint offset)
{
gchar *buf;
buf=(gchar *)ep_alloc(MAX_IP_STR_LEN);
ip_to_str_buf(tvb_get_ptr(tvb, offset, IPV4_LENGTH), buf, MAX_IP_STR_LEN);
return buf;
}
const gchar *
ip6_to_str(const struct e_in6_addr *ad) {
gchar *str;
str=(gchar *)ep_alloc(MAX_IP6_STR_LEN);
ip6_to_str_buf(ad, str);
return str;
}
const gchar *
ip6_guint8_to_str(const guint8 *ad) {
gchar *str;
str=(gchar *)ep_alloc(MAX_IP6_STR_LEN);
ip6_to_str_buf_len((const guchar*)ad, str, MAX_IP6_STR_LEN);
return str;
}
const gchar *
tvb_ip6_to_str(tvbuff_t *tvb, const gint offset)
{
gchar *buf;
buf=(gchar *)ep_alloc(MAX_IP6_STR_LEN);
ip6_to_str_buf((const struct e_in6_addr *)tvb_get_ptr(tvb, offset, IPV6_LENGTH), buf);
return buf;
}
static void
ip6_to_str_buf_len(const guchar* src, char *buf, size_t buf_len)
{
struct { int base, len; } best, cur;
guint words[8];
int i;
if (buf_len < MAX_IP6_STR_LEN) {
g_strlcpy(buf, BUF_TOO_SMALL_ERR, buf_len);
return;
}
for (i = 0; i < 16; i += 2) {
words[i / 2] = (src[i+1] << 0);
words[i / 2] |= (src[i] << 8);
}
best.base = -1; best.len = 0;
cur.base = -1; cur.len = 0;
for (i = 0; i < 8; i++) {
if (words[i] == 0) {
if (cur.base == -1) {
cur.base = i;
cur.len = 1;
} else
cur.len++;
} else {
if (cur.base != -1) {
if (best.base == -1 || cur.len > best.len)
best = cur;
cur.base = -1;
}
}
}
if (cur.base != -1) {
if (best.base == -1 || cur.len > best.len)
best = cur;
}
if (best.base != -1 && best.len < 2)
best.base = -1;
if (best.base == 0 && (best.len == 6 || (best.len == 5 && words[5] == 0xffff)))
{
buf = g_stpcpy(buf, "::");
if (best.len == 5)
buf = g_stpcpy(buf, "ffff:");
ip_to_str_buf(src + 12, buf, MAX_IP_STR_LEN);
return;
}
for (i = 0; i < 8; i++) {
if (i == best.base) {
*buf++ = ':';
i += best.len;
if (i == 8) {
*buf++ = ':';
break;
}
}
if (i != 0)
*buf++ = ':';
buf = word_to_hex_npad(buf, words[i]);
}
*buf = '\0';
}
void
ip6_to_str_buf(const struct e_in6_addr *ad, gchar *buf)
{
ip6_to_str_buf_len((const guchar*)ad, buf, MAX_IP6_STR_LEN);
}
gchar*
ipx_addr_to_str(const guint32 net, const guint8 *ad)
{
gchar *buf;
char *name;
name = get_ether_name_if_known(ad);
if (name) {
buf = ep_strdup_printf("%s.%s", get_ipxnet_name(net), name);
}
else {
buf = ep_strdup_printf("%s.%s", get_ipxnet_name(net),
bytestring_to_ep_str(ad, 6, '\0'));
}
return buf;
}
gchar*
ipxnet_to_string(const guint8 *ad)
{
guint32 addr = pntoh32(ad);
return ipxnet_to_str_punct(addr, ' ');
}
gchar*
tvb_ipxnet_to_string(tvbuff_t *tvb, const gint offset)
{
return ipxnet_to_str_punct(tvb_get_ntohl(tvb, offset), ' ');
}
gchar *
ipxnet_to_str_punct(const guint32 ad, const char punct)
{
gchar *buf = (gchar *)ep_alloc(12);
*dword_to_hex_punct(buf, ad, punct) = '\0';
return buf;
}
static void
vines_addr_to_str_buf(const guint8 *addrp, gchar *buf, int buf_len)
{
if (buf_len < 14) {
g_strlcpy(buf, BUF_TOO_SMALL_ERR, buf_len);
return;
}
buf = dword_to_hex(buf, pntoh32(&addrp[0]));
*buf++ = '.';
buf = word_to_hex(buf, pntoh16(&addrp[4]));
*buf = '\0';
}
gchar *
tvb_vines_addr_to_str(tvbuff_t *tvb, const gint offset)
{
gchar *buf;
buf=(gchar *)ep_alloc(214);
vines_addr_to_str_buf(tvb_get_ptr(tvb, offset, VINES_ADDR_LEN), buf, 214);
return buf;
}
gchar *
eui64_to_str(const guint64 ad) {
gchar *buf;
guint8 *p_eui64;
p_eui64 = (guint8 *)ep_alloc(8);
buf=(gchar *)ep_alloc(EUI64_STR_LEN);
*(guint64 *)(void *)(p_eui64) = pntoh64(&(ad));
g_snprintf(buf, EUI64_STR_LEN, "%.2x:%.2x:%.2x:%.2x:%.2x:%.2x:%.2x:%.2x",
p_eui64[0], p_eui64[1], p_eui64[2], p_eui64[3],
p_eui64[4], p_eui64[5], p_eui64[6], p_eui64[7] );
return buf;
}
gchar *
tvb_eui64_to_str(tvbuff_t *tvb, const gint offset, const guint encoding)
{
if(encoding)
{
return eui64_to_str(tvb_get_letoh64(tvb, offset));
}else {
return eui64_to_str(tvb_get_ntoh64(tvb, offset));
}
}
static void
usb_addr_to_str_buf(const guint8 *addrp, gchar *buf, int buf_len)
{
if(pletoh32(&addrp[0])==0xffffffff){
g_snprintf(buf, buf_len, "host");
} else {
g_snprintf(buf, buf_len, "%d.%d.%d", pletoh16(&addrp[8]),
pletoh32(&addrp[0]), pletoh32(&addrp[4]));
}
}
static void
tipc_addr_to_str_buf( const guint8 *data, gchar *buf, int buf_len){
guint8 zone;
guint16 subnetwork;
guint16 processor;
guint32 tipc_address;
tipc_address = data[0];
tipc_address = (tipc_address << 8) ^ data[1];
tipc_address = (tipc_address << 8) ^ data[2];
tipc_address = (tipc_address << 8) ^ data[3];
processor = tipc_address & 0x0fff;
tipc_address = tipc_address >> 12;
subnetwork = tipc_address & 0x0fff;
tipc_address = tipc_address >> 12;
zone = tipc_address & 0xff;
g_snprintf(buf,buf_len,"%u.%u.%u",zone,subnetwork,processor);
}
static void
ib_addr_to_str_buf( const address *addr, gchar *buf, int buf_len){
if (addr->len >= 16) {
#define PREAMBLE_STR_LEN ((int)(sizeof("GID: ") - 1))
g_snprintf(buf,buf_len,"GID: ");
if (buf_len < PREAMBLE_STR_LEN ||
inet_ntop(AF_INET6, addr->data, buf + PREAMBLE_STR_LEN,
buf_len - PREAMBLE_STR_LEN) == NULL )
g_snprintf ( buf, buf_len, BUF_TOO_SMALL_ERR );
} else {
guint16 lid_number;
memcpy((void *)&lid_number, addr->data, sizeof lid_number);
g_snprintf(buf,buf_len,"LID: %u",lid_number);
}
}
const gchar *
fc_to_str(const guint8 *ad)
{
return bytestring_to_ep_str (ad, 3, '.');
}
const gchar *
tvb_fc_to_str(tvbuff_t *tvb, const gint offset)
{
return bytestring_to_ep_str (tvb_get_ptr(tvb, offset, 3), 3, '.');
}
gchar *
fcwwn_to_str (const guint8 *ad)
{
int fmt;
guint8 oui[6];
gchar *ethstr;
gchar *ethptr;
if (ad == NULL) return NULL;
ethstr=(gchar *)ep_alloc(512);
ethptr = bytes_to_hexstr_punct(ethstr, ad, 8, ':');
fmt = (ad[0] & 0xF0) >> 4;
switch (fmt) {
case FC_NH_NAA_IEEE:
case FC_NH_NAA_IEEE_E:
memcpy (oui, &ad[2], 6);
g_snprintf (ethptr, 512-23, " (%s)", get_manuf_name (oui));
break;
case FC_NH_NAA_IEEE_R:
oui[0] = ((ad[0] & 0x0F) << 4) | ((ad[1] & 0xF0) >> 4);
oui[1] = ((ad[1] & 0x0F) << 4) | ((ad[2] & 0xF0) >> 4);
oui[2] = ((ad[2] & 0x0F) << 4) | ((ad[3] & 0xF0) >> 4);
oui[3] = ((ad[3] & 0x0F) << 4) | ((ad[4] & 0xF0) >> 4);
oui[4] = ((ad[4] & 0x0F) << 4) | ((ad[5] & 0xF0) >> 4);
oui[5] = ((ad[5] & 0x0F) << 4) | ((ad[6] & 0xF0) >> 4);
g_snprintf (ethptr, 512-23, " (%s)", get_manuf_name (oui));
break;
default:
*ethptr = '\0';
break;
}
return (ethstr);
}
gchar *
tvb_fcwwn_to_str(tvbuff_t *tvb, const gint offset)
{
return fcwwn_to_str (tvb_get_ptr(tvb, offset, 8));
}
const gchar *
ax25_to_str(const guint8 *ad)
{
return bytestring_to_ep_str(ad, 7, ':');
}
gchar *
get_ax25_name(const guint8 *ad)
{
address addr;
addr.type = AT_AX25;
addr.len = 7;
addr.data = ad;
return ep_address_to_str( &addr );
}
gchar*
address_to_str(wmem_allocator_t *scope, const address *addr)
{
gchar *str;
str=(gchar *)wmem_alloc(scope, MAX_ADDR_STR_LEN);
address_to_str_buf(addr, str, MAX_ADDR_STR_LEN);
return str;
}
gchar*
ep_address_to_str(const address *addr)
{
gchar *str;
str=(gchar *)ep_alloc(MAX_ADDR_STR_LEN);
address_to_str_buf(addr, str, MAX_ADDR_STR_LEN);
return str;
}
void
address_to_str_buf(const address *addr, gchar *buf, int buf_len)
{
const guint8 *addrdata;
struct atalk_ddp_addr ddp_addr;
guint16 ieee_802_15_4_short_addr;
char temp[32];
char *tempptr = temp;
if (!buf || !buf_len)
return;
switch(addr->type){
case AT_NONE:
buf[0] = '\0';
break;
case AT_ETHER:
tempptr = bytes_to_hexstr_punct(tempptr, (const guint8 *)addr->data, 6, ':');
break;
case AT_IPv4:
ip_to_str_buf((const guint8 *)addr->data, buf, buf_len);
break;
case AT_IPv6:
ip6_to_str_buf_len((const guchar *)addr->data, buf, buf_len);
break;
case AT_IPX:
addrdata = (const guint8 *)addr->data;
tempptr = bytes_to_hexstr(tempptr, &addrdata[0], 4);
*tempptr++ = '.';
tempptr = bytes_to_hexstr(tempptr, &addrdata[4], 6);
break;
case AT_SNA:
sna_fid_to_str_buf(addr, buf, buf_len);
break;
case AT_ATALK:
memcpy(&ddp_addr, addr->data, sizeof ddp_addr);
atalk_addr_to_str_buf(&ddp_addr, buf, buf_len);
break;
case AT_VINES:
vines_addr_to_str_buf((const guint8 *)addr->data, buf, buf_len);
break;
case AT_USB:
usb_addr_to_str_buf((const guint8 *)addr->data, buf, buf_len);
break;
case AT_OSI:
print_nsap_net_buf((const guint8 *)addr->data, addr->len, buf, buf_len);
break;
case AT_ARCNET:
tempptr = g_stpcpy(tempptr, "0x");
tempptr = bytes_to_hexstr(tempptr, (const guint8 *)addr->data, 1);
break;
case AT_FC:
tempptr = bytes_to_hexstr_punct(tempptr, (const guint8 *)addr->data, 3, '.');
break;
case AT_SS7PC:
mtp3_addr_to_str_buf((const mtp3_addr_pc_t *)addr->data, buf, buf_len);
break;
case AT_STRINGZ:
g_strlcpy(buf, (const gchar *)addr->data, buf_len);
break;
case AT_EUI64:
tempptr = bytes_to_hexstr_punct(tempptr, (const guint8 *)addr->data, 8, ':');
break;
case AT_URI: {
int copy_len = addr->len < (buf_len - 1) ? addr->len : (buf_len - 1);
memcpy(buf, addr->data, copy_len );
buf[copy_len] = '\0';
}
break;
case AT_TIPC:
tipc_addr_to_str_buf((const guint8 *)addr->data, buf, buf_len);
break;
case AT_IB:
ib_addr_to_str_buf(addr, buf, buf_len);
break;
case AT_AX25:
addrdata = (const guint8 *)addr->data;
g_snprintf(buf, buf_len, "%c%c%c%c%c%c-%02d",
printable_char_or_period(addrdata[0] >> 1),
printable_char_or_period(addrdata[1] >> 1),
printable_char_or_period(addrdata[2] >> 1),
printable_char_or_period(addrdata[3] >> 1),
printable_char_or_period(addrdata[4] >> 1),
printable_char_or_period(addrdata[5] >> 1),
(addrdata[6] >> 1) & 0x0f );
break;
case AT_IEEE_802_15_4_SHORT:
ieee_802_15_4_short_addr = pletoh16(addr->data);
if (ieee_802_15_4_short_addr == 0xffff)
g_snprintf(buf, buf_len, "Broadcast");
else
g_snprintf(buf, buf_len, "0x%04x", ieee_802_15_4_short_addr);
break;
case AT_J1939:
addrdata = (const guint8 *)addr->data;
g_snprintf(buf, buf_len, "%d", addrdata[0]);
break;
case AT_DEVICENET:
addrdata = (const guint8 *)addr->data;
g_snprintf(buf, buf_len, "%d", addrdata[0] & 0x3f);
break;
default:
g_assert_not_reached();
}
if (tempptr != temp) {
size_t temp_len = (size_t) (tempptr - temp);
if (temp_len < (size_t) buf_len) {
memcpy(buf, temp, temp_len);
buf[temp_len] = '\0';
} else
g_strlcpy(buf, BUF_TOO_SMALL_ERR, buf_len);
}
}
