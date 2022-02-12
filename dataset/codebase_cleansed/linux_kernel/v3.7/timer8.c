static irqreturn_t timer_interrupt(int irq, void *dev_id)
{
h8300_timer_tick();
ctrl_bclr(CMFA, _8BASE + _8TCSR);
return IRQ_HANDLED;
}
void __init h8300_timer_setup(void)
{
unsigned int div;
unsigned int cnt;
calc_param(cnt, div, divide_rate, 0x10000);
div++;
setup_irq(_8IRQ, &timer8_irq);
#if defined(CONFIG_CPU_H8S)
ctrl_bclr(0, MSTPCRL)
#endif
ctrl_outw(cnt, _8BASE + TCORA);
ctrl_outw(0x0000, _8BASE + _8TCSR);
ctrl_outw((CMIEA|CCLR_CMA|CKS2) << 8 | div,
_8BASE + _8TCR);
}
