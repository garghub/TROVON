static int pcidio_attach(struct comedi_device *dev, struct comedi_devconfig *it)
{
struct pci_dev *pcidev = NULL;
int index;
int i;
printk("comedi%d: cb_pcidio: \n", dev->minor);
if (alloc_private(dev, sizeof(struct pcidio_private)) < 0)
return -ENOMEM;
for_each_pci_dev(pcidev) {
if (pcidev->vendor != PCI_VENDOR_ID_CB)
continue;
for (index = 0; index < ARRAY_SIZE(pcidio_boards); index++) {
if (pcidio_boards[index].dev_id != pcidev->device)
continue;
if (it->options[0] || it->options[1]) {
if (pcidev->bus->number != it->options[0] ||
PCI_SLOT(pcidev->devfn) != it->options[1]) {
continue;
}
}
dev->board_ptr = pcidio_boards + index;
goto found;
}
}
printk("No supported ComputerBoards/MeasurementComputing card found on "
"requested position\n");
return -EIO;
found:
dev->board_name = thisboard->name;
devpriv->pci_dev = pcidev;
printk("Found %s on bus %i, slot %i\n", thisboard->name,
devpriv->pci_dev->bus->number,
PCI_SLOT(devpriv->pci_dev->devfn));
if (comedi_pci_enable(pcidev, thisboard->name)) {
printk
("cb_pcidio: failed to enable PCI device and request regions\n");
return -EIO;
}
devpriv->dio_reg_base
=
pci_resource_start(devpriv->pci_dev,
pcidio_boards[index].dioregs_badrindex);
if (alloc_subdevices(dev, thisboard->n_8255) < 0)
return -ENOMEM;
for (i = 0; i < thisboard->n_8255; i++) {
subdev_8255_init(dev, dev->subdevices + i,
NULL, devpriv->dio_reg_base + i * 4);
printk(" subdev %d: base = 0x%lx\n", i,
devpriv->dio_reg_base + i * 4);
}
printk("attached\n");
return 1;
}
static int pcidio_detach(struct comedi_device *dev)
{
printk("comedi%d: cb_pcidio: remove\n", dev->minor);
if (devpriv) {
if (devpriv->pci_dev) {
if (devpriv->dio_reg_base)
comedi_pci_disable(devpriv->pci_dev);
pci_dev_put(devpriv->pci_dev);
}
}
if (dev->subdevices) {
int i;
for (i = 0; i < thisboard->n_8255; i++)
subdev_8255_cleanup(dev, dev->subdevices + i);
}
return 0;
}
static int __devinit driver_cb_pcidio_pci_probe(struct pci_dev *dev,
const struct pci_device_id *ent)
{
return comedi_pci_auto_config(dev, driver_cb_pcidio.driver_name);
}
static void __devexit driver_cb_pcidio_pci_remove(struct pci_dev *dev)
{
comedi_pci_auto_unconfig(dev);
}
static int __init driver_cb_pcidio_init_module(void)
{
int retval;
retval = comedi_driver_register(&driver_cb_pcidio);
if (retval < 0)
return retval;
driver_cb_pcidio_pci_driver.name = (char *)driver_cb_pcidio.driver_name;
return pci_register_driver(&driver_cb_pcidio_pci_driver);
}
static void __exit driver_cb_pcidio_cleanup_module(void)
{
pci_unregister_driver(&driver_cb_pcidio_pci_driver);
comedi_driver_unregister(&driver_cb_pcidio);
}
