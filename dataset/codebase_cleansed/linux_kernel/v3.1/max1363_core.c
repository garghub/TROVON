const struct max1363_mode
*max1363_match_mode(u32 mask, const struct max1363_chip_info *ci)
{
int i;
if (mask)
for (i = 0; i < ci->num_modes; i++)
if (!((~max1363_mode_table[ci->mode_list[i]].modemask) &
mask))
return &max1363_mode_table[ci->mode_list[i]];
return NULL;
}
static int max1363_write_basic_config(struct i2c_client *client,
unsigned char d1,
unsigned char d2)
{
u8 tx_buf[2] = {d1, d2};
return i2c_master_send(client, tx_buf, 2);
}
int max1363_set_scan_mode(struct max1363_state *st)
{
st->configbyte &= ~(MAX1363_CHANNEL_SEL_MASK
| MAX1363_SCAN_MASK
| MAX1363_SE_DE_MASK);
st->configbyte |= st->current_mode->conf;
return max1363_write_basic_config(st->client,
st->setupbyte,
st->configbyte);
}
static int max1363_read_single_chan(struct iio_dev *indio_dev,
struct iio_chan_spec const *chan,
int *val,
long m)
{
int ret = 0;
s32 data;
char rxbuf[2];
long mask;
struct max1363_state *st = iio_priv(indio_dev);
struct i2c_client *client = st->client;
mutex_lock(&indio_dev->mlock);
if (st->monitor_on) {
ret = -EBUSY;
goto error_ret;
}
if (iio_ring_enabled(indio_dev)) {
mask = max1363_mode_table[chan->address].modemask;
data = max1363_single_channel_from_ring(mask, st);
if (data < 0) {
ret = data;
goto error_ret;
}
} else {
if (st->current_mode != &max1363_mode_table[chan->address]) {
st->current_mode = &max1363_mode_table[chan->address];
ret = max1363_set_scan_mode(st);
if (ret < 0)
goto error_ret;
}
if (st->chip_info->bits != 8) {
data = i2c_master_recv(client, rxbuf, 2);
if (data < 0) {
ret = data;
goto error_ret;
}
data = (s32)(rxbuf[1]) | ((s32)(rxbuf[0] & 0x0F)) << 8;
} else {
data = i2c_master_recv(client, rxbuf, 1);
if (data < 0) {
ret = data;
goto error_ret;
}
data = rxbuf[0];
}
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
case 0:
ret = max1363_read_single_chan(indio_dev, chan, val, m);
if (ret)
return ret;
return IIO_VAL_INT;
case (1 << IIO_CHAN_INFO_SCALE_SHARED):
if ((1 << (st->chip_info->bits + 1)) >
st->chip_info->int_vref_mv) {
*val = 0;
*val2 = 500000;
return IIO_VAL_INT_PLUS_MICRO;
} else {
*val = (st->chip_info->int_vref_mv)
>> st->chip_info->bits;
return IIO_VAL_INT;
}
default:
return -EINVAL;
}
return 0;
}
static ssize_t max1363_monitor_show_freq(struct device *dev,
struct device_attribute *attr,
char *buf)
{
struct max1363_state *st = iio_priv(dev_get_drvdata(dev));
return sprintf(buf, "%d\n", max1363_monitor_speeds[st->monitor_speed]);
}
static ssize_t max1363_monitor_store_freq(struct device *dev,
struct device_attribute *attr,
const char *buf,
size_t len)
{
struct iio_dev *indio_dev = dev_get_drvdata(dev);
struct max1363_state *st = iio_priv(indio_dev);
int i, ret;
unsigned long val;
bool found = false;
ret = strict_strtoul(buf, 10, &val);
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
int event_code,
int *val)
{
struct max1363_state *st = iio_priv(indio_dev);
if (IIO_EVENT_CODE_EXTRACT_DIR(event_code) == IIO_EV_DIR_FALLING)
*val = st->thresh_low[IIO_EVENT_CODE_EXTRACT_NUM(event_code)];
else
*val = st->thresh_high[IIO_EVENT_CODE_EXTRACT_NUM(event_code)];
return 0;
}
static int max1363_write_thresh(struct iio_dev *indio_dev,
int event_code,
int val)
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
switch (IIO_EVENT_CODE_EXTRACT_DIR(event_code)) {
case IIO_EV_DIR_FALLING:
st->thresh_low[IIO_EVENT_CODE_EXTRACT_NUM(event_code)] = val;
break;
case IIO_EV_DIR_RISING:
st->thresh_high[IIO_EVENT_CODE_EXTRACT_NUM(event_code)] = val;
break;
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
i2c_master_recv(st->client, &rx, 1);
mask = rx;
for_each_set_bit(loc, &mask, 8)
iio_push_event(indio_dev, 0, max1363_event_codes[loc],
timestamp);
i2c_master_send(st->client, tx, 2);
return IRQ_HANDLED;
}
static int max1363_read_event_config(struct iio_dev *indio_dev,
int event_code)
{
struct max1363_state *st = iio_priv(indio_dev);
int val;
int number = IIO_EVENT_CODE_EXTRACT_NUM(event_code);
mutex_lock(&indio_dev->mlock);
if (IIO_EVENT_CODE_EXTRACT_DIR(event_code) == IIO_EV_DIR_FALLING)
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
long modemask;
if (!enabled) {
st->setupbyte &= ~MAX1363_SETUP_MONITOR_SETUP;
st->configbyte &= ~MAX1363_SCAN_MASK;
st->monitor_on = false;
return max1363_write_basic_config(st->client,
st->setupbyte,
st->configbyte);
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
numelements = hweight_long(modemask);
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
if (modemask & (1 << j)) {
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
ret = i2c_master_send(st->client, tx_buf, len);
if (ret < 0)
goto error_ret;
if (ret != len) {
ret = -EIO;
goto error_ret;
}
tx_buf[0] = st->setupbyte;
tx_buf[1] = MAX1363_MON_INT_ENABLE | (st->monitor_speed << 1) | 0xF0;
ret = i2c_master_send(st->client, tx_buf, 2);
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
int event_code,
int state)
{
int ret = 0;
struct max1363_state *st = iio_priv(indio_dev);
u16 unifiedmask;
int number = IIO_EVENT_CODE_EXTRACT_NUM(event_code);
mutex_lock(&indio_dev->mlock);
unifiedmask = st->mask_low | st->mask_high;
if (IIO_EVENT_CODE_EXTRACT_DIR(event_code) == IIO_EV_DIR_FALLING) {
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
static int max1363_initial_setup(struct max1363_state *st)
{
st->setupbyte = MAX1363_SETUP_AIN3_IS_AIN3_REF_IS_VDD
| MAX1363_SETUP_POWER_UP_INT_REF
| MAX1363_SETUP_INT_CLOCK
| MAX1363_SETUP_UNIPOLAR
| MAX1363_SETUP_NORESET;
st->setupbyte = MAX1363_SETUP_BYTE(st->setupbyte);
st->current_mode = &max1363_mode_table[st->chip_info->default_mode];
st->configbyte = MAX1363_CONFIG_BYTE(st->configbyte);
return max1363_set_scan_mode(st);
}
static int __devinit max1363_probe(struct i2c_client *client,
const struct i2c_device_id *id)
{
int ret, i, regdone = 0;
struct max1363_state *st;
struct iio_dev *indio_dev;
struct regulator *reg;
reg = regulator_get(&client->dev, "vcc");
if (IS_ERR(reg)) {
ret = PTR_ERR(reg);
goto error_out;
}
ret = regulator_enable(reg);
if (ret)
goto error_put_reg;
indio_dev = iio_allocate_device(sizeof(struct max1363_state));
if (indio_dev == NULL) {
ret = -ENOMEM;
goto error_disable_reg;
}
st = iio_priv(indio_dev);
st->reg = reg;
i2c_set_clientdata(client, indio_dev);
st->chip_info = &max1363_chip_info_tbl[id->driver_data];
st->client = client;
indio_dev->available_scan_masks
= kzalloc(sizeof(*indio_dev->available_scan_masks)*
(st->chip_info->num_modes + 1), GFP_KERNEL);
if (!indio_dev->available_scan_masks) {
ret = -ENOMEM;
goto error_free_device;
}
for (i = 0; i < st->chip_info->num_modes; i++)
indio_dev->available_scan_masks[i] =
max1363_mode_table[st->chip_info->mode_list[i]]
.modemask;
indio_dev->dev.parent = &client->dev;
indio_dev->name = id->name;
indio_dev->info = st->chip_info->info;
indio_dev->modes = INDIO_DIRECT_MODE;
ret = max1363_initial_setup(st);
if (ret < 0)
goto error_free_available_scan_masks;
ret = max1363_register_ring_funcs_and_init(indio_dev);
if (ret)
goto error_free_available_scan_masks;
ret = iio_device_register(indio_dev);
if (ret)
goto error_cleanup_ring;
regdone = 1;
ret = iio_ring_buffer_register_ex(indio_dev->ring, 0,
st->chip_info->channels,
st->chip_info->num_channels);
if (ret)
goto error_cleanup_ring;
if (client->irq) {
ret = request_threaded_irq(st->client->irq,
NULL,
&max1363_event_handler,
IRQF_TRIGGER_RISING | IRQF_ONESHOT,
"max1363_event",
indio_dev);
if (ret)
goto error_uninit_ring;
}
return 0;
error_uninit_ring:
iio_ring_buffer_unregister(indio_dev->ring);
error_cleanup_ring:
max1363_ring_cleanup(indio_dev);
error_free_available_scan_masks:
kfree(indio_dev->available_scan_masks);
error_free_device:
if (!regdone)
iio_free_device(indio_dev);
else
iio_device_unregister(indio_dev);
error_disable_reg:
regulator_disable(reg);
error_put_reg:
regulator_put(reg);
error_out:
return ret;
}
static int max1363_remove(struct i2c_client *client)
{
struct iio_dev *indio_dev = i2c_get_clientdata(client);
struct max1363_state *st = iio_priv(indio_dev);
struct regulator *reg = st->reg;
if (client->irq)
free_irq(st->client->irq, indio_dev);
iio_ring_buffer_unregister(indio_dev->ring);
max1363_ring_cleanup(indio_dev);
kfree(indio_dev->available_scan_masks);
if (!IS_ERR(reg)) {
regulator_disable(reg);
regulator_put(reg);
}
iio_device_unregister(indio_dev);
return 0;
}
static __init int max1363_init(void)
{
return i2c_add_driver(&max1363_driver);
}
static __exit void max1363_exit(void)
{
i2c_del_driver(&max1363_driver);
}
