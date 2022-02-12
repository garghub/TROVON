unsigned int irq_lookup(unsigned int irq)
{
return __raw_readl(INTACK) & 1 ? irq : NO_IRQ_IGNORE;
}
void irq_finish(unsigned int irq)
{
__raw_writel(irq2evt(irq), INTACKCLR);
}
static int __init shx3_irq_setup(void)
{
return register_intc_userimask(INTC_USERIMASK);
}
