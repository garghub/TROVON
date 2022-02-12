void __init sh73a0_add_standard_devices(void)
{
__raw_writel(__raw_readl(SRCR2) & ~(1 << 18), SRCR2);
platform_add_devices(sh73a0_early_devices,
ARRAY_SIZE(sh73a0_early_devices));
platform_add_devices(sh73a0_late_devices,
ARRAY_SIZE(sh73a0_late_devices));
}
void __init sh73a0_add_early_devices(void)
{
early_platform_add_devices(sh73a0_early_devices,
ARRAY_SIZE(sh73a0_early_devices));
}
