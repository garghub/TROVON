void __init ti814x_clockdomains_init(void)
{
clkdm_register_platform_funcs(&am33xx_clkdm_operations);
clkdm_register_clkdms(clockdomains_ti814x);
clkdm_complete_init();
}
void __init ti816x_clockdomains_init(void)
{
clkdm_register_platform_funcs(&am33xx_clkdm_operations);
clkdm_register_clkdms(clockdomains_ti816x);
clkdm_complete_init();
}
