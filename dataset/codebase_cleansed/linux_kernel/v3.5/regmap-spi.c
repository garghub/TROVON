static int regmap_spi_write(void *context, const void *data, size_t count)
{
struct device *dev = context;
struct spi_device *spi = to_spi_device(dev);
return spi_write(spi, data, count);
}
static int regmap_spi_gather_write(void *context,
const void *reg, size_t reg_len,
const void *val, size_t val_len)
{
struct device *dev = context;
struct spi_device *spi = to_spi_device(dev);
struct spi_message m;
struct spi_transfer t[2] = { { .tx_buf = reg, .len = reg_len, },
{ .tx_buf = val, .len = val_len, }, };
spi_message_init(&m);
spi_message_add_tail(&t[0], &m);
spi_message_add_tail(&t[1], &m);
return spi_sync(spi, &m);
}
static int regmap_spi_read(void *context,
const void *reg, size_t reg_size,
void *val, size_t val_size)
{
struct device *dev = context;
struct spi_device *spi = to_spi_device(dev);
return spi_write_then_read(spi, reg, reg_size, val, val_size);
}
struct regmap *regmap_init_spi(struct spi_device *spi,
const struct regmap_config *config)
{
return regmap_init(&spi->dev, &regmap_spi, &spi->dev, config);
}
struct regmap *devm_regmap_init_spi(struct spi_device *spi,
const struct regmap_config *config)
{
return devm_regmap_init(&spi->dev, &regmap_spi, &spi->dev, config);
}
