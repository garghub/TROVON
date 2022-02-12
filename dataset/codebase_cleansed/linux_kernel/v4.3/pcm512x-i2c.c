static int pcm512x_i2c_probe(struct i2c_client *i2c,
const struct i2c_device_id *id)
{
struct regmap *regmap;
struct regmap_config config = pcm512x_regmap;
config.read_flag_mask = 0x80;
config.write_flag_mask = 0x80;
regmap = devm_regmap_init_i2c(i2c, &config);
if (IS_ERR(regmap))
return PTR_ERR(regmap);
return pcm512x_probe(&i2c->dev, regmap);
}
static int pcm512x_i2c_remove(struct i2c_client *i2c)
{
pcm512x_remove(&i2c->dev);
return 0;
}
