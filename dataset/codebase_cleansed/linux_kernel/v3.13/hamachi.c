static int hamachi_init_one(struct pci_dev *pdev,
const struct pci_device_id *ent)
{
struct hamachi_private *hmp;
int option, i, rx_int_var, tx_int_var, boguscnt;
int chip_id = ent->driver_data;
int irq;
void __iomem *ioaddr;
unsigned long base;
static int card_idx;
struct net_device *dev;
void *ring_space;
dma_addr_t ring_dma;
int ret = -ENOMEM;
#ifndef MODULE
static int printed_version;
if (!printed_version++)
printk(version);
#endif
if (pci_enable_device(pdev)) {
ret = -EIO;
goto err_out;
}
base = pci_resource_start(pdev, 0);
#ifdef __alpha__
base |= (pci_resource_start(pdev, 1) << 32);
#endif
pci_set_master(pdev);
i = pci_request_regions(pdev, DRV_NAME);
if (i)
return i;
irq = pdev->irq;
ioaddr = ioremap(base, 0x400);
if (!ioaddr)
goto err_out_release;
dev = alloc_etherdev(sizeof(struct hamachi_private));
if (!dev)
goto err_out_iounmap;
SET_NETDEV_DEV(dev, &pdev->dev);
for (i = 0; i < 6; i++)
dev->dev_addr[i] = 1 ? read_eeprom(ioaddr, 4 + i)
: readb(ioaddr + StationAddr + i);
#if ! defined(final_version)
if (hamachi_debug > 4)
for (i = 0; i < 0x10; i++)
printk("%2.2x%s",
read_eeprom(ioaddr, i), i % 16 != 15 ? " " : "\n");
#endif
hmp = netdev_priv(dev);
spin_lock_init(&hmp->lock);
hmp->mii_if.dev = dev;
hmp->mii_if.mdio_read = mdio_read;
hmp->mii_if.mdio_write = mdio_write;
hmp->mii_if.phy_id_mask = 0x1f;
hmp->mii_if.reg_num_mask = 0x1f;
ring_space = pci_alloc_consistent(pdev, TX_TOTAL_SIZE, &ring_dma);
if (!ring_space)
goto err_out_cleardev;
hmp->tx_ring = ring_space;
hmp->tx_ring_dma = ring_dma;
ring_space = pci_alloc_consistent(pdev, RX_TOTAL_SIZE, &ring_dma);
if (!ring_space)
goto err_out_unmap_tx;
hmp->rx_ring = ring_space;
hmp->rx_ring_dma = ring_dma;
option = card_idx < MAX_UNITS ? options[card_idx] : 0;
if (dev->mem_start)
option = dev->mem_start;
force32 = force32 ? force32 :
((option >= 0) ? ((option & 0x00000070) >> 4) : 0 );
if (force32)
writeb(force32, ioaddr + VirtualJumpers);
writeb(0x01, ioaddr + ChipReset);
udelay(10);
i = readb(ioaddr + PCIClkMeas);
for (boguscnt = 0; (!(i & 0x080)) && boguscnt < 1000; boguscnt++){
udelay(10);
i = readb(ioaddr + PCIClkMeas);
}
hmp->base = ioaddr;
pci_set_drvdata(pdev, dev);
hmp->chip_id = chip_id;
hmp->pci_dev = pdev;
if (option > 0) {
hmp->option = option;
if (option & 0x200)
hmp->mii_if.full_duplex = 1;
else if (option & 0x080)
hmp->mii_if.full_duplex = 0;
hmp->default_port = option & 15;
if (hmp->default_port)
hmp->mii_if.force_media = 1;
}
if (card_idx < MAX_UNITS && full_duplex[card_idx] > 0)
hmp->mii_if.full_duplex = 1;
if (hmp->mii_if.full_duplex || (option & 0x080))
hmp->duplex_lock = 1;
max_rx_latency = max_rx_latency & 0x00ff;
max_rx_gap = max_rx_gap & 0x00ff;
min_rx_pkt = min_rx_pkt & 0x00ff;
max_tx_latency = max_tx_latency & 0x00ff;
max_tx_gap = max_tx_gap & 0x00ff;
min_tx_pkt = min_tx_pkt & 0x00ff;
rx_int_var = card_idx < MAX_UNITS ? rx_params[card_idx] : -1;
tx_int_var = card_idx < MAX_UNITS ? tx_params[card_idx] : -1;
hmp->rx_int_var = rx_int_var >= 0 ? rx_int_var :
(min_rx_pkt << 16 | max_rx_gap << 8 | max_rx_latency);
hmp->tx_int_var = tx_int_var >= 0 ? tx_int_var :
(min_tx_pkt << 16 | max_tx_gap << 8 | max_tx_latency);
dev->netdev_ops = &hamachi_netdev_ops;
if (chip_tbl[hmp->chip_id].flags & CanHaveMII)
SET_ETHTOOL_OPS(dev, &ethtool_ops);
else
SET_ETHTOOL_OPS(dev, &ethtool_ops_no_mii);
dev->watchdog_timeo = TX_TIMEOUT;
if (mtu)
dev->mtu = mtu;
i = register_netdev(dev);
if (i) {
ret = i;
goto err_out_unmap_rx;
}
printk(KERN_INFO "%s: %s type %x at %p, %pM, IRQ %d.\n",
dev->name, chip_tbl[chip_id].name, readl(ioaddr + ChipRev),
ioaddr, dev->dev_addr, irq);
i = readb(ioaddr + PCIClkMeas);
printk(KERN_INFO "%s: %d-bit %d Mhz PCI bus (%d), Virtual Jumpers "
"%2.2x, LPA %4.4x.\n",
dev->name, readw(ioaddr + MiscStatus) & 1 ? 64 : 32,
i ? 2000/(i&0x7f) : 0, i&0x7f, (int)readb(ioaddr + VirtualJumpers),
readw(ioaddr + ANLinkPartnerAbility));
if (chip_tbl[hmp->chip_id].flags & CanHaveMII) {
int phy, phy_idx = 0;
for (phy = 0; phy < 32 && phy_idx < MII_CNT; phy++) {
int mii_status = mdio_read(dev, phy, MII_BMSR);
if (mii_status != 0xffff &&
mii_status != 0x0000) {
hmp->phys[phy_idx++] = phy;
hmp->mii_if.advertising = mdio_read(dev, phy, MII_ADVERTISE);
printk(KERN_INFO "%s: MII PHY found at address %d, status "
"0x%4.4x advertising %4.4x.\n",
dev->name, phy, mii_status, hmp->mii_if.advertising);
}
}
hmp->mii_cnt = phy_idx;
if (hmp->mii_cnt > 0)
hmp->mii_if.phy_id = hmp->phys[0];
else
memset(&hmp->mii_if, 0, sizeof(hmp->mii_if));
}
writew(0x0400, ioaddr + ANXchngCtrl);
writew(0x08e0, ioaddr + ANAdvertise);
writew(0x1000, ioaddr + ANCtrl);
card_idx++;
return 0;
err_out_unmap_rx:
pci_free_consistent(pdev, RX_TOTAL_SIZE, hmp->rx_ring,
hmp->rx_ring_dma);
err_out_unmap_tx:
pci_free_consistent(pdev, TX_TOTAL_SIZE, hmp->tx_ring,
hmp->tx_ring_dma);
err_out_cleardev:
free_netdev (dev);
err_out_iounmap:
iounmap(ioaddr);
err_out_release:
pci_release_regions(pdev);
err_out:
return ret;
}
static int read_eeprom(void __iomem *ioaddr, int location)
{
int bogus_cnt = 1000;
while ((readb(ioaddr + EECmdStatus) & 0x40) && --bogus_cnt > 0);
writew(location, ioaddr + EEAddr);
writeb(0x02, ioaddr + EECmdStatus);
bogus_cnt = 1000;
while ((readb(ioaddr + EECmdStatus) & 0x40) && --bogus_cnt > 0);
if (hamachi_debug > 5)
printk(" EEPROM status is %2.2x after %d ticks.\n",
(int)readb(ioaddr + EECmdStatus), 1000- bogus_cnt);
return readb(ioaddr + EEData);
}
static int mdio_read(struct net_device *dev, int phy_id, int location)
{
struct hamachi_private *hmp = netdev_priv(dev);
void __iomem *ioaddr = hmp->base;
int i;
for (i = 10000; i >= 0; i--)
if ((readw(ioaddr + MII_Status) & 1) == 0)
break;
writew((phy_id<<8) + location, ioaddr + MII_Addr);
writew(0x0001, ioaddr + MII_Cmd);
for (i = 10000; i >= 0; i--)
if ((readw(ioaddr + MII_Status) & 1) == 0)
break;
return readw(ioaddr + MII_Rd_Data);
}
static void mdio_write(struct net_device *dev, int phy_id, int location, int value)
{
struct hamachi_private *hmp = netdev_priv(dev);
void __iomem *ioaddr = hmp->base;
int i;
for (i = 10000; i >= 0; i--)
if ((readw(ioaddr + MII_Status) & 1) == 0)
break;
writew((phy_id<<8) + location, ioaddr + MII_Addr);
writew(value, ioaddr + MII_Wr_Data);
for (i = 10000; i >= 0; i--)
if ((readw(ioaddr + MII_Status) & 1) == 0)
break;
}
static int hamachi_open(struct net_device *dev)
{
struct hamachi_private *hmp = netdev_priv(dev);
void __iomem *ioaddr = hmp->base;
int i;
u32 rx_int_var, tx_int_var;
u16 fifo_info;
i = request_irq(hmp->pci_dev->irq, hamachi_interrupt, IRQF_SHARED,
dev->name, dev);
if (i)
return i;
hamachi_init_ring(dev);
#if ADDRLEN == 64
writel(hmp->rx_ring_dma, ioaddr + RxPtr);
writel(hmp->rx_ring_dma >> 32, ioaddr + RxPtr + 4);
writel(hmp->tx_ring_dma, ioaddr + TxPtr);
writel(hmp->tx_ring_dma >> 32, ioaddr + TxPtr + 4);
#else
writel(hmp->rx_ring_dma, ioaddr + RxPtr);
writel(hmp->tx_ring_dma, ioaddr + TxPtr);
#endif
for (i = 0; i < 6; i++)
writeb(dev->dev_addr[i], ioaddr + StationAddr + i);
fifo_info = (readw(ioaddr + GPIO) & 0x00C0) >> 6;
switch (fifo_info){
case 0 :
writew(0x0000, ioaddr + FIFOcfg);
break;
case 1 :
writew(0x0028, ioaddr + FIFOcfg);
break;
case 2 :
writew(0x004C, ioaddr + FIFOcfg);
break;
case 3 :
writew(0x006C, ioaddr + FIFOcfg);
break;
default :
printk(KERN_WARNING "%s: Unsupported external memory config!\n",
dev->name);
writew(0x0000, ioaddr + FIFOcfg);
break;
}
if (dev->if_port == 0)
dev->if_port = hmp->default_port;
if (hmp->duplex_lock != 1)
hmp->mii_if.full_duplex = 1;
writew(0x0001, ioaddr + RxChecksum);
writew(0x0000, ioaddr + TxChecksum);
writew(0x8000, ioaddr + MACCnfg);
writew(0x215F, ioaddr + MACCnfg);
writew(0x000C, ioaddr + FrameGap0);
writew(0x1018, ioaddr + FrameGap1);
writew(0x0780, ioaddr + MACCnfg2);
writel(0x0030FFFF, ioaddr + FlowCtrl);
writew(MAX_FRAME_SIZE, ioaddr + MaxFrameSize);
writew(0x0400, ioaddr + ANXchngCtrl);
writeb(0x03, ioaddr + LEDCtrl);
rx_int_var = hmp->rx_int_var;
tx_int_var = hmp->tx_int_var;
if (hamachi_debug > 1) {
printk("max_tx_latency: %d, max_tx_gap: %d, min_tx_pkt: %d\n",
tx_int_var & 0x00ff, (tx_int_var & 0x00ff00) >> 8,
(tx_int_var & 0x00ff0000) >> 16);
printk("max_rx_latency: %d, max_rx_gap: %d, min_rx_pkt: %d\n",
rx_int_var & 0x00ff, (rx_int_var & 0x00ff00) >> 8,
(rx_int_var & 0x00ff0000) >> 16);
printk("rx_int_var: %x, tx_int_var: %x\n", rx_int_var, tx_int_var);
}
writel(tx_int_var, ioaddr + TxIntrCtrl);
writel(rx_int_var, ioaddr + RxIntrCtrl);
set_rx_mode(dev);
netif_start_queue(dev);
writel(0x80878787, ioaddr + InterruptEnable);
writew(0x0000, ioaddr + EventStatus);
#if ADDRLEN == 64
writew(0x005D, ioaddr + RxDMACtrl);
writew(0x005D, ioaddr + TxDMACtrl);
#else
writew(0x001D, ioaddr + RxDMACtrl);
writew(0x001D, ioaddr + TxDMACtrl);
#endif
writew(0x0001, ioaddr + RxCmd);
if (hamachi_debug > 2) {
printk(KERN_DEBUG "%s: Done hamachi_open(), status: Rx %x Tx %x.\n",
dev->name, readw(ioaddr + RxStatus), readw(ioaddr + TxStatus));
}
init_timer(&hmp->timer);
hmp->timer.expires = RUN_AT((24*HZ)/10);
hmp->timer.data = (unsigned long)dev;
hmp->timer.function = hamachi_timer;
add_timer(&hmp->timer);
return 0;
}
static inline int hamachi_tx(struct net_device *dev)
{
struct hamachi_private *hmp = netdev_priv(dev);
for (; hmp->cur_tx - hmp->dirty_tx > 0; hmp->dirty_tx++) {
int entry = hmp->dirty_tx % TX_RING_SIZE;
struct sk_buff *skb;
if (hmp->tx_ring[entry].status_n_length & cpu_to_le32(DescOwn))
break;
skb = hmp->tx_skbuff[entry];
if (skb) {
pci_unmap_single(hmp->pci_dev,
leXX_to_cpu(hmp->tx_ring[entry].addr),
skb->len, PCI_DMA_TODEVICE);
dev_kfree_skb(skb);
hmp->tx_skbuff[entry] = NULL;
}
hmp->tx_ring[entry].status_n_length = 0;
if (entry >= TX_RING_SIZE-1)
hmp->tx_ring[TX_RING_SIZE-1].status_n_length |=
cpu_to_le32(DescEndRing);
dev->stats.tx_packets++;
}
return 0;
}
static void hamachi_timer(unsigned long data)
{
struct net_device *dev = (struct net_device *)data;
struct hamachi_private *hmp = netdev_priv(dev);
void __iomem *ioaddr = hmp->base;
int next_tick = 10*HZ;
if (hamachi_debug > 2) {
printk(KERN_INFO "%s: Hamachi Autonegotiation status %4.4x, LPA "
"%4.4x.\n", dev->name, readw(ioaddr + ANStatus),
readw(ioaddr + ANLinkPartnerAbility));
printk(KERN_INFO "%s: Autonegotiation regs %4.4x %4.4x %4.4x "
"%4.4x %4.4x %4.4x.\n", dev->name,
readw(ioaddr + 0x0e0),
readw(ioaddr + 0x0e2),
readw(ioaddr + 0x0e4),
readw(ioaddr + 0x0e6),
readw(ioaddr + 0x0e8),
readw(ioaddr + 0x0eA));
}
hmp->timer.expires = RUN_AT(next_tick);
add_timer(&hmp->timer);
}
static void hamachi_tx_timeout(struct net_device *dev)
{
int i;
struct hamachi_private *hmp = netdev_priv(dev);
void __iomem *ioaddr = hmp->base;
printk(KERN_WARNING "%s: Hamachi transmit timed out, status %8.8x,"
" resetting...\n", dev->name, (int)readw(ioaddr + TxStatus));
{
printk(KERN_DEBUG " Rx ring %p: ", hmp->rx_ring);
for (i = 0; i < RX_RING_SIZE; i++)
printk(KERN_CONT " %8.8x",
le32_to_cpu(hmp->rx_ring[i].status_n_length));
printk(KERN_CONT "\n");
printk(KERN_DEBUG" Tx ring %p: ", hmp->tx_ring);
for (i = 0; i < TX_RING_SIZE; i++)
printk(KERN_CONT " %4.4x",
le32_to_cpu(hmp->tx_ring[i].status_n_length));
printk(KERN_CONT "\n");
}
dev->if_port = 0;
for (i = 0; i < RX_RING_SIZE; i++)
hmp->rx_ring[i].status_n_length &= cpu_to_le32(~DescOwn);
for (i = 0; i < TX_RING_SIZE; i++){
struct sk_buff *skb;
if (i >= TX_RING_SIZE - 1)
hmp->tx_ring[i].status_n_length =
cpu_to_le32(DescEndRing) |
(hmp->tx_ring[i].status_n_length &
cpu_to_le32(0x0000ffff));
else
hmp->tx_ring[i].status_n_length &= cpu_to_le32(0x0000ffff);
skb = hmp->tx_skbuff[i];
if (skb){
pci_unmap_single(hmp->pci_dev, leXX_to_cpu(hmp->tx_ring[i].addr),
skb->len, PCI_DMA_TODEVICE);
dev_kfree_skb(skb);
hmp->tx_skbuff[i] = NULL;
}
}
udelay(60);
writew(0x0002, ioaddr + RxCmd);
writeb(0x01, ioaddr + ChipReset);
hmp->tx_full = 0;
hmp->cur_rx = hmp->cur_tx = 0;
hmp->dirty_rx = hmp->dirty_tx = 0;
for (i = 0; i < RX_RING_SIZE; i++){
struct sk_buff *skb = hmp->rx_skbuff[i];
if (skb){
pci_unmap_single(hmp->pci_dev,
leXX_to_cpu(hmp->rx_ring[i].addr),
hmp->rx_buf_sz, PCI_DMA_FROMDEVICE);
dev_kfree_skb(skb);
hmp->rx_skbuff[i] = NULL;
}
}
for (i = 0; i < RX_RING_SIZE; i++) {
struct sk_buff *skb;
skb = netdev_alloc_skb_ip_align(dev, hmp->rx_buf_sz);
hmp->rx_skbuff[i] = skb;
if (skb == NULL)
break;
hmp->rx_ring[i].addr = cpu_to_leXX(pci_map_single(hmp->pci_dev,
skb->data, hmp->rx_buf_sz, PCI_DMA_FROMDEVICE));
hmp->rx_ring[i].status_n_length = cpu_to_le32(DescOwn |
DescEndPacket | DescIntr | (hmp->rx_buf_sz - 2));
}
hmp->dirty_rx = (unsigned int)(i - RX_RING_SIZE);
hmp->rx_ring[RX_RING_SIZE-1].status_n_length |= cpu_to_le32(DescEndRing);
dev->trans_start = jiffies;
dev->stats.tx_errors++;
writew(0x0002, ioaddr + TxCmd);
writew(0x0001, ioaddr + TxCmd);
writew(0x0001, ioaddr + RxCmd);
netif_wake_queue(dev);
}
static void hamachi_init_ring(struct net_device *dev)
{
struct hamachi_private *hmp = netdev_priv(dev);
int i;
hmp->tx_full = 0;
hmp->cur_rx = hmp->cur_tx = 0;
hmp->dirty_rx = hmp->dirty_tx = 0;
hmp->rx_buf_sz = (dev->mtu <= 1492 ? PKT_BUF_SZ :
(((dev->mtu+26+7) & ~7) + 16));
for (i = 0; i < RX_RING_SIZE; i++) {
hmp->rx_ring[i].status_n_length = 0;
hmp->rx_skbuff[i] = NULL;
}
for (i = 0; i < RX_RING_SIZE; i++) {
struct sk_buff *skb = netdev_alloc_skb(dev, hmp->rx_buf_sz + 2);
hmp->rx_skbuff[i] = skb;
if (skb == NULL)
break;
skb_reserve(skb, 2);
hmp->rx_ring[i].addr = cpu_to_leXX(pci_map_single(hmp->pci_dev,
skb->data, hmp->rx_buf_sz, PCI_DMA_FROMDEVICE));
hmp->rx_ring[i].status_n_length = cpu_to_le32(DescOwn |
DescEndPacket | DescIntr | (hmp->rx_buf_sz -2));
}
hmp->dirty_rx = (unsigned int)(i - RX_RING_SIZE);
hmp->rx_ring[RX_RING_SIZE-1].status_n_length |= cpu_to_le32(DescEndRing);
for (i = 0; i < TX_RING_SIZE; i++) {
hmp->tx_skbuff[i] = NULL;
hmp->tx_ring[i].status_n_length = 0;
}
hmp->tx_ring[TX_RING_SIZE-1].status_n_length |= cpu_to_le32(DescEndRing);
}
static netdev_tx_t hamachi_start_xmit(struct sk_buff *skb,
struct net_device *dev)
{
struct hamachi_private *hmp = netdev_priv(dev);
unsigned entry;
u16 status;
if (hmp->tx_full) {
printk(KERN_WARNING "%s: Hamachi transmit queue full at slot %d.\n",dev->name, hmp->cur_tx);
status=readw(hmp->base + TxStatus);
if( !(status & 0x0001) || (status & 0x0002))
writew(0x0001, hmp->base + TxCmd);
return NETDEV_TX_BUSY;
}
entry = hmp->cur_tx % TX_RING_SIZE;
hmp->tx_skbuff[entry] = skb;
hmp->tx_ring[entry].addr = cpu_to_leXX(pci_map_single(hmp->pci_dev,
skb->data, skb->len, PCI_DMA_TODEVICE));
if (entry >= TX_RING_SIZE-1)
hmp->tx_ring[entry].status_n_length = cpu_to_le32(DescOwn |
DescEndPacket | DescEndRing | DescIntr | skb->len);
else
hmp->tx_ring[entry].status_n_length = cpu_to_le32(DescOwn |
DescEndPacket | DescIntr | skb->len);
hmp->cur_tx++;
status=readw(hmp->base + TxStatus);
if( !(status & 0x0001) || (status & 0x0002))
writew(0x0001, hmp->base + TxCmd);
hamachi_tx(dev);
if ((hmp->cur_tx - hmp->dirty_tx) < (TX_RING_SIZE - 4))
netif_wake_queue(dev);
else {
hmp->tx_full = 1;
netif_stop_queue(dev);
}
if (hamachi_debug > 4) {
printk(KERN_DEBUG "%s: Hamachi transmit frame #%d queued in slot %d.\n",
dev->name, hmp->cur_tx, entry);
}
return NETDEV_TX_OK;
}
static irqreturn_t hamachi_interrupt(int irq, void *dev_instance)
{
struct net_device *dev = dev_instance;
struct hamachi_private *hmp = netdev_priv(dev);
void __iomem *ioaddr = hmp->base;
long boguscnt = max_interrupt_work;
int handled = 0;
#ifndef final_version
if (dev == NULL) {
printk (KERN_ERR "hamachi_interrupt(): irq %d for unknown device.\n", irq);
return IRQ_NONE;
}
#endif
spin_lock(&hmp->lock);
do {
u32 intr_status = readl(ioaddr + InterruptClear);
if (hamachi_debug > 4)
printk(KERN_DEBUG "%s: Hamachi interrupt, status %4.4x.\n",
dev->name, intr_status);
if (intr_status == 0)
break;
handled = 1;
if (intr_status & IntrRxDone)
hamachi_rx(dev);
if (intr_status & IntrTxDone){
if (hmp->tx_full){
for (; hmp->cur_tx - hmp->dirty_tx > 0; hmp->dirty_tx++){
int entry = hmp->dirty_tx % TX_RING_SIZE;
struct sk_buff *skb;
if (hmp->tx_ring[entry].status_n_length & cpu_to_le32(DescOwn))
break;
skb = hmp->tx_skbuff[entry];
if (skb){
pci_unmap_single(hmp->pci_dev,
leXX_to_cpu(hmp->tx_ring[entry].addr),
skb->len,
PCI_DMA_TODEVICE);
dev_kfree_skb_irq(skb);
hmp->tx_skbuff[entry] = NULL;
}
hmp->tx_ring[entry].status_n_length = 0;
if (entry >= TX_RING_SIZE-1)
hmp->tx_ring[TX_RING_SIZE-1].status_n_length |=
cpu_to_le32(DescEndRing);
dev->stats.tx_packets++;
}
if (hmp->cur_tx - hmp->dirty_tx < TX_RING_SIZE - 4){
hmp->tx_full = 0;
netif_wake_queue(dev);
}
} else {
netif_wake_queue(dev);
}
}
if (intr_status &
(IntrTxPCIFault | IntrTxPCIErr | IntrRxPCIFault | IntrRxPCIErr |
LinkChange | NegotiationChange | StatsMax))
hamachi_error(dev, intr_status);
if (--boguscnt < 0) {
printk(KERN_WARNING "%s: Too much work at interrupt, status=0x%4.4x.\n",
dev->name, intr_status);
break;
}
} while (1);
if (hamachi_debug > 3)
printk(KERN_DEBUG "%s: exiting interrupt, status=%#4.4x.\n",
dev->name, readl(ioaddr + IntrStatus));
#ifndef final_version
{
static int stopit = 10;
if (dev->start == 0 && --stopit < 0) {
printk(KERN_ERR "%s: Emergency stop, looping startup interrupt.\n",
dev->name);
free_irq(irq, dev);
}
}
#endif
spin_unlock(&hmp->lock);
return IRQ_RETVAL(handled);
}
static int hamachi_rx(struct net_device *dev)
{
struct hamachi_private *hmp = netdev_priv(dev);
int entry = hmp->cur_rx % RX_RING_SIZE;
int boguscnt = (hmp->dirty_rx + RX_RING_SIZE) - hmp->cur_rx;
if (hamachi_debug > 4) {
printk(KERN_DEBUG " In hamachi_rx(), entry %d status %4.4x.\n",
entry, hmp->rx_ring[entry].status_n_length);
}
while (1) {
struct hamachi_desc *desc = &(hmp->rx_ring[entry]);
u32 desc_status = le32_to_cpu(desc->status_n_length);
u16 data_size = desc_status;
u8 *buf_addr;
s32 frame_status;
if (desc_status & DescOwn)
break;
pci_dma_sync_single_for_cpu(hmp->pci_dev,
leXX_to_cpu(desc->addr),
hmp->rx_buf_sz,
PCI_DMA_FROMDEVICE);
buf_addr = (u8 *) hmp->rx_skbuff[entry]->data;
frame_status = get_unaligned_le32(&(buf_addr[data_size - 12]));
if (hamachi_debug > 4)
printk(KERN_DEBUG " hamachi_rx() status was %8.8x.\n",
frame_status);
if (--boguscnt < 0)
break;
if ( ! (desc_status & DescEndPacket)) {
printk(KERN_WARNING "%s: Oversized Ethernet frame spanned "
"multiple buffers, entry %#x length %d status %4.4x!\n",
dev->name, hmp->cur_rx, data_size, desc_status);
printk(KERN_WARNING "%s: Oversized Ethernet frame %p vs %p.\n",
dev->name, desc, &hmp->rx_ring[hmp->cur_rx % RX_RING_SIZE]);
printk(KERN_WARNING "%s: Oversized Ethernet frame -- next status %x/%x last status %x.\n",
dev->name,
le32_to_cpu(hmp->rx_ring[(hmp->cur_rx+1) % RX_RING_SIZE].status_n_length) & 0xffff0000,
le32_to_cpu(hmp->rx_ring[(hmp->cur_rx+1) % RX_RING_SIZE].status_n_length) & 0x0000ffff,
le32_to_cpu(hmp->rx_ring[(hmp->cur_rx-1) % RX_RING_SIZE].status_n_length));
dev->stats.rx_length_errors++;
}
if (frame_status & 0x00380000) {
if (hamachi_debug > 2)
printk(KERN_DEBUG " hamachi_rx() Rx error was %8.8x.\n",
frame_status);
dev->stats.rx_errors++;
if (frame_status & 0x00600000)
dev->stats.rx_length_errors++;
if (frame_status & 0x00080000)
dev->stats.rx_frame_errors++;
if (frame_status & 0x00100000)
dev->stats.rx_crc_errors++;
if (frame_status < 0)
dev->stats.rx_dropped++;
} else {
struct sk_buff *skb;
u16 pkt_len = (frame_status & 0x07ff) - 4;
#ifdef RX_CHECKSUM
u32 pfck = *(u32 *) &buf_addr[data_size - 8];
#endif
#ifndef final_version
if (hamachi_debug > 4)
printk(KERN_DEBUG " hamachi_rx() normal Rx pkt length %d"
" of %d, bogus_cnt %d.\n",
pkt_len, data_size, boguscnt);
if (hamachi_debug > 5)
printk(KERN_DEBUG"%s: rx status %8.8x %8.8x %8.8x %8.8x %8.8x.\n",
dev->name,
*(s32*)&(buf_addr[data_size - 20]),
*(s32*)&(buf_addr[data_size - 16]),
*(s32*)&(buf_addr[data_size - 12]),
*(s32*)&(buf_addr[data_size - 8]),
*(s32*)&(buf_addr[data_size - 4]));
#endif
if (pkt_len < rx_copybreak &&
(skb = netdev_alloc_skb(dev, pkt_len + 2)) != NULL) {
#ifdef RX_CHECKSUM
printk(KERN_ERR "%s: rx_copybreak non-zero "
"not good with RX_CHECKSUM\n", dev->name);
#endif
skb_reserve(skb, 2);
pci_dma_sync_single_for_cpu(hmp->pci_dev,
leXX_to_cpu(hmp->rx_ring[entry].addr),
hmp->rx_buf_sz,
PCI_DMA_FROMDEVICE);
#if 1 || USE_IP_COPYSUM
skb_copy_to_linear_data(skb,
hmp->rx_skbuff[entry]->data, pkt_len);
skb_put(skb, pkt_len);
#else
memcpy(skb_put(skb, pkt_len), hmp->rx_ring_dma
+ entry*sizeof(*desc), pkt_len);
#endif
pci_dma_sync_single_for_device(hmp->pci_dev,
leXX_to_cpu(hmp->rx_ring[entry].addr),
hmp->rx_buf_sz,
PCI_DMA_FROMDEVICE);
} else {
pci_unmap_single(hmp->pci_dev,
leXX_to_cpu(hmp->rx_ring[entry].addr),
hmp->rx_buf_sz, PCI_DMA_FROMDEVICE);
skb_put(skb = hmp->rx_skbuff[entry], pkt_len);
hmp->rx_skbuff[entry] = NULL;
}
skb->protocol = eth_type_trans(skb, dev);
#ifdef RX_CHECKSUM
if (pfck>>24 == 0x91 || pfck>>24 == 0x51) {
struct iphdr *ih = (struct iphdr *) skb->data;
if (ntohs(ih->tot_len) >= 46){
if (!(ih->frag_off & cpu_to_be16(IP_MF|IP_OFFSET))) {
u32 inv = *(u32 *) &buf_addr[data_size - 16];
u32 *p = (u32 *) &buf_addr[data_size - 20];
register u32 crc, p_r, p_r1;
if (inv & 4) {
inv &= ~4;
--p;
}
p_r = *p;
p_r1 = *(p-1);
switch (inv) {
case 0:
crc = (p_r & 0xffff) + (p_r >> 16);
break;
case 1:
crc = (p_r >> 16) + (p_r & 0xffff)
+ (p_r1 >> 16 & 0xff00);
break;
case 2:
crc = p_r + (p_r1 >> 16);
break;
case 3:
crc = p_r + (p_r1 & 0xff00) + (p_r1 >> 16);
break;
default: crc = 0;
}
if (crc & 0xffff0000) {
crc &= 0xffff;
++crc;
}
skb->csum = ntohs(pfck & 0xffff);
if (skb->csum > crc)
skb->csum -= crc;
else
skb->csum += (~crc & 0xffff);
skb->ip_summed = CHECKSUM_COMPLETE;
}
}
}
#endif
netif_rx(skb);
dev->stats.rx_packets++;
}
entry = (++hmp->cur_rx) % RX_RING_SIZE;
}
for (; hmp->cur_rx - hmp->dirty_rx > 0; hmp->dirty_rx++) {
struct hamachi_desc *desc;
entry = hmp->dirty_rx % RX_RING_SIZE;
desc = &(hmp->rx_ring[entry]);
if (hmp->rx_skbuff[entry] == NULL) {
struct sk_buff *skb = netdev_alloc_skb(dev, hmp->rx_buf_sz + 2);
hmp->rx_skbuff[entry] = skb;
if (skb == NULL)
break;
skb_reserve(skb, 2);
desc->addr = cpu_to_leXX(pci_map_single(hmp->pci_dev,
skb->data, hmp->rx_buf_sz, PCI_DMA_FROMDEVICE));
}
desc->status_n_length = cpu_to_le32(hmp->rx_buf_sz);
if (entry >= RX_RING_SIZE-1)
desc->status_n_length |= cpu_to_le32(DescOwn |
DescEndPacket | DescEndRing | DescIntr);
else
desc->status_n_length |= cpu_to_le32(DescOwn |
DescEndPacket | DescIntr);
}
if (readw(hmp->base + RxStatus) & 0x0002)
writew(0x0001, hmp->base + RxCmd);
return 0;
}
static void hamachi_error(struct net_device *dev, int intr_status)
{
struct hamachi_private *hmp = netdev_priv(dev);
void __iomem *ioaddr = hmp->base;
if (intr_status & (LinkChange|NegotiationChange)) {
if (hamachi_debug > 1)
printk(KERN_INFO "%s: Link changed: AutoNegotiation Ctrl"
" %4.4x, Status %4.4x %4.4x Intr status %4.4x.\n",
dev->name, readw(ioaddr + 0x0E0), readw(ioaddr + 0x0E2),
readw(ioaddr + ANLinkPartnerAbility),
readl(ioaddr + IntrStatus));
if (readw(ioaddr + ANStatus) & 0x20)
writeb(0x01, ioaddr + LEDCtrl);
else
writeb(0x03, ioaddr + LEDCtrl);
}
if (intr_status & StatsMax) {
hamachi_get_stats(dev);
readl(ioaddr + 0x370);
readl(ioaddr + 0x3F0);
}
if ((intr_status & ~(LinkChange|StatsMax|NegotiationChange|IntrRxDone|IntrTxDone)) &&
hamachi_debug)
printk(KERN_ERR "%s: Something Wicked happened! %4.4x.\n",
dev->name, intr_status);
if (intr_status & (IntrTxPCIErr | IntrTxPCIFault))
dev->stats.tx_fifo_errors++;
if (intr_status & (IntrRxPCIErr | IntrRxPCIFault))
dev->stats.rx_fifo_errors++;
}
static int hamachi_close(struct net_device *dev)
{
struct hamachi_private *hmp = netdev_priv(dev);
void __iomem *ioaddr = hmp->base;
struct sk_buff *skb;
int i;
netif_stop_queue(dev);
if (hamachi_debug > 1) {
printk(KERN_DEBUG "%s: Shutting down ethercard, status was Tx %4.4x Rx %4.4x Int %2.2x.\n",
dev->name, readw(ioaddr + TxStatus),
readw(ioaddr + RxStatus), readl(ioaddr + IntrStatus));
printk(KERN_DEBUG "%s: Queue pointers were Tx %d / %d, Rx %d / %d.\n",
dev->name, hmp->cur_tx, hmp->dirty_tx, hmp->cur_rx, hmp->dirty_rx);
}
writel(0x0000, ioaddr + InterruptEnable);
writel(2, ioaddr + RxCmd);
writew(2, ioaddr + TxCmd);
#ifdef __i386__
if (hamachi_debug > 2) {
printk(KERN_DEBUG " Tx ring at %8.8x:\n",
(int)hmp->tx_ring_dma);
for (i = 0; i < TX_RING_SIZE; i++)
printk(KERN_DEBUG " %c #%d desc. %8.8x %8.8x.\n",
readl(ioaddr + TxCurPtr) == (long)&hmp->tx_ring[i] ? '>' : ' ',
i, hmp->tx_ring[i].status_n_length, hmp->tx_ring[i].addr);
printk(KERN_DEBUG " Rx ring %8.8x:\n",
(int)hmp->rx_ring_dma);
for (i = 0; i < RX_RING_SIZE; i++) {
printk(KERN_DEBUG " %c #%d desc. %4.4x %8.8x\n",
readl(ioaddr + RxCurPtr) == (long)&hmp->rx_ring[i] ? '>' : ' ',
i, hmp->rx_ring[i].status_n_length, hmp->rx_ring[i].addr);
if (hamachi_debug > 6) {
if (*(u8*)hmp->rx_skbuff[i]->data != 0x69) {
u16 *addr = (u16 *)
hmp->rx_skbuff[i]->data;
int j;
printk(KERN_DEBUG "Addr: ");
for (j = 0; j < 0x50; j++)
printk(" %4.4x", addr[j]);
printk("\n");
}
}
}
}
#endif
free_irq(hmp->pci_dev->irq, dev);
del_timer_sync(&hmp->timer);
for (i = 0; i < RX_RING_SIZE; i++) {
skb = hmp->rx_skbuff[i];
hmp->rx_ring[i].status_n_length = 0;
if (skb) {
pci_unmap_single(hmp->pci_dev,
leXX_to_cpu(hmp->rx_ring[i].addr),
hmp->rx_buf_sz, PCI_DMA_FROMDEVICE);
dev_kfree_skb(skb);
hmp->rx_skbuff[i] = NULL;
}
hmp->rx_ring[i].addr = cpu_to_leXX(0xBADF00D0);
}
for (i = 0; i < TX_RING_SIZE; i++) {
skb = hmp->tx_skbuff[i];
if (skb) {
pci_unmap_single(hmp->pci_dev,
leXX_to_cpu(hmp->tx_ring[i].addr),
skb->len, PCI_DMA_TODEVICE);
dev_kfree_skb(skb);
hmp->tx_skbuff[i] = NULL;
}
}
writeb(0x00, ioaddr + LEDCtrl);
return 0;
}
static struct net_device_stats *hamachi_get_stats(struct net_device *dev)
{
struct hamachi_private *hmp = netdev_priv(dev);
void __iomem *ioaddr = hmp->base;
dev->stats.rx_bytes = readl(ioaddr + 0x330);
dev->stats.tx_bytes = readl(ioaddr + 0x3B0);
dev->stats.multicast = readl(ioaddr + 0x320);
dev->stats.rx_length_errors = readl(ioaddr + 0x368);
dev->stats.rx_over_errors = readl(ioaddr + 0x35C);
dev->stats.rx_crc_errors = readl(ioaddr + 0x360);
dev->stats.rx_frame_errors = readl(ioaddr + 0x364);
dev->stats.rx_missed_errors = readl(ioaddr + 0x36C);
return &dev->stats;
}
static void set_rx_mode(struct net_device *dev)
{
struct hamachi_private *hmp = netdev_priv(dev);
void __iomem *ioaddr = hmp->base;
if (dev->flags & IFF_PROMISC) {
writew(0x000F, ioaddr + AddrMode);
} else if ((netdev_mc_count(dev) > 63) || (dev->flags & IFF_ALLMULTI)) {
writew(0x000B, ioaddr + AddrMode);
} else if (!netdev_mc_empty(dev)) {
struct netdev_hw_addr *ha;
int i = 0;
netdev_for_each_mc_addr(ha, dev) {
writel(*(u32 *)(ha->addr), ioaddr + 0x100 + i*8);
writel(0x20000 | (*(u16 *)&ha->addr[4]),
ioaddr + 0x104 + i*8);
i++;
}
for (; i < 64; i++)
writel(0, ioaddr + 0x104 + i*8);
writew(0x0003, ioaddr + AddrMode);
} else {
writew(0x0001, ioaddr + AddrMode);
}
}
static int check_if_running(struct net_device *dev)
{
if (!netif_running(dev))
return -EINVAL;
return 0;
}
static void hamachi_get_drvinfo(struct net_device *dev, struct ethtool_drvinfo *info)
{
struct hamachi_private *np = netdev_priv(dev);
strlcpy(info->driver, DRV_NAME, sizeof(info->driver));
strlcpy(info->version, DRV_VERSION, sizeof(info->version));
strlcpy(info->bus_info, pci_name(np->pci_dev), sizeof(info->bus_info));
}
static int hamachi_get_settings(struct net_device *dev, struct ethtool_cmd *ecmd)
{
struct hamachi_private *np = netdev_priv(dev);
spin_lock_irq(&np->lock);
mii_ethtool_gset(&np->mii_if, ecmd);
spin_unlock_irq(&np->lock);
return 0;
}
static int hamachi_set_settings(struct net_device *dev, struct ethtool_cmd *ecmd)
{
struct hamachi_private *np = netdev_priv(dev);
int res;
spin_lock_irq(&np->lock);
res = mii_ethtool_sset(&np->mii_if, ecmd);
spin_unlock_irq(&np->lock);
return res;
}
static int hamachi_nway_reset(struct net_device *dev)
{
struct hamachi_private *np = netdev_priv(dev);
return mii_nway_restart(&np->mii_if);
}
static u32 hamachi_get_link(struct net_device *dev)
{
struct hamachi_private *np = netdev_priv(dev);
return mii_link_ok(&np->mii_if);
}
static int netdev_ioctl(struct net_device *dev, struct ifreq *rq, int cmd)
{
struct hamachi_private *np = netdev_priv(dev);
struct mii_ioctl_data *data = if_mii(rq);
int rc;
if (!netif_running(dev))
return -EINVAL;
if (cmd == (SIOCDEVPRIVATE+3)) {
u32 *d = (u32 *)&rq->ifr_ifru;
if (!capable(CAP_NET_ADMIN))
return -EPERM;
writel(d[0], np->base + TxIntrCtrl);
writel(d[1], np->base + RxIntrCtrl);
printk(KERN_NOTICE "%s: tx %08x, rx %08x intr\n", dev->name,
(u32) readl(np->base + TxIntrCtrl),
(u32) readl(np->base + RxIntrCtrl));
rc = 0;
}
else {
spin_lock_irq(&np->lock);
rc = generic_mii_ioctl(&np->mii_if, data, cmd, NULL);
spin_unlock_irq(&np->lock);
}
return rc;
}
static void hamachi_remove_one(struct pci_dev *pdev)
{
struct net_device *dev = pci_get_drvdata(pdev);
if (dev) {
struct hamachi_private *hmp = netdev_priv(dev);
pci_free_consistent(pdev, RX_TOTAL_SIZE, hmp->rx_ring,
hmp->rx_ring_dma);
pci_free_consistent(pdev, TX_TOTAL_SIZE, hmp->tx_ring,
hmp->tx_ring_dma);
unregister_netdev(dev);
iounmap(hmp->base);
free_netdev(dev);
pci_release_regions(pdev);
}
}
static int __init hamachi_init (void)
{
#ifdef MODULE
printk(version);
#endif
return pci_register_driver(&hamachi_driver);
}
static void __exit hamachi_exit (void)
{
pci_unregister_driver(&hamachi_driver);
}
