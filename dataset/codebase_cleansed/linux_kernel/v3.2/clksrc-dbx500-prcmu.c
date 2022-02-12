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
unsigned long long notrace sched_clock(void)
{
u32 cyc;
if (unlikely(!clksrc_dbx500_timer_base))
return 0;
cyc = clksrc_dbx500_prcmu_read(&clocksource_dbx500_prcmu);
return cyc_to_sched_clock(&cd, cyc, (u32)~0);
}
static void notrace clksrc_dbx500_prcmu_update_sched_clock(void)
{
u32 cyc = clksrc_dbx500_prcmu_read(&clocksource_dbx500_prcmu);
update_sched_clock(&cd, cyc, (u32)~0);
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
init_sched_clock(&cd, clksrc_dbx500_prcmu_update_sched_clock,
32, RATE_32K);
#endif
clocksource_calc_mult_shift(&clocksource_dbx500_prcmu,
RATE_32K, SCHED_CLOCK_MIN_WRAP);
clocksource_register(&clocksource_dbx500_prcmu);
}
