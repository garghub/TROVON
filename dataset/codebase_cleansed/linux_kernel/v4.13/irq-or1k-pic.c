static void or1k_pic_mask(struct irq_data *data)
{
mtspr(SPR_PICMR, mfspr(SPR_PICMR) & ~(1UL << data->hwirq));
}
static void or1k_pic_unmask(struct irq_data *data)
{
mtspr(SPR_PICMR, mfspr(SPR_PICMR) | (1UL << data->hwirq));
}
static void or1k_pic_ack(struct irq_data *data)
{
mtspr(SPR_PICSR, (1UL << data->hwirq));
}
static void or1k_pic_mask_ack(struct irq_data *data)
{
mtspr(SPR_PICMR, mfspr(SPR_PICMR) & ~(1UL << data->hwirq));
mtspr(SPR_PICSR, (1UL << data->hwirq));
}
static void or1k_pic_or1200_ack(struct irq_data *data)
{
mtspr(SPR_PICSR, mfspr(SPR_PICSR) & ~(1UL << data->hwirq));
}
static void or1k_pic_or1200_mask_ack(struct irq_data *data)
{
mtspr(SPR_PICMR, mfspr(SPR_PICMR) & ~(1UL << data->hwirq));
mtspr(SPR_PICSR, mfspr(SPR_PICSR) & ~(1UL << data->hwirq));
}
static inline int pic_get_irq(int first)
{
int hwirq;
hwirq = ffs(mfspr(SPR_PICSR) >> first);
if (!hwirq)
return NO_IRQ;
else
hwirq = hwirq + first - 1;
return hwirq;
}
static void or1k_pic_handle_irq(struct pt_regs *regs)
{
int irq = -1;
while ((irq = pic_get_irq(irq + 1)) != NO_IRQ)
handle_domain_irq(root_domain, irq, regs);
}
static int or1k_map(struct irq_domain *d, unsigned int irq, irq_hw_number_t hw)
{
struct or1k_pic_dev *pic = d->host_data;
irq_set_chip_and_handler(irq, &pic->chip, pic->handle);
irq_set_status_flags(irq, pic->flags);
return 0;
}
static int __init or1k_pic_init(struct device_node *node,
struct or1k_pic_dev *pic)
{
mtspr(SPR_PICMR, (0UL));
root_domain = irq_domain_add_linear(node, 32, &or1k_irq_domain_ops,
pic);
set_handle_irq(or1k_pic_handle_irq);
return 0;
}
static int __init or1k_pic_or1200_init(struct device_node *node,
struct device_node *parent)
{
return or1k_pic_init(node, &or1k_pic_or1200);
}
static int __init or1k_pic_level_init(struct device_node *node,
struct device_node *parent)
{
return or1k_pic_init(node, &or1k_pic_level);
}
static int __init or1k_pic_edge_init(struct device_node *node,
struct device_node *parent)
{
return or1k_pic_init(node, &or1k_pic_edge);
}
