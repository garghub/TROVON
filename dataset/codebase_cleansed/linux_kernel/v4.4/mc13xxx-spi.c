static int mc13xxx_spi_read(void *context, const void *reg, size_t reg_size,
void *val, size_t val_size)
{
unsigned char w[4] = { *((unsigned char *) reg), 0, 0, 0};
unsigned char r[4];
unsigned char *p = val;
struct device *dev = context;
struct spi_device *spi = to_spi_device(dev);
struct spi_transfer t = {
.tx_buf = w,
.rx_buf = r,
.len = 4,
};
struct spi_message m;
int ret;
if (val_size != 3 || reg_size != 1)
return -ENOTSUPP;
spi_message_init(&m);
spi_message_add_tail(&t, &m);
ret = spi_sync(spi, &m);
memcpy(p, &r[1], 3);
return ret;
}
static int mc13xxx_spi_write(void *context, const void *data, size_t count)
{
struct device *dev = context;
struct spi_device *spi = to_spi_device(dev);
const char *reg = data;
if (count != 4)
return -ENOTSUPP;
if (*reg == MC13783_AUDIO_CODEC || *reg == MC13783_AUDIO_DAC)
spi_write(spi, data, count);
return spi_write(spi, data, count);
}
static int mc13xxx_spi_probe(struct spi_device *spi)
{
struct mc13xxx *mc13xxx;
int ret;
mc13xxx = devm_kzalloc(&spi->dev, sizeof(*mc13xxx), GFP_KERNEL);
if (!mc13xxx)
return -ENOMEM;
dev_set_drvdata(&spi->dev, mc13xxx);
spi->mode = SPI_MODE_0 | SPI_CS_HIGH;
mc13xxx->irq = spi->irq;
spi->max_speed_hz = spi->max_speed_hz ? : 26000000;
ret = spi_setup(spi);
if (ret)
return ret;
mc13xxx->regmap = devm_regmap_init(&spi->dev, &regmap_mc13xxx_bus,
&spi->dev,
&mc13xxx_regmap_spi_config);
if (IS_ERR(mc13xxx->regmap)) {
ret = PTR_ERR(mc13xxx->regmap);
dev_err(&spi->dev, "Failed to initialize regmap: %d\n", ret);
return ret;
}
if (spi->dev.of_node) {
const struct of_device_id *of_id =
of_match_device(mc13xxx_dt_ids, &spi->dev);
mc13xxx->variant = of_id->data;
} else {
const struct spi_device_id *id_entry = spi_get_device_id(spi);
mc13xxx->variant = (void *)id_entry->driver_data;
}
return mc13xxx_common_init(&spi->dev);
}
static int mc13xxx_spi_remove(struct spi_device *spi)
{
return mc13xxx_common_exit(&spi->dev);
}
static int __init mc13xxx_init(void)
{
return spi_register_driver(&mc13xxx_spi_driver);
}
static void __exit mc13xxx_exit(void)
{
spi_unregister_driver(&mc13xxx_spi_driver);
}
