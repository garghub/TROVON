static int cnl_pinctrl_probe(struct platform_device *pdev)
{
const struct intel_pinctrl_soc_data *soc_data;
const struct acpi_device_id *id;
id = acpi_match_device(cnl_pinctrl_acpi_match, &pdev->dev);
if (!id || !id->driver_data)
return -ENODEV;
soc_data = (const struct intel_pinctrl_soc_data *)id->driver_data;
return intel_pinctrl_probe(pdev, soc_data);
}
