static inline void s5p_irq_eint_mask(struct irq_data *data)
{
u32 mask;
mask = __raw_readl(S5P_EINT_MASK(EINT_REG_NR(data->irq)));
mask |= eint_irq_to_bit(data->irq);
__raw_writel(mask, S5P_EINT_MASK(EINT_REG_NR(data->irq)));
}
static void s5p_irq_eint_unmask(struct irq_data *data)
{
u32 mask;
mask = __raw_readl(S5P_EINT_MASK(EINT_REG_NR(data->irq)));
mask &= ~(eint_irq_to_bit(data->irq));
__raw_writel(mask, S5P_EINT_MASK(EINT_REG_NR(data->irq)));
}
static inline void s5p_irq_eint_ack(struct irq_data *data)
{
__raw_writel(eint_irq_to_bit(data->irq),
S5P_EINT_PEND(EINT_REG_NR(data->irq)));
}
static void s5p_irq_eint_maskack(struct irq_data *data)
{
s5p_irq_eint_mask(data);
s5p_irq_eint_ack(data);
}
static int s5p_irq_eint_set_type(struct irq_data *data, unsigned int type)
{
int offs = EINT_OFFSET(data->irq);
int shift;
u32 ctrl, mask;
u32 newvalue = 0;
switch (type) {
case IRQ_TYPE_EDGE_RISING:
newvalue = S5P_IRQ_TYPE_EDGE_RISING;
break;
case IRQ_TYPE_EDGE_FALLING:
newvalue = S5P_IRQ_TYPE_EDGE_FALLING;
break;
case IRQ_TYPE_EDGE_BOTH:
newvalue = S5P_IRQ_TYPE_EDGE_BOTH;
break;
case IRQ_TYPE_LEVEL_LOW:
newvalue = S5P_IRQ_TYPE_LEVEL_LOW;
break;
case IRQ_TYPE_LEVEL_HIGH:
newvalue = S5P_IRQ_TYPE_LEVEL_HIGH;
break;
default:
printk(KERN_ERR "No such irq type %d", type);
return -EINVAL;
}
shift = (offs & 0x7) * 4;
mask = 0x7 << shift;
ctrl = __raw_readl(S5P_EINT_CON(EINT_REG_NR(data->irq)));
ctrl &= ~mask;
ctrl |= newvalue << shift;
__raw_writel(ctrl, S5P_EINT_CON(EINT_REG_NR(data->irq)));
if ((0 <= offs) && (offs < 8))
s3c_gpio_cfgpin(EINT_GPIO_0(offs & 0x7), EINT_MODE);
else if ((8 <= offs) && (offs < 16))
s3c_gpio_cfgpin(EINT_GPIO_1(offs & 0x7), EINT_MODE);
else if ((16 <= offs) && (offs < 24))
s3c_gpio_cfgpin(EINT_GPIO_2(offs & 0x7), EINT_MODE);
else if ((24 <= offs) && (offs < 32))
s3c_gpio_cfgpin(EINT_GPIO_3(offs & 0x7), EINT_MODE);
else
printk(KERN_ERR "No such irq number %d", offs);
return 0;
}
static inline void s5p_irq_demux_eint(unsigned int start)
{
u32 status = __raw_readl(S5P_EINT_PEND(EINT_REG_NR(start)));
u32 mask = __raw_readl(S5P_EINT_MASK(EINT_REG_NR(start)));
unsigned int irq;
status &= ~mask;
status &= 0xff;
while (status) {
irq = fls(status) - 1;
generic_handle_irq(irq + start);
status &= ~(1 << irq);
}
}
static void s5p_irq_demux_eint16_31(unsigned int irq, struct irq_desc *desc)
{
s5p_irq_demux_eint(IRQ_EINT(16));
s5p_irq_demux_eint(IRQ_EINT(24));
}
static inline void s5p_irq_vic_eint_mask(struct irq_data *data)
{
void __iomem *base = irq_data_get_irq_chip_data(data);
s5p_irq_eint_mask(data);
writel(1 << EINT_OFFSET(data->irq), base + VIC_INT_ENABLE_CLEAR);
}
static void s5p_irq_vic_eint_unmask(struct irq_data *data)
{
void __iomem *base = irq_data_get_irq_chip_data(data);
s5p_irq_eint_unmask(data);
writel(1 << EINT_OFFSET(data->irq), base + VIC_INT_ENABLE);
}
static inline void s5p_irq_vic_eint_ack(struct irq_data *data)
{
__raw_writel(eint_irq_to_bit(data->irq),
S5P_EINT_PEND(EINT_REG_NR(data->irq)));
}
static void s5p_irq_vic_eint_maskack(struct irq_data *data)
{
s5p_irq_vic_eint_mask(data);
s5p_irq_vic_eint_ack(data);
}
static int __init s5p_init_irq_eint(void)
{
int irq;
if (of_have_populated_dt())
return -ENODEV;
for (irq = IRQ_EINT(0); irq <= IRQ_EINT(15); irq++)
irq_set_chip(irq, &s5p_irq_vic_eint);
for (irq = IRQ_EINT(16); irq <= IRQ_EINT(31); irq++) {
irq_set_chip_and_handler(irq, &s5p_irq_eint, handle_level_irq);
set_irq_flags(irq, IRQF_VALID);
}
irq_set_chained_handler(IRQ_EINT16_31, s5p_irq_demux_eint16_31);
return 0;
}
