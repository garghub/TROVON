static inline bool
hash_ipportip4_data_equal(const struct hash_ipportip4_elem *ip1,
const struct hash_ipportip4_elem *ip2,
u32 *multi)
{
return ip1->ip == ip2->ip &&
ip1->ip2 == ip2->ip2 &&
ip1->port == ip2->port &&
ip1->proto == ip2->proto;
}
static bool
hash_ipportip4_data_list(struct sk_buff *skb,
const struct hash_ipportip4_elem *data)
{
if (nla_put_ipaddr4(skb, IPSET_ATTR_IP, data->ip) ||
nla_put_ipaddr4(skb, IPSET_ATTR_IP2, data->ip2) ||
nla_put_net16(skb, IPSET_ATTR_PORT, data->port) ||
nla_put_u8(skb, IPSET_ATTR_PROTO, data->proto))
goto nla_put_failure;
return 0;
nla_put_failure:
return 1;
}
static inline void
hash_ipportip4_data_next(struct hash_ipportip4_elem *next,
const struct hash_ipportip4_elem *d)
{
next->ip = d->ip;
next->port = d->port;
}
static int
hash_ipportip4_kadt(struct ip_set *set, const struct sk_buff *skb,
const struct xt_action_param *par,
enum ipset_adt adt, struct ip_set_adt_opt *opt)
{
ipset_adtfn adtfn = set->variant->adt[adt];
struct hash_ipportip4_elem e = { };
struct ip_set_ext ext = IP_SET_INIT_KEXT(skb, opt, set);
if (!ip_set_get_ip4_port(skb, opt->flags & IPSET_DIM_TWO_SRC,
&e.port, &e.proto))
return -EINVAL;
ip4addrptr(skb, opt->flags & IPSET_DIM_ONE_SRC, &e.ip);
ip4addrptr(skb, opt->flags & IPSET_DIM_THREE_SRC, &e.ip2);
return adtfn(set, &e, &ext, &opt->ext, opt->cmdflags);
}
static int
hash_ipportip4_uadt(struct ip_set *set, struct nlattr *tb[],
enum ipset_adt adt, u32 *lineno, u32 flags, bool retried)
{
const struct hash_ipportip *h = set->data;
ipset_adtfn adtfn = set->variant->adt[adt];
struct hash_ipportip4_elem e = { };
struct ip_set_ext ext = IP_SET_INIT_UEXT(set);
u32 ip, ip_to = 0, p = 0, port, port_to;
bool with_ports = false;
int ret;
if (unlikely(!tb[IPSET_ATTR_IP] || !tb[IPSET_ATTR_IP2] ||
!ip_set_attr_netorder(tb, IPSET_ATTR_PORT) ||
!ip_set_optattr_netorder(tb, IPSET_ATTR_PORT_TO) ||
!ip_set_optattr_netorder(tb, IPSET_ATTR_TIMEOUT) ||
!ip_set_optattr_netorder(tb, IPSET_ATTR_PACKETS) ||
!ip_set_optattr_netorder(tb, IPSET_ATTR_BYTES)))
return -IPSET_ERR_PROTOCOL;
if (tb[IPSET_ATTR_LINENO])
*lineno = nla_get_u32(tb[IPSET_ATTR_LINENO]);
ret = ip_set_get_ipaddr4(tb[IPSET_ATTR_IP], &e.ip) ||
ip_set_get_extensions(set, tb, &ext);
if (ret)
return ret;
ret = ip_set_get_ipaddr4(tb[IPSET_ATTR_IP2], &e.ip2);
if (ret)
return ret;
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
if (adt == IPSET_TEST ||
!(tb[IPSET_ATTR_IP_TO] || tb[IPSET_ATTR_CIDR] ||
tb[IPSET_ATTR_PORT_TO])) {
ret = adtfn(set, &e, &ext, &ext, flags);
return ip_set_eexist(ret, flags) ? 0 : ret;
}
ip_to = ip = ntohl(e.ip);
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
if (with_ports && tb[IPSET_ATTR_PORT_TO]) {
port_to = ip_set_get_h16(tb[IPSET_ATTR_PORT_TO]);
if (port > port_to)
swap(port, port_to);
}
if (retried)
ip = ntohl(h->next.ip);
for (; !before(ip_to, ip); ip++) {
p = retried && ip == ntohl(h->next.ip) ? ntohs(h->next.port)
: port;
for (; p <= port_to; p++) {
e.ip = htonl(ip);
e.port = htons(p);
ret = adtfn(set, &e, &ext, &ext, flags);
if (ret && !ip_set_eexist(ret, flags))
return ret;
else
ret = 0;
}
}
return ret;
}
static inline bool
hash_ipportip6_data_equal(const struct hash_ipportip6_elem *ip1,
const struct hash_ipportip6_elem *ip2,
u32 *multi)
{
return ipv6_addr_equal(&ip1->ip.in6, &ip2->ip.in6) &&
ipv6_addr_equal(&ip1->ip2.in6, &ip2->ip2.in6) &&
ip1->port == ip2->port &&
ip1->proto == ip2->proto;
}
static bool
hash_ipportip6_data_list(struct sk_buff *skb,
const struct hash_ipportip6_elem *data)
{
if (nla_put_ipaddr6(skb, IPSET_ATTR_IP, &data->ip.in6) ||
nla_put_ipaddr6(skb, IPSET_ATTR_IP2, &data->ip2.in6) ||
nla_put_net16(skb, IPSET_ATTR_PORT, data->port) ||
nla_put_u8(skb, IPSET_ATTR_PROTO, data->proto))
goto nla_put_failure;
return 0;
nla_put_failure:
return 1;
}
static inline void
hash_ipportip6_data_next(struct hash_ipportip4_elem *next,
const struct hash_ipportip6_elem *d)
{
next->port = d->port;
}
static int
hash_ipportip6_kadt(struct ip_set *set, const struct sk_buff *skb,
const struct xt_action_param *par,
enum ipset_adt adt, struct ip_set_adt_opt *opt)
{
ipset_adtfn adtfn = set->variant->adt[adt];
struct hash_ipportip6_elem e = { };
struct ip_set_ext ext = IP_SET_INIT_KEXT(skb, opt, set);
if (!ip_set_get_ip6_port(skb, opt->flags & IPSET_DIM_TWO_SRC,
&e.port, &e.proto))
return -EINVAL;
ip6addrptr(skb, opt->flags & IPSET_DIM_ONE_SRC, &e.ip.in6);
ip6addrptr(skb, opt->flags & IPSET_DIM_THREE_SRC, &e.ip2.in6);
return adtfn(set, &e, &ext, &opt->ext, opt->cmdflags);
}
static int
hash_ipportip6_uadt(struct ip_set *set, struct nlattr *tb[],
enum ipset_adt adt, u32 *lineno, u32 flags, bool retried)
{
const struct hash_ipportip *h = set->data;
ipset_adtfn adtfn = set->variant->adt[adt];
struct hash_ipportip6_elem e = { };
struct ip_set_ext ext = IP_SET_INIT_UEXT(set);
u32 port, port_to;
bool with_ports = false;
int ret;
if (unlikely(!tb[IPSET_ATTR_IP] || !tb[IPSET_ATTR_IP2] ||
!ip_set_attr_netorder(tb, IPSET_ATTR_PORT) ||
!ip_set_optattr_netorder(tb, IPSET_ATTR_PORT_TO) ||
!ip_set_optattr_netorder(tb, IPSET_ATTR_TIMEOUT) ||
!ip_set_optattr_netorder(tb, IPSET_ATTR_PACKETS) ||
!ip_set_optattr_netorder(tb, IPSET_ATTR_BYTES) ||
tb[IPSET_ATTR_IP_TO] ||
tb[IPSET_ATTR_CIDR]))
return -IPSET_ERR_PROTOCOL;
if (tb[IPSET_ATTR_LINENO])
*lineno = nla_get_u32(tb[IPSET_ATTR_LINENO]);
ret = ip_set_get_ipaddr6(tb[IPSET_ATTR_IP], &e.ip) ||
ip_set_get_extensions(set, tb, &ext);
if (ret)
return ret;
ret = ip_set_get_ipaddr6(tb[IPSET_ATTR_IP2], &e.ip2);
if (ret)
return ret;
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
if (adt == IPSET_TEST || !with_ports || !tb[IPSET_ATTR_PORT_TO]) {
ret = adtfn(set, &e, &ext, &ext, flags);
return ip_set_eexist(ret, flags) ? 0 : ret;
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
hash_ipportip_init(void)
{
return ip_set_type_register(&hash_ipportip_type);
}
static void __exit
hash_ipportip_fini(void)
{
ip_set_type_unregister(&hash_ipportip_type);
}
