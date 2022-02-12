static int spt_pinctrl_probe(struct platform_device *pdev)
{
const struct intel_pinctrl_soc_data *soc_data;
const struct acpi_device_id *id;
id = acpi_match_device(spt_pinctrl_acpi_match, &pdev->dev);
if (!id || !id->driver_data)
return -ENODEV;
soc_data = (const struct intel_pinctrl_soc_data *)id->driver_data;
return intel_pinctrl_probe(pdev, soc_data);
}
static int __init spt_pinctrl_init(void)
{
return platform_driver_register(&spt_pinctrl_driver);
}
static void __exit spt_pinctrl_exit(void)
{
platform_driver_unregister(&spt_pinctrl_driver);
}
