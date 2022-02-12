static inline struct spi_lm70llp *spidev_to_pp(struct spi_device *spi)
{
return spi->controller_data;
}
static inline void deassertCS(struct spi_lm70llp *pp)
{
u8 data = parport_read_data(pp->port);
data &= ~0x80;
parport_write_data(pp->port, data | nCS);
}
static inline void assertCS(struct spi_lm70llp *pp)
{
u8 data = parport_read_data(pp->port);
data |= 0x80;
parport_write_data(pp->port, data & ~nCS);
}
static inline void clkHigh(struct spi_lm70llp *pp)
{
u8 data = parport_read_data(pp->port);
parport_write_data(pp->port, data | SCLK);
}
static inline void clkLow(struct spi_lm70llp *pp)
{
u8 data = parport_read_data(pp->port);
parport_write_data(pp->port, data & ~SCLK);
}
static inline void spidelay(unsigned d)
{
udelay(d);
}
static inline void setsck(struct spi_device *s, int is_on)
{
struct spi_lm70llp *pp = spidev_to_pp(s);
if (is_on)
clkHigh(pp);
else
clkLow(pp);
}
static inline void setmosi(struct spi_device *s, int is_on)
{
}
static inline int getmiso(struct spi_device *s)
{
struct spi_lm70llp *pp = spidev_to_pp(s);
return ((SIO == (parport_read_status(pp->port) & SIO)) ? 0 : 1 );
}
static void lm70_chipselect(struct spi_device *spi, int value)
{
struct spi_lm70llp *pp = spidev_to_pp(spi);
if (value)
assertCS(pp);
else
deassertCS(pp);
}
static u32 lm70_txrx(struct spi_device *spi, unsigned nsecs, u32 word, u8 bits)
{
return bitbang_txrx_be_cpha0(spi, nsecs, 0, 0, word, bits);
}
static void spi_lm70llp_attach(struct parport *p)
{
struct pardevice *pd;
struct spi_lm70llp *pp;
struct spi_master *master;
int status;
if (lm70llp) {
printk(KERN_WARNING
"%s: spi_lm70llp instance already loaded. Aborting.\n",
DRVNAME);
return;
}
master = spi_alloc_master(p->physport->dev, sizeof *pp);
if (!master) {
status = -ENOMEM;
goto out_fail;
}
pp = spi_master_get_devdata(master);
master->bus_num = -1;
master->num_chipselect = 1;
pp->bitbang.master = spi_master_get(master);
pp->bitbang.chipselect = lm70_chipselect;
pp->bitbang.txrx_word[SPI_MODE_0] = lm70_txrx;
pp->bitbang.flags = SPI_3WIRE;
pp->port = p;
pd = parport_register_device(p, DRVNAME,
NULL, NULL, NULL,
PARPORT_FLAG_EXCL, pp);
if (!pd) {
status = -ENOMEM;
goto out_free_master;
}
pp->pd = pd;
status = parport_claim(pd);
if (status < 0)
goto out_parport_unreg;
status = spi_bitbang_start(&pp->bitbang);
if (status < 0) {
printk(KERN_WARNING
"%s: spi_bitbang_start failed with status %d\n",
DRVNAME, status);
goto out_off_and_release;
}
strcpy(pp->info.modalias, "lm70");
pp->info.max_speed_hz = 6 * 1000 * 1000;
pp->info.chip_select = 0;
pp->info.mode = SPI_3WIRE | SPI_MODE_0;
parport_write_data(pp->port, lm70_INIT);
pp->info.controller_data = pp;
pp->spidev_lm70 = spi_new_device(pp->bitbang.master, &pp->info);
if (pp->spidev_lm70)
dev_dbg(&pp->spidev_lm70->dev, "spidev_lm70 at %s\n",
dev_name(&pp->spidev_lm70->dev));
else {
printk(KERN_WARNING "%s: spi_new_device failed\n", DRVNAME);
status = -ENODEV;
goto out_bitbang_stop;
}
pp->spidev_lm70->bits_per_word = 8;
lm70llp = pp;
return;
out_bitbang_stop:
spi_bitbang_stop(&pp->bitbang);
out_off_and_release:
parport_write_data(pp->port, 0);
mdelay(10);
parport_release(pp->pd);
out_parport_unreg:
parport_unregister_device(pd);
out_free_master:
(void) spi_master_put(master);
out_fail:
pr_info("%s: spi_lm70llp probe fail, status %d\n", DRVNAME, status);
}
static void spi_lm70llp_detach(struct parport *p)
{
struct spi_lm70llp *pp;
if (!lm70llp || lm70llp->port != p)
return;
pp = lm70llp;
spi_bitbang_stop(&pp->bitbang);
parport_write_data(pp->port, 0);
parport_release(pp->pd);
parport_unregister_device(pp->pd);
(void) spi_master_put(pp->bitbang.master);
lm70llp = NULL;
}
static int __init init_spi_lm70llp(void)
{
return parport_register_driver(&spi_lm70llp_drv);
}
static void __exit cleanup_spi_lm70llp(void)
{
parport_unregister_driver(&spi_lm70llp_drv);
}
