static int phison_pre_reset(struct ata_link *link, unsigned long deadline)
{
int ret;
struct ata_port *ap = link->ap;
ap->cbl = ATA_CBL_NONE;
ret = ata_std_prereset(link, deadline);
dev_dbg(ap->dev, "phison_pre_reset(), ret = %x\n", ret);
return ret;
}
static int phison_init_one(struct pci_dev *pdev, const struct pci_device_id *id)
{
int ret;
struct ata_port_info info = {
.flags = ATA_FLAG_NO_ATAPI,
.pio_mask = 0x1f,
.mwdma_mask = 0x07,
.udma_mask = ATA_UDMA5,
.port_ops = &phison_ops,
};
const struct ata_port_info *ppi[] = { &info, NULL };
ret = ata_pci_bmdma_init_one(pdev, ppi, &phison_sht, NULL, 0);
dev_dbg(&pdev->dev, "phison_init_one(), ret = %x\n", ret);
return ret;
}
static int __init phison_ide_init(void)
{
return pci_register_driver(&phison_pci_driver);
}
static void __exit phison_ide_exit(void)
{
pci_unregister_driver(&phison_pci_driver);
}
