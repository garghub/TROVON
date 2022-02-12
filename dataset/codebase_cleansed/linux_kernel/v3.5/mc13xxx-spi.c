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
const struct of_device_id *of_id;
struct spi_driver *sdrv = to_spi_driver(spi->dev.driver);
struct mc13xxx *mc13xxx;
struct mc13xxx_platform_data *pdata = dev_get_platdata(&spi->dev);
int ret;
of_id = of_match_device(mc13xxx_dt_ids, &spi->dev);
if (of_id)
sdrv->id_table = &mc13xxx_device_id[(enum mc13xxx_id) of_id->data];
int __devexit mc13xxx_spi_remove(struct spi_device *spi)
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
