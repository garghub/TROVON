static int mc13xxx_i2c_probe(struct i2c_client *client,
const struct i2c_device_id *id)
{
const struct of_device_id *of_id;
struct i2c_driver *idrv = to_i2c_driver(client->dev.driver);
struct mc13xxx *mc13xxx;
struct mc13xxx_platform_data *pdata = dev_get_platdata(&client->dev);
int ret;
of_id = of_match_device(mc13xxx_dt_ids, &client->dev);
if (of_id)
idrv->id_table = (const struct i2c_device_id*) of_id->data;
mc13xxx = kzalloc(sizeof(*mc13xxx), GFP_KERNEL);
if (!mc13xxx)
return -ENOMEM;
dev_set_drvdata(&client->dev, mc13xxx);
mc13xxx->dev = &client->dev;
mutex_init(&mc13xxx->lock);
mc13xxx->regmap = regmap_init_i2c(client, &mc13xxx_regmap_i2c_config);
if (IS_ERR(mc13xxx->regmap)) {
ret = PTR_ERR(mc13xxx->regmap);
dev_err(mc13xxx->dev, "Failed to initialize register map: %d\n",
ret);
dev_set_drvdata(&client->dev, NULL);
kfree(mc13xxx);
return ret;
}
ret = mc13xxx_common_init(mc13xxx, pdata, client->irq);
if (ret == 0 && (id->driver_data != mc13xxx->ictype))
dev_warn(mc13xxx->dev,
"device id doesn't match auto detection!\n");
return ret;
}
static int __devexit mc13xxx_i2c_remove(struct i2c_client *client)
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
