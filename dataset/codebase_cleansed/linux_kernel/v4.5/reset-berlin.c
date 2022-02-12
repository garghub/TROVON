static int berlin_reset_reset(struct reset_controller_dev *rcdev,
unsigned long id)
{
struct berlin_reset_priv *priv = to_berlin_reset_priv(rcdev);
int offset = id >> 8;
int mask = BIT(id & 0x1f);
regmap_write(priv->regmap, offset, mask);
udelay(10);
return 0;
}
static int berlin_reset_xlate(struct reset_controller_dev *rcdev,
const struct of_phandle_args *reset_spec)
{
unsigned offset, bit;
if (WARN_ON(reset_spec->args_count != rcdev->of_reset_n_cells))
return -EINVAL;
offset = reset_spec->args[0];
bit = reset_spec->args[1];
if (bit >= BERLIN_MAX_RESETS)
return -EINVAL;
return (offset << 8) | bit;
}
static int berlin2_reset_probe(struct platform_device *pdev)
{
struct device_node *parent_np = of_get_parent(pdev->dev.of_node);
struct berlin_reset_priv *priv;
priv = devm_kzalloc(&pdev->dev, sizeof(*priv), GFP_KERNEL);
if (!priv)
return -ENOMEM;
priv->regmap = syscon_node_to_regmap(parent_np);
of_node_put(parent_np);
if (IS_ERR(priv->regmap))
return PTR_ERR(priv->regmap);
priv->rcdev.owner = THIS_MODULE;
priv->rcdev.ops = &berlin_reset_ops;
priv->rcdev.of_node = pdev->dev.of_node;
priv->rcdev.of_reset_n_cells = 2;
priv->rcdev.of_xlate = berlin_reset_xlate;
return reset_controller_register(&priv->rcdev);
}
