static inline struct ila_lwt *ila_lwt_lwtunnel(
struct lwtunnel_state *lwt)
{
return (struct ila_lwt *)lwt->data;
}
static inline struct ila_params *ila_params_lwtunnel(
struct lwtunnel_state *lwt)
{
return &ila_lwt_lwtunnel(lwt)->p;
}
static int ila_output(struct net *net, struct sock *sk, struct sk_buff *skb)
{
struct dst_entry *orig_dst = skb_dst(skb);
struct rt6_info *rt = (struct rt6_info *)orig_dst;
struct ila_lwt *ilwt = ila_lwt_lwtunnel(orig_dst->lwtstate);
struct dst_entry *dst;
int err = -EINVAL;
if (skb->protocol != htons(ETH_P_IPV6))
goto drop;
ila_update_ipv6_locator(skb, ila_params_lwtunnel(orig_dst->lwtstate),
true);
if (rt->rt6i_flags & (RTF_GATEWAY | RTF_CACHE)) {
return orig_dst->lwtstate->orig_output(net, sk, skb);
}
dst = dst_cache_get(&ilwt->dst_cache);
if (unlikely(!dst)) {
struct ipv6hdr *ip6h = ipv6_hdr(skb);
struct flowi6 fl6;
memset(&fl6, 0, sizeof(fl6));
fl6.flowi6_oif = orig_dst->dev->ifindex;
fl6.flowi6_iif = LOOPBACK_IFINDEX;
fl6.daddr = *rt6_nexthop((struct rt6_info *)orig_dst,
&ip6h->daddr);
dst = ip6_route_output(net, NULL, &fl6);
if (dst->error) {
err = -EHOSTUNREACH;
dst_release(dst);
goto drop;
}
dst = xfrm_lookup(net, dst, flowi6_to_flowi(&fl6), NULL, 0);
if (IS_ERR(dst)) {
err = PTR_ERR(dst);
goto drop;
}
if (ilwt->connected)
dst_cache_set_ip6(&ilwt->dst_cache, dst, &fl6.saddr);
}
skb_dst_set(skb, dst);
return dst_output(net, sk, skb);
drop:
kfree_skb(skb);
return -EINVAL;
}
static int ila_input(struct sk_buff *skb)
{
struct dst_entry *dst = skb_dst(skb);
if (skb->protocol != htons(ETH_P_IPV6))
goto drop;
ila_update_ipv6_locator(skb, ila_params_lwtunnel(dst->lwtstate), false);
return dst->lwtstate->orig_input(skb);
drop:
kfree_skb(skb);
return -EINVAL;
}
static int ila_build_state(struct nlattr *nla,
unsigned int family, const void *cfg,
struct lwtunnel_state **ts)
{
struct ila_lwt *ilwt;
struct ila_params *p;
struct nlattr *tb[ILA_ATTR_MAX + 1];
struct lwtunnel_state *newts;
const struct fib6_config *cfg6 = cfg;
struct ila_addr *iaddr;
int ret;
if (family != AF_INET6)
return -EINVAL;
if (cfg6->fc_dst_len < 8 * sizeof(struct ila_locator) + 3) {
return -EINVAL;
}
iaddr = (struct ila_addr *)&cfg6->fc_dst;
if (!ila_addr_is_ila(iaddr) || ila_csum_neutral_set(iaddr->ident)) {
return -EINVAL;
}
ret = nla_parse_nested(tb, ILA_ATTR_MAX, nla,
ila_nl_policy);
if (ret < 0)
return ret;
if (!tb[ILA_ATTR_LOCATOR])
return -EINVAL;
newts = lwtunnel_state_alloc(sizeof(*ilwt));
if (!newts)
return -ENOMEM;
ilwt = ila_lwt_lwtunnel(newts);
ret = dst_cache_init(&ilwt->dst_cache, GFP_ATOMIC);
if (ret) {
kfree(newts);
return ret;
}
p = ila_params_lwtunnel(newts);
p->locator.v64 = (__force __be64)nla_get_u64(tb[ILA_ATTR_LOCATOR]);
p->locator_match = iaddr->loc;
p->csum_diff = compute_csum_diff8(
(__be32 *)&p->locator_match, (__be32 *)&p->locator);
if (tb[ILA_ATTR_CSUM_MODE])
p->csum_mode = nla_get_u8(tb[ILA_ATTR_CSUM_MODE]);
ila_init_saved_csum(p);
newts->type = LWTUNNEL_ENCAP_ILA;
newts->flags |= LWTUNNEL_STATE_OUTPUT_REDIRECT |
LWTUNNEL_STATE_INPUT_REDIRECT;
if (cfg6->fc_dst_len == 8 * sizeof(struct in6_addr))
ilwt->connected = 1;
*ts = newts;
return 0;
}
static void ila_destroy_state(struct lwtunnel_state *lwt)
{
dst_cache_destroy(&ila_lwt_lwtunnel(lwt)->dst_cache);
}
static int ila_fill_encap_info(struct sk_buff *skb,
struct lwtunnel_state *lwtstate)
{
struct ila_params *p = ila_params_lwtunnel(lwtstate);
if (nla_put_u64_64bit(skb, ILA_ATTR_LOCATOR, (__force u64)p->locator.v64,
ILA_ATTR_PAD))
goto nla_put_failure;
if (nla_put_u8(skb, ILA_ATTR_CSUM_MODE, (__force u8)p->csum_mode))
goto nla_put_failure;
return 0;
nla_put_failure:
return -EMSGSIZE;
}
static int ila_encap_nlsize(struct lwtunnel_state *lwtstate)
{
return nla_total_size_64bit(sizeof(u64)) +
nla_total_size(sizeof(u8)) +
0;
}
static int ila_encap_cmp(struct lwtunnel_state *a, struct lwtunnel_state *b)
{
struct ila_params *a_p = ila_params_lwtunnel(a);
struct ila_params *b_p = ila_params_lwtunnel(b);
return (a_p->locator.v64 != b_p->locator.v64);
}
int ila_lwt_init(void)
{
return lwtunnel_encap_add_ops(&ila_encap_ops, LWTUNNEL_ENCAP_ILA);
}
void ila_lwt_fini(void)
{
lwtunnel_encap_del_ops(&ila_encap_ops, LWTUNNEL_ENCAP_ILA);
}
