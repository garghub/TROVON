static int pata_platform_set_mode(struct ata_link *link, struct ata_device **unused)
{
struct ata_device *dev;
ata_for_each_dev(dev, link, ENABLED) {
dev->pio_mode = dev->xfer_mode = XFER_PIO_0;
dev->xfer_shift = ATA_SHIFT_PIO;
dev->flags |= ATA_DFLAG_PIO;
ata_dev_info(dev, "configured for PIO\n");
}
return 0;
}
static void pata_platform_setup_port(struct ata_ioports *ioaddr,
unsigned int shift)
{
ioaddr->data_addr = ioaddr->cmd_addr + (ATA_REG_DATA << shift);
ioaddr->error_addr = ioaddr->cmd_addr + (ATA_REG_ERR << shift);
ioaddr->feature_addr = ioaddr->cmd_addr + (ATA_REG_FEATURE << shift);
ioaddr->nsect_addr = ioaddr->cmd_addr + (ATA_REG_NSECT << shift);
ioaddr->lbal_addr = ioaddr->cmd_addr + (ATA_REG_LBAL << shift);
ioaddr->lbam_addr = ioaddr->cmd_addr + (ATA_REG_LBAM << shift);
ioaddr->lbah_addr = ioaddr->cmd_addr + (ATA_REG_LBAH << shift);
ioaddr->device_addr = ioaddr->cmd_addr + (ATA_REG_DEVICE << shift);
ioaddr->status_addr = ioaddr->cmd_addr + (ATA_REG_STATUS << shift);
ioaddr->command_addr = ioaddr->cmd_addr + (ATA_REG_CMD << shift);
}
int __pata_platform_probe(struct device *dev, struct resource *io_res,
struct resource *ctl_res, struct resource *irq_res,
unsigned int ioport_shift, int __pio_mask,
struct scsi_host_template *sht)
{
struct ata_host *host;
struct ata_port *ap;
unsigned int mmio;
int irq = 0;
int irq_flags = 0;
mmio = (( io_res->flags == IORESOURCE_MEM) &&
(ctl_res->flags == IORESOURCE_MEM));
if (irq_res && irq_res->start > 0) {
irq = irq_res->start;
irq_flags = irq_res->flags & IRQF_TRIGGER_MASK;
}
host = ata_host_alloc(dev, 1);
if (!host)
return -ENOMEM;
ap = host->ports[0];
ap->ops = &pata_platform_port_ops;
ap->pio_mask = __pio_mask;
ap->flags |= ATA_FLAG_SLAVE_POSS;
if (!irq) {
ap->flags |= ATA_FLAG_PIO_POLLING;
ata_port_desc(ap, "no IRQ, using PIO polling");
}
if (mmio) {
ap->ioaddr.cmd_addr = devm_ioremap(dev, io_res->start,
resource_size(io_res));
ap->ioaddr.ctl_addr = devm_ioremap(dev, ctl_res->start,
resource_size(ctl_res));
} else {
ap->ioaddr.cmd_addr = devm_ioport_map(dev, io_res->start,
resource_size(io_res));
ap->ioaddr.ctl_addr = devm_ioport_map(dev, ctl_res->start,
resource_size(ctl_res));
}
if (!ap->ioaddr.cmd_addr || !ap->ioaddr.ctl_addr) {
dev_err(dev, "failed to map IO/CTL base\n");
return -ENOMEM;
}
ap->ioaddr.altstatus_addr = ap->ioaddr.ctl_addr;
pata_platform_setup_port(&ap->ioaddr, ioport_shift);
ata_port_desc(ap, "%s cmd 0x%llx ctl 0x%llx", mmio ? "mmio" : "ioport",
(unsigned long long)io_res->start,
(unsigned long long)ctl_res->start);
return ata_host_activate(host, irq, irq ? ata_sff_interrupt : NULL,
irq_flags, sht);
}
static int pata_platform_probe(struct platform_device *pdev)
{
struct resource *io_res;
struct resource *ctl_res;
struct resource *irq_res;
struct pata_platform_info *pp_info = dev_get_platdata(&pdev->dev);
if ((pdev->num_resources != 3) && (pdev->num_resources != 2)) {
dev_err(&pdev->dev, "invalid number of resources\n");
return -EINVAL;
}
io_res = platform_get_resource(pdev, IORESOURCE_IO, 0);
if (io_res == NULL) {
io_res = platform_get_resource(pdev, IORESOURCE_MEM, 0);
if (unlikely(io_res == NULL))
return -EINVAL;
}
ctl_res = platform_get_resource(pdev, IORESOURCE_IO, 1);
if (ctl_res == NULL) {
ctl_res = platform_get_resource(pdev, IORESOURCE_MEM, 1);
if (unlikely(ctl_res == NULL))
return -EINVAL;
}
irq_res = platform_get_resource(pdev, IORESOURCE_IRQ, 0);
return __pata_platform_probe(&pdev->dev, io_res, ctl_res, irq_res,
pp_info ? pp_info->ioport_shift : 0,
pio_mask, &pata_platform_sht);
}
