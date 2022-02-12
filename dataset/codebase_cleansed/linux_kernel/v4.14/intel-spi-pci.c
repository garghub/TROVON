static int intel_spi_pci_probe(struct pci_dev *pdev,
const struct pci_device_id *id)
{
struct intel_spi_boardinfo *info;
struct intel_spi *ispi;
u32 bcr;
int ret;
ret = pcim_enable_device(pdev);
if (ret)
return ret;
info = devm_kmemdup(&pdev->dev, (void *)id->driver_data, sizeof(*info),
GFP_KERNEL);
if (!info)
return -ENOMEM;
pci_read_config_dword(pdev, BCR, &bcr);
if (!(bcr & BCR_WPD)) {
bcr |= BCR_WPD;
pci_write_config_dword(pdev, BCR, bcr);
pci_read_config_dword(pdev, BCR, &bcr);
}
info->writeable = !!(bcr & BCR_WPD);
ispi = intel_spi_probe(&pdev->dev, &pdev->resource[0], info);
if (IS_ERR(ispi))
return PTR_ERR(ispi);
pci_set_drvdata(pdev, ispi);
return 0;
}
static void intel_spi_pci_remove(struct pci_dev *pdev)
{
intel_spi_remove(pci_get_drvdata(pdev));
}
