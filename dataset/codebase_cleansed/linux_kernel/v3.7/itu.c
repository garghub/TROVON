static irqreturn_t timer_interrupt(int irq, void *dev_id)
{
h8300_timer_tick();
ctrl_bclr(IMFA, ITUBASE + TSR);
return IRQ_HANDLED;
}
void __init h8300_timer_setup(void)
{
unsigned int div;
unsigned int cnt;
calc_param(cnt, div, divide_rate, 0x10000);
setup_irq(ITUIRQ, &itu_irq);
ctrl_outb(0, TSTR);
ctrl_outb(CCLR0 | div, ITUBASE + TCR);
ctrl_outb(0x01, ITUBASE + TIER);
ctrl_outw(cnt, ITUBASE + GRA);
ctrl_bset(CONFIG_H8300_ITU_CH, TSTR);
}
