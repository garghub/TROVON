static void __init capc7117_ide_init(void)
{
platform_device_register(&capc7117_ide_device);
}
static void __init capc7117_uarts_init(void)
{
platform_device_register(&ti16c752_device);
}
static void __init capc7117_init(void)
{
mxm_8x10_barebones_init();
mxm_8x10_ac97_init();
mxm_8x10_usb_host_init();
mxm_8x10_mmc_init();
capc7117_uarts_init();
capc7117_ide_init();
}
