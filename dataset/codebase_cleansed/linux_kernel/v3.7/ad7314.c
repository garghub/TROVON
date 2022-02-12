static int ad7314_spi_read(struct ad7314_data *chip)
{
int ret;
ret = spi_read(chip->spi_dev, (u8 *)&chip->rx, sizeof(chip->rx));
if (ret < 0) {
dev_err(&chip->spi_dev->dev, "SPI read error\n");
return ret;
}
return be16_to_cpu(chip->rx);
}
static ssize_t ad7314_show_temperature(struct device *dev,
struct device_attribute *attr,
char *buf)
{
struct ad7314_data *chip = dev_get_drvdata(dev);
s16 data;
int ret;
ret = ad7314_spi_read(chip);
if (ret < 0)
return ret;
switch (spi_get_device_id(chip->spi_dev)->driver_data) {
case ad7314:
data = (ret & AD7314_TEMP_MASK) >> AD7314_TEMP_SHIFT;
data = (data << 6) >> 6;
return sprintf(buf, "%d\n", 250 * data);
case adt7301:
case adt7302:
data = ret & ADT7301_TEMP_MASK;
data = (data << 2) >> 2;
return sprintf(buf, "%d\n",
DIV_ROUND_CLOSEST(data * 3125, 100));
default:
return -EINVAL;
}
}
static ssize_t ad7314_show_name(struct device *dev,
struct device_attribute *devattr, char *buf)
{
return sprintf(buf, "%s\n", to_spi_device(dev)->modalias);
}
static int __devinit ad7314_probe(struct spi_device *spi_dev)
{
int ret;
struct ad7314_data *chip;
chip = devm_kzalloc(&spi_dev->dev, sizeof(*chip), GFP_KERNEL);
if (chip == NULL)
return -ENOMEM;
dev_set_drvdata(&spi_dev->dev, chip);
ret = sysfs_create_group(&spi_dev->dev.kobj, &ad7314_group);
if (ret < 0)
return ret;
chip->hwmon_dev = hwmon_device_register(&spi_dev->dev);
if (IS_ERR(chip->hwmon_dev)) {
ret = PTR_ERR(chip->hwmon_dev);
goto error_remove_group;
}
chip->spi_dev = spi_dev;
return 0;
error_remove_group:
sysfs_remove_group(&spi_dev->dev.kobj, &ad7314_group);
return ret;
}
static int __devexit ad7314_remove(struct spi_device *spi_dev)
{
struct ad7314_data *chip = dev_get_drvdata(&spi_dev->dev);
hwmon_device_unregister(chip->hwmon_dev);
sysfs_remove_group(&spi_dev->dev.kobj, &ad7314_group);
return 0;
}
