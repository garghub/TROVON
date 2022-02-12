static void exynos_dsi_wait_for_reset(struct exynos_dsi *dsi)
{
if (wait_for_completion_timeout(&dsi->completed, msecs_to_jiffies(300)))
return;
dev_err(dsi->dev, "timeout waiting for reset\n");
}
static void exynos_dsi_reset(struct exynos_dsi *dsi)
{
reinit_completion(&dsi->completed);
writel(DSIM_SWRST, dsi->reg_base + DSIM_SWRST_REG);
}
static unsigned long exynos_dsi_pll_find_pms(struct exynos_dsi *dsi,
unsigned long fin, unsigned long fout, u8 *p, u16 *m, u8 *s)
{
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
if (tmp < 500 * MHZ || tmp > 1000 * MHZ)
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
static const unsigned long freq_bands[] = {
100 * MHZ, 120 * MHZ, 160 * MHZ, 200 * MHZ,
270 * MHZ, 320 * MHZ, 390 * MHZ, 450 * MHZ,
510 * MHZ, 560 * MHZ, 640 * MHZ, 690 * MHZ,
770 * MHZ, 870 * MHZ, 950 * MHZ,
};
unsigned long fin, fout;
int timeout, band;
u8 p, s;
u16 m;
u32 reg;
clk_set_rate(dsi->pll_clk, dsi->pll_clk_rate);
fin = clk_get_rate(dsi->pll_clk);
if (!fin) {
dev_err(dsi->dev, "failed to get PLL clock frequency\n");
return 0;
}
dev_dbg(dsi->dev, "PLL input frequency: %lu\n", fin);
fout = exynos_dsi_pll_find_pms(dsi, fin, freq, &p, &m, &s);
if (!fout) {
dev_err(dsi->dev,
"failed to find PLL PMS for requested frequency\n");
return -EFAULT;
}
for (band = 0; band < ARRAY_SIZE(freq_bands); ++band)
if (fout < freq_bands[band])
break;
dev_dbg(dsi->dev, "PLL freq %lu, (p %d, m %d, s %d), band %d\n", fout,
p, m, s, band);
writel(500, dsi->reg_base + DSIM_PLLTMR_REG);
reg = DSIM_FREQ_BAND(band) | DSIM_PLL_EN
| DSIM_PLL_P(p) | DSIM_PLL_M(m) | DSIM_PLL_S(s);
writel(reg, dsi->reg_base + DSIM_PLLCTRL_REG);
timeout = 1000;
do {
if (timeout-- == 0) {
dev_err(dsi->dev, "PLL failed to stabilize\n");
return -EFAULT;
}
reg = readl(dsi->reg_base + DSIM_STATUS_REG);
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
reg = readl(dsi->reg_base + DSIM_CLKCTRL_REG);
reg &= ~(DSIM_ESC_PRESCALER_MASK | DSIM_LANE_ESC_CLK_EN_CLK
| DSIM_LANE_ESC_CLK_EN_DATA_MASK | DSIM_PLL_BYPASS
| DSIM_BYTE_CLK_SRC_MASK);
reg |= DSIM_ESC_CLKEN | DSIM_BYTE_CLKEN
| DSIM_ESC_PRESCALER(esc_div)
| DSIM_LANE_ESC_CLK_EN_CLK
| DSIM_LANE_ESC_CLK_EN_DATA(BIT(dsi->lanes) - 1)
| DSIM_BYTE_CLK_SRC(0)
| DSIM_TX_REQUEST_HSCLK;
writel(reg, dsi->reg_base + DSIM_CLKCTRL_REG);
return 0;
}
static void exynos_dsi_disable_clock(struct exynos_dsi *dsi)
{
u32 reg;
reg = readl(dsi->reg_base + DSIM_CLKCTRL_REG);
reg &= ~(DSIM_LANE_ESC_CLK_EN_CLK | DSIM_LANE_ESC_CLK_EN_DATA_MASK
| DSIM_ESC_CLKEN | DSIM_BYTE_CLKEN);
writel(reg, dsi->reg_base + DSIM_CLKCTRL_REG);
reg = readl(dsi->reg_base + DSIM_PLLCTRL_REG);
reg &= ~DSIM_PLL_EN;
writel(reg, dsi->reg_base + DSIM_PLLCTRL_REG);
}
static int exynos_dsi_init_link(struct exynos_dsi *dsi)
{
int timeout;
u32 reg;
u32 lanes_mask;
reg = readl(dsi->reg_base + DSIM_FIFOCTRL_REG);
reg &= ~0x1f;
writel(reg, dsi->reg_base + DSIM_FIFOCTRL_REG);
usleep_range(9000, 11000);
reg |= 0x1f;
writel(reg, dsi->reg_base + DSIM_FIFOCTRL_REG);
usleep_range(9000, 11000);
reg = 0;
if (dsi->mode_flags & MIPI_DSI_MODE_VIDEO) {
reg |= DSIM_VIDEO_MODE;
if (!(dsi->mode_flags & MIPI_DSI_MODE_VSYNC_FLUSH))
reg |= DSIM_MFLUSH_VS;
if (!(dsi->mode_flags & MIPI_DSI_MODE_EOT_PACKET))
reg |= DSIM_EOT_DISABLE;
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
reg |= DSIM_NUM_OF_DATA_LANE(dsi->lanes - 1);
writel(reg, dsi->reg_base + DSIM_CONFIG_REG);
reg |= DSIM_LANE_EN_CLK;
writel(reg, dsi->reg_base + DSIM_CONFIG_REG);
lanes_mask = BIT(dsi->lanes) - 1;
reg |= DSIM_LANE_EN(lanes_mask);
writel(reg, dsi->reg_base + DSIM_CONFIG_REG);
timeout = 100;
do {
if (timeout-- == 0) {
dev_err(dsi->dev, "waiting for bus lanes timed out\n");
return -EFAULT;
}
reg = readl(dsi->reg_base + DSIM_STATUS_REG);
if ((reg & DSIM_STOP_STATE_DAT(lanes_mask))
!= DSIM_STOP_STATE_DAT(lanes_mask))
continue;
} while (!(reg & (DSIM_STOP_STATE_CLK | DSIM_TX_READY_HS_CLK)));
reg = readl(dsi->reg_base + DSIM_ESCMODE_REG);
reg &= ~DSIM_STOP_STATE_CNT_MASK;
reg |= DSIM_STOP_STATE_CNT(0xf);
writel(reg, dsi->reg_base + DSIM_ESCMODE_REG);
reg = DSIM_BTA_TIMEOUT(0xff) | DSIM_LPDR_TIMEOUT(0xffff);
writel(reg, dsi->reg_base + DSIM_TIMEOUT_REG);
return 0;
}
static void exynos_dsi_set_display_mode(struct exynos_dsi *dsi)
{
struct videomode *vm = &dsi->vm;
u32 reg;
if (dsi->mode_flags & MIPI_DSI_MODE_VIDEO) {
reg = DSIM_CMD_ALLOW(0xf)
| DSIM_STABLE_VFP(vm->vfront_porch)
| DSIM_MAIN_VBP(vm->vback_porch);
writel(reg, dsi->reg_base + DSIM_MVPORCH_REG);
reg = DSIM_MAIN_HFP(vm->hfront_porch)
| DSIM_MAIN_HBP(vm->hback_porch);
writel(reg, dsi->reg_base + DSIM_MHPORCH_REG);
reg = DSIM_MAIN_VSA(vm->vsync_len)
| DSIM_MAIN_HSA(vm->hsync_len);
writel(reg, dsi->reg_base + DSIM_MSYNC_REG);
}
reg = DSIM_MAIN_HRESOL(vm->hactive) | DSIM_MAIN_VRESOL(vm->vactive);
writel(reg, dsi->reg_base + DSIM_MDRESOL_REG);
dev_dbg(dsi->dev, "LCD size = %dx%d\n", vm->hactive, vm->vactive);
}
static void exynos_dsi_set_display_enable(struct exynos_dsi *dsi, bool enable)
{
u32 reg;
reg = readl(dsi->reg_base + DSIM_MDRESOL_REG);
if (enable)
reg |= DSIM_MAIN_STAND_BY;
else
reg &= ~DSIM_MAIN_STAND_BY;
writel(reg, dsi->reg_base + DSIM_MDRESOL_REG);
}
static int exynos_dsi_wait_for_hdr_fifo(struct exynos_dsi *dsi)
{
int timeout = 2000;
do {
u32 reg = readl(dsi->reg_base + DSIM_FIFOCTRL_REG);
if (!(reg & DSIM_SFR_HEADER_FULL))
return 0;
if (!cond_resched())
usleep_range(950, 1050);
} while (--timeout);
return -ETIMEDOUT;
}
static void exynos_dsi_set_cmd_lpm(struct exynos_dsi *dsi, bool lpm)
{
u32 v = readl(dsi->reg_base + DSIM_ESCMODE_REG);
if (lpm)
v |= DSIM_CMD_LPDT_LP;
else
v &= ~DSIM_CMD_LPDT_LP;
writel(v, dsi->reg_base + DSIM_ESCMODE_REG);
}
static void exynos_dsi_force_bta(struct exynos_dsi *dsi)
{
u32 v = readl(dsi->reg_base + DSIM_ESCMODE_REG);
v |= DSIM_FORCE_BTA;
writel(v, dsi->reg_base + DSIM_ESCMODE_REG);
}
static void exynos_dsi_send_to_fifo(struct exynos_dsi *dsi,
struct exynos_dsi_transfer *xfer)
{
struct device *dev = dsi->dev;
const u8 *payload = xfer->tx_payload + xfer->tx_done;
u16 length = xfer->tx_len - xfer->tx_done;
bool first = !xfer->tx_done;
u32 reg;
dev_dbg(dev, "< xfer %p: tx len %u, done %u, rx len %u, done %u\n",
xfer, xfer->tx_len, xfer->tx_done, xfer->rx_len, xfer->rx_done);
if (length > DSI_TX_FIFO_SIZE)
length = DSI_TX_FIFO_SIZE;
xfer->tx_done += length;
while (length >= 4) {
reg = (payload[3] << 24) | (payload[2] << 16)
| (payload[1] << 8) | payload[0];
writel(reg, dsi->reg_base + DSIM_PAYLOAD_REG);
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
writel(reg, dsi->reg_base + DSIM_PAYLOAD_REG);
break;
case 0:
break;
}
if (!first)
return;
reg = (xfer->data[1] << 16) | (xfer->data[0] << 8) | xfer->data_id;
if (exynos_dsi_wait_for_hdr_fifo(dsi)) {
dev_err(dev, "waiting for header FIFO timed out\n");
return;
}
if (NEQV(xfer->flags & MIPI_DSI_MSG_USE_LPM,
dsi->state & DSIM_STATE_CMD_LPM)) {
exynos_dsi_set_cmd_lpm(dsi, xfer->flags & MIPI_DSI_MSG_USE_LPM);
dsi->state ^= DSIM_STATE_CMD_LPM;
}
writel(reg, dsi->reg_base + DSIM_PKTHDR_REG);
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
reg = readl(dsi->reg_base + DSIM_RXFIFO_REG);
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
reg = readl(dsi->reg_base + DSIM_RXFIFO_REG);
payload[0] = (reg >> 0) & 0xff;
payload[1] = (reg >> 8) & 0xff;
payload[2] = (reg >> 16) & 0xff;
payload[3] = (reg >> 24) & 0xff;
payload += 4;
length -= 4;
}
if (length) {
reg = readl(dsi->reg_base + DSIM_RXFIFO_REG);
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
reg = readl(dsi->reg_base + DSIM_RXFIFO_REG);
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
if (xfer->tx_len && xfer->tx_done == xfer->tx_len)
return;
exynos_dsi_send_to_fifo(dsi, xfer);
if (xfer->tx_len || xfer->rx_len)
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
"> xfer %p, tx_len %u, tx_done %u, rx_len %u, rx_done %u\n",
xfer, xfer->tx_len, xfer->tx_done, xfer->rx_len, xfer->rx_done);
if (xfer->tx_done != xfer->tx_len)
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
exynos_dsi_remove_transfer(dsi, xfer);
dev_err(dsi->dev, "xfer timed out: %*ph %*ph\n", 2, xfer->data,
xfer->tx_len, xfer->tx_payload);
return -ETIMEDOUT;
}
return xfer->result;
}
static irqreturn_t exynos_dsi_irq(int irq, void *dev_id)
{
struct exynos_dsi *dsi = dev_id;
u32 status;
status = readl(dsi->reg_base + DSIM_INTSRC_REG);
if (!status) {
static unsigned long int j;
if (printk_timed_ratelimit(&j, 500))
dev_warn(dsi->dev, "spurious interrupt\n");
return IRQ_HANDLED;
}
writel(status, dsi->reg_base + DSIM_INTSRC_REG);
if (status & DSIM_INT_SW_RST_RELEASE) {
u32 mask = ~(DSIM_INT_RX_DONE | DSIM_INT_SFR_FIFO_EMPTY);
writel(mask, dsi->reg_base + DSIM_INTMSK_REG);
complete(&dsi->completed);
return IRQ_HANDLED;
}
if (!(status & (DSIM_INT_RX_DONE | DSIM_INT_SFR_FIFO_EMPTY)))
return IRQ_HANDLED;
if (exynos_dsi_transfer_finish(dsi))
exynos_dsi_transfer_start(dsi);
return IRQ_HANDLED;
}
static int exynos_dsi_init(struct exynos_dsi *dsi)
{
exynos_dsi_enable_clock(dsi);
exynos_dsi_reset(dsi);
enable_irq(dsi->irq);
exynos_dsi_wait_for_reset(dsi);
exynos_dsi_init_link(dsi);
return 0;
}
static int exynos_dsi_host_attach(struct mipi_dsi_host *host,
struct mipi_dsi_device *device)
{
struct exynos_dsi *dsi = host_to_dsi(host);
dsi->lanes = device->lanes;
dsi->format = device->format;
dsi->mode_flags = device->mode_flags;
dsi->panel_node = device->dev.of_node;
if (dsi->connector.dev)
drm_helper_hpd_irq_event(dsi->connector.dev);
return 0;
}
static int exynos_dsi_host_detach(struct mipi_dsi_host *host,
struct mipi_dsi_device *device)
{
struct exynos_dsi *dsi = host_to_dsi(host);
dsi->panel_node = NULL;
if (dsi->connector.dev)
drm_helper_hpd_irq_event(dsi->connector.dev);
return 0;
}
static bool exynos_dsi_is_short_dsi_type(u8 type)
{
return (type & 0x0f) <= 8;
}
static ssize_t exynos_dsi_host_transfer(struct mipi_dsi_host *host,
struct mipi_dsi_msg *msg)
{
struct exynos_dsi *dsi = host_to_dsi(host);
struct exynos_dsi_transfer xfer;
int ret;
if (!(dsi->state & DSIM_STATE_INITIALIZED)) {
ret = exynos_dsi_init(dsi);
if (ret)
return ret;
dsi->state |= DSIM_STATE_INITIALIZED;
}
if (msg->tx_len == 0)
return -EINVAL;
xfer.data_id = msg->type | (msg->channel << 6);
if (exynos_dsi_is_short_dsi_type(msg->type)) {
const char *tx_buf = msg->tx_buf;
if (msg->tx_len > 2)
return -EINVAL;
xfer.tx_len = 0;
xfer.data[0] = tx_buf[0];
xfer.data[1] = (msg->tx_len == 2) ? tx_buf[1] : 0;
} else {
xfer.tx_len = msg->tx_len;
xfer.data[0] = msg->tx_len & 0xff;
xfer.data[1] = msg->tx_len >> 8;
xfer.tx_payload = msg->tx_buf;
}
xfer.rx_len = msg->rx_len;
xfer.rx_payload = msg->rx_buf;
xfer.flags = msg->flags;
ret = exynos_dsi_transfer(dsi, &xfer);
return (ret < 0) ? ret : xfer.rx_done;
}
static int exynos_dsi_poweron(struct exynos_dsi *dsi)
{
int ret;
ret = regulator_bulk_enable(ARRAY_SIZE(dsi->supplies), dsi->supplies);
if (ret < 0) {
dev_err(dsi->dev, "cannot enable regulators %d\n", ret);
return ret;
}
ret = clk_prepare_enable(dsi->bus_clk);
if (ret < 0) {
dev_err(dsi->dev, "cannot enable bus clock %d\n", ret);
goto err_bus_clk;
}
ret = clk_prepare_enable(dsi->pll_clk);
if (ret < 0) {
dev_err(dsi->dev, "cannot enable pll clock %d\n", ret);
goto err_pll_clk;
}
ret = phy_power_on(dsi->phy);
if (ret < 0) {
dev_err(dsi->dev, "cannot enable phy %d\n", ret);
goto err_phy;
}
return 0;
err_phy:
clk_disable_unprepare(dsi->pll_clk);
err_pll_clk:
clk_disable_unprepare(dsi->bus_clk);
err_bus_clk:
regulator_bulk_disable(ARRAY_SIZE(dsi->supplies), dsi->supplies);
return ret;
}
static void exynos_dsi_poweroff(struct exynos_dsi *dsi)
{
int ret;
usleep_range(10000, 20000);
if (dsi->state & DSIM_STATE_INITIALIZED) {
dsi->state &= ~DSIM_STATE_INITIALIZED;
exynos_dsi_disable_clock(dsi);
disable_irq(dsi->irq);
}
dsi->state &= ~DSIM_STATE_CMD_LPM;
phy_power_off(dsi->phy);
clk_disable_unprepare(dsi->pll_clk);
clk_disable_unprepare(dsi->bus_clk);
ret = regulator_bulk_disable(ARRAY_SIZE(dsi->supplies), dsi->supplies);
if (ret < 0)
dev_err(dsi->dev, "cannot disable regulators %d\n", ret);
}
static int exynos_dsi_enable(struct exynos_dsi *dsi)
{
int ret;
if (dsi->state & DSIM_STATE_ENABLED)
return 0;
ret = exynos_dsi_poweron(dsi);
if (ret < 0)
return ret;
ret = drm_panel_enable(dsi->panel);
if (ret < 0) {
exynos_dsi_poweroff(dsi);
return ret;
}
exynos_dsi_set_display_mode(dsi);
exynos_dsi_set_display_enable(dsi, true);
dsi->state |= DSIM_STATE_ENABLED;
return 0;
}
static void exynos_dsi_disable(struct exynos_dsi *dsi)
{
if (!(dsi->state & DSIM_STATE_ENABLED))
return;
exynos_dsi_set_display_enable(dsi, false);
drm_panel_disable(dsi->panel);
exynos_dsi_poweroff(dsi);
dsi->state &= ~DSIM_STATE_ENABLED;
}
static void exynos_dsi_dpms(struct exynos_drm_display *display, int mode)
{
struct exynos_dsi *dsi = display->ctx;
if (dsi->panel) {
switch (mode) {
case DRM_MODE_DPMS_ON:
exynos_dsi_enable(dsi);
break;
case DRM_MODE_DPMS_STANDBY:
case DRM_MODE_DPMS_SUSPEND:
case DRM_MODE_DPMS_OFF:
exynos_dsi_disable(dsi);
break;
default:
break;
}
}
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
struct exynos_drm_display *display;
display = platform_get_drvdata(to_platform_device(dsi->dev));
exynos_dsi_dpms(display, DRM_MODE_DPMS_OFF);
drm_panel_detach(dsi->panel);
dsi->panel = NULL;
}
if (dsi->panel)
return connector_status_connected;
return connector_status_disconnected;
}
static void exynos_dsi_connector_destroy(struct drm_connector *connector)
{
}
static int exynos_dsi_get_modes(struct drm_connector *connector)
{
struct exynos_dsi *dsi = connector_to_dsi(connector);
if (dsi->panel)
return dsi->panel->funcs->get_modes(dsi->panel);
return 0;
}
static int exynos_dsi_mode_valid(struct drm_connector *connector,
struct drm_display_mode *mode)
{
return MODE_OK;
}
static struct drm_encoder *
exynos_dsi_best_encoder(struct drm_connector *connector)
{
struct exynos_dsi *dsi = connector_to_dsi(connector);
return dsi->encoder;
}
static int exynos_dsi_create_connector(struct exynos_drm_display *display,
struct drm_encoder *encoder)
{
struct exynos_dsi *dsi = display->ctx;
struct drm_connector *connector = &dsi->connector;
int ret;
dsi->encoder = encoder;
connector->polled = DRM_CONNECTOR_POLL_HPD;
ret = drm_connector_init(encoder->dev, connector,
&exynos_dsi_connector_funcs,
DRM_MODE_CONNECTOR_DSI);
if (ret) {
DRM_ERROR("Failed to initialize connector with drm\n");
return ret;
}
drm_connector_helper_add(connector, &exynos_dsi_connector_helper_funcs);
drm_sysfs_connector_add(connector);
drm_mode_connector_attach_encoder(connector, encoder);
return 0;
}
static void exynos_dsi_mode_set(struct exynos_drm_display *display,
struct drm_display_mode *mode)
{
struct exynos_dsi *dsi = display->ctx;
struct videomode *vm = &dsi->vm;
vm->hactive = mode->hdisplay;
vm->vactive = mode->vdisplay;
vm->vfront_porch = mode->vsync_start - mode->vdisplay;
vm->vback_porch = mode->vtotal - mode->vsync_end;
vm->vsync_len = mode->vsync_end - mode->vsync_start;
vm->hfront_porch = mode->hsync_start - mode->hdisplay;
vm->hback_porch = mode->htotal - mode->hsync_end;
vm->hsync_len = mode->hsync_end - mode->hsync_start;
}
static struct device_node *
of_get_child_by_name_reg(struct device_node *parent, const char *name, u32 reg)
{
struct device_node *np;
for_each_child_of_node(parent, np) {
u32 r;
if (!np->name || of_node_cmp(np->name, name))
continue;
if (of_property_read_u32(np, "reg", &r) < 0)
r = 0;
if (reg == r)
break;
}
return np;
}
static struct device_node *of_graph_get_port_by_reg(struct device_node *parent,
u32 reg)
{
struct device_node *ports, *port;
ports = of_get_child_by_name(parent, "ports");
if (ports)
parent = ports;
port = of_get_child_by_name_reg(parent, "port", reg);
of_node_put(ports);
return port;
}
static struct device_node *
of_graph_get_endpoint_by_reg(struct device_node *port, u32 reg)
{
return of_get_child_by_name_reg(port, "endpoint", reg);
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
struct device_node *port, *ep;
int ret;
ret = exynos_dsi_of_read_u32(node, "samsung,pll-clock-frequency",
&dsi->pll_clk_rate);
if (ret < 0)
return ret;
port = of_graph_get_port_by_reg(node, DSI_PORT_OUT);
if (!port) {
dev_err(dev, "no output port specified\n");
return -EINVAL;
}
ep = of_graph_get_endpoint_by_reg(port, 0);
of_node_put(port);
if (!ep) {
dev_err(dev, "no endpoint specified in output port\n");
return -EINVAL;
}
ret = exynos_dsi_of_read_u32(ep, "samsung,burst-clock-frequency",
&dsi->burst_clk_rate);
if (ret < 0)
goto end;
ret = exynos_dsi_of_read_u32(ep, "samsung,esc-clock-frequency",
&dsi->esc_clk_rate);
end:
of_node_put(ep);
return ret;
}
static int exynos_dsi_bind(struct device *dev, struct device *master,
void *data)
{
struct drm_device *drm_dev = data;
struct exynos_dsi *dsi;
int ret;
ret = exynos_drm_create_enc_conn(drm_dev, &exynos_dsi_display);
if (ret) {
DRM_ERROR("Encoder create [%d] failed with %d\n",
exynos_dsi_display.type, ret);
return ret;
}
dsi = exynos_dsi_display.ctx;
return mipi_dsi_host_register(&dsi->dsi_host);
}
static void exynos_dsi_unbind(struct device *dev, struct device *master,
void *data)
{
struct exynos_dsi *dsi = exynos_dsi_display.ctx;
struct drm_encoder *encoder = dsi->encoder;
exynos_dsi_dpms(&exynos_dsi_display, DRM_MODE_DPMS_OFF);
mipi_dsi_host_unregister(&dsi->dsi_host);
encoder->funcs->destroy(encoder);
drm_connector_cleanup(&dsi->connector);
}
static int exynos_dsi_probe(struct platform_device *pdev)
{
struct resource *res;
struct exynos_dsi *dsi;
int ret;
ret = exynos_drm_component_add(&pdev->dev, EXYNOS_DEVICE_TYPE_CONNECTOR,
exynos_dsi_display.type);
if (ret)
return ret;
dsi = devm_kzalloc(&pdev->dev, sizeof(*dsi), GFP_KERNEL);
if (!dsi) {
dev_err(&pdev->dev, "failed to allocate dsi object.\n");
ret = -ENOMEM;
goto err_del_component;
}
init_completion(&dsi->completed);
spin_lock_init(&dsi->transfer_lock);
INIT_LIST_HEAD(&dsi->transfer_list);
dsi->dsi_host.ops = &exynos_dsi_ops;
dsi->dsi_host.dev = &pdev->dev;
dsi->dev = &pdev->dev;
ret = exynos_dsi_parse_dt(dsi);
if (ret)
goto err_del_component;
dsi->supplies[0].supply = "vddcore";
dsi->supplies[1].supply = "vddio";
ret = devm_regulator_bulk_get(&pdev->dev, ARRAY_SIZE(dsi->supplies),
dsi->supplies);
if (ret) {
dev_info(&pdev->dev, "failed to get regulators: %d\n", ret);
return -EPROBE_DEFER;
}
dsi->pll_clk = devm_clk_get(&pdev->dev, "pll_clk");
if (IS_ERR(dsi->pll_clk)) {
dev_info(&pdev->dev, "failed to get dsi pll input clock\n");
ret = PTR_ERR(dsi->pll_clk);
goto err_del_component;
}
dsi->bus_clk = devm_clk_get(&pdev->dev, "bus_clk");
if (IS_ERR(dsi->bus_clk)) {
dev_info(&pdev->dev, "failed to get dsi bus clock\n");
ret = PTR_ERR(dsi->bus_clk);
goto err_del_component;
}
res = platform_get_resource(pdev, IORESOURCE_MEM, 0);
dsi->reg_base = devm_ioremap_resource(&pdev->dev, res);
if (IS_ERR(dsi->reg_base)) {
dev_err(&pdev->dev, "failed to remap io region\n");
ret = PTR_ERR(dsi->reg_base);
goto err_del_component;
}
dsi->phy = devm_phy_get(&pdev->dev, "dsim");
if (IS_ERR(dsi->phy)) {
dev_info(&pdev->dev, "failed to get dsim phy\n");
ret = PTR_ERR(dsi->phy);
goto err_del_component;
}
dsi->irq = platform_get_irq(pdev, 0);
if (dsi->irq < 0) {
dev_err(&pdev->dev, "failed to request dsi irq resource\n");
ret = dsi->irq;
goto err_del_component;
}
irq_set_status_flags(dsi->irq, IRQ_NOAUTOEN);
ret = devm_request_threaded_irq(&pdev->dev, dsi->irq, NULL,
exynos_dsi_irq, IRQF_ONESHOT,
dev_name(&pdev->dev), dsi);
if (ret) {
dev_err(&pdev->dev, "failed to request dsi irq\n");
goto err_del_component;
}
exynos_dsi_display.ctx = dsi;
platform_set_drvdata(pdev, &exynos_dsi_display);
ret = component_add(&pdev->dev, &exynos_dsi_component_ops);
if (ret)
goto err_del_component;
return ret;
err_del_component:
exynos_drm_component_del(&pdev->dev, EXYNOS_DEVICE_TYPE_CONNECTOR);
return ret;
}
static int exynos_dsi_remove(struct platform_device *pdev)
{
component_del(&pdev->dev, &exynos_dsi_component_ops);
exynos_drm_component_del(&pdev->dev, EXYNOS_DEVICE_TYPE_CONNECTOR);
return 0;
}
