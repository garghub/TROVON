static int mpc512x_psc_spi_transfer_setup(struct spi_device *spi,
struct spi_transfer *t)
{
struct mpc512x_psc_spi_cs *cs = spi->controller_state;
cs->speed_hz = (t && t->speed_hz)
? t->speed_hz : spi->max_speed_hz;
cs->bits_per_word = (t && t->bits_per_word)
? t->bits_per_word : spi->bits_per_word;
cs->bits_per_word = ((cs->bits_per_word + 7) / 8) * 8;
return 0;
}
static void mpc512x_psc_spi_activate_cs(struct spi_device *spi)
{
struct mpc512x_psc_spi_cs *cs = spi->controller_state;
struct mpc512x_psc_spi *mps = spi_master_get_devdata(spi->master);
struct mpc52xx_psc __iomem *psc = mps->psc;
u32 sicr;
u32 ccr;
u16 bclkdiv;
sicr = in_be32(&psc->sicr);
if (spi->mode & SPI_CPHA)
sicr |= 0x00001000;
else
sicr &= ~0x00001000;
if (spi->mode & SPI_CPOL)
sicr |= 0x00002000;
else
sicr &= ~0x00002000;
if (spi->mode & SPI_LSB_FIRST)
sicr |= 0x10000000;
else
sicr &= ~0x10000000;
out_be32(&psc->sicr, sicr);
ccr = in_be32(&psc->ccr);
ccr &= 0xFF000000;
if (cs->speed_hz)
bclkdiv = (mps->mclk / cs->speed_hz) - 1;
else
bclkdiv = (mps->mclk / 1000000) - 1;
ccr |= (((bclkdiv & 0xff) << 16) | (((bclkdiv >> 8) & 0xff) << 8));
out_be32(&psc->ccr, ccr);
mps->bits_per_word = cs->bits_per_word;
if (mps->cs_control && gpio_is_valid(spi->cs_gpio))
mps->cs_control(spi, (spi->mode & SPI_CS_HIGH) ? 1 : 0);
}
static void mpc512x_psc_spi_deactivate_cs(struct spi_device *spi)
{
struct mpc512x_psc_spi *mps = spi_master_get_devdata(spi->master);
if (mps->cs_control && gpio_is_valid(spi->cs_gpio))
mps->cs_control(spi, (spi->mode & SPI_CS_HIGH) ? 0 : 1);
}
static int mpc512x_psc_spi_transfer_rxtx(struct spi_device *spi,
struct spi_transfer *t)
{
struct mpc512x_psc_spi *mps = spi_master_get_devdata(spi->master);
struct mpc512x_psc_fifo __iomem *fifo = mps->fifo;
size_t tx_len = t->len;
size_t rx_len = t->len;
u8 *tx_buf = (u8 *)t->tx_buf;
u8 *rx_buf = (u8 *)t->rx_buf;
if (!tx_buf && !rx_buf && t->len)
return -EINVAL;
while (rx_len || tx_len) {
size_t txcount;
u8 data;
size_t fifosz;
size_t rxcount;
int rxtries;
fifosz = MPC512x_PSC_FIFO_SZ(in_be32(&fifo->txsz));
txcount = min(fifosz, tx_len);
fifosz = MPC512x_PSC_FIFO_SZ(in_be32(&fifo->rxsz));
fifosz -= in_be32(&fifo->rxcnt) + 1;
txcount = min(fifosz, txcount);
if (txcount) {
while (txcount-- > 0) {
data = tx_buf ? *tx_buf++ : 0;
if (tx_len == EOFBYTE && t->cs_change)
setbits32(&fifo->txcmd,
MPC512x_PSC_FIFO_EOF);
out_8(&fifo->txdata_8, data);
tx_len--;
}
INIT_COMPLETION(mps->txisrdone);
out_be32(&fifo->txisr, MPC512x_PSC_FIFO_EMPTY);
out_be32(&fifo->tximr, MPC512x_PSC_FIFO_EMPTY);
wait_for_completion(&mps->txisrdone);
}
rxtries = 50;
do {
fifosz = in_be32(&fifo->rxcnt);
rxcount = min(fifosz, rx_len);
while (rxcount-- > 0) {
data = in_8(&fifo->rxdata_8);
if (rx_buf)
*rx_buf++ = data;
rx_len--;
}
if (tx_len)
break;
if (!rx_len)
break;
usleep_range(10, 100);
} while (--rxtries > 0);
if (!tx_len && rx_len && !rxtries) {
rxcount = in_be32(&fifo->rxcnt);
dev_warn(&spi->dev,
"short xfer, missing %zd RX bytes, FIFO level %zd\n",
rx_len, rxcount);
}
if (!tx_len && !rx_len) {
while (in_be32(&fifo->rxcnt))
in_8(&fifo->rxdata_8);
}
}
return 0;
}
static int mpc512x_psc_spi_msg_xfer(struct spi_master *master,
struct spi_message *m)
{
struct spi_device *spi;
unsigned cs_change;
int status;
struct spi_transfer *t;
spi = m->spi;
cs_change = 1;
status = 0;
list_for_each_entry(t, &m->transfers, transfer_list) {
if (t->bits_per_word || t->speed_hz) {
status = mpc512x_psc_spi_transfer_setup(spi, t);
if (status < 0)
break;
}
if (cs_change)
mpc512x_psc_spi_activate_cs(spi);
cs_change = t->cs_change;
status = mpc512x_psc_spi_transfer_rxtx(spi, t);
if (status)
break;
m->actual_length += t->len;
if (t->delay_usecs)
udelay(t->delay_usecs);
if (cs_change)
mpc512x_psc_spi_deactivate_cs(spi);
}
m->status = status;
m->complete(m->context);
if (status || !cs_change)
mpc512x_psc_spi_deactivate_cs(spi);
mpc512x_psc_spi_transfer_setup(spi, NULL);
spi_finalize_current_message(master);
return status;
}
static int mpc512x_psc_spi_prep_xfer_hw(struct spi_master *master)
{
struct mpc512x_psc_spi *mps = spi_master_get_devdata(master);
struct mpc52xx_psc __iomem *psc = mps->psc;
dev_dbg(&master->dev, "%s()\n", __func__);
in_8(&psc->mode);
out_8(&psc->mode, 0x0);
out_8(&psc->command, MPC52xx_PSC_TX_ENABLE | MPC52xx_PSC_RX_ENABLE);
return 0;
}
static int mpc512x_psc_spi_unprep_xfer_hw(struct spi_master *master)
{
struct mpc512x_psc_spi *mps = spi_master_get_devdata(master);
struct mpc52xx_psc __iomem *psc = mps->psc;
struct mpc512x_psc_fifo __iomem *fifo = mps->fifo;
dev_dbg(&master->dev, "%s()\n", __func__);
out_8(&psc->command, MPC52xx_PSC_TX_DISABLE | MPC52xx_PSC_RX_DISABLE);
out_be32(&fifo->tximr, 0);
return 0;
}
static int mpc512x_psc_spi_setup(struct spi_device *spi)
{
struct mpc512x_psc_spi_cs *cs = spi->controller_state;
int ret;
if (spi->bits_per_word % 8)
return -EINVAL;
if (!cs) {
cs = kzalloc(sizeof *cs, GFP_KERNEL);
if (!cs)
return -ENOMEM;
if (gpio_is_valid(spi->cs_gpio)) {
ret = gpio_request(spi->cs_gpio, dev_name(&spi->dev));
if (ret) {
dev_err(&spi->dev, "can't get CS gpio: %d\n",
ret);
kfree(cs);
return ret;
}
gpio_direction_output(spi->cs_gpio,
spi->mode & SPI_CS_HIGH ? 0 : 1);
}
spi->controller_state = cs;
}
cs->bits_per_word = spi->bits_per_word;
cs->speed_hz = spi->max_speed_hz;
return 0;
}
static void mpc512x_psc_spi_cleanup(struct spi_device *spi)
{
if (gpio_is_valid(spi->cs_gpio))
gpio_free(spi->cs_gpio);
kfree(spi->controller_state);
}
static int mpc512x_psc_spi_port_config(struct spi_master *master,
struct mpc512x_psc_spi *mps)
{
struct mpc52xx_psc __iomem *psc = mps->psc;
struct mpc512x_psc_fifo __iomem *fifo = mps->fifo;
struct clk *spiclk;
int ret = 0;
char name[32];
u32 sicr;
u32 ccr;
u16 bclkdiv;
sprintf(name, "psc%d_mclk", master->bus_num);
spiclk = clk_get(&master->dev, name);
clk_enable(spiclk);
mps->mclk = clk_get_rate(spiclk);
clk_put(spiclk);
out_8(&psc->command, MPC52xx_PSC_RST_RX);
out_8(&psc->command, MPC52xx_PSC_RST_TX);
out_8(&psc->command, MPC52xx_PSC_TX_DISABLE | MPC52xx_PSC_RX_DISABLE);
out_be16(&psc->isr_imr.imr, 0);
out_be32(&fifo->tximr, 0);
out_be32(&fifo->rximr, 0);
sicr = 0x01000000 |
0x00800000 |
0x00008000 |
0x00004000 |
0x00000800;
out_be32(&psc->sicr, sicr);
ccr = in_be32(&psc->ccr);
ccr &= 0xFF000000;
bclkdiv = (mps->mclk / 1000000) - 1;
ccr |= (((bclkdiv & 0xff) << 16) | (((bclkdiv >> 8) & 0xff) << 8));
out_be32(&psc->ccr, ccr);
out_8(&psc->ctur, 0x00);
out_8(&psc->ctlr, 0x82);
out_be32(&fifo->rxalarm, 0xfff);
out_be32(&fifo->txalarm, 0);
out_be32(&fifo->rxcmd,
MPC512x_PSC_FIFO_ENABLE_SLICE | MPC512x_PSC_FIFO_ENABLE_DMA);
out_be32(&fifo->txcmd,
MPC512x_PSC_FIFO_ENABLE_SLICE | MPC512x_PSC_FIFO_ENABLE_DMA);
mps->bits_per_word = 8;
return ret;
}
static irqreturn_t mpc512x_psc_spi_isr(int irq, void *dev_id)
{
struct mpc512x_psc_spi *mps = (struct mpc512x_psc_spi *)dev_id;
struct mpc512x_psc_fifo __iomem *fifo = mps->fifo;
if (in_be32(&fifo->txisr) &
in_be32(&fifo->tximr) & MPC512x_PSC_FIFO_EMPTY) {
out_be32(&fifo->txisr, MPC512x_PSC_FIFO_EMPTY);
out_be32(&fifo->tximr, 0);
complete(&mps->txisrdone);
return IRQ_HANDLED;
}
return IRQ_NONE;
}
static void mpc512x_spi_cs_control(struct spi_device *spi, bool onoff)
{
gpio_set_value(spi->cs_gpio, onoff);
}
static int mpc512x_psc_spi_do_probe(struct device *dev, u32 regaddr,
u32 size, unsigned int irq,
s16 bus_num)
{
struct fsl_spi_platform_data *pdata = dev->platform_data;
struct mpc512x_psc_spi *mps;
struct spi_master *master;
int ret;
void *tempp;
master = spi_alloc_master(dev, sizeof *mps);
if (master == NULL)
return -ENOMEM;
dev_set_drvdata(dev, master);
mps = spi_master_get_devdata(master);
mps->irq = irq;
if (pdata == NULL) {
mps->cs_control = mpc512x_spi_cs_control;
master->bus_num = bus_num;
} else {
mps->cs_control = pdata->cs_control;
master->bus_num = pdata->bus_num;
master->num_chipselect = pdata->max_chipselect;
}
master->mode_bits = SPI_CPOL | SPI_CPHA | SPI_CS_HIGH | SPI_LSB_FIRST;
master->setup = mpc512x_psc_spi_setup;
master->prepare_transfer_hardware = mpc512x_psc_spi_prep_xfer_hw;
master->transfer_one_message = mpc512x_psc_spi_msg_xfer;
master->unprepare_transfer_hardware = mpc512x_psc_spi_unprep_xfer_hw;
master->cleanup = mpc512x_psc_spi_cleanup;
master->dev.of_node = dev->of_node;
tempp = ioremap(regaddr, size);
if (!tempp) {
dev_err(dev, "could not ioremap I/O port range\n");
ret = -EFAULT;
goto free_master;
}
mps->psc = tempp;
mps->fifo =
(struct mpc512x_psc_fifo *)(tempp + sizeof(struct mpc52xx_psc));
ret = request_irq(mps->irq, mpc512x_psc_spi_isr, IRQF_SHARED,
"mpc512x-psc-spi", mps);
if (ret)
goto free_master;
init_completion(&mps->txisrdone);
ret = mpc512x_psc_spi_port_config(master, mps);
if (ret < 0)
goto free_irq;
ret = spi_register_master(master);
if (ret < 0)
goto free_irq;
return ret;
free_irq:
free_irq(mps->irq, mps);
free_master:
if (mps->psc)
iounmap(mps->psc);
spi_master_put(master);
return ret;
}
static int mpc512x_psc_spi_do_remove(struct device *dev)
{
struct spi_master *master = spi_master_get(dev_get_drvdata(dev));
struct mpc512x_psc_spi *mps = spi_master_get_devdata(master);
spi_unregister_master(master);
free_irq(mps->irq, mps);
if (mps->psc)
iounmap(mps->psc);
spi_master_put(master);
return 0;
}
static int mpc512x_psc_spi_of_probe(struct platform_device *op)
{
const u32 *regaddr_p;
u64 regaddr64, size64;
s16 id = -1;
regaddr_p = of_get_address(op->dev.of_node, 0, &size64, NULL);
if (!regaddr_p) {
dev_err(&op->dev, "Invalid PSC address\n");
return -EINVAL;
}
regaddr64 = of_translate_address(op->dev.of_node, regaddr_p);
id = of_alias_get_id(op->dev.of_node, "spi");
if (id < 0) {
dev_err(&op->dev, "no alias id for %s\n",
op->dev.of_node->full_name);
return id;
}
return mpc512x_psc_spi_do_probe(&op->dev, (u32) regaddr64, (u32) size64,
irq_of_parse_and_map(op->dev.of_node, 0), id);
}
static int mpc512x_psc_spi_of_remove(struct platform_device *op)
{
return mpc512x_psc_spi_do_remove(&op->dev);
}
