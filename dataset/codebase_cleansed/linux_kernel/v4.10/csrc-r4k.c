static u64 c0_hpt_read(struct clocksource *cs)
{
return read_c0_count();
}
static u64 __maybe_unused notrace r4k_read_sched_clock(void)
{
return read_c0_count();
}
static inline unsigned int rdhwr_count(void)
{
unsigned int count;
__asm__ __volatile__(
" .set push\n"
" .set mips32r2\n"
" rdhwr %0, $2\n"
" .set pop\n"
: "=r" (count));
return count;
}
static bool rdhwr_count_usable(void)
{
unsigned int prev, curr, i;
for (i = 0, prev = rdhwr_count(); i < 100; i++) {
curr = rdhwr_count();
if (curr != prev)
return true;
prev = curr;
}
pr_warn("Not using R4K clocksource in VDSO due to broken RDHWR\n");
return false;
}
int __init init_r4k_clocksource(void)
{
if (!cpu_has_counter || !mips_hpt_frequency)
return -ENXIO;
clocksource_mips.rating = 200 + mips_hpt_frequency / 10000000;
if (cpu_has_mips_r2_r6 && rdhwr_count_usable())
clocksource_mips.archdata.vdso_clock_mode = VDSO_CLOCK_R4K;
clocksource_register_hz(&clocksource_mips, mips_hpt_frequency);
#ifndef CONFIG_CPU_FREQ
sched_clock_register(r4k_read_sched_clock, 32, mips_hpt_frequency);
#endif
return 0;
}
