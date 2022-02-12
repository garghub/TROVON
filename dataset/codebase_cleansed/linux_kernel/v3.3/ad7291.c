static int ad7291_i2c_read(struct ad7291_chip_info *chip, u8 reg, u16 *data)
{
struct i2c_client *client = chip->client;
int ret = 0;
ret = i2c_smbus_read_word_data(client, reg);
if (ret < 0) {
dev_err(&client->dev, "I2C read error\n");
return ret;
}
*data = swab16((u16)ret);
return 0;
}
static int ad7291_i2c_write(struct ad7291_chip_info *chip, u8 reg, u16 data)
{
return i2c_smbus_write_word_data(chip->client, reg, swab16(data));
}
static ssize_t ad7291_store_reset(struct device *dev,
struct device_attribute *attr,
const char *buf,
size_t len)
{
struct iio_dev *indio_dev = dev_get_drvdata(dev);
struct ad7291_chip_info *chip = iio_priv(indio_dev);
return ad7291_i2c_write(chip, AD7291_COMMAND,
chip->command | AD7291_RESET);
}
static irqreturn_t ad7291_event_handler(int irq, void *private)
{
struct iio_dev *indio_dev = private;
struct ad7291_chip_info *chip = iio_priv(private);
u16 t_status, v_status;
u16 command;
int i;
s64 timestamp = iio_get_time_ns();
if (ad7291_i2c_read(chip, AD7291_T_ALERT_STATUS, &t_status))
return IRQ_HANDLED;
if (ad7291_i2c_read(chip, AD7291_VOLTAGE_ALERT_STATUS, &v_status))
return IRQ_HANDLED;
if (!(t_status || v_status))
return IRQ_HANDLED;
command = chip->command | AD7291_ALERT_CLEAR;
ad7291_i2c_write(chip, AD7291_COMMAND, command);
command = chip->command & ~AD7291_ALERT_CLEAR;
ad7291_i2c_write(chip, AD7291_COMMAND, command);
if ((t_status & (1 << 0)) || (t_status & (1 << 2)))
iio_push_event(indio_dev,
IIO_UNMOD_EVENT_CODE(IIO_TEMP,
0,
IIO_EV_TYPE_THRESH,
IIO_EV_DIR_FALLING),
timestamp);
if ((t_status & (1 << 1)) || (t_status & (1 << 3)))
iio_push_event(indio_dev,
IIO_UNMOD_EVENT_CODE(IIO_TEMP,
0,
IIO_EV_TYPE_THRESH,
IIO_EV_DIR_RISING),
timestamp);
for (i = 0; i < AD7291_VOLTAGE_LIMIT_COUNT*2; i += 2) {
if (v_status & (1 << i))
iio_push_event(indio_dev,
IIO_UNMOD_EVENT_CODE(IIO_VOLTAGE,
i/2,
IIO_EV_TYPE_THRESH,
IIO_EV_DIR_FALLING),
timestamp);
if (v_status & (1 << (i + 1)))
iio_push_event(indio_dev,
IIO_UNMOD_EVENT_CODE(IIO_VOLTAGE,
i/2,
IIO_EV_TYPE_THRESH,
IIO_EV_DIR_RISING),
timestamp);
}
return IRQ_HANDLED;
}
static inline ssize_t ad7291_show_hyst(struct device *dev,
struct device_attribute *attr,
char *buf)
{
struct iio_dev *indio_dev = dev_get_drvdata(dev);
struct ad7291_chip_info *chip = iio_priv(indio_dev);
struct iio_dev_attr *this_attr = to_iio_dev_attr(attr);
u16 data;
int ret;
ret = ad7291_i2c_read(chip, this_attr->address, &data);
if (ret < 0)
return ret;
return sprintf(buf, "%d\n", data & AD7291_VALUE_MASK);
}
static inline ssize_t ad7291_set_hyst(struct device *dev,
struct device_attribute *attr,
const char *buf,
size_t len)
{
struct iio_dev *indio_dev = dev_get_drvdata(dev);
struct ad7291_chip_info *chip = iio_priv(indio_dev);
struct iio_dev_attr *this_attr = to_iio_dev_attr(attr);
u16 data;
int ret;
ret = kstrtou16(buf, 10, &data);
if (ret < 0)
return ret;
if (data > AD7291_VALUE_MASK)
return -EINVAL;
ret = ad7291_i2c_write(chip, this_attr->address, data);
if (ret < 0)
return ret;
return len;
}
static int ad7291_read_event_value(struct iio_dev *indio_dev,
u64 event_code,
int *val)
{
struct ad7291_chip_info *chip = iio_priv(indio_dev);
int ret;
u8 reg;
u16 uval;
s16 signval;
switch (IIO_EVENT_CODE_EXTRACT_CHAN_TYPE(event_code)) {
case IIO_VOLTAGE:
reg = ad7291_limit_regs[IIO_EVENT_CODE_EXTRACT_NUM(event_code)]
[!(IIO_EVENT_CODE_EXTRACT_DIR(event_code) ==
IIO_EV_DIR_RISING)];
ret = ad7291_i2c_read(chip, reg, &uval);
if (ret < 0)
return ret;
*val = uval & AD7291_VALUE_MASK;
return 0;
case IIO_TEMP:
reg = ad7291_limit_regs[8]
[!(IIO_EVENT_CODE_EXTRACT_DIR(event_code) ==
IIO_EV_DIR_RISING)];
ret = ad7291_i2c_read(chip, reg, &signval);
if (ret < 0)
return ret;
signval = (s16)((signval & AD7291_VALUE_MASK) << 4) >> 4;
*val = signval;
return 0;
default:
return -EINVAL;
};
}
static int ad7291_write_event_value(struct iio_dev *indio_dev,
u64 event_code,
int val)
{
struct ad7291_chip_info *chip = iio_priv(indio_dev);
u8 reg;
s16 signval;
switch (IIO_EVENT_CODE_EXTRACT_CHAN_TYPE(event_code)) {
case IIO_VOLTAGE:
if (val > AD7291_VALUE_MASK || val < 0)
return -EINVAL;
reg = ad7291_limit_regs[IIO_EVENT_CODE_EXTRACT_NUM(event_code)]
[!(IIO_EVENT_CODE_EXTRACT_DIR(event_code) ==
IIO_EV_DIR_RISING)];
return ad7291_i2c_write(chip, reg, val);
case IIO_TEMP:
if (val > 2047 || val < -2048)
return -EINVAL;
reg = ad7291_limit_regs[8]
[!(IIO_EVENT_CODE_EXTRACT_DIR(event_code) ==
IIO_EV_DIR_RISING)];
signval = val;
return ad7291_i2c_write(chip, reg, *(u16 *)&signval);
default:
return -EINVAL;
};
}
static int ad7291_read_event_config(struct iio_dev *indio_dev,
u64 event_code)
{
struct ad7291_chip_info *chip = iio_priv(indio_dev);
switch (IIO_EVENT_CODE_EXTRACT_CHAN_TYPE(event_code)) {
case IIO_VOLTAGE:
if (chip->c_mask &
(1 << (15 - IIO_EVENT_CODE_EXTRACT_NUM(event_code))))
return 1;
else
return 0;
case IIO_TEMP:
return 1;
default:
return -EINVAL;
}
}
static int ad7291_write_event_config(struct iio_dev *indio_dev,
u64 event_code,
int state)
{
int ret = 0;
struct ad7291_chip_info *chip = iio_priv(indio_dev);
u16 regval;
mutex_lock(&chip->state_lock);
regval = chip->command;
switch (IIO_EVENT_CODE_EXTRACT_TYPE(event_code)) {
case IIO_VOLTAGE:
if ((!state) && (chip->c_mask & (1 << (15 -
IIO_EVENT_CODE_EXTRACT_NUM(event_code)))))
chip->c_mask &= ~(1 << (15 - IIO_EVENT_CODE_EXTRACT_NUM
(event_code)));
else if (state && (!(chip->c_mask & (1 << (15 -
IIO_EVENT_CODE_EXTRACT_NUM(event_code))))))
chip->c_mask |= (1 << (15 - IIO_EVENT_CODE_EXTRACT_NUM
(event_code)));
else
break;
regval &= ~AD7291_AUTOCYCLE;
regval |= chip->c_mask;
if (chip->c_mask)
regval |= AD7291_AUTOCYCLE;
ret = ad7291_i2c_write(chip, AD7291_COMMAND, regval);
if (ret < 0)
goto error_ret;
chip->command = regval;
break;
default:
ret = -EINVAL;
}
error_ret:
mutex_unlock(&chip->state_lock);
return ret;
}
static int ad7291_read_raw(struct iio_dev *indio_dev,
struct iio_chan_spec const *chan,
int *val,
int *val2,
long mask)
{
int ret;
struct ad7291_chip_info *chip = iio_priv(indio_dev);
unsigned int scale_uv;
u16 regval;
s16 signval;
switch (mask) {
case 0:
switch (chan->type) {
case IIO_VOLTAGE:
mutex_lock(&chip->state_lock);
if (chip->command & AD7291_AUTOCYCLE) {
mutex_unlock(&chip->state_lock);
return -EBUSY;
}
regval = chip->command & (~AD7291_VOLTAGE_MASK);
regval |= 1 << (15 - chan->channel);
ret = ad7291_i2c_write(chip, AD7291_COMMAND, regval);
if (ret < 0) {
mutex_unlock(&chip->state_lock);
return ret;
}
ret = i2c_smbus_read_word_data(chip->client,
AD7291_VOLTAGE);
if (ret < 0) {
mutex_unlock(&chip->state_lock);
return ret;
}
*val = swab16((u16)ret) & AD7291_VALUE_MASK;
mutex_unlock(&chip->state_lock);
return IIO_VAL_INT;
case IIO_TEMP:
ret = i2c_smbus_read_word_data(chip->client,
AD7291_T_SENSE);
if (ret < 0)
return ret;
signval = (s16)((swab16((u16)ret) &
AD7291_VALUE_MASK) << 4) >> 4;
*val = signval;
return IIO_VAL_INT;
default:
return -EINVAL;
}
case IIO_CHAN_INFO_AVERAGE_RAW:
ret = i2c_smbus_read_word_data(chip->client,
AD7291_T_AVERAGE);
if (ret < 0)
return ret;
signval = (s16)((swab16((u16)ret) &
AD7291_VALUE_MASK) << 4) >> 4;
*val = signval;
return IIO_VAL_INT;
case IIO_CHAN_INFO_SCALE:
switch (chan->type) {
case IIO_VOLTAGE:
scale_uv = (chip->int_vref_mv * 1000) >> AD7291_BITS;
*val = scale_uv / 1000;
*val2 = (scale_uv % 1000) * 1000;
return IIO_VAL_INT_PLUS_MICRO;
case IIO_TEMP:
*val = 250;
return IIO_VAL_INT;
default:
return -EINVAL;
}
default:
return -EINVAL;
}
}
static int __devinit ad7291_probe(struct i2c_client *client,
const struct i2c_device_id *id)
{
struct ad7291_chip_info *chip;
struct iio_dev *indio_dev;
int ret = 0, voltage_uv = 0;
indio_dev = iio_allocate_device(sizeof(*chip));
if (indio_dev == NULL) {
ret = -ENOMEM;
goto error_ret;
}
chip = iio_priv(indio_dev);
chip->reg = regulator_get(&client->dev, "vcc");
if (!IS_ERR(chip->reg)) {
ret = regulator_enable(chip->reg);
if (ret)
goto error_put_reg;
voltage_uv = regulator_get_voltage(chip->reg);
}
mutex_init(&chip->state_lock);
i2c_set_clientdata(client, indio_dev);
chip->client = client;
chip->command = AD7291_NOISE_DELAY |
AD7291_T_SENSE_MASK |
AD7291_ALERT_POLARITY;
if (voltage_uv) {
chip->int_vref_mv = voltage_uv / 1000;
chip->command |= AD7291_EXT_REF;
} else {
chip->int_vref_mv = 2500;
}
indio_dev->name = id->name;
indio_dev->channels = ad7291_channels;
indio_dev->num_channels = ARRAY_SIZE(ad7291_channels);
indio_dev->dev.parent = &client->dev;
indio_dev->info = &ad7291_info;
indio_dev->modes = INDIO_DIRECT_MODE;
ret = ad7291_i2c_write(chip, AD7291_COMMAND, AD7291_RESET);
if (ret) {
ret = -EIO;
goto error_disable_reg;
}
ret = ad7291_i2c_write(chip, AD7291_COMMAND, chip->command);
if (ret) {
ret = -EIO;
goto error_disable_reg;
}
if (client->irq > 0) {
ret = request_threaded_irq(client->irq,
NULL,
&ad7291_event_handler,
IRQF_TRIGGER_LOW | IRQF_ONESHOT,
id->name,
indio_dev);
if (ret)
goto error_disable_reg;
}
ret = iio_device_register(indio_dev);
if (ret)
goto error_unreg_irq;
dev_info(&client->dev, "%s ADC registered.\n",
id->name);
return 0;
error_unreg_irq:
if (client->irq)
free_irq(client->irq, indio_dev);
error_disable_reg:
if (!IS_ERR(chip->reg))
regulator_disable(chip->reg);
error_put_reg:
if (!IS_ERR(chip->reg))
regulator_put(chip->reg);
iio_free_device(indio_dev);
error_ret:
return ret;
}
static int __devexit ad7291_remove(struct i2c_client *client)
{
struct iio_dev *indio_dev = i2c_get_clientdata(client);
struct ad7291_chip_info *chip = iio_priv(indio_dev);
iio_device_unregister(indio_dev);
if (client->irq)
free_irq(client->irq, indio_dev);
if (!IS_ERR(chip->reg)) {
regulator_disable(chip->reg);
regulator_put(chip->reg);
}
iio_free_device(indio_dev);
return 0;
}
