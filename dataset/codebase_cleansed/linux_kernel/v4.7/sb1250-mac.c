static void sbmac_mii_sync(void __iomem *sbm_mdio)
{
int cnt;
uint64_t bits;
int mac_mdio_genc;
mac_mdio_genc = __raw_readq(sbm_mdio) & M_MAC_GENC;
bits = M_MAC_MDIO_DIR_OUTPUT | M_MAC_MDIO_OUT;
__raw_writeq(bits | mac_mdio_genc, sbm_mdio);
for (cnt = 0; cnt < 32; cnt++) {
__raw_writeq(bits | M_MAC_MDC | mac_mdio_genc, sbm_mdio);
__raw_writeq(bits | mac_mdio_genc, sbm_mdio);
}
}
static void sbmac_mii_senddata(void __iomem *sbm_mdio, unsigned int data,
int bitcnt)
{
int i;
uint64_t bits;
unsigned int curmask;
int mac_mdio_genc;
mac_mdio_genc = __raw_readq(sbm_mdio) & M_MAC_GENC;
bits = M_MAC_MDIO_DIR_OUTPUT;
__raw_writeq(bits | mac_mdio_genc, sbm_mdio);
curmask = 1 << (bitcnt - 1);
for (i = 0; i < bitcnt; i++) {
if (data & curmask)
bits |= M_MAC_MDIO_OUT;
else bits &= ~M_MAC_MDIO_OUT;
__raw_writeq(bits | mac_mdio_genc, sbm_mdio);
__raw_writeq(bits | M_MAC_MDC | mac_mdio_genc, sbm_mdio);
__raw_writeq(bits | mac_mdio_genc, sbm_mdio);
curmask >>= 1;
}
}
static int sbmac_mii_read(struct mii_bus *bus, int phyaddr, int regidx)
{
struct sbmac_softc *sc = (struct sbmac_softc *)bus->priv;
void __iomem *sbm_mdio = sc->sbm_mdio;
int idx;
int error;
int regval;
int mac_mdio_genc;
sbmac_mii_sync(sbm_mdio);
sbmac_mii_senddata(sbm_mdio, MII_COMMAND_START, 2);
sbmac_mii_senddata(sbm_mdio, MII_COMMAND_READ, 2);
sbmac_mii_senddata(sbm_mdio, phyaddr, 5);
sbmac_mii_senddata(sbm_mdio, regidx, 5);
mac_mdio_genc = __raw_readq(sbm_mdio) & M_MAC_GENC;
__raw_writeq(M_MAC_MDIO_DIR_INPUT | mac_mdio_genc, sbm_mdio);
__raw_writeq(M_MAC_MDIO_DIR_INPUT | M_MAC_MDC | mac_mdio_genc,
sbm_mdio);
__raw_writeq(M_MAC_MDIO_DIR_INPUT | mac_mdio_genc, sbm_mdio);
error = __raw_readq(sbm_mdio) & M_MAC_MDIO_IN;
__raw_writeq(M_MAC_MDIO_DIR_INPUT | M_MAC_MDC | mac_mdio_genc,
sbm_mdio);
__raw_writeq(M_MAC_MDIO_DIR_INPUT | mac_mdio_genc, sbm_mdio);
regval = 0;
for (idx = 0; idx < 16; idx++) {
regval <<= 1;
if (error == 0) {
if (__raw_readq(sbm_mdio) & M_MAC_MDIO_IN)
regval |= 1;
}
__raw_writeq(M_MAC_MDIO_DIR_INPUT | M_MAC_MDC | mac_mdio_genc,
sbm_mdio);
__raw_writeq(M_MAC_MDIO_DIR_INPUT | mac_mdio_genc, sbm_mdio);
}
__raw_writeq(M_MAC_MDIO_DIR_OUTPUT | mac_mdio_genc, sbm_mdio);
if (error == 0)
return regval;
return 0xffff;
}
static int sbmac_mii_write(struct mii_bus *bus, int phyaddr, int regidx,
u16 regval)
{
struct sbmac_softc *sc = (struct sbmac_softc *)bus->priv;
void __iomem *sbm_mdio = sc->sbm_mdio;
int mac_mdio_genc;
sbmac_mii_sync(sbm_mdio);
sbmac_mii_senddata(sbm_mdio, MII_COMMAND_START, 2);
sbmac_mii_senddata(sbm_mdio, MII_COMMAND_WRITE, 2);
sbmac_mii_senddata(sbm_mdio, phyaddr, 5);
sbmac_mii_senddata(sbm_mdio, regidx, 5);
sbmac_mii_senddata(sbm_mdio, MII_COMMAND_ACK, 2);
sbmac_mii_senddata(sbm_mdio, regval, 16);
mac_mdio_genc = __raw_readq(sbm_mdio) & M_MAC_GENC;
__raw_writeq(M_MAC_MDIO_DIR_OUTPUT | mac_mdio_genc, sbm_mdio);
return 0;
}
static void sbdma_initctx(struct sbmacdma *d, struct sbmac_softc *s, int chan,
int txrx, int maxdescr)
{
#ifdef CONFIG_SBMAC_COALESCE
int int_pktcnt, int_timeout;
#endif
d->sbdma_eth = s;
d->sbdma_channel = chan;
d->sbdma_txdir = txrx;
#if 0
s->sbe_idx =(s->sbm_base - A_MAC_BASE_0)/MAC_SPACING;
#endif
__raw_writeq(0, s->sbm_base + R_MAC_RMON_TX_BYTES);
__raw_writeq(0, s->sbm_base + R_MAC_RMON_COLLISIONS);
__raw_writeq(0, s->sbm_base + R_MAC_RMON_LATE_COL);
__raw_writeq(0, s->sbm_base + R_MAC_RMON_EX_COL);
__raw_writeq(0, s->sbm_base + R_MAC_RMON_FCS_ERROR);
__raw_writeq(0, s->sbm_base + R_MAC_RMON_TX_ABORT);
__raw_writeq(0, s->sbm_base + R_MAC_RMON_TX_BAD);
__raw_writeq(0, s->sbm_base + R_MAC_RMON_TX_GOOD);
__raw_writeq(0, s->sbm_base + R_MAC_RMON_TX_RUNT);
__raw_writeq(0, s->sbm_base + R_MAC_RMON_TX_OVERSIZE);
__raw_writeq(0, s->sbm_base + R_MAC_RMON_RX_BYTES);
__raw_writeq(0, s->sbm_base + R_MAC_RMON_RX_MCAST);
__raw_writeq(0, s->sbm_base + R_MAC_RMON_RX_BCAST);
__raw_writeq(0, s->sbm_base + R_MAC_RMON_RX_BAD);
__raw_writeq(0, s->sbm_base + R_MAC_RMON_RX_GOOD);
__raw_writeq(0, s->sbm_base + R_MAC_RMON_RX_RUNT);
__raw_writeq(0, s->sbm_base + R_MAC_RMON_RX_OVERSIZE);
__raw_writeq(0, s->sbm_base + R_MAC_RMON_RX_FCS_ERROR);
__raw_writeq(0, s->sbm_base + R_MAC_RMON_RX_LENGTH_ERROR);
__raw_writeq(0, s->sbm_base + R_MAC_RMON_RX_CODE_ERROR);
__raw_writeq(0, s->sbm_base + R_MAC_RMON_RX_ALIGN_ERROR);
d->sbdma_config0 =
s->sbm_base + R_MAC_DMA_REGISTER(txrx,chan,R_MAC_DMA_CONFIG0);
d->sbdma_config1 =
s->sbm_base + R_MAC_DMA_REGISTER(txrx,chan,R_MAC_DMA_CONFIG1);
d->sbdma_dscrbase =
s->sbm_base + R_MAC_DMA_REGISTER(txrx,chan,R_MAC_DMA_DSCR_BASE);
d->sbdma_dscrcnt =
s->sbm_base + R_MAC_DMA_REGISTER(txrx,chan,R_MAC_DMA_DSCR_CNT);
d->sbdma_curdscr =
s->sbm_base + R_MAC_DMA_REGISTER(txrx,chan,R_MAC_DMA_CUR_DSCRADDR);
if (d->sbdma_txdir)
d->sbdma_oodpktlost = NULL;
else
d->sbdma_oodpktlost =
s->sbm_base + R_MAC_DMA_REGISTER(txrx,chan,R_MAC_DMA_OODPKTLOST_RX);
d->sbdma_maxdescr = maxdescr;
d->sbdma_dscrtable_unaligned = kcalloc(d->sbdma_maxdescr + 1,
sizeof(*d->sbdma_dscrtable),
GFP_KERNEL);
d->sbdma_dscrtable = (struct sbdmadscr *)
ALIGN((unsigned long)d->sbdma_dscrtable_unaligned,
sizeof(*d->sbdma_dscrtable));
d->sbdma_dscrtable_end = d->sbdma_dscrtable + d->sbdma_maxdescr;
d->sbdma_dscrtable_phys = virt_to_phys(d->sbdma_dscrtable);
d->sbdma_ctxtable = kcalloc(d->sbdma_maxdescr,
sizeof(*d->sbdma_ctxtable), GFP_KERNEL);
#ifdef CONFIG_SBMAC_COALESCE
int_pktcnt = (txrx == DMA_TX) ? int_pktcnt_tx : int_pktcnt_rx;
if ( int_pktcnt ) {
d->sbdma_int_pktcnt = int_pktcnt;
} else {
d->sbdma_int_pktcnt = 1;
}
int_timeout = (txrx == DMA_TX) ? int_timeout_tx : int_timeout_rx;
if ( int_timeout ) {
d->sbdma_int_timeout = int_timeout;
} else {
d->sbdma_int_timeout = 0;
}
#endif
}
static void sbdma_channel_start(struct sbmacdma *d, int rxtx)
{
#ifdef CONFIG_SBMAC_COALESCE
__raw_writeq(V_DMA_INT_TIMEOUT(d->sbdma_int_timeout) |
0, d->sbdma_config1);
__raw_writeq(M_DMA_EOP_INT_EN |
V_DMA_RINGSZ(d->sbdma_maxdescr) |
V_DMA_INT_PKTCNT(d->sbdma_int_pktcnt) |
0, d->sbdma_config0);
#else
__raw_writeq(0, d->sbdma_config1);
__raw_writeq(V_DMA_RINGSZ(d->sbdma_maxdescr) |
0, d->sbdma_config0);
#endif
__raw_writeq(d->sbdma_dscrtable_phys, d->sbdma_dscrbase);
d->sbdma_addptr = d->sbdma_dscrtable;
d->sbdma_remptr = d->sbdma_dscrtable;
}
static void sbdma_channel_stop(struct sbmacdma *d)
{
__raw_writeq(0, d->sbdma_config1);
__raw_writeq(0, d->sbdma_dscrbase);
__raw_writeq(0, d->sbdma_config0);
d->sbdma_addptr = NULL;
d->sbdma_remptr = NULL;
}
static inline void sbdma_align_skb(struct sk_buff *skb,
unsigned int power2, unsigned int offset)
{
unsigned char *addr = skb->data;
unsigned char *newaddr = PTR_ALIGN(addr, power2);
skb_reserve(skb, newaddr - addr + offset);
}
static int sbdma_add_rcvbuffer(struct sbmac_softc *sc, struct sbmacdma *d,
struct sk_buff *sb)
{
struct net_device *dev = sc->sbm_dev;
struct sbdmadscr *dsc;
struct sbdmadscr *nextdsc;
struct sk_buff *sb_new = NULL;
int pktsize = ENET_PACKET_SIZE;
dsc = d->sbdma_addptr;
nextdsc = SBDMA_NEXTBUF(d,sbdma_addptr);
if (nextdsc == d->sbdma_remptr) {
return -ENOSPC;
}
if (sb == NULL) {
sb_new = netdev_alloc_skb(dev, ENET_PACKET_SIZE +
SMP_CACHE_BYTES * 2 +
NET_IP_ALIGN);
if (sb_new == NULL)
return -ENOBUFS;
sbdma_align_skb(sb_new, SMP_CACHE_BYTES, NET_IP_ALIGN);
}
else {
sb_new = sb;
}
#ifdef CONFIG_SBMAC_COALESCE
dsc->dscr_a = virt_to_phys(sb_new->data) |
V_DMA_DSCRA_A_SIZE(NUMCACHEBLKS(pktsize + NET_IP_ALIGN)) | 0;
#else
dsc->dscr_a = virt_to_phys(sb_new->data) |
V_DMA_DSCRA_A_SIZE(NUMCACHEBLKS(pktsize + NET_IP_ALIGN)) |
M_DMA_DSCRA_INTERRUPT;
#endif
dsc->dscr_b = 0;
d->sbdma_ctxtable[dsc-d->sbdma_dscrtable] = sb_new;
d->sbdma_addptr = nextdsc;
__raw_writeq(1, d->sbdma_dscrcnt);
return 0;
}
static int sbdma_add_txbuffer(struct sbmacdma *d, struct sk_buff *sb)
{
struct sbdmadscr *dsc;
struct sbdmadscr *nextdsc;
uint64_t phys;
uint64_t ncb;
int length;
dsc = d->sbdma_addptr;
nextdsc = SBDMA_NEXTBUF(d,sbdma_addptr);
if (nextdsc == d->sbdma_remptr) {
return -ENOSPC;
}
length = sb->len;
phys = virt_to_phys(sb->data);
ncb = NUMCACHEBLKS(length+(phys & (SMP_CACHE_BYTES - 1)));
dsc->dscr_a = phys |
V_DMA_DSCRA_A_SIZE(ncb) |
#ifndef CONFIG_SBMAC_COALESCE
M_DMA_DSCRA_INTERRUPT |
#endif
M_DMA_ETHTX_SOP;
dsc->dscr_b = V_DMA_DSCRB_OPTIONS(K_DMA_ETHTX_APPENDCRC_APPENDPAD) |
V_DMA_DSCRB_PKT_SIZE(length);
d->sbdma_ctxtable[dsc-d->sbdma_dscrtable] = sb;
d->sbdma_addptr = nextdsc;
__raw_writeq(1, d->sbdma_dscrcnt);
return 0;
}
static void sbdma_emptyring(struct sbmacdma *d)
{
int idx;
struct sk_buff *sb;
for (idx = 0; idx < d->sbdma_maxdescr; idx++) {
sb = d->sbdma_ctxtable[idx];
if (sb) {
dev_kfree_skb(sb);
d->sbdma_ctxtable[idx] = NULL;
}
}
}
static void sbdma_fillring(struct sbmac_softc *sc, struct sbmacdma *d)
{
int idx;
for (idx = 0; idx < SBMAC_MAX_RXDESCR - 1; idx++) {
if (sbdma_add_rcvbuffer(sc, d, NULL) != 0)
break;
}
}
static void sbmac_netpoll(struct net_device *netdev)
{
struct sbmac_softc *sc = netdev_priv(netdev);
int irq = sc->sbm_dev->irq;
__raw_writeq(0, sc->sbm_imr);
sbmac_intr(irq, netdev);
#ifdef CONFIG_SBMAC_COALESCE
__raw_writeq(((M_MAC_INT_EOP_COUNT | M_MAC_INT_EOP_TIMER) << S_MAC_TX_CH0) |
((M_MAC_INT_EOP_COUNT | M_MAC_INT_EOP_TIMER) << S_MAC_RX_CH0),
sc->sbm_imr);
#else
__raw_writeq((M_MAC_INT_CHANNEL << S_MAC_TX_CH0) |
(M_MAC_INT_CHANNEL << S_MAC_RX_CH0), sc->sbm_imr);
#endif
}
static int sbdma_rx_process(struct sbmac_softc *sc, struct sbmacdma *d,
int work_to_do, int poll)
{
struct net_device *dev = sc->sbm_dev;
int curidx;
int hwidx;
struct sbdmadscr *dsc;
struct sk_buff *sb;
int len;
int work_done = 0;
int dropped = 0;
prefetch(d);
again:
dev->stats.rx_fifo_errors
+= __raw_readq(sc->sbm_rxdma.sbdma_oodpktlost) & 0xffff;
__raw_writeq(0, sc->sbm_rxdma.sbdma_oodpktlost);
while (work_to_do-- > 0) {
dsc = d->sbdma_remptr;
curidx = dsc - d->sbdma_dscrtable;
prefetch(dsc);
prefetch(&d->sbdma_ctxtable[curidx]);
hwidx = ((__raw_readq(d->sbdma_curdscr) & M_DMA_CURDSCR_ADDR) -
d->sbdma_dscrtable_phys) /
sizeof(*d->sbdma_dscrtable);
if (curidx == hwidx)
goto done;
sb = d->sbdma_ctxtable[curidx];
d->sbdma_ctxtable[curidx] = NULL;
len = (int)G_DMA_DSCRB_PKT_SIZE(dsc->dscr_b) - 4;
if (likely (!(dsc->dscr_a & M_DMA_ETHRX_BAD))) {
if (unlikely(sbdma_add_rcvbuffer(sc, d, NULL) ==
-ENOBUFS)) {
dev->stats.rx_dropped++;
sbdma_add_rcvbuffer(sc, d, sb);
printk(KERN_ERR "dropped packet (1)\n");
d->sbdma_remptr = SBDMA_NEXTBUF(d,sbdma_remptr);
goto done;
} else {
skb_put(sb,len);
sb->protocol = eth_type_trans(sb,d->sbdma_eth->sbm_dev);
if (sc->rx_hw_checksum == ENABLE) {
if (!((dsc->dscr_a) & M_DMA_ETHRX_BADIP4CS) &&
!((dsc->dscr_a) & M_DMA_ETHRX_BADTCPCS)) {
sb->ip_summed = CHECKSUM_UNNECESSARY;
} else {
skb_checksum_none_assert(sb);
}
}
prefetch(sb->data);
prefetch((const void *)(((char *)sb->data)+32));
if (poll)
dropped = netif_receive_skb(sb);
else
dropped = netif_rx(sb);
if (dropped == NET_RX_DROP) {
dev->stats.rx_dropped++;
d->sbdma_remptr = SBDMA_NEXTBUF(d,sbdma_remptr);
goto done;
}
else {
dev->stats.rx_bytes += len;
dev->stats.rx_packets++;
}
}
} else {
dev->stats.rx_errors++;
sbdma_add_rcvbuffer(sc, d, sb);
}
d->sbdma_remptr = SBDMA_NEXTBUF(d,sbdma_remptr);
work_done++;
}
if (!poll) {
work_to_do = 32;
goto again;
}
done:
return work_done;
}
static void sbdma_tx_process(struct sbmac_softc *sc, struct sbmacdma *d,
int poll)
{
struct net_device *dev = sc->sbm_dev;
int curidx;
int hwidx;
struct sbdmadscr *dsc;
struct sk_buff *sb;
unsigned long flags;
int packets_handled = 0;
spin_lock_irqsave(&(sc->sbm_lock), flags);
if (d->sbdma_remptr == d->sbdma_addptr)
goto end_unlock;
hwidx = ((__raw_readq(d->sbdma_curdscr) & M_DMA_CURDSCR_ADDR) -
d->sbdma_dscrtable_phys) / sizeof(*d->sbdma_dscrtable);
for (;;) {
curidx = d->sbdma_remptr - d->sbdma_dscrtable;
if (curidx == hwidx)
break;
dsc = &(d->sbdma_dscrtable[curidx]);
sb = d->sbdma_ctxtable[curidx];
d->sbdma_ctxtable[curidx] = NULL;
dev->stats.tx_bytes += sb->len;
dev->stats.tx_packets++;
dev_kfree_skb_irq(sb);
d->sbdma_remptr = SBDMA_NEXTBUF(d,sbdma_remptr);
packets_handled++;
}
if (packets_handled)
netif_wake_queue(d->sbdma_eth->sbm_dev);
end_unlock:
spin_unlock_irqrestore(&(sc->sbm_lock), flags);
}
static int sbmac_initctx(struct sbmac_softc *s)
{
s->sbm_macenable = s->sbm_base + R_MAC_ENABLE;
s->sbm_maccfg = s->sbm_base + R_MAC_CFG;
s->sbm_fifocfg = s->sbm_base + R_MAC_THRSH_CFG;
s->sbm_framecfg = s->sbm_base + R_MAC_FRAMECFG;
s->sbm_rxfilter = s->sbm_base + R_MAC_ADFILTER_CFG;
s->sbm_isr = s->sbm_base + R_MAC_STATUS;
s->sbm_imr = s->sbm_base + R_MAC_INT_MASK;
s->sbm_mdio = s->sbm_base + R_MAC_MDIO;
sbdma_initctx(&(s->sbm_txdma),s,0,DMA_TX,SBMAC_MAX_TXDESCR);
sbdma_initctx(&(s->sbm_rxdma),s,0,DMA_RX,SBMAC_MAX_RXDESCR);
s->sbm_state = sbmac_state_off;
return 0;
}
static void sbdma_uninitctx(struct sbmacdma *d)
{
if (d->sbdma_dscrtable_unaligned) {
kfree(d->sbdma_dscrtable_unaligned);
d->sbdma_dscrtable_unaligned = d->sbdma_dscrtable = NULL;
}
if (d->sbdma_ctxtable) {
kfree(d->sbdma_ctxtable);
d->sbdma_ctxtable = NULL;
}
}
static void sbmac_uninitctx(struct sbmac_softc *sc)
{
sbdma_uninitctx(&(sc->sbm_txdma));
sbdma_uninitctx(&(sc->sbm_rxdma));
}
static void sbmac_channel_start(struct sbmac_softc *s)
{
uint64_t reg;
void __iomem *port;
uint64_t cfg,fifo,framecfg;
int idx, th_value;
if (s->sbm_state == sbmac_state_on)
return;
__raw_writeq(0, s->sbm_macenable);
__raw_writeq(0, s->sbm_rxfilter);
cfg = M_MAC_RETRY_EN |
M_MAC_TX_HOLD_SOP_EN |
V_MAC_TX_PAUSE_CNT_16K |
M_MAC_AP_STAT_EN |
M_MAC_FAST_SYNC |
M_MAC_SS_EN |
0;
if (soc_type == K_SYS_SOC_TYPE_BCM1250 && periph_rev < 2)
th_value = 28;
else
th_value = 64;
fifo = V_MAC_TX_WR_THRSH(4) |
((s->sbm_speed == sbmac_speed_1000)
? V_MAC_TX_RD_THRSH(th_value) : V_MAC_TX_RD_THRSH(4)) |
V_MAC_TX_RL_THRSH(4) |
V_MAC_RX_PL_THRSH(4) |
V_MAC_RX_RD_THRSH(4) |
V_MAC_RX_RL_THRSH(8) |
0;
framecfg = V_MAC_MIN_FRAMESZ_DEFAULT |
V_MAC_MAX_FRAMESZ_DEFAULT |
V_MAC_BACKOFF_SEL(1);
port = s->sbm_base + R_MAC_HASH_BASE;
for (idx = 0; idx < MAC_HASH_COUNT; idx++) {
__raw_writeq(0, port);
port += sizeof(uint64_t);
}
port = s->sbm_base + R_MAC_ADDR_BASE;
for (idx = 0; idx < MAC_ADDR_COUNT; idx++) {
__raw_writeq(0, port);
port += sizeof(uint64_t);
}
port = s->sbm_base + R_MAC_CHUP0_BASE;
for (idx = 0; idx < MAC_CHMAP_COUNT; idx++) {
__raw_writeq(0, port);
port += sizeof(uint64_t);
}
port = s->sbm_base + R_MAC_CHLO0_BASE;
for (idx = 0; idx < MAC_CHMAP_COUNT; idx++) {
__raw_writeq(0, port);
port += sizeof(uint64_t);
}
reg = sbmac_addr2reg(s->sbm_hwaddr);
port = s->sbm_base + R_MAC_ADDR_BASE;
__raw_writeq(reg, port);
port = s->sbm_base + R_MAC_ETHERNET_ADDR;
__raw_writeq(reg, port);
__raw_writeq(0, s->sbm_rxfilter);
__raw_writeq(0, s->sbm_imr);
__raw_writeq(framecfg, s->sbm_framecfg);
__raw_writeq(fifo, s->sbm_fifocfg);
__raw_writeq(cfg, s->sbm_maccfg);
sbdma_channel_start(&(s->sbm_rxdma), DMA_RX);
sbdma_channel_start(&(s->sbm_txdma), DMA_TX);
sbmac_set_speed(s,s->sbm_speed);
sbmac_set_duplex(s,s->sbm_duplex,s->sbm_fc);
sbdma_fillring(s, &(s->sbm_rxdma));
#if defined(CONFIG_SIBYTE_BCM1x55) || defined(CONFIG_SIBYTE_BCM1x80)
__raw_writeq(M_MAC_RXDMA_EN0 |
M_MAC_TXDMA_EN0, s->sbm_macenable);
#elif defined(CONFIG_SIBYTE_SB1250) || defined(CONFIG_SIBYTE_BCM112X)
__raw_writeq(M_MAC_RXDMA_EN0 |
M_MAC_TXDMA_EN0 |
M_MAC_RX_ENABLE |
M_MAC_TX_ENABLE, s->sbm_macenable);
#else
#error invalid SiByte MAC configuration
#endif
#ifdef CONFIG_SBMAC_COALESCE
__raw_writeq(((M_MAC_INT_EOP_COUNT | M_MAC_INT_EOP_TIMER) << S_MAC_TX_CH0) |
((M_MAC_INT_EOP_COUNT | M_MAC_INT_EOP_TIMER) << S_MAC_RX_CH0), s->sbm_imr);
#else
__raw_writeq((M_MAC_INT_CHANNEL << S_MAC_TX_CH0) |
(M_MAC_INT_CHANNEL << S_MAC_RX_CH0), s->sbm_imr);
#endif
__raw_writeq(M_MAC_UCAST_EN | M_MAC_BCAST_EN, s->sbm_rxfilter);
s->sbm_state = sbmac_state_on;
sbmac_setmulti(s);
if (s->sbm_devflags & IFF_PROMISC) {
sbmac_promiscuous_mode(s,1);
}
}
static void sbmac_channel_stop(struct sbmac_softc *s)
{
if (s->sbm_state == sbmac_state_off)
return;
__raw_writeq(0, s->sbm_rxfilter);
__raw_writeq(0, s->sbm_imr);
__raw_writeq(0, s->sbm_macenable);
s->sbm_state = sbmac_state_off;
sbdma_channel_stop(&(s->sbm_rxdma));
sbdma_channel_stop(&(s->sbm_txdma));
sbdma_emptyring(&(s->sbm_rxdma));
sbdma_emptyring(&(s->sbm_txdma));
}
static enum sbmac_state sbmac_set_channel_state(struct sbmac_softc *sc,
enum sbmac_state state)
{
enum sbmac_state oldstate = sc->sbm_state;
if (state == oldstate) {
return oldstate;
}
if (state == sbmac_state_on) {
sbmac_channel_start(sc);
}
else {
sbmac_channel_stop(sc);
}
return oldstate;
}
static void sbmac_promiscuous_mode(struct sbmac_softc *sc,int onoff)
{
uint64_t reg;
if (sc->sbm_state != sbmac_state_on)
return;
if (onoff) {
reg = __raw_readq(sc->sbm_rxfilter);
reg |= M_MAC_ALLPKT_EN;
__raw_writeq(reg, sc->sbm_rxfilter);
}
else {
reg = __raw_readq(sc->sbm_rxfilter);
reg &= ~M_MAC_ALLPKT_EN;
__raw_writeq(reg, sc->sbm_rxfilter);
}
}
static void sbmac_set_iphdr_offset(struct sbmac_softc *sc)
{
uint64_t reg;
reg = __raw_readq(sc->sbm_rxfilter);
reg &= ~M_MAC_IPHDR_OFFSET | V_MAC_IPHDR_OFFSET(15);
__raw_writeq(reg, sc->sbm_rxfilter);
if (soc_type == K_SYS_SOC_TYPE_BCM1250 && periph_rev < 2) {
sc->rx_hw_checksum = DISABLE;
} else {
sc->rx_hw_checksum = ENABLE;
}
}
static uint64_t sbmac_addr2reg(unsigned char *ptr)
{
uint64_t reg = 0;
ptr += 6;
reg |= (uint64_t) *(--ptr);
reg <<= 8;
reg |= (uint64_t) *(--ptr);
reg <<= 8;
reg |= (uint64_t) *(--ptr);
reg <<= 8;
reg |= (uint64_t) *(--ptr);
reg <<= 8;
reg |= (uint64_t) *(--ptr);
reg <<= 8;
reg |= (uint64_t) *(--ptr);
return reg;
}
static int sbmac_set_speed(struct sbmac_softc *s, enum sbmac_speed speed)
{
uint64_t cfg;
uint64_t framecfg;
s->sbm_speed = speed;
if (s->sbm_state == sbmac_state_on)
return 0;
cfg = __raw_readq(s->sbm_maccfg);
framecfg = __raw_readq(s->sbm_framecfg);
cfg &= ~(M_MAC_BURST_EN | M_MAC_SPEED_SEL);
framecfg &= ~(M_MAC_IFG_RX | M_MAC_IFG_TX | M_MAC_IFG_THRSH |
M_MAC_SLOT_SIZE);
switch (speed) {
case sbmac_speed_10:
framecfg |= V_MAC_IFG_RX_10 |
V_MAC_IFG_TX_10 |
K_MAC_IFG_THRSH_10 |
V_MAC_SLOT_SIZE_10;
cfg |= V_MAC_SPEED_SEL_10MBPS;
break;
case sbmac_speed_100:
framecfg |= V_MAC_IFG_RX_100 |
V_MAC_IFG_TX_100 |
V_MAC_IFG_THRSH_100 |
V_MAC_SLOT_SIZE_100;
cfg |= V_MAC_SPEED_SEL_100MBPS ;
break;
case sbmac_speed_1000:
framecfg |= V_MAC_IFG_RX_1000 |
V_MAC_IFG_TX_1000 |
V_MAC_IFG_THRSH_1000 |
V_MAC_SLOT_SIZE_1000;
cfg |= V_MAC_SPEED_SEL_1000MBPS | M_MAC_BURST_EN;
break;
default:
return 0;
}
__raw_writeq(framecfg, s->sbm_framecfg);
__raw_writeq(cfg, s->sbm_maccfg);
return 1;
}
static int sbmac_set_duplex(struct sbmac_softc *s, enum sbmac_duplex duplex,
enum sbmac_fc fc)
{
uint64_t cfg;
s->sbm_duplex = duplex;
s->sbm_fc = fc;
if (s->sbm_state == sbmac_state_on)
return 0;
cfg = __raw_readq(s->sbm_maccfg);
cfg &= ~(M_MAC_FC_SEL | M_MAC_FC_CMD | M_MAC_HDX_EN);
switch (duplex) {
case sbmac_duplex_half:
switch (fc) {
case sbmac_fc_disabled:
cfg |= M_MAC_HDX_EN | V_MAC_FC_CMD_DISABLED;
break;
case sbmac_fc_collision:
cfg |= M_MAC_HDX_EN | V_MAC_FC_CMD_ENABLED;
break;
case sbmac_fc_carrier:
cfg |= M_MAC_HDX_EN | V_MAC_FC_CMD_ENAB_FALSECARR;
break;
case sbmac_fc_frame:
default:
return 0;
}
break;
case sbmac_duplex_full:
switch (fc) {
case sbmac_fc_disabled:
cfg |= V_MAC_FC_CMD_DISABLED;
break;
case sbmac_fc_frame:
cfg |= V_MAC_FC_CMD_ENABLED;
break;
case sbmac_fc_collision:
case sbmac_fc_carrier:
default:
return 0;
}
break;
default:
return 0;
}
__raw_writeq(cfg, s->sbm_maccfg);
return 1;
}
static irqreturn_t sbmac_intr(int irq,void *dev_instance)
{
struct net_device *dev = (struct net_device *) dev_instance;
struct sbmac_softc *sc = netdev_priv(dev);
uint64_t isr;
int handled = 0;
isr = __raw_readq(sc->sbm_isr) & ~M_MAC_COUNTER_ADDR;
if (isr == 0)
return IRQ_RETVAL(0);
handled = 1;
if (isr & (M_MAC_INT_CHANNEL << S_MAC_TX_CH0))
sbdma_tx_process(sc,&(sc->sbm_txdma), 0);
if (isr & (M_MAC_INT_CHANNEL << S_MAC_RX_CH0)) {
if (napi_schedule_prep(&sc->napi)) {
__raw_writeq(0, sc->sbm_imr);
__napi_schedule(&sc->napi);
}
else {
sbdma_rx_process(sc,&(sc->sbm_rxdma),
SBMAC_MAX_RXDESCR * 2, 0);
}
}
return IRQ_RETVAL(handled);
}
static int sbmac_start_tx(struct sk_buff *skb, struct net_device *dev)
{
struct sbmac_softc *sc = netdev_priv(dev);
unsigned long flags;
spin_lock_irqsave(&sc->sbm_lock, flags);
if (sbdma_add_txbuffer(&(sc->sbm_txdma),skb)) {
netif_stop_queue(dev);
spin_unlock_irqrestore(&sc->sbm_lock, flags);
return NETDEV_TX_BUSY;
}
spin_unlock_irqrestore(&sc->sbm_lock, flags);
return NETDEV_TX_OK;
}
static void sbmac_setmulti(struct sbmac_softc *sc)
{
uint64_t reg;
void __iomem *port;
int idx;
struct netdev_hw_addr *ha;
struct net_device *dev = sc->sbm_dev;
for (idx = 1; idx < MAC_ADDR_COUNT; idx++) {
port = sc->sbm_base + R_MAC_ADDR_BASE+(idx*sizeof(uint64_t));
__raw_writeq(0, port);
}
for (idx = 0; idx < MAC_HASH_COUNT; idx++) {
port = sc->sbm_base + R_MAC_HASH_BASE+(idx*sizeof(uint64_t));
__raw_writeq(0, port);
}
reg = __raw_readq(sc->sbm_rxfilter);
reg &= ~(M_MAC_MCAST_INV | M_MAC_MCAST_EN);
__raw_writeq(reg, sc->sbm_rxfilter);
if (dev->flags & IFF_ALLMULTI) {
reg = __raw_readq(sc->sbm_rxfilter);
reg |= (M_MAC_MCAST_INV | M_MAC_MCAST_EN);
__raw_writeq(reg, sc->sbm_rxfilter);
return;
}
idx = 1;
netdev_for_each_mc_addr(ha, dev) {
if (idx == MAC_ADDR_COUNT)
break;
reg = sbmac_addr2reg(ha->addr);
port = sc->sbm_base + R_MAC_ADDR_BASE+(idx * sizeof(uint64_t));
__raw_writeq(reg, port);
idx++;
}
if (idx > 1) {
reg = __raw_readq(sc->sbm_rxfilter);
reg |= M_MAC_MCAST_EN;
__raw_writeq(reg, sc->sbm_rxfilter);
}
}
static int sb1250_change_mtu(struct net_device *_dev, int new_mtu)
{
if (new_mtu > ENET_PACKET_SIZE)
return -EINVAL;
_dev->mtu = new_mtu;
pr_info("changing the mtu to %d\n", new_mtu);
return 0;
}
static int sbmac_init(struct platform_device *pldev, long long base)
{
struct net_device *dev = platform_get_drvdata(pldev);
int idx = pldev->id;
struct sbmac_softc *sc = netdev_priv(dev);
unsigned char *eaddr;
uint64_t ea_reg;
int i;
int err;
sc->sbm_dev = dev;
sc->sbe_idx = idx;
eaddr = sc->sbm_hwaddr;
ea_reg = __raw_readq(sc->sbm_base + R_MAC_ETHERNET_ADDR);
__raw_writeq(0, sc->sbm_base + R_MAC_ETHERNET_ADDR);
for (i = 0; i < 6; i++) {
eaddr[i] = (uint8_t) (ea_reg & 0xFF);
ea_reg >>= 8;
}
for (i = 0; i < 6; i++) {
dev->dev_addr[i] = eaddr[i];
}
sbmac_initctx(sc);
spin_lock_init(&(sc->sbm_lock));
dev->netdev_ops = &sbmac_netdev_ops;
dev->watchdog_timeo = TX_TIMEOUT;
netif_napi_add(dev, &sc->napi, sbmac_poll, 16);
dev->irq = UNIT_INT(idx);
sbmac_set_iphdr_offset(sc);
sc->mii_bus = mdiobus_alloc();
if (sc->mii_bus == NULL) {
err = -ENOMEM;
goto uninit_ctx;
}
sc->mii_bus->name = sbmac_mdio_string;
snprintf(sc->mii_bus->id, MII_BUS_ID_SIZE, "%s-%x",
pldev->name, idx);
sc->mii_bus->priv = sc;
sc->mii_bus->read = sbmac_mii_read;
sc->mii_bus->write = sbmac_mii_write;
sc->mii_bus->parent = &pldev->dev;
err = mdiobus_register(sc->mii_bus);
if (err) {
printk(KERN_ERR "%s: unable to register MDIO bus\n",
dev->name);
goto free_mdio;
}
platform_set_drvdata(pldev, sc->mii_bus);
err = register_netdev(dev);
if (err) {
printk(KERN_ERR "%s.%d: unable to register netdev\n",
sbmac_string, idx);
goto unreg_mdio;
}
pr_info("%s.%d: registered as %s\n", sbmac_string, idx, dev->name);
if (sc->rx_hw_checksum == ENABLE)
pr_info("%s: enabling TCP rcv checksum\n", dev->name);
pr_info("%s: SiByte Ethernet at 0x%08Lx, address: %pM\n",
dev->name, base, eaddr);
return 0;
unreg_mdio:
mdiobus_unregister(sc->mii_bus);
free_mdio:
mdiobus_free(sc->mii_bus);
uninit_ctx:
sbmac_uninitctx(sc);
return err;
}
static int sbmac_open(struct net_device *dev)
{
struct sbmac_softc *sc = netdev_priv(dev);
int err;
if (debug > 1)
pr_debug("%s: sbmac_open() irq %d.\n", dev->name, dev->irq);
__raw_readq(sc->sbm_isr);
err = request_irq(dev->irq, sbmac_intr, IRQF_SHARED, dev->name, dev);
if (err) {
printk(KERN_ERR "%s: unable to get IRQ %d\n", dev->name,
dev->irq);
goto out_err;
}
sc->sbm_speed = sbmac_speed_none;
sc->sbm_duplex = sbmac_duplex_none;
sc->sbm_fc = sbmac_fc_none;
sc->sbm_pause = -1;
sc->sbm_link = 0;
err = sbmac_mii_probe(dev);
if (err)
goto out_unregister;
sbmac_set_channel_state(sc,sbmac_state_on);
netif_start_queue(dev);
sbmac_set_rx_mode(dev);
phy_start(sc->phy_dev);
napi_enable(&sc->napi);
return 0;
out_unregister:
free_irq(dev->irq, dev);
out_err:
return err;
}
static int sbmac_mii_probe(struct net_device *dev)
{
struct sbmac_softc *sc = netdev_priv(dev);
struct phy_device *phy_dev;
phy_dev = phy_find_first(sc->mii_bus);
if (!phy_dev) {
printk(KERN_ERR "%s: no PHY found\n", dev->name);
return -ENXIO;
}
phy_dev = phy_connect(dev, dev_name(&phy_dev->mdio.dev),
&sbmac_mii_poll, PHY_INTERFACE_MODE_GMII);
if (IS_ERR(phy_dev)) {
printk(KERN_ERR "%s: could not attach to PHY\n", dev->name);
return PTR_ERR(phy_dev);
}
phy_dev->supported &= SUPPORTED_10baseT_Half |
SUPPORTED_10baseT_Full |
SUPPORTED_100baseT_Half |
SUPPORTED_100baseT_Full |
SUPPORTED_1000baseT_Half |
SUPPORTED_1000baseT_Full |
SUPPORTED_Autoneg |
SUPPORTED_MII |
SUPPORTED_Pause |
SUPPORTED_Asym_Pause;
phy_attached_info(phy_dev);
phy_dev->advertising = phy_dev->supported;
sc->phy_dev = phy_dev;
return 0;
}
static void sbmac_mii_poll(struct net_device *dev)
{
struct sbmac_softc *sc = netdev_priv(dev);
struct phy_device *phy_dev = sc->phy_dev;
unsigned long flags;
enum sbmac_fc fc;
int link_chg, speed_chg, duplex_chg, pause_chg, fc_chg;
link_chg = (sc->sbm_link != phy_dev->link);
speed_chg = (sc->sbm_speed != phy_dev->speed);
duplex_chg = (sc->sbm_duplex != phy_dev->duplex);
pause_chg = (sc->sbm_pause != phy_dev->pause);
if (!link_chg && !speed_chg && !duplex_chg && !pause_chg)
return;
if (!phy_dev->link) {
if (link_chg) {
sc->sbm_link = phy_dev->link;
sc->sbm_speed = sbmac_speed_none;
sc->sbm_duplex = sbmac_duplex_none;
sc->sbm_fc = sbmac_fc_disabled;
sc->sbm_pause = -1;
pr_info("%s: link unavailable\n", dev->name);
}
return;
}
if (phy_dev->duplex == DUPLEX_FULL) {
if (phy_dev->pause)
fc = sbmac_fc_frame;
else
fc = sbmac_fc_disabled;
} else
fc = sbmac_fc_collision;
fc_chg = (sc->sbm_fc != fc);
pr_info("%s: link available: %dbase-%cD\n", dev->name, phy_dev->speed,
phy_dev->duplex == DUPLEX_FULL ? 'F' : 'H');
spin_lock_irqsave(&sc->sbm_lock, flags);
sc->sbm_speed = phy_dev->speed;
sc->sbm_duplex = phy_dev->duplex;
sc->sbm_fc = fc;
sc->sbm_pause = phy_dev->pause;
sc->sbm_link = phy_dev->link;
if ((speed_chg || duplex_chg || fc_chg) &&
sc->sbm_state != sbmac_state_off) {
if (debug > 1)
pr_debug("%s: restarting channel "
"because PHY state changed\n", dev->name);
sbmac_channel_stop(sc);
sbmac_channel_start(sc);
}
spin_unlock_irqrestore(&sc->sbm_lock, flags);
}
static void sbmac_tx_timeout (struct net_device *dev)
{
struct sbmac_softc *sc = netdev_priv(dev);
unsigned long flags;
spin_lock_irqsave(&sc->sbm_lock, flags);
netif_trans_update(dev);
dev->stats.tx_errors++;
spin_unlock_irqrestore(&sc->sbm_lock, flags);
printk (KERN_WARNING "%s: Transmit timed out\n",dev->name);
}
static void sbmac_set_rx_mode(struct net_device *dev)
{
unsigned long flags;
struct sbmac_softc *sc = netdev_priv(dev);
spin_lock_irqsave(&sc->sbm_lock, flags);
if ((dev->flags ^ sc->sbm_devflags) & IFF_PROMISC) {
if (dev->flags & IFF_PROMISC) {
sbmac_promiscuous_mode(sc,1);
}
else {
sbmac_promiscuous_mode(sc,0);
}
}
spin_unlock_irqrestore(&sc->sbm_lock, flags);
sbmac_setmulti(sc);
}
static int sbmac_mii_ioctl(struct net_device *dev, struct ifreq *rq, int cmd)
{
struct sbmac_softc *sc = netdev_priv(dev);
if (!netif_running(dev) || !sc->phy_dev)
return -EINVAL;
return phy_mii_ioctl(sc->phy_dev, rq, cmd);
}
static int sbmac_close(struct net_device *dev)
{
struct sbmac_softc *sc = netdev_priv(dev);
napi_disable(&sc->napi);
phy_stop(sc->phy_dev);
sbmac_set_channel_state(sc, sbmac_state_off);
netif_stop_queue(dev);
if (debug > 1)
pr_debug("%s: Shutting down ethercard\n", dev->name);
phy_disconnect(sc->phy_dev);
sc->phy_dev = NULL;
free_irq(dev->irq, dev);
sbdma_emptyring(&(sc->sbm_txdma));
sbdma_emptyring(&(sc->sbm_rxdma));
return 0;
}
static int sbmac_poll(struct napi_struct *napi, int budget)
{
struct sbmac_softc *sc = container_of(napi, struct sbmac_softc, napi);
int work_done;
work_done = sbdma_rx_process(sc, &(sc->sbm_rxdma), budget, 1);
sbdma_tx_process(sc, &(sc->sbm_txdma), 1);
if (work_done < budget) {
napi_complete(napi);
#ifdef CONFIG_SBMAC_COALESCE
__raw_writeq(((M_MAC_INT_EOP_COUNT | M_MAC_INT_EOP_TIMER) << S_MAC_TX_CH0) |
((M_MAC_INT_EOP_COUNT | M_MAC_INT_EOP_TIMER) << S_MAC_RX_CH0),
sc->sbm_imr);
#else
__raw_writeq((M_MAC_INT_CHANNEL << S_MAC_TX_CH0) |
(M_MAC_INT_CHANNEL << S_MAC_RX_CH0), sc->sbm_imr);
#endif
}
return work_done;
}
static int sbmac_probe(struct platform_device *pldev)
{
struct net_device *dev;
struct sbmac_softc *sc;
void __iomem *sbm_base;
struct resource *res;
u64 sbmac_orig_hwaddr;
int err;
res = platform_get_resource(pldev, IORESOURCE_MEM, 0);
BUG_ON(!res);
sbm_base = ioremap_nocache(res->start, resource_size(res));
if (!sbm_base) {
printk(KERN_ERR "%s: unable to map device registers\n",
dev_name(&pldev->dev));
err = -ENOMEM;
goto out_out;
}
sbmac_orig_hwaddr = __raw_readq(sbm_base + R_MAC_ETHERNET_ADDR);
pr_debug("%s: %sconfiguring MAC at 0x%08Lx\n", dev_name(&pldev->dev),
sbmac_orig_hwaddr ? "" : "not ", (long long)res->start);
if (sbmac_orig_hwaddr == 0) {
err = 0;
goto out_unmap;
}
dev = alloc_etherdev(sizeof(struct sbmac_softc));
if (!dev) {
err = -ENOMEM;
goto out_unmap;
}
platform_set_drvdata(pldev, dev);
SET_NETDEV_DEV(dev, &pldev->dev);
sc = netdev_priv(dev);
sc->sbm_base = sbm_base;
err = sbmac_init(pldev, res->start);
if (err)
goto out_kfree;
return 0;
out_kfree:
free_netdev(dev);
__raw_writeq(sbmac_orig_hwaddr, sbm_base + R_MAC_ETHERNET_ADDR);
out_unmap:
iounmap(sbm_base);
out_out:
return err;
}
static int __exit sbmac_remove(struct platform_device *pldev)
{
struct net_device *dev = platform_get_drvdata(pldev);
struct sbmac_softc *sc = netdev_priv(dev);
unregister_netdev(dev);
sbmac_uninitctx(sc);
mdiobus_unregister(sc->mii_bus);
mdiobus_free(sc->mii_bus);
iounmap(sc->sbm_base);
free_netdev(dev);
return 0;
}
