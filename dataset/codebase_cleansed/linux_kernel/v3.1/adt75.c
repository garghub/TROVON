static int adt75_i2c_read(struct iio_dev *dev_info, u8 reg, u8 *data)
{
struct adt75_chip_info *chip = iio_priv(dev_info);
struct i2c_client *client = chip->client;
int ret = 0, len;
ret = i2c_smbus_write_byte(client, reg);
if (ret < 0) {
dev_err(&client->dev, "I2C read register address error\n");
return ret;
}
if (reg == ADT75_CONFIG || reg == ADT75_ONESHOT)
len = 1;
else
len = 2;
ret = i2c_master_recv(client, data, len);
if (ret < 0) {
dev_err(&client->dev, "I2C read error\n");
return ret;
}
return ret;
}
static int adt75_i2c_write(struct iio_dev *dev_info, u8 reg, u8 data)
{
struct adt75_chip_info *chip = iio_priv(dev_info);
struct i2c_client *client = chip->client;
int ret = 0;
if (reg == ADT75_CONFIG || reg == ADT75_ONESHOT)
ret = i2c_smbus_write_byte_data(client, reg, data);
else
ret = i2c_smbus_write_word_data(client, reg, data);
if (ret < 0)
dev_err(&client->dev, "I2C write error\n");
return ret;
}
static ssize_t adt75_show_mode(struct device *dev,
struct device_attribute *attr,
char *buf)
{
struct adt75_chip_info *chip = iio_priv(dev_get_drvdata(dev));
if (chip->config & ADT75_PD)
return sprintf(buf, "power-save\n");
else
return sprintf(buf, "full\n");
}
static ssize_t adt75_store_mode(struct device *dev,
struct device_attribute *attr,
const char *buf,
size_t len)
{
struct iio_dev *dev_info = dev_get_drvdata(dev);
struct adt75_chip_info *chip = iio_priv(dev_info);
int ret;
u8 config;
ret = adt75_i2c_read(dev_info, ADT75_CONFIG, &chip->config);
if (ret)
return -EIO;
config = chip->config & ~ADT75_PD;
if (!strcmp(buf, "full"))
config |= ADT75_PD;
ret = adt75_i2c_write(dev_info, ADT75_CONFIG, config);
if (ret)
return -EIO;
chip->config = config;
return ret;
}
static ssize_t adt75_show_available_modes(struct device *dev,
struct device_attribute *attr,
char *buf)
{
return sprintf(buf, "full\npower-down\n");
}
static ssize_t adt75_show_oneshot(struct device *dev,
struct device_attribute *attr,
char *buf)
{
struct adt75_chip_info *chip = iio_priv(dev_get_drvdata(dev));
return sprintf(buf, "%d\n", !!(chip->config & ADT75_ONESHOT));
}
static ssize_t adt75_store_oneshot(struct device *dev,
struct device_attribute *attr,
const char *buf,
size_t len)
{
struct iio_dev *dev_info = dev_get_drvdata(dev);
struct adt75_chip_info *chip = iio_priv(dev_info);
unsigned long data = 0;
int ret;
u8 config;
ret = strict_strtoul(buf, 10, &data);
if (ret)
return -EINVAL;
ret = adt75_i2c_read(dev_info, ADT75_CONFIG, &chip->config);
if (ret)
return -EIO;
config = chip->config & ~ADT75_ONESHOT;
if (data)
config |= ADT75_ONESHOT;
ret = adt75_i2c_write(dev_info, ADT75_CONFIG, config);
if (ret)
return -EIO;
chip->config = config;
return ret;
}
static ssize_t adt75_show_value(struct device *dev,
struct device_attribute *attr,
char *buf)
{
struct iio_dev *dev_info = dev_get_drvdata(dev);
struct adt75_chip_info *chip = iio_priv(dev_info);
u16 data;
char sign = ' ';
int ret;
if (chip->config & ADT75_PD) {
dev_err(dev, "Can't read value in power-down mode.\n");
return -EIO;
}
if (chip->config & ADT75_ONESHOT) {
ret = i2c_smbus_write_byte(chip->client, ADT75_ONESHOT);
if (ret)
return -EIO;
}
ret = adt75_i2c_read(dev_info, ADT75_TEMPERATURE, (u8 *)&data);
if (ret)
return -EIO;
data = swab16(data) >> ADT75_VALUE_OFFSET;
if (data & ADT75_VALUE_SIGN) {
data = (ADT75_VALUE_SIGN << 1) - data;
sign = '-';
}
return sprintf(buf, "%c%d.%.4d\n", sign,
(data >> ADT75_VALUE_FLOAT_OFFSET),
(data & ADT75_VALUE_FLOAT_MASK) * 625);
}
static irqreturn_t adt75_event_handler(int irq, void *private)
{
iio_push_event(private, 0,
IIO_EVENT_CODE_ADT75_OTI,
iio_get_time_ns());
return IRQ_HANDLED;
}
static ssize_t adt75_show_oti_mode(struct device *dev,
struct device_attribute *attr,
char *buf)
{
struct iio_dev *dev_info = dev_get_drvdata(dev);
struct adt75_chip_info *chip = iio_priv(dev_info);
int ret;
ret = adt75_i2c_read(dev_info, ADT75_CONFIG, &chip->config);
if (ret)
return -EIO;
if (chip->config & ADT75_OS_INT)
return sprintf(buf, "interrupt\n");
else
return sprintf(buf, "comparator\n");
}
static ssize_t adt75_set_oti_mode(struct device *dev,
struct device_attribute *attr,
const char *buf,
size_t len)
{
struct iio_dev *dev_info = dev_get_drvdata(dev);
struct adt75_chip_info *chip = iio_priv(dev_info);
int ret;
u8 config;
ret = adt75_i2c_read(dev_info, ADT75_CONFIG, &chip->config);
if (ret)
return -EIO;
config = chip->config & ~ADT75_OS_INT;
if (strcmp(buf, "comparator") != 0)
config |= ADT75_OS_INT;
ret = adt75_i2c_write(dev_info, ADT75_CONFIG, config);
if (ret)
return -EIO;
chip->config = config;
return ret;
}
static ssize_t adt75_show_available_oti_modes(struct device *dev,
struct device_attribute *attr,
char *buf)
{
return sprintf(buf, "comparator\ninterrupt\n");
}
static ssize_t adt75_show_smbus_alart(struct device *dev,
struct device_attribute *attr,
char *buf)
{
struct iio_dev *dev_info = dev_get_drvdata(dev);
struct adt75_chip_info *chip = iio_priv(dev_info);
int ret;
ret = adt75_i2c_read(dev_info, ADT75_CONFIG, &chip->config);
if (ret)
return -EIO;
return sprintf(buf, "%d\n", !!(chip->config & ADT75_SMBUS_ALART));
}
static ssize_t adt75_set_smbus_alart(struct device *dev,
struct device_attribute *attr,
const char *buf,
size_t len)
{
struct iio_dev *dev_info = dev_get_drvdata(dev);
struct adt75_chip_info *chip = iio_priv(dev_info);
unsigned long data = 0;
int ret;
u8 config;
ret = strict_strtoul(buf, 10, &data);
if (ret)
return -EINVAL;
ret = adt75_i2c_read(dev_info, ADT75_CONFIG, &chip->config);
if (ret)
return -EIO;
config = chip->config & ~ADT75_SMBUS_ALART;
if (data)
config |= ADT75_SMBUS_ALART;
ret = adt75_i2c_write(dev_info, ADT75_CONFIG, config);
if (ret)
return -EIO;
chip->config = config;
return ret;
}
static ssize_t adt75_show_fault_queue(struct device *dev,
struct device_attribute *attr,
char *buf)
{
struct iio_dev *dev_info = dev_get_drvdata(dev);
struct adt75_chip_info *chip = iio_priv(dev_info);
int ret;
ret = adt75_i2c_read(dev_info, ADT75_CONFIG, &chip->config);
if (ret)
return -EIO;
return sprintf(buf, "%d\n", (chip->config & ADT75_FAULT_QUEUE_MASK) >>
ADT75_FAULT_QUEUE_OFFSET);
}
static ssize_t adt75_set_fault_queue(struct device *dev,
struct device_attribute *attr,
const char *buf,
size_t len)
{
struct iio_dev *dev_info = dev_get_drvdata(dev);
struct adt75_chip_info *chip = iio_priv(dev_info);
unsigned long data;
int ret;
u8 config;
ret = strict_strtoul(buf, 10, &data);
if (ret || data > 3)
return -EINVAL;
ret = adt75_i2c_read(dev_info, ADT75_CONFIG, &chip->config);
if (ret)
return -EIO;
config = chip->config & ~ADT75_FAULT_QUEUE_MASK;
config |= (data << ADT75_FAULT_QUEUE_OFFSET);
ret = adt75_i2c_write(dev_info, ADT75_CONFIG, config);
if (ret)
return -EIO;
chip->config = config;
return ret;
}
static inline ssize_t adt75_show_t_bound(struct device *dev,
struct device_attribute *attr,
char *buf)
{
struct iio_dev_attr *this_attr = to_iio_dev_attr(attr);
struct iio_dev *dev_info = dev_get_drvdata(dev);
u16 data;
char sign = ' ';
int ret;
ret = adt75_i2c_read(dev_info, this_attr->address, (u8 *)&data);
if (ret)
return -EIO;
data = swab16(data) >> ADT75_VALUE_OFFSET;
if (data & ADT75_VALUE_SIGN) {
data = (ADT75_VALUE_SIGN << 1) - data;
sign = '-';
}
return sprintf(buf, "%c%d.%.4d\n", sign,
(data >> ADT75_VALUE_FLOAT_OFFSET),
(data & ADT75_VALUE_FLOAT_MASK) * 625);
}
static inline ssize_t adt75_set_t_bound(struct device *dev,
struct device_attribute *attr,
const char *buf,
size_t len)
{
struct iio_dev_attr *this_attr = to_iio_dev_attr(attr);
struct iio_dev *dev_info = dev_get_drvdata(dev);
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
if (len > ADT75_VALUE_FLOAT_OFFSET)
len = ADT75_VALUE_FLOAT_OFFSET;
pos[len] = 0;
ret = strict_strtol(pos, 10, &tmp2);
if (!ret)
tmp2 = (tmp2 / 625) * 625;
}
if (tmp1 < 0)
data = (u16)(-tmp1);
else
data = (u16)tmp1;
data = (data << ADT75_VALUE_FLOAT_OFFSET) | (tmp2 & ADT75_VALUE_FLOAT_MASK);
if (tmp1 < 0)
data = (ADT75_VALUE_SIGN << 1) - data;
data <<= ADT75_VALUE_OFFSET;
data = swab16(data);
ret = adt75_i2c_write(dev_info, this_attr->address, (u8)data);
if (ret)
return -EIO;
return ret;
}
static int __devinit adt75_probe(struct i2c_client *client,
const struct i2c_device_id *id)
{
struct adt75_chip_info *chip;
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
indio_dev->name = id->name;
indio_dev->dev.parent = &client->dev;
indio_dev->info = &adt75_info;
indio_dev->modes = INDIO_DIRECT_MODE;
ret = iio_device_register(indio_dev);
if (ret)
goto error_free_dev;
if (client->irq > 0) {
ret = request_threaded_irq(client->irq,
NULL,
&adt75_event_handler,
IRQF_TRIGGER_LOW,
indio_dev->name,
indio_dev);
if (ret)
goto error_unreg_dev;
ret = adt75_i2c_read(indio_dev, ADT75_CONFIG, &chip->config);
if (ret) {
ret = -EIO;
goto error_unreg_irq;
}
chip->config &= ~ADT75_OS_POLARITY;
ret = adt75_i2c_write(indio_dev, ADT75_CONFIG, chip->config);
if (ret) {
ret = -EIO;
goto error_unreg_irq;
}
}
dev_info(&client->dev, "%s temperature sensor registered.\n",
indio_dev->name);
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
static int __devexit adt75_remove(struct i2c_client *client)
{
struct iio_dev *indio_dev = i2c_get_clientdata(client);
if (client->irq)
free_irq(client->irq, indio_dev);
iio_device_unregister(indio_dev);
iio_free_device(indio_dev);
return 0;
}
static __init int adt75_init(void)
{
return i2c_add_driver(&adt75_driver);
}
static __exit void adt75_exit(void)
{
i2c_del_driver(&adt75_driver);
}
