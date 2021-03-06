static void lpc18xx_gpio_set(struct gpio_chip *chip, unsigned offset, int value)
{
struct lpc18xx_gpio_chip *gc = gpiochip_get_data(chip);
writeb(value ? 1 : 0, gc->base + offset);
}
static int lpc18xx_gpio_get(struct gpio_chip *chip, unsigned offset)
{
struct lpc18xx_gpio_chip *gc = gpiochip_get_data(chip);
return !!readb(gc->base + offset);
}
static int lpc18xx_gpio_direction(struct gpio_chip *chip, unsigned offset,
bool out)
{
struct lpc18xx_gpio_chip *gc = gpiochip_get_data(chip);
unsigned long flags;
u32 port, pin, dir;
port = offset / LPC18XX_PINS_PER_PORT;
pin = offset % LPC18XX_PINS_PER_PORT;
spin_lock_irqsave(&gc->lock, flags);
dir = readl(gc->base + LPC18XX_REG_DIR(port));
if (out)
dir |= BIT(pin);
else
dir &= ~BIT(pin);
writel(dir, gc->base + LPC18XX_REG_DIR(port));
spin_unlock_irqrestore(&gc->lock, flags);
return 0;
}
static int lpc18xx_gpio_direction_input(struct gpio_chip *chip,
unsigned offset)
{
return lpc18xx_gpio_direction(chip, offset, false);
}
static int lpc18xx_gpio_direction_output(struct gpio_chip *chip,
unsigned offset, int value)
{
lpc18xx_gpio_set(chip, offset, value);
return lpc18xx_gpio_direction(chip, offset, true);
}
static int lpc18xx_gpio_probe(struct platform_device *pdev)
{
struct lpc18xx_gpio_chip *gc;
struct resource *res;
int ret;
gc = devm_kzalloc(&pdev->dev, sizeof(*gc), GFP_KERNEL);
if (!gc)
return -ENOMEM;
gc->gpio = lpc18xx_chip;
platform_set_drvdata(pdev, gc);
res = platform_get_resource(pdev, IORESOURCE_MEM, 0);
gc->base = devm_ioremap_resource(&pdev->dev, res);
if (IS_ERR(gc->base))
return PTR_ERR(gc->base);
gc->clk = devm_clk_get(&pdev->dev, NULL);
if (IS_ERR(gc->clk)) {
dev_err(&pdev->dev, "input clock not found\n");
return PTR_ERR(gc->clk);
}
ret = clk_prepare_enable(gc->clk);
if (ret) {
dev_err(&pdev->dev, "unable to enable clock\n");
return ret;
}
spin_lock_init(&gc->lock);
gc->gpio.parent = &pdev->dev;
ret = gpiochip_add_data(&gc->gpio, gc);
if (ret) {
dev_err(&pdev->dev, "failed to add gpio chip\n");
clk_disable_unprepare(gc->clk);
return ret;
}
return 0;
}
static int lpc18xx_gpio_remove(struct platform_device *pdev)
{
struct lpc18xx_gpio_chip *gc = platform_get_drvdata(pdev);
gpiochip_remove(&gc->gpio);
clk_disable_unprepare(gc->clk);
return 0;
}
