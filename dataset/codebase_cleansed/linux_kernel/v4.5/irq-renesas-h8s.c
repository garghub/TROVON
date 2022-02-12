static void h8s_disable_irq(struct irq_data *data)
{
int pos;
unsigned int addr;
unsigned short pri;
int irq = data->irq;
addr = IPRA + ((ipr_table[irq - 16] & 0xf0) >> 3);
pos = (ipr_table[irq - 16] & 0x0f) * 4;
pri = ~(0x000f << pos);
pri &= readw(addr);
writew(pri, addr);
}
static void h8s_enable_irq(struct irq_data *data)
{
int pos;
unsigned int addr;
unsigned short pri;
int irq = data->irq;
addr = IPRA + ((ipr_table[irq - 16] & 0xf0) >> 3);
pos = (ipr_table[irq - 16] & 0x0f) * 4;
pri = ~(0x000f << pos);
pri &= readw(addr);
pri |= 1 << pos;
writew(pri, addr);
}
static __init int irq_map(struct irq_domain *h, unsigned int virq,
irq_hw_number_t hw_irq_num)
{
irq_set_chip_and_handler(virq, &h8s_irq_chip, handle_simple_irq);
return 0;
}
static int __init h8s_intc_of_init(struct device_node *intc,
struct device_node *parent)
{
struct irq_domain *domain;
int n;
intc_baseaddr = of_iomap(intc, 0);
BUG_ON(!intc_baseaddr);
for (n = 0; n <= 'k' - 'a'; n++)
writew(0x0000, IPRA + (n * 2));
domain = irq_domain_add_linear(intc, NR_IRQS, &irq_ops, NULL);
BUG_ON(!domain);
irq_set_default_host(domain);
return 0;
}
