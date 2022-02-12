static int dmx3191d_probe_one(struct pci_dev *pdev,
const struct pci_device_id *id)
{
struct Scsi_Host *shost;
unsigned long io;
int error = -ENODEV;
if (pci_enable_device(pdev))
goto out;
io = pci_resource_start(pdev, 0);
if (!request_region(io, DMX3191D_REGION_LEN, DMX3191D_DRIVER_NAME)) {
printk(KERN_ERR "dmx3191: region 0x%lx-0x%lx already reserved\n",
io, io + DMX3191D_REGION_LEN);
goto out_disable_device;
}
shost = scsi_host_alloc(&dmx3191d_driver_template,
sizeof(struct NCR5380_hostdata));
if (!shost)
goto out_release_region;
shost->io_port = io;
shost->irq = NO_IRQ;
error = NCR5380_init(shost, 0);
if (error)
goto out_host_put;
NCR5380_maybe_reset_bus(shost);
pci_set_drvdata(pdev, shost);
error = scsi_add_host(shost, &pdev->dev);
if (error)
goto out_exit;
scsi_scan_host(shost);
return 0;
out_exit:
NCR5380_exit(shost);
out_host_put:
scsi_host_put(shost);
out_release_region:
release_region(io, DMX3191D_REGION_LEN);
out_disable_device:
pci_disable_device(pdev);
out:
return error;
}
static void dmx3191d_remove_one(struct pci_dev *pdev)
{
struct Scsi_Host *shost = pci_get_drvdata(pdev);
unsigned long io = shost->io_port;
scsi_remove_host(shost);
NCR5380_exit(shost);
scsi_host_put(shost);
release_region(io, DMX3191D_REGION_LEN);
pci_disable_device(pdev);
}
static int __init dmx3191d_init(void)
{
return pci_register_driver(&dmx3191d_pci_driver);
}
static void __exit dmx3191d_exit(void)
{
pci_unregister_driver(&dmx3191d_pci_driver);
}
