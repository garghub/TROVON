static int mtk_sysirq_set_type(struct irq_data *data, unsigned int type)
{
irq_hw_number_t hwirq = data->hwirq;
struct mtk_sysirq_chip_data *chip_data = data->chip_data;
u8 intpol_idx = chip_data->intpol_idx[hwirq];
void __iomem *base;
u32 offset, reg_index, value;
unsigned long flags;
int ret;
base = chip_data->intpol_bases[intpol_idx];
reg_index = chip_data->which_word[hwirq];
offset = hwirq & 0x1f;
spin_lock_irqsave(&chip_data->lock, flags);
value = readl_relaxed(base + reg_index * 4);
if (type == IRQ_TYPE_LEVEL_LOW || type == IRQ_TYPE_EDGE_FALLING) {
if (type == IRQ_TYPE_LEVEL_LOW)
type = IRQ_TYPE_LEVEL_HIGH;
else
type = IRQ_TYPE_EDGE_RISING;
value |= (1 << offset);
} else {
value &= ~(1 << offset);
}
writel_relaxed(value, base + reg_index * 4);
data = data->parent_data;
ret = data->chip->irq_set_type(data, type);
spin_unlock_irqrestore(&chip_data->lock, flags);
return ret;
}
static int mtk_sysirq_domain_translate(struct irq_domain *d,
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
*type = fwspec->param[2] & IRQ_TYPE_SENSE_MASK;
return 0;
}
return -EINVAL;
}
static int mtk_sysirq_domain_alloc(struct irq_domain *domain, unsigned int virq,
unsigned int nr_irqs, void *arg)
{
int i;
irq_hw_number_t hwirq;
struct irq_fwspec *fwspec = arg;
struct irq_fwspec gic_fwspec = *fwspec;
if (fwspec->param_count != 3)
return -EINVAL;
if (fwspec->param[0])
return -EINVAL;
hwirq = fwspec->param[1];
for (i = 0; i < nr_irqs; i++)
irq_domain_set_hwirq_and_chip(domain, virq + i, hwirq + i,
&mtk_sysirq_chip,
domain->host_data);
gic_fwspec.fwnode = domain->parent->fwnode;
return irq_domain_alloc_irqs_parent(domain, virq, nr_irqs, &gic_fwspec);
}
static int __init mtk_sysirq_of_init(struct device_node *node,
struct device_node *parent)
{
struct irq_domain *domain, *domain_parent;
struct mtk_sysirq_chip_data *chip_data;
int ret, size, intpol_num = 0, nr_intpol_bases = 0, i = 0;
domain_parent = irq_find_host(parent);
if (!domain_parent) {
pr_err("mtk_sysirq: interrupt-parent not found\n");
return -EINVAL;
}
chip_data = kzalloc(sizeof(*chip_data), GFP_KERNEL);
if (!chip_data)
return -ENOMEM;
while (of_get_address(node, i++, NULL, NULL))
nr_intpol_bases++;
if (nr_intpol_bases == 0) {
pr_err("mtk_sysirq: base address not specified\n");
ret = -EINVAL;
goto out_free_chip;
}
chip_data->intpol_words = kcalloc(nr_intpol_bases,
sizeof(*chip_data->intpol_words),
GFP_KERNEL);
if (!chip_data->intpol_words) {
ret = -ENOMEM;
goto out_free_chip;
}
chip_data->intpol_bases = kcalloc(nr_intpol_bases,
sizeof(*chip_data->intpol_bases),
GFP_KERNEL);
if (!chip_data->intpol_bases) {
ret = -ENOMEM;
goto out_free_intpol_words;
}
for (i = 0; i < nr_intpol_bases; i++) {
struct resource res;
ret = of_address_to_resource(node, i, &res);
size = resource_size(&res);
intpol_num += size * 8;
chip_data->intpol_words[i] = size / 4;
chip_data->intpol_bases[i] = of_iomap(node, i);
if (ret || !chip_data->intpol_bases[i]) {
pr_err("%pOF: couldn't map region %d\n", node, i);
ret = -ENODEV;
goto out_free_intpol;
}
}
chip_data->intpol_idx = kcalloc(intpol_num,
sizeof(*chip_data->intpol_idx),
GFP_KERNEL);
if (!chip_data->intpol_idx) {
ret = -ENOMEM;
goto out_free_intpol;
}
chip_data->which_word = kcalloc(intpol_num,
sizeof(*chip_data->which_word),
GFP_KERNEL);
if (!chip_data->which_word) {
ret = -ENOMEM;
goto out_free_intpol_idx;
}
for (i = 0; i < intpol_num ; i++) {
u32 word = i / 32, j;
for (j = 0; word >= chip_data->intpol_words[j] ; j++)
word -= chip_data->intpol_words[j];
chip_data->intpol_idx[i] = j;
chip_data->which_word[i] = word;
}
domain = irq_domain_add_hierarchy(domain_parent, 0, intpol_num, node,
&sysirq_domain_ops, chip_data);
if (!domain) {
ret = -ENOMEM;
goto out_free_which_word;
}
spin_lock_init(&chip_data->lock);
return 0;
out_free_which_word:
kfree(chip_data->which_word);
out_free_intpol_idx:
kfree(chip_data->intpol_idx);
out_free_intpol:
for (i = 0; i < nr_intpol_bases; i++)
if (chip_data->intpol_bases[i])
iounmap(chip_data->intpol_bases[i]);
kfree(chip_data->intpol_bases);
out_free_intpol_words:
kfree(chip_data->intpol_words);
out_free_chip:
kfree(chip_data);
return ret;
}
