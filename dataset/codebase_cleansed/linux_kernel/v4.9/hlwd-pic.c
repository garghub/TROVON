static void hlwd_pic_mask_and_ack(struct irq_data *d)
{
int irq = irqd_to_hwirq(d);
void __iomem *io_base = irq_data_get_irq_chip_data(d);
u32 mask = 1 << irq;
clrbits32(io_base + HW_BROADWAY_IMR, mask);
out_be32(io_base + HW_BROADWAY_ICR, mask);
}
static void hlwd_pic_ack(struct irq_data *d)
{
int irq = irqd_to_hwirq(d);
void __iomem *io_base = irq_data_get_irq_chip_data(d);
out_be32(io_base + HW_BROADWAY_ICR, 1 << irq);
}
static void hlwd_pic_mask(struct irq_data *d)
{
int irq = irqd_to_hwirq(d);
void __iomem *io_base = irq_data_get_irq_chip_data(d);
clrbits32(io_base + HW_BROADWAY_IMR, 1 << irq);
}
static void hlwd_pic_unmask(struct irq_data *d)
{
int irq = irqd_to_hwirq(d);
void __iomem *io_base = irq_data_get_irq_chip_data(d);
setbits32(io_base + HW_BROADWAY_IMR, 1 << irq);
}
static int hlwd_pic_map(struct irq_domain *h, unsigned int virq,
irq_hw_number_t hwirq)
{
irq_set_chip_data(virq, h->host_data);
irq_set_status_flags(virq, IRQ_LEVEL);
irq_set_chip_and_handler(virq, &hlwd_pic, handle_level_irq);
return 0;
}
static unsigned int __hlwd_pic_get_irq(struct irq_domain *h)
{
void __iomem *io_base = h->host_data;
int irq;
u32 irq_status;
irq_status = in_be32(io_base + HW_BROADWAY_ICR) &
in_be32(io_base + HW_BROADWAY_IMR);
if (irq_status == 0)
return 0;
irq = __ffs(irq_status);
return irq_linear_revmap(h, irq);
}
static void hlwd_pic_irq_cascade(struct irq_desc *desc)
{
struct irq_chip *chip = irq_desc_get_chip(desc);
struct irq_domain *irq_domain = irq_desc_get_handler_data(desc);
unsigned int virq;
raw_spin_lock(&desc->lock);
chip->irq_mask(&desc->irq_data);
raw_spin_unlock(&desc->lock);
virq = __hlwd_pic_get_irq(irq_domain);
if (virq)
generic_handle_irq(virq);
else
pr_err("spurious interrupt!\n");
raw_spin_lock(&desc->lock);
chip->irq_ack(&desc->irq_data);
if (!irqd_irq_disabled(&desc->irq_data) && chip->irq_unmask)
chip->irq_unmask(&desc->irq_data);
raw_spin_unlock(&desc->lock);
}
static void __hlwd_quiesce(void __iomem *io_base)
{
out_be32(io_base + HW_BROADWAY_IMR, 0);
out_be32(io_base + HW_BROADWAY_ICR, 0xffffffff);
}
struct irq_domain *hlwd_pic_init(struct device_node *np)
{
struct irq_domain *irq_domain;
struct resource res;
void __iomem *io_base;
int retval;
retval = of_address_to_resource(np, 0, &res);
if (retval) {
pr_err("no io memory range found\n");
return NULL;
}
io_base = ioremap(res.start, resource_size(&res));
if (!io_base) {
pr_err("ioremap failed\n");
return NULL;
}
pr_info("controller at 0x%08x mapped to 0x%p\n", res.start, io_base);
__hlwd_quiesce(io_base);
irq_domain = irq_domain_add_linear(np, HLWD_NR_IRQS,
&hlwd_irq_domain_ops, io_base);
if (!irq_domain) {
pr_err("failed to allocate irq_domain\n");
iounmap(io_base);
return NULL;
}
return irq_domain;
}
unsigned int hlwd_pic_get_irq(void)
{
return __hlwd_pic_get_irq(hlwd_irq_host);
}
void hlwd_pic_probe(void)
{
struct irq_domain *host;
struct device_node *np;
const u32 *interrupts;
int cascade_virq;
for_each_compatible_node(np, NULL, "nintendo,hollywood-pic") {
interrupts = of_get_property(np, "interrupts", NULL);
if (interrupts) {
host = hlwd_pic_init(np);
BUG_ON(!host);
cascade_virq = irq_of_parse_and_map(np, 0);
irq_set_handler_data(cascade_virq, host);
irq_set_chained_handler(cascade_virq,
hlwd_pic_irq_cascade);
hlwd_irq_host = host;
break;
}
}
}
void hlwd_quiesce(void)
{
void __iomem *io_base = hlwd_irq_host->host_data;
__hlwd_quiesce(io_base);
}
