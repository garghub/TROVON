void __init am33xx_clockdomains_init(void)
{
clkdm_register_platform_funcs(&am33xx_clkdm_operations);
clkdm_register_clkdms(clockdomains_am33xx);
clkdm_complete_init();
}
