static int sky81452_reg_probe(struct platform_device *pdev)
{
struct device *dev = &pdev->dev;
const struct regulator_init_data *init_data = dev_get_platdata(dev);
struct regulator_config config = { };
struct regulator_dev *rdev;
config.dev = dev->parent;
config.init_data = init_data;
config.of_node = dev->of_node;
config.regmap = dev_get_drvdata(dev->parent);
rdev = devm_regulator_register(dev, &sky81452_reg, &config);
if (IS_ERR(rdev)) {
dev_err(dev, "failed to register. err=%ld\n", PTR_ERR(rdev));
return PTR_ERR(rdev);
}
platform_set_drvdata(pdev, rdev);
return 0;
}
