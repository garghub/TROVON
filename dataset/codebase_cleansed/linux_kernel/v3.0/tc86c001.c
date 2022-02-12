static void tc86c001_set_mode(ide_hwif_t *hwif, ide_drive_t *drive)
{
unsigned long scr_port = hwif->config_data + (drive->dn ? 0x02 : 0x00);
u16 mode, scr = inw(scr_port);
const u8 speed = drive->dma_mode;
switch (speed) {
case XFER_UDMA_4: mode = 0x00c0; break;
case XFER_UDMA_3: mode = 0x00b0; break;
case XFER_UDMA_2: mode = 0x00a0; break;
case XFER_UDMA_1: mode = 0x0090; break;
case XFER_UDMA_0: mode = 0x0080; break;
case XFER_MW_DMA_2: mode = 0x0070; break;
case XFER_MW_DMA_1: mode = 0x0060; break;
case XFER_MW_DMA_0: mode = 0x0050; break;
case XFER_PIO_4: mode = 0x0400; break;
case XFER_PIO_3: mode = 0x0300; break;
case XFER_PIO_2: mode = 0x0200; break;
case XFER_PIO_1: mode = 0x0100; break;
case XFER_PIO_0:
default: mode = 0x0000; break;
}
scr &= (speed < XFER_MW_DMA_0) ? 0xf8ff : 0xff0f;
scr |= mode;
outw(scr, scr_port);
}
static void tc86c001_set_pio_mode(ide_hwif_t *hwif, ide_drive_t *drive)
{
drive->dma_mode = drive->pio_mode;
tc86c001_set_mode(hwif, drive);
}
static int tc86c001_timer_expiry(ide_drive_t *drive)
{
ide_hwif_t *hwif = drive->hwif;
ide_expiry_t *expiry = ide_get_hwifdata(hwif);
u8 dma_stat = inb(hwif->dma_base + ATA_DMA_STATUS);
hwif->expiry = expiry;
if ((dma_stat & 5) == 1) {
unsigned long sc_base = hwif->config_data;
unsigned long twcr_port = sc_base + (drive->dn ? 0x06 : 0x04);
u8 dma_cmd = inb(hwif->dma_base + ATA_DMA_CMD);
printk(KERN_WARNING "%s: DMA interrupt possibly stuck, "
"attempting recovery...\n", drive->name);
outb(dma_cmd & ~0x01, hwif->dma_base + ATA_DMA_CMD);
outw(0, sc_base + 0x0a);
outw(0, twcr_port);
outb(0x00, hwif->dma_base + ATA_DMA_CMD);
outb(0x01, hwif->dma_base + ATA_DMA_CMD);
return WAIT_MIN_SLEEP;
}
if (likely(expiry != NULL))
return expiry(drive);
return -1;
}
static void tc86c001_dma_start(ide_drive_t *drive)
{
ide_hwif_t *hwif = drive->hwif;
unsigned long sc_base = hwif->config_data;
unsigned long twcr_port = sc_base + (drive->dn ? 0x06 : 0x04);
unsigned long nsectors = blk_rq_sectors(hwif->rq);
outw(nsectors, sc_base + 0x0a);
outw(SECTOR_SIZE / 2, twcr_port);
ide_set_hwifdata(hwif, hwif->expiry);
hwif->expiry = &tc86c001_timer_expiry;
ide_dma_start(drive);
}
static u8 tc86c001_cable_detect(ide_hwif_t *hwif)
{
struct pci_dev *dev = to_pci_dev(hwif->dev);
unsigned long sc_base = pci_resource_start(dev, 5);
u16 scr1 = inw(sc_base + 0x00);
return (scr1 & 0x2000) ? ATA_CBL_PATA40 : ATA_CBL_PATA80;
}
static void __devinit init_hwif_tc86c001(ide_hwif_t *hwif)
{
struct pci_dev *dev = to_pci_dev(hwif->dev);
unsigned long sc_base = pci_resource_start(dev, 5);
u16 scr1 = inw(sc_base + 0x00);
outw(scr1 | 0x8000, sc_base + 0x00);
outw(scr1 | 0x4000, sc_base + 0x00);
outw(scr1 & ~0xc000, sc_base + 0x00);
hwif->config_data = sc_base;
if (!hwif->dma_base)
return;
outw(0x0003, sc_base + 0x0c);
hwif->rqsize = 0xffff;
}
static int __devinit tc86c001_init_one(struct pci_dev *dev,
const struct pci_device_id *id)
{
int rc;
rc = pci_enable_device(dev);
if (rc)
goto out;
rc = pci_request_region(dev, 5, DRV_NAME);
if (rc) {
printk(KERN_ERR DRV_NAME ": system control regs already in use");
goto out_disable;
}
rc = ide_pci_init_one(dev, &tc86c001_chipset, NULL);
if (rc)
goto out_release;
goto out;
out_release:
pci_release_region(dev, 5);
out_disable:
pci_disable_device(dev);
out:
return rc;
}
static void __devexit tc86c001_remove(struct pci_dev *dev)
{
ide_pci_remove(dev);
pci_release_region(dev, 5);
pci_disable_device(dev);
}
static int __init tc86c001_ide_init(void)
{
return ide_pci_register_driver(&tc86c001_pci_driver);
}
static void __exit tc86c001_ide_exit(void)
{
pci_unregister_driver(&tc86c001_pci_driver);
}
