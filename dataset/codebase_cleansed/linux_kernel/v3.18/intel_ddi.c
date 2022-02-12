enum port intel_ddi_get_encoder_port(struct intel_encoder *intel_encoder)
{
struct drm_encoder *encoder = &intel_encoder->base;
int type = intel_encoder->type;
if (type == INTEL_OUTPUT_DP_MST) {
struct intel_digital_port *intel_dig_port = enc_to_mst(encoder)->primary;
return intel_dig_port->port;
} else if (type == INTEL_OUTPUT_DISPLAYPORT || type == INTEL_OUTPUT_EDP ||
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
static void intel_prepare_ddi_buffers(struct drm_device *dev, enum port port)
{
struct drm_i915_private *dev_priv = dev->dev_private;
u32 reg;
int i, n_hdmi_entries, hdmi_800mV_0dB;
int hdmi_level = dev_priv->vbt.ddi_port_info[port].hdmi_level_shift;
const struct ddi_buf_trans *ddi_translations_fdi;
const struct ddi_buf_trans *ddi_translations_dp;
const struct ddi_buf_trans *ddi_translations_edp;
const struct ddi_buf_trans *ddi_translations_hdmi;
const struct ddi_buf_trans *ddi_translations;
if (IS_BROADWELL(dev)) {
ddi_translations_fdi = bdw_ddi_translations_fdi;
ddi_translations_dp = bdw_ddi_translations_dp;
ddi_translations_edp = bdw_ddi_translations_edp;
ddi_translations_hdmi = bdw_ddi_translations_hdmi;
n_hdmi_entries = ARRAY_SIZE(bdw_ddi_translations_hdmi);
hdmi_800mV_0dB = 7;
} else if (IS_HASWELL(dev)) {
ddi_translations_fdi = hsw_ddi_translations_fdi;
ddi_translations_dp = hsw_ddi_translations_dp;
ddi_translations_edp = hsw_ddi_translations_dp;
ddi_translations_hdmi = hsw_ddi_translations_hdmi;
n_hdmi_entries = ARRAY_SIZE(hsw_ddi_translations_hdmi);
hdmi_800mV_0dB = 6;
} else {
WARN(1, "ddi translation table missing\n");
ddi_translations_edp = bdw_ddi_translations_dp;
ddi_translations_fdi = bdw_ddi_translations_fdi;
ddi_translations_dp = bdw_ddi_translations_dp;
ddi_translations_hdmi = bdw_ddi_translations_hdmi;
n_hdmi_entries = ARRAY_SIZE(bdw_ddi_translations_hdmi);
hdmi_800mV_0dB = 7;
}
switch (port) {
case PORT_A:
ddi_translations = ddi_translations_edp;
break;
case PORT_B:
case PORT_C:
ddi_translations = ddi_translations_dp;
break;
case PORT_D:
if (intel_dp_is_edp(dev, PORT_D))
ddi_translations = ddi_translations_edp;
else
ddi_translations = ddi_translations_dp;
break;
case PORT_E:
ddi_translations = ddi_translations_fdi;
break;
default:
BUG();
}
for (i = 0, reg = DDI_BUF_TRANS(port);
i < ARRAY_SIZE(hsw_ddi_translations_fdi); i++) {
I915_WRITE(reg, ddi_translations[i].trans1);
reg += 4;
I915_WRITE(reg, ddi_translations[i].trans2);
reg += 4;
}
if (hdmi_level == HDMI_LEVEL_SHIFT_UNKNOWN ||
hdmi_level >= n_hdmi_entries)
hdmi_level = hdmi_800mV_0dB;
I915_WRITE(reg, ddi_translations_hdmi[hdmi_level].trans1);
reg += 4;
I915_WRITE(reg, ddi_translations_hdmi[hdmi_level].trans2);
reg += 4;
}
void intel_prepare_ddi(struct drm_device *dev)
{
int port;
if (!HAS_DDI(dev))
return;
for (port = PORT_A; port <= PORT_E; port++)
intel_prepare_ddi_buffers(dev, port);
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
rx_ctl_val = dev_priv->fdi_rx_config | FDI_RX_ENHANCE_FRAME_ENABLE |
FDI_RX_PLL_ENABLE |
FDI_DP_PORT_WIDTH(intel_crtc->config.fdi_lanes);
I915_WRITE(_FDI_RXA_CTL, rx_ctl_val);
POSTING_READ(_FDI_RXA_CTL);
udelay(220);
rx_ctl_val |= FDI_PCDCLK;
I915_WRITE(_FDI_RXA_CTL, rx_ctl_val);
I915_WRITE(PORT_CLK_SEL(PORT_E), intel_crtc->config.ddi_pll_sel);
WARN_ON(intel_crtc->config.ddi_pll_sel != PORT_CLK_SEL_SPLL);
for (i = 0; i < ARRAY_SIZE(hsw_ddi_translations_fdi) * 2; i++) {
I915_WRITE(DP_TP_CTL(PORT_E),
DP_TP_CTL_FDI_AUTOTRAIN |
DP_TP_CTL_ENHANCED_FRAME_ENABLE |
DP_TP_CTL_LINK_TRAIN_PAT1 |
DP_TP_CTL_ENABLE);
I915_WRITE(DDI_BUF_CTL(PORT_E),
DDI_BUF_CTL_ENABLE |
((intel_crtc->config.fdi_lanes - 1) << 1) |
DDI_BUF_TRANS_SELECT(i / 2));
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
void intel_ddi_init_dp_buf_reg(struct intel_encoder *encoder)
{
struct intel_dp *intel_dp = enc_to_intel_dp(&encoder->base);
struct intel_digital_port *intel_dig_port =
enc_to_dig_port(&encoder->base);
intel_dp->DP = intel_dig_port->saved_port_bits |
DDI_BUF_CTL_ENABLE | DDI_BUF_TRANS_SELECT(0);
intel_dp->DP |= DDI_PORT_WIDTH(intel_dp->lane_count);
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
WARN(1, "%d encoders on crtc for pipe %c\n", num_encoders,
pipe_name(intel_crtc->pipe));
BUG_ON(ret == NULL);
return ret;
}
static unsigned wrpll_get_budget_for_freq(int clock)
{
unsigned budget;
switch (clock) {
case 25175000:
case 25200000:
case 27000000:
case 27027000:
case 37762500:
case 37800000:
case 40500000:
case 40541000:
case 54000000:
case 54054000:
case 59341000:
case 59400000:
case 72000000:
case 74176000:
case 74250000:
case 81000000:
case 81081000:
case 89012000:
case 89100000:
case 108000000:
case 108108000:
case 111264000:
case 111375000:
case 148352000:
case 148500000:
case 162000000:
case 162162000:
case 222525000:
case 222750000:
case 296703000:
case 297000000:
budget = 0;
break;
case 233500000:
case 245250000:
case 247750000:
case 253250000:
case 298000000:
budget = 1500;
break;
case 169128000:
case 169500000:
case 179500000:
case 202000000:
budget = 2000;
break;
case 256250000:
case 262500000:
case 270000000:
case 272500000:
case 273750000:
case 280750000:
case 281250000:
case 286000000:
case 291750000:
budget = 4000;
break;
case 267250000:
case 268500000:
budget = 5000;
break;
default:
budget = 1000;
break;
}
return budget;
}
static void wrpll_update_rnp(uint64_t freq2k, unsigned budget,
unsigned r2, unsigned n2, unsigned p,
struct wrpll_rnp *best)
{
uint64_t a, b, c, d, diff, diff_best;
if (best->p == 0) {
best->p = p;
best->n2 = n2;
best->r2 = r2;
return;
}
a = freq2k * budget * p * r2;
b = freq2k * budget * best->p * best->r2;
diff = abs_diff(freq2k * p * r2, LC_FREQ_2K * n2);
diff_best = abs_diff(freq2k * best->p * best->r2,
LC_FREQ_2K * best->n2);
c = 1000000 * diff;
d = 1000000 * diff_best;
if (a < c && b < d) {
if (best->p * best->r2 * diff < p * r2 * diff_best) {
best->p = p;
best->n2 = n2;
best->r2 = r2;
}
} else if (a >= c && b < d) {
best->p = p;
best->n2 = n2;
best->r2 = r2;
} else if (a >= c && b >= d) {
if (n2 * best->r2 * best->r2 > best->n2 * r2 * r2) {
best->p = p;
best->n2 = n2;
best->r2 = r2;
}
}
}
static int intel_ddi_calc_wrpll_link(struct drm_i915_private *dev_priv,
int reg)
{
int refclk = LC_FREQ;
int n, p, r;
u32 wrpll;
wrpll = I915_READ(reg);
switch (wrpll & WRPLL_PLL_REF_MASK) {
case WRPLL_PLL_SSC:
case WRPLL_PLL_NON_SSC:
refclk = 135;
break;
case WRPLL_PLL_LCPLL:
refclk = LC_FREQ;
break;
default:
WARN(1, "bad wrpll refclk\n");
return 0;
}
r = wrpll & WRPLL_DIVIDER_REF_MASK;
p = (wrpll & WRPLL_DIVIDER_POST_MASK) >> WRPLL_DIVIDER_POST_SHIFT;
n = (wrpll & WRPLL_DIVIDER_FB_MASK) >> WRPLL_DIVIDER_FB_SHIFT;
return (refclk * n * 100) / (p * r);
}
static void hsw_ddi_clock_get(struct intel_encoder *encoder,
struct intel_crtc_config *pipe_config)
{
struct drm_i915_private *dev_priv = encoder->base.dev->dev_private;
int link_clock = 0;
u32 val, pll;
val = pipe_config->ddi_pll_sel;
switch (val & PORT_CLK_SEL_MASK) {
case PORT_CLK_SEL_LCPLL_810:
link_clock = 81000;
break;
case PORT_CLK_SEL_LCPLL_1350:
link_clock = 135000;
break;
case PORT_CLK_SEL_LCPLL_2700:
link_clock = 270000;
break;
case PORT_CLK_SEL_WRPLL1:
link_clock = intel_ddi_calc_wrpll_link(dev_priv, WRPLL_CTL1);
break;
case PORT_CLK_SEL_WRPLL2:
link_clock = intel_ddi_calc_wrpll_link(dev_priv, WRPLL_CTL2);
break;
case PORT_CLK_SEL_SPLL:
pll = I915_READ(SPLL_CTL) & SPLL_PLL_FREQ_MASK;
if (pll == SPLL_PLL_FREQ_810MHz)
link_clock = 81000;
else if (pll == SPLL_PLL_FREQ_1350MHz)
link_clock = 135000;
else if (pll == SPLL_PLL_FREQ_2700MHz)
link_clock = 270000;
else {
WARN(1, "bad spll freq\n");
return;
}
break;
default:
WARN(1, "bad port clock sel\n");
return;
}
pipe_config->port_clock = link_clock * 2;
if (pipe_config->has_pch_encoder)
pipe_config->adjusted_mode.crtc_clock =
intel_dotclock_calculate(pipe_config->port_clock,
&pipe_config->fdi_m_n);
else if (pipe_config->has_dp_encoder)
pipe_config->adjusted_mode.crtc_clock =
intel_dotclock_calculate(pipe_config->port_clock,
&pipe_config->dp_m_n);
else
pipe_config->adjusted_mode.crtc_clock = pipe_config->port_clock;
}
void intel_ddi_clock_get(struct intel_encoder *encoder,
struct intel_crtc_config *pipe_config)
{
hsw_ddi_clock_get(encoder, pipe_config);
}
static void
hsw_ddi_calculate_wrpll(int clock ,
unsigned *r2_out, unsigned *n2_out, unsigned *p_out)
{
uint64_t freq2k;
unsigned p, n2, r2;
struct wrpll_rnp best = { 0, 0, 0 };
unsigned budget;
freq2k = clock / 100;
budget = wrpll_get_budget_for_freq(clock);
if (freq2k == 5400000) {
*n2_out = 2;
*p_out = 1;
*r2_out = 2;
return;
}
for (r2 = LC_FREQ * 2 / REF_MAX + 1;
r2 <= LC_FREQ * 2 / REF_MIN;
r2++) {
for (n2 = VCO_MIN * r2 / LC_FREQ + 1;
n2 <= VCO_MAX * r2 / LC_FREQ;
n2++) {
for (p = P_MIN; p <= P_MAX; p += P_INC)
wrpll_update_rnp(freq2k, budget,
r2, n2, p, &best);
}
}
*n2_out = best.n2;
*p_out = best.p;
*r2_out = best.r2;
}
static bool
hsw_ddi_pll_select(struct intel_crtc *intel_crtc,
struct intel_encoder *intel_encoder,
int clock)
{
if (intel_encoder->type == INTEL_OUTPUT_HDMI) {
struct intel_shared_dpll *pll;
uint32_t val;
unsigned p, n2, r2;
hsw_ddi_calculate_wrpll(clock * 1000, &r2, &n2, &p);
val = WRPLL_PLL_ENABLE | WRPLL_PLL_LCPLL |
WRPLL_DIVIDER_REFERENCE(r2) | WRPLL_DIVIDER_FEEDBACK(n2) |
WRPLL_DIVIDER_POST(p);
intel_crtc->config.dpll_hw_state.wrpll = val;
pll = intel_get_shared_dpll(intel_crtc);
if (pll == NULL) {
DRM_DEBUG_DRIVER("failed to find PLL for pipe %c\n",
pipe_name(intel_crtc->pipe));
return false;
}
intel_crtc->config.ddi_pll_sel = PORT_CLK_SEL_WRPLL(pll->id);
}
return true;
}
bool intel_ddi_pll_select(struct intel_crtc *intel_crtc)
{
struct drm_crtc *crtc = &intel_crtc->base;
struct intel_encoder *intel_encoder = intel_ddi_get_crtc_encoder(crtc);
int clock = intel_crtc->config.port_clock;
intel_put_shared_dpll(intel_crtc);
return hsw_ddi_pll_select(intel_crtc, intel_encoder, clock);
}
void intel_ddi_set_pipe_settings(struct drm_crtc *crtc)
{
struct drm_i915_private *dev_priv = crtc->dev->dev_private;
struct intel_crtc *intel_crtc = to_intel_crtc(crtc);
struct intel_encoder *intel_encoder = intel_ddi_get_crtc_encoder(crtc);
enum transcoder cpu_transcoder = intel_crtc->config.cpu_transcoder;
int type = intel_encoder->type;
uint32_t temp;
if (type == INTEL_OUTPUT_DISPLAYPORT || type == INTEL_OUTPUT_EDP || type == INTEL_OUTPUT_DP_MST) {
temp = TRANS_MSA_SYNC_CLK;
switch (intel_crtc->config.pipe_bpp) {
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
BUG();
}
I915_WRITE(TRANS_MSA_MISC(cpu_transcoder), temp);
}
}
void intel_ddi_set_vc_payload_alloc(struct drm_crtc *crtc, bool state)
{
struct intel_crtc *intel_crtc = to_intel_crtc(crtc);
struct drm_device *dev = crtc->dev;
struct drm_i915_private *dev_priv = dev->dev_private;
enum transcoder cpu_transcoder = intel_crtc->config.cpu_transcoder;
uint32_t temp;
temp = I915_READ(TRANS_DDI_FUNC_CTL(cpu_transcoder));
if (state == true)
temp |= TRANS_DDI_DP_VC_PAYLOAD_ALLOC;
else
temp &= ~TRANS_DDI_DP_VC_PAYLOAD_ALLOC;
I915_WRITE(TRANS_DDI_FUNC_CTL(cpu_transcoder), temp);
}
void intel_ddi_enable_transcoder_func(struct drm_crtc *crtc)
{
struct intel_crtc *intel_crtc = to_intel_crtc(crtc);
struct intel_encoder *intel_encoder = intel_ddi_get_crtc_encoder(crtc);
struct drm_encoder *encoder = &intel_encoder->base;
struct drm_device *dev = crtc->dev;
struct drm_i915_private *dev_priv = dev->dev_private;
enum pipe pipe = intel_crtc->pipe;
enum transcoder cpu_transcoder = intel_crtc->config.cpu_transcoder;
enum port port = intel_ddi_get_encoder_port(intel_encoder);
int type = intel_encoder->type;
uint32_t temp;
temp = TRANS_DDI_FUNC_ENABLE;
temp |= TRANS_DDI_SELECT_PORT(port);
switch (intel_crtc->config.pipe_bpp) {
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
BUG();
}
if (intel_crtc->config.adjusted_mode.flags & DRM_MODE_FLAG_PVSYNC)
temp |= TRANS_DDI_PVSYNC;
if (intel_crtc->config.adjusted_mode.flags & DRM_MODE_FLAG_PHSYNC)
temp |= TRANS_DDI_PHSYNC;
if (cpu_transcoder == TRANSCODER_EDP) {
switch (pipe) {
case PIPE_A:
if (IS_HASWELL(dev) &&
(intel_crtc->config.pch_pfit.enabled ||
intel_crtc->config.pch_pfit.force_thru))
temp |= TRANS_DDI_EDP_INPUT_A_ONOFF;
else
temp |= TRANS_DDI_EDP_INPUT_A_ON;
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
if (intel_crtc->config.has_hdmi_sink)
temp |= TRANS_DDI_MODE_SELECT_HDMI;
else
temp |= TRANS_DDI_MODE_SELECT_DVI;
} else if (type == INTEL_OUTPUT_ANALOG) {
temp |= TRANS_DDI_MODE_SELECT_FDI;
temp |= (intel_crtc->config.fdi_lanes - 1) << 1;
} else if (type == INTEL_OUTPUT_DISPLAYPORT ||
type == INTEL_OUTPUT_EDP) {
struct intel_dp *intel_dp = enc_to_intel_dp(encoder);
if (intel_dp->is_mst) {
temp |= TRANS_DDI_MODE_SELECT_DP_MST;
} else
temp |= TRANS_DDI_MODE_SELECT_DP_SST;
temp |= DDI_PORT_WIDTH(intel_dp->lane_count);
} else if (type == INTEL_OUTPUT_DP_MST) {
struct intel_dp *intel_dp = &enc_to_mst(encoder)->primary->dp;
if (intel_dp->is_mst) {
temp |= TRANS_DDI_MODE_SELECT_DP_MST;
} else
temp |= TRANS_DDI_MODE_SELECT_DP_SST;
temp |= DDI_PORT_WIDTH(intel_dp->lane_count);
} else {
WARN(1, "Invalid encoder type %d for pipe %c\n",
intel_encoder->type, pipe_name(pipe));
}
I915_WRITE(TRANS_DDI_FUNC_CTL(cpu_transcoder), temp);
}
void intel_ddi_disable_transcoder_func(struct drm_i915_private *dev_priv,
enum transcoder cpu_transcoder)
{
uint32_t reg = TRANS_DDI_FUNC_CTL(cpu_transcoder);
uint32_t val = I915_READ(reg);
val &= ~(TRANS_DDI_FUNC_ENABLE | TRANS_DDI_PORT_MASK | TRANS_DDI_DP_VC_PAYLOAD_ALLOC);
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
enum intel_display_power_domain power_domain;
uint32_t tmp;
power_domain = intel_display_port_power_domain(intel_encoder);
if (!intel_display_power_enabled(dev_priv, power_domain))
return false;
if (!intel_encoder->get_hw_state(intel_encoder, &pipe))
return false;
if (port == PORT_A)
cpu_transcoder = TRANSCODER_EDP;
else
cpu_transcoder = (enum transcoder) pipe;
tmp = I915_READ(TRANS_DDI_FUNC_CTL(cpu_transcoder));
switch (tmp & TRANS_DDI_MODE_SELECT_MASK) {
case TRANS_DDI_MODE_SELECT_HDMI:
case TRANS_DDI_MODE_SELECT_DVI:
return (type == DRM_MODE_CONNECTOR_HDMIA);
case TRANS_DDI_MODE_SELECT_DP_SST:
if (type == DRM_MODE_CONNECTOR_eDP)
return true;
return (type == DRM_MODE_CONNECTOR_DisplayPort);
case TRANS_DDI_MODE_SELECT_DP_MST:
return false;
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
enum intel_display_power_domain power_domain;
u32 tmp;
int i;
power_domain = intel_display_port_power_domain(encoder);
if (!intel_display_power_enabled(dev_priv, power_domain))
return false;
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
if ((tmp & TRANS_DDI_MODE_SELECT_MASK) == TRANS_DDI_MODE_SELECT_DP_MST)
return false;
*pipe = i;
return true;
}
}
}
DRM_DEBUG_KMS("No pipe for ddi port %c found\n", port_name(port));
return false;
}
void intel_ddi_enable_pipe_clock(struct intel_crtc *intel_crtc)
{
struct drm_crtc *crtc = &intel_crtc->base;
struct drm_i915_private *dev_priv = crtc->dev->dev_private;
struct intel_encoder *intel_encoder = intel_ddi_get_crtc_encoder(crtc);
enum port port = intel_ddi_get_encoder_port(intel_encoder);
enum transcoder cpu_transcoder = intel_crtc->config.cpu_transcoder;
if (cpu_transcoder != TRANSCODER_EDP)
I915_WRITE(TRANS_CLK_SEL(cpu_transcoder),
TRANS_CLK_SEL_PORT(port));
}
void intel_ddi_disable_pipe_clock(struct intel_crtc *intel_crtc)
{
struct drm_i915_private *dev_priv = intel_crtc->base.dev->dev_private;
enum transcoder cpu_transcoder = intel_crtc->config.cpu_transcoder;
if (cpu_transcoder != TRANSCODER_EDP)
I915_WRITE(TRANS_CLK_SEL(cpu_transcoder),
TRANS_CLK_SEL_DISABLED);
}
static void intel_ddi_pre_enable(struct intel_encoder *intel_encoder)
{
struct drm_encoder *encoder = &intel_encoder->base;
struct drm_i915_private *dev_priv = encoder->dev->dev_private;
struct intel_crtc *crtc = to_intel_crtc(encoder->crtc);
enum port port = intel_ddi_get_encoder_port(intel_encoder);
int type = intel_encoder->type;
if (crtc->config.has_audio) {
DRM_DEBUG_DRIVER("Audio on pipe %c on DDI\n",
pipe_name(crtc->pipe));
DRM_DEBUG_DRIVER("DDI audio: write eld information\n");
intel_write_eld(encoder, &crtc->config.adjusted_mode);
}
if (type == INTEL_OUTPUT_EDP) {
struct intel_dp *intel_dp = enc_to_intel_dp(encoder);
intel_edp_panel_on(intel_dp);
}
WARN_ON(crtc->config.ddi_pll_sel == PORT_CLK_SEL_NONE);
I915_WRITE(PORT_CLK_SEL(port), crtc->config.ddi_pll_sel);
if (type == INTEL_OUTPUT_DISPLAYPORT || type == INTEL_OUTPUT_EDP) {
struct intel_dp *intel_dp = enc_to_intel_dp(encoder);
intel_ddi_init_dp_buf_reg(intel_encoder);
intel_dp_sink_dpms(intel_dp, DRM_MODE_DPMS_ON);
intel_dp_start_link_train(intel_dp);
intel_dp_complete_link_train(intel_dp);
if (port != PORT_A)
intel_dp_stop_link_train(intel_dp);
} else if (type == INTEL_OUTPUT_HDMI) {
struct intel_hdmi *intel_hdmi = enc_to_intel_hdmi(encoder);
intel_hdmi->set_infoframes(encoder,
crtc->config.has_hdmi_sink,
&crtc->config.adjusted_mode);
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
if (type == INTEL_OUTPUT_DISPLAYPORT || type == INTEL_OUTPUT_EDP) {
struct intel_dp *intel_dp = enc_to_intel_dp(encoder);
intel_dp_sink_dpms(intel_dp, DRM_MODE_DPMS_OFF);
intel_edp_panel_vdd_on(intel_dp);
intel_edp_panel_off(intel_dp);
}
I915_WRITE(PORT_CLK_SEL(port), PORT_CLK_SEL_NONE);
}
static void intel_enable_ddi(struct intel_encoder *intel_encoder)
{
struct drm_encoder *encoder = &intel_encoder->base;
struct drm_crtc *crtc = encoder->crtc;
struct intel_crtc *intel_crtc = to_intel_crtc(crtc);
int pipe = intel_crtc->pipe;
struct drm_device *dev = encoder->dev;
struct drm_i915_private *dev_priv = dev->dev_private;
enum port port = intel_ddi_get_encoder_port(intel_encoder);
int type = intel_encoder->type;
uint32_t tmp;
if (type == INTEL_OUTPUT_HDMI) {
struct intel_digital_port *intel_dig_port =
enc_to_dig_port(encoder);
I915_WRITE(DDI_BUF_CTL(port),
intel_dig_port->saved_port_bits |
DDI_BUF_CTL_ENABLE);
} else if (type == INTEL_OUTPUT_EDP) {
struct intel_dp *intel_dp = enc_to_intel_dp(encoder);
if (port == PORT_A)
intel_dp_stop_link_train(intel_dp);
intel_edp_backlight_on(intel_dp);
intel_edp_psr_enable(intel_dp);
}
if (intel_crtc->config.has_audio) {
intel_display_power_get(dev_priv, POWER_DOMAIN_AUDIO);
tmp = I915_READ(HSW_AUD_PIN_ELD_CP_VLD);
tmp |= ((AUDIO_OUTPUT_ENABLE_A | AUDIO_ELD_VALID_A) << (pipe * 4));
I915_WRITE(HSW_AUD_PIN_ELD_CP_VLD, tmp);
}
}
static void intel_disable_ddi(struct intel_encoder *intel_encoder)
{
struct drm_encoder *encoder = &intel_encoder->base;
struct drm_crtc *crtc = encoder->crtc;
struct intel_crtc *intel_crtc = to_intel_crtc(crtc);
int pipe = intel_crtc->pipe;
int type = intel_encoder->type;
struct drm_device *dev = encoder->dev;
struct drm_i915_private *dev_priv = dev->dev_private;
uint32_t tmp;
if (intel_crtc->config.has_audio) {
tmp = I915_READ(HSW_AUD_PIN_ELD_CP_VLD);
tmp &= ~((AUDIO_OUTPUT_ENABLE_A | AUDIO_ELD_VALID_A) <<
(pipe * 4));
I915_WRITE(HSW_AUD_PIN_ELD_CP_VLD, tmp);
intel_display_power_put(dev_priv, POWER_DOMAIN_AUDIO);
}
if (type == INTEL_OUTPUT_EDP) {
struct intel_dp *intel_dp = enc_to_intel_dp(encoder);
intel_edp_psr_disable(intel_dp);
intel_edp_backlight_off(intel_dp);
}
}
static int bdw_get_cdclk_freq(struct drm_i915_private *dev_priv)
{
uint32_t lcpll = I915_READ(LCPLL_CTL);
uint32_t freq = lcpll & LCPLL_CLK_FREQ_MASK;
if (lcpll & LCPLL_CD_SOURCE_FCLK)
return 800000;
else if (I915_READ(FUSE_STRAP) & HSW_CDCLK_LIMIT)
return 450000;
else if (freq == LCPLL_CLK_FREQ_450)
return 450000;
else if (freq == LCPLL_CLK_FREQ_54O_BDW)
return 540000;
else if (freq == LCPLL_CLK_FREQ_337_5_BDW)
return 337500;
else
return 675000;
}
static int hsw_get_cdclk_freq(struct drm_i915_private *dev_priv)
{
struct drm_device *dev = dev_priv->dev;
uint32_t lcpll = I915_READ(LCPLL_CTL);
uint32_t freq = lcpll & LCPLL_CLK_FREQ_MASK;
if (lcpll & LCPLL_CD_SOURCE_FCLK)
return 800000;
else if (I915_READ(FUSE_STRAP) & HSW_CDCLK_LIMIT)
return 450000;
else if (freq == LCPLL_CLK_FREQ_450)
return 450000;
else if (IS_ULT(dev))
return 337500;
else
return 540000;
}
int intel_ddi_get_cdclk_freq(struct drm_i915_private *dev_priv)
{
struct drm_device *dev = dev_priv->dev;
if (IS_BROADWELL(dev))
return bdw_get_cdclk_freq(dev_priv);
return hsw_get_cdclk_freq(dev_priv);
}
static void hsw_ddi_pll_enable(struct drm_i915_private *dev_priv,
struct intel_shared_dpll *pll)
{
I915_WRITE(WRPLL_CTL(pll->id), pll->hw_state.wrpll);
POSTING_READ(WRPLL_CTL(pll->id));
udelay(20);
}
static void hsw_ddi_pll_disable(struct drm_i915_private *dev_priv,
struct intel_shared_dpll *pll)
{
uint32_t val;
val = I915_READ(WRPLL_CTL(pll->id));
I915_WRITE(WRPLL_CTL(pll->id), val & ~WRPLL_PLL_ENABLE);
POSTING_READ(WRPLL_CTL(pll->id));
}
static bool hsw_ddi_pll_get_hw_state(struct drm_i915_private *dev_priv,
struct intel_shared_dpll *pll,
struct intel_dpll_hw_state *hw_state)
{
uint32_t val;
if (!intel_display_power_enabled(dev_priv, POWER_DOMAIN_PLLS))
return false;
val = I915_READ(WRPLL_CTL(pll->id));
hw_state->wrpll = val;
return val & WRPLL_PLL_ENABLE;
}
static void hsw_shared_dplls_init(struct drm_i915_private *dev_priv)
{
int i;
dev_priv->num_shared_dpll = 2;
for (i = 0; i < dev_priv->num_shared_dpll; i++) {
dev_priv->shared_dplls[i].id = i;
dev_priv->shared_dplls[i].name = hsw_ddi_pll_names[i];
dev_priv->shared_dplls[i].disable = hsw_ddi_pll_disable;
dev_priv->shared_dplls[i].enable = hsw_ddi_pll_enable;
dev_priv->shared_dplls[i].get_hw_state =
hsw_ddi_pll_get_hw_state;
}
}
void intel_ddi_pll_init(struct drm_device *dev)
{
struct drm_i915_private *dev_priv = dev->dev_private;
uint32_t val = I915_READ(LCPLL_CTL);
hsw_shared_dplls_init(dev_priv);
DRM_DEBUG_KMS("CDCLK running at %dKHz\n",
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
uint32_t val;
bool wait = false;
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
val = DP_TP_CTL_ENABLE |
DP_TP_CTL_LINK_TRAIN_PAT1 | DP_TP_CTL_SCRAMBLE_DISABLE;
if (intel_dp->is_mst)
val |= DP_TP_CTL_MODE_MST;
else {
val |= DP_TP_CTL_MODE_SST;
if (drm_dp_enhanced_frame_cap(intel_dp->dpcd))
val |= DP_TP_CTL_ENHANCED_FRAME_ENABLE;
}
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
struct intel_digital_port *intel_dig_port = enc_to_dig_port(&intel_encoder->base);
int type = intel_dig_port->base.type;
if (type != INTEL_OUTPUT_DISPLAYPORT &&
type != INTEL_OUTPUT_EDP &&
type != INTEL_OUTPUT_UNKNOWN) {
return;
}
intel_dp_hot_plug(intel_encoder);
}
void intel_ddi_get_config(struct intel_encoder *encoder,
struct intel_crtc_config *pipe_config)
{
struct drm_i915_private *dev_priv = encoder->base.dev->dev_private;
struct intel_crtc *intel_crtc = to_intel_crtc(encoder->base.crtc);
enum transcoder cpu_transcoder = intel_crtc->config.cpu_transcoder;
u32 temp, flags = 0;
temp = I915_READ(TRANS_DDI_FUNC_CTL(cpu_transcoder));
if (temp & TRANS_DDI_PHSYNC)
flags |= DRM_MODE_FLAG_PHSYNC;
else
flags |= DRM_MODE_FLAG_NHSYNC;
if (temp & TRANS_DDI_PVSYNC)
flags |= DRM_MODE_FLAG_PVSYNC;
else
flags |= DRM_MODE_FLAG_NVSYNC;
pipe_config->adjusted_mode.flags |= flags;
switch (temp & TRANS_DDI_BPC_MASK) {
case TRANS_DDI_BPC_6:
pipe_config->pipe_bpp = 18;
break;
case TRANS_DDI_BPC_8:
pipe_config->pipe_bpp = 24;
break;
case TRANS_DDI_BPC_10:
pipe_config->pipe_bpp = 30;
break;
case TRANS_DDI_BPC_12:
pipe_config->pipe_bpp = 36;
break;
default:
break;
}
switch (temp & TRANS_DDI_MODE_SELECT_MASK) {
case TRANS_DDI_MODE_SELECT_HDMI:
pipe_config->has_hdmi_sink = true;
case TRANS_DDI_MODE_SELECT_DVI:
case TRANS_DDI_MODE_SELECT_FDI:
break;
case TRANS_DDI_MODE_SELECT_DP_SST:
case TRANS_DDI_MODE_SELECT_DP_MST:
pipe_config->has_dp_encoder = true;
intel_dp_get_m_n(intel_crtc, pipe_config);
break;
default:
break;
}
if (intel_display_power_enabled(dev_priv, POWER_DOMAIN_AUDIO)) {
temp = I915_READ(HSW_AUD_PIN_ELD_CP_VLD);
if (temp & (AUDIO_OUTPUT_ENABLE_A << (intel_crtc->pipe * 4)))
pipe_config->has_audio = true;
}
if (encoder->type == INTEL_OUTPUT_EDP && dev_priv->vbt.edp_bpp &&
pipe_config->pipe_bpp > dev_priv->vbt.edp_bpp) {
DRM_DEBUG_KMS("pipe has %d bpp for eDP panel, overriding BIOS-provided max %d bpp\n",
pipe_config->pipe_bpp, dev_priv->vbt.edp_bpp);
dev_priv->vbt.edp_bpp = pipe_config->pipe_bpp;
}
hsw_ddi_clock_get(encoder, pipe_config);
}
static void intel_ddi_destroy(struct drm_encoder *encoder)
{
intel_dp_encoder_destroy(encoder);
}
static bool intel_ddi_compute_config(struct intel_encoder *encoder,
struct intel_crtc_config *pipe_config)
{
int type = encoder->type;
int port = intel_ddi_get_encoder_port(encoder);
WARN(type == INTEL_OUTPUT_UNKNOWN, "compute_config() on unknown output!\n");
if (port == PORT_A)
pipe_config->cpu_transcoder = TRANSCODER_EDP;
if (type == INTEL_OUTPUT_HDMI)
return intel_hdmi_compute_config(encoder, pipe_config);
else
return intel_dp_compute_config(encoder, pipe_config);
}
static struct intel_connector *
intel_ddi_init_dp_connector(struct intel_digital_port *intel_dig_port)
{
struct intel_connector *connector;
enum port port = intel_dig_port->port;
connector = kzalloc(sizeof(*connector), GFP_KERNEL);
if (!connector)
return NULL;
intel_dig_port->dp.output_reg = DDI_BUF_CTL(port);
if (!intel_dp_init_connector(intel_dig_port, connector)) {
kfree(connector);
return NULL;
}
return connector;
}
static struct intel_connector *
intel_ddi_init_hdmi_connector(struct intel_digital_port *intel_dig_port)
{
struct intel_connector *connector;
enum port port = intel_dig_port->port;
connector = kzalloc(sizeof(*connector), GFP_KERNEL);
if (!connector)
return NULL;
intel_dig_port->hdmi.hdmi_reg = DDI_BUF_CTL(port);
intel_hdmi_init_connector(intel_dig_port, connector);
return connector;
}
void intel_ddi_init(struct drm_device *dev, enum port port)
{
struct drm_i915_private *dev_priv = dev->dev_private;
struct intel_digital_port *intel_dig_port;
struct intel_encoder *intel_encoder;
struct drm_encoder *encoder;
bool init_hdmi, init_dp;
init_hdmi = (dev_priv->vbt.ddi_port_info[port].supports_dvi ||
dev_priv->vbt.ddi_port_info[port].supports_hdmi);
init_dp = dev_priv->vbt.ddi_port_info[port].supports_dp;
if (!init_dp && !init_hdmi) {
DRM_DEBUG_KMS("VBT says port %c is not DVI/HDMI/DP compatible, assuming it is\n",
port_name(port));
init_hdmi = true;
init_dp = true;
}
intel_dig_port = kzalloc(sizeof(*intel_dig_port), GFP_KERNEL);
if (!intel_dig_port)
return;
intel_encoder = &intel_dig_port->base;
encoder = &intel_encoder->base;
drm_encoder_init(dev, encoder, &intel_ddi_funcs,
DRM_MODE_ENCODER_TMDS);
intel_encoder->compute_config = intel_ddi_compute_config;
intel_encoder->enable = intel_enable_ddi;
intel_encoder->pre_enable = intel_ddi_pre_enable;
intel_encoder->disable = intel_disable_ddi;
intel_encoder->post_disable = intel_ddi_post_disable;
intel_encoder->get_hw_state = intel_ddi_get_hw_state;
intel_encoder->get_config = intel_ddi_get_config;
intel_dig_port->port = port;
intel_dig_port->saved_port_bits = I915_READ(DDI_BUF_CTL(port)) &
(DDI_BUF_PORT_REVERSAL |
DDI_A_4_LANES);
intel_encoder->type = INTEL_OUTPUT_UNKNOWN;
intel_encoder->crtc_mask = (1 << 0) | (1 << 1) | (1 << 2);
intel_encoder->cloneable = 0;
intel_encoder->hot_plug = intel_ddi_hot_plug;
if (init_dp) {
if (!intel_ddi_init_dp_connector(intel_dig_port))
goto err;
intel_dig_port->hpd_pulse = intel_dp_hpd_pulse;
dev_priv->hpd_irq_port[port] = intel_dig_port;
}
if (intel_encoder->type != INTEL_OUTPUT_EDP && init_hdmi) {
if (!intel_ddi_init_hdmi_connector(intel_dig_port))
goto err;
}
return;
err:
drm_encoder_cleanup(encoder);
kfree(intel_dig_port);
}
