static int msm_gpio_write(struct msm_gpio_chip *msm_chip,
unsigned offset, unsigned on)
{
unsigned mask = BIT(offset);
unsigned val;
val = readl(msm_chip->regs.out);
if (on)
writel(val | mask, msm_chip->regs.out);
else
writel(val & ~mask, msm_chip->regs.out);
return 0;
}
static void msm_gpio_update_both_edge_detect(struct msm_gpio_chip *msm_chip)
{
int loop_limit = 100;
unsigned pol, val, val2, intstat;
do {
val = readl(msm_chip->regs.in);
pol = readl(msm_chip->regs.int_pos);
pol = (pol & ~msm_chip->both_edge_detect) |
(~val & msm_chip->both_edge_detect);
writel(pol, msm_chip->regs.int_pos);
intstat = readl(msm_chip->regs.int_status);
val2 = readl(msm_chip->regs.in);
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
msm_chip->int_status_copy |= readl(msm_chip->regs.int_status);
msm_chip->int_status_copy &= ~bit;
#endif
writel(bit, msm_chip->regs.int_clear);
msm_gpio_update_both_edge_detect(msm_chip);
return 0;
}
static int msm_gpio_direction_input(struct gpio_chip *chip, unsigned offset)
{
struct msm_gpio_chip *msm_chip;
unsigned long irq_flags;
msm_chip = container_of(chip, struct msm_gpio_chip, chip);
spin_lock_irqsave(&msm_chip->lock, irq_flags);
writel(readl(msm_chip->regs.oe) & ~BIT(offset), msm_chip->regs.oe);
spin_unlock_irqrestore(&msm_chip->lock, irq_flags);
return 0;
}
static int
msm_gpio_direction_output(struct gpio_chip *chip, unsigned offset, int value)
{
struct msm_gpio_chip *msm_chip;
unsigned long irq_flags;
msm_chip = container_of(chip, struct msm_gpio_chip, chip);
spin_lock_irqsave(&msm_chip->lock, irq_flags);
msm_gpio_write(msm_chip, offset, value);
writel(readl(msm_chip->regs.oe) | BIT(offset), msm_chip->regs.oe);
spin_unlock_irqrestore(&msm_chip->lock, irq_flags);
return 0;
}
static int msm_gpio_get(struct gpio_chip *chip, unsigned offset)
{
struct msm_gpio_chip *msm_chip;
msm_chip = container_of(chip, struct msm_gpio_chip, chip);
return (readl(msm_chip->regs.in) & (1U << offset)) ? 1 : 0;
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
if (!(readl(msm_chip->regs.int_edge) & BIT(offset)))
msm_gpio_clear_detect_status(msm_chip, offset);
msm_chip->int_enable[0] &= ~BIT(offset);
writel(msm_chip->int_enable[0], msm_chip->regs.int_en);
spin_unlock_irqrestore(&msm_chip->lock, irq_flags);
}
static void msm_gpio_irq_unmask(struct irq_data *d)
{
unsigned long irq_flags;
struct msm_gpio_chip *msm_chip = irq_data_get_irq_chip_data(d);
unsigned offset = d->irq - gpio_to_irq(msm_chip->chip.base);
spin_lock_irqsave(&msm_chip->lock, irq_flags);
if (!(readl(msm_chip->regs.int_edge) & BIT(offset)))
msm_gpio_clear_detect_status(msm_chip, offset);
msm_chip->int_enable[0] |= BIT(offset);
writel(msm_chip->int_enable[0], msm_chip->regs.int_en);
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
val = readl(msm_chip->regs.int_edge);
if (flow_type & IRQ_TYPE_EDGE_BOTH) {
writel(val | mask, msm_chip->regs.int_edge);
__irq_set_handler_locked(d->irq, handle_edge_irq);
} else {
writel(val & ~mask, msm_chip->regs.int_edge);
__irq_set_handler_locked(d->irq, handle_level_irq);
}
if ((flow_type & IRQ_TYPE_EDGE_BOTH) == IRQ_TYPE_EDGE_BOTH) {
msm_chip->both_edge_detect |= mask;
msm_gpio_update_both_edge_detect(msm_chip);
} else {
msm_chip->both_edge_detect &= ~mask;
val = readl(msm_chip->regs.int_pos);
if (flow_type & (IRQF_TRIGGER_RISING | IRQF_TRIGGER_HIGH))
writel(val | mask, msm_chip->regs.int_pos);
else
writel(val & ~mask, msm_chip->regs.int_pos);
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
val = readl(msm_chip->regs.int_status);
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
static int __init msm_init_gpio(void)
{
int i, j = 0;
if (cpu_is_msm7x01()) {
msm_gpio_chips = msm_gpio_chips_msm7x01;
msm_gpio_count = ARRAY_SIZE(msm_gpio_chips_msm7x01);
} else if (cpu_is_msm7x30()) {
msm_gpio_chips = msm_gpio_chips_msm7x30;
msm_gpio_count = ARRAY_SIZE(msm_gpio_chips_msm7x30);
} else if (cpu_is_qsd8x50()) {
msm_gpio_chips = msm_gpio_chips_qsd8x50;
msm_gpio_count = ARRAY_SIZE(msm_gpio_chips_qsd8x50);
} else {
return 0;
}
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
spin_lock_init(&msm_gpio_chips[i].lock);
writel(0, msm_gpio_chips[i].regs.int_en);
gpiochip_add(&msm_gpio_chips[i].chip);
}
irq_set_chained_handler(INT_GPIO_GROUP1, msm_gpio_irq_handler);
irq_set_chained_handler(INT_GPIO_GROUP2, msm_gpio_irq_handler);
irq_set_irq_wake(INT_GPIO_GROUP1, 1);
irq_set_irq_wake(INT_GPIO_GROUP2, 2);
return 0;
}
