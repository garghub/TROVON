static int tps65912_i2c_probe(struct i2c_client *client,
const struct i2c_device_id *ids)
{
struct tps65912 *tps;
tps = devm_kzalloc(&client->dev, sizeof(*tps), GFP_KERNEL);
if (!tps)
return -ENOMEM;
i2c_set_clientdata(client, tps);
tps->dev = &client->dev;
tps->irq = client->irq;
tps->regmap = devm_regmap_init_i2c(client, &tps65912_regmap_config);
if (IS_ERR(tps->regmap)) {
dev_err(tps->dev, "Failed to initialize register map\n");
return PTR_ERR(tps->regmap);
}
return tps65912_device_init(tps);
}
static int tps65912_i2c_remove(struct i2c_client *client)
{
struct tps65912 *tps = i2c_get_clientdata(client);
return tps65912_device_exit(tps);
}
