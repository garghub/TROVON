static void cs5535_set_speed(ide_drive_t *drive, const u8 speed)
{
u32 reg = 0, dummy;
u8 unit = drive->dn & 1;
if (speed < XFER_SW_DMA_0) {
ide_drive_t *pair = ide_get_pair_dev(drive);
u8 cmd, pioa;
cmd = pioa = speed - XFER_PIO_0;
if (pair) {
u8 piob = pair->pio_mode - XFER_PIO_0;
if (piob < cmd)
cmd = piob;
}
reg = (cs5535_pio_cmd_timings[cmd] << 16) |
cs5535_pio_dta_timings[pioa];
wrmsr(unit ? ATAC_CH0D1_PIO : ATAC_CH0D0_PIO, reg, 0);
rdmsr(unit ? ATAC_CH0D0_PIO : ATAC_CH0D1_PIO, reg, dummy);
if (((reg >> 16) & cs5535_pio_cmd_timings[cmd]) !=
cs5535_pio_cmd_timings[cmd]) {
reg &= 0x0000FFFF;
reg |= cs5535_pio_cmd_timings[cmd] << 16;
wrmsr(unit ? ATAC_CH0D0_PIO : ATAC_CH0D1_PIO, reg, 0);
}
rdmsr(unit ? ATAC_CH0D1_DMA : ATAC_CH0D0_DMA, reg, dummy);
wrmsr(unit ? ATAC_CH0D1_DMA : ATAC_CH0D0_DMA,
reg | 0x80000000UL, 0);
} else {
rdmsr(unit ? ATAC_CH0D1_DMA : ATAC_CH0D0_DMA, reg, dummy);
reg &= 0x80000000UL;
if (speed >= XFER_UDMA_0 && speed <= XFER_UDMA_4)
reg |= cs5535_udma_timings[speed - XFER_UDMA_0];
else if (speed >= XFER_MW_DMA_0 && speed <= XFER_MW_DMA_2)
reg |= cs5535_mwdma_timings[speed - XFER_MW_DMA_0];
else
return;
wrmsr(unit ? ATAC_CH0D1_DMA : ATAC_CH0D0_DMA, reg, 0);
}
}
static void cs5535_set_dma_mode(ide_hwif_t *hwif, ide_drive_t *drive)
{
cs5535_set_speed(drive, drive->dma_mode);
}
static void cs5535_set_pio_mode(ide_hwif_t *hwif, ide_drive_t *drive)
{
cs5535_set_speed(drive, drive->pio_mode);
}
static u8 cs5535_cable_detect(ide_hwif_t *hwif)
{
struct pci_dev *dev = to_pci_dev(hwif->dev);
u8 bit;
pci_read_config_byte(dev, CS5535_CABLE_DETECT, &bit);
return (bit & 1) ? ATA_CBL_PATA80 : ATA_CBL_PATA40;
}
static int cs5535_init_one(struct pci_dev *dev, const struct pci_device_id *id)
{
return ide_pci_init_one(dev, &cs5535_chipset, NULL);
}
static int __init cs5535_ide_init(void)
{
return ide_pci_register_driver(&cs5535_pci_driver);
}
static void __exit cs5535_ide_exit(void)
{
pci_unregister_driver(&cs5535_pci_driver);
}
