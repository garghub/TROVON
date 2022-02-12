static void ipi_resched_dispatch(void)
{
do_IRQ(MIPS_CPU_IPI_RESCHED_IRQ);
}
static void ipi_call_dispatch(void)
{
do_IRQ(MIPS_CPU_IPI_CALL_IRQ);
}
static irqreturn_t ipi_resched_interrupt(int irq, void *dev_id)
{
return IRQ_HANDLED;
}
static irqreturn_t ipi_call_interrupt(int irq, void *dev_id)
{
smp_call_function_interrupt();
return IRQ_HANDLED;
}
void __init arch_init_ipiirq(int irq, struct irqaction *action)
{
setup_irq(irq, action);
irq_set_handler(irq, handle_percpu_irq);
}
void __init msp_vsmp_int_init(void)
{
set_vi_handler(MIPS_CPU_IPI_RESCHED_IRQ, ipi_resched_dispatch);
set_vi_handler(MIPS_CPU_IPI_CALL_IRQ, ipi_call_dispatch);
arch_init_ipiirq(MIPS_CPU_IPI_RESCHED_IRQ, &irq_resched);
arch_init_ipiirq(MIPS_CPU_IPI_CALL_IRQ, &irq_call);
}
