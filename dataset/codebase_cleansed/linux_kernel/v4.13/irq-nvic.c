asmlinkage void __exception_irq_entry
nvic_handle_irq(irq_hw_number_t hwirq, struct pt_regs *regs)
{
unsigned int irq = irq_linear_revmap(nvic_irq_domain, hwirq);
handle_IRQ(irq, regs);
}
static int nvic_irq_domain_translate(struct irq_domain *d,
struct irq_fwspec *fwspec,
unsigned long *hwirq, unsigned int *type)
{
if (WARN_ON(fwspec->param_count < 1))
return -EINVAL;
*hwirq = fwspec->param[0];
*type = IRQ_TYPE_NONE;
return 0;
}
static int nvic_irq_domain_alloc(struct irq_domain *domain, unsigned int virq,
unsigned int nr_irqs, void *arg)
{
int i, ret;
irq_hw_number_t hwirq;
unsigned int type = IRQ_TYPE_NONE;
struct irq_fwspec *fwspec = arg;
ret = nvic_irq_domain_translate(domain, fwspec, &hwirq, &type);
if (ret)
return ret;
for (i = 0; i < nr_irqs; i++)
irq_map_generic_chip(domain, virq + i, hwirq + i);
return 0;
}
static int __init nvic_of_init(struct device_node *node,
struct device_node *parent)
{
unsigned int clr = IRQ_NOREQUEST | IRQ_NOPROBE | IRQ_NOAUTOEN;
unsigned int irqs, i, ret, numbanks;
void __iomem *nvic_base;
numbanks = (readl_relaxed(V7M_SCS_ICTR) &
V7M_SCS_ICTR_INTLINESNUM_MASK) + 1;
nvic_base = of_iomap(node, 0);
if (!nvic_base) {
pr_warn("unable to map nvic registers\n");
return -ENOMEM;
}
irqs = numbanks * 32;
if (irqs > NVIC_MAX_IRQ)
irqs = NVIC_MAX_IRQ;
nvic_irq_domain =
irq_domain_add_linear(node, irqs, &nvic_irq_domain_ops, NULL);
if (!nvic_irq_domain) {
pr_warn("Failed to allocate irq domain\n");
return -ENOMEM;
}
ret = irq_alloc_domain_generic_chips(nvic_irq_domain, 32, 1,
"nvic_irq", handle_fasteoi_irq,
clr, 0, IRQ_GC_INIT_MASK_CACHE);
if (ret) {
pr_warn("Failed to allocate irq chips\n");
irq_domain_remove(nvic_irq_domain);
return ret;
}
for (i = 0; i < numbanks; ++i) {
struct irq_chip_generic *gc;
gc = irq_get_domain_generic_chip(nvic_irq_domain, 32 * i);
gc->reg_base = nvic_base + 4 * i;
gc->chip_types[0].regs.enable = NVIC_ISER;
gc->chip_types[0].regs.disable = NVIC_ICER;
gc->chip_types[0].chip.irq_mask = irq_gc_mask_disable_reg;
gc->chip_types[0].chip.irq_unmask = irq_gc_unmask_enable_reg;
gc->chip_types[0].chip.irq_eoi = irq_gc_noop;
writel_relaxed(~0, gc->reg_base + NVIC_ICER);
}
for (i = 0; i < irqs; i += 4)
writel_relaxed(0, nvic_base + NVIC_IPR + i);
return 0;
}
