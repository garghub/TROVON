notrace cycle_t __vsyscall_fn vread_tsc(void)
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
