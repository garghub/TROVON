static int sky81452_probe(struct i2c_client *client,
const struct i2c_device_id *id)
{
struct device *dev = &client->dev;
const struct sky81452_platform_data *pdata = dev_get_platdata(dev);
struct mfd_cell cells[2];
struct regmap *regmap;
int ret;
if (!pdata) {
pdata = devm_kzalloc(dev, sizeof(*pdata), GFP_KERNEL);
if (!pdata)
return -ENOMEM;
}
regmap = devm_regmap_init_i2c(client, &sky81452_config);
if (IS_ERR(regmap)) {
dev_err(dev, "failed to initialize.err=%ld\n", PTR_ERR(regmap));
return PTR_ERR(regmap);
}
i2c_set_clientdata(client, regmap);
memset(cells, 0, sizeof(cells));
cells[0].name = "sky81452-backlight";
cells[0].of_compatible = "skyworks,sky81452-backlight";
cells[0].platform_data = pdata->bl_pdata;
cells[0].pdata_size = sizeof(*pdata->bl_pdata);
cells[1].name = "sky81452-regulator";
cells[1].platform_data = pdata->regulator_init_data;
cells[1].pdata_size = sizeof(*pdata->regulator_init_data);
ret = devm_mfd_add_devices(dev, -1, cells, ARRAY_SIZE(cells),
NULL, 0, NULL);
if (ret)
dev_err(dev, "failed to add child devices. err=%d\n", ret);
return ret;
}
