static int uniphier_reset_update(struct reset_controller_dev *rcdev,
unsigned long id, int assert)
{
struct uniphier_reset_priv *priv = to_uniphier_reset_priv(rcdev);
const struct uniphier_reset_data *p;
for (p = priv->data; p->id != UNIPHIER_RESET_ID_END; p++) {
unsigned int mask, val;
if (p->id != id)
continue;
mask = BIT(p->bit);
if (assert)
val = mask;
else
val = ~mask;
if (p->flags & UNIPHIER_RESET_ACTIVE_LOW)
val = ~val;
return regmap_write_bits(priv->regmap, p->reg, mask, val);
}
dev_err(priv->dev, "reset_id=%lu was not handled\n", id);
return -EINVAL;
}
static int uniphier_reset_assert(struct reset_controller_dev *rcdev,
unsigned long id)
{
return uniphier_reset_update(rcdev, id, 1);
}
static int uniphier_reset_deassert(struct reset_controller_dev *rcdev,
unsigned long id)
{
return uniphier_reset_update(rcdev, id, 0);
}
static int uniphier_reset_status(struct reset_controller_dev *rcdev,
unsigned long id)
{
struct uniphier_reset_priv *priv = to_uniphier_reset_priv(rcdev);
const struct uniphier_reset_data *p;
for (p = priv->data; p->id != UNIPHIER_RESET_ID_END; p++) {
unsigned int val;
int ret, asserted;
if (p->id != id)
continue;
ret = regmap_read(priv->regmap, p->reg, &val);
if (ret)
return ret;
asserted = !!(val & BIT(p->bit));
if (p->flags & UNIPHIER_RESET_ACTIVE_LOW)
asserted = !asserted;
return asserted;
}
dev_err(priv->dev, "reset_id=%lu was not found\n", id);
return -EINVAL;
}
static int uniphier_reset_probe(struct platform_device *pdev)
{
struct device *dev = &pdev->dev;
struct uniphier_reset_priv *priv;
const struct uniphier_reset_data *p, *data;
struct regmap *regmap;
struct device_node *parent;
unsigned int nr_resets = 0;
data = of_device_get_match_data(dev);
if (WARN_ON(!data))
return -EINVAL;
parent = of_get_parent(dev->of_node);
regmap = syscon_node_to_regmap(parent);
of_node_put(parent);
if (IS_ERR(regmap)) {
dev_err(dev, "failed to get regmap (error %ld)\n",
PTR_ERR(regmap));
return PTR_ERR(regmap);
}
priv = devm_kzalloc(dev, sizeof(*priv), GFP_KERNEL);
if (!priv)
return -ENOMEM;
for (p = data; p->id != UNIPHIER_RESET_ID_END; p++)
nr_resets = max(nr_resets, p->id + 1);
priv->rcdev.ops = &uniphier_reset_ops;
priv->rcdev.owner = dev->driver->owner;
priv->rcdev.of_node = dev->of_node;
priv->rcdev.nr_resets = nr_resets;
priv->dev = dev;
priv->regmap = regmap;
priv->data = data;
return devm_reset_controller_register(&pdev->dev, &priv->rcdev);
}
