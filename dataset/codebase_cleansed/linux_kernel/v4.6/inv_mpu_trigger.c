static void inv_scan_query(struct iio_dev *indio_dev)
{
struct inv_mpu6050_state *st = iio_priv(indio_dev);
st->chip_config.gyro_fifo_enable =
test_bit(INV_MPU6050_SCAN_GYRO_X,
indio_dev->active_scan_mask) ||
test_bit(INV_MPU6050_SCAN_GYRO_Y,
indio_dev->active_scan_mask) ||
test_bit(INV_MPU6050_SCAN_GYRO_Z,
indio_dev->active_scan_mask);
st->chip_config.accl_fifo_enable =
test_bit(INV_MPU6050_SCAN_ACCL_X,
indio_dev->active_scan_mask) ||
test_bit(INV_MPU6050_SCAN_ACCL_Y,
indio_dev->active_scan_mask) ||
test_bit(INV_MPU6050_SCAN_ACCL_Z,
indio_dev->active_scan_mask);
}
static int inv_mpu6050_set_enable(struct iio_dev *indio_dev, bool enable)
{
struct inv_mpu6050_state *st = iio_priv(indio_dev);
int result;
if (enable) {
result = inv_mpu6050_set_power_itg(st, true);
if (result)
return result;
inv_scan_query(indio_dev);
if (st->chip_config.gyro_fifo_enable) {
result = inv_mpu6050_switch_engine(st, true,
INV_MPU6050_BIT_PWR_GYRO_STBY);
if (result)
return result;
}
if (st->chip_config.accl_fifo_enable) {
result = inv_mpu6050_switch_engine(st, true,
INV_MPU6050_BIT_PWR_ACCL_STBY);
if (result)
return result;
}
result = inv_reset_fifo(indio_dev);
if (result)
return result;
} else {
result = regmap_write(st->map, st->reg->fifo_en, 0);
if (result)
return result;
result = regmap_write(st->map, st->reg->int_enable, 0);
if (result)
return result;
result = regmap_write(st->map, st->reg->user_ctrl, 0);
if (result)
return result;
result = inv_mpu6050_switch_engine(st, false,
INV_MPU6050_BIT_PWR_GYRO_STBY);
if (result)
return result;
result = inv_mpu6050_switch_engine(st, false,
INV_MPU6050_BIT_PWR_ACCL_STBY);
if (result)
return result;
result = inv_mpu6050_set_power_itg(st, false);
if (result)
return result;
}
st->chip_config.enable = enable;
return 0;
}
static int inv_mpu_data_rdy_trigger_set_state(struct iio_trigger *trig,
bool state)
{
return inv_mpu6050_set_enable(iio_trigger_get_drvdata(trig), state);
}
int inv_mpu6050_probe_trigger(struct iio_dev *indio_dev)
{
int ret;
struct inv_mpu6050_state *st = iio_priv(indio_dev);
st->trig = devm_iio_trigger_alloc(&indio_dev->dev,
"%s-dev%d",
indio_dev->name,
indio_dev->id);
if (!st->trig)
return -ENOMEM;
ret = devm_request_irq(&indio_dev->dev, st->irq,
&iio_trigger_generic_data_rdy_poll,
IRQF_TRIGGER_RISING,
"inv_mpu",
st->trig);
if (ret)
return ret;
st->trig->dev.parent = regmap_get_device(st->map);
st->trig->ops = &inv_mpu_trigger_ops;
iio_trigger_set_drvdata(st->trig, indio_dev);
ret = iio_trigger_register(st->trig);
if (ret)
return ret;
indio_dev->trig = iio_trigger_get(st->trig);
return 0;
}
void inv_mpu6050_remove_trigger(struct inv_mpu6050_state *st)
{
iio_trigger_unregister(st->trig);
}
