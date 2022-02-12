static u32 bxt_phy_port_mask(const struct bxt_ddi_phy_info *phy_info)
{
return (phy_info->dual_channel * BIT(phy_info->channel[DPIO_CH1].port)) |
BIT(phy_info->channel[DPIO_CH0].port);
}
void bxt_port_to_phy_channel(enum port port,
enum dpio_phy *phy, enum dpio_channel *ch)
{
const struct bxt_ddi_phy_info *phy_info;
int i;
for (i = 0; i < ARRAY_SIZE(bxt_ddi_phy_info); i++) {
phy_info = &bxt_ddi_phy_info[i];
if (port == phy_info->channel[DPIO_CH0].port) {
*phy = i;
*ch = DPIO_CH0;
return;
}
if (phy_info->dual_channel &&
port == phy_info->channel[DPIO_CH1].port) {
*phy = i;
*ch = DPIO_CH1;
return;
}
}
WARN(1, "PHY not found for PORT %c", port_name(port));
*phy = DPIO_PHY0;
*ch = DPIO_CH0;
}
void bxt_ddi_phy_set_signal_level(struct drm_i915_private *dev_priv,
enum port port, u32 margin, u32 scale,
u32 enable, u32 deemphasis)
{
u32 val;
enum dpio_phy phy;
enum dpio_channel ch;
bxt_port_to_phy_channel(port, &phy, &ch);
val = I915_READ(BXT_PORT_PCS_DW10_LN01(phy, ch));
val &= ~(TX2_SWING_CALC_INIT | TX1_SWING_CALC_INIT);
I915_WRITE(BXT_PORT_PCS_DW10_GRP(phy, ch), val);
val = I915_READ(BXT_PORT_TX_DW2_LN0(phy, ch));
val &= ~(MARGIN_000 | UNIQ_TRANS_SCALE);
val |= margin << MARGIN_000_SHIFT | scale << UNIQ_TRANS_SCALE_SHIFT;
I915_WRITE(BXT_PORT_TX_DW2_GRP(phy, ch), val);
val = I915_READ(BXT_PORT_TX_DW3_LN0(phy, ch));
val &= ~SCALE_DCOMP_METHOD;
if (enable)
val |= SCALE_DCOMP_METHOD;
if ((val & UNIQUE_TRANGE_EN_METHOD) && !(val & SCALE_DCOMP_METHOD))
DRM_ERROR("Disabled scaling while ouniqetrangenmethod was set");
I915_WRITE(BXT_PORT_TX_DW3_GRP(phy, ch), val);
val = I915_READ(BXT_PORT_TX_DW4_LN0(phy, ch));
val &= ~DE_EMPHASIS;
val |= deemphasis << DEEMPH_SHIFT;
I915_WRITE(BXT_PORT_TX_DW4_GRP(phy, ch), val);
val = I915_READ(BXT_PORT_PCS_DW10_LN01(phy, ch));
val |= TX2_SWING_CALC_INIT | TX1_SWING_CALC_INIT;
I915_WRITE(BXT_PORT_PCS_DW10_GRP(phy, ch), val);
}
bool bxt_ddi_phy_is_enabled(struct drm_i915_private *dev_priv,
enum dpio_phy phy)
{
const struct bxt_ddi_phy_info *phy_info = &bxt_ddi_phy_info[phy];
enum port port;
if (!(I915_READ(BXT_P_CR_GT_DISP_PWRON) & GT_DISPLAY_POWER_ON(phy)))
return false;
if ((I915_READ(BXT_PORT_CL1CM_DW0(phy)) &
(PHY_POWER_GOOD | PHY_RESERVED)) != PHY_POWER_GOOD) {
DRM_DEBUG_DRIVER("DDI PHY %d powered, but power hasn't settled\n",
phy);
return false;
}
if (phy_info->rcomp_phy == -1 &&
!(I915_READ(BXT_PORT_REF_DW3(phy)) & GRC_DONE)) {
DRM_DEBUG_DRIVER("DDI PHY %d powered, but GRC isn't done\n",
phy);
return false;
}
if (!(I915_READ(BXT_PHY_CTL_FAMILY(phy)) & COMMON_RESET_DIS)) {
DRM_DEBUG_DRIVER("DDI PHY %d powered, but still in reset\n",
phy);
return false;
}
for_each_port_masked(port, bxt_phy_port_mask(phy_info)) {
u32 tmp = I915_READ(BXT_PHY_CTL(port));
if (tmp & BXT_PHY_CMNLANE_POWERDOWN_ACK) {
DRM_DEBUG_DRIVER("DDI PHY %d powered, but common lane "
"for port %c powered down "
"(PHY_CTL %08x)\n",
phy, port_name(port), tmp);
return false;
}
}
return true;
}
static u32 bxt_get_grc(struct drm_i915_private *dev_priv, enum dpio_phy phy)
{
u32 val = I915_READ(BXT_PORT_REF_DW6(phy));
return (val & GRC_CODE_MASK) >> GRC_CODE_SHIFT;
}
static void bxt_phy_wait_grc_done(struct drm_i915_private *dev_priv,
enum dpio_phy phy)
{
if (intel_wait_for_register(dev_priv,
BXT_PORT_REF_DW3(phy),
GRC_DONE, GRC_DONE,
10))
DRM_ERROR("timeout waiting for PHY%d GRC\n", phy);
}
static void _bxt_ddi_phy_init(struct drm_i915_private *dev_priv,
enum dpio_phy phy)
{
const struct bxt_ddi_phy_info *phy_info = &bxt_ddi_phy_info[phy];
u32 val;
if (bxt_ddi_phy_is_enabled(dev_priv, phy)) {
if (phy_info->rcomp_phy != -1)
dev_priv->bxt_phy_grc = bxt_get_grc(dev_priv, phy);
if (bxt_ddi_phy_verify_state(dev_priv, phy)) {
DRM_DEBUG_DRIVER("DDI PHY %d already enabled, "
"won't reprogram it\n", phy);
return;
}
DRM_DEBUG_DRIVER("DDI PHY %d enabled with invalid state, "
"force reprogramming it\n", phy);
}
val = I915_READ(BXT_P_CR_GT_DISP_PWRON);
val |= GT_DISPLAY_POWER_ON(phy);
I915_WRITE(BXT_P_CR_GT_DISP_PWRON, val);
if (wait_for_us(((I915_READ(BXT_PORT_CL1CM_DW0(phy)) &
(PHY_RESERVED | PHY_POWER_GOOD)) == PHY_POWER_GOOD), 100)) {
DRM_ERROR("timeout during PHY%d power on\n", phy);
}
val = I915_READ(BXT_PORT_CL1CM_DW9(phy));
val &= ~IREF0RC_OFFSET_MASK;
val |= 0xE4 << IREF0RC_OFFSET_SHIFT;
I915_WRITE(BXT_PORT_CL1CM_DW9(phy), val);
val = I915_READ(BXT_PORT_CL1CM_DW10(phy));
val &= ~IREF1RC_OFFSET_MASK;
val |= 0xE4 << IREF1RC_OFFSET_SHIFT;
I915_WRITE(BXT_PORT_CL1CM_DW10(phy), val);
val = I915_READ(BXT_PORT_CL1CM_DW28(phy));
val |= OCL1_POWER_DOWN_EN | DW28_OLDO_DYN_PWR_DOWN_EN |
SUS_CLK_CONFIG;
I915_WRITE(BXT_PORT_CL1CM_DW28(phy), val);
if (phy_info->dual_channel) {
val = I915_READ(BXT_PORT_CL2CM_DW6(phy));
val |= DW6_OLDO_DYN_PWR_DOWN_EN;
I915_WRITE(BXT_PORT_CL2CM_DW6(phy), val);
}
if (phy_info->rcomp_phy != -1) {
uint32_t grc_code;
val = dev_priv->bxt_phy_grc = bxt_get_grc(dev_priv,
phy_info->rcomp_phy);
grc_code = val << GRC_CODE_FAST_SHIFT |
val << GRC_CODE_SLOW_SHIFT |
val;
I915_WRITE(BXT_PORT_REF_DW6(phy), grc_code);
val = I915_READ(BXT_PORT_REF_DW8(phy));
val |= GRC_DIS | GRC_RDY_OVRD;
I915_WRITE(BXT_PORT_REF_DW8(phy), val);
}
val = I915_READ(BXT_PHY_CTL_FAMILY(phy));
val |= COMMON_RESET_DIS;
I915_WRITE(BXT_PHY_CTL_FAMILY(phy), val);
if (phy_info->rcomp_phy == -1)
bxt_phy_wait_grc_done(dev_priv, phy);
}
void bxt_ddi_phy_uninit(struct drm_i915_private *dev_priv, enum dpio_phy phy)
{
uint32_t val;
val = I915_READ(BXT_PHY_CTL_FAMILY(phy));
val &= ~COMMON_RESET_DIS;
I915_WRITE(BXT_PHY_CTL_FAMILY(phy), val);
val = I915_READ(BXT_P_CR_GT_DISP_PWRON);
val &= ~GT_DISPLAY_POWER_ON(phy);
I915_WRITE(BXT_P_CR_GT_DISP_PWRON, val);
}
void bxt_ddi_phy_init(struct drm_i915_private *dev_priv, enum dpio_phy phy)
{
const struct bxt_ddi_phy_info *phy_info = &bxt_ddi_phy_info[phy];
enum dpio_phy rcomp_phy = phy_info->rcomp_phy;
bool was_enabled;
lockdep_assert_held(&dev_priv->power_domains.lock);
if (rcomp_phy != -1) {
was_enabled = bxt_ddi_phy_is_enabled(dev_priv, rcomp_phy);
if (!was_enabled)
_bxt_ddi_phy_init(dev_priv, rcomp_phy);
}
_bxt_ddi_phy_init(dev_priv, phy);
if (rcomp_phy != -1 && !was_enabled)
bxt_ddi_phy_uninit(dev_priv, phy_info->rcomp_phy);
}
bool bxt_ddi_phy_verify_state(struct drm_i915_private *dev_priv,
enum dpio_phy phy)
{
const struct bxt_ddi_phy_info *phy_info = &bxt_ddi_phy_info[phy];
uint32_t mask;
bool ok;
#define _CHK(reg, mask, exp, fmt, ...) \
__phy_reg_verify_state(dev_priv, phy, reg, mask, exp, fmt, \
## __VA_ARGS__)
if (!bxt_ddi_phy_is_enabled(dev_priv, phy))
return false;
ok = true;
ok &= _CHK(BXT_PORT_CL1CM_DW9(phy),
IREF0RC_OFFSET_MASK, 0xe4 << IREF0RC_OFFSET_SHIFT,
"BXT_PORT_CL1CM_DW9(%d)", phy);
ok &= _CHK(BXT_PORT_CL1CM_DW10(phy),
IREF1RC_OFFSET_MASK, 0xe4 << IREF1RC_OFFSET_SHIFT,
"BXT_PORT_CL1CM_DW10(%d)", phy);
mask = OCL1_POWER_DOWN_EN | DW28_OLDO_DYN_PWR_DOWN_EN | SUS_CLK_CONFIG;
ok &= _CHK(BXT_PORT_CL1CM_DW28(phy), mask, mask,
"BXT_PORT_CL1CM_DW28(%d)", phy);
if (phy_info->dual_channel)
ok &= _CHK(BXT_PORT_CL2CM_DW6(phy),
DW6_OLDO_DYN_PWR_DOWN_EN, DW6_OLDO_DYN_PWR_DOWN_EN,
"BXT_PORT_CL2CM_DW6(%d)", phy);
if (phy_info->rcomp_phy != -1) {
u32 grc_code = dev_priv->bxt_phy_grc;
grc_code = grc_code << GRC_CODE_FAST_SHIFT |
grc_code << GRC_CODE_SLOW_SHIFT |
grc_code;
mask = GRC_CODE_FAST_MASK | GRC_CODE_SLOW_MASK |
GRC_CODE_NOM_MASK;
ok &= _CHK(BXT_PORT_REF_DW6(phy), mask, grc_code,
"BXT_PORT_REF_DW6(%d)", phy);
mask = GRC_DIS | GRC_RDY_OVRD;
ok &= _CHK(BXT_PORT_REF_DW8(phy), mask, mask,
"BXT_PORT_REF_DW8(%d)", phy);
}
return ok;
#undef _CHK
}
uint8_t
bxt_ddi_phy_calc_lane_lat_optim_mask(struct intel_encoder *encoder,
uint8_t lane_count)
{
switch (lane_count) {
case 1:
return 0;
case 2:
return BIT(2) | BIT(0);
case 4:
return BIT(3) | BIT(2) | BIT(0);
default:
MISSING_CASE(lane_count);
return 0;
}
}
void bxt_ddi_phy_set_lane_optim_mask(struct intel_encoder *encoder,
uint8_t lane_lat_optim_mask)
{
struct intel_digital_port *dport = enc_to_dig_port(&encoder->base);
struct drm_i915_private *dev_priv = to_i915(dport->base.base.dev);
enum port port = dport->port;
enum dpio_phy phy;
enum dpio_channel ch;
int lane;
bxt_port_to_phy_channel(port, &phy, &ch);
for (lane = 0; lane < 4; lane++) {
u32 val = I915_READ(BXT_PORT_TX_DW14_LN(phy, ch, lane));
val &= ~LATENCY_OPTIM;
if (lane_lat_optim_mask & BIT(lane))
val |= LATENCY_OPTIM;
I915_WRITE(BXT_PORT_TX_DW14_LN(phy, ch, lane), val);
}
}
uint8_t
bxt_ddi_phy_get_lane_lat_optim_mask(struct intel_encoder *encoder)
{
struct intel_digital_port *dport = enc_to_dig_port(&encoder->base);
struct drm_i915_private *dev_priv = to_i915(dport->base.base.dev);
enum port port = dport->port;
enum dpio_phy phy;
enum dpio_channel ch;
int lane;
uint8_t mask;
bxt_port_to_phy_channel(port, &phy, &ch);
mask = 0;
for (lane = 0; lane < 4; lane++) {
u32 val = I915_READ(BXT_PORT_TX_DW14_LN(phy, ch, lane));
if (val & LATENCY_OPTIM)
mask |= BIT(lane);
}
return mask;
}
void chv_set_phy_signal_level(struct intel_encoder *encoder,
u32 deemph_reg_value, u32 margin_reg_value,
bool uniq_trans_scale)
{
struct drm_i915_private *dev_priv = to_i915(encoder->base.dev);
struct intel_digital_port *dport = enc_to_dig_port(&encoder->base);
struct intel_crtc *intel_crtc = to_intel_crtc(dport->base.base.crtc);
enum dpio_channel ch = vlv_dport_to_channel(dport);
enum pipe pipe = intel_crtc->pipe;
u32 val;
int i;
mutex_lock(&dev_priv->sb_lock);
val = vlv_dpio_read(dev_priv, pipe, VLV_PCS01_DW10(ch));
val &= ~(DPIO_PCS_SWING_CALC_TX0_TX2 | DPIO_PCS_SWING_CALC_TX1_TX3);
val &= ~(DPIO_PCS_TX1DEEMP_MASK | DPIO_PCS_TX2DEEMP_MASK);
val |= DPIO_PCS_TX1DEEMP_9P5 | DPIO_PCS_TX2DEEMP_9P5;
vlv_dpio_write(dev_priv, pipe, VLV_PCS01_DW10(ch), val);
if (intel_crtc->config->lane_count > 2) {
val = vlv_dpio_read(dev_priv, pipe, VLV_PCS23_DW10(ch));
val &= ~(DPIO_PCS_SWING_CALC_TX0_TX2 | DPIO_PCS_SWING_CALC_TX1_TX3);
val &= ~(DPIO_PCS_TX1DEEMP_MASK | DPIO_PCS_TX2DEEMP_MASK);
val |= DPIO_PCS_TX1DEEMP_9P5 | DPIO_PCS_TX2DEEMP_9P5;
vlv_dpio_write(dev_priv, pipe, VLV_PCS23_DW10(ch), val);
}
val = vlv_dpio_read(dev_priv, pipe, VLV_PCS01_DW9(ch));
val &= ~(DPIO_PCS_TX1MARGIN_MASK | DPIO_PCS_TX2MARGIN_MASK);
val |= DPIO_PCS_TX1MARGIN_000 | DPIO_PCS_TX2MARGIN_000;
vlv_dpio_write(dev_priv, pipe, VLV_PCS01_DW9(ch), val);
if (intel_crtc->config->lane_count > 2) {
val = vlv_dpio_read(dev_priv, pipe, VLV_PCS23_DW9(ch));
val &= ~(DPIO_PCS_TX1MARGIN_MASK | DPIO_PCS_TX2MARGIN_MASK);
val |= DPIO_PCS_TX1MARGIN_000 | DPIO_PCS_TX2MARGIN_000;
vlv_dpio_write(dev_priv, pipe, VLV_PCS23_DW9(ch), val);
}
for (i = 0; i < intel_crtc->config->lane_count; i++) {
val = vlv_dpio_read(dev_priv, pipe, CHV_TX_DW4(ch, i));
val &= ~DPIO_SWING_DEEMPH9P5_MASK;
val |= deemph_reg_value << DPIO_SWING_DEEMPH9P5_SHIFT;
vlv_dpio_write(dev_priv, pipe, CHV_TX_DW4(ch, i), val);
}
for (i = 0; i < intel_crtc->config->lane_count; i++) {
val = vlv_dpio_read(dev_priv, pipe, CHV_TX_DW2(ch, i));
val &= ~DPIO_SWING_MARGIN000_MASK;
val |= margin_reg_value << DPIO_SWING_MARGIN000_SHIFT;
val &= ~(0xff << DPIO_UNIQ_TRANS_SCALE_SHIFT);
val |= 0x9a << DPIO_UNIQ_TRANS_SCALE_SHIFT;
vlv_dpio_write(dev_priv, pipe, CHV_TX_DW2(ch, i), val);
}
for (i = 0; i < intel_crtc->config->lane_count; i++) {
val = vlv_dpio_read(dev_priv, pipe, CHV_TX_DW3(ch, i));
if (uniq_trans_scale)
val |= DPIO_TX_UNIQ_TRANS_SCALE_EN;
else
val &= ~DPIO_TX_UNIQ_TRANS_SCALE_EN;
vlv_dpio_write(dev_priv, pipe, CHV_TX_DW3(ch, i), val);
}
val = vlv_dpio_read(dev_priv, pipe, VLV_PCS01_DW10(ch));
val |= DPIO_PCS_SWING_CALC_TX0_TX2 | DPIO_PCS_SWING_CALC_TX1_TX3;
vlv_dpio_write(dev_priv, pipe, VLV_PCS01_DW10(ch), val);
if (intel_crtc->config->lane_count > 2) {
val = vlv_dpio_read(dev_priv, pipe, VLV_PCS23_DW10(ch));
val |= DPIO_PCS_SWING_CALC_TX0_TX2 | DPIO_PCS_SWING_CALC_TX1_TX3;
vlv_dpio_write(dev_priv, pipe, VLV_PCS23_DW10(ch), val);
}
mutex_unlock(&dev_priv->sb_lock);
}
void chv_data_lane_soft_reset(struct intel_encoder *encoder,
bool reset)
{
struct drm_i915_private *dev_priv = to_i915(encoder->base.dev);
enum dpio_channel ch = vlv_dport_to_channel(enc_to_dig_port(&encoder->base));
struct intel_crtc *crtc = to_intel_crtc(encoder->base.crtc);
enum pipe pipe = crtc->pipe;
uint32_t val;
val = vlv_dpio_read(dev_priv, pipe, VLV_PCS01_DW0(ch));
if (reset)
val &= ~(DPIO_PCS_TX_LANE2_RESET | DPIO_PCS_TX_LANE1_RESET);
else
val |= DPIO_PCS_TX_LANE2_RESET | DPIO_PCS_TX_LANE1_RESET;
vlv_dpio_write(dev_priv, pipe, VLV_PCS01_DW0(ch), val);
if (crtc->config->lane_count > 2) {
val = vlv_dpio_read(dev_priv, pipe, VLV_PCS23_DW0(ch));
if (reset)
val &= ~(DPIO_PCS_TX_LANE2_RESET | DPIO_PCS_TX_LANE1_RESET);
else
val |= DPIO_PCS_TX_LANE2_RESET | DPIO_PCS_TX_LANE1_RESET;
vlv_dpio_write(dev_priv, pipe, VLV_PCS23_DW0(ch), val);
}
val = vlv_dpio_read(dev_priv, pipe, VLV_PCS01_DW1(ch));
val |= CHV_PCS_REQ_SOFTRESET_EN;
if (reset)
val &= ~DPIO_PCS_CLK_SOFT_RESET;
else
val |= DPIO_PCS_CLK_SOFT_RESET;
vlv_dpio_write(dev_priv, pipe, VLV_PCS01_DW1(ch), val);
if (crtc->config->lane_count > 2) {
val = vlv_dpio_read(dev_priv, pipe, VLV_PCS23_DW1(ch));
val |= CHV_PCS_REQ_SOFTRESET_EN;
if (reset)
val &= ~DPIO_PCS_CLK_SOFT_RESET;
else
val |= DPIO_PCS_CLK_SOFT_RESET;
vlv_dpio_write(dev_priv, pipe, VLV_PCS23_DW1(ch), val);
}
}
void chv_phy_pre_pll_enable(struct intel_encoder *encoder)
{
struct intel_digital_port *dport = enc_to_dig_port(&encoder->base);
struct drm_device *dev = encoder->base.dev;
struct drm_i915_private *dev_priv = to_i915(dev);
struct intel_crtc *intel_crtc =
to_intel_crtc(encoder->base.crtc);
enum dpio_channel ch = vlv_dport_to_channel(dport);
enum pipe pipe = intel_crtc->pipe;
unsigned int lane_mask =
intel_dp_unused_lane_mask(intel_crtc->config->lane_count);
u32 val;
if (ch == DPIO_CH0 && pipe == PIPE_B)
dport->release_cl2_override =
!chv_phy_powergate_ch(dev_priv, DPIO_PHY0, DPIO_CH1, true);
chv_phy_powergate_lanes(encoder, true, lane_mask);
mutex_lock(&dev_priv->sb_lock);
chv_data_lane_soft_reset(encoder, true);
if (pipe != PIPE_B) {
val = vlv_dpio_read(dev_priv, pipe, _CHV_CMN_DW5_CH0);
val &= ~(CHV_BUFLEFTENA1_MASK | CHV_BUFRIGHTENA1_MASK);
if (ch == DPIO_CH0)
val |= CHV_BUFLEFTENA1_FORCE;
if (ch == DPIO_CH1)
val |= CHV_BUFRIGHTENA1_FORCE;
vlv_dpio_write(dev_priv, pipe, _CHV_CMN_DW5_CH0, val);
} else {
val = vlv_dpio_read(dev_priv, pipe, _CHV_CMN_DW1_CH1);
val &= ~(CHV_BUFLEFTENA2_MASK | CHV_BUFRIGHTENA2_MASK);
if (ch == DPIO_CH0)
val |= CHV_BUFLEFTENA2_FORCE;
if (ch == DPIO_CH1)
val |= CHV_BUFRIGHTENA2_FORCE;
vlv_dpio_write(dev_priv, pipe, _CHV_CMN_DW1_CH1, val);
}
val = vlv_dpio_read(dev_priv, pipe, VLV_PCS01_DW8(ch));
val |= CHV_PCS_USEDCLKCHANNEL_OVRRIDE;
if (pipe != PIPE_B)
val &= ~CHV_PCS_USEDCLKCHANNEL;
else
val |= CHV_PCS_USEDCLKCHANNEL;
vlv_dpio_write(dev_priv, pipe, VLV_PCS01_DW8(ch), val);
if (intel_crtc->config->lane_count > 2) {
val = vlv_dpio_read(dev_priv, pipe, VLV_PCS23_DW8(ch));
val |= CHV_PCS_USEDCLKCHANNEL_OVRRIDE;
if (pipe != PIPE_B)
val &= ~CHV_PCS_USEDCLKCHANNEL;
else
val |= CHV_PCS_USEDCLKCHANNEL;
vlv_dpio_write(dev_priv, pipe, VLV_PCS23_DW8(ch), val);
}
val = vlv_dpio_read(dev_priv, pipe, CHV_CMN_DW19(ch));
if (pipe != PIPE_B)
val &= ~CHV_CMN_USEDCLKCHANNEL;
else
val |= CHV_CMN_USEDCLKCHANNEL;
vlv_dpio_write(dev_priv, pipe, CHV_CMN_DW19(ch), val);
mutex_unlock(&dev_priv->sb_lock);
}
void chv_phy_pre_encoder_enable(struct intel_encoder *encoder)
{
struct intel_dp *intel_dp = enc_to_intel_dp(&encoder->base);
struct intel_digital_port *dport = dp_to_dig_port(intel_dp);
struct drm_device *dev = encoder->base.dev;
struct drm_i915_private *dev_priv = to_i915(dev);
struct intel_crtc *intel_crtc =
to_intel_crtc(encoder->base.crtc);
enum dpio_channel ch = vlv_dport_to_channel(dport);
int pipe = intel_crtc->pipe;
int data, i, stagger;
u32 val;
mutex_lock(&dev_priv->sb_lock);
val = vlv_dpio_read(dev_priv, pipe, VLV_PCS01_DW11(ch));
val &= ~DPIO_LANEDESKEW_STRAP_OVRD;
vlv_dpio_write(dev_priv, pipe, VLV_PCS01_DW11(ch), val);
if (intel_crtc->config->lane_count > 2) {
val = vlv_dpio_read(dev_priv, pipe, VLV_PCS23_DW11(ch));
val &= ~DPIO_LANEDESKEW_STRAP_OVRD;
vlv_dpio_write(dev_priv, pipe, VLV_PCS23_DW11(ch), val);
}
for (i = 0; i < intel_crtc->config->lane_count; i++) {
if (intel_crtc->config->lane_count == 1)
data = 0x0;
else
data = (i == 1) ? 0x0 : 0x1;
vlv_dpio_write(dev_priv, pipe, CHV_TX_DW14(ch, i),
data << DPIO_UPAR_SHIFT);
}
if (intel_crtc->config->port_clock > 270000)
stagger = 0x18;
else if (intel_crtc->config->port_clock > 135000)
stagger = 0xd;
else if (intel_crtc->config->port_clock > 67500)
stagger = 0x7;
else if (intel_crtc->config->port_clock > 33750)
stagger = 0x4;
else
stagger = 0x2;
val = vlv_dpio_read(dev_priv, pipe, VLV_PCS01_DW11(ch));
val |= DPIO_TX2_STAGGER_MASK(0x1f);
vlv_dpio_write(dev_priv, pipe, VLV_PCS01_DW11(ch), val);
if (intel_crtc->config->lane_count > 2) {
val = vlv_dpio_read(dev_priv, pipe, VLV_PCS23_DW11(ch));
val |= DPIO_TX2_STAGGER_MASK(0x1f);
vlv_dpio_write(dev_priv, pipe, VLV_PCS23_DW11(ch), val);
}
vlv_dpio_write(dev_priv, pipe, VLV_PCS01_DW12(ch),
DPIO_LANESTAGGER_STRAP(stagger) |
DPIO_LANESTAGGER_STRAP_OVRD |
DPIO_TX1_STAGGER_MASK(0x1f) |
DPIO_TX1_STAGGER_MULT(6) |
DPIO_TX2_STAGGER_MULT(0));
if (intel_crtc->config->lane_count > 2) {
vlv_dpio_write(dev_priv, pipe, VLV_PCS23_DW12(ch),
DPIO_LANESTAGGER_STRAP(stagger) |
DPIO_LANESTAGGER_STRAP_OVRD |
DPIO_TX1_STAGGER_MASK(0x1f) |
DPIO_TX1_STAGGER_MULT(7) |
DPIO_TX2_STAGGER_MULT(5));
}
chv_data_lane_soft_reset(encoder, false);
mutex_unlock(&dev_priv->sb_lock);
}
void chv_phy_release_cl2_override(struct intel_encoder *encoder)
{
struct intel_digital_port *dport = enc_to_dig_port(&encoder->base);
struct drm_i915_private *dev_priv = to_i915(encoder->base.dev);
if (dport->release_cl2_override) {
chv_phy_powergate_ch(dev_priv, DPIO_PHY0, DPIO_CH1, false);
dport->release_cl2_override = false;
}
}
void chv_phy_post_pll_disable(struct intel_encoder *encoder)
{
struct drm_i915_private *dev_priv = to_i915(encoder->base.dev);
enum pipe pipe = to_intel_crtc(encoder->base.crtc)->pipe;
u32 val;
mutex_lock(&dev_priv->sb_lock);
if (pipe != PIPE_B) {
val = vlv_dpio_read(dev_priv, pipe, _CHV_CMN_DW5_CH0);
val &= ~(CHV_BUFLEFTENA1_MASK | CHV_BUFRIGHTENA1_MASK);
vlv_dpio_write(dev_priv, pipe, _CHV_CMN_DW5_CH0, val);
} else {
val = vlv_dpio_read(dev_priv, pipe, _CHV_CMN_DW1_CH1);
val &= ~(CHV_BUFLEFTENA2_MASK | CHV_BUFRIGHTENA2_MASK);
vlv_dpio_write(dev_priv, pipe, _CHV_CMN_DW1_CH1, val);
}
mutex_unlock(&dev_priv->sb_lock);
chv_phy_powergate_lanes(encoder, false, 0x0);
}
void vlv_set_phy_signal_level(struct intel_encoder *encoder,
u32 demph_reg_value, u32 preemph_reg_value,
u32 uniqtranscale_reg_value, u32 tx3_demph)
{
struct drm_i915_private *dev_priv = to_i915(encoder->base.dev);
struct intel_crtc *intel_crtc = to_intel_crtc(encoder->base.crtc);
struct intel_digital_port *dport = enc_to_dig_port(&encoder->base);
enum dpio_channel port = vlv_dport_to_channel(dport);
int pipe = intel_crtc->pipe;
mutex_lock(&dev_priv->sb_lock);
vlv_dpio_write(dev_priv, pipe, VLV_TX_DW5(port), 0x00000000);
vlv_dpio_write(dev_priv, pipe, VLV_TX_DW4(port), demph_reg_value);
vlv_dpio_write(dev_priv, pipe, VLV_TX_DW2(port),
uniqtranscale_reg_value);
vlv_dpio_write(dev_priv, pipe, VLV_TX_DW3(port), 0x0C782040);
if (tx3_demph)
vlv_dpio_write(dev_priv, pipe, VLV_TX3_DW4(port), tx3_demph);
vlv_dpio_write(dev_priv, pipe, VLV_PCS_DW11(port), 0x00030000);
vlv_dpio_write(dev_priv, pipe, VLV_PCS_DW9(port), preemph_reg_value);
vlv_dpio_write(dev_priv, pipe, VLV_TX_DW5(port), DPIO_TX_OCALINIT_EN);
mutex_unlock(&dev_priv->sb_lock);
}
void vlv_phy_pre_pll_enable(struct intel_encoder *encoder)
{
struct intel_digital_port *dport = enc_to_dig_port(&encoder->base);
struct drm_device *dev = encoder->base.dev;
struct drm_i915_private *dev_priv = to_i915(dev);
struct intel_crtc *intel_crtc =
to_intel_crtc(encoder->base.crtc);
enum dpio_channel port = vlv_dport_to_channel(dport);
int pipe = intel_crtc->pipe;
mutex_lock(&dev_priv->sb_lock);
vlv_dpio_write(dev_priv, pipe, VLV_PCS_DW0(port),
DPIO_PCS_TX_LANE2_RESET |
DPIO_PCS_TX_LANE1_RESET);
vlv_dpio_write(dev_priv, pipe, VLV_PCS_DW1(port),
DPIO_PCS_CLK_CRI_RXEB_EIOS_EN |
DPIO_PCS_CLK_CRI_RXDIGFILTSG_EN |
(1<<DPIO_PCS_CLK_DATAWIDTH_SHIFT) |
DPIO_PCS_CLK_SOFT_RESET);
vlv_dpio_write(dev_priv, pipe, VLV_PCS_DW12(port), 0x00750f00);
vlv_dpio_write(dev_priv, pipe, VLV_TX_DW11(port), 0x00001500);
vlv_dpio_write(dev_priv, pipe, VLV_TX_DW14(port), 0x40400000);
mutex_unlock(&dev_priv->sb_lock);
}
void vlv_phy_pre_encoder_enable(struct intel_encoder *encoder)
{
struct intel_dp *intel_dp = enc_to_intel_dp(&encoder->base);
struct intel_digital_port *dport = dp_to_dig_port(intel_dp);
struct drm_device *dev = encoder->base.dev;
struct drm_i915_private *dev_priv = to_i915(dev);
struct intel_crtc *intel_crtc = to_intel_crtc(encoder->base.crtc);
enum dpio_channel port = vlv_dport_to_channel(dport);
int pipe = intel_crtc->pipe;
u32 val;
mutex_lock(&dev_priv->sb_lock);
val = vlv_dpio_read(dev_priv, pipe, VLV_PCS01_DW8(port));
val = 0;
if (pipe)
val |= (1<<21);
else
val &= ~(1<<21);
val |= 0x001000c4;
vlv_dpio_write(dev_priv, pipe, VLV_PCS_DW8(port), val);
vlv_dpio_write(dev_priv, pipe, VLV_PCS_DW14(port), 0x00760018);
vlv_dpio_write(dev_priv, pipe, VLV_PCS_DW23(port), 0x00400888);
mutex_unlock(&dev_priv->sb_lock);
}
void vlv_phy_reset_lanes(struct intel_encoder *encoder)
{
struct intel_digital_port *dport = enc_to_dig_port(&encoder->base);
struct drm_i915_private *dev_priv = to_i915(encoder->base.dev);
struct intel_crtc *intel_crtc =
to_intel_crtc(encoder->base.crtc);
enum dpio_channel port = vlv_dport_to_channel(dport);
int pipe = intel_crtc->pipe;
mutex_lock(&dev_priv->sb_lock);
vlv_dpio_write(dev_priv, pipe, VLV_PCS_DW0(port), 0x00000000);
vlv_dpio_write(dev_priv, pipe, VLV_PCS_DW1(port), 0x00e00060);
mutex_unlock(&dev_priv->sb_lock);
}
