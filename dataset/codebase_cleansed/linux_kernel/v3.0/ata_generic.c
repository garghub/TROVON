static int generic_set_mode(struct ata_link *link, struct ata_device **unused)
{
struct ata_port *ap = link->ap;
const struct pci_device_id *id = ap->host->private_data;
int dma_enabled = 0;
struct ata_device *dev;
if (id->driver_data & ATA_GEN_FORCE_DMA) {
dma_enabled = 0xff;
} else if (ap->ioaddr.bmdma_addr) {
dma_enabled = ioread8(ap->ioaddr.bmdma_addr + ATA_DMA_STATUS);
}
ata_for_each_dev(dev, link, ENABLED) {
dev->pio_mode = XFER_PIO_0;
dev->dma_mode = XFER_MW_DMA_0;
if (dma_enabled & (1 << (5 + dev->devno))) {
unsigned int xfer_mask = ata_id_xfermask(dev->id);
const char *name;
if (xfer_mask & (ATA_MASK_MWDMA | ATA_MASK_UDMA))
name = ata_mode_string(xfer_mask);
else {
name = "DMA";
xfer_mask |= ata_xfer_mode2mask(XFER_MW_DMA_0);
}
ata_dev_printk(dev, KERN_INFO, "configured for %s\n",
name);
dev->xfer_mode = ata_xfer_mask2mode(xfer_mask);
dev->xfer_shift = ata_xfer_mode2shift(dev->xfer_mode);
dev->flags &= ~ATA_DFLAG_PIO;
} else {
ata_dev_printk(dev, KERN_INFO, "configured for PIO\n");
dev->xfer_mode = XFER_PIO_0;
dev->xfer_shift = ATA_SHIFT_PIO;
dev->flags |= ATA_DFLAG_PIO;
}
}
return 0;
}
static int is_intel_ider(struct pci_dev *dev)
{
u32 r;
u16 t;
pci_read_config_dword(dev, 0xF8, &r);
if (r != 0)
return 0;
pci_read_config_word(dev, 0x40, &t);
if (t != 0)
return 0;
pci_write_config_word(dev, 0x40, 1);
pci_read_config_word(dev, 0x40, &t);
if (t) {
pci_write_config_word(dev, 0x40, 0);
return 0;
}
return 1;
}
static int ata_generic_init_one(struct pci_dev *dev, const struct pci_device_id *id)
{
u16 command;
static const struct ata_port_info info = {
.flags = ATA_FLAG_SLAVE_POSS,
.pio_mask = ATA_PIO4,
.mwdma_mask = ATA_MWDMA2,
.udma_mask = ATA_UDMA5,
.port_ops = &generic_port_ops
};
const struct ata_port_info *ppi[] = { &info, NULL };
if ((id->driver_data & ATA_GEN_CLASS_MATCH) && all_generic_ide == 0)
return -ENODEV;
if (id->driver_data & ATA_GEN_INTEL_IDER)
if (!is_intel_ider(dev))
return -ENODEV;
if (dev->vendor == PCI_VENDOR_ID_UMC &&
dev->device == PCI_DEVICE_ID_UMC_UM8886A &&
(!(PCI_FUNC(dev->devfn) & 1)))
return -ENODEV;
if (dev->vendor == PCI_VENDOR_ID_OPTI &&
dev->device == PCI_DEVICE_ID_OPTI_82C558 &&
(!(PCI_FUNC(dev->devfn) & 1)))
return -ENODEV;
pci_read_config_word(dev, PCI_COMMAND, &command);
if (!(command & PCI_COMMAND_IO))
return -ENODEV;
if (dev->vendor == PCI_VENDOR_ID_AL)
ata_pci_bmdma_clear_simplex(dev);
if (dev->vendor == PCI_VENDOR_ID_ATI) {
int rc = pcim_enable_device(dev);
if (rc < 0)
return rc;
pcim_pin_device(dev);
}
return ata_pci_bmdma_init_one(dev, ppi, &generic_sht, (void *)id, 0);
}
static int __init ata_generic_init(void)
{
return pci_register_driver(&ata_generic_pci_driver);
}
static void __exit ata_generic_exit(void)
{
pci_unregister_driver(&ata_generic_pci_driver);
}
