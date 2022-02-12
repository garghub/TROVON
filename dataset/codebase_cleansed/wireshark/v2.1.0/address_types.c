static void address_type_register(int addr_type, address_type_t *at)
{
g_assert(addr_type < MAX_ADDR_TYPE_VALUE);
g_assert(addr_type == at->addr_type);
g_assert(type_list[addr_type] == NULL);
DISSECTOR_ASSERT(at->name);
DISSECTOR_ASSERT(at->pretty_name);
DISSECTOR_ASSERT(at->addr_to_str);
DISSECTOR_ASSERT(at->addr_str_len);
DISSECTOR_ASSERT(((at->addr_name_res_str != NULL) && (at->addr_name_res_len != NULL)) ||
((at->addr_name_res_str == NULL) && (at->addr_name_res_len == NULL)));
type_list[addr_type] = at;
}
int address_type_dissector_register(const char* name, const char* pretty_name,
AddrValueToString to_str_func, AddrValueToStringLen str_len_func,
AddrColFilterString col_filter_str_func, AddrFixedLen fixed_len_func,
AddrNameResolutionToString name_res_str_func, AddrNameResolutionLen name_res_len_func)
{
int addr_type;
DISSECTOR_ASSERT(name);
DISSECTOR_ASSERT(pretty_name);
DISSECTOR_ASSERT(to_str_func);
DISSECTOR_ASSERT(str_len_func);
DISSECTOR_ASSERT(((name_res_str_func != NULL) && (name_res_len_func != NULL)) ||
((name_res_str_func == NULL) && (name_res_len_func == NULL)));
DISSECTOR_ASSERT(num_dissector_addr_type < MAX_DISSECTOR_ADDR_TYPE);
addr_type = AT_END_OF_LIST+num_dissector_addr_type;
dissector_type_addresses[num_dissector_addr_type].addr_type = addr_type;
dissector_type_addresses[num_dissector_addr_type].name = name;
dissector_type_addresses[num_dissector_addr_type].pretty_name = pretty_name;
dissector_type_addresses[num_dissector_addr_type].addr_to_str = to_str_func;
dissector_type_addresses[num_dissector_addr_type].addr_str_len = str_len_func;
dissector_type_addresses[num_dissector_addr_type].addr_col_filter = col_filter_str_func;
dissector_type_addresses[num_dissector_addr_type].addr_fixed_len = fixed_len_func;
dissector_type_addresses[num_dissector_addr_type].addr_name_res_str = name_res_str_func;
dissector_type_addresses[num_dissector_addr_type].addr_name_res_len = name_res_len_func;
type_list[addr_type] = &dissector_type_addresses[num_dissector_addr_type];
num_dissector_addr_type++;
return addr_type;
}
int none_addr_to_str(const address* addr _U_, gchar *buf, int buf_len _U_)
{
buf[0] = '\0';
return none_addr_str_len(addr);
}
int none_addr_str_len(const address* addr _U_)
{
return 1;
}
int none_addr_len(void)
{
return 0;
}
static int none_name_res_len(void)
{
return 5;
}
static const gchar* none_name_res_str(const address* addr _U_)
{
return "NONE";
}
int ether_to_str(const address* addr, gchar *buf, int buf_len _U_)
{
bytes_to_hexstr_punct(buf, (const guint8*)addr->data, 6, ':');
buf[17] = '\0';
return ether_str_len(addr);
}
int ether_str_len(const address* addr _U_)
{
return 18;
}
static const char* ether_col_filter_str(const address* addr _U_, gboolean is_src)
{
if (is_src)
return "eth.src";
return "eth.dst";
}
int ether_len(void)
{
return 6;
}
const gchar* ether_name_resolution_str(const address* addr)
{
return get_ether_name((const guint8 *)addr->data);
}
int ether_name_resolution_len(void)
{
return MAX_ADDR_STR_LEN;
}
static int ipv4_to_str(const address* addr, gchar *buf, int buf_len)
{
ip_to_str_buf((const guint8*)addr->data, buf, buf_len);
return (int)(strlen(buf)+1);
}
static int ipv4_str_len(const address* addr _U_)
{
return MAX_IP_STR_LEN;
}
static const char* ipv4_col_filter_str(const address* addr _U_, gboolean is_src)
{
if (is_src)
return "ip.src";
return "ip.dst";
}
static int ipv4_len(void)
{
return 4;
}
static const gchar* ipv4_name_res_str(const address* addr)
{
guint32 ip4_addr;
memcpy(&ip4_addr, addr->data, sizeof ip4_addr);
return get_hostname(ip4_addr);
}
static int ipv4_name_res_len(void)
{
return MAX_ADDR_STR_LEN;
}
static int ipv6_to_str(const address* addr, gchar *buf, int buf_len)
{
ip6_to_str_buf((const struct e_in6_addr *)addr->data, buf, buf_len);
return (int)(strlen(buf)+1);
}
static int ipv6_str_len(const address* addr _U_)
{
return MAX_IP6_STR_LEN;
}
static const char* ipv6_col_filter_str(const address* addr _U_, gboolean is_src)
{
if (is_src)
return "ipv6.src";
return "ipv6.dst";
}
static int ipv6_len(void)
{
return 16;
}
static const gchar* ipv6_name_res_str(const address* addr)
{
struct e_in6_addr ip6_addr;
memcpy(&ip6_addr.bytes, addr->data, sizeof ip6_addr.bytes);
return get_hostname6(&ip6_addr);
}
static int ipv6_name_res_len(void)
{
return MAX_ADDR_STR_LEN;
}
static int ipx_to_str(const address* addr, gchar *buf, int buf_len _U_)
{
const guint8 *addrdata = (const guint8 *)addr->data;
gchar *bufp = buf;
bufp = bytes_to_hexstr(bufp, &addrdata[0], 4);
*bufp++ = '.';
bufp = bytes_to_hexstr(bufp, &addrdata[4], 6);
*bufp++ = '\0';
return (int)(bufp - buf);
}
static int ipx_str_len(const address* addr _U_)
{
return 22;
}
static int ipx_len(void)
{
return 10;
}
static int vines_to_str(const address* addr, gchar *buf, int buf_len _U_)
{
const guint8 *addr_data = (const guint8 *)addr->data;
gchar *bufp = buf;
bufp = dword_to_hex(bufp, pntoh32(&addr_data[0]));
*bufp++ = '.';
bufp = word_to_hex(bufp, pntoh16(&addr_data[4]));
*bufp++ = '\0';
return (int)(bufp - buf);
}
static int vines_str_len(const address* addr _U_)
{
return 14;
}
static int vines_len(void)
{
return VINES_ADDR_LEN;
}
static int fc_to_str(const address* addr, gchar *buf, int buf_len _U_)
{
gchar *bufp = buf;
bufp = bytes_to_hexstr_punct(bufp, (const guint8 *)addr->data, 3, '.');
*bufp++ = '\0';
return (int)(bufp - buf);
}
static int fc_str_len(const address* addr _U_)
{
return 9;
}
static int fc_len(void)
{
return 3;
}
static int fcwwn_str_len(const address* addr _U_)
{
return 24;
}
static int fcwwn_to_str(const address* addr, gchar *buf, int buf_len _U_)
{
const guint8 *addrp = (const guint8*)addr->data;
buf = bytes_to_hexstr_punct(buf, addrp, 8, ':');
*buf = '\0';
return fcwwn_str_len(addr);
}
static int fcwwn_len(void)
{
return FCWWN_ADDR_LEN;
}
static const gchar* fcwwn_name_res_str(const address* addr)
{
const guint8 *addrp = (const guint8*)addr->data;
int fmt;
guint8 oui[6];
fmt = (addrp[0] & 0xF0) >> 4;
switch (fmt) {
case FC_NH_NAA_IEEE:
case FC_NH_NAA_IEEE_E:
memcpy (oui, &addrp[2], 6);
return get_manuf_name(oui);
case FC_NH_NAA_IEEE_R:
oui[0] = ((addrp[0] & 0x0F) << 4) | ((addrp[1] & 0xF0) >> 4);
oui[1] = ((addrp[1] & 0x0F) << 4) | ((addrp[2] & 0xF0) >> 4);
oui[2] = ((addrp[2] & 0x0F) << 4) | ((addrp[3] & 0xF0) >> 4);
oui[3] = ((addrp[3] & 0x0F) << 4) | ((addrp[4] & 0xF0) >> 4);
oui[4] = ((addrp[4] & 0x0F) << 4) | ((addrp[5] & 0xF0) >> 4);
oui[5] = ((addrp[5] & 0x0F) << 4) | ((addrp[6] & 0xF0) >> 4);
return get_manuf_name(oui);
}
return "";
}
static int fcwwn_name_res_len(void)
{
return MAX_ADDR_STR_LEN;
}
static int ss7pc_to_str(const address* addr, gchar *buf, int buf_len)
{
mtp3_addr_to_str_buf((const mtp3_addr_pc_t *)addr->data, buf, buf_len);
return (int)(strlen(buf)+1);
}
static int ss7pc_str_len(const address* addr _U_)
{
return 50;
}
static int stringz_addr_to_str(const address* addr, gchar *buf, int buf_len)
{
g_strlcpy(buf, (const gchar *)addr->data, buf_len);
return (int)(strlen(buf)+1);
}
static int stringz_addr_str_len(const address* addr)
{
return addr->len+1;
}
static int eui64_addr_to_str(const address* addr, gchar *buf, int buf_len _U_)
{
buf = bytes_to_hexstr_punct(buf, (const guint8 *)addr->data, 8, ':');
*buf = '\0';
return sizeof(buf) + 1;
}
static int eui64_str_len(const address* addr _U_)
{
return EUI64_STR_LEN;
}
static int eui64_len(void)
{
return 8;
}
static int
ib_addr_to_str( const address *addr, gchar *buf, int buf_len){
if (addr->len >= 16) {
#define PREAMBLE_STR_LEN ((int)(sizeof("GID: ") - 1))
g_strlcpy(buf, "GID: ", buf_len);
if (buf_len < PREAMBLE_STR_LEN ||
ws_inet_ntop6(addr->data, buf + PREAMBLE_STR_LEN,
buf_len - PREAMBLE_STR_LEN) == NULL )
g_strlcpy(buf, BUF_TOO_SMALL_ERR, buf_len);
} else {
guint16 lid_number;
memcpy((void *)&lid_number, addr->data, sizeof lid_number);
g_snprintf(buf,buf_len,"LID: %u",lid_number);
}
return sizeof(buf) + 1;
}
static int ib_str_len(const address* addr _U_)
{
return MAX_ADDR_STR_LEN;
}
static int usb_addr_to_str(const address* addr, gchar *buf, int buf_len _U_)
{
const guint8 *addrp = (const guint8 *)addr->data;
if(pletoh32(&addrp[0])==0xffffffff){
g_strlcpy(buf, "host", buf_len);
} else {
g_snprintf(buf, buf_len, "%d.%d.%d", pletoh16(&addrp[8]),
pletoh32(&addrp[0]), pletoh32(&addrp[4]));
}
return (int)(strlen(buf)+1);
}
static int usb_addr_str_len(const address* addr _U_)
{
return 50;
}
static int ax25_addr_to_str(const address* addr, gchar *buf, int buf_len _U_)
{
const guint8 *addrdata = (const guint8 *)addr->data;
gchar *bufp = buf;
*bufp++ = printable_char_or_period(addrdata[0] >> 1);
*bufp++ = printable_char_or_period(addrdata[1] >> 1);
*bufp++ = printable_char_or_period(addrdata[2] >> 1);
*bufp++ = printable_char_or_period(addrdata[3] >> 1);
*bufp++ = printable_char_or_period(addrdata[4] >> 1);
*bufp++ = printable_char_or_period(addrdata[5] >> 1);
*bufp++ = '-';
bufp = uint_to_str_back(bufp, (addrdata[6] >> 1) & 0x0f);
*bufp++ = '\0';
return (int)(bufp - buf);
}
static int ax25_addr_str_len(const address* addr _U_)
{
return 21;
}
static const char* ax25_col_filter_str(const address* addr _U_, gboolean is_src)
{
if (is_src)
return "ax25.src";
return "ax25.dst";
}
static int ax25_len(void)
{
return AX25_ADDR_LEN;
}
void address_types_initialize(void)
{
static address_type_t none_address = {
AT_NONE,
"AT_NONE",
"No address",
none_addr_to_str,
none_addr_str_len,
NULL,
none_addr_len,
none_name_res_str,
none_name_res_len,
};
static address_type_t ether_address = {
AT_ETHER,
"AT_ETHER",
"Ethernet address",
ether_to_str,
ether_str_len,
ether_col_filter_str,
ether_len,
ether_name_resolution_str,
ether_name_resolution_len,
};
static address_type_t ipv4_address = {
AT_IPv4,
"AT_IPv4",
"IPv4 address",
ipv4_to_str,
ipv4_str_len,
ipv4_col_filter_str,
ipv4_len,
ipv4_name_res_str,
ipv4_name_res_len,
};
static address_type_t ipv6_address = {
AT_IPv6,
"AT_IPv6",
"IPv6 address",
ipv6_to_str,
ipv6_str_len,
ipv6_col_filter_str,
ipv6_len,
ipv6_name_res_str,
ipv6_name_res_len,
};
static address_type_t ipx_address = {
AT_IPX,
"AT_IPX",
"IPX address",
ipx_to_str,
ipx_str_len,
NULL,
ipx_len,
NULL,
NULL,
};
static address_type_t vines_address = {
AT_VINES,
"AT_VINES",
"Banyan Vines address",
vines_to_str,
vines_str_len,
NULL,
vines_len,
NULL,
NULL,
};
static address_type_t fc_address = {
AT_FC,
"AT_FC",
"FC address",
fc_to_str,
fc_str_len,
NULL,
fc_len,
NULL,
NULL,
};
static address_type_t fcwwn_address = {
AT_FCWWN,
"AT_FCWWN",
"Fibre Channel WWN",
fcwwn_to_str,
fcwwn_str_len,
NULL,
fcwwn_len,
fcwwn_name_res_str,
fcwwn_name_res_len,
};
static address_type_t ss7pc_address = {
AT_SS7PC,
"AT_SS7PC",
"SS7 Point Code",
ss7pc_to_str,
ss7pc_str_len,
NULL,
NULL,
NULL,
NULL,
};
static address_type_t stringz_address = {
AT_STRINGZ,
"AT_STRINGZ",
"String address",
stringz_addr_to_str,
stringz_addr_str_len,
NULL,
NULL,
NULL,
NULL,
};
static address_type_t eui64_address = {
AT_EUI64,
"AT_EUI64",
"IEEE EUI-64",
eui64_addr_to_str,
eui64_str_len,
NULL,
eui64_len,
NULL,
NULL,
};
static address_type_t ib_address = {
AT_IB,
"AT_IB",
"Infiniband GID/LID",
ib_addr_to_str,
ib_str_len,
NULL,
NULL,
NULL,
NULL,
};
static address_type_t usb_address = {
AT_USB,
"AT_USB",
"USB Address",
usb_addr_to_str,
usb_addr_str_len,
NULL,
NULL,
NULL,
NULL,
};
static address_type_t ax25_address = {
AT_AX25,
"AT_AX25",
"AX.25 Address",
ax25_addr_to_str,
ax25_addr_str_len,
ax25_col_filter_str,
ax25_len,
NULL,
NULL,
};
num_dissector_addr_type = 0;
memset(type_list, 0, MAX_ADDR_TYPE_VALUE*sizeof(address_type_t*));
address_type_register(AT_NONE, &none_address );
address_type_register(AT_ETHER, &ether_address );
address_type_register(AT_IPv4, &ipv4_address );
address_type_register(AT_IPv6, &ipv6_address );
address_type_register(AT_IPX, &ipx_address );
address_type_register(AT_VINES, &vines_address );
address_type_register(AT_FC, &fc_address );
address_type_register(AT_FCWWN, &fcwwn_address );
address_type_register(AT_SS7PC, &ss7pc_address );
address_type_register(AT_STRINGZ, &stringz_address );
address_type_register(AT_EUI64, &eui64_address );
address_type_register(AT_IB, &ib_address );
address_type_register(AT_USB, &usb_address );
address_type_register(AT_AX25, &ax25_address );
}
static int address_type_get_length(const address* addr)
{
address_type_t *at;
ADDR_TYPE_LOOKUP(addr->type, at);
if (at == NULL)
return 0;
return at->addr_str_len(addr);
}
gchar*
address_to_str(wmem_allocator_t *scope, const address *addr)
{
gchar *str;
int len = address_type_get_length(addr);
if (len <= 0)
len = MAX_ADDR_STR_LEN;
str=(gchar *)wmem_alloc(scope, len);
address_to_str_buf(addr, str, len);
return str;
}
void address_to_str_buf(const address* addr, gchar *buf, int buf_len)
{
address_type_t *at;
if (!buf || !buf_len)
return;
ADDR_TYPE_LOOKUP(addr->type, at);
if ((at == NULL) || (at->addr_to_str == NULL))
{
buf[0] = '\0';
return;
}
at->addr_to_str(addr, buf, buf_len);
}
const gchar *
address_to_name(const address *addr)
{
address_type_t *at;
ADDR_TYPE_LOOKUP(addr->type, at);
if (at == NULL)
{
return NULL;
}
switch (addr->type) {
case AT_STRINGZ:
return (const gchar *)addr->data;
default:
if (at->addr_name_res_str != NULL)
return at->addr_name_res_str(addr);
else
return NULL;
}
}
gchar *
address_to_display(wmem_allocator_t *allocator, const address *addr)
{
gchar *str = NULL;
const gchar *result = address_to_name(addr);
if (result != NULL) {
str = wmem_strdup(allocator, result);
}
else if (addr->type == AT_NONE) {
str = wmem_strdup(allocator, "NONE");
}
else {
str = (gchar *) wmem_alloc(allocator, MAX_ADDR_STR_LEN);
address_to_str_buf(addr, str, MAX_ADDR_STR_LEN);
}
return str;
}
static void address_with_resolution_to_str_buf(const address* addr, gchar *buf, int buf_len)
{
address_type_t *at;
int addr_len;
gsize pos;
gboolean empty;
if (!buf || !buf_len)
return;
ADDR_TYPE_LOOKUP(addr->type, at);
if (at == NULL)
{
buf[0] = '\0';
return;
}
#if 0
if (at->addr_name_res_str == NULL)
return address_to_str_buf(addr, buf, buf_len);
#endif
pos = g_strlcpy(buf, at->addr_name_res_str(addr), buf_len);
if (addr->type == AT_NONE)
return;
if ((int)(pos + 4 + at->addr_str_len(addr)) >= buf_len)
return;
empty = (pos <= 1) ? TRUE : FALSE;
if (!empty)
{
buf[pos++] = ' ';
buf[pos++] = '(';
}
addr_len = at->addr_to_str(addr, &buf[pos], (int)(buf_len-pos));
pos += addr_len - 1;
if (!empty)
{
buf[pos++] = ')';
buf[pos++] = '\0';
}
}
gchar* address_with_resolution_to_str(wmem_allocator_t *scope, const address *addr)
{
address_type_t *at;
int len;
gchar *str;
ADDR_TYPE_LOOKUP(addr->type, at);
if (at == NULL)
return wmem_strdup(scope, "");
if ((at->addr_name_res_str == NULL) ||
(ADDR_RESOLV_MACADDR(addr) && !gbl_resolv_flags.mac_name) ||
(ADDR_RESOLV_NETADDR(addr) && !gbl_resolv_flags.network_name)) {
return address_to_str(scope, addr);
}
len = at->addr_name_res_len() + at->addr_str_len(addr) + 4;
str=(gchar *)wmem_alloc(scope, len);
address_with_resolution_to_str_buf(addr, str, len);
return str;
}
const char* address_type_column_filter_string(const address* addr, gboolean src)
{
address_type_t *at;
ADDR_TYPE_LOOKUP(addr->type, at);
if ((at == NULL) || (at->addr_col_filter == NULL))
{
return "";
}
return at->addr_col_filter(addr, src);
}
gchar*
tvb_address_to_str(wmem_allocator_t *scope, tvbuff_t *tvb, int type, const gint offset)
{
address addr;
address_type_t *at;
ADDR_TYPE_LOOKUP(type, at);
if (at == NULL)
{
return NULL;
}
if (at->addr_fixed_len == NULL)
{
g_assert_not_reached();
return NULL;
}
set_address_tvb(&addr, type, at->addr_fixed_len(), tvb, offset);
return address_to_str(scope, &addr);
}
gchar* tvb_address_var_to_str(wmem_allocator_t *scope, tvbuff_t *tvb, address_type type, const gint offset, int length)
{
address addr;
set_address_tvb(&addr, type, length, tvb, offset);
return address_to_str(scope, &addr);
}
gchar*
tvb_address_with_resolution_to_str(wmem_allocator_t *scope, tvbuff_t *tvb, int type, const gint offset)
{
address addr;
address_type_t *at;
ADDR_TYPE_LOOKUP(type, at);
if (at == NULL)
{
return NULL;
}
if (at->addr_fixed_len == NULL)
{
g_assert_not_reached();
return NULL;
}
set_address_tvb(&addr, type, at->addr_fixed_len(), tvb, offset);
return address_with_resolution_to_str(scope, &addr);
}
