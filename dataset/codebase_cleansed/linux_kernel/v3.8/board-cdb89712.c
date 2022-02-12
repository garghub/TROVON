static void __init cdb89712_init(void)
{
platform_device_register(&cdb89712_flash_pdev);
platform_device_register(&cdb89712_bootrom_pdev);
platform_device_register(&cdb89712_sram_pdev);
platform_device_register_simple("cs89x0", 0, cdb89712_cs8900_resource,
ARRAY_SIZE(cdb89712_cs8900_resource));
}
