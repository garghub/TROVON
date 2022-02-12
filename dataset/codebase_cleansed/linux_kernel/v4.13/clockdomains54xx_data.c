void __init omap54xx_clockdomains_init(void)
{
clkdm_register_platform_funcs(&omap4_clkdm_operations);
clkdm_register_clkdms(clockdomains_omap54xx);
clkdm_complete_init();
}
