void s3c2410_cpufreq_setrefresh(struct s3c_cpufreq_config *cfg)
{
struct s3c_cpufreq_board *board = cfg->board;
unsigned long refresh;
unsigned long refval;
refresh = (cfg->freq.hclk / 100) * (board->refresh / 10);
refresh = DIV_ROUND_UP(refresh, (1000 * 1000));
refresh = (1 << 11) + 1 - refresh;
s3c_freq_dbg("%s: refresh value %lu\n", __func__, refresh);
refval = __raw_readl(S3C2410_REFRESH);
refval &= ~((1 << 12) - 1);
refval |= refresh;
__raw_writel(refval, S3C2410_REFRESH);
}
void s3c2410_set_fvco(struct s3c_cpufreq_config *cfg)
{
if (!IS_ERR(cfg->mpll))
clk_set_rate(cfg->mpll, cfg->pll.frequency);
}
