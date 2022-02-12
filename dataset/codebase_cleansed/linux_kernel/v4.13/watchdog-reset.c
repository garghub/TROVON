void samsung_wdt_reset(void)
{
if (!wdt_base) {
pr_err("%s: wdt reset not initialized\n", __func__);
mdelay(50);
return;
}
if (!IS_ERR(wdt_clock))
clk_prepare_enable(wdt_clock);
__raw_writel(0, wdt_base + S3C2410_WTCON);
__raw_writel(0x80, wdt_base + S3C2410_WTCNT);
__raw_writel(0x80, wdt_base + S3C2410_WTDAT);
__raw_writel(S3C2410_WTCON_ENABLE | S3C2410_WTCON_DIV16 |
S3C2410_WTCON_RSTEN | S3C2410_WTCON_PRESCALE(0x20),
wdt_base + S3C2410_WTCON);
mdelay(500);
pr_err("Watchdog reset failed to assert reset\n");
mdelay(50);
}
void __init samsung_wdt_reset_of_init(void)
{
struct device_node *np;
np = of_find_matching_node(NULL, s3c2410_wdt_match);
if (!np) {
pr_err("%s: failed to find watchdog node\n", __func__);
return;
}
wdt_base = of_iomap(np, 0);
if (!wdt_base) {
pr_err("%s: failed to map watchdog registers\n", __func__);
return;
}
wdt_clock = of_clk_get(np, 0);
}
void __init samsung_wdt_reset_init(void __iomem *base)
{
wdt_base = base;
wdt_clock = clk_get(NULL, "watchdog");
}
