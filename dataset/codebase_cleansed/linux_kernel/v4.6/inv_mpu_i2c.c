static int inv_mpu6050_write_reg_unlocked(struct i2c_client *client,
u8 reg, u8 d)
{
int ret;
u8 buf[2] = {reg, d};
struct i2c_msg msg[1] = {
{
.addr = client->addr,
.flags = 0,
.len = sizeof(buf),
.buf = buf,
}
};
ret = __i2c_transfer(client->adapter, msg, 1);
if (ret != 1)
return ret;
return 0;
}
static int inv_mpu6050_select_bypass(struct i2c_adapter *adap, void *mux_priv,
u32 chan_id)
{
struct i2c_client *client = mux_priv;
struct iio_dev *indio_dev = dev_get_drvdata(&client->dev);
struct inv_mpu6050_state *st = iio_priv(indio_dev);
int ret = 0;
mutex_lock(&indio_dev->mlock);
if (!st->powerup_count) {
ret = inv_mpu6050_write_reg_unlocked(client,
st->reg->pwr_mgmt_1, 0);
if (ret)
goto write_error;
usleep_range(INV_MPU6050_REG_UP_TIME_MIN,
INV_MPU6050_REG_UP_TIME_MAX);
}
if (!ret) {
st->powerup_count++;
ret = inv_mpu6050_write_reg_unlocked(client,
st->reg->int_pin_cfg,
INV_MPU6050_INT_PIN_CFG |
INV_MPU6050_BIT_BYPASS_EN);
}
write_error:
mutex_unlock(&indio_dev->mlock);
return ret;
}
static int inv_mpu6050_deselect_bypass(struct i2c_adapter *adap,
void *mux_priv, u32 chan_id)
{
struct i2c_client *client = mux_priv;
struct iio_dev *indio_dev = dev_get_drvdata(&client->dev);
struct inv_mpu6050_state *st = iio_priv(indio_dev);
mutex_lock(&indio_dev->mlock);
inv_mpu6050_write_reg_unlocked(client, st->reg->int_pin_cfg,
INV_MPU6050_INT_PIN_CFG);
st->powerup_count--;
if (!st->powerup_count)
inv_mpu6050_write_reg_unlocked(client, st->reg->pwr_mgmt_1,
INV_MPU6050_BIT_SLEEP);
mutex_unlock(&indio_dev->mlock);
return 0;
}
static const char *inv_mpu_match_acpi_device(struct device *dev, int *chip_id)
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
int result, chip_type;
struct regmap *regmap;
const char *name;
if (!i2c_check_functionality(client->adapter,
I2C_FUNC_SMBUS_I2C_BLOCK))
return -EOPNOTSUPP;
if (id) {
chip_type = (int)id->driver_data;
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
st->mux_adapter = i2c_add_mux_adapter(client->adapter,
&client->dev,
client,
0, 0, 0,
inv_mpu6050_select_bypass,
inv_mpu6050_deselect_bypass);
if (!st->mux_adapter) {
result = -ENODEV;
goto out_unreg_device;
}
result = inv_mpu_acpi_create_mux_client(client);
if (result)
goto out_del_mux;
return 0;
out_del_mux:
i2c_del_mux_adapter(st->mux_adapter);
out_unreg_device:
inv_mpu_core_remove(&client->dev);
return result;
}
static int inv_mpu_remove(struct i2c_client *client)
{
struct iio_dev *indio_dev = i2c_get_clientdata(client);
struct inv_mpu6050_state *st = iio_priv(indio_dev);
inv_mpu_acpi_delete_mux_client(client);
i2c_del_mux_adapter(st->mux_adapter);
return inv_mpu_core_remove(&client->dev);
}
