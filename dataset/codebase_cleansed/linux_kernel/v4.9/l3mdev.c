int l3mdev_master_ifindex_rcu(const struct net_device *dev)
{
int ifindex = 0;
if (!dev)
return 0;
if (netif_is_l3_master(dev)) {
ifindex = dev->ifindex;
} else if (netif_is_l3_slave(dev)) {
struct net_device *master;
struct net_device *_dev = (struct net_device *)dev;
master = netdev_master_upper_dev_get_rcu(_dev);
if (master)
ifindex = master->ifindex;
}
return ifindex;
}
u32 l3mdev_fib_table_rcu(const struct net_device *dev)
{
u32 tb_id = 0;
if (!dev)
return 0;
if (netif_is_l3_master(dev)) {
if (dev->l3mdev_ops->l3mdev_fib_table)
tb_id = dev->l3mdev_ops->l3mdev_fib_table(dev);
} else if (netif_is_l3_slave(dev)) {
struct net_device *_dev = (struct net_device *) dev;
const struct net_device *master;
master = netdev_master_upper_dev_get_rcu(_dev);
if (master &&
master->l3mdev_ops->l3mdev_fib_table)
tb_id = master->l3mdev_ops->l3mdev_fib_table(master);
}
return tb_id;
}
u32 l3mdev_fib_table_by_index(struct net *net, int ifindex)
{
struct net_device *dev;
u32 tb_id = 0;
if (!ifindex)
return 0;
rcu_read_lock();
dev = dev_get_by_index_rcu(net, ifindex);
if (dev)
tb_id = l3mdev_fib_table_rcu(dev);
rcu_read_unlock();
return tb_id;
}
struct dst_entry *l3mdev_link_scope_lookup(struct net *net,
struct flowi6 *fl6)
{
struct dst_entry *dst = NULL;
struct net_device *dev;
if (fl6->flowi6_oif) {
rcu_read_lock();
dev = dev_get_by_index_rcu(net, fl6->flowi6_oif);
if (dev && netif_is_l3_slave(dev))
dev = netdev_master_upper_dev_get_rcu(dev);
if (dev && netif_is_l3_master(dev) &&
dev->l3mdev_ops->l3mdev_link_scope_lookup)
dst = dev->l3mdev_ops->l3mdev_link_scope_lookup(dev, fl6);
rcu_read_unlock();
}
return dst;
}
int l3mdev_fib_rule_match(struct net *net, struct flowi *fl,
struct fib_lookup_arg *arg)
{
struct net_device *dev;
int rc = 0;
rcu_read_lock();
dev = dev_get_by_index_rcu(net, fl->flowi_oif);
if (dev && netif_is_l3_master(dev) &&
dev->l3mdev_ops->l3mdev_fib_table) {
arg->table = dev->l3mdev_ops->l3mdev_fib_table(dev);
rc = 1;
goto out;
}
dev = dev_get_by_index_rcu(net, fl->flowi_iif);
if (dev && netif_is_l3_master(dev) &&
dev->l3mdev_ops->l3mdev_fib_table) {
arg->table = dev->l3mdev_ops->l3mdev_fib_table(dev);
rc = 1;
goto out;
}
out:
rcu_read_unlock();
return rc;
}
void l3mdev_update_flow(struct net *net, struct flowi *fl)
{
struct net_device *dev;
int ifindex;
rcu_read_lock();
if (fl->flowi_oif) {
dev = dev_get_by_index_rcu(net, fl->flowi_oif);
if (dev) {
ifindex = l3mdev_master_ifindex_rcu(dev);
if (ifindex) {
fl->flowi_oif = ifindex;
fl->flowi_flags |= FLOWI_FLAG_SKIP_NH_OIF;
goto out;
}
}
}
if (fl->flowi_iif) {
dev = dev_get_by_index_rcu(net, fl->flowi_iif);
if (dev) {
ifindex = l3mdev_master_ifindex_rcu(dev);
if (ifindex) {
fl->flowi_iif = ifindex;
fl->flowi_flags |= FLOWI_FLAG_SKIP_NH_OIF;
}
}
}
out:
rcu_read_unlock();
}
