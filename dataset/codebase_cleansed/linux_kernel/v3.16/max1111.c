static int max1111_read(struct device *dev, int channel)
{
struct max1111_data *data = dev_get_drvdata(dev);
uint8_t v1, v2;
int err;
mutex_lock(&data->drvdata_lock);
data->tx_buf[0] = (channel << data->sel_sh) |
MAX1111_CTRL_PD0 | MAX1111_CTRL_PD1 |
MAX1111_CTRL_SGL | MAX1111_CTRL_UNI | MAX1111_CTRL_STR;
err = spi_sync(data->spi, &data->msg);
if (err < 0) {
dev_err(dev, "spi_sync failed with %d\n", err);
mutex_unlock(&data->drvdata_lock);
return err;
}
v1 = data->rx_buf[0];
v2 = data->rx_buf[1];
mutex_unlock(&data->drvdata_lock);
if ((v1 & 0xc0) || (v2 & 0x3f))
return -EINVAL;
return (v1 << 2) | (v2 >> 6);
}
int max1111_read_channel(int channel)
{
return max1111_read(&the_max1111->spi->dev, channel);
}
static ssize_t show_name(struct device *dev,
struct device_attribute *attr, char *buf)
{
return sprintf(buf, "%s\n", to_spi_device(dev)->modalias);
}
static ssize_t show_adc(struct device *dev,
struct device_attribute *attr, char *buf)
{
struct max1111_data *data = dev_get_drvdata(dev);
int channel = to_sensor_dev_attr(attr)->index;
int ret;
ret = max1111_read(dev, channel);
if (ret < 0)
return ret;
return sprintf(buf, "%d\n", ret * data->lsb);
}
static int setup_transfer(struct max1111_data *data)
{
struct spi_message *m;
struct spi_transfer *x;
m = &data->msg;
x = &data->xfer[0];
spi_message_init(m);
x->tx_buf = &data->tx_buf[0];
x->len = MAX1111_TX_BUF_SIZE;
spi_message_add_tail(x, m);
x++;
x->rx_buf = &data->rx_buf[0];
x->len = MAX1111_RX_BUF_SIZE;
spi_message_add_tail(x, m);
return 0;
}
static int max1111_probe(struct spi_device *spi)
{
enum chips chip = spi_get_device_id(spi)->driver_data;
struct max1111_data *data;
int err;
spi->bits_per_word = 8;
spi->mode = SPI_MODE_0;
err = spi_setup(spi);
if (err < 0)
return err;
data = devm_kzalloc(&spi->dev, sizeof(struct max1111_data), GFP_KERNEL);
if (data == NULL)
return -ENOMEM;
switch (chip) {
case max1110:
data->lsb = 8;
data->sel_sh = MAX1110_CTRL_SEL_SH;
break;
case max1111:
data->lsb = 8;
data->sel_sh = MAX1111_CTRL_SEL_SH;
break;
case max1112:
data->lsb = 16;
data->sel_sh = MAX1110_CTRL_SEL_SH;
break;
case max1113:
data->lsb = 16;
data->sel_sh = MAX1111_CTRL_SEL_SH;
break;
}
err = setup_transfer(data);
if (err)
return err;
mutex_init(&data->drvdata_lock);
data->spi = spi;
spi_set_drvdata(spi, data);
err = sysfs_create_group(&spi->dev.kobj, &max1111_attr_group);
if (err) {
dev_err(&spi->dev, "failed to create attribute group\n");
return err;
}
if (chip == max1110 || chip == max1112) {
err = sysfs_create_group(&spi->dev.kobj, &max1110_attr_group);
if (err) {
dev_err(&spi->dev,
"failed to create extended attribute group\n");
goto err_remove;
}
}
data->hwmon_dev = hwmon_device_register(&spi->dev);
if (IS_ERR(data->hwmon_dev)) {
dev_err(&spi->dev, "failed to create hwmon device\n");
err = PTR_ERR(data->hwmon_dev);
goto err_remove;
}
#ifdef CONFIG_SHARPSL_PM
the_max1111 = data;
#endif
return 0;
err_remove:
sysfs_remove_group(&spi->dev.kobj, &max1110_attr_group);
sysfs_remove_group(&spi->dev.kobj, &max1111_attr_group);
return err;
}
static int max1111_remove(struct spi_device *spi)
{
struct max1111_data *data = spi_get_drvdata(spi);
hwmon_device_unregister(data->hwmon_dev);
sysfs_remove_group(&spi->dev.kobj, &max1110_attr_group);
sysfs_remove_group(&spi->dev.kobj, &max1111_attr_group);
mutex_destroy(&data->drvdata_lock);
return 0;
}
