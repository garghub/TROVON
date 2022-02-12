static int tps65912_spi_write(struct tps65912 *tps65912, u8 addr,
int bytes, void *src)
{
struct spi_device *spi = tps65912->control_data;
u8 *data = (u8 *) src;
int ret;
unsigned long spi_data = 1 << 23 | addr << 15 | *data;
struct spi_transfer xfer;
struct spi_message msg;
u32 tx_buf;
tx_buf = spi_data;
xfer.tx_buf = &tx_buf;
xfer.rx_buf = NULL;
xfer.len = sizeof(unsigned long);
xfer.bits_per_word = 24;
spi_message_init(&msg);
spi_message_add_tail(&xfer, &msg);
ret = spi_sync(spi, &msg);
return ret;
}
static int tps65912_spi_read(struct tps65912 *tps65912, u8 addr,
int bytes, void *dest)
{
struct spi_device *spi = tps65912->control_data;
unsigned long spi_data = 0 << 23 | addr << 15;
struct spi_transfer xfer;
struct spi_message msg;
int ret;
u8 *data = (u8 *) dest;
u32 tx_buf, rx_buf;
tx_buf = spi_data;
rx_buf = 0;
xfer.tx_buf = &tx_buf;
xfer.rx_buf = &rx_buf;
xfer.len = sizeof(unsigned long);
xfer.bits_per_word = 24;
spi_message_init(&msg);
spi_message_add_tail(&xfer, &msg);
if (spi == NULL)
return 0;
ret = spi_sync(spi, &msg);
if (ret == 0)
*data = (u8) (rx_buf & 0xFF);
return ret;
}
static int tps65912_spi_probe(struct spi_device *spi)
{
struct tps65912 *tps65912;
tps65912 = devm_kzalloc(&spi->dev,
sizeof(struct tps65912), GFP_KERNEL);
if (tps65912 == NULL)
return -ENOMEM;
tps65912->dev = &spi->dev;
tps65912->control_data = spi;
tps65912->read = tps65912_spi_read;
tps65912->write = tps65912_spi_write;
spi_set_drvdata(spi, tps65912);
return tps65912_device_init(tps65912);
}
static int tps65912_spi_remove(struct spi_device *spi)
{
struct tps65912 *tps65912 = spi_get_drvdata(spi);
tps65912_device_exit(tps65912);
return 0;
}
static int __init tps65912_spi_init(void)
{
int ret;
ret = spi_register_driver(&tps65912_spi_driver);
if (ret != 0)
pr_err("Failed to register TPS65912 SPI driver: %d\n", ret);
return 0;
}
static void __exit tps65912_spi_exit(void)
{
spi_unregister_driver(&tps65912_spi_driver);
}
