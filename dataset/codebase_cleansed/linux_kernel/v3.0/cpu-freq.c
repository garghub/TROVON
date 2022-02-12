static int s3c2412_cpufreq_calcdivs(struct s3c_cpufreq_config *cfg)
{
unsigned int hdiv, pdiv, armdiv, dvs;
unsigned long hclk, fclk, armclk, armdiv_clk;
unsigned long hclk_max;
fclk = cfg->freq.fclk;
armclk = cfg->freq.armclk;
hclk_max = cfg->max.hclk;
if (hclk_max > armclk)
hclk_max = armclk;
s3c_freq_dbg("%s: fclk=%lu, armclk=%lu, hclk_max=%lu\n",
__func__, fclk, armclk, hclk_max);
s3c_freq_dbg("%s: want f=%lu, arm=%lu, h=%lu, p=%lu\n",
__func__, cfg->freq.fclk, cfg->freq.armclk,
cfg->freq.hclk, cfg->freq.pclk);
armdiv = fclk / armclk;
if (armdiv < 1)
armdiv = 1;
if (armdiv > 2)
armdiv = 2;
cfg->divs.arm_divisor = armdiv;
armdiv_clk = fclk / armdiv;
hdiv = armdiv_clk / hclk_max;
if (hdiv < 1)
hdiv = 1;
cfg->freq.hclk = hclk = armdiv_clk / hdiv;
cfg->divs.dvs = dvs = armclk < armdiv_clk;
cfg->freq.armclk = dvs ? hclk : armdiv_clk;
s3c_freq_dbg("%s: armclk %lu, hclk %lu, armdiv %d, hdiv %d, dvs %d\n",
__func__, armclk, hclk, armdiv, hdiv, cfg->divs.dvs);
if (hdiv > 4)
goto invalid;
pdiv = (hclk > cfg->max.pclk) ? 2 : 1;
if ((hclk / pdiv) > cfg->max.pclk)
pdiv++;
cfg->freq.pclk = hclk / pdiv;
s3c_freq_dbg("%s: pdiv %d\n", __func__, pdiv);
if (pdiv > 2)
goto invalid;
pdiv *= hdiv;
cfg->divs.h_divisor = hdiv * armdiv;
cfg->divs.p_divisor = pdiv * armdiv;
return 0;
invalid:
return -EINVAL;
}
static void s3c2412_cpufreq_setdivs(struct s3c_cpufreq_config *cfg)
{
unsigned long clkdiv;
unsigned long olddiv;
olddiv = clkdiv = __raw_readl(S3C2410_CLKDIVN);
clkdiv &= ~S3C2412_CLKDIVN_ARMDIVN;
clkdiv &= ~S3C2412_CLKDIVN_HDIVN_MASK;
clkdiv &= ~S3C2412_CLKDIVN_PDIVN;
if (cfg->divs.arm_divisor == 2)
clkdiv |= S3C2412_CLKDIVN_ARMDIVN;
clkdiv |= ((cfg->divs.h_divisor / cfg->divs.arm_divisor) - 1);
if (cfg->divs.p_divisor != cfg->divs.h_divisor)
clkdiv |= S3C2412_CLKDIVN_PDIVN;
s3c_freq_dbg("%s: div %08lx => %08lx\n", __func__, olddiv, clkdiv);
__raw_writel(clkdiv, S3C2410_CLKDIVN);
clk_set_parent(armclk, cfg->divs.dvs ? hclk : fclk);
}
static void s3c2412_cpufreq_setrefresh(struct s3c_cpufreq_config *cfg)
{
struct s3c_cpufreq_board *board = cfg->board;
unsigned long refresh;
s3c_freq_dbg("%s: refresh %u ns, hclk %lu\n", __func__,
board->refresh, cfg->freq.hclk);
refresh = (board->refresh / 10);
refresh *= (cfg->freq.hclk / 100);
refresh /= (1 * 1000 * 1000);
s3c_freq_dbg("%s: setting refresh 0x%08lx\n", __func__, refresh);
__raw_writel(refresh, S3C2412_REFRESH);
}
static int s3c2412_cpufreq_add(struct sys_device *sysdev)
{
unsigned long fclk_rate;
hclk = clk_get(NULL, "hclk");
if (IS_ERR(hclk)) {
printk(KERN_ERR "%s: cannot find hclk clock\n", __func__);
return -ENOENT;
}
fclk = clk_get(NULL, "fclk");
if (IS_ERR(fclk)) {
printk(KERN_ERR "%s: cannot find fclk clock\n", __func__);
goto err_fclk;
}
fclk_rate = clk_get_rate(fclk);
if (fclk_rate > 200000000) {
printk(KERN_INFO
"%s: fclk %ld MHz, assuming 266MHz capable part\n",
__func__, fclk_rate / 1000000);
s3c2412_cpufreq_info.max.fclk = 266000000;
s3c2412_cpufreq_info.max.hclk = 133000000;
s3c2412_cpufreq_info.max.pclk = 66000000;
}
armclk = clk_get(NULL, "armclk");
if (IS_ERR(armclk)) {
printk(KERN_ERR "%s: cannot find arm clock\n", __func__);
goto err_armclk;
}
xtal = clk_get(NULL, "xtal");
if (IS_ERR(xtal)) {
printk(KERN_ERR "%s: cannot find xtal clock\n", __func__);
goto err_xtal;
}
return s3c_cpufreq_register(&s3c2412_cpufreq_info);
err_xtal:
clk_put(armclk);
err_armclk:
clk_put(fclk);
err_fclk:
clk_put(hclk);
return -ENOENT;
}
static int s3c2412_cpufreq_init(void)
{
return sysdev_driver_register(&s3c2412_sysclass,
&s3c2412_cpufreq_driver);
}
