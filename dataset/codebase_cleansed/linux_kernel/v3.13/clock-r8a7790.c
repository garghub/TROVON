void __init r8a7790_clock_init(void)
{
u32 mode = rcar_gen2_read_mode_pins();
int k, ret = 0;
switch (mode & (MD(14) | MD(13))) {
case 0:
R8A7790_CLOCK_ROOT(15, &extal_clk, 172, 208, 106, 88);
break;
case MD(13):
R8A7790_CLOCK_ROOT(20, &extal_clk, 130, 156, 80, 66);
break;
case MD(14):
R8A7790_CLOCK_ROOT(26, &extal_div2_clk, 200, 240, 122, 102);
break;
case MD(13) | MD(14):
R8A7790_CLOCK_ROOT(30, &extal_div2_clk, 172, 208, 106, 88);
break;
}
if (mode & (MD(18)))
SH_CLK_SET_RATIO(&lb_clk_ratio, 1, 36);
else
SH_CLK_SET_RATIO(&lb_clk_ratio, 1, 24);
if ((mode & (MD(3) | MD(2) | MD(1))) == MD(2))
SH_CLK_SET_RATIO(&qspi_clk_ratio, 1, 16);
else
SH_CLK_SET_RATIO(&qspi_clk_ratio, 1, 20);
for (k = 0; !ret && (k < ARRAY_SIZE(main_clks)); k++)
ret = clk_register(main_clks[k]);
if (!ret)
ret = sh_clk_div4_register(div4_clks, DIV4_NR, &div4_table);
if (!ret)
ret = sh_clk_div6_register(div6_clks, DIV6_NR);
if (!ret)
ret = sh_clk_mstp_register(mstp_clks, MSTP_NR);
clkdev_add_table(lookups, ARRAY_SIZE(lookups));
if (!ret)
shmobile_clk_init();
else
panic("failed to setup r8a7790 clocks\n");
}
