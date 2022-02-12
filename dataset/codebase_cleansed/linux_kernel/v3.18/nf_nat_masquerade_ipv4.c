unsigned int
nf_nat_masquerade_ipv4(struct sk_buff *skb, unsigned int hooknum,
const struct nf_nat_range *range,
const struct net_device *out)
{
struct nf_conn *ct;
struct nf_conn_nat *nat;
enum ip_conntrack_info ctinfo;
struct nf_nat_range newrange;
const struct rtable *rt;
__be32 newsrc, nh;
NF_CT_ASSERT(hooknum == NF_INET_POST_ROUTING);
ct = nf_ct_get(skb, &ctinfo);
nat = nfct_nat(ct);
NF_CT_ASSERT(ct && (ctinfo == IP_CT_NEW || ctinfo == IP_CT_RELATED ||
ctinfo == IP_CT_RELATED_REPLY));
if (ct->tuplehash[IP_CT_DIR_ORIGINAL].tuple.src.u3.ip == 0)
return NF_ACCEPT;
rt = skb_rtable(skb);
nh = rt_nexthop(rt, ip_hdr(skb)->daddr);
newsrc = inet_select_addr(out, nh, RT_SCOPE_UNIVERSE);
if (!newsrc) {
pr_info("%s ate my IP address\n", out->name);
return NF_DROP;
}
nat->masq_index = out->ifindex;
memset(&newrange.min_addr, 0, sizeof(newrange.min_addr));
memset(&newrange.max_addr, 0, sizeof(newrange.max_addr));
newrange.flags = range->flags | NF_NAT_RANGE_MAP_IPS;
newrange.min_addr.ip = newsrc;
newrange.max_addr.ip = newsrc;
newrange.min_proto = range->min_proto;
newrange.max_proto = range->max_proto;
return nf_nat_setup_info(ct, &newrange, NF_NAT_MANIP_SRC);
}
static int device_cmp(struct nf_conn *i, void *ifindex)
{
const struct nf_conn_nat *nat = nfct_nat(i);
if (!nat)
return 0;
if (nf_ct_l3num(i) != NFPROTO_IPV4)
return 0;
return nat->masq_index == (int)(long)ifindex;
}
static int masq_device_event(struct notifier_block *this,
unsigned long event,
void *ptr)
{
const struct net_device *dev = netdev_notifier_info_to_dev(ptr);
struct net *net = dev_net(dev);
if (event == NETDEV_DOWN) {
NF_CT_ASSERT(dev->ifindex != 0);
nf_ct_iterate_cleanup(net, device_cmp,
(void *)(long)dev->ifindex, 0, 0);
}
return NOTIFY_DONE;
}
static int masq_inet_event(struct notifier_block *this,
unsigned long event,
void *ptr)
{
struct net_device *dev = ((struct in_ifaddr *)ptr)->ifa_dev->dev;
struct netdev_notifier_info info;
netdev_notifier_info_init(&info, dev);
return masq_device_event(this, event, &info);
}
void nf_nat_masquerade_ipv4_register_notifier(void)
{
if (atomic_inc_return(&masquerade_notifier_refcount) > 1)
return;
register_netdevice_notifier(&masq_dev_notifier);
register_inetaddr_notifier(&masq_inet_notifier);
}
void nf_nat_masquerade_ipv4_unregister_notifier(void)
{
if (atomic_dec_return(&masquerade_notifier_refcount) > 0)
return;
unregister_netdevice_notifier(&masq_dev_notifier);
unregister_inetaddr_notifier(&masq_inet_notifier);
}
