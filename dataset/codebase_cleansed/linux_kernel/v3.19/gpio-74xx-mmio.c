static inline struct mmio_74xx_gpio_priv *to_74xx_gpio(struct gpio_chip *gc)
{
struct bgpio_chip *bgc = to_bgpio_chip(gc);
return container_of(bgc, struct mmio_74xx_gpio_priv, bgc);
}
static int mmio_74xx_get_direction(struct gpio_chip *gc, unsigned offset)
{
struct mmio_74xx_gpio_priv *priv = to_74xx_gpio(gc);
return (priv->flags & MMIO_74XX_DIR_OUT) ? GPIOF_DIR_OUT : GPIOF_DIR_IN;
}
static int mmio_74xx_dir_in(struct gpio_chip *gc, unsigned int gpio)
{
struct mmio_74xx_gpio_priv *priv = to_74xx_gpio(gc);
return (priv->flags & MMIO_74XX_DIR_OUT) ? -ENOTSUPP : 0;
}
static int mmio_74xx_dir_out(struct gpio_chip *gc, unsigned int gpio, int val)
{
struct mmio_74xx_gpio_priv *priv = to_74xx_gpio(gc);
if (priv->flags & MMIO_74XX_DIR_OUT) {
gc->set(gc, gpio, val);
return 0;
}
return -ENOTSUPP;
}
static int mmio_74xx_gpio_probe(struct platform_device *pdev)
{
const struct of_device_id *of_id =
of_match_device(mmio_74xx_gpio_ids, &pdev->dev);
struct mmio_74xx_gpio_priv *priv;
struct resource *res;
void __iomem *dat;
int err;
priv = devm_kzalloc(&pdev->dev, sizeof(*priv), GFP_KERNEL);
if (!priv)
return -ENOMEM;
res = platform_get_resource(pdev, IORESOURCE_MEM, 0);
dat = devm_ioremap_resource(&pdev->dev, res);
if (IS_ERR(dat))
return PTR_ERR(dat);
priv->flags = (unsigned)of_id->data;
err = bgpio_init(&priv->bgc, &pdev->dev,
DIV_ROUND_UP(MMIO_74XX_BIT_CNT(priv->flags), 8),
dat, NULL, NULL, NULL, NULL, 0);
if (err)
return err;
priv->bgc.gc.direction_input = mmio_74xx_dir_in;
priv->bgc.gc.direction_output = mmio_74xx_dir_out;
priv->bgc.gc.get_direction = mmio_74xx_get_direction;
priv->bgc.gc.ngpio = MMIO_74XX_BIT_CNT(priv->flags);
priv->bgc.gc.owner = THIS_MODULE;
platform_set_drvdata(pdev, priv);
return gpiochip_add(&priv->bgc.gc);
}
static int mmio_74xx_gpio_remove(struct platform_device *pdev)
{
struct mmio_74xx_gpio_priv *priv = platform_get_drvdata(pdev);
return bgpio_remove(&priv->bgc);
}
