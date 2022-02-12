static int labpc_pci_auto_attach(struct comedi_device *dev,
unsigned long context)
{
struct pci_dev *pcidev = comedi_to_pci_dev(dev);
const struct labpc_boardinfo *board = NULL;
struct labpc_private *devpriv;
int ret;
if (context < ARRAY_SIZE(labpc_pci_boards))
board = &labpc_pci_boards[context];
if (!board)
return -ENODEV;
dev->board_ptr = board;
dev->board_name = board->name;
ret = comedi_pci_enable(dev);
if (ret)
return ret;
devpriv = kzalloc(sizeof(*devpriv), GFP_KERNEL);
if (!devpriv)
return -ENOMEM;
dev->private = devpriv;
devpriv->mite = mite_alloc(pcidev);
if (!devpriv->mite)
return -ENOMEM;
ret = mite_setup(devpriv->mite);
if (ret < 0)
return ret;
dev->iobase = (unsigned long)devpriv->mite->daq_io_addr;
return labpc_common_attach(dev, mite_irq(devpriv->mite), IRQF_SHARED);
}
static void labpc_pci_detach(struct comedi_device *dev)
{
struct labpc_private *devpriv = dev->private;
labpc_common_detach(dev);
if (devpriv && devpriv->mite) {
mite_unsetup(devpriv->mite);
mite_free(devpriv->mite);
}
if (dev->irq)
free_irq(dev->irq, dev);
comedi_pci_disable(dev);
}
static int labpc_pci_probe(struct pci_dev *dev,
const struct pci_device_id *id)
{
return comedi_pci_auto_config(dev, &labpc_pci_comedi_driver,
id->driver_data);
}
