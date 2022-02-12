static int cs5535_cable_detect(struct ata_port *ap)
{
u8 cable;
struct pci_dev *pdev = to_pci_dev(ap->host->dev);
pci_read_config_byte(pdev, CS5535_CABLE_DETECT, &cable);
if (cable & 1)
return ATA_CBL_PATA80;
else
return ATA_CBL_PATA40;
}
static void cs5535_set_piomode(struct ata_port *ap, struct ata_device *adev)
{
static const u16 pio_timings[5] = {
0xF7F4, 0xF173, 0x8141, 0x5131, 0x1131
};
static const u16 pio_cmd_timings[5] = {
0xF7F4, 0x53F3, 0x13F1, 0x5131, 0x1131
};
u32 reg, dummy;
struct ata_device *pair = ata_dev_pair(adev);
int mode = adev->pio_mode - XFER_PIO_0;
int cmdmode = mode;
if (pair) {
int pairmode = pair->pio_mode - XFER_PIO_0;
cmdmode = min(mode, pairmode);
if (cmdmode < pairmode)
wrmsr(ATAC_CH0D0_PIO + 2 * pair->devno,
pio_cmd_timings[cmdmode] << 16 | pio_timings[pairmode], 0);
}
wrmsr(ATAC_CH0D0_PIO + 2 * adev->devno,
pio_cmd_timings[cmdmode] << 16 | pio_timings[mode], 0);
rdmsr(ATAC_CH0D0_DMA + 2 * adev->devno, reg, dummy);
wrmsr(ATAC_CH0D0_DMA + 2 * adev->devno, reg | 0x80000000UL, 0);
}
static void cs5535_set_dmamode(struct ata_port *ap, struct ata_device *adev)
{
static const u32 udma_timings[5] = {
0x7F7436A1, 0x7F733481, 0x7F723261, 0x7F713161, 0x7F703061
};
static const u32 mwdma_timings[3] = {
0x7F0FFFF3, 0x7F035352, 0x7F024241
};
u32 reg, dummy;
int mode = adev->dma_mode;
rdmsr(ATAC_CH0D0_DMA + 2 * adev->devno, reg, dummy);
reg &= 0x80000000UL;
if (mode >= XFER_UDMA_0)
reg |= udma_timings[mode - XFER_UDMA_0];
else
reg |= mwdma_timings[mode - XFER_MW_DMA_0];
wrmsr(ATAC_CH0D0_DMA + 2 * adev->devno, reg, 0);
}
static int cs5535_init_one(struct pci_dev *dev, const struct pci_device_id *id)
{
static const struct ata_port_info info = {
.flags = ATA_FLAG_SLAVE_POSS,
.pio_mask = ATA_PIO4,
.mwdma_mask = ATA_MWDMA2,
.udma_mask = ATA_UDMA4,
.port_ops = &cs5535_port_ops
};
const struct ata_port_info *ppi[] = { &info, &ata_dummy_port_info };
u32 timings, dummy;
rdmsr(ATAC_CH0D0_PIO, timings, dummy);
if (CS5535_BAD_PIO(timings))
wrmsr(ATAC_CH0D0_PIO, 0xF7F4F7F4UL, 0);
rdmsr(ATAC_CH0D1_PIO, timings, dummy);
if (CS5535_BAD_PIO(timings))
wrmsr(ATAC_CH0D1_PIO, 0xF7F4F7F4UL, 0);
return ata_pci_bmdma_init_one(dev, ppi, &cs5535_sht, NULL, 0);
}
static int __init cs5535_init(void)
{
return pci_register_driver(&cs5535_pci_driver);
}
static void __exit cs5535_exit(void)
{
pci_unregister_driver(&cs5535_pci_driver);
}
