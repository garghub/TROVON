int __vdso_clock_gettime(clockid_t clock, struct timespec *ts)
{
long ret;
asm("syscall" : "=a" (ret) :
"0" (__NR_clock_gettime), "D" (clock), "S" (ts) : "memory");
return ret;
}
int __vdso_gettimeofday(struct timeval *tv, struct timezone *tz)
{
long ret;
asm("syscall" : "=a" (ret) :
"0" (__NR_gettimeofday), "D" (tv), "S" (tz) : "memory");
return ret;
}
time_t __vdso_time(time_t *t)
{
long secs;
asm volatile("syscall"
: "=a" (secs)
: "0" (__NR_time), "D" (t) : "cc", "r11", "cx", "memory");
return secs;
}
long
__vdso_getcpu(unsigned *cpu, unsigned *node, struct getcpu_cache *unused)
{
if (cpu)
*cpu = 0;
if (node)
*node = 0;
return 0;
}
