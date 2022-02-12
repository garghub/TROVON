static int cs5536_read(struct pci_dev *pdev, int reg, u32 *val)
{
if (unlikely(use_msr)) {
u32 dummy __maybe_unused;
rdmsr(MSR_IDE_CFG + reg, *val, dummy);
return 0;
}
return pci_read_config_dword(pdev, PCI_IDE_CFG + reg * 4, val);
}
static int cs5536_write(struct pci_dev *pdev, int reg, int val)
{
if (unlikely(use_msr)) {
wrmsr(MSR_IDE_CFG + reg, val, 0);
return 0;
}
return pci_write_config_dword(pdev, PCI_IDE_CFG + reg * 4, val);
}
static void cs5536_program_dtc(struct ata_device *adev, u8 tim)
{
struct pci_dev *pdev = to_pci_dev(adev->link->ap->host->dev);
int dshift = adev->devno ? IDE_D1_SHIFT : IDE_D0_SHIFT;
u32 dtc;
cs5536_read(pdev, DTC, &dtc);
dtc &= ~(IDE_DRV_MASK << dshift);
dtc |= tim << dshift;
cs5536_write(pdev, DTC, dtc);
}
static int cs5536_cable_detect(struct ata_port *ap)
{
struct pci_dev *pdev = to_pci_dev(ap->host->dev);
u32 cfg;
cs5536_read(pdev, CFG, &cfg);
if (cfg & IDE_CFG_CABLE)
return ATA_CBL_PATA80;
else
return ATA_CBL_PATA40;
}
static void cs5536_set_piomode(struct ata_port *ap, struct ata_device *adev)
{
static const u8 drv_timings[5] = {
0x98, 0x55, 0x32, 0x21, 0x20,
};
static const u8 addr_timings[5] = {
0x2, 0x1, 0x0, 0x0, 0x0,
};
static const u8 cmd_timings[5] = {
0x99, 0x92, 0x90, 0x22, 0x20,
};
struct pci_dev *pdev = to_pci_dev(ap->host->dev);
struct ata_device *pair = ata_dev_pair(adev);
int mode = adev->pio_mode - XFER_PIO_0;
int cmdmode = mode;
int cshift = adev->devno ? IDE_CAST_D1_SHIFT : IDE_CAST_D0_SHIFT;
u32 cast;
if (pair)
cmdmode = min(mode, pair->pio_mode - XFER_PIO_0);
cs5536_program_dtc(adev, drv_timings[mode]);
cs5536_read(pdev, CAST, &cast);
cast &= ~(IDE_CAST_DRV_MASK << cshift);
cast |= addr_timings[mode] << cshift;
cast &= ~(IDE_CAST_CMD_MASK << IDE_CAST_CMD_SHIFT);
cast |= cmd_timings[cmdmode] << IDE_CAST_CMD_SHIFT;
cs5536_write(pdev, CAST, cast);
}
static void cs5536_set_dmamode(struct ata_port *ap, struct ata_device *adev)
{
static const u8 udma_timings[6] = {
0xc2, 0xc1, 0xc0, 0xc4, 0xc5, 0xc6,
};
static const u8 mwdma_timings[3] = {
0x67, 0x21, 0x20,
};
struct pci_dev *pdev = to_pci_dev(ap->host->dev);
u32 etc;
int mode = adev->dma_mode;
int dshift = adev->devno ? IDE_D1_SHIFT : IDE_D0_SHIFT;
cs5536_read(pdev, ETC, &etc);
if (mode >= XFER_UDMA_0) {
etc &= ~(IDE_DRV_MASK << dshift);
etc |= udma_timings[mode - XFER_UDMA_0] << dshift;
} else {
etc &= ~(IDE_ETC_UDMA_MASK << dshift);
cs5536_program_dtc(adev, mwdma_timings[mode - XFER_MW_DMA_0]);
}
cs5536_write(pdev, ETC, etc);
}
static int cs5536_init_one(struct pci_dev *dev, const struct pci_device_id *id)
{
static const struct ata_port_info info = {
.flags = ATA_FLAG_SLAVE_POSS,
.pio_mask = ATA_PIO4,
.mwdma_mask = ATA_MWDMA2,
.udma_mask = ATA_UDMA5,
.port_ops = &cs5536_port_ops,
};
const struct ata_port_info *ppi[] = { &info, &ata_dummy_port_info };
u32 cfg;
if (use_msr)
printk(KERN_ERR DRV_NAME ": Using MSR regs instead of PCI\n");
cs5536_read(dev, CFG, &cfg);
if ((cfg & IDE_CFG_CHANEN) == 0) {
printk(KERN_ERR DRV_NAME ": disabled by BIOS\n");
return -ENODEV;
}
return ata_pci_bmdma_init_one(dev, ppi, &cs5536_sht, NULL, 0);
}
