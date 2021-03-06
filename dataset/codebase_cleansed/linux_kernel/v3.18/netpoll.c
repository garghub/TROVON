static int netpoll_start_xmit(struct sk_buff *skb, struct net_device *dev,
struct netdev_queue *txq)
{
int status = NETDEV_TX_OK;
netdev_features_t features;
features = netif_skb_features(skb);
if (vlan_tx_tag_present(skb) &&
!vlan_hw_offload_capable(features, skb->vlan_proto)) {
skb = __vlan_put_tag(skb, skb->vlan_proto,
vlan_tx_tag_get(skb));
if (unlikely(!skb)) {
goto out;
}
skb->vlan_tci = 0;
}
status = netdev_start_xmit(skb, dev, txq, false);
out:
return status;
}
static void queue_process(struct work_struct *work)
{
struct netpoll_info *npinfo =
container_of(work, struct netpoll_info, tx_work.work);
struct sk_buff *skb;
unsigned long flags;
while ((skb = skb_dequeue(&npinfo->txq))) {
struct net_device *dev = skb->dev;
struct netdev_queue *txq;
if (!netif_device_present(dev) || !netif_running(dev)) {
kfree_skb(skb);
continue;
}
txq = skb_get_tx_queue(dev, skb);
local_irq_save(flags);
HARD_TX_LOCK(dev, txq, smp_processor_id());
if (netif_xmit_frozen_or_stopped(txq) ||
netpoll_start_xmit(skb, dev, txq) != NETDEV_TX_OK) {
skb_queue_head(&npinfo->txq, skb);
HARD_TX_UNLOCK(dev, txq);
local_irq_restore(flags);
schedule_delayed_work(&npinfo->tx_work, HZ/10);
return;
}
HARD_TX_UNLOCK(dev, txq);
local_irq_restore(flags);
}
}
static int poll_one_napi(struct napi_struct *napi, int budget)
{
int work;
if (!test_bit(NAPI_STATE_SCHED, &napi->state))
return budget;
set_bit(NAPI_STATE_NPSVC, &napi->state);
work = napi->poll(napi, budget);
WARN_ONCE(work > budget, "%pF exceeded budget in poll\n", napi->poll);
trace_napi_poll(napi);
clear_bit(NAPI_STATE_NPSVC, &napi->state);
return budget - work;
}
static void poll_napi(struct net_device *dev, int budget)
{
struct napi_struct *napi;
list_for_each_entry(napi, &dev->napi_list, dev_list) {
if (napi->poll_owner != smp_processor_id() &&
spin_trylock(&napi->poll_lock)) {
budget = poll_one_napi(napi, budget);
spin_unlock(&napi->poll_lock);
}
}
}
static void netpoll_poll_dev(struct net_device *dev)
{
const struct net_device_ops *ops;
struct netpoll_info *ni = rcu_dereference_bh(dev->npinfo);
int budget = 0;
if (down_trylock(&ni->dev_lock))
return;
if (!netif_running(dev)) {
up(&ni->dev_lock);
return;
}
ops = dev->netdev_ops;
if (!ops->ndo_poll_controller) {
up(&ni->dev_lock);
return;
}
ops->ndo_poll_controller(dev);
poll_napi(dev, budget);
up(&ni->dev_lock);
zap_completion_queue();
}
void netpoll_poll_disable(struct net_device *dev)
{
struct netpoll_info *ni;
int idx;
might_sleep();
idx = srcu_read_lock(&netpoll_srcu);
ni = srcu_dereference(dev->npinfo, &netpoll_srcu);
if (ni)
down(&ni->dev_lock);
srcu_read_unlock(&netpoll_srcu, idx);
}
void netpoll_poll_enable(struct net_device *dev)
{
struct netpoll_info *ni;
rcu_read_lock();
ni = rcu_dereference(dev->npinfo);
if (ni)
up(&ni->dev_lock);
rcu_read_unlock();
}
static void refill_skbs(void)
{
struct sk_buff *skb;
unsigned long flags;
spin_lock_irqsave(&skb_pool.lock, flags);
while (skb_pool.qlen < MAX_SKBS) {
skb = alloc_skb(MAX_SKB_SIZE, GFP_ATOMIC);
if (!skb)
break;
__skb_queue_tail(&skb_pool, skb);
}
spin_unlock_irqrestore(&skb_pool.lock, flags);
}
static void zap_completion_queue(void)
{
unsigned long flags;
struct softnet_data *sd = &get_cpu_var(softnet_data);
if (sd->completion_queue) {
struct sk_buff *clist;
local_irq_save(flags);
clist = sd->completion_queue;
sd->completion_queue = NULL;
local_irq_restore(flags);
while (clist != NULL) {
struct sk_buff *skb = clist;
clist = clist->next;
if (!skb_irq_freeable(skb)) {
atomic_inc(&skb->users);
dev_kfree_skb_any(skb);
} else {
__kfree_skb(skb);
}
}
}
put_cpu_var(softnet_data);
}
static struct sk_buff *find_skb(struct netpoll *np, int len, int reserve)
{
int count = 0;
struct sk_buff *skb;
zap_completion_queue();
refill_skbs();
repeat:
skb = alloc_skb(len, GFP_ATOMIC);
if (!skb)
skb = skb_dequeue(&skb_pool);
if (!skb) {
if (++count < 10) {
netpoll_poll_dev(np->dev);
goto repeat;
}
return NULL;
}
atomic_set(&skb->users, 1);
skb_reserve(skb, reserve);
return skb;
}
static int netpoll_owner_active(struct net_device *dev)
{
struct napi_struct *napi;
list_for_each_entry(napi, &dev->napi_list, dev_list) {
if (napi->poll_owner == smp_processor_id())
return 1;
}
return 0;
}
void netpoll_send_skb_on_dev(struct netpoll *np, struct sk_buff *skb,
struct net_device *dev)
{
int status = NETDEV_TX_BUSY;
unsigned long tries;
struct netpoll_info *npinfo;
WARN_ON_ONCE(!irqs_disabled());
npinfo = rcu_dereference_bh(np->dev->npinfo);
if (!npinfo || !netif_running(dev) || !netif_device_present(dev)) {
dev_kfree_skb_irq(skb);
return;
}
if (skb_queue_len(&npinfo->txq) == 0 && !netpoll_owner_active(dev)) {
struct netdev_queue *txq;
txq = netdev_pick_tx(dev, skb, NULL);
for (tries = jiffies_to_usecs(1)/USEC_PER_POLL;
tries > 0; --tries) {
if (HARD_TX_TRYLOCK(dev, txq)) {
if (!netif_xmit_stopped(txq))
status = netpoll_start_xmit(skb, dev, txq);
HARD_TX_UNLOCK(dev, txq);
if (status == NETDEV_TX_OK)
break;
}
netpoll_poll_dev(np->dev);
udelay(USEC_PER_POLL);
}
WARN_ONCE(!irqs_disabled(),
"netpoll_send_skb_on_dev(): %s enabled interrupts in poll (%pF)\n",
dev->name, dev->netdev_ops->ndo_start_xmit);
}
if (status != NETDEV_TX_OK) {
skb_queue_tail(&npinfo->txq, skb);
schedule_delayed_work(&npinfo->tx_work,0);
}
}
void netpoll_send_udp(struct netpoll *np, const char *msg, int len)
{
int total_len, ip_len, udp_len;
struct sk_buff *skb;
struct udphdr *udph;
struct iphdr *iph;
struct ethhdr *eth;
static atomic_t ip_ident;
struct ipv6hdr *ip6h;
udp_len = len + sizeof(*udph);
if (np->ipv6)
ip_len = udp_len + sizeof(*ip6h);
else
ip_len = udp_len + sizeof(*iph);
total_len = ip_len + LL_RESERVED_SPACE(np->dev);
skb = find_skb(np, total_len + np->dev->needed_tailroom,
total_len - len);
if (!skb)
return;
skb_copy_to_linear_data(skb, msg, len);
skb_put(skb, len);
skb_push(skb, sizeof(*udph));
skb_reset_transport_header(skb);
udph = udp_hdr(skb);
udph->source = htons(np->local_port);
udph->dest = htons(np->remote_port);
udph->len = htons(udp_len);
if (np->ipv6) {
udph->check = 0;
udph->check = csum_ipv6_magic(&np->local_ip.in6,
&np->remote_ip.in6,
udp_len, IPPROTO_UDP,
csum_partial(udph, udp_len, 0));
if (udph->check == 0)
udph->check = CSUM_MANGLED_0;
skb_push(skb, sizeof(*ip6h));
skb_reset_network_header(skb);
ip6h = ipv6_hdr(skb);
put_unaligned(0x60, (unsigned char *)ip6h);
ip6h->flow_lbl[0] = 0;
ip6h->flow_lbl[1] = 0;
ip6h->flow_lbl[2] = 0;
ip6h->payload_len = htons(sizeof(struct udphdr) + len);
ip6h->nexthdr = IPPROTO_UDP;
ip6h->hop_limit = 32;
ip6h->saddr = np->local_ip.in6;
ip6h->daddr = np->remote_ip.in6;
eth = (struct ethhdr *) skb_push(skb, ETH_HLEN);
skb_reset_mac_header(skb);
skb->protocol = eth->h_proto = htons(ETH_P_IPV6);
} else {
udph->check = 0;
udph->check = csum_tcpudp_magic(np->local_ip.ip,
np->remote_ip.ip,
udp_len, IPPROTO_UDP,
csum_partial(udph, udp_len, 0));
if (udph->check == 0)
udph->check = CSUM_MANGLED_0;
skb_push(skb, sizeof(*iph));
skb_reset_network_header(skb);
iph = ip_hdr(skb);
put_unaligned(0x45, (unsigned char *)iph);
iph->tos = 0;
put_unaligned(htons(ip_len), &(iph->tot_len));
iph->id = htons(atomic_inc_return(&ip_ident));
iph->frag_off = 0;
iph->ttl = 64;
iph->protocol = IPPROTO_UDP;
iph->check = 0;
put_unaligned(np->local_ip.ip, &(iph->saddr));
put_unaligned(np->remote_ip.ip, &(iph->daddr));
iph->check = ip_fast_csum((unsigned char *)iph, iph->ihl);
eth = (struct ethhdr *) skb_push(skb, ETH_HLEN);
skb_reset_mac_header(skb);
skb->protocol = eth->h_proto = htons(ETH_P_IP);
}
ether_addr_copy(eth->h_source, np->dev->dev_addr);
ether_addr_copy(eth->h_dest, np->remote_mac);
skb->dev = np->dev;
netpoll_send_skb(np, skb);
}
void netpoll_print_options(struct netpoll *np)
{
np_info(np, "local port %d\n", np->local_port);
if (np->ipv6)
np_info(np, "local IPv6 address %pI6c\n", &np->local_ip.in6);
else
np_info(np, "local IPv4 address %pI4\n", &np->local_ip.ip);
np_info(np, "interface '%s'\n", np->dev_name);
np_info(np, "remote port %d\n", np->remote_port);
if (np->ipv6)
np_info(np, "remote IPv6 address %pI6c\n", &np->remote_ip.in6);
else
np_info(np, "remote IPv4 address %pI4\n", &np->remote_ip.ip);
np_info(np, "remote ethernet address %pM\n", np->remote_mac);
}
static int netpoll_parse_ip_addr(const char *str, union inet_addr *addr)
{
const char *end;
if (!strchr(str, ':') &&
in4_pton(str, -1, (void *)addr, -1, &end) > 0) {
if (!*end)
return 0;
}
if (in6_pton(str, -1, addr->in6.s6_addr, -1, &end) > 0) {
#if IS_ENABLED(CONFIG_IPV6)
if (!*end)
return 1;
#else
return -1;
#endif
}
return -1;
}
int netpoll_parse_options(struct netpoll *np, char *opt)
{
char *cur=opt, *delim;
int ipv6;
bool ipversion_set = false;
if (*cur != '@') {
if ((delim = strchr(cur, '@')) == NULL)
goto parse_failed;
*delim = 0;
if (kstrtou16(cur, 10, &np->local_port))
goto parse_failed;
cur = delim;
}
cur++;
if (*cur != '/') {
ipversion_set = true;
if ((delim = strchr(cur, '/')) == NULL)
goto parse_failed;
*delim = 0;
ipv6 = netpoll_parse_ip_addr(cur, &np->local_ip);
if (ipv6 < 0)
goto parse_failed;
else
np->ipv6 = (bool)ipv6;
cur = delim;
}
cur++;
if (*cur != ',') {
if ((delim = strchr(cur, ',')) == NULL)
goto parse_failed;
*delim = 0;
strlcpy(np->dev_name, cur, sizeof(np->dev_name));
cur = delim;
}
cur++;
if (*cur != '@') {
if ((delim = strchr(cur, '@')) == NULL)
goto parse_failed;
*delim = 0;
if (*cur == ' ' || *cur == '\t')
np_info(np, "warning: whitespace is not allowed\n");
if (kstrtou16(cur, 10, &np->remote_port))
goto parse_failed;
cur = delim;
}
cur++;
if ((delim = strchr(cur, '/')) == NULL)
goto parse_failed;
*delim = 0;
ipv6 = netpoll_parse_ip_addr(cur, &np->remote_ip);
if (ipv6 < 0)
goto parse_failed;
else if (ipversion_set && np->ipv6 != (bool)ipv6)
goto parse_failed;
else
np->ipv6 = (bool)ipv6;
cur = delim + 1;
if (*cur != 0) {
if (!mac_pton(cur, np->remote_mac))
goto parse_failed;
}
netpoll_print_options(np);
return 0;
parse_failed:
np_info(np, "couldn't parse config at '%s'!\n", cur);
return -1;
}
int __netpoll_setup(struct netpoll *np, struct net_device *ndev)
{
struct netpoll_info *npinfo;
const struct net_device_ops *ops;
int err;
np->dev = ndev;
strlcpy(np->dev_name, ndev->name, IFNAMSIZ);
INIT_WORK(&np->cleanup_work, netpoll_async_cleanup);
if ((ndev->priv_flags & IFF_DISABLE_NETPOLL) ||
!ndev->netdev_ops->ndo_poll_controller) {
np_err(np, "%s doesn't support polling, aborting\n",
np->dev_name);
err = -ENOTSUPP;
goto out;
}
if (!ndev->npinfo) {
npinfo = kmalloc(sizeof(*npinfo), GFP_KERNEL);
if (!npinfo) {
err = -ENOMEM;
goto out;
}
sema_init(&npinfo->dev_lock, 1);
skb_queue_head_init(&npinfo->txq);
INIT_DELAYED_WORK(&npinfo->tx_work, queue_process);
atomic_set(&npinfo->refcnt, 1);
ops = np->dev->netdev_ops;
if (ops->ndo_netpoll_setup) {
err = ops->ndo_netpoll_setup(ndev, npinfo);
if (err)
goto free_npinfo;
}
} else {
npinfo = rtnl_dereference(ndev->npinfo);
atomic_inc(&npinfo->refcnt);
}
npinfo->netpoll = np;
rcu_assign_pointer(ndev->npinfo, npinfo);
return 0;
free_npinfo:
kfree(npinfo);
out:
return err;
}
int netpoll_setup(struct netpoll *np)
{
struct net_device *ndev = NULL;
struct in_device *in_dev;
int err;
rtnl_lock();
if (np->dev_name) {
struct net *net = current->nsproxy->net_ns;
ndev = __dev_get_by_name(net, np->dev_name);
}
if (!ndev) {
np_err(np, "%s doesn't exist, aborting\n", np->dev_name);
err = -ENODEV;
goto unlock;
}
dev_hold(ndev);
if (netdev_master_upper_dev_get(ndev)) {
np_err(np, "%s is a slave device, aborting\n", np->dev_name);
err = -EBUSY;
goto put;
}
if (!netif_running(ndev)) {
unsigned long atmost, atleast;
np_info(np, "device %s not up yet, forcing it\n", np->dev_name);
err = dev_open(ndev);
if (err) {
np_err(np, "failed to open %s\n", ndev->name);
goto put;
}
rtnl_unlock();
atleast = jiffies + HZ/10;
atmost = jiffies + carrier_timeout * HZ;
while (!netif_carrier_ok(ndev)) {
if (time_after(jiffies, atmost)) {
np_notice(np, "timeout waiting for carrier\n");
break;
}
msleep(1);
}
if (time_before(jiffies, atleast)) {
np_notice(np, "carrier detect appears untrustworthy, waiting 4 seconds\n");
msleep(4000);
}
rtnl_lock();
}
if (!np->local_ip.ip) {
if (!np->ipv6) {
in_dev = __in_dev_get_rtnl(ndev);
if (!in_dev || !in_dev->ifa_list) {
np_err(np, "no IP address for %s, aborting\n",
np->dev_name);
err = -EDESTADDRREQ;
goto put;
}
np->local_ip.ip = in_dev->ifa_list->ifa_local;
np_info(np, "local IP %pI4\n", &np->local_ip.ip);
} else {
#if IS_ENABLED(CONFIG_IPV6)
struct inet6_dev *idev;
err = -EDESTADDRREQ;
idev = __in6_dev_get(ndev);
if (idev) {
struct inet6_ifaddr *ifp;
read_lock_bh(&idev->lock);
list_for_each_entry(ifp, &idev->addr_list, if_list) {
if (ipv6_addr_type(&ifp->addr) & IPV6_ADDR_LINKLOCAL)
continue;
np->local_ip.in6 = ifp->addr;
err = 0;
break;
}
read_unlock_bh(&idev->lock);
}
if (err) {
np_err(np, "no IPv6 address for %s, aborting\n",
np->dev_name);
goto put;
} else
np_info(np, "local IPv6 %pI6c\n", &np->local_ip.in6);
#else
np_err(np, "IPv6 is not supported %s, aborting\n",
np->dev_name);
err = -EINVAL;
goto put;
#endif
}
}
refill_skbs();
err = __netpoll_setup(np, ndev);
if (err)
goto put;
rtnl_unlock();
return 0;
put:
dev_put(ndev);
unlock:
rtnl_unlock();
return err;
}
static int __init netpoll_init(void)
{
skb_queue_head_init(&skb_pool);
return 0;
}
static void rcu_cleanup_netpoll_info(struct rcu_head *rcu_head)
{
struct netpoll_info *npinfo =
container_of(rcu_head, struct netpoll_info, rcu);
skb_queue_purge(&npinfo->txq);
cancel_delayed_work(&npinfo->tx_work);
__skb_queue_purge(&npinfo->txq);
cancel_delayed_work(&npinfo->tx_work);
kfree(npinfo);
}
void __netpoll_cleanup(struct netpoll *np)
{
struct netpoll_info *npinfo;
npinfo = rtnl_dereference(np->dev->npinfo);
if (!npinfo)
return;
synchronize_srcu(&netpoll_srcu);
if (atomic_dec_and_test(&npinfo->refcnt)) {
const struct net_device_ops *ops;
ops = np->dev->netdev_ops;
if (ops->ndo_netpoll_cleanup)
ops->ndo_netpoll_cleanup(np->dev);
RCU_INIT_POINTER(np->dev->npinfo, NULL);
call_rcu_bh(&npinfo->rcu, rcu_cleanup_netpoll_info);
} else
RCU_INIT_POINTER(np->dev->npinfo, NULL);
}
static void netpoll_async_cleanup(struct work_struct *work)
{
struct netpoll *np = container_of(work, struct netpoll, cleanup_work);
rtnl_lock();
__netpoll_cleanup(np);
rtnl_unlock();
kfree(np);
}
void __netpoll_free_async(struct netpoll *np)
{
schedule_work(&np->cleanup_work);
}
void netpoll_cleanup(struct netpoll *np)
{
rtnl_lock();
if (!np->dev)
goto out;
__netpoll_cleanup(np);
dev_put(np->dev);
np->dev = NULL;
out:
rtnl_unlock();
}
