static void cy82c693_set_dma_mode(ide_hwif_t *hwif, ide_drive_t *drive)
{
const u8 mode = drive->dma_mode;
u8 single = (mode & 0x10) >> 4, index = 0, data = 0;
index = hwif->channel ? CY82_INDEX_CHANNEL1 : CY82_INDEX_CHANNEL0;
data = (mode & 3) | (single << 2);
outb(index, CY82_INDEX_PORT);
outb(data, CY82_DATA_PORT);
data = BUSMASTER_TIMEOUT;
outb(CY82_INDEX_TIMEOUT, CY82_INDEX_PORT);
outb(data, CY82_DATA_PORT);
}
static void cy82c693_set_pio_mode(ide_hwif_t *hwif, ide_drive_t *drive)
{
struct pci_dev *dev = to_pci_dev(hwif->dev);
int bus_speed = ide_pci_clk ? ide_pci_clk : 33;
const unsigned long T = 1000000 / bus_speed;
unsigned int addrCtrl;
struct ide_timing t;
u8 time_16, time_8;
if (drive->dn > 1) {
dev = pci_get_slot(dev->bus, dev->devfn+1);
if (!dev) {
printk(KERN_ERR "%s: tune_drive: "
"Cannot find secondary interface!\n",
drive->name);
return;
}
}
ide_timing_compute(drive, drive->pio_mode, &t, T, 1);
time_16 = clamp_val(t.recover - 1, 0, 15) |
(clamp_val(t.active - 1, 0, 15) << 4);
time_8 = clamp_val(t.act8b - 1, 0, 15) |
(clamp_val(t.rec8b - 1, 0, 15) << 4);
if ((drive->dn & 1) == 0) {
pci_read_config_dword(dev, CY82_IDE_ADDRSETUP, &addrCtrl);
addrCtrl &= (~0xF);
addrCtrl |= clamp_val(t.setup - 1, 0, 15);
pci_write_config_dword(dev, CY82_IDE_ADDRSETUP, addrCtrl);
pci_write_config_byte(dev, CY82_IDE_MASTER_IOR, time_16);
pci_write_config_byte(dev, CY82_IDE_MASTER_IOW, time_16);
pci_write_config_byte(dev, CY82_IDE_MASTER_8BIT, time_8);
} else {
pci_read_config_dword(dev, CY82_IDE_ADDRSETUP, &addrCtrl);
addrCtrl &= (~0xF0);
addrCtrl |= (clamp_val(t.setup - 1, 0, 15) << 4);
pci_write_config_dword(dev, CY82_IDE_ADDRSETUP, addrCtrl);
pci_write_config_byte(dev, CY82_IDE_SLAVE_IOR, time_16);
pci_write_config_byte(dev, CY82_IDE_SLAVE_IOW, time_16);
pci_write_config_byte(dev, CY82_IDE_SLAVE_8BIT, time_8);
}
if (drive->dn > 1)
pci_dev_put(dev);
}
static void init_iops_cy82c693(ide_hwif_t *hwif)
{
static ide_hwif_t *primary;
struct pci_dev *dev = to_pci_dev(hwif->dev);
if (PCI_FUNC(dev->devfn) == 1)
primary = hwif;
else {
hwif->mate = primary;
hwif->channel = 1;
}
}
static int cy82c693_init_one(struct pci_dev *dev,
const struct pci_device_id *id)
{
struct pci_dev *dev2;
int ret = -ENODEV;
if ((dev->class >> 8) == PCI_CLASS_STORAGE_IDE &&
PCI_FUNC(dev->devfn) == 1) {
dev2 = pci_get_slot(dev->bus, dev->devfn + 1);
ret = ide_pci_init_two(dev, dev2, &cy82c693_chipset, NULL);
if (ret)
pci_dev_put(dev2);
}
return ret;
}
static void cy82c693_remove(struct pci_dev *dev)
{
struct ide_host *host = pci_get_drvdata(dev);
struct pci_dev *dev2 = host->dev[1] ? to_pci_dev(host->dev[1]) : NULL;
ide_pci_remove(dev);
pci_dev_put(dev2);
}
static int __init cy82c693_ide_init(void)
{
return ide_pci_register_driver(&cy82c693_pci_driver);
}
static void __exit cy82c693_ide_exit(void)
{
pci_unregister_driver(&cy82c693_pci_driver);
}
