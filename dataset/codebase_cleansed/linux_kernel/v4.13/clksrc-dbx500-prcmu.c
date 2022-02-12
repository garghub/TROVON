static u64 notrace clksrc_dbx500_prcmu_read(struct clocksource *cs)
{
void __iomem *base = clksrc_dbx500_timer_base;
u32 count, count2;
do {
count = readl_relaxed(base + PRCMU_TIMER_DOWNCOUNT);
count2 = readl_relaxed(base + PRCMU_TIMER_DOWNCOUNT);
} while (count2 != count);
return ~count;
}
static u64 notrace dbx500_prcmu_sched_clock_read(void)
{
if (unlikely(!clksrc_dbx500_timer_base))
return 0;
return clksrc_dbx500_prcmu_read(&clocksource_dbx500_prcmu);
}
static int __init clksrc_dbx500_prcmu_init(struct device_node *node)
{
clksrc_dbx500_timer_base = of_iomap(node, 0);
if (readl(clksrc_dbx500_timer_base + PRCMU_TIMER_MODE) !=
TIMER_MODE_CONTINOUS) {
writel(TIMER_MODE_CONTINOUS,
clksrc_dbx500_timer_base + PRCMU_TIMER_MODE);
writel(TIMER_DOWNCOUNT_VAL,
clksrc_dbx500_timer_base + PRCMU_TIMER_REF);
}
#ifdef CONFIG_CLKSRC_DBX500_PRCMU_SCHED_CLOCK
sched_clock_register(dbx500_prcmu_sched_clock_read, 32, RATE_32K);
#endif
return clocksource_register_hz(&clocksource_dbx500_prcmu, RATE_32K);
}
