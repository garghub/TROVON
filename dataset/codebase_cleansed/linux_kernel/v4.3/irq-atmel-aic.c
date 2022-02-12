static asmlinkage void __exception_irq_entry
aic_handle(struct pt_regs *regs)
{
struct irq_domain_chip_generic *dgc = aic_domain->gc;
struct irq_chip_generic *gc = dgc->gc[0];
u32 irqnr;
u32 irqstat;
irqnr = irq_reg_readl(gc, AT91_AIC_IVR);
irqstat = irq_reg_readl(gc, AT91_AIC_ISR);
if (!irqstat)
irq_reg_writel(gc, 0, AT91_AIC_EOICR);
else
handle_domain_irq(aic_domain, irqnr, regs);
}
static int aic_retrigger(struct irq_data *d)
{
struct irq_chip_generic *gc = irq_data_get_irq_chip_data(d);
irq_gc_lock(gc);
irq_reg_writel(gc, d->mask, AT91_AIC_ISCR);
irq_gc_unlock(gc);
return 0;
}
static int aic_set_type(struct irq_data *d, unsigned type)
{
struct irq_chip_generic *gc = irq_data_get_irq_chip_data(d);
unsigned int smr;
int ret;
smr = irq_reg_readl(gc, AT91_AIC_SMR(d->hwirq));
ret = aic_common_set_type(d, type, &smr);
if (ret)
return ret;
irq_reg_writel(gc, smr, AT91_AIC_SMR(d->hwirq));
return 0;
}
static void aic_suspend(struct irq_data *d)
{
struct irq_chip_generic *gc = irq_data_get_irq_chip_data(d);
irq_gc_lock(gc);
irq_reg_writel(gc, gc->mask_cache, AT91_AIC_IDCR);
irq_reg_writel(gc, gc->wake_active, AT91_AIC_IECR);
irq_gc_unlock(gc);
}
static void aic_resume(struct irq_data *d)
{
struct irq_chip_generic *gc = irq_data_get_irq_chip_data(d);
irq_gc_lock(gc);
irq_reg_writel(gc, gc->wake_active, AT91_AIC_IDCR);
irq_reg_writel(gc, gc->mask_cache, AT91_AIC_IECR);
irq_gc_unlock(gc);
}
static void aic_pm_shutdown(struct irq_data *d)
{
struct irq_chip_generic *gc = irq_data_get_irq_chip_data(d);
irq_gc_lock(gc);
irq_reg_writel(gc, 0xffffffff, AT91_AIC_IDCR);
irq_reg_writel(gc, 0xffffffff, AT91_AIC_ICCR);
irq_gc_unlock(gc);
}
static void __init aic_hw_init(struct irq_domain *domain)
{
struct irq_chip_generic *gc = irq_get_domain_generic_chip(domain, 0);
int i;
for (i = 0; i < 8; i++)
irq_reg_writel(gc, 0, AT91_AIC_EOICR);
irq_reg_writel(gc, 0xffffffff, AT91_AIC_SPU);
irq_reg_writel(gc, 0, AT91_AIC_DCR);
irq_reg_writel(gc, 0xffffffff, AT91_AIC_IDCR);
irq_reg_writel(gc, 0xffffffff, AT91_AIC_ICCR);
for (i = 0; i < 32; i++)
irq_reg_writel(gc, i, AT91_AIC_SVR(i));
}
static int aic_irq_domain_xlate(struct irq_domain *d,
struct device_node *ctrlr,
const u32 *intspec, unsigned int intsize,
irq_hw_number_t *out_hwirq,
unsigned int *out_type)
{
struct irq_domain_chip_generic *dgc = d->gc;
struct irq_chip_generic *gc;
unsigned smr;
int idx;
int ret;
if (!dgc)
return -EINVAL;
ret = aic_common_irq_domain_xlate(d, ctrlr, intspec, intsize,
out_hwirq, out_type);
if (ret)
return ret;
idx = intspec[0] / dgc->irqs_per_chip;
if (idx >= dgc->num_chips)
return -EINVAL;
gc = dgc->gc[idx];
irq_gc_lock(gc);
smr = irq_reg_readl(gc, AT91_AIC_SMR(*out_hwirq));
ret = aic_common_set_priority(intspec[2], &smr);
if (!ret)
irq_reg_writel(gc, smr, AT91_AIC_SMR(*out_hwirq));
irq_gc_unlock(gc);
return ret;
}
static void __init at91rm9200_aic_irq_fixup(struct device_node *root)
{
aic_common_rtc_irq_fixup(root);
}
static void __init at91sam9260_aic_irq_fixup(struct device_node *root)
{
aic_common_rtt_irq_fixup(root);
}
static void __init at91sam9g45_aic_irq_fixup(struct device_node *root)
{
aic_common_rtc_irq_fixup(root);
aic_common_rtt_irq_fixup(root);
}
static int __init aic_of_init(struct device_node *node,
struct device_node *parent)
{
struct irq_chip_generic *gc;
struct irq_domain *domain;
if (aic_domain)
return -EEXIST;
domain = aic_common_of_init(node, &aic_irq_ops, "atmel-aic",
NR_AIC_IRQS);
if (IS_ERR(domain))
return PTR_ERR(domain);
aic_common_irq_fixup(aic_irq_fixups);
aic_domain = domain;
gc = irq_get_domain_generic_chip(domain, 0);
gc->chip_types[0].regs.eoi = AT91_AIC_EOICR;
gc->chip_types[0].regs.enable = AT91_AIC_IECR;
gc->chip_types[0].regs.disable = AT91_AIC_IDCR;
gc->chip_types[0].chip.irq_mask = irq_gc_mask_disable_reg;
gc->chip_types[0].chip.irq_unmask = irq_gc_unmask_enable_reg;
gc->chip_types[0].chip.irq_retrigger = aic_retrigger;
gc->chip_types[0].chip.irq_set_type = aic_set_type;
gc->chip_types[0].chip.irq_suspend = aic_suspend;
gc->chip_types[0].chip.irq_resume = aic_resume;
gc->chip_types[0].chip.irq_pm_shutdown = aic_pm_shutdown;
aic_hw_init(domain);
set_handle_irq(aic_handle);
return 0;
}
