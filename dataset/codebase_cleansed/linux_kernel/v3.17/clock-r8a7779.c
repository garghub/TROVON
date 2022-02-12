void __init r8a7779_clock_init(void)
{
u32 mode = r8a7779_read_mode_pins();
int k, ret = 0;
if (mode & MD(1)) {
plla_clk.rate = 1500000000;
SH_CLK_SET_RATIO(&clkz_clk_ratio, 2, 3);
SH_CLK_SET_RATIO(&clkzs_clk_ratio, 1, 6);
SH_CLK_SET_RATIO(&clki_clk_ratio, 1, 2);
SH_CLK_SET_RATIO(&clks_clk_ratio, 1, 6);
SH_CLK_SET_RATIO(&clks1_clk_ratio, 1, 12);
SH_CLK_SET_RATIO(&clks3_clk_ratio, 1, 8);
SH_CLK_SET_RATIO(&clks4_clk_ratio, 1, 16);
SH_CLK_SET_RATIO(&clkp_clk_ratio, 1, 24);
SH_CLK_SET_RATIO(&clkg_clk_ratio, 1, 24);
if (mode & MD(2)) {
SH_CLK_SET_RATIO(&clkb_clk_ratio, 1, 36);
SH_CLK_SET_RATIO(&clkout_clk_ratio, 1, 36);
} else {
SH_CLK_SET_RATIO(&clkb_clk_ratio, 1, 24);
SH_CLK_SET_RATIO(&clkout_clk_ratio, 1, 24);
}
} else {
plla_clk.rate = 1600000000;
SH_CLK_SET_RATIO(&clkz_clk_ratio, 1, 2);
SH_CLK_SET_RATIO(&clkzs_clk_ratio, 1, 8);
SH_CLK_SET_RATIO(&clki_clk_ratio, 1, 2);
SH_CLK_SET_RATIO(&clks_clk_ratio, 1, 8);
SH_CLK_SET_RATIO(&clks1_clk_ratio, 1, 16);
SH_CLK_SET_RATIO(&clks3_clk_ratio, 1, 8);
SH_CLK_SET_RATIO(&clks4_clk_ratio, 1, 16);
SH_CLK_SET_RATIO(&clkp_clk_ratio, 1, 32);
SH_CLK_SET_RATIO(&clkg_clk_ratio, 1, 24);
if (mode & MD(2)) {
SH_CLK_SET_RATIO(&clkb_clk_ratio, 1, 32);
SH_CLK_SET_RATIO(&clkout_clk_ratio, 1, 32);
} else {
SH_CLK_SET_RATIO(&clkb_clk_ratio, 1, 24);
SH_CLK_SET_RATIO(&clkout_clk_ratio, 1, 24);
}
}
for (k = 0; !ret && (k < ARRAY_SIZE(main_clks)); k++)
ret = clk_register(main_clks[k]);
if (!ret)
ret = sh_clk_mstp_register(mstp_clks, MSTP_NR);
clkdev_add_table(lookups, ARRAY_SIZE(lookups));
if (!ret)
shmobile_clk_init();
else
panic("failed to setup r8a7779 clocks\n");
}
void __init __weak r8a7779_register_twd(void) { }
void __init r8a7779_earlytimer_init(void)
{
r8a7779_clock_init();
r8a7779_register_twd();
shmobile_earlytimer_init();
}
