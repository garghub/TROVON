static struct mr6_table *ip6mr_get_table(struct net *net, u32 id)
{
struct mr6_table *mrt;
ip6mr_for_each_table(mrt, net) {
if (mrt->id == id)
return mrt;
}
return NULL;
}
static int ip6mr_fib_lookup(struct net *net, struct flowi6 *flp6,
struct mr6_table **mrt)
{
int err;
struct ip6mr_result res;
struct fib_lookup_arg arg = {
.result = &res,
.flags = FIB_LOOKUP_NOREF,
};
err = fib_rules_lookup(net->ipv6.mr6_rules_ops,
flowi6_to_flowi(flp6), 0, &arg);
if (err < 0)
return err;
*mrt = res.mrt;
return 0;
}
static int ip6mr_rule_action(struct fib_rule *rule, struct flowi *flp,
int flags, struct fib_lookup_arg *arg)
{
struct ip6mr_result *res = arg->result;
struct mr6_table *mrt;
switch (rule->action) {
case FR_ACT_TO_TBL:
break;
case FR_ACT_UNREACHABLE:
return -ENETUNREACH;
case FR_ACT_PROHIBIT:
return -EACCES;
case FR_ACT_BLACKHOLE:
default:
return -EINVAL;
}
mrt = ip6mr_get_table(rule->fr_net, rule->table);
if (mrt == NULL)
return -EAGAIN;
res->mrt = mrt;
return 0;
}
static int ip6mr_rule_match(struct fib_rule *rule, struct flowi *flp, int flags)
{
return 1;
}
static int ip6mr_rule_configure(struct fib_rule *rule, struct sk_buff *skb,
struct fib_rule_hdr *frh, struct nlattr **tb)
{
return 0;
}
static int ip6mr_rule_compare(struct fib_rule *rule, struct fib_rule_hdr *frh,
struct nlattr **tb)
{
return 1;
}
static int ip6mr_rule_fill(struct fib_rule *rule, struct sk_buff *skb,
struct fib_rule_hdr *frh)
{
frh->dst_len = 0;
frh->src_len = 0;
frh->tos = 0;
return 0;
}
static int __net_init ip6mr_rules_init(struct net *net)
{
struct fib_rules_ops *ops;
struct mr6_table *mrt;
int err;
ops = fib_rules_register(&ip6mr_rules_ops_template, net);
if (IS_ERR(ops))
return PTR_ERR(ops);
INIT_LIST_HEAD(&net->ipv6.mr6_tables);
mrt = ip6mr_new_table(net, RT6_TABLE_DFLT);
if (mrt == NULL) {
err = -ENOMEM;
goto err1;
}
err = fib_default_rule_add(ops, 0x7fff, RT6_TABLE_DFLT, 0);
if (err < 0)
goto err2;
net->ipv6.mr6_rules_ops = ops;
return 0;
err2:
kfree(mrt);
err1:
fib_rules_unregister(ops);
return err;
}
static void __net_exit ip6mr_rules_exit(struct net *net)
{
struct mr6_table *mrt, *next;
rtnl_lock();
list_for_each_entry_safe(mrt, next, &net->ipv6.mr6_tables, list) {
list_del(&mrt->list);
ip6mr_free_table(mrt);
}
rtnl_unlock();
fib_rules_unregister(net->ipv6.mr6_rules_ops);
}
static struct mr6_table *ip6mr_get_table(struct net *net, u32 id)
{
return net->ipv6.mrt6;
}
static int ip6mr_fib_lookup(struct net *net, struct flowi6 *flp6,
struct mr6_table **mrt)
{
*mrt = net->ipv6.mrt6;
return 0;
}
static int __net_init ip6mr_rules_init(struct net *net)
{
net->ipv6.mrt6 = ip6mr_new_table(net, RT6_TABLE_DFLT);
return net->ipv6.mrt6 ? 0 : -ENOMEM;
}
static void __net_exit ip6mr_rules_exit(struct net *net)
{
rtnl_lock();
ip6mr_free_table(net->ipv6.mrt6);
net->ipv6.mrt6 = NULL;
rtnl_unlock();
}
static struct mr6_table *ip6mr_new_table(struct net *net, u32 id)
{
struct mr6_table *mrt;
unsigned int i;
mrt = ip6mr_get_table(net, id);
if (mrt != NULL)
return mrt;
mrt = kzalloc(sizeof(*mrt), GFP_KERNEL);
if (mrt == NULL)
return NULL;
mrt->id = id;
write_pnet(&mrt->net, net);
for (i = 0; i < MFC6_LINES; i++)
INIT_LIST_HEAD(&mrt->mfc6_cache_array[i]);
INIT_LIST_HEAD(&mrt->mfc6_unres_queue);
setup_timer(&mrt->ipmr_expire_timer, ipmr_expire_process,
(unsigned long)mrt);
#ifdef CONFIG_IPV6_PIMSM_V2
mrt->mroute_reg_vif_num = -1;
#endif
#ifdef CONFIG_IPV6_MROUTE_MULTIPLE_TABLES
list_add_tail_rcu(&mrt->list, &net->ipv6.mr6_tables);
#endif
return mrt;
}
static void ip6mr_free_table(struct mr6_table *mrt)
{
del_timer(&mrt->ipmr_expire_timer);
mroute_clean_tables(mrt);
kfree(mrt);
}
static struct mfc6_cache *ipmr_mfc_seq_idx(struct net *net,
struct ipmr_mfc_iter *it, loff_t pos)
{
struct mr6_table *mrt = it->mrt;
struct mfc6_cache *mfc;
read_lock(&mrt_lock);
for (it->ct = 0; it->ct < MFC6_LINES; it->ct++) {
it->cache = &mrt->mfc6_cache_array[it->ct];
list_for_each_entry(mfc, it->cache, list)
if (pos-- == 0)
return mfc;
}
read_unlock(&mrt_lock);
spin_lock_bh(&mfc_unres_lock);
it->cache = &mrt->mfc6_unres_queue;
list_for_each_entry(mfc, it->cache, list)
if (pos-- == 0)
return mfc;
spin_unlock_bh(&mfc_unres_lock);
it->cache = NULL;
return NULL;
}
static struct mif_device *ip6mr_vif_seq_idx(struct net *net,
struct ipmr_vif_iter *iter,
loff_t pos)
{
struct mr6_table *mrt = iter->mrt;
for (iter->ct = 0; iter->ct < mrt->maxvif; ++iter->ct) {
if (!MIF_EXISTS(mrt, iter->ct))
continue;
if (pos-- == 0)
return &mrt->vif6_table[iter->ct];
}
return NULL;
}
static void *ip6mr_vif_seq_start(struct seq_file *seq, loff_t *pos)
__acquires(mrt_lock)
{
struct ipmr_vif_iter *iter = seq->private;
struct net *net = seq_file_net(seq);
struct mr6_table *mrt;
mrt = ip6mr_get_table(net, RT6_TABLE_DFLT);
if (mrt == NULL)
return ERR_PTR(-ENOENT);
iter->mrt = mrt;
read_lock(&mrt_lock);
return *pos ? ip6mr_vif_seq_idx(net, seq->private, *pos - 1)
: SEQ_START_TOKEN;
}
static void *ip6mr_vif_seq_next(struct seq_file *seq, void *v, loff_t *pos)
{
struct ipmr_vif_iter *iter = seq->private;
struct net *net = seq_file_net(seq);
struct mr6_table *mrt = iter->mrt;
++*pos;
if (v == SEQ_START_TOKEN)
return ip6mr_vif_seq_idx(net, iter, 0);
while (++iter->ct < mrt->maxvif) {
if (!MIF_EXISTS(mrt, iter->ct))
continue;
return &mrt->vif6_table[iter->ct];
}
return NULL;
}
static void ip6mr_vif_seq_stop(struct seq_file *seq, void *v)
__releases(mrt_lock)
{
read_unlock(&mrt_lock);
}
static int ip6mr_vif_seq_show(struct seq_file *seq, void *v)
{
struct ipmr_vif_iter *iter = seq->private;
struct mr6_table *mrt = iter->mrt;
if (v == SEQ_START_TOKEN) {
seq_puts(seq,
"Interface BytesIn PktsIn BytesOut PktsOut Flags\n");
} else {
const struct mif_device *vif = v;
const char *name = vif->dev ? vif->dev->name : "none";
seq_printf(seq,
"%2td %-10s %8ld %7ld %8ld %7ld %05X\n",
vif - mrt->vif6_table,
name, vif->bytes_in, vif->pkt_in,
vif->bytes_out, vif->pkt_out,
vif->flags);
}
return 0;
}
static int ip6mr_vif_open(struct inode *inode, struct file *file)
{
return seq_open_net(inode, file, &ip6mr_vif_seq_ops,
sizeof(struct ipmr_vif_iter));
}
static void *ipmr_mfc_seq_start(struct seq_file *seq, loff_t *pos)
{
struct ipmr_mfc_iter *it = seq->private;
struct net *net = seq_file_net(seq);
struct mr6_table *mrt;
mrt = ip6mr_get_table(net, RT6_TABLE_DFLT);
if (mrt == NULL)
return ERR_PTR(-ENOENT);
it->mrt = mrt;
return *pos ? ipmr_mfc_seq_idx(net, seq->private, *pos - 1)
: SEQ_START_TOKEN;
}
static void *ipmr_mfc_seq_next(struct seq_file *seq, void *v, loff_t *pos)
{
struct mfc6_cache *mfc = v;
struct ipmr_mfc_iter *it = seq->private;
struct net *net = seq_file_net(seq);
struct mr6_table *mrt = it->mrt;
++*pos;
if (v == SEQ_START_TOKEN)
return ipmr_mfc_seq_idx(net, seq->private, 0);
if (mfc->list.next != it->cache)
return list_entry(mfc->list.next, struct mfc6_cache, list);
if (it->cache == &mrt->mfc6_unres_queue)
goto end_of_list;
BUG_ON(it->cache != &mrt->mfc6_cache_array[it->ct]);
while (++it->ct < MFC6_LINES) {
it->cache = &mrt->mfc6_cache_array[it->ct];
if (list_empty(it->cache))
continue;
return list_first_entry(it->cache, struct mfc6_cache, list);
}
read_unlock(&mrt_lock);
it->cache = &mrt->mfc6_unres_queue;
it->ct = 0;
spin_lock_bh(&mfc_unres_lock);
if (!list_empty(it->cache))
return list_first_entry(it->cache, struct mfc6_cache, list);
end_of_list:
spin_unlock_bh(&mfc_unres_lock);
it->cache = NULL;
return NULL;
}
static void ipmr_mfc_seq_stop(struct seq_file *seq, void *v)
{
struct ipmr_mfc_iter *it = seq->private;
struct mr6_table *mrt = it->mrt;
if (it->cache == &mrt->mfc6_unres_queue)
spin_unlock_bh(&mfc_unres_lock);
else if (it->cache == mrt->mfc6_cache_array)
read_unlock(&mrt_lock);
}
static int ipmr_mfc_seq_show(struct seq_file *seq, void *v)
{
int n;
if (v == SEQ_START_TOKEN) {
seq_puts(seq,
"Group "
"Origin "
"Iif Pkts Bytes Wrong Oifs\n");
} else {
const struct mfc6_cache *mfc = v;
const struct ipmr_mfc_iter *it = seq->private;
struct mr6_table *mrt = it->mrt;
seq_printf(seq, "%pI6 %pI6 %-3hd",
&mfc->mf6c_mcastgrp, &mfc->mf6c_origin,
mfc->mf6c_parent);
if (it->cache != &mrt->mfc6_unres_queue) {
seq_printf(seq, " %8lu %8lu %8lu",
mfc->mfc_un.res.pkt,
mfc->mfc_un.res.bytes,
mfc->mfc_un.res.wrong_if);
for (n = mfc->mfc_un.res.minvif;
n < mfc->mfc_un.res.maxvif; n++) {
if (MIF_EXISTS(mrt, n) &&
mfc->mfc_un.res.ttls[n] < 255)
seq_printf(seq,
" %2d:%-3d",
n, mfc->mfc_un.res.ttls[n]);
}
} else {
seq_printf(seq, " %8lu %8lu %8lu", 0ul, 0ul, 0ul);
}
seq_putc(seq, '\n');
}
return 0;
}
static int ipmr_mfc_open(struct inode *inode, struct file *file)
{
return seq_open_net(inode, file, &ipmr_mfc_seq_ops,
sizeof(struct ipmr_mfc_iter));
}
static int pim6_rcv(struct sk_buff *skb)
{
struct pimreghdr *pim;
struct ipv6hdr *encap;
struct net_device *reg_dev = NULL;
struct net *net = dev_net(skb->dev);
struct mr6_table *mrt;
struct flowi6 fl6 = {
.flowi6_iif = skb->dev->ifindex,
.flowi6_mark = skb->mark,
};
int reg_vif_num;
if (!pskb_may_pull(skb, sizeof(*pim) + sizeof(*encap)))
goto drop;
pim = (struct pimreghdr *)skb_transport_header(skb);
if (pim->type != ((PIM_VERSION << 4) | PIM_REGISTER) ||
(pim->flags & PIM_NULL_REGISTER) ||
(csum_ipv6_magic(&ipv6_hdr(skb)->saddr, &ipv6_hdr(skb)->daddr,
sizeof(*pim), IPPROTO_PIM,
csum_partial((void *)pim, sizeof(*pim), 0)) &&
csum_fold(skb_checksum(skb, 0, skb->len, 0))))
goto drop;
encap = (struct ipv6hdr *)(skb_transport_header(skb) +
sizeof(*pim));
if (!ipv6_addr_is_multicast(&encap->daddr) ||
encap->payload_len == 0 ||
ntohs(encap->payload_len) + sizeof(*pim) > skb->len)
goto drop;
if (ip6mr_fib_lookup(net, &fl6, &mrt) < 0)
goto drop;
reg_vif_num = mrt->mroute_reg_vif_num;
read_lock(&mrt_lock);
if (reg_vif_num >= 0)
reg_dev = mrt->vif6_table[reg_vif_num].dev;
if (reg_dev)
dev_hold(reg_dev);
read_unlock(&mrt_lock);
if (reg_dev == NULL)
goto drop;
skb->mac_header = skb->network_header;
skb_pull(skb, (u8 *)encap - skb->data);
skb_reset_network_header(skb);
skb->protocol = htons(ETH_P_IPV6);
skb->ip_summed = CHECKSUM_NONE;
skb_tunnel_rx(skb, reg_dev, dev_net(reg_dev));
netif_rx(skb);
dev_put(reg_dev);
return 0;
drop:
kfree_skb(skb);
return 0;
}
static netdev_tx_t reg_vif_xmit(struct sk_buff *skb,
struct net_device *dev)
{
struct net *net = dev_net(dev);
struct mr6_table *mrt;
struct flowi6 fl6 = {
.flowi6_oif = dev->ifindex,
.flowi6_iif = skb->skb_iif ? : LOOPBACK_IFINDEX,
.flowi6_mark = skb->mark,
};
int err;
err = ip6mr_fib_lookup(net, &fl6, &mrt);
if (err < 0) {
kfree_skb(skb);
return err;
}
read_lock(&mrt_lock);
dev->stats.tx_bytes += skb->len;
dev->stats.tx_packets++;
ip6mr_cache_report(mrt, skb, mrt->mroute_reg_vif_num, MRT6MSG_WHOLEPKT);
read_unlock(&mrt_lock);
kfree_skb(skb);
return NETDEV_TX_OK;
}
static void reg_vif_setup(struct net_device *dev)
{
dev->type = ARPHRD_PIMREG;
dev->mtu = 1500 - sizeof(struct ipv6hdr) - 8;
dev->flags = IFF_NOARP;
dev->netdev_ops = &reg_vif_netdev_ops;
dev->destructor = free_netdev;
dev->features |= NETIF_F_NETNS_LOCAL;
}
static struct net_device *ip6mr_reg_vif(struct net *net, struct mr6_table *mrt)
{
struct net_device *dev;
char name[IFNAMSIZ];
if (mrt->id == RT6_TABLE_DFLT)
sprintf(name, "pim6reg");
else
sprintf(name, "pim6reg%u", mrt->id);
dev = alloc_netdev(0, name, NET_NAME_UNKNOWN, reg_vif_setup);
if (dev == NULL)
return NULL;
dev_net_set(dev, net);
if (register_netdevice(dev)) {
free_netdev(dev);
return NULL;
}
dev->iflink = 0;
if (dev_open(dev))
goto failure;
dev_hold(dev);
return dev;
failure:
rtnl_unlock();
rtnl_lock();
unregister_netdevice(dev);
return NULL;
}
static int mif6_delete(struct mr6_table *mrt, int vifi, struct list_head *head)
{
struct mif_device *v;
struct net_device *dev;
struct inet6_dev *in6_dev;
if (vifi < 0 || vifi >= mrt->maxvif)
return -EADDRNOTAVAIL;
v = &mrt->vif6_table[vifi];
write_lock_bh(&mrt_lock);
dev = v->dev;
v->dev = NULL;
if (!dev) {
write_unlock_bh(&mrt_lock);
return -EADDRNOTAVAIL;
}
#ifdef CONFIG_IPV6_PIMSM_V2
if (vifi == mrt->mroute_reg_vif_num)
mrt->mroute_reg_vif_num = -1;
#endif
if (vifi + 1 == mrt->maxvif) {
int tmp;
for (tmp = vifi - 1; tmp >= 0; tmp--) {
if (MIF_EXISTS(mrt, tmp))
break;
}
mrt->maxvif = tmp + 1;
}
write_unlock_bh(&mrt_lock);
dev_set_allmulti(dev, -1);
in6_dev = __in6_dev_get(dev);
if (in6_dev) {
in6_dev->cnf.mc_forwarding--;
inet6_netconf_notify_devconf(dev_net(dev),
NETCONFA_MC_FORWARDING,
dev->ifindex, &in6_dev->cnf);
}
if (v->flags & MIFF_REGISTER)
unregister_netdevice_queue(dev, head);
dev_put(dev);
return 0;
}
static inline void ip6mr_cache_free(struct mfc6_cache *c)
{
kmem_cache_free(mrt_cachep, c);
}
static void ip6mr_destroy_unres(struct mr6_table *mrt, struct mfc6_cache *c)
{
struct net *net = read_pnet(&mrt->net);
struct sk_buff *skb;
atomic_dec(&mrt->cache_resolve_queue_len);
while ((skb = skb_dequeue(&c->mfc_un.unres.unresolved)) != NULL) {
if (ipv6_hdr(skb)->version == 0) {
struct nlmsghdr *nlh = (struct nlmsghdr *)skb_pull(skb, sizeof(struct ipv6hdr));
nlh->nlmsg_type = NLMSG_ERROR;
nlh->nlmsg_len = nlmsg_msg_size(sizeof(struct nlmsgerr));
skb_trim(skb, nlh->nlmsg_len);
((struct nlmsgerr *)nlmsg_data(nlh))->error = -ETIMEDOUT;
rtnl_unicast(skb, net, NETLINK_CB(skb).portid);
} else
kfree_skb(skb);
}
ip6mr_cache_free(c);
}
static void ipmr_do_expire_process(struct mr6_table *mrt)
{
unsigned long now = jiffies;
unsigned long expires = 10 * HZ;
struct mfc6_cache *c, *next;
list_for_each_entry_safe(c, next, &mrt->mfc6_unres_queue, list) {
if (time_after(c->mfc_un.unres.expires, now)) {
unsigned long interval = c->mfc_un.unres.expires - now;
if (interval < expires)
expires = interval;
continue;
}
list_del(&c->list);
mr6_netlink_event(mrt, c, RTM_DELROUTE);
ip6mr_destroy_unres(mrt, c);
}
if (!list_empty(&mrt->mfc6_unres_queue))
mod_timer(&mrt->ipmr_expire_timer, jiffies + expires);
}
static void ipmr_expire_process(unsigned long arg)
{
struct mr6_table *mrt = (struct mr6_table *)arg;
if (!spin_trylock(&mfc_unres_lock)) {
mod_timer(&mrt->ipmr_expire_timer, jiffies + 1);
return;
}
if (!list_empty(&mrt->mfc6_unres_queue))
ipmr_do_expire_process(mrt);
spin_unlock(&mfc_unres_lock);
}
static void ip6mr_update_thresholds(struct mr6_table *mrt, struct mfc6_cache *cache,
unsigned char *ttls)
{
int vifi;
cache->mfc_un.res.minvif = MAXMIFS;
cache->mfc_un.res.maxvif = 0;
memset(cache->mfc_un.res.ttls, 255, MAXMIFS);
for (vifi = 0; vifi < mrt->maxvif; vifi++) {
if (MIF_EXISTS(mrt, vifi) &&
ttls[vifi] && ttls[vifi] < 255) {
cache->mfc_un.res.ttls[vifi] = ttls[vifi];
if (cache->mfc_un.res.minvif > vifi)
cache->mfc_un.res.minvif = vifi;
if (cache->mfc_un.res.maxvif <= vifi)
cache->mfc_un.res.maxvif = vifi + 1;
}
}
}
static int mif6_add(struct net *net, struct mr6_table *mrt,
struct mif6ctl *vifc, int mrtsock)
{
int vifi = vifc->mif6c_mifi;
struct mif_device *v = &mrt->vif6_table[vifi];
struct net_device *dev;
struct inet6_dev *in6_dev;
int err;
if (MIF_EXISTS(mrt, vifi))
return -EADDRINUSE;
switch (vifc->mif6c_flags) {
#ifdef CONFIG_IPV6_PIMSM_V2
case MIFF_REGISTER:
if (mrt->mroute_reg_vif_num >= 0)
return -EADDRINUSE;
dev = ip6mr_reg_vif(net, mrt);
if (!dev)
return -ENOBUFS;
err = dev_set_allmulti(dev, 1);
if (err) {
unregister_netdevice(dev);
dev_put(dev);
return err;
}
break;
#endif
case 0:
dev = dev_get_by_index(net, vifc->mif6c_pifi);
if (!dev)
return -EADDRNOTAVAIL;
err = dev_set_allmulti(dev, 1);
if (err) {
dev_put(dev);
return err;
}
break;
default:
return -EINVAL;
}
in6_dev = __in6_dev_get(dev);
if (in6_dev) {
in6_dev->cnf.mc_forwarding++;
inet6_netconf_notify_devconf(dev_net(dev),
NETCONFA_MC_FORWARDING,
dev->ifindex, &in6_dev->cnf);
}
v->rate_limit = vifc->vifc_rate_limit;
v->flags = vifc->mif6c_flags;
if (!mrtsock)
v->flags |= VIFF_STATIC;
v->threshold = vifc->vifc_threshold;
v->bytes_in = 0;
v->bytes_out = 0;
v->pkt_in = 0;
v->pkt_out = 0;
v->link = dev->ifindex;
if (v->flags & MIFF_REGISTER)
v->link = dev->iflink;
write_lock_bh(&mrt_lock);
v->dev = dev;
#ifdef CONFIG_IPV6_PIMSM_V2
if (v->flags & MIFF_REGISTER)
mrt->mroute_reg_vif_num = vifi;
#endif
if (vifi + 1 > mrt->maxvif)
mrt->maxvif = vifi + 1;
write_unlock_bh(&mrt_lock);
return 0;
}
static struct mfc6_cache *ip6mr_cache_find(struct mr6_table *mrt,
const struct in6_addr *origin,
const struct in6_addr *mcastgrp)
{
int line = MFC6_HASH(mcastgrp, origin);
struct mfc6_cache *c;
list_for_each_entry(c, &mrt->mfc6_cache_array[line], list) {
if (ipv6_addr_equal(&c->mf6c_origin, origin) &&
ipv6_addr_equal(&c->mf6c_mcastgrp, mcastgrp))
return c;
}
return NULL;
}
static struct mfc6_cache *ip6mr_cache_find_any_parent(struct mr6_table *mrt,
mifi_t mifi)
{
int line = MFC6_HASH(&in6addr_any, &in6addr_any);
struct mfc6_cache *c;
list_for_each_entry(c, &mrt->mfc6_cache_array[line], list)
if (ipv6_addr_any(&c->mf6c_origin) &&
ipv6_addr_any(&c->mf6c_mcastgrp) &&
(c->mfc_un.res.ttls[mifi] < 255))
return c;
return NULL;
}
static struct mfc6_cache *ip6mr_cache_find_any(struct mr6_table *mrt,
struct in6_addr *mcastgrp,
mifi_t mifi)
{
int line = MFC6_HASH(mcastgrp, &in6addr_any);
struct mfc6_cache *c, *proxy;
if (ipv6_addr_any(mcastgrp))
goto skip;
list_for_each_entry(c, &mrt->mfc6_cache_array[line], list)
if (ipv6_addr_any(&c->mf6c_origin) &&
ipv6_addr_equal(&c->mf6c_mcastgrp, mcastgrp)) {
if (c->mfc_un.res.ttls[mifi] < 255)
return c;
proxy = ip6mr_cache_find_any_parent(mrt,
c->mf6c_parent);
if (proxy && proxy->mfc_un.res.ttls[mifi] < 255)
return c;
}
skip:
return ip6mr_cache_find_any_parent(mrt, mifi);
}
static struct mfc6_cache *ip6mr_cache_alloc(void)
{
struct mfc6_cache *c = kmem_cache_zalloc(mrt_cachep, GFP_KERNEL);
if (c == NULL)
return NULL;
c->mfc_un.res.minvif = MAXMIFS;
return c;
}
static struct mfc6_cache *ip6mr_cache_alloc_unres(void)
{
struct mfc6_cache *c = kmem_cache_zalloc(mrt_cachep, GFP_ATOMIC);
if (c == NULL)
return NULL;
skb_queue_head_init(&c->mfc_un.unres.unresolved);
c->mfc_un.unres.expires = jiffies + 10 * HZ;
return c;
}
static void ip6mr_cache_resolve(struct net *net, struct mr6_table *mrt,
struct mfc6_cache *uc, struct mfc6_cache *c)
{
struct sk_buff *skb;
while ((skb = __skb_dequeue(&uc->mfc_un.unres.unresolved))) {
if (ipv6_hdr(skb)->version == 0) {
struct nlmsghdr *nlh = (struct nlmsghdr *)skb_pull(skb, sizeof(struct ipv6hdr));
if (__ip6mr_fill_mroute(mrt, skb, c, nlmsg_data(nlh)) > 0) {
nlh->nlmsg_len = skb_tail_pointer(skb) - (u8 *)nlh;
} else {
nlh->nlmsg_type = NLMSG_ERROR;
nlh->nlmsg_len = nlmsg_msg_size(sizeof(struct nlmsgerr));
skb_trim(skb, nlh->nlmsg_len);
((struct nlmsgerr *)nlmsg_data(nlh))->error = -EMSGSIZE;
}
rtnl_unicast(skb, net, NETLINK_CB(skb).portid);
} else
ip6_mr_forward(net, mrt, skb, c);
}
}
static int ip6mr_cache_report(struct mr6_table *mrt, struct sk_buff *pkt,
mifi_t mifi, int assert)
{
struct sk_buff *skb;
struct mrt6msg *msg;
int ret;
#ifdef CONFIG_IPV6_PIMSM_V2
if (assert == MRT6MSG_WHOLEPKT)
skb = skb_realloc_headroom(pkt, -skb_network_offset(pkt)
+sizeof(*msg));
else
#endif
skb = alloc_skb(sizeof(struct ipv6hdr) + sizeof(*msg), GFP_ATOMIC);
if (!skb)
return -ENOBUFS;
skb->ip_summed = CHECKSUM_UNNECESSARY;
#ifdef CONFIG_IPV6_PIMSM_V2
if (assert == MRT6MSG_WHOLEPKT) {
skb_push(skb, -skb_network_offset(pkt));
skb_push(skb, sizeof(*msg));
skb_reset_transport_header(skb);
msg = (struct mrt6msg *)skb_transport_header(skb);
msg->im6_mbz = 0;
msg->im6_msgtype = MRT6MSG_WHOLEPKT;
msg->im6_mif = mrt->mroute_reg_vif_num;
msg->im6_pad = 0;
msg->im6_src = ipv6_hdr(pkt)->saddr;
msg->im6_dst = ipv6_hdr(pkt)->daddr;
skb->ip_summed = CHECKSUM_UNNECESSARY;
} else
#endif
{
skb_put(skb, sizeof(struct ipv6hdr));
skb_reset_network_header(skb);
skb_copy_to_linear_data(skb, ipv6_hdr(pkt), sizeof(struct ipv6hdr));
skb_put(skb, sizeof(*msg));
skb_reset_transport_header(skb);
msg = (struct mrt6msg *)skb_transport_header(skb);
msg->im6_mbz = 0;
msg->im6_msgtype = assert;
msg->im6_mif = mifi;
msg->im6_pad = 0;
msg->im6_src = ipv6_hdr(pkt)->saddr;
msg->im6_dst = ipv6_hdr(pkt)->daddr;
skb_dst_set(skb, dst_clone(skb_dst(pkt)));
skb->ip_summed = CHECKSUM_UNNECESSARY;
}
if (mrt->mroute6_sk == NULL) {
kfree_skb(skb);
return -EINVAL;
}
ret = sock_queue_rcv_skb(mrt->mroute6_sk, skb);
if (ret < 0) {
net_warn_ratelimited("mroute6: pending queue full, dropping entries\n");
kfree_skb(skb);
}
return ret;
}
static int
ip6mr_cache_unresolved(struct mr6_table *mrt, mifi_t mifi, struct sk_buff *skb)
{
bool found = false;
int err;
struct mfc6_cache *c;
spin_lock_bh(&mfc_unres_lock);
list_for_each_entry(c, &mrt->mfc6_unres_queue, list) {
if (ipv6_addr_equal(&c->mf6c_mcastgrp, &ipv6_hdr(skb)->daddr) &&
ipv6_addr_equal(&c->mf6c_origin, &ipv6_hdr(skb)->saddr)) {
found = true;
break;
}
}
if (!found) {
if (atomic_read(&mrt->cache_resolve_queue_len) >= 10 ||
(c = ip6mr_cache_alloc_unres()) == NULL) {
spin_unlock_bh(&mfc_unres_lock);
kfree_skb(skb);
return -ENOBUFS;
}
c->mf6c_parent = -1;
c->mf6c_origin = ipv6_hdr(skb)->saddr;
c->mf6c_mcastgrp = ipv6_hdr(skb)->daddr;
err = ip6mr_cache_report(mrt, skb, mifi, MRT6MSG_NOCACHE);
if (err < 0) {
spin_unlock_bh(&mfc_unres_lock);
ip6mr_cache_free(c);
kfree_skb(skb);
return err;
}
atomic_inc(&mrt->cache_resolve_queue_len);
list_add(&c->list, &mrt->mfc6_unres_queue);
mr6_netlink_event(mrt, c, RTM_NEWROUTE);
ipmr_do_expire_process(mrt);
}
if (c->mfc_un.unres.unresolved.qlen > 3) {
kfree_skb(skb);
err = -ENOBUFS;
} else {
skb_queue_tail(&c->mfc_un.unres.unresolved, skb);
err = 0;
}
spin_unlock_bh(&mfc_unres_lock);
return err;
}
static int ip6mr_mfc_delete(struct mr6_table *mrt, struct mf6cctl *mfc,
int parent)
{
int line;
struct mfc6_cache *c, *next;
line = MFC6_HASH(&mfc->mf6cc_mcastgrp.sin6_addr, &mfc->mf6cc_origin.sin6_addr);
list_for_each_entry_safe(c, next, &mrt->mfc6_cache_array[line], list) {
if (ipv6_addr_equal(&c->mf6c_origin, &mfc->mf6cc_origin.sin6_addr) &&
ipv6_addr_equal(&c->mf6c_mcastgrp,
&mfc->mf6cc_mcastgrp.sin6_addr) &&
(parent == -1 || parent == c->mf6c_parent)) {
write_lock_bh(&mrt_lock);
list_del(&c->list);
write_unlock_bh(&mrt_lock);
mr6_netlink_event(mrt, c, RTM_DELROUTE);
ip6mr_cache_free(c);
return 0;
}
}
return -ENOENT;
}
static int ip6mr_device_event(struct notifier_block *this,
unsigned long event, void *ptr)
{
struct net_device *dev = netdev_notifier_info_to_dev(ptr);
struct net *net = dev_net(dev);
struct mr6_table *mrt;
struct mif_device *v;
int ct;
LIST_HEAD(list);
if (event != NETDEV_UNREGISTER)
return NOTIFY_DONE;
ip6mr_for_each_table(mrt, net) {
v = &mrt->vif6_table[0];
for (ct = 0; ct < mrt->maxvif; ct++, v++) {
if (v->dev == dev)
mif6_delete(mrt, ct, &list);
}
}
unregister_netdevice_many(&list);
return NOTIFY_DONE;
}
static int __net_init ip6mr_net_init(struct net *net)
{
int err;
err = ip6mr_rules_init(net);
if (err < 0)
goto fail;
#ifdef CONFIG_PROC_FS
err = -ENOMEM;
if (!proc_create("ip6_mr_vif", 0, net->proc_net, &ip6mr_vif_fops))
goto proc_vif_fail;
if (!proc_create("ip6_mr_cache", 0, net->proc_net, &ip6mr_mfc_fops))
goto proc_cache_fail;
#endif
return 0;
#ifdef CONFIG_PROC_FS
proc_cache_fail:
remove_proc_entry("ip6_mr_vif", net->proc_net);
proc_vif_fail:
ip6mr_rules_exit(net);
#endif
fail:
return err;
}
static void __net_exit ip6mr_net_exit(struct net *net)
{
#ifdef CONFIG_PROC_FS
remove_proc_entry("ip6_mr_cache", net->proc_net);
remove_proc_entry("ip6_mr_vif", net->proc_net);
#endif
ip6mr_rules_exit(net);
}
int __init ip6_mr_init(void)
{
int err;
mrt_cachep = kmem_cache_create("ip6_mrt_cache",
sizeof(struct mfc6_cache),
0, SLAB_HWCACHE_ALIGN,
NULL);
if (!mrt_cachep)
return -ENOMEM;
err = register_pernet_subsys(&ip6mr_net_ops);
if (err)
goto reg_pernet_fail;
err = register_netdevice_notifier(&ip6_mr_notifier);
if (err)
goto reg_notif_fail;
#ifdef CONFIG_IPV6_PIMSM_V2
if (inet6_add_protocol(&pim6_protocol, IPPROTO_PIM) < 0) {
pr_err("%s: can't add PIM protocol\n", __func__);
err = -EAGAIN;
goto add_proto_fail;
}
#endif
rtnl_register(RTNL_FAMILY_IP6MR, RTM_GETROUTE, NULL,
ip6mr_rtm_dumproute, NULL);
return 0;
#ifdef CONFIG_IPV6_PIMSM_V2
add_proto_fail:
unregister_netdevice_notifier(&ip6_mr_notifier);
#endif
reg_notif_fail:
unregister_pernet_subsys(&ip6mr_net_ops);
reg_pernet_fail:
kmem_cache_destroy(mrt_cachep);
return err;
}
void ip6_mr_cleanup(void)
{
rtnl_unregister(RTNL_FAMILY_IP6MR, RTM_GETROUTE);
#ifdef CONFIG_IPV6_PIMSM_V2
inet6_del_protocol(&pim6_protocol, IPPROTO_PIM);
#endif
unregister_netdevice_notifier(&ip6_mr_notifier);
unregister_pernet_subsys(&ip6mr_net_ops);
kmem_cache_destroy(mrt_cachep);
}
static int ip6mr_mfc_add(struct net *net, struct mr6_table *mrt,
struct mf6cctl *mfc, int mrtsock, int parent)
{
bool found = false;
int line;
struct mfc6_cache *uc, *c;
unsigned char ttls[MAXMIFS];
int i;
if (mfc->mf6cc_parent >= MAXMIFS)
return -ENFILE;
memset(ttls, 255, MAXMIFS);
for (i = 0; i < MAXMIFS; i++) {
if (IF_ISSET(i, &mfc->mf6cc_ifset))
ttls[i] = 1;
}
line = MFC6_HASH(&mfc->mf6cc_mcastgrp.sin6_addr, &mfc->mf6cc_origin.sin6_addr);
list_for_each_entry(c, &mrt->mfc6_cache_array[line], list) {
if (ipv6_addr_equal(&c->mf6c_origin, &mfc->mf6cc_origin.sin6_addr) &&
ipv6_addr_equal(&c->mf6c_mcastgrp,
&mfc->mf6cc_mcastgrp.sin6_addr) &&
(parent == -1 || parent == mfc->mf6cc_parent)) {
found = true;
break;
}
}
if (found) {
write_lock_bh(&mrt_lock);
c->mf6c_parent = mfc->mf6cc_parent;
ip6mr_update_thresholds(mrt, c, ttls);
if (!mrtsock)
c->mfc_flags |= MFC_STATIC;
write_unlock_bh(&mrt_lock);
mr6_netlink_event(mrt, c, RTM_NEWROUTE);
return 0;
}
if (!ipv6_addr_any(&mfc->mf6cc_mcastgrp.sin6_addr) &&
!ipv6_addr_is_multicast(&mfc->mf6cc_mcastgrp.sin6_addr))
return -EINVAL;
c = ip6mr_cache_alloc();
if (c == NULL)
return -ENOMEM;
c->mf6c_origin = mfc->mf6cc_origin.sin6_addr;
c->mf6c_mcastgrp = mfc->mf6cc_mcastgrp.sin6_addr;
c->mf6c_parent = mfc->mf6cc_parent;
ip6mr_update_thresholds(mrt, c, ttls);
if (!mrtsock)
c->mfc_flags |= MFC_STATIC;
write_lock_bh(&mrt_lock);
list_add(&c->list, &mrt->mfc6_cache_array[line]);
write_unlock_bh(&mrt_lock);
found = false;
spin_lock_bh(&mfc_unres_lock);
list_for_each_entry(uc, &mrt->mfc6_unres_queue, list) {
if (ipv6_addr_equal(&uc->mf6c_origin, &c->mf6c_origin) &&
ipv6_addr_equal(&uc->mf6c_mcastgrp, &c->mf6c_mcastgrp)) {
list_del(&uc->list);
atomic_dec(&mrt->cache_resolve_queue_len);
found = true;
break;
}
}
if (list_empty(&mrt->mfc6_unres_queue))
del_timer(&mrt->ipmr_expire_timer);
spin_unlock_bh(&mfc_unres_lock);
if (found) {
ip6mr_cache_resolve(net, mrt, uc, c);
ip6mr_cache_free(uc);
}
mr6_netlink_event(mrt, c, RTM_NEWROUTE);
return 0;
}
static void mroute_clean_tables(struct mr6_table *mrt)
{
int i;
LIST_HEAD(list);
struct mfc6_cache *c, *next;
for (i = 0; i < mrt->maxvif; i++) {
if (!(mrt->vif6_table[i].flags & VIFF_STATIC))
mif6_delete(mrt, i, &list);
}
unregister_netdevice_many(&list);
for (i = 0; i < MFC6_LINES; i++) {
list_for_each_entry_safe(c, next, &mrt->mfc6_cache_array[i], list) {
if (c->mfc_flags & MFC_STATIC)
continue;
write_lock_bh(&mrt_lock);
list_del(&c->list);
write_unlock_bh(&mrt_lock);
mr6_netlink_event(mrt, c, RTM_DELROUTE);
ip6mr_cache_free(c);
}
}
if (atomic_read(&mrt->cache_resolve_queue_len) != 0) {
spin_lock_bh(&mfc_unres_lock);
list_for_each_entry_safe(c, next, &mrt->mfc6_unres_queue, list) {
list_del(&c->list);
mr6_netlink_event(mrt, c, RTM_DELROUTE);
ip6mr_destroy_unres(mrt, c);
}
spin_unlock_bh(&mfc_unres_lock);
}
}
static int ip6mr_sk_init(struct mr6_table *mrt, struct sock *sk)
{
int err = 0;
struct net *net = sock_net(sk);
rtnl_lock();
write_lock_bh(&mrt_lock);
if (likely(mrt->mroute6_sk == NULL)) {
mrt->mroute6_sk = sk;
net->ipv6.devconf_all->mc_forwarding++;
inet6_netconf_notify_devconf(net, NETCONFA_MC_FORWARDING,
NETCONFA_IFINDEX_ALL,
net->ipv6.devconf_all);
}
else
err = -EADDRINUSE;
write_unlock_bh(&mrt_lock);
rtnl_unlock();
return err;
}
int ip6mr_sk_done(struct sock *sk)
{
int err = -EACCES;
struct net *net = sock_net(sk);
struct mr6_table *mrt;
rtnl_lock();
ip6mr_for_each_table(mrt, net) {
if (sk == mrt->mroute6_sk) {
write_lock_bh(&mrt_lock);
mrt->mroute6_sk = NULL;
net->ipv6.devconf_all->mc_forwarding--;
inet6_netconf_notify_devconf(net,
NETCONFA_MC_FORWARDING,
NETCONFA_IFINDEX_ALL,
net->ipv6.devconf_all);
write_unlock_bh(&mrt_lock);
mroute_clean_tables(mrt);
err = 0;
break;
}
}
rtnl_unlock();
return err;
}
struct sock *mroute6_socket(struct net *net, struct sk_buff *skb)
{
struct mr6_table *mrt;
struct flowi6 fl6 = {
.flowi6_iif = skb->skb_iif ? : LOOPBACK_IFINDEX,
.flowi6_oif = skb->dev->ifindex,
.flowi6_mark = skb->mark,
};
if (ip6mr_fib_lookup(net, &fl6, &mrt) < 0)
return NULL;
return mrt->mroute6_sk;
}
int ip6_mroute_setsockopt(struct sock *sk, int optname, char __user *optval, unsigned int optlen)
{
int ret, parent = 0;
struct mif6ctl vif;
struct mf6cctl mfc;
mifi_t mifi;
struct net *net = sock_net(sk);
struct mr6_table *mrt;
mrt = ip6mr_get_table(net, raw6_sk(sk)->ip6mr_table ? : RT6_TABLE_DFLT);
if (mrt == NULL)
return -ENOENT;
if (optname != MRT6_INIT) {
if (sk != mrt->mroute6_sk && !ns_capable(net->user_ns, CAP_NET_ADMIN))
return -EACCES;
}
switch (optname) {
case MRT6_INIT:
if (sk->sk_type != SOCK_RAW ||
inet_sk(sk)->inet_num != IPPROTO_ICMPV6)
return -EOPNOTSUPP;
if (optlen < sizeof(int))
return -EINVAL;
return ip6mr_sk_init(mrt, sk);
case MRT6_DONE:
return ip6mr_sk_done(sk);
case MRT6_ADD_MIF:
if (optlen < sizeof(vif))
return -EINVAL;
if (copy_from_user(&vif, optval, sizeof(vif)))
return -EFAULT;
if (vif.mif6c_mifi >= MAXMIFS)
return -ENFILE;
rtnl_lock();
ret = mif6_add(net, mrt, &vif, sk == mrt->mroute6_sk);
rtnl_unlock();
return ret;
case MRT6_DEL_MIF:
if (optlen < sizeof(mifi_t))
return -EINVAL;
if (copy_from_user(&mifi, optval, sizeof(mifi_t)))
return -EFAULT;
rtnl_lock();
ret = mif6_delete(mrt, mifi, NULL);
rtnl_unlock();
return ret;
case MRT6_ADD_MFC:
case MRT6_DEL_MFC:
parent = -1;
case MRT6_ADD_MFC_PROXY:
case MRT6_DEL_MFC_PROXY:
if (optlen < sizeof(mfc))
return -EINVAL;
if (copy_from_user(&mfc, optval, sizeof(mfc)))
return -EFAULT;
if (parent == 0)
parent = mfc.mf6cc_parent;
rtnl_lock();
if (optname == MRT6_DEL_MFC || optname == MRT6_DEL_MFC_PROXY)
ret = ip6mr_mfc_delete(mrt, &mfc, parent);
else
ret = ip6mr_mfc_add(net, mrt, &mfc,
sk == mrt->mroute6_sk, parent);
rtnl_unlock();
return ret;
case MRT6_ASSERT:
{
int v;
if (optlen != sizeof(v))
return -EINVAL;
if (get_user(v, (int __user *)optval))
return -EFAULT;
mrt->mroute_do_assert = v;
return 0;
}
#ifdef CONFIG_IPV6_PIMSM_V2
case MRT6_PIM:
{
int v;
if (optlen != sizeof(v))
return -EINVAL;
if (get_user(v, (int __user *)optval))
return -EFAULT;
v = !!v;
rtnl_lock();
ret = 0;
if (v != mrt->mroute_do_pim) {
mrt->mroute_do_pim = v;
mrt->mroute_do_assert = v;
}
rtnl_unlock();
return ret;
}
#endif
#ifdef CONFIG_IPV6_MROUTE_MULTIPLE_TABLES
case MRT6_TABLE:
{
u32 v;
if (optlen != sizeof(u32))
return -EINVAL;
if (get_user(v, (u32 __user *)optval))
return -EFAULT;
if (v != RT_TABLE_DEFAULT && v >= 100000000)
return -EINVAL;
if (sk == mrt->mroute6_sk)
return -EBUSY;
rtnl_lock();
ret = 0;
if (!ip6mr_new_table(net, v))
ret = -ENOMEM;
raw6_sk(sk)->ip6mr_table = v;
rtnl_unlock();
return ret;
}
#endif
default:
return -ENOPROTOOPT;
}
}
int ip6_mroute_getsockopt(struct sock *sk, int optname, char __user *optval,
int __user *optlen)
{
int olr;
int val;
struct net *net = sock_net(sk);
struct mr6_table *mrt;
mrt = ip6mr_get_table(net, raw6_sk(sk)->ip6mr_table ? : RT6_TABLE_DFLT);
if (mrt == NULL)
return -ENOENT;
switch (optname) {
case MRT6_VERSION:
val = 0x0305;
break;
#ifdef CONFIG_IPV6_PIMSM_V2
case MRT6_PIM:
val = mrt->mroute_do_pim;
break;
#endif
case MRT6_ASSERT:
val = mrt->mroute_do_assert;
break;
default:
return -ENOPROTOOPT;
}
if (get_user(olr, optlen))
return -EFAULT;
olr = min_t(int, olr, sizeof(int));
if (olr < 0)
return -EINVAL;
if (put_user(olr, optlen))
return -EFAULT;
if (copy_to_user(optval, &val, olr))
return -EFAULT;
return 0;
}
int ip6mr_ioctl(struct sock *sk, int cmd, void __user *arg)
{
struct sioc_sg_req6 sr;
struct sioc_mif_req6 vr;
struct mif_device *vif;
struct mfc6_cache *c;
struct net *net = sock_net(sk);
struct mr6_table *mrt;
mrt = ip6mr_get_table(net, raw6_sk(sk)->ip6mr_table ? : RT6_TABLE_DFLT);
if (mrt == NULL)
return -ENOENT;
switch (cmd) {
case SIOCGETMIFCNT_IN6:
if (copy_from_user(&vr, arg, sizeof(vr)))
return -EFAULT;
if (vr.mifi >= mrt->maxvif)
return -EINVAL;
read_lock(&mrt_lock);
vif = &mrt->vif6_table[vr.mifi];
if (MIF_EXISTS(mrt, vr.mifi)) {
vr.icount = vif->pkt_in;
vr.ocount = vif->pkt_out;
vr.ibytes = vif->bytes_in;
vr.obytes = vif->bytes_out;
read_unlock(&mrt_lock);
if (copy_to_user(arg, &vr, sizeof(vr)))
return -EFAULT;
return 0;
}
read_unlock(&mrt_lock);
return -EADDRNOTAVAIL;
case SIOCGETSGCNT_IN6:
if (copy_from_user(&sr, arg, sizeof(sr)))
return -EFAULT;
read_lock(&mrt_lock);
c = ip6mr_cache_find(mrt, &sr.src.sin6_addr, &sr.grp.sin6_addr);
if (c) {
sr.pktcnt = c->mfc_un.res.pkt;
sr.bytecnt = c->mfc_un.res.bytes;
sr.wrong_if = c->mfc_un.res.wrong_if;
read_unlock(&mrt_lock);
if (copy_to_user(arg, &sr, sizeof(sr)))
return -EFAULT;
return 0;
}
read_unlock(&mrt_lock);
return -EADDRNOTAVAIL;
default:
return -ENOIOCTLCMD;
}
}
int ip6mr_compat_ioctl(struct sock *sk, unsigned int cmd, void __user *arg)
{
struct compat_sioc_sg_req6 sr;
struct compat_sioc_mif_req6 vr;
struct mif_device *vif;
struct mfc6_cache *c;
struct net *net = sock_net(sk);
struct mr6_table *mrt;
mrt = ip6mr_get_table(net, raw6_sk(sk)->ip6mr_table ? : RT6_TABLE_DFLT);
if (mrt == NULL)
return -ENOENT;
switch (cmd) {
case SIOCGETMIFCNT_IN6:
if (copy_from_user(&vr, arg, sizeof(vr)))
return -EFAULT;
if (vr.mifi >= mrt->maxvif)
return -EINVAL;
read_lock(&mrt_lock);
vif = &mrt->vif6_table[vr.mifi];
if (MIF_EXISTS(mrt, vr.mifi)) {
vr.icount = vif->pkt_in;
vr.ocount = vif->pkt_out;
vr.ibytes = vif->bytes_in;
vr.obytes = vif->bytes_out;
read_unlock(&mrt_lock);
if (copy_to_user(arg, &vr, sizeof(vr)))
return -EFAULT;
return 0;
}
read_unlock(&mrt_lock);
return -EADDRNOTAVAIL;
case SIOCGETSGCNT_IN6:
if (copy_from_user(&sr, arg, sizeof(sr)))
return -EFAULT;
read_lock(&mrt_lock);
c = ip6mr_cache_find(mrt, &sr.src.sin6_addr, &sr.grp.sin6_addr);
if (c) {
sr.pktcnt = c->mfc_un.res.pkt;
sr.bytecnt = c->mfc_un.res.bytes;
sr.wrong_if = c->mfc_un.res.wrong_if;
read_unlock(&mrt_lock);
if (copy_to_user(arg, &sr, sizeof(sr)))
return -EFAULT;
return 0;
}
read_unlock(&mrt_lock);
return -EADDRNOTAVAIL;
default:
return -ENOIOCTLCMD;
}
}
static inline int ip6mr_forward2_finish(struct sk_buff *skb)
{
IP6_INC_STATS_BH(dev_net(skb_dst(skb)->dev), ip6_dst_idev(skb_dst(skb)),
IPSTATS_MIB_OUTFORWDATAGRAMS);
IP6_ADD_STATS_BH(dev_net(skb_dst(skb)->dev), ip6_dst_idev(skb_dst(skb)),
IPSTATS_MIB_OUTOCTETS, skb->len);
return dst_output(skb);
}
static int ip6mr_forward2(struct net *net, struct mr6_table *mrt,
struct sk_buff *skb, struct mfc6_cache *c, int vifi)
{
struct ipv6hdr *ipv6h;
struct mif_device *vif = &mrt->vif6_table[vifi];
struct net_device *dev;
struct dst_entry *dst;
struct flowi6 fl6;
if (vif->dev == NULL)
goto out_free;
#ifdef CONFIG_IPV6_PIMSM_V2
if (vif->flags & MIFF_REGISTER) {
vif->pkt_out++;
vif->bytes_out += skb->len;
vif->dev->stats.tx_bytes += skb->len;
vif->dev->stats.tx_packets++;
ip6mr_cache_report(mrt, skb, vifi, MRT6MSG_WHOLEPKT);
goto out_free;
}
#endif
ipv6h = ipv6_hdr(skb);
fl6 = (struct flowi6) {
.flowi6_oif = vif->link,
.daddr = ipv6h->daddr,
};
dst = ip6_route_output(net, NULL, &fl6);
if (dst->error) {
dst_release(dst);
goto out_free;
}
skb_dst_drop(skb);
skb_dst_set(skb, dst);
dev = vif->dev;
skb->dev = dev;
vif->pkt_out++;
vif->bytes_out += skb->len;
if (skb_cow(skb, sizeof(*ipv6h) + LL_RESERVED_SPACE(dev)))
goto out_free;
ipv6h = ipv6_hdr(skb);
ipv6h->hop_limit--;
IP6CB(skb)->flags |= IP6SKB_FORWARDED;
return NF_HOOK(NFPROTO_IPV6, NF_INET_FORWARD, skb, skb->dev, dev,
ip6mr_forward2_finish);
out_free:
kfree_skb(skb);
return 0;
}
static int ip6mr_find_vif(struct mr6_table *mrt, struct net_device *dev)
{
int ct;
for (ct = mrt->maxvif - 1; ct >= 0; ct--) {
if (mrt->vif6_table[ct].dev == dev)
break;
}
return ct;
}
static void ip6_mr_forward(struct net *net, struct mr6_table *mrt,
struct sk_buff *skb, struct mfc6_cache *cache)
{
int psend = -1;
int vif, ct;
int true_vifi = ip6mr_find_vif(mrt, skb->dev);
vif = cache->mf6c_parent;
cache->mfc_un.res.pkt++;
cache->mfc_un.res.bytes += skb->len;
if (ipv6_addr_any(&cache->mf6c_origin) && true_vifi >= 0) {
struct mfc6_cache *cache_proxy;
cache_proxy = ip6mr_cache_find_any_parent(mrt, vif);
if (cache_proxy &&
cache_proxy->mfc_un.res.ttls[true_vifi] < 255)
goto forward;
}
if (mrt->vif6_table[vif].dev != skb->dev) {
cache->mfc_un.res.wrong_if++;
if (true_vifi >= 0 && mrt->mroute_do_assert &&
(mrt->mroute_do_pim ||
cache->mfc_un.res.ttls[true_vifi] < 255) &&
time_after(jiffies,
cache->mfc_un.res.last_assert + MFC_ASSERT_THRESH)) {
cache->mfc_un.res.last_assert = jiffies;
ip6mr_cache_report(mrt, skb, true_vifi, MRT6MSG_WRONGMIF);
}
goto dont_forward;
}
forward:
mrt->vif6_table[vif].pkt_in++;
mrt->vif6_table[vif].bytes_in += skb->len;
if (ipv6_addr_any(&cache->mf6c_origin) &&
ipv6_addr_any(&cache->mf6c_mcastgrp)) {
if (true_vifi >= 0 &&
true_vifi != cache->mf6c_parent &&
ipv6_hdr(skb)->hop_limit >
cache->mfc_un.res.ttls[cache->mf6c_parent]) {
psend = cache->mf6c_parent;
goto last_forward;
}
goto dont_forward;
}
for (ct = cache->mfc_un.res.maxvif - 1; ct >= cache->mfc_un.res.minvif; ct--) {
if ((!ipv6_addr_any(&cache->mf6c_origin) || ct != true_vifi) &&
ipv6_hdr(skb)->hop_limit > cache->mfc_un.res.ttls[ct]) {
if (psend != -1) {
struct sk_buff *skb2 = skb_clone(skb, GFP_ATOMIC);
if (skb2)
ip6mr_forward2(net, mrt, skb2, cache, psend);
}
psend = ct;
}
}
last_forward:
if (psend != -1) {
ip6mr_forward2(net, mrt, skb, cache, psend);
return;
}
dont_forward:
kfree_skb(skb);
}
int ip6_mr_input(struct sk_buff *skb)
{
struct mfc6_cache *cache;
struct net *net = dev_net(skb->dev);
struct mr6_table *mrt;
struct flowi6 fl6 = {
.flowi6_iif = skb->dev->ifindex,
.flowi6_mark = skb->mark,
};
int err;
err = ip6mr_fib_lookup(net, &fl6, &mrt);
if (err < 0) {
kfree_skb(skb);
return err;
}
read_lock(&mrt_lock);
cache = ip6mr_cache_find(mrt,
&ipv6_hdr(skb)->saddr, &ipv6_hdr(skb)->daddr);
if (cache == NULL) {
int vif = ip6mr_find_vif(mrt, skb->dev);
if (vif >= 0)
cache = ip6mr_cache_find_any(mrt,
&ipv6_hdr(skb)->daddr,
vif);
}
if (cache == NULL) {
int vif;
vif = ip6mr_find_vif(mrt, skb->dev);
if (vif >= 0) {
int err = ip6mr_cache_unresolved(mrt, vif, skb);
read_unlock(&mrt_lock);
return err;
}
read_unlock(&mrt_lock);
kfree_skb(skb);
return -ENODEV;
}
ip6_mr_forward(net, mrt, skb, cache);
read_unlock(&mrt_lock);
return 0;
}
static int __ip6mr_fill_mroute(struct mr6_table *mrt, struct sk_buff *skb,
struct mfc6_cache *c, struct rtmsg *rtm)
{
int ct;
struct rtnexthop *nhp;
struct nlattr *mp_attr;
struct rta_mfc_stats mfcs;
if (c->mf6c_parent >= MAXMIFS)
return -ENOENT;
if (MIF_EXISTS(mrt, c->mf6c_parent) &&
nla_put_u32(skb, RTA_IIF, mrt->vif6_table[c->mf6c_parent].dev->ifindex) < 0)
return -EMSGSIZE;
mp_attr = nla_nest_start(skb, RTA_MULTIPATH);
if (mp_attr == NULL)
return -EMSGSIZE;
for (ct = c->mfc_un.res.minvif; ct < c->mfc_un.res.maxvif; ct++) {
if (MIF_EXISTS(mrt, ct) && c->mfc_un.res.ttls[ct] < 255) {
nhp = nla_reserve_nohdr(skb, sizeof(*nhp));
if (nhp == NULL) {
nla_nest_cancel(skb, mp_attr);
return -EMSGSIZE;
}
nhp->rtnh_flags = 0;
nhp->rtnh_hops = c->mfc_un.res.ttls[ct];
nhp->rtnh_ifindex = mrt->vif6_table[ct].dev->ifindex;
nhp->rtnh_len = sizeof(*nhp);
}
}
nla_nest_end(skb, mp_attr);
mfcs.mfcs_packets = c->mfc_un.res.pkt;
mfcs.mfcs_bytes = c->mfc_un.res.bytes;
mfcs.mfcs_wrong_if = c->mfc_un.res.wrong_if;
if (nla_put(skb, RTA_MFC_STATS, sizeof(mfcs), &mfcs) < 0)
return -EMSGSIZE;
rtm->rtm_type = RTN_MULTICAST;
return 1;
}
int ip6mr_get_route(struct net *net,
struct sk_buff *skb, struct rtmsg *rtm, int nowait)
{
int err;
struct mr6_table *mrt;
struct mfc6_cache *cache;
struct rt6_info *rt = (struct rt6_info *)skb_dst(skb);
mrt = ip6mr_get_table(net, RT6_TABLE_DFLT);
if (mrt == NULL)
return -ENOENT;
read_lock(&mrt_lock);
cache = ip6mr_cache_find(mrt, &rt->rt6i_src.addr, &rt->rt6i_dst.addr);
if (!cache && skb->dev) {
int vif = ip6mr_find_vif(mrt, skb->dev);
if (vif >= 0)
cache = ip6mr_cache_find_any(mrt, &rt->rt6i_dst.addr,
vif);
}
if (!cache) {
struct sk_buff *skb2;
struct ipv6hdr *iph;
struct net_device *dev;
int vif;
if (nowait) {
read_unlock(&mrt_lock);
return -EAGAIN;
}
dev = skb->dev;
if (dev == NULL || (vif = ip6mr_find_vif(mrt, dev)) < 0) {
read_unlock(&mrt_lock);
return -ENODEV;
}
skb2 = alloc_skb(sizeof(struct ipv6hdr), GFP_ATOMIC);
if (!skb2) {
read_unlock(&mrt_lock);
return -ENOMEM;
}
skb_reset_transport_header(skb2);
skb_put(skb2, sizeof(struct ipv6hdr));
skb_reset_network_header(skb2);
iph = ipv6_hdr(skb2);
iph->version = 0;
iph->priority = 0;
iph->flow_lbl[0] = 0;
iph->flow_lbl[1] = 0;
iph->flow_lbl[2] = 0;
iph->payload_len = 0;
iph->nexthdr = IPPROTO_NONE;
iph->hop_limit = 0;
iph->saddr = rt->rt6i_src.addr;
iph->daddr = rt->rt6i_dst.addr;
err = ip6mr_cache_unresolved(mrt, vif, skb2);
read_unlock(&mrt_lock);
return err;
}
if (!nowait && (rtm->rtm_flags&RTM_F_NOTIFY))
cache->mfc_flags |= MFC_NOTIFY;
err = __ip6mr_fill_mroute(mrt, skb, cache, rtm);
read_unlock(&mrt_lock);
return err;
}
static int ip6mr_fill_mroute(struct mr6_table *mrt, struct sk_buff *skb,
u32 portid, u32 seq, struct mfc6_cache *c, int cmd,
int flags)
{
struct nlmsghdr *nlh;
struct rtmsg *rtm;
int err;
nlh = nlmsg_put(skb, portid, seq, cmd, sizeof(*rtm), flags);
if (nlh == NULL)
return -EMSGSIZE;
rtm = nlmsg_data(nlh);
rtm->rtm_family = RTNL_FAMILY_IP6MR;
rtm->rtm_dst_len = 128;
rtm->rtm_src_len = 128;
rtm->rtm_tos = 0;
rtm->rtm_table = mrt->id;
if (nla_put_u32(skb, RTA_TABLE, mrt->id))
goto nla_put_failure;
rtm->rtm_type = RTN_MULTICAST;
rtm->rtm_scope = RT_SCOPE_UNIVERSE;
if (c->mfc_flags & MFC_STATIC)
rtm->rtm_protocol = RTPROT_STATIC;
else
rtm->rtm_protocol = RTPROT_MROUTED;
rtm->rtm_flags = 0;
if (nla_put(skb, RTA_SRC, 16, &c->mf6c_origin) ||
nla_put(skb, RTA_DST, 16, &c->mf6c_mcastgrp))
goto nla_put_failure;
err = __ip6mr_fill_mroute(mrt, skb, c, rtm);
if (err < 0 && err != -ENOENT)
goto nla_put_failure;
return nlmsg_end(skb, nlh);
nla_put_failure:
nlmsg_cancel(skb, nlh);
return -EMSGSIZE;
}
static int mr6_msgsize(bool unresolved, int maxvif)
{
size_t len =
NLMSG_ALIGN(sizeof(struct rtmsg))
+ nla_total_size(4)
+ nla_total_size(sizeof(struct in6_addr))
+ nla_total_size(sizeof(struct in6_addr))
;
if (!unresolved)
len = len
+ nla_total_size(4)
+ nla_total_size(0)
+ maxvif * NLA_ALIGN(sizeof(struct rtnexthop))
+ nla_total_size(sizeof(struct rta_mfc_stats))
;
return len;
}
static void mr6_netlink_event(struct mr6_table *mrt, struct mfc6_cache *mfc,
int cmd)
{
struct net *net = read_pnet(&mrt->net);
struct sk_buff *skb;
int err = -ENOBUFS;
skb = nlmsg_new(mr6_msgsize(mfc->mf6c_parent >= MAXMIFS, mrt->maxvif),
GFP_ATOMIC);
if (skb == NULL)
goto errout;
err = ip6mr_fill_mroute(mrt, skb, 0, 0, mfc, cmd, 0);
if (err < 0)
goto errout;
rtnl_notify(skb, net, 0, RTNLGRP_IPV6_MROUTE, NULL, GFP_ATOMIC);
return;
errout:
kfree_skb(skb);
if (err < 0)
rtnl_set_sk_err(net, RTNLGRP_IPV6_MROUTE, err);
}
static int ip6mr_rtm_dumproute(struct sk_buff *skb, struct netlink_callback *cb)
{
struct net *net = sock_net(skb->sk);
struct mr6_table *mrt;
struct mfc6_cache *mfc;
unsigned int t = 0, s_t;
unsigned int h = 0, s_h;
unsigned int e = 0, s_e;
s_t = cb->args[0];
s_h = cb->args[1];
s_e = cb->args[2];
read_lock(&mrt_lock);
ip6mr_for_each_table(mrt, net) {
if (t < s_t)
goto next_table;
if (t > s_t)
s_h = 0;
for (h = s_h; h < MFC6_LINES; h++) {
list_for_each_entry(mfc, &mrt->mfc6_cache_array[h], list) {
if (e < s_e)
goto next_entry;
if (ip6mr_fill_mroute(mrt, skb,
NETLINK_CB(cb->skb).portid,
cb->nlh->nlmsg_seq,
mfc, RTM_NEWROUTE,
NLM_F_MULTI) < 0)
goto done;
next_entry:
e++;
}
e = s_e = 0;
}
spin_lock_bh(&mfc_unres_lock);
list_for_each_entry(mfc, &mrt->mfc6_unres_queue, list) {
if (e < s_e)
goto next_entry2;
if (ip6mr_fill_mroute(mrt, skb,
NETLINK_CB(cb->skb).portid,
cb->nlh->nlmsg_seq,
mfc, RTM_NEWROUTE,
NLM_F_MULTI) < 0) {
spin_unlock_bh(&mfc_unres_lock);
goto done;
}
next_entry2:
e++;
}
spin_unlock_bh(&mfc_unres_lock);
e = s_e = 0;
s_h = 0;
next_table:
t++;
}
done:
read_unlock(&mrt_lock);
cb->args[2] = e;
cb->args[1] = h;
cb->args[0] = t;
return skb->len;
}
