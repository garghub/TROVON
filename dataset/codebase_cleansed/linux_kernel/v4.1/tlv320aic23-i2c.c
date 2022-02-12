static int tlv320aic23_i2c_probe(struct i2c_client *i2c,
const struct i2c_device_id *i2c_id)
{
struct regmap *regmap;
if (!i2c_check_functionality(i2c->adapter, I2C_FUNC_SMBUS_BYTE_DATA))
return -EINVAL;
regmap = devm_regmap_init_i2c(i2c, &tlv320aic23_regmap);
return tlv320aic23_probe(&i2c->dev, regmap);
}
static int tlv320aic23_i2c_remove(struct i2c_client *i2c)
{
snd_soc_unregister_codec(&i2c->dev);
return 0;
}
