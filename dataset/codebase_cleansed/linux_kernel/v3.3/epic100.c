static int __devinit epic_init_one (struct pci_dev *pdev,
const struct pci_device_id *ent)
{
static int card_idx = -1;
long ioaddr;
int chip_idx = (int) ent->driver_data;
int irq;
struct net_device *dev;
struct epic_private *ep;
int i, ret, option = 0, duplex = 0;
void *ring_space;
dma_addr_t ring_dma;
#ifndef MODULE
static int printed_version;
if (!printed_version++)
printk(KERN_INFO "%s%s", version, version2);
#endif
card_idx++;
ret = pci_enable_device(pdev);
if (ret)
goto out;
irq = pdev->irq;
if (pci_resource_len(pdev, 0) < EPIC_TOTAL_SIZE) {
dev_err(&pdev->dev, "no PCI region space\n");
ret = -ENODEV;
goto err_out_disable;
}
pci_set_master(pdev);
ret = pci_request_regions(pdev, DRV_NAME);
if (ret < 0)
goto err_out_disable;
ret = -ENOMEM;
dev = alloc_etherdev(sizeof (*ep));
if (!dev) {
dev_err(&pdev->dev, "no memory for eth device\n");
goto err_out_free_res;
}
SET_NETDEV_DEV(dev, &pdev->dev);
#ifdef USE_IO_OPS
ioaddr = pci_resource_start (pdev, 0);
#else
ioaddr = pci_resource_start (pdev, 1);
ioaddr = (long) pci_ioremap_bar(pdev, 1);
if (!ioaddr) {
dev_err(&pdev->dev, "ioremap failed\n");
goto err_out_free_netdev;
}
#endif
pci_set_drvdata(pdev, dev);
ep = netdev_priv(dev);
ep->mii.dev = dev;
ep->mii.mdio_read = mdio_read;
ep->mii.mdio_write = mdio_write;
ep->mii.phy_id_mask = 0x1f;
ep->mii.reg_num_mask = 0x1f;
ring_space = pci_alloc_consistent(pdev, TX_TOTAL_SIZE, &ring_dma);
if (!ring_space)
goto err_out_iounmap;
ep->tx_ring = ring_space;
ep->tx_ring_dma = ring_dma;
ring_space = pci_alloc_consistent(pdev, RX_TOTAL_SIZE, &ring_dma);
if (!ring_space)
goto err_out_unmap_tx;
ep->rx_ring = ring_space;
ep->rx_ring_dma = ring_dma;
if (dev->mem_start) {
option = dev->mem_start;
duplex = (dev->mem_start & 16) ? 1 : 0;
} else if (card_idx >= 0 && card_idx < MAX_UNITS) {
if (options[card_idx] >= 0)
option = options[card_idx];
if (full_duplex[card_idx] >= 0)
duplex = full_duplex[card_idx];
}
dev->base_addr = ioaddr;
dev->irq = irq;
spin_lock_init(&ep->lock);
spin_lock_init(&ep->napi_lock);
ep->reschedule_in_poll = 0;
outl(0x4200, ioaddr + GENCTL);
for (i = 16; i > 0; i--)
outl(0x0008, ioaddr + TEST1);
outl(0x12, ioaddr + MIICfg);
if (chip_idx == 1)
outl((inl(ioaddr + NVCTL) & ~0x003C) | 0x4800, ioaddr + NVCTL);
outl(0x0200, ioaddr + GENCTL);
for (i = 0; i < 3; i++)
((__le16 *)dev->dev_addr)[i] = cpu_to_le16(inw(ioaddr + LAN0 + i*4));
if (debug > 2) {
dev_printk(KERN_DEBUG, &pdev->dev, "EEPROM contents:\n");
for (i = 0; i < 64; i++)
printk(" %4.4x%s", read_eeprom(ioaddr, i),
i % 16 == 15 ? "\n" : "");
}
ep->pci_dev = pdev;
ep->chip_id = chip_idx;
ep->chip_flags = pci_id_tbl[chip_idx].drv_flags;
ep->irq_mask =
(ep->chip_flags & TYPE2_INTR ? PCIBusErr175 : PCIBusErr170)
| CntFull | TxUnderrun | EpicNapiEvent;
{
int phy, phy_idx = 0;
for (phy = 1; phy < 32 && phy_idx < sizeof(ep->phys); phy++) {
int mii_status = mdio_read(dev, phy, MII_BMSR);
if (mii_status != 0xffff && mii_status != 0x0000) {
ep->phys[phy_idx++] = phy;
dev_info(&pdev->dev,
"MII transceiver #%d control "
"%4.4x status %4.4x.\n",
phy, mdio_read(dev, phy, 0), mii_status);
}
}
ep->mii_phy_cnt = phy_idx;
if (phy_idx != 0) {
phy = ep->phys[0];
ep->mii.advertising = mdio_read(dev, phy, MII_ADVERTISE);
dev_info(&pdev->dev,
"Autonegotiation advertising %4.4x link "
"partner %4.4x.\n",
ep->mii.advertising, mdio_read(dev, phy, 5));
} else if ( ! (ep->chip_flags & NO_MII)) {
dev_warn(&pdev->dev,
"***WARNING***: No MII transceiver found!\n");
ep->phys[0] = 3;
}
ep->mii.phy_id = ep->phys[0];
}
if (ep->chip_flags & MII_PWRDWN)
outl(inl(ioaddr + NVCTL) & ~0x483C, ioaddr + NVCTL);
outl(0x0008, ioaddr + GENCTL);
if (duplex) {
ep->mii.force_media = ep->mii.full_duplex = 1;
dev_info(&pdev->dev, "Forced full duplex requested.\n");
}
dev->if_port = ep->default_port = option;
dev->netdev_ops = &epic_netdev_ops;
dev->ethtool_ops = &netdev_ethtool_ops;
dev->watchdog_timeo = TX_TIMEOUT;
netif_napi_add(dev, &ep->napi, epic_poll, 64);
ret = register_netdev(dev);
if (ret < 0)
goto err_out_unmap_rx;
printk(KERN_INFO "%s: %s at %#lx, IRQ %d, %pM\n",
dev->name, pci_id_tbl[chip_idx].name, ioaddr, dev->irq,
dev->dev_addr);
out:
return ret;
err_out_unmap_rx:
pci_free_consistent(pdev, RX_TOTAL_SIZE, ep->rx_ring, ep->rx_ring_dma);
err_out_unmap_tx:
pci_free_consistent(pdev, TX_TOTAL_SIZE, ep->tx_ring, ep->tx_ring_dma);
err_out_iounmap:
#ifndef USE_IO_OPS
iounmap(ioaddr);
err_out_free_netdev:
#endif
free_netdev(dev);
err_out_free_res:
pci_release_regions(pdev);
err_out_disable:
pci_disable_device(pdev);
goto out;
}
static void epic_disable_int(struct net_device *dev, struct epic_private *ep)
{
long ioaddr = dev->base_addr;
outl(0x00000000, ioaddr + INTMASK);
}
static inline void __epic_pci_commit(long ioaddr)
{
#ifndef USE_IO_OPS
inl(ioaddr + INTMASK);
#endif
}
static inline void epic_napi_irq_off(struct net_device *dev,
struct epic_private *ep)
{
long ioaddr = dev->base_addr;
outl(ep->irq_mask & ~EpicNapiEvent, ioaddr + INTMASK);
__epic_pci_commit(ioaddr);
}
static inline void epic_napi_irq_on(struct net_device *dev,
struct epic_private *ep)
{
long ioaddr = dev->base_addr;
outl(ep->irq_mask | EpicNapiEvent, ioaddr + INTMASK);
}
static int __devinit read_eeprom(long ioaddr, int location)
{
int i;
int retval = 0;
long ee_addr = ioaddr + EECTL;
int read_cmd = location |
(inl(ee_addr) & 0x40 ? EE_READ64_CMD : EE_READ256_CMD);
outl(EE_ENB & ~EE_CS, ee_addr);
outl(EE_ENB, ee_addr);
for (i = 12; i >= 0; i--) {
short dataval = (read_cmd & (1 << i)) ? EE_WRITE_1 : EE_WRITE_0;
outl(EE_ENB | dataval, ee_addr);
eeprom_delay();
outl(EE_ENB | dataval | EE_SHIFT_CLK, ee_addr);
eeprom_delay();
}
outl(EE_ENB, ee_addr);
for (i = 16; i > 0; i--) {
outl(EE_ENB | EE_SHIFT_CLK, ee_addr);
eeprom_delay();
retval = (retval << 1) | ((inl(ee_addr) & EE_DATA_READ) ? 1 : 0);
outl(EE_ENB, ee_addr);
eeprom_delay();
}
outl(EE_ENB & ~EE_CS, ee_addr);
return retval;
}
static int mdio_read(struct net_device *dev, int phy_id, int location)
{
long ioaddr = dev->base_addr;
int read_cmd = (phy_id << 9) | (location << 4) | MII_READOP;
int i;
outl(read_cmd, ioaddr + MIICtrl);
for (i = 400; i > 0; i--) {
barrier();
if ((inl(ioaddr + MIICtrl) & MII_READOP) == 0) {
if (phy_id == 1 && location < 6 &&
inw(ioaddr + MIIData) == 0xffff) {
outl(read_cmd, ioaddr + MIICtrl);
continue;
}
return inw(ioaddr + MIIData);
}
}
return 0xffff;
}
static void mdio_write(struct net_device *dev, int phy_id, int loc, int value)
{
long ioaddr = dev->base_addr;
int i;
outw(value, ioaddr + MIIData);
outl((phy_id << 9) | (loc << 4) | MII_WRITEOP, ioaddr + MIICtrl);
for (i = 10000; i > 0; i--) {
barrier();
if ((inl(ioaddr + MIICtrl) & MII_WRITEOP) == 0)
break;
}
}
static int epic_open(struct net_device *dev)
{
struct epic_private *ep = netdev_priv(dev);
long ioaddr = dev->base_addr;
int i;
int retval;
outl(0x4001, ioaddr + GENCTL);
napi_enable(&ep->napi);
if ((retval = request_irq(dev->irq, epic_interrupt, IRQF_SHARED, dev->name, dev))) {
napi_disable(&ep->napi);
return retval;
}
epic_init_ring(dev);
outl(0x4000, ioaddr + GENCTL);
for (i = 16; i > 0; i--)
outl(0x0008, ioaddr + TEST1);
#if 0
outl(dev->if_port == 1 ? 0x13 : 0x12, ioaddr + MIICfg);
#endif
if (ep->chip_flags & MII_PWRDWN)
outl((inl(ioaddr + NVCTL) & ~0x003C) | 0x4800, ioaddr + NVCTL);
#ifdef __BIG_ENDIAN
outl(0x4432 | (RX_FIFO_THRESH<<8), ioaddr + GENCTL);
inl(ioaddr + GENCTL);
outl(0x0432 | (RX_FIFO_THRESH<<8), ioaddr + GENCTL);
#else
outl(0x4412 | (RX_FIFO_THRESH<<8), ioaddr + GENCTL);
inl(ioaddr + GENCTL);
outl(0x0412 | (RX_FIFO_THRESH<<8), ioaddr + GENCTL);
#endif
udelay(20);
for (i = 0; i < 3; i++)
outl(le16_to_cpu(((__le16*)dev->dev_addr)[i]), ioaddr + LAN0 + i*4);
ep->tx_threshold = TX_FIFO_THRESH;
outl(ep->tx_threshold, ioaddr + TxThresh);
if (media2miictl[dev->if_port & 15]) {
if (ep->mii_phy_cnt)
mdio_write(dev, ep->phys[0], MII_BMCR, media2miictl[dev->if_port&15]);
if (dev->if_port == 1) {
if (debug > 1)
printk(KERN_INFO "%s: Using the 10base2 transceiver, MII "
"status %4.4x.\n",
dev->name, mdio_read(dev, ep->phys[0], MII_BMSR));
}
} else {
int mii_lpa = mdio_read(dev, ep->phys[0], MII_LPA);
if (mii_lpa != 0xffff) {
if ((mii_lpa & LPA_100FULL) || (mii_lpa & 0x01C0) == LPA_10FULL)
ep->mii.full_duplex = 1;
else if (! (mii_lpa & LPA_LPACK))
mdio_write(dev, ep->phys[0], MII_BMCR, BMCR_ANENABLE|BMCR_ANRESTART);
if (debug > 1)
printk(KERN_INFO "%s: Setting %s-duplex based on MII xcvr %d"
" register read of %4.4x.\n", dev->name,
ep->mii.full_duplex ? "full" : "half",
ep->phys[0], mii_lpa);
}
}
outl(ep->mii.full_duplex ? 0x7F : 0x79, ioaddr + TxCtrl);
outl(ep->rx_ring_dma, ioaddr + PRxCDAR);
outl(ep->tx_ring_dma, ioaddr + PTxCDAR);
set_rx_mode(dev);
outl(StartRx | RxQueued, ioaddr + COMMAND);
netif_start_queue(dev);
outl((ep->chip_flags & TYPE2_INTR ? PCIBusErr175 : PCIBusErr170)
| CntFull | TxUnderrun
| RxError | RxHeader | EpicNapiEvent, ioaddr + INTMASK);
if (debug > 1)
printk(KERN_DEBUG "%s: epic_open() ioaddr %lx IRQ %d status %4.4x "
"%s-duplex.\n",
dev->name, ioaddr, dev->irq, (int)inl(ioaddr + GENCTL),
ep->mii.full_duplex ? "full" : "half");
init_timer(&ep->timer);
ep->timer.expires = jiffies + 3*HZ;
ep->timer.data = (unsigned long)dev;
ep->timer.function = epic_timer;
add_timer(&ep->timer);
return 0;
}
static void epic_pause(struct net_device *dev)
{
long ioaddr = dev->base_addr;
netif_stop_queue (dev);
outl(0x00000000, ioaddr + INTMASK);
outw(StopRx | StopTxDMA | StopRxDMA, ioaddr + COMMAND);
if (inw(ioaddr + COMMAND) != 0xffff) {
dev->stats.rx_missed_errors += inb(ioaddr + MPCNT);
dev->stats.rx_frame_errors += inb(ioaddr + ALICNT);
dev->stats.rx_crc_errors += inb(ioaddr + CRCCNT);
}
epic_rx(dev, RX_RING_SIZE);
}
static void epic_restart(struct net_device *dev)
{
long ioaddr = dev->base_addr;
struct epic_private *ep = netdev_priv(dev);
int i;
outl(0x4001, ioaddr + GENCTL);
printk(KERN_DEBUG "%s: Restarting the EPIC chip, Rx %d/%d Tx %d/%d.\n",
dev->name, ep->cur_rx, ep->dirty_rx, ep->dirty_tx, ep->cur_tx);
udelay(1);
for (i = 16; i > 0; i--)
outl(0x0008, ioaddr + TEST1);
#ifdef __BIG_ENDIAN
outl(0x0432 | (RX_FIFO_THRESH<<8), ioaddr + GENCTL);
#else
outl(0x0412 | (RX_FIFO_THRESH<<8), ioaddr + GENCTL);
#endif
outl(dev->if_port == 1 ? 0x13 : 0x12, ioaddr + MIICfg);
if (ep->chip_flags & MII_PWRDWN)
outl((inl(ioaddr + NVCTL) & ~0x003C) | 0x4800, ioaddr + NVCTL);
for (i = 0; i < 3; i++)
outl(le16_to_cpu(((__le16*)dev->dev_addr)[i]), ioaddr + LAN0 + i*4);
ep->tx_threshold = TX_FIFO_THRESH;
outl(ep->tx_threshold, ioaddr + TxThresh);
outl(ep->mii.full_duplex ? 0x7F : 0x79, ioaddr + TxCtrl);
outl(ep->rx_ring_dma + (ep->cur_rx%RX_RING_SIZE)*
sizeof(struct epic_rx_desc), ioaddr + PRxCDAR);
outl(ep->tx_ring_dma + (ep->dirty_tx%TX_RING_SIZE)*
sizeof(struct epic_tx_desc), ioaddr + PTxCDAR);
set_rx_mode(dev);
outl(StartRx | RxQueued, ioaddr + COMMAND);
outl((ep->chip_flags & TYPE2_INTR ? PCIBusErr175 : PCIBusErr170)
| CntFull | TxUnderrun
| RxError | RxHeader | EpicNapiEvent, ioaddr + INTMASK);
printk(KERN_DEBUG "%s: epic_restart() done, cmd status %4.4x, ctl %4.4x"
" interrupt %4.4x.\n",
dev->name, (int)inl(ioaddr + COMMAND), (int)inl(ioaddr + GENCTL),
(int)inl(ioaddr + INTSTAT));
}
static void check_media(struct net_device *dev)
{
struct epic_private *ep = netdev_priv(dev);
long ioaddr = dev->base_addr;
int mii_lpa = ep->mii_phy_cnt ? mdio_read(dev, ep->phys[0], MII_LPA) : 0;
int negotiated = mii_lpa & ep->mii.advertising;
int duplex = (negotiated & 0x0100) || (negotiated & 0x01C0) == 0x0040;
if (ep->mii.force_media)
return;
if (mii_lpa == 0xffff)
return;
if (ep->mii.full_duplex != duplex) {
ep->mii.full_duplex = duplex;
printk(KERN_INFO "%s: Setting %s-duplex based on MII #%d link"
" partner capability of %4.4x.\n", dev->name,
ep->mii.full_duplex ? "full" : "half", ep->phys[0], mii_lpa);
outl(ep->mii.full_duplex ? 0x7F : 0x79, ioaddr + TxCtrl);
}
}
static void epic_timer(unsigned long data)
{
struct net_device *dev = (struct net_device *)data;
struct epic_private *ep = netdev_priv(dev);
long ioaddr = dev->base_addr;
int next_tick = 5*HZ;
if (debug > 3) {
printk(KERN_DEBUG "%s: Media monitor tick, Tx status %8.8x.\n",
dev->name, (int)inl(ioaddr + TxSTAT));
printk(KERN_DEBUG "%s: Other registers are IntMask %4.4x "
"IntStatus %4.4x RxStatus %4.4x.\n",
dev->name, (int)inl(ioaddr + INTMASK),
(int)inl(ioaddr + INTSTAT), (int)inl(ioaddr + RxSTAT));
}
check_media(dev);
ep->timer.expires = jiffies + next_tick;
add_timer(&ep->timer);
}
static void epic_tx_timeout(struct net_device *dev)
{
struct epic_private *ep = netdev_priv(dev);
long ioaddr = dev->base_addr;
if (debug > 0) {
printk(KERN_WARNING "%s: Transmit timeout using MII device, "
"Tx status %4.4x.\n",
dev->name, (int)inw(ioaddr + TxSTAT));
if (debug > 1) {
printk(KERN_DEBUG "%s: Tx indices: dirty_tx %d, cur_tx %d.\n",
dev->name, ep->dirty_tx, ep->cur_tx);
}
}
if (inw(ioaddr + TxSTAT) & 0x10) {
dev->stats.tx_fifo_errors++;
outl(RestartTx, ioaddr + COMMAND);
} else {
epic_restart(dev);
outl(TxQueued, dev->base_addr + COMMAND);
}
dev->trans_start = jiffies;
dev->stats.tx_errors++;
if (!ep->tx_full)
netif_wake_queue(dev);
}
static void epic_init_ring(struct net_device *dev)
{
struct epic_private *ep = netdev_priv(dev);
int i;
ep->tx_full = 0;
ep->dirty_tx = ep->cur_tx = 0;
ep->cur_rx = ep->dirty_rx = 0;
ep->rx_buf_sz = (dev->mtu <= 1500 ? PKT_BUF_SZ : dev->mtu + 32);
for (i = 0; i < RX_RING_SIZE; i++) {
ep->rx_ring[i].rxstatus = 0;
ep->rx_ring[i].buflength = ep->rx_buf_sz;
ep->rx_ring[i].next = ep->rx_ring_dma +
(i+1)*sizeof(struct epic_rx_desc);
ep->rx_skbuff[i] = NULL;
}
ep->rx_ring[i-1].next = ep->rx_ring_dma;
for (i = 0; i < RX_RING_SIZE; i++) {
struct sk_buff *skb = dev_alloc_skb(ep->rx_buf_sz + 2);
ep->rx_skbuff[i] = skb;
if (skb == NULL)
break;
skb_reserve(skb, 2);
ep->rx_ring[i].bufaddr = pci_map_single(ep->pci_dev,
skb->data, ep->rx_buf_sz, PCI_DMA_FROMDEVICE);
ep->rx_ring[i].rxstatus = DescOwn;
}
ep->dirty_rx = (unsigned int)(i - RX_RING_SIZE);
for (i = 0; i < TX_RING_SIZE; i++) {
ep->tx_skbuff[i] = NULL;
ep->tx_ring[i].txstatus = 0x0000;
ep->tx_ring[i].next = ep->tx_ring_dma +
(i+1)*sizeof(struct epic_tx_desc);
}
ep->tx_ring[i-1].next = ep->tx_ring_dma;
}
static netdev_tx_t epic_start_xmit(struct sk_buff *skb, struct net_device *dev)
{
struct epic_private *ep = netdev_priv(dev);
int entry, free_count;
u32 ctrl_word;
unsigned long flags;
if (skb_padto(skb, ETH_ZLEN))
return NETDEV_TX_OK;
spin_lock_irqsave(&ep->lock, flags);
free_count = ep->cur_tx - ep->dirty_tx;
entry = ep->cur_tx % TX_RING_SIZE;
ep->tx_skbuff[entry] = skb;
ep->tx_ring[entry].bufaddr = pci_map_single(ep->pci_dev, skb->data,
skb->len, PCI_DMA_TODEVICE);
if (free_count < TX_QUEUE_LEN/2) {
ctrl_word = 0x100000;
} else if (free_count == TX_QUEUE_LEN/2) {
ctrl_word = 0x140000;
} else if (free_count < TX_QUEUE_LEN - 1) {
ctrl_word = 0x100000;
} else {
ctrl_word = 0x140000;
ep->tx_full = 1;
}
ep->tx_ring[entry].buflength = ctrl_word | skb->len;
ep->tx_ring[entry].txstatus =
((skb->len >= ETH_ZLEN ? skb->len : ETH_ZLEN) << 16)
| DescOwn;
ep->cur_tx++;
if (ep->tx_full)
netif_stop_queue(dev);
spin_unlock_irqrestore(&ep->lock, flags);
outl(TxQueued, dev->base_addr + COMMAND);
if (debug > 4)
printk(KERN_DEBUG "%s: Queued Tx packet size %d to slot %d, "
"flag %2.2x Tx status %8.8x.\n",
dev->name, (int)skb->len, entry, ctrl_word,
(int)inl(dev->base_addr + TxSTAT));
return NETDEV_TX_OK;
}
static void epic_tx_error(struct net_device *dev, struct epic_private *ep,
int status)
{
struct net_device_stats *stats = &dev->stats;
#ifndef final_version
if (debug > 1)
printk(KERN_DEBUG "%s: Transmit error, Tx status %8.8x.\n",
dev->name, status);
#endif
stats->tx_errors++;
if (status & 0x1050)
stats->tx_aborted_errors++;
if (status & 0x0008)
stats->tx_carrier_errors++;
if (status & 0x0040)
stats->tx_window_errors++;
if (status & 0x0010)
stats->tx_fifo_errors++;
}
static void epic_tx(struct net_device *dev, struct epic_private *ep)
{
unsigned int dirty_tx, cur_tx;
cur_tx = ep->cur_tx;
for (dirty_tx = ep->dirty_tx; cur_tx - dirty_tx > 0; dirty_tx++) {
struct sk_buff *skb;
int entry = dirty_tx % TX_RING_SIZE;
int txstatus = ep->tx_ring[entry].txstatus;
if (txstatus & DescOwn)
break;
if (likely(txstatus & 0x0001)) {
dev->stats.collisions += (txstatus >> 8) & 15;
dev->stats.tx_packets++;
dev->stats.tx_bytes += ep->tx_skbuff[entry]->len;
} else
epic_tx_error(dev, ep, txstatus);
skb = ep->tx_skbuff[entry];
pci_unmap_single(ep->pci_dev, ep->tx_ring[entry].bufaddr,
skb->len, PCI_DMA_TODEVICE);
dev_kfree_skb_irq(skb);
ep->tx_skbuff[entry] = NULL;
}
#ifndef final_version
if (cur_tx - dirty_tx > TX_RING_SIZE) {
printk(KERN_WARNING
"%s: Out-of-sync dirty pointer, %d vs. %d, full=%d.\n",
dev->name, dirty_tx, cur_tx, ep->tx_full);
dirty_tx += TX_RING_SIZE;
}
#endif
ep->dirty_tx = dirty_tx;
if (ep->tx_full && cur_tx - dirty_tx < TX_QUEUE_LEN - 4) {
ep->tx_full = 0;
netif_wake_queue(dev);
}
}
static irqreturn_t epic_interrupt(int irq, void *dev_instance)
{
struct net_device *dev = dev_instance;
struct epic_private *ep = netdev_priv(dev);
long ioaddr = dev->base_addr;
unsigned int handled = 0;
int status;
status = inl(ioaddr + INTSTAT);
outl(status & EpicNormalEvent, ioaddr + INTSTAT);
if (debug > 4) {
printk(KERN_DEBUG "%s: Interrupt, status=%#8.8x new "
"intstat=%#8.8x.\n", dev->name, status,
(int)inl(ioaddr + INTSTAT));
}
if ((status & IntrSummary) == 0)
goto out;
handled = 1;
if ((status & EpicNapiEvent) && !ep->reschedule_in_poll) {
spin_lock(&ep->napi_lock);
if (napi_schedule_prep(&ep->napi)) {
epic_napi_irq_off(dev, ep);
__napi_schedule(&ep->napi);
} else
ep->reschedule_in_poll++;
spin_unlock(&ep->napi_lock);
}
status &= ~EpicNapiEvent;
if (status & (CntFull | TxUnderrun | PCIBusErr170 | PCIBusErr175)) {
if (status == EpicRemoved)
goto out;
dev->stats.rx_missed_errors += inb(ioaddr + MPCNT);
dev->stats.rx_frame_errors += inb(ioaddr + ALICNT);
dev->stats.rx_crc_errors += inb(ioaddr + CRCCNT);
if (status & TxUnderrun) {
dev->stats.tx_fifo_errors++;
outl(ep->tx_threshold += 128, ioaddr + TxThresh);
outl(RestartTx, ioaddr + COMMAND);
}
if (status & PCIBusErr170) {
printk(KERN_ERR "%s: PCI Bus Error! status %4.4x.\n",
dev->name, status);
epic_pause(dev);
epic_restart(dev);
}
outl(status & 0x7f18, ioaddr + INTSTAT);
}
out:
if (debug > 3) {
printk(KERN_DEBUG "%s: exit interrupt, intr_status=%#4.4x.\n",
dev->name, status);
}
return IRQ_RETVAL(handled);
}
static int epic_rx(struct net_device *dev, int budget)
{
struct epic_private *ep = netdev_priv(dev);
int entry = ep->cur_rx % RX_RING_SIZE;
int rx_work_limit = ep->dirty_rx + RX_RING_SIZE - ep->cur_rx;
int work_done = 0;
if (debug > 4)
printk(KERN_DEBUG " In epic_rx(), entry %d %8.8x.\n", entry,
ep->rx_ring[entry].rxstatus);
if (rx_work_limit > budget)
rx_work_limit = budget;
while ((ep->rx_ring[entry].rxstatus & DescOwn) == 0) {
int status = ep->rx_ring[entry].rxstatus;
if (debug > 4)
printk(KERN_DEBUG " epic_rx() status was %8.8x.\n", status);
if (--rx_work_limit < 0)
break;
if (status & 0x2006) {
if (debug > 2)
printk(KERN_DEBUG "%s: epic_rx() error status was %8.8x.\n",
dev->name, status);
if (status & 0x2000) {
printk(KERN_WARNING "%s: Oversized Ethernet frame spanned "
"multiple buffers, status %4.4x!\n", dev->name, status);
dev->stats.rx_length_errors++;
} else if (status & 0x0006)
dev->stats.rx_errors++;
} else {
short pkt_len = (status >> 16) - 4;
struct sk_buff *skb;
if (pkt_len > PKT_BUF_SZ - 4) {
printk(KERN_ERR "%s: Oversized Ethernet frame, status %x "
"%d bytes.\n",
dev->name, status, pkt_len);
pkt_len = 1514;
}
if (pkt_len < rx_copybreak &&
(skb = dev_alloc_skb(pkt_len + 2)) != NULL) {
skb_reserve(skb, 2);
pci_dma_sync_single_for_cpu(ep->pci_dev,
ep->rx_ring[entry].bufaddr,
ep->rx_buf_sz,
PCI_DMA_FROMDEVICE);
skb_copy_to_linear_data(skb, ep->rx_skbuff[entry]->data, pkt_len);
skb_put(skb, pkt_len);
pci_dma_sync_single_for_device(ep->pci_dev,
ep->rx_ring[entry].bufaddr,
ep->rx_buf_sz,
PCI_DMA_FROMDEVICE);
} else {
pci_unmap_single(ep->pci_dev,
ep->rx_ring[entry].bufaddr,
ep->rx_buf_sz, PCI_DMA_FROMDEVICE);
skb_put(skb = ep->rx_skbuff[entry], pkt_len);
ep->rx_skbuff[entry] = NULL;
}
skb->protocol = eth_type_trans(skb, dev);
netif_receive_skb(skb);
dev->stats.rx_packets++;
dev->stats.rx_bytes += pkt_len;
}
work_done++;
entry = (++ep->cur_rx) % RX_RING_SIZE;
}
for (; ep->cur_rx - ep->dirty_rx > 0; ep->dirty_rx++) {
entry = ep->dirty_rx % RX_RING_SIZE;
if (ep->rx_skbuff[entry] == NULL) {
struct sk_buff *skb;
skb = ep->rx_skbuff[entry] = dev_alloc_skb(ep->rx_buf_sz + 2);
if (skb == NULL)
break;
skb_reserve(skb, 2);
ep->rx_ring[entry].bufaddr = pci_map_single(ep->pci_dev,
skb->data, ep->rx_buf_sz, PCI_DMA_FROMDEVICE);
work_done++;
}
ep->rx_ring[entry].rxstatus = DescOwn;
}
return work_done;
}
static void epic_rx_err(struct net_device *dev, struct epic_private *ep)
{
long ioaddr = dev->base_addr;
int status;
status = inl(ioaddr + INTSTAT);
if (status == EpicRemoved)
return;
if (status & RxOverflow)
dev->stats.rx_errors++;
if (status & (RxOverflow | RxFull))
outw(RxQueued, ioaddr + COMMAND);
}
static int epic_poll(struct napi_struct *napi, int budget)
{
struct epic_private *ep = container_of(napi, struct epic_private, napi);
struct net_device *dev = ep->mii.dev;
int work_done = 0;
long ioaddr = dev->base_addr;
rx_action:
epic_tx(dev, ep);
work_done += epic_rx(dev, budget);
epic_rx_err(dev, ep);
if (work_done < budget) {
unsigned long flags;
int more;
spin_lock_irqsave(&ep->napi_lock, flags);
more = ep->reschedule_in_poll;
if (!more) {
__napi_complete(napi);
outl(EpicNapiEvent, ioaddr + INTSTAT);
epic_napi_irq_on(dev, ep);
} else
ep->reschedule_in_poll--;
spin_unlock_irqrestore(&ep->napi_lock, flags);
if (more)
goto rx_action;
}
return work_done;
}
static int epic_close(struct net_device *dev)
{
long ioaddr = dev->base_addr;
struct epic_private *ep = netdev_priv(dev);
struct sk_buff *skb;
int i;
netif_stop_queue(dev);
napi_disable(&ep->napi);
if (debug > 1)
printk(KERN_DEBUG "%s: Shutting down ethercard, status was %2.2x.\n",
dev->name, (int)inl(ioaddr + INTSTAT));
del_timer_sync(&ep->timer);
epic_disable_int(dev, ep);
free_irq(dev->irq, dev);
epic_pause(dev);
for (i = 0; i < RX_RING_SIZE; i++) {
skb = ep->rx_skbuff[i];
ep->rx_skbuff[i] = NULL;
ep->rx_ring[i].rxstatus = 0;
ep->rx_ring[i].buflength = 0;
if (skb) {
pci_unmap_single(ep->pci_dev, ep->rx_ring[i].bufaddr,
ep->rx_buf_sz, PCI_DMA_FROMDEVICE);
dev_kfree_skb(skb);
}
ep->rx_ring[i].bufaddr = 0xBADF00D0;
}
for (i = 0; i < TX_RING_SIZE; i++) {
skb = ep->tx_skbuff[i];
ep->tx_skbuff[i] = NULL;
if (!skb)
continue;
pci_unmap_single(ep->pci_dev, ep->tx_ring[i].bufaddr,
skb->len, PCI_DMA_TODEVICE);
dev_kfree_skb(skb);
}
outl(0x0008, ioaddr + GENCTL);
return 0;
}
static struct net_device_stats *epic_get_stats(struct net_device *dev)
{
long ioaddr = dev->base_addr;
if (netif_running(dev)) {
dev->stats.rx_missed_errors += inb(ioaddr + MPCNT);
dev->stats.rx_frame_errors += inb(ioaddr + ALICNT);
dev->stats.rx_crc_errors += inb(ioaddr + CRCCNT);
}
return &dev->stats;
}
static void set_rx_mode(struct net_device *dev)
{
long ioaddr = dev->base_addr;
struct epic_private *ep = netdev_priv(dev);
unsigned char mc_filter[8];
int i;
if (dev->flags & IFF_PROMISC) {
outl(0x002C, ioaddr + RxCtrl);
memset(mc_filter, 0xff, sizeof(mc_filter));
} else if ((!netdev_mc_empty(dev)) || (dev->flags & IFF_ALLMULTI)) {
memset(mc_filter, 0xff, sizeof(mc_filter));
outl(0x000C, ioaddr + RxCtrl);
} else if (netdev_mc_empty(dev)) {
outl(0x0004, ioaddr + RxCtrl);
return;
} else {
struct netdev_hw_addr *ha;
memset(mc_filter, 0, sizeof(mc_filter));
netdev_for_each_mc_addr(ha, dev) {
unsigned int bit_nr =
ether_crc_le(ETH_ALEN, ha->addr) & 0x3f;
mc_filter[bit_nr >> 3] |= (1 << bit_nr);
}
}
if (memcmp(mc_filter, ep->mc_filter, sizeof(mc_filter))) {
for (i = 0; i < 4; i++)
outw(((u16 *)mc_filter)[i], ioaddr + MC0 + i*4);
memcpy(ep->mc_filter, mc_filter, sizeof(mc_filter));
}
}
static void netdev_get_drvinfo (struct net_device *dev, struct ethtool_drvinfo *info)
{
struct epic_private *np = netdev_priv(dev);
strlcpy(info->driver, DRV_NAME, sizeof(info->driver));
strlcpy(info->version, DRV_VERSION, sizeof(info->version));
strlcpy(info->bus_info, pci_name(np->pci_dev), sizeof(info->bus_info));
}
static int netdev_get_settings(struct net_device *dev, struct ethtool_cmd *cmd)
{
struct epic_private *np = netdev_priv(dev);
int rc;
spin_lock_irq(&np->lock);
rc = mii_ethtool_gset(&np->mii, cmd);
spin_unlock_irq(&np->lock);
return rc;
}
static int netdev_set_settings(struct net_device *dev, struct ethtool_cmd *cmd)
{
struct epic_private *np = netdev_priv(dev);
int rc;
spin_lock_irq(&np->lock);
rc = mii_ethtool_sset(&np->mii, cmd);
spin_unlock_irq(&np->lock);
return rc;
}
static int netdev_nway_reset(struct net_device *dev)
{
struct epic_private *np = netdev_priv(dev);
return mii_nway_restart(&np->mii);
}
static u32 netdev_get_link(struct net_device *dev)
{
struct epic_private *np = netdev_priv(dev);
return mii_link_ok(&np->mii);
}
static u32 netdev_get_msglevel(struct net_device *dev)
{
return debug;
}
static void netdev_set_msglevel(struct net_device *dev, u32 value)
{
debug = value;
}
static int ethtool_begin(struct net_device *dev)
{
unsigned long ioaddr = dev->base_addr;
if (! netif_running(dev)) {
outl(0x0200, ioaddr + GENCTL);
outl((inl(ioaddr + NVCTL) & ~0x003C) | 0x4800, ioaddr + NVCTL);
}
return 0;
}
static void ethtool_complete(struct net_device *dev)
{
unsigned long ioaddr = dev->base_addr;
if (! netif_running(dev)) {
outl(0x0008, ioaddr + GENCTL);
outl((inl(ioaddr + NVCTL) & ~0x483C) | 0x0000, ioaddr + NVCTL);
}
}
static int netdev_ioctl(struct net_device *dev, struct ifreq *rq, int cmd)
{
struct epic_private *np = netdev_priv(dev);
long ioaddr = dev->base_addr;
struct mii_ioctl_data *data = if_mii(rq);
int rc;
if (! netif_running(dev)) {
outl(0x0200, ioaddr + GENCTL);
outl((inl(ioaddr + NVCTL) & ~0x003C) | 0x4800, ioaddr + NVCTL);
}
spin_lock_irq(&np->lock);
rc = generic_mii_ioctl(&np->mii, data, cmd, NULL);
spin_unlock_irq(&np->lock);
if (! netif_running(dev)) {
outl(0x0008, ioaddr + GENCTL);
outl((inl(ioaddr + NVCTL) & ~0x483C) | 0x0000, ioaddr + NVCTL);
}
return rc;
}
static void __devexit epic_remove_one (struct pci_dev *pdev)
{
struct net_device *dev = pci_get_drvdata(pdev);
struct epic_private *ep = netdev_priv(dev);
pci_free_consistent(pdev, TX_TOTAL_SIZE, ep->tx_ring, ep->tx_ring_dma);
pci_free_consistent(pdev, RX_TOTAL_SIZE, ep->rx_ring, ep->rx_ring_dma);
unregister_netdev(dev);
#ifndef USE_IO_OPS
iounmap((void*) dev->base_addr);
#endif
pci_release_regions(pdev);
free_netdev(dev);
pci_disable_device(pdev);
pci_set_drvdata(pdev, NULL);
}
static int epic_suspend (struct pci_dev *pdev, pm_message_t state)
{
struct net_device *dev = pci_get_drvdata(pdev);
long ioaddr = dev->base_addr;
if (!netif_running(dev))
return 0;
epic_pause(dev);
outl(0x0008, ioaddr + GENCTL);
return 0;
}
static int epic_resume (struct pci_dev *pdev)
{
struct net_device *dev = pci_get_drvdata(pdev);
if (!netif_running(dev))
return 0;
epic_restart(dev);
return 0;
}
static int __init epic_init (void)
{
#ifdef MODULE
printk (KERN_INFO "%s%s",
version, version2);
#endif
return pci_register_driver(&epic_driver);
}
static void __exit epic_cleanup (void)
{
pci_unregister_driver (&epic_driver);
}
