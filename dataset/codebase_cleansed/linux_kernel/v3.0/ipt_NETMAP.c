static int netmap_tg_check(const struct xt_tgchk_param *par)
{
const struct nf_nat_multi_range_compat *mr = par->targinfo;
if (!(mr->range[0].flags & IP_NAT_RANGE_MAP_IPS)) {
pr_debug("bad MAP_IPS.\n");
return -EINVAL;
}
if (mr->rangesize != 1) {
pr_debug("bad rangesize %u.\n", mr->rangesize);
return -EINVAL;
}
return 0;
}
static unsigned int
netmap_tg(struct sk_buff *skb, const struct xt_action_param *par)
{
struct nf_conn *ct;
enum ip_conntrack_info ctinfo;
__be32 new_ip, netmask;
const struct nf_nat_multi_range_compat *mr = par->targinfo;
struct nf_nat_range newrange;
NF_CT_ASSERT(par->hooknum == NF_INET_PRE_ROUTING ||
par->hooknum == NF_INET_POST_ROUTING ||
par->hooknum == NF_INET_LOCAL_OUT ||
par->hooknum == NF_INET_LOCAL_IN);
ct = nf_ct_get(skb, &ctinfo);
netmask = ~(mr->range[0].min_ip ^ mr->range[0].max_ip);
if (par->hooknum == NF_INET_PRE_ROUTING ||
par->hooknum == NF_INET_LOCAL_OUT)
new_ip = ip_hdr(skb)->daddr & ~netmask;
else
new_ip = ip_hdr(skb)->saddr & ~netmask;
new_ip |= mr->range[0].min_ip & netmask;
newrange = ((struct nf_nat_range)
{ mr->range[0].flags | IP_NAT_RANGE_MAP_IPS,
new_ip, new_ip,
mr->range[0].min, mr->range[0].max });
return nf_nat_setup_info(ct, &newrange, HOOK2MANIP(par->hooknum));
}
static int __init netmap_tg_init(void)
{
return xt_register_target(&netmap_tg_reg);
}
static void __exit netmap_tg_exit(void)
{
xt_unregister_target(&netmap_tg_reg);
}
