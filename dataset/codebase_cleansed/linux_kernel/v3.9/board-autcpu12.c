static void __init autcpu12_adjust_parts(struct gpio_nand_platdata *pdata,
size_t sz)
{
switch (sz) {
case SZ_16M:
case SZ_32M:
break;
case SZ_64M:
case SZ_128M:
pdata->parts[0].size = SZ_16M;
break;
default:
pr_warn("Unsupported SmartMedia device size %u\n", sz);
break;
}
}
static void __init autcpu12_init(void)
{
platform_device_register_simple("video-clps711x", 0, NULL, 0);
platform_device_register_simple("cs89x0", 0, autcpu12_cs8900_resource,
ARRAY_SIZE(autcpu12_cs8900_resource));
platform_device_register(&autcpu12_mmgpio_pdev);
platform_device_register(&autcpu12_nvram_pdev);
}
static void __init autcpu12_init_late(void)
{
if (IS_ENABLED(MTD_NAND_GPIO) && IS_ENABLED(GPIO_GENERIC_PLATFORM)) {
platform_device_register(&autcpu12_nand_pdev);
}
}
