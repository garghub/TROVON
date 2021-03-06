static int aemif_calc_rate(int wanted, unsigned long clk, int max)
{
int result;
result = DIV_ROUND_UP((wanted * clk), NSEC_PER_MSEC) - 1;
pr_debug("%s: result %d from %ld, %d\n", __func__, result, clk, wanted);
if (result < 0)
result = 0;
else if (result > max)
result = -EINVAL;
return result;
}
int davinci_aemif_setup_timing(struct davinci_aemif_timing *t,
void __iomem *base, unsigned cs)
{
unsigned set, val;
int ta, rhold, rstrobe, rsetup, whold, wstrobe, wsetup;
unsigned offset = A1CR_OFFSET + cs * 4;
struct clk *aemif_clk;
unsigned long clkrate;
if (!t)
return 0;
aemif_clk = clk_get(NULL, "aemif");
if (IS_ERR(aemif_clk))
return PTR_ERR(aemif_clk);
clkrate = clk_get_rate(aemif_clk);
clkrate /= 1000;
ta = aemif_calc_rate(t->ta, clkrate, TA_MAX);
rhold = aemif_calc_rate(t->rhold, clkrate, RHOLD_MAX);
rstrobe = aemif_calc_rate(t->rstrobe, clkrate, RSTROBE_MAX);
rsetup = aemif_calc_rate(t->rsetup, clkrate, RSETUP_MAX);
whold = aemif_calc_rate(t->whold, clkrate, WHOLD_MAX);
wstrobe = aemif_calc_rate(t->wstrobe, clkrate, WSTROBE_MAX);
wsetup = aemif_calc_rate(t->wsetup, clkrate, WSETUP_MAX);
if (ta < 0 || rhold < 0 || rstrobe < 0 || rsetup < 0 ||
whold < 0 || wstrobe < 0 || wsetup < 0) {
pr_err("%s: cannot get suitable timings\n", __func__);
return -EINVAL;
}
set = TA(ta) | RHOLD(rhold) | RSTROBE(rstrobe) | RSETUP(rsetup) |
WHOLD(whold) | WSTROBE(wstrobe) | WSETUP(wsetup);
val = __raw_readl(base + offset);
val &= ~TIMING_MASK;
val |= set;
__raw_writel(val, base + offset);
return 0;
}
