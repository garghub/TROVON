static int s5p6440_epll_set_rate(struct clk *clk, unsigned long rate)
{
unsigned int epll_con, epll_con_k;
unsigned int i;
if (clk->rate == rate)
return 0;
epll_con = __raw_readl(S5P64X0_EPLL_CON);
epll_con_k = __raw_readl(S5P64X0_EPLL_CON_K);
epll_con_k &= ~(PLL90XX_KDIV_MASK);
epll_con &= ~(PLL90XX_MDIV_MASK | PLL90XX_PDIV_MASK | PLL90XX_SDIV_MASK);
for (i = 0; i < ARRAY_SIZE(epll_div); i++) {
if (epll_div[i][0] == rate) {
epll_con_k |= (epll_div[i][1] << PLL90XX_KDIV_SHIFT);
epll_con |= (epll_div[i][2] << PLL90XX_MDIV_SHIFT) |
(epll_div[i][3] << PLL90XX_PDIV_SHIFT) |
(epll_div[i][4] << PLL90XX_SDIV_SHIFT);
break;
}
}
if (i == ARRAY_SIZE(epll_div)) {
printk(KERN_ERR "%s: Invalid Clock EPLL Frequency\n", __func__);
return -EINVAL;
}
__raw_writel(epll_con, S5P64X0_EPLL_CON);
__raw_writel(epll_con_k, S5P64X0_EPLL_CON_K);
printk(KERN_WARNING "EPLL Rate changes from %lu to %lu\n",
clk->rate, rate);
clk->rate = rate;
return 0;
}
void __init_or_cpufreq s5p6440_setup_clocks(void)
{
struct clk *xtal_clk;
unsigned long xtal;
unsigned long fclk;
unsigned long hclk;
unsigned long hclk_low;
unsigned long pclk;
unsigned long pclk_low;
unsigned long apll;
unsigned long mpll;
unsigned long epll;
unsigned int ptr;
clk_fout_epll.enable = s5p_epll_enable;
clk_fout_epll.ops = &s5p6440_epll_ops;
clk_48m.enable = s5p64x0_clk48m_ctrl;
xtal_clk = clk_get(NULL, "ext_xtal");
BUG_ON(IS_ERR(xtal_clk));
xtal = clk_get_rate(xtal_clk);
clk_put(xtal_clk);
apll = s5p_get_pll45xx(xtal, __raw_readl(S5P64X0_APLL_CON), pll_4502);
mpll = s5p_get_pll45xx(xtal, __raw_readl(S5P64X0_MPLL_CON), pll_4502);
epll = s5p_get_pll90xx(xtal, __raw_readl(S5P64X0_EPLL_CON),
__raw_readl(S5P64X0_EPLL_CON_K));
clk_fout_apll.rate = apll;
clk_fout_mpll.rate = mpll;
clk_fout_epll.rate = epll;
printk(KERN_INFO "S5P6440: PLL settings, A=%ld.%ldMHz, M=%ld.%ldMHz," \
" E=%ld.%ldMHz\n",
print_mhz(apll), print_mhz(mpll), print_mhz(epll));
fclk = clk_get_rate(&clk_armclk.clk);
hclk = clk_get_rate(&clk_hclk.clk);
pclk = clk_get_rate(&clk_pclk.clk);
hclk_low = clk_get_rate(&clk_hclk_low.clk);
pclk_low = clk_get_rate(&clk_pclk_low.clk);
printk(KERN_INFO "S5P6440: HCLK=%ld.%ldMHz, HCLK_LOW=%ld.%ldMHz," \
" PCLK=%ld.%ldMHz, PCLK_LOW=%ld.%ldMHz\n",
print_mhz(hclk), print_mhz(hclk_low),
print_mhz(pclk), print_mhz(pclk_low));
clk_f.rate = fclk;
clk_h.rate = hclk;
clk_p.rate = pclk;
for (ptr = 0; ptr < ARRAY_SIZE(clksrcs); ptr++)
s3c_set_clksrc(&clksrcs[ptr], true);
}
void __init s5p6440_register_clocks(void)
{
int ptr;
unsigned int cnt;
s3c24xx_register_clocks(clks, ARRAY_SIZE(clks));
for (ptr = 0; ptr < ARRAY_SIZE(sysclks); ptr++)
s3c_register_clksrc(sysclks[ptr], 1);
s3c24xx_register_clocks(clk_cdev, ARRAY_SIZE(clk_cdev));
for (cnt = 0; cnt < ARRAY_SIZE(clk_cdev); cnt++)
s3c_disable_clocks(clk_cdev[cnt], 1);
s3c_register_clksrc(clksrcs, ARRAY_SIZE(clksrcs));
s3c_register_clocks(init_clocks, ARRAY_SIZE(init_clocks));
for (ptr = 0; ptr < ARRAY_SIZE(clksrc_cdev); ptr++)
s3c_register_clksrc(clksrc_cdev[ptr], 1);
s3c_register_clocks(init_clocks_off, ARRAY_SIZE(init_clocks_off));
s3c_disable_clocks(init_clocks_off, ARRAY_SIZE(init_clocks_off));
clkdev_add_table(s5p6440_clk_lookup, ARRAY_SIZE(s5p6440_clk_lookup));
s3c24xx_register_clock(&dummy_apb_pclk);
s3c_pwmclk_init();
}
