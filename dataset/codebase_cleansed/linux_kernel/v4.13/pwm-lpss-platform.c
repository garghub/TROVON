static int pwm_lpss_probe_platform(struct platform_device *pdev)
{
const struct pwm_lpss_boardinfo *info;
const struct acpi_device_id *id;
struct pwm_lpss_chip *lpwm;
struct resource *r;
id = acpi_match_device(pdev->dev.driver->acpi_match_table, &pdev->dev);
if (!id)
return -ENODEV;
info = (const struct pwm_lpss_boardinfo *)id->driver_data;
r = platform_get_resource(pdev, IORESOURCE_MEM, 0);
lpwm = pwm_lpss_probe(&pdev->dev, r, info);
if (IS_ERR(lpwm))
return PTR_ERR(lpwm);
platform_set_drvdata(pdev, lpwm);
pm_runtime_set_active(&pdev->dev);
pm_runtime_enable(&pdev->dev);
return 0;
}
static int pwm_lpss_remove_platform(struct platform_device *pdev)
{
struct pwm_lpss_chip *lpwm = platform_get_drvdata(pdev);
pm_runtime_disable(&pdev->dev);
return pwm_lpss_remove(lpwm);
}
