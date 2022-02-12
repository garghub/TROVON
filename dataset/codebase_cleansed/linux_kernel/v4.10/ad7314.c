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
data = sign_extend32(data, 9);
return sprintf(buf, "%d\n", 250 * data);
case adt7301:
case adt7302:
data = ret & ADT7301_TEMP_MASK;
data = sign_extend32(data, 13);
return sprintf(buf, "%d\n",
DIV_ROUND_CLOSEST(data * 3125, 100));
default:
return -EINVAL;
}
}
static int ad7314_probe(struct spi_device *spi_dev)
{
struct ad7314_data *chip;
struct device *hwmon_dev;
chip = devm_kzalloc(&spi_dev->dev, sizeof(*chip), GFP_KERNEL);
if (chip == NULL)
return -ENOMEM;
chip->spi_dev = spi_dev;
hwmon_dev = devm_hwmon_device_register_with_groups(&spi_dev->dev,
spi_dev->modalias,
chip, ad7314_groups);
return PTR_ERR_OR_ZERO(hwmon_dev);
}
