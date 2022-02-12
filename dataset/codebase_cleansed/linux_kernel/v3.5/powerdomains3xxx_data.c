void __init omap3xxx_powerdomains_init(void)
{
unsigned int rev;
if (!cpu_is_omap34xx())
return;
pwrdm_register_platform_funcs(&omap3_pwrdm_operations);
pwrdm_register_pwrdms(powerdomains_omap3430_common);
rev = omap_rev();
if (rev == OMAP3430_REV_ES1_0)
pwrdm_register_pwrdms(powerdomains_omap3430es1);
else if (rev == OMAP3430_REV_ES2_0 || rev == OMAP3430_REV_ES2_1 ||
rev == OMAP3430_REV_ES3_0 || rev == OMAP3630_REV_ES1_0)
pwrdm_register_pwrdms(powerdomains_omap3430es2_es3_0);
else if (rev == OMAP3430_REV_ES3_1 || rev == OMAP3430_REV_ES3_1_2 ||
rev == AM35XX_REV_ES1_0 || rev == AM35XX_REV_ES1_1 ||
rev == OMAP3630_REV_ES1_1 || rev == OMAP3630_REV_ES1_2)
pwrdm_register_pwrdms(powerdomains_omap3430es3_1plus);
else
WARN(1, "OMAP3 powerdomain init: unknown chip type\n");
pwrdm_complete_init();
}
