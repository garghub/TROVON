static void handle_jcore_irq(struct irq_desc *desc)
{
if (irqd_is_per_cpu(irq_desc_get_irq_data(desc)))
handle_percpu_irq(desc);
else
handle_simple_irq(desc);
}
static int jcore_aic_irqdomain_map(struct irq_domain *d, unsigned int irq,
irq_hw_number_t hwirq)
{
struct irq_chip *aic = d->host_data;
irq_set_chip_and_handler(irq, aic, handle_jcore_irq);
return 0;
}
static void noop(struct irq_data *data)
{
}
static int __init aic_irq_of_init(struct device_node *node,
struct device_node *parent)
{
unsigned min_irq = JCORE_AIC2_MIN_HWIRQ;
unsigned dom_sz = JCORE_AIC_MAX_HWIRQ+1;
struct irq_domain *domain;
pr_info("Initializing J-Core AIC\n");
if (of_device_is_compatible(node, "jcore,aic1")) {
unsigned cpu;
for_each_present_cpu(cpu) {
void __iomem *base = of_iomap(node, cpu);
if (!base) {
pr_err("Unable to map AIC for cpu %u\n", cpu);
return -ENOMEM;
}
__raw_writel(0xffffffff, base + JCORE_AIC1_INTPRI_REG);
iounmap(base);
}
min_irq = JCORE_AIC1_MIN_HWIRQ;
}
jcore_aic.irq_mask = noop;
jcore_aic.irq_unmask = noop;
jcore_aic.name = "AIC";
domain = irq_domain_add_linear(node, dom_sz, &jcore_aic_irqdomain_ops,
&jcore_aic);
if (!domain)
return -ENOMEM;
irq_create_strict_mappings(domain, min_irq, min_irq, dom_sz - min_irq);
return 0;
}
