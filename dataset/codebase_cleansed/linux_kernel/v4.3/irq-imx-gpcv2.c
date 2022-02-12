u32 imx_gpcv2_get_wakeup_source(u32 **sources)
{
if (!imx_gpcv2_instance)
return 0;
if (sources)
*sources = imx_gpcv2_instance->wakeup_sources;
return IMR_NUM;
}
static int gpcv2_wakeup_source_save(void)
{
struct gpcv2_irqchip_data *cd;
void __iomem *reg;
int i;
cd = imx_gpcv2_instance;
if (!cd)
return 0;
for (i = 0; i < IMR_NUM; i++) {
reg = cd->gpc_base + cd->cpu2wakeup + i * 4;
cd->saved_irq_mask[i] = readl_relaxed(reg);
writel_relaxed(cd->wakeup_sources[i], reg);
}
return 0;
}
static void gpcv2_wakeup_source_restore(void)
{
struct gpcv2_irqchip_data *cd;
void __iomem *reg;
int i;
cd = imx_gpcv2_instance;
if (!cd)
return;
for (i = 0; i < IMR_NUM; i++) {
reg = cd->gpc_base + cd->cpu2wakeup + i * 4;
writel_relaxed(cd->saved_irq_mask[i], reg);
}
}
static int imx_gpcv2_irq_set_wake(struct irq_data *d, unsigned int on)
{
struct gpcv2_irqchip_data *cd = d->chip_data;
unsigned int idx = d->hwirq / 32;
unsigned long flags;
void __iomem *reg;
u32 mask, val;
raw_spin_lock_irqsave(&cd->rlock, flags);
reg = cd->gpc_base + cd->cpu2wakeup + idx * 4;
mask = 1 << d->hwirq % 32;
val = cd->wakeup_sources[idx];
cd->wakeup_sources[idx] = on ? (val & ~mask) : (val | mask);
raw_spin_unlock_irqrestore(&cd->rlock, flags);
return 0;
}
static void imx_gpcv2_irq_unmask(struct irq_data *d)
{
struct gpcv2_irqchip_data *cd = d->chip_data;
void __iomem *reg;
u32 val;
raw_spin_lock(&cd->rlock);
reg = cd->gpc_base + cd->cpu2wakeup + d->hwirq / 32 * 4;
val = readl_relaxed(reg);
val &= ~(1 << d->hwirq % 32);
writel_relaxed(val, reg);
raw_spin_unlock(&cd->rlock);
irq_chip_unmask_parent(d);
}
static void imx_gpcv2_irq_mask(struct irq_data *d)
{
struct gpcv2_irqchip_data *cd = d->chip_data;
void __iomem *reg;
u32 val;
raw_spin_lock(&cd->rlock);
reg = cd->gpc_base + cd->cpu2wakeup + d->hwirq / 32 * 4;
val = readl_relaxed(reg);
val |= 1 << (d->hwirq % 32);
writel_relaxed(val, reg);
raw_spin_unlock(&cd->rlock);
irq_chip_mask_parent(d);
}
static int imx_gpcv2_domain_xlate(struct irq_domain *domain,
struct device_node *controller,
const u32 *intspec,
unsigned int intsize,
unsigned long *out_hwirq,
unsigned int *out_type)
{
if (domain->of_node != controller)
return -EINVAL;
if (intsize != 3)
return -EINVAL;
if (intspec[0] != 0)
return -EINVAL;
*out_hwirq = intspec[1];
*out_type = intspec[2];
return 0;
}
static int imx_gpcv2_domain_alloc(struct irq_domain *domain,
unsigned int irq, unsigned int nr_irqs,
void *data)
{
struct of_phandle_args *args = data;
struct of_phandle_args parent_args;
irq_hw_number_t hwirq;
int i;
if (args->args_count != 3)
return -EINVAL;
if (args->args[0] != 0)
return -EINVAL;
hwirq = args->args[1];
if (hwirq >= GPC_MAX_IRQS)
return -EINVAL;
for (i = 0; i < nr_irqs; i++) {
irq_domain_set_hwirq_and_chip(domain, irq + i, hwirq + i,
&gpcv2_irqchip_data_chip, domain->host_data);
}
parent_args = *args;
parent_args.np = domain->parent->of_node;
return irq_domain_alloc_irqs_parent(domain, irq, nr_irqs, &parent_args);
}
static int __init imx_gpcv2_irqchip_init(struct device_node *node,
struct device_node *parent)
{
struct irq_domain *parent_domain, *domain;
struct gpcv2_irqchip_data *cd;
int i;
if (!parent) {
pr_err("%s: no parent, giving up\n", node->full_name);
return -ENODEV;
}
parent_domain = irq_find_host(parent);
if (!parent_domain) {
pr_err("%s: unable to get parent domain\n", node->full_name);
return -ENXIO;
}
cd = kzalloc(sizeof(struct gpcv2_irqchip_data), GFP_KERNEL);
if (!cd) {
pr_err("kzalloc failed!\n");
return -ENOMEM;
}
cd->gpc_base = of_iomap(node, 0);
if (!cd->gpc_base) {
pr_err("fsl-gpcv2: unable to map gpc registers\n");
kfree(cd);
return -ENOMEM;
}
domain = irq_domain_add_hierarchy(parent_domain, 0, GPC_MAX_IRQS,
node, &gpcv2_irqchip_data_domain_ops, cd);
if (!domain) {
iounmap(cd->gpc_base);
kfree(cd);
return -ENOMEM;
}
irq_set_default_host(domain);
for (i = 0; i < IMR_NUM; i++) {
writel_relaxed(~0, cd->gpc_base + GPC_IMR1_CORE0 + i * 4);
writel_relaxed(~0, cd->gpc_base + GPC_IMR1_CORE1 + i * 4);
cd->wakeup_sources[i] = ~0;
}
cd->cpu2wakeup = GPC_IMR1_CORE0;
writel_relaxed(~0x1, cd->gpc_base + cd->cpu2wakeup);
imx_gpcv2_instance = cd;
register_syscore_ops(&imx_gpcv2_syscore_ops);
return 0;
}
