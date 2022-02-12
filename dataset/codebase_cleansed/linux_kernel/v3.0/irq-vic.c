static inline void msm_irq_write_all_regs(void __iomem *base, unsigned int val)
{
int i;
for (i = 0; i < VIC_NUM_REGS; i++)
writel(val, base + (i * 4));
}
static void msm_irq_ack(struct irq_data *d)
{
void __iomem *reg = VIC_INT_TO_REG_ADDR(VIC_INT_CLEAR0, d->irq);
writel(1 << (d->irq & 31), reg);
}
static void msm_irq_mask(struct irq_data *d)
{
void __iomem *reg = VIC_INT_TO_REG_ADDR(VIC_INT_ENCLEAR0, d->irq);
unsigned index = VIC_INT_TO_REG_INDEX(d->irq);
uint32_t mask = 1UL << (d->irq & 31);
int smsm_irq = msm_irq_to_smsm[d->irq];
msm_irq_shadow_reg[index].int_en[0] &= ~mask;
writel(mask, reg);
if (smsm_irq == 0)
msm_irq_idle_disable[index] &= ~mask;
else {
mask = 1UL << (smsm_irq - 1);
msm_irq_smsm_wake_enable[0] &= ~mask;
}
}
static void msm_irq_unmask(struct irq_data *d)
{
void __iomem *reg = VIC_INT_TO_REG_ADDR(VIC_INT_ENSET0, d->irq);
unsigned index = VIC_INT_TO_REG_INDEX(d->irq);
uint32_t mask = 1UL << (d->irq & 31);
int smsm_irq = msm_irq_to_smsm[d->irq];
msm_irq_shadow_reg[index].int_en[0] |= mask;
writel(mask, reg);
if (smsm_irq == 0)
msm_irq_idle_disable[index] |= mask;
else {
mask = 1UL << (smsm_irq - 1);
msm_irq_smsm_wake_enable[0] |= mask;
}
}
static int msm_irq_set_wake(struct irq_data *d, unsigned int on)
{
unsigned index = VIC_INT_TO_REG_INDEX(d->irq);
uint32_t mask = 1UL << (d->irq & 31);
int smsm_irq = msm_irq_to_smsm[d->irq];
if (smsm_irq == 0) {
printk(KERN_ERR "msm_irq_set_wake: bad wakeup irq %d\n", d->irq);
return -EINVAL;
}
if (on)
msm_irq_shadow_reg[index].int_en[1] |= mask;
else
msm_irq_shadow_reg[index].int_en[1] &= ~mask;
if (smsm_irq == SMSM_FAKE_IRQ)
return 0;
mask = 1UL << (smsm_irq - 1);
if (on)
msm_irq_smsm_wake_enable[1] |= mask;
else
msm_irq_smsm_wake_enable[1] &= ~mask;
return 0;
}
static int msm_irq_set_type(struct irq_data *d, unsigned int flow_type)
{
void __iomem *treg = VIC_INT_TO_REG_ADDR(VIC_INT_TYPE0, d->irq);
void __iomem *preg = VIC_INT_TO_REG_ADDR(VIC_INT_POLARITY0, d->irq);
unsigned index = VIC_INT_TO_REG_INDEX(d->irq);
int b = 1 << (d->irq & 31);
uint32_t polarity;
uint32_t type;
polarity = msm_irq_shadow_reg[index].int_polarity;
if (flow_type & (IRQF_TRIGGER_FALLING | IRQF_TRIGGER_LOW))
polarity |= b;
if (flow_type & (IRQF_TRIGGER_RISING | IRQF_TRIGGER_HIGH))
polarity &= ~b;
writel(polarity, preg);
msm_irq_shadow_reg[index].int_polarity = polarity;
type = msm_irq_shadow_reg[index].int_type;
if (flow_type & (IRQF_TRIGGER_RISING | IRQF_TRIGGER_FALLING)) {
type |= b;
__irq_set_handler_locked(d->irq, handle_edge_irq);
}
if (flow_type & (IRQF_TRIGGER_HIGH | IRQF_TRIGGER_LOW)) {
type &= ~b;
__irq_set_handler_locked(d->irq, handle_level_irq);
}
writel(type, treg);
msm_irq_shadow_reg[index].int_type = type;
return 0;
}
void __init msm_init_irq(void)
{
unsigned n;
msm_irq_write_all_regs(VIC_INT_TYPE0, 0);
msm_irq_write_all_regs(VIC_INT_POLARITY0, 0);
msm_irq_write_all_regs(VIC_INT_SELECT0, 0);
msm_irq_write_all_regs(VIC_INT_EN0, 0);
writel(0, VIC_CONFIG);
writel(3, VIC_INT_MASTEREN);
for (n = 0; n < NR_MSM_IRQS; n++) {
irq_set_chip_and_handler(n, &msm_irq_chip, handle_level_irq);
set_irq_flags(n, IRQF_VALID);
}
}
