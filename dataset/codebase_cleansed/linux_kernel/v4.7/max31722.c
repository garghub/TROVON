static int max31722_set_mode(struct max31722_data *data, u8 mode)
{
int ret;
struct spi_device *spi = data->spi_device;
u8 buf[2] = {
MAX31722_REG_CFG | MAX31722_WRITE_MASK,
(data->mode & MAX31722_MODE_MASK) | mode
};
ret = spi_write(spi, &buf, sizeof(buf));
if (ret < 0) {
dev_err(&spi->dev, "failed to set sensor mode.\n");
return ret;
}
data->mode = (data->mode & MAX31722_MODE_MASK) | mode;
return 0;
}
static ssize_t max31722_show_temp(struct device *dev,
struct device_attribute *attr,
char *buf)
{
ssize_t ret;
struct max31722_data *data = dev_get_drvdata(dev);
ret = spi_w8r16(data->spi_device, MAX31722_REG_TEMP_LSB);
if (ret < 0)
return ret;
return sprintf(buf, "%d\n", (s16)le16_to_cpu(ret) * 125 / 32);
}
static int max31722_probe(struct spi_device *spi)
{
int ret;
struct max31722_data *data;
data = devm_kzalloc(&spi->dev, sizeof(*data), GFP_KERNEL);
if (!data)
return -ENOMEM;
spi_set_drvdata(spi, data);
data->spi_device = spi;
data->mode = MAX31722_MODE_CONTINUOUS | MAX31722_RESOLUTION_12BIT;
ret = max31722_set_mode(data, MAX31722_MODE_CONTINUOUS);
if (ret < 0)
return ret;
data->hwmon_dev = hwmon_device_register_with_groups(&spi->dev,
spi->modalias,
data,
max31722_groups);
if (IS_ERR(data->hwmon_dev)) {
max31722_set_mode(data, MAX31722_MODE_STANDBY);
return PTR_ERR(data->hwmon_dev);
}
return 0;
}
static int max31722_remove(struct spi_device *spi)
{
struct max31722_data *data = spi_get_drvdata(spi);
hwmon_device_unregister(data->hwmon_dev);
return max31722_set_mode(data, MAX31722_MODE_STANDBY);
}
static int __maybe_unused max31722_suspend(struct device *dev)
{
struct spi_device *spi_device = to_spi_device(dev);
struct max31722_data *data = spi_get_drvdata(spi_device);
return max31722_set_mode(data, MAX31722_MODE_STANDBY);
}
static int __maybe_unused max31722_resume(struct device *dev)
{
struct spi_device *spi_device = to_spi_device(dev);
struct max31722_data *data = spi_get_drvdata(spi_device);
return max31722_set_mode(data, MAX31722_MODE_CONTINUOUS);
}
