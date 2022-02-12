static int kxsd9_i2c_probe(struct i2c_client *i2c,
const struct i2c_device_id *id)
{
static const struct regmap_config config = {
.reg_bits = 8,
.val_bits = 8,
.max_register = 0x0e,
};
struct regmap *regmap;
regmap = devm_regmap_init_i2c(i2c, &config);
if (IS_ERR(regmap)) {
dev_err(&i2c->dev, "Failed to register i2c regmap %d\n",
(int)PTR_ERR(regmap));
return PTR_ERR(regmap);
}
return kxsd9_common_probe(&i2c->dev,
regmap,
i2c->name);
}
static int kxsd9_i2c_remove(struct i2c_client *client)
{
return kxsd9_common_remove(&client->dev);
}
