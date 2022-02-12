static void pdc202xx_set_mode(ide_hwif_t *hwif, ide_drive_t *drive)
{
struct pci_dev *dev = to_pci_dev(hwif->dev);
u8 drive_pci = 0x60 + (drive->dn << 2);
const u8 speed = drive->dma_mode;
u8 AP = 0, BP = 0, CP = 0;
u8 TA = 0, TB = 0, TC = 0;
pci_read_config_byte(dev, drive_pci, &AP);
pci_read_config_byte(dev, drive_pci + 1, &BP);
pci_read_config_byte(dev, drive_pci + 2, &CP);
switch(speed) {
case XFER_UDMA_5:
case XFER_UDMA_4: TB = 0x20; TC = 0x01; break;
case XFER_UDMA_2: TB = 0x20; TC = 0x01; break;
case XFER_UDMA_3:
case XFER_UDMA_1: TB = 0x40; TC = 0x02; break;
case XFER_UDMA_0:
case XFER_MW_DMA_2: TB = 0x60; TC = 0x03; break;
case XFER_MW_DMA_1: TB = 0x60; TC = 0x04; break;
case XFER_MW_DMA_0: TB = 0xE0; TC = 0x0F; break;
case XFER_PIO_4: TA = 0x01; TB = 0x04; break;
case XFER_PIO_3: TA = 0x02; TB = 0x06; break;
case XFER_PIO_2: TA = 0x03; TB = 0x08; break;
case XFER_PIO_1: TA = 0x05; TB = 0x0C; break;
case XFER_PIO_0:
default: TA = 0x09; TB = 0x13; break;
}
if (speed < XFER_SW_DMA_0) {
AP &= ~0x3f;
if (ide_pio_need_iordy(drive, speed - XFER_PIO_0))
AP |= 0x20;
if (drive->media == ide_disk)
AP |= 0x10;
BP &= ~0x1f;
pci_write_config_byte(dev, drive_pci, AP | TA);
pci_write_config_byte(dev, drive_pci + 1, BP | TB);
} else {
BP &= ~0xe0;
CP &= ~0x0f;
pci_write_config_byte(dev, drive_pci + 1, BP | TB);
pci_write_config_byte(dev, drive_pci + 2, CP | TC);
}
}
static void pdc202xx_set_pio_mode(ide_hwif_t *hwif, ide_drive_t *drive)
{
drive->dma_mode = drive->pio_mode;
pdc202xx_set_mode(hwif, drive);
}
static int pdc202xx_test_irq(ide_hwif_t *hwif)
{
struct pci_dev *dev = to_pci_dev(hwif->dev);
unsigned long high_16 = pci_resource_start(dev, 4);
u8 sc1d = inb(high_16 + 0x1d);
if (hwif->channel) {
return (sc1d & 0x40) ? 1 : 0;
} else {
return (sc1d & 0x04) ? 1 : 0;
}
}
static u8 pdc2026x_cable_detect(ide_hwif_t *hwif)
{
struct pci_dev *dev = to_pci_dev(hwif->dev);
u16 CIS, mask = hwif->channel ? (1 << 11) : (1 << 10);
pci_read_config_word(dev, 0x50, &CIS);
return (CIS & mask) ? ATA_CBL_PATA40 : ATA_CBL_PATA80;
}
static void pdc_old_enable_66MHz_clock(ide_hwif_t *hwif)
{
unsigned long clock_reg = hwif->extra_base + 0x01;
u8 clock = inb(clock_reg);
outb(clock | (hwif->channel ? 0x08 : 0x02), clock_reg);
}
static void pdc_old_disable_66MHz_clock(ide_hwif_t *hwif)
{
unsigned long clock_reg = hwif->extra_base + 0x01;
u8 clock = inb(clock_reg);
outb(clock & ~(hwif->channel ? 0x08 : 0x02), clock_reg);
}
static void pdc2026x_init_hwif(ide_hwif_t *hwif)
{
pdc_old_disable_66MHz_clock(hwif);
}
static void pdc202xx_dma_start(ide_drive_t *drive)
{
if (drive->current_speed > XFER_UDMA_2)
pdc_old_enable_66MHz_clock(drive->hwif);
if (drive->media != ide_disk || (drive->dev_flags & IDE_DFLAG_LBA48)) {
ide_hwif_t *hwif = drive->hwif;
struct request *rq = hwif->rq;
unsigned long high_16 = hwif->extra_base - 16;
unsigned long atapi_reg = high_16 + (hwif->channel ? 0x24 : 0x20);
u32 word_count = 0;
u8 clock = inb(high_16 + 0x11);
outb(clock | (hwif->channel ? 0x08 : 0x02), high_16 + 0x11);
word_count = (blk_rq_sectors(rq) << 8);
word_count = (rq_data_dir(rq) == READ) ?
word_count | 0x05000000 :
word_count | 0x06000000;
outl(word_count, atapi_reg);
}
ide_dma_start(drive);
}
static int pdc202xx_dma_end(ide_drive_t *drive)
{
if (drive->media != ide_disk || (drive->dev_flags & IDE_DFLAG_LBA48)) {
ide_hwif_t *hwif = drive->hwif;
unsigned long high_16 = hwif->extra_base - 16;
unsigned long atapi_reg = high_16 + (hwif->channel ? 0x24 : 0x20);
u8 clock = 0;
outl(0, atapi_reg);
clock = inb(high_16 + 0x11);
outb(clock & ~(hwif->channel ? 0x08:0x02), high_16 + 0x11);
}
if (drive->current_speed > XFER_UDMA_2)
pdc_old_disable_66MHz_clock(drive->hwif);
return ide_dma_end(drive);
}
static int init_chipset_pdc202xx(struct pci_dev *dev)
{
unsigned long dmabase = pci_resource_start(dev, 4);
u8 udma_speed_flag = 0, primary_mode = 0, secondary_mode = 0;
if (dmabase == 0)
goto out;
udma_speed_flag = inb(dmabase | 0x1f);
primary_mode = inb(dmabase | 0x1a);
secondary_mode = inb(dmabase | 0x1b);
printk(KERN_INFO "%s: (U)DMA Burst Bit %sABLED " \
"Primary %s Mode " \
"Secondary %s Mode.\n", pci_name(dev),
(udma_speed_flag & 1) ? "EN" : "DIS",
(primary_mode & 1) ? "MASTER" : "PCI",
(secondary_mode & 1) ? "MASTER" : "PCI" );
if (!(udma_speed_flag & 1)) {
printk(KERN_INFO "%s: FORCING BURST BIT 0x%02x->0x%02x ",
pci_name(dev), udma_speed_flag,
(udma_speed_flag|1));
outb(udma_speed_flag | 1, dmabase | 0x1f);
printk("%sACTIVE\n", (inb(dmabase | 0x1f) & 1) ? "" : "IN");
}
out:
return 0;
}
static void __devinit pdc202ata4_fixup_irq(struct pci_dev *dev,
const char *name)
{
if ((dev->class >> 8) != PCI_CLASS_STORAGE_IDE) {
u8 irq = 0, irq2 = 0;
pci_read_config_byte(dev, PCI_INTERRUPT_LINE, &irq);
pci_read_config_byte(dev, (PCI_INTERRUPT_LINE)|0x80, &irq2);
if (irq != irq2) {
pci_write_config_byte(dev,
(PCI_INTERRUPT_LINE)|0x80, irq);
printk(KERN_INFO "%s %s: PCI config space interrupt "
"mirror fixed\n", name, pci_name(dev));
}
}
}
static int __devinit pdc202xx_init_one(struct pci_dev *dev, const struct pci_device_id *id)
{
const struct ide_port_info *d;
u8 idx = id->driver_data;
d = &pdc202xx_chipsets[idx];
if (idx < 2)
pdc202ata4_fixup_irq(dev, d->name);
if (dev->vendor == PCI_DEVICE_ID_PROMISE_20265) {
struct pci_dev *bridge = dev->bus->self;
if (bridge &&
bridge->vendor == PCI_VENDOR_ID_INTEL &&
(bridge->device == PCI_DEVICE_ID_INTEL_I960 ||
bridge->device == PCI_DEVICE_ID_INTEL_I960RM)) {
printk(KERN_INFO DRV_NAME " %s: skipping Promise "
"PDC20265 attached to I2O RAID controller\n",
pci_name(dev));
return -ENODEV;
}
}
return ide_pci_init_one(dev, d, NULL);
}
static int __init pdc202xx_ide_init(void)
{
return ide_pci_register_driver(&pdc202xx_pci_driver);
}
static void __exit pdc202xx_ide_exit(void)
{
pci_unregister_driver(&pdc202xx_pci_driver);
}
