static irqreturn_t
h7201_timer_interrupt(int irq, void *dev_id)
{
CPU_REG (TIMER_VIRT, TIMER_TOPSTAT);
timer_tick();
return IRQ_HANDLED;
}
void __init h7201_timer_init(void)
{
arch_gettimeoffset = h720x_gettimeoffset;
CPU_REG (TIMER_VIRT, TM0_PERIOD) = LATCH;
CPU_REG (TIMER_VIRT, TM0_CTRL) = TM_RESET;
CPU_REG (TIMER_VIRT, TM0_CTRL) = TM_REPEAT | TM_START;
CPU_REG (TIMER_VIRT, TIMER_TOPCTRL) = ENABLE_TM0_INTR | TIMER_ENABLE_BIT;
setup_irq(IRQ_TIMER0, &h7201_timer_irq);
}
