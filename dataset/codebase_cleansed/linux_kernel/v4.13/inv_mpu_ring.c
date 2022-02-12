static void inv_clear_kfifo(struct inv_mpu6050_state *st)
{
unsigned long flags;
spin_lock_irqsave(&st->time_stamp_lock, flags);
kfifo_reset(&st->timestamps);
spin_unlock_irqrestore(&st->time_stamp_lock, flags);
}
int inv_reset_fifo(struct iio_dev *indio_dev)
{
int result;
u8 d;
struct inv_mpu6050_state *st = iio_priv(indio_dev);
result = regmap_write(st->map, st->reg->int_enable, 0);
if (result) {
dev_err(regmap_get_device(st->map), "int_enable failed %d\n",
result);
return result;
}
result = regmap_write(st->map, st->reg->fifo_en, 0);
if (result)
goto reset_fifo_fail;
result = regmap_write(st->map, st->reg->user_ctrl, 0);
if (result)
goto reset_fifo_fail;
result = regmap_write(st->map, st->reg->user_ctrl,
INV_MPU6050_BIT_FIFO_RST);
if (result)
goto reset_fifo_fail;
inv_clear_kfifo(st);
if (st->chip_config.accl_fifo_enable ||
st->chip_config.gyro_fifo_enable) {
result = regmap_write(st->map, st->reg->int_enable,
INV_MPU6050_BIT_DATA_RDY_EN);
if (result)
return result;
}
result = regmap_write(st->map, st->reg->user_ctrl,
INV_MPU6050_BIT_FIFO_EN);
if (result)
goto reset_fifo_fail;
d = 0;
if (st->chip_config.gyro_fifo_enable)
d |= INV_MPU6050_BITS_GYRO_OUT;
if (st->chip_config.accl_fifo_enable)
d |= INV_MPU6050_BIT_ACCEL_OUT;
result = regmap_write(st->map, st->reg->fifo_en, d);
if (result)
goto reset_fifo_fail;
return 0;
reset_fifo_fail:
dev_err(regmap_get_device(st->map), "reset fifo failed %d\n", result);
result = regmap_write(st->map, st->reg->int_enable,
INV_MPU6050_BIT_DATA_RDY_EN);
return result;
}
irqreturn_t inv_mpu6050_irq_handler(int irq, void *p)
{
struct iio_poll_func *pf = p;
struct iio_dev *indio_dev = pf->indio_dev;
struct inv_mpu6050_state *st = iio_priv(indio_dev);
s64 timestamp;
timestamp = iio_get_time_ns(indio_dev);
kfifo_in_spinlocked(&st->timestamps, &timestamp, 1,
&st->time_stamp_lock);
return IRQ_WAKE_THREAD;
}
irqreturn_t inv_mpu6050_read_fifo(int irq, void *p)
{
struct iio_poll_func *pf = p;
struct iio_dev *indio_dev = pf->indio_dev;
struct inv_mpu6050_state *st = iio_priv(indio_dev);
size_t bytes_per_datum;
int result;
u8 data[INV_MPU6050_OUTPUT_DATA_SIZE];
u16 fifo_count;
s64 timestamp;
mutex_lock(&st->lock);
if (!(st->chip_config.accl_fifo_enable |
st->chip_config.gyro_fifo_enable))
goto end_session;
bytes_per_datum = 0;
if (st->chip_config.accl_fifo_enable)
bytes_per_datum += INV_MPU6050_BYTES_PER_3AXIS_SENSOR;
if (st->chip_config.gyro_fifo_enable)
bytes_per_datum += INV_MPU6050_BYTES_PER_3AXIS_SENSOR;
result = regmap_bulk_read(st->map, st->reg->fifo_count_h, data,
INV_MPU6050_FIFO_COUNT_BYTE);
if (result)
goto end_session;
fifo_count = be16_to_cpup((__be16 *)(&data[0]));
if (fifo_count < bytes_per_datum)
goto end_session;
if (fifo_count & 1)
goto flush_fifo;
if (fifo_count > INV_MPU6050_FIFO_THRESHOLD)
goto flush_fifo;
if (kfifo_len(&st->timestamps) >
fifo_count / bytes_per_datum + INV_MPU6050_TIME_STAMP_TOR)
goto flush_fifo;
while (fifo_count >= bytes_per_datum) {
result = regmap_bulk_read(st->map, st->reg->fifo_r_w,
data, bytes_per_datum);
if (result)
goto flush_fifo;
result = kfifo_out(&st->timestamps, &timestamp, 1);
if (result == 0)
timestamp = 0;
result = iio_push_to_buffers_with_timestamp(indio_dev, data,
timestamp);
if (result)
goto flush_fifo;
fifo_count -= bytes_per_datum;
}
end_session:
mutex_unlock(&st->lock);
iio_trigger_notify_done(indio_dev->trig);
return IRQ_HANDLED;
flush_fifo:
inv_reset_fifo(indio_dev);
mutex_unlock(&st->lock);
iio_trigger_notify_done(indio_dev->trig);
return IRQ_HANDLED;
}
