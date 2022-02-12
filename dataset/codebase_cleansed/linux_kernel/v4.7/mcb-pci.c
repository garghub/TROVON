static int mcb_pci_get_irq(struct mcb_device *mdev)
{
struct mcb_bus *mbus = mdev->bus;
struct device *dev = mbus->carrier;
struct pci_dev *pdev = to_pci_dev(dev);
return pdev->irq;
}
static int mcb_pci_probe(struct pci_dev *pdev, const struct pci_device_id *id)
{
struct resource *res;
struct priv *priv;
int ret;
unsigned long flags;
priv = devm_kzalloc(&pdev->dev, sizeof(struct priv), GFP_KERNEL);
if (!priv)
return -ENOMEM;
ret = pci_enable_device(pdev);
if (ret) {
dev_err(&pdev->dev, "Failed to enable PCI device\n");
return -ENODEV;
}
priv->mapbase = pci_resource_start(pdev, 0);
if (!priv->mapbase) {
dev_err(&pdev->dev, "No PCI resource\n");
ret = -ENODEV;
goto out_disable;
}
res = devm_request_mem_region(&pdev->dev, priv->mapbase,
CHAM_HEADER_SIZE,
KBUILD_MODNAME);
if (!res) {
dev_err(&pdev->dev, "Failed to request PCI memory\n");
ret = -EBUSY;
goto out_disable;
}
priv->base = devm_ioremap(&pdev->dev, priv->mapbase, CHAM_HEADER_SIZE);
if (!priv->base) {
dev_err(&pdev->dev, "Cannot ioremap\n");
ret = -ENOMEM;
goto out_disable;
}
flags = pci_resource_flags(pdev, 0);
if (flags & IORESOURCE_IO) {
ret = -ENOTSUPP;
dev_err(&pdev->dev,
"IO mapped PCI devices are not supported\n");
goto out_disable;
}
pci_set_drvdata(pdev, priv);
priv->bus = mcb_alloc_bus(&pdev->dev);
if (IS_ERR(priv->bus)) {
ret = PTR_ERR(priv->bus);
goto out_disable;
}
priv->bus->get_irq = mcb_pci_get_irq;
ret = chameleon_parse_cells(priv->bus, priv->mapbase, priv->base);
if (ret < 0)
goto out_mcb_bus;
dev_dbg(&pdev->dev, "Found %d cells\n", ret);
mcb_bus_add_devices(priv->bus);
return 0;
out_mcb_bus:
mcb_release_bus(priv->bus);
out_disable:
pci_disable_device(pdev);
return ret;
}
static void mcb_pci_remove(struct pci_dev *pdev)
{
struct priv *priv = pci_get_drvdata(pdev);
mcb_release_bus(priv->bus);
pci_disable_device(pdev);
}
