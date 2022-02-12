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
size_t k;
if (!WARN_ON(!spi_hz || !parent_rate))
div = DIV_ROUND_UP(parent_rate, spi_hz);
for (k = 0; k < ARRAY_SIZE(sh_msiof_spi_clk_table); k++) {
if (sh_msiof_spi_clk_table[k].div >= div)
break;
}
k = min_t(int, k, ARRAY_SIZE(sh_msiof_spi_clk_table) - 1);
sh_msiof_write(p, TSCR, sh_msiof_spi_clk_table[k].scr);
if (!(p->chipdata->master_flags & SPI_MASTER_MUST_TX))
sh_msiof_write(p, RSCR, sh_msiof_spi_clk_table[k].scr);
}
static void sh_msiof_spi_set_pin_regs(struct sh_msiof_spi_priv *p,
u32 cpol, u32 cpha,
u32 tx_hi_z, u32 lsb_first, u32 cs_high)
{
u32 tmp;
int edge;
sh_msiof_write(p, FCTR, 0);
tmp = MDR1_SYNCMD_SPI | 1 << MDR1_FLD_SHIFT | MDR1_XXSTP;
tmp |= !cs_high << MDR1_SYNCAC_SHIFT;
tmp |= lsb_first << MDR1_BITLSB_SHIFT;
sh_msiof_write(p, TMDR1, tmp | MDR1_TRMD | TMDR1_PCON);
if (p->chipdata->master_flags & SPI_MASTER_MUST_TX) {
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
if (tx_buf || (p->chipdata->master_flags & SPI_MASTER_MUST_TX))
sh_msiof_write(p, TMDR2, dr2);
else
sh_msiof_write(p, TMDR2, dr2 | MDR2_GRPMASK1);
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
static int sh_msiof_spi_setup(struct spi_device *spi)
{
struct device_node *np = spi->master->dev.of_node;
struct sh_msiof_spi_priv *p = spi_master_get_devdata(spi->master);
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
reinit_completion(&p->done);
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
static int sh_msiof_transfer_one(struct spi_master *master,
struct spi_device *spi,
struct spi_transfer *t)
{
struct sh_msiof_spi_priv *p = spi_master_get_devdata(master);
void (*tx_fifo)(struct sh_msiof_spi_priv *, const void *, int, int);
void (*rx_fifo)(struct sh_msiof_spi_priv *, void *, int, int);
int bits;
int bytes_per_word;
int bytes_done;
int words;
int n;
bool swab;
bits = t->bits_per_word;
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
sh_msiof_spi_set_clk_regs(p, clk_get_rate(p->clk), t->speed_hz);
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
return 0;
}
static struct sh_msiof_spi_info *sh_msiof_spi_parse_dt(struct device *dev)
{
struct sh_msiof_spi_info *info;
struct device_node *np = dev->of_node;
u32 num_cs = 1;
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
const struct of_device_id *of_id;
struct sh_msiof_spi_priv *p;
int i;
int ret;
master = spi_alloc_master(&pdev->dev, sizeof(struct sh_msiof_spi_priv));
if (master == NULL) {
dev_err(&pdev->dev, "failed to allocate spi master\n");
return -ENOMEM;
}
p = spi_master_get_devdata(master);
platform_set_drvdata(pdev, p);
of_id = of_match_device(sh_msiof_match, &pdev->dev);
if (of_id) {
p->chipdata = of_id->data;
p->info = sh_msiof_spi_parse_dt(&pdev->dev);
} else {
p->chipdata = (const void *)pdev->id_entry->driver_data;
p->info = dev_get_platdata(&pdev->dev);
}
if (!p->info) {
dev_err(&pdev->dev, "failed to obtain device info\n");
ret = -ENXIO;
goto err1;
}
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
p->tx_fifo_size = p->chipdata->tx_fifo_size;
p->rx_fifo_size = p->chipdata->rx_fifo_size;
if (p->info->tx_fifo_override)
p->tx_fifo_size = p->info->tx_fifo_override;
if (p->info->rx_fifo_override)
p->rx_fifo_size = p->info->rx_fifo_override;
master->mode_bits = SPI_CPOL | SPI_CPHA | SPI_CS_HIGH;
master->mode_bits |= SPI_LSB_FIRST | SPI_3WIRE;
master->flags = p->chipdata->master_flags;
master->bus_num = pdev->id;
master->dev.of_node = pdev->dev.of_node;
master->num_chipselect = p->info->num_chipselect;
master->setup = sh_msiof_spi_setup;
master->prepare_message = sh_msiof_prepare_message;
master->bits_per_word_mask = SPI_BPW_RANGE_MASK(8, 32);
master->auto_runtime_pm = true;
master->transfer_one = sh_msiof_transfer_one;
ret = devm_spi_register_master(&pdev->dev, master);
if (ret < 0) {
dev_err(&pdev->dev, "spi_register_master error.\n");
goto err2;
}
return 0;
err2:
pm_runtime_disable(&pdev->dev);
err1:
spi_master_put(master);
return ret;
}
static int sh_msiof_spi_remove(struct platform_device *pdev)
{
pm_runtime_disable(&pdev->dev);
return 0;
}
