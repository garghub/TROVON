static int __init omap2xxx_clk_arch_init(void)
{
int ret;
if (!cpu_is_omap24xx())
return 0;
ret = omap2_clk_switch_mpurate_at_boot("virt_prcm_set");
if (!ret)
omap2_clk_print_new_rates("sys_ck", "dpll_ck", "mpu_ck");
return ret;
}
