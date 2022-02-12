static int mc13xxx_i2c_probe(struct i2c_client *client,
const struct i2c_device_id *id)
{
struct mc13xxx *mc13xxx;
struct mc13xxx_platform_data *pdata = dev_get_platdata(&client->dev);
int ret;
mc13xxx = devm_kzalloc(&client->dev, sizeof(*mc13xxx), GFP_KERNEL);
if (!mc13xxx)
return -ENOMEM;
dev_set_drvdata(&client->dev, mc13xxx);
mc13xxx->dev = &client->dev;
mutex_init(&mc13xxx->lock);
mc13xxx->regmap = devm_regmap_init_i2c(client,
&mc13xxx_regmap_i2c_config);
if (IS_ERR(mc13xxx->regmap)) {
ret = PTR_ERR(mc13xxx->regmap);
dev_err(mc13xxx->dev, "Failed to initialize register map: %d\n",
ret);
return ret;
}
if (client->dev.of_node) {
const struct of_device_id *of_id =
of_match_device(mc13xxx_dt_ids, &client->dev);
mc13xxx->variant = of_id->data;
} else {
mc13xxx->variant = (void *)id->driver_data;
}
ret = mc13xxx_common_init(mc13xxx, pdata, client->irq);
return ret;
}
static int mc13xxx_i2c_remove(struct i2c_client *client)
{
struct mc13xxx *mc13xxx = dev_get_drvdata(&client->dev);
mc13xxx_common_cleanup(mc13xxx);
return 0;
}
static int __init mc13xxx_i2c_init(void)
{
return i2c_add_driver(&mc13xxx_i2c_driver);
}
static void __exit mc13xxx_i2c_exit(void)
{
i2c_del_driver(&mc13xxx_i2c_driver);
}
