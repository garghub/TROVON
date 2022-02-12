static int pcm179x_i2c_probe(struct i2c_client *client,
const struct i2c_device_id *id)
{
struct regmap *regmap;
int ret;
regmap = devm_regmap_init_i2c(client, &pcm179x_regmap_config);
if (IS_ERR(regmap)) {
ret = PTR_ERR(regmap);
dev_err(&client->dev, "Failed to allocate regmap: %d\n", ret);
return ret;
}
return pcm179x_common_init(&client->dev, regmap);
}
static int pcm179x_i2c_remove(struct i2c_client *client)
{
return pcm179x_common_exit(&client->dev);
}
