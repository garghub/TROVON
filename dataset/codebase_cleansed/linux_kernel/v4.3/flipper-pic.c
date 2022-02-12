static void flipper_pic_mask_and_ack(struct irq_data *d)
{
int irq = irqd_to_hwirq(d);
void __iomem *io_base = irq_data_get_irq_chip_data(d);
u32 mask = 1 << irq;
clrbits32(io_base + FLIPPER_IMR, mask);
out_be32(io_base + FLIPPER_ICR, mask);
}
static void flipper_pic_ack(struct irq_data *d)
{
int irq = irqd_to_hwirq(d);
void __iomem *io_base = irq_data_get_irq_chip_data(d);
out_be32(io_base + FLIPPER_ICR, 1 << irq);
}
static void flipper_pic_mask(struct irq_data *d)
{
int irq = irqd_to_hwirq(d);
void __iomem *io_base = irq_data_get_irq_chip_data(d);
clrbits32(io_base + FLIPPER_IMR, 1 << irq);
}
static void flipper_pic_unmask(struct irq_data *d)
{
int irq = irqd_to_hwirq(d);
void __iomem *io_base = irq_data_get_irq_chip_data(d);
setbits32(io_base + FLIPPER_IMR, 1 << irq);
}
static int flipper_pic_map(struct irq_domain *h, unsigned int virq,
irq_hw_number_t hwirq)
{
irq_set_chip_data(virq, h->host_data);
irq_set_status_flags(virq, IRQ_LEVEL);
irq_set_chip_and_handler(virq, &flipper_pic, handle_level_irq);
return 0;
}
static int flipper_pic_match(struct irq_domain *h, struct device_node *np,
enum irq_domain_bus_token bus_token)
{
return 1;
}
static void __flipper_quiesce(void __iomem *io_base)
{
out_be32(io_base + FLIPPER_IMR, 0x00000000);
out_be32(io_base + FLIPPER_ICR, 0xffffffff);
}
struct irq_domain * __init flipper_pic_init(struct device_node *np)
{
struct device_node *pi;
struct irq_domain *irq_domain = NULL;
struct resource res;
void __iomem *io_base;
int retval;
pi = of_get_parent(np);
if (!pi) {
pr_err("no parent found\n");
goto out;
}
if (!of_device_is_compatible(pi, "nintendo,flipper-pi")) {
pr_err("unexpected parent compatible\n");
goto out;
}
retval = of_address_to_resource(pi, 0, &res);
if (retval) {
pr_err("no io memory range found\n");
goto out;
}
io_base = ioremap(res.start, resource_size(&res));
pr_info("controller at 0x%08x mapped to 0x%p\n", res.start, io_base);
__flipper_quiesce(io_base);
irq_domain = irq_domain_add_linear(np, FLIPPER_NR_IRQS,
&flipper_irq_domain_ops, io_base);
if (!irq_domain) {
pr_err("failed to allocate irq_domain\n");
return NULL;
}
out:
return irq_domain;
}
unsigned int flipper_pic_get_irq(void)
{
void __iomem *io_base = flipper_irq_host->host_data;
int irq;
u32 irq_status;
irq_status = in_be32(io_base + FLIPPER_ICR) &
in_be32(io_base + FLIPPER_IMR);
if (irq_status == 0)
return NO_IRQ;
irq = __ffs(irq_status);
return irq_linear_revmap(flipper_irq_host, irq);
}
void __init flipper_pic_probe(void)
{
struct device_node *np;
np = of_find_compatible_node(NULL, NULL, "nintendo,flipper-pic");
BUG_ON(!np);
flipper_irq_host = flipper_pic_init(np);
BUG_ON(!flipper_irq_host);
irq_set_default_host(flipper_irq_host);
of_node_put(np);
}
void flipper_quiesce(void)
{
void __iomem *io_base = flipper_irq_host->host_data;
__flipper_quiesce(io_base);
}
void flipper_platform_reset(void)
{
void __iomem *io_base;
if (flipper_irq_host && flipper_irq_host->host_data) {
io_base = flipper_irq_host->host_data;
out_8(io_base + FLIPPER_RESET, 0x00);
}
}
int flipper_is_reset_button_pressed(void)
{
void __iomem *io_base;
u32 icr;
if (flipper_irq_host && flipper_irq_host->host_data) {
io_base = flipper_irq_host->host_data;
icr = in_be32(io_base + FLIPPER_ICR);
return !(icr & FLIPPER_ICR_RSS);
}
return 0;
}
