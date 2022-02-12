static inline struct syscon_gpio_priv *to_syscon_gpio(struct gpio_chip *chip)
{
return container_of(chip, struct syscon_gpio_priv, chip);
}
static int syscon_gpio_get(struct gpio_chip *chip, unsigned offset)
{
struct syscon_gpio_priv *priv = to_syscon_gpio(chip);
unsigned int val, offs = priv->data->dat_bit_offset + offset;
int ret;
ret = regmap_read(priv->syscon,
(offs / SYSCON_REG_BITS) * SYSCON_REG_SIZE, &val);
if (ret)
return ret;
return !!(val & BIT(offs % SYSCON_REG_BITS));
}
static void syscon_gpio_set(struct gpio_chip *chip, unsigned offset, int val)
{
struct syscon_gpio_priv *priv = to_syscon_gpio(chip);
unsigned int offs = priv->data->dat_bit_offset + offset;
regmap_update_bits(priv->syscon,
(offs / SYSCON_REG_BITS) * SYSCON_REG_SIZE,
BIT(offs % SYSCON_REG_BITS),
val ? BIT(offs % SYSCON_REG_BITS) : 0);
}
static int syscon_gpio_dir_in(struct gpio_chip *chip, unsigned offset)
{
struct syscon_gpio_priv *priv = to_syscon_gpio(chip);
if (priv->data->flags & GPIO_SYSCON_FEAT_DIR) {
unsigned int offs = priv->data->dir_bit_offset + offset;
regmap_update_bits(priv->syscon,
(offs / SYSCON_REG_BITS) * SYSCON_REG_SIZE,
BIT(offs % SYSCON_REG_BITS), 0);
}
return 0;
}
static int syscon_gpio_dir_out(struct gpio_chip *chip, unsigned offset, int val)
{
struct syscon_gpio_priv *priv = to_syscon_gpio(chip);
if (priv->data->flags & GPIO_SYSCON_FEAT_DIR) {
unsigned int offs = priv->data->dir_bit_offset + offset;
regmap_update_bits(priv->syscon,
(offs / SYSCON_REG_BITS) * SYSCON_REG_SIZE,
BIT(offs % SYSCON_REG_BITS),
BIT(offs % SYSCON_REG_BITS));
}
syscon_gpio_set(chip, offset, val);
return 0;
}
static int syscon_gpio_probe(struct platform_device *pdev)
{
struct device *dev = &pdev->dev;
const struct of_device_id *of_id = of_match_device(syscon_gpio_ids, dev);
struct syscon_gpio_priv *priv;
priv = devm_kzalloc(dev, sizeof(*priv), GFP_KERNEL);
if (!priv)
return -ENOMEM;
priv->data = of_id->data;
priv->syscon =
syscon_regmap_lookup_by_compatible(priv->data->compatible);
if (IS_ERR(priv->syscon))
return PTR_ERR(priv->syscon);
priv->chip.dev = dev;
priv->chip.owner = THIS_MODULE;
priv->chip.label = dev_name(dev);
priv->chip.base = -1;
priv->chip.ngpio = priv->data->bit_count;
priv->chip.get = syscon_gpio_get;
if (priv->data->flags & GPIO_SYSCON_FEAT_IN)
priv->chip.direction_input = syscon_gpio_dir_in;
if (priv->data->flags & GPIO_SYSCON_FEAT_OUT) {
priv->chip.set = syscon_gpio_set;
priv->chip.direction_output = syscon_gpio_dir_out;
}
platform_set_drvdata(pdev, priv);
return gpiochip_add(&priv->chip);
}
static int syscon_gpio_remove(struct platform_device *pdev)
{
struct syscon_gpio_priv *priv = platform_get_drvdata(pdev);
gpiochip_remove(&priv->chip);
return 0;
}
