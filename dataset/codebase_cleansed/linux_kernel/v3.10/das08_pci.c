static int das08_pci_auto_attach(struct comedi_device *dev,
unsigned long context_unused)
{
struct pci_dev *pdev = comedi_to_pci_dev(dev);
struct das08_private_struct *devpriv;
int ret;
devpriv = kzalloc(sizeof(*devpriv), GFP_KERNEL);
if (!devpriv)
return -ENOMEM;
dev->private = devpriv;
dev->board_ptr = &das08_pci_boards[0];
ret = comedi_pci_enable(dev);
if (ret)
return ret;
dev->iobase = pci_resource_start(pdev, 2);
return das08_common_attach(dev, dev->iobase);
}
static void das08_pci_detach(struct comedi_device *dev)
{
das08_common_detach(dev);
comedi_pci_disable(dev);
}
static int das08_pci_probe(struct pci_dev *dev,
const struct pci_device_id *id)
{
return comedi_pci_auto_config(dev, &das08_pci_comedi_driver,
id->driver_data);
}
