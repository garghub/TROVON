int itg3200_write_reg_8(struct iio_dev *indio_dev,
u8 reg_address, u8 val)
{
struct itg3200 *st = iio_priv(indio_dev);
return i2c_smbus_write_byte_data(st->i2c, 0x80 | reg_address, val);
}
int itg3200_read_reg_8(struct iio_dev *indio_dev,
u8 reg_address, u8 *val)
{
struct itg3200 *st = iio_priv(indio_dev);
int ret;
ret = i2c_smbus_read_byte_data(st->i2c, reg_address);
if (ret < 0)
return ret;
*val = ret;
return 0;
}
static int itg3200_read_reg_s16(struct iio_dev *indio_dev, u8 lower_reg_address,
int *val)
{
struct itg3200 *st = iio_priv(indio_dev);
struct i2c_client *client = st->i2c;
int ret;
s16 out;
struct i2c_msg msg[2] = {
{
.addr = client->addr,
.flags = client->flags,
.len = 1,
.buf = (char *)&lower_reg_address,
},
{
.addr = client->addr,
.flags = client->flags | I2C_M_RD,
.len = 2,
.buf = (char *)&out,
},
};
lower_reg_address |= 0x80;
ret = i2c_transfer(client->adapter, msg, 2);
be16_to_cpus(&out);
*val = out;
return (ret == 2) ? 0 : ret;
}
static int itg3200_read_raw(struct iio_dev *indio_dev,
const struct iio_chan_spec *chan,
int *val, int *val2, long info)
{
int ret = 0;
u8 reg;
u8 regval;
switch (info) {
case IIO_CHAN_INFO_RAW:
reg = (u8)chan->address;
ret = itg3200_read_reg_s16(indio_dev, reg, val);
return IIO_VAL_INT;
case IIO_CHAN_INFO_SCALE:
*val = 0;
if (chan->type == IIO_TEMP)
*val2 = 1000000000/280;
else
*val2 = 1214142;
return IIO_VAL_INT_PLUS_NANO;
case IIO_CHAN_INFO_OFFSET:
*val = 23000;
return IIO_VAL_INT;
case IIO_CHAN_INFO_SAMP_FREQ:
ret = itg3200_read_reg_8(indio_dev, ITG3200_REG_DLPF, &regval);
if (ret)
return ret;
*val = (regval & ITG3200_DLPF_CFG_MASK) ? 1000 : 8000;
ret = itg3200_read_reg_8(indio_dev,
ITG3200_REG_SAMPLE_RATE_DIV,
&regval);
if (ret)
return ret;
*val /= regval + 1;
return IIO_VAL_INT;
default:
return -EINVAL;
}
}
static int itg3200_write_raw(struct iio_dev *indio_dev,
struct iio_chan_spec const *chan,
int val,
int val2,
long mask)
{
int ret;
u8 t;
switch (mask) {
case IIO_CHAN_INFO_SAMP_FREQ:
if (val == 0 || val2 != 0)
return -EINVAL;
mutex_lock(&indio_dev->mlock);
ret = itg3200_read_reg_8(indio_dev, ITG3200_REG_DLPF, &t);
if (ret) {
mutex_unlock(&indio_dev->mlock);
return ret;
}
t = ((t & ITG3200_DLPF_CFG_MASK) ? 1000u : 8000u) / val - 1;
ret = itg3200_write_reg_8(indio_dev,
ITG3200_REG_SAMPLE_RATE_DIV,
t);
mutex_unlock(&indio_dev->mlock);
return ret;
default:
return -EINVAL;
}
}
static int itg3200_reset(struct iio_dev *indio_dev)
{
struct itg3200 *st = iio_priv(indio_dev);
int ret;
dev_dbg(&st->i2c->dev, "reset device");
ret = itg3200_write_reg_8(indio_dev,
ITG3200_REG_POWER_MANAGEMENT,
ITG3200_RESET);
if (ret) {
dev_err(&st->i2c->dev, "error resetting device");
goto error_ret;
}
udelay(1500);
ret = itg3200_write_reg_8(indio_dev,
ITG3200_REG_IRQ_CONFIG,
ITG3200_IRQ_ACTIVE_HIGH |
ITG3200_IRQ_PUSH_PULL |
ITG3200_IRQ_LATCH_50US_PULSE |
ITG3200_IRQ_LATCH_CLEAR_ANY);
if (ret)
dev_err(&st->i2c->dev, "error init device");
error_ret:
return ret;
}
static int itg3200_enable_full_scale(struct iio_dev *indio_dev)
{
u8 val;
int ret;
ret = itg3200_read_reg_8(indio_dev, ITG3200_REG_DLPF, &val);
if (ret)
goto err_ret;
val |= ITG3200_DLPF_FS_SEL_2000;
return itg3200_write_reg_8(indio_dev, ITG3200_REG_DLPF, val);
err_ret:
return ret;
}
static int itg3200_initial_setup(struct iio_dev *indio_dev)
{
struct itg3200 *st = iio_priv(indio_dev);
int ret;
u8 val;
ret = itg3200_read_reg_8(indio_dev, ITG3200_REG_ADDRESS, &val);
if (ret)
goto err_ret;
if (((val >> 1) & 0x3f) != 0x34) {
dev_err(&st->i2c->dev, "invalid reg value 0x%02x", val);
ret = -ENXIO;
goto err_ret;
}
ret = itg3200_reset(indio_dev);
if (ret)
goto err_ret;
ret = itg3200_enable_full_scale(indio_dev);
err_ret:
return ret;
}
static int itg3200_probe(struct i2c_client *client,
const struct i2c_device_id *id)
{
int ret;
struct itg3200 *st;
struct iio_dev *indio_dev;
dev_dbg(&client->dev, "probe I2C dev with IRQ %i", client->irq);
indio_dev = devm_iio_device_alloc(&client->dev, sizeof(*st));
if (!indio_dev)
return -ENOMEM;
st = iio_priv(indio_dev);
i2c_set_clientdata(client, indio_dev);
st->i2c = client;
indio_dev->dev.parent = &client->dev;
indio_dev->name = client->dev.driver->name;
indio_dev->channels = itg3200_channels;
indio_dev->num_channels = ARRAY_SIZE(itg3200_channels);
indio_dev->available_scan_masks = itg3200_available_scan_masks;
indio_dev->info = &itg3200_info;
indio_dev->modes = INDIO_DIRECT_MODE;
ret = itg3200_buffer_configure(indio_dev);
if (ret)
return ret;
if (client->irq) {
ret = itg3200_probe_trigger(indio_dev);
if (ret)
goto error_unconfigure_buffer;
}
ret = itg3200_initial_setup(indio_dev);
if (ret)
goto error_remove_trigger;
ret = iio_device_register(indio_dev);
if (ret)
goto error_remove_trigger;
return 0;
error_remove_trigger:
if (client->irq)
itg3200_remove_trigger(indio_dev);
error_unconfigure_buffer:
itg3200_buffer_unconfigure(indio_dev);
return ret;
}
static int itg3200_remove(struct i2c_client *client)
{
struct iio_dev *indio_dev = i2c_get_clientdata(client);
iio_device_unregister(indio_dev);
if (client->irq)
itg3200_remove_trigger(indio_dev);
itg3200_buffer_unconfigure(indio_dev);
return 0;
}
