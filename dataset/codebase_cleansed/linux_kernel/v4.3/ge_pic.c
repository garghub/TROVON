static void gef_pic_cascade(struct irq_desc *desc)
{
struct irq_chip *chip = irq_desc_get_chip(desc);
unsigned int cascade_irq;
cascade_irq = gef_pic_get_irq();
if (cascade_irq != NO_IRQ)
generic_handle_irq(cascade_irq);
chip->irq_eoi(&desc->irq_data);
}
static void gef_pic_mask(struct irq_data *d)
{
unsigned long flags;
unsigned int hwirq = irqd_to_hwirq(d);
u32 mask;
raw_spin_lock_irqsave(&gef_pic_lock, flags);
mask = in_be32(gef_pic_irq_reg_base + GEF_PIC_INTR_MASK(0));
mask &= ~(1 << hwirq);
out_be32(gef_pic_irq_reg_base + GEF_PIC_INTR_MASK(0), mask);
raw_spin_unlock_irqrestore(&gef_pic_lock, flags);
}
static void gef_pic_mask_ack(struct irq_data *d)
{
gef_pic_mask(d);
}
static void gef_pic_unmask(struct irq_data *d)
{
unsigned long flags;
unsigned int hwirq = irqd_to_hwirq(d);
u32 mask;
raw_spin_lock_irqsave(&gef_pic_lock, flags);
mask = in_be32(gef_pic_irq_reg_base + GEF_PIC_INTR_MASK(0));
mask |= (1 << hwirq);
out_be32(gef_pic_irq_reg_base + GEF_PIC_INTR_MASK(0), mask);
raw_spin_unlock_irqrestore(&gef_pic_lock, flags);
}
static int gef_pic_host_map(struct irq_domain *h, unsigned int virq,
irq_hw_number_t hwirq)
{
irq_set_status_flags(virq, IRQ_LEVEL);
irq_set_chip_and_handler(virq, &gef_pic_chip, handle_level_irq);
return 0;
}
static int gef_pic_host_xlate(struct irq_domain *h, struct device_node *ct,
const u32 *intspec, unsigned int intsize,
irq_hw_number_t *out_hwirq, unsigned int *out_flags)
{
*out_hwirq = intspec[0];
if (intsize > 1)
*out_flags = intspec[1];
else
*out_flags = IRQ_TYPE_LEVEL_HIGH;
return 0;
}
void __init gef_pic_init(struct device_node *np)
{
unsigned long flags;
gef_pic_irq_reg_base = of_iomap(np, 0);
raw_spin_lock_irqsave(&gef_pic_lock, flags);
out_be32(gef_pic_irq_reg_base + GEF_PIC_CPU0_INTR_MASK, 0);
out_be32(gef_pic_irq_reg_base + GEF_PIC_CPU1_INTR_MASK, 0);
out_be32(gef_pic_irq_reg_base + GEF_PIC_CPU0_MCP_MASK, 0);
out_be32(gef_pic_irq_reg_base + GEF_PIC_CPU1_MCP_MASK, 0);
raw_spin_unlock_irqrestore(&gef_pic_lock, flags);
gef_pic_cascade_irq = irq_of_parse_and_map(np, 0);
if (gef_pic_cascade_irq == NO_IRQ) {
printk(KERN_ERR "SBC610: failed to map cascade interrupt");
return;
}
gef_pic_irq_host = irq_domain_add_linear(np, GEF_PIC_NUM_IRQS,
&gef_pic_host_ops, NULL);
if (gef_pic_irq_host == NULL)
return;
irq_set_chained_handler(gef_pic_cascade_irq, gef_pic_cascade);
}
unsigned int gef_pic_get_irq(void)
{
u32 cause, mask, active;
unsigned int virq = NO_IRQ;
int hwirq;
cause = in_be32(gef_pic_irq_reg_base + GEF_PIC_INTR_STATUS);
mask = in_be32(gef_pic_irq_reg_base + GEF_PIC_INTR_MASK(0));
active = cause & mask;
if (active) {
for (hwirq = GEF_PIC_NUM_IRQS - 1; hwirq > -1; hwirq--) {
if (active & (0x1 << hwirq))
break;
}
virq = irq_linear_revmap(gef_pic_irq_host,
(irq_hw_number_t)hwirq);
}
return virq;
}
