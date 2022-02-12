static int ad714x_spi_suspend(struct device *dev)
{
return ad714x_disable(spi_get_drvdata(to_spi_device(dev)));
}
static int ad714x_spi_resume(struct device *dev)
{
return ad714x_enable(spi_get_drvdata(to_spi_device(dev)));
}
static int ad714x_spi_read(struct device *dev, unsigned short reg,
unsigned short *data)
{
struct spi_device *spi = to_spi_device(dev);
unsigned short tx = AD714x_SPI_CMD_PREFIX | AD714x_SPI_READ | reg;
return spi_write_then_read(spi, (u8 *)&tx, 2, (u8 *)data, 2);
}
static int ad714x_spi_write(struct device *dev, unsigned short reg,
unsigned short data)
{
struct spi_device *spi = to_spi_device(dev);
unsigned short tx[2] = {
AD714x_SPI_CMD_PREFIX | reg,
data
};
return spi_write(spi, (u8 *)tx, 4);
}
static int __devinit ad714x_spi_probe(struct spi_device *spi)
{
struct ad714x_chip *chip;
chip = ad714x_probe(&spi->dev, BUS_SPI, spi->irq,
ad714x_spi_read, ad714x_spi_write);
if (IS_ERR(chip))
return PTR_ERR(chip);
spi_set_drvdata(spi, chip);
return 0;
}
static int __devexit ad714x_spi_remove(struct spi_device *spi)
{
struct ad714x_chip *chip = spi_get_drvdata(spi);
ad714x_remove(chip);
spi_set_drvdata(spi, NULL);
return 0;
}
static __init int ad714x_spi_init(void)
{
return spi_register_driver(&ad714x_spi_driver);
}
static __exit void ad714x_spi_exit(void)
{
spi_unregister_driver(&ad714x_spi_driver);
}
