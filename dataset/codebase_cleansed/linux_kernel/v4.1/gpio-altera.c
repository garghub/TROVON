static void altera_gpio_irq_unmask(struct irq_data *d)
{
struct altera_gpio_chip *altera_gc;
struct of_mm_gpio_chip *mm_gc;
unsigned long flags;
u32 intmask;
altera_gc = irq_data_get_irq_chip_data(d);
mm_gc = &altera_gc->mmchip;
spin_lock_irqsave(&altera_gc->gpio_lock, flags);
intmask = readl(mm_gc->regs + ALTERA_GPIO_IRQ_MASK);
intmask |= BIT(irqd_to_hwirq(d));
writel(intmask, mm_gc->regs + ALTERA_GPIO_IRQ_MASK);
spin_unlock_irqrestore(&altera_gc->gpio_lock, flags);
}
static void altera_gpio_irq_mask(struct irq_data *d)
{
struct altera_gpio_chip *altera_gc;
struct of_mm_gpio_chip *mm_gc;
unsigned long flags;
u32 intmask;
altera_gc = irq_data_get_irq_chip_data(d);
mm_gc = &altera_gc->mmchip;
spin_lock_irqsave(&altera_gc->gpio_lock, flags);
intmask = readl(mm_gc->regs + ALTERA_GPIO_IRQ_MASK);
intmask &= ~BIT(irqd_to_hwirq(d));
writel(intmask, mm_gc->regs + ALTERA_GPIO_IRQ_MASK);
spin_unlock_irqrestore(&altera_gc->gpio_lock, flags);
}
static int altera_gpio_irq_set_type(struct irq_data *d,
unsigned int type)
{
struct altera_gpio_chip *altera_gc;
altera_gc = irq_data_get_irq_chip_data(d);
if (type == IRQ_TYPE_NONE)
return 0;
if (type == IRQ_TYPE_LEVEL_HIGH &&
altera_gc->interrupt_trigger == IRQ_TYPE_LEVEL_HIGH)
return 0;
if (type == IRQ_TYPE_EDGE_RISING &&
altera_gc->interrupt_trigger == IRQ_TYPE_EDGE_RISING)
return 0;
if (type == IRQ_TYPE_EDGE_FALLING &&
altera_gc->interrupt_trigger == IRQ_TYPE_EDGE_FALLING)
return 0;
if (type == IRQ_TYPE_EDGE_BOTH &&
altera_gc->interrupt_trigger == IRQ_TYPE_EDGE_BOTH)
return 0;
return -EINVAL;
}
static unsigned int altera_gpio_irq_startup(struct irq_data *d) {
altera_gpio_irq_unmask(d);
return 0;
}
static int altera_gpio_get(struct gpio_chip *gc, unsigned offset)
{
struct of_mm_gpio_chip *mm_gc;
mm_gc = to_of_mm_gpio_chip(gc);
return !!(readl(mm_gc->regs + ALTERA_GPIO_DATA) & BIT(offset));
}
static void altera_gpio_set(struct gpio_chip *gc, unsigned offset, int value)
{
struct of_mm_gpio_chip *mm_gc;
struct altera_gpio_chip *chip;
unsigned long flags;
unsigned int data_reg;
mm_gc = to_of_mm_gpio_chip(gc);
chip = container_of(mm_gc, struct altera_gpio_chip, mmchip);
spin_lock_irqsave(&chip->gpio_lock, flags);
data_reg = readl(mm_gc->regs + ALTERA_GPIO_DATA);
if (value)
data_reg |= BIT(offset);
else
data_reg &= ~BIT(offset);
writel(data_reg, mm_gc->regs + ALTERA_GPIO_DATA);
spin_unlock_irqrestore(&chip->gpio_lock, flags);
}
static int altera_gpio_direction_input(struct gpio_chip *gc, unsigned offset)
{
struct of_mm_gpio_chip *mm_gc;
struct altera_gpio_chip *chip;
unsigned long flags;
unsigned int gpio_ddr;
mm_gc = to_of_mm_gpio_chip(gc);
chip = container_of(mm_gc, struct altera_gpio_chip, mmchip);
spin_lock_irqsave(&chip->gpio_lock, flags);
gpio_ddr = readl(mm_gc->regs + ALTERA_GPIO_DIR);
gpio_ddr &= ~BIT(offset);
writel(gpio_ddr, mm_gc->regs + ALTERA_GPIO_DIR);
spin_unlock_irqrestore(&chip->gpio_lock, flags);
return 0;
}
static int altera_gpio_direction_output(struct gpio_chip *gc,
unsigned offset, int value)
{
struct of_mm_gpio_chip *mm_gc;
struct altera_gpio_chip *chip;
unsigned long flags;
unsigned int data_reg, gpio_ddr;
mm_gc = to_of_mm_gpio_chip(gc);
chip = container_of(mm_gc, struct altera_gpio_chip, mmchip);
spin_lock_irqsave(&chip->gpio_lock, flags);
data_reg = readl(mm_gc->regs + ALTERA_GPIO_DATA);
if (value)
data_reg |= BIT(offset);
else
data_reg &= ~BIT(offset);
writel(data_reg, mm_gc->regs + ALTERA_GPIO_DATA);
gpio_ddr = readl(mm_gc->regs + ALTERA_GPIO_DIR);
gpio_ddr |= BIT(offset);
writel(gpio_ddr, mm_gc->regs + ALTERA_GPIO_DIR);
spin_unlock_irqrestore(&chip->gpio_lock, flags);
return 0;
}
static void altera_gpio_irq_edge_handler(unsigned int irq,
struct irq_desc *desc)
{
struct altera_gpio_chip *altera_gc;
struct irq_chip *chip;
struct of_mm_gpio_chip *mm_gc;
struct irq_domain *irqdomain;
unsigned long status;
int i;
altera_gc = irq_desc_get_handler_data(desc);
chip = irq_desc_get_chip(desc);
mm_gc = &altera_gc->mmchip;
irqdomain = altera_gc->mmchip.gc.irqdomain;
chained_irq_enter(chip, desc);
while ((status =
(readl(mm_gc->regs + ALTERA_GPIO_EDGE_CAP) &
readl(mm_gc->regs + ALTERA_GPIO_IRQ_MASK)))) {
writel(status, mm_gc->regs + ALTERA_GPIO_EDGE_CAP);
for_each_set_bit(i, &status, mm_gc->gc.ngpio) {
generic_handle_irq(irq_find_mapping(irqdomain, i));
}
}
chained_irq_exit(chip, desc);
}
static void altera_gpio_irq_leveL_high_handler(unsigned int irq,
struct irq_desc *desc)
{
struct altera_gpio_chip *altera_gc;
struct irq_chip *chip;
struct of_mm_gpio_chip *mm_gc;
struct irq_domain *irqdomain;
unsigned long status;
int i;
altera_gc = irq_desc_get_handler_data(desc);
chip = irq_desc_get_chip(desc);
mm_gc = &altera_gc->mmchip;
irqdomain = altera_gc->mmchip.gc.irqdomain;
chained_irq_enter(chip, desc);
status = readl(mm_gc->regs + ALTERA_GPIO_DATA);
status &= readl(mm_gc->regs + ALTERA_GPIO_IRQ_MASK);
for_each_set_bit(i, &status, mm_gc->gc.ngpio) {
generic_handle_irq(irq_find_mapping(irqdomain, i));
}
chained_irq_exit(chip, desc);
}
static int altera_gpio_probe(struct platform_device *pdev)
{
struct device_node *node = pdev->dev.of_node;
int reg, ret;
struct altera_gpio_chip *altera_gc;
altera_gc = devm_kzalloc(&pdev->dev, sizeof(*altera_gc), GFP_KERNEL);
if (!altera_gc)
return -ENOMEM;
spin_lock_init(&altera_gc->gpio_lock);
if (of_property_read_u32(node, "altr,ngpio", &reg))
altera_gc->mmchip.gc.ngpio = ALTERA_GPIO_MAX_NGPIO;
else
altera_gc->mmchip.gc.ngpio = reg;
if (altera_gc->mmchip.gc.ngpio > ALTERA_GPIO_MAX_NGPIO) {
dev_warn(&pdev->dev,
"ngpio is greater than %d, defaulting to %d\n",
ALTERA_GPIO_MAX_NGPIO, ALTERA_GPIO_MAX_NGPIO);
altera_gc->mmchip.gc.ngpio = ALTERA_GPIO_MAX_NGPIO;
}
altera_gc->mmchip.gc.direction_input = altera_gpio_direction_input;
altera_gc->mmchip.gc.direction_output = altera_gpio_direction_output;
altera_gc->mmchip.gc.get = altera_gpio_get;
altera_gc->mmchip.gc.set = altera_gpio_set;
altera_gc->mmchip.gc.owner = THIS_MODULE;
altera_gc->mmchip.gc.dev = &pdev->dev;
ret = of_mm_gpiochip_add(node, &altera_gc->mmchip);
if (ret) {
dev_err(&pdev->dev, "Failed adding memory mapped gpiochip\n");
return ret;
}
platform_set_drvdata(pdev, altera_gc);
altera_gc->mapped_irq = platform_get_irq(pdev, 0);
if (altera_gc->mapped_irq < 0)
goto skip_irq;
if (of_property_read_u32(node, "altr,interrupt-type", &reg)) {
ret = -EINVAL;
dev_err(&pdev->dev,
"altr,interrupt-type value not set in device tree\n");
goto teardown;
}
altera_gc->interrupt_trigger = reg;
ret = gpiochip_irqchip_add(&altera_gc->mmchip.gc, &altera_irq_chip, 0,
handle_simple_irq, IRQ_TYPE_NONE);
if (ret) {
dev_info(&pdev->dev, "could not add irqchip\n");
return ret;
}
gpiochip_set_chained_irqchip(&altera_gc->mmchip.gc,
&altera_irq_chip,
altera_gc->mapped_irq,
altera_gc->interrupt_trigger == IRQ_TYPE_LEVEL_HIGH ?
altera_gpio_irq_leveL_high_handler :
altera_gpio_irq_edge_handler);
skip_irq:
return 0;
teardown:
pr_err("%s: registration failed with status %d\n",
node->full_name, ret);
return ret;
}
static int altera_gpio_remove(struct platform_device *pdev)
{
struct altera_gpio_chip *altera_gc = platform_get_drvdata(pdev);
gpiochip_remove(&altera_gc->mmchip.gc);
return -EIO;
}
static int __init altera_gpio_init(void)
{
return platform_driver_register(&altera_gpio_driver);
}
static void __exit altera_gpio_exit(void)
{
platform_driver_unregister(&altera_gpio_driver);
}
