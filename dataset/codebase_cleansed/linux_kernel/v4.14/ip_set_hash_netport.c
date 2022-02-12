static inline bool
hash_netport4_data_equal(const struct hash_netport4_elem *ip1,
const struct hash_netport4_elem *ip2,
u32 *multi)
{
return ip1->ip == ip2->ip &&
ip1->port == ip2->port &&
ip1->proto == ip2->proto &&
ip1->cidr == ip2->cidr;
}
static inline int
hash_netport4_do_data_match(const struct hash_netport4_elem *elem)
{
return elem->nomatch ? -ENOTEMPTY : 1;
}
static inline void
hash_netport4_data_set_flags(struct hash_netport4_elem *elem, u32 flags)
{
elem->nomatch = !!((flags >> 16) & IPSET_FLAG_NOMATCH);
}
static inline void
hash_netport4_data_reset_flags(struct hash_netport4_elem *elem, u8 *flags)
{
swap(*flags, elem->nomatch);
}
static inline void
hash_netport4_data_netmask(struct hash_netport4_elem *elem, u8 cidr)
{
elem->ip &= ip_set_netmask(cidr);
elem->cidr = cidr - 1;
}
static bool
hash_netport4_data_list(struct sk_buff *skb,
const struct hash_netport4_elem *data)
{
u32 flags = data->nomatch ? IPSET_FLAG_NOMATCH : 0;
if (nla_put_ipaddr4(skb, IPSET_ATTR_IP, data->ip) ||
nla_put_net16(skb, IPSET_ATTR_PORT, data->port) ||
nla_put_u8(skb, IPSET_ATTR_CIDR, data->cidr + 1) ||
nla_put_u8(skb, IPSET_ATTR_PROTO, data->proto) ||
(flags &&
nla_put_net32(skb, IPSET_ATTR_CADT_FLAGS, htonl(flags))))
goto nla_put_failure;
return false;
nla_put_failure:
return true;
}
static inline void
hash_netport4_data_next(struct hash_netport4_elem *next,
const struct hash_netport4_elem *d)
{
next->ip = d->ip;
next->port = d->port;
}
static int
hash_netport4_kadt(struct ip_set *set, const struct sk_buff *skb,
const struct xt_action_param *par,
enum ipset_adt adt, struct ip_set_adt_opt *opt)
{
const struct hash_netport4 *h = set->data;
ipset_adtfn adtfn = set->variant->adt[adt];
struct hash_netport4_elem e = {
.cidr = INIT_CIDR(h->nets[0].cidr[0], HOST_MASK),
};
struct ip_set_ext ext = IP_SET_INIT_KEXT(skb, opt, set);
if (adt == IPSET_TEST)
e.cidr = HOST_MASK - 1;
if (!ip_set_get_ip4_port(skb, opt->flags & IPSET_DIM_TWO_SRC,
&e.port, &e.proto))
return -EINVAL;
ip4addrptr(skb, opt->flags & IPSET_DIM_ONE_SRC, &e.ip);
e.ip &= ip_set_netmask(e.cidr + 1);
return adtfn(set, &e, &ext, &opt->ext, opt->cmdflags);
}
static int
hash_netport4_uadt(struct ip_set *set, struct nlattr *tb[],
enum ipset_adt adt, u32 *lineno, u32 flags, bool retried)
{
const struct hash_netport4 *h = set->data;
ipset_adtfn adtfn = set->variant->adt[adt];
struct hash_netport4_elem e = { .cidr = HOST_MASK - 1 };
struct ip_set_ext ext = IP_SET_INIT_UEXT(set);
u32 port, port_to, p = 0, ip = 0, ip_to = 0, last;
bool with_ports = false;
u8 cidr;
int ret;
if (tb[IPSET_ATTR_LINENO])
*lineno = nla_get_u32(tb[IPSET_ATTR_LINENO]);
if (unlikely(!tb[IPSET_ATTR_IP] ||
!ip_set_attr_netorder(tb, IPSET_ATTR_PORT) ||
!ip_set_optattr_netorder(tb, IPSET_ATTR_PORT_TO) ||
!ip_set_optattr_netorder(tb, IPSET_ATTR_CADT_FLAGS)))
return -IPSET_ERR_PROTOCOL;
ret = ip_set_get_hostipaddr4(tb[IPSET_ATTR_IP], &ip);
if (ret)
return ret;
ret = ip_set_get_extensions(set, tb, &ext);
if (ret)
return ret;
if (tb[IPSET_ATTR_CIDR]) {
cidr = nla_get_u8(tb[IPSET_ATTR_CIDR]);
if (!cidr || cidr > HOST_MASK)
return -IPSET_ERR_INVALID_CIDR;
e.cidr = cidr - 1;
}
e.port = nla_get_be16(tb[IPSET_ATTR_PORT]);
if (tb[IPSET_ATTR_PROTO]) {
e.proto = nla_get_u8(tb[IPSET_ATTR_PROTO]);
with_ports = ip_set_proto_with_ports(e.proto);
if (e.proto == 0)
return -IPSET_ERR_INVALID_PROTO;
} else {
return -IPSET_ERR_MISSING_PROTO;
}
if (!(with_ports || e.proto == IPPROTO_ICMP))
e.port = 0;
with_ports = with_ports && tb[IPSET_ATTR_PORT_TO];
if (tb[IPSET_ATTR_CADT_FLAGS]) {
u32 cadt_flags = ip_set_get_h32(tb[IPSET_ATTR_CADT_FLAGS]);
if (cadt_flags & IPSET_FLAG_NOMATCH)
flags |= (IPSET_FLAG_NOMATCH << 16);
}
if (adt == IPSET_TEST || !(with_ports || tb[IPSET_ATTR_IP_TO])) {
e.ip = htonl(ip & ip_set_hostmask(e.cidr + 1));
ret = adtfn(set, &e, &ext, &ext, flags);
return ip_set_enomatch(ret, flags, adt, set) ? -ret :
ip_set_eexist(ret, flags) ? 0 : ret;
}
port = port_to = ntohs(e.port);
if (tb[IPSET_ATTR_PORT_TO]) {
port_to = ip_set_get_h16(tb[IPSET_ATTR_PORT_TO]);
if (port_to < port)
swap(port, port_to);
}
if (tb[IPSET_ATTR_IP_TO]) {
ret = ip_set_get_hostipaddr4(tb[IPSET_ATTR_IP_TO], &ip_to);
if (ret)
return ret;
if (ip_to < ip)
swap(ip, ip_to);
if (ip + UINT_MAX == ip_to)
return -IPSET_ERR_HASH_RANGE;
} else {
ip_set_mask_from_to(ip, ip_to, e.cidr + 1);
}
if (retried)
ip = ntohl(h->next.ip);
while (ip <= ip_to) {
e.ip = htonl(ip);
last = ip_set_range_to_cidr(ip, ip_to, &cidr);
e.cidr = cidr - 1;
p = retried && ip == ntohl(h->next.ip) ? ntohs(h->next.port)
: port;
for (; p <= port_to; p++) {
e.port = htons(p);
ret = adtfn(set, &e, &ext, &ext, flags);
if (ret && !ip_set_eexist(ret, flags))
return ret;
ret = 0;
}
ip = last + 1;
}
return ret;
}
static inline bool
hash_netport6_data_equal(const struct hash_netport6_elem *ip1,
const struct hash_netport6_elem *ip2,
u32 *multi)
{
return ipv6_addr_equal(&ip1->ip.in6, &ip2->ip.in6) &&
ip1->port == ip2->port &&
ip1->proto == ip2->proto &&
ip1->cidr == ip2->cidr;
}
static inline int
hash_netport6_do_data_match(const struct hash_netport6_elem *elem)
{
return elem->nomatch ? -ENOTEMPTY : 1;
}
static inline void
hash_netport6_data_set_flags(struct hash_netport6_elem *elem, u32 flags)
{
elem->nomatch = !!((flags >> 16) & IPSET_FLAG_NOMATCH);
}
static inline void
hash_netport6_data_reset_flags(struct hash_netport6_elem *elem, u8 *flags)
{
swap(*flags, elem->nomatch);
}
static inline void
hash_netport6_data_netmask(struct hash_netport6_elem *elem, u8 cidr)
{
ip6_netmask(&elem->ip, cidr);
elem->cidr = cidr - 1;
}
static bool
hash_netport6_data_list(struct sk_buff *skb,
const struct hash_netport6_elem *data)
{
u32 flags = data->nomatch ? IPSET_FLAG_NOMATCH : 0;
if (nla_put_ipaddr6(skb, IPSET_ATTR_IP, &data->ip.in6) ||
nla_put_net16(skb, IPSET_ATTR_PORT, data->port) ||
nla_put_u8(skb, IPSET_ATTR_CIDR, data->cidr + 1) ||
nla_put_u8(skb, IPSET_ATTR_PROTO, data->proto) ||
(flags &&
nla_put_net32(skb, IPSET_ATTR_CADT_FLAGS, htonl(flags))))
goto nla_put_failure;
return false;
nla_put_failure:
return true;
}
static inline void
hash_netport6_data_next(struct hash_netport6_elem *next,
const struct hash_netport6_elem *d)
{
next->port = d->port;
}
static int
hash_netport6_kadt(struct ip_set *set, const struct sk_buff *skb,
const struct xt_action_param *par,
enum ipset_adt adt, struct ip_set_adt_opt *opt)
{
const struct hash_netport6 *h = set->data;
ipset_adtfn adtfn = set->variant->adt[adt];
struct hash_netport6_elem e = {
.cidr = INIT_CIDR(h->nets[0].cidr[0], HOST_MASK),
};
struct ip_set_ext ext = IP_SET_INIT_KEXT(skb, opt, set);
if (adt == IPSET_TEST)
e.cidr = HOST_MASK - 1;
if (!ip_set_get_ip6_port(skb, opt->flags & IPSET_DIM_TWO_SRC,
&e.port, &e.proto))
return -EINVAL;
ip6addrptr(skb, opt->flags & IPSET_DIM_ONE_SRC, &e.ip.in6);
ip6_netmask(&e.ip, e.cidr + 1);
return adtfn(set, &e, &ext, &opt->ext, opt->cmdflags);
}
static int
hash_netport6_uadt(struct ip_set *set, struct nlattr *tb[],
enum ipset_adt adt, u32 *lineno, u32 flags, bool retried)
{
const struct hash_netport6 *h = set->data;
ipset_adtfn adtfn = set->variant->adt[adt];
struct hash_netport6_elem e = { .cidr = HOST_MASK - 1 };
struct ip_set_ext ext = IP_SET_INIT_UEXT(set);
u32 port, port_to;
bool with_ports = false;
u8 cidr;
int ret;
if (tb[IPSET_ATTR_LINENO])
*lineno = nla_get_u32(tb[IPSET_ATTR_LINENO]);
if (unlikely(!tb[IPSET_ATTR_IP] ||
!ip_set_attr_netorder(tb, IPSET_ATTR_PORT) ||
!ip_set_optattr_netorder(tb, IPSET_ATTR_PORT_TO) ||
!ip_set_optattr_netorder(tb, IPSET_ATTR_CADT_FLAGS)))
return -IPSET_ERR_PROTOCOL;
if (unlikely(tb[IPSET_ATTR_IP_TO]))
return -IPSET_ERR_HASH_RANGE_UNSUPPORTED;
ret = ip_set_get_ipaddr6(tb[IPSET_ATTR_IP], &e.ip);
if (ret)
return ret;
ret = ip_set_get_extensions(set, tb, &ext);
if (ret)
return ret;
if (tb[IPSET_ATTR_CIDR]) {
cidr = nla_get_u8(tb[IPSET_ATTR_CIDR]);
if (!cidr || cidr > HOST_MASK)
return -IPSET_ERR_INVALID_CIDR;
e.cidr = cidr - 1;
}
ip6_netmask(&e.ip, e.cidr + 1);
e.port = nla_get_be16(tb[IPSET_ATTR_PORT]);
if (tb[IPSET_ATTR_PROTO]) {
e.proto = nla_get_u8(tb[IPSET_ATTR_PROTO]);
with_ports = ip_set_proto_with_ports(e.proto);
if (e.proto == 0)
return -IPSET_ERR_INVALID_PROTO;
} else {
return -IPSET_ERR_MISSING_PROTO;
}
if (!(with_ports || e.proto == IPPROTO_ICMPV6))
e.port = 0;
if (tb[IPSET_ATTR_CADT_FLAGS]) {
u32 cadt_flags = ip_set_get_h32(tb[IPSET_ATTR_CADT_FLAGS]);
if (cadt_flags & IPSET_FLAG_NOMATCH)
flags |= (IPSET_FLAG_NOMATCH << 16);
}
if (adt == IPSET_TEST || !with_ports || !tb[IPSET_ATTR_PORT_TO]) {
ret = adtfn(set, &e, &ext, &ext, flags);
return ip_set_enomatch(ret, flags, adt, set) ? -ret :
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
ret = 0;
}
return ret;
}
static int __init
hash_netport_init(void)
{
return ip_set_type_register(&hash_netport_type);
}
static void __exit
hash_netport_fini(void)
{
rcu_barrier();
ip_set_type_unregister(&hash_netport_type);
}
