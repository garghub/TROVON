static inline void stm32_spi_set_bits(struct stm32_spi *spi,
u32 offset, u32 bits)
{
writel_relaxed(readl_relaxed(spi->base + offset) | bits,
spi->base + offset);
}
static inline void stm32_spi_clr_bits(struct stm32_spi *spi,
u32 offset, u32 bits)
{
writel_relaxed(readl_relaxed(spi->base + offset) & ~bits,
spi->base + offset);
}
static int stm32_spi_get_fifo_size(struct stm32_spi *spi)
{
unsigned long flags;
u32 count = 0;
spin_lock_irqsave(&spi->lock, flags);
stm32_spi_set_bits(spi, STM32_SPI_CR1, SPI_CR1_SPE);
while (readl_relaxed(spi->base + STM32_SPI_SR) & SPI_SR_TXP)
writeb_relaxed(++count, spi->base + STM32_SPI_TXDR);
stm32_spi_clr_bits(spi, STM32_SPI_CR1, SPI_CR1_SPE);
spin_unlock_irqrestore(&spi->lock, flags);
dev_dbg(spi->dev, "%d x 8-bit fifo size\n", count);
return count;
}
static int stm32_spi_get_bpw_mask(struct stm32_spi *spi)
{
unsigned long flags;
u32 cfg1, max_bpw;
spin_lock_irqsave(&spi->lock, flags);
stm32_spi_set_bits(spi, STM32_SPI_CFG1, SPI_CFG1_DSIZE);
cfg1 = readl_relaxed(spi->base + STM32_SPI_CFG1);
max_bpw = (cfg1 & SPI_CFG1_DSIZE) >> SPI_CFG1_DSIZE_SHIFT;
max_bpw += 1;
spin_unlock_irqrestore(&spi->lock, flags);
dev_dbg(spi->dev, "%d-bit maximum data frame\n", max_bpw);
return SPI_BPW_RANGE_MASK(4, max_bpw);
}
static int stm32_spi_prepare_mbr(struct stm32_spi *spi, u32 speed_hz)
{
u32 div, mbrdiv;
div = DIV_ROUND_UP(spi->clk_rate, speed_hz);
if (div < SPI_MBR_DIV_MIN ||
div > SPI_MBR_DIV_MAX)
return -EINVAL;
if (div & (div - 1))
mbrdiv = fls(div);
else
mbrdiv = fls(div) - 1;
spi->cur_speed = spi->clk_rate / (1 << mbrdiv);
return mbrdiv - 1;
}
static u32 stm32_spi_prepare_fthlv(struct stm32_spi *spi)
{
u32 fthlv, half_fifo;
half_fifo = (spi->fifo_size / 2);
if (spi->cur_bpw <= 8)
fthlv = half_fifo;
else if (spi->cur_bpw <= 16)
fthlv = half_fifo / 2;
else
fthlv = half_fifo / 4;
if (spi->cur_bpw > 8)
fthlv -= (fthlv % 2);
else
fthlv -= (fthlv % 4);
return fthlv;
}
static void stm32_spi_write_txfifo(struct stm32_spi *spi)
{
while ((spi->tx_len > 0) &&
(readl_relaxed(spi->base + STM32_SPI_SR) & SPI_SR_TXP)) {
u32 offs = spi->cur_xferlen - spi->tx_len;
if (spi->tx_len >= sizeof(u32)) {
const u32 *tx_buf32 = (const u32 *)(spi->tx_buf + offs);
writel_relaxed(*tx_buf32, spi->base + STM32_SPI_TXDR);
spi->tx_len -= sizeof(u32);
} else if (spi->tx_len >= sizeof(u16)) {
const u16 *tx_buf16 = (const u16 *)(spi->tx_buf + offs);
writew_relaxed(*tx_buf16, spi->base + STM32_SPI_TXDR);
spi->tx_len -= sizeof(u16);
} else {
const u8 *tx_buf8 = (const u8 *)(spi->tx_buf + offs);
writeb_relaxed(*tx_buf8, spi->base + STM32_SPI_TXDR);
spi->tx_len -= sizeof(u8);
}
}
dev_dbg(spi->dev, "%s: %d bytes left\n", __func__, spi->tx_len);
}
static void stm32_spi_read_rxfifo(struct stm32_spi *spi, bool flush)
{
u32 sr = readl_relaxed(spi->base + STM32_SPI_SR);
u32 rxplvl = (sr & SPI_SR_RXPLVL) >> SPI_SR_RXPLVL_SHIFT;
while ((spi->rx_len > 0) &&
((sr & SPI_SR_RXP) ||
(flush && ((sr & SPI_SR_RXWNE) || (rxplvl > 0))))) {
u32 offs = spi->cur_xferlen - spi->rx_len;
if ((spi->rx_len >= sizeof(u32)) ||
(flush && (sr & SPI_SR_RXWNE))) {
u32 *rx_buf32 = (u32 *)(spi->rx_buf + offs);
*rx_buf32 = readl_relaxed(spi->base + STM32_SPI_RXDR);
spi->rx_len -= sizeof(u32);
} else if ((spi->rx_len >= sizeof(u16)) ||
(flush && (rxplvl >= 2 || spi->cur_bpw > 8))) {
u16 *rx_buf16 = (u16 *)(spi->rx_buf + offs);
*rx_buf16 = readw_relaxed(spi->base + STM32_SPI_RXDR);
spi->rx_len -= sizeof(u16);
} else {
u8 *rx_buf8 = (u8 *)(spi->rx_buf + offs);
*rx_buf8 = readb_relaxed(spi->base + STM32_SPI_RXDR);
spi->rx_len -= sizeof(u8);
}
sr = readl_relaxed(spi->base + STM32_SPI_SR);
rxplvl = (sr & SPI_SR_RXPLVL) >> SPI_SR_RXPLVL_SHIFT;
}
dev_dbg(spi->dev, "%s%s: %d bytes left\n", __func__,
flush ? "(flush)" : "", spi->rx_len);
}
static void stm32_spi_enable(struct stm32_spi *spi)
{
dev_dbg(spi->dev, "enable controller\n");
stm32_spi_set_bits(spi, STM32_SPI_CR1, SPI_CR1_SPE);
}
static void stm32_spi_disable(struct stm32_spi *spi)
{
unsigned long flags;
u32 cr1, sr;
dev_dbg(spi->dev, "disable controller\n");
spin_lock_irqsave(&spi->lock, flags);
cr1 = readl_relaxed(spi->base + STM32_SPI_CR1);
if (!(cr1 & SPI_CR1_SPE)) {
spin_unlock_irqrestore(&spi->lock, flags);
return;
}
if (readl_relaxed_poll_timeout_atomic(spi->base + STM32_SPI_SR,
sr, !(sr & SPI_SR_EOT),
10, 100000) < 0) {
if (cr1 & SPI_CR1_CSTART) {
writel_relaxed(cr1 | SPI_CR1_CSUSP,
spi->base + STM32_SPI_CR1);
if (readl_relaxed_poll_timeout_atomic(
spi->base + STM32_SPI_SR,
sr, !(sr & SPI_SR_SUSP),
10, 100000) < 0)
dev_warn(spi->dev,
"Suspend request timeout\n");
}
}
if (!spi->cur_usedma && spi->rx_buf && (spi->rx_len > 0))
stm32_spi_read_rxfifo(spi, true);
if (spi->cur_usedma && spi->tx_buf)
dmaengine_terminate_all(spi->dma_tx);
if (spi->cur_usedma && spi->rx_buf)
dmaengine_terminate_all(spi->dma_rx);
stm32_spi_clr_bits(spi, STM32_SPI_CR1, SPI_CR1_SPE);
stm32_spi_clr_bits(spi, STM32_SPI_CFG1, SPI_CFG1_TXDMAEN |
SPI_CFG1_RXDMAEN);
writel_relaxed(0, spi->base + STM32_SPI_IER);
writel_relaxed(SPI_IFCR_ALL, spi->base + STM32_SPI_IFCR);
spin_unlock_irqrestore(&spi->lock, flags);
}
static bool stm32_spi_can_dma(struct spi_master *master,
struct spi_device *spi_dev,
struct spi_transfer *transfer)
{
struct stm32_spi *spi = spi_master_get_devdata(master);
dev_dbg(spi->dev, "%s: %s\n", __func__,
(transfer->len > spi->fifo_size) ? "true" : "false");
return (transfer->len > spi->fifo_size);
}
static irqreturn_t stm32_spi_irq(int irq, void *dev_id)
{
struct spi_master *master = dev_id;
struct stm32_spi *spi = spi_master_get_devdata(master);
u32 sr, ier, mask;
unsigned long flags;
bool end = false;
spin_lock_irqsave(&spi->lock, flags);
sr = readl_relaxed(spi->base + STM32_SPI_SR);
ier = readl_relaxed(spi->base + STM32_SPI_IER);
mask = ier;
mask |= SPI_SR_SUSP;
if (spi->rx_buf && !spi->cur_usedma)
mask |= SPI_SR_RXP;
if (!(sr & mask)) {
dev_dbg(spi->dev, "spurious IT (sr=0x%08x, ier=0x%08x)\n",
sr, ier);
spin_unlock_irqrestore(&spi->lock, flags);
return IRQ_NONE;
}
if (sr & SPI_SR_SUSP) {
dev_warn(spi->dev, "Communication suspended\n");
if (!spi->cur_usedma && (spi->rx_buf && (spi->rx_len > 0)))
stm32_spi_read_rxfifo(spi, false);
if (spi->cur_usedma)
end = true;
}
if (sr & SPI_SR_MODF) {
dev_warn(spi->dev, "Mode fault: transfer aborted\n");
end = true;
}
if (sr & SPI_SR_OVR) {
dev_warn(spi->dev, "Overrun: received value discarded\n");
if (!spi->cur_usedma && (spi->rx_buf && (spi->rx_len > 0)))
stm32_spi_read_rxfifo(spi, false);
if (spi->cur_usedma)
end = true;
}
if (sr & SPI_SR_EOT) {
if (!spi->cur_usedma && (spi->rx_buf && (spi->rx_len > 0)))
stm32_spi_read_rxfifo(spi, true);
end = true;
}
if (sr & SPI_SR_TXP)
if (!spi->cur_usedma && (spi->tx_buf && (spi->tx_len > 0)))
stm32_spi_write_txfifo(spi);
if (sr & SPI_SR_RXP)
if (!spi->cur_usedma && (spi->rx_buf && (spi->rx_len > 0)))
stm32_spi_read_rxfifo(spi, false);
writel_relaxed(mask, spi->base + STM32_SPI_IFCR);
spin_unlock_irqrestore(&spi->lock, flags);
if (end) {
spi_finalize_current_transfer(master);
stm32_spi_disable(spi);
}
return IRQ_HANDLED;
}
static int stm32_spi_setup(struct spi_device *spi_dev)
{
int ret = 0;
if (!gpio_is_valid(spi_dev->cs_gpio)) {
dev_err(&spi_dev->dev, "%d is not a valid gpio\n",
spi_dev->cs_gpio);
return -EINVAL;
}
dev_dbg(&spi_dev->dev, "%s: set gpio%d output %s\n", __func__,
spi_dev->cs_gpio,
(spi_dev->mode & SPI_CS_HIGH) ? "low" : "high");
ret = gpio_direction_output(spi_dev->cs_gpio,
!(spi_dev->mode & SPI_CS_HIGH));
return ret;
}
static int stm32_spi_prepare_msg(struct spi_master *master,
struct spi_message *msg)
{
struct stm32_spi *spi = spi_master_get_devdata(master);
struct spi_device *spi_dev = msg->spi;
struct device_node *np = spi_dev->dev.of_node;
unsigned long flags;
u32 cfg2_clrb = 0, cfg2_setb = 0;
spi->cur_midi = 0;
if (np && !of_property_read_u32(np, "st,spi-midi-ns", &spi->cur_midi))
dev_dbg(spi->dev, "%dns inter-data idleness\n", spi->cur_midi);
if (spi_dev->mode & SPI_CPOL)
cfg2_setb |= SPI_CFG2_CPOL;
else
cfg2_clrb |= SPI_CFG2_CPOL;
if (spi_dev->mode & SPI_CPHA)
cfg2_setb |= SPI_CFG2_CPHA;
else
cfg2_clrb |= SPI_CFG2_CPHA;
if (spi_dev->mode & SPI_LSB_FIRST)
cfg2_setb |= SPI_CFG2_LSBFRST;
else
cfg2_clrb |= SPI_CFG2_LSBFRST;
dev_dbg(spi->dev, "cpol=%d cpha=%d lsb_first=%d cs_high=%d\n",
spi_dev->mode & SPI_CPOL,
spi_dev->mode & SPI_CPHA,
spi_dev->mode & SPI_LSB_FIRST,
spi_dev->mode & SPI_CS_HIGH);
spin_lock_irqsave(&spi->lock, flags);
if (cfg2_clrb || cfg2_setb)
writel_relaxed(
(readl_relaxed(spi->base + STM32_SPI_CFG2) &
~cfg2_clrb) | cfg2_setb,
spi->base + STM32_SPI_CFG2);
spin_unlock_irqrestore(&spi->lock, flags);
return 0;
}
static void stm32_spi_dma_cb(void *data)
{
struct stm32_spi *spi = data;
unsigned long flags;
u32 sr;
spin_lock_irqsave(&spi->lock, flags);
sr = readl_relaxed(spi->base + STM32_SPI_SR);
spin_unlock_irqrestore(&spi->lock, flags);
if (!(sr & SPI_SR_EOT))
dev_warn(spi->dev, "DMA error (sr=0x%08x)\n", sr);
}
static void stm32_spi_dma_config(struct stm32_spi *spi,
struct dma_slave_config *dma_conf,
enum dma_transfer_direction dir)
{
enum dma_slave_buswidth buswidth;
u32 maxburst;
if (spi->cur_bpw <= 8)
buswidth = DMA_SLAVE_BUSWIDTH_1_BYTE;
else if (spi->cur_bpw <= 16)
buswidth = DMA_SLAVE_BUSWIDTH_2_BYTES;
else
buswidth = DMA_SLAVE_BUSWIDTH_4_BYTES;
if (spi->cur_fthlv == 2)
maxburst = 1;
else
maxburst = spi->cur_fthlv;
memset(dma_conf, 0, sizeof(struct dma_slave_config));
dma_conf->direction = dir;
if (dma_conf->direction == DMA_DEV_TO_MEM) {
dma_conf->src_addr = spi->phys_addr + STM32_SPI_RXDR;
dma_conf->src_addr_width = buswidth;
dma_conf->src_maxburst = maxburst;
dev_dbg(spi->dev, "Rx DMA config buswidth=%d, maxburst=%d\n",
buswidth, maxburst);
} else if (dma_conf->direction == DMA_MEM_TO_DEV) {
dma_conf->dst_addr = spi->phys_addr + STM32_SPI_TXDR;
dma_conf->dst_addr_width = buswidth;
dma_conf->dst_maxburst = maxburst;
dev_dbg(spi->dev, "Tx DMA config buswidth=%d, maxburst=%d\n",
buswidth, maxburst);
}
}
static int stm32_spi_transfer_one_irq(struct stm32_spi *spi)
{
unsigned long flags;
u32 ier = 0;
if (spi->tx_buf && spi->rx_buf)
ier |= SPI_IER_DXPIE;
else if (spi->tx_buf)
ier |= SPI_IER_TXPIE;
else if (spi->rx_buf)
ier |= SPI_IER_RXPIE;
ier |= SPI_IER_EOTIE | SPI_IER_TXTFIE | SPI_IER_OVRIE | SPI_IER_MODFIE;
spin_lock_irqsave(&spi->lock, flags);
stm32_spi_enable(spi);
if (spi->tx_buf)
stm32_spi_write_txfifo(spi);
stm32_spi_set_bits(spi, STM32_SPI_CR1, SPI_CR1_CSTART);
writel_relaxed(ier, spi->base + STM32_SPI_IER);
spin_unlock_irqrestore(&spi->lock, flags);
return 1;
}
static int stm32_spi_transfer_one_dma(struct stm32_spi *spi,
struct spi_transfer *xfer)
{
struct dma_slave_config tx_dma_conf, rx_dma_conf;
struct dma_async_tx_descriptor *tx_dma_desc, *rx_dma_desc;
unsigned long flags;
u32 ier = 0;
spin_lock_irqsave(&spi->lock, flags);
rx_dma_desc = NULL;
if (spi->rx_buf) {
stm32_spi_dma_config(spi, &rx_dma_conf, DMA_DEV_TO_MEM);
dmaengine_slave_config(spi->dma_rx, &rx_dma_conf);
stm32_spi_set_bits(spi, STM32_SPI_CFG1, SPI_CFG1_RXDMAEN);
rx_dma_desc = dmaengine_prep_slave_sg(
spi->dma_rx, xfer->rx_sg.sgl,
xfer->rx_sg.nents,
rx_dma_conf.direction,
DMA_PREP_INTERRUPT);
}
tx_dma_desc = NULL;
if (spi->tx_buf) {
stm32_spi_dma_config(spi, &tx_dma_conf, DMA_MEM_TO_DEV);
dmaengine_slave_config(spi->dma_tx, &tx_dma_conf);
tx_dma_desc = dmaengine_prep_slave_sg(
spi->dma_tx, xfer->tx_sg.sgl,
xfer->tx_sg.nents,
tx_dma_conf.direction,
DMA_PREP_INTERRUPT);
}
if ((spi->tx_buf && !tx_dma_desc) ||
(spi->rx_buf && !rx_dma_desc))
goto dma_desc_error;
if (rx_dma_desc) {
rx_dma_desc->callback = stm32_spi_dma_cb;
rx_dma_desc->callback_param = spi;
if (dma_submit_error(dmaengine_submit(rx_dma_desc))) {
dev_err(spi->dev, "Rx DMA submit failed\n");
goto dma_desc_error;
}
dma_async_issue_pending(spi->dma_rx);
}
if (tx_dma_desc) {
if (spi->cur_comm == SPI_SIMPLEX_TX) {
tx_dma_desc->callback = stm32_spi_dma_cb;
tx_dma_desc->callback_param = spi;
}
if (dma_submit_error(dmaengine_submit(tx_dma_desc))) {
dev_err(spi->dev, "Tx DMA submit failed\n");
goto dma_submit_error;
}
dma_async_issue_pending(spi->dma_tx);
stm32_spi_set_bits(spi, STM32_SPI_CFG1, SPI_CFG1_TXDMAEN);
}
ier |= SPI_IER_EOTIE | SPI_IER_TXTFIE | SPI_IER_OVRIE | SPI_IER_MODFIE;
writel_relaxed(ier, spi->base + STM32_SPI_IER);
stm32_spi_enable(spi);
stm32_spi_set_bits(spi, STM32_SPI_CR1, SPI_CR1_CSTART);
spin_unlock_irqrestore(&spi->lock, flags);
return 1;
dma_submit_error:
if (spi->rx_buf)
dmaengine_terminate_all(spi->dma_rx);
dma_desc_error:
stm32_spi_clr_bits(spi, STM32_SPI_CFG1, SPI_CFG1_RXDMAEN);
spin_unlock_irqrestore(&spi->lock, flags);
dev_info(spi->dev, "DMA issue: fall back to irq transfer\n");
return stm32_spi_transfer_one_irq(spi);
}
static int stm32_spi_transfer_one_setup(struct stm32_spi *spi,
struct spi_device *spi_dev,
struct spi_transfer *transfer)
{
unsigned long flags;
u32 cfg1_clrb = 0, cfg1_setb = 0, cfg2_clrb = 0, cfg2_setb = 0;
u32 mode, nb_words;
int ret = 0;
spin_lock_irqsave(&spi->lock, flags);
if (spi->cur_bpw != transfer->bits_per_word) {
u32 bpw, fthlv;
spi->cur_bpw = transfer->bits_per_word;
bpw = spi->cur_bpw - 1;
cfg1_clrb |= SPI_CFG1_DSIZE;
cfg1_setb |= (bpw << SPI_CFG1_DSIZE_SHIFT) & SPI_CFG1_DSIZE;
spi->cur_fthlv = stm32_spi_prepare_fthlv(spi);
fthlv = spi->cur_fthlv - 1;
cfg1_clrb |= SPI_CFG1_FTHLV;
cfg1_setb |= (fthlv << SPI_CFG1_FTHLV_SHIFT) & SPI_CFG1_FTHLV;
}
if (spi->cur_speed != transfer->speed_hz) {
int mbr;
mbr = stm32_spi_prepare_mbr(spi, transfer->speed_hz);
if (mbr < 0) {
ret = mbr;
goto out;
}
transfer->speed_hz = spi->cur_speed;
cfg1_clrb |= SPI_CFG1_MBR;
cfg1_setb |= ((u32)mbr << SPI_CFG1_MBR_SHIFT) & SPI_CFG1_MBR;
}
if (cfg1_clrb || cfg1_setb)
writel_relaxed((readl_relaxed(spi->base + STM32_SPI_CFG1) &
~cfg1_clrb) | cfg1_setb,
spi->base + STM32_SPI_CFG1);
mode = SPI_FULL_DUPLEX;
if (spi_dev->mode & SPI_3WIRE) {
mode = SPI_HALF_DUPLEX;
if (!transfer->tx_buf)
stm32_spi_clr_bits(spi, STM32_SPI_CR1, SPI_CR1_HDDIR);
else if (!transfer->rx_buf)
stm32_spi_set_bits(spi, STM32_SPI_CR1, SPI_CR1_HDDIR);
} else {
if (!transfer->tx_buf)
mode = SPI_SIMPLEX_RX;
else if (!transfer->rx_buf)
mode = SPI_SIMPLEX_TX;
}
if (spi->cur_comm != mode) {
spi->cur_comm = mode;
cfg2_clrb |= SPI_CFG2_COMM;
cfg2_setb |= (mode << SPI_CFG2_COMM_SHIFT) & SPI_CFG2_COMM;
}
cfg2_clrb |= SPI_CFG2_MIDI;
if ((transfer->len > 1) && (spi->cur_midi > 0)) {
u32 sck_period_ns = DIV_ROUND_UP(SPI_1HZ_NS, spi->cur_speed);
u32 midi = min((u32)DIV_ROUND_UP(spi->cur_midi, sck_period_ns),
(u32)SPI_CFG2_MIDI >> SPI_CFG2_MIDI_SHIFT);
dev_dbg(spi->dev, "period=%dns, midi=%d(=%dns)\n",
sck_period_ns, midi, midi * sck_period_ns);
cfg2_setb |= (midi << SPI_CFG2_MIDI_SHIFT) & SPI_CFG2_MIDI;
}
if (cfg2_clrb || cfg2_setb)
writel_relaxed((readl_relaxed(spi->base + STM32_SPI_CFG2) &
~cfg2_clrb) | cfg2_setb,
spi->base + STM32_SPI_CFG2);
if (spi->cur_bpw <= 8)
nb_words = transfer->len;
else if (spi->cur_bpw <= 16)
nb_words = DIV_ROUND_UP(transfer->len * 8, 16);
else
nb_words = DIV_ROUND_UP(transfer->len * 8, 32);
nb_words <<= SPI_CR2_TSIZE_SHIFT;
if (nb_words <= SPI_CR2_TSIZE) {
writel_relaxed(nb_words, spi->base + STM32_SPI_CR2);
} else {
ret = -EMSGSIZE;
goto out;
}
spi->cur_xferlen = transfer->len;
dev_dbg(spi->dev, "transfer communication mode set to %d\n",
spi->cur_comm);
dev_dbg(spi->dev,
"data frame of %d-bit, data packet of %d data frames\n",
spi->cur_bpw, spi->cur_fthlv);
dev_dbg(spi->dev, "speed set to %dHz\n", spi->cur_speed);
dev_dbg(spi->dev, "transfer of %d bytes (%d data frames)\n",
spi->cur_xferlen, nb_words);
dev_dbg(spi->dev, "dma %s\n",
(spi->cur_usedma) ? "enabled" : "disabled");
out:
spin_unlock_irqrestore(&spi->lock, flags);
return ret;
}
static int stm32_spi_transfer_one(struct spi_master *master,
struct spi_device *spi_dev,
struct spi_transfer *transfer)
{
struct stm32_spi *spi = spi_master_get_devdata(master);
int ret;
spi->tx_buf = transfer->tx_buf;
spi->rx_buf = transfer->rx_buf;
spi->tx_len = spi->tx_buf ? transfer->len : 0;
spi->rx_len = spi->rx_buf ? transfer->len : 0;
spi->cur_usedma = (master->can_dma &&
stm32_spi_can_dma(master, spi_dev, transfer));
ret = stm32_spi_transfer_one_setup(spi, spi_dev, transfer);
if (ret) {
dev_err(spi->dev, "SPI transfer setup failed\n");
return ret;
}
if (spi->cur_usedma)
return stm32_spi_transfer_one_dma(spi, transfer);
else
return stm32_spi_transfer_one_irq(spi);
}
static int stm32_spi_unprepare_msg(struct spi_master *master,
struct spi_message *msg)
{
struct stm32_spi *spi = spi_master_get_devdata(master);
stm32_spi_disable(spi);
return 0;
}
static int stm32_spi_config(struct stm32_spi *spi)
{
unsigned long flags;
spin_lock_irqsave(&spi->lock, flags);
stm32_spi_clr_bits(spi, STM32_SPI_I2SCFGR, SPI_I2SCFGR_I2SMOD);
stm32_spi_set_bits(spi, STM32_SPI_CR1, SPI_CR1_SSI |
SPI_CR1_HDDIR |
SPI_CR1_MASRX);
stm32_spi_set_bits(spi, STM32_SPI_CFG2, SPI_CFG2_MASTER |
SPI_CFG2_SSM |
SPI_CFG2_AFCNTR);
spin_unlock_irqrestore(&spi->lock, flags);
return 0;
}
static int stm32_spi_probe(struct platform_device *pdev)
{
struct spi_master *master;
struct stm32_spi *spi;
struct resource *res;
int i, ret;
master = spi_alloc_master(&pdev->dev, sizeof(struct stm32_spi));
if (!master) {
dev_err(&pdev->dev, "spi master allocation failed\n");
return -ENOMEM;
}
platform_set_drvdata(pdev, master);
spi = spi_master_get_devdata(master);
spi->dev = &pdev->dev;
spi->master = master;
spin_lock_init(&spi->lock);
res = platform_get_resource(pdev, IORESOURCE_MEM, 0);
spi->base = devm_ioremap_resource(&pdev->dev, res);
if (IS_ERR(spi->base)) {
ret = PTR_ERR(spi->base);
goto err_master_put;
}
spi->phys_addr = (dma_addr_t)res->start;
spi->irq = platform_get_irq(pdev, 0);
if (spi->irq <= 0) {
dev_err(&pdev->dev, "no irq: %d\n", spi->irq);
ret = -ENOENT;
goto err_master_put;
}
ret = devm_request_threaded_irq(&pdev->dev, spi->irq, NULL,
stm32_spi_irq, IRQF_ONESHOT,
pdev->name, master);
if (ret) {
dev_err(&pdev->dev, "irq%d request failed: %d\n", spi->irq,
ret);
goto err_master_put;
}
spi->clk = devm_clk_get(&pdev->dev, 0);
if (IS_ERR(spi->clk)) {
ret = PTR_ERR(spi->clk);
dev_err(&pdev->dev, "clk get failed: %d\n", ret);
goto err_master_put;
}
ret = clk_prepare_enable(spi->clk);
if (ret) {
dev_err(&pdev->dev, "clk enable failed: %d\n", ret);
goto err_master_put;
}
spi->clk_rate = clk_get_rate(spi->clk);
if (!spi->clk_rate) {
dev_err(&pdev->dev, "clk rate = 0\n");
ret = -EINVAL;
goto err_master_put;
}
spi->rst = devm_reset_control_get_exclusive(&pdev->dev, NULL);
if (!IS_ERR(spi->rst)) {
reset_control_assert(spi->rst);
udelay(2);
reset_control_deassert(spi->rst);
}
spi->fifo_size = stm32_spi_get_fifo_size(spi);
ret = stm32_spi_config(spi);
if (ret) {
dev_err(&pdev->dev, "controller configuration failed: %d\n",
ret);
goto err_clk_disable;
}
master->dev.of_node = pdev->dev.of_node;
master->auto_runtime_pm = true;
master->bus_num = pdev->id;
master->mode_bits = SPI_MODE_3 | SPI_CS_HIGH | SPI_LSB_FIRST |
SPI_3WIRE | SPI_LOOP;
master->bits_per_word_mask = stm32_spi_get_bpw_mask(spi);
master->max_speed_hz = spi->clk_rate / SPI_MBR_DIV_MIN;
master->min_speed_hz = spi->clk_rate / SPI_MBR_DIV_MAX;
master->setup = stm32_spi_setup;
master->prepare_message = stm32_spi_prepare_msg;
master->transfer_one = stm32_spi_transfer_one;
master->unprepare_message = stm32_spi_unprepare_msg;
spi->dma_tx = dma_request_slave_channel(spi->dev, "tx");
if (!spi->dma_tx)
dev_warn(&pdev->dev, "failed to request tx dma channel\n");
else
master->dma_tx = spi->dma_tx;
spi->dma_rx = dma_request_slave_channel(spi->dev, "rx");
if (!spi->dma_rx)
dev_warn(&pdev->dev, "failed to request rx dma channel\n");
else
master->dma_rx = spi->dma_rx;
if (spi->dma_tx || spi->dma_rx)
master->can_dma = stm32_spi_can_dma;
pm_runtime_set_active(&pdev->dev);
pm_runtime_enable(&pdev->dev);
ret = devm_spi_register_master(&pdev->dev, master);
if (ret) {
dev_err(&pdev->dev, "spi master registration failed: %d\n",
ret);
goto err_dma_release;
}
if (!master->cs_gpios) {
dev_err(&pdev->dev, "no CS gpios available\n");
ret = -EINVAL;
goto err_dma_release;
}
for (i = 0; i < master->num_chipselect; i++) {
if (!gpio_is_valid(master->cs_gpios[i])) {
dev_err(&pdev->dev, "%i is not a valid gpio\n",
master->cs_gpios[i]);
ret = -EINVAL;
goto err_dma_release;
}
ret = devm_gpio_request(&pdev->dev, master->cs_gpios[i],
DRIVER_NAME);
if (ret) {
dev_err(&pdev->dev, "can't get CS gpio %i\n",
master->cs_gpios[i]);
goto err_dma_release;
}
}
dev_info(&pdev->dev, "driver initialized\n");
return 0;
err_dma_release:
if (spi->dma_tx)
dma_release_channel(spi->dma_tx);
if (spi->dma_rx)
dma_release_channel(spi->dma_rx);
pm_runtime_disable(&pdev->dev);
err_clk_disable:
clk_disable_unprepare(spi->clk);
err_master_put:
spi_master_put(master);
return ret;
}
static int stm32_spi_remove(struct platform_device *pdev)
{
struct spi_master *master = platform_get_drvdata(pdev);
struct stm32_spi *spi = spi_master_get_devdata(master);
stm32_spi_disable(spi);
if (master->dma_tx)
dma_release_channel(master->dma_tx);
if (master->dma_rx)
dma_release_channel(master->dma_rx);
clk_disable_unprepare(spi->clk);
pm_runtime_disable(&pdev->dev);
return 0;
}
static int stm32_spi_runtime_suspend(struct device *dev)
{
struct spi_master *master = dev_get_drvdata(dev);
struct stm32_spi *spi = spi_master_get_devdata(master);
clk_disable_unprepare(spi->clk);
return 0;
}
static int stm32_spi_runtime_resume(struct device *dev)
{
struct spi_master *master = dev_get_drvdata(dev);
struct stm32_spi *spi = spi_master_get_devdata(master);
return clk_prepare_enable(spi->clk);
}
static int stm32_spi_suspend(struct device *dev)
{
struct spi_master *master = dev_get_drvdata(dev);
int ret;
ret = spi_master_suspend(master);
if (ret)
return ret;
return pm_runtime_force_suspend(dev);
}
static int stm32_spi_resume(struct device *dev)
{
struct spi_master *master = dev_get_drvdata(dev);
struct stm32_spi *spi = spi_master_get_devdata(master);
int ret;
ret = pm_runtime_force_resume(dev);
if (ret)
return ret;
ret = spi_master_resume(master);
if (ret)
clk_disable_unprepare(spi->clk);
return ret;
}
