static int xtensa_pic_irq_domain_xlate(struct irq_domain *d,
struct device_node *ctrlr,
const u32 *intspec, unsigned int intsize,
unsigned long *out_hwirq, unsigned int *out_type)
{
return xtensa_irq_domain_xlate(intspec, intsize,
intspec[0], intspec[0],
out_hwirq, out_type);
}
static void xtensa_irq_mask(struct irq_data *d)
{
cached_irq_mask &= ~(1 << d->hwirq);
set_sr(cached_irq_mask, intenable);
}
static void xtensa_irq_unmask(struct irq_data *d)
{
cached_irq_mask |= 1 << d->hwirq;
set_sr(cached_irq_mask, intenable);
}
static void xtensa_irq_enable(struct irq_data *d)
{
variant_irq_enable(d->hwirq);
xtensa_irq_unmask(d);
}
static void xtensa_irq_disable(struct irq_data *d)
{
xtensa_irq_mask(d);
variant_irq_disable(d->hwirq);
}
static void xtensa_irq_ack(struct irq_data *d)
{
set_sr(1 << d->hwirq, intclear);
}
static int xtensa_irq_retrigger(struct irq_data *d)
{
set_sr(1 << d->hwirq, intset);
return 1;
}
int __init xtensa_pic_init_legacy(struct device_node *interrupt_parent)
{
struct irq_domain *root_domain =
irq_domain_add_legacy(NULL, NR_IRQS, 0, 0,
&xtensa_irq_domain_ops, &xtensa_irq_chip);
irq_set_default_host(root_domain);
return 0;
}
static int __init xtensa_pic_init(struct device_node *np,
struct device_node *interrupt_parent)
{
struct irq_domain *root_domain =
irq_domain_add_linear(np, NR_IRQS, &xtensa_irq_domain_ops,
&xtensa_irq_chip);
irq_set_default_host(root_domain);
return 0;
}
