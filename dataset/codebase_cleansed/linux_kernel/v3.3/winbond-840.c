static int __devinit w840_probe1 (struct pci_dev *pdev,
const struct pci_device_id *ent)
{
struct net_device *dev;
struct netdev_private *np;
static int find_cnt;
int chip_idx = ent->driver_data;
int irq;
int i, option = find_cnt < MAX_UNITS ? options[find_cnt] : 0;
void __iomem *ioaddr;
i = pci_enable_device(pdev);
if (i) return i;
pci_set_master(pdev);
irq = pdev->irq;
if (pci_set_dma_mask(pdev, DMA_BIT_MASK(32))) {
pr_warn("Device %s disabled due to DMA limitations\n",
pci_name(pdev));
return -EIO;
}
dev = alloc_etherdev(sizeof(*np));
if (!dev)
return -ENOMEM;
SET_NETDEV_DEV(dev, &pdev->dev);
if (pci_request_regions(pdev, DRV_NAME))
goto err_out_netdev;
ioaddr = pci_iomap(pdev, TULIP_BAR, netdev_res_size);
if (!ioaddr)
goto err_out_free_res;
for (i = 0; i < 3; i++)
((__le16 *)dev->dev_addr)[i] = cpu_to_le16(eeprom_read(ioaddr, i));
iowrite32(0x00000001, ioaddr + PCIBusCfg);
dev->base_addr = (unsigned long)ioaddr;
dev->irq = irq;
np = netdev_priv(dev);
np->pci_dev = pdev;
np->chip_id = chip_idx;
np->drv_flags = pci_id_tbl[chip_idx].drv_flags;
spin_lock_init(&np->lock);
np->mii_if.dev = dev;
np->mii_if.mdio_read = mdio_read;
np->mii_if.mdio_write = mdio_write;
np->base_addr = ioaddr;
pci_set_drvdata(pdev, dev);
if (dev->mem_start)
option = dev->mem_start;
if (option > 0) {
if (option & 0x200)
np->mii_if.full_duplex = 1;
if (option & 15)
dev_info(&dev->dev,
"ignoring user supplied media type %d",
option & 15);
}
if (find_cnt < MAX_UNITS && full_duplex[find_cnt] > 0)
np->mii_if.full_duplex = 1;
if (np->mii_if.full_duplex)
np->mii_if.force_media = 1;
dev->netdev_ops = &netdev_ops;
dev->ethtool_ops = &netdev_ethtool_ops;
dev->watchdog_timeo = TX_TIMEOUT;
i = register_netdev(dev);
if (i)
goto err_out_cleardev;
dev_info(&dev->dev, "%s at %p, %pM, IRQ %d\n",
pci_id_tbl[chip_idx].name, ioaddr, dev->dev_addr, irq);
if (np->drv_flags & CanHaveMII) {
int phy, phy_idx = 0;
for (phy = 1; phy < 32 && phy_idx < MII_CNT; phy++) {
int mii_status = mdio_read(dev, phy, MII_BMSR);
if (mii_status != 0xffff && mii_status != 0x0000) {
np->phys[phy_idx++] = phy;
np->mii_if.advertising = mdio_read(dev, phy, MII_ADVERTISE);
np->mii = (mdio_read(dev, phy, MII_PHYSID1) << 16)+
mdio_read(dev, phy, MII_PHYSID2);
dev_info(&dev->dev,
"MII PHY %08xh found at address %d, status 0x%04x advertising %04x\n",
np->mii, phy, mii_status,
np->mii_if.advertising);
}
}
np->mii_cnt = phy_idx;
np->mii_if.phy_id = np->phys[0];
if (phy_idx == 0) {
dev_warn(&dev->dev,
"MII PHY not found -- this device may not operate correctly\n");
}
}
find_cnt++;
return 0;
err_out_cleardev:
pci_set_drvdata(pdev, NULL);
pci_iounmap(pdev, ioaddr);
err_out_free_res:
pci_release_regions(pdev);
err_out_netdev:
free_netdev (dev);
return -ENODEV;
}
static int eeprom_read(void __iomem *addr, int location)
{
int i;
int retval = 0;
void __iomem *ee_addr = addr + EECtrl;
int read_cmd = location | EE_ReadCmd;
iowrite32(EE_ChipSelect, ee_addr);
for (i = 10; i >= 0; i--) {
short dataval = (read_cmd & (1 << i)) ? EE_Write1 : EE_Write0;
iowrite32(dataval, ee_addr);
eeprom_delay(ee_addr);
iowrite32(dataval | EE_ShiftClk, ee_addr);
eeprom_delay(ee_addr);
}
iowrite32(EE_ChipSelect, ee_addr);
eeprom_delay(ee_addr);
for (i = 16; i > 0; i--) {
iowrite32(EE_ChipSelect | EE_ShiftClk, ee_addr);
eeprom_delay(ee_addr);
retval = (retval << 1) | ((ioread32(ee_addr) & EE_DataIn) ? 1 : 0);
iowrite32(EE_ChipSelect, ee_addr);
eeprom_delay(ee_addr);
}
iowrite32(0, ee_addr);
return retval;
}
static void mdio_sync(void __iomem *mdio_addr)
{
int bits = 32;
while (--bits >= 0) {
iowrite32(MDIO_WRITE1, mdio_addr);
mdio_delay(mdio_addr);
iowrite32(MDIO_WRITE1 | MDIO_ShiftClk, mdio_addr);
mdio_delay(mdio_addr);
}
}
static int mdio_read(struct net_device *dev, int phy_id, int location)
{
struct netdev_private *np = netdev_priv(dev);
void __iomem *mdio_addr = np->base_addr + MIICtrl;
int mii_cmd = (0xf6 << 10) | (phy_id << 5) | location;
int i, retval = 0;
if (mii_preamble_required)
mdio_sync(mdio_addr);
for (i = 15; i >= 0; i--) {
int dataval = (mii_cmd & (1 << i)) ? MDIO_WRITE1 : MDIO_WRITE0;
iowrite32(dataval, mdio_addr);
mdio_delay(mdio_addr);
iowrite32(dataval | MDIO_ShiftClk, mdio_addr);
mdio_delay(mdio_addr);
}
for (i = 20; i > 0; i--) {
iowrite32(MDIO_EnbIn, mdio_addr);
mdio_delay(mdio_addr);
retval = (retval << 1) | ((ioread32(mdio_addr) & MDIO_DataIn) ? 1 : 0);
iowrite32(MDIO_EnbIn | MDIO_ShiftClk, mdio_addr);
mdio_delay(mdio_addr);
}
return (retval>>1) & 0xffff;
}
static void mdio_write(struct net_device *dev, int phy_id, int location, int value)
{
struct netdev_private *np = netdev_priv(dev);
void __iomem *mdio_addr = np->base_addr + MIICtrl;
int mii_cmd = (0x5002 << 16) | (phy_id << 23) | (location<<18) | value;
int i;
if (location == 4 && phy_id == np->phys[0])
np->mii_if.advertising = value;
if (mii_preamble_required)
mdio_sync(mdio_addr);
for (i = 31; i >= 0; i--) {
int dataval = (mii_cmd & (1 << i)) ? MDIO_WRITE1 : MDIO_WRITE0;
iowrite32(dataval, mdio_addr);
mdio_delay(mdio_addr);
iowrite32(dataval | MDIO_ShiftClk, mdio_addr);
mdio_delay(mdio_addr);
}
for (i = 2; i > 0; i--) {
iowrite32(MDIO_EnbIn, mdio_addr);
mdio_delay(mdio_addr);
iowrite32(MDIO_EnbIn | MDIO_ShiftClk, mdio_addr);
mdio_delay(mdio_addr);
}
}
static int netdev_open(struct net_device *dev)
{
struct netdev_private *np = netdev_priv(dev);
void __iomem *ioaddr = np->base_addr;
int i;
iowrite32(0x00000001, ioaddr + PCIBusCfg);
netif_device_detach(dev);
i = request_irq(dev->irq, intr_handler, IRQF_SHARED, dev->name, dev);
if (i)
goto out_err;
if (debug > 1)
netdev_dbg(dev, "w89c840_open() irq %d\n", dev->irq);
if((i=alloc_ringdesc(dev)))
goto out_err;
spin_lock_irq(&np->lock);
netif_device_attach(dev);
init_registers(dev);
spin_unlock_irq(&np->lock);
netif_start_queue(dev);
if (debug > 2)
netdev_dbg(dev, "Done netdev_open()\n");
init_timer(&np->timer);
np->timer.expires = jiffies + 1*HZ;
np->timer.data = (unsigned long)dev;
np->timer.function = netdev_timer;
add_timer(&np->timer);
return 0;
out_err:
netif_device_attach(dev);
return i;
}
static int update_link(struct net_device *dev)
{
struct netdev_private *np = netdev_priv(dev);
int duplex, fasteth, result, mii_reg;
mii_reg = mdio_read(dev, np->phys[0], MII_BMSR);
if (mii_reg == 0xffff)
return np->csr6;
mii_reg = mdio_read(dev, np->phys[0], MII_BMSR);
if (!(mii_reg & 0x4)) {
if (netif_carrier_ok(dev)) {
if (debug)
dev_info(&dev->dev,
"MII #%d reports no link. Disabling watchdog\n",
np->phys[0]);
netif_carrier_off(dev);
}
return np->csr6;
}
if (!netif_carrier_ok(dev)) {
if (debug)
dev_info(&dev->dev,
"MII #%d link is back. Enabling watchdog\n",
np->phys[0]);
netif_carrier_on(dev);
}
if ((np->mii & ~0xf) == MII_DAVICOM_DM9101) {
mii_reg = mdio_read(dev, np->phys[0], MII_BMCR);
duplex = mii_reg & BMCR_FULLDPLX;
fasteth = mii_reg & BMCR_SPEED100;
} else {
int negotiated;
mii_reg = mdio_read(dev, np->phys[0], MII_LPA);
negotiated = mii_reg & np->mii_if.advertising;
duplex = (negotiated & LPA_100FULL) || ((negotiated & 0x02C0) == LPA_10FULL);
fasteth = negotiated & 0x380;
}
duplex |= np->mii_if.force_media;
result = np->csr6 & ~0x20000200;
if (duplex)
result |= 0x200;
if (fasteth)
result |= 0x20000000;
if (result != np->csr6 && debug)
dev_info(&dev->dev,
"Setting %dMBit-%s-duplex based on MII#%d\n",
fasteth ? 100 : 10, duplex ? "full" : "half",
np->phys[0]);
return result;
}
static inline void update_csr6(struct net_device *dev, int new)
{
struct netdev_private *np = netdev_priv(dev);
void __iomem *ioaddr = np->base_addr;
int limit = RXTX_TIMEOUT;
if (!netif_device_present(dev))
new = 0;
if (new==np->csr6)
return;
iowrite32(np->csr6 & ~0x2002, ioaddr + NetworkConfig);
for (;;) {
int csr5 = ioread32(ioaddr + IntrStatus);
int t;
t = (csr5 >> 17) & 0x07;
if (t==0||t==1) {
t = (csr5 >> 20) & 0x07;
if (t==0||t==1)
break;
}
limit--;
if(!limit) {
dev_info(&dev->dev,
"couldn't stop rxtx, IntrStatus %xh\n", csr5);
break;
}
udelay(1);
}
np->csr6 = new;
iowrite32(np->csr6, ioaddr + NetworkConfig);
if (new & 0x200)
np->mii_if.full_duplex = 1;
}
static void netdev_timer(unsigned long data)
{
struct net_device *dev = (struct net_device *)data;
struct netdev_private *np = netdev_priv(dev);
void __iomem *ioaddr = np->base_addr;
if (debug > 2)
netdev_dbg(dev, "Media selection timer tick, status %08x config %08x\n",
ioread32(ioaddr + IntrStatus),
ioread32(ioaddr + NetworkConfig));
spin_lock_irq(&np->lock);
update_csr6(dev, update_link(dev));
spin_unlock_irq(&np->lock);
np->timer.expires = jiffies + 10*HZ;
add_timer(&np->timer);
}
static void init_rxtx_rings(struct net_device *dev)
{
struct netdev_private *np = netdev_priv(dev);
int i;
np->rx_head_desc = &np->rx_ring[0];
np->tx_ring = (struct w840_tx_desc*)&np->rx_ring[RX_RING_SIZE];
for (i = 0; i < RX_RING_SIZE; i++) {
np->rx_ring[i].length = np->rx_buf_sz;
np->rx_ring[i].status = 0;
np->rx_skbuff[i] = NULL;
}
np->rx_ring[i-1].length |= DescEndRing;
for (i = 0; i < RX_RING_SIZE; i++) {
struct sk_buff *skb = dev_alloc_skb(np->rx_buf_sz);
np->rx_skbuff[i] = skb;
if (skb == NULL)
break;
np->rx_addr[i] = pci_map_single(np->pci_dev,skb->data,
np->rx_buf_sz,PCI_DMA_FROMDEVICE);
np->rx_ring[i].buffer1 = np->rx_addr[i];
np->rx_ring[i].status = DescOwned;
}
np->cur_rx = 0;
np->dirty_rx = (unsigned int)(i - RX_RING_SIZE);
for (i = 0; i < TX_RING_SIZE; i++) {
np->tx_skbuff[i] = NULL;
np->tx_ring[i].status = 0;
}
np->tx_full = 0;
np->tx_q_bytes = np->dirty_tx = np->cur_tx = 0;
iowrite32(np->ring_dma_addr, np->base_addr + RxRingPtr);
iowrite32(np->ring_dma_addr+sizeof(struct w840_rx_desc)*RX_RING_SIZE,
np->base_addr + TxRingPtr);
}
static void free_rxtx_rings(struct netdev_private* np)
{
int i;
for (i = 0; i < RX_RING_SIZE; i++) {
np->rx_ring[i].status = 0;
if (np->rx_skbuff[i]) {
pci_unmap_single(np->pci_dev,
np->rx_addr[i],
np->rx_skbuff[i]->len,
PCI_DMA_FROMDEVICE);
dev_kfree_skb(np->rx_skbuff[i]);
}
np->rx_skbuff[i] = NULL;
}
for (i = 0; i < TX_RING_SIZE; i++) {
if (np->tx_skbuff[i]) {
pci_unmap_single(np->pci_dev,
np->tx_addr[i],
np->tx_skbuff[i]->len,
PCI_DMA_TODEVICE);
dev_kfree_skb(np->tx_skbuff[i]);
}
np->tx_skbuff[i] = NULL;
}
}
static void init_registers(struct net_device *dev)
{
struct netdev_private *np = netdev_priv(dev);
void __iomem *ioaddr = np->base_addr;
int i;
for (i = 0; i < 6; i++)
iowrite8(dev->dev_addr[i], ioaddr + StationAddr + i);
#ifdef __BIG_ENDIAN
i = (1<<20);
#else
i = 0;
#endif
i |= (0x04<<2);
i |= 0x02;
#if defined (__i386__) && !defined(MODULE)
if (boot_cpu_data.x86 <= 4) {
i |= 0x4800;
dev_info(&dev->dev,
"This is a 386/486 PCI system, setting cache alignment to 8 longwords\n");
} else {
i |= 0xE000;
}
#elif defined(__powerpc__) || defined(__i386__) || defined(__alpha__) || defined(__ia64__) || defined(__x86_64__)
i |= 0xE000;
#elif defined(CONFIG_SPARC) || defined (CONFIG_PARISC)
i |= 0x4800;
#else
#warning Processor architecture undefined
i |= 0x4800;
#endif
iowrite32(i, ioaddr + PCIBusCfg);
np->csr6 = 0;
update_csr6(dev, 0x00022002 | update_link(dev) | __set_rx_mode(dev));
iowrite32(0x1A0F5, ioaddr + IntrStatus);
iowrite32(0x1A0F5, ioaddr + IntrEnable);
iowrite32(0, ioaddr + RxStartDemand);
}
static void tx_timeout(struct net_device *dev)
{
struct netdev_private *np = netdev_priv(dev);
void __iomem *ioaddr = np->base_addr;
dev_warn(&dev->dev, "Transmit timed out, status %08x, resetting...\n",
ioread32(ioaddr + IntrStatus));
{
int i;
printk(KERN_DEBUG " Rx ring %p: ", np->rx_ring);
for (i = 0; i < RX_RING_SIZE; i++)
printk(KERN_CONT " %08x", (unsigned int)np->rx_ring[i].status);
printk(KERN_CONT "\n");
printk(KERN_DEBUG " Tx ring %p: ", np->tx_ring);
for (i = 0; i < TX_RING_SIZE; i++)
printk(KERN_CONT " %08x", np->tx_ring[i].status);
printk(KERN_CONT "\n");
}
printk(KERN_DEBUG "Tx cur %d Tx dirty %d Tx Full %d, q bytes %d\n",
np->cur_tx, np->dirty_tx, np->tx_full, np->tx_q_bytes);
printk(KERN_DEBUG "Tx Descriptor addr %xh\n", ioread32(ioaddr+0x4C));
disable_irq(dev->irq);
spin_lock_irq(&np->lock);
iowrite32(1, np->base_addr+PCIBusCfg);
udelay(1);
free_rxtx_rings(np);
init_rxtx_rings(dev);
init_registers(dev);
spin_unlock_irq(&np->lock);
enable_irq(dev->irq);
netif_wake_queue(dev);
dev->trans_start = jiffies;
np->stats.tx_errors++;
}
static int alloc_ringdesc(struct net_device *dev)
{
struct netdev_private *np = netdev_priv(dev);
np->rx_buf_sz = (dev->mtu <= 1500 ? PKT_BUF_SZ : dev->mtu + 32);
np->rx_ring = pci_alloc_consistent(np->pci_dev,
sizeof(struct w840_rx_desc)*RX_RING_SIZE +
sizeof(struct w840_tx_desc)*TX_RING_SIZE,
&np->ring_dma_addr);
if(!np->rx_ring)
return -ENOMEM;
init_rxtx_rings(dev);
return 0;
}
static void free_ringdesc(struct netdev_private *np)
{
pci_free_consistent(np->pci_dev,
sizeof(struct w840_rx_desc)*RX_RING_SIZE +
sizeof(struct w840_tx_desc)*TX_RING_SIZE,
np->rx_ring, np->ring_dma_addr);
}
static netdev_tx_t start_tx(struct sk_buff *skb, struct net_device *dev)
{
struct netdev_private *np = netdev_priv(dev);
unsigned entry;
entry = np->cur_tx % TX_RING_SIZE;
np->tx_addr[entry] = pci_map_single(np->pci_dev,
skb->data,skb->len, PCI_DMA_TODEVICE);
np->tx_skbuff[entry] = skb;
np->tx_ring[entry].buffer1 = np->tx_addr[entry];
if (skb->len < TX_BUFLIMIT) {
np->tx_ring[entry].length = DescWholePkt | skb->len;
} else {
int len = skb->len - TX_BUFLIMIT;
np->tx_ring[entry].buffer2 = np->tx_addr[entry]+TX_BUFLIMIT;
np->tx_ring[entry].length = DescWholePkt | (len << 11) | TX_BUFLIMIT;
}
if(entry == TX_RING_SIZE-1)
np->tx_ring[entry].length |= DescEndRing;
spin_lock_irq(&np->lock);
np->cur_tx++;
wmb();
np->tx_ring[entry].status = DescOwned;
wmb();
iowrite32(0, np->base_addr + TxStartDemand);
np->tx_q_bytes += skb->len;
if (np->cur_tx - np->dirty_tx > TX_QUEUE_LEN ||
((np->drv_flags & HasBrokenTx) && np->tx_q_bytes > TX_BUG_FIFO_LIMIT)) {
netif_stop_queue(dev);
wmb();
np->tx_full = 1;
}
spin_unlock_irq(&np->lock);
if (debug > 4) {
netdev_dbg(dev, "Transmit frame #%d queued in slot %d\n",
np->cur_tx, entry);
}
return NETDEV_TX_OK;
}
static void netdev_tx_done(struct net_device *dev)
{
struct netdev_private *np = netdev_priv(dev);
for (; np->cur_tx - np->dirty_tx > 0; np->dirty_tx++) {
int entry = np->dirty_tx % TX_RING_SIZE;
int tx_status = np->tx_ring[entry].status;
if (tx_status < 0)
break;
if (tx_status & 0x8000) {
#ifndef final_version
if (debug > 1)
netdev_dbg(dev, "Transmit error, Tx status %08x\n",
tx_status);
#endif
np->stats.tx_errors++;
if (tx_status & 0x0104) np->stats.tx_aborted_errors++;
if (tx_status & 0x0C80) np->stats.tx_carrier_errors++;
if (tx_status & 0x0200) np->stats.tx_window_errors++;
if (tx_status & 0x0002) np->stats.tx_fifo_errors++;
if ((tx_status & 0x0080) && np->mii_if.full_duplex == 0)
np->stats.tx_heartbeat_errors++;
} else {
#ifndef final_version
if (debug > 3)
netdev_dbg(dev, "Transmit slot %d ok, Tx status %08x\n",
entry, tx_status);
#endif
np->stats.tx_bytes += np->tx_skbuff[entry]->len;
np->stats.collisions += (tx_status >> 3) & 15;
np->stats.tx_packets++;
}
pci_unmap_single(np->pci_dev,np->tx_addr[entry],
np->tx_skbuff[entry]->len,
PCI_DMA_TODEVICE);
np->tx_q_bytes -= np->tx_skbuff[entry]->len;
dev_kfree_skb_irq(np->tx_skbuff[entry]);
np->tx_skbuff[entry] = NULL;
}
if (np->tx_full &&
np->cur_tx - np->dirty_tx < TX_QUEUE_LEN_RESTART &&
np->tx_q_bytes < TX_BUG_FIFO_LIMIT) {
np->tx_full = 0;
wmb();
netif_wake_queue(dev);
}
}
static irqreturn_t intr_handler(int irq, void *dev_instance)
{
struct net_device *dev = (struct net_device *)dev_instance;
struct netdev_private *np = netdev_priv(dev);
void __iomem *ioaddr = np->base_addr;
int work_limit = max_interrupt_work;
int handled = 0;
if (!netif_device_present(dev))
return IRQ_NONE;
do {
u32 intr_status = ioread32(ioaddr + IntrStatus);
iowrite32(intr_status & 0x001ffff, ioaddr + IntrStatus);
if (debug > 4)
netdev_dbg(dev, "Interrupt, status %04x\n", intr_status);
if ((intr_status & (NormalIntr|AbnormalIntr)) == 0)
break;
handled = 1;
if (intr_status & (RxIntr | RxNoBuf))
netdev_rx(dev);
if (intr_status & RxNoBuf)
iowrite32(0, ioaddr + RxStartDemand);
if (intr_status & (TxNoBuf | TxIntr) &&
np->cur_tx != np->dirty_tx) {
spin_lock(&np->lock);
netdev_tx_done(dev);
spin_unlock(&np->lock);
}
if (intr_status & (AbnormalIntr | TxFIFOUnderflow | SystemError |
TimerInt | TxDied))
netdev_error(dev, intr_status);
if (--work_limit < 0) {
dev_warn(&dev->dev,
"Too much work at interrupt, status=0x%04x\n",
intr_status);
spin_lock(&np->lock);
if (netif_device_present(dev)) {
iowrite32(AbnormalIntr | TimerInt, ioaddr + IntrEnable);
iowrite32(10, ioaddr + GPTimer);
}
spin_unlock(&np->lock);
break;
}
} while (1);
if (debug > 3)
netdev_dbg(dev, "exiting interrupt, status=%#4.4x\n",
ioread32(ioaddr + IntrStatus));
return IRQ_RETVAL(handled);
}
static int netdev_rx(struct net_device *dev)
{
struct netdev_private *np = netdev_priv(dev);
int entry = np->cur_rx % RX_RING_SIZE;
int work_limit = np->dirty_rx + RX_RING_SIZE - np->cur_rx;
if (debug > 4) {
netdev_dbg(dev, " In netdev_rx(), entry %d status %04x\n",
entry, np->rx_ring[entry].status);
}
while (--work_limit >= 0) {
struct w840_rx_desc *desc = np->rx_head_desc;
s32 status = desc->status;
if (debug > 4)
netdev_dbg(dev, " netdev_rx() status was %08x\n",
status);
if (status < 0)
break;
if ((status & 0x38008300) != 0x0300) {
if ((status & 0x38000300) != 0x0300) {
if ((status & 0xffff) != 0x7fff) {
dev_warn(&dev->dev,
"Oversized Ethernet frame spanned multiple buffers, entry %#x status %04x!\n",
np->cur_rx, status);
np->stats.rx_length_errors++;
}
} else if (status & 0x8000) {
if (debug > 2)
netdev_dbg(dev, "Receive error, Rx status %08x\n",
status);
np->stats.rx_errors++;
if (status & 0x0890) np->stats.rx_length_errors++;
if (status & 0x004C) np->stats.rx_frame_errors++;
if (status & 0x0002) np->stats.rx_crc_errors++;
}
} else {
struct sk_buff *skb;
int pkt_len = ((status >> 16) & 0x7ff) - 4;
#ifndef final_version
if (debug > 4)
netdev_dbg(dev, " netdev_rx() normal Rx pkt length %d status %x\n",
pkt_len, status);
#endif
if (pkt_len < rx_copybreak &&
(skb = dev_alloc_skb(pkt_len + 2)) != NULL) {
skb_reserve(skb, 2);
pci_dma_sync_single_for_cpu(np->pci_dev,np->rx_addr[entry],
np->rx_skbuff[entry]->len,
PCI_DMA_FROMDEVICE);
skb_copy_to_linear_data(skb, np->rx_skbuff[entry]->data, pkt_len);
skb_put(skb, pkt_len);
pci_dma_sync_single_for_device(np->pci_dev,np->rx_addr[entry],
np->rx_skbuff[entry]->len,
PCI_DMA_FROMDEVICE);
} else {
pci_unmap_single(np->pci_dev,np->rx_addr[entry],
np->rx_skbuff[entry]->len,
PCI_DMA_FROMDEVICE);
skb_put(skb = np->rx_skbuff[entry], pkt_len);
np->rx_skbuff[entry] = NULL;
}
#ifndef final_version
if (debug > 5)
netdev_dbg(dev, " Rx data %pM %pM %02x%02x %pI4\n",
&skb->data[0], &skb->data[6],
skb->data[12], skb->data[13],
&skb->data[14]);
#endif
skb->protocol = eth_type_trans(skb, dev);
netif_rx(skb);
np->stats.rx_packets++;
np->stats.rx_bytes += pkt_len;
}
entry = (++np->cur_rx) % RX_RING_SIZE;
np->rx_head_desc = &np->rx_ring[entry];
}
for (; np->cur_rx - np->dirty_rx > 0; np->dirty_rx++) {
struct sk_buff *skb;
entry = np->dirty_rx % RX_RING_SIZE;
if (np->rx_skbuff[entry] == NULL) {
skb = dev_alloc_skb(np->rx_buf_sz);
np->rx_skbuff[entry] = skb;
if (skb == NULL)
break;
np->rx_addr[entry] = pci_map_single(np->pci_dev,
skb->data,
np->rx_buf_sz, PCI_DMA_FROMDEVICE);
np->rx_ring[entry].buffer1 = np->rx_addr[entry];
}
wmb();
np->rx_ring[entry].status = DescOwned;
}
return 0;
}
static void netdev_error(struct net_device *dev, int intr_status)
{
struct netdev_private *np = netdev_priv(dev);
void __iomem *ioaddr = np->base_addr;
if (debug > 2)
netdev_dbg(dev, "Abnormal event, %08x\n", intr_status);
if (intr_status == 0xffffffff)
return;
spin_lock(&np->lock);
if (intr_status & TxFIFOUnderflow) {
int new;
#if 0
new = np->csr6 + 0x4000;
#else
new = (np->csr6 >> 14)&0x7f;
if (new < 64)
new *= 2;
else
new = 127;
new = (np->csr6 & ~(0x7F << 14)) | (new<<14);
#endif
netdev_dbg(dev, "Tx underflow, new csr6 %08x\n", new);
update_csr6(dev, new);
}
if (intr_status & RxDied) {
np->stats.rx_errors++;
}
if (intr_status & TimerInt) {
if (netif_device_present(dev))
iowrite32(0x1A0F5, ioaddr + IntrEnable);
}
np->stats.rx_missed_errors += ioread32(ioaddr + RxMissed) & 0xffff;
iowrite32(0, ioaddr + RxStartDemand);
spin_unlock(&np->lock);
}
static struct net_device_stats *get_stats(struct net_device *dev)
{
struct netdev_private *np = netdev_priv(dev);
void __iomem *ioaddr = np->base_addr;
spin_lock_irq(&np->lock);
if (netif_running(dev) && netif_device_present(dev))
np->stats.rx_missed_errors += ioread32(ioaddr + RxMissed) & 0xffff;
spin_unlock_irq(&np->lock);
return &np->stats;
}
static u32 __set_rx_mode(struct net_device *dev)
{
struct netdev_private *np = netdev_priv(dev);
void __iomem *ioaddr = np->base_addr;
u32 mc_filter[2];
u32 rx_mode;
if (dev->flags & IFF_PROMISC) {
memset(mc_filter, 0xff, sizeof(mc_filter));
rx_mode = RxAcceptBroadcast | AcceptMulticast | RxAcceptAllPhys
| AcceptMyPhys;
} else if ((netdev_mc_count(dev) > multicast_filter_limit) ||
(dev->flags & IFF_ALLMULTI)) {
memset(mc_filter, 0xff, sizeof(mc_filter));
rx_mode = RxAcceptBroadcast | AcceptMulticast | AcceptMyPhys;
} else {
struct netdev_hw_addr *ha;
memset(mc_filter, 0, sizeof(mc_filter));
netdev_for_each_mc_addr(ha, dev) {
int filbit;
filbit = (ether_crc(ETH_ALEN, ha->addr) >> 26) ^ 0x3F;
filbit &= 0x3f;
mc_filter[filbit >> 5] |= 1 << (filbit & 31);
}
rx_mode = RxAcceptBroadcast | AcceptMulticast | AcceptMyPhys;
}
iowrite32(mc_filter[0], ioaddr + MulticastFilter0);
iowrite32(mc_filter[1], ioaddr + MulticastFilter1);
return rx_mode;
}
static void set_rx_mode(struct net_device *dev)
{
struct netdev_private *np = netdev_priv(dev);
u32 rx_mode = __set_rx_mode(dev);
spin_lock_irq(&np->lock);
update_csr6(dev, (np->csr6 & ~0x00F8) | rx_mode);
spin_unlock_irq(&np->lock);
}
static void netdev_get_drvinfo (struct net_device *dev, struct ethtool_drvinfo *info)
{
struct netdev_private *np = netdev_priv(dev);
strlcpy(info->driver, DRV_NAME, sizeof(info->driver));
strlcpy(info->version, DRV_VERSION, sizeof(info->version));
strlcpy(info->bus_info, pci_name(np->pci_dev), sizeof(info->bus_info));
}
static int netdev_get_settings(struct net_device *dev, struct ethtool_cmd *cmd)
{
struct netdev_private *np = netdev_priv(dev);
int rc;
spin_lock_irq(&np->lock);
rc = mii_ethtool_gset(&np->mii_if, cmd);
spin_unlock_irq(&np->lock);
return rc;
}
static int netdev_set_settings(struct net_device *dev, struct ethtool_cmd *cmd)
{
struct netdev_private *np = netdev_priv(dev);
int rc;
spin_lock_irq(&np->lock);
rc = mii_ethtool_sset(&np->mii_if, cmd);
spin_unlock_irq(&np->lock);
return rc;
}
static int netdev_nway_reset(struct net_device *dev)
{
struct netdev_private *np = netdev_priv(dev);
return mii_nway_restart(&np->mii_if);
}
static u32 netdev_get_link(struct net_device *dev)
{
struct netdev_private *np = netdev_priv(dev);
return mii_link_ok(&np->mii_if);
}
static u32 netdev_get_msglevel(struct net_device *dev)
{
return debug;
}
static void netdev_set_msglevel(struct net_device *dev, u32 value)
{
debug = value;
}
static int netdev_ioctl(struct net_device *dev, struct ifreq *rq, int cmd)
{
struct mii_ioctl_data *data = if_mii(rq);
struct netdev_private *np = netdev_priv(dev);
switch(cmd) {
case SIOCGMIIPHY:
data->phy_id = ((struct netdev_private *)netdev_priv(dev))->phys[0] & 0x1f;
case SIOCGMIIREG:
spin_lock_irq(&np->lock);
data->val_out = mdio_read(dev, data->phy_id & 0x1f, data->reg_num & 0x1f);
spin_unlock_irq(&np->lock);
return 0;
case SIOCSMIIREG:
spin_lock_irq(&np->lock);
mdio_write(dev, data->phy_id & 0x1f, data->reg_num & 0x1f, data->val_in);
spin_unlock_irq(&np->lock);
return 0;
default:
return -EOPNOTSUPP;
}
}
static int netdev_close(struct net_device *dev)
{
struct netdev_private *np = netdev_priv(dev);
void __iomem *ioaddr = np->base_addr;
netif_stop_queue(dev);
if (debug > 1) {
netdev_dbg(dev, "Shutting down ethercard, status was %08x Config %08x\n",
ioread32(ioaddr + IntrStatus),
ioread32(ioaddr + NetworkConfig));
netdev_dbg(dev, "Queue pointers were Tx %d / %d, Rx %d / %d\n",
np->cur_tx, np->dirty_tx,
np->cur_rx, np->dirty_rx);
}
spin_lock_irq(&np->lock);
netif_device_detach(dev);
update_csr6(dev, 0);
iowrite32(0x0000, ioaddr + IntrEnable);
spin_unlock_irq(&np->lock);
free_irq(dev->irq, dev);
wmb();
netif_device_attach(dev);
if (ioread32(ioaddr + NetworkConfig) != 0xffffffff)
np->stats.rx_missed_errors += ioread32(ioaddr + RxMissed) & 0xffff;
#ifdef __i386__
if (debug > 2) {
int i;
printk(KERN_DEBUG" Tx ring at %p:\n", np->tx_ring);
for (i = 0; i < TX_RING_SIZE; i++)
printk(KERN_DEBUG " #%d desc. %04x %04x %08x\n",
i, np->tx_ring[i].length,
np->tx_ring[i].status, np->tx_ring[i].buffer1);
printk(KERN_DEBUG " Rx ring %p:\n", np->rx_ring);
for (i = 0; i < RX_RING_SIZE; i++) {
printk(KERN_DEBUG " #%d desc. %04x %04x %08x\n",
i, np->rx_ring[i].length,
np->rx_ring[i].status, np->rx_ring[i].buffer1);
}
}
#endif
del_timer_sync(&np->timer);
free_rxtx_rings(np);
free_ringdesc(np);
return 0;
}
static void __devexit w840_remove1 (struct pci_dev *pdev)
{
struct net_device *dev = pci_get_drvdata(pdev);
if (dev) {
struct netdev_private *np = netdev_priv(dev);
unregister_netdev(dev);
pci_release_regions(pdev);
pci_iounmap(pdev, np->base_addr);
free_netdev(dev);
}
pci_set_drvdata(pdev, NULL);
}
static int w840_suspend (struct pci_dev *pdev, pm_message_t state)
{
struct net_device *dev = pci_get_drvdata (pdev);
struct netdev_private *np = netdev_priv(dev);
void __iomem *ioaddr = np->base_addr;
rtnl_lock();
if (netif_running (dev)) {
del_timer_sync(&np->timer);
spin_lock_irq(&np->lock);
netif_device_detach(dev);
update_csr6(dev, 0);
iowrite32(0, ioaddr + IntrEnable);
spin_unlock_irq(&np->lock);
synchronize_irq(dev->irq);
netif_tx_disable(dev);
np->stats.rx_missed_errors += ioread32(ioaddr + RxMissed) & 0xffff;
BUG_ON(np->csr6 || ioread32(ioaddr + IntrEnable));
free_rxtx_rings(np);
} else {
netif_device_detach(dev);
}
rtnl_unlock();
return 0;
}
static int w840_resume (struct pci_dev *pdev)
{
struct net_device *dev = pci_get_drvdata (pdev);
struct netdev_private *np = netdev_priv(dev);
int retval = 0;
rtnl_lock();
if (netif_device_present(dev))
goto out;
if (netif_running(dev)) {
if ((retval = pci_enable_device(pdev))) {
dev_err(&dev->dev,
"pci_enable_device failed in resume\n");
goto out;
}
spin_lock_irq(&np->lock);
iowrite32(1, np->base_addr+PCIBusCfg);
ioread32(np->base_addr+PCIBusCfg);
udelay(1);
netif_device_attach(dev);
init_rxtx_rings(dev);
init_registers(dev);
spin_unlock_irq(&np->lock);
netif_wake_queue(dev);
mod_timer(&np->timer, jiffies + 1*HZ);
} else {
netif_device_attach(dev);
}
out:
rtnl_unlock();
return retval;
}
static int __init w840_init(void)
{
printk(version);
return pci_register_driver(&w840_driver);
}
static void __exit w840_exit(void)
{
pci_unregister_driver(&w840_driver);
}
