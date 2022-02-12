static unsigned long arch_timer_read_counter_long(void)
{
return arch_timer_read_counter();
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
return 0;
}
