static inline void mcspi_write_reg(struct spi_master *master,
int idx, u32 val)
{
struct omap2_mcspi *mcspi = spi_master_get_devdata(master);
__raw_writel(val, mcspi->base + idx);
}
static inline u32 mcspi_read_reg(struct spi_master *master, int idx)
{
struct omap2_mcspi *mcspi = spi_master_get_devdata(master);
return __raw_readl(mcspi->base + idx);
}
static inline void mcspi_write_cs_reg(const struct spi_device *spi,
int idx, u32 val)
{
struct omap2_mcspi_cs *cs = spi->controller_state;
__raw_writel(val, cs->base + idx);
}
static inline u32 mcspi_read_cs_reg(const struct spi_device *spi, int idx)
{
struct omap2_mcspi_cs *cs = spi->controller_state;
return __raw_readl(cs->base + idx);
}
static inline u32 mcspi_cached_chconf0(const struct spi_device *spi)
{
struct omap2_mcspi_cs *cs = spi->controller_state;
return cs->chconf0;
}
static inline void mcspi_write_chconf0(const struct spi_device *spi, u32 val)
{
struct omap2_mcspi_cs *cs = spi->controller_state;
cs->chconf0 = val;
mcspi_write_cs_reg(spi, OMAP2_MCSPI_CHCONF0, val);
mcspi_read_cs_reg(spi, OMAP2_MCSPI_CHCONF0);
}
static void omap2_mcspi_set_dma_req(const struct spi_device *spi,
int is_read, int enable)
{
u32 l, rw;
l = mcspi_cached_chconf0(spi);
if (is_read)
rw = OMAP2_MCSPI_CHCONF_DMAR;
else
rw = OMAP2_MCSPI_CHCONF_DMAW;
if (enable)
l |= rw;
else
l &= ~rw;
mcspi_write_chconf0(spi, l);
}
static void omap2_mcspi_set_enable(const struct spi_device *spi, int enable)
{
u32 l;
l = enable ? OMAP2_MCSPI_CHCTRL_EN : 0;
mcspi_write_cs_reg(spi, OMAP2_MCSPI_CHCTRL0, l);
mcspi_read_cs_reg(spi, OMAP2_MCSPI_CHCTRL0);
}
static void omap2_mcspi_force_cs(struct spi_device *spi, int cs_active)
{
u32 l;
l = mcspi_cached_chconf0(spi);
if (cs_active)
l |= OMAP2_MCSPI_CHCONF_FORCE;
else
l &= ~OMAP2_MCSPI_CHCONF_FORCE;
mcspi_write_chconf0(spi, l);
}
static void omap2_mcspi_set_master_mode(struct spi_master *master)
{
struct omap2_mcspi *mcspi = spi_master_get_devdata(master);
struct omap2_mcspi_regs *ctx = &mcspi->ctx;
u32 l;
l = mcspi_read_reg(master, OMAP2_MCSPI_MODULCTRL);
l &= ~(OMAP2_MCSPI_MODULCTRL_STEST | OMAP2_MCSPI_MODULCTRL_MS);
l |= OMAP2_MCSPI_MODULCTRL_SINGLE;
mcspi_write_reg(master, OMAP2_MCSPI_MODULCTRL, l);
ctx->modulctrl = l;
}
static void omap2_mcspi_restore_ctx(struct omap2_mcspi *mcspi)
{
struct spi_master *spi_cntrl = mcspi->master;
struct omap2_mcspi_regs *ctx = &mcspi->ctx;
struct omap2_mcspi_cs *cs;
mcspi_write_reg(spi_cntrl, OMAP2_MCSPI_MODULCTRL, ctx->modulctrl);
mcspi_write_reg(spi_cntrl, OMAP2_MCSPI_WAKEUPENABLE, ctx->wakeupenable);
list_for_each_entry(cs, &ctx->cs, node)
__raw_writel(cs->chconf0, cs->base + OMAP2_MCSPI_CHCONF0);
}
static int omap2_prepare_transfer(struct spi_master *master)
{
struct omap2_mcspi *mcspi = spi_master_get_devdata(master);
pm_runtime_get_sync(mcspi->dev);
return 0;
}
static int omap2_unprepare_transfer(struct spi_master *master)
{
struct omap2_mcspi *mcspi = spi_master_get_devdata(master);
pm_runtime_mark_last_busy(mcspi->dev);
pm_runtime_put_autosuspend(mcspi->dev);
return 0;
}
static int mcspi_wait_for_reg_bit(void __iomem *reg, unsigned long bit)
{
unsigned long timeout;
timeout = jiffies + msecs_to_jiffies(1000);
while (!(__raw_readl(reg) & bit)) {
if (time_after(jiffies, timeout))
return -1;
cpu_relax();
}
return 0;
}
static void omap2_mcspi_rx_callback(void *data)
{
struct spi_device *spi = data;
struct omap2_mcspi *mcspi = spi_master_get_devdata(spi->master);
struct omap2_mcspi_dma *mcspi_dma = &mcspi->dma_channels[spi->chip_select];
complete(&mcspi_dma->dma_rx_completion);
omap2_mcspi_set_dma_req(spi, 1, 0);
}
static void omap2_mcspi_tx_callback(void *data)
{
struct spi_device *spi = data;
struct omap2_mcspi *mcspi = spi_master_get_devdata(spi->master);
struct omap2_mcspi_dma *mcspi_dma = &mcspi->dma_channels[spi->chip_select];
complete(&mcspi_dma->dma_tx_completion);
omap2_mcspi_set_dma_req(spi, 0, 0);
}
static void omap2_mcspi_tx_dma(struct spi_device *spi,
struct spi_transfer *xfer,
struct dma_slave_config cfg)
{
struct omap2_mcspi *mcspi;
struct omap2_mcspi_dma *mcspi_dma;
unsigned int count;
u8 * rx;
const u8 * tx;
void __iomem *chstat_reg;
struct omap2_mcspi_cs *cs = spi->controller_state;
mcspi = spi_master_get_devdata(spi->master);
mcspi_dma = &mcspi->dma_channels[spi->chip_select];
count = xfer->len;
rx = xfer->rx_buf;
tx = xfer->tx_buf;
chstat_reg = cs->base + OMAP2_MCSPI_CHSTAT0;
if (mcspi_dma->dma_tx) {
struct dma_async_tx_descriptor *tx;
struct scatterlist sg;
dmaengine_slave_config(mcspi_dma->dma_tx, &cfg);
sg_init_table(&sg, 1);
sg_dma_address(&sg) = xfer->tx_dma;
sg_dma_len(&sg) = xfer->len;
tx = dmaengine_prep_slave_sg(mcspi_dma->dma_tx, &sg, 1,
DMA_MEM_TO_DEV, DMA_PREP_INTERRUPT | DMA_CTRL_ACK);
if (tx) {
tx->callback = omap2_mcspi_tx_callback;
tx->callback_param = spi;
dmaengine_submit(tx);
} else {
}
}
dma_async_issue_pending(mcspi_dma->dma_tx);
omap2_mcspi_set_dma_req(spi, 0, 1);
wait_for_completion(&mcspi_dma->dma_tx_completion);
dma_unmap_single(mcspi->dev, xfer->tx_dma, count,
DMA_TO_DEVICE);
if (rx == NULL) {
if (mcspi_wait_for_reg_bit(chstat_reg,
OMAP2_MCSPI_CHSTAT_TXS) < 0)
dev_err(&spi->dev, "TXS timed out\n");
else if (mcspi_wait_for_reg_bit(chstat_reg,
OMAP2_MCSPI_CHSTAT_EOT) < 0)
dev_err(&spi->dev, "EOT timed out\n");
}
}
static unsigned
omap2_mcspi_rx_dma(struct spi_device *spi, struct spi_transfer *xfer,
struct dma_slave_config cfg,
unsigned es)
{
struct omap2_mcspi *mcspi;
struct omap2_mcspi_dma *mcspi_dma;
unsigned int count;
u32 l;
int elements = 0;
int word_len, element_count;
struct omap2_mcspi_cs *cs = spi->controller_state;
mcspi = spi_master_get_devdata(spi->master);
mcspi_dma = &mcspi->dma_channels[spi->chip_select];
count = xfer->len;
word_len = cs->word_len;
l = mcspi_cached_chconf0(spi);
if (word_len <= 8)
element_count = count;
else if (word_len <= 16)
element_count = count >> 1;
else
element_count = count >> 2;
if (mcspi_dma->dma_rx) {
struct dma_async_tx_descriptor *tx;
struct scatterlist sg;
size_t len = xfer->len - es;
dmaengine_slave_config(mcspi_dma->dma_rx, &cfg);
if (l & OMAP2_MCSPI_CHCONF_TURBO)
len -= es;
sg_init_table(&sg, 1);
sg_dma_address(&sg) = xfer->rx_dma;
sg_dma_len(&sg) = len;
tx = dmaengine_prep_slave_sg(mcspi_dma->dma_rx, &sg, 1,
DMA_DEV_TO_MEM, DMA_PREP_INTERRUPT |
DMA_CTRL_ACK);
if (tx) {
tx->callback = omap2_mcspi_rx_callback;
tx->callback_param = spi;
dmaengine_submit(tx);
} else {
}
}
dma_async_issue_pending(mcspi_dma->dma_rx);
omap2_mcspi_set_dma_req(spi, 1, 1);
wait_for_completion(&mcspi_dma->dma_rx_completion);
dma_unmap_single(mcspi->dev, xfer->rx_dma, count,
DMA_FROM_DEVICE);
omap2_mcspi_set_enable(spi, 0);
elements = element_count - 1;
if (l & OMAP2_MCSPI_CHCONF_TURBO) {
elements--;
if (likely(mcspi_read_cs_reg(spi, OMAP2_MCSPI_CHSTAT0)
& OMAP2_MCSPI_CHSTAT_RXS)) {
u32 w;
w = mcspi_read_cs_reg(spi, OMAP2_MCSPI_RX0);
if (word_len <= 8)
((u8 *)xfer->rx_buf)[elements++] = w;
else if (word_len <= 16)
((u16 *)xfer->rx_buf)[elements++] = w;
else
((u32 *)xfer->rx_buf)[elements++] = w;
} else {
dev_err(&spi->dev, "DMA RX penultimate word empty");
count -= (word_len <= 8) ? 2 :
(word_len <= 16) ? 4 :
8;
omap2_mcspi_set_enable(spi, 1);
return count;
}
}
if (likely(mcspi_read_cs_reg(spi, OMAP2_MCSPI_CHSTAT0)
& OMAP2_MCSPI_CHSTAT_RXS)) {
u32 w;
w = mcspi_read_cs_reg(spi, OMAP2_MCSPI_RX0);
if (word_len <= 8)
((u8 *)xfer->rx_buf)[elements] = w;
else if (word_len <= 16)
((u16 *)xfer->rx_buf)[elements] = w;
else
((u32 *)xfer->rx_buf)[elements] = w;
} else {
dev_err(&spi->dev, "DMA RX last word empty");
count -= (word_len <= 8) ? 1 :
(word_len <= 16) ? 2 :
4;
}
omap2_mcspi_set_enable(spi, 1);
return count;
}
static unsigned
omap2_mcspi_txrx_dma(struct spi_device *spi, struct spi_transfer *xfer)
{
struct omap2_mcspi *mcspi;
struct omap2_mcspi_cs *cs = spi->controller_state;
struct omap2_mcspi_dma *mcspi_dma;
unsigned int count;
u32 l;
u8 *rx;
const u8 *tx;
struct dma_slave_config cfg;
enum dma_slave_buswidth width;
unsigned es;
mcspi = spi_master_get_devdata(spi->master);
mcspi_dma = &mcspi->dma_channels[spi->chip_select];
l = mcspi_cached_chconf0(spi);
if (cs->word_len <= 8) {
width = DMA_SLAVE_BUSWIDTH_1_BYTE;
es = 1;
} else if (cs->word_len <= 16) {
width = DMA_SLAVE_BUSWIDTH_2_BYTES;
es = 2;
} else {
width = DMA_SLAVE_BUSWIDTH_4_BYTES;
es = 4;
}
memset(&cfg, 0, sizeof(cfg));
cfg.src_addr = cs->phys + OMAP2_MCSPI_RX0;
cfg.dst_addr = cs->phys + OMAP2_MCSPI_TX0;
cfg.src_addr_width = width;
cfg.dst_addr_width = width;
cfg.src_maxburst = 1;
cfg.dst_maxburst = 1;
rx = xfer->rx_buf;
tx = xfer->tx_buf;
count = xfer->len;
if (tx != NULL)
omap2_mcspi_tx_dma(spi, xfer, cfg);
if (rx != NULL)
return omap2_mcspi_rx_dma(spi, xfer, cfg, es);
return count;
}
static unsigned
omap2_mcspi_txrx_pio(struct spi_device *spi, struct spi_transfer *xfer)
{
struct omap2_mcspi *mcspi;
struct omap2_mcspi_cs *cs = spi->controller_state;
unsigned int count, c;
u32 l;
void __iomem *base = cs->base;
void __iomem *tx_reg;
void __iomem *rx_reg;
void __iomem *chstat_reg;
int word_len;
mcspi = spi_master_get_devdata(spi->master);
count = xfer->len;
c = count;
word_len = cs->word_len;
l = mcspi_cached_chconf0(spi);
tx_reg = base + OMAP2_MCSPI_TX0;
rx_reg = base + OMAP2_MCSPI_RX0;
chstat_reg = base + OMAP2_MCSPI_CHSTAT0;
if (c < (word_len>>3))
return 0;
if (word_len <= 8) {
u8 *rx;
const u8 *tx;
rx = xfer->rx_buf;
tx = xfer->tx_buf;
do {
c -= 1;
if (tx != NULL) {
if (mcspi_wait_for_reg_bit(chstat_reg,
OMAP2_MCSPI_CHSTAT_TXS) < 0) {
dev_err(&spi->dev, "TXS timed out\n");
goto out;
}
dev_vdbg(&spi->dev, "write-%d %02x\n",
word_len, *tx);
__raw_writel(*tx++, tx_reg);
}
if (rx != NULL) {
if (mcspi_wait_for_reg_bit(chstat_reg,
OMAP2_MCSPI_CHSTAT_RXS) < 0) {
dev_err(&spi->dev, "RXS timed out\n");
goto out;
}
if (c == 1 && tx == NULL &&
(l & OMAP2_MCSPI_CHCONF_TURBO)) {
omap2_mcspi_set_enable(spi, 0);
*rx++ = __raw_readl(rx_reg);
dev_vdbg(&spi->dev, "read-%d %02x\n",
word_len, *(rx - 1));
if (mcspi_wait_for_reg_bit(chstat_reg,
OMAP2_MCSPI_CHSTAT_RXS) < 0) {
dev_err(&spi->dev,
"RXS timed out\n");
goto out;
}
c = 0;
} else if (c == 0 && tx == NULL) {
omap2_mcspi_set_enable(spi, 0);
}
*rx++ = __raw_readl(rx_reg);
dev_vdbg(&spi->dev, "read-%d %02x\n",
word_len, *(rx - 1));
}
} while (c);
} else if (word_len <= 16) {
u16 *rx;
const u16 *tx;
rx = xfer->rx_buf;
tx = xfer->tx_buf;
do {
c -= 2;
if (tx != NULL) {
if (mcspi_wait_for_reg_bit(chstat_reg,
OMAP2_MCSPI_CHSTAT_TXS) < 0) {
dev_err(&spi->dev, "TXS timed out\n");
goto out;
}
dev_vdbg(&spi->dev, "write-%d %04x\n",
word_len, *tx);
__raw_writel(*tx++, tx_reg);
}
if (rx != NULL) {
if (mcspi_wait_for_reg_bit(chstat_reg,
OMAP2_MCSPI_CHSTAT_RXS) < 0) {
dev_err(&spi->dev, "RXS timed out\n");
goto out;
}
if (c == 2 && tx == NULL &&
(l & OMAP2_MCSPI_CHCONF_TURBO)) {
omap2_mcspi_set_enable(spi, 0);
*rx++ = __raw_readl(rx_reg);
dev_vdbg(&spi->dev, "read-%d %04x\n",
word_len, *(rx - 1));
if (mcspi_wait_for_reg_bit(chstat_reg,
OMAP2_MCSPI_CHSTAT_RXS) < 0) {
dev_err(&spi->dev,
"RXS timed out\n");
goto out;
}
c = 0;
} else if (c == 0 && tx == NULL) {
omap2_mcspi_set_enable(spi, 0);
}
*rx++ = __raw_readl(rx_reg);
dev_vdbg(&spi->dev, "read-%d %04x\n",
word_len, *(rx - 1));
}
} while (c >= 2);
} else if (word_len <= 32) {
u32 *rx;
const u32 *tx;
rx = xfer->rx_buf;
tx = xfer->tx_buf;
do {
c -= 4;
if (tx != NULL) {
if (mcspi_wait_for_reg_bit(chstat_reg,
OMAP2_MCSPI_CHSTAT_TXS) < 0) {
dev_err(&spi->dev, "TXS timed out\n");
goto out;
}
dev_vdbg(&spi->dev, "write-%d %08x\n",
word_len, *tx);
__raw_writel(*tx++, tx_reg);
}
if (rx != NULL) {
if (mcspi_wait_for_reg_bit(chstat_reg,
OMAP2_MCSPI_CHSTAT_RXS) < 0) {
dev_err(&spi->dev, "RXS timed out\n");
goto out;
}
if (c == 4 && tx == NULL &&
(l & OMAP2_MCSPI_CHCONF_TURBO)) {
omap2_mcspi_set_enable(spi, 0);
*rx++ = __raw_readl(rx_reg);
dev_vdbg(&spi->dev, "read-%d %08x\n",
word_len, *(rx - 1));
if (mcspi_wait_for_reg_bit(chstat_reg,
OMAP2_MCSPI_CHSTAT_RXS) < 0) {
dev_err(&spi->dev,
"RXS timed out\n");
goto out;
}
c = 0;
} else if (c == 0 && tx == NULL) {
omap2_mcspi_set_enable(spi, 0);
}
*rx++ = __raw_readl(rx_reg);
dev_vdbg(&spi->dev, "read-%d %08x\n",
word_len, *(rx - 1));
}
} while (c >= 4);
}
if (xfer->rx_buf == NULL) {
if (mcspi_wait_for_reg_bit(chstat_reg,
OMAP2_MCSPI_CHSTAT_TXS) < 0) {
dev_err(&spi->dev, "TXS timed out\n");
} else if (mcspi_wait_for_reg_bit(chstat_reg,
OMAP2_MCSPI_CHSTAT_EOT) < 0)
dev_err(&spi->dev, "EOT timed out\n");
omap2_mcspi_set_enable(spi, 0);
}
out:
omap2_mcspi_set_enable(spi, 1);
return count - c;
}
static u32 omap2_mcspi_calc_divisor(u32 speed_hz)
{
u32 div;
for (div = 0; div < 15; div++)
if (speed_hz >= (OMAP2_MCSPI_MAX_FREQ >> div))
return div;
return 15;
}
static int omap2_mcspi_setup_transfer(struct spi_device *spi,
struct spi_transfer *t)
{
struct omap2_mcspi_cs *cs = spi->controller_state;
struct omap2_mcspi *mcspi;
struct spi_master *spi_cntrl;
u32 l = 0, div = 0;
u8 word_len = spi->bits_per_word;
u32 speed_hz = spi->max_speed_hz;
mcspi = spi_master_get_devdata(spi->master);
spi_cntrl = mcspi->master;
if (t != NULL && t->bits_per_word)
word_len = t->bits_per_word;
cs->word_len = word_len;
if (t && t->speed_hz)
speed_hz = t->speed_hz;
speed_hz = min_t(u32, speed_hz, OMAP2_MCSPI_MAX_FREQ);
div = omap2_mcspi_calc_divisor(speed_hz);
l = mcspi_cached_chconf0(spi);
l &= ~(OMAP2_MCSPI_CHCONF_IS|OMAP2_MCSPI_CHCONF_DPE1);
l |= OMAP2_MCSPI_CHCONF_DPE0;
l &= ~OMAP2_MCSPI_CHCONF_WL_MASK;
l |= (word_len - 1) << 7;
if (!(spi->mode & SPI_CS_HIGH))
l |= OMAP2_MCSPI_CHCONF_EPOL;
else
l &= ~OMAP2_MCSPI_CHCONF_EPOL;
l &= ~OMAP2_MCSPI_CHCONF_CLKD_MASK;
l |= div << 2;
if (spi->mode & SPI_CPOL)
l |= OMAP2_MCSPI_CHCONF_POL;
else
l &= ~OMAP2_MCSPI_CHCONF_POL;
if (spi->mode & SPI_CPHA)
l |= OMAP2_MCSPI_CHCONF_PHA;
else
l &= ~OMAP2_MCSPI_CHCONF_PHA;
mcspi_write_chconf0(spi, l);
dev_dbg(&spi->dev, "setup: speed %d, sample %s edge, clk %s\n",
OMAP2_MCSPI_MAX_FREQ >> div,
(spi->mode & SPI_CPHA) ? "trailing" : "leading",
(spi->mode & SPI_CPOL) ? "inverted" : "normal");
return 0;
}
static int omap2_mcspi_request_dma(struct spi_device *spi)
{
struct spi_master *master = spi->master;
struct omap2_mcspi *mcspi;
struct omap2_mcspi_dma *mcspi_dma;
dma_cap_mask_t mask;
unsigned sig;
mcspi = spi_master_get_devdata(master);
mcspi_dma = mcspi->dma_channels + spi->chip_select;
init_completion(&mcspi_dma->dma_rx_completion);
init_completion(&mcspi_dma->dma_tx_completion);
dma_cap_zero(mask);
dma_cap_set(DMA_SLAVE, mask);
sig = mcspi_dma->dma_rx_sync_dev;
mcspi_dma->dma_rx = dma_request_channel(mask, omap_dma_filter_fn, &sig);
if (!mcspi_dma->dma_rx) {
dev_err(&spi->dev, "no RX DMA engine channel for McSPI\n");
return -EAGAIN;
}
sig = mcspi_dma->dma_tx_sync_dev;
mcspi_dma->dma_tx = dma_request_channel(mask, omap_dma_filter_fn, &sig);
if (!mcspi_dma->dma_tx) {
dev_err(&spi->dev, "no TX DMA engine channel for McSPI\n");
dma_release_channel(mcspi_dma->dma_rx);
mcspi_dma->dma_rx = NULL;
return -EAGAIN;
}
return 0;
}
static int omap2_mcspi_setup(struct spi_device *spi)
{
int ret;
struct omap2_mcspi *mcspi = spi_master_get_devdata(spi->master);
struct omap2_mcspi_regs *ctx = &mcspi->ctx;
struct omap2_mcspi_dma *mcspi_dma;
struct omap2_mcspi_cs *cs = spi->controller_state;
if (spi->bits_per_word < 4 || spi->bits_per_word > 32) {
dev_dbg(&spi->dev, "setup: unsupported %d bit words\n",
spi->bits_per_word);
return -EINVAL;
}
mcspi_dma = &mcspi->dma_channels[spi->chip_select];
if (!cs) {
cs = kzalloc(sizeof *cs, GFP_KERNEL);
if (!cs)
return -ENOMEM;
cs->base = mcspi->base + spi->chip_select * 0x14;
cs->phys = mcspi->phys + spi->chip_select * 0x14;
cs->chconf0 = 0;
spi->controller_state = cs;
list_add_tail(&cs->node, &ctx->cs);
}
if (!mcspi_dma->dma_rx || !mcspi_dma->dma_tx) {
ret = omap2_mcspi_request_dma(spi);
if (ret < 0)
return ret;
}
ret = pm_runtime_get_sync(mcspi->dev);
if (ret < 0)
return ret;
ret = omap2_mcspi_setup_transfer(spi, NULL);
pm_runtime_mark_last_busy(mcspi->dev);
pm_runtime_put_autosuspend(mcspi->dev);
return ret;
}
static void omap2_mcspi_cleanup(struct spi_device *spi)
{
struct omap2_mcspi *mcspi;
struct omap2_mcspi_dma *mcspi_dma;
struct omap2_mcspi_cs *cs;
mcspi = spi_master_get_devdata(spi->master);
if (spi->controller_state) {
cs = spi->controller_state;
list_del(&cs->node);
kfree(cs);
}
if (spi->chip_select < spi->master->num_chipselect) {
mcspi_dma = &mcspi->dma_channels[spi->chip_select];
if (mcspi_dma->dma_rx) {
dma_release_channel(mcspi_dma->dma_rx);
mcspi_dma->dma_rx = NULL;
}
if (mcspi_dma->dma_tx) {
dma_release_channel(mcspi_dma->dma_tx);
mcspi_dma->dma_tx = NULL;
}
}
}
static void omap2_mcspi_work(struct omap2_mcspi *mcspi, struct spi_message *m)
{
struct spi_device *spi;
struct spi_transfer *t = NULL;
int cs_active = 0;
struct omap2_mcspi_cs *cs;
struct omap2_mcspi_device_config *cd;
int par_override = 0;
int status = 0;
u32 chconf;
spi = m->spi;
cs = spi->controller_state;
cd = spi->controller_data;
omap2_mcspi_set_enable(spi, 1);
list_for_each_entry(t, &m->transfers, transfer_list) {
if (t->tx_buf == NULL && t->rx_buf == NULL && t->len) {
status = -EINVAL;
break;
}
if (par_override || t->speed_hz || t->bits_per_word) {
par_override = 1;
status = omap2_mcspi_setup_transfer(spi, t);
if (status < 0)
break;
if (!t->speed_hz && !t->bits_per_word)
par_override = 0;
}
if (!cs_active) {
omap2_mcspi_force_cs(spi, 1);
cs_active = 1;
}
chconf = mcspi_cached_chconf0(spi);
chconf &= ~OMAP2_MCSPI_CHCONF_TRM_MASK;
chconf &= ~OMAP2_MCSPI_CHCONF_TURBO;
if (t->tx_buf == NULL)
chconf |= OMAP2_MCSPI_CHCONF_TRM_RX_ONLY;
else if (t->rx_buf == NULL)
chconf |= OMAP2_MCSPI_CHCONF_TRM_TX_ONLY;
if (cd && cd->turbo_mode && t->tx_buf == NULL) {
if (t->len > ((cs->word_len + 7) >> 3))
chconf |= OMAP2_MCSPI_CHCONF_TURBO;
}
mcspi_write_chconf0(spi, chconf);
if (t->len) {
unsigned count;
if (t->tx_buf == NULL)
__raw_writel(0, cs->base
+ OMAP2_MCSPI_TX0);
if (m->is_dma_mapped || t->len >= DMA_MIN_BYTES)
count = omap2_mcspi_txrx_dma(spi, t);
else
count = omap2_mcspi_txrx_pio(spi, t);
m->actual_length += count;
if (count != t->len) {
status = -EIO;
break;
}
}
if (t->delay_usecs)
udelay(t->delay_usecs);
if (t->cs_change) {
omap2_mcspi_force_cs(spi, 0);
cs_active = 0;
}
}
if (par_override) {
par_override = 0;
status = omap2_mcspi_setup_transfer(spi, NULL);
}
if (cs_active)
omap2_mcspi_force_cs(spi, 0);
omap2_mcspi_set_enable(spi, 0);
m->status = status;
}
static int omap2_mcspi_transfer_one_message(struct spi_master *master,
struct spi_message *m)
{
struct omap2_mcspi *mcspi;
struct spi_transfer *t;
mcspi = spi_master_get_devdata(master);
m->actual_length = 0;
m->status = 0;
if (list_empty(&m->transfers))
return -EINVAL;
list_for_each_entry(t, &m->transfers, transfer_list) {
const void *tx_buf = t->tx_buf;
void *rx_buf = t->rx_buf;
unsigned len = t->len;
if (t->speed_hz > OMAP2_MCSPI_MAX_FREQ
|| (len && !(rx_buf || tx_buf))
|| (t->bits_per_word &&
( t->bits_per_word < 4
|| t->bits_per_word > 32))) {
dev_dbg(mcspi->dev, "transfer: %d Hz, %d %s%s, %d bpw\n",
t->speed_hz,
len,
tx_buf ? "tx" : "",
rx_buf ? "rx" : "",
t->bits_per_word);
return -EINVAL;
}
if (t->speed_hz && t->speed_hz < (OMAP2_MCSPI_MAX_FREQ >> 15)) {
dev_dbg(mcspi->dev, "speed_hz %d below minimum %d Hz\n",
t->speed_hz,
OMAP2_MCSPI_MAX_FREQ >> 15);
return -EINVAL;
}
if (m->is_dma_mapped || len < DMA_MIN_BYTES)
continue;
if (tx_buf != NULL) {
t->tx_dma = dma_map_single(mcspi->dev, (void *) tx_buf,
len, DMA_TO_DEVICE);
if (dma_mapping_error(mcspi->dev, t->tx_dma)) {
dev_dbg(mcspi->dev, "dma %cX %d bytes error\n",
'T', len);
return -EINVAL;
}
}
if (rx_buf != NULL) {
t->rx_dma = dma_map_single(mcspi->dev, rx_buf, t->len,
DMA_FROM_DEVICE);
if (dma_mapping_error(mcspi->dev, t->rx_dma)) {
dev_dbg(mcspi->dev, "dma %cX %d bytes error\n",
'R', len);
if (tx_buf != NULL)
dma_unmap_single(mcspi->dev, t->tx_dma,
len, DMA_TO_DEVICE);
return -EINVAL;
}
}
}
omap2_mcspi_work(mcspi, m);
spi_finalize_current_message(master);
return 0;
}
static int __devinit omap2_mcspi_master_setup(struct omap2_mcspi *mcspi)
{
struct spi_master *master = mcspi->master;
struct omap2_mcspi_regs *ctx = &mcspi->ctx;
int ret = 0;
ret = pm_runtime_get_sync(mcspi->dev);
if (ret < 0)
return ret;
mcspi_write_reg(master, OMAP2_MCSPI_WAKEUPENABLE,
OMAP2_MCSPI_WAKEUPENABLE_WKEN);
ctx->wakeupenable = OMAP2_MCSPI_WAKEUPENABLE_WKEN;
omap2_mcspi_set_master_mode(master);
pm_runtime_mark_last_busy(mcspi->dev);
pm_runtime_put_autosuspend(mcspi->dev);
return 0;
}
static int omap_mcspi_runtime_resume(struct device *dev)
{
struct omap2_mcspi *mcspi;
struct spi_master *master;
master = dev_get_drvdata(dev);
mcspi = spi_master_get_devdata(master);
omap2_mcspi_restore_ctx(mcspi);
return 0;
}
static int __devinit omap2_mcspi_probe(struct platform_device *pdev)
{
struct spi_master *master;
const struct omap2_mcspi_platform_config *pdata;
struct omap2_mcspi *mcspi;
struct resource *r;
int status = 0, i;
u32 regs_offset = 0;
static int bus_num = 1;
struct device_node *node = pdev->dev.of_node;
const struct of_device_id *match;
struct pinctrl *pinctrl;
master = spi_alloc_master(&pdev->dev, sizeof *mcspi);
if (master == NULL) {
dev_dbg(&pdev->dev, "master allocation failed\n");
return -ENOMEM;
}
master->mode_bits = SPI_CPOL | SPI_CPHA | SPI_CS_HIGH;
master->setup = omap2_mcspi_setup;
master->prepare_transfer_hardware = omap2_prepare_transfer;
master->unprepare_transfer_hardware = omap2_unprepare_transfer;
master->transfer_one_message = omap2_mcspi_transfer_one_message;
master->cleanup = omap2_mcspi_cleanup;
master->dev.of_node = node;
match = of_match_device(omap_mcspi_of_match, &pdev->dev);
if (match) {
u32 num_cs = 1;
pdata = match->data;
of_property_read_u32(node, "ti,spi-num-cs", &num_cs);
master->num_chipselect = num_cs;
master->bus_num = bus_num++;
} else {
pdata = pdev->dev.platform_data;
master->num_chipselect = pdata->num_cs;
if (pdev->id != -1)
master->bus_num = pdev->id;
}
regs_offset = pdata->regs_offset;
dev_set_drvdata(&pdev->dev, master);
mcspi = spi_master_get_devdata(master);
mcspi->master = master;
r = platform_get_resource(pdev, IORESOURCE_MEM, 0);
if (r == NULL) {
status = -ENODEV;
goto free_master;
}
r->start += regs_offset;
r->end += regs_offset;
mcspi->phys = r->start;
mcspi->base = devm_request_and_ioremap(&pdev->dev, r);
if (!mcspi->base) {
dev_dbg(&pdev->dev, "can't ioremap MCSPI\n");
status = -ENOMEM;
goto free_master;
}
mcspi->dev = &pdev->dev;
INIT_LIST_HEAD(&mcspi->ctx.cs);
mcspi->dma_channels = kcalloc(master->num_chipselect,
sizeof(struct omap2_mcspi_dma),
GFP_KERNEL);
if (mcspi->dma_channels == NULL)
goto free_master;
for (i = 0; i < master->num_chipselect; i++) {
char dma_ch_name[14];
struct resource *dma_res;
sprintf(dma_ch_name, "rx%d", i);
dma_res = platform_get_resource_byname(pdev, IORESOURCE_DMA,
dma_ch_name);
if (!dma_res) {
dev_dbg(&pdev->dev, "cannot get DMA RX channel\n");
status = -ENODEV;
break;
}
mcspi->dma_channels[i].dma_rx_sync_dev = dma_res->start;
sprintf(dma_ch_name, "tx%d", i);
dma_res = platform_get_resource_byname(pdev, IORESOURCE_DMA,
dma_ch_name);
if (!dma_res) {
dev_dbg(&pdev->dev, "cannot get DMA TX channel\n");
status = -ENODEV;
break;
}
mcspi->dma_channels[i].dma_tx_sync_dev = dma_res->start;
}
if (status < 0)
goto dma_chnl_free;
pinctrl = devm_pinctrl_get_select_default(&pdev->dev);
if (IS_ERR(pinctrl))
dev_warn(&pdev->dev,
"pins are not configured from the driver\n");
pm_runtime_use_autosuspend(&pdev->dev);
pm_runtime_set_autosuspend_delay(&pdev->dev, SPI_AUTOSUSPEND_TIMEOUT);
pm_runtime_enable(&pdev->dev);
if (status || omap2_mcspi_master_setup(mcspi) < 0)
goto disable_pm;
status = spi_register_master(master);
if (status < 0)
goto disable_pm;
return status;
disable_pm:
pm_runtime_disable(&pdev->dev);
dma_chnl_free:
kfree(mcspi->dma_channels);
free_master:
spi_master_put(master);
return status;
}
static int __devexit omap2_mcspi_remove(struct platform_device *pdev)
{
struct spi_master *master;
struct omap2_mcspi *mcspi;
struct omap2_mcspi_dma *dma_channels;
master = dev_get_drvdata(&pdev->dev);
mcspi = spi_master_get_devdata(master);
dma_channels = mcspi->dma_channels;
pm_runtime_put_sync(mcspi->dev);
pm_runtime_disable(&pdev->dev);
spi_unregister_master(master);
kfree(dma_channels);
return 0;
}
static int omap2_mcspi_resume(struct device *dev)
{
struct spi_master *master = dev_get_drvdata(dev);
struct omap2_mcspi *mcspi = spi_master_get_devdata(master);
struct omap2_mcspi_regs *ctx = &mcspi->ctx;
struct omap2_mcspi_cs *cs;
pm_runtime_get_sync(mcspi->dev);
list_for_each_entry(cs, &ctx->cs, node) {
if ((cs->chconf0 & OMAP2_MCSPI_CHCONF_FORCE) == 0) {
cs->chconf0 |= OMAP2_MCSPI_CHCONF_FORCE;
__raw_writel(cs->chconf0, cs->base + OMAP2_MCSPI_CHCONF0);
cs->chconf0 &= ~OMAP2_MCSPI_CHCONF_FORCE;
__raw_writel(cs->chconf0, cs->base + OMAP2_MCSPI_CHCONF0);
}
}
pm_runtime_mark_last_busy(mcspi->dev);
pm_runtime_put_autosuspend(mcspi->dev);
return 0;
}
