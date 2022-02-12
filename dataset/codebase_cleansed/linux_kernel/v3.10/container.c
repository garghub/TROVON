static int container_device_attach(struct acpi_device *device,
const struct acpi_device_id *not_used)
{
return 1;
}
void __init acpi_container_init(void)
{
acpi_scan_add_handler_with_hotplug(&container_handler, "container");
}
