static int check_in_drive_lists (ide_drive_t *drive, const char **list)
{
char *m = (char *)&drive->id[ATA_ID_PROD];
while (*list)
if (!strcmp(*list++, m))
return 1;
return 0;
}
static u8 svwks_udma_filter(ide_drive_t *drive)
{
struct pci_dev *dev = to_pci_dev(drive->hwif->dev);
if (dev->device == PCI_DEVICE_ID_SERVERWORKS_HT1000IDE) {
return 0x1f;
} else if (dev->revision < SVWKS_CSB5_REVISION_NEW) {
return 0x07;
} else {
u8 btr = 0, mode, mask;
pci_read_config_byte(dev, 0x5A, &btr);
mode = btr & 0x3;
if (mode > 2 && check_in_drive_lists(drive, svwks_bad_ata100))
mode = 2;
switch(mode) {
case 3: mask = 0x3f; break;
case 2: mask = 0x1f; break;
case 1: mask = 0x07; break;
default: mask = 0x00; break;
}
return mask;
}
}
static u8 svwks_csb_check (struct pci_dev *dev)
{
switch (dev->device) {
case PCI_DEVICE_ID_SERVERWORKS_CSB5IDE:
case PCI_DEVICE_ID_SERVERWORKS_CSB6IDE:
case PCI_DEVICE_ID_SERVERWORKS_CSB6IDE2:
case PCI_DEVICE_ID_SERVERWORKS_HT1000IDE:
return 1;
default:
break;
}
return 0;
}
static void svwks_set_pio_mode(ide_hwif_t *hwif, ide_drive_t *drive)
{
static const u8 pio_modes[] = { 0x5d, 0x47, 0x34, 0x22, 0x20 };
static const u8 drive_pci[] = { 0x41, 0x40, 0x43, 0x42 };
struct pci_dev *dev = to_pci_dev(hwif->dev);
const u8 pio = drive->pio_mode - XFER_PIO_0;
pci_write_config_byte(dev, drive_pci[drive->dn], pio_modes[pio]);
if (svwks_csb_check(dev)) {
u16 csb_pio = 0;
pci_read_config_word(dev, 0x4a, &csb_pio);
csb_pio &= ~(0x0f << (4 * drive->dn));
csb_pio |= (pio << (4 * drive->dn));
pci_write_config_word(dev, 0x4a, csb_pio);
}
}
static void svwks_set_dma_mode(ide_hwif_t *hwif, ide_drive_t *drive)
{
static const u8 udma_modes[] = { 0x00, 0x01, 0x02, 0x03, 0x04, 0x05 };
static const u8 dma_modes[] = { 0x77, 0x21, 0x20 };
static const u8 drive_pci2[] = { 0x45, 0x44, 0x47, 0x46 };
struct pci_dev *dev = to_pci_dev(hwif->dev);
const u8 speed = drive->dma_mode;
u8 unit = drive->dn & 1;
u8 ultra_enable = 0, ultra_timing = 0, dma_timing = 0;
pci_read_config_byte(dev, (0x56|hwif->channel), &ultra_timing);
pci_read_config_byte(dev, 0x54, &ultra_enable);
ultra_timing &= ~(0x0F << (4*unit));
ultra_enable &= ~(0x01 << drive->dn);
if (speed >= XFER_UDMA_0) {
dma_timing |= dma_modes[2];
ultra_timing |= (udma_modes[speed - XFER_UDMA_0] << (4 * unit));
ultra_enable |= (0x01 << drive->dn);
} else if (speed >= XFER_MW_DMA_0)
dma_timing |= dma_modes[speed - XFER_MW_DMA_0];
pci_write_config_byte(dev, drive_pci2[drive->dn], dma_timing);
pci_write_config_byte(dev, (0x56|hwif->channel), ultra_timing);
pci_write_config_byte(dev, 0x54, ultra_enable);
}
static int init_chipset_svwks(struct pci_dev *dev)
{
unsigned int reg;
u8 btr;
pci_write_config_byte(dev, PCI_LATENCY_TIMER, 0x40);
if (dev->device == PCI_DEVICE_ID_SERVERWORKS_OSB4IDE) {
struct pci_dev *isa_dev =
pci_get_device(PCI_VENDOR_ID_SERVERWORKS,
PCI_DEVICE_ID_SERVERWORKS_OSB4, NULL);
if (isa_dev) {
pci_read_config_dword(isa_dev, 0x64, &reg);
reg &= ~0x00002000;
if(!(reg & 0x00004000))
printk(KERN_DEBUG DRV_NAME " %s: UDMA not BIOS "
"enabled.\n", pci_name(dev));
reg |= 0x00004000;
pci_write_config_dword(isa_dev, 0x64, reg);
pci_dev_put(isa_dev);
}
}
else if ((dev->device == PCI_DEVICE_ID_SERVERWORKS_CSB5IDE) ||
(dev->device == PCI_DEVICE_ID_SERVERWORKS_CSB6IDE) ||
(dev->device == PCI_DEVICE_ID_SERVERWORKS_CSB6IDE2)) {
if (!(PCI_FUNC(dev->devfn) & 1)) {
struct pci_dev * findev = NULL;
u32 reg4c = 0;
findev = pci_get_device(PCI_VENDOR_ID_SERVERWORKS,
PCI_DEVICE_ID_SERVERWORKS_CSB5, NULL);
if (findev) {
pci_read_config_dword(findev, 0x4C, &reg4c);
reg4c &= ~0x000007FF;
reg4c |= 0x00000040;
reg4c |= 0x00000020;
pci_write_config_dword(findev, 0x4C, reg4c);
pci_dev_put(findev);
}
outb_p(0x06, 0x0c00);
dev->irq = inb_p(0x0c01);
} else {
struct pci_dev * findev = NULL;
u8 reg41 = 0;
findev = pci_get_device(PCI_VENDOR_ID_SERVERWORKS,
PCI_DEVICE_ID_SERVERWORKS_CSB6, NULL);
if (findev) {
pci_read_config_byte(findev, 0x41, &reg41);
reg41 &= ~0x40;
pci_write_config_byte(findev, 0x41, reg41);
pci_dev_put(findev);
}
if ((dev->class >> 8) == PCI_CLASS_STORAGE_IDE)
dev->irq = 0;
}
pci_read_config_byte(dev, 0x5A, &btr);
btr &= ~0x40;
if (!(PCI_FUNC(dev->devfn) & 1))
btr |= 0x2;
else
btr |= (dev->revision >= SVWKS_CSB5_REVISION_NEW) ? 0x3 : 0x2;
pci_write_config_byte(dev, 0x5A, btr);
}
else if (dev->device == PCI_DEVICE_ID_SERVERWORKS_HT1000IDE) {
pci_read_config_byte(dev, 0x5A, &btr);
btr &= ~0x40;
btr |= 0x3;
pci_write_config_byte(dev, 0x5A, btr);
}
return 0;
}
static u8 ata66_svwks_svwks(ide_hwif_t *hwif)
{
return ATA_CBL_PATA80;
}
static u8 ata66_svwks_dell(ide_hwif_t *hwif)
{
struct pci_dev *dev = to_pci_dev(hwif->dev);
if (dev->subsystem_vendor == PCI_VENDOR_ID_DELL &&
dev->vendor == PCI_VENDOR_ID_SERVERWORKS &&
(dev->device == PCI_DEVICE_ID_SERVERWORKS_CSB5IDE ||
dev->device == PCI_DEVICE_ID_SERVERWORKS_CSB6IDE))
return ((1 << (hwif->channel + 14)) &
dev->subsystem_device) ? ATA_CBL_PATA80 : ATA_CBL_PATA40;
return ATA_CBL_PATA40;
}
static u8 ata66_svwks_cobalt(ide_hwif_t *hwif)
{
struct pci_dev *dev = to_pci_dev(hwif->dev);
if (dev->subsystem_vendor == PCI_VENDOR_ID_SUN &&
dev->vendor == PCI_VENDOR_ID_SERVERWORKS &&
dev->device == PCI_DEVICE_ID_SERVERWORKS_CSB5IDE)
return ((1 << (hwif->channel + 14)) &
dev->subsystem_device) ? ATA_CBL_PATA80 : ATA_CBL_PATA40;
return ATA_CBL_PATA40;
}
static u8 svwks_cable_detect(ide_hwif_t *hwif)
{
struct pci_dev *dev = to_pci_dev(hwif->dev);
if (dev->subsystem_vendor == PCI_VENDOR_ID_SERVERWORKS)
return ata66_svwks_svwks (hwif);
if (dev->subsystem_vendor == PCI_VENDOR_ID_DELL)
return ata66_svwks_dell (hwif);
if (dev->subsystem_vendor == PCI_VENDOR_ID_SUN)
return ata66_svwks_cobalt (hwif);
if ((dev->device == PCI_DEVICE_ID_SERVERWORKS_CSB6IDE) ||
(dev->device == PCI_DEVICE_ID_SERVERWORKS_CSB6IDE2))
return ATA_CBL_PATA80;
return ATA_CBL_PATA40;
}
static int __devinit svwks_init_one(struct pci_dev *dev, const struct pci_device_id *id)
{
struct ide_port_info d;
u8 idx = id->driver_data;
d = serverworks_chipsets[idx];
if (idx == 1)
d.host_flags |= IDE_HFLAG_CLEAR_SIMPLEX;
else if (idx == 2 || idx == 3) {
if ((PCI_FUNC(dev->devfn) & 1) == 0) {
if (pci_resource_start(dev, 0) != 0x01f1)
d.host_flags |= IDE_HFLAG_NON_BOOTABLE;
d.host_flags |= IDE_HFLAG_SINGLE;
} else
d.host_flags &= ~IDE_HFLAG_SINGLE;
}
return ide_pci_init_one(dev, &d, NULL);
}
static int __init svwks_ide_init(void)
{
return ide_pci_register_driver(&svwks_pci_driver);
}
static void __exit svwks_ide_exit(void)
{
pci_unregister_driver(&svwks_pci_driver);
}
