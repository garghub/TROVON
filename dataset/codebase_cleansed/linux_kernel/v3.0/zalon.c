static int __init
zalon_probe(struct parisc_device *dev)
{
struct gsc_irq gsc_irq;
u32 zalon_vers;
int error = -ENODEV;
void __iomem *zalon = ioremap_nocache(dev->hpa.start, 4096);
void __iomem *io_port = zalon + GSC_SCSI_ZALON_OFFSET;
static int unit = 0;
struct Scsi_Host *host;
struct ncr_device device;
__raw_writel(CMD_RESET, zalon + IO_MODULE_IO_COMMAND);
while (!(__raw_readl(zalon + IO_MODULE_IO_STATUS) & IOSTATUS_RY))
cpu_relax();
__raw_writel(IOIIDATA_MINT5EN | IOIIDATA_PACKEN | IOIIDATA_PREFETCHEN,
zalon + IO_MODULE_II_CDATA);
zalon_vers = (__raw_readl(zalon + IO_MODULE_II_CDATA) >> 24) & 0x07;
dev->irq = gsc_alloc_irq(&gsc_irq);
printk(KERN_INFO "%s: Zalon version %d, IRQ %d\n", __func__,
zalon_vers, dev->irq);
__raw_writel(gsc_irq.txn_addr | gsc_irq.txn_data, zalon + IO_MODULE_EIM);
if (zalon_vers == 0)
printk(KERN_WARNING "%s: Zalon 1.1 or earlier\n", __func__);
memset(&device, 0, sizeof(struct ncr_device));
__raw_writeb(0x20, io_port + 0x38);
__raw_writeb(0x04, io_port + 0x1b);
__raw_writeb(0x80, io_port + 0x22);
device.chip = zalon720_chip;
device.host_id = 7;
device.dev = &dev->dev;
device.slot.base = dev->hpa.start + GSC_SCSI_ZALON_OFFSET;
device.slot.base_v = io_port;
device.slot.irq = dev->irq;
device.differential = 2;
host = ncr_attach(&zalon7xx_template, unit, &device);
if (!host)
return -ENODEV;
if (request_irq(dev->irq, ncr53c8xx_intr, IRQF_SHARED, "zalon", host)) {
dev_printk(KERN_ERR, &dev->dev, "irq problem with %d, detaching\n ",
dev->irq);
goto fail;
}
unit++;
dev_set_drvdata(&dev->dev, host);
error = scsi_add_host(host, &dev->dev);
if (error)
goto fail_free_irq;
scsi_scan_host(host);
return 0;
fail_free_irq:
free_irq(dev->irq, host);
fail:
ncr53c8xx_release(host);
return error;
}
static int __exit zalon_remove(struct parisc_device *dev)
{
struct Scsi_Host *host = dev_get_drvdata(&dev->dev);
scsi_remove_host(host);
ncr53c8xx_release(host);
free_irq(dev->irq, host);
return 0;
}
static int __init zalon7xx_init(void)
{
int ret = ncr53c8xx_init();
if (!ret)
ret = register_parisc_driver(&zalon_driver);
if (ret)
ncr53c8xx_exit();
return ret;
}
static void __exit zalon7xx_exit(void)
{
unregister_parisc_driver(&zalon_driver);
ncr53c8xx_exit();
}
