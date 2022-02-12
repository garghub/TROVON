static int contec_attach(struct comedi_device *dev, struct comedi_devconfig *it)
{
struct pci_dev *pcidev = NULL;
struct comedi_subdevice *s;
printk("comedi%d: contec: ", dev->minor);
dev->board_name = thisboard->name;
if (alloc_private(dev, sizeof(struct contec_private)) < 0)
return -ENOMEM;
if (alloc_subdevices(dev, 2) < 0)
return -ENOMEM;
for_each_pci_dev(pcidev) {
if (pcidev->vendor == PCI_VENDOR_ID_CONTEC &&
pcidev->device == PCI_DEVICE_ID_PIO1616L) {
if (it->options[0] || it->options[1]) {
if (it->options[0] != pcidev->bus->number ||
it->options[1] != PCI_SLOT(pcidev->devfn)) {
continue;
}
}
devpriv->pci_dev = pcidev;
if (comedi_pci_enable(pcidev, "contec_pci_dio")) {
printk
("error enabling PCI device and request regions!\n");
return -EIO;
}
dev->iobase = pci_resource_start(pcidev, 0);
printk(" base addr %lx ", dev->iobase);
dev->board_ptr = contec_boards + 0;
s = dev->subdevices + 0;
s->type = COMEDI_SUBD_DI;
s->subdev_flags = SDF_READABLE;
s->n_chan = 16;
s->maxdata = 1;
s->range_table = &range_digital;
s->insn_bits = contec_di_insn_bits;
s = dev->subdevices + 1;
s->type = COMEDI_SUBD_DO;
s->subdev_flags = SDF_WRITABLE;
s->n_chan = 16;
s->maxdata = 1;
s->range_table = &range_digital;
s->insn_bits = contec_do_insn_bits;
printk("attached\n");
return 1;
}
}
printk("card not present!\n");
return -EIO;
}
static int contec_detach(struct comedi_device *dev)
{
printk("comedi%d: contec: remove\n", dev->minor);
if (devpriv && devpriv->pci_dev) {
if (dev->iobase)
comedi_pci_disable(devpriv->pci_dev);
pci_dev_put(devpriv->pci_dev);
}
return 0;
}
static int contec_do_insn_bits(struct comedi_device *dev,
struct comedi_subdevice *s,
struct comedi_insn *insn, unsigned int *data)
{
dev_dbg(dev->hw_dev, "contec_do_insn_bits called\n");
dev_dbg(dev->hw_dev, "data: %d %d\n", data[0], data[1]);
if (insn->n != 2)
return -EINVAL;
if (data[0]) {
s->state &= ~data[0];
s->state |= data[0] & data[1];
dev_dbg(dev->hw_dev, "out: %d on %lx\n", s->state,
dev->iobase + thisboard->out_offs);
outw(s->state, dev->iobase + thisboard->out_offs);
}
return 2;
}
static int contec_di_insn_bits(struct comedi_device *dev,
struct comedi_subdevice *s,
struct comedi_insn *insn, unsigned int *data)
{
dev_dbg(dev->hw_dev, "contec_di_insn_bits called\n");
dev_dbg(dev->hw_dev, "data: %d %d\n", data[0], data[1]);
if (insn->n != 2)
return -EINVAL;
data[1] = inw(dev->iobase + thisboard->in_offs);
return 2;
}
static int __devinit driver_contec_pci_probe(struct pci_dev *dev,
const struct pci_device_id *ent)
{
return comedi_pci_auto_config(dev, driver_contec.driver_name);
}
static void __devexit driver_contec_pci_remove(struct pci_dev *dev)
{
comedi_pci_auto_unconfig(dev);
}
static int __init driver_contec_init_module(void)
{
int retval;
retval = comedi_driver_register(&driver_contec);
if (retval < 0)
return retval;
driver_contec_pci_driver.name = (char *)driver_contec.driver_name;
return pci_register_driver(&driver_contec_pci_driver);
}
static void __exit driver_contec_cleanup_module(void)
{
pci_unregister_driver(&driver_contec_pci_driver);
comedi_driver_unregister(&driver_contec);
}
