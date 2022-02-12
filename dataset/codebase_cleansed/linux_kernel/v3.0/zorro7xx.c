static int __devinit zorro7xx_init_one(struct zorro_dev *z,
const struct zorro_device_id *ent)
{
struct Scsi_Host *host;
struct NCR_700_Host_Parameters *hostdata;
struct zorro_driver_data *zdd;
unsigned long board, ioaddr;
board = zorro_resource_start(z);
zdd = (struct zorro_driver_data *)ent->driver_data;
if (zdd->absolute) {
ioaddr = zdd->offset;
} else {
ioaddr = board + zdd->offset;
}
if (!zorro_request_device(z, zdd->name)) {
printk(KERN_ERR "zorro7xx: cannot reserve region 0x%lx, abort\n",
board);
return -EBUSY;
}
hostdata = kzalloc(sizeof(struct NCR_700_Host_Parameters), GFP_KERNEL);
if (!hostdata) {
printk(KERN_ERR "zorro7xx: Failed to allocate host data\n");
goto out_release;
}
if (ioaddr > 0x01000000)
hostdata->base = ioremap(ioaddr, zorro_resource_len(z));
else
hostdata->base = (void __iomem *)ZTWO_VADDR(ioaddr);
hostdata->clock = 50;
hostdata->chip710 = 1;
hostdata->ctest7_extra = CTEST7_TT1;
zorro7xx_scsi_driver_template.name = zdd->name;
host = NCR_700_detect(&zorro7xx_scsi_driver_template, hostdata,
&z->dev);
if (!host) {
printk(KERN_ERR "zorro7xx: No host detected; "
"board configuration problem?\n");
goto out_free;
}
host->this_id = 7;
host->base = ioaddr;
host->irq = IRQ_AMIGA_PORTS;
if (request_irq(host->irq, NCR_700_intr, IRQF_SHARED, "zorro7xx-scsi",
host)) {
printk(KERN_ERR "zorro7xx: request_irq failed\n");
goto out_put_host;
}
zorro_set_drvdata(z, host);
scsi_scan_host(host);
return 0;
out_put_host:
scsi_host_put(host);
out_free:
if (ioaddr > 0x01000000)
iounmap(hostdata->base);
kfree(hostdata);
out_release:
zorro_release_device(z);
return -ENODEV;
}
static __devexit void zorro7xx_remove_one(struct zorro_dev *z)
{
struct Scsi_Host *host = zorro_get_drvdata(z);
struct NCR_700_Host_Parameters *hostdata = shost_priv(host);
scsi_remove_host(host);
NCR_700_release(host);
kfree(hostdata);
free_irq(host->irq, host);
zorro_release_device(z);
}
static int __init zorro7xx_scsi_init(void)
{
return zorro_register_driver(&zorro7xx_driver);
}
static void __exit zorro7xx_scsi_exit(void)
{
zorro_unregister_driver(&zorro7xx_driver);
}
