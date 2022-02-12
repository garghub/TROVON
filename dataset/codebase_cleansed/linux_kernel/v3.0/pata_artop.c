static int artop6210_pre_reset(struct ata_link *link, unsigned long deadline)
{
struct ata_port *ap = link->ap;
struct pci_dev *pdev = to_pci_dev(ap->host->dev);
const struct pci_bits artop_enable_bits[] = {
{ 0x4AU, 1U, 0x02UL, 0x02UL },
{ 0x4AU, 1U, 0x04UL, 0x04UL },
};
if (!pci_test_config_bits(pdev, &artop_enable_bits[ap->port_no]))
return -ENOENT;
return ata_sff_prereset(link, deadline);
}
static int artop6260_pre_reset(struct ata_link *link, unsigned long deadline)
{
static const struct pci_bits artop_enable_bits[] = {
{ 0x4AU, 1U, 0x02UL, 0x02UL },
{ 0x4AU, 1U, 0x04UL, 0x04UL },
};
struct ata_port *ap = link->ap;
struct pci_dev *pdev = to_pci_dev(ap->host->dev);
if ((pdev->device & 1) &&
!pci_test_config_bits(pdev, &artop_enable_bits[ap->port_no]))
return -ENOENT;
return ata_sff_prereset(link, deadline);
}
static int artop6260_cable_detect(struct ata_port *ap)
{
struct pci_dev *pdev = to_pci_dev(ap->host->dev);
u8 tmp;
pci_read_config_byte(pdev, 0x49, &tmp);
if (tmp & (1 << ap->port_no))
return ATA_CBL_PATA40;
return ATA_CBL_PATA80;
}
static void artop6210_load_piomode(struct ata_port *ap, struct ata_device *adev, unsigned int pio)
{
struct pci_dev *pdev = to_pci_dev(ap->host->dev);
int dn = adev->devno + 2 * ap->port_no;
const u16 timing[2][5] = {
{ 0x0000, 0x000A, 0x0008, 0x0303, 0x0301 },
{ 0x0700, 0x070A, 0x0708, 0x0403, 0x0401 }
};
pci_write_config_word(pdev, 0x40 + 2 * dn, timing[clock][pio]);
}
static void artop6210_set_piomode(struct ata_port *ap, struct ata_device *adev)
{
struct pci_dev *pdev = to_pci_dev(ap->host->dev);
int dn = adev->devno + 2 * ap->port_no;
u8 ultra;
artop6210_load_piomode(ap, adev, adev->pio_mode - XFER_PIO_0);
pci_read_config_byte(pdev, 0x54, &ultra);
ultra &= ~(3 << (2 * dn));
pci_write_config_byte(pdev, 0x54, ultra);
}
static void artop6260_load_piomode (struct ata_port *ap, struct ata_device *adev, unsigned int pio)
{
struct pci_dev *pdev = to_pci_dev(ap->host->dev);
int dn = adev->devno + 2 * ap->port_no;
const u8 timing[2][5] = {
{ 0x00, 0x0A, 0x08, 0x33, 0x31 },
{ 0x70, 0x7A, 0x78, 0x43, 0x41 }
};
pci_write_config_byte(pdev, 0x40 + dn, timing[clock][pio]);
}
static void artop6260_set_piomode(struct ata_port *ap, struct ata_device *adev)
{
struct pci_dev *pdev = to_pci_dev(ap->host->dev);
u8 ultra;
artop6260_load_piomode(ap, adev, adev->pio_mode - XFER_PIO_0);
pci_read_config_byte(pdev, 0x44 + ap->port_no, &ultra);
ultra &= ~(7 << (4 * adev->devno));
pci_write_config_byte(pdev, 0x44 + ap->port_no, ultra);
}
static void artop6210_set_dmamode (struct ata_port *ap, struct ata_device *adev)
{
unsigned int pio;
struct pci_dev *pdev = to_pci_dev(ap->host->dev);
int dn = adev->devno + 2 * ap->port_no;
u8 ultra;
if (adev->dma_mode == XFER_MW_DMA_0)
pio = 1;
else
pio = 4;
artop6210_load_piomode(ap, adev, pio);
pci_read_config_byte(pdev, 0x54, &ultra);
ultra &= ~(3 << (2 * dn));
if (adev->dma_mode >= XFER_UDMA_0) {
u8 mode = (adev->dma_mode - XFER_UDMA_0) + 1 - clock;
if (mode == 0)
mode = 1;
ultra |= (mode << (2 * dn));
}
pci_write_config_byte(pdev, 0x54, ultra);
}
static void artop6260_set_dmamode (struct ata_port *ap, struct ata_device *adev)
{
unsigned int pio = adev->pio_mode - XFER_PIO_0;
struct pci_dev *pdev = to_pci_dev(ap->host->dev);
u8 ultra;
if (adev->dma_mode == XFER_MW_DMA_0)
pio = 1;
else
pio = 4;
artop6260_load_piomode(ap, adev, pio);
pci_read_config_byte(pdev, 0x44 + ap->port_no, &ultra);
ultra &= ~(7 << (4 * adev->devno));
if (adev->dma_mode >= XFER_UDMA_0) {
u8 mode = adev->dma_mode - XFER_UDMA_0 + 1 - clock;
if (mode == 0)
mode = 1;
ultra |= (mode << (4 * adev->devno));
}
pci_write_config_byte(pdev, 0x44 + ap->port_no, ultra);
}
static int artop6210_qc_defer(struct ata_queued_cmd *qc)
{
struct ata_host *host = qc->ap->host;
struct ata_port *alt = host->ports[1 ^ qc->ap->port_no];
int rc;
rc = ata_std_qc_defer(qc);
if (rc != 0)
return rc;
if (alt && alt->qc_active)
return ATA_DEFER_PORT;
return 0;
}
static int artop_init_one (struct pci_dev *pdev, const struct pci_device_id *id)
{
static int printed_version;
static const struct ata_port_info info_6210 = {
.flags = ATA_FLAG_SLAVE_POSS,
.pio_mask = ATA_PIO4,
.mwdma_mask = ATA_MWDMA2,
.udma_mask = ATA_UDMA2,
.port_ops = &artop6210_ops,
};
static const struct ata_port_info info_626x = {
.flags = ATA_FLAG_SLAVE_POSS,
.pio_mask = ATA_PIO4,
.mwdma_mask = ATA_MWDMA2,
.udma_mask = ATA_UDMA4,
.port_ops = &artop6260_ops,
};
static const struct ata_port_info info_628x = {
.flags = ATA_FLAG_SLAVE_POSS,
.pio_mask = ATA_PIO4,
.mwdma_mask = ATA_MWDMA2,
.udma_mask = ATA_UDMA5,
.port_ops = &artop6260_ops,
};
static const struct ata_port_info info_628x_fast = {
.flags = ATA_FLAG_SLAVE_POSS,
.pio_mask = ATA_PIO4,
.mwdma_mask = ATA_MWDMA2,
.udma_mask = ATA_UDMA6,
.port_ops = &artop6260_ops,
};
const struct ata_port_info *ppi[] = { NULL, NULL };
int rc;
if (!printed_version++)
dev_printk(KERN_DEBUG, &pdev->dev,
"version " DRV_VERSION "\n");
rc = pcim_enable_device(pdev);
if (rc)
return rc;
if (id->driver_data == 0) {
ppi[0] = &info_6210;
pci_write_config_byte(pdev, 0x54, 0);
}
else if (id->driver_data == 1)
ppi[0] = &info_626x;
else if (id->driver_data == 2) {
unsigned long io = pci_resource_start(pdev, 4);
u8 reg;
ppi[0] = &info_628x;
if (inb(io) & 0x10)
ppi[0] = &info_628x_fast;
pci_read_config_byte(pdev, 0x49, &reg);
pci_write_config_byte(pdev, 0x49, reg & ~ 0x30);
pci_read_config_byte(pdev, PCI_LATENCY_TIMER, &reg);
if (reg <= 0x80)
pci_write_config_byte(pdev, PCI_LATENCY_TIMER, 0x90);
pci_read_config_byte(pdev, 0x4a, &reg);
pci_write_config_byte(pdev, 0x4a, (reg & ~0x01) | 0x80);
}
BUG_ON(ppi[0] == NULL);
return ata_pci_bmdma_init_one(pdev, ppi, &artop_sht, NULL, 0);
}
static int __init artop_init(void)
{
return pci_register_driver(&artop_pci_driver);
}
static void __exit artop_exit(void)
{
pci_unregister_driver(&artop_pci_driver);
}
