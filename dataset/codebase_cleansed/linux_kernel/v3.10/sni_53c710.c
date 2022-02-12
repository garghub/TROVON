static int snirm710_probe(struct platform_device *dev)
{
unsigned long base;
struct NCR_700_Host_Parameters *hostdata;
struct Scsi_Host *host;
struct resource *res;
res = platform_get_resource(dev, IORESOURCE_MEM, 0);
if (!res)
return -ENODEV;
base = res->start;
hostdata = kzalloc(sizeof(*hostdata), GFP_KERNEL);
if (!hostdata) {
dev_printk(KERN_ERR, dev, "Failed to allocate host data\n");
return -ENOMEM;
}
hostdata->dev = &dev->dev;
dma_set_mask(&dev->dev, DMA_BIT_MASK(32));
hostdata->base = ioremap_nocache(base, 0x100);
hostdata->differential = 0;
hostdata->clock = SNIRM710_CLOCK;
hostdata->force_le_on_be = 1;
hostdata->chip710 = 1;
hostdata->burst_length = 4;
host = NCR_700_detect(&snirm710_template, hostdata, &dev->dev);
if (!host)
goto out_kfree;
host->this_id = 7;
host->base = base;
host->irq = platform_get_irq(dev, 0);
if(request_irq(host->irq, NCR_700_intr, IRQF_SHARED, "snirm710", host)) {
printk(KERN_ERR "snirm710: request_irq failed!\n");
goto out_put_host;
}
dev_set_drvdata(&dev->dev, host);
scsi_scan_host(host);
return 0;
out_put_host:
scsi_host_put(host);
out_kfree:
iounmap(hostdata->base);
kfree(hostdata);
return -ENODEV;
}
static int __exit snirm710_driver_remove(struct platform_device *dev)
{
struct Scsi_Host *host = dev_get_drvdata(&dev->dev);
struct NCR_700_Host_Parameters *hostdata =
(struct NCR_700_Host_Parameters *)host->hostdata[0];
scsi_remove_host(host);
NCR_700_release(host);
free_irq(host->irq, host);
iounmap(hostdata->base);
kfree(hostdata);
return 0;
}
static int __init snirm710_init(void)
{
return platform_driver_register(&snirm710_driver);
}
static void __exit snirm710_exit(void)
{
platform_driver_unregister(&snirm710_driver);
}
