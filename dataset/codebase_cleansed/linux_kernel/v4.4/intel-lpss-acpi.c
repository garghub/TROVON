static int intel_lpss_acpi_probe(struct platform_device *pdev)
{
struct intel_lpss_platform_info *info;
const struct acpi_device_id *id;
id = acpi_match_device(intel_lpss_acpi_ids, &pdev->dev);
if (!id)
return -ENODEV;
info = devm_kmemdup(&pdev->dev, (void *)id->driver_data, sizeof(*info),
GFP_KERNEL);
if (!info)
return -ENOMEM;
info->mem = platform_get_resource(pdev, IORESOURCE_MEM, 0);
info->irq = platform_get_irq(pdev, 0);
pm_runtime_set_active(&pdev->dev);
pm_runtime_enable(&pdev->dev);
return intel_lpss_probe(&pdev->dev, info);
}
static int intel_lpss_acpi_remove(struct platform_device *pdev)
{
intel_lpss_remove(&pdev->dev);
pm_runtime_disable(&pdev->dev);
return 0;
}
