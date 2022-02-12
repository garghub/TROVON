static struct regulator_init_data *sky81452_reg_parse_dt(struct device *dev)
{
struct regulator_init_data *init_data;
struct device_node *np;
np = of_get_child_by_name(dev->parent->of_node, "regulator");
if (unlikely(!np)) {
dev_err(dev, "regulator node not found");
return NULL;
}
init_data = of_get_regulator_init_data(dev, np);
of_node_put(np);
return init_data;
}
static struct regulator_init_data *sky81452_reg_parse_dt(struct device *dev)
{
return ERR_PTR(-EINVAL);
}
static int sky81452_reg_probe(struct platform_device *pdev)
{
struct device *dev = &pdev->dev;
const struct regulator_init_data *init_data = dev_get_platdata(dev);
struct regulator_config config = { };
struct regulator_dev *rdev;
if (!init_data) {
init_data = sky81452_reg_parse_dt(dev);
if (IS_ERR(init_data))
return PTR_ERR(init_data);
}
config.dev = dev;
config.init_data = init_data;
config.of_node = dev->of_node;
config.regmap = dev_get_drvdata(dev->parent);
rdev = devm_regulator_register(dev, &sky81452_reg, &config);
if (IS_ERR(rdev))
return PTR_ERR(rdev);
platform_set_drvdata(pdev, rdev);
return 0;
}
