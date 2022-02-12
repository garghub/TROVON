static void gpio_line_config(int line, int direction)
{
unsigned long flags;
u32 val;
local_irq_save(flags);
val = readl(IOP3XX_GPOE);
if (direction == GPIO_IN) {
val |= BIT(line);
} else if (direction == GPIO_OUT) {
val &= ~BIT(line);
}
writel(val, IOP3XX_GPOE);
local_irq_restore(flags);
}
static int gpio_line_get(int line)
{
return !!(readl(IOP3XX_GPID) & BIT(line));
}
static void gpio_line_set(int line, int value)
{
unsigned long flags;
u32 val;
local_irq_save(flags);
val = readl(IOP3XX_GPOD);
if (value == GPIO_LOW) {
val &= ~BIT(line);
} else if (value == GPIO_HIGH) {
val |= BIT(line);
}
writel(val, IOP3XX_GPOD);
local_irq_restore(flags);
}
static int iop3xx_gpio_direction_input(struct gpio_chip *chip, unsigned gpio)
{
gpio_line_config(gpio, GPIO_IN);
return 0;
}
static int iop3xx_gpio_direction_output(struct gpio_chip *chip, unsigned gpio, int level)
{
gpio_line_set(gpio, level);
gpio_line_config(gpio, GPIO_OUT);
return 0;
}
static int iop3xx_gpio_get_value(struct gpio_chip *chip, unsigned gpio)
{
return gpio_line_get(gpio);
}
static void iop3xx_gpio_set_value(struct gpio_chip *chip, unsigned gpio, int value)
{
gpio_line_set(gpio, value);
}
static int iop3xx_gpio_probe(struct platform_device *pdev)
{
struct resource *res;
res = platform_get_resource(pdev, IORESOURCE_MEM, 0);
base = devm_ioremap_resource(&pdev->dev, res);
if (IS_ERR(base))
return PTR_ERR(base);
return devm_gpiochip_add_data(&pdev->dev, &iop3xx_chip, NULL);
}
static int __init iop3xx_gpio_init(void)
{
return platform_driver_register(&iop3xx_gpio_driver);
}
