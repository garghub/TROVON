static int clps711x_gpio_probe(struct platform_device *pdev)
{
struct device_node *np = pdev->dev.of_node;
void __iomem *dat, *dir;
struct bgpio_chip *bgc;
struct resource *res;
int err, id = np ? of_alias_get_id(np, "gpio") : pdev->id;
if ((id < 0) || (id > 4))
return -ENODEV;
bgc = devm_kzalloc(&pdev->dev, sizeof(*bgc), GFP_KERNEL);
if (!bgc)
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
err = bgpio_init(bgc, &pdev->dev, 1, dat, NULL, NULL,
NULL, dir, 0);
break;
default:
err = bgpio_init(bgc, &pdev->dev, 1, dat, NULL, NULL,
dir, NULL, 0);
break;
}
if (err)
return err;
switch (id) {
case 4:
bgc->gc.ngpio = 3;
break;
default:
break;
}
bgc->gc.base = id * 8;
platform_set_drvdata(pdev, bgc);
return gpiochip_add(&bgc->gc);
}
static int clps711x_gpio_remove(struct platform_device *pdev)
{
struct bgpio_chip *bgc = platform_get_drvdata(pdev);
return bgpio_remove(bgc);
}
