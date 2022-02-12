static int ads7871_read_reg8(struct spi_device *spi, int reg)
{
int ret;
reg = reg | INST_READ_bm;
ret = spi_w8r8(spi, reg);
return ret;
}
static int ads7871_read_reg16(struct spi_device *spi, int reg)
{
int ret;
reg = reg | INST_READ_bm | INST_16BIT_bm;
ret = spi_w8r16(spi, reg);
return ret;
}
static int ads7871_write_reg8(struct spi_device *spi, int reg, u8 val)
{
u8 tmp[2] = {reg, val};
return spi_write(spi, tmp, sizeof(tmp));
}
static ssize_t show_voltage(struct device *dev,
struct device_attribute *da, char *buf)
{
struct spi_device *spi = to_spi_device(dev);
struct sensor_device_attribute *attr = to_sensor_dev_attr(da);
int ret, val, i = 0;
uint8_t channel, mux_cnv;
channel = attr->index;
ads7871_write_reg8(spi, REG_GAIN_MUX,
(MUX_CNV_bm | MUX_M3_bm | channel));
ret = ads7871_read_reg8(spi, REG_GAIN_MUX);
mux_cnv = ((ret & MUX_CNV_bm)>>MUX_CNV_bv);
while ((i < 2) && mux_cnv) {
i++;
ret = ads7871_read_reg8(spi, REG_GAIN_MUX);
mux_cnv = ((ret & MUX_CNV_bm)>>MUX_CNV_bv);
msleep_interruptible(1);
}
if (mux_cnv == 0) {
val = ads7871_read_reg16(spi, REG_LS_BYTE);
val = ((val>>2) * 25000) / 8192;
return sprintf(buf, "%d\n", val);
} else {
return -1;
}
}
static int __devinit ads7871_probe(struct spi_device *spi)
{
int ret, err;
uint8_t val;
struct ads7871_data *pdata;
dev_dbg(&spi->dev, "probe\n");
spi->mode = (SPI_MODE_0);
spi->bits_per_word = 8;
spi_setup(spi);
ads7871_write_reg8(spi, REG_SER_CONTROL, 0);
ads7871_write_reg8(spi, REG_AD_CONTROL, 0);
val = (OSC_OSCR_bm | OSC_OSCE_bm | OSC_REFE_bm | OSC_BUFE_bm);
ads7871_write_reg8(spi, REG_OSC_CONTROL, val);
ret = ads7871_read_reg8(spi, REG_OSC_CONTROL);
dev_dbg(&spi->dev, "REG_OSC_CONTROL write:%x, read:%x\n", val, ret);
if (val != ret) {
err = -ENODEV;
goto exit;
}
pdata = kzalloc(sizeof(struct ads7871_data), GFP_KERNEL);
if (!pdata) {
err = -ENOMEM;
goto exit;
}
err = sysfs_create_group(&spi->dev.kobj, &ads7871_group);
if (err < 0)
goto error_free;
spi_set_drvdata(spi, pdata);
pdata->hwmon_dev = hwmon_device_register(&spi->dev);
if (IS_ERR(pdata->hwmon_dev)) {
err = PTR_ERR(pdata->hwmon_dev);
goto error_remove;
}
return 0;
error_remove:
sysfs_remove_group(&spi->dev.kobj, &ads7871_group);
error_free:
kfree(pdata);
exit:
return err;
}
static int __devexit ads7871_remove(struct spi_device *spi)
{
struct ads7871_data *pdata = spi_get_drvdata(spi);
hwmon_device_unregister(pdata->hwmon_dev);
sysfs_remove_group(&spi->dev.kobj, &ads7871_group);
kfree(pdata);
return 0;
}
static int __init ads7871_init(void)
{
return spi_register_driver(&ads7871_driver);
}
static void __exit ads7871_exit(void)
{
spi_unregister_driver(&ads7871_driver);
}
