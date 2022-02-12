static irqreturn_t timer_interrupt(int irq, void *dev_id)
{
h8300_timer_tick();
ctrl_bclr(0, TPUBASE + _TSR);
return IRQ_HANDLED;
}
void __init h8300_timer_setup(void)
{
unsigned int cnt;
unsigned int div;
calc_param(cnt, div, divide_rate, 0x10000);
setup_irq(TPUIRQ, &tpu_irq);
ctrl_bclr(3, MSTPCRH);
ctrl_outb(0, TSTR);
ctrl_outb(CCLR0 | div, TPUBASE + _TCR);
ctrl_outb(0, TPUBASE + _TMDR);
ctrl_outw(0, TPUBASE + _TIOR);
ctrl_outb(0x01, TPUBASE + _TIER);
ctrl_outw(cnt, TPUBASE + _GRA);
ctrl_bset(CONFIG_H8300_TPU_CH, TSTR);
}
