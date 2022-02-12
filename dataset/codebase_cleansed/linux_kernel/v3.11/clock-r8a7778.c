void __init r8a7778_clock_init(void)
{
void __iomem *modemr = ioremap_nocache(MODEMR, PAGE_SIZE);
u32 mode;
int k, ret = 0;
BUG_ON(!modemr);
mode = ioread32(modemr);
iounmap(modemr);
switch (mode & (MD(19) | MD(18) | MD(12) | MD(11))) {
case MD(19):
extal_clk.rate = 38000000;
SH_CLK_SET_RATIO(&plla_clk_ratio, 21, 1);
SH_CLK_SET_RATIO(&pllb_clk_ratio, 21, 1);
break;
case MD(19) | MD(11):
extal_clk.rate = 33333333;
SH_CLK_SET_RATIO(&plla_clk_ratio, 24, 1);
SH_CLK_SET_RATIO(&pllb_clk_ratio, 24, 1);
break;
case MD(19) | MD(12):
extal_clk.rate = 28500000;
SH_CLK_SET_RATIO(&plla_clk_ratio, 28, 1);
SH_CLK_SET_RATIO(&pllb_clk_ratio, 28, 1);
break;
case MD(19) | MD(12) | MD(11):
extal_clk.rate = 25000000;
SH_CLK_SET_RATIO(&plla_clk_ratio, 32, 1);
SH_CLK_SET_RATIO(&pllb_clk_ratio, 32, 1);
break;
case MD(19) | MD(18) | MD(11):
extal_clk.rate = 33333333;
SH_CLK_SET_RATIO(&plla_clk_ratio, 24, 1);
SH_CLK_SET_RATIO(&pllb_clk_ratio, 21, 1);
break;
case MD(19) | MD(18) | MD(12):
extal_clk.rate = 28500000;
SH_CLK_SET_RATIO(&plla_clk_ratio, 28, 1);
SH_CLK_SET_RATIO(&pllb_clk_ratio, 21, 1);
break;
case MD(19) | MD(18) | MD(12) | MD(11):
extal_clk.rate = 25000000;
SH_CLK_SET_RATIO(&plla_clk_ratio, 32, 1);
SH_CLK_SET_RATIO(&pllb_clk_ratio, 24, 1);
break;
default:
BUG();
}
if (mode & MD(1)) {
SH_CLK_SET_RATIO(&i_clk_ratio, 1, 1);
SH_CLK_SET_RATIO(&s_clk_ratio, 1, 3);
SH_CLK_SET_RATIO(&s1_clk_ratio, 1, 6);
SH_CLK_SET_RATIO(&s3_clk_ratio, 1, 4);
SH_CLK_SET_RATIO(&s4_clk_ratio, 1, 8);
SH_CLK_SET_RATIO(&p_clk_ratio, 1, 12);
SH_CLK_SET_RATIO(&g_clk_ratio, 1, 12);
if (mode & MD(2)) {
SH_CLK_SET_RATIO(&b_clk_ratio, 1, 18);
SH_CLK_SET_RATIO(&out_clk_ratio, 1, 18);
} else {
SH_CLK_SET_RATIO(&b_clk_ratio, 1, 12);
SH_CLK_SET_RATIO(&out_clk_ratio, 1, 12);
}
} else {
SH_CLK_SET_RATIO(&i_clk_ratio, 1, 1);
SH_CLK_SET_RATIO(&s_clk_ratio, 1, 4);
SH_CLK_SET_RATIO(&s1_clk_ratio, 1, 8);
SH_CLK_SET_RATIO(&s3_clk_ratio, 1, 4);
SH_CLK_SET_RATIO(&s4_clk_ratio, 1, 8);
SH_CLK_SET_RATIO(&p_clk_ratio, 1, 16);
SH_CLK_SET_RATIO(&g_clk_ratio, 1, 12);
if (mode & MD(2)) {
SH_CLK_SET_RATIO(&b_clk_ratio, 1, 16);
SH_CLK_SET_RATIO(&out_clk_ratio, 1, 16);
} else {
SH_CLK_SET_RATIO(&b_clk_ratio, 1, 12);
SH_CLK_SET_RATIO(&out_clk_ratio, 1, 12);
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
panic("failed to setup r8a7778 clocks\n");
}
