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
if (count != 4)
return -ENOTSUPP;
return spi_write(spi, data, count);
}
static int mc13xxx_spi_probe(struct spi_device *spi)
{
struct mc13xxx *mc13xxx;
struct mc13xxx_platform_data *pdata = dev_get_platdata(&spi->dev);
int ret;
mc13xxx = devm_kzalloc(&spi->dev, sizeof(*mc13xxx), GFP_KERNEL);
if (!mc13xxx)
return -ENOMEM;
dev_set_drvdata(&spi->dev, mc13xxx);
spi->mode = SPI_MODE_0 | SPI_CS_HIGH;
mc13xxx->dev = &spi->dev;
mutex_init(&mc13xxx->lock);
mc13xxx->regmap = devm_regmap_init(&spi->dev, &regmap_mc13xxx_bus,
&spi->dev,
&mc13xxx_regmap_spi_config);
if (IS_ERR(mc13xxx->regmap)) {
ret = PTR_ERR(mc13xxx->regmap);
dev_err(mc13xxx->dev, "Failed to initialize register map: %d\n",
ret);
dev_set_drvdata(&spi->dev, NULL);
return ret;
}
ret = mc13xxx_common_init(mc13xxx, pdata, spi->irq);
if (ret) {
dev_set_drvdata(&spi->dev, NULL);
} else {
const struct spi_device_id *devid =
spi_get_device_id(spi);
if (!devid || devid->driver_data != mc13xxx->ictype)
dev_warn(mc13xxx->dev,
"device id doesn't match auto detection!\n");
}
return ret;
}
static int __devexit mc13xxx_spi_remove(struct spi_device *spi)
{
struct mc13xxx *mc13xxx = dev_get_drvdata(&spi->dev);
mc13xxx_common_cleanup(mc13xxx);
return 0;
}
static int __init mc13xxx_init(void)
{
return spi_register_driver(&mc13xxx_spi_driver);
}
static void __exit mc13xxx_exit(void)
{
spi_unregister_driver(&mc13xxx_spi_driver);
}
