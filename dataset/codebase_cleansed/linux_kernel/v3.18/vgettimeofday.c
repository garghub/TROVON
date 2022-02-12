static inline cycles_t get_cycles_inline(void)
{
unsigned int high = __insn_mfspr(SPR_CYCLE_HIGH);
unsigned int low = __insn_mfspr(SPR_CYCLE_LOW);
unsigned int high2 = __insn_mfspr(SPR_CYCLE_HIGH);
while (unlikely(high != high2)) {
low = __insn_mfspr(SPR_CYCLE_LOW);
high = high2;
high2 = __insn_mfspr(SPR_CYCLE_HIGH);
}
return (((cycles_t)high) << 32) | low;
}
inline unsigned long get_datapage(void)
{
unsigned long ret;
asm volatile ("lnk %0" : "=r"(ret));
ret &= ~(PAGE_SIZE - 1);
ret += PAGE_SIZE;
return ret;
}
static inline u64 vgetsns(struct vdso_data *vdso)
{
return ((get_cycles() - vdso->cycle_last) & vdso->mask) * vdso->mult;
}
static inline int do_realtime(struct vdso_data *vdso, struct timespec *ts)
{
unsigned count;
u64 ns;
do {
count = read_seqcount_begin(&vdso->tb_seq);
ts->tv_sec = vdso->wall_time_sec;
ns = vdso->wall_time_snsec;
ns += vgetsns(vdso);
ns >>= vdso->shift;
} while (unlikely(read_seqcount_retry(&vdso->tb_seq, count)));
ts->tv_sec += __iter_div_u64_rem(ns, NSEC_PER_SEC, &ns);
ts->tv_nsec = ns;
return 0;
}
static inline int do_monotonic(struct vdso_data *vdso, struct timespec *ts)
{
unsigned count;
u64 ns;
do {
count = read_seqcount_begin(&vdso->tb_seq);
ts->tv_sec = vdso->monotonic_time_sec;
ns = vdso->monotonic_time_snsec;
ns += vgetsns(vdso);
ns >>= vdso->shift;
} while (unlikely(read_seqcount_retry(&vdso->tb_seq, count)));
ts->tv_sec += __iter_div_u64_rem(ns, NSEC_PER_SEC, &ns);
ts->tv_nsec = ns;
return 0;
}
static inline int do_realtime_coarse(struct vdso_data *vdso,
struct timespec *ts)
{
unsigned count;
do {
count = read_seqcount_begin(&vdso->tb_seq);
ts->tv_sec = vdso->wall_time_coarse_sec;
ts->tv_nsec = vdso->wall_time_coarse_nsec;
} while (unlikely(read_seqcount_retry(&vdso->tb_seq, count)));
return 0;
}
static inline int do_monotonic_coarse(struct vdso_data *vdso,
struct timespec *ts)
{
unsigned count;
do {
count = read_seqcount_begin(&vdso->tb_seq);
ts->tv_sec = vdso->monotonic_time_coarse_sec;
ts->tv_nsec = vdso->monotonic_time_coarse_nsec;
} while (unlikely(read_seqcount_retry(&vdso->tb_seq, count)));
return 0;
}
struct syscall_return_value __vdso_gettimeofday(struct timeval *tv,
struct timezone *tz)
{
struct syscall_return_value ret = { 0, 0 };
unsigned count;
struct vdso_data *vdso = (struct vdso_data *)get_datapage();
if (unlikely(tz != NULL)) {
do {
count = read_seqcount_begin(&vdso->tz_seq);
tz->tz_minuteswest = vdso->tz_minuteswest;
tz->tz_dsttime = vdso->tz_dsttime;
} while (unlikely(read_seqcount_retry(&vdso->tz_seq, count)));
}
if (unlikely(tv == NULL))
return ret;
do_realtime(vdso, (struct timespec *)tv);
tv->tv_usec /= 1000;
return ret;
}
static struct syscall_return_value vdso_fallback_gettime(long clock,
struct timespec *ts)
{
struct syscall_return_value ret;
__asm__ __volatile__ (
"swint1"
: "=R00" (ret.value), "=R01" (ret.error)
: "R10" (__NR_clock_gettime), "R00" (clock), "R01" (ts)
: "r2", "r3", "r4", "r5", "r6", "r7",
"r8", "r9", "r11", "r12", "r13", "r14", "r15",
"r16", "r17", "r18", "r19", "r20", "r21", "r22", "r23",
"r24", "r25", "r26", "r27", "r28", "r29", "memory");
return ret;
}
struct syscall_return_value __vdso_clock_gettime(clockid_t clock,
struct timespec *ts)
{
struct vdso_data *vdso = (struct vdso_data *)get_datapage();
struct syscall_return_value ret = { 0, 0 };
switch (clock) {
case CLOCK_REALTIME:
do_realtime(vdso, ts);
return ret;
case CLOCK_MONOTONIC:
do_monotonic(vdso, ts);
return ret;
case CLOCK_REALTIME_COARSE:
do_realtime_coarse(vdso, ts);
return ret;
case CLOCK_MONOTONIC_COARSE:
do_monotonic_coarse(vdso, ts);
return ret;
default:
return vdso_fallback_gettime(clock, ts);
}
}
