static int redirect_tg_check(const struct xt_tgchk_param *par)
{
const struct nf_nat_multi_range_compat *mr = par->targinfo;
if (mr->range[0].flags & IP_NAT_RANGE_MAP_IPS) {
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
redirect_tg(struct sk_buff *skb, const struct xt_action_param *par)
{
struct nf_conn *ct;
enum ip_conntrack_info ctinfo;
__be32 newdst;
const struct nf_nat_multi_range_compat *mr = par->targinfo;
struct nf_nat_range newrange;
NF_CT_ASSERT(par->hooknum == NF_INET_PRE_ROUTING ||
par->hooknum == NF_INET_LOCAL_OUT);
ct = nf_ct_get(skb, &ctinfo);
NF_CT_ASSERT(ct && (ctinfo == IP_CT_NEW || ctinfo == IP_CT_RELATED));
if (par->hooknum == NF_INET_LOCAL_OUT)
newdst = htonl(0x7F000001);
else {
struct in_device *indev;
struct in_ifaddr *ifa;
newdst = 0;
rcu_read_lock();
indev = __in_dev_get_rcu(skb->dev);
if (indev && (ifa = indev->ifa_list))
newdst = ifa->ifa_local;
rcu_read_unlock();
if (!newdst)
return NF_DROP;
}
newrange = ((struct nf_nat_range)
{ mr->range[0].flags | IP_NAT_RANGE_MAP_IPS,
newdst, newdst,
mr->range[0].min, mr->range[0].max });
return nf_nat_setup_info(ct, &newrange, IP_NAT_MANIP_DST);
}
static int __init redirect_tg_init(void)
{
return xt_register_target(&redirect_tg_reg);
}
static void __exit redirect_tg_exit(void)
{
xt_unregister_target(&redirect_tg_reg);
}
