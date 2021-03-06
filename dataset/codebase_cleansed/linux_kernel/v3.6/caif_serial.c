static inline void update_tty_status(struct ser_device *ser)
{
ser->tty_status =
ser->tty->stopped << 5 |
ser->tty->hw_stopped << 4 |
ser->tty->flow_stopped << 3 |
ser->tty->packet << 2 |
ser->tty->low_latency << 1 |
ser->tty->warned;
}
static inline void debugfs_init(struct ser_device *ser, struct tty_struct *tty)
{
ser->debugfs_tty_dir =
debugfs_create_dir(tty->name, debugfsdir);
if (!IS_ERR(ser->debugfs_tty_dir)) {
debugfs_create_blob("last_tx_msg", S_IRUSR,
ser->debugfs_tty_dir,
&ser->tx_blob);
debugfs_create_blob("last_rx_msg", S_IRUSR,
ser->debugfs_tty_dir,
&ser->rx_blob);
debugfs_create_x32("ser_state", S_IRUSR,
ser->debugfs_tty_dir,
(u32 *)&ser->state);
debugfs_create_x8("tty_status", S_IRUSR,
ser->debugfs_tty_dir,
&ser->tty_status);
}
ser->tx_blob.data = ser->tx_data;
ser->tx_blob.size = 0;
ser->rx_blob.data = ser->rx_data;
ser->rx_blob.size = 0;
}
static inline void debugfs_deinit(struct ser_device *ser)
{
debugfs_remove_recursive(ser->debugfs_tty_dir);
}
static inline void debugfs_rx(struct ser_device *ser, const u8 *data, int size)
{
if (size > sizeof(ser->rx_data))
size = sizeof(ser->rx_data);
memcpy(ser->rx_data, data, size);
ser->rx_blob.data = ser->rx_data;
ser->rx_blob.size = size;
}
static inline void debugfs_tx(struct ser_device *ser, const u8 *data, int size)
{
if (size > sizeof(ser->tx_data))
size = sizeof(ser->tx_data);
memcpy(ser->tx_data, data, size);
ser->tx_blob.data = ser->tx_data;
ser->tx_blob.size = size;
}
static inline void debugfs_init(struct ser_device *ser, struct tty_struct *tty)
{
}
static inline void debugfs_deinit(struct ser_device *ser)
{
}
static inline void update_tty_status(struct ser_device *ser)
{
}
static inline void debugfs_rx(struct ser_device *ser, const u8 *data, int size)
{
}
static inline void debugfs_tx(struct ser_device *ser, const u8 *data, int size)
{
}
static void ldisc_receive(struct tty_struct *tty, const u8 *data,
char *flags, int count)
{
struct sk_buff *skb = NULL;
struct ser_device *ser;
int ret;
u8 *p;
ser = tty->disc_data;
if (!ser->common.use_stx && !ser->tx_started) {
dev_info(&ser->dev->dev,
"Bytes received before initial transmission -"
"bytes discarded.\n");
return;
}
BUG_ON(ser->dev == NULL);
skb = netdev_alloc_skb(ser->dev, count+1);
if (skb == NULL)
return;
p = skb_put(skb, count);
memcpy(p, data, count);
skb->protocol = htons(ETH_P_CAIF);
skb_reset_mac_header(skb);
skb->dev = ser->dev;
debugfs_rx(ser, data, count);
ret = netif_rx_ni(skb);
if (!ret) {
ser->dev->stats.rx_packets++;
ser->dev->stats.rx_bytes += count;
} else
++ser->dev->stats.rx_dropped;
update_tty_status(ser);
}
static int handle_tx(struct ser_device *ser)
{
struct tty_struct *tty;
struct sk_buff *skb;
int tty_wr, len, room;
tty = ser->tty;
ser->tx_started = true;
if (test_and_set_bit(CAIF_SENDING, &ser->state))
return 0;
while ((skb = skb_peek(&ser->head)) != NULL) {
len = skb->len;
room = tty_write_room(tty);
if (!room)
break;
if (room > ser_write_chunk)
room = ser_write_chunk;
if (len > room)
len = room;
if (!ser_loop) {
tty_wr = tty->ops->write(tty, skb->data, len);
update_tty_status(ser);
} else {
tty_wr = len;
ldisc_receive(tty, skb->data, NULL, len);
}
ser->dev->stats.tx_packets++;
ser->dev->stats.tx_bytes += tty_wr;
if (tty_wr < 0)
goto error;
skb_pull(skb, tty_wr);
if (skb->len == 0) {
struct sk_buff *tmp = skb_dequeue(&ser->head);
WARN_ON(tmp != skb);
if (in_interrupt())
dev_kfree_skb_irq(skb);
else
kfree_skb(skb);
}
}
if (ser->head.qlen <= SEND_QUEUE_LOW &&
test_and_clear_bit(CAIF_FLOW_OFF_SENT, &ser->state) &&
ser->common.flowctrl != NULL)
ser->common.flowctrl(ser->dev, ON);
clear_bit(CAIF_SENDING, &ser->state);
return 0;
error:
clear_bit(CAIF_SENDING, &ser->state);
return tty_wr;
}
static int caif_xmit(struct sk_buff *skb, struct net_device *dev)
{
struct ser_device *ser;
BUG_ON(dev == NULL);
ser = netdev_priv(dev);
if (ser->head.qlen > SEND_QUEUE_HIGH &&
!test_and_set_bit(CAIF_FLOW_OFF_SENT, &ser->state) &&
ser->common.flowctrl != NULL)
ser->common.flowctrl(ser->dev, OFF);
skb_queue_tail(&ser->head, skb);
return handle_tx(ser);
}
static void ldisc_tx_wakeup(struct tty_struct *tty)
{
struct ser_device *ser;
ser = tty->disc_data;
BUG_ON(ser == NULL);
WARN_ON(ser->tty != tty);
handle_tx(ser);
}
static int ldisc_open(struct tty_struct *tty)
{
struct ser_device *ser;
struct net_device *dev;
char name[64];
int result;
if (tty->ops->write == NULL)
return -EOPNOTSUPP;
if (!capable(CAP_SYS_ADMIN) && !capable(CAP_SYS_TTY_CONFIG))
return -EPERM;
sprintf(name, "cf%s", tty->name);
dev = alloc_netdev(sizeof(*ser), name, caifdev_setup);
if (!dev)
return -ENOMEM;
ser = netdev_priv(dev);
ser->tty = tty_kref_get(tty);
ser->dev = dev;
debugfs_init(ser, tty);
tty->receive_room = N_TTY_BUF_SIZE;
tty->disc_data = ser;
set_bit(TTY_DO_WRITE_WAKEUP, &tty->flags);
rtnl_lock();
result = register_netdevice(dev);
if (result) {
rtnl_unlock();
free_netdev(dev);
return -ENODEV;
}
list_add(&ser->node, &ser_list);
rtnl_unlock();
netif_stop_queue(dev);
update_tty_status(ser);
return 0;
}
static void ldisc_close(struct tty_struct *tty)
{
struct ser_device *ser = tty->disc_data;
int islocked = rtnl_is_locked();
if (!islocked)
rtnl_lock();
dev_close(ser->dev);
unregister_netdevice(ser->dev);
list_del(&ser->node);
debugfs_deinit(ser);
tty_kref_put(ser->tty);
if (!islocked)
rtnl_unlock();
}
static int register_ldisc(void)
{
int result;
result = tty_register_ldisc(N_CAIF, &caif_ldisc);
if (result < 0) {
pr_err("cannot register CAIF ldisc=%d err=%d\n", N_CAIF,
result);
return result;
}
return result;
}
static void caifdev_setup(struct net_device *dev)
{
struct ser_device *serdev = netdev_priv(dev);
dev->features = 0;
dev->netdev_ops = &netdev_ops;
dev->type = ARPHRD_CAIF;
dev->flags = IFF_POINTOPOINT | IFF_NOARP;
dev->mtu = CAIF_MAX_MTU;
dev->tx_queue_len = 0;
dev->destructor = free_netdev;
skb_queue_head_init(&serdev->head);
serdev->common.link_select = CAIF_LINK_LOW_LATENCY;
serdev->common.use_frag = true;
serdev->common.use_stx = ser_use_stx;
serdev->common.use_fcs = ser_use_fcs;
serdev->dev = dev;
}
static int caif_net_open(struct net_device *dev)
{
netif_wake_queue(dev);
return 0;
}
static int caif_net_close(struct net_device *dev)
{
netif_stop_queue(dev);
return 0;
}
static int __init caif_ser_init(void)
{
int ret;
ret = register_ldisc();
debugfsdir = debugfs_create_dir("caif_serial", NULL);
return ret;
}
static void __exit caif_ser_exit(void)
{
struct ser_device *ser = NULL;
struct list_head *node;
struct list_head *_tmp;
list_for_each_safe(node, _tmp, &ser_list) {
ser = list_entry(node, struct ser_device, node);
dev_close(ser->dev);
unregister_netdevice(ser->dev);
list_del(node);
}
tty_unregister_ldisc(N_CAIF);
debugfs_remove_recursive(debugfsdir);
}
