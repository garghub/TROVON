static int oldpiix_pre_reset(struct ata_link *link, unsigned long deadline)
{
struct ata_port *ap = link->ap;
struct pci_dev *pdev = to_pci_dev(ap->host->dev);
static const struct pci_bits oldpiix_enable_bits[] = {
{ 0x41U, 1U, 0x80UL, 0x80UL },
{ 0x43U, 1U, 0x80UL, 0x80UL },
};
if (!pci_test_config_bits(pdev, &oldpiix_enable_bits[ap->port_no]))
return -ENOENT;
return ata_sff_prereset(link, deadline);
}
static void oldpiix_set_piomode (struct ata_port *ap, struct ata_device *adev)
{
unsigned int pio = adev->pio_mode - XFER_PIO_0;
struct pci_dev *dev = to_pci_dev(ap->host->dev);
unsigned int idetm_port= ap->port_no ? 0x42 : 0x40;
u16 idetm_data;
int control = 0;
static const
u8 timings[][2] = { { 0, 0 },
{ 0, 0 },
{ 1, 0 },
{ 2, 1 },
{ 2, 3 }, };
if (pio > 1)
control |= 1;
if (ata_pio_need_iordy(adev))
control |= 2;
if (adev->class == ATA_DEV_ATA)
control |= 4;
pci_read_config_word(dev, idetm_port, &idetm_data);
if (adev->devno == 0) {
idetm_data &= 0xCCE0;
idetm_data |= control;
} else {
idetm_data &= 0xCC0E;
idetm_data |= (control << 4);
}
idetm_data |= (timings[pio][0] << 12) |
(timings[pio][1] << 8);
pci_write_config_word(dev, idetm_port, idetm_data);
ap->private_data = adev;
}
static void oldpiix_set_dmamode (struct ata_port *ap, struct ata_device *adev)
{
struct pci_dev *dev = to_pci_dev(ap->host->dev);
u8 idetm_port = ap->port_no ? 0x42 : 0x40;
u16 idetm_data;
static const
u8 timings[][2] = { { 0, 0 },
{ 0, 0 },
{ 1, 0 },
{ 2, 1 },
{ 2, 3 }, };
unsigned int mwdma = adev->dma_mode - XFER_MW_DMA_0;
unsigned int control;
const unsigned int needed_pio[3] = {
XFER_PIO_0, XFER_PIO_3, XFER_PIO_4
};
int pio = needed_pio[mwdma] - XFER_PIO_0;
pci_read_config_word(dev, idetm_port, &idetm_data);
control = 3;
if (adev->class == ATA_DEV_ATA)
control |= 4;
if (adev->pio_mode < needed_pio[mwdma])
control |= 8;
if (adev->devno == 0) {
idetm_data &= 0xCCE0;
idetm_data |= control;
} else {
idetm_data &= 0xCC0E;
idetm_data |= (control << 4);
}
idetm_data |= (timings[pio][0] << 12) | (timings[pio][1] << 8);
pci_write_config_word(dev, idetm_port, idetm_data);
ap->private_data = adev;
}
static unsigned int oldpiix_qc_issue(struct ata_queued_cmd *qc)
{
struct ata_port *ap = qc->ap;
struct ata_device *adev = qc->dev;
if (adev != ap->private_data) {
oldpiix_set_piomode(ap, adev);
if (ata_dma_enabled(adev))
oldpiix_set_dmamode(ap, adev);
}
return ata_bmdma_qc_issue(qc);
}
static int oldpiix_init_one (struct pci_dev *pdev, const struct pci_device_id *ent)
{
static const struct ata_port_info info = {
.flags = ATA_FLAG_SLAVE_POSS,
.pio_mask = ATA_PIO4,
.mwdma_mask = ATA_MWDMA12_ONLY,
.port_ops = &oldpiix_pata_ops,
};
const struct ata_port_info *ppi[] = { &info, NULL };
ata_print_version_once(&pdev->dev, DRV_VERSION);
return ata_pci_bmdma_init_one(pdev, ppi, &oldpiix_sht, NULL, 0);
}
