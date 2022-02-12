static int adxl34x_spi_read(struct device *dev, unsigned char reg)
{
struct spi_device *spi = to_spi_device(dev);
unsigned char cmd;
cmd = ADXL34X_READCMD(reg);
return spi_w8r8(spi, cmd);
}
static int adxl34x_spi_write(struct device *dev,
unsigned char reg, unsigned char val)
{
struct spi_device *spi = to_spi_device(dev);
unsigned char buf[2];
buf[0] = ADXL34X_WRITECMD(reg);
buf[1] = val;
return spi_write(spi, buf, sizeof(buf));
}
static int adxl34x_spi_read_block(struct device *dev,
unsigned char reg, int count,
void *buf)
{
struct spi_device *spi = to_spi_device(dev);
ssize_t status;
reg = ADXL34X_READMB_CMD(reg);
status = spi_write_then_read(spi, &reg, 1, buf, count);
return (status < 0) ? status : 0;
}
static int adxl34x_spi_probe(struct spi_device *spi)
{
struct adxl34x *ac;
if (spi->max_speed_hz > MAX_SPI_FREQ_HZ) {
dev_err(&spi->dev, "SPI CLK %d Hz too fast\n", spi->max_speed_hz);
return -EINVAL;
}
ac = adxl34x_probe(&spi->dev, spi->irq,
spi->max_speed_hz > MAX_FREQ_NO_FIFODELAY,
&adxl34x_spi_bops);
if (IS_ERR(ac))
return PTR_ERR(ac);
spi_set_drvdata(spi, ac);
return 0;
}
static int adxl34x_spi_remove(struct spi_device *spi)
{
struct adxl34x *ac = spi_get_drvdata(spi);
return adxl34x_remove(ac);
}
static int __maybe_unused adxl34x_spi_suspend(struct device *dev)
{
struct spi_device *spi = to_spi_device(dev);
struct adxl34x *ac = spi_get_drvdata(spi);
adxl34x_suspend(ac);
return 0;
}
static int __maybe_unused adxl34x_spi_resume(struct device *dev)
{
struct spi_device *spi = to_spi_device(dev);
struct adxl34x *ac = spi_get_drvdata(spi);
adxl34x_resume(ac);
return 0;
}
