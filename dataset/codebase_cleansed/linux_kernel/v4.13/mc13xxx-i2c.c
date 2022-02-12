static int mc13xxx_i2c_probe(struct i2c_client *client,
const struct i2c_device_id *id)
{
struct mc13xxx *mc13xxx;
int ret;
mc13xxx = devm_kzalloc(&client->dev, sizeof(*mc13xxx), GFP_KERNEL);
if (!mc13xxx)
return -ENOMEM;
dev_set_drvdata(&client->dev, mc13xxx);
mc13xxx->irq = client->irq;
mc13xxx->regmap = devm_regmap_init_i2c(client,
&mc13xxx_regmap_i2c_config);
if (IS_ERR(mc13xxx->regmap)) {
ret = PTR_ERR(mc13xxx->regmap);
dev_err(&client->dev, "Failed to initialize regmap: %d\n", ret);
return ret;
}
if (client->dev.of_node) {
const struct of_device_id *of_id =
of_match_device(mc13xxx_dt_ids, &client->dev);
mc13xxx->variant = of_id->data;
} else {
mc13xxx->variant = (void *)id->driver_data;
}
return mc13xxx_common_init(&client->dev);
}
static int mc13xxx_i2c_remove(struct i2c_client *client)
{
return mc13xxx_common_exit(&client->dev);
}
static int __init mc13xxx_i2c_init(void)
{
return i2c_add_driver(&mc13xxx_i2c_driver);
}
static void __exit mc13xxx_i2c_exit(void)
{
i2c_del_driver(&mc13xxx_i2c_driver);
}
