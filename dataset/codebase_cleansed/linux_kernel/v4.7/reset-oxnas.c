static int oxnas_reset_reset(struct reset_controller_dev *rcdev,
unsigned long id)
{
struct oxnas_reset *data =
container_of(rcdev, struct oxnas_reset, rcdev);
regmap_write(data->regmap, RST_SET_REGOFFSET, BIT(id));
msleep(50);
regmap_write(data->regmap, RST_CLR_REGOFFSET, BIT(id));
return 0;
}
static int oxnas_reset_assert(struct reset_controller_dev *rcdev,
unsigned long id)
{
struct oxnas_reset *data =
container_of(rcdev, struct oxnas_reset, rcdev);
regmap_write(data->regmap, RST_SET_REGOFFSET, BIT(id));
return 0;
}
static int oxnas_reset_deassert(struct reset_controller_dev *rcdev,
unsigned long id)
{
struct oxnas_reset *data =
container_of(rcdev, struct oxnas_reset, rcdev);
regmap_write(data->regmap, RST_CLR_REGOFFSET, BIT(id));
return 0;
}
static int oxnas_reset_probe(struct platform_device *pdev)
{
struct oxnas_reset *data;
struct device *parent;
parent = pdev->dev.parent;
if (!parent) {
dev_err(&pdev->dev, "no parent\n");
return -ENODEV;
}
data = devm_kzalloc(&pdev->dev, sizeof(*data), GFP_KERNEL);
if (!data)
return -ENOMEM;
data->regmap = syscon_node_to_regmap(parent->of_node);
if (IS_ERR(data->regmap)) {
dev_err(&pdev->dev, "failed to get parent regmap\n");
return PTR_ERR(data->regmap);
}
platform_set_drvdata(pdev, data);
data->rcdev.owner = THIS_MODULE;
data->rcdev.nr_resets = 32;
data->rcdev.ops = &oxnas_reset_ops;
data->rcdev.of_node = pdev->dev.of_node;
return reset_controller_register(&data->rcdev);
}
static int oxnas_reset_remove(struct platform_device *pdev)
{
struct oxnas_reset *data = platform_get_drvdata(pdev);
reset_controller_unregister(&data->rcdev);
return 0;
}
