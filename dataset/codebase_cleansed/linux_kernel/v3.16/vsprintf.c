unsigned long long simple_strtoull(const char *cp, char **endp, unsigned int base)
{
unsigned long long result;
unsigned int rv;
cp = _parse_integer_fixup_radix(cp, &base);
rv = _parse_integer(cp, base, &result);
cp += (rv & ~KSTRTOX_OVERFLOW);
if (endp)
*endp = (char *)cp;
return result;
}
unsigned long simple_strtoul(const char *cp, char **endp, unsigned int base)
{
return simple_strtoull(cp, endp, base);
}
long simple_strtol(const char *cp, char **endp, unsigned int base)
{
if (*cp == '-')
return -simple_strtoul(cp + 1, endp, base);
return simple_strtoul(cp, endp, base);
}
long long simple_strtoll(const char *cp, char **endp, unsigned int base)
{
if (*cp == '-')
return -simple_strtoull(cp + 1, endp, base);
return simple_strtoull(cp, endp, base);
}
static noinline_for_stack
int skip_atoi(const char **s)
{
int i = 0;
while (isdigit(**s))
i = i*10 + *((*s)++) - '0';
return i;
}
static noinline_for_stack
char *put_dec_full9(char *buf, unsigned q)
{
unsigned r;
r = (q * (uint64_t)0x1999999a) >> 32;
*buf++ = (q - 10 * r) + '0';
q = (r * (uint64_t)0x1999999a) >> 32;
*buf++ = (r - 10 * q) + '0';
r = (q * (uint64_t)0x1999999a) >> 32;
*buf++ = (q - 10 * r) + '0';
q = (r * (uint64_t)0x1999999a) >> 32;
*buf++ = (r - 10 * q) + '0';
r = (q * (uint64_t)0x1999999a) >> 32;
*buf++ = (q - 10 * r) + '0';
q = (r * 0x199a) >> 16;
*buf++ = (r - 10 * q) + '0';
r = (q * 0xcd) >> 11;
*buf++ = (q - 10 * r) + '0';
q = (r * 0xcd) >> 11;
*buf++ = (r - 10 * q) + '0';
*buf++ = q + '0';
return buf;
}
static noinline_for_stack
char *put_dec_trunc8(char *buf, unsigned r)
{
unsigned q;
while (r >= 10000) {
q = r + '0';
r = (r * (uint64_t)0x1999999a) >> 32;
*buf++ = q - 10*r;
}
q = (r * 0x199a) >> 16;
*buf++ = (r - 10 * q) + '0';
if (q == 0)
return buf;
r = (q * 0xcd) >> 11;
*buf++ = (q - 10 * r) + '0';
if (r == 0)
return buf;
q = (r * 0xcd) >> 11;
*buf++ = (r - 10 * q) + '0';
if (q == 0)
return buf;
*buf++ = q + '0';
return buf;
}
static
char *put_dec(char *buf, unsigned long long n)
{
if (n >= 100*1000*1000) {
while (n >= 1000*1000*1000)
buf = put_dec_full9(buf, do_div(n, 1000*1000*1000));
if (n >= 100*1000*1000)
return put_dec_full9(buf, n);
}
return put_dec_trunc8(buf, n);
}
static noinline_for_stack
void put_dec_full4(char *buf, unsigned q)
{
unsigned r;
r = (q * 0xccd) >> 15;
buf[0] = (q - 10 * r) + '0';
q = (r * 0xcd) >> 11;
buf[1] = (r - 10 * q) + '0';
r = (q * 0xcd) >> 11;
buf[2] = (q - 10 * r) + '0';
buf[3] = r + '0';
}
static
unsigned put_dec_helper4(char *buf, unsigned x)
{
uint32_t q = (x * (uint64_t)0x346DC5D7) >> 43;
put_dec_full4(buf, x - q * 10000);
return q;
}
static
char *put_dec(char *buf, unsigned long long n)
{
uint32_t d3, d2, d1, q, h;
if (n < 100*1000*1000)
return put_dec_trunc8(buf, n);
d1 = ((uint32_t)n >> 16);
h = (n >> 32);
d2 = (h ) & 0xffff;
d3 = (h >> 16);
q = 656 * d3 + 7296 * d2 + 5536 * d1 + ((uint32_t)n & 0xffff);
q = put_dec_helper4(buf, q);
q += 7671 * d3 + 9496 * d2 + 6 * d1;
q = put_dec_helper4(buf+4, q);
q += 4749 * d3 + 42 * d2;
q = put_dec_helper4(buf+8, q);
q += 281 * d3;
buf += 12;
if (q)
buf = put_dec_trunc8(buf, q);
else while (buf[-1] == '0')
--buf;
return buf;
}
int num_to_str(char *buf, int size, unsigned long long num)
{
char tmp[sizeof(num) * 3];
int idx, len;
if (num <= 9) {
tmp[0] = '0' + num;
len = 1;
} else {
len = put_dec(tmp, num) - tmp;
}
if (len > size)
return 0;
for (idx = 0; idx < len; ++idx)
buf[idx] = tmp[len - idx - 1];
return len;
}
static noinline_for_stack
char *number(char *buf, char *end, unsigned long long num,
struct printf_spec spec)
{
static const char digits[16] = "0123456789ABCDEF";
char tmp[66];
char sign;
char locase;
int need_pfx = ((spec.flags & SPECIAL) && spec.base != 10);
int i;
bool is_zero = num == 0LL;
locase = (spec.flags & SMALL);
if (spec.flags & LEFT)
spec.flags &= ~ZEROPAD;
sign = 0;
if (spec.flags & SIGN) {
if ((signed long long)num < 0) {
sign = '-';
num = -(signed long long)num;
spec.field_width--;
} else if (spec.flags & PLUS) {
sign = '+';
spec.field_width--;
} else if (spec.flags & SPACE) {
sign = ' ';
spec.field_width--;
}
}
if (need_pfx) {
if (spec.base == 16)
spec.field_width -= 2;
else if (!is_zero)
spec.field_width--;
}
i = 0;
if (num < spec.base)
tmp[i++] = digits[num] | locase;
else if (spec.base != 10) {
int mask = spec.base - 1;
int shift = 3;
if (spec.base == 16)
shift = 4;
do {
tmp[i++] = (digits[((unsigned char)num) & mask] | locase);
num >>= shift;
} while (num);
} else {
i = put_dec(tmp, num) - tmp;
}
if (i > spec.precision)
spec.precision = i;
spec.field_width -= spec.precision;
if (!(spec.flags & (ZEROPAD+LEFT))) {
while (--spec.field_width >= 0) {
if (buf < end)
*buf = ' ';
++buf;
}
}
if (sign) {
if (buf < end)
*buf = sign;
++buf;
}
if (need_pfx) {
if (spec.base == 16 || !is_zero) {
if (buf < end)
*buf = '0';
++buf;
}
if (spec.base == 16) {
if (buf < end)
*buf = ('X' | locase);
++buf;
}
}
if (!(spec.flags & LEFT)) {
char c = (spec.flags & ZEROPAD) ? '0' : ' ';
while (--spec.field_width >= 0) {
if (buf < end)
*buf = c;
++buf;
}
}
while (i <= --spec.precision) {
if (buf < end)
*buf = '0';
++buf;
}
while (--i >= 0) {
if (buf < end)
*buf = tmp[i];
++buf;
}
while (--spec.field_width >= 0) {
if (buf < end)
*buf = ' ';
++buf;
}
return buf;
}
static noinline_for_stack
char *string(char *buf, char *end, const char *s, struct printf_spec spec)
{
int len, i;
if ((unsigned long)s < PAGE_SIZE)
s = "(null)";
len = strnlen(s, spec.precision);
if (!(spec.flags & LEFT)) {
while (len < spec.field_width--) {
if (buf < end)
*buf = ' ';
++buf;
}
}
for (i = 0; i < len; ++i) {
if (buf < end)
*buf = *s;
++buf; ++s;
}
while (len < spec.field_width--) {
if (buf < end)
*buf = ' ';
++buf;
}
return buf;
}
static void widen(char *buf, char *end, unsigned len, unsigned spaces)
{
size_t size;
if (buf >= end)
return;
size = end - buf;
if (size <= spaces) {
memset(buf, ' ', size);
return;
}
if (len) {
if (len > size - spaces)
len = size - spaces;
memmove(buf + spaces, buf, len);
}
memset(buf, ' ', spaces);
}
static noinline_for_stack
char *dentry_name(char *buf, char *end, const struct dentry *d, struct printf_spec spec,
const char *fmt)
{
const char *array[4], *s;
const struct dentry *p;
int depth;
int i, n;
switch (fmt[1]) {
case '2': case '3': case '4':
depth = fmt[1] - '0';
break;
default:
depth = 1;
}
rcu_read_lock();
for (i = 0; i < depth; i++, d = p) {
p = ACCESS_ONCE(d->d_parent);
array[i] = ACCESS_ONCE(d->d_name.name);
if (p == d) {
if (i)
array[i] = "";
i++;
break;
}
}
s = array[--i];
for (n = 0; n != spec.precision; n++, buf++) {
char c = *s++;
if (!c) {
if (!i)
break;
c = '/';
s = array[--i];
}
if (buf < end)
*buf = c;
}
rcu_read_unlock();
if (n < spec.field_width) {
unsigned spaces = spec.field_width - n;
if (!(spec.flags & LEFT)) {
widen(buf - n, end, n, spaces);
return buf + spaces;
}
while (spaces--) {
if (buf < end)
*buf = ' ';
++buf;
}
}
return buf;
}
static noinline_for_stack
char *symbol_string(char *buf, char *end, void *ptr,
struct printf_spec spec, const char *fmt)
{
unsigned long value;
#ifdef CONFIG_KALLSYMS
char sym[KSYM_SYMBOL_LEN];
#endif
if (fmt[1] == 'R')
ptr = __builtin_extract_return_addr(ptr);
value = (unsigned long)ptr;
#ifdef CONFIG_KALLSYMS
if (*fmt == 'B')
sprint_backtrace(sym, value);
else if (*fmt != 'f' && *fmt != 's')
sprint_symbol(sym, value);
else
sprint_symbol_no_offset(sym, value);
return string(buf, end, sym, spec);
#else
spec.field_width = 2 * sizeof(void *);
spec.flags |= SPECIAL | SMALL | ZEROPAD;
spec.base = 16;
return number(buf, end, value, spec);
#endif
}
static noinline_for_stack
char *resource_string(char *buf, char *end, struct resource *res,
struct printf_spec spec, const char *fmt)
{
#ifndef IO_RSRC_PRINTK_SIZE
#define IO_RSRC_PRINTK_SIZE 6
#endif
#ifndef MEM_RSRC_PRINTK_SIZE
#define MEM_RSRC_PRINTK_SIZE 10
#endif
static const struct printf_spec io_spec = {
.base = 16,
.field_width = IO_RSRC_PRINTK_SIZE,
.precision = -1,
.flags = SPECIAL | SMALL | ZEROPAD,
};
static const struct printf_spec mem_spec = {
.base = 16,
.field_width = MEM_RSRC_PRINTK_SIZE,
.precision = -1,
.flags = SPECIAL | SMALL | ZEROPAD,
};
static const struct printf_spec bus_spec = {
.base = 16,
.field_width = 2,
.precision = -1,
.flags = SMALL | ZEROPAD,
};
static const struct printf_spec dec_spec = {
.base = 10,
.precision = -1,
.flags = 0,
};
static const struct printf_spec str_spec = {
.field_width = -1,
.precision = 10,
.flags = LEFT,
};
static const struct printf_spec flag_spec = {
.base = 16,
.precision = -1,
.flags = SPECIAL | SMALL,
};
#define RSRC_BUF_SIZE ((2 * sizeof(resource_size_t)) + 4)
#define FLAG_BUF_SIZE (2 * sizeof(res->flags))
#define DECODED_BUF_SIZE sizeof("[mem - 64bit pref window disabled]")
#define RAW_BUF_SIZE sizeof("[mem - flags 0x]")
char sym[max(2*RSRC_BUF_SIZE + DECODED_BUF_SIZE,
2*RSRC_BUF_SIZE + FLAG_BUF_SIZE + RAW_BUF_SIZE)];
char *p = sym, *pend = sym + sizeof(sym);
int decode = (fmt[0] == 'R') ? 1 : 0;
const struct printf_spec *specp;
*p++ = '[';
if (res->flags & IORESOURCE_IO) {
p = string(p, pend, "io ", str_spec);
specp = &io_spec;
} else if (res->flags & IORESOURCE_MEM) {
p = string(p, pend, "mem ", str_spec);
specp = &mem_spec;
} else if (res->flags & IORESOURCE_IRQ) {
p = string(p, pend, "irq ", str_spec);
specp = &dec_spec;
} else if (res->flags & IORESOURCE_DMA) {
p = string(p, pend, "dma ", str_spec);
specp = &dec_spec;
} else if (res->flags & IORESOURCE_BUS) {
p = string(p, pend, "bus ", str_spec);
specp = &bus_spec;
} else {
p = string(p, pend, "??? ", str_spec);
specp = &mem_spec;
decode = 0;
}
if (decode && res->flags & IORESOURCE_UNSET) {
p = string(p, pend, "size ", str_spec);
p = number(p, pend, resource_size(res), *specp);
} else {
p = number(p, pend, res->start, *specp);
if (res->start != res->end) {
*p++ = '-';
p = number(p, pend, res->end, *specp);
}
}
if (decode) {
if (res->flags & IORESOURCE_MEM_64)
p = string(p, pend, " 64bit", str_spec);
if (res->flags & IORESOURCE_PREFETCH)
p = string(p, pend, " pref", str_spec);
if (res->flags & IORESOURCE_WINDOW)
p = string(p, pend, " window", str_spec);
if (res->flags & IORESOURCE_DISABLED)
p = string(p, pend, " disabled", str_spec);
} else {
p = string(p, pend, " flags ", str_spec);
p = number(p, pend, res->flags, flag_spec);
}
*p++ = ']';
*p = '\0';
return string(buf, end, sym, spec);
}
static noinline_for_stack
char *hex_string(char *buf, char *end, u8 *addr, struct printf_spec spec,
const char *fmt)
{
int i, len = 1;
char separator;
if (spec.field_width == 0)
return buf;
if (ZERO_OR_NULL_PTR(addr))
return string(buf, end, NULL, spec);
switch (fmt[1]) {
case 'C':
separator = ':';
break;
case 'D':
separator = '-';
break;
case 'N':
separator = 0;
break;
default:
separator = ' ';
break;
}
if (spec.field_width > 0)
len = min_t(int, spec.field_width, 64);
for (i = 0; i < len && buf < end - 1; i++) {
buf = hex_byte_pack(buf, addr[i]);
if (buf < end && separator && i != len - 1)
*buf++ = separator;
}
return buf;
}
static noinline_for_stack
char *mac_address_string(char *buf, char *end, u8 *addr,
struct printf_spec spec, const char *fmt)
{
char mac_addr[sizeof("xx:xx:xx:xx:xx:xx")];
char *p = mac_addr;
int i;
char separator;
bool reversed = false;
switch (fmt[1]) {
case 'F':
separator = '-';
break;
case 'R':
reversed = true;
default:
separator = ':';
break;
}
for (i = 0; i < 6; i++) {
if (reversed)
p = hex_byte_pack(p, addr[5 - i]);
else
p = hex_byte_pack(p, addr[i]);
if (fmt[0] == 'M' && i != 5)
*p++ = separator;
}
*p = '\0';
return string(buf, end, mac_addr, spec);
}
static noinline_for_stack
char *ip4_string(char *p, const u8 *addr, const char *fmt)
{
int i;
bool leading_zeros = (fmt[0] == 'i');
int index;
int step;
switch (fmt[2]) {
case 'h':
#ifdef __BIG_ENDIAN
index = 0;
step = 1;
#else
index = 3;
step = -1;
#endif
break;
case 'l':
index = 3;
step = -1;
break;
case 'n':
case 'b':
default:
index = 0;
step = 1;
break;
}
for (i = 0; i < 4; i++) {
char temp[3];
int digits = put_dec_trunc8(temp, addr[index]) - temp;
if (leading_zeros) {
if (digits < 3)
*p++ = '0';
if (digits < 2)
*p++ = '0';
}
while (digits--)
*p++ = temp[digits];
if (i < 3)
*p++ = '.';
index += step;
}
*p = '\0';
return p;
}
static noinline_for_stack
char *ip6_compressed_string(char *p, const char *addr)
{
int i, j, range;
unsigned char zerolength[8];
int longest = 1;
int colonpos = -1;
u16 word;
u8 hi, lo;
bool needcolon = false;
bool useIPv4;
struct in6_addr in6;
memcpy(&in6, addr, sizeof(struct in6_addr));
useIPv4 = ipv6_addr_v4mapped(&in6) || ipv6_addr_is_isatap(&in6);
memset(zerolength, 0, sizeof(zerolength));
if (useIPv4)
range = 6;
else
range = 8;
for (i = 0; i < range; i++) {
for (j = i; j < range; j++) {
if (in6.s6_addr16[j] != 0)
break;
zerolength[i]++;
}
}
for (i = 0; i < range; i++) {
if (zerolength[i] > longest) {
longest = zerolength[i];
colonpos = i;
}
}
if (longest == 1)
colonpos = -1;
for (i = 0; i < range; i++) {
if (i == colonpos) {
if (needcolon || i == 0)
*p++ = ':';
*p++ = ':';
needcolon = false;
i += longest - 1;
continue;
}
if (needcolon) {
*p++ = ':';
needcolon = false;
}
word = ntohs(in6.s6_addr16[i]);
hi = word >> 8;
lo = word & 0xff;
if (hi) {
if (hi > 0x0f)
p = hex_byte_pack(p, hi);
else
*p++ = hex_asc_lo(hi);
p = hex_byte_pack(p, lo);
}
else if (lo > 0x0f)
p = hex_byte_pack(p, lo);
else
*p++ = hex_asc_lo(lo);
needcolon = true;
}
if (useIPv4) {
if (needcolon)
*p++ = ':';
p = ip4_string(p, &in6.s6_addr[12], "I4");
}
*p = '\0';
return p;
}
static noinline_for_stack
char *ip6_string(char *p, const char *addr, const char *fmt)
{
int i;
for (i = 0; i < 8; i++) {
p = hex_byte_pack(p, *addr++);
p = hex_byte_pack(p, *addr++);
if (fmt[0] == 'I' && i != 7)
*p++ = ':';
}
*p = '\0';
return p;
}
static noinline_for_stack
char *ip6_addr_string(char *buf, char *end, const u8 *addr,
struct printf_spec spec, const char *fmt)
{
char ip6_addr[sizeof("xxxx:xxxx:xxxx:xxxx:xxxx:xxxx:255.255.255.255")];
if (fmt[0] == 'I' && fmt[2] == 'c')
ip6_compressed_string(ip6_addr, addr);
else
ip6_string(ip6_addr, addr, fmt);
return string(buf, end, ip6_addr, spec);
}
static noinline_for_stack
char *ip4_addr_string(char *buf, char *end, const u8 *addr,
struct printf_spec spec, const char *fmt)
{
char ip4_addr[sizeof("255.255.255.255")];
ip4_string(ip4_addr, addr, fmt);
return string(buf, end, ip4_addr, spec);
}
static noinline_for_stack
char *ip6_addr_string_sa(char *buf, char *end, const struct sockaddr_in6 *sa,
struct printf_spec spec, const char *fmt)
{
bool have_p = false, have_s = false, have_f = false, have_c = false;
char ip6_addr[sizeof("[xxxx:xxxx:xxxx:xxxx:xxxx:xxxx:255.255.255.255]") +
sizeof(":12345") + sizeof("/123456789") +
sizeof("%1234567890")];
char *p = ip6_addr, *pend = ip6_addr + sizeof(ip6_addr);
const u8 *addr = (const u8 *) &sa->sin6_addr;
char fmt6[2] = { fmt[0], '6' };
u8 off = 0;
fmt++;
while (isalpha(*++fmt)) {
switch (*fmt) {
case 'p':
have_p = true;
break;
case 'f':
have_f = true;
break;
case 's':
have_s = true;
break;
case 'c':
have_c = true;
break;
}
}
if (have_p || have_s || have_f) {
*p = '[';
off = 1;
}
if (fmt6[0] == 'I' && have_c)
p = ip6_compressed_string(ip6_addr + off, addr);
else
p = ip6_string(ip6_addr + off, addr, fmt6);
if (have_p || have_s || have_f)
*p++ = ']';
if (have_p) {
*p++ = ':';
p = number(p, pend, ntohs(sa->sin6_port), spec);
}
if (have_f) {
*p++ = '/';
p = number(p, pend, ntohl(sa->sin6_flowinfo &
IPV6_FLOWINFO_MASK), spec);
}
if (have_s) {
*p++ = '%';
p = number(p, pend, sa->sin6_scope_id, spec);
}
*p = '\0';
return string(buf, end, ip6_addr, spec);
}
static noinline_for_stack
char *ip4_addr_string_sa(char *buf, char *end, const struct sockaddr_in *sa,
struct printf_spec spec, const char *fmt)
{
bool have_p = false;
char *p, ip4_addr[sizeof("255.255.255.255") + sizeof(":12345")];
char *pend = ip4_addr + sizeof(ip4_addr);
const u8 *addr = (const u8 *) &sa->sin_addr.s_addr;
char fmt4[3] = { fmt[0], '4', 0 };
fmt++;
while (isalpha(*++fmt)) {
switch (*fmt) {
case 'p':
have_p = true;
break;
case 'h':
case 'l':
case 'n':
case 'b':
fmt4[2] = *fmt;
break;
}
}
p = ip4_string(ip4_addr, addr, fmt4);
if (have_p) {
*p++ = ':';
p = number(p, pend, ntohs(sa->sin_port), spec);
}
*p = '\0';
return string(buf, end, ip4_addr, spec);
}
static noinline_for_stack
char *uuid_string(char *buf, char *end, const u8 *addr,
struct printf_spec spec, const char *fmt)
{
char uuid[sizeof("xxxxxxxx-xxxx-xxxx-xxxx-xxxxxxxxxxxx")];
char *p = uuid;
int i;
static const u8 be[16] = {0,1,2,3,4,5,6,7,8,9,10,11,12,13,14,15};
static const u8 le[16] = {3,2,1,0,5,4,7,6,8,9,10,11,12,13,14,15};
const u8 *index = be;
bool uc = false;
switch (*(++fmt)) {
case 'L':
uc = true;
case 'l':
index = le;
break;
case 'B':
uc = true;
break;
}
for (i = 0; i < 16; i++) {
p = hex_byte_pack(p, addr[index[i]]);
switch (i) {
case 3:
case 5:
case 7:
case 9:
*p++ = '-';
break;
}
}
*p = 0;
if (uc) {
p = uuid;
do {
*p = toupper(*p);
} while (*(++p));
}
return string(buf, end, uuid, spec);
}
static
char *netdev_feature_string(char *buf, char *end, const u8 *addr,
struct printf_spec spec)
{
spec.flags |= SPECIAL | SMALL | ZEROPAD;
if (spec.field_width == -1)
spec.field_width = 2 + 2 * sizeof(netdev_features_t);
spec.base = 16;
return number(buf, end, *(const netdev_features_t *)addr, spec);
}
static noinline_for_stack
char *address_val(char *buf, char *end, const void *addr,
struct printf_spec spec, const char *fmt)
{
unsigned long long num;
spec.flags |= SPECIAL | SMALL | ZEROPAD;
spec.base = 16;
switch (fmt[1]) {
case 'd':
num = *(const dma_addr_t *)addr;
spec.field_width = sizeof(dma_addr_t) * 2 + 2;
break;
case 'p':
default:
num = *(const phys_addr_t *)addr;
spec.field_width = sizeof(phys_addr_t) * 2 + 2;
break;
}
return number(buf, end, num, spec);
}
static noinline_for_stack
char *pointer(const char *fmt, char *buf, char *end, void *ptr,
struct printf_spec spec)
{
int default_width = 2 * sizeof(void *) + (spec.flags & SPECIAL ? 2 : 0);
if (!ptr && *fmt != 'K') {
if (spec.field_width == -1)
spec.field_width = default_width;
return string(buf, end, "(null)", spec);
}
switch (*fmt) {
case 'F':
case 'f':
ptr = dereference_function_descriptor(ptr);
case 'S':
case 's':
case 'B':
return symbol_string(buf, end, ptr, spec, fmt);
case 'R':
case 'r':
return resource_string(buf, end, ptr, spec, fmt);
case 'h':
return hex_string(buf, end, ptr, spec, fmt);
case 'M':
case 'm':
return mac_address_string(buf, end, ptr, spec, fmt);
case 'I':
case 'i':
switch (fmt[1]) {
case '6':
return ip6_addr_string(buf, end, ptr, spec, fmt);
case '4':
return ip4_addr_string(buf, end, ptr, spec, fmt);
case 'S': {
const union {
struct sockaddr raw;
struct sockaddr_in v4;
struct sockaddr_in6 v6;
} *sa = ptr;
switch (sa->raw.sa_family) {
case AF_INET:
return ip4_addr_string_sa(buf, end, &sa->v4, spec, fmt);
case AF_INET6:
return ip6_addr_string_sa(buf, end, &sa->v6, spec, fmt);
default:
return string(buf, end, "(invalid address)", spec);
}}
}
break;
case 'U':
return uuid_string(buf, end, ptr, spec, fmt);
case 'V':
{
va_list va;
va_copy(va, *((struct va_format *)ptr)->va);
buf += vsnprintf(buf, end > buf ? end - buf : 0,
((struct va_format *)ptr)->fmt, va);
va_end(va);
return buf;
}
case 'K':
if (kptr_restrict && (in_irq() || in_serving_softirq() ||
in_nmi())) {
if (spec.field_width == -1)
spec.field_width = default_width;
return string(buf, end, "pK-error", spec);
}
switch (kptr_restrict) {
case 0:
break;
case 1: {
const struct cred *cred = current_cred();
if (!has_capability_noaudit(current, CAP_SYSLOG) ||
!uid_eq(cred->euid, cred->uid) ||
!gid_eq(cred->egid, cred->gid))
ptr = NULL;
break;
}
case 2:
default:
ptr = NULL;
break;
}
break;
case 'N':
switch (fmt[1]) {
case 'F':
return netdev_feature_string(buf, end, ptr, spec);
}
break;
case 'a':
return address_val(buf, end, ptr, spec, fmt);
case 'd':
return dentry_name(buf, end, ptr, spec, fmt);
case 'D':
return dentry_name(buf, end,
((const struct file *)ptr)->f_path.dentry,
spec, fmt);
}
spec.flags |= SMALL;
if (spec.field_width == -1) {
spec.field_width = default_width;
spec.flags |= ZEROPAD;
}
spec.base = 16;
return number(buf, end, (unsigned long) ptr, spec);
}
static noinline_for_stack
int format_decode(const char *fmt, struct printf_spec *spec)
{
const char *start = fmt;
if (spec->type == FORMAT_TYPE_WIDTH) {
if (spec->field_width < 0) {
spec->field_width = -spec->field_width;
spec->flags |= LEFT;
}
spec->type = FORMAT_TYPE_NONE;
goto precision;
}
if (spec->type == FORMAT_TYPE_PRECISION) {
if (spec->precision < 0)
spec->precision = 0;
spec->type = FORMAT_TYPE_NONE;
goto qualifier;
}
spec->type = FORMAT_TYPE_NONE;
for (; *fmt ; ++fmt) {
if (*fmt == '%')
break;
}
if (fmt != start || !*fmt)
return fmt - start;
spec->flags = 0;
while (1) {
bool found = true;
++fmt;
switch (*fmt) {
case '-': spec->flags |= LEFT; break;
case '+': spec->flags |= PLUS; break;
case ' ': spec->flags |= SPACE; break;
case '#': spec->flags |= SPECIAL; break;
case '0': spec->flags |= ZEROPAD; break;
default: found = false;
}
if (!found)
break;
}
spec->field_width = -1;
if (isdigit(*fmt))
spec->field_width = skip_atoi(&fmt);
else if (*fmt == '*') {
spec->type = FORMAT_TYPE_WIDTH;
return ++fmt - start;
}
precision:
spec->precision = -1;
if (*fmt == '.') {
++fmt;
if (isdigit(*fmt)) {
spec->precision = skip_atoi(&fmt);
if (spec->precision < 0)
spec->precision = 0;
} else if (*fmt == '*') {
spec->type = FORMAT_TYPE_PRECISION;
return ++fmt - start;
}
}
qualifier:
spec->qualifier = -1;
if (*fmt == 'h' || _tolower(*fmt) == 'l' ||
_tolower(*fmt) == 'z' || *fmt == 't') {
spec->qualifier = *fmt++;
if (unlikely(spec->qualifier == *fmt)) {
if (spec->qualifier == 'l') {
spec->qualifier = 'L';
++fmt;
} else if (spec->qualifier == 'h') {
spec->qualifier = 'H';
++fmt;
}
}
}
spec->base = 10;
switch (*fmt) {
case 'c':
spec->type = FORMAT_TYPE_CHAR;
return ++fmt - start;
case 's':
spec->type = FORMAT_TYPE_STR;
return ++fmt - start;
case 'p':
spec->type = FORMAT_TYPE_PTR;
return fmt - start;
case '%':
spec->type = FORMAT_TYPE_PERCENT_CHAR;
return ++fmt - start;
case 'o':
spec->base = 8;
break;
case 'x':
spec->flags |= SMALL;
case 'X':
spec->base = 16;
break;
case 'd':
case 'i':
spec->flags |= SIGN;
case 'u':
break;
case 'n':
WARN_ONCE(1, "Please remove ignored %%n in '%s'\n", fmt);
default:
spec->type = FORMAT_TYPE_INVALID;
return fmt - start;
}
if (spec->qualifier == 'L')
spec->type = FORMAT_TYPE_LONG_LONG;
else if (spec->qualifier == 'l') {
if (spec->flags & SIGN)
spec->type = FORMAT_TYPE_LONG;
else
spec->type = FORMAT_TYPE_ULONG;
} else if (_tolower(spec->qualifier) == 'z') {
spec->type = FORMAT_TYPE_SIZE_T;
} else if (spec->qualifier == 't') {
spec->type = FORMAT_TYPE_PTRDIFF;
} else if (spec->qualifier == 'H') {
if (spec->flags & SIGN)
spec->type = FORMAT_TYPE_BYTE;
else
spec->type = FORMAT_TYPE_UBYTE;
} else if (spec->qualifier == 'h') {
if (spec->flags & SIGN)
spec->type = FORMAT_TYPE_SHORT;
else
spec->type = FORMAT_TYPE_USHORT;
} else {
if (spec->flags & SIGN)
spec->type = FORMAT_TYPE_INT;
else
spec->type = FORMAT_TYPE_UINT;
}
return ++fmt - start;
}
int vsnprintf(char *buf, size_t size, const char *fmt, va_list args)
{
unsigned long long num;
char *str, *end;
struct printf_spec spec = {0};
if (WARN_ON_ONCE((int) size < 0))
return 0;
str = buf;
end = buf + size;
if (end < buf) {
end = ((void *)-1);
size = end - buf;
}
while (*fmt) {
const char *old_fmt = fmt;
int read = format_decode(fmt, &spec);
fmt += read;
switch (spec.type) {
case FORMAT_TYPE_NONE: {
int copy = read;
if (str < end) {
if (copy > end - str)
copy = end - str;
memcpy(str, old_fmt, copy);
}
str += read;
break;
}
case FORMAT_TYPE_WIDTH:
spec.field_width = va_arg(args, int);
break;
case FORMAT_TYPE_PRECISION:
spec.precision = va_arg(args, int);
break;
case FORMAT_TYPE_CHAR: {
char c;
if (!(spec.flags & LEFT)) {
while (--spec.field_width > 0) {
if (str < end)
*str = ' ';
++str;
}
}
c = (unsigned char) va_arg(args, int);
if (str < end)
*str = c;
++str;
while (--spec.field_width > 0) {
if (str < end)
*str = ' ';
++str;
}
break;
}
case FORMAT_TYPE_STR:
str = string(str, end, va_arg(args, char *), spec);
break;
case FORMAT_TYPE_PTR:
str = pointer(fmt+1, str, end, va_arg(args, void *),
spec);
while (isalnum(*fmt))
fmt++;
break;
case FORMAT_TYPE_PERCENT_CHAR:
if (str < end)
*str = '%';
++str;
break;
case FORMAT_TYPE_INVALID:
if (str < end)
*str = '%';
++str;
break;
default:
switch (spec.type) {
case FORMAT_TYPE_LONG_LONG:
num = va_arg(args, long long);
break;
case FORMAT_TYPE_ULONG:
num = va_arg(args, unsigned long);
break;
case FORMAT_TYPE_LONG:
num = va_arg(args, long);
break;
case FORMAT_TYPE_SIZE_T:
if (spec.flags & SIGN)
num = va_arg(args, ssize_t);
else
num = va_arg(args, size_t);
break;
case FORMAT_TYPE_PTRDIFF:
num = va_arg(args, ptrdiff_t);
break;
case FORMAT_TYPE_UBYTE:
num = (unsigned char) va_arg(args, int);
break;
case FORMAT_TYPE_BYTE:
num = (signed char) va_arg(args, int);
break;
case FORMAT_TYPE_USHORT:
num = (unsigned short) va_arg(args, int);
break;
case FORMAT_TYPE_SHORT:
num = (short) va_arg(args, int);
break;
case FORMAT_TYPE_INT:
num = (int) va_arg(args, int);
break;
default:
num = va_arg(args, unsigned int);
}
str = number(str, end, num, spec);
}
}
if (size > 0) {
if (str < end)
*str = '\0';
else
end[-1] = '\0';
}
return str-buf;
}
int vscnprintf(char *buf, size_t size, const char *fmt, va_list args)
{
int i;
i = vsnprintf(buf, size, fmt, args);
if (likely(i < size))
return i;
if (size != 0)
return size - 1;
return 0;
}
int snprintf(char *buf, size_t size, const char *fmt, ...)
{
va_list args;
int i;
va_start(args, fmt);
i = vsnprintf(buf, size, fmt, args);
va_end(args);
return i;
}
int scnprintf(char *buf, size_t size, const char *fmt, ...)
{
va_list args;
int i;
va_start(args, fmt);
i = vscnprintf(buf, size, fmt, args);
va_end(args);
return i;
}
int vsprintf(char *buf, const char *fmt, va_list args)
{
return vsnprintf(buf, INT_MAX, fmt, args);
}
int sprintf(char *buf, const char *fmt, ...)
{
va_list args;
int i;
va_start(args, fmt);
i = vsnprintf(buf, INT_MAX, fmt, args);
va_end(args);
return i;
}
int vbin_printf(u32 *bin_buf, size_t size, const char *fmt, va_list args)
{
struct printf_spec spec = {0};
char *str, *end;
str = (char *)bin_buf;
end = (char *)(bin_buf + size);
#define save_arg(type) \
do { \
if (sizeof(type) == 8) { \
unsigned long long value; \
str = PTR_ALIGN(str, sizeof(u32)); \
value = va_arg(args, unsigned long long); \
if (str + sizeof(type) <= end) { \
*(u32 *)str = *(u32 *)&value; \
*(u32 *)(str + 4) = *((u32 *)&value + 1); \
} \
} else { \
unsigned long value; \
str = PTR_ALIGN(str, sizeof(type)); \
value = va_arg(args, int); \
if (str + sizeof(type) <= end) \
*(typeof(type) *)str = (type)value; \
} \
str += sizeof(type); \
} while (0)
while (*fmt) {
int read = format_decode(fmt, &spec);
fmt += read;
switch (spec.type) {
case FORMAT_TYPE_NONE:
case FORMAT_TYPE_INVALID:
case FORMAT_TYPE_PERCENT_CHAR:
break;
case FORMAT_TYPE_WIDTH:
case FORMAT_TYPE_PRECISION:
save_arg(int);
break;
case FORMAT_TYPE_CHAR:
save_arg(char);
break;
case FORMAT_TYPE_STR: {
const char *save_str = va_arg(args, char *);
size_t len;
if ((unsigned long)save_str > (unsigned long)-PAGE_SIZE
|| (unsigned long)save_str < PAGE_SIZE)
save_str = "(null)";
len = strlen(save_str) + 1;
if (str + len < end)
memcpy(str, save_str, len);
str += len;
break;
}
case FORMAT_TYPE_PTR:
save_arg(void *);
while (isalnum(*fmt))
fmt++;
break;
default:
switch (spec.type) {
case FORMAT_TYPE_LONG_LONG:
save_arg(long long);
break;
case FORMAT_TYPE_ULONG:
case FORMAT_TYPE_LONG:
save_arg(unsigned long);
break;
case FORMAT_TYPE_SIZE_T:
save_arg(size_t);
break;
case FORMAT_TYPE_PTRDIFF:
save_arg(ptrdiff_t);
break;
case FORMAT_TYPE_UBYTE:
case FORMAT_TYPE_BYTE:
save_arg(char);
break;
case FORMAT_TYPE_USHORT:
case FORMAT_TYPE_SHORT:
save_arg(short);
break;
default:
save_arg(int);
}
}
}
return (u32 *)(PTR_ALIGN(str, sizeof(u32))) - bin_buf;
#undef save_arg
}
int bstr_printf(char *buf, size_t size, const char *fmt, const u32 *bin_buf)
{
struct printf_spec spec = {0};
char *str, *end;
const char *args = (const char *)bin_buf;
if (WARN_ON_ONCE((int) size < 0))
return 0;
str = buf;
end = buf + size;
#define get_arg(type) \
({ \
typeof(type) value; \
if (sizeof(type) == 8) { \
args = PTR_ALIGN(args, sizeof(u32)); \
*(u32 *)&value = *(u32 *)args; \
*((u32 *)&value + 1) = *(u32 *)(args + 4); \
} else { \
args = PTR_ALIGN(args, sizeof(type)); \
value = *(typeof(type) *)args; \
} \
args += sizeof(type); \
value; \
})
if (end < buf) {
end = ((void *)-1);
size = end - buf;
}
while (*fmt) {
const char *old_fmt = fmt;
int read = format_decode(fmt, &spec);
fmt += read;
switch (spec.type) {
case FORMAT_TYPE_NONE: {
int copy = read;
if (str < end) {
if (copy > end - str)
copy = end - str;
memcpy(str, old_fmt, copy);
}
str += read;
break;
}
case FORMAT_TYPE_WIDTH:
spec.field_width = get_arg(int);
break;
case FORMAT_TYPE_PRECISION:
spec.precision = get_arg(int);
break;
case FORMAT_TYPE_CHAR: {
char c;
if (!(spec.flags & LEFT)) {
while (--spec.field_width > 0) {
if (str < end)
*str = ' ';
++str;
}
}
c = (unsigned char) get_arg(char);
if (str < end)
*str = c;
++str;
while (--spec.field_width > 0) {
if (str < end)
*str = ' ';
++str;
}
break;
}
case FORMAT_TYPE_STR: {
const char *str_arg = args;
args += strlen(str_arg) + 1;
str = string(str, end, (char *)str_arg, spec);
break;
}
case FORMAT_TYPE_PTR:
str = pointer(fmt+1, str, end, get_arg(void *), spec);
while (isalnum(*fmt))
fmt++;
break;
case FORMAT_TYPE_PERCENT_CHAR:
case FORMAT_TYPE_INVALID:
if (str < end)
*str = '%';
++str;
break;
default: {
unsigned long long num;
switch (spec.type) {
case FORMAT_TYPE_LONG_LONG:
num = get_arg(long long);
break;
case FORMAT_TYPE_ULONG:
case FORMAT_TYPE_LONG:
num = get_arg(unsigned long);
break;
case FORMAT_TYPE_SIZE_T:
num = get_arg(size_t);
break;
case FORMAT_TYPE_PTRDIFF:
num = get_arg(ptrdiff_t);
break;
case FORMAT_TYPE_UBYTE:
num = get_arg(unsigned char);
break;
case FORMAT_TYPE_BYTE:
num = get_arg(signed char);
break;
case FORMAT_TYPE_USHORT:
num = get_arg(unsigned short);
break;
case FORMAT_TYPE_SHORT:
num = get_arg(short);
break;
case FORMAT_TYPE_UINT:
num = get_arg(unsigned int);
break;
default:
num = get_arg(int);
}
str = number(str, end, num, spec);
}
}
}
if (size > 0) {
if (str < end)
*str = '\0';
else
end[-1] = '\0';
}
#undef get_arg
return str - buf;
}
int bprintf(u32 *bin_buf, size_t size, const char *fmt, ...)
{
va_list args;
int ret;
va_start(args, fmt);
ret = vbin_printf(bin_buf, size, fmt, args);
va_end(args);
return ret;
}
int vsscanf(const char *buf, const char *fmt, va_list args)
{
const char *str = buf;
char *next;
char digit;
int num = 0;
u8 qualifier;
unsigned int base;
union {
long long s;
unsigned long long u;
} val;
s16 field_width;
bool is_sign;
while (*fmt) {
if (isspace(*fmt)) {
fmt = skip_spaces(++fmt);
str = skip_spaces(str);
}
if (*fmt != '%' && *fmt) {
if (*fmt++ != *str++)
break;
continue;
}
if (!*fmt)
break;
++fmt;
if (*fmt == '*') {
if (!*str)
break;
while (!isspace(*fmt) && *fmt != '%' && *fmt)
fmt++;
while (!isspace(*str) && *str)
str++;
continue;
}
field_width = -1;
if (isdigit(*fmt)) {
field_width = skip_atoi(&fmt);
if (field_width <= 0)
break;
}
qualifier = -1;
if (*fmt == 'h' || _tolower(*fmt) == 'l' ||
_tolower(*fmt) == 'z') {
qualifier = *fmt++;
if (unlikely(qualifier == *fmt)) {
if (qualifier == 'h') {
qualifier = 'H';
fmt++;
} else if (qualifier == 'l') {
qualifier = 'L';
fmt++;
}
}
}
if (!*fmt)
break;
if (*fmt == 'n') {
*va_arg(args, int *) = str - buf;
++fmt;
continue;
}
if (!*str)
break;
base = 10;
is_sign = false;
switch (*fmt++) {
case 'c':
{
char *s = (char *)va_arg(args, char*);
if (field_width == -1)
field_width = 1;
do {
*s++ = *str++;
} while (--field_width > 0 && *str);
num++;
}
continue;
case 's':
{
char *s = (char *)va_arg(args, char *);
if (field_width == -1)
field_width = SHRT_MAX;
str = skip_spaces(str);
while (*str && !isspace(*str) && field_width--)
*s++ = *str++;
*s = '\0';
num++;
}
continue;
case 'o':
base = 8;
break;
case 'x':
case 'X':
base = 16;
break;
case 'i':
base = 0;
case 'd':
is_sign = true;
case 'u':
break;
case '%':
if (*str++ != '%')
return num;
continue;
default:
return num;
}
str = skip_spaces(str);
digit = *str;
if (is_sign && digit == '-')
digit = *(str + 1);
if (!digit
|| (base == 16 && !isxdigit(digit))
|| (base == 10 && !isdigit(digit))
|| (base == 8 && (!isdigit(digit) || digit > '7'))
|| (base == 0 && !isdigit(digit)))
break;
if (is_sign)
val.s = qualifier != 'L' ?
simple_strtol(str, &next, base) :
simple_strtoll(str, &next, base);
else
val.u = qualifier != 'L' ?
simple_strtoul(str, &next, base) :
simple_strtoull(str, &next, base);
if (field_width > 0 && next - str > field_width) {
if (base == 0)
_parse_integer_fixup_radix(str, &base);
while (next - str > field_width) {
if (is_sign)
val.s = div_s64(val.s, base);
else
val.u = div_u64(val.u, base);
--next;
}
}
switch (qualifier) {
case 'H':
if (is_sign)
*va_arg(args, signed char *) = val.s;
else
*va_arg(args, unsigned char *) = val.u;
break;
case 'h':
if (is_sign)
*va_arg(args, short *) = val.s;
else
*va_arg(args, unsigned short *) = val.u;
break;
case 'l':
if (is_sign)
*va_arg(args, long *) = val.s;
else
*va_arg(args, unsigned long *) = val.u;
break;
case 'L':
if (is_sign)
*va_arg(args, long long *) = val.s;
else
*va_arg(args, unsigned long long *) = val.u;
break;
case 'Z':
case 'z':
*va_arg(args, size_t *) = val.u;
break;
default:
if (is_sign)
*va_arg(args, int *) = val.s;
else
*va_arg(args, unsigned int *) = val.u;
break;
}
num++;
if (!next)
break;
str = next;
}
return num;
}
int sscanf(const char *buf, const char *fmt, ...)
{
va_list args;
int i;
va_start(args, fmt);
i = vsscanf(buf, fmt, args);
va_end(args);
return i;
}
