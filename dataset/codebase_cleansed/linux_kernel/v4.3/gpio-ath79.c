static void __ath79_gpio_set_value(unsigned gpio, int value)
{
void __iomem *base = ath79_gpio_base;
if (value)
__raw_writel(1 << gpio, base + AR71XX_GPIO_REG_SET);
else
__raw_writel(1 << gpio, base + AR71XX_GPIO_REG_CLEAR);
}
static int __ath79_gpio_get_value(unsigned gpio)
{
return (__raw_readl(ath79_gpio_base + AR71XX_GPIO_REG_IN) >> gpio) & 1;
}
static int ath79_gpio_get_value(struct gpio_chip *chip, unsigned offset)
{
return __ath79_gpio_get_value(offset);
}
static void ath79_gpio_set_value(struct gpio_chip *chip,
unsigned offset, int value)
{
__ath79_gpio_set_value(offset, value);
}
static int ath79_gpio_direction_input(struct gpio_chip *chip,
unsigned offset)
{
void __iomem *base = ath79_gpio_base;
unsigned long flags;
spin_lock_irqsave(&ath79_gpio_lock, flags);
__raw_writel(__raw_readl(base + AR71XX_GPIO_REG_OE) & ~(1 << offset),
base + AR71XX_GPIO_REG_OE);
spin_unlock_irqrestore(&ath79_gpio_lock, flags);
return 0;
}
static int ath79_gpio_direction_output(struct gpio_chip *chip,
unsigned offset, int value)
{
void __iomem *base = ath79_gpio_base;
unsigned long flags;
spin_lock_irqsave(&ath79_gpio_lock, flags);
if (value)
__raw_writel(1 << offset, base + AR71XX_GPIO_REG_SET);
else
__raw_writel(1 << offset, base + AR71XX_GPIO_REG_CLEAR);
__raw_writel(__raw_readl(base + AR71XX_GPIO_REG_OE) | (1 << offset),
base + AR71XX_GPIO_REG_OE);
spin_unlock_irqrestore(&ath79_gpio_lock, flags);
return 0;
}
static int ar934x_gpio_direction_input(struct gpio_chip *chip, unsigned offset)
{
void __iomem *base = ath79_gpio_base;
unsigned long flags;
spin_lock_irqsave(&ath79_gpio_lock, flags);
__raw_writel(__raw_readl(base + AR71XX_GPIO_REG_OE) | (1 << offset),
base + AR71XX_GPIO_REG_OE);
spin_unlock_irqrestore(&ath79_gpio_lock, flags);
return 0;
}
static int ar934x_gpio_direction_output(struct gpio_chip *chip, unsigned offset,
int value)
{
void __iomem *base = ath79_gpio_base;
unsigned long flags;
spin_lock_irqsave(&ath79_gpio_lock, flags);
if (value)
__raw_writel(1 << offset, base + AR71XX_GPIO_REG_SET);
else
__raw_writel(1 << offset, base + AR71XX_GPIO_REG_CLEAR);
__raw_writel(__raw_readl(base + AR71XX_GPIO_REG_OE) & ~(1 << offset),
base + AR71XX_GPIO_REG_OE);
spin_unlock_irqrestore(&ath79_gpio_lock, flags);
return 0;
}
static int ath79_gpio_probe(struct platform_device *pdev)
{
struct ath79_gpio_platform_data *pdata = pdev->dev.platform_data;
struct device_node *np = pdev->dev.of_node;
struct resource *res;
bool oe_inverted;
int err;
if (np) {
err = of_property_read_u32(np, "ngpios", &ath79_gpio_count);
if (err) {
dev_err(&pdev->dev, "ngpios property is not valid\n");
return err;
}
if (ath79_gpio_count >= 32) {
dev_err(&pdev->dev, "ngpios must be less than 32\n");
return -EINVAL;
}
oe_inverted = of_device_is_compatible(np, "qca,ar9340-gpio");
} else if (pdata) {
ath79_gpio_count = pdata->ngpios;
oe_inverted = pdata->oe_inverted;
} else {
dev_err(&pdev->dev, "No DT node or platform data found\n");
return -EINVAL;
}
res = platform_get_resource(pdev, IORESOURCE_MEM, 0);
ath79_gpio_base = devm_ioremap_nocache(
&pdev->dev, res->start, resource_size(res));
if (!ath79_gpio_base)
return -ENOMEM;
ath79_gpio_chip.dev = &pdev->dev;
ath79_gpio_chip.ngpio = ath79_gpio_count;
if (oe_inverted) {
ath79_gpio_chip.direction_input = ar934x_gpio_direction_input;
ath79_gpio_chip.direction_output = ar934x_gpio_direction_output;
}
err = gpiochip_add(&ath79_gpio_chip);
if (err) {
dev_err(&pdev->dev,
"cannot add AR71xx GPIO chip, error=%d", err);
return err;
}
return 0;
}
