void __init omap3xxx_voltagedomains_init(void)
{
struct voltagedomain *voltdm;
int i;
if (cpu_is_omap3630()) {
omap3_voltdm_mpu.volt_data = omap36xx_vddmpu_volt_data;
omap3_voltdm_core.volt_data = omap36xx_vddcore_volt_data;
} else {
omap3_voltdm_mpu.volt_data = omap34xx_vddmpu_volt_data;
omap3_voltdm_core.volt_data = omap34xx_vddcore_volt_data;
}
for (i = 0; voltdm = voltagedomains_omap3[i], voltdm; i++)
voltdm->sys_clk.name = sys_clk_name;
voltdm_init(voltagedomains_omap3);
}
