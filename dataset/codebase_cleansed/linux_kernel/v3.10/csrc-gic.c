static cycle_t gic_hpt_read(struct clocksource *cs)
{
return gic_read_count();
}
void __init gic_clocksource_init(unsigned int frequency)
{
unsigned int config, bits;
GICREAD(GIC_REG(SHARED, GIC_SH_CONFIG), config);
bits = 32 + ((config & GIC_SH_CONFIG_COUNTBITS_MSK) >>
(GIC_SH_CONFIG_COUNTBITS_SHF - 2));
gic_clocksource.mask = CLOCKSOURCE_MASK(bits);
gic_clocksource.rating = 200 + frequency / 10000000;
clocksource_register_hz(&gic_clocksource, frequency);
}
