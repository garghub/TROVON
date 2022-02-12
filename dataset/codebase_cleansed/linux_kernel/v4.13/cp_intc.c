static inline unsigned int cp_intc_read(unsigned offset)
{
return __raw_readl(davinci_intc_base + offset);
}
static inline void cp_intc_write(unsigned long value, unsigned offset)
{
__raw_writel(value, davinci_intc_base + offset);
}
static void cp_intc_ack_irq(struct irq_data *d)
{
cp_intc_write(d->hwirq, CP_INTC_SYS_STAT_IDX_CLR);
}
static void cp_intc_mask_irq(struct irq_data *d)
{
cp_intc_write(1, CP_INTC_HOST_ENABLE_IDX_CLR);
cp_intc_write(d->hwirq, CP_INTC_SYS_ENABLE_IDX_CLR);
cp_intc_write(1, CP_INTC_HOST_ENABLE_IDX_SET);
}
static void cp_intc_unmask_irq(struct irq_data *d)
{
cp_intc_write(d->hwirq, CP_INTC_SYS_ENABLE_IDX_SET);
}
static int cp_intc_set_irq_type(struct irq_data *d, unsigned int flow_type)
{
unsigned reg = BIT_WORD(d->hwirq);
unsigned mask = BIT_MASK(d->hwirq);
unsigned polarity = cp_intc_read(CP_INTC_SYS_POLARITY(reg));
unsigned type = cp_intc_read(CP_INTC_SYS_TYPE(reg));
switch (flow_type) {
case IRQ_TYPE_EDGE_RISING:
polarity |= mask;
type |= mask;
break;
case IRQ_TYPE_EDGE_FALLING:
polarity &= ~mask;
type |= mask;
break;
case IRQ_TYPE_LEVEL_HIGH:
polarity |= mask;
type &= ~mask;
break;
case IRQ_TYPE_LEVEL_LOW:
polarity &= ~mask;
type &= ~mask;
break;
default:
return -EINVAL;
}
cp_intc_write(polarity, CP_INTC_SYS_POLARITY(reg));
cp_intc_write(type, CP_INTC_SYS_TYPE(reg));
return 0;
}
static int cp_intc_host_map(struct irq_domain *h, unsigned int virq,
irq_hw_number_t hw)
{
pr_debug("cp_intc_host_map(%d, 0x%lx)\n", virq, hw);
irq_set_chip(virq, &cp_intc_irq_chip);
irq_set_probe(virq);
irq_set_handler(virq, handle_edge_irq);
return 0;
}
int __init cp_intc_of_init(struct device_node *node, struct device_node *parent)
{
u32 num_irq = davinci_soc_info.intc_irq_num;
u8 *irq_prio = davinci_soc_info.intc_irq_prios;
u32 *host_map = davinci_soc_info.intc_host_map;
unsigned num_reg = BITS_TO_LONGS(num_irq);
int i, irq_base;
davinci_intc_type = DAVINCI_INTC_TYPE_CP_INTC;
if (node) {
davinci_intc_base = of_iomap(node, 0);
if (of_property_read_u32(node, "ti,intc-size", &num_irq))
pr_warn("unable to get intc-size, default to %d\n",
num_irq);
} else {
davinci_intc_base = ioremap(davinci_soc_info.intc_base, SZ_8K);
}
if (WARN_ON(!davinci_intc_base))
return -EINVAL;
cp_intc_write(0, CP_INTC_GLOBAL_ENABLE);
cp_intc_write(0, CP_INTC_HOST_ENABLE(0));
for (i = 0; i < num_reg; i++)
cp_intc_write(~0, CP_INTC_SYS_ENABLE_CLR(i));
cp_intc_write(0, CP_INTC_CTRL);
cp_intc_write(0, CP_INTC_HOST_CTRL);
for (i = 0; i < num_reg; i++)
cp_intc_write(~0, CP_INTC_SYS_STAT_CLR(i));
cp_intc_write(1, CP_INTC_HOST_ENABLE_IDX_SET);
num_reg = (num_irq + 3) >> 2;
if (irq_prio) {
unsigned j, k;
u32 val;
for (k = i = 0; i < num_reg; i++) {
for (val = j = 0; j < 4; j++, k++) {
val >>= 8;
if (k < num_irq)
val |= irq_prio[k] << 24;
}
cp_intc_write(val, CP_INTC_CHAN_MAP(i));
}
} else {
for (i = 0; i < num_reg; i++)
cp_intc_write(0x0f0f0f0f, CP_INTC_CHAN_MAP(i));
}
if (host_map)
for (i = 0; host_map[i] != -1; i++)
cp_intc_write(host_map[i], CP_INTC_HOST_MAP(i));
irq_base = irq_alloc_descs(-1, 0, num_irq, 0);
if (irq_base < 0) {
pr_warn("Couldn't allocate IRQ numbers\n");
irq_base = 0;
}
cp_intc_domain = irq_domain_add_legacy(node, num_irq,
irq_base, 0, &cp_intc_host_ops, NULL);
if (!cp_intc_domain) {
pr_err("cp_intc: failed to allocate irq host!\n");
return -EINVAL;
}
cp_intc_write(1, CP_INTC_GLOBAL_ENABLE);
return 0;
}
void __init cp_intc_init(void)
{
cp_intc_of_init(NULL, NULL);
}
