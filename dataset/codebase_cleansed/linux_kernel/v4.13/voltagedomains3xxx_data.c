void __init omap3xxx_voltagedomains_init(void)
{
struct voltagedomain *voltdm;
struct voltagedomain **voltdms;
int i;
#ifdef CONFIG_PM_OPP
if (cpu_is_omap3630()) {
omap3_voltdm_mpu.volt_data = omap36xx_vddmpu_volt_data;
omap3_voltdm_core.volt_data = omap36xx_vddcore_volt_data;
} else {
omap3_voltdm_mpu.volt_data = omap34xx_vddmpu_volt_data;
omap3_voltdm_core.volt_data = omap34xx_vddcore_volt_data;
}
#endif
omap3_voltdm_mpu.vp_param = &omap3_mpu_vp_data;
omap3_voltdm_core.vp_param = &omap3_core_vp_data;
omap3_voltdm_mpu.vc_param = &omap3_mpu_vc_data;
omap3_voltdm_core.vc_param = &omap3_core_vc_data;
if (soc_is_am35xx())
voltdms = voltagedomains_am35xx;
else
voltdms = voltagedomains_omap3;
for (i = 0; voltdm = voltdms[i], voltdm; i++)
voltdm->sys_clk.name = sys_clk_name;
voltdm_init(voltdms);
}
