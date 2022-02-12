static void h8300h_disable_irq(struct irq_data *data)
{
int bit;
int irq = data->irq - 12;
bit = ipr_bit[irq];
if (bit >= 0) {
if (bit < 8)
ctrl_bclr(bit & 7, IPR);
else
ctrl_bclr(bit & 7, (IPR+1));
}
}
static void h8300h_enable_irq(struct irq_data *data)
{
int bit;
int irq = data->irq - 12;
bit = ipr_bit[irq];
if (bit >= 0) {
if (bit < 8)
ctrl_bset(bit & 7, IPR);
else
ctrl_bset(bit & 7, (IPR+1));
}
}
static int irq_map(struct irq_domain *h, unsigned int virq,
irq_hw_number_t hw_irq_num)
{
irq_set_chip_and_handler(virq, &h8300h_irq_chip, handle_simple_irq);
return 0;
}
static int __init h8300h_intc_of_init(struct device_node *intc,
struct device_node *parent)
{
struct irq_domain *domain;
intc_baseaddr = of_iomap(intc, 0);
BUG_ON(!intc_baseaddr);
writeb(0x00, IPR + 0);
writeb(0x00, IPR + 1);
domain = irq_domain_add_linear(intc, NR_IRQS, &irq_ops, NULL);
BUG_ON(!domain);
irq_set_default_host(domain);
return 0;
}
