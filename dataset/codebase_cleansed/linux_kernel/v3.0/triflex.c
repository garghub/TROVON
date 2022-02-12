static void triflex_set_mode(ide_hwif_t *hwif, ide_drive_t *drive)
{
struct pci_dev *dev = to_pci_dev(hwif->dev);
u32 triflex_timings = 0;
u16 timing = 0;
u8 channel_offset = hwif->channel ? 0x74 : 0x70, unit = drive->dn & 1;
pci_read_config_dword(dev, channel_offset, &triflex_timings);
switch (drive->dma_mode) {
case XFER_MW_DMA_2:
timing = 0x0103;
break;
case XFER_MW_DMA_1:
timing = 0x0203;
break;
case XFER_MW_DMA_0:
timing = 0x0808;
break;
case XFER_SW_DMA_2:
case XFER_SW_DMA_1:
case XFER_SW_DMA_0:
timing = 0x0f0f;
break;
case XFER_PIO_4:
timing = 0x0202;
break;
case XFER_PIO_3:
timing = 0x0204;
break;
case XFER_PIO_2:
timing = 0x0404;
break;
case XFER_PIO_1:
timing = 0x0508;
break;
case XFER_PIO_0:
timing = 0x0808;
break;
}
triflex_timings &= ~(0xFFFF << (16 * unit));
triflex_timings |= (timing << (16 * unit));
pci_write_config_dword(dev, channel_offset, triflex_timings);
}
static void triflex_set_pio_mode(ide_hwif_t *hwif, ide_drive_t *drive)
{
drive->dma_mode = drive->pio_mode;
triflex_set_mode(hwif, drive);
}
static int __devinit triflex_init_one(struct pci_dev *dev,
const struct pci_device_id *id)
{
return ide_pci_init_one(dev, &triflex_device, NULL);
}
static int __init triflex_ide_init(void)
{
return ide_pci_register_driver(&triflex_pci_driver);
}
static void __exit triflex_ide_exit(void)
{
pci_unregister_driver(&triflex_pci_driver);
}
