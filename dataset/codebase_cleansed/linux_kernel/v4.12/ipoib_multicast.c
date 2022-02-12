static void __ipoib_mcast_schedule_join_thread(struct ipoib_dev_priv *priv,
struct ipoib_mcast *mcast,
bool delay)
{
if (!test_bit(IPOIB_FLAG_OPER_UP, &priv->flags))
return;
cancel_delayed_work(&priv->mcast_task);
if (mcast && delay) {
mcast->backoff *= 2;
if (mcast->backoff > IPOIB_MAX_BACKOFF_SECONDS)
mcast->backoff = IPOIB_MAX_BACKOFF_SECONDS;
mcast->delay_until = jiffies + (mcast->backoff * HZ);
queue_delayed_work(priv->wq, &priv->mcast_task, 0);
} else if (delay) {
queue_delayed_work(priv->wq, &priv->mcast_task, HZ);
} else
queue_delayed_work(priv->wq, &priv->mcast_task, 0);
}
static void ipoib_mcast_free(struct ipoib_mcast *mcast)
{
struct net_device *dev = mcast->dev;
int tx_dropped = 0;
ipoib_dbg_mcast(ipoib_priv(dev), "deleting multicast group %pI6\n",
mcast->mcmember.mgid.raw);
ipoib_del_neighs_by_gid(dev, mcast->mcmember.mgid.raw);
if (mcast->ah)
ipoib_put_ah(mcast->ah);
while (!skb_queue_empty(&mcast->pkt_queue)) {
++tx_dropped;
dev_kfree_skb_any(skb_dequeue(&mcast->pkt_queue));
}
netif_tx_lock_bh(dev);
dev->stats.tx_dropped += tx_dropped;
netif_tx_unlock_bh(dev);
kfree(mcast);
}
static struct ipoib_mcast *ipoib_mcast_alloc(struct net_device *dev,
int can_sleep)
{
struct ipoib_mcast *mcast;
mcast = kzalloc(sizeof *mcast, can_sleep ? GFP_KERNEL : GFP_ATOMIC);
if (!mcast)
return NULL;
mcast->dev = dev;
mcast->created = jiffies;
mcast->delay_until = jiffies;
mcast->backoff = 1;
INIT_LIST_HEAD(&mcast->list);
INIT_LIST_HEAD(&mcast->neigh_list);
skb_queue_head_init(&mcast->pkt_queue);
return mcast;
}
static struct ipoib_mcast *__ipoib_mcast_find(struct net_device *dev, void *mgid)
{
struct ipoib_dev_priv *priv = ipoib_priv(dev);
struct rb_node *n = priv->multicast_tree.rb_node;
while (n) {
struct ipoib_mcast *mcast;
int ret;
mcast = rb_entry(n, struct ipoib_mcast, rb_node);
ret = memcmp(mgid, mcast->mcmember.mgid.raw,
sizeof (union ib_gid));
if (ret < 0)
n = n->rb_left;
else if (ret > 0)
n = n->rb_right;
else
return mcast;
}
return NULL;
}
static int __ipoib_mcast_add(struct net_device *dev, struct ipoib_mcast *mcast)
{
struct ipoib_dev_priv *priv = ipoib_priv(dev);
struct rb_node **n = &priv->multicast_tree.rb_node, *pn = NULL;
while (*n) {
struct ipoib_mcast *tmcast;
int ret;
pn = *n;
tmcast = rb_entry(pn, struct ipoib_mcast, rb_node);
ret = memcmp(mcast->mcmember.mgid.raw, tmcast->mcmember.mgid.raw,
sizeof (union ib_gid));
if (ret < 0)
n = &pn->rb_left;
else if (ret > 0)
n = &pn->rb_right;
else
return -EEXIST;
}
rb_link_node(&mcast->rb_node, pn, n);
rb_insert_color(&mcast->rb_node, &priv->multicast_tree);
return 0;
}
static int ipoib_mcast_join_finish(struct ipoib_mcast *mcast,
struct ib_sa_mcmember_rec *mcmember)
{
struct net_device *dev = mcast->dev;
struct ipoib_dev_priv *priv = ipoib_priv(dev);
struct rdma_netdev *rn = netdev_priv(dev);
struct ipoib_ah *ah;
struct rdma_ah_attr av;
int ret;
int set_qkey = 0;
mcast->mcmember = *mcmember;
if (!memcmp(mcast->mcmember.mgid.raw, priv->dev->broadcast + 4,
sizeof (union ib_gid))) {
spin_lock_irq(&priv->lock);
if (!priv->broadcast) {
spin_unlock_irq(&priv->lock);
return -EAGAIN;
}
priv->broadcast->mcmember.qkey = mcmember->qkey;
priv->broadcast->mcmember.mtu = mcmember->mtu;
priv->broadcast->mcmember.traffic_class = mcmember->traffic_class;
priv->broadcast->mcmember.rate = mcmember->rate;
priv->broadcast->mcmember.sl = mcmember->sl;
priv->broadcast->mcmember.flow_label = mcmember->flow_label;
priv->broadcast->mcmember.hop_limit = mcmember->hop_limit;
if (priv->mcast_mtu == priv->admin_mtu)
priv->admin_mtu =
priv->mcast_mtu =
IPOIB_UD_MTU(ib_mtu_enum_to_int(priv->broadcast->mcmember.mtu));
else
priv->mcast_mtu =
IPOIB_UD_MTU(ib_mtu_enum_to_int(priv->broadcast->mcmember.mtu));
priv->qkey = be32_to_cpu(priv->broadcast->mcmember.qkey);
spin_unlock_irq(&priv->lock);
priv->tx_wr.remote_qkey = priv->qkey;
set_qkey = 1;
}
if (!test_bit(IPOIB_MCAST_FLAG_SENDONLY, &mcast->flags)) {
if (test_and_set_bit(IPOIB_MCAST_FLAG_ATTACHED, &mcast->flags)) {
ipoib_warn(priv, "multicast group %pI6 already attached\n",
mcast->mcmember.mgid.raw);
return 0;
}
ret = rn->attach_mcast(dev, priv->ca, &mcast->mcmember.mgid,
be16_to_cpu(mcast->mcmember.mlid),
set_qkey, priv->qkey);
if (ret < 0) {
ipoib_warn(priv, "couldn't attach QP to multicast group %pI6\n",
mcast->mcmember.mgid.raw);
clear_bit(IPOIB_MCAST_FLAG_ATTACHED, &mcast->flags);
return ret;
}
}
memset(&av, 0, sizeof(av));
av.type = rdma_ah_find_type(priv->ca, priv->port);
rdma_ah_set_dlid(&av, be16_to_cpu(mcast->mcmember.mlid)),
rdma_ah_set_port_num(&av, priv->port);
rdma_ah_set_sl(&av, mcast->mcmember.sl);
rdma_ah_set_static_rate(&av, mcast->mcmember.rate);
rdma_ah_set_grh(&av, &mcast->mcmember.mgid,
be32_to_cpu(mcast->mcmember.flow_label),
0, mcast->mcmember.hop_limit,
mcast->mcmember.traffic_class);
ah = ipoib_create_ah(dev, priv->pd, &av);
if (IS_ERR(ah)) {
ipoib_warn(priv, "ib_address_create failed %ld\n",
-PTR_ERR(ah));
return PTR_ERR(ah);
}
spin_lock_irq(&priv->lock);
mcast->ah = ah;
spin_unlock_irq(&priv->lock);
ipoib_dbg_mcast(priv, "MGID %pI6 AV %p, LID 0x%04x, SL %d\n",
mcast->mcmember.mgid.raw,
mcast->ah->ah,
be16_to_cpu(mcast->mcmember.mlid),
mcast->mcmember.sl);
netif_tx_lock_bh(dev);
while (!skb_queue_empty(&mcast->pkt_queue)) {
struct sk_buff *skb = skb_dequeue(&mcast->pkt_queue);
netif_tx_unlock_bh(dev);
skb->dev = dev;
ret = dev_queue_xmit(skb);
if (ret)
ipoib_warn(priv, "%s:dev_queue_xmit failed to re-queue packet, ret:%d\n",
__func__, ret);
netif_tx_lock_bh(dev);
}
netif_tx_unlock_bh(dev);
return 0;
}
void ipoib_mcast_carrier_on_task(struct work_struct *work)
{
struct ipoib_dev_priv *priv = container_of(work, struct ipoib_dev_priv,
carrier_on_task);
struct ib_port_attr attr;
if (ib_query_port(priv->ca, priv->port, &attr) ||
attr.state != IB_PORT_ACTIVE) {
ipoib_dbg(priv, "Keeping carrier off until IB port is active\n");
return;
}
priv->sm_fullmember_sendonly_support =
ib_sa_sendonly_fullmem_support(&ipoib_sa_client,
priv->ca, priv->port);
while (!rtnl_trylock()) {
if (!test_bit(IPOIB_FLAG_OPER_UP, &priv->flags))
return;
else
msleep(20);
}
if (!ipoib_cm_admin_enabled(priv->dev))
dev_set_mtu(priv->dev, min(priv->mcast_mtu, priv->admin_mtu));
netif_carrier_on(priv->dev);
rtnl_unlock();
}
static int ipoib_mcast_join_complete(int status,
struct ib_sa_multicast *multicast)
{
struct ipoib_mcast *mcast = multicast->context;
struct net_device *dev = mcast->dev;
struct ipoib_dev_priv *priv = ipoib_priv(dev);
ipoib_dbg_mcast(priv, "%sjoin completion for %pI6 (status %d)\n",
test_bit(IPOIB_MCAST_FLAG_SENDONLY, &mcast->flags) ?
"sendonly " : "",
mcast->mcmember.mgid.raw, status);
if (status == -ENETRESET) {
status = 0;
goto out;
}
if (!status)
status = ipoib_mcast_join_finish(mcast, &multicast->rec);
if (!status) {
mcast->backoff = 1;
mcast->delay_until = jiffies;
if (mcast == priv->broadcast) {
spin_lock_irq(&priv->lock);
queue_work(priv->wq, &priv->carrier_on_task);
__ipoib_mcast_schedule_join_thread(priv, NULL, 0);
goto out_locked;
}
} else {
bool silent_fail =
test_bit(IPOIB_MCAST_FLAG_SENDONLY, &mcast->flags) &&
status == -EINVAL;
if (mcast->logcount < 20) {
if (status == -ETIMEDOUT || status == -EAGAIN ||
silent_fail) {
ipoib_dbg_mcast(priv, "%smulticast join failed for %pI6, status %d\n",
test_bit(IPOIB_MCAST_FLAG_SENDONLY, &mcast->flags) ? "sendonly " : "",
mcast->mcmember.mgid.raw, status);
} else {
ipoib_warn(priv, "%smulticast join failed for %pI6, status %d\n",
test_bit(IPOIB_MCAST_FLAG_SENDONLY, &mcast->flags) ? "sendonly " : "",
mcast->mcmember.mgid.raw, status);
}
if (!silent_fail)
mcast->logcount++;
}
if (test_bit(IPOIB_MCAST_FLAG_SENDONLY, &mcast->flags) &&
mcast->backoff >= 2) {
mcast->backoff = 1;
netif_tx_lock_bh(dev);
while (!skb_queue_empty(&mcast->pkt_queue)) {
++dev->stats.tx_dropped;
dev_kfree_skb_any(skb_dequeue(&mcast->pkt_queue));
}
netif_tx_unlock_bh(dev);
} else {
spin_lock_irq(&priv->lock);
__ipoib_mcast_schedule_join_thread(priv, mcast, 1);
goto out_locked;
}
}
out:
spin_lock_irq(&priv->lock);
out_locked:
if (status)
mcast->mc = NULL;
else
mcast->mc = multicast;
clear_bit(IPOIB_MCAST_FLAG_BUSY, &mcast->flags);
spin_unlock_irq(&priv->lock);
complete(&mcast->done);
return status;
}
static int ipoib_mcast_join(struct net_device *dev, struct ipoib_mcast *mcast)
{
struct ipoib_dev_priv *priv = ipoib_priv(dev);
struct ib_sa_multicast *multicast;
struct ib_sa_mcmember_rec rec = {
.join_state = 1
};
ib_sa_comp_mask comp_mask;
int ret = 0;
if (!priv->broadcast ||
!test_bit(IPOIB_FLAG_OPER_UP, &priv->flags))
return -EINVAL;
init_completion(&mcast->done);
set_bit(IPOIB_MCAST_FLAG_BUSY, &mcast->flags);
ipoib_dbg_mcast(priv, "joining MGID %pI6\n", mcast->mcmember.mgid.raw);
rec.mgid = mcast->mcmember.mgid;
rec.port_gid = priv->local_gid;
rec.pkey = cpu_to_be16(priv->pkey);
comp_mask =
IB_SA_MCMEMBER_REC_MGID |
IB_SA_MCMEMBER_REC_PORT_GID |
IB_SA_MCMEMBER_REC_PKEY |
IB_SA_MCMEMBER_REC_JOIN_STATE;
if (mcast != priv->broadcast) {
comp_mask |=
IB_SA_MCMEMBER_REC_QKEY |
IB_SA_MCMEMBER_REC_MTU_SELECTOR |
IB_SA_MCMEMBER_REC_MTU |
IB_SA_MCMEMBER_REC_TRAFFIC_CLASS |
IB_SA_MCMEMBER_REC_RATE_SELECTOR |
IB_SA_MCMEMBER_REC_RATE |
IB_SA_MCMEMBER_REC_SL |
IB_SA_MCMEMBER_REC_FLOW_LABEL |
IB_SA_MCMEMBER_REC_HOP_LIMIT;
rec.qkey = priv->broadcast->mcmember.qkey;
rec.mtu_selector = IB_SA_EQ;
rec.mtu = priv->broadcast->mcmember.mtu;
rec.traffic_class = priv->broadcast->mcmember.traffic_class;
rec.rate_selector = IB_SA_EQ;
rec.rate = priv->broadcast->mcmember.rate;
rec.sl = priv->broadcast->mcmember.sl;
rec.flow_label = priv->broadcast->mcmember.flow_label;
rec.hop_limit = priv->broadcast->mcmember.hop_limit;
if (test_bit(IPOIB_MCAST_FLAG_SENDONLY, &mcast->flags) &&
priv->sm_fullmember_sendonly_support)
rec.join_state = SENDONLY_FULLMEMBER_JOIN;
}
spin_unlock_irq(&priv->lock);
multicast = ib_sa_join_multicast(&ipoib_sa_client, priv->ca, priv->port,
&rec, comp_mask, GFP_KERNEL,
ipoib_mcast_join_complete, mcast);
spin_lock_irq(&priv->lock);
if (IS_ERR(multicast)) {
ret = PTR_ERR(multicast);
ipoib_warn(priv, "ib_sa_join_multicast failed, status %d\n", ret);
__ipoib_mcast_schedule_join_thread(priv, mcast, 1);
clear_bit(IPOIB_MCAST_FLAG_BUSY, &mcast->flags);
spin_unlock_irq(&priv->lock);
complete(&mcast->done);
spin_lock_irq(&priv->lock);
}
return 0;
}
void ipoib_mcast_join_task(struct work_struct *work)
{
struct ipoib_dev_priv *priv =
container_of(work, struct ipoib_dev_priv, mcast_task.work);
struct net_device *dev = priv->dev;
struct ib_port_attr port_attr;
unsigned long delay_until = 0;
struct ipoib_mcast *mcast = NULL;
if (!test_bit(IPOIB_FLAG_OPER_UP, &priv->flags))
return;
if (ib_query_port(priv->ca, priv->port, &port_attr)) {
ipoib_dbg(priv, "ib_query_port() failed\n");
return;
}
if (port_attr.state != IB_PORT_ACTIVE) {
ipoib_dbg(priv, "port state is not ACTIVE (state = %d) suspending join task\n",
port_attr.state);
return;
}
priv->local_lid = port_attr.lid;
netif_addr_lock_bh(dev);
if (!test_bit(IPOIB_FLAG_DEV_ADDR_SET, &priv->flags)) {
netif_addr_unlock_bh(dev);
return;
}
netif_addr_unlock_bh(dev);
spin_lock_irq(&priv->lock);
if (!test_bit(IPOIB_FLAG_OPER_UP, &priv->flags))
goto out;
if (!priv->broadcast) {
struct ipoib_mcast *broadcast;
broadcast = ipoib_mcast_alloc(dev, 0);
if (!broadcast) {
ipoib_warn(priv, "failed to allocate broadcast group\n");
__ipoib_mcast_schedule_join_thread(priv, NULL, 1);
goto out;
}
memcpy(broadcast->mcmember.mgid.raw, priv->dev->broadcast + 4,
sizeof (union ib_gid));
priv->broadcast = broadcast;
__ipoib_mcast_add(dev, priv->broadcast);
}
if (!test_bit(IPOIB_MCAST_FLAG_ATTACHED, &priv->broadcast->flags)) {
if (IS_ERR_OR_NULL(priv->broadcast->mc) &&
!test_bit(IPOIB_MCAST_FLAG_BUSY, &priv->broadcast->flags)) {
mcast = priv->broadcast;
if (mcast->backoff > 1 &&
time_before(jiffies, mcast->delay_until)) {
delay_until = mcast->delay_until;
mcast = NULL;
}
}
goto out;
}
list_for_each_entry(mcast, &priv->multicast_list, list) {
if (IS_ERR_OR_NULL(mcast->mc) &&
!test_bit(IPOIB_MCAST_FLAG_BUSY, &mcast->flags) &&
(!test_bit(IPOIB_MCAST_FLAG_SENDONLY, &mcast->flags) ||
!skb_queue_empty(&mcast->pkt_queue))) {
if (mcast->backoff == 1 ||
time_after_eq(jiffies, mcast->delay_until)) {
if (ipoib_mcast_join(dev, mcast)) {
spin_unlock_irq(&priv->lock);
return;
}
} else if (!delay_until ||
time_before(mcast->delay_until, delay_until))
delay_until = mcast->delay_until;
}
}
mcast = NULL;
ipoib_dbg_mcast(priv, "successfully started all multicast joins\n");
out:
if (delay_until) {
cancel_delayed_work(&priv->mcast_task);
queue_delayed_work(priv->wq, &priv->mcast_task,
delay_until - jiffies);
}
if (mcast)
ipoib_mcast_join(dev, mcast);
spin_unlock_irq(&priv->lock);
}
void ipoib_mcast_start_thread(struct net_device *dev)
{
struct ipoib_dev_priv *priv = ipoib_priv(dev);
unsigned long flags;
ipoib_dbg_mcast(priv, "starting multicast thread\n");
spin_lock_irqsave(&priv->lock, flags);
__ipoib_mcast_schedule_join_thread(priv, NULL, 0);
spin_unlock_irqrestore(&priv->lock, flags);
}
int ipoib_mcast_stop_thread(struct net_device *dev)
{
struct ipoib_dev_priv *priv = ipoib_priv(dev);
unsigned long flags;
ipoib_dbg_mcast(priv, "stopping multicast thread\n");
spin_lock_irqsave(&priv->lock, flags);
cancel_delayed_work(&priv->mcast_task);
spin_unlock_irqrestore(&priv->lock, flags);
flush_workqueue(priv->wq);
return 0;
}
static int ipoib_mcast_leave(struct net_device *dev, struct ipoib_mcast *mcast)
{
struct ipoib_dev_priv *priv = ipoib_priv(dev);
struct rdma_netdev *rn = netdev_priv(dev);
int ret = 0;
if (test_and_clear_bit(IPOIB_MCAST_FLAG_BUSY, &mcast->flags))
ipoib_warn(priv, "ipoib_mcast_leave on an in-flight join\n");
if (!IS_ERR_OR_NULL(mcast->mc))
ib_sa_free_multicast(mcast->mc);
if (test_and_clear_bit(IPOIB_MCAST_FLAG_ATTACHED, &mcast->flags)) {
ipoib_dbg_mcast(priv, "leaving MGID %pI6\n",
mcast->mcmember.mgid.raw);
ret = rn->detach_mcast(dev, priv->ca, &mcast->mcmember.mgid,
be16_to_cpu(mcast->mcmember.mlid));
if (ret)
ipoib_warn(priv, "ib_detach_mcast failed (result = %d)\n", ret);
} else if (!test_bit(IPOIB_MCAST_FLAG_SENDONLY, &mcast->flags))
ipoib_dbg(priv, "leaving with no mcmember but not a "
"SENDONLY join\n");
return 0;
}
void ipoib_check_and_add_mcast_sendonly(struct ipoib_dev_priv *priv, u8 *mgid,
struct list_head *remove_list)
{
if (*mgid == 0xff) {
struct ipoib_mcast *mcast = __ipoib_mcast_find(priv->dev, mgid);
if (mcast && test_bit(IPOIB_MCAST_FLAG_SENDONLY, &mcast->flags)) {
list_del(&mcast->list);
rb_erase(&mcast->rb_node, &priv->multicast_tree);
list_add_tail(&mcast->list, remove_list);
}
}
}
void ipoib_mcast_remove_list(struct list_head *remove_list)
{
struct ipoib_mcast *mcast, *tmcast;
list_for_each_entry_safe(mcast, tmcast, remove_list, list) {
ipoib_mcast_leave(mcast->dev, mcast);
ipoib_mcast_free(mcast);
}
}
void ipoib_mcast_send(struct net_device *dev, u8 *daddr, struct sk_buff *skb)
{
struct ipoib_dev_priv *priv = ipoib_priv(dev);
struct rdma_netdev *rn = netdev_priv(dev);
struct ipoib_mcast *mcast;
unsigned long flags;
void *mgid = daddr + 4;
spin_lock_irqsave(&priv->lock, flags);
if (!test_bit(IPOIB_FLAG_OPER_UP, &priv->flags) ||
!priv->broadcast ||
!test_bit(IPOIB_MCAST_FLAG_ATTACHED, &priv->broadcast->flags)) {
++dev->stats.tx_dropped;
dev_kfree_skb_any(skb);
goto unlock;
}
mcast = __ipoib_mcast_find(dev, mgid);
if (!mcast || !mcast->ah) {
if (!mcast) {
ipoib_dbg_mcast(priv, "setting up send only multicast group for %pI6\n",
mgid);
mcast = ipoib_mcast_alloc(dev, 0);
if (!mcast) {
ipoib_warn(priv, "unable to allocate memory "
"for multicast structure\n");
++dev->stats.tx_dropped;
dev_kfree_skb_any(skb);
goto unlock;
}
set_bit(IPOIB_MCAST_FLAG_SENDONLY, &mcast->flags);
memcpy(mcast->mcmember.mgid.raw, mgid,
sizeof (union ib_gid));
__ipoib_mcast_add(dev, mcast);
list_add_tail(&mcast->list, &priv->multicast_list);
}
if (skb_queue_len(&mcast->pkt_queue) < IPOIB_MAX_MCAST_QUEUE) {
skb_push(skb, sizeof(struct ipoib_pseudo_header));
skb_queue_tail(&mcast->pkt_queue, skb);
} else {
++dev->stats.tx_dropped;
dev_kfree_skb_any(skb);
}
if (!test_bit(IPOIB_MCAST_FLAG_BUSY, &mcast->flags)) {
__ipoib_mcast_schedule_join_thread(priv, NULL, 0);
}
} else {
struct ipoib_neigh *neigh;
spin_unlock_irqrestore(&priv->lock, flags);
neigh = ipoib_neigh_get(dev, daddr);
spin_lock_irqsave(&priv->lock, flags);
if (!neigh) {
neigh = ipoib_neigh_alloc(daddr, dev);
if (neigh) {
kref_get(&mcast->ah->ref);
neigh->ah = mcast->ah;
list_add_tail(&neigh->list, &mcast->neigh_list);
}
}
spin_unlock_irqrestore(&priv->lock, flags);
mcast->ah->last_send = rn->send(dev, skb, mcast->ah->ah,
IB_MULTICAST_QPN);
if (neigh)
ipoib_neigh_put(neigh);
return;
}
unlock:
spin_unlock_irqrestore(&priv->lock, flags);
}
void ipoib_mcast_dev_flush(struct net_device *dev)
{
struct ipoib_dev_priv *priv = ipoib_priv(dev);
LIST_HEAD(remove_list);
struct ipoib_mcast *mcast, *tmcast;
unsigned long flags;
ipoib_dbg_mcast(priv, "flushing multicast list\n");
spin_lock_irqsave(&priv->lock, flags);
list_for_each_entry_safe(mcast, tmcast, &priv->multicast_list, list) {
list_del(&mcast->list);
rb_erase(&mcast->rb_node, &priv->multicast_tree);
list_add_tail(&mcast->list, &remove_list);
}
if (priv->broadcast) {
rb_erase(&priv->broadcast->rb_node, &priv->multicast_tree);
list_add_tail(&priv->broadcast->list, &remove_list);
priv->broadcast = NULL;
}
spin_unlock_irqrestore(&priv->lock, flags);
list_for_each_entry_safe(mcast, tmcast, &remove_list, list)
if (test_bit(IPOIB_MCAST_FLAG_BUSY, &mcast->flags))
wait_for_completion(&mcast->done);
ipoib_mcast_remove_list(&remove_list);
}
static int ipoib_mcast_addr_is_valid(const u8 *addr, const u8 *broadcast)
{
if (memcmp(addr, broadcast, 6))
return 0;
if (memcmp(addr + 7, broadcast + 7, 3))
return 0;
return 1;
}
void ipoib_mcast_restart_task(struct work_struct *work)
{
struct ipoib_dev_priv *priv =
container_of(work, struct ipoib_dev_priv, restart_task);
struct net_device *dev = priv->dev;
struct netdev_hw_addr *ha;
struct ipoib_mcast *mcast, *tmcast;
LIST_HEAD(remove_list);
unsigned long flags;
struct ib_sa_mcmember_rec rec;
if (!test_bit(IPOIB_FLAG_OPER_UP, &priv->flags))
return;
ipoib_dbg_mcast(priv, "restarting multicast task\n");
local_irq_save(flags);
netif_addr_lock(dev);
spin_lock(&priv->lock);
list_for_each_entry(mcast, &priv->multicast_list, list)
clear_bit(IPOIB_MCAST_FLAG_FOUND, &mcast->flags);
netdev_for_each_mc_addr(ha, dev) {
union ib_gid mgid;
if (!ipoib_mcast_addr_is_valid(ha->addr, dev->broadcast))
continue;
memcpy(mgid.raw, ha->addr + 4, sizeof mgid);
mcast = __ipoib_mcast_find(dev, &mgid);
if (!mcast || test_bit(IPOIB_MCAST_FLAG_SENDONLY, &mcast->flags)) {
struct ipoib_mcast *nmcast;
if (test_bit(IPOIB_FLAG_UMCAST, &priv->flags) &&
!ib_sa_get_mcmember_rec(priv->ca, priv->port, &mgid, &rec)) {
ipoib_dbg_mcast(priv, "ignoring multicast entry for mgid %pI6\n",
mgid.raw);
continue;
}
ipoib_dbg_mcast(priv, "adding multicast entry for mgid %pI6\n",
mgid.raw);
nmcast = ipoib_mcast_alloc(dev, 0);
if (!nmcast) {
ipoib_warn(priv, "unable to allocate memory for multicast structure\n");
continue;
}
set_bit(IPOIB_MCAST_FLAG_FOUND, &nmcast->flags);
nmcast->mcmember.mgid = mgid;
if (mcast) {
list_move_tail(&mcast->list, &remove_list);
rb_replace_node(&mcast->rb_node,
&nmcast->rb_node,
&priv->multicast_tree);
} else
__ipoib_mcast_add(dev, nmcast);
list_add_tail(&nmcast->list, &priv->multicast_list);
}
if (mcast)
set_bit(IPOIB_MCAST_FLAG_FOUND, &mcast->flags);
}
list_for_each_entry_safe(mcast, tmcast, &priv->multicast_list, list) {
if (!test_bit(IPOIB_MCAST_FLAG_FOUND, &mcast->flags) &&
!test_bit(IPOIB_MCAST_FLAG_SENDONLY, &mcast->flags)) {
ipoib_dbg_mcast(priv, "deleting multicast group %pI6\n",
mcast->mcmember.mgid.raw);
rb_erase(&mcast->rb_node, &priv->multicast_tree);
list_move_tail(&mcast->list, &remove_list);
}
}
spin_unlock(&priv->lock);
netif_addr_unlock(dev);
local_irq_restore(flags);
list_for_each_entry_safe(mcast, tmcast, &remove_list, list)
if (test_bit(IPOIB_MCAST_FLAG_BUSY, &mcast->flags))
wait_for_completion(&mcast->done);
ipoib_mcast_remove_list(&remove_list);
if (test_bit(IPOIB_FLAG_OPER_UP, &priv->flags)) {
spin_lock_irqsave(&priv->lock, flags);
__ipoib_mcast_schedule_join_thread(priv, NULL, 0);
spin_unlock_irqrestore(&priv->lock, flags);
}
}
struct ipoib_mcast_iter *ipoib_mcast_iter_init(struct net_device *dev)
{
struct ipoib_mcast_iter *iter;
iter = kmalloc(sizeof *iter, GFP_KERNEL);
if (!iter)
return NULL;
iter->dev = dev;
memset(iter->mgid.raw, 0, 16);
if (ipoib_mcast_iter_next(iter)) {
kfree(iter);
return NULL;
}
return iter;
}
int ipoib_mcast_iter_next(struct ipoib_mcast_iter *iter)
{
struct ipoib_dev_priv *priv = ipoib_priv(iter->dev);
struct rb_node *n;
struct ipoib_mcast *mcast;
int ret = 1;
spin_lock_irq(&priv->lock);
n = rb_first(&priv->multicast_tree);
while (n) {
mcast = rb_entry(n, struct ipoib_mcast, rb_node);
if (memcmp(iter->mgid.raw, mcast->mcmember.mgid.raw,
sizeof (union ib_gid)) < 0) {
iter->mgid = mcast->mcmember.mgid;
iter->created = mcast->created;
iter->queuelen = skb_queue_len(&mcast->pkt_queue);
iter->complete = !!mcast->ah;
iter->send_only = !!(mcast->flags & (1 << IPOIB_MCAST_FLAG_SENDONLY));
ret = 0;
break;
}
n = rb_next(n);
}
spin_unlock_irq(&priv->lock);
return ret;
}
void ipoib_mcast_iter_read(struct ipoib_mcast_iter *iter,
union ib_gid *mgid,
unsigned long *created,
unsigned int *queuelen,
unsigned int *complete,
unsigned int *send_only)
{
*mgid = iter->mgid;
*created = iter->created;
*queuelen = iter->queuelen;
*complete = iter->complete;
*send_only = iter->send_only;
}
