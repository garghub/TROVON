static void eql_timer(unsigned long param)
{
equalizer_t *eql = (equalizer_t *) param;
struct list_head *this, *tmp, *head;
spin_lock(&eql->queue.lock);
head = &eql->queue.all_slaves;
list_for_each_safe(this, tmp, head) {
slave_t *slave = list_entry(this, slave_t, list);
if ((slave->dev->flags & IFF_UP) == IFF_UP) {
slave->bytes_queued -= slave->priority_Bps;
if (slave->bytes_queued < 0)
slave->bytes_queued = 0;
} else {
eql_kill_one_slave(&eql->queue, slave);
}
}
spin_unlock(&eql->queue.lock);
eql->timer.expires = jiffies + EQL_DEFAULT_RESCHED_IVAL;
add_timer(&eql->timer);
}
static void __init eql_setup(struct net_device *dev)
{
equalizer_t *eql = netdev_priv(dev);
init_timer(&eql->timer);
eql->timer.data = (unsigned long) eql;
eql->timer.expires = jiffies + EQL_DEFAULT_RESCHED_IVAL;
eql->timer.function = eql_timer;
spin_lock_init(&eql->queue.lock);
INIT_LIST_HEAD(&eql->queue.all_slaves);
eql->queue.master_dev = dev;
dev->netdev_ops = &eql_netdev_ops;
dev->mtu = EQL_DEFAULT_MTU;
dev->flags = IFF_MASTER;
dev->type = ARPHRD_SLIP;
dev->tx_queue_len = 5;
dev->priv_flags &= ~IFF_XMIT_DST_RELEASE;
}
static int eql_open(struct net_device *dev)
{
equalizer_t *eql = netdev_priv(dev);
netdev_info(dev,
"remember to turn off Van-Jacobson compression on your slave devices\n");
BUG_ON(!list_empty(&eql->queue.all_slaves));
eql->min_slaves = 1;
eql->max_slaves = EQL_DEFAULT_MAX_SLAVES;
add_timer(&eql->timer);
return 0;
}
static void eql_kill_one_slave(slave_queue_t *queue, slave_t *slave)
{
list_del(&slave->list);
queue->num_slaves--;
slave->dev->flags &= ~IFF_SLAVE;
dev_put(slave->dev);
kfree(slave);
}
static void eql_kill_slave_queue(slave_queue_t *queue)
{
struct list_head *head, *tmp, *this;
spin_lock_bh(&queue->lock);
head = &queue->all_slaves;
list_for_each_safe(this, tmp, head) {
slave_t *s = list_entry(this, slave_t, list);
eql_kill_one_slave(queue, s);
}
spin_unlock_bh(&queue->lock);
}
static int eql_close(struct net_device *dev)
{
equalizer_t *eql = netdev_priv(dev);
del_timer_sync(&eql->timer);
eql_kill_slave_queue(&eql->queue);
return 0;
}
static int eql_ioctl(struct net_device *dev, struct ifreq *ifr, int cmd)
{
if (cmd != EQL_GETMASTRCFG && cmd != EQL_GETSLAVECFG &&
!capable(CAP_NET_ADMIN))
return -EPERM;
switch (cmd) {
case EQL_ENSLAVE:
return eql_enslave(dev, ifr->ifr_data);
case EQL_EMANCIPATE:
return eql_emancipate(dev, ifr->ifr_data);
case EQL_GETSLAVECFG:
return eql_g_slave_cfg(dev, ifr->ifr_data);
case EQL_SETSLAVECFG:
return eql_s_slave_cfg(dev, ifr->ifr_data);
case EQL_GETMASTRCFG:
return eql_g_master_cfg(dev, ifr->ifr_data);
case EQL_SETMASTRCFG:
return eql_s_master_cfg(dev, ifr->ifr_data);
default:
return -EOPNOTSUPP;
}
}
static slave_t *__eql_schedule_slaves(slave_queue_t *queue)
{
unsigned long best_load = ~0UL;
struct list_head *this, *tmp, *head;
slave_t *best_slave;
best_slave = NULL;
head = &queue->all_slaves;
list_for_each_safe(this, tmp, head) {
slave_t *slave = list_entry(this, slave_t, list);
unsigned long slave_load, bytes_queued, priority_Bps;
bytes_queued = slave->bytes_queued;
priority_Bps = slave->priority_Bps;
if ((slave->dev->flags & IFF_UP) == IFF_UP) {
slave_load = (~0UL - (~0UL / 2)) -
(priority_Bps) + bytes_queued * 8;
if (slave_load < best_load) {
best_load = slave_load;
best_slave = slave;
}
} else {
eql_kill_one_slave(queue, slave);
}
}
return best_slave;
}
static netdev_tx_t eql_slave_xmit(struct sk_buff *skb, struct net_device *dev)
{
equalizer_t *eql = netdev_priv(dev);
slave_t *slave;
spin_lock(&eql->queue.lock);
slave = __eql_schedule_slaves(&eql->queue);
if (slave) {
struct net_device *slave_dev = slave->dev;
skb->dev = slave_dev;
skb->priority = TC_PRIO_FILLER;
slave->bytes_queued += skb->len;
dev_queue_xmit(skb);
dev->stats.tx_packets++;
} else {
dev->stats.tx_dropped++;
dev_kfree_skb(skb);
}
spin_unlock(&eql->queue.lock);
return NETDEV_TX_OK;
}
static slave_t *__eql_find_slave_dev(slave_queue_t *queue, struct net_device *dev)
{
struct list_head *this, *head;
head = &queue->all_slaves;
list_for_each(this, head) {
slave_t *slave = list_entry(this, slave_t, list);
if (slave->dev == dev)
return slave;
}
return NULL;
}
static inline int eql_is_full(slave_queue_t *queue)
{
equalizer_t *eql = netdev_priv(queue->master_dev);
if (queue->num_slaves >= eql->max_slaves)
return 1;
return 0;
}
static int __eql_insert_slave(slave_queue_t *queue, slave_t *slave)
{
if (!eql_is_full(queue)) {
slave_t *duplicate_slave = NULL;
duplicate_slave = __eql_find_slave_dev(queue, slave->dev);
if (duplicate_slave)
eql_kill_one_slave(queue, duplicate_slave);
dev_hold(slave->dev);
list_add(&slave->list, &queue->all_slaves);
queue->num_slaves++;
slave->dev->flags |= IFF_SLAVE;
return 0;
}
return -ENOSPC;
}
static int eql_enslave(struct net_device *master_dev, slaving_request_t __user *srqp)
{
struct net_device *slave_dev;
slaving_request_t srq;
if (copy_from_user(&srq, srqp, sizeof (slaving_request_t)))
return -EFAULT;
slave_dev = __dev_get_by_name(&init_net, srq.slave_name);
if (!slave_dev)
return -ENODEV;
if ((master_dev->flags & IFF_UP) == IFF_UP) {
if (!eql_is_master(slave_dev) && !eql_is_slave(slave_dev)) {
slave_t *s = kmalloc(sizeof(*s), GFP_KERNEL);
equalizer_t *eql = netdev_priv(master_dev);
int ret;
if (!s)
return -ENOMEM;
memset(s, 0, sizeof(*s));
s->dev = slave_dev;
s->priority = srq.priority;
s->priority_bps = srq.priority;
s->priority_Bps = srq.priority / 8;
spin_lock_bh(&eql->queue.lock);
ret = __eql_insert_slave(&eql->queue, s);
if (ret)
kfree(s);
spin_unlock_bh(&eql->queue.lock);
return ret;
}
}
return -EINVAL;
}
static int eql_emancipate(struct net_device *master_dev, slaving_request_t __user *srqp)
{
equalizer_t *eql = netdev_priv(master_dev);
struct net_device *slave_dev;
slaving_request_t srq;
int ret;
if (copy_from_user(&srq, srqp, sizeof (slaving_request_t)))
return -EFAULT;
slave_dev = __dev_get_by_name(&init_net, srq.slave_name);
if (!slave_dev)
return -ENODEV;
ret = -EINVAL;
spin_lock_bh(&eql->queue.lock);
if (eql_is_slave(slave_dev)) {
slave_t *slave = __eql_find_slave_dev(&eql->queue, slave_dev);
if (slave) {
eql_kill_one_slave(&eql->queue, slave);
ret = 0;
}
}
spin_unlock_bh(&eql->queue.lock);
return ret;
}
static int eql_g_slave_cfg(struct net_device *dev, slave_config_t __user *scp)
{
equalizer_t *eql = netdev_priv(dev);
slave_t *slave;
struct net_device *slave_dev;
slave_config_t sc;
int ret;
if (copy_from_user(&sc, scp, sizeof (slave_config_t)))
return -EFAULT;
slave_dev = __dev_get_by_name(&init_net, sc.slave_name);
if (!slave_dev)
return -ENODEV;
ret = -EINVAL;
spin_lock_bh(&eql->queue.lock);
if (eql_is_slave(slave_dev)) {
slave = __eql_find_slave_dev(&eql->queue, slave_dev);
if (slave) {
sc.priority = slave->priority;
ret = 0;
}
}
spin_unlock_bh(&eql->queue.lock);
if (!ret && copy_to_user(scp, &sc, sizeof (slave_config_t)))
ret = -EFAULT;
return ret;
}
static int eql_s_slave_cfg(struct net_device *dev, slave_config_t __user *scp)
{
slave_t *slave;
equalizer_t *eql;
struct net_device *slave_dev;
slave_config_t sc;
int ret;
if (copy_from_user(&sc, scp, sizeof (slave_config_t)))
return -EFAULT;
slave_dev = __dev_get_by_name(&init_net, sc.slave_name);
if (!slave_dev)
return -ENODEV;
ret = -EINVAL;
eql = netdev_priv(dev);
spin_lock_bh(&eql->queue.lock);
if (eql_is_slave(slave_dev)) {
slave = __eql_find_slave_dev(&eql->queue, slave_dev);
if (slave) {
slave->priority = sc.priority;
slave->priority_bps = sc.priority;
slave->priority_Bps = sc.priority / 8;
ret = 0;
}
}
spin_unlock_bh(&eql->queue.lock);
return ret;
}
static int eql_g_master_cfg(struct net_device *dev, master_config_t __user *mcp)
{
equalizer_t *eql;
master_config_t mc;
memset(&mc, 0, sizeof(master_config_t));
if (eql_is_master(dev)) {
eql = netdev_priv(dev);
mc.max_slaves = eql->max_slaves;
mc.min_slaves = eql->min_slaves;
if (copy_to_user(mcp, &mc, sizeof (master_config_t)))
return -EFAULT;
return 0;
}
return -EINVAL;
}
static int eql_s_master_cfg(struct net_device *dev, master_config_t __user *mcp)
{
equalizer_t *eql;
master_config_t mc;
if (copy_from_user(&mc, mcp, sizeof (master_config_t)))
return -EFAULT;
if (eql_is_master(dev)) {
eql = netdev_priv(dev);
eql->max_slaves = mc.max_slaves;
eql->min_slaves = mc.min_slaves;
return 0;
}
return -EINVAL;
}
static int __init eql_init_module(void)
{
int err;
pr_info("%s\n", version);
dev_eql = alloc_netdev(sizeof(equalizer_t), "eql", NET_NAME_UNKNOWN,
eql_setup);
if (!dev_eql)
return -ENOMEM;
err = register_netdev(dev_eql);
if (err)
free_netdev(dev_eql);
return err;
}
static void __exit eql_cleanup_module(void)
{
unregister_netdev(dev_eql);
free_netdev(dev_eql);
}
