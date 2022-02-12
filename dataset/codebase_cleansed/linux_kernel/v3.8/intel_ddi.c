static enum port intel_ddi_get_encoder_port(struct intel_encoder *intel_encoder)
{
struct drm_encoder *encoder = &intel_encoder->base;
int type = intel_encoder->type;
if (type == INTEL_OUTPUT_DISPLAYPORT || type == INTEL_OUTPUT_EDP ||
type == INTEL_OUTPUT_HDMI || type == INTEL_OUTPUT_UNKNOWN) {
struct intel_digital_port *intel_dig_port =
enc_to_dig_port(encoder);
return intel_dig_port->port;
} else if (type == INTEL_OUTPUT_ANALOG) {
return PORT_E;
} else {
DRM_ERROR("Invalid DDI encoder type %d\n", type);
BUG();
}
}
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
static void intel_wait_ddi_buf_idle(struct drm_i915_private *dev_priv,
enum port port)
{
uint32_t reg = DDI_BUF_CTL(port);
int i;
for (i = 0; i < 8; i++) {
udelay(1);
if (I915_READ(reg) & DDI_BUF_IS_IDLE)
return;
}
DRM_ERROR("Timeout waiting for DDI BUF %c idle bit\n", port_name(port));
}
void hsw_fdi_link_train(struct drm_crtc *crtc)
{
struct drm_device *dev = crtc->dev;
struct drm_i915_private *dev_priv = dev->dev_private;
struct intel_crtc *intel_crtc = to_intel_crtc(crtc);
u32 temp, i, rx_ctl_val;
I915_WRITE(_FDI_RXA_MISC, FDI_RX_PWRDN_LANE1_VAL(2) |
FDI_RX_PWRDN_LANE0_VAL(2) |
FDI_RX_TP1_TO_TP2_48 | FDI_RX_FDI_DELAY_90);
rx_ctl_val = FDI_RX_PLL_ENABLE | FDI_RX_ENHANCE_FRAME_ENABLE |
((intel_crtc->fdi_lanes - 1) << 19);
if (dev_priv->fdi_rx_polarity_reversed)
rx_ctl_val |= FDI_RX_POLARITY_REVERSED_LPT;
I915_WRITE(_FDI_RXA_CTL, rx_ctl_val);
POSTING_READ(_FDI_RXA_CTL);
udelay(220);
rx_ctl_val |= FDI_PCDCLK;
I915_WRITE(_FDI_RXA_CTL, rx_ctl_val);
I915_WRITE(PORT_CLK_SEL(PORT_E), intel_crtc->ddi_pll_sel);
for (i = 0; i < ARRAY_SIZE(hsw_ddi_buf_ctl_values) * 2; i++) {
I915_WRITE(DP_TP_CTL(PORT_E),
DP_TP_CTL_FDI_AUTOTRAIN |
DP_TP_CTL_ENHANCED_FRAME_ENABLE |
DP_TP_CTL_LINK_TRAIN_PAT1 |
DP_TP_CTL_ENABLE);
I915_WRITE(DDI_BUF_CTL(PORT_E),
DDI_BUF_CTL_ENABLE |
((intel_crtc->fdi_lanes - 1) << 1) |
hsw_ddi_buf_ctl_values[i / 2]);
POSTING_READ(DDI_BUF_CTL(PORT_E));
udelay(600);
I915_WRITE(_FDI_RXA_TUSIZE1, TU_SIZE(64));
rx_ctl_val |= FDI_RX_ENABLE | FDI_LINK_TRAIN_AUTO;
I915_WRITE(_FDI_RXA_CTL, rx_ctl_val);
POSTING_READ(_FDI_RXA_CTL);
udelay(30);
temp = I915_READ(_FDI_RXA_MISC);
temp &= ~(FDI_RX_PWRDN_LANE1_MASK | FDI_RX_PWRDN_LANE0_MASK);
I915_WRITE(_FDI_RXA_MISC, temp);
POSTING_READ(_FDI_RXA_MISC);
udelay(5);
temp = I915_READ(DP_TP_STATUS(PORT_E));
if (temp & DP_TP_STATUS_AUTOTRAIN_DONE) {
DRM_DEBUG_KMS("FDI link training done on step %d\n", i);
I915_WRITE(DP_TP_CTL(PORT_E),
DP_TP_CTL_FDI_AUTOTRAIN |
DP_TP_CTL_LINK_TRAIN_NORMAL |
DP_TP_CTL_ENHANCED_FRAME_ENABLE |
DP_TP_CTL_ENABLE);
return;
}
temp = I915_READ(DDI_BUF_CTL(PORT_E));
temp &= ~DDI_BUF_CTL_ENABLE;
I915_WRITE(DDI_BUF_CTL(PORT_E), temp);
POSTING_READ(DDI_BUF_CTL(PORT_E));
temp = I915_READ(DP_TP_CTL(PORT_E));
temp &= ~(DP_TP_CTL_ENABLE | DP_TP_CTL_LINK_TRAIN_MASK);
temp |= DP_TP_CTL_LINK_TRAIN_PAT1;
I915_WRITE(DP_TP_CTL(PORT_E), temp);
POSTING_READ(DP_TP_CTL(PORT_E));
intel_wait_ddi_buf_idle(dev_priv, PORT_E);
rx_ctl_val &= ~FDI_RX_ENABLE;
I915_WRITE(_FDI_RXA_CTL, rx_ctl_val);
POSTING_READ(_FDI_RXA_CTL);
temp = I915_READ(_FDI_RXA_MISC);
temp &= ~(FDI_RX_PWRDN_LANE1_MASK | FDI_RX_PWRDN_LANE0_MASK);
temp |= FDI_RX_PWRDN_LANE1_VAL(2) | FDI_RX_PWRDN_LANE0_VAL(2);
I915_WRITE(_FDI_RXA_MISC, temp);
POSTING_READ(_FDI_RXA_MISC);
}
DRM_ERROR("FDI link training failed!\n");
}
static void intel_ddi_mode_set(struct drm_encoder *encoder,
struct drm_display_mode *mode,
struct drm_display_mode *adjusted_mode)
{
struct drm_crtc *crtc = encoder->crtc;
struct intel_crtc *intel_crtc = to_intel_crtc(crtc);
struct intel_encoder *intel_encoder = to_intel_encoder(encoder);
int port = intel_ddi_get_encoder_port(intel_encoder);
int pipe = intel_crtc->pipe;
int type = intel_encoder->type;
DRM_DEBUG_KMS("Preparing DDI mode for Haswell on port %c, pipe %c\n",
port_name(port), pipe_name(pipe));
if (type == INTEL_OUTPUT_DISPLAYPORT || type == INTEL_OUTPUT_EDP) {
struct intel_dp *intel_dp = enc_to_intel_dp(encoder);
intel_dp->DP = DDI_BUF_CTL_ENABLE | DDI_BUF_EMP_400MV_0DB_HSW;
switch (intel_dp->lane_count) {
case 1:
intel_dp->DP |= DDI_PORT_WIDTH_X1;
break;
case 2:
intel_dp->DP |= DDI_PORT_WIDTH_X2;
break;
case 4:
intel_dp->DP |= DDI_PORT_WIDTH_X4;
break;
default:
intel_dp->DP |= DDI_PORT_WIDTH_X4;
WARN(1, "Unexpected DP lane count %d\n",
intel_dp->lane_count);
break;
}
if (intel_dp->has_audio) {
DRM_DEBUG_DRIVER("DP audio on pipe %c on DDI\n",
pipe_name(intel_crtc->pipe));
DRM_DEBUG_DRIVER("DP audio: write eld information\n");
intel_write_eld(encoder, adjusted_mode);
}
intel_dp_init_link_config(intel_dp);
} else if (type == INTEL_OUTPUT_HDMI) {
struct intel_hdmi *intel_hdmi = enc_to_intel_hdmi(encoder);
if (intel_hdmi->has_audio) {
DRM_DEBUG_DRIVER("HDMI audio on pipe %c on DDI\n",
pipe_name(intel_crtc->pipe));
DRM_DEBUG_DRIVER("HDMI audio: write eld information\n");
intel_write_eld(encoder, adjusted_mode);
}
intel_hdmi->set_infoframes(encoder, adjusted_mode);
}
}
static struct intel_encoder *
intel_ddi_get_crtc_encoder(struct drm_crtc *crtc)
{
struct drm_device *dev = crtc->dev;
struct intel_crtc *intel_crtc = to_intel_crtc(crtc);
struct intel_encoder *intel_encoder, *ret = NULL;
int num_encoders = 0;
for_each_encoder_on_crtc(dev, crtc, intel_encoder) {
ret = intel_encoder;
num_encoders++;
}
if (num_encoders != 1)
WARN(1, "%d encoders on crtc for pipe %d\n", num_encoders,
intel_crtc->pipe);
BUG_ON(ret == NULL);
return ret;
}
void intel_ddi_put_crtc_pll(struct drm_crtc *crtc)
{
struct drm_i915_private *dev_priv = crtc->dev->dev_private;
struct intel_ddi_plls *plls = &dev_priv->ddi_plls;
struct intel_crtc *intel_crtc = to_intel_crtc(crtc);
uint32_t val;
switch (intel_crtc->ddi_pll_sel) {
case PORT_CLK_SEL_SPLL:
plls->spll_refcount--;
if (plls->spll_refcount == 0) {
DRM_DEBUG_KMS("Disabling SPLL\n");
val = I915_READ(SPLL_CTL);
WARN_ON(!(val & SPLL_PLL_ENABLE));
I915_WRITE(SPLL_CTL, val & ~SPLL_PLL_ENABLE);
POSTING_READ(SPLL_CTL);
}
break;
case PORT_CLK_SEL_WRPLL1:
plls->wrpll1_refcount--;
if (plls->wrpll1_refcount == 0) {
DRM_DEBUG_KMS("Disabling WRPLL 1\n");
val = I915_READ(WRPLL_CTL1);
WARN_ON(!(val & WRPLL_PLL_ENABLE));
I915_WRITE(WRPLL_CTL1, val & ~WRPLL_PLL_ENABLE);
POSTING_READ(WRPLL_CTL1);
}
break;
case PORT_CLK_SEL_WRPLL2:
plls->wrpll2_refcount--;
if (plls->wrpll2_refcount == 0) {
DRM_DEBUG_KMS("Disabling WRPLL 2\n");
val = I915_READ(WRPLL_CTL2);
WARN_ON(!(val & WRPLL_PLL_ENABLE));
I915_WRITE(WRPLL_CTL2, val & ~WRPLL_PLL_ENABLE);
POSTING_READ(WRPLL_CTL2);
}
break;
}
WARN(plls->spll_refcount < 0, "Invalid SPLL refcount\n");
WARN(plls->wrpll1_refcount < 0, "Invalid WRPLL1 refcount\n");
WARN(plls->wrpll2_refcount < 0, "Invalid WRPLL2 refcount\n");
intel_crtc->ddi_pll_sel = PORT_CLK_SEL_NONE;
}
static void intel_ddi_calculate_wrpll(int clock, int *p, int *n2, int *r2)
{
u32 i;
for (i = 0; i < ARRAY_SIZE(wrpll_tmds_clock_table); i++)
if (clock <= wrpll_tmds_clock_table[i].clock)
break;
if (i == ARRAY_SIZE(wrpll_tmds_clock_table))
i--;
*p = wrpll_tmds_clock_table[i].p;
*n2 = wrpll_tmds_clock_table[i].n2;
*r2 = wrpll_tmds_clock_table[i].r2;
if (wrpll_tmds_clock_table[i].clock != clock)
DRM_INFO("WRPLL: using settings for %dKHz on %dKHz mode\n",
wrpll_tmds_clock_table[i].clock, clock);
DRM_DEBUG_KMS("WRPLL: %dKHz refresh rate with p=%d, n2=%d r2=%d\n",
clock, *p, *n2, *r2);
}
bool intel_ddi_pll_mode_set(struct drm_crtc *crtc, int clock)
{
struct intel_crtc *intel_crtc = to_intel_crtc(crtc);
struct intel_encoder *intel_encoder = intel_ddi_get_crtc_encoder(crtc);
struct drm_encoder *encoder = &intel_encoder->base;
struct drm_i915_private *dev_priv = crtc->dev->dev_private;
struct intel_ddi_plls *plls = &dev_priv->ddi_plls;
int type = intel_encoder->type;
enum pipe pipe = intel_crtc->pipe;
uint32_t reg, val;
intel_ddi_put_crtc_pll(crtc);
if (type == INTEL_OUTPUT_DISPLAYPORT || type == INTEL_OUTPUT_EDP) {
struct intel_dp *intel_dp = enc_to_intel_dp(encoder);
switch (intel_dp->link_bw) {
case DP_LINK_BW_1_62:
intel_crtc->ddi_pll_sel = PORT_CLK_SEL_LCPLL_810;
break;
case DP_LINK_BW_2_7:
intel_crtc->ddi_pll_sel = PORT_CLK_SEL_LCPLL_1350;
break;
case DP_LINK_BW_5_4:
intel_crtc->ddi_pll_sel = PORT_CLK_SEL_LCPLL_2700;
break;
default:
DRM_ERROR("Link bandwidth %d unsupported\n",
intel_dp->link_bw);
return false;
}
return true;
} else if (type == INTEL_OUTPUT_HDMI) {
int p, n2, r2;
if (plls->wrpll1_refcount == 0) {
DRM_DEBUG_KMS("Using WRPLL 1 on pipe %c\n",
pipe_name(pipe));
plls->wrpll1_refcount++;
reg = WRPLL_CTL1;
intel_crtc->ddi_pll_sel = PORT_CLK_SEL_WRPLL1;
} else if (plls->wrpll2_refcount == 0) {
DRM_DEBUG_KMS("Using WRPLL 2 on pipe %c\n",
pipe_name(pipe));
plls->wrpll2_refcount++;
reg = WRPLL_CTL2;
intel_crtc->ddi_pll_sel = PORT_CLK_SEL_WRPLL2;
} else {
DRM_ERROR("No WRPLLs available!\n");
return false;
}
WARN(I915_READ(reg) & WRPLL_PLL_ENABLE,
"WRPLL already enabled\n");
intel_ddi_calculate_wrpll(clock, &p, &n2, &r2);
val = WRPLL_PLL_ENABLE | WRPLL_PLL_SELECT_LCPLL_2700 |
WRPLL_DIVIDER_REFERENCE(r2) | WRPLL_DIVIDER_FEEDBACK(n2) |
WRPLL_DIVIDER_POST(p);
} else if (type == INTEL_OUTPUT_ANALOG) {
if (plls->spll_refcount == 0) {
DRM_DEBUG_KMS("Using SPLL on pipe %c\n",
pipe_name(pipe));
plls->spll_refcount++;
reg = SPLL_CTL;
intel_crtc->ddi_pll_sel = PORT_CLK_SEL_SPLL;
}
WARN(I915_READ(reg) & SPLL_PLL_ENABLE,
"SPLL already enabled\n");
val = SPLL_PLL_ENABLE | SPLL_PLL_FREQ_1350MHz | SPLL_PLL_SSC;
} else {
WARN(1, "Invalid DDI encoder type %d\n", type);
return false;
}
I915_WRITE(reg, val);
udelay(20);
return true;
}
void intel_ddi_set_pipe_settings(struct drm_crtc *crtc)
{
struct drm_i915_private *dev_priv = crtc->dev->dev_private;
struct intel_crtc *intel_crtc = to_intel_crtc(crtc);
struct intel_encoder *intel_encoder = intel_ddi_get_crtc_encoder(crtc);
enum transcoder cpu_transcoder = intel_crtc->cpu_transcoder;
int type = intel_encoder->type;
uint32_t temp;
if (type == INTEL_OUTPUT_DISPLAYPORT || type == INTEL_OUTPUT_EDP) {
temp = TRANS_MSA_SYNC_CLK;
switch (intel_crtc->bpp) {
case 18:
temp |= TRANS_MSA_6_BPC;
break;
case 24:
temp |= TRANS_MSA_8_BPC;
break;
case 30:
temp |= TRANS_MSA_10_BPC;
break;
case 36:
temp |= TRANS_MSA_12_BPC;
break;
default:
temp |= TRANS_MSA_8_BPC;
WARN(1, "%d bpp unsupported by DDI function\n",
intel_crtc->bpp);
}
I915_WRITE(TRANS_MSA_MISC(cpu_transcoder), temp);
}
}
void intel_ddi_enable_pipe_func(struct drm_crtc *crtc)
{
struct intel_crtc *intel_crtc = to_intel_crtc(crtc);
struct intel_encoder *intel_encoder = intel_ddi_get_crtc_encoder(crtc);
struct drm_encoder *encoder = &intel_encoder->base;
struct drm_i915_private *dev_priv = crtc->dev->dev_private;
enum pipe pipe = intel_crtc->pipe;
enum transcoder cpu_transcoder = intel_crtc->cpu_transcoder;
enum port port = intel_ddi_get_encoder_port(intel_encoder);
int type = intel_encoder->type;
uint32_t temp;
temp = TRANS_DDI_FUNC_ENABLE;
temp |= TRANS_DDI_SELECT_PORT(port);
switch (intel_crtc->bpp) {
case 18:
temp |= TRANS_DDI_BPC_6;
break;
case 24:
temp |= TRANS_DDI_BPC_8;
break;
case 30:
temp |= TRANS_DDI_BPC_10;
break;
case 36:
temp |= TRANS_DDI_BPC_12;
break;
default:
WARN(1, "%d bpp unsupported by transcoder DDI function\n",
intel_crtc->bpp);
}
if (crtc->mode.flags & DRM_MODE_FLAG_PVSYNC)
temp |= TRANS_DDI_PVSYNC;
if (crtc->mode.flags & DRM_MODE_FLAG_PHSYNC)
temp |= TRANS_DDI_PHSYNC;
if (cpu_transcoder == TRANSCODER_EDP) {
switch (pipe) {
case PIPE_A:
temp |= TRANS_DDI_EDP_INPUT_A_ONOFF;
break;
case PIPE_B:
temp |= TRANS_DDI_EDP_INPUT_B_ONOFF;
break;
case PIPE_C:
temp |= TRANS_DDI_EDP_INPUT_C_ONOFF;
break;
default:
BUG();
break;
}
}
if (type == INTEL_OUTPUT_HDMI) {
struct intel_hdmi *intel_hdmi = enc_to_intel_hdmi(encoder);
if (intel_hdmi->has_hdmi_sink)
temp |= TRANS_DDI_MODE_SELECT_HDMI;
else
temp |= TRANS_DDI_MODE_SELECT_DVI;
} else if (type == INTEL_OUTPUT_ANALOG) {
temp |= TRANS_DDI_MODE_SELECT_FDI;
temp |= (intel_crtc->fdi_lanes - 1) << 1;
} else if (type == INTEL_OUTPUT_DISPLAYPORT ||
type == INTEL_OUTPUT_EDP) {
struct intel_dp *intel_dp = enc_to_intel_dp(encoder);
temp |= TRANS_DDI_MODE_SELECT_DP_SST;
switch (intel_dp->lane_count) {
case 1:
temp |= TRANS_DDI_PORT_WIDTH_X1;
break;
case 2:
temp |= TRANS_DDI_PORT_WIDTH_X2;
break;
case 4:
temp |= TRANS_DDI_PORT_WIDTH_X4;
break;
default:
temp |= TRANS_DDI_PORT_WIDTH_X4;
WARN(1, "Unsupported lane count %d\n",
intel_dp->lane_count);
}
} else {
WARN(1, "Invalid encoder type %d for pipe %d\n",
intel_encoder->type, pipe);
}
I915_WRITE(TRANS_DDI_FUNC_CTL(cpu_transcoder), temp);
}
void intel_ddi_disable_transcoder_func(struct drm_i915_private *dev_priv,
enum transcoder cpu_transcoder)
{
uint32_t reg = TRANS_DDI_FUNC_CTL(cpu_transcoder);
uint32_t val = I915_READ(reg);
val &= ~(TRANS_DDI_FUNC_ENABLE | TRANS_DDI_PORT_MASK);
val |= TRANS_DDI_PORT_NONE;
I915_WRITE(reg, val);
}
bool intel_ddi_connector_get_hw_state(struct intel_connector *intel_connector)
{
struct drm_device *dev = intel_connector->base.dev;
struct drm_i915_private *dev_priv = dev->dev_private;
struct intel_encoder *intel_encoder = intel_connector->encoder;
int type = intel_connector->base.connector_type;
enum port port = intel_ddi_get_encoder_port(intel_encoder);
enum pipe pipe = 0;
enum transcoder cpu_transcoder;
uint32_t tmp;
if (!intel_encoder->get_hw_state(intel_encoder, &pipe))
return false;
if (port == PORT_A)
cpu_transcoder = TRANSCODER_EDP;
else
cpu_transcoder = pipe;
tmp = I915_READ(TRANS_DDI_FUNC_CTL(cpu_transcoder));
switch (tmp & TRANS_DDI_MODE_SELECT_MASK) {
case TRANS_DDI_MODE_SELECT_HDMI:
case TRANS_DDI_MODE_SELECT_DVI:
return (type == DRM_MODE_CONNECTOR_HDMIA);
case TRANS_DDI_MODE_SELECT_DP_SST:
if (type == DRM_MODE_CONNECTOR_eDP)
return true;
case TRANS_DDI_MODE_SELECT_DP_MST:
return (type == DRM_MODE_CONNECTOR_DisplayPort);
case TRANS_DDI_MODE_SELECT_FDI:
return (type == DRM_MODE_CONNECTOR_VGA);
default:
return false;
}
}
bool intel_ddi_get_hw_state(struct intel_encoder *encoder,
enum pipe *pipe)
{
struct drm_device *dev = encoder->base.dev;
struct drm_i915_private *dev_priv = dev->dev_private;
enum port port = intel_ddi_get_encoder_port(encoder);
u32 tmp;
int i;
tmp = I915_READ(DDI_BUF_CTL(port));
if (!(tmp & DDI_BUF_CTL_ENABLE))
return false;
if (port == PORT_A) {
tmp = I915_READ(TRANS_DDI_FUNC_CTL(TRANSCODER_EDP));
switch (tmp & TRANS_DDI_EDP_INPUT_MASK) {
case TRANS_DDI_EDP_INPUT_A_ON:
case TRANS_DDI_EDP_INPUT_A_ONOFF:
*pipe = PIPE_A;
break;
case TRANS_DDI_EDP_INPUT_B_ONOFF:
*pipe = PIPE_B;
break;
case TRANS_DDI_EDP_INPUT_C_ONOFF:
*pipe = PIPE_C;
break;
}
return true;
} else {
for (i = TRANSCODER_A; i <= TRANSCODER_C; i++) {
tmp = I915_READ(TRANS_DDI_FUNC_CTL(i));
if ((tmp & TRANS_DDI_PORT_MASK)
== TRANS_DDI_SELECT_PORT(port)) {
*pipe = i;
return true;
}
}
}
DRM_DEBUG_KMS("No pipe for ddi port %i found\n", port);
return true;
}
static uint32_t intel_ddi_get_crtc_pll(struct drm_i915_private *dev_priv,
enum pipe pipe)
{
uint32_t temp, ret;
enum port port;
enum transcoder cpu_transcoder = intel_pipe_to_cpu_transcoder(dev_priv,
pipe);
int i;
if (cpu_transcoder == TRANSCODER_EDP) {
port = PORT_A;
} else {
temp = I915_READ(TRANS_DDI_FUNC_CTL(cpu_transcoder));
temp &= TRANS_DDI_PORT_MASK;
for (i = PORT_B; i <= PORT_E; i++)
if (temp == TRANS_DDI_SELECT_PORT(i))
port = i;
}
ret = I915_READ(PORT_CLK_SEL(port));
DRM_DEBUG_KMS("Pipe %c connected to port %c using clock 0x%08x\n",
pipe_name(pipe), port_name(port), ret);
return ret;
}
void intel_ddi_setup_hw_pll_state(struct drm_device *dev)
{
struct drm_i915_private *dev_priv = dev->dev_private;
enum pipe pipe;
struct intel_crtc *intel_crtc;
for_each_pipe(pipe) {
intel_crtc =
to_intel_crtc(dev_priv->pipe_to_crtc_mapping[pipe]);
if (!intel_crtc->active)
continue;
intel_crtc->ddi_pll_sel = intel_ddi_get_crtc_pll(dev_priv,
pipe);
switch (intel_crtc->ddi_pll_sel) {
case PORT_CLK_SEL_SPLL:
dev_priv->ddi_plls.spll_refcount++;
break;
case PORT_CLK_SEL_WRPLL1:
dev_priv->ddi_plls.wrpll1_refcount++;
break;
case PORT_CLK_SEL_WRPLL2:
dev_priv->ddi_plls.wrpll2_refcount++;
break;
}
}
}
void intel_ddi_enable_pipe_clock(struct intel_crtc *intel_crtc)
{
struct drm_crtc *crtc = &intel_crtc->base;
struct drm_i915_private *dev_priv = crtc->dev->dev_private;
struct intel_encoder *intel_encoder = intel_ddi_get_crtc_encoder(crtc);
enum port port = intel_ddi_get_encoder_port(intel_encoder);
enum transcoder cpu_transcoder = intel_crtc->cpu_transcoder;
if (cpu_transcoder != TRANSCODER_EDP)
I915_WRITE(TRANS_CLK_SEL(cpu_transcoder),
TRANS_CLK_SEL_PORT(port));
}
void intel_ddi_disable_pipe_clock(struct intel_crtc *intel_crtc)
{
struct drm_i915_private *dev_priv = intel_crtc->base.dev->dev_private;
enum transcoder cpu_transcoder = intel_crtc->cpu_transcoder;
if (cpu_transcoder != TRANSCODER_EDP)
I915_WRITE(TRANS_CLK_SEL(cpu_transcoder),
TRANS_CLK_SEL_DISABLED);
}
static void intel_ddi_pre_enable(struct intel_encoder *intel_encoder)
{
struct drm_encoder *encoder = &intel_encoder->base;
struct drm_crtc *crtc = encoder->crtc;
struct drm_i915_private *dev_priv = encoder->dev->dev_private;
struct intel_crtc *intel_crtc = to_intel_crtc(crtc);
enum port port = intel_ddi_get_encoder_port(intel_encoder);
int type = intel_encoder->type;
if (type == INTEL_OUTPUT_EDP) {
struct intel_dp *intel_dp = enc_to_intel_dp(encoder);
ironlake_edp_panel_vdd_on(intel_dp);
ironlake_edp_panel_on(intel_dp);
ironlake_edp_panel_vdd_off(intel_dp, true);
}
WARN_ON(intel_crtc->ddi_pll_sel == PORT_CLK_SEL_NONE);
I915_WRITE(PORT_CLK_SEL(port), intel_crtc->ddi_pll_sel);
if (type == INTEL_OUTPUT_DISPLAYPORT || type == INTEL_OUTPUT_EDP) {
struct intel_dp *intel_dp = enc_to_intel_dp(encoder);
intel_dp_sink_dpms(intel_dp, DRM_MODE_DPMS_ON);
intel_dp_start_link_train(intel_dp);
intel_dp_complete_link_train(intel_dp);
}
}
static void intel_ddi_post_disable(struct intel_encoder *intel_encoder)
{
struct drm_encoder *encoder = &intel_encoder->base;
struct drm_i915_private *dev_priv = encoder->dev->dev_private;
enum port port = intel_ddi_get_encoder_port(intel_encoder);
int type = intel_encoder->type;
uint32_t val;
bool wait = false;
val = I915_READ(DDI_BUF_CTL(port));
if (val & DDI_BUF_CTL_ENABLE) {
val &= ~DDI_BUF_CTL_ENABLE;
I915_WRITE(DDI_BUF_CTL(port), val);
wait = true;
}
val = I915_READ(DP_TP_CTL(port));
val &= ~(DP_TP_CTL_ENABLE | DP_TP_CTL_LINK_TRAIN_MASK);
val |= DP_TP_CTL_LINK_TRAIN_PAT1;
I915_WRITE(DP_TP_CTL(port), val);
if (wait)
intel_wait_ddi_buf_idle(dev_priv, port);
if (type == INTEL_OUTPUT_EDP) {
struct intel_dp *intel_dp = enc_to_intel_dp(encoder);
ironlake_edp_panel_vdd_on(intel_dp);
ironlake_edp_panel_off(intel_dp);
}
I915_WRITE(PORT_CLK_SEL(port), PORT_CLK_SEL_NONE);
}
static void intel_enable_ddi(struct intel_encoder *intel_encoder)
{
struct drm_encoder *encoder = &intel_encoder->base;
struct drm_device *dev = encoder->dev;
struct drm_i915_private *dev_priv = dev->dev_private;
enum port port = intel_ddi_get_encoder_port(intel_encoder);
int type = intel_encoder->type;
if (type == INTEL_OUTPUT_HDMI) {
I915_WRITE(DDI_BUF_CTL(port), DDI_BUF_CTL_ENABLE);
} else if (type == INTEL_OUTPUT_EDP) {
struct intel_dp *intel_dp = enc_to_intel_dp(encoder);
ironlake_edp_backlight_on(intel_dp);
}
}
static void intel_disable_ddi(struct intel_encoder *intel_encoder)
{
struct drm_encoder *encoder = &intel_encoder->base;
int type = intel_encoder->type;
if (type == INTEL_OUTPUT_EDP) {
struct intel_dp *intel_dp = enc_to_intel_dp(encoder);
ironlake_edp_backlight_off(intel_dp);
}
}
int intel_ddi_get_cdclk_freq(struct drm_i915_private *dev_priv)
{
if (I915_READ(HSW_FUSE_STRAP) & HSW_CDCLK_LIMIT)
return 450;
else if ((I915_READ(LCPLL_CTL) & LCPLL_CLK_FREQ_MASK) ==
LCPLL_CLK_FREQ_450)
return 450;
else if (IS_ULT(dev_priv->dev))
return 338;
else
return 540;
}
void intel_ddi_pll_init(struct drm_device *dev)
{
struct drm_i915_private *dev_priv = dev->dev_private;
uint32_t val = I915_READ(LCPLL_CTL);
DRM_DEBUG_KMS("CDCLK running at %dMHz\n",
intel_ddi_get_cdclk_freq(dev_priv));
if (val & LCPLL_CD_SOURCE_FCLK)
DRM_ERROR("CDCLK source is not LCPLL\n");
if (val & LCPLL_PLL_DISABLE)
DRM_ERROR("LCPLL is disabled\n");
}
void intel_ddi_prepare_link_retrain(struct drm_encoder *encoder)
{
struct intel_digital_port *intel_dig_port = enc_to_dig_port(encoder);
struct intel_dp *intel_dp = &intel_dig_port->dp;
struct drm_i915_private *dev_priv = encoder->dev->dev_private;
enum port port = intel_dig_port->port;
bool wait;
uint32_t val;
if (I915_READ(DP_TP_CTL(port)) & DP_TP_CTL_ENABLE) {
val = I915_READ(DDI_BUF_CTL(port));
if (val & DDI_BUF_CTL_ENABLE) {
val &= ~DDI_BUF_CTL_ENABLE;
I915_WRITE(DDI_BUF_CTL(port), val);
wait = true;
}
val = I915_READ(DP_TP_CTL(port));
val &= ~(DP_TP_CTL_ENABLE | DP_TP_CTL_LINK_TRAIN_MASK);
val |= DP_TP_CTL_LINK_TRAIN_PAT1;
I915_WRITE(DP_TP_CTL(port), val);
POSTING_READ(DP_TP_CTL(port));
if (wait)
intel_wait_ddi_buf_idle(dev_priv, port);
}
val = DP_TP_CTL_ENABLE | DP_TP_CTL_MODE_SST |
DP_TP_CTL_LINK_TRAIN_PAT1 | DP_TP_CTL_SCRAMBLE_DISABLE;
if (intel_dp->link_configuration[1] & DP_LANE_COUNT_ENHANCED_FRAME_EN)
val |= DP_TP_CTL_ENHANCED_FRAME_ENABLE;
I915_WRITE(DP_TP_CTL(port), val);
POSTING_READ(DP_TP_CTL(port));
intel_dp->DP |= DDI_BUF_CTL_ENABLE;
I915_WRITE(DDI_BUF_CTL(port), intel_dp->DP);
POSTING_READ(DDI_BUF_CTL(port));
udelay(600);
}
void intel_ddi_fdi_disable(struct drm_crtc *crtc)
{
struct drm_i915_private *dev_priv = crtc->dev->dev_private;
struct intel_encoder *intel_encoder = intel_ddi_get_crtc_encoder(crtc);
uint32_t val;
intel_ddi_post_disable(intel_encoder);
val = I915_READ(_FDI_RXA_CTL);
val &= ~FDI_RX_ENABLE;
I915_WRITE(_FDI_RXA_CTL, val);
val = I915_READ(_FDI_RXA_MISC);
val &= ~(FDI_RX_PWRDN_LANE1_MASK | FDI_RX_PWRDN_LANE0_MASK);
val |= FDI_RX_PWRDN_LANE1_VAL(2) | FDI_RX_PWRDN_LANE0_VAL(2);
I915_WRITE(_FDI_RXA_MISC, val);
val = I915_READ(_FDI_RXA_CTL);
val &= ~FDI_PCDCLK;
I915_WRITE(_FDI_RXA_CTL, val);
val = I915_READ(_FDI_RXA_CTL);
val &= ~FDI_RX_PLL_ENABLE;
I915_WRITE(_FDI_RXA_CTL, val);
}
static void intel_ddi_hot_plug(struct intel_encoder *intel_encoder)
{
struct intel_dp *intel_dp = enc_to_intel_dp(&intel_encoder->base);
int type = intel_encoder->type;
if (type == INTEL_OUTPUT_DISPLAYPORT || type == INTEL_OUTPUT_EDP)
intel_dp_check_link_status(intel_dp);
}
static void intel_ddi_destroy(struct drm_encoder *encoder)
{
intel_dp_encoder_destroy(encoder);
}
static bool intel_ddi_mode_fixup(struct drm_encoder *encoder,
const struct drm_display_mode *mode,
struct drm_display_mode *adjusted_mode)
{
struct intel_encoder *intel_encoder = to_intel_encoder(encoder);
int type = intel_encoder->type;
WARN(type == INTEL_OUTPUT_UNKNOWN, "mode_fixup() on unknown output!\n");
if (type == INTEL_OUTPUT_HDMI)
return intel_hdmi_mode_fixup(encoder, mode, adjusted_mode);
else
return intel_dp_mode_fixup(encoder, mode, adjusted_mode);
}
void intel_ddi_init(struct drm_device *dev, enum port port)
{
struct intel_digital_port *intel_dig_port;
struct intel_encoder *intel_encoder;
struct drm_encoder *encoder;
struct intel_connector *hdmi_connector = NULL;
struct intel_connector *dp_connector = NULL;
intel_dig_port = kzalloc(sizeof(struct intel_digital_port), GFP_KERNEL);
if (!intel_dig_port)
return;
dp_connector = kzalloc(sizeof(struct intel_connector), GFP_KERNEL);
if (!dp_connector) {
kfree(intel_dig_port);
return;
}
if (port != PORT_A) {
hdmi_connector = kzalloc(sizeof(struct intel_connector),
GFP_KERNEL);
if (!hdmi_connector) {
kfree(dp_connector);
kfree(intel_dig_port);
return;
}
}
intel_encoder = &intel_dig_port->base;
encoder = &intel_encoder->base;
drm_encoder_init(dev, encoder, &intel_ddi_funcs,
DRM_MODE_ENCODER_TMDS);
drm_encoder_helper_add(encoder, &intel_ddi_helper_funcs);
intel_encoder->enable = intel_enable_ddi;
intel_encoder->pre_enable = intel_ddi_pre_enable;
intel_encoder->disable = intel_disable_ddi;
intel_encoder->post_disable = intel_ddi_post_disable;
intel_encoder->get_hw_state = intel_ddi_get_hw_state;
intel_dig_port->port = port;
if (hdmi_connector)
intel_dig_port->hdmi.sdvox_reg = DDI_BUF_CTL(port);
else
intel_dig_port->hdmi.sdvox_reg = 0;
intel_dig_port->dp.output_reg = DDI_BUF_CTL(port);
intel_encoder->type = INTEL_OUTPUT_UNKNOWN;
intel_encoder->crtc_mask = (1 << 0) | (1 << 1) | (1 << 2);
intel_encoder->cloneable = false;
intel_encoder->hot_plug = intel_ddi_hot_plug;
if (hdmi_connector)
intel_hdmi_init_connector(intel_dig_port, hdmi_connector);
intel_dp_init_connector(intel_dig_port, dp_connector);
}
