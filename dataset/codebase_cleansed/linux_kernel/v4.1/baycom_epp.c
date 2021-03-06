static inline int check_crc_ccitt(const unsigned char *buf, int cnt)
{
return (crc_ccitt(0xffff, buf, cnt) & 0xffff) == 0xf0b8;
}
static inline int calc_crc_ccitt(const unsigned char *buf, int cnt)
{
return (crc_ccitt(0xffff, buf, cnt) ^ 0xffff) & 0xffff;
}
static inline void baycom_int_freq(struct baycom_state *bc)
{
#ifdef BAYCOM_DEBUG
unsigned long cur_jiffies = jiffies;
bc->debug_vals.cur_intcnt++;
if (time_after_eq(cur_jiffies, bc->debug_vals.last_jiffies + HZ)) {
bc->debug_vals.last_jiffies = cur_jiffies;
bc->debug_vals.last_intcnt = bc->debug_vals.cur_intcnt;
bc->debug_vals.cur_intcnt = 0;
bc->debug_vals.last_pllcorr = bc->debug_vals.cur_pllcorr;
bc->debug_vals.cur_pllcorr = 0;
}
#endif
}
static int eppconfig(struct baycom_state *bc)
{
char modearg[256];
char portarg[16];
char *argv[] = { eppconfig_path, "-s", "-p", portarg, "-m", modearg,
NULL };
sprintf(modearg, "%sclk,%smodem,fclk=%d,bps=%d,divider=%d%s,extstat",
bc->cfg.intclk ? "int" : "ext",
bc->cfg.extmodem ? "ext" : "int", bc->cfg.fclk, bc->cfg.bps,
(bc->cfg.fclk + 8 * bc->cfg.bps) / (16 * bc->cfg.bps),
bc->cfg.loopback ? ",loopback" : "");
sprintf(portarg, "%ld", bc->pdev->port->base);
printk(KERN_DEBUG "%s: %s -s -p %s -m %s\n", bc_drvname, eppconfig_path, portarg, modearg);
return call_usermodehelper(eppconfig_path, argv, envp, UMH_WAIT_PROC);
}
static inline void do_kiss_params(struct baycom_state *bc,
unsigned char *data, unsigned long len)
{
#ifdef KISS_VERBOSE
#define PKP(a,b) printk(KERN_INFO "baycomm_epp: channel params: " a "\n", b)
#else
#define PKP(a,b)
#endif
if (len < 2)
return;
switch(data[0]) {
case PARAM_TXDELAY:
bc->ch_params.tx_delay = data[1];
PKP("TX delay = %ums", 10 * bc->ch_params.tx_delay);
break;
case PARAM_PERSIST:
bc->ch_params.ppersist = data[1];
PKP("p persistence = %u", bc->ch_params.ppersist);
break;
case PARAM_SLOTTIME:
bc->ch_params.slottime = data[1];
PKP("slot time = %ums", bc->ch_params.slottime);
break;
case PARAM_TXTAIL:
bc->ch_params.tx_tail = data[1];
PKP("TX tail = %ums", bc->ch_params.tx_tail);
break;
case PARAM_FULLDUP:
bc->ch_params.fulldup = !!data[1];
PKP("%s duplex", bc->ch_params.fulldup ? "full" : "half");
break;
default:
break;
}
#undef PKP
}
static void encode_hdlc(struct baycom_state *bc)
{
struct sk_buff *skb;
unsigned char *wp, *bp;
int pkt_len;
unsigned bitstream, notbitstream, bitbuf, numbit, crc;
unsigned char crcarr[2];
int j;
if (bc->hdlctx.bufcnt > 0)
return;
skb = bc->skb;
if (!skb)
return;
bc->skb = NULL;
pkt_len = skb->len-1;
wp = bc->hdlctx.buf;
bp = skb->data+1;
crc = calc_crc_ccitt(bp, pkt_len);
crcarr[0] = crc;
crcarr[1] = crc >> 8;
*wp++ = 0x7e;
bitstream = bitbuf = numbit = 0;
while (pkt_len > -2) {
bitstream >>= 8;
bitstream |= ((unsigned int)*bp) << 8;
bitbuf |= ((unsigned int)*bp) << numbit;
notbitstream = ~bitstream;
bp++;
pkt_len--;
if (!pkt_len)
bp = crcarr;
for (j = 0; j < 8; j++)
if (unlikely(!(notbitstream & (0x1f0 << j)))) {
bitstream &= ~(0x100 << j);
bitbuf = (bitbuf & (((2 << j) << numbit) - 1)) |
((bitbuf & ~(((2 << j) << numbit) - 1)) << 1);
numbit++;
notbitstream = ~bitstream;
}
numbit += 8;
while (numbit >= 8) {
*wp++ = bitbuf;
bitbuf >>= 8;
numbit -= 8;
}
}
bitbuf |= 0x7e7e << numbit;
numbit += 16;
while (numbit >= 8) {
*wp++ = bitbuf;
bitbuf >>= 8;
numbit -= 8;
}
bc->hdlctx.bufptr = bc->hdlctx.buf;
bc->hdlctx.bufcnt = wp - bc->hdlctx.buf;
dev_kfree_skb(skb);
bc->dev->stats.tx_packets++;
}
static int transmit(struct baycom_state *bc, int cnt, unsigned char stat)
{
struct parport *pp = bc->pdev->port;
unsigned char tmp[128];
int i, j;
if (bc->hdlctx.state == tx_tail && !(stat & EPP_PTTBIT))
bc->hdlctx.state = tx_idle;
if (bc->hdlctx.state == tx_idle && bc->hdlctx.calibrate <= 0) {
if (bc->hdlctx.bufcnt <= 0)
encode_hdlc(bc);
if (bc->hdlctx.bufcnt <= 0)
return 0;
if (!bc->ch_params.fulldup) {
if (!(stat & EPP_DCDBIT)) {
bc->hdlctx.slotcnt = bc->ch_params.slottime;
return 0;
}
if ((--bc->hdlctx.slotcnt) > 0)
return 0;
bc->hdlctx.slotcnt = bc->ch_params.slottime;
if ((prandom_u32() % 256) > bc->ch_params.ppersist)
return 0;
}
}
if (bc->hdlctx.state == tx_idle && bc->hdlctx.bufcnt > 0) {
bc->hdlctx.state = tx_keyup;
bc->hdlctx.flags = tenms_to_flags(bc, bc->ch_params.tx_delay);
bc->ptt_keyed++;
}
while (cnt > 0) {
switch (bc->hdlctx.state) {
case tx_keyup:
i = min_t(int, cnt, bc->hdlctx.flags);
cnt -= i;
bc->hdlctx.flags -= i;
if (bc->hdlctx.flags <= 0)
bc->hdlctx.state = tx_data;
memset(tmp, 0x7e, sizeof(tmp));
while (i > 0) {
j = (i > sizeof(tmp)) ? sizeof(tmp) : i;
if (j != pp->ops->epp_write_data(pp, tmp, j, 0))
return -1;
i -= j;
}
break;
case tx_data:
if (bc->hdlctx.bufcnt <= 0) {
encode_hdlc(bc);
if (bc->hdlctx.bufcnt <= 0) {
bc->hdlctx.state = tx_tail;
bc->hdlctx.flags = tenms_to_flags(bc, bc->ch_params.tx_tail);
break;
}
}
i = min_t(int, cnt, bc->hdlctx.bufcnt);
bc->hdlctx.bufcnt -= i;
cnt -= i;
if (i != pp->ops->epp_write_data(pp, bc->hdlctx.bufptr, i, 0))
return -1;
bc->hdlctx.bufptr += i;
break;
case tx_tail:
encode_hdlc(bc);
if (bc->hdlctx.bufcnt > 0) {
bc->hdlctx.state = tx_data;
break;
}
i = min_t(int, cnt, bc->hdlctx.flags);
if (i) {
cnt -= i;
bc->hdlctx.flags -= i;
memset(tmp, 0x7e, sizeof(tmp));
while (i > 0) {
j = (i > sizeof(tmp)) ? sizeof(tmp) : i;
if (j != pp->ops->epp_write_data(pp, tmp, j, 0))
return -1;
i -= j;
}
break;
}
default:
if (bc->hdlctx.calibrate <= 0)
return 0;
i = min_t(int, cnt, bc->hdlctx.calibrate);
cnt -= i;
bc->hdlctx.calibrate -= i;
memset(tmp, 0, sizeof(tmp));
while (i > 0) {
j = (i > sizeof(tmp)) ? sizeof(tmp) : i;
if (j != pp->ops->epp_write_data(pp, tmp, j, 0))
return -1;
i -= j;
}
break;
}
}
return 0;
}
static void do_rxpacket(struct net_device *dev)
{
struct baycom_state *bc = netdev_priv(dev);
struct sk_buff *skb;
unsigned char *cp;
unsigned pktlen;
if (bc->hdlcrx.bufcnt < 4)
return;
if (!check_crc_ccitt(bc->hdlcrx.buf, bc->hdlcrx.bufcnt))
return;
pktlen = bc->hdlcrx.bufcnt-2+1;
if (!(skb = dev_alloc_skb(pktlen))) {
printk("%s: memory squeeze, dropping packet\n", dev->name);
dev->stats.rx_dropped++;
return;
}
cp = skb_put(skb, pktlen);
*cp++ = 0;
memcpy(cp, bc->hdlcrx.buf, pktlen - 1);
skb->protocol = ax25_type_trans(skb, dev);
netif_rx(skb);
dev->stats.rx_packets++;
}
static int receive(struct net_device *dev, int cnt)
{
struct baycom_state *bc = netdev_priv(dev);
struct parport *pp = bc->pdev->port;
unsigned int bitbuf, notbitstream, bitstream, numbits, state;
unsigned char tmp[128];
unsigned char *cp;
int cnt2, ret = 0;
int j;
numbits = bc->hdlcrx.numbits;
state = bc->hdlcrx.state;
bitstream = bc->hdlcrx.bitstream;
bitbuf = bc->hdlcrx.bitbuf;
while (cnt > 0) {
cnt2 = (cnt > sizeof(tmp)) ? sizeof(tmp) : cnt;
cnt -= cnt2;
if (cnt2 != pp->ops->epp_read_data(pp, tmp, cnt2, 0)) {
ret = -1;
break;
}
cp = tmp;
for (; cnt2 > 0; cnt2--, cp++) {
bitstream >>= 8;
bitstream |= (*cp) << 8;
bitbuf >>= 8;
bitbuf |= (*cp) << 8;
numbits += 8;
notbitstream = ~bitstream;
for (j = 0; j < 8; j++) {
if (unlikely(!(notbitstream & (0x0fc << j)))) {
if (!(notbitstream & (0x1fc << j)))
state = 0;
else if ((bitstream & (0x1fe << j)) == (0x0fc << j)) {
if (state)
do_rxpacket(dev);
bc->hdlcrx.bufcnt = 0;
bc->hdlcrx.bufptr = bc->hdlcrx.buf;
state = 1;
numbits = 7-j;
}
}
else if (unlikely((bitstream & (0x1f8 << j)) == (0xf8 << j))) {
numbits--;
bitbuf = (bitbuf & ((~0xff) << j)) | ((bitbuf & ~((~0xff) << j)) << 1);
}
}
while (state && numbits >= 8) {
if (bc->hdlcrx.bufcnt >= TXBUFFER_SIZE) {
state = 0;
} else {
*(bc->hdlcrx.bufptr)++ = bitbuf >> (16-numbits);
bc->hdlcrx.bufcnt++;
numbits -= 8;
}
}
}
}
bc->hdlcrx.numbits = numbits;
bc->hdlcrx.state = state;
bc->hdlcrx.bitstream = bitstream;
bc->hdlcrx.bitbuf = bitbuf;
return ret;
}
static void epp_bh(struct work_struct *work)
{
struct net_device *dev;
struct baycom_state *bc;
struct parport *pp;
unsigned char stat;
unsigned char tmp[2];
unsigned int time1 = 0, time2 = 0, time3 = 0;
int cnt, cnt2;
bc = container_of(work, struct baycom_state, run_work.work);
dev = bc->dev;
if (!bc->work_running)
return;
baycom_int_freq(bc);
pp = bc->pdev->port;
if (pp->ops->epp_read_addr(pp, &stat, 1, 0) != 1)
goto epptimeout;
bc->stat = stat;
bc->debug_vals.last_pllcorr = stat;
GETTICK(time1);
if (bc->modem == EPP_FPGAEXTSTATUS) {
tmp[0] = EPP_TX_FIFO_ENABLE|EPP_RX_FIFO_ENABLE|EPP_MODEM_ENABLE|1;
if (pp->ops->epp_write_addr(pp, tmp, 1, 0) != 1)
goto epptimeout;
if (pp->ops->epp_read_addr(pp, tmp, 2, 0) != 2)
goto epptimeout;
cnt = tmp[0] | (tmp[1] << 8);
cnt &= 0x7fff;
tmp[0] = EPP_TX_FIFO_ENABLE|EPP_RX_FIFO_ENABLE|EPP_MODEM_ENABLE|2;
if (pp->ops->epp_write_addr(pp, tmp, 1, 0) != 1)
goto epptimeout;
if (pp->ops->epp_read_addr(pp, tmp, 2, 0) != 2)
goto epptimeout;
cnt2 = tmp[0] | (tmp[1] << 8);
cnt2 = 16384 - (cnt2 & 0x7fff);
tmp[0] = EPP_TX_FIFO_ENABLE|EPP_RX_FIFO_ENABLE|EPP_MODEM_ENABLE;
if (pp->ops->epp_write_addr(pp, tmp, 1, 0) != 1)
goto epptimeout;
if (transmit(bc, cnt2, stat))
goto epptimeout;
GETTICK(time2);
if (receive(dev, cnt))
goto epptimeout;
if (pp->ops->epp_read_addr(pp, &stat, 1, 0) != 1)
goto epptimeout;
bc->stat = stat;
} else {
switch (stat & (EPP_NTAEF|EPP_NTHF)) {
case EPP_NTHF:
cnt = 2048 - 256;
break;
case EPP_NTAEF:
cnt = 2048 - 1793;
break;
case 0:
cnt = 0;
break;
default:
cnt = 2048 - 1025;
break;
}
if (transmit(bc, cnt, stat))
goto epptimeout;
GETTICK(time2);
while ((stat & (EPP_NRAEF|EPP_NRHF)) != EPP_NRHF) {
switch (stat & (EPP_NRAEF|EPP_NRHF)) {
case EPP_NRAEF:
cnt = 1025;
break;
case 0:
cnt = 1793;
break;
default:
cnt = 256;
break;
}
if (receive(dev, cnt))
goto epptimeout;
if (pp->ops->epp_read_addr(pp, &stat, 1, 0) != 1)
goto epptimeout;
}
cnt = 0;
if (bc->bitrate < 50000)
cnt = 256;
else if (bc->bitrate < 100000)
cnt = 128;
while (cnt > 0 && stat & EPP_NREF) {
if (receive(dev, 1))
goto epptimeout;
cnt--;
if (pp->ops->epp_read_addr(pp, &stat, 1, 0) != 1)
goto epptimeout;
}
}
GETTICK(time3);
#ifdef BAYCOM_DEBUG
bc->debug_vals.mod_cycles = time2 - time1;
bc->debug_vals.demod_cycles = time3 - time2;
#endif
schedule_delayed_work(&bc->run_work, 1);
if (!bc->skb)
netif_wake_queue(dev);
return;
epptimeout:
printk(KERN_ERR "%s: EPP timeout!\n", bc_drvname);
}
static int baycom_send_packet(struct sk_buff *skb, struct net_device *dev)
{
struct baycom_state *bc = netdev_priv(dev);
if (skb->protocol == htons(ETH_P_IP))
return ax25_ip_xmit(skb);
if (skb->data[0] != 0) {
do_kiss_params(bc, skb->data, skb->len);
dev_kfree_skb(skb);
return NETDEV_TX_OK;
}
if (bc->skb)
return NETDEV_TX_LOCKED;
if (skb->len >= HDLCDRV_MAXFLEN+1 || skb->len < 3) {
dev_kfree_skb(skb);
return NETDEV_TX_OK;
}
netif_stop_queue(dev);
bc->skb = skb;
return NETDEV_TX_OK;
}
static int baycom_set_mac_address(struct net_device *dev, void *addr)
{
struct sockaddr *sa = (struct sockaddr *)addr;
memcpy(dev->dev_addr, sa->sa_data, dev->addr_len);
return 0;
}
static void epp_wakeup(void *handle)
{
struct net_device *dev = (struct net_device *)handle;
struct baycom_state *bc = netdev_priv(dev);
printk(KERN_DEBUG "baycom_epp: %s: why am I being woken up?\n", dev->name);
if (!parport_claim(bc->pdev))
printk(KERN_DEBUG "baycom_epp: %s: I'm broken.\n", dev->name);
}
static int epp_open(struct net_device *dev)
{
struct baycom_state *bc = netdev_priv(dev);
struct parport *pp = parport_find_base(dev->base_addr);
unsigned int i, j;
unsigned char tmp[128];
unsigned char stat;
unsigned long tstart;
if (!pp) {
printk(KERN_ERR "%s: parport at 0x%lx unknown\n", bc_drvname, dev->base_addr);
return -ENXIO;
}
#if 0
if (pp->irq < 0) {
printk(KERN_ERR "%s: parport at 0x%lx has no irq\n", bc_drvname, pp->base);
parport_put_port(pp);
return -ENXIO;
}
#endif
if ((~pp->modes) & (PARPORT_MODE_TRISTATE | PARPORT_MODE_PCSPP | PARPORT_MODE_SAFEININT)) {
printk(KERN_ERR "%s: parport at 0x%lx cannot be used\n",
bc_drvname, pp->base);
parport_put_port(pp);
return -EIO;
}
memset(&bc->modem, 0, sizeof(bc->modem));
bc->pdev = parport_register_device(pp, dev->name, NULL, epp_wakeup,
NULL, PARPORT_DEV_EXCL, dev);
parport_put_port(pp);
if (!bc->pdev) {
printk(KERN_ERR "%s: cannot register parport at 0x%lx\n", bc_drvname, pp->base);
return -ENXIO;
}
if (parport_claim(bc->pdev)) {
printk(KERN_ERR "%s: parport at 0x%lx busy\n", bc_drvname, pp->base);
parport_unregister_device(bc->pdev);
return -EBUSY;
}
dev->irq = 0;
INIT_DELAYED_WORK(&bc->run_work, epp_bh);
bc->work_running = 1;
bc->modem = EPP_CONVENTIONAL;
if (eppconfig(bc))
printk(KERN_INFO "%s: no FPGA detected, assuming conventional EPP modem\n", bc_drvname);
else
bc->modem = EPP_FPGAEXTSTATUS;
parport_write_control(pp, LPTCTRL_PROGRAM);
tmp[0] = 0;
tmp[1] = EPP_TX_FIFO_ENABLE|EPP_RX_FIFO_ENABLE|EPP_MODEM_ENABLE;
if (pp->ops->epp_write_addr(pp, tmp, 2, 0) != 2)
goto epptimeout;
tstart = jiffies;
i = 0;
while (time_before(jiffies, tstart + HZ/3)) {
if (pp->ops->epp_read_addr(pp, &stat, 1, 0) != 1)
goto epptimeout;
if ((stat & (EPP_NRAEF|EPP_NRHF)) == EPP_NRHF) {
schedule();
continue;
}
if (pp->ops->epp_read_data(pp, tmp, 128, 0) != 128)
goto epptimeout;
if (pp->ops->epp_read_data(pp, tmp, 128, 0) != 128)
goto epptimeout;
i += 256;
}
for (j = 0; j < 256; j++) {
if (pp->ops->epp_read_addr(pp, &stat, 1, 0) != 1)
goto epptimeout;
if (!(stat & EPP_NREF))
break;
if (pp->ops->epp_read_data(pp, tmp, 1, 0) != 1)
goto epptimeout;
i++;
}
tstart = jiffies - tstart;
bc->bitrate = i * (8 * HZ) / tstart;
j = 1;
i = bc->bitrate >> 3;
while (j < 7 && i > 150) {
j++;
i >>= 1;
}
printk(KERN_INFO "%s: autoprobed bitrate: %d int divider: %d int rate: %d\n",
bc_drvname, bc->bitrate, j, bc->bitrate >> (j+2));
tmp[0] = EPP_TX_FIFO_ENABLE|EPP_RX_FIFO_ENABLE|EPP_MODEM_ENABLE;
if (pp->ops->epp_write_addr(pp, tmp, 1, 0) != 1)
goto epptimeout;
bc->hdlcrx.state = 0;
bc->hdlcrx.numbits = 0;
bc->hdlctx.state = tx_idle;
bc->hdlctx.bufcnt = 0;
bc->hdlctx.slotcnt = bc->ch_params.slottime;
bc->hdlctx.calibrate = 0;
schedule_delayed_work(&bc->run_work, 1);
netif_start_queue(dev);
return 0;
epptimeout:
printk(KERN_ERR "%s: epp timeout during bitrate probe\n", bc_drvname);
parport_write_control(pp, 0);
parport_release(bc->pdev);
parport_unregister_device(bc->pdev);
return -EIO;
}
static int epp_close(struct net_device *dev)
{
struct baycom_state *bc = netdev_priv(dev);
struct parport *pp = bc->pdev->port;
unsigned char tmp[1];
bc->work_running = 0;
cancel_delayed_work_sync(&bc->run_work);
bc->stat = EPP_DCDBIT;
tmp[0] = 0;
pp->ops->epp_write_addr(pp, tmp, 1, 0);
parport_write_control(pp, 0);
parport_release(bc->pdev);
parport_unregister_device(bc->pdev);
if (bc->skb)
dev_kfree_skb(bc->skb);
bc->skb = NULL;
printk(KERN_INFO "%s: close epp at iobase 0x%lx irq %u\n",
bc_drvname, dev->base_addr, dev->irq);
return 0;
}
static int baycom_setmode(struct baycom_state *bc, const char *modestr)
{
const char *cp;
if (strstr(modestr,"intclk"))
bc->cfg.intclk = 1;
if (strstr(modestr,"extclk"))
bc->cfg.intclk = 0;
if (strstr(modestr,"intmodem"))
bc->cfg.extmodem = 0;
if (strstr(modestr,"extmodem"))
bc->cfg.extmodem = 1;
if (strstr(modestr,"noloopback"))
bc->cfg.loopback = 0;
if (strstr(modestr,"loopback"))
bc->cfg.loopback = 1;
if ((cp = strstr(modestr,"fclk="))) {
bc->cfg.fclk = simple_strtoul(cp+5, NULL, 0);
if (bc->cfg.fclk < 1000000)
bc->cfg.fclk = 1000000;
if (bc->cfg.fclk > 25000000)
bc->cfg.fclk = 25000000;
}
if ((cp = strstr(modestr,"bps="))) {
bc->cfg.bps = simple_strtoul(cp+4, NULL, 0);
if (bc->cfg.bps < 1000)
bc->cfg.bps = 1000;
if (bc->cfg.bps > 1500000)
bc->cfg.bps = 1500000;
}
return 0;
}
static int baycom_ioctl(struct net_device *dev, struct ifreq *ifr, int cmd)
{
struct baycom_state *bc = netdev_priv(dev);
struct hdlcdrv_ioctl hi;
if (cmd != SIOCDEVPRIVATE)
return -ENOIOCTLCMD;
if (copy_from_user(&hi, ifr->ifr_data, sizeof(hi)))
return -EFAULT;
switch (hi.cmd) {
default:
return -ENOIOCTLCMD;
case HDLCDRVCTL_GETCHANNELPAR:
hi.data.cp.tx_delay = bc->ch_params.tx_delay;
hi.data.cp.tx_tail = bc->ch_params.tx_tail;
hi.data.cp.slottime = bc->ch_params.slottime;
hi.data.cp.ppersist = bc->ch_params.ppersist;
hi.data.cp.fulldup = bc->ch_params.fulldup;
break;
case HDLCDRVCTL_SETCHANNELPAR:
if (!capable(CAP_NET_ADMIN))
return -EACCES;
bc->ch_params.tx_delay = hi.data.cp.tx_delay;
bc->ch_params.tx_tail = hi.data.cp.tx_tail;
bc->ch_params.slottime = hi.data.cp.slottime;
bc->ch_params.ppersist = hi.data.cp.ppersist;
bc->ch_params.fulldup = hi.data.cp.fulldup;
bc->hdlctx.slotcnt = 1;
return 0;
case HDLCDRVCTL_GETMODEMPAR:
hi.data.mp.iobase = dev->base_addr;
hi.data.mp.irq = dev->irq;
hi.data.mp.dma = dev->dma;
hi.data.mp.dma2 = 0;
hi.data.mp.seriobase = 0;
hi.data.mp.pariobase = 0;
hi.data.mp.midiiobase = 0;
break;
case HDLCDRVCTL_SETMODEMPAR:
if ((!capable(CAP_SYS_RAWIO)) || netif_running(dev))
return -EACCES;
dev->base_addr = hi.data.mp.iobase;
dev->irq = 0;
dev->dma = 0;
return 0;
case HDLCDRVCTL_GETSTAT:
hi.data.cs.ptt = !!(bc->stat & EPP_PTTBIT);
hi.data.cs.dcd = !(bc->stat & EPP_DCDBIT);
hi.data.cs.ptt_keyed = bc->ptt_keyed;
hi.data.cs.tx_packets = dev->stats.tx_packets;
hi.data.cs.tx_errors = dev->stats.tx_errors;
hi.data.cs.rx_packets = dev->stats.rx_packets;
hi.data.cs.rx_errors = dev->stats.rx_errors;
break;
case HDLCDRVCTL_OLDGETSTAT:
hi.data.ocs.ptt = !!(bc->stat & EPP_PTTBIT);
hi.data.ocs.dcd = !(bc->stat & EPP_DCDBIT);
hi.data.ocs.ptt_keyed = bc->ptt_keyed;
break;
case HDLCDRVCTL_CALIBRATE:
if (!capable(CAP_SYS_RAWIO))
return -EACCES;
bc->hdlctx.calibrate = hi.data.calibrate * bc->bitrate / 8;
return 0;
case HDLCDRVCTL_DRIVERNAME:
strncpy(hi.data.drivername, "baycom_epp", sizeof(hi.data.drivername));
break;
case HDLCDRVCTL_GETMODE:
sprintf(hi.data.modename, "%sclk,%smodem,fclk=%d,bps=%d%s",
bc->cfg.intclk ? "int" : "ext",
bc->cfg.extmodem ? "ext" : "int", bc->cfg.fclk, bc->cfg.bps,
bc->cfg.loopback ? ",loopback" : "");
break;
case HDLCDRVCTL_SETMODE:
if (!capable(CAP_NET_ADMIN) || netif_running(dev))
return -EACCES;
hi.data.modename[sizeof(hi.data.modename)-1] = '\0';
return baycom_setmode(bc, hi.data.modename);
case HDLCDRVCTL_MODELIST:
strncpy(hi.data.modename, "intclk,extclk,intmodem,extmodem,divider=x",
sizeof(hi.data.modename));
break;
case HDLCDRVCTL_MODEMPARMASK:
return HDLCDRV_PARMASK_IOBASE;
}
if (copy_to_user(ifr->ifr_data, &hi, sizeof(hi)))
return -EFAULT;
return 0;
}
static void baycom_probe(struct net_device *dev)
{
const struct hdlcdrv_channel_params dflt_ch_params = {
20, 2, 10, 40, 0
};
struct baycom_state *bc;
bc = netdev_priv(dev);
bc->ch_params = dflt_ch_params;
bc->ptt_keyed = 0;
bc->skb = NULL;
dev->netdev_ops = &baycom_netdev_ops;
dev->header_ops = &ax25_header_ops;
dev->type = ARPHRD_AX25;
dev->hard_header_len = AX25_MAX_HEADER_LEN + AX25_BPQ_HEADER_LEN;
dev->mtu = AX25_DEF_PACLEN;
dev->addr_len = AX25_ADDR_LEN;
memcpy(dev->broadcast, &ax25_bcast, AX25_ADDR_LEN);
memcpy(dev->dev_addr, &null_ax25_address, AX25_ADDR_LEN);
dev->tx_queue_len = 16;
dev->flags = 0;
}
static void __init baycom_epp_dev_setup(struct net_device *dev)
{
struct baycom_state *bc = netdev_priv(dev);
bc->dev = dev;
bc->magic = BAYCOM_MAGIC;
bc->cfg.fclk = 19666600;
bc->cfg.bps = 9600;
baycom_probe(dev);
}
static int __init init_baycomepp(void)
{
int i, found = 0;
char set_hw = 1;
printk(bc_drvinfo);
for (i = 0; i < NR_PORTS; i++) {
struct net_device *dev;
dev = alloc_netdev(sizeof(struct baycom_state), "bce%d",
NET_NAME_UNKNOWN, baycom_epp_dev_setup);
if (!dev) {
printk(KERN_WARNING "bce%d : out of memory\n", i);
return found ? 0 : -ENOMEM;
}
sprintf(dev->name, "bce%d", i);
dev->base_addr = iobase[i];
if (!mode[i])
set_hw = 0;
if (!set_hw)
iobase[i] = 0;
if (register_netdev(dev)) {
printk(KERN_WARNING "%s: cannot register net device %s\n", bc_drvname, dev->name);
free_netdev(dev);
break;
}
if (set_hw && baycom_setmode(netdev_priv(dev), mode[i]))
set_hw = 0;
baycom_device[i] = dev;
found++;
}
return found ? 0 : -ENXIO;
}
static void __exit cleanup_baycomepp(void)
{
int i;
for(i = 0; i < NR_PORTS; i++) {
struct net_device *dev = baycom_device[i];
if (dev) {
struct baycom_state *bc = netdev_priv(dev);
if (bc->magic == BAYCOM_MAGIC) {
unregister_netdev(dev);
free_netdev(dev);
} else
printk(paranoia_str, "cleanup_module");
}
}
}
static int __init baycom_epp_setup(char *str)
{
static unsigned __initdata nr_dev = 0;
int ints[2];
if (nr_dev >= NR_PORTS)
return 0;
str = get_options(str, 2, ints);
if (ints[0] < 1)
return 0;
mode[nr_dev] = str;
iobase[nr_dev] = ints[1];
nr_dev++;
return 1;
}
