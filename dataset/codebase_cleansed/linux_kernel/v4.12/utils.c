int net_ratelimit(void)
{
return __ratelimit(&net_ratelimit_state);
}
__be32 in_aton(const char *str)
{
unsigned int l;
unsigned int val;
int i;
l = 0;
for (i = 0; i < 4; i++) {
l <<= 8;
if (*str != '\0') {
val = 0;
while (*str != '\0' && *str != '.' && *str != '\n') {
val *= 10;
val += *str - '0';
str++;
}
l |= val;
if (*str != '\0')
str++;
}
}
return htonl(l);
}
static inline int xdigit2bin(char c, int delim)
{
int val;
if (c == delim || c == '\0')
return IN6PTON_DELIM;
if (c == ':')
return IN6PTON_COLON_MASK;
if (c == '.')
return IN6PTON_DOT;
val = hex_to_bin(c);
if (val >= 0)
return val | IN6PTON_XDIGIT | (val < 10 ? IN6PTON_DIGIT : 0);
if (delim == -1)
return IN6PTON_DELIM;
return IN6PTON_UNKNOWN;
}
int in4_pton(const char *src, int srclen,
u8 *dst,
int delim, const char **end)
{
const char *s;
u8 *d;
u8 dbuf[4];
int ret = 0;
int i;
int w = 0;
if (srclen < 0)
srclen = strlen(src);
s = src;
d = dbuf;
i = 0;
while (1) {
int c;
c = xdigit2bin(srclen > 0 ? *s : '\0', delim);
if (!(c & (IN6PTON_DIGIT | IN6PTON_DOT | IN6PTON_DELIM | IN6PTON_COLON_MASK))) {
goto out;
}
if (c & (IN6PTON_DOT | IN6PTON_DELIM | IN6PTON_COLON_MASK)) {
if (w == 0)
goto out;
*d++ = w & 0xff;
w = 0;
i++;
if (c & (IN6PTON_DELIM | IN6PTON_COLON_MASK)) {
if (i != 4)
goto out;
break;
}
goto cont;
}
w = (w * 10) + c;
if ((w & 0xffff) > 255) {
goto out;
}
cont:
if (i >= 4)
goto out;
s++;
srclen--;
}
ret = 1;
memcpy(dst, dbuf, sizeof(dbuf));
out:
if (end)
*end = s;
return ret;
}
int in6_pton(const char *src, int srclen,
u8 *dst,
int delim, const char **end)
{
const char *s, *tok = NULL;
u8 *d, *dc = NULL;
u8 dbuf[16];
int ret = 0;
int i;
int state = IN6PTON_COLON_1_2 | IN6PTON_XDIGIT | IN6PTON_NULL;
int w = 0;
memset(dbuf, 0, sizeof(dbuf));
s = src;
d = dbuf;
if (srclen < 0)
srclen = strlen(src);
while (1) {
int c;
c = xdigit2bin(srclen > 0 ? *s : '\0', delim);
if (!(c & state))
goto out;
if (c & (IN6PTON_DELIM | IN6PTON_COLON_MASK)) {
if (!(state & IN6PTON_NULL)) {
*d++ = (w >> 8) & 0xff;
*d++ = w & 0xff;
}
w = 0;
if (c & IN6PTON_DELIM) {
break;
}
switch (state & IN6PTON_COLON_MASK) {
case IN6PTON_COLON_2:
dc = d;
state = IN6PTON_XDIGIT | IN6PTON_DELIM;
if (dc - dbuf >= sizeof(dbuf))
state |= IN6PTON_NULL;
break;
case IN6PTON_COLON_1|IN6PTON_COLON_1_2:
state = IN6PTON_XDIGIT | IN6PTON_COLON_2;
break;
case IN6PTON_COLON_1:
state = IN6PTON_XDIGIT;
break;
case IN6PTON_COLON_1_2:
state = IN6PTON_COLON_2;
break;
default:
state = 0;
}
tok = s + 1;
goto cont;
}
if (c & IN6PTON_DOT) {
ret = in4_pton(tok ? tok : s, srclen + (int)(s - tok), d, delim, &s);
if (ret > 0) {
d += 4;
break;
}
goto out;
}
w = (w << 4) | (0xff & c);
state = IN6PTON_COLON_1 | IN6PTON_DELIM;
if (!(w & 0xf000)) {
state |= IN6PTON_XDIGIT;
}
if (!dc && d + 2 < dbuf + sizeof(dbuf)) {
state |= IN6PTON_COLON_1_2;
state &= ~IN6PTON_DELIM;
}
if (d + 2 >= dbuf + sizeof(dbuf)) {
state &= ~(IN6PTON_COLON_1|IN6PTON_COLON_1_2);
}
cont:
if ((dc && d + 4 < dbuf + sizeof(dbuf)) ||
d + 4 == dbuf + sizeof(dbuf)) {
state |= IN6PTON_DOT;
}
if (d >= dbuf + sizeof(dbuf)) {
state &= ~(IN6PTON_XDIGIT|IN6PTON_COLON_MASK);
}
s++;
srclen--;
}
i = 15; d--;
if (dc) {
while (d >= dc)
dst[i--] = *d--;
while (i >= dc - dbuf)
dst[i--] = 0;
while (i >= 0)
dst[i--] = *d--;
} else
memcpy(dst, dbuf, sizeof(dbuf));
ret = 1;
out:
if (end)
*end = s;
return ret;
}
static int inet4_pton(const char *src, u16 port_num,
struct sockaddr_storage *addr)
{
struct sockaddr_in *addr4 = (struct sockaddr_in *)addr;
int srclen = strlen(src);
if (srclen > INET_ADDRSTRLEN)
return -EINVAL;
if (in4_pton(src, srclen, (u8 *)&addr4->sin_addr.s_addr,
'\n', NULL) == 0)
return -EINVAL;
addr4->sin_family = AF_INET;
addr4->sin_port = htons(port_num);
return 0;
}
static int inet6_pton(struct net *net, const char *src, u16 port_num,
struct sockaddr_storage *addr)
{
struct sockaddr_in6 *addr6 = (struct sockaddr_in6 *)addr;
const char *scope_delim;
int srclen = strlen(src);
if (srclen > INET6_ADDRSTRLEN)
return -EINVAL;
if (in6_pton(src, srclen, (u8 *)&addr6->sin6_addr.s6_addr,
'%', &scope_delim) == 0)
return -EINVAL;
if (ipv6_addr_type(&addr6->sin6_addr) & IPV6_ADDR_LINKLOCAL &&
src + srclen != scope_delim && *scope_delim == '%') {
struct net_device *dev;
char scope_id[16];
size_t scope_len = min_t(size_t, sizeof(scope_id) - 1,
src + srclen - scope_delim - 1);
memcpy(scope_id, scope_delim + 1, scope_len);
scope_id[scope_len] = '\0';
dev = dev_get_by_name(net, scope_id);
if (dev) {
addr6->sin6_scope_id = dev->ifindex;
dev_put(dev);
} else if (kstrtouint(scope_id, 0, &addr6->sin6_scope_id)) {
return -EINVAL;
}
}
addr6->sin6_family = AF_INET6;
addr6->sin6_port = htons(port_num);
return 0;
}
int inet_pton_with_scope(struct net *net, __kernel_sa_family_t af,
const char *src, const char *port, struct sockaddr_storage *addr)
{
u16 port_num;
int ret = -EINVAL;
if (port) {
if (kstrtou16(port, 0, &port_num))
return -EINVAL;
} else {
port_num = 0;
}
switch (af) {
case AF_INET:
ret = inet4_pton(src, port_num, addr);
break;
case AF_INET6:
ret = inet6_pton(net, src, port_num, addr);
break;
case AF_UNSPEC:
ret = inet4_pton(src, port_num, addr);
if (ret)
ret = inet6_pton(net, src, port_num, addr);
break;
default:
pr_err("unexpected address family %d\n", af);
};
return ret;
}
void inet_proto_csum_replace4(__sum16 *sum, struct sk_buff *skb,
__be32 from, __be32 to, bool pseudohdr)
{
if (skb->ip_summed != CHECKSUM_PARTIAL) {
csum_replace4(sum, from, to);
if (skb->ip_summed == CHECKSUM_COMPLETE && pseudohdr)
skb->csum = ~csum_add(csum_sub(~(skb->csum),
(__force __wsum)from),
(__force __wsum)to);
} else if (pseudohdr)
*sum = ~csum_fold(csum_add(csum_sub(csum_unfold(*sum),
(__force __wsum)from),
(__force __wsum)to));
}
void inet_proto_csum_replace16(__sum16 *sum, struct sk_buff *skb,
const __be32 *from, const __be32 *to,
bool pseudohdr)
{
__be32 diff[] = {
~from[0], ~from[1], ~from[2], ~from[3],
to[0], to[1], to[2], to[3],
};
if (skb->ip_summed != CHECKSUM_PARTIAL) {
*sum = csum_fold(csum_partial(diff, sizeof(diff),
~csum_unfold(*sum)));
if (skb->ip_summed == CHECKSUM_COMPLETE && pseudohdr)
skb->csum = ~csum_partial(diff, sizeof(diff),
~skb->csum);
} else if (pseudohdr)
*sum = ~csum_fold(csum_partial(diff, sizeof(diff),
csum_unfold(*sum)));
}
void inet_proto_csum_replace_by_diff(__sum16 *sum, struct sk_buff *skb,
__wsum diff, bool pseudohdr)
{
if (skb->ip_summed != CHECKSUM_PARTIAL) {
*sum = csum_fold(csum_add(diff, ~csum_unfold(*sum)));
if (skb->ip_summed == CHECKSUM_COMPLETE && pseudohdr)
skb->csum = ~csum_add(diff, ~skb->csum);
} else if (pseudohdr) {
*sum = ~csum_fold(csum_add(diff, csum_unfold(*sum)));
}
}
