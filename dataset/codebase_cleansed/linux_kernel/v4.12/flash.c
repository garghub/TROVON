static int __init asb2303_mtd_init(void)
{
platform_device_register(&asb2303_bootprom);
platform_device_register(&asb2303_sysflash);
return 0;
}
