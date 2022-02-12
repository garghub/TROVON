static inline int within_khz(unsigned long a, unsigned long b)
{
long diff = a - b;
return (diff >= -1000 && diff <= 1000);
}
static int s3c2440_cpufreq_calcdivs(struct s3c_cpufreq_config *cfg)
{
unsigned int hdiv, pdiv;
unsigned long hclk, fclk, armclk;
unsigned long hclk_max;
fclk = cfg->freq.fclk;
armclk = cfg->freq.armclk;
hclk_max = cfg->max.hclk;
s3c_freq_dbg("%s: fclk is %lu, armclk %lu, max hclk %lu\n",
__func__, fclk, armclk, hclk_max);
if (armclk > fclk) {
pr_warn("%s: armclk > fclk\n", __func__);
armclk = fclk;
}
if (armclk < fclk && armclk < hclk_max)
hclk_max = armclk;
for (hdiv = 1; hdiv < 9; hdiv++) {
if (hdiv == 5 || hdiv == 7)
hdiv++;
hclk = (fclk / hdiv);
if (hclk <= hclk_max || within_khz(hclk, hclk_max))
break;
}
s3c_freq_dbg("%s: hclk %lu, div %d\n", __func__, hclk, hdiv);
if (hdiv > 8)
goto invalid;
pdiv = (hclk > cfg->max.pclk) ? 2 : 1;
if ((hclk / pdiv) > cfg->max.pclk)
pdiv++;
s3c_freq_dbg("%s: pdiv %d\n", __func__, pdiv);
if (pdiv > 2)
goto invalid;
pdiv *= hdiv;
if (armclk < hclk)
armclk = hclk;
if (armclk < fclk) {
cfg->divs.dvs = 1;
armclk = hclk;
} else
cfg->divs.dvs = 0;
cfg->freq.armclk = armclk;
cfg->divs.h_divisor = hdiv;
cfg->divs.p_divisor = pdiv;
return 0;
invalid:
return -EINVAL;
}
static void s3c2440_cpufreq_setdivs(struct s3c_cpufreq_config *cfg)
{
unsigned long clkdiv, camdiv;
s3c_freq_dbg("%s: divsiors: h=%d, p=%d\n", __func__,
cfg->divs.h_divisor, cfg->divs.p_divisor);
clkdiv = __raw_readl(S3C2410_CLKDIVN);
camdiv = __raw_readl(S3C2440_CAMDIVN);
clkdiv &= ~(S3C2440_CLKDIVN_HDIVN_MASK | S3C2440_CLKDIVN_PDIVN);
camdiv &= ~CAMDIVN_HCLK_HALF;
switch (cfg->divs.h_divisor) {
case 1:
clkdiv |= S3C2440_CLKDIVN_HDIVN_1;
break;
case 2:
clkdiv |= S3C2440_CLKDIVN_HDIVN_2;
break;
case 6:
camdiv |= S3C2440_CAMDIVN_HCLK3_HALF;
case 3:
clkdiv |= S3C2440_CLKDIVN_HDIVN_3_6;
break;
case 8:
camdiv |= S3C2440_CAMDIVN_HCLK4_HALF;
case 4:
clkdiv |= S3C2440_CLKDIVN_HDIVN_4_8;
break;
default:
BUG();
}
if (cfg->divs.p_divisor != cfg->divs.h_divisor)
clkdiv |= S3C2440_CLKDIVN_PDIVN;
__raw_writel(camdiv | CAMDIVN_HCLK_HALF, S3C2440_CAMDIVN);
__raw_writel(clkdiv, S3C2410_CLKDIVN);
ndelay(20);
__raw_writel(camdiv, S3C2440_CAMDIVN);
clk_set_parent(armclk, cfg->divs.dvs ? hclk : fclk);
}
static int run_freq_for(unsigned long max_hclk, unsigned long fclk,
int *divs,
struct cpufreq_frequency_table *table,
size_t table_size)
{
unsigned long freq;
int index = 0;
int div;
for (div = *divs; div > 0; div = *divs++) {
freq = fclk / div;
if (freq > max_hclk && div != 1)
continue;
freq /= 1000;
index = s3c_cpufreq_addfreq(table, index, table_size, freq);
if (index < 0)
break;
}
return index;
}
static int s3c2440_cpufreq_calctable(struct s3c_cpufreq_config *cfg,
struct cpufreq_frequency_table *table,
size_t table_size)
{
int ret;
WARN_ON(cfg->info == NULL);
WARN_ON(cfg->board == NULL);
ret = run_freq_for(cfg->info->max.hclk,
cfg->info->max.fclk,
hclk_divs,
table, table_size);
s3c_freq_dbg("%s: returning %d\n", __func__, ret);
return ret;
}
static int s3c2440_cpufreq_add(struct device *dev,
struct subsys_interface *sif)
{
xtal = s3c_cpufreq_clk_get(NULL, "xtal");
hclk = s3c_cpufreq_clk_get(NULL, "hclk");
fclk = s3c_cpufreq_clk_get(NULL, "fclk");
armclk = s3c_cpufreq_clk_get(NULL, "armclk");
if (IS_ERR(xtal) || IS_ERR(hclk) || IS_ERR(fclk) || IS_ERR(armclk)) {
pr_err("%s: failed to get clocks\n", __func__);
return -ENOENT;
}
return s3c_cpufreq_register(&s3c2440_cpufreq_info);
}
static int s3c2440_cpufreq_init(void)
{
return subsys_interface_register(&s3c2440_cpufreq_interface);
}
static int s3c2442_cpufreq_init(void)
{
return subsys_interface_register(&s3c2442_cpufreq_interface);
}
