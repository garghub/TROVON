static int mmio_74xx_get_direction(struct gpio_chip *gc, unsigned offset)
{
struct mmio_74xx_gpio_priv *priv = gpiochip_get_data(gc);
return !(priv->flags & MMIO_74XX_DIR_OUT);
}
static int mmio_74xx_dir_in(struct gpio_chip *gc, unsigned int gpio)
{
struct mmio_74xx_gpio_priv *priv = gpiochip_get_data(gc);
return (priv->flags & MMIO_74XX_DIR_OUT) ? -ENOTSUPP : 0;
}
static int mmio_74xx_dir_out(struct gpio_chip *gc, unsigned int gpio, int val)
{
struct mmio_74xx_gpio_priv *priv = gpiochip_get_data(gc);
if (priv->flags & MMIO_74XX_DIR_OUT) {
gc->set(gc, gpio, val);
return 0;
}
return -ENOTSUPP;
}
static int mmio_74xx_gpio_probe(struct platform_device *pdev)
{
const struct of_device_id *of_id;
struct mmio_74xx_gpio_priv *priv;
struct resource *res;
void __iomem *dat;
int err;
of_id = of_match_device(mmio_74xx_gpio_ids, &pdev->dev);
if (!of_id)
return -ENODEV;
priv = devm_kzalloc(&pdev->dev, sizeof(*priv), GFP_KERNEL);
if (!priv)
return -ENOMEM;
res = platform_get_resource(pdev, IORESOURCE_MEM, 0);
dat = devm_ioremap_resource(&pdev->dev, res);
if (IS_ERR(dat))
return PTR_ERR(dat);
priv->flags = (uintptr_t) of_id->data;
err = bgpio_init(&priv->gc, &pdev->dev,
DIV_ROUND_UP(MMIO_74XX_BIT_CNT(priv->flags), 8),
dat, NULL, NULL, NULL, NULL, 0);
if (err)
return err;
priv->gc.direction_input = mmio_74xx_dir_in;
priv->gc.direction_output = mmio_74xx_dir_out;
priv->gc.get_direction = mmio_74xx_get_direction;
priv->gc.ngpio = MMIO_74XX_BIT_CNT(priv->flags);
priv->gc.owner = THIS_MODULE;
platform_set_drvdata(pdev, priv);
return devm_gpiochip_add_data(&pdev->dev, &priv->gc, priv);
}
