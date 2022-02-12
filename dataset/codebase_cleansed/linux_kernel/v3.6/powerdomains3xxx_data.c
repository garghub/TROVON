void __init omap3xxx_powerdomains_init(void)
{
unsigned int rev;
if (!cpu_is_omap34xx())
return;
pwrdm_register_platform_funcs(&omap3_pwrdm_operations);
rev = omap_rev();
if (rev == AM35XX_REV_ES1_0 || rev == AM35XX_REV_ES1_1) {
pwrdm_register_pwrdms(powerdomains_am35x);
} else {
pwrdm_register_pwrdms(powerdomains_omap3430_common);
switch (rev) {
case OMAP3430_REV_ES1_0:
pwrdm_register_pwrdms(powerdomains_omap3430es1);
break;
case OMAP3430_REV_ES2_0:
case OMAP3430_REV_ES2_1:
case OMAP3430_REV_ES3_0:
case OMAP3630_REV_ES1_0:
pwrdm_register_pwrdms(powerdomains_omap3430es2_es3_0);
break;
case OMAP3430_REV_ES3_1:
case OMAP3430_REV_ES3_1_2:
case OMAP3630_REV_ES1_1:
case OMAP3630_REV_ES1_2:
pwrdm_register_pwrdms(powerdomains_omap3430es3_1plus);
break;
default:
WARN(1, "OMAP3 powerdomain init: unknown chip type\n");
}
}
pwrdm_complete_init();
}
