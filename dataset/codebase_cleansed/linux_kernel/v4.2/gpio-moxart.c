static int moxart_gpio_request(struct gpio_chip *chip, unsigned offset)
{
return pinctrl_request_gpio(offset);
}
static void moxart_gpio_free(struct gpio_chip *chip, unsigned offset)
{
pinctrl_free_gpio(offset);
}
static int moxart_gpio_probe(struct platform_device *pdev)
{
struct device *dev = &pdev->dev;
struct resource *res;
struct bgpio_chip *bgc;
void __iomem *base;
int ret;
bgc = devm_kzalloc(dev, sizeof(*bgc), GFP_KERNEL);
if (!bgc)
return -ENOMEM;
res = platform_get_resource(pdev, IORESOURCE_MEM, 0);
base = devm_ioremap_resource(dev, res);
if (IS_ERR(base))
return PTR_ERR(base);
ret = bgpio_init(bgc, dev, 4, base + GPIO_DATA_IN,
base + GPIO_DATA_OUT, NULL,
base + GPIO_PIN_DIRECTION, NULL,
BGPIOF_READ_OUTPUT_REG_SET);
if (ret) {
dev_err(&pdev->dev, "bgpio_init failed\n");
return ret;
}
bgc->gc.label = "moxart-gpio";
bgc->gc.request = moxart_gpio_request;
bgc->gc.free = moxart_gpio_free;
bgc->data = bgc->read_reg(bgc->reg_set);
bgc->gc.base = 0;
bgc->gc.ngpio = 32;
bgc->gc.dev = dev;
bgc->gc.owner = THIS_MODULE;
ret = gpiochip_add(&bgc->gc);
if (ret) {
dev_err(dev, "%s: gpiochip_add failed\n",
dev->of_node->full_name);
return ret;
}
return ret;
}
