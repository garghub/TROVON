static int opt3001_find_scale(const struct opt3001 *opt, int val,
int val2, u8 *exponent)
{
int i;
for (i = 0; i < ARRAY_SIZE(opt3001_scales); i++) {
const struct opt3001_scale *scale = &opt3001_scales[i];
if ((val * 1000 + val2 / 1000) <=
(scale->val * 1000 + scale->val2 / 1000)) {
*exponent = i;
return 0;
}
}
return -EINVAL;
}
static void opt3001_to_iio_ret(struct opt3001 *opt, u8 exponent,
u16 mantissa, int *val, int *val2)
{
int lux;
lux = 10 * (mantissa << exponent);
*val = lux / 1000;
*val2 = (lux - (*val * 1000)) * 1000;
}
static void opt3001_set_mode(struct opt3001 *opt, u16 *reg, u16 mode)
{
*reg &= ~OPT3001_CONFIGURATION_M_MASK;
*reg |= mode;
opt->mode = mode;
}
static int opt3001_get_lux(struct opt3001 *opt, int *val, int *val2)
{
int ret;
u16 mantissa;
u16 reg;
u8 exponent;
u16 value;
long timeout;
if (opt->use_irq) {
ret = i2c_smbus_write_word_swapped(opt->client,
OPT3001_LOW_LIMIT,
OPT3001_LOW_LIMIT_EOC_ENABLE);
if (ret < 0) {
dev_err(opt->dev, "failed to write register %02x\n",
OPT3001_LOW_LIMIT);
return ret;
}
opt->ok_to_ignore_lock = true;
}
opt->result_ready = false;
ret = i2c_smbus_read_word_swapped(opt->client, OPT3001_CONFIGURATION);
if (ret < 0) {
dev_err(opt->dev, "failed to read register %02x\n",
OPT3001_CONFIGURATION);
goto err;
}
reg = ret;
opt3001_set_mode(opt, &reg, OPT3001_CONFIGURATION_M_SINGLE);
ret = i2c_smbus_write_word_swapped(opt->client, OPT3001_CONFIGURATION,
reg);
if (ret < 0) {
dev_err(opt->dev, "failed to write register %02x\n",
OPT3001_CONFIGURATION);
goto err;
}
if (opt->use_irq) {
ret = wait_event_timeout(opt->result_ready_queue,
opt->result_ready,
msecs_to_jiffies(OPT3001_RESULT_READY_LONG));
} else {
timeout = (opt->int_time == OPT3001_INT_TIME_SHORT) ?
OPT3001_RESULT_READY_SHORT : OPT3001_RESULT_READY_LONG;
msleep(timeout);
ret = i2c_smbus_read_word_swapped(opt->client,
OPT3001_CONFIGURATION);
if (ret < 0) {
dev_err(opt->dev, "failed to read register %02x\n",
OPT3001_CONFIGURATION);
goto err;
}
if (!(ret & OPT3001_CONFIGURATION_CRF)) {
ret = -ETIMEDOUT;
goto err;
}
ret = i2c_smbus_read_word_swapped(opt->client, OPT3001_RESULT);
if (ret < 0) {
dev_err(opt->dev, "failed to read register %02x\n",
OPT3001_RESULT);
goto err;
}
opt->result = ret;
opt->result_ready = true;
}
err:
if (opt->use_irq)
opt->ok_to_ignore_lock = false;
if (ret == 0)
return -ETIMEDOUT;
else if (ret < 0)
return ret;
if (opt->use_irq) {
value = (opt->low_thresh_exp << 12) | opt->low_thresh_mantissa;
ret = i2c_smbus_write_word_swapped(opt->client,
OPT3001_LOW_LIMIT,
value);
if (ret < 0) {
dev_err(opt->dev, "failed to write register %02x\n",
OPT3001_LOW_LIMIT);
return ret;
}
}
exponent = OPT3001_REG_EXPONENT(opt->result);
mantissa = OPT3001_REG_MANTISSA(opt->result);
opt3001_to_iio_ret(opt, exponent, mantissa, val, val2);
return IIO_VAL_INT_PLUS_MICRO;
}
static int opt3001_get_int_time(struct opt3001 *opt, int *val, int *val2)
{
*val = 0;
*val2 = opt->int_time;
return IIO_VAL_INT_PLUS_MICRO;
}
static int opt3001_set_int_time(struct opt3001 *opt, int time)
{
int ret;
u16 reg;
ret = i2c_smbus_read_word_swapped(opt->client, OPT3001_CONFIGURATION);
if (ret < 0) {
dev_err(opt->dev, "failed to read register %02x\n",
OPT3001_CONFIGURATION);
return ret;
}
reg = ret;
switch (time) {
case OPT3001_INT_TIME_SHORT:
reg &= ~OPT3001_CONFIGURATION_CT;
opt->int_time = OPT3001_INT_TIME_SHORT;
break;
case OPT3001_INT_TIME_LONG:
reg |= OPT3001_CONFIGURATION_CT;
opt->int_time = OPT3001_INT_TIME_LONG;
break;
default:
return -EINVAL;
}
return i2c_smbus_write_word_swapped(opt->client, OPT3001_CONFIGURATION,
reg);
}
static int opt3001_read_raw(struct iio_dev *iio,
struct iio_chan_spec const *chan, int *val, int *val2,
long mask)
{
struct opt3001 *opt = iio_priv(iio);
int ret;
if (opt->mode == OPT3001_CONFIGURATION_M_CONTINUOUS)
return -EBUSY;
if (chan->type != IIO_LIGHT)
return -EINVAL;
mutex_lock(&opt->lock);
switch (mask) {
case IIO_CHAN_INFO_PROCESSED:
ret = opt3001_get_lux(opt, val, val2);
break;
case IIO_CHAN_INFO_INT_TIME:
ret = opt3001_get_int_time(opt, val, val2);
break;
default:
ret = -EINVAL;
}
mutex_unlock(&opt->lock);
return ret;
}
static int opt3001_write_raw(struct iio_dev *iio,
struct iio_chan_spec const *chan, int val, int val2,
long mask)
{
struct opt3001 *opt = iio_priv(iio);
int ret;
if (opt->mode == OPT3001_CONFIGURATION_M_CONTINUOUS)
return -EBUSY;
if (chan->type != IIO_LIGHT)
return -EINVAL;
if (mask != IIO_CHAN_INFO_INT_TIME)
return -EINVAL;
if (val != 0)
return -EINVAL;
mutex_lock(&opt->lock);
ret = opt3001_set_int_time(opt, val2);
mutex_unlock(&opt->lock);
return ret;
}
static int opt3001_read_event_value(struct iio_dev *iio,
const struct iio_chan_spec *chan, enum iio_event_type type,
enum iio_event_direction dir, enum iio_event_info info,
int *val, int *val2)
{
struct opt3001 *opt = iio_priv(iio);
int ret = IIO_VAL_INT_PLUS_MICRO;
mutex_lock(&opt->lock);
switch (dir) {
case IIO_EV_DIR_RISING:
opt3001_to_iio_ret(opt, opt->high_thresh_exp,
opt->high_thresh_mantissa, val, val2);
break;
case IIO_EV_DIR_FALLING:
opt3001_to_iio_ret(opt, opt->low_thresh_exp,
opt->low_thresh_mantissa, val, val2);
break;
default:
ret = -EINVAL;
}
mutex_unlock(&opt->lock);
return ret;
}
static int opt3001_write_event_value(struct iio_dev *iio,
const struct iio_chan_spec *chan, enum iio_event_type type,
enum iio_event_direction dir, enum iio_event_info info,
int val, int val2)
{
struct opt3001 *opt = iio_priv(iio);
int ret;
u16 mantissa;
u16 value;
u16 reg;
u8 exponent;
if (val < 0)
return -EINVAL;
mutex_lock(&opt->lock);
ret = opt3001_find_scale(opt, val, val2, &exponent);
if (ret < 0) {
dev_err(opt->dev, "can't find scale for %d.%06u\n", val, val2);
goto err;
}
mantissa = (((val * 1000) + (val2 / 1000)) / 10) >> exponent;
value = (exponent << 12) | mantissa;
switch (dir) {
case IIO_EV_DIR_RISING:
reg = OPT3001_HIGH_LIMIT;
opt->high_thresh_mantissa = mantissa;
opt->high_thresh_exp = exponent;
break;
case IIO_EV_DIR_FALLING:
reg = OPT3001_LOW_LIMIT;
opt->low_thresh_mantissa = mantissa;
opt->low_thresh_exp = exponent;
break;
default:
ret = -EINVAL;
goto err;
}
ret = i2c_smbus_write_word_swapped(opt->client, reg, value);
if (ret < 0) {
dev_err(opt->dev, "failed to write register %02x\n", reg);
goto err;
}
err:
mutex_unlock(&opt->lock);
return ret;
}
static int opt3001_read_event_config(struct iio_dev *iio,
const struct iio_chan_spec *chan, enum iio_event_type type,
enum iio_event_direction dir)
{
struct opt3001 *opt = iio_priv(iio);
return opt->mode == OPT3001_CONFIGURATION_M_CONTINUOUS;
}
static int opt3001_write_event_config(struct iio_dev *iio,
const struct iio_chan_spec *chan, enum iio_event_type type,
enum iio_event_direction dir, int state)
{
struct opt3001 *opt = iio_priv(iio);
int ret;
u16 mode;
u16 reg;
if (state && opt->mode == OPT3001_CONFIGURATION_M_CONTINUOUS)
return 0;
if (!state && opt->mode == OPT3001_CONFIGURATION_M_SHUTDOWN)
return 0;
mutex_lock(&opt->lock);
mode = state ? OPT3001_CONFIGURATION_M_CONTINUOUS
: OPT3001_CONFIGURATION_M_SHUTDOWN;
ret = i2c_smbus_read_word_swapped(opt->client, OPT3001_CONFIGURATION);
if (ret < 0) {
dev_err(opt->dev, "failed to read register %02x\n",
OPT3001_CONFIGURATION);
goto err;
}
reg = ret;
opt3001_set_mode(opt, &reg, mode);
ret = i2c_smbus_write_word_swapped(opt->client, OPT3001_CONFIGURATION,
reg);
if (ret < 0) {
dev_err(opt->dev, "failed to write register %02x\n",
OPT3001_CONFIGURATION);
goto err;
}
err:
mutex_unlock(&opt->lock);
return ret;
}
static int opt3001_read_id(struct opt3001 *opt)
{
char manufacturer[2];
u16 device_id;
int ret;
ret = i2c_smbus_read_word_swapped(opt->client, OPT3001_MANUFACTURER_ID);
if (ret < 0) {
dev_err(opt->dev, "failed to read register %02x\n",
OPT3001_MANUFACTURER_ID);
return ret;
}
manufacturer[0] = ret >> 8;
manufacturer[1] = ret & 0xff;
ret = i2c_smbus_read_word_swapped(opt->client, OPT3001_DEVICE_ID);
if (ret < 0) {
dev_err(opt->dev, "failed to read register %02x\n",
OPT3001_DEVICE_ID);
return ret;
}
device_id = ret;
dev_info(opt->dev, "Found %c%c OPT%04x\n", manufacturer[0],
manufacturer[1], device_id);
return 0;
}
static int opt3001_configure(struct opt3001 *opt)
{
int ret;
u16 reg;
ret = i2c_smbus_read_word_swapped(opt->client, OPT3001_CONFIGURATION);
if (ret < 0) {
dev_err(opt->dev, "failed to read register %02x\n",
OPT3001_CONFIGURATION);
return ret;
}
reg = ret;
reg &= ~OPT3001_CONFIGURATION_RN_MASK;
reg |= OPT3001_CONFIGURATION_RN_AUTO;
if (reg & OPT3001_CONFIGURATION_CT)
opt->int_time = OPT3001_INT_TIME_LONG;
else
opt->int_time = OPT3001_INT_TIME_SHORT;
opt3001_set_mode(opt, &reg, OPT3001_CONFIGURATION_M_SHUTDOWN);
reg |= OPT3001_CONFIGURATION_L;
reg &= ~OPT3001_CONFIGURATION_POL;
reg &= ~OPT3001_CONFIGURATION_ME;
reg &= ~OPT3001_CONFIGURATION_FC_MASK;
ret = i2c_smbus_write_word_swapped(opt->client, OPT3001_CONFIGURATION,
reg);
if (ret < 0) {
dev_err(opt->dev, "failed to write register %02x\n",
OPT3001_CONFIGURATION);
return ret;
}
ret = i2c_smbus_read_word_swapped(opt->client, OPT3001_LOW_LIMIT);
if (ret < 0) {
dev_err(opt->dev, "failed to read register %02x\n",
OPT3001_LOW_LIMIT);
return ret;
}
opt->low_thresh_mantissa = OPT3001_REG_MANTISSA(ret);
opt->low_thresh_exp = OPT3001_REG_EXPONENT(ret);
ret = i2c_smbus_read_word_swapped(opt->client, OPT3001_HIGH_LIMIT);
if (ret < 0) {
dev_err(opt->dev, "failed to read register %02x\n",
OPT3001_HIGH_LIMIT);
return ret;
}
opt->high_thresh_mantissa = OPT3001_REG_MANTISSA(ret);
opt->high_thresh_exp = OPT3001_REG_EXPONENT(ret);
return 0;
}
static irqreturn_t opt3001_irq(int irq, void *_iio)
{
struct iio_dev *iio = _iio;
struct opt3001 *opt = iio_priv(iio);
int ret;
if (!opt->ok_to_ignore_lock)
mutex_lock(&opt->lock);
ret = i2c_smbus_read_word_swapped(opt->client, OPT3001_CONFIGURATION);
if (ret < 0) {
dev_err(opt->dev, "failed to read register %02x\n",
OPT3001_CONFIGURATION);
goto out;
}
if ((ret & OPT3001_CONFIGURATION_M_MASK) ==
OPT3001_CONFIGURATION_M_CONTINUOUS) {
if (ret & OPT3001_CONFIGURATION_FH)
iio_push_event(iio,
IIO_UNMOD_EVENT_CODE(IIO_LIGHT, 0,
IIO_EV_TYPE_THRESH,
IIO_EV_DIR_RISING),
iio_get_time_ns(iio));
if (ret & OPT3001_CONFIGURATION_FL)
iio_push_event(iio,
IIO_UNMOD_EVENT_CODE(IIO_LIGHT, 0,
IIO_EV_TYPE_THRESH,
IIO_EV_DIR_FALLING),
iio_get_time_ns(iio));
} else if (ret & OPT3001_CONFIGURATION_CRF) {
ret = i2c_smbus_read_word_swapped(opt->client, OPT3001_RESULT);
if (ret < 0) {
dev_err(opt->dev, "failed to read register %02x\n",
OPT3001_RESULT);
goto out;
}
opt->result = ret;
opt->result_ready = true;
wake_up(&opt->result_ready_queue);
}
out:
if (!opt->ok_to_ignore_lock)
mutex_unlock(&opt->lock);
return IRQ_HANDLED;
}
static int opt3001_probe(struct i2c_client *client,
const struct i2c_device_id *id)
{
struct device *dev = &client->dev;
struct iio_dev *iio;
struct opt3001 *opt;
int irq = client->irq;
int ret;
iio = devm_iio_device_alloc(dev, sizeof(*opt));
if (!iio)
return -ENOMEM;
opt = iio_priv(iio);
opt->client = client;
opt->dev = dev;
mutex_init(&opt->lock);
init_waitqueue_head(&opt->result_ready_queue);
i2c_set_clientdata(client, iio);
ret = opt3001_read_id(opt);
if (ret)
return ret;
ret = opt3001_configure(opt);
if (ret)
return ret;
iio->name = client->name;
iio->channels = opt3001_channels;
iio->num_channels = ARRAY_SIZE(opt3001_channels);
iio->dev.parent = dev;
iio->modes = INDIO_DIRECT_MODE;
iio->info = &opt3001_info;
ret = devm_iio_device_register(dev, iio);
if (ret) {
dev_err(dev, "failed to register IIO device\n");
return ret;
}
if (irq > 0) {
ret = request_threaded_irq(irq, NULL, opt3001_irq,
IRQF_TRIGGER_FALLING | IRQF_ONESHOT,
"opt3001", iio);
if (ret) {
dev_err(dev, "failed to request IRQ #%d\n", irq);
return ret;
}
opt->use_irq = true;
} else {
dev_dbg(opt->dev, "enabling interrupt-less operation\n");
}
return 0;
}
static int opt3001_remove(struct i2c_client *client)
{
struct iio_dev *iio = i2c_get_clientdata(client);
struct opt3001 *opt = iio_priv(iio);
int ret;
u16 reg;
if (opt->use_irq)
free_irq(client->irq, iio);
ret = i2c_smbus_read_word_swapped(opt->client, OPT3001_CONFIGURATION);
if (ret < 0) {
dev_err(opt->dev, "failed to read register %02x\n",
OPT3001_CONFIGURATION);
return ret;
}
reg = ret;
opt3001_set_mode(opt, &reg, OPT3001_CONFIGURATION_M_SHUTDOWN);
ret = i2c_smbus_write_word_swapped(opt->client, OPT3001_CONFIGURATION,
reg);
if (ret < 0) {
dev_err(opt->dev, "failed to write register %02x\n",
OPT3001_CONFIGURATION);
return ret;
}
return 0;
}
