int __init omap3xxx_hwmod_init(void)
{
int r;
struct omap_hwmod **h = NULL;
unsigned int rev;
r = omap_hwmod_register(omap3xxx_hwmods);
if (r < 0)
return r;
rev = omap_rev();
if (rev == OMAP3430_REV_ES1_0 || rev == OMAP3430_REV_ES2_0 ||
rev == OMAP3430_REV_ES2_1 || rev == OMAP3430_REV_ES3_0 ||
rev == OMAP3430_REV_ES3_1 || rev == OMAP3430_REV_ES3_1_2) {
h = omap34xx_hwmods;
} else if (rev == OMAP3517_REV_ES1_0 || rev == OMAP3517_REV_ES1_1) {
h = am35xx_hwmods;
} else if (rev == OMAP3630_REV_ES1_0 || rev == OMAP3630_REV_ES1_1 ||
rev == OMAP3630_REV_ES1_2) {
h = omap36xx_hwmods;
} else {
WARN(1, "OMAP3 hwmod family init: unknown chip type\n");
return -EINVAL;
};
r = omap_hwmod_register(h);
if (r < 0)
return r;
h = NULL;
if (rev == OMAP3430_REV_ES1_0) {
h = omap3430es1_hwmods;
} else if (rev == OMAP3430_REV_ES2_0 || rev == OMAP3430_REV_ES2_1 ||
rev == OMAP3430_REV_ES3_0 || rev == OMAP3430_REV_ES3_1 ||
rev == OMAP3430_REV_ES3_1_2) {
h = omap3430es2plus_hwmods;
};
if (h)
r = omap_hwmod_register(h);
return r;
}
