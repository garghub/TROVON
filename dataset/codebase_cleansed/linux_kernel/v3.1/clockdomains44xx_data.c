void __init omap44xx_clockdomains_init(void)
{
clkdm_init(clockdomains_omap44xx, NULL, &omap4_clkdm_operations);
}
