void __init omap54xx_voltagedomains_init(void)
{
struct voltagedomain *voltdm;
int i;
for (i = 0; voltdm = voltagedomains_omap5[i], voltdm; i++)
voltdm->sys_clk.name = sys_clk_name;
voltdm_init(voltagedomains_omap5);
}
