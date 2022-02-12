unsigned int
nf_nat_masquerade_ipv6(struct sk_buff *skb, const struct nf_nat_range *range,
const struct net_device *out)
{
enum ip_conntrack_info ctinfo;
struct nf_conn_nat *nat;
struct in6_addr src;
struct nf_conn *ct;
struct nf_nat_range newrange;
ct = nf_ct_get(skb, &ctinfo);
NF_CT_ASSERT(ct && (ctinfo == IP_CT_NEW || ctinfo == IP_CT_RELATED ||
ctinfo == IP_CT_RELATED_REPLY));
if (ipv6_dev_get_saddr(nf_ct_net(ct), out,
&ipv6_hdr(skb)->daddr, 0, &src) < 0)
return NF_DROP;
nat = nf_ct_nat_ext_add(ct);
if (nat)
nat->masq_index = out->ifindex;
newrange.flags = range->flags | NF_NAT_RANGE_MAP_IPS;
newrange.min_addr.in6 = src;
newrange.max_addr.in6 = src;
newrange.min_proto = range->min_proto;
newrange.max_proto = range->max_proto;
return nf_nat_setup_info(ct, &newrange, NF_NAT_MANIP_SRC);
}
static int device_cmp(struct nf_conn *ct, void *ifindex)
{
const struct nf_conn_nat *nat = nfct_nat(ct);
if (!nat)
return 0;
if (nf_ct_l3num(ct) != NFPROTO_IPV6)
return 0;
return nat->masq_index == (int)(long)ifindex;
}
static int masq_device_event(struct notifier_block *this,
unsigned long event, void *ptr)
{
const struct net_device *dev = netdev_notifier_info_to_dev(ptr);
struct net *net = dev_net(dev);
if (event == NETDEV_DOWN)
nf_ct_iterate_cleanup_net(net, device_cmp,
(void *)(long)dev->ifindex, 0, 0);
return NOTIFY_DONE;
}
static void iterate_cleanup_work(struct work_struct *work)
{
struct masq_dev_work *w;
long index;
w = container_of(work, struct masq_dev_work, work);
index = w->ifindex;
nf_ct_iterate_cleanup_net(w->net, device_cmp, (void *)index, 0, 0);
put_net(w->net);
kfree(w);
atomic_dec(&v6_worker_count);
module_put(THIS_MODULE);
}
static int masq_inet_event(struct notifier_block *this,
unsigned long event, void *ptr)
{
struct inet6_ifaddr *ifa = ptr;
const struct net_device *dev;
struct masq_dev_work *w;
struct net *net;
if (event != NETDEV_DOWN ||
atomic_read(&v6_worker_count) >= MAX_WORK_COUNT)
return NOTIFY_DONE;
dev = ifa->idev->dev;
net = maybe_get_net(dev_net(dev));
if (!net)
return NOTIFY_DONE;
if (!try_module_get(THIS_MODULE))
goto err_module;
w = kmalloc(sizeof(*w), GFP_ATOMIC);
if (w) {
atomic_inc(&v6_worker_count);
INIT_WORK(&w->work, iterate_cleanup_work);
w->ifindex = dev->ifindex;
w->net = net;
schedule_work(&w->work);
return NOTIFY_DONE;
}
module_put(THIS_MODULE);
err_module:
put_net(net);
return NOTIFY_DONE;
}
void nf_nat_masquerade_ipv6_register_notifier(void)
{
if (atomic_inc_return(&masquerade_notifier_refcount) > 1)
return;
register_netdevice_notifier(&masq_dev_notifier);
register_inet6addr_notifier(&masq_inet_notifier);
}
void nf_nat_masquerade_ipv6_unregister_notifier(void)
{
if (atomic_dec_return(&masquerade_notifier_refcount) > 0)
return;
unregister_inet6addr_notifier(&masq_inet_notifier);
unregister_netdevice_notifier(&masq_dev_notifier);
}
