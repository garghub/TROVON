static int int340x_thermal_handler_attach(struct acpi_device *adev,
const struct acpi_device_id *id)
{
if (IS_ENABLED(CONFIG_INT340X_THERMAL))
acpi_create_platform_device(adev, NULL);
else if (IS_ENABLED(CONFIG_INTEL_SOC_DTS_THERMAL) &&
id->driver_data == INT3401_DEVICE)
acpi_create_platform_device(adev, NULL);
return 1;
}
void __init acpi_int340x_thermal_init(void)
{
acpi_scan_add_handler(&int340x_thermal_handler);
}
