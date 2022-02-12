int can_ioctl(struct socket *sock, unsigned int cmd, unsigned long arg)
{
struct sock *sk = sock->sk;
switch (cmd) {
case SIOCGSTAMP:
return sock_get_timestamp(sk, (struct timeval __user *)arg);
default:
return -ENOIOCTLCMD;
}
}
static void can_sock_destruct(struct sock *sk)
{
skb_queue_purge(&sk->sk_receive_queue);
}
static const struct can_proto *can_get_proto(int protocol)
{
const struct can_proto *cp;
rcu_read_lock();
cp = rcu_dereference(proto_tab[protocol]);
if (cp && !try_module_get(cp->prot->owner))
cp = NULL;
rcu_read_unlock();
return cp;
}
static inline void can_put_proto(const struct can_proto *cp)
{
module_put(cp->prot->owner);
}
static int can_create(struct net *net, struct socket *sock, int protocol,
int kern)
{
struct sock *sk;
const struct can_proto *cp;
int err = 0;
sock->state = SS_UNCONNECTED;
if (protocol < 0 || protocol >= CAN_NPROTO)
return -EINVAL;
if (!net_eq(net, &init_net))
return -EAFNOSUPPORT;
cp = can_get_proto(protocol);
#ifdef CONFIG_MODULES
if (!cp) {
err = request_module("can-proto-%d", protocol);
if (err)
printk_ratelimited(KERN_ERR "can: request_module "
"(can-proto-%d) failed.\n", protocol);
cp = can_get_proto(protocol);
}
#endif
if (!cp)
return -EPROTONOSUPPORT;
if (cp->type != sock->type) {
err = -EPROTOTYPE;
goto errout;
}
sock->ops = cp->ops;
sk = sk_alloc(net, PF_CAN, GFP_KERNEL, cp->prot, kern);
if (!sk) {
err = -ENOMEM;
goto errout;
}
sock_init_data(sock, sk);
sk->sk_destruct = can_sock_destruct;
if (sk->sk_prot->init)
err = sk->sk_prot->init(sk);
if (err) {
sock_orphan(sk);
sock_put(sk);
}
errout:
can_put_proto(cp);
return err;
}
int can_send(struct sk_buff *skb, int loop)
{
struct sk_buff *newskb = NULL;
struct canfd_frame *cfd = (struct canfd_frame *)skb->data;
int err = -EINVAL;
if (skb->len == CAN_MTU) {
skb->protocol = htons(ETH_P_CAN);
if (unlikely(cfd->len > CAN_MAX_DLEN))
goto inval_skb;
} else if (skb->len == CANFD_MTU) {
skb->protocol = htons(ETH_P_CANFD);
if (unlikely(cfd->len > CANFD_MAX_DLEN))
goto inval_skb;
} else
goto inval_skb;
if (unlikely(skb->len > skb->dev->mtu && cfd->len > CAN_MAX_DLEN)) {
err = -EMSGSIZE;
goto inval_skb;
}
if (unlikely(skb->dev->type != ARPHRD_CAN)) {
err = -EPERM;
goto inval_skb;
}
if (unlikely(!(skb->dev->flags & IFF_UP))) {
err = -ENETDOWN;
goto inval_skb;
}
skb->ip_summed = CHECKSUM_UNNECESSARY;
skb_reset_mac_header(skb);
skb_reset_network_header(skb);
skb_reset_transport_header(skb);
if (loop) {
skb->pkt_type = PACKET_LOOPBACK;
if (!(skb->dev->flags & IFF_ECHO)) {
newskb = skb_clone(skb, GFP_ATOMIC);
if (!newskb) {
kfree_skb(skb);
return -ENOMEM;
}
can_skb_set_owner(newskb, skb->sk);
newskb->ip_summed = CHECKSUM_UNNECESSARY;
newskb->pkt_type = PACKET_BROADCAST;
}
} else {
skb->pkt_type = PACKET_HOST;
}
err = dev_queue_xmit(skb);
if (err > 0)
err = net_xmit_errno(err);
if (err) {
kfree_skb(newskb);
return err;
}
if (newskb)
netif_rx_ni(newskb);
can_stats.tx_frames++;
can_stats.tx_frames_delta++;
return 0;
inval_skb:
kfree_skb(skb);
return err;
}
static struct dev_rcv_lists *find_dev_rcv_lists(struct net_device *dev)
{
if (!dev)
return &can_rx_alldev_list;
else
return (struct dev_rcv_lists *)dev->ml_priv;
}
static unsigned int effhash(canid_t can_id)
{
unsigned int hash;
hash = can_id;
hash ^= can_id >> CAN_EFF_RCV_HASH_BITS;
hash ^= can_id >> (2 * CAN_EFF_RCV_HASH_BITS);
return hash & ((1 << CAN_EFF_RCV_HASH_BITS) - 1);
}
static struct hlist_head *find_rcv_list(canid_t *can_id, canid_t *mask,
struct dev_rcv_lists *d)
{
canid_t inv = *can_id & CAN_INV_FILTER;
if (*mask & CAN_ERR_FLAG) {
*mask &= CAN_ERR_MASK;
return &d->rx[RX_ERR];
}
#define CAN_EFF_RTR_FLAGS (CAN_EFF_FLAG | CAN_RTR_FLAG)
if ((*mask & CAN_EFF_FLAG) && !(*can_id & CAN_EFF_FLAG))
*mask &= (CAN_SFF_MASK | CAN_EFF_RTR_FLAGS);
*can_id &= *mask;
if (inv)
return &d->rx[RX_INV];
if (!(*mask))
return &d->rx[RX_ALL];
if (((*mask & CAN_EFF_RTR_FLAGS) == CAN_EFF_RTR_FLAGS) &&
!(*can_id & CAN_RTR_FLAG)) {
if (*can_id & CAN_EFF_FLAG) {
if (*mask == (CAN_EFF_MASK | CAN_EFF_RTR_FLAGS))
return &d->rx_eff[effhash(*can_id)];
} else {
if (*mask == (CAN_SFF_MASK | CAN_EFF_RTR_FLAGS))
return &d->rx_sff[*can_id];
}
}
return &d->rx[RX_FIL];
}
int can_rx_register(struct net_device *dev, canid_t can_id, canid_t mask,
void (*func)(struct sk_buff *, void *), void *data,
char *ident)
{
struct receiver *r;
struct hlist_head *rl;
struct dev_rcv_lists *d;
int err = 0;
if (dev && dev->type != ARPHRD_CAN)
return -ENODEV;
r = kmem_cache_alloc(rcv_cache, GFP_KERNEL);
if (!r)
return -ENOMEM;
spin_lock(&can_rcvlists_lock);
d = find_dev_rcv_lists(dev);
if (d) {
rl = find_rcv_list(&can_id, &mask, d);
r->can_id = can_id;
r->mask = mask;
r->matches = 0;
r->func = func;
r->data = data;
r->ident = ident;
hlist_add_head_rcu(&r->list, rl);
d->entries++;
can_pstats.rcv_entries++;
if (can_pstats.rcv_entries_max < can_pstats.rcv_entries)
can_pstats.rcv_entries_max = can_pstats.rcv_entries;
} else {
kmem_cache_free(rcv_cache, r);
err = -ENODEV;
}
spin_unlock(&can_rcvlists_lock);
return err;
}
static void can_rx_delete_receiver(struct rcu_head *rp)
{
struct receiver *r = container_of(rp, struct receiver, rcu);
kmem_cache_free(rcv_cache, r);
}
void can_rx_unregister(struct net_device *dev, canid_t can_id, canid_t mask,
void (*func)(struct sk_buff *, void *), void *data)
{
struct receiver *r = NULL;
struct hlist_head *rl;
struct dev_rcv_lists *d;
if (dev && dev->type != ARPHRD_CAN)
return;
spin_lock(&can_rcvlists_lock);
d = find_dev_rcv_lists(dev);
if (!d) {
pr_err("BUG: receive list not found for "
"dev %s, id %03X, mask %03X\n",
DNAME(dev), can_id, mask);
goto out;
}
rl = find_rcv_list(&can_id, &mask, d);
hlist_for_each_entry_rcu(r, rl, list) {
if (r->can_id == can_id && r->mask == mask &&
r->func == func && r->data == data)
break;
}
if (!r) {
WARN(1, "BUG: receive list entry not found for dev %s, "
"id %03X, mask %03X\n", DNAME(dev), can_id, mask);
goto out;
}
hlist_del_rcu(&r->list);
d->entries--;
if (can_pstats.rcv_entries > 0)
can_pstats.rcv_entries--;
if (d->remove_on_zero_entries && !d->entries) {
kfree(d);
dev->ml_priv = NULL;
}
out:
spin_unlock(&can_rcvlists_lock);
if (r)
call_rcu(&r->rcu, can_rx_delete_receiver);
}
static inline void deliver(struct sk_buff *skb, struct receiver *r)
{
r->func(skb, r->data);
r->matches++;
}
static int can_rcv_filter(struct dev_rcv_lists *d, struct sk_buff *skb)
{
struct receiver *r;
int matches = 0;
struct can_frame *cf = (struct can_frame *)skb->data;
canid_t can_id = cf->can_id;
if (d->entries == 0)
return 0;
if (can_id & CAN_ERR_FLAG) {
hlist_for_each_entry_rcu(r, &d->rx[RX_ERR], list) {
if (can_id & r->mask) {
deliver(skb, r);
matches++;
}
}
return matches;
}
hlist_for_each_entry_rcu(r, &d->rx[RX_ALL], list) {
deliver(skb, r);
matches++;
}
hlist_for_each_entry_rcu(r, &d->rx[RX_FIL], list) {
if ((can_id & r->mask) == r->can_id) {
deliver(skb, r);
matches++;
}
}
hlist_for_each_entry_rcu(r, &d->rx[RX_INV], list) {
if ((can_id & r->mask) != r->can_id) {
deliver(skb, r);
matches++;
}
}
if (can_id & CAN_RTR_FLAG)
return matches;
if (can_id & CAN_EFF_FLAG) {
hlist_for_each_entry_rcu(r, &d->rx_eff[effhash(can_id)], list) {
if (r->can_id == can_id) {
deliver(skb, r);
matches++;
}
}
} else {
can_id &= CAN_SFF_MASK;
hlist_for_each_entry_rcu(r, &d->rx_sff[can_id], list) {
deliver(skb, r);
matches++;
}
}
return matches;
}
static void can_receive(struct sk_buff *skb, struct net_device *dev)
{
struct dev_rcv_lists *d;
int matches;
can_stats.rx_frames++;
can_stats.rx_frames_delta++;
while (!(can_skb_prv(skb)->skbcnt))
can_skb_prv(skb)->skbcnt = atomic_inc_return(&skbcounter);
rcu_read_lock();
matches = can_rcv_filter(&can_rx_alldev_list, skb);
d = find_dev_rcv_lists(dev);
if (d)
matches += can_rcv_filter(d, skb);
rcu_read_unlock();
consume_skb(skb);
if (matches > 0) {
can_stats.matches++;
can_stats.matches_delta++;
}
}
static int can_rcv(struct sk_buff *skb, struct net_device *dev,
struct packet_type *pt, struct net_device *orig_dev)
{
struct canfd_frame *cfd = (struct canfd_frame *)skb->data;
if (unlikely(!net_eq(dev_net(dev), &init_net)))
goto drop;
if (WARN_ONCE(dev->type != ARPHRD_CAN ||
skb->len != CAN_MTU ||
cfd->len > CAN_MAX_DLEN,
"PF_CAN: dropped non conform CAN skbuf: "
"dev type %d, len %d, datalen %d\n",
dev->type, skb->len, cfd->len))
goto drop;
can_receive(skb, dev);
return NET_RX_SUCCESS;
drop:
kfree_skb(skb);
return NET_RX_DROP;
}
static int canfd_rcv(struct sk_buff *skb, struct net_device *dev,
struct packet_type *pt, struct net_device *orig_dev)
{
struct canfd_frame *cfd = (struct canfd_frame *)skb->data;
if (unlikely(!net_eq(dev_net(dev), &init_net)))
goto drop;
if (WARN_ONCE(dev->type != ARPHRD_CAN ||
skb->len != CANFD_MTU ||
cfd->len > CANFD_MAX_DLEN,
"PF_CAN: dropped non conform CAN FD skbuf: "
"dev type %d, len %d, datalen %d\n",
dev->type, skb->len, cfd->len))
goto drop;
can_receive(skb, dev);
return NET_RX_SUCCESS;
drop:
kfree_skb(skb);
return NET_RX_DROP;
}
int can_proto_register(const struct can_proto *cp)
{
int proto = cp->protocol;
int err = 0;
if (proto < 0 || proto >= CAN_NPROTO) {
pr_err("can: protocol number %d out of range\n", proto);
return -EINVAL;
}
err = proto_register(cp->prot, 0);
if (err < 0)
return err;
mutex_lock(&proto_tab_lock);
if (proto_tab[proto]) {
pr_err("can: protocol %d already registered\n", proto);
err = -EBUSY;
} else
RCU_INIT_POINTER(proto_tab[proto], cp);
mutex_unlock(&proto_tab_lock);
if (err < 0)
proto_unregister(cp->prot);
return err;
}
void can_proto_unregister(const struct can_proto *cp)
{
int proto = cp->protocol;
mutex_lock(&proto_tab_lock);
BUG_ON(proto_tab[proto] != cp);
RCU_INIT_POINTER(proto_tab[proto], NULL);
mutex_unlock(&proto_tab_lock);
synchronize_rcu();
proto_unregister(cp->prot);
}
static int can_notifier(struct notifier_block *nb, unsigned long msg,
void *ptr)
{
struct net_device *dev = netdev_notifier_info_to_dev(ptr);
struct dev_rcv_lists *d;
if (!net_eq(dev_net(dev), &init_net))
return NOTIFY_DONE;
if (dev->type != ARPHRD_CAN)
return NOTIFY_DONE;
switch (msg) {
case NETDEV_REGISTER:
d = kzalloc(sizeof(*d), GFP_KERNEL);
if (!d)
return NOTIFY_DONE;
BUG_ON(dev->ml_priv);
dev->ml_priv = d;
break;
case NETDEV_UNREGISTER:
spin_lock(&can_rcvlists_lock);
d = dev->ml_priv;
if (d) {
if (d->entries)
d->remove_on_zero_entries = 1;
else {
kfree(d);
dev->ml_priv = NULL;
}
} else
pr_err("can: notifier: receive list not found for dev "
"%s\n", dev->name);
spin_unlock(&can_rcvlists_lock);
break;
}
return NOTIFY_DONE;
}
static __init int can_init(void)
{
BUILD_BUG_ON(offsetof(struct can_frame, can_dlc) !=
offsetof(struct canfd_frame, len) ||
offsetof(struct can_frame, data) !=
offsetof(struct canfd_frame, data));
pr_info("can: controller area network core (" CAN_VERSION_STRING ")\n");
memset(&can_rx_alldev_list, 0, sizeof(can_rx_alldev_list));
rcv_cache = kmem_cache_create("can_receiver", sizeof(struct receiver),
0, 0, NULL);
if (!rcv_cache)
return -ENOMEM;
if (IS_ENABLED(CONFIG_PROC_FS)) {
if (stats_timer) {
setup_timer(&can_stattimer, can_stat_update, 0);
mod_timer(&can_stattimer, round_jiffies(jiffies + HZ));
}
can_init_proc();
}
sock_register(&can_family_ops);
register_netdevice_notifier(&can_netdev_notifier);
dev_add_pack(&can_packet);
dev_add_pack(&canfd_packet);
return 0;
}
static __exit void can_exit(void)
{
struct net_device *dev;
if (IS_ENABLED(CONFIG_PROC_FS)) {
if (stats_timer)
del_timer_sync(&can_stattimer);
can_remove_proc();
}
dev_remove_pack(&canfd_packet);
dev_remove_pack(&can_packet);
unregister_netdevice_notifier(&can_netdev_notifier);
sock_unregister(PF_CAN);
rcu_read_lock();
for_each_netdev_rcu(&init_net, dev) {
if (dev->type == ARPHRD_CAN && dev->ml_priv) {
struct dev_rcv_lists *d = dev->ml_priv;
BUG_ON(d->entries);
kfree(d);
dev->ml_priv = NULL;
}
}
rcu_read_unlock();
rcu_barrier();
kmem_cache_destroy(rcv_cache);
}
