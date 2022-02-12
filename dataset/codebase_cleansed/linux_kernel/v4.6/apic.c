static inline void imcr_pic_to_apic(void)
{
outb(0x70, 0x22);
outb(0x01, 0x23);
}
static inline void imcr_apic_to_pic(void)
{
outb(0x70, 0x22);
outb(0x00, 0x23);
}
static int __init parse_lapic(char *arg)
{
if (config_enabled(CONFIG_X86_32) && !arg)
force_enable_local_apic = 1;
else if (arg && !strncmp(arg, "notscdeadline", 13))
setup_clear_cpu_cap(X86_FEATURE_TSC_DEADLINE_TIMER);
return 0;
}
static __init int setup_apicpmtimer(char *s)
{
apic_calibrate_pmtmr = 1;
notsc_setup(NULL);
return 0;
}
static inline int lapic_get_version(void)
{
return GET_APIC_VERSION(apic_read(APIC_LVR));
}
static inline int lapic_is_integrated(void)
{
#ifdef CONFIG_X86_64
return 1;
#else
return APIC_INTEGRATED(lapic_get_version());
#endif
}
static int modern_apic(void)
{
if (boot_cpu_data.x86_vendor == X86_VENDOR_AMD &&
boot_cpu_data.x86 >= 0xf)
return 1;
return lapic_get_version() >= 0x14;
}
static void __init apic_disable(void)
{
pr_info("APIC: switched to apic NOOP\n");
apic = &apic_noop;
}
void native_apic_wait_icr_idle(void)
{
while (apic_read(APIC_ICR) & APIC_ICR_BUSY)
cpu_relax();
}
u32 native_safe_apic_wait_icr_idle(void)
{
u32 send_status;
int timeout;
timeout = 0;
do {
send_status = apic_read(APIC_ICR) & APIC_ICR_BUSY;
if (!send_status)
break;
inc_irq_stat(icr_read_retry_count);
udelay(100);
} while (timeout++ < 1000);
return send_status;
}
void native_apic_icr_write(u32 low, u32 id)
{
unsigned long flags;
local_irq_save(flags);
apic_write(APIC_ICR2, SET_APIC_DEST_FIELD(id));
apic_write(APIC_ICR, low);
local_irq_restore(flags);
}
u64 native_apic_icr_read(void)
{
u32 icr1, icr2;
icr2 = apic_read(APIC_ICR2);
icr1 = apic_read(APIC_ICR);
return icr1 | ((u64)icr2 << 32);
}
int get_physical_broadcast(void)
{
return modern_apic() ? 0xff : 0xf;
}
int lapic_get_maxlvt(void)
{
unsigned int v;
v = apic_read(APIC_LVR);
return APIC_INTEGRATED(GET_APIC_VERSION(v)) ? GET_APIC_MAXLVT(v) : 2;
}
static void __setup_APIC_LVTT(unsigned int clocks, int oneshot, int irqen)
{
unsigned int lvtt_value, tmp_value;
lvtt_value = LOCAL_TIMER_VECTOR;
if (!oneshot)
lvtt_value |= APIC_LVT_TIMER_PERIODIC;
else if (boot_cpu_has(X86_FEATURE_TSC_DEADLINE_TIMER))
lvtt_value |= APIC_LVT_TIMER_TSCDEADLINE;
if (!lapic_is_integrated())
lvtt_value |= SET_APIC_TIMER_BASE(APIC_TIMER_BASE_DIV);
if (!irqen)
lvtt_value |= APIC_LVT_MASKED;
apic_write(APIC_LVTT, lvtt_value);
if (lvtt_value & APIC_LVT_TIMER_TSCDEADLINE) {
asm volatile("mfence" : : : "memory");
printk_once(KERN_DEBUG "TSC deadline timer enabled\n");
return;
}
tmp_value = apic_read(APIC_TDCR);
apic_write(APIC_TDCR,
(tmp_value & ~(APIC_TDR_DIV_1 | APIC_TDR_DIV_TMBASE)) |
APIC_TDR_DIV_16);
if (!oneshot)
apic_write(APIC_TMICT, clocks / APIC_DIVISOR);
}
static inline int eilvt_entry_is_changeable(unsigned int old, unsigned int new)
{
return (old & APIC_EILVT_MASKED)
|| (new == APIC_EILVT_MASKED)
|| ((new & ~APIC_EILVT_MASKED) == old);
}
static unsigned int reserve_eilvt_offset(int offset, unsigned int new)
{
unsigned int rsvd, vector;
if (offset >= APIC_EILVT_NR_MAX)
return ~0;
rsvd = atomic_read(&eilvt_offsets[offset]);
do {
vector = rsvd & ~APIC_EILVT_MASKED;
if (vector && !eilvt_entry_is_changeable(vector, new))
return rsvd;
rsvd = atomic_cmpxchg(&eilvt_offsets[offset], rsvd, new);
} while (rsvd != new);
rsvd &= ~APIC_EILVT_MASKED;
if (rsvd && rsvd != vector)
pr_info("LVT offset %d assigned for vector 0x%02x\n",
offset, rsvd);
return new;
}
int setup_APIC_eilvt(u8 offset, u8 vector, u8 msg_type, u8 mask)
{
unsigned long reg = APIC_EILVTn(offset);
unsigned int new, old, reserved;
new = (mask << 16) | (msg_type << 8) | vector;
old = apic_read(reg);
reserved = reserve_eilvt_offset(offset, new);
if (reserved != new) {
pr_err(FW_BUG "cpu %d, try to use APIC%lX (LVT offset %d) for "
"vector 0x%x, but the register is already in use for "
"vector 0x%x on another cpu\n",
smp_processor_id(), reg, offset, new, reserved);
return -EINVAL;
}
if (!eilvt_entry_is_changeable(old, new)) {
pr_err(FW_BUG "cpu %d, try to use APIC%lX (LVT offset %d) for "
"vector 0x%x, but the register is already in use for "
"vector 0x%x on this cpu\n",
smp_processor_id(), reg, offset, new, old);
return -EBUSY;
}
apic_write(reg, new);
return 0;
}
static int lapic_next_event(unsigned long delta,
struct clock_event_device *evt)
{
apic_write(APIC_TMICT, delta);
return 0;
}
static int lapic_next_deadline(unsigned long delta,
struct clock_event_device *evt)
{
u64 tsc;
tsc = rdtsc();
wrmsrl(MSR_IA32_TSC_DEADLINE, tsc + (((u64) delta) * TSC_DIVISOR));
return 0;
}
static int lapic_timer_shutdown(struct clock_event_device *evt)
{
unsigned int v;
if (evt->features & CLOCK_EVT_FEAT_DUMMY)
return 0;
v = apic_read(APIC_LVTT);
v |= (APIC_LVT_MASKED | LOCAL_TIMER_VECTOR);
apic_write(APIC_LVTT, v);
apic_write(APIC_TMICT, 0);
return 0;
}
static inline int
lapic_timer_set_periodic_oneshot(struct clock_event_device *evt, bool oneshot)
{
if (evt->features & CLOCK_EVT_FEAT_DUMMY)
return 0;
__setup_APIC_LVTT(lapic_timer_frequency, oneshot, 1);
return 0;
}
static int lapic_timer_set_periodic(struct clock_event_device *evt)
{
return lapic_timer_set_periodic_oneshot(evt, false);
}
static int lapic_timer_set_oneshot(struct clock_event_device *evt)
{
return lapic_timer_set_periodic_oneshot(evt, true);
}
static void lapic_timer_broadcast(const struct cpumask *mask)
{
#ifdef CONFIG_SMP
apic->send_IPI_mask(mask, LOCAL_TIMER_VECTOR);
#endif
}
static void setup_APIC_timer(void)
{
struct clock_event_device *levt = this_cpu_ptr(&lapic_events);
if (this_cpu_has(X86_FEATURE_ARAT)) {
lapic_clockevent.features &= ~CLOCK_EVT_FEAT_C3STOP;
lapic_clockevent.rating = 150;
}
memcpy(levt, &lapic_clockevent, sizeof(*levt));
levt->cpumask = cpumask_of(smp_processor_id());
if (this_cpu_has(X86_FEATURE_TSC_DEADLINE_TIMER)) {
levt->features &= ~(CLOCK_EVT_FEAT_PERIODIC |
CLOCK_EVT_FEAT_DUMMY);
levt->set_next_event = lapic_next_deadline;
clockevents_config_and_register(levt,
(tsc_khz / TSC_DIVISOR) * 1000,
0xF, ~0UL);
} else
clockevents_register_device(levt);
}
static void __init lapic_cal_handler(struct clock_event_device *dev)
{
unsigned long long tsc = 0;
long tapic = apic_read(APIC_TMCCT);
unsigned long pm = acpi_pm_read_early();
if (cpu_has_tsc)
tsc = rdtsc();
switch (lapic_cal_loops++) {
case 0:
lapic_cal_t1 = tapic;
lapic_cal_tsc1 = tsc;
lapic_cal_pm1 = pm;
lapic_cal_j1 = jiffies;
break;
case LAPIC_CAL_LOOPS:
lapic_cal_t2 = tapic;
lapic_cal_tsc2 = tsc;
if (pm < lapic_cal_pm1)
pm += ACPI_PM_OVRRUN;
lapic_cal_pm2 = pm;
lapic_cal_j2 = jiffies;
break;
}
}
static int __init
calibrate_by_pmtimer(long deltapm, long *delta, long *deltatsc)
{
const long pm_100ms = PMTMR_TICKS_PER_SEC / 10;
const long pm_thresh = pm_100ms / 100;
unsigned long mult;
u64 res;
#ifndef CONFIG_X86_PM_TIMER
return -1;
#endif
apic_printk(APIC_VERBOSE, "... PM-Timer delta = %ld\n", deltapm);
if (!deltapm)
return -1;
mult = clocksource_hz2mult(PMTMR_TICKS_PER_SEC, 22);
if (deltapm > (pm_100ms - pm_thresh) &&
deltapm < (pm_100ms + pm_thresh)) {
apic_printk(APIC_VERBOSE, "... PM-Timer result ok\n");
return 0;
}
res = (((u64)deltapm) * mult) >> 22;
do_div(res, 1000000);
pr_warning("APIC calibration not consistent "
"with PM-Timer: %ldms instead of 100ms\n",(long)res);
res = (((u64)(*delta)) * pm_100ms);
do_div(res, deltapm);
pr_info("APIC delta adjusted to PM-Timer: "
"%lu (%ld)\n", (unsigned long)res, *delta);
*delta = (long)res;
if (cpu_has_tsc) {
res = (((u64)(*deltatsc)) * pm_100ms);
do_div(res, deltapm);
apic_printk(APIC_VERBOSE, "TSC delta adjusted to "
"PM-Timer: %lu (%ld)\n",
(unsigned long)res, *deltatsc);
*deltatsc = (long)res;
}
return 0;
}
static int __init calibrate_APIC_clock(void)
{
struct clock_event_device *levt = this_cpu_ptr(&lapic_events);
void (*real_handler)(struct clock_event_device *dev);
unsigned long deltaj;
long delta, deltatsc;
int pm_referenced = 0;
if (boot_cpu_has(X86_FEATURE_TSC_DEADLINE_TIMER)) {
return 0;
} else if (lapic_timer_frequency) {
apic_printk(APIC_VERBOSE, "lapic timer already calibrated %d\n",
lapic_timer_frequency);
lapic_clockevent.mult = div_sc(lapic_timer_frequency/APIC_DIVISOR,
TICK_NSEC, lapic_clockevent.shift);
lapic_clockevent.max_delta_ns =
clockevent_delta2ns(0x7FFFFF, &lapic_clockevent);
lapic_clockevent.min_delta_ns =
clockevent_delta2ns(0xF, &lapic_clockevent);
lapic_clockevent.features &= ~CLOCK_EVT_FEAT_DUMMY;
return 0;
}
apic_printk(APIC_VERBOSE, "Using local APIC timer interrupts.\n"
"calibrating APIC timer ...\n");
local_irq_disable();
real_handler = global_clock_event->event_handler;
global_clock_event->event_handler = lapic_cal_handler;
__setup_APIC_LVTT(0xffffffff, 0, 0);
local_irq_enable();
while (lapic_cal_loops <= LAPIC_CAL_LOOPS)
cpu_relax();
local_irq_disable();
global_clock_event->event_handler = real_handler;
delta = lapic_cal_t1 - lapic_cal_t2;
apic_printk(APIC_VERBOSE, "... lapic delta = %ld\n", delta);
deltatsc = (long)(lapic_cal_tsc2 - lapic_cal_tsc1);
pm_referenced = !calibrate_by_pmtimer(lapic_cal_pm2 - lapic_cal_pm1,
&delta, &deltatsc);
lapic_clockevent.mult = div_sc(delta, TICK_NSEC * LAPIC_CAL_LOOPS,
lapic_clockevent.shift);
lapic_clockevent.max_delta_ns =
clockevent_delta2ns(0x7FFFFFFF, &lapic_clockevent);
lapic_clockevent.min_delta_ns =
clockevent_delta2ns(0xF, &lapic_clockevent);
lapic_timer_frequency = (delta * APIC_DIVISOR) / LAPIC_CAL_LOOPS;
apic_printk(APIC_VERBOSE, "..... delta %ld\n", delta);
apic_printk(APIC_VERBOSE, "..... mult: %u\n", lapic_clockevent.mult);
apic_printk(APIC_VERBOSE, "..... calibration result: %u\n",
lapic_timer_frequency);
if (cpu_has_tsc) {
apic_printk(APIC_VERBOSE, "..... CPU clock speed is "
"%ld.%04ld MHz.\n",
(deltatsc / LAPIC_CAL_LOOPS) / (1000000 / HZ),
(deltatsc / LAPIC_CAL_LOOPS) % (1000000 / HZ));
}
apic_printk(APIC_VERBOSE, "..... host bus clock speed is "
"%u.%04u MHz.\n",
lapic_timer_frequency / (1000000 / HZ),
lapic_timer_frequency % (1000000 / HZ));
if (lapic_timer_frequency < (1000000 / HZ)) {
local_irq_enable();
pr_warning("APIC frequency too slow, disabling apic timer\n");
return -1;
}
levt->features &= ~CLOCK_EVT_FEAT_DUMMY;
if (!pm_referenced) {
apic_printk(APIC_VERBOSE, "... verify APIC timer\n");
levt->event_handler = lapic_cal_handler;
lapic_timer_set_periodic(levt);
lapic_cal_loops = -1;
local_irq_enable();
while (lapic_cal_loops <= LAPIC_CAL_LOOPS)
cpu_relax();
local_irq_disable();
lapic_timer_shutdown(levt);
deltaj = lapic_cal_j2 - lapic_cal_j1;
apic_printk(APIC_VERBOSE, "... jiffies delta = %lu\n", deltaj);
if (deltaj >= LAPIC_CAL_LOOPS-2 && deltaj <= LAPIC_CAL_LOOPS+2)
apic_printk(APIC_VERBOSE, "... jiffies result ok\n");
else
levt->features |= CLOCK_EVT_FEAT_DUMMY;
}
local_irq_enable();
if (levt->features & CLOCK_EVT_FEAT_DUMMY) {
pr_warning("APIC timer disabled due to verification failure\n");
return -1;
}
return 0;
}
void __init setup_boot_APIC_clock(void)
{
if (disable_apic_timer) {
pr_info("Disabling APIC timer\n");
if (num_possible_cpus() > 1) {
lapic_clockevent.mult = 1;
setup_APIC_timer();
}
return;
}
if (calibrate_APIC_clock()) {
if (num_possible_cpus() > 1)
setup_APIC_timer();
return;
}
lapic_clockevent.features &= ~CLOCK_EVT_FEAT_DUMMY;
setup_APIC_timer();
}
void setup_secondary_APIC_clock(void)
{
setup_APIC_timer();
}
static void local_apic_timer_interrupt(void)
{
int cpu = smp_processor_id();
struct clock_event_device *evt = &per_cpu(lapic_events, cpu);
if (!evt->event_handler) {
pr_warning("Spurious LAPIC timer interrupt on cpu %d\n", cpu);
lapic_timer_shutdown(evt);
return;
}
inc_irq_stat(apic_timer_irqs);
evt->event_handler(evt);
}
__visible void __irq_entry smp_apic_timer_interrupt(struct pt_regs *regs)
{
struct pt_regs *old_regs = set_irq_regs(regs);
entering_ack_irq();
local_apic_timer_interrupt();
exiting_irq();
set_irq_regs(old_regs);
}
__visible void __irq_entry smp_trace_apic_timer_interrupt(struct pt_regs *regs)
{
struct pt_regs *old_regs = set_irq_regs(regs);
entering_ack_irq();
trace_local_timer_entry(LOCAL_TIMER_VECTOR);
local_apic_timer_interrupt();
trace_local_timer_exit(LOCAL_TIMER_VECTOR);
exiting_irq();
set_irq_regs(old_regs);
}
int setup_profiling_timer(unsigned int multiplier)
{
return -EINVAL;
}
void clear_local_APIC(void)
{
int maxlvt;
u32 v;
if (!x2apic_mode && !apic_phys)
return;
maxlvt = lapic_get_maxlvt();
if (maxlvt >= 3) {
v = ERROR_APIC_VECTOR;
apic_write(APIC_LVTERR, v | APIC_LVT_MASKED);
}
v = apic_read(APIC_LVTT);
apic_write(APIC_LVTT, v | APIC_LVT_MASKED);
v = apic_read(APIC_LVT0);
apic_write(APIC_LVT0, v | APIC_LVT_MASKED);
v = apic_read(APIC_LVT1);
apic_write(APIC_LVT1, v | APIC_LVT_MASKED);
if (maxlvt >= 4) {
v = apic_read(APIC_LVTPC);
apic_write(APIC_LVTPC, v | APIC_LVT_MASKED);
}
#ifdef CONFIG_X86_THERMAL_VECTOR
if (maxlvt >= 5) {
v = apic_read(APIC_LVTTHMR);
apic_write(APIC_LVTTHMR, v | APIC_LVT_MASKED);
}
#endif
#ifdef CONFIG_X86_MCE_INTEL
if (maxlvt >= 6) {
v = apic_read(APIC_LVTCMCI);
if (!(v & APIC_LVT_MASKED))
apic_write(APIC_LVTCMCI, v | APIC_LVT_MASKED);
}
#endif
apic_write(APIC_LVTT, APIC_LVT_MASKED);
apic_write(APIC_LVT0, APIC_LVT_MASKED);
apic_write(APIC_LVT1, APIC_LVT_MASKED);
if (maxlvt >= 3)
apic_write(APIC_LVTERR, APIC_LVT_MASKED);
if (maxlvt >= 4)
apic_write(APIC_LVTPC, APIC_LVT_MASKED);
if (lapic_is_integrated()) {
if (maxlvt > 3)
apic_write(APIC_ESR, 0);
apic_read(APIC_ESR);
}
}
void disable_local_APIC(void)
{
unsigned int value;
if (!x2apic_mode && !apic_phys)
return;
clear_local_APIC();
value = apic_read(APIC_SPIV);
value &= ~APIC_SPIV_APIC_ENABLED;
apic_write(APIC_SPIV, value);
#ifdef CONFIG_X86_32
if (enabled_via_apicbase) {
unsigned int l, h;
rdmsr(MSR_IA32_APICBASE, l, h);
l &= ~MSR_IA32_APICBASE_ENABLE;
wrmsr(MSR_IA32_APICBASE, l, h);
}
#endif
}
void lapic_shutdown(void)
{
unsigned long flags;
if (!cpu_has_apic && !apic_from_smp_config())
return;
local_irq_save(flags);
#ifdef CONFIG_X86_32
if (!enabled_via_apicbase)
clear_local_APIC();
else
#endif
disable_local_APIC();
local_irq_restore(flags);
}
void __init sync_Arb_IDs(void)
{
if (modern_apic() || boot_cpu_data.x86_vendor == X86_VENDOR_AMD)
return;
apic_wait_icr_idle();
apic_printk(APIC_DEBUG, "Synchronizing Arb IDs.\n");
apic_write(APIC_ICR, APIC_DEST_ALLINC |
APIC_INT_LEVELTRIG | APIC_DM_INIT);
}
void __init init_bsp_APIC(void)
{
unsigned int value;
if (smp_found_config || !cpu_has_apic)
return;
clear_local_APIC();
value = apic_read(APIC_SPIV);
value &= ~APIC_VECTOR_MASK;
value |= APIC_SPIV_APIC_ENABLED;
#ifdef CONFIG_X86_32
if ((boot_cpu_data.x86_vendor == X86_VENDOR_INTEL) &&
(boot_cpu_data.x86 == 15))
value &= ~APIC_SPIV_FOCUS_DISABLED;
else
#endif
value |= APIC_SPIV_FOCUS_DISABLED;
value |= SPURIOUS_APIC_VECTOR;
apic_write(APIC_SPIV, value);
apic_write(APIC_LVT0, APIC_DM_EXTINT);
value = APIC_DM_NMI;
if (!lapic_is_integrated())
value |= APIC_LVT_LEVEL_TRIGGER;
if (apic_extnmi == APIC_EXTNMI_NONE)
value |= APIC_LVT_MASKED;
apic_write(APIC_LVT1, value);
}
static void lapic_setup_esr(void)
{
unsigned int oldvalue, value, maxlvt;
if (!lapic_is_integrated()) {
pr_info("No ESR for 82489DX.\n");
return;
}
if (apic->disable_esr) {
pr_info("Leaving ESR disabled.\n");
return;
}
maxlvt = lapic_get_maxlvt();
if (maxlvt > 3)
apic_write(APIC_ESR, 0);
oldvalue = apic_read(APIC_ESR);
value = ERROR_APIC_VECTOR;
apic_write(APIC_LVTERR, value);
if (maxlvt > 3)
apic_write(APIC_ESR, 0);
value = apic_read(APIC_ESR);
if (value != oldvalue)
apic_printk(APIC_VERBOSE, "ESR value before enabling "
"vector: 0x%08x after: 0x%08x\n",
oldvalue, value);
}
void setup_local_APIC(void)
{
int cpu = smp_processor_id();
unsigned int value, queued;
int i, j, acked = 0;
unsigned long long tsc = 0, ntsc;
long long max_loops = cpu_khz ? cpu_khz : 1000000;
if (cpu_has_tsc)
tsc = rdtsc();
if (disable_apic) {
disable_ioapic_support();
return;
}
#ifdef CONFIG_X86_32
if (lapic_is_integrated() && apic->disable_esr) {
apic_write(APIC_ESR, 0);
apic_write(APIC_ESR, 0);
apic_write(APIC_ESR, 0);
apic_write(APIC_ESR, 0);
}
#endif
perf_events_lapic_init();
BUG_ON(!apic->apic_id_registered());
apic->init_apic_ldr();
#ifdef CONFIG_X86_32
i = early_per_cpu(x86_cpu_to_logical_apicid, cpu);
WARN_ON(i != BAD_APICID && i != logical_smp_processor_id());
early_per_cpu(x86_cpu_to_logical_apicid, cpu) =
logical_smp_processor_id();
#endif
value = apic_read(APIC_TASKPRI);
value &= ~APIC_TPRI_MASK;
apic_write(APIC_TASKPRI, value);
do {
queued = 0;
for (i = APIC_ISR_NR - 1; i >= 0; i--)
queued |= apic_read(APIC_IRR + i*0x10);
for (i = APIC_ISR_NR - 1; i >= 0; i--) {
value = apic_read(APIC_ISR + i*0x10);
for (j = 31; j >= 0; j--) {
if (value & (1<<j)) {
ack_APIC_irq();
acked++;
}
}
}
if (acked > 256) {
printk(KERN_ERR "LAPIC pending interrupts after %d EOI\n",
acked);
break;
}
if (queued) {
if (cpu_has_tsc && cpu_khz) {
ntsc = rdtsc();
max_loops = (cpu_khz << 10) - (ntsc - tsc);
} else
max_loops--;
}
} while (queued && max_loops > 0);
WARN_ON(max_loops <= 0);
value = apic_read(APIC_SPIV);
value &= ~APIC_VECTOR_MASK;
value |= APIC_SPIV_APIC_ENABLED;
#ifdef CONFIG_X86_32
value &= ~APIC_SPIV_FOCUS_DISABLED;
#endif
value |= SPURIOUS_APIC_VECTOR;
apic_write(APIC_SPIV, value);
value = apic_read(APIC_LVT0) & APIC_LVT_MASKED;
if (!cpu && (pic_mode || !value)) {
value = APIC_DM_EXTINT;
apic_printk(APIC_VERBOSE, "enabled ExtINT on CPU#%d\n", cpu);
} else {
value = APIC_DM_EXTINT | APIC_LVT_MASKED;
apic_printk(APIC_VERBOSE, "masked ExtINT on CPU#%d\n", cpu);
}
apic_write(APIC_LVT0, value);
if ((!cpu && apic_extnmi != APIC_EXTNMI_NONE) ||
apic_extnmi == APIC_EXTNMI_ALL)
value = APIC_DM_NMI;
else
value = APIC_DM_NMI | APIC_LVT_MASKED;
if (!lapic_is_integrated())
value |= APIC_LVT_LEVEL_TRIGGER;
apic_write(APIC_LVT1, value);
#ifdef CONFIG_X86_MCE_INTEL
if (!cpu)
cmci_recheck();
#endif
}
static void end_local_APIC_setup(void)
{
lapic_setup_esr();
#ifdef CONFIG_X86_32
{
unsigned int value;
value = apic_read(APIC_LVTT);
value |= (APIC_LVT_MASKED | LOCAL_TIMER_VECTOR);
apic_write(APIC_LVTT, value);
}
#endif
apic_pm_activate();
}
void apic_ap_setup(void)
{
setup_local_APIC();
end_local_APIC_setup();
}
static void __x2apic_disable(void)
{
u64 msr;
if (!cpu_has_apic)
return;
rdmsrl(MSR_IA32_APICBASE, msr);
if (!(msr & X2APIC_ENABLE))
return;
wrmsrl(MSR_IA32_APICBASE, msr & ~(X2APIC_ENABLE | XAPIC_ENABLE));
wrmsrl(MSR_IA32_APICBASE, msr & ~X2APIC_ENABLE);
printk_once(KERN_INFO "x2apic disabled\n");
}
static void __x2apic_enable(void)
{
u64 msr;
rdmsrl(MSR_IA32_APICBASE, msr);
if (msr & X2APIC_ENABLE)
return;
wrmsrl(MSR_IA32_APICBASE, msr | X2APIC_ENABLE);
printk_once(KERN_INFO "x2apic enabled\n");
}
static int __init setup_nox2apic(char *str)
{
if (x2apic_enabled()) {
int apicid = native_apic_msr_read(APIC_ID);
if (apicid >= 255) {
pr_warning("Apicid: %08x, cannot enforce nox2apic\n",
apicid);
return 0;
}
pr_warning("x2apic already enabled.\n");
__x2apic_disable();
}
setup_clear_cpu_cap(X86_FEATURE_X2APIC);
x2apic_state = X2APIC_DISABLED;
x2apic_mode = 0;
return 0;
}
void x2apic_setup(void)
{
if (x2apic_state != X2APIC_ON) {
__x2apic_disable();
return;
}
__x2apic_enable();
}
static __init void x2apic_disable(void)
{
u32 x2apic_id, state = x2apic_state;
x2apic_mode = 0;
x2apic_state = X2APIC_DISABLED;
if (state != X2APIC_ON)
return;
x2apic_id = read_apic_id();
if (x2apic_id >= 255)
panic("Cannot disable x2apic, id: %08x\n", x2apic_id);
__x2apic_disable();
register_lapic_address(mp_lapic_addr);
}
static __init void x2apic_enable(void)
{
if (x2apic_state != X2APIC_OFF)
return;
x2apic_mode = 1;
x2apic_state = X2APIC_ON;
__x2apic_enable();
}
static __init void try_to_enable_x2apic(int remap_mode)
{
if (x2apic_state == X2APIC_DISABLED)
return;
if (remap_mode != IRQ_REMAP_X2APIC_MODE) {
if (max_physical_apicid > 255 ||
!hypervisor_x2apic_available()) {
pr_info("x2apic: IRQ remapping doesn't support X2APIC mode\n");
x2apic_disable();
return;
}
x2apic_phys = 1;
}
x2apic_enable();
}
void __init check_x2apic(void)
{
if (x2apic_enabled()) {
pr_info("x2apic: enabled by BIOS, switching to x2apic ops\n");
x2apic_mode = 1;
x2apic_state = X2APIC_ON;
} else if (!cpu_has_x2apic) {
x2apic_state = X2APIC_DISABLED;
}
}
static int __init validate_x2apic(void)
{
if (!apic_is_x2apic_enabled())
return 0;
panic("BIOS has enabled x2apic but kernel doesn't support x2apic, please disable x2apic in BIOS.\n");
}
static inline void try_to_enable_x2apic(int remap_mode) { }
static inline void __x2apic_enable(void) { }
static int __init try_to_enable_IR(void)
{
#ifdef CONFIG_X86_IO_APIC
if (!x2apic_enabled() && skip_ioapic_setup) {
pr_info("Not enabling interrupt remapping due to skipped IO-APIC setup\n");
return -1;
}
#endif
return irq_remapping_enable();
}
void __init enable_IR_x2apic(void)
{
unsigned long flags;
int ret, ir_stat;
ir_stat = irq_remapping_prepare();
if (ir_stat < 0 && !x2apic_supported())
return;
ret = save_ioapic_entries();
if (ret) {
pr_info("Saving IO-APIC state failed: %d\n", ret);
return;
}
local_irq_save(flags);
legacy_pic->mask_all();
mask_ioapic_entries();
if (ir_stat >= 0)
ir_stat = try_to_enable_IR();
try_to_enable_x2apic(ir_stat);
if (ir_stat < 0)
restore_ioapic_entries();
legacy_pic->restore_mask();
local_irq_restore(flags);
}
static int __init detect_init_APIC(void)
{
if (!cpu_has_apic) {
pr_info("No local APIC present\n");
return -1;
}
mp_lapic_addr = APIC_DEFAULT_PHYS_BASE;
return 0;
}
static int __init apic_verify(void)
{
u32 features, h, l;
features = cpuid_edx(1);
if (!(features & (1 << X86_FEATURE_APIC))) {
pr_warning("Could not enable APIC!\n");
return -1;
}
set_cpu_cap(&boot_cpu_data, X86_FEATURE_APIC);
mp_lapic_addr = APIC_DEFAULT_PHYS_BASE;
if (boot_cpu_data.x86 >= 6) {
rdmsr(MSR_IA32_APICBASE, l, h);
if (l & MSR_IA32_APICBASE_ENABLE)
mp_lapic_addr = l & MSR_IA32_APICBASE_BASE;
}
pr_info("Found and enabled local APIC!\n");
return 0;
}
int __init apic_force_enable(unsigned long addr)
{
u32 h, l;
if (disable_apic)
return -1;
if (boot_cpu_data.x86 >= 6) {
rdmsr(MSR_IA32_APICBASE, l, h);
if (!(l & MSR_IA32_APICBASE_ENABLE)) {
pr_info("Local APIC disabled by BIOS -- reenabling.\n");
l &= ~MSR_IA32_APICBASE_BASE;
l |= MSR_IA32_APICBASE_ENABLE | addr;
wrmsr(MSR_IA32_APICBASE, l, h);
enabled_via_apicbase = 1;
}
}
return apic_verify();
}
static int __init detect_init_APIC(void)
{
if (disable_apic)
return -1;
switch (boot_cpu_data.x86_vendor) {
case X86_VENDOR_AMD:
if ((boot_cpu_data.x86 == 6 && boot_cpu_data.x86_model > 1) ||
(boot_cpu_data.x86 >= 15))
break;
goto no_apic;
case X86_VENDOR_INTEL:
if (boot_cpu_data.x86 == 6 || boot_cpu_data.x86 == 15 ||
(boot_cpu_data.x86 == 5 && cpu_has_apic))
break;
goto no_apic;
default:
goto no_apic;
}
if (!cpu_has_apic) {
if (!force_enable_local_apic) {
pr_info("Local APIC disabled by BIOS -- "
"you can enable it with \"lapic\"\n");
return -1;
}
if (apic_force_enable(APIC_DEFAULT_PHYS_BASE))
return -1;
} else {
if (apic_verify())
return -1;
}
apic_pm_activate();
return 0;
no_apic:
pr_info("No local APIC present or hardware disabled\n");
return -1;
}
void __init init_apic_mappings(void)
{
unsigned int new_apicid;
if (x2apic_mode) {
boot_cpu_physical_apicid = read_apic_id();
return;
}
if (!smp_found_config && detect_init_APIC()) {
pr_info("APIC: disable apic facility\n");
apic_disable();
} else {
apic_phys = mp_lapic_addr;
if (!acpi_lapic && !smp_found_config)
register_lapic_address(apic_phys);
}
new_apicid = read_apic_id();
if (boot_cpu_physical_apicid != new_apicid) {
boot_cpu_physical_apicid = new_apicid;
apic_version[new_apicid] =
GET_APIC_VERSION(apic_read(APIC_LVR));
}
}
void __init register_lapic_address(unsigned long address)
{
mp_lapic_addr = address;
if (!x2apic_mode) {
set_fixmap_nocache(FIX_APIC_BASE, address);
apic_printk(APIC_VERBOSE, "mapped APIC to %16lx (%16lx)\n",
APIC_BASE, mp_lapic_addr);
}
if (boot_cpu_physical_apicid == -1U) {
boot_cpu_physical_apicid = read_apic_id();
apic_version[boot_cpu_physical_apicid] =
GET_APIC_VERSION(apic_read(APIC_LVR));
}
}
static void __smp_spurious_interrupt(u8 vector)
{
u32 v;
v = apic_read(APIC_ISR + ((vector & ~0x1f) >> 1));
if (v & (1 << (vector & 0x1f)))
ack_APIC_irq();
inc_irq_stat(irq_spurious_count);
pr_info("spurious APIC interrupt through vector %02x on CPU#%d, "
"should never happen.\n", vector, smp_processor_id());
}
__visible void smp_spurious_interrupt(struct pt_regs *regs)
{
entering_irq();
__smp_spurious_interrupt(~regs->orig_ax);
exiting_irq();
}
__visible void smp_trace_spurious_interrupt(struct pt_regs *regs)
{
u8 vector = ~regs->orig_ax;
entering_irq();
trace_spurious_apic_entry(vector);
__smp_spurious_interrupt(vector);
trace_spurious_apic_exit(vector);
exiting_irq();
}
static void __smp_error_interrupt(struct pt_regs *regs)
{
u32 v;
u32 i = 0;
static const char * const error_interrupt_reason[] = {
"Send CS error",
"Receive CS error",
"Send accept error",
"Receive accept error",
"Redirectable IPI",
"Send illegal vector",
"Received illegal vector",
"Illegal register address",
};
if (lapic_get_maxlvt() > 3)
apic_write(APIC_ESR, 0);
v = apic_read(APIC_ESR);
ack_APIC_irq();
atomic_inc(&irq_err_count);
apic_printk(APIC_DEBUG, KERN_DEBUG "APIC error on CPU%d: %02x",
smp_processor_id(), v);
v &= 0xff;
while (v) {
if (v & 0x1)
apic_printk(APIC_DEBUG, KERN_CONT " : %s", error_interrupt_reason[i]);
i++;
v >>= 1;
}
apic_printk(APIC_DEBUG, KERN_CONT "\n");
}
__visible void smp_error_interrupt(struct pt_regs *regs)
{
entering_irq();
__smp_error_interrupt(regs);
exiting_irq();
}
__visible void smp_trace_error_interrupt(struct pt_regs *regs)
{
entering_irq();
trace_error_apic_entry(ERROR_APIC_VECTOR);
__smp_error_interrupt(regs);
trace_error_apic_exit(ERROR_APIC_VECTOR);
exiting_irq();
}
static void __init connect_bsp_APIC(void)
{
#ifdef CONFIG_X86_32
if (pic_mode) {
clear_local_APIC();
apic_printk(APIC_VERBOSE, "leaving PIC mode, "
"enabling APIC mode.\n");
imcr_pic_to_apic();
}
#endif
}
void disconnect_bsp_APIC(int virt_wire_setup)
{
unsigned int value;
#ifdef CONFIG_X86_32
if (pic_mode) {
apic_printk(APIC_VERBOSE, "disabling APIC mode, "
"entering PIC mode.\n");
imcr_apic_to_pic();
return;
}
#endif
value = apic_read(APIC_SPIV);
value &= ~APIC_VECTOR_MASK;
value |= APIC_SPIV_APIC_ENABLED;
value |= 0xf;
apic_write(APIC_SPIV, value);
if (!virt_wire_setup) {
value = apic_read(APIC_LVT0);
value &= ~(APIC_MODE_MASK | APIC_SEND_PENDING |
APIC_INPUT_POLARITY | APIC_LVT_REMOTE_IRR |
APIC_LVT_LEVEL_TRIGGER | APIC_LVT_MASKED);
value |= APIC_LVT_REMOTE_IRR | APIC_SEND_PENDING;
value = SET_APIC_DELIVERY_MODE(value, APIC_MODE_EXTINT);
apic_write(APIC_LVT0, value);
} else {
apic_write(APIC_LVT0, APIC_LVT_MASKED);
}
value = apic_read(APIC_LVT1);
value &= ~(APIC_MODE_MASK | APIC_SEND_PENDING |
APIC_INPUT_POLARITY | APIC_LVT_REMOTE_IRR |
APIC_LVT_LEVEL_TRIGGER | APIC_LVT_MASKED);
value |= APIC_LVT_REMOTE_IRR | APIC_SEND_PENDING;
value = SET_APIC_DELIVERY_MODE(value, APIC_MODE_NMI);
apic_write(APIC_LVT1, value);
}
int generic_processor_info(int apicid, int version)
{
int cpu, max = nr_cpu_ids;
bool boot_cpu_detected = physid_isset(boot_cpu_physical_apicid,
phys_cpu_present_map);
if (disabled_cpu_apicid != BAD_APICID &&
disabled_cpu_apicid != read_apic_id() &&
disabled_cpu_apicid == apicid) {
int thiscpu = num_processors + disabled_cpus;
pr_warning("APIC: Disabling requested cpu."
" Processor %d/0x%x ignored.\n",
thiscpu, apicid);
disabled_cpus++;
return -ENODEV;
}
if (!boot_cpu_detected && num_processors >= nr_cpu_ids - 1 &&
apicid != boot_cpu_physical_apicid) {
int thiscpu = max + disabled_cpus - 1;
pr_warning(
"ACPI: NR_CPUS/possible_cpus limit of %i almost"
" reached. Keeping one slot for boot cpu."
" Processor %d/0x%x ignored.\n", max, thiscpu, apicid);
disabled_cpus++;
return -ENODEV;
}
if (num_processors >= nr_cpu_ids) {
int thiscpu = max + disabled_cpus;
pr_warning(
"ACPI: NR_CPUS/possible_cpus limit of %i reached."
" Processor %d/0x%x ignored.\n", max, thiscpu, apicid);
disabled_cpus++;
return -EINVAL;
}
num_processors++;
if (apicid == boot_cpu_physical_apicid) {
cpu = 0;
} else
cpu = cpumask_next_zero(-1, cpu_present_mask);
if (topology_update_package_map(apicid, cpu) < 0) {
int thiscpu = max + disabled_cpus;
pr_warning("ACPI: Package limit reached. Processor %d/0x%x ignored.\n",
thiscpu, apicid);
disabled_cpus++;
return -ENOSPC;
}
if (version == 0x0) {
pr_warning("BIOS bug: APIC version is 0 for CPU %d/0x%x, fixing up to 0x10\n",
cpu, apicid);
version = 0x10;
}
apic_version[apicid] = version;
if (version != apic_version[boot_cpu_physical_apicid]) {
pr_warning("BIOS bug: APIC version mismatch, boot CPU: %x, CPU %d: version %x\n",
apic_version[boot_cpu_physical_apicid], cpu, version);
}
physid_set(apicid, phys_cpu_present_map);
if (apicid > max_physical_apicid)
max_physical_apicid = apicid;
#if defined(CONFIG_SMP) || defined(CONFIG_X86_64)
early_per_cpu(x86_cpu_to_apicid, cpu) = apicid;
early_per_cpu(x86_bios_cpu_apicid, cpu) = apicid;
#endif
#ifdef CONFIG_X86_32
early_per_cpu(x86_cpu_to_logical_apicid, cpu) =
apic->x86_32_early_logical_apicid(cpu);
#endif
set_cpu_possible(cpu, true);
set_cpu_present(cpu, true);
return cpu;
}
int hard_smp_processor_id(void)
{
return read_apic_id();
}
void default_init_apic_ldr(void)
{
unsigned long val;
apic_write(APIC_DFR, APIC_DFR_VALUE);
val = apic_read(APIC_LDR) & ~APIC_LDR_MASK;
val |= SET_APIC_LOGICAL_ID(1UL << smp_processor_id());
apic_write(APIC_LDR, val);
}
int default_cpu_mask_to_apicid_and(const struct cpumask *cpumask,
const struct cpumask *andmask,
unsigned int *apicid)
{
unsigned int cpu;
for_each_cpu_and(cpu, cpumask, andmask) {
if (cpumask_test_cpu(cpu, cpu_online_mask))
break;
}
if (likely(cpu < nr_cpu_ids)) {
*apicid = per_cpu(x86_cpu_to_apicid, cpu);
return 0;
}
return -EINVAL;
}
void __init apic_set_eoi_write(void (*eoi_write)(u32 reg, u32 v))
{
struct apic **drv;
for (drv = __apicdrivers; drv < __apicdrivers_end; drv++) {
WARN_ON((*drv)->eoi_write == eoi_write);
(*drv)->eoi_write = eoi_write;
}
}
static void __init apic_bsp_up_setup(void)
{
#ifdef CONFIG_X86_64
apic_write(APIC_ID, SET_APIC_ID(boot_cpu_physical_apicid));
#else
# ifdef CONFIG_CRASH_DUMP
boot_cpu_physical_apicid = read_apic_id();
# endif
#endif
physid_set_mask_of_physid(boot_cpu_physical_apicid, &phys_cpu_present_map);
}
int __init apic_bsp_setup(bool upmode)
{
int id;
connect_bsp_APIC();
if (upmode)
apic_bsp_up_setup();
setup_local_APIC();
if (x2apic_mode)
id = apic_read(APIC_LDR);
else
id = GET_APIC_LOGICAL_ID(apic_read(APIC_LDR));
enable_IO_APIC();
end_local_APIC_setup();
irq_remap_enable_fault_handling();
setup_IO_APIC();
x86_init.timers.setup_percpu_clockev();
return id;
}
int __init APIC_init_uniprocessor(void)
{
if (disable_apic) {
pr_info("Apic disabled\n");
return -1;
}
#ifdef CONFIG_X86_64
if (!cpu_has_apic) {
disable_apic = 1;
pr_info("Apic disabled by BIOS\n");
return -1;
}
#else
if (!smp_found_config && !cpu_has_apic)
return -1;
if (!cpu_has_apic &&
APIC_INTEGRATED(apic_version[boot_cpu_physical_apicid])) {
pr_err("BIOS bug, local APIC 0x%x not detected!...\n",
boot_cpu_physical_apicid);
return -1;
}
#endif
if (!smp_found_config)
disable_ioapic_support();
default_setup_apic_routing();
apic_bsp_setup(true);
return 0;
}
void __init up_late_init(void)
{
APIC_init_uniprocessor();
}
static int lapic_suspend(void)
{
unsigned long flags;
int maxlvt;
if (!apic_pm_state.active)
return 0;
maxlvt = lapic_get_maxlvt();
apic_pm_state.apic_id = apic_read(APIC_ID);
apic_pm_state.apic_taskpri = apic_read(APIC_TASKPRI);
apic_pm_state.apic_ldr = apic_read(APIC_LDR);
apic_pm_state.apic_dfr = apic_read(APIC_DFR);
apic_pm_state.apic_spiv = apic_read(APIC_SPIV);
apic_pm_state.apic_lvtt = apic_read(APIC_LVTT);
if (maxlvt >= 4)
apic_pm_state.apic_lvtpc = apic_read(APIC_LVTPC);
apic_pm_state.apic_lvt0 = apic_read(APIC_LVT0);
apic_pm_state.apic_lvt1 = apic_read(APIC_LVT1);
apic_pm_state.apic_lvterr = apic_read(APIC_LVTERR);
apic_pm_state.apic_tmict = apic_read(APIC_TMICT);
apic_pm_state.apic_tdcr = apic_read(APIC_TDCR);
#ifdef CONFIG_X86_THERMAL_VECTOR
if (maxlvt >= 5)
apic_pm_state.apic_thmr = apic_read(APIC_LVTTHMR);
#endif
#ifdef CONFIG_X86_MCE_INTEL
if (maxlvt >= 6)
apic_pm_state.apic_cmci = apic_read(APIC_LVTCMCI);
#endif
local_irq_save(flags);
disable_local_APIC();
irq_remapping_disable();
local_irq_restore(flags);
return 0;
}
static void lapic_resume(void)
{
unsigned int l, h;
unsigned long flags;
int maxlvt;
if (!apic_pm_state.active)
return;
local_irq_save(flags);
mask_ioapic_entries();
legacy_pic->mask_all();
if (x2apic_mode) {
__x2apic_enable();
} else {
if (boot_cpu_data.x86 >= 6) {
rdmsr(MSR_IA32_APICBASE, l, h);
l &= ~MSR_IA32_APICBASE_BASE;
l |= MSR_IA32_APICBASE_ENABLE | mp_lapic_addr;
wrmsr(MSR_IA32_APICBASE, l, h);
}
}
maxlvt = lapic_get_maxlvt();
apic_write(APIC_LVTERR, ERROR_APIC_VECTOR | APIC_LVT_MASKED);
apic_write(APIC_ID, apic_pm_state.apic_id);
apic_write(APIC_DFR, apic_pm_state.apic_dfr);
apic_write(APIC_LDR, apic_pm_state.apic_ldr);
apic_write(APIC_TASKPRI, apic_pm_state.apic_taskpri);
apic_write(APIC_SPIV, apic_pm_state.apic_spiv);
apic_write(APIC_LVT0, apic_pm_state.apic_lvt0);
apic_write(APIC_LVT1, apic_pm_state.apic_lvt1);
#ifdef CONFIG_X86_THERMAL_VECTOR
if (maxlvt >= 5)
apic_write(APIC_LVTTHMR, apic_pm_state.apic_thmr);
#endif
#ifdef CONFIG_X86_MCE_INTEL
if (maxlvt >= 6)
apic_write(APIC_LVTCMCI, apic_pm_state.apic_cmci);
#endif
if (maxlvt >= 4)
apic_write(APIC_LVTPC, apic_pm_state.apic_lvtpc);
apic_write(APIC_LVTT, apic_pm_state.apic_lvtt);
apic_write(APIC_TDCR, apic_pm_state.apic_tdcr);
apic_write(APIC_TMICT, apic_pm_state.apic_tmict);
apic_write(APIC_ESR, 0);
apic_read(APIC_ESR);
apic_write(APIC_LVTERR, apic_pm_state.apic_lvterr);
apic_write(APIC_ESR, 0);
apic_read(APIC_ESR);
irq_remapping_reenable(x2apic_mode);
local_irq_restore(flags);
}
static void apic_pm_activate(void)
{
apic_pm_state.active = 1;
}
static int __init init_lapic_sysfs(void)
{
if (cpu_has_apic)
register_syscore_ops(&lapic_syscore_ops);
return 0;
}
static void apic_pm_activate(void) { }
static int set_multi(const struct dmi_system_id *d)
{
if (multi)
return 0;
pr_info("APIC: %s detected, Multi Chassis\n", d->ident);
multi = 1;
return 0;
}
static void dmi_check_multi(void)
{
if (multi_checked)
return;
dmi_check_system(multi_dmi_table);
multi_checked = 1;
}
int apic_is_clustered_box(void)
{
dmi_check_multi();
return multi;
}
static int __init setup_disableapic(char *arg)
{
disable_apic = 1;
setup_clear_cpu_cap(X86_FEATURE_APIC);
return 0;
}
static int __init setup_nolapic(char *arg)
{
return setup_disableapic(arg);
}
static int __init parse_lapic_timer_c2_ok(char *arg)
{
local_apic_timer_c2_ok = 1;
return 0;
}
static int __init parse_disable_apic_timer(char *arg)
{
disable_apic_timer = 1;
return 0;
}
static int __init parse_nolapic_timer(char *arg)
{
disable_apic_timer = 1;
return 0;
}
static int __init apic_set_verbosity(char *arg)
{
if (!arg) {
#ifdef CONFIG_X86_64
skip_ioapic_setup = 0;
return 0;
#endif
return -EINVAL;
}
if (strcmp("debug", arg) == 0)
apic_verbosity = APIC_DEBUG;
else if (strcmp("verbose", arg) == 0)
apic_verbosity = APIC_VERBOSE;
else {
pr_warning("APIC Verbosity level %s not recognised"
" use apic=verbose or apic=debug\n", arg);
return -EINVAL;
}
return 0;
}
static int __init lapic_insert_resource(void)
{
if (!apic_phys)
return -1;
lapic_resource.start = apic_phys;
lapic_resource.end = lapic_resource.start + PAGE_SIZE - 1;
insert_resource(&iomem_resource, &lapic_resource);
return 0;
}
static int __init apic_set_disabled_cpu_apicid(char *arg)
{
if (!arg || !get_option(&arg, &disabled_cpu_apicid))
return -EINVAL;
return 0;
}
static int __init apic_set_extnmi(char *arg)
{
if (!arg)
return -EINVAL;
if (!strncmp("all", arg, 3))
apic_extnmi = APIC_EXTNMI_ALL;
else if (!strncmp("none", arg, 4))
apic_extnmi = APIC_EXTNMI_NONE;
else if (!strncmp("bsp", arg, 3))
apic_extnmi = APIC_EXTNMI_BSP;
else {
pr_warn("Unknown external NMI delivery mode `%s' ignored\n", arg);
return -EINVAL;
}
return 0;
}
