static inline bool
hash_ipportnet4_data_equal(const struct hash_ipportnet4_elem *ip1,
const struct hash_ipportnet4_elem *ip2,
u32 *multi)
{
return ip1->ip == ip2->ip &&
ip1->ip2 == ip2->ip2 &&
ip1->cidr == ip2->cidr &&
ip1->port == ip2->port &&
ip1->proto == ip2->proto;
}
static inline int
hash_ipportnet4_do_data_match(const struct hash_ipportnet4_elem *elem)
{
return elem->nomatch ? -ENOTEMPTY : 1;
}
static inline void
hash_ipportnet4_data_set_flags(struct hash_ipportnet4_elem *elem, u32 flags)
{
elem->nomatch = !!((flags >> 16) & IPSET_FLAG_NOMATCH);
}
static inline void
hash_ipportnet4_data_reset_flags(struct hash_ipportnet4_elem *elem, u8 *flags)
{
swap(*flags, elem->nomatch);
}
static inline void
hash_ipportnet4_data_netmask(struct hash_ipportnet4_elem *elem, u8 cidr)
{
elem->ip2 &= ip_set_netmask(cidr);
elem->cidr = cidr - 1;
}
static bool
hash_ipportnet4_data_list(struct sk_buff *skb,
const struct hash_ipportnet4_elem *data)
{
u32 flags = data->nomatch ? IPSET_FLAG_NOMATCH : 0;
if (nla_put_ipaddr4(skb, IPSET_ATTR_IP, data->ip) ||
nla_put_ipaddr4(skb, IPSET_ATTR_IP2, data->ip2) ||
nla_put_net16(skb, IPSET_ATTR_PORT, data->port) ||
nla_put_u8(skb, IPSET_ATTR_CIDR2, data->cidr + 1) ||
nla_put_u8(skb, IPSET_ATTR_PROTO, data->proto) ||
(flags &&
nla_put_net32(skb, IPSET_ATTR_CADT_FLAGS, htonl(flags))))
goto nla_put_failure;
return 0;
nla_put_failure:
return 1;
}
static inline void
hash_ipportnet4_data_next(struct hash_ipportnet4_elem *next,
const struct hash_ipportnet4_elem *d)
{
next->ip = d->ip;
next->port = d->port;
next->ip2 = d->ip2;
}
static int
hash_ipportnet4_kadt(struct ip_set *set, const struct sk_buff *skb,
const struct xt_action_param *par,
enum ipset_adt adt, struct ip_set_adt_opt *opt)
{
const struct hash_ipportnet *h = set->data;
ipset_adtfn adtfn = set->variant->adt[adt];
struct hash_ipportnet4_elem e = {
.cidr = h->nets[0].cidr ? h->nets[0].cidr - 1 : HOST_MASK - 1
};
struct ip_set_ext ext = IP_SET_INIT_KEXT(skb, opt, h);
if (adt == IPSET_TEST)
e.cidr = HOST_MASK - 1;
if (!ip_set_get_ip4_port(skb, opt->flags & IPSET_DIM_TWO_SRC,
&e.port, &e.proto))
return -EINVAL;
ip4addrptr(skb, opt->flags & IPSET_DIM_ONE_SRC, &e.ip);
ip4addrptr(skb, opt->flags & IPSET_DIM_THREE_SRC, &e.ip2);
e.ip2 &= ip_set_netmask(e.cidr + 1);
return adtfn(set, &e, &ext, &opt->ext, opt->cmdflags);
}
static int
hash_ipportnet4_uadt(struct ip_set *set, struct nlattr *tb[],
enum ipset_adt adt, u32 *lineno, u32 flags, bool retried)
{
const struct hash_ipportnet *h = set->data;
ipset_adtfn adtfn = set->variant->adt[adt];
struct hash_ipportnet4_elem e = { .cidr = HOST_MASK - 1 };
struct ip_set_ext ext = IP_SET_INIT_UEXT(h);
u32 ip, ip_to, p = 0, port, port_to;
u32 ip2_from, ip2_to, ip2_last, ip2;
bool with_ports = false;
u8 cidr;
int ret;
if (unlikely(!tb[IPSET_ATTR_IP] || !tb[IPSET_ATTR_IP2] ||
!ip_set_attr_netorder(tb, IPSET_ATTR_PORT) ||
!ip_set_optattr_netorder(tb, IPSET_ATTR_PORT_TO) ||
!ip_set_optattr_netorder(tb, IPSET_ATTR_TIMEOUT) ||
!ip_set_optattr_netorder(tb, IPSET_ATTR_CADT_FLAGS) ||
!ip_set_optattr_netorder(tb, IPSET_ATTR_PACKETS) ||
!ip_set_optattr_netorder(tb, IPSET_ATTR_BYTES)))
return -IPSET_ERR_PROTOCOL;
if (tb[IPSET_ATTR_LINENO])
*lineno = nla_get_u32(tb[IPSET_ATTR_LINENO]);
ret = ip_set_get_hostipaddr4(tb[IPSET_ATTR_IP], &ip) ||
ip_set_get_extensions(set, tb, &ext);
if (ret)
return ret;
ret = ip_set_get_hostipaddr4(tb[IPSET_ATTR_IP2], &ip2_from);
if (ret)
return ret;
if (tb[IPSET_ATTR_CIDR2]) {
cidr = nla_get_u8(tb[IPSET_ATTR_CIDR2]);
if (!cidr || cidr > HOST_MASK)
return -IPSET_ERR_INVALID_CIDR;
e.cidr = cidr - 1;
}
if (tb[IPSET_ATTR_PORT])
e.port = nla_get_be16(tb[IPSET_ATTR_PORT]);
else
return -IPSET_ERR_PROTOCOL;
if (tb[IPSET_ATTR_PROTO]) {
e.proto = nla_get_u8(tb[IPSET_ATTR_PROTO]);
with_ports = ip_set_proto_with_ports(e.proto);
if (e.proto == 0)
return -IPSET_ERR_INVALID_PROTO;
} else
return -IPSET_ERR_MISSING_PROTO;
if (!(with_ports || e.proto == IPPROTO_ICMP))
e.port = 0;
if (tb[IPSET_ATTR_CADT_FLAGS]) {
u32 cadt_flags = ip_set_get_h32(tb[IPSET_ATTR_CADT_FLAGS]);
if (cadt_flags & IPSET_FLAG_NOMATCH)
flags |= (IPSET_FLAG_NOMATCH << 16);
}
with_ports = with_ports && tb[IPSET_ATTR_PORT_TO];
if (adt == IPSET_TEST ||
!(tb[IPSET_ATTR_CIDR] || tb[IPSET_ATTR_IP_TO] || with_ports ||
tb[IPSET_ATTR_IP2_TO])) {
e.ip = htonl(ip);
e.ip2 = htonl(ip2_from & ip_set_hostmask(e.cidr + 1));
ret = adtfn(set, &e, &ext, &ext, flags);
return ip_set_enomatch(ret, flags, adt) ? 1 :
ip_set_eexist(ret, flags) ? 0 : ret;
}
ip_to = ip;
if (tb[IPSET_ATTR_IP_TO]) {
ret = ip_set_get_hostipaddr4(tb[IPSET_ATTR_IP_TO], &ip_to);
if (ret)
return ret;
if (ip > ip_to)
swap(ip, ip_to);
} else if (tb[IPSET_ATTR_CIDR]) {
u8 cidr = nla_get_u8(tb[IPSET_ATTR_CIDR]);
if (!cidr || cidr > 32)
return -IPSET_ERR_INVALID_CIDR;
ip_set_mask_from_to(ip, ip_to, cidr);
}
port_to = port = ntohs(e.port);
if (tb[IPSET_ATTR_PORT_TO]) {
port_to = ip_set_get_h16(tb[IPSET_ATTR_PORT_TO]);
if (port > port_to)
swap(port, port_to);
}
ip2_to = ip2_from;
if (tb[IPSET_ATTR_IP2_TO]) {
ret = ip_set_get_hostipaddr4(tb[IPSET_ATTR_IP2_TO], &ip2_to);
if (ret)
return ret;
if (ip2_from > ip2_to)
swap(ip2_from, ip2_to);
if (ip2_from + UINT_MAX == ip2_to)
return -IPSET_ERR_HASH_RANGE;
} else
ip_set_mask_from_to(ip2_from, ip2_to, e.cidr + 1);
if (retried)
ip = ntohl(h->next.ip);
for (; !before(ip_to, ip); ip++) {
e.ip = htonl(ip);
p = retried && ip == ntohl(h->next.ip) ? ntohs(h->next.port)
: port;
for (; p <= port_to; p++) {
e.port = htons(p);
ip2 = retried
&& ip == ntohl(h->next.ip)
&& p == ntohs(h->next.port)
? ntohl(h->next.ip2) : ip2_from;
while (!after(ip2, ip2_to)) {
e.ip2 = htonl(ip2);
ip2_last = ip_set_range_to_cidr(ip2, ip2_to,
&cidr);
e.cidr = cidr - 1;
ret = adtfn(set, &e, &ext, &ext, flags);
if (ret && !ip_set_eexist(ret, flags))
return ret;
else
ret = 0;
ip2 = ip2_last + 1;
}
}
}
return ret;
}
static inline bool
hash_ipportnet6_data_equal(const struct hash_ipportnet6_elem *ip1,
const struct hash_ipportnet6_elem *ip2,
u32 *multi)
{
return ipv6_addr_equal(&ip1->ip.in6, &ip2->ip.in6) &&
ipv6_addr_equal(&ip1->ip2.in6, &ip2->ip2.in6) &&
ip1->cidr == ip2->cidr &&
ip1->port == ip2->port &&
ip1->proto == ip2->proto;
}
static inline int
hash_ipportnet6_do_data_match(const struct hash_ipportnet6_elem *elem)
{
return elem->nomatch ? -ENOTEMPTY : 1;
}
static inline void
hash_ipportnet6_data_set_flags(struct hash_ipportnet6_elem *elem, u32 flags)
{
elem->nomatch = !!((flags >> 16) & IPSET_FLAG_NOMATCH);
}
static inline void
hash_ipportnet6_data_reset_flags(struct hash_ipportnet6_elem *elem, u8 *flags)
{
swap(*flags, elem->nomatch);
}
static inline void
hash_ipportnet6_data_netmask(struct hash_ipportnet6_elem *elem, u8 cidr)
{
ip6_netmask(&elem->ip2, cidr);
elem->cidr = cidr - 1;
}
static bool
hash_ipportnet6_data_list(struct sk_buff *skb,
const struct hash_ipportnet6_elem *data)
{
u32 flags = data->nomatch ? IPSET_FLAG_NOMATCH : 0;
if (nla_put_ipaddr6(skb, IPSET_ATTR_IP, &data->ip.in6) ||
nla_put_ipaddr6(skb, IPSET_ATTR_IP2, &data->ip2.in6) ||
nla_put_net16(skb, IPSET_ATTR_PORT, data->port) ||
nla_put_u8(skb, IPSET_ATTR_CIDR2, data->cidr + 1) ||
nla_put_u8(skb, IPSET_ATTR_PROTO, data->proto) ||
(flags &&
nla_put_net32(skb, IPSET_ATTR_CADT_FLAGS, htonl(flags))))
goto nla_put_failure;
return 0;
nla_put_failure:
return 1;
}
static inline void
hash_ipportnet6_data_next(struct hash_ipportnet4_elem *next,
const struct hash_ipportnet6_elem *d)
{
next->port = d->port;
}
static int
hash_ipportnet6_kadt(struct ip_set *set, const struct sk_buff *skb,
const struct xt_action_param *par,
enum ipset_adt adt, struct ip_set_adt_opt *opt)
{
const struct hash_ipportnet *h = set->data;
ipset_adtfn adtfn = set->variant->adt[adt];
struct hash_ipportnet6_elem e = {
.cidr = h->nets[0].cidr ? h->nets[0].cidr - 1 : HOST_MASK - 1
};
struct ip_set_ext ext = IP_SET_INIT_KEXT(skb, opt, h);
if (adt == IPSET_TEST)
e.cidr = HOST_MASK - 1;
if (!ip_set_get_ip6_port(skb, opt->flags & IPSET_DIM_TWO_SRC,
&e.port, &e.proto))
return -EINVAL;
ip6addrptr(skb, opt->flags & IPSET_DIM_ONE_SRC, &e.ip.in6);
ip6addrptr(skb, opt->flags & IPSET_DIM_THREE_SRC, &e.ip2.in6);
ip6_netmask(&e.ip2, e.cidr + 1);
return adtfn(set, &e, &ext, &opt->ext, opt->cmdflags);
}
static int
hash_ipportnet6_uadt(struct ip_set *set, struct nlattr *tb[],
enum ipset_adt adt, u32 *lineno, u32 flags, bool retried)
{
const struct hash_ipportnet *h = set->data;
ipset_adtfn adtfn = set->variant->adt[adt];
struct hash_ipportnet6_elem e = { .cidr = HOST_MASK - 1 };
struct ip_set_ext ext = IP_SET_INIT_UEXT(h);
u32 port, port_to;
bool with_ports = false;
u8 cidr;
int ret;
if (unlikely(!tb[IPSET_ATTR_IP] || !tb[IPSET_ATTR_IP2] ||
!ip_set_attr_netorder(tb, IPSET_ATTR_PORT) ||
!ip_set_optattr_netorder(tb, IPSET_ATTR_PORT_TO) ||
!ip_set_optattr_netorder(tb, IPSET_ATTR_TIMEOUT) ||
!ip_set_optattr_netorder(tb, IPSET_ATTR_CADT_FLAGS) ||
!ip_set_optattr_netorder(tb, IPSET_ATTR_PACKETS) ||
!ip_set_optattr_netorder(tb, IPSET_ATTR_BYTES) ||
tb[IPSET_ATTR_IP_TO] ||
tb[IPSET_ATTR_CIDR]))
return -IPSET_ERR_PROTOCOL;
if (unlikely(tb[IPSET_ATTR_IP_TO]))
return -IPSET_ERR_HASH_RANGE_UNSUPPORTED;
if (tb[IPSET_ATTR_LINENO])
*lineno = nla_get_u32(tb[IPSET_ATTR_LINENO]);
ret = ip_set_get_ipaddr6(tb[IPSET_ATTR_IP], &e.ip) ||
ip_set_get_extensions(set, tb, &ext);
if (ret)
return ret;
ret = ip_set_get_ipaddr6(tb[IPSET_ATTR_IP2], &e.ip2);
if (ret)
return ret;
if (tb[IPSET_ATTR_CIDR2]) {
cidr = nla_get_u8(tb[IPSET_ATTR_CIDR2]);
if (!cidr || cidr > HOST_MASK)
return -IPSET_ERR_INVALID_CIDR;
e.cidr = cidr - 1;
}
ip6_netmask(&e.ip2, e.cidr + 1);
if (tb[IPSET_ATTR_PORT])
e.port = nla_get_be16(tb[IPSET_ATTR_PORT]);
else
return -IPSET_ERR_PROTOCOL;
if (tb[IPSET_ATTR_PROTO]) {
e.proto = nla_get_u8(tb[IPSET_ATTR_PROTO]);
with_ports = ip_set_proto_with_ports(e.proto);
if (e.proto == 0)
return -IPSET_ERR_INVALID_PROTO;
} else
return -IPSET_ERR_MISSING_PROTO;
if (!(with_ports || e.proto == IPPROTO_ICMPV6))
e.port = 0;
if (tb[IPSET_ATTR_CADT_FLAGS]) {
u32 cadt_flags = ip_set_get_h32(tb[IPSET_ATTR_CADT_FLAGS]);
if (cadt_flags & IPSET_FLAG_NOMATCH)
flags |= (IPSET_FLAG_NOMATCH << 16);
}
if (adt == IPSET_TEST || !with_ports || !tb[IPSET_ATTR_PORT_TO]) {
ret = adtfn(set, &e, &ext, &ext, flags);
return ip_set_enomatch(ret, flags, adt) ? 1 :
ip_set_eexist(ret, flags) ? 0 : ret;
}
port = ntohs(e.port);
port_to = ip_set_get_h16(tb[IPSET_ATTR_PORT_TO]);
if (port > port_to)
swap(port, port_to);
if (retried)
port = ntohs(h->next.port);
for (; port <= port_to; port++) {
e.port = htons(port);
ret = adtfn(set, &e, &ext, &ext, flags);
if (ret && !ip_set_eexist(ret, flags))
return ret;
else
ret = 0;
}
return ret;
}
static int __init
hash_ipportnet_init(void)
{
return ip_set_type_register(&hash_ipportnet_type);
}
static void __exit
hash_ipportnet_fini(void)
{
ip_set_type_unregister(&hash_ipportnet_type);
}
