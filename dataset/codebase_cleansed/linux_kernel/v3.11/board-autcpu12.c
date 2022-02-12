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
static void __init autcpu12_nvram_init(void)
{
void __iomem *nvram;
unsigned int save[2];
resource_size_t nvram_size = SZ_128K;
nvram = ioremap(autcpu12_nvram_resource[0].start, SZ_128K);
if (nvram) {
save[0] = readl(nvram + 0);
save[1] = readl(nvram + SZ_64K);
writel(~save[0], nvram + SZ_64K);
if (readl(nvram + 0) != save[0]) {
writel(save[0], nvram + 0);
nvram_size = SZ_32K;
} else
writel(save[1], nvram + SZ_64K);
iounmap(nvram);
autcpu12_nvram_resource[0].end =
autcpu12_nvram_resource[0].start + nvram_size - 1;
platform_device_register(&autcpu12_nvram_pdev);
} else
pr_err("Failed to remap NVRAM resource\n");
}
static void __init autcpu12_init(void)
{
clps711x_devices_init();
platform_device_register(&autcpu12_flash_pdev);
platform_device_register_simple("video-clps711x", 0, NULL, 0);
platform_device_register_simple("cs89x0", 0, autcpu12_cs8900_resource,
ARRAY_SIZE(autcpu12_cs8900_resource));
platform_device_register(&autcpu12_mmgpio_pdev);
autcpu12_nvram_init();
}
static void __init autcpu12_init_late(void)
{
gpio_request_array(autcpu12_gpios, ARRAY_SIZE(autcpu12_gpios));
if (IS_ENABLED(MTD_NAND_GPIO) && IS_ENABLED(GPIO_GENERIC_PLATFORM)) {
platform_device_register(&autcpu12_nand_pdev);
}
}
