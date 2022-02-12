static u64 notrace omap_32k_read_sched_clock(void)
{
return sync32k_cnt_reg ? readl_relaxed(sync32k_cnt_reg) : 0;
}
static void omap_read_persistent_clock(struct timespec *ts)
{
unsigned long long nsecs;
cycles_t last_cycles;
unsigned long flags;
spin_lock_irqsave(&read_persistent_clock_lock, flags);
last_cycles = cycles;
cycles = sync32k_cnt_reg ? readl_relaxed(sync32k_cnt_reg) : 0;
nsecs = clocksource_cyc2ns(cycles - last_cycles,
persistent_mult, persistent_shift);
timespec_add_ns(&persistent_ts, nsecs);
*ts = persistent_ts;
spin_unlock_irqrestore(&read_persistent_clock_lock, flags);
}
int __init omap_init_clocksource_32k(void __iomem *vbase)
{
int ret;
if (readl_relaxed(vbase + OMAP2_32KSYNCNT_REV_OFF) &
OMAP2_32KSYNCNT_REV_SCHEME)
sync32k_cnt_reg = vbase + OMAP2_32KSYNCNT_CR_OFF_HIGH;
else
sync32k_cnt_reg = vbase + OMAP2_32KSYNCNT_CR_OFF_LOW;
clocks_calc_mult_shift(&persistent_mult, &persistent_shift,
32768, NSEC_PER_SEC, 120000);
ret = clocksource_mmio_init(sync32k_cnt_reg, "32k_counter", 32768,
250, 32, clocksource_mmio_readl_up);
if (ret) {
pr_err("32k_counter: can't register clocksource\n");
return ret;
}
sched_clock_register(omap_32k_read_sched_clock, 32, 32768);
register_persistent_clock(NULL, omap_read_persistent_clock);
pr_info("OMAP clocksource: 32k_counter at 32768 Hz\n");
return 0;
}
