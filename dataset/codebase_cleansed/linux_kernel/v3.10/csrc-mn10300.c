static cycle_t mn10300_read(struct clocksource *cs)
{
return read_timestamp_counter();
}
int __init init_clocksource(void)
{
startup_timestamp_counter();
clocksource_register_hz(&clocksource_mn10300, MN10300_TSCCLK);
return 0;
}
