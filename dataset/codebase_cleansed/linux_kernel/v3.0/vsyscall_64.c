void update_vsyscall_tz(void)
{
unsigned long flags;
write_seqlock_irqsave(&vsyscall_gtod_data.lock, flags);
vsyscall_gtod_data.sys_tz = sys_tz;
write_sequnlock_irqrestore(&vsyscall_gtod_data.lock, flags);
}
void update_vsyscall(struct timespec *wall_time, struct timespec *wtm,
struct clocksource *clock, u32 mult)
{
unsigned long flags;
write_seqlock_irqsave(&vsyscall_gtod_data.lock, flags);
vsyscall_gtod_data.clock.vread = clock->vread;
vsyscall_gtod_data.clock.cycle_last = clock->cycle_last;
vsyscall_gtod_data.clock.mask = clock->mask;
vsyscall_gtod_data.clock.mult = mult;
vsyscall_gtod_data.clock.shift = clock->shift;
vsyscall_gtod_data.wall_time_sec = wall_time->tv_sec;
vsyscall_gtod_data.wall_time_nsec = wall_time->tv_nsec;
vsyscall_gtod_data.wall_to_monotonic = *wtm;
vsyscall_gtod_data.wall_time_coarse = __current_kernel_time();
write_sequnlock_irqrestore(&vsyscall_gtod_data.lock, flags);
}
static __always_inline void do_get_tz(struct timezone * tz)
{
*tz = VVAR(vsyscall_gtod_data).sys_tz;
}
static __always_inline int gettimeofday(struct timeval *tv, struct timezone *tz)
{
int ret;
asm volatile("syscall"
: "=a" (ret)
: "0" (__NR_gettimeofday),"D" (tv),"S" (tz)
: __syscall_clobber );
return ret;
}
static __always_inline long time_syscall(long *t)
{
long secs;
asm volatile("syscall"
: "=a" (secs)
: "0" (__NR_time),"D" (t) : __syscall_clobber);
return secs;
}
static __always_inline void do_vgettimeofday(struct timeval * tv)
{
cycle_t now, base, mask, cycle_delta;
unsigned seq;
unsigned long mult, shift, nsec;
cycle_t (*vread)(void);
do {
seq = read_seqbegin(&VVAR(vsyscall_gtod_data).lock);
vread = VVAR(vsyscall_gtod_data).clock.vread;
if (unlikely(!VVAR(vsyscall_gtod_data).sysctl_enabled ||
!vread)) {
gettimeofday(tv,NULL);
return;
}
now = vread();
base = VVAR(vsyscall_gtod_data).clock.cycle_last;
mask = VVAR(vsyscall_gtod_data).clock.mask;
mult = VVAR(vsyscall_gtod_data).clock.mult;
shift = VVAR(vsyscall_gtod_data).clock.shift;
tv->tv_sec = VVAR(vsyscall_gtod_data).wall_time_sec;
nsec = VVAR(vsyscall_gtod_data).wall_time_nsec;
} while (read_seqretry(&VVAR(vsyscall_gtod_data).lock, seq));
cycle_delta = (now - base) & mask;
nsec += (cycle_delta * mult) >> shift;
while (nsec >= NSEC_PER_SEC) {
tv->tv_sec += 1;
nsec -= NSEC_PER_SEC;
}
tv->tv_usec = nsec / NSEC_PER_USEC;
}
static void __cpuinit vsyscall_set_cpu(int cpu)
{
unsigned long d;
unsigned long node = 0;
#ifdef CONFIG_NUMA
node = cpu_to_node(cpu);
#endif
if (cpu_has(&cpu_data(cpu), X86_FEATURE_RDTSCP))
write_rdtscp_aux((node << 12) | cpu);
d = 0x0f40000000000ULL;
d |= cpu;
d |= (node & 0xf) << 12;
d |= (node >> 4) << 48;
write_gdt_entry(get_cpu_gdt_table(cpu), GDT_ENTRY_PER_CPU, &d, DESCTYPE_S);
}
static void __cpuinit cpu_vsyscall_init(void *arg)
{
vsyscall_set_cpu(raw_smp_processor_id());
}
static int __cpuinit
cpu_vsyscall_notifier(struct notifier_block *n, unsigned long action, void *arg)
{
long cpu = (long)arg;
if (action == CPU_ONLINE || action == CPU_ONLINE_FROZEN)
smp_call_function_single(cpu, cpu_vsyscall_init, NULL, 1);
return NOTIFY_DONE;
}
void __init map_vsyscall(void)
{
extern char __vsyscall_0;
unsigned long physaddr_page0 = __pa_symbol(&__vsyscall_0);
__set_fixmap(VSYSCALL_FIRST_PAGE, physaddr_page0, PAGE_KERNEL_VSYSCALL);
}
static int __init vsyscall_init(void)
{
BUG_ON(((unsigned long) &vgettimeofday !=
VSYSCALL_ADDR(__NR_vgettimeofday)));
BUG_ON((unsigned long) &vtime != VSYSCALL_ADDR(__NR_vtime));
BUG_ON((VSYSCALL_ADDR(0) != __fix_to_virt(VSYSCALL_FIRST_PAGE)));
BUG_ON((unsigned long) &vgetcpu != VSYSCALL_ADDR(__NR_vgetcpu));
#ifdef CONFIG_SYSCTL
register_sysctl_table(kernel_root_table2);
#endif
on_each_cpu(cpu_vsyscall_init, NULL, 1);
hotcpu_notifier(cpu_vsyscall_notifier, 30);
return 0;
}
