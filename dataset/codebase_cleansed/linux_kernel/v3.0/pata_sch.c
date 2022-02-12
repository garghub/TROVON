static void sch_set_piomode(struct ata_port *ap, struct ata_device *adev)
{
unsigned int pio = adev->pio_mode - XFER_PIO_0;
struct pci_dev *dev = to_pci_dev(ap->host->dev);
unsigned int port = adev->devno ? D1TIM : D0TIM;
unsigned int data;
pci_read_config_dword(dev, port, &data);
data &= ~(PM | PPE);
data |= pio;
if (adev->class == ATA_DEV_ATA)
data |= PPE;
pci_write_config_dword(dev, port, data);
}
static void sch_set_dmamode(struct ata_port *ap, struct ata_device *adev)
{
unsigned int dma_mode = adev->dma_mode;
struct pci_dev *dev = to_pci_dev(ap->host->dev);
unsigned int port = adev->devno ? D1TIM : D0TIM;
unsigned int data;
pci_read_config_dword(dev, port, &data);
if (dma_mode >= XFER_UDMA_0) {
data |= USD;
data &= ~UDM;
data |= (dma_mode - XFER_UDMA_0) << 16;
} else {
data &= ~(USD | MDM);
data |= (dma_mode - XFER_MW_DMA_0) << 8;
}
pci_write_config_dword(dev, port, data);
}
static int __devinit sch_init_one(struct pci_dev *pdev,
const struct pci_device_id *ent)
{
static int printed_version;
const struct ata_port_info *ppi[] = { &sch_port_info, NULL };
if (!printed_version++)
dev_printk(KERN_DEBUG, &pdev->dev,
"version " DRV_VERSION "\n");
return ata_pci_bmdma_init_one(pdev, ppi, &sch_sht, NULL, 0);
}
static int __init sch_init(void)
{
return pci_register_driver(&sch_pci_driver);
}
static void __exit sch_exit(void)
{
pci_unregister_driver(&sch_pci_driver);
}
