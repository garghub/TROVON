static inline bool
hash_mac4_data_equal(const struct hash_mac4_elem *e1,
const struct hash_mac4_elem *e2,
u32 *multi)
{
return ether_addr_equal(e1->ether, e2->ether);
}
static inline bool
hash_mac4_data_list(struct sk_buff *skb, const struct hash_mac4_elem *e)
{
if (nla_put(skb, IPSET_ATTR_ETHER, ETH_ALEN, e->ether))
goto nla_put_failure;
return false;
nla_put_failure:
return true;
}
static inline void
hash_mac4_data_next(struct hash_mac4_elem *next,
const struct hash_mac4_elem *e)
{
}
static int
hash_mac4_kadt(struct ip_set *set, const struct sk_buff *skb,
const struct xt_action_param *par,
enum ipset_adt adt, struct ip_set_adt_opt *opt)
{
ipset_adtfn adtfn = set->variant->adt[adt];
struct hash_mac4_elem e = { { .foo[0] = 0, .foo[1] = 0 } };
struct ip_set_ext ext = IP_SET_INIT_KEXT(skb, opt, set);
if (!(opt->flags & IPSET_DIM_ONE_SRC))
return 0;
if (skb_mac_header(skb) < skb->head ||
(skb_mac_header(skb) + ETH_HLEN) > skb->data)
return -EINVAL;
ether_addr_copy(e.ether, eth_hdr(skb)->h_source);
if (memcmp(e.ether, invalid_ether, ETH_ALEN) == 0)
return -EINVAL;
return adtfn(set, &e, &ext, &opt->ext, opt->cmdflags);
}
static int
hash_mac4_uadt(struct ip_set *set, struct nlattr *tb[],
enum ipset_adt adt, u32 *lineno, u32 flags, bool retried)
{
ipset_adtfn adtfn = set->variant->adt[adt];
struct hash_mac4_elem e = { { .foo[0] = 0, .foo[1] = 0 } };
struct ip_set_ext ext = IP_SET_INIT_UEXT(set);
int ret;
if (tb[IPSET_ATTR_LINENO])
*lineno = nla_get_u32(tb[IPSET_ATTR_LINENO]);
if (unlikely(!tb[IPSET_ATTR_ETHER]))
return -IPSET_ERR_PROTOCOL;
ret = ip_set_get_extensions(set, tb, &ext);
if (ret)
return ret;
ether_addr_copy(e.ether, nla_data(tb[IPSET_ATTR_ETHER]));
if (memcmp(e.ether, invalid_ether, ETH_ALEN) == 0)
return -IPSET_ERR_HASH_ELEM;
return adtfn(set, &e, &ext, &ext, flags);
}
static int __init
hash_mac_init(void)
{
return ip_set_type_register(&hash_mac_type);
}
static void __exit
hash_mac_fini(void)
{
rcu_barrier();
ip_set_type_unregister(&hash_mac_type);
}
