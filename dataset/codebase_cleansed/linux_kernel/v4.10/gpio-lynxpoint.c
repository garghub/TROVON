static unsigned long lp_gpio_reg(struct gpio_chip *chip, unsigned offset,
int reg)
{
struct lp_gpio *lg = gpiochip_get_data(chip);
int reg_offset;
if (reg == LP_CONFIG1 || reg == LP_CONFIG2)
reg_offset = offset * 8;
else
reg_offset = (offset / 32) * 4;
return lg->reg_base + reg + reg_offset;
}
static int lp_gpio_request(struct gpio_chip *chip, unsigned offset)
{
struct lp_gpio *lg = gpiochip_get_data(chip);
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
struct lp_gpio *lg = gpiochip_get_data(chip);
unsigned long conf2 = lp_gpio_reg(chip, offset, LP_CONFIG2);
outl(inl(conf2) | GPINDIS_BIT, conf2);
pm_runtime_put(&lg->pdev->dev);
}
static int lp_irq_type(struct irq_data *d, unsigned type)
{
struct gpio_chip *gc = irq_data_get_irq_chip_data(d);
struct lp_gpio *lg = gpiochip_get_data(gc);
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
return !!(inl(reg) & IN_LVL_BIT);
}
static void lp_gpio_set(struct gpio_chip *chip, unsigned offset, int value)
{
struct lp_gpio *lg = gpiochip_get_data(chip);
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
struct lp_gpio *lg = gpiochip_get_data(chip);
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
struct lp_gpio *lg = gpiochip_get_data(chip);
unsigned long reg = lp_gpio_reg(chip, offset, LP_CONFIG1);
unsigned long flags;
lp_gpio_set(chip, offset, value);
spin_lock_irqsave(&lg->lock, flags);
outl(inl(reg) & ~DIR_BIT, reg);
spin_unlock_irqrestore(&lg->lock, flags);
return 0;
}
static void lp_gpio_irq_handler(struct irq_desc *desc)
{
struct irq_data *data = irq_desc_get_irq_data(desc);
struct gpio_chip *gc = irq_desc_get_handler_data(desc);
struct lp_gpio *lg = gpiochip_get_data(gc);
struct irq_chip *chip = irq_data_get_irq_chip(data);
u32 base, pin, mask;
unsigned long reg, ena, pending;
for (base = 0; base < lg->chip.ngpio; base += 32) {
reg = lp_gpio_reg(&lg->chip, base, LP_INT_STAT);
ena = lp_gpio_reg(&lg->chip, base, LP_INT_ENABLE);
while ((pending = (inl(reg) & inl(ena)))) {
unsigned irq;
pin = __ffs(pending);
mask = BIT(pin);
outl(mask, reg);
irq = irq_find_mapping(lg->chip.irqdomain, base + pin);
generic_handle_irq(irq);
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
struct gpio_chip *gc = irq_data_get_irq_chip_data(d);
struct lp_gpio *lg = gpiochip_get_data(gc);
u32 hwirq = irqd_to_hwirq(d);
unsigned long reg = lp_gpio_reg(&lg->chip, hwirq, LP_INT_ENABLE);
unsigned long flags;
spin_lock_irqsave(&lg->lock, flags);
outl(inl(reg) | BIT(hwirq % 32), reg);
spin_unlock_irqrestore(&lg->lock, flags);
}
static void lp_irq_disable(struct irq_data *d)
{
struct gpio_chip *gc = irq_data_get_irq_chip_data(d);
struct lp_gpio *lg = gpiochip_get_data(gc);
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
static int lp_gpio_probe(struct platform_device *pdev)
{
struct lp_gpio *lg;
struct gpio_chip *gc;
struct resource *io_rc, *irq_rc;
struct device *dev = &pdev->dev;
unsigned long reg_len;
int ret = -ENODEV;
lg = devm_kzalloc(dev, sizeof(struct lp_gpio), GFP_KERNEL);
if (!lg)
return -ENOMEM;
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
gc->can_sleep = false;
gc->parent = dev;
ret = devm_gpiochip_add_data(dev, gc, lg);
if (ret) {
dev_err(dev, "failed adding lp-gpio chip\n");
return ret;
}
if (irq_rc && irq_rc->start) {
lp_gpio_irq_init_hw(lg);
ret = gpiochip_irqchip_add(gc, &lp_irqchip, 0,
handle_simple_irq, IRQ_TYPE_NONE);
if (ret) {
dev_err(dev, "failed to add irqchip\n");
return ret;
}
gpiochip_set_chained_irqchip(gc, &lp_irqchip,
(unsigned)irq_rc->start,
lp_gpio_irq_handler);
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
static int lp_gpio_resume(struct device *dev)
{
struct platform_device *pdev = to_platform_device(dev);
struct lp_gpio *lg = platform_get_drvdata(pdev);
unsigned long reg;
int i;
for (i = 0; i < lg->chip.ngpio; i++) {
if (gpiochip_is_requested(&lg->chip, i) != NULL) {
reg = lp_gpio_reg(&lg->chip, i, LP_CONFIG2);
outl(inl(reg) & ~GPINDIS_BIT, reg);
}
}
return 0;
}
static int lp_gpio_remove(struct platform_device *pdev)
{
pm_runtime_disable(&pdev->dev);
return 0;
}
static int __init lp_gpio_init(void)
{
return platform_driver_register(&lp_gpio_driver);
}
static void __exit lp_gpio_exit(void)
{
platform_driver_unregister(&lp_gpio_driver);
}
