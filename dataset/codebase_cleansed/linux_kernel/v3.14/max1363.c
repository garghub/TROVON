static const struct max1363_mode
*max1363_match_mode(const unsigned long *mask,
const struct max1363_chip_info *ci)
{
int i;
if (mask)
for (i = 0; i < ci->num_modes; i++)
if (bitmap_subset(mask,
max1363_mode_table[ci->mode_list[i]].
modemask,
MAX1363_MAX_CHANNELS))
return &max1363_mode_table[ci->mode_list[i]];
return NULL;
}
static int max1363_smbus_send(const struct i2c_client *client, const char *buf,
int count)
{
int i, err;
for (i = err = 0; err == 0 && i < count; ++i)
err = i2c_smbus_write_byte(client, buf[i]);
return err ? err : count;
}
static int max1363_smbus_recv(const struct i2c_client *client, char *buf,
int count)
{
int i, ret;
for (i = 0; i < count; ++i) {
ret = i2c_smbus_read_byte(client);
if (ret < 0)
return ret;
buf[i] = ret;
}
return count;
}
static int max1363_write_basic_config(struct max1363_state *st)
{
u8 tx_buf[2] = { st->setupbyte, st->configbyte };
return st->send(st->client, tx_buf, 2);
}
static int max1363_set_scan_mode(struct max1363_state *st)
{
st->configbyte &= ~(MAX1363_CHANNEL_SEL_MASK
| MAX1363_SCAN_MASK
| MAX1363_SE_DE_MASK);
st->configbyte |= st->current_mode->conf;
return max1363_write_basic_config(st);
}
static int max1363_read_single_chan(struct iio_dev *indio_dev,
struct iio_chan_spec const *chan,
int *val,
long m)
{
int ret = 0;
s32 data;
u8 rxbuf[2];
struct max1363_state *st = iio_priv(indio_dev);
struct i2c_client *client = st->client;
mutex_lock(&indio_dev->mlock);
if (st->monitor_on || iio_buffer_enabled(indio_dev)) {
ret = -EBUSY;
goto error_ret;
}
if (st->current_mode != &max1363_mode_table[chan->address]) {
st->current_mode = &max1363_mode_table[chan->address];
ret = max1363_set_scan_mode(st);
if (ret < 0)
goto error_ret;
}
if (st->chip_info->bits != 8) {
data = st->recv(client, rxbuf, 2);
if (data < 0) {
ret = data;
goto error_ret;
}
data = (rxbuf[1] | rxbuf[0] << 8) &
((1 << st->chip_info->bits) - 1);
} else {
data = st->recv(client, rxbuf, 1);
if (data < 0) {
ret = data;
goto error_ret;
}
data = rxbuf[0];
}
*val = data;
error_ret:
mutex_unlock(&indio_dev->mlock);
return ret;
}
static int max1363_read_raw(struct iio_dev *indio_dev,
struct iio_chan_spec const *chan,
int *val,
int *val2,
long m)
{
struct max1363_state *st = iio_priv(indio_dev);
int ret;
switch (m) {
case IIO_CHAN_INFO_RAW:
ret = max1363_read_single_chan(indio_dev, chan, val, m);
if (ret < 0)
return ret;
return IIO_VAL_INT;
case IIO_CHAN_INFO_SCALE:
*val = st->vref_uv / 1000;
*val2 = st->chip_info->bits;
return IIO_VAL_FRACTIONAL_LOG2;
default:
return -EINVAL;
}
return 0;
}
static ssize_t max1363_monitor_show_freq(struct device *dev,
struct device_attribute *attr,
char *buf)
{
struct max1363_state *st = iio_priv(dev_to_iio_dev(dev));
return sprintf(buf, "%d\n", max1363_monitor_speeds[st->monitor_speed]);
}
static ssize_t max1363_monitor_store_freq(struct device *dev,
struct device_attribute *attr,
const char *buf,
size_t len)
{
struct iio_dev *indio_dev = dev_to_iio_dev(dev);
struct max1363_state *st = iio_priv(indio_dev);
int i, ret;
unsigned long val;
bool found = false;
ret = kstrtoul(buf, 10, &val);
if (ret)
return -EINVAL;
for (i = 0; i < ARRAY_SIZE(max1363_monitor_speeds); i++)
if (val == max1363_monitor_speeds[i]) {
found = true;
break;
}
if (!found)
return -EINVAL;
mutex_lock(&indio_dev->mlock);
st->monitor_speed = i;
mutex_unlock(&indio_dev->mlock);
return 0;
}
static int max1363_read_thresh(struct iio_dev *indio_dev,
const struct iio_chan_spec *chan, enum iio_event_type type,
enum iio_event_direction dir, enum iio_event_info info, int *val,
int *val2)
{
struct max1363_state *st = iio_priv(indio_dev);
if (dir == IIO_EV_DIR_FALLING)
*val = st->thresh_low[chan->channel];
else
*val = st->thresh_high[chan->channel];
return IIO_VAL_INT;
}
static int max1363_write_thresh(struct iio_dev *indio_dev,
const struct iio_chan_spec *chan, enum iio_event_type type,
enum iio_event_direction dir, enum iio_event_info info, int val,
int val2)
{
struct max1363_state *st = iio_priv(indio_dev);
switch (st->chip_info->bits) {
case 10:
if (val > 0x3FF)
return -EINVAL;
break;
case 12:
if (val > 0xFFF)
return -EINVAL;
break;
}
switch (dir) {
case IIO_EV_DIR_FALLING:
st->thresh_low[chan->channel] = val;
break;
case IIO_EV_DIR_RISING:
st->thresh_high[chan->channel] = val;
break;
default:
return -EINVAL;
}
return 0;
}
static irqreturn_t max1363_event_handler(int irq, void *private)
{
struct iio_dev *indio_dev = private;
struct max1363_state *st = iio_priv(indio_dev);
s64 timestamp = iio_get_time_ns();
unsigned long mask, loc;
u8 rx;
u8 tx[2] = { st->setupbyte,
MAX1363_MON_INT_ENABLE | (st->monitor_speed << 1) | 0xF0 };
st->recv(st->client, &rx, 1);
mask = rx;
for_each_set_bit(loc, &mask, 8)
iio_push_event(indio_dev, max1363_event_codes[loc], timestamp);
st->send(st->client, tx, 2);
return IRQ_HANDLED;
}
static int max1363_read_event_config(struct iio_dev *indio_dev,
const struct iio_chan_spec *chan, enum iio_event_type type,
enum iio_event_direction dir)
{
struct max1363_state *st = iio_priv(indio_dev);
int val;
int number = chan->channel;
mutex_lock(&indio_dev->mlock);
if (dir == IIO_EV_DIR_FALLING)
val = (1 << number) & st->mask_low;
else
val = (1 << number) & st->mask_high;
mutex_unlock(&indio_dev->mlock);
return val;
}
static int max1363_monitor_mode_update(struct max1363_state *st, int enabled)
{
u8 *tx_buf;
int ret, i = 3, j;
unsigned long numelements;
int len;
const long *modemask;
if (!enabled) {
st->setupbyte &= ~MAX1363_SETUP_MONITOR_SETUP;
st->configbyte &= ~MAX1363_SCAN_MASK;
st->monitor_on = false;
return max1363_write_basic_config(st);
}
st->setupbyte |= MAX1363_SETUP_MONITOR_SETUP;
st->configbyte &= ~(MAX1363_CHANNEL_SEL_MASK
| MAX1363_SCAN_MASK
| MAX1363_SE_DE_MASK);
st->configbyte |= MAX1363_CONFIG_SCAN_MONITOR_MODE;
if ((st->mask_low | st->mask_high) & 0x0F) {
st->configbyte |= max1363_mode_table[s0to3].conf;
modemask = max1363_mode_table[s0to3].modemask;
} else if ((st->mask_low | st->mask_high) & 0x30) {
st->configbyte |= max1363_mode_table[d0m1to2m3].conf;
modemask = max1363_mode_table[d0m1to2m3].modemask;
} else {
st->configbyte |= max1363_mode_table[d1m0to3m2].conf;
modemask = max1363_mode_table[d1m0to3m2].modemask;
}
numelements = bitmap_weight(modemask, MAX1363_MAX_CHANNELS);
len = 3 * numelements + 3;
tx_buf = kmalloc(len, GFP_KERNEL);
if (!tx_buf) {
ret = -ENOMEM;
goto error_ret;
}
tx_buf[0] = st->configbyte;
tx_buf[1] = st->setupbyte;
tx_buf[2] = (st->monitor_speed << 1);
for (j = 0; j < 8; j++)
if (test_bit(j, modemask)) {
if (st->mask_low & (1 << j)) {
tx_buf[i] = (st->thresh_low[j] >> 4) & 0xFF;
tx_buf[i + 1] = (st->thresh_low[j] << 4) & 0xF0;
} else if (j < 4) {
tx_buf[i] = 0;
tx_buf[i + 1] = 0;
} else {
tx_buf[i] = 0x80;
tx_buf[i + 1] = 0;
}
if (st->mask_high & (1 << j)) {
tx_buf[i + 1] |=
(st->thresh_high[j] >> 8) & 0x0F;
tx_buf[i + 2] = st->thresh_high[j] & 0xFF;
} else if (j < 4) {
tx_buf[i + 1] |= 0x0F;
tx_buf[i + 2] = 0xFF;
} else {
tx_buf[i + 1] |= 0x07;
tx_buf[i + 2] = 0xFF;
}
i += 3;
}
ret = st->send(st->client, tx_buf, len);
if (ret < 0)
goto error_ret;
if (ret != len) {
ret = -EIO;
goto error_ret;
}
tx_buf[0] = st->setupbyte;
tx_buf[1] = MAX1363_MON_INT_ENABLE | (st->monitor_speed << 1) | 0xF0;
ret = st->send(st->client, tx_buf, 2);
if (ret < 0)
goto error_ret;
if (ret != 2) {
ret = -EIO;
goto error_ret;
}
ret = 0;
st->monitor_on = true;
error_ret:
kfree(tx_buf);
return ret;
}
static inline int __max1363_check_event_mask(int thismask, int checkmask)
{
int ret = 0;
if (thismask < 4) {
if (checkmask & ~0x0F) {
ret = -EBUSY;
goto error_ret;
}
} else if (thismask < 6) {
if (checkmask & ~0x30) {
ret = -EBUSY;
goto error_ret;
}
} else if (checkmask & ~0xC0)
ret = -EBUSY;
error_ret:
return ret;
}
static int max1363_write_event_config(struct iio_dev *indio_dev,
const struct iio_chan_spec *chan, enum iio_event_type type,
enum iio_event_direction dir, int state)
{
int ret = 0;
struct max1363_state *st = iio_priv(indio_dev);
u16 unifiedmask;
int number = chan->channel;
mutex_lock(&indio_dev->mlock);
unifiedmask = st->mask_low | st->mask_high;
if (dir == IIO_EV_DIR_FALLING) {
if (state == 0)
st->mask_low &= ~(1 << number);
else {
ret = __max1363_check_event_mask((1 << number),
unifiedmask);
if (ret)
goto error_ret;
st->mask_low |= (1 << number);
}
} else {
if (state == 0)
st->mask_high &= ~(1 << number);
else {
ret = __max1363_check_event_mask((1 << number),
unifiedmask);
if (ret)
goto error_ret;
st->mask_high |= (1 << number);
}
}
max1363_monitor_mode_update(st, !!(st->mask_high | st->mask_low));
error_ret:
mutex_unlock(&indio_dev->mlock);
return ret;
}
static int max1363_update_scan_mode(struct iio_dev *indio_dev,
const unsigned long *scan_mask)
{
struct max1363_state *st = iio_priv(indio_dev);
st->current_mode = max1363_match_mode(scan_mask, st->chip_info);
if (!st->current_mode)
return -EINVAL;
max1363_set_scan_mode(st);
return 0;
}
static int max1363_initial_setup(struct max1363_state *st)
{
st->setupbyte = MAX1363_SETUP_INT_CLOCK
| MAX1363_SETUP_UNIPOLAR
| MAX1363_SETUP_NORESET;
if (st->vref)
st->setupbyte |= MAX1363_SETUP_AIN3_IS_REF_EXT_TO_REF;
else
st->setupbyte |= MAX1363_SETUP_POWER_UP_INT_REF
| MAX1363_SETUP_AIN3_IS_AIN3_REF_IS_INT;
st->setupbyte = MAX1363_SETUP_BYTE(st->setupbyte);
st->current_mode = &max1363_mode_table[st->chip_info->default_mode];
st->configbyte = MAX1363_CONFIG_BYTE(st->configbyte);
return max1363_set_scan_mode(st);
}
static int max1363_alloc_scan_masks(struct iio_dev *indio_dev)
{
struct max1363_state *st = iio_priv(indio_dev);
unsigned long *masks;
int i;
masks = devm_kzalloc(&indio_dev->dev,
BITS_TO_LONGS(MAX1363_MAX_CHANNELS) * sizeof(long) *
(st->chip_info->num_modes + 1), GFP_KERNEL);
if (!masks)
return -ENOMEM;
for (i = 0; i < st->chip_info->num_modes; i++)
bitmap_copy(masks + BITS_TO_LONGS(MAX1363_MAX_CHANNELS)*i,
max1363_mode_table[st->chip_info->mode_list[i]]
.modemask, MAX1363_MAX_CHANNELS);
indio_dev->available_scan_masks = masks;
return 0;
}
static irqreturn_t max1363_trigger_handler(int irq, void *p)
{
struct iio_poll_func *pf = p;
struct iio_dev *indio_dev = pf->indio_dev;
struct max1363_state *st = iio_priv(indio_dev);
__u8 *rxbuf;
int b_sent;
size_t d_size;
unsigned long numvals = bitmap_weight(st->current_mode->modemask,
MAX1363_MAX_CHANNELS);
if (st->chip_info->bits != 8)
d_size = numvals*2;
else
d_size = numvals;
if (indio_dev->scan_timestamp) {
d_size += sizeof(s64);
if (d_size % sizeof(s64))
d_size += sizeof(s64) - (d_size % sizeof(s64));
}
if (numvals == 0)
goto done;
rxbuf = kmalloc(d_size, GFP_KERNEL);
if (rxbuf == NULL)
goto done;
if (st->chip_info->bits != 8)
b_sent = st->recv(st->client, rxbuf, numvals * 2);
else
b_sent = st->recv(st->client, rxbuf, numvals);
if (b_sent < 0)
goto done_free;
iio_push_to_buffers_with_timestamp(indio_dev, rxbuf, iio_get_time_ns());
done_free:
kfree(rxbuf);
done:
iio_trigger_notify_done(indio_dev->trig);
return IRQ_HANDLED;
}
static int max1363_probe(struct i2c_client *client,
const struct i2c_device_id *id)
{
int ret;
struct max1363_state *st;
struct iio_dev *indio_dev;
struct regulator *vref;
indio_dev = devm_iio_device_alloc(&client->dev,
sizeof(struct max1363_state));
if (!indio_dev)
return -ENOMEM;
indio_dev->dev.of_node = client->dev.of_node;
ret = iio_map_array_register(indio_dev, client->dev.platform_data);
if (ret < 0)
return ret;
st = iio_priv(indio_dev);
st->reg = devm_regulator_get(&client->dev, "vcc");
if (IS_ERR(st->reg)) {
ret = PTR_ERR(st->reg);
goto error_unregister_map;
}
ret = regulator_enable(st->reg);
if (ret)
goto error_unregister_map;
i2c_set_clientdata(client, indio_dev);
st->chip_info = &max1363_chip_info_tbl[id->driver_data];
st->client = client;
st->vref_uv = st->chip_info->int_vref_mv * 1000;
vref = devm_regulator_get_optional(&client->dev, "vref");
if (!IS_ERR(vref)) {
int vref_uv;
ret = regulator_enable(vref);
if (ret)
goto error_disable_reg;
st->vref = vref;
vref_uv = regulator_get_voltage(vref);
if (vref_uv <= 0) {
ret = -EINVAL;
goto error_disable_reg;
}
st->vref_uv = vref_uv;
}
if (i2c_check_functionality(client->adapter, I2C_FUNC_I2C)) {
st->send = i2c_master_send;
st->recv = i2c_master_recv;
} else if (i2c_check_functionality(client->adapter, I2C_FUNC_SMBUS_BYTE)
&& st->chip_info->bits == 8) {
st->send = max1363_smbus_send;
st->recv = max1363_smbus_recv;
} else {
ret = -EOPNOTSUPP;
goto error_disable_reg;
}
ret = max1363_alloc_scan_masks(indio_dev);
if (ret)
goto error_disable_reg;
indio_dev->dev.parent = &client->dev;
indio_dev->name = id->name;
indio_dev->channels = st->chip_info->channels;
indio_dev->num_channels = st->chip_info->num_channels;
indio_dev->info = st->chip_info->info;
indio_dev->modes = INDIO_DIRECT_MODE;
ret = max1363_initial_setup(st);
if (ret < 0)
goto error_disable_reg;
ret = iio_triggered_buffer_setup(indio_dev, NULL,
&max1363_trigger_handler, NULL);
if (ret)
goto error_disable_reg;
if (client->irq) {
ret = devm_request_threaded_irq(&client->dev, st->client->irq,
NULL,
&max1363_event_handler,
IRQF_TRIGGER_RISING | IRQF_ONESHOT,
"max1363_event",
indio_dev);
if (ret)
goto error_uninit_buffer;
}
ret = iio_device_register(indio_dev);
if (ret < 0)
goto error_uninit_buffer;
return 0;
error_uninit_buffer:
iio_triggered_buffer_cleanup(indio_dev);
error_disable_reg:
if (st->vref)
regulator_disable(st->vref);
regulator_disable(st->reg);
error_unregister_map:
iio_map_array_unregister(indio_dev);
return ret;
}
static int max1363_remove(struct i2c_client *client)
{
struct iio_dev *indio_dev = i2c_get_clientdata(client);
struct max1363_state *st = iio_priv(indio_dev);
iio_device_unregister(indio_dev);
iio_triggered_buffer_cleanup(indio_dev);
if (st->vref)
regulator_disable(st->vref);
regulator_disable(st->reg);
iio_map_array_unregister(indio_dev);
return 0;
}
