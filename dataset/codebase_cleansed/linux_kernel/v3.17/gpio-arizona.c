static inline struct arizona_gpio *to_arizona_gpio(struct gpio_chip *chip)
{
return container_of(chip, struct arizona_gpio, gpio_chip);
}
static int arizona_gpio_direction_in(struct gpio_chip *chip, unsigned offset)
{
struct arizona_gpio *arizona_gpio = to_arizona_gpio(chip);
struct arizona *arizona = arizona_gpio->arizona;
return regmap_update_bits(arizona->regmap, ARIZONA_GPIO1_CTRL + offset,
ARIZONA_GPN_DIR, ARIZONA_GPN_DIR);
}
static int arizona_gpio_get(struct gpio_chip *chip, unsigned offset)
{
struct arizona_gpio *arizona_gpio = to_arizona_gpio(chip);
struct arizona *arizona = arizona_gpio->arizona;
unsigned int val;
int ret;
ret = regmap_read(arizona->regmap, ARIZONA_GPIO1_CTRL + offset, &val);
if (ret < 0)
return ret;
if (val & ARIZONA_GPN_LVL)
return 1;
else
return 0;
}
static int arizona_gpio_direction_out(struct gpio_chip *chip,
unsigned offset, int value)
{
struct arizona_gpio *arizona_gpio = to_arizona_gpio(chip);
struct arizona *arizona = arizona_gpio->arizona;
if (value)
value = ARIZONA_GPN_LVL;
return regmap_update_bits(arizona->regmap, ARIZONA_GPIO1_CTRL + offset,
ARIZONA_GPN_DIR | ARIZONA_GPN_LVL, value);
}
static void arizona_gpio_set(struct gpio_chip *chip, unsigned offset, int value)
{
struct arizona_gpio *arizona_gpio = to_arizona_gpio(chip);
struct arizona *arizona = arizona_gpio->arizona;
if (value)
value = ARIZONA_GPN_LVL;
regmap_update_bits(arizona->regmap, ARIZONA_GPIO1_CTRL + offset,
ARIZONA_GPN_LVL, value);
}
static int arizona_gpio_probe(struct platform_device *pdev)
{
struct arizona *arizona = dev_get_drvdata(pdev->dev.parent);
struct arizona_pdata *pdata = dev_get_platdata(arizona->dev);
struct arizona_gpio *arizona_gpio;
int ret;
arizona_gpio = devm_kzalloc(&pdev->dev, sizeof(*arizona_gpio),
GFP_KERNEL);
if (arizona_gpio == NULL)
return -ENOMEM;
arizona_gpio->arizona = arizona;
arizona_gpio->gpio_chip = template_chip;
arizona_gpio->gpio_chip.dev = &pdev->dev;
#ifdef CONFIG_OF_GPIO
arizona_gpio->gpio_chip.of_node = arizona->dev->of_node;
#endif
switch (arizona->type) {
case WM5102:
case WM5110:
case WM8997:
arizona_gpio->gpio_chip.ngpio = 5;
break;
default:
dev_err(&pdev->dev, "Unknown chip variant %d\n",
arizona->type);
return -EINVAL;
}
if (pdata && pdata->gpio_base)
arizona_gpio->gpio_chip.base = pdata->gpio_base;
else
arizona_gpio->gpio_chip.base = -1;
ret = gpiochip_add(&arizona_gpio->gpio_chip);
if (ret < 0) {
dev_err(&pdev->dev, "Could not register gpiochip, %d\n",
ret);
goto err;
}
platform_set_drvdata(pdev, arizona_gpio);
return ret;
err:
return ret;
}
static int arizona_gpio_remove(struct platform_device *pdev)
{
struct arizona_gpio *arizona_gpio = platform_get_drvdata(pdev);
gpiochip_remove(&arizona_gpio->gpio_chip);
return 0;
}
