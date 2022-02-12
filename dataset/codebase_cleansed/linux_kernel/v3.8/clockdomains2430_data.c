void __init omap243x_clockdomains_init(void)
{
if (!cpu_is_omap243x())
return;
clkdm_register_platform_funcs(&omap2_clkdm_operations);
clkdm_register_clkdms(clockdomains_omap243x);
clkdm_complete_init();
}
