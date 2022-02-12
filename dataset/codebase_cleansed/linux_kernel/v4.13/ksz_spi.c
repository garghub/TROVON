static int ksz_spi_read_reg(struct spi_device *spi, u32 reg, u8 *val,
unsigned int len)
{
u32 txbuf;
int ret;
txbuf = reg & SPI_ADDR_MASK;
txbuf |= KS_SPIOP_RD << SPI_ADDR_SHIFT;
txbuf <<= SPI_TURNAROUND_SHIFT;
txbuf = cpu_to_be32(txbuf);
ret = spi_write_then_read(spi, &txbuf, 4, val, len);
return ret;
}
static int ksz_spi_read(struct ksz_device *dev, u32 reg, u8 *data,
unsigned int len)
{
struct spi_device *spi = dev->priv;
return ksz_spi_read_reg(spi, reg, data, len);
}
static int ksz_spi_read8(struct ksz_device *dev, u32 reg, u8 *val)
{
return ksz_spi_read(dev, reg, val, 1);
}
static int ksz_spi_read16(struct ksz_device *dev, u32 reg, u16 *val)
{
int ret = ksz_spi_read(dev, reg, (u8 *)val, 2);
if (!ret)
*val = be16_to_cpu(*val);
return ret;
}
static int ksz_spi_read24(struct ksz_device *dev, u32 reg, u32 *val)
{
int ret;
*val = 0;
ret = ksz_spi_read(dev, reg, (u8 *)val, 3);
if (!ret) {
*val = be32_to_cpu(*val);
*val >>= 8;
}
return ret;
}
static int ksz_spi_read32(struct ksz_device *dev, u32 reg, u32 *val)
{
int ret = ksz_spi_read(dev, reg, (u8 *)val, 4);
if (!ret)
*val = be32_to_cpu(*val);
return ret;
}
static int ksz_spi_write_reg(struct spi_device *spi, u32 reg, u8 *val,
unsigned int len)
{
u32 txbuf;
u8 data[12];
int i;
txbuf = reg & SPI_ADDR_MASK;
txbuf |= (KS_SPIOP_WR << SPI_ADDR_SHIFT);
txbuf <<= SPI_TURNAROUND_SHIFT;
txbuf = cpu_to_be32(txbuf);
data[0] = txbuf & 0xFF;
data[1] = (txbuf & 0xFF00) >> 8;
data[2] = (txbuf & 0xFF0000) >> 16;
data[3] = (txbuf & 0xFF000000) >> 24;
for (i = 0; i < len; i++)
data[i + 4] = val[i];
return spi_write(spi, &data, 4 + len);
}
static int ksz_spi_write8(struct ksz_device *dev, u32 reg, u8 value)
{
struct spi_device *spi = dev->priv;
return ksz_spi_write_reg(spi, reg, &value, 1);
}
static int ksz_spi_write16(struct ksz_device *dev, u32 reg, u16 value)
{
struct spi_device *spi = dev->priv;
value = cpu_to_be16(value);
return ksz_spi_write_reg(spi, reg, (u8 *)&value, 2);
}
static int ksz_spi_write24(struct ksz_device *dev, u32 reg, u32 value)
{
struct spi_device *spi = dev->priv;
value <<= 8;
value = cpu_to_be32(value);
return ksz_spi_write_reg(spi, reg, (u8 *)&value, 3);
}
static int ksz_spi_write32(struct ksz_device *dev, u32 reg, u32 value)
{
struct spi_device *spi = dev->priv;
value = cpu_to_be32(value);
return ksz_spi_write_reg(spi, reg, (u8 *)&value, 4);
}
static int ksz_spi_probe(struct spi_device *spi)
{
struct ksz_device *dev;
int ret;
dev = ksz_switch_alloc(&spi->dev, &ksz_spi_ops, spi);
if (!dev)
return -ENOMEM;
if (spi->dev.platform_data)
dev->pdata = spi->dev.platform_data;
ret = ksz_switch_register(dev);
if (ret)
return ret;
spi_set_drvdata(spi, dev);
return 0;
}
static int ksz_spi_remove(struct spi_device *spi)
{
struct ksz_device *dev = spi_get_drvdata(spi);
if (dev)
ksz_switch_remove(dev);
return 0;
}
