static bool ina2xx_is_writeable_reg(struct device *dev, unsigned int reg)
{
return (reg == INA2XX_CONFIG) || (reg > INA2XX_CURRENT);
}
static bool ina2xx_is_volatile_reg(struct device *dev, unsigned int reg)
{
return (reg != INA2XX_CONFIG);
}
static inline bool is_signed_reg(unsigned int reg)
{
return (reg == INA2XX_SHUNT_VOLTAGE) || (reg == INA2XX_CURRENT);
}
static int ina2xx_read_raw(struct iio_dev *indio_dev,
struct iio_chan_spec const *chan,
int *val, int *val2, long mask)
{
int ret;
struct ina2xx_chip_info *chip = iio_priv(indio_dev);
unsigned int regval;
switch (mask) {
case IIO_CHAN_INFO_RAW:
ret = regmap_read(chip->regmap, chan->address, &regval);
if (ret < 0)
return ret;
if (is_signed_reg(chan->address))
*val = (s16) regval;
else
*val = regval;
return IIO_VAL_INT;
case IIO_CHAN_INFO_OVERSAMPLING_RATIO:
*val = chip->avg;
return IIO_VAL_INT;
case IIO_CHAN_INFO_INT_TIME:
*val = 0;
if (chan->address == INA2XX_SHUNT_VOLTAGE)
*val2 = chip->int_time_vshunt;
else
*val2 = chip->int_time_vbus;
return IIO_VAL_INT_PLUS_MICRO;
case IIO_CHAN_INFO_SAMP_FREQ:
*val = DIV_ROUND_CLOSEST(1000000, SAMPLING_PERIOD(chip));
return IIO_VAL_INT;
case IIO_CHAN_INFO_SCALE:
switch (chan->address) {
case INA2XX_SHUNT_VOLTAGE:
*val2 = chip->config->shunt_div;
*val = 1000;
return IIO_VAL_FRACTIONAL;
case INA2XX_BUS_VOLTAGE:
*val = chip->config->bus_voltage_lsb;
*val2 = 1000 << chip->config->bus_voltage_shift;
return IIO_VAL_FRACTIONAL;
case INA2XX_POWER:
*val = chip->config->power_lsb;
*val2 = 1000;
return IIO_VAL_FRACTIONAL;
case INA2XX_CURRENT:
*val = 1;
return IIO_VAL_INT;
}
}
return -EINVAL;
}
static int ina226_set_average(struct ina2xx_chip_info *chip, unsigned int val,
unsigned int *config)
{
int bits;
if (val > 1024 || val < 1)
return -EINVAL;
bits = find_closest(val, ina226_avg_tab,
ARRAY_SIZE(ina226_avg_tab));
chip->avg = ina226_avg_tab[bits];
*config &= ~INA226_AVG_MASK;
*config |= INA226_SHIFT_AVG(bits) & INA226_AVG_MASK;
return 0;
}
static int ina226_set_int_time_vbus(struct ina2xx_chip_info *chip,
unsigned int val_us, unsigned int *config)
{
int bits;
if (val_us > 8244 || val_us < 140)
return -EINVAL;
bits = find_closest(val_us, ina226_conv_time_tab,
ARRAY_SIZE(ina226_conv_time_tab));
chip->int_time_vbus = ina226_conv_time_tab[bits];
*config &= ~INA226_ITB_MASK;
*config |= INA226_SHIFT_ITB(bits) & INA226_ITB_MASK;
return 0;
}
static int ina226_set_int_time_vshunt(struct ina2xx_chip_info *chip,
unsigned int val_us, unsigned int *config)
{
int bits;
if (val_us > 8244 || val_us < 140)
return -EINVAL;
bits = find_closest(val_us, ina226_conv_time_tab,
ARRAY_SIZE(ina226_conv_time_tab));
chip->int_time_vshunt = ina226_conv_time_tab[bits];
*config &= ~INA226_ITS_MASK;
*config |= INA226_SHIFT_ITS(bits) & INA226_ITS_MASK;
return 0;
}
static int ina2xx_write_raw(struct iio_dev *indio_dev,
struct iio_chan_spec const *chan,
int val, int val2, long mask)
{
struct ina2xx_chip_info *chip = iio_priv(indio_dev);
int ret;
unsigned int config, tmp;
if (iio_buffer_enabled(indio_dev))
return -EBUSY;
mutex_lock(&chip->state_lock);
ret = regmap_read(chip->regmap, INA2XX_CONFIG, &config);
if (ret < 0)
goto _err;
tmp = config;
switch (mask) {
case IIO_CHAN_INFO_OVERSAMPLING_RATIO:
ret = ina226_set_average(chip, val, &tmp);
break;
case IIO_CHAN_INFO_INT_TIME:
if (chan->address == INA2XX_SHUNT_VOLTAGE)
ret = ina226_set_int_time_vshunt(chip, val2, &tmp);
else
ret = ina226_set_int_time_vbus(chip, val2, &tmp);
break;
default:
ret = -EINVAL;
}
if (!ret && (tmp != config))
ret = regmap_write(chip->regmap, INA2XX_CONFIG, tmp);
_err:
mutex_unlock(&chip->state_lock);
return ret;
}
static ssize_t ina2xx_allow_async_readout_show(struct device *dev,
struct device_attribute *attr,
char *buf)
{
struct ina2xx_chip_info *chip = iio_priv(dev_to_iio_dev(dev));
return sprintf(buf, "%d\n", chip->allow_async_readout);
}
static ssize_t ina2xx_allow_async_readout_store(struct device *dev,
struct device_attribute *attr,
const char *buf, size_t len)
{
struct ina2xx_chip_info *chip = iio_priv(dev_to_iio_dev(dev));
bool val;
int ret;
ret = strtobool((const char *) buf, &val);
if (ret)
return ret;
chip->allow_async_readout = val;
return len;
}
static int set_shunt_resistor(struct ina2xx_chip_info *chip, unsigned int val)
{
if (val <= 0 || val > chip->config->calibration_factor)
return -EINVAL;
chip->shunt_resistor = val;
return 0;
}
static ssize_t ina2xx_shunt_resistor_show(struct device *dev,
struct device_attribute *attr,
char *buf)
{
struct ina2xx_chip_info *chip = iio_priv(dev_to_iio_dev(dev));
return sprintf(buf, "%d\n", chip->shunt_resistor);
}
static ssize_t ina2xx_shunt_resistor_store(struct device *dev,
struct device_attribute *attr,
const char *buf, size_t len)
{
struct ina2xx_chip_info *chip = iio_priv(dev_to_iio_dev(dev));
unsigned long val;
int ret;
ret = kstrtoul((const char *) buf, 10, &val);
if (ret)
return ret;
ret = set_shunt_resistor(chip, val);
if (ret)
return ret;
return len;
}
static int ina2xx_work_buffer(struct iio_dev *indio_dev)
{
struct ina2xx_chip_info *chip = iio_priv(indio_dev);
unsigned short data[8];
int bit, ret, i = 0;
unsigned long buffer_us, elapsed_us;
s64 time_a, time_b;
unsigned int alert;
time_a = iio_get_time_ns();
if (!chip->allow_async_readout)
do {
ret = regmap_read(chip->regmap, INA226_ALERT_MASK,
&alert);
if (ret < 0)
return ret;
alert &= INA266_CVRF;
trace_printk("Conversion ready: %d\n", !!alert);
} while (!alert);
for_each_set_bit(bit, indio_dev->active_scan_mask,
indio_dev->masklength) {
unsigned int val;
ret = regmap_read(chip->regmap,
INA2XX_SHUNT_VOLTAGE + bit, &val);
if (ret < 0)
return ret;
data[i++] = val;
}
time_b = iio_get_time_ns();
iio_push_to_buffers_with_timestamp(indio_dev,
(unsigned int *)data, time_a);
buffer_us = (unsigned long)(time_b - time_a) / 1000;
elapsed_us = (unsigned long)(time_a - chip->prev_ns) / 1000;
trace_printk("uS: elapsed: %lu, buf: %lu\n", elapsed_us, buffer_us);
chip->prev_ns = time_a;
return buffer_us;
}
static int ina2xx_capture_thread(void *data)
{
struct iio_dev *indio_dev = (struct iio_dev *)data;
struct ina2xx_chip_info *chip = iio_priv(indio_dev);
unsigned int sampling_us = SAMPLING_PERIOD(chip);
int buffer_us;
if (!chip->allow_async_readout)
sampling_us -= 200;
do {
buffer_us = ina2xx_work_buffer(indio_dev);
if (buffer_us < 0)
return buffer_us;
if (sampling_us > buffer_us)
udelay(sampling_us - buffer_us);
} while (!kthread_should_stop());
return 0;
}
static int ina2xx_buffer_enable(struct iio_dev *indio_dev)
{
struct ina2xx_chip_info *chip = iio_priv(indio_dev);
unsigned int sampling_us = SAMPLING_PERIOD(chip);
trace_printk("Enabling buffer w/ scan_mask %02x, freq = %d, avg =%u\n",
(unsigned int)(*indio_dev->active_scan_mask),
1000000/sampling_us, chip->avg);
trace_printk("Expected work period: %u us\n", sampling_us);
trace_printk("Async readout mode: %d\n", chip->allow_async_readout);
chip->prev_ns = iio_get_time_ns();
chip->task = kthread_run(ina2xx_capture_thread, (void *)indio_dev,
"%s:%d-%uus", indio_dev->name, indio_dev->id,
sampling_us);
return PTR_ERR_OR_ZERO(chip->task);
}
static int ina2xx_buffer_disable(struct iio_dev *indio_dev)
{
struct ina2xx_chip_info *chip = iio_priv(indio_dev);
if (chip->task) {
kthread_stop(chip->task);
chip->task = NULL;
}
return 0;
}
static int ina2xx_debug_reg(struct iio_dev *indio_dev,
unsigned reg, unsigned writeval, unsigned *readval)
{
struct ina2xx_chip_info *chip = iio_priv(indio_dev);
if (!readval)
return regmap_write(chip->regmap, reg, writeval);
return regmap_read(chip->regmap, reg, readval);
}
static int ina2xx_init(struct ina2xx_chip_info *chip, unsigned int config)
{
u16 regval;
int ret = regmap_write(chip->regmap, INA2XX_CONFIG, config);
if (ret < 0)
return ret;
regval = DIV_ROUND_CLOSEST(chip->config->calibration_factor,
chip->shunt_resistor);
return regmap_write(chip->regmap, INA2XX_CALIBRATION, regval);
}
static int ina2xx_probe(struct i2c_client *client,
const struct i2c_device_id *id)
{
struct ina2xx_chip_info *chip;
struct iio_dev *indio_dev;
struct iio_buffer *buffer;
int ret;
unsigned int val;
indio_dev = devm_iio_device_alloc(&client->dev, sizeof(*chip));
if (!indio_dev)
return -ENOMEM;
chip = iio_priv(indio_dev);
chip->config = &ina2xx_config[id->driver_data];
if (of_property_read_u32(client->dev.of_node,
"shunt-resistor", &val) < 0) {
struct ina2xx_platform_data *pdata =
dev_get_platdata(&client->dev);
if (pdata)
val = pdata->shunt_uohms;
else
val = INA2XX_RSHUNT_DEFAULT;
}
ret = set_shunt_resistor(chip, val);
if (ret)
return ret;
mutex_init(&chip->state_lock);
i2c_set_clientdata(client, indio_dev);
indio_dev->name = id->name;
indio_dev->channels = ina2xx_channels;
indio_dev->num_channels = ARRAY_SIZE(ina2xx_channels);
indio_dev->dev.parent = &client->dev;
indio_dev->info = &ina2xx_info;
indio_dev->modes = INDIO_DIRECT_MODE | INDIO_BUFFER_SOFTWARE;
chip->regmap = devm_regmap_init_i2c(client, &ina2xx_regmap_config);
if (IS_ERR(chip->regmap)) {
dev_err(&client->dev, "failed to allocate register map\n");
return PTR_ERR(chip->regmap);
}
val = chip->config->config_default;
if (id->driver_data == ina226) {
ina226_set_average(chip, INA226_DEFAULT_AVG, &val);
ina226_set_int_time_vbus(chip, INA226_DEFAULT_IT, &val);
ina226_set_int_time_vshunt(chip, INA226_DEFAULT_IT, &val);
}
ret = ina2xx_init(chip, val);
if (ret < 0) {
dev_err(&client->dev, "error configuring the device: %d\n",
ret);
return -ENODEV;
}
buffer = devm_iio_kfifo_allocate(&indio_dev->dev);
if (!buffer)
return -ENOMEM;
indio_dev->setup_ops = &ina2xx_setup_ops;
iio_device_attach_buffer(indio_dev, buffer);
return iio_device_register(indio_dev);
}
static int ina2xx_remove(struct i2c_client *client)
{
struct iio_dev *indio_dev = i2c_get_clientdata(client);
struct ina2xx_chip_info *chip = iio_priv(indio_dev);
iio_device_unregister(indio_dev);
return regmap_update_bits(chip->regmap, INA2XX_CONFIG,
INA2XX_MODE_MASK, 0);
}
