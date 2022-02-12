static asmlinkage void __exception_irq_entry
aic5_handle(struct pt_regs *regs)
{
struct irq_domain_chip_generic *dgc = aic5_domain->gc;
struct irq_chip_generic *gc = dgc->gc[0];
u32 irqnr;
u32 irqstat;
irqnr = irq_reg_readl(gc, AT91_AIC5_IVR);
irqstat = irq_reg_readl(gc, AT91_AIC5_ISR);
if (!irqstat)
irq_reg_writel(gc, 0, AT91_AIC5_EOICR);
else
handle_domain_irq(aic5_domain, irqnr, regs);
}
static void aic5_mask(struct irq_data *d)
{
struct irq_domain *domain = d->domain;
struct irq_domain_chip_generic *dgc = domain->gc;
struct irq_chip_generic *gc = dgc->gc[0];
irq_gc_lock(gc);
irq_reg_writel(gc, d->hwirq, AT91_AIC5_SSR);
irq_reg_writel(gc, 1, AT91_AIC5_IDCR);
gc->mask_cache &= ~d->mask;
irq_gc_unlock(gc);
}
static void aic5_unmask(struct irq_data *d)
{
struct irq_domain *domain = d->domain;
struct irq_domain_chip_generic *dgc = domain->gc;
struct irq_chip_generic *gc = dgc->gc[0];
irq_gc_lock(gc);
irq_reg_writel(gc, d->hwirq, AT91_AIC5_SSR);
irq_reg_writel(gc, 1, AT91_AIC5_IECR);
gc->mask_cache |= d->mask;
irq_gc_unlock(gc);
}
static int aic5_retrigger(struct irq_data *d)
{
struct irq_domain *domain = d->domain;
struct irq_domain_chip_generic *dgc = domain->gc;
struct irq_chip_generic *gc = dgc->gc[0];
irq_gc_lock(gc);
irq_reg_writel(gc, d->hwirq, AT91_AIC5_SSR);
irq_reg_writel(gc, 1, AT91_AIC5_ISCR);
irq_gc_unlock(gc);
return 0;
}
static int aic5_set_type(struct irq_data *d, unsigned type)
{
struct irq_domain *domain = d->domain;
struct irq_domain_chip_generic *dgc = domain->gc;
struct irq_chip_generic *gc = dgc->gc[0];
unsigned int smr;
int ret;
irq_gc_lock(gc);
irq_reg_writel(gc, d->hwirq, AT91_AIC5_SSR);
smr = irq_reg_readl(gc, AT91_AIC5_SMR);
ret = aic_common_set_type(d, type, &smr);
if (!ret)
irq_reg_writel(gc, smr, AT91_AIC5_SMR);
irq_gc_unlock(gc);
return ret;
}
static void aic5_suspend(struct irq_data *d)
{
struct irq_domain *domain = d->domain;
struct irq_domain_chip_generic *dgc = domain->gc;
struct irq_chip_generic *bgc = dgc->gc[0];
struct irq_chip_generic *gc = irq_data_get_irq_chip_data(d);
int i;
u32 mask;
irq_gc_lock(bgc);
for (i = 0; i < dgc->irqs_per_chip; i++) {
mask = 1 << i;
if ((mask & gc->mask_cache) == (mask & gc->wake_active))
continue;
irq_reg_writel(bgc, i + gc->irq_base, AT91_AIC5_SSR);
if (mask & gc->wake_active)
irq_reg_writel(bgc, 1, AT91_AIC5_IECR);
else
irq_reg_writel(bgc, 1, AT91_AIC5_IDCR);
}
irq_gc_unlock(bgc);
}
static void aic5_resume(struct irq_data *d)
{
struct irq_domain *domain = d->domain;
struct irq_domain_chip_generic *dgc = domain->gc;
struct irq_chip_generic *bgc = dgc->gc[0];
struct irq_chip_generic *gc = irq_data_get_irq_chip_data(d);
int i;
u32 mask;
irq_gc_lock(bgc);
for (i = 0; i < dgc->irqs_per_chip; i++) {
mask = 1 << i;
if ((mask & gc->mask_cache) == (mask & gc->wake_active))
continue;
irq_reg_writel(bgc, i + gc->irq_base, AT91_AIC5_SSR);
if (mask & gc->mask_cache)
irq_reg_writel(bgc, 1, AT91_AIC5_IECR);
else
irq_reg_writel(bgc, 1, AT91_AIC5_IDCR);
}
irq_gc_unlock(bgc);
}
static void aic5_pm_shutdown(struct irq_data *d)
{
struct irq_domain *domain = d->domain;
struct irq_domain_chip_generic *dgc = domain->gc;
struct irq_chip_generic *bgc = dgc->gc[0];
struct irq_chip_generic *gc = irq_data_get_irq_chip_data(d);
int i;
irq_gc_lock(bgc);
for (i = 0; i < dgc->irqs_per_chip; i++) {
irq_reg_writel(bgc, i + gc->irq_base, AT91_AIC5_SSR);
irq_reg_writel(bgc, 1, AT91_AIC5_IDCR);
irq_reg_writel(bgc, 1, AT91_AIC5_ICCR);
}
irq_gc_unlock(bgc);
}
static void __init aic5_hw_init(struct irq_domain *domain)
{
struct irq_chip_generic *gc = irq_get_domain_generic_chip(domain, 0);
int i;
for (i = 0; i < 8; i++)
irq_reg_writel(gc, 0, AT91_AIC5_EOICR);
irq_reg_writel(gc, 0xffffffff, AT91_AIC5_SPU);
irq_reg_writel(gc, 0, AT91_AIC5_DCR);
for (i = 0; i < domain->revmap_size; i++) {
irq_reg_writel(gc, i, AT91_AIC5_SSR);
irq_reg_writel(gc, i, AT91_AIC5_SVR);
irq_reg_writel(gc, 1, AT91_AIC5_IDCR);
irq_reg_writel(gc, 1, AT91_AIC5_ICCR);
}
}
static int aic5_irq_domain_xlate(struct irq_domain *d,
struct device_node *ctrlr,
const u32 *intspec, unsigned int intsize,
irq_hw_number_t *out_hwirq,
unsigned int *out_type)
{
struct irq_domain_chip_generic *dgc = d->gc;
struct irq_chip_generic *gc;
unsigned smr;
int ret;
if (!dgc)
return -EINVAL;
ret = aic_common_irq_domain_xlate(d, ctrlr, intspec, intsize,
out_hwirq, out_type);
if (ret)
return ret;
gc = dgc->gc[0];
irq_gc_lock(gc);
irq_reg_writel(gc, *out_hwirq, AT91_AIC5_SSR);
smr = irq_reg_readl(gc, AT91_AIC5_SMR);
ret = aic_common_set_priority(intspec[2], &smr);
if (!ret)
irq_reg_writel(gc, intspec[2] | smr, AT91_AIC5_SMR);
irq_gc_unlock(gc);
return ret;
}
static void __init sama5d3_aic_irq_fixup(struct device_node *root)
{
aic_common_rtc_irq_fixup(root);
}
static int __init aic5_of_init(struct device_node *node,
struct device_node *parent,
int nirqs)
{
struct irq_chip_generic *gc;
struct irq_domain *domain;
int nchips;
int i;
if (nirqs > NR_AIC5_IRQS)
return -EINVAL;
if (aic5_domain)
return -EEXIST;
domain = aic_common_of_init(node, &aic5_irq_ops, "atmel-aic5",
nirqs);
if (IS_ERR(domain))
return PTR_ERR(domain);
aic_common_irq_fixup(aic5_irq_fixups);
aic5_domain = domain;
nchips = aic5_domain->revmap_size / 32;
for (i = 0; i < nchips; i++) {
gc = irq_get_domain_generic_chip(domain, i * 32);
gc->chip_types[0].regs.eoi = AT91_AIC5_EOICR;
gc->chip_types[0].chip.irq_mask = aic5_mask;
gc->chip_types[0].chip.irq_unmask = aic5_unmask;
gc->chip_types[0].chip.irq_retrigger = aic5_retrigger;
gc->chip_types[0].chip.irq_set_type = aic5_set_type;
gc->chip_types[0].chip.irq_suspend = aic5_suspend;
gc->chip_types[0].chip.irq_resume = aic5_resume;
gc->chip_types[0].chip.irq_pm_shutdown = aic5_pm_shutdown;
}
aic5_hw_init(domain);
set_handle_irq(aic5_handle);
return 0;
}
static int __init sama5d2_aic5_of_init(struct device_node *node,
struct device_node *parent)
{
return aic5_of_init(node, parent, NR_SAMA5D2_IRQS);
}
static int __init sama5d3_aic5_of_init(struct device_node *node,
struct device_node *parent)
{
return aic5_of_init(node, parent, NR_SAMA5D3_IRQS);
}
static int __init sama5d4_aic5_of_init(struct device_node *node,
struct device_node *parent)
{
return aic5_of_init(node, parent, NR_SAMA5D4_IRQS);
}
