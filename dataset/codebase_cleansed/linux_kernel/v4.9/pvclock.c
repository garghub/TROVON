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
void pvclock_touch_watchdogs(void)
{
touch_softlockup_watchdog_sync();
clocksource_touch_watchdog();
rcu_cpu_stall_reset();
reset_hung_task_detector();
}
void pvclock_resume(void)
{
atomic64_set(&last_value, 0);
}
u8 pvclock_read_flags(struct pvclock_vcpu_time_info *src)
{
unsigned version;
u8 flags;
do {
version = pvclock_read_begin(src);
flags = src->flags;
} while (pvclock_read_retry(src, version));
return flags & valid_flags;
}
cycle_t pvclock_clocksource_read(struct pvclock_vcpu_time_info *src)
{
unsigned version;
cycle_t ret;
u64 last;
u8 flags;
do {
version = pvclock_read_begin(src);
ret = __pvclock_read_cycles(src, rdtsc_ordered());
flags = src->flags;
} while (pvclock_read_retry(src, version));
if (unlikely((flags & PVCLOCK_GUEST_STOPPED) != 0)) {
src->flags &= ~PVCLOCK_GUEST_STOPPED;
pvclock_touch_watchdogs();
}
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
