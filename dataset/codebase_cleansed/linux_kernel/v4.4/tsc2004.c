static int tsc2004_cmd(struct device *dev, u8 cmd)
{
u8 tx = TSC200X_CMD | TSC200X_CMD_12BIT | cmd;
s32 data;
struct i2c_client *i2c = to_i2c_client(dev);
data = i2c_smbus_write_byte(i2c, tx);
if (data < 0) {
dev_err(dev, "%s: failed, command: %x i2c error: %d\n",
__func__, cmd, data);
return data;
}
return 0;
}
static int tsc2004_probe(struct i2c_client *i2c,
const struct i2c_device_id *id)
{
return tsc200x_probe(&i2c->dev, i2c->irq, BUS_I2C,
devm_regmap_init_i2c(i2c, &tsc200x_regmap_config),
tsc2004_cmd);
}
static int tsc2004_remove(struct i2c_client *i2c)
{
return tsc200x_remove(&i2c->dev);
}
