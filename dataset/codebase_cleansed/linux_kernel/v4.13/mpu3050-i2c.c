static int mpu3050_i2c_bypass_select(struct i2c_mux_core *mux, u32 chan_id)
{
struct mpu3050 *mpu3050 = i2c_mux_priv(mux);
pm_runtime_get_sync(mpu3050->dev);
return 0;
}
static int mpu3050_i2c_bypass_deselect(struct i2c_mux_core *mux, u32 chan_id)
{
struct mpu3050 *mpu3050 = i2c_mux_priv(mux);
pm_runtime_mark_last_busy(mpu3050->dev);
pm_runtime_put_autosuspend(mpu3050->dev);
return 0;
}
static int mpu3050_i2c_probe(struct i2c_client *client,
const struct i2c_device_id *id)
{
struct regmap *regmap;
const char *name;
struct mpu3050 *mpu3050;
int ret;
if (!i2c_check_functionality(client->adapter,
I2C_FUNC_SMBUS_I2C_BLOCK))
return -EOPNOTSUPP;
if (id)
name = id->name;
else
return -ENODEV;
regmap = devm_regmap_init_i2c(client, &mpu3050_i2c_regmap_config);
if (IS_ERR(regmap)) {
dev_err(&client->dev, "Failed to register i2c regmap %d\n",
(int)PTR_ERR(regmap));
return PTR_ERR(regmap);
}
ret = mpu3050_common_probe(&client->dev, regmap, client->irq, name);
if (ret)
return ret;
mpu3050 = iio_priv(dev_get_drvdata(&client->dev));
mpu3050->i2cmux = i2c_mux_alloc(client->adapter, &client->dev,
1, 0, I2C_MUX_LOCKED | I2C_MUX_GATE,
mpu3050_i2c_bypass_select,
mpu3050_i2c_bypass_deselect);
if (!mpu3050->i2cmux)
dev_err(&client->dev, "failed to allocate I2C mux\n");
else {
mpu3050->i2cmux->priv = mpu3050;
i2c_mux_add_adapter(mpu3050->i2cmux, 0, 0, 0);
}
return 0;
}
static int mpu3050_i2c_remove(struct i2c_client *client)
{
struct iio_dev *indio_dev = dev_get_drvdata(&client->dev);
struct mpu3050 *mpu3050 = iio_priv(indio_dev);
if (mpu3050->i2cmux)
i2c_mux_del_adapters(mpu3050->i2cmux);
return mpu3050_common_remove(&client->dev);
}
