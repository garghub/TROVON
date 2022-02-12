struct pci_dev *comedi_to_pci_dev(struct comedi_device *dev)
{
return dev->hw_dev ? to_pci_dev(dev->hw_dev) : NULL;
}
int comedi_pci_enable(struct comedi_device *dev)
{
struct pci_dev *pcidev = comedi_to_pci_dev(dev);
int rc;
if (!pcidev)
return -ENODEV;
rc = pci_enable_device(pcidev);
if (rc < 0)
return rc;
rc = pci_request_regions(pcidev, dev->board_name);
if (rc < 0)
pci_disable_device(pcidev);
else
dev->ioenabled = true;
return rc;
}
void comedi_pci_disable(struct comedi_device *dev)
{
struct pci_dev *pcidev = comedi_to_pci_dev(dev);
if (pcidev && dev->ioenabled) {
pci_release_regions(pcidev);
pci_disable_device(pcidev);
}
dev->ioenabled = false;
}
int comedi_pci_auto_config(struct pci_dev *pcidev,
struct comedi_driver *driver,
unsigned long context)
{
return comedi_auto_config(&pcidev->dev, driver, context);
}
void comedi_pci_auto_unconfig(struct pci_dev *pcidev)
{
comedi_auto_unconfig(&pcidev->dev);
}
int comedi_pci_driver_register(struct comedi_driver *comedi_driver,
struct pci_driver *pci_driver)
{
int ret;
ret = comedi_driver_register(comedi_driver);
if (ret < 0)
return ret;
ret = pci_register_driver(pci_driver);
if (ret < 0) {
comedi_driver_unregister(comedi_driver);
return ret;
}
return 0;
}
void comedi_pci_driver_unregister(struct comedi_driver *comedi_driver,
struct pci_driver *pci_driver)
{
pci_unregister_driver(pci_driver);
comedi_driver_unregister(comedi_driver);
}
