void cyc2ns_read_begin(struct cyc2ns_data *data)
{
int seq, idx;
preempt_disable_notrace();
do {
seq = this_cpu_read(cyc2ns.seq.sequence);
idx = seq & 1;
data->cyc2ns_offset = this_cpu_read(cyc2ns.data[idx].cyc2ns_offset);
data->cyc2ns_mul = this_cpu_read(cyc2ns.data[idx].cyc2ns_mul);
data->cyc2ns_shift = this_cpu_read(cyc2ns.data[idx].cyc2ns_shift);
} while (unlikely(seq != this_cpu_read(cyc2ns.seq.sequence)));
}
void cyc2ns_read_end(void)
{
preempt_enable_notrace();
}
static void cyc2ns_data_init(struct cyc2ns_data *data)
{
data->cyc2ns_mul = 0;
data->cyc2ns_shift = 0;
data->cyc2ns_offset = 0;
}
static void cyc2ns_init(int cpu)
{
struct cyc2ns *c2n = &per_cpu(cyc2ns, cpu);
cyc2ns_data_init(&c2n->data[0]);
cyc2ns_data_init(&c2n->data[1]);
seqcount_init(&c2n->seq);
}
static inline unsigned long long cycles_2_ns(unsigned long long cyc)
{
struct cyc2ns_data data;
unsigned long long ns;
cyc2ns_read_begin(&data);
ns = data.cyc2ns_offset;
ns += mul_u64_u32_shr(cyc, data.cyc2ns_mul, data.cyc2ns_shift);
cyc2ns_read_end();
return ns;
}
static void set_cyc2ns_scale(unsigned long khz, int cpu, unsigned long long tsc_now)
{
unsigned long long ns_now;
struct cyc2ns_data data;
struct cyc2ns *c2n;
unsigned long flags;
local_irq_save(flags);
sched_clock_idle_sleep_event();
if (!khz)
goto done;
ns_now = cycles_2_ns(tsc_now);
clocks_calc_mult_shift(&data.cyc2ns_mul, &data.cyc2ns_shift, khz,
NSEC_PER_MSEC, 0);
if (data.cyc2ns_shift == 32) {
data.cyc2ns_shift = 31;
data.cyc2ns_mul >>= 1;
}
data.cyc2ns_offset = ns_now -
mul_u64_u32_shr(tsc_now, data.cyc2ns_mul, data.cyc2ns_shift);
c2n = per_cpu_ptr(&cyc2ns, cpu);
raw_write_seqcount_latch(&c2n->seq);
c2n->data[0] = data;
raw_write_seqcount_latch(&c2n->seq);
c2n->data[1] = data;
done:
sched_clock_idle_wakeup_event();
local_irq_restore(flags);
}
u64 native_sched_clock(void)
{
if (static_branch_likely(&__use_tsc)) {
u64 tsc_now = rdtsc();
return cycles_2_ns(tsc_now);
}
return (jiffies_64 - INITIAL_JIFFIES) * (1000000000 / HZ);
}
u64 native_sched_clock_from_tsc(u64 tsc)
{
return cycles_2_ns(tsc);
}
unsigned long long sched_clock(void)
{
return paravirt_sched_clock();
}
bool using_native_sched_clock(void)
{
return pv_time_ops.sched_clock == native_sched_clock;
}
bool using_native_sched_clock(void) { return true; }
int check_tsc_unstable(void)
{
return tsc_unstable;
}
int __init notsc_setup(char *str)
{
pr_warn("Kernel compiled with CONFIG_X86_TSC, cannot disable TSC completely\n");
tsc_disabled = 1;
return 1;
}
int __init notsc_setup(char *str)
{
setup_clear_cpu_cap(X86_FEATURE_TSC);
return 1;
}
static int __init tsc_setup(char *str)
{
if (!strcmp(str, "reliable"))
tsc_clocksource_reliable = 1;
if (!strncmp(str, "noirqtime", 9))
no_sched_irq_time = 1;
if (!strcmp(str, "unstable"))
mark_tsc_unstable("boot parameter");
return 1;
}
static u64 tsc_read_refs(u64 *p, int hpet)
{
u64 t1, t2;
int i;
for (i = 0; i < MAX_RETRIES; i++) {
t1 = get_cycles();
if (hpet)
*p = hpet_readl(HPET_COUNTER) & 0xFFFFFFFF;
else
*p = acpi_pm_read_early();
t2 = get_cycles();
if ((t2 - t1) < SMI_TRESHOLD)
return t2;
}
return ULLONG_MAX;
}
static unsigned long calc_hpet_ref(u64 deltatsc, u64 hpet1, u64 hpet2)
{
u64 tmp;
if (hpet2 < hpet1)
hpet2 += 0x100000000ULL;
hpet2 -= hpet1;
tmp = ((u64)hpet2 * hpet_readl(HPET_PERIOD));
do_div(tmp, 1000000);
do_div(deltatsc, tmp);
return (unsigned long) deltatsc;
}
static unsigned long calc_pmtimer_ref(u64 deltatsc, u64 pm1, u64 pm2)
{
u64 tmp;
if (!pm1 && !pm2)
return ULONG_MAX;
if (pm2 < pm1)
pm2 += (u64)ACPI_PM_OVRRUN;
pm2 -= pm1;
tmp = pm2 * 1000000000LL;
do_div(tmp, PMTMR_TICKS_PER_SEC);
do_div(deltatsc, tmp);
return (unsigned long) deltatsc;
}
static unsigned long pit_calibrate_tsc(u32 latch, unsigned long ms, int loopmin)
{
u64 tsc, t1, t2, delta;
unsigned long tscmin, tscmax;
int pitcnt;
outb((inb(0x61) & ~0x02) | 0x01, 0x61);
outb(0xb0, 0x43);
outb(latch & 0xff, 0x42);
outb(latch >> 8, 0x42);
tsc = t1 = t2 = get_cycles();
pitcnt = 0;
tscmax = 0;
tscmin = ULONG_MAX;
while ((inb(0x61) & 0x20) == 0) {
t2 = get_cycles();
delta = t2 - tsc;
tsc = t2;
if ((unsigned long) delta < tscmin)
tscmin = (unsigned int) delta;
if ((unsigned long) delta > tscmax)
tscmax = (unsigned int) delta;
pitcnt++;
}
if (pitcnt < loopmin || tscmax > 10 * tscmin)
return ULONG_MAX;
delta = t2 - t1;
do_div(delta, ms);
return delta;
}
static inline int pit_verify_msb(unsigned char val)
{
inb(0x42);
return inb(0x42) == val;
}
static inline int pit_expect_msb(unsigned char val, u64 *tscp, unsigned long *deltap)
{
int count;
u64 tsc = 0, prev_tsc = 0;
for (count = 0; count < 50000; count++) {
if (!pit_verify_msb(val))
break;
prev_tsc = tsc;
tsc = get_cycles();
}
*deltap = get_cycles() - prev_tsc;
*tscp = tsc;
return count > 5;
}
static unsigned long quick_pit_calibrate(void)
{
int i;
u64 tsc, delta;
unsigned long d1, d2;
outb((inb(0x61) & ~0x02) | 0x01, 0x61);
outb(0xb0, 0x43);
outb(0xff, 0x42);
outb(0xff, 0x42);
pit_verify_msb(0);
if (pit_expect_msb(0xff, &tsc, &d1)) {
for (i = 1; i <= MAX_QUICK_PIT_ITERATIONS; i++) {
if (!pit_expect_msb(0xff-i, &delta, &d2))
break;
delta -= tsc;
if (i == 1 &&
d1 + d2 >= (delta * MAX_QUICK_PIT_ITERATIONS) >> 11)
return 0;
if (d1+d2 >= delta >> 11)
continue;
if (!pit_verify_msb(0xfe - i))
break;
goto success;
}
}
pr_info("Fast TSC calibration failed\n");
return 0;
success:
delta *= PIT_TICK_RATE;
do_div(delta, i*256*1000);
pr_info("Fast TSC calibration using PIT\n");
return delta;
}
unsigned long native_calibrate_tsc(void)
{
unsigned int eax_denominator, ebx_numerator, ecx_hz, edx;
unsigned int crystal_khz;
if (boot_cpu_data.x86_vendor != X86_VENDOR_INTEL)
return 0;
if (boot_cpu_data.cpuid_level < 0x15)
return 0;
eax_denominator = ebx_numerator = ecx_hz = edx = 0;
cpuid(0x15, &eax_denominator, &ebx_numerator, &ecx_hz, &edx);
if (ebx_numerator == 0 || eax_denominator == 0)
return 0;
crystal_khz = ecx_hz / 1000;
if (crystal_khz == 0) {
switch (boot_cpu_data.x86_model) {
case INTEL_FAM6_SKYLAKE_MOBILE:
case INTEL_FAM6_SKYLAKE_DESKTOP:
case INTEL_FAM6_KABYLAKE_MOBILE:
case INTEL_FAM6_KABYLAKE_DESKTOP:
crystal_khz = 24000;
break;
case INTEL_FAM6_SKYLAKE_X:
case INTEL_FAM6_ATOM_DENVERTON:
crystal_khz = 25000;
break;
case INTEL_FAM6_ATOM_GOLDMONT:
crystal_khz = 19200;
break;
}
}
setup_force_cpu_cap(X86_FEATURE_TSC_KNOWN_FREQ);
if (boot_cpu_data.x86_model == INTEL_FAM6_ATOM_GOLDMONT)
setup_force_cpu_cap(X86_FEATURE_TSC_RELIABLE);
return crystal_khz * ebx_numerator / eax_denominator;
}
static unsigned long cpu_khz_from_cpuid(void)
{
unsigned int eax_base_mhz, ebx_max_mhz, ecx_bus_mhz, edx;
if (boot_cpu_data.x86_vendor != X86_VENDOR_INTEL)
return 0;
if (boot_cpu_data.cpuid_level < 0x16)
return 0;
eax_base_mhz = ebx_max_mhz = ecx_bus_mhz = edx = 0;
cpuid(0x16, &eax_base_mhz, &ebx_max_mhz, &ecx_bus_mhz, &edx);
return eax_base_mhz * 1000;
}
unsigned long native_calibrate_cpu(void)
{
u64 tsc1, tsc2, delta, ref1, ref2;
unsigned long tsc_pit_min = ULONG_MAX, tsc_ref_min = ULONG_MAX;
unsigned long flags, latch, ms, fast_calibrate;
int hpet = is_hpet_enabled(), i, loopmin;
fast_calibrate = cpu_khz_from_cpuid();
if (fast_calibrate)
return fast_calibrate;
fast_calibrate = cpu_khz_from_msr();
if (fast_calibrate)
return fast_calibrate;
local_irq_save(flags);
fast_calibrate = quick_pit_calibrate();
local_irq_restore(flags);
if (fast_calibrate)
return fast_calibrate;
latch = CAL_LATCH;
ms = CAL_MS;
loopmin = CAL_PIT_LOOPS;
for (i = 0; i < 3; i++) {
unsigned long tsc_pit_khz;
local_irq_save(flags);
tsc1 = tsc_read_refs(&ref1, hpet);
tsc_pit_khz = pit_calibrate_tsc(latch, ms, loopmin);
tsc2 = tsc_read_refs(&ref2, hpet);
local_irq_restore(flags);
tsc_pit_min = min(tsc_pit_min, tsc_pit_khz);
if (ref1 == ref2)
continue;
if (tsc1 == ULLONG_MAX || tsc2 == ULLONG_MAX)
continue;
tsc2 = (tsc2 - tsc1) * 1000000LL;
if (hpet)
tsc2 = calc_hpet_ref(tsc2, ref1, ref2);
else
tsc2 = calc_pmtimer_ref(tsc2, ref1, ref2);
tsc_ref_min = min(tsc_ref_min, (unsigned long) tsc2);
delta = ((u64) tsc_pit_min) * 100;
do_div(delta, tsc_ref_min);
if (delta >= 90 && delta <= 110) {
pr_info("PIT calibration matches %s. %d loops\n",
hpet ? "HPET" : "PMTIMER", i + 1);
return tsc_ref_min;
}
if (i == 1 && tsc_pit_min == ULONG_MAX) {
latch = CAL2_LATCH;
ms = CAL2_MS;
loopmin = CAL2_PIT_LOOPS;
}
}
if (tsc_pit_min == ULONG_MAX) {
pr_warn("Unable to calibrate against PIT\n");
if (!hpet && !ref1 && !ref2) {
pr_notice("No reference (HPET/PMTIMER) available\n");
return 0;
}
if (tsc_ref_min == ULONG_MAX) {
pr_warn("HPET/PMTIMER calibration failed\n");
return 0;
}
pr_info("using %s reference calibration\n",
hpet ? "HPET" : "PMTIMER");
return tsc_ref_min;
}
if (!hpet && !ref1 && !ref2) {
pr_info("Using PIT calibration value\n");
return tsc_pit_min;
}
if (tsc_ref_min == ULONG_MAX) {
pr_warn("HPET/PMTIMER calibration failed. Using PIT calibration.\n");
return tsc_pit_min;
}
pr_warn("PIT calibration deviates from %s: %lu %lu\n",
hpet ? "HPET" : "PMTIMER", tsc_pit_min, tsc_ref_min);
pr_info("Using PIT calibration value\n");
return tsc_pit_min;
}
int recalibrate_cpu_khz(void)
{
#ifndef CONFIG_SMP
unsigned long cpu_khz_old = cpu_khz;
if (!boot_cpu_has(X86_FEATURE_TSC))
return -ENODEV;
cpu_khz = x86_platform.calibrate_cpu();
tsc_khz = x86_platform.calibrate_tsc();
if (tsc_khz == 0)
tsc_khz = cpu_khz;
else if (abs(cpu_khz - tsc_khz) * 10 > tsc_khz)
cpu_khz = tsc_khz;
cpu_data(0).loops_per_jiffy = cpufreq_scale(cpu_data(0).loops_per_jiffy,
cpu_khz_old, cpu_khz);
return 0;
#else
return -ENODEV;
#endif
}
void tsc_save_sched_clock_state(void)
{
if (!sched_clock_stable())
return;
cyc2ns_suspend = sched_clock();
}
void tsc_restore_sched_clock_state(void)
{
unsigned long long offset;
unsigned long flags;
int cpu;
if (!sched_clock_stable())
return;
local_irq_save(flags);
this_cpu_write(cyc2ns.data[0].cyc2ns_offset, 0);
this_cpu_write(cyc2ns.data[1].cyc2ns_offset, 0);
offset = cyc2ns_suspend - sched_clock();
for_each_possible_cpu(cpu) {
per_cpu(cyc2ns.data[0].cyc2ns_offset, cpu) = offset;
per_cpu(cyc2ns.data[1].cyc2ns_offset, cpu) = offset;
}
local_irq_restore(flags);
}
static int time_cpufreq_notifier(struct notifier_block *nb, unsigned long val,
void *data)
{
struct cpufreq_freqs *freq = data;
unsigned long *lpj;
lpj = &boot_cpu_data.loops_per_jiffy;
#ifdef CONFIG_SMP
if (!(freq->flags & CPUFREQ_CONST_LOOPS))
lpj = &cpu_data(freq->cpu).loops_per_jiffy;
#endif
if (!ref_freq) {
ref_freq = freq->old;
loops_per_jiffy_ref = *lpj;
tsc_khz_ref = tsc_khz;
}
if ((val == CPUFREQ_PRECHANGE && freq->old < freq->new) ||
(val == CPUFREQ_POSTCHANGE && freq->old > freq->new)) {
*lpj = cpufreq_scale(loops_per_jiffy_ref, ref_freq, freq->new);
tsc_khz = cpufreq_scale(tsc_khz_ref, ref_freq, freq->new);
if (!(freq->flags & CPUFREQ_CONST_LOOPS))
mark_tsc_unstable("cpufreq changes");
set_cyc2ns_scale(tsc_khz, freq->cpu, rdtsc());
}
return 0;
}
static int __init cpufreq_register_tsc_scaling(void)
{
if (!boot_cpu_has(X86_FEATURE_TSC))
return 0;
if (boot_cpu_has(X86_FEATURE_CONSTANT_TSC))
return 0;
cpufreq_register_notifier(&time_cpufreq_notifier_block,
CPUFREQ_TRANSITION_NOTIFIER);
return 0;
}
static void detect_art(void)
{
unsigned int unused[2];
if (boot_cpu_data.cpuid_level < ART_CPUID_LEAF)
return;
if (boot_cpu_has(X86_FEATURE_HYPERVISOR) ||
!boot_cpu_has(X86_FEATURE_NONSTOP_TSC) ||
!boot_cpu_has(X86_FEATURE_TSC_ADJUST))
return;
cpuid(ART_CPUID_LEAF, &art_to_tsc_denominator,
&art_to_tsc_numerator, unused, unused+1);
if (art_to_tsc_denominator < ART_MIN_DENOMINATOR)
return;
rdmsrl(MSR_IA32_TSC_ADJUST, art_to_tsc_offset);
setup_force_cpu_cap(X86_FEATURE_ART);
}
static void tsc_resume(struct clocksource *cs)
{
tsc_verify_tsc_adjust(true);
}
static u64 read_tsc(struct clocksource *cs)
{
return (u64)rdtsc_ordered();
}
static void tsc_cs_mark_unstable(struct clocksource *cs)
{
if (tsc_unstable)
return;
tsc_unstable = 1;
if (using_native_sched_clock())
clear_sched_clock_stable();
disable_sched_clock_irqtime();
pr_info("Marking TSC unstable due to clocksource watchdog\n");
}
static void tsc_cs_tick_stable(struct clocksource *cs)
{
if (tsc_unstable)
return;
if (using_native_sched_clock())
sched_clock_tick_stable();
}
void mark_tsc_unstable(char *reason)
{
if (tsc_unstable)
return;
tsc_unstable = 1;
if (using_native_sched_clock())
clear_sched_clock_stable();
disable_sched_clock_irqtime();
pr_info("Marking TSC unstable due to %s\n", reason);
if (clocksource_tsc.mult) {
clocksource_mark_unstable(&clocksource_tsc);
} else {
clocksource_tsc.flags |= CLOCK_SOURCE_UNSTABLE;
clocksource_tsc.rating = 0;
}
}
static void __init check_system_tsc_reliable(void)
{
#if defined(CONFIG_MGEODEGX1) || defined(CONFIG_MGEODE_LX) || defined(CONFIG_X86_GENERIC)
if (is_geode_lx()) {
#define RTSC_SUSP 0x100
unsigned long res_low, res_high;
rdmsr_safe(MSR_GEODE_BUSCONT_CONF0, &res_low, &res_high);
if (res_low & RTSC_SUSP)
tsc_clocksource_reliable = 1;
}
#endif
if (boot_cpu_has(X86_FEATURE_TSC_RELIABLE))
tsc_clocksource_reliable = 1;
}
int unsynchronized_tsc(void)
{
if (!boot_cpu_has(X86_FEATURE_TSC) || tsc_unstable)
return 1;
#ifdef CONFIG_SMP
if (apic_is_clustered_box())
return 1;
#endif
if (boot_cpu_has(X86_FEATURE_CONSTANT_TSC))
return 0;
if (tsc_clocksource_reliable)
return 0;
if (boot_cpu_data.x86_vendor != X86_VENDOR_INTEL) {
if (num_possible_cpus() > 1)
return 1;
}
return 0;
}
struct system_counterval_t convert_art_to_tsc(u64 art)
{
u64 tmp, res, rem;
rem = do_div(art, art_to_tsc_denominator);
res = art * art_to_tsc_numerator;
tmp = rem * art_to_tsc_numerator;
do_div(tmp, art_to_tsc_denominator);
res += tmp + art_to_tsc_offset;
return (struct system_counterval_t) {.cs = art_related_clocksource,
.cycles = res};
}
static void tsc_refine_calibration_work(struct work_struct *work)
{
static u64 tsc_start = -1, ref_start;
static int hpet;
u64 tsc_stop, ref_stop, delta;
unsigned long freq;
int cpu;
if (check_tsc_unstable())
goto out;
if (tsc_start == -1) {
hpet = is_hpet_enabled();
schedule_delayed_work(&tsc_irqwork, HZ);
tsc_start = tsc_read_refs(&ref_start, hpet);
return;
}
tsc_stop = tsc_read_refs(&ref_stop, hpet);
if (ref_start == ref_stop)
goto out;
if (tsc_start == ULLONG_MAX || tsc_stop == ULLONG_MAX)
goto out;
delta = tsc_stop - tsc_start;
delta *= 1000000LL;
if (hpet)
freq = calc_hpet_ref(delta, ref_start, ref_stop);
else
freq = calc_pmtimer_ref(delta, ref_start, ref_stop);
if (abs(tsc_khz - freq) > tsc_khz/100)
goto out;
tsc_khz = freq;
pr_info("Refined TSC clocksource calibration: %lu.%03lu MHz\n",
(unsigned long)tsc_khz / 1000,
(unsigned long)tsc_khz % 1000);
lapic_update_tsc_freq();
for_each_possible_cpu(cpu)
set_cyc2ns_scale(tsc_khz, cpu, tsc_stop);
out:
if (boot_cpu_has(X86_FEATURE_ART))
art_related_clocksource = &clocksource_tsc;
clocksource_register_khz(&clocksource_tsc, tsc_khz);
}
static int __init init_tsc_clocksource(void)
{
if (!boot_cpu_has(X86_FEATURE_TSC) || tsc_disabled > 0 || !tsc_khz)
return 0;
if (tsc_clocksource_reliable)
clocksource_tsc.flags &= ~CLOCK_SOURCE_MUST_VERIFY;
if (check_tsc_unstable()) {
clocksource_tsc.rating = 0;
clocksource_tsc.flags &= ~CLOCK_SOURCE_IS_CONTINUOUS;
}
if (boot_cpu_has(X86_FEATURE_NONSTOP_TSC_S3))
clocksource_tsc.flags |= CLOCK_SOURCE_SUSPEND_NONSTOP;
if (boot_cpu_has(X86_FEATURE_TSC_KNOWN_FREQ)) {
if (boot_cpu_has(X86_FEATURE_ART))
art_related_clocksource = &clocksource_tsc;
clocksource_register_khz(&clocksource_tsc, tsc_khz);
return 0;
}
schedule_delayed_work(&tsc_irqwork, 0);
return 0;
}
void __init tsc_init(void)
{
u64 lpj, cyc;
int cpu;
if (!boot_cpu_has(X86_FEATURE_TSC)) {
setup_clear_cpu_cap(X86_FEATURE_TSC_DEADLINE_TIMER);
return;
}
cpu_khz = x86_platform.calibrate_cpu();
tsc_khz = x86_platform.calibrate_tsc();
if (tsc_khz == 0)
tsc_khz = cpu_khz;
else if (abs(cpu_khz - tsc_khz) * 10 > tsc_khz)
cpu_khz = tsc_khz;
if (!tsc_khz) {
mark_tsc_unstable("could not calculate TSC khz");
setup_clear_cpu_cap(X86_FEATURE_TSC_DEADLINE_TIMER);
return;
}
pr_info("Detected %lu.%03lu MHz processor\n",
(unsigned long)cpu_khz / 1000,
(unsigned long)cpu_khz % 1000);
tsc_store_and_check_tsc_adjust(true);
cyc = rdtsc();
for_each_possible_cpu(cpu) {
cyc2ns_init(cpu);
set_cyc2ns_scale(tsc_khz, cpu, cyc);
}
if (tsc_disabled > 0)
return;
tsc_disabled = 0;
static_branch_enable(&__use_tsc);
if (!no_sched_irq_time)
enable_sched_clock_irqtime();
lpj = ((u64)tsc_khz * 1000);
do_div(lpj, HZ);
lpj_fine = lpj;
use_tsc_delay();
check_system_tsc_reliable();
if (unsynchronized_tsc())
mark_tsc_unstable("TSCs unsynchronized");
detect_art();
}
unsigned long calibrate_delay_is_known(void)
{
int sibling, cpu = smp_processor_id();
int constant_tsc = cpu_has(&cpu_data(cpu), X86_FEATURE_CONSTANT_TSC);
const struct cpumask *mask = topology_core_cpumask(cpu);
if (tsc_disabled || !constant_tsc || !mask)
return 0;
sibling = cpumask_any_but(mask, cpu);
if (sibling < nr_cpu_ids)
return cpu_data(sibling).loops_per_jiffy;
return 0;
}
