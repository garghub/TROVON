static int ad7150_i2c_read(struct ad7150_chip_info *chip, u8 reg, u8 *data, int len)
{
struct i2c_client *client = chip->client;
int ret = 0;
ret = i2c_master_send(client, &reg, 1);
if (ret < 0) {
dev_err(&client->dev, "I2C write error\n");
return ret;
}
ret = i2c_master_recv(client, data, len);
if (ret < 0) {
dev_err(&client->dev, "I2C read error\n");
return ret;
}
return ret;
}
static int ad7150_i2c_write(struct ad7150_chip_info *chip, u8 reg, u8 data)
{
struct i2c_client *client = chip->client;
int ret = 0;
u8 tx[2] = {
reg,
data,
};
ret = i2c_master_send(client, tx, 2);
if (ret < 0)
dev_err(&client->dev, "I2C write error\n");
return ret;
}
static ssize_t ad7150_show_conversion_modes(struct device *dev,
struct device_attribute *attr,
char *buf)
{
int i;
int len = 0;
for (i = 0; i < AD7150_MAX_CONV_MODE; i++)
len += sprintf(buf + len, "%s\n", ad7150_conv_mode_table[i].name);
return len;
}
static ssize_t ad7150_show_conversion_mode(struct device *dev,
struct device_attribute *attr,
char *buf)
{
struct iio_dev *dev_info = dev_get_drvdata(dev);
struct ad7150_chip_info *chip = dev_info->dev_data;
return sprintf(buf, "%s\n", chip->conversion_mode);
}
static ssize_t ad7150_store_conversion_mode(struct device *dev,
struct device_attribute *attr,
const char *buf,
size_t len)
{
struct iio_dev *dev_info = dev_get_drvdata(dev);
struct ad7150_chip_info *chip = dev_info->dev_data;
u8 cfg;
int i;
ad7150_i2c_read(chip, AD7150_CFG, &cfg, 1);
for (i = 0; i < AD7150_MAX_CONV_MODE; i++) {
if (strncmp(buf, ad7150_conv_mode_table[i].name,
strlen(ad7150_conv_mode_table[i].name) - 1) == 0) {
chip->conversion_mode = ad7150_conv_mode_table[i].name;
cfg |= 0x18 | ad7150_conv_mode_table[i].reg_cfg;
ad7150_i2c_write(chip, AD7150_CFG, cfg);
return len;
}
}
dev_err(dev, "not supported conversion mode\n");
return -EINVAL;
}
static ssize_t ad7150_show_threshold_modes(struct device *dev,
struct device_attribute *attr,
char *buf)
{
return sprintf(buf, "adaptive\nfixed\n");
}
static ssize_t ad7150_show_ch1_value(struct device *dev,
struct device_attribute *attr,
char *buf)
{
struct iio_dev *dev_info = dev_get_drvdata(dev);
struct ad7150_chip_info *chip = dev_info->dev_data;
u8 data[2];
ad7150_i2c_read(chip, AD7150_CH1_DATA_HIGH, data, 2);
return sprintf(buf, "%d\n", ((int) data[0] << 8) | data[1]);
}
static ssize_t ad7150_show_ch2_value(struct device *dev,
struct device_attribute *attr,
char *buf)
{
struct iio_dev *dev_info = dev_get_drvdata(dev);
struct ad7150_chip_info *chip = dev_info->dev_data;
u8 data[2];
ad7150_i2c_read(chip, AD7150_CH2_DATA_HIGH, data, 2);
return sprintf(buf, "%d\n", ((int) data[0] << 8) | data[1]);
}
static ssize_t ad7150_show_threshold_mode(struct device *dev,
struct device_attribute *attr,
char *buf)
{
struct iio_dev *dev_info = dev_get_drvdata(dev);
struct ad7150_chip_info *chip = dev_info->dev_data;
return sprintf(buf, "%s\n", chip->threshold_mode);
}
static ssize_t ad7150_store_threshold_mode(struct device *dev,
struct device_attribute *attr,
const char *buf,
size_t len)
{
struct iio_dev *dev_info = dev_get_drvdata(dev);
struct ad7150_chip_info *chip = dev_info->dev_data;
u8 cfg;
ad7150_i2c_read(chip, AD7150_CFG, &cfg, 1);
if (strncmp(buf, "fixed", 5) == 0) {
strcpy(chip->threshold_mode, "fixed");
cfg |= AD7150_CFG_FIX;
ad7150_i2c_write(chip, AD7150_CFG, cfg);
return len;
} else if (strncmp(buf, "adaptive", 8) == 0) {
strcpy(chip->threshold_mode, "adaptive");
cfg &= ~AD7150_CFG_FIX;
ad7150_i2c_write(chip, AD7150_CFG, cfg);
return len;
}
dev_err(dev, "not supported threshold mode\n");
return -EINVAL;
}
static ssize_t ad7150_show_ch1_threshold(struct device *dev,
struct device_attribute *attr,
char *buf)
{
struct iio_dev *dev_info = dev_get_drvdata(dev);
struct ad7150_chip_info *chip = dev_info->dev_data;
return sprintf(buf, "%d\n", chip->ch1_threshold);
}
static ssize_t ad7150_store_ch1_threshold(struct device *dev,
struct device_attribute *attr,
const char *buf,
size_t len)
{
struct iio_dev *dev_info = dev_get_drvdata(dev);
struct ad7150_chip_info *chip = dev_info->dev_data;
unsigned long data;
int ret;
ret = strict_strtoul(buf, 10, &data);
if ((!ret) && (data < 0x10000)) {
ad7150_i2c_write(chip, AD7150_CH1_THR_HOLD_H, data >> 8);
ad7150_i2c_write(chip, AD7150_CH1_THR_HOLD_L, data);
chip->ch1_threshold = data;
return len;
}
return -EINVAL;
}
static ssize_t ad7150_show_ch2_threshold(struct device *dev,
struct device_attribute *attr,
char *buf)
{
struct iio_dev *dev_info = dev_get_drvdata(dev);
struct ad7150_chip_info *chip = dev_info->dev_data;
return sprintf(buf, "%d\n", chip->ch2_threshold);
}
static ssize_t ad7150_store_ch2_threshold(struct device *dev,
struct device_attribute *attr,
const char *buf,
size_t len)
{
struct iio_dev *dev_info = dev_get_drvdata(dev);
struct ad7150_chip_info *chip = dev_info->dev_data;
unsigned long data;
int ret;
ret = strict_strtoul(buf, 10, &data);
if ((!ret) && (data < 0x10000)) {
ad7150_i2c_write(chip, AD7150_CH2_THR_HOLD_H, data >> 8);
ad7150_i2c_write(chip, AD7150_CH2_THR_HOLD_L, data);
chip->ch2_threshold = data;
return len;
}
return -EINVAL;
}
static ssize_t ad7150_show_ch1_sensitivity(struct device *dev,
struct device_attribute *attr,
char *buf)
{
struct iio_dev *dev_info = dev_get_drvdata(dev);
struct ad7150_chip_info *chip = dev_info->dev_data;
return sprintf(buf, "%d\n", chip->ch1_sensitivity);
}
static ssize_t ad7150_store_ch1_sensitivity(struct device *dev,
struct device_attribute *attr,
const char *buf,
size_t len)
{
struct iio_dev *dev_info = dev_get_drvdata(dev);
struct ad7150_chip_info *chip = dev_info->dev_data;
unsigned long data;
int ret;
ret = strict_strtoul(buf, 10, &data);
if ((!ret) && (data < 0x100)) {
ad7150_i2c_write(chip, AD7150_CH1_SENSITIVITY, data);
chip->ch1_sensitivity = data;
return len;
}
return -EINVAL;
}
static ssize_t ad7150_show_ch2_sensitivity(struct device *dev,
struct device_attribute *attr,
char *buf)
{
struct iio_dev *dev_info = dev_get_drvdata(dev);
struct ad7150_chip_info *chip = dev_info->dev_data;
return sprintf(buf, "%d\n", chip->ch2_sensitivity);
}
static ssize_t ad7150_store_ch2_sensitivity(struct device *dev,
struct device_attribute *attr,
const char *buf,
size_t len)
{
struct iio_dev *dev_info = dev_get_drvdata(dev);
struct ad7150_chip_info *chip = dev_info->dev_data;
unsigned long data;
int ret;
ret = strict_strtoul(buf, 10, &data);
if ((!ret) && (data < 0x100)) {
ad7150_i2c_write(chip, AD7150_CH2_SENSITIVITY, data);
chip->ch2_sensitivity = data;
return len;
}
return -EINVAL;
}
static ssize_t ad7150_show_ch1_timeout(struct device *dev,
struct device_attribute *attr,
char *buf)
{
struct iio_dev *dev_info = dev_get_drvdata(dev);
struct ad7150_chip_info *chip = dev_info->dev_data;
return sprintf(buf, "%d\n", chip->ch1_timeout);
}
static ssize_t ad7150_store_ch1_timeout(struct device *dev,
struct device_attribute *attr,
const char *buf,
size_t len)
{
struct iio_dev *dev_info = dev_get_drvdata(dev);
struct ad7150_chip_info *chip = dev_info->dev_data;
unsigned long data;
int ret;
ret = strict_strtoul(buf, 10, &data);
if ((!ret) && (data < 0x100)) {
ad7150_i2c_write(chip, AD7150_CH1_TIMEOUT, data);
chip->ch1_timeout = data;
return len;
}
return -EINVAL;
}
static ssize_t ad7150_show_ch2_timeout(struct device *dev,
struct device_attribute *attr,
char *buf)
{
struct iio_dev *dev_info = dev_get_drvdata(dev);
struct ad7150_chip_info *chip = dev_info->dev_data;
return sprintf(buf, "%d\n", chip->ch2_timeout);
}
static ssize_t ad7150_store_ch2_timeout(struct device *dev,
struct device_attribute *attr,
const char *buf,
size_t len)
{
struct iio_dev *dev_info = dev_get_drvdata(dev);
struct ad7150_chip_info *chip = dev_info->dev_data;
unsigned long data;
int ret;
ret = strict_strtoul(buf, 10, &data);
if ((!ret) && (data < 0x100)) {
ad7150_i2c_write(chip, AD7150_CH2_TIMEOUT, data);
chip->ch2_timeout = data;
return len;
}
return -EINVAL;
}
static ssize_t ad7150_show_ch1_setup(struct device *dev,
struct device_attribute *attr,
char *buf)
{
struct iio_dev *dev_info = dev_get_drvdata(dev);
struct ad7150_chip_info *chip = dev_info->dev_data;
return sprintf(buf, "0x%02x\n", chip->ch1_setup);
}
static ssize_t ad7150_store_ch1_setup(struct device *dev,
struct device_attribute *attr,
const char *buf,
size_t len)
{
struct iio_dev *dev_info = dev_get_drvdata(dev);
struct ad7150_chip_info *chip = dev_info->dev_data;
unsigned long data;
int ret;
ret = strict_strtoul(buf, 10, &data);
if ((!ret) && (data < 0x100)) {
ad7150_i2c_write(chip, AD7150_CH1_SETUP, data);
chip->ch1_setup = data;
return len;
}
return -EINVAL;
}
static ssize_t ad7150_show_ch2_setup(struct device *dev,
struct device_attribute *attr,
char *buf)
{
struct iio_dev *dev_info = dev_get_drvdata(dev);
struct ad7150_chip_info *chip = dev_info->dev_data;
return sprintf(buf, "0x%02x\n", chip->ch2_setup);
}
static ssize_t ad7150_store_ch2_setup(struct device *dev,
struct device_attribute *attr,
const char *buf,
size_t len)
{
struct iio_dev *dev_info = dev_get_drvdata(dev);
struct ad7150_chip_info *chip = dev_info->dev_data;
unsigned long data;
int ret;
ret = strict_strtoul(buf, 10, &data);
if ((!ret) && (data < 0x100)) {
ad7150_i2c_write(chip, AD7150_CH2_SETUP, data);
chip->ch2_setup = data;
return len;
}
return -EINVAL;
}
static ssize_t ad7150_show_powerdown_timer(struct device *dev,
struct device_attribute *attr,
char *buf)
{
struct iio_dev *dev_info = dev_get_drvdata(dev);
struct ad7150_chip_info *chip = dev_info->dev_data;
return sprintf(buf, "0x%02x\n", chip->powerdown_timer);
}
static ssize_t ad7150_store_powerdown_timer(struct device *dev,
struct device_attribute *attr,
const char *buf,
size_t len)
{
struct iio_dev *dev_info = dev_get_drvdata(dev);
struct ad7150_chip_info *chip = dev_info->dev_data;
unsigned long data;
int ret;
ret = strict_strtoul(buf, 10, &data);
if ((!ret) && (data < 0x40)) {
chip->powerdown_timer = data;
return len;
}
return -EINVAL;
}
static irqreturn_t ad7150_event_handler(int irq, void *private)
{
struct iio_dev *indio_dev = private;
struct ad7150_chip_info *chip = iio_dev_get_devdata(indio_dev);
u8 int_status;
s64 timestamp = iio_get_time_ns();
ad7150_i2c_read(chip, AD7150_STATUS, &int_status, 1);
if ((int_status & AD7150_STATUS_OUT1) && !(chip->old_state & AD7150_STATUS_OUT1))
iio_push_event(indio_dev, 0,
IIO_UNMOD_EVENT_CODE(IIO_EV_CLASS_IN,
0,
IIO_EV_TYPE_THRESH,
IIO_EV_DIR_RISING),
timestamp);
else if ((!(int_status & AD7150_STATUS_OUT1)) && (chip->old_state & AD7150_STATUS_OUT1))
iio_push_event(indio_dev, 0,
IIO_UNMOD_EVENT_CODE(IIO_EV_CLASS_IN,
0,
IIO_EV_TYPE_THRESH,
IIO_EV_DIR_FALLING),
timestamp);
if ((int_status & AD7150_STATUS_OUT2) && !(chip->old_state & AD7150_STATUS_OUT2))
iio_push_event(indio_dev, 0,
IIO_UNMOD_EVENT_CODE(IIO_EV_CLASS_IN,
1,
IIO_EV_TYPE_THRESH,
IIO_EV_DIR_RISING),
timestamp);
else if ((!(int_status & AD7150_STATUS_OUT2)) && (chip->old_state & AD7150_STATUS_OUT2))
iio_push_event(indio_dev, 0,
IIO_UNMOD_EVENT_CODE(IIO_EV_CLASS_IN,
1,
IIO_EV_TYPE_THRESH,
IIO_EV_DIR_FALLING),
timestamp);
return IRQ_HANDLED;
}
static int __devinit ad7150_probe(struct i2c_client *client,
const struct i2c_device_id *id)
{
int ret = 0, regdone = 0;
struct ad7150_chip_info *chip = kzalloc(sizeof(*chip), GFP_KERNEL);
if (chip == NULL) {
ret = -ENOMEM;
goto error_ret;
}
i2c_set_clientdata(client, chip);
chip->client = client;
chip->indio_dev = iio_allocate_device(0);
if (chip->indio_dev == NULL) {
ret = -ENOMEM;
goto error_free_chip;
}
chip->indio_dev->name = id->name;
chip->indio_dev->dev.parent = &client->dev;
chip->indio_dev->info = &ad7150_info;
chip->indio_dev->dev_data = (void *)(chip);
chip->indio_dev->modes = INDIO_DIRECT_MODE;
ret = iio_device_register(chip->indio_dev);
if (ret)
goto error_free_dev;
regdone = 1;
if (client->irq) {
ret = request_threaded_irq(client->irq,
NULL,
&ad7150_event_handler,
IRQF_TRIGGER_RISING |
IRQF_TRIGGER_FALLING,
"ad7150",
chip->indio_dev);
if (ret)
goto error_free_dev;
}
dev_err(&client->dev, "%s capacitive sensor registered, irq: %d\n", id->name, client->irq);
return 0;
error_free_dev:
if (regdone)
iio_device_unregister(chip->indio_dev);
else
iio_free_device(chip->indio_dev);
error_free_chip:
kfree(chip);
error_ret:
return ret;
}
static int __devexit ad7150_remove(struct i2c_client *client)
{
struct ad7150_chip_info *chip = i2c_get_clientdata(client);
struct iio_dev *indio_dev = chip->indio_dev;
if (client->irq)
free_irq(client->irq, indio_dev);
iio_device_unregister(indio_dev);
kfree(chip);
return 0;
}
static __init int ad7150_init(void)
{
return i2c_add_driver(&ad7150_driver);
}
static __exit void ad7150_exit(void)
{
i2c_del_driver(&ad7150_driver);
}
