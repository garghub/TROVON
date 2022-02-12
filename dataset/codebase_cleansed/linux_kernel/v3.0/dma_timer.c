static cycle_t cf_dt_get_cycles(struct clocksource *cs)
{
return __raw_readl(DTCN0);
}
static int __init init_cf_dt_clocksource(void)
{
__raw_writeb(0x00, DTXMR0);
__raw_writeb(0x00, DTER0);
__raw_writel(0x00000000, DTRR0);
__raw_writew(DMA_DTMR_CLK_DIV_16 | DMA_DTMR_ENABLE, DTMR0);
clocksource_cf_dt.mult = clocksource_hz2mult(DMA_FREQ,
clocksource_cf_dt.shift);
return clocksource_register(&clocksource_cf_dt);
}
static unsigned long long cycles2ns(unsigned long cycl)
{
return (unsigned long long) ((unsigned long long)cycl *
CYC2NS_SCALE) >> CYC2NS_SCALE_FACTOR;
}
unsigned long long sched_clock(void)
{
unsigned long cycl = __raw_readl(DTCN0);
return cycles2ns(cycl);
}
