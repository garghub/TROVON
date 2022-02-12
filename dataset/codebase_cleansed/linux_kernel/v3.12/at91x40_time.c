static u32 at91x40_gettimeoffset(void)
{
return (at91_tc_read(AT91_TC_CLK1BASE + AT91_TC_CV) * 1000000 /
(AT91X40_MASTER_CLOCK / 128)) * 1000;
}
static irqreturn_t at91x40_timer_interrupt(int irq, void *dev_id)
{
at91_tc_read(AT91_TC_CLK1BASE + AT91_TC_SR);
timer_tick();
return IRQ_HANDLED;
}
void __init at91x40_timer_init(void)
{
unsigned int v;
arch_gettimeoffset = at91x40_gettimeoffset;
at91_tc_write(AT91_TC_BCR, 0);
v = at91_tc_read(AT91_TC_BMR);
v = (v & ~AT91_TC_TC1XC1S) | AT91_TC_TC1XC1S_NONE;
at91_tc_write(AT91_TC_BMR, v);
at91_tc_write(AT91_TC_CLK1BASE + AT91_TC_CCR, AT91_TC_CLKDIS);
at91_tc_write(AT91_TC_CLK1BASE + AT91_TC_CMR, (AT91_TC_TIMER_CLOCK4 | AT91_TC_CPCTRG));
at91_tc_write(AT91_TC_CLK1BASE + AT91_TC_IDR, 0xffffffff);
at91_tc_write(AT91_TC_CLK1BASE + AT91_TC_RC, (AT91X40_MASTER_CLOCK / 128) / HZ - 1);
at91_tc_write(AT91_TC_CLK1BASE + AT91_TC_IER, (1<<4));
setup_irq(AT91X40_ID_TC1, &at91x40_timer_irq);
at91_tc_write(AT91_TC_CLK1BASE + AT91_TC_CCR, (AT91_TC_SWTRG | AT91_TC_CLKEN));
}
