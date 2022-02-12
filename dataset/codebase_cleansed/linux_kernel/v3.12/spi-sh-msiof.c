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
unsigned long parent_rate,
unsigned long spi_hz)
{
unsigned long div = 1024;
size_t k;
if (!WARN_ON(!spi_hz || !parent_rate))
div = parent_rate / spi_hz;
for (k = 0; k < ARRAY_SIZE(sh_msiof_spi_clk_table); k++) {
if (sh_msiof_spi_clk_table[k].div >= div)
break;
}
k = min_t(int, k, ARRAY_SIZE(sh_msiof_spi_clk_table) - 1);
sh_msiof_write(p, TSCR, sh_msiof_spi_clk_table[k].scr);
sh_msiof_write(p, RSCR, sh_msiof_spi_clk_table[k].scr);
}
static void sh_msiof_spi_set_pin_regs(struct sh_msiof_spi_priv *p,
u32 cpol, u32 cpha,
u32 tx_hi_z, u32 lsb_first)
{
u32 tmp;
int edge;
sh_msiof_write(p, FCTR, 0);
sh_msiof_write(p, TMDR1, 0xe2000005 | (lsb_first << 24));
sh_msiof_write(p, RMDR1, 0x22000005 | (lsb_first << 24));
tmp = 0xa0000000;
tmp |= cpol << 30;
tmp |= cpol << 28;
edge = cpol ^ !cpha;
tmp |= edge << 27;
tmp |= edge << 26;
tmp |= (tx_hi_z ? 2 : 0) << 22;
sh_msiof_write(p, CTR, tmp);
}
static void sh_msiof_spi_set_mode_regs(struct sh_msiof_spi_priv *p,
const void *tx_buf, void *rx_buf,
u32 bits, u32 words)
{
u32 dr2 = ((bits - 1) << 24) | ((words - 1) << 16);
if (tx_buf)
sh_msiof_write(p, TMDR2, dr2);
else
sh_msiof_write(p, TMDR2, dr2 | 1);
if (rx_buf)
sh_msiof_write(p, RMDR2, dr2);
sh_msiof_write(p, IER, STR_TEOF | STR_REOF);
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
static int sh_msiof_spi_bits(struct spi_device *spi, struct spi_transfer *t)
{
int bits;
bits = t ? t->bits_per_word : 0;
if (!bits)
bits = spi->bits_per_word;
return bits;
}
static unsigned long sh_msiof_spi_hz(struct spi_device *spi,
struct spi_transfer *t)
{
unsigned long hz;
hz = t ? t->speed_hz : 0;
if (!hz)
hz = spi->max_speed_hz;
return hz;
}
static int sh_msiof_spi_setup_transfer(struct spi_device *spi,
struct spi_transfer *t)
{
int bits;
bits = sh_msiof_spi_bits(spi, t);
if (bits < 8)
return -EINVAL;
if (bits > 32)
return -EINVAL;
return spi_bitbang_setup_transfer(spi, t);
}
static void sh_msiof_spi_chipselect(struct spi_device *spi, int is_on)
{
struct sh_msiof_spi_priv *p = spi_master_get_devdata(spi->master);
int value;
if (spi->mode & SPI_CS_HIGH)
value = (is_on == BITBANG_CS_ACTIVE) ? 1 : 0;
else
value = (is_on == BITBANG_CS_ACTIVE) ? 0 : 1;
if (is_on == BITBANG_CS_ACTIVE) {
if (!test_and_set_bit(0, &p->flags)) {
pm_runtime_get_sync(&p->pdev->dev);
clk_enable(p->clk);
}
sh_msiof_spi_set_pin_regs(p, !!(spi->mode & SPI_CPOL),
!!(spi->mode & SPI_CPHA),
!!(spi->mode & SPI_3WIRE),
!!(spi->mode & SPI_LSB_FIRST));
}
gpio_set_value((unsigned)spi->controller_data, value);
if (is_on == BITBANG_CS_INACTIVE) {
if (test_and_clear_bit(0, &p->flags)) {
clk_disable(p->clk);
pm_runtime_put(&p->pdev->dev);
}
}
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
sh_msiof_spi_set_mode_regs(p, tx_buf, rx_buf, bits, words);
if (tx_buf)
tx_fifo(p, tx_buf, words, fifo_shift);
ret = sh_msiof_modify_ctr_wait(p, 0, CTR_TSCKE);
if (rx_buf)
ret = ret ? ret : sh_msiof_modify_ctr_wait(p, 0, CTR_RXE);
ret = ret ? ret : sh_msiof_modify_ctr_wait(p, 0, CTR_TXE);
INIT_COMPLETION(p->done);
ret = ret ? ret : sh_msiof_modify_ctr_wait(p, 0, CTR_TFSE);
if (ret) {
dev_err(&p->pdev->dev, "failed to start hardware\n");
goto err;
}
wait_for_completion(&p->done);
if (rx_buf)
rx_fifo(p, rx_buf, words, fifo_shift);
sh_msiof_reset_str(p);
ret = sh_msiof_modify_ctr_wait(p, CTR_TFSE, 0);
ret = ret ? ret : sh_msiof_modify_ctr_wait(p, CTR_TXE, 0);
if (rx_buf)
ret = ret ? ret : sh_msiof_modify_ctr_wait(p, CTR_RXE, 0);
ret = ret ? ret : sh_msiof_modify_ctr_wait(p, CTR_TSCKE, 0);
if (ret) {
dev_err(&p->pdev->dev, "failed to shut down hardware\n");
goto err;
}
return words;
err:
sh_msiof_write(p, IER, 0);
return ret;
}
static int sh_msiof_spi_txrx(struct spi_device *spi, struct spi_transfer *t)
{
struct sh_msiof_spi_priv *p = spi_master_get_devdata(spi->master);
void (*tx_fifo)(struct sh_msiof_spi_priv *, const void *, int, int);
void (*rx_fifo)(struct sh_msiof_spi_priv *, void *, int, int);
int bits;
int bytes_per_word;
int bytes_done;
int words;
int n;
bool swab;
bits = sh_msiof_spi_bits(spi, t);
if (bits <= 8 && t->len > 15 && !(t->len & 3)) {
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
if ((unsigned long)t->tx_buf & 0x01)
tx_fifo = sh_msiof_spi_write_fifo_16u;
else
tx_fifo = sh_msiof_spi_write_fifo_16;
if ((unsigned long)t->rx_buf & 0x01)
rx_fifo = sh_msiof_spi_read_fifo_16u;
else
rx_fifo = sh_msiof_spi_read_fifo_16;
} else if (swab) {
bytes_per_word = 4;
if ((unsigned long)t->tx_buf & 0x03)
tx_fifo = sh_msiof_spi_write_fifo_s32u;
else
tx_fifo = sh_msiof_spi_write_fifo_s32;
if ((unsigned long)t->rx_buf & 0x03)
rx_fifo = sh_msiof_spi_read_fifo_s32u;
else
rx_fifo = sh_msiof_spi_read_fifo_s32;
} else {
bytes_per_word = 4;
if ((unsigned long)t->tx_buf & 0x03)
tx_fifo = sh_msiof_spi_write_fifo_32u;
else
tx_fifo = sh_msiof_spi_write_fifo_32;
if ((unsigned long)t->rx_buf & 0x03)
rx_fifo = sh_msiof_spi_read_fifo_32u;
else
rx_fifo = sh_msiof_spi_read_fifo_32;
}
sh_msiof_spi_set_clk_regs(p, clk_get_rate(p->clk),
sh_msiof_spi_hz(spi, t));
words = t->len / bytes_per_word;
bytes_done = 0;
while (bytes_done < t->len) {
void *rx_buf = t->rx_buf ? t->rx_buf + bytes_done : NULL;
const void *tx_buf = t->tx_buf ? t->tx_buf + bytes_done : NULL;
n = sh_msiof_spi_txrx_once(p, tx_fifo, rx_fifo,
tx_buf,
rx_buf,
words, bits);
if (n < 0)
break;
bytes_done += n * bytes_per_word;
words -= n;
}
return bytes_done;
}
static u32 sh_msiof_spi_txrx_word(struct spi_device *spi, unsigned nsecs,
u32 word, u8 bits)
{
BUG();
return 0;
}
static struct sh_msiof_spi_info *sh_msiof_spi_parse_dt(struct device *dev)
{
struct sh_msiof_spi_info *info;
struct device_node *np = dev->of_node;
u32 num_cs = 0;
info = devm_kzalloc(dev, sizeof(struct sh_msiof_spi_info), GFP_KERNEL);
if (!info) {
dev_err(dev, "failed to allocate setup data\n");
return NULL;
}
of_property_read_u32(np, "num-cs", &num_cs);
of_property_read_u32(np, "renesas,tx-fifo-size",
&info->tx_fifo_override);
of_property_read_u32(np, "renesas,rx-fifo-size",
&info->rx_fifo_override);
info->num_chipselect = num_cs;
return info;
}
static struct sh_msiof_spi_info *sh_msiof_spi_parse_dt(struct device *dev)
{
return NULL;
}
static int sh_msiof_spi_probe(struct platform_device *pdev)
{
struct resource *r;
struct spi_master *master;
struct sh_msiof_spi_priv *p;
int i;
int ret;
master = spi_alloc_master(&pdev->dev, sizeof(struct sh_msiof_spi_priv));
if (master == NULL) {
dev_err(&pdev->dev, "failed to allocate spi master\n");
ret = -ENOMEM;
goto err0;
}
p = spi_master_get_devdata(master);
platform_set_drvdata(pdev, p);
if (pdev->dev.of_node)
p->info = sh_msiof_spi_parse_dt(&pdev->dev);
else
p->info = dev_get_platdata(&pdev->dev);
if (!p->info) {
dev_err(&pdev->dev, "failed to obtain device info\n");
ret = -ENXIO;
goto err1;
}
init_completion(&p->done);
p->clk = clk_get(&pdev->dev, NULL);
if (IS_ERR(p->clk)) {
dev_err(&pdev->dev, "cannot get clock\n");
ret = PTR_ERR(p->clk);
goto err1;
}
r = platform_get_resource(pdev, IORESOURCE_MEM, 0);
i = platform_get_irq(pdev, 0);
if (!r || i < 0) {
dev_err(&pdev->dev, "cannot get platform resources\n");
ret = -ENOENT;
goto err2;
}
p->mapbase = ioremap_nocache(r->start, resource_size(r));
if (!p->mapbase) {
dev_err(&pdev->dev, "unable to ioremap\n");
ret = -ENXIO;
goto err2;
}
ret = request_irq(i, sh_msiof_spi_irq, 0,
dev_name(&pdev->dev), p);
if (ret) {
dev_err(&pdev->dev, "unable to request irq\n");
goto err3;
}
p->pdev = pdev;
pm_runtime_enable(&pdev->dev);
p->tx_fifo_size = 64;
p->rx_fifo_size = 64;
if (p->info->tx_fifo_override)
p->tx_fifo_size = p->info->tx_fifo_override;
if (p->info->rx_fifo_override)
p->rx_fifo_size = p->info->rx_fifo_override;
master->mode_bits = SPI_CPOL | SPI_CPHA | SPI_CS_HIGH;
master->mode_bits |= SPI_LSB_FIRST | SPI_3WIRE;
master->flags = 0;
master->bus_num = pdev->id;
master->num_chipselect = p->info->num_chipselect;
master->setup = spi_bitbang_setup;
master->cleanup = spi_bitbang_cleanup;
p->bitbang.master = master;
p->bitbang.chipselect = sh_msiof_spi_chipselect;
p->bitbang.setup_transfer = sh_msiof_spi_setup_transfer;
p->bitbang.txrx_bufs = sh_msiof_spi_txrx;
p->bitbang.txrx_word[SPI_MODE_0] = sh_msiof_spi_txrx_word;
p->bitbang.txrx_word[SPI_MODE_1] = sh_msiof_spi_txrx_word;
p->bitbang.txrx_word[SPI_MODE_2] = sh_msiof_spi_txrx_word;
p->bitbang.txrx_word[SPI_MODE_3] = sh_msiof_spi_txrx_word;
ret = spi_bitbang_start(&p->bitbang);
if (ret == 0)
return 0;
pm_runtime_disable(&pdev->dev);
err3:
iounmap(p->mapbase);
err2:
clk_put(p->clk);
err1:
spi_master_put(master);
err0:
return ret;
}
static int sh_msiof_spi_remove(struct platform_device *pdev)
{
struct sh_msiof_spi_priv *p = platform_get_drvdata(pdev);
int ret;
ret = spi_bitbang_stop(&p->bitbang);
if (!ret) {
pm_runtime_disable(&pdev->dev);
free_irq(platform_get_irq(pdev, 0), p);
iounmap(p->mapbase);
clk_put(p->clk);
spi_master_put(p->bitbang.master);
}
return ret;
}
