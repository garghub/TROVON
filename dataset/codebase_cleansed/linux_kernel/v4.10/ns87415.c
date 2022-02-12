static u8 superio_ide_inb (unsigned long port)
{
u8 tmp;
int retries = SUPERIO_IDE_MAX_RETRIES;
do {
tmp = inb(port);
if (tmp == 0)
udelay(50);
} while (tmp == 0 && retries-- > 0);
return tmp;
}
static u8 superio_read_status(ide_hwif_t *hwif)
{
return superio_ide_inb(hwif->io_ports.status_addr);
}
static u8 superio_dma_sff_read_status(ide_hwif_t *hwif)
{
return superio_ide_inb(hwif->dma_base + ATA_DMA_STATUS);
}
static void superio_tf_read(ide_drive_t *drive, struct ide_taskfile *tf,
u8 valid)
{
struct ide_io_ports *io_ports = &drive->hwif->io_ports;
if (valid & IDE_VALID_ERROR)
tf->error = inb(io_ports->feature_addr);
if (valid & IDE_VALID_NSECT)
tf->nsect = inb(io_ports->nsect_addr);
if (valid & IDE_VALID_LBAL)
tf->lbal = inb(io_ports->lbal_addr);
if (valid & IDE_VALID_LBAM)
tf->lbam = inb(io_ports->lbam_addr);
if (valid & IDE_VALID_LBAH)
tf->lbah = inb(io_ports->lbah_addr);
if (valid & IDE_VALID_DEVICE)
tf->device = superio_ide_inb(io_ports->device_addr);
}
static void superio_init_iops(struct hwif_s *hwif)
{
struct pci_dev *pdev = to_pci_dev(hwif->dev);
u32 dma_stat;
u8 port = hwif->channel, tmp;
dma_stat = (pci_resource_start(pdev, 4) & ~3) + (!port ? 2 : 0xa);
tmp = superio_ide_inb(dma_stat);
outb(tmp | 0x66, dma_stat);
}
static void ns87415_prepare_drive (ide_drive_t *drive, unsigned int use_dma)
{
ide_hwif_t *hwif = drive->hwif;
struct pci_dev *dev = to_pci_dev(hwif->dev);
unsigned int bit, other, new, *old = (unsigned int *) hwif->select_data;
unsigned long flags;
local_irq_save(flags);
new = *old;
bit = 1 << (8 + hwif->channel);
if (drive->dev_flags & IDE_DFLAG_PRESENT)
new &= ~bit;
else
new |= bit;
bit = 1 << (20 + (drive->dn & 1) + (hwif->channel << 1));
other = 1 << (20 + (1 - (drive->dn & 1)) + (hwif->channel << 1));
new = use_dma ? ((new & ~other) | bit) : (new & ~bit);
if (new != *old) {
unsigned char stat;
(void) pci_read_config_byte(dev, 0x43, &stat);
while (stat & 0x03) {
udelay(1);
(void) pci_read_config_byte(dev, 0x43, &stat);
}
*old = new;
(void) pci_write_config_dword(dev, 0x40, new);
udelay(10);
}
local_irq_restore(flags);
}
static void ns87415_dev_select(ide_drive_t *drive)
{
ns87415_prepare_drive(drive,
!!(drive->dev_flags & IDE_DFLAG_USING_DMA));
outb(drive->select | ATA_DEVICE_OBS, drive->hwif->io_ports.device_addr);
}
static void ns87415_dma_start(ide_drive_t *drive)
{
ns87415_prepare_drive(drive, 1);
ide_dma_start(drive);
}
static int ns87415_dma_end(ide_drive_t *drive)
{
ide_hwif_t *hwif = drive->hwif;
u8 dma_stat = 0, dma_cmd = 0;
dma_stat = hwif->dma_ops->dma_sff_read_status(hwif);
dma_cmd = inb(hwif->dma_base + ATA_DMA_CMD);
outb(dma_cmd & ~1, hwif->dma_base + ATA_DMA_CMD);
dma_cmd = inb(hwif->dma_base + ATA_DMA_CMD);
outb(dma_cmd | 6, hwif->dma_base + ATA_DMA_CMD);
ns87415_prepare_drive(drive, 0);
return (dma_stat & 7) != 4;
}
static void init_hwif_ns87415 (ide_hwif_t *hwif)
{
struct pci_dev *dev = to_pci_dev(hwif->dev);
unsigned int ctrl, using_inta;
u8 progif;
#ifdef __sparc_v9__
int timeout;
u8 stat;
#endif
(void) pci_read_config_dword(dev, 0x40, &ctrl);
(void) pci_read_config_byte(dev, 0x09, &progif);
using_inta = progif & (1 << (hwif->channel << 1));
if (!using_inta)
using_inta = ctrl & (1 << (4 + hwif->channel));
if (hwif->mate) {
hwif->select_data = hwif->mate->select_data;
} else {
hwif->select_data = (unsigned long)
&ns87415_control[ns87415_count++];
ctrl |= (1 << 8) | (1 << 9);
if (using_inta)
ctrl &= ~(1 << 6);
*((unsigned int *)hwif->select_data) = ctrl;
(void) pci_write_config_dword(dev, 0x40, ctrl);
pci_write_config_byte(dev, 0x55, 0xee);
#ifdef __sparc_v9__
timeout = 10000;
outb(12, hwif->io_ports.ctl_addr);
udelay(10);
outb(8, hwif->io_ports.ctl_addr);
do {
udelay(50);
stat = hwif->tp_ops->read_status(hwif);
if (stat == 0xff)
break;
} while ((stat & ATA_BUSY) && --timeout);
#endif
}
if (!using_inta)
hwif->irq = pci_get_legacy_ide_irq(dev, hwif->channel);
if (!hwif->dma_base)
return;
outb(0x60, hwif->dma_base + ATA_DMA_STATUS);
}
static int ns87415_init_one(struct pci_dev *dev, const struct pci_device_id *id)
{
struct ide_port_info d = ns87415_chipset;
#ifdef CONFIG_SUPERIO
if (PCI_SLOT(dev->devfn) == 0xE) {
d.init_iops = superio_init_iops;
d.tp_ops = &superio_tp_ops;
}
#endif
return ide_pci_init_one(dev, &d, NULL);
}
static int __init ns87415_ide_init(void)
{
return ide_pci_register_driver(&ns87415_pci_driver);
}
static void __exit ns87415_ide_exit(void)
{
pci_unregister_driver(&ns87415_pci_driver);
}
