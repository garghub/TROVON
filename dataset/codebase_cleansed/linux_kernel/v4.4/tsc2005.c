static int tsc2005_cmd(struct device *dev, u8 cmd)
{
u8 tx = TSC200X_CMD | TSC200X_CMD_12BIT | cmd;
struct spi_transfer xfer = {
.tx_buf = &tx,
.len = 1,
.bits_per_word = 8,
};
struct spi_message msg;
struct spi_device *spi = to_spi_device(dev);
int error;
spi_message_init(&msg);
spi_message_add_tail(&xfer, &msg);
error = spi_sync(spi, &msg);
if (error) {
dev_err(dev, "%s: failed, command: %x, spi error: %d\n",
__func__, cmd, error);
return error;
}
return 0;
}
static int tsc2005_probe(struct spi_device *spi)
{
int error;
spi->mode = SPI_MODE_0;
spi->bits_per_word = 8;
if (!spi->max_speed_hz)
spi->max_speed_hz = TSC2005_SPI_MAX_SPEED_HZ;
error = spi_setup(spi);
if (error)
return error;
return tsc200x_probe(&spi->dev, spi->irq, BUS_SPI,
devm_regmap_init_spi(spi, &tsc200x_regmap_config),
tsc2005_cmd);
}
static int tsc2005_remove(struct spi_device *spi)
{
return tsc200x_remove(&spi->dev);
}
