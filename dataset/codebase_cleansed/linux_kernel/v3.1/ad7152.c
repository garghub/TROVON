static int ad7152_i2c_read(struct ad7152_chip_info *chip, u8 reg, u8 *data, int len)
{
struct i2c_client *client = chip->client;
int ret;
ret = i2c_master_send(client, &reg, 1);
if (ret < 0) {
dev_err(&client->dev, "I2C write error\n");
return ret;
}
ret = i2c_master_recv(client, data, len);
if (ret < 0) {
dev_err(&client->dev, "I2C read error\n");
}
return ret;
}
static int ad7152_i2c_write(struct ad7152_chip_info *chip, u8 reg, u8 data)
{
struct i2c_client *client = chip->client;
int ret;
u8 tx[2] = {
reg,
data,
};
ret = i2c_master_send(client, tx, 2);
if (ret < 0)
dev_err(&client->dev, "I2C write error\n");
return ret;
}
static ssize_t ad7152_show_conversion_modes(struct device *dev,
struct device_attribute *attr,
char *buf)
{
int i;
int len = 0;
for (i = 0; i < AD7152_MAX_CONV_MODE; i++)
len += sprintf(buf + len, "%s ", ad7152_conv_mode_table[i].name);
len += sprintf(buf + len, "\n");
return len;
}
static ssize_t ad7152_show_ch1_value(struct device *dev,
struct device_attribute *attr,
char *buf)
{
struct iio_dev *dev_info = dev_get_drvdata(dev);
struct ad7152_chip_info *chip = iio_priv(dev_info);
u8 data[2];
ad7152_i2c_read(chip, AD7152_CH1_DATA_HIGH, data, 2);
return sprintf(buf, "%d\n", ((int)data[0] << 8) | data[1]);
}
static ssize_t ad7152_show_ch2_value(struct device *dev,
struct device_attribute *attr,
char *buf)
{
struct iio_dev *dev_info = dev_get_drvdata(dev);
struct ad7152_chip_info *chip = iio_priv(dev_info);
u8 data[2];
ad7152_i2c_read(chip, AD7152_CH2_DATA_HIGH, data, 2);
return sprintf(buf, "%d\n", ((int)data[0] << 8) | data[1]);
}
static ssize_t ad7152_show_conversion_mode(struct device *dev,
struct device_attribute *attr,
char *buf)
{
struct iio_dev *dev_info = dev_get_drvdata(dev);
struct ad7152_chip_info *chip = iio_priv(dev_info);
return sprintf(buf, "%s\n", chip->conversion_mode);
}
static ssize_t ad7152_store_conversion_mode(struct device *dev,
struct device_attribute *attr,
const char *buf,
size_t len)
{
struct iio_dev *dev_info = dev_get_drvdata(dev);
struct ad7152_chip_info *chip = iio_priv(dev_info);
u8 cfg;
int i;
ad7152_i2c_read(chip, AD7152_CFG, &cfg, 1);
for (i = 0; i < AD7152_MAX_CONV_MODE; i++)
if (strncmp(buf, ad7152_conv_mode_table[i].name,
strlen(ad7152_conv_mode_table[i].name) - 1) == 0) {
chip->conversion_mode = ad7152_conv_mode_table[i].name;
cfg |= 0x18 | ad7152_conv_mode_table[i].reg_cfg;
ad7152_i2c_write(chip, AD7152_CFG, cfg);
return len;
}
dev_err(dev, "not supported conversion mode\n");
return -EINVAL;
}
static ssize_t ad7152_show_ch1_offset(struct device *dev,
struct device_attribute *attr,
char *buf)
{
struct iio_dev *dev_info = dev_get_drvdata(dev);
struct ad7152_chip_info *chip = iio_priv(dev_info);
return sprintf(buf, "%d\n", chip->ch1_offset);
}
static ssize_t ad7152_store_ch1_offset(struct device *dev,
struct device_attribute *attr,
const char *buf,
size_t len)
{
struct iio_dev *dev_info = dev_get_drvdata(dev);
struct ad7152_chip_info *chip = iio_priv(dev_info);
unsigned long data;
int ret;
ret = strict_strtoul(buf, 10, &data);
if ((!ret) && (data < 0x10000)) {
ad7152_i2c_write(chip, AD7152_CH1_OFFS_HIGH, data >> 8);
ad7152_i2c_write(chip, AD7152_CH1_OFFS_LOW, data);
chip->ch1_offset = data;
return len;
}
return -EINVAL;
}
static ssize_t ad7152_show_ch2_offset(struct device *dev,
struct device_attribute *attr,
char *buf)
{
struct iio_dev *dev_info = dev_get_drvdata(dev);
struct ad7152_chip_info *chip = iio_priv(dev_info);
return sprintf(buf, "%d\n", chip->ch2_offset);
}
static ssize_t ad7152_store_ch2_offset(struct device *dev,
struct device_attribute *attr,
const char *buf,
size_t len)
{
struct iio_dev *dev_info = dev_get_drvdata(dev);
struct ad7152_chip_info *chip = iio_priv(dev_info);
unsigned long data;
int ret;
ret = strict_strtoul(buf, 10, &data);
if ((!ret) && (data < 0x10000)) {
ad7152_i2c_write(chip, AD7152_CH2_OFFS_HIGH, data >> 8);
ad7152_i2c_write(chip, AD7152_CH2_OFFS_LOW, data);
chip->ch2_offset = data;
return len;
}
return -EINVAL;
}
static ssize_t ad7152_show_ch1_gain(struct device *dev,
struct device_attribute *attr,
char *buf)
{
struct iio_dev *dev_info = dev_get_drvdata(dev);
struct ad7152_chip_info *chip = iio_priv(dev_info);
return sprintf(buf, "%d\n", chip->ch1_gain);
}
static ssize_t ad7152_store_ch1_gain(struct device *dev,
struct device_attribute *attr,
const char *buf,
size_t len)
{
struct iio_dev *dev_info = dev_get_drvdata(dev);
struct ad7152_chip_info *chip = iio_priv(dev_info);
unsigned long data;
int ret;
ret = strict_strtoul(buf, 10, &data);
if ((!ret) && (data < 0x10000)) {
ad7152_i2c_write(chip, AD7152_CH1_GAIN_HIGH, data >> 8);
ad7152_i2c_write(chip, AD7152_CH1_GAIN_LOW, data);
chip->ch1_gain = data;
return len;
}
return -EINVAL;
}
static ssize_t ad7152_show_ch2_gain(struct device *dev,
struct device_attribute *attr,
char *buf)
{
struct iio_dev *dev_info = dev_get_drvdata(dev);
struct ad7152_chip_info *chip = iio_priv(dev_info);
return sprintf(buf, "%d\n", chip->ch2_gain);
}
static ssize_t ad7152_store_ch2_gain(struct device *dev,
struct device_attribute *attr,
const char *buf,
size_t len)
{
struct iio_dev *dev_info = dev_get_drvdata(dev);
struct ad7152_chip_info *chip = iio_priv(dev_info);
unsigned long data;
int ret;
ret = strict_strtoul(buf, 10, &data);
if ((!ret) && (data < 0x10000)) {
ad7152_i2c_write(chip, AD7152_CH2_GAIN_HIGH, data >> 8);
ad7152_i2c_write(chip, AD7152_CH2_GAIN_LOW, data);
chip->ch2_gain = data;
return len;
}
return -EINVAL;
}
static ssize_t ad7152_show_ch1_setup(struct device *dev,
struct device_attribute *attr,
char *buf)
{
struct iio_dev *dev_info = dev_get_drvdata(dev);
struct ad7152_chip_info *chip = iio_priv(dev_info);
return sprintf(buf, "0x%02x\n", chip->ch1_setup);
}
static ssize_t ad7152_store_ch1_setup(struct device *dev,
struct device_attribute *attr,
const char *buf,
size_t len)
{
struct iio_dev *dev_info = dev_get_drvdata(dev);
struct ad7152_chip_info *chip = iio_priv(dev_info);
unsigned long data;
int ret;
ret = strict_strtoul(buf, 10, &data);
if ((!ret) && (data < 0x100)) {
ad7152_i2c_write(chip, AD7152_CH1_SETUP, data);
chip->ch1_setup = data;
return len;
}
return -EINVAL;
}
static ssize_t ad7152_show_ch2_setup(struct device *dev,
struct device_attribute *attr,
char *buf)
{
struct iio_dev *dev_info = dev_get_drvdata(dev);
struct ad7152_chip_info *chip = iio_priv(dev_info);
return sprintf(buf, "0x%02x\n", chip->ch2_setup);
}
static ssize_t ad7152_store_ch2_setup(struct device *dev,
struct device_attribute *attr,
const char *buf,
size_t len)
{
struct iio_dev *dev_info = dev_get_drvdata(dev);
struct ad7152_chip_info *chip = iio_priv(dev_info);
unsigned long data;
int ret;
ret = strict_strtoul(buf, 10, &data);
if ((!ret) && (data < 0x100)) {
ad7152_i2c_write(chip, AD7152_CH2_SETUP, data);
chip->ch2_setup = data;
return len;
}
return -EINVAL;
}
static ssize_t ad7152_show_filter_rate_setup(struct device *dev,
struct device_attribute *attr,
char *buf)
{
struct iio_dev *dev_info = dev_get_drvdata(dev);
struct ad7152_chip_info *chip = iio_priv(dev_info);
return sprintf(buf, "0x%02x\n", chip->filter_rate_setup);
}
static ssize_t ad7152_store_filter_rate_setup(struct device *dev,
struct device_attribute *attr,
const char *buf,
size_t len)
{
struct iio_dev *dev_info = dev_get_drvdata(dev);
struct ad7152_chip_info *chip = iio_priv(dev_info);
unsigned long data;
int ret;
ret = strict_strtoul(buf, 10, &data);
if ((!ret) && (data < 0x100)) {
ad7152_i2c_write(chip, AD7152_CFG2, data);
chip->filter_rate_setup = data;
return len;
}
return -EINVAL;
}
static int __devinit ad7152_probe(struct i2c_client *client,
const struct i2c_device_id *id)
{
int ret = 0;
struct ad7152_chip_info *chip;
struct iio_dev *indio_dev;
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
indio_dev->info = &ad7152_info;
indio_dev->modes = INDIO_DIRECT_MODE;
ret = iio_device_register(indio_dev);
if (ret)
goto error_free_dev;
dev_err(&client->dev, "%s capacitive sensor registered\n", id->name);
return 0;
error_free_dev:
iio_free_device(indio_dev);
error_ret:
return ret;
}
static int __devexit ad7152_remove(struct i2c_client *client)
{
struct iio_dev *indio_dev = i2c_get_clientdata(client);
iio_device_unregister(indio_dev);
return 0;
}
static __init int ad7152_init(void)
{
return i2c_add_driver(&ad7152_driver);
}
static __exit void ad7152_exit(void)
{
i2c_del_driver(&ad7152_driver);
}
