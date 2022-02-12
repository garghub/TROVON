static void mtk_cirq_write_mask(struct irq_data *data, unsigned int offset)
{
struct mtk_cirq_chip_data *chip_data = data->chip_data;
unsigned int cirq_num = data->hwirq;
u32 mask = 1 << (cirq_num % 32);
writel_relaxed(mask, chip_data->base + offset + (cirq_num / 32) * 4);
}
static void mtk_cirq_mask(struct irq_data *data)
{
mtk_cirq_write_mask(data, CIRQ_MASK_SET);
irq_chip_mask_parent(data);
}
static void mtk_cirq_unmask(struct irq_data *data)
{
mtk_cirq_write_mask(data, CIRQ_MASK_CLR);
irq_chip_unmask_parent(data);
}
static int mtk_cirq_set_type(struct irq_data *data, unsigned int type)
{
int ret;
switch (type & IRQ_TYPE_SENSE_MASK) {
case IRQ_TYPE_EDGE_FALLING:
mtk_cirq_write_mask(data, CIRQ_POL_CLR);
mtk_cirq_write_mask(data, CIRQ_SENS_CLR);
break;
case IRQ_TYPE_EDGE_RISING:
mtk_cirq_write_mask(data, CIRQ_POL_SET);
mtk_cirq_write_mask(data, CIRQ_SENS_CLR);
break;
case IRQ_TYPE_LEVEL_LOW:
mtk_cirq_write_mask(data, CIRQ_POL_CLR);
mtk_cirq_write_mask(data, CIRQ_SENS_SET);
break;
case IRQ_TYPE_LEVEL_HIGH:
mtk_cirq_write_mask(data, CIRQ_POL_SET);
mtk_cirq_write_mask(data, CIRQ_SENS_SET);
break;
default:
break;
}
data = data->parent_data;
ret = data->chip->irq_set_type(data, type);
return ret;
}
static int mtk_cirq_domain_translate(struct irq_domain *d,
struct irq_fwspec *fwspec,
unsigned long *hwirq,
unsigned int *type)
{
if (is_of_node(fwspec->fwnode)) {
if (fwspec->param_count != 3)
return -EINVAL;
if (fwspec->param[0] != 0)
return -EINVAL;
if (fwspec->param[1] < cirq_data->ext_irq_start ||
fwspec->param[1] > cirq_data->ext_irq_end)
return -EINVAL;
*hwirq = fwspec->param[1] - cirq_data->ext_irq_start;
*type = fwspec->param[2] & IRQ_TYPE_SENSE_MASK;
return 0;
}
return -EINVAL;
}
static int mtk_cirq_domain_alloc(struct irq_domain *domain, unsigned int virq,
unsigned int nr_irqs, void *arg)
{
int ret;
irq_hw_number_t hwirq;
unsigned int type;
struct irq_fwspec *fwspec = arg;
struct irq_fwspec parent_fwspec = *fwspec;
ret = mtk_cirq_domain_translate(domain, fwspec, &hwirq, &type);
if (ret)
return ret;
if (WARN_ON(nr_irqs != 1))
return -EINVAL;
irq_domain_set_hwirq_and_chip(domain, virq, hwirq,
&mtk_cirq_chip,
domain->host_data);
parent_fwspec.fwnode = domain->parent->fwnode;
return irq_domain_alloc_irqs_parent(domain, virq, nr_irqs,
&parent_fwspec);
}
static int mtk_cirq_suspend(void)
{
u32 value, mask;
unsigned int irq, hwirq_num;
bool pending, masked;
int i, pendret, maskret;
hwirq_num = cirq_data->ext_irq_end - cirq_data->ext_irq_start + 1;
for (i = 0; i < hwirq_num; i++) {
irq = irq_find_mapping(cirq_data->domain, i);
if (irq) {
pendret = irq_get_irqchip_state(irq,
IRQCHIP_STATE_PENDING,
&pending);
maskret = irq_get_irqchip_state(irq,
IRQCHIP_STATE_MASKED,
&masked);
if (pendret == 0 && maskret == 0 &&
(pending && !masked))
continue;
}
mask = 1 << (i % 32);
writel_relaxed(mask, cirq_data->base + CIRQ_ACK + (i / 32) * 4);
}
value = readl_relaxed(cirq_data->base + CIRQ_CONTROL);
value |= (CIRQ_EDGE | CIRQ_EN);
writel_relaxed(value, cirq_data->base + CIRQ_CONTROL);
return 0;
}
static void mtk_cirq_resume(void)
{
u32 value;
value = readl_relaxed(cirq_data->base + CIRQ_CONTROL);
writel_relaxed(value | CIRQ_FLUSH, cirq_data->base + CIRQ_CONTROL);
value = readl_relaxed(cirq_data->base + CIRQ_CONTROL);
value &= ~(CIRQ_EDGE | CIRQ_EN);
writel_relaxed(value, cirq_data->base + CIRQ_CONTROL);
}
static void mtk_cirq_syscore_init(void)
{
register_syscore_ops(&mtk_cirq_syscore_ops);
}
static inline void mtk_cirq_syscore_init(void) {}
static int __init mtk_cirq_of_init(struct device_node *node,
struct device_node *parent)
{
struct irq_domain *domain, *domain_parent;
unsigned int irq_num;
int ret;
domain_parent = irq_find_host(parent);
if (!domain_parent) {
pr_err("mtk_cirq: interrupt-parent not found\n");
return -EINVAL;
}
cirq_data = kzalloc(sizeof(*cirq_data), GFP_KERNEL);
if (!cirq_data)
return -ENOMEM;
cirq_data->base = of_iomap(node, 0);
if (!cirq_data->base) {
pr_err("mtk_cirq: unable to map cirq register\n");
ret = -ENXIO;
goto out_free;
}
ret = of_property_read_u32_index(node, "mediatek,ext-irq-range", 0,
&cirq_data->ext_irq_start);
if (ret)
goto out_unmap;
ret = of_property_read_u32_index(node, "mediatek,ext-irq-range", 1,
&cirq_data->ext_irq_end);
if (ret)
goto out_unmap;
irq_num = cirq_data->ext_irq_end - cirq_data->ext_irq_start + 1;
domain = irq_domain_add_hierarchy(domain_parent, 0,
irq_num, node,
&cirq_domain_ops, cirq_data);
if (!domain) {
ret = -ENOMEM;
goto out_unmap;
}
cirq_data->domain = domain;
mtk_cirq_syscore_init();
return 0;
out_unmap:
iounmap(cirq_data->base);
out_free:
kfree(cirq_data);
return ret;
}
