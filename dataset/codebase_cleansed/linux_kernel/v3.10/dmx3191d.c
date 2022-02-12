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
shost->irq = pdev->irq;
NCR5380_init(shost, FLAG_NO_PSEUDO_DMA | FLAG_DTC3181E);
if (request_irq(pdev->irq, NCR5380_intr, IRQF_SHARED,
DMX3191D_DRIVER_NAME, shost)) {
printk(KERN_WARNING "dmx3191: IRQ %d not available - "
"switching to polled mode.\n", pdev->irq);
shost->irq = SCSI_IRQ_NONE;
}
pci_set_drvdata(pdev, shost);
error = scsi_add_host(shost, &pdev->dev);
if (error)
goto out_free_irq;
scsi_scan_host(shost);
return 0;
out_free_irq:
free_irq(shost->irq, shost);
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
scsi_remove_host(shost);
NCR5380_exit(shost);
if (shost->irq != SCSI_IRQ_NONE)
free_irq(shost->irq, shost);
release_region(shost->io_port, DMX3191D_REGION_LEN);
pci_disable_device(pdev);
scsi_host_put(shost);
}
static int __init dmx3191d_init(void)
{
return pci_register_driver(&dmx3191d_pci_driver);
}
static void __exit dmx3191d_exit(void)
{
pci_unregister_driver(&dmx3191d_pci_driver);
}
