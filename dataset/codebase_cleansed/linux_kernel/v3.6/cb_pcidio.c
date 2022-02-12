static struct pci_dev *pcidio_find_pci_dev(struct comedi_device *dev,
struct comedi_devconfig *it)
{
struct pci_dev *pcidev = NULL;
int bus = it->options[0];
int slot = it->options[1];
int i;
for_each_pci_dev(pcidev) {
if (bus || slot) {
if (bus != pcidev->bus->number ||
slot != PCI_SLOT(pcidev->devfn))
continue;
}
if (pcidev->vendor != PCI_VENDOR_ID_CB)
continue;
for (i = 0; i < ARRAY_SIZE(pcidio_boards); i++) {
if (pcidio_boards[i].dev_id != pcidev->device)
continue;
dev->board_ptr = pcidio_boards + i;
return pcidev;
}
}
dev_err(dev->class_dev,
"No supported board found! (req. bus %d, slot %d)\n",
bus, slot);
return NULL;
}
static int pcidio_attach(struct comedi_device *dev, struct comedi_devconfig *it)
{
struct pci_dev *pcidev;
int i;
int ret;
pcidev = pcidio_find_pci_dev(dev, it);
if (!pcidev)
return -EIO;
comedi_set_hw_dev(dev, &pcidev->dev);
dev->board_name = thisboard->name;
if (comedi_pci_enable(pcidev, thisboard->name))
return -EIO;
dev->iobase = pci_resource_start(pcidev, thisboard->dioregs_badrindex);
ret = comedi_alloc_subdevices(dev, thisboard->n_8255);
if (ret)
return ret;
for (i = 0; i < thisboard->n_8255; i++) {
subdev_8255_init(dev, dev->subdevices + i,
NULL, dev->iobase + i * 4);
dev_dbg(dev->class_dev, "subdev %d: base = 0x%lx\n", i,
dev->iobase + i * 4);
}
return 1;
}
static void pcidio_detach(struct comedi_device *dev)
{
struct pci_dev *pcidev = comedi_to_pci_dev(dev);
if (pcidev) {
if (dev->iobase)
comedi_pci_disable(pcidev);
pci_dev_put(pcidev);
}
if (dev->subdevices) {
int i;
for (i = 0; i < thisboard->n_8255; i++)
subdev_8255_cleanup(dev, dev->subdevices + i);
}
}
static int __devinit cb_pcidio_pci_probe(struct pci_dev *dev,
const struct pci_device_id *ent)
{
return comedi_pci_auto_config(dev, &cb_pcidio_driver);
}
static void __devexit cb_pcidio_pci_remove(struct pci_dev *dev)
{
comedi_pci_auto_unconfig(dev);
}
