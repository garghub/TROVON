static int adl_pci7296_attach(struct comedi_device *dev,
struct comedi_devconfig *it)
{
struct pci_dev *pcidev = NULL;
struct comedi_subdevice *s;
int bus, slot;
int ret;
printk(KERN_INFO "comedi%d: attach adl_pci7432\n", dev->minor);
dev->board_name = "pci7432";
bus = it->options[0];
slot = it->options[1];
if (alloc_private(dev, sizeof(struct adl_pci7296_private)) < 0)
return -ENOMEM;
if (alloc_subdevices(dev, 4) < 0)
return -ENOMEM;
for_each_pci_dev(pcidev) {
if (pcidev->vendor == PCI_VENDOR_ID_ADLINK &&
pcidev->device == PCI_DEVICE_ID_PCI7296) {
if (bus || slot) {
if (pcidev->bus->number != bus
|| PCI_SLOT(pcidev->devfn) != slot) {
continue;
}
}
devpriv->pci_dev = pcidev;
if (comedi_pci_enable(pcidev, "adl_pci7296") < 0) {
printk(KERN_ERR "comedi%d: Failed to enable PCI device and request regions\n",
dev->minor);
return -EIO;
}
dev->iobase = pci_resource_start(pcidev, 2);
printk(KERN_INFO "comedi: base addr %4lx\n",
dev->iobase);
s = dev->subdevices + 0;
subdev_8255_init(dev, s, NULL,
(unsigned long)(dev->iobase));
s = dev->subdevices + 1;
ret = subdev_8255_init(dev, s, NULL,
(unsigned long)(dev->iobase +
PORT2A));
if (ret < 0)
return ret;
s = dev->subdevices + 2;
ret = subdev_8255_init(dev, s, NULL,
(unsigned long)(dev->iobase +
PORT3A));
if (ret < 0)
return ret;
s = dev->subdevices + 3;
ret = subdev_8255_init(dev, s, NULL,
(unsigned long)(dev->iobase +
PORT4A));
if (ret < 0)
return ret;
printk(KERN_DEBUG "comedi%d: adl_pci7432 attached\n",
dev->minor);
return 1;
}
}
printk(KERN_ERR "comedi%d: no supported board found! (req. bus/slot : %d/%d)\n",
dev->minor, bus, slot);
return -EIO;
}
static void adl_pci7296_detach(struct comedi_device *dev)
{
if (devpriv && devpriv->pci_dev) {
if (dev->iobase)
comedi_pci_disable(devpriv->pci_dev);
pci_dev_put(devpriv->pci_dev);
}
if (dev->subdevices) {
subdev_8255_cleanup(dev, dev->subdevices + 0);
subdev_8255_cleanup(dev, dev->subdevices + 1);
subdev_8255_cleanup(dev, dev->subdevices + 2);
subdev_8255_cleanup(dev, dev->subdevices + 3);
}
}
static int __devinit adl_pci7296_pci_probe(struct pci_dev *dev,
const struct pci_device_id *ent)
{
return comedi_pci_auto_config(dev, &adl_pci7296_driver);
}
static void __devexit adl_pci7296_pci_remove(struct pci_dev *dev)
{
comedi_pci_auto_unconfig(dev);
}
