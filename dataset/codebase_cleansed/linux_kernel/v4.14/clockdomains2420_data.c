void __init omap242x_clockdomains_init(void)
{
if (!cpu_is_omap242x())
return;
clkdm_register_platform_funcs(&omap2_clkdm_operations);
clkdm_register_clkdms(clockdomains_omap242x);
clkdm_complete_init();
}
