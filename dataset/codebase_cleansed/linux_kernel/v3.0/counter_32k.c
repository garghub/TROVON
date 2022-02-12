static cycle_t notrace omap16xx_32k_read(struct clocksource *cs)
{
return omap_readl(OMAP16XX_TIMER_32K_SYNCHRONIZED) - offset_32k;
}
static cycle_t notrace omap2420_32k_read(struct clocksource *cs)
{
return omap_readl(OMAP2420_32KSYNCT_BASE + 0x10) - offset_32k;
}
static cycle_t notrace omap2430_32k_read(struct clocksource *cs)
{
return omap_readl(OMAP2430_32KSYNCT_BASE + 0x10) - offset_32k;
}
static cycle_t notrace omap34xx_32k_read(struct clocksource *cs)
{
return omap_readl(OMAP3430_32KSYNCT_BASE + 0x10) - offset_32k;
}
static cycle_t notrace omap44xx_32k_read(struct clocksource *cs)
{
return omap_readl(OMAP4430_32KSYNCT_BASE + 0x10) - offset_32k;
}
static cycle_t notrace omap_32k_read_dummy(struct clocksource *cs)
{
return 0;
}
static inline unsigned long long notrace _omap_32k_sched_clock(void)
{
u32 cyc = clocksource_32k.read(&clocksource_32k);
return cyc_to_fixed_sched_clock(&cd, cyc, (u32)~0, SC_MULT, SC_SHIFT);
}
unsigned long long notrace sched_clock(void)
{
return _omap_32k_sched_clock();
}
unsigned long long notrace omap_32k_sched_clock(void)
{
return _omap_32k_sched_clock();
}
static void notrace omap_update_sched_clock(void)
{
u32 cyc = clocksource_32k.read(&clocksource_32k);
update_sched_clock(&cd, cyc, (u32)~0);
}
void read_persistent_clock(struct timespec *ts)
{
unsigned long long nsecs;
cycles_t delta;
struct timespec *tsp = &persistent_ts;
last_cycles = cycles;
cycles = clocksource_32k.read(&clocksource_32k);
delta = cycles - last_cycles;
nsecs = clocksource_cyc2ns(delta,
clocksource_32k.mult, clocksource_32k.shift);
timespec_add_ns(tsp, nsecs);
*ts = *tsp;
}
int __init omap_init_clocksource_32k(void)
{
static char err[] __initdata = KERN_ERR
"%s: can't register clocksource!\n";
if (cpu_is_omap16xx() || cpu_class_is_omap2()) {
struct clk *sync_32k_ick;
if (cpu_is_omap16xx())
clocksource_32k.read = omap16xx_32k_read;
else if (cpu_is_omap2420())
clocksource_32k.read = omap2420_32k_read;
else if (cpu_is_omap2430())
clocksource_32k.read = omap2430_32k_read;
else if (cpu_is_omap34xx())
clocksource_32k.read = omap34xx_32k_read;
else if (cpu_is_omap44xx())
clocksource_32k.read = omap44xx_32k_read;
else
return -ENODEV;
sync_32k_ick = clk_get(NULL, "omap_32ksync_ick");
if (!IS_ERR(sync_32k_ick))
clk_enable(sync_32k_ick);
offset_32k = clocksource_32k.read(&clocksource_32k);
if (clocksource_register_hz(&clocksource_32k, 32768))
printk(err, clocksource_32k.name);
init_fixed_sched_clock(&cd, omap_update_sched_clock, 32,
32768, SC_MULT, SC_SHIFT);
}
return 0;
}
