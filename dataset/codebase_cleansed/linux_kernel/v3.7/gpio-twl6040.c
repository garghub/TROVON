static int twl6040gpo_get(struct gpio_chip *chip, unsigned offset)
{
struct twl6040 *twl6040 = dev_get_drvdata(chip->dev->parent);
int ret = 0;
ret = twl6040_reg_read(twl6040, TWL6040_REG_GPOCTL);
if (ret < 0)
return ret;
return (ret >> offset) & 1;
}
static int twl6040gpo_direction_out(struct gpio_chip *chip, unsigned offset,
int value)
{
return 0;
}
static void twl6040gpo_set(struct gpio_chip *chip, unsigned offset, int value)
{
struct twl6040 *twl6040 = dev_get_drvdata(chip->dev->parent);
int ret;
u8 gpoctl;
ret = twl6040_reg_read(twl6040, TWL6040_REG_GPOCTL);
if (ret < 0)
return;
if (value)
gpoctl = ret | (1 << offset);
else
gpoctl = ret & ~(1 << offset);
twl6040_reg_write(twl6040, TWL6040_REG_GPOCTL, gpoctl);
}
static int __devinit gpo_twl6040_probe(struct platform_device *pdev)
{
struct twl6040_gpo_data *pdata = pdev->dev.platform_data;
struct device *twl6040_core_dev = pdev->dev.parent;
struct twl6040 *twl6040 = dev_get_drvdata(twl6040_core_dev);
int ret;
if (pdata)
twl6040gpo_chip.base = pdata->gpio_base;
else
twl6040gpo_chip.base = -1;
if (twl6040_get_revid(twl6040) < TWL6041_REV_ES2_0)
twl6040gpo_chip.ngpio = 3;
else
twl6040gpo_chip.ngpio = 1;
twl6040gpo_chip.dev = &pdev->dev;
#ifdef CONFIG_OF_GPIO
twl6040gpo_chip.of_node = twl6040_core_dev->of_node;
#endif
ret = gpiochip_add(&twl6040gpo_chip);
if (ret < 0) {
dev_err(&pdev->dev, "could not register gpiochip, %d\n", ret);
twl6040gpo_chip.ngpio = 0;
}
return ret;
}
static int __devexit gpo_twl6040_remove(struct platform_device *pdev)
{
return gpiochip_remove(&twl6040gpo_chip);
}
