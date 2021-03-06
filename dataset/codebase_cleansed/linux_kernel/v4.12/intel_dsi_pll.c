static u32 dsi_clk_from_pclk(u32 pclk, enum mipi_dsi_pixel_format fmt,
int lane_count)
{
u32 dsi_clk_khz;
u32 bpp = mipi_dsi_pixel_format_to_bpp(fmt);
dsi_clk_khz = DIV_ROUND_CLOSEST(pclk * bpp, lane_count);
return dsi_clk_khz;
}
static int dsi_calc_mnp(struct drm_i915_private *dev_priv,
struct intel_crtc_state *config,
int target_dsi_clk)
{
unsigned int m_min, m_max, p_min = 2, p_max = 6;
unsigned int m, n, p;
unsigned int calc_m, calc_p;
int delta, ref_clk;
if (target_dsi_clk < 300000 || target_dsi_clk > 1150000) {
DRM_ERROR("DSI CLK Out of Range\n");
return -ECHRNG;
}
if (IS_CHERRYVIEW(dev_priv)) {
ref_clk = 100000;
n = 4;
m_min = 70;
m_max = 96;
} else {
ref_clk = 25000;
n = 1;
m_min = 62;
m_max = 92;
}
calc_p = p_min;
calc_m = m_min;
delta = abs(target_dsi_clk - (m_min * ref_clk) / (p_min * n));
for (m = m_min; m <= m_max && delta; m++) {
for (p = p_min; p <= p_max && delta; p++) {
int calc_dsi_clk = (m * ref_clk) / (p * n);
int d = abs(target_dsi_clk - calc_dsi_clk);
if (d < delta) {
delta = d;
calc_m = m;
calc_p = p;
}
}
}
config->dsi_pll.ctrl = 1 << (DSI_PLL_P1_POST_DIV_SHIFT + calc_p - 2);
config->dsi_pll.div =
(ffs(n) - 1) << DSI_PLL_N1_DIV_SHIFT |
(u32)lfsr_converts[calc_m - 62] << DSI_PLL_M1_DIV_SHIFT;
return 0;
}
static int vlv_compute_dsi_pll(struct intel_encoder *encoder,
struct intel_crtc_state *config)
{
struct drm_i915_private *dev_priv = to_i915(encoder->base.dev);
struct intel_dsi *intel_dsi = enc_to_intel_dsi(&encoder->base);
int ret;
u32 dsi_clk;
dsi_clk = dsi_clk_from_pclk(intel_dsi->pclk, intel_dsi->pixel_format,
intel_dsi->lane_count);
ret = dsi_calc_mnp(dev_priv, config, dsi_clk);
if (ret) {
DRM_DEBUG_KMS("dsi_calc_mnp failed\n");
return ret;
}
if (intel_dsi->ports & (1 << PORT_A))
config->dsi_pll.ctrl |= DSI_PLL_CLK_GATE_DSI0_DSIPLL;
if (intel_dsi->ports & (1 << PORT_C))
config->dsi_pll.ctrl |= DSI_PLL_CLK_GATE_DSI1_DSIPLL;
config->dsi_pll.ctrl |= DSI_PLL_VCO_EN;
DRM_DEBUG_KMS("dsi pll div %08x, ctrl %08x\n",
config->dsi_pll.div, config->dsi_pll.ctrl);
return 0;
}
static void vlv_enable_dsi_pll(struct intel_encoder *encoder,
const struct intel_crtc_state *config)
{
struct drm_i915_private *dev_priv = to_i915(encoder->base.dev);
DRM_DEBUG_KMS("\n");
mutex_lock(&dev_priv->sb_lock);
vlv_cck_write(dev_priv, CCK_REG_DSI_PLL_CONTROL, 0);
vlv_cck_write(dev_priv, CCK_REG_DSI_PLL_DIVIDER, config->dsi_pll.div);
vlv_cck_write(dev_priv, CCK_REG_DSI_PLL_CONTROL,
config->dsi_pll.ctrl & ~DSI_PLL_VCO_EN);
usleep_range(10, 50);
vlv_cck_write(dev_priv, CCK_REG_DSI_PLL_CONTROL, config->dsi_pll.ctrl);
if (wait_for(vlv_cck_read(dev_priv, CCK_REG_DSI_PLL_CONTROL) &
DSI_PLL_LOCK, 20)) {
mutex_unlock(&dev_priv->sb_lock);
DRM_ERROR("DSI PLL lock failed\n");
return;
}
mutex_unlock(&dev_priv->sb_lock);
DRM_DEBUG_KMS("DSI PLL locked\n");
}
static void vlv_disable_dsi_pll(struct intel_encoder *encoder)
{
struct drm_i915_private *dev_priv = to_i915(encoder->base.dev);
u32 tmp;
DRM_DEBUG_KMS("\n");
mutex_lock(&dev_priv->sb_lock);
tmp = vlv_cck_read(dev_priv, CCK_REG_DSI_PLL_CONTROL);
tmp &= ~DSI_PLL_VCO_EN;
tmp |= DSI_PLL_LDO_GATE;
vlv_cck_write(dev_priv, CCK_REG_DSI_PLL_CONTROL, tmp);
mutex_unlock(&dev_priv->sb_lock);
}
static bool bxt_dsi_pll_is_enabled(struct drm_i915_private *dev_priv)
{
bool enabled;
u32 val;
u32 mask;
mask = BXT_DSI_PLL_DO_ENABLE | BXT_DSI_PLL_LOCKED;
val = I915_READ(BXT_DSI_PLL_ENABLE);
enabled = (val & mask) == mask;
if (!enabled)
return false;
val = I915_READ(BXT_DSI_PLL_CTL);
if (IS_GEMINILAKE(dev_priv)) {
if (!(val & BXT_DSIA_16X_MASK)) {
DRM_DEBUG_DRIVER("Invalid PLL divider (%08x)\n", val);
enabled = false;
}
} else {
if (!(val & BXT_DSIA_16X_MASK) || !(val & BXT_DSIC_16X_MASK)) {
DRM_DEBUG_DRIVER("Invalid PLL divider (%08x)\n", val);
enabled = false;
}
}
return enabled;
}
static void bxt_disable_dsi_pll(struct intel_encoder *encoder)
{
struct drm_i915_private *dev_priv = to_i915(encoder->base.dev);
u32 val;
DRM_DEBUG_KMS("\n");
val = I915_READ(BXT_DSI_PLL_ENABLE);
val &= ~BXT_DSI_PLL_DO_ENABLE;
I915_WRITE(BXT_DSI_PLL_ENABLE, val);
if (intel_wait_for_register(dev_priv,
BXT_DSI_PLL_ENABLE,
BXT_DSI_PLL_LOCKED,
0,
1))
DRM_ERROR("Timeout waiting for PLL lock deassertion\n");
}
static void assert_bpp_mismatch(enum mipi_dsi_pixel_format fmt, int pipe_bpp)
{
int bpp = mipi_dsi_pixel_format_to_bpp(fmt);
WARN(bpp != pipe_bpp,
"bpp match assertion failure (expected %d, current %d)\n",
bpp, pipe_bpp);
}
static u32 vlv_dsi_get_pclk(struct intel_encoder *encoder, int pipe_bpp,
struct intel_crtc_state *config)
{
struct drm_i915_private *dev_priv = to_i915(encoder->base.dev);
struct intel_dsi *intel_dsi = enc_to_intel_dsi(&encoder->base);
u32 dsi_clock, pclk;
u32 pll_ctl, pll_div;
u32 m = 0, p = 0, n;
int refclk = IS_CHERRYVIEW(dev_priv) ? 100000 : 25000;
int i;
DRM_DEBUG_KMS("\n");
mutex_lock(&dev_priv->sb_lock);
pll_ctl = vlv_cck_read(dev_priv, CCK_REG_DSI_PLL_CONTROL);
pll_div = vlv_cck_read(dev_priv, CCK_REG_DSI_PLL_DIVIDER);
mutex_unlock(&dev_priv->sb_lock);
config->dsi_pll.ctrl = pll_ctl & ~DSI_PLL_LOCK;
config->dsi_pll.div = pll_div;
pll_ctl &= DSI_PLL_P1_POST_DIV_MASK;
pll_ctl = pll_ctl >> (DSI_PLL_P1_POST_DIV_SHIFT - 2);
n = (pll_div & DSI_PLL_N1_DIV_MASK) >> DSI_PLL_N1_DIV_SHIFT;
n = 1 << n;
pll_div &= DSI_PLL_M1_DIV_MASK;
pll_div = pll_div >> DSI_PLL_M1_DIV_SHIFT;
while (pll_ctl) {
pll_ctl = pll_ctl >> 1;
p++;
}
p--;
if (!p) {
DRM_ERROR("wrong P1 divisor\n");
return 0;
}
for (i = 0; i < ARRAY_SIZE(lfsr_converts); i++) {
if (lfsr_converts[i] == pll_div)
break;
}
if (i == ARRAY_SIZE(lfsr_converts)) {
DRM_ERROR("wrong m_seed programmed\n");
return 0;
}
m = i + 62;
dsi_clock = (m * refclk) / (p * n);
assert_bpp_mismatch(intel_dsi->pixel_format, pipe_bpp);
pclk = DIV_ROUND_CLOSEST(dsi_clock * intel_dsi->lane_count, pipe_bpp);
return pclk;
}
static u32 bxt_dsi_get_pclk(struct intel_encoder *encoder, int pipe_bpp,
struct intel_crtc_state *config)
{
u32 pclk;
u32 dsi_clk;
u32 dsi_ratio;
struct intel_dsi *intel_dsi = enc_to_intel_dsi(&encoder->base);
struct drm_i915_private *dev_priv = to_i915(encoder->base.dev);
if (!pipe_bpp) {
DRM_ERROR("Invalid BPP(0)\n");
return 0;
}
config->dsi_pll.ctrl = I915_READ(BXT_DSI_PLL_CTL);
dsi_ratio = config->dsi_pll.ctrl & BXT_DSI_PLL_RATIO_MASK;
dsi_clk = (dsi_ratio * BXT_REF_CLOCK_KHZ) / 2;
assert_bpp_mismatch(intel_dsi->pixel_format, pipe_bpp);
pclk = DIV_ROUND_CLOSEST(dsi_clk * intel_dsi->lane_count, pipe_bpp);
DRM_DEBUG_DRIVER("Calculated pclk=%u\n", pclk);
return pclk;
}
u32 intel_dsi_get_pclk(struct intel_encoder *encoder, int pipe_bpp,
struct intel_crtc_state *config)
{
if (IS_GEN9_LP(to_i915(encoder->base.dev)))
return bxt_dsi_get_pclk(encoder, pipe_bpp, config);
else
return vlv_dsi_get_pclk(encoder, pipe_bpp, config);
}
static void vlv_dsi_reset_clocks(struct intel_encoder *encoder, enum port port)
{
u32 temp;
struct drm_i915_private *dev_priv = to_i915(encoder->base.dev);
struct intel_dsi *intel_dsi = enc_to_intel_dsi(&encoder->base);
temp = I915_READ(MIPI_CTRL(port));
temp &= ~ESCAPE_CLOCK_DIVIDER_MASK;
I915_WRITE(MIPI_CTRL(port), temp |
intel_dsi->escape_clk_div <<
ESCAPE_CLOCK_DIVIDER_SHIFT);
}
static void glk_dsi_program_esc_clock(struct drm_device *dev,
const struct intel_crtc_state *config)
{
struct drm_i915_private *dev_priv = to_i915(dev);
u32 dsi_rate = 0;
u32 pll_ratio = 0;
u32 ddr_clk = 0;
u32 div1_value = 0;
u32 div2_value = 0;
u32 txesc1_div = 0;
u32 txesc2_div = 0;
pll_ratio = config->dsi_pll.ctrl & BXT_DSI_PLL_RATIO_MASK;
dsi_rate = (BXT_REF_CLOCK_KHZ * pll_ratio) / 2;
ddr_clk = dsi_rate / 2;
div1_value = DIV_ROUND_CLOSEST(ddr_clk, 20000);
if (div1_value <= 10)
txesc1_div = div1_value;
else if ((div1_value > 10) && (div1_value <= 20))
txesc1_div = DIV_ROUND_UP(div1_value, 2);
else if ((div1_value > 20) && (div1_value <= 30))
txesc1_div = DIV_ROUND_UP(div1_value, 4);
else if ((div1_value > 30) && (div1_value <= 40))
txesc1_div = DIV_ROUND_UP(div1_value, 6);
else if ((div1_value > 40) && (div1_value <= 50))
txesc1_div = DIV_ROUND_UP(div1_value, 8);
else
txesc1_div = 10;
div2_value = DIV_ROUND_UP(div1_value, txesc1_div);
if (div2_value < 10)
txesc2_div = div2_value;
else
txesc2_div = 10;
I915_WRITE(MIPIO_TXESC_CLK_DIV1, txesc1_div & GLK_TX_ESC_CLK_DIV1_MASK);
I915_WRITE(MIPIO_TXESC_CLK_DIV2, txesc2_div & GLK_TX_ESC_CLK_DIV2_MASK);
}
static void bxt_dsi_program_clocks(struct drm_device *dev, enum port port,
const struct intel_crtc_state *config)
{
struct drm_i915_private *dev_priv = to_i915(dev);
u32 tmp;
u32 dsi_rate = 0;
u32 pll_ratio = 0;
u32 rx_div;
u32 tx_div;
u32 rx_div_upper;
u32 rx_div_lower;
u32 mipi_8by3_divider;
tmp = I915_READ(BXT_MIPI_CLOCK_CTL);
tmp &= ~(BXT_MIPI_TX_ESCLK_FIXDIV_MASK(port));
tmp &= ~(BXT_MIPI_RX_ESCLK_UPPER_FIXDIV_MASK(port));
tmp &= ~(BXT_MIPI_8X_BY3_DIVIDER_MASK(port));
tmp &= ~(BXT_MIPI_RX_ESCLK_LOWER_FIXDIV_MASK(port));
pll_ratio = config->dsi_pll.ctrl & BXT_DSI_PLL_RATIO_MASK;
dsi_rate = (BXT_REF_CLOCK_KHZ * pll_ratio) / 2;
tx_div = DIV_ROUND_UP(dsi_rate, 20000) - 1;
rx_div = DIV_ROUND_UP(dsi_rate, 150000) - 1;
rx_div_lower = rx_div & RX_DIVIDER_BIT_1_2;
rx_div_upper = (rx_div & RX_DIVIDER_BIT_3_4) >> 2;
mipi_8by3_divider = 0x2;
tmp |= BXT_MIPI_8X_BY3_DIVIDER(port, mipi_8by3_divider);
tmp |= BXT_MIPI_TX_ESCLK_DIVIDER(port, tx_div);
tmp |= BXT_MIPI_RX_ESCLK_LOWER_DIVIDER(port, rx_div_lower);
tmp |= BXT_MIPI_RX_ESCLK_UPPER_DIVIDER(port, rx_div_upper);
I915_WRITE(BXT_MIPI_CLOCK_CTL, tmp);
}
static int gen9lp_compute_dsi_pll(struct intel_encoder *encoder,
struct intel_crtc_state *config)
{
struct drm_i915_private *dev_priv = to_i915(encoder->base.dev);
struct intel_dsi *intel_dsi = enc_to_intel_dsi(&encoder->base);
u8 dsi_ratio, dsi_ratio_min, dsi_ratio_max;
u32 dsi_clk;
dsi_clk = dsi_clk_from_pclk(intel_dsi->pclk, intel_dsi->pixel_format,
intel_dsi->lane_count);
dsi_ratio = DIV_ROUND_UP(dsi_clk * 2, BXT_REF_CLOCK_KHZ);
if (IS_BROXTON(dev_priv)) {
dsi_ratio_min = BXT_DSI_PLL_RATIO_MIN;
dsi_ratio_max = BXT_DSI_PLL_RATIO_MAX;
} else {
dsi_ratio_min = GLK_DSI_PLL_RATIO_MIN;
dsi_ratio_max = GLK_DSI_PLL_RATIO_MAX;
}
if (dsi_ratio < dsi_ratio_min || dsi_ratio > dsi_ratio_max) {
DRM_ERROR("Cant get a suitable ratio from DSI PLL ratios\n");
return -ECHRNG;
} else
DRM_DEBUG_KMS("DSI PLL calculation is Done!!\n");
config->dsi_pll.ctrl = dsi_ratio | BXT_DSIA_16X_BY2 | BXT_DSIC_16X_BY2;
if (IS_BROXTON(dev_priv) && dsi_ratio <= 50)
config->dsi_pll.ctrl |= BXT_DSI_PLL_PVD_RATIO_1;
return 0;
}
static void gen9lp_enable_dsi_pll(struct intel_encoder *encoder,
const struct intel_crtc_state *config)
{
struct drm_i915_private *dev_priv = to_i915(encoder->base.dev);
struct intel_dsi *intel_dsi = enc_to_intel_dsi(&encoder->base);
enum port port;
u32 val;
DRM_DEBUG_KMS("\n");
I915_WRITE(BXT_DSI_PLL_CTL, config->dsi_pll.ctrl);
POSTING_READ(BXT_DSI_PLL_CTL);
if (IS_BROXTON(dev_priv)) {
for_each_dsi_port(port, intel_dsi->ports)
bxt_dsi_program_clocks(encoder->base.dev, port, config);
} else {
glk_dsi_program_esc_clock(encoder->base.dev, config);
}
val = I915_READ(BXT_DSI_PLL_ENABLE);
val |= BXT_DSI_PLL_DO_ENABLE;
I915_WRITE(BXT_DSI_PLL_ENABLE, val);
if (intel_wait_for_register(dev_priv,
BXT_DSI_PLL_ENABLE,
BXT_DSI_PLL_LOCKED,
BXT_DSI_PLL_LOCKED,
1)) {
DRM_ERROR("Timed out waiting for DSI PLL to lock\n");
return;
}
DRM_DEBUG_KMS("DSI PLL locked\n");
}
bool intel_dsi_pll_is_enabled(struct drm_i915_private *dev_priv)
{
if (IS_GEN9_LP(dev_priv))
return bxt_dsi_pll_is_enabled(dev_priv);
MISSING_CASE(INTEL_DEVID(dev_priv));
return false;
}
int intel_compute_dsi_pll(struct intel_encoder *encoder,
struct intel_crtc_state *config)
{
struct drm_i915_private *dev_priv = to_i915(encoder->base.dev);
if (IS_VALLEYVIEW(dev_priv) || IS_CHERRYVIEW(dev_priv))
return vlv_compute_dsi_pll(encoder, config);
else if (IS_GEN9_LP(dev_priv))
return gen9lp_compute_dsi_pll(encoder, config);
return -ENODEV;
}
void intel_enable_dsi_pll(struct intel_encoder *encoder,
const struct intel_crtc_state *config)
{
struct drm_i915_private *dev_priv = to_i915(encoder->base.dev);
if (IS_VALLEYVIEW(dev_priv) || IS_CHERRYVIEW(dev_priv))
vlv_enable_dsi_pll(encoder, config);
else if (IS_GEN9_LP(dev_priv))
gen9lp_enable_dsi_pll(encoder, config);
}
void intel_disable_dsi_pll(struct intel_encoder *encoder)
{
struct drm_i915_private *dev_priv = to_i915(encoder->base.dev);
if (IS_VALLEYVIEW(dev_priv) || IS_CHERRYVIEW(dev_priv))
vlv_disable_dsi_pll(encoder);
else if (IS_GEN9_LP(dev_priv))
bxt_disable_dsi_pll(encoder);
}
static void gen9lp_dsi_reset_clocks(struct intel_encoder *encoder,
enum port port)
{
u32 tmp;
struct drm_device *dev = encoder->base.dev;
struct drm_i915_private *dev_priv = to_i915(dev);
if (IS_BROXTON(dev_priv)) {
tmp = I915_READ(BXT_MIPI_CLOCK_CTL);
tmp &= ~(BXT_MIPI_TX_ESCLK_FIXDIV_MASK(port));
tmp &= ~(BXT_MIPI_RX_ESCLK_UPPER_FIXDIV_MASK(port));
tmp &= ~(BXT_MIPI_8X_BY3_DIVIDER_MASK(port));
tmp &= ~(BXT_MIPI_RX_ESCLK_LOWER_FIXDIV_MASK(port));
I915_WRITE(BXT_MIPI_CLOCK_CTL, tmp);
} else {
tmp = I915_READ(MIPIO_TXESC_CLK_DIV1);
tmp &= ~GLK_TX_ESC_CLK_DIV1_MASK;
I915_WRITE(MIPIO_TXESC_CLK_DIV1, tmp);
tmp = I915_READ(MIPIO_TXESC_CLK_DIV2);
tmp &= ~GLK_TX_ESC_CLK_DIV2_MASK;
I915_WRITE(MIPIO_TXESC_CLK_DIV2, tmp);
}
I915_WRITE(MIPI_EOT_DISABLE(port), CLOCKSTOP);
}
void intel_dsi_reset_clocks(struct intel_encoder *encoder, enum port port)
{
struct drm_i915_private *dev_priv = to_i915(encoder->base.dev);
if (IS_GEN9_LP(dev_priv))
gen9lp_dsi_reset_clocks(encoder, port);
else if (IS_VALLEYVIEW(dev_priv) || IS_CHERRYVIEW(dev_priv))
vlv_dsi_reset_clocks(encoder, port);
}
