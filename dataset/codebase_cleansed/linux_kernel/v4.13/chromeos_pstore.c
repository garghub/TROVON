static int __init chromeos_probe_acpi(struct platform_device *pdev)
{
struct resource *res;
resource_size_t len;
res = platform_get_resource(pdev, IORESOURCE_MEM, 0);
if (!res)
return -ENOMEM;
len = resource_size(res);
if (!res->start || !len)
return -ENOMEM;
pr_info("chromeos ramoops using acpi device.\n");
chromeos_ramoops_data.mem_size = len;
chromeos_ramoops_data.mem_address = res->start;
return 0;
}
static bool __init chromeos_check_acpi(void)
{
if (!platform_driver_probe(&chromeos_ramoops_acpi, chromeos_probe_acpi))
return true;
return false;
}
static inline bool chromeos_check_acpi(void) { return false; }
static int __init chromeos_pstore_init(void)
{
bool acpi_dev_found;
acpi_dev_found = chromeos_check_acpi();
if (acpi_dev_found || dmi_check_system(chromeos_pstore_dmi_table))
return platform_device_register(&chromeos_ramoops);
return -ENODEV;
}
static void __exit chromeos_pstore_exit(void)
{
platform_device_unregister(&chromeos_ramoops);
}
