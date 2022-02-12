static inline struct s3c2410_spigpio *spidev_to_sg(struct spi_device *spi)
{
return spi_master_get_devdata(spi->master);
}
static inline void setsck(struct spi_device *dev, int on)
{
struct s3c2410_spigpio *sg = spidev_to_sg(dev);
s3c2410_gpio_setpin(sg->info->pin_clk, on ? 1 : 0);
}
static inline void setmosi(struct spi_device *dev, int on)
{
struct s3c2410_spigpio *sg = spidev_to_sg(dev);
s3c2410_gpio_setpin(sg->info->pin_mosi, on ? 1 : 0);
}
static inline u32 getmiso(struct spi_device *dev)
{
struct s3c2410_spigpio *sg = spidev_to_sg(dev);
return s3c2410_gpio_getpin(sg->info->pin_miso) ? 1 : 0;
}
static u32 s3c2410_spigpio_txrx_mode0(struct spi_device *spi,
unsigned nsecs, u32 word, u8 bits)
{
return bitbang_txrx_be_cpha0(spi, nsecs, 0, 0, word, bits);
}
static u32 s3c2410_spigpio_txrx_mode1(struct spi_device *spi,
unsigned nsecs, u32 word, u8 bits)
{
return bitbang_txrx_be_cpha1(spi, nsecs, 0, 0, word, bits);
}
static u32 s3c2410_spigpio_txrx_mode2(struct spi_device *spi,
unsigned nsecs, u32 word, u8 bits)
{
return bitbang_txrx_be_cpha0(spi, nsecs, 1, 0, word, bits);
}
static u32 s3c2410_spigpio_txrx_mode3(struct spi_device *spi,
unsigned nsecs, u32 word, u8 bits)
{
return bitbang_txrx_be_cpha1(spi, nsecs, 1, 0, word, bits);
}
static void s3c2410_spigpio_chipselect(struct spi_device *dev, int value)
{
struct s3c2410_spigpio *sg = spidev_to_sg(dev);
if (sg->info && sg->info->chip_select)
(sg->info->chip_select)(sg->info, value);
}
static int s3c2410_spigpio_probe(struct platform_device *dev)
{
struct s3c2410_spigpio_info *info;
struct spi_master *master;
struct s3c2410_spigpio *sp;
int ret;
master = spi_alloc_master(&dev->dev, sizeof(struct s3c2410_spigpio));
if (master == NULL) {
dev_err(&dev->dev, "failed to allocate spi master\n");
ret = -ENOMEM;
goto err;
}
sp = spi_master_get_devdata(master);
platform_set_drvdata(dev, sp);
info = sp->info = dev->dev.platform_data;
sp->bitbang.master = spi_master_get(master);
sp->bitbang.master->bus_num = info->bus_num;
sp->bitbang.master->num_chipselect = info->num_chipselect;
sp->bitbang.chipselect = s3c2410_spigpio_chipselect;
sp->bitbang.txrx_word[SPI_MODE_0] = s3c2410_spigpio_txrx_mode0;
sp->bitbang.txrx_word[SPI_MODE_1] = s3c2410_spigpio_txrx_mode1;
sp->bitbang.txrx_word[SPI_MODE_2] = s3c2410_spigpio_txrx_mode2;
sp->bitbang.txrx_word[SPI_MODE_3] = s3c2410_spigpio_txrx_mode3;
s3c2410_gpio_setpin(info->pin_clk, 0);
s3c2410_gpio_cfgpin(info->pin_clk, S3C2410_GPIO_OUTPUT);
if (info->pin_mosi < S3C2410_GPH10) {
s3c2410_gpio_setpin(info->pin_mosi, 0);
s3c2410_gpio_cfgpin(info->pin_mosi, S3C2410_GPIO_OUTPUT);
}
if (info->pin_miso != S3C2410_GPA0 && info->pin_miso < S3C2410_GPH10)
s3c2410_gpio_cfgpin(info->pin_miso, S3C2410_GPIO_INPUT);
ret = spi_bitbang_start(&sp->bitbang);
if (ret)
goto err_no_bitbang;
return 0;
err_no_bitbang:
spi_master_put(sp->bitbang.master);
err:
return ret;
}
static int s3c2410_spigpio_remove(struct platform_device *dev)
{
struct s3c2410_spigpio *sp = platform_get_drvdata(dev);
spi_bitbang_stop(&sp->bitbang);
spi_master_put(sp->bitbang.master);
return 0;
}
static int __init s3c2410_spigpio_init(void)
{
return platform_driver_register(&s3c2410_spigpio_drv);
}
static void __exit s3c2410_spigpio_exit(void)
{
platform_driver_unregister(&s3c2410_spigpio_drv);
}
