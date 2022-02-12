static __devinit int
bvme6000_probe(struct platform_device *dev)
{
struct Scsi_Host *host;
struct NCR_700_Host_Parameters *hostdata;
if (!MACH_IS_BVME6000)
goto out;
hostdata = kzalloc(sizeof(struct NCR_700_Host_Parameters), GFP_KERNEL);
if (!hostdata) {
printk(KERN_ERR "bvme6000-scsi: "
"Failed to allocate host data\n");
goto out;
}
hostdata->base = (void __iomem *)BVME_NCR53C710_BASE;
hostdata->clock = 40;
hostdata->chip710 = 1;
hostdata->dmode_extra = DMODE_FC2;
hostdata->dcntl_extra = EA_710;
hostdata->ctest7_extra = CTEST7_TT1;
host = NCR_700_detect(&bvme6000_scsi_driver_template, hostdata,
&dev->dev);
if (!host) {
printk(KERN_ERR "bvme6000-scsi: No host detected; "
"board configuration problem?\n");
goto out_free;
}
host->base = BVME_NCR53C710_BASE;
host->this_id = 7;
host->irq = BVME_IRQ_SCSI;
if (request_irq(BVME_IRQ_SCSI, NCR_700_intr, 0, "bvme6000-scsi",
host)) {
printk(KERN_ERR "bvme6000-scsi: request_irq failed\n");
goto out_put_host;
}
platform_set_drvdata(dev, host);
scsi_scan_host(host);
return 0;
out_put_host:
scsi_host_put(host);
out_free:
kfree(hostdata);
out:
return -ENODEV;
}
static __devexit int
bvme6000_device_remove(struct platform_device *dev)
{
struct Scsi_Host *host = platform_get_drvdata(dev);
struct NCR_700_Host_Parameters *hostdata = shost_priv(host);
scsi_remove_host(host);
NCR_700_release(host);
kfree(hostdata);
free_irq(host->irq, host);
return 0;
}
static int __init bvme6000_scsi_init(void)
{
int err;
err = platform_driver_register(&bvme6000_scsi_driver);
if (err)
return err;
bvme6000_scsi_device = platform_device_register_simple("bvme6000-scsi",
-1, NULL, 0);
if (IS_ERR(bvme6000_scsi_device)) {
platform_driver_unregister(&bvme6000_scsi_driver);
return PTR_ERR(bvme6000_scsi_device);
}
return 0;
}
static void __exit bvme6000_scsi_exit(void)
{
platform_device_unregister(bvme6000_scsi_device);
platform_driver_unregister(&bvme6000_scsi_driver);
}
