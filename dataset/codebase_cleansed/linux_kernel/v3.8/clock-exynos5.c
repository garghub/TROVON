static int exynos5_clksrc_mask_top_ctrl(struct clk *clk, int enable)
{
return s5p_gatectrl(EXYNOS5_CLKSRC_MASK_TOP, clk, enable);
}
static int exynos5_clksrc_mask_disp1_0_ctrl(struct clk *clk, int enable)
{
return s5p_gatectrl(EXYNOS5_CLKSRC_MASK_DISP1_0, clk, enable);
}
static int exynos5_clksrc_mask_fsys_ctrl(struct clk *clk, int enable)
{
return s5p_gatectrl(EXYNOS5_CLKSRC_MASK_FSYS, clk, enable);
}
static int exynos5_clksrc_mask_gscl_ctrl(struct clk *clk, int enable)
{
return s5p_gatectrl(EXYNOS5_CLKSRC_MASK_GSCL, clk, enable);
}
static int exynos5_clksrc_mask_peric0_ctrl(struct clk *clk, int enable)
{
return s5p_gatectrl(EXYNOS5_CLKSRC_MASK_PERIC0, clk, enable);
}
static int exynos5_clksrc_mask_peric1_ctrl(struct clk *clk, int enable)
{
return s5p_gatectrl(EXYNOS5_CLKSRC_MASK_PERIC1, clk, enable);
}
static int exynos5_clk_ip_acp_ctrl(struct clk *clk, int enable)
{
return s5p_gatectrl(EXYNOS5_CLKGATE_IP_ACP, clk, enable);
}
static int exynos5_clk_ip_core_ctrl(struct clk *clk, int enable)
{
return s5p_gatectrl(EXYNOS5_CLKGATE_IP_CORE, clk, enable);
}
static int exynos5_clk_ip_disp1_ctrl(struct clk *clk, int enable)
{
return s5p_gatectrl(EXYNOS5_CLKGATE_IP_DISP1, clk, enable);
}
static int exynos5_clk_ip_fsys_ctrl(struct clk *clk, int enable)
{
return s5p_gatectrl(EXYNOS5_CLKGATE_IP_FSYS, clk, enable);
}
static int exynos5_clk_block_ctrl(struct clk *clk, int enable)
{
return s5p_gatectrl(EXYNOS5_CLKGATE_BLOCK, clk, enable);
}
static int exynos5_clk_ip_gen_ctrl(struct clk *clk, int enable)
{
return s5p_gatectrl(EXYNOS5_CLKGATE_IP_GEN, clk, enable);
}
static int exynos5_clk_ip_mfc_ctrl(struct clk *clk, int enable)
{
return s5p_gatectrl(EXYNOS5_CLKGATE_IP_MFC, clk, enable);
}
static int exynos5_clk_ip_peric_ctrl(struct clk *clk, int enable)
{
return s5p_gatectrl(EXYNOS5_CLKGATE_IP_PERIC, clk, enable);
}
static int exynos5_clk_ip_peris_ctrl(struct clk *clk, int enable)
{
return s5p_gatectrl(EXYNOS5_CLKGATE_IP_PERIS, clk, enable);
}
static int exynos5_clk_ip_gscl_ctrl(struct clk *clk, int enable)
{
return s5p_gatectrl(EXYNOS5_CLKGATE_IP_GSCL, clk, enable);
}
static int exynos5_clk_ip_isp0_ctrl(struct clk *clk, int enable)
{
return s5p_gatectrl(EXYNOS5_CLKGATE_IP_ISP0, clk, enable);
}
static int exynos5_clk_ip_isp1_ctrl(struct clk *clk, int enable)
{
return s5p_gatectrl(EXYNOS5_CLKGATE_IP_ISP1, clk, enable);
}
static int exynos5_clk_hdmiphy_ctrl(struct clk *clk, int enable)
{
return s5p_gatectrl(S5P_HDMI_PHY_CONTROL, clk, enable);
}
static unsigned long exynos5_epll_get_rate(struct clk *clk)
{
return clk->rate;
}
static int exynos5_epll_set_rate(struct clk *clk, unsigned long rate)
{
unsigned int epll_con, epll_con_k;
unsigned int i;
unsigned int tmp;
unsigned int epll_rate;
unsigned int locktime;
unsigned int lockcnt;
if (clk->rate == rate)
return 0;
if (clk->parent)
epll_rate = clk_get_rate(clk->parent);
else
epll_rate = clk_ext_xtal_mux.rate;
if (epll_rate != 24000000) {
pr_err("Invalid Clock : recommended clock is 24MHz.\n");
return -EINVAL;
}
epll_con = __raw_readl(EXYNOS5_EPLL_CON0);
epll_con &= ~(0x1 << 27 | \
PLL46XX_MDIV_MASK << PLL46XX_MDIV_SHIFT | \
PLL46XX_PDIV_MASK << PLL46XX_PDIV_SHIFT | \
PLL46XX_SDIV_MASK << PLL46XX_SDIV_SHIFT);
for (i = 0; i < ARRAY_SIZE(epll_div); i++) {
if (epll_div[i][0] == rate) {
epll_con_k = epll_div[i][5] << 0;
epll_con |= epll_div[i][1] << 27;
epll_con |= epll_div[i][2] << PLL46XX_MDIV_SHIFT;
epll_con |= epll_div[i][3] << PLL46XX_PDIV_SHIFT;
epll_con |= epll_div[i][4] << PLL46XX_SDIV_SHIFT;
break;
}
}
if (i == ARRAY_SIZE(epll_div)) {
printk(KERN_ERR "%s: Invalid Clock EPLL Frequency\n",
__func__);
return -EINVAL;
}
epll_rate /= 1000000;
locktime = 3000 / epll_rate * epll_div[i][3];
lockcnt = locktime * 10000 / (10000 / epll_rate);
__raw_writel(lockcnt, EXYNOS5_EPLL_LOCK);
__raw_writel(epll_con, EXYNOS5_EPLL_CON0);
__raw_writel(epll_con_k, EXYNOS5_EPLL_CON1);
do {
tmp = __raw_readl(EXYNOS5_EPLL_CON0);
} while (!(tmp & 0x1 << EXYNOS5_EPLLCON0_LOCKED_SHIFT));
clk->rate = rate;
return 0;
}
static unsigned long exynos5_fout_apll_get_rate(struct clk *clk)
{
return s5p_get_pll35xx(xtal_rate, __raw_readl(EXYNOS5_APLL_CON0));
}
static int exynos5_clock_suspend(void)
{
s3c_pm_do_save(exynos5_clock_save, ARRAY_SIZE(exynos5_clock_save));
return 0;
}
static void exynos5_clock_resume(void)
{
s3c_pm_do_restore_core(exynos5_clock_save, ARRAY_SIZE(exynos5_clock_save));
}
void __init_or_cpufreq exynos5_setup_clocks(void)
{
struct clk *xtal_clk;
unsigned long apll;
unsigned long bpll;
unsigned long cpll;
unsigned long mpll;
unsigned long epll;
unsigned long vpll;
unsigned long vpllsrc;
unsigned long xtal;
unsigned long armclk;
unsigned long mout_cdrex;
unsigned long aclk_400;
unsigned long aclk_333;
unsigned long aclk_266;
unsigned long aclk_200;
unsigned long aclk_166;
unsigned long aclk_66;
unsigned int ptr;
printk(KERN_DEBUG "%s: registering clocks\n", __func__);
xtal_clk = clk_get(NULL, "xtal");
BUG_ON(IS_ERR(xtal_clk));
xtal = clk_get_rate(xtal_clk);
xtal_rate = xtal;
clk_put(xtal_clk);
printk(KERN_DEBUG "%s: xtal is %ld\n", __func__, xtal);
apll = s5p_get_pll35xx(xtal, __raw_readl(EXYNOS5_APLL_CON0));
bpll = s5p_get_pll35xx(xtal, __raw_readl(EXYNOS5_BPLL_CON0));
cpll = s5p_get_pll35xx(xtal, __raw_readl(EXYNOS5_CPLL_CON0));
mpll = s5p_get_pll35xx(xtal, __raw_readl(EXYNOS5_MPLL_CON0));
epll = s5p_get_pll36xx(xtal, __raw_readl(EXYNOS5_EPLL_CON0),
__raw_readl(EXYNOS5_EPLL_CON1));
vpllsrc = clk_get_rate(&exynos5_clk_vpllsrc.clk);
vpll = s5p_get_pll36xx(vpllsrc, __raw_readl(EXYNOS5_VPLL_CON0),
__raw_readl(EXYNOS5_VPLL_CON1));
clk_fout_apll.ops = &exynos5_fout_apll_ops;
clk_fout_bpll.rate = bpll;
clk_fout_bpll_div2.rate = bpll >> 1;
clk_fout_cpll.rate = cpll;
clk_fout_mpll.rate = mpll;
clk_fout_mpll_div2.rate = mpll >> 1;
clk_fout_epll.rate = epll;
clk_fout_vpll.rate = vpll;
printk(KERN_INFO "EXYNOS5: PLL settings, A=%ld, B=%ld, C=%ld\n"
"M=%ld, E=%ld V=%ld",
apll, bpll, cpll, mpll, epll, vpll);
armclk = clk_get_rate(&exynos5_clk_armclk);
mout_cdrex = clk_get_rate(&exynos5_clk_cdrex.clk);
aclk_400 = clk_get_rate(&exynos5_clk_aclk_400.clk);
aclk_333 = clk_get_rate(&exynos5_clk_aclk_333.clk);
aclk_266 = clk_get_rate(&exynos5_clk_aclk_266.clk);
aclk_200 = clk_get_rate(&exynos5_clk_aclk_200.clk);
aclk_166 = clk_get_rate(&exynos5_clk_aclk_166.clk);
aclk_66 = clk_get_rate(&exynos5_clk_aclk_66.clk);
printk(KERN_INFO "EXYNOS5: ARMCLK=%ld, CDREX=%ld, ACLK400=%ld\n"
"ACLK333=%ld, ACLK266=%ld, ACLK200=%ld\n"
"ACLK166=%ld, ACLK66=%ld\n",
armclk, mout_cdrex, aclk_400,
aclk_333, aclk_266, aclk_200,
aclk_166, aclk_66);
clk_fout_epll.ops = &exynos5_epll_ops;
if (clk_set_parent(&exynos5_clk_mout_epll.clk, &clk_fout_epll))
printk(KERN_ERR "Unable to set parent %s of clock %s.\n",
clk_fout_epll.name, exynos5_clk_mout_epll.clk.name);
clk_set_rate(&exynos5_clk_sclk_apll.clk, 100000000);
clk_set_rate(&exynos5_clk_aclk_266.clk, 300000000);
clk_set_rate(&exynos5_clk_aclk_acp.clk, 267000000);
clk_set_rate(&exynos5_clk_pclk_acp.clk, 134000000);
for (ptr = 0; ptr < ARRAY_SIZE(exynos5_clksrcs); ptr++)
s3c_set_clksrc(&exynos5_clksrcs[ptr], true);
}
void __init exynos5_register_clocks(void)
{
int ptr;
s3c24xx_register_clocks(exynos5_clks, ARRAY_SIZE(exynos5_clks));
for (ptr = 0; ptr < ARRAY_SIZE(exynos5_sysclks); ptr++)
s3c_register_clksrc(exynos5_sysclks[ptr], 1);
for (ptr = 0; ptr < ARRAY_SIZE(exynos5_sclk_tv); ptr++)
s3c_register_clksrc(exynos5_sclk_tv[ptr], 1);
for (ptr = 0; ptr < ARRAY_SIZE(exynos5_clksrc_cdev); ptr++)
s3c_register_clksrc(exynos5_clksrc_cdev[ptr], 1);
s3c_register_clksrc(exynos5_clksrcs, ARRAY_SIZE(exynos5_clksrcs));
s3c_register_clocks(exynos5_init_clocks_on, ARRAY_SIZE(exynos5_init_clocks_on));
s3c24xx_register_clocks(exynos5_clk_cdev, ARRAY_SIZE(exynos5_clk_cdev));
for (ptr = 0; ptr < ARRAY_SIZE(exynos5_clk_cdev); ptr++)
s3c_disable_clocks(exynos5_clk_cdev[ptr], 1);
s3c_register_clocks(exynos5_init_clocks_off, ARRAY_SIZE(exynos5_init_clocks_off));
s3c_disable_clocks(exynos5_init_clocks_off, ARRAY_SIZE(exynos5_init_clocks_off));
clkdev_add_table(exynos5_clk_lookup, ARRAY_SIZE(exynos5_clk_lookup));
register_syscore_ops(&exynos5_clock_syscore_ops);
s3c_pwmclk_init();
}
