static int moxart_gpio_probe(struct platform_device *pdev)
{
struct device *dev = &pdev->dev;
struct resource *res;
struct gpio_chip *gc;
void __iomem *base;
int ret;
gc = devm_kzalloc(dev, sizeof(*gc), GFP_KERNEL);
if (!gc)
return -ENOMEM;
res = platform_get_resource(pdev, IORESOURCE_MEM, 0);
base = devm_ioremap_resource(dev, res);
if (IS_ERR(base))
return PTR_ERR(base);
ret = bgpio_init(gc, dev, 4, base + GPIO_DATA_IN,
base + GPIO_DATA_OUT, NULL,
base + GPIO_PIN_DIRECTION, NULL,
BGPIOF_READ_OUTPUT_REG_SET);
if (ret) {
dev_err(&pdev->dev, "bgpio_init failed\n");
return ret;
}
gc->label = "moxart-gpio";
gc->request = gpiochip_generic_request;
gc->free = gpiochip_generic_free;
gc->base = 0;
gc->owner = THIS_MODULE;
ret = devm_gpiochip_add_data(dev, gc, NULL);
if (ret) {
dev_err(dev, "%s: gpiochip_add failed\n",
dev->of_node->full_name);
return ret;
}
return ret;
}
