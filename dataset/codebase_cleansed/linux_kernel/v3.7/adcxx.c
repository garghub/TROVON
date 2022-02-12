static ssize_t adcxx_read(struct device *dev,
struct device_attribute *devattr, char *buf)
{
struct spi_device *spi = to_spi_device(dev);
struct sensor_device_attribute *attr = to_sensor_dev_attr(devattr);
struct adcxx *adc = spi_get_drvdata(spi);
u8 tx_buf[2];
u8 rx_buf[2];
int status;
u32 value;
if (mutex_lock_interruptible(&adc->lock))
return -ERESTARTSYS;
if (adc->channels == 1) {
status = spi_read(spi, rx_buf, sizeof(rx_buf));
} else {
tx_buf[0] = attr->index << 3;
status = spi_write_then_read(spi, tx_buf, sizeof(tx_buf),
rx_buf, sizeof(rx_buf));
}
if (status < 0) {
dev_warn(dev, "SPI synch. transfer failed with status %d\n",
status);
goto out;
}
value = (rx_buf[0] << 8) + rx_buf[1];
dev_dbg(dev, "raw value = 0x%x\n", value);
value = value * adc->reference >> 12;
status = sprintf(buf, "%d\n", value);
out:
mutex_unlock(&adc->lock);
return status;
}
static ssize_t adcxx_show_min(struct device *dev,
struct device_attribute *devattr, char *buf)
{
return sprintf(buf, "0\n");
}
static ssize_t adcxx_show_max(struct device *dev,
struct device_attribute *devattr, char *buf)
{
struct spi_device *spi = to_spi_device(dev);
struct adcxx *adc = spi_get_drvdata(spi);
u32 reference;
if (mutex_lock_interruptible(&adc->lock))
return -ERESTARTSYS;
reference = adc->reference;
mutex_unlock(&adc->lock);
return sprintf(buf, "%d\n", reference);
}
static ssize_t adcxx_set_max(struct device *dev,
struct device_attribute *devattr, const char *buf, size_t count)
{
struct spi_device *spi = to_spi_device(dev);
struct adcxx *adc = spi_get_drvdata(spi);
unsigned long value;
if (kstrtoul(buf, 10, &value))
return -EINVAL;
if (mutex_lock_interruptible(&adc->lock))
return -ERESTARTSYS;
adc->reference = value;
mutex_unlock(&adc->lock);
return count;
}
static ssize_t adcxx_show_name(struct device *dev, struct device_attribute
*devattr, char *buf)
{
return sprintf(buf, "%s\n", to_spi_device(dev)->modalias);
}
static int __devinit adcxx_probe(struct spi_device *spi)
{
int channels = spi_get_device_id(spi)->driver_data;
struct adcxx *adc;
int status;
int i;
adc = devm_kzalloc(&spi->dev, sizeof(*adc), GFP_KERNEL);
if (!adc)
return -ENOMEM;
adc->reference = 3300;
adc->channels = channels;
mutex_init(&adc->lock);
mutex_lock(&adc->lock);
spi_set_drvdata(spi, adc);
for (i = 0; i < 3 + adc->channels; i++) {
status = device_create_file(&spi->dev, &ad_input[i].dev_attr);
if (status) {
dev_err(&spi->dev, "device_create_file failed.\n");
goto out_err;
}
}
adc->hwmon_dev = hwmon_device_register(&spi->dev);
if (IS_ERR(adc->hwmon_dev)) {
dev_err(&spi->dev, "hwmon_device_register failed.\n");
status = PTR_ERR(adc->hwmon_dev);
goto out_err;
}
mutex_unlock(&adc->lock);
return 0;
out_err:
for (i--; i >= 0; i--)
device_remove_file(&spi->dev, &ad_input[i].dev_attr);
spi_set_drvdata(spi, NULL);
mutex_unlock(&adc->lock);
return status;
}
static int __devexit adcxx_remove(struct spi_device *spi)
{
struct adcxx *adc = spi_get_drvdata(spi);
int i;
mutex_lock(&adc->lock);
hwmon_device_unregister(adc->hwmon_dev);
for (i = 0; i < 3 + adc->channels; i++)
device_remove_file(&spi->dev, &ad_input[i].dev_attr);
spi_set_drvdata(spi, NULL);
mutex_unlock(&adc->lock);
return 0;
}
