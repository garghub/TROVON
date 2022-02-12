static inline struct exynos_dsi *encoder_to_dsi(struct drm_encoder *e)
{
return container_of(e, struct exynos_dsi, encoder);
}
static inline void exynos_dsi_write(struct exynos_dsi *dsi, enum reg_idx idx,
u32 val)
{
writel(val, dsi->reg_base + dsi->driver_data->reg_ofs[idx]);
}
static inline u32 exynos_dsi_read(struct exynos_dsi *dsi, enum reg_idx idx)
{
return readl(dsi->reg_base + dsi->driver_data->reg_ofs[idx]);
}
static void exynos_dsi_wait_for_reset(struct exynos_dsi *dsi)
{
if (wait_for_completion_timeout(&dsi->completed, msecs_to_jiffies(300)))
return;
dev_err(dsi->dev, "timeout waiting for reset\n");
}
static void exynos_dsi_reset(struct exynos_dsi *dsi)
{
u32 reset_val = dsi->driver_data->reg_values[RESET_TYPE];
reinit_completion(&dsi->completed);
exynos_dsi_write(dsi, DSIM_SWRST_REG, reset_val);
}
static unsigned long exynos_dsi_pll_find_pms(struct exynos_dsi *dsi,
unsigned long fin, unsigned long fout, u8 *p, u16 *m, u8 *s)
{
const struct exynos_dsi_driver_data *driver_data = dsi->driver_data;
unsigned long best_freq = 0;
u32 min_delta = 0xffffffff;
u8 p_min, p_max;
u8 _p, uninitialized_var(best_p);
u16 _m, uninitialized_var(best_m);
u8 _s, uninitialized_var(best_s);
p_min = DIV_ROUND_UP(fin, (12 * MHZ));
p_max = fin / (6 * MHZ);
for (_p = p_min; _p <= p_max; ++_p) {
for (_s = 0; _s <= 5; ++_s) {
u64 tmp;
u32 delta;
tmp = (u64)fout * (_p << _s);
do_div(tmp, fin);
_m = tmp;
if (_m < 41 || _m > 125)
continue;
tmp = (u64)_m * fin;
do_div(tmp, _p);
if (tmp < 500 * MHZ ||
tmp > driver_data->max_freq * MHZ)
continue;
tmp = (u64)_m * fin;
do_div(tmp, _p << _s);
delta = abs(fout - tmp);
if (delta < min_delta) {
best_p = _p;
best_m = _m;
best_s = _s;
min_delta = delta;
best_freq = tmp;
}
}
}
if (best_freq) {
*p = best_p;
*m = best_m;
*s = best_s;
}
return best_freq;
}
static unsigned long exynos_dsi_set_pll(struct exynos_dsi *dsi,
unsigned long freq)
{
const struct exynos_dsi_driver_data *driver_data = dsi->driver_data;
unsigned long fin, fout;
int timeout;
u8 p, s;
u16 m;
u32 reg;
fin = dsi->pll_clk_rate;
fout = exynos_dsi_pll_find_pms(dsi, fin, freq, &p, &m, &s);
if (!fout) {
dev_err(dsi->dev,
"failed to find PLL PMS for requested frequency\n");
return 0;
}
dev_dbg(dsi->dev, "PLL freq %lu, (p %d, m %d, s %d)\n", fout, p, m, s);
writel(driver_data->reg_values[PLL_TIMER],
dsi->reg_base + driver_data->plltmr_reg);
reg = DSIM_PLL_EN | DSIM_PLL_P(p) | DSIM_PLL_M(m) | DSIM_PLL_S(s);
if (driver_data->has_freqband) {
static const unsigned long freq_bands[] = {
100 * MHZ, 120 * MHZ, 160 * MHZ, 200 * MHZ,
270 * MHZ, 320 * MHZ, 390 * MHZ, 450 * MHZ,
510 * MHZ, 560 * MHZ, 640 * MHZ, 690 * MHZ,
770 * MHZ, 870 * MHZ, 950 * MHZ,
};
int band;
for (band = 0; band < ARRAY_SIZE(freq_bands); ++band)
if (fout < freq_bands[band])
break;
dev_dbg(dsi->dev, "band %d\n", band);
reg |= DSIM_FREQ_BAND(band);
}
exynos_dsi_write(dsi, DSIM_PLLCTRL_REG, reg);
timeout = 1000;
do {
if (timeout-- == 0) {
dev_err(dsi->dev, "PLL failed to stabilize\n");
return 0;
}
reg = exynos_dsi_read(dsi, DSIM_STATUS_REG);
} while ((reg & DSIM_PLL_STABLE) == 0);
return fout;
}
static int exynos_dsi_enable_clock(struct exynos_dsi *dsi)
{
unsigned long hs_clk, byte_clk, esc_clk;
unsigned long esc_div;
u32 reg;
hs_clk = exynos_dsi_set_pll(dsi, dsi->burst_clk_rate);
if (!hs_clk) {
dev_err(dsi->dev, "failed to configure DSI PLL\n");
return -EFAULT;
}
byte_clk = hs_clk / 8;
esc_div = DIV_ROUND_UP(byte_clk, dsi->esc_clk_rate);
esc_clk = byte_clk / esc_div;
if (esc_clk > 20 * MHZ) {
++esc_div;
esc_clk = byte_clk / esc_div;
}
dev_dbg(dsi->dev, "hs_clk = %lu, byte_clk = %lu, esc_clk = %lu\n",
hs_clk, byte_clk, esc_clk);
reg = exynos_dsi_read(dsi, DSIM_CLKCTRL_REG);
reg &= ~(DSIM_ESC_PRESCALER_MASK | DSIM_LANE_ESC_CLK_EN_CLK
| DSIM_LANE_ESC_CLK_EN_DATA_MASK | DSIM_PLL_BYPASS
| DSIM_BYTE_CLK_SRC_MASK);
reg |= DSIM_ESC_CLKEN | DSIM_BYTE_CLKEN
| DSIM_ESC_PRESCALER(esc_div)
| DSIM_LANE_ESC_CLK_EN_CLK
| DSIM_LANE_ESC_CLK_EN_DATA(BIT(dsi->lanes) - 1)
| DSIM_BYTE_CLK_SRC(0)
| DSIM_TX_REQUEST_HSCLK;
exynos_dsi_write(dsi, DSIM_CLKCTRL_REG, reg);
return 0;
}
static void exynos_dsi_set_phy_ctrl(struct exynos_dsi *dsi)
{
const struct exynos_dsi_driver_data *driver_data = dsi->driver_data;
const unsigned int *reg_values = driver_data->reg_values;
u32 reg;
if (driver_data->has_freqband)
return;
reg = reg_values[PHYCTRL_ULPS_EXIT] | reg_values[PHYCTRL_VREG_LP] |
reg_values[PHYCTRL_SLEW_UP];
exynos_dsi_write(dsi, DSIM_PHYCTRL_REG, reg);
reg = reg_values[PHYTIMING_LPX] | reg_values[PHYTIMING_HS_EXIT];
exynos_dsi_write(dsi, DSIM_PHYTIMING_REG, reg);
reg = reg_values[PHYTIMING_CLK_PREPARE] |
reg_values[PHYTIMING_CLK_ZERO] |
reg_values[PHYTIMING_CLK_POST] |
reg_values[PHYTIMING_CLK_TRAIL];
exynos_dsi_write(dsi, DSIM_PHYTIMING1_REG, reg);
reg = reg_values[PHYTIMING_HS_PREPARE] | reg_values[PHYTIMING_HS_ZERO] |
reg_values[PHYTIMING_HS_TRAIL];
exynos_dsi_write(dsi, DSIM_PHYTIMING2_REG, reg);
}
static void exynos_dsi_disable_clock(struct exynos_dsi *dsi)
{
u32 reg;
reg = exynos_dsi_read(dsi, DSIM_CLKCTRL_REG);
reg &= ~(DSIM_LANE_ESC_CLK_EN_CLK | DSIM_LANE_ESC_CLK_EN_DATA_MASK
| DSIM_ESC_CLKEN | DSIM_BYTE_CLKEN);
exynos_dsi_write(dsi, DSIM_CLKCTRL_REG, reg);
reg = exynos_dsi_read(dsi, DSIM_PLLCTRL_REG);
reg &= ~DSIM_PLL_EN;
exynos_dsi_write(dsi, DSIM_PLLCTRL_REG, reg);
}
static void exynos_dsi_enable_lane(struct exynos_dsi *dsi, u32 lane)
{
u32 reg = exynos_dsi_read(dsi, DSIM_CONFIG_REG);
reg |= (DSIM_NUM_OF_DATA_LANE(dsi->lanes - 1) | DSIM_LANE_EN_CLK |
DSIM_LANE_EN(lane));
exynos_dsi_write(dsi, DSIM_CONFIG_REG, reg);
}
static int exynos_dsi_init_link(struct exynos_dsi *dsi)
{
const struct exynos_dsi_driver_data *driver_data = dsi->driver_data;
int timeout;
u32 reg;
u32 lanes_mask;
reg = exynos_dsi_read(dsi, DSIM_FIFOCTRL_REG);
reg &= ~0x1f;
exynos_dsi_write(dsi, DSIM_FIFOCTRL_REG, reg);
usleep_range(9000, 11000);
reg |= 0x1f;
exynos_dsi_write(dsi, DSIM_FIFOCTRL_REG, reg);
usleep_range(9000, 11000);
reg = 0;
if (dsi->mode_flags & MIPI_DSI_MODE_VIDEO) {
reg |= DSIM_VIDEO_MODE;
if (!(dsi->mode_flags & MIPI_DSI_MODE_VSYNC_FLUSH))
reg |= DSIM_MFLUSH_VS;
if (dsi->mode_flags & MIPI_DSI_MODE_VIDEO_SYNC_PULSE)
reg |= DSIM_SYNC_INFORM;
if (dsi->mode_flags & MIPI_DSI_MODE_VIDEO_BURST)
reg |= DSIM_BURST_MODE;
if (dsi->mode_flags & MIPI_DSI_MODE_VIDEO_AUTO_VERT)
reg |= DSIM_AUTO_MODE;
if (dsi->mode_flags & MIPI_DSI_MODE_VIDEO_HSE)
reg |= DSIM_HSE_MODE;
if (!(dsi->mode_flags & MIPI_DSI_MODE_VIDEO_HFP))
reg |= DSIM_HFP_MODE;
if (!(dsi->mode_flags & MIPI_DSI_MODE_VIDEO_HBP))
reg |= DSIM_HBP_MODE;
if (!(dsi->mode_flags & MIPI_DSI_MODE_VIDEO_HSA))
reg |= DSIM_HSA_MODE;
}
if (!(dsi->mode_flags & MIPI_DSI_MODE_EOT_PACKET))
reg |= DSIM_EOT_DISABLE;
switch (dsi->format) {
case MIPI_DSI_FMT_RGB888:
reg |= DSIM_MAIN_PIX_FORMAT_RGB888;
break;
case MIPI_DSI_FMT_RGB666:
reg |= DSIM_MAIN_PIX_FORMAT_RGB666;
break;
case MIPI_DSI_FMT_RGB666_PACKED:
reg |= DSIM_MAIN_PIX_FORMAT_RGB666_P;
break;
case MIPI_DSI_FMT_RGB565:
reg |= DSIM_MAIN_PIX_FORMAT_RGB565;
break;
default:
dev_err(dsi->dev, "invalid pixel format\n");
return -EINVAL;
}
if (driver_data->has_clklane_stop &&
dsi->mode_flags & MIPI_DSI_CLOCK_NON_CONTINUOUS) {
reg |= DSIM_CLKLANE_STOP;
}
exynos_dsi_write(dsi, DSIM_CONFIG_REG, reg);
lanes_mask = BIT(dsi->lanes) - 1;
exynos_dsi_enable_lane(dsi, lanes_mask);
timeout = 100;
do {
if (timeout-- == 0) {
dev_err(dsi->dev, "waiting for bus lanes timed out\n");
return -EFAULT;
}
reg = exynos_dsi_read(dsi, DSIM_STATUS_REG);
if ((reg & DSIM_STOP_STATE_DAT(lanes_mask))
!= DSIM_STOP_STATE_DAT(lanes_mask))
continue;
} while (!(reg & (DSIM_STOP_STATE_CLK | DSIM_TX_READY_HS_CLK)));
reg = exynos_dsi_read(dsi, DSIM_ESCMODE_REG);
reg &= ~DSIM_STOP_STATE_CNT_MASK;
reg |= DSIM_STOP_STATE_CNT(driver_data->reg_values[STOP_STATE_CNT]);
exynos_dsi_write(dsi, DSIM_ESCMODE_REG, reg);
reg = DSIM_BTA_TIMEOUT(0xff) | DSIM_LPDR_TIMEOUT(0xffff);
exynos_dsi_write(dsi, DSIM_TIMEOUT_REG, reg);
return 0;
}
static void exynos_dsi_set_display_mode(struct exynos_dsi *dsi)
{
struct videomode *vm = &dsi->vm;
unsigned int num_bits_resol = dsi->driver_data->num_bits_resol;
u32 reg;
if (dsi->mode_flags & MIPI_DSI_MODE_VIDEO) {
reg = DSIM_CMD_ALLOW(0xf)
| DSIM_STABLE_VFP(vm->vfront_porch)
| DSIM_MAIN_VBP(vm->vback_porch);
exynos_dsi_write(dsi, DSIM_MVPORCH_REG, reg);
reg = DSIM_MAIN_HFP(vm->hfront_porch)
| DSIM_MAIN_HBP(vm->hback_porch);
exynos_dsi_write(dsi, DSIM_MHPORCH_REG, reg);
reg = DSIM_MAIN_VSA(vm->vsync_len)
| DSIM_MAIN_HSA(vm->hsync_len);
exynos_dsi_write(dsi, DSIM_MSYNC_REG, reg);
}
reg = DSIM_MAIN_HRESOL(vm->hactive, num_bits_resol) |
DSIM_MAIN_VRESOL(vm->vactive, num_bits_resol);
exynos_dsi_write(dsi, DSIM_MDRESOL_REG, reg);
dev_dbg(dsi->dev, "LCD size = %dx%d\n", vm->hactive, vm->vactive);
}
static void exynos_dsi_set_display_enable(struct exynos_dsi *dsi, bool enable)
{
u32 reg;
reg = exynos_dsi_read(dsi, DSIM_MDRESOL_REG);
if (enable)
reg |= DSIM_MAIN_STAND_BY;
else
reg &= ~DSIM_MAIN_STAND_BY;
exynos_dsi_write(dsi, DSIM_MDRESOL_REG, reg);
}
static int exynos_dsi_wait_for_hdr_fifo(struct exynos_dsi *dsi)
{
int timeout = 2000;
do {
u32 reg = exynos_dsi_read(dsi, DSIM_FIFOCTRL_REG);
if (!(reg & DSIM_SFR_HEADER_FULL))
return 0;
if (!cond_resched())
usleep_range(950, 1050);
} while (--timeout);
return -ETIMEDOUT;
}
static void exynos_dsi_set_cmd_lpm(struct exynos_dsi *dsi, bool lpm)
{
u32 v = exynos_dsi_read(dsi, DSIM_ESCMODE_REG);
if (lpm)
v |= DSIM_CMD_LPDT_LP;
else
v &= ~DSIM_CMD_LPDT_LP;
exynos_dsi_write(dsi, DSIM_ESCMODE_REG, v);
}
static void exynos_dsi_force_bta(struct exynos_dsi *dsi)
{
u32 v = exynos_dsi_read(dsi, DSIM_ESCMODE_REG);
v |= DSIM_FORCE_BTA;
exynos_dsi_write(dsi, DSIM_ESCMODE_REG, v);
}
static void exynos_dsi_send_to_fifo(struct exynos_dsi *dsi,
struct exynos_dsi_transfer *xfer)
{
struct device *dev = dsi->dev;
struct mipi_dsi_packet *pkt = &xfer->packet;
const u8 *payload = pkt->payload + xfer->tx_done;
u16 length = pkt->payload_length - xfer->tx_done;
bool first = !xfer->tx_done;
u32 reg;
dev_dbg(dev, "< xfer %pK: tx len %u, done %u, rx len %u, done %u\n",
xfer, length, xfer->tx_done, xfer->rx_len, xfer->rx_done);
if (length > DSI_TX_FIFO_SIZE)
length = DSI_TX_FIFO_SIZE;
xfer->tx_done += length;
while (length >= 4) {
reg = get_unaligned_le32(payload);
exynos_dsi_write(dsi, DSIM_PAYLOAD_REG, reg);
payload += 4;
length -= 4;
}
reg = 0;
switch (length) {
case 3:
reg |= payload[2] << 16;
case 2:
reg |= payload[1] << 8;
case 1:
reg |= payload[0];
exynos_dsi_write(dsi, DSIM_PAYLOAD_REG, reg);
break;
}
if (!first)
return;
reg = get_unaligned_le32(pkt->header);
if (exynos_dsi_wait_for_hdr_fifo(dsi)) {
dev_err(dev, "waiting for header FIFO timed out\n");
return;
}
if (NEQV(xfer->flags & MIPI_DSI_MSG_USE_LPM,
dsi->state & DSIM_STATE_CMD_LPM)) {
exynos_dsi_set_cmd_lpm(dsi, xfer->flags & MIPI_DSI_MSG_USE_LPM);
dsi->state ^= DSIM_STATE_CMD_LPM;
}
exynos_dsi_write(dsi, DSIM_PKTHDR_REG, reg);
if (xfer->flags & MIPI_DSI_MSG_REQ_ACK)
exynos_dsi_force_bta(dsi);
}
static void exynos_dsi_read_from_fifo(struct exynos_dsi *dsi,
struct exynos_dsi_transfer *xfer)
{
u8 *payload = xfer->rx_payload + xfer->rx_done;
bool first = !xfer->rx_done;
struct device *dev = dsi->dev;
u16 length;
u32 reg;
if (first) {
reg = exynos_dsi_read(dsi, DSIM_RXFIFO_REG);
switch (reg & 0x3f) {
case MIPI_DSI_RX_GENERIC_SHORT_READ_RESPONSE_2BYTE:
case MIPI_DSI_RX_DCS_SHORT_READ_RESPONSE_2BYTE:
if (xfer->rx_len >= 2) {
payload[1] = reg >> 16;
++xfer->rx_done;
}
case MIPI_DSI_RX_GENERIC_SHORT_READ_RESPONSE_1BYTE:
case MIPI_DSI_RX_DCS_SHORT_READ_RESPONSE_1BYTE:
payload[0] = reg >> 8;
++xfer->rx_done;
xfer->rx_len = xfer->rx_done;
xfer->result = 0;
goto clear_fifo;
case MIPI_DSI_RX_ACKNOWLEDGE_AND_ERROR_REPORT:
dev_err(dev, "DSI Error Report: 0x%04x\n",
(reg >> 8) & 0xffff);
xfer->result = 0;
goto clear_fifo;
}
length = (reg >> 8) & 0xffff;
if (length > xfer->rx_len) {
dev_err(dev,
"response too long (%u > %u bytes), stripping\n",
xfer->rx_len, length);
length = xfer->rx_len;
} else if (length < xfer->rx_len)
xfer->rx_len = length;
}
length = xfer->rx_len - xfer->rx_done;
xfer->rx_done += length;
while (length >= 4) {
reg = exynos_dsi_read(dsi, DSIM_RXFIFO_REG);
payload[0] = (reg >> 0) & 0xff;
payload[1] = (reg >> 8) & 0xff;
payload[2] = (reg >> 16) & 0xff;
payload[3] = (reg >> 24) & 0xff;
payload += 4;
length -= 4;
}
if (length) {
reg = exynos_dsi_read(dsi, DSIM_RXFIFO_REG);
switch (length) {
case 3:
payload[2] = (reg >> 16) & 0xff;
case 2:
payload[1] = (reg >> 8) & 0xff;
case 1:
payload[0] = reg & 0xff;
}
}
if (xfer->rx_done == xfer->rx_len)
xfer->result = 0;
clear_fifo:
length = DSI_RX_FIFO_SIZE / 4;
do {
reg = exynos_dsi_read(dsi, DSIM_RXFIFO_REG);
if (reg == DSI_RX_FIFO_EMPTY)
break;
} while (--length);
}
static void exynos_dsi_transfer_start(struct exynos_dsi *dsi)
{
unsigned long flags;
struct exynos_dsi_transfer *xfer;
bool start = false;
again:
spin_lock_irqsave(&dsi->transfer_lock, flags);
if (list_empty(&dsi->transfer_list)) {
spin_unlock_irqrestore(&dsi->transfer_lock, flags);
return;
}
xfer = list_first_entry(&dsi->transfer_list,
struct exynos_dsi_transfer, list);
spin_unlock_irqrestore(&dsi->transfer_lock, flags);
if (xfer->packet.payload_length &&
xfer->tx_done == xfer->packet.payload_length)
return;
exynos_dsi_send_to_fifo(dsi, xfer);
if (xfer->packet.payload_length || xfer->rx_len)
return;
xfer->result = 0;
complete(&xfer->completed);
spin_lock_irqsave(&dsi->transfer_lock, flags);
list_del_init(&xfer->list);
start = !list_empty(&dsi->transfer_list);
spin_unlock_irqrestore(&dsi->transfer_lock, flags);
if (start)
goto again;
}
static bool exynos_dsi_transfer_finish(struct exynos_dsi *dsi)
{
struct exynos_dsi_transfer *xfer;
unsigned long flags;
bool start = true;
spin_lock_irqsave(&dsi->transfer_lock, flags);
if (list_empty(&dsi->transfer_list)) {
spin_unlock_irqrestore(&dsi->transfer_lock, flags);
return false;
}
xfer = list_first_entry(&dsi->transfer_list,
struct exynos_dsi_transfer, list);
spin_unlock_irqrestore(&dsi->transfer_lock, flags);
dev_dbg(dsi->dev,
"> xfer %pK, tx_len %zu, tx_done %u, rx_len %u, rx_done %u\n",
xfer, xfer->packet.payload_length, xfer->tx_done, xfer->rx_len,
xfer->rx_done);
if (xfer->tx_done != xfer->packet.payload_length)
return true;
if (xfer->rx_done != xfer->rx_len)
exynos_dsi_read_from_fifo(dsi, xfer);
if (xfer->rx_done != xfer->rx_len)
return true;
spin_lock_irqsave(&dsi->transfer_lock, flags);
list_del_init(&xfer->list);
start = !list_empty(&dsi->transfer_list);
spin_unlock_irqrestore(&dsi->transfer_lock, flags);
if (!xfer->rx_len)
xfer->result = 0;
complete(&xfer->completed);
return start;
}
static void exynos_dsi_remove_transfer(struct exynos_dsi *dsi,
struct exynos_dsi_transfer *xfer)
{
unsigned long flags;
bool start;
spin_lock_irqsave(&dsi->transfer_lock, flags);
if (!list_empty(&dsi->transfer_list) &&
xfer == list_first_entry(&dsi->transfer_list,
struct exynos_dsi_transfer, list)) {
list_del_init(&xfer->list);
start = !list_empty(&dsi->transfer_list);
spin_unlock_irqrestore(&dsi->transfer_lock, flags);
if (start)
exynos_dsi_transfer_start(dsi);
return;
}
list_del_init(&xfer->list);
spin_unlock_irqrestore(&dsi->transfer_lock, flags);
}
static int exynos_dsi_transfer(struct exynos_dsi *dsi,
struct exynos_dsi_transfer *xfer)
{
unsigned long flags;
bool stopped;
xfer->tx_done = 0;
xfer->rx_done = 0;
xfer->result = -ETIMEDOUT;
init_completion(&xfer->completed);
spin_lock_irqsave(&dsi->transfer_lock, flags);
stopped = list_empty(&dsi->transfer_list);
list_add_tail(&xfer->list, &dsi->transfer_list);
spin_unlock_irqrestore(&dsi->transfer_lock, flags);
if (stopped)
exynos_dsi_transfer_start(dsi);
wait_for_completion_timeout(&xfer->completed,
msecs_to_jiffies(DSI_XFER_TIMEOUT_MS));
if (xfer->result == -ETIMEDOUT) {
struct mipi_dsi_packet *pkt = &xfer->packet;
exynos_dsi_remove_transfer(dsi, xfer);
dev_err(dsi->dev, "xfer timed out: %*ph %*ph\n", 4, pkt->header,
(int)pkt->payload_length, pkt->payload);
return -ETIMEDOUT;
}
return xfer->result;
}
static irqreturn_t exynos_dsi_irq(int irq, void *dev_id)
{
struct exynos_dsi *dsi = dev_id;
u32 status;
status = exynos_dsi_read(dsi, DSIM_INTSRC_REG);
if (!status) {
static unsigned long int j;
if (printk_timed_ratelimit(&j, 500))
dev_warn(dsi->dev, "spurious interrupt\n");
return IRQ_HANDLED;
}
exynos_dsi_write(dsi, DSIM_INTSRC_REG, status);
if (status & DSIM_INT_SW_RST_RELEASE) {
u32 mask = ~(DSIM_INT_RX_DONE | DSIM_INT_SFR_FIFO_EMPTY |
DSIM_INT_SFR_HDR_FIFO_EMPTY | DSIM_INT_FRAME_DONE |
DSIM_INT_RX_ECC_ERR | DSIM_INT_SW_RST_RELEASE);
exynos_dsi_write(dsi, DSIM_INTMSK_REG, mask);
complete(&dsi->completed);
return IRQ_HANDLED;
}
if (!(status & (DSIM_INT_RX_DONE | DSIM_INT_SFR_FIFO_EMPTY |
DSIM_INT_FRAME_DONE | DSIM_INT_PLL_STABLE)))
return IRQ_HANDLED;
if (exynos_dsi_transfer_finish(dsi))
exynos_dsi_transfer_start(dsi);
return IRQ_HANDLED;
}
static irqreturn_t exynos_dsi_te_irq_handler(int irq, void *dev_id)
{
struct exynos_dsi *dsi = (struct exynos_dsi *)dev_id;
struct drm_encoder *encoder = &dsi->encoder;
if (dsi->state & DSIM_STATE_VIDOUT_AVAILABLE)
exynos_drm_crtc_te_handler(encoder->crtc);
return IRQ_HANDLED;
}
static void exynos_dsi_enable_irq(struct exynos_dsi *dsi)
{
enable_irq(dsi->irq);
if (gpio_is_valid(dsi->te_gpio))
enable_irq(gpio_to_irq(dsi->te_gpio));
}
static void exynos_dsi_disable_irq(struct exynos_dsi *dsi)
{
if (gpio_is_valid(dsi->te_gpio))
disable_irq(gpio_to_irq(dsi->te_gpio));
disable_irq(dsi->irq);
}
static int exynos_dsi_init(struct exynos_dsi *dsi)
{
const struct exynos_dsi_driver_data *driver_data = dsi->driver_data;
exynos_dsi_reset(dsi);
exynos_dsi_enable_irq(dsi);
if (driver_data->reg_values[RESET_TYPE] == DSIM_FUNCRST)
exynos_dsi_enable_lane(dsi, BIT(dsi->lanes) - 1);
exynos_dsi_enable_clock(dsi);
if (driver_data->wait_for_reset)
exynos_dsi_wait_for_reset(dsi);
exynos_dsi_set_phy_ctrl(dsi);
exynos_dsi_init_link(dsi);
return 0;
}
static int exynos_dsi_register_te_irq(struct exynos_dsi *dsi)
{
int ret;
int te_gpio_irq;
dsi->te_gpio = of_get_named_gpio(dsi->panel_node, "te-gpios", 0);
if (dsi->te_gpio == -ENOENT)
return 0;
if (!gpio_is_valid(dsi->te_gpio)) {
ret = dsi->te_gpio;
dev_err(dsi->dev, "cannot get te-gpios, %d\n", ret);
goto out;
}
ret = gpio_request(dsi->te_gpio, "te_gpio");
if (ret) {
dev_err(dsi->dev, "gpio request failed with %d\n", ret);
goto out;
}
te_gpio_irq = gpio_to_irq(dsi->te_gpio);
irq_set_status_flags(te_gpio_irq, IRQ_NOAUTOEN);
ret = request_threaded_irq(te_gpio_irq, exynos_dsi_te_irq_handler, NULL,
IRQF_TRIGGER_RISING, "TE", dsi);
if (ret) {
dev_err(dsi->dev, "request interrupt failed with %d\n", ret);
gpio_free(dsi->te_gpio);
goto out;
}
out:
return ret;
}
static void exynos_dsi_unregister_te_irq(struct exynos_dsi *dsi)
{
if (gpio_is_valid(dsi->te_gpio)) {
free_irq(gpio_to_irq(dsi->te_gpio), dsi);
gpio_free(dsi->te_gpio);
dsi->te_gpio = -ENOENT;
}
}
static int exynos_dsi_host_attach(struct mipi_dsi_host *host,
struct mipi_dsi_device *device)
{
struct exynos_dsi *dsi = host_to_dsi(host);
dsi->lanes = device->lanes;
dsi->format = device->format;
dsi->mode_flags = device->mode_flags;
dsi->panel_node = device->dev.of_node;
if (!(dsi->mode_flags & MIPI_DSI_MODE_VIDEO)) {
int ret = exynos_dsi_register_te_irq(dsi);
if (ret)
return ret;
}
if (dsi->connector.dev)
drm_helper_hpd_irq_event(dsi->connector.dev);
return 0;
}
static int exynos_dsi_host_detach(struct mipi_dsi_host *host,
struct mipi_dsi_device *device)
{
struct exynos_dsi *dsi = host_to_dsi(host);
exynos_dsi_unregister_te_irq(dsi);
dsi->panel_node = NULL;
if (dsi->connector.dev)
drm_helper_hpd_irq_event(dsi->connector.dev);
return 0;
}
static ssize_t exynos_dsi_host_transfer(struct mipi_dsi_host *host,
const struct mipi_dsi_msg *msg)
{
struct exynos_dsi *dsi = host_to_dsi(host);
struct exynos_dsi_transfer xfer;
int ret;
if (!(dsi->state & DSIM_STATE_ENABLED))
return -EINVAL;
if (!(dsi->state & DSIM_STATE_INITIALIZED)) {
ret = exynos_dsi_init(dsi);
if (ret)
return ret;
dsi->state |= DSIM_STATE_INITIALIZED;
}
ret = mipi_dsi_create_packet(&xfer.packet, msg);
if (ret < 0)
return ret;
xfer.rx_len = msg->rx_len;
xfer.rx_payload = msg->rx_buf;
xfer.flags = msg->flags;
ret = exynos_dsi_transfer(dsi, &xfer);
return (ret < 0) ? ret : xfer.rx_done;
}
static void exynos_dsi_enable(struct drm_encoder *encoder)
{
struct exynos_dsi *dsi = encoder_to_dsi(encoder);
int ret;
if (dsi->state & DSIM_STATE_ENABLED)
return;
pm_runtime_get_sync(dsi->dev);
dsi->state |= DSIM_STATE_ENABLED;
ret = drm_panel_prepare(dsi->panel);
if (ret < 0) {
dsi->state &= ~DSIM_STATE_ENABLED;
pm_runtime_put_sync(dsi->dev);
return;
}
exynos_dsi_set_display_mode(dsi);
exynos_dsi_set_display_enable(dsi, true);
ret = drm_panel_enable(dsi->panel);
if (ret < 0) {
dsi->state &= ~DSIM_STATE_ENABLED;
exynos_dsi_set_display_enable(dsi, false);
drm_panel_unprepare(dsi->panel);
pm_runtime_put_sync(dsi->dev);
return;
}
dsi->state |= DSIM_STATE_VIDOUT_AVAILABLE;
}
static void exynos_dsi_disable(struct drm_encoder *encoder)
{
struct exynos_dsi *dsi = encoder_to_dsi(encoder);
if (!(dsi->state & DSIM_STATE_ENABLED))
return;
dsi->state &= ~DSIM_STATE_VIDOUT_AVAILABLE;
drm_panel_disable(dsi->panel);
exynos_dsi_set_display_enable(dsi, false);
drm_panel_unprepare(dsi->panel);
dsi->state &= ~DSIM_STATE_ENABLED;
pm_runtime_put_sync(dsi->dev);
}
static enum drm_connector_status
exynos_dsi_detect(struct drm_connector *connector, bool force)
{
struct exynos_dsi *dsi = connector_to_dsi(connector);
if (!dsi->panel) {
dsi->panel = of_drm_find_panel(dsi->panel_node);
if (dsi->panel)
drm_panel_attach(dsi->panel, &dsi->connector);
} else if (!dsi->panel_node) {
struct drm_encoder *encoder;
encoder = platform_get_drvdata(to_platform_device(dsi->dev));
exynos_dsi_disable(encoder);
drm_panel_detach(dsi->panel);
dsi->panel = NULL;
}
if (dsi->panel)
return connector_status_connected;
return connector_status_disconnected;
}
static void exynos_dsi_connector_destroy(struct drm_connector *connector)
{
drm_connector_unregister(connector);
drm_connector_cleanup(connector);
connector->dev = NULL;
}
static int exynos_dsi_get_modes(struct drm_connector *connector)
{
struct exynos_dsi *dsi = connector_to_dsi(connector);
if (dsi->panel)
return dsi->panel->funcs->get_modes(dsi->panel);
return 0;
}
static int exynos_dsi_create_connector(struct drm_encoder *encoder)
{
struct exynos_dsi *dsi = encoder_to_dsi(encoder);
struct drm_connector *connector = &dsi->connector;
int ret;
connector->polled = DRM_CONNECTOR_POLL_HPD;
ret = drm_connector_init(encoder->dev, connector,
&exynos_dsi_connector_funcs,
DRM_MODE_CONNECTOR_DSI);
if (ret) {
DRM_ERROR("Failed to initialize connector with drm\n");
return ret;
}
drm_connector_helper_add(connector, &exynos_dsi_connector_helper_funcs);
drm_mode_connector_attach_encoder(connector, encoder);
return 0;
}
static void exynos_dsi_mode_set(struct drm_encoder *encoder,
struct drm_display_mode *mode,
struct drm_display_mode *adjusted_mode)
{
struct exynos_dsi *dsi = encoder_to_dsi(encoder);
struct videomode *vm = &dsi->vm;
struct drm_display_mode *m = adjusted_mode;
vm->hactive = m->hdisplay;
vm->vactive = m->vdisplay;
vm->vfront_porch = m->vsync_start - m->vdisplay;
vm->vback_porch = m->vtotal - m->vsync_end;
vm->vsync_len = m->vsync_end - m->vsync_start;
vm->hfront_porch = m->hsync_start - m->hdisplay;
vm->hback_porch = m->htotal - m->hsync_end;
vm->hsync_len = m->hsync_end - m->hsync_start;
}
static int exynos_dsi_of_read_u32(const struct device_node *np,
const char *propname, u32 *out_value)
{
int ret = of_property_read_u32(np, propname, out_value);
if (ret < 0)
pr_err("%s: failed to get '%s' property\n", np->full_name,
propname);
return ret;
}
static int exynos_dsi_parse_dt(struct exynos_dsi *dsi)
{
struct device *dev = dsi->dev;
struct device_node *node = dev->of_node;
int ret;
ret = exynos_dsi_of_read_u32(node, "samsung,pll-clock-frequency",
&dsi->pll_clk_rate);
if (ret < 0)
return ret;
ret = exynos_dsi_of_read_u32(node, "samsung,burst-clock-frequency",
&dsi->burst_clk_rate);
if (ret < 0)
return ret;
ret = exynos_dsi_of_read_u32(node, "samsung,esc-clock-frequency",
&dsi->esc_clk_rate);
if (ret < 0)
return ret;
dsi->bridge_node = of_graph_get_remote_node(node, DSI_PORT_OUT, 0);
if (!dsi->bridge_node)
return -EINVAL;
return 0;
}
static int exynos_dsi_bind(struct device *dev, struct device *master,
void *data)
{
struct drm_encoder *encoder = dev_get_drvdata(dev);
struct exynos_dsi *dsi = encoder_to_dsi(encoder);
struct drm_device *drm_dev = data;
struct drm_bridge *bridge;
int ret;
ret = exynos_drm_crtc_get_pipe_from_type(drm_dev,
EXYNOS_DISPLAY_TYPE_LCD);
if (ret < 0)
return ret;
encoder->possible_crtcs = 1 << ret;
DRM_DEBUG_KMS("possible_crtcs = 0x%x\n", encoder->possible_crtcs);
drm_encoder_init(drm_dev, encoder, &exynos_dsi_encoder_funcs,
DRM_MODE_ENCODER_TMDS, NULL);
drm_encoder_helper_add(encoder, &exynos_dsi_encoder_helper_funcs);
ret = exynos_dsi_create_connector(encoder);
if (ret) {
DRM_ERROR("failed to create connector ret = %d\n", ret);
drm_encoder_cleanup(encoder);
return ret;
}
bridge = of_drm_find_bridge(dsi->bridge_node);
if (bridge)
drm_bridge_attach(encoder, bridge, NULL);
return mipi_dsi_host_register(&dsi->dsi_host);
}
static void exynos_dsi_unbind(struct device *dev, struct device *master,
void *data)
{
struct drm_encoder *encoder = dev_get_drvdata(dev);
struct exynos_dsi *dsi = encoder_to_dsi(encoder);
exynos_dsi_disable(encoder);
mipi_dsi_host_unregister(&dsi->dsi_host);
}
static int exynos_dsi_probe(struct platform_device *pdev)
{
struct device *dev = &pdev->dev;
struct resource *res;
struct exynos_dsi *dsi;
int ret, i;
dsi = devm_kzalloc(dev, sizeof(*dsi), GFP_KERNEL);
if (!dsi)
return -ENOMEM;
dsi->te_gpio = -ENOENT;
init_completion(&dsi->completed);
spin_lock_init(&dsi->transfer_lock);
INIT_LIST_HEAD(&dsi->transfer_list);
dsi->dsi_host.ops = &exynos_dsi_ops;
dsi->dsi_host.dev = dev;
dsi->dev = dev;
dsi->driver_data = of_device_get_match_data(dev);
ret = exynos_dsi_parse_dt(dsi);
if (ret)
return ret;
dsi->supplies[0].supply = "vddcore";
dsi->supplies[1].supply = "vddio";
ret = devm_regulator_bulk_get(dev, ARRAY_SIZE(dsi->supplies),
dsi->supplies);
if (ret) {
dev_info(dev, "failed to get regulators: %d\n", ret);
return -EPROBE_DEFER;
}
dsi->clks = devm_kzalloc(dev,
sizeof(*dsi->clks) * dsi->driver_data->num_clks,
GFP_KERNEL);
if (!dsi->clks)
return -ENOMEM;
for (i = 0; i < dsi->driver_data->num_clks; i++) {
dsi->clks[i] = devm_clk_get(dev, clk_names[i]);
if (IS_ERR(dsi->clks[i])) {
if (strcmp(clk_names[i], "sclk_mipi") == 0) {
strcpy(clk_names[i], OLD_SCLK_MIPI_CLK_NAME);
i--;
continue;
}
dev_info(dev, "failed to get the clock: %s\n",
clk_names[i]);
return PTR_ERR(dsi->clks[i]);
}
}
res = platform_get_resource(pdev, IORESOURCE_MEM, 0);
dsi->reg_base = devm_ioremap_resource(dev, res);
if (IS_ERR(dsi->reg_base)) {
dev_err(dev, "failed to remap io region\n");
return PTR_ERR(dsi->reg_base);
}
dsi->phy = devm_phy_get(dev, "dsim");
if (IS_ERR(dsi->phy)) {
dev_info(dev, "failed to get dsim phy\n");
return PTR_ERR(dsi->phy);
}
dsi->irq = platform_get_irq(pdev, 0);
if (dsi->irq < 0) {
dev_err(dev, "failed to request dsi irq resource\n");
return dsi->irq;
}
irq_set_status_flags(dsi->irq, IRQ_NOAUTOEN);
ret = devm_request_threaded_irq(dev, dsi->irq, NULL,
exynos_dsi_irq, IRQF_ONESHOT,
dev_name(dev), dsi);
if (ret) {
dev_err(dev, "failed to request dsi irq\n");
return ret;
}
platform_set_drvdata(pdev, &dsi->encoder);
pm_runtime_enable(dev);
return component_add(dev, &exynos_dsi_component_ops);
}
static int exynos_dsi_remove(struct platform_device *pdev)
{
struct exynos_dsi *dsi = platform_get_drvdata(pdev);
of_node_put(dsi->bridge_node);
pm_runtime_disable(&pdev->dev);
component_del(&pdev->dev, &exynos_dsi_component_ops);
return 0;
}
static int __maybe_unused exynos_dsi_suspend(struct device *dev)
{
struct drm_encoder *encoder = dev_get_drvdata(dev);
struct exynos_dsi *dsi = encoder_to_dsi(encoder);
const struct exynos_dsi_driver_data *driver_data = dsi->driver_data;
int ret, i;
usleep_range(10000, 20000);
if (dsi->state & DSIM_STATE_INITIALIZED) {
dsi->state &= ~DSIM_STATE_INITIALIZED;
exynos_dsi_disable_clock(dsi);
exynos_dsi_disable_irq(dsi);
}
dsi->state &= ~DSIM_STATE_CMD_LPM;
phy_power_off(dsi->phy);
for (i = driver_data->num_clks - 1; i > -1; i--)
clk_disable_unprepare(dsi->clks[i]);
ret = regulator_bulk_disable(ARRAY_SIZE(dsi->supplies), dsi->supplies);
if (ret < 0)
dev_err(dsi->dev, "cannot disable regulators %d\n", ret);
return 0;
}
static int __maybe_unused exynos_dsi_resume(struct device *dev)
{
struct drm_encoder *encoder = dev_get_drvdata(dev);
struct exynos_dsi *dsi = encoder_to_dsi(encoder);
const struct exynos_dsi_driver_data *driver_data = dsi->driver_data;
int ret, i;
ret = regulator_bulk_enable(ARRAY_SIZE(dsi->supplies), dsi->supplies);
if (ret < 0) {
dev_err(dsi->dev, "cannot enable regulators %d\n", ret);
return ret;
}
for (i = 0; i < driver_data->num_clks; i++) {
ret = clk_prepare_enable(dsi->clks[i]);
if (ret < 0)
goto err_clk;
}
ret = phy_power_on(dsi->phy);
if (ret < 0) {
dev_err(dsi->dev, "cannot enable phy %d\n", ret);
goto err_clk;
}
return 0;
err_clk:
while (--i > -1)
clk_disable_unprepare(dsi->clks[i]);
regulator_bulk_disable(ARRAY_SIZE(dsi->supplies), dsi->supplies);
return ret;
}
