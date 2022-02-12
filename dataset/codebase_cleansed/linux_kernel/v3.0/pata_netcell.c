static unsigned int netcell_read_id(struct ata_device *adev,
struct ata_taskfile *tf, u16 *id)
{
unsigned int err_mask = ata_do_dev_read_id(adev, tf, id);
if (err_mask == 0)
id[ATA_ID_CSF_DEFAULT] |= 0x4000;
return err_mask;
}
static int netcell_init_one (struct pci_dev *pdev, const struct pci_device_id *ent)
{
static int printed_version;
static const struct ata_port_info info = {
.flags = ATA_FLAG_SLAVE_POSS,
.pio_mask = ATA_PIO4,
.mwdma_mask = ATA_MWDMA2,
.udma_mask = ATA_UDMA5,
.port_ops = &netcell_ops,
};
const struct ata_port_info *port_info[] = { &info, NULL };
int rc;
if (!printed_version++)
dev_printk(KERN_DEBUG, &pdev->dev,
"version " DRV_VERSION "\n");
rc = pcim_enable_device(pdev);
if (rc)
return rc;
ata_pci_bmdma_clear_simplex(pdev);
return ata_pci_bmdma_init_one(pdev, port_info, &netcell_sht, NULL, 0);
}
static int __init netcell_init(void)
{
return pci_register_driver(&netcell_pci_driver);
}
static void __exit netcell_exit(void)
{
pci_unregister_driver(&netcell_pci_driver);
}
