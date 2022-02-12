static int __init rtc_init(void)
{
if (efi_enabled(EFI_RUNTIME_SERVICES))
if (platform_device_register(&rtc_efi_dev) < 0)
pr_err("unable to register rtc device...\n");
return 0;
}
