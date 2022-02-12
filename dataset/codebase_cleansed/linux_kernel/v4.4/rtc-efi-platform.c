static int __init rtc_init(void)\r\n{\r\nif (efi_enabled(EFI_RUNTIME_SERVICES))\r\nif (platform_device_register(&rtc_efi_dev) < 0)\r\npr_err("unable to register rtc device...\n");\r\nreturn 0;\r\n}
