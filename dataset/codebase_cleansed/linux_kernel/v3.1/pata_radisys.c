static void radisys_set_piomode (struct ata_port *ap, struct ata_device *adev)
{
unsigned int pio = adev->pio_mode - XFER_PIO_0;
struct pci_dev *dev = to_pci_dev(ap->host->dev);
u16 idetm_data;
int control = 0;
static const
u8 timings[][2] = { { 0, 0 },
{ 0, 0 },
{ 1, 1 },
{ 2, 2 },
{ 3, 3 }, };
if (pio > 0)
control |= 1;
if (ata_pio_need_iordy(adev))
control |= 2;
pci_read_config_word(dev, 0x40, &idetm_data);
idetm_data &= 0xCCCC;
idetm_data |= (control << (4 * adev->devno));
idetm_data |= (timings[pio][0] << 12) |
(timings[pio][1] << 8);
pci_write_config_word(dev, 0x40, idetm_data);
ap->private_data = adev;
}
static void radisys_set_dmamode (struct ata_port *ap, struct ata_device *adev)
{
struct pci_dev *dev = to_pci_dev(ap->host->dev);
u16 idetm_data;
u8 udma_enable;
static const
u8 timings[][2] = { { 0, 0 },
{ 0, 0 },
{ 1, 1 },
{ 2, 2 },
{ 3, 3 }, };
pci_read_config_word(dev, 0x40, &idetm_data);
pci_read_config_byte(dev, 0x48, &udma_enable);
if (adev->dma_mode < XFER_UDMA_0) {
unsigned int mwdma = adev->dma_mode - XFER_MW_DMA_0;
const unsigned int needed_pio[3] = {
XFER_PIO_0, XFER_PIO_3, XFER_PIO_4
};
int pio = needed_pio[mwdma] - XFER_PIO_0;
int control = 3;
if (adev->pio_mode < needed_pio[mwdma])
control = 1;
idetm_data &= 0xCCCC;
idetm_data |= control << (4 * adev->devno);
idetm_data |= (timings[pio][0] << 12) | (timings[pio][1] << 8);
udma_enable &= ~(1 << adev->devno);
} else {
u8 udma_mode;
pci_read_config_byte(dev, 0x4A, &udma_mode);
if (adev->xfer_mode == XFER_UDMA_2)
udma_mode &= ~(2 << (adev->devno * 4));
else
udma_mode |= (2 << (adev->devno * 4));
pci_write_config_byte(dev, 0x4A, udma_mode);
udma_enable |= (1 << adev->devno);
}
pci_write_config_word(dev, 0x40, idetm_data);
pci_write_config_byte(dev, 0x48, udma_enable);
ap->private_data = adev;
}
static unsigned int radisys_qc_issue(struct ata_queued_cmd *qc)
{
struct ata_port *ap = qc->ap;
struct ata_device *adev = qc->dev;
if (adev != ap->private_data) {
if (adev->dma_mode < XFER_UDMA_0) {
if (adev->dma_mode)
radisys_set_dmamode(ap, adev);
else if (adev->pio_mode)
radisys_set_piomode(ap, adev);
}
}
return ata_bmdma_qc_issue(qc);
}
static int radisys_init_one (struct pci_dev *pdev, const struct pci_device_id *ent)
{
static const struct ata_port_info info = {
.flags = ATA_FLAG_SLAVE_POSS,
.pio_mask = ATA_PIO4,
.mwdma_mask = ATA_MWDMA12_ONLY,
.udma_mask = ATA_UDMA24_ONLY,
.port_ops = &radisys_pata_ops,
};
const struct ata_port_info *ppi[] = { &info, NULL };
ata_print_version_once(&pdev->dev, DRV_VERSION);
return ata_pci_bmdma_init_one(pdev, ppi, &radisys_sht, NULL, 0);
}
static int __init radisys_init(void)
{
return pci_register_driver(&radisys_pci_driver);
}
static void __exit radisys_exit(void)
{
pci_unregister_driver(&radisys_pci_driver);
}
