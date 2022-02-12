static inline struct ti_32k *to_ti_32k(struct clocksource *cs)
{
return container_of(cs, struct ti_32k, cs);
}
static cycle_t notrace ti_32k_read_cycles(struct clocksource *cs)
{
struct ti_32k *ti = to_ti_32k(cs);
return (cycle_t)readl_relaxed(ti->counter);
}
static u64 notrace omap_32k_read_sched_clock(void)
{
return ti_32k_read_cycles(&ti_32k_timer.cs);
}
static int __init ti_32k_timer_init(struct device_node *np)
{
int ret;
ti_32k_timer.base = of_iomap(np, 0);
if (!ti_32k_timer.base) {
pr_err("Can't ioremap 32k timer base\n");
return -ENXIO;
}
ti_32k_timer.counter = ti_32k_timer.base;
if (readl_relaxed(ti_32k_timer.base + OMAP2_32KSYNCNT_REV_OFF) &
OMAP2_32KSYNCNT_REV_SCHEME)
ti_32k_timer.counter += OMAP2_32KSYNCNT_CR_OFF_HIGH;
else
ti_32k_timer.counter += OMAP2_32KSYNCNT_CR_OFF_LOW;
ret = clocksource_register_hz(&ti_32k_timer.cs, 32768);
if (ret) {
pr_err("32k_counter: can't register clocksource\n");
return ret;
}
sched_clock_register(omap_32k_read_sched_clock, 32, 32768);
pr_info("OMAP clocksource: 32k_counter at 32768 Hz\n");
return 0;
}
