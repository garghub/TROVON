void __init omap44xx_voltagedomains_init(void)
{
struct voltagedomain *voltdm;
int i;
omap4_voltdm_mpu.volt_data = omap44xx_vdd_mpu_volt_data;
omap4_voltdm_iva.volt_data = omap44xx_vdd_iva_volt_data;
omap4_voltdm_core.volt_data = omap44xx_vdd_core_volt_data;
for (i = 0; voltdm = voltagedomains_omap4[i], voltdm; i++)
voltdm->sys_clk.name = sys_clk_name;
voltdm_init(voltagedomains_omap4);
}
