void __init sh7367_map_io(void)
{
iotable_init(sh7367_io_desc, ARRAY_SIZE(sh7367_io_desc));
}
void __init sh7367_add_standard_devices(void)
{
platform_add_devices(sh7367_early_devices,
ARRAY_SIZE(sh7367_early_devices));
platform_add_devices(sh7367_devices,
ARRAY_SIZE(sh7367_devices));
}
static void __init sh7367_earlytimer_init(void)
{
sh7367_clock_init();
shmobile_earlytimer_init();
}
void __init sh7367_add_early_devices(void)
{
__raw_writel(__raw_readl(SYMSTPCR2) & ~SYMSTPCR2_CMT1, SYMSTPCR2);
early_platform_add_devices(sh7367_early_devices,
ARRAY_SIZE(sh7367_early_devices));
shmobile_setup_console();
shmobile_timer.init = sh7367_earlytimer_init;
}
