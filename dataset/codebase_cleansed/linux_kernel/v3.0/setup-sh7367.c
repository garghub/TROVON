void __init sh7367_add_standard_devices(void)
{
platform_add_devices(sh7367_early_devices,
ARRAY_SIZE(sh7367_early_devices));
platform_add_devices(sh7367_devices,
ARRAY_SIZE(sh7367_devices));
}
void __init sh7367_add_early_devices(void)
{
__raw_writel(__raw_readl(SYMSTPCR2) & ~SYMSTPCR2_CMT1, SYMSTPCR2);
early_platform_add_devices(sh7367_early_devices,
ARRAY_SIZE(sh7367_early_devices));
}
