int imx_irq_set_priority(unsigned char irq, unsigned char prio)
{
struct mxc_irq_chip *chip;
struct irq_chip *base;
int ret;
ret = -ENOSYS;
base = irq_get_chip(irq);
if (base) {
chip = container_of(base, struct mxc_irq_chip, base);
if (chip->set_priority)
ret = chip->set_priority(irq, prio);
}
return ret;
}
int mxc_set_irq_fiq(unsigned int irq, unsigned int type)
{
struct irq_chip_generic *gc;
int (*set_irq_fiq)(unsigned int, unsigned int);
int ret;
ret = -ENOSYS;
gc = irq_get_chip_data(irq);
if (gc && gc->private) {
set_irq_fiq = gc->private;
ret = set_irq_fiq(irq, type);
}
return ret;
}
