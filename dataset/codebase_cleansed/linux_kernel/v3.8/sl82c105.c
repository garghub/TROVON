static unsigned int get_pio_timings(ide_drive_t *drive, u8 pio)
{
struct ide_timing *t = ide_timing_find_mode(XFER_PIO_0 + pio);
unsigned int cmd_on, cmd_off;
u8 iordy = 0;
cmd_on = (t->active + 29) / 30;
cmd_off = (ide_pio_cycle_time(drive, pio) - 30 * cmd_on + 29) / 30;
if (cmd_on == 0)
cmd_on = 1;
if (cmd_off == 0)
cmd_off = 1;
if (ide_pio_need_iordy(drive, pio))
iordy = 0x40;
return (cmd_on - 1) << 8 | (cmd_off - 1) | iordy;
}
static void sl82c105_set_pio_mode(ide_hwif_t *hwif, ide_drive_t *drive)
{
struct pci_dev *dev = to_pci_dev(hwif->dev);
unsigned long timings = (unsigned long)ide_get_drivedata(drive);
int reg = 0x44 + drive->dn * 4;
u16 drv_ctrl;
const u8 pio = drive->pio_mode - XFER_PIO_0;
drv_ctrl = get_pio_timings(drive, pio);
timings &= 0xffff0000;
timings |= drv_ctrl;
ide_set_drivedata(drive, (void *)timings);
pci_write_config_word(dev, reg, drv_ctrl);
pci_read_config_word (dev, reg, &drv_ctrl);
printk(KERN_DEBUG "%s: selected %s (%dns) (%04X)\n", drive->name,
ide_xfer_verbose(pio + XFER_PIO_0),
ide_pio_cycle_time(drive, pio), drv_ctrl);
}
static void sl82c105_set_dma_mode(ide_hwif_t *hwif, ide_drive_t *drive)
{
static u16 mwdma_timings[] = {0x0707, 0x0201, 0x0200};
unsigned long timings = (unsigned long)ide_get_drivedata(drive);
u16 drv_ctrl;
const u8 speed = drive->dma_mode;
drv_ctrl = mwdma_timings[speed - XFER_MW_DMA_0];
timings &= 0x0000ffff;
timings |= (unsigned long)drv_ctrl << 16;
ide_set_drivedata(drive, (void *)timings);
}
static int sl82c105_test_irq(ide_hwif_t *hwif)
{
struct pci_dev *dev = to_pci_dev(hwif->dev);
u32 val, mask = hwif->channel ? CTRL_IDE_IRQB : CTRL_IDE_IRQA;
pci_read_config_dword(dev, 0x40, &val);
return (val & mask) ? 1 : 0;
}
static inline void sl82c105_reset_host(struct pci_dev *dev)
{
u16 val;
pci_read_config_word(dev, 0x7e, &val);
pci_write_config_word(dev, 0x7e, val | (1 << 2));
pci_write_config_word(dev, 0x7e, val & ~(1 << 2));
}
static void sl82c105_dma_lost_irq(ide_drive_t *drive)
{
ide_hwif_t *hwif = drive->hwif;
struct pci_dev *dev = to_pci_dev(hwif->dev);
u32 val, mask = hwif->channel ? CTRL_IDE_IRQB : CTRL_IDE_IRQA;
u8 dma_cmd;
printk(KERN_WARNING "sl82c105: lost IRQ, resetting host\n");
pci_read_config_dword(dev, 0x40, &val);
if (val & mask)
printk(KERN_INFO "sl82c105: drive was requesting IRQ, "
"but host lost it\n");
dma_cmd = inb(hwif->dma_base + ATA_DMA_CMD);
if (dma_cmd & 1) {
outb(dma_cmd & ~1, hwif->dma_base + ATA_DMA_CMD);
printk(KERN_INFO "sl82c105: DMA was enabled\n");
}
sl82c105_reset_host(dev);
}
static void sl82c105_dma_start(ide_drive_t *drive)
{
ide_hwif_t *hwif = drive->hwif;
struct pci_dev *dev = to_pci_dev(hwif->dev);
int reg = 0x44 + drive->dn * 4;
pci_write_config_word(dev, reg,
(unsigned long)ide_get_drivedata(drive) >> 16);
sl82c105_reset_host(dev);
ide_dma_start(drive);
}
static void sl82c105_dma_clear(ide_drive_t *drive)
{
struct pci_dev *dev = to_pci_dev(drive->hwif->dev);
sl82c105_reset_host(dev);
}
static int sl82c105_dma_end(ide_drive_t *drive)
{
struct pci_dev *dev = to_pci_dev(drive->hwif->dev);
int reg = 0x44 + drive->dn * 4;
int ret = ide_dma_end(drive);
pci_write_config_word(dev, reg,
(unsigned long)ide_get_drivedata(drive));
return ret;
}
static void sl82c105_resetproc(ide_drive_t *drive)
{
struct pci_dev *dev = to_pci_dev(drive->hwif->dev);
u32 val;
pci_read_config_dword(dev, 0x40, &val);
val |= (CTRL_P1F16 | CTRL_P0F16);
pci_write_config_dword(dev, 0x40, val);
}
static u8 sl82c105_bridge_revision(struct pci_dev *dev)
{
struct pci_dev *bridge;
bridge = pci_get_bus_and_slot(dev->bus->number,
PCI_DEVFN(PCI_SLOT(dev->devfn), 0));
if (!bridge)
return -1;
if (bridge->vendor != PCI_VENDOR_ID_WINBOND ||
bridge->device != PCI_DEVICE_ID_WINBOND_83C553 ||
bridge->class >> 8 != PCI_CLASS_BRIDGE_ISA) {
pci_dev_put(bridge);
return -1;
}
pci_dev_put(bridge);
return bridge->revision;
}
static int init_chipset_sl82c105(struct pci_dev *dev)
{
u32 val;
pci_read_config_dword(dev, 0x40, &val);
val |= CTRL_P0EN | CTRL_P0F16 | CTRL_P1F16;
pci_write_config_dword(dev, 0x40, val);
return 0;
}
static int sl82c105_init_one(struct pci_dev *dev, const struct pci_device_id *id)
{
struct ide_port_info d = sl82c105_chipset;
u8 rev = sl82c105_bridge_revision(dev);
if (rev <= 5) {
printk(KERN_INFO DRV_NAME ": Winbond W83C553 bridge "
"revision %d, BM-DMA disabled\n", rev);
d.dma_ops = NULL;
d.mwdma_mask = 0;
d.host_flags &= ~IDE_HFLAG_SERIALIZE_DMA;
}
return ide_pci_init_one(dev, &d, NULL);
}
static int __init sl82c105_ide_init(void)
{
return ide_pci_register_driver(&sl82c105_pci_driver);
}
static void __exit sl82c105_ide_exit(void)
{
pci_unregister_driver(&sl82c105_pci_driver);
}
