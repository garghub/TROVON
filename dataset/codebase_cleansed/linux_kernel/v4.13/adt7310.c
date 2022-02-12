static int adt7310_spi_read_word(struct device *dev, u8 reg)
{
struct spi_device *spi = to_spi_device(dev);
return spi_w8r16be(spi, AD7310_COMMAND(reg) | ADT7310_CMD_READ);
}
static int adt7310_spi_write_word(struct device *dev, u8 reg, u16 data)
{
struct spi_device *spi = to_spi_device(dev);
u8 buf[3];
buf[0] = AD7310_COMMAND(reg);
put_unaligned_be16(data, &buf[1]);
return spi_write(spi, buf, sizeof(buf));
}
static int adt7310_spi_read_byte(struct device *dev, u8 reg)
{
struct spi_device *spi = to_spi_device(dev);
return spi_w8r8(spi, AD7310_COMMAND(reg) | ADT7310_CMD_READ);
}
static int adt7310_spi_write_byte(struct device *dev, u8 reg,
u8 data)
{
struct spi_device *spi = to_spi_device(dev);
u8 buf[2];
buf[0] = AD7310_COMMAND(reg);
buf[1] = data;
return spi_write(spi, buf, sizeof(buf));
}
static int adt7310_spi_probe(struct spi_device *spi)
{
return adt7x10_probe(&spi->dev, spi_get_device_id(spi)->name, spi->irq,
&adt7310_spi_ops);
}
static int adt7310_spi_remove(struct spi_device *spi)
{
return adt7x10_remove(&spi->dev, spi->irq);
}
