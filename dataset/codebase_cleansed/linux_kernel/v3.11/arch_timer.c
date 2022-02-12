static unsigned long arch_timer_read_counter_long(void)
{
return arch_timer_read_counter();
}
static unsigned long long notrace arch_timer_sched_clock(void)
{
return arch_timer_read_counter() * sched_clock_mult;
}
static void __init arch_timer_delay_timer_register(void)
{
arch_delay_timer.read_current_timer = arch_timer_read_counter_long;
arch_delay_timer.freq = arch_timer_get_rate();
register_current_timer_delay(&arch_delay_timer);
}
int __init arch_timer_arch_init(void)
{
u32 arch_timer_rate = arch_timer_get_rate();
if (arch_timer_rate == 0)
return -ENXIO;
arch_timer_delay_timer_register();
sched_clock_mult = NSEC_PER_SEC / arch_timer_rate;
sched_clock_func = arch_timer_sched_clock;
pr_info("sched_clock: ARM arch timer >56 bits at %ukHz, resolution %uns\n",
arch_timer_rate / 1000, sched_clock_mult);
return 0;
}
