static int __init
lasi700_probe(struct parisc_device *dev)
{
unsigned long base = dev->hpa.start + LASI_SCSI_CORE_OFFSET;
struct NCR_700_Host_Parameters *hostdata;
struct Scsi_Host *host;
hostdata = kzalloc(sizeof(*hostdata), GFP_KERNEL);
if (!hostdata) {
dev_printk(KERN_ERR, &dev->dev, "Failed to allocate host data\n");
return -ENOMEM;
}
hostdata->dev = &dev->dev;
dma_set_mask(&dev->dev, DMA_BIT_MASK(32));
hostdata->base = ioremap_nocache(base, 0x100);
hostdata->differential = 0;
if (dev->id.sversion == LASI_700_SVERSION) {
hostdata->clock = LASI700_CLOCK;
hostdata->force_le_on_be = 1;
} else {
hostdata->clock = LASI710_CLOCK;
hostdata->force_le_on_be = 0;
hostdata->chip710 = 1;
hostdata->dmode_extra = DMODE_FC2;
hostdata->burst_length = 8;
}
host = NCR_700_detect(&lasi700_template, hostdata, &dev->dev);
if (!host)
goto out_kfree;
host->this_id = 7;
host->base = base;
host->irq = dev->irq;
if(request_irq(dev->irq, NCR_700_intr, IRQF_SHARED, "lasi700", host)) {
printk(KERN_ERR "lasi700: request_irq failed!\n");
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
static int __exit
lasi700_driver_remove(struct parisc_device *dev)
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
static int __init
lasi700_init(void)
{
return register_parisc_driver(&lasi700_driver);
}
static void __exit
lasi700_exit(void)
{
unregister_parisc_driver(&lasi700_driver);
}
