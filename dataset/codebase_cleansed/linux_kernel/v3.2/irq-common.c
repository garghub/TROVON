int imx_irq_set_priority(unsigned char irq, unsigned char prio)
{
struct irq_chip_generic *gc;
struct mxc_extra_irq *exirq;
int ret;
ret = -ENOSYS;
gc = irq_get_chip_data(irq);
if (gc && gc->private) {
exirq = gc->private;
if (exirq->set_priority)
ret = exirq->set_priority(irq, prio);
}
return ret;
}
int mxc_set_irq_fiq(unsigned int irq, unsigned int type)
{
struct irq_chip_generic *gc;
struct mxc_extra_irq *exirq;
int ret;
ret = -ENOSYS;
gc = irq_get_chip_data(irq);
if (gc && gc->private) {
exirq = gc->private;
if (exirq->set_irq_fiq)
ret = exirq->set_irq_fiq(irq, type);
}
return ret;
}
