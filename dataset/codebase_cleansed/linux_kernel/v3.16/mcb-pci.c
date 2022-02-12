static int mcb_pci_get_irq(struct mcb_device *mdev)
{
struct mcb_bus *mbus = mdev->bus;
struct device *dev = mbus->carrier;
struct pci_dev *pdev = to_pci_dev(dev);
return pdev->irq;
}
static int mcb_pci_probe(struct pci_dev *pdev, const struct pci_device_id *id)
{
struct priv *priv;
phys_addr_t mapbase;
int ret;
int num_cells;
unsigned long flags;
priv = devm_kzalloc(&pdev->dev, sizeof(struct priv), GFP_KERNEL);
if (!priv)
return -ENOMEM;
ret = pci_enable_device(pdev);
if (ret) {
dev_err(&pdev->dev, "Failed to enable PCI device\n");
return -ENODEV;
}
mapbase = pci_resource_start(pdev, 0);
if (!mapbase) {
dev_err(&pdev->dev, "No PCI resource\n");
goto err_start;
}
ret = pci_request_region(pdev, 0, KBUILD_MODNAME);
if (ret) {
dev_err(&pdev->dev, "Failed to request PCI BARs\n");
goto err_start;
}
priv->base = pci_iomap(pdev, 0, 0);
if (!priv->base) {
dev_err(&pdev->dev, "Cannot ioremap\n");
ret = -ENOMEM;
goto err_ioremap;
}
flags = pci_resource_flags(pdev, 0);
if (flags & IORESOURCE_IO) {
ret = -ENOTSUPP;
dev_err(&pdev->dev,
"IO mapped PCI devices are not supported\n");
goto err_ioremap;
}
pci_set_drvdata(pdev, priv);
priv->bus = mcb_alloc_bus(&pdev->dev);
if (IS_ERR(priv->bus)) {
ret = PTR_ERR(priv->bus);
goto err_drvdata;
}
priv->bus->get_irq = mcb_pci_get_irq;
ret = chameleon_parse_cells(priv->bus, mapbase, priv->base);
if (ret < 0)
goto err_drvdata;
num_cells = ret;
dev_dbg(&pdev->dev, "Found %d cells\n", num_cells);
mcb_bus_add_devices(priv->bus);
err_drvdata:
pci_iounmap(pdev, priv->base);
err_ioremap:
pci_release_region(pdev, 0);
err_start:
pci_disable_device(pdev);
return ret;
}
static void mcb_pci_remove(struct pci_dev *pdev)
{
struct priv *priv = pci_get_drvdata(pdev);
mcb_release_bus(priv->bus);
}
