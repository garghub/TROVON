static int bxt_pinctrl_probe(struct platform_device *pdev)
{
const struct intel_pinctrl_soc_data *soc_data = NULL;
const struct intel_pinctrl_soc_data **soc_table;
struct acpi_device *adev;
int i;
adev = ACPI_COMPANION(&pdev->dev);
if (adev) {
const struct acpi_device_id *id;
id = acpi_match_device(bxt_pinctrl_acpi_match, &pdev->dev);
if (!id)
return -ENODEV;
soc_table = (const struct intel_pinctrl_soc_data **)
id->driver_data;
for (i = 0; soc_table[i]; i++) {
if (!strcmp(adev->pnp.unique_id, soc_table[i]->uid)) {
soc_data = soc_table[i];
break;
}
}
} else {
const struct platform_device_id *pid;
pid = platform_get_device_id(pdev);
if (!pid)
return -ENODEV;
soc_table = (const struct intel_pinctrl_soc_data **)
pid->driver_data;
soc_data = soc_table[pdev->id];
}
if (!soc_data)
return -ENODEV;
return intel_pinctrl_probe(pdev, soc_data);
}
static int __init bxt_pinctrl_init(void)
{
return platform_driver_register(&bxt_pinctrl_driver);
}
static void __exit bxt_pinctrl_exit(void)
{
platform_driver_unregister(&bxt_pinctrl_driver);
}
