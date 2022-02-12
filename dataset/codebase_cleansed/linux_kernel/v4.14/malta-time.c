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
unsigned char secs1, secs2, ctrl;
int secs;
u64 giccount = 0, gicstart = 0;
#if defined(CONFIG_KVM_GUEST) && CONFIG_KVM_GUEST_TIMER_FREQ
mips_hpt_frequency = CONFIG_KVM_GUEST_TIMER_FREQ * 1000000;
return;
#endif
local_irq_save(flags);
if (mips_gic_present())
clear_gic_config(GIC_CONFIG_COUNTSTOP);
while (CMOS_READ(RTC_REG_A) & RTC_UIP);
while (!(CMOS_READ(RTC_REG_A) & RTC_UIP));
start = read_c0_count();
if (mips_gic_present())
gicstart = read_gic_counter();
while (CMOS_READ(RTC_REG_A) & RTC_UIP);
secs1 = CMOS_READ(RTC_SECONDS);
while (!(CMOS_READ(RTC_REG_A) & RTC_UIP));
count = read_c0_count();
if (mips_gic_present())
giccount = read_gic_counter();
while (CMOS_READ(RTC_REG_A) & RTC_UIP);
secs2 = CMOS_READ(RTC_SECONDS);
ctrl = CMOS_READ(RTC_CONTROL);
local_irq_restore(flags);
if (!(ctrl & RTC_DM_BINARY) || RTC_ALWAYS_BCD) {
secs1 = bcd2bin(secs1);
secs2 = bcd2bin(secs2);
}
secs = secs2 - secs1;
if (secs < 1)
secs += 60;
count -= start;
count /= secs;
mips_hpt_frequency = count;
if (mips_gic_present()) {
giccount = div_u64(giccount - gicstart, secs);
gic_frequency = giccount;
}
}
void read_persistent_clock(struct timespec *ts)
{
ts->tv_sec = mc146818_get_cmos_time();
ts->tv_nsec = 0;
}
int get_c0_fdc_int(void)
{
switch (current_cpu_type()) {
case CPU_INTERAPTIV:
case CPU_PROAPTIV:
return -1;
};
if (cpu_has_veic)
return -1;
else if (mips_gic_present())
return gic_get_c0_fdc_int();
else if (cp0_fdc_irq >= 0)
return MIPS_CPU_IRQ_BASE + cp0_fdc_irq;
else
return -1;
}
int get_c0_perfcount_int(void)
{
if (cpu_has_veic) {
set_vi_handler(MSC01E_INT_PERFCTR, mips_perf_dispatch);
mips_cpu_perf_irq = MSC01E_INT_BASE + MSC01E_INT_PERFCTR;
} else if (mips_gic_present()) {
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
} else if (mips_gic_present()) {
mips_cpu_timer_irq = gic_get_c0_compare_int();
} else {
mips_cpu_timer_irq = MIPS_CPU_IRQ_BASE + cp0_compare_irq;
}
return mips_cpu_timer_irq;
}
static void __init init_rtc(void)
{
unsigned char freq, ctrl;
freq = CMOS_READ(RTC_FREQ_SELECT);
if ((freq & RTC_DIV_CTL) != RTC_REF_CLCK_32KHZ)
CMOS_WRITE(RTC_REF_CLCK_32KHZ, RTC_FREQ_SELECT);
ctrl = CMOS_READ(RTC_CONTROL);
if (ctrl & RTC_SET)
CMOS_WRITE(ctrl & ~RTC_SET, RTC_CONTROL);
}
static void update_gic_frequency_dt(void)
{
struct device_node *node;
gic_frequency_dt = cpu_to_be32(gic_frequency);
node = of_find_compatible_node(NULL, NULL, "mti,gic-timer");
if (!node) {
pr_err("mti,gic-timer device node not found\n");
return;
}
if (of_update_property(node, &gic_frequency_prop) < 0)
pr_err("error updating gic frequency property\n");
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
if (mips_gic_present()) {
freq = freqround(gic_frequency, 5000);
printk("GIC frequency %d.%02d MHz\n", freq/1000000,
(freq%1000000)*100/1000000);
#ifdef CONFIG_CLKSRC_MIPS_GIC
update_gic_frequency_dt();
timer_probe();
#endif
}
}
