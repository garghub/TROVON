static int mlx90614_read_raw(struct iio_dev *indio_dev,
struct iio_chan_spec const *channel, int *val,
int *val2, long mask)
{
struct mlx90614_data *data = iio_priv(indio_dev);
u8 cmd;
s32 ret;
switch (mask) {
case IIO_CHAN_INFO_RAW:
switch (channel->channel2) {
case IIO_MOD_TEMP_AMBIENT:
cmd = MLX90614_TA;
break;
case IIO_MOD_TEMP_OBJECT:
switch (channel->channel) {
case 0:
cmd = MLX90614_TOBJ1;
break;
case 1:
cmd = MLX90614_TOBJ2;
break;
default:
return -EINVAL;
}
break;
default:
return -EINVAL;
}
ret = i2c_smbus_read_word_data(data->client, cmd);
if (ret < 0)
return ret;
*val = ret;
return IIO_VAL_INT;
case IIO_CHAN_INFO_OFFSET:
*val = 13657;
*val2 = 500000;
return IIO_VAL_INT_PLUS_MICRO;
case IIO_CHAN_INFO_SCALE:
*val = 20;
return IIO_VAL_INT;
default:
return -EINVAL;
}
}
static int mlx90614_probe_num_ir_sensors(struct i2c_client *client)
{
s32 ret;
ret = i2c_smbus_read_word_data(client, MLX90614_CONFIG);
if (ret < 0)
return ret;
return (ret & MLX90614_CONFIG_DUAL_MASK) ? 1 : 0;
}
static int mlx90614_probe(struct i2c_client *client,
const struct i2c_device_id *id)
{
struct iio_dev *indio_dev;
struct mlx90614_data *data;
int ret;
if (!i2c_check_functionality(client->adapter, I2C_FUNC_SMBUS_WORD_DATA))
return -ENODEV;
indio_dev = devm_iio_device_alloc(&client->dev, sizeof(*data));
if (!indio_dev)
return -ENOMEM;
data = iio_priv(indio_dev);
i2c_set_clientdata(client, indio_dev);
data->client = client;
indio_dev->dev.parent = &client->dev;
indio_dev->name = id->name;
indio_dev->modes = INDIO_DIRECT_MODE;
indio_dev->info = &mlx90614_info;
ret = mlx90614_probe_num_ir_sensors(client);
switch (ret) {
case 0:
dev_dbg(&client->dev, "Found single sensor");
indio_dev->channels = mlx90614_channels;
indio_dev->num_channels = 2;
break;
case 1:
dev_dbg(&client->dev, "Found dual sensor");
indio_dev->channels = mlx90614_channels;
indio_dev->num_channels = 3;
break;
default:
return ret;
}
return iio_device_register(indio_dev);
}
static int mlx90614_remove(struct i2c_client *client)
{
iio_device_unregister(i2c_get_clientdata(client));
return 0;
}
