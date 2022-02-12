static inline struct mtk_dsi *encoder_to_dsi(struct drm_encoder *e)
{
return container_of(e, struct mtk_dsi, encoder);
}
static inline struct mtk_dsi *connector_to_dsi(struct drm_connector *c)
{
return container_of(c, struct mtk_dsi, conn);
}
static inline struct mtk_dsi *host_to_dsi(struct mipi_dsi_host *h)
{
return container_of(h, struct mtk_dsi, host);
}
static void mtk_dsi_mask(struct mtk_dsi *dsi, u32 offset, u32 mask, u32 data)
{
u32 temp = readl(dsi->regs + offset);
writel((temp & ~mask) | (data & mask), dsi->regs + offset);
}
static void mtk_dsi_phy_timconfig(struct mtk_dsi *dsi)
{
u32 timcon0, timcon1, timcon2, timcon3;
u32 ui, cycle_time;
ui = 1000 / dsi->data_rate + 0x01;
cycle_time = 8000 / dsi->data_rate + 0x01;
timcon0 = T_LPX | T_HS_PREP << 8 | T_HS_ZERO << 16 | T_HS_TRAIL << 24;
timcon1 = 4 * T_LPX | (3 * T_LPX / 2) << 8 | 5 * T_LPX << 16 |
T_HS_EXIT << 24;
timcon2 = ((NS_TO_CYCLE(0x64, cycle_time) + 0xa) << 24) |
(NS_TO_CYCLE(0x150, cycle_time) << 16);
timcon3 = NS_TO_CYCLE(0x40, cycle_time) | (2 * T_LPX) << 16 |
NS_TO_CYCLE(80 + 52 * ui, cycle_time) << 8;
writel(timcon0, dsi->regs + DSI_PHY_TIMECON0);
writel(timcon1, dsi->regs + DSI_PHY_TIMECON1);
writel(timcon2, dsi->regs + DSI_PHY_TIMECON2);
writel(timcon3, dsi->regs + DSI_PHY_TIMECON3);
}
static void mtk_dsi_enable(struct mtk_dsi *dsi)
{
mtk_dsi_mask(dsi, DSI_CON_CTRL, DSI_EN, DSI_EN);
}
static void mtk_dsi_disable(struct mtk_dsi *dsi)
{
mtk_dsi_mask(dsi, DSI_CON_CTRL, DSI_EN, 0);
}
static void mtk_dsi_reset_engine(struct mtk_dsi *dsi)
{
mtk_dsi_mask(dsi, DSI_CON_CTRL, DSI_RESET, DSI_RESET);
mtk_dsi_mask(dsi, DSI_CON_CTRL, DSI_RESET, 0);
}
static void mtk_dsi_clk_ulp_mode_enter(struct mtk_dsi *dsi)
{
mtk_dsi_mask(dsi, DSI_PHY_LCCON, LC_HS_TX_EN, 0);
mtk_dsi_mask(dsi, DSI_PHY_LCCON, LC_ULPM_EN, 0);
}
static void mtk_dsi_clk_ulp_mode_leave(struct mtk_dsi *dsi)
{
mtk_dsi_mask(dsi, DSI_PHY_LCCON, LC_ULPM_EN, 0);
mtk_dsi_mask(dsi, DSI_PHY_LCCON, LC_WAKEUP_EN, LC_WAKEUP_EN);
mtk_dsi_mask(dsi, DSI_PHY_LCCON, LC_WAKEUP_EN, 0);
}
static void mtk_dsi_lane0_ulp_mode_enter(struct mtk_dsi *dsi)
{
mtk_dsi_mask(dsi, DSI_PHY_LD0CON, LD0_HS_TX_EN, 0);
mtk_dsi_mask(dsi, DSI_PHY_LD0CON, LD0_ULPM_EN, 0);
}
static void mtk_dsi_lane0_ulp_mode_leave(struct mtk_dsi *dsi)
{
mtk_dsi_mask(dsi, DSI_PHY_LD0CON, LD0_ULPM_EN, 0);
mtk_dsi_mask(dsi, DSI_PHY_LD0CON, LD0_WAKEUP_EN, LD0_WAKEUP_EN);
mtk_dsi_mask(dsi, DSI_PHY_LD0CON, LD0_WAKEUP_EN, 0);
}
static bool mtk_dsi_clk_hs_state(struct mtk_dsi *dsi)
{
u32 tmp_reg1;
tmp_reg1 = readl(dsi->regs + DSI_PHY_LCCON);
return ((tmp_reg1 & LC_HS_TX_EN) == 1) ? true : false;
}
static void mtk_dsi_clk_hs_mode(struct mtk_dsi *dsi, bool enter)
{
if (enter && !mtk_dsi_clk_hs_state(dsi))
mtk_dsi_mask(dsi, DSI_PHY_LCCON, LC_HS_TX_EN, LC_HS_TX_EN);
else if (!enter && mtk_dsi_clk_hs_state(dsi))
mtk_dsi_mask(dsi, DSI_PHY_LCCON, LC_HS_TX_EN, 0);
}
static void mtk_dsi_set_mode(struct mtk_dsi *dsi)
{
u32 vid_mode = CMD_MODE;
if (dsi->mode_flags & MIPI_DSI_MODE_VIDEO) {
if (dsi->mode_flags & MIPI_DSI_MODE_VIDEO_BURST)
vid_mode = BURST_MODE;
else if (dsi->mode_flags & MIPI_DSI_MODE_VIDEO_SYNC_PULSE)
vid_mode = SYNC_PULSE_MODE;
else
vid_mode = SYNC_EVENT_MODE;
}
writel(vid_mode, dsi->regs + DSI_MODE_CTRL);
}
static void mtk_dsi_set_vm_cmd(struct mtk_dsi *dsi)
{
mtk_dsi_mask(dsi, DSI_VM_CMD_CON, VM_CMD_EN, VM_CMD_EN);
mtk_dsi_mask(dsi, DSI_VM_CMD_CON, TS_VFP_EN, TS_VFP_EN);
}
static void mtk_dsi_ps_control_vact(struct mtk_dsi *dsi)
{
struct videomode *vm = &dsi->vm;
u32 dsi_buf_bpp, ps_wc;
u32 ps_bpp_mode;
if (dsi->format == MIPI_DSI_FMT_RGB565)
dsi_buf_bpp = 2;
else
dsi_buf_bpp = 3;
ps_wc = vm->hactive * dsi_buf_bpp;
ps_bpp_mode = ps_wc;
switch (dsi->format) {
case MIPI_DSI_FMT_RGB888:
ps_bpp_mode |= PACKED_PS_24BIT_RGB888;
break;
case MIPI_DSI_FMT_RGB666:
ps_bpp_mode |= PACKED_PS_18BIT_RGB666;
break;
case MIPI_DSI_FMT_RGB666_PACKED:
ps_bpp_mode |= LOOSELY_PS_18BIT_RGB666;
break;
case MIPI_DSI_FMT_RGB565:
ps_bpp_mode |= PACKED_PS_16BIT_RGB565;
break;
}
writel(vm->vactive, dsi->regs + DSI_VACT_NL);
writel(ps_bpp_mode, dsi->regs + DSI_PSCTRL);
writel(ps_wc, dsi->regs + DSI_HSTX_CKL_WC);
}
static void mtk_dsi_rxtx_control(struct mtk_dsi *dsi)
{
u32 tmp_reg;
switch (dsi->lanes) {
case 1:
tmp_reg = 1 << 2;
break;
case 2:
tmp_reg = 3 << 2;
break;
case 3:
tmp_reg = 7 << 2;
break;
case 4:
tmp_reg = 0xf << 2;
break;
default:
tmp_reg = 0xf << 2;
break;
}
tmp_reg |= (dsi->mode_flags & MIPI_DSI_CLOCK_NON_CONTINUOUS) << 6;
tmp_reg |= (dsi->mode_flags & MIPI_DSI_MODE_EOT_PACKET) >> 3;
writel(tmp_reg, dsi->regs + DSI_TXRX_CTRL);
}
static void mtk_dsi_ps_control(struct mtk_dsi *dsi)
{
u32 dsi_tmp_buf_bpp;
u32 tmp_reg;
switch (dsi->format) {
case MIPI_DSI_FMT_RGB888:
tmp_reg = PACKED_PS_24BIT_RGB888;
dsi_tmp_buf_bpp = 3;
break;
case MIPI_DSI_FMT_RGB666:
tmp_reg = LOOSELY_PS_18BIT_RGB666;
dsi_tmp_buf_bpp = 3;
break;
case MIPI_DSI_FMT_RGB666_PACKED:
tmp_reg = PACKED_PS_18BIT_RGB666;
dsi_tmp_buf_bpp = 3;
break;
case MIPI_DSI_FMT_RGB565:
tmp_reg = PACKED_PS_16BIT_RGB565;
dsi_tmp_buf_bpp = 2;
break;
default:
tmp_reg = PACKED_PS_24BIT_RGB888;
dsi_tmp_buf_bpp = 3;
break;
}
tmp_reg += dsi->vm.hactive * dsi_tmp_buf_bpp & DSI_PS_WC;
writel(tmp_reg, dsi->regs + DSI_PSCTRL);
}
static void mtk_dsi_config_vdo_timing(struct mtk_dsi *dsi)
{
u32 horizontal_sync_active_byte;
u32 horizontal_backporch_byte;
u32 horizontal_frontporch_byte;
u32 dsi_tmp_buf_bpp;
struct videomode *vm = &dsi->vm;
if (dsi->format == MIPI_DSI_FMT_RGB565)
dsi_tmp_buf_bpp = 2;
else
dsi_tmp_buf_bpp = 3;
writel(vm->vsync_len, dsi->regs + DSI_VSA_NL);
writel(vm->vback_porch, dsi->regs + DSI_VBP_NL);
writel(vm->vfront_porch, dsi->regs + DSI_VFP_NL);
writel(vm->vactive, dsi->regs + DSI_VACT_NL);
horizontal_sync_active_byte = (vm->hsync_len * dsi_tmp_buf_bpp - 10);
if (dsi->mode_flags & MIPI_DSI_MODE_VIDEO_SYNC_PULSE)
horizontal_backporch_byte =
(vm->hback_porch * dsi_tmp_buf_bpp - 10);
else
horizontal_backporch_byte = ((vm->hback_porch + vm->hsync_len) *
dsi_tmp_buf_bpp - 10);
horizontal_frontporch_byte = (vm->hfront_porch * dsi_tmp_buf_bpp - 12);
writel(horizontal_sync_active_byte, dsi->regs + DSI_HSA_WC);
writel(horizontal_backporch_byte, dsi->regs + DSI_HBP_WC);
writel(horizontal_frontporch_byte, dsi->regs + DSI_HFP_WC);
mtk_dsi_ps_control(dsi);
}
static void mtk_dsi_start(struct mtk_dsi *dsi)
{
writel(0, dsi->regs + DSI_START);
writel(1, dsi->regs + DSI_START);
}
static void mtk_dsi_stop(struct mtk_dsi *dsi)
{
writel(0, dsi->regs + DSI_START);
}
static void mtk_dsi_set_cmd_mode(struct mtk_dsi *dsi)
{
writel(CMD_MODE, dsi->regs + DSI_MODE_CTRL);
}
static void mtk_dsi_set_interrupt_enable(struct mtk_dsi *dsi)
{
u32 inten = LPRX_RD_RDY_INT_FLAG | CMD_DONE_INT_FLAG | VM_DONE_INT_FLAG;
writel(inten, dsi->regs + DSI_INTEN);
}
static void mtk_dsi_irq_data_set(struct mtk_dsi *dsi, u32 irq_bit)
{
dsi->irq_data |= irq_bit;
}
static void mtk_dsi_irq_data_clear(struct mtk_dsi *dsi, u32 irq_bit)
{
dsi->irq_data &= ~irq_bit;
}
static s32 mtk_dsi_wait_for_irq_done(struct mtk_dsi *dsi, u32 irq_flag,
unsigned int timeout)
{
s32 ret = 0;
unsigned long jiffies = msecs_to_jiffies(timeout);
ret = wait_event_interruptible_timeout(dsi->irq_wait_queue,
dsi->irq_data & irq_flag,
jiffies);
if (ret == 0) {
DRM_WARN("Wait DSI IRQ(0x%08x) Timeout\n", irq_flag);
mtk_dsi_enable(dsi);
mtk_dsi_reset_engine(dsi);
}
return ret;
}
static irqreturn_t mtk_dsi_irq(int irq, void *dev_id)
{
struct mtk_dsi *dsi = dev_id;
u32 status, tmp;
u32 flag = LPRX_RD_RDY_INT_FLAG | CMD_DONE_INT_FLAG | VM_DONE_INT_FLAG;
status = readl(dsi->regs + DSI_INTSTA) & flag;
if (status) {
do {
mtk_dsi_mask(dsi, DSI_RACK, RACK, RACK);
tmp = readl(dsi->regs + DSI_INTSTA);
} while (tmp & DSI_BUSY);
mtk_dsi_mask(dsi, DSI_INTSTA, status, 0);
mtk_dsi_irq_data_set(dsi, status);
wake_up_interruptible(&dsi->irq_wait_queue);
}
return IRQ_HANDLED;
}
static s32 mtk_dsi_switch_to_cmd_mode(struct mtk_dsi *dsi, u8 irq_flag, u32 t)
{
mtk_dsi_irq_data_clear(dsi, irq_flag);
mtk_dsi_set_cmd_mode(dsi);
if (!mtk_dsi_wait_for_irq_done(dsi, irq_flag, t)) {
DRM_ERROR("failed to switch cmd mode\n");
return -ETIME;
} else {
return 0;
}
}
static int mtk_dsi_poweron(struct mtk_dsi *dsi)
{
struct device *dev = dsi->dev;
int ret;
u64 pixel_clock, total_bits;
u32 htotal, htotal_bits, bit_per_pixel, overhead_cycles, overhead_bits;
if (++dsi->refcount != 1)
return 0;
switch (dsi->format) {
case MIPI_DSI_FMT_RGB565:
bit_per_pixel = 16;
break;
case MIPI_DSI_FMT_RGB666_PACKED:
bit_per_pixel = 18;
break;
case MIPI_DSI_FMT_RGB666:
case MIPI_DSI_FMT_RGB888:
default:
bit_per_pixel = 24;
break;
}
pixel_clock = dsi->vm.pixelclock * 1000;
htotal = dsi->vm.hactive + dsi->vm.hback_porch + dsi->vm.hfront_porch +
dsi->vm.hsync_len;
htotal_bits = htotal * bit_per_pixel;
overhead_cycles = T_LPX + T_HS_PREP + T_HS_ZERO + T_HS_TRAIL +
T_HS_EXIT;
overhead_bits = overhead_cycles * dsi->lanes * 8;
total_bits = htotal_bits + overhead_bits;
dsi->data_rate = DIV_ROUND_UP_ULL(pixel_clock * total_bits,
htotal * dsi->lanes);
ret = clk_set_rate(dsi->hs_clk, dsi->data_rate);
if (ret < 0) {
dev_err(dev, "Failed to set data rate: %d\n", ret);
goto err_refcount;
}
phy_power_on(dsi->phy);
ret = clk_prepare_enable(dsi->engine_clk);
if (ret < 0) {
dev_err(dev, "Failed to enable engine clock: %d\n", ret);
goto err_phy_power_off;
}
ret = clk_prepare_enable(dsi->digital_clk);
if (ret < 0) {
dev_err(dev, "Failed to enable digital clock: %d\n", ret);
goto err_disable_engine_clk;
}
mtk_dsi_enable(dsi);
mtk_dsi_reset_engine(dsi);
mtk_dsi_phy_timconfig(dsi);
mtk_dsi_rxtx_control(dsi);
mtk_dsi_ps_control_vact(dsi);
mtk_dsi_set_vm_cmd(dsi);
mtk_dsi_config_vdo_timing(dsi);
mtk_dsi_set_interrupt_enable(dsi);
mtk_dsi_clk_ulp_mode_leave(dsi);
mtk_dsi_lane0_ulp_mode_leave(dsi);
mtk_dsi_clk_hs_mode(dsi, 0);
if (dsi->panel) {
if (drm_panel_prepare(dsi->panel)) {
DRM_ERROR("failed to prepare the panel\n");
goto err_disable_digital_clk;
}
}
return 0;
err_disable_digital_clk:
clk_disable_unprepare(dsi->digital_clk);
err_disable_engine_clk:
clk_disable_unprepare(dsi->engine_clk);
err_phy_power_off:
phy_power_off(dsi->phy);
err_refcount:
dsi->refcount--;
return ret;
}
static void mtk_dsi_poweroff(struct mtk_dsi *dsi)
{
if (WARN_ON(dsi->refcount == 0))
return;
if (--dsi->refcount != 0)
return;
if (!mtk_dsi_switch_to_cmd_mode(dsi, VM_DONE_INT_FLAG, 500)) {
if (dsi->panel) {
if (drm_panel_unprepare(dsi->panel)) {
DRM_ERROR("failed to unprepare the panel\n");
return;
}
}
}
mtk_dsi_reset_engine(dsi);
mtk_dsi_lane0_ulp_mode_enter(dsi);
mtk_dsi_clk_ulp_mode_enter(dsi);
mtk_dsi_disable(dsi);
clk_disable_unprepare(dsi->engine_clk);
clk_disable_unprepare(dsi->digital_clk);
phy_power_off(dsi->phy);
}
static void mtk_output_dsi_enable(struct mtk_dsi *dsi)
{
int ret;
if (dsi->enabled)
return;
ret = mtk_dsi_poweron(dsi);
if (ret < 0) {
DRM_ERROR("failed to power on dsi\n");
return;
}
mtk_dsi_set_mode(dsi);
mtk_dsi_clk_hs_mode(dsi, 1);
mtk_dsi_start(dsi);
if (dsi->panel) {
if (drm_panel_enable(dsi->panel)) {
DRM_ERROR("failed to enable the panel\n");
goto err_dsi_power_off;
}
}
dsi->enabled = true;
return;
err_dsi_power_off:
mtk_dsi_stop(dsi);
mtk_dsi_poweroff(dsi);
}
static void mtk_output_dsi_disable(struct mtk_dsi *dsi)
{
if (!dsi->enabled)
return;
if (dsi->panel) {
if (drm_panel_disable(dsi->panel)) {
DRM_ERROR("failed to disable the panel\n");
return;
}
}
mtk_dsi_stop(dsi);
mtk_dsi_poweroff(dsi);
dsi->enabled = false;
}
static void mtk_dsi_encoder_destroy(struct drm_encoder *encoder)
{
drm_encoder_cleanup(encoder);
}
static bool mtk_dsi_encoder_mode_fixup(struct drm_encoder *encoder,
const struct drm_display_mode *mode,
struct drm_display_mode *adjusted_mode)
{
return true;
}
static void mtk_dsi_encoder_mode_set(struct drm_encoder *encoder,
struct drm_display_mode *mode,
struct drm_display_mode *adjusted)
{
struct mtk_dsi *dsi = encoder_to_dsi(encoder);
dsi->vm.pixelclock = adjusted->clock;
dsi->vm.hactive = adjusted->hdisplay;
dsi->vm.hback_porch = adjusted->htotal - adjusted->hsync_end;
dsi->vm.hfront_porch = adjusted->hsync_start - adjusted->hdisplay;
dsi->vm.hsync_len = adjusted->hsync_end - adjusted->hsync_start;
dsi->vm.vactive = adjusted->vdisplay;
dsi->vm.vback_porch = adjusted->vtotal - adjusted->vsync_end;
dsi->vm.vfront_porch = adjusted->vsync_start - adjusted->vdisplay;
dsi->vm.vsync_len = adjusted->vsync_end - adjusted->vsync_start;
}
static void mtk_dsi_encoder_disable(struct drm_encoder *encoder)
{
struct mtk_dsi *dsi = encoder_to_dsi(encoder);
mtk_output_dsi_disable(dsi);
}
static void mtk_dsi_encoder_enable(struct drm_encoder *encoder)
{
struct mtk_dsi *dsi = encoder_to_dsi(encoder);
mtk_output_dsi_enable(dsi);
}
static int mtk_dsi_connector_get_modes(struct drm_connector *connector)
{
struct mtk_dsi *dsi = connector_to_dsi(connector);
return drm_panel_get_modes(dsi->panel);
}
static int mtk_dsi_create_connector(struct drm_device *drm, struct mtk_dsi *dsi)
{
int ret;
ret = drm_connector_init(drm, &dsi->conn, &mtk_dsi_connector_funcs,
DRM_MODE_CONNECTOR_DSI);
if (ret) {
DRM_ERROR("Failed to connector init to drm\n");
return ret;
}
drm_connector_helper_add(&dsi->conn, &mtk_dsi_connector_helper_funcs);
dsi->conn.dpms = DRM_MODE_DPMS_OFF;
drm_mode_connector_attach_encoder(&dsi->conn, &dsi->encoder);
if (dsi->panel) {
ret = drm_panel_attach(dsi->panel, &dsi->conn);
if (ret) {
DRM_ERROR("Failed to attach panel to drm\n");
goto err_connector_cleanup;
}
}
return 0;
err_connector_cleanup:
drm_connector_cleanup(&dsi->conn);
return ret;
}
static int mtk_dsi_create_conn_enc(struct drm_device *drm, struct mtk_dsi *dsi)
{
int ret;
ret = drm_encoder_init(drm, &dsi->encoder, &mtk_dsi_encoder_funcs,
DRM_MODE_ENCODER_DSI, NULL);
if (ret) {
DRM_ERROR("Failed to encoder init to drm\n");
return ret;
}
drm_encoder_helper_add(&dsi->encoder, &mtk_dsi_encoder_helper_funcs);
dsi->encoder.possible_crtcs = 1;
ret = drm_bridge_attach(&dsi->encoder, dsi->bridge, NULL);
if (ret) {
DRM_ERROR("Failed to attach bridge to drm\n");
ret = mtk_dsi_create_connector(drm, dsi);
if (ret)
goto err_encoder_cleanup;
}
return 0;
err_encoder_cleanup:
drm_encoder_cleanup(&dsi->encoder);
return ret;
}
static void mtk_dsi_destroy_conn_enc(struct mtk_dsi *dsi)
{
drm_encoder_cleanup(&dsi->encoder);
if (dsi->conn.dev)
drm_connector_cleanup(&dsi->conn);
}
static void mtk_dsi_ddp_start(struct mtk_ddp_comp *comp)
{
struct mtk_dsi *dsi = container_of(comp, struct mtk_dsi, ddp_comp);
mtk_dsi_poweron(dsi);
}
static void mtk_dsi_ddp_stop(struct mtk_ddp_comp *comp)
{
struct mtk_dsi *dsi = container_of(comp, struct mtk_dsi, ddp_comp);
mtk_dsi_poweroff(dsi);
}
static int mtk_dsi_host_attach(struct mipi_dsi_host *host,
struct mipi_dsi_device *device)
{
struct mtk_dsi *dsi = host_to_dsi(host);
dsi->lanes = device->lanes;
dsi->format = device->format;
dsi->mode_flags = device->mode_flags;
if (dsi->conn.dev)
drm_helper_hpd_irq_event(dsi->conn.dev);
return 0;
}
static int mtk_dsi_host_detach(struct mipi_dsi_host *host,
struct mipi_dsi_device *device)
{
struct mtk_dsi *dsi = host_to_dsi(host);
if (dsi->conn.dev)
drm_helper_hpd_irq_event(dsi->conn.dev);
return 0;
}
static void mtk_dsi_wait_for_idle(struct mtk_dsi *dsi)
{
int ret;
u32 val;
ret = readl_poll_timeout(dsi->regs + DSI_INTSTA, val, !(val & DSI_BUSY),
4, 2000000);
if (ret) {
DRM_WARN("polling dsi wait not busy timeout!\n");
mtk_dsi_enable(dsi);
mtk_dsi_reset_engine(dsi);
}
}
static u32 mtk_dsi_recv_cnt(u8 type, u8 *read_data)
{
switch (type) {
case MIPI_DSI_RX_GENERIC_SHORT_READ_RESPONSE_1BYTE:
case MIPI_DSI_RX_DCS_SHORT_READ_RESPONSE_1BYTE:
return 1;
case MIPI_DSI_RX_GENERIC_SHORT_READ_RESPONSE_2BYTE:
case MIPI_DSI_RX_DCS_SHORT_READ_RESPONSE_2BYTE:
return 2;
case MIPI_DSI_RX_GENERIC_LONG_READ_RESPONSE:
case MIPI_DSI_RX_DCS_LONG_READ_RESPONSE:
return read_data[1] + read_data[2] * 16;
case MIPI_DSI_RX_ACKNOWLEDGE_AND_ERROR_REPORT:
DRM_INFO("type is 0x02, try again\n");
break;
default:
DRM_INFO("type(0x%x) not recognized\n", type);
break;
}
return 0;
}
static void mtk_dsi_cmdq(struct mtk_dsi *dsi, const struct mipi_dsi_msg *msg)
{
const char *tx_buf = msg->tx_buf;
u8 config, cmdq_size, cmdq_off, type = msg->type;
u32 reg_val, cmdq_mask, i;
if (MTK_DSI_HOST_IS_READ(type))
config = BTA;
else
config = (msg->tx_len > 2) ? LONG_PACKET : SHORT_PACKET;
if (msg->tx_len > 2) {
cmdq_size = 1 + (msg->tx_len + 3) / 4;
cmdq_off = 4;
cmdq_mask = CONFIG | DATA_ID | DATA_0 | DATA_1;
reg_val = (msg->tx_len << 16) | (type << 8) | config;
} else {
cmdq_size = 1;
cmdq_off = 2;
cmdq_mask = CONFIG | DATA_ID;
reg_val = (type << 8) | config;
}
for (i = 0; i < msg->tx_len; i++)
writeb(tx_buf[i], dsi->regs + DSI_CMDQ0 + cmdq_off + i);
mtk_dsi_mask(dsi, DSI_CMDQ0, cmdq_mask, reg_val);
mtk_dsi_mask(dsi, DSI_CMDQ_SIZE, CMDQ_SIZE, cmdq_size);
}
static ssize_t mtk_dsi_host_send_cmd(struct mtk_dsi *dsi,
const struct mipi_dsi_msg *msg, u8 flag)
{
mtk_dsi_wait_for_idle(dsi);
mtk_dsi_irq_data_clear(dsi, flag);
mtk_dsi_cmdq(dsi, msg);
mtk_dsi_start(dsi);
if (!mtk_dsi_wait_for_irq_done(dsi, flag, 2000))
return -ETIME;
else
return 0;
}
static ssize_t mtk_dsi_host_transfer(struct mipi_dsi_host *host,
const struct mipi_dsi_msg *msg)
{
struct mtk_dsi *dsi = host_to_dsi(host);
u32 recv_cnt, i;
u8 read_data[16];
void *src_addr;
u8 irq_flag = CMD_DONE_INT_FLAG;
if (readl(dsi->regs + DSI_MODE_CTRL) & MODE) {
DRM_ERROR("dsi engine is not command mode\n");
return -EINVAL;
}
if (MTK_DSI_HOST_IS_READ(msg->type))
irq_flag |= LPRX_RD_RDY_INT_FLAG;
if (mtk_dsi_host_send_cmd(dsi, msg, irq_flag) < 0)
return -ETIME;
if (!MTK_DSI_HOST_IS_READ(msg->type))
return 0;
if (!msg->rx_buf) {
DRM_ERROR("dsi receive buffer size may be NULL\n");
return -EINVAL;
}
for (i = 0; i < 16; i++)
*(read_data + i) = readb(dsi->regs + DSI_RX_DATA0 + i);
recv_cnt = mtk_dsi_recv_cnt(read_data[0], read_data);
if (recv_cnt > 2)
src_addr = &read_data[4];
else
src_addr = &read_data[1];
if (recv_cnt > 10)
recv_cnt = 10;
if (recv_cnt > msg->rx_len)
recv_cnt = msg->rx_len;
if (recv_cnt)
memcpy(msg->rx_buf, src_addr, recv_cnt);
DRM_INFO("dsi get %d byte data from the panel address(0x%x)\n",
recv_cnt, *((u8 *)(msg->tx_buf)));
return recv_cnt;
}
static int mtk_dsi_bind(struct device *dev, struct device *master, void *data)
{
int ret;
struct drm_device *drm = data;
struct mtk_dsi *dsi = dev_get_drvdata(dev);
ret = mtk_ddp_comp_register(drm, &dsi->ddp_comp);
if (ret < 0) {
dev_err(dev, "Failed to register component %s: %d\n",
dev->of_node->full_name, ret);
return ret;
}
ret = mipi_dsi_host_register(&dsi->host);
if (ret < 0) {
dev_err(dev, "failed to register DSI host: %d\n", ret);
goto err_ddp_comp_unregister;
}
ret = mtk_dsi_create_conn_enc(drm, dsi);
if (ret) {
DRM_ERROR("Encoder create failed with %d\n", ret);
goto err_unregister;
}
return 0;
err_unregister:
mipi_dsi_host_unregister(&dsi->host);
err_ddp_comp_unregister:
mtk_ddp_comp_unregister(drm, &dsi->ddp_comp);
return ret;
}
static void mtk_dsi_unbind(struct device *dev, struct device *master,
void *data)
{
struct drm_device *drm = data;
struct mtk_dsi *dsi = dev_get_drvdata(dev);
mtk_dsi_destroy_conn_enc(dsi);
mipi_dsi_host_unregister(&dsi->host);
mtk_ddp_comp_unregister(drm, &dsi->ddp_comp);
}
static int mtk_dsi_probe(struct platform_device *pdev)
{
struct mtk_dsi *dsi;
struct device *dev = &pdev->dev;
struct resource *regs;
int irq_num;
int comp_id;
int ret;
dsi = devm_kzalloc(dev, sizeof(*dsi), GFP_KERNEL);
if (!dsi)
return -ENOMEM;
dsi->host.ops = &mtk_dsi_ops;
dsi->host.dev = dev;
ret = drm_of_find_panel_or_bridge(dev->of_node, 0, 0,
&dsi->panel, &dsi->bridge);
if (ret)
return ret;
dsi->engine_clk = devm_clk_get(dev, "engine");
if (IS_ERR(dsi->engine_clk)) {
ret = PTR_ERR(dsi->engine_clk);
dev_err(dev, "Failed to get engine clock: %d\n", ret);
return ret;
}
dsi->digital_clk = devm_clk_get(dev, "digital");
if (IS_ERR(dsi->digital_clk)) {
ret = PTR_ERR(dsi->digital_clk);
dev_err(dev, "Failed to get digital clock: %d\n", ret);
return ret;
}
dsi->hs_clk = devm_clk_get(dev, "hs");
if (IS_ERR(dsi->hs_clk)) {
ret = PTR_ERR(dsi->hs_clk);
dev_err(dev, "Failed to get hs clock: %d\n", ret);
return ret;
}
regs = platform_get_resource(pdev, IORESOURCE_MEM, 0);
dsi->regs = devm_ioremap_resource(dev, regs);
if (IS_ERR(dsi->regs)) {
ret = PTR_ERR(dsi->regs);
dev_err(dev, "Failed to ioremap memory: %d\n", ret);
return ret;
}
dsi->phy = devm_phy_get(dev, "dphy");
if (IS_ERR(dsi->phy)) {
ret = PTR_ERR(dsi->phy);
dev_err(dev, "Failed to get MIPI-DPHY: %d\n", ret);
return ret;
}
comp_id = mtk_ddp_comp_get_id(dev->of_node, MTK_DSI);
if (comp_id < 0) {
dev_err(dev, "Failed to identify by alias: %d\n", comp_id);
return comp_id;
}
ret = mtk_ddp_comp_init(dev, dev->of_node, &dsi->ddp_comp, comp_id,
&mtk_dsi_funcs);
if (ret) {
dev_err(dev, "Failed to initialize component: %d\n", ret);
return ret;
}
irq_num = platform_get_irq(pdev, 0);
if (irq_num < 0) {
dev_err(&pdev->dev, "failed to request dsi irq resource\n");
return -EPROBE_DEFER;
}
irq_set_status_flags(irq_num, IRQ_TYPE_LEVEL_LOW);
ret = devm_request_irq(&pdev->dev, irq_num, mtk_dsi_irq,
IRQF_TRIGGER_LOW, dev_name(&pdev->dev), dsi);
if (ret) {
dev_err(&pdev->dev, "failed to request mediatek dsi irq\n");
return -EPROBE_DEFER;
}
init_waitqueue_head(&dsi->irq_wait_queue);
platform_set_drvdata(pdev, dsi);
return component_add(&pdev->dev, &mtk_dsi_component_ops);
}
static int mtk_dsi_remove(struct platform_device *pdev)
{
struct mtk_dsi *dsi = platform_get_drvdata(pdev);
mtk_output_dsi_disable(dsi);
component_del(&pdev->dev, &mtk_dsi_component_ops);
return 0;
}
