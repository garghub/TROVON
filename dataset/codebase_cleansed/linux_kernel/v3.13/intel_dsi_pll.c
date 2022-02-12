static u32 dsi_rr_formula(const struct drm_display_mode *mode,
int pixel_format, int video_mode_format,
int lane_count, bool eotp)
{
u32 bpp;
u32 hactive, vactive, hfp, hsync, hbp, vfp, vsync, vbp;
u32 hsync_bytes, hbp_bytes, hactive_bytes, hfp_bytes;
u32 bytes_per_line, bytes_per_frame;
u32 num_frames;
u32 bytes_per_x_frames, bytes_per_x_frames_x_lanes;
u32 dsi_bit_clock_hz;
u32 dsi_clk;
switch (pixel_format) {
default:
case VID_MODE_FORMAT_RGB888:
case VID_MODE_FORMAT_RGB666_LOOSE:
bpp = 24;
break;
case VID_MODE_FORMAT_RGB666:
bpp = 18;
break;
case VID_MODE_FORMAT_RGB565:
bpp = 16;
break;
}
hactive = mode->hdisplay;
vactive = mode->vdisplay;
hfp = mode->hsync_start - mode->hdisplay;
hsync = mode->hsync_end - mode->hsync_start;
hbp = mode->htotal - mode->hsync_end;
vfp = mode->vsync_start - mode->vdisplay;
vsync = mode->vsync_end - mode->vsync_start;
vbp = mode->vtotal - mode->vsync_end;
hsync_bytes = DIV_ROUND_UP(hsync * bpp, 8);
hbp_bytes = DIV_ROUND_UP(hbp * bpp, 8);
hactive_bytes = DIV_ROUND_UP(hactive * bpp, 8);
hfp_bytes = DIV_ROUND_UP(hfp * bpp, 8);
bytes_per_line = DSI_HSS_PACKET_SIZE + hsync_bytes +
DSI_HSA_PACKET_EXTRA_SIZE + DSI_HSE_PACKET_SIZE +
hbp_bytes + DSI_HBP_PACKET_EXTRA_SIZE +
hactive_bytes + DSI_HACTIVE_PACKET_EXTRA_SIZE +
hfp_bytes + DSI_HFP_PACKET_EXTRA_SIZE;
if (eotp && video_mode_format == VIDEO_MODE_BURST)
bytes_per_line += DSI_EOTP_PACKET_SIZE;
bytes_per_frame = vsync * bytes_per_line + vbp * bytes_per_line +
vactive * bytes_per_line + vfp * bytes_per_line;
if (eotp &&
(video_mode_format == VIDEO_MODE_NON_BURST_WITH_SYNC_PULSE ||
video_mode_format == VIDEO_MODE_NON_BURST_WITH_SYNC_EVENTS))
bytes_per_frame += DSI_EOTP_PACKET_SIZE;
num_frames = drm_mode_vrefresh(mode);
bytes_per_x_frames = num_frames * bytes_per_frame;
bytes_per_x_frames_x_lanes = bytes_per_x_frames / lane_count;
dsi_bit_clock_hz = bytes_per_x_frames_x_lanes * 8;
dsi_clk = dsi_bit_clock_hz / (1000 * 1000);
if (eotp && video_mode_format == VIDEO_MODE_BURST)
dsi_clk *= 2;
return dsi_clk;
}
static int dsi_calc_mnp(u32 dsi_clk, struct dsi_mnp *dsi_mnp)
{
unsigned int i;
u8 m;
u8 n;
u8 p;
u32 m_seed;
if (dsi_clk < 300 || dsi_clk > 1000)
return -ECHRNG;
for (i = 0; i <= ARRAY_SIZE(dsi_clk_tbl); i++) {
if (dsi_clk_tbl[i].freq > dsi_clk)
break;
}
m = dsi_clk_tbl[i].m;
p = dsi_clk_tbl[i].p;
m_seed = lfsr_converts[m - 62];
n = 1;
dsi_mnp->dsi_pll_ctrl = 1 << (DSI_PLL_P1_POST_DIV_SHIFT + p - 2);
dsi_mnp->dsi_pll_div = (n - 1) << DSI_PLL_N1_DIV_SHIFT |
m_seed << DSI_PLL_M1_DIV_SHIFT;
return 0;
}
static int dsi_calc_mnp(u32 dsi_clk, struct dsi_mnp *dsi_mnp)
{
u32 m, n, p;
u32 ref_clk;
u32 error;
u32 tmp_error;
u32 target_dsi_clk;
u32 calc_dsi_clk;
u32 calc_m;
u32 calc_p;
u32 m_seed;
if (dsi_clk < 300 || dsi_clk > 1150) {
DRM_ERROR("DSI CLK Out of Range\n");
return -ECHRNG;
}
ref_clk = 25000;
target_dsi_clk = dsi_clk * 1000;
error = 0xFFFFFFFF;
calc_m = 0;
calc_p = 0;
for (m = 62; m <= 92; m++) {
for (p = 2; p <= 6; p++) {
calc_dsi_clk = (m * ref_clk) / p;
if (calc_dsi_clk >= target_dsi_clk) {
tmp_error = calc_dsi_clk - target_dsi_clk;
if (tmp_error < error) {
error = tmp_error;
calc_m = m;
calc_p = p;
}
}
}
}
m_seed = lfsr_converts[calc_m - 62];
n = 1;
dsi_mnp->dsi_pll_ctrl = 1 << (DSI_PLL_P1_POST_DIV_SHIFT + calc_p - 2);
dsi_mnp->dsi_pll_div = (n - 1) << DSI_PLL_N1_DIV_SHIFT |
m_seed << DSI_PLL_M1_DIV_SHIFT;
return 0;
}
static void vlv_configure_dsi_pll(struct intel_encoder *encoder)
{
struct drm_i915_private *dev_priv = encoder->base.dev->dev_private;
struct intel_crtc *intel_crtc = to_intel_crtc(encoder->base.crtc);
const struct drm_display_mode *mode = &intel_crtc->config.adjusted_mode;
struct intel_dsi *intel_dsi = enc_to_intel_dsi(&encoder->base);
int ret;
struct dsi_mnp dsi_mnp;
u32 dsi_clk;
dsi_clk = dsi_rr_formula(mode, intel_dsi->pixel_format,
intel_dsi->video_mode_format,
intel_dsi->lane_count, !intel_dsi->eot_disable);
ret = dsi_calc_mnp(dsi_clk, &dsi_mnp);
if (ret) {
DRM_DEBUG_KMS("dsi_calc_mnp failed\n");
return;
}
dsi_mnp.dsi_pll_ctrl |= DSI_PLL_CLK_GATE_DSI0_DSIPLL;
DRM_DEBUG_KMS("dsi pll div %08x, ctrl %08x\n",
dsi_mnp.dsi_pll_div, dsi_mnp.dsi_pll_ctrl);
vlv_cck_write(dev_priv, CCK_REG_DSI_PLL_CONTROL, 0);
vlv_cck_write(dev_priv, CCK_REG_DSI_PLL_DIVIDER, dsi_mnp.dsi_pll_div);
vlv_cck_write(dev_priv, CCK_REG_DSI_PLL_CONTROL, dsi_mnp.dsi_pll_ctrl);
}
void vlv_enable_dsi_pll(struct intel_encoder *encoder)
{
struct drm_i915_private *dev_priv = encoder->base.dev->dev_private;
u32 tmp;
DRM_DEBUG_KMS("\n");
mutex_lock(&dev_priv->dpio_lock);
vlv_configure_dsi_pll(encoder);
usleep_range(1, 10);
tmp = vlv_cck_read(dev_priv, CCK_REG_DSI_PLL_CONTROL);
tmp |= DSI_PLL_VCO_EN;
vlv_cck_write(dev_priv, CCK_REG_DSI_PLL_CONTROL, tmp);
mutex_unlock(&dev_priv->dpio_lock);
if (wait_for(I915_READ(PIPECONF(PIPE_A)) & PIPECONF_DSI_PLL_LOCKED, 20)) {
DRM_ERROR("DSI PLL lock failed\n");
return;
}
DRM_DEBUG_KMS("DSI PLL locked\n");
}
void vlv_disable_dsi_pll(struct intel_encoder *encoder)
{
struct drm_i915_private *dev_priv = encoder->base.dev->dev_private;
u32 tmp;
DRM_DEBUG_KMS("\n");
mutex_lock(&dev_priv->dpio_lock);
tmp = vlv_cck_read(dev_priv, CCK_REG_DSI_PLL_CONTROL);
tmp &= ~DSI_PLL_VCO_EN;
tmp |= DSI_PLL_LDO_GATE;
vlv_cck_write(dev_priv, CCK_REG_DSI_PLL_CONTROL, tmp);
mutex_unlock(&dev_priv->dpio_lock);
}
