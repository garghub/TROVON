static void s3c2410_cpufreq_setdivs(struct s3c_cpufreq_config *cfg)
{
u32 clkdiv = 0;
if (cfg->divs.h_divisor == 2)
clkdiv |= S3C2410_CLKDIVN_HDIVN;
if (cfg->divs.p_divisor != cfg->divs.h_divisor)
clkdiv |= S3C2410_CLKDIVN_PDIVN;
__raw_writel(clkdiv, S3C2410_CLKDIVN);
}
static int s3c2410_cpufreq_calcdivs(struct s3c_cpufreq_config *cfg)
{
unsigned long hclk, fclk, pclk;
unsigned int hdiv, pdiv;
unsigned long hclk_max;
fclk = cfg->freq.fclk;
hclk_max = cfg->max.hclk;
cfg->freq.armclk = fclk;
s3c_freq_dbg("%s: fclk is %lu, max hclk %lu\n",
__func__, fclk, hclk_max);
hdiv = (fclk > cfg->max.hclk) ? 2 : 1;
hclk = fclk / hdiv;
if (hclk > cfg->max.hclk) {
s3c_freq_dbg("%s: hclk too big\n", __func__);
return -EINVAL;
}
pdiv = (hclk > cfg->max.pclk) ? 2 : 1;
pclk = hclk / pdiv;
if (pclk > cfg->max.pclk) {
s3c_freq_dbg("%s: pclk too big\n", __func__);
return -EINVAL;
}
pdiv *= hdiv;
cfg->divs.p_divisor = pdiv;
cfg->divs.h_divisor = hdiv;
return 0;
}
static int s3c2410_cpufreq_add(struct device *dev,
struct subsys_interface *sif)
{
return s3c_cpufreq_register(&s3c2410_cpufreq_info);
}
static int __init s3c2410_cpufreq_init(void)
{
return subsys_interface_register(&s3c2410_cpufreq_interface);
}
static int s3c2410a_cpufreq_add(struct device *dev,
struct subsys_interface *sif)
{
s3c2410_cpufreq_info.max.fclk = 266000000;
s3c2410_cpufreq_info.max.hclk = 133000000;
s3c2410_cpufreq_info.max.pclk = 66500000;
s3c2410_cpufreq_info.name = "s3c2410a";
return s3c2410_cpufreq_add(dev, sif);
}
static int __init s3c2410a_cpufreq_init(void)
{
return subsys_interface_register(&s3c2410a_cpufreq_interface);
}
