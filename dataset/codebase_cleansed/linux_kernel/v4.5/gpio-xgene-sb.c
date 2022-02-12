static void xgene_gpio_set_bit(struct gpio_chip *gc, void __iomem *reg, u32 gpio, int val)
{
u32 data;
data = gc->read_reg(reg);
if (val)
data |= GPIO_MASK(gpio);
else
data &= ~GPIO_MASK(gpio);
gc->write_reg(reg, data);
}
static int apm_gpio_sb_to_irq(struct gpio_chip *gc, u32 gpio)
{
struct xgene_gpio_sb *priv = gpiochip_get_data(gc);
if (priv->irq[gpio])
return priv->irq[gpio];
return -ENXIO;
}
static int xgene_gpio_sb_probe(struct platform_device *pdev)
{
struct xgene_gpio_sb *priv;
u32 ret, i;
u32 default_lines[] = {0x08, 0x09, 0x0A, 0x0B, 0x0C, 0x0D};
struct resource *res;
void __iomem *regs;
priv = devm_kzalloc(&pdev->dev, sizeof(*priv), GFP_KERNEL);
if (!priv)
return -ENOMEM;
res = platform_get_resource(pdev, IORESOURCE_MEM, 0);
regs = devm_ioremap_resource(&pdev->dev, res);
if (IS_ERR(regs))
return PTR_ERR(regs);
ret = bgpio_init(&priv->gc, &pdev->dev, 4,
regs + MPA_GPIO_IN_ADDR,
regs + MPA_GPIO_OUT_ADDR, NULL,
regs + MPA_GPIO_OE_ADDR, NULL, 0);
if (ret)
return ret;
priv->gc.to_irq = apm_gpio_sb_to_irq;
priv->gc.ngpio = XGENE_MAX_GPIO_DS;
priv->nirq = XGENE_MAX_GPIO_DS_IRQ;
priv->irq = devm_kzalloc(&pdev->dev, sizeof(u32) * XGENE_MAX_GPIO_DS,
GFP_KERNEL);
if (!priv->irq)
return -ENOMEM;
for (i = 0; i < priv->nirq; i++) {
priv->irq[default_lines[i]] = platform_get_irq(pdev, i);
xgene_gpio_set_bit(&priv->gc, regs + MPA_GPIO_SEL_LO,
default_lines[i] * 2, 1);
xgene_gpio_set_bit(&priv->gc, regs + MPA_GPIO_INT_LVL, i, 1);
}
platform_set_drvdata(pdev, priv);
ret = gpiochip_add_data(&priv->gc, priv);
if (ret)
dev_err(&pdev->dev, "failed to register X-Gene GPIO Standby driver\n");
else
dev_info(&pdev->dev, "X-Gene GPIO Standby driver registered\n");
if (priv->nirq > 0) {
acpi_gpiochip_request_interrupts(&priv->gc);
}
return ret;
}
static int xgene_gpio_sb_remove(struct platform_device *pdev)
{
struct xgene_gpio_sb *priv = platform_get_drvdata(pdev);
if (priv->nirq > 0) {
acpi_gpiochip_free_interrupts(&priv->gc);
}
gpiochip_remove(&priv->gc);
return 0;
}
