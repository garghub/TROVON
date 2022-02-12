static int __devinit netdrv_init_board(struct pci_dev *pdev,
struct net_device **dev_out,
void **ioaddr_out)
{
void *ioaddr = NULL;
struct net_device *dev;
struct netdrv_private *tp;
int rc, i;
u32 pio_start, pio_end, pio_flags, pio_len;
unsigned long mmio_start, mmio_end, mmio_flags, mmio_len;
u32 tmp;
DPRINTK("ENTER\n");
assert(pdev != NULL);
assert(ioaddr_out != NULL);
*ioaddr_out = NULL;
*dev_out = NULL;
dev = alloc_etherdev(sizeof(*tp));
if (dev == NULL) {
dev_err(&pdev->dev, "unable to alloc new ethernet\n");
DPRINTK("EXIT, returning -ENOMEM\n");
return -ENOMEM;
}
SET_NETDEV_DEV(dev, &pdev->dev);
tp = netdev_priv(dev);
rc = pci_enable_device(pdev);
if (rc)
goto err_out;
pio_start = pci_resource_start(pdev, 0);
pio_end = pci_resource_end(pdev, 0);
pio_flags = pci_resource_flags(pdev, 0);
pio_len = pci_resource_len(pdev, 0);
mmio_start = pci_resource_start(pdev, 1);
mmio_end = pci_resource_end(pdev, 1);
mmio_flags = pci_resource_flags(pdev, 1);
mmio_len = pci_resource_len(pdev, 1);
DPRINTK("PIO region size == %#02X\n", pio_len);
DPRINTK("MMIO region size == %#02lX\n", mmio_len);
if (!(pio_flags & IORESOURCE_IO)) {
dev_err(&pdev->dev, "region #0 not a PIO resource, aborting\n");
rc = -ENODEV;
goto err_out;
}
if (!(mmio_flags & IORESOURCE_MEM)) {
dev_err(&pdev->dev, "region #1 not an MMIO resource, aborting\n");
rc = -ENODEV;
goto err_out;
}
if ((pio_len < NETDRV_MIN_IO_SIZE) ||
(mmio_len < NETDRV_MIN_IO_SIZE)) {
dev_err(&pdev->dev, "Invalid PCI region size(s), aborting\n");
rc = -ENODEV;
goto err_out;
}
rc = pci_request_regions(pdev, MODNAME);
if (rc)
goto err_out;
pci_set_master(pdev);
#ifdef USE_IO_OPS
ioaddr = (void *)pio_start;
#else
ioaddr = ioremap(mmio_start, mmio_len);
if (ioaddr == NULL) {
dev_err(&pdev->dev, "cannot remap MMIO, aborting\n");
rc = -EIO;
goto err_out_free_res;
}
#endif
NETDRV_W8(ChipCmd, (NETDRV_R8(ChipCmd) & ChipCmdClear) | CmdReset);
for (i = 1000; i > 0; i--)
if ((NETDRV_R8(ChipCmd) & CmdReset) == 0)
break;
else
udelay(10);
#ifndef USE_IO_OPS
assert(inb(pio_start+Config0) == readb(ioaddr+Config0));
assert(inb(pio_start+Config1) == readb(ioaddr+Config1));
assert(inb(pio_start+TxConfig) == readb(ioaddr+TxConfig));
assert(inb(pio_start+RxConfig) == readb(ioaddr+RxConfig));
#endif
tmp = NETDRV_R8(ChipVersion);
for (i = ARRAY_SIZE(rtl_chip_info) - 1; i >= 0; i--)
if (tmp == rtl_chip_info[i].version) {
tp->chipset = i;
goto match;
}
dev_printk(KERN_DEBUG, &pdev->dev,
"unknown chip version, assuming RTL-8139\n");
dev_printk(KERN_DEBUG, &pdev->dev, "TxConfig = %#lx\n",
NETDRV_R32(TxConfig));
tp->chipset = 0;
match:
DPRINTK("chipset id(%d) == index %d, '%s'\n",
tmp, tp->chipset, rtl_chip_info[tp->chipset].name);
rc = register_netdev(dev);
if (rc)
goto err_out_unmap;
DPRINTK("EXIT, returning 0\n");
*ioaddr_out = ioaddr;
*dev_out = dev;
return 0;
err_out_unmap:
#ifndef USE_IO_OPS
iounmap(ioaddr);
err_out_free_res:
#endif
pci_release_regions(pdev);
err_out:
free_netdev(dev);
DPRINTK("EXIT, returning %d\n", rc);
return rc;
}
static int __devinit netdrv_init_one(struct pci_dev *pdev,
const struct pci_device_id *ent)
{
struct net_device *dev = NULL;
struct netdrv_private *tp;
int i, addr_len, option;
void *ioaddr = NULL;
static int board_idx = -1;
#ifndef MODULE
static int printed_version;
if (!printed_version++)
printk(version);
#endif
DPRINTK("ENTER\n");
assert(pdev != NULL);
assert(ent != NULL);
board_idx++;
i = netdrv_init_board(pdev, &dev, &ioaddr);
if (i < 0) {
DPRINTK("EXIT, returning %d\n", i);
return i;
}
tp = netdev_priv(dev);
assert(ioaddr != NULL);
assert(dev != NULL);
assert(tp != NULL);
addr_len = read_eeprom(ioaddr, 0, 8) == 0x8129 ? 8 : 6;
for (i = 0; i < 3; i++)
((u16 *)(dev->dev_addr))[i] =
le16_to_cpu(read_eeprom(ioaddr, i + 7, addr_len));
dev->netdev_ops = &netdrv_netdev_ops;
dev->watchdog_timeo = TX_TIMEOUT;
dev->irq = pdev->irq;
dev->base_addr = (unsigned long) ioaddr;
tp = netdev_priv(dev);
tp->drv_flags = PCI_COMMAND_IO | PCI_COMMAND_MEMORY |
PCI_COMMAND_MASTER | NETDRV_CAPS;
tp->pci_dev = pdev;
tp->board = ent->driver_data;
tp->mmio_addr = ioaddr;
spin_lock_init(&tp->lock);
pci_set_drvdata(pdev, dev);
tp->phys[0] = 32;
netdev_info(dev, "%s at %#lx, %pM IRQ %d\n",
board_info[ent->driver_data].name,
dev->base_addr, dev->dev_addr, dev->irq);
netdev_printk(KERN_DEBUG, dev, "Identified 8139 chip type '%s'\n",
rtl_chip_info[tp->chipset].name);
NETDRV_W8_F(Cfg9346, Cfg9346_Unlock);
option = (board_idx > 7) ? 0 : media[board_idx];
if (option > 0) {
tp->full_duplex = (option & 0x200) ? 1 : 0;
tp->default_port = option & 15;
if (tp->default_port)
tp->medialock = 1;
}
if (tp->full_duplex) {
netdev_info(dev, "Media type forced to Full Duplex\n");
mdio_write(dev, tp->phys[0], MII_ADVERTISE, ADVERTISE_FULL);
tp->duplex_lock = 1;
}
DPRINTK("EXIT - returning 0\n");
return 0;
}
static void __devexit netdrv_remove_one(struct pci_dev *pdev)
{
struct net_device *dev = pci_get_drvdata(pdev);
struct netdrv_private *np;
DPRINTK("ENTER\n");
assert(dev != NULL);
np = netdev_priv(dev);
assert(np != NULL);
unregister_netdev(dev);
#ifndef USE_IO_OPS
iounmap(np->mmio_addr);
#endif
pci_release_regions(pdev);
free_netdev(dev);
pci_set_drvdata(pdev, NULL);
pci_disable_device(pdev);
DPRINTK("EXIT\n");
}
static int __devinit read_eeprom(void *ioaddr, int location, int addr_len)
{
int i;
unsigned retval = 0;
void *ee_addr = ioaddr + Cfg9346;
int read_cmd = location | (EE_READ_CMD << addr_len);
DPRINTK("ENTER\n");
writeb(EE_ENB & ~EE_CS, ee_addr);
writeb(EE_ENB, ee_addr);
eeprom_delay();
for (i = 4 + addr_len; i >= 0; i--) {
int dataval = (read_cmd & (1 << i)) ? EE_DATA_WRITE : 0;
writeb(EE_ENB | dataval, ee_addr);
eeprom_delay();
writeb(EE_ENB | dataval | EE_SHIFT_CLK, ee_addr);
eeprom_delay();
}
writeb(EE_ENB, ee_addr);
eeprom_delay();
for (i = 16; i > 0; i--) {
writeb(EE_ENB | EE_SHIFT_CLK, ee_addr);
eeprom_delay();
retval =
(retval << 1) | ((readb(ee_addr) & EE_DATA_READ) ? 1 :
0);
writeb(EE_ENB, ee_addr);
eeprom_delay();
}
writeb(~EE_CS, ee_addr);
eeprom_delay();
DPRINTK("EXIT - returning %d\n", retval);
return retval;
}
static void mdio_sync(void *mdio_addr)
{
int i;
DPRINTK("ENTER\n");
for (i = 32; i >= 0; i--) {
writeb(MDIO_WRITE1, mdio_addr);
mdio_delay();
writeb(MDIO_WRITE1 | MDIO_CLK, mdio_addr);
mdio_delay();
}
DPRINTK("EXIT\n");
}
static int mdio_read(struct net_device *dev, int phy_id, int location)
{
struct netdrv_private *tp = netdev_priv(dev);
void *mdio_addr = tp->mmio_addr + Config4;
int mii_cmd = (0xf6 << 10) | (phy_id << 5) | location;
int retval = 0;
int i;
DPRINTK("ENTER\n");
if (phy_id > 31) {
DPRINTK("EXIT after directly using 8139 internal regs\n");
return location < 8 && mii_2_8139_map[location] ?
readw(tp->mmio_addr + mii_2_8139_map[location]) : 0;
}
mdio_sync(mdio_addr);
for (i = 15; i >= 0; i--) {
int dataval = (mii_cmd & (1 << i)) ? MDIO_DATA_OUT : 0;
writeb(MDIO_DIR | dataval, mdio_addr);
mdio_delay();
writeb(MDIO_DIR | dataval | MDIO_CLK, mdio_addr);
mdio_delay();
}
for (i = 19; i > 0; i--) {
writeb(0, mdio_addr);
mdio_delay();
retval = ((retval << 1) | ((readb(mdio_addr) & MDIO_DATA_IN))
? 1 : 0);
writeb(MDIO_CLK, mdio_addr);
mdio_delay();
}
DPRINTK("EXIT, returning %d\n", (retval >> 1) & 0xffff);
return (retval >> 1) & 0xffff;
}
static void mdio_write(struct net_device *dev, int phy_id, int location,
int value)
{
struct netdrv_private *tp = netdev_priv(dev);
void *mdio_addr = tp->mmio_addr + Config4;
int mii_cmd =
(0x5002 << 16) | (phy_id << 23) | (location << 18) | value;
int i;
DPRINTK("ENTER\n");
if (phy_id > 31) {
if (location < 8 && mii_2_8139_map[location]) {
writew(value,
tp->mmio_addr + mii_2_8139_map[location]);
readw(tp->mmio_addr + mii_2_8139_map[location]);
}
DPRINTK("EXIT after directly using 8139 internal regs\n");
return;
}
mdio_sync(mdio_addr);
for (i = 31; i >= 0; i--) {
int dataval =
(mii_cmd & (1 << i)) ? MDIO_WRITE1 : MDIO_WRITE0;
writeb(dataval, mdio_addr);
mdio_delay();
writeb(dataval | MDIO_CLK, mdio_addr);
mdio_delay();
}
for (i = 2; i > 0; i--) {
writeb(0, mdio_addr);
mdio_delay();
writeb(MDIO_CLK, mdio_addr);
mdio_delay();
}
DPRINTK("EXIT\n");
}
static int netdrv_open(struct net_device *dev)
{
struct netdrv_private *tp = netdev_priv(dev);
int retval;
void *ioaddr = tp->mmio_addr;
DPRINTK("ENTER\n");
retval = request_irq(dev->irq, netdrv_interrupt, IRQF_SHARED, dev->name, dev);
if (retval) {
DPRINTK("EXIT, returning %d\n", retval);
return retval;
}
tp->tx_bufs = pci_alloc_consistent(tp->pci_dev, TX_BUF_TOT_LEN,
&tp->tx_bufs_dma);
tp->rx_ring = pci_alloc_consistent(tp->pci_dev, RX_BUF_TOT_LEN,
&tp->rx_ring_dma);
if (tp->tx_bufs == NULL || tp->rx_ring == NULL) {
free_irq(dev->irq, dev);
if (tp->tx_bufs)
pci_free_consistent(tp->pci_dev, TX_BUF_TOT_LEN,
tp->tx_bufs, tp->tx_bufs_dma);
if (tp->rx_ring)
pci_free_consistent(tp->pci_dev, RX_BUF_TOT_LEN,
tp->rx_ring, tp->rx_ring_dma);
DPRINTK("EXIT, returning -ENOMEM\n");
return -ENOMEM;
}
tp->full_duplex = tp->duplex_lock;
tp->tx_flag = (TX_FIFO_THRESH << 11) & 0x003f0000;
netdrv_init_ring(dev);
netdrv_hw_start(dev);
netdev_dbg(dev, "ioaddr %#llx IRQ %d GP Pins %02x %s-duplex\n",
(unsigned long long)pci_resource_start(tp->pci_dev, 1),
dev->irq, NETDRV_R8(MediaStatus),
tp->full_duplex ? "full" : "half");
init_timer(&tp->timer);
tp->timer.expires = jiffies + 3 * HZ;
tp->timer.data = (unsigned long) dev;
tp->timer.function = netdrv_timer;
add_timer(&tp->timer);
DPRINTK("EXIT, returning 0\n");
return 0;
}
static void netdrv_hw_start(struct net_device *dev)
{
struct netdrv_private *tp = netdev_priv(dev);
void *ioaddr = tp->mmio_addr;
u32 i;
DPRINTK("ENTER\n");
NETDRV_W8(ChipCmd, (NETDRV_R8(ChipCmd) & ChipCmdClear) | CmdReset);
udelay(100);
for (i = 1000; i > 0; i--)
if ((NETDRV_R8(ChipCmd) & CmdReset) == 0)
break;
NETDRV_W32_F(MAC0 + 0, cpu_to_le32(*(u32 *)(dev->dev_addr + 0)));
NETDRV_W32_F(MAC0 + 4, cpu_to_le32(*(u32 *)(dev->dev_addr + 4)));
NETDRV_W8_F(ChipCmd, (NETDRV_R8(ChipCmd) & ChipCmdClear) |
CmdRxEnb | CmdTxEnb);
i = netdrv_rx_config |
(NETDRV_R32(RxConfig) & rtl_chip_info[tp->chipset].RxConfigMask);
NETDRV_W32_F(RxConfig, i);
NETDRV_W32(TxConfig, (TX_DMA_BURST << TxDMAShift));
NETDRV_W8_F(Cfg9346, Cfg9346_Unlock);
udelay(10);
tp->cur_rx = 0;
NETDRV_W8_F(Cfg9346, Cfg9346_Lock);
udelay(10);
NETDRV_W32_F(RxBuf, tp->rx_ring_dma);
for (i = 0; i < NUM_TX_DESC; i++)
NETDRV_W32_F(TxAddr0 + (i * 4), tp->tx_bufs_dma + (tp->tx_buf[i] - tp->tx_bufs));
NETDRV_W32_F(RxMissed, 0);
netdrv_set_rx_mode(dev);
NETDRV_W16(MultiIntr, NETDRV_R16(MultiIntr) & MultiIntrClear);
NETDRV_W8_F(ChipCmd, (NETDRV_R8(ChipCmd) & ChipCmdClear) |
CmdRxEnb | CmdTxEnb);
NETDRV_W16_F(IntrMask, netdrv_intr_mask);
netif_start_queue(dev);
DPRINTK("EXIT\n");
}
static void netdrv_init_ring(struct net_device *dev)
{
struct netdrv_private *tp = netdev_priv(dev);
int i;
DPRINTK("ENTER\n");
tp->cur_rx = 0;
atomic_set(&tp->cur_tx, 0);
atomic_set(&tp->dirty_tx, 0);
for (i = 0; i < NUM_TX_DESC; i++) {
tp->tx_info[i].skb = NULL;
tp->tx_info[i].mapping = 0;
tp->tx_buf[i] = &tp->tx_bufs[i * TX_BUF_SIZE];
}
DPRINTK("EXIT\n");
}
static void netdrv_timer(unsigned long data)
{
struct net_device *dev = (struct net_device *) data;
struct netdrv_private *tp = netdev_priv(dev);
void *ioaddr = tp->mmio_addr;
int next_tick = 60 * HZ;
int mii_lpa;
mii_lpa = mdio_read(dev, tp->phys[0], MII_LPA);
if (!tp->duplex_lock && mii_lpa != 0xffff) {
int duplex = ((mii_lpa & LPA_100FULL) ||
(mii_lpa & 0x01C0) == 0x0040);
if (tp->full_duplex != duplex) {
tp->full_duplex = duplex;
netdev_info(dev, "Setting %s-duplex based on MII #%d link partner ability of %04x\n",
tp->full_duplex ? "full" : "half",
tp->phys[0], mii_lpa);
NETDRV_W8(Cfg9346, Cfg9346_Unlock);
NETDRV_W8(Config1, tp->full_duplex ? 0x60 : 0x20);
NETDRV_W8(Cfg9346, Cfg9346_Lock);
}
}
netdev_dbg(dev, "Media selection tick, Link partner %04x\n",
NETDRV_R16(NWayLPAR));
netdev_dbg(dev, "Other registers are IntMask %04x IntStatus %04x RxStatus %04lx\n",
NETDRV_R16(IntrMask),
NETDRV_R16(IntrStatus),
NETDRV_R32(RxEarlyStatus));
netdev_dbg(dev, "Chip config %02x %02x\n",
NETDRV_R8(Config0), NETDRV_R8(Config1));
tp->timer.expires = jiffies + next_tick;
add_timer(&tp->timer);
}
static void netdrv_tx_clear(struct net_device *dev)
{
int i;
struct netdrv_private *tp = netdev_priv(dev);
atomic_set(&tp->cur_tx, 0);
atomic_set(&tp->dirty_tx, 0);
for (i = 0; i < NUM_TX_DESC; i++) {
struct ring_info *rp = &tp->tx_info[i];
if (rp->mapping != 0) {
pci_unmap_single(tp->pci_dev, rp->mapping,
rp->skb->len, PCI_DMA_TODEVICE);
rp->mapping = 0;
}
if (rp->skb) {
dev_kfree_skb(rp->skb);
rp->skb = NULL;
dev->stats.tx_dropped++;
}
}
}
static void netdrv_tx_timeout(struct net_device *dev)
{
struct netdrv_private *tp = netdev_priv(dev);
void *ioaddr = tp->mmio_addr;
int i;
u8 tmp8;
unsigned long flags;
netdev_dbg(dev, "Transmit timeout, status %02x %04x media %02x\n",
NETDRV_R8(ChipCmd),
NETDRV_R16(IntrStatus),
NETDRV_R8(MediaStatus));
tmp8 = NETDRV_R8(ChipCmd);
if (tmp8 & CmdTxEnb)
NETDRV_W8(ChipCmd, tmp8 & ~CmdTxEnb);
NETDRV_W16(IntrMask, 0x0000);
netdev_dbg(dev, "Tx queue start entry %d dirty entry %d\n",
atomic_read(&tp->cur_tx),
atomic_read(&tp->dirty_tx));
for (i = 0; i < NUM_TX_DESC; i++)
netdev_dbg(dev, "Tx descriptor %d is %08lx%s\n",
i, NETDRV_R32(TxStatus0 + (i * 4)),
i == atomic_read(&tp->dirty_tx) % NUM_TX_DESC ?
"(queue head)" : "");
spin_lock_irqsave(&tp->lock, flags);
netdrv_tx_clear(dev);
spin_unlock_irqrestore(&tp->lock, flags);
netdrv_hw_start(dev);
netif_wake_queue(dev);
}
static int netdrv_start_xmit(struct sk_buff *skb, struct net_device *dev)
{
struct netdrv_private *tp = netdev_priv(dev);
void *ioaddr = tp->mmio_addr;
int entry;
entry = atomic_read(&tp->cur_tx) % NUM_TX_DESC;
assert(tp->tx_info[entry].skb == NULL);
assert(tp->tx_info[entry].mapping == 0);
tp->tx_info[entry].skb = skb;
skb_copy_from_linear_data(skb, tp->tx_buf[entry], skb->len);
NETDRV_W32(TxStatus0 + (entry * sizeof(u32)),
tp->tx_flag | (skb->len >= ETH_ZLEN ? skb->len : ETH_ZLEN));
atomic_inc(&tp->cur_tx);
if ((atomic_read(&tp->cur_tx) - atomic_read(&tp->dirty_tx)) >= NUM_TX_DESC)
netif_stop_queue(dev);
netdev_dbg(dev, "Queued Tx packet at %p size %u to slot %d\n",
skb->data, skb->len, entry);
return NETDEV_TX_OK;
}
static void netdrv_tx_interrupt(struct net_device *dev,
struct netdrv_private *tp,
void *ioaddr)
{
int cur_tx, dirty_tx, tx_left;
assert(dev != NULL);
assert(tp != NULL);
assert(ioaddr != NULL);
dirty_tx = atomic_read(&tp->dirty_tx);
cur_tx = atomic_read(&tp->cur_tx);
tx_left = cur_tx - dirty_tx;
while (tx_left > 0) {
int entry = dirty_tx % NUM_TX_DESC;
int txstatus;
txstatus = NETDRV_R32(TxStatus0 + (entry * sizeof(u32)));
if (!(txstatus & (TxStatOK | TxUnderrun | TxAborted)))
break;
if (txstatus & (TxOutOfWindow | TxAborted)) {
netdev_dbg(dev, "Transmit error, Tx status %#08x\n",
txstatus);
dev->stats.tx_errors++;
if (txstatus & TxAborted) {
dev->stats.tx_aborted_errors++;
NETDRV_W32(TxConfig, TxClearAbt | (TX_DMA_BURST << TxDMAShift));
}
if (txstatus & TxCarrierLost)
dev->stats.tx_carrier_errors++;
if (txstatus & TxOutOfWindow)
dev->stats.tx_window_errors++;
} else {
if (txstatus & TxUnderrun) {
if (tp->tx_flag < 0x00300000)
tp->tx_flag += 0x00020000;
dev->stats.tx_fifo_errors++;
}
dev->stats.collisions += (txstatus >> 24) & 15;
dev->stats.tx_bytes += txstatus & 0x7ff;
dev->stats.tx_packets++;
}
if (tp->tx_info[entry].mapping != 0) {
pci_unmap_single(tp->pci_dev,
tp->tx_info[entry].mapping,
tp->tx_info[entry].skb->len,
PCI_DMA_TODEVICE);
tp->tx_info[entry].mapping = 0;
}
dev_kfree_skb_irq(tp->tx_info[entry].skb);
tp->tx_info[entry].skb = NULL;
dirty_tx++;
if (dirty_tx < 0) {
atomic_sub(cur_tx, &tp->cur_tx);
dirty_tx = cur_tx - tx_left + 1;
}
if (netif_queue_stopped(dev))
netif_wake_queue(dev);
cur_tx = atomic_read(&tp->cur_tx);
tx_left = cur_tx - dirty_tx;
}
#ifndef NETDRV_NDEBUG
if (atomic_read(&tp->cur_tx) - dirty_tx > NUM_TX_DESC) {
netdev_err(dev, "Out-of-sync dirty pointer, %d vs. %d\n",
dirty_tx, atomic_read(&tp->cur_tx));
dirty_tx += NUM_TX_DESC;
}
#endif
atomic_set(&tp->dirty_tx, dirty_tx);
}
static void netdrv_rx_err(u32 rx_status, struct net_device *dev,
struct netdrv_private *tp, void *ioaddr)
{
u8 tmp8;
int tmp_work = 1000;
netdev_dbg(dev, "Ethernet frame had errors, status %08x\n", rx_status);
if (rx_status & RxTooLong)
netdev_dbg(dev, "Oversized Ethernet frame, status %04x!\n",
rx_status);
dev->stats.rx_errors++;
if (rx_status & (RxBadSymbol | RxBadAlign))
dev->stats.rx_frame_errors++;
if (rx_status & (RxRunt | RxTooLong))
dev->stats.rx_length_errors++;
if (rx_status & RxCRCErr)
dev->stats.rx_crc_errors++;
tp->cur_rx = 0;
tmp8 = NETDRV_R8(ChipCmd) & ChipCmdClear;
NETDRV_W8_F(ChipCmd, tmp8 | CmdTxEnb);
netdrv_set_rx_mode(dev);
while (--tmp_work > 0) {
tmp8 = NETDRV_R8(ChipCmd);
if ((tmp8 & CmdRxEnb) && (tmp8 & CmdTxEnb))
break;
NETDRV_W8_F(ChipCmd,
(tmp8 & ChipCmdClear) | CmdRxEnb | CmdTxEnb);
}
netdrv_set_rx_mode(dev);
if (tmp_work <= 0)
netdev_warn(dev, "tx/rx enable wait too long\n");
}
static void netdrv_rx_interrupt(struct net_device *dev,
struct netdrv_private *tp, void *ioaddr)
{
unsigned char *rx_ring;
u16 cur_rx;
assert(dev != NULL);
assert(tp != NULL);
assert(ioaddr != NULL);
rx_ring = tp->rx_ring;
cur_rx = tp->cur_rx;
netdev_dbg(dev, "In netdrv_rx(), current %04x BufAddr %04x, free to %04x, Cmd %02x\n",
cur_rx, NETDRV_R16(RxBufAddr),
NETDRV_R16(RxBufPtr), NETDRV_R8(ChipCmd));
while ((NETDRV_R8(ChipCmd) & RxBufEmpty) == 0) {
int ring_offset = cur_rx % RX_BUF_LEN;
u32 rx_status;
unsigned int rx_size;
unsigned int pkt_size;
struct sk_buff *skb;
rx_status = le32_to_cpu(*(u32 *)(rx_ring + ring_offset));
rx_size = rx_status >> 16;
pkt_size = rx_size - 4;
netdev_dbg(dev, "netdrv_rx() status %04x, size %04x, cur %04x\n",
rx_status, rx_size, cur_rx);
#if defined(NETDRV_DEBUG) && (NETDRV_DEBUG > 2)
print_hex_dump_bytes("Frame contents: ", HEX_DUMP_OFFSET,
&rx_ring[ring_offset], 70);
#endif
if ((rx_size > (MAX_ETH_FRAME_SIZE+4)) ||
(!(rx_status & RxStatusOK))) {
netdrv_rx_err(rx_status, dev, tp, ioaddr);
return;
}
skb = dev_alloc_skb(pkt_size + 2);
if (skb) {
skb_reserve(skb, 2);
skb_copy_to_linear_data(skb, &rx_ring[ring_offset + 4], pkt_size);
skb_put(skb, pkt_size);
skb->protocol = eth_type_trans(skb, dev);
netif_rx(skb);
dev->stats.rx_bytes += pkt_size;
dev->stats.rx_packets++;
} else {
netdev_warn(dev, "Memory squeeze, dropping packet\n");
dev->stats.rx_dropped++;
}
cur_rx = (cur_rx + rx_size + 4 + 3) & ~3;
NETDRV_W16_F(RxBufPtr, cur_rx - 16);
}
netdev_dbg(dev, "Done netdrv_rx(), current %04x BufAddr %04x, free to %04x, Cmd %02x\n",
cur_rx, NETDRV_R16(RxBufAddr),
NETDRV_R16(RxBufPtr), NETDRV_R8(ChipCmd));
tp->cur_rx = cur_rx;
}
static void netdrv_weird_interrupt(struct net_device *dev,
struct netdrv_private *tp,
void *ioaddr,
int status, int link_changed)
{
netdev_printk(KERN_DEBUG, dev, "Abnormal interrupt, status %08x\n",
status);
assert(dev != NULL);
assert(tp != NULL);
assert(ioaddr != NULL);
dev->stats.rx_missed_errors += NETDRV_R32(RxMissed);
NETDRV_W32(RxMissed, 0);
if ((status & RxUnderrun) && link_changed &&
(tp->drv_flags & HAS_LNK_CHNG)) {
int lpar = NETDRV_R16(NWayLPAR);
int duplex = ((lpar & 0x0100) || (lpar & 0x01C0) == 0x0040 ||
tp->duplex_lock);
if (tp->full_duplex != duplex) {
tp->full_duplex = duplex;
NETDRV_W8(Cfg9346, Cfg9346_Unlock);
NETDRV_W8(Config1, tp->full_duplex ? 0x60 : 0x20);
NETDRV_W8(Cfg9346, Cfg9346_Lock);
}
status &= ~RxUnderrun;
}
if (status & (RxUnderrun | RxOverflow | RxErr | RxFIFOOver))
dev->stats.rx_errors++;
if (status & (PCSTimeout))
dev->stats.rx_length_errors++;
if (status & (RxUnderrun | RxFIFOOver))
dev->stats.rx_fifo_errors++;
if (status & RxOverflow) {
dev->stats.rx_over_errors++;
tp->cur_rx = NETDRV_R16(RxBufAddr) % RX_BUF_LEN;
NETDRV_W16_F(RxBufPtr, tp->cur_rx - 16);
}
if (status & PCIErr) {
u16 pci_cmd_status;
pci_read_config_word(tp->pci_dev, PCI_STATUS, &pci_cmd_status);
netdev_err(dev, "PCI Bus error %04x\n", pci_cmd_status);
}
}
static irqreturn_t netdrv_interrupt(int irq, void *dev_instance)
{
struct net_device *dev = (struct net_device *) dev_instance;
struct netdrv_private *tp = netdev_priv(dev);
int boguscnt = max_interrupt_work;
void *ioaddr = tp->mmio_addr;
int status = 0, link_changed = 0;
int handled = 0;
spin_lock(&tp->lock);
do {
status = NETDRV_R16(IntrStatus);
if (status == 0xFFFF)
break;
handled = 1;
NETDRV_W16_F(IntrStatus, status);
netdev_dbg(dev, "interrupt status=%#04x new intstat=%#04x\n",
status, NETDRV_R16(IntrStatus));
if ((status &
(PCIErr | PCSTimeout | RxUnderrun | RxOverflow |
RxFIFOOver | TxErr | TxOK | RxErr | RxOK)) == 0)
break;
if (status & (PCIErr | PCSTimeout | RxUnderrun | RxOverflow |
RxFIFOOver | TxErr | RxErr))
netdrv_weird_interrupt(dev, tp, ioaddr,
status, link_changed);
if (status & (RxOK | RxUnderrun | RxOverflow | RxFIFOOver))
netdrv_rx_interrupt(dev, tp, ioaddr);
if (status & (TxOK | TxErr))
netdrv_tx_interrupt(dev, tp, ioaddr);
boguscnt--;
} while (boguscnt > 0);
if (boguscnt <= 0) {
netdev_warn(dev, "Too much work at interrupt, IntrStatus=%#04x\n",
status);
NETDRV_W16(IntrStatus, 0xffff);
}
spin_unlock(&tp->lock);
netdev_dbg(dev, "exiting interrupt, intr_status=%#04x\n",
NETDRV_R16(IntrStatus));
return IRQ_RETVAL(handled);
}
static int netdrv_close(struct net_device *dev)
{
struct netdrv_private *tp = netdev_priv(dev);
void *ioaddr = tp->mmio_addr;
unsigned long flags;
DPRINTK("ENTER\n");
netif_stop_queue(dev);
netdev_dbg(dev, "Shutting down ethercard, status was %#04x\n",
NETDRV_R16(IntrStatus));
del_timer_sync(&tp->timer);
spin_lock_irqsave(&tp->lock, flags);
NETDRV_W8(ChipCmd, (NETDRV_R8(ChipCmd) & ChipCmdClear));
NETDRV_W16(IntrMask, 0x0000);
dev->stats.rx_missed_errors += NETDRV_R32(RxMissed);
NETDRV_W32(RxMissed, 0);
spin_unlock_irqrestore(&tp->lock, flags);
free_irq(dev->irq, dev);
netdrv_tx_clear(dev);
pci_free_consistent(tp->pci_dev, RX_BUF_TOT_LEN,
tp->rx_ring, tp->rx_ring_dma);
pci_free_consistent(tp->pci_dev, TX_BUF_TOT_LEN,
tp->tx_bufs, tp->tx_bufs_dma);
tp->rx_ring = NULL;
tp->tx_bufs = NULL;
NETDRV_W8(Cfg9346, Cfg9346_Unlock);
NETDRV_W8(Config1, 0x03);
NETDRV_W8(Cfg9346, Cfg9346_Lock);
DPRINTK("EXIT\n");
return 0;
}
static int netdrv_ioctl(struct net_device *dev, struct ifreq *rq, int cmd)
{
struct netdrv_private *tp = netdev_priv(dev);
struct mii_ioctl_data *data = if_mii(rq);
unsigned long flags;
int rc = 0;
DPRINTK("ENTER\n");
switch (cmd) {
case SIOCGMIIPHY:
data->phy_id = tp->phys[0] & 0x3f;
case SIOCGMIIREG:
spin_lock_irqsave(&tp->lock, flags);
data->val_out = mdio_read(dev, data->phy_id & 0x1f, data->reg_num & 0x1f);
spin_unlock_irqrestore(&tp->lock, flags);
break;
case SIOCSMIIREG:
spin_lock_irqsave(&tp->lock, flags);
mdio_write(dev, data->phy_id & 0x1f, data->reg_num & 0x1f, data->val_in);
spin_unlock_irqrestore(&tp->lock, flags);
break;
default:
rc = -EOPNOTSUPP;
break;
}
DPRINTK("EXIT, returning %d\n", rc);
return rc;
}
static void netdrv_set_rx_mode(struct net_device *dev)
{
struct netdrv_private *tp = netdev_priv(dev);
void *ioaddr = tp->mmio_addr;
u32 mc_filter[2];
int rx_mode;
u32 tmp;
DPRINTK("ENTER\n");
netdev_dbg(dev, "%s(%04x) done -- Rx config %08lx\n",
__func__, dev->flags, NETDRV_R32(RxConfig));
if (dev->flags & IFF_PROMISC) {
rx_mode =
AcceptBroadcast | AcceptMulticast | AcceptMyPhys |
AcceptAllPhys;
mc_filter[1] = mc_filter[0] = 0xffffffff;
} else if ((netdev_mc_count(dev) > multicast_filter_limit) ||
(dev->flags & IFF_ALLMULTI)) {
rx_mode = AcceptBroadcast | AcceptMulticast | AcceptMyPhys;
mc_filter[1] = mc_filter[0] = 0xffffffff;
} else {
struct netdev_hw_addr *ha;
rx_mode = AcceptBroadcast | AcceptMulticast | AcceptMyPhys;
mc_filter[1] = mc_filter[0] = 0;
netdev_for_each_mc_addr(ha, dev) {
int bit_nr = ether_crc(ETH_ALEN, ha->addr) >> 26;
mc_filter[bit_nr >> 5] |= 1 << (bit_nr & 31);
}
}
if (!in_irq())
spin_lock_irq(&tp->lock);
tmp = netdrv_rx_config | rx_mode |
(NETDRV_R32(RxConfig) & rtl_chip_info[tp->chipset].RxConfigMask);
NETDRV_W32_F(RxConfig, tmp);
NETDRV_W32_F(MAR0 + 0, mc_filter[0]);
NETDRV_W32_F(MAR0 + 4, mc_filter[1]);
if (!in_irq())
spin_unlock_irq(&tp->lock);
DPRINTK("EXIT\n");
}
static int netdrv_suspend(struct pci_dev *pdev, pm_message_t state)
{
struct net_device *dev = pci_get_drvdata(pdev);
struct netdrv_private *tp = netdev_priv(dev);
void *ioaddr = tp->mmio_addr;
unsigned long flags;
if (!netif_running(dev))
return 0;
netif_device_detach(dev);
spin_lock_irqsave(&tp->lock, flags);
NETDRV_W16(IntrMask, 0x0000);
NETDRV_W8(ChipCmd, (NETDRV_R8(ChipCmd) & ChipCmdClear));
dev->stats.rx_missed_errors += NETDRV_R32(RxMissed);
NETDRV_W32(RxMissed, 0);
spin_unlock_irqrestore(&tp->lock, flags);
pci_save_state(pdev);
pci_set_power_state(pdev, PCI_D3hot);
return 0;
}
static int netdrv_resume(struct pci_dev *pdev)
{
struct net_device *dev = pci_get_drvdata(pdev);
if (!netif_running(dev))
return 0;
pci_set_power_state(pdev, PCI_D0);
pci_restore_state(pdev);
netif_device_attach(dev);
netdrv_hw_start(dev);
return 0;
}
static int __init netdrv_init_module(void)
{
#ifdef MODULE
printk(version);
#endif
return pci_register_driver(&netdrv_pci_driver);
}
static void __exit netdrv_cleanup_module(void)
{
pci_unregister_driver(&netdrv_pci_driver);
}
