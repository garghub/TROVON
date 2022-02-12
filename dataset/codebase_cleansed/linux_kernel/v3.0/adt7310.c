static int adt7310_spi_read_word(struct adt7310_chip_info *chip, u8 reg, u16 *data)
{
struct spi_device *spi_dev = chip->spi_dev;
u8 command = (reg << ADT7310_CMD_REG_OFFSET) & ADT7310_CMD_REG_MASK;
int ret = 0;
command |= ADT7310_CMD_READ;
ret = spi_write(spi_dev, &command, sizeof(command));
if (ret < 0) {
dev_err(&spi_dev->dev, "SPI write command error\n");
return ret;
}
ret = spi_read(spi_dev, (u8 *)data, sizeof(*data));
if (ret < 0) {
dev_err(&spi_dev->dev, "SPI read word error\n");
return ret;
}
*data = be16_to_cpu(*data);
return 0;
}
static int adt7310_spi_write_word(struct adt7310_chip_info *chip, u8 reg, u16 data)
{
struct spi_device *spi_dev = chip->spi_dev;
u8 buf[3];
int ret = 0;
buf[0] = (reg << ADT7310_CMD_REG_OFFSET) & ADT7310_CMD_REG_MASK;
buf[1] = (u8)(data >> 8);
buf[2] = (u8)(data & 0xFF);
ret = spi_write(spi_dev, buf, 3);
if (ret < 0) {
dev_err(&spi_dev->dev, "SPI write word error\n");
return ret;
}
return ret;
}
static int adt7310_spi_read_byte(struct adt7310_chip_info *chip, u8 reg, u8 *data)
{
struct spi_device *spi_dev = chip->spi_dev;
u8 command = (reg << ADT7310_CMD_REG_OFFSET) & ADT7310_CMD_REG_MASK;
int ret = 0;
command |= ADT7310_CMD_READ;
ret = spi_write(spi_dev, &command, sizeof(command));
if (ret < 0) {
dev_err(&spi_dev->dev, "SPI write command error\n");
return ret;
}
ret = spi_read(spi_dev, data, sizeof(*data));
if (ret < 0) {
dev_err(&spi_dev->dev, "SPI read byte error\n");
return ret;
}
return 0;
}
static int adt7310_spi_write_byte(struct adt7310_chip_info *chip, u8 reg, u8 data)
{
struct spi_device *spi_dev = chip->spi_dev;
u8 buf[2];
int ret = 0;
buf[0] = (reg << ADT7310_CMD_REG_OFFSET) & ADT7310_CMD_REG_MASK;
buf[1] = data;
ret = spi_write(spi_dev, buf, 2);
if (ret < 0) {
dev_err(&spi_dev->dev, "SPI write byte error\n");
return ret;
}
return ret;
}
static ssize_t adt7310_show_mode(struct device *dev,
struct device_attribute *attr,
char *buf)
{
struct iio_dev *dev_info = dev_get_drvdata(dev);
struct adt7310_chip_info *chip = dev_info->dev_data;
u8 config;
config = chip->config & ADT7310_MODE_MASK;
switch (config) {
case ADT7310_PD:
return sprintf(buf, "power-down\n");
case ADT7310_ONESHOT:
return sprintf(buf, "one-shot\n");
case ADT7310_SPS:
return sprintf(buf, "sps\n");
default:
return sprintf(buf, "full\n");
}
}
static ssize_t adt7310_store_mode(struct device *dev,
struct device_attribute *attr,
const char *buf,
size_t len)
{
struct iio_dev *dev_info = dev_get_drvdata(dev);
struct adt7310_chip_info *chip = dev_info->dev_data;
u16 config;
int ret;
ret = adt7310_spi_read_byte(chip, ADT7310_CONFIG, &chip->config);
if (ret)
return -EIO;
config = chip->config & (~ADT7310_MODE_MASK);
if (strcmp(buf, "power-down"))
config |= ADT7310_PD;
else if (strcmp(buf, "one-shot"))
config |= ADT7310_ONESHOT;
else if (strcmp(buf, "sps"))
config |= ADT7310_SPS;
ret = adt7310_spi_write_byte(chip, ADT7310_CONFIG, config);
if (ret)
return -EIO;
chip->config = config;
return len;
}
static ssize_t adt7310_show_available_modes(struct device *dev,
struct device_attribute *attr,
char *buf)
{
return sprintf(buf, "full\none-shot\nsps\npower-down\n");
}
static ssize_t adt7310_show_resolution(struct device *dev,
struct device_attribute *attr,
char *buf)
{
struct iio_dev *dev_info = dev_get_drvdata(dev);
struct adt7310_chip_info *chip = dev_info->dev_data;
int ret;
int bits;
ret = adt7310_spi_read_byte(chip, ADT7310_CONFIG, &chip->config);
if (ret)
return -EIO;
if (chip->config & ADT7310_RESOLUTION)
bits = 16;
else
bits = 13;
return sprintf(buf, "%d bits\n", bits);
}
static ssize_t adt7310_store_resolution(struct device *dev,
struct device_attribute *attr,
const char *buf,
size_t len)
{
struct iio_dev *dev_info = dev_get_drvdata(dev);
struct adt7310_chip_info *chip = dev_info->dev_data;
unsigned long data;
u16 config;
int ret;
ret = strict_strtoul(buf, 10, &data);
if (ret)
return -EINVAL;
ret = adt7310_spi_read_byte(chip, ADT7310_CONFIG, &chip->config);
if (ret)
return -EIO;
config = chip->config & (~ADT7310_RESOLUTION);
if (data)
config |= ADT7310_RESOLUTION;
ret = adt7310_spi_write_byte(chip, ADT7310_CONFIG, config);
if (ret)
return -EIO;
chip->config = config;
return len;
}
static ssize_t adt7310_show_id(struct device *dev,
struct device_attribute *attr,
char *buf)
{
struct iio_dev *dev_info = dev_get_drvdata(dev);
struct adt7310_chip_info *chip = dev_info->dev_data;
u8 id;
int ret;
ret = adt7310_spi_read_byte(chip, ADT7310_ID, &id);
if (ret)
return -EIO;
return sprintf(buf, "device id: 0x%x\nmanufactory id: 0x%x\n",
id & ADT7310_DEVICE_ID_MASK,
(id & ADT7310_MANUFACTORY_ID_MASK) >> ADT7310_MANUFACTORY_ID_OFFSET);
}
static ssize_t adt7310_convert_temperature(struct adt7310_chip_info *chip,
u16 data, char *buf)
{
char sign = ' ';
if (chip->config & ADT7310_RESOLUTION) {
if (data & ADT7310_T16_VALUE_SIGN) {
data = (u16)((ADT7310_T16_VALUE_SIGN << 1) - (u32)data);
sign = '-';
}
return sprintf(buf, "%c%d.%.7d\n", sign,
(data >> ADT7310_T16_VALUE_FLOAT_OFFSET),
(data & ADT7310_T16_VALUE_FLOAT_MASK) * 78125);
} else {
if (data & ADT7310_T13_VALUE_SIGN) {
data >>= ADT7310_T13_VALUE_OFFSET;
data = (ADT7310_T13_VALUE_SIGN << 1) - data;
sign = '-';
}
return sprintf(buf, "%c%d.%.4d\n", sign,
(data >> ADT7310_T13_VALUE_FLOAT_OFFSET),
(data & ADT7310_T13_VALUE_FLOAT_MASK) * 625);
}
}
static ssize_t adt7310_show_value(struct device *dev,
struct device_attribute *attr,
char *buf)
{
struct iio_dev *dev_info = dev_get_drvdata(dev);
struct adt7310_chip_info *chip = dev_info->dev_data;
u8 status;
u16 data;
int ret, i = 0;
do {
ret = adt7310_spi_read_byte(chip, ADT7310_STATUS, &status);
if (ret)
return -EIO;
i++;
if (i == 10000)
return -EIO;
} while (status & ADT7310_STAT_NOT_RDY);
ret = adt7310_spi_read_word(chip, ADT7310_TEMPERATURE, &data);
if (ret)
return -EIO;
return adt7310_convert_temperature(chip, data, buf);
}
static irqreturn_t adt7310_event_handler(int irq, void *private)
{
struct iio_dev *indio_dev = private;
struct adt7310_chip_info *chip = iio_dev_get_devdata(indio_dev);
s64 timestamp = iio_get_time_ns();
u8 status;
int ret;
ret = adt7310_spi_read_byte(chip, ADT7310_STATUS, &status);
if (ret)
return ret;
if (status & ADT7310_STAT_T_HIGH)
iio_push_event(indio_dev, 0,
IIO_UNMOD_EVENT_CODE(IIO_TEMP, 0,
IIO_EV_TYPE_THRESH,
IIO_EV_DIR_RISING),
timestamp);
if (status & ADT7310_STAT_T_LOW)
iio_push_event(indio_dev, 0,
IIO_UNMOD_EVENT_CODE(IIO_TEMP, 0,
IIO_EV_TYPE_THRESH,
IIO_EV_DIR_FALLING),
timestamp);
if (status & ADT7310_STAT_T_CRIT)
iio_push_event(indio_dev, 0,
IIO_UNMOD_EVENT_CODE(IIO_TEMP, 0,
IIO_EV_TYPE_THRESH,
IIO_EV_DIR_RISING),
timestamp);
return IRQ_HANDLED;
}
static ssize_t adt7310_show_event_mode(struct device *dev,
struct device_attribute *attr,
char *buf)
{
struct iio_dev *dev_info = dev_get_drvdata(dev);
struct adt7310_chip_info *chip = dev_info->dev_data;
int ret;
ret = adt7310_spi_read_byte(chip, ADT7310_CONFIG, &chip->config);
if (ret)
return -EIO;
if (chip->config & ADT7310_EVENT_MODE)
return sprintf(buf, "interrupt\n");
else
return sprintf(buf, "comparator\n");
}
static ssize_t adt7310_set_event_mode(struct device *dev,
struct device_attribute *attr,
const char *buf,
size_t len)
{
struct iio_dev *dev_info = dev_get_drvdata(dev);
struct adt7310_chip_info *chip = dev_info->dev_data;
u16 config;
int ret;
ret = adt7310_spi_read_byte(chip, ADT7310_CONFIG, &chip->config);
if (ret)
return -EIO;
config = chip->config &= ~ADT7310_EVENT_MODE;
if (strcmp(buf, "comparator") != 0)
config |= ADT7310_EVENT_MODE;
ret = adt7310_spi_write_byte(chip, ADT7310_CONFIG, config);
if (ret)
return -EIO;
chip->config = config;
return len;
}
static ssize_t adt7310_show_available_event_modes(struct device *dev,
struct device_attribute *attr,
char *buf)
{
return sprintf(buf, "comparator\ninterrupt\n");
}
static ssize_t adt7310_show_fault_queue(struct device *dev,
struct device_attribute *attr,
char *buf)
{
struct iio_dev *dev_info = dev_get_drvdata(dev);
struct adt7310_chip_info *chip = dev_info->dev_data;
int ret;
ret = adt7310_spi_read_byte(chip, ADT7310_CONFIG, &chip->config);
if (ret)
return -EIO;
return sprintf(buf, "%d\n", chip->config & ADT7310_FAULT_QUEUE_MASK);
}
static ssize_t adt7310_set_fault_queue(struct device *dev,
struct device_attribute *attr,
const char *buf,
size_t len)
{
struct iio_dev *dev_info = dev_get_drvdata(dev);
struct adt7310_chip_info *chip = dev_info->dev_data;
unsigned long data;
int ret;
u8 config;
ret = strict_strtoul(buf, 10, &data);
if (ret || data > 3)
return -EINVAL;
ret = adt7310_spi_read_byte(chip, ADT7310_CONFIG, &chip->config);
if (ret)
return -EIO;
config = chip->config & ~ADT7310_FAULT_QUEUE_MASK;
config |= data;
ret = adt7310_spi_write_byte(chip, ADT7310_CONFIG, config);
if (ret)
return -EIO;
chip->config = config;
return len;
}
static inline ssize_t adt7310_show_t_bound(struct device *dev,
struct device_attribute *attr,
u8 bound_reg,
char *buf)
{
struct iio_dev *dev_info = dev_get_drvdata(dev);
struct adt7310_chip_info *chip = dev_info->dev_data;
u16 data;
int ret;
ret = adt7310_spi_read_word(chip, bound_reg, &data);
if (ret)
return -EIO;
return adt7310_convert_temperature(chip, data, buf);
}
static inline ssize_t adt7310_set_t_bound(struct device *dev,
struct device_attribute *attr,
u8 bound_reg,
const char *buf,
size_t len)
{
struct iio_dev *dev_info = dev_get_drvdata(dev);
struct adt7310_chip_info *chip = dev_info->dev_data;
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
if (chip->config & ADT7310_RESOLUTION) {
if (len > ADT7310_T16_VALUE_FLOAT_OFFSET)
len = ADT7310_T16_VALUE_FLOAT_OFFSET;
pos[len] = 0;
ret = strict_strtol(pos, 10, &tmp2);
if (!ret)
tmp2 = (tmp2 / 78125) * 78125;
} else {
if (len > ADT7310_T13_VALUE_FLOAT_OFFSET)
len = ADT7310_T13_VALUE_FLOAT_OFFSET;
pos[len] = 0;
ret = strict_strtol(pos, 10, &tmp2);
if (!ret)
tmp2 = (tmp2 / 625) * 625;
}
}
if (tmp1 < 0)
data = (u16)(-tmp1);
else
data = (u16)tmp1;
if (chip->config & ADT7310_RESOLUTION) {
data = (data << ADT7310_T16_VALUE_FLOAT_OFFSET) |
(tmp2 & ADT7310_T16_VALUE_FLOAT_MASK);
if (tmp1 < 0)
data = (u16)((ADT7310_T16_VALUE_SIGN << 1) - (u32)data);
} else {
data = (data << ADT7310_T13_VALUE_FLOAT_OFFSET) |
(tmp2 & ADT7310_T13_VALUE_FLOAT_MASK);
if (tmp1 < 0)
data = (ADT7310_T13_VALUE_SIGN << 1) - data;
data <<= ADT7310_T13_VALUE_OFFSET;
}
ret = adt7310_spi_write_word(chip, bound_reg, data);
if (ret)
return -EIO;
return len;
}
static ssize_t adt7310_show_t_alarm_high(struct device *dev,
struct device_attribute *attr,
char *buf)
{
return adt7310_show_t_bound(dev, attr,
ADT7310_T_ALARM_HIGH, buf);
}
static inline ssize_t adt7310_set_t_alarm_high(struct device *dev,
struct device_attribute *attr,
const char *buf,
size_t len)
{
return adt7310_set_t_bound(dev, attr,
ADT7310_T_ALARM_HIGH, buf, len);
}
static ssize_t adt7310_show_t_alarm_low(struct device *dev,
struct device_attribute *attr,
char *buf)
{
return adt7310_show_t_bound(dev, attr,
ADT7310_T_ALARM_LOW, buf);
}
static inline ssize_t adt7310_set_t_alarm_low(struct device *dev,
struct device_attribute *attr,
const char *buf,
size_t len)
{
return adt7310_set_t_bound(dev, attr,
ADT7310_T_ALARM_LOW, buf, len);
}
static ssize_t adt7310_show_t_crit(struct device *dev,
struct device_attribute *attr,
char *buf)
{
return adt7310_show_t_bound(dev, attr,
ADT7310_T_CRIT, buf);
}
static inline ssize_t adt7310_set_t_crit(struct device *dev,
struct device_attribute *attr,
const char *buf,
size_t len)
{
return adt7310_set_t_bound(dev, attr,
ADT7310_T_CRIT, buf, len);
}
static ssize_t adt7310_show_t_hyst(struct device *dev,
struct device_attribute *attr,
char *buf)
{
struct iio_dev *dev_info = dev_get_drvdata(dev);
struct adt7310_chip_info *chip = dev_info->dev_data;
int ret;
u8 t_hyst;
ret = adt7310_spi_read_byte(chip, ADT7310_T_HYST, &t_hyst);
if (ret)
return -EIO;
return sprintf(buf, "%d\n", t_hyst & ADT7310_T_HYST_MASK);
}
static inline ssize_t adt7310_set_t_hyst(struct device *dev,
struct device_attribute *attr,
const char *buf,
size_t len)
{
struct iio_dev *dev_info = dev_get_drvdata(dev);
struct adt7310_chip_info *chip = dev_info->dev_data;
int ret;
unsigned long data;
u8 t_hyst;
ret = strict_strtol(buf, 10, &data);
if (ret || data > ADT7310_T_HYST_MASK)
return -EINVAL;
t_hyst = (u8)data;
ret = adt7310_spi_write_byte(chip, ADT7310_T_HYST, t_hyst);
if (ret)
return -EIO;
return len;
}
static int __devinit adt7310_probe(struct spi_device *spi_dev)
{
struct adt7310_chip_info *chip;
int ret = 0;
unsigned long *adt7310_platform_data = spi_dev->dev.platform_data;
unsigned long irq_flags;
chip = kzalloc(sizeof(struct adt7310_chip_info), GFP_KERNEL);
if (chip == NULL)
return -ENOMEM;
dev_set_drvdata(&spi_dev->dev, chip);
chip->spi_dev = spi_dev;
chip->indio_dev = iio_allocate_device(0);
if (chip->indio_dev == NULL) {
ret = -ENOMEM;
goto error_free_chip;
}
chip->indio_dev->dev.parent = &spi_dev->dev;
chip->indio_dev->name = spi_get_device_id(spi_dev)->name;
chip->indio_dev->info = &adt7310_info;
chip->indio_dev->dev_data = (void *)chip;
chip->indio_dev->modes = INDIO_DIRECT_MODE;
ret = iio_device_register(chip->indio_dev);
if (ret)
goto error_free_dev;
if (spi_dev->irq) {
if (adt7310_platform_data[2])
irq_flags = adt7310_platform_data[2];
else
irq_flags = IRQF_TRIGGER_LOW;
ret = request_threaded_irq(spi_dev->irq,
NULL,
&adt7310_event_handler,
irq_flags,
chip->indio_dev->name,
chip->indio_dev);
if (ret)
goto error_unreg_dev;
}
if (adt7310_platform_data[0]) {
ret = request_threaded_irq(adt7310_platform_data[0],
NULL,
&adt7310_event_handler,
adt7310_platform_data[1],
chip->indio_dev->name,
chip->indio_dev);
if (ret)
goto error_unreg_ct_irq;
}
if (spi_dev->irq && adt7310_platform_data[0]) {
ret = adt7310_spi_read_byte(chip, ADT7310_CONFIG, &chip->config);
if (ret) {
ret = -EIO;
goto error_unreg_int_irq;
}
chip->config &= ~ADT7310_CT_POLARITY;
if (adt7310_platform_data[1] & IRQF_TRIGGER_HIGH)
chip->config |= ADT7310_INT_POLARITY;
else
chip->config &= ~ADT7310_INT_POLARITY;
ret = adt7310_spi_write_byte(chip, ADT7310_CONFIG, chip->config);
if (ret) {
ret = -EIO;
goto error_unreg_int_irq;
}
}
dev_info(&spi_dev->dev, "%s temperature sensor registered.\n",
chip->indio_dev->name);
return 0;
error_unreg_int_irq:
free_irq(adt7310_platform_data[0], chip->indio_dev);
error_unreg_ct_irq:
free_irq(spi_dev->irq, chip->indio_dev);
error_unreg_dev:
iio_device_unregister(chip->indio_dev);
error_free_dev:
iio_free_device(chip->indio_dev);
error_free_chip:
kfree(chip);
return ret;
}
static int __devexit adt7310_remove(struct spi_device *spi_dev)
{
struct adt7310_chip_info *chip = dev_get_drvdata(&spi_dev->dev);
struct iio_dev *indio_dev = chip->indio_dev;
unsigned long *adt7310_platform_data = spi_dev->dev.platform_data;
dev_set_drvdata(&spi_dev->dev, NULL);
if (adt7310_platform_data[0])
free_irq(adt7310_platform_data[0], chip->indio_dev);
if (spi_dev->irq)
free_irq(spi_dev->irq, chip->indio_dev);
iio_device_unregister(indio_dev);
iio_free_device(chip->indio_dev);
kfree(chip);
return 0;
}
static __init int adt7310_init(void)
{
return spi_register_driver(&adt7310_driver);
}
static __exit void adt7310_exit(void)
{
spi_unregister_driver(&adt7310_driver);
}
