static unsigned short calc_crc_flex(unsigned char *cp, int size)
{
unsigned short crc = 0xffff;
while (size--)
crc = (crc << 8) ^ crc_flex_table[((crc >> 8) ^ *cp++) & 0xff];
return crc;
}
static int check_crc_flex(unsigned char *cp, int size)
{
unsigned short crc = 0xffff;
if (size < 3)
return -1;
while (size--)
crc = (crc << 8) ^ crc_flex_table[((crc >> 8) ^ *cp++) & 0xff];
if ((crc & 0xffff) != 0x7070)
return -1;
return 0;
}
static int check_crc_16(unsigned char *cp, int size)
{
unsigned short crc = 0x0000;
if (size < 3)
return -1;
crc = crc16(0, cp, size);
if (crc != 0x0000)
return -1;
return 0;
}
static int kiss_esc(unsigned char *s, unsigned char *d, int len)
{
unsigned char *ptr = d;
unsigned char c;
*ptr++ = END;
while (len-- > 0) {
switch (c = *s++) {
case END:
*ptr++ = ESC;
*ptr++ = ESC_END;
break;
case ESC:
*ptr++ = ESC;
*ptr++ = ESC_ESC;
break;
default:
*ptr++ = c;
break;
}
}
*ptr++ = END;
return ptr - d;
}
static int kiss_esc_crc(unsigned char *s, unsigned char *d, unsigned short crc,
int len)
{
unsigned char *ptr = d;
unsigned char c=0;
*ptr++ = END;
while (len > 0) {
if (len > 2)
c = *s++;
else if (len > 1)
c = crc >> 8;
else if (len > 0)
c = crc & 0xff;
len--;
switch (c) {
case END:
*ptr++ = ESC;
*ptr++ = ESC_END;
break;
case ESC:
*ptr++ = ESC;
*ptr++ = ESC_ESC;
break;
default:
*ptr++ = c;
break;
}
}
*ptr++ = END;
return ptr - d;
}
static void ax_bump(struct mkiss *ax)
{
struct sk_buff *skb;
int count;
spin_lock_bh(&ax->buflock);
if (ax->rbuff[0] > 0x0f) {
if (ax->rbuff[0] & 0x80) {
if (check_crc_16(ax->rbuff, ax->rcount) < 0) {
ax->dev->stats.rx_errors++;
spin_unlock_bh(&ax->buflock);
return;
}
if (ax->crcmode != CRC_MODE_SMACK && ax->crcauto) {
printk(KERN_INFO
"mkiss: %s: Switching to crc-smack\n",
ax->dev->name);
ax->crcmode = CRC_MODE_SMACK;
}
ax->rcount -= 2;
*ax->rbuff &= ~0x80;
} else if (ax->rbuff[0] & 0x20) {
if (check_crc_flex(ax->rbuff, ax->rcount) < 0) {
ax->dev->stats.rx_errors++;
spin_unlock_bh(&ax->buflock);
return;
}
if (ax->crcmode != CRC_MODE_FLEX && ax->crcauto) {
printk(KERN_INFO
"mkiss: %s: Switching to crc-flexnet\n",
ax->dev->name);
ax->crcmode = CRC_MODE_FLEX;
}
ax->rcount -= 2;
*ax->rbuff &= ~0x20;
}
}
count = ax->rcount;
if ((skb = dev_alloc_skb(count)) == NULL) {
printk(KERN_ERR "mkiss: %s: memory squeeze, dropping packet.\n",
ax->dev->name);
ax->dev->stats.rx_dropped++;
spin_unlock_bh(&ax->buflock);
return;
}
memcpy(skb_put(skb,count), ax->rbuff, count);
skb->protocol = ax25_type_trans(skb, ax->dev);
netif_rx(skb);
ax->dev->stats.rx_packets++;
ax->dev->stats.rx_bytes += count;
spin_unlock_bh(&ax->buflock);
}
static void kiss_unesc(struct mkiss *ax, unsigned char s)
{
switch (s) {
case END:
if (test_bit(AXF_KEEPTEST, &ax->flags))
clear_bit(AXF_KEEPTEST, &ax->flags);
if (!test_and_clear_bit(AXF_ERROR, &ax->flags) && (ax->rcount > 2))
ax_bump(ax);
clear_bit(AXF_ESCAPE, &ax->flags);
ax->rcount = 0;
return;
case ESC:
set_bit(AXF_ESCAPE, &ax->flags);
return;
case ESC_ESC:
if (test_and_clear_bit(AXF_ESCAPE, &ax->flags))
s = ESC;
break;
case ESC_END:
if (test_and_clear_bit(AXF_ESCAPE, &ax->flags))
s = END;
break;
}
spin_lock_bh(&ax->buflock);
if (!test_bit(AXF_ERROR, &ax->flags)) {
if (ax->rcount < ax->buffsize) {
ax->rbuff[ax->rcount++] = s;
spin_unlock_bh(&ax->buflock);
return;
}
ax->dev->stats.rx_over_errors++;
set_bit(AXF_ERROR, &ax->flags);
}
spin_unlock_bh(&ax->buflock);
}
static int ax_set_mac_address(struct net_device *dev, void *addr)
{
struct sockaddr_ax25 *sa = addr;
netif_tx_lock_bh(dev);
netif_addr_lock(dev);
memcpy(dev->dev_addr, &sa->sax25_call, AX25_ADDR_LEN);
netif_addr_unlock(dev);
netif_tx_unlock_bh(dev);
return 0;
}
static void ax_changedmtu(struct mkiss *ax)
{
struct net_device *dev = ax->dev;
unsigned char *xbuff, *rbuff, *oxbuff, *orbuff;
int len;
len = dev->mtu * 2;
if (len < 576 * 2)
len = 576 * 2;
xbuff = kmalloc(len + 4, GFP_ATOMIC);
rbuff = kmalloc(len + 4, GFP_ATOMIC);
if (xbuff == NULL || rbuff == NULL) {
printk(KERN_ERR "mkiss: %s: unable to grow ax25 buffers, "
"MTU change cancelled.\n",
ax->dev->name);
dev->mtu = ax->mtu;
kfree(xbuff);
kfree(rbuff);
return;
}
spin_lock_bh(&ax->buflock);
oxbuff = ax->xbuff;
ax->xbuff = xbuff;
orbuff = ax->rbuff;
ax->rbuff = rbuff;
if (ax->xleft) {
if (ax->xleft <= len) {
memcpy(ax->xbuff, ax->xhead, ax->xleft);
} else {
ax->xleft = 0;
dev->stats.tx_dropped++;
}
}
ax->xhead = ax->xbuff;
if (ax->rcount) {
if (ax->rcount <= len) {
memcpy(ax->rbuff, orbuff, ax->rcount);
} else {
ax->rcount = 0;
dev->stats.rx_over_errors++;
set_bit(AXF_ERROR, &ax->flags);
}
}
ax->mtu = dev->mtu + 73;
ax->buffsize = len;
spin_unlock_bh(&ax->buflock);
kfree(oxbuff);
kfree(orbuff);
}
static void ax_encaps(struct net_device *dev, unsigned char *icp, int len)
{
struct mkiss *ax = netdev_priv(dev);
unsigned char *p;
int actual, count;
if (ax->mtu != ax->dev->mtu + 73)
ax_changedmtu(ax);
if (len > ax->mtu) {
len = ax->mtu;
printk(KERN_ERR "mkiss: %s: truncating oversized transmit packet!\n", ax->dev->name);
dev->stats.tx_dropped++;
netif_start_queue(dev);
return;
}
p = icp;
spin_lock_bh(&ax->buflock);
if ((*p & 0x0f) != 0) {
switch (*p & 0xff) {
case 0x85:
if (len > 1) {
int cmd = (p[1] & 0xff);
switch(cmd) {
case 3:
ax->crcmode = CRC_MODE_SMACK;
break;
case 2:
ax->crcmode = CRC_MODE_FLEX;
break;
case 1:
ax->crcmode = CRC_MODE_NONE;
break;
case 0:
default:
ax->crcmode = CRC_MODE_SMACK_TEST;
cmd = 0;
}
ax->crcauto = (cmd ? 0 : 1);
printk(KERN_INFO "mkiss: %s: crc mode %s %d\n", ax->dev->name, (len) ? "set to" : "is", cmd);
}
spin_unlock_bh(&ax->buflock);
netif_start_queue(dev);
return;
default:
count = kiss_esc(p, ax->xbuff, len);
}
} else {
unsigned short crc;
switch (ax->crcmode) {
case CRC_MODE_SMACK_TEST:
ax->crcmode = CRC_MODE_FLEX_TEST;
printk(KERN_INFO "mkiss: %s: Trying crc-smack\n", ax->dev->name);
case CRC_MODE_SMACK:
*p |= 0x80;
crc = swab16(crc16(0, p, len));
count = kiss_esc_crc(p, ax->xbuff, crc, len+2);
break;
case CRC_MODE_FLEX_TEST:
ax->crcmode = CRC_MODE_NONE;
printk(KERN_INFO "mkiss: %s: Trying crc-flexnet\n", ax->dev->name);
case CRC_MODE_FLEX:
*p |= 0x20;
crc = calc_crc_flex(p, len);
count = kiss_esc_crc(p, ax->xbuff, crc, len+2);
break;
default:
count = kiss_esc(p, ax->xbuff, len);
}
}
spin_unlock_bh(&ax->buflock);
set_bit(TTY_DO_WRITE_WAKEUP, &ax->tty->flags);
actual = ax->tty->ops->write(ax->tty, ax->xbuff, count);
dev->stats.tx_packets++;
dev->stats.tx_bytes += actual;
netif_trans_update(ax->dev);
ax->xleft = count - actual;
ax->xhead = ax->xbuff + actual;
}
static netdev_tx_t ax_xmit(struct sk_buff *skb, struct net_device *dev)
{
struct mkiss *ax = netdev_priv(dev);
if (skb->protocol == htons(ETH_P_IP))
return ax25_ip_xmit(skb);
if (!netif_running(dev)) {
printk(KERN_ERR "mkiss: %s: xmit call when iface is down\n", dev->name);
return NETDEV_TX_BUSY;
}
if (netif_queue_stopped(dev)) {
if (time_before(jiffies, dev_trans_start(dev) + 20 * HZ)) {
return NETDEV_TX_BUSY;
}
printk(KERN_ERR "mkiss: %s: transmit timed out, %s?\n", dev->name,
(tty_chars_in_buffer(ax->tty) || ax->xleft) ?
"bad line quality" : "driver error");
ax->xleft = 0;
clear_bit(TTY_DO_WRITE_WAKEUP, &ax->tty->flags);
netif_start_queue(dev);
}
netif_stop_queue(dev);
ax_encaps(dev, skb->data, skb->len);
kfree_skb(skb);
return NETDEV_TX_OK;
}
static int ax_open_dev(struct net_device *dev)
{
struct mkiss *ax = netdev_priv(dev);
if (ax->tty == NULL)
return -ENODEV;
return 0;
}
static int ax_open(struct net_device *dev)
{
struct mkiss *ax = netdev_priv(dev);
unsigned long len;
if (ax->tty == NULL)
return -ENODEV;
len = dev->mtu * 2;
if (len < 576 * 2)
len = 576 * 2;
if ((ax->rbuff = kmalloc(len + 4, GFP_KERNEL)) == NULL)
goto norbuff;
if ((ax->xbuff = kmalloc(len + 4, GFP_KERNEL)) == NULL)
goto noxbuff;
ax->mtu = dev->mtu + 73;
ax->buffsize = len;
ax->rcount = 0;
ax->xleft = 0;
ax->flags &= (1 << AXF_INUSE);
spin_lock_init(&ax->buflock);
return 0;
noxbuff:
kfree(ax->rbuff);
norbuff:
return -ENOMEM;
}
static int ax_close(struct net_device *dev)
{
struct mkiss *ax = netdev_priv(dev);
if (ax->tty)
clear_bit(TTY_DO_WRITE_WAKEUP, &ax->tty->flags);
netif_stop_queue(dev);
return 0;
}
static void ax_setup(struct net_device *dev)
{
dev->mtu = AX_MTU;
dev->hard_header_len = 0;
dev->addr_len = 0;
dev->type = ARPHRD_AX25;
dev->tx_queue_len = 10;
dev->header_ops = &ax25_header_ops;
dev->netdev_ops = &ax_netdev_ops;
memcpy(dev->broadcast, &ax25_bcast, AX25_ADDR_LEN);
memcpy(dev->dev_addr, &ax25_defaddr, AX25_ADDR_LEN);
dev->flags = IFF_BROADCAST | IFF_MULTICAST;
}
static struct mkiss *mkiss_get(struct tty_struct *tty)
{
struct mkiss *ax;
read_lock(&disc_data_lock);
ax = tty->disc_data;
if (ax)
atomic_inc(&ax->refcnt);
read_unlock(&disc_data_lock);
return ax;
}
static void mkiss_put(struct mkiss *ax)
{
if (atomic_dec_and_test(&ax->refcnt))
up(&ax->dead_sem);
}
static int mkiss_open(struct tty_struct *tty)
{
struct net_device *dev;
struct mkiss *ax;
int err;
if (!capable(CAP_NET_ADMIN))
return -EPERM;
if (tty->ops->write == NULL)
return -EOPNOTSUPP;
dev = alloc_netdev(sizeof(struct mkiss), "ax%d", NET_NAME_UNKNOWN,
ax_setup);
if (!dev) {
err = -ENOMEM;
goto out;
}
ax = netdev_priv(dev);
ax->dev = dev;
spin_lock_init(&ax->buflock);
atomic_set(&ax->refcnt, 1);
sema_init(&ax->dead_sem, 0);
ax->tty = tty;
tty->disc_data = ax;
tty->receive_room = 65535;
tty_driver_flush_buffer(tty);
dev->type = ARPHRD_AX25;
err = ax_open(ax->dev);
if (err)
goto out_free_netdev;
err = register_netdev(dev);
if (err)
goto out_free_buffers;
switch (crc_force) {
case 3:
ax->crcmode = CRC_MODE_SMACK;
printk(KERN_INFO "mkiss: %s: crc mode smack forced.\n",
ax->dev->name);
break;
case 2:
ax->crcmode = CRC_MODE_FLEX;
printk(KERN_INFO "mkiss: %s: crc mode flexnet forced.\n",
ax->dev->name);
break;
case 1:
ax->crcmode = CRC_MODE_NONE;
printk(KERN_INFO "mkiss: %s: crc mode disabled.\n",
ax->dev->name);
break;
case 0:
default:
crc_force = 0;
printk(KERN_INFO "mkiss: %s: crc mode is auto.\n",
ax->dev->name);
ax->crcmode = CRC_MODE_SMACK_TEST;
}
ax->crcauto = (crc_force ? 0 : 1);
netif_start_queue(dev);
return 0;
out_free_buffers:
kfree(ax->rbuff);
kfree(ax->xbuff);
out_free_netdev:
free_netdev(dev);
out:
return err;
}
static void mkiss_close(struct tty_struct *tty)
{
struct mkiss *ax;
write_lock_bh(&disc_data_lock);
ax = tty->disc_data;
tty->disc_data = NULL;
write_unlock_bh(&disc_data_lock);
if (!ax)
return;
if (!atomic_dec_and_test(&ax->refcnt))
down(&ax->dead_sem);
netif_stop_queue(ax->dev);
kfree(ax->rbuff);
kfree(ax->xbuff);
ax->tty = NULL;
unregister_netdev(ax->dev);
}
static int mkiss_ioctl(struct tty_struct *tty, struct file *file,
unsigned int cmd, unsigned long arg)
{
struct mkiss *ax = mkiss_get(tty);
struct net_device *dev;
unsigned int tmp, err;
if (ax == NULL)
return -ENXIO;
dev = ax->dev;
switch (cmd) {
case SIOCGIFNAME:
err = copy_to_user((void __user *) arg, ax->dev->name,
strlen(ax->dev->name) + 1) ? -EFAULT : 0;
break;
case SIOCGIFENCAP:
err = put_user(4, (int __user *) arg);
break;
case SIOCSIFENCAP:
if (get_user(tmp, (int __user *) arg)) {
err = -EFAULT;
break;
}
ax->mode = tmp;
dev->addr_len = AX25_ADDR_LEN;
dev->hard_header_len = AX25_KISS_HEADER_LEN +
AX25_MAX_HEADER_LEN + 3;
dev->type = ARPHRD_AX25;
err = 0;
break;
case SIOCSIFHWADDR: {
char addr[AX25_ADDR_LEN];
if (copy_from_user(&addr,
(void __user *) arg, AX25_ADDR_LEN)) {
err = -EFAULT;
break;
}
netif_tx_lock_bh(dev);
memcpy(dev->dev_addr, addr, AX25_ADDR_LEN);
netif_tx_unlock_bh(dev);
err = 0;
break;
}
default:
err = -ENOIOCTLCMD;
}
mkiss_put(ax);
return err;
}
static long mkiss_compat_ioctl(struct tty_struct *tty, struct file *file,
unsigned int cmd, unsigned long arg)
{
switch (cmd) {
case SIOCGIFNAME:
case SIOCGIFENCAP:
case SIOCSIFENCAP:
case SIOCSIFHWADDR:
return mkiss_ioctl(tty, file, cmd,
(unsigned long)compat_ptr(arg));
}
return -ENOIOCTLCMD;
}
static void mkiss_receive_buf(struct tty_struct *tty, const unsigned char *cp,
char *fp, int count)
{
struct mkiss *ax = mkiss_get(tty);
if (!ax)
return;
if (ax->mtu != ax->dev->mtu + 73)
ax_changedmtu(ax);
while (count--) {
if (fp != NULL && *fp++) {
if (!test_and_set_bit(AXF_ERROR, &ax->flags))
ax->dev->stats.rx_errors++;
cp++;
continue;
}
kiss_unesc(ax, *cp++);
}
mkiss_put(ax);
tty_unthrottle(tty);
}
static void mkiss_write_wakeup(struct tty_struct *tty)
{
struct mkiss *ax = mkiss_get(tty);
int actual;
if (!ax)
return;
if (ax->xleft <= 0) {
clear_bit(TTY_DO_WRITE_WAKEUP, &tty->flags);
netif_wake_queue(ax->dev);
goto out;
}
actual = tty->ops->write(tty, ax->xhead, ax->xleft);
ax->xleft -= actual;
ax->xhead += actual;
out:
mkiss_put(ax);
}
static int __init mkiss_init_driver(void)
{
int status;
printk(banner);
status = tty_register_ldisc(N_AX25, &ax_ldisc);
if (status != 0)
printk(msg_regfail, status);
return status;
}
static void __exit mkiss_exit_driver(void)
{
int ret;
if ((ret = tty_unregister_ldisc(N_AX25)))
printk(msg_unregfail, ret);
}
