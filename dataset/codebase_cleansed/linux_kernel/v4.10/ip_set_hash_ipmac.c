static inline bool
hash_ipmac4_data_equal(const struct hash_ipmac4_elem *e1,
const struct hash_ipmac4_elem *e2,
u32 *multi)
{
return e1->ip == e2->ip && ether_addr_equal(e1->ether, e2->ether);
}
static bool
hash_ipmac4_data_list(struct sk_buff *skb, const struct hash_ipmac4_elem *e)
{
if (nla_put_ipaddr4(skb, IPSET_ATTR_IP, e->ip) ||
nla_put(skb, IPSET_ATTR_ETHER, ETH_ALEN, e->ether))
goto nla_put_failure;
return false;
nla_put_failure:
return true;
}
static inline void
hash_ipmac4_data_next(struct hash_ipmac4_elem *next,
const struct hash_ipmac4_elem *e)
{
next->ip = e->ip;
}
static int
hash_ipmac4_kadt(struct ip_set *set, const struct sk_buff *skb,
const struct xt_action_param *par,
enum ipset_adt adt, struct ip_set_adt_opt *opt)
{
ipset_adtfn adtfn = set->variant->adt[adt];
struct hash_ipmac4_elem e = { .ip = 0, { .foo[0] = 0, .foo[1] = 0 } };
struct ip_set_ext ext = IP_SET_INIT_KEXT(skb, opt, set);
if (!(opt->flags & IPSET_DIM_TWO_SRC))
return 0;
if (skb_mac_header(skb) < skb->head ||
(skb_mac_header(skb) + ETH_HLEN) > skb->data)
return -EINVAL;
memcpy(e.ether, eth_hdr(skb)->h_source, ETH_ALEN);
if (ether_addr_equal(e.ether, invalid_ether))
return -EINVAL;
ip4addrptr(skb, opt->flags & IPSET_DIM_ONE_SRC, &e.ip);
return adtfn(set, &e, &ext, &opt->ext, opt->cmdflags);
}
static int
hash_ipmac4_uadt(struct ip_set *set, struct nlattr *tb[],
enum ipset_adt adt, u32 *lineno, u32 flags, bool retried)
{
ipset_adtfn adtfn = set->variant->adt[adt];
struct hash_ipmac4_elem e = { .ip = 0, { .foo[0] = 0, .foo[1] = 0 } };
struct ip_set_ext ext = IP_SET_INIT_UEXT(set);
int ret;
if (unlikely(!tb[IPSET_ATTR_IP] ||
!tb[IPSET_ATTR_ETHER] ||
nla_len(tb[IPSET_ATTR_ETHER]) != ETH_ALEN ||
!ip_set_optattr_netorder(tb, IPSET_ATTR_TIMEOUT) ||
!ip_set_optattr_netorder(tb, IPSET_ATTR_PACKETS) ||
!ip_set_optattr_netorder(tb, IPSET_ATTR_BYTES) ||
!ip_set_optattr_netorder(tb, IPSET_ATTR_SKBMARK) ||
!ip_set_optattr_netorder(tb, IPSET_ATTR_SKBPRIO) ||
!ip_set_optattr_netorder(tb, IPSET_ATTR_SKBQUEUE)))
return -IPSET_ERR_PROTOCOL;
if (tb[IPSET_ATTR_LINENO])
*lineno = nla_get_u32(tb[IPSET_ATTR_LINENO]);
ret = ip_set_get_ipaddr4(tb[IPSET_ATTR_IP], &e.ip) ||
ip_set_get_extensions(set, tb, &ext);
if (ret)
return ret;
memcpy(e.ether, nla_data(tb[IPSET_ATTR_ETHER]), ETH_ALEN);
if (ether_addr_equal(e.ether, invalid_ether))
return -IPSET_ERR_HASH_ELEM;
return adtfn(set, &e, &ext, &ext, flags);
}
static inline bool
hash_ipmac6_data_equal(const struct hash_ipmac6_elem *e1,
const struct hash_ipmac6_elem *e2,
u32 *multi)
{
return ipv6_addr_equal(&e1->ip.in6, &e2->ip.in6) &&
ether_addr_equal(e1->ether, e2->ether);
}
static bool
hash_ipmac6_data_list(struct sk_buff *skb, const struct hash_ipmac6_elem *e)
{
if (nla_put_ipaddr6(skb, IPSET_ATTR_IP, &e->ip.in6) ||
nla_put(skb, IPSET_ATTR_ETHER, ETH_ALEN, e->ether))
goto nla_put_failure;
return false;
nla_put_failure:
return true;
}
static inline void
hash_ipmac6_data_next(struct hash_ipmac6_elem *next,
const struct hash_ipmac6_elem *e)
{
}
static int
hash_ipmac6_kadt(struct ip_set *set, const struct sk_buff *skb,
const struct xt_action_param *par,
enum ipset_adt adt, struct ip_set_adt_opt *opt)
{
ipset_adtfn adtfn = set->variant->adt[adt];
struct hash_ipmac6_elem e = {
{ .all = { 0 } },
{ .foo[0] = 0, .foo[1] = 0 }
};
struct ip_set_ext ext = IP_SET_INIT_KEXT(skb, opt, set);
if (!(opt->flags & IPSET_DIM_TWO_SRC))
return 0;
if (skb_mac_header(skb) < skb->head ||
(skb_mac_header(skb) + ETH_HLEN) > skb->data)
return -EINVAL;
memcpy(e.ether, eth_hdr(skb)->h_source, ETH_ALEN);
if (ether_addr_equal(e.ether, invalid_ether))
return -EINVAL;
ip6addrptr(skb, opt->flags & IPSET_DIM_ONE_SRC, &e.ip.in6);
return adtfn(set, &e, &ext, &opt->ext, opt->cmdflags);
}
static int
hash_ipmac6_uadt(struct ip_set *set, struct nlattr *tb[],
enum ipset_adt adt, u32 *lineno, u32 flags, bool retried)
{
ipset_adtfn adtfn = set->variant->adt[adt];
struct hash_ipmac6_elem e = {
{ .all = { 0 } },
{ .foo[0] = 0, .foo[1] = 0 }
};
struct ip_set_ext ext = IP_SET_INIT_UEXT(set);
int ret;
if (unlikely(!tb[IPSET_ATTR_IP] ||
!tb[IPSET_ATTR_ETHER] ||
nla_len(tb[IPSET_ATTR_ETHER]) != ETH_ALEN ||
!ip_set_optattr_netorder(tb, IPSET_ATTR_TIMEOUT) ||
!ip_set_optattr_netorder(tb, IPSET_ATTR_PACKETS) ||
!ip_set_optattr_netorder(tb, IPSET_ATTR_BYTES) ||
!ip_set_optattr_netorder(tb, IPSET_ATTR_SKBMARK) ||
!ip_set_optattr_netorder(tb, IPSET_ATTR_SKBPRIO) ||
!ip_set_optattr_netorder(tb, IPSET_ATTR_SKBQUEUE)))
return -IPSET_ERR_PROTOCOL;
if (tb[IPSET_ATTR_LINENO])
*lineno = nla_get_u32(tb[IPSET_ATTR_LINENO]);
ret = ip_set_get_ipaddr6(tb[IPSET_ATTR_IP], &e.ip) ||
ip_set_get_extensions(set, tb, &ext);
if (ret)
return ret;
memcpy(e.ether, nla_data(tb[IPSET_ATTR_ETHER]), ETH_ALEN);
if (ether_addr_equal(e.ether, invalid_ether))
return -IPSET_ERR_HASH_ELEM;
return adtfn(set, &e, &ext, &ext, flags);
}
static int __init
hash_ipmac_init(void)
{
return ip_set_type_register(&hash_ipmac_type);
}
static void __exit
hash_ipmac_fini(void)
{
ip_set_type_unregister(&hash_ipmac_type);
}
