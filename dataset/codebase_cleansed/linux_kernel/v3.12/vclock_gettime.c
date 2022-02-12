notrace static cycle_t vread_tsc(void)
{
cycle_t ret;
u64 last;
rdtsc_barrier();
ret = (cycle_t)vget_cycles();
last = VVAR(vsyscall_gtod_data).clock.cycle_last;
if (likely(ret >= last))
return ret;
asm volatile ("");
return last;
}
static notrace cycle_t vread_hpet(void)
{
return readl((const void __iomem *)fix_to_virt(VSYSCALL_HPET) + HPET_COUNTER);
}
static notrace cycle_t vread_pvclock(int *mode)
{
const struct pvclock_vsyscall_time_info *pvti;
cycle_t ret;
u64 last;
u32 version;
u8 flags;
unsigned cpu, cpu1;
do {
cpu = __getcpu() & VGETCPU_CPU_MASK;
pvti = get_pvti(cpu);
version = __pvclock_read_cycles(&pvti->pvti, &ret, &flags);
cpu1 = __getcpu() & VGETCPU_CPU_MASK;
} while (unlikely(cpu != cpu1 ||
(pvti->pvti.version & 1) ||
pvti->pvti.version != version));
if (unlikely(!(flags & PVCLOCK_TSC_STABLE_BIT)))
*mode = VCLOCK_NONE;
last = VVAR(vsyscall_gtod_data).clock.cycle_last;
if (likely(ret >= last))
return ret;
return last;
}
notrace static long vdso_fallback_gettime(long clock, struct timespec *ts)
{
long ret;
asm("syscall" : "=a" (ret) :
"0" (__NR_clock_gettime),"D" (clock), "S" (ts) : "memory");
return ret;
}
notrace static long vdso_fallback_gtod(struct timeval *tv, struct timezone *tz)
{
long ret;
asm("syscall" : "=a" (ret) :
"0" (__NR_gettimeofday), "D" (tv), "S" (tz) : "memory");
return ret;
}
notrace static inline u64 vgetsns(int *mode)
{
long v;
cycles_t cycles;
if (gtod->clock.vclock_mode == VCLOCK_TSC)
cycles = vread_tsc();
else if (gtod->clock.vclock_mode == VCLOCK_HPET)
cycles = vread_hpet();
#ifdef CONFIG_PARAVIRT_CLOCK
else if (gtod->clock.vclock_mode == VCLOCK_PVCLOCK)
cycles = vread_pvclock(mode);
#endif
else
return 0;
v = (cycles - gtod->clock.cycle_last) & gtod->clock.mask;
return v * gtod->clock.mult;
}
notrace static int __always_inline do_realtime(struct timespec *ts)
{
unsigned long seq;
u64 ns;
int mode;
ts->tv_nsec = 0;
do {
seq = read_seqcount_begin(&gtod->seq);
mode = gtod->clock.vclock_mode;
ts->tv_sec = gtod->wall_time_sec;
ns = gtod->wall_time_snsec;
ns += vgetsns(&mode);
ns >>= gtod->clock.shift;
} while (unlikely(read_seqcount_retry(&gtod->seq, seq)));
timespec_add_ns(ts, ns);
return mode;
}
notrace static int do_monotonic(struct timespec *ts)
{
unsigned long seq;
u64 ns;
int mode;
ts->tv_nsec = 0;
do {
seq = read_seqcount_begin(&gtod->seq);
mode = gtod->clock.vclock_mode;
ts->tv_sec = gtod->monotonic_time_sec;
ns = gtod->monotonic_time_snsec;
ns += vgetsns(&mode);
ns >>= gtod->clock.shift;
} while (unlikely(read_seqcount_retry(&gtod->seq, seq)));
timespec_add_ns(ts, ns);
return mode;
}
notrace static int do_realtime_coarse(struct timespec *ts)
{
unsigned long seq;
do {
seq = read_seqcount_begin(&gtod->seq);
ts->tv_sec = gtod->wall_time_coarse.tv_sec;
ts->tv_nsec = gtod->wall_time_coarse.tv_nsec;
} while (unlikely(read_seqcount_retry(&gtod->seq, seq)));
return 0;
}
notrace static int do_monotonic_coarse(struct timespec *ts)
{
unsigned long seq;
do {
seq = read_seqcount_begin(&gtod->seq);
ts->tv_sec = gtod->monotonic_time_coarse.tv_sec;
ts->tv_nsec = gtod->monotonic_time_coarse.tv_nsec;
} while (unlikely(read_seqcount_retry(&gtod->seq, seq)));
return 0;
}
notrace int __vdso_clock_gettime(clockid_t clock, struct timespec *ts)
{
int ret = VCLOCK_NONE;
switch (clock) {
case CLOCK_REALTIME:
ret = do_realtime(ts);
break;
case CLOCK_MONOTONIC:
ret = do_monotonic(ts);
break;
case CLOCK_REALTIME_COARSE:
return do_realtime_coarse(ts);
case CLOCK_MONOTONIC_COARSE:
return do_monotonic_coarse(ts);
}
if (ret == VCLOCK_NONE)
return vdso_fallback_gettime(clock, ts);
return 0;
}
notrace int __vdso_gettimeofday(struct timeval *tv, struct timezone *tz)
{
long ret = VCLOCK_NONE;
if (likely(tv != NULL)) {
BUILD_BUG_ON(offsetof(struct timeval, tv_usec) !=
offsetof(struct timespec, tv_nsec) ||
sizeof(*tv) != sizeof(struct timespec));
ret = do_realtime((struct timespec *)tv);
tv->tv_usec /= 1000;
}
if (unlikely(tz != NULL)) {
tz->tz_minuteswest = gtod->sys_tz.tz_minuteswest;
tz->tz_dsttime = gtod->sys_tz.tz_dsttime;
}
if (ret == VCLOCK_NONE)
return vdso_fallback_gtod(tv, tz);
return 0;
}
notrace time_t __vdso_time(time_t *t)
{
time_t result = ACCESS_ONCE(VVAR(vsyscall_gtod_data).wall_time_sec);
if (t)
*t = result;
return result;
}
