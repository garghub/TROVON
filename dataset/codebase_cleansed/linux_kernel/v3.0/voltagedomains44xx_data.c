static int __init omap44xx_voltage_early_init(void)
{
s16 prm_mod = OMAP4430_PRM_DEVICE_INST;
s16 prm_irqst_ocp_mod = OMAP4430_PRM_OCP_SOCKET_INST;
if (!cpu_is_omap44xx())
return 0;
omap4_vdd_mpu_info.volt_data = omap44xx_vdd_mpu_volt_data;
omap4_vdd_iva_info.volt_data = omap44xx_vdd_iva_volt_data;
omap4_vdd_core_info.volt_data = omap44xx_vdd_core_volt_data;
return omap_voltage_early_init(prm_mod, prm_irqst_ocp_mod,
omap4_vdd_info,
ARRAY_SIZE(omap4_vdd_info));
}
