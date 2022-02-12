static inline struct moxart_gpio_chip *to_moxart_gpio(struct gpio_chip *chip)
{
return container_of(chip, struct moxart_gpio_chip, gpio);
}
static int moxart_gpio_request(struct gpio_chip *chip, unsigned offset)
{
return pinctrl_request_gpio(offset);
}
static void moxart_gpio_free(struct gpio_chip *chip, unsigned offset)
{
pinctrl_free_gpio(offset);
}
static void moxart_gpio_set(struct gpio_chip *chip, unsigned offset, int value)
{
struct moxart_gpio_chip *gc = to_moxart_gpio(chip);
void __iomem *ioaddr = gc->base + GPIO_DATA_OUT;
u32 reg = readl(ioaddr);
if (value)
reg = reg | BIT(offset);
else
reg = reg & ~BIT(offset);
writel(reg, ioaddr);
}
static int moxart_gpio_get(struct gpio_chip *chip, unsigned offset)
{
struct moxart_gpio_chip *gc = to_moxart_gpio(chip);
u32 ret = readl(gc->base + GPIO_PIN_DIRECTION);
if (ret & BIT(offset))
return !!(readl(gc->base + GPIO_DATA_OUT) & BIT(offset));
else
return !!(readl(gc->base + GPIO_DATA_IN) & BIT(offset));
}
static int moxart_gpio_direction_input(struct gpio_chip *chip, unsigned offset)
{
struct moxart_gpio_chip *gc = to_moxart_gpio(chip);
void __iomem *ioaddr = gc->base + GPIO_PIN_DIRECTION;
writel(readl(ioaddr) & ~BIT(offset), ioaddr);
return 0;
}
static int moxart_gpio_direction_output(struct gpio_chip *chip,
unsigned offset, int value)
{
struct moxart_gpio_chip *gc = to_moxart_gpio(chip);
void __iomem *ioaddr = gc->base + GPIO_PIN_DIRECTION;
moxart_gpio_set(chip, offset, value);
writel(readl(ioaddr) | BIT(offset), ioaddr);
return 0;
}
static int moxart_gpio_probe(struct platform_device *pdev)
{
struct device *dev = &pdev->dev;
struct resource *res;
struct moxart_gpio_chip *mgc;
int ret;
mgc = devm_kzalloc(dev, sizeof(*mgc), GFP_KERNEL);
if (!mgc) {
dev_err(dev, "can't allocate GPIO chip container\n");
return -ENOMEM;
}
mgc->gpio = moxart_template_chip;
res = platform_get_resource(pdev, IORESOURCE_MEM, 0);
mgc->base = devm_ioremap_resource(dev, res);
if (IS_ERR(mgc->base))
return PTR_ERR(mgc->base);
mgc->gpio.dev = dev;
ret = gpiochip_add(&mgc->gpio);
if (ret) {
dev_err(dev, "%s: gpiochip_add failed\n",
dev->of_node->full_name);
return ret;
}
return 0;
}
