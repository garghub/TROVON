static inline void crossbar_writel(int irq_no, int cb_no)
{
writel(cb_no, cb->crossbar_base + cb->register_offsets[irq_no]);
}
static inline void crossbar_writew(int irq_no, int cb_no)
{
writew(cb_no, cb->crossbar_base + cb->register_offsets[irq_no]);
}
static inline void crossbar_writeb(int irq_no, int cb_no)
{
writeb(cb_no, cb->crossbar_base + cb->register_offsets[irq_no]);
}
static inline int allocate_free_irq(int cb_no)
{
int i;
for (i = 0; i < cb->int_max; i++) {
if (cb->irq_map[i] == IRQ_FREE) {
cb->irq_map[i] = cb_no;
return i;
}
}
return -ENODEV;
}
static int crossbar_domain_map(struct irq_domain *d, unsigned int irq,
irq_hw_number_t hw)
{
cb->write(hw - GIC_IRQ_START, cb->irq_map[hw - GIC_IRQ_START]);
return 0;
}
static void crossbar_domain_unmap(struct irq_domain *d, unsigned int irq)
{
irq_hw_number_t hw = irq_get_irq_data(irq)->hwirq;
if (hw > GIC_IRQ_START)
cb->irq_map[hw - GIC_IRQ_START] = IRQ_FREE;
}
static int crossbar_domain_xlate(struct irq_domain *d,
struct device_node *controller,
const u32 *intspec, unsigned int intsize,
unsigned long *out_hwirq,
unsigned int *out_type)
{
unsigned long ret;
ret = allocate_free_irq(intspec[1]);
if (IS_ERR_VALUE(ret))
return ret;
*out_hwirq = ret + GIC_IRQ_START;
return 0;
}
static int __init crossbar_of_init(struct device_node *node)
{
int i, size, max, reserved = 0, entry;
const __be32 *irqsr;
cb = kzalloc(sizeof(*cb), GFP_KERNEL);
if (!cb)
return -ENOMEM;
cb->crossbar_base = of_iomap(node, 0);
if (!cb->crossbar_base)
goto err1;
of_property_read_u32(node, "ti,max-irqs", &max);
cb->irq_map = kzalloc(max * sizeof(int), GFP_KERNEL);
if (!cb->irq_map)
goto err2;
cb->int_max = max;
for (i = 0; i < max; i++)
cb->irq_map[i] = IRQ_FREE;
irqsr = of_get_property(node, "ti,irqs-reserved", &size);
if (irqsr) {
size /= sizeof(__be32);
for (i = 0; i < size; i++) {
of_property_read_u32_index(node,
"ti,irqs-reserved",
i, &entry);
if (entry > max) {
pr_err("Invalid reserved entry\n");
goto err3;
}
cb->irq_map[entry] = 0;
}
}
cb->register_offsets = kzalloc(max * sizeof(int), GFP_KERNEL);
if (!cb->register_offsets)
goto err3;
of_property_read_u32(node, "ti,reg-size", &size);
switch (size) {
case 1:
cb->write = crossbar_writeb;
break;
case 2:
cb->write = crossbar_writew;
break;
case 4:
cb->write = crossbar_writel;
break;
default:
pr_err("Invalid reg-size property\n");
goto err4;
break;
}
for (i = 0; i < max; i++) {
if (!cb->irq_map[i])
continue;
cb->register_offsets[i] = reserved;
reserved += size;
}
register_routable_domain_ops(&routable_irq_domain_ops);
return 0;
err4:
kfree(cb->register_offsets);
err3:
kfree(cb->irq_map);
err2:
iounmap(cb->crossbar_base);
err1:
kfree(cb);
return -ENOMEM;
}
int __init irqcrossbar_init(void)
{
struct device_node *np;
np = of_find_matching_node(NULL, crossbar_match);
if (!np)
return -ENODEV;
crossbar_of_init(np);
return 0;
}
