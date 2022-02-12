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
struct i2c_client *client = chip->client;
int ret = 0;
ret = i2c_smbus_write_word_data(client, reg, swab16(data));
if (ret < 0)
dev_err(&client->dev, "I2C write error\n");
return ret;
}
static int ad7291_i2c_read_data(struct ad7291_chip_info *chip, u8 reg, u16 *data)
{
struct i2c_client *client = chip->client;
u8 commands[4];
int ret = 0;
int i, count;
if (reg == AD7291_T_SENSE || reg == AD7291_T_AVERAGE)
count = 2;
else if (reg == AD7291_VOLTAGE) {
if (!chip->channels) {
dev_err(&client->dev, "No voltage channel is selected.\n");
return -EINVAL;
}
count = 2 + chip->channels * 2;
} else {
dev_err(&client->dev, "I2C wrong data register\n");
return -EINVAL;
}
commands[0] = 0;
commands[1] = (chip->command >> 8) & 0xff;
commands[2] = chip->command & 0xff;
commands[3] = reg;
ret = i2c_master_send(client, commands, 4);
if (ret < 0) {
dev_err(&client->dev, "I2C master send error\n");
return ret;
}
ret = i2c_master_recv(client, (u8 *)data, count);
if (ret < 0) {
dev_err(&client->dev, "I2C master receive error\n");
return ret;
}
ret >>= 2;
for (i = 0; i < ret; i++)
data[i] = swab16(data[i]);
return ret;
}
static ssize_t ad7291_show_mode(struct device *dev,
struct device_attribute *attr,
char *buf)
{
struct iio_dev *dev_info = dev_get_drvdata(dev);
struct ad7291_chip_info *chip = iio_priv(dev_info);
if (chip->command & AD7291_AUTOCYCLE)
return sprintf(buf, "autocycle\n");
else
return sprintf(buf, "command\n");
}
static ssize_t ad7291_store_mode(struct device *dev,
struct device_attribute *attr,
const char *buf,
size_t len)
{
struct iio_dev *dev_info = dev_get_drvdata(dev);
struct ad7291_chip_info *chip = iio_priv(dev_info);
u16 command;
int ret;
command = chip->command & (~AD7291_AUTOCYCLE);
if (strcmp(buf, "autocycle"))
command |= AD7291_AUTOCYCLE;
ret = ad7291_i2c_write(chip, AD7291_COMMAND, command);
if (ret)
return -EIO;
chip->command = command;
return ret;
}
static ssize_t ad7291_show_available_modes(struct device *dev,
struct device_attribute *attr,
char *buf)
{
return sprintf(buf, "command\nautocycle\n");
}
static ssize_t ad7291_store_reset(struct device *dev,
struct device_attribute *attr,
const char *buf,
size_t len)
{
struct iio_dev *dev_info = dev_get_drvdata(dev);
struct ad7291_chip_info *chip = iio_priv(dev_info);
u16 command;
int ret;
command = chip->command | AD7291_RESET;
ret = ad7291_i2c_write(chip, AD7291_COMMAND, command);
if (ret)
return -EIO;
return ret;
}
static ssize_t ad7291_show_ext_ref(struct device *dev,
struct device_attribute *attr,
char *buf)
{
struct iio_dev *dev_info = dev_get_drvdata(dev);
struct ad7291_chip_info *chip = iio_priv(dev_info);
return sprintf(buf, "%d\n", !!(chip->command & AD7291_EXT_REF));
}
static ssize_t ad7291_store_ext_ref(struct device *dev,
struct device_attribute *attr,
const char *buf,
size_t len)
{
struct iio_dev *dev_info = dev_get_drvdata(dev);
struct ad7291_chip_info *chip = iio_priv(dev_info);
u16 command;
int ret;
command = chip->command & (~AD7291_EXT_REF);
if (strcmp(buf, "1"))
command |= AD7291_EXT_REF;
ret = ad7291_i2c_write(chip, AD7291_COMMAND, command);
if (ret)
return -EIO;
chip->command = command;
return ret;
}
static ssize_t ad7291_show_noise_delay(struct device *dev,
struct device_attribute *attr,
char *buf)
{
struct iio_dev *dev_info = dev_get_drvdata(dev);
struct ad7291_chip_info *chip = iio_priv(dev_info);
return sprintf(buf, "%d\n", !!(chip->command & AD7291_NOISE_DELAY));
}
static ssize_t ad7291_store_noise_delay(struct device *dev,
struct device_attribute *attr,
const char *buf,
size_t len)
{
struct iio_dev *dev_info = dev_get_drvdata(dev);
struct ad7291_chip_info *chip = iio_priv(dev_info);
u16 command;
int ret;
command = chip->command & (~AD7291_NOISE_DELAY);
if (strcmp(buf, "1"))
command |= AD7291_NOISE_DELAY;
ret = ad7291_i2c_write(chip, AD7291_COMMAND, command);
if (ret)
return -EIO;
chip->command = command;
return ret;
}
static ssize_t ad7291_show_t_sense(struct device *dev,
struct device_attribute *attr,
char *buf)
{
struct iio_dev *dev_info = dev_get_drvdata(dev);
struct ad7291_chip_info *chip = iio_priv(dev_info);
u16 data;
char sign = ' ';
int ret;
ret = ad7291_i2c_read_data(chip, AD7291_T_SENSE, &data);
if (ret)
return -EIO;
if (data & AD7291_T_VALUE_SIGN) {
data = (AD7291_T_VALUE_SIGN << 1) - data;
sign = '-';
}
return sprintf(buf, "%c%d.%.2d\n", sign,
(data >> AD7291_T_VALUE_FLOAT_OFFSET),
(data & AD7291_T_VALUE_FLOAT_MASK) * 25);
}
static ssize_t ad7291_show_t_average(struct device *dev,
struct device_attribute *attr,
char *buf)
{
struct iio_dev *dev_info = dev_get_drvdata(dev);
struct ad7291_chip_info *chip = iio_priv(dev_info);
u16 data;
char sign = ' ';
int ret;
ret = ad7291_i2c_read_data(chip, AD7291_T_AVERAGE, &data);
if (ret)
return -EIO;
if (data & AD7291_T_VALUE_SIGN) {
data = (AD7291_T_VALUE_SIGN << 1) - data;
sign = '-';
}
return sprintf(buf, "%c%d.%.2d\n", sign,
(data >> AD7291_T_VALUE_FLOAT_OFFSET),
(data & AD7291_T_VALUE_FLOAT_MASK) * 25);
}
static ssize_t ad7291_show_voltage(struct device *dev,
struct device_attribute *attr,
char *buf)
{
struct iio_dev *dev_info = dev_get_drvdata(dev);
struct ad7291_chip_info *chip = iio_priv(dev_info);
u16 data[AD7291_VOLTAGE_LIMIT_COUNT];
int i, size, ret;
ret = ad7291_i2c_read_data(chip, AD7291_VOLTAGE, data);
if (ret)
return -EIO;
for (i = 0; i < AD7291_VOLTAGE_LIMIT_COUNT; i++) {
if (chip->command & (AD7291_T_SENSE_MASK << i)) {
ret = sprintf(buf, "channel[%d]=%d\n", i,
data[i] & AD7291_VALUE_MASK);
if (ret < 0)
break;
buf += ret;
size += ret;
}
}
return size;
}
static ssize_t ad7291_show_channel_mask(struct device *dev,
struct device_attribute *attr,
char *buf)
{
struct iio_dev *dev_info = dev_get_drvdata(dev);
struct ad7291_chip_info *chip = iio_priv(dev_info);
return sprintf(buf, "0x%x\n", (chip->command & AD7291_VOLTAGE_MASK) >>
AD7291_VOLTAGE_OFFSET);
}
static ssize_t ad7291_store_channel_mask(struct device *dev,
struct device_attribute *attr,
const char *buf,
size_t len)
{
struct iio_dev *dev_info = dev_get_drvdata(dev);
struct ad7291_chip_info *chip = iio_priv(dev_info);
u16 command;
unsigned long data;
int i, ret;
ret = strict_strtoul(buf, 16, &data);
if (ret || data > 0xff)
return -EINVAL;
command = chip->command & (~AD7291_VOLTAGE_MASK);
command |= data << AD7291_VOLTAGE_OFFSET;
ret = ad7291_i2c_write(chip, AD7291_COMMAND, command);
if (ret)
return -EIO;
chip->command = command;
for (i = 0, chip->channels = 0; i < AD7291_VOLTAGE_LIMIT_COUNT; i++) {
if (chip->command & (AD7291_T_SENSE_MASK << i))
chip->channels++;
}
return ret;
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
command = chip->command | AD7291_ALART_CLEAR;
ad7291_i2c_write(chip, AD7291_COMMAND, command);
command = chip->command & ~AD7291_ALART_CLEAR;
ad7291_i2c_write(chip, AD7291_COMMAND, command);
if (t_status & (1 << 0))
iio_push_event(indio_dev, 0,
IIO_UNMOD_EVENT_CODE(IIO_TEMP,
0,
IIO_EV_TYPE_THRESH,
IIO_EV_DIR_FALLING),
timestamp);
if (t_status & (1 << 1))
iio_push_event(indio_dev, 0,
IIO_UNMOD_EVENT_CODE(IIO_TEMP,
0,
IIO_EV_TYPE_THRESH,
IIO_EV_DIR_RISING),
timestamp);
if (t_status & (1 << 2))
iio_push_event(indio_dev, 0,
IIO_UNMOD_EVENT_CODE(IIO_TEMP,
0,
IIO_EV_TYPE_THRESH,
IIO_EV_DIR_FALLING),
timestamp);
if (t_status & (1 << 3))
iio_push_event(indio_dev, 0,
IIO_UNMOD_EVENT_CODE(IIO_TEMP,
0,
IIO_EV_TYPE_THRESH,
IIO_EV_DIR_RISING),
timestamp);
for (i = 0; i < AD7291_VOLTAGE_LIMIT_COUNT*2; i += 2) {
if (v_status & (1 << i))
iio_push_event(indio_dev, 0,
IIO_UNMOD_EVENT_CODE(IIO_IN,
i/2,
IIO_EV_TYPE_THRESH,
IIO_EV_DIR_FALLING),
timestamp);
if (v_status & (1 << (i + 1)))
iio_push_event(indio_dev, 0,
IIO_UNMOD_EVENT_CODE(IIO_IN,
i/2,
IIO_EV_TYPE_THRESH,
IIO_EV_DIR_RISING),
timestamp);
}
return IRQ_HANDLED;
}
static inline ssize_t ad7291_show_t_bound(struct device *dev,
struct device_attribute *attr,
char *buf)
{
struct iio_dev *dev_info = dev_get_drvdata(dev);
struct ad7291_chip_info *chip = iio_priv(dev_info);
struct iio_dev_attr *this_attr = to_iio_dev_attr(attr);
u16 data;
char sign = ' ';
int ret;
ret = ad7291_i2c_read(chip, this_attr->address, &data);
if (ret)
return -EIO;
data &= AD7291_VALUE_MASK;
if (data & AD7291_T_VALUE_SIGN) {
data = (AD7291_T_VALUE_SIGN << 1) - data;
sign = '-';
}
return sprintf(buf, "%c%d.%.2d\n", sign,
data >> AD7291_T_VALUE_FLOAT_OFFSET,
(data & AD7291_T_VALUE_FLOAT_MASK) * 25);
}
static inline ssize_t ad7291_set_t_bound(struct device *dev,
struct device_attribute *attr,
const char *buf,
size_t len)
{
struct iio_dev *dev_info = dev_get_drvdata(dev);
struct ad7291_chip_info *chip = iio_priv(dev_info);
struct iio_dev_attr *this_attr = to_iio_dev_attr(attr);
long tmp1, tmp2;
u16 data;
char *pos;
int ret;
pos = strchr(buf, '.');
ret = strict_strtol(buf, 10, &tmp1);
if (ret || tmp1 > 127 || tmp1 < -128)
return -EINVAL;
if (pos) {
len = strlen(pos);
if (len > AD7291_T_VALUE_FLOAT_OFFSET)
len = AD7291_T_VALUE_FLOAT_OFFSET;
pos[len] = 0;
ret = strict_strtol(pos, 10, &tmp2);
if (!ret)
tmp2 = (tmp2 / 25) * 25;
}
if (tmp1 < 0)
data = (u16)(-tmp1);
else
data = (u16)tmp1;
data = (data << AD7291_T_VALUE_FLOAT_OFFSET) |
(tmp2 & AD7291_T_VALUE_FLOAT_MASK);
if (tmp1 < 0)
data = (AD7291_T_VALUE_SIGN << 1) - data;
ret = ad7291_i2c_write(chip, this_attr->address, data);
if (ret)
return -EIO;
return ret;
}
static inline ssize_t ad7291_show_v_bound(struct device *dev,
struct device_attribute *attr,
u8 bound_reg,
char *buf)
{
struct iio_dev *dev_info = dev_get_drvdata(dev);
struct ad7291_chip_info *chip = iio_priv(dev_info);
u16 data;
int ret;
if (bound_reg < AD7291_VOLTAGE_LIMIT_BASE ||
bound_reg >= AD7291_VOLTAGE_LIMIT_BASE +
AD7291_VOLTAGE_LIMIT_COUNT)
return -EINVAL;
ret = ad7291_i2c_read(chip, bound_reg, &data);
if (ret)
return -EIO;
data &= AD7291_VALUE_MASK;
return sprintf(buf, "%d\n", data);
}
static inline ssize_t ad7291_set_v_bound(struct device *dev,
struct device_attribute *attr,
u8 bound_reg,
const char *buf,
size_t len)
{
struct iio_dev *dev_info = dev_get_drvdata(dev);
struct ad7291_chip_info *chip = iio_priv(dev_info);
unsigned long value;
u16 data;
int ret;
if (bound_reg < AD7291_VOLTAGE_LIMIT_BASE ||
bound_reg >= AD7291_VOLTAGE_LIMIT_BASE +
AD7291_VOLTAGE_LIMIT_COUNT)
return -EINVAL;
ret = strict_strtoul(buf, 10, &value);
if (ret || value >= 4096)
return -EINVAL;
data = (u16)value;
ret = ad7291_i2c_write(chip, bound_reg, data);
if (ret)
return -EIO;
return ret;
}
static int __devinit ad7291_probe(struct i2c_client *client,
const struct i2c_device_id *id)
{
struct ad7291_chip_info *chip;
struct iio_dev *indio_dev;
int ret = 0;
indio_dev = iio_allocate_device(sizeof(*chip));
if (indio_dev == NULL) {
ret = -ENOMEM;
goto error_ret;
}
chip = iio_priv(indio_dev);
i2c_set_clientdata(client, indio_dev);
chip->client = client;
chip->command = AD7291_NOISE_DELAY | AD7291_T_SENSE_MASK;
indio_dev->name = id->name;
indio_dev->dev.parent = &client->dev;
indio_dev->info = &ad7291_info;
indio_dev->modes = INDIO_DIRECT_MODE;
ret = iio_device_register(indio_dev);
if (ret)
goto error_free_dev;
if (client->irq > 0) {
ret = request_threaded_irq(client->irq,
NULL,
&ad7291_event_handler,
IRQF_TRIGGER_LOW | IRQF_ONESHOT,
id->name,
indio_dev);
if (ret)
goto error_unreg_dev;
chip->command |= AD7291_ALART_POLARITY;
}
ret = ad7291_i2c_write(chip, AD7291_COMMAND, chip->command);
if (ret) {
ret = -EIO;
goto error_unreg_irq;
}
dev_info(&client->dev, "%s temperature sensor registered.\n",
id->name);
return 0;
error_unreg_irq:
free_irq(client->irq, indio_dev);
error_unreg_dev:
iio_device_unregister(indio_dev);
error_free_dev:
iio_free_device(indio_dev);
error_ret:
return ret;
}
static int __devexit ad7291_remove(struct i2c_client *client)
{
struct iio_dev *indio_dev = i2c_get_clientdata(client);
if (client->irq)
free_irq(client->irq, indio_dev);
iio_device_unregister(indio_dev);
iio_free_device(indio_dev);
return 0;
}
static __init int ad7291_init(void)
{
return i2c_add_driver(&ad7291_driver);
}
static __exit void ad7291_exit(void)
{
i2c_del_driver(&ad7291_driver);
}
