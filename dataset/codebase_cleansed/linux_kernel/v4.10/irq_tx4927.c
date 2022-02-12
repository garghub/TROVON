void __init tx4927_irq_init(void)
{
int i;
mips_cpu_irq_init();
txx9_irq_init(TX4927_IRC_REG & 0xfffffffffULL);
irq_set_chained_handler(MIPS_CPU_IRQ_BASE + TX4927_IRC_INT,
handle_simple_irq);
txx9_irq_set_pri(TX4927_IR_ECCERR, 7);
txx9_irq_set_pri(TX4927_IR_WTOERR, 7);
txx9_irq_set_pri(TX4927_IR_PCIERR, 7);
txx9_irq_set_pri(TX4927_IR_PCIPME, 7);
for (i = 0; i < TX4927_NUM_IR_TMR; i++)
txx9_irq_set_pri(TX4927_IR_TMR(i), 6);
for (i = 0; i < TX4927_NUM_IR_SIO; i++)
txx9_irq_set_pri(TX4927_IR_SIO(i), 5);
}
