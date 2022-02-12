void pvclock_set_flags(u8 flags)
{
valid_flags = flags;
}
unsigned long pvclock_tsc_khz(struct pvclock_vcpu_time_info *src)
{
u64 pv_tsc_khz = 1000000ULL << 32;
do_div(pv_tsc_khz, src->tsc_to_system_mul);
if (src->tsc_shift < 0)
pv_tsc_khz <<= -src->tsc_shift;
else
pv_tsc_khz >>= src->tsc_shift;
return pv_tsc_khz;
}
void pvclock_resume(void)
{
atomic64_set(&last_value, 0);
}
u8 pvclock_read_flags(struct pvclock_vcpu_time_info *src)
{
unsigned version;
cycle_t ret;
u8 flags;
do {
version = __pvclock_read_cycles(src, &ret, &flags);
} while ((src->version & 1) || version != src->version);
return flags & valid_flags;
}
cycle_t pvclock_clocksource_read(struct pvclock_vcpu_time_info *src)
{
unsigned version;
cycle_t ret;
u64 last;
u8 flags;
do {
version = __pvclock_read_cycles(src, &ret, &flags);
} while ((src->version & 1) || version != src->version);
if ((valid_flags & PVCLOCK_TSC_STABLE_BIT) &&
(flags & PVCLOCK_TSC_STABLE_BIT))
return ret;
last = atomic64_read(&last_value);
do {
if (ret < last)
return last;
last = atomic64_cmpxchg(&last_value, last, ret);
} while (unlikely(last != ret));
return ret;
}
void pvclock_read_wallclock(struct pvclock_wall_clock *wall_clock,
struct pvclock_vcpu_time_info *vcpu_time,
struct timespec *ts)
{
u32 version;
u64 delta;
struct timespec now;
do {
version = wall_clock->version;
rmb();
now.tv_sec = wall_clock->sec;
now.tv_nsec = wall_clock->nsec;
rmb();
} while ((wall_clock->version & 1) || (version != wall_clock->version));
delta = pvclock_clocksource_read(vcpu_time);
delta += now.tv_sec * (u64)NSEC_PER_SEC + now.tv_nsec;
now.tv_nsec = do_div(delta, NSEC_PER_SEC);
now.tv_sec = delta;
set_normalized_timespec(ts, now.tv_sec, now.tv_nsec);
}
static struct pvclock_vsyscall_time_info *
pvclock_get_vsyscall_user_time_info(int cpu)
{
if (!pvclock_vdso_info) {
BUG();
return NULL;
}
return &pvclock_vdso_info[cpu];
}
struct pvclock_vcpu_time_info *pvclock_get_vsyscall_time_info(int cpu)
{
return &pvclock_get_vsyscall_user_time_info(cpu)->pvti;
}
static int pvclock_task_migrate(struct notifier_block *nb, unsigned long l,
void *v)
{
struct task_migration_notifier *mn = v;
struct pvclock_vsyscall_time_info *pvti;
pvti = pvclock_get_vsyscall_user_time_info(mn->from_cpu);
if (unlikely(pvti == NULL))
return NOTIFY_DONE;
pvti->migrate_count++;
return NOTIFY_DONE;
}
int __init pvclock_init_vsyscall(struct pvclock_vsyscall_time_info *i,
int size)
{
int idx;
WARN_ON (size != PVCLOCK_VSYSCALL_NR_PAGES*PAGE_SIZE);
pvclock_vdso_info = i;
for (idx = 0; idx <= (PVCLOCK_FIXMAP_END-PVCLOCK_FIXMAP_BEGIN); idx++) {
__set_fixmap(PVCLOCK_FIXMAP_BEGIN + idx,
__pa(i) + (idx*PAGE_SIZE),
PAGE_KERNEL_VVAR);
}
register_task_migration_notifier(&pvclock_migrate);
return 0;
}
