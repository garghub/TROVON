static void atiixp_set_pio_mode(ide_hwif_t *hwif, ide_drive_t *drive)
{
struct pci_dev *dev = to_pci_dev(hwif->dev);
unsigned long flags;
int timing_shift = (drive->dn ^ 1) * 8;
u32 pio_timing_data;
u16 pio_mode_data;
const u8 pio = drive->pio_mode - XFER_PIO_0;
spin_lock_irqsave(&atiixp_lock, flags);
pci_read_config_word(dev, ATIIXP_IDE_PIO_MODE, &pio_mode_data);
pio_mode_data &= ~(0x07 << (drive->dn * 4));
pio_mode_data |= (pio << (drive->dn * 4));
pci_write_config_word(dev, ATIIXP_IDE_PIO_MODE, pio_mode_data);
pci_read_config_dword(dev, ATIIXP_IDE_PIO_TIMING, &pio_timing_data);
pio_timing_data &= ~(0xff << timing_shift);
pio_timing_data |= (pio_timing[pio].recover_width << timing_shift) |
(pio_timing[pio].command_width << (timing_shift + 4));
pci_write_config_dword(dev, ATIIXP_IDE_PIO_TIMING, pio_timing_data);
spin_unlock_irqrestore(&atiixp_lock, flags);
}
static void atiixp_set_dma_mode(ide_hwif_t *hwif, ide_drive_t *drive)
{
struct pci_dev *dev = to_pci_dev(hwif->dev);
unsigned long flags;
int timing_shift = (drive->dn ^ 1) * 8;
u32 tmp32;
u16 tmp16;
u16 udma_ctl = 0;
const u8 speed = drive->dma_mode;
spin_lock_irqsave(&atiixp_lock, flags);
pci_read_config_word(dev, ATIIXP_IDE_UDMA_CONTROL, &udma_ctl);
if (speed >= XFER_UDMA_0) {
pci_read_config_word(dev, ATIIXP_IDE_UDMA_MODE, &tmp16);
tmp16 &= ~(0x07 << (drive->dn * 4));
tmp16 |= ((speed & 0x07) << (drive->dn * 4));
pci_write_config_word(dev, ATIIXP_IDE_UDMA_MODE, tmp16);
udma_ctl |= (1 << drive->dn);
} else if (speed >= XFER_MW_DMA_0) {
u8 i = speed & 0x03;
pci_read_config_dword(dev, ATIIXP_IDE_MDMA_TIMING, &tmp32);
tmp32 &= ~(0xff << timing_shift);
tmp32 |= (mdma_timing[i].recover_width << timing_shift) |
(mdma_timing[i].command_width << (timing_shift + 4));
pci_write_config_dword(dev, ATIIXP_IDE_MDMA_TIMING, tmp32);
udma_ctl &= ~(1 << drive->dn);
}
pci_write_config_word(dev, ATIIXP_IDE_UDMA_CONTROL, udma_ctl);
spin_unlock_irqrestore(&atiixp_lock, flags);
}
static u8 atiixp_cable_detect(ide_hwif_t *hwif)
{
struct pci_dev *pdev = to_pci_dev(hwif->dev);
u8 udma_mode = 0, ch = hwif->channel;
pci_read_config_byte(pdev, ATIIXP_IDE_UDMA_MODE + ch, &udma_mode);
if ((udma_mode & 0x07) >= 0x04 || (udma_mode & 0x70) >= 0x40)
return ATA_CBL_PATA80;
else
return ATA_CBL_PATA40;
}
static int __devinit atiixp_init_one(struct pci_dev *dev, const struct pci_device_id *id)
{
return ide_pci_init_one(dev, &atiixp_pci_info[id->driver_data], NULL);
}
static int __init atiixp_ide_init(void)
{
return ide_pci_register_driver(&atiixp_pci_driver);
}
static void __exit atiixp_ide_exit(void)
{
pci_unregister_driver(&atiixp_pci_driver);
}
