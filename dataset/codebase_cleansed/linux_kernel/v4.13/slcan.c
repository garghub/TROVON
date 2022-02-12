static void slc_bump(struct slcan *sl)
{
struct sk_buff *skb;
struct can_frame cf;
int i, tmp;
u32 tmpid;
char *cmd = sl->rbuff;
cf.can_id = 0;
switch (*cmd) {
case 'r':
cf.can_id = CAN_RTR_FLAG;
case 't':
cf.can_dlc = sl->rbuff[SLC_CMD_LEN + SLC_SFF_ID_LEN];
sl->rbuff[SLC_CMD_LEN + SLC_SFF_ID_LEN] = 0;
cmd += SLC_CMD_LEN + SLC_SFF_ID_LEN + 1;
break;
case 'R':
cf.can_id = CAN_RTR_FLAG;
case 'T':
cf.can_id |= CAN_EFF_FLAG;
cf.can_dlc = sl->rbuff[SLC_CMD_LEN + SLC_EFF_ID_LEN];
sl->rbuff[SLC_CMD_LEN + SLC_EFF_ID_LEN] = 0;
cmd += SLC_CMD_LEN + SLC_EFF_ID_LEN + 1;
break;
default:
return;
}
if (kstrtou32(sl->rbuff + SLC_CMD_LEN, 16, &tmpid))
return;
cf.can_id |= tmpid;
if (cf.can_dlc >= '0' && cf.can_dlc < '9')
cf.can_dlc -= '0';
else
return;
*(u64 *) (&cf.data) = 0;
if (!(cf.can_id & CAN_RTR_FLAG)) {
for (i = 0; i < cf.can_dlc; i++) {
tmp = hex_to_bin(*cmd++);
if (tmp < 0)
return;
cf.data[i] = (tmp << 4);
tmp = hex_to_bin(*cmd++);
if (tmp < 0)
return;
cf.data[i] |= tmp;
}
}
skb = dev_alloc_skb(sizeof(struct can_frame) +
sizeof(struct can_skb_priv));
if (!skb)
return;
skb->dev = sl->dev;
skb->protocol = htons(ETH_P_CAN);
skb->pkt_type = PACKET_BROADCAST;
skb->ip_summed = CHECKSUM_UNNECESSARY;
can_skb_reserve(skb);
can_skb_prv(skb)->ifindex = sl->dev->ifindex;
can_skb_prv(skb)->skbcnt = 0;
skb_put_data(skb, &cf, sizeof(struct can_frame));
sl->dev->stats.rx_packets++;
sl->dev->stats.rx_bytes += cf.can_dlc;
netif_rx_ni(skb);
}
static void slcan_unesc(struct slcan *sl, unsigned char s)
{
if ((s == '\r') || (s == '\a')) {
if (!test_and_clear_bit(SLF_ERROR, &sl->flags) &&
(sl->rcount > 4)) {
slc_bump(sl);
}
sl->rcount = 0;
} else {
if (!test_bit(SLF_ERROR, &sl->flags)) {
if (sl->rcount < SLC_MTU) {
sl->rbuff[sl->rcount++] = s;
return;
} else {
sl->dev->stats.rx_over_errors++;
set_bit(SLF_ERROR, &sl->flags);
}
}
}
}
static void slc_encaps(struct slcan *sl, struct can_frame *cf)
{
int actual, i;
unsigned char *pos;
unsigned char *endpos;
canid_t id = cf->can_id;
pos = sl->xbuff;
if (cf->can_id & CAN_RTR_FLAG)
*pos = 'R';
else
*pos = 'T';
if (cf->can_id & CAN_EFF_FLAG) {
id &= CAN_EFF_MASK;
endpos = pos + SLC_EFF_ID_LEN;
} else {
*pos |= 0x20;
id &= CAN_SFF_MASK;
endpos = pos + SLC_SFF_ID_LEN;
}
pos++;
while (endpos >= pos) {
*endpos-- = hex_asc_upper[id & 0xf];
id >>= 4;
}
pos += (cf->can_id & CAN_EFF_FLAG) ? SLC_EFF_ID_LEN : SLC_SFF_ID_LEN;
*pos++ = cf->can_dlc + '0';
if (!(cf->can_id & CAN_RTR_FLAG)) {
for (i = 0; i < cf->can_dlc; i++)
pos = hex_byte_pack_upper(pos, cf->data[i]);
}
*pos++ = '\r';
set_bit(TTY_DO_WRITE_WAKEUP, &sl->tty->flags);
actual = sl->tty->ops->write(sl->tty, sl->xbuff, pos - sl->xbuff);
sl->xleft = (pos - sl->xbuff) - actual;
sl->xhead = sl->xbuff + actual;
sl->dev->stats.tx_bytes += cf->can_dlc;
}
static void slcan_transmit(struct work_struct *work)
{
struct slcan *sl = container_of(work, struct slcan, tx_work);
int actual;
spin_lock_bh(&sl->lock);
if (!sl->tty || sl->magic != SLCAN_MAGIC || !netif_running(sl->dev)) {
spin_unlock_bh(&sl->lock);
return;
}
if (sl->xleft <= 0) {
sl->dev->stats.tx_packets++;
clear_bit(TTY_DO_WRITE_WAKEUP, &sl->tty->flags);
spin_unlock_bh(&sl->lock);
netif_wake_queue(sl->dev);
return;
}
actual = sl->tty->ops->write(sl->tty, sl->xhead, sl->xleft);
sl->xleft -= actual;
sl->xhead += actual;
spin_unlock_bh(&sl->lock);
}
static void slcan_write_wakeup(struct tty_struct *tty)
{
struct slcan *sl = tty->disc_data;
schedule_work(&sl->tx_work);
}
static netdev_tx_t slc_xmit(struct sk_buff *skb, struct net_device *dev)
{
struct slcan *sl = netdev_priv(dev);
if (skb->len != CAN_MTU)
goto out;
spin_lock(&sl->lock);
if (!netif_running(dev)) {
spin_unlock(&sl->lock);
printk(KERN_WARNING "%s: xmit: iface is down\n", dev->name);
goto out;
}
if (sl->tty == NULL) {
spin_unlock(&sl->lock);
goto out;
}
netif_stop_queue(sl->dev);
slc_encaps(sl, (struct can_frame *) skb->data);
spin_unlock(&sl->lock);
out:
kfree_skb(skb);
return NETDEV_TX_OK;
}
static int slc_close(struct net_device *dev)
{
struct slcan *sl = netdev_priv(dev);
spin_lock_bh(&sl->lock);
if (sl->tty) {
clear_bit(TTY_DO_WRITE_WAKEUP, &sl->tty->flags);
}
netif_stop_queue(dev);
sl->rcount = 0;
sl->xleft = 0;
spin_unlock_bh(&sl->lock);
return 0;
}
static int slc_open(struct net_device *dev)
{
struct slcan *sl = netdev_priv(dev);
if (sl->tty == NULL)
return -ENODEV;
sl->flags &= (1 << SLF_INUSE);
netif_start_queue(dev);
return 0;
}
static void slc_free_netdev(struct net_device *dev)
{
int i = dev->base_addr;
slcan_devs[i] = NULL;
}
static int slcan_change_mtu(struct net_device *dev, int new_mtu)
{
return -EINVAL;
}
static void slc_setup(struct net_device *dev)
{
dev->netdev_ops = &slc_netdev_ops;
dev->needs_free_netdev = true;
dev->priv_destructor = slc_free_netdev;
dev->hard_header_len = 0;
dev->addr_len = 0;
dev->tx_queue_len = 10;
dev->mtu = CAN_MTU;
dev->type = ARPHRD_CAN;
dev->flags = IFF_NOARP;
dev->features = NETIF_F_HW_CSUM;
}
static void slcan_receive_buf(struct tty_struct *tty,
const unsigned char *cp, char *fp, int count)
{
struct slcan *sl = (struct slcan *) tty->disc_data;
if (!sl || sl->magic != SLCAN_MAGIC || !netif_running(sl->dev))
return;
while (count--) {
if (fp && *fp++) {
if (!test_and_set_bit(SLF_ERROR, &sl->flags))
sl->dev->stats.rx_errors++;
cp++;
continue;
}
slcan_unesc(sl, *cp++);
}
}
static void slc_sync(void)
{
int i;
struct net_device *dev;
struct slcan *sl;
for (i = 0; i < maxdev; i++) {
dev = slcan_devs[i];
if (dev == NULL)
break;
sl = netdev_priv(dev);
if (sl->tty)
continue;
if (dev->flags & IFF_UP)
dev_close(dev);
}
}
static struct slcan *slc_alloc(dev_t line)
{
int i;
char name[IFNAMSIZ];
struct net_device *dev = NULL;
struct slcan *sl;
for (i = 0; i < maxdev; i++) {
dev = slcan_devs[i];
if (dev == NULL)
break;
}
if (i >= maxdev)
return NULL;
sprintf(name, "slcan%d", i);
dev = alloc_netdev(sizeof(*sl), name, NET_NAME_UNKNOWN, slc_setup);
if (!dev)
return NULL;
dev->base_addr = i;
sl = netdev_priv(dev);
sl->magic = SLCAN_MAGIC;
sl->dev = dev;
spin_lock_init(&sl->lock);
INIT_WORK(&sl->tx_work, slcan_transmit);
slcan_devs[i] = dev;
return sl;
}
static int slcan_open(struct tty_struct *tty)
{
struct slcan *sl;
int err;
if (!capable(CAP_NET_ADMIN))
return -EPERM;
if (tty->ops->write == NULL)
return -EOPNOTSUPP;
rtnl_lock();
slc_sync();
sl = tty->disc_data;
err = -EEXIST;
if (sl && sl->magic == SLCAN_MAGIC)
goto err_exit;
err = -ENFILE;
sl = slc_alloc(tty_devnum(tty));
if (sl == NULL)
goto err_exit;
sl->tty = tty;
tty->disc_data = sl;
if (!test_bit(SLF_INUSE, &sl->flags)) {
sl->rcount = 0;
sl->xleft = 0;
set_bit(SLF_INUSE, &sl->flags);
err = register_netdevice(sl->dev);
if (err)
goto err_free_chan;
}
rtnl_unlock();
tty->receive_room = 65536;
return 0;
err_free_chan:
sl->tty = NULL;
tty->disc_data = NULL;
clear_bit(SLF_INUSE, &sl->flags);
err_exit:
rtnl_unlock();
return err;
}
static void slcan_close(struct tty_struct *tty)
{
struct slcan *sl = (struct slcan *) tty->disc_data;
if (!sl || sl->magic != SLCAN_MAGIC || sl->tty != tty)
return;
spin_lock_bh(&sl->lock);
tty->disc_data = NULL;
sl->tty = NULL;
spin_unlock_bh(&sl->lock);
flush_work(&sl->tx_work);
unregister_netdev(sl->dev);
}
static int slcan_hangup(struct tty_struct *tty)
{
slcan_close(tty);
return 0;
}
static int slcan_ioctl(struct tty_struct *tty, struct file *file,
unsigned int cmd, unsigned long arg)
{
struct slcan *sl = (struct slcan *) tty->disc_data;
unsigned int tmp;
if (!sl || sl->magic != SLCAN_MAGIC)
return -EINVAL;
switch (cmd) {
case SIOCGIFNAME:
tmp = strlen(sl->dev->name) + 1;
if (copy_to_user((void __user *)arg, sl->dev->name, tmp))
return -EFAULT;
return 0;
case SIOCSIFHWADDR:
return -EINVAL;
default:
return tty_mode_ioctl(tty, file, cmd, arg);
}
}
static int __init slcan_init(void)
{
int status;
if (maxdev < 4)
maxdev = 4;
pr_info("slcan: serial line CAN interface driver\n");
pr_info("slcan: %d dynamic interface channels.\n", maxdev);
slcan_devs = kzalloc(sizeof(struct net_device *)*maxdev, GFP_KERNEL);
if (!slcan_devs)
return -ENOMEM;
status = tty_register_ldisc(N_SLCAN, &slc_ldisc);
if (status) {
printk(KERN_ERR "slcan: can't register line discipline\n");
kfree(slcan_devs);
}
return status;
}
static void __exit slcan_exit(void)
{
int i;
struct net_device *dev;
struct slcan *sl;
unsigned long timeout = jiffies + HZ;
int busy = 0;
if (slcan_devs == NULL)
return;
do {
if (busy)
msleep_interruptible(100);
busy = 0;
for (i = 0; i < maxdev; i++) {
dev = slcan_devs[i];
if (!dev)
continue;
sl = netdev_priv(dev);
spin_lock_bh(&sl->lock);
if (sl->tty) {
busy++;
tty_hangup(sl->tty);
}
spin_unlock_bh(&sl->lock);
}
} while (busy && time_before(jiffies, timeout));
for (i = 0; i < maxdev; i++) {
dev = slcan_devs[i];
if (!dev)
continue;
slcan_devs[i] = NULL;
sl = netdev_priv(dev);
if (sl->tty) {
printk(KERN_ERR "%s: tty discipline still running\n",
dev->name);
}
unregister_netdev(dev);
}
kfree(slcan_devs);
slcan_devs = NULL;
i = tty_unregister_ldisc(N_SLCAN);
if (i)
printk(KERN_ERR "slcan: can't unregister ldisc (err %d)\n", i);
}
