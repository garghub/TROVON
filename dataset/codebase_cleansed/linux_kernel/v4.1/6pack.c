static void sp_xmit_on_air(unsigned long channel)
{
struct sixpack *sp = (struct sixpack *) channel;
int actual, when = sp->slottime;
static unsigned char random;
random = random * 17 + 41;
if (((sp->status1 & SIXP_DCD_MASK) == 0) && (random < sp->persistence)) {
sp->led_state = 0x70;
sp->tty->ops->write(sp->tty, &sp->led_state, 1);
sp->tx_enable = 1;
actual = sp->tty->ops->write(sp->tty, sp->xbuff, sp->status2);
sp->xleft -= actual;
sp->xhead += actual;
sp->led_state = 0x60;
sp->tty->ops->write(sp->tty, &sp->led_state, 1);
sp->status2 = 0;
} else
mod_timer(&sp->tx_t, jiffies + ((when + 1) * HZ) / 100);
}
static void sp_encaps(struct sixpack *sp, unsigned char *icp, int len)
{
unsigned char *msg, *p = icp;
int actual, count;
if (len > sp->mtu) {
msg = "oversized transmit packet!";
goto out_drop;
}
if (len > sp->mtu) {
msg = "oversized transmit packet!";
goto out_drop;
}
if (p[0] > 5) {
msg = "invalid KISS command";
goto out_drop;
}
if ((p[0] != 0) && (len > 2)) {
msg = "KISS control packet too long";
goto out_drop;
}
if ((p[0] == 0) && (len < 15)) {
msg = "bad AX.25 packet to transmit";
goto out_drop;
}
count = encode_sixpack(p, sp->xbuff, len, sp->tx_delay);
set_bit(TTY_DO_WRITE_WAKEUP, &sp->tty->flags);
switch (p[0]) {
case 1: sp->tx_delay = p[1];
return;
case 2: sp->persistence = p[1];
return;
case 3: sp->slottime = p[1];
return;
case 4:
return;
case 5: sp->duplex = p[1];
return;
}
if (p[0] != 0)
return;
if (sp->duplex == 1) {
sp->led_state = 0x70;
sp->tty->ops->write(sp->tty, &sp->led_state, 1);
sp->tx_enable = 1;
actual = sp->tty->ops->write(sp->tty, sp->xbuff, count);
sp->xleft = count - actual;
sp->xhead = sp->xbuff + actual;
sp->led_state = 0x60;
sp->tty->ops->write(sp->tty, &sp->led_state, 1);
} else {
sp->xleft = count;
sp->xhead = sp->xbuff;
sp->status2 = count;
sp_xmit_on_air((unsigned long)sp);
}
return;
out_drop:
sp->dev->stats.tx_dropped++;
netif_start_queue(sp->dev);
if (net_ratelimit())
printk(KERN_DEBUG "%s: %s - dropped.\n", sp->dev->name, msg);
}
static netdev_tx_t sp_xmit(struct sk_buff *skb, struct net_device *dev)
{
struct sixpack *sp = netdev_priv(dev);
if (skb->protocol == htons(ETH_P_IP))
return ax25_ip_xmit(skb);
spin_lock_bh(&sp->lock);
netif_stop_queue(dev);
dev->stats.tx_bytes += skb->len;
sp_encaps(sp, skb->data, skb->len);
spin_unlock_bh(&sp->lock);
dev_kfree_skb(skb);
return NETDEV_TX_OK;
}
static int sp_open_dev(struct net_device *dev)
{
struct sixpack *sp = netdev_priv(dev);
if (sp->tty == NULL)
return -ENODEV;
return 0;
}
static int sp_close(struct net_device *dev)
{
struct sixpack *sp = netdev_priv(dev);
spin_lock_bh(&sp->lock);
if (sp->tty) {
clear_bit(TTY_DO_WRITE_WAKEUP, &sp->tty->flags);
}
netif_stop_queue(dev);
spin_unlock_bh(&sp->lock);
return 0;
}
static int sp_set_mac_address(struct net_device *dev, void *addr)
{
struct sockaddr_ax25 *sa = addr;
netif_tx_lock_bh(dev);
netif_addr_lock(dev);
memcpy(dev->dev_addr, &sa->sax25_call, AX25_ADDR_LEN);
netif_addr_unlock(dev);
netif_tx_unlock_bh(dev);
return 0;
}
static void sp_setup(struct net_device *dev)
{
dev->netdev_ops = &sp_netdev_ops;
dev->destructor = free_netdev;
dev->mtu = SIXP_MTU;
dev->hard_header_len = AX25_MAX_HEADER_LEN;
dev->header_ops = &ax25_header_ops;
dev->addr_len = AX25_ADDR_LEN;
dev->type = ARPHRD_AX25;
dev->tx_queue_len = 10;
memcpy(dev->broadcast, &ax25_bcast, AX25_ADDR_LEN);
memcpy(dev->dev_addr, &ax25_defaddr, AX25_ADDR_LEN);
dev->flags = 0;
}
static void sp_bump(struct sixpack *sp, char cmd)
{
struct sk_buff *skb;
int count;
unsigned char *ptr;
count = sp->rcount + 1;
sp->dev->stats.rx_bytes += count;
if ((skb = dev_alloc_skb(count)) == NULL)
goto out_mem;
ptr = skb_put(skb, count);
*ptr++ = cmd;
memcpy(ptr, sp->cooked_buf + 1, count);
skb->protocol = ax25_type_trans(skb, sp->dev);
netif_rx(skb);
sp->dev->stats.rx_packets++;
return;
out_mem:
sp->dev->stats.rx_dropped++;
}
static struct sixpack *sp_get(struct tty_struct *tty)
{
struct sixpack *sp;
read_lock(&disc_data_lock);
sp = tty->disc_data;
if (sp)
atomic_inc(&sp->refcnt);
read_unlock(&disc_data_lock);
return sp;
}
static void sp_put(struct sixpack *sp)
{
if (atomic_dec_and_test(&sp->refcnt))
up(&sp->dead_sem);
}
static void sixpack_write_wakeup(struct tty_struct *tty)
{
struct sixpack *sp = sp_get(tty);
int actual;
if (!sp)
return;
if (sp->xleft <= 0) {
sp->dev->stats.tx_packets++;
clear_bit(TTY_DO_WRITE_WAKEUP, &tty->flags);
sp->tx_enable = 0;
netif_wake_queue(sp->dev);
goto out;
}
if (sp->tx_enable) {
actual = tty->ops->write(tty, sp->xhead, sp->xleft);
sp->xleft -= actual;
sp->xhead += actual;
}
out:
sp_put(sp);
}
static void sixpack_receive_buf(struct tty_struct *tty,
const unsigned char *cp, char *fp, int count)
{
struct sixpack *sp;
unsigned char buf[512];
int count1;
if (!count)
return;
sp = sp_get(tty);
if (!sp)
return;
memcpy(buf, cp, count < sizeof(buf) ? count : sizeof(buf));
count1 = count;
while (count) {
count--;
if (fp && *fp++) {
if (!test_and_set_bit(SIXPF_ERROR, &sp->flags))
sp->dev->stats.rx_errors++;
continue;
}
}
sixpack_decode(sp, buf, count1);
sp_put(sp);
tty_unthrottle(tty);
}
static void __tnc_set_sync_state(struct sixpack *sp, int new_tnc_state)
{
char *msg;
switch (new_tnc_state) {
default:
case TNC_UNSYNC_STARTUP:
msg = "Synchronizing with TNC";
break;
case TNC_UNSYNCED:
msg = "Lost synchronization with TNC\n";
break;
case TNC_IN_SYNC:
msg = "Found TNC";
break;
}
sp->tnc_state = new_tnc_state;
printk(KERN_INFO "%s: %s\n", sp->dev->name, msg);
}
static inline void tnc_set_sync_state(struct sixpack *sp, int new_tnc_state)
{
int old_tnc_state = sp->tnc_state;
if (old_tnc_state != new_tnc_state)
__tnc_set_sync_state(sp, new_tnc_state);
}
static void resync_tnc(unsigned long channel)
{
struct sixpack *sp = (struct sixpack *) channel;
static char resync_cmd = 0xe8;
sp->rx_count = 0;
sp->rx_count_cooked = 0;
sp->status = 1;
sp->status1 = 1;
sp->status2 = 0;
sp->led_state = 0x60;
sp->tty->ops->write(sp->tty, &sp->led_state, 1);
sp->tty->ops->write(sp->tty, &resync_cmd, 1);
del_timer(&sp->resync_t);
sp->resync_t.data = (unsigned long) sp;
sp->resync_t.function = resync_tnc;
sp->resync_t.expires = jiffies + SIXP_RESYNC_TIMEOUT;
add_timer(&sp->resync_t);
}
static inline int tnc_init(struct sixpack *sp)
{
unsigned char inbyte = 0xe8;
tnc_set_sync_state(sp, TNC_UNSYNC_STARTUP);
sp->tty->ops->write(sp->tty, &inbyte, 1);
del_timer(&sp->resync_t);
sp->resync_t.data = (unsigned long) sp;
sp->resync_t.function = resync_tnc;
sp->resync_t.expires = jiffies + SIXP_RESYNC_TIMEOUT;
add_timer(&sp->resync_t);
return 0;
}
static int sixpack_open(struct tty_struct *tty)
{
char *rbuff = NULL, *xbuff = NULL;
struct net_device *dev;
struct sixpack *sp;
unsigned long len;
int err = 0;
if (!capable(CAP_NET_ADMIN))
return -EPERM;
if (tty->ops->write == NULL)
return -EOPNOTSUPP;
dev = alloc_netdev(sizeof(struct sixpack), "sp%d", NET_NAME_UNKNOWN,
sp_setup);
if (!dev) {
err = -ENOMEM;
goto out;
}
sp = netdev_priv(dev);
sp->dev = dev;
spin_lock_init(&sp->lock);
atomic_set(&sp->refcnt, 1);
sema_init(&sp->dead_sem, 0);
len = dev->mtu * 2;
rbuff = kmalloc(len + 4, GFP_KERNEL);
xbuff = kmalloc(len + 4, GFP_KERNEL);
if (rbuff == NULL || xbuff == NULL) {
err = -ENOBUFS;
goto out_free;
}
spin_lock_bh(&sp->lock);
sp->tty = tty;
sp->rbuff = rbuff;
sp->xbuff = xbuff;
sp->mtu = AX25_MTU + 73;
sp->buffsize = len;
sp->rcount = 0;
sp->rx_count = 0;
sp->rx_count_cooked = 0;
sp->xleft = 0;
sp->flags = 0;
sp->duplex = 0;
sp->tx_delay = SIXP_TXDELAY;
sp->persistence = SIXP_PERSIST;
sp->slottime = SIXP_SLOTTIME;
sp->led_state = 0x60;
sp->status = 1;
sp->status1 = 1;
sp->status2 = 0;
sp->tx_enable = 0;
netif_start_queue(dev);
init_timer(&sp->tx_t);
sp->tx_t.function = sp_xmit_on_air;
sp->tx_t.data = (unsigned long) sp;
init_timer(&sp->resync_t);
spin_unlock_bh(&sp->lock);
tty->disc_data = sp;
tty->receive_room = 65536;
err = register_netdev(dev);
if (err)
goto out_free;
tnc_init(sp);
return 0;
out_free:
kfree(xbuff);
kfree(rbuff);
free_netdev(dev);
out:
return err;
}
static void sixpack_close(struct tty_struct *tty)
{
struct sixpack *sp;
write_lock_bh(&disc_data_lock);
sp = tty->disc_data;
tty->disc_data = NULL;
write_unlock_bh(&disc_data_lock);
if (!sp)
return;
if (!atomic_dec_and_test(&sp->refcnt))
down(&sp->dead_sem);
unregister_netdev(sp->dev);
del_timer(&sp->tx_t);
del_timer(&sp->resync_t);
kfree(sp->rbuff);
kfree(sp->xbuff);
}
static int sixpack_ioctl(struct tty_struct *tty, struct file *file,
unsigned int cmd, unsigned long arg)
{
struct sixpack *sp = sp_get(tty);
struct net_device *dev;
unsigned int tmp, err;
if (!sp)
return -ENXIO;
dev = sp->dev;
switch(cmd) {
case SIOCGIFNAME:
err = copy_to_user((void __user *) arg, dev->name,
strlen(dev->name) + 1) ? -EFAULT : 0;
break;
case SIOCGIFENCAP:
err = put_user(0, (int __user *) arg);
break;
case SIOCSIFENCAP:
if (get_user(tmp, (int __user *) arg)) {
err = -EFAULT;
break;
}
sp->mode = tmp;
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
memcpy(dev->dev_addr, &addr, AX25_ADDR_LEN);
netif_tx_unlock_bh(dev);
err = 0;
break;
}
default:
err = tty_mode_ioctl(tty, file, cmd, arg);
}
sp_put(sp);
return err;
}
static long sixpack_compat_ioctl(struct tty_struct * tty, struct file * file,
unsigned int cmd, unsigned long arg)
{
switch (cmd) {
case SIOCGIFNAME:
case SIOCGIFENCAP:
case SIOCSIFENCAP:
case SIOCSIFHWADDR:
return sixpack_ioctl(tty, file, cmd,
(unsigned long)compat_ptr(arg));
}
return -ENOIOCTLCMD;
}
static int __init sixpack_init_driver(void)
{
int status;
printk(msg_banner);
if ((status = tty_register_ldisc(N_6PACK, &sp_ldisc)) != 0)
printk(msg_regfail, status);
return status;
}
static void __exit sixpack_exit_driver(void)
{
int ret;
if ((ret = tty_unregister_ldisc(N_6PACK)))
printk(msg_unregfail, ret);
}
static int encode_sixpack(unsigned char *tx_buf, unsigned char *tx_buf_raw,
int length, unsigned char tx_delay)
{
int count = 0;
unsigned char checksum = 0, buf[400];
int raw_count = 0;
tx_buf_raw[raw_count++] = SIXP_PRIO_CMD_MASK | SIXP_TX_MASK;
tx_buf_raw[raw_count++] = SIXP_SEOF;
buf[0] = tx_delay;
for (count = 1; count < length; count++)
buf[count] = tx_buf[count];
for (count = 0; count < length; count++)
checksum += buf[count];
buf[length] = (unsigned char) 0xff - checksum;
for (count = 0; count <= length; count++) {
if ((count % 3) == 0) {
tx_buf_raw[raw_count++] = (buf[count] & 0x3f);
tx_buf_raw[raw_count] = ((buf[count] >> 2) & 0x30);
} else if ((count % 3) == 1) {
tx_buf_raw[raw_count++] |= (buf[count] & 0x0f);
tx_buf_raw[raw_count] = ((buf[count] >> 2) & 0x3c);
} else {
tx_buf_raw[raw_count++] |= (buf[count] & 0x03);
tx_buf_raw[raw_count++] = (buf[count] >> 2);
}
}
if ((length % 3) != 2)
raw_count++;
tx_buf_raw[raw_count++] = SIXP_SEOF;
return raw_count;
}
static void decode_data(struct sixpack *sp, unsigned char inbyte)
{
unsigned char *buf;
if (sp->rx_count != 3) {
sp->raw_buf[sp->rx_count++] = inbyte;
return;
}
buf = sp->raw_buf;
sp->cooked_buf[sp->rx_count_cooked++] =
buf[0] | ((buf[1] << 2) & 0xc0);
sp->cooked_buf[sp->rx_count_cooked++] =
(buf[1] & 0x0f) | ((buf[2] << 2) & 0xf0);
sp->cooked_buf[sp->rx_count_cooked++] =
(buf[2] & 0x03) | (inbyte << 2);
sp->rx_count = 0;
}
static void decode_prio_command(struct sixpack *sp, unsigned char cmd)
{
unsigned char channel;
int actual;
channel = cmd & SIXP_CHN_MASK;
if ((cmd & SIXP_PRIO_DATA_MASK) != 0) {
if (((sp->status & SIXP_DCD_MASK) == 0) &&
((cmd & SIXP_RX_DCD_MASK) == SIXP_RX_DCD_MASK)) {
if (sp->status != 1)
printk(KERN_DEBUG "6pack: protocol violation\n");
else
sp->status = 0;
cmd &= ~SIXP_RX_DCD_MASK;
}
sp->status = cmd & SIXP_PRIO_DATA_MASK;
} else {
if ((sp->status2 != 0) && (sp->duplex == 1)) {
sp->led_state = 0x70;
sp->tty->ops->write(sp->tty, &sp->led_state, 1);
sp->tx_enable = 1;
actual = sp->tty->ops->write(sp->tty, sp->xbuff, sp->status2);
sp->xleft -= actual;
sp->xhead += actual;
sp->led_state = 0x60;
sp->status2 = 0;
}
}
sp->tty->ops->write(sp->tty, &sp->led_state, 1);
if (sp->tnc_state == TNC_IN_SYNC) {
del_timer(&sp->resync_t);
sp->resync_t.data = (unsigned long) sp;
sp->resync_t.function = resync_tnc;
sp->resync_t.expires = jiffies + SIXP_INIT_RESYNC_TIMEOUT;
add_timer(&sp->resync_t);
}
sp->status1 = cmd & SIXP_PRIO_DATA_MASK;
}
static void decode_std_command(struct sixpack *sp, unsigned char cmd)
{
unsigned char checksum = 0, rest = 0, channel;
short i;
channel = cmd & SIXP_CHN_MASK;
switch (cmd & SIXP_CMD_MASK) {
case SIXP_SEOF:
if ((sp->rx_count == 0) && (sp->rx_count_cooked == 0)) {
if ((sp->status & SIXP_RX_DCD_MASK) ==
SIXP_RX_DCD_MASK) {
sp->led_state = 0x68;
sp->tty->ops->write(sp->tty, &sp->led_state, 1);
}
} else {
sp->led_state = 0x60;
sp->tty->ops->write(sp->tty, &sp->led_state, 1);
rest = sp->rx_count;
if (rest != 0)
for (i = rest; i <= 3; i++)
decode_data(sp, 0);
if (rest == 2)
sp->rx_count_cooked -= 2;
else if (rest == 3)
sp->rx_count_cooked -= 1;
for (i = 0; i < sp->rx_count_cooked; i++)
checksum += sp->cooked_buf[i];
if (checksum != SIXP_CHKSUM) {
printk(KERN_DEBUG "6pack: bad checksum %2.2x\n", checksum);
} else {
sp->rcount = sp->rx_count_cooked-2;
sp_bump(sp, 0);
}
sp->rx_count_cooked = 0;
}
break;
case SIXP_TX_URUN: printk(KERN_DEBUG "6pack: TX underrun\n");
break;
case SIXP_RX_ORUN: printk(KERN_DEBUG "6pack: RX overrun\n");
break;
case SIXP_RX_BUF_OVL:
printk(KERN_DEBUG "6pack: RX buffer overflow\n");
}
}
static void
sixpack_decode(struct sixpack *sp, unsigned char *pre_rbuff, int count)
{
unsigned char inbyte;
int count1;
for (count1 = 0; count1 < count; count1++) {
inbyte = pre_rbuff[count1];
if (inbyte == SIXP_FOUND_TNC) {
tnc_set_sync_state(sp, TNC_IN_SYNC);
del_timer(&sp->resync_t);
}
if ((inbyte & SIXP_PRIO_CMD_MASK) != 0)
decode_prio_command(sp, inbyte);
else if ((inbyte & SIXP_STD_CMD_MASK) != 0)
decode_std_command(sp, inbyte);
else if ((sp->status & SIXP_RX_DCD_MASK) == SIXP_RX_DCD_MASK)
decode_data(sp, inbyte);
}
}
