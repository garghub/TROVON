static inline struct butterfly *spidev_to_pp(struct spi_device *spi)
{
return spi->controller_data;
}
static inline void
setsck(struct spi_device *spi, int is_on)
{
struct butterfly *pp = spidev_to_pp(spi);
u8 bit, byte = pp->lastbyte;
bit = spi_sck_bit;
if (is_on)
byte |= bit;
else
byte &= ~bit;
parport_write_data(pp->port, byte);
pp->lastbyte = byte;
}
static inline void
setmosi(struct spi_device *spi, int is_on)
{
struct butterfly *pp = spidev_to_pp(spi);
u8 bit, byte = pp->lastbyte;
bit = spi_mosi_bit;
if (is_on)
byte |= bit;
else
byte &= ~bit;
parport_write_data(pp->port, byte);
pp->lastbyte = byte;
}
static inline int getmiso(struct spi_device *spi)
{
struct butterfly *pp = spidev_to_pp(spi);
int value;
u8 bit;
bit = spi_miso_bit;
value = !(parport_read_status(pp->port) & bit);
return (bit == PARPORT_STATUS_BUSY) ? value : !value;
}
static void butterfly_chipselect(struct spi_device *spi, int value)
{
struct butterfly *pp = spidev_to_pp(spi);
if (value != BITBANG_CS_INACTIVE)
setsck(spi, spi->mode & SPI_CPOL);
if (spi_cs_bit == PARPORT_CONTROL_INIT)
value = !value;
parport_frob_control(pp->port, spi_cs_bit, value ? spi_cs_bit : 0);
}
static u32
butterfly_txrx_word_mode0(struct spi_device *spi, unsigned nsecs, u32 word,
u8 bits)
{
return bitbang_txrx_be_cpha0(spi, nsecs, 0, 0, word, bits);
}
static void butterfly_attach(struct parport *p)
{
struct pardevice *pd;
int status;
struct butterfly *pp;
struct spi_master *master;
struct device *dev = p->physport->dev;
struct pardev_cb butterfly_cb;
if (butterfly || !dev)
return;
master = spi_alloc_master(dev, sizeof(*pp));
if (!master) {
status = -ENOMEM;
goto done;
}
pp = spi_master_get_devdata(master);
master->bus_num = 42;
master->num_chipselect = 2;
pp->bitbang.master = master;
pp->bitbang.chipselect = butterfly_chipselect;
pp->bitbang.txrx_word[SPI_MODE_0] = butterfly_txrx_word_mode0;
pp->port = p;
memset(&butterfly_cb, 0, sizeof(butterfly_cb));
butterfly_cb.private = pp;
pd = parport_register_dev_model(p, "spi_butterfly", &butterfly_cb, 0);
if (!pd) {
status = -ENOMEM;
goto clean0;
}
pp->pd = pd;
status = parport_claim(pd);
if (status < 0)
goto clean1;
pr_debug("%s: powerup/reset Butterfly\n", p->name);
parport_frob_control(pp->port, spi_cs_bit, 0);
pp->lastbyte |= vcc_bits;
parport_write_data(pp->port, pp->lastbyte);
msleep(5);
pp->lastbyte |= butterfly_nreset;
parport_write_data(pp->port, pp->lastbyte);
msleep(100);
status = spi_bitbang_start(&pp->bitbang);
if (status < 0)
goto clean2;
pp->info[0].max_speed_hz = 15 * 1000 * 1000;
strcpy(pp->info[0].modalias, "mtd_dataflash");
pp->info[0].platform_data = &flash;
pp->info[0].chip_select = 1;
pp->info[0].controller_data = pp;
pp->dataflash = spi_new_device(pp->bitbang.master, &pp->info[0]);
if (pp->dataflash)
pr_debug("%s: dataflash at %s\n", p->name,
dev_name(&pp->dataflash->dev));
pr_info("%s: AVR Butterfly\n", p->name);
butterfly = pp;
return;
clean2:
parport_write_data(pp->port, 0);
parport_release(pp->pd);
clean1:
parport_unregister_device(pd);
clean0:
spi_master_put(pp->bitbang.master);
done:
pr_debug("%s: butterfly probe, fail %d\n", p->name, status);
}
static void butterfly_detach(struct parport *p)
{
struct butterfly *pp;
if (!butterfly || butterfly->port != p)
return;
pp = butterfly;
butterfly = NULL;
spi_bitbang_stop(&pp->bitbang);
parport_write_data(pp->port, 0);
msleep(10);
parport_release(pp->pd);
parport_unregister_device(pp->pd);
spi_master_put(pp->bitbang.master);
}
static int __init butterfly_init(void)
{
return parport_register_driver(&butterfly_driver);
}
static void __exit butterfly_exit(void)
{
parport_unregister_driver(&butterfly_driver);
}
