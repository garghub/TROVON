void __init omap3xxx_clockdomains_init(void)
{
struct clockdomain **sc;
unsigned int rev;
if (!cpu_is_omap34xx())
return;
clkdm_register_platform_funcs(&omap3_clkdm_operations);
clkdm_register_clkdms(clockdomains_common);
rev = omap_rev();
if (rev == AM35XX_REV_ES1_0 || rev == AM35XX_REV_ES1_1) {
clkdm_register_clkdms(clockdomains_am35x);
clkdm_register_autodeps(clkdm_am35x_autodeps);
} else {
clkdm_register_clkdms(clockdomains_omap3430);
sc = (rev == OMAP3430_REV_ES1_0) ?
clockdomains_omap3430es1 : clockdomains_omap3430es2plus;
clkdm_register_clkdms(sc);
clkdm_register_autodeps(clkdm_autodeps);
}
clkdm_complete_init();
}
