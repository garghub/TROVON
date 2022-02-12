static int stw481x_vmmc_regulator_probe(struct platform_device *pdev)
{
struct stw481x *stw481x = dev_get_platdata(&pdev->dev);
struct regulator_config config = { };
struct regulator_dev *rdev;
int ret;
ret = regmap_update_bits(stw481x->map, STW_CONF2,
STW_CONF2_VMMC_EXT, 0);
if (ret) {
dev_err(&pdev->dev, "could not disable external VMMC\n");
return ret;
}
config.dev = &pdev->dev;
config.driver_data = stw481x;
config.regmap = stw481x->map;
config.of_node = pdev->dev.of_node;
config.init_data = of_get_regulator_init_data(&pdev->dev,
pdev->dev.of_node,
&vmmc_regulator);
rdev = devm_regulator_register(&pdev->dev, &vmmc_regulator, &config);
if (IS_ERR(rdev)) {
dev_err(&pdev->dev,
"error initializing STw481x VMMC regulator\n");
return PTR_ERR(rdev);
}
dev_info(&pdev->dev, "initialized STw481x VMMC regulator\n");
return 0;
}
