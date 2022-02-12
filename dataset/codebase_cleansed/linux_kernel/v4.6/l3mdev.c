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
