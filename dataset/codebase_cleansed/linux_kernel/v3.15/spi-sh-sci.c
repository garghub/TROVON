static inline void setbits(struct sh_sci_spi *sp, int bits, int on)
{
if (on)
sp->val |= bits;
else
sp->val &= ~bits;
iowrite8(sp->val, SCSPTR(sp));
}
static inline void setsck(struct spi_device *dev, int on)
{
setbits(spi_master_get_devdata(dev->master), PIN_SCK, on);
}
static inline void setmosi(struct spi_device *dev, int on)
{
setbits(spi_master_get_devdata(dev->master), PIN_TXD, on);
}
static inline u32 getmiso(struct spi_device *dev)
{
struct sh_sci_spi *sp = spi_master_get_devdata(dev->master);
return (ioread8(SCSPTR(sp)) & PIN_RXD) ? 1 : 0;
}
static u32 sh_sci_spi_txrx_mode0(struct spi_device *spi,
unsigned nsecs, u32 word, u8 bits)
{
return bitbang_txrx_be_cpha0(spi, nsecs, 0, 0, word, bits);
}
static u32 sh_sci_spi_txrx_mode1(struct spi_device *spi,
unsigned nsecs, u32 word, u8 bits)
{
return bitbang_txrx_be_cpha1(spi, nsecs, 0, 0, word, bits);
}
static u32 sh_sci_spi_txrx_mode2(struct spi_device *spi,
unsigned nsecs, u32 word, u8 bits)
{
return bitbang_txrx_be_cpha0(spi, nsecs, 1, 0, word, bits);
}
static u32 sh_sci_spi_txrx_mode3(struct spi_device *spi,
unsigned nsecs, u32 word, u8 bits)
{
return bitbang_txrx_be_cpha1(spi, nsecs, 1, 0, word, bits);
}
static void sh_sci_spi_chipselect(struct spi_device *dev, int value)
{
struct sh_sci_spi *sp = spi_master_get_devdata(dev->master);
if (sp->info->chip_select)
(sp->info->chip_select)(sp->info, dev->chip_select, value);
}
static int sh_sci_spi_probe(struct platform_device *dev)
{
struct resource *r;
struct spi_master *master;
struct sh_sci_spi *sp;
int ret;
master = spi_alloc_master(&dev->dev, sizeof(struct sh_sci_spi));
if (master == NULL) {
dev_err(&dev->dev, "failed to allocate spi master\n");
ret = -ENOMEM;
goto err0;
}
sp = spi_master_get_devdata(master);
platform_set_drvdata(dev, sp);
sp->info = dev_get_platdata(&dev->dev);
if (!sp->info) {
dev_err(&dev->dev, "platform data is missing\n");
ret = -ENOENT;
goto err1;
}
sp->bitbang.master = master;
sp->bitbang.master->bus_num = sp->info->bus_num;
sp->bitbang.master->num_chipselect = sp->info->num_chipselect;
sp->bitbang.chipselect = sh_sci_spi_chipselect;
sp->bitbang.txrx_word[SPI_MODE_0] = sh_sci_spi_txrx_mode0;
sp->bitbang.txrx_word[SPI_MODE_1] = sh_sci_spi_txrx_mode1;
sp->bitbang.txrx_word[SPI_MODE_2] = sh_sci_spi_txrx_mode2;
sp->bitbang.txrx_word[SPI_MODE_3] = sh_sci_spi_txrx_mode3;
r = platform_get_resource(dev, IORESOURCE_MEM, 0);
if (r == NULL) {
ret = -ENOENT;
goto err1;
}
sp->membase = ioremap(r->start, resource_size(r));
if (!sp->membase) {
ret = -ENXIO;
goto err1;
}
sp->val = ioread8(SCSPTR(sp));
setbits(sp, PIN_INIT, 1);
ret = spi_bitbang_start(&sp->bitbang);
if (!ret)
return 0;
setbits(sp, PIN_INIT, 0);
iounmap(sp->membase);
err1:
spi_master_put(sp->bitbang.master);
err0:
return ret;
}
static int sh_sci_spi_remove(struct platform_device *dev)
{
struct sh_sci_spi *sp = platform_get_drvdata(dev);
iounmap(sp->membase);
setbits(sp, PIN_INIT, 0);
spi_bitbang_stop(&sp->bitbang);
spi_master_put(sp->bitbang.master);
return 0;
}
