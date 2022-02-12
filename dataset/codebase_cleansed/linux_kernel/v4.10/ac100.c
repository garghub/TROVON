static int ac100_rsb_probe(struct sunxi_rsb_device *rdev)
{
struct ac100_dev *ac100;
int ret;
ac100 = devm_kzalloc(&rdev->dev, sizeof(*ac100), GFP_KERNEL);
if (!ac100)
return -ENOMEM;
ac100->dev = &rdev->dev;
sunxi_rsb_device_set_drvdata(rdev, ac100);
ac100->regmap = devm_regmap_init_sunxi_rsb(rdev, &ac100_regmap_config);
if (IS_ERR(ac100->regmap)) {
ret = PTR_ERR(ac100->regmap);
dev_err(ac100->dev, "regmap init failed: %d\n", ret);
return ret;
}
ret = devm_mfd_add_devices(ac100->dev, PLATFORM_DEVID_NONE, ac100_cells,
ARRAY_SIZE(ac100_cells), NULL, 0, NULL);
if (ret) {
dev_err(ac100->dev, "failed to add MFD devices: %d\n", ret);
return ret;
}
return 0;
}
