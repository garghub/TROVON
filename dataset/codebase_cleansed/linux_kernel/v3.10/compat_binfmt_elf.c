static void cputime_to_compat_timeval(const cputime_t cputime,
struct compat_timeval *value)
{
struct timeval tv;
cputime_to_timeval(cputime, &tv);
value->tv_sec = tv.tv_sec;
value->tv_usec = tv.tv_usec;
}
