notrace static long vdso_fallback_gettime(long clock, struct timespec *ts)
{
long ret;
asm("syscall" : "=a" (ret) :
"0" (__NR_clock_gettime),"D" (clock), "S" (ts) : "memory");
return ret;
}
notrace static inline long vgetns(void)
{
long v;
cycles_t (*vread)(void);
vread = gtod->clock.vread;
v = (vread() - gtod->clock.cycle_last) & gtod->clock.mask;
return (v * gtod->clock.mult) >> gtod->clock.shift;
}
notrace static noinline int do_realtime(struct timespec *ts)
{
unsigned long seq, ns;
do {
seq = read_seqbegin(&gtod->lock);
ts->tv_sec = gtod->wall_time_sec;
ts->tv_nsec = gtod->wall_time_nsec;
ns = vgetns();
} while (unlikely(read_seqretry(&gtod->lock, seq)));
timespec_add_ns(ts, ns);
return 0;
}
notrace static noinline int do_monotonic(struct timespec *ts)
{
unsigned long seq, ns, secs;
do {
seq = read_seqbegin(&gtod->lock);
secs = gtod->wall_time_sec;
ns = gtod->wall_time_nsec + vgetns();
secs += gtod->wall_to_monotonic.tv_sec;
ns += gtod->wall_to_monotonic.tv_nsec;
} while (unlikely(read_seqretry(&gtod->lock, seq)));
while (ns >= NSEC_PER_SEC) {
ns -= NSEC_PER_SEC;
++secs;
}
ts->tv_sec = secs;
ts->tv_nsec = ns;
return 0;
}
notrace static noinline int do_realtime_coarse(struct timespec *ts)
{
unsigned long seq;
do {
seq = read_seqbegin(&gtod->lock);
ts->tv_sec = gtod->wall_time_coarse.tv_sec;
ts->tv_nsec = gtod->wall_time_coarse.tv_nsec;
} while (unlikely(read_seqretry(&gtod->lock, seq)));
return 0;
}
notrace static noinline int do_monotonic_coarse(struct timespec *ts)
{
unsigned long seq, ns, secs;
do {
seq = read_seqbegin(&gtod->lock);
secs = gtod->wall_time_coarse.tv_sec;
ns = gtod->wall_time_coarse.tv_nsec;
secs += gtod->wall_to_monotonic.tv_sec;
ns += gtod->wall_to_monotonic.tv_nsec;
} while (unlikely(read_seqretry(&gtod->lock, seq)));
if (ns >= NSEC_PER_SEC) {
ns -= NSEC_PER_SEC;
++secs;
}
ts->tv_sec = secs;
ts->tv_nsec = ns;
return 0;
}
notrace int __vdso_clock_gettime(clockid_t clock, struct timespec *ts)
{
if (likely(gtod->sysctl_enabled))
switch (clock) {
case CLOCK_REALTIME:
if (likely(gtod->clock.vread))
return do_realtime(ts);
break;
case CLOCK_MONOTONIC:
if (likely(gtod->clock.vread))
return do_monotonic(ts);
break;
case CLOCK_REALTIME_COARSE:
return do_realtime_coarse(ts);
case CLOCK_MONOTONIC_COARSE:
return do_monotonic_coarse(ts);
}
return vdso_fallback_gettime(clock, ts);
}
notrace int __vdso_gettimeofday(struct timeval *tv, struct timezone *tz)
{
long ret;
if (likely(gtod->sysctl_enabled && gtod->clock.vread)) {
if (likely(tv != NULL)) {
BUILD_BUG_ON(offsetof(struct timeval, tv_usec) !=
offsetof(struct timespec, tv_nsec) ||
sizeof(*tv) != sizeof(struct timespec));
do_realtime((struct timespec *)tv);
tv->tv_usec /= 1000;
}
if (unlikely(tz != NULL)) {
tz->tz_minuteswest = gtod->sys_tz.tz_minuteswest;
tz->tz_dsttime = gtod->sys_tz.tz_dsttime;
}
return 0;
}
asm("syscall" : "=a" (ret) :
"0" (__NR_gettimeofday), "D" (tv), "S" (tz) : "memory");
return ret;
}
static __always_inline long time_syscall(long *t)
{
long secs;
asm volatile("syscall"
: "=a" (secs)
: "0" (__NR_time), "D" (t) : "cc", "r11", "cx", "memory");
return secs;
}
notrace time_t __vdso_time(time_t *t)
{
time_t result;
if (unlikely(!VVAR(vsyscall_gtod_data).sysctl_enabled))
return time_syscall(t);
result = ACCESS_ONCE(VVAR(vsyscall_gtod_data).wall_time_sec);
if (t)
*t = result;
return result;
}
