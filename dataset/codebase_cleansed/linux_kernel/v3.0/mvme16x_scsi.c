static __devinit int
mvme16x_probe(struct platform_device *dev)
{
struct Scsi_Host * host = NULL;
struct NCR_700_Host_Parameters *hostdata;
if (!MACH_IS_MVME16x)
goto out;
if (mvme16x_config & MVME16x_CONFIG_NO_SCSICHIP) {
printk(KERN_INFO "mvme16x-scsi: detection disabled, "
"SCSI chip not present\n");
goto out;
}
hostdata = kzalloc(sizeof(struct NCR_700_Host_Parameters), GFP_KERNEL);
if (hostdata == NULL) {
printk(KERN_ERR "mvme16x-scsi: "
"Failed to allocate host data\n");
goto out;
}
hostdata->base = (void __iomem *)0xfff47000UL;
hostdata->clock = 50;
hostdata->chip710 = 1;
hostdata->dmode_extra = DMODE_FC2;
hostdata->dcntl_extra = EA_710;
hostdata->ctest7_extra = CTEST7_TT1;
host = NCR_700_detect(&mvme16x_scsi_driver_template, hostdata,
&dev->dev);
if (!host) {
printk(KERN_ERR "mvme16x-scsi: No host detected; "
"board configuration problem?\n");
goto out_free;
}
host->this_id = 7;
host->base = 0xfff47000UL;
host->irq = MVME16x_IRQ_SCSI;
if (request_irq(host->irq, NCR_700_intr, 0, "mvme16x-scsi", host)) {
printk(KERN_ERR "mvme16x-scsi: request_irq failed\n");
goto out_put_host;
}
{
volatile unsigned long v;
v = in_be32(0xfff4202c);
v = (v & ~0xff) | 0x10 | 4;
out_be32(0xfff4202c, v);
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
mvme16x_device_remove(struct platform_device *dev)
{
struct Scsi_Host *host = platform_get_drvdata(dev);
struct NCR_700_Host_Parameters *hostdata = shost_priv(host);
{
volatile unsigned long v;
v = in_be32(0xfff4202c);
v &= ~0x10;
out_be32(0xfff4202c, v);
}
scsi_remove_host(host);
NCR_700_release(host);
kfree(hostdata);
free_irq(host->irq, host);
return 0;
}
static int __init mvme16x_scsi_init(void)
{
int err;
err = platform_driver_register(&mvme16x_scsi_driver);
if (err)
return err;
mvme16x_scsi_device = platform_device_register_simple("mvme16x-scsi",
-1, NULL, 0);
if (IS_ERR(mvme16x_scsi_device)) {
platform_driver_unregister(&mvme16x_scsi_driver);
return PTR_ERR(mvme16x_scsi_device);
}
return 0;
}
static void __exit mvme16x_scsi_exit(void)
{
platform_device_unregister(mvme16x_scsi_device);
platform_driver_unregister(&mvme16x_scsi_driver);
}
