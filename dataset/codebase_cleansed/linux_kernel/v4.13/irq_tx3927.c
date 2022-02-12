void __init tx3927_irq_init(void)
{
int i;
txx9_irq_init(TX3927_IRC_REG);
for (i = 0; i < TX3927_NR_TMR; i++)
txx9_irq_set_pri(TX3927_IR_TMR(i), 6);
for (i = 0; i < TX3927_NR_SIO; i++)
txx9_irq_set_pri(TX3927_IR_SIO(i), 7);
}
