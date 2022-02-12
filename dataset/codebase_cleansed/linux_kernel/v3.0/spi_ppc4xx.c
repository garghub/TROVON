static int spi_ppc4xx_txrx(struct spi_device *spi, struct spi_transfer *t)
{
struct ppc4xx_spi *hw;
u8 data;
dev_dbg(&spi->dev, "txrx: tx %p, rx %p, len %d\n",
t->tx_buf, t->rx_buf, t->len);
hw = spi_master_get_devdata(spi->master);
hw->tx = t->tx_buf;
hw->rx = t->rx_buf;
hw->len = t->len;
hw->count = 0;
data = hw->tx ? hw->tx[0] : 0;
out_8(&hw->regs->txd, data);
out_8(&hw->regs->cr, SPI_PPC4XX_CR_STR);
wait_for_completion(&hw->done);
return hw->count;
}
static int spi_ppc4xx_setupxfer(struct spi_device *spi, struct spi_transfer *t)
{
struct ppc4xx_spi *hw = spi_master_get_devdata(spi->master);
struct spi_ppc4xx_cs *cs = spi->controller_state;
int scr;
u8 cdm = 0;
u32 speed;
u8 bits_per_word;
bits_per_word = spi->bits_per_word;
speed = spi->max_speed_hz;
if (t) {
if (t->bits_per_word)
bits_per_word = t->bits_per_word;
if (t->speed_hz)
speed = min(t->speed_hz, spi->max_speed_hz);
}
if (bits_per_word != 8) {
dev_err(&spi->dev, "invalid bits-per-word (%d)\n",
bits_per_word);
return -EINVAL;
}
if (!speed || (speed > spi->max_speed_hz)) {
dev_err(&spi->dev, "invalid speed_hz (%d)\n", speed);
return -EINVAL;
}
out_8(&hw->regs->mode, cs->mode);
scr = (hw->opb_freq / speed) - 1;
if (scr > 0)
cdm = min(scr, 0xff);
dev_dbg(&spi->dev, "setting pre-scaler to %d (hz %d)\n", cdm, speed);
if (in_8(&hw->regs->cdm) != cdm)
out_8(&hw->regs->cdm, cdm);
spin_lock(&hw->bitbang.lock);
if (!hw->bitbang.busy) {
hw->bitbang.chipselect(spi, BITBANG_CS_INACTIVE);
}
spin_unlock(&hw->bitbang.lock);
return 0;
}
static int spi_ppc4xx_setup(struct spi_device *spi)
{
struct spi_ppc4xx_cs *cs = spi->controller_state;
if (spi->bits_per_word != 8) {
dev_err(&spi->dev, "invalid bits-per-word (%d)\n",
spi->bits_per_word);
return -EINVAL;
}
if (!spi->max_speed_hz) {
dev_err(&spi->dev, "invalid max_speed_hz (must be non-zero)\n");
return -EINVAL;
}
if (cs == NULL) {
cs = kzalloc(sizeof *cs, GFP_KERNEL);
if (!cs)
return -ENOMEM;
spi->controller_state = cs;
}
cs->mode = SPI_PPC4XX_MODE_SPE;
switch (spi->mode & (SPI_CPHA | SPI_CPOL)) {
case SPI_MODE_0:
cs->mode |= SPI_CLK_MODE0;
break;
case SPI_MODE_1:
cs->mode |= SPI_CLK_MODE1;
break;
case SPI_MODE_2:
cs->mode |= SPI_CLK_MODE2;
break;
case SPI_MODE_3:
cs->mode |= SPI_CLK_MODE3;
break;
}
if (spi->mode & SPI_LSB_FIRST)
cs->mode |= SPI_PPC4XX_MODE_RD;
return 0;
}
static void spi_ppc4xx_chipsel(struct spi_device *spi, int value)
{
struct ppc4xx_spi *hw = spi_master_get_devdata(spi->master);
unsigned int cs = spi->chip_select;
unsigned int cspol;
if (!hw->master->num_chipselect || hw->gpios[cs] == -EEXIST)
return;
cspol = spi->mode & SPI_CS_HIGH ? 1 : 0;
if (value == BITBANG_CS_INACTIVE)
cspol = !cspol;
gpio_set_value(hw->gpios[cs], cspol);
}
static irqreturn_t spi_ppc4xx_int(int irq, void *dev_id)
{
struct ppc4xx_spi *hw;
u8 status;
u8 data;
unsigned int count;
hw = (struct ppc4xx_spi *)dev_id;
status = in_8(&hw->regs->sr);
if (!status)
return IRQ_NONE;
if (unlikely(status & SPI_PPC4XX_SR_BSY)) {
u8 lstatus;
int cnt = 0;
dev_dbg(hw->dev, "got interrupt but spi still busy?\n");
do {
ndelay(10);
lstatus = in_8(&hw->regs->sr);
} while (++cnt < 100 && lstatus & SPI_PPC4XX_SR_BSY);
if (cnt >= 100) {
dev_err(hw->dev, "busywait: too many loops!\n");
complete(&hw->done);
return IRQ_HANDLED;
} else {
status = in_8(&hw->regs->sr);
dev_dbg(hw->dev, "loops %d status %x\n", cnt, status);
}
}
count = hw->count;
hw->count++;
data = in_8(&hw->regs->rxd);
if (hw->rx)
hw->rx[count] = data;
count++;
if (count < hw->len) {
data = hw->tx ? hw->tx[count] : 0;
out_8(&hw->regs->txd, data);
out_8(&hw->regs->cr, SPI_PPC4XX_CR_STR);
} else {
complete(&hw->done);
}
return IRQ_HANDLED;
}
static void spi_ppc4xx_cleanup(struct spi_device *spi)
{
kfree(spi->controller_state);
}
static void spi_ppc4xx_enable(struct ppc4xx_spi *hw)
{
dcri_clrset(SDR0, SDR0_PFC1, 0x80000000 >> 14, 0);
}
static void free_gpios(struct ppc4xx_spi *hw)
{
if (hw->master->num_chipselect) {
int i;
for (i = 0; i < hw->master->num_chipselect; i++)
if (gpio_is_valid(hw->gpios[i]))
gpio_free(hw->gpios[i]);
kfree(hw->gpios);
hw->gpios = NULL;
}
}
static int __init spi_ppc4xx_of_probe(struct platform_device *op)
{
struct ppc4xx_spi *hw;
struct spi_master *master;
struct spi_bitbang *bbp;
struct resource resource;
struct device_node *np = op->dev.of_node;
struct device *dev = &op->dev;
struct device_node *opbnp;
int ret;
int num_gpios;
const unsigned int *clk;
master = spi_alloc_master(dev, sizeof *hw);
if (master == NULL)
return -ENOMEM;
master->dev.of_node = np;
dev_set_drvdata(dev, master);
hw = spi_master_get_devdata(master);
hw->master = spi_master_get(master);
hw->dev = dev;
init_completion(&hw->done);
num_gpios = of_gpio_count(np);
if (num_gpios) {
int i;
hw->gpios = kzalloc(sizeof(int) * num_gpios, GFP_KERNEL);
if (!hw->gpios) {
ret = -ENOMEM;
goto free_master;
}
for (i = 0; i < num_gpios; i++) {
int gpio;
enum of_gpio_flags flags;
gpio = of_get_gpio_flags(np, i, &flags);
hw->gpios[i] = gpio;
if (gpio_is_valid(gpio)) {
ret = gpio_request(gpio, np->name);
if (ret < 0) {
dev_err(dev, "can't request gpio "
"#%d: %d\n", i, ret);
goto free_gpios;
}
gpio_direction_output(gpio,
!!(flags & OF_GPIO_ACTIVE_LOW));
} else if (gpio == -EEXIST) {
;
} else {
dev_err(dev, "invalid gpio #%d: %d\n", i, gpio);
ret = -EINVAL;
goto free_gpios;
}
}
}
bbp = &hw->bitbang;
bbp->master = hw->master;
bbp->setup_transfer = spi_ppc4xx_setupxfer;
bbp->chipselect = spi_ppc4xx_chipsel;
bbp->txrx_bufs = spi_ppc4xx_txrx;
bbp->use_dma = 0;
bbp->master->setup = spi_ppc4xx_setup;
bbp->master->cleanup = spi_ppc4xx_cleanup;
bbp->master->bus_num = -1;
bbp->master->mode_bits =
SPI_CPHA | SPI_CPOL | SPI_CS_HIGH | SPI_LSB_FIRST;
bbp->master->num_chipselect = num_gpios;
opbnp = of_find_compatible_node(NULL, NULL, "ibm,opb");
if (opbnp == NULL) {
dev_err(dev, "OPB: cannot find node\n");
ret = -ENODEV;
goto free_gpios;
}
clk = of_get_property(opbnp, "clock-frequency", NULL);
if (clk == NULL) {
dev_err(dev, "OPB: no clock-frequency property set\n");
of_node_put(opbnp);
ret = -ENODEV;
goto free_gpios;
}
hw->opb_freq = *clk;
hw->opb_freq >>= 2;
of_node_put(opbnp);
ret = of_address_to_resource(np, 0, &resource);
if (ret) {
dev_err(dev, "error while parsing device node resource\n");
goto free_gpios;
}
hw->mapbase = resource.start;
hw->mapsize = resource.end - resource.start + 1;
if (hw->mapsize < sizeof(struct spi_ppc4xx_regs)) {
dev_err(dev, "too small to map registers\n");
ret = -EINVAL;
goto free_gpios;
}
hw->irqnum = irq_of_parse_and_map(np, 0);
ret = request_irq(hw->irqnum, spi_ppc4xx_int,
IRQF_DISABLED, "spi_ppc4xx_of", (void *)hw);
if (ret) {
dev_err(dev, "unable to allocate interrupt\n");
goto free_gpios;
}
if (!request_mem_region(hw->mapbase, hw->mapsize, DRIVER_NAME)) {
dev_err(dev, "resource unavailable\n");
ret = -EBUSY;
goto request_mem_error;
}
hw->regs = ioremap(hw->mapbase, sizeof(struct spi_ppc4xx_regs));
if (!hw->regs) {
dev_err(dev, "unable to memory map registers\n");
ret = -ENXIO;
goto map_io_error;
}
spi_ppc4xx_enable(hw);
dev->dma_mask = 0;
ret = spi_bitbang_start(bbp);
if (ret) {
dev_err(dev, "failed to register SPI master\n");
goto unmap_regs;
}
dev_info(dev, "driver initialized\n");
return 0;
unmap_regs:
iounmap(hw->regs);
map_io_error:
release_mem_region(hw->mapbase, hw->mapsize);
request_mem_error:
free_irq(hw->irqnum, hw);
free_gpios:
free_gpios(hw);
free_master:
dev_set_drvdata(dev, NULL);
spi_master_put(master);
dev_err(dev, "initialization failed\n");
return ret;
}
static int __exit spi_ppc4xx_of_remove(struct platform_device *op)
{
struct spi_master *master = dev_get_drvdata(&op->dev);
struct ppc4xx_spi *hw = spi_master_get_devdata(master);
spi_bitbang_stop(&hw->bitbang);
dev_set_drvdata(&op->dev, NULL);
release_mem_region(hw->mapbase, hw->mapsize);
free_irq(hw->irqnum, hw);
iounmap(hw->regs);
free_gpios(hw);
return 0;
}
static int __init spi_ppc4xx_init(void)
{
return platform_driver_register(&spi_ppc4xx_of_driver);
}
static void __exit spi_ppc4xx_exit(void)
{
platform_driver_unregister(&spi_ppc4xx_of_driver);
}
