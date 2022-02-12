void intel_prepare_ddi_buffers(struct drm_device *dev, enum port port, bool use_fdi_mode)
{
struct drm_i915_private *dev_priv = dev->dev_private;
u32 reg;
int i;
const u32 *ddi_translations = ((use_fdi_mode) ?
hsw_ddi_translations_fdi :
hsw_ddi_translations_dp);
DRM_DEBUG_DRIVER("Initializing DDI buffers for port %c in %s mode\n",
port_name(port),
use_fdi_mode ? "FDI" : "DP");
WARN((use_fdi_mode && (port != PORT_E)),
"Programming port %c in FDI mode, this probably will not work.\n",
port_name(port));
for (i=0, reg=DDI_BUF_TRANS(port); i < ARRAY_SIZE(hsw_ddi_translations_fdi); i++) {
I915_WRITE(reg, ddi_translations[i]);
reg += 4;
}
}
void intel_prepare_ddi(struct drm_device *dev)
{
int port;
if (IS_HASWELL(dev)) {
for (port = PORT_A; port < PORT_E; port++)
intel_prepare_ddi_buffers(dev, port, false);
intel_prepare_ddi_buffers(dev, PORT_E, true);
}
}
void hsw_fdi_link_train(struct drm_crtc *crtc)
{
struct drm_device *dev = crtc->dev;
struct drm_i915_private *dev_priv = dev->dev_private;
struct intel_crtc *intel_crtc = to_intel_crtc(crtc);
int pipe = intel_crtc->pipe;
u32 reg, temp, i;
I915_WRITE(SPLL_CTL,
SPLL_PLL_ENABLE |
SPLL_PLL_FREQ_1350MHz |
SPLL_PLL_SCC);
I915_WRITE(PORT_CLK_SEL(PORT_E),
PORT_CLK_SEL_SPLL);
I915_WRITE(PIPE_CLK_SEL(pipe),
PIPE_CLK_SEL_PORT(PORT_E));
udelay(20);
for (i=0; i < ARRAY_SIZE(hsw_ddi_buf_ctl_values); i++) {
I915_WRITE(DP_TP_CTL(PORT_E),
DP_TP_CTL_FDI_AUTOTRAIN |
DP_TP_CTL_ENHANCED_FRAME_ENABLE |
DP_TP_CTL_LINK_TRAIN_PAT1 |
DP_TP_CTL_ENABLE);
temp = I915_READ(DDI_BUF_CTL(PORT_E));
temp = (temp & ~DDI_BUF_EMP_MASK);
I915_WRITE(DDI_BUF_CTL(PORT_E),
temp |
DDI_BUF_CTL_ENABLE |
DDI_PORT_WIDTH_X2 |
hsw_ddi_buf_ctl_values[i]);
udelay(600);
reg = FDI_RX_CTL(pipe);
I915_WRITE(reg,
I915_READ(reg) |
FDI_LINK_TRAIN_AUTO |
FDI_RX_ENABLE |
FDI_LINK_TRAIN_PATTERN_1_CPT |
FDI_RX_ENHANCE_FRAME_ENABLE |
FDI_PORT_WIDTH_2X_LPT |
FDI_RX_PLL_ENABLE);
POSTING_READ(reg);
udelay(100);
temp = I915_READ(DP_TP_STATUS(PORT_E));
if (temp & DP_TP_STATUS_AUTOTRAIN_DONE) {
DRM_DEBUG_DRIVER("BUF_CTL training done on %d step\n", i);
I915_WRITE(DP_TP_CTL(PORT_E),
DP_TP_CTL_FDI_AUTOTRAIN |
DP_TP_CTL_LINK_TRAIN_NORMAL |
DP_TP_CTL_ENHANCED_FRAME_ENABLE |
DP_TP_CTL_ENABLE);
temp = I915_READ(DDI_FUNC_CTL(pipe));
temp &= ~PIPE_DDI_PORT_MASK;
temp |= PIPE_DDI_SELECT_PORT(PORT_E) |
PIPE_DDI_MODE_SELECT_FDI |
PIPE_DDI_FUNC_ENABLE |
PIPE_DDI_PORT_WIDTH_X2;
I915_WRITE(DDI_FUNC_CTL(pipe),
temp);
break;
} else {
DRM_ERROR("Error training BUF_CTL %d\n", i);
I915_WRITE(DP_TP_CTL(PORT_E),
I915_READ(DP_TP_CTL(PORT_E)) &
~DP_TP_CTL_ENABLE);
I915_WRITE(FDI_RX_CTL(pipe),
I915_READ(FDI_RX_CTL(pipe)) &
~FDI_RX_PLL_ENABLE);
continue;
}
}
DRM_DEBUG_KMS("FDI train done.\n");
}
void intel_ddi_init(struct drm_device *dev, enum port port)
{
switch(port){
case PORT_A:
DRM_DEBUG_DRIVER("Found digital output on DDI port A\n");
break;
case PORT_B:
case PORT_C:
case PORT_D:
intel_hdmi_init(dev, DDI_BUF_CTL(port));
break;
default:
DRM_DEBUG_DRIVER("No handlers defined for port %d, skipping DDI initialization\n",
port);
break;
}
}
void intel_ddi_mode_set(struct drm_encoder *encoder,
struct drm_display_mode *mode,
struct drm_display_mode *adjusted_mode)
{
struct drm_device *dev = encoder->dev;
struct drm_i915_private *dev_priv = dev->dev_private;
struct drm_crtc *crtc = encoder->crtc;
struct intel_crtc *intel_crtc = to_intel_crtc(crtc);
struct intel_hdmi *intel_hdmi = enc_to_intel_hdmi(encoder);
int port = intel_hdmi->ddi_port;
int pipe = intel_crtc->pipe;
int p, n2, r2, valid=0;
u32 temp, i;
DRM_DEBUG_KMS("Preparing HDMI DDI mode for Haswell on port %c, pipe %c\n", port_name(port), pipe_name(pipe));
for (i=0; i < ARRAY_SIZE(wrpll_tmds_clock_table); i++) {
if (crtc->mode.clock == wrpll_tmds_clock_table[i].clock) {
p = wrpll_tmds_clock_table[i].p;
n2 = wrpll_tmds_clock_table[i].n2;
r2 = wrpll_tmds_clock_table[i].r2;
DRM_DEBUG_KMS("WR PLL clock: found settings for %dKHz refresh rate: p=%d, n2=%d, r2=%d\n",
crtc->mode.clock,
p, n2, r2);
valid = 1;
break;
}
}
if (!valid) {
DRM_ERROR("Unable to find WR PLL clock settings for %dKHz refresh rate\n",
crtc->mode.clock);
return;
}
temp = I915_READ(LCPLL_CTL);
if (temp & LCPLL_PLL_DISABLE)
I915_WRITE(LCPLL_CTL,
temp & ~LCPLL_PLL_DISABLE);
I915_WRITE(WRPLL_CTL1,
WRPLL_PLL_ENABLE |
WRPLL_PLL_SELECT_LCPLL_2700 |
WRPLL_DIVIDER_REFERENCE(r2) |
WRPLL_DIVIDER_FEEDBACK(n2) |
WRPLL_DIVIDER_POST(p));
udelay(20);
I915_WRITE(PORT_CLK_SEL(port),
PORT_CLK_SEL_WRPLL1);
I915_WRITE(PIPE_CLK_SEL(pipe),
PIPE_CLK_SEL_PORT(port));
udelay(20);
if (intel_hdmi->has_audio) {
DRM_DEBUG_DRIVER("HDMI audio on pipe %c not yet supported on DDI\n",
pipe_name(intel_crtc->pipe));
}
temp = I915_READ(DDI_FUNC_CTL(pipe));
temp &= ~PIPE_DDI_PORT_MASK;
temp &= ~PIPE_DDI_BPC_12;
temp |= PIPE_DDI_SELECT_PORT(port) |
PIPE_DDI_MODE_SELECT_HDMI |
((intel_crtc->bpp > 24) ?
PIPE_DDI_BPC_12 :
PIPE_DDI_BPC_8) |
PIPE_DDI_FUNC_ENABLE;
I915_WRITE(DDI_FUNC_CTL(pipe), temp);
intel_hdmi_set_avi_infoframe(encoder, adjusted_mode);
intel_hdmi_set_spd_infoframe(encoder);
}
void intel_ddi_dpms(struct drm_encoder *encoder, int mode)
{
struct drm_device *dev = encoder->dev;
struct drm_i915_private *dev_priv = dev->dev_private;
struct intel_hdmi *intel_hdmi = enc_to_intel_hdmi(encoder);
int port = intel_hdmi->ddi_port;
u32 temp;
temp = I915_READ(DDI_BUF_CTL(port));
if (mode != DRM_MODE_DPMS_ON) {
temp &= ~DDI_BUF_CTL_ENABLE;
} else {
temp |= DDI_BUF_CTL_ENABLE;
}
I915_WRITE(DDI_BUF_CTL(port),
temp);
}
