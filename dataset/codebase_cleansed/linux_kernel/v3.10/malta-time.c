static void mips_timer_dispatch(void)
{
do_IRQ(mips_cpu_timer_irq);
}
static void mips_perf_dispatch(void)
{
do_IRQ(mips_cpu_perf_irq);
}
static unsigned int freqround(unsigned int freq, unsigned int amount)
{
freq += amount;
freq -= freq % (amount*2);
return freq;
}
static void __init estimate_frequencies(void)
{
unsigned long flags;
unsigned int count, start;
#ifdef CONFIG_IRQ_GIC
unsigned int giccount = 0, gicstart = 0;
#endif
#if defined (CONFIG_KVM_GUEST) && defined (CONFIG_KVM_HOST_FREQ)
unsigned int prid = read_c0_prid() & 0xffff00;
count = (CONFIG_KVM_HOST_FREQ * 1000000) >> 3;
if ((prid != (PRID_COMP_MIPS | PRID_IMP_20KC)) &&
(prid != (PRID_COMP_MIPS | PRID_IMP_25KF)))
count *= 2;
mips_hpt_frequency = count;
return;
#endif
local_irq_save(flags);
while (CMOS_READ(RTC_REG_A) & RTC_UIP);
while (!(CMOS_READ(RTC_REG_A) & RTC_UIP));
start = read_c0_count();
#ifdef CONFIG_IRQ_GIC
if (gic_present)
GICREAD(GIC_REG(SHARED, GIC_SH_COUNTER_31_00), gicstart);
#endif
while (CMOS_READ(RTC_REG_A) & RTC_UIP);
while (!(CMOS_READ(RTC_REG_A) & RTC_UIP));
count = read_c0_count();
#ifdef CONFIG_IRQ_GIC
if (gic_present)
GICREAD(GIC_REG(SHARED, GIC_SH_COUNTER_31_00), giccount);
#endif
local_irq_restore(flags);
count -= start;
mips_hpt_frequency = count;
#ifdef CONFIG_IRQ_GIC
if (gic_present) {
giccount -= gicstart;
gic_frequency = giccount;
}
#endif
}
void read_persistent_clock(struct timespec *ts)
{
ts->tv_sec = mc146818_get_cmos_time();
ts->tv_nsec = 0;
}
static void __init plat_perf_setup(void)
{
#ifdef MSC01E_INT_BASE
if (cpu_has_veic) {
set_vi_handler(MSC01E_INT_PERFCTR, mips_perf_dispatch);
mips_cpu_perf_irq = MSC01E_INT_BASE + MSC01E_INT_PERFCTR;
} else
#endif
if (cp0_perfcount_irq >= 0) {
if (cpu_has_vint)
set_vi_handler(cp0_perfcount_irq, mips_perf_dispatch);
mips_cpu_perf_irq = MIPS_CPU_IRQ_BASE + cp0_perfcount_irq;
#ifdef CONFIG_SMP
irq_set_handler(mips_cpu_perf_irq, handle_percpu_irq);
#endif
}
}
unsigned int __cpuinit get_c0_compare_int(void)
{
#ifdef MSC01E_INT_BASE
if (cpu_has_veic) {
set_vi_handler(MSC01E_INT_CPUCTR, mips_timer_dispatch);
mips_cpu_timer_irq = MSC01E_INT_BASE + MSC01E_INT_CPUCTR;
} else
#endif
{
if (cpu_has_vint)
set_vi_handler(cp0_compare_irq, mips_timer_dispatch);
mips_cpu_timer_irq = MIPS_CPU_IRQ_BASE + cp0_compare_irq;
}
return mips_cpu_timer_irq;
}
void __init plat_time_init(void)
{
unsigned int prid = read_c0_prid() & 0xffff00;
unsigned int freq;
estimate_frequencies();
freq = mips_hpt_frequency;
if ((prid != (PRID_COMP_MIPS | PRID_IMP_20KC)) &&
(prid != (PRID_COMP_MIPS | PRID_IMP_25KF)))
freq *= 2;
freq = freqround(freq, 5000);
printk("CPU frequency %d.%02d MHz\n", freq/1000000,
(freq%1000000)*100/1000000);
cpu_khz = freq / 1000;
mips_scroll_message();
#ifdef CONFIG_I8253
setup_pit_timer();
#endif
#ifdef CONFIG_IRQ_GIC
if (gic_present) {
freq = freqround(gic_frequency, 5000);
printk("GIC frequency %d.%02d MHz\n", freq/1000000,
(freq%1000000)*100/1000000);
#ifdef CONFIG_CSRC_GIC
gic_clocksource_init(gic_frequency);
#endif
}
#endif
plat_perf_setup();
}
