static unsigned long lp_gpio_reg(struct gpio_chip *chip, unsigned offset,
int reg)
{
struct lp_gpio *lg = container_of(chip, struct lp_gpio, chip);
int reg_offset;
if (reg == LP_CONFIG1 || reg == LP_CONFIG2)
reg_offset = offset * 8;
else
reg_offset = (offset / 32) * 4;
return lg->reg_base + reg + reg_offset;
}
static int lp_gpio_request(struct gpio_chip *chip, unsigned offset)
{
struct lp_gpio *lg = container_of(chip, struct lp_gpio, chip);
unsigned long reg = lp_gpio_reg(chip, offset, LP_CONFIG1);
unsigned long conf2 = lp_gpio_reg(chip, offset, LP_CONFIG2);
unsigned long acpi_use = lp_gpio_reg(chip, offset, LP_ACPI_OWNED);
pm_runtime_get(&lg->pdev->dev);
if (!(inl(acpi_use) & BIT(offset % 32))) {
dev_err(&lg->pdev->dev, "gpio %d reserved for ACPI\n", offset);
return -EBUSY;
}
if (!(inl(reg) & USE_SEL_BIT))
return -ENODEV;
outl(inl(conf2) & ~GPINDIS_BIT, conf2);
return 0;
}
static void lp_gpio_free(struct gpio_chip *chip, unsigned offset)
{
struct lp_gpio *lg = container_of(chip, struct lp_gpio, chip);
unsigned long conf2 = lp_gpio_reg(chip, offset, LP_CONFIG2);
outl(inl(conf2) | GPINDIS_BIT, conf2);
pm_runtime_put(&lg->pdev->dev);
}
static int lp_irq_type(struct irq_data *d, unsigned type)
{
struct lp_gpio *lg = irq_data_get_irq_chip_data(d);
u32 hwirq = irqd_to_hwirq(d);
unsigned long flags;
u32 value;
unsigned long reg = lp_gpio_reg(&lg->chip, hwirq, LP_CONFIG1);
if (hwirq >= lg->chip.ngpio)
return -EINVAL;
spin_lock_irqsave(&lg->lock, flags);
value = inl(reg);
if (type & IRQ_TYPE_EDGE_RISING)
value &= ~(TRIG_SEL_BIT | INT_INV_BIT);
if (type & IRQ_TYPE_EDGE_FALLING)
value = (value | INT_INV_BIT) & ~TRIG_SEL_BIT;
if (type & IRQ_TYPE_LEVEL_LOW)
value = (value | TRIG_SEL_BIT) & ~INT_INV_BIT;
if (type & IRQ_TYPE_LEVEL_HIGH)
value |= TRIG_SEL_BIT | INT_INV_BIT;
outl(value, reg);
spin_unlock_irqrestore(&lg->lock, flags);
return 0;
}
static int lp_gpio_get(struct gpio_chip *chip, unsigned offset)
{
unsigned long reg = lp_gpio_reg(chip, offset, LP_CONFIG1);
return inl(reg) & IN_LVL_BIT;
}
static void lp_gpio_set(struct gpio_chip *chip, unsigned offset, int value)
{
struct lp_gpio *lg = container_of(chip, struct lp_gpio, chip);
unsigned long reg = lp_gpio_reg(chip, offset, LP_CONFIG1);
unsigned long flags;
spin_lock_irqsave(&lg->lock, flags);
if (value)
outl(inl(reg) | OUT_LVL_BIT, reg);
else
outl(inl(reg) & ~OUT_LVL_BIT, reg);
spin_unlock_irqrestore(&lg->lock, flags);
}
static int lp_gpio_direction_input(struct gpio_chip *chip, unsigned offset)
{
struct lp_gpio *lg = container_of(chip, struct lp_gpio, chip);
unsigned long reg = lp_gpio_reg(chip, offset, LP_CONFIG1);
unsigned long flags;
spin_lock_irqsave(&lg->lock, flags);
outl(inl(reg) | DIR_BIT, reg);
spin_unlock_irqrestore(&lg->lock, flags);
return 0;
}
static int lp_gpio_direction_output(struct gpio_chip *chip,
unsigned offset, int value)
{
struct lp_gpio *lg = container_of(chip, struct lp_gpio, chip);
unsigned long reg = lp_gpio_reg(chip, offset, LP_CONFIG1);
unsigned long flags;
lp_gpio_set(chip, offset, value);
spin_lock_irqsave(&lg->lock, flags);
outl(inl(reg) & ~DIR_BIT, reg);
spin_unlock_irqrestore(&lg->lock, flags);
return 0;
}
static int lp_gpio_to_irq(struct gpio_chip *chip, unsigned offset)
{
struct lp_gpio *lg = container_of(chip, struct lp_gpio, chip);
return irq_create_mapping(lg->domain, offset);
}
static void lp_gpio_irq_handler(unsigned irq, struct irq_desc *desc)
{
struct irq_data *data = irq_desc_get_irq_data(desc);
struct lp_gpio *lg = irq_data_get_irq_handler_data(data);
struct irq_chip *chip = irq_data_get_irq_chip(data);
u32 base, pin, mask;
unsigned long reg, pending;
unsigned virq;
for (base = 0; base < lg->chip.ngpio; base += 32) {
reg = lp_gpio_reg(&lg->chip, base, LP_INT_STAT);
while ((pending = inl(reg))) {
pin = __ffs(pending);
mask = BIT(pin);
outl(mask, reg);
virq = irq_find_mapping(lg->domain, base + pin);
generic_handle_irq(virq);
}
}
chip->irq_eoi(data);
}
static void lp_irq_unmask(struct irq_data *d)
{
}
static void lp_irq_mask(struct irq_data *d)
{
}
static void lp_irq_enable(struct irq_data *d)
{
struct lp_gpio *lg = irq_data_get_irq_chip_data(d);
u32 hwirq = irqd_to_hwirq(d);
unsigned long reg = lp_gpio_reg(&lg->chip, hwirq, LP_INT_ENABLE);
unsigned long flags;
spin_lock_irqsave(&lg->lock, flags);
outl(inl(reg) | BIT(hwirq % 32), reg);
spin_unlock_irqrestore(&lg->lock, flags);
}
static void lp_irq_disable(struct irq_data *d)
{
struct lp_gpio *lg = irq_data_get_irq_chip_data(d);
u32 hwirq = irqd_to_hwirq(d);
unsigned long reg = lp_gpio_reg(&lg->chip, hwirq, LP_INT_ENABLE);
unsigned long flags;
spin_lock_irqsave(&lg->lock, flags);
outl(inl(reg) & ~BIT(hwirq % 32), reg);
spin_unlock_irqrestore(&lg->lock, flags);
}
static void lp_gpio_irq_init_hw(struct lp_gpio *lg)
{
unsigned long reg;
unsigned base;
for (base = 0; base < lg->chip.ngpio; base += 32) {
reg = lp_gpio_reg(&lg->chip, base, LP_INT_ENABLE);
outl(0, reg);
reg = lp_gpio_reg(&lg->chip, base, LP_INT_STAT);
outl(0xffffffff, reg);
}
}
static int lp_gpio_irq_map(struct irq_domain *d, unsigned int virq,
irq_hw_number_t hw)
{
struct lp_gpio *lg = d->host_data;
irq_set_chip_and_handler_name(virq, &lp_irqchip, handle_simple_irq,
"demux");
irq_set_chip_data(virq, lg);
irq_set_irq_type(virq, IRQ_TYPE_NONE);
return 0;
}
static int lp_gpio_probe(struct platform_device *pdev)
{
struct lp_gpio *lg;
struct gpio_chip *gc;
struct resource *io_rc, *irq_rc;
struct device *dev = &pdev->dev;
unsigned long reg_len;
unsigned hwirq;
int ret = -ENODEV;
lg = devm_kzalloc(dev, sizeof(struct lp_gpio), GFP_KERNEL);
if (!lg) {
dev_err(dev, "can't allocate lp_gpio chip data\n");
return -ENOMEM;
}
lg->pdev = pdev;
platform_set_drvdata(pdev, lg);
io_rc = platform_get_resource(pdev, IORESOURCE_IO, 0);
irq_rc = platform_get_resource(pdev, IORESOURCE_IRQ, 0);
if (!io_rc) {
dev_err(dev, "missing IO resources\n");
return -EINVAL;
}
lg->reg_base = io_rc->start;
reg_len = resource_size(io_rc);
if (!devm_request_region(dev, lg->reg_base, reg_len, "lp-gpio")) {
dev_err(dev, "failed requesting IO region 0x%x\n",
(unsigned int)lg->reg_base);
return -EBUSY;
}
spin_lock_init(&lg->lock);
gc = &lg->chip;
gc->label = dev_name(dev);
gc->owner = THIS_MODULE;
gc->request = lp_gpio_request;
gc->free = lp_gpio_free;
gc->direction_input = lp_gpio_direction_input;
gc->direction_output = lp_gpio_direction_output;
gc->get = lp_gpio_get;
gc->set = lp_gpio_set;
gc->base = -1;
gc->ngpio = LP_NUM_GPIO;
gc->can_sleep = 0;
gc->dev = dev;
if (irq_rc && irq_rc->start) {
hwirq = irq_rc->start;
gc->to_irq = lp_gpio_to_irq;
lg->domain = irq_domain_add_linear(NULL, LP_NUM_GPIO,
&lp_gpio_irq_ops, lg);
if (!lg->domain)
return -ENXIO;
lp_gpio_irq_init_hw(lg);
irq_set_handler_data(hwirq, lg);
irq_set_chained_handler(hwirq, lp_gpio_irq_handler);
}
ret = gpiochip_add(gc);
if (ret) {
dev_err(dev, "failed adding lp-gpio chip\n");
return ret;
}
pm_runtime_enable(dev);
return 0;
}
static int lp_gpio_runtime_suspend(struct device *dev)
{
return 0;
}
static int lp_gpio_runtime_resume(struct device *dev)
{
return 0;
}
static int lp_gpio_remove(struct platform_device *pdev)
{
struct lp_gpio *lg = platform_get_drvdata(pdev);
int err;
err = gpiochip_remove(&lg->chip);
if (err)
dev_warn(&pdev->dev, "failed to remove gpio_chip.\n");
return 0;
}
static int __init lp_gpio_init(void)
{
return platform_driver_register(&lp_gpio_driver);
}
