static void mpc52xx_spi_chipsel(struct mpc52xx_spi *ms, int value)
{
int cs;
if (ms->gpio_cs_count > 0) {
cs = ms->message->spi->chip_select;
gpio_set_value(ms->gpio_cs[cs], value ? 0 : 1);
} else
out_8(ms->regs + SPI_PORTDATA, value ? 0 : 0x08);
}
static void mpc52xx_spi_start_transfer(struct mpc52xx_spi *ms)
{
ms->rx_buf = ms->transfer->rx_buf;
ms->tx_buf = ms->transfer->tx_buf;
ms->len = ms->transfer->len;
if (ms->cs_change)
mpc52xx_spi_chipsel(ms, 1);
ms->cs_change = ms->transfer->cs_change;
ms->wcol_tx_timestamp = get_tbl();
if (ms->tx_buf)
out_8(ms->regs + SPI_DATA, *ms->tx_buf++);
else
out_8(ms->regs + SPI_DATA, 0);
}
static int
mpc52xx_spi_fsmstate_idle(int irq, struct mpc52xx_spi *ms, u8 status, u8 data)
{
struct spi_device *spi;
int spr, sppr;
u8 ctrl1;
if (status && (irq != NO_IRQ))
dev_err(&ms->master->dev, "spurious irq, status=0x%.2x\n",
status);
if (list_empty(&ms->queue))
return FSM_STOP;
ms->message = list_first_entry(&ms->queue, struct spi_message, queue);
list_del_init(&ms->message->queue);
ctrl1 = SPI_CTRL1_SPIE | SPI_CTRL1_SPE | SPI_CTRL1_MSTR;
spi = ms->message->spi;
if (spi->mode & SPI_CPHA)
ctrl1 |= SPI_CTRL1_CPHA;
if (spi->mode & SPI_CPOL)
ctrl1 |= SPI_CTRL1_CPOL;
if (spi->mode & SPI_LSB_FIRST)
ctrl1 |= SPI_CTRL1_LSBFE;
out_8(ms->regs + SPI_CTRL1, ctrl1);
sppr = ((ms->ipb_freq / ms->message->spi->max_speed_hz) + 1) >> 1;
spr = 0;
if (sppr < 1)
sppr = 1;
while (((sppr - 1) & ~0x7) != 0) {
sppr = (sppr + 1) >> 1;
spr++;
}
sppr--;
if (spr > 7) {
spr = 7;
sppr = 7;
}
out_8(ms->regs + SPI_BRR, sppr << 4 | spr);
ms->cs_change = 1;
ms->transfer = container_of(ms->message->transfers.next,
struct spi_transfer, transfer_list);
mpc52xx_spi_start_transfer(ms);
ms->state = mpc52xx_spi_fsmstate_transfer;
return FSM_CONTINUE;
}
static int mpc52xx_spi_fsmstate_transfer(int irq, struct mpc52xx_spi *ms,
u8 status, u8 data)
{
if (!status)
return ms->irq0 ? FSM_STOP : FSM_POLL;
if (status & SPI_STATUS_WCOL) {
ms->wcol_count++;
ms->wcol_ticks += get_tbl() - ms->wcol_tx_timestamp;
ms->wcol_tx_timestamp = get_tbl();
data = 0;
if (ms->tx_buf)
data = *(ms->tx_buf - 1);
out_8(ms->regs + SPI_DATA, data);
return FSM_CONTINUE;
} else if (status & SPI_STATUS_MODF) {
ms->modf_count++;
dev_err(&ms->master->dev, "mode fault\n");
mpc52xx_spi_chipsel(ms, 0);
ms->message->status = -EIO;
if (ms->message->complete)
ms->message->complete(ms->message->context);
ms->state = mpc52xx_spi_fsmstate_idle;
return FSM_CONTINUE;
}
ms->byte_count++;
if (ms->rx_buf)
*ms->rx_buf++ = data;
ms->len--;
if (ms->len == 0) {
ms->timestamp = get_tbl();
ms->timestamp += ms->transfer->delay_usecs * tb_ticks_per_usec;
ms->state = mpc52xx_spi_fsmstate_wait;
return FSM_CONTINUE;
}
ms->wcol_tx_timestamp = get_tbl();
if (ms->tx_buf)
out_8(ms->regs + SPI_DATA, *ms->tx_buf++);
else
out_8(ms->regs + SPI_DATA, 0);
return FSM_CONTINUE;
}
static int
mpc52xx_spi_fsmstate_wait(int irq, struct mpc52xx_spi *ms, u8 status, u8 data)
{
if (status && irq)
dev_err(&ms->master->dev, "spurious irq, status=0x%.2x\n",
status);
if (((int)get_tbl()) - ms->timestamp < 0)
return FSM_POLL;
ms->message->actual_length += ms->transfer->len;
if (ms->transfer->transfer_list.next == &ms->message->transfers) {
ms->msg_count++;
mpc52xx_spi_chipsel(ms, 0);
ms->message->status = 0;
if (ms->message->complete)
ms->message->complete(ms->message->context);
ms->state = mpc52xx_spi_fsmstate_idle;
return FSM_CONTINUE;
}
if (ms->cs_change)
mpc52xx_spi_chipsel(ms, 0);
ms->transfer = container_of(ms->transfer->transfer_list.next,
struct spi_transfer, transfer_list);
mpc52xx_spi_start_transfer(ms);
ms->state = mpc52xx_spi_fsmstate_transfer;
return FSM_CONTINUE;
}
static void mpc52xx_spi_fsm_process(int irq, struct mpc52xx_spi *ms)
{
int rc = FSM_CONTINUE;
u8 status, data;
while (rc == FSM_CONTINUE) {
status = in_8(ms->regs + SPI_STATUS);
data = in_8(ms->regs + SPI_DATA);
rc = ms->state(irq, ms, status, data);
}
if (rc == FSM_POLL)
schedule_work(&ms->work);
}
static irqreturn_t mpc52xx_spi_irq(int irq, void *_ms)
{
struct mpc52xx_spi *ms = _ms;
spin_lock(&ms->lock);
mpc52xx_spi_fsm_process(irq, ms);
spin_unlock(&ms->lock);
return IRQ_HANDLED;
}
static void mpc52xx_spi_wq(struct work_struct *work)
{
struct mpc52xx_spi *ms = container_of(work, struct mpc52xx_spi, work);
unsigned long flags;
spin_lock_irqsave(&ms->lock, flags);
mpc52xx_spi_fsm_process(0, ms);
spin_unlock_irqrestore(&ms->lock, flags);
}
static int mpc52xx_spi_transfer(struct spi_device *spi, struct spi_message *m)
{
struct mpc52xx_spi *ms = spi_master_get_devdata(spi->master);
unsigned long flags;
m->actual_length = 0;
m->status = -EINPROGRESS;
spin_lock_irqsave(&ms->lock, flags);
list_add_tail(&m->queue, &ms->queue);
spin_unlock_irqrestore(&ms->lock, flags);
schedule_work(&ms->work);
return 0;
}
static int mpc52xx_spi_probe(struct platform_device *op)
{
struct spi_master *master;
struct mpc52xx_spi *ms;
void __iomem *regs;
u8 ctrl1;
int rc, i = 0;
int gpio_cs;
dev_dbg(&op->dev, "probing mpc5200 SPI device\n");
regs = of_iomap(op->dev.of_node, 0);
if (!regs)
return -ENODEV;
ctrl1 = SPI_CTRL1_SPIE | SPI_CTRL1_SPE | SPI_CTRL1_MSTR;
out_8(regs + SPI_CTRL1, ctrl1);
out_8(regs + SPI_CTRL2, 0x0);
out_8(regs + SPI_DATADIR, 0xe);
out_8(regs + SPI_PORTDATA, 0x8);
in_8(regs + SPI_STATUS);
out_8(regs + SPI_CTRL1, ctrl1);
in_8(regs + SPI_DATA);
if (in_8(regs + SPI_STATUS) & SPI_STATUS_MODF) {
dev_err(&op->dev, "mode fault; is port_config correct?\n");
rc = -EIO;
goto err_init;
}
dev_dbg(&op->dev, "allocating spi_master struct\n");
master = spi_alloc_master(&op->dev, sizeof *ms);
if (!master) {
rc = -ENOMEM;
goto err_alloc;
}
master->transfer = mpc52xx_spi_transfer;
master->mode_bits = SPI_CPOL | SPI_CPHA | SPI_LSB_FIRST;
master->bits_per_word_mask = SPI_BPW_MASK(8);
master->dev.of_node = op->dev.of_node;
platform_set_drvdata(op, master);
ms = spi_master_get_devdata(master);
ms->master = master;
ms->regs = regs;
ms->irq0 = irq_of_parse_and_map(op->dev.of_node, 0);
ms->irq1 = irq_of_parse_and_map(op->dev.of_node, 1);
ms->state = mpc52xx_spi_fsmstate_idle;
ms->ipb_freq = mpc5xxx_get_bus_frequency(op->dev.of_node);
ms->gpio_cs_count = of_gpio_count(op->dev.of_node);
if (ms->gpio_cs_count > 0) {
master->num_chipselect = ms->gpio_cs_count;
ms->gpio_cs = kmalloc(ms->gpio_cs_count * sizeof(unsigned int),
GFP_KERNEL);
if (!ms->gpio_cs) {
rc = -ENOMEM;
goto err_alloc_gpio;
}
for (i = 0; i < ms->gpio_cs_count; i++) {
gpio_cs = of_get_gpio(op->dev.of_node, i);
if (gpio_cs < 0) {
dev_err(&op->dev,
"could not parse the gpio field "
"in oftree\n");
rc = -ENODEV;
goto err_gpio;
}
rc = gpio_request(gpio_cs, dev_name(&op->dev));
if (rc) {
dev_err(&op->dev,
"can't request spi cs gpio #%d "
"on gpio line %d\n", i, gpio_cs);
goto err_gpio;
}
gpio_direction_output(gpio_cs, 1);
ms->gpio_cs[i] = gpio_cs;
}
}
spin_lock_init(&ms->lock);
INIT_LIST_HEAD(&ms->queue);
INIT_WORK(&ms->work, mpc52xx_spi_wq);
if (ms->irq0 && ms->irq1) {
rc = request_irq(ms->irq0, mpc52xx_spi_irq, 0,
"mpc5200-spi-modf", ms);
rc |= request_irq(ms->irq1, mpc52xx_spi_irq, 0,
"mpc5200-spi-spif", ms);
if (rc) {
free_irq(ms->irq0, ms);
free_irq(ms->irq1, ms);
ms->irq0 = ms->irq1 = 0;
}
} else {
ms->irq0 = ms->irq1 = 0;
}
if (!ms->irq0)
dev_info(&op->dev, "using polled mode\n");
dev_dbg(&op->dev, "registering spi_master struct\n");
rc = spi_register_master(master);
if (rc)
goto err_register;
dev_info(&ms->master->dev, "registered MPC5200 SPI bus\n");
return rc;
err_register:
dev_err(&ms->master->dev, "initialization failed\n");
err_gpio:
while (i-- > 0)
gpio_free(ms->gpio_cs[i]);
kfree(ms->gpio_cs);
err_alloc_gpio:
spi_master_put(master);
err_alloc:
err_init:
iounmap(regs);
return rc;
}
static int mpc52xx_spi_remove(struct platform_device *op)
{
struct spi_master *master = spi_master_get(platform_get_drvdata(op));
struct mpc52xx_spi *ms = spi_master_get_devdata(master);
int i;
free_irq(ms->irq0, ms);
free_irq(ms->irq1, ms);
for (i = 0; i < ms->gpio_cs_count; i++)
gpio_free(ms->gpio_cs[i]);
kfree(ms->gpio_cs);
spi_unregister_master(master);
iounmap(ms->regs);
spi_master_put(master);
return 0;
}
