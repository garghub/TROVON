static int ds1347_read_time(struct device *dev, struct rtc_time *dt)
{
struct spi_device *spi = to_spi_device(dev);
struct regmap *map;
int err;
unsigned char buf[8];
map = spi_get_drvdata(spi);
err = regmap_bulk_read(map, DS1347_CLOCK_BURST, buf, 8);
if (err)
return err;
dt->tm_sec = bcd2bin(buf[0]);
dt->tm_min = bcd2bin(buf[1]);
dt->tm_hour = bcd2bin(buf[2] & 0x3F);
dt->tm_mday = bcd2bin(buf[3]);
dt->tm_mon = bcd2bin(buf[4]) - 1;
dt->tm_wday = bcd2bin(buf[5]) - 1;
dt->tm_year = bcd2bin(buf[6]) + 100;
return rtc_valid_tm(dt);
}
static int ds1347_set_time(struct device *dev, struct rtc_time *dt)
{
struct spi_device *spi = to_spi_device(dev);
struct regmap *map;
unsigned char buf[8];
map = spi_get_drvdata(spi);
buf[0] = bin2bcd(dt->tm_sec);
buf[1] = bin2bcd(dt->tm_min);
buf[2] = (bin2bcd(dt->tm_hour) & 0x3F);
buf[3] = bin2bcd(dt->tm_mday);
buf[4] = bin2bcd(dt->tm_mon + 1);
buf[5] = bin2bcd(dt->tm_wday + 1);
dt->tm_year = dt->tm_year % 100;
buf[6] = bin2bcd(dt->tm_year);
buf[7] = bin2bcd(0x00);
return regmap_bulk_write(map, DS1347_CLOCK_BURST, buf, 8);
}
static int ds1347_probe(struct spi_device *spi)
{
struct rtc_device *rtc;
struct regmap_config config;
struct regmap *map;
unsigned int data;
int res;
memset(&config, 0, sizeof(config));
config.reg_bits = 8;
config.val_bits = 8;
config.read_flag_mask = 0x80;
config.max_register = 0x3F;
config.wr_table = &ds1347_access_table;
spi->mode = SPI_MODE_3;
spi->bits_per_word = 8;
spi_setup(spi);
map = devm_regmap_init_spi(spi, &config);
if (IS_ERR(map)) {
dev_err(&spi->dev, "ds1347 regmap init spi failed\n");
return PTR_ERR(map);
}
spi_set_drvdata(spi, map);
res = regmap_read(map, DS1347_SECONDS_REG, &data);
if (res)
return res;
regmap_read(map, DS1347_CONTROL_REG, &data);
data = data & ~(1<<7);
regmap_write(map, DS1347_CONTROL_REG, data);
regmap_read(map, DS1347_STATUS_REG, &data);
data = data & 0x1B;
regmap_write(map, DS1347_STATUS_REG, data);
regmap_read(map, DS1347_CONTROL_REG, &data);
dev_info(&spi->dev, "DS1347 RTC CTRL Reg = 0x%02x\n", data);
regmap_read(map, DS1347_STATUS_REG, &data);
dev_info(&spi->dev, "DS1347 RTC Status Reg = 0x%02x\n", data);
rtc = devm_rtc_device_register(&spi->dev, "ds1347",
&ds1347_rtc_ops, THIS_MODULE);
if (IS_ERR(rtc))
return PTR_ERR(rtc);
return 0;
}
