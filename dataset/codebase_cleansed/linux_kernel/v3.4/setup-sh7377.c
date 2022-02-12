void __init sh7377_map_io(void)
{
iotable_init(sh7377_io_desc, ARRAY_SIZE(sh7377_io_desc));
}
void __init sh7377_add_standard_devices(void)
{
platform_add_devices(sh7377_early_devices,
ARRAY_SIZE(sh7377_early_devices));
platform_add_devices(sh7377_devices,
ARRAY_SIZE(sh7377_devices));
}
static void __init sh7377_earlytimer_init(void)
{
sh7377_clock_init();
shmobile_earlytimer_init();
}
void __init sh7377_add_early_devices(void)
{
__raw_writel(__raw_readl(SMSTPCR3) & ~SMSTPCR3_CMT1, SMSTPCR3);
early_platform_add_devices(sh7377_early_devices,
ARRAY_SIZE(sh7377_early_devices));
shmobile_setup_console();
shmobile_timer.init = sh7377_earlytimer_init;
}
