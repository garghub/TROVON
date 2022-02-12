void __init omap2xxx_clockdomains_init(void)
{
clkdm_init(clockdomains_omap2, clkdm_autodeps, &omap2_clkdm_operations);
}
void __init omap3xxx_clockdomains_init(void)
{
clkdm_init(clockdomains_omap2, clkdm_autodeps, &omap3_clkdm_operations);
}
