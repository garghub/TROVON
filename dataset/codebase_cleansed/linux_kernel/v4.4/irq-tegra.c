static inline void tegra_ictlr_write_mask(struct irq_data *d, unsigned long reg)
{
void __iomem *base = d->chip_data;
u32 mask;
mask = BIT(d->hwirq % 32);
writel_relaxed(mask, base + reg);
}
static void tegra_mask(struct irq_data *d)
{
tegra_ictlr_write_mask(d, ICTLR_CPU_IER_CLR);
irq_chip_mask_parent(d);
}
static void tegra_unmask(struct irq_data *d)
{
tegra_ictlr_write_mask(d, ICTLR_CPU_IER_SET);
irq_chip_unmask_parent(d);
}
static void tegra_eoi(struct irq_data *d)
{
tegra_ictlr_write_mask(d, ICTLR_CPU_IEP_FIR_CLR);
irq_chip_eoi_parent(d);
}
static int tegra_retrigger(struct irq_data *d)
{
tegra_ictlr_write_mask(d, ICTLR_CPU_IEP_FIR_SET);
return irq_chip_retrigger_hierarchy(d);
}
static int tegra_set_wake(struct irq_data *d, unsigned int enable)
{
u32 irq = d->hwirq;
u32 index, mask;
index = (irq / 32);
mask = BIT(irq % 32);
if (enable)
lic->ictlr_wake_mask[index] |= mask;
else
lic->ictlr_wake_mask[index] &= ~mask;
return 0;
}
static int tegra_ictlr_suspend(void)
{
unsigned long flags;
unsigned int i;
local_irq_save(flags);
for (i = 0; i < num_ictlrs; i++) {
void __iomem *ictlr = lic->base[i];
lic->cpu_ier[i] = readl_relaxed(ictlr + ICTLR_CPU_IER);
lic->cpu_iep[i] = readl_relaxed(ictlr + ICTLR_CPU_IEP_CLASS);
lic->cop_ier[i] = readl_relaxed(ictlr + ICTLR_COP_IER);
lic->cop_iep[i] = readl_relaxed(ictlr + ICTLR_COP_IEP_CLASS);
writel_relaxed(~0ul, ictlr + ICTLR_COP_IER_CLR);
writel_relaxed(~0ul, ictlr + ICTLR_CPU_IER_CLR);
writel_relaxed(lic->ictlr_wake_mask[i], ictlr + ICTLR_CPU_IER_SET);
}
local_irq_restore(flags);
return 0;
}
static void tegra_ictlr_resume(void)
{
unsigned long flags;
unsigned int i;
local_irq_save(flags);
for (i = 0; i < num_ictlrs; i++) {
void __iomem *ictlr = lic->base[i];
writel_relaxed(lic->cpu_iep[i],
ictlr + ICTLR_CPU_IEP_CLASS);
writel_relaxed(~0ul, ictlr + ICTLR_CPU_IER_CLR);
writel_relaxed(lic->cpu_ier[i],
ictlr + ICTLR_CPU_IER_SET);
writel_relaxed(lic->cop_iep[i],
ictlr + ICTLR_COP_IEP_CLASS);
writel_relaxed(~0ul, ictlr + ICTLR_COP_IER_CLR);
writel_relaxed(lic->cop_ier[i],
ictlr + ICTLR_COP_IER_SET);
}
local_irq_restore(flags);
}
static void tegra_ictlr_syscore_init(void)
{
register_syscore_ops(&tegra_ictlr_syscore_ops);
}
static inline void tegra_ictlr_syscore_init(void) {}
static int tegra_ictlr_domain_translate(struct irq_domain *d,
struct irq_fwspec *fwspec,
unsigned long *hwirq,
unsigned int *type)
{
if (is_of_node(fwspec->fwnode)) {
if (fwspec->param_count != 3)
return -EINVAL;
if (fwspec->param[0] != 0)
return -EINVAL;
*hwirq = fwspec->param[1];
*type = fwspec->param[2];
return 0;
}
return -EINVAL;
}
static int tegra_ictlr_domain_alloc(struct irq_domain *domain,
unsigned int virq,
unsigned int nr_irqs, void *data)
{
struct irq_fwspec *fwspec = data;
struct irq_fwspec parent_fwspec;
struct tegra_ictlr_info *info = domain->host_data;
irq_hw_number_t hwirq;
unsigned int i;
if (fwspec->param_count != 3)
return -EINVAL;
if (fwspec->param[0] != GIC_SPI)
return -EINVAL;
hwirq = fwspec->param[1];
if (hwirq >= (num_ictlrs * 32))
return -EINVAL;
for (i = 0; i < nr_irqs; i++) {
int ictlr = (hwirq + i) / 32;
irq_domain_set_hwirq_and_chip(domain, virq + i, hwirq + i,
&tegra_ictlr_chip,
info->base[ictlr]);
}
parent_fwspec = *fwspec;
parent_fwspec.fwnode = domain->parent->fwnode;
return irq_domain_alloc_irqs_parent(domain, virq, nr_irqs,
&parent_fwspec);
}
static void tegra_ictlr_domain_free(struct irq_domain *domain,
unsigned int virq,
unsigned int nr_irqs)
{
unsigned int i;
for (i = 0; i < nr_irqs; i++) {
struct irq_data *d = irq_domain_get_irq_data(domain, virq + i);
irq_domain_reset_irq_data(d);
}
}
static int __init tegra_ictlr_init(struct device_node *node,
struct device_node *parent)
{
struct irq_domain *parent_domain, *domain;
const struct of_device_id *match;
const struct tegra_ictlr_soc *soc;
unsigned int i;
int err;
if (!parent) {
pr_err("%s: no parent, giving up\n", node->full_name);
return -ENODEV;
}
parent_domain = irq_find_host(parent);
if (!parent_domain) {
pr_err("%s: unable to obtain parent domain\n", node->full_name);
return -ENXIO;
}
match = of_match_node(ictlr_matches, node);
if (!match)
return -ENODEV;
soc = match->data;
lic = kzalloc(sizeof(*lic), GFP_KERNEL);
if (!lic)
return -ENOMEM;
for (i = 0; i < TEGRA_MAX_NUM_ICTLRS; i++) {
void __iomem *base;
base = of_iomap(node, i);
if (!base)
break;
lic->base[i] = base;
writel_relaxed(~0UL, base + ICTLR_CPU_IER_CLR);
writel_relaxed(0, base + ICTLR_CPU_IEP_CLASS);
num_ictlrs++;
}
if (!num_ictlrs) {
pr_err("%s: no valid regions, giving up\n", node->full_name);
err = -ENOMEM;
goto out_free;
}
WARN(num_ictlrs != soc->num_ictlrs,
"%s: Found %u interrupt controllers in DT; expected %u.\n",
node->full_name, num_ictlrs, soc->num_ictlrs);
domain = irq_domain_add_hierarchy(parent_domain, 0, num_ictlrs * 32,
node, &tegra_ictlr_domain_ops,
lic);
if (!domain) {
pr_err("%s: failed to allocated domain\n", node->full_name);
err = -ENOMEM;
goto out_unmap;
}
tegra_ictlr_syscore_init();
pr_info("%s: %d interrupts forwarded to %s\n",
node->full_name, num_ictlrs * 32, parent->full_name);
return 0;
out_unmap:
for (i = 0; i < num_ictlrs; i++)
iounmap(lic->base[i]);
out_free:
kfree(lic);
return err;
}
