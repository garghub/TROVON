static int rdc_gpio_get_value(struct gpio_chip *chip, unsigned gpio)
{
struct rdc321x_gpio *gpch;
u32 value = 0;
int reg;
gpch = gpiochip_get_data(chip);
reg = gpio < 32 ? gpch->reg1_data_base : gpch->reg2_data_base;
spin_lock(&gpch->lock);
pci_write_config_dword(gpch->sb_pdev, reg,
gpch->data_reg[gpio < 32 ? 0 : 1]);
pci_read_config_dword(gpch->sb_pdev, reg, &value);
spin_unlock(&gpch->lock);
return (1 << (gpio & 0x1f)) & value ? 1 : 0;
}
static void rdc_gpio_set_value_impl(struct gpio_chip *chip,
unsigned gpio, int value)
{
struct rdc321x_gpio *gpch;
int reg = (gpio < 32) ? 0 : 1;
gpch = gpiochip_get_data(chip);
if (value)
gpch->data_reg[reg] |= 1 << (gpio & 0x1f);
else
gpch->data_reg[reg] &= ~(1 << (gpio & 0x1f));
pci_write_config_dword(gpch->sb_pdev,
reg ? gpch->reg2_data_base : gpch->reg1_data_base,
gpch->data_reg[reg]);
}
static void rdc_gpio_set_value(struct gpio_chip *chip,
unsigned gpio, int value)
{
struct rdc321x_gpio *gpch;
gpch = gpiochip_get_data(chip);
spin_lock(&gpch->lock);
rdc_gpio_set_value_impl(chip, gpio, value);
spin_unlock(&gpch->lock);
}
static int rdc_gpio_config(struct gpio_chip *chip,
unsigned gpio, int value)
{
struct rdc321x_gpio *gpch;
int err;
u32 reg;
gpch = gpiochip_get_data(chip);
spin_lock(&gpch->lock);
err = pci_read_config_dword(gpch->sb_pdev, gpio < 32 ?
gpch->reg1_ctrl_base : gpch->reg2_ctrl_base, &reg);
if (err)
goto unlock;
reg |= 1 << (gpio & 0x1f);
err = pci_write_config_dword(gpch->sb_pdev, gpio < 32 ?
gpch->reg1_ctrl_base : gpch->reg2_ctrl_base, reg);
if (err)
goto unlock;
rdc_gpio_set_value_impl(chip, gpio, value);
unlock:
spin_unlock(&gpch->lock);
return err;
}
static int rdc_gpio_direction_input(struct gpio_chip *chip, unsigned gpio)
{
return rdc_gpio_config(chip, gpio, 1);
}
static int rdc321x_gpio_probe(struct platform_device *pdev)
{
int err;
struct resource *r;
struct rdc321x_gpio *rdc321x_gpio_dev;
struct rdc321x_gpio_pdata *pdata;
pdata = dev_get_platdata(&pdev->dev);
if (!pdata) {
dev_err(&pdev->dev, "no platform data supplied\n");
return -ENODEV;
}
rdc321x_gpio_dev = devm_kzalloc(&pdev->dev, sizeof(struct rdc321x_gpio),
GFP_KERNEL);
if (!rdc321x_gpio_dev)
return -ENOMEM;
r = platform_get_resource_byname(pdev, IORESOURCE_IO, "gpio-reg1");
if (!r) {
dev_err(&pdev->dev, "failed to get gpio-reg1 resource\n");
return -ENODEV;
}
spin_lock_init(&rdc321x_gpio_dev->lock);
rdc321x_gpio_dev->sb_pdev = pdata->sb_pdev;
rdc321x_gpio_dev->reg1_ctrl_base = r->start;
rdc321x_gpio_dev->reg1_data_base = r->start + 0x4;
r = platform_get_resource_byname(pdev, IORESOURCE_IO, "gpio-reg2");
if (!r) {
dev_err(&pdev->dev, "failed to get gpio-reg2 resource\n");
return -ENODEV;
}
rdc321x_gpio_dev->reg2_ctrl_base = r->start;
rdc321x_gpio_dev->reg2_data_base = r->start + 0x4;
rdc321x_gpio_dev->chip.label = "rdc321x-gpio";
rdc321x_gpio_dev->chip.owner = THIS_MODULE;
rdc321x_gpio_dev->chip.direction_input = rdc_gpio_direction_input;
rdc321x_gpio_dev->chip.direction_output = rdc_gpio_config;
rdc321x_gpio_dev->chip.get = rdc_gpio_get_value;
rdc321x_gpio_dev->chip.set = rdc_gpio_set_value;
rdc321x_gpio_dev->chip.base = 0;
rdc321x_gpio_dev->chip.ngpio = pdata->max_gpios;
platform_set_drvdata(pdev, rdc321x_gpio_dev);
err = pci_read_config_dword(rdc321x_gpio_dev->sb_pdev,
rdc321x_gpio_dev->reg1_data_base,
&rdc321x_gpio_dev->data_reg[0]);
if (err)
return err;
err = pci_read_config_dword(rdc321x_gpio_dev->sb_pdev,
rdc321x_gpio_dev->reg2_data_base,
&rdc321x_gpio_dev->data_reg[1]);
if (err)
return err;
dev_info(&pdev->dev, "registering %d GPIOs\n",
rdc321x_gpio_dev->chip.ngpio);
return devm_gpiochip_add_data(&pdev->dev, &rdc321x_gpio_dev->chip,
rdc321x_gpio_dev);
}
