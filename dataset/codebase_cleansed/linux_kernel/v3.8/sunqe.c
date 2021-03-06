static inline int qec_global_reset(void __iomem *gregs)
{
int tries = QEC_RESET_TRIES;
sbus_writel(GLOB_CTRL_RESET, gregs + GLOB_CTRL);
while (--tries) {
u32 tmp = sbus_readl(gregs + GLOB_CTRL);
if (tmp & GLOB_CTRL_RESET) {
udelay(20);
continue;
}
break;
}
if (tries)
return 0;
printk(KERN_ERR "QuadEther: AIEEE cannot reset the QEC!\n");
return -1;
}
static inline int qe_stop(struct sunqe *qep)
{
void __iomem *cregs = qep->qcregs;
void __iomem *mregs = qep->mregs;
int tries;
sbus_writeb(MREGS_BCONFIG_RESET, mregs + MREGS_BCONFIG);
tries = MACE_RESET_RETRIES;
while (--tries) {
u8 tmp = sbus_readb(mregs + MREGS_BCONFIG);
if (tmp & MREGS_BCONFIG_RESET) {
udelay(20);
continue;
}
break;
}
if (!tries) {
printk(KERN_ERR "QuadEther: AIEEE cannot reset the MACE!\n");
return -1;
}
sbus_writel(CREG_CTRL_RESET, cregs + CREG_CTRL);
tries = QE_RESET_RETRIES;
while (--tries) {
u32 tmp = sbus_readl(cregs + CREG_CTRL);
if (tmp & CREG_CTRL_RESET) {
udelay(20);
continue;
}
break;
}
if (!tries) {
printk(KERN_ERR "QuadEther: Cannot reset QE channel!\n");
return -1;
}
return 0;
}
static void qe_init_rings(struct sunqe *qep)
{
struct qe_init_block *qb = qep->qe_block;
struct sunqe_buffers *qbufs = qep->buffers;
__u32 qbufs_dvma = qep->buffers_dvma;
int i;
qep->rx_new = qep->rx_old = qep->tx_new = qep->tx_old = 0;
memset(qb, 0, sizeof(struct qe_init_block));
memset(qbufs, 0, sizeof(struct sunqe_buffers));
for (i = 0; i < RX_RING_SIZE; i++) {
qb->qe_rxd[i].rx_addr = qbufs_dvma + qebuf_offset(rx_buf, i);
qb->qe_rxd[i].rx_flags =
(RXD_OWN | ((RXD_PKT_SZ) & RXD_LENGTH));
}
}
static int qe_init(struct sunqe *qep, int from_irq)
{
struct sunqec *qecp = qep->parent;
void __iomem *cregs = qep->qcregs;
void __iomem *mregs = qep->mregs;
void __iomem *gregs = qecp->gregs;
unsigned char *e = &qep->dev->dev_addr[0];
u32 tmp;
int i;
if (qe_stop(qep))
return -EAGAIN;
sbus_writel(qep->qblock_dvma + qib_offset(qe_rxd, 0), cregs + CREG_RXDS);
sbus_writel(qep->qblock_dvma + qib_offset(qe_txd, 0), cregs + CREG_TXDS);
sbus_writel(0, cregs + CREG_RIMASK);
sbus_writel(1, cregs + CREG_TIMASK);
sbus_writel(0, cregs + CREG_QMASK);
sbus_writel(CREG_MMASK_RXCOLL, cregs + CREG_MMASK);
tmp = qep->channel * sbus_readl(gregs + GLOB_MSIZE);
sbus_writel(tmp, cregs + CREG_RXRBUFPTR);
sbus_writel(tmp, cregs + CREG_RXWBUFPTR);
tmp = sbus_readl(cregs + CREG_RXRBUFPTR) +
sbus_readl(gregs + GLOB_RSIZE);
sbus_writel(tmp, cregs + CREG_TXRBUFPTR);
sbus_writel(tmp, cregs + CREG_TXWBUFPTR);
sbus_writel(0, cregs + CREG_CCNT);
sbus_writel(0, cregs + CREG_PIPG);
sbus_writeb(MREGS_PHYCONFIG_AUTO, mregs + MREGS_PHYCONFIG);
sbus_writeb(MREGS_TXFCNTL_AUTOPAD, mregs + MREGS_TXFCNTL);
sbus_writeb(0, mregs + MREGS_RXFCNTL);
sbus_writeb(MREGS_IMASK_COLL | MREGS_IMASK_RXIRQ, mregs + MREGS_IMASK);
sbus_writeb(MREGS_BCONFIG_BSWAP | MREGS_BCONFIG_64TS, mregs + MREGS_BCONFIG);
sbus_writeb((MREGS_FCONFIG_TXF16 | MREGS_FCONFIG_RXF32 |
MREGS_FCONFIG_RFWU | MREGS_FCONFIG_TFWU),
mregs + MREGS_FCONFIG);
sbus_writeb(MREGS_PLSCONFIG_TP, mregs + MREGS_PLSCONFIG);
sbus_writeb(MREGS_IACONFIG_ACHNGE | MREGS_IACONFIG_PARESET,
mregs + MREGS_IACONFIG);
while ((sbus_readb(mregs + MREGS_IACONFIG) & MREGS_IACONFIG_ACHNGE) != 0)
barrier();
sbus_writeb(e[0], mregs + MREGS_ETHADDR);
sbus_writeb(e[1], mregs + MREGS_ETHADDR);
sbus_writeb(e[2], mregs + MREGS_ETHADDR);
sbus_writeb(e[3], mregs + MREGS_ETHADDR);
sbus_writeb(e[4], mregs + MREGS_ETHADDR);
sbus_writeb(e[5], mregs + MREGS_ETHADDR);
sbus_writeb(MREGS_IACONFIG_ACHNGE | MREGS_IACONFIG_LARESET,
mregs + MREGS_IACONFIG);
while ((sbus_readb(mregs + MREGS_IACONFIG) & MREGS_IACONFIG_ACHNGE) != 0)
barrier();
for (i = 0; i < 8; i++)
sbus_writeb(0, mregs + MREGS_FILTER);
sbus_writeb(0, mregs + MREGS_IACONFIG);
qe_init_rings(qep);
mdelay(5);
if (!(sbus_readb(mregs + MREGS_PHYCONFIG) & MREGS_PHYCONFIG_LTESTDIS)) {
int tries = 50;
while (--tries) {
u8 tmp;
mdelay(5);
barrier();
tmp = sbus_readb(mregs + MREGS_PHYCONFIG);
if ((tmp & MREGS_PHYCONFIG_LSTAT) != 0)
break;
}
if (tries == 0)
printk(KERN_NOTICE "%s: Warning, link state is down.\n", qep->dev->name);
}
sbus_readb(mregs + MREGS_MPCNT);
qe_set_multicast(qep->dev);
return 0;
}
static int qe_is_bolixed(struct sunqe *qep, u32 qe_status)
{
struct net_device *dev = qep->dev;
int mace_hwbug_workaround = 0;
if (qe_status & CREG_STAT_EDEFER) {
printk(KERN_ERR "%s: Excessive transmit defers.\n", dev->name);
dev->stats.tx_errors++;
}
if (qe_status & CREG_STAT_CLOSS) {
printk(KERN_ERR "%s: Carrier lost, link down?\n", dev->name);
dev->stats.tx_errors++;
dev->stats.tx_carrier_errors++;
}
if (qe_status & CREG_STAT_ERETRIES) {
printk(KERN_ERR "%s: Excessive transmit retries (more than 16).\n", dev->name);
dev->stats.tx_errors++;
mace_hwbug_workaround = 1;
}
if (qe_status & CREG_STAT_LCOLL) {
printk(KERN_ERR "%s: Late transmit collision.\n", dev->name);
dev->stats.tx_errors++;
dev->stats.collisions++;
mace_hwbug_workaround = 1;
}
if (qe_status & CREG_STAT_FUFLOW) {
printk(KERN_ERR "%s: Transmit fifo underflow, driver bug.\n", dev->name);
dev->stats.tx_errors++;
mace_hwbug_workaround = 1;
}
if (qe_status & CREG_STAT_JERROR) {
printk(KERN_ERR "%s: Jabber error.\n", dev->name);
}
if (qe_status & CREG_STAT_BERROR) {
printk(KERN_ERR "%s: Babble error.\n", dev->name);
}
if (qe_status & CREG_STAT_CCOFLOW) {
dev->stats.tx_errors += 256;
dev->stats.collisions += 256;
}
if (qe_status & CREG_STAT_TXDERROR) {
printk(KERN_ERR "%s: Transmit descriptor is bogus, driver bug.\n", dev->name);
dev->stats.tx_errors++;
dev->stats.tx_aborted_errors++;
mace_hwbug_workaround = 1;
}
if (qe_status & CREG_STAT_TXLERR) {
printk(KERN_ERR "%s: Transmit late error.\n", dev->name);
dev->stats.tx_errors++;
mace_hwbug_workaround = 1;
}
if (qe_status & CREG_STAT_TXPERR) {
printk(KERN_ERR "%s: Transmit DMA parity error.\n", dev->name);
dev->stats.tx_errors++;
dev->stats.tx_aborted_errors++;
mace_hwbug_workaround = 1;
}
if (qe_status & CREG_STAT_TXSERR) {
printk(KERN_ERR "%s: Transmit DMA sbus error ack.\n", dev->name);
dev->stats.tx_errors++;
dev->stats.tx_aborted_errors++;
mace_hwbug_workaround = 1;
}
if (qe_status & CREG_STAT_RCCOFLOW) {
dev->stats.rx_errors += 256;
dev->stats.collisions += 256;
}
if (qe_status & CREG_STAT_RUOFLOW) {
dev->stats.rx_errors += 256;
dev->stats.rx_over_errors += 256;
}
if (qe_status & CREG_STAT_MCOFLOW) {
dev->stats.rx_errors += 256;
dev->stats.rx_missed_errors += 256;
}
if (qe_status & CREG_STAT_RXFOFLOW) {
printk(KERN_ERR "%s: Receive fifo overflow.\n", dev->name);
dev->stats.rx_errors++;
dev->stats.rx_over_errors++;
}
if (qe_status & CREG_STAT_RLCOLL) {
printk(KERN_ERR "%s: Late receive collision.\n", dev->name);
dev->stats.rx_errors++;
dev->stats.collisions++;
}
if (qe_status & CREG_STAT_FCOFLOW) {
dev->stats.rx_errors += 256;
dev->stats.rx_frame_errors += 256;
}
if (qe_status & CREG_STAT_CECOFLOW) {
dev->stats.rx_errors += 256;
dev->stats.rx_crc_errors += 256;
}
if (qe_status & CREG_STAT_RXDROP) {
printk(KERN_ERR "%s: Receive packet dropped.\n", dev->name);
dev->stats.rx_errors++;
dev->stats.rx_dropped++;
dev->stats.rx_missed_errors++;
}
if (qe_status & CREG_STAT_RXSMALL) {
printk(KERN_ERR "%s: Receive buffer too small, driver bug.\n", dev->name);
dev->stats.rx_errors++;
dev->stats.rx_length_errors++;
}
if (qe_status & CREG_STAT_RXLERR) {
printk(KERN_ERR "%s: Receive late error.\n", dev->name);
dev->stats.rx_errors++;
mace_hwbug_workaround = 1;
}
if (qe_status & CREG_STAT_RXPERR) {
printk(KERN_ERR "%s: Receive DMA parity error.\n", dev->name);
dev->stats.rx_errors++;
dev->stats.rx_missed_errors++;
mace_hwbug_workaround = 1;
}
if (qe_status & CREG_STAT_RXSERR) {
printk(KERN_ERR "%s: Receive DMA sbus error ack.\n", dev->name);
dev->stats.rx_errors++;
dev->stats.rx_missed_errors++;
mace_hwbug_workaround = 1;
}
if (mace_hwbug_workaround)
qe_init(qep, 1);
return mace_hwbug_workaround;
}
static void qe_rx(struct sunqe *qep)
{
struct qe_rxd *rxbase = &qep->qe_block->qe_rxd[0];
struct net_device *dev = qep->dev;
struct qe_rxd *this;
struct sunqe_buffers *qbufs = qep->buffers;
__u32 qbufs_dvma = qep->buffers_dvma;
int elem = qep->rx_new, drops = 0;
u32 flags;
this = &rxbase[elem];
while (!((flags = this->rx_flags) & RXD_OWN)) {
struct sk_buff *skb;
unsigned char *this_qbuf =
&qbufs->rx_buf[elem & (RX_RING_SIZE - 1)][0];
__u32 this_qbuf_dvma = qbufs_dvma +
qebuf_offset(rx_buf, (elem & (RX_RING_SIZE - 1)));
struct qe_rxd *end_rxd =
&rxbase[(elem+RX_RING_SIZE)&(RX_RING_MAXSIZE-1)];
int len = (flags & RXD_LENGTH) - 4;
if (len < ETH_ZLEN) {
dev->stats.rx_errors++;
dev->stats.rx_length_errors++;
dev->stats.rx_dropped++;
} else {
skb = netdev_alloc_skb(dev, len + 2);
if (skb == NULL) {
drops++;
dev->stats.rx_dropped++;
} else {
skb_reserve(skb, 2);
skb_put(skb, len);
skb_copy_to_linear_data(skb, this_qbuf,
len);
skb->protocol = eth_type_trans(skb, qep->dev);
netif_rx(skb);
dev->stats.rx_packets++;
dev->stats.rx_bytes += len;
}
}
end_rxd->rx_addr = this_qbuf_dvma;
end_rxd->rx_flags = (RXD_OWN | ((RXD_PKT_SZ) & RXD_LENGTH));
elem = NEXT_RX(elem);
this = &rxbase[elem];
}
qep->rx_new = elem;
if (drops)
printk(KERN_NOTICE "%s: Memory squeeze, deferring packet.\n", qep->dev->name);
}
static irqreturn_t qec_interrupt(int irq, void *dev_id)
{
struct sunqec *qecp = dev_id;
u32 qec_status;
int channel = 0;
qec_status = sbus_readl(qecp->gregs + GLOB_STAT);
while (channel < 4) {
if (qec_status & 0xf) {
struct sunqe *qep = qecp->qes[channel];
u32 qe_status;
qe_status = sbus_readl(qep->qcregs + CREG_STAT);
if (qe_status & CREG_STAT_ERRORS) {
if (qe_is_bolixed(qep, qe_status))
goto next;
}
if (qe_status & CREG_STAT_RXIRQ)
qe_rx(qep);
if (netif_queue_stopped(qep->dev) &&
(qe_status & CREG_STAT_TXIRQ)) {
spin_lock(&qep->lock);
qe_tx_reclaim(qep);
if (TX_BUFFS_AVAIL(qep) > 0) {
netif_wake_queue(qep->dev);
sbus_writel(1, qep->qcregs + CREG_TIMASK);
}
spin_unlock(&qep->lock);
}
next:
;
}
qec_status >>= 4;
channel++;
}
return IRQ_HANDLED;
}
static int qe_open(struct net_device *dev)
{
struct sunqe *qep = netdev_priv(dev);
qep->mconfig = (MREGS_MCONFIG_TXENAB |
MREGS_MCONFIG_RXENAB |
MREGS_MCONFIG_MBAENAB);
return qe_init(qep, 0);
}
static int qe_close(struct net_device *dev)
{
struct sunqe *qep = netdev_priv(dev);
qe_stop(qep);
return 0;
}
static void qe_tx_reclaim(struct sunqe *qep)
{
struct qe_txd *txbase = &qep->qe_block->qe_txd[0];
int elem = qep->tx_old;
while (elem != qep->tx_new) {
u32 flags = txbase[elem].tx_flags;
if (flags & TXD_OWN)
break;
elem = NEXT_TX(elem);
}
qep->tx_old = elem;
}
static void qe_tx_timeout(struct net_device *dev)
{
struct sunqe *qep = netdev_priv(dev);
int tx_full;
spin_lock_irq(&qep->lock);
qe_tx_reclaim(qep);
tx_full = TX_BUFFS_AVAIL(qep) <= 0;
spin_unlock_irq(&qep->lock);
if (! tx_full)
goto out;
printk(KERN_ERR "%s: transmit timed out, resetting\n", dev->name);
qe_init(qep, 1);
out:
netif_wake_queue(dev);
}
static int qe_start_xmit(struct sk_buff *skb, struct net_device *dev)
{
struct sunqe *qep = netdev_priv(dev);
struct sunqe_buffers *qbufs = qep->buffers;
__u32 txbuf_dvma, qbufs_dvma = qep->buffers_dvma;
unsigned char *txbuf;
int len, entry;
spin_lock_irq(&qep->lock);
qe_tx_reclaim(qep);
len = skb->len;
entry = qep->tx_new;
txbuf = &qbufs->tx_buf[entry & (TX_RING_SIZE - 1)][0];
txbuf_dvma = qbufs_dvma +
qebuf_offset(tx_buf, (entry & (TX_RING_SIZE - 1)));
qep->qe_block->qe_txd[entry].tx_flags = TXD_UPDATE;
skb_copy_from_linear_data(skb, txbuf, len);
qep->qe_block->qe_txd[entry].tx_addr = txbuf_dvma;
qep->qe_block->qe_txd[entry].tx_flags =
(TXD_OWN | TXD_SOP | TXD_EOP | (len & TXD_LENGTH));
qep->tx_new = NEXT_TX(entry);
sbus_writel(CREG_CTRL_TWAKEUP, qep->qcregs + CREG_CTRL);
dev->stats.tx_packets++;
dev->stats.tx_bytes += len;
if (TX_BUFFS_AVAIL(qep) <= 0) {
netif_stop_queue(dev);
sbus_writel(0, qep->qcregs + CREG_TIMASK);
}
spin_unlock_irq(&qep->lock);
dev_kfree_skb(skb);
return NETDEV_TX_OK;
}
static void qe_set_multicast(struct net_device *dev)
{
struct sunqe *qep = netdev_priv(dev);
struct netdev_hw_addr *ha;
u8 new_mconfig = qep->mconfig;
int i;
u32 crc;
netif_stop_queue(dev);
if ((dev->flags & IFF_ALLMULTI) || (netdev_mc_count(dev) > 64)) {
sbus_writeb(MREGS_IACONFIG_ACHNGE | MREGS_IACONFIG_LARESET,
qep->mregs + MREGS_IACONFIG);
while ((sbus_readb(qep->mregs + MREGS_IACONFIG) & MREGS_IACONFIG_ACHNGE) != 0)
barrier();
for (i = 0; i < 8; i++)
sbus_writeb(0xff, qep->mregs + MREGS_FILTER);
sbus_writeb(0, qep->mregs + MREGS_IACONFIG);
} else if (dev->flags & IFF_PROMISC) {
new_mconfig |= MREGS_MCONFIG_PROMISC;
} else {
u16 hash_table[4];
u8 *hbytes = (unsigned char *) &hash_table[0];
memset(hash_table, 0, sizeof(hash_table));
netdev_for_each_mc_addr(ha, dev) {
crc = ether_crc_le(6, ha->addr);
crc >>= 26;
hash_table[crc >> 4] |= 1 << (crc & 0xf);
}
sbus_writeb(MREGS_IACONFIG_ACHNGE | MREGS_IACONFIG_LARESET,
qep->mregs + MREGS_IACONFIG);
while ((sbus_readb(qep->mregs + MREGS_IACONFIG) & MREGS_IACONFIG_ACHNGE) != 0)
barrier();
for (i = 0; i < 8; i++) {
u8 tmp = *hbytes++;
sbus_writeb(tmp, qep->mregs + MREGS_FILTER);
}
sbus_writeb(0, qep->mregs + MREGS_IACONFIG);
}
qep->mconfig = new_mconfig;
sbus_writeb(qep->mconfig, qep->mregs + MREGS_MCONFIG);
netif_wake_queue(dev);
}
static void qe_get_drvinfo(struct net_device *dev, struct ethtool_drvinfo *info)
{
const struct linux_prom_registers *regs;
struct sunqe *qep = netdev_priv(dev);
struct platform_device *op;
strcpy(info->driver, "sunqe");
strcpy(info->version, "3.0");
op = qep->op;
regs = of_get_property(op->dev.of_node, "reg", NULL);
if (regs)
sprintf(info->bus_info, "SBUS:%d", regs->which_io);
}
static u32 qe_get_link(struct net_device *dev)
{
struct sunqe *qep = netdev_priv(dev);
void __iomem *mregs = qep->mregs;
u8 phyconfig;
spin_lock_irq(&qep->lock);
phyconfig = sbus_readb(mregs + MREGS_PHYCONFIG);
spin_unlock_irq(&qep->lock);
return phyconfig & MREGS_PHYCONFIG_LSTAT;
}
static void qec_init_once(struct sunqec *qecp, struct platform_device *op)
{
u8 bsizes = qecp->qec_bursts;
if (sbus_can_burst64() && (bsizes & DMA_BURST64)) {
sbus_writel(GLOB_CTRL_B64, qecp->gregs + GLOB_CTRL);
} else if (bsizes & DMA_BURST32) {
sbus_writel(GLOB_CTRL_B32, qecp->gregs + GLOB_CTRL);
} else {
sbus_writel(GLOB_CTRL_B16, qecp->gregs + GLOB_CTRL);
}
sbus_writel(GLOB_PSIZE_2048, qecp->gregs + GLOB_PSIZE);
sbus_writel((resource_size(&op->resource[1]) >> 2),
qecp->gregs + GLOB_MSIZE);
sbus_writel((resource_size(&op->resource[1]) >> 2) >> 1,
qecp->gregs + GLOB_TSIZE);
sbus_writel((resource_size(&op->resource[1]) >> 2) >> 1,
qecp->gregs + GLOB_RSIZE);
}
static u8 qec_get_burst(struct device_node *dp)
{
u8 bsizes, bsizes_more;
bsizes = of_getintprop_default(dp, "burst-sizes", 0xff);
bsizes &= 0xff;
bsizes_more = of_getintprop_default(dp->parent, "burst-sizes", 0xff);
if (bsizes_more != 0xff)
bsizes &= bsizes_more;
if (bsizes == 0xff || (bsizes & DMA_BURST16) == 0 ||
(bsizes & DMA_BURST32)==0)
bsizes = (DMA_BURST32 - 1);
return bsizes;
}
static struct sunqec *get_qec(struct platform_device *child)
{
struct platform_device *op = to_platform_device(child->dev.parent);
struct sunqec *qecp;
qecp = dev_get_drvdata(&op->dev);
if (!qecp) {
qecp = kzalloc(sizeof(struct sunqec), GFP_KERNEL);
if (qecp) {
u32 ctrl;
qecp->op = op;
qecp->gregs = of_ioremap(&op->resource[0], 0,
GLOB_REG_SIZE,
"QEC Global Registers");
if (!qecp->gregs)
goto fail;
ctrl = sbus_readl(qecp->gregs + GLOB_CTRL);
ctrl &= 0xf0000000;
if (ctrl != GLOB_CTRL_MMODE) {
printk(KERN_ERR "qec: Not in MACE mode!\n");
goto fail;
}
if (qec_global_reset(qecp->gregs))
goto fail;
qecp->qec_bursts = qec_get_burst(op->dev.of_node);
qec_init_once(qecp, op);
if (request_irq(op->archdata.irqs[0], qec_interrupt,
IRQF_SHARED, "qec", (void *) qecp)) {
printk(KERN_ERR "qec: Can't register irq.\n");
goto fail;
}
dev_set_drvdata(&op->dev, qecp);
qecp->next_module = root_qec_dev;
root_qec_dev = qecp;
}
}
return qecp;
fail:
if (qecp->gregs)
of_iounmap(&op->resource[0], qecp->gregs, GLOB_REG_SIZE);
kfree(qecp);
return NULL;
}
static int qec_ether_init(struct platform_device *op)
{
static unsigned version_printed;
struct net_device *dev;
struct sunqec *qecp;
struct sunqe *qe;
int i, res;
if (version_printed++ == 0)
printk(KERN_INFO "%s", version);
dev = alloc_etherdev(sizeof(struct sunqe));
if (!dev)
return -ENOMEM;
memcpy(dev->dev_addr, idprom->id_ethaddr, 6);
qe = netdev_priv(dev);
res = -ENODEV;
i = of_getintprop_default(op->dev.of_node, "channel#", -1);
if (i == -1)
goto fail;
qe->channel = i;
spin_lock_init(&qe->lock);
qecp = get_qec(op);
if (!qecp)
goto fail;
qecp->qes[qe->channel] = qe;
qe->dev = dev;
qe->parent = qecp;
qe->op = op;
res = -ENOMEM;
qe->qcregs = of_ioremap(&op->resource[0], 0,
CREG_REG_SIZE, "QEC Channel Registers");
if (!qe->qcregs) {
printk(KERN_ERR "qe: Cannot map channel registers.\n");
goto fail;
}
qe->mregs = of_ioremap(&op->resource[1], 0,
MREGS_REG_SIZE, "QE MACE Registers");
if (!qe->mregs) {
printk(KERN_ERR "qe: Cannot map MACE registers.\n");
goto fail;
}
qe->qe_block = dma_alloc_coherent(&op->dev, PAGE_SIZE,
&qe->qblock_dvma, GFP_ATOMIC);
qe->buffers = dma_alloc_coherent(&op->dev, sizeof(struct sunqe_buffers),
&qe->buffers_dvma, GFP_ATOMIC);
if (qe->qe_block == NULL || qe->qblock_dvma == 0 ||
qe->buffers == NULL || qe->buffers_dvma == 0)
goto fail;
qe_stop(qe);
SET_NETDEV_DEV(dev, &op->dev);
dev->watchdog_timeo = 5*HZ;
dev->irq = op->archdata.irqs[0];
dev->dma = 0;
dev->ethtool_ops = &qe_ethtool_ops;
dev->netdev_ops = &qec_ops;
res = register_netdev(dev);
if (res)
goto fail;
dev_set_drvdata(&op->dev, qe);
printk(KERN_INFO "%s: qe channel[%d] %pM\n", dev->name, qe->channel,
dev->dev_addr);
return 0;
fail:
if (qe->qcregs)
of_iounmap(&op->resource[0], qe->qcregs, CREG_REG_SIZE);
if (qe->mregs)
of_iounmap(&op->resource[1], qe->mregs, MREGS_REG_SIZE);
if (qe->qe_block)
dma_free_coherent(&op->dev, PAGE_SIZE,
qe->qe_block, qe->qblock_dvma);
if (qe->buffers)
dma_free_coherent(&op->dev,
sizeof(struct sunqe_buffers),
qe->buffers,
qe->buffers_dvma);
free_netdev(dev);
return res;
}
static int qec_sbus_probe(struct platform_device *op)
{
return qec_ether_init(op);
}
static int qec_sbus_remove(struct platform_device *op)
{
struct sunqe *qp = dev_get_drvdata(&op->dev);
struct net_device *net_dev = qp->dev;
unregister_netdev(net_dev);
of_iounmap(&op->resource[0], qp->qcregs, CREG_REG_SIZE);
of_iounmap(&op->resource[1], qp->mregs, MREGS_REG_SIZE);
dma_free_coherent(&op->dev, PAGE_SIZE,
qp->qe_block, qp->qblock_dvma);
dma_free_coherent(&op->dev, sizeof(struct sunqe_buffers),
qp->buffers, qp->buffers_dvma);
free_netdev(net_dev);
dev_set_drvdata(&op->dev, NULL);
return 0;
}
static int __init qec_init(void)
{
return platform_driver_register(&qec_sbus_driver);
}
static void __exit qec_exit(void)
{
platform_driver_unregister(&qec_sbus_driver);
while (root_qec_dev) {
struct sunqec *next = root_qec_dev->next_module;
struct platform_device *op = root_qec_dev->op;
free_irq(op->archdata.irqs[0], (void *) root_qec_dev);
of_iounmap(&op->resource[0], root_qec_dev->gregs,
GLOB_REG_SIZE);
kfree(root_qec_dev);
root_qec_dev = next;
}
}
