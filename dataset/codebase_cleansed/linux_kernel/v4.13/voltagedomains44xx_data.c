void __init omap44xx_voltagedomains_init(void)
{
struct voltagedomain *voltdm;
int i;
#ifdef CONFIG_PM_OPP
if (cpu_is_omap443x()) {
omap4_voltdm_mpu.volt_data = omap443x_vdd_mpu_volt_data;
omap4_voltdm_iva.volt_data = omap443x_vdd_iva_volt_data;
omap4_voltdm_core.volt_data = omap443x_vdd_core_volt_data;
} else if (cpu_is_omap446x()) {
omap4_voltdm_mpu.volt_data = omap446x_vdd_mpu_volt_data;
omap4_voltdm_iva.volt_data = omap446x_vdd_iva_volt_data;
omap4_voltdm_core.volt_data = omap446x_vdd_core_volt_data;
}
#endif
omap4_voltdm_mpu.vp_param = &omap4_mpu_vp_data;
omap4_voltdm_iva.vp_param = &omap4_iva_vp_data;
omap4_voltdm_core.vp_param = &omap4_core_vp_data;
omap4_voltdm_mpu.vc_param = &omap4_mpu_vc_data;
omap4_voltdm_iva.vc_param = &omap4_iva_vc_data;
omap4_voltdm_core.vc_param = &omap4_core_vc_data;
for (i = 0; voltdm = voltagedomains_omap4[i], voltdm; i++)
voltdm->sys_clk.name = sys_clk_name;
voltdm_init(voltagedomains_omap4);
}
