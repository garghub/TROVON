static cycle_t sb1250_hpt_read(struct clocksource *cs)
{
unsigned int count;
count = G_SCD_TIMER_CNT(__raw_readq(IOADDR(A_SCD_TIMER_REGISTER(SB1250_HPT_NUM, R_SCD_TIMER_CNT))));
return SB1250_HPT_VALUE - count;
}
void __init sb1250_clocksource_init(void)
{
struct clocksource *cs = &bcm1250_clocksource;
__raw_writeq(0,
IOADDR(A_SCD_TIMER_REGISTER(SB1250_HPT_NUM,
R_SCD_TIMER_CFG)));
__raw_writeq(SB1250_HPT_VALUE,
IOADDR(A_SCD_TIMER_REGISTER(SB1250_HPT_NUM,
R_SCD_TIMER_INIT)));
__raw_writeq(M_SCD_TIMER_ENABLE | M_SCD_TIMER_MODE_CONTINUOUS,
IOADDR(A_SCD_TIMER_REGISTER(SB1250_HPT_NUM,
R_SCD_TIMER_CFG)));
clocksource_register_hz(cs, V_SCD_TIMER_FREQ);
}
