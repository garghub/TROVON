irqreturn_t exynos_mipi_dsi_interrupt_handler(int irq, void *dev_id)
{
struct mipi_dsim_device *dsim = dev_id;
unsigned int intsrc, intmsk;
if (dsim == NULL) {
dev_err(dsim->dev, "%s: wrong parameter\n", __func__);
return IRQ_NONE;
}
intsrc = exynos_mipi_dsi_read_interrupt(dsim);
intmsk = exynos_mipi_dsi_read_interrupt_mask(dsim);
intmsk = ~intmsk & intsrc;
if (intsrc & INTMSK_RX_DONE) {
complete(&dsim_rd_comp);
dev_dbg(dsim->dev, "MIPI INTMSK_RX_DONE\n");
}
if (intsrc & INTMSK_FIFO_EMPTY) {
complete(&dsim_wr_comp);
dev_dbg(dsim->dev, "MIPI INTMSK_FIFO_EMPTY\n");
}
exynos_mipi_dsi_clear_interrupt(dsim, intmsk);
return IRQ_HANDLED;
}
static void exynos_mipi_dsi_long_data_wr(struct mipi_dsim_device *dsim,
const unsigned char *data0, unsigned int data_size)
{
unsigned int data_cnt = 0, payload = 0;
for (data_cnt = 0; data_cnt < data_size; data_cnt += 4) {
if ((data_size - data_cnt) < 4) {
if ((data_size - data_cnt) == 3) {
payload = data0[data_cnt] |
data0[data_cnt + 1] << 8 |
data0[data_cnt + 2] << 16;
dev_dbg(dsim->dev, "count = 3 payload = %x, %x %x %x\n",
payload, data0[data_cnt],
data0[data_cnt + 1],
data0[data_cnt + 2]);
} else if ((data_size - data_cnt) == 2) {
payload = data0[data_cnt] |
data0[data_cnt + 1] << 8;
dev_dbg(dsim->dev,
"count = 2 payload = %x, %x %x\n", payload,
data0[data_cnt],
data0[data_cnt + 1]);
} else if ((data_size - data_cnt) == 1) {
payload = data0[data_cnt];
}
exynos_mipi_dsi_wr_tx_data(dsim, payload);
} else {
payload = data0[data_cnt] |
data0[data_cnt + 1] << 8 |
data0[data_cnt + 2] << 16 |
data0[data_cnt + 3] << 24;
dev_dbg(dsim->dev,
"count = 4 payload = %x, %x %x %x %x\n",
payload, *(u8 *)(data0 + data_cnt),
data0[data_cnt + 1],
data0[data_cnt + 2],
data0[data_cnt + 3]);
exynos_mipi_dsi_wr_tx_data(dsim, payload);
}
}
}
int exynos_mipi_dsi_wr_data(struct mipi_dsim_device *dsim, unsigned int data_id,
const unsigned char *data0, unsigned int data_size)
{
unsigned int check_rx_ack = 0;
if (dsim->state == DSIM_STATE_ULPS) {
dev_err(dsim->dev, "state is ULPS.\n");
return -EINVAL;
}
msleep(20);
mutex_lock(&dsim->lock);
switch (data_id) {
case MIPI_DSI_GENERIC_SHORT_WRITE_0_PARAM:
case MIPI_DSI_GENERIC_SHORT_WRITE_1_PARAM:
case MIPI_DSI_GENERIC_SHORT_WRITE_2_PARAM:
case MIPI_DSI_DCS_SHORT_WRITE:
case MIPI_DSI_DCS_SHORT_WRITE_PARAM:
case MIPI_DSI_SET_MAXIMUM_RETURN_PACKET_SIZE:
exynos_mipi_dsi_wr_tx_header(dsim, data_id, data0[0], data0[1]);
if (check_rx_ack) {
mutex_unlock(&dsim->lock);
return 0;
} else {
mutex_unlock(&dsim->lock);
return -EINVAL;
}
case MIPI_DSI_COLOR_MODE_OFF:
case MIPI_DSI_COLOR_MODE_ON:
case MIPI_DSI_SHUTDOWN_PERIPHERAL:
case MIPI_DSI_TURN_ON_PERIPHERAL:
exynos_mipi_dsi_wr_tx_header(dsim, data_id, data0[0], data0[1]);
if (check_rx_ack) {
mutex_unlock(&dsim->lock);
return 0;
} else {
mutex_unlock(&dsim->lock);
return -EINVAL;
}
case MIPI_DSI_V_SYNC_START:
case MIPI_DSI_V_SYNC_END:
case MIPI_DSI_H_SYNC_START:
case MIPI_DSI_H_SYNC_END:
case MIPI_DSI_END_OF_TRANSMISSION:
mutex_unlock(&dsim->lock);
return 0;
case MIPI_DSI_NULL_PACKET:
case MIPI_DSI_BLANKING_PACKET:
mutex_unlock(&dsim->lock);
return 0;
case MIPI_DSI_GENERIC_LONG_WRITE:
case MIPI_DSI_DCS_LONG_WRITE:
{
unsigned int size, payload = 0;
INIT_COMPLETION(dsim_wr_comp);
size = data_size * 4;
if (data_size < 4) {
payload = data0[0] |
data0[1] << 8 |
data0[2] << 16;
exynos_mipi_dsi_wr_tx_data(dsim, payload);
dev_dbg(dsim->dev, "count = %d payload = %x,%x %x %x\n",
data_size, payload, data0[0],
data0[1], data0[2]);
} else
exynos_mipi_dsi_long_data_wr(dsim, data0, data_size);
exynos_mipi_dsi_wr_tx_header(dsim, data_id, data_size & 0xff,
(data_size & 0xff00) >> 8);
if (!wait_for_completion_interruptible_timeout(&dsim_wr_comp,
MIPI_FIFO_TIMEOUT)) {
dev_warn(dsim->dev, "command write timeout.\n");
mutex_unlock(&dsim->lock);
return -EAGAIN;
}
if (check_rx_ack) {
mutex_unlock(&dsim->lock);
return 0;
} else {
mutex_unlock(&dsim->lock);
return -EINVAL;
}
}
case MIPI_DSI_PACKED_PIXEL_STREAM_16:
case MIPI_DSI_PACKED_PIXEL_STREAM_18:
case MIPI_DSI_PIXEL_STREAM_3BYTE_18:
case MIPI_DSI_PACKED_PIXEL_STREAM_24:
if (check_rx_ack) {
mutex_unlock(&dsim->lock);
return 0;
} else {
mutex_unlock(&dsim->lock);
return -EINVAL;
}
default:
dev_warn(dsim->dev,
"data id %x is not supported current DSI spec.\n",
data_id);
mutex_unlock(&dsim->lock);
return -EINVAL;
}
mutex_unlock(&dsim->lock);
return 0;
}
static unsigned int exynos_mipi_dsi_long_data_rd(struct mipi_dsim_device *dsim,
unsigned int req_size, unsigned int rx_data, u8 *rx_buf)
{
unsigned int rcv_pkt, i, j;
u16 rxsize;
rxsize = (u16)((rx_data & 0x00ffff00) >> 8);
dev_dbg(dsim->dev, "mipi dsi rx size : %d\n", rxsize);
if (rxsize != req_size) {
dev_dbg(dsim->dev,
"received size mismatch received: %d, requested: %d\n",
rxsize, req_size);
goto err;
}
for (i = 0; i < (rxsize >> 2); i++) {
rcv_pkt = exynos_mipi_dsi_rd_rx_fifo(dsim);
dev_dbg(dsim->dev, "received pkt : %08x\n", rcv_pkt);
for (j = 0; j < 4; j++) {
rx_buf[(i * 4) + j] =
(u8)(rcv_pkt >> (j * 8)) & 0xff;
dev_dbg(dsim->dev, "received value : %02x\n",
(rcv_pkt >> (j * 8)) & 0xff);
}
}
if (rxsize % 4) {
rcv_pkt = exynos_mipi_dsi_rd_rx_fifo(dsim);
dev_dbg(dsim->dev, "received pkt : %08x\n", rcv_pkt);
for (j = 0; j < (rxsize % 4); j++) {
rx_buf[(i * 4) + j] =
(u8)(rcv_pkt >> (j * 8)) & 0xff;
dev_dbg(dsim->dev, "received value : %02x\n",
(rcv_pkt >> (j * 8)) & 0xff);
}
}
return rxsize;
err:
return -EINVAL;
}
static unsigned int exynos_mipi_dsi_response_size(unsigned int req_size)
{
switch (req_size) {
case 1:
return MIPI_DSI_RX_GENERIC_SHORT_READ_RESPONSE_1BYTE;
case 2:
return MIPI_DSI_RX_GENERIC_SHORT_READ_RESPONSE_2BYTE;
default:
return MIPI_DSI_RX_GENERIC_LONG_READ_RESPONSE;
}
}
int exynos_mipi_dsi_rd_data(struct mipi_dsim_device *dsim, unsigned int data_id,
unsigned int data0, unsigned int req_size, u8 *rx_buf)
{
unsigned int rx_data, rcv_pkt, i;
u8 response = 0;
u16 rxsize;
if (dsim->state == DSIM_STATE_ULPS) {
dev_err(dsim->dev, "state is ULPS.\n");
return -EINVAL;
}
msleep(20);
mutex_lock(&dsim->lock);
INIT_COMPLETION(dsim_rd_comp);
exynos_mipi_dsi_rd_tx_header(dsim,
MIPI_DSI_SET_MAXIMUM_RETURN_PACKET_SIZE, req_size);
response = exynos_mipi_dsi_response_size(req_size);
switch (data_id) {
case MIPI_DSI_GENERIC_READ_REQUEST_0_PARAM:
case MIPI_DSI_GENERIC_READ_REQUEST_1_PARAM:
case MIPI_DSI_GENERIC_READ_REQUEST_2_PARAM:
case MIPI_DSI_DCS_READ:
exynos_mipi_dsi_rd_tx_header(dsim,
data_id, data0);
break;
default:
dev_warn(dsim->dev,
"data id %x is not supported current DSI spec.\n",
data_id);
return -EINVAL;
}
if (!wait_for_completion_interruptible_timeout(&dsim_rd_comp,
MIPI_FIFO_TIMEOUT)) {
pr_err("RX done interrupt timeout\n");
mutex_unlock(&dsim->lock);
return 0;
}
msleep(20);
rx_data = exynos_mipi_dsi_rd_rx_fifo(dsim);
if ((u8)(rx_data & 0xff) != response) {
printk(KERN_ERR
"mipi dsi wrong response rx_data : %x, response:%x\n",
rx_data, response);
goto clear_rx_fifo;
}
if (req_size <= 2) {
for (i = 0; i < req_size; i++)
rx_buf[i] = (rx_data >> (8 + (i * 8))) & 0xff;
rxsize = req_size;
} else {
rxsize = exynos_mipi_dsi_long_data_rd(dsim, req_size, rx_data,
rx_buf);
if (rxsize != req_size)
goto clear_rx_fifo;
}
rcv_pkt = exynos_mipi_dsi_rd_rx_fifo(dsim);
msleep(20);
if (rcv_pkt != MIPI_RX_FIFO_READ_DONE) {
dev_info(dsim->dev,
"Can't found RX FIFO READ DONE FLAG : %x\n", rcv_pkt);
goto clear_rx_fifo;
}
mutex_unlock(&dsim->lock);
return rxsize;
clear_rx_fifo:
i = 0;
while (1) {
rcv_pkt = exynos_mipi_dsi_rd_rx_fifo(dsim);
if ((rcv_pkt == MIPI_RX_FIFO_READ_DONE)
|| (i > MIPI_MAX_RX_FIFO))
break;
dev_dbg(dsim->dev,
"mipi dsi clear rx fifo : %08x\n", rcv_pkt);
i++;
}
dev_info(dsim->dev,
"mipi dsi rx done count : %d, rcv_pkt : %08x\n", i, rcv_pkt);
mutex_unlock(&dsim->lock);
return 0;
}
static int exynos_mipi_dsi_pll_on(struct mipi_dsim_device *dsim,
unsigned int enable)
{
int sw_timeout;
if (enable) {
sw_timeout = 1000;
exynos_mipi_dsi_enable_pll(dsim, 1);
while (1) {
sw_timeout--;
if (exynos_mipi_dsi_is_pll_stable(dsim))
return 0;
if (sw_timeout == 0)
return -EINVAL;
}
} else
exynos_mipi_dsi_enable_pll(dsim, 0);
return 0;
}
static unsigned long exynos_mipi_dsi_change_pll(struct mipi_dsim_device *dsim,
unsigned int pre_divider, unsigned int main_divider,
unsigned int scaler)
{
unsigned long dfin_pll, dfvco, dpll_out;
unsigned int i, freq_band = 0xf;
dfin_pll = (FIN_HZ / pre_divider);
if (dfin_pll < DFIN_PLL_MIN_HZ || dfin_pll > DFIN_PLL_MAX_HZ) {
dev_warn(dsim->dev, "fin_pll range should be 6MHz ~ 12MHz\n");
exynos_mipi_dsi_enable_afc(dsim, 0, 0);
} else {
if (dfin_pll < 7 * MHZ)
exynos_mipi_dsi_enable_afc(dsim, 1, 0x1);
else if (dfin_pll < 8 * MHZ)
exynos_mipi_dsi_enable_afc(dsim, 1, 0x0);
else if (dfin_pll < 9 * MHZ)
exynos_mipi_dsi_enable_afc(dsim, 1, 0x3);
else if (dfin_pll < 10 * MHZ)
exynos_mipi_dsi_enable_afc(dsim, 1, 0x2);
else if (dfin_pll < 11 * MHZ)
exynos_mipi_dsi_enable_afc(dsim, 1, 0x5);
else
exynos_mipi_dsi_enable_afc(dsim, 1, 0x4);
}
dfvco = dfin_pll * main_divider;
dev_dbg(dsim->dev, "dfvco = %lu, dfin_pll = %lu, main_divider = %d\n",
dfvco, dfin_pll, main_divider);
if (dfvco < DFVCO_MIN_HZ || dfvco > DFVCO_MAX_HZ)
dev_warn(dsim->dev, "fvco range should be 500MHz ~ 1000MHz\n");
dpll_out = dfvco / (1 << scaler);
dev_dbg(dsim->dev, "dpll_out = %lu, dfvco = %lu, scaler = %d\n",
dpll_out, dfvco, scaler);
for (i = 0; i < ARRAY_SIZE(dpll_table); i++) {
if (dpll_out < dpll_table[i] * MHZ) {
freq_band = i;
break;
}
}
dev_dbg(dsim->dev, "freq_band = %d\n", freq_band);
exynos_mipi_dsi_pll_freq(dsim, pre_divider, main_divider, scaler);
exynos_mipi_dsi_hs_zero_ctrl(dsim, 0);
exynos_mipi_dsi_prep_ctrl(dsim, 0);
exynos_mipi_dsi_pll_freq_band(dsim, freq_band);
exynos_mipi_dsi_pll_stable_time(dsim, dsim->dsim_config->pll_stable_time);
dev_dbg(dsim->dev, "FOUT of mipi dphy pll is %luMHz\n",
(dpll_out / MHZ));
return dpll_out;
}
static int exynos_mipi_dsi_set_clock(struct mipi_dsim_device *dsim,
unsigned int byte_clk_sel, unsigned int enable)
{
unsigned int esc_div;
unsigned long esc_clk_error_rate;
unsigned long hs_clk = 0, byte_clk = 0, escape_clk = 0;
if (enable) {
dsim->e_clk_src = byte_clk_sel;
exynos_mipi_dsi_set_byte_clock_src(dsim, byte_clk_sel);
if (byte_clk_sel == DSIM_PLL_OUT_DIV8) {
hs_clk = exynos_mipi_dsi_change_pll(dsim,
dsim->dsim_config->p, dsim->dsim_config->m,
dsim->dsim_config->s);
if (hs_clk == 0) {
dev_err(dsim->dev,
"failed to get hs clock.\n");
return -EINVAL;
}
byte_clk = hs_clk / 8;
exynos_mipi_dsi_enable_pll_bypass(dsim, 0);
exynos_mipi_dsi_pll_on(dsim, 1);
} else if (byte_clk_sel == DSIM_EXT_CLK_DIV8) {
dev_warn(dsim->dev, "this project is not support\n");
dev_warn(dsim->dev,
"external clock source for MIPI DSIM.\n");
} else if (byte_clk_sel == DSIM_EXT_CLK_BYPASS) {
dev_warn(dsim->dev, "this project is not support\n");
dev_warn(dsim->dev,
"external clock source for MIPI DSIM\n");
}
esc_div = byte_clk / (dsim->dsim_config->esc_clk);
dev_dbg(dsim->dev,
"esc_div = %d, byte_clk = %lu, esc_clk = %lu\n",
esc_div, byte_clk, dsim->dsim_config->esc_clk);
if ((byte_clk / esc_div) >= (20 * MHZ) ||
(byte_clk / esc_div) >
dsim->dsim_config->esc_clk)
esc_div += 1;
escape_clk = byte_clk / esc_div;
dev_dbg(dsim->dev,
"escape_clk = %lu, byte_clk = %lu, esc_div = %d\n",
escape_clk, byte_clk, esc_div);
exynos_mipi_dsi_enable_byte_clock(dsim, 1);
exynos_mipi_dsi_set_esc_clk_prs(dsim, 1, esc_div);
exynos_mipi_dsi_enable_esc_clk_on_lane(dsim,
(DSIM_LANE_CLOCK | dsim->data_lane), 1);
dev_dbg(dsim->dev, "byte clock is %luMHz\n",
(byte_clk / MHZ));
dev_dbg(dsim->dev, "escape clock that user's need is %lu\n",
(dsim->dsim_config->esc_clk / MHZ));
dev_dbg(dsim->dev, "escape clock divider is %x\n", esc_div);
dev_dbg(dsim->dev, "escape clock is %luMHz\n",
((byte_clk / esc_div) / MHZ));
if ((byte_clk / esc_div) > escape_clk) {
esc_clk_error_rate = escape_clk /
(byte_clk / esc_div);
dev_warn(dsim->dev, "error rate is %lu over.\n",
(esc_clk_error_rate / 100));
} else if ((byte_clk / esc_div) < (escape_clk)) {
esc_clk_error_rate = (byte_clk / esc_div) /
escape_clk;
dev_warn(dsim->dev, "error rate is %lu under.\n",
(esc_clk_error_rate / 100));
}
} else {
exynos_mipi_dsi_enable_esc_clk_on_lane(dsim,
(DSIM_LANE_CLOCK | dsim->data_lane), 0);
exynos_mipi_dsi_set_esc_clk_prs(dsim, 0, 0);
exynos_mipi_dsi_enable_byte_clock(dsim, 0);
if (byte_clk_sel == DSIM_PLL_OUT_DIV8)
exynos_mipi_dsi_pll_on(dsim, 0);
}
return 0;
}
int exynos_mipi_dsi_init_dsim(struct mipi_dsim_device *dsim)
{
dsim->state = DSIM_STATE_INIT;
switch (dsim->dsim_config->e_no_data_lane) {
case DSIM_DATA_LANE_1:
dsim->data_lane = DSIM_LANE_DATA0;
break;
case DSIM_DATA_LANE_2:
dsim->data_lane = DSIM_LANE_DATA0 | DSIM_LANE_DATA1;
break;
case DSIM_DATA_LANE_3:
dsim->data_lane = DSIM_LANE_DATA0 | DSIM_LANE_DATA1 |
DSIM_LANE_DATA2;
break;
case DSIM_DATA_LANE_4:
dsim->data_lane = DSIM_LANE_DATA0 | DSIM_LANE_DATA1 |
DSIM_LANE_DATA2 | DSIM_LANE_DATA3;
break;
default:
dev_info(dsim->dev, "data lane is invalid.\n");
return -EINVAL;
};
exynos_mipi_dsi_sw_reset(dsim);
exynos_mipi_dsi_func_reset(dsim);
exynos_mipi_dsi_dp_dn_swap(dsim, 0);
return 0;
}
void exynos_mipi_dsi_init_interrupt(struct mipi_dsim_device *dsim)
{
unsigned int src = 0;
src = (INTSRC_SFR_FIFO_EMPTY | INTSRC_RX_DATA_DONE);
exynos_mipi_dsi_set_interrupt(dsim, src, 1);
src = 0;
src = ~(INTMSK_RX_DONE | INTMSK_FIFO_EMPTY);
exynos_mipi_dsi_set_interrupt_mask(dsim, src, 1);
}
int exynos_mipi_dsi_enable_frame_done_int(struct mipi_dsim_device *dsim,
unsigned int enable)
{
exynos_mipi_dsi_set_interrupt_mask(dsim, INTMSK_FRAME_DONE, enable);
return 0;
}
void exynos_mipi_dsi_stand_by(struct mipi_dsim_device *dsim,
unsigned int enable)
{
exynos_mipi_dsi_set_main_stand_by(dsim, enable);
}
int exynos_mipi_dsi_set_display_mode(struct mipi_dsim_device *dsim,
struct mipi_dsim_config *dsim_config)
{
struct mipi_dsim_platform_data *dsim_pd;
struct fb_videomode *timing;
dsim_pd = (struct mipi_dsim_platform_data *)dsim->pd;
timing = (struct fb_videomode *)dsim_pd->lcd_panel_info;
if (dsim_config->e_interface == (u32) DSIM_VIDEO) {
if (dsim_config->auto_vertical_cnt == 0) {
exynos_mipi_dsi_set_main_disp_vporch(dsim,
dsim_config->cmd_allow,
timing->lower_margin,
timing->upper_margin);
exynos_mipi_dsi_set_main_disp_hporch(dsim,
timing->right_margin,
timing->left_margin);
exynos_mipi_dsi_set_main_disp_sync_area(dsim,
timing->vsync_len,
timing->hsync_len);
}
}
exynos_mipi_dsi_set_main_disp_resol(dsim, timing->xres,
timing->yres);
exynos_mipi_dsi_display_config(dsim, dsim_config);
dev_info(dsim->dev, "lcd panel ==> width = %d, height = %d\n",
timing->xres, timing->yres);
return 0;
}
int exynos_mipi_dsi_init_link(struct mipi_dsim_device *dsim)
{
unsigned int time_out = 100;
switch (dsim->state) {
case DSIM_STATE_INIT:
exynos_mipi_dsi_init_fifo_pointer(dsim, 0x1f);
exynos_mipi_dsi_init_config(dsim);
exynos_mipi_dsi_enable_lane(dsim, DSIM_LANE_CLOCK, 1);
exynos_mipi_dsi_enable_lane(dsim, dsim->data_lane, 1);
exynos_mipi_dsi_set_clock(dsim, dsim->dsim_config->e_byte_clk, 1);
while (!(exynos_mipi_dsi_is_lane_state(dsim))) {
time_out--;
if (time_out == 0) {
dev_err(dsim->dev,
"DSI Master is not stop state.\n");
dev_err(dsim->dev,
"Check initialization process\n");
return -EINVAL;
}
}
if (time_out != 0) {
dev_info(dsim->dev,
"DSI Master driver has been completed.\n");
dev_info(dsim->dev, "DSI Master state is stop state\n");
}
dsim->state = DSIM_STATE_STOP;
exynos_mipi_dsi_set_stop_state_counter(dsim,
dsim->dsim_config->stop_holding_cnt);
exynos_mipi_dsi_set_bta_timeout(dsim,
dsim->dsim_config->bta_timeout);
exynos_mipi_dsi_set_lpdr_timeout(dsim,
dsim->dsim_config->rx_timeout);
return 0;
default:
dev_info(dsim->dev, "DSI Master is already init.\n");
return 0;
}
return 0;
}
int exynos_mipi_dsi_set_hs_enable(struct mipi_dsim_device *dsim)
{
if (dsim->state != DSIM_STATE_STOP) {
dev_warn(dsim->dev, "DSIM is not in stop state.\n");
return 0;
}
if (dsim->e_clk_src == DSIM_EXT_CLK_BYPASS) {
dev_warn(dsim->dev, "clock source is external bypass.\n");
return 0;
}
dsim->state = DSIM_STATE_HSCLKEN;
exynos_mipi_dsi_set_lcdc_transfer_mode(dsim, 0);
exynos_mipi_dsi_set_cpu_transfer_mode(dsim, 0);
exynos_mipi_dsi_enable_hs_clock(dsim, 1);
return 0;
}
int exynos_mipi_dsi_set_data_transfer_mode(struct mipi_dsim_device *dsim,
unsigned int mode)
{
if (mode) {
if (dsim->state != DSIM_STATE_HSCLKEN) {
dev_err(dsim->dev, "HS Clock lane is not enabled.\n");
return -EINVAL;
}
exynos_mipi_dsi_set_lcdc_transfer_mode(dsim, 0);
} else {
if (dsim->state == DSIM_STATE_INIT || dsim->state ==
DSIM_STATE_ULPS) {
dev_err(dsim->dev,
"DSI Master is not STOP or HSDT state.\n");
return -EINVAL;
}
exynos_mipi_dsi_set_cpu_transfer_mode(dsim, 0);
}
return 0;
}
int exynos_mipi_dsi_get_frame_done_status(struct mipi_dsim_device *dsim)
{
return _exynos_mipi_dsi_get_frame_done_status(dsim);
}
int exynos_mipi_dsi_clear_frame_done(struct mipi_dsim_device *dsim)
{
_exynos_mipi_dsi_clear_frame_done(dsim);
return 0;
}
int exynos_mipi_dsi_fifo_clear(struct mipi_dsim_device *dsim,
unsigned int val)
{
int try = TRY_FIFO_CLEAR;
exynos_mipi_dsi_sw_reset_release(dsim);
exynos_mipi_dsi_func_reset(dsim);
do {
if (exynos_mipi_dsi_get_sw_reset_release(dsim)) {
exynos_mipi_dsi_init_interrupt(dsim);
dev_dbg(dsim->dev, "reset release done.\n");
return 0;
}
} while (--try);
dev_err(dsim->dev, "failed to clear dsim fifo.\n");
return -EAGAIN;
}
