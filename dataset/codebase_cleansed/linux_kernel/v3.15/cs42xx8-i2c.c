static int cs42xx8_i2c_probe(struct i2c_client *i2c,
const struct i2c_device_id *id)
{
u32 ret = cs42xx8_probe(&i2c->dev,
devm_regmap_init_i2c(i2c, &cs42xx8_regmap_config));
if (ret)
return ret;
pm_runtime_enable(&i2c->dev);
pm_request_idle(&i2c->dev);
return 0;
}
static int cs42xx8_i2c_remove(struct i2c_client *i2c)
{
snd_soc_unregister_codec(&i2c->dev);
pm_runtime_disable(&i2c->dev);
return 0;
}
