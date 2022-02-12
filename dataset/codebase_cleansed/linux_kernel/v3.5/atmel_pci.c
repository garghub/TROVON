static int __devinit atmel_pci_probe(struct pci_dev *pdev,
const struct pci_device_id *pent)
{
struct net_device *dev;
if (pci_enable_device(pdev))
return -ENODEV;
pci_set_master(pdev);
dev = init_atmel_card(pdev->irq, pdev->resource[1].start,
ATMEL_FW_TYPE_506,
&pdev->dev, NULL, NULL);
if (!dev)
return -ENODEV;
pci_set_drvdata(pdev, dev);
return 0;
}
static void __devexit atmel_pci_remove(struct pci_dev *pdev)
{
stop_atmel_card(pci_get_drvdata(pdev));
}
