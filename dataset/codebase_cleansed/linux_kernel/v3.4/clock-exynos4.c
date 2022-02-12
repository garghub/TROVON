static int exynos4_clksrc_mask_top_ctrl(struct clk *clk, int enable)
{
return s5p_gatectrl(EXYNOS4_CLKSRC_MASK_TOP, clk, enable);
}
static int exynos4_clksrc_mask_cam_ctrl(struct clk *clk, int enable)
{
return s5p_gatectrl(EXYNOS4_CLKSRC_MASK_CAM, clk, enable);
}
static int exynos4_clksrc_mask_lcd0_ctrl(struct clk *clk, int enable)
{
return s5p_gatectrl(EXYNOS4_CLKSRC_MASK_LCD0, clk, enable);
}
int exynos4_clksrc_mask_fsys_ctrl(struct clk *clk, int enable)
{
return s5p_gatectrl(EXYNOS4_CLKSRC_MASK_FSYS, clk, enable);
}
static int exynos4_clksrc_mask_peril0_ctrl(struct clk *clk, int enable)
{
return s5p_gatectrl(EXYNOS4_CLKSRC_MASK_PERIL0, clk, enable);
}
static int exynos4_clksrc_mask_peril1_ctrl(struct clk *clk, int enable)
{
return s5p_gatectrl(EXYNOS4_CLKSRC_MASK_PERIL1, clk, enable);
}
static int exynos4_clk_ip_mfc_ctrl(struct clk *clk, int enable)
{
return s5p_gatectrl(EXYNOS4_CLKGATE_IP_MFC, clk, enable);
}
static int exynos4_clksrc_mask_tv_ctrl(struct clk *clk, int enable)
{
return s5p_gatectrl(EXYNOS4_CLKSRC_MASK_TV, clk, enable);
}
static int exynos4_clk_ip_cam_ctrl(struct clk *clk, int enable)
{
return s5p_gatectrl(EXYNOS4_CLKGATE_IP_CAM, clk, enable);
}
static int exynos4_clk_ip_tv_ctrl(struct clk *clk, int enable)
{
return s5p_gatectrl(EXYNOS4_CLKGATE_IP_TV, clk, enable);
}
static int exynos4_clk_ip_image_ctrl(struct clk *clk, int enable)
{
return s5p_gatectrl(EXYNOS4_CLKGATE_IP_IMAGE, clk, enable);
}
static int exynos4_clk_ip_lcd0_ctrl(struct clk *clk, int enable)
{
return s5p_gatectrl(EXYNOS4_CLKGATE_IP_LCD0, clk, enable);
}
int exynos4_clk_ip_lcd1_ctrl(struct clk *clk, int enable)
{
return s5p_gatectrl(EXYNOS4210_CLKGATE_IP_LCD1, clk, enable);
}
int exynos4_clk_ip_fsys_ctrl(struct clk *clk, int enable)
{
return s5p_gatectrl(EXYNOS4_CLKGATE_IP_FSYS, clk, enable);
}
static int exynos4_clk_ip_peril_ctrl(struct clk *clk, int enable)
{
return s5p_gatectrl(EXYNOS4_CLKGATE_IP_PERIL, clk, enable);
}
static int exynos4_clk_ip_perir_ctrl(struct clk *clk, int enable)
{
return s5p_gatectrl(EXYNOS4_CLKGATE_IP_PERIR, clk, enable);
}
static int exynos4_clk_hdmiphy_ctrl(struct clk *clk, int enable)
{
return s5p_gatectrl(S5P_HDMI_PHY_CONTROL, clk, enable);
}
static int exynos4_clk_dac_ctrl(struct clk *clk, int enable)
{
return s5p_gatectrl(S5P_DAC_PHY_CONTROL, clk, enable);
}
static unsigned long exynos4_fout_apll_get_rate(struct clk *clk)
{
if (soc_is_exynos4210())
return s5p_get_pll45xx(xtal_rate, __raw_readl(EXYNOS4_APLL_CON0),
pll_4508);
else if (soc_is_exynos4212() || soc_is_exynos4412())
return s5p_get_pll35xx(xtal_rate, __raw_readl(EXYNOS4_APLL_CON0));
else
return 0;
}
static unsigned long exynos4_vpll_get_rate(struct clk *clk)
{
return clk->rate;
}
static int exynos4_vpll_set_rate(struct clk *clk, unsigned long rate)
{
unsigned int vpll_con0, vpll_con1 = 0;
unsigned int i;
if (clk->rate == rate)
return 0;
vpll_con0 = __raw_readl(EXYNOS4_VPLL_CON0);
vpll_con0 &= ~(0x1 << 27 | \
PLL90XX_MDIV_MASK << PLL46XX_MDIV_SHIFT | \
PLL90XX_PDIV_MASK << PLL46XX_PDIV_SHIFT | \
PLL90XX_SDIV_MASK << PLL46XX_SDIV_SHIFT);
vpll_con1 = __raw_readl(EXYNOS4_VPLL_CON1);
vpll_con1 &= ~(PLL46XX_MRR_MASK << PLL46XX_MRR_SHIFT | \
PLL46XX_MFR_MASK << PLL46XX_MFR_SHIFT | \
PLL4650C_KDIV_MASK << PLL46XX_KDIV_SHIFT);
for (i = 0; i < ARRAY_SIZE(exynos4_vpll_div); i++) {
if (exynos4_vpll_div[i][0] == rate) {
vpll_con0 |= exynos4_vpll_div[i][1] << PLL46XX_PDIV_SHIFT;
vpll_con0 |= exynos4_vpll_div[i][2] << PLL46XX_MDIV_SHIFT;
vpll_con0 |= exynos4_vpll_div[i][3] << PLL46XX_SDIV_SHIFT;
vpll_con1 |= exynos4_vpll_div[i][4] << PLL46XX_KDIV_SHIFT;
vpll_con1 |= exynos4_vpll_div[i][5] << PLL46XX_MFR_SHIFT;
vpll_con1 |= exynos4_vpll_div[i][6] << PLL46XX_MRR_SHIFT;
vpll_con0 |= exynos4_vpll_div[i][7] << 27;
break;
}
}
if (i == ARRAY_SIZE(exynos4_vpll_div)) {
printk(KERN_ERR "%s: Invalid Clock VPLL Frequency\n",
__func__);
return -EINVAL;
}
__raw_writel(vpll_con0, EXYNOS4_VPLL_CON0);
__raw_writel(vpll_con1, EXYNOS4_VPLL_CON1);
while (!(__raw_readl(EXYNOS4_VPLL_CON0) & (1 << PLL46XX_LOCKED_SHIFT)))
continue;
clk->rate = rate;
return 0;
}
void __init_or_cpufreq exynos4_setup_clocks(void)
{
struct clk *xtal_clk;
unsigned long apll = 0;
unsigned long mpll = 0;
unsigned long epll = 0;
unsigned long vpll = 0;
unsigned long vpllsrc;
unsigned long xtal;
unsigned long armclk;
unsigned long sclk_dmc;
unsigned long aclk_200;
unsigned long aclk_100;
unsigned long aclk_160;
unsigned long aclk_133;
unsigned int ptr;
printk(KERN_DEBUG "%s: registering clocks\n", __func__);
xtal_clk = clk_get(NULL, "xtal");
BUG_ON(IS_ERR(xtal_clk));
xtal = clk_get_rate(xtal_clk);
xtal_rate = xtal;
clk_put(xtal_clk);
printk(KERN_DEBUG "%s: xtal is %ld\n", __func__, xtal);
if (soc_is_exynos4210()) {
apll = s5p_get_pll45xx(xtal, __raw_readl(EXYNOS4_APLL_CON0),
pll_4508);
mpll = s5p_get_pll45xx(xtal, __raw_readl(EXYNOS4_MPLL_CON0),
pll_4508);
epll = s5p_get_pll46xx(xtal, __raw_readl(EXYNOS4_EPLL_CON0),
__raw_readl(EXYNOS4_EPLL_CON1), pll_4600);
vpllsrc = clk_get_rate(&exynos4_clk_vpllsrc.clk);
vpll = s5p_get_pll46xx(vpllsrc, __raw_readl(EXYNOS4_VPLL_CON0),
__raw_readl(EXYNOS4_VPLL_CON1), pll_4650c);
} else if (soc_is_exynos4212() || soc_is_exynos4412()) {
apll = s5p_get_pll35xx(xtal, __raw_readl(EXYNOS4_APLL_CON0));
mpll = s5p_get_pll35xx(xtal, __raw_readl(EXYNOS4_MPLL_CON0));
epll = s5p_get_pll36xx(xtal, __raw_readl(EXYNOS4_EPLL_CON0),
__raw_readl(EXYNOS4_EPLL_CON1));
vpllsrc = clk_get_rate(&exynos4_clk_vpllsrc.clk);
vpll = s5p_get_pll36xx(vpllsrc, __raw_readl(EXYNOS4_VPLL_CON0),
__raw_readl(EXYNOS4_VPLL_CON1));
} else {
}
clk_fout_apll.ops = &exynos4_fout_apll_ops;
clk_fout_mpll.rate = mpll;
clk_fout_epll.rate = epll;
clk_fout_vpll.ops = &exynos4_vpll_ops;
clk_fout_vpll.rate = vpll;
printk(KERN_INFO "EXYNOS4: PLL settings, A=%ld, M=%ld, E=%ld V=%ld",
apll, mpll, epll, vpll);
armclk = clk_get_rate(&exynos4_clk_armclk.clk);
sclk_dmc = clk_get_rate(&exynos4_clk_sclk_dmc.clk);
aclk_200 = clk_get_rate(&exynos4_clk_aclk_200.clk);
aclk_100 = clk_get_rate(&exynos4_clk_aclk_100.clk);
aclk_160 = clk_get_rate(&exynos4_clk_aclk_160.clk);
aclk_133 = clk_get_rate(&exynos4_clk_aclk_133.clk);
printk(KERN_INFO "EXYNOS4: ARMCLK=%ld, DMC=%ld, ACLK200=%ld\n"
"ACLK100=%ld, ACLK160=%ld, ACLK133=%ld\n",
armclk, sclk_dmc, aclk_200,
aclk_100, aclk_160, aclk_133);
clk_f.rate = armclk;
clk_h.rate = sclk_dmc;
clk_p.rate = aclk_100;
for (ptr = 0; ptr < ARRAY_SIZE(exynos4_clksrcs); ptr++)
s3c_set_clksrc(&exynos4_clksrcs[ptr], true);
}
static int exynos4_clock_suspend(void)
{
s3c_pm_do_save(exynos4_clock_save, ARRAY_SIZE(exynos4_clock_save));
return 0;
}
static void exynos4_clock_resume(void)
{
s3c_pm_do_restore_core(exynos4_clock_save, ARRAY_SIZE(exynos4_clock_save));
}
void __init exynos4_register_clocks(void)
{
int ptr;
s3c24xx_register_clocks(exynos4_clks, ARRAY_SIZE(exynos4_clks));
for (ptr = 0; ptr < ARRAY_SIZE(exynos4_sysclks); ptr++)
s3c_register_clksrc(exynos4_sysclks[ptr], 1);
for (ptr = 0; ptr < ARRAY_SIZE(exynos4_sclk_tv); ptr++)
s3c_register_clksrc(exynos4_sclk_tv[ptr], 1);
for (ptr = 0; ptr < ARRAY_SIZE(exynos4_clksrc_cdev); ptr++)
s3c_register_clksrc(exynos4_clksrc_cdev[ptr], 1);
s3c_register_clksrc(exynos4_clksrcs, ARRAY_SIZE(exynos4_clksrcs));
s3c_register_clocks(exynos4_init_clocks_on, ARRAY_SIZE(exynos4_init_clocks_on));
s3c24xx_register_clocks(exynos4_clk_cdev, ARRAY_SIZE(exynos4_clk_cdev));
for (ptr = 0; ptr < ARRAY_SIZE(exynos4_clk_cdev); ptr++)
s3c_disable_clocks(exynos4_clk_cdev[ptr], 1);
s3c_register_clocks(exynos4_init_clocks_off, ARRAY_SIZE(exynos4_init_clocks_off));
s3c_disable_clocks(exynos4_init_clocks_off, ARRAY_SIZE(exynos4_init_clocks_off));
clkdev_add_table(exynos4_clk_lookup, ARRAY_SIZE(exynos4_clk_lookup));
register_syscore_ops(&exynos4_clock_syscore_ops);
s3c24xx_register_clock(&dummy_apb_pclk);
s3c_pwmclk_init();
}
