static inline bool
hash_ipmark4_data_equal(const struct hash_ipmark4_elem *ip1,
const struct hash_ipmark4_elem *ip2,
u32 *multi)
{
return ip1->ip == ip2->ip &&
ip1->mark == ip2->mark;
}
static bool
hash_ipmark4_data_list(struct sk_buff *skb,
const struct hash_ipmark4_elem *data)
{
if (nla_put_ipaddr4(skb, IPSET_ATTR_IP, data->ip) ||
nla_put_net32(skb, IPSET_ATTR_MARK, htonl(data->mark)))
goto nla_put_failure;
return false;
nla_put_failure:
return true;
}
static inline void
hash_ipmark4_data_next(struct hash_ipmark4_elem *next,
const struct hash_ipmark4_elem *d)
{
next->ip = d->ip;
}
static int
hash_ipmark4_kadt(struct ip_set *set, const struct sk_buff *skb,
const struct xt_action_param *par,
enum ipset_adt adt, struct ip_set_adt_opt *opt)
{
const struct hash_ipmark *h = set->data;
ipset_adtfn adtfn = set->variant->adt[adt];
struct hash_ipmark4_elem e = { };
struct ip_set_ext ext = IP_SET_INIT_KEXT(skb, opt, set);
e.mark = skb->mark;
e.mark &= h->markmask;
ip4addrptr(skb, opt->flags & IPSET_DIM_ONE_SRC, &e.ip);
return adtfn(set, &e, &ext, &opt->ext, opt->cmdflags);
}
static int
hash_ipmark4_uadt(struct ip_set *set, struct nlattr *tb[],
enum ipset_adt adt, u32 *lineno, u32 flags, bool retried)
{
const struct hash_ipmark *h = set->data;
ipset_adtfn adtfn = set->variant->adt[adt];
struct hash_ipmark4_elem e = { };
struct ip_set_ext ext = IP_SET_INIT_UEXT(set);
u32 ip, ip_to = 0;
int ret;
if (tb[IPSET_ATTR_LINENO])
*lineno = nla_get_u32(tb[IPSET_ATTR_LINENO]);
if (unlikely(!tb[IPSET_ATTR_IP] ||
!ip_set_attr_netorder(tb, IPSET_ATTR_MARK)))
return -IPSET_ERR_PROTOCOL;
ret = ip_set_get_ipaddr4(tb[IPSET_ATTR_IP], &e.ip);
if (ret)
return ret;
ret = ip_set_get_extensions(set, tb, &ext);
if (ret)
return ret;
e.mark = ntohl(nla_get_be32(tb[IPSET_ATTR_MARK]));
e.mark &= h->markmask;
if (adt == IPSET_TEST ||
!(tb[IPSET_ATTR_IP_TO] || tb[IPSET_ATTR_CIDR])) {
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
if (!cidr || cidr > HOST_MASK)
return -IPSET_ERR_INVALID_CIDR;
ip_set_mask_from_to(ip, ip_to, cidr);
}
if (retried)
ip = ntohl(h->next.ip);
for (; !before(ip_to, ip); ip++) {
e.ip = htonl(ip);
ret = adtfn(set, &e, &ext, &ext, flags);
if (ret && !ip_set_eexist(ret, flags))
return ret;
ret = 0;
}
return ret;
}
static inline bool
hash_ipmark6_data_equal(const struct hash_ipmark6_elem *ip1,
const struct hash_ipmark6_elem *ip2,
u32 *multi)
{
return ipv6_addr_equal(&ip1->ip.in6, &ip2->ip.in6) &&
ip1->mark == ip2->mark;
}
static bool
hash_ipmark6_data_list(struct sk_buff *skb,
const struct hash_ipmark6_elem *data)
{
if (nla_put_ipaddr6(skb, IPSET_ATTR_IP, &data->ip.in6) ||
nla_put_net32(skb, IPSET_ATTR_MARK, htonl(data->mark)))
goto nla_put_failure;
return false;
nla_put_failure:
return true;
}
static inline void
hash_ipmark6_data_next(struct hash_ipmark4_elem *next,
const struct hash_ipmark6_elem *d)
{
}
static int
hash_ipmark6_kadt(struct ip_set *set, const struct sk_buff *skb,
const struct xt_action_param *par,
enum ipset_adt adt, struct ip_set_adt_opt *opt)
{
const struct hash_ipmark *h = set->data;
ipset_adtfn adtfn = set->variant->adt[adt];
struct hash_ipmark6_elem e = { };
struct ip_set_ext ext = IP_SET_INIT_KEXT(skb, opt, set);
e.mark = skb->mark;
e.mark &= h->markmask;
ip6addrptr(skb, opt->flags & IPSET_DIM_ONE_SRC, &e.ip.in6);
return adtfn(set, &e, &ext, &opt->ext, opt->cmdflags);
}
static int
hash_ipmark6_uadt(struct ip_set *set, struct nlattr *tb[],
enum ipset_adt adt, u32 *lineno, u32 flags, bool retried)
{
const struct hash_ipmark *h = set->data;
ipset_adtfn adtfn = set->variant->adt[adt];
struct hash_ipmark6_elem e = { };
struct ip_set_ext ext = IP_SET_INIT_UEXT(set);
int ret;
if (tb[IPSET_ATTR_LINENO])
*lineno = nla_get_u32(tb[IPSET_ATTR_LINENO]);
if (unlikely(!tb[IPSET_ATTR_IP] ||
!ip_set_attr_netorder(tb, IPSET_ATTR_MARK)))
return -IPSET_ERR_PROTOCOL;
if (unlikely(tb[IPSET_ATTR_IP_TO]))
return -IPSET_ERR_HASH_RANGE_UNSUPPORTED;
if (unlikely(tb[IPSET_ATTR_CIDR])) {
u8 cidr = nla_get_u8(tb[IPSET_ATTR_CIDR]);
if (cidr != HOST_MASK)
return -IPSET_ERR_INVALID_CIDR;
}
ret = ip_set_get_ipaddr6(tb[IPSET_ATTR_IP], &e.ip);
if (ret)
return ret;
ret = ip_set_get_extensions(set, tb, &ext);
if (ret)
return ret;
e.mark = ntohl(nla_get_be32(tb[IPSET_ATTR_MARK]));
e.mark &= h->markmask;
if (adt == IPSET_TEST) {
ret = adtfn(set, &e, &ext, &ext, flags);
return ip_set_eexist(ret, flags) ? 0 : ret;
}
ret = adtfn(set, &e, &ext, &ext, flags);
if (ret && !ip_set_eexist(ret, flags))
return ret;
return 0;
}
static int __init
hash_ipmark_init(void)
{
return ip_set_type_register(&hash_ipmark_type);
}
static void __exit
hash_ipmark_fini(void)
{
rcu_barrier();
ip_set_type_unregister(&hash_ipmark_type);
}
