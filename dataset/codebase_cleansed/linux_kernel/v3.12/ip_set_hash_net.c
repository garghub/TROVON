static inline bool
hash_net4_data_equal(const struct hash_net4_elem *ip1,
const struct hash_net4_elem *ip2,
u32 *multi)
{
return ip1->ip == ip2->ip &&
ip1->cidr == ip2->cidr;
}
static inline int
hash_net4_do_data_match(const struct hash_net4_elem *elem)
{
return elem->nomatch ? -ENOTEMPTY : 1;
}
static inline void
hash_net4_data_set_flags(struct hash_net4_elem *elem, u32 flags)
{
elem->nomatch = (flags >> 16) & IPSET_FLAG_NOMATCH;
}
static inline void
hash_net4_data_reset_flags(struct hash_net4_elem *elem, u8 *flags)
{
swap(*flags, elem->nomatch);
}
static inline void
hash_net4_data_netmask(struct hash_net4_elem *elem, u8 cidr)
{
elem->ip &= ip_set_netmask(cidr);
elem->cidr = cidr;
}
static bool
hash_net4_data_list(struct sk_buff *skb, const struct hash_net4_elem *data)
{
u32 flags = data->nomatch ? IPSET_FLAG_NOMATCH : 0;
if (nla_put_ipaddr4(skb, IPSET_ATTR_IP, data->ip) ||
nla_put_u8(skb, IPSET_ATTR_CIDR, data->cidr) ||
(flags &&
nla_put_net32(skb, IPSET_ATTR_CADT_FLAGS, htonl(flags))))
goto nla_put_failure;
return 0;
nla_put_failure:
return 1;
}
static inline void
hash_net4_data_next(struct hash_net4_elem *next,
const struct hash_net4_elem *d)
{
next->ip = d->ip;
}
static int
hash_net4_kadt(struct ip_set *set, const struct sk_buff *skb,
const struct xt_action_param *par,
enum ipset_adt adt, struct ip_set_adt_opt *opt)
{
const struct hash_net *h = set->data;
ipset_adtfn adtfn = set->variant->adt[adt];
struct hash_net4_elem e = {
.cidr = h->nets[0].cidr ? h->nets[0].cidr : HOST_MASK
};
struct ip_set_ext ext = IP_SET_INIT_KEXT(skb, opt, h);
if (e.cidr == 0)
return -EINVAL;
if (adt == IPSET_TEST)
e.cidr = HOST_MASK;
ip4addrptr(skb, opt->flags & IPSET_DIM_ONE_SRC, &e.ip);
e.ip &= ip_set_netmask(e.cidr);
return adtfn(set, &e, &ext, &opt->ext, opt->cmdflags);
}
static int
hash_net4_uadt(struct ip_set *set, struct nlattr *tb[],
enum ipset_adt adt, u32 *lineno, u32 flags, bool retried)
{
const struct hash_net *h = set->data;
ipset_adtfn adtfn = set->variant->adt[adt];
struct hash_net4_elem e = { .cidr = HOST_MASK };
struct ip_set_ext ext = IP_SET_INIT_UEXT(h);
u32 ip = 0, ip_to, last;
int ret;
if (unlikely(!tb[IPSET_ATTR_IP] ||
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
if (tb[IPSET_ATTR_CIDR]) {
e.cidr = nla_get_u8(tb[IPSET_ATTR_CIDR]);
if (!e.cidr || e.cidr > HOST_MASK)
return -IPSET_ERR_INVALID_CIDR;
}
if (tb[IPSET_ATTR_CADT_FLAGS]) {
u32 cadt_flags = ip_set_get_h32(tb[IPSET_ATTR_CADT_FLAGS]);
if (cadt_flags & IPSET_FLAG_NOMATCH)
flags |= (IPSET_FLAG_NOMATCH << 16);
}
if (adt == IPSET_TEST || !tb[IPSET_ATTR_IP_TO]) {
e.ip = htonl(ip & ip_set_hostmask(e.cidr));
ret = adtfn(set, &e, &ext, &ext, flags);
return ip_set_enomatch(ret, flags, adt, set) ? -ret:
ip_set_eexist(ret, flags) ? 0 : ret;
}
ip_to = ip;
if (tb[IPSET_ATTR_IP_TO]) {
ret = ip_set_get_hostipaddr4(tb[IPSET_ATTR_IP_TO], &ip_to);
if (ret)
return ret;
if (ip_to < ip)
swap(ip, ip_to);
if (ip + UINT_MAX == ip_to)
return -IPSET_ERR_HASH_RANGE;
}
if (retried)
ip = ntohl(h->next.ip);
while (!after(ip, ip_to)) {
e.ip = htonl(ip);
last = ip_set_range_to_cidr(ip, ip_to, &e.cidr);
ret = adtfn(set, &e, &ext, &ext, flags);
if (ret && !ip_set_eexist(ret, flags))
return ret;
else
ret = 0;
ip = last + 1;
}
return ret;
}
static inline bool
hash_net6_data_equal(const struct hash_net6_elem *ip1,
const struct hash_net6_elem *ip2,
u32 *multi)
{
return ipv6_addr_equal(&ip1->ip.in6, &ip2->ip.in6) &&
ip1->cidr == ip2->cidr;
}
static inline int
hash_net6_do_data_match(const struct hash_net6_elem *elem)
{
return elem->nomatch ? -ENOTEMPTY : 1;
}
static inline void
hash_net6_data_set_flags(struct hash_net6_elem *elem, u32 flags)
{
elem->nomatch = (flags >> 16) & IPSET_FLAG_NOMATCH;
}
static inline void
hash_net6_data_reset_flags(struct hash_net6_elem *elem, u8 *flags)
{
swap(*flags, elem->nomatch);
}
static inline void
hash_net6_data_netmask(struct hash_net6_elem *elem, u8 cidr)
{
ip6_netmask(&elem->ip, cidr);
elem->cidr = cidr;
}
static bool
hash_net6_data_list(struct sk_buff *skb, const struct hash_net6_elem *data)
{
u32 flags = data->nomatch ? IPSET_FLAG_NOMATCH : 0;
if (nla_put_ipaddr6(skb, IPSET_ATTR_IP, &data->ip.in6) ||
nla_put_u8(skb, IPSET_ATTR_CIDR, data->cidr) ||
(flags &&
nla_put_net32(skb, IPSET_ATTR_CADT_FLAGS, htonl(flags))))
goto nla_put_failure;
return 0;
nla_put_failure:
return 1;
}
static inline void
hash_net6_data_next(struct hash_net4_elem *next,
const struct hash_net6_elem *d)
{
}
static int
hash_net6_kadt(struct ip_set *set, const struct sk_buff *skb,
const struct xt_action_param *par,
enum ipset_adt adt, struct ip_set_adt_opt *opt)
{
const struct hash_net *h = set->data;
ipset_adtfn adtfn = set->variant->adt[adt];
struct hash_net6_elem e = {
.cidr = h->nets[0].cidr ? h->nets[0].cidr : HOST_MASK
};
struct ip_set_ext ext = IP_SET_INIT_KEXT(skb, opt, h);
if (e.cidr == 0)
return -EINVAL;
if (adt == IPSET_TEST)
e.cidr = HOST_MASK;
ip6addrptr(skb, opt->flags & IPSET_DIM_ONE_SRC, &e.ip.in6);
ip6_netmask(&e.ip, e.cidr);
return adtfn(set, &e, &ext, &opt->ext, opt->cmdflags);
}
static int
hash_net6_uadt(struct ip_set *set, struct nlattr *tb[],
enum ipset_adt adt, u32 *lineno, u32 flags, bool retried)
{
const struct hash_net *h = set->data;
ipset_adtfn adtfn = set->variant->adt[adt];
struct hash_net6_elem e = { .cidr = HOST_MASK };
struct ip_set_ext ext = IP_SET_INIT_UEXT(h);
int ret;
if (unlikely(!tb[IPSET_ATTR_IP] ||
!ip_set_optattr_netorder(tb, IPSET_ATTR_TIMEOUT) ||
!ip_set_optattr_netorder(tb, IPSET_ATTR_CADT_FLAGS) ||
!ip_set_optattr_netorder(tb, IPSET_ATTR_PACKETS) ||
!ip_set_optattr_netorder(tb, IPSET_ATTR_BYTES)))
return -IPSET_ERR_PROTOCOL;
if (unlikely(tb[IPSET_ATTR_IP_TO]))
return -IPSET_ERR_HASH_RANGE_UNSUPPORTED;
if (tb[IPSET_ATTR_LINENO])
*lineno = nla_get_u32(tb[IPSET_ATTR_LINENO]);
ret = ip_set_get_ipaddr6(tb[IPSET_ATTR_IP], &e.ip) ||
ip_set_get_extensions(set, tb, &ext);
if (ret)
return ret;
if (tb[IPSET_ATTR_CIDR])
e.cidr = nla_get_u8(tb[IPSET_ATTR_CIDR]);
if (!e.cidr || e.cidr > HOST_MASK)
return -IPSET_ERR_INVALID_CIDR;
ip6_netmask(&e.ip, e.cidr);
if (tb[IPSET_ATTR_CADT_FLAGS]) {
u32 cadt_flags = ip_set_get_h32(tb[IPSET_ATTR_CADT_FLAGS]);
if (cadt_flags & IPSET_FLAG_NOMATCH)
flags |= (IPSET_FLAG_NOMATCH << 16);
}
ret = adtfn(set, &e, &ext, &ext, flags);
return ip_set_enomatch(ret, flags, adt, set) ? -ret :
ip_set_eexist(ret, flags) ? 0 : ret;
}
static int __init
hash_net_init(void)
{
return ip_set_type_register(&hash_net_type);
}
static void __exit
hash_net_fini(void)
{
ip_set_type_unregister(&hash_net_type);
}
