static cycle_t bcm1480_hpt_read(struct clocksource *cs)
{
return (cycle_t) __raw_readq(IOADDR(A_SCD_ZBBUS_CYCLE_COUNT));
}
void __init sb1480_clocksource_init(void)
{
struct clocksource *cs = &bcm1480_clocksource;
unsigned int plldiv;
unsigned long zbbus;
plldiv = G_BCM1480_SYS_PLL_DIV(__raw_readq(IOADDR(A_SCD_SYSTEM_CFG)));
zbbus = ((plldiv >> 1) * 50000000) + ((plldiv & 1) * 25000000);
clocksource_register_hz(cs, zbbus);
}
