static int int340x_thermal_handler_attach(struct acpi_device *adev,
const struct acpi_device_id *id)
{
#if defined(CONFIG_INT340X_THERMAL) || defined(CONFIG_INT340X_THERMAL_MODULE)
acpi_create_platform_device(adev);
#elif defined(INTEL_SOC_DTS_THERMAL) || defined(INTEL_SOC_DTS_THERMAL_MODULE)
if (id->driver_data == INT3401_DEVICE)
acpi_create_platform_device(adev);
#endif
return 1;
}
void __init acpi_int340x_thermal_init(void)
{
acpi_scan_add_handler(&int340x_thermal_handler);
}
