static int mpc52xx_psc_spi_transfer_setup(struct spi_device *spi,
struct spi_transfer *t)
{
struct mpc52xx_psc_spi_cs *cs = spi->controller_state;
cs->speed_hz = (t && t->speed_hz)
? t->speed_hz : spi->max_speed_hz;
cs->bits_per_word = (t && t->bits_per_word)
? t->bits_per_word : spi->bits_per_word;
cs->bits_per_word = ((cs->bits_per_word + 7) / 8) * 8;
return 0;
}
static void mpc52xx_psc_spi_activate_cs(struct spi_device *spi)
{
struct mpc52xx_psc_spi_cs *cs = spi->controller_state;
struct mpc52xx_psc_spi *mps = spi_master_get_devdata(spi->master);
struct mpc52xx_psc __iomem *psc = mps->psc;
u32 sicr;
u16 ccr;
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
ccr = in_be16((u16 __iomem *)&psc->ccr);
ccr &= 0xFF00;
if (cs->speed_hz)
ccr |= (MCLK / cs->speed_hz - 1) & 0xFF;
else
ccr |= (MCLK / 1000000 - 1) & 0xFF;
out_be16((u16 __iomem *)&psc->ccr, ccr);
mps->bits_per_word = cs->bits_per_word;
if (mps->cs_control)
mps->cs_control(spi, (spi->mode & SPI_CS_HIGH) ? 1 : 0);
}
static void mpc52xx_psc_spi_deactivate_cs(struct spi_device *spi)
{
struct mpc52xx_psc_spi *mps = spi_master_get_devdata(spi->master);
if (mps->cs_control)
mps->cs_control(spi, (spi->mode & SPI_CS_HIGH) ? 0 : 1);
}
static int mpc52xx_psc_spi_transfer_rxtx(struct spi_device *spi,
struct spi_transfer *t)
{
struct mpc52xx_psc_spi *mps = spi_master_get_devdata(spi->master);
struct mpc52xx_psc __iomem *psc = mps->psc;
struct mpc52xx_psc_fifo __iomem *fifo = mps->fifo;
unsigned rb = 0;
unsigned sb = 0;
unsigned char *rx_buf = (unsigned char *)t->rx_buf;
unsigned char *tx_buf = (unsigned char *)t->tx_buf;
unsigned rfalarm;
unsigned send_at_once = MPC52xx_PSC_BUFSIZE;
unsigned recv_at_once;
int last_block = 0;
if (!t->tx_buf && !t->rx_buf && t->len)
return -EINVAL;
out_8(&psc->command, MPC52xx_PSC_TX_ENABLE | MPC52xx_PSC_RX_ENABLE);
while (rb < t->len) {
if (t->len - rb > MPC52xx_PSC_BUFSIZE) {
rfalarm = MPC52xx_PSC_RFALARM;
last_block = 0;
} else {
send_at_once = t->len - sb;
rfalarm = MPC52xx_PSC_BUFSIZE - (t->len - rb);
last_block = 1;
}
dev_dbg(&spi->dev, "send %d bytes...\n", send_at_once);
for (; send_at_once; sb++, send_at_once--) {
if (send_at_once == 1 && last_block)
out_8(&psc->ircr2, 0x01);
if (tx_buf)
out_8(&psc->mpc52xx_psc_buffer_8, tx_buf[sb]);
else
out_8(&psc->mpc52xx_psc_buffer_8, 0);
}
out_8(&psc->command, MPC52xx_PSC_SEL_MODE_REG_1);
if (t->len - rb == 1) {
out_8(&psc->mode, 0);
} else {
out_8(&psc->mode, MPC52xx_PSC_MODE_FFULL);
out_be16(&fifo->rfalarm, rfalarm);
}
out_be16(&psc->mpc52xx_psc_imr, MPC52xx_PSC_IMR_RXRDY);
wait_for_completion(&mps->done);
recv_at_once = in_be16(&fifo->rfnum);
dev_dbg(&spi->dev, "%d bytes received\n", recv_at_once);
send_at_once = recv_at_once;
if (rx_buf) {
for (; recv_at_once; rb++, recv_at_once--)
rx_buf[rb] = in_8(&psc->mpc52xx_psc_buffer_8);
} else {
for (; recv_at_once; rb++, recv_at_once--)
in_8(&psc->mpc52xx_psc_buffer_8);
}
}
out_8(&psc->command, MPC52xx_PSC_TX_DISABLE | MPC52xx_PSC_RX_DISABLE);
return 0;
}
static void mpc52xx_psc_spi_work(struct work_struct *work)
{
struct mpc52xx_psc_spi *mps =
container_of(work, struct mpc52xx_psc_spi, work);
spin_lock_irq(&mps->lock);
mps->busy = 1;
while (!list_empty(&mps->queue)) {
struct spi_message *m;
struct spi_device *spi;
struct spi_transfer *t = NULL;
unsigned cs_change;
int status;
m = container_of(mps->queue.next, struct spi_message, queue);
list_del_init(&m->queue);
spin_unlock_irq(&mps->lock);
spi = m->spi;
cs_change = 1;
status = 0;
list_for_each_entry (t, &m->transfers, transfer_list) {
if (t->bits_per_word || t->speed_hz) {
status = mpc52xx_psc_spi_transfer_setup(spi, t);
if (status < 0)
break;
}
if (cs_change)
mpc52xx_psc_spi_activate_cs(spi);
cs_change = t->cs_change;
status = mpc52xx_psc_spi_transfer_rxtx(spi, t);
if (status)
break;
m->actual_length += t->len;
if (t->delay_usecs)
udelay(t->delay_usecs);
if (cs_change)
mpc52xx_psc_spi_deactivate_cs(spi);
}
m->status = status;
m->complete(m->context);
if (status || !cs_change)
mpc52xx_psc_spi_deactivate_cs(spi);
mpc52xx_psc_spi_transfer_setup(spi, NULL);
spin_lock_irq(&mps->lock);
}
mps->busy = 0;
spin_unlock_irq(&mps->lock);
}
static int mpc52xx_psc_spi_setup(struct spi_device *spi)
{
struct mpc52xx_psc_spi *mps = spi_master_get_devdata(spi->master);
struct mpc52xx_psc_spi_cs *cs = spi->controller_state;
unsigned long flags;
if (spi->bits_per_word%8)
return -EINVAL;
if (!cs) {
cs = kzalloc(sizeof *cs, GFP_KERNEL);
if (!cs)
return -ENOMEM;
spi->controller_state = cs;
}
cs->bits_per_word = spi->bits_per_word;
cs->speed_hz = spi->max_speed_hz;
spin_lock_irqsave(&mps->lock, flags);
if (!mps->busy)
mpc52xx_psc_spi_deactivate_cs(spi);
spin_unlock_irqrestore(&mps->lock, flags);
return 0;
}
static int mpc52xx_psc_spi_transfer(struct spi_device *spi,
struct spi_message *m)
{
struct mpc52xx_psc_spi *mps = spi_master_get_devdata(spi->master);
unsigned long flags;
m->actual_length = 0;
m->status = -EINPROGRESS;
spin_lock_irqsave(&mps->lock, flags);
list_add_tail(&m->queue, &mps->queue);
queue_work(mps->workqueue, &mps->work);
spin_unlock_irqrestore(&mps->lock, flags);
return 0;
}
static void mpc52xx_psc_spi_cleanup(struct spi_device *spi)
{
kfree(spi->controller_state);
}
static int mpc52xx_psc_spi_port_config(int psc_id, struct mpc52xx_psc_spi *mps)
{
struct mpc52xx_psc __iomem *psc = mps->psc;
struct mpc52xx_psc_fifo __iomem *fifo = mps->fifo;
u32 mclken_div;
int ret;
mclken_div = (mps->sysclk ? mps->sysclk : 512000000) / MCLK;
ret = mpc52xx_set_psc_clkdiv(psc_id, mclken_div);
if (ret)
return ret;
out_8(&psc->command, MPC52xx_PSC_RST_RX);
out_8(&psc->command, MPC52xx_PSC_RST_TX);
out_8(&psc->command, MPC52xx_PSC_TX_DISABLE | MPC52xx_PSC_RX_DISABLE);
out_be16(&psc->mpc52xx_psc_imr, 0);
out_8(&psc->command, MPC52xx_PSC_SEL_MODE_REG_1);
out_8(&fifo->rfcntl, 0);
out_8(&psc->mode, MPC52xx_PSC_MODE_FFULL);
out_be32(&psc->sicr, 0x0180C800);
out_be16((u16 __iomem *)&psc->ccr, 0x070F);
out_8(&psc->ctur, 0x00);
out_8(&psc->ctlr, 0x84);
mps->bits_per_word = 8;
return 0;
}
static irqreturn_t mpc52xx_psc_spi_isr(int irq, void *dev_id)
{
struct mpc52xx_psc_spi *mps = (struct mpc52xx_psc_spi *)dev_id;
struct mpc52xx_psc __iomem *psc = mps->psc;
if (in_be16(&psc->mpc52xx_psc_isr) & MPC52xx_PSC_IMR_RXRDY) {
out_be16(&psc->mpc52xx_psc_imr, 0);
complete(&mps->done);
return IRQ_HANDLED;
}
return IRQ_NONE;
}
static int __devinit mpc52xx_psc_spi_do_probe(struct device *dev, u32 regaddr,
u32 size, unsigned int irq, s16 bus_num)
{
struct fsl_spi_platform_data *pdata = dev->platform_data;
struct mpc52xx_psc_spi *mps;
struct spi_master *master;
int ret;
master = spi_alloc_master(dev, sizeof *mps);
if (master == NULL)
return -ENOMEM;
dev_set_drvdata(dev, master);
mps = spi_master_get_devdata(master);
master->mode_bits = SPI_CPOL | SPI_CPHA | SPI_CS_HIGH | SPI_LSB_FIRST;
mps->irq = irq;
if (pdata == NULL) {
dev_warn(dev, "probe called without platform data, no "
"cs_control function will be called\n");
mps->cs_control = NULL;
mps->sysclk = 0;
master->bus_num = bus_num;
master->num_chipselect = 255;
} else {
mps->cs_control = pdata->cs_control;
mps->sysclk = pdata->sysclk;
master->bus_num = pdata->bus_num;
master->num_chipselect = pdata->max_chipselect;
}
master->setup = mpc52xx_psc_spi_setup;
master->transfer = mpc52xx_psc_spi_transfer;
master->cleanup = mpc52xx_psc_spi_cleanup;
master->dev.of_node = dev->of_node;
mps->psc = ioremap(regaddr, size);
if (!mps->psc) {
dev_err(dev, "could not ioremap I/O port range\n");
ret = -EFAULT;
goto free_master;
}
mps->fifo = ((void __iomem *)mps->psc) + sizeof(struct mpc52xx_psc);
ret = request_irq(mps->irq, mpc52xx_psc_spi_isr, 0, "mpc52xx-psc-spi",
mps);
if (ret)
goto free_master;
ret = mpc52xx_psc_spi_port_config(master->bus_num, mps);
if (ret < 0) {
dev_err(dev, "can't configure PSC! Is it capable of SPI?\n");
goto free_irq;
}
spin_lock_init(&mps->lock);
init_completion(&mps->done);
INIT_WORK(&mps->work, mpc52xx_psc_spi_work);
INIT_LIST_HEAD(&mps->queue);
mps->workqueue = create_singlethread_workqueue(
dev_name(master->dev.parent));
if (mps->workqueue == NULL) {
ret = -EBUSY;
goto free_irq;
}
ret = spi_register_master(master);
if (ret < 0)
goto unreg_master;
return ret;
unreg_master:
destroy_workqueue(mps->workqueue);
free_irq:
free_irq(mps->irq, mps);
free_master:
if (mps->psc)
iounmap(mps->psc);
spi_master_put(master);
return ret;
}
static int __devinit mpc52xx_psc_spi_of_probe(struct platform_device *op)
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
if (op->dev.platform_data == NULL) {
const u32 *psc_nump;
psc_nump = of_get_property(op->dev.of_node, "cell-index", NULL);
if (!psc_nump || *psc_nump > 5) {
dev_err(&op->dev, "Invalid cell-index property\n");
return -EINVAL;
}
id = *psc_nump + 1;
}
return mpc52xx_psc_spi_do_probe(&op->dev, (u32)regaddr64, (u32)size64,
irq_of_parse_and_map(op->dev.of_node, 0), id);
}
static int __devexit mpc52xx_psc_spi_of_remove(struct platform_device *op)
{
struct spi_master *master = dev_get_drvdata(&op->dev);
struct mpc52xx_psc_spi *mps = spi_master_get_devdata(master);
flush_workqueue(mps->workqueue);
destroy_workqueue(mps->workqueue);
spi_unregister_master(master);
free_irq(mps->irq, mps);
if (mps->psc)
iounmap(mps->psc);
return 0;
}
