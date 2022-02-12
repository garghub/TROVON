static inline struct syscon_gpio_priv *to_syscon_gpio(struct gpio_chip *chip)
{
return container_of(chip, struct syscon_gpio_priv, chip);
}
static int syscon_gpio_get(struct gpio_chip *chip, unsigned offset)
{
struct syscon_gpio_priv *priv = to_syscon_gpio(chip);
unsigned int val, offs;
int ret;
offs = priv->dreg_offset + priv->data->dat_bit_offset + offset;
ret = regmap_read(priv->syscon,
(offs / SYSCON_REG_BITS) * SYSCON_REG_SIZE, &val);
if (ret)
return ret;
return !!(val & BIT(offs % SYSCON_REG_BITS));
}
static void syscon_gpio_set(struct gpio_chip *chip, unsigned offset, int val)
{
struct syscon_gpio_priv *priv = to_syscon_gpio(chip);
unsigned int offs;
offs = priv->dreg_offset + priv->data->dat_bit_offset + offset;
regmap_update_bits(priv->syscon,
(offs / SYSCON_REG_BITS) * SYSCON_REG_SIZE,
BIT(offs % SYSCON_REG_BITS),
val ? BIT(offs % SYSCON_REG_BITS) : 0);
}
static int syscon_gpio_dir_in(struct gpio_chip *chip, unsigned offset)
{
struct syscon_gpio_priv *priv = to_syscon_gpio(chip);
if (priv->data->flags & GPIO_SYSCON_FEAT_DIR) {
unsigned int offs;
offs = priv->dir_reg_offset +
priv->data->dir_bit_offset + offset;
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
unsigned int offs;
offs = priv->dir_reg_offset +
priv->data->dir_bit_offset + offset;
regmap_update_bits(priv->syscon,
(offs / SYSCON_REG_BITS) * SYSCON_REG_SIZE,
BIT(offs % SYSCON_REG_BITS),
BIT(offs % SYSCON_REG_BITS));
}
priv->data->set(chip, offset, val);
return 0;
}
static void keystone_gpio_set(struct gpio_chip *chip, unsigned offset, int val)
{
struct syscon_gpio_priv *priv = to_syscon_gpio(chip);
unsigned int offs;
int ret;
offs = priv->dreg_offset + priv->data->dat_bit_offset + offset;
if (!val)
return;
ret = regmap_update_bits(
priv->syscon,
(offs / SYSCON_REG_BITS) * SYSCON_REG_SIZE,
BIT(offs % SYSCON_REG_BITS) | KEYSTONE_LOCK_BIT,
BIT(offs % SYSCON_REG_BITS) | KEYSTONE_LOCK_BIT);
if (ret < 0)
dev_err(chip->dev, "gpio write failed ret(%d)\n", ret);
}
static int syscon_gpio_probe(struct platform_device *pdev)
{
struct device *dev = &pdev->dev;
const struct of_device_id *of_id = of_match_device(syscon_gpio_ids, dev);
struct syscon_gpio_priv *priv;
struct device_node *np = dev->of_node;
int ret;
priv = devm_kzalloc(dev, sizeof(*priv), GFP_KERNEL);
if (!priv)
return -ENOMEM;
priv->data = of_id->data;
if (priv->data->compatible) {
priv->syscon = syscon_regmap_lookup_by_compatible(
priv->data->compatible);
if (IS_ERR(priv->syscon))
return PTR_ERR(priv->syscon);
} else {
priv->syscon =
syscon_regmap_lookup_by_phandle(np, "gpio,syscon-dev");
if (IS_ERR(priv->syscon))
return PTR_ERR(priv->syscon);
ret = of_property_read_u32_index(np, "gpio,syscon-dev", 1,
&priv->dreg_offset);
if (ret)
dev_err(dev, "can't read the data register offset!\n");
priv->dreg_offset <<= 3;
ret = of_property_read_u32_index(np, "gpio,syscon-dev", 2,
&priv->dir_reg_offset);
if (ret)
dev_dbg(dev, "can't read the dir register offset!\n");
priv->dir_reg_offset <<= 3;
}
priv->chip.dev = dev;
priv->chip.owner = THIS_MODULE;
priv->chip.label = dev_name(dev);
priv->chip.base = -1;
priv->chip.ngpio = priv->data->bit_count;
priv->chip.get = syscon_gpio_get;
if (priv->data->flags & GPIO_SYSCON_FEAT_IN)
priv->chip.direction_input = syscon_gpio_dir_in;
if (priv->data->flags & GPIO_SYSCON_FEAT_OUT) {
priv->chip.set = priv->data->set ? : syscon_gpio_set;
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
