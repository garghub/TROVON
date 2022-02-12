int mdfld_dsi_dbi_update_area(struct mdfld_dsi_dbi_output *dbi_output,
u16 x1, u16 y1, u16 x2, u16 y2)
{
struct mdfld_dsi_pkg_sender *sender =
mdfld_dsi_encoder_get_pkg_sender(&dbi_output->base);
u8 param[4];
u8 cmd;
int err;
if (!sender) {
WARN_ON(1);
return -EINVAL;
}
cmd = DCS_SET_COLUMN_ADDRESS;
param[0] = x1 >> 8;
param[1] = x1;
param[2] = x2 >> 8;
param[3] = x2;
err = mdfld_dsi_send_dcs(sender,
cmd,
param,
4,
CMD_DATA_SRC_SYSTEM_MEM,
MDFLD_DSI_QUEUE_PACKAGE);
if (err) {
dev_err(sender->dev->dev, "DCS 0x%x sent failed\n", cmd);
goto err_out;
}
cmd = DCS_SET_PAGE_ADDRESS;
param[0] = y1 >> 8;
param[1] = y1;
param[2] = y2 >> 8;
param[3] = y2;
err = mdfld_dsi_send_dcs(sender,
cmd,
param,
4,
CMD_DATA_SRC_SYSTEM_MEM,
MDFLD_DSI_QUEUE_PACKAGE);
if (err) {
dev_err(sender->dev->dev, "DCS 0x%x sent failed\n", cmd);
goto err_out;
}
err = mdfld_dsi_send_dcs(sender,
write_mem_start,
NULL,
0,
CMD_DATA_SRC_PIPE,
MDFLD_DSI_QUEUE_PACKAGE);
if (err) {
dev_err(sender->dev->dev, "DCS 0x%x sent failed\n", cmd);
goto err_out;
}
mdfld_dsi_cmds_kick_out(sender);
err_out:
return err;
}
int mdfld_dsi_dbi_update_power(struct mdfld_dsi_dbi_output *dbi_output,
int mode)
{
struct drm_device *dev = dbi_output->dev;
struct mdfld_dsi_pkg_sender *sender =
mdfld_dsi_encoder_get_pkg_sender(&dbi_output->base);
u8 param = 0;
u32 err = 0;
if (!sender) {
WARN_ON(1);
return -EINVAL;
}
if (mode == DRM_MODE_DPMS_ON) {
err = mdfld_dsi_send_dcs(sender,
DCS_EXIT_SLEEP_MODE,
NULL,
0,
CMD_DATA_SRC_SYSTEM_MEM,
MDFLD_DSI_QUEUE_PACKAGE);
if (err) {
dev_err(dev->dev, "DCS 0x%x sent failed\n",
DCS_EXIT_SLEEP_MODE);
goto power_err;
}
err = mdfld_dsi_send_dcs(sender,
DCS_SET_DISPLAY_ON,
NULL,
0,
CMD_DATA_SRC_SYSTEM_MEM,
MDFLD_DSI_QUEUE_PACKAGE);
if (err) {
dev_err(dev->dev, "DCS 0x%x sent failed\n",
DCS_SET_DISPLAY_ON);
goto power_err;
}
err = mdfld_dsi_send_dcs(sender,
DCS_SET_TEAR_ON,
&param,
1,
CMD_DATA_SRC_SYSTEM_MEM,
MDFLD_DSI_QUEUE_PACKAGE);
if (err) {
dev_err(dev->dev, "DCS 0x%x sent failed\n",
set_tear_on);
goto power_err;
}
err = mdfld_dsi_send_dcs(sender,
DCS_WRITE_MEM_START,
NULL,
0,
CMD_DATA_SRC_PIPE,
MDFLD_DSI_QUEUE_PACKAGE);
if (err) {
dev_err(dev->dev, "DCS 0x%x sent failed\n",
DCS_WRITE_MEM_START);
goto power_err;
}
} else {
err = mdfld_dsi_send_dcs(sender,
DCS_SET_TEAR_OFF,
NULL,
0,
CMD_DATA_SRC_SYSTEM_MEM,
MDFLD_DSI_QUEUE_PACKAGE);
if (err) {
dev_err(dev->dev, "DCS 0x%x sent failed\n",
DCS_SET_TEAR_OFF);
goto power_err;
}
err = mdfld_dsi_send_dcs(sender,
DCS_SET_DISPLAY_OFF,
NULL,
0,
CMD_DATA_SRC_SYSTEM_MEM,
MDFLD_DSI_QUEUE_PACKAGE);
if (err) {
dev_err(dev->dev, "DCS 0x%x sent failed\n",
DCS_SET_DISPLAY_OFF);
goto power_err;
}
err = mdfld_dsi_send_dcs(sender,
DCS_ENTER_SLEEP_MODE,
NULL,
0,
CMD_DATA_SRC_SYSTEM_MEM,
MDFLD_DSI_QUEUE_PACKAGE);
if (err) {
dev_err(dev->dev, "DCS 0x%x sent failed\n",
DCS_ENTER_SLEEP_MODE);
goto power_err;
}
}
mdfld_dsi_cmds_kick_out(sender);
power_err:
return err;
}
int mdfld_dsi_dbi_send_dcs(struct mdfld_dsi_dbi_output *dbi_output,
u8 dcs, u8 *param, u32 num, u8 data_src)
{
struct mdfld_dsi_pkg_sender *sender =
mdfld_dsi_encoder_get_pkg_sender(&dbi_output->base);
int ret;
if (!sender) {
WARN_ON(1);
return -EINVAL;
}
ret = mdfld_dsi_send_dcs(sender,
dcs,
param,
num,
data_src,
MDFLD_DSI_SEND_PACKAGE);
return ret;
}
void mdfld_dsi_dbi_enter_dsr(struct mdfld_dsi_dbi_output *dbi_output, int pipe)
{
u32 reg_val;
struct drm_device *dev = dbi_output->dev;
struct drm_psb_private *dev_priv = dev->dev_private;
struct drm_crtc *crtc = dbi_output->base.base.crtc;
struct psb_intel_crtc *psb_crtc = (crtc) ?
to_psb_intel_crtc(crtc) : NULL;
u32 dpll_reg = MRST_DPLL_A;
u32 pipeconf_reg = PIPEACONF;
u32 dspcntr_reg = DSPACNTR;
if (!dbi_output)
return;
dev_priv->is_in_idle = true;
gdbi_output = dbi_output;
if ((dbi_output->mode_flags & MODE_SETTING_ON_GOING) ||
(psb_crtc && psb_crtc->mode_flags & MODE_SETTING_ON_GOING))
return;
if (pipe == 2) {
dpll_reg = MRST_DPLL_A;
pipeconf_reg = PIPECCONF;
dspcntr_reg = DSPCCNTR;
}
if (!gma_power_begin(dev, true)) {
dev_err(dev->dev, "hw begin failed\n");
return;
}
mdfld_disable_te(dev, pipe);
reg_val = REG_READ(dspcntr_reg);
if (!(reg_val & DISPLAY_PLANE_ENABLE)) {
REG_WRITE(dspcntr_reg, reg_val & ~DISPLAY_PLANE_ENABLE);
REG_READ(dspcntr_reg);
}
reg_val = REG_READ(pipeconf_reg);
if (!(reg_val & DISPLAY_PLANE_ENABLE)) {
reg_val &= ~DISPLAY_PLANE_ENABLE;
reg_val |= (PIPECONF_PLANE_OFF | PIPECONF_CURSOR_OFF);
REG_WRITE(pipeconf_reg, reg_val);
REG_READ(pipeconf_reg);
mdfldWaitForPipeDisable(dev, pipe);
}
reg_val = REG_READ(dpll_reg);
if (!(reg_val & DPLL_VCO_ENABLE)) {
reg_val &= ~DPLL_VCO_ENABLE;
REG_WRITE(dpll_reg, reg_val);
REG_READ(dpll_reg);
udelay(500);
}
gma_power_end(dev);
dbi_output->mode_flags |= MODE_SETTING_IN_DSR;
if (pipe == 2) {
enter_dsr = 1;
}
}
static void mdfld_dbi_output_exit_dsr(struct mdfld_dsi_dbi_output *dbi_output,
int pipe)
{
struct drm_device *dev = dbi_output->dev;
struct drm_crtc *crtc = dbi_output->base.base.crtc;
struct psb_intel_crtc *psb_crtc = (crtc) ?
to_psb_intel_crtc(crtc) : NULL;
u32 reg_val;
u32 dpll_reg = MRST_DPLL_A;
u32 pipeconf_reg = PIPEACONF;
u32 dspcntr_reg = DSPACNTR;
u32 reg_offset = 0;
if ((dbi_output->mode_flags & MODE_SETTING_ON_GOING) ||
(psb_crtc && psb_crtc->mode_flags & MODE_SETTING_ON_GOING))
return;
if (pipe == 2) {
dpll_reg = MRST_DPLL_A;
pipeconf_reg = PIPECCONF;
dspcntr_reg = DSPCCNTR;
reg_offset = MIPIC_REG_OFFSET;
}
if (!gma_power_begin(dev, true)) {
dev_err(dev->dev, "hw begin failed\n");
return;
}
reg_val = REG_READ(dpll_reg);
if (!(reg_val & DPLL_VCO_ENABLE)) {
if (reg_val & MDFLD_PWR_GATE_EN) {
reg_val &= ~MDFLD_PWR_GATE_EN;
REG_WRITE(dpll_reg, reg_val);
REG_READ(dpll_reg);
udelay(500);
}
reg_val |= DPLL_VCO_ENABLE;
REG_WRITE(dpll_reg, reg_val);
REG_READ(dpll_reg);
udelay(500);
while (!(REG_READ(pipeconf_reg) & PIPECONF_DSIPLL_LOCK))
cpu_relax();
}
reg_val = REG_READ(pipeconf_reg);
if (!(reg_val & PIPEACONF_ENABLE)) {
reg_val |= PIPEACONF_ENABLE;
REG_WRITE(pipeconf_reg, reg_val);
REG_READ(pipeconf_reg);
udelay(500);
mdfldWaitForPipeEnable(dev, pipe);
}
reg_val = REG_READ(dspcntr_reg);
if (!(reg_val & DISPLAY_PLANE_ENABLE)) {
reg_val |= DISPLAY_PLANE_ENABLE;
REG_WRITE(dspcntr_reg, reg_val);
REG_READ(dspcntr_reg);
udelay(500);
}
mdfld_enable_te(dev, pipe);
gma_power_end(dev);
dbi_output->mode_flags &= ~MODE_SETTING_IN_DSR;
}
void mdfld_dsi_dbi_exit_dsr(struct drm_device *dev, u32 update_src)
{
struct drm_psb_private *dev_priv = dev->dev_private;
struct mdfld_dbi_dsr_info *dsr_info = dev_priv->dbi_dsr_info;
struct mdfld_dsi_dbi_output **dbi_output;
int i;
int pipe;
dev_priv->is_in_idle = false;
dbi_output = dsr_info->dbi_outputs;
#ifdef CONFIG_PM_RUNTIME
if (!enable_gfx_rtpm) {
}
#endif
for (i = 0; i < dsr_info->dbi_output_num; i++) {
if (!dbi_output[i] || !dbi_output[i]->dbi_panel_on)
continue;
pipe = dbi_output[i]->channel_num ? 2 : 0;
enter_dsr = 0;
mdfld_dbi_output_exit_dsr(dbi_output[i], pipe);
}
dev_priv->dsr_fb_update |= update_src;
}
static bool mdfld_dbi_is_in_dsr(struct drm_device *dev)
{
if (REG_READ(MRST_DPLL_A) & DPLL_VCO_ENABLE)
return false;
if ((REG_READ(PIPEACONF) & PIPEACONF_ENABLE) ||
(REG_READ(PIPECCONF) & PIPEACONF_ENABLE))
return false;
if ((REG_READ(DSPACNTR) & DISPLAY_PLANE_ENABLE) ||
(REG_READ(DSPCCNTR) & DISPLAY_PLANE_ENABLE))
return false;
return true;
}
void mdfld_dbi_update_panel(struct drm_device *dev, int pipe)
{
struct drm_psb_private *dev_priv = dev->dev_private;
struct mdfld_dbi_dsr_info *dsr_info = dev_priv->dbi_dsr_info;
struct mdfld_dsi_dbi_output **dbi_outputs;
struct mdfld_dsi_dbi_output *dbi_output;
int i;
int can_enter_dsr = 0;
u32 damage_mask;
dbi_outputs = dsr_info->dbi_outputs;
dbi_output = pipe ? dbi_outputs[1] : dbi_outputs[0];
if (!dbi_output)
return;
if (pipe == 0)
damage_mask = dev_priv->dsr_fb_update & MDFLD_DSR_DAMAGE_MASK_0;
else if (pipe == 2)
damage_mask = dev_priv->dsr_fb_update & MDFLD_DSR_DAMAGE_MASK_2;
else
return;
if (damage_mask && dbi_output->dbi_panel_on) {
dbi_output->dsr_fb_update_done = false;
if (dbi_output->p_funcs->update_fb)
dbi_output->p_funcs->update_fb(dbi_output, pipe);
if (dev_priv->dsr_enable && dbi_output->dsr_fb_update_done)
dev_priv->dsr_fb_update &= ~damage_mask;
dbi_output->mode_flags &= ~MODE_SETTING_IN_DSR;
dbi_output->dsr_idle_count = 0;
} else {
dbi_output->dsr_idle_count++;
}
switch (dsr_info->dbi_output_num) {
case 1:
if (dbi_output->dsr_idle_count > MDFLD_DSR_MAX_IDLE_COUNT)
can_enter_dsr = 1;
break;
case 2:
if (dbi_outputs[0]->dsr_idle_count > MDFLD_DSR_MAX_IDLE_COUNT
&& dbi_outputs[1]->dsr_idle_count > MDFLD_DSR_MAX_IDLE_COUNT)
can_enter_dsr = 1;
break;
default:
DRM_ERROR("Wrong DBI output number\n");
}
if (can_enter_dsr) {
for (i = 0; i < dsr_info->dbi_output_num; i++) {
if (!mdfld_dbi_is_in_dsr(dev) && dbi_outputs[i] &&
!(dbi_outputs[i]->mode_flags & MODE_SETTING_ON_GOING)) {
mdfld_dsi_dbi_enter_dsr(dbi_outputs[i],
dbi_outputs[i]->channel_num ? 2 : 0);
#if 0
enter_dsr = 1;
pr_err("%s: enter_dsr = 1\n", __func__);
#endif
}
}
#ifdef CONFIG_GFX_RTPM
if (!dev_priv->rpm_enabled
|| !enter_dsr
|| pm_schedule_suspend(&dev->pdev->dev, gfxrtdelay))
dev_warn(dev->dev,
"Runtime PM schedule suspend failed, rpm %d\n",
dev_priv->rpm_enabled);
#endif
}
}
int mdfld_dbi_dsr_init(struct drm_device *dev)
{
struct drm_psb_private *dev_priv = dev->dev_private;
struct mdfld_dbi_dsr_info *dsr_info = dev_priv->dbi_dsr_info;
if (!dsr_info || IS_ERR(dsr_info)) {
dsr_info = kzalloc(sizeof(struct mdfld_dbi_dsr_info),
GFP_KERNEL);
if (!dsr_info) {
dev_err(dev->dev, "No memory\n");
return -ENOMEM;
}
dev_priv->dbi_dsr_info = dsr_info;
}
return 0;
}
void mdfld_dbi_dsr_exit(struct drm_device *dev)
{
struct drm_psb_private *dev_priv = dev->dev_private;
struct mdfld_dbi_dsr_info *dsr_info = dev_priv->dbi_dsr_info;
if (dsr_info) {
kfree(dsr_info);
dev_priv->dbi_dsr_info = NULL;
}
}
void mdfld_dsi_controller_dbi_init(struct mdfld_dsi_config *dsi_config,
int pipe)
{
struct drm_device *dev = dsi_config->dev;
u32 reg_offset = pipe ? MIPIC_REG_OFFSET : 0;
int lane_count = dsi_config->lane_count;
u32 val = 0;
dev_dbg(dev->dev, "Init DBI interface on pipe %d...\n", pipe);
REG_WRITE((MIPIA_DEVICE_READY_REG + reg_offset), 0x00000000);
REG_WRITE((MIPIA_CONTROL_REG + reg_offset), 0x00000018);
REG_WRITE((MIPIA_DPHY_PARAM_REG + reg_offset), 0x150c3408);
REG_WRITE((MIPIA_CLK_LANE_SWITCH_TIME_CNT_REG + reg_offset),
0x000a0014);
REG_WRITE((MIPIA_DBI_BW_CTRL_REG + reg_offset), 0x00000400);
REG_WRITE((MIPIA_DBI_FIFO_THROTTLE_REG + reg_offset), 0x00000001);
REG_WRITE((MIPIA_HS_LS_DBI_ENABLE_REG + reg_offset), 0x00000000);
REG_WRITE((MIPIA_INTR_EN_REG + reg_offset), 0xffffffff);
REG_WRITE((MIPIA_TURN_AROUND_TIMEOUT_REG + reg_offset), 0x0000001f);
REG_WRITE((MIPIA_DEVICE_RESET_TIMER_REG + reg_offset), 0x0000ffff);
REG_WRITE((MIPIA_INIT_COUNT_REG + reg_offset), 0x00000fa0);
val |= lane_count;
val |= (dsi_config->channel_num << DSI_DBI_VIRT_CHANNEL_OFFSET);
val |= DSI_DBI_COLOR_FORMAT_OPTION2;
REG_WRITE((MIPIA_DSI_FUNC_PRG_REG + reg_offset), val);
REG_WRITE((MIPIA_HS_TX_TIMEOUT_REG + reg_offset), 0x3fffff);
REG_WRITE((MIPIA_LP_RX_TIMEOUT_REG + reg_offset), 0xffff);
REG_WRITE((MIPIA_HIGH_LOW_SWITCH_COUNT_REG + reg_offset), 0x46);
REG_WRITE((MIPIA_EOT_DISABLE_REG + reg_offset), 0x00000000);
REG_WRITE((MIPIA_LP_BYTECLK_REG + reg_offset), 0x00000004);
REG_WRITE((MIPIA_DEVICE_READY_REG + reg_offset), 0x00000001);
}
struct mdfld_dsi_encoder *mdfld_dsi_dbi_init(struct drm_device *dev,
struct mdfld_dsi_connector *dsi_connector,
struct panel_funcs *p_funcs)
{
struct drm_psb_private *dev_priv = dev->dev_private;
struct mdfld_dsi_dbi_output *dbi_output = NULL;
struct mdfld_dsi_config *dsi_config;
struct drm_connector *connector = NULL;
struct drm_encoder *encoder = NULL;
struct drm_display_mode *fixed_mode = NULL;
struct psb_gtt *pg = dev_priv ? (&dev_priv->gtt) : NULL;
struct mdfld_dbi_dpu_info *dpu_info = dev_priv ? (dev_priv->dbi_dpu_info) : NULL;
struct mdfld_dbi_dsr_info *dsr_info = dev_priv ? (dev_priv->dbi_dsr_info) : NULL;
u32 data = 0;
int pipe;
int ret;
if (!pg || !dsi_connector || !p_funcs) {
WARN_ON(1);
return NULL;
}
dsi_config = mdfld_dsi_get_config(dsi_connector);
pipe = dsi_connector->pipe;
if (p_funcs->reset) {
ret = p_funcs->reset(pipe);
if (ret) {
DRM_ERROR("Panel %d hard-reset failed\n", pipe);
return NULL;
}
}
if (p_funcs->drv_ic_init)
p_funcs->drv_ic_init(dsi_config, pipe);
ret = mdfld_dsi_get_power_mode(dsi_config,
&data,
MDFLD_DSI_HS_TRANSMISSION);
if (ret) {
DRM_ERROR("Panel %d get power mode failed\n", pipe);
dsi_connector->status = connector_status_disconnected;
} else {
DRM_INFO("pipe %d power mode 0x%x\n", pipe, data);
dsi_connector->status = connector_status_connected;
}
dbi_output = kzalloc(sizeof(struct mdfld_dsi_dbi_output), GFP_KERNEL);
if (!dbi_output) {
dev_err(dev->dev, "No memory\n");
return NULL;
}
if (dsi_connector->pipe == 0) {
dbi_output->channel_num = 0;
dev_priv->dbi_output = dbi_output;
} else if (dsi_connector->pipe == 2) {
dbi_output->channel_num = 1;
dev_priv->dbi_output2 = dbi_output;
} else {
dev_err(dev->dev, "only support 2 DSI outputs\n");
goto out_err1;
}
dbi_output->dev = dev;
dbi_output->p_funcs = p_funcs;
fixed_mode = dsi_config->fixed_mode;
dbi_output->panel_fixed_mode = fixed_mode;
connector = &dsi_connector->base.base;
encoder = &dbi_output->base.base;
drm_encoder_init(dev,
encoder,
p_funcs->encoder_funcs,
DRM_MODE_ENCODER_LVDS);
drm_encoder_helper_add(encoder, p_funcs->encoder_helper_funcs);
drm_mode_connector_attach_encoder(connector, encoder);
if (dsi_connector->pipe) {
encoder->possible_crtcs = (1 << 2);
encoder->possible_clones = (1 << 1);
} else {
encoder->possible_crtcs = (1 << 0);
encoder->possible_clones = (1 << 0);
}
dev_priv->dsr_fb_update = 0;
dev_priv->dsr_enable = false;
dev_priv->exit_idle = mdfld_dsi_dbi_exit_dsr;
dbi_output->first_boot = true;
dbi_output->mode_flags = MODE_SETTING_IN_ENCODER;
if (dpu_info && dsi_connector->status == connector_status_connected) {
if (dsi_connector->pipe == 0)
dpu_info->dbi_outputs[0] = dbi_output;
else
dpu_info->dbi_outputs[1] = dbi_output;
dpu_info->dbi_output_num++;
} else if (dsi_connector->status == connector_status_connected) {
if (dsi_connector->pipe == 0)
dsr_info->dbi_outputs[0] = dbi_output;
else
dsr_info->dbi_outputs[1] = dbi_output;
dsr_info->dbi_output_num++;
}
return &dbi_output->base;
out_err1:
kfree(dbi_output);
return NULL;
}
