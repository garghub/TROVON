static int intel_lpss_pci_probe(struct pci_dev *pdev,
const struct pci_device_id *id)
{
struct intel_lpss_platform_info *info;
int ret;
ret = pcim_enable_device(pdev);
if (ret)
return ret;
info = devm_kmemdup(&pdev->dev, (void *)id->driver_data, sizeof(*info),
GFP_KERNEL);
if (!info)
return -ENOMEM;
info->mem = &pdev->resource[0];
info->irq = pdev->irq;
pci_set_master(pdev);
ret = intel_lpss_probe(&pdev->dev, info);
if (ret)
return ret;
pm_runtime_put(&pdev->dev);
pm_runtime_allow(&pdev->dev);
return 0;
}
static void intel_lpss_pci_remove(struct pci_dev *pdev)
{
pm_runtime_forbid(&pdev->dev);
pm_runtime_get_sync(&pdev->dev);
intel_lpss_remove(&pdev->dev);
}
