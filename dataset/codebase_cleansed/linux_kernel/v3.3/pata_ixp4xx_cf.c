static int ixp4xx_set_mode(struct ata_link *link, struct ata_device **error)
{
struct ata_device *dev;
ata_for_each_dev(dev, link, ENABLED) {
ata_dev_info(dev, "configured for PIO0\n");
dev->pio_mode = XFER_PIO_0;
dev->xfer_mode = XFER_PIO_0;
dev->xfer_shift = ATA_SHIFT_PIO;
dev->flags |= ATA_DFLAG_PIO;
}
return 0;
}
static unsigned int ixp4xx_mmio_data_xfer(struct ata_device *dev,
unsigned char *buf, unsigned int buflen, int rw)
{
unsigned int i;
unsigned int words = buflen >> 1;
u16 *buf16 = (u16 *) buf;
struct ata_port *ap = dev->link->ap;
void __iomem *mmio = ap->ioaddr.data_addr;
struct ixp4xx_pata_data *data = ap->host->dev->platform_data;
*data->cs0_cfg &= ~(0x01);
udelay(100);
if (rw == READ)
for (i = 0; i < words; i++)
buf16[i] = readw(mmio);
else
for (i = 0; i < words; i++)
writew(buf16[i], mmio);
if (unlikely(buflen & 0x01)) {
u16 align_buf[1] = { 0 };
unsigned char *trailing_buf = buf + buflen - 1;
if (rw == READ) {
align_buf[0] = readw(mmio);
memcpy(trailing_buf, align_buf, 1);
} else {
memcpy(align_buf, trailing_buf, 1);
writew(align_buf[0], mmio);
}
words++;
}
udelay(100);
*data->cs0_cfg |= 0x01;
return words << 1;
}
static void ixp4xx_setup_port(struct ata_port *ap,
struct ixp4xx_pata_data *data,
unsigned long raw_cs0, unsigned long raw_cs1)
{
struct ata_ioports *ioaddr = &ap->ioaddr;
unsigned long raw_cmd = raw_cs0;
unsigned long raw_ctl = raw_cs1 + 0x06;
ioaddr->cmd_addr = data->cs0;
ioaddr->altstatus_addr = data->cs1 + 0x06;
ioaddr->ctl_addr = data->cs1 + 0x06;
ata_sff_std_ports(ioaddr);
#ifndef __ARMEB__
*(unsigned long *)&ioaddr->data_addr ^= 0x02;
*(unsigned long *)&ioaddr->cmd_addr ^= 0x03;
*(unsigned long *)&ioaddr->altstatus_addr ^= 0x03;
*(unsigned long *)&ioaddr->ctl_addr ^= 0x03;
*(unsigned long *)&ioaddr->error_addr ^= 0x03;
*(unsigned long *)&ioaddr->feature_addr ^= 0x03;
*(unsigned long *)&ioaddr->nsect_addr ^= 0x03;
*(unsigned long *)&ioaddr->lbal_addr ^= 0x03;
*(unsigned long *)&ioaddr->lbam_addr ^= 0x03;
*(unsigned long *)&ioaddr->lbah_addr ^= 0x03;
*(unsigned long *)&ioaddr->device_addr ^= 0x03;
*(unsigned long *)&ioaddr->status_addr ^= 0x03;
*(unsigned long *)&ioaddr->command_addr ^= 0x03;
raw_cmd ^= 0x03;
raw_ctl ^= 0x03;
#endif
ata_port_desc(ap, "cmd 0x%lx ctl 0x%lx", raw_cmd, raw_ctl);
}
static __devinit int ixp4xx_pata_probe(struct platform_device *pdev)
{
unsigned int irq;
struct resource *cs0, *cs1;
struct ata_host *host;
struct ata_port *ap;
struct ixp4xx_pata_data *data = pdev->dev.platform_data;
cs0 = platform_get_resource(pdev, IORESOURCE_MEM, 0);
cs1 = platform_get_resource(pdev, IORESOURCE_MEM, 1);
if (!cs0 || !cs1)
return -EINVAL;
host = ata_host_alloc(&pdev->dev, 1);
if (!host)
return -ENOMEM;
pdev->dev.coherent_dma_mask = DMA_BIT_MASK(32);
data->cs0 = devm_ioremap(&pdev->dev, cs0->start, 0x1000);
data->cs1 = devm_ioremap(&pdev->dev, cs1->start, 0x1000);
if (!data->cs0 || !data->cs1)
return -ENOMEM;
irq = platform_get_irq(pdev, 0);
if (irq)
irq_set_irq_type(irq, IRQ_TYPE_EDGE_RISING);
*data->cs0_cfg = data->cs0_bits;
*data->cs1_cfg = data->cs1_bits;
ap = host->ports[0];
ap->ops = &ixp4xx_port_ops;
ap->pio_mask = ATA_PIO4;
ap->flags |= ATA_FLAG_NO_ATAPI;
ixp4xx_setup_port(ap, data, cs0->start, cs1->start);
ata_print_version_once(&pdev->dev, DRV_VERSION);
return ata_host_activate(host, irq, ata_sff_interrupt, 0, &ixp4xx_sht);
}
static __devexit int ixp4xx_pata_remove(struct platform_device *dev)
{
struct ata_host *host = platform_get_drvdata(dev);
ata_host_detach(host);
return 0;
}
