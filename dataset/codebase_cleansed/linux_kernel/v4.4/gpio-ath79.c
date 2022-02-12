static void ath79_gpio_set_value(struct gpio_chip *chip,
unsigned gpio, int value)
{
struct ath79_gpio_ctrl *ctrl = to_ath79_gpio_ctrl(chip);
if (value)
__raw_writel(BIT(gpio), ctrl->base + AR71XX_GPIO_REG_SET);
else
__raw_writel(BIT(gpio), ctrl->base + AR71XX_GPIO_REG_CLEAR);
}
static int ath79_gpio_get_value(struct gpio_chip *chip, unsigned gpio)
{
struct ath79_gpio_ctrl *ctrl = to_ath79_gpio_ctrl(chip);
return (__raw_readl(ctrl->base + AR71XX_GPIO_REG_IN) >> gpio) & 1;
}
static int ath79_gpio_direction_input(struct gpio_chip *chip,
unsigned offset)
{
struct ath79_gpio_ctrl *ctrl = to_ath79_gpio_ctrl(chip);
unsigned long flags;
spin_lock_irqsave(&ctrl->lock, flags);
__raw_writel(
__raw_readl(ctrl->base + AR71XX_GPIO_REG_OE) & ~BIT(offset),
ctrl->base + AR71XX_GPIO_REG_OE);
spin_unlock_irqrestore(&ctrl->lock, flags);
return 0;
}
static int ath79_gpio_direction_output(struct gpio_chip *chip,
unsigned offset, int value)
{
struct ath79_gpio_ctrl *ctrl = to_ath79_gpio_ctrl(chip);
unsigned long flags;
spin_lock_irqsave(&ctrl->lock, flags);
if (value)
__raw_writel(BIT(offset), ctrl->base + AR71XX_GPIO_REG_SET);
else
__raw_writel(BIT(offset), ctrl->base + AR71XX_GPIO_REG_CLEAR);
__raw_writel(
__raw_readl(ctrl->base + AR71XX_GPIO_REG_OE) | BIT(offset),
ctrl->base + AR71XX_GPIO_REG_OE);
spin_unlock_irqrestore(&ctrl->lock, flags);
return 0;
}
static int ar934x_gpio_direction_input(struct gpio_chip *chip, unsigned offset)
{
struct ath79_gpio_ctrl *ctrl = to_ath79_gpio_ctrl(chip);
unsigned long flags;
spin_lock_irqsave(&ctrl->lock, flags);
__raw_writel(
__raw_readl(ctrl->base + AR71XX_GPIO_REG_OE) | BIT(offset),
ctrl->base + AR71XX_GPIO_REG_OE);
spin_unlock_irqrestore(&ctrl->lock, flags);
return 0;
}
static int ar934x_gpio_direction_output(struct gpio_chip *chip, unsigned offset,
int value)
{
struct ath79_gpio_ctrl *ctrl = to_ath79_gpio_ctrl(chip);
unsigned long flags;
spin_lock_irqsave(&ctrl->lock, flags);
if (value)
__raw_writel(BIT(offset), ctrl->base + AR71XX_GPIO_REG_SET);
else
__raw_writel(BIT(offset), ctrl->base + AR71XX_GPIO_REG_CLEAR);
__raw_writel(
__raw_readl(ctrl->base + AR71XX_GPIO_REG_OE) & ~BIT(offset),
ctrl->base + AR71XX_GPIO_REG_OE);
spin_unlock_irqrestore(&ctrl->lock, flags);
return 0;
}
static int ath79_gpio_probe(struct platform_device *pdev)
{
struct ath79_gpio_platform_data *pdata = pdev->dev.platform_data;
struct device_node *np = pdev->dev.of_node;
struct ath79_gpio_ctrl *ctrl;
struct resource *res;
u32 ath79_gpio_count;
bool oe_inverted;
int err;
ctrl = devm_kzalloc(&pdev->dev, sizeof(*ctrl), GFP_KERNEL);
if (!ctrl)
return -ENOMEM;
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
ctrl->base = devm_ioremap_nocache(
&pdev->dev, res->start, resource_size(res));
if (!ctrl->base)
return -ENOMEM;
spin_lock_init(&ctrl->lock);
memcpy(&ctrl->chip, &ath79_gpio_chip, sizeof(ctrl->chip));
ctrl->chip.dev = &pdev->dev;
ctrl->chip.ngpio = ath79_gpio_count;
if (oe_inverted) {
ctrl->chip.direction_input = ar934x_gpio_direction_input;
ctrl->chip.direction_output = ar934x_gpio_direction_output;
}
err = gpiochip_add(&ctrl->chip);
if (err) {
dev_err(&pdev->dev,
"cannot add AR71xx GPIO chip, error=%d", err);
return err;
}
return 0;
}
