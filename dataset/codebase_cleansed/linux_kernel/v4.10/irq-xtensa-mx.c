static int xtensa_mx_irq_map(struct irq_domain *d, unsigned int irq,
irq_hw_number_t hw)
{
if (hw < HW_IRQ_IPI_COUNT) {
struct irq_chip *irq_chip = d->host_data;
irq_set_chip_and_handler_name(irq, irq_chip,
handle_percpu_irq, "ipi");
irq_set_status_flags(irq, IRQ_LEVEL);
return 0;
}
return xtensa_irq_map(d, irq, hw);
}
static int xtensa_mx_irq_domain_xlate(struct irq_domain *d,
struct device_node *ctrlr,
const u32 *intspec, unsigned int intsize,
unsigned long *out_hwirq, unsigned int *out_type)
{
return xtensa_irq_domain_xlate(intspec, intsize,
intspec[0], intspec[0] + HW_IRQ_EXTERN_BASE,
out_hwirq, out_type);
}
void secondary_init_irq(void)
{
__this_cpu_write(cached_irq_mask,
XCHAL_INTTYPE_MASK_EXTERN_EDGE |
XCHAL_INTTYPE_MASK_EXTERN_LEVEL);
set_sr(XCHAL_INTTYPE_MASK_EXTERN_EDGE |
XCHAL_INTTYPE_MASK_EXTERN_LEVEL, intenable);
}
static void xtensa_mx_irq_mask(struct irq_data *d)
{
unsigned int mask = 1u << d->hwirq;
if (mask & (XCHAL_INTTYPE_MASK_EXTERN_EDGE |
XCHAL_INTTYPE_MASK_EXTERN_LEVEL)) {
set_er(1u << (xtensa_get_ext_irq_no(d->hwirq) -
HW_IRQ_MX_BASE), MIENG);
} else {
mask = __this_cpu_read(cached_irq_mask) & ~mask;
__this_cpu_write(cached_irq_mask, mask);
set_sr(mask, intenable);
}
}
static void xtensa_mx_irq_unmask(struct irq_data *d)
{
unsigned int mask = 1u << d->hwirq;
if (mask & (XCHAL_INTTYPE_MASK_EXTERN_EDGE |
XCHAL_INTTYPE_MASK_EXTERN_LEVEL)) {
set_er(1u << (xtensa_get_ext_irq_no(d->hwirq) -
HW_IRQ_MX_BASE), MIENGSET);
} else {
mask |= __this_cpu_read(cached_irq_mask);
__this_cpu_write(cached_irq_mask, mask);
set_sr(mask, intenable);
}
}
static void xtensa_mx_irq_enable(struct irq_data *d)
{
variant_irq_enable(d->hwirq);
xtensa_mx_irq_unmask(d);
}
static void xtensa_mx_irq_disable(struct irq_data *d)
{
xtensa_mx_irq_mask(d);
variant_irq_disable(d->hwirq);
}
static void xtensa_mx_irq_ack(struct irq_data *d)
{
set_sr(1 << d->hwirq, intclear);
}
static int xtensa_mx_irq_retrigger(struct irq_data *d)
{
set_sr(1 << d->hwirq, intset);
return 1;
}
static int xtensa_mx_irq_set_affinity(struct irq_data *d,
const struct cpumask *dest, bool force)
{
unsigned mask = 1u << cpumask_any_and(dest, cpu_online_mask);
set_er(mask, MIROUT(d->hwirq - HW_IRQ_MX_BASE));
return 0;
}
int __init xtensa_mx_init_legacy(struct device_node *interrupt_parent)
{
struct irq_domain *root_domain =
irq_domain_add_legacy(NULL, NR_IRQS, 0, 0,
&xtensa_mx_irq_domain_ops,
&xtensa_mx_irq_chip);
irq_set_default_host(root_domain);
secondary_init_irq();
return 0;
}
static int __init xtensa_mx_init(struct device_node *np,
struct device_node *interrupt_parent)
{
struct irq_domain *root_domain =
irq_domain_add_linear(np, NR_IRQS, &xtensa_mx_irq_domain_ops,
&xtensa_mx_irq_chip);
irq_set_default_host(root_domain);
secondary_init_irq();
return 0;
}
