void __init ti81xx_clockdomains_init(void)
{
clkdm_register_platform_funcs(&am33xx_clkdm_operations);
clkdm_register_clkdms(clockdomains_ti81xx);
clkdm_complete_init();
}
