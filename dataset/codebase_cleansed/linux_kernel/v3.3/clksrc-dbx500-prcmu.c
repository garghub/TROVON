static cycle_t clksrc_dbx500_prcmu_read(struct clocksource *cs)
{
u32 count, count2;
do {
count = readl(clksrc_dbx500_timer_base +
PRCMU_TIMER_DOWNCOUNT);
count2 = readl(clksrc_dbx500_timer_base +
PRCMU_TIMER_DOWNCOUNT);
} while (count2 != count);
return ~count;
}
static u32 notrace dbx500_prcmu_sched_clock_read(void)
{
if (unlikely(!clksrc_dbx500_timer_base))
return 0;
return clksrc_dbx500_prcmu_read(&clocksource_dbx500_prcmu);
}
void __init clksrc_dbx500_prcmu_init(void __iomem *base)
{
clksrc_dbx500_timer_base = base;
if (readl(clksrc_dbx500_timer_base + PRCMU_TIMER_MODE) !=
TIMER_MODE_CONTINOUS) {
writel(TIMER_MODE_CONTINOUS,
clksrc_dbx500_timer_base + PRCMU_TIMER_MODE);
writel(TIMER_DOWNCOUNT_VAL,
clksrc_dbx500_timer_base + PRCMU_TIMER_REF);
}
#ifdef CONFIG_CLKSRC_DBX500_PRCMU_SCHED_CLOCK
setup_sched_clock(dbx500_prcmu_sched_clock_read,
32, RATE_32K);
#endif
clocksource_calc_mult_shift(&clocksource_dbx500_prcmu,
RATE_32K, SCHED_CLOCK_MIN_WRAP);
clocksource_register(&clocksource_dbx500_prcmu);
}
