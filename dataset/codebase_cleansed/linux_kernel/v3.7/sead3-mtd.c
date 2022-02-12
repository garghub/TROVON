static int __init sead3_mtd_init(void)
{
platform_device_register(&sead3_flash);
return 0;
}
