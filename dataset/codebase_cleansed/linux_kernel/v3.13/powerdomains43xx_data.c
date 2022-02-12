static int am43xx_check_vcvp(void)
{
return 0;
}
void __init am43xx_powerdomains_init(void)
{
omap4_pwrdm_operations.pwrdm_has_voltdm = am43xx_check_vcvp;
pwrdm_register_platform_funcs(&omap4_pwrdm_operations);
pwrdm_register_pwrdms(powerdomains_am43xx);
pwrdm_complete_init();
}
