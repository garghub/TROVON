static struct lapbethdev *lapbeth_get_x25_dev(struct net_device *dev)
{
struct lapbethdev *lapbeth;
list_for_each_entry_rcu(lapbeth, &lapbeth_devices, node) {
if (lapbeth->ethdev == dev)
return lapbeth;
}
return NULL;
}
static __inline__ int dev_is_ethdev(struct net_device *dev)
{
return dev->type == ARPHRD_ETHER && strncmp(dev->name, "dummy", 5);
}
static int lapbeth_rcv(struct sk_buff *skb, struct net_device *dev, struct packet_type *ptype, struct net_device *orig_dev)
{
int len, err;
struct lapbethdev *lapbeth;
if (dev_net(dev) != &init_net)
goto drop;
if ((skb = skb_share_check(skb, GFP_ATOMIC)) == NULL)
return NET_RX_DROP;
if (!pskb_may_pull(skb, 2))
goto drop;
rcu_read_lock();
lapbeth = lapbeth_get_x25_dev(dev);
if (!lapbeth)
goto drop_unlock;
if (!netif_running(lapbeth->axdev))
goto drop_unlock;
len = skb->data[0] + skb->data[1] * 256;
dev->stats.rx_packets++;
dev->stats.rx_bytes += len;
skb_pull(skb, 2);
skb_trim(skb, len);
if ((err = lapb_data_received(lapbeth->axdev, skb)) != LAPB_OK) {
printk(KERN_DEBUG "lapbether: lapb_data_received err - %d\n", err);
goto drop_unlock;
}
out:
rcu_read_unlock();
return 0;
drop_unlock:
kfree_skb(skb);
goto out;
drop:
kfree_skb(skb);
return 0;
}
static int lapbeth_data_indication(struct net_device *dev, struct sk_buff *skb)
{
unsigned char *ptr;
skb_push(skb, 1);
if (skb_cow(skb, 1))
return NET_RX_DROP;
ptr = skb->data;
*ptr = X25_IFACE_DATA;
skb->protocol = x25_type_trans(skb, dev);
return netif_rx(skb);
}
static netdev_tx_t lapbeth_xmit(struct sk_buff *skb,
struct net_device *dev)
{
int err;
if (!netif_running(dev))
goto drop;
switch (skb->data[0]) {
case X25_IFACE_DATA:
break;
case X25_IFACE_CONNECT:
if ((err = lapb_connect_request(dev)) != LAPB_OK)
pr_err("lapb_connect_request error: %d\n", err);
goto drop;
case X25_IFACE_DISCONNECT:
if ((err = lapb_disconnect_request(dev)) != LAPB_OK)
pr_err("lapb_disconnect_request err: %d\n", err);
default:
goto drop;
}
skb_pull(skb, 1);
if ((err = lapb_data_request(dev, skb)) != LAPB_OK) {
pr_err("lapb_data_request error - %d\n", err);
goto drop;
}
out:
return NETDEV_TX_OK;
drop:
kfree_skb(skb);
goto out;
}
static void lapbeth_data_transmit(struct net_device *ndev, struct sk_buff *skb)
{
struct lapbethdev *lapbeth = netdev_priv(ndev);
unsigned char *ptr;
struct net_device *dev;
int size = skb->len;
skb->protocol = htons(ETH_P_X25);
ptr = skb_push(skb, 2);
*ptr++ = size % 256;
*ptr++ = size / 256;
ndev->stats.tx_packets++;
ndev->stats.tx_bytes += size;
skb->dev = dev = lapbeth->ethdev;
dev_hard_header(skb, dev, ETH_P_DEC, bcast_addr, NULL, 0);
dev_queue_xmit(skb);
}
static void lapbeth_connected(struct net_device *dev, int reason)
{
unsigned char *ptr;
struct sk_buff *skb = dev_alloc_skb(1);
if (!skb) {
pr_err("out of memory\n");
return;
}
ptr = skb_put(skb, 1);
*ptr = X25_IFACE_CONNECT;
skb->protocol = x25_type_trans(skb, dev);
netif_rx(skb);
}
static void lapbeth_disconnected(struct net_device *dev, int reason)
{
unsigned char *ptr;
struct sk_buff *skb = dev_alloc_skb(1);
if (!skb) {
pr_err("out of memory\n");
return;
}
ptr = skb_put(skb, 1);
*ptr = X25_IFACE_DISCONNECT;
skb->protocol = x25_type_trans(skb, dev);
netif_rx(skb);
}
static int lapbeth_set_mac_address(struct net_device *dev, void *addr)
{
struct sockaddr *sa = addr;
memcpy(dev->dev_addr, sa->sa_data, dev->addr_len);
return 0;
}
static int lapbeth_open(struct net_device *dev)
{
int err;
if ((err = lapb_register(dev, &lapbeth_callbacks)) != LAPB_OK) {
pr_err("lapb_register error: %d\n", err);
return -ENODEV;
}
netif_start_queue(dev);
return 0;
}
static int lapbeth_close(struct net_device *dev)
{
int err;
netif_stop_queue(dev);
if ((err = lapb_unregister(dev)) != LAPB_OK)
pr_err("lapb_unregister error: %d\n", err);
return 0;
}
static void lapbeth_setup(struct net_device *dev)
{
dev->netdev_ops = &lapbeth_netdev_ops;
dev->needs_free_netdev = true;
dev->type = ARPHRD_X25;
dev->hard_header_len = 3;
dev->mtu = 1000;
dev->addr_len = 0;
}
static int lapbeth_new_device(struct net_device *dev)
{
struct net_device *ndev;
struct lapbethdev *lapbeth;
int rc = -ENOMEM;
ASSERT_RTNL();
ndev = alloc_netdev(sizeof(*lapbeth), "lapb%d", NET_NAME_UNKNOWN,
lapbeth_setup);
if (!ndev)
goto out;
lapbeth = netdev_priv(ndev);
lapbeth->axdev = ndev;
dev_hold(dev);
lapbeth->ethdev = dev;
rc = -EIO;
if (register_netdevice(ndev))
goto fail;
list_add_rcu(&lapbeth->node, &lapbeth_devices);
rc = 0;
out:
return rc;
fail:
dev_put(dev);
free_netdev(ndev);
kfree(lapbeth);
goto out;
}
static void lapbeth_free_device(struct lapbethdev *lapbeth)
{
dev_put(lapbeth->ethdev);
list_del_rcu(&lapbeth->node);
unregister_netdevice(lapbeth->axdev);
}
static int lapbeth_device_event(struct notifier_block *this,
unsigned long event, void *ptr)
{
struct lapbethdev *lapbeth;
struct net_device *dev = netdev_notifier_info_to_dev(ptr);
if (dev_net(dev) != &init_net)
return NOTIFY_DONE;
if (!dev_is_ethdev(dev))
return NOTIFY_DONE;
switch (event) {
case NETDEV_UP:
if (lapbeth_get_x25_dev(dev) == NULL)
lapbeth_new_device(dev);
break;
case NETDEV_DOWN:
lapbeth = lapbeth_get_x25_dev(dev);
if (lapbeth)
dev_close(lapbeth->axdev);
break;
case NETDEV_UNREGISTER:
lapbeth = lapbeth_get_x25_dev(dev);
if (lapbeth)
lapbeth_free_device(lapbeth);
break;
}
return NOTIFY_DONE;
}
static int __init lapbeth_init_driver(void)
{
dev_add_pack(&lapbeth_packet_type);
register_netdevice_notifier(&lapbeth_dev_notifier);
printk(banner);
return 0;
}
static void __exit lapbeth_cleanup_driver(void)
{
struct lapbethdev *lapbeth;
struct list_head *entry, *tmp;
dev_remove_pack(&lapbeth_packet_type);
unregister_netdevice_notifier(&lapbeth_dev_notifier);
rtnl_lock();
list_for_each_safe(entry, tmp, &lapbeth_devices) {
lapbeth = list_entry(entry, struct lapbethdev, node);
dev_put(lapbeth->ethdev);
unregister_netdevice(lapbeth->axdev);
}
rtnl_unlock();
}
