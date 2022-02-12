int clk_enable(struct clk *clk)
{
return 0;
}
void clk_disable(struct clk *clk)
{
}
unsigned long clk_get_rate(struct clk *clk)
{
return AT91X40_MASTER_CLOCK;
}
static void at91x40_idle(void)
{
__raw_writel(AT91_PS_CR_CPU, AT91_IO_P2V(AT91_PS_CR));
cpu_do_idle();
}
void __init at91x40_initialize(unsigned long main_clock)
{
arm_pm_idle = at91x40_idle;
at91_extern_irq = (1 << AT91X40_ID_IRQ0) | (1 << AT91X40_ID_IRQ1)
| (1 << AT91X40_ID_IRQ2);
}
void __init at91x40_init_interrupts(unsigned int priority[NR_AIC_IRQS])
{
if (!priority)
priority = at91x40_default_irq_priority;
at91_aic_init(priority, at91_extern_irq);
}
