static int netdev_vlan_rx_add_vid(struct net_device *dev,
__be16 proto, u16 vid)
{
struct netdev_private *np = netdev_priv(dev);
spin_lock(&np->lock);
if (debug > 1)
printk("%s: Adding vlanid %d to vlan filter\n", dev->name, vid);
set_bit(vid, np->active_vlans);
set_rx_mode(dev);
spin_unlock(&np->lock);
return 0;
}
static int netdev_vlan_rx_kill_vid(struct net_device *dev,
__be16 proto, u16 vid)
{
struct netdev_private *np = netdev_priv(dev);
spin_lock(&np->lock);
if (debug > 1)
printk("%s: removing vlanid %d from vlan filter\n", dev->name, vid);
clear_bit(vid, np->active_vlans);
set_rx_mode(dev);
spin_unlock(&np->lock);
return 0;
}
static int starfire_init_one(struct pci_dev *pdev,
const struct pci_device_id *ent)
{
struct device *d = &pdev->dev;
struct netdev_private *np;
int i, irq, chip_idx = ent->driver_data;
struct net_device *dev;
long ioaddr;
void __iomem *base;
int drv_flags, io_size;
int boguscnt;
#ifndef MODULE
static int printed_version;
if (!printed_version++)
printk(version);
#endif
if (pci_enable_device (pdev))
return -EIO;
ioaddr = pci_resource_start(pdev, 0);
io_size = pci_resource_len(pdev, 0);
if (!ioaddr || ((pci_resource_flags(pdev, 0) & IORESOURCE_MEM) == 0)) {
dev_err(d, "no PCI MEM resources, aborting\n");
return -ENODEV;
}
dev = alloc_etherdev(sizeof(*np));
if (!dev)
return -ENOMEM;
SET_NETDEV_DEV(dev, &pdev->dev);
irq = pdev->irq;
if (pci_request_regions (pdev, DRV_NAME)) {
dev_err(d, "cannot reserve PCI resources, aborting\n");
goto err_out_free_netdev;
}
base = ioremap(ioaddr, io_size);
if (!base) {
dev_err(d, "cannot remap %#x @ %#lx, aborting\n",
io_size, ioaddr);
goto err_out_free_res;
}
pci_set_master(pdev);
pci_try_set_mwi(pdev);
#ifdef ZEROCOPY
if (enable_hw_cksum)
dev->features |= NETIF_F_IP_CSUM | NETIF_F_SG;
#endif
#ifdef VLAN_SUPPORT
dev->features |= NETIF_F_HW_VLAN_CTAG_RX | NETIF_F_HW_VLAN_CTAG_FILTER;
#endif
#ifdef ADDR_64BITS
dev->features |= NETIF_F_HIGHDMA;
#endif
for (i = 0; i < 6; i++)
dev->dev_addr[i] = readb(base + EEPROMCtrl + 20 - i);
#if ! defined(final_version)
if (debug > 4)
for (i = 0; i < 0x20; i++)
printk("%2.2x%s",
(unsigned int)readb(base + EEPROMCtrl + i),
i % 16 != 15 ? " " : "\n");
#endif
writel(MiiSoftReset, base + TxMode);
udelay(1000);
writel(0, base + TxMode);
writel(1, base + PCIDeviceConfig);
boguscnt = 1000;
while (--boguscnt > 0) {
udelay(10);
if ((readl(base + PCIDeviceConfig) & 1) == 0)
break;
}
if (boguscnt == 0)
printk("%s: chipset reset never completed!\n", dev->name);
udelay(1000);
np = netdev_priv(dev);
np->dev = dev;
np->base = base;
spin_lock_init(&np->lock);
pci_set_drvdata(pdev, dev);
np->pci_dev = pdev;
np->mii_if.dev = dev;
np->mii_if.mdio_read = mdio_read;
np->mii_if.mdio_write = mdio_write;
np->mii_if.phy_id_mask = 0x1f;
np->mii_if.reg_num_mask = 0x1f;
drv_flags = netdrv_tbl[chip_idx].drv_flags;
np->speed100 = 1;
np->intr_timer_ctrl = (((intr_latency * 10) / 1024) & IntrLatencyMask) |
Timer10X | EnableIntrMasking;
if (small_frames > 0) {
np->intr_timer_ctrl |= SmallFrameBypass;
switch (small_frames) {
case 1 ... 64:
np->intr_timer_ctrl |= SmallFrame64;
break;
case 65 ... 128:
np->intr_timer_ctrl |= SmallFrame128;
break;
case 129 ... 256:
np->intr_timer_ctrl |= SmallFrame256;
break;
default:
np->intr_timer_ctrl |= SmallFrame512;
if (small_frames > 512)
printk("Adjusting small_frames down to 512\n");
break;
}
}
dev->netdev_ops = &netdev_ops;
dev->watchdog_timeo = TX_TIMEOUT;
SET_ETHTOOL_OPS(dev, &ethtool_ops);
netif_napi_add(dev, &np->napi, netdev_poll, max_interrupt_work);
if (mtu)
dev->mtu = mtu;
if (register_netdev(dev))
goto err_out_cleardev;
printk(KERN_INFO "%s: %s at %p, %pM, IRQ %d.\n",
dev->name, netdrv_tbl[chip_idx].name, base,
dev->dev_addr, irq);
if (drv_flags & CanHaveMII) {
int phy, phy_idx = 0;
int mii_status;
for (phy = 0; phy < 32 && phy_idx < PHY_CNT; phy++) {
mdio_write(dev, phy, MII_BMCR, BMCR_RESET);
mdelay(100);
boguscnt = 1000;
while (--boguscnt > 0)
if ((mdio_read(dev, phy, MII_BMCR) & BMCR_RESET) == 0)
break;
if (boguscnt == 0) {
printk("%s: PHY#%d reset never completed!\n", dev->name, phy);
continue;
}
mii_status = mdio_read(dev, phy, MII_BMSR);
if (mii_status != 0) {
np->phys[phy_idx++] = phy;
np->mii_if.advertising = mdio_read(dev, phy, MII_ADVERTISE);
printk(KERN_INFO "%s: MII PHY found at address %d, status "
"%#4.4x advertising %#4.4x.\n",
dev->name, phy, mii_status, np->mii_if.advertising);
break;
}
}
np->phy_cnt = phy_idx;
if (np->phy_cnt > 0)
np->mii_if.phy_id = np->phys[0];
else
memset(&np->mii_if, 0, sizeof(np->mii_if));
}
printk(KERN_INFO "%s: scatter-gather and hardware TCP cksumming %s.\n",
dev->name, enable_hw_cksum ? "enabled" : "disabled");
return 0;
err_out_cleardev:
pci_set_drvdata(pdev, NULL);
iounmap(base);
err_out_free_res:
pci_release_regions (pdev);
err_out_free_netdev:
free_netdev(dev);
return -ENODEV;
}
static int mdio_read(struct net_device *dev, int phy_id, int location)
{
struct netdev_private *np = netdev_priv(dev);
void __iomem *mdio_addr = np->base + MIICtrl + (phy_id<<7) + (location<<2);
int result, boguscnt=1000;
do {
result = readl(mdio_addr);
} while ((result & 0xC0000000) != 0x80000000 && --boguscnt > 0);
if (boguscnt == 0)
return 0;
if ((result & 0xffff) == 0xffff)
return 0;
return result & 0xffff;
}
static void mdio_write(struct net_device *dev, int phy_id, int location, int value)
{
struct netdev_private *np = netdev_priv(dev);
void __iomem *mdio_addr = np->base + MIICtrl + (phy_id<<7) + (location<<2);
writel(value, mdio_addr);
}
static int netdev_open(struct net_device *dev)
{
const struct firmware *fw_rx, *fw_tx;
const __be32 *fw_rx_data, *fw_tx_data;
struct netdev_private *np = netdev_priv(dev);
void __iomem *ioaddr = np->base;
const int irq = np->pci_dev->irq;
int i, retval;
size_t tx_size, rx_size;
size_t tx_done_q_size, rx_done_q_size, tx_ring_size, rx_ring_size;
retval = request_irq(irq, intr_handler, IRQF_SHARED, dev->name, dev);
if (retval)
return retval;
writel(0, ioaddr + GenCtrl);
writel(1, ioaddr + PCIDeviceConfig);
if (debug > 1)
printk(KERN_DEBUG "%s: netdev_open() irq %d.\n",
dev->name, irq);
if (!np->queue_mem) {
tx_done_q_size = ((sizeof(struct tx_done_desc) * DONE_Q_SIZE + QUEUE_ALIGN - 1) / QUEUE_ALIGN) * QUEUE_ALIGN;
rx_done_q_size = ((sizeof(rx_done_desc) * DONE_Q_SIZE + QUEUE_ALIGN - 1) / QUEUE_ALIGN) * QUEUE_ALIGN;
tx_ring_size = ((sizeof(starfire_tx_desc) * TX_RING_SIZE + QUEUE_ALIGN - 1) / QUEUE_ALIGN) * QUEUE_ALIGN;
rx_ring_size = sizeof(struct starfire_rx_desc) * RX_RING_SIZE;
np->queue_mem_size = tx_done_q_size + rx_done_q_size + tx_ring_size + rx_ring_size;
np->queue_mem = pci_alloc_consistent(np->pci_dev, np->queue_mem_size, &np->queue_mem_dma);
if (np->queue_mem == NULL) {
free_irq(irq, dev);
return -ENOMEM;
}
np->tx_done_q = np->queue_mem;
np->tx_done_q_dma = np->queue_mem_dma;
np->rx_done_q = (void *) np->tx_done_q + tx_done_q_size;
np->rx_done_q_dma = np->tx_done_q_dma + tx_done_q_size;
np->tx_ring = (void *) np->rx_done_q + rx_done_q_size;
np->tx_ring_dma = np->rx_done_q_dma + rx_done_q_size;
np->rx_ring = (void *) np->tx_ring + tx_ring_size;
np->rx_ring_dma = np->tx_ring_dma + tx_ring_size;
}
netif_carrier_off(dev);
init_ring(dev);
writel((np->rx_buf_sz << RxBufferLenShift) |
(0 << RxMinDescrThreshShift) |
RxPrefetchMode | RxVariableQ |
RX_Q_ENTRIES |
RX_DESC_Q_ADDR_SIZE | RX_DESC_ADDR_SIZE |
RxDescSpace4,
ioaddr + RxDescQCtrl);
writel(RxChecksumIgnore |
(0 << RxEarlyIntThreshShift) |
(6 << RxHighPrioThreshShift) |
((DMA_BURST_SIZE / 32) << RxBurstSizeShift),
ioaddr + RxDMACtrl);
writel((2 << TxHiPriFIFOThreshShift) |
(0 << TxPadLenShift) |
((DMA_BURST_SIZE / 32) << TxDMABurstSizeShift) |
TX_DESC_Q_ADDR_SIZE |
TX_DESC_SPACING | TX_DESC_TYPE,
ioaddr + TxDescCtrl);
writel( (np->queue_mem_dma >> 16) >> 16, ioaddr + RxDescQHiAddr);
writel( (np->queue_mem_dma >> 16) >> 16, ioaddr + TxRingHiAddr);
writel( (np->queue_mem_dma >> 16) >> 16, ioaddr + CompletionHiAddr);
writel(np->rx_ring_dma, ioaddr + RxDescQAddr);
writel(np->tx_ring_dma, ioaddr + TxRingPtr);
writel(np->tx_done_q_dma, ioaddr + TxCompletionAddr);
writel(np->rx_done_q_dma |
RxComplType |
(0 << RxComplThreshShift),
ioaddr + RxCompletionAddr);
if (debug > 1)
printk(KERN_DEBUG "%s: Filling in the station address.\n", dev->name);
for (i = 0; i < 6; i++)
writeb(dev->dev_addr[i], ioaddr + TxStationAddr + 5 - i);
writew(0, ioaddr + PerfFilterTable);
writew(0, ioaddr + PerfFilterTable + 4);
writew(0, ioaddr + PerfFilterTable + 8);
for (i = 1; i < 16; i++) {
__be16 *eaddrs = (__be16 *)dev->dev_addr;
void __iomem *setup_frm = ioaddr + PerfFilterTable + i * 16;
writew(be16_to_cpu(eaddrs[2]), setup_frm); setup_frm += 4;
writew(be16_to_cpu(eaddrs[1]), setup_frm); setup_frm += 4;
writew(be16_to_cpu(eaddrs[0]), setup_frm); setup_frm += 8;
}
np->tx_mode = TxFlowEnable|RxFlowEnable|PadEnable;
writel(MiiSoftReset | np->tx_mode, ioaddr + TxMode);
udelay(1000);
writel(np->tx_mode, ioaddr + TxMode);
np->tx_threshold = 4;
writel(np->tx_threshold, ioaddr + TxThreshold);
writel(np->intr_timer_ctrl, ioaddr + IntrTimerCtrl);
napi_enable(&np->napi);
netif_start_queue(dev);
if (debug > 1)
printk(KERN_DEBUG "%s: Setting the Rx and Tx modes.\n", dev->name);
set_rx_mode(dev);
np->mii_if.advertising = mdio_read(dev, np->phys[0], MII_ADVERTISE);
check_duplex(dev);
writel(0x0f00ff00, ioaddr + GPIOCtrl);
writel(IntrRxDone | IntrRxEmpty | IntrDMAErr |
IntrTxDMADone | IntrStatsMax | IntrLinkChange |
IntrRxGFPDead | IntrNoTxCsum | IntrTxBadID,
ioaddr + IntrEnable);
writel(0x00800000 | readl(ioaddr + PCIDeviceConfig),
ioaddr + PCIDeviceConfig);
#ifdef VLAN_SUPPORT
writel(ETH_P_8021Q, ioaddr + VlanType);
#endif
retval = request_firmware(&fw_rx, FIRMWARE_RX, &np->pci_dev->dev);
if (retval) {
printk(KERN_ERR "starfire: Failed to load firmware \"%s\"\n",
FIRMWARE_RX);
goto out_init;
}
if (fw_rx->size % 4) {
printk(KERN_ERR "starfire: bogus length %zu in \"%s\"\n",
fw_rx->size, FIRMWARE_RX);
retval = -EINVAL;
goto out_rx;
}
retval = request_firmware(&fw_tx, FIRMWARE_TX, &np->pci_dev->dev);
if (retval) {
printk(KERN_ERR "starfire: Failed to load firmware \"%s\"\n",
FIRMWARE_TX);
goto out_rx;
}
if (fw_tx->size % 4) {
printk(KERN_ERR "starfire: bogus length %zu in \"%s\"\n",
fw_tx->size, FIRMWARE_TX);
retval = -EINVAL;
goto out_tx;
}
fw_rx_data = (const __be32 *)&fw_rx->data[0];
fw_tx_data = (const __be32 *)&fw_tx->data[0];
rx_size = fw_rx->size / 4;
tx_size = fw_tx->size / 4;
for (i = 0; i < rx_size; i++)
writel(be32_to_cpup(&fw_rx_data[i]), ioaddr + RxGfpMem + i * 4);
for (i = 0; i < tx_size; i++)
writel(be32_to_cpup(&fw_tx_data[i]), ioaddr + TxGfpMem + i * 4);
if (enable_hw_cksum)
writel(TxEnable|TxGFPEnable|RxEnable|RxGFPEnable, ioaddr + GenCtrl);
else
writel(TxEnable|RxEnable, ioaddr + GenCtrl);
if (debug > 1)
printk(KERN_DEBUG "%s: Done netdev_open().\n",
dev->name);
out_tx:
release_firmware(fw_tx);
out_rx:
release_firmware(fw_rx);
out_init:
if (retval)
netdev_close(dev);
return retval;
}
static void check_duplex(struct net_device *dev)
{
struct netdev_private *np = netdev_priv(dev);
u16 reg0;
int silly_count = 1000;
mdio_write(dev, np->phys[0], MII_ADVERTISE, np->mii_if.advertising);
mdio_write(dev, np->phys[0], MII_BMCR, BMCR_RESET);
udelay(500);
while (--silly_count && mdio_read(dev, np->phys[0], MII_BMCR) & BMCR_RESET)
;
if (!silly_count) {
printk("%s: MII reset failed!\n", dev->name);
return;
}
reg0 = mdio_read(dev, np->phys[0], MII_BMCR);
if (!np->mii_if.force_media) {
reg0 |= BMCR_ANENABLE | BMCR_ANRESTART;
} else {
reg0 &= ~(BMCR_ANENABLE | BMCR_ANRESTART);
if (np->speed100)
reg0 |= BMCR_SPEED100;
if (np->mii_if.full_duplex)
reg0 |= BMCR_FULLDPLX;
printk(KERN_DEBUG "%s: Link forced to %sMbit %s-duplex\n",
dev->name,
np->speed100 ? "100" : "10",
np->mii_if.full_duplex ? "full" : "half");
}
mdio_write(dev, np->phys[0], MII_BMCR, reg0);
}
static void tx_timeout(struct net_device *dev)
{
struct netdev_private *np = netdev_priv(dev);
void __iomem *ioaddr = np->base;
int old_debug;
printk(KERN_WARNING "%s: Transmit timed out, status %#8.8x, "
"resetting...\n", dev->name, (int) readl(ioaddr + IntrStatus));
old_debug = debug;
debug = 2;
netdev_close(dev);
netdev_open(dev);
debug = old_debug;
dev->trans_start = jiffies;
dev->stats.tx_errors++;
netif_wake_queue(dev);
}
static void init_ring(struct net_device *dev)
{
struct netdev_private *np = netdev_priv(dev);
int i;
np->cur_rx = np->cur_tx = np->reap_tx = 0;
np->dirty_rx = np->dirty_tx = np->rx_done = np->tx_done = 0;
np->rx_buf_sz = (dev->mtu <= 1500 ? PKT_BUF_SZ : dev->mtu + 32);
for (i = 0; i < RX_RING_SIZE; i++) {
struct sk_buff *skb = netdev_alloc_skb(dev, np->rx_buf_sz);
np->rx_info[i].skb = skb;
if (skb == NULL)
break;
np->rx_info[i].mapping = pci_map_single(np->pci_dev, skb->data, np->rx_buf_sz, PCI_DMA_FROMDEVICE);
np->rx_ring[i].rxaddr = cpu_to_dma(np->rx_info[i].mapping | RxDescValid);
}
writew(i - 1, np->base + RxDescQIdx);
np->dirty_rx = (unsigned int)(i - RX_RING_SIZE);
for ( ; i < RX_RING_SIZE; i++) {
np->rx_ring[i].rxaddr = 0;
np->rx_info[i].skb = NULL;
np->rx_info[i].mapping = 0;
}
np->rx_ring[RX_RING_SIZE - 1].rxaddr |= cpu_to_dma(RxDescEndRing);
for (i = 0; i < DONE_Q_SIZE; i++) {
np->rx_done_q[i].status = 0;
np->tx_done_q[i].status = 0;
}
for (i = 0; i < TX_RING_SIZE; i++)
memset(&np->tx_info[i], 0, sizeof(np->tx_info[i]));
}
static netdev_tx_t start_tx(struct sk_buff *skb, struct net_device *dev)
{
struct netdev_private *np = netdev_priv(dev);
unsigned int entry;
u32 status;
int i;
if ((np->cur_tx - np->dirty_tx) + skb_num_frags(skb) * 2 > TX_RING_SIZE) {
netif_stop_queue(dev);
return NETDEV_TX_BUSY;
}
#if defined(ZEROCOPY) && defined(HAS_BROKEN_FIRMWARE)
if (skb->ip_summed == CHECKSUM_PARTIAL) {
if (skb_padto(skb, (skb->len + PADDING_MASK) & ~PADDING_MASK))
return NETDEV_TX_OK;
}
#endif
entry = np->cur_tx % TX_RING_SIZE;
for (i = 0; i < skb_num_frags(skb); i++) {
int wrap_ring = 0;
status = TxDescID;
if (i == 0) {
np->tx_info[entry].skb = skb;
status |= TxCRCEn;
if (entry >= TX_RING_SIZE - skb_num_frags(skb)) {
status |= TxRingWrap;
wrap_ring = 1;
}
if (np->reap_tx) {
status |= TxDescIntr;
np->reap_tx = 0;
}
if (skb->ip_summed == CHECKSUM_PARTIAL) {
status |= TxCalTCP;
dev->stats.tx_compressed++;
}
status |= skb_first_frag_len(skb) | (skb_num_frags(skb) << 16);
np->tx_info[entry].mapping =
pci_map_single(np->pci_dev, skb->data, skb_first_frag_len(skb), PCI_DMA_TODEVICE);
} else {
const skb_frag_t *this_frag = &skb_shinfo(skb)->frags[i - 1];
status |= skb_frag_size(this_frag);
np->tx_info[entry].mapping =
pci_map_single(np->pci_dev,
skb_frag_address(this_frag),
skb_frag_size(this_frag),
PCI_DMA_TODEVICE);
}
np->tx_ring[entry].addr = cpu_to_dma(np->tx_info[entry].mapping);
np->tx_ring[entry].status = cpu_to_le32(status);
if (debug > 3)
printk(KERN_DEBUG "%s: Tx #%d/#%d slot %d status %#8.8x.\n",
dev->name, np->cur_tx, np->dirty_tx,
entry, status);
if (wrap_ring) {
np->tx_info[entry].used_slots = TX_RING_SIZE - entry;
np->cur_tx += np->tx_info[entry].used_slots;
entry = 0;
} else {
np->tx_info[entry].used_slots = 1;
np->cur_tx += np->tx_info[entry].used_slots;
entry++;
}
if (np->cur_tx % (TX_RING_SIZE / 2) == 0)
np->reap_tx = 1;
}
wmb();
writel(entry * (sizeof(starfire_tx_desc) / 8), np->base + TxProducerIdx);
if ((np->cur_tx - np->dirty_tx) + 4 > TX_RING_SIZE)
netif_stop_queue(dev);
return NETDEV_TX_OK;
}
static irqreturn_t intr_handler(int irq, void *dev_instance)
{
struct net_device *dev = dev_instance;
struct netdev_private *np = netdev_priv(dev);
void __iomem *ioaddr = np->base;
int boguscnt = max_interrupt_work;
int consumer;
int tx_status;
int handled = 0;
do {
u32 intr_status = readl(ioaddr + IntrClear);
if (debug > 4)
printk(KERN_DEBUG "%s: Interrupt status %#8.8x.\n",
dev->name, intr_status);
if (intr_status == 0 || intr_status == (u32) -1)
break;
handled = 1;
if (intr_status & (IntrRxDone | IntrRxEmpty)) {
u32 enable;
if (likely(napi_schedule_prep(&np->napi))) {
__napi_schedule(&np->napi);
enable = readl(ioaddr + IntrEnable);
enable &= ~(IntrRxDone | IntrRxEmpty);
writel(enable, ioaddr + IntrEnable);
readl(ioaddr + IntrEnable);
} else {
enable = readl(ioaddr + IntrEnable);
if (enable & (IntrRxDone | IntrRxEmpty)) {
printk(KERN_INFO
"%s: interrupt while in poll!\n",
dev->name);
enable &= ~(IntrRxDone | IntrRxEmpty);
writel(enable, ioaddr + IntrEnable);
}
}
}
consumer = readl(ioaddr + TxConsumerIdx);
if (debug > 3)
printk(KERN_DEBUG "%s: Tx Consumer index is %d.\n",
dev->name, consumer);
while ((tx_status = le32_to_cpu(np->tx_done_q[np->tx_done].status)) != 0) {
if (debug > 3)
printk(KERN_DEBUG "%s: Tx completion #%d entry %d is %#8.8x.\n",
dev->name, np->dirty_tx, np->tx_done, tx_status);
if ((tx_status & 0xe0000000) == 0xa0000000) {
dev->stats.tx_packets++;
} else if ((tx_status & 0xe0000000) == 0x80000000) {
u16 entry = (tx_status & 0x7fff) / sizeof(starfire_tx_desc);
struct sk_buff *skb = np->tx_info[entry].skb;
np->tx_info[entry].skb = NULL;
pci_unmap_single(np->pci_dev,
np->tx_info[entry].mapping,
skb_first_frag_len(skb),
PCI_DMA_TODEVICE);
np->tx_info[entry].mapping = 0;
np->dirty_tx += np->tx_info[entry].used_slots;
entry = (entry + np->tx_info[entry].used_slots) % TX_RING_SIZE;
{
int i;
for (i = 0; i < skb_shinfo(skb)->nr_frags; i++) {
pci_unmap_single(np->pci_dev,
np->tx_info[entry].mapping,
skb_frag_size(&skb_shinfo(skb)->frags[i]),
PCI_DMA_TODEVICE);
np->dirty_tx++;
entry++;
}
}
dev_kfree_skb_irq(skb);
}
np->tx_done_q[np->tx_done].status = 0;
np->tx_done = (np->tx_done + 1) % DONE_Q_SIZE;
}
writew(np->tx_done, ioaddr + CompletionQConsumerIdx + 2);
if (netif_queue_stopped(dev) &&
(np->cur_tx - np->dirty_tx + 4 < TX_RING_SIZE)) {
netif_wake_queue(dev);
}
if (intr_status & IntrStatsMax)
get_stats(dev);
if (intr_status & IntrLinkChange)
netdev_media_change(dev);
if (intr_status & IntrAbnormalSummary)
netdev_error(dev, intr_status);
if (--boguscnt < 0) {
if (debug > 1)
printk(KERN_WARNING "%s: Too much work at interrupt, "
"status=%#8.8x.\n",
dev->name, intr_status);
break;
}
} while (1);
if (debug > 4)
printk(KERN_DEBUG "%s: exiting interrupt, status=%#8.8x.\n",
dev->name, (int) readl(ioaddr + IntrStatus));
return IRQ_RETVAL(handled);
}
static int __netdev_rx(struct net_device *dev, int *quota)
{
struct netdev_private *np = netdev_priv(dev);
u32 desc_status;
int retcode = 0;
while ((desc_status = le32_to_cpu(np->rx_done_q[np->rx_done].status)) != 0) {
struct sk_buff *skb;
u16 pkt_len;
int entry;
rx_done_desc *desc = &np->rx_done_q[np->rx_done];
if (debug > 4)
printk(KERN_DEBUG " netdev_rx() status of %d was %#8.8x.\n", np->rx_done, desc_status);
if (!(desc_status & RxOK)) {
if (debug > 2)
printk(KERN_DEBUG " netdev_rx() Rx error was %#8.8x.\n", desc_status);
dev->stats.rx_errors++;
if (desc_status & RxFIFOErr)
dev->stats.rx_fifo_errors++;
goto next_rx;
}
if (*quota <= 0) {
retcode = 1;
goto out;
}
(*quota)--;
pkt_len = desc_status;
entry = (desc_status >> 16) & 0x7ff;
if (debug > 4)
printk(KERN_DEBUG " netdev_rx() normal Rx pkt length %d, quota %d.\n", pkt_len, *quota);
if (pkt_len < rx_copybreak &&
(skb = netdev_alloc_skb(dev, pkt_len + 2)) != NULL) {
skb_reserve(skb, 2);
pci_dma_sync_single_for_cpu(np->pci_dev,
np->rx_info[entry].mapping,
pkt_len, PCI_DMA_FROMDEVICE);
skb_copy_to_linear_data(skb, np->rx_info[entry].skb->data, pkt_len);
pci_dma_sync_single_for_device(np->pci_dev,
np->rx_info[entry].mapping,
pkt_len, PCI_DMA_FROMDEVICE);
skb_put(skb, pkt_len);
} else {
pci_unmap_single(np->pci_dev, np->rx_info[entry].mapping, np->rx_buf_sz, PCI_DMA_FROMDEVICE);
skb = np->rx_info[entry].skb;
skb_put(skb, pkt_len);
np->rx_info[entry].skb = NULL;
np->rx_info[entry].mapping = 0;
}
#ifndef final_version
if (debug > 5) {
printk(KERN_DEBUG " Rx data %pM %pM %2.2x%2.2x.\n",
skb->data, skb->data + 6,
skb->data[12], skb->data[13]);
}
#endif
skb->protocol = eth_type_trans(skb, dev);
#ifdef VLAN_SUPPORT
if (debug > 4)
printk(KERN_DEBUG " netdev_rx() status2 of %d was %#4.4x.\n", np->rx_done, le16_to_cpu(desc->status2));
#endif
if (le16_to_cpu(desc->status2) & 0x0100) {
skb->ip_summed = CHECKSUM_UNNECESSARY;
dev->stats.rx_compressed++;
}
else if (le16_to_cpu(desc->status2) & 0x0040) {
skb->ip_summed = CHECKSUM_COMPLETE;
skb->csum = le16_to_cpu(desc->csum);
printk(KERN_DEBUG "%s: checksum_hw, status2 = %#x\n", dev->name, le16_to_cpu(desc->status2));
}
#ifdef VLAN_SUPPORT
if (le16_to_cpu(desc->status2) & 0x0200) {
u16 vlid = le16_to_cpu(desc->vlanid);
if (debug > 4) {
printk(KERN_DEBUG " netdev_rx() vlanid = %d\n",
vlid);
}
__vlan_hwaccel_put_tag(skb, htons(ETH_P_8021Q), vlid);
}
#endif
netif_receive_skb(skb);
dev->stats.rx_packets++;
next_rx:
np->cur_rx++;
desc->status = 0;
np->rx_done = (np->rx_done + 1) % DONE_Q_SIZE;
}
if (*quota == 0) {
retcode = 1;
goto out;
}
writew(np->rx_done, np->base + CompletionQConsumerIdx);
out:
refill_rx_ring(dev);
if (debug > 5)
printk(KERN_DEBUG " exiting netdev_rx(): %d, status of %d was %#8.8x.\n",
retcode, np->rx_done, desc_status);
return retcode;
}
static int netdev_poll(struct napi_struct *napi, int budget)
{
struct netdev_private *np = container_of(napi, struct netdev_private, napi);
struct net_device *dev = np->dev;
u32 intr_status;
void __iomem *ioaddr = np->base;
int quota = budget;
do {
writel(IntrRxDone | IntrRxEmpty, ioaddr + IntrClear);
if (__netdev_rx(dev, &quota))
goto out;
intr_status = readl(ioaddr + IntrStatus);
} while (intr_status & (IntrRxDone | IntrRxEmpty));
napi_complete(napi);
intr_status = readl(ioaddr + IntrEnable);
intr_status |= IntrRxDone | IntrRxEmpty;
writel(intr_status, ioaddr + IntrEnable);
out:
if (debug > 5)
printk(KERN_DEBUG " exiting netdev_poll(): %d.\n",
budget - quota);
return budget - quota;
}
static void refill_rx_ring(struct net_device *dev)
{
struct netdev_private *np = netdev_priv(dev);
struct sk_buff *skb;
int entry = -1;
for (; np->cur_rx - np->dirty_rx > 0; np->dirty_rx++) {
entry = np->dirty_rx % RX_RING_SIZE;
if (np->rx_info[entry].skb == NULL) {
skb = netdev_alloc_skb(dev, np->rx_buf_sz);
np->rx_info[entry].skb = skb;
if (skb == NULL)
break;
np->rx_info[entry].mapping =
pci_map_single(np->pci_dev, skb->data, np->rx_buf_sz, PCI_DMA_FROMDEVICE);
np->rx_ring[entry].rxaddr =
cpu_to_dma(np->rx_info[entry].mapping | RxDescValid);
}
if (entry == RX_RING_SIZE - 1)
np->rx_ring[entry].rxaddr |= cpu_to_dma(RxDescEndRing);
}
if (entry >= 0)
writew(entry, np->base + RxDescQIdx);
}
static void netdev_media_change(struct net_device *dev)
{
struct netdev_private *np = netdev_priv(dev);
void __iomem *ioaddr = np->base;
u16 reg0, reg1, reg4, reg5;
u32 new_tx_mode;
u32 new_intr_timer_ctrl;
mdio_read(dev, np->phys[0], MII_BMCR);
mdio_read(dev, np->phys[0], MII_BMSR);
reg0 = mdio_read(dev, np->phys[0], MII_BMCR);
reg1 = mdio_read(dev, np->phys[0], MII_BMSR);
if (reg1 & BMSR_LSTATUS) {
if (reg0 & BMCR_ANENABLE) {
reg4 = mdio_read(dev, np->phys[0], MII_ADVERTISE);
reg5 = mdio_read(dev, np->phys[0], MII_LPA);
if (reg4 & ADVERTISE_100FULL && reg5 & LPA_100FULL) {
np->speed100 = 1;
np->mii_if.full_duplex = 1;
} else if (reg4 & ADVERTISE_100HALF && reg5 & LPA_100HALF) {
np->speed100 = 1;
np->mii_if.full_duplex = 0;
} else if (reg4 & ADVERTISE_10FULL && reg5 & LPA_10FULL) {
np->speed100 = 0;
np->mii_if.full_duplex = 1;
} else {
np->speed100 = 0;
np->mii_if.full_duplex = 0;
}
} else {
if (reg0 & BMCR_SPEED100)
np->speed100 = 1;
else
np->speed100 = 0;
if (reg0 & BMCR_FULLDPLX)
np->mii_if.full_duplex = 1;
else
np->mii_if.full_duplex = 0;
}
netif_carrier_on(dev);
printk(KERN_DEBUG "%s: Link is up, running at %sMbit %s-duplex\n",
dev->name,
np->speed100 ? "100" : "10",
np->mii_if.full_duplex ? "full" : "half");
new_tx_mode = np->tx_mode & ~FullDuplex;
if (np->mii_if.full_duplex)
new_tx_mode |= FullDuplex;
if (np->tx_mode != new_tx_mode) {
np->tx_mode = new_tx_mode;
writel(np->tx_mode | MiiSoftReset, ioaddr + TxMode);
udelay(1000);
writel(np->tx_mode, ioaddr + TxMode);
}
new_intr_timer_ctrl = np->intr_timer_ctrl & ~Timer10X;
if (np->speed100)
new_intr_timer_ctrl |= Timer10X;
if (np->intr_timer_ctrl != new_intr_timer_ctrl) {
np->intr_timer_ctrl = new_intr_timer_ctrl;
writel(new_intr_timer_ctrl, ioaddr + IntrTimerCtrl);
}
} else {
netif_carrier_off(dev);
printk(KERN_DEBUG "%s: Link is down\n", dev->name);
}
}
static void netdev_error(struct net_device *dev, int intr_status)
{
struct netdev_private *np = netdev_priv(dev);
if (intr_status & IntrTxDataLow) {
if (np->tx_threshold <= PKT_BUF_SZ / 16) {
writel(++np->tx_threshold, np->base + TxThreshold);
printk(KERN_NOTICE "%s: PCI bus congestion, increasing Tx FIFO threshold to %d bytes\n",
dev->name, np->tx_threshold * 16);
} else
printk(KERN_WARNING "%s: PCI Tx underflow -- adapter is probably malfunctioning\n", dev->name);
}
if (intr_status & IntrRxGFPDead) {
dev->stats.rx_fifo_errors++;
dev->stats.rx_errors++;
}
if (intr_status & (IntrNoTxCsum | IntrDMAErr)) {
dev->stats.tx_fifo_errors++;
dev->stats.tx_errors++;
}
if ((intr_status & ~(IntrNormalMask | IntrAbnormalSummary | IntrLinkChange | IntrStatsMax | IntrTxDataLow | IntrRxGFPDead | IntrNoTxCsum | IntrPCIPad)) && debug)
printk(KERN_ERR "%s: Something Wicked happened! %#8.8x.\n",
dev->name, intr_status);
}
static struct net_device_stats *get_stats(struct net_device *dev)
{
struct netdev_private *np = netdev_priv(dev);
void __iomem *ioaddr = np->base;
dev->stats.tx_bytes = readl(ioaddr + 0x57010);
dev->stats.rx_bytes = readl(ioaddr + 0x57044);
dev->stats.tx_packets = readl(ioaddr + 0x57000);
dev->stats.tx_aborted_errors =
readl(ioaddr + 0x57024) + readl(ioaddr + 0x57028);
dev->stats.tx_window_errors = readl(ioaddr + 0x57018);
dev->stats.collisions =
readl(ioaddr + 0x57004) + readl(ioaddr + 0x57008);
dev->stats.rx_dropped += readw(ioaddr + RxDMAStatus);
writew(0, ioaddr + RxDMAStatus);
dev->stats.rx_crc_errors = readl(ioaddr + 0x5703C);
dev->stats.rx_frame_errors = readl(ioaddr + 0x57040);
dev->stats.rx_length_errors = readl(ioaddr + 0x57058);
dev->stats.rx_missed_errors = readl(ioaddr + 0x5707C);
return &dev->stats;
}
static u32 set_vlan_mode(struct netdev_private *np)
{
u32 ret = VlanMode;
u16 vid;
void __iomem *filter_addr = np->base + HashTable + 8;
int vlan_count = 0;
for_each_set_bit(vid, np->active_vlans, VLAN_N_VID) {
if (vlan_count == 32)
break;
writew(vid, filter_addr);
filter_addr += 16;
vlan_count++;
}
if (vlan_count == 32) {
ret |= PerfectFilterVlan;
while (vlan_count < 32) {
writew(0, filter_addr);
filter_addr += 16;
vlan_count++;
}
}
return ret;
}
static void set_rx_mode(struct net_device *dev)
{
struct netdev_private *np = netdev_priv(dev);
void __iomem *ioaddr = np->base;
u32 rx_mode = MinVLANPrio;
struct netdev_hw_addr *ha;
int i;
#ifdef VLAN_SUPPORT
rx_mode |= set_vlan_mode(np);
#endif
if (dev->flags & IFF_PROMISC) {
rx_mode |= AcceptAll;
} else if ((netdev_mc_count(dev) > multicast_filter_limit) ||
(dev->flags & IFF_ALLMULTI)) {
rx_mode |= AcceptBroadcast|AcceptAllMulticast|PerfectFilter;
} else if (netdev_mc_count(dev) <= 14) {
void __iomem *filter_addr = ioaddr + PerfFilterTable + 2 * 16;
__be16 *eaddrs;
netdev_for_each_mc_addr(ha, dev) {
eaddrs = (__be16 *) ha->addr;
writew(be16_to_cpu(eaddrs[2]), filter_addr); filter_addr += 4;
writew(be16_to_cpu(eaddrs[1]), filter_addr); filter_addr += 4;
writew(be16_to_cpu(eaddrs[0]), filter_addr); filter_addr += 8;
}
eaddrs = (__be16 *)dev->dev_addr;
i = netdev_mc_count(dev) + 2;
while (i++ < 16) {
writew(be16_to_cpu(eaddrs[0]), filter_addr); filter_addr += 4;
writew(be16_to_cpu(eaddrs[1]), filter_addr); filter_addr += 4;
writew(be16_to_cpu(eaddrs[2]), filter_addr); filter_addr += 8;
}
rx_mode |= AcceptBroadcast|PerfectFilter;
} else {
void __iomem *filter_addr;
__be16 *eaddrs;
__le16 mc_filter[32] __attribute__ ((aligned(sizeof(long))));
memset(mc_filter, 0, sizeof(mc_filter));
netdev_for_each_mc_addr(ha, dev) {
int bit_nr = ether_crc_le(ETH_ALEN, ha->addr) >> 23;
__le32 *fptr = (__le32 *) &mc_filter[(bit_nr >> 4) & ~1];
*fptr |= cpu_to_le32(1 << (bit_nr & 31));
}
filter_addr = ioaddr + PerfFilterTable + 2 * 16;
eaddrs = (__be16 *)dev->dev_addr;
for (i = 2; i < 16; i++) {
writew(be16_to_cpu(eaddrs[0]), filter_addr); filter_addr += 4;
writew(be16_to_cpu(eaddrs[1]), filter_addr); filter_addr += 4;
writew(be16_to_cpu(eaddrs[2]), filter_addr); filter_addr += 8;
}
for (filter_addr = ioaddr + HashTable, i = 0; i < 32; filter_addr+= 16, i++)
writew(mc_filter[i], filter_addr);
rx_mode |= AcceptBroadcast|PerfectFilter|HashFilter;
}
writel(rx_mode, ioaddr + RxFilterMode);
}
static int check_if_running(struct net_device *dev)
{
if (!netif_running(dev))
return -EINVAL;
return 0;
}
static void get_drvinfo(struct net_device *dev, struct ethtool_drvinfo *info)
{
struct netdev_private *np = netdev_priv(dev);
strlcpy(info->driver, DRV_NAME, sizeof(info->driver));
strlcpy(info->version, DRV_VERSION, sizeof(info->version));
strlcpy(info->bus_info, pci_name(np->pci_dev), sizeof(info->bus_info));
}
static int get_settings(struct net_device *dev, struct ethtool_cmd *ecmd)
{
struct netdev_private *np = netdev_priv(dev);
spin_lock_irq(&np->lock);
mii_ethtool_gset(&np->mii_if, ecmd);
spin_unlock_irq(&np->lock);
return 0;
}
static int set_settings(struct net_device *dev, struct ethtool_cmd *ecmd)
{
struct netdev_private *np = netdev_priv(dev);
int res;
spin_lock_irq(&np->lock);
res = mii_ethtool_sset(&np->mii_if, ecmd);
spin_unlock_irq(&np->lock);
check_duplex(dev);
return res;
}
static int nway_reset(struct net_device *dev)
{
struct netdev_private *np = netdev_priv(dev);
return mii_nway_restart(&np->mii_if);
}
static u32 get_link(struct net_device *dev)
{
struct netdev_private *np = netdev_priv(dev);
return mii_link_ok(&np->mii_if);
}
static u32 get_msglevel(struct net_device *dev)
{
return debug;
}
static void set_msglevel(struct net_device *dev, u32 val)
{
debug = val;
}
static int netdev_ioctl(struct net_device *dev, struct ifreq *rq, int cmd)
{
struct netdev_private *np = netdev_priv(dev);
struct mii_ioctl_data *data = if_mii(rq);
int rc;
if (!netif_running(dev))
return -EINVAL;
spin_lock_irq(&np->lock);
rc = generic_mii_ioctl(&np->mii_if, data, cmd, NULL);
spin_unlock_irq(&np->lock);
if ((cmd == SIOCSMIIREG) && (data->phy_id == np->phys[0]))
check_duplex(dev);
return rc;
}
static int netdev_close(struct net_device *dev)
{
struct netdev_private *np = netdev_priv(dev);
void __iomem *ioaddr = np->base;
int i;
netif_stop_queue(dev);
napi_disable(&np->napi);
if (debug > 1) {
printk(KERN_DEBUG "%s: Shutting down ethercard, Intr status %#8.8x.\n",
dev->name, (int) readl(ioaddr + IntrStatus));
printk(KERN_DEBUG "%s: Queue pointers were Tx %d / %d, Rx %d / %d.\n",
dev->name, np->cur_tx, np->dirty_tx,
np->cur_rx, np->dirty_rx);
}
writel(0, ioaddr + IntrEnable);
writel(0, ioaddr + GenCtrl);
readl(ioaddr + GenCtrl);
if (debug > 5) {
printk(KERN_DEBUG" Tx ring at %#llx:\n",
(long long) np->tx_ring_dma);
for (i = 0; i < 8 ; i++)
printk(KERN_DEBUG " #%d desc. %#8.8x %#llx -> %#8.8x.\n",
i, le32_to_cpu(np->tx_ring[i].status),
(long long) dma_to_cpu(np->tx_ring[i].addr),
le32_to_cpu(np->tx_done_q[i].status));
printk(KERN_DEBUG " Rx ring at %#llx -> %p:\n",
(long long) np->rx_ring_dma, np->rx_done_q);
if (np->rx_done_q)
for (i = 0; i < 8 ; i++) {
printk(KERN_DEBUG " #%d desc. %#llx -> %#8.8x\n",
i, (long long) dma_to_cpu(np->rx_ring[i].rxaddr), le32_to_cpu(np->rx_done_q[i].status));
}
}
free_irq(np->pci_dev->irq, dev);
for (i = 0; i < RX_RING_SIZE; i++) {
np->rx_ring[i].rxaddr = cpu_to_dma(0xBADF00D0);
if (np->rx_info[i].skb != NULL) {
pci_unmap_single(np->pci_dev, np->rx_info[i].mapping, np->rx_buf_sz, PCI_DMA_FROMDEVICE);
dev_kfree_skb(np->rx_info[i].skb);
}
np->rx_info[i].skb = NULL;
np->rx_info[i].mapping = 0;
}
for (i = 0; i < TX_RING_SIZE; i++) {
struct sk_buff *skb = np->tx_info[i].skb;
if (skb == NULL)
continue;
pci_unmap_single(np->pci_dev,
np->tx_info[i].mapping,
skb_first_frag_len(skb), PCI_DMA_TODEVICE);
np->tx_info[i].mapping = 0;
dev_kfree_skb(skb);
np->tx_info[i].skb = NULL;
}
return 0;
}
static int starfire_suspend(struct pci_dev *pdev, pm_message_t state)
{
struct net_device *dev = pci_get_drvdata(pdev);
if (netif_running(dev)) {
netif_device_detach(dev);
netdev_close(dev);
}
pci_save_state(pdev);
pci_set_power_state(pdev, pci_choose_state(pdev,state));
return 0;
}
static int starfire_resume(struct pci_dev *pdev)
{
struct net_device *dev = pci_get_drvdata(pdev);
pci_set_power_state(pdev, PCI_D0);
pci_restore_state(pdev);
if (netif_running(dev)) {
netdev_open(dev);
netif_device_attach(dev);
}
return 0;
}
static void starfire_remove_one(struct pci_dev *pdev)
{
struct net_device *dev = pci_get_drvdata(pdev);
struct netdev_private *np = netdev_priv(dev);
BUG_ON(!dev);
unregister_netdev(dev);
if (np->queue_mem)
pci_free_consistent(pdev, np->queue_mem_size, np->queue_mem, np->queue_mem_dma);
pci_set_power_state(pdev, PCI_D3hot);
pci_disable_device(pdev);
iounmap(np->base);
pci_release_regions(pdev);
pci_set_drvdata(pdev, NULL);
free_netdev(dev);
}
static int __init starfire_init (void)
{
#ifdef MODULE
printk(version);
printk(KERN_INFO DRV_NAME ": polling (NAPI) enabled\n");
#endif
BUILD_BUG_ON(sizeof(dma_addr_t) != sizeof(netdrv_addr_t));
return pci_register_driver(&starfire_driver);
}
static void __exit starfire_cleanup (void)
{
pci_unregister_driver (&starfire_driver);
}
