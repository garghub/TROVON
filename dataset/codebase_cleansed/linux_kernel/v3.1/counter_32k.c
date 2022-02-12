static inline unsigned long long notrace _omap_32k_sched_clock(void)
{
u32 cyc = timer_32k_base ? __raw_readl(timer_32k_base) : 0;
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
u32 cyc = timer_32k_base ? __raw_readl(timer_32k_base) : 0;
update_sched_clock(&cd, cyc, (u32)~0);
}
void read_persistent_clock(struct timespec *ts)
{
unsigned long long nsecs;
cycles_t delta;
struct timespec *tsp = &persistent_ts;
last_cycles = cycles;
cycles = timer_32k_base ? __raw_readl(timer_32k_base) : 0;
delta = cycles - last_cycles;
nsecs = clocksource_cyc2ns(delta, persistent_mult, persistent_shift);
timespec_add_ns(tsp, nsecs);
*ts = *tsp;
}
int __init omap_init_clocksource_32k(void)
{
static char err[] __initdata = KERN_ERR
"%s: can't register clocksource!\n";
if (cpu_is_omap16xx() || cpu_class_is_omap2()) {
u32 pbase;
unsigned long size = SZ_4K;
void __iomem *base;
struct clk *sync_32k_ick;
if (cpu_is_omap16xx()) {
pbase = OMAP16XX_TIMER_32K_SYNCHRONIZED;
size = SZ_1K;
} else if (cpu_is_omap2420())
pbase = OMAP2420_32KSYNCT_BASE + 0x10;
else if (cpu_is_omap2430())
pbase = OMAP2430_32KSYNCT_BASE + 0x10;
else if (cpu_is_omap34xx())
pbase = OMAP3430_32KSYNCT_BASE + 0x10;
else if (cpu_is_omap44xx())
pbase = OMAP4430_32KSYNCT_BASE + 0x10;
else
return -ENODEV;
base = ioremap(pbase, size);
if (!base)
return -ENODEV;
sync_32k_ick = clk_get(NULL, "omap_32ksync_ick");
if (!IS_ERR(sync_32k_ick))
clk_enable(sync_32k_ick);
timer_32k_base = base;
clocks_calc_mult_shift(&persistent_mult, &persistent_shift,
32768, NSEC_PER_SEC, 120000);
if (clocksource_mmio_init(base, "32k_counter", 32768, 250, 32,
clocksource_mmio_readl_up))
printk(err, "32k_counter");
init_fixed_sched_clock(&cd, omap_update_sched_clock, 32,
32768, SC_MULT, SC_SHIFT);
}
return 0;
}
