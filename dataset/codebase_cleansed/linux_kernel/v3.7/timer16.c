static irqreturn_t timer_interrupt(int irq, void *dev_id)
{
h8300_timer_tick();
ctrl_bclr(CONFIG_H8300_TIMER16_CH, TISRA);
return IRQ_HANDLED;
}
void __init h8300_timer_setup(void)
{
unsigned int div;
unsigned int cnt;
calc_param(cnt, div, divide_rate, 0x10000);
setup_irq(_16IRQ, &timer16_irq);
ctrl_outb(0, TSTR);
ctrl_outb(CCLR0 | div, _16BASE + TCR);
ctrl_outw(cnt, _16BASE + GRA);
ctrl_bset(4 + CONFIG_H8300_TIMER16_CH, TISRA);
ctrl_bset(CONFIG_H8300_TIMER16_CH, TSTR);
}
