static inline void mcspi_write_reg(struct spi_master *master,
int idx, u32 val)
{
struct omap2_mcspi *mcspi = spi_master_get_devdata(master);
writel_relaxed(val, mcspi->base + idx);
}
static inline u32 mcspi_read_reg(struct spi_master *master, int idx)
{
struct omap2_mcspi *mcspi = spi_master_get_devdata(master);
return readl_relaxed(mcspi->base + idx);
}
static inline void mcspi_write_cs_reg(const struct spi_device *spi,
int idx, u32 val)
{
struct omap2_mcspi_cs *cs = spi->controller_state;
writel_relaxed(val, cs->base + idx);
}
static inline u32 mcspi_read_cs_reg(const struct spi_device *spi, int idx)
{
struct omap2_mcspi_cs *cs = spi->controller_state;
return readl_relaxed(cs->base + idx);
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
static inline int mcspi_bytes_per_word(int word_len)
{
if (word_len <= 8)
return 1;
else if (word_len <= 16)
return 2;
else
return 4;
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
struct omap2_mcspi_cs *cs = spi->controller_state;
u32 l;
l = cs->chctrl0;
if (enable)
l |= OMAP2_MCSPI_CHCTRL_EN;
else
l &= ~OMAP2_MCSPI_CHCTRL_EN;
cs->chctrl0 = l;
mcspi_write_cs_reg(spi, OMAP2_MCSPI_CHCTRL0, cs->chctrl0);
mcspi_read_cs_reg(spi, OMAP2_MCSPI_CHCTRL0);
}
static void omap2_mcspi_set_cs(struct spi_device *spi, bool enable)
{
struct omap2_mcspi *mcspi = spi_master_get_devdata(spi->master);
u32 l;
if (spi->mode & SPI_CS_HIGH)
enable = !enable;
if (spi->controller_state) {
int err = pm_runtime_get_sync(mcspi->dev);
if (err < 0) {
dev_err(mcspi->dev, "failed to get sync: %d\n", err);
return;
}
l = mcspi_cached_chconf0(spi);
if (enable)
l &= ~OMAP2_MCSPI_CHCONF_FORCE;
else
l |= OMAP2_MCSPI_CHCONF_FORCE;
mcspi_write_chconf0(spi, l);
pm_runtime_mark_last_busy(mcspi->dev);
pm_runtime_put_autosuspend(mcspi->dev);
}
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
static void omap2_mcspi_set_fifo(const struct spi_device *spi,
struct spi_transfer *t, int enable)
{
struct spi_master *master = spi->master;
struct omap2_mcspi_cs *cs = spi->controller_state;
struct omap2_mcspi *mcspi;
unsigned int wcnt;
int max_fifo_depth, fifo_depth, bytes_per_word;
u32 chconf, xferlevel;
mcspi = spi_master_get_devdata(master);
chconf = mcspi_cached_chconf0(spi);
if (enable) {
bytes_per_word = mcspi_bytes_per_word(cs->word_len);
if (t->len % bytes_per_word != 0)
goto disable_fifo;
if (t->rx_buf != NULL && t->tx_buf != NULL)
max_fifo_depth = OMAP2_MCSPI_MAX_FIFODEPTH / 2;
else
max_fifo_depth = OMAP2_MCSPI_MAX_FIFODEPTH;
fifo_depth = gcd(t->len, max_fifo_depth);
if (fifo_depth < 2 || fifo_depth % bytes_per_word != 0)
goto disable_fifo;
wcnt = t->len / bytes_per_word;
if (wcnt > OMAP2_MCSPI_MAX_FIFOWCNT)
goto disable_fifo;
xferlevel = wcnt << 16;
if (t->rx_buf != NULL) {
chconf |= OMAP2_MCSPI_CHCONF_FFER;
xferlevel |= (fifo_depth - 1) << 8;
}
if (t->tx_buf != NULL) {
chconf |= OMAP2_MCSPI_CHCONF_FFET;
xferlevel |= fifo_depth - 1;
}
mcspi_write_reg(master, OMAP2_MCSPI_XFERLEVEL, xferlevel);
mcspi_write_chconf0(spi, chconf);
mcspi->fifo_depth = fifo_depth;
return;
}
disable_fifo:
if (t->rx_buf != NULL)
chconf &= ~OMAP2_MCSPI_CHCONF_FFER;
if (t->tx_buf != NULL)
chconf &= ~OMAP2_MCSPI_CHCONF_FFET;
mcspi_write_chconf0(spi, chconf);
mcspi->fifo_depth = 0;
}
static void omap2_mcspi_restore_ctx(struct omap2_mcspi *mcspi)
{
struct spi_master *spi_cntrl = mcspi->master;
struct omap2_mcspi_regs *ctx = &mcspi->ctx;
struct omap2_mcspi_cs *cs;
mcspi_write_reg(spi_cntrl, OMAP2_MCSPI_MODULCTRL, ctx->modulctrl);
mcspi_write_reg(spi_cntrl, OMAP2_MCSPI_WAKEUPENABLE, ctx->wakeupenable);
list_for_each_entry(cs, &ctx->cs, node)
writel_relaxed(cs->chconf0, cs->base + OMAP2_MCSPI_CHCONF0);
}
static int mcspi_wait_for_reg_bit(void __iomem *reg, unsigned long bit)
{
unsigned long timeout;
timeout = jiffies + msecs_to_jiffies(1000);
while (!(readl_relaxed(reg) & bit)) {
if (time_after(jiffies, timeout)) {
if (!(readl_relaxed(reg) & bit))
return -ETIMEDOUT;
else
return 0;
}
cpu_relax();
}
return 0;
}
static void omap2_mcspi_rx_callback(void *data)
{
struct spi_device *spi = data;
struct omap2_mcspi *mcspi = spi_master_get_devdata(spi->master);
struct omap2_mcspi_dma *mcspi_dma = &mcspi->dma_channels[spi->chip_select];
omap2_mcspi_set_dma_req(spi, 1, 0);
complete(&mcspi_dma->dma_rx_completion);
}
static void omap2_mcspi_tx_callback(void *data)
{
struct spi_device *spi = data;
struct omap2_mcspi *mcspi = spi_master_get_devdata(spi->master);
struct omap2_mcspi_dma *mcspi_dma = &mcspi->dma_channels[spi->chip_select];
omap2_mcspi_set_dma_req(spi, 0, 0);
complete(&mcspi_dma->dma_tx_completion);
}
static void omap2_mcspi_tx_dma(struct spi_device *spi,
struct spi_transfer *xfer,
struct dma_slave_config cfg)
{
struct omap2_mcspi *mcspi;
struct omap2_mcspi_dma *mcspi_dma;
unsigned int count;
mcspi = spi_master_get_devdata(spi->master);
mcspi_dma = &mcspi->dma_channels[spi->chip_select];
count = xfer->len;
if (mcspi_dma->dma_tx) {
struct dma_async_tx_descriptor *tx;
dmaengine_slave_config(mcspi_dma->dma_tx, &cfg);
tx = dmaengine_prep_slave_sg(mcspi_dma->dma_tx, xfer->tx_sg.sgl,
xfer->tx_sg.nents,
DMA_MEM_TO_DEV,
DMA_PREP_INTERRUPT | DMA_CTRL_ACK);
if (tx) {
tx->callback = omap2_mcspi_tx_callback;
tx->callback_param = spi;
dmaengine_submit(tx);
} else {
}
}
dma_async_issue_pending(mcspi_dma->dma_tx);
omap2_mcspi_set_dma_req(spi, 0, 1);
}
static unsigned
omap2_mcspi_rx_dma(struct spi_device *spi, struct spi_transfer *xfer,
struct dma_slave_config cfg,
unsigned es)
{
struct omap2_mcspi *mcspi;
struct omap2_mcspi_dma *mcspi_dma;
unsigned int count, transfer_reduction = 0;
struct scatterlist *sg_out[2];
int nb_sizes = 0, out_mapped_nents[2], ret, x;
size_t sizes[2];
u32 l;
int elements = 0;
int word_len, element_count;
struct omap2_mcspi_cs *cs = spi->controller_state;
void __iomem *chstat_reg = cs->base + OMAP2_MCSPI_CHSTAT0;
mcspi = spi_master_get_devdata(spi->master);
mcspi_dma = &mcspi->dma_channels[spi->chip_select];
count = xfer->len;
if (mcspi->fifo_depth == 0)
transfer_reduction = es;
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
dmaengine_slave_config(mcspi_dma->dma_rx, &cfg);
if ((l & OMAP2_MCSPI_CHCONF_TURBO) && mcspi->fifo_depth == 0)
transfer_reduction += es;
if (transfer_reduction) {
sizes[0] = count - transfer_reduction;
sizes[1] = transfer_reduction;
nb_sizes = 2;
} else {
sizes[0] = count;
nb_sizes = 1;
}
ret = sg_split(xfer->rx_sg.sgl, xfer->rx_sg.nents,
0, nb_sizes,
sizes,
sg_out, out_mapped_nents,
GFP_KERNEL);
if (ret < 0) {
dev_err(&spi->dev, "sg_split failed\n");
return 0;
}
tx = dmaengine_prep_slave_sg(mcspi_dma->dma_rx,
sg_out[0],
out_mapped_nents[0],
DMA_DEV_TO_MEM,
DMA_PREP_INTERRUPT | DMA_CTRL_ACK);
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
for (x = 0; x < nb_sizes; x++)
kfree(sg_out[x]);
if (mcspi->fifo_depth > 0)
return count;
omap2_mcspi_set_enable(spi, 0);
elements = element_count - 1;
if (l & OMAP2_MCSPI_CHCONF_TURBO) {
elements--;
if (!mcspi_wait_for_reg_bit(chstat_reg,
OMAP2_MCSPI_CHSTAT_RXS)) {
u32 w;
w = mcspi_read_cs_reg(spi, OMAP2_MCSPI_RX0);
if (word_len <= 8)
((u8 *)xfer->rx_buf)[elements++] = w;
else if (word_len <= 16)
((u16 *)xfer->rx_buf)[elements++] = w;
else
((u32 *)xfer->rx_buf)[elements++] = w;
} else {
int bytes_per_word = mcspi_bytes_per_word(word_len);
dev_err(&spi->dev, "DMA RX penultimate word empty\n");
count -= (bytes_per_word << 1);
omap2_mcspi_set_enable(spi, 1);
return count;
}
}
if (!mcspi_wait_for_reg_bit(chstat_reg, OMAP2_MCSPI_CHSTAT_RXS)) {
u32 w;
w = mcspi_read_cs_reg(spi, OMAP2_MCSPI_RX0);
if (word_len <= 8)
((u8 *)xfer->rx_buf)[elements] = w;
else if (word_len <= 16)
((u16 *)xfer->rx_buf)[elements] = w;
else
((u32 *)xfer->rx_buf)[elements] = w;
} else {
dev_err(&spi->dev, "DMA RX last word empty\n");
count -= mcspi_bytes_per_word(word_len);
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
u32 burst;
void __iomem *chstat_reg;
void __iomem *irqstat_reg;
int wait_res;
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
count = xfer->len;
burst = 1;
if (mcspi->fifo_depth > 0) {
if (count > mcspi->fifo_depth)
burst = mcspi->fifo_depth / es;
else
burst = count / es;
}
memset(&cfg, 0, sizeof(cfg));
cfg.src_addr = cs->phys + OMAP2_MCSPI_RX0;
cfg.dst_addr = cs->phys + OMAP2_MCSPI_TX0;
cfg.src_addr_width = width;
cfg.dst_addr_width = width;
cfg.src_maxburst = burst;
cfg.dst_maxburst = burst;
rx = xfer->rx_buf;
tx = xfer->tx_buf;
if (tx != NULL)
omap2_mcspi_tx_dma(spi, xfer, cfg);
if (rx != NULL)
count = omap2_mcspi_rx_dma(spi, xfer, cfg, es);
if (tx != NULL) {
wait_for_completion(&mcspi_dma->dma_tx_completion);
if (mcspi->fifo_depth > 0) {
irqstat_reg = mcspi->base + OMAP2_MCSPI_IRQSTATUS;
if (mcspi_wait_for_reg_bit(irqstat_reg,
OMAP2_MCSPI_IRQSTATUS_EOW) < 0)
dev_err(&spi->dev, "EOW timed out\n");
mcspi_write_reg(mcspi->master, OMAP2_MCSPI_IRQSTATUS,
OMAP2_MCSPI_IRQSTATUS_EOW);
}
if (rx == NULL) {
chstat_reg = cs->base + OMAP2_MCSPI_CHSTAT0;
if (mcspi->fifo_depth > 0) {
wait_res = mcspi_wait_for_reg_bit(chstat_reg,
OMAP2_MCSPI_CHSTAT_TXFFE);
if (wait_res < 0)
dev_err(&spi->dev, "TXFFE timed out\n");
} else {
wait_res = mcspi_wait_for_reg_bit(chstat_reg,
OMAP2_MCSPI_CHSTAT_TXS);
if (wait_res < 0)
dev_err(&spi->dev, "TXS timed out\n");
}
if (wait_res >= 0 &&
(mcspi_wait_for_reg_bit(chstat_reg,
OMAP2_MCSPI_CHSTAT_EOT) < 0))
dev_err(&spi->dev, "EOT timed out\n");
}
}
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
writel_relaxed(*tx++, tx_reg);
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
*rx++ = readl_relaxed(rx_reg);
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
*rx++ = readl_relaxed(rx_reg);
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
writel_relaxed(*tx++, tx_reg);
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
*rx++ = readl_relaxed(rx_reg);
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
*rx++ = readl_relaxed(rx_reg);
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
writel_relaxed(*tx++, tx_reg);
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
*rx++ = readl_relaxed(rx_reg);
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
*rx++ = readl_relaxed(rx_reg);
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
u32 l = 0, clkd = 0, div, extclk = 0, clkg = 0;
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
if (speed_hz < (OMAP2_MCSPI_MAX_FREQ / OMAP2_MCSPI_MAX_DIVIDER)) {
clkd = omap2_mcspi_calc_divisor(speed_hz);
speed_hz = OMAP2_MCSPI_MAX_FREQ >> clkd;
clkg = 0;
} else {
div = (OMAP2_MCSPI_MAX_FREQ + speed_hz - 1) / speed_hz;
speed_hz = OMAP2_MCSPI_MAX_FREQ / div;
clkd = (div - 1) & 0xf;
extclk = (div - 1) >> 4;
clkg = OMAP2_MCSPI_CHCONF_CLKG;
}
l = mcspi_cached_chconf0(spi);
if (mcspi->pin_dir == MCSPI_PINDIR_D0_IN_D1_OUT) {
l &= ~OMAP2_MCSPI_CHCONF_IS;
l &= ~OMAP2_MCSPI_CHCONF_DPE1;
l |= OMAP2_MCSPI_CHCONF_DPE0;
} else {
l |= OMAP2_MCSPI_CHCONF_IS;
l |= OMAP2_MCSPI_CHCONF_DPE1;
l &= ~OMAP2_MCSPI_CHCONF_DPE0;
}
l &= ~OMAP2_MCSPI_CHCONF_WL_MASK;
l |= (word_len - 1) << 7;
if (!(spi->mode & SPI_CS_HIGH))
l |= OMAP2_MCSPI_CHCONF_EPOL;
else
l &= ~OMAP2_MCSPI_CHCONF_EPOL;
l &= ~OMAP2_MCSPI_CHCONF_CLKD_MASK;
l |= clkd << 2;
l &= ~OMAP2_MCSPI_CHCONF_CLKG;
l |= clkg;
if (clkg) {
cs->chctrl0 &= ~OMAP2_MCSPI_CHCTRL_EXTCLK_MASK;
cs->chctrl0 |= extclk << 8;
mcspi_write_cs_reg(spi, OMAP2_MCSPI_CHCTRL0, cs->chctrl0);
}
if (spi->mode & SPI_CPOL)
l |= OMAP2_MCSPI_CHCONF_POL;
else
l &= ~OMAP2_MCSPI_CHCONF_POL;
if (spi->mode & SPI_CPHA)
l |= OMAP2_MCSPI_CHCONF_PHA;
else
l &= ~OMAP2_MCSPI_CHCONF_PHA;
mcspi_write_chconf0(spi, l);
cs->mode = spi->mode;
dev_dbg(&spi->dev, "setup: speed %d, sample %s edge, clk %s\n",
speed_hz,
(spi->mode & SPI_CPHA) ? "trailing" : "leading",
(spi->mode & SPI_CPOL) ? "inverted" : "normal");
return 0;
}
static int omap2_mcspi_request_dma(struct spi_device *spi)
{
struct spi_master *master = spi->master;
struct omap2_mcspi *mcspi;
struct omap2_mcspi_dma *mcspi_dma;
int ret = 0;
mcspi = spi_master_get_devdata(master);
mcspi_dma = mcspi->dma_channels + spi->chip_select;
init_completion(&mcspi_dma->dma_rx_completion);
init_completion(&mcspi_dma->dma_tx_completion);
mcspi_dma->dma_rx = dma_request_chan(&master->dev,
mcspi_dma->dma_rx_ch_name);
if (IS_ERR(mcspi_dma->dma_rx)) {
ret = PTR_ERR(mcspi_dma->dma_rx);
mcspi_dma->dma_rx = NULL;
goto no_dma;
}
mcspi_dma->dma_tx = dma_request_chan(&master->dev,
mcspi_dma->dma_tx_ch_name);
if (IS_ERR(mcspi_dma->dma_tx)) {
ret = PTR_ERR(mcspi_dma->dma_tx);
mcspi_dma->dma_tx = NULL;
dma_release_channel(mcspi_dma->dma_rx);
mcspi_dma->dma_rx = NULL;
}
no_dma:
return ret;
}
static int omap2_mcspi_setup(struct spi_device *spi)
{
int ret;
struct omap2_mcspi *mcspi = spi_master_get_devdata(spi->master);
struct omap2_mcspi_regs *ctx = &mcspi->ctx;
struct omap2_mcspi_dma *mcspi_dma;
struct omap2_mcspi_cs *cs = spi->controller_state;
mcspi_dma = &mcspi->dma_channels[spi->chip_select];
if (!cs) {
cs = kzalloc(sizeof *cs, GFP_KERNEL);
if (!cs)
return -ENOMEM;
cs->base = mcspi->base + spi->chip_select * 0x14;
cs->phys = mcspi->phys + spi->chip_select * 0x14;
cs->mode = 0;
cs->chconf0 = 0;
cs->chctrl0 = 0;
spi->controller_state = cs;
list_add_tail(&cs->node, &ctx->cs);
if (gpio_is_valid(spi->cs_gpio)) {
ret = gpio_request(spi->cs_gpio, dev_name(&spi->dev));
if (ret) {
dev_err(&spi->dev, "failed to request gpio\n");
return ret;
}
gpio_direction_output(spi->cs_gpio,
!(spi->mode & SPI_CS_HIGH));
}
}
if (!mcspi_dma->dma_rx || !mcspi_dma->dma_tx) {
ret = omap2_mcspi_request_dma(spi);
if (ret)
dev_warn(&spi->dev, "not using DMA for McSPI (%d)\n",
ret);
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
if (gpio_is_valid(spi->cs_gpio))
gpio_free(spi->cs_gpio);
}
static int omap2_mcspi_transfer_one(struct spi_master *master,
struct spi_device *spi,
struct spi_transfer *t)
{
struct omap2_mcspi *mcspi;
struct omap2_mcspi_dma *mcspi_dma;
struct omap2_mcspi_cs *cs;
struct omap2_mcspi_device_config *cd;
int par_override = 0;
int status = 0;
u32 chconf;
mcspi = spi_master_get_devdata(master);
mcspi_dma = mcspi->dma_channels + spi->chip_select;
cs = spi->controller_state;
cd = spi->controller_data;
if (spi->mode != cs->mode)
par_override = 1;
omap2_mcspi_set_enable(spi, 0);
if (gpio_is_valid(spi->cs_gpio))
omap2_mcspi_set_cs(spi, spi->mode & SPI_CS_HIGH);
if (par_override ||
(t->speed_hz != spi->max_speed_hz) ||
(t->bits_per_word != spi->bits_per_word)) {
par_override = 1;
status = omap2_mcspi_setup_transfer(spi, t);
if (status < 0)
goto out;
if (t->speed_hz == spi->max_speed_hz &&
t->bits_per_word == spi->bits_per_word)
par_override = 0;
}
if (cd && cd->cs_per_word) {
chconf = mcspi->ctx.modulctrl;
chconf &= ~OMAP2_MCSPI_MODULCTRL_SINGLE;
mcspi_write_reg(master, OMAP2_MCSPI_MODULCTRL, chconf);
mcspi->ctx.modulctrl =
mcspi_read_cs_reg(spi, OMAP2_MCSPI_MODULCTRL);
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
if ((mcspi_dma->dma_rx && mcspi_dma->dma_tx) &&
master->cur_msg_mapped &&
master->can_dma(master, spi, t))
omap2_mcspi_set_fifo(spi, t, 1);
omap2_mcspi_set_enable(spi, 1);
if (t->tx_buf == NULL)
writel_relaxed(0, cs->base
+ OMAP2_MCSPI_TX0);
if ((mcspi_dma->dma_rx && mcspi_dma->dma_tx) &&
master->cur_msg_mapped &&
master->can_dma(master, spi, t))
count = omap2_mcspi_txrx_dma(spi, t);
else
count = omap2_mcspi_txrx_pio(spi, t);
if (count != t->len) {
status = -EIO;
goto out;
}
}
omap2_mcspi_set_enable(spi, 0);
if (mcspi->fifo_depth > 0)
omap2_mcspi_set_fifo(spi, t, 0);
out:
if (par_override) {
par_override = 0;
status = omap2_mcspi_setup_transfer(spi, NULL);
}
if (cd && cd->cs_per_word) {
chconf = mcspi->ctx.modulctrl;
chconf |= OMAP2_MCSPI_MODULCTRL_SINGLE;
mcspi_write_reg(master, OMAP2_MCSPI_MODULCTRL, chconf);
mcspi->ctx.modulctrl =
mcspi_read_cs_reg(spi, OMAP2_MCSPI_MODULCTRL);
}
omap2_mcspi_set_enable(spi, 0);
if (gpio_is_valid(spi->cs_gpio))
omap2_mcspi_set_cs(spi, !(spi->mode & SPI_CS_HIGH));
if (mcspi->fifo_depth > 0 && t)
omap2_mcspi_set_fifo(spi, t, 0);
return status;
}
static int omap2_mcspi_prepare_message(struct spi_master *master,
struct spi_message *msg)
{
struct omap2_mcspi *mcspi = spi_master_get_devdata(master);
struct omap2_mcspi_regs *ctx = &mcspi->ctx;
struct omap2_mcspi_cs *cs;
list_for_each_entry(cs, &ctx->cs, node) {
if (msg->spi->controller_state == cs)
continue;
if ((cs->chconf0 & OMAP2_MCSPI_CHCONF_FORCE)) {
cs->chconf0 &= ~OMAP2_MCSPI_CHCONF_FORCE;
writel_relaxed(cs->chconf0,
cs->base + OMAP2_MCSPI_CHCONF0);
readl_relaxed(cs->base + OMAP2_MCSPI_CHCONF0);
}
}
return 0;
}
static bool omap2_mcspi_can_dma(struct spi_master *master,
struct spi_device *spi,
struct spi_transfer *xfer)
{
return (xfer->len >= DMA_MIN_BYTES);
}
static int omap2_mcspi_master_setup(struct omap2_mcspi *mcspi)
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
static int omap2_mcspi_probe(struct platform_device *pdev)
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
master = spi_alloc_master(&pdev->dev, sizeof *mcspi);
if (master == NULL) {
dev_dbg(&pdev->dev, "master allocation failed\n");
return -ENOMEM;
}
master->mode_bits = SPI_CPOL | SPI_CPHA | SPI_CS_HIGH;
master->bits_per_word_mask = SPI_BPW_RANGE_MASK(4, 32);
master->setup = omap2_mcspi_setup;
master->auto_runtime_pm = true;
master->prepare_message = omap2_mcspi_prepare_message;
master->can_dma = omap2_mcspi_can_dma;
master->transfer_one = omap2_mcspi_transfer_one;
master->set_cs = omap2_mcspi_set_cs;
master->cleanup = omap2_mcspi_cleanup;
master->dev.of_node = node;
master->max_speed_hz = OMAP2_MCSPI_MAX_FREQ;
master->min_speed_hz = OMAP2_MCSPI_MAX_FREQ >> 15;
platform_set_drvdata(pdev, master);
mcspi = spi_master_get_devdata(master);
mcspi->master = master;
match = of_match_device(omap_mcspi_of_match, &pdev->dev);
if (match) {
u32 num_cs = 1;
pdata = match->data;
of_property_read_u32(node, "ti,spi-num-cs", &num_cs);
master->num_chipselect = num_cs;
master->bus_num = bus_num++;
if (of_get_property(node, "ti,pindir-d0-out-d1-in", NULL))
mcspi->pin_dir = MCSPI_PINDIR_D0_OUT_D1_IN;
} else {
pdata = dev_get_platdata(&pdev->dev);
master->num_chipselect = pdata->num_cs;
if (pdev->id != -1)
master->bus_num = pdev->id;
mcspi->pin_dir = pdata->pin_dir;
}
regs_offset = pdata->regs_offset;
r = platform_get_resource(pdev, IORESOURCE_MEM, 0);
mcspi->base = devm_ioremap_resource(&pdev->dev, r);
if (IS_ERR(mcspi->base)) {
status = PTR_ERR(mcspi->base);
goto free_master;
}
mcspi->phys = r->start + regs_offset;
mcspi->base += regs_offset;
mcspi->dev = &pdev->dev;
INIT_LIST_HEAD(&mcspi->ctx.cs);
mcspi->dma_channels = devm_kcalloc(&pdev->dev, master->num_chipselect,
sizeof(struct omap2_mcspi_dma),
GFP_KERNEL);
if (mcspi->dma_channels == NULL) {
status = -ENOMEM;
goto free_master;
}
for (i = 0; i < master->num_chipselect; i++) {
sprintf(mcspi->dma_channels[i].dma_rx_ch_name, "rx%d", i);
sprintf(mcspi->dma_channels[i].dma_tx_ch_name, "tx%d", i);
}
if (status < 0)
goto free_master;
pm_runtime_use_autosuspend(&pdev->dev);
pm_runtime_set_autosuspend_delay(&pdev->dev, SPI_AUTOSUSPEND_TIMEOUT);
pm_runtime_enable(&pdev->dev);
status = omap2_mcspi_master_setup(mcspi);
if (status < 0)
goto disable_pm;
status = devm_spi_register_master(&pdev->dev, master);
if (status < 0)
goto disable_pm;
return status;
disable_pm:
pm_runtime_dont_use_autosuspend(&pdev->dev);
pm_runtime_put_sync(&pdev->dev);
pm_runtime_disable(&pdev->dev);
free_master:
spi_master_put(master);
return status;
}
static int omap2_mcspi_remove(struct platform_device *pdev)
{
struct spi_master *master = platform_get_drvdata(pdev);
struct omap2_mcspi *mcspi = spi_master_get_devdata(master);
pm_runtime_dont_use_autosuspend(mcspi->dev);
pm_runtime_put_sync(mcspi->dev);
pm_runtime_disable(&pdev->dev);
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
writel_relaxed(cs->chconf0, cs->base + OMAP2_MCSPI_CHCONF0);
cs->chconf0 &= ~OMAP2_MCSPI_CHCONF_FORCE;
writel_relaxed(cs->chconf0, cs->base + OMAP2_MCSPI_CHCONF0);
}
}
pm_runtime_mark_last_busy(mcspi->dev);
pm_runtime_put_autosuspend(mcspi->dev);
return pinctrl_pm_select_default_state(dev);
}
static int omap2_mcspi_suspend(struct device *dev)
{
return pinctrl_pm_select_sleep_state(dev);
}
