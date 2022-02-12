void __init am43xx_clockdomains_init(void)
{
clkdm_register_platform_funcs(&am43xx_clkdm_operations);
clkdm_register_clkdms(clockdomains_am43xx);
clkdm_complete_init();
}
