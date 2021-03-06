static int __devinit yellowfin_init_one(struct pci_dev *pdev,
const struct pci_device_id *ent)
{
struct net_device *dev;
struct yellowfin_private *np;
int irq;
int chip_idx = ent->driver_data;
static int find_cnt;
void __iomem *ioaddr;
int i, option = find_cnt < MAX_UNITS ? options[find_cnt] : 0;
int drv_flags = pci_id_tbl[chip_idx].drv_flags;
void *ring_space;
dma_addr_t ring_dma;
#ifdef USE_IO_OPS
int bar = 0;
#else
int bar = 1;
#endif
#ifndef MODULE
static int printed_version;
if (!printed_version++)
printk(version);
#endif
i = pci_enable_device(pdev);
if (i) return i;
dev = alloc_etherdev(sizeof(*np));
if (!dev)
return -ENOMEM;
SET_NETDEV_DEV(dev, &pdev->dev);
np = netdev_priv(dev);
if (pci_request_regions(pdev, DRV_NAME))
goto err_out_free_netdev;
pci_set_master (pdev);
ioaddr = pci_iomap(pdev, bar, YELLOWFIN_SIZE);
if (!ioaddr)
goto err_out_free_res;
irq = pdev->irq;
if (drv_flags & DontUseEeprom)
for (i = 0; i < 6; i++)
dev->dev_addr[i] = ioread8(ioaddr + StnAddr + i);
else {
int ee_offset = (read_eeprom(ioaddr, 6) == 0xff ? 0x100 : 0);
for (i = 0; i < 6; i++)
dev->dev_addr[i] = read_eeprom(ioaddr, ee_offset + i);
}
iowrite32(0x80000000, ioaddr + DMACtrl);
pci_set_drvdata(pdev, dev);
spin_lock_init(&np->lock);
np->pci_dev = pdev;
np->chip_id = chip_idx;
np->drv_flags = drv_flags;
np->base = ioaddr;
ring_space = pci_alloc_consistent(pdev, TX_TOTAL_SIZE, &ring_dma);
if (!ring_space)
goto err_out_cleardev;
np->tx_ring = ring_space;
np->tx_ring_dma = ring_dma;
ring_space = pci_alloc_consistent(pdev, RX_TOTAL_SIZE, &ring_dma);
if (!ring_space)
goto err_out_unmap_tx;
np->rx_ring = ring_space;
np->rx_ring_dma = ring_dma;
ring_space = pci_alloc_consistent(pdev, STATUS_TOTAL_SIZE, &ring_dma);
if (!ring_space)
goto err_out_unmap_rx;
np->tx_status = ring_space;
np->tx_status_dma = ring_dma;
if (dev->mem_start)
option = dev->mem_start;
if (option > 0) {
if (option & 0x200)
np->full_duplex = 1;
np->default_port = option & 15;
if (np->default_port)
np->medialock = 1;
}
if (find_cnt < MAX_UNITS && full_duplex[find_cnt] > 0)
np->full_duplex = 1;
if (np->full_duplex)
np->duplex_lock = 1;
dev->netdev_ops = &netdev_ops;
SET_ETHTOOL_OPS(dev, &ethtool_ops);
dev->watchdog_timeo = TX_TIMEOUT;
if (mtu)
dev->mtu = mtu;
i = register_netdev(dev);
if (i)
goto err_out_unmap_status;
netdev_info(dev, "%s type %8x at %p, %pM, IRQ %d\n",
pci_id_tbl[chip_idx].name,
ioread32(ioaddr + ChipRev), ioaddr,
dev->dev_addr, irq);
if (np->drv_flags & HasMII) {
int phy, phy_idx = 0;
for (phy = 0; phy < 32 && phy_idx < MII_CNT; phy++) {
int mii_status = mdio_read(ioaddr, phy, 1);
if (mii_status != 0xffff && mii_status != 0x0000) {
np->phys[phy_idx++] = phy;
np->advertising = mdio_read(ioaddr, phy, 4);
netdev_info(dev, "MII PHY found at address %d, status 0x%04x advertising %04x\n",
phy, mii_status, np->advertising);
}
}
np->mii_cnt = phy_idx;
}
find_cnt++;
return 0;
err_out_unmap_status:
pci_free_consistent(pdev, STATUS_TOTAL_SIZE, np->tx_status,
np->tx_status_dma);
err_out_unmap_rx:
pci_free_consistent(pdev, RX_TOTAL_SIZE, np->rx_ring, np->rx_ring_dma);
err_out_unmap_tx:
pci_free_consistent(pdev, TX_TOTAL_SIZE, np->tx_ring, np->tx_ring_dma);
err_out_cleardev:
pci_set_drvdata(pdev, NULL);
pci_iounmap(pdev, ioaddr);
err_out_free_res:
pci_release_regions(pdev);
err_out_free_netdev:
free_netdev (dev);
return -ENODEV;
}
static int __devinit read_eeprom(void __iomem *ioaddr, int location)
{
int bogus_cnt = 10000;
iowrite8(location, ioaddr + EEAddr);
iowrite8(0x30 | ((location >> 8) & 7), ioaddr + EECtrl);
while ((ioread8(ioaddr + EEStatus) & 0x80) && --bogus_cnt > 0)
;
return ioread8(ioaddr + EERead);
}
static int mdio_read(void __iomem *ioaddr, int phy_id, int location)
{
int i;
iowrite16((phy_id<<8) + location, ioaddr + MII_Addr);
iowrite16(1, ioaddr + MII_Cmd);
for (i = 10000; i >= 0; i--)
if ((ioread16(ioaddr + MII_Status) & 1) == 0)
break;
return ioread16(ioaddr + MII_Rd_Data);
}
static void mdio_write(void __iomem *ioaddr, int phy_id, int location, int value)
{
int i;
iowrite16((phy_id<<8) + location, ioaddr + MII_Addr);
iowrite16(value, ioaddr + MII_Wr_Data);
for (i = 10000; i >= 0; i--)
if ((ioread16(ioaddr + MII_Status) & 1) == 0)
break;
}
static int yellowfin_open(struct net_device *dev)
{
struct yellowfin_private *yp = netdev_priv(dev);
const int irq = yp->pci_dev->irq;
void __iomem *ioaddr = yp->base;
int i, rc;
iowrite32(0x80000000, ioaddr + DMACtrl);
rc = request_irq(irq, yellowfin_interrupt, IRQF_SHARED, dev->name, dev);
if (rc)
return rc;
rc = yellowfin_init_ring(dev);
if (rc < 0)
goto err_free_irq;
iowrite32(yp->rx_ring_dma, ioaddr + RxPtr);
iowrite32(yp->tx_ring_dma, ioaddr + TxPtr);
for (i = 0; i < 6; i++)
iowrite8(dev->dev_addr[i], ioaddr + StnAddr + i);
iowrite32(0x00800080, ioaddr + TxIntrSel);
iowrite32(0x00800080, ioaddr + TxBranchSel);
iowrite32(0x00400040, ioaddr + TxWaitSel);
iowrite32(0x00400040, ioaddr + RxIntrSel);
iowrite32(0x00400040, ioaddr + RxBranchSel);
iowrite32(0x00400040, ioaddr + RxWaitSel);
iowrite32(dma_ctrl, ioaddr + DMACtrl);
iowrite16(fifo_cfg, ioaddr + FIFOcfg);
iowrite32(0x0030FFFF, ioaddr + FlowCtrl);
yp->tx_threshold = 32;
iowrite32(yp->tx_threshold, ioaddr + TxThreshold);
if (dev->if_port == 0)
dev->if_port = yp->default_port;
netif_start_queue(dev);
if (yp->drv_flags & IsGigabit) {
yp->full_duplex = 1;
iowrite16(0x01CF, ioaddr + Cnfg);
} else {
iowrite16(0x0018, ioaddr + FrameGap0);
iowrite16(0x1018, ioaddr + FrameGap1);
iowrite16(0x101C | (yp->full_duplex ? 2 : 0), ioaddr + Cnfg);
}
set_rx_mode(dev);
iowrite16(0x81ff, ioaddr + IntrEnb);
iowrite16(0x0000, ioaddr + EventStatus);
iowrite32(0x80008000, ioaddr + RxCtrl);
iowrite32(0x80008000, ioaddr + TxCtrl);
if (yellowfin_debug > 2) {
netdev_printk(KERN_DEBUG, dev, "Done %s()\n", __func__);
}
init_timer(&yp->timer);
yp->timer.expires = jiffies + 3*HZ;
yp->timer.data = (unsigned long)dev;
yp->timer.function = yellowfin_timer;
add_timer(&yp->timer);
out:
return rc;
err_free_irq:
free_irq(irq, dev);
goto out;
}
static void yellowfin_timer(unsigned long data)
{
struct net_device *dev = (struct net_device *)data;
struct yellowfin_private *yp = netdev_priv(dev);
void __iomem *ioaddr = yp->base;
int next_tick = 60*HZ;
if (yellowfin_debug > 3) {
netdev_printk(KERN_DEBUG, dev, "Yellowfin timer tick, status %08x\n",
ioread16(ioaddr + IntrStatus));
}
if (yp->mii_cnt) {
int bmsr = mdio_read(ioaddr, yp->phys[0], MII_BMSR);
int lpa = mdio_read(ioaddr, yp->phys[0], MII_LPA);
int negotiated = lpa & yp->advertising;
if (yellowfin_debug > 1)
netdev_printk(KERN_DEBUG, dev, "MII #%d status register is %04x, link partner capability %04x\n",
yp->phys[0], bmsr, lpa);
yp->full_duplex = mii_duplex(yp->duplex_lock, negotiated);
iowrite16(0x101C | (yp->full_duplex ? 2 : 0), ioaddr + Cnfg);
if (bmsr & BMSR_LSTATUS)
next_tick = 60*HZ;
else
next_tick = 3*HZ;
}
yp->timer.expires = jiffies + next_tick;
add_timer(&yp->timer);
}
static void yellowfin_tx_timeout(struct net_device *dev)
{
struct yellowfin_private *yp = netdev_priv(dev);
void __iomem *ioaddr = yp->base;
netdev_warn(dev, "Yellowfin transmit timed out at %d/%d Tx status %04x, Rx status %04x, resetting...\n",
yp->cur_tx, yp->dirty_tx,
ioread32(ioaddr + TxStatus),
ioread32(ioaddr + RxStatus));
if (yellowfin_debug) {
int i;
pr_warning(" Rx ring %p: ", yp->rx_ring);
for (i = 0; i < RX_RING_SIZE; i++)
pr_cont(" %08x", yp->rx_ring[i].result_status);
pr_cont("\n");
pr_warning(" Tx ring %p: ", yp->tx_ring);
for (i = 0; i < TX_RING_SIZE; i++)
pr_cont(" %04x /%08x",
yp->tx_status[i].tx_errs,
yp->tx_ring[i].result_status);
pr_cont("\n");
}
dev->if_port = 0;
iowrite32(0x10001000, yp->base + TxCtrl);
if (yp->cur_tx - yp->dirty_tx < TX_QUEUE_SIZE)
netif_wake_queue (dev);
dev->trans_start = jiffies;
dev->stats.tx_errors++;
}
static int yellowfin_init_ring(struct net_device *dev)
{
struct yellowfin_private *yp = netdev_priv(dev);
int i, j;
yp->tx_full = 0;
yp->cur_rx = yp->cur_tx = 0;
yp->dirty_tx = 0;
yp->rx_buf_sz = (dev->mtu <= 1500 ? PKT_BUF_SZ : dev->mtu + 32);
for (i = 0; i < RX_RING_SIZE; i++) {
yp->rx_ring[i].dbdma_cmd =
cpu_to_le32(CMD_RX_BUF | INTR_ALWAYS | yp->rx_buf_sz);
yp->rx_ring[i].branch_addr = cpu_to_le32(yp->rx_ring_dma +
((i+1)%RX_RING_SIZE)*sizeof(struct yellowfin_desc));
}
for (i = 0; i < RX_RING_SIZE; i++) {
struct sk_buff *skb = netdev_alloc_skb(dev, yp->rx_buf_sz + 2);
yp->rx_skbuff[i] = skb;
if (skb == NULL)
break;
skb_reserve(skb, 2);
yp->rx_ring[i].addr = cpu_to_le32(pci_map_single(yp->pci_dev,
skb->data, yp->rx_buf_sz, PCI_DMA_FROMDEVICE));
}
if (i != RX_RING_SIZE) {
for (j = 0; j < i; j++)
dev_kfree_skb(yp->rx_skbuff[j]);
return -ENOMEM;
}
yp->rx_ring[i-1].dbdma_cmd = cpu_to_le32(CMD_STOP);
yp->dirty_rx = (unsigned int)(i - RX_RING_SIZE);
#define NO_TXSTATS
#ifdef NO_TXSTATS
for (i = 0; i < TX_RING_SIZE; i++) {
yp->tx_skbuff[i] = NULL;
yp->tx_ring[i].dbdma_cmd = cpu_to_le32(CMD_STOP);
yp->tx_ring[i].branch_addr = cpu_to_le32(yp->tx_ring_dma +
((i+1)%TX_RING_SIZE)*sizeof(struct yellowfin_desc));
}
yp->tx_ring[--i].dbdma_cmd = cpu_to_le32(CMD_STOP | BRANCH_ALWAYS);
#else
{
for (i = 0; i < TX_RING_SIZE; i++) {
j = 2*i;
yp->tx_skbuff[i] = 0;
yp->tx_ring[j].dbdma_cmd = cpu_to_le32(CMD_STOP);
yp->tx_ring[j].branch_addr = cpu_to_le32(yp->tx_ring_dma +
(j+1)*sizeof(struct yellowfin_desc));
j++;
if (yp->flags & FullTxStatus) {
yp->tx_ring[j].dbdma_cmd =
cpu_to_le32(CMD_TXSTATUS | sizeof(*yp->tx_status));
yp->tx_ring[j].request_cnt = sizeof(*yp->tx_status);
yp->tx_ring[j].addr = cpu_to_le32(yp->tx_status_dma +
i*sizeof(struct tx_status_words));
} else {
yp->tx_ring[j].dbdma_cmd =
cpu_to_le32(CMD_TXSTATUS | INTR_ALWAYS | 2);
yp->tx_ring[j].request_cnt = 2;
yp->tx_ring[j].addr = cpu_to_le32(yp->tx_status_dma +
i*sizeof(struct tx_status_words) +
&(yp->tx_status[0].tx_errs) -
&(yp->tx_status[0]));
}
yp->tx_ring[j].branch_addr = cpu_to_le32(yp->tx_ring_dma +
((j+1)%(2*TX_RING_SIZE))*sizeof(struct yellowfin_desc));
}
yp->tx_ring[++j].dbdma_cmd |= cpu_to_le32(BRANCH_ALWAYS | INTR_ALWAYS);
}
#endif
yp->tx_tail_desc = &yp->tx_status[0];
return 0;
}
static netdev_tx_t yellowfin_start_xmit(struct sk_buff *skb,
struct net_device *dev)
{
struct yellowfin_private *yp = netdev_priv(dev);
unsigned entry;
int len = skb->len;
netif_stop_queue (dev);
entry = yp->cur_tx % TX_RING_SIZE;
if (gx_fix) {
int cacheline_end = ((unsigned long)skb->data + skb->len) % 32;
if (cacheline_end > 24 || cacheline_end == 0) {
len = skb->len + 32 - cacheline_end + 1;
if (skb_padto(skb, len)) {
yp->tx_skbuff[entry] = NULL;
netif_wake_queue(dev);
return NETDEV_TX_OK;
}
}
}
yp->tx_skbuff[entry] = skb;
#ifdef NO_TXSTATS
yp->tx_ring[entry].addr = cpu_to_le32(pci_map_single(yp->pci_dev,
skb->data, len, PCI_DMA_TODEVICE));
yp->tx_ring[entry].result_status = 0;
if (entry >= TX_RING_SIZE-1) {
yp->tx_ring[0].dbdma_cmd = cpu_to_le32(CMD_STOP);
yp->tx_ring[TX_RING_SIZE-1].dbdma_cmd =
cpu_to_le32(CMD_TX_PKT|BRANCH_ALWAYS | len);
} else {
yp->tx_ring[entry+1].dbdma_cmd = cpu_to_le32(CMD_STOP);
yp->tx_ring[entry].dbdma_cmd =
cpu_to_le32(CMD_TX_PKT | BRANCH_IFTRUE | len);
}
yp->cur_tx++;
#else
yp->tx_ring[entry<<1].request_cnt = len;
yp->tx_ring[entry<<1].addr = cpu_to_le32(pci_map_single(yp->pci_dev,
skb->data, len, PCI_DMA_TODEVICE));
yp->cur_tx++;
{
unsigned next_entry = yp->cur_tx % TX_RING_SIZE;
yp->tx_ring[next_entry<<1].dbdma_cmd = cpu_to_le32(CMD_STOP);
}
yp->tx_ring[entry<<1].dbdma_cmd =
cpu_to_le32( ((entry % 6) == 0 ? CMD_TX_PKT|INTR_ALWAYS|BRANCH_IFTRUE :
CMD_TX_PKT | BRANCH_IFTRUE) | len);
#endif
iowrite32(0x10001000, yp->base + TxCtrl);
if (yp->cur_tx - yp->dirty_tx < TX_QUEUE_SIZE)
netif_start_queue (dev);
else
yp->tx_full = 1;
if (yellowfin_debug > 4) {
netdev_printk(KERN_DEBUG, dev, "Yellowfin transmit frame #%d queued in slot %d\n",
yp->cur_tx, entry);
}
return NETDEV_TX_OK;
}
static irqreturn_t yellowfin_interrupt(int irq, void *dev_instance)
{
struct net_device *dev = dev_instance;
struct yellowfin_private *yp;
void __iomem *ioaddr;
int boguscnt = max_interrupt_work;
unsigned int handled = 0;
yp = netdev_priv(dev);
ioaddr = yp->base;
spin_lock (&yp->lock);
do {
u16 intr_status = ioread16(ioaddr + IntrClear);
if (yellowfin_debug > 4)
netdev_printk(KERN_DEBUG, dev, "Yellowfin interrupt, status %04x\n",
intr_status);
if (intr_status == 0)
break;
handled = 1;
if (intr_status & (IntrRxDone | IntrEarlyRx)) {
yellowfin_rx(dev);
iowrite32(0x10001000, ioaddr + RxCtrl);
}
#ifdef NO_TXSTATS
for (; yp->cur_tx - yp->dirty_tx > 0; yp->dirty_tx++) {
int entry = yp->dirty_tx % TX_RING_SIZE;
struct sk_buff *skb;
if (yp->tx_ring[entry].result_status == 0)
break;
skb = yp->tx_skbuff[entry];
dev->stats.tx_packets++;
dev->stats.tx_bytes += skb->len;
pci_unmap_single(yp->pci_dev, le32_to_cpu(yp->tx_ring[entry].addr),
skb->len, PCI_DMA_TODEVICE);
dev_kfree_skb_irq(skb);
yp->tx_skbuff[entry] = NULL;
}
if (yp->tx_full &&
yp->cur_tx - yp->dirty_tx < TX_QUEUE_SIZE - 4) {
yp->tx_full = 0;
netif_wake_queue(dev);
}
#else
if ((intr_status & IntrTxDone) || (yp->tx_tail_desc->tx_errs)) {
unsigned dirty_tx = yp->dirty_tx;
for (dirty_tx = yp->dirty_tx; yp->cur_tx - dirty_tx > 0;
dirty_tx++) {
int entry = dirty_tx % TX_RING_SIZE;
u16 tx_errs = yp->tx_status[entry].tx_errs;
struct sk_buff *skb;
#ifndef final_version
if (yellowfin_debug > 5)
netdev_printk(KERN_DEBUG, dev, "Tx queue %d check, Tx status %04x %04x %04x %04x\n",
entry,
yp->tx_status[entry].tx_cnt,
yp->tx_status[entry].tx_errs,
yp->tx_status[entry].total_tx_cnt,
yp->tx_status[entry].paused);
#endif
if (tx_errs == 0)
break;
skb = yp->tx_skbuff[entry];
if (tx_errs & 0xF810) {
#ifndef final_version
if (yellowfin_debug > 1)
netdev_printk(KERN_DEBUG, dev, "Transmit error, Tx status %04x\n",
tx_errs);
#endif
dev->stats.tx_errors++;
if (tx_errs & 0xF800) dev->stats.tx_aborted_errors++;
if (tx_errs & 0x0800) dev->stats.tx_carrier_errors++;
if (tx_errs & 0x2000) dev->stats.tx_window_errors++;
if (tx_errs & 0x8000) dev->stats.tx_fifo_errors++;
} else {
#ifndef final_version
if (yellowfin_debug > 4)
netdev_printk(KERN_DEBUG, dev, "Normal transmit, Tx status %04x\n",
tx_errs);
#endif
dev->stats.tx_bytes += skb->len;
dev->stats.collisions += tx_errs & 15;
dev->stats.tx_packets++;
}
pci_unmap_single(yp->pci_dev,
yp->tx_ring[entry<<1].addr, skb->len,
PCI_DMA_TODEVICE);
dev_kfree_skb_irq(skb);
yp->tx_skbuff[entry] = 0;
yp->tx_status[entry].tx_errs = 0;
}
#ifndef final_version
if (yp->cur_tx - dirty_tx > TX_RING_SIZE) {
netdev_err(dev, "Out-of-sync dirty pointer, %d vs. %d, full=%d\n",
dirty_tx, yp->cur_tx, yp->tx_full);
dirty_tx += TX_RING_SIZE;
}
#endif
if (yp->tx_full &&
yp->cur_tx - dirty_tx < TX_QUEUE_SIZE - 2) {
yp->tx_full = 0;
netif_wake_queue(dev);
}
yp->dirty_tx = dirty_tx;
yp->tx_tail_desc = &yp->tx_status[dirty_tx % TX_RING_SIZE];
}
#endif
if (intr_status & 0x2ee)
yellowfin_error(dev, intr_status);
if (--boguscnt < 0) {
netdev_warn(dev, "Too much work at interrupt, status=%#04x\n",
intr_status);
break;
}
} while (1);
if (yellowfin_debug > 3)
netdev_printk(KERN_DEBUG, dev, "exiting interrupt, status=%#04x\n",
ioread16(ioaddr + IntrStatus));
spin_unlock (&yp->lock);
return IRQ_RETVAL(handled);
}
static int yellowfin_rx(struct net_device *dev)
{
struct yellowfin_private *yp = netdev_priv(dev);
int entry = yp->cur_rx % RX_RING_SIZE;
int boguscnt = yp->dirty_rx + RX_RING_SIZE - yp->cur_rx;
if (yellowfin_debug > 4) {
printk(KERN_DEBUG " In yellowfin_rx(), entry %d status %08x\n",
entry, yp->rx_ring[entry].result_status);
printk(KERN_DEBUG " #%d desc. %08x %08x %08x\n",
entry, yp->rx_ring[entry].dbdma_cmd, yp->rx_ring[entry].addr,
yp->rx_ring[entry].result_status);
}
while (1) {
struct yellowfin_desc *desc = &yp->rx_ring[entry];
struct sk_buff *rx_skb = yp->rx_skbuff[entry];
s16 frame_status;
u16 desc_status;
int data_size;
u8 *buf_addr;
if(!desc->result_status)
break;
pci_dma_sync_single_for_cpu(yp->pci_dev, le32_to_cpu(desc->addr),
yp->rx_buf_sz, PCI_DMA_FROMDEVICE);
desc_status = le32_to_cpu(desc->result_status) >> 16;
buf_addr = rx_skb->data;
data_size = (le32_to_cpu(desc->dbdma_cmd) -
le32_to_cpu(desc->result_status)) & 0xffff;
frame_status = get_unaligned_le16(&(buf_addr[data_size - 2]));
if (yellowfin_debug > 4)
printk(KERN_DEBUG " %s() status was %04x\n",
__func__, frame_status);
if (--boguscnt < 0)
break;
if ( ! (desc_status & RX_EOP)) {
if (data_size != 0)
netdev_warn(dev, "Oversized Ethernet frame spanned multiple buffers, status %04x, data_size %d!\n",
desc_status, data_size);
dev->stats.rx_length_errors++;
} else if ((yp->drv_flags & IsGigabit) && (frame_status & 0x0038)) {
if (yellowfin_debug > 3)
printk(KERN_DEBUG " %s() Rx error was %04x\n",
__func__, frame_status);
dev->stats.rx_errors++;
if (frame_status & 0x0060) dev->stats.rx_length_errors++;
if (frame_status & 0x0008) dev->stats.rx_frame_errors++;
if (frame_status & 0x0010) dev->stats.rx_crc_errors++;
if (frame_status < 0) dev->stats.rx_dropped++;
} else if ( !(yp->drv_flags & IsGigabit) &&
((buf_addr[data_size-1] & 0x85) || buf_addr[data_size-2] & 0xC0)) {
u8 status1 = buf_addr[data_size-2];
u8 status2 = buf_addr[data_size-1];
dev->stats.rx_errors++;
if (status1 & 0xC0) dev->stats.rx_length_errors++;
if (status2 & 0x03) dev->stats.rx_frame_errors++;
if (status2 & 0x04) dev->stats.rx_crc_errors++;
if (status2 & 0x80) dev->stats.rx_dropped++;
#ifdef YF_PROTOTYPE
} else if ((yp->flags & HasMACAddrBug) &&
memcmp(le32_to_cpu(yp->rx_ring_dma +
entry*sizeof(struct yellowfin_desc)),
dev->dev_addr, 6) != 0 &&
memcmp(le32_to_cpu(yp->rx_ring_dma +
entry*sizeof(struct yellowfin_desc)),
"\377\377\377\377\377\377", 6) != 0) {
if (bogus_rx++ == 0)
netdev_warn(dev, "Bad frame to %pM\n",
buf_addr);
#endif
} else {
struct sk_buff *skb;
int pkt_len = data_size -
(yp->chip_id ? 7 : 8 + buf_addr[data_size - 8]);
#ifndef final_version
if (yellowfin_debug > 4)
printk(KERN_DEBUG " %s() normal Rx pkt length %d of %d, bogus_cnt %d\n",
__func__, pkt_len, data_size, boguscnt);
#endif
if (pkt_len > rx_copybreak) {
skb_put(skb = rx_skb, pkt_len);
pci_unmap_single(yp->pci_dev,
le32_to_cpu(yp->rx_ring[entry].addr),
yp->rx_buf_sz,
PCI_DMA_FROMDEVICE);
yp->rx_skbuff[entry] = NULL;
} else {
skb = netdev_alloc_skb(dev, pkt_len + 2);
if (skb == NULL)
break;
skb_reserve(skb, 2);
skb_copy_to_linear_data(skb, rx_skb->data, pkt_len);
skb_put(skb, pkt_len);
pci_dma_sync_single_for_device(yp->pci_dev,
le32_to_cpu(desc->addr),
yp->rx_buf_sz,
PCI_DMA_FROMDEVICE);
}
skb->protocol = eth_type_trans(skb, dev);
netif_rx(skb);
dev->stats.rx_packets++;
dev->stats.rx_bytes += pkt_len;
}
entry = (++yp->cur_rx) % RX_RING_SIZE;
}
for (; yp->cur_rx - yp->dirty_rx > 0; yp->dirty_rx++) {
entry = yp->dirty_rx % RX_RING_SIZE;
if (yp->rx_skbuff[entry] == NULL) {
struct sk_buff *skb = netdev_alloc_skb(dev, yp->rx_buf_sz + 2);
if (skb == NULL)
break;
yp->rx_skbuff[entry] = skb;
skb_reserve(skb, 2);
yp->rx_ring[entry].addr = cpu_to_le32(pci_map_single(yp->pci_dev,
skb->data, yp->rx_buf_sz, PCI_DMA_FROMDEVICE));
}
yp->rx_ring[entry].dbdma_cmd = cpu_to_le32(CMD_STOP);
yp->rx_ring[entry].result_status = 0;
if (entry != 0)
yp->rx_ring[entry - 1].dbdma_cmd =
cpu_to_le32(CMD_RX_BUF | INTR_ALWAYS | yp->rx_buf_sz);
else
yp->rx_ring[RX_RING_SIZE - 1].dbdma_cmd =
cpu_to_le32(CMD_RX_BUF | INTR_ALWAYS | BRANCH_ALWAYS
| yp->rx_buf_sz);
}
return 0;
}
static void yellowfin_error(struct net_device *dev, int intr_status)
{
netdev_err(dev, "Something Wicked happened! %04x\n", intr_status);
if (intr_status & (IntrTxPCIErr | IntrTxPCIFault))
dev->stats.tx_errors++;
if (intr_status & (IntrRxPCIErr | IntrRxPCIFault))
dev->stats.rx_errors++;
}
static int yellowfin_close(struct net_device *dev)
{
struct yellowfin_private *yp = netdev_priv(dev);
void __iomem *ioaddr = yp->base;
int i;
netif_stop_queue (dev);
if (yellowfin_debug > 1) {
netdev_printk(KERN_DEBUG, dev, "Shutting down ethercard, status was Tx %04x Rx %04x Int %02x\n",
ioread16(ioaddr + TxStatus),
ioread16(ioaddr + RxStatus),
ioread16(ioaddr + IntrStatus));
netdev_printk(KERN_DEBUG, dev, "Queue pointers were Tx %d / %d, Rx %d / %d\n",
yp->cur_tx, yp->dirty_tx,
yp->cur_rx, yp->dirty_rx);
}
iowrite16(0x0000, ioaddr + IntrEnb);
iowrite32(0x80000000, ioaddr + RxCtrl);
iowrite32(0x80000000, ioaddr + TxCtrl);
del_timer(&yp->timer);
#if defined(__i386__)
if (yellowfin_debug > 2) {
printk(KERN_DEBUG " Tx ring at %08llx:\n",
(unsigned long long)yp->tx_ring_dma);
for (i = 0; i < TX_RING_SIZE*2; i++)
printk(KERN_DEBUG " %c #%d desc. %08x %08x %08x %08x\n",
ioread32(ioaddr + TxPtr) == (long)&yp->tx_ring[i] ? '>' : ' ',
i, yp->tx_ring[i].dbdma_cmd, yp->tx_ring[i].addr,
yp->tx_ring[i].branch_addr, yp->tx_ring[i].result_status);
printk(KERN_DEBUG " Tx status %p:\n", yp->tx_status);
for (i = 0; i < TX_RING_SIZE; i++)
printk(KERN_DEBUG " #%d status %04x %04x %04x %04x\n",
i, yp->tx_status[i].tx_cnt, yp->tx_status[i].tx_errs,
yp->tx_status[i].total_tx_cnt, yp->tx_status[i].paused);
printk(KERN_DEBUG " Rx ring %08llx:\n",
(unsigned long long)yp->rx_ring_dma);
for (i = 0; i < RX_RING_SIZE; i++) {
printk(KERN_DEBUG " %c #%d desc. %08x %08x %08x\n",
ioread32(ioaddr + RxPtr) == (long)&yp->rx_ring[i] ? '>' : ' ',
i, yp->rx_ring[i].dbdma_cmd, yp->rx_ring[i].addr,
yp->rx_ring[i].result_status);
if (yellowfin_debug > 6) {
if (get_unaligned((u8*)yp->rx_ring[i].addr) != 0x69) {
int j;
printk(KERN_DEBUG);
for (j = 0; j < 0x50; j++)
pr_cont(" %04x",
get_unaligned(((u16*)yp->rx_ring[i].addr) + j));
pr_cont("\n");
}
}
}
}
#endif
free_irq(yp->pci_dev->irq, dev);
for (i = 0; i < RX_RING_SIZE; i++) {
yp->rx_ring[i].dbdma_cmd = cpu_to_le32(CMD_STOP);
yp->rx_ring[i].addr = cpu_to_le32(0xBADF00D0);
if (yp->rx_skbuff[i]) {
dev_kfree_skb(yp->rx_skbuff[i]);
}
yp->rx_skbuff[i] = NULL;
}
for (i = 0; i < TX_RING_SIZE; i++) {
if (yp->tx_skbuff[i])
dev_kfree_skb(yp->tx_skbuff[i]);
yp->tx_skbuff[i] = NULL;
}
#ifdef YF_PROTOTYPE
if (yellowfin_debug > 0) {
netdev_printk(KERN_DEBUG, dev, "Received %d frames that we should not have\n",
bogus_rx);
}
#endif
return 0;
}
static void set_rx_mode(struct net_device *dev)
{
struct yellowfin_private *yp = netdev_priv(dev);
void __iomem *ioaddr = yp->base;
u16 cfg_value = ioread16(ioaddr + Cnfg);
iowrite16(cfg_value & ~0x1000, ioaddr + Cnfg);
if (dev->flags & IFF_PROMISC) {
iowrite16(0x000F, ioaddr + AddrMode);
} else if ((netdev_mc_count(dev) > 64) ||
(dev->flags & IFF_ALLMULTI)) {
iowrite16(0x000B, ioaddr + AddrMode);
} else if (!netdev_mc_empty(dev)) {
struct netdev_hw_addr *ha;
u16 hash_table[4];
int i;
memset(hash_table, 0, sizeof(hash_table));
netdev_for_each_mc_addr(ha, dev) {
unsigned int bit;
if (yp->drv_flags & HasMulticastBug) {
bit = (ether_crc_le(3, ha->addr) >> 3) & 0x3f;
hash_table[bit >> 4] |= (1 << bit);
bit = (ether_crc_le(4, ha->addr) >> 3) & 0x3f;
hash_table[bit >> 4] |= (1 << bit);
bit = (ether_crc_le(5, ha->addr) >> 3) & 0x3f;
hash_table[bit >> 4] |= (1 << bit);
}
bit = (ether_crc_le(6, ha->addr) >> 3) & 0x3f;
hash_table[bit >> 4] |= (1 << bit);
}
for (i = 0; i < 4; i++)
iowrite16(hash_table[i], ioaddr + HashTbl + i*2);
iowrite16(0x0003, ioaddr + AddrMode);
} else {
iowrite16(0x0001, ioaddr + AddrMode);
}
iowrite16(cfg_value | 0x1000, ioaddr + Cnfg);
}
static void yellowfin_get_drvinfo(struct net_device *dev, struct ethtool_drvinfo *info)
{
struct yellowfin_private *np = netdev_priv(dev);
strcpy(info->driver, DRV_NAME);
strcpy(info->version, DRV_VERSION);
strcpy(info->bus_info, pci_name(np->pci_dev));
}
static int netdev_ioctl(struct net_device *dev, struct ifreq *rq, int cmd)
{
struct yellowfin_private *np = netdev_priv(dev);
void __iomem *ioaddr = np->base;
struct mii_ioctl_data *data = if_mii(rq);
switch(cmd) {
case SIOCGMIIPHY:
data->phy_id = np->phys[0] & 0x1f;
case SIOCGMIIREG:
data->val_out = mdio_read(ioaddr, data->phy_id & 0x1f, data->reg_num & 0x1f);
return 0;
case SIOCSMIIREG:
if (data->phy_id == np->phys[0]) {
u16 value = data->val_in;
switch (data->reg_num) {
case 0:
np->medialock = (value & 0x9000) ? 0 : 1;
if (np->medialock)
np->full_duplex = (value & 0x0100) ? 1 : 0;
break;
case 4: np->advertising = value; break;
}
}
mdio_write(ioaddr, data->phy_id & 0x1f, data->reg_num & 0x1f, data->val_in);
return 0;
default:
return -EOPNOTSUPP;
}
}
static void __devexit yellowfin_remove_one (struct pci_dev *pdev)
{
struct net_device *dev = pci_get_drvdata(pdev);
struct yellowfin_private *np;
BUG_ON(!dev);
np = netdev_priv(dev);
pci_free_consistent(pdev, STATUS_TOTAL_SIZE, np->tx_status,
np->tx_status_dma);
pci_free_consistent(pdev, RX_TOTAL_SIZE, np->rx_ring, np->rx_ring_dma);
pci_free_consistent(pdev, TX_TOTAL_SIZE, np->tx_ring, np->tx_ring_dma);
unregister_netdev (dev);
pci_iounmap(pdev, np->base);
pci_release_regions (pdev);
free_netdev (dev);
pci_set_drvdata(pdev, NULL);
}
static int __init yellowfin_init (void)
{
#ifdef MODULE
printk(version);
#endif
return pci_register_driver(&yellowfin_driver);
}
static void __exit yellowfin_cleanup (void)
{
pci_unregister_driver (&yellowfin_driver);
}
