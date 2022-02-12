static void
h7202_timerx_demux_handler(unsigned int irq_unused, struct irq_desc *desc)
{
unsigned int mask, irq;
mask = CPU_REG (TIMER_VIRT, TIMER_TOPSTAT);
if ( mask & TSTAT_T0INT ) {
timer_tick();
if( mask == TSTAT_T0INT )
return;
}
mask >>= 1;
irq = IRQ_TIMER1;
while (mask) {
if (mask & 1)
generic_handle_irq(irq);
irq++;
mask >>= 1;
}
}
static irqreturn_t
h7202_timer_interrupt(int irq, void *dev_id)
{
h7202_timerx_demux_handler(0, NULL);
return IRQ_HANDLED;
}
static void inline __mask_timerx_irq(unsigned int irq)
{
unsigned int bit;
bit = 2 << ((irq == IRQ_TIMER64B) ? 4 : (irq - IRQ_TIMER1));
CPU_REG (TIMER_VIRT, TIMER_TOPCTRL) &= ~bit;
}
static void inline mask_timerx_irq(struct irq_data *d)
{
__mask_timerx_irq(d->irq);
}
static void inline unmask_timerx_irq(struct irq_data *d)
{
unsigned int bit;
bit = 2 << ((d->irq == IRQ_TIMER64B) ? 4 : (d->irq - IRQ_TIMER1));
CPU_REG (TIMER_VIRT, TIMER_TOPCTRL) |= bit;
}
void __init h7202_init_time(void)
{
CPU_REG (TIMER_VIRT, TM0_PERIOD) = LATCH;
CPU_REG (TIMER_VIRT, TM0_CTRL) = TM_RESET;
CPU_REG (TIMER_VIRT, TM0_CTRL) = TM_REPEAT | TM_START;
CPU_REG (TIMER_VIRT, TIMER_TOPCTRL) = ENABLE_TM0_INTR | TIMER_ENABLE_BIT;
setup_irq(IRQ_TIMER0, &h7202_timer_irq);
}
void __init h7202_init_irq (void)
{
int irq;
CPU_REG (GPIO_E_VIRT, GPIO_MASK) = 0x0;
for (irq = IRQ_TIMER1;
irq < IRQ_CHAINED_TIMERX(NR_TIMERX_IRQS); irq++) {
__mask_timerx_irq(irq);
irq_set_chip_and_handler(irq, &h7202_timerx_chip,
handle_edge_irq);
set_irq_flags(irq, IRQF_VALID );
}
irq_set_chained_handler(IRQ_TIMERX, h7202_timerx_demux_handler);
h720x_init_irq();
}
void __init init_hw_h7202(void)
{
CPU_REG (PMU_BASE, PMU_PLL_CTRL) |= PLL_2_EN | PLL_1_EN | PLL_3_MUTE;
CPU_REG (SERIAL0_VIRT, SERIAL_ENABLE) = SERIAL_ENABLE_EN;
CPU_REG (SERIAL1_VIRT, SERIAL_ENABLE) = SERIAL_ENABLE_EN;
#ifdef CONFIG_H7202_SERIAL23
CPU_REG (SERIAL2_VIRT, SERIAL_ENABLE) = SERIAL_ENABLE_EN;
CPU_REG (SERIAL3_VIRT, SERIAL_ENABLE) = SERIAL_ENABLE_EN;
CPU_IO (GPIO_AMULSEL) = AMULSEL_USIN2 | AMULSEL_USOUT2 |
AMULSEL_USIN3 | AMULSEL_USOUT3;
#endif
(void) platform_add_devices(devices, ARRAY_SIZE(devices));
}
