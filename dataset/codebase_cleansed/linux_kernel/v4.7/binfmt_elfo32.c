static inline void
jiffies_to_compat_timeval(unsigned long jiffies, struct compat_timeval *value)
{
u64 nsec = (u64)jiffies * TICK_NSEC;
u32 rem;
value->tv_sec = div_u64_rem(nsec, NSEC_PER_SEC, &rem);
value->tv_usec = rem / NSEC_PER_USEC;
}
static __inline__ void
cputime_to_compat_timeval(const cputime_t cputime, struct compat_timeval *value)
{
unsigned long jiffies = cputime_to_jiffies(cputime);
value->tv_usec = (jiffies % HZ) * (1000000L / HZ);
value->tv_sec = jiffies / HZ;
}
