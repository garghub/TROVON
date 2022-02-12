static int axp20x_rsb_probe(struct sunxi_rsb_device *rdev)
{
struct axp20x_dev *axp20x;
int ret;
axp20x = devm_kzalloc(&rdev->dev, sizeof(*axp20x), GFP_KERNEL);
if (!axp20x)
return -ENOMEM;
axp20x->dev = &rdev->dev;
axp20x->irq = rdev->irq;
dev_set_drvdata(&rdev->dev, axp20x);
ret = axp20x_match_device(axp20x);
if (ret)
return ret;
axp20x->regmap = devm_regmap_init_sunxi_rsb(rdev, axp20x->regmap_cfg);
if (IS_ERR(axp20x->regmap)) {
ret = PTR_ERR(axp20x->regmap);
dev_err(&rdev->dev, "regmap init failed: %d\n", ret);
return ret;
}
return axp20x_device_probe(axp20x);
}
static int axp20x_rsb_remove(struct sunxi_rsb_device *rdev)
{
struct axp20x_dev *axp20x = sunxi_rsb_device_get_drvdata(rdev);
return axp20x_device_remove(axp20x);
}
