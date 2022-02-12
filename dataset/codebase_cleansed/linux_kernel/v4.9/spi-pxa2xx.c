static inline const struct lpss_config
*lpss_get_config(const struct driver_data *drv_data)
{
return &lpss_platforms[drv_data->ssp_type - LPSS_LPT_SSP];
}
static bool is_lpss_ssp(const struct driver_data *drv_data)
{
switch (drv_data->ssp_type) {
case LPSS_LPT_SSP:
case LPSS_BYT_SSP:
case LPSS_BSW_SSP:
case LPSS_SPT_SSP:
case LPSS_BXT_SSP:
return true;
default:
return false;
}
}
static bool is_quark_x1000_ssp(const struct driver_data *drv_data)
{
return drv_data->ssp_type == QUARK_X1000_SSP;
}
static u32 pxa2xx_spi_get_ssrc1_change_mask(const struct driver_data *drv_data)
{
switch (drv_data->ssp_type) {
case QUARK_X1000_SSP:
return QUARK_X1000_SSCR1_CHANGE_MASK;
case CE4100_SSP:
return CE4100_SSCR1_CHANGE_MASK;
default:
return SSCR1_CHANGE_MASK;
}
}
static u32
pxa2xx_spi_get_rx_default_thre(const struct driver_data *drv_data)
{
switch (drv_data->ssp_type) {
case QUARK_X1000_SSP:
return RX_THRESH_QUARK_X1000_DFLT;
case CE4100_SSP:
return RX_THRESH_CE4100_DFLT;
default:
return RX_THRESH_DFLT;
}
}
static bool pxa2xx_spi_txfifo_full(const struct driver_data *drv_data)
{
u32 mask;
switch (drv_data->ssp_type) {
case QUARK_X1000_SSP:
mask = QUARK_X1000_SSSR_TFL_MASK;
break;
case CE4100_SSP:
mask = CE4100_SSSR_TFL_MASK;
break;
default:
mask = SSSR_TFL_MASK;
break;
}
return (pxa2xx_spi_read(drv_data, SSSR) & mask) == mask;
}
static void pxa2xx_spi_clear_rx_thre(const struct driver_data *drv_data,
u32 *sccr1_reg)
{
u32 mask;
switch (drv_data->ssp_type) {
case QUARK_X1000_SSP:
mask = QUARK_X1000_SSCR1_RFT;
break;
case CE4100_SSP:
mask = CE4100_SSCR1_RFT;
break;
default:
mask = SSCR1_RFT;
break;
}
*sccr1_reg &= ~mask;
}
static void pxa2xx_spi_set_rx_thre(const struct driver_data *drv_data,
u32 *sccr1_reg, u32 threshold)
{
switch (drv_data->ssp_type) {
case QUARK_X1000_SSP:
*sccr1_reg |= QUARK_X1000_SSCR1_RxTresh(threshold);
break;
case CE4100_SSP:
*sccr1_reg |= CE4100_SSCR1_RxTresh(threshold);
break;
default:
*sccr1_reg |= SSCR1_RxTresh(threshold);
break;
}
}
static u32 pxa2xx_configure_sscr0(const struct driver_data *drv_data,
u32 clk_div, u8 bits)
{
switch (drv_data->ssp_type) {
case QUARK_X1000_SSP:
return clk_div
| QUARK_X1000_SSCR0_Motorola
| QUARK_X1000_SSCR0_DataSize(bits > 32 ? 8 : bits)
| SSCR0_SSE;
default:
return clk_div
| SSCR0_Motorola
| SSCR0_DataSize(bits > 16 ? bits - 16 : bits)
| SSCR0_SSE
| (bits > 16 ? SSCR0_EDSS : 0);
}
}
static u32 __lpss_ssp_read_priv(struct driver_data *drv_data, unsigned offset)
{
WARN_ON(!drv_data->lpss_base);
return readl(drv_data->lpss_base + offset);
}
static void __lpss_ssp_write_priv(struct driver_data *drv_data,
unsigned offset, u32 value)
{
WARN_ON(!drv_data->lpss_base);
writel(value, drv_data->lpss_base + offset);
}
static void lpss_ssp_setup(struct driver_data *drv_data)
{
const struct lpss_config *config;
u32 value;
config = lpss_get_config(drv_data);
drv_data->lpss_base = drv_data->ioaddr + config->offset;
value = __lpss_ssp_read_priv(drv_data, config->reg_cs_ctrl);
value &= ~(LPSS_CS_CONTROL_SW_MODE | LPSS_CS_CONTROL_CS_HIGH);
value |= LPSS_CS_CONTROL_SW_MODE | LPSS_CS_CONTROL_CS_HIGH;
__lpss_ssp_write_priv(drv_data, config->reg_cs_ctrl, value);
if (drv_data->master_info->enable_dma) {
__lpss_ssp_write_priv(drv_data, config->reg_ssp, 1);
if (config->reg_general >= 0) {
value = __lpss_ssp_read_priv(drv_data,
config->reg_general);
value |= LPSS_GENERAL_REG_RXTO_HOLDOFF_DISABLE;
__lpss_ssp_write_priv(drv_data,
config->reg_general, value);
}
}
}
static void lpss_ssp_select_cs(struct driver_data *drv_data,
const struct lpss_config *config)
{
u32 value, cs;
if (!config->cs_sel_mask)
return;
value = __lpss_ssp_read_priv(drv_data, config->reg_cs_ctrl);
cs = drv_data->master->cur_msg->spi->chip_select;
cs <<= config->cs_sel_shift;
if (cs != (value & config->cs_sel_mask)) {
value &= ~config->cs_sel_mask;
value |= cs;
__lpss_ssp_write_priv(drv_data,
config->reg_cs_ctrl, value);
ndelay(1000000000 /
(drv_data->master->max_speed_hz / 2));
}
}
static void lpss_ssp_cs_control(struct driver_data *drv_data, bool enable)
{
const struct lpss_config *config;
u32 value;
config = lpss_get_config(drv_data);
if (enable)
lpss_ssp_select_cs(drv_data, config);
value = __lpss_ssp_read_priv(drv_data, config->reg_cs_ctrl);
if (enable)
value &= ~LPSS_CS_CONTROL_CS_HIGH;
else
value |= LPSS_CS_CONTROL_CS_HIGH;
__lpss_ssp_write_priv(drv_data, config->reg_cs_ctrl, value);
}
static void cs_assert(struct driver_data *drv_data)
{
struct chip_data *chip =
spi_get_ctldata(drv_data->master->cur_msg->spi);
if (drv_data->ssp_type == CE4100_SSP) {
pxa2xx_spi_write(drv_data, SSSR, chip->frm);
return;
}
if (chip->cs_control) {
chip->cs_control(PXA2XX_CS_ASSERT);
return;
}
if (gpio_is_valid(chip->gpio_cs)) {
gpio_set_value(chip->gpio_cs, chip->gpio_cs_inverted);
return;
}
if (is_lpss_ssp(drv_data))
lpss_ssp_cs_control(drv_data, true);
}
static void cs_deassert(struct driver_data *drv_data)
{
struct chip_data *chip =
spi_get_ctldata(drv_data->master->cur_msg->spi);
if (drv_data->ssp_type == CE4100_SSP)
return;
if (chip->cs_control) {
chip->cs_control(PXA2XX_CS_DEASSERT);
return;
}
if (gpio_is_valid(chip->gpio_cs)) {
gpio_set_value(chip->gpio_cs, !chip->gpio_cs_inverted);
return;
}
if (is_lpss_ssp(drv_data))
lpss_ssp_cs_control(drv_data, false);
}
int pxa2xx_spi_flush(struct driver_data *drv_data)
{
unsigned long limit = loops_per_jiffy << 1;
do {
while (pxa2xx_spi_read(drv_data, SSSR) & SSSR_RNE)
pxa2xx_spi_read(drv_data, SSDR);
} while ((pxa2xx_spi_read(drv_data, SSSR) & SSSR_BSY) && --limit);
write_SSSR_CS(drv_data, SSSR_ROR);
return limit;
}
static int null_writer(struct driver_data *drv_data)
{
u8 n_bytes = drv_data->n_bytes;
if (pxa2xx_spi_txfifo_full(drv_data)
|| (drv_data->tx == drv_data->tx_end))
return 0;
pxa2xx_spi_write(drv_data, SSDR, 0);
drv_data->tx += n_bytes;
return 1;
}
static int null_reader(struct driver_data *drv_data)
{
u8 n_bytes = drv_data->n_bytes;
while ((pxa2xx_spi_read(drv_data, SSSR) & SSSR_RNE)
&& (drv_data->rx < drv_data->rx_end)) {
pxa2xx_spi_read(drv_data, SSDR);
drv_data->rx += n_bytes;
}
return drv_data->rx == drv_data->rx_end;
}
static int u8_writer(struct driver_data *drv_data)
{
if (pxa2xx_spi_txfifo_full(drv_data)
|| (drv_data->tx == drv_data->tx_end))
return 0;
pxa2xx_spi_write(drv_data, SSDR, *(u8 *)(drv_data->tx));
++drv_data->tx;
return 1;
}
static int u8_reader(struct driver_data *drv_data)
{
while ((pxa2xx_spi_read(drv_data, SSSR) & SSSR_RNE)
&& (drv_data->rx < drv_data->rx_end)) {
*(u8 *)(drv_data->rx) = pxa2xx_spi_read(drv_data, SSDR);
++drv_data->rx;
}
return drv_data->rx == drv_data->rx_end;
}
static int u16_writer(struct driver_data *drv_data)
{
if (pxa2xx_spi_txfifo_full(drv_data)
|| (drv_data->tx == drv_data->tx_end))
return 0;
pxa2xx_spi_write(drv_data, SSDR, *(u16 *)(drv_data->tx));
drv_data->tx += 2;
return 1;
}
static int u16_reader(struct driver_data *drv_data)
{
while ((pxa2xx_spi_read(drv_data, SSSR) & SSSR_RNE)
&& (drv_data->rx < drv_data->rx_end)) {
*(u16 *)(drv_data->rx) = pxa2xx_spi_read(drv_data, SSDR);
drv_data->rx += 2;
}
return drv_data->rx == drv_data->rx_end;
}
static int u32_writer(struct driver_data *drv_data)
{
if (pxa2xx_spi_txfifo_full(drv_data)
|| (drv_data->tx == drv_data->tx_end))
return 0;
pxa2xx_spi_write(drv_data, SSDR, *(u32 *)(drv_data->tx));
drv_data->tx += 4;
return 1;
}
static int u32_reader(struct driver_data *drv_data)
{
while ((pxa2xx_spi_read(drv_data, SSSR) & SSSR_RNE)
&& (drv_data->rx < drv_data->rx_end)) {
*(u32 *)(drv_data->rx) = pxa2xx_spi_read(drv_data, SSDR);
drv_data->rx += 4;
}
return drv_data->rx == drv_data->rx_end;
}
void *pxa2xx_spi_next_transfer(struct driver_data *drv_data)
{
struct spi_message *msg = drv_data->master->cur_msg;
struct spi_transfer *trans = drv_data->cur_transfer;
if (trans->transfer_list.next != &msg->transfers) {
drv_data->cur_transfer =
list_entry(trans->transfer_list.next,
struct spi_transfer,
transfer_list);
return RUNNING_STATE;
} else
return DONE_STATE;
}
static void giveback(struct driver_data *drv_data)
{
struct spi_transfer* last_transfer;
struct spi_message *msg;
unsigned long timeout;
msg = drv_data->master->cur_msg;
drv_data->cur_transfer = NULL;
last_transfer = list_last_entry(&msg->transfers, struct spi_transfer,
transfer_list);
if (last_transfer->delay_usecs)
udelay(last_transfer->delay_usecs);
timeout = jiffies + msecs_to_jiffies(10);
while (pxa2xx_spi_read(drv_data, SSSR) & SSSR_BSY &&
!time_after(jiffies, timeout))
cpu_relax();
if (!last_transfer->cs_change)
cs_deassert(drv_data);
else {
struct spi_message *next_msg;
next_msg = spi_get_next_queued_message(drv_data->master);
if ((next_msg && next_msg->spi != msg->spi) ||
msg->state == ERROR_STATE)
cs_deassert(drv_data);
}
spi_finalize_current_message(drv_data->master);
}
static void reset_sccr1(struct driver_data *drv_data)
{
struct chip_data *chip =
spi_get_ctldata(drv_data->master->cur_msg->spi);
u32 sccr1_reg;
sccr1_reg = pxa2xx_spi_read(drv_data, SSCR1) & ~drv_data->int_cr1;
switch (drv_data->ssp_type) {
case QUARK_X1000_SSP:
sccr1_reg &= ~QUARK_X1000_SSCR1_RFT;
break;
case CE4100_SSP:
sccr1_reg &= ~CE4100_SSCR1_RFT;
break;
default:
sccr1_reg &= ~SSCR1_RFT;
break;
}
sccr1_reg |= chip->threshold;
pxa2xx_spi_write(drv_data, SSCR1, sccr1_reg);
}
static void int_error_stop(struct driver_data *drv_data, const char* msg)
{
write_SSSR_CS(drv_data, drv_data->clear_sr);
reset_sccr1(drv_data);
if (!pxa25x_ssp_comp(drv_data))
pxa2xx_spi_write(drv_data, SSTO, 0);
pxa2xx_spi_flush(drv_data);
pxa2xx_spi_write(drv_data, SSCR0,
pxa2xx_spi_read(drv_data, SSCR0) & ~SSCR0_SSE);
dev_err(&drv_data->pdev->dev, "%s\n", msg);
drv_data->master->cur_msg->state = ERROR_STATE;
tasklet_schedule(&drv_data->pump_transfers);
}
static void int_transfer_complete(struct driver_data *drv_data)
{
write_SSSR_CS(drv_data, drv_data->clear_sr);
reset_sccr1(drv_data);
if (!pxa25x_ssp_comp(drv_data))
pxa2xx_spi_write(drv_data, SSTO, 0);
drv_data->master->cur_msg->actual_length += drv_data->len -
(drv_data->rx_end - drv_data->rx);
drv_data->master->cur_msg->state = pxa2xx_spi_next_transfer(drv_data);
tasklet_schedule(&drv_data->pump_transfers);
}
static irqreturn_t interrupt_transfer(struct driver_data *drv_data)
{
u32 irq_mask = (pxa2xx_spi_read(drv_data, SSCR1) & SSCR1_TIE) ?
drv_data->mask_sr : drv_data->mask_sr & ~SSSR_TFS;
u32 irq_status = pxa2xx_spi_read(drv_data, SSSR) & irq_mask;
if (irq_status & SSSR_ROR) {
int_error_stop(drv_data, "interrupt_transfer: fifo overrun");
return IRQ_HANDLED;
}
if (irq_status & SSSR_TINT) {
pxa2xx_spi_write(drv_data, SSSR, SSSR_TINT);
if (drv_data->read(drv_data)) {
int_transfer_complete(drv_data);
return IRQ_HANDLED;
}
}
do {
if (drv_data->read(drv_data)) {
int_transfer_complete(drv_data);
return IRQ_HANDLED;
}
} while (drv_data->write(drv_data));
if (drv_data->read(drv_data)) {
int_transfer_complete(drv_data);
return IRQ_HANDLED;
}
if (drv_data->tx == drv_data->tx_end) {
u32 bytes_left;
u32 sccr1_reg;
sccr1_reg = pxa2xx_spi_read(drv_data, SSCR1);
sccr1_reg &= ~SSCR1_TIE;
if (pxa25x_ssp_comp(drv_data)) {
u32 rx_thre;
pxa2xx_spi_clear_rx_thre(drv_data, &sccr1_reg);
bytes_left = drv_data->rx_end - drv_data->rx;
switch (drv_data->n_bytes) {
case 4:
bytes_left >>= 1;
case 2:
bytes_left >>= 1;
}
rx_thre = pxa2xx_spi_get_rx_default_thre(drv_data);
if (rx_thre > bytes_left)
rx_thre = bytes_left;
pxa2xx_spi_set_rx_thre(drv_data, &sccr1_reg, rx_thre);
}
pxa2xx_spi_write(drv_data, SSCR1, sccr1_reg);
}
return IRQ_HANDLED;
}
static irqreturn_t ssp_int(int irq, void *dev_id)
{
struct driver_data *drv_data = dev_id;
u32 sccr1_reg;
u32 mask = drv_data->mask_sr;
u32 status;
if (pm_runtime_suspended(&drv_data->pdev->dev))
return IRQ_NONE;
status = pxa2xx_spi_read(drv_data, SSSR);
if (status == ~0)
return IRQ_NONE;
sccr1_reg = pxa2xx_spi_read(drv_data, SSCR1);
if (!(sccr1_reg & SSCR1_TIE))
mask &= ~SSSR_TFS;
if (!(sccr1_reg & SSCR1_TINTE))
mask &= ~SSSR_TINT;
if (!(status & mask))
return IRQ_NONE;
if (!drv_data->master->cur_msg) {
pxa2xx_spi_write(drv_data, SSCR0,
pxa2xx_spi_read(drv_data, SSCR0)
& ~SSCR0_SSE);
pxa2xx_spi_write(drv_data, SSCR1,
pxa2xx_spi_read(drv_data, SSCR1)
& ~drv_data->int_cr1);
if (!pxa25x_ssp_comp(drv_data))
pxa2xx_spi_write(drv_data, SSTO, 0);
write_SSSR_CS(drv_data, drv_data->clear_sr);
dev_err(&drv_data->pdev->dev,
"bad message state in interrupt handler\n");
return IRQ_HANDLED;
}
return drv_data->transfer_handler(drv_data);
}
static unsigned int quark_x1000_get_clk_div(int rate, u32 *dds)
{
unsigned long xtal = 200000000;
unsigned long fref = xtal / 2;
unsigned long fref1 = fref / 2;
unsigned long fref2 = fref * 2 / 5;
unsigned long scale;
unsigned long q, q1, q2;
long r, r1, r2;
u32 mul;
mul = (1 << 24) >> 1;
q1 = DIV_ROUND_UP(fref1, rate);
if (q1 > 256) {
scale = fls_long(q1 - 1);
if (scale > 9) {
q1 >>= scale - 9;
mul >>= scale - 9;
}
q1 += q1 & 1;
}
scale = __ffs(q1);
q1 >>= scale;
mul >>= scale;
r1 = abs(fref1 / (1 << (24 - fls_long(mul))) / q1 - rate);
q2 = DIV_ROUND_UP(fref2, rate);
r2 = abs(fref2 / q2 - rate);
if (r2 >= r1 || q2 > 256) {
r = r1;
q = q1;
} else {
r = r2;
q = q2;
mul = (1 << 24) * 2 / 5;
}
if (fref / rate >= 80) {
u64 fssp;
u32 m;
q1 = DIV_ROUND_UP(fref, rate);
m = (1 << 24) / q1;
fssp = (u64)fref * m;
do_div(fssp, 1 << 24);
r1 = abs(fssp - rate);
if (r1 < r) {
q = 1;
mul = m;
}
}
*dds = mul;
return q - 1;
}
static unsigned int ssp_get_clk_div(struct driver_data *drv_data, int rate)
{
unsigned long ssp_clk = drv_data->master->max_speed_hz;
const struct ssp_device *ssp = drv_data->ssp;
rate = min_t(int, ssp_clk, rate);
if (ssp->type == PXA25x_SSP || ssp->type == CE4100_SSP)
return (ssp_clk / (2 * rate) - 1) & 0xff;
else
return (ssp_clk / rate - 1) & 0xfff;
}
static unsigned int pxa2xx_ssp_get_clk_div(struct driver_data *drv_data,
int rate)
{
struct chip_data *chip =
spi_get_ctldata(drv_data->master->cur_msg->spi);
unsigned int clk_div;
switch (drv_data->ssp_type) {
case QUARK_X1000_SSP:
clk_div = quark_x1000_get_clk_div(rate, &chip->dds_rate);
break;
default:
clk_div = ssp_get_clk_div(drv_data, rate);
break;
}
return clk_div << 8;
}
static bool pxa2xx_spi_can_dma(struct spi_master *master,
struct spi_device *spi,
struct spi_transfer *xfer)
{
struct chip_data *chip = spi_get_ctldata(spi);
return chip->enable_dma &&
xfer->len <= MAX_DMA_LEN &&
xfer->len >= chip->dma_burst_size;
}
static void pump_transfers(unsigned long data)
{
struct driver_data *drv_data = (struct driver_data *)data;
struct spi_master *master = drv_data->master;
struct spi_message *message = master->cur_msg;
struct chip_data *chip = spi_get_ctldata(message->spi);
u32 dma_thresh = chip->dma_threshold;
u32 dma_burst = chip->dma_burst_size;
u32 change_mask = pxa2xx_spi_get_ssrc1_change_mask(drv_data);
struct spi_transfer *transfer;
struct spi_transfer *previous;
u32 clk_div;
u8 bits;
u32 speed;
u32 cr0;
u32 cr1;
int err;
int dma_mapped;
transfer = drv_data->cur_transfer;
if (message->state == ERROR_STATE) {
message->status = -EIO;
giveback(drv_data);
return;
}
if (message->state == DONE_STATE) {
message->status = 0;
giveback(drv_data);
return;
}
if (message->state == RUNNING_STATE) {
previous = list_entry(transfer->transfer_list.prev,
struct spi_transfer,
transfer_list);
if (previous->delay_usecs)
udelay(previous->delay_usecs);
if (previous->cs_change)
cs_deassert(drv_data);
}
if (transfer->len > MAX_DMA_LEN && chip->enable_dma) {
if (message->is_dma_mapped
|| transfer->rx_dma || transfer->tx_dma) {
dev_err(&drv_data->pdev->dev,
"pump_transfers: mapped transfer length of "
"%u is greater than %d\n",
transfer->len, MAX_DMA_LEN);
message->status = -EINVAL;
giveback(drv_data);
return;
}
dev_warn_ratelimited(&message->spi->dev,
"pump_transfers: DMA disabled for transfer length %ld "
"greater than %d\n",
(long)drv_data->len, MAX_DMA_LEN);
}
if (pxa2xx_spi_flush(drv_data) == 0) {
dev_err(&drv_data->pdev->dev, "pump_transfers: flush failed\n");
message->status = -EIO;
giveback(drv_data);
return;
}
drv_data->n_bytes = chip->n_bytes;
drv_data->tx = (void *)transfer->tx_buf;
drv_data->tx_end = drv_data->tx + transfer->len;
drv_data->rx = transfer->rx_buf;
drv_data->rx_end = drv_data->rx + transfer->len;
drv_data->len = transfer->len;
drv_data->write = drv_data->tx ? chip->write : null_writer;
drv_data->read = drv_data->rx ? chip->read : null_reader;
bits = transfer->bits_per_word;
speed = transfer->speed_hz;
clk_div = pxa2xx_ssp_get_clk_div(drv_data, speed);
if (bits <= 8) {
drv_data->n_bytes = 1;
drv_data->read = drv_data->read != null_reader ?
u8_reader : null_reader;
drv_data->write = drv_data->write != null_writer ?
u8_writer : null_writer;
} else if (bits <= 16) {
drv_data->n_bytes = 2;
drv_data->read = drv_data->read != null_reader ?
u16_reader : null_reader;
drv_data->write = drv_data->write != null_writer ?
u16_writer : null_writer;
} else if (bits <= 32) {
drv_data->n_bytes = 4;
drv_data->read = drv_data->read != null_reader ?
u32_reader : null_reader;
drv_data->write = drv_data->write != null_writer ?
u32_writer : null_writer;
}
if (chip->enable_dma) {
if (pxa2xx_spi_set_dma_burst_and_threshold(chip,
message->spi,
bits, &dma_burst,
&dma_thresh))
dev_warn_ratelimited(&message->spi->dev,
"pump_transfers: DMA burst size reduced to match bits_per_word\n");
}
message->state = RUNNING_STATE;
dma_mapped = master->can_dma &&
master->can_dma(master, message->spi, transfer) &&
master->cur_msg_mapped;
if (dma_mapped) {
drv_data->transfer_handler = pxa2xx_spi_dma_transfer;
err = pxa2xx_spi_dma_prepare(drv_data, dma_burst);
if (err) {
message->status = err;
giveback(drv_data);
return;
}
cr1 = chip->cr1 | dma_thresh | drv_data->dma_cr1;
pxa2xx_spi_write(drv_data, SSSR, drv_data->clear_sr);
pxa2xx_spi_dma_start(drv_data);
} else {
drv_data->transfer_handler = interrupt_transfer;
cr1 = chip->cr1 | chip->threshold | drv_data->int_cr1;
write_SSSR_CS(drv_data, drv_data->clear_sr);
}
cr0 = pxa2xx_configure_sscr0(drv_data, clk_div, bits);
if (!pxa25x_ssp_comp(drv_data))
dev_dbg(&message->spi->dev, "%u Hz actual, %s\n",
master->max_speed_hz
/ (1 + ((cr0 & SSCR0_SCR(0xfff)) >> 8)),
dma_mapped ? "DMA" : "PIO");
else
dev_dbg(&message->spi->dev, "%u Hz actual, %s\n",
master->max_speed_hz / 2
/ (1 + ((cr0 & SSCR0_SCR(0x0ff)) >> 8)),
dma_mapped ? "DMA" : "PIO");
if (is_lpss_ssp(drv_data)) {
if ((pxa2xx_spi_read(drv_data, SSIRF) & 0xff)
!= chip->lpss_rx_threshold)
pxa2xx_spi_write(drv_data, SSIRF,
chip->lpss_rx_threshold);
if ((pxa2xx_spi_read(drv_data, SSITF) & 0xffff)
!= chip->lpss_tx_threshold)
pxa2xx_spi_write(drv_data, SSITF,
chip->lpss_tx_threshold);
}
if (is_quark_x1000_ssp(drv_data) &&
(pxa2xx_spi_read(drv_data, DDS_RATE) != chip->dds_rate))
pxa2xx_spi_write(drv_data, DDS_RATE, chip->dds_rate);
if ((pxa2xx_spi_read(drv_data, SSCR0) != cr0)
|| (pxa2xx_spi_read(drv_data, SSCR1) & change_mask)
!= (cr1 & change_mask)) {
pxa2xx_spi_write(drv_data, SSCR0, cr0 & ~SSCR0_SSE);
if (!pxa25x_ssp_comp(drv_data))
pxa2xx_spi_write(drv_data, SSTO, chip->timeout);
pxa2xx_spi_write(drv_data, SSCR1, cr1 & change_mask);
pxa2xx_spi_write(drv_data, SSCR0, cr0);
} else {
if (!pxa25x_ssp_comp(drv_data))
pxa2xx_spi_write(drv_data, SSTO, chip->timeout);
}
cs_assert(drv_data);
pxa2xx_spi_write(drv_data, SSCR1, cr1);
}
static int pxa2xx_spi_transfer_one_message(struct spi_master *master,
struct spi_message *msg)
{
struct driver_data *drv_data = spi_master_get_devdata(master);
msg->state = START_STATE;
drv_data->cur_transfer = list_entry(msg->transfers.next,
struct spi_transfer,
transfer_list);
tasklet_schedule(&drv_data->pump_transfers);
return 0;
}
static int pxa2xx_spi_unprepare_transfer(struct spi_master *master)
{
struct driver_data *drv_data = spi_master_get_devdata(master);
pxa2xx_spi_write(drv_data, SSCR0,
pxa2xx_spi_read(drv_data, SSCR0) & ~SSCR0_SSE);
return 0;
}
static int setup_cs(struct spi_device *spi, struct chip_data *chip,
struct pxa2xx_spi_chip *chip_info)
{
struct driver_data *drv_data = spi_master_get_devdata(spi->master);
int err = 0;
if (chip == NULL)
return 0;
if (drv_data->cs_gpiods) {
struct gpio_desc *gpiod;
gpiod = drv_data->cs_gpiods[spi->chip_select];
if (gpiod) {
chip->gpio_cs = desc_to_gpio(gpiod);
chip->gpio_cs_inverted = spi->mode & SPI_CS_HIGH;
gpiod_set_value(gpiod, chip->gpio_cs_inverted);
}
return 0;
}
if (chip_info == NULL)
return 0;
if (gpio_is_valid(chip->gpio_cs))
gpio_free(chip->gpio_cs);
if (chip_info->cs_control) {
chip->cs_control = chip_info->cs_control;
return 0;
}
if (gpio_is_valid(chip_info->gpio_cs)) {
err = gpio_request(chip_info->gpio_cs, "SPI_CS");
if (err) {
dev_err(&spi->dev, "failed to request chip select GPIO%d\n",
chip_info->gpio_cs);
return err;
}
chip->gpio_cs = chip_info->gpio_cs;
chip->gpio_cs_inverted = spi->mode & SPI_CS_HIGH;
err = gpio_direction_output(chip->gpio_cs,
!chip->gpio_cs_inverted);
}
return err;
}
static int setup(struct spi_device *spi)
{
struct pxa2xx_spi_chip *chip_info;
struct chip_data *chip;
const struct lpss_config *config;
struct driver_data *drv_data = spi_master_get_devdata(spi->master);
uint tx_thres, tx_hi_thres, rx_thres;
switch (drv_data->ssp_type) {
case QUARK_X1000_SSP:
tx_thres = TX_THRESH_QUARK_X1000_DFLT;
tx_hi_thres = 0;
rx_thres = RX_THRESH_QUARK_X1000_DFLT;
break;
case CE4100_SSP:
tx_thres = TX_THRESH_CE4100_DFLT;
tx_hi_thres = 0;
rx_thres = RX_THRESH_CE4100_DFLT;
break;
case LPSS_LPT_SSP:
case LPSS_BYT_SSP:
case LPSS_BSW_SSP:
case LPSS_SPT_SSP:
case LPSS_BXT_SSP:
config = lpss_get_config(drv_data);
tx_thres = config->tx_threshold_lo;
tx_hi_thres = config->tx_threshold_hi;
rx_thres = config->rx_threshold;
break;
default:
tx_thres = TX_THRESH_DFLT;
tx_hi_thres = 0;
rx_thres = RX_THRESH_DFLT;
break;
}
chip = spi_get_ctldata(spi);
if (!chip) {
chip = kzalloc(sizeof(struct chip_data), GFP_KERNEL);
if (!chip)
return -ENOMEM;
if (drv_data->ssp_type == CE4100_SSP) {
if (spi->chip_select > 4) {
dev_err(&spi->dev,
"failed setup: cs number must not be > 4.\n");
kfree(chip);
return -EINVAL;
}
chip->frm = spi->chip_select;
} else
chip->gpio_cs = -1;
chip->enable_dma = drv_data->master_info->enable_dma;
chip->timeout = TIMOUT_DFLT;
}
chip_info = spi->controller_data;
chip->cr1 = 0;
if (chip_info) {
if (chip_info->timeout)
chip->timeout = chip_info->timeout;
if (chip_info->tx_threshold)
tx_thres = chip_info->tx_threshold;
if (chip_info->tx_hi_threshold)
tx_hi_thres = chip_info->tx_hi_threshold;
if (chip_info->rx_threshold)
rx_thres = chip_info->rx_threshold;
chip->dma_threshold = 0;
if (chip_info->enable_loopback)
chip->cr1 = SSCR1_LBM;
}
chip->lpss_rx_threshold = SSIRF_RxThresh(rx_thres);
chip->lpss_tx_threshold = SSITF_TxLoThresh(tx_thres)
| SSITF_TxHiThresh(tx_hi_thres);
if (chip->enable_dma) {
if (pxa2xx_spi_set_dma_burst_and_threshold(chip, spi,
spi->bits_per_word,
&chip->dma_burst_size,
&chip->dma_threshold)) {
dev_warn(&spi->dev,
"in setup: DMA burst size reduced to match bits_per_word\n");
}
}
switch (drv_data->ssp_type) {
case QUARK_X1000_SSP:
chip->threshold = (QUARK_X1000_SSCR1_RxTresh(rx_thres)
& QUARK_X1000_SSCR1_RFT)
| (QUARK_X1000_SSCR1_TxTresh(tx_thres)
& QUARK_X1000_SSCR1_TFT);
break;
case CE4100_SSP:
chip->threshold = (CE4100_SSCR1_RxTresh(rx_thres) & CE4100_SSCR1_RFT) |
(CE4100_SSCR1_TxTresh(tx_thres) & CE4100_SSCR1_TFT);
break;
default:
chip->threshold = (SSCR1_RxTresh(rx_thres) & SSCR1_RFT) |
(SSCR1_TxTresh(tx_thres) & SSCR1_TFT);
break;
}
chip->cr1 &= ~(SSCR1_SPO | SSCR1_SPH);
chip->cr1 |= (((spi->mode & SPI_CPHA) != 0) ? SSCR1_SPH : 0)
| (((spi->mode & SPI_CPOL) != 0) ? SSCR1_SPO : 0);
if (spi->mode & SPI_LOOP)
chip->cr1 |= SSCR1_LBM;
if (spi->bits_per_word <= 8) {
chip->n_bytes = 1;
chip->read = u8_reader;
chip->write = u8_writer;
} else if (spi->bits_per_word <= 16) {
chip->n_bytes = 2;
chip->read = u16_reader;
chip->write = u16_writer;
} else if (spi->bits_per_word <= 32) {
chip->n_bytes = 4;
chip->read = u32_reader;
chip->write = u32_writer;
}
spi_set_ctldata(spi, chip);
if (drv_data->ssp_type == CE4100_SSP)
return 0;
return setup_cs(spi, chip, chip_info);
}
static void cleanup(struct spi_device *spi)
{
struct chip_data *chip = spi_get_ctldata(spi);
struct driver_data *drv_data = spi_master_get_devdata(spi->master);
if (!chip)
return;
if (drv_data->ssp_type != CE4100_SSP && !drv_data->cs_gpiods &&
gpio_is_valid(chip->gpio_cs))
gpio_free(chip->gpio_cs);
kfree(chip);
}
static int pxa2xx_spi_get_port_id(struct acpi_device *adev)
{
unsigned int devid;
int port_id = -1;
if (adev && adev->pnp.unique_id &&
!kstrtouint(adev->pnp.unique_id, 0, &devid))
port_id = devid;
return port_id;
}
static int pxa2xx_spi_get_port_id(struct acpi_device *adev)
{
return -1;
}
static bool pxa2xx_spi_idma_filter(struct dma_chan *chan, void *param)
{
struct device *dev = param;
if (dev != chan->device->dev->parent)
return false;
return true;
}
static struct pxa2xx_spi_master *
pxa2xx_spi_init_pdata(struct platform_device *pdev)
{
struct pxa2xx_spi_master *pdata;
struct acpi_device *adev;
struct ssp_device *ssp;
struct resource *res;
const struct acpi_device_id *adev_id = NULL;
const struct pci_device_id *pcidev_id = NULL;
int type;
adev = ACPI_COMPANION(&pdev->dev);
if (dev_is_pci(pdev->dev.parent))
pcidev_id = pci_match_id(pxa2xx_spi_pci_compound_match,
to_pci_dev(pdev->dev.parent));
else if (adev)
adev_id = acpi_match_device(pdev->dev.driver->acpi_match_table,
&pdev->dev);
else
return NULL;
if (adev_id)
type = (int)adev_id->driver_data;
else if (pcidev_id)
type = (int)pcidev_id->driver_data;
else
return NULL;
pdata = devm_kzalloc(&pdev->dev, sizeof(*pdata), GFP_KERNEL);
if (!pdata)
return NULL;
res = platform_get_resource(pdev, IORESOURCE_MEM, 0);
if (!res)
return NULL;
ssp = &pdata->ssp;
ssp->phys_base = res->start;
ssp->mmio_base = devm_ioremap_resource(&pdev->dev, res);
if (IS_ERR(ssp->mmio_base))
return NULL;
if (pcidev_id) {
pdata->tx_param = pdev->dev.parent;
pdata->rx_param = pdev->dev.parent;
pdata->dma_filter = pxa2xx_spi_idma_filter;
}
ssp->clk = devm_clk_get(&pdev->dev, NULL);
ssp->irq = platform_get_irq(pdev, 0);
ssp->type = type;
ssp->pdev = pdev;
ssp->port_id = pxa2xx_spi_get_port_id(adev);
pdata->num_chipselect = 1;
pdata->enable_dma = true;
return pdata;
}
static inline struct pxa2xx_spi_master *
pxa2xx_spi_init_pdata(struct platform_device *pdev)
{
return NULL;
}
static int pxa2xx_spi_fw_translate_cs(struct spi_master *master, unsigned cs)
{
struct driver_data *drv_data = spi_master_get_devdata(master);
if (has_acpi_companion(&drv_data->pdev->dev)) {
switch (drv_data->ssp_type) {
case LPSS_BYT_SSP:
case LPSS_BSW_SSP:
return cs - 1;
default:
break;
}
}
return cs;
}
static int pxa2xx_spi_probe(struct platform_device *pdev)
{
struct device *dev = &pdev->dev;
struct pxa2xx_spi_master *platform_info;
struct spi_master *master;
struct driver_data *drv_data;
struct ssp_device *ssp;
const struct lpss_config *config;
int status, count;
u32 tmp;
platform_info = dev_get_platdata(dev);
if (!platform_info) {
platform_info = pxa2xx_spi_init_pdata(pdev);
if (!platform_info) {
dev_err(&pdev->dev, "missing platform data\n");
return -ENODEV;
}
}
ssp = pxa_ssp_request(pdev->id, pdev->name);
if (!ssp)
ssp = &platform_info->ssp;
if (!ssp->mmio_base) {
dev_err(&pdev->dev, "failed to get ssp\n");
return -ENODEV;
}
master = spi_alloc_master(dev, sizeof(struct driver_data));
if (!master) {
dev_err(&pdev->dev, "cannot alloc spi_master\n");
pxa_ssp_free(ssp);
return -ENOMEM;
}
drv_data = spi_master_get_devdata(master);
drv_data->master = master;
drv_data->master_info = platform_info;
drv_data->pdev = pdev;
drv_data->ssp = ssp;
master->dev.of_node = pdev->dev.of_node;
master->mode_bits = SPI_CPOL | SPI_CPHA | SPI_CS_HIGH | SPI_LOOP;
master->bus_num = ssp->port_id;
master->dma_alignment = DMA_ALIGNMENT;
master->cleanup = cleanup;
master->setup = setup;
master->transfer_one_message = pxa2xx_spi_transfer_one_message;
master->unprepare_transfer_hardware = pxa2xx_spi_unprepare_transfer;
master->fw_translate_cs = pxa2xx_spi_fw_translate_cs;
master->auto_runtime_pm = true;
master->flags = SPI_MASTER_MUST_RX | SPI_MASTER_MUST_TX;
drv_data->ssp_type = ssp->type;
drv_data->ioaddr = ssp->mmio_base;
drv_data->ssdr_physical = ssp->phys_base + SSDR;
if (pxa25x_ssp_comp(drv_data)) {
switch (drv_data->ssp_type) {
case QUARK_X1000_SSP:
master->bits_per_word_mask = SPI_BPW_RANGE_MASK(4, 32);
break;
default:
master->bits_per_word_mask = SPI_BPW_RANGE_MASK(4, 16);
break;
}
drv_data->int_cr1 = SSCR1_TIE | SSCR1_RIE;
drv_data->dma_cr1 = 0;
drv_data->clear_sr = SSSR_ROR;
drv_data->mask_sr = SSSR_RFS | SSSR_TFS | SSSR_ROR;
} else {
master->bits_per_word_mask = SPI_BPW_RANGE_MASK(4, 32);
drv_data->int_cr1 = SSCR1_TIE | SSCR1_RIE | SSCR1_TINTE;
drv_data->dma_cr1 = DEFAULT_DMA_CR1;
drv_data->clear_sr = SSSR_ROR | SSSR_TINT;
drv_data->mask_sr = SSSR_TINT | SSSR_RFS | SSSR_TFS | SSSR_ROR;
}
status = request_irq(ssp->irq, ssp_int, IRQF_SHARED, dev_name(dev),
drv_data);
if (status < 0) {
dev_err(&pdev->dev, "cannot get IRQ %d\n", ssp->irq);
goto out_error_master_alloc;
}
if (platform_info->enable_dma) {
status = pxa2xx_spi_dma_setup(drv_data);
if (status) {
dev_dbg(dev, "no DMA channels available, using PIO\n");
platform_info->enable_dma = false;
} else {
master->can_dma = pxa2xx_spi_can_dma;
}
}
clk_prepare_enable(ssp->clk);
master->max_speed_hz = clk_get_rate(ssp->clk);
pxa2xx_spi_write(drv_data, SSCR0, 0);
switch (drv_data->ssp_type) {
case QUARK_X1000_SSP:
tmp = QUARK_X1000_SSCR1_RxTresh(RX_THRESH_QUARK_X1000_DFLT) |
QUARK_X1000_SSCR1_TxTresh(TX_THRESH_QUARK_X1000_DFLT);
pxa2xx_spi_write(drv_data, SSCR1, tmp);
tmp = QUARK_X1000_SSCR0_Motorola | QUARK_X1000_SSCR0_DataSize(8);
pxa2xx_spi_write(drv_data, SSCR0, tmp);
break;
case CE4100_SSP:
tmp = CE4100_SSCR1_RxTresh(RX_THRESH_CE4100_DFLT) |
CE4100_SSCR1_TxTresh(TX_THRESH_CE4100_DFLT);
pxa2xx_spi_write(drv_data, SSCR1, tmp);
tmp = SSCR0_SCR(2) | SSCR0_Motorola | SSCR0_DataSize(8);
pxa2xx_spi_write(drv_data, SSCR0, tmp);
default:
tmp = SSCR1_RxTresh(RX_THRESH_DFLT) |
SSCR1_TxTresh(TX_THRESH_DFLT);
pxa2xx_spi_write(drv_data, SSCR1, tmp);
tmp = SSCR0_SCR(2) | SSCR0_Motorola | SSCR0_DataSize(8);
pxa2xx_spi_write(drv_data, SSCR0, tmp);
break;
}
if (!pxa25x_ssp_comp(drv_data))
pxa2xx_spi_write(drv_data, SSTO, 0);
if (!is_quark_x1000_ssp(drv_data))
pxa2xx_spi_write(drv_data, SSPSP, 0);
if (is_lpss_ssp(drv_data)) {
lpss_ssp_setup(drv_data);
config = lpss_get_config(drv_data);
if (config->reg_capabilities >= 0) {
tmp = __lpss_ssp_read_priv(drv_data,
config->reg_capabilities);
tmp &= LPSS_CAPS_CS_EN_MASK;
tmp >>= LPSS_CAPS_CS_EN_SHIFT;
platform_info->num_chipselect = ffz(tmp);
} else if (config->cs_num) {
platform_info->num_chipselect = config->cs_num;
}
}
master->num_chipselect = platform_info->num_chipselect;
count = gpiod_count(&pdev->dev, "cs");
if (count > 0) {
int i;
master->num_chipselect = max_t(int, count,
master->num_chipselect);
drv_data->cs_gpiods = devm_kcalloc(&pdev->dev,
master->num_chipselect, sizeof(struct gpio_desc *),
GFP_KERNEL);
if (!drv_data->cs_gpiods) {
status = -ENOMEM;
goto out_error_clock_enabled;
}
for (i = 0; i < master->num_chipselect; i++) {
struct gpio_desc *gpiod;
gpiod = devm_gpiod_get_index(dev, "cs", i,
GPIOD_OUT_HIGH);
if (IS_ERR(gpiod)) {
if (PTR_ERR(gpiod) == -ENOENT)
continue;
status = (int)PTR_ERR(gpiod);
goto out_error_clock_enabled;
} else {
drv_data->cs_gpiods[i] = gpiod;
}
}
}
tasklet_init(&drv_data->pump_transfers, pump_transfers,
(unsigned long)drv_data);
pm_runtime_set_autosuspend_delay(&pdev->dev, 50);
pm_runtime_use_autosuspend(&pdev->dev);
pm_runtime_set_active(&pdev->dev);
pm_runtime_enable(&pdev->dev);
platform_set_drvdata(pdev, drv_data);
status = devm_spi_register_master(&pdev->dev, master);
if (status != 0) {
dev_err(&pdev->dev, "problem registering spi master\n");
goto out_error_clock_enabled;
}
return status;
out_error_clock_enabled:
clk_disable_unprepare(ssp->clk);
pxa2xx_spi_dma_release(drv_data);
free_irq(ssp->irq, drv_data);
out_error_master_alloc:
spi_master_put(master);
pxa_ssp_free(ssp);
return status;
}
static int pxa2xx_spi_remove(struct platform_device *pdev)
{
struct driver_data *drv_data = platform_get_drvdata(pdev);
struct ssp_device *ssp;
if (!drv_data)
return 0;
ssp = drv_data->ssp;
pm_runtime_get_sync(&pdev->dev);
pxa2xx_spi_write(drv_data, SSCR0, 0);
clk_disable_unprepare(ssp->clk);
if (drv_data->master_info->enable_dma)
pxa2xx_spi_dma_release(drv_data);
pm_runtime_put_noidle(&pdev->dev);
pm_runtime_disable(&pdev->dev);
free_irq(ssp->irq, drv_data);
pxa_ssp_free(ssp);
return 0;
}
static void pxa2xx_spi_shutdown(struct platform_device *pdev)
{
int status = 0;
if ((status = pxa2xx_spi_remove(pdev)) != 0)
dev_err(&pdev->dev, "shutdown failed with %d\n", status);
}
static int pxa2xx_spi_suspend(struct device *dev)
{
struct driver_data *drv_data = dev_get_drvdata(dev);
struct ssp_device *ssp = drv_data->ssp;
int status;
status = spi_master_suspend(drv_data->master);
if (status != 0)
return status;
pxa2xx_spi_write(drv_data, SSCR0, 0);
if (!pm_runtime_suspended(dev))
clk_disable_unprepare(ssp->clk);
return 0;
}
static int pxa2xx_spi_resume(struct device *dev)
{
struct driver_data *drv_data = dev_get_drvdata(dev);
struct ssp_device *ssp = drv_data->ssp;
int status;
if (!pm_runtime_suspended(dev))
clk_prepare_enable(ssp->clk);
if (is_lpss_ssp(drv_data))
lpss_ssp_setup(drv_data);
status = spi_master_resume(drv_data->master);
if (status != 0) {
dev_err(dev, "problem starting queue (%d)\n", status);
return status;
}
return 0;
}
static int pxa2xx_spi_runtime_suspend(struct device *dev)
{
struct driver_data *drv_data = dev_get_drvdata(dev);
clk_disable_unprepare(drv_data->ssp->clk);
return 0;
}
static int pxa2xx_spi_runtime_resume(struct device *dev)
{
struct driver_data *drv_data = dev_get_drvdata(dev);
clk_prepare_enable(drv_data->ssp->clk);
return 0;
}
static int __init pxa2xx_spi_init(void)
{
return platform_driver_register(&driver);
}
static void __exit pxa2xx_spi_exit(void)
{
platform_driver_unregister(&driver);
}
