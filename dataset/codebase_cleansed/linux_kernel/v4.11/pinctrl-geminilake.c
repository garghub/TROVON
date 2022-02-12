static int glk_pinctrl_probe(struct platform_device *pdev)
{
const struct intel_pinctrl_soc_data *soc_data = NULL;
struct acpi_device *adev;
int i;
adev = ACPI_COMPANION(&pdev->dev);
if (!adev)
return -ENODEV;
for (i = 0; glk_pinctrl_soc_data[i]; i++) {
if (!strcmp(adev->pnp.unique_id,
glk_pinctrl_soc_data[i]->uid)) {
soc_data = glk_pinctrl_soc_data[i];
break;
}
}
if (!soc_data)
return -ENODEV;
return intel_pinctrl_probe(pdev, soc_data);
}
static int __init glk_pinctrl_init(void)
{
return platform_driver_register(&glk_pinctrl_driver);
}
static void __exit glk_pinctrl_exit(void)
{
platform_driver_unregister(&glk_pinctrl_driver);
}
