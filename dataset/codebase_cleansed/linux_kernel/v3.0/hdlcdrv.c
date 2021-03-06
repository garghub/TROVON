static inline void append_crc_ccitt(unsigned char *buffer, int len)
{
unsigned int crc = crc_ccitt(0xffff, buffer, len) ^ 0xffff;
buffer += len;
*buffer++ = crc;
*buffer++ = crc >> 8;
}
static inline int check_crc_ccitt(const unsigned char *buf, int cnt)
{
return (crc_ccitt(0xffff, buf, cnt) & 0xffff) == 0xf0b8;
}
static int hdlc_rx_add_bytes(struct hdlcdrv_state *s, unsigned int bits,
int num)
{
int added = 0;
while (s->hdlcrx.rx_state && num >= 8) {
if (s->hdlcrx.len >= sizeof(s->hdlcrx.buffer)) {
s->hdlcrx.rx_state = 0;
return 0;
}
*s->hdlcrx.bp++ = bits >> (32-num);
s->hdlcrx.len++;
num -= 8;
added += 8;
}
return added;
}
static void hdlc_rx_flag(struct net_device *dev, struct hdlcdrv_state *s)
{
struct sk_buff *skb;
int pkt_len;
unsigned char *cp;
if (s->hdlcrx.len < 4)
return;
if (!check_crc_ccitt(s->hdlcrx.buffer, s->hdlcrx.len))
return;
pkt_len = s->hdlcrx.len - 2 + 1;
if (!(skb = dev_alloc_skb(pkt_len))) {
printk("%s: memory squeeze, dropping packet\n", dev->name);
dev->stats.rx_dropped++;
return;
}
cp = skb_put(skb, pkt_len);
*cp++ = 0;
memcpy(cp, s->hdlcrx.buffer, pkt_len - 1);
skb->protocol = ax25_type_trans(skb, dev);
netif_rx(skb);
dev->stats.rx_packets++;
}
void hdlcdrv_receiver(struct net_device *dev, struct hdlcdrv_state *s)
{
int i;
unsigned int mask1, mask2, mask3, mask4, mask5, mask6, word;
if (!s || s->magic != HDLCDRV_MAGIC)
return;
if (test_and_set_bit(0, &s->hdlcrx.in_hdlc_rx))
return;
while (!hdlcdrv_hbuf_empty(&s->hdlcrx.hbuf)) {
word = hdlcdrv_hbuf_get(&s->hdlcrx.hbuf);
#ifdef HDLCDRV_DEBUG
hdlcdrv_add_bitbuffer_word(&s->bitbuf_hdlc, word);
#endif
s->hdlcrx.bitstream >>= 16;
s->hdlcrx.bitstream |= word << 16;
s->hdlcrx.bitbuf >>= 16;
s->hdlcrx.bitbuf |= word << 16;
s->hdlcrx.numbits += 16;
for(i = 15, mask1 = 0x1fc00, mask2 = 0x1fe00, mask3 = 0x0fc00,
mask4 = 0x1f800, mask5 = 0xf800, mask6 = 0xffff;
i >= 0;
i--, mask1 <<= 1, mask2 <<= 1, mask3 <<= 1, mask4 <<= 1,
mask5 <<= 1, mask6 = (mask6 << 1) | 1) {
if ((s->hdlcrx.bitstream & mask1) == mask1)
s->hdlcrx.rx_state = 0;
else if ((s->hdlcrx.bitstream & mask2) == mask3) {
if (s->hdlcrx.rx_state) {
hdlc_rx_add_bytes(s, s->hdlcrx.bitbuf
<< (8+i),
s->hdlcrx.numbits
-8-i);
hdlc_rx_flag(dev, s);
}
s->hdlcrx.len = 0;
s->hdlcrx.bp = s->hdlcrx.buffer;
s->hdlcrx.rx_state = 1;
s->hdlcrx.numbits = i;
} else if ((s->hdlcrx.bitstream & mask4) == mask5) {
s->hdlcrx.numbits--;
s->hdlcrx.bitbuf = (s->hdlcrx.bitbuf & (~mask6)) |
((s->hdlcrx.bitbuf & mask6) << 1);
}
}
s->hdlcrx.numbits -= hdlc_rx_add_bytes(s, s->hdlcrx.bitbuf,
s->hdlcrx.numbits);
}
clear_bit(0, &s->hdlcrx.in_hdlc_rx);
}
static inline void do_kiss_params(struct hdlcdrv_state *s,
unsigned char *data, unsigned long len)
{
#ifdef KISS_VERBOSE
#define PKP(a,b) printk(KERN_INFO "hdlcdrv.c: channel params: " a "\n", b)
#else
#define PKP(a,b)
#endif
if (len < 2)
return;
switch(data[0]) {
case PARAM_TXDELAY:
s->ch_params.tx_delay = data[1];
PKP("TX delay = %ums", 10 * s->ch_params.tx_delay);
break;
case PARAM_PERSIST:
s->ch_params.ppersist = data[1];
PKP("p persistence = %u", s->ch_params.ppersist);
break;
case PARAM_SLOTTIME:
s->ch_params.slottime = data[1];
PKP("slot time = %ums", s->ch_params.slottime);
break;
case PARAM_TXTAIL:
s->ch_params.tx_tail = data[1];
PKP("TX tail = %ums", s->ch_params.tx_tail);
break;
case PARAM_FULLDUP:
s->ch_params.fulldup = !!data[1];
PKP("%s duplex", s->ch_params.fulldup ? "full" : "half");
break;
default:
break;
}
#undef PKP
}
void hdlcdrv_transmitter(struct net_device *dev, struct hdlcdrv_state *s)
{
unsigned int mask1, mask2, mask3;
int i;
struct sk_buff *skb;
int pkt_len;
if (!s || s->magic != HDLCDRV_MAGIC)
return;
if (test_and_set_bit(0, &s->hdlctx.in_hdlc_tx))
return;
for (;;) {
if (s->hdlctx.numbits >= 16) {
if (hdlcdrv_hbuf_full(&s->hdlctx.hbuf)) {
clear_bit(0, &s->hdlctx.in_hdlc_tx);
return;
}
hdlcdrv_hbuf_put(&s->hdlctx.hbuf, s->hdlctx.bitbuf);
s->hdlctx.bitbuf >>= 16;
s->hdlctx.numbits -= 16;
}
switch (s->hdlctx.tx_state) {
default:
clear_bit(0, &s->hdlctx.in_hdlc_tx);
return;
case 0:
case 1:
if (s->hdlctx.numflags) {
s->hdlctx.numflags--;
s->hdlctx.bitbuf |=
0x7e7e << s->hdlctx.numbits;
s->hdlctx.numbits += 16;
break;
}
if (s->hdlctx.tx_state == 1) {
clear_bit(0, &s->hdlctx.in_hdlc_tx);
return;
}
if (!(skb = s->skb)) {
int flgs = tenms_to_2flags(s, s->ch_params.tx_tail);
if (flgs < 2)
flgs = 2;
s->hdlctx.tx_state = 1;
s->hdlctx.numflags = flgs;
break;
}
s->skb = NULL;
netif_wake_queue(dev);
pkt_len = skb->len-1;
if (pkt_len >= HDLCDRV_MAXFLEN || pkt_len < 2) {
s->hdlctx.tx_state = 0;
s->hdlctx.numflags = 1;
dev_kfree_skb_irq(skb);
break;
}
skb_copy_from_linear_data_offset(skb, 1,
s->hdlctx.buffer,
pkt_len);
dev_kfree_skb_irq(skb);
s->hdlctx.bp = s->hdlctx.buffer;
append_crc_ccitt(s->hdlctx.buffer, pkt_len);
s->hdlctx.len = pkt_len+2;
s->hdlctx.tx_state = 2;
s->hdlctx.bitstream = 0;
dev->stats.tx_packets++;
break;
case 2:
if (!s->hdlctx.len) {
s->hdlctx.tx_state = 0;
s->hdlctx.numflags = 1;
break;
}
s->hdlctx.len--;
s->hdlctx.bitbuf |= *s->hdlctx.bp <<
s->hdlctx.numbits;
s->hdlctx.bitstream >>= 8;
s->hdlctx.bitstream |= (*s->hdlctx.bp++) << 16;
mask1 = 0x1f000;
mask2 = 0x10000;
mask3 = 0xffffffff >> (31-s->hdlctx.numbits);
s->hdlctx.numbits += 8;
for(i = 0; i < 8; i++, mask1 <<= 1, mask2 <<= 1,
mask3 = (mask3 << 1) | 1) {
if ((s->hdlctx.bitstream & mask1) != mask1)
continue;
s->hdlctx.bitstream &= ~mask2;
s->hdlctx.bitbuf =
(s->hdlctx.bitbuf & mask3) |
((s->hdlctx.bitbuf &
(~mask3)) << 1);
s->hdlctx.numbits++;
mask3 = (mask3 << 1) | 1;
}
break;
}
}
}
static void start_tx(struct net_device *dev, struct hdlcdrv_state *s)
{
s->hdlctx.tx_state = 0;
s->hdlctx.numflags = tenms_to_2flags(s, s->ch_params.tx_delay);
s->hdlctx.bitbuf = s->hdlctx.bitstream = s->hdlctx.numbits = 0;
hdlcdrv_transmitter(dev, s);
s->hdlctx.ptt = 1;
s->ptt_keyed++;
}
void hdlcdrv_arbitrate(struct net_device *dev, struct hdlcdrv_state *s)
{
if (!s || s->magic != HDLCDRV_MAGIC || s->hdlctx.ptt || !s->skb)
return;
if (s->ch_params.fulldup) {
start_tx(dev, s);
return;
}
if (s->hdlcrx.dcd) {
s->hdlctx.slotcnt = s->ch_params.slottime;
return;
}
if ((--s->hdlctx.slotcnt) > 0)
return;
s->hdlctx.slotcnt = s->ch_params.slottime;
if ((random32() % 256) > s->ch_params.ppersist)
return;
start_tx(dev, s);
}
static netdev_tx_t hdlcdrv_send_packet(struct sk_buff *skb,
struct net_device *dev)
{
struct hdlcdrv_state *sm = netdev_priv(dev);
if (skb->data[0] != 0) {
do_kiss_params(sm, skb->data, skb->len);
dev_kfree_skb(skb);
return NETDEV_TX_OK;
}
if (sm->skb)
return NETDEV_TX_LOCKED;
netif_stop_queue(dev);
sm->skb = skb;
return NETDEV_TX_OK;
}
static int hdlcdrv_set_mac_address(struct net_device *dev, void *addr)
{
struct sockaddr *sa = (struct sockaddr *)addr;
memcpy(dev->dev_addr, sa->sa_data, dev->addr_len);
return 0;
}
static int hdlcdrv_open(struct net_device *dev)
{
struct hdlcdrv_state *s = netdev_priv(dev);
int i;
if (!s->ops || !s->ops->open)
return -ENODEV;
s->opened = 1;
s->hdlcrx.hbuf.rd = s->hdlcrx.hbuf.wr = 0;
s->hdlcrx.in_hdlc_rx = 0;
s->hdlcrx.rx_state = 0;
s->hdlctx.hbuf.rd = s->hdlctx.hbuf.wr = 0;
s->hdlctx.in_hdlc_tx = 0;
s->hdlctx.tx_state = 1;
s->hdlctx.numflags = 0;
s->hdlctx.bitstream = s->hdlctx.bitbuf = s->hdlctx.numbits = 0;
s->hdlctx.ptt = 0;
s->hdlctx.slotcnt = s->ch_params.slottime;
s->hdlctx.calibrate = 0;
i = s->ops->open(dev);
if (i)
return i;
netif_start_queue(dev);
return 0;
}
static int hdlcdrv_close(struct net_device *dev)
{
struct hdlcdrv_state *s = netdev_priv(dev);
int i = 0;
netif_stop_queue(dev);
if (s->ops && s->ops->close)
i = s->ops->close(dev);
if (s->skb)
dev_kfree_skb(s->skb);
s->skb = NULL;
s->opened = 0;
return i;
}
static int hdlcdrv_ioctl(struct net_device *dev, struct ifreq *ifr, int cmd)
{
struct hdlcdrv_state *s = netdev_priv(dev);
struct hdlcdrv_ioctl bi;
if (cmd != SIOCDEVPRIVATE) {
if (s->ops && s->ops->ioctl)
return s->ops->ioctl(dev, ifr, &bi, cmd);
return -ENOIOCTLCMD;
}
if (copy_from_user(&bi, ifr->ifr_data, sizeof(bi)))
return -EFAULT;
switch (bi.cmd) {
default:
if (s->ops && s->ops->ioctl)
return s->ops->ioctl(dev, ifr, &bi, cmd);
return -ENOIOCTLCMD;
case HDLCDRVCTL_GETCHANNELPAR:
bi.data.cp.tx_delay = s->ch_params.tx_delay;
bi.data.cp.tx_tail = s->ch_params.tx_tail;
bi.data.cp.slottime = s->ch_params.slottime;
bi.data.cp.ppersist = s->ch_params.ppersist;
bi.data.cp.fulldup = s->ch_params.fulldup;
break;
case HDLCDRVCTL_SETCHANNELPAR:
if (!capable(CAP_NET_ADMIN))
return -EACCES;
s->ch_params.tx_delay = bi.data.cp.tx_delay;
s->ch_params.tx_tail = bi.data.cp.tx_tail;
s->ch_params.slottime = bi.data.cp.slottime;
s->ch_params.ppersist = bi.data.cp.ppersist;
s->ch_params.fulldup = bi.data.cp.fulldup;
s->hdlctx.slotcnt = 1;
return 0;
case HDLCDRVCTL_GETMODEMPAR:
bi.data.mp.iobase = dev->base_addr;
bi.data.mp.irq = dev->irq;
bi.data.mp.dma = dev->dma;
bi.data.mp.dma2 = s->ptt_out.dma2;
bi.data.mp.seriobase = s->ptt_out.seriobase;
bi.data.mp.pariobase = s->ptt_out.pariobase;
bi.data.mp.midiiobase = s->ptt_out.midiiobase;
break;
case HDLCDRVCTL_SETMODEMPAR:
if ((!capable(CAP_SYS_RAWIO)) || netif_running(dev))
return -EACCES;
dev->base_addr = bi.data.mp.iobase;
dev->irq = bi.data.mp.irq;
dev->dma = bi.data.mp.dma;
s->ptt_out.dma2 = bi.data.mp.dma2;
s->ptt_out.seriobase = bi.data.mp.seriobase;
s->ptt_out.pariobase = bi.data.mp.pariobase;
s->ptt_out.midiiobase = bi.data.mp.midiiobase;
return 0;
case HDLCDRVCTL_GETSTAT:
bi.data.cs.ptt = hdlcdrv_ptt(s);
bi.data.cs.dcd = s->hdlcrx.dcd;
bi.data.cs.ptt_keyed = s->ptt_keyed;
bi.data.cs.tx_packets = dev->stats.tx_packets;
bi.data.cs.tx_errors = dev->stats.tx_errors;
bi.data.cs.rx_packets = dev->stats.rx_packets;
bi.data.cs.rx_errors = dev->stats.rx_errors;
break;
case HDLCDRVCTL_OLDGETSTAT:
bi.data.ocs.ptt = hdlcdrv_ptt(s);
bi.data.ocs.dcd = s->hdlcrx.dcd;
bi.data.ocs.ptt_keyed = s->ptt_keyed;
break;
case HDLCDRVCTL_CALIBRATE:
if(!capable(CAP_SYS_RAWIO))
return -EPERM;
s->hdlctx.calibrate = bi.data.calibrate * s->par.bitrate / 16;
return 0;
case HDLCDRVCTL_GETSAMPLES:
#ifndef HDLCDRV_DEBUG
return -EPERM;
#else
if (s->bitbuf_channel.rd == s->bitbuf_channel.wr)
return -EAGAIN;
bi.data.bits =
s->bitbuf_channel.buffer[s->bitbuf_channel.rd];
s->bitbuf_channel.rd = (s->bitbuf_channel.rd+1) %
sizeof(s->bitbuf_channel.buffer);
break;
#endif
case HDLCDRVCTL_GETBITS:
#ifndef HDLCDRV_DEBUG
return -EPERM;
#else
if (s->bitbuf_hdlc.rd == s->bitbuf_hdlc.wr)
return -EAGAIN;
bi.data.bits =
s->bitbuf_hdlc.buffer[s->bitbuf_hdlc.rd];
s->bitbuf_hdlc.rd = (s->bitbuf_hdlc.rd+1) %
sizeof(s->bitbuf_hdlc.buffer);
break;
#endif
case HDLCDRVCTL_DRIVERNAME:
if (s->ops && s->ops->drvname) {
strncpy(bi.data.drivername, s->ops->drvname,
sizeof(bi.data.drivername));
break;
}
bi.data.drivername[0] = '\0';
break;
}
if (copy_to_user(ifr->ifr_data, &bi, sizeof(bi)))
return -EFAULT;
return 0;
}
static void hdlcdrv_setup(struct net_device *dev)
{
static const struct hdlcdrv_channel_params dflt_ch_params = {
20, 2, 10, 40, 0
};
struct hdlcdrv_state *s = netdev_priv(dev);
s->ch_params = dflt_ch_params;
s->ptt_keyed = 0;
spin_lock_init(&s->hdlcrx.hbuf.lock);
s->hdlcrx.hbuf.rd = s->hdlcrx.hbuf.wr = 0;
s->hdlcrx.in_hdlc_rx = 0;
s->hdlcrx.rx_state = 0;
spin_lock_init(&s->hdlctx.hbuf.lock);
s->hdlctx.hbuf.rd = s->hdlctx.hbuf.wr = 0;
s->hdlctx.in_hdlc_tx = 0;
s->hdlctx.tx_state = 1;
s->hdlctx.numflags = 0;
s->hdlctx.bitstream = s->hdlctx.bitbuf = s->hdlctx.numbits = 0;
s->hdlctx.ptt = 0;
s->hdlctx.slotcnt = s->ch_params.slottime;
s->hdlctx.calibrate = 0;
#ifdef HDLCDRV_DEBUG
s->bitbuf_channel.rd = s->bitbuf_channel.wr = 0;
s->bitbuf_channel.shreg = 0x80;
s->bitbuf_hdlc.rd = s->bitbuf_hdlc.wr = 0;
s->bitbuf_hdlc.shreg = 0x80;
#endif
s->skb = NULL;
dev->netdev_ops = &hdlcdrv_netdev;
dev->header_ops = &ax25_header_ops;
dev->type = ARPHRD_AX25;
dev->hard_header_len = AX25_MAX_HEADER_LEN + AX25_BPQ_HEADER_LEN;
dev->mtu = AX25_DEF_PACLEN;
dev->addr_len = AX25_ADDR_LEN;
memcpy(dev->broadcast, &ax25_bcast, AX25_ADDR_LEN);
memcpy(dev->dev_addr, &ax25_defaddr, AX25_ADDR_LEN);
dev->tx_queue_len = 16;
}
struct net_device *hdlcdrv_register(const struct hdlcdrv_ops *ops,
unsigned int privsize, const char *ifname,
unsigned int baseaddr, unsigned int irq,
unsigned int dma)
{
struct net_device *dev;
struct hdlcdrv_state *s;
int err;
BUG_ON(ops == NULL);
if (privsize < sizeof(struct hdlcdrv_state))
privsize = sizeof(struct hdlcdrv_state);
dev = alloc_netdev(privsize, ifname, hdlcdrv_setup);
if (!dev)
return ERR_PTR(-ENOMEM);
s = netdev_priv(dev);
s->magic = HDLCDRV_MAGIC;
s->ops = ops;
dev->base_addr = baseaddr;
dev->irq = irq;
dev->dma = dma;
err = register_netdev(dev);
if (err < 0) {
printk(KERN_WARNING "hdlcdrv: cannot register net "
"device %s\n", dev->name);
free_netdev(dev);
dev = ERR_PTR(err);
}
return dev;
}
void hdlcdrv_unregister(struct net_device *dev)
{
struct hdlcdrv_state *s = netdev_priv(dev);
BUG_ON(s->magic != HDLCDRV_MAGIC);
if (s->opened && s->ops->close)
s->ops->close(dev);
unregister_netdev(dev);
free_netdev(dev);
}
static int __init hdlcdrv_init_driver(void)
{
printk(KERN_INFO "hdlcdrv: (C) 1996-2000 Thomas Sailer HB9JNX/AE4WA\n");
printk(KERN_INFO "hdlcdrv: version 0.8\n");
return 0;
}
static void __exit hdlcdrv_cleanup_driver(void)
{
printk(KERN_INFO "hdlcdrv: cleanup\n");
}
