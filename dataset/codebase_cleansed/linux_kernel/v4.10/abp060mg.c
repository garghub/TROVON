static int abp060mg_get_measurement(struct abp_state *state, int *val)
{
struct i2c_client *client = state->client;
__be16 buf[2];
u16 pressure;
int ret;
buf[0] = 0;
ret = i2c_master_send(client, (u8 *)&buf, state->mreq_len);
if (ret < 0)
return ret;
msleep_interruptible(ABP060MG_RESP_TIME_MS);
ret = i2c_master_recv(client, (u8 *)&buf, sizeof(buf));
if (ret < 0)
return ret;
pressure = be16_to_cpu(buf[0]);
if (pressure & ABP060MG_ERROR_MASK)
return -EIO;
if (pressure < ABP060MG_MIN_COUNTS || pressure > ABP060MG_MAX_COUNTS)
return -EIO;
*val = pressure;
return IIO_VAL_INT;
}
static int abp060mg_read_raw(struct iio_dev *indio_dev,
struct iio_chan_spec const *chan, int *val,
int *val2, long mask)
{
struct abp_state *state = iio_priv(indio_dev);
int ret;
mutex_lock(&state->lock);
switch (mask) {
case IIO_CHAN_INFO_RAW:
ret = abp060mg_get_measurement(state, val);
break;
case IIO_CHAN_INFO_OFFSET:
*val = state->offset;
ret = IIO_VAL_INT;
break;
case IIO_CHAN_INFO_SCALE:
*val = state->scale;
*val2 = ABP060MG_NUM_COUNTS * 1000;
ret = IIO_VAL_FRACTIONAL;
break;
default:
ret = -EINVAL;
break;
}
mutex_unlock(&state->lock);
return ret;
}
static void abp060mg_init_device(struct iio_dev *indio_dev, unsigned long id)
{
struct abp_state *state = iio_priv(indio_dev);
struct abp_config *cfg = &abp_config[id];
state->scale = cfg->max - cfg->min;
state->offset = -ABP060MG_MIN_COUNTS;
if (cfg->min < 0)
state->offset -= ABP060MG_NUM_COUNTS >> 1;
}
static int abp060mg_probe(struct i2c_client *client,
const struct i2c_device_id *id)
{
struct iio_dev *indio_dev;
struct abp_state *state;
unsigned long cfg_id = id->driver_data;
indio_dev = devm_iio_device_alloc(&client->dev, sizeof(*state));
if (!indio_dev)
return -ENOMEM;
state = iio_priv(indio_dev);
i2c_set_clientdata(client, state);
state->client = client;
if (!i2c_check_functionality(client->adapter, I2C_FUNC_SMBUS_QUICK))
state->mreq_len = 1;
abp060mg_init_device(indio_dev, cfg_id);
indio_dev->dev.parent = &client->dev;
indio_dev->name = dev_name(&client->dev);
indio_dev->modes = INDIO_DIRECT_MODE;
indio_dev->info = &abp060mg_info;
indio_dev->channels = abp060mg_channels;
indio_dev->num_channels = ARRAY_SIZE(abp060mg_channels);
mutex_init(&state->lock);
return devm_iio_device_register(&client->dev, indio_dev);
}
