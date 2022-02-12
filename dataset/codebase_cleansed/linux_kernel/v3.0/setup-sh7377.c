void __init sh7377_add_standard_devices(void)
{
platform_add_devices(sh7377_early_devices,
ARRAY_SIZE(sh7377_early_devices));
platform_add_devices(sh7377_devices,
ARRAY_SIZE(sh7377_devices));
}
void __init sh7377_add_early_devices(void)
{
__raw_writel(__raw_readl(SMSTPCR3) & ~SMSTPCR3_CMT1, SMSTPCR3);
early_platform_add_devices(sh7377_early_devices,
ARRAY_SIZE(sh7377_early_devices));
}
