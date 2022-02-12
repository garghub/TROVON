static struct lantiq_rcu_reset_priv *to_lantiq_rcu_reset_priv(
struct reset_controller_dev *rcdev)
{
return container_of(rcdev, struct lantiq_rcu_reset_priv, rcdev);
}
static int lantiq_rcu_reset_status(struct reset_controller_dev *rcdev,
unsigned long id)
{
struct lantiq_rcu_reset_priv *priv = to_lantiq_rcu_reset_priv(rcdev);
unsigned int status = (id >> 8) & 0x1f;
u32 val;
int ret;
ret = regmap_read(priv->regmap, priv->status_offset, &val);
if (ret)
return ret;
return !!(val & BIT(status));
}
static int lantiq_rcu_reset_status_timeout(struct reset_controller_dev *rcdev,
unsigned long id, bool assert)
{
int ret;
int retry = LANTIQ_RCU_RESET_TIMEOUT;
do {
ret = lantiq_rcu_reset_status(rcdev, id);
if (ret < 0)
return ret;
if (ret == assert)
return 0;
usleep_range(20, 40);
} while (--retry);
return -ETIMEDOUT;
}
static int lantiq_rcu_reset_update(struct reset_controller_dev *rcdev,
unsigned long id, bool assert)
{
struct lantiq_rcu_reset_priv *priv = to_lantiq_rcu_reset_priv(rcdev);
unsigned int set = id & 0x1f;
u32 val = assert ? BIT(set) : 0;
int ret;
ret = regmap_update_bits(priv->regmap, priv->reset_offset, BIT(set),
val);
if (ret) {
dev_err(priv->dev, "Failed to set reset bit %u\n", set);
return ret;
}
ret = lantiq_rcu_reset_status_timeout(rcdev, id, assert);
if (ret)
dev_err(priv->dev, "Failed to %s bit %u\n",
assert ? "assert" : "deassert", set);
return ret;
}
static int lantiq_rcu_reset_assert(struct reset_controller_dev *rcdev,
unsigned long id)
{
return lantiq_rcu_reset_update(rcdev, id, true);
}
static int lantiq_rcu_reset_deassert(struct reset_controller_dev *rcdev,
unsigned long id)
{
return lantiq_rcu_reset_update(rcdev, id, false);
}
static int lantiq_rcu_reset_reset(struct reset_controller_dev *rcdev,
unsigned long id)
{
int ret;
ret = lantiq_rcu_reset_assert(rcdev, id);
if (ret)
return ret;
return lantiq_rcu_reset_deassert(rcdev, id);
}
static int lantiq_rcu_reset_of_parse(struct platform_device *pdev,
struct lantiq_rcu_reset_priv *priv)
{
struct device *dev = &pdev->dev;
const __be32 *offset;
priv->regmap = syscon_node_to_regmap(dev->of_node->parent);
if (IS_ERR(priv->regmap)) {
dev_err(&pdev->dev, "Failed to lookup RCU regmap\n");
return PTR_ERR(priv->regmap);
}
offset = of_get_address(dev->of_node, 0, NULL, NULL);
if (!offset) {
dev_err(&pdev->dev, "Failed to get RCU reset offset\n");
return -ENOENT;
}
priv->reset_offset = __be32_to_cpu(*offset);
offset = of_get_address(dev->of_node, 1, NULL, NULL);
if (!offset) {
dev_err(&pdev->dev, "Failed to get RCU status offset\n");
return -ENOENT;
}
priv->status_offset = __be32_to_cpu(*offset);
return 0;
}
static int lantiq_rcu_reset_xlate(struct reset_controller_dev *rcdev,
const struct of_phandle_args *reset_spec)
{
unsigned int status, set;
set = reset_spec->args[0];
status = reset_spec->args[1];
if (set >= rcdev->nr_resets || status >= rcdev->nr_resets)
return -EINVAL;
return (status << 8) | set;
}
static int lantiq_rcu_reset_probe(struct platform_device *pdev)
{
struct lantiq_rcu_reset_priv *priv;
int err;
priv = devm_kzalloc(&pdev->dev, sizeof(*priv), GFP_KERNEL);
if (!priv)
return -ENOMEM;
priv->dev = &pdev->dev;
platform_set_drvdata(pdev, priv);
err = lantiq_rcu_reset_of_parse(pdev, priv);
if (err)
return err;
priv->rcdev.ops = &lantiq_rcu_reset_ops;
priv->rcdev.owner = THIS_MODULE;
priv->rcdev.of_node = pdev->dev.of_node;
priv->rcdev.nr_resets = 32;
priv->rcdev.of_xlate = lantiq_rcu_reset_xlate;
priv->rcdev.of_reset_n_cells = 2;
return reset_controller_register(&priv->rcdev);
}
