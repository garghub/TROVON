static cycle_t c0_hpt_read(struct clocksource *cs)
{
return read_c0_count();
}
int __init init_r4k_clocksource(void)
{
if (!cpu_has_counter || !mips_hpt_frequency)
return -ENXIO;
clocksource_mips.rating = 200 + mips_hpt_frequency / 10000000;
clocksource_register_hz(&clocksource_mips, mips_hpt_frequency);
return 0;
}
