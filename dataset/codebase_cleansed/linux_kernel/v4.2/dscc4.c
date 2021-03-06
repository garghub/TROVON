static inline struct dscc4_dev_priv *dscc4_priv(struct net_device *dev)
{
return dev_to_hdlc(dev)->priv;
}
static inline struct net_device *dscc4_to_dev(struct dscc4_dev_priv *p)
{
return p->dev;
}
static void scc_patchl(u32 mask, u32 value, struct dscc4_dev_priv *dpriv,
struct net_device *dev, int offset)
{
u32 state;
state = dpriv->scc_regs[offset >> 2];
state &= ~mask;
state |= value;
dpriv->scc_regs[offset >> 2] = state;
writel(state, dpriv->base_addr + SCC_REG_START(dpriv) + offset);
}
static void scc_writel(u32 bits, struct dscc4_dev_priv *dpriv,
struct net_device *dev, int offset)
{
dpriv->scc_regs[offset >> 2] = bits;
writel(bits, dpriv->base_addr + SCC_REG_START(dpriv) + offset);
}
static inline u32 scc_readl(struct dscc4_dev_priv *dpriv, int offset)
{
return dpriv->scc_regs[offset >> 2];
}
static u32 scc_readl_star(struct dscc4_dev_priv *dpriv, struct net_device *dev)
{
readl(dpriv->base_addr + SCC_REG_START(dpriv) + STAR);
return readl(dpriv->base_addr + SCC_REG_START(dpriv) + STAR);
}
static inline void dscc4_do_tx(struct dscc4_dev_priv *dpriv,
struct net_device *dev)
{
dpriv->ltda = dpriv->tx_fd_dma +
((dpriv->tx_current-1)%TX_RING_SIZE)*sizeof(struct TxFD);
writel(dpriv->ltda, dpriv->base_addr + CH0LTDA + dpriv->dev_id*4);
readl(dpriv->base_addr + CH0LTDA + dpriv->dev_id*4);
}
static inline void dscc4_rx_update(struct dscc4_dev_priv *dpriv,
struct net_device *dev)
{
dpriv->lrda = dpriv->rx_fd_dma +
((dpriv->rx_dirty - 1)%RX_RING_SIZE)*sizeof(struct RxFD);
writel(dpriv->lrda, dpriv->base_addr + CH0LRDA + dpriv->dev_id*4);
}
static inline unsigned int dscc4_tx_done(struct dscc4_dev_priv *dpriv)
{
return dpriv->tx_current == dpriv->tx_dirty;
}
static inline unsigned int dscc4_tx_quiescent(struct dscc4_dev_priv *dpriv,
struct net_device *dev)
{
return readl(dpriv->base_addr + CH0FTDA + dpriv->dev_id*4) == dpriv->ltda;
}
static int state_check(u32 state, struct dscc4_dev_priv *dpriv,
struct net_device *dev, const char *msg)
{
int ret = 0;
if (debug > 1) {
if (SOURCE_ID(state) != dpriv->dev_id) {
printk(KERN_DEBUG "%s (%s): Source Id=%d, state=%08x\n",
dev->name, msg, SOURCE_ID(state), state );
ret = -1;
}
if (state & 0x0df80c00) {
printk(KERN_DEBUG "%s (%s): state=%08x (UFO alert)\n",
dev->name, msg, state);
ret = -1;
}
}
return ret;
}
static void dscc4_tx_print(struct net_device *dev,
struct dscc4_dev_priv *dpriv,
char *msg)
{
printk(KERN_DEBUG "%s: tx_current=%02d tx_dirty=%02d (%s)\n",
dev->name, dpriv->tx_current, dpriv->tx_dirty, msg);
}
static void dscc4_release_ring(struct dscc4_dev_priv *dpriv)
{
struct pci_dev *pdev = dpriv->pci_priv->pdev;
struct TxFD *tx_fd = dpriv->tx_fd;
struct RxFD *rx_fd = dpriv->rx_fd;
struct sk_buff **skbuff;
int i;
pci_free_consistent(pdev, TX_TOTAL_SIZE, tx_fd, dpriv->tx_fd_dma);
pci_free_consistent(pdev, RX_TOTAL_SIZE, rx_fd, dpriv->rx_fd_dma);
skbuff = dpriv->tx_skbuff;
for (i = 0; i < TX_RING_SIZE; i++) {
if (*skbuff) {
pci_unmap_single(pdev, le32_to_cpu(tx_fd->data),
(*skbuff)->len, PCI_DMA_TODEVICE);
dev_kfree_skb(*skbuff);
}
skbuff++;
tx_fd++;
}
skbuff = dpriv->rx_skbuff;
for (i = 0; i < RX_RING_SIZE; i++) {
if (*skbuff) {
pci_unmap_single(pdev, le32_to_cpu(rx_fd->data),
RX_MAX(HDLC_MAX_MRU), PCI_DMA_FROMDEVICE);
dev_kfree_skb(*skbuff);
}
skbuff++;
rx_fd++;
}
}
static inline int try_get_rx_skb(struct dscc4_dev_priv *dpriv,
struct net_device *dev)
{
unsigned int dirty = dpriv->rx_dirty%RX_RING_SIZE;
struct RxFD *rx_fd = dpriv->rx_fd + dirty;
const int len = RX_MAX(HDLC_MAX_MRU);
struct sk_buff *skb;
int ret = 0;
skb = dev_alloc_skb(len);
dpriv->rx_skbuff[dirty] = skb;
if (skb) {
skb->protocol = hdlc_type_trans(skb, dev);
rx_fd->data = cpu_to_le32(pci_map_single(dpriv->pci_priv->pdev,
skb->data, len, PCI_DMA_FROMDEVICE));
} else {
rx_fd->data = 0;
ret = -1;
}
return ret;
}
static int dscc4_wait_ack_cec(struct dscc4_dev_priv *dpriv,
struct net_device *dev, char *msg)
{
s8 i = 0;
do {
if (!(scc_readl_star(dpriv, dev) & SccBusy)) {
printk(KERN_DEBUG "%s: %s ack (%d try)\n", dev->name,
msg, i);
goto done;
}
schedule_timeout_uninterruptible(msecs_to_jiffies(100));
rmb();
} while (++i > 0);
netdev_err(dev, "%s timeout\n", msg);
done:
return (i >= 0) ? i : -EAGAIN;
}
static int dscc4_do_action(struct net_device *dev, char *msg)
{
void __iomem *ioaddr = dscc4_priv(dev)->base_addr;
s16 i = 0;
writel(Action, ioaddr + GCMDR);
ioaddr += GSTAR;
do {
u32 state = readl(ioaddr);
if (state & ArAck) {
netdev_dbg(dev, "%s ack\n", msg);
writel(ArAck, ioaddr);
goto done;
} else if (state & Arf) {
netdev_err(dev, "%s failed\n", msg);
writel(Arf, ioaddr);
i = -1;
goto done;
}
rmb();
} while (++i > 0);
netdev_err(dev, "%s timeout\n", msg);
done:
return i;
}
static inline int dscc4_xpr_ack(struct dscc4_dev_priv *dpriv)
{
int cur = dpriv->iqtx_current%IRQ_RING_SIZE;
s8 i = 0;
do {
if (!(dpriv->flags & (NeedIDR | NeedIDT)) ||
(dpriv->iqtx[cur] & cpu_to_le32(Xpr)))
break;
smp_rmb();
schedule_timeout_uninterruptible(msecs_to_jiffies(100));
} while (++i > 0);
return (i >= 0 ) ? i : -EAGAIN;
}
static inline void dscc4_rx_skb(struct dscc4_dev_priv *dpriv,
struct net_device *dev)
{
struct RxFD *rx_fd = dpriv->rx_fd + dpriv->rx_current%RX_RING_SIZE;
struct pci_dev *pdev = dpriv->pci_priv->pdev;
struct sk_buff *skb;
int pkt_len;
skb = dpriv->rx_skbuff[dpriv->rx_current++%RX_RING_SIZE];
if (!skb) {
printk(KERN_DEBUG "%s: skb=0 (%s)\n", dev->name, __func__);
goto refill;
}
pkt_len = TO_SIZE(le32_to_cpu(rx_fd->state2));
pci_unmap_single(pdev, le32_to_cpu(rx_fd->data),
RX_MAX(HDLC_MAX_MRU), PCI_DMA_FROMDEVICE);
if ((skb->data[--pkt_len] & FrameOk) == FrameOk) {
dev->stats.rx_packets++;
dev->stats.rx_bytes += pkt_len;
skb_put(skb, pkt_len);
if (netif_running(dev))
skb->protocol = hdlc_type_trans(skb, dev);
netif_rx(skb);
} else {
if (skb->data[pkt_len] & FrameRdo)
dev->stats.rx_fifo_errors++;
else if (!(skb->data[pkt_len] & FrameCrc))
dev->stats.rx_crc_errors++;
else if ((skb->data[pkt_len] & (FrameVfr | FrameRab)) !=
(FrameVfr | FrameRab))
dev->stats.rx_length_errors++;
dev->stats.rx_errors++;
dev_kfree_skb_irq(skb);
}
refill:
while ((dpriv->rx_dirty - dpriv->rx_current) % RX_RING_SIZE) {
if (try_get_rx_skb(dpriv, dev) < 0)
break;
dpriv->rx_dirty++;
}
dscc4_rx_update(dpriv, dev);
rx_fd->state2 = 0x00000000;
rx_fd->end = cpu_to_le32(0xbabeface);
}
static void dscc4_free1(struct pci_dev *pdev)
{
struct dscc4_pci_priv *ppriv;
struct dscc4_dev_priv *root;
int i;
ppriv = pci_get_drvdata(pdev);
root = ppriv->root;
for (i = 0; i < dev_per_card; i++)
unregister_hdlc_device(dscc4_to_dev(root + i));
for (i = 0; i < dev_per_card; i++)
free_netdev(root[i].dev);
kfree(root);
kfree(ppriv);
}
static int dscc4_init_one(struct pci_dev *pdev, const struct pci_device_id *ent)
{
struct dscc4_pci_priv *priv;
struct dscc4_dev_priv *dpriv;
void __iomem *ioaddr;
int i, rc;
printk(KERN_DEBUG "%s", version);
rc = pci_enable_device(pdev);
if (rc < 0)
goto out;
rc = pci_request_region(pdev, 0, "registers");
if (rc < 0) {
pr_err("can't reserve MMIO region (regs)\n");
goto err_disable_0;
}
rc = pci_request_region(pdev, 1, "LBI interface");
if (rc < 0) {
pr_err("can't reserve MMIO region (lbi)\n");
goto err_free_mmio_region_1;
}
ioaddr = pci_ioremap_bar(pdev, 0);
if (!ioaddr) {
pr_err("cannot remap MMIO region %llx @ %llx\n",
(unsigned long long)pci_resource_len(pdev, 0),
(unsigned long long)pci_resource_start(pdev, 0));
rc = -EIO;
goto err_free_mmio_regions_2;
}
printk(KERN_DEBUG "Siemens DSCC4, MMIO at %#llx (regs), %#llx (lbi), IRQ %d\n",
(unsigned long long)pci_resource_start(pdev, 0),
(unsigned long long)pci_resource_start(pdev, 1), pdev->irq);
pci_write_config_byte(pdev, PCI_LATENCY_TIMER, 0xf8);
pci_set_master(pdev);
rc = dscc4_found1(pdev, ioaddr);
if (rc < 0)
goto err_iounmap_3;
priv = pci_get_drvdata(pdev);
rc = request_irq(pdev->irq, dscc4_irq, IRQF_SHARED, DRV_NAME, priv->root);
if (rc < 0) {
pr_warn("IRQ %d busy\n", pdev->irq);
goto err_release_4;
}
writel(0x00000001, ioaddr + GMODE);
{
u32 bits;
bits = (IRQ_RING_SIZE >> 5) - 1;
bits |= bits << 4;
bits |= bits << 8;
bits |= bits << 16;
writel(bits, ioaddr + IQLENR0);
}
writel((u32)(((IRQ_RING_SIZE >> 5) - 1) << 20), ioaddr + IQLENR1);
rc = -ENOMEM;
priv->iqcfg = (__le32 *) pci_alloc_consistent(pdev,
IRQ_RING_SIZE*sizeof(__le32), &priv->iqcfg_dma);
if (!priv->iqcfg)
goto err_free_irq_5;
writel(priv->iqcfg_dma, ioaddr + IQCFG);
for (i = 0; i < dev_per_card; i++) {
dpriv = priv->root + i;
dpriv->iqtx = (__le32 *) pci_alloc_consistent(pdev,
IRQ_RING_SIZE*sizeof(u32), &dpriv->iqtx_dma);
if (!dpriv->iqtx)
goto err_free_iqtx_6;
writel(dpriv->iqtx_dma, ioaddr + IQTX0 + i*4);
}
for (i = 0; i < dev_per_card; i++) {
dpriv = priv->root + i;
dpriv->iqrx = (__le32 *) pci_alloc_consistent(pdev,
IRQ_RING_SIZE*sizeof(u32), &dpriv->iqrx_dma);
if (!dpriv->iqrx)
goto err_free_iqrx_7;
writel(dpriv->iqrx_dma, ioaddr + IQRX0 + i*4);
}
writel(0x42104000, ioaddr + FIFOCR1);
writel(0xdef6d800, ioaddr + FIFOCR2);
writel(0x18181818, ioaddr + FIFOCR4);
writel(0x0000000e, ioaddr + FIFOCR3);
writel(0xff200001, ioaddr + GCMDR);
rc = 0;
out:
return rc;
err_free_iqrx_7:
while (--i >= 0) {
dpriv = priv->root + i;
pci_free_consistent(pdev, IRQ_RING_SIZE*sizeof(u32),
dpriv->iqrx, dpriv->iqrx_dma);
}
i = dev_per_card;
err_free_iqtx_6:
while (--i >= 0) {
dpriv = priv->root + i;
pci_free_consistent(pdev, IRQ_RING_SIZE*sizeof(u32),
dpriv->iqtx, dpriv->iqtx_dma);
}
pci_free_consistent(pdev, IRQ_RING_SIZE*sizeof(u32), priv->iqcfg,
priv->iqcfg_dma);
err_free_irq_5:
free_irq(pdev->irq, priv->root);
err_release_4:
dscc4_free1(pdev);
err_iounmap_3:
iounmap (ioaddr);
err_free_mmio_regions_2:
pci_release_region(pdev, 1);
err_free_mmio_region_1:
pci_release_region(pdev, 0);
err_disable_0:
pci_disable_device(pdev);
goto out;
}
static void dscc4_init_registers(struct dscc4_dev_priv *dpriv,
struct net_device *dev)
{
scc_writel(0x00000000, dpriv, dev, CCR0);
scc_writel(LengthCheck | (HDLC_MAX_MRU >> 5), dpriv, dev, RLCR);
scc_writel(0x02408000, dpriv, dev, CCR1);
scc_writel(0x00050008 & ~RxActivate, dpriv, dev, CCR2);
}
static inline int dscc4_set_quartz(struct dscc4_dev_priv *dpriv, int hz)
{
int ret = 0;
if ((hz < 0) || (hz > DSCC4_HZ_MAX))
ret = -EOPNOTSUPP;
else
dpriv->pci_priv->xtal_hz = hz;
return ret;
}
static int dscc4_found1(struct pci_dev *pdev, void __iomem *ioaddr)
{
struct dscc4_pci_priv *ppriv;
struct dscc4_dev_priv *root;
int i, ret = -ENOMEM;
root = kcalloc(dev_per_card, sizeof(*root), GFP_KERNEL);
if (!root)
goto err_out;
for (i = 0; i < dev_per_card; i++) {
root[i].dev = alloc_hdlcdev(root + i);
if (!root[i].dev)
goto err_free_dev;
}
ppriv = kzalloc(sizeof(*ppriv), GFP_KERNEL);
if (!ppriv)
goto err_free_dev;
ppriv->root = root;
spin_lock_init(&ppriv->lock);
for (i = 0; i < dev_per_card; i++) {
struct dscc4_dev_priv *dpriv = root + i;
struct net_device *d = dscc4_to_dev(dpriv);
hdlc_device *hdlc = dev_to_hdlc(d);
d->base_addr = (unsigned long)ioaddr;
d->irq = pdev->irq;
d->netdev_ops = &dscc4_ops;
d->watchdog_timeo = TX_TIMEOUT;
SET_NETDEV_DEV(d, &pdev->dev);
dpriv->dev_id = i;
dpriv->pci_priv = ppriv;
dpriv->base_addr = ioaddr;
spin_lock_init(&dpriv->lock);
hdlc->xmit = dscc4_start_xmit;
hdlc->attach = dscc4_hdlc_attach;
dscc4_init_registers(dpriv, d);
dpriv->parity = PARITY_CRC16_PR0_CCITT;
dpriv->encoding = ENCODING_NRZ;
ret = dscc4_init_ring(d);
if (ret < 0)
goto err_unregister;
ret = register_hdlc_device(d);
if (ret < 0) {
pr_err("unable to register\n");
dscc4_release_ring(dpriv);
goto err_unregister;
}
}
ret = dscc4_set_quartz(root, quartz);
if (ret < 0)
goto err_unregister;
pci_set_drvdata(pdev, ppriv);
return ret;
err_unregister:
while (i-- > 0) {
dscc4_release_ring(root + i);
unregister_hdlc_device(dscc4_to_dev(root + i));
}
kfree(ppriv);
i = dev_per_card;
err_free_dev:
while (i-- > 0)
free_netdev(root[i].dev);
kfree(root);
err_out:
return ret;
}
static void dscc4_timer(unsigned long data)
{
struct net_device *dev = (struct net_device *)data;
struct dscc4_dev_priv *dpriv = dscc4_priv(dev);
goto done;
done:
dpriv->timer.expires = jiffies + TX_TIMEOUT;
add_timer(&dpriv->timer);
}
static void dscc4_tx_timeout(struct net_device *dev)
{
}
static int dscc4_loopback_check(struct dscc4_dev_priv *dpriv)
{
sync_serial_settings *settings = &dpriv->settings;
if (settings->loopback && (settings->clock_type != CLOCK_INT)) {
struct net_device *dev = dscc4_to_dev(dpriv);
netdev_info(dev, "loopback requires clock\n");
return -1;
}
return 0;
}
static void dscc4_pci_reset(struct pci_dev *pdev, void __iomem *ioaddr)
{
int i;
mutex_lock(&dscc4_mutex);
for (i = 0; i < 16; i++)
pci_read_config_dword(pdev, i << 2, dscc4_pci_config_store + i);
writel(0x001c0000, ioaddr + GMODE);
writel(0x0000ffff, ioaddr + GPDIR);
writel(0x0000ffff, ioaddr + GPIM);
writel(0x0000ffff, ioaddr + GPDATA);
writel(0x00000000, ioaddr + GPDATA);
readl(ioaddr + GSTAR);
schedule_timeout_uninterruptible(msecs_to_jiffies(100));
for (i = 0; i < 16; i++)
pci_write_config_dword(pdev, i << 2, dscc4_pci_config_store[i]);
mutex_unlock(&dscc4_mutex);
}
static int dscc4_open(struct net_device *dev)
{
struct dscc4_dev_priv *dpriv = dscc4_priv(dev);
int ret = -EAGAIN;
if ((dscc4_loopback_check(dpriv) < 0))
goto err;
if ((ret = hdlc_open(dev)))
goto err;
if (dpriv->flags & FakeReset) {
dpriv->flags &= ~FakeReset;
scc_patchl(0, PowerUp, dpriv, dev, CCR0);
scc_patchl(0, 0x00050000, dpriv, dev, CCR2);
scc_writel(EventsMask, dpriv, dev, IMR);
netdev_info(dev, "up again\n");
goto done;
}
dpriv->flags = NeedIDR | NeedIDT;
scc_patchl(0, PowerUp | Vis, dpriv, dev, CCR0);
if (scc_readl_star(dpriv, dev) & SccBusy) {
netdev_err(dev, "busy - try later\n");
ret = -EAGAIN;
goto err_out;
} else
netdev_info(dev, "available - good\n");
scc_writel(EventsMask, dpriv, dev, IMR);
scc_writel(TxSccRes | RxSccRes, dpriv, dev, CMDR);
if ((ret = dscc4_wait_ack_cec(dpriv, dev, "Cec")) < 0)
goto err_disable_scc_events;
if ((ret = dscc4_xpr_ack(dpriv)) < 0) {
pr_err("XPR timeout\n");
goto err_disable_scc_events;
}
if (debug > 2)
dscc4_tx_print(dev, dpriv, "Open");
done:
netif_start_queue(dev);
init_timer(&dpriv->timer);
dpriv->timer.expires = jiffies + 10*HZ;
dpriv->timer.data = (unsigned long)dev;
dpriv->timer.function = dscc4_timer;
add_timer(&dpriv->timer);
netif_carrier_on(dev);
return 0;
err_disable_scc_events:
scc_writel(0xffffffff, dpriv, dev, IMR);
scc_patchl(PowerUp | Vis, 0, dpriv, dev, CCR0);
err_out:
hdlc_close(dev);
err:
return ret;
}
static int dscc4_tx_poll(struct dscc4_dev_priv *dpriv, struct net_device *dev)
{
}
static netdev_tx_t dscc4_start_xmit(struct sk_buff *skb,
struct net_device *dev)
{
struct dscc4_dev_priv *dpriv = dscc4_priv(dev);
struct dscc4_pci_priv *ppriv = dpriv->pci_priv;
struct TxFD *tx_fd;
int next;
next = dpriv->tx_current%TX_RING_SIZE;
dpriv->tx_skbuff[next] = skb;
tx_fd = dpriv->tx_fd + next;
tx_fd->state = FrameEnd | TO_STATE_TX(skb->len);
tx_fd->data = cpu_to_le32(pci_map_single(ppriv->pdev, skb->data, skb->len,
PCI_DMA_TODEVICE));
tx_fd->complete = 0x00000000;
tx_fd->jiffies = jiffies;
mb();
#ifdef DSCC4_POLLING
spin_lock(&dpriv->lock);
while (dscc4_tx_poll(dpriv, dev));
spin_unlock(&dpriv->lock);
#endif
if (debug > 2)
dscc4_tx_print(dev, dpriv, "Xmit");
if (!((++dpriv->tx_current - dpriv->tx_dirty)%TX_RING_SIZE))
netif_stop_queue(dev);
if (dscc4_tx_quiescent(dpriv, dev))
dscc4_do_tx(dpriv, dev);
return NETDEV_TX_OK;
}
static int dscc4_close(struct net_device *dev)
{
struct dscc4_dev_priv *dpriv = dscc4_priv(dev);
del_timer_sync(&dpriv->timer);
netif_stop_queue(dev);
scc_patchl(PowerUp | Vis, 0, dpriv, dev, CCR0);
scc_patchl(0x00050000, 0, dpriv, dev, CCR2);
scc_writel(0xffffffff, dpriv, dev, IMR);
dpriv->flags |= FakeReset;
hdlc_close(dev);
return 0;
}
static inline int dscc4_check_clock_ability(int port)
{
int ret = 0;
#ifdef CONFIG_DSCC4_PCISYNC
if (port >= 2)
ret = -1;
#endif
return ret;
}
static int dscc4_set_clock(struct net_device *dev, u32 *bps, u32 *state)
{
struct dscc4_dev_priv *dpriv = dscc4_priv(dev);
int ret = -1;
u32 brr;
*state &= ~Ccr0ClockMask;
if (*bps) {
u32 n = 0, m = 0, divider;
int xtal;
xtal = dpriv->pci_priv->xtal_hz;
if (!xtal)
goto done;
if (dscc4_check_clock_ability(dpriv->dev_id) < 0)
goto done;
divider = xtal / *bps;
if (divider > BRR_DIVIDER_MAX) {
divider >>= 4;
*state |= 0x00000036;
} else
*state |= 0x00000037;
if (divider >> 22) {
n = 63;
m = 15;
} else if (divider) {
m = 0;
while (0xffffffc0 & divider) {
m++;
divider >>= 1;
}
n = divider;
}
brr = (m << 8) | n;
divider = n << m;
if (!(*state & 0x00000001))
divider <<= 4;
*bps = xtal / divider;
} else {
brr = 0;
}
scc_writel(brr, dpriv, dev, BRR);
ret = 0;
done:
return ret;
}
static int dscc4_ioctl(struct net_device *dev, struct ifreq *ifr, int cmd)
{
sync_serial_settings __user *line = ifr->ifr_settings.ifs_ifsu.sync;
struct dscc4_dev_priv *dpriv = dscc4_priv(dev);
const size_t size = sizeof(dpriv->settings);
int ret = 0;
if (dev->flags & IFF_UP)
return -EBUSY;
if (cmd != SIOCWANDEV)
return -EOPNOTSUPP;
switch(ifr->ifr_settings.type) {
case IF_GET_IFACE:
ifr->ifr_settings.type = IF_IFACE_SYNC_SERIAL;
if (ifr->ifr_settings.size < size) {
ifr->ifr_settings.size = size;
return -ENOBUFS;
}
if (copy_to_user(line, &dpriv->settings, size))
return -EFAULT;
break;
case IF_IFACE_SYNC_SERIAL:
if (!capable(CAP_NET_ADMIN))
return -EPERM;
if (dpriv->flags & FakeReset) {
netdev_info(dev, "please reset the device before this command\n");
return -EPERM;
}
if (copy_from_user(&dpriv->settings, line, size))
return -EFAULT;
ret = dscc4_set_iface(dpriv, dev);
break;
default:
ret = hdlc_ioctl(dev, ifr, cmd);
break;
}
return ret;
}
static int dscc4_match(const struct thingie *p, int value)
{
int i;
for (i = 0; p[i].define != -1; i++) {
if (value == p[i].define)
break;
}
if (p[i].define == -1)
return -1;
else
return i;
}
static int dscc4_clock_setting(struct dscc4_dev_priv *dpriv,
struct net_device *dev)
{
sync_serial_settings *settings = &dpriv->settings;
int ret = -EOPNOTSUPP;
u32 bps, state;
bps = settings->clock_rate;
state = scc_readl(dpriv, CCR0);
if (dscc4_set_clock(dev, &bps, &state) < 0)
goto done;
if (bps) {
printk(KERN_DEBUG "%s: generated RxClk (DCE)\n", dev->name);
if (settings->clock_rate != bps) {
printk(KERN_DEBUG "%s: clock adjusted (%08d -> %08d)\n",
dev->name, settings->clock_rate, bps);
settings->clock_rate = bps;
}
} else {
state |= PowerUp | Vis;
printk(KERN_DEBUG "%s: external RxClk (DTE)\n", dev->name);
}
scc_writel(state, dpriv, dev, CCR0);
ret = 0;
done:
return ret;
}
static int dscc4_encoding_setting(struct dscc4_dev_priv *dpriv,
struct net_device *dev)
{
static const struct thingie encoding[] = {
{ ENCODING_NRZ, 0x00000000 },
{ ENCODING_NRZI, 0x00200000 },
{ ENCODING_FM_MARK, 0x00400000 },
{ ENCODING_FM_SPACE, 0x00500000 },
{ ENCODING_MANCHESTER, 0x00600000 },
{ -1, 0}
};
int i, ret = 0;
i = dscc4_match(encoding, dpriv->encoding);
if (i >= 0)
scc_patchl(EncodingMask, encoding[i].bits, dpriv, dev, CCR0);
else
ret = -EOPNOTSUPP;
return ret;
}
static int dscc4_loopback_setting(struct dscc4_dev_priv *dpriv,
struct net_device *dev)
{
sync_serial_settings *settings = &dpriv->settings;
u32 state;
state = scc_readl(dpriv, CCR1);
if (settings->loopback) {
printk(KERN_DEBUG "%s: loopback\n", dev->name);
state |= 0x00000100;
} else {
printk(KERN_DEBUG "%s: normal\n", dev->name);
state &= ~0x00000100;
}
scc_writel(state, dpriv, dev, CCR1);
return 0;
}
static int dscc4_crc_setting(struct dscc4_dev_priv *dpriv,
struct net_device *dev)
{
static const struct thingie crc[] = {
{ PARITY_CRC16_PR0_CCITT, 0x00000010 },
{ PARITY_CRC16_PR1_CCITT, 0x00000000 },
{ PARITY_CRC32_PR0_CCITT, 0x00000011 },
{ PARITY_CRC32_PR1_CCITT, 0x00000001 }
};
int i, ret = 0;
i = dscc4_match(crc, dpriv->parity);
if (i >= 0)
scc_patchl(CrcMask, crc[i].bits, dpriv, dev, CCR1);
else
ret = -EOPNOTSUPP;
return ret;
}
static int dscc4_set_iface(struct dscc4_dev_priv *dpriv, struct net_device *dev)
{
struct {
int (*action)(struct dscc4_dev_priv *, struct net_device *);
} *p, do_setting[] = {
{ dscc4_encoding_setting },
{ dscc4_clock_setting },
{ dscc4_loopback_setting },
{ dscc4_crc_setting },
{ NULL }
};
int ret = 0;
for (p = do_setting; p->action; p++) {
if ((ret = p->action(dpriv, dev)) < 0)
break;
}
return ret;
}
static irqreturn_t dscc4_irq(int irq, void *token)
{
struct dscc4_dev_priv *root = token;
struct dscc4_pci_priv *priv;
struct net_device *dev;
void __iomem *ioaddr;
u32 state;
unsigned long flags;
int i, handled = 1;
priv = root->pci_priv;
dev = dscc4_to_dev(root);
spin_lock_irqsave(&priv->lock, flags);
ioaddr = root->base_addr;
state = readl(ioaddr + GSTAR);
if (!state) {
handled = 0;
goto out;
}
if (debug > 3)
printk(KERN_DEBUG "%s: GSTAR = 0x%08x\n", DRV_NAME, state);
writel(state, ioaddr + GSTAR);
if (state & Arf) {
netdev_err(dev, "failure (Arf). Harass the maintainer\n");
goto out;
}
state &= ~ArAck;
if (state & Cfg) {
if (debug > 0)
printk(KERN_DEBUG "%s: CfgIV\n", DRV_NAME);
if (priv->iqcfg[priv->cfg_cur++%IRQ_RING_SIZE] & cpu_to_le32(Arf))
netdev_err(dev, "CFG failed\n");
if (!(state &= ~Cfg))
goto out;
}
if (state & RxEvt) {
i = dev_per_card - 1;
do {
dscc4_rx_irq(priv, root + i);
} while (--i >= 0);
state &= ~RxEvt;
}
if (state & TxEvt) {
i = dev_per_card - 1;
do {
dscc4_tx_irq(priv, root + i);
} while (--i >= 0);
state &= ~TxEvt;
}
out:
spin_unlock_irqrestore(&priv->lock, flags);
return IRQ_RETVAL(handled);
}
static void dscc4_tx_irq(struct dscc4_pci_priv *ppriv,
struct dscc4_dev_priv *dpriv)
{
struct net_device *dev = dscc4_to_dev(dpriv);
u32 state;
int cur, loop = 0;
try:
cur = dpriv->iqtx_current%IRQ_RING_SIZE;
state = le32_to_cpu(dpriv->iqtx[cur]);
if (!state) {
if (debug > 4)
printk(KERN_DEBUG "%s: Tx ISR = 0x%08x\n", dev->name,
state);
if ((debug > 1) && (loop > 1))
printk(KERN_DEBUG "%s: Tx irq loop=%d\n", dev->name, loop);
if (loop && netif_queue_stopped(dev))
if ((dpriv->tx_current - dpriv->tx_dirty)%TX_RING_SIZE)
netif_wake_queue(dev);
if (netif_running(dev) && dscc4_tx_quiescent(dpriv, dev) &&
!dscc4_tx_done(dpriv))
dscc4_do_tx(dpriv, dev);
return;
}
loop++;
dpriv->iqtx[cur] = 0;
dpriv->iqtx_current++;
if (state_check(state, dpriv, dev, "Tx") < 0)
return;
if (state & SccEvt) {
if (state & Alls) {
struct sk_buff *skb;
struct TxFD *tx_fd;
if (debug > 2)
dscc4_tx_print(dev, dpriv, "Alls");
cur = dpriv->tx_dirty%TX_RING_SIZE;
tx_fd = dpriv->tx_fd + cur;
skb = dpriv->tx_skbuff[cur];
if (skb) {
pci_unmap_single(ppriv->pdev, le32_to_cpu(tx_fd->data),
skb->len, PCI_DMA_TODEVICE);
if (tx_fd->state & FrameEnd) {
dev->stats.tx_packets++;
dev->stats.tx_bytes += skb->len;
}
dev_kfree_skb_irq(skb);
dpriv->tx_skbuff[cur] = NULL;
++dpriv->tx_dirty;
} else {
if (debug > 1)
netdev_err(dev, "Tx: NULL skb %d\n",
cur);
}
tx_fd->data = tx_fd->next;
tx_fd->state = FrameEnd | TO_STATE_TX(2*DUMMY_SKB_SIZE);
tx_fd->complete = 0x00000000;
tx_fd->jiffies = 0;
if (!(state &= ~Alls))
goto try;
}
if (state & Xdu) {
netdev_err(dev, "Tx Data Underrun. Ask maintainer\n");
dpriv->flags = NeedIDT;
writel(MTFi | Rdt,
dpriv->base_addr + 0x0c*dpriv->dev_id + CH0CFG);
writel(Action, dpriv->base_addr + GCMDR);
return;
}
if (state & Cts) {
netdev_info(dev, "CTS transition\n");
if (!(state &= ~Cts))
goto try;
}
if (state & Xmr) {
netdev_err(dev, "Tx ReTx. Ask maintainer\n");
if (!(state &= ~Xmr))
goto try;
}
if (state & Xpr) {
void __iomem *scc_addr;
unsigned long ring;
int i;
for (i = 1; i; i <<= 1) {
if (!(scc_readl_star(dpriv, dev) & SccBusy))
break;
}
if (!i)
netdev_info(dev, "busy in irq\n");
scc_addr = dpriv->base_addr + 0x0c*dpriv->dev_id;
if (dpriv->flags & NeedIDT) {
if (debug > 2)
dscc4_tx_print(dev, dpriv, "Xpr");
ring = dpriv->tx_fd_dma +
(dpriv->tx_dirty%TX_RING_SIZE)*
sizeof(struct TxFD);
writel(ring, scc_addr + CH0BTDA);
dscc4_do_tx(dpriv, dev);
writel(MTFi | Idt, scc_addr + CH0CFG);
if (dscc4_do_action(dev, "IDT") < 0)
goto err_xpr;
dpriv->flags &= ~NeedIDT;
}
if (dpriv->flags & NeedIDR) {
ring = dpriv->rx_fd_dma +
(dpriv->rx_current%RX_RING_SIZE)*
sizeof(struct RxFD);
writel(ring, scc_addr + CH0BRDA);
dscc4_rx_update(dpriv, dev);
writel(MTFi | Idr, scc_addr + CH0CFG);
if (dscc4_do_action(dev, "IDR") < 0)
goto err_xpr;
dpriv->flags &= ~NeedIDR;
smp_wmb();
scc_writel(0x08050008, dpriv, dev, CCR2);
}
err_xpr:
if (!(state &= ~Xpr))
goto try;
}
if (state & Cd) {
if (debug > 0)
netdev_info(dev, "CD transition\n");
if (!(state &= ~Cd))
goto try;
}
} else {
if (state & Hi) {
#ifdef DSCC4_POLLING
while (!dscc4_tx_poll(dpriv, dev));
#endif
netdev_info(dev, "Tx Hi\n");
state &= ~Hi;
}
if (state & Err) {
netdev_info(dev, "Tx ERR\n");
dev->stats.tx_errors++;
state &= ~Err;
}
}
goto try;
}
static void dscc4_rx_irq(struct dscc4_pci_priv *priv,
struct dscc4_dev_priv *dpriv)
{
struct net_device *dev = dscc4_to_dev(dpriv);
u32 state;
int cur;
try:
cur = dpriv->iqrx_current%IRQ_RING_SIZE;
state = le32_to_cpu(dpriv->iqrx[cur]);
if (!state)
return;
dpriv->iqrx[cur] = 0;
dpriv->iqrx_current++;
if (state_check(state, dpriv, dev, "Rx") < 0)
return;
if (!(state & SccEvt)){
struct RxFD *rx_fd;
if (debug > 4)
printk(KERN_DEBUG "%s: Rx ISR = 0x%08x\n", dev->name,
state);
state &= 0x00ffffff;
if (state & Err) {
printk(KERN_DEBUG "%s: Rx ERR\n", dev->name);
cur = dpriv->rx_current%RX_RING_SIZE;
rx_fd = dpriv->rx_fd + cur;
while (!(rx_fd->state1 & Hold)) {
rx_fd++;
cur++;
if (!(cur = cur%RX_RING_SIZE))
rx_fd = dpriv->rx_fd;
}
try_get_rx_skb(dpriv, dev);
if (!rx_fd->data)
goto try;
rx_fd->state1 &= ~Hold;
rx_fd->state2 = 0x00000000;
rx_fd->end = cpu_to_le32(0xbabeface);
goto try;
}
if (state & Fi) {
dscc4_rx_skb(dpriv, dev);
goto try;
}
if (state & Hi ) {
netdev_info(dev, "Rx Hi\n");
state &= ~Hi;
goto try;
}
} else {
if (debug > 1) {
static struct {
u32 mask;
const char *irq_name;
} evts[] = {
{ 0x00008000, "TIN"},
{ 0x00000020, "RSC"},
{ 0x00000010, "PCE"},
{ 0x00000008, "PLLA"},
{ 0, NULL}
}, *evt;
for (evt = evts; evt->irq_name; evt++) {
if (state & evt->mask) {
printk(KERN_DEBUG "%s: %s\n",
dev->name, evt->irq_name);
if (!(state &= ~evt->mask))
goto try;
}
}
} else {
if (!(state &= ~0x0000c03c))
goto try;
}
if (state & Cts) {
netdev_info(dev, "CTS transition\n");
if (!(state &= ~Cts))
goto try;
}
if (state & Rdo) {
struct RxFD *rx_fd;
void __iomem *scc_addr;
int cur;
scc_addr = dpriv->base_addr + 0x0c*dpriv->dev_id;
scc_patchl(RxActivate, 0, dpriv, dev, CCR2);
scc_writel(RxSccRes, dpriv, dev, CMDR);
dpriv->flags |= RdoSet;
do {
cur = dpriv->rx_current++%RX_RING_SIZE;
rx_fd = dpriv->rx_fd + cur;
if (!(rx_fd->state2 & DataComplete))
break;
if (rx_fd->state2 & FrameAborted) {
dev->stats.rx_over_errors++;
rx_fd->state1 |= Hold;
rx_fd->state2 = 0x00000000;
rx_fd->end = cpu_to_le32(0xbabeface);
} else
dscc4_rx_skb(dpriv, dev);
} while (1);
if (debug > 0) {
if (dpriv->flags & RdoSet)
printk(KERN_DEBUG
"%s: no RDO in Rx data\n", DRV_NAME);
}
#ifdef DSCC4_RDO_EXPERIMENTAL_RECOVERY
#warning "FIXME: CH0BRDA"
writel(dpriv->rx_fd_dma +
(dpriv->rx_current%RX_RING_SIZE)*
sizeof(struct RxFD), scc_addr + CH0BRDA);
writel(MTFi|Rdr|Idr, scc_addr + CH0CFG);
if (dscc4_do_action(dev, "RDR") < 0) {
netdev_err(dev, "RDO recovery failed(RDR)\n");
goto rdo_end;
}
writel(MTFi|Idr, scc_addr + CH0CFG);
if (dscc4_do_action(dev, "IDR") < 0) {
netdev_err(dev, "RDO recovery failed(IDR)\n");
goto rdo_end;
}
rdo_end:
#endif
scc_patchl(0, RxActivate, dpriv, dev, CCR2);
goto try;
}
if (state & Cd) {
netdev_info(dev, "CD transition\n");
if (!(state &= ~Cd))
goto try;
}
if (state & Flex) {
printk(KERN_DEBUG "%s: Flex. Ttttt...\n", DRV_NAME);
if (!(state &= ~Flex))
goto try;
}
}
}
static struct sk_buff *dscc4_init_dummy_skb(struct dscc4_dev_priv *dpriv)
{
struct sk_buff *skb;
skb = dev_alloc_skb(DUMMY_SKB_SIZE);
if (skb) {
int last = dpriv->tx_dirty%TX_RING_SIZE;
struct TxFD *tx_fd = dpriv->tx_fd + last;
skb->len = DUMMY_SKB_SIZE;
skb_copy_to_linear_data(skb, version,
strlen(version) % DUMMY_SKB_SIZE);
tx_fd->state = FrameEnd | TO_STATE_TX(DUMMY_SKB_SIZE);
tx_fd->data = cpu_to_le32(pci_map_single(dpriv->pci_priv->pdev,
skb->data, DUMMY_SKB_SIZE,
PCI_DMA_TODEVICE));
dpriv->tx_skbuff[last] = skb;
}
return skb;
}
static int dscc4_init_ring(struct net_device *dev)
{
struct dscc4_dev_priv *dpriv = dscc4_priv(dev);
struct pci_dev *pdev = dpriv->pci_priv->pdev;
struct TxFD *tx_fd;
struct RxFD *rx_fd;
void *ring;
int i;
ring = pci_alloc_consistent(pdev, RX_TOTAL_SIZE, &dpriv->rx_fd_dma);
if (!ring)
goto err_out;
dpriv->rx_fd = rx_fd = (struct RxFD *) ring;
ring = pci_alloc_consistent(pdev, TX_TOTAL_SIZE, &dpriv->tx_fd_dma);
if (!ring)
goto err_free_dma_rx;
dpriv->tx_fd = tx_fd = (struct TxFD *) ring;
memset(dpriv->tx_skbuff, 0, sizeof(struct sk_buff *)*TX_RING_SIZE);
dpriv->tx_dirty = 0xffffffff;
i = dpriv->tx_current = 0;
do {
tx_fd->state = FrameEnd | TO_STATE_TX(2*DUMMY_SKB_SIZE);
tx_fd->complete = 0x00000000;
tx_fd->data = cpu_to_le32(dpriv->tx_fd_dma);
(tx_fd++)->next = cpu_to_le32(dpriv->tx_fd_dma +
(++i%TX_RING_SIZE)*sizeof(*tx_fd));
} while (i < TX_RING_SIZE);
if (!dscc4_init_dummy_skb(dpriv))
goto err_free_dma_tx;
memset(dpriv->rx_skbuff, 0, sizeof(struct sk_buff *)*RX_RING_SIZE);
i = dpriv->rx_dirty = dpriv->rx_current = 0;
do {
rx_fd->state1 = HiDesc;
rx_fd->state2 = 0x00000000;
rx_fd->end = cpu_to_le32(0xbabeface);
rx_fd->state1 |= TO_STATE_RX(HDLC_MAX_MRU);
if (try_get_rx_skb(dpriv, dev) >= 0)
dpriv->rx_dirty++;
(rx_fd++)->next = cpu_to_le32(dpriv->rx_fd_dma +
(++i%RX_RING_SIZE)*sizeof(*rx_fd));
} while (i < RX_RING_SIZE);
return 0;
err_free_dma_tx:
pci_free_consistent(pdev, TX_TOTAL_SIZE, ring, dpriv->tx_fd_dma);
err_free_dma_rx:
pci_free_consistent(pdev, RX_TOTAL_SIZE, rx_fd, dpriv->rx_fd_dma);
err_out:
return -ENOMEM;
}
static void dscc4_remove_one(struct pci_dev *pdev)
{
struct dscc4_pci_priv *ppriv;
struct dscc4_dev_priv *root;
void __iomem *ioaddr;
int i;
ppriv = pci_get_drvdata(pdev);
root = ppriv->root;
ioaddr = root->base_addr;
dscc4_pci_reset(pdev, ioaddr);
free_irq(pdev->irq, root);
pci_free_consistent(pdev, IRQ_RING_SIZE*sizeof(u32), ppriv->iqcfg,
ppriv->iqcfg_dma);
for (i = 0; i < dev_per_card; i++) {
struct dscc4_dev_priv *dpriv = root + i;
dscc4_release_ring(dpriv);
pci_free_consistent(pdev, IRQ_RING_SIZE*sizeof(u32),
dpriv->iqrx, dpriv->iqrx_dma);
pci_free_consistent(pdev, IRQ_RING_SIZE*sizeof(u32),
dpriv->iqtx, dpriv->iqtx_dma);
}
dscc4_free1(pdev);
iounmap(ioaddr);
pci_release_region(pdev, 1);
pci_release_region(pdev, 0);
pci_disable_device(pdev);
}
static int dscc4_hdlc_attach(struct net_device *dev, unsigned short encoding,
unsigned short parity)
{
struct dscc4_dev_priv *dpriv = dscc4_priv(dev);
if (encoding != ENCODING_NRZ &&
encoding != ENCODING_NRZI &&
encoding != ENCODING_FM_MARK &&
encoding != ENCODING_FM_SPACE &&
encoding != ENCODING_MANCHESTER)
return -EINVAL;
if (parity != PARITY_NONE &&
parity != PARITY_CRC16_PR0_CCITT &&
parity != PARITY_CRC16_PR1_CCITT &&
parity != PARITY_CRC32_PR0_CCITT &&
parity != PARITY_CRC32_PR1_CCITT)
return -EINVAL;
dpriv->encoding = encoding;
dpriv->parity = parity;
return 0;
}
static int __init dscc4_setup(char *str)
{
int *args[] = { &debug, &quartz, NULL }, **p = args;
while (*p && (get_option(&str, *p) == 2))
p++;
return 1;
}
