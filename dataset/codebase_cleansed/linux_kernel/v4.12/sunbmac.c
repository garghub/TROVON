static int qec_global_reset(void __iomem *gregs)
{
int tries = QEC_RESET_TRIES;
sbus_writel(GLOB_CTRL_RESET, gregs + GLOB_CTRL);
while (--tries) {
if (sbus_readl(gregs + GLOB_CTRL) & GLOB_CTRL_RESET) {
udelay(20);
continue;
}
break;
}
if (tries)
return 0;
printk(KERN_ERR "BigMAC: Cannot reset the QEC.\n");
return -1;
}
static void qec_init(struct bigmac *bp)
{
struct platform_device *qec_op = bp->qec_op;
void __iomem *gregs = bp->gregs;
u8 bsizes = bp->bigmac_bursts;
u32 regval;
if (bsizes & DMA_BURST32)
regval = GLOB_CTRL_B32;
else
regval = GLOB_CTRL_B16;
sbus_writel(regval | GLOB_CTRL_BMODE, gregs + GLOB_CTRL);
sbus_writel(GLOB_PSIZE_2048, gregs + GLOB_PSIZE);
sbus_writel(resource_size(&qec_op->resource[1]),
gregs + GLOB_MSIZE);
sbus_writel(resource_size(&qec_op->resource[1]) >> 1,
gregs + GLOB_TSIZE);
sbus_writel(resource_size(&qec_op->resource[1]) >> 1,
gregs + GLOB_RSIZE);
}
static void bigmac_tx_reset(void __iomem *bregs)
{
int tries = TX_RESET_TRIES;
sbus_writel(0, bregs + BMAC_TXCFG);
while ((sbus_readl(bregs + BMAC_TXCFG) & ~(BIGMAC_TXCFG_FIFO)) != 0 &&
--tries != 0)
udelay(20);
if (!tries) {
printk(KERN_ERR "BIGMAC: Transmitter will not reset.\n");
printk(KERN_ERR "BIGMAC: tx_cfg is %08x\n",
sbus_readl(bregs + BMAC_TXCFG));
}
}
static void bigmac_rx_reset(void __iomem *bregs)
{
int tries = RX_RESET_TRIES;
sbus_writel(0, bregs + BMAC_RXCFG);
while (sbus_readl(bregs + BMAC_RXCFG) && --tries)
udelay(20);
if (!tries) {
printk(KERN_ERR "BIGMAC: Receiver will not reset.\n");
printk(KERN_ERR "BIGMAC: rx_cfg is %08x\n",
sbus_readl(bregs + BMAC_RXCFG));
}
}
static void bigmac_stop(struct bigmac *bp)
{
bigmac_tx_reset(bp->bregs);
bigmac_rx_reset(bp->bregs);
}
static void bigmac_get_counters(struct bigmac *bp, void __iomem *bregs)
{
struct net_device_stats *stats = &bp->dev->stats;
stats->rx_crc_errors += sbus_readl(bregs + BMAC_RCRCECTR);
sbus_writel(0, bregs + BMAC_RCRCECTR);
stats->rx_frame_errors += sbus_readl(bregs + BMAC_UNALECTR);
sbus_writel(0, bregs + BMAC_UNALECTR);
stats->rx_length_errors += sbus_readl(bregs + BMAC_GLECTR);
sbus_writel(0, bregs + BMAC_GLECTR);
stats->tx_aborted_errors += sbus_readl(bregs + BMAC_EXCTR);
stats->collisions +=
(sbus_readl(bregs + BMAC_EXCTR) +
sbus_readl(bregs + BMAC_LTCTR));
sbus_writel(0, bregs + BMAC_EXCTR);
sbus_writel(0, bregs + BMAC_LTCTR);
}
static void bigmac_clean_rings(struct bigmac *bp)
{
int i;
for (i = 0; i < RX_RING_SIZE; i++) {
if (bp->rx_skbs[i] != NULL) {
dev_kfree_skb_any(bp->rx_skbs[i]);
bp->rx_skbs[i] = NULL;
}
}
for (i = 0; i < TX_RING_SIZE; i++) {
if (bp->tx_skbs[i] != NULL) {
dev_kfree_skb_any(bp->tx_skbs[i]);
bp->tx_skbs[i] = NULL;
}
}
}
static void bigmac_init_rings(struct bigmac *bp, int from_irq)
{
struct bmac_init_block *bb = bp->bmac_block;
int i;
gfp_t gfp_flags = GFP_KERNEL;
if (from_irq || in_interrupt())
gfp_flags = GFP_ATOMIC;
bp->rx_new = bp->rx_old = bp->tx_new = bp->tx_old = 0;
bigmac_clean_rings(bp);
for (i = 0; i < RX_RING_SIZE; i++) {
struct sk_buff *skb;
skb = big_mac_alloc_skb(RX_BUF_ALLOC_SIZE, gfp_flags);
if (!skb)
continue;
bp->rx_skbs[i] = skb;
skb_put(skb, ETH_FRAME_LEN);
skb_reserve(skb, 34);
bb->be_rxd[i].rx_addr =
dma_map_single(&bp->bigmac_op->dev,
skb->data,
RX_BUF_ALLOC_SIZE - 34,
DMA_FROM_DEVICE);
bb->be_rxd[i].rx_flags =
(RXD_OWN | ((RX_BUF_ALLOC_SIZE - 34) & RXD_LENGTH));
}
for (i = 0; i < TX_RING_SIZE; i++)
bb->be_txd[i].tx_flags = bb->be_txd[i].tx_addr = 0;
}
static void idle_transceiver(void __iomem *tregs)
{
int i = 20;
while (i--) {
sbus_writel(MGMT_CLKOFF, tregs + TCVR_MPAL);
sbus_readl(tregs + TCVR_MPAL);
sbus_writel(MGMT_CLKON, tregs + TCVR_MPAL);
sbus_readl(tregs + TCVR_MPAL);
}
}
static void write_tcvr_bit(struct bigmac *bp, void __iomem *tregs, int bit)
{
if (bp->tcvr_type == internal) {
bit = (bit & 1) << 3;
sbus_writel(bit | (MGMT_PAL_OENAB | MGMT_PAL_EXT_MDIO),
tregs + TCVR_MPAL);
sbus_readl(tregs + TCVR_MPAL);
sbus_writel(bit | MGMT_PAL_OENAB | MGMT_PAL_EXT_MDIO | MGMT_PAL_DCLOCK,
tregs + TCVR_MPAL);
sbus_readl(tregs + TCVR_MPAL);
} else if (bp->tcvr_type == external) {
bit = (bit & 1) << 2;
sbus_writel(bit | MGMT_PAL_INT_MDIO | MGMT_PAL_OENAB,
tregs + TCVR_MPAL);
sbus_readl(tregs + TCVR_MPAL);
sbus_writel(bit | MGMT_PAL_INT_MDIO | MGMT_PAL_OENAB | MGMT_PAL_DCLOCK,
tregs + TCVR_MPAL);
sbus_readl(tregs + TCVR_MPAL);
} else {
printk(KERN_ERR "write_tcvr_bit: No transceiver type known!\n");
}
}
static int read_tcvr_bit(struct bigmac *bp, void __iomem *tregs)
{
int retval = 0;
if (bp->tcvr_type == internal) {
sbus_writel(MGMT_PAL_EXT_MDIO, tregs + TCVR_MPAL);
sbus_readl(tregs + TCVR_MPAL);
sbus_writel(MGMT_PAL_EXT_MDIO | MGMT_PAL_DCLOCK,
tregs + TCVR_MPAL);
sbus_readl(tregs + TCVR_MPAL);
retval = (sbus_readl(tregs + TCVR_MPAL) & MGMT_PAL_INT_MDIO) >> 3;
} else if (bp->tcvr_type == external) {
sbus_writel(MGMT_PAL_INT_MDIO, tregs + TCVR_MPAL);
sbus_readl(tregs + TCVR_MPAL);
sbus_writel(MGMT_PAL_INT_MDIO | MGMT_PAL_DCLOCK, tregs + TCVR_MPAL);
sbus_readl(tregs + TCVR_MPAL);
retval = (sbus_readl(tregs + TCVR_MPAL) & MGMT_PAL_EXT_MDIO) >> 2;
} else {
printk(KERN_ERR "read_tcvr_bit: No transceiver type known!\n");
}
return retval;
}
static int read_tcvr_bit2(struct bigmac *bp, void __iomem *tregs)
{
int retval = 0;
if (bp->tcvr_type == internal) {
sbus_writel(MGMT_PAL_EXT_MDIO, tregs + TCVR_MPAL);
sbus_readl(tregs + TCVR_MPAL);
retval = (sbus_readl(tregs + TCVR_MPAL) & MGMT_PAL_INT_MDIO) >> 3;
sbus_writel(MGMT_PAL_EXT_MDIO | MGMT_PAL_DCLOCK, tregs + TCVR_MPAL);
sbus_readl(tregs + TCVR_MPAL);
} else if (bp->tcvr_type == external) {
sbus_writel(MGMT_PAL_INT_MDIO, tregs + TCVR_MPAL);
sbus_readl(tregs + TCVR_MPAL);
retval = (sbus_readl(tregs + TCVR_MPAL) & MGMT_PAL_EXT_MDIO) >> 2;
sbus_writel(MGMT_PAL_INT_MDIO | MGMT_PAL_DCLOCK, tregs + TCVR_MPAL);
sbus_readl(tregs + TCVR_MPAL);
} else {
printk(KERN_ERR "read_tcvr_bit2: No transceiver type known!\n");
}
return retval;
}
static void put_tcvr_byte(struct bigmac *bp,
void __iomem *tregs,
unsigned int byte)
{
int shift = 4;
do {
write_tcvr_bit(bp, tregs, ((byte >> shift) & 1));
shift -= 1;
} while (shift >= 0);
}
static void bigmac_tcvr_write(struct bigmac *bp, void __iomem *tregs,
int reg, unsigned short val)
{
int shift;
reg &= 0xff;
val &= 0xffff;
switch(bp->tcvr_type) {
case internal:
case external:
break;
default:
printk(KERN_ERR "bigmac_tcvr_read: Whoops, no known transceiver type.\n");
return;
}
idle_transceiver(tregs);
write_tcvr_bit(bp, tregs, 0);
write_tcvr_bit(bp, tregs, 1);
write_tcvr_bit(bp, tregs, 0);
write_tcvr_bit(bp, tregs, 1);
put_tcvr_byte(bp, tregs,
((bp->tcvr_type == internal) ?
BIGMAC_PHY_INTERNAL : BIGMAC_PHY_EXTERNAL));
put_tcvr_byte(bp, tregs, reg);
write_tcvr_bit(bp, tregs, 1);
write_tcvr_bit(bp, tregs, 0);
shift = 15;
do {
write_tcvr_bit(bp, tregs, (val >> shift) & 1);
shift -= 1;
} while (shift >= 0);
}
static unsigned short bigmac_tcvr_read(struct bigmac *bp,
void __iomem *tregs,
int reg)
{
unsigned short retval = 0;
reg &= 0xff;
switch(bp->tcvr_type) {
case internal:
case external:
break;
default:
printk(KERN_ERR "bigmac_tcvr_read: Whoops, no known transceiver type.\n");
return 0xffff;
}
idle_transceiver(tregs);
write_tcvr_bit(bp, tregs, 0);
write_tcvr_bit(bp, tregs, 1);
write_tcvr_bit(bp, tregs, 1);
write_tcvr_bit(bp, tregs, 0);
put_tcvr_byte(bp, tregs,
((bp->tcvr_type == internal) ?
BIGMAC_PHY_INTERNAL : BIGMAC_PHY_EXTERNAL));
put_tcvr_byte(bp, tregs, reg);
if (bp->tcvr_type == external) {
int shift = 15;
(void) read_tcvr_bit2(bp, tregs);
(void) read_tcvr_bit2(bp, tregs);
do {
int tmp;
tmp = read_tcvr_bit2(bp, tregs);
retval |= ((tmp & 1) << shift);
shift -= 1;
} while (shift >= 0);
(void) read_tcvr_bit2(bp, tregs);
(void) read_tcvr_bit2(bp, tregs);
(void) read_tcvr_bit2(bp, tregs);
} else {
int shift = 15;
(void) read_tcvr_bit(bp, tregs);
(void) read_tcvr_bit(bp, tregs);
do {
int tmp;
tmp = read_tcvr_bit(bp, tregs);
retval |= ((tmp & 1) << shift);
shift -= 1;
} while (shift >= 0);
(void) read_tcvr_bit(bp, tregs);
(void) read_tcvr_bit(bp, tregs);
(void) read_tcvr_bit(bp, tregs);
}
return retval;
}
static void bigmac_tcvr_init(struct bigmac *bp)
{
void __iomem *tregs = bp->tregs;
u32 mpal;
idle_transceiver(tregs);
sbus_writel(MGMT_PAL_INT_MDIO | MGMT_PAL_EXT_MDIO | MGMT_PAL_DCLOCK,
tregs + TCVR_MPAL);
sbus_readl(tregs + TCVR_MPAL);
sbus_writel(MGMT_PAL_INT_MDIO | MGMT_PAL_EXT_MDIO, tregs + TCVR_MPAL);
sbus_readl(tregs + TCVR_MPAL);
udelay(20);
mpal = sbus_readl(tregs + TCVR_MPAL);
if (mpal & MGMT_PAL_EXT_MDIO) {
bp->tcvr_type = external;
sbus_writel(~(TCVR_PAL_EXTLBACK | TCVR_PAL_MSENSE | TCVR_PAL_LTENABLE),
tregs + TCVR_TPAL);
sbus_readl(tregs + TCVR_TPAL);
} else if (mpal & MGMT_PAL_INT_MDIO) {
bp->tcvr_type = internal;
sbus_writel(~(TCVR_PAL_SERIAL | TCVR_PAL_EXTLBACK |
TCVR_PAL_MSENSE | TCVR_PAL_LTENABLE),
tregs + TCVR_TPAL);
sbus_readl(tregs + TCVR_TPAL);
} else {
printk(KERN_ERR "BIGMAC: AIEEE, neither internal nor "
"external MDIO available!\n");
printk(KERN_ERR "BIGMAC: mgmt_pal[%08x] tcvr_pal[%08x]\n",
sbus_readl(tregs + TCVR_MPAL),
sbus_readl(tregs + TCVR_TPAL));
}
}
static int try_next_permutation(struct bigmac *bp, void __iomem *tregs)
{
if (bp->sw_bmcr & BMCR_SPEED100) {
int timeout;
bp->sw_bmcr = (BMCR_ISOLATE | BMCR_PDOWN | BMCR_LOOPBACK);
bigmac_tcvr_write(bp, tregs, MII_BMCR, bp->sw_bmcr);
bp->sw_bmcr = (BMCR_RESET);
bigmac_tcvr_write(bp, tregs, MII_BMCR, bp->sw_bmcr);
timeout = 64;
while (--timeout) {
bp->sw_bmcr = bigmac_tcvr_read(bp, tregs, MII_BMCR);
if ((bp->sw_bmcr & BMCR_RESET) == 0)
break;
udelay(20);
}
if (timeout == 0)
printk(KERN_ERR "%s: PHY reset failed.\n", bp->dev->name);
bp->sw_bmcr = bigmac_tcvr_read(bp, tregs, MII_BMCR);
bp->sw_bmcr &= ~(BMCR_SPEED100);
bigmac_tcvr_write(bp, tregs, MII_BMCR, bp->sw_bmcr);
return 0;
}
return -1;
}
static void bigmac_timer(unsigned long data)
{
struct bigmac *bp = (struct bigmac *) data;
void __iomem *tregs = bp->tregs;
int restart_timer = 0;
bp->timer_ticks++;
if (bp->timer_state == ltrywait) {
bp->sw_bmsr = bigmac_tcvr_read(bp, tregs, MII_BMSR);
bp->sw_bmcr = bigmac_tcvr_read(bp, tregs, MII_BMCR);
if (bp->sw_bmsr & BMSR_LSTATUS) {
printk(KERN_INFO "%s: Link is now up at %s.\n",
bp->dev->name,
(bp->sw_bmcr & BMCR_SPEED100) ?
"100baseT" : "10baseT");
bp->timer_state = asleep;
restart_timer = 0;
} else {
if (bp->timer_ticks >= 4) {
int ret;
ret = try_next_permutation(bp, tregs);
if (ret == -1) {
printk(KERN_ERR "%s: Link down, cable problem?\n",
bp->dev->name);
ret = bigmac_init_hw(bp, 0);
if (ret) {
printk(KERN_ERR "%s: Error, cannot re-init the "
"BigMAC.\n", bp->dev->name);
}
return;
}
bp->timer_ticks = 0;
restart_timer = 1;
} else {
restart_timer = 1;
}
}
} else {
printk(KERN_ERR "%s: Aieee, link timer is asleep but we got one anyways!\n",
bp->dev->name);
restart_timer = 0;
bp->timer_ticks = 0;
bp->timer_state = asleep;
}
if (restart_timer != 0) {
bp->bigmac_timer.expires = jiffies + ((12 * HZ)/10);
add_timer(&bp->bigmac_timer);
}
}
static void bigmac_begin_auto_negotiation(struct bigmac *bp)
{
void __iomem *tregs = bp->tregs;
int timeout;
bp->sw_bmsr = bigmac_tcvr_read(bp, tregs, MII_BMSR);
bp->sw_bmcr = bigmac_tcvr_read(bp, tregs, MII_BMCR);
bp->sw_bmcr = (BMCR_ISOLATE | BMCR_PDOWN | BMCR_LOOPBACK);
bigmac_tcvr_write(bp, tregs, MII_BMCR, bp->sw_bmcr);
bp->sw_bmcr = (BMCR_RESET);
bigmac_tcvr_write(bp, tregs, MII_BMCR, bp->sw_bmcr);
timeout = 64;
while (--timeout) {
bp->sw_bmcr = bigmac_tcvr_read(bp, tregs, MII_BMCR);
if ((bp->sw_bmcr & BMCR_RESET) == 0)
break;
udelay(20);
}
if (timeout == 0)
printk(KERN_ERR "%s: PHY reset failed.\n", bp->dev->name);
bp->sw_bmcr = bigmac_tcvr_read(bp, tregs, MII_BMCR);
bp->sw_bmcr |= BMCR_SPEED100;
bigmac_tcvr_write(bp, tregs, MII_BMCR, bp->sw_bmcr);
bp->timer_state = ltrywait;
bp->timer_ticks = 0;
bp->bigmac_timer.expires = jiffies + (12 * HZ) / 10;
bp->bigmac_timer.data = (unsigned long) bp;
bp->bigmac_timer.function = bigmac_timer;
add_timer(&bp->bigmac_timer);
}
static int bigmac_init_hw(struct bigmac *bp, int from_irq)
{
void __iomem *gregs = bp->gregs;
void __iomem *cregs = bp->creg;
void __iomem *bregs = bp->bregs;
__u32 bblk_dvma = (__u32)bp->bblock_dvma;
unsigned char *e = &bp->dev->dev_addr[0];
bigmac_get_counters(bp, bregs);
qec_global_reset(gregs);
qec_init(bp);
bigmac_init_rings(bp, from_irq);
bigmac_tcvr_init(bp);
bigmac_stop(bp);
sbus_writel(((e[4] << 8) | e[5]), bregs + BMAC_MACADDR2);
sbus_writel(((e[2] << 8) | e[3]), bregs + BMAC_MACADDR1);
sbus_writel(((e[0] << 8) | e[1]), bregs + BMAC_MACADDR0);
sbus_writel(0, bregs + BMAC_HTABLE3);
sbus_writel(0, bregs + BMAC_HTABLE2);
sbus_writel(0, bregs + BMAC_HTABLE1);
sbus_writel(0, bregs + BMAC_HTABLE0);
sbus_writel(BIGMAC_RXCFG_HENABLE | BIGMAC_RXCFG_FIFO,
bregs + BMAC_RXCFG);
udelay(20);
sbus_writel(BIGMAC_TXCFG_FIFO, bregs + BMAC_TXCFG);
sbus_writel(((e[5] | e[4] << 8) & 0x3ff),
bregs + BMAC_RSEED);
sbus_writel(BIGMAC_XCFG_ODENABLE | BIGMAC_XCFG_RESV,
bregs + BMAC_XIFCFG);
sbus_writel(bblk_dvma + bib_offset(be_rxd, 0),
cregs + CREG_RXDS);
sbus_writel(bblk_dvma + bib_offset(be_txd, 0),
cregs + CREG_TXDS);
sbus_writel(0, cregs + CREG_RXRBUFPTR);
sbus_writel(0, cregs + CREG_RXWBUFPTR);
sbus_writel(sbus_readl(gregs + GLOB_RSIZE),
cregs + CREG_TXRBUFPTR);
sbus_writel(sbus_readl(gregs + GLOB_RSIZE),
cregs + CREG_TXWBUFPTR);
sbus_writel(BIGMAC_IMASK_GOTFRAME | BIGMAC_IMASK_SENTFRAME,
bregs + BMAC_IMASK);
sbus_writel(0, cregs + CREG_RIMASK);
sbus_writel(0, cregs + CREG_TIMASK);
sbus_writel(0, cregs + CREG_QMASK);
sbus_writel(0, cregs + CREG_BMASK);
sbus_writel(DEFAULT_JAMSIZE, bregs + BMAC_JSIZE);
sbus_writel(0, cregs + CREG_CCNT);
sbus_writel(sbus_readl(bregs + BMAC_TXCFG) | BIGMAC_TXCFG_ENABLE,
bregs + BMAC_TXCFG);
sbus_writel(sbus_readl(bregs + BMAC_RXCFG) | BIGMAC_RXCFG_ENABLE,
bregs + BMAC_RXCFG);
bigmac_begin_auto_negotiation(bp);
return 0;
}
static void bigmac_is_medium_rare(struct bigmac *bp, u32 qec_status, u32 bmac_status)
{
printk(KERN_ERR "bigmac_is_medium_rare: ");
if (qec_status & (GLOB_STAT_ER | GLOB_STAT_BM)) {
if (qec_status & GLOB_STAT_ER)
printk("QEC_ERROR, ");
if (qec_status & GLOB_STAT_BM)
printk("QEC_BMAC_ERROR, ");
}
if (bmac_status & CREG_STAT_ERRORS) {
if (bmac_status & CREG_STAT_BERROR)
printk("BMAC_ERROR, ");
if (bmac_status & CREG_STAT_TXDERROR)
printk("TXD_ERROR, ");
if (bmac_status & CREG_STAT_TXLERR)
printk("TX_LATE_ERROR, ");
if (bmac_status & CREG_STAT_TXPERR)
printk("TX_PARITY_ERROR, ");
if (bmac_status & CREG_STAT_TXSERR)
printk("TX_SBUS_ERROR, ");
if (bmac_status & CREG_STAT_RXDROP)
printk("RX_DROP_ERROR, ");
if (bmac_status & CREG_STAT_RXSMALL)
printk("RX_SMALL_ERROR, ");
if (bmac_status & CREG_STAT_RXLERR)
printk("RX_LATE_ERROR, ");
if (bmac_status & CREG_STAT_RXPERR)
printk("RX_PARITY_ERROR, ");
if (bmac_status & CREG_STAT_RXSERR)
printk("RX_SBUS_ERROR, ");
}
printk(" RESET\n");
bigmac_init_hw(bp, 1);
}
static void bigmac_tx(struct bigmac *bp)
{
struct be_txd *txbase = &bp->bmac_block->be_txd[0];
struct net_device *dev = bp->dev;
int elem;
spin_lock(&bp->lock);
elem = bp->tx_old;
DTX(("bigmac_tx: tx_old[%d] ", elem));
while (elem != bp->tx_new) {
struct sk_buff *skb;
struct be_txd *this = &txbase[elem];
DTX(("this(%p) [flags(%08x)addr(%08x)]",
this, this->tx_flags, this->tx_addr));
if (this->tx_flags & TXD_OWN)
break;
skb = bp->tx_skbs[elem];
dev->stats.tx_packets++;
dev->stats.tx_bytes += skb->len;
dma_unmap_single(&bp->bigmac_op->dev,
this->tx_addr, skb->len,
DMA_TO_DEVICE);
DTX(("skb(%p) ", skb));
bp->tx_skbs[elem] = NULL;
dev_kfree_skb_irq(skb);
elem = NEXT_TX(elem);
}
DTX((" DONE, tx_old=%d\n", elem));
bp->tx_old = elem;
if (netif_queue_stopped(dev) &&
TX_BUFFS_AVAIL(bp) > 0)
netif_wake_queue(bp->dev);
spin_unlock(&bp->lock);
}
static void bigmac_rx(struct bigmac *bp)
{
struct be_rxd *rxbase = &bp->bmac_block->be_rxd[0];
struct be_rxd *this;
int elem = bp->rx_new, drops = 0;
u32 flags;
this = &rxbase[elem];
while (!((flags = this->rx_flags) & RXD_OWN)) {
struct sk_buff *skb;
int len = (flags & RXD_LENGTH);
if (len < ETH_ZLEN) {
bp->dev->stats.rx_errors++;
bp->dev->stats.rx_length_errors++;
drop_it:
bp->dev->stats.rx_dropped++;
this->rx_flags =
(RXD_OWN | ((RX_BUF_ALLOC_SIZE - 34) & RXD_LENGTH));
goto next;
}
skb = bp->rx_skbs[elem];
if (len > RX_COPY_THRESHOLD) {
struct sk_buff *new_skb;
new_skb = big_mac_alloc_skb(RX_BUF_ALLOC_SIZE, GFP_ATOMIC);
if (new_skb == NULL) {
drops++;
goto drop_it;
}
dma_unmap_single(&bp->bigmac_op->dev,
this->rx_addr,
RX_BUF_ALLOC_SIZE - 34,
DMA_FROM_DEVICE);
bp->rx_skbs[elem] = new_skb;
skb_put(new_skb, ETH_FRAME_LEN);
skb_reserve(new_skb, 34);
this->rx_addr =
dma_map_single(&bp->bigmac_op->dev,
new_skb->data,
RX_BUF_ALLOC_SIZE - 34,
DMA_FROM_DEVICE);
this->rx_flags =
(RXD_OWN | ((RX_BUF_ALLOC_SIZE - 34) & RXD_LENGTH));
skb_trim(skb, len);
} else {
struct sk_buff *copy_skb = netdev_alloc_skb(bp->dev, len + 2);
if (copy_skb == NULL) {
drops++;
goto drop_it;
}
skb_reserve(copy_skb, 2);
skb_put(copy_skb, len);
dma_sync_single_for_cpu(&bp->bigmac_op->dev,
this->rx_addr, len,
DMA_FROM_DEVICE);
skb_copy_to_linear_data(copy_skb, (unsigned char *)skb->data, len);
dma_sync_single_for_device(&bp->bigmac_op->dev,
this->rx_addr, len,
DMA_FROM_DEVICE);
this->rx_flags =
(RXD_OWN | ((RX_BUF_ALLOC_SIZE - 34) & RXD_LENGTH));
skb = copy_skb;
}
skb->protocol = eth_type_trans(skb, bp->dev);
netif_rx(skb);
bp->dev->stats.rx_packets++;
bp->dev->stats.rx_bytes += len;
next:
elem = NEXT_RX(elem);
this = &rxbase[elem];
}
bp->rx_new = elem;
if (drops)
printk(KERN_NOTICE "%s: Memory squeeze, deferring packet.\n", bp->dev->name);
}
static irqreturn_t bigmac_interrupt(int irq, void *dev_id)
{
struct bigmac *bp = (struct bigmac *) dev_id;
u32 qec_status, bmac_status;
DIRQ(("bigmac_interrupt: "));
bmac_status = sbus_readl(bp->creg + CREG_STAT);
qec_status = sbus_readl(bp->gregs + GLOB_STAT);
DIRQ(("qec_status=%08x bmac_status=%08x\n", qec_status, bmac_status));
if ((qec_status & (GLOB_STAT_ER | GLOB_STAT_BM)) ||
(bmac_status & CREG_STAT_ERRORS))
bigmac_is_medium_rare(bp, qec_status, bmac_status);
if (bmac_status & CREG_STAT_TXIRQ)
bigmac_tx(bp);
if (bmac_status & CREG_STAT_RXIRQ)
bigmac_rx(bp);
return IRQ_HANDLED;
}
static int bigmac_open(struct net_device *dev)
{
struct bigmac *bp = netdev_priv(dev);
int ret;
ret = request_irq(dev->irq, bigmac_interrupt, IRQF_SHARED, dev->name, bp);
if (ret) {
printk(KERN_ERR "BIGMAC: Can't order irq %d to go.\n", dev->irq);
return ret;
}
init_timer(&bp->bigmac_timer);
ret = bigmac_init_hw(bp, 0);
if (ret)
free_irq(dev->irq, bp);
return ret;
}
static int bigmac_close(struct net_device *dev)
{
struct bigmac *bp = netdev_priv(dev);
del_timer(&bp->bigmac_timer);
bp->timer_state = asleep;
bp->timer_ticks = 0;
bigmac_stop(bp);
bigmac_clean_rings(bp);
free_irq(dev->irq, bp);
return 0;
}
static void bigmac_tx_timeout(struct net_device *dev)
{
struct bigmac *bp = netdev_priv(dev);
bigmac_init_hw(bp, 0);
netif_wake_queue(dev);
}
static int bigmac_start_xmit(struct sk_buff *skb, struct net_device *dev)
{
struct bigmac *bp = netdev_priv(dev);
int len, entry;
u32 mapping;
len = skb->len;
mapping = dma_map_single(&bp->bigmac_op->dev, skb->data,
len, DMA_TO_DEVICE);
spin_lock_irq(&bp->lock);
entry = bp->tx_new;
DTX(("bigmac_start_xmit: len(%d) entry(%d)\n", len, entry));
bp->bmac_block->be_txd[entry].tx_flags = TXD_UPDATE;
bp->tx_skbs[entry] = skb;
bp->bmac_block->be_txd[entry].tx_addr = mapping;
bp->bmac_block->be_txd[entry].tx_flags =
(TXD_OWN | TXD_SOP | TXD_EOP | (len & TXD_LENGTH));
bp->tx_new = NEXT_TX(entry);
if (TX_BUFFS_AVAIL(bp) <= 0)
netif_stop_queue(dev);
spin_unlock_irq(&bp->lock);
sbus_writel(CREG_CTRL_TWAKEUP, bp->creg + CREG_CTRL);
return NETDEV_TX_OK;
}
static struct net_device_stats *bigmac_get_stats(struct net_device *dev)
{
struct bigmac *bp = netdev_priv(dev);
bigmac_get_counters(bp, bp->bregs);
return &dev->stats;
}
static void bigmac_set_multicast(struct net_device *dev)
{
struct bigmac *bp = netdev_priv(dev);
void __iomem *bregs = bp->bregs;
struct netdev_hw_addr *ha;
u32 tmp, crc;
tmp = sbus_readl(bregs + BMAC_RXCFG);
tmp &= ~(BIGMAC_RXCFG_ENABLE);
sbus_writel(tmp, bregs + BMAC_RXCFG);
while ((sbus_readl(bregs + BMAC_RXCFG) & BIGMAC_RXCFG_ENABLE) != 0)
udelay(20);
if ((dev->flags & IFF_ALLMULTI) || (netdev_mc_count(dev) > 64)) {
sbus_writel(0xffff, bregs + BMAC_HTABLE0);
sbus_writel(0xffff, bregs + BMAC_HTABLE1);
sbus_writel(0xffff, bregs + BMAC_HTABLE2);
sbus_writel(0xffff, bregs + BMAC_HTABLE3);
} else if (dev->flags & IFF_PROMISC) {
tmp = sbus_readl(bregs + BMAC_RXCFG);
tmp |= BIGMAC_RXCFG_PMISC;
sbus_writel(tmp, bregs + BMAC_RXCFG);
} else {
u16 hash_table[4] = { 0 };
netdev_for_each_mc_addr(ha, dev) {
crc = ether_crc_le(6, ha->addr);
crc >>= 26;
hash_table[crc >> 4] |= 1 << (crc & 0xf);
}
sbus_writel(hash_table[0], bregs + BMAC_HTABLE0);
sbus_writel(hash_table[1], bregs + BMAC_HTABLE1);
sbus_writel(hash_table[2], bregs + BMAC_HTABLE2);
sbus_writel(hash_table[3], bregs + BMAC_HTABLE3);
}
tmp = sbus_readl(bregs + BMAC_RXCFG);
tmp |= BIGMAC_RXCFG_ENABLE;
sbus_writel(tmp, bregs + BMAC_RXCFG);
}
static void bigmac_get_drvinfo(struct net_device *dev, struct ethtool_drvinfo *info)
{
strlcpy(info->driver, "sunbmac", sizeof(info->driver));
strlcpy(info->version, "2.0", sizeof(info->version));
}
static u32 bigmac_get_link(struct net_device *dev)
{
struct bigmac *bp = netdev_priv(dev);
spin_lock_irq(&bp->lock);
bp->sw_bmsr = bigmac_tcvr_read(bp, bp->tregs, MII_BMSR);
spin_unlock_irq(&bp->lock);
return (bp->sw_bmsr & BMSR_LSTATUS);
}
static int bigmac_ether_init(struct platform_device *op,
struct platform_device *qec_op)
{
static int version_printed;
struct net_device *dev;
u8 bsizes, bsizes_more;
struct bigmac *bp;
int i;
dev = alloc_etherdev(sizeof(struct bigmac));
if (!dev)
return -ENOMEM;
if (version_printed++ == 0)
printk(KERN_INFO "%s", version);
for (i = 0; i < 6; i++)
dev->dev_addr[i] = idprom->id_ethaddr[i];
bp = netdev_priv(dev);
bp->qec_op = qec_op;
bp->bigmac_op = op;
SET_NETDEV_DEV(dev, &op->dev);
spin_lock_init(&bp->lock);
bp->gregs = of_ioremap(&qec_op->resource[0], 0,
GLOB_REG_SIZE, "BigMAC QEC GLobal Regs");
if (!bp->gregs) {
printk(KERN_ERR "BIGMAC: Cannot map QEC global registers.\n");
goto fail_and_cleanup;
}
if ((sbus_readl(bp->gregs + GLOB_CTRL) & 0xf0000000) != GLOB_CTRL_BMODE) {
printk(KERN_ERR "BigMAC: AIEEE, QEC is not in BigMAC mode!\n");
goto fail_and_cleanup;
}
if (qec_global_reset(bp->gregs))
goto fail_and_cleanup;
bsizes = of_getintprop_default(qec_op->dev.of_node, "burst-sizes", 0xff);
bsizes_more = of_getintprop_default(qec_op->dev.of_node, "burst-sizes", 0xff);
bsizes &= 0xff;
if (bsizes_more != 0xff)
bsizes &= bsizes_more;
if (bsizes == 0xff || (bsizes & DMA_BURST16) == 0 ||
(bsizes & DMA_BURST32) == 0)
bsizes = (DMA_BURST32 - 1);
bp->bigmac_bursts = bsizes;
qec_init(bp);
bp->creg = of_ioremap(&op->resource[0], 0,
CREG_REG_SIZE, "BigMAC QEC Channel Regs");
if (!bp->creg) {
printk(KERN_ERR "BIGMAC: Cannot map QEC channel registers.\n");
goto fail_and_cleanup;
}
bp->bregs = of_ioremap(&op->resource[1], 0,
BMAC_REG_SIZE, "BigMAC Primary Regs");
if (!bp->bregs) {
printk(KERN_ERR "BIGMAC: Cannot map BigMAC primary registers.\n");
goto fail_and_cleanup;
}
bp->tregs = of_ioremap(&op->resource[2], 0,
TCVR_REG_SIZE, "BigMAC Transceiver Regs");
if (!bp->tregs) {
printk(KERN_ERR "BIGMAC: Cannot map BigMAC transceiver registers.\n");
goto fail_and_cleanup;
}
bigmac_stop(bp);
bp->bmac_block = dma_alloc_coherent(&bp->bigmac_op->dev,
PAGE_SIZE,
&bp->bblock_dvma, GFP_ATOMIC);
if (bp->bmac_block == NULL || bp->bblock_dvma == 0)
goto fail_and_cleanup;
bp->board_rev = of_getintprop_default(bp->bigmac_op->dev.of_node,
"board-version", 1);
init_timer(&bp->bigmac_timer);
bp->timer_state = asleep;
bp->timer_ticks = 0;
bp->dev = dev;
dev->ethtool_ops = &bigmac_ethtool_ops;
dev->netdev_ops = &bigmac_ops;
dev->watchdog_timeo = 5*HZ;
dev->irq = bp->bigmac_op->archdata.irqs[0];
dev->dma = 0;
if (register_netdev(dev)) {
printk(KERN_ERR "BIGMAC: Cannot register device.\n");
goto fail_and_cleanup;
}
dev_set_drvdata(&bp->bigmac_op->dev, bp);
printk(KERN_INFO "%s: BigMAC 100baseT Ethernet %pM\n",
dev->name, dev->dev_addr);
return 0;
fail_and_cleanup:
if (bp->gregs)
of_iounmap(&qec_op->resource[0], bp->gregs, GLOB_REG_SIZE);
if (bp->creg)
of_iounmap(&op->resource[0], bp->creg, CREG_REG_SIZE);
if (bp->bregs)
of_iounmap(&op->resource[1], bp->bregs, BMAC_REG_SIZE);
if (bp->tregs)
of_iounmap(&op->resource[2], bp->tregs, TCVR_REG_SIZE);
if (bp->bmac_block)
dma_free_coherent(&bp->bigmac_op->dev,
PAGE_SIZE,
bp->bmac_block,
bp->bblock_dvma);
free_netdev(dev);
return -ENODEV;
}
static int bigmac_sbus_probe(struct platform_device *op)
{
struct device *parent = op->dev.parent;
struct platform_device *qec_op;
qec_op = to_platform_device(parent);
return bigmac_ether_init(op, qec_op);
}
static int bigmac_sbus_remove(struct platform_device *op)
{
struct bigmac *bp = platform_get_drvdata(op);
struct device *parent = op->dev.parent;
struct net_device *net_dev = bp->dev;
struct platform_device *qec_op;
qec_op = to_platform_device(parent);
unregister_netdev(net_dev);
of_iounmap(&qec_op->resource[0], bp->gregs, GLOB_REG_SIZE);
of_iounmap(&op->resource[0], bp->creg, CREG_REG_SIZE);
of_iounmap(&op->resource[1], bp->bregs, BMAC_REG_SIZE);
of_iounmap(&op->resource[2], bp->tregs, TCVR_REG_SIZE);
dma_free_coherent(&op->dev,
PAGE_SIZE,
bp->bmac_block,
bp->bblock_dvma);
free_netdev(net_dev);
return 0;
}
