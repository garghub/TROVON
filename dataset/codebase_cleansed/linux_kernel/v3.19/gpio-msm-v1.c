static void msm_gpio_writel(struct msm_gpio_chip *chip, u32 val,
enum msm_gpio_reg reg)
{
writel(val, chip->base + chip->regs[reg]);
}
static u32 msm_gpio_readl(struct msm_gpio_chip *chip, enum msm_gpio_reg reg)
{
return readl(chip->base + chip->regs[reg]);
}
static int msm_gpio_write(struct msm_gpio_chip *msm_chip,
unsigned offset, unsigned on)
{
unsigned mask = BIT(offset);
unsigned val;
val = msm_gpio_readl(msm_chip, MSM_GPIO_OUT);
if (on)
msm_gpio_writel(msm_chip, val | mask, MSM_GPIO_OUT);
else
msm_gpio_writel(msm_chip, val & ~mask, MSM_GPIO_OUT);
return 0;
}
static void msm_gpio_update_both_edge_detect(struct msm_gpio_chip *msm_chip)
{
int loop_limit = 100;
unsigned pol, val, val2, intstat;
do {
val = msm_gpio_readl(msm_chip, MSM_GPIO_IN);
pol = msm_gpio_readl(msm_chip, MSM_GPIO_INT_POS);
pol = (pol & ~msm_chip->both_edge_detect) |
(~val & msm_chip->both_edge_detect);
msm_gpio_writel(msm_chip, pol, MSM_GPIO_INT_POS);
intstat = msm_gpio_readl(msm_chip, MSM_GPIO_INT_STATUS);
val2 = msm_gpio_readl(msm_chip, MSM_GPIO_IN);
if (((val ^ val2) & msm_chip->both_edge_detect & ~intstat) == 0)
return;
} while (loop_limit-- > 0);
printk(KERN_ERR "msm_gpio_update_both_edge_detect, "
"failed to reach stable state %x != %x\n", val, val2);
}
static int msm_gpio_clear_detect_status(struct msm_gpio_chip *msm_chip,
unsigned offset)
{
unsigned bit = BIT(offset);
#if MSM_GPIO_BROKEN_INT_CLEAR
msm_chip->int_status_copy |=
msm_gpio_readl(msm_chip, MSM_GPIO_INT_STATUS);
msm_chip->int_status_copy &= ~bit;
#endif
msm_gpio_writel(msm_chip, bit, MSM_GPIO_INT_CLEAR);
msm_gpio_update_both_edge_detect(msm_chip);
return 0;
}
static int msm_gpio_direction_input(struct gpio_chip *chip, unsigned offset)
{
struct msm_gpio_chip *msm_chip;
unsigned long irq_flags;
u32 val;
msm_chip = container_of(chip, struct msm_gpio_chip, chip);
spin_lock_irqsave(&msm_chip->lock, irq_flags);
val = msm_gpio_readl(msm_chip, MSM_GPIO_OE) & ~BIT(offset);
msm_gpio_writel(msm_chip, val, MSM_GPIO_OE);
spin_unlock_irqrestore(&msm_chip->lock, irq_flags);
return 0;
}
static int
msm_gpio_direction_output(struct gpio_chip *chip, unsigned offset, int value)
{
struct msm_gpio_chip *msm_chip;
unsigned long irq_flags;
u32 val;
msm_chip = container_of(chip, struct msm_gpio_chip, chip);
spin_lock_irqsave(&msm_chip->lock, irq_flags);
msm_gpio_write(msm_chip, offset, value);
val = msm_gpio_readl(msm_chip, MSM_GPIO_OE) | BIT(offset);
msm_gpio_writel(msm_chip, val, MSM_GPIO_OE);
spin_unlock_irqrestore(&msm_chip->lock, irq_flags);
return 0;
}
static int msm_gpio_get(struct gpio_chip *chip, unsigned offset)
{
struct msm_gpio_chip *msm_chip;
msm_chip = container_of(chip, struct msm_gpio_chip, chip);
return (msm_gpio_readl(msm_chip, MSM_GPIO_IN) & (1U << offset)) ? 1 : 0;
}
static void msm_gpio_set(struct gpio_chip *chip, unsigned offset, int value)
{
struct msm_gpio_chip *msm_chip;
unsigned long irq_flags;
msm_chip = container_of(chip, struct msm_gpio_chip, chip);
spin_lock_irqsave(&msm_chip->lock, irq_flags);
msm_gpio_write(msm_chip, offset, value);
spin_unlock_irqrestore(&msm_chip->lock, irq_flags);
}
static int msm_gpio_to_irq(struct gpio_chip *chip, unsigned offset)
{
return MSM_GPIO_TO_INT(chip->base + offset);
}
static int msm_gpio_request(struct gpio_chip *chip, unsigned offset)
{
return msm_gpiomux_get(chip->base + offset);
}
static void msm_gpio_free(struct gpio_chip *chip, unsigned offset)
{
msm_gpiomux_put(chip->base + offset);
}
static void msm_gpio_irq_ack(struct irq_data *d)
{
unsigned long irq_flags;
struct msm_gpio_chip *msm_chip = irq_data_get_irq_chip_data(d);
spin_lock_irqsave(&msm_chip->lock, irq_flags);
msm_gpio_clear_detect_status(msm_chip,
d->irq - gpio_to_irq(msm_chip->chip.base));
spin_unlock_irqrestore(&msm_chip->lock, irq_flags);
}
static void msm_gpio_irq_mask(struct irq_data *d)
{
unsigned long irq_flags;
struct msm_gpio_chip *msm_chip = irq_data_get_irq_chip_data(d);
unsigned offset = d->irq - gpio_to_irq(msm_chip->chip.base);
spin_lock_irqsave(&msm_chip->lock, irq_flags);
if (!(msm_gpio_readl(msm_chip, MSM_GPIO_INT_EDGE) & BIT(offset)))
msm_gpio_clear_detect_status(msm_chip, offset);
msm_chip->int_enable[0] &= ~BIT(offset);
msm_gpio_writel(msm_chip, msm_chip->int_enable[0], MSM_GPIO_INT_EN);
spin_unlock_irqrestore(&msm_chip->lock, irq_flags);
}
static void msm_gpio_irq_unmask(struct irq_data *d)
{
unsigned long irq_flags;
struct msm_gpio_chip *msm_chip = irq_data_get_irq_chip_data(d);
unsigned offset = d->irq - gpio_to_irq(msm_chip->chip.base);
spin_lock_irqsave(&msm_chip->lock, irq_flags);
if (!(msm_gpio_readl(msm_chip, MSM_GPIO_INT_EDGE) & BIT(offset)))
msm_gpio_clear_detect_status(msm_chip, offset);
msm_chip->int_enable[0] |= BIT(offset);
msm_gpio_writel(msm_chip, msm_chip->int_enable[0], MSM_GPIO_INT_EN);
spin_unlock_irqrestore(&msm_chip->lock, irq_flags);
}
static int msm_gpio_irq_set_wake(struct irq_data *d, unsigned int on)
{
unsigned long irq_flags;
struct msm_gpio_chip *msm_chip = irq_data_get_irq_chip_data(d);
unsigned offset = d->irq - gpio_to_irq(msm_chip->chip.base);
spin_lock_irqsave(&msm_chip->lock, irq_flags);
if (on)
msm_chip->int_enable[1] |= BIT(offset);
else
msm_chip->int_enable[1] &= ~BIT(offset);
spin_unlock_irqrestore(&msm_chip->lock, irq_flags);
return 0;
}
static int msm_gpio_irq_set_type(struct irq_data *d, unsigned int flow_type)
{
unsigned long irq_flags;
struct msm_gpio_chip *msm_chip = irq_data_get_irq_chip_data(d);
unsigned offset = d->irq - gpio_to_irq(msm_chip->chip.base);
unsigned val, mask = BIT(offset);
spin_lock_irqsave(&msm_chip->lock, irq_flags);
val = msm_gpio_readl(msm_chip, MSM_GPIO_INT_EDGE);
if (flow_type & IRQ_TYPE_EDGE_BOTH) {
msm_gpio_writel(msm_chip, val | mask, MSM_GPIO_INT_EDGE);
__irq_set_handler_locked(d->irq, handle_edge_irq);
} else {
msm_gpio_writel(msm_chip, val & ~mask, MSM_GPIO_INT_EDGE);
__irq_set_handler_locked(d->irq, handle_level_irq);
}
if ((flow_type & IRQ_TYPE_EDGE_BOTH) == IRQ_TYPE_EDGE_BOTH) {
msm_chip->both_edge_detect |= mask;
msm_gpio_update_both_edge_detect(msm_chip);
} else {
msm_chip->both_edge_detect &= ~mask;
val = msm_gpio_readl(msm_chip, MSM_GPIO_INT_POS);
if (flow_type & (IRQF_TRIGGER_RISING | IRQF_TRIGGER_HIGH))
val |= mask;
else
val &= ~mask;
msm_gpio_writel(msm_chip, val, MSM_GPIO_INT_POS);
}
spin_unlock_irqrestore(&msm_chip->lock, irq_flags);
return 0;
}
static void msm_gpio_irq_handler(unsigned int irq, struct irq_desc *desc)
{
int i, j, mask;
unsigned val;
for (i = 0; i < msm_gpio_count; i++) {
struct msm_gpio_chip *msm_chip = &msm_gpio_chips[i];
val = msm_gpio_readl(msm_chip, MSM_GPIO_INT_STATUS);
val &= msm_chip->int_enable[0];
while (val) {
mask = val & -val;
j = fls(mask) - 1;
val &= ~mask;
generic_handle_irq(FIRST_GPIO_IRQ +
msm_chip->chip.base + j);
}
}
desc->irq_data.chip->irq_ack(&desc->irq_data);
}
static int gpio_msm_v1_probe(struct platform_device *pdev)
{
int i, j = 0;
const struct platform_device_id *dev_id = platform_get_device_id(pdev);
struct msm_gpio_initdata *data;
int irq1, irq2;
struct resource *res;
void __iomem *base1, __iomem *base2;
data = (struct msm_gpio_initdata *)dev_id->driver_data;
msm_gpio_chips = data->chips;
msm_gpio_count = data->count;
irq1 = platform_get_irq(pdev, 0);
if (irq1 < 0)
return irq1;
irq2 = platform_get_irq(pdev, 1);
if (irq2 < 0)
return irq2;
res = platform_get_resource(pdev, IORESOURCE_MEM, 0);
base1 = devm_ioremap_resource(&pdev->dev, res);
if (IS_ERR(base1))
return PTR_ERR(base1);
res = platform_get_resource(pdev, IORESOURCE_MEM, 1);
base2 = devm_ioremap_resource(&pdev->dev, res);
if (IS_ERR(base2))
return PTR_ERR(base2);
for (i = FIRST_GPIO_IRQ; i < FIRST_GPIO_IRQ + NR_GPIO_IRQS; i++) {
if (i - FIRST_GPIO_IRQ >=
msm_gpio_chips[j].chip.base +
msm_gpio_chips[j].chip.ngpio)
j++;
irq_set_chip_data(i, &msm_gpio_chips[j]);
irq_set_chip_and_handler(i, &msm_gpio_irq_chip,
handle_edge_irq);
set_irq_flags(i, IRQF_VALID);
}
for (i = 0; i < msm_gpio_count; i++) {
if (i == 1)
msm_gpio_chips[i].base = base2;
else
msm_gpio_chips[i].base = base1;
spin_lock_init(&msm_gpio_chips[i].lock);
msm_gpio_writel(&msm_gpio_chips[i], 0, MSM_GPIO_INT_EN);
gpiochip_add(&msm_gpio_chips[i].chip);
}
irq_set_chained_handler(irq1, msm_gpio_irq_handler);
irq_set_chained_handler(irq2, msm_gpio_irq_handler);
irq_set_irq_wake(irq1, 1);
irq_set_irq_wake(irq2, 1);
return 0;
}
static int __init gpio_msm_v1_init(void)
{
return platform_driver_register(&gpio_msm_v1_driver);
}
