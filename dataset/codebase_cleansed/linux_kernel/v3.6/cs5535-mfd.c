static int cs5535_mfd_res_enable(struct platform_device *pdev)
{
struct resource *res;
res = platform_get_resource(pdev, IORESOURCE_IO, 0);
if (!res) {
dev_err(&pdev->dev, "can't fetch device resource info\n");
return -EIO;
}
if (!request_region(res->start, resource_size(res), DRV_NAME)) {
dev_err(&pdev->dev, "can't request region\n");
return -EIO;
}
return 0;
}
static int cs5535_mfd_res_disable(struct platform_device *pdev)
{
struct resource *res;
res = platform_get_resource(pdev, IORESOURCE_IO, 0);
if (!res) {
dev_err(&pdev->dev, "can't fetch device resource info\n");
return -EIO;
}
release_region(res->start, resource_size(res));
return 0;
}
static void __devinit cs5535_clone_olpc_cells(void)
{
const char *acpi_clones[] = { "olpc-xo1-pm-acpi", "olpc-xo1-sci-acpi" };
if (!machine_is_olpc())
return;
mfd_clone_cell("cs5535-acpi", acpi_clones, ARRAY_SIZE(acpi_clones));
}
static void cs5535_clone_olpc_cells(void) { }
static int __devinit cs5535_mfd_probe(struct pci_dev *pdev,
const struct pci_device_id *id)
{
int err, i;
err = pci_enable_device(pdev);
if (err)
return err;
for (i = 0; i < ARRAY_SIZE(cs5535_mfd_cells); i++) {
int bar = cs5535_mfd_cells[i].id;
struct resource *r = &cs5535_mfd_resources[bar];
r->flags = IORESOURCE_IO;
r->start = pci_resource_start(pdev, bar);
r->end = pci_resource_end(pdev, bar);
cs5535_mfd_cells[i].id = 0;
}
err = mfd_add_devices(&pdev->dev, -1, cs5535_mfd_cells,
ARRAY_SIZE(cs5535_mfd_cells), NULL, 0, NULL);
if (err) {
dev_err(&pdev->dev, "MFD add devices failed: %d\n", err);
goto err_disable;
}
cs5535_clone_olpc_cells();
dev_info(&pdev->dev, "%zu devices registered.\n",
ARRAY_SIZE(cs5535_mfd_cells));
return 0;
err_disable:
pci_disable_device(pdev);
return err;
}
static void __devexit cs5535_mfd_remove(struct pci_dev *pdev)
{
mfd_remove_devices(&pdev->dev);
pci_disable_device(pdev);
}
