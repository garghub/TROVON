static void bpq_set_lockdep_class_one(struct net_device *dev,
struct netdev_queue *txq,
void *_unused)
{
lockdep_set_class(&txq->_xmit_lock, &bpq_netdev_xmit_lock_key);
}
static void bpq_set_lockdep_class(struct net_device *dev)
{
lockdep_set_class(&dev->addr_list_lock, &bpq_netdev_addr_lock_key);
netdev_for_each_tx_queue(dev, bpq_set_lockdep_class_one, NULL);
}
static inline struct net_device *bpq_get_ether_dev(struct net_device *dev)
{
struct bpqdev *bpq = netdev_priv(dev);
return bpq ? bpq->ethdev : NULL;
}
static inline struct net_device *bpq_get_ax25_dev(struct net_device *dev)
{
struct bpqdev *bpq;
list_for_each_entry_rcu(bpq, &bpq_devices, bpq_list) {
if (bpq->ethdev == dev)
return bpq->axdev;
}
return NULL;
}
static inline int dev_is_ethdev(struct net_device *dev)
{
return dev->type == ARPHRD_ETHER && strncmp(dev->name, "dummy", 5);
}
static int bpq_rcv(struct sk_buff *skb, struct net_device *dev, struct packet_type *ptype, struct net_device *orig_dev)
{
int len;
char * ptr;
struct ethhdr *eth;
struct bpqdev *bpq;
if (!net_eq(dev_net(dev), &init_net))
goto drop;
if ((skb = skb_share_check(skb, GFP_ATOMIC)) == NULL)
return NET_RX_DROP;
if (!pskb_may_pull(skb, sizeof(struct ethhdr)))
goto drop;
rcu_read_lock();
dev = bpq_get_ax25_dev(dev);
if (dev == NULL || !netif_running(dev))
goto drop_unlock;
bpq = netdev_priv(dev);
eth = eth_hdr(skb);
if (!(bpq->acpt_addr[0] & 0x01) &&
!ether_addr_equal(eth->h_source, bpq->acpt_addr))
goto drop_unlock;
if (skb_cow(skb, sizeof(struct ethhdr)))
goto drop_unlock;
len = skb->data[0] + skb->data[1] * 256 - 5;
skb_pull(skb, 2);
skb_trim(skb, len);
dev->stats.rx_packets++;
dev->stats.rx_bytes += len;
ptr = skb_push(skb, 1);
*ptr = 0;
skb->protocol = ax25_type_trans(skb, dev);
netif_rx(skb);
unlock:
rcu_read_unlock();
return 0;
drop_unlock:
kfree_skb(skb);
goto unlock;
drop:
kfree_skb(skb);
return 0;
}
static netdev_tx_t bpq_xmit(struct sk_buff *skb, struct net_device *dev)
{
unsigned char *ptr;
struct bpqdev *bpq;
struct net_device *orig_dev;
int size;
if (skb->protocol == htons(ETH_P_IP))
return ax25_ip_xmit(skb);
if (!netif_running(dev)) {
kfree_skb(skb);
return NETDEV_TX_OK;
}
skb_pull(skb, 1);
size = skb->len;
if (skb_cow(skb, AX25_BPQ_HEADER_LEN)) {
if (net_ratelimit())
pr_err("bpqether: out of memory\n");
kfree_skb(skb);
return NETDEV_TX_OK;
}
ptr = skb_push(skb, 2);
*ptr++ = (size + 5) % 256;
*ptr++ = (size + 5) / 256;
bpq = netdev_priv(dev);
orig_dev = dev;
if ((dev = bpq_get_ether_dev(dev)) == NULL) {
orig_dev->stats.tx_dropped++;
kfree_skb(skb);
return NETDEV_TX_OK;
}
skb->protocol = ax25_type_trans(skb, dev);
skb_reset_network_header(skb);
dev_hard_header(skb, dev, ETH_P_BPQ, bpq->dest_addr, NULL, 0);
dev->stats.tx_packets++;
dev->stats.tx_bytes+=skb->len;
dev_queue_xmit(skb);
netif_wake_queue(dev);
return NETDEV_TX_OK;
}
static int bpq_set_mac_address(struct net_device *dev, void *addr)
{
struct sockaddr *sa = (struct sockaddr *)addr;
memcpy(dev->dev_addr, sa->sa_data, dev->addr_len);
return 0;
}
static int bpq_ioctl(struct net_device *dev, struct ifreq *ifr, int cmd)
{
struct bpq_ethaddr __user *ethaddr = ifr->ifr_data;
struct bpqdev *bpq = netdev_priv(dev);
struct bpq_req req;
if (!capable(CAP_NET_ADMIN))
return -EPERM;
switch (cmd) {
case SIOCSBPQETHOPT:
if (copy_from_user(&req, ifr->ifr_data, sizeof(struct bpq_req)))
return -EFAULT;
switch (req.cmd) {
case SIOCGBPQETHPARAM:
case SIOCSBPQETHPARAM:
default:
return -EINVAL;
}
break;
case SIOCSBPQETHADDR:
if (copy_from_user(bpq->dest_addr, ethaddr->destination, ETH_ALEN))
return -EFAULT;
if (copy_from_user(bpq->acpt_addr, ethaddr->accept, ETH_ALEN))
return -EFAULT;
break;
default:
return -EINVAL;
}
return 0;
}
static int bpq_open(struct net_device *dev)
{
netif_start_queue(dev);
return 0;
}
static int bpq_close(struct net_device *dev)
{
netif_stop_queue(dev);
return 0;
}
static void *bpq_seq_start(struct seq_file *seq, loff_t *pos)
__acquires(RCU)
{
int i = 1;
struct bpqdev *bpqdev;
rcu_read_lock();
if (*pos == 0)
return SEQ_START_TOKEN;
list_for_each_entry_rcu(bpqdev, &bpq_devices, bpq_list) {
if (i == *pos)
return bpqdev;
}
return NULL;
}
static void *bpq_seq_next(struct seq_file *seq, void *v, loff_t *pos)
{
struct list_head *p;
struct bpqdev *bpqdev = v;
++*pos;
if (v == SEQ_START_TOKEN)
p = rcu_dereference(list_next_rcu(&bpq_devices));
else
p = rcu_dereference(list_next_rcu(&bpqdev->bpq_list));
return (p == &bpq_devices) ? NULL
: list_entry(p, struct bpqdev, bpq_list);
}
static void bpq_seq_stop(struct seq_file *seq, void *v)
__releases(RCU)
{
rcu_read_unlock();
}
static int bpq_seq_show(struct seq_file *seq, void *v)
{
if (v == SEQ_START_TOKEN)
seq_puts(seq,
"dev ether destination accept from\n");
else {
const struct bpqdev *bpqdev = v;
seq_printf(seq, "%-5s %-10s %pM ",
bpqdev->axdev->name, bpqdev->ethdev->name,
bpqdev->dest_addr);
if (is_multicast_ether_addr(bpqdev->acpt_addr))
seq_printf(seq, "*\n");
else
seq_printf(seq, "%pM\n", bpqdev->acpt_addr);
}
return 0;
}
static int bpq_info_open(struct inode *inode, struct file *file)
{
return seq_open(file, &bpq_seqops);
}
static void bpq_setup(struct net_device *dev)
{
dev->netdev_ops = &bpq_netdev_ops;
dev->destructor = free_netdev;
memcpy(dev->broadcast, &ax25_bcast, AX25_ADDR_LEN);
memcpy(dev->dev_addr, &ax25_defaddr, AX25_ADDR_LEN);
dev->flags = 0;
#if defined(CONFIG_AX25) || defined(CONFIG_AX25_MODULE)
dev->header_ops = &ax25_header_ops;
#endif
dev->type = ARPHRD_AX25;
dev->hard_header_len = AX25_MAX_HEADER_LEN + AX25_BPQ_HEADER_LEN;
dev->mtu = AX25_DEF_PACLEN;
dev->addr_len = AX25_ADDR_LEN;
}
static int bpq_new_device(struct net_device *edev)
{
int err;
struct net_device *ndev;
struct bpqdev *bpq;
ndev = alloc_netdev(sizeof(struct bpqdev), "bpq%d", NET_NAME_UNKNOWN,
bpq_setup);
if (!ndev)
return -ENOMEM;
bpq = netdev_priv(ndev);
dev_hold(edev);
bpq->ethdev = edev;
bpq->axdev = ndev;
memcpy(bpq->dest_addr, bcast_addr, sizeof(bpq_eth_addr));
memcpy(bpq->acpt_addr, bcast_addr, sizeof(bpq_eth_addr));
err = register_netdevice(ndev);
if (err)
goto error;
bpq_set_lockdep_class(ndev);
list_add_rcu(&bpq->bpq_list, &bpq_devices);
return 0;
error:
dev_put(edev);
free_netdev(ndev);
return err;
}
static void bpq_free_device(struct net_device *ndev)
{
struct bpqdev *bpq = netdev_priv(ndev);
dev_put(bpq->ethdev);
list_del_rcu(&bpq->bpq_list);
unregister_netdevice(ndev);
}
static int bpq_device_event(struct notifier_block *this,
unsigned long event, void *ptr)
{
struct net_device *dev = netdev_notifier_info_to_dev(ptr);
if (!net_eq(dev_net(dev), &init_net))
return NOTIFY_DONE;
if (!dev_is_ethdev(dev))
return NOTIFY_DONE;
switch (event) {
case NETDEV_UP:
if (bpq_get_ax25_dev(dev) == NULL)
bpq_new_device(dev);
break;
case NETDEV_DOWN:
if ((dev = bpq_get_ax25_dev(dev)) != NULL)
dev_close(dev);
break;
case NETDEV_UNREGISTER:
if ((dev = bpq_get_ax25_dev(dev)) != NULL)
bpq_free_device(dev);
break;
default:
break;
}
return NOTIFY_DONE;
}
static int __init bpq_init_driver(void)
{
#ifdef CONFIG_PROC_FS
if (!proc_create("bpqether", S_IRUGO, init_net.proc_net,
&bpq_info_fops)) {
printk(KERN_ERR
"bpq: cannot create /proc/net/bpqether entry.\n");
return -ENOENT;
}
#endif
dev_add_pack(&bpq_packet_type);
register_netdevice_notifier(&bpq_dev_notifier);
printk(banner);
return 0;
}
static void __exit bpq_cleanup_driver(void)
{
struct bpqdev *bpq;
dev_remove_pack(&bpq_packet_type);
unregister_netdevice_notifier(&bpq_dev_notifier);
remove_proc_entry("bpqether", init_net.proc_net);
rtnl_lock();
while (!list_empty(&bpq_devices)) {
bpq = list_entry(bpq_devices.next, struct bpqdev, bpq_list);
bpq_free_device(bpq->axdev);
}
rtnl_unlock();
}
