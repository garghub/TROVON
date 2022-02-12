static void sirc_irq_mask(struct irq_data *d)
{
unsigned int mask;
mask = 1 << (d->irq - FIRST_SIRC_IRQ);
writel(mask, sirc_regs.int_enable_clear);
int_enable &= ~mask;
return;
}
static void sirc_irq_unmask(struct irq_data *d)
{
unsigned int mask;
mask = 1 << (d->irq - FIRST_SIRC_IRQ);
writel(mask, sirc_regs.int_enable_set);
int_enable |= mask;
return;
}
static void sirc_irq_ack(struct irq_data *d)
{
unsigned int mask;
mask = 1 << (d->irq - FIRST_SIRC_IRQ);
writel(mask, sirc_regs.int_clear);
return;
}
static int sirc_irq_set_wake(struct irq_data *d, unsigned int on)
{
unsigned int mask;
mask = 1 << (d->irq - FIRST_SIRC_IRQ);
if (on)
wake_enable |= mask;
else
wake_enable &= ~mask;
return 0;
}
static int sirc_irq_set_type(struct irq_data *d, unsigned int flow_type)
{
unsigned int mask;
unsigned int val;
mask = 1 << (d->irq - FIRST_SIRC_IRQ);
val = readl(sirc_regs.int_polarity);
if (flow_type & (IRQF_TRIGGER_LOW | IRQF_TRIGGER_FALLING))
val |= mask;
else
val &= ~mask;
writel(val, sirc_regs.int_polarity);
val = readl(sirc_regs.int_type);
if (flow_type & (IRQF_TRIGGER_RISING | IRQF_TRIGGER_FALLING)) {
val |= mask;
__irq_set_handler_locked(d->irq, handle_edge_irq);
} else {
val &= ~mask;
__irq_set_handler_locked(d->irq, handle_level_irq);
}
writel(val, sirc_regs.int_type);
return 0;
}
static void sirc_irq_handler(unsigned int irq, struct irq_desc *desc)
{
unsigned int reg = 0;
unsigned int sirq;
unsigned int status;
while ((reg < ARRAY_SIZE(sirc_reg_table)) &&
(sirc_reg_table[reg].cascade_irq != irq))
reg++;
status = readl(sirc_reg_table[reg].int_status);
status &= SIRC_MASK;
if (status == 0)
return;
for (sirq = 0;
(sirq < NR_SIRC_IRQS) && ((status & (1U << sirq)) == 0);
sirq++)
;
generic_handle_irq(sirq+FIRST_SIRC_IRQ);
desc->irq_data.chip->irq_ack(&desc->irq_data);
}
void __init msm_init_sirc(void)
{
int i;
int_enable = 0;
wake_enable = 0;
for (i = FIRST_SIRC_IRQ; i < LAST_SIRC_IRQ; i++) {
irq_set_chip_and_handler(i, &sirc_irq_chip, handle_edge_irq);
set_irq_flags(i, IRQF_VALID);
}
for (i = 0; i < ARRAY_SIZE(sirc_reg_table); i++) {
irq_set_chained_handler(sirc_reg_table[i].cascade_irq,
sirc_irq_handler);
irq_set_irq_wake(sirc_reg_table[i].cascade_irq, 1);
}
return;
}
