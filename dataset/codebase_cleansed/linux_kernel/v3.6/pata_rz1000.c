static int rz1000_set_mode(struct ata_link *link, struct ata_device **unused)
{
struct ata_device *dev;
ata_for_each_dev(dev, link, ENABLED) {
dev->pio_mode = XFER_PIO_0;
dev->xfer_mode = XFER_PIO_0;
dev->xfer_shift = ATA_SHIFT_PIO;
dev->flags |= ATA_DFLAG_PIO;
ata_dev_info(dev, "configured for PIO\n");
}
return 0;
}
static int rz1000_fifo_disable(struct pci_dev *pdev)
{
u16 reg;
if (pci_read_config_word(pdev, 0x40, &reg) != 0)
return -1;
reg &= 0xDFFF;
if (pci_write_config_word(pdev, 0x40, reg) != 0)
return -1;
printk(KERN_INFO DRV_NAME ": disabled chipset readahead.\n");
return 0;
}
static int rz1000_init_one (struct pci_dev *pdev, const struct pci_device_id *ent)
{
static const struct ata_port_info info = {
.flags = ATA_FLAG_SLAVE_POSS,
.pio_mask = ATA_PIO4,
.port_ops = &rz1000_port_ops
};
const struct ata_port_info *ppi[] = { &info, NULL };
ata_print_version_once(&pdev->dev, DRV_VERSION);
if (rz1000_fifo_disable(pdev) == 0)
return ata_pci_sff_init_one(pdev, ppi, &rz1000_sht, NULL, 0);
printk(KERN_ERR DRV_NAME ": failed to disable read-ahead on chipset..\n");
return -ENODEV;
}
static int rz1000_reinit_one(struct pci_dev *pdev)
{
struct ata_host *host = dev_get_drvdata(&pdev->dev);
int rc;
rc = ata_pci_device_do_resume(pdev);
if (rc)
return rc;
if (rz1000_fifo_disable(pdev))
panic("rz1000 fifo");
ata_host_resume(host);
return 0;
}
