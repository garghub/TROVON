static void appldata_get_net_sum_data(void *data)
{
int i;
struct appldata_net_sum_data *net_data;
struct net_device *dev;
unsigned long rx_packets, tx_packets, rx_bytes, tx_bytes, rx_errors,
tx_errors, rx_dropped, tx_dropped, collisions;
net_data = data;
net_data->sync_count_1++;
i = 0;
rx_packets = 0;
tx_packets = 0;
rx_bytes = 0;
tx_bytes = 0;
rx_errors = 0;
tx_errors = 0;
rx_dropped = 0;
tx_dropped = 0;
collisions = 0;
rcu_read_lock();
for_each_netdev_rcu(&init_net, dev) {
const struct rtnl_link_stats64 *stats;
struct rtnl_link_stats64 temp;
stats = dev_get_stats(dev, &temp);
rx_packets += stats->rx_packets;
tx_packets += stats->tx_packets;
rx_bytes += stats->rx_bytes;
tx_bytes += stats->tx_bytes;
rx_errors += stats->rx_errors;
tx_errors += stats->tx_errors;
rx_dropped += stats->rx_dropped;
tx_dropped += stats->tx_dropped;
collisions += stats->collisions;
i++;
}
rcu_read_unlock();
net_data->nr_interfaces = i;
net_data->rx_packets = rx_packets;
net_data->tx_packets = tx_packets;
net_data->rx_bytes = rx_bytes;
net_data->tx_bytes = tx_bytes;
net_data->rx_errors = rx_errors;
net_data->tx_errors = tx_errors;
net_data->rx_dropped = rx_dropped;
net_data->tx_dropped = tx_dropped;
net_data->collisions = collisions;
net_data->timestamp = get_tod_clock();
net_data->sync_count_2++;
}
static int __init appldata_net_init(void)
{
return appldata_register_ops(&ops);
}
static void __exit appldata_net_exit(void)
{
appldata_unregister_ops(&ops);
}
