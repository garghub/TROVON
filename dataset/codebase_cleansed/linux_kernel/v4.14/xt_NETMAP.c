static unsigned int
netmap_tg6(struct sk_buff *skb, const struct xt_action_param *par)
{
const struct nf_nat_range *range = par->targinfo;
struct nf_nat_range newrange;
struct nf_conn *ct;
enum ip_conntrack_info ctinfo;
union nf_inet_addr new_addr, netmask;
unsigned int i;
ct = nf_ct_get(skb, &ctinfo);
for (i = 0; i < ARRAY_SIZE(range->min_addr.ip6); i++)
netmask.ip6[i] = ~(range->min_addr.ip6[i] ^
range->max_addr.ip6[i]);
if (xt_hooknum(par) == NF_INET_PRE_ROUTING ||
xt_hooknum(par) == NF_INET_LOCAL_OUT)
new_addr.in6 = ipv6_hdr(skb)->daddr;
else
new_addr.in6 = ipv6_hdr(skb)->saddr;
for (i = 0; i < ARRAY_SIZE(new_addr.ip6); i++) {
new_addr.ip6[i] &= ~netmask.ip6[i];
new_addr.ip6[i] |= range->min_addr.ip6[i] &
netmask.ip6[i];
}
newrange.flags = range->flags | NF_NAT_RANGE_MAP_IPS;
newrange.min_addr = new_addr;
newrange.max_addr = new_addr;
newrange.min_proto = range->min_proto;
newrange.max_proto = range->max_proto;
return nf_nat_setup_info(ct, &newrange, HOOK2MANIP(xt_hooknum(par)));
}
static int netmap_tg6_checkentry(const struct xt_tgchk_param *par)
{
const struct nf_nat_range *range = par->targinfo;
if (!(range->flags & NF_NAT_RANGE_MAP_IPS))
return -EINVAL;
return nf_ct_netns_get(par->net, par->family);
}
static void netmap_tg_destroy(const struct xt_tgdtor_param *par)
{
nf_ct_netns_put(par->net, par->family);
}
static unsigned int
netmap_tg4(struct sk_buff *skb, const struct xt_action_param *par)
{
struct nf_conn *ct;
enum ip_conntrack_info ctinfo;
__be32 new_ip, netmask;
const struct nf_nat_ipv4_multi_range_compat *mr = par->targinfo;
struct nf_nat_range newrange;
WARN_ON(xt_hooknum(par) != NF_INET_PRE_ROUTING &&
xt_hooknum(par) != NF_INET_POST_ROUTING &&
xt_hooknum(par) != NF_INET_LOCAL_OUT &&
xt_hooknum(par) != NF_INET_LOCAL_IN);
ct = nf_ct_get(skb, &ctinfo);
netmask = ~(mr->range[0].min_ip ^ mr->range[0].max_ip);
if (xt_hooknum(par) == NF_INET_PRE_ROUTING ||
xt_hooknum(par) == NF_INET_LOCAL_OUT)
new_ip = ip_hdr(skb)->daddr & ~netmask;
else
new_ip = ip_hdr(skb)->saddr & ~netmask;
new_ip |= mr->range[0].min_ip & netmask;
memset(&newrange.min_addr, 0, sizeof(newrange.min_addr));
memset(&newrange.max_addr, 0, sizeof(newrange.max_addr));
newrange.flags = mr->range[0].flags | NF_NAT_RANGE_MAP_IPS;
newrange.min_addr.ip = new_ip;
newrange.max_addr.ip = new_ip;
newrange.min_proto = mr->range[0].min;
newrange.max_proto = mr->range[0].max;
return nf_nat_setup_info(ct, &newrange, HOOK2MANIP(xt_hooknum(par)));
}
static int netmap_tg4_check(const struct xt_tgchk_param *par)
{
const struct nf_nat_ipv4_multi_range_compat *mr = par->targinfo;
if (!(mr->range[0].flags & NF_NAT_RANGE_MAP_IPS)) {
pr_debug("bad MAP_IPS.\n");
return -EINVAL;
}
if (mr->rangesize != 1) {
pr_debug("bad rangesize %u.\n", mr->rangesize);
return -EINVAL;
}
return nf_ct_netns_get(par->net, par->family);
}
static int __init netmap_tg_init(void)
{
return xt_register_targets(netmap_tg_reg, ARRAY_SIZE(netmap_tg_reg));
}
static void netmap_tg_exit(void)
{
xt_unregister_targets(netmap_tg_reg, ARRAY_SIZE(netmap_tg_reg));
}
