static unsigned int
redirect_tg6(struct sk_buff *skb, const struct xt_action_param *par)
{
const struct nf_nat_range *range = par->targinfo;
struct nf_nat_range newrange;
struct in6_addr newdst;
enum ip_conntrack_info ctinfo;
struct nf_conn *ct;
ct = nf_ct_get(skb, &ctinfo);
if (par->hooknum == NF_INET_LOCAL_OUT)
newdst = loopback_addr;
else {
struct inet6_dev *idev;
struct inet6_ifaddr *ifa;
bool addr = false;
rcu_read_lock();
idev = __in6_dev_get(skb->dev);
if (idev != NULL) {
list_for_each_entry(ifa, &idev->addr_list, if_list) {
newdst = ifa->addr;
addr = true;
break;
}
}
rcu_read_unlock();
if (!addr)
return NF_DROP;
}
newrange.flags = range->flags | NF_NAT_RANGE_MAP_IPS;
newrange.min_addr.in6 = newdst;
newrange.max_addr.in6 = newdst;
newrange.min_proto = range->min_proto;
newrange.max_proto = range->max_proto;
return nf_nat_setup_info(ct, &newrange, NF_NAT_MANIP_DST);
}
static int redirect_tg6_checkentry(const struct xt_tgchk_param *par)
{
const struct nf_nat_range *range = par->targinfo;
if (range->flags & NF_NAT_RANGE_MAP_IPS)
return -EINVAL;
return 0;
}
static int redirect_tg4_check(const struct xt_tgchk_param *par)
{
const struct nf_nat_ipv4_multi_range_compat *mr = par->targinfo;
if (mr->range[0].flags & NF_NAT_RANGE_MAP_IPS) {
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
redirect_tg4(struct sk_buff *skb, const struct xt_action_param *par)
{
struct nf_conn *ct;
enum ip_conntrack_info ctinfo;
__be32 newdst;
const struct nf_nat_ipv4_multi_range_compat *mr = par->targinfo;
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
memset(&newrange.min_addr, 0, sizeof(newrange.min_addr));
memset(&newrange.max_addr, 0, sizeof(newrange.max_addr));
newrange.flags = mr->range[0].flags | NF_NAT_RANGE_MAP_IPS;
newrange.min_addr.ip = newdst;
newrange.max_addr.ip = newdst;
newrange.min_proto = mr->range[0].min;
newrange.max_proto = mr->range[0].max;
return nf_nat_setup_info(ct, &newrange, NF_NAT_MANIP_DST);
}
static int __init redirect_tg_init(void)
{
return xt_register_targets(redirect_tg_reg,
ARRAY_SIZE(redirect_tg_reg));
}
static void __exit redirect_tg_exit(void)
{
xt_unregister_targets(redirect_tg_reg, ARRAY_SIZE(redirect_tg_reg));
}
