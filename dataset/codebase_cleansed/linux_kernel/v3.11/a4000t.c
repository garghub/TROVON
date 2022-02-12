static int __init amiga_a4000t_scsi_probe(struct platform_device *pdev)
{
struct resource *res;
phys_addr_t scsi_addr;
struct NCR_700_Host_Parameters *hostdata;
struct Scsi_Host *host;
res = platform_get_resource(pdev, IORESOURCE_MEM, 0);
if (!res)
return -ENODEV;
if (!request_mem_region(res->start, resource_size(res),
"A4000T builtin SCSI"))
return -EBUSY;
hostdata = kzalloc(sizeof(struct NCR_700_Host_Parameters),
GFP_KERNEL);
if (!hostdata) {
dev_err(&pdev->dev, "Failed to allocate host data\n");
goto out_release;
}
scsi_addr = res->start + A4000T_SCSI_OFFSET;
hostdata->base = (void __iomem *)ZTWO_VADDR(scsi_addr);
hostdata->clock = 50;
hostdata->chip710 = 1;
hostdata->dmode_extra = DMODE_FC2;
hostdata->dcntl_extra = EA_710;
host = NCR_700_detect(&a4000t_scsi_driver_template, hostdata,
&pdev->dev);
if (!host) {
dev_err(&pdev->dev,
"No host detected; board configuration problem?\n");
goto out_free;
}
host->this_id = 7;
host->base = scsi_addr;
host->irq = IRQ_AMIGA_PORTS;
if (request_irq(host->irq, NCR_700_intr, IRQF_SHARED, "a4000t-scsi",
host)) {
dev_err(&pdev->dev, "request_irq failed\n");
goto out_put_host;
}
platform_set_drvdata(pdev, host);
scsi_scan_host(host);
return 0;
out_put_host:
scsi_host_put(host);
out_free:
kfree(hostdata);
out_release:
release_mem_region(res->start, resource_size(res));
return -ENODEV;
}
static int __exit amiga_a4000t_scsi_remove(struct platform_device *pdev)
{
struct Scsi_Host *host = platform_get_drvdata(pdev);
struct NCR_700_Host_Parameters *hostdata = shost_priv(host);
struct resource *res = platform_get_resource(pdev, IORESOURCE_MEM, 0);
scsi_remove_host(host);
NCR_700_release(host);
kfree(hostdata);
free_irq(host->irq, host);
release_mem_region(res->start, resource_size(res));
return 0;
}
