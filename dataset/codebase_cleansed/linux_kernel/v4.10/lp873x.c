static int lp873x_probe(struct i2c_client *client,
const struct i2c_device_id *ids)
{
struct lp873x *lp873;
int ret;
unsigned int otpid;
lp873 = devm_kzalloc(&client->dev, sizeof(*lp873), GFP_KERNEL);
if (!lp873)
return -ENOMEM;
lp873->dev = &client->dev;
lp873->regmap = devm_regmap_init_i2c(client, &lp873x_regmap_config);
if (IS_ERR(lp873->regmap)) {
ret = PTR_ERR(lp873->regmap);
dev_err(lp873->dev,
"Failed to initialize register map: %d\n", ret);
return ret;
}
ret = regmap_read(lp873->regmap, LP873X_REG_OTP_REV, &otpid);
if (ret) {
dev_err(lp873->dev, "Failed to read OTP ID\n");
return ret;
}
lp873->rev = otpid & LP873X_OTP_REV_OTP_ID;
i2c_set_clientdata(client, lp873);
ret = mfd_add_devices(lp873->dev, PLATFORM_DEVID_AUTO, lp873x_cells,
ARRAY_SIZE(lp873x_cells), NULL, 0, NULL);
return ret;
}
