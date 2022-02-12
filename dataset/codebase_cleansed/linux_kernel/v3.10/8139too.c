static void __rtl8139_cleanup_dev (struct net_device *dev)
{
struct rtl8139_private *tp = netdev_priv(dev);
struct pci_dev *pdev;
assert (dev != NULL);
assert (tp->pci_dev != NULL);
pdev = tp->pci_dev;
if (tp->mmio_addr)
pci_iounmap (pdev, tp->mmio_addr);
pci_release_regions (pdev);
free_netdev(dev);
pci_set_drvdata (pdev, NULL);
}
static void rtl8139_chip_reset (void __iomem *ioaddr)
{
int i;
RTL_W8 (ChipCmd, CmdReset);
for (i = 1000; i > 0; i--) {
barrier();
if ((RTL_R8 (ChipCmd) & CmdReset) == 0)
break;
udelay (10);
}
}
static struct net_device *rtl8139_init_board(struct pci_dev *pdev)
{
struct device *d = &pdev->dev;
void __iomem *ioaddr;
struct net_device *dev;
struct rtl8139_private *tp;
u8 tmp8;
int rc, disable_dev_on_err = 0;
unsigned int i, bar;
unsigned long io_len;
u32 version;
static const struct {
unsigned long mask;
char *type;
} res[] = {
{ IORESOURCE_IO, "PIO" },
{ IORESOURCE_MEM, "MMIO" }
};
assert (pdev != NULL);
dev = alloc_etherdev (sizeof (*tp));
if (dev == NULL)
return ERR_PTR(-ENOMEM);
SET_NETDEV_DEV(dev, &pdev->dev);
tp = netdev_priv(dev);
tp->pci_dev = pdev;
rc = pci_enable_device (pdev);
if (rc)
goto err_out;
rc = pci_request_regions (pdev, DRV_NAME);
if (rc)
goto err_out;
disable_dev_on_err = 1;
pci_set_master (pdev);
retry:
bar = !use_io;
io_len = pci_resource_len(pdev, bar);
dev_dbg(d, "%s region size = 0x%02lX\n", res[bar].type, io_len);
if (!(pci_resource_flags(pdev, bar) & res[bar].mask)) {
dev_err(d, "region #%d not a %s resource, aborting\n", bar,
res[bar].type);
rc = -ENODEV;
goto err_out;
}
if (io_len < RTL_MIN_IO_SIZE) {
dev_err(d, "Invalid PCI %s region size(s), aborting\n",
res[bar].type);
rc = -ENODEV;
goto err_out;
}
ioaddr = pci_iomap(pdev, bar, 0);
if (!ioaddr) {
dev_err(d, "cannot map %s\n", res[bar].type);
if (!use_io) {
use_io = true;
goto retry;
}
rc = -ENODEV;
goto err_out;
}
tp->regs_len = io_len;
tp->mmio_addr = ioaddr;
RTL_W8 (HltClk, 'R');
if (RTL_R32 (TxConfig) == 0xFFFFFFFF) {
dev_err(&pdev->dev, "Chip not responding, ignoring board\n");
rc = -EIO;
goto err_out;
}
version = RTL_R32 (TxConfig) & HW_REVID_MASK;
for (i = 0; i < ARRAY_SIZE (rtl_chip_info); i++)
if (version == rtl_chip_info[i].version) {
tp->chipset = i;
goto match;
}
i = 0;
dev_dbg(&pdev->dev, "unknown chip version, assuming RTL-8139\n");
dev_dbg(&pdev->dev, "TxConfig = 0x%x\n", RTL_R32 (TxConfig));
tp->chipset = 0;
match:
pr_debug("chipset id (%d) == index %d, '%s'\n",
version, i, rtl_chip_info[i].name);
if (tp->chipset >= CH_8139B) {
u8 new_tmp8 = tmp8 = RTL_R8 (Config1);
pr_debug("PCI PM wakeup\n");
if ((rtl_chip_info[tp->chipset].flags & HasLWake) &&
(tmp8 & LWAKE))
new_tmp8 &= ~LWAKE;
new_tmp8 |= Cfg1_PM_Enable;
if (new_tmp8 != tmp8) {
RTL_W8 (Cfg9346, Cfg9346_Unlock);
RTL_W8 (Config1, tmp8);
RTL_W8 (Cfg9346, Cfg9346_Lock);
}
if (rtl_chip_info[tp->chipset].flags & HasLWake) {
tmp8 = RTL_R8 (Config4);
if (tmp8 & LWPTN) {
RTL_W8 (Cfg9346, Cfg9346_Unlock);
RTL_W8 (Config4, tmp8 & ~LWPTN);
RTL_W8 (Cfg9346, Cfg9346_Lock);
}
}
} else {
pr_debug("Old chip wakeup\n");
tmp8 = RTL_R8 (Config1);
tmp8 &= ~(SLEEP | PWRDN);
RTL_W8 (Config1, tmp8);
}
rtl8139_chip_reset (ioaddr);
return dev;
err_out:
__rtl8139_cleanup_dev (dev);
if (disable_dev_on_err)
pci_disable_device (pdev);
return ERR_PTR(rc);
}
static int rtl8139_set_features(struct net_device *dev, netdev_features_t features)
{
struct rtl8139_private *tp = netdev_priv(dev);
unsigned long flags;
netdev_features_t changed = features ^ dev->features;
void __iomem *ioaddr = tp->mmio_addr;
if (!(changed & (NETIF_F_RXALL)))
return 0;
spin_lock_irqsave(&tp->lock, flags);
if (changed & NETIF_F_RXALL) {
int rx_mode = tp->rx_config;
if (features & NETIF_F_RXALL)
rx_mode |= (AcceptErr | AcceptRunt);
else
rx_mode &= ~(AcceptErr | AcceptRunt);
tp->rx_config = rtl8139_rx_config | rx_mode;
RTL_W32_F(RxConfig, tp->rx_config);
}
spin_unlock_irqrestore(&tp->lock, flags);
return 0;
}
static int rtl8139_init_one(struct pci_dev *pdev,
const struct pci_device_id *ent)
{
struct net_device *dev = NULL;
struct rtl8139_private *tp;
int i, addr_len, option;
void __iomem *ioaddr;
static int board_idx = -1;
assert (pdev != NULL);
assert (ent != NULL);
board_idx++;
#ifndef MODULE
{
static int printed_version;
if (!printed_version++)
pr_info(RTL8139_DRIVER_NAME "\n");
}
#endif
if (pdev->vendor == PCI_VENDOR_ID_REALTEK &&
pdev->device == PCI_DEVICE_ID_REALTEK_8139 && pdev->revision >= 0x20) {
dev_info(&pdev->dev,
"This (id %04x:%04x rev %02x) is an enhanced 8139C+ chip, use 8139cp\n",
pdev->vendor, pdev->device, pdev->revision);
return -ENODEV;
}
if (pdev->vendor == PCI_VENDOR_ID_REALTEK &&
pdev->device == PCI_DEVICE_ID_REALTEK_8139 &&
pdev->subsystem_vendor == PCI_VENDOR_ID_ATHEROS &&
pdev->subsystem_device == PCI_DEVICE_ID_REALTEK_8139) {
pr_info("OQO Model 2 detected. Forcing PIO\n");
use_io = 1;
}
dev = rtl8139_init_board (pdev);
if (IS_ERR(dev))
return PTR_ERR(dev);
assert (dev != NULL);
tp = netdev_priv(dev);
tp->dev = dev;
ioaddr = tp->mmio_addr;
assert (ioaddr != NULL);
addr_len = read_eeprom (ioaddr, 0, 8) == 0x8129 ? 8 : 6;
for (i = 0; i < 3; i++)
((__le16 *) (dev->dev_addr))[i] =
cpu_to_le16(read_eeprom (ioaddr, i + 7, addr_len));
dev->netdev_ops = &rtl8139_netdev_ops;
dev->ethtool_ops = &rtl8139_ethtool_ops;
dev->watchdog_timeo = TX_TIMEOUT;
netif_napi_add(dev, &tp->napi, rtl8139_poll, 64);
dev->features |= NETIF_F_SG | NETIF_F_HW_CSUM | NETIF_F_HIGHDMA;
dev->vlan_features = dev->features;
dev->hw_features |= NETIF_F_RXALL;
dev->hw_features |= NETIF_F_RXFCS;
tp = netdev_priv(dev);
tp->drv_flags = board_info[ent->driver_data].hw_flags;
tp->mmio_addr = ioaddr;
tp->msg_enable =
(debug < 0 ? RTL8139_DEF_MSG_ENABLE : ((1 << debug) - 1));
spin_lock_init (&tp->lock);
spin_lock_init (&tp->rx_lock);
INIT_DELAYED_WORK(&tp->thread, rtl8139_thread);
tp->mii.dev = dev;
tp->mii.mdio_read = mdio_read;
tp->mii.mdio_write = mdio_write;
tp->mii.phy_id_mask = 0x3f;
tp->mii.reg_num_mask = 0x1f;
pr_debug("about to register device named %s (%p)...\n",
dev->name, dev);
i = register_netdev (dev);
if (i) goto err_out;
pci_set_drvdata (pdev, dev);
netdev_info(dev, "%s at 0x%p, %pM, IRQ %d\n",
board_info[ent->driver_data].name,
ioaddr, dev->dev_addr, pdev->irq);
netdev_dbg(dev, "Identified 8139 chip type '%s'\n",
rtl_chip_info[tp->chipset].name);
#ifdef CONFIG_8139TOO_8129
if (tp->drv_flags & HAS_MII_XCVR) {
int phy, phy_idx = 0;
for (phy = 0; phy < 32 && phy_idx < sizeof(tp->phys); phy++) {
int mii_status = mdio_read(dev, phy, 1);
if (mii_status != 0xffff && mii_status != 0x0000) {
u16 advertising = mdio_read(dev, phy, 4);
tp->phys[phy_idx++] = phy;
netdev_info(dev, "MII transceiver %d status 0x%04x advertising %04x\n",
phy, mii_status, advertising);
}
}
if (phy_idx == 0) {
netdev_info(dev, "No MII transceivers found! Assuming SYM transceiver\n");
tp->phys[0] = 32;
}
} else
#endif
tp->phys[0] = 32;
tp->mii.phy_id = tp->phys[0];
option = (board_idx >= MAX_UNITS) ? 0 : media[board_idx];
if (option > 0) {
tp->mii.full_duplex = (option & 0x210) ? 1 : 0;
tp->default_port = option & 0xFF;
if (tp->default_port)
tp->mii.force_media = 1;
}
if (board_idx < MAX_UNITS && full_duplex[board_idx] > 0)
tp->mii.full_duplex = full_duplex[board_idx];
if (tp->mii.full_duplex) {
netdev_info(dev, "Media type forced to Full Duplex\n");
tp->mii.force_media = 1;
}
if (tp->default_port) {
netdev_info(dev, " Forcing %dMbps %s-duplex operation\n",
(option & 0x20 ? 100 : 10),
(option & 0x10 ? "full" : "half"));
mdio_write(dev, tp->phys[0], 0,
((option & 0x20) ? 0x2000 : 0) |
((option & 0x10) ? 0x0100 : 0));
}
if (rtl_chip_info[tp->chipset].flags & HasHltClk)
RTL_W8 (HltClk, 'H');
return 0;
err_out:
__rtl8139_cleanup_dev (dev);
pci_disable_device (pdev);
return i;
}
static void rtl8139_remove_one(struct pci_dev *pdev)
{
struct net_device *dev = pci_get_drvdata (pdev);
struct rtl8139_private *tp = netdev_priv(dev);
assert (dev != NULL);
cancel_delayed_work_sync(&tp->thread);
unregister_netdev (dev);
__rtl8139_cleanup_dev (dev);
pci_disable_device (pdev);
}
static int read_eeprom(void __iomem *ioaddr, int location, int addr_len)
{
int i;
unsigned retval = 0;
int read_cmd = location | (EE_READ_CMD << addr_len);
RTL_W8 (Cfg9346, EE_ENB & ~EE_CS);
RTL_W8 (Cfg9346, EE_ENB);
eeprom_delay ();
for (i = 4 + addr_len; i >= 0; i--) {
int dataval = (read_cmd & (1 << i)) ? EE_DATA_WRITE : 0;
RTL_W8 (Cfg9346, EE_ENB | dataval);
eeprom_delay ();
RTL_W8 (Cfg9346, EE_ENB | dataval | EE_SHIFT_CLK);
eeprom_delay ();
}
RTL_W8 (Cfg9346, EE_ENB);
eeprom_delay ();
for (i = 16; i > 0; i--) {
RTL_W8 (Cfg9346, EE_ENB | EE_SHIFT_CLK);
eeprom_delay ();
retval =
(retval << 1) | ((RTL_R8 (Cfg9346) & EE_DATA_READ) ? 1 :
0);
RTL_W8 (Cfg9346, EE_ENB);
eeprom_delay ();
}
RTL_W8(Cfg9346, 0);
eeprom_delay ();
return retval;
}
static void mdio_sync (void __iomem *ioaddr)
{
int i;
for (i = 32; i >= 0; i--) {
RTL_W8 (Config4, MDIO_WRITE1);
mdio_delay ();
RTL_W8 (Config4, MDIO_WRITE1 | MDIO_CLK);
mdio_delay ();
}
}
static int mdio_read (struct net_device *dev, int phy_id, int location)
{
struct rtl8139_private *tp = netdev_priv(dev);
int retval = 0;
#ifdef CONFIG_8139TOO_8129
void __iomem *ioaddr = tp->mmio_addr;
int mii_cmd = (0xf6 << 10) | (phy_id << 5) | location;
int i;
#endif
if (phy_id > 31) {
void __iomem *ioaddr = tp->mmio_addr;
return location < 8 && mii_2_8139_map[location] ?
RTL_R16 (mii_2_8139_map[location]) : 0;
}
#ifdef CONFIG_8139TOO_8129
mdio_sync (ioaddr);
for (i = 15; i >= 0; i--) {
int dataval = (mii_cmd & (1 << i)) ? MDIO_DATA_OUT : 0;
RTL_W8 (Config4, MDIO_DIR | dataval);
mdio_delay ();
RTL_W8 (Config4, MDIO_DIR | dataval | MDIO_CLK);
mdio_delay ();
}
for (i = 19; i > 0; i--) {
RTL_W8 (Config4, 0);
mdio_delay ();
retval = (retval << 1) | ((RTL_R8 (Config4) & MDIO_DATA_IN) ? 1 : 0);
RTL_W8 (Config4, MDIO_CLK);
mdio_delay ();
}
#endif
return (retval >> 1) & 0xffff;
}
static void mdio_write (struct net_device *dev, int phy_id, int location,
int value)
{
struct rtl8139_private *tp = netdev_priv(dev);
#ifdef CONFIG_8139TOO_8129
void __iomem *ioaddr = tp->mmio_addr;
int mii_cmd = (0x5002 << 16) | (phy_id << 23) | (location << 18) | value;
int i;
#endif
if (phy_id > 31) {
void __iomem *ioaddr = tp->mmio_addr;
if (location == 0) {
RTL_W8 (Cfg9346, Cfg9346_Unlock);
RTL_W16 (BasicModeCtrl, value);
RTL_W8 (Cfg9346, Cfg9346_Lock);
} else if (location < 8 && mii_2_8139_map[location])
RTL_W16 (mii_2_8139_map[location], value);
return;
}
#ifdef CONFIG_8139TOO_8129
mdio_sync (ioaddr);
for (i = 31; i >= 0; i--) {
int dataval =
(mii_cmd & (1 << i)) ? MDIO_WRITE1 : MDIO_WRITE0;
RTL_W8 (Config4, dataval);
mdio_delay ();
RTL_W8 (Config4, dataval | MDIO_CLK);
mdio_delay ();
}
for (i = 2; i > 0; i--) {
RTL_W8 (Config4, 0);
mdio_delay ();
RTL_W8 (Config4, MDIO_CLK);
mdio_delay ();
}
#endif
}
static int rtl8139_open (struct net_device *dev)
{
struct rtl8139_private *tp = netdev_priv(dev);
void __iomem *ioaddr = tp->mmio_addr;
const int irq = tp->pci_dev->irq;
int retval;
retval = request_irq(irq, rtl8139_interrupt, IRQF_SHARED, dev->name, dev);
if (retval)
return retval;
tp->tx_bufs = dma_alloc_coherent(&tp->pci_dev->dev, TX_BUF_TOT_LEN,
&tp->tx_bufs_dma, GFP_KERNEL);
tp->rx_ring = dma_alloc_coherent(&tp->pci_dev->dev, RX_BUF_TOT_LEN,
&tp->rx_ring_dma, GFP_KERNEL);
if (tp->tx_bufs == NULL || tp->rx_ring == NULL) {
free_irq(irq, dev);
if (tp->tx_bufs)
dma_free_coherent(&tp->pci_dev->dev, TX_BUF_TOT_LEN,
tp->tx_bufs, tp->tx_bufs_dma);
if (tp->rx_ring)
dma_free_coherent(&tp->pci_dev->dev, RX_BUF_TOT_LEN,
tp->rx_ring, tp->rx_ring_dma);
return -ENOMEM;
}
napi_enable(&tp->napi);
tp->mii.full_duplex = tp->mii.force_media;
tp->tx_flag = (TX_FIFO_THRESH << 11) & 0x003f0000;
rtl8139_init_ring (dev);
rtl8139_hw_start (dev);
netif_start_queue (dev);
netif_dbg(tp, ifup, dev,
"%s() ioaddr %#llx IRQ %d GP Pins %02x %s-duplex\n",
__func__,
(unsigned long long)pci_resource_start (tp->pci_dev, 1),
irq, RTL_R8 (MediaStatus),
tp->mii.full_duplex ? "full" : "half");
rtl8139_start_thread(tp);
return 0;
}
static void rtl_check_media (struct net_device *dev, unsigned int init_media)
{
struct rtl8139_private *tp = netdev_priv(dev);
if (tp->phys[0] >= 0) {
mii_check_media(&tp->mii, netif_msg_link(tp), init_media);
}
}
static void rtl8139_hw_start (struct net_device *dev)
{
struct rtl8139_private *tp = netdev_priv(dev);
void __iomem *ioaddr = tp->mmio_addr;
u32 i;
u8 tmp;
if (rtl_chip_info[tp->chipset].flags & HasHltClk)
RTL_W8 (HltClk, 'R');
rtl8139_chip_reset (ioaddr);
RTL_W8_F (Cfg9346, Cfg9346_Unlock);
RTL_W32_F (MAC0 + 0, le32_to_cpu (*(__le32 *) (dev->dev_addr + 0)));
RTL_W32_F (MAC0 + 4, le16_to_cpu (*(__le16 *) (dev->dev_addr + 4)));
tp->cur_rx = 0;
RTL_W32_F (RxBuf, tp->rx_ring_dma);
RTL_W8 (ChipCmd, CmdRxEnb | CmdTxEnb);
tp->rx_config = rtl8139_rx_config | AcceptBroadcast | AcceptMyPhys;
RTL_W32 (RxConfig, tp->rx_config);
RTL_W32 (TxConfig, rtl8139_tx_config);
rtl_check_media (dev, 1);
if (tp->chipset >= CH_8139B) {
RTL_W8 (Config3, RTL_R8 (Config3) & ~Cfg3_Magic);
}
netdev_dbg(dev, "init buffer addresses\n");
RTL_W8 (Cfg9346, Cfg9346_Lock);
for (i = 0; i < NUM_TX_DESC; i++)
RTL_W32_F (TxAddr0 + (i * 4), tp->tx_bufs_dma + (tp->tx_buf[i] - tp->tx_bufs));
RTL_W32 (RxMissed, 0);
rtl8139_set_rx_mode (dev);
RTL_W16 (MultiIntr, RTL_R16 (MultiIntr) & MultiIntrClear);
tmp = RTL_R8 (ChipCmd);
if ((!(tmp & CmdRxEnb)) || (!(tmp & CmdTxEnb)))
RTL_W8 (ChipCmd, CmdRxEnb | CmdTxEnb);
RTL_W16 (IntrMask, rtl8139_intr_mask);
}
static void rtl8139_init_ring (struct net_device *dev)
{
struct rtl8139_private *tp = netdev_priv(dev);
int i;
tp->cur_rx = 0;
tp->cur_tx = 0;
tp->dirty_tx = 0;
for (i = 0; i < NUM_TX_DESC; i++)
tp->tx_buf[i] = &tp->tx_bufs[i * TX_BUF_SIZE];
}
static inline void rtl8139_tune_twister (struct net_device *dev,
struct rtl8139_private *tp) {}
static void rtl8139_tune_twister (struct net_device *dev,
struct rtl8139_private *tp)
{
int linkcase;
void __iomem *ioaddr = tp->mmio_addr;
switch (tp->twistie) {
case 1:
if (RTL_R16 (CSCR) & CSCR_LinkOKBit) {
RTL_W16 (CSCR, CSCR_LinkDownOffCmd);
tp->twistie = 2;
next_tick = HZ / 10;
} else {
RTL_W16 (CSCR, CSCR_LinkDownCmd);
RTL_W32 (FIFOTMS, 0x20);
RTL_W32 (PARA78, PARA78_default);
RTL_W32 (PARA7c, PARA7c_default);
tp->twistie = 0;
}
break;
case 2:
linkcase = RTL_R16 (CSCR) & CSCR_LinkStatusBits;
if (linkcase == 0x7000)
tp->twist_row = 3;
else if (linkcase == 0x3000)
tp->twist_row = 2;
else if (linkcase == 0x1000)
tp->twist_row = 1;
else
tp->twist_row = 0;
tp->twist_col = 0;
tp->twistie = 3;
next_tick = HZ / 10;
break;
case 3:
if (tp->twist_col == 0)
RTL_W16 (FIFOTMS, 0);
RTL_W32 (PARA7c, param[(int) tp->twist_row]
[(int) tp->twist_col]);
next_tick = HZ / 10;
if (++tp->twist_col >= 4) {
tp->twistie =
(tp->twist_row == 3) ? 4 : 0;
}
break;
case 4:
if ((RTL_R16 (CSCR) &
CSCR_LinkStatusBits) == 0x7000) {
tp->twistie = 0;
break;
} else {
RTL_W32 (PARA7c, 0xfb38de03);
tp->twistie = 5;
next_tick = HZ / 10;
}
break;
case 5:
RTL_W32 (FIFOTMS, 0x20);
RTL_W32 (PARA78, PARA78_default);
RTL_W32 (PARA7c, PARA7c_default);
RTL_W32 (FIFOTMS, 0x00);
tp->twist_row = 2;
tp->twist_col = 0;
tp->twistie = 3;
next_tick = HZ / 10;
break;
default:
break;
}
}
static inline void rtl8139_thread_iter (struct net_device *dev,
struct rtl8139_private *tp,
void __iomem *ioaddr)
{
int mii_lpa;
mii_lpa = mdio_read (dev, tp->phys[0], MII_LPA);
if (!tp->mii.force_media && mii_lpa != 0xffff) {
int duplex = ((mii_lpa & LPA_100FULL) ||
(mii_lpa & 0x01C0) == 0x0040);
if (tp->mii.full_duplex != duplex) {
tp->mii.full_duplex = duplex;
if (mii_lpa) {
netdev_info(dev, "Setting %s-duplex based on MII #%d link partner ability of %04x\n",
tp->mii.full_duplex ? "full" : "half",
tp->phys[0], mii_lpa);
} else {
netdev_info(dev, "media is unconnected, link down, or incompatible connection\n");
}
#if 0
RTL_W8 (Cfg9346, Cfg9346_Unlock);
RTL_W8 (Config1, tp->mii.full_duplex ? 0x60 : 0x20);
RTL_W8 (Cfg9346, Cfg9346_Lock);
#endif
}
}
next_tick = HZ * 60;
rtl8139_tune_twister (dev, tp);
netdev_dbg(dev, "Media selection tick, Link partner %04x\n",
RTL_R16(NWayLPAR));
netdev_dbg(dev, "Other registers are IntMask %04x IntStatus %04x\n",
RTL_R16(IntrMask), RTL_R16(IntrStatus));
netdev_dbg(dev, "Chip config %02x %02x\n",
RTL_R8(Config0), RTL_R8(Config1));
}
static void rtl8139_thread (struct work_struct *work)
{
struct rtl8139_private *tp =
container_of(work, struct rtl8139_private, thread.work);
struct net_device *dev = tp->mii.dev;
unsigned long thr_delay = next_tick;
rtnl_lock();
if (!netif_running(dev))
goto out_unlock;
if (tp->watchdog_fired) {
tp->watchdog_fired = 0;
rtl8139_tx_timeout_task(work);
} else
rtl8139_thread_iter(dev, tp, tp->mmio_addr);
if (tp->have_thread)
schedule_delayed_work(&tp->thread, thr_delay);
out_unlock:
rtnl_unlock ();
}
static void rtl8139_start_thread(struct rtl8139_private *tp)
{
tp->twistie = 0;
if (tp->chipset == CH_8139_K)
tp->twistie = 1;
else if (tp->drv_flags & HAS_LNK_CHNG)
return;
tp->have_thread = 1;
tp->watchdog_fired = 0;
schedule_delayed_work(&tp->thread, next_tick);
}
static inline void rtl8139_tx_clear (struct rtl8139_private *tp)
{
tp->cur_tx = 0;
tp->dirty_tx = 0;
}
static void rtl8139_tx_timeout_task (struct work_struct *work)
{
struct rtl8139_private *tp =
container_of(work, struct rtl8139_private, thread.work);
struct net_device *dev = tp->mii.dev;
void __iomem *ioaddr = tp->mmio_addr;
int i;
u8 tmp8;
netdev_dbg(dev, "Transmit timeout, status %02x %04x %04x media %02x\n",
RTL_R8(ChipCmd), RTL_R16(IntrStatus),
RTL_R16(IntrMask), RTL_R8(MediaStatus));
netdev_dbg(dev, "Tx queue start entry %ld dirty entry %ld\n",
tp->cur_tx, tp->dirty_tx);
for (i = 0; i < NUM_TX_DESC; i++)
netdev_dbg(dev, "Tx descriptor %d is %08x%s\n",
i, RTL_R32(TxStatus0 + (i * 4)),
i == tp->dirty_tx % NUM_TX_DESC ?
" (queue head)" : "");
tp->xstats.tx_timeouts++;
tmp8 = RTL_R8 (ChipCmd);
if (tmp8 & CmdTxEnb)
RTL_W8 (ChipCmd, CmdRxEnb);
spin_lock_bh(&tp->rx_lock);
RTL_W16 (IntrMask, 0x0000);
spin_lock_irq(&tp->lock);
rtl8139_tx_clear (tp);
spin_unlock_irq(&tp->lock);
if (netif_running(dev)) {
rtl8139_hw_start (dev);
netif_wake_queue (dev);
}
spin_unlock_bh(&tp->rx_lock);
}
static void rtl8139_tx_timeout (struct net_device *dev)
{
struct rtl8139_private *tp = netdev_priv(dev);
tp->watchdog_fired = 1;
if (!tp->have_thread) {
INIT_DELAYED_WORK(&tp->thread, rtl8139_thread);
schedule_delayed_work(&tp->thread, next_tick);
}
}
static netdev_tx_t rtl8139_start_xmit (struct sk_buff *skb,
struct net_device *dev)
{
struct rtl8139_private *tp = netdev_priv(dev);
void __iomem *ioaddr = tp->mmio_addr;
unsigned int entry;
unsigned int len = skb->len;
unsigned long flags;
entry = tp->cur_tx % NUM_TX_DESC;
if (likely(len < TX_BUF_SIZE)) {
if (len < ETH_ZLEN)
memset(tp->tx_buf[entry], 0, ETH_ZLEN);
skb_copy_and_csum_dev(skb, tp->tx_buf[entry]);
dev_kfree_skb(skb);
} else {
dev_kfree_skb(skb);
dev->stats.tx_dropped++;
return NETDEV_TX_OK;
}
spin_lock_irqsave(&tp->lock, flags);
wmb();
RTL_W32_F (TxStatus0 + (entry * sizeof (u32)),
tp->tx_flag | max(len, (unsigned int)ETH_ZLEN));
tp->cur_tx++;
if ((tp->cur_tx - NUM_TX_DESC) == tp->dirty_tx)
netif_stop_queue (dev);
spin_unlock_irqrestore(&tp->lock, flags);
netif_dbg(tp, tx_queued, dev, "Queued Tx packet size %u to slot %d\n",
len, entry);
return NETDEV_TX_OK;
}
static void rtl8139_tx_interrupt (struct net_device *dev,
struct rtl8139_private *tp,
void __iomem *ioaddr)
{
unsigned long dirty_tx, tx_left;
assert (dev != NULL);
assert (ioaddr != NULL);
dirty_tx = tp->dirty_tx;
tx_left = tp->cur_tx - dirty_tx;
while (tx_left > 0) {
int entry = dirty_tx % NUM_TX_DESC;
int txstatus;
txstatus = RTL_R32 (TxStatus0 + (entry * sizeof (u32)));
if (!(txstatus & (TxStatOK | TxUnderrun | TxAborted)))
break;
if (txstatus & (TxOutOfWindow | TxAborted)) {
netif_dbg(tp, tx_err, dev, "Transmit error, Tx status %08x\n",
txstatus);
dev->stats.tx_errors++;
if (txstatus & TxAborted) {
dev->stats.tx_aborted_errors++;
RTL_W32 (TxConfig, TxClearAbt);
RTL_W16 (IntrStatus, TxErr);
wmb();
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
u64_stats_update_begin(&tp->tx_stats.syncp);
tp->tx_stats.packets++;
tp->tx_stats.bytes += txstatus & 0x7ff;
u64_stats_update_end(&tp->tx_stats.syncp);
}
dirty_tx++;
tx_left--;
}
#ifndef RTL8139_NDEBUG
if (tp->cur_tx - dirty_tx > NUM_TX_DESC) {
netdev_err(dev, "Out-of-sync dirty pointer, %ld vs. %ld\n",
dirty_tx, tp->cur_tx);
dirty_tx += NUM_TX_DESC;
}
#endif
if (tp->dirty_tx != dirty_tx) {
tp->dirty_tx = dirty_tx;
mb();
netif_wake_queue (dev);
}
}
static void rtl8139_rx_err (u32 rx_status, struct net_device *dev,
struct rtl8139_private *tp, void __iomem *ioaddr)
{
u8 tmp8;
#ifdef CONFIG_8139_OLD_RX_RESET
int tmp_work;
#endif
netif_dbg(tp, rx_err, dev, "Ethernet frame had errors, status %08x\n",
rx_status);
dev->stats.rx_errors++;
if (!(rx_status & RxStatusOK)) {
if (rx_status & RxTooLong) {
netdev_dbg(dev, "Oversized Ethernet frame, status %04x!\n",
rx_status);
}
if (rx_status & (RxBadSymbol | RxBadAlign))
dev->stats.rx_frame_errors++;
if (rx_status & (RxRunt | RxTooLong))
dev->stats.rx_length_errors++;
if (rx_status & RxCRCErr)
dev->stats.rx_crc_errors++;
} else {
tp->xstats.rx_lost_in_ring++;
}
#ifndef CONFIG_8139_OLD_RX_RESET
tmp8 = RTL_R8 (ChipCmd);
RTL_W8 (ChipCmd, tmp8 & ~CmdRxEnb);
RTL_W8 (ChipCmd, tmp8);
RTL_W32 (RxConfig, tp->rx_config);
tp->cur_rx = 0;
#else
RTL_W8_F (ChipCmd, CmdTxEnb);
tmp_work = 200;
while (--tmp_work > 0) {
udelay(1);
tmp8 = RTL_R8 (ChipCmd);
if (!(tmp8 & CmdRxEnb))
break;
}
if (tmp_work <= 0)
netdev_warn(dev, "rx stop wait too long\n");
tmp_work = 200;
while (--tmp_work > 0) {
RTL_W8_F (ChipCmd, CmdRxEnb | CmdTxEnb);
udelay(1);
tmp8 = RTL_R8 (ChipCmd);
if ((tmp8 & CmdRxEnb) && (tmp8 & CmdTxEnb))
break;
}
if (tmp_work <= 0)
netdev_warn(dev, "tx/rx enable wait too long\n");
RTL_W8_F (Cfg9346, Cfg9346_Unlock);
RTL_W8 (ChipCmd, CmdRxEnb | CmdTxEnb);
tp->rx_config = rtl8139_rx_config | AcceptBroadcast | AcceptMyPhys;
RTL_W32 (RxConfig, tp->rx_config);
tp->cur_rx = 0;
netdev_dbg(dev, "init buffer addresses\n");
RTL_W8 (Cfg9346, Cfg9346_Lock);
RTL_W32_F (RxBuf, tp->rx_ring_dma);
__set_rx_mode (dev);
#endif
}
static inline void wrap_copy(struct sk_buff *skb, const unsigned char *ring,
u32 offset, unsigned int size)
{
u32 left = RX_BUF_LEN - offset;
if (size > left) {
skb_copy_to_linear_data(skb, ring + offset, left);
skb_copy_to_linear_data_offset(skb, left, ring, size - left);
} else
skb_copy_to_linear_data(skb, ring + offset, size);
}
static void rtl8139_isr_ack(struct rtl8139_private *tp)
{
void __iomem *ioaddr = tp->mmio_addr;
u16 status;
status = RTL_R16 (IntrStatus) & RxAckBits;
if (likely(status != 0)) {
if (unlikely(status & (RxFIFOOver | RxOverflow))) {
tp->dev->stats.rx_errors++;
if (status & RxFIFOOver)
tp->dev->stats.rx_fifo_errors++;
}
RTL_W16_F (IntrStatus, RxAckBits);
}
}
static int rtl8139_rx(struct net_device *dev, struct rtl8139_private *tp,
int budget)
{
void __iomem *ioaddr = tp->mmio_addr;
int received = 0;
unsigned char *rx_ring = tp->rx_ring;
unsigned int cur_rx = tp->cur_rx;
unsigned int rx_size = 0;
netdev_dbg(dev, "In %s(), current %04x BufAddr %04x, free to %04x, Cmd %02x\n",
__func__, (u16)cur_rx,
RTL_R16(RxBufAddr), RTL_R16(RxBufPtr), RTL_R8(ChipCmd));
while (netif_running(dev) && received < budget &&
(RTL_R8 (ChipCmd) & RxBufEmpty) == 0) {
u32 ring_offset = cur_rx % RX_BUF_LEN;
u32 rx_status;
unsigned int pkt_size;
struct sk_buff *skb;
rmb();
rx_status = le32_to_cpu (*(__le32 *) (rx_ring + ring_offset));
rx_size = rx_status >> 16;
if (likely(!(dev->features & NETIF_F_RXFCS)))
pkt_size = rx_size - 4;
else
pkt_size = rx_size;
netif_dbg(tp, rx_status, dev, "%s() status %04x, size %04x, cur %04x\n",
__func__, rx_status, rx_size, cur_rx);
#if RTL8139_DEBUG > 2
print_hex_dump(KERN_DEBUG, "Frame contents: ",
DUMP_PREFIX_OFFSET, 16, 1,
&rx_ring[ring_offset], 70, true);
#endif
if (unlikely(rx_size == 0xfff0)) {
if (!tp->fifo_copy_timeout)
tp->fifo_copy_timeout = jiffies + 2;
else if (time_after(jiffies, tp->fifo_copy_timeout)) {
netdev_dbg(dev, "hung FIFO. Reset\n");
rx_size = 0;
goto no_early_rx;
}
netif_dbg(tp, intr, dev, "fifo copy in progress\n");
tp->xstats.early_rx++;
break;
}
no_early_rx:
tp->fifo_copy_timeout = 0;
if (unlikely((rx_size > (MAX_ETH_FRAME_SIZE+4)) ||
(rx_size < 8) ||
(!(rx_status & RxStatusOK)))) {
if ((dev->features & NETIF_F_RXALL) &&
(rx_size <= (MAX_ETH_FRAME_SIZE + 4)) &&
(rx_size >= 8) &&
(!(rx_status & RxStatusOK))) {
dev->stats.rx_errors++;
if (rx_status & RxCRCErr) {
dev->stats.rx_crc_errors++;
goto keep_pkt;
}
if (rx_status & RxRunt) {
dev->stats.rx_length_errors++;
goto keep_pkt;
}
}
rtl8139_rx_err (rx_status, dev, tp, ioaddr);
received = -1;
goto out;
}
keep_pkt:
skb = netdev_alloc_skb_ip_align(dev, pkt_size);
if (likely(skb)) {
#if RX_BUF_IDX == 3
wrap_copy(skb, rx_ring, ring_offset+4, pkt_size);
#else
skb_copy_to_linear_data (skb, &rx_ring[ring_offset + 4], pkt_size);
#endif
skb_put (skb, pkt_size);
skb->protocol = eth_type_trans (skb, dev);
u64_stats_update_begin(&tp->rx_stats.syncp);
tp->rx_stats.packets++;
tp->rx_stats.bytes += pkt_size;
u64_stats_update_end(&tp->rx_stats.syncp);
netif_receive_skb (skb);
} else {
dev->stats.rx_dropped++;
}
received++;
cur_rx = (cur_rx + rx_size + 4 + 3) & ~3;
RTL_W16 (RxBufPtr, (u16) (cur_rx - 16));
rtl8139_isr_ack(tp);
}
if (unlikely(!received || rx_size == 0xfff0))
rtl8139_isr_ack(tp);
netdev_dbg(dev, "Done %s(), current %04x BufAddr %04x, free to %04x, Cmd %02x\n",
__func__, cur_rx,
RTL_R16(RxBufAddr), RTL_R16(RxBufPtr), RTL_R8(ChipCmd));
tp->cur_rx = cur_rx;
if (tp->fifo_copy_timeout)
received = budget;
out:
return received;
}
static void rtl8139_weird_interrupt (struct net_device *dev,
struct rtl8139_private *tp,
void __iomem *ioaddr,
int status, int link_changed)
{
netdev_dbg(dev, "Abnormal interrupt, status %08x\n", status);
assert (dev != NULL);
assert (tp != NULL);
assert (ioaddr != NULL);
dev->stats.rx_missed_errors += RTL_R32 (RxMissed);
RTL_W32 (RxMissed, 0);
if ((status & RxUnderrun) && link_changed &&
(tp->drv_flags & HAS_LNK_CHNG)) {
rtl_check_media(dev, 0);
status &= ~RxUnderrun;
}
if (status & (RxUnderrun | RxErr))
dev->stats.rx_errors++;
if (status & PCSTimeout)
dev->stats.rx_length_errors++;
if (status & RxUnderrun)
dev->stats.rx_fifo_errors++;
if (status & PCIErr) {
u16 pci_cmd_status;
pci_read_config_word (tp->pci_dev, PCI_STATUS, &pci_cmd_status);
pci_write_config_word (tp->pci_dev, PCI_STATUS, pci_cmd_status);
netdev_err(dev, "PCI Bus error %04x\n", pci_cmd_status);
}
}
static int rtl8139_poll(struct napi_struct *napi, int budget)
{
struct rtl8139_private *tp = container_of(napi, struct rtl8139_private, napi);
struct net_device *dev = tp->dev;
void __iomem *ioaddr = tp->mmio_addr;
int work_done;
spin_lock(&tp->rx_lock);
work_done = 0;
if (likely(RTL_R16(IntrStatus) & RxAckBits))
work_done += rtl8139_rx(dev, tp, budget);
if (work_done < budget) {
unsigned long flags;
spin_lock_irqsave(&tp->lock, flags);
__napi_complete(napi);
RTL_W16_F(IntrMask, rtl8139_intr_mask);
spin_unlock_irqrestore(&tp->lock, flags);
}
spin_unlock(&tp->rx_lock);
return work_done;
}
static irqreturn_t rtl8139_interrupt (int irq, void *dev_instance)
{
struct net_device *dev = (struct net_device *) dev_instance;
struct rtl8139_private *tp = netdev_priv(dev);
void __iomem *ioaddr = tp->mmio_addr;
u16 status, ackstat;
int link_changed = 0;
int handled = 0;
spin_lock (&tp->lock);
status = RTL_R16 (IntrStatus);
if (unlikely((status & rtl8139_intr_mask) == 0))
goto out;
handled = 1;
if (unlikely(status == 0xFFFF))
goto out;
if (unlikely(!netif_running(dev))) {
RTL_W16 (IntrMask, 0);
goto out;
}
if (unlikely(status & RxUnderrun))
link_changed = RTL_R16 (CSCR) & CSCR_LinkChangeBit;
ackstat = status & ~(RxAckBits | TxErr);
if (ackstat)
RTL_W16 (IntrStatus, ackstat);
if (status & RxAckBits){
if (napi_schedule_prep(&tp->napi)) {
RTL_W16_F (IntrMask, rtl8139_norx_intr_mask);
__napi_schedule(&tp->napi);
}
}
if (unlikely(status & (PCIErr | PCSTimeout | RxUnderrun | RxErr)))
rtl8139_weird_interrupt (dev, tp, ioaddr,
status, link_changed);
if (status & (TxOK | TxErr)) {
rtl8139_tx_interrupt (dev, tp, ioaddr);
if (status & TxErr)
RTL_W16 (IntrStatus, TxErr);
}
out:
spin_unlock (&tp->lock);
netdev_dbg(dev, "exiting interrupt, intr_status=%#4.4x\n",
RTL_R16(IntrStatus));
return IRQ_RETVAL(handled);
}
static void rtl8139_poll_controller(struct net_device *dev)
{
struct rtl8139_private *tp = netdev_priv(dev);
const int irq = tp->pci_dev->irq;
disable_irq(irq);
rtl8139_interrupt(irq, dev);
enable_irq(irq);
}
static int rtl8139_set_mac_address(struct net_device *dev, void *p)
{
struct rtl8139_private *tp = netdev_priv(dev);
void __iomem *ioaddr = tp->mmio_addr;
struct sockaddr *addr = p;
if (!is_valid_ether_addr(addr->sa_data))
return -EADDRNOTAVAIL;
memcpy(dev->dev_addr, addr->sa_data, dev->addr_len);
spin_lock_irq(&tp->lock);
RTL_W8_F(Cfg9346, Cfg9346_Unlock);
RTL_W32_F(MAC0 + 0, cpu_to_le32 (*(u32 *) (dev->dev_addr + 0)));
RTL_W32_F(MAC0 + 4, cpu_to_le32 (*(u32 *) (dev->dev_addr + 4)));
RTL_W8_F(Cfg9346, Cfg9346_Lock);
spin_unlock_irq(&tp->lock);
return 0;
}
static int rtl8139_close (struct net_device *dev)
{
struct rtl8139_private *tp = netdev_priv(dev);
void __iomem *ioaddr = tp->mmio_addr;
unsigned long flags;
netif_stop_queue(dev);
napi_disable(&tp->napi);
netif_dbg(tp, ifdown, dev, "Shutting down ethercard, status was 0x%04x\n",
RTL_R16(IntrStatus));
spin_lock_irqsave (&tp->lock, flags);
RTL_W8 (ChipCmd, 0);
RTL_W16 (IntrMask, 0);
dev->stats.rx_missed_errors += RTL_R32 (RxMissed);
RTL_W32 (RxMissed, 0);
spin_unlock_irqrestore (&tp->lock, flags);
free_irq(tp->pci_dev->irq, dev);
rtl8139_tx_clear (tp);
dma_free_coherent(&tp->pci_dev->dev, RX_BUF_TOT_LEN,
tp->rx_ring, tp->rx_ring_dma);
dma_free_coherent(&tp->pci_dev->dev, TX_BUF_TOT_LEN,
tp->tx_bufs, tp->tx_bufs_dma);
tp->rx_ring = NULL;
tp->tx_bufs = NULL;
RTL_W8 (Cfg9346, Cfg9346_Unlock);
if (rtl_chip_info[tp->chipset].flags & HasHltClk)
RTL_W8 (HltClk, 'H');
return 0;
}
static void rtl8139_get_wol(struct net_device *dev, struct ethtool_wolinfo *wol)
{
struct rtl8139_private *tp = netdev_priv(dev);
void __iomem *ioaddr = tp->mmio_addr;
spin_lock_irq(&tp->lock);
if (rtl_chip_info[tp->chipset].flags & HasLWake) {
u8 cfg3 = RTL_R8 (Config3);
u8 cfg5 = RTL_R8 (Config5);
wol->supported = WAKE_PHY | WAKE_MAGIC
| WAKE_UCAST | WAKE_MCAST | WAKE_BCAST;
wol->wolopts = 0;
if (cfg3 & Cfg3_LinkUp)
wol->wolopts |= WAKE_PHY;
if (cfg3 & Cfg3_Magic)
wol->wolopts |= WAKE_MAGIC;
if (cfg5 & Cfg5_UWF)
wol->wolopts |= WAKE_UCAST;
if (cfg5 & Cfg5_MWF)
wol->wolopts |= WAKE_MCAST;
if (cfg5 & Cfg5_BWF)
wol->wolopts |= WAKE_BCAST;
}
spin_unlock_irq(&tp->lock);
}
static int rtl8139_set_wol(struct net_device *dev, struct ethtool_wolinfo *wol)
{
struct rtl8139_private *tp = netdev_priv(dev);
void __iomem *ioaddr = tp->mmio_addr;
u32 support;
u8 cfg3, cfg5;
support = ((rtl_chip_info[tp->chipset].flags & HasLWake)
? (WAKE_PHY | WAKE_MAGIC
| WAKE_UCAST | WAKE_MCAST | WAKE_BCAST)
: 0);
if (wol->wolopts & ~support)
return -EINVAL;
spin_lock_irq(&tp->lock);
cfg3 = RTL_R8 (Config3) & ~(Cfg3_LinkUp | Cfg3_Magic);
if (wol->wolopts & WAKE_PHY)
cfg3 |= Cfg3_LinkUp;
if (wol->wolopts & WAKE_MAGIC)
cfg3 |= Cfg3_Magic;
RTL_W8 (Cfg9346, Cfg9346_Unlock);
RTL_W8 (Config3, cfg3);
RTL_W8 (Cfg9346, Cfg9346_Lock);
cfg5 = RTL_R8 (Config5) & ~(Cfg5_UWF | Cfg5_MWF | Cfg5_BWF);
if (wol->wolopts & WAKE_UCAST)
cfg5 |= Cfg5_UWF;
if (wol->wolopts & WAKE_MCAST)
cfg5 |= Cfg5_MWF;
if (wol->wolopts & WAKE_BCAST)
cfg5 |= Cfg5_BWF;
RTL_W8 (Config5, cfg5);
spin_unlock_irq(&tp->lock);
return 0;
}
static void rtl8139_get_drvinfo(struct net_device *dev, struct ethtool_drvinfo *info)
{
struct rtl8139_private *tp = netdev_priv(dev);
strlcpy(info->driver, DRV_NAME, sizeof(info->driver));
strlcpy(info->version, DRV_VERSION, sizeof(info->version));
strlcpy(info->bus_info, pci_name(tp->pci_dev), sizeof(info->bus_info));
info->regdump_len = tp->regs_len;
}
static int rtl8139_get_settings(struct net_device *dev, struct ethtool_cmd *cmd)
{
struct rtl8139_private *tp = netdev_priv(dev);
spin_lock_irq(&tp->lock);
mii_ethtool_gset(&tp->mii, cmd);
spin_unlock_irq(&tp->lock);
return 0;
}
static int rtl8139_set_settings(struct net_device *dev, struct ethtool_cmd *cmd)
{
struct rtl8139_private *tp = netdev_priv(dev);
int rc;
spin_lock_irq(&tp->lock);
rc = mii_ethtool_sset(&tp->mii, cmd);
spin_unlock_irq(&tp->lock);
return rc;
}
static int rtl8139_nway_reset(struct net_device *dev)
{
struct rtl8139_private *tp = netdev_priv(dev);
return mii_nway_restart(&tp->mii);
}
static u32 rtl8139_get_link(struct net_device *dev)
{
struct rtl8139_private *tp = netdev_priv(dev);
return mii_link_ok(&tp->mii);
}
static u32 rtl8139_get_msglevel(struct net_device *dev)
{
struct rtl8139_private *tp = netdev_priv(dev);
return tp->msg_enable;
}
static void rtl8139_set_msglevel(struct net_device *dev, u32 datum)
{
struct rtl8139_private *tp = netdev_priv(dev);
tp->msg_enable = datum;
}
static int rtl8139_get_regs_len(struct net_device *dev)
{
struct rtl8139_private *tp;
if (use_io)
return 0;
tp = netdev_priv(dev);
return tp->regs_len;
}
static void rtl8139_get_regs(struct net_device *dev, struct ethtool_regs *regs, void *regbuf)
{
struct rtl8139_private *tp;
if (use_io)
return;
tp = netdev_priv(dev);
regs->version = RTL_REGS_VER;
spin_lock_irq(&tp->lock);
memcpy_fromio(regbuf, tp->mmio_addr, regs->len);
spin_unlock_irq(&tp->lock);
}
static int rtl8139_get_sset_count(struct net_device *dev, int sset)
{
switch (sset) {
case ETH_SS_STATS:
return RTL_NUM_STATS;
default:
return -EOPNOTSUPP;
}
}
static void rtl8139_get_ethtool_stats(struct net_device *dev, struct ethtool_stats *stats, u64 *data)
{
struct rtl8139_private *tp = netdev_priv(dev);
data[0] = tp->xstats.early_rx;
data[1] = tp->xstats.tx_buf_mapped;
data[2] = tp->xstats.tx_timeouts;
data[3] = tp->xstats.rx_lost_in_ring;
}
static void rtl8139_get_strings(struct net_device *dev, u32 stringset, u8 *data)
{
memcpy(data, ethtool_stats_keys, sizeof(ethtool_stats_keys));
}
static int netdev_ioctl(struct net_device *dev, struct ifreq *rq, int cmd)
{
struct rtl8139_private *tp = netdev_priv(dev);
int rc;
if (!netif_running(dev))
return -EINVAL;
spin_lock_irq(&tp->lock);
rc = generic_mii_ioctl(&tp->mii, if_mii(rq), cmd, NULL);
spin_unlock_irq(&tp->lock);
return rc;
}
static struct rtnl_link_stats64 *
rtl8139_get_stats64(struct net_device *dev, struct rtnl_link_stats64 *stats)
{
struct rtl8139_private *tp = netdev_priv(dev);
void __iomem *ioaddr = tp->mmio_addr;
unsigned long flags;
unsigned int start;
if (netif_running(dev)) {
spin_lock_irqsave (&tp->lock, flags);
dev->stats.rx_missed_errors += RTL_R32 (RxMissed);
RTL_W32 (RxMissed, 0);
spin_unlock_irqrestore (&tp->lock, flags);
}
netdev_stats_to_stats64(stats, &dev->stats);
do {
start = u64_stats_fetch_begin_bh(&tp->rx_stats.syncp);
stats->rx_packets = tp->rx_stats.packets;
stats->rx_bytes = tp->rx_stats.bytes;
} while (u64_stats_fetch_retry_bh(&tp->rx_stats.syncp, start));
do {
start = u64_stats_fetch_begin_bh(&tp->tx_stats.syncp);
stats->tx_packets = tp->tx_stats.packets;
stats->tx_bytes = tp->tx_stats.bytes;
} while (u64_stats_fetch_retry_bh(&tp->tx_stats.syncp, start));
return stats;
}
static void __set_rx_mode (struct net_device *dev)
{
struct rtl8139_private *tp = netdev_priv(dev);
void __iomem *ioaddr = tp->mmio_addr;
u32 mc_filter[2];
int rx_mode;
u32 tmp;
netdev_dbg(dev, "rtl8139_set_rx_mode(%04x) done -- Rx config %08x\n",
dev->flags, RTL_R32(RxConfig));
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
rx_mode = AcceptBroadcast | AcceptMyPhys;
mc_filter[1] = mc_filter[0] = 0;
netdev_for_each_mc_addr(ha, dev) {
int bit_nr = ether_crc(ETH_ALEN, ha->addr) >> 26;
mc_filter[bit_nr >> 5] |= 1 << (bit_nr & 31);
rx_mode |= AcceptMulticast;
}
}
if (dev->features & NETIF_F_RXALL)
rx_mode |= (AcceptErr | AcceptRunt);
tmp = rtl8139_rx_config | rx_mode;
if (tp->rx_config != tmp) {
RTL_W32_F (RxConfig, tmp);
tp->rx_config = tmp;
}
RTL_W32_F (MAR0 + 0, mc_filter[0]);
RTL_W32_F (MAR0 + 4, mc_filter[1]);
}
static void rtl8139_set_rx_mode (struct net_device *dev)
{
unsigned long flags;
struct rtl8139_private *tp = netdev_priv(dev);
spin_lock_irqsave (&tp->lock, flags);
__set_rx_mode(dev);
spin_unlock_irqrestore (&tp->lock, flags);
}
static int rtl8139_suspend (struct pci_dev *pdev, pm_message_t state)
{
struct net_device *dev = pci_get_drvdata (pdev);
struct rtl8139_private *tp = netdev_priv(dev);
void __iomem *ioaddr = tp->mmio_addr;
unsigned long flags;
pci_save_state (pdev);
if (!netif_running (dev))
return 0;
netif_device_detach (dev);
spin_lock_irqsave (&tp->lock, flags);
RTL_W16 (IntrMask, 0);
RTL_W8 (ChipCmd, 0);
dev->stats.rx_missed_errors += RTL_R32 (RxMissed);
RTL_W32 (RxMissed, 0);
spin_unlock_irqrestore (&tp->lock, flags);
pci_set_power_state (pdev, PCI_D3hot);
return 0;
}
static int rtl8139_resume (struct pci_dev *pdev)
{
struct net_device *dev = pci_get_drvdata (pdev);
pci_restore_state (pdev);
if (!netif_running (dev))
return 0;
pci_set_power_state (pdev, PCI_D0);
rtl8139_init_ring (dev);
rtl8139_hw_start (dev);
netif_device_attach (dev);
return 0;
}
static int __init rtl8139_init_module (void)
{
#ifdef MODULE
pr_info(RTL8139_DRIVER_NAME "\n");
#endif
return pci_register_driver(&rtl8139_pci_driver);
}
static void __exit rtl8139_cleanup_module (void)
{
pci_unregister_driver (&rtl8139_pci_driver);
}
