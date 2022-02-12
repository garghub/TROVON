void __init dra7xx_powerdomains_init(void)
{
pwrdm_register_platform_funcs(&omap4_pwrdm_operations);
pwrdm_register_pwrdms(powerdomains_dra7xx);
if (soc_is_dra76x())
pwrdm_register_pwrdms(powerdomains_dra76x);
else if (soc_is_dra74x())
pwrdm_register_pwrdms(powerdomains_dra74x);
else if (soc_is_dra72x())
pwrdm_register_pwrdms(powerdomains_dra72x);
pwrdm_complete_init();
}
