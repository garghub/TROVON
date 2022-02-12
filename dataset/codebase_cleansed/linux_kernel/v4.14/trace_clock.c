u64 notrace trace_clock_x86_tsc(void)
{
return rdtsc_ordered();
}
