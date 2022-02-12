static int masquerade_tg_check(const struct xt_tgchk_param *par)
{
const struct nf_nat_ipv4_multi_range_compat *mr = par->targinfo;
if (mr->range[0].flags & NF_NAT_RANGE_MAP_IPS) {
pr_debug("bad MAP_IPS.\n");
return -EINVAL;
}
if (mr->rangesize != 1) {
pr_debug("bad rangesize %u\n", mr->rangesize);
return -EINVAL;
}
return 0;
}
static unsigned int
masquerade_tg(struct sk_buff *skb, const struct xt_action_param *par)
{
struct nf_conn *ct;
struct nf_conn_nat *nat;
enum ip_conntrack_info ctinfo;
struct nf_nat_ipv4_range newrange;
const struct nf_nat_ipv4_multi_range_compat *mr;
const struct rtable *rt;
__be32 newsrc;
NF_CT_ASSERT(par->hooknum == NF_INET_POST_ROUTING);
ct = nf_ct_get(skb, &ctinfo);
nat = nfct_nat(ct);
NF_CT_ASSERT(ct && (ctinfo == IP_CT_NEW || ctinfo == IP_CT_RELATED ||
ctinfo == IP_CT_RELATED_REPLY));
if (ct->tuplehash[IP_CT_DIR_ORIGINAL].tuple.src.u3.ip == 0)
return NF_ACCEPT;
mr = par->targinfo;
rt = skb_rtable(skb);
newsrc = inet_select_addr(par->out, rt->rt_gateway, RT_SCOPE_UNIVERSE);
if (!newsrc) {
pr_info("%s ate my IP address\n", par->out->name);
return NF_DROP;
}
nat->masq_index = par->out->ifindex;
newrange = ((struct nf_nat_ipv4_range)
{ mr->range[0].flags | NF_NAT_RANGE_MAP_IPS,
newsrc, newsrc,
mr->range[0].min, mr->range[0].max });
return nf_nat_setup_info(ct, &newrange, NF_NAT_MANIP_SRC);
}
static int
device_cmp(struct nf_conn *i, void *ifindex)
{
const struct nf_conn_nat *nat = nfct_nat(i);
if (!nat)
return 0;
return nat->masq_index == (int)(long)ifindex;
}
static int masq_device_event(struct notifier_block *this,
unsigned long event,
void *ptr)
{
const struct net_device *dev = ptr;
struct net *net = dev_net(dev);
if (event == NETDEV_DOWN) {
NF_CT_ASSERT(dev->ifindex != 0);
nf_ct_iterate_cleanup(net, device_cmp,
(void *)(long)dev->ifindex);
}
return NOTIFY_DONE;
}
static int masq_inet_event(struct notifier_block *this,
unsigned long event,
void *ptr)
{
struct net_device *dev = ((struct in_ifaddr *)ptr)->ifa_dev->dev;
return masq_device_event(this, event, dev);
}
static int __init masquerade_tg_init(void)
{
int ret;
ret = xt_register_target(&masquerade_tg_reg);
if (ret == 0) {
register_netdevice_notifier(&masq_dev_notifier);
register_inetaddr_notifier(&masq_inet_notifier);
}
return ret;
}
static void __exit masquerade_tg_exit(void)
{
xt_unregister_target(&masquerade_tg_reg);
unregister_netdevice_notifier(&masq_dev_notifier);
unregister_inetaddr_notifier(&masq_inet_notifier);
}
