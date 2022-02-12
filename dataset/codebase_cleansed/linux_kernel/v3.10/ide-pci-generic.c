static void netcell_quirkproc(ide_drive_t *drive)
{
drive->id[ATA_ID_CSF_DEFAULT] |= 0x4000;
}
static int generic_init_one(struct pci_dev *dev, const struct pci_device_id *id)
{
const struct ide_port_info *d = &generic_chipsets[id->driver_data];
int ret = -ENODEV;
if (id->driver_data == 0 && ide_generic_all == 0)
goto out;
switch (dev->vendor) {
case PCI_VENDOR_ID_UMC:
if (dev->device == PCI_DEVICE_ID_UMC_UM8886A &&
!(PCI_FUNC(dev->devfn) & 1))
goto out;
break;
case PCI_VENDOR_ID_OPTI:
if (dev->device == PCI_DEVICE_ID_OPTI_82C558 &&
!(PCI_FUNC(dev->devfn) & 1))
goto out;
break;
case PCI_VENDOR_ID_JMICRON:
if (dev->device != PCI_DEVICE_ID_JMICRON_JMB368 &&
PCI_FUNC(dev->devfn) != 1)
goto out;
break;
case PCI_VENDOR_ID_NS:
if (dev->device == PCI_DEVICE_ID_NS_87410 &&
(dev->class >> 8) != PCI_CLASS_STORAGE_IDE)
goto out;
break;
}
if (dev->vendor != PCI_VENDOR_ID_JMICRON) {
u16 command;
pci_read_config_word(dev, PCI_COMMAND, &command);
if (!(command & PCI_COMMAND_IO)) {
printk(KERN_INFO "%s %s: skipping disabled "
"controller\n", d->name, pci_name(dev));
goto out;
}
}
ret = ide_pci_init_one(dev, d, NULL);
out:
return ret;
}
static int __init generic_ide_init(void)
{
return ide_pci_register_driver(&generic_pci_driver);
}
static void __exit generic_ide_exit(void)
{
pci_unregister_driver(&generic_pci_driver);
}
