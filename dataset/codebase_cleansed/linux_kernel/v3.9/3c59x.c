static void window_set(struct vortex_private *vp, int window)
{
if (window != vp->window) {
iowrite16(SelectWindow + window, vp->ioaddr + EL3_CMD);
vp->window = window;
}
}
static void poll_vortex(struct net_device *dev)
{
struct vortex_private *vp = netdev_priv(dev);
unsigned long flags;
local_irq_save(flags);
(vp->full_bus_master_rx ? boomerang_interrupt:vortex_interrupt)(dev->irq,dev);
local_irq_restore(flags);
}
static int vortex_suspend(struct device *dev)
{
struct pci_dev *pdev = to_pci_dev(dev);
struct net_device *ndev = pci_get_drvdata(pdev);
if (!ndev || !netif_running(ndev))
return 0;
netif_device_detach(ndev);
vortex_down(ndev, 1);
return 0;
}
static int vortex_resume(struct device *dev)
{
struct pci_dev *pdev = to_pci_dev(dev);
struct net_device *ndev = pci_get_drvdata(pdev);
int err;
if (!ndev || !netif_running(ndev))
return 0;
err = vortex_up(ndev);
if (err)
return err;
netif_device_attach(ndev);
return 0;
}
static int __init vortex_eisa_probe(struct device *device)
{
void __iomem *ioaddr;
struct eisa_device *edev;
edev = to_eisa_device(device);
if (!request_region(edev->base_addr, VORTEX_TOTAL_SIZE, DRV_NAME))
return -EBUSY;
ioaddr = ioport_map(edev->base_addr, VORTEX_TOTAL_SIZE);
if (vortex_probe1(device, ioaddr, ioread16(ioaddr + 0xC88) >> 12,
edev->id.driver_data, vortex_cards_found)) {
release_region(edev->base_addr, VORTEX_TOTAL_SIZE);
return -ENODEV;
}
vortex_cards_found++;
return 0;
}
static int vortex_eisa_remove(struct device *device)
{
struct eisa_device *edev;
struct net_device *dev;
struct vortex_private *vp;
void __iomem *ioaddr;
edev = to_eisa_device(device);
dev = eisa_get_drvdata(edev);
if (!dev) {
pr_err("vortex_eisa_remove called for Compaq device!\n");
BUG();
}
vp = netdev_priv(dev);
ioaddr = vp->ioaddr;
unregister_netdev(dev);
iowrite16(TotalReset|0x14, ioaddr + EL3_CMD);
release_region(dev->base_addr, VORTEX_TOTAL_SIZE);
free_netdev(dev);
return 0;
}
static int __init vortex_eisa_init(void)
{
int eisa_found = 0;
int orig_cards_found = vortex_cards_found;
#ifdef CONFIG_EISA
int err;
err = eisa_driver_register (&vortex_eisa_driver);
if (!err) {
eisa_found = 1;
}
#endif
if (compaq_ioaddr) {
vortex_probe1(NULL, ioport_map(compaq_ioaddr, VORTEX_TOTAL_SIZE),
compaq_irq, compaq_device_id, vortex_cards_found++);
}
return vortex_cards_found - orig_cards_found + eisa_found;
}
static int vortex_init_one(struct pci_dev *pdev,
const struct pci_device_id *ent)
{
int rc, unit, pci_bar;
struct vortex_chip_info *vci;
void __iomem *ioaddr;
rc = pci_enable_device(pdev);
if (rc < 0)
goto out;
unit = vortex_cards_found;
if (global_use_mmio < 0 && (unit >= MAX_UNITS || use_mmio[unit] < 0)) {
vci = &vortex_info_tbl[ent->driver_data];
pci_bar = vci->drv_flags & (IS_CYCLONE | IS_TORNADO) ? 1 : 0;
} else if (unit < MAX_UNITS && use_mmio[unit] >= 0)
pci_bar = use_mmio[unit] ? 1 : 0;
else
pci_bar = global_use_mmio ? 1 : 0;
ioaddr = pci_iomap(pdev, pci_bar, 0);
if (!ioaddr)
ioaddr = pci_iomap(pdev, 0, 0);
if (!ioaddr) {
pci_disable_device(pdev);
rc = -ENOMEM;
goto out;
}
rc = vortex_probe1(&pdev->dev, ioaddr, pdev->irq,
ent->driver_data, unit);
if (rc < 0) {
pci_iounmap(pdev, ioaddr);
pci_disable_device(pdev);
goto out;
}
vortex_cards_found++;
out:
return rc;
}
static int vortex_probe1(struct device *gendev, void __iomem *ioaddr, int irq,
int chip_idx, int card_idx)
{
struct vortex_private *vp;
int option;
unsigned int eeprom[0x40], checksum = 0;
int i, step;
struct net_device *dev;
static int printed_version;
int retval, print_info;
struct vortex_chip_info * const vci = &vortex_info_tbl[chip_idx];
const char *print_name = "3c59x";
struct pci_dev *pdev = NULL;
struct eisa_device *edev = NULL;
if (!printed_version) {
pr_info("%s", version);
printed_version = 1;
}
if (gendev) {
if ((pdev = DEVICE_PCI(gendev))) {
print_name = pci_name(pdev);
}
if ((edev = DEVICE_EISA(gendev))) {
print_name = dev_name(&edev->dev);
}
}
dev = alloc_etherdev(sizeof(*vp));
retval = -ENOMEM;
if (!dev)
goto out;
SET_NETDEV_DEV(dev, gendev);
vp = netdev_priv(dev);
option = global_options;
if (dev->mem_start) {
option = dev->mem_start;
}
else if (card_idx < MAX_UNITS) {
if (options[card_idx] >= 0)
option = options[card_idx];
}
if (option > 0) {
if (option & 0x8000)
vortex_debug = 7;
if (option & 0x4000)
vortex_debug = 2;
if (option & 0x0400)
vp->enable_wol = 1;
}
print_info = (vortex_debug > 1);
if (print_info)
pr_info("See Documentation/networking/vortex.txt\n");
pr_info("%s: 3Com %s %s at %p.\n",
print_name,
pdev ? "PCI" : "EISA",
vci->name,
ioaddr);
dev->base_addr = (unsigned long)ioaddr;
dev->irq = irq;
dev->mtu = mtu;
vp->ioaddr = ioaddr;
vp->large_frames = mtu > 1500;
vp->drv_flags = vci->drv_flags;
vp->has_nway = (vci->drv_flags & HAS_NWAY) ? 1 : 0;
vp->io_size = vci->io_size;
vp->card_idx = card_idx;
vp->window = -1;
if (gendev == NULL) {
compaq_net_device = dev;
}
if (pdev) {
if (request_region(dev->base_addr, vci->io_size, print_name) != NULL)
vp->must_free_region = 1;
if (vci->flags & PCI_USES_MASTER)
pci_set_master(pdev);
if (vci->drv_flags & IS_VORTEX) {
u8 pci_latency;
u8 new_latency = 248;
pci_read_config_byte(pdev, PCI_LATENCY_TIMER, &pci_latency);
if (pci_latency < new_latency) {
pr_info("%s: Overriding PCI latency timer (CFLT) setting of %d, new value is %d.\n",
print_name, pci_latency, new_latency);
pci_write_config_byte(pdev, PCI_LATENCY_TIMER, new_latency);
}
}
}
spin_lock_init(&vp->lock);
spin_lock_init(&vp->mii_lock);
spin_lock_init(&vp->window_lock);
vp->gendev = gendev;
vp->mii.dev = dev;
vp->mii.mdio_read = mdio_read;
vp->mii.mdio_write = mdio_write;
vp->mii.phy_id_mask = 0x1f;
vp->mii.reg_num_mask = 0x1f;
vp->rx_ring = pci_alloc_consistent(pdev, sizeof(struct boom_rx_desc) * RX_RING_SIZE
+ sizeof(struct boom_tx_desc) * TX_RING_SIZE,
&vp->rx_ring_dma);
retval = -ENOMEM;
if (!vp->rx_ring)
goto free_region;
vp->tx_ring = (struct boom_tx_desc *)(vp->rx_ring + RX_RING_SIZE);
vp->tx_ring_dma = vp->rx_ring_dma + sizeof(struct boom_rx_desc) * RX_RING_SIZE;
if (pdev)
pci_set_drvdata(pdev, dev);
if (edev)
eisa_set_drvdata(edev, dev);
vp->media_override = 7;
if (option >= 0) {
vp->media_override = ((option & 7) == 2) ? 0 : option & 15;
if (vp->media_override != 7)
vp->medialock = 1;
vp->full_duplex = (option & 0x200) ? 1 : 0;
vp->bus_master = (option & 16) ? 1 : 0;
}
if (global_full_duplex > 0)
vp->full_duplex = 1;
if (global_enable_wol > 0)
vp->enable_wol = 1;
if (card_idx < MAX_UNITS) {
if (full_duplex[card_idx] > 0)
vp->full_duplex = 1;
if (flow_ctrl[card_idx] > 0)
vp->flow_ctrl = 1;
if (enable_wol[card_idx] > 0)
vp->enable_wol = 1;
}
vp->mii.force_media = vp->full_duplex;
vp->options = option;
{
int base;
if (vci->drv_flags & EEPROM_8BIT)
base = 0x230;
else if (vci->drv_flags & EEPROM_OFFSET)
base = EEPROM_Read + 0x30;
else
base = EEPROM_Read;
for (i = 0; i < 0x40; i++) {
int timer;
window_write16(vp, base + i, 0, Wn0EepromCmd);
for (timer = 10; timer >= 0; timer--) {
udelay(162);
if ((window_read16(vp, 0, Wn0EepromCmd) &
0x8000) == 0)
break;
}
eeprom[i] = window_read16(vp, 0, Wn0EepromData);
}
}
for (i = 0; i < 0x18; i++)
checksum ^= eeprom[i];
checksum = (checksum ^ (checksum >> 8)) & 0xff;
if (checksum != 0x00) {
while (i < 0x21)
checksum ^= eeprom[i++];
checksum = (checksum ^ (checksum >> 8)) & 0xff;
}
if ((checksum != 0x00) && !(vci->drv_flags & IS_TORNADO))
pr_cont(" ***INVALID CHECKSUM %4.4x*** ", checksum);
for (i = 0; i < 3; i++)
((__be16 *)dev->dev_addr)[i] = htons(eeprom[i + 10]);
if (print_info)
pr_cont(" %pM", dev->dev_addr);
if (!is_valid_ether_addr(dev->dev_addr)) {
retval = -EINVAL;
pr_err("*** EEPROM MAC address is invalid.\n");
goto free_ring;
}
for (i = 0; i < 6; i++)
window_write8(vp, dev->dev_addr[i], 2, i);
if (print_info)
pr_cont(", IRQ %d\n", dev->irq);
if (dev->irq <= 0 || dev->irq >= nr_irqs)
pr_warning(" *** Warning: IRQ %d is unlikely to work! ***\n",
dev->irq);
step = (window_read8(vp, 4, Wn4_NetDiag) & 0x1e) >> 1;
if (print_info) {
pr_info(" product code %02x%02x rev %02x.%d date %02d-%02d-%02d\n",
eeprom[6]&0xff, eeprom[6]>>8, eeprom[0x14],
step, (eeprom[4]>>5) & 15, eeprom[4] & 31, eeprom[4]>>9);
}
if (pdev && vci->drv_flags & HAS_CB_FNS) {
unsigned short n;
vp->cb_fn_base = pci_iomap(pdev, 2, 0);
if (!vp->cb_fn_base) {
retval = -ENOMEM;
goto free_ring;
}
if (print_info) {
pr_info("%s: CardBus functions mapped %16.16llx->%p\n",
print_name,
(unsigned long long)pci_resource_start(pdev, 2),
vp->cb_fn_base);
}
n = window_read16(vp, 2, Wn2_ResetOptions) & ~0x4010;
if (vp->drv_flags & INVERT_LED_PWR)
n |= 0x10;
if (vp->drv_flags & INVERT_MII_PWR)
n |= 0x4000;
window_write16(vp, n, 2, Wn2_ResetOptions);
if (vp->drv_flags & WNO_XCVR_PWR) {
window_write16(vp, 0x0800, 0, 0);
}
}
vp->info1 = eeprom[13];
vp->info2 = eeprom[15];
vp->capabilities = eeprom[16];
if (vp->info1 & 0x8000) {
vp->full_duplex = 1;
if (print_info)
pr_info("Full duplex capable\n");
}
{
static const char * const ram_split[] = {"5:3", "3:1", "1:1", "3:5"};
unsigned int config;
vp->available_media = window_read16(vp, 3, Wn3_Options);
if ((vp->available_media & 0xff) == 0)
vp->available_media = 0x40;
config = window_read32(vp, 3, Wn3_Config);
if (print_info) {
pr_debug(" Internal config register is %4.4x, transceivers %#x.\n",
config, window_read16(vp, 3, Wn3_Options));
pr_info(" %dK %s-wide RAM %s Rx:Tx split, %s%s interface.\n",
8 << RAM_SIZE(config),
RAM_WIDTH(config) ? "word" : "byte",
ram_split[RAM_SPLIT(config)],
AUTOSELECT(config) ? "autoselect/" : "",
XCVR(config) > XCVR_ExtMII ? "<invalid transceiver>" :
media_tbl[XCVR(config)].name);
}
vp->default_media = XCVR(config);
if (vp->default_media == XCVR_NWAY)
vp->has_nway = 1;
vp->autoselect = AUTOSELECT(config);
}
if (vp->media_override != 7) {
pr_info("%s: Media override to transceiver type %d (%s).\n",
print_name, vp->media_override,
media_tbl[vp->media_override].name);
dev->if_port = vp->media_override;
} else
dev->if_port = vp->default_media;
if ((vp->available_media & 0x40) || (vci->drv_flags & HAS_NWAY) ||
dev->if_port == XCVR_MII || dev->if_port == XCVR_NWAY) {
int phy, phy_idx = 0;
mii_preamble_required++;
if (vp->drv_flags & EXTRA_PREAMBLE)
mii_preamble_required++;
mdio_sync(vp, 32);
mdio_read(dev, 24, MII_BMSR);
for (phy = 0; phy < 32 && phy_idx < 1; phy++) {
int mii_status, phyx;
if (phy == 0)
phyx = 24;
else if (phy <= 24)
phyx = phy - 1;
else
phyx = phy;
mii_status = mdio_read(dev, phyx, MII_BMSR);
if (mii_status && mii_status != 0xffff) {
vp->phys[phy_idx++] = phyx;
if (print_info) {
pr_info(" MII transceiver found at address %d, status %4x.\n",
phyx, mii_status);
}
if ((mii_status & 0x0040) == 0)
mii_preamble_required++;
}
}
mii_preamble_required--;
if (phy_idx == 0) {
pr_warning(" ***WARNING*** No MII transceivers found!\n");
vp->phys[0] = 24;
} else {
vp->advertising = mdio_read(dev, vp->phys[0], MII_ADVERTISE);
if (vp->full_duplex) {
vp->advertising &= ~0x02A0;
mdio_write(dev, vp->phys[0], 4, vp->advertising);
}
}
vp->mii.phy_id = vp->phys[0];
}
if (vp->capabilities & CapBusMaster) {
vp->full_bus_master_tx = 1;
if (print_info) {
pr_info(" Enabling bus-master transmits and %s receives.\n",
(vp->info2 & 1) ? "early" : "whole-frame" );
}
vp->full_bus_master_rx = (vp->info2 & 1) ? 1 : 2;
vp->bus_master = 0;
}
if (vp->full_bus_master_tx) {
dev->netdev_ops = &boomrang_netdev_ops;
if (card_idx < MAX_UNITS &&
((hw_checksums[card_idx] == -1 && (vp->drv_flags & HAS_HWCKSM)) ||
hw_checksums[card_idx] == 1)) {
dev->features |= NETIF_F_IP_CSUM | NETIF_F_SG;
}
} else
dev->netdev_ops = &vortex_netdev_ops;
if (print_info) {
pr_info("%s: scatter/gather %sabled. h/w checksums %sabled\n",
print_name,
(dev->features & NETIF_F_SG) ? "en":"dis",
(dev->features & NETIF_F_IP_CSUM) ? "en":"dis");
}
dev->ethtool_ops = &vortex_ethtool_ops;
dev->watchdog_timeo = (watchdog * HZ) / 1000;
if (pdev) {
vp->pm_state_valid = 1;
pci_save_state(VORTEX_PCI(vp));
acpi_set_WOL(dev);
}
retval = register_netdev(dev);
if (retval == 0)
return 0;
free_ring:
pci_free_consistent(pdev,
sizeof(struct boom_rx_desc) * RX_RING_SIZE
+ sizeof(struct boom_tx_desc) * TX_RING_SIZE,
vp->rx_ring,
vp->rx_ring_dma);
free_region:
if (vp->must_free_region)
release_region(dev->base_addr, vci->io_size);
free_netdev(dev);
pr_err(PFX "vortex_probe1 fails. Returns %d\n", retval);
out:
return retval;
}
static void
issue_and_wait(struct net_device *dev, int cmd)
{
struct vortex_private *vp = netdev_priv(dev);
void __iomem *ioaddr = vp->ioaddr;
int i;
iowrite16(cmd, ioaddr + EL3_CMD);
for (i = 0; i < 2000; i++) {
if (!(ioread16(ioaddr + EL3_STATUS) & CmdInProgress))
return;
}
for (i = 0; i < 100000; i++) {
if (!(ioread16(ioaddr + EL3_STATUS) & CmdInProgress)) {
if (vortex_debug > 1)
pr_info("%s: command 0x%04x took %d usecs\n",
dev->name, cmd, i * 10);
return;
}
udelay(10);
}
pr_err("%s: command 0x%04x did not complete! Status=0x%x\n",
dev->name, cmd, ioread16(ioaddr + EL3_STATUS));
}
static void
vortex_set_duplex(struct net_device *dev)
{
struct vortex_private *vp = netdev_priv(dev);
pr_info("%s: setting %s-duplex.\n",
dev->name, (vp->full_duplex) ? "full" : "half");
window_write16(vp,
((vp->info1 & 0x8000) || vp->full_duplex ? 0x20 : 0) |
(vp->large_frames ? 0x40 : 0) |
((vp->full_duplex && vp->flow_ctrl && vp->partner_flow_ctrl) ?
0x100 : 0),
3, Wn3_MAC_Ctrl);
}
static void vortex_check_media(struct net_device *dev, unsigned int init)
{
struct vortex_private *vp = netdev_priv(dev);
unsigned int ok_to_print = 0;
if (vortex_debug > 3)
ok_to_print = 1;
if (mii_check_media(&vp->mii, ok_to_print, init)) {
vp->full_duplex = vp->mii.full_duplex;
vortex_set_duplex(dev);
} else if (init) {
vortex_set_duplex(dev);
}
}
static int
vortex_up(struct net_device *dev)
{
struct vortex_private *vp = netdev_priv(dev);
void __iomem *ioaddr = vp->ioaddr;
unsigned int config;
int i, mii_reg1, mii_reg5, err = 0;
if (VORTEX_PCI(vp)) {
pci_set_power_state(VORTEX_PCI(vp), PCI_D0);
if (vp->pm_state_valid)
pci_restore_state(VORTEX_PCI(vp));
err = pci_enable_device(VORTEX_PCI(vp));
if (err) {
pr_warning("%s: Could not enable device\n",
dev->name);
goto err_out;
}
}
config = window_read32(vp, 3, Wn3_Config);
if (vp->media_override != 7) {
pr_info("%s: Media override to transceiver %d (%s).\n",
dev->name, vp->media_override,
media_tbl[vp->media_override].name);
dev->if_port = vp->media_override;
} else if (vp->autoselect) {
if (vp->has_nway) {
if (vortex_debug > 1)
pr_info("%s: using NWAY device table, not %d\n",
dev->name, dev->if_port);
dev->if_port = XCVR_NWAY;
} else {
dev->if_port = XCVR_100baseTx;
while (! (vp->available_media & media_tbl[dev->if_port].mask))
dev->if_port = media_tbl[dev->if_port].next;
if (vortex_debug > 1)
pr_info("%s: first available media type: %s\n",
dev->name, media_tbl[dev->if_port].name);
}
} else {
dev->if_port = vp->default_media;
if (vortex_debug > 1)
pr_info("%s: using default media %s\n",
dev->name, media_tbl[dev->if_port].name);
}
init_timer(&vp->timer);
vp->timer.expires = RUN_AT(media_tbl[dev->if_port].wait);
vp->timer.data = (unsigned long)dev;
vp->timer.function = vortex_timer;
add_timer(&vp->timer);
init_timer(&vp->rx_oom_timer);
vp->rx_oom_timer.data = (unsigned long)dev;
vp->rx_oom_timer.function = rx_oom_timer;
if (vortex_debug > 1)
pr_debug("%s: Initial media type %s.\n",
dev->name, media_tbl[dev->if_port].name);
vp->full_duplex = vp->mii.force_media;
config = BFINS(config, dev->if_port, 20, 4);
if (vortex_debug > 6)
pr_debug("vortex_up(): writing 0x%x to InternalConfig\n", config);
window_write32(vp, config, 3, Wn3_Config);
if (dev->if_port == XCVR_MII || dev->if_port == XCVR_NWAY) {
mii_reg1 = mdio_read(dev, vp->phys[0], MII_BMSR);
mii_reg5 = mdio_read(dev, vp->phys[0], MII_LPA);
vp->partner_flow_ctrl = ((mii_reg5 & 0x0400) != 0);
vp->mii.full_duplex = vp->full_duplex;
vortex_check_media(dev, 1);
}
else
vortex_set_duplex(dev);
issue_and_wait(dev, TxReset);
issue_and_wait(dev, RxReset|0x04);
iowrite16(SetStatusEnb | 0x00, ioaddr + EL3_CMD);
if (vortex_debug > 1) {
pr_debug("%s: vortex_up() irq %d media status %4.4x.\n",
dev->name, dev->irq, window_read16(vp, 4, Wn4_Media));
}
for (i = 0; i < 6; i++)
window_write8(vp, dev->dev_addr[i], 2, i);
for (; i < 12; i+=2)
window_write16(vp, 0, 2, i);
if (vp->cb_fn_base) {
unsigned short n = window_read16(vp, 2, Wn2_ResetOptions) & ~0x4010;
if (vp->drv_flags & INVERT_LED_PWR)
n |= 0x10;
if (vp->drv_flags & INVERT_MII_PWR)
n |= 0x4000;
window_write16(vp, n, 2, Wn2_ResetOptions);
}
if (dev->if_port == XCVR_10base2)
iowrite16(StartCoax, ioaddr + EL3_CMD);
if (dev->if_port != XCVR_NWAY) {
window_write16(vp,
(window_read16(vp, 4, Wn4_Media) &
~(Media_10TP|Media_SQE)) |
media_tbl[dev->if_port].media_bits,
4, Wn4_Media);
}
iowrite16(StatsDisable, ioaddr + EL3_CMD);
for (i = 0; i < 10; i++)
window_read8(vp, 6, i);
window_read16(vp, 6, 10);
window_read16(vp, 6, 12);
window_read8(vp, 4, 12);
window_write16(vp, 0x0040, 4, Wn4_NetDiag);
if (vp->full_bus_master_rx) {
vp->cur_rx = vp->dirty_rx = 0;
iowrite16(SetRxThreshold + (1536>>2), ioaddr + EL3_CMD);
iowrite32(0x0020, ioaddr + PktStatus);
iowrite32(vp->rx_ring_dma, ioaddr + UpListPtr);
}
if (vp->full_bus_master_tx) {
vp->cur_tx = vp->dirty_tx = 0;
if (vp->drv_flags & IS_BOOMERANG)
iowrite8(PKT_BUF_SZ>>8, ioaddr + TxFreeThreshold);
for (i = 0; i < RX_RING_SIZE; i++)
vp->rx_ring[i].status = 0;
for (i = 0; i < TX_RING_SIZE; i++)
vp->tx_skbuff[i] = NULL;
iowrite32(0, ioaddr + DownListPtr);
}
set_rx_mode(dev);
set_8021q_mode(dev, 1);
iowrite16(StatsEnable, ioaddr + EL3_CMD);
iowrite16(RxEnable, ioaddr + EL3_CMD);
iowrite16(TxEnable, ioaddr + EL3_CMD);
vp->status_enable = SetStatusEnb | HostError|IntReq|StatsFull|TxComplete|
(vp->full_bus_master_tx ? DownComplete : TxAvailable) |
(vp->full_bus_master_rx ? UpComplete : RxComplete) |
(vp->bus_master ? DMADone : 0);
vp->intr_enable = SetIntrEnb | IntLatch | TxAvailable |
(vp->full_bus_master_rx ? 0 : RxComplete) |
StatsFull | HostError | TxComplete | IntReq
| (vp->bus_master ? DMADone : 0) | UpComplete | DownComplete;
iowrite16(vp->status_enable, ioaddr + EL3_CMD);
iowrite16(AckIntr | IntLatch | TxAvailable | RxEarly | IntReq,
ioaddr + EL3_CMD);
iowrite16(vp->intr_enable, ioaddr + EL3_CMD);
if (vp->cb_fn_base)
iowrite32(0x8000, vp->cb_fn_base + 4);
netif_start_queue (dev);
err_out:
return err;
}
static int
vortex_open(struct net_device *dev)
{
struct vortex_private *vp = netdev_priv(dev);
int i;
int retval;
if ((retval = request_irq(dev->irq, vp->full_bus_master_rx ?
boomerang_interrupt : vortex_interrupt, IRQF_SHARED, dev->name, dev))) {
pr_err("%s: Could not reserve IRQ %d\n", dev->name, dev->irq);
goto err;
}
if (vp->full_bus_master_rx) {
if (vortex_debug > 2)
pr_debug("%s: Filling in the Rx ring.\n", dev->name);
for (i = 0; i < RX_RING_SIZE; i++) {
struct sk_buff *skb;
vp->rx_ring[i].next = cpu_to_le32(vp->rx_ring_dma + sizeof(struct boom_rx_desc) * (i+1));
vp->rx_ring[i].status = 0;
vp->rx_ring[i].length = cpu_to_le32(PKT_BUF_SZ | LAST_FRAG);
skb = __netdev_alloc_skb(dev, PKT_BUF_SZ + NET_IP_ALIGN,
GFP_KERNEL);
vp->rx_skbuff[i] = skb;
if (skb == NULL)
break;
skb_reserve(skb, NET_IP_ALIGN);
vp->rx_ring[i].addr = cpu_to_le32(pci_map_single(VORTEX_PCI(vp), skb->data, PKT_BUF_SZ, PCI_DMA_FROMDEVICE));
}
if (i != RX_RING_SIZE) {
int j;
pr_emerg("%s: no memory for rx ring\n", dev->name);
for (j = 0; j < i; j++) {
if (vp->rx_skbuff[j]) {
dev_kfree_skb(vp->rx_skbuff[j]);
vp->rx_skbuff[j] = NULL;
}
}
retval = -ENOMEM;
goto err_free_irq;
}
vp->rx_ring[i-1].next = cpu_to_le32(vp->rx_ring_dma);
}
retval = vortex_up(dev);
if (!retval)
goto out;
err_free_irq:
free_irq(dev->irq, dev);
err:
if (vortex_debug > 1)
pr_err("%s: vortex_open() fails: returning %d\n", dev->name, retval);
out:
return retval;
}
static void
vortex_timer(unsigned long data)
{
struct net_device *dev = (struct net_device *)data;
struct vortex_private *vp = netdev_priv(dev);
void __iomem *ioaddr = vp->ioaddr;
int next_tick = 60*HZ;
int ok = 0;
int media_status;
if (vortex_debug > 2) {
pr_debug("%s: Media selection timer tick happened, %s.\n",
dev->name, media_tbl[dev->if_port].name);
pr_debug("dev->watchdog_timeo=%d\n", dev->watchdog_timeo);
}
media_status = window_read16(vp, 4, Wn4_Media);
switch (dev->if_port) {
case XCVR_10baseT: case XCVR_100baseTx: case XCVR_100baseFx:
if (media_status & Media_LnkBeat) {
netif_carrier_on(dev);
ok = 1;
if (vortex_debug > 1)
pr_debug("%s: Media %s has link beat, %x.\n",
dev->name, media_tbl[dev->if_port].name, media_status);
} else {
netif_carrier_off(dev);
if (vortex_debug > 1) {
pr_debug("%s: Media %s has no link beat, %x.\n",
dev->name, media_tbl[dev->if_port].name, media_status);
}
}
break;
case XCVR_MII: case XCVR_NWAY:
{
ok = 1;
vortex_check_media(dev, 0);
}
break;
default:
if (vortex_debug > 1)
pr_debug("%s: Media %s has no indication, %x.\n",
dev->name, media_tbl[dev->if_port].name, media_status);
ok = 1;
}
if (dev->flags & IFF_SLAVE || !netif_carrier_ok(dev))
next_tick = 5*HZ;
if (vp->medialock)
goto leave_media_alone;
if (!ok) {
unsigned int config;
spin_lock_irq(&vp->lock);
do {
dev->if_port = media_tbl[dev->if_port].next;
} while ( ! (vp->available_media & media_tbl[dev->if_port].mask));
if (dev->if_port == XCVR_Default) {
dev->if_port = vp->default_media;
if (vortex_debug > 1)
pr_debug("%s: Media selection failing, using default %s port.\n",
dev->name, media_tbl[dev->if_port].name);
} else {
if (vortex_debug > 1)
pr_debug("%s: Media selection failed, now trying %s port.\n",
dev->name, media_tbl[dev->if_port].name);
next_tick = media_tbl[dev->if_port].wait;
}
window_write16(vp,
(media_status & ~(Media_10TP|Media_SQE)) |
media_tbl[dev->if_port].media_bits,
4, Wn4_Media);
config = window_read32(vp, 3, Wn3_Config);
config = BFINS(config, dev->if_port, 20, 4);
window_write32(vp, config, 3, Wn3_Config);
iowrite16(dev->if_port == XCVR_10base2 ? StartCoax : StopCoax,
ioaddr + EL3_CMD);
if (vortex_debug > 1)
pr_debug("wrote 0x%08x to Wn3_Config\n", config);
spin_unlock_irq(&vp->lock);
}
leave_media_alone:
if (vortex_debug > 2)
pr_debug("%s: Media selection timer finished, %s.\n",
dev->name, media_tbl[dev->if_port].name);
mod_timer(&vp->timer, RUN_AT(next_tick));
if (vp->deferred)
iowrite16(FakeIntr, ioaddr + EL3_CMD);
}
static void vortex_tx_timeout(struct net_device *dev)
{
struct vortex_private *vp = netdev_priv(dev);
void __iomem *ioaddr = vp->ioaddr;
pr_err("%s: transmit timed out, tx_status %2.2x status %4.4x.\n",
dev->name, ioread8(ioaddr + TxStatus),
ioread16(ioaddr + EL3_STATUS));
pr_err(" diagnostics: net %04x media %04x dma %08x fifo %04x\n",
window_read16(vp, 4, Wn4_NetDiag),
window_read16(vp, 4, Wn4_Media),
ioread32(ioaddr + PktStatus),
window_read16(vp, 4, Wn4_FIFODiag));
if ((ioread8(ioaddr + TxStatus) & 0x88) == 0x88)
pr_err("%s: Transmitter encountered 16 collisions --"
" network cable problem?\n", dev->name);
if (ioread16(ioaddr + EL3_STATUS) & IntLatch) {
pr_err("%s: Interrupt posted but not delivered --"
" IRQ blocked by another device?\n", dev->name);
{
unsigned long flags;
local_irq_save(flags);
if (vp->full_bus_master_tx)
boomerang_interrupt(dev->irq, dev);
else
vortex_interrupt(dev->irq, dev);
local_irq_restore(flags);
}
}
if (vortex_debug > 0)
dump_tx_ring(dev);
issue_and_wait(dev, TxReset);
dev->stats.tx_errors++;
if (vp->full_bus_master_tx) {
pr_debug("%s: Resetting the Tx ring pointer.\n", dev->name);
if (vp->cur_tx - vp->dirty_tx > 0 && ioread32(ioaddr + DownListPtr) == 0)
iowrite32(vp->tx_ring_dma + (vp->dirty_tx % TX_RING_SIZE) * sizeof(struct boom_tx_desc),
ioaddr + DownListPtr);
if (vp->cur_tx - vp->dirty_tx < TX_RING_SIZE)
netif_wake_queue (dev);
if (vp->drv_flags & IS_BOOMERANG)
iowrite8(PKT_BUF_SZ>>8, ioaddr + TxFreeThreshold);
iowrite16(DownUnstall, ioaddr + EL3_CMD);
} else {
dev->stats.tx_dropped++;
netif_wake_queue(dev);
}
iowrite16(TxEnable, ioaddr + EL3_CMD);
dev->trans_start = jiffies;
}
static void
vortex_error(struct net_device *dev, int status)
{
struct vortex_private *vp = netdev_priv(dev);
void __iomem *ioaddr = vp->ioaddr;
int do_tx_reset = 0, reset_mask = 0;
unsigned char tx_status = 0;
if (vortex_debug > 2) {
pr_err("%s: vortex_error(), status=0x%x\n", dev->name, status);
}
if (status & TxComplete) {
tx_status = ioread8(ioaddr + TxStatus);
if (vortex_debug > 2 ||
(tx_status != 0x88 && vortex_debug > 0)) {
pr_err("%s: Transmit error, Tx status register %2.2x.\n",
dev->name, tx_status);
if (tx_status == 0x82) {
pr_err("Probably a duplex mismatch. See "
"Documentation/networking/vortex.txt\n");
}
dump_tx_ring(dev);
}
if (tx_status & 0x14) dev->stats.tx_fifo_errors++;
if (tx_status & 0x38) dev->stats.tx_aborted_errors++;
if (tx_status & 0x08) vp->xstats.tx_max_collisions++;
iowrite8(0, ioaddr + TxStatus);
if (tx_status & 0x30) {
do_tx_reset = 1;
} else if ((tx_status & 0x08) && (vp->drv_flags & MAX_COLLISION_RESET)) {
do_tx_reset = 1;
reset_mask = 0x0108;
} else {
iowrite16(TxEnable, ioaddr + EL3_CMD);
}
}
if (status & RxEarly)
iowrite16(AckIntr | RxEarly, ioaddr + EL3_CMD);
if (status & StatsFull) {
static int DoneDidThat;
if (vortex_debug > 4)
pr_debug("%s: Updating stats.\n", dev->name);
update_stats(ioaddr, dev);
if (DoneDidThat == 0 &&
ioread16(ioaddr + EL3_STATUS) & StatsFull) {
pr_warning("%s: Updating statistics failed, disabling "
"stats as an interrupt source.\n", dev->name);
iowrite16(SetIntrEnb |
(window_read16(vp, 5, 10) & ~StatsFull),
ioaddr + EL3_CMD);
vp->intr_enable &= ~StatsFull;
DoneDidThat++;
}
}
if (status & IntReq) {
iowrite16(vp->status_enable, ioaddr + EL3_CMD);
iowrite16(vp->intr_enable, ioaddr + EL3_CMD);
}
if (status & HostError) {
u16 fifo_diag;
fifo_diag = window_read16(vp, 4, Wn4_FIFODiag);
pr_err("%s: Host error, FIFO diagnostic register %4.4x.\n",
dev->name, fifo_diag);
if (vp->full_bus_master_tx) {
int bus_status = ioread32(ioaddr + PktStatus);
if (vortex_debug)
pr_err("%s: PCI bus error, bus status %8.8x\n", dev->name, bus_status);
vortex_down(dev, 0);
issue_and_wait(dev, TotalReset | 0xff);
vortex_up(dev);
} else if (fifo_diag & 0x0400)
do_tx_reset = 1;
if (fifo_diag & 0x3000) {
issue_and_wait(dev, RxReset|0x07);
set_rx_mode(dev);
set_8021q_mode(dev, 1);
iowrite16(RxEnable, ioaddr + EL3_CMD);
iowrite16(AckIntr | HostError, ioaddr + EL3_CMD);
}
}
if (do_tx_reset) {
issue_and_wait(dev, TxReset|reset_mask);
iowrite16(TxEnable, ioaddr + EL3_CMD);
if (!vp->full_bus_master_tx)
netif_wake_queue(dev);
}
}
static netdev_tx_t
vortex_start_xmit(struct sk_buff *skb, struct net_device *dev)
{
struct vortex_private *vp = netdev_priv(dev);
void __iomem *ioaddr = vp->ioaddr;
iowrite32(skb->len, ioaddr + TX_FIFO);
if (vp->bus_master) {
int len = (skb->len + 3) & ~3;
vp->tx_skb_dma = pci_map_single(VORTEX_PCI(vp), skb->data, len,
PCI_DMA_TODEVICE);
spin_lock_irq(&vp->window_lock);
window_set(vp, 7);
iowrite32(vp->tx_skb_dma, ioaddr + Wn7_MasterAddr);
iowrite16(len, ioaddr + Wn7_MasterLen);
spin_unlock_irq(&vp->window_lock);
vp->tx_skb = skb;
iowrite16(StartDMADown, ioaddr + EL3_CMD);
} else {
iowrite32_rep(ioaddr + TX_FIFO, skb->data, (skb->len + 3) >> 2);
dev_kfree_skb (skb);
if (ioread16(ioaddr + TxFree) > 1536) {
netif_start_queue (dev);
} else {
netif_stop_queue(dev);
iowrite16(SetTxThreshold + (1536>>2), ioaddr + EL3_CMD);
}
}
{
int tx_status;
int i = 32;
while (--i > 0 && (tx_status = ioread8(ioaddr + TxStatus)) > 0) {
if (tx_status & 0x3C) {
if (vortex_debug > 2)
pr_debug("%s: Tx error, status %2.2x.\n",
dev->name, tx_status);
if (tx_status & 0x04) dev->stats.tx_fifo_errors++;
if (tx_status & 0x38) dev->stats.tx_aborted_errors++;
if (tx_status & 0x30) {
issue_and_wait(dev, TxReset);
}
iowrite16(TxEnable, ioaddr + EL3_CMD);
}
iowrite8(0x00, ioaddr + TxStatus);
}
}
return NETDEV_TX_OK;
}
static netdev_tx_t
boomerang_start_xmit(struct sk_buff *skb, struct net_device *dev)
{
struct vortex_private *vp = netdev_priv(dev);
void __iomem *ioaddr = vp->ioaddr;
int entry = vp->cur_tx % TX_RING_SIZE;
struct boom_tx_desc *prev_entry = &vp->tx_ring[(vp->cur_tx-1) % TX_RING_SIZE];
unsigned long flags;
if (vortex_debug > 6) {
pr_debug("boomerang_start_xmit()\n");
pr_debug("%s: Trying to send a packet, Tx index %d.\n",
dev->name, vp->cur_tx);
}
if (vp->handling_irq)
return NETDEV_TX_BUSY;
if (vp->cur_tx - vp->dirty_tx >= TX_RING_SIZE) {
if (vortex_debug > 0)
pr_warning("%s: BUG! Tx Ring full, refusing to send buffer.\n",
dev->name);
netif_stop_queue(dev);
return NETDEV_TX_BUSY;
}
vp->tx_skbuff[entry] = skb;
vp->tx_ring[entry].next = 0;
#if DO_ZEROCOPY
if (skb->ip_summed != CHECKSUM_PARTIAL)
vp->tx_ring[entry].status = cpu_to_le32(skb->len | TxIntrUploaded);
else
vp->tx_ring[entry].status = cpu_to_le32(skb->len | TxIntrUploaded | AddTCPChksum | AddUDPChksum);
if (!skb_shinfo(skb)->nr_frags) {
vp->tx_ring[entry].frag[0].addr = cpu_to_le32(pci_map_single(VORTEX_PCI(vp), skb->data,
skb->len, PCI_DMA_TODEVICE));
vp->tx_ring[entry].frag[0].length = cpu_to_le32(skb->len | LAST_FRAG);
} else {
int i;
vp->tx_ring[entry].frag[0].addr = cpu_to_le32(pci_map_single(VORTEX_PCI(vp), skb->data,
skb_headlen(skb), PCI_DMA_TODEVICE));
vp->tx_ring[entry].frag[0].length = cpu_to_le32(skb_headlen(skb));
for (i = 0; i < skb_shinfo(skb)->nr_frags; i++) {
skb_frag_t *frag = &skb_shinfo(skb)->frags[i];
vp->tx_ring[entry].frag[i+1].addr =
cpu_to_le32(pci_map_single(
VORTEX_PCI(vp),
(void *)skb_frag_address(frag),
skb_frag_size(frag), PCI_DMA_TODEVICE));
if (i == skb_shinfo(skb)->nr_frags-1)
vp->tx_ring[entry].frag[i+1].length = cpu_to_le32(skb_frag_size(frag)|LAST_FRAG);
else
vp->tx_ring[entry].frag[i+1].length = cpu_to_le32(skb_frag_size(frag));
}
}
#else
vp->tx_ring[entry].addr = cpu_to_le32(pci_map_single(VORTEX_PCI(vp), skb->data, skb->len, PCI_DMA_TODEVICE));
vp->tx_ring[entry].length = cpu_to_le32(skb->len | LAST_FRAG);
vp->tx_ring[entry].status = cpu_to_le32(skb->len | TxIntrUploaded);
#endif
spin_lock_irqsave(&vp->lock, flags);
issue_and_wait(dev, DownStall);
prev_entry->next = cpu_to_le32(vp->tx_ring_dma + entry * sizeof(struct boom_tx_desc));
if (ioread32(ioaddr + DownListPtr) == 0) {
iowrite32(vp->tx_ring_dma + entry * sizeof(struct boom_tx_desc), ioaddr + DownListPtr);
vp->queued_packet++;
}
vp->cur_tx++;
if (vp->cur_tx - vp->dirty_tx > TX_RING_SIZE - 1) {
netif_stop_queue (dev);
} else {
#if defined(tx_interrupt_mitigation)
prev_entry->status &= cpu_to_le32(~TxIntrUploaded);
#endif
}
iowrite16(DownUnstall, ioaddr + EL3_CMD);
spin_unlock_irqrestore(&vp->lock, flags);
return NETDEV_TX_OK;
}
static irqreturn_t
vortex_interrupt(int irq, void *dev_id)
{
struct net_device *dev = dev_id;
struct vortex_private *vp = netdev_priv(dev);
void __iomem *ioaddr;
int status;
int work_done = max_interrupt_work;
int handled = 0;
ioaddr = vp->ioaddr;
spin_lock(&vp->lock);
status = ioread16(ioaddr + EL3_STATUS);
if (vortex_debug > 6)
pr_debug("vortex_interrupt(). status=0x%4x\n", status);
if ((status & IntLatch) == 0)
goto handler_exit;
handled = 1;
if (status & IntReq) {
status |= vp->deferred;
vp->deferred = 0;
}
if (status == 0xffff)
goto handler_exit;
if (vortex_debug > 4)
pr_debug("%s: interrupt, status %4.4x, latency %d ticks.\n",
dev->name, status, ioread8(ioaddr + Timer));
spin_lock(&vp->window_lock);
window_set(vp, 7);
do {
if (vortex_debug > 5)
pr_debug("%s: In interrupt loop, status %4.4x.\n",
dev->name, status);
if (status & RxComplete)
vortex_rx(dev);
if (status & TxAvailable) {
if (vortex_debug > 5)
pr_debug(" TX room bit was handled.\n");
iowrite16(AckIntr | TxAvailable, ioaddr + EL3_CMD);
netif_wake_queue (dev);
}
if (status & DMADone) {
if (ioread16(ioaddr + Wn7_MasterStatus) & 0x1000) {
iowrite16(0x1000, ioaddr + Wn7_MasterStatus);
pci_unmap_single(VORTEX_PCI(vp), vp->tx_skb_dma, (vp->tx_skb->len + 3) & ~3, PCI_DMA_TODEVICE);
dev_kfree_skb_irq(vp->tx_skb);
if (ioread16(ioaddr + TxFree) > 1536) {
netif_wake_queue(dev);
} else {
iowrite16(SetTxThreshold + (1536>>2), ioaddr + EL3_CMD);
netif_stop_queue(dev);
}
}
}
if (status & (HostError | RxEarly | StatsFull | TxComplete | IntReq)) {
if (status == 0xffff)
break;
if (status & RxEarly)
vortex_rx(dev);
spin_unlock(&vp->window_lock);
vortex_error(dev, status);
spin_lock(&vp->window_lock);
window_set(vp, 7);
}
if (--work_done < 0) {
pr_warning("%s: Too much work in interrupt, status %4.4x.\n",
dev->name, status);
do {
vp->deferred |= status;
iowrite16(SetStatusEnb | (~vp->deferred & vp->status_enable),
ioaddr + EL3_CMD);
iowrite16(AckIntr | (vp->deferred & 0x7ff), ioaddr + EL3_CMD);
} while ((status = ioread16(ioaddr + EL3_CMD)) & IntLatch);
mod_timer(&vp->timer, jiffies + 1*HZ);
break;
}
iowrite16(AckIntr | IntReq | IntLatch, ioaddr + EL3_CMD);
} while ((status = ioread16(ioaddr + EL3_STATUS)) & (IntLatch | RxComplete));
spin_unlock(&vp->window_lock);
if (vortex_debug > 4)
pr_debug("%s: exiting interrupt, status %4.4x.\n",
dev->name, status);
handler_exit:
spin_unlock(&vp->lock);
return IRQ_RETVAL(handled);
}
static irqreturn_t
boomerang_interrupt(int irq, void *dev_id)
{
struct net_device *dev = dev_id;
struct vortex_private *vp = netdev_priv(dev);
void __iomem *ioaddr;
int status;
int work_done = max_interrupt_work;
ioaddr = vp->ioaddr;
spin_lock(&vp->lock);
vp->handling_irq = 1;
status = ioread16(ioaddr + EL3_STATUS);
if (vortex_debug > 6)
pr_debug("boomerang_interrupt. status=0x%4x\n", status);
if ((status & IntLatch) == 0)
goto handler_exit;
if (status == 0xffff) {
if (vortex_debug > 1)
pr_debug("boomerang_interrupt(1): status = 0xffff\n");
goto handler_exit;
}
if (status & IntReq) {
status |= vp->deferred;
vp->deferred = 0;
}
if (vortex_debug > 4)
pr_debug("%s: interrupt, status %4.4x, latency %d ticks.\n",
dev->name, status, ioread8(ioaddr + Timer));
do {
if (vortex_debug > 5)
pr_debug("%s: In interrupt loop, status %4.4x.\n",
dev->name, status);
if (status & UpComplete) {
iowrite16(AckIntr | UpComplete, ioaddr + EL3_CMD);
if (vortex_debug > 5)
pr_debug("boomerang_interrupt->boomerang_rx\n");
boomerang_rx(dev);
}
if (status & DownComplete) {
unsigned int dirty_tx = vp->dirty_tx;
iowrite16(AckIntr | DownComplete, ioaddr + EL3_CMD);
while (vp->cur_tx - dirty_tx > 0) {
int entry = dirty_tx % TX_RING_SIZE;
#if 1
if (ioread32(ioaddr + DownListPtr) ==
vp->tx_ring_dma + entry * sizeof(struct boom_tx_desc))
break;
#else
if ((vp->tx_ring[entry].status & DN_COMPLETE) == 0)
break;
#endif
if (vp->tx_skbuff[entry]) {
struct sk_buff *skb = vp->tx_skbuff[entry];
#if DO_ZEROCOPY
int i;
for (i=0; i<=skb_shinfo(skb)->nr_frags; i++)
pci_unmap_single(VORTEX_PCI(vp),
le32_to_cpu(vp->tx_ring[entry].frag[i].addr),
le32_to_cpu(vp->tx_ring[entry].frag[i].length)&0xFFF,
PCI_DMA_TODEVICE);
#else
pci_unmap_single(VORTEX_PCI(vp),
le32_to_cpu(vp->tx_ring[entry].addr), skb->len, PCI_DMA_TODEVICE);
#endif
dev_kfree_skb_irq(skb);
vp->tx_skbuff[entry] = NULL;
} else {
pr_debug("boomerang_interrupt: no skb!\n");
}
dirty_tx++;
}
vp->dirty_tx = dirty_tx;
if (vp->cur_tx - dirty_tx <= TX_RING_SIZE - 1) {
if (vortex_debug > 6)
pr_debug("boomerang_interrupt: wake queue\n");
netif_wake_queue (dev);
}
}
if (status & (HostError | RxEarly | StatsFull | TxComplete | IntReq))
vortex_error(dev, status);
if (--work_done < 0) {
pr_warning("%s: Too much work in interrupt, status %4.4x.\n",
dev->name, status);
do {
vp->deferred |= status;
iowrite16(SetStatusEnb | (~vp->deferred & vp->status_enable),
ioaddr + EL3_CMD);
iowrite16(AckIntr | (vp->deferred & 0x7ff), ioaddr + EL3_CMD);
} while ((status = ioread16(ioaddr + EL3_CMD)) & IntLatch);
mod_timer(&vp->timer, jiffies + 1*HZ);
break;
}
iowrite16(AckIntr | IntReq | IntLatch, ioaddr + EL3_CMD);
if (vp->cb_fn_base)
iowrite32(0x8000, vp->cb_fn_base + 4);
} while ((status = ioread16(ioaddr + EL3_STATUS)) & IntLatch);
if (vortex_debug > 4)
pr_debug("%s: exiting interrupt, status %4.4x.\n",
dev->name, status);
handler_exit:
vp->handling_irq = 0;
spin_unlock(&vp->lock);
return IRQ_HANDLED;
}
static int vortex_rx(struct net_device *dev)
{
struct vortex_private *vp = netdev_priv(dev);
void __iomem *ioaddr = vp->ioaddr;
int i;
short rx_status;
if (vortex_debug > 5)
pr_debug("vortex_rx(): status %4.4x, rx_status %4.4x.\n",
ioread16(ioaddr+EL3_STATUS), ioread16(ioaddr+RxStatus));
while ((rx_status = ioread16(ioaddr + RxStatus)) > 0) {
if (rx_status & 0x4000) {
unsigned char rx_error = ioread8(ioaddr + RxErrors);
if (vortex_debug > 2)
pr_debug(" Rx error: status %2.2x.\n", rx_error);
dev->stats.rx_errors++;
if (rx_error & 0x01) dev->stats.rx_over_errors++;
if (rx_error & 0x02) dev->stats.rx_length_errors++;
if (rx_error & 0x04) dev->stats.rx_frame_errors++;
if (rx_error & 0x08) dev->stats.rx_crc_errors++;
if (rx_error & 0x10) dev->stats.rx_length_errors++;
} else {
int pkt_len = rx_status & 0x1fff;
struct sk_buff *skb;
skb = netdev_alloc_skb(dev, pkt_len + 5);
if (vortex_debug > 4)
pr_debug("Receiving packet size %d status %4.4x.\n",
pkt_len, rx_status);
if (skb != NULL) {
skb_reserve(skb, 2);
if (vp->bus_master &&
! (ioread16(ioaddr + Wn7_MasterStatus) & 0x8000)) {
dma_addr_t dma = pci_map_single(VORTEX_PCI(vp), skb_put(skb, pkt_len),
pkt_len, PCI_DMA_FROMDEVICE);
iowrite32(dma, ioaddr + Wn7_MasterAddr);
iowrite16((skb->len + 3) & ~3, ioaddr + Wn7_MasterLen);
iowrite16(StartDMAUp, ioaddr + EL3_CMD);
while (ioread16(ioaddr + Wn7_MasterStatus) & 0x8000)
;
pci_unmap_single(VORTEX_PCI(vp), dma, pkt_len, PCI_DMA_FROMDEVICE);
} else {
ioread32_rep(ioaddr + RX_FIFO,
skb_put(skb, pkt_len),
(pkt_len + 3) >> 2);
}
iowrite16(RxDiscard, ioaddr + EL3_CMD);
skb->protocol = eth_type_trans(skb, dev);
netif_rx(skb);
dev->stats.rx_packets++;
for (i = 200; i >= 0; i--)
if ( ! (ioread16(ioaddr + EL3_STATUS) & CmdInProgress))
break;
continue;
} else if (vortex_debug > 0)
pr_notice("%s: No memory to allocate a sk_buff of size %d.\n",
dev->name, pkt_len);
dev->stats.rx_dropped++;
}
issue_and_wait(dev, RxDiscard);
}
return 0;
}
static int
boomerang_rx(struct net_device *dev)
{
struct vortex_private *vp = netdev_priv(dev);
int entry = vp->cur_rx % RX_RING_SIZE;
void __iomem *ioaddr = vp->ioaddr;
int rx_status;
int rx_work_limit = vp->dirty_rx + RX_RING_SIZE - vp->cur_rx;
if (vortex_debug > 5)
pr_debug("boomerang_rx(): status %4.4x\n", ioread16(ioaddr+EL3_STATUS));
while ((rx_status = le32_to_cpu(vp->rx_ring[entry].status)) & RxDComplete){
if (--rx_work_limit < 0)
break;
if (rx_status & RxDError) {
unsigned char rx_error = rx_status >> 16;
if (vortex_debug > 2)
pr_debug(" Rx error: status %2.2x.\n", rx_error);
dev->stats.rx_errors++;
if (rx_error & 0x01) dev->stats.rx_over_errors++;
if (rx_error & 0x02) dev->stats.rx_length_errors++;
if (rx_error & 0x04) dev->stats.rx_frame_errors++;
if (rx_error & 0x08) dev->stats.rx_crc_errors++;
if (rx_error & 0x10) dev->stats.rx_length_errors++;
} else {
int pkt_len = rx_status & 0x1fff;
struct sk_buff *skb;
dma_addr_t dma = le32_to_cpu(vp->rx_ring[entry].addr);
if (vortex_debug > 4)
pr_debug("Receiving packet size %d status %4.4x.\n",
pkt_len, rx_status);
if (pkt_len < rx_copybreak &&
(skb = netdev_alloc_skb(dev, pkt_len + 2)) != NULL) {
skb_reserve(skb, 2);
pci_dma_sync_single_for_cpu(VORTEX_PCI(vp), dma, PKT_BUF_SZ, PCI_DMA_FROMDEVICE);
memcpy(skb_put(skb, pkt_len),
vp->rx_skbuff[entry]->data,
pkt_len);
pci_dma_sync_single_for_device(VORTEX_PCI(vp), dma, PKT_BUF_SZ, PCI_DMA_FROMDEVICE);
vp->rx_copy++;
} else {
skb = vp->rx_skbuff[entry];
vp->rx_skbuff[entry] = NULL;
skb_put(skb, pkt_len);
pci_unmap_single(VORTEX_PCI(vp), dma, PKT_BUF_SZ, PCI_DMA_FROMDEVICE);
vp->rx_nocopy++;
}
skb->protocol = eth_type_trans(skb, dev);
{
int csum_bits = rx_status & 0xee000000;
if (csum_bits &&
(csum_bits == (IPChksumValid | TCPChksumValid) ||
csum_bits == (IPChksumValid | UDPChksumValid))) {
skb->ip_summed = CHECKSUM_UNNECESSARY;
vp->rx_csumhits++;
}
}
netif_rx(skb);
dev->stats.rx_packets++;
}
entry = (++vp->cur_rx) % RX_RING_SIZE;
}
for (; vp->cur_rx - vp->dirty_rx > 0; vp->dirty_rx++) {
struct sk_buff *skb;
entry = vp->dirty_rx % RX_RING_SIZE;
if (vp->rx_skbuff[entry] == NULL) {
skb = netdev_alloc_skb_ip_align(dev, PKT_BUF_SZ);
if (skb == NULL) {
static unsigned long last_jif;
if (time_after(jiffies, last_jif + 10 * HZ)) {
pr_warning("%s: memory shortage\n", dev->name);
last_jif = jiffies;
}
if ((vp->cur_rx - vp->dirty_rx) == RX_RING_SIZE)
mod_timer(&vp->rx_oom_timer, RUN_AT(HZ * 1));
break;
}
vp->rx_ring[entry].addr = cpu_to_le32(pci_map_single(VORTEX_PCI(vp), skb->data, PKT_BUF_SZ, PCI_DMA_FROMDEVICE));
vp->rx_skbuff[entry] = skb;
}
vp->rx_ring[entry].status = 0;
iowrite16(UpUnstall, ioaddr + EL3_CMD);
}
return 0;
}
static void
rx_oom_timer(unsigned long arg)
{
struct net_device *dev = (struct net_device *)arg;
struct vortex_private *vp = netdev_priv(dev);
spin_lock_irq(&vp->lock);
if ((vp->cur_rx - vp->dirty_rx) == RX_RING_SIZE)
boomerang_rx(dev);
if (vortex_debug > 1) {
pr_debug("%s: rx_oom_timer %s\n", dev->name,
((vp->cur_rx - vp->dirty_rx) != RX_RING_SIZE) ? "succeeded" : "retrying");
}
spin_unlock_irq(&vp->lock);
}
static void
vortex_down(struct net_device *dev, int final_down)
{
struct vortex_private *vp = netdev_priv(dev);
void __iomem *ioaddr = vp->ioaddr;
netif_stop_queue (dev);
del_timer_sync(&vp->rx_oom_timer);
del_timer_sync(&vp->timer);
iowrite16(StatsDisable, ioaddr + EL3_CMD);
iowrite16(RxDisable, ioaddr + EL3_CMD);
iowrite16(TxDisable, ioaddr + EL3_CMD);
set_8021q_mode(dev, 0);
if (dev->if_port == XCVR_10base2)
iowrite16(StopCoax, ioaddr + EL3_CMD);
iowrite16(SetIntrEnb | 0x0000, ioaddr + EL3_CMD);
update_stats(ioaddr, dev);
if (vp->full_bus_master_rx)
iowrite32(0, ioaddr + UpListPtr);
if (vp->full_bus_master_tx)
iowrite32(0, ioaddr + DownListPtr);
if (final_down && VORTEX_PCI(vp)) {
vp->pm_state_valid = 1;
pci_save_state(VORTEX_PCI(vp));
acpi_set_WOL(dev);
}
}
static int
vortex_close(struct net_device *dev)
{
struct vortex_private *vp = netdev_priv(dev);
void __iomem *ioaddr = vp->ioaddr;
int i;
if (netif_device_present(dev))
vortex_down(dev, 1);
if (vortex_debug > 1) {
pr_debug("%s: vortex_close() status %4.4x, Tx status %2.2x.\n",
dev->name, ioread16(ioaddr + EL3_STATUS), ioread8(ioaddr + TxStatus));
pr_debug("%s: vortex close stats: rx_nocopy %d rx_copy %d"
" tx_queued %d Rx pre-checksummed %d.\n",
dev->name, vp->rx_nocopy, vp->rx_copy, vp->queued_packet, vp->rx_csumhits);
}
#if DO_ZEROCOPY
if (vp->rx_csumhits &&
(vp->drv_flags & HAS_HWCKSM) == 0 &&
(vp->card_idx >= MAX_UNITS || hw_checksums[vp->card_idx] == -1)) {
pr_warning("%s supports hardware checksums, and we're not using them!\n", dev->name);
}
#endif
free_irq(dev->irq, dev);
if (vp->full_bus_master_rx) {
for (i = 0; i < RX_RING_SIZE; i++)
if (vp->rx_skbuff[i]) {
pci_unmap_single( VORTEX_PCI(vp), le32_to_cpu(vp->rx_ring[i].addr),
PKT_BUF_SZ, PCI_DMA_FROMDEVICE);
dev_kfree_skb(vp->rx_skbuff[i]);
vp->rx_skbuff[i] = NULL;
}
}
if (vp->full_bus_master_tx) {
for (i = 0; i < TX_RING_SIZE; i++) {
if (vp->tx_skbuff[i]) {
struct sk_buff *skb = vp->tx_skbuff[i];
#if DO_ZEROCOPY
int k;
for (k=0; k<=skb_shinfo(skb)->nr_frags; k++)
pci_unmap_single(VORTEX_PCI(vp),
le32_to_cpu(vp->tx_ring[i].frag[k].addr),
le32_to_cpu(vp->tx_ring[i].frag[k].length)&0xFFF,
PCI_DMA_TODEVICE);
#else
pci_unmap_single(VORTEX_PCI(vp), le32_to_cpu(vp->tx_ring[i].addr), skb->len, PCI_DMA_TODEVICE);
#endif
dev_kfree_skb(skb);
vp->tx_skbuff[i] = NULL;
}
}
}
return 0;
}
static void
dump_tx_ring(struct net_device *dev)
{
if (vortex_debug > 0) {
struct vortex_private *vp = netdev_priv(dev);
void __iomem *ioaddr = vp->ioaddr;
if (vp->full_bus_master_tx) {
int i;
int stalled = ioread32(ioaddr + PktStatus) & 0x04;
pr_err(" Flags; bus-master %d, dirty %d(%d) current %d(%d)\n",
vp->full_bus_master_tx,
vp->dirty_tx, vp->dirty_tx % TX_RING_SIZE,
vp->cur_tx, vp->cur_tx % TX_RING_SIZE);
pr_err(" Transmit list %8.8x vs. %p.\n",
ioread32(ioaddr + DownListPtr),
&vp->tx_ring[vp->dirty_tx % TX_RING_SIZE]);
issue_and_wait(dev, DownStall);
for (i = 0; i < TX_RING_SIZE; i++) {
unsigned int length;
#if DO_ZEROCOPY
length = le32_to_cpu(vp->tx_ring[i].frag[0].length);
#else
length = le32_to_cpu(vp->tx_ring[i].length);
#endif
pr_err(" %d: @%p length %8.8x status %8.8x\n",
i, &vp->tx_ring[i], length,
le32_to_cpu(vp->tx_ring[i].status));
}
if (!stalled)
iowrite16(DownUnstall, ioaddr + EL3_CMD);
}
}
}
static struct net_device_stats *vortex_get_stats(struct net_device *dev)
{
struct vortex_private *vp = netdev_priv(dev);
void __iomem *ioaddr = vp->ioaddr;
unsigned long flags;
if (netif_device_present(dev)) {
spin_lock_irqsave (&vp->lock, flags);
update_stats(ioaddr, dev);
spin_unlock_irqrestore (&vp->lock, flags);
}
return &dev->stats;
}
static void update_stats(void __iomem *ioaddr, struct net_device *dev)
{
struct vortex_private *vp = netdev_priv(dev);
dev->stats.tx_carrier_errors += window_read8(vp, 6, 0);
dev->stats.tx_heartbeat_errors += window_read8(vp, 6, 1);
dev->stats.tx_window_errors += window_read8(vp, 6, 4);
dev->stats.rx_fifo_errors += window_read8(vp, 6, 5);
dev->stats.tx_packets += window_read8(vp, 6, 6);
dev->stats.tx_packets += (window_read8(vp, 6, 9) &
0x30) << 4;
window_read8(vp, 6, 7);
dev->stats.rx_bytes += window_read16(vp, 6, 10);
dev->stats.tx_bytes += window_read16(vp, 6, 12);
vp->xstats.tx_multiple_collisions += window_read8(vp, 6, 2);
vp->xstats.tx_single_collisions += window_read8(vp, 6, 3);
vp->xstats.tx_deferred += window_read8(vp, 6, 8);
vp->xstats.rx_bad_ssd += window_read8(vp, 4, 12);
dev->stats.collisions = vp->xstats.tx_multiple_collisions
+ vp->xstats.tx_single_collisions
+ vp->xstats.tx_max_collisions;
{
u8 up = window_read8(vp, 4, 13);
dev->stats.rx_bytes += (up & 0x0f) << 16;
dev->stats.tx_bytes += (up & 0xf0) << 12;
}
}
static int vortex_nway_reset(struct net_device *dev)
{
struct vortex_private *vp = netdev_priv(dev);
return mii_nway_restart(&vp->mii);
}
static int vortex_get_settings(struct net_device *dev, struct ethtool_cmd *cmd)
{
struct vortex_private *vp = netdev_priv(dev);
return mii_ethtool_gset(&vp->mii, cmd);
}
static int vortex_set_settings(struct net_device *dev, struct ethtool_cmd *cmd)
{
struct vortex_private *vp = netdev_priv(dev);
return mii_ethtool_sset(&vp->mii, cmd);
}
static u32 vortex_get_msglevel(struct net_device *dev)
{
return vortex_debug;
}
static void vortex_set_msglevel(struct net_device *dev, u32 dbg)
{
vortex_debug = dbg;
}
static int vortex_get_sset_count(struct net_device *dev, int sset)
{
switch (sset) {
case ETH_SS_STATS:
return VORTEX_NUM_STATS;
default:
return -EOPNOTSUPP;
}
}
static void vortex_get_ethtool_stats(struct net_device *dev,
struct ethtool_stats *stats, u64 *data)
{
struct vortex_private *vp = netdev_priv(dev);
void __iomem *ioaddr = vp->ioaddr;
unsigned long flags;
spin_lock_irqsave(&vp->lock, flags);
update_stats(ioaddr, dev);
spin_unlock_irqrestore(&vp->lock, flags);
data[0] = vp->xstats.tx_deferred;
data[1] = vp->xstats.tx_max_collisions;
data[2] = vp->xstats.tx_multiple_collisions;
data[3] = vp->xstats.tx_single_collisions;
data[4] = vp->xstats.rx_bad_ssd;
}
static void vortex_get_strings(struct net_device *dev, u32 stringset, u8 *data)
{
switch (stringset) {
case ETH_SS_STATS:
memcpy(data, &ethtool_stats_keys, sizeof(ethtool_stats_keys));
break;
default:
WARN_ON(1);
break;
}
}
static void vortex_get_drvinfo(struct net_device *dev,
struct ethtool_drvinfo *info)
{
struct vortex_private *vp = netdev_priv(dev);
strlcpy(info->driver, DRV_NAME, sizeof(info->driver));
if (VORTEX_PCI(vp)) {
strlcpy(info->bus_info, pci_name(VORTEX_PCI(vp)),
sizeof(info->bus_info));
} else {
if (VORTEX_EISA(vp))
strlcpy(info->bus_info, dev_name(vp->gendev),
sizeof(info->bus_info));
else
snprintf(info->bus_info, sizeof(info->bus_info),
"EISA 0x%lx %d", dev->base_addr, dev->irq);
}
}
static void vortex_get_wol(struct net_device *dev, struct ethtool_wolinfo *wol)
{
struct vortex_private *vp = netdev_priv(dev);
if (!VORTEX_PCI(vp))
return;
wol->supported = WAKE_MAGIC;
wol->wolopts = 0;
if (vp->enable_wol)
wol->wolopts |= WAKE_MAGIC;
}
static int vortex_set_wol(struct net_device *dev, struct ethtool_wolinfo *wol)
{
struct vortex_private *vp = netdev_priv(dev);
if (!VORTEX_PCI(vp))
return -EOPNOTSUPP;
if (wol->wolopts & ~WAKE_MAGIC)
return -EINVAL;
if (wol->wolopts & WAKE_MAGIC)
vp->enable_wol = 1;
else
vp->enable_wol = 0;
acpi_set_WOL(dev);
return 0;
}
static int vortex_ioctl(struct net_device *dev, struct ifreq *rq, int cmd)
{
int err;
struct vortex_private *vp = netdev_priv(dev);
pci_power_t state = 0;
if(VORTEX_PCI(vp))
state = VORTEX_PCI(vp)->current_state;
if(state != 0)
pci_set_power_state(VORTEX_PCI(vp), PCI_D0);
err = generic_mii_ioctl(&vp->mii, if_mii(rq), cmd, NULL);
if(state != 0)
pci_set_power_state(VORTEX_PCI(vp), state);
return err;
}
static void set_rx_mode(struct net_device *dev)
{
struct vortex_private *vp = netdev_priv(dev);
void __iomem *ioaddr = vp->ioaddr;
int new_mode;
if (dev->flags & IFF_PROMISC) {
if (vortex_debug > 3)
pr_notice("%s: Setting promiscuous mode.\n", dev->name);
new_mode = SetRxFilter|RxStation|RxMulticast|RxBroadcast|RxProm;
} else if (!netdev_mc_empty(dev) || dev->flags & IFF_ALLMULTI) {
new_mode = SetRxFilter|RxStation|RxMulticast|RxBroadcast;
} else
new_mode = SetRxFilter | RxStation | RxBroadcast;
iowrite16(new_mode, ioaddr + EL3_CMD);
}
static void set_8021q_mode(struct net_device *dev, int enable)
{
struct vortex_private *vp = netdev_priv(dev);
int mac_ctrl;
if ((vp->drv_flags&IS_CYCLONE) || (vp->drv_flags&IS_TORNADO)) {
int max_pkt_size = dev->mtu+14;
if (enable)
max_pkt_size += 4;
window_write16(vp, max_pkt_size, 3, Wn3_MaxPktSize);
window_write16(vp, VLAN_ETHER_TYPE, 7, Wn7_VlanEtherType);
} else {
vp->large_frames = dev->mtu > 1500 || enable;
mac_ctrl = window_read16(vp, 3, Wn3_MAC_Ctrl);
if (vp->large_frames)
mac_ctrl |= 0x40;
else
mac_ctrl &= ~0x40;
window_write16(vp, mac_ctrl, 3, Wn3_MAC_Ctrl);
}
}
static void set_8021q_mode(struct net_device *dev, int enable)
{
}
static void mdio_delay(struct vortex_private *vp)
{
window_read32(vp, 4, Wn4_PhysicalMgmt);
}
static void mdio_sync(struct vortex_private *vp, int bits)
{
while (-- bits >= 0) {
window_write16(vp, MDIO_DATA_WRITE1, 4, Wn4_PhysicalMgmt);
mdio_delay(vp);
window_write16(vp, MDIO_DATA_WRITE1 | MDIO_SHIFT_CLK,
4, Wn4_PhysicalMgmt);
mdio_delay(vp);
}
}
static int mdio_read(struct net_device *dev, int phy_id, int location)
{
int i;
struct vortex_private *vp = netdev_priv(dev);
int read_cmd = (0xf6 << 10) | (phy_id << 5) | location;
unsigned int retval = 0;
spin_lock_bh(&vp->mii_lock);
if (mii_preamble_required)
mdio_sync(vp, 32);
for (i = 14; i >= 0; i--) {
int dataval = (read_cmd&(1<<i)) ? MDIO_DATA_WRITE1 : MDIO_DATA_WRITE0;
window_write16(vp, dataval, 4, Wn4_PhysicalMgmt);
mdio_delay(vp);
window_write16(vp, dataval | MDIO_SHIFT_CLK,
4, Wn4_PhysicalMgmt);
mdio_delay(vp);
}
for (i = 19; i > 0; i--) {
window_write16(vp, MDIO_ENB_IN, 4, Wn4_PhysicalMgmt);
mdio_delay(vp);
retval = (retval << 1) |
((window_read16(vp, 4, Wn4_PhysicalMgmt) &
MDIO_DATA_READ) ? 1 : 0);
window_write16(vp, MDIO_ENB_IN | MDIO_SHIFT_CLK,
4, Wn4_PhysicalMgmt);
mdio_delay(vp);
}
spin_unlock_bh(&vp->mii_lock);
return retval & 0x20000 ? 0xffff : retval>>1 & 0xffff;
}
static void mdio_write(struct net_device *dev, int phy_id, int location, int value)
{
struct vortex_private *vp = netdev_priv(dev);
int write_cmd = 0x50020000 | (phy_id << 23) | (location << 18) | value;
int i;
spin_lock_bh(&vp->mii_lock);
if (mii_preamble_required)
mdio_sync(vp, 32);
for (i = 31; i >= 0; i--) {
int dataval = (write_cmd&(1<<i)) ? MDIO_DATA_WRITE1 : MDIO_DATA_WRITE0;
window_write16(vp, dataval, 4, Wn4_PhysicalMgmt);
mdio_delay(vp);
window_write16(vp, dataval | MDIO_SHIFT_CLK,
4, Wn4_PhysicalMgmt);
mdio_delay(vp);
}
for (i = 1; i >= 0; i--) {
window_write16(vp, MDIO_ENB_IN, 4, Wn4_PhysicalMgmt);
mdio_delay(vp);
window_write16(vp, MDIO_ENB_IN | MDIO_SHIFT_CLK,
4, Wn4_PhysicalMgmt);
mdio_delay(vp);
}
spin_unlock_bh(&vp->mii_lock);
}
static void acpi_set_WOL(struct net_device *dev)
{
struct vortex_private *vp = netdev_priv(dev);
void __iomem *ioaddr = vp->ioaddr;
device_set_wakeup_enable(vp->gendev, vp->enable_wol);
if (vp->enable_wol) {
window_write16(vp, 2, 7, 0x0c);
iowrite16(SetRxFilter|RxStation|RxMulticast|RxBroadcast, ioaddr + EL3_CMD);
iowrite16(RxEnable, ioaddr + EL3_CMD);
if (pci_enable_wake(VORTEX_PCI(vp), PCI_D3hot, 1)) {
pr_info("%s: WOL not supported.\n", pci_name(VORTEX_PCI(vp)));
vp->enable_wol = 0;
return;
}
if (VORTEX_PCI(vp)->current_state < PCI_D3hot)
return;
pci_set_power_state(VORTEX_PCI(vp), PCI_D3hot);
}
}
static void vortex_remove_one(struct pci_dev *pdev)
{
struct net_device *dev = pci_get_drvdata(pdev);
struct vortex_private *vp;
if (!dev) {
pr_err("vortex_remove_one called for Compaq device!\n");
BUG();
}
vp = netdev_priv(dev);
if (vp->cb_fn_base)
pci_iounmap(VORTEX_PCI(vp), vp->cb_fn_base);
unregister_netdev(dev);
if (VORTEX_PCI(vp)) {
pci_set_power_state(VORTEX_PCI(vp), PCI_D0);
if (vp->pm_state_valid)
pci_restore_state(VORTEX_PCI(vp));
pci_disable_device(VORTEX_PCI(vp));
}
iowrite16(TotalReset | ((vp->drv_flags & EEPROM_RESET) ? 0x04 : 0x14),
vp->ioaddr + EL3_CMD);
pci_iounmap(VORTEX_PCI(vp), vp->ioaddr);
pci_free_consistent(pdev,
sizeof(struct boom_rx_desc) * RX_RING_SIZE
+ sizeof(struct boom_tx_desc) * TX_RING_SIZE,
vp->rx_ring,
vp->rx_ring_dma);
if (vp->must_free_region)
release_region(dev->base_addr, vp->io_size);
free_netdev(dev);
}
static int __init vortex_init(void)
{
int pci_rc, eisa_rc;
pci_rc = pci_register_driver(&vortex_driver);
eisa_rc = vortex_eisa_init();
if (pci_rc == 0)
vortex_have_pci = 1;
if (eisa_rc > 0)
vortex_have_eisa = 1;
return (vortex_have_pci + vortex_have_eisa) ? 0 : -ENODEV;
}
static void __exit vortex_eisa_cleanup(void)
{
struct vortex_private *vp;
void __iomem *ioaddr;
#ifdef CONFIG_EISA
eisa_driver_unregister(&vortex_eisa_driver);
#endif
if (compaq_net_device) {
vp = netdev_priv(compaq_net_device);
ioaddr = ioport_map(compaq_net_device->base_addr,
VORTEX_TOTAL_SIZE);
unregister_netdev(compaq_net_device);
iowrite16(TotalReset, ioaddr + EL3_CMD);
release_region(compaq_net_device->base_addr,
VORTEX_TOTAL_SIZE);
free_netdev(compaq_net_device);
}
}
static void __exit vortex_cleanup(void)
{
if (vortex_have_pci)
pci_unregister_driver(&vortex_driver);
if (vortex_have_eisa)
vortex_eisa_cleanup();
}
