int mxc_set_irq_fiq(unsigned int irq, unsigned int type)
{
struct irq_chip_generic *gc;
struct mxc_extra_irq *exirq;
int ret;
ret = -ENOSYS;
gc = irq_get_chip_data(irq);
if (gc && gc->private) {
exirq = gc->private;
if (exirq->set_irq_fiq) {
struct irq_data *d = irq_get_irq_data(irq);
ret = exirq->set_irq_fiq(irqd_to_hwirq(d), type);
}
}
return ret;
}
