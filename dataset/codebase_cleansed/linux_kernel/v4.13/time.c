void
cris_do_profile(struct pt_regs* regs)
{
#ifdef CONFIG_SYSTEM_PROFILER
cris_profile_sample(regs);
#endif
#ifdef CONFIG_PROFILING
profile_tick(CPU_PROFILING);
#endif
}
unsigned long long sched_clock(void)
{
return (unsigned long long)jiffies * (NSEC_PER_SEC / HZ) +
get_ns_in_jiffie();
}
static int
__init init_udelay(void)
{
loops_per_usec = (loops_per_jiffy * HZ) / 1000000;
return 0;
}
