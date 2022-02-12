static unsigned long arch_timer_read_counter_long(void)
{
return arch_timer_read_counter();
}
static u32 arch_timer_read_counter_u32(void)
{
return arch_timer_read_counter();
}
static void __init arch_timer_delay_timer_register(void)
{
arch_delay_timer.read_current_timer = arch_timer_read_counter_long;
arch_delay_timer.freq = arch_timer_get_rate();
register_current_timer_delay(&arch_delay_timer);
}
int __init arch_timer_of_register(void)
{
int ret;
ret = arch_timer_init();
if (ret)
return ret;
arch_timer_delay_timer_register();
return 0;
}
int __init arch_timer_sched_clock_init(void)
{
if (arch_timer_get_rate() == 0)
return -ENXIO;
setup_sched_clock(arch_timer_read_counter_u32,
32, arch_timer_get_rate());
return 0;
}
