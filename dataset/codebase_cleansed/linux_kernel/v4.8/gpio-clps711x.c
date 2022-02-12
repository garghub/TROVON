static int clps711x_gpio_probe(struct platform_device *pdev)
{
struct device_node *np = pdev->dev.of_node;
void __iomem *dat, *dir;
struct gpio_chip *gc;
struct resource *res;
int err, id;
if (!np)
return -ENODEV;
id = of_alias_get_id(np, "gpio");
if ((id < 0) || (id > 4))
return -ENODEV;
gc = devm_kzalloc(&pdev->dev, sizeof(*gc), GFP_KERNEL);
if (!gc)
return -ENOMEM;
res = platform_get_resource(pdev, IORESOURCE_MEM, 0);
dat = devm_ioremap_resource(&pdev->dev, res);
if (IS_ERR(dat))
return PTR_ERR(dat);
res = platform_get_resource(pdev, IORESOURCE_MEM, 1);
dir = devm_ioremap_resource(&pdev->dev, res);
if (IS_ERR(dir))
return PTR_ERR(dir);
switch (id) {
case 3:
err = bgpio_init(gc, &pdev->dev, 1, dat, NULL, NULL,
NULL, dir, 0);
break;
default:
err = bgpio_init(gc, &pdev->dev, 1, dat, NULL, NULL,
dir, NULL, 0);
break;
}
if (err)
return err;
switch (id) {
case 4:
gc->ngpio = 3;
break;
default:
break;
}
gc->base = -1;
gc->owner = THIS_MODULE;
platform_set_drvdata(pdev, gc);
return devm_gpiochip_add_data(&pdev->dev, gc, NULL);
}
