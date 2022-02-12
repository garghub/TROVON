static ssize_t lm70_sense_temp(struct device *dev,
struct device_attribute *attr, char *buf)
{
struct spi_device *spi = to_spi_device(dev);
int status, val = 0;
u8 rxbuf[2];
s16 raw = 0;
struct lm70 *p_lm70 = spi_get_drvdata(spi);
if (mutex_lock_interruptible(&p_lm70->lock))
return -ERESTARTSYS;
status = spi_write_then_read(spi, NULL, 0, &rxbuf[0], 2);
if (status < 0) {
pr_warn("spi_write_then_read failed with status %d\n", status);
goto out;
}
raw = (rxbuf[0] << 8) + rxbuf[1];
dev_dbg(dev, "rxbuf[0] : 0x%02x rxbuf[1] : 0x%02x raw=0x%04x\n",
rxbuf[0], rxbuf[1], raw);
switch (p_lm70->chip) {
case LM70_CHIP_LM70:
val = ((int)raw / 32) * 250;
break;
case LM70_CHIP_TMP121:
val = ((int)raw / 8) * 625 / 10;
break;
}
status = sprintf(buf, "%d\n", val);
out:
mutex_unlock(&p_lm70->lock);
return status;
}
static ssize_t lm70_show_name(struct device *dev, struct device_attribute
*devattr, char *buf)
{
struct lm70 *p_lm70 = dev_get_drvdata(dev);
int ret;
switch (p_lm70->chip) {
case LM70_CHIP_LM70:
ret = sprintf(buf, "lm70\n");
break;
case LM70_CHIP_TMP121:
ret = sprintf(buf, "tmp121\n");
break;
default:
ret = -EINVAL;
}
return ret;
}
static int __devinit lm70_probe(struct spi_device *spi)
{
int chip = spi_get_device_id(spi)->driver_data;
struct lm70 *p_lm70;
int status;
if (spi->mode & (SPI_CPOL | SPI_CPHA))
return -EINVAL;
if (chip == LM70_CHIP_LM70 && !(spi->mode & SPI_3WIRE))
return -EINVAL;
p_lm70 = kzalloc(sizeof *p_lm70, GFP_KERNEL);
if (!p_lm70)
return -ENOMEM;
mutex_init(&p_lm70->lock);
p_lm70->chip = chip;
spi_set_drvdata(spi, p_lm70);
status = device_create_file(&spi->dev, &dev_attr_temp1_input);
if (status)
goto out_dev_create_temp_file_failed;
status = device_create_file(&spi->dev, &dev_attr_name);
if (status)
goto out_dev_create_file_failed;
p_lm70->hwmon_dev = hwmon_device_register(&spi->dev);
if (IS_ERR(p_lm70->hwmon_dev)) {
dev_dbg(&spi->dev, "hwmon_device_register failed.\n");
status = PTR_ERR(p_lm70->hwmon_dev);
goto out_dev_reg_failed;
}
return 0;
out_dev_reg_failed:
device_remove_file(&spi->dev, &dev_attr_name);
out_dev_create_file_failed:
device_remove_file(&spi->dev, &dev_attr_temp1_input);
out_dev_create_temp_file_failed:
spi_set_drvdata(spi, NULL);
kfree(p_lm70);
return status;
}
static int __devexit lm70_remove(struct spi_device *spi)
{
struct lm70 *p_lm70 = spi_get_drvdata(spi);
hwmon_device_unregister(p_lm70->hwmon_dev);
device_remove_file(&spi->dev, &dev_attr_temp1_input);
device_remove_file(&spi->dev, &dev_attr_name);
spi_set_drvdata(spi, NULL);
kfree(p_lm70);
return 0;
}
