static void shirq_irq_mask(struct irq_data *d)
{
struct spear_shirq *shirq = irq_data_get_irq_chip_data(d);
u32 val, shift = d->irq - shirq->virq_base + shirq->offset;
u32 __iomem *reg = shirq->base + shirq->mask_reg;
raw_spin_lock(&shirq_lock);
val = readl(reg) & ~(0x1 << shift);
writel(val, reg);
raw_spin_unlock(&shirq_lock);
}
static void shirq_irq_unmask(struct irq_data *d)
{
struct spear_shirq *shirq = irq_data_get_irq_chip_data(d);
u32 val, shift = d->irq - shirq->virq_base + shirq->offset;
u32 __iomem *reg = shirq->base + shirq->mask_reg;
raw_spin_lock(&shirq_lock);
val = readl(reg) | (0x1 << shift);
writel(val, reg);
raw_spin_unlock(&shirq_lock);
}
static void shirq_handler(struct irq_desc *desc)
{
struct spear_shirq *shirq = irq_desc_get_handler_data(desc);
u32 pend;
pend = readl(shirq->base + shirq->status_reg) & shirq->mask;
pend >>= shirq->offset;
while (pend) {
int irq = __ffs(pend);
pend &= ~(0x1 << irq);
generic_handle_irq(shirq->virq_base + irq);
}
}
static void __init spear_shirq_register(struct spear_shirq *shirq,
int parent_irq)
{
int i;
if (!shirq->irq_chip)
return;
irq_set_chained_handler_and_data(parent_irq, shirq_handler, shirq);
for (i = 0; i < shirq->nr_irqs; i++) {
irq_set_chip_and_handler(shirq->virq_base + i,
shirq->irq_chip, handle_simple_irq);
irq_set_chip_data(shirq->virq_base + i, shirq);
}
}
static int __init shirq_init(struct spear_shirq **shirq_blocks, int block_nr,
struct device_node *np)
{
int i, parent_irq, virq_base, hwirq = 0, nr_irqs = 0;
struct irq_domain *shirq_domain;
void __iomem *base;
base = of_iomap(np, 0);
if (!base) {
pr_err("%s: failed to map shirq registers\n", __func__);
return -ENXIO;
}
for (i = 0; i < block_nr; i++)
nr_irqs += shirq_blocks[i]->nr_irqs;
virq_base = irq_alloc_descs(-1, 0, nr_irqs, 0);
if (virq_base < 0) {
pr_err("%s: irq desc alloc failed\n", __func__);
goto err_unmap;
}
shirq_domain = irq_domain_add_legacy(np, nr_irqs, virq_base, 0,
&irq_domain_simple_ops, NULL);
if (WARN_ON(!shirq_domain)) {
pr_warn("%s: irq domain init failed\n", __func__);
goto err_free_desc;
}
for (i = 0; i < block_nr; i++) {
shirq_blocks[i]->base = base;
shirq_blocks[i]->virq_base = irq_find_mapping(shirq_domain,
hwirq);
parent_irq = irq_of_parse_and_map(np, i);
spear_shirq_register(shirq_blocks[i], parent_irq);
hwirq += shirq_blocks[i]->nr_irqs;
}
return 0;
err_free_desc:
irq_free_descs(virq_base, nr_irqs);
err_unmap:
iounmap(base);
return -ENXIO;
}
static int __init spear300_shirq_of_init(struct device_node *np,
struct device_node *parent)
{
return shirq_init(spear300_shirq_blocks,
ARRAY_SIZE(spear300_shirq_blocks), np);
}
static int __init spear310_shirq_of_init(struct device_node *np,
struct device_node *parent)
{
return shirq_init(spear310_shirq_blocks,
ARRAY_SIZE(spear310_shirq_blocks), np);
}
static int __init spear320_shirq_of_init(struct device_node *np,
struct device_node *parent)
{
return shirq_init(spear320_shirq_blocks,
ARRAY_SIZE(spear320_shirq_blocks), np);
}
