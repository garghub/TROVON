static int ts4800_gpio_probe(struct platform_device *pdev)
{
struct device_node *node;
struct gpio_chip *chip;
struct resource *res;
void __iomem *base_addr;
int retval;
u32 ngpios;
chip = devm_kzalloc(&pdev->dev, sizeof(struct gpio_chip), GFP_KERNEL);
if (!chip)
return -ENOMEM;
res = platform_get_resource(pdev, IORESOURCE_MEM, 0);
base_addr = devm_ioremap_resource(&pdev->dev, res);
if (IS_ERR(base_addr))
return PTR_ERR(base_addr);
node = pdev->dev.of_node;
if (!node)
return -EINVAL;
retval = of_property_read_u32(node, "ngpios", &ngpios);
if (retval == -EINVAL)
ngpios = DEFAULT_PIN_NUMBER;
else if (retval)
return retval;
retval = bgpio_init(chip, &pdev->dev, 2, base_addr + INPUT_REG_OFFSET,
base_addr + OUTPUT_REG_OFFSET, NULL,
base_addr + DIRECTION_REG_OFFSET, NULL, 0);
if (retval) {
dev_err(&pdev->dev, "bgpio_init failed\n");
return retval;
}
chip->ngpio = ngpios;
platform_set_drvdata(pdev, chip);
return devm_gpiochip_add_data(&pdev->dev, chip, NULL);
}
