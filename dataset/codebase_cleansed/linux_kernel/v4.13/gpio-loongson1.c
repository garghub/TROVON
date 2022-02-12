static int ls1x_gpio_request(struct gpio_chip *gc, unsigned int offset)
{
unsigned long pinmask = gc->pin2mask(gc, offset);
unsigned long flags;
spin_lock_irqsave(&gc->bgpio_lock, flags);
__raw_writel(__raw_readl(gpio_reg_base + GPIO_CFG) | pinmask,
gpio_reg_base + GPIO_CFG);
spin_unlock_irqrestore(&gc->bgpio_lock, flags);
return 0;
}
static void ls1x_gpio_free(struct gpio_chip *gc, unsigned int offset)
{
unsigned long pinmask = gc->pin2mask(gc, offset);
unsigned long flags;
spin_lock_irqsave(&gc->bgpio_lock, flags);
__raw_writel(__raw_readl(gpio_reg_base + GPIO_CFG) & ~pinmask,
gpio_reg_base + GPIO_CFG);
spin_unlock_irqrestore(&gc->bgpio_lock, flags);
}
static int ls1x_gpio_probe(struct platform_device *pdev)
{
struct device *dev = &pdev->dev;
struct gpio_chip *gc;
struct resource *res;
int ret;
gc = devm_kzalloc(dev, sizeof(*gc), GFP_KERNEL);
if (!gc)
return -ENOMEM;
res = platform_get_resource(pdev, IORESOURCE_MEM, 0);
gpio_reg_base = devm_ioremap_resource(dev, res);
if (IS_ERR(gpio_reg_base))
return PTR_ERR(gpio_reg_base);
ret = bgpio_init(gc, dev, 4, gpio_reg_base + GPIO_DATA,
gpio_reg_base + GPIO_OUTPUT, NULL,
NULL, gpio_reg_base + GPIO_DIR, 0);
if (ret)
goto err;
gc->owner = THIS_MODULE;
gc->request = ls1x_gpio_request;
gc->free = ls1x_gpio_free;
gc->base = pdev->id * 32;
ret = devm_gpiochip_add_data(dev, gc, NULL);
if (ret)
goto err;
platform_set_drvdata(pdev, gc);
dev_info(dev, "Loongson1 GPIO driver registered\n");
return 0;
err:
dev_err(dev, "failed to register GPIO device\n");
return ret;
}
