static int iop3xx_gpio_probe(struct platform_device *pdev)
{
struct resource *res;
struct gpio_chip *gc;
void __iomem *base;
int err;
gc = devm_kzalloc(&pdev->dev, sizeof(*gc), GFP_KERNEL);
if (!gc)
return -ENOMEM;
res = platform_get_resource(pdev, IORESOURCE_MEM, 0);
base = devm_ioremap_resource(&pdev->dev, res);
if (IS_ERR(base))
return PTR_ERR(base);
err = bgpio_init(gc, &pdev->dev, 1, base + IOP3XX_GPID,
base + IOP3XX_GPOD, NULL, NULL, base + IOP3XX_GPOE, 0);
if (err)
return err;
gc->base = 0;
gc->owner = THIS_MODULE;
return devm_gpiochip_add_data(&pdev->dev, gc, NULL);
}
static int __init iop3xx_gpio_init(void)
{
return platform_driver_register(&iop3xx_gpio_driver);
}
