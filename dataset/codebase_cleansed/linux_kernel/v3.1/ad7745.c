static int ad774x_i2c_read(struct ad774x_chip_info *chip, u8 reg, u8 *data, int len)
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
return ret;
}
return ret;
}
static int ad774x_i2c_write(struct ad774x_chip_info *chip, u8 reg, u8 data)
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
static ssize_t ad774x_show_conversion_modes(struct device *dev,
struct device_attribute *attr,
char *buf)
{
int i;
int len = 0;
for (i = 0; i < AD774X_MAX_CONV_MODE; i++)
len += sprintf(buf + len, "%s ", ad774x_conv_mode_table[i].name);
len += sprintf(buf + len, "\n");
return len;
}
static ssize_t ad774x_show_conversion_mode(struct device *dev,
struct device_attribute *attr,
char *buf)
{
struct iio_dev *dev_info = dev_get_drvdata(dev);
struct ad774x_chip_info *chip = iio_priv(dev_info);
return sprintf(buf, "%s\n", chip->conversion_mode);
}
static ssize_t ad774x_store_conversion_mode(struct device *dev,
struct device_attribute *attr,
const char *buf,
size_t len)
{
struct iio_dev *dev_info = dev_get_drvdata(dev);
struct ad774x_chip_info *chip = iio_priv(dev_info);
u8 cfg;
int i;
ad774x_i2c_read(chip, AD774X_CFG, &cfg, 1);
for (i = 0; i < AD774X_MAX_CONV_MODE; i++) {
if (strncmp(buf, ad774x_conv_mode_table[i].name,
strlen(ad774x_conv_mode_table[i].name) - 1) == 0) {
chip->conversion_mode = ad774x_conv_mode_table[i].name;
cfg |= 0x18 | ad774x_conv_mode_table[i].reg_cfg;
ad774x_i2c_write(chip, AD774X_CFG, cfg);
return len;
}
}
dev_err(dev, "not supported conversion mode\n");
return -EINVAL;
}
static ssize_t ad774x_show_dac_value(struct device *dev,
struct device_attribute *attr,
char *buf)
{
struct iio_dev *dev_info = dev_get_drvdata(dev);
struct ad774x_chip_info *chip = iio_priv(dev_info);
struct iio_dev_attr *this_attr = to_iio_dev_attr(attr);
u8 data;
ad774x_i2c_read(chip, this_attr->address, &data, 1);
return sprintf(buf, "%02x\n", data & 0x7F);
}
static ssize_t ad774x_store_dac_value(struct device *dev,
struct device_attribute *attr,
const char *buf,
size_t len)
{
struct iio_dev *dev_info = dev_get_drvdata(dev);
struct ad774x_chip_info *chip = iio_priv(dev_info);
struct iio_dev_attr *this_attr = to_iio_dev_attr(attr);
unsigned long data;
int ret;
ret = strict_strtoul(buf, 10, &data);
if (!ret) {
ad774x_i2c_write(chip, this_attr->address,
(data ? AD774X_CAPDAC_EN : 0) | (data & 0x7F));
return len;
}
return -EINVAL;
}
static ssize_t ad774x_show_cap_setup(struct device *dev,
struct device_attribute *attr,
char *buf)
{
struct iio_dev *dev_info = dev_get_drvdata(dev);
struct ad774x_chip_info *chip = iio_priv(dev_info);
return sprintf(buf, "0x%02x\n", chip->cap_setup);
}
static ssize_t ad774x_store_cap_setup(struct device *dev,
struct device_attribute *attr,
const char *buf,
size_t len)
{
struct iio_dev *dev_info = dev_get_drvdata(dev);
struct ad774x_chip_info *chip = iio_priv(dev_info);
unsigned long data;
int ret;
ret = strict_strtoul(buf, 10, &data);
if ((!ret) && (data < 0x100)) {
ad774x_i2c_write(chip, AD774X_CAP_SETUP, data);
chip->cap_setup = data;
return len;
}
return -EINVAL;
}
static ssize_t ad774x_show_vt_setup(struct device *dev,
struct device_attribute *attr,
char *buf)
{
struct iio_dev *dev_info = dev_get_drvdata(dev);
struct ad774x_chip_info *chip = iio_priv(dev_info);
return sprintf(buf, "0x%02x\n", chip->vt_setup);
}
static ssize_t ad774x_store_vt_setup(struct device *dev,
struct device_attribute *attr,
const char *buf,
size_t len)
{
struct iio_dev *dev_info = dev_get_drvdata(dev);
struct ad774x_chip_info *chip = iio_priv(dev_info);
unsigned long data;
int ret;
ret = strict_strtoul(buf, 10, &data);
if ((!ret) && (data < 0x100)) {
ad774x_i2c_write(chip, AD774X_VT_SETUP, data);
chip->vt_setup = data;
return len;
}
return -EINVAL;
}
static ssize_t ad774x_show_exec_setup(struct device *dev,
struct device_attribute *attr,
char *buf)
{
struct iio_dev *dev_info = dev_get_drvdata(dev);
struct ad774x_chip_info *chip = iio_priv(dev_info);
return sprintf(buf, "0x%02x\n", chip->exec_setup);
}
static ssize_t ad774x_store_exec_setup(struct device *dev,
struct device_attribute *attr,
const char *buf,
size_t len)
{
struct iio_dev *dev_info = dev_get_drvdata(dev);
struct ad774x_chip_info *chip = iio_priv(dev_info);
unsigned long data;
int ret;
ret = strict_strtoul(buf, 10, &data);
if ((!ret) && (data < 0x100)) {
ad774x_i2c_write(chip, AD774X_EXEC_SETUP, data);
chip->exec_setup = data;
return len;
}
return -EINVAL;
}
static ssize_t ad774x_show_volt_gain(struct device *dev,
struct device_attribute *attr,
char *buf)
{
struct iio_dev *dev_info = dev_get_drvdata(dev);
struct ad774x_chip_info *chip = iio_priv(dev_info);
return sprintf(buf, "%d\n", chip->volt_gain);
}
static ssize_t ad774x_store_volt_gain(struct device *dev,
struct device_attribute *attr,
const char *buf,
size_t len)
{
struct iio_dev *dev_info = dev_get_drvdata(dev);
struct ad774x_chip_info *chip = iio_priv(dev_info);
unsigned long data;
int ret;
ret = strict_strtoul(buf, 10, &data);
if ((!ret) && (data < 0x10000)) {
ad774x_i2c_write(chip, AD774X_VOLT_GAINH, data >> 8);
ad774x_i2c_write(chip, AD774X_VOLT_GAINL, data);
chip->volt_gain = data;
return len;
}
return -EINVAL;
}
static ssize_t ad774x_show_cap_data(struct device *dev,
struct device_attribute *attr,
char *buf)
{
struct iio_dev *dev_info = dev_get_drvdata(dev);
struct ad774x_chip_info *chip = iio_priv(dev_info);
unsigned long data;
char tmp[3];
ad774x_i2c_read(chip, AD774X_CAP_DATA_HIGH, tmp, 3);
data = ((int)tmp[0] << 16) | ((int)tmp[1] << 8) | (int)tmp[2];
return sprintf(buf, "%ld\n", data);
}
static ssize_t ad774x_show_vt_data(struct device *dev,
struct device_attribute *attr,
char *buf)
{
struct iio_dev *dev_info = dev_get_drvdata(dev);
struct ad774x_chip_info *chip = iio_priv(dev_info);
unsigned long data;
char tmp[3];
ad774x_i2c_read(chip, AD774X_VT_DATA_HIGH, tmp, 3);
data = ((int)tmp[0] << 16) | ((int)tmp[1] << 8) | (int)tmp[2];
return sprintf(buf, "%ld\n", data);
}
static ssize_t ad774x_show_cap_offs(struct device *dev,
struct device_attribute *attr,
char *buf)
{
struct iio_dev *dev_info = dev_get_drvdata(dev);
struct ad774x_chip_info *chip = iio_priv(dev_info);
return sprintf(buf, "%d\n", chip->cap_offs);
}
static ssize_t ad774x_store_cap_offs(struct device *dev,
struct device_attribute *attr,
const char *buf,
size_t len)
{
struct iio_dev *dev_info = dev_get_drvdata(dev);
struct ad774x_chip_info *chip = iio_priv(dev_info);
unsigned long data;
int ret;
ret = strict_strtoul(buf, 10, &data);
if ((!ret) && (data < 0x10000)) {
ad774x_i2c_write(chip, AD774X_CAP_OFFH, data >> 8);
ad774x_i2c_write(chip, AD774X_CAP_OFFL, data);
chip->cap_offs = data;
return len;
}
return -EINVAL;
}
static ssize_t ad774x_show_cap_gain(struct device *dev,
struct device_attribute *attr,
char *buf)
{
struct iio_dev *dev_info = dev_get_drvdata(dev);
struct ad774x_chip_info *chip = iio_priv(dev_info);
return sprintf(buf, "%d\n", chip->cap_gain);
}
static ssize_t ad774x_store_cap_gain(struct device *dev,
struct device_attribute *attr,
const char *buf,
size_t len)
{
struct iio_dev *dev_info = dev_get_drvdata(dev);
struct ad774x_chip_info *chip = iio_priv(dev_info);
unsigned long data;
int ret;
ret = strict_strtoul(buf, 10, &data);
if ((!ret) && (data < 0x10000)) {
ad774x_i2c_write(chip, AD774X_CAP_GAINH, data >> 8);
ad774x_i2c_write(chip, AD774X_CAP_GAINL, data);
chip->cap_gain = data;
return len;
}
return -EINVAL;
}
static irqreturn_t ad774x_event_handler(int irq, void *private)
{
struct iio_dev *indio_dev = private;
struct ad774x_chip_info *chip = iio_priv(indio_dev);
u8 int_status;
ad774x_i2c_read(chip, AD774X_STATUS, &int_status, 1);
if (int_status & AD774X_STATUS_RDYCAP)
iio_push_event(indio_dev, 0,
IIO_EVENT_CODE_CAP_RDY,
iio_get_time_ns());
if (int_status & AD774X_STATUS_RDYVT)
iio_push_event(indio_dev, 0,
IIO_EVENT_CODE_VT_RDY,
iio_get_time_ns());
return IRQ_HANDLED;
}
static int __devinit ad774x_probe(struct i2c_client *client,
const struct i2c_device_id *id)
{
int ret = 0, regdone = 0;
struct ad774x_chip_info *chip;
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
indio_dev->info = &ad774x_info;
indio_dev->modes = INDIO_DIRECT_MODE;
ret = iio_device_register(indio_dev);
if (ret)
goto error_free_dev;
regdone = 1;
if (client->irq) {
ret = request_threaded_irq(client->irq,
NULL,
&ad774x_event_handler,
IRQF_TRIGGER_FALLING,
"ad774x",
indio_dev);
if (ret)
goto error_free_dev;
}
dev_err(&client->dev, "%s capacitive sensor registered, irq: %d\n", id->name, client->irq);
return 0;
error_free_dev:
if (regdone)
free_irq(client->irq, indio_dev);
else
iio_free_device(indio_dev);
error_ret:
return ret;
}
static int __devexit ad774x_remove(struct i2c_client *client)
{
struct iio_dev *indio_dev = i2c_get_clientdata(client);
if (client->irq)
free_irq(client->irq, indio_dev);
iio_device_unregister(indio_dev);
return 0;
}
static __init int ad774x_init(void)
{
return i2c_add_driver(&ad774x_driver);
}
static __exit void ad774x_exit(void)
{
i2c_del_driver(&ad774x_driver);
}
