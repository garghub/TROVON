static ssize_t dac7512_store_val(struct device *dev,
struct device_attribute *attr,
const char *buf, size_t count)
{
struct spi_device *spi = to_spi_device(dev);
unsigned char tmp[2];
unsigned long val;
if (strict_strtoul(buf, 10, &val) < 0)
return -EINVAL;
tmp[0] = val >> 8;
tmp[1] = val & 0xff;
spi_write(spi, tmp, sizeof(tmp));
return count;
}
static int __devinit dac7512_probe(struct spi_device *spi)
{
int ret;
spi->bits_per_word = 8;
spi->mode = SPI_MODE_0;
ret = spi_setup(spi);
if (ret < 0)
return ret;
return sysfs_create_group(&spi->dev.kobj, &dac7512_attr_group);
}
static int __devexit dac7512_remove(struct spi_device *spi)
{
sysfs_remove_group(&spi->dev.kobj, &dac7512_attr_group);
return 0;
}
