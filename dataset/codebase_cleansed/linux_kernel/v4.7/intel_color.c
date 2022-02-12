static bool crtc_state_is_legacy(struct drm_crtc_state *state)
{
return !state->degamma_lut &&
!state->ctm &&
state->gamma_lut &&
state->gamma_lut->length == LEGACY_LUT_LENGTH;
}
static void ctm_mult_by_limited(uint64_t *result, int64_t *input)
{
int i;
for (i = 0; i < 9; i++)
result[i] = 0;
for (i = 0; i < 3; i++) {
int64_t user_coeff = input[i * 3 + i];
uint64_t limited_coeff = CTM_COEFF_LIMITED_RANGE >> 2;
uint64_t abs_coeff = clamp_val(CTM_COEFF_ABS(user_coeff),
0,
CTM_COEFF_4_0 - 1) >> 2;
result[i * 3 + i] = (limited_coeff * abs_coeff) >> 27;
if (CTM_COEFF_NEGATIVE(user_coeff))
result[i * 3 + i] |= CTM_COEFF_SIGN;
}
}
static void i9xx_load_csc_matrix(struct drm_crtc_state *crtc_state)
{
struct drm_crtc *crtc = crtc_state->crtc;
struct drm_device *dev = crtc->dev;
struct drm_i915_private *dev_priv = dev->dev_private;
struct intel_crtc *intel_crtc = to_intel_crtc(crtc);
int i, pipe = intel_crtc->pipe;
uint16_t coeffs[9] = { 0, };
if (crtc_state->ctm) {
struct drm_color_ctm *ctm =
(struct drm_color_ctm *)crtc_state->ctm->data;
uint64_t input[9] = { 0, };
if (intel_crtc->config->limited_color_range) {
ctm_mult_by_limited(input, ctm->matrix);
} else {
for (i = 0; i < ARRAY_SIZE(input); i++)
input[i] = ctm->matrix[i];
}
for (i = 0; i < ARRAY_SIZE(coeffs); i++) {
uint64_t abs_coeff = ((1ULL << 63) - 1) & input[i];
abs_coeff = clamp_val(abs_coeff, 0, CTM_COEFF_4_0 - 1);
if (CTM_COEFF_NEGATIVE(input[i]))
coeffs[i] |= 1 << 15;
if (abs_coeff < CTM_COEFF_0_125)
coeffs[i] |= (3 << 12) |
I9XX_CSC_COEFF_FP(abs_coeff, 12);
else if (abs_coeff < CTM_COEFF_0_25)
coeffs[i] |= (2 << 12) |
I9XX_CSC_COEFF_FP(abs_coeff, 11);
else if (abs_coeff < CTM_COEFF_0_5)
coeffs[i] |= (1 << 12) |
I9XX_CSC_COEFF_FP(abs_coeff, 10);
else if (abs_coeff < CTM_COEFF_1_0)
coeffs[i] |= I9XX_CSC_COEFF_FP(abs_coeff, 9);
else if (abs_coeff < CTM_COEFF_2_0)
coeffs[i] |= (7 << 12) |
I9XX_CSC_COEFF_FP(abs_coeff, 8);
else
coeffs[i] |= (6 << 12) |
I9XX_CSC_COEFF_FP(abs_coeff, 7);
}
} else {
for (i = 0; i < 3; i++) {
if (intel_crtc->config->limited_color_range)
coeffs[i * 3 + i] =
I9XX_CSC_COEFF_LIMITED_RANGE;
else
coeffs[i * 3 + i] = I9XX_CSC_COEFF_1_0;
}
}
I915_WRITE(PIPE_CSC_COEFF_RY_GY(pipe), coeffs[0] << 16 | coeffs[1]);
I915_WRITE(PIPE_CSC_COEFF_BY(pipe), coeffs[2] << 16);
I915_WRITE(PIPE_CSC_COEFF_RU_GU(pipe), coeffs[3] << 16 | coeffs[4]);
I915_WRITE(PIPE_CSC_COEFF_BU(pipe), coeffs[5] << 16);
I915_WRITE(PIPE_CSC_COEFF_RV_GV(pipe), coeffs[6] << 16 | coeffs[7]);
I915_WRITE(PIPE_CSC_COEFF_BV(pipe), coeffs[8] << 16);
I915_WRITE(PIPE_CSC_PREOFF_HI(pipe), 0);
I915_WRITE(PIPE_CSC_PREOFF_ME(pipe), 0);
I915_WRITE(PIPE_CSC_PREOFF_LO(pipe), 0);
if (INTEL_INFO(dev)->gen > 6) {
uint16_t postoff = 0;
if (intel_crtc->config->limited_color_range)
postoff = (16 * (1 << 12) / 255) & 0x1fff;
I915_WRITE(PIPE_CSC_POSTOFF_HI(pipe), postoff);
I915_WRITE(PIPE_CSC_POSTOFF_ME(pipe), postoff);
I915_WRITE(PIPE_CSC_POSTOFF_LO(pipe), postoff);
I915_WRITE(PIPE_CSC_MODE(pipe), 0);
} else {
uint32_t mode = CSC_MODE_YUV_TO_RGB;
if (intel_crtc->config->limited_color_range)
mode |= CSC_BLACK_SCREEN_OFFSET;
I915_WRITE(PIPE_CSC_MODE(pipe), mode);
}
}
static void cherryview_load_csc_matrix(struct drm_crtc_state *state)
{
struct drm_crtc *crtc = state->crtc;
struct drm_device *dev = crtc->dev;
struct drm_i915_private *dev_priv = dev->dev_private;
int pipe = to_intel_crtc(crtc)->pipe;
uint32_t mode;
if (state->ctm) {
struct drm_color_ctm *ctm =
(struct drm_color_ctm *) state->ctm->data;
uint16_t coeffs[9] = { 0, };
int i;
for (i = 0; i < ARRAY_SIZE(coeffs); i++) {
uint64_t abs_coeff =
((1ULL << 63) - 1) & ctm->matrix[i];
abs_coeff += 1 << (32 - 13);
abs_coeff = clamp_val(abs_coeff, 0, CTM_COEFF_8_0 - 1);
if (ctm->matrix[i] & (1ULL << 63))
coeffs[i] = 1 << 15;
coeffs[i] |= ((abs_coeff >> 32) & 7) << 12;
coeffs[i] |= (abs_coeff >> 20) & 0xfff;
}
I915_WRITE(CGM_PIPE_CSC_COEFF01(pipe),
coeffs[1] << 16 | coeffs[0]);
I915_WRITE(CGM_PIPE_CSC_COEFF23(pipe),
coeffs[3] << 16 | coeffs[2]);
I915_WRITE(CGM_PIPE_CSC_COEFF45(pipe),
coeffs[5] << 16 | coeffs[4]);
I915_WRITE(CGM_PIPE_CSC_COEFF67(pipe),
coeffs[7] << 16 | coeffs[6]);
I915_WRITE(CGM_PIPE_CSC_COEFF8(pipe), coeffs[8]);
}
mode = (state->ctm ? CGM_PIPE_MODE_CSC : 0);
if (!crtc_state_is_legacy(state)) {
mode |= (state->degamma_lut ? CGM_PIPE_MODE_DEGAMMA : 0) |
(state->gamma_lut ? CGM_PIPE_MODE_GAMMA : 0);
}
I915_WRITE(CGM_PIPE_MODE(pipe), mode);
}
void intel_color_set_csc(struct drm_crtc_state *crtc_state)
{
struct drm_device *dev = crtc_state->crtc->dev;
struct drm_i915_private *dev_priv = dev->dev_private;
if (dev_priv->display.load_csc_matrix)
dev_priv->display.load_csc_matrix(crtc_state);
}
static void i9xx_load_luts_internal(struct drm_crtc *crtc,
struct drm_property_blob *blob)
{
struct drm_device *dev = crtc->dev;
struct drm_i915_private *dev_priv = dev->dev_private;
struct intel_crtc *intel_crtc = to_intel_crtc(crtc);
enum pipe pipe = intel_crtc->pipe;
int i;
if (HAS_GMCH_DISPLAY(dev)) {
if (intel_crtc->config->has_dsi_encoder)
assert_dsi_pll_enabled(dev_priv);
else
assert_pll_enabled(dev_priv, pipe);
}
if (blob) {
struct drm_color_lut *lut = (struct drm_color_lut *) blob->data;
for (i = 0; i < 256; i++) {
uint32_t word =
(drm_color_lut_extract(lut[i].red, 8) << 16) |
(drm_color_lut_extract(lut[i].green, 8) << 8) |
drm_color_lut_extract(lut[i].blue, 8);
if (HAS_GMCH_DISPLAY(dev))
I915_WRITE(PALETTE(pipe, i), word);
else
I915_WRITE(LGC_PALETTE(pipe, i), word);
}
} else {
for (i = 0; i < 256; i++) {
uint32_t word = (i << 16) | (i << 8) | i;
if (HAS_GMCH_DISPLAY(dev))
I915_WRITE(PALETTE(pipe, i), word);
else
I915_WRITE(LGC_PALETTE(pipe, i), word);
}
}
}
static void i9xx_load_luts(struct drm_crtc_state *crtc_state)
{
i9xx_load_luts_internal(crtc_state->crtc, crtc_state->gamma_lut);
}
static void haswell_load_luts(struct drm_crtc_state *crtc_state)
{
struct drm_crtc *crtc = crtc_state->crtc;
struct drm_device *dev = crtc->dev;
struct drm_i915_private *dev_priv = dev->dev_private;
struct intel_crtc *intel_crtc = to_intel_crtc(crtc);
struct intel_crtc_state *intel_crtc_state =
to_intel_crtc_state(crtc_state);
bool reenable_ips = false;
if (IS_HASWELL(dev) && intel_crtc->config->ips_enabled &&
(intel_crtc_state->gamma_mode == GAMMA_MODE_MODE_SPLIT)) {
hsw_disable_ips(intel_crtc);
reenable_ips = true;
}
intel_crtc_state->gamma_mode = GAMMA_MODE_MODE_8BIT;
I915_WRITE(GAMMA_MODE(intel_crtc->pipe), GAMMA_MODE_MODE_8BIT);
i9xx_load_luts(crtc_state);
if (reenable_ips)
hsw_enable_ips(intel_crtc);
}
static void broadwell_load_luts(struct drm_crtc_state *state)
{
struct drm_crtc *crtc = state->crtc;
struct drm_device *dev = crtc->dev;
struct drm_i915_private *dev_priv = dev->dev_private;
struct intel_crtc_state *intel_state = to_intel_crtc_state(state);
enum pipe pipe = to_intel_crtc(crtc)->pipe;
uint32_t i, lut_size = INTEL_INFO(dev)->color.degamma_lut_size;
if (crtc_state_is_legacy(state)) {
haswell_load_luts(state);
return;
}
I915_WRITE(PREC_PAL_INDEX(pipe),
PAL_PREC_SPLIT_MODE | PAL_PREC_AUTO_INCREMENT);
if (state->degamma_lut) {
struct drm_color_lut *lut =
(struct drm_color_lut *) state->degamma_lut->data;
for (i = 0; i < lut_size; i++) {
uint32_t word =
drm_color_lut_extract(lut[i].red, 10) << 20 |
drm_color_lut_extract(lut[i].green, 10) << 10 |
drm_color_lut_extract(lut[i].blue, 10);
I915_WRITE(PREC_PAL_DATA(pipe), word);
}
} else {
for (i = 0; i < lut_size; i++) {
uint32_t v = (i * ((1 << 10) - 1)) / (lut_size - 1);
I915_WRITE(PREC_PAL_DATA(pipe),
(v << 20) | (v << 10) | v);
}
}
if (state->gamma_lut) {
struct drm_color_lut *lut =
(struct drm_color_lut *) state->gamma_lut->data;
for (i = 0; i < lut_size; i++) {
uint32_t word =
(drm_color_lut_extract(lut[i].red, 10) << 20) |
(drm_color_lut_extract(lut[i].green, 10) << 10) |
drm_color_lut_extract(lut[i].blue, 10);
I915_WRITE(PREC_PAL_DATA(pipe), word);
}
I915_WRITE(PREC_PAL_GC_MAX(pipe, 0),
drm_color_lut_extract(lut[i].red, 16));
I915_WRITE(PREC_PAL_GC_MAX(pipe, 1),
drm_color_lut_extract(lut[i].green, 16));
I915_WRITE(PREC_PAL_GC_MAX(pipe, 2),
drm_color_lut_extract(lut[i].blue, 16));
} else {
for (i = 0; i < lut_size; i++) {
uint32_t v = (i * ((1 << 10) - 1)) / (lut_size - 1);
I915_WRITE(PREC_PAL_DATA(pipe),
(v << 20) | (v << 10) | v);
}
I915_WRITE(PREC_PAL_GC_MAX(pipe, 0), (1 << 16) - 1);
I915_WRITE(PREC_PAL_GC_MAX(pipe, 1), (1 << 16) - 1);
I915_WRITE(PREC_PAL_GC_MAX(pipe, 2), (1 << 16) - 1);
}
intel_state->gamma_mode = GAMMA_MODE_MODE_SPLIT;
I915_WRITE(GAMMA_MODE(pipe), GAMMA_MODE_MODE_SPLIT);
POSTING_READ(GAMMA_MODE(pipe));
I915_WRITE(PREC_PAL_INDEX(pipe), 0);
}
static void cherryview_load_luts(struct drm_crtc_state *state)
{
struct drm_crtc *crtc = state->crtc;
struct drm_device *dev = crtc->dev;
struct drm_i915_private *dev_priv = dev->dev_private;
enum pipe pipe = to_intel_crtc(crtc)->pipe;
struct drm_color_lut *lut;
uint32_t i, lut_size;
uint32_t word0, word1;
if (crtc_state_is_legacy(state)) {
I915_WRITE(CGM_PIPE_MODE(pipe),
(state->ctm ? CGM_PIPE_MODE_CSC : 0));
i9xx_load_luts_internal(crtc, state->gamma_lut);
return;
}
if (state->degamma_lut) {
lut = (struct drm_color_lut *) state->degamma_lut->data;
lut_size = INTEL_INFO(dev)->color.degamma_lut_size;
for (i = 0; i < lut_size; i++) {
word0 =
(drm_color_lut_extract(lut[i].green, 14) << 16) |
drm_color_lut_extract(lut[i].blue, 14);
word1 = drm_color_lut_extract(lut[i].red, 14);
I915_WRITE(CGM_PIPE_DEGAMMA(pipe, i, 0), word0);
I915_WRITE(CGM_PIPE_DEGAMMA(pipe, i, 1), word1);
}
}
if (state->gamma_lut) {
lut = (struct drm_color_lut *) state->gamma_lut->data;
lut_size = INTEL_INFO(dev)->color.gamma_lut_size;
for (i = 0; i < lut_size; i++) {
word0 =
(drm_color_lut_extract(lut[i].green, 10) << 16) |
drm_color_lut_extract(lut[i].blue, 10);
word1 = drm_color_lut_extract(lut[i].red, 10);
I915_WRITE(CGM_PIPE_GAMMA(pipe, i, 0), word0);
I915_WRITE(CGM_PIPE_GAMMA(pipe, i, 1), word1);
}
}
I915_WRITE(CGM_PIPE_MODE(pipe),
(state->ctm ? CGM_PIPE_MODE_CSC : 0) |
(state->degamma_lut ? CGM_PIPE_MODE_DEGAMMA : 0) |
(state->gamma_lut ? CGM_PIPE_MODE_GAMMA : 0));
i9xx_load_luts_internal(crtc, NULL);
}
void intel_color_load_luts(struct drm_crtc_state *crtc_state)
{
struct drm_device *dev = crtc_state->crtc->dev;
struct drm_i915_private *dev_priv = dev->dev_private;
dev_priv->display.load_luts(crtc_state);
}
int intel_color_check(struct drm_crtc *crtc,
struct drm_crtc_state *crtc_state)
{
struct drm_device *dev = crtc->dev;
size_t gamma_length, degamma_length;
degamma_length = INTEL_INFO(dev)->color.degamma_lut_size *
sizeof(struct drm_color_lut);
gamma_length = INTEL_INFO(dev)->color.gamma_lut_size *
sizeof(struct drm_color_lut);
if ((!crtc_state->degamma_lut ||
crtc_state->degamma_lut->length == degamma_length) &&
(!crtc_state->gamma_lut ||
crtc_state->gamma_lut->length == gamma_length))
return 0;
if (!crtc_state->degamma_lut &&
crtc_state->gamma_lut &&
crtc_state->gamma_lut->length == LEGACY_LUT_LENGTH)
return 0;
return -EINVAL;
}
void intel_color_init(struct drm_crtc *crtc)
{
struct drm_device *dev = crtc->dev;
struct drm_i915_private *dev_priv = dev->dev_private;
drm_mode_crtc_set_gamma_size(crtc, 256);
if (IS_CHERRYVIEW(dev)) {
dev_priv->display.load_csc_matrix = cherryview_load_csc_matrix;
dev_priv->display.load_luts = cherryview_load_luts;
} else if (IS_HASWELL(dev)) {
dev_priv->display.load_csc_matrix = i9xx_load_csc_matrix;
dev_priv->display.load_luts = haswell_load_luts;
} else if (IS_BROADWELL(dev) || IS_SKYLAKE(dev) ||
IS_BROXTON(dev) || IS_KABYLAKE(dev)) {
dev_priv->display.load_csc_matrix = i9xx_load_csc_matrix;
dev_priv->display.load_luts = broadwell_load_luts;
} else {
dev_priv->display.load_luts = i9xx_load_luts;
}
if (INTEL_INFO(dev)->color.degamma_lut_size != 0 &&
INTEL_INFO(dev)->color.gamma_lut_size != 0)
drm_helper_crtc_enable_color_mgmt(crtc,
INTEL_INFO(dev)->color.degamma_lut_size,
INTEL_INFO(dev)->color.gamma_lut_size);
}
