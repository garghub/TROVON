void __init omap54xx_powerdomains_init(void)
{
pwrdm_register_platform_funcs(&omap4_pwrdm_operations);
pwrdm_register_pwrdms(powerdomains_omap54xx);
pwrdm_complete_init();
}
