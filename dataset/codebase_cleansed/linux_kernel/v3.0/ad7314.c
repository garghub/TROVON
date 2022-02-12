static int ad7314_spi_read(struct ad7314_chip_info *chip, u16 *data)
{
struct spi_device *spi_dev = chip->spi_dev;
int ret = 0;
u16 value;
ret = spi_read(spi_dev, (u8 *)&value, sizeof(value));
if (ret < 0) {
dev_err(&spi_dev->dev, "SPI read error\n");
return ret;
}
*data = be16_to_cpu((u16)value);
return ret;
}
static int ad7314_spi_write(struct ad7314_chip_info *chip, u16 data)
{
struct spi_device *spi_dev = chip->spi_dev;
int ret = 0;
u16 value = cpu_to_be16(data);
ret = spi_write(spi_dev, (u8 *)&value, sizeof(value));
if (ret < 0)
dev_err(&spi_dev->dev, "SPI write error\n");
return ret;
}
static ssize_t ad7314_show_mode(struct device *dev,
struct device_attribute *attr,
char *buf)
{
struct iio_dev *dev_info = dev_get_drvdata(dev);
struct ad7314_chip_info *chip = dev_info->dev_data;
if (chip->mode)
return sprintf(buf, "power-save\n");
else
return sprintf(buf, "full\n");
}
static ssize_t ad7314_store_mode(struct device *dev,
struct device_attribute *attr,
const char *buf,
size_t len)
{
struct iio_dev *dev_info = dev_get_drvdata(dev);
struct ad7314_chip_info *chip = dev_info->dev_data;
u16 mode = 0;
int ret;
if (!strcmp(buf, "full"))
mode = AD7314_PD;
ret = ad7314_spi_write(chip, mode);
if (ret)
return -EIO;
chip->mode = mode;
return len;
}
static ssize_t ad7314_show_available_modes(struct device *dev,
struct device_attribute *attr,
char *buf)
{
return sprintf(buf, "full\npower-save\n");
}
static ssize_t ad7314_show_temperature(struct device *dev,
struct device_attribute *attr,
char *buf)
{
struct iio_dev *dev_info = dev_get_drvdata(dev);
struct ad7314_chip_info *chip = dev_info->dev_data;
u16 data;
char sign = ' ';
int ret;
if (chip->mode) {
ret = ad7314_spi_write(chip, 0);
if (ret)
return -EIO;
}
ret = ad7314_spi_read(chip, &data);
if (ret)
return -EIO;
if (chip->mode)
ad7314_spi_write(chip, chip->mode);
if (strcmp(dev_info->name, "ad7314")) {
data = (data & AD7314_TEMP_MASK) >>
AD7314_TEMP_OFFSET;
if (data & AD7314_TEMP_SIGN) {
data = (AD7314_TEMP_SIGN << 1) - data;
sign = '-';
}
return sprintf(buf, "%c%d.%.2d\n", sign,
data >> AD7314_TEMP_FLOAT_OFFSET,
(data & AD7314_TEMP_FLOAT_MASK) * 25);
} else {
data &= ADT7301_TEMP_MASK;
if (data & ADT7301_TEMP_SIGN) {
data = (ADT7301_TEMP_SIGN << 1) - data;
sign = '-';
}
return sprintf(buf, "%c%d.%.5d\n", sign,
data >> ADT7301_TEMP_FLOAT_OFFSET,
(data & ADT7301_TEMP_FLOAT_MASK) * 3125);
}
}
static int __devinit ad7314_probe(struct spi_device *spi_dev)
{
struct ad7314_chip_info *chip;
int ret = 0;
chip = kzalloc(sizeof(struct ad7314_chip_info), GFP_KERNEL);
if (chip == NULL)
return -ENOMEM;
dev_set_drvdata(&spi_dev->dev, chip);
chip->spi_dev = spi_dev;
chip->indio_dev = iio_allocate_device(0);
if (chip->indio_dev == NULL) {
ret = -ENOMEM;
goto error_free_chip;
}
chip->indio_dev->name = spi_get_device_id(spi_dev)->name;
chip->indio_dev->dev.parent = &spi_dev->dev;
chip->indio_dev->info = &ad7314_info;
chip->indio_dev->dev_data = (void *)chip;
ret = iio_device_register(chip->indio_dev);
if (ret)
goto error_free_dev;
dev_info(&spi_dev->dev, "%s temperature sensor registered.\n",
chip->indio_dev->name);
return 0;
error_free_dev:
iio_free_device(chip->indio_dev);
error_free_chip:
kfree(chip);
return ret;
}
static int __devexit ad7314_remove(struct spi_device *spi_dev)
{
struct ad7314_chip_info *chip = dev_get_drvdata(&spi_dev->dev);
struct iio_dev *indio_dev = chip->indio_dev;
dev_set_drvdata(&spi_dev->dev, NULL);
iio_device_unregister(indio_dev);
iio_free_device(chip->indio_dev);
kfree(chip);
return 0;
}
static __init int ad7314_init(void)
{
return spi_register_driver(&ad7314_driver);
}
static __exit void ad7314_exit(void)
{
spi_unregister_driver(&ad7314_driver);
}
