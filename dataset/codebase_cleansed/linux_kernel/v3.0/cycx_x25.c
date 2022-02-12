int cycx_x25_wan_init(struct cycx_device *card, wandev_conf_t *conf)
{
struct cycx_x25_config cfg;
if (conf->config_id != WANCONFIG_X25) {
printk(KERN_INFO "%s: invalid configuration ID %u!\n",
card->devname, conf->config_id);
return -EINVAL;
}
card->mbox = card->hw.dpmbase + X25_MBOX_OFFS;
card->u.x.connection_keys = 0;
spin_lock_init(&card->u.x.lock);
memset(&cfg, 0, sizeof(cfg));
cfg.link = 0;
cfg.clock = conf->clocking == WANOPT_EXTERNAL ? 8 : 55;
cfg.speed = bps_to_speed_code(conf->bps);
cfg.n3win = 7;
cfg.n2win = 2;
cfg.n2 = 5;
cfg.nvc = 1;
cfg.npvc = 1;
cfg.flags = 0x02;
cfg.t1 = 10;
cfg.t2 = 29;
cfg.t21 = 180;
cfg.t23 = 180;
if (!conf->mtu || conf->mtu >= 512)
card->wandev.mtu = 512;
else if (conf->mtu >= 256)
card->wandev.mtu = 256;
else if (conf->mtu >= 128)
card->wandev.mtu = 128;
else
card->wandev.mtu = 64;
cfg.pktlen = cycx_log2(card->wandev.mtu);
if (conf->station == WANOPT_DTE) {
cfg.locaddr = 3;
cfg.remaddr = 1;
} else {
cfg.locaddr = 1;
cfg.remaddr = 3;
}
if (conf->interface == WANOPT_RS232)
cfg.flags = 0;
if (conf->u.x25.hi_pvc) {
card->u.x.hi_pvc = min_t(unsigned int, conf->u.x25.hi_pvc, 4095);
card->u.x.lo_pvc = min_t(unsigned int, conf->u.x25.lo_pvc, card->u.x.hi_pvc);
}
if (conf->u.x25.hi_svc) {
card->u.x.hi_svc = min_t(unsigned int, conf->u.x25.hi_svc, 4095);
card->u.x.lo_svc = min_t(unsigned int, conf->u.x25.lo_svc, card->u.x.hi_svc);
}
if (card->u.x.lo_pvc == 255)
cfg.npvc = 0;
else
cfg.npvc = card->u.x.hi_pvc - card->u.x.lo_pvc + 1;
cfg.nvc = card->u.x.hi_svc - card->u.x.lo_svc + 1 + cfg.npvc;
if (conf->u.x25.hdlc_window)
cfg.n2win = min_t(unsigned int, conf->u.x25.hdlc_window, 7);
if (conf->u.x25.pkt_window)
cfg.n3win = min_t(unsigned int, conf->u.x25.pkt_window, 7);
if (conf->u.x25.t1)
cfg.t1 = min_t(unsigned int, conf->u.x25.t1, 30);
if (conf->u.x25.t2)
cfg.t2 = min_t(unsigned int, conf->u.x25.t2, 30);
if (conf->u.x25.t11_t21)
cfg.t21 = min_t(unsigned int, conf->u.x25.t11_t21, 30);
if (conf->u.x25.t13_t23)
cfg.t23 = min_t(unsigned int, conf->u.x25.t13_t23, 30);
if (conf->u.x25.n2)
cfg.n2 = min_t(unsigned int, conf->u.x25.n2, 30);
if (cycx_x25_configure(card, &cfg))
return -EIO;
card->wandev.bps = conf->bps;
card->wandev.interface = conf->interface;
card->wandev.clocking = conf->clocking;
card->wandev.station = conf->station;
card->isr = cycx_x25_irq_handler;
card->exec = NULL;
card->wandev.update = cycx_wan_update;
card->wandev.new_if = cycx_wan_new_if;
card->wandev.del_if = cycx_wan_del_if;
card->wandev.state = WAN_DISCONNECTED;
return 0;
}
static int cycx_wan_update(struct wan_device *wandev)
{
if (!wandev || !wandev->private)
return -EFAULT;
if (wandev->state == WAN_UNCONFIGURED)
return -ENODEV;
cycx_x25_get_stats(wandev->private);
return 0;
}
static int cycx_wan_new_if(struct wan_device *wandev, struct net_device *dev,
wanif_conf_t *conf)
{
struct cycx_device *card = wandev->private;
struct cycx_x25_channel *chan;
int err = 0;
if (!conf->name[0] || strlen(conf->name) > WAN_IFNAME_SZ) {
printk(KERN_INFO "%s: invalid interface name!\n",
card->devname);
return -EINVAL;
}
dev = alloc_netdev(sizeof(struct cycx_x25_channel), conf->name,
cycx_x25_chan_setup);
if (!dev)
return -ENOMEM;
chan = netdev_priv(dev);
strcpy(chan->name, conf->name);
chan->card = card;
chan->link = conf->port;
chan->protocol = conf->protocol ? ETH_P_X25 : ETH_P_IP;
chan->rx_skb = NULL;
chan->local_addr = NULL;
if (conf->addr[0] == '@') {
int len = strlen(conf->local_addr);
if (len) {
if (len > WAN_ADDRESS_SZ) {
printk(KERN_ERR "%s: %s local addr too long!\n",
wandev->name, chan->name);
err = -EINVAL;
goto error;
} else {
chan->local_addr = kmalloc(len + 1, GFP_KERNEL);
if (!chan->local_addr) {
err = -ENOMEM;
goto error;
}
}
strncpy(chan->local_addr, conf->local_addr,
WAN_ADDRESS_SZ);
}
chan->svc = 1;
strncpy(chan->addr, &conf->addr[1], WAN_ADDRESS_SZ);
init_timer(&chan->timer);
chan->timer.function = cycx_x25_chan_timer;
chan->timer.data = (unsigned long)dev;
chan->idle_tmout = conf->idle_timeout ? conf->idle_timeout : 90;
} else if (isdigit(conf->addr[0])) {
s16 lcn = dec_to_uint(conf->addr, 0);
if (lcn >= card->u.x.lo_pvc && lcn <= card->u.x.hi_pvc)
chan->lcn = lcn;
else {
printk(KERN_ERR
"%s: PVC %u is out of range on interface %s!\n",
wandev->name, lcn, chan->name);
err = -EINVAL;
goto error;
}
} else {
printk(KERN_ERR "%s: invalid media address on interface %s!\n",
wandev->name, chan->name);
err = -EINVAL;
goto error;
}
return 0;
error:
free_netdev(dev);
return err;
}
static int cycx_wan_del_if(struct wan_device *wandev, struct net_device *dev)
{
struct cycx_x25_channel *chan = netdev_priv(dev);
if (chan->svc) {
kfree(chan->local_addr);
if (chan->state == WAN_CONNECTED)
del_timer(&chan->timer);
}
return 0;
}
static void cycx_x25_chan_setup(struct net_device *dev)
{
dev->netdev_ops = &cycx_netdev_ops;
dev->header_ops = &cycx_header_ops;
dev->mtu = CYCX_X25_CHAN_MTU;
dev->type = ARPHRD_HWX25;
dev->hard_header_len = 0;
dev->addr_len = 0;
}
static int cycx_netdevice_init(struct net_device *dev)
{
struct cycx_x25_channel *chan = netdev_priv(dev);
struct cycx_device *card = chan->card;
struct wan_device *wandev = &card->wandev;
if (!chan->svc)
*(__be16*)dev->dev_addr = htons(chan->lcn);
dev->irq = wandev->irq;
dev->dma = wandev->dma;
dev->base_addr = wandev->ioport;
dev->mem_start = (unsigned long)wandev->maddr;
dev->mem_end = (unsigned long)(wandev->maddr +
wandev->msize - 1);
dev->flags |= IFF_NOARP;
dev->tx_queue_len = 10;
cycx_x25_set_chan_state(dev, WAN_DISCONNECTED);
return 0;
}
static int cycx_netdevice_open(struct net_device *dev)
{
if (netif_running(dev))
return -EBUSY;
netif_start_queue(dev);
return 0;
}
static int cycx_netdevice_stop(struct net_device *dev)
{
struct cycx_x25_channel *chan = netdev_priv(dev);
netif_stop_queue(dev);
if (chan->state == WAN_CONNECTED || chan->state == WAN_CONNECTING)
cycx_x25_chan_disconnect(dev);
return 0;
}
static int cycx_netdevice_hard_header(struct sk_buff *skb,
struct net_device *dev, u16 type,
const void *daddr, const void *saddr,
unsigned len)
{
skb->protocol = htons(type);
return dev->hard_header_len;
}
static int cycx_netdevice_rebuild_header(struct sk_buff *skb)
{
return 1;
}
static netdev_tx_t cycx_netdevice_hard_start_xmit(struct sk_buff *skb,
struct net_device *dev)
{
struct cycx_x25_channel *chan = netdev_priv(dev);
struct cycx_device *card = chan->card;
if (!chan->svc)
chan->protocol = ntohs(skb->protocol);
if (card->wandev.state != WAN_CONNECTED)
++chan->ifstats.tx_dropped;
else if (chan->svc && chan->protocol &&
chan->protocol != ntohs(skb->protocol)) {
printk(KERN_INFO
"%s: unsupported Ethertype 0x%04X on interface %s!\n",
card->devname, ntohs(skb->protocol), dev->name);
++chan->ifstats.tx_errors;
} else if (chan->protocol == ETH_P_IP) {
switch (chan->state) {
case WAN_DISCONNECTED:
if (cycx_x25_chan_connect(dev)) {
netif_stop_queue(dev);
return NETDEV_TX_BUSY;
}
case WAN_CONNECTED:
reset_timer(dev);
dev->trans_start = jiffies;
netif_stop_queue(dev);
if (cycx_x25_chan_send(dev, skb))
return NETDEV_TX_BUSY;
break;
default:
++chan->ifstats.tx_dropped;
++card->wandev.stats.tx_dropped;
}
} else {
switch (skb->data[0]) {
case X25_IFACE_DATA:
break;
case X25_IFACE_CONNECT:
cycx_x25_chan_connect(dev);
goto free_packet;
case X25_IFACE_DISCONNECT:
cycx_x25_chan_disconnect(dev);
goto free_packet;
default:
printk(KERN_INFO
"%s: unknown %d x25-iface request on %s!\n",
card->devname, skb->data[0], dev->name);
++chan->ifstats.tx_errors;
goto free_packet;
}
skb_pull(skb, 1);
reset_timer(dev);
dev->trans_start = jiffies;
netif_stop_queue(dev);
if (cycx_x25_chan_send(dev, skb)) {
skb_push(skb, 1);
return NETDEV_TX_BUSY;
}
}
free_packet:
dev_kfree_skb(skb);
return NETDEV_TX_OK;
}
static struct net_device_stats *cycx_netdevice_get_stats(struct net_device *dev)
{
struct cycx_x25_channel *chan = netdev_priv(dev);
return chan ? &chan->ifstats : NULL;
}
static void cycx_x25_irq_handler(struct cycx_device *card)
{
struct cycx_x25_cmd cmd;
u16 z = 0;
card->in_isr = 1;
card->buff_int_mode_unbusy = 0;
cycx_peek(&card->hw, X25_RXMBOX_OFFS, &cmd, sizeof(cmd));
switch (cmd.command) {
case X25_DATA_INDICATION:
cycx_x25_irq_rx(card, &cmd);
break;
case X25_ACK_FROM_VC:
cycx_x25_irq_tx(card, &cmd);
break;
case X25_LOG:
cycx_x25_irq_log(card, &cmd);
break;
case X25_STATISTIC:
cycx_x25_irq_stat(card, &cmd);
break;
case X25_CONNECT_CONFIRM:
cycx_x25_irq_connect_confirm(card, &cmd);
break;
case X25_CONNECT_INDICATION:
cycx_x25_irq_connect(card, &cmd);
break;
case X25_DISCONNECT_INDICATION:
cycx_x25_irq_disconnect(card, &cmd);
break;
case X25_DISCONNECT_CONFIRM:
cycx_x25_irq_disconnect_confirm(card, &cmd);
break;
case X25_LINE_ON:
cycx_set_state(card, WAN_CONNECTED);
break;
case X25_LINE_OFF:
cycx_set_state(card, WAN_DISCONNECTED);
break;
default:
cycx_x25_irq_spurious(card, &cmd);
break;
}
cycx_poke(&card->hw, 0, &z, sizeof(z));
cycx_poke(&card->hw, X25_RXMBOX_OFFS, &z, sizeof(z));
card->in_isr = 0;
}
static void cycx_x25_irq_tx(struct cycx_device *card, struct cycx_x25_cmd *cmd)
{
struct net_device *dev;
struct wan_device *wandev = &card->wandev;
u8 lcn;
cycx_peek(&card->hw, cmd->buf, &lcn, sizeof(lcn));
dev = cycx_x25_get_dev_by_lcn(wandev, lcn);
if (dev) {
card->buff_int_mode_unbusy = 1;
netif_wake_queue(dev);
} else
printk(KERN_ERR "%s:ackvc for inexistent lcn %d\n",
card->devname, lcn);
}
static void cycx_x25_irq_rx(struct cycx_device *card, struct cycx_x25_cmd *cmd)
{
struct wan_device *wandev = &card->wandev;
struct net_device *dev;
struct cycx_x25_channel *chan;
struct sk_buff *skb;
u8 bitm, lcn;
int pktlen = cmd->len - 5;
cycx_peek(&card->hw, cmd->buf, &lcn, sizeof(lcn));
cycx_peek(&card->hw, cmd->buf + 4, &bitm, sizeof(bitm));
bitm &= 0x10;
dev = cycx_x25_get_dev_by_lcn(wandev, lcn);
if (!dev) {
printk(KERN_INFO "%s: receiving on orphaned LCN %d!\n",
card->devname, lcn);
return;
}
chan = netdev_priv(dev);
reset_timer(dev);
if (chan->drop_sequence) {
if (!bitm)
chan->drop_sequence = 0;
else
return;
}
if ((skb = chan->rx_skb) == NULL) {
int bufsize = bitm ? dev->mtu : pktlen;
if ((skb = dev_alloc_skb((chan->protocol == ETH_P_X25 ? 1 : 0) +
bufsize +
dev->hard_header_len)) == NULL) {
printk(KERN_INFO "%s: no socket buffers available!\n",
card->devname);
chan->drop_sequence = 1;
++chan->ifstats.rx_dropped;
return;
}
if (chan->protocol == ETH_P_X25)
skb_put(skb, 1);
skb->dev = dev;
skb->protocol = htons(chan->protocol);
chan->rx_skb = skb;
}
if (skb_tailroom(skb) < pktlen) {
dev_kfree_skb_irq(skb);
chan->rx_skb = NULL;
if (bitm)
chan->drop_sequence = 1;
printk(KERN_INFO "%s: unexpectedly long packet sequence "
"on interface %s!\n", card->devname, dev->name);
++chan->ifstats.rx_length_errors;
return;
}
cycx_peek(&card->hw, cmd->buf + 5, skb_put(skb, pktlen), pktlen);
if (bitm)
return;
chan->rx_skb = NULL;
++chan->ifstats.rx_packets;
chan->ifstats.rx_bytes += pktlen;
skb_reset_mac_header(skb);
netif_rx(skb);
}
static void cycx_x25_irq_connect(struct cycx_device *card,
struct cycx_x25_cmd *cmd)
{
struct wan_device *wandev = &card->wandev;
struct net_device *dev = NULL;
struct cycx_x25_channel *chan;
u8 d[32],
loc[24],
rem[24];
u8 lcn, sizeloc, sizerem;
cycx_peek(&card->hw, cmd->buf, &lcn, sizeof(lcn));
cycx_peek(&card->hw, cmd->buf + 5, &sizeloc, sizeof(sizeloc));
cycx_peek(&card->hw, cmd->buf + 6, d, cmd->len - 6);
sizerem = sizeloc >> 4;
sizeloc &= 0x0F;
loc[0] = rem[0] = '\0';
if (sizeloc)
nibble_to_byte(d, loc, sizeloc, 0);
if (sizerem)
nibble_to_byte(d + (sizeloc >> 1), rem, sizerem, sizeloc & 1);
dprintk(1, KERN_INFO "%s:lcn=%d, local=%s, remote=%s\n",
__func__, lcn, loc, rem);
dev = cycx_x25_get_dev_by_dte_addr(wandev, rem);
if (!dev) {
printk(KERN_INFO "%s: connect not expected: remote %s!\n",
card->devname, rem);
return;
}
chan = netdev_priv(dev);
chan->lcn = lcn;
cycx_x25_connect_response(card, chan);
cycx_x25_set_chan_state(dev, WAN_CONNECTED);
}
static void cycx_x25_irq_connect_confirm(struct cycx_device *card,
struct cycx_x25_cmd *cmd)
{
struct wan_device *wandev = &card->wandev;
struct net_device *dev;
struct cycx_x25_channel *chan;
u8 lcn, key;
cycx_peek(&card->hw, cmd->buf, &lcn, sizeof(lcn));
cycx_peek(&card->hw, cmd->buf + 1, &key, sizeof(key));
dprintk(1, KERN_INFO "%s: %s:lcn=%d, key=%d\n",
card->devname, __func__, lcn, key);
dev = cycx_x25_get_dev_by_lcn(wandev, -key);
if (!dev) {
clear_bit(--key, (void*)&card->u.x.connection_keys);
printk(KERN_INFO "%s: connect confirm not expected: lcn %d, "
"key=%d!\n", card->devname, lcn, key);
return;
}
clear_bit(--key, (void*)&card->u.x.connection_keys);
chan = netdev_priv(dev);
chan->lcn = lcn;
cycx_x25_set_chan_state(dev, WAN_CONNECTED);
}
static void cycx_x25_irq_disconnect_confirm(struct cycx_device *card,
struct cycx_x25_cmd *cmd)
{
struct wan_device *wandev = &card->wandev;
struct net_device *dev;
u8 lcn;
cycx_peek(&card->hw, cmd->buf, &lcn, sizeof(lcn));
dprintk(1, KERN_INFO "%s: %s:lcn=%d\n",
card->devname, __func__, lcn);
dev = cycx_x25_get_dev_by_lcn(wandev, lcn);
if (!dev) {
printk(KERN_INFO "%s:disconnect confirm not expected!:lcn %d\n",
card->devname, lcn);
return;
}
cycx_x25_set_chan_state(dev, WAN_DISCONNECTED);
}
static void cycx_x25_irq_disconnect(struct cycx_device *card,
struct cycx_x25_cmd *cmd)
{
struct wan_device *wandev = &card->wandev;
struct net_device *dev;
u8 lcn;
cycx_peek(&card->hw, cmd->buf, &lcn, sizeof(lcn));
dprintk(1, KERN_INFO "%s:lcn=%d\n", __func__, lcn);
dev = cycx_x25_get_dev_by_lcn(wandev, lcn);
if (dev) {
struct cycx_x25_channel *chan = netdev_priv(dev);
cycx_x25_disconnect_response(card, chan->link, lcn);
cycx_x25_set_chan_state(dev, WAN_DISCONNECTED);
} else
cycx_x25_disconnect_response(card, 0, lcn);
}
static void cycx_x25_irq_log(struct cycx_device *card, struct cycx_x25_cmd *cmd)
{
#if CYCLOMX_X25_DEBUG
char bf[20];
u16 size, toread, link, msg_code;
u8 code, routine;
cycx_peek(&card->hw, cmd->buf, &msg_code, sizeof(msg_code));
cycx_peek(&card->hw, cmd->buf + 2, &link, sizeof(link));
cycx_peek(&card->hw, cmd->buf + 4, &size, sizeof(size));
toread = size < 20 ? size : 20;
cycx_peek(&card->hw, cmd->buf + 10, &bf, toread);
cycx_peek(&card->hw, cmd->buf + 10 + toread, &code, 1);
cycx_peek(&card->hw, cmd->buf + 10 + toread + 1, &routine, 1);
printk(KERN_INFO "cycx_x25_irq_handler: X25_LOG (0x4500) indic.:\n");
printk(KERN_INFO "cmd->buf=0x%X\n", cmd->buf);
printk(KERN_INFO "Log message code=0x%X\n", msg_code);
printk(KERN_INFO "Link=%d\n", link);
printk(KERN_INFO "log code=0x%X\n", code);
printk(KERN_INFO "log routine=0x%X\n", routine);
printk(KERN_INFO "Message size=%d\n", size);
hex_dump("Message", bf, toread);
#endif
}
static void cycx_x25_irq_stat(struct cycx_device *card,
struct cycx_x25_cmd *cmd)
{
cycx_peek(&card->hw, cmd->buf, &card->u.x.stats,
sizeof(card->u.x.stats));
hex_dump("cycx_x25_irq_stat", (unsigned char*)&card->u.x.stats,
sizeof(card->u.x.stats));
cycx_x25_dump_stats(&card->u.x.stats);
wake_up_interruptible(&card->wait_stats);
}
static void cycx_x25_irq_spurious(struct cycx_device *card,
struct cycx_x25_cmd *cmd)
{
printk(KERN_INFO "%s: spurious interrupt (0x%X)!\n",
card->devname, cmd->command);
}
static void hex_dump(char *msg, unsigned char *p, int len)
{
unsigned char hex[1024],
* phex = hex;
if (len >= (sizeof(hex) / 2))
len = (sizeof(hex) / 2) - 1;
while (len--) {
sprintf(phex, "%02x", *p++);
phex += 2;
}
printk(KERN_INFO "%s: %s\n", msg, hex);
}
static int x25_exec(struct cycx_device *card, int command, int link,
void *d1, int len1, void *d2, int len2)
{
struct cycx_x25_cmd c;
unsigned long flags;
u32 addr = 0x1200 + 0x2E0 * link + 0x1E2;
u8 retry = CYCX_X25_MAX_CMD_RETRY;
int err = 0;
c.command = command;
c.link = link;
c.len = len1 + len2;
spin_lock_irqsave(&card->u.x.lock, flags);
cycx_poke(&card->hw, X25_MBOX_OFFS, &c, sizeof(c) - sizeof(c.buf));
if (d1) {
cycx_poke(&card->hw, addr, d1, len1);
if (d2) {
if (len2 > 254) {
u32 addr1 = 0xA00 + 0x400 * link;
cycx_poke(&card->hw, addr + len1, d2, 249);
cycx_poke(&card->hw, addr1, ((u8*)d2) + 249,
len2 - 249);
} else
cycx_poke(&card->hw, addr + len1, d2, len2);
}
}
cycx_intr(&card->hw);
do {
err = cycx_exec(card->mbox);
} while (retry-- && err);
spin_unlock_irqrestore(&card->u.x.lock, flags);
return err;
}
static int cycx_x25_configure(struct cycx_device *card,
struct cycx_x25_config *conf)
{
struct {
u16 nlinks;
struct cycx_x25_config conf[2];
} x25_cmd_conf;
memset(&x25_cmd_conf, 0, sizeof(x25_cmd_conf));
x25_cmd_conf.nlinks = 2;
x25_cmd_conf.conf[0] = *conf;
x25_cmd_conf.conf[1] = *conf;
x25_cmd_conf.conf[1].link = 1;
x25_cmd_conf.conf[1].speed = 5;
x25_cmd_conf.conf[1].clock = 8;
x25_cmd_conf.conf[1].flags = 0;
cycx_x25_dump_config(&x25_cmd_conf.conf[0]);
cycx_x25_dump_config(&x25_cmd_conf.conf[1]);
return x25_exec(card, X25_CONFIG, 0,
&x25_cmd_conf, sizeof(x25_cmd_conf), NULL, 0);
}
static int cycx_x25_get_stats(struct cycx_device *card)
{
int err = x25_exec(card, X25_STATISTIC, 0, NULL, 20, NULL, 0);
if (err)
return err;
interruptible_sleep_on(&card->wait_stats);
if (signal_pending(current))
return -EINTR;
card->wandev.stats.rx_packets = card->u.x.stats.n2_rx_frames;
card->wandev.stats.rx_over_errors = card->u.x.stats.rx_over_errors;
card->wandev.stats.rx_crc_errors = card->u.x.stats.rx_crc_errors;
card->wandev.stats.rx_length_errors = 0;
card->wandev.stats.rx_frame_errors = 0;
card->wandev.stats.rx_missed_errors = card->u.x.stats.rx_aborts;
card->wandev.stats.rx_dropped = 0;
card->wandev.stats.rx_errors = 0;
card->wandev.stats.tx_packets = card->u.x.stats.n2_tx_frames;
card->wandev.stats.tx_aborted_errors = card->u.x.stats.tx_aborts;
card->wandev.stats.tx_dropped = 0;
card->wandev.stats.collisions = 0;
card->wandev.stats.tx_errors = 0;
cycx_x25_dump_devs(&card->wandev);
return 0;
}
static int byte_to_nibble(u8 *s, u8 *d, char *nibble)
{
int i = 0;
if (*nibble && *s) {
d[i] |= *s++ - '0';
*nibble = 0;
++i;
}
while (*s) {
d[i] = (*s - '0') << 4;
if (*(s + 1))
d[i] |= *(s + 1) - '0';
else {
*nibble = 1;
break;
}
++i;
s += 2;
}
return i;
}
static void nibble_to_byte(u8 *s, u8 *d, u8 len, u8 nibble)
{
if (nibble) {
*d++ = '0' + (*s++ & 0x0F);
--len;
}
while (len) {
*d++ = '0' + (*s >> 4);
if (--len) {
*d++ = '0' + (*s & 0x0F);
--len;
} else break;
++s;
}
*d = '\0';
}
static int x25_place_call(struct cycx_device *card,
struct cycx_x25_channel *chan)
{
int err = 0,
len;
char d[64],
nibble = 0,
mylen = chan->local_addr ? strlen(chan->local_addr) : 0,
remotelen = strlen(chan->addr);
u8 key;
if (card->u.x.connection_keys == ~0U) {
printk(KERN_INFO "%s: too many simultaneous connection "
"requests!\n", card->devname);
return -EAGAIN;
}
key = ffz(card->u.x.connection_keys);
set_bit(key, (void*)&card->u.x.connection_keys);
++key;
dprintk(1, KERN_INFO "%s:x25_place_call:key=%d\n", card->devname, key);
memset(d, 0, sizeof(d));
d[1] = key;
d[2] = 0x10;
d[4] = 0x0B;
len = byte_to_nibble(chan->addr, d + 6, &nibble);
if (chan->local_addr)
len += byte_to_nibble(chan->local_addr, d + 6 + len, &nibble);
if (nibble)
++len;
d[5] = mylen << 4 | remotelen;
d[6 + len + 1] = 0xCC;
if ((err = x25_exec(card, X25_CONNECT_REQUEST, chan->link,
&d, 7 + len + 1, NULL, 0)) != 0)
clear_bit(--key, (void*)&card->u.x.connection_keys);
else
chan->lcn = -key;
return err;
}
static int cycx_x25_connect_response(struct cycx_device *card,
struct cycx_x25_channel *chan)
{
u8 d[8];
memset(d, 0, sizeof(d));
d[0] = d[3] = chan->lcn;
d[2] = 0x10;
d[4] = 0x0F;
d[7] = 0xCC;
return x25_exec(card, X25_CONNECT_RESPONSE, chan->link, &d, 8, NULL, 0);
}
static int cycx_x25_disconnect_response(struct cycx_device *card, u8 link,
u8 lcn)
{
char d[5];
memset(d, 0, sizeof(d));
d[0] = d[3] = lcn;
d[2] = 0x10;
d[4] = 0x17;
return x25_exec(card, X25_DISCONNECT_RESPONSE, link, &d, 5, NULL, 0);
}
static int x25_clear_call(struct cycx_device *card, u8 link, u8 lcn, u8 cause,
u8 diagn)
{
u8 d[7];
memset(d, 0, sizeof(d));
d[0] = d[3] = lcn;
d[2] = 0x10;
d[4] = 0x13;
d[5] = cause;
d[6] = diagn;
return x25_exec(card, X25_DISCONNECT_REQUEST, link, d, 7, NULL, 0);
}
static int cycx_x25_send(struct cycx_device *card, u8 link, u8 lcn, u8 bitm,
int len, void *buf)
{
u8 d[] = "?\xFF\x10??";
d[0] = d[3] = lcn;
d[4] = bitm;
return x25_exec(card, X25_DATA_REQUEST, link, &d, 5, buf, len);
}
static struct net_device *cycx_x25_get_dev_by_lcn(struct wan_device *wandev,
s16 lcn)
{
struct net_device *dev = wandev->dev;
struct cycx_x25_channel *chan;
while (dev) {
chan = netdev_priv(dev);
if (chan->lcn == lcn)
break;
dev = chan->slave;
}
return dev;
}
static struct net_device *
cycx_x25_get_dev_by_dte_addr(struct wan_device *wandev, char *dte)
{
struct net_device *dev = wandev->dev;
struct cycx_x25_channel *chan;
while (dev) {
chan = netdev_priv(dev);
if (!strcmp(chan->addr, dte))
break;
dev = chan->slave;
}
return dev;
}
static int cycx_x25_chan_connect(struct net_device *dev)
{
struct cycx_x25_channel *chan = netdev_priv(dev);
struct cycx_device *card = chan->card;
if (chan->svc) {
if (!chan->addr[0])
return -EINVAL;
dprintk(1, KERN_INFO "%s: placing X.25 call to %s...\n",
card->devname, chan->addr);
if (x25_place_call(card, chan))
return -EIO;
cycx_x25_set_chan_state(dev, WAN_CONNECTING);
return 1;
} else
cycx_x25_set_chan_state(dev, WAN_CONNECTED);
return 0;
}
static void cycx_x25_chan_disconnect(struct net_device *dev)
{
struct cycx_x25_channel *chan = netdev_priv(dev);
if (chan->svc) {
x25_clear_call(chan->card, chan->link, chan->lcn, 0, 0);
cycx_x25_set_chan_state(dev, WAN_DISCONNECTING);
} else
cycx_x25_set_chan_state(dev, WAN_DISCONNECTED);
}
static void cycx_x25_chan_timer(unsigned long d)
{
struct net_device *dev = (struct net_device *)d;
struct cycx_x25_channel *chan = netdev_priv(dev);
if (chan->state == WAN_CONNECTED)
cycx_x25_chan_disconnect(dev);
else
printk(KERN_ERR "%s: %s for svc (%s) not connected!\n",
chan->card->devname, __func__, dev->name);
}
static void cycx_x25_set_chan_state(struct net_device *dev, u8 state)
{
struct cycx_x25_channel *chan = netdev_priv(dev);
struct cycx_device *card = chan->card;
unsigned long flags;
char *string_state = NULL;
spin_lock_irqsave(&card->lock, flags);
if (chan->state != state) {
if (chan->svc && chan->state == WAN_CONNECTED)
del_timer(&chan->timer);
switch (state) {
case WAN_CONNECTED:
string_state = "connected!";
*(__be16*)dev->dev_addr = htons(chan->lcn);
netif_wake_queue(dev);
reset_timer(dev);
if (chan->protocol == ETH_P_X25)
cycx_x25_chan_send_event(dev,
X25_IFACE_CONNECT);
break;
case WAN_CONNECTING:
string_state = "connecting...";
break;
case WAN_DISCONNECTING:
string_state = "disconnecting...";
break;
case WAN_DISCONNECTED:
string_state = "disconnected!";
if (chan->svc) {
*(unsigned short*)dev->dev_addr = 0;
chan->lcn = 0;
}
if (chan->protocol == ETH_P_X25)
cycx_x25_chan_send_event(dev,
X25_IFACE_DISCONNECT);
netif_wake_queue(dev);
break;
}
printk(KERN_INFO "%s: interface %s %s\n", card->devname,
dev->name, string_state);
chan->state = state;
}
spin_unlock_irqrestore(&card->lock, flags);
}
static int cycx_x25_chan_send(struct net_device *dev, struct sk_buff *skb)
{
struct cycx_x25_channel *chan = netdev_priv(dev);
struct cycx_device *card = chan->card;
int bitm = 0;
unsigned len = skb->len;
if (skb->len > card->wandev.mtu) {
len = card->wandev.mtu;
bitm = 0x10;
}
if (cycx_x25_send(card, chan->link, chan->lcn, bitm, len, skb->data))
return 1;
if (bitm) {
skb_pull(skb, len);
return 1;
}
++chan->ifstats.tx_packets;
chan->ifstats.tx_bytes += len;
return 0;
}
static void cycx_x25_chan_send_event(struct net_device *dev, u8 event)
{
struct sk_buff *skb;
unsigned char *ptr;
if ((skb = dev_alloc_skb(1)) == NULL) {
printk(KERN_ERR "%s: out of memory\n", __func__);
return;
}
ptr = skb_put(skb, 1);
*ptr = event;
skb->protocol = x25_type_trans(skb, dev);
netif_rx(skb);
}
static u8 bps_to_speed_code(u32 bps)
{
u8 number = 0;
if (bps >= 512000) number = 8;
else if (bps >= 256000) number = 7;
else if (bps >= 64000) number = 6;
else if (bps >= 38400) number = 5;
else if (bps >= 19200) number = 4;
else if (bps >= 9600) number = 3;
else if (bps >= 4800) number = 2;
else if (bps >= 2400) number = 1;
return number;
}
static u8 cycx_log2(u32 n)
{
u8 log = 0;
if (!n)
return 0;
while (n > 1) {
n >>= 1;
++log;
}
return log;
}
static unsigned dec_to_uint(u8 *str, int len)
{
unsigned val = 0;
if (!len)
len = strlen(str);
for (; len && isdigit(*str); ++str, --len)
val = (val * 10) + (*str - (unsigned) '0');
return val;
}
static void reset_timer(struct net_device *dev)
{
struct cycx_x25_channel *chan = netdev_priv(dev);
if (chan->svc)
mod_timer(&chan->timer, jiffies+chan->idle_tmout*HZ);
}
static void cycx_x25_dump_config(struct cycx_x25_config *conf)
{
printk(KERN_INFO "X.25 configuration\n");
printk(KERN_INFO "-----------------\n");
printk(KERN_INFO "link number=%d\n", conf->link);
printk(KERN_INFO "line speed=%d\n", conf->speed);
printk(KERN_INFO "clock=%sternal\n", conf->clock == 8 ? "Ex" : "In");
printk(KERN_INFO "# level 2 retransm.=%d\n", conf->n2);
printk(KERN_INFO "level 2 window=%d\n", conf->n2win);
printk(KERN_INFO "level 3 window=%d\n", conf->n3win);
printk(KERN_INFO "# logical channels=%d\n", conf->nvc);
printk(KERN_INFO "level 3 pkt len=%d\n", conf->pktlen);
printk(KERN_INFO "my address=%d\n", conf->locaddr);
printk(KERN_INFO "remote address=%d\n", conf->remaddr);
printk(KERN_INFO "t1=%d seconds\n", conf->t1);
printk(KERN_INFO "t2=%d seconds\n", conf->t2);
printk(KERN_INFO "t21=%d seconds\n", conf->t21);
printk(KERN_INFO "# PVCs=%d\n", conf->npvc);
printk(KERN_INFO "t23=%d seconds\n", conf->t23);
printk(KERN_INFO "flags=0x%x\n", conf->flags);
}
static void cycx_x25_dump_stats(struct cycx_x25_stats *stats)
{
printk(KERN_INFO "X.25 statistics\n");
printk(KERN_INFO "--------------\n");
printk(KERN_INFO "rx_crc_errors=%d\n", stats->rx_crc_errors);
printk(KERN_INFO "rx_over_errors=%d\n", stats->rx_over_errors);
printk(KERN_INFO "n2_tx_frames=%d\n", stats->n2_tx_frames);
printk(KERN_INFO "n2_rx_frames=%d\n", stats->n2_rx_frames);
printk(KERN_INFO "tx_timeouts=%d\n", stats->tx_timeouts);
printk(KERN_INFO "rx_timeouts=%d\n", stats->rx_timeouts);
printk(KERN_INFO "n3_tx_packets=%d\n", stats->n3_tx_packets);
printk(KERN_INFO "n3_rx_packets=%d\n", stats->n3_rx_packets);
printk(KERN_INFO "tx_aborts=%d\n", stats->tx_aborts);
printk(KERN_INFO "rx_aborts=%d\n", stats->rx_aborts);
}
static void cycx_x25_dump_devs(struct wan_device *wandev)
{
struct net_device *dev = wandev->dev;
printk(KERN_INFO "X.25 dev states\n");
printk(KERN_INFO "name: addr: txoff: protocol:\n");
printk(KERN_INFO "---------------------------------------\n");
while(dev) {
struct cycx_x25_channel *chan = netdev_priv(dev);
printk(KERN_INFO "%-5.5s %-15.15s %d ETH_P_%s\n",
chan->name, chan->addr, netif_queue_stopped(dev),
chan->protocol == ETH_P_IP ? "IP" : "X25");
dev = chan->slave;
}
}
