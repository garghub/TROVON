static int __devinit rdc321x_sb_probe(struct pci_dev *pdev,
const struct pci_device_id *ent)
{
int err;
err = pci_enable_device(pdev);
if (err) {
dev_err(&pdev->dev, "failed to enable device\n");
return err;
}
rdc321x_gpio_pdata.sb_pdev = pdev;
rdc321x_wdt_pdata.sb_pdev = pdev;
return mfd_add_devices(&pdev->dev, -1,
rdc321x_sb_cells, ARRAY_SIZE(rdc321x_sb_cells), NULL, 0);
}
static void __devexit rdc321x_sb_remove(struct pci_dev *pdev)
{
mfd_remove_devices(&pdev->dev);
}
