static u32 sh_msiof_read(struct sh_msiof_spi_priv *p, int reg_offs)
{
switch (reg_offs) {
case TSCR:
case RSCR:
return ioread16(p->mapbase + reg_offs);
default:
return ioread32(p->mapbase + reg_offs);
}
}
static void sh_msiof_write(struct sh_msiof_spi_priv *p, int reg_offs,
u32 value)
{
switch (reg_offs) {
case TSCR:
case RSCR:
iowrite16(value, p->mapbase + reg_offs);
break;
default:
iowrite32(value, p->mapbase + reg_offs);
break;
}
}
static int sh_msiof_modify_ctr_wait(struct sh_msiof_spi_priv *p,
u32 clr, u32 set)
{
u32 mask = clr | set;
u32 data;
int k;
data = sh_msiof_read(p, CTR);
data &= ~clr;
data |= set;
sh_msiof_write(p, CTR, data);
for (k = 100; k > 0; k--) {
if ((sh_msiof_read(p, CTR) & mask) == set)
break;
udelay(10);
}
return k > 0 ? 0 : -ETIMEDOUT;
}
static irqreturn_t sh_msiof_spi_irq(int irq, void *data)
{
struct sh_msiof_spi_priv *p = data;
sh_msiof_write(p, IER, 0);
complete(&p->done);
return IRQ_HANDLED;
}
static void sh_msiof_spi_set_clk_regs(struct sh_msiof_spi_priv *p,
unsigned long parent_rate, u32 spi_hz)
{
unsigned long div = 1024;
u32 brps, scr;
size_t k;
if (!WARN_ON(!spi_hz || !parent_rate))
div = DIV_ROUND_UP(parent_rate, spi_hz);
div = max_t(unsigned long, div, p->min_div);
for (k = 0; k < ARRAY_SIZE(sh_msiof_spi_div_table); k++) {
brps = DIV_ROUND_UP(div, sh_msiof_spi_div_table[k].div);
if (sh_msiof_spi_div_table[k].div == 1 && brps > 2)
continue;
if (brps <= 32)
break;
}
k = min_t(int, k, ARRAY_SIZE(sh_msiof_spi_div_table) - 1);
scr = sh_msiof_spi_div_table[k].brdv | SCR_BRPS(brps);
sh_msiof_write(p, TSCR, scr);
if (!(p->master->flags & SPI_MASTER_MUST_TX))
sh_msiof_write(p, RSCR, scr);
}
static u32 sh_msiof_get_delay_bit(u32 dtdl_or_syncdl)
{
if (dtdl_or_syncdl % 100)
return dtdl_or_syncdl / 100 + 5;
else
return dtdl_or_syncdl / 100;
}
static u32 sh_msiof_spi_get_dtdl_and_syncdl(struct sh_msiof_spi_priv *p)
{
u32 val;
if (!p->info)
return 0;
if (p->info->dtdl > 200 || p->info->syncdl > 300) {
dev_warn(&p->pdev->dev, "DTDL or SYNCDL is too large\n");
return 0;
}
if ((p->info->dtdl + p->info->syncdl) % 100) {
dev_warn(&p->pdev->dev, "the sum of DTDL/SYNCDL is not good\n");
return 0;
}
val = sh_msiof_get_delay_bit(p->info->dtdl) << MDR1_DTDL_SHIFT;
val |= sh_msiof_get_delay_bit(p->info->syncdl) << MDR1_SYNCDL_SHIFT;
return val;
}
static void sh_msiof_spi_set_pin_regs(struct sh_msiof_spi_priv *p,
u32 cpol, u32 cpha,
u32 tx_hi_z, u32 lsb_first, u32 cs_high)
{
u32 tmp;
int edge;
tmp = MDR1_SYNCMD_SPI | 1 << MDR1_FLD_SHIFT | MDR1_XXSTP;
tmp |= !cs_high << MDR1_SYNCAC_SHIFT;
tmp |= lsb_first << MDR1_BITLSB_SHIFT;
tmp |= sh_msiof_spi_get_dtdl_and_syncdl(p);
if (spi_controller_is_slave(p->master))
sh_msiof_write(p, TMDR1, tmp | TMDR1_PCON);
else
sh_msiof_write(p, TMDR1, tmp | MDR1_TRMD | TMDR1_PCON);
if (p->master->flags & SPI_MASTER_MUST_TX) {
tmp &= ~0x0000ffff;
}
sh_msiof_write(p, RMDR1, tmp);
tmp = 0;
tmp |= CTR_TSCKIZ_SCK | cpol << CTR_TSCKIZ_POL_SHIFT;
tmp |= CTR_RSCKIZ_SCK | cpol << CTR_RSCKIZ_POL_SHIFT;
edge = cpol ^ !cpha;
tmp |= edge << CTR_TEDG_SHIFT;
tmp |= edge << CTR_REDG_SHIFT;
tmp |= tx_hi_z ? CTR_TXDIZ_HIZ : CTR_TXDIZ_LOW;
sh_msiof_write(p, CTR, tmp);
}
static void sh_msiof_spi_set_mode_regs(struct sh_msiof_spi_priv *p,
const void *tx_buf, void *rx_buf,
u32 bits, u32 words)
{
u32 dr2 = MDR2_BITLEN1(bits) | MDR2_WDLEN1(words);
if (tx_buf || (p->master->flags & SPI_MASTER_MUST_TX))
sh_msiof_write(p, TMDR2, dr2);
else
sh_msiof_write(p, TMDR2, dr2 | MDR2_GRPMASK1);
if (rx_buf)
sh_msiof_write(p, RMDR2, dr2);
}
static void sh_msiof_reset_str(struct sh_msiof_spi_priv *p)
{
sh_msiof_write(p, STR, sh_msiof_read(p, STR));
}
static void sh_msiof_spi_write_fifo_8(struct sh_msiof_spi_priv *p,
const void *tx_buf, int words, int fs)
{
const u8 *buf_8 = tx_buf;
int k;
for (k = 0; k < words; k++)
sh_msiof_write(p, TFDR, buf_8[k] << fs);
}
static void sh_msiof_spi_write_fifo_16(struct sh_msiof_spi_priv *p,
const void *tx_buf, int words, int fs)
{
const u16 *buf_16 = tx_buf;
int k;
for (k = 0; k < words; k++)
sh_msiof_write(p, TFDR, buf_16[k] << fs);
}
static void sh_msiof_spi_write_fifo_16u(struct sh_msiof_spi_priv *p,
const void *tx_buf, int words, int fs)
{
const u16 *buf_16 = tx_buf;
int k;
for (k = 0; k < words; k++)
sh_msiof_write(p, TFDR, get_unaligned(&buf_16[k]) << fs);
}
static void sh_msiof_spi_write_fifo_32(struct sh_msiof_spi_priv *p,
const void *tx_buf, int words, int fs)
{
const u32 *buf_32 = tx_buf;
int k;
for (k = 0; k < words; k++)
sh_msiof_write(p, TFDR, buf_32[k] << fs);
}
static void sh_msiof_spi_write_fifo_32u(struct sh_msiof_spi_priv *p,
const void *tx_buf, int words, int fs)
{
const u32 *buf_32 = tx_buf;
int k;
for (k = 0; k < words; k++)
sh_msiof_write(p, TFDR, get_unaligned(&buf_32[k]) << fs);
}
static void sh_msiof_spi_write_fifo_s32(struct sh_msiof_spi_priv *p,
const void *tx_buf, int words, int fs)
{
const u32 *buf_32 = tx_buf;
int k;
for (k = 0; k < words; k++)
sh_msiof_write(p, TFDR, swab32(buf_32[k] << fs));
}
static void sh_msiof_spi_write_fifo_s32u(struct sh_msiof_spi_priv *p,
const void *tx_buf, int words, int fs)
{
const u32 *buf_32 = tx_buf;
int k;
for (k = 0; k < words; k++)
sh_msiof_write(p, TFDR, swab32(get_unaligned(&buf_32[k]) << fs));
}
static void sh_msiof_spi_read_fifo_8(struct sh_msiof_spi_priv *p,
void *rx_buf, int words, int fs)
{
u8 *buf_8 = rx_buf;
int k;
for (k = 0; k < words; k++)
buf_8[k] = sh_msiof_read(p, RFDR) >> fs;
}
static void sh_msiof_spi_read_fifo_16(struct sh_msiof_spi_priv *p,
void *rx_buf, int words, int fs)
{
u16 *buf_16 = rx_buf;
int k;
for (k = 0; k < words; k++)
buf_16[k] = sh_msiof_read(p, RFDR) >> fs;
}
static void sh_msiof_spi_read_fifo_16u(struct sh_msiof_spi_priv *p,
void *rx_buf, int words, int fs)
{
u16 *buf_16 = rx_buf;
int k;
for (k = 0; k < words; k++)
put_unaligned(sh_msiof_read(p, RFDR) >> fs, &buf_16[k]);
}
static void sh_msiof_spi_read_fifo_32(struct sh_msiof_spi_priv *p,
void *rx_buf, int words, int fs)
{
u32 *buf_32 = rx_buf;
int k;
for (k = 0; k < words; k++)
buf_32[k] = sh_msiof_read(p, RFDR) >> fs;
}
static void sh_msiof_spi_read_fifo_32u(struct sh_msiof_spi_priv *p,
void *rx_buf, int words, int fs)
{
u32 *buf_32 = rx_buf;
int k;
for (k = 0; k < words; k++)
put_unaligned(sh_msiof_read(p, RFDR) >> fs, &buf_32[k]);
}
static void sh_msiof_spi_read_fifo_s32(struct sh_msiof_spi_priv *p,
void *rx_buf, int words, int fs)
{
u32 *buf_32 = rx_buf;
int k;
for (k = 0; k < words; k++)
buf_32[k] = swab32(sh_msiof_read(p, RFDR) >> fs);
}
static void sh_msiof_spi_read_fifo_s32u(struct sh_msiof_spi_priv *p,
void *rx_buf, int words, int fs)
{
u32 *buf_32 = rx_buf;
int k;
for (k = 0; k < words; k++)
put_unaligned(swab32(sh_msiof_read(p, RFDR) >> fs), &buf_32[k]);
}
static int sh_msiof_spi_setup(struct spi_device *spi)
{
struct device_node *np = spi->master->dev.of_node;
struct sh_msiof_spi_priv *p = spi_master_get_devdata(spi->master);
pm_runtime_get_sync(&p->pdev->dev);
if (!np) {
spi->cs_gpio = (uintptr_t)spi->controller_data;
}
sh_msiof_spi_set_pin_regs(p, !!(spi->mode & SPI_CPOL),
!!(spi->mode & SPI_CPHA),
!!(spi->mode & SPI_3WIRE),
!!(spi->mode & SPI_LSB_FIRST),
!!(spi->mode & SPI_CS_HIGH));
if (spi->cs_gpio >= 0)
gpio_set_value(spi->cs_gpio, !(spi->mode & SPI_CS_HIGH));
pm_runtime_put(&p->pdev->dev);
return 0;
}
static int sh_msiof_prepare_message(struct spi_master *master,
struct spi_message *msg)
{
struct sh_msiof_spi_priv *p = spi_master_get_devdata(master);
const struct spi_device *spi = msg->spi;
sh_msiof_spi_set_pin_regs(p, !!(spi->mode & SPI_CPOL),
!!(spi->mode & SPI_CPHA),
!!(spi->mode & SPI_3WIRE),
!!(spi->mode & SPI_LSB_FIRST),
!!(spi->mode & SPI_CS_HIGH));
return 0;
}
static int sh_msiof_spi_start(struct sh_msiof_spi_priv *p, void *rx_buf)
{
bool slave = spi_controller_is_slave(p->master);
int ret = 0;
if (!slave)
ret = sh_msiof_modify_ctr_wait(p, 0, CTR_TSCKE);
if (rx_buf && !ret)
ret = sh_msiof_modify_ctr_wait(p, 0, CTR_RXE);
if (!ret)
ret = sh_msiof_modify_ctr_wait(p, 0, CTR_TXE);
if (!ret && !slave)
ret = sh_msiof_modify_ctr_wait(p, 0, CTR_TFSE);
return ret;
}
static int sh_msiof_spi_stop(struct sh_msiof_spi_priv *p, void *rx_buf)
{
bool slave = spi_controller_is_slave(p->master);
int ret = 0;
if (!slave)
ret = sh_msiof_modify_ctr_wait(p, CTR_TFSE, 0);
if (!ret)
ret = sh_msiof_modify_ctr_wait(p, CTR_TXE, 0);
if (rx_buf && !ret)
ret = sh_msiof_modify_ctr_wait(p, CTR_RXE, 0);
if (!ret && !slave)
ret = sh_msiof_modify_ctr_wait(p, CTR_TSCKE, 0);
return ret;
}
static int sh_msiof_slave_abort(struct spi_master *master)
{
struct sh_msiof_spi_priv *p = spi_master_get_devdata(master);
p->slave_aborted = true;
complete(&p->done);
return 0;
}
static int sh_msiof_wait_for_completion(struct sh_msiof_spi_priv *p)
{
if (spi_controller_is_slave(p->master)) {
if (wait_for_completion_interruptible(&p->done) ||
p->slave_aborted) {
dev_dbg(&p->pdev->dev, "interrupted\n");
return -EINTR;
}
} else {
if (!wait_for_completion_timeout(&p->done, HZ)) {
dev_err(&p->pdev->dev, "timeout\n");
return -ETIMEDOUT;
}
}
return 0;
}
static int sh_msiof_spi_txrx_once(struct sh_msiof_spi_priv *p,
void (*tx_fifo)(struct sh_msiof_spi_priv *,
const void *, int, int),
void (*rx_fifo)(struct sh_msiof_spi_priv *,
void *, int, int),
const void *tx_buf, void *rx_buf,
int words, int bits)
{
int fifo_shift;
int ret;
if (tx_buf)
words = min_t(int, words, p->tx_fifo_size);
if (rx_buf)
words = min_t(int, words, p->rx_fifo_size);
fifo_shift = 32 - bits;
sh_msiof_write(p, FCTR, 0);
sh_msiof_spi_set_mode_regs(p, tx_buf, rx_buf, bits, words);
sh_msiof_write(p, IER, IER_TEOFE | IER_REOFE);
if (tx_buf)
tx_fifo(p, tx_buf, words, fifo_shift);
reinit_completion(&p->done);
p->slave_aborted = false;
ret = sh_msiof_spi_start(p, rx_buf);
if (ret) {
dev_err(&p->pdev->dev, "failed to start hardware\n");
goto stop_ier;
}
ret = sh_msiof_wait_for_completion(p);
if (ret)
goto stop_reset;
if (rx_buf)
rx_fifo(p, rx_buf, words, fifo_shift);
sh_msiof_reset_str(p);
ret = sh_msiof_spi_stop(p, rx_buf);
if (ret) {
dev_err(&p->pdev->dev, "failed to shut down hardware\n");
return ret;
}
return words;
stop_reset:
sh_msiof_reset_str(p);
sh_msiof_spi_stop(p, rx_buf);
stop_ier:
sh_msiof_write(p, IER, 0);
return ret;
}
static void sh_msiof_dma_complete(void *arg)
{
struct sh_msiof_spi_priv *p = arg;
sh_msiof_write(p, IER, 0);
complete(&p->done);
}
static int sh_msiof_dma_once(struct sh_msiof_spi_priv *p, const void *tx,
void *rx, unsigned int len)
{
u32 ier_bits = 0;
struct dma_async_tx_descriptor *desc_tx = NULL, *desc_rx = NULL;
dma_cookie_t cookie;
int ret;
if (rx) {
ier_bits |= IER_RDREQE | IER_RDMAE;
desc_rx = dmaengine_prep_slave_single(p->master->dma_rx,
p->rx_dma_addr, len, DMA_FROM_DEVICE,
DMA_PREP_INTERRUPT | DMA_CTRL_ACK);
if (!desc_rx)
return -EAGAIN;
desc_rx->callback = sh_msiof_dma_complete;
desc_rx->callback_param = p;
cookie = dmaengine_submit(desc_rx);
if (dma_submit_error(cookie))
return cookie;
}
if (tx) {
ier_bits |= IER_TDREQE | IER_TDMAE;
dma_sync_single_for_device(p->master->dma_tx->device->dev,
p->tx_dma_addr, len, DMA_TO_DEVICE);
desc_tx = dmaengine_prep_slave_single(p->master->dma_tx,
p->tx_dma_addr, len, DMA_TO_DEVICE,
DMA_PREP_INTERRUPT | DMA_CTRL_ACK);
if (!desc_tx) {
ret = -EAGAIN;
goto no_dma_tx;
}
if (rx) {
desc_tx->callback = NULL;
} else {
desc_tx->callback = sh_msiof_dma_complete;
desc_tx->callback_param = p;
}
cookie = dmaengine_submit(desc_tx);
if (dma_submit_error(cookie)) {
ret = cookie;
goto no_dma_tx;
}
}
sh_msiof_write(p, FCTR, FCTR_TFWM_1 | FCTR_RFWM_1);
sh_msiof_spi_set_mode_regs(p, tx, rx, 32, len / 4);
sh_msiof_write(p, IER, ier_bits);
reinit_completion(&p->done);
p->slave_aborted = false;
if (rx)
dma_async_issue_pending(p->master->dma_rx);
if (tx)
dma_async_issue_pending(p->master->dma_tx);
ret = sh_msiof_spi_start(p, rx);
if (ret) {
dev_err(&p->pdev->dev, "failed to start hardware\n");
goto stop_dma;
}
ret = sh_msiof_wait_for_completion(p);
if (ret)
goto stop_reset;
sh_msiof_reset_str(p);
ret = sh_msiof_spi_stop(p, rx);
if (ret) {
dev_err(&p->pdev->dev, "failed to shut down hardware\n");
return ret;
}
if (rx)
dma_sync_single_for_cpu(p->master->dma_rx->device->dev,
p->rx_dma_addr, len,
DMA_FROM_DEVICE);
return 0;
stop_reset:
sh_msiof_reset_str(p);
sh_msiof_spi_stop(p, rx);
stop_dma:
if (tx)
dmaengine_terminate_all(p->master->dma_tx);
no_dma_tx:
if (rx)
dmaengine_terminate_all(p->master->dma_rx);
sh_msiof_write(p, IER, 0);
return ret;
}
static void copy_bswap32(u32 *dst, const u32 *src, unsigned int words)
{
if ((unsigned long)src & 3) {
while (words--) {
*dst++ = swab32(get_unaligned(src));
src++;
}
} else if ((unsigned long)dst & 3) {
while (words--) {
put_unaligned(swab32(*src++), dst);
dst++;
}
} else {
while (words--)
*dst++ = swab32(*src++);
}
}
static void copy_wswap32(u32 *dst, const u32 *src, unsigned int words)
{
if ((unsigned long)src & 3) {
while (words--) {
*dst++ = swahw32(get_unaligned(src));
src++;
}
} else if ((unsigned long)dst & 3) {
while (words--) {
put_unaligned(swahw32(*src++), dst);
dst++;
}
} else {
while (words--)
*dst++ = swahw32(*src++);
}
}
static void copy_plain32(u32 *dst, const u32 *src, unsigned int words)
{
memcpy(dst, src, words * 4);
}
static int sh_msiof_transfer_one(struct spi_master *master,
struct spi_device *spi,
struct spi_transfer *t)
{
struct sh_msiof_spi_priv *p = spi_master_get_devdata(master);
void (*copy32)(u32 *, const u32 *, unsigned int);
void (*tx_fifo)(struct sh_msiof_spi_priv *, const void *, int, int);
void (*rx_fifo)(struct sh_msiof_spi_priv *, void *, int, int);
const void *tx_buf = t->tx_buf;
void *rx_buf = t->rx_buf;
unsigned int len = t->len;
unsigned int bits = t->bits_per_word;
unsigned int bytes_per_word;
unsigned int words;
int n;
bool swab;
int ret;
if (!spi_controller_is_slave(p->master))
sh_msiof_spi_set_clk_regs(p, clk_get_rate(p->clk), t->speed_hz);
while (master->dma_tx && len > 15) {
unsigned int l = 0;
if (tx_buf)
l = min(len, p->tx_fifo_size * 4);
if (rx_buf)
l = min(len, p->rx_fifo_size * 4);
if (bits <= 8) {
if (l & 3)
break;
copy32 = copy_bswap32;
} else if (bits <= 16) {
if (l & 1)
break;
copy32 = copy_wswap32;
} else {
copy32 = copy_plain32;
}
if (tx_buf)
copy32(p->tx_dma_page, tx_buf, l / 4);
ret = sh_msiof_dma_once(p, tx_buf, rx_buf, l);
if (ret == -EAGAIN) {
pr_warn_once("%s %s: DMA not available, falling back to PIO\n",
dev_driver_string(&p->pdev->dev),
dev_name(&p->pdev->dev));
break;
}
if (ret)
return ret;
if (rx_buf) {
copy32(rx_buf, p->rx_dma_page, l / 4);
rx_buf += l;
}
if (tx_buf)
tx_buf += l;
len -= l;
if (!len)
return 0;
}
if (bits <= 8 && len > 15 && !(len & 3)) {
bits = 32;
swab = true;
} else {
swab = false;
}
if (bits <= 8) {
bytes_per_word = 1;
tx_fifo = sh_msiof_spi_write_fifo_8;
rx_fifo = sh_msiof_spi_read_fifo_8;
} else if (bits <= 16) {
bytes_per_word = 2;
if ((unsigned long)tx_buf & 0x01)
tx_fifo = sh_msiof_spi_write_fifo_16u;
else
tx_fifo = sh_msiof_spi_write_fifo_16;
if ((unsigned long)rx_buf & 0x01)
rx_fifo = sh_msiof_spi_read_fifo_16u;
else
rx_fifo = sh_msiof_spi_read_fifo_16;
} else if (swab) {
bytes_per_word = 4;
if ((unsigned long)tx_buf & 0x03)
tx_fifo = sh_msiof_spi_write_fifo_s32u;
else
tx_fifo = sh_msiof_spi_write_fifo_s32;
if ((unsigned long)rx_buf & 0x03)
rx_fifo = sh_msiof_spi_read_fifo_s32u;
else
rx_fifo = sh_msiof_spi_read_fifo_s32;
} else {
bytes_per_word = 4;
if ((unsigned long)tx_buf & 0x03)
tx_fifo = sh_msiof_spi_write_fifo_32u;
else
tx_fifo = sh_msiof_spi_write_fifo_32;
if ((unsigned long)rx_buf & 0x03)
rx_fifo = sh_msiof_spi_read_fifo_32u;
else
rx_fifo = sh_msiof_spi_read_fifo_32;
}
words = len / bytes_per_word;
while (words > 0) {
n = sh_msiof_spi_txrx_once(p, tx_fifo, rx_fifo, tx_buf, rx_buf,
words, bits);
if (n < 0)
return n;
if (tx_buf)
tx_buf += n * bytes_per_word;
if (rx_buf)
rx_buf += n * bytes_per_word;
words -= n;
}
return 0;
}
static struct sh_msiof_spi_info *sh_msiof_spi_parse_dt(struct device *dev)
{
struct sh_msiof_spi_info *info;
struct device_node *np = dev->of_node;
u32 num_cs = 1;
info = devm_kzalloc(dev, sizeof(struct sh_msiof_spi_info), GFP_KERNEL);
if (!info)
return NULL;
info->mode = of_property_read_bool(np, "spi-slave") ? MSIOF_SPI_SLAVE
: MSIOF_SPI_MASTER;
if (info->mode == MSIOF_SPI_MASTER)
of_property_read_u32(np, "num-cs", &num_cs);
of_property_read_u32(np, "renesas,tx-fifo-size",
&info->tx_fifo_override);
of_property_read_u32(np, "renesas,rx-fifo-size",
&info->rx_fifo_override);
of_property_read_u32(np, "renesas,dtdl", &info->dtdl);
of_property_read_u32(np, "renesas,syncdl", &info->syncdl);
info->num_chipselect = num_cs;
return info;
}
static struct sh_msiof_spi_info *sh_msiof_spi_parse_dt(struct device *dev)
{
return NULL;
}
static struct dma_chan *sh_msiof_request_dma_chan(struct device *dev,
enum dma_transfer_direction dir, unsigned int id, dma_addr_t port_addr)
{
dma_cap_mask_t mask;
struct dma_chan *chan;
struct dma_slave_config cfg;
int ret;
dma_cap_zero(mask);
dma_cap_set(DMA_SLAVE, mask);
chan = dma_request_slave_channel_compat(mask, shdma_chan_filter,
(void *)(unsigned long)id, dev,
dir == DMA_MEM_TO_DEV ? "tx" : "rx");
if (!chan) {
dev_warn(dev, "dma_request_slave_channel_compat failed\n");
return NULL;
}
memset(&cfg, 0, sizeof(cfg));
cfg.direction = dir;
if (dir == DMA_MEM_TO_DEV) {
cfg.dst_addr = port_addr;
cfg.dst_addr_width = DMA_SLAVE_BUSWIDTH_4_BYTES;
} else {
cfg.src_addr = port_addr;
cfg.src_addr_width = DMA_SLAVE_BUSWIDTH_4_BYTES;
}
ret = dmaengine_slave_config(chan, &cfg);
if (ret) {
dev_warn(dev, "dmaengine_slave_config failed %d\n", ret);
dma_release_channel(chan);
return NULL;
}
return chan;
}
static int sh_msiof_request_dma(struct sh_msiof_spi_priv *p)
{
struct platform_device *pdev = p->pdev;
struct device *dev = &pdev->dev;
const struct sh_msiof_spi_info *info = dev_get_platdata(dev);
unsigned int dma_tx_id, dma_rx_id;
const struct resource *res;
struct spi_master *master;
struct device *tx_dev, *rx_dev;
if (dev->of_node) {
dma_tx_id = 0;
dma_rx_id = 0;
} else if (info && info->dma_tx_id && info->dma_rx_id) {
dma_tx_id = info->dma_tx_id;
dma_rx_id = info->dma_rx_id;
} else {
return 0;
}
res = platform_get_resource(pdev, IORESOURCE_MEM, 1);
if (!res)
res = platform_get_resource(pdev, IORESOURCE_MEM, 0);
master = p->master;
master->dma_tx = sh_msiof_request_dma_chan(dev, DMA_MEM_TO_DEV,
dma_tx_id,
res->start + TFDR);
if (!master->dma_tx)
return -ENODEV;
master->dma_rx = sh_msiof_request_dma_chan(dev, DMA_DEV_TO_MEM,
dma_rx_id,
res->start + RFDR);
if (!master->dma_rx)
goto free_tx_chan;
p->tx_dma_page = (void *)__get_free_page(GFP_KERNEL | GFP_DMA);
if (!p->tx_dma_page)
goto free_rx_chan;
p->rx_dma_page = (void *)__get_free_page(GFP_KERNEL | GFP_DMA);
if (!p->rx_dma_page)
goto free_tx_page;
tx_dev = master->dma_tx->device->dev;
p->tx_dma_addr = dma_map_single(tx_dev, p->tx_dma_page, PAGE_SIZE,
DMA_TO_DEVICE);
if (dma_mapping_error(tx_dev, p->tx_dma_addr))
goto free_rx_page;
rx_dev = master->dma_rx->device->dev;
p->rx_dma_addr = dma_map_single(rx_dev, p->rx_dma_page, PAGE_SIZE,
DMA_FROM_DEVICE);
if (dma_mapping_error(rx_dev, p->rx_dma_addr))
goto unmap_tx_page;
dev_info(dev, "DMA available");
return 0;
unmap_tx_page:
dma_unmap_single(tx_dev, p->tx_dma_addr, PAGE_SIZE, DMA_TO_DEVICE);
free_rx_page:
free_page((unsigned long)p->rx_dma_page);
free_tx_page:
free_page((unsigned long)p->tx_dma_page);
free_rx_chan:
dma_release_channel(master->dma_rx);
free_tx_chan:
dma_release_channel(master->dma_tx);
master->dma_tx = NULL;
return -ENODEV;
}
static void sh_msiof_release_dma(struct sh_msiof_spi_priv *p)
{
struct spi_master *master = p->master;
struct device *dev;
if (!master->dma_tx)
return;
dev = &p->pdev->dev;
dma_unmap_single(master->dma_rx->device->dev, p->rx_dma_addr,
PAGE_SIZE, DMA_FROM_DEVICE);
dma_unmap_single(master->dma_tx->device->dev, p->tx_dma_addr,
PAGE_SIZE, DMA_TO_DEVICE);
free_page((unsigned long)p->rx_dma_page);
free_page((unsigned long)p->tx_dma_page);
dma_release_channel(master->dma_rx);
dma_release_channel(master->dma_tx);
}
static int sh_msiof_spi_probe(struct platform_device *pdev)
{
struct resource *r;
struct spi_master *master;
const struct sh_msiof_chipdata *chipdata;
const struct of_device_id *of_id;
struct sh_msiof_spi_info *info;
struct sh_msiof_spi_priv *p;
int i;
int ret;
of_id = of_match_device(sh_msiof_match, &pdev->dev);
if (of_id) {
chipdata = of_id->data;
info = sh_msiof_spi_parse_dt(&pdev->dev);
} else {
chipdata = (const void *)pdev->id_entry->driver_data;
info = dev_get_platdata(&pdev->dev);
}
if (!info) {
dev_err(&pdev->dev, "failed to obtain device info\n");
return -ENXIO;
}
if (info->mode == MSIOF_SPI_SLAVE)
master = spi_alloc_slave(&pdev->dev,
sizeof(struct sh_msiof_spi_priv));
else
master = spi_alloc_master(&pdev->dev,
sizeof(struct sh_msiof_spi_priv));
if (master == NULL)
return -ENOMEM;
p = spi_master_get_devdata(master);
platform_set_drvdata(pdev, p);
p->master = master;
p->info = info;
p->min_div = chipdata->min_div;
init_completion(&p->done);
p->clk = devm_clk_get(&pdev->dev, NULL);
if (IS_ERR(p->clk)) {
dev_err(&pdev->dev, "cannot get clock\n");
ret = PTR_ERR(p->clk);
goto err1;
}
i = platform_get_irq(pdev, 0);
if (i < 0) {
dev_err(&pdev->dev, "cannot get platform IRQ\n");
ret = -ENOENT;
goto err1;
}
r = platform_get_resource(pdev, IORESOURCE_MEM, 0);
p->mapbase = devm_ioremap_resource(&pdev->dev, r);
if (IS_ERR(p->mapbase)) {
ret = PTR_ERR(p->mapbase);
goto err1;
}
ret = devm_request_irq(&pdev->dev, i, sh_msiof_spi_irq, 0,
dev_name(&pdev->dev), p);
if (ret) {
dev_err(&pdev->dev, "unable to request irq\n");
goto err1;
}
p->pdev = pdev;
pm_runtime_enable(&pdev->dev);
p->tx_fifo_size = chipdata->tx_fifo_size;
p->rx_fifo_size = chipdata->rx_fifo_size;
if (p->info->tx_fifo_override)
p->tx_fifo_size = p->info->tx_fifo_override;
if (p->info->rx_fifo_override)
p->rx_fifo_size = p->info->rx_fifo_override;
master->mode_bits = SPI_CPOL | SPI_CPHA | SPI_CS_HIGH;
master->mode_bits |= SPI_LSB_FIRST | SPI_3WIRE;
master->flags = chipdata->master_flags;
master->bus_num = pdev->id;
master->dev.of_node = pdev->dev.of_node;
master->num_chipselect = p->info->num_chipselect;
master->setup = sh_msiof_spi_setup;
master->prepare_message = sh_msiof_prepare_message;
master->slave_abort = sh_msiof_slave_abort;
master->bits_per_word_mask = SPI_BPW_RANGE_MASK(8, 32);
master->auto_runtime_pm = true;
master->transfer_one = sh_msiof_transfer_one;
ret = sh_msiof_request_dma(p);
if (ret < 0)
dev_warn(&pdev->dev, "DMA not available, using PIO\n");
ret = devm_spi_register_master(&pdev->dev, master);
if (ret < 0) {
dev_err(&pdev->dev, "spi_register_master error.\n");
goto err2;
}
return 0;
err2:
sh_msiof_release_dma(p);
pm_runtime_disable(&pdev->dev);
err1:
spi_master_put(master);
return ret;
}
static int sh_msiof_spi_remove(struct platform_device *pdev)
{
struct sh_msiof_spi_priv *p = platform_get_drvdata(pdev);
sh_msiof_release_dma(p);
pm_runtime_disable(&pdev->dev);
return 0;
}
