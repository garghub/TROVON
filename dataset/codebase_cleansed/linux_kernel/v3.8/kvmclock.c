static int parse_no_kvmclock(char *arg)
{
kvmclock = 0;
return 0;
}
static unsigned long kvm_get_wallclock(void)
{
struct pvclock_vcpu_time_info *vcpu_time;
struct timespec ts;
int low, high;
int cpu;
low = (int)__pa_symbol(&wall_clock);
high = ((u64)__pa_symbol(&wall_clock) >> 32);
native_write_msr(msr_kvm_wall_clock, low, high);
preempt_disable();
cpu = smp_processor_id();
vcpu_time = &hv_clock[cpu].pvti;
pvclock_read_wallclock(&wall_clock, vcpu_time, &ts);
preempt_enable();
return ts.tv_sec;
}
static int kvm_set_wallclock(unsigned long now)
{
return -1;
}
static cycle_t kvm_clock_read(void)
{
struct pvclock_vcpu_time_info *src;
cycle_t ret;
int cpu;
preempt_disable_notrace();
cpu = smp_processor_id();
src = &hv_clock[cpu].pvti;
ret = pvclock_clocksource_read(src);
preempt_enable_notrace();
return ret;
}
static cycle_t kvm_clock_get_cycles(struct clocksource *cs)
{
return kvm_clock_read();
}
static unsigned long kvm_get_tsc_khz(void)
{
struct pvclock_vcpu_time_info *src;
int cpu;
unsigned long tsc_khz;
preempt_disable();
cpu = smp_processor_id();
src = &hv_clock[cpu].pvti;
tsc_khz = pvclock_tsc_khz(src);
preempt_enable();
return tsc_khz;
}
static void kvm_get_preset_lpj(void)
{
unsigned long khz;
u64 lpj;
khz = kvm_get_tsc_khz();
lpj = ((u64)khz * 1000);
do_div(lpj, HZ);
preset_lpj = lpj;
}
bool kvm_check_and_clear_guest_paused(void)
{
bool ret = false;
struct pvclock_vcpu_time_info *src;
int cpu = smp_processor_id();
if (!hv_clock)
return ret;
src = &hv_clock[cpu].pvti;
if ((src->flags & PVCLOCK_GUEST_STOPPED) != 0) {
src->flags &= ~PVCLOCK_GUEST_STOPPED;
ret = true;
}
return ret;
}
int kvm_register_clock(char *txt)
{
int cpu = smp_processor_id();
int low, high, ret;
struct pvclock_vcpu_time_info *src = &hv_clock[cpu].pvti;
low = (int)__pa(src) | 1;
high = ((u64)__pa(src) >> 32);
ret = native_write_msr_safe(msr_kvm_system_time, low, high);
printk(KERN_INFO "kvm-clock: cpu %d, msr %x:%x, %s\n",
cpu, high, low, txt);
return ret;
}
static void kvm_save_sched_clock_state(void)
{
}
static void kvm_restore_sched_clock_state(void)
{
kvm_register_clock("primary cpu clock, resume");
}
static void __cpuinit kvm_setup_secondary_clock(void)
{
WARN_ON(kvm_register_clock("secondary cpu clock"));
}
static void kvm_crash_shutdown(struct pt_regs *regs)
{
native_write_msr(msr_kvm_system_time, 0, 0);
kvm_disable_steal_time();
native_machine_crash_shutdown(regs);
}
static void kvm_shutdown(void)
{
native_write_msr(msr_kvm_system_time, 0, 0);
kvm_disable_steal_time();
native_machine_shutdown();
}
void __init kvmclock_init(void)
{
unsigned long mem;
if (!kvm_para_available())
return;
if (kvmclock && kvm_para_has_feature(KVM_FEATURE_CLOCKSOURCE2)) {
msr_kvm_system_time = MSR_KVM_SYSTEM_TIME_NEW;
msr_kvm_wall_clock = MSR_KVM_WALL_CLOCK_NEW;
} else if (!(kvmclock && kvm_para_has_feature(KVM_FEATURE_CLOCKSOURCE)))
return;
printk(KERN_INFO "kvm-clock: Using msrs %x and %x",
msr_kvm_system_time, msr_kvm_wall_clock);
mem = memblock_alloc(sizeof(struct pvclock_vsyscall_time_info)*NR_CPUS,
PAGE_SIZE);
if (!mem)
return;
hv_clock = __va(mem);
if (kvm_register_clock("boot clock")) {
hv_clock = NULL;
memblock_free(mem,
sizeof(struct pvclock_vsyscall_time_info)*NR_CPUS);
return;
}
pv_time_ops.sched_clock = kvm_clock_read;
x86_platform.calibrate_tsc = kvm_get_tsc_khz;
x86_platform.get_wallclock = kvm_get_wallclock;
x86_platform.set_wallclock = kvm_set_wallclock;
#ifdef CONFIG_X86_LOCAL_APIC
x86_cpuinit.early_percpu_clock_init =
kvm_setup_secondary_clock;
#endif
x86_platform.save_sched_clock_state = kvm_save_sched_clock_state;
x86_platform.restore_sched_clock_state = kvm_restore_sched_clock_state;
machine_ops.shutdown = kvm_shutdown;
#ifdef CONFIG_KEXEC
machine_ops.crash_shutdown = kvm_crash_shutdown;
#endif
kvm_get_preset_lpj();
clocksource_register_hz(&kvm_clock, NSEC_PER_SEC);
pv_info.paravirt_enabled = 1;
pv_info.name = "KVM";
if (kvm_para_has_feature(KVM_FEATURE_CLOCKSOURCE_STABLE_BIT))
pvclock_set_flags(PVCLOCK_TSC_STABLE_BIT);
}
int __init kvm_setup_vsyscall_timeinfo(void)
{
#ifdef CONFIG_X86_64
int cpu;
int ret;
u8 flags;
struct pvclock_vcpu_time_info *vcpu_time;
unsigned int size;
size = sizeof(struct pvclock_vsyscall_time_info)*NR_CPUS;
preempt_disable();
cpu = smp_processor_id();
vcpu_time = &hv_clock[cpu].pvti;
flags = pvclock_read_flags(vcpu_time);
if (!(flags & PVCLOCK_TSC_STABLE_BIT)) {
preempt_enable();
return 1;
}
if ((ret = pvclock_init_vsyscall(hv_clock, size))) {
preempt_enable();
return ret;
}
preempt_enable();
kvm_clock.archdata.vclock_mode = VCLOCK_PVCLOCK;
#endif
return 0;
}
