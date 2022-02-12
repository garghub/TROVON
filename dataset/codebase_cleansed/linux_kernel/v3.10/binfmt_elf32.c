static __inline__ void
cputime_to_compat_timeval(const cputime_t cputime, struct compat_timeval *value)
{
unsigned long jiffies = cputime_to_jiffies(cputime);
value->tv_usec = (jiffies % HZ) * (1000000L / HZ);
value->tv_sec = jiffies / HZ;
}
