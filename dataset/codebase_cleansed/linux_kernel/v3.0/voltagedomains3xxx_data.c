static int __init omap3xxx_voltage_early_init(void)
{
s16 prm_mod = OMAP3430_GR_MOD;
s16 prm_irqst_ocp_mod = OCP_MOD;
if (!cpu_is_omap34xx())
return 0;
if (cpu_is_omap3630()) {
omap3_vdd1_info.volt_data = omap36xx_vddmpu_volt_data;
omap3_vdd2_info.volt_data = omap36xx_vddcore_volt_data;
} else {
omap3_vdd1_info.volt_data = omap34xx_vddmpu_volt_data;
omap3_vdd2_info.volt_data = omap34xx_vddcore_volt_data;
}
return omap_voltage_early_init(prm_mod, prm_irqst_ocp_mod,
omap3_vdd_info,
ARRAY_SIZE(omap3_vdd_info));
}
