static int inv_mpu6050_select_bypass(struct i2c_mux_core *muxc, u32 chan_id)
{
struct iio_dev *indio_dev = i2c_mux_priv(muxc);
struct inv_mpu6050_state *st = iio_priv(indio_dev);
int ret = 0;
mutex_lock(&st->lock);
if (!st->powerup_count) {
ret = regmap_write(st->map, st->reg->pwr_mgmt_1, 0);
if (ret)
goto write_error;
usleep_range(INV_MPU6050_REG_UP_TIME_MIN,
INV_MPU6050_REG_UP_TIME_MAX);
}
if (!ret) {
st->powerup_count++;
ret = regmap_write(st->map, st->reg->int_pin_cfg,
INV_MPU6050_INT_PIN_CFG |
INV_MPU6050_BIT_BYPASS_EN);
}
write_error:
mutex_unlock(&st->lock);
return ret;
}
static int inv_mpu6050_deselect_bypass(struct i2c_mux_core *muxc, u32 chan_id)
{
struct iio_dev *indio_dev = i2c_mux_priv(muxc);
struct inv_mpu6050_state *st = iio_priv(indio_dev);
mutex_lock(&st->lock);
regmap_write(st->map, st->reg->int_pin_cfg, INV_MPU6050_INT_PIN_CFG);
st->powerup_count--;
if (!st->powerup_count)
regmap_write(st->map, st->reg->pwr_mgmt_1,
INV_MPU6050_BIT_SLEEP);
mutex_unlock(&st->lock);
return 0;
}
static const char *inv_mpu_match_acpi_device(struct device *dev,
enum inv_devices *chip_id)
{
const struct acpi_device_id *id;
id = acpi_match_device(dev->driver->acpi_match_table, dev);
if (!id)
return NULL;
*chip_id = (int)id->driver_data;
return dev_name(dev);
}
static int inv_mpu_probe(struct i2c_client *client,
const struct i2c_device_id *id)
{
struct inv_mpu6050_state *st;
int result;
enum inv_devices chip_type;
struct regmap *regmap;
const char *name;
if (!i2c_check_functionality(client->adapter,
I2C_FUNC_SMBUS_I2C_BLOCK))
return -EOPNOTSUPP;
if (client->dev.of_node) {
chip_type = (enum inv_devices)
of_device_get_match_data(&client->dev);
name = client->name;
} else if (id) {
chip_type = (enum inv_devices)
id->driver_data;
name = id->name;
} else if (ACPI_HANDLE(&client->dev)) {
name = inv_mpu_match_acpi_device(&client->dev, &chip_type);
if (!name)
return -ENODEV;
} else {
return -ENOSYS;
}
regmap = devm_regmap_init_i2c(client, &inv_mpu_regmap_config);
if (IS_ERR(regmap)) {
dev_err(&client->dev, "Failed to register i2c regmap %d\n",
(int)PTR_ERR(regmap));
return PTR_ERR(regmap);
}
result = inv_mpu_core_probe(regmap, client->irq, name,
NULL, chip_type);
if (result < 0)
return result;
st = iio_priv(dev_get_drvdata(&client->dev));
st->muxc = i2c_mux_alloc(client->adapter, &client->dev,
1, 0, I2C_MUX_LOCKED | I2C_MUX_GATE,
inv_mpu6050_select_bypass,
inv_mpu6050_deselect_bypass);
if (!st->muxc) {
result = -ENOMEM;
goto out_unreg_device;
}
st->muxc->priv = dev_get_drvdata(&client->dev);
result = i2c_mux_add_adapter(st->muxc, 0, 0, 0);
if (result)
goto out_unreg_device;
result = inv_mpu_acpi_create_mux_client(client);
if (result)
goto out_del_mux;
return 0;
out_del_mux:
i2c_mux_del_adapters(st->muxc);
out_unreg_device:
inv_mpu_core_remove(&client->dev);
return result;
}
static int inv_mpu_remove(struct i2c_client *client)
{
struct iio_dev *indio_dev = i2c_get_clientdata(client);
struct inv_mpu6050_state *st = iio_priv(indio_dev);
inv_mpu_acpi_delete_mux_client(client);
i2c_mux_del_adapters(st->muxc);
return inv_mpu_core_remove(&client->dev);
}
