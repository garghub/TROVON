static int mcp795_rtcc_read(struct device *dev, u8 addr, u8 *buf, u8 count)
{
struct spi_device *spi = to_spi_device(dev);
int ret;
u8 tx[2];
tx[0] = MCP795_READ;
tx[1] = addr;
ret = spi_write_then_read(spi, tx, sizeof(tx), buf, count);
if (ret)
dev_err(dev, "Failed reading %d bytes from address %x.\n",
count, addr);
return ret;
}
static int mcp795_rtcc_write(struct device *dev, u8 addr, u8 *data, u8 count)
{
struct spi_device *spi = to_spi_device(dev);
int ret;
u8 tx[2 + count];
tx[0] = MCP795_WRITE;
tx[1] = addr;
memcpy(&tx[2], data, count);
ret = spi_write(spi, tx, 2 + count);
if (ret)
dev_err(dev, "Failed to write %d bytes to address %x.\n",
count, addr);
return ret;
}
static int mcp795_rtcc_set_bits(struct device *dev, u8 addr, u8 mask, u8 state)
{
int ret;
u8 tmp;
ret = mcp795_rtcc_read(dev, addr, &tmp, 1);
if (ret)
return ret;
if ((tmp & mask) != state) {
tmp = (tmp & ~mask) | state;
ret = mcp795_rtcc_write(dev, addr, &tmp, 1);
}
return ret;
}
static int mcp795_set_time(struct device *dev, struct rtc_time *tim)
{
int ret;
u8 data[7];
ret = mcp795_rtcc_read(dev, 0x01, data, sizeof(data));
if (ret)
return ret;
data[0] = (data[0] & 0x80) | ((tim->tm_sec / 10) << 4) | (tim->tm_sec % 10);
data[1] = (data[1] & 0x80) | ((tim->tm_min / 10) << 4) | (tim->tm_min % 10);
data[2] = ((tim->tm_hour / 10) << 4) | (tim->tm_hour % 10);
data[4] = ((tim->tm_mday / 10) << 4) | ((tim->tm_mday) % 10);
data[5] = (data[5] & 0x10) | (tim->tm_mon / 10) | (tim->tm_mon % 10);
if (tim->tm_year > 100)
tim->tm_year -= 100;
data[6] = ((tim->tm_year / 10) << 4) | (tim->tm_year % 10);
ret = mcp795_rtcc_write(dev, 0x01, data, sizeof(data));
if (ret)
return ret;
dev_dbg(dev, "Set mcp795: %04d-%02d-%02d %02d:%02d:%02d\n",
tim->tm_year + 1900, tim->tm_mon, tim->tm_mday,
tim->tm_hour, tim->tm_min, tim->tm_sec);
return 0;
}
static int mcp795_read_time(struct device *dev, struct rtc_time *tim)
{
int ret;
u8 data[7];
ret = mcp795_rtcc_read(dev, 0x01, data, sizeof(data));
if (ret)
return ret;
tim->tm_sec = ((data[0] & 0x70) >> 4) * 10 + (data[0] & 0x0f);
tim->tm_min = ((data[1] & 0x70) >> 4) * 10 + (data[1] & 0x0f);
tim->tm_hour = ((data[2] & 0x30) >> 4) * 10 + (data[2] & 0x0f);
tim->tm_mday = ((data[4] & 0x30) >> 4) * 10 + (data[4] & 0x0f);
tim->tm_mon = ((data[5] & 0x10) >> 4) * 10 + (data[5] & 0x0f);
tim->tm_year = ((data[6] & 0xf0) >> 4) * 10 + (data[6] & 0x0f) + 100;
dev_dbg(dev, "Read from mcp795: %04d-%02d-%02d %02d:%02d:%02d\n",
tim->tm_year + 1900, tim->tm_mon, tim->tm_mday,
tim->tm_hour, tim->tm_min, tim->tm_sec);
return rtc_valid_tm(tim);
}
static int mcp795_probe(struct spi_device *spi)
{
struct rtc_device *rtc;
int ret;
spi->mode = SPI_MODE_0;
spi->bits_per_word = 8;
ret = spi_setup(spi);
if (ret) {
dev_err(&spi->dev, "Unable to setup SPI\n");
return ret;
}
mcp795_rtcc_set_bits(&spi->dev, 0x01, MCP795_ST_BIT, MCP795_ST_BIT);
mcp795_rtcc_set_bits(&spi->dev, 0x03, MCP795_24_BIT, 0);
rtc = devm_rtc_device_register(&spi->dev, "rtc-mcp795",
&mcp795_rtc_ops, THIS_MODULE);
if (IS_ERR(rtc))
return PTR_ERR(rtc);
spi_set_drvdata(spi, rtc);
return 0;
}
