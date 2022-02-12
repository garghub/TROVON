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
cycle_t giccount = 0, gicstart = 0;
#if defined(CONFIG_KVM_GUEST) && CONFIG_KVM_GUEST_TIMER_FREQ
mips_hpt_frequency = CONFIG_KVM_GUEST_TIMER_FREQ * 1000000;
return;
#endif
local_irq_save(flags);
while (CMOS_READ(RTC_REG_A) & RTC_UIP);
while (!(CMOS_READ(RTC_REG_A) & RTC_UIP));
start = read_c0_count();
if (gic_present)
gicstart = gic_read_count();
while (CMOS_READ(RTC_REG_A) & RTC_UIP);
while (!(CMOS_READ(RTC_REG_A) & RTC_UIP));
count = read_c0_count();
if (gic_present)
giccount = gic_read_count();
local_irq_restore(flags);
count -= start;
mips_hpt_frequency = count;
if (gic_present) {
giccount -= gicstart;
gic_frequency = giccount;
}
}
void read_persistent_clock(struct timespec *ts)
{
ts->tv_sec = mc146818_get_cmos_time();
ts->tv_nsec = 0;
}
int get_c0_perfcount_int(void)
{
if (cpu_has_veic) {
set_vi_handler(MSC01E_INT_PERFCTR, mips_perf_dispatch);
mips_cpu_perf_irq = MSC01E_INT_BASE + MSC01E_INT_PERFCTR;
} else if (gic_present) {
mips_cpu_perf_irq = gic_get_c0_perfcount_int();
} else if (cp0_perfcount_irq >= 0) {
mips_cpu_perf_irq = MIPS_CPU_IRQ_BASE + cp0_perfcount_irq;
} else {
mips_cpu_perf_irq = -1;
}
return mips_cpu_perf_irq;
}
unsigned int get_c0_compare_int(void)
{
if (cpu_has_veic) {
set_vi_handler(MSC01E_INT_CPUCTR, mips_timer_dispatch);
mips_cpu_timer_irq = MSC01E_INT_BASE + MSC01E_INT_CPUCTR;
} else if (gic_present) {
mips_cpu_timer_irq = gic_get_c0_compare_int();
} else {
mips_cpu_timer_irq = MIPS_CPU_IRQ_BASE + cp0_compare_irq;
}
return mips_cpu_timer_irq;
}
static void __init init_rtc(void)
{
CMOS_WRITE(RTC_SET | RTC_24H, RTC_CONTROL);
CMOS_WRITE(RTC_REF_CLCK_32KHZ, RTC_FREQ_SELECT);
CMOS_WRITE(RTC_24H, RTC_CONTROL);
}
void __init plat_time_init(void)
{
unsigned int prid = read_c0_prid() & (PRID_COMP_MASK | PRID_IMP_MASK);
unsigned int freq;
init_rtc();
estimate_frequencies();
freq = mips_hpt_frequency;
if ((prid != (PRID_COMP_MIPS | PRID_IMP_20KC)) &&
(prid != (PRID_COMP_MIPS | PRID_IMP_25KF)))
freq *= 2;
freq = freqround(freq, 5000);
printk("CPU frequency %d.%02d MHz\n", freq/1000000,
(freq%1000000)*100/1000000);
mips_scroll_message();
#ifdef CONFIG_I8253
setup_pit_timer();
#endif
#ifdef CONFIG_MIPS_GIC
if (gic_present) {
freq = freqround(gic_frequency, 5000);
printk("GIC frequency %d.%02d MHz\n", freq/1000000,
(freq%1000000)*100/1000000);
#ifdef CONFIG_CLKSRC_MIPS_GIC
gic_clocksource_init(gic_frequency);
#endif
}
#endif
}
