void __init omap242x_powerdomains_init(void)
{
if (!cpu_is_omap2420())
return;
pwrdm_register_platform_funcs(&omap2_pwrdm_operations);
pwrdm_register_pwrdms(powerdomains_omap24xx);
pwrdm_complete_init();
}
void __init omap243x_powerdomains_init(void)
{
if (!cpu_is_omap2430())
return;
pwrdm_register_platform_funcs(&omap2_pwrdm_operations);
pwrdm_register_pwrdms(powerdomains_omap24xx);
pwrdm_register_pwrdms(powerdomains_omap2430);
pwrdm_complete_init();
}
