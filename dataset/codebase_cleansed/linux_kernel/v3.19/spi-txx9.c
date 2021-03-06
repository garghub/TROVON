static u32 txx9spi_rd(struct txx9spi *c, int reg)
{
return __raw_readl(c->membase + reg);
}
static void txx9spi_wr(struct txx9spi *c, u32 val, int reg)
{
__raw_writel(val, c->membase + reg);
}
static void txx9spi_cs_func(struct spi_device *spi, struct txx9spi *c,
int on, unsigned int cs_delay)
{
int val = (spi->mode & SPI_CS_HIGH) ? on : !on;
if (on) {
if (c->last_chipselect >= 0)
gpio_set_value(c->last_chipselect,
!c->last_chipselect_val);
c->last_chipselect = spi->chip_select;
c->last_chipselect_val = val;
} else {
c->last_chipselect = -1;
ndelay(cs_delay);
}
gpio_set_value(spi->chip_select, val);
ndelay(cs_delay);
}
static int txx9spi_setup(struct spi_device *spi)
{
struct txx9spi *c = spi_master_get_devdata(spi->master);
if (!spi->max_speed_hz)
return -EINVAL;
if (gpio_direction_output(spi->chip_select,
!(spi->mode & SPI_CS_HIGH))) {
dev_err(&spi->dev, "Cannot setup GPIO for chipselect.\n");
return -EINVAL;
}
spin_lock(&c->lock);
txx9spi_cs_func(spi, c, 0, (NSEC_PER_SEC / 2) / spi->max_speed_hz);
spin_unlock(&c->lock);
return 0;
}
static irqreturn_t txx9spi_interrupt(int irq, void *dev_id)
{
struct txx9spi *c = dev_id;
txx9spi_wr(c, txx9spi_rd(c, TXx9_SPCR0) & ~TXx9_SPCR0_RBSIE,
TXx9_SPCR0);
wake_up(&c->waitq);
return IRQ_HANDLED;
}
static void txx9spi_work_one(struct txx9spi *c, struct spi_message *m)
{
struct spi_device *spi = m->spi;
struct spi_transfer *t;
unsigned int cs_delay;
unsigned int cs_change = 1;
int status = 0;
u32 mcr;
u32 prev_speed_hz = 0;
u8 prev_bits_per_word = 0;
cs_delay = 100 + (NSEC_PER_SEC / 2) / spi->max_speed_hz;
mcr = txx9spi_rd(c, TXx9_SPMCR);
if (unlikely((mcr & TXx9_SPMCR_OPMODE) == TXx9_SPMCR_ACTIVE)) {
dev_err(&spi->dev, "Bad mode.\n");
status = -EIO;
goto exit;
}
mcr &= ~(TXx9_SPMCR_OPMODE | TXx9_SPMCR_SPSTP | TXx9_SPMCR_BCLR);
txx9spi_wr(c, mcr | TXx9_SPMCR_CONFIG | TXx9_SPMCR_BCLR, TXx9_SPMCR);
txx9spi_wr(c, TXx9_SPCR0_SBOS
| ((spi->mode & SPI_CPOL) ? TXx9_SPCR0_SPOL : 0)
| ((spi->mode & SPI_CPHA) ? TXx9_SPCR0_SPHA : 0)
| 0x08,
TXx9_SPCR0);
list_for_each_entry(t, &m->transfers, transfer_list) {
const void *txbuf = t->tx_buf;
void *rxbuf = t->rx_buf;
u32 data;
unsigned int len = t->len;
unsigned int wsize;
u32 speed_hz = t->speed_hz ? : spi->max_speed_hz;
u8 bits_per_word = t->bits_per_word;
wsize = bits_per_word >> 3;
if (prev_speed_hz != speed_hz
|| prev_bits_per_word != bits_per_word) {
int n = DIV_ROUND_UP(c->baseclk, speed_hz) - 1;
n = clamp(n, SPI_MIN_DIVIDER, SPI_MAX_DIVIDER);
txx9spi_wr(c, mcr | TXx9_SPMCR_CONFIG | TXx9_SPMCR_BCLR,
TXx9_SPMCR);
txx9spi_wr(c, (n << 8) | bits_per_word, TXx9_SPCR1);
txx9spi_wr(c, mcr | TXx9_SPMCR_ACTIVE, TXx9_SPMCR);
prev_speed_hz = speed_hz;
prev_bits_per_word = bits_per_word;
}
if (cs_change)
txx9spi_cs_func(spi, c, 1, cs_delay);
cs_change = t->cs_change;
while (len) {
unsigned int count = SPI_FIFO_SIZE;
int i;
u32 cr0;
if (len < count * wsize)
count = len / wsize;
while (!(txx9spi_rd(c, TXx9_SPSR) & TXx9_SPSR_SIDLE))
cpu_relax();
cr0 = txx9spi_rd(c, TXx9_SPCR0);
cr0 &= ~TXx9_SPCR0_RXIFL_MASK;
cr0 |= (count - 1) << 12;
cr0 |= TXx9_SPCR0_RBSIE;
txx9spi_wr(c, cr0, TXx9_SPCR0);
for (i = 0; i < count; i++) {
if (txbuf) {
data = (wsize == 1)
? *(const u8 *)txbuf
: *(const u16 *)txbuf;
txx9spi_wr(c, data, TXx9_SPDR);
txbuf += wsize;
} else
txx9spi_wr(c, 0, TXx9_SPDR);
}
wait_event(c->waitq,
txx9spi_rd(c, TXx9_SPSR) & TXx9_SPSR_RBSI);
for (i = 0; i < count; i++) {
data = txx9spi_rd(c, TXx9_SPDR);
if (rxbuf) {
if (wsize == 1)
*(u8 *)rxbuf = data;
else
*(u16 *)rxbuf = data;
rxbuf += wsize;
}
}
len -= count * wsize;
}
m->actual_length += t->len;
if (t->delay_usecs)
udelay(t->delay_usecs);
if (!cs_change)
continue;
if (t->transfer_list.next == &m->transfers)
break;
txx9spi_cs_func(spi, c, 0, cs_delay);
}
exit:
m->status = status;
if (m->complete)
m->complete(m->context);
if (!(status == 0 && cs_change))
txx9spi_cs_func(spi, c, 0, cs_delay);
txx9spi_wr(c, mcr | TXx9_SPMCR_CONFIG | TXx9_SPMCR_BCLR, TXx9_SPMCR);
}
static void txx9spi_work(struct work_struct *work)
{
struct txx9spi *c = container_of(work, struct txx9spi, work);
unsigned long flags;
spin_lock_irqsave(&c->lock, flags);
while (!list_empty(&c->queue)) {
struct spi_message *m;
m = container_of(c->queue.next, struct spi_message, queue);
list_del_init(&m->queue);
spin_unlock_irqrestore(&c->lock, flags);
txx9spi_work_one(c, m);
spin_lock_irqsave(&c->lock, flags);
}
spin_unlock_irqrestore(&c->lock, flags);
}
static int txx9spi_transfer(struct spi_device *spi, struct spi_message *m)
{
struct spi_master *master = spi->master;
struct txx9spi *c = spi_master_get_devdata(master);
struct spi_transfer *t;
unsigned long flags;
m->actual_length = 0;
list_for_each_entry(t, &m->transfers, transfer_list) {
if (!t->tx_buf && !t->rx_buf && t->len)
return -EINVAL;
}
spin_lock_irqsave(&c->lock, flags);
list_add_tail(&m->queue, &c->queue);
queue_work(c->workqueue, &c->work);
spin_unlock_irqrestore(&c->lock, flags);
return 0;
}
static int txx9spi_probe(struct platform_device *dev)
{
struct spi_master *master;
struct txx9spi *c;
struct resource *res;
int ret = -ENODEV;
u32 mcr;
int irq;
master = spi_alloc_master(&dev->dev, sizeof(*c));
if (!master)
return ret;
c = spi_master_get_devdata(master);
platform_set_drvdata(dev, master);
INIT_WORK(&c->work, txx9spi_work);
spin_lock_init(&c->lock);
INIT_LIST_HEAD(&c->queue);
init_waitqueue_head(&c->waitq);
c->clk = devm_clk_get(&dev->dev, "spi-baseclk");
if (IS_ERR(c->clk)) {
ret = PTR_ERR(c->clk);
c->clk = NULL;
goto exit;
}
ret = clk_enable(c->clk);
if (ret) {
c->clk = NULL;
goto exit;
}
c->baseclk = clk_get_rate(c->clk);
master->min_speed_hz = DIV_ROUND_UP(c->baseclk, SPI_MAX_DIVIDER + 1);
master->max_speed_hz = c->baseclk / (SPI_MIN_DIVIDER + 1);
res = platform_get_resource(dev, IORESOURCE_MEM, 0);
c->membase = devm_ioremap_resource(&dev->dev, res);
if (IS_ERR(c->membase))
goto exit_busy;
mcr = txx9spi_rd(c, TXx9_SPMCR);
mcr &= ~(TXx9_SPMCR_OPMODE | TXx9_SPMCR_SPSTP | TXx9_SPMCR_BCLR);
txx9spi_wr(c, mcr | TXx9_SPMCR_CONFIG | TXx9_SPMCR_BCLR, TXx9_SPMCR);
irq = platform_get_irq(dev, 0);
if (irq < 0)
goto exit_busy;
ret = devm_request_irq(&dev->dev, irq, txx9spi_interrupt, 0,
"spi_txx9", c);
if (ret)
goto exit;
c->workqueue = create_singlethread_workqueue(
dev_name(master->dev.parent));
if (!c->workqueue)
goto exit_busy;
c->last_chipselect = -1;
dev_info(&dev->dev, "at %#llx, irq %d, %dMHz\n",
(unsigned long long)res->start, irq,
(c->baseclk + 500000) / 1000000);
master->mode_bits = SPI_CS_HIGH | SPI_CPOL | SPI_CPHA;
master->bus_num = dev->id;
master->setup = txx9spi_setup;
master->transfer = txx9spi_transfer;
master->num_chipselect = (u16)UINT_MAX;
master->bits_per_word_mask = SPI_BPW_MASK(8) | SPI_BPW_MASK(16);
ret = devm_spi_register_master(&dev->dev, master);
if (ret)
goto exit;
return 0;
exit_busy:
ret = -EBUSY;
exit:
if (c->workqueue)
destroy_workqueue(c->workqueue);
clk_disable(c->clk);
spi_master_put(master);
return ret;
}
static int txx9spi_remove(struct platform_device *dev)
{
struct spi_master *master = platform_get_drvdata(dev);
struct txx9spi *c = spi_master_get_devdata(master);
destroy_workqueue(c->workqueue);
clk_disable(c->clk);
return 0;
}
static int __init txx9spi_init(void)
{
return platform_driver_register(&txx9spi_driver);
}
static void __exit txx9spi_exit(void)
{
platform_driver_unregister(&txx9spi_driver);
}
