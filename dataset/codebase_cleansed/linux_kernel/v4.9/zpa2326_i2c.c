static unsigned int zpa2326_i2c_hwid(const struct i2c_client *client)
{
#define ZPA2326_SA0(_addr) (_addr & BIT(0))
#define ZPA2326_DEVICE_ID_SA0_SHIFT (1)
return (ZPA2326_DEVICE_ID |
(ZPA2326_SA0(client->addr) << ZPA2326_DEVICE_ID_SA0_SHIFT));
}
static int zpa2326_probe_i2c(struct i2c_client *client,
const struct i2c_device_id *i2c_id)
{
struct regmap *regmap;
regmap = devm_regmap_init_i2c(client, &zpa2326_regmap_i2c_config);
if (IS_ERR(regmap)) {
dev_err(&client->dev, "failed to init registers map");
return PTR_ERR(regmap);
}
return zpa2326_probe(&client->dev, i2c_id->name, client->irq,
zpa2326_i2c_hwid(client), regmap);
}
static int zpa2326_remove_i2c(struct i2c_client *client)
{
zpa2326_remove(&client->dev);
return 0;
}
