static int __init chromeos_pstore_init(void)
{
if (dmi_check_system(chromeos_pstore_dmi_table))
return platform_device_register(&chromeos_ramoops);
return -ENODEV;
}
static void __exit chromeos_pstore_exit(void)
{
platform_device_unregister(&chromeos_ramoops);
}
