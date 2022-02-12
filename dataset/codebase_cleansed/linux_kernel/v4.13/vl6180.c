static int vl6180_read(struct i2c_client *client, u16 cmd, void *databuf,
u8 len)
{
__be16 cmdbuf = cpu_to_be16(cmd);
struct i2c_msg msgs[2] = {
{ .addr = client->addr, .len = sizeof(cmdbuf), .buf = (u8 *) &cmdbuf },
{ .addr = client->addr, .len = len, .buf = databuf,
.flags = I2C_M_RD } };
int ret;
ret = i2c_transfer(client->adapter, msgs, ARRAY_SIZE(msgs));
if (ret < 0)
dev_err(&client->dev, "failed reading register 0x%04x\n", cmd);
return ret;
}
static int vl6180_read_byte(struct i2c_client *client, u16 cmd)
{
u8 data;
int ret;
ret = vl6180_read(client, cmd, &data, sizeof(data));
if (ret < 0)
return ret;
return data;
}
static int vl6180_read_word(struct i2c_client *client, u16 cmd)
{
__be16 data;
int ret;
ret = vl6180_read(client, cmd, &data, sizeof(data));
if (ret < 0)
return ret;
return be16_to_cpu(data);
}
static int vl6180_write_byte(struct i2c_client *client, u16 cmd, u8 val)
{
u8 buf[3];
struct i2c_msg msgs[1] = {
{ .addr = client->addr, .len = sizeof(buf), .buf = (u8 *) &buf } };
int ret;
buf[0] = cmd >> 8;
buf[1] = cmd & 0xff;
buf[2] = val;
ret = i2c_transfer(client->adapter, msgs, ARRAY_SIZE(msgs));
if (ret < 0) {
dev_err(&client->dev, "failed writing register 0x%04x\n", cmd);
return ret;
}
return 0;
}
static int vl6180_write_word(struct i2c_client *client, u16 cmd, u16 val)
{
__be16 buf[2];
struct i2c_msg msgs[1] = {
{ .addr = client->addr, .len = sizeof(buf), .buf = (u8 *) &buf } };
int ret;
buf[0] = cpu_to_be16(cmd);
buf[1] = cpu_to_be16(val);
ret = i2c_transfer(client->adapter, msgs, ARRAY_SIZE(msgs));
if (ret < 0) {
dev_err(&client->dev, "failed writing register 0x%04x\n", cmd);
return ret;
}
return 0;
}
static int vl6180_measure(struct vl6180_data *data, int addr)
{
struct i2c_client *client = data->client;
int tries = 20, ret;
u16 value;
mutex_lock(&data->lock);
ret = vl6180_write_byte(client,
vl6180_chan_regs_table[addr].start_reg, VL6180_STARTSTOP);
if (ret < 0)
goto fail;
while (tries--) {
ret = vl6180_read_byte(client, VL6180_INTR_STATUS);
if (ret < 0)
goto fail;
if (ret & vl6180_chan_regs_table[addr].drdy_mask)
break;
msleep(20);
}
if (tries < 0) {
ret = -EIO;
goto fail;
}
ret = vl6180_chan_regs_table[addr].word ?
vl6180_read_word(client, vl6180_chan_regs_table[addr].value_reg) :
vl6180_read_byte(client, vl6180_chan_regs_table[addr].value_reg);
if (ret < 0)
goto fail;
value = ret;
ret = vl6180_write_byte(client, VL6180_INTR_CLEAR,
VL6180_CLEAR_ERROR | VL6180_CLEAR_ALS | VL6180_CLEAR_RANGE);
if (ret < 0)
goto fail;
ret = value;
fail:
mutex_unlock(&data->lock);
return ret;
}
static int vl6180_read_raw(struct iio_dev *indio_dev,
struct iio_chan_spec const *chan,
int *val, int *val2, long mask)
{
struct vl6180_data *data = iio_priv(indio_dev);
int ret, i;
switch (mask) {
case IIO_CHAN_INFO_RAW:
ret = vl6180_measure(data, chan->address);
if (ret < 0)
return ret;
*val = ret;
return IIO_VAL_INT;
case IIO_CHAN_INFO_INT_TIME:
ret = vl6180_read_word(data->client, VL6180_ALS_IT);
if (ret < 0)
return ret;
*val = 0;
*val2 = (ret + 1) * 1000;
return IIO_VAL_INT_PLUS_MICRO;
case IIO_CHAN_INFO_SCALE:
switch (chan->type) {
case IIO_LIGHT:
*val = 0;
*val2 = 320000;
break;
case IIO_DISTANCE:
*val = 0;
*val2 = 1000;
break;
default:
return -EINVAL;
}
return IIO_VAL_INT_PLUS_MICRO;
case IIO_CHAN_INFO_HARDWAREGAIN:
ret = vl6180_read_byte(data->client, VL6180_ALS_GAIN);
if (ret < 0)
return -EINVAL;
for (i = 0; i < ARRAY_SIZE(vl6180_als_gain); i++) {
if (ret == vl6180_als_gain[i][2]) {
*val = vl6180_als_gain[i][0];
*val2 = vl6180_als_gain[i][1];
}
}
return IIO_VAL_INT_PLUS_MICRO;
default:
return -EINVAL;
}
}
static int vl6180_hold(struct vl6180_data *data, bool hold)
{
return vl6180_write_byte(data->client, VL6180_HOLD,
hold ? VL6180_HOLD_ON : 0);
}
static int vl6180_set_als_gain(struct vl6180_data *data, int val, int val2)
{
int i, ret;
for (i = 0; i < ARRAY_SIZE(vl6180_als_gain); i++) {
if (val == vl6180_als_gain[i][0] &&
val2 == vl6180_als_gain[i][1]) {
mutex_lock(&data->lock);
ret = vl6180_hold(data, true);
if (ret < 0)
goto fail;
ret = vl6180_write_byte(data->client, VL6180_ALS_GAIN,
vl6180_als_gain[i][3]);
fail:
vl6180_hold(data, false);
mutex_unlock(&data->lock);
return ret;
}
}
return -EINVAL;
}
static int vl6180_set_it(struct vl6180_data *data, int val2)
{
int ret;
mutex_lock(&data->lock);
ret = vl6180_hold(data, true);
if (ret < 0)
goto fail;
ret = vl6180_write_word(data->client, VL6180_ALS_IT,
(val2 - 500) / 1000);
fail:
vl6180_hold(data, false);
mutex_unlock(&data->lock);
return ret;
}
static int vl6180_write_raw(struct iio_dev *indio_dev,
struct iio_chan_spec const *chan,
int val, int val2, long mask)
{
struct vl6180_data *data = iio_priv(indio_dev);
switch (mask) {
case IIO_CHAN_INFO_INT_TIME:
if (val != 0 || val2 < 500 || val2 >= 512500)
return -EINVAL;
return vl6180_set_it(data, val2);
case IIO_CHAN_INFO_HARDWAREGAIN:
if (chan->type != IIO_LIGHT)
return -EINVAL;
return vl6180_set_als_gain(data, val, val2);
default:
return -EINVAL;
}
}
static int vl6180_init(struct vl6180_data *data)
{
struct i2c_client *client = data->client;
int ret;
ret = vl6180_read_byte(client, VL6180_MODEL_ID);
if (ret < 0)
return ret;
if (ret != VL6180_MODEL_ID_VAL) {
dev_err(&client->dev, "invalid model ID %02x\n", ret);
return -ENODEV;
}
ret = vl6180_hold(data, true);
if (ret < 0)
return ret;
ret = vl6180_read_byte(client, VL6180_OUT_OF_RESET);
if (ret < 0)
return ret;
if (ret != 0x01)
dev_info(&client->dev, "device is not fresh out of reset\n");
ret = vl6180_write_byte(client, VL6180_INTR_CONFIG,
VL6180_ALS_READY | VL6180_RANGE_READY);
if (ret < 0)
return ret;
ret = vl6180_write_word(client, VL6180_ALS_IT, VL6180_ALS_IT_100);
if (ret < 0)
return ret;
ret = vl6180_write_byte(client, VL6180_ALS_GAIN, VL6180_ALS_GAIN_1);
if (ret < 0)
return ret;
ret = vl6180_write_byte(client, VL6180_OUT_OF_RESET, 0x00);
if (ret < 0)
return ret;
return vl6180_hold(data, false);
}
static int vl6180_probe(struct i2c_client *client,
const struct i2c_device_id *id)
{
struct vl6180_data *data;
struct iio_dev *indio_dev;
int ret;
indio_dev = devm_iio_device_alloc(&client->dev, sizeof(*data));
if (!indio_dev)
return -ENOMEM;
data = iio_priv(indio_dev);
i2c_set_clientdata(client, indio_dev);
data->client = client;
mutex_init(&data->lock);
indio_dev->dev.parent = &client->dev;
indio_dev->info = &vl6180_info;
indio_dev->channels = vl6180_channels;
indio_dev->num_channels = ARRAY_SIZE(vl6180_channels);
indio_dev->name = VL6180_DRV_NAME;
indio_dev->modes = INDIO_DIRECT_MODE;
ret = vl6180_init(data);
if (ret < 0)
return ret;
return devm_iio_device_register(&client->dev, indio_dev);
}
