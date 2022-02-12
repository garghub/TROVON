static int lan9303_i2c_probe(struct i2c_client *client,
const struct i2c_device_id *id)
{
struct lan9303_i2c *sw_dev;
int ret;
sw_dev = devm_kzalloc(&client->dev, sizeof(struct lan9303_i2c),
GFP_KERNEL);
if (!sw_dev)
return -ENOMEM;
sw_dev->chip.regmap = devm_regmap_init_i2c(client,
&lan9303_i2c_regmap_config);
if (IS_ERR(sw_dev->chip.regmap)) {
ret = PTR_ERR(sw_dev->chip.regmap);
dev_err(&client->dev, "Failed to allocate register map: %d\n",
ret);
return ret;
}
sw_dev->device = client;
i2c_set_clientdata(client, sw_dev);
sw_dev->chip.dev = &client->dev;
sw_dev->chip.ops = &lan9303_indirect_phy_ops;
ret = lan9303_probe(&sw_dev->chip, client->dev.of_node);
if (ret != 0)
return ret;
dev_info(&client->dev, "LAN9303 I2C driver loaded successfully\n");
return 0;
}
static int lan9303_i2c_remove(struct i2c_client *client)
{
struct lan9303_i2c *sw_dev;
sw_dev = i2c_get_clientdata(client);
if (!sw_dev)
return -ENODEV;
return lan9303_remove(&sw_dev->chip);
}
