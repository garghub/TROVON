void __init am33xx_powerdomains_init(void)
{
pwrdm_register_platform_funcs(&am33xx_pwrdm_operations);
pwrdm_register_pwrdms(powerdomains_am33xx);
pwrdm_complete_init();
}
