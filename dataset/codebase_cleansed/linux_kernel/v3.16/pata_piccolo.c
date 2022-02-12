static void tosh_set_piomode(struct ata_port *ap, struct ata_device *adev)
{
static const u16 pio[6] = {
0x0566, 0x0433, 0x0311, 0x0201, 0x0200, 0x0100
};
struct pci_dev *pdev = to_pci_dev(ap->host->dev);
u16 conf;
pci_read_config_word(pdev, 0x50, &conf);
conf &= 0xE088;
conf |= pio[adev->pio_mode - XFER_PIO_0];
pci_write_config_word(pdev, 0x50, conf);
}
static void tosh_set_dmamode(struct ata_port *ap, struct ata_device *adev)
{
struct pci_dev *pdev = to_pci_dev(ap->host->dev);
u32 conf;
pci_read_config_dword(pdev, 0x5C, &conf);
conf &= 0x78FFE088;
if (adev->dma_mode >= XFER_UDMA_0) {
int udma = adev->dma_mode - XFER_UDMA_0;
conf |= 0x80000000;
conf |= (udma + 2) << 28;
conf |= (2 - udma) * 0x111;
} else {
static const u32 mwdma[4] = {
0x0655, 0x0200, 0x0200, 0x0100
};
conf |= mwdma[adev->dma_mode - XFER_MW_DMA_0];
}
pci_write_config_dword(pdev, 0x5C, conf);
}
static int ata_tosh_init_one(struct pci_dev *dev, const struct pci_device_id *id)
{
static const struct ata_port_info info = {
.flags = ATA_FLAG_SLAVE_POSS,
.pio_mask = ATA_PIO5,
.mwdma_mask = ATA_MWDMA2,
.udma_mask = ATA_UDMA2,
.port_ops = &tosh_port_ops
};
const struct ata_port_info *ppi[] = { &info, &ata_dummy_port_info };
return ata_pci_bmdma_init_one(dev, ppi, &tosh_sht, NULL, 0);
}
