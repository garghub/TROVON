static void ninja32_set_piomode(struct ata_port *ap, struct ata_device *adev)
{
static u16 pio_timing[5] = {
0xd6, 0x85, 0x44, 0x33, 0x13
};
iowrite8(pio_timing[adev->pio_mode - XFER_PIO_0],
ap->ioaddr.bmdma_addr + 0x1f);
ap->private_data = adev;
}
static void ninja32_dev_select(struct ata_port *ap, unsigned int device)
{
struct ata_device *adev = &ap->link.device[device];
if (ap->private_data != adev) {
iowrite8(0xd6, ap->ioaddr.bmdma_addr + 0x1f);
ata_sff_dev_select(ap, device);
ninja32_set_piomode(ap, adev);
}
}
static void ninja32_program(void __iomem *base)
{
iowrite8(0x05, base + 0x01);
iowrite8(0xBE, base + 0x02);
iowrite8(0x01, base + 0x03);
iowrite8(0x20, base + 0x04);
iowrite8(0x8f, base + 0x05);
iowrite8(0xa4, base + 0x1c);
iowrite8(0x83, base + 0x1d);
}
static int ninja32_init_one(struct pci_dev *dev, const struct pci_device_id *id)
{
struct ata_host *host;
struct ata_port *ap;
void __iomem *base;
int rc;
host = ata_host_alloc(&dev->dev, 1);
if (!host)
return -ENOMEM;
ap = host->ports[0];
rc = pcim_enable_device(dev);
if (rc)
return rc;
rc = pcim_iomap_regions(dev, 1 << 0, DRV_NAME);
if (rc == -EBUSY)
pcim_pin_device(dev);
if (rc)
return rc;
host->iomap = pcim_iomap_table(dev);
rc = dma_set_mask(&dev->dev, ATA_DMA_MASK);
if (rc)
return rc;
rc = dma_set_coherent_mask(&dev->dev, ATA_DMA_MASK);
if (rc)
return rc;
pci_set_master(dev);
base = host->iomap[0];
if (!base)
return -ENOMEM;
ap->ops = &ninja32_port_ops;
ap->pio_mask = ATA_PIO4;
ap->flags |= ATA_FLAG_SLAVE_POSS;
ap->ioaddr.cmd_addr = base + 0x10;
ap->ioaddr.ctl_addr = base + 0x1E;
ap->ioaddr.altstatus_addr = base + 0x1E;
ap->ioaddr.bmdma_addr = base;
ata_sff_std_ports(&ap->ioaddr);
ap->pflags |= ATA_PFLAG_PIO32 | ATA_PFLAG_PIO32CHANGE;
ninja32_program(base);
return ata_host_activate(host, dev->irq, ata_bmdma_interrupt,
IRQF_SHARED, &ninja32_sht);
}
static int ninja32_reinit_one(struct pci_dev *pdev)
{
struct ata_host *host = pci_get_drvdata(pdev);
int rc;
rc = ata_pci_device_do_resume(pdev);
if (rc)
return rc;
ninja32_program(host->iomap[0]);
ata_host_resume(host);
return 0;
}
