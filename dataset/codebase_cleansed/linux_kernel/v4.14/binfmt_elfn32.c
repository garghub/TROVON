static __inline__ void
jiffies_to_compat_timeval(unsigned long jiffies, struct compat_timeval *value)
{
u64 nsec = (u64)jiffies * TICK_NSEC;
u32 rem;
value->tv_sec = div_u64_rem(nsec, NSEC_PER_SEC, &rem);
value->tv_usec = rem / NSEC_PER_USEC;
}
