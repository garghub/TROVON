static void pci236_intr_update_cb(struct comedi_device *dev, bool enable)
{
struct pc236_private *devpriv = dev->private;
outl(enable ? PCI236_INTR_ENABLE : PCI236_INTR_DISABLE,
devpriv->lcr_iobase + PLX9052_INTCSR);
}
static bool pci236_intr_chk_clr_cb(struct comedi_device *dev)
{
struct pc236_private *devpriv = dev->private;
if (!(inl(devpriv->lcr_iobase + PLX9052_INTCSR) &
PLX9052_INTCSR_LI1STAT))
return false;
pci236_intr_update_cb(dev, devpriv->enable_irq);
return true;
}
static int pci236_auto_attach(struct comedi_device *dev,
unsigned long context_unused)
{
struct pci_dev *pci_dev = comedi_to_pci_dev(dev);
struct pc236_private *devpriv;
unsigned long iobase;
int ret;
dev_info(dev->class_dev, "amplc_pci236: attach pci %s\n",
pci_name(pci_dev));
devpriv = comedi_alloc_devpriv(dev, sizeof(*devpriv));
if (!devpriv)
return -ENOMEM;
dev->board_ptr = &pc236_pci_board;
dev->board_name = pc236_pci_board.name;
ret = comedi_pci_enable(dev);
if (ret)
return ret;
devpriv->lcr_iobase = pci_resource_start(pci_dev, 1);
iobase = pci_resource_start(pci_dev, 2);
return amplc_pc236_common_attach(dev, iobase, pci_dev->irq,
IRQF_SHARED);
}
static void pci236_detach(struct comedi_device *dev)
{
if (dev->irq)
free_irq(dev->irq, dev);
comedi_pci_disable(dev);
}
static int amplc_pci236_pci_probe(struct pci_dev *dev,
const struct pci_device_id *id)
{
return comedi_pci_auto_config(dev, &amplc_pci236_driver,
id->driver_data);
}
