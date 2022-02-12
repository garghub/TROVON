static inline void rt_intc_w32(u32 val, unsigned reg)
{
__raw_writel(val, rt_intc_membase + reg);
}
static inline u32 rt_intc_r32(unsigned reg)
{
return __raw_readl(rt_intc_membase + reg);
}
static void ralink_intc_irq_unmask(struct irq_data *d)
{
rt_intc_w32(BIT(d->hwirq), INTC_REG_ENABLE);
}
static void ralink_intc_irq_mask(struct irq_data *d)
{
rt_intc_w32(BIT(d->hwirq), INTC_REG_DISABLE);
}
unsigned int get_c0_compare_int(void)
{
return CP0_LEGACY_COMPARE_IRQ;
}
static void ralink_intc_irq_handler(unsigned int irq, struct irq_desc *desc)
{
u32 pending = rt_intc_r32(INTC_REG_STATUS0);
if (pending) {
struct irq_domain *domain = irq_get_handler_data(irq);
generic_handle_irq(irq_find_mapping(domain, __ffs(pending)));
} else {
spurious_interrupt();
}
}
asmlinkage void plat_irq_dispatch(void)
{
unsigned long pending;
pending = read_c0_status() & read_c0_cause() & ST0_IM;
if (pending & STATUSF_IP7)
do_IRQ(RALINK_CPU_IRQ_COUNTER);
else if (pending & STATUSF_IP5)
do_IRQ(RALINK_CPU_IRQ_FE);
else if (pending & STATUSF_IP6)
do_IRQ(RALINK_CPU_IRQ_WIFI);
else if (pending & STATUSF_IP4)
do_IRQ(RALINK_CPU_IRQ_PCI);
else if (pending & STATUSF_IP2)
do_IRQ(RALINK_CPU_IRQ_INTC);
else
spurious_interrupt();
}
static int intc_map(struct irq_domain *d, unsigned int irq, irq_hw_number_t hw)
{
irq_set_chip_and_handler(irq, &ralink_intc_irq_chip, handle_level_irq);
return 0;
}
static int __init intc_of_init(struct device_node *node,
struct device_node *parent)
{
struct resource res;
struct irq_domain *domain;
int irq;
irq = irq_of_parse_and_map(node, 0);
if (!irq)
panic("Failed to get INTC IRQ");
if (of_address_to_resource(node, 0, &res))
panic("Failed to get intc memory range");
if (request_mem_region(res.start, resource_size(&res),
res.name) < 0)
pr_err("Failed to request intc memory");
rt_intc_membase = ioremap_nocache(res.start,
resource_size(&res));
if (!rt_intc_membase)
panic("Failed to remap intc memory");
rt_intc_w32(~0, INTC_REG_DISABLE);
rt_intc_w32(0, INTC_REG_TYPE);
domain = irq_domain_add_legacy(node, RALINK_INTC_IRQ_COUNT,
RALINK_INTC_IRQ_BASE, 0, &irq_domain_ops, NULL);
if (!domain)
panic("Failed to add irqdomain");
rt_intc_w32(INTC_INT_GLOBAL, INTC_REG_ENABLE);
irq_set_chained_handler(irq, ralink_intc_irq_handler);
irq_set_handler_data(irq, domain);
cp0_perfcount_irq = irq_create_mapping(domain, 9);
return 0;
}
void __init arch_init_irq(void)
{
of_irq_init(of_irq_ids);
}
