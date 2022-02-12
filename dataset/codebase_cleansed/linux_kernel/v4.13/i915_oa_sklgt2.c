static int
get_render_basic_mux_config(struct drm_i915_private *dev_priv,
const struct i915_oa_reg **regs,
int *lens)
{
int n = 0;
BUILD_BUG_ON(ARRAY_SIZE(dev_priv->perf.oa.mux_regs) < 1);
BUILD_BUG_ON(ARRAY_SIZE(dev_priv->perf.oa.mux_regs_lens) < 1);
if (dev_priv->drm.pdev->revision >= 0x02) {
regs[n] = mux_config_render_basic_1_sku_gte_0x02;
lens[n] = ARRAY_SIZE(mux_config_render_basic_1_sku_gte_0x02);
n++;
}
return n;
}
static int
get_compute_basic_mux_config(struct drm_i915_private *dev_priv,
const struct i915_oa_reg **regs,
int *lens)
{
int n = 0;
BUILD_BUG_ON(ARRAY_SIZE(dev_priv->perf.oa.mux_regs) < 2);
BUILD_BUG_ON(ARRAY_SIZE(dev_priv->perf.oa.mux_regs_lens) < 2);
if ((INTEL_INFO(dev_priv)->sseu.slice_mask & 0x01) &&
(dev_priv->drm.pdev->revision < 0x02)) {
regs[n] = mux_config_compute_basic_0_slices_0x01_and_sku_lt_0x02;
lens[n] = ARRAY_SIZE(mux_config_compute_basic_0_slices_0x01_and_sku_lt_0x02);
n++;
}
if ((INTEL_INFO(dev_priv)->sseu.slice_mask & 0x01) &&
(dev_priv->drm.pdev->revision >= 0x02)) {
regs[n] = mux_config_compute_basic_0_slices_0x01_and_sku_gte_0x02;
lens[n] = ARRAY_SIZE(mux_config_compute_basic_0_slices_0x01_and_sku_gte_0x02);
n++;
}
return n;
}
static int
get_render_pipe_profile_mux_config(struct drm_i915_private *dev_priv,
const struct i915_oa_reg **regs,
int *lens)
{
int n = 0;
BUILD_BUG_ON(ARRAY_SIZE(dev_priv->perf.oa.mux_regs) < 2);
BUILD_BUG_ON(ARRAY_SIZE(dev_priv->perf.oa.mux_regs_lens) < 2);
if (dev_priv->drm.pdev->revision < 0x02) {
regs[n] = mux_config_render_pipe_profile_0_sku_lt_0x02;
lens[n] = ARRAY_SIZE(mux_config_render_pipe_profile_0_sku_lt_0x02);
n++;
}
if (dev_priv->drm.pdev->revision >= 0x02) {
regs[n] = mux_config_render_pipe_profile_0_sku_gte_0x02;
lens[n] = ARRAY_SIZE(mux_config_render_pipe_profile_0_sku_gte_0x02);
n++;
}
return n;
}
static int
get_memory_reads_mux_config(struct drm_i915_private *dev_priv,
const struct i915_oa_reg **regs,
int *lens)
{
int n = 0;
BUILD_BUG_ON(ARRAY_SIZE(dev_priv->perf.oa.mux_regs) < 3);
BUILD_BUG_ON(ARRAY_SIZE(dev_priv->perf.oa.mux_regs_lens) < 3);
if ((INTEL_INFO(dev_priv)->sseu.slice_mask & 0x01) &&
(dev_priv->drm.pdev->revision < 0x02)) {
regs[n] = mux_config_memory_reads_0_slices_0x01_and_sku_lt_0x02;
lens[n] = ARRAY_SIZE(mux_config_memory_reads_0_slices_0x01_and_sku_lt_0x02);
n++;
}
if ((dev_priv->drm.pdev->revision < 0x05) &&
(dev_priv->drm.pdev->revision >= 0x02)) {
regs[n] = mux_config_memory_reads_0_sku_lt_0x05_and_sku_gte_0x02;
lens[n] = ARRAY_SIZE(mux_config_memory_reads_0_sku_lt_0x05_and_sku_gte_0x02);
n++;
}
if (dev_priv->drm.pdev->revision >= 0x05) {
regs[n] = mux_config_memory_reads_0_sku_gte_0x05;
lens[n] = ARRAY_SIZE(mux_config_memory_reads_0_sku_gte_0x05);
n++;
}
return n;
}
static int
get_memory_writes_mux_config(struct drm_i915_private *dev_priv,
const struct i915_oa_reg **regs,
int *lens)
{
int n = 0;
BUILD_BUG_ON(ARRAY_SIZE(dev_priv->perf.oa.mux_regs) < 3);
BUILD_BUG_ON(ARRAY_SIZE(dev_priv->perf.oa.mux_regs_lens) < 3);
if ((INTEL_INFO(dev_priv)->sseu.slice_mask & 0x01) &&
(dev_priv->drm.pdev->revision < 0x02)) {
regs[n] = mux_config_memory_writes_0_slices_0x01_and_sku_lt_0x02;
lens[n] = ARRAY_SIZE(mux_config_memory_writes_0_slices_0x01_and_sku_lt_0x02);
n++;
}
if ((dev_priv->drm.pdev->revision < 0x05) &&
(dev_priv->drm.pdev->revision >= 0x02)) {
regs[n] = mux_config_memory_writes_0_sku_lt_0x05_and_sku_gte_0x02;
lens[n] = ARRAY_SIZE(mux_config_memory_writes_0_sku_lt_0x05_and_sku_gte_0x02);
n++;
}
if (dev_priv->drm.pdev->revision >= 0x05) {
regs[n] = mux_config_memory_writes_0_sku_gte_0x05;
lens[n] = ARRAY_SIZE(mux_config_memory_writes_0_sku_gte_0x05);
n++;
}
return n;
}
static int
get_compute_extended_mux_config(struct drm_i915_private *dev_priv,
const struct i915_oa_reg **regs,
int *lens)
{
int n = 0;
BUILD_BUG_ON(ARRAY_SIZE(dev_priv->perf.oa.mux_regs) < 1);
BUILD_BUG_ON(ARRAY_SIZE(dev_priv->perf.oa.mux_regs_lens) < 1);
if (INTEL_INFO(dev_priv)->sseu.subslice_mask & 0x01) {
regs[n] = mux_config_compute_extended_0_subslices_0x01;
lens[n] = ARRAY_SIZE(mux_config_compute_extended_0_subslices_0x01);
n++;
}
return n;
}
static int
get_compute_l3_cache_mux_config(struct drm_i915_private *dev_priv,
const struct i915_oa_reg **regs,
int *lens)
{
int n = 0;
BUILD_BUG_ON(ARRAY_SIZE(dev_priv->perf.oa.mux_regs) < 1);
BUILD_BUG_ON(ARRAY_SIZE(dev_priv->perf.oa.mux_regs_lens) < 1);
regs[n] = mux_config_compute_l3_cache;
lens[n] = ARRAY_SIZE(mux_config_compute_l3_cache);
n++;
return n;
}
static int
get_hdc_and_sf_mux_config(struct drm_i915_private *dev_priv,
const struct i915_oa_reg **regs,
int *lens)
{
int n = 0;
BUILD_BUG_ON(ARRAY_SIZE(dev_priv->perf.oa.mux_regs) < 1);
BUILD_BUG_ON(ARRAY_SIZE(dev_priv->perf.oa.mux_regs_lens) < 1);
regs[n] = mux_config_hdc_and_sf;
lens[n] = ARRAY_SIZE(mux_config_hdc_and_sf);
n++;
return n;
}
static int
get_l3_1_mux_config(struct drm_i915_private *dev_priv,
const struct i915_oa_reg **regs,
int *lens)
{
int n = 0;
BUILD_BUG_ON(ARRAY_SIZE(dev_priv->perf.oa.mux_regs) < 1);
BUILD_BUG_ON(ARRAY_SIZE(dev_priv->perf.oa.mux_regs_lens) < 1);
regs[n] = mux_config_l3_1;
lens[n] = ARRAY_SIZE(mux_config_l3_1);
n++;
return n;
}
static int
get_l3_2_mux_config(struct drm_i915_private *dev_priv,
const struct i915_oa_reg **regs,
int *lens)
{
int n = 0;
BUILD_BUG_ON(ARRAY_SIZE(dev_priv->perf.oa.mux_regs) < 1);
BUILD_BUG_ON(ARRAY_SIZE(dev_priv->perf.oa.mux_regs_lens) < 1);
regs[n] = mux_config_l3_2;
lens[n] = ARRAY_SIZE(mux_config_l3_2);
n++;
return n;
}
static int
get_l3_3_mux_config(struct drm_i915_private *dev_priv,
const struct i915_oa_reg **regs,
int *lens)
{
int n = 0;
BUILD_BUG_ON(ARRAY_SIZE(dev_priv->perf.oa.mux_regs) < 1);
BUILD_BUG_ON(ARRAY_SIZE(dev_priv->perf.oa.mux_regs_lens) < 1);
regs[n] = mux_config_l3_3;
lens[n] = ARRAY_SIZE(mux_config_l3_3);
n++;
return n;
}
static int
get_rasterizer_and_pixel_backend_mux_config(struct drm_i915_private *dev_priv,
const struct i915_oa_reg **regs,
int *lens)
{
int n = 0;
BUILD_BUG_ON(ARRAY_SIZE(dev_priv->perf.oa.mux_regs) < 1);
BUILD_BUG_ON(ARRAY_SIZE(dev_priv->perf.oa.mux_regs_lens) < 1);
regs[n] = mux_config_rasterizer_and_pixel_backend;
lens[n] = ARRAY_SIZE(mux_config_rasterizer_and_pixel_backend);
n++;
return n;
}
static int
get_sampler_mux_config(struct drm_i915_private *dev_priv,
const struct i915_oa_reg **regs,
int *lens)
{
int n = 0;
BUILD_BUG_ON(ARRAY_SIZE(dev_priv->perf.oa.mux_regs) < 1);
BUILD_BUG_ON(ARRAY_SIZE(dev_priv->perf.oa.mux_regs_lens) < 1);
regs[n] = mux_config_sampler;
lens[n] = ARRAY_SIZE(mux_config_sampler);
n++;
return n;
}
static int
get_tdl_1_mux_config(struct drm_i915_private *dev_priv,
const struct i915_oa_reg **regs,
int *lens)
{
int n = 0;
BUILD_BUG_ON(ARRAY_SIZE(dev_priv->perf.oa.mux_regs) < 1);
BUILD_BUG_ON(ARRAY_SIZE(dev_priv->perf.oa.mux_regs_lens) < 1);
regs[n] = mux_config_tdl_1;
lens[n] = ARRAY_SIZE(mux_config_tdl_1);
n++;
return n;
}
static int
get_tdl_2_mux_config(struct drm_i915_private *dev_priv,
const struct i915_oa_reg **regs,
int *lens)
{
int n = 0;
BUILD_BUG_ON(ARRAY_SIZE(dev_priv->perf.oa.mux_regs) < 1);
BUILD_BUG_ON(ARRAY_SIZE(dev_priv->perf.oa.mux_regs_lens) < 1);
regs[n] = mux_config_tdl_2;
lens[n] = ARRAY_SIZE(mux_config_tdl_2);
n++;
return n;
}
static int
get_compute_extra_mux_config(struct drm_i915_private *dev_priv,
const struct i915_oa_reg **regs,
int *lens)
{
int n = 0;
BUILD_BUG_ON(ARRAY_SIZE(dev_priv->perf.oa.mux_regs) < 1);
BUILD_BUG_ON(ARRAY_SIZE(dev_priv->perf.oa.mux_regs_lens) < 1);
regs[n] = mux_config_compute_extra;
lens[n] = ARRAY_SIZE(mux_config_compute_extra);
n++;
return n;
}
static int
get_vme_pipe_mux_config(struct drm_i915_private *dev_priv,
const struct i915_oa_reg **regs,
int *lens)
{
int n = 0;
BUILD_BUG_ON(ARRAY_SIZE(dev_priv->perf.oa.mux_regs) < 1);
BUILD_BUG_ON(ARRAY_SIZE(dev_priv->perf.oa.mux_regs_lens) < 1);
regs[n] = mux_config_vme_pipe;
lens[n] = ARRAY_SIZE(mux_config_vme_pipe);
n++;
return n;
}
static int
get_test_oa_mux_config(struct drm_i915_private *dev_priv,
const struct i915_oa_reg **regs,
int *lens)
{
int n = 0;
BUILD_BUG_ON(ARRAY_SIZE(dev_priv->perf.oa.mux_regs) < 1);
BUILD_BUG_ON(ARRAY_SIZE(dev_priv->perf.oa.mux_regs_lens) < 1);
regs[n] = mux_config_test_oa;
lens[n] = ARRAY_SIZE(mux_config_test_oa);
n++;
return n;
}
int i915_oa_select_metric_set_sklgt2(struct drm_i915_private *dev_priv)
{
dev_priv->perf.oa.n_mux_configs = 0;
dev_priv->perf.oa.b_counter_regs = NULL;
dev_priv->perf.oa.b_counter_regs_len = 0;
dev_priv->perf.oa.flex_regs = NULL;
dev_priv->perf.oa.flex_regs_len = 0;
switch (dev_priv->perf.oa.metrics_set) {
case METRIC_SET_ID_RENDER_BASIC:
dev_priv->perf.oa.n_mux_configs =
get_render_basic_mux_config(dev_priv,
dev_priv->perf.oa.mux_regs,
dev_priv->perf.oa.mux_regs_lens);
if (dev_priv->perf.oa.n_mux_configs == 0) {
DRM_DEBUG_DRIVER("No suitable MUX config for \"RENDER_BASIC\" metric set\n");
return -EINVAL;
}
dev_priv->perf.oa.b_counter_regs =
b_counter_config_render_basic;
dev_priv->perf.oa.b_counter_regs_len =
ARRAY_SIZE(b_counter_config_render_basic);
dev_priv->perf.oa.flex_regs =
flex_eu_config_render_basic;
dev_priv->perf.oa.flex_regs_len =
ARRAY_SIZE(flex_eu_config_render_basic);
return 0;
case METRIC_SET_ID_COMPUTE_BASIC:
dev_priv->perf.oa.n_mux_configs =
get_compute_basic_mux_config(dev_priv,
dev_priv->perf.oa.mux_regs,
dev_priv->perf.oa.mux_regs_lens);
if (dev_priv->perf.oa.n_mux_configs == 0) {
DRM_DEBUG_DRIVER("No suitable MUX config for \"COMPUTE_BASIC\" metric set\n");
return -EINVAL;
}
dev_priv->perf.oa.b_counter_regs =
b_counter_config_compute_basic;
dev_priv->perf.oa.b_counter_regs_len =
ARRAY_SIZE(b_counter_config_compute_basic);
dev_priv->perf.oa.flex_regs =
flex_eu_config_compute_basic;
dev_priv->perf.oa.flex_regs_len =
ARRAY_SIZE(flex_eu_config_compute_basic);
return 0;
case METRIC_SET_ID_RENDER_PIPE_PROFILE:
dev_priv->perf.oa.n_mux_configs =
get_render_pipe_profile_mux_config(dev_priv,
dev_priv->perf.oa.mux_regs,
dev_priv->perf.oa.mux_regs_lens);
if (dev_priv->perf.oa.n_mux_configs == 0) {
DRM_DEBUG_DRIVER("No suitable MUX config for \"RENDER_PIPE_PROFILE\" metric set\n");
return -EINVAL;
}
dev_priv->perf.oa.b_counter_regs =
b_counter_config_render_pipe_profile;
dev_priv->perf.oa.b_counter_regs_len =
ARRAY_SIZE(b_counter_config_render_pipe_profile);
dev_priv->perf.oa.flex_regs =
flex_eu_config_render_pipe_profile;
dev_priv->perf.oa.flex_regs_len =
ARRAY_SIZE(flex_eu_config_render_pipe_profile);
return 0;
case METRIC_SET_ID_MEMORY_READS:
dev_priv->perf.oa.n_mux_configs =
get_memory_reads_mux_config(dev_priv,
dev_priv->perf.oa.mux_regs,
dev_priv->perf.oa.mux_regs_lens);
if (dev_priv->perf.oa.n_mux_configs == 0) {
DRM_DEBUG_DRIVER("No suitable MUX config for \"MEMORY_READS\" metric set\n");
return -EINVAL;
}
dev_priv->perf.oa.b_counter_regs =
b_counter_config_memory_reads;
dev_priv->perf.oa.b_counter_regs_len =
ARRAY_SIZE(b_counter_config_memory_reads);
dev_priv->perf.oa.flex_regs =
flex_eu_config_memory_reads;
dev_priv->perf.oa.flex_regs_len =
ARRAY_SIZE(flex_eu_config_memory_reads);
return 0;
case METRIC_SET_ID_MEMORY_WRITES:
dev_priv->perf.oa.n_mux_configs =
get_memory_writes_mux_config(dev_priv,
dev_priv->perf.oa.mux_regs,
dev_priv->perf.oa.mux_regs_lens);
if (dev_priv->perf.oa.n_mux_configs == 0) {
DRM_DEBUG_DRIVER("No suitable MUX config for \"MEMORY_WRITES\" metric set\n");
return -EINVAL;
}
dev_priv->perf.oa.b_counter_regs =
b_counter_config_memory_writes;
dev_priv->perf.oa.b_counter_regs_len =
ARRAY_SIZE(b_counter_config_memory_writes);
dev_priv->perf.oa.flex_regs =
flex_eu_config_memory_writes;
dev_priv->perf.oa.flex_regs_len =
ARRAY_SIZE(flex_eu_config_memory_writes);
return 0;
case METRIC_SET_ID_COMPUTE_EXTENDED:
dev_priv->perf.oa.n_mux_configs =
get_compute_extended_mux_config(dev_priv,
dev_priv->perf.oa.mux_regs,
dev_priv->perf.oa.mux_regs_lens);
if (dev_priv->perf.oa.n_mux_configs == 0) {
DRM_DEBUG_DRIVER("No suitable MUX config for \"COMPUTE_EXTENDED\" metric set\n");
return -EINVAL;
}
dev_priv->perf.oa.b_counter_regs =
b_counter_config_compute_extended;
dev_priv->perf.oa.b_counter_regs_len =
ARRAY_SIZE(b_counter_config_compute_extended);
dev_priv->perf.oa.flex_regs =
flex_eu_config_compute_extended;
dev_priv->perf.oa.flex_regs_len =
ARRAY_SIZE(flex_eu_config_compute_extended);
return 0;
case METRIC_SET_ID_COMPUTE_L3_CACHE:
dev_priv->perf.oa.n_mux_configs =
get_compute_l3_cache_mux_config(dev_priv,
dev_priv->perf.oa.mux_regs,
dev_priv->perf.oa.mux_regs_lens);
if (dev_priv->perf.oa.n_mux_configs == 0) {
DRM_DEBUG_DRIVER("No suitable MUX config for \"COMPUTE_L3_CACHE\" metric set\n");
return -EINVAL;
}
dev_priv->perf.oa.b_counter_regs =
b_counter_config_compute_l3_cache;
dev_priv->perf.oa.b_counter_regs_len =
ARRAY_SIZE(b_counter_config_compute_l3_cache);
dev_priv->perf.oa.flex_regs =
flex_eu_config_compute_l3_cache;
dev_priv->perf.oa.flex_regs_len =
ARRAY_SIZE(flex_eu_config_compute_l3_cache);
return 0;
case METRIC_SET_ID_HDC_AND_SF:
dev_priv->perf.oa.n_mux_configs =
get_hdc_and_sf_mux_config(dev_priv,
dev_priv->perf.oa.mux_regs,
dev_priv->perf.oa.mux_regs_lens);
if (dev_priv->perf.oa.n_mux_configs == 0) {
DRM_DEBUG_DRIVER("No suitable MUX config for \"HDC_AND_SF\" metric set\n");
return -EINVAL;
}
dev_priv->perf.oa.b_counter_regs =
b_counter_config_hdc_and_sf;
dev_priv->perf.oa.b_counter_regs_len =
ARRAY_SIZE(b_counter_config_hdc_and_sf);
dev_priv->perf.oa.flex_regs =
flex_eu_config_hdc_and_sf;
dev_priv->perf.oa.flex_regs_len =
ARRAY_SIZE(flex_eu_config_hdc_and_sf);
return 0;
case METRIC_SET_ID_L3_1:
dev_priv->perf.oa.n_mux_configs =
get_l3_1_mux_config(dev_priv,
dev_priv->perf.oa.mux_regs,
dev_priv->perf.oa.mux_regs_lens);
if (dev_priv->perf.oa.n_mux_configs == 0) {
DRM_DEBUG_DRIVER("No suitable MUX config for \"L3_1\" metric set\n");
return -EINVAL;
}
dev_priv->perf.oa.b_counter_regs =
b_counter_config_l3_1;
dev_priv->perf.oa.b_counter_regs_len =
ARRAY_SIZE(b_counter_config_l3_1);
dev_priv->perf.oa.flex_regs =
flex_eu_config_l3_1;
dev_priv->perf.oa.flex_regs_len =
ARRAY_SIZE(flex_eu_config_l3_1);
return 0;
case METRIC_SET_ID_L3_2:
dev_priv->perf.oa.n_mux_configs =
get_l3_2_mux_config(dev_priv,
dev_priv->perf.oa.mux_regs,
dev_priv->perf.oa.mux_regs_lens);
if (dev_priv->perf.oa.n_mux_configs == 0) {
DRM_DEBUG_DRIVER("No suitable MUX config for \"L3_2\" metric set\n");
return -EINVAL;
}
dev_priv->perf.oa.b_counter_regs =
b_counter_config_l3_2;
dev_priv->perf.oa.b_counter_regs_len =
ARRAY_SIZE(b_counter_config_l3_2);
dev_priv->perf.oa.flex_regs =
flex_eu_config_l3_2;
dev_priv->perf.oa.flex_regs_len =
ARRAY_SIZE(flex_eu_config_l3_2);
return 0;
case METRIC_SET_ID_L3_3:
dev_priv->perf.oa.n_mux_configs =
get_l3_3_mux_config(dev_priv,
dev_priv->perf.oa.mux_regs,
dev_priv->perf.oa.mux_regs_lens);
if (dev_priv->perf.oa.n_mux_configs == 0) {
DRM_DEBUG_DRIVER("No suitable MUX config for \"L3_3\" metric set\n");
return -EINVAL;
}
dev_priv->perf.oa.b_counter_regs =
b_counter_config_l3_3;
dev_priv->perf.oa.b_counter_regs_len =
ARRAY_SIZE(b_counter_config_l3_3);
dev_priv->perf.oa.flex_regs =
flex_eu_config_l3_3;
dev_priv->perf.oa.flex_regs_len =
ARRAY_SIZE(flex_eu_config_l3_3);
return 0;
case METRIC_SET_ID_RASTERIZER_AND_PIXEL_BACKEND:
dev_priv->perf.oa.n_mux_configs =
get_rasterizer_and_pixel_backend_mux_config(dev_priv,
dev_priv->perf.oa.mux_regs,
dev_priv->perf.oa.mux_regs_lens);
if (dev_priv->perf.oa.n_mux_configs == 0) {
DRM_DEBUG_DRIVER("No suitable MUX config for \"RASTERIZER_AND_PIXEL_BACKEND\" metric set\n");
return -EINVAL;
}
dev_priv->perf.oa.b_counter_regs =
b_counter_config_rasterizer_and_pixel_backend;
dev_priv->perf.oa.b_counter_regs_len =
ARRAY_SIZE(b_counter_config_rasterizer_and_pixel_backend);
dev_priv->perf.oa.flex_regs =
flex_eu_config_rasterizer_and_pixel_backend;
dev_priv->perf.oa.flex_regs_len =
ARRAY_SIZE(flex_eu_config_rasterizer_and_pixel_backend);
return 0;
case METRIC_SET_ID_SAMPLER:
dev_priv->perf.oa.n_mux_configs =
get_sampler_mux_config(dev_priv,
dev_priv->perf.oa.mux_regs,
dev_priv->perf.oa.mux_regs_lens);
if (dev_priv->perf.oa.n_mux_configs == 0) {
DRM_DEBUG_DRIVER("No suitable MUX config for \"SAMPLER\" metric set\n");
return -EINVAL;
}
dev_priv->perf.oa.b_counter_regs =
b_counter_config_sampler;
dev_priv->perf.oa.b_counter_regs_len =
ARRAY_SIZE(b_counter_config_sampler);
dev_priv->perf.oa.flex_regs =
flex_eu_config_sampler;
dev_priv->perf.oa.flex_regs_len =
ARRAY_SIZE(flex_eu_config_sampler);
return 0;
case METRIC_SET_ID_TDL_1:
dev_priv->perf.oa.n_mux_configs =
get_tdl_1_mux_config(dev_priv,
dev_priv->perf.oa.mux_regs,
dev_priv->perf.oa.mux_regs_lens);
if (dev_priv->perf.oa.n_mux_configs == 0) {
DRM_DEBUG_DRIVER("No suitable MUX config for \"TDL_1\" metric set\n");
return -EINVAL;
}
dev_priv->perf.oa.b_counter_regs =
b_counter_config_tdl_1;
dev_priv->perf.oa.b_counter_regs_len =
ARRAY_SIZE(b_counter_config_tdl_1);
dev_priv->perf.oa.flex_regs =
flex_eu_config_tdl_1;
dev_priv->perf.oa.flex_regs_len =
ARRAY_SIZE(flex_eu_config_tdl_1);
return 0;
case METRIC_SET_ID_TDL_2:
dev_priv->perf.oa.n_mux_configs =
get_tdl_2_mux_config(dev_priv,
dev_priv->perf.oa.mux_regs,
dev_priv->perf.oa.mux_regs_lens);
if (dev_priv->perf.oa.n_mux_configs == 0) {
DRM_DEBUG_DRIVER("No suitable MUX config for \"TDL_2\" metric set\n");
return -EINVAL;
}
dev_priv->perf.oa.b_counter_regs =
b_counter_config_tdl_2;
dev_priv->perf.oa.b_counter_regs_len =
ARRAY_SIZE(b_counter_config_tdl_2);
dev_priv->perf.oa.flex_regs =
flex_eu_config_tdl_2;
dev_priv->perf.oa.flex_regs_len =
ARRAY_SIZE(flex_eu_config_tdl_2);
return 0;
case METRIC_SET_ID_COMPUTE_EXTRA:
dev_priv->perf.oa.n_mux_configs =
get_compute_extra_mux_config(dev_priv,
dev_priv->perf.oa.mux_regs,
dev_priv->perf.oa.mux_regs_lens);
if (dev_priv->perf.oa.n_mux_configs == 0) {
DRM_DEBUG_DRIVER("No suitable MUX config for \"COMPUTE_EXTRA\" metric set\n");
return -EINVAL;
}
dev_priv->perf.oa.b_counter_regs =
b_counter_config_compute_extra;
dev_priv->perf.oa.b_counter_regs_len =
ARRAY_SIZE(b_counter_config_compute_extra);
dev_priv->perf.oa.flex_regs =
flex_eu_config_compute_extra;
dev_priv->perf.oa.flex_regs_len =
ARRAY_SIZE(flex_eu_config_compute_extra);
return 0;
case METRIC_SET_ID_VME_PIPE:
dev_priv->perf.oa.n_mux_configs =
get_vme_pipe_mux_config(dev_priv,
dev_priv->perf.oa.mux_regs,
dev_priv->perf.oa.mux_regs_lens);
if (dev_priv->perf.oa.n_mux_configs == 0) {
DRM_DEBUG_DRIVER("No suitable MUX config for \"VME_PIPE\" metric set\n");
return -EINVAL;
}
dev_priv->perf.oa.b_counter_regs =
b_counter_config_vme_pipe;
dev_priv->perf.oa.b_counter_regs_len =
ARRAY_SIZE(b_counter_config_vme_pipe);
dev_priv->perf.oa.flex_regs =
flex_eu_config_vme_pipe;
dev_priv->perf.oa.flex_regs_len =
ARRAY_SIZE(flex_eu_config_vme_pipe);
return 0;
case METRIC_SET_ID_TEST_OA:
dev_priv->perf.oa.n_mux_configs =
get_test_oa_mux_config(dev_priv,
dev_priv->perf.oa.mux_regs,
dev_priv->perf.oa.mux_regs_lens);
if (dev_priv->perf.oa.n_mux_configs == 0) {
DRM_DEBUG_DRIVER("No suitable MUX config for \"TEST_OA\" metric set\n");
return -EINVAL;
}
dev_priv->perf.oa.b_counter_regs =
b_counter_config_test_oa;
dev_priv->perf.oa.b_counter_regs_len =
ARRAY_SIZE(b_counter_config_test_oa);
dev_priv->perf.oa.flex_regs =
flex_eu_config_test_oa;
dev_priv->perf.oa.flex_regs_len =
ARRAY_SIZE(flex_eu_config_test_oa);
return 0;
default:
return -ENODEV;
}
}
static ssize_t
show_render_basic_id(struct device *kdev, struct device_attribute *attr, char *buf)
{
return sprintf(buf, "%d\n", METRIC_SET_ID_RENDER_BASIC);
}
static ssize_t
show_compute_basic_id(struct device *kdev, struct device_attribute *attr, char *buf)
{
return sprintf(buf, "%d\n", METRIC_SET_ID_COMPUTE_BASIC);
}
static ssize_t
show_render_pipe_profile_id(struct device *kdev, struct device_attribute *attr, char *buf)
{
return sprintf(buf, "%d\n", METRIC_SET_ID_RENDER_PIPE_PROFILE);
}
static ssize_t
show_memory_reads_id(struct device *kdev, struct device_attribute *attr, char *buf)
{
return sprintf(buf, "%d\n", METRIC_SET_ID_MEMORY_READS);
}
static ssize_t
show_memory_writes_id(struct device *kdev, struct device_attribute *attr, char *buf)
{
return sprintf(buf, "%d\n", METRIC_SET_ID_MEMORY_WRITES);
}
static ssize_t
show_compute_extended_id(struct device *kdev, struct device_attribute *attr, char *buf)
{
return sprintf(buf, "%d\n", METRIC_SET_ID_COMPUTE_EXTENDED);
}
static ssize_t
show_compute_l3_cache_id(struct device *kdev, struct device_attribute *attr, char *buf)
{
return sprintf(buf, "%d\n", METRIC_SET_ID_COMPUTE_L3_CACHE);
}
static ssize_t
show_hdc_and_sf_id(struct device *kdev, struct device_attribute *attr, char *buf)
{
return sprintf(buf, "%d\n", METRIC_SET_ID_HDC_AND_SF);
}
static ssize_t
show_l3_1_id(struct device *kdev, struct device_attribute *attr, char *buf)
{
return sprintf(buf, "%d\n", METRIC_SET_ID_L3_1);
}
static ssize_t
show_l3_2_id(struct device *kdev, struct device_attribute *attr, char *buf)
{
return sprintf(buf, "%d\n", METRIC_SET_ID_L3_2);
}
static ssize_t
show_l3_3_id(struct device *kdev, struct device_attribute *attr, char *buf)
{
return sprintf(buf, "%d\n", METRIC_SET_ID_L3_3);
}
static ssize_t
show_rasterizer_and_pixel_backend_id(struct device *kdev, struct device_attribute *attr, char *buf)
{
return sprintf(buf, "%d\n", METRIC_SET_ID_RASTERIZER_AND_PIXEL_BACKEND);
}
static ssize_t
show_sampler_id(struct device *kdev, struct device_attribute *attr, char *buf)
{
return sprintf(buf, "%d\n", METRIC_SET_ID_SAMPLER);
}
static ssize_t
show_tdl_1_id(struct device *kdev, struct device_attribute *attr, char *buf)
{
return sprintf(buf, "%d\n", METRIC_SET_ID_TDL_1);
}
static ssize_t
show_tdl_2_id(struct device *kdev, struct device_attribute *attr, char *buf)
{
return sprintf(buf, "%d\n", METRIC_SET_ID_TDL_2);
}
static ssize_t
show_compute_extra_id(struct device *kdev, struct device_attribute *attr, char *buf)
{
return sprintf(buf, "%d\n", METRIC_SET_ID_COMPUTE_EXTRA);
}
static ssize_t
show_vme_pipe_id(struct device *kdev, struct device_attribute *attr, char *buf)
{
return sprintf(buf, "%d\n", METRIC_SET_ID_VME_PIPE);
}
static ssize_t
show_test_oa_id(struct device *kdev, struct device_attribute *attr, char *buf)
{
return sprintf(buf, "%d\n", METRIC_SET_ID_TEST_OA);
}
int
i915_perf_register_sysfs_sklgt2(struct drm_i915_private *dev_priv)
{
const struct i915_oa_reg *mux_regs[ARRAY_SIZE(dev_priv->perf.oa.mux_regs)];
int mux_lens[ARRAY_SIZE(dev_priv->perf.oa.mux_regs_lens)];
int ret = 0;
if (get_render_basic_mux_config(dev_priv, mux_regs, mux_lens)) {
ret = sysfs_create_group(dev_priv->perf.metrics_kobj, &group_render_basic);
if (ret)
goto error_render_basic;
}
if (get_compute_basic_mux_config(dev_priv, mux_regs, mux_lens)) {
ret = sysfs_create_group(dev_priv->perf.metrics_kobj, &group_compute_basic);
if (ret)
goto error_compute_basic;
}
if (get_render_pipe_profile_mux_config(dev_priv, mux_regs, mux_lens)) {
ret = sysfs_create_group(dev_priv->perf.metrics_kobj, &group_render_pipe_profile);
if (ret)
goto error_render_pipe_profile;
}
if (get_memory_reads_mux_config(dev_priv, mux_regs, mux_lens)) {
ret = sysfs_create_group(dev_priv->perf.metrics_kobj, &group_memory_reads);
if (ret)
goto error_memory_reads;
}
if (get_memory_writes_mux_config(dev_priv, mux_regs, mux_lens)) {
ret = sysfs_create_group(dev_priv->perf.metrics_kobj, &group_memory_writes);
if (ret)
goto error_memory_writes;
}
if (get_compute_extended_mux_config(dev_priv, mux_regs, mux_lens)) {
ret = sysfs_create_group(dev_priv->perf.metrics_kobj, &group_compute_extended);
if (ret)
goto error_compute_extended;
}
if (get_compute_l3_cache_mux_config(dev_priv, mux_regs, mux_lens)) {
ret = sysfs_create_group(dev_priv->perf.metrics_kobj, &group_compute_l3_cache);
if (ret)
goto error_compute_l3_cache;
}
if (get_hdc_and_sf_mux_config(dev_priv, mux_regs, mux_lens)) {
ret = sysfs_create_group(dev_priv->perf.metrics_kobj, &group_hdc_and_sf);
if (ret)
goto error_hdc_and_sf;
}
if (get_l3_1_mux_config(dev_priv, mux_regs, mux_lens)) {
ret = sysfs_create_group(dev_priv->perf.metrics_kobj, &group_l3_1);
if (ret)
goto error_l3_1;
}
if (get_l3_2_mux_config(dev_priv, mux_regs, mux_lens)) {
ret = sysfs_create_group(dev_priv->perf.metrics_kobj, &group_l3_2);
if (ret)
goto error_l3_2;
}
if (get_l3_3_mux_config(dev_priv, mux_regs, mux_lens)) {
ret = sysfs_create_group(dev_priv->perf.metrics_kobj, &group_l3_3);
if (ret)
goto error_l3_3;
}
if (get_rasterizer_and_pixel_backend_mux_config(dev_priv, mux_regs, mux_lens)) {
ret = sysfs_create_group(dev_priv->perf.metrics_kobj, &group_rasterizer_and_pixel_backend);
if (ret)
goto error_rasterizer_and_pixel_backend;
}
if (get_sampler_mux_config(dev_priv, mux_regs, mux_lens)) {
ret = sysfs_create_group(dev_priv->perf.metrics_kobj, &group_sampler);
if (ret)
goto error_sampler;
}
if (get_tdl_1_mux_config(dev_priv, mux_regs, mux_lens)) {
ret = sysfs_create_group(dev_priv->perf.metrics_kobj, &group_tdl_1);
if (ret)
goto error_tdl_1;
}
if (get_tdl_2_mux_config(dev_priv, mux_regs, mux_lens)) {
ret = sysfs_create_group(dev_priv->perf.metrics_kobj, &group_tdl_2);
if (ret)
goto error_tdl_2;
}
if (get_compute_extra_mux_config(dev_priv, mux_regs, mux_lens)) {
ret = sysfs_create_group(dev_priv->perf.metrics_kobj, &group_compute_extra);
if (ret)
goto error_compute_extra;
}
if (get_vme_pipe_mux_config(dev_priv, mux_regs, mux_lens)) {
ret = sysfs_create_group(dev_priv->perf.metrics_kobj, &group_vme_pipe);
if (ret)
goto error_vme_pipe;
}
if (get_test_oa_mux_config(dev_priv, mux_regs, mux_lens)) {
ret = sysfs_create_group(dev_priv->perf.metrics_kobj, &group_test_oa);
if (ret)
goto error_test_oa;
}
return 0;
error_test_oa:
if (get_vme_pipe_mux_config(dev_priv, mux_regs, mux_lens))
sysfs_remove_group(dev_priv->perf.metrics_kobj, &group_vme_pipe);
error_vme_pipe:
if (get_compute_extra_mux_config(dev_priv, mux_regs, mux_lens))
sysfs_remove_group(dev_priv->perf.metrics_kobj, &group_compute_extra);
error_compute_extra:
if (get_tdl_2_mux_config(dev_priv, mux_regs, mux_lens))
sysfs_remove_group(dev_priv->perf.metrics_kobj, &group_tdl_2);
error_tdl_2:
if (get_tdl_1_mux_config(dev_priv, mux_regs, mux_lens))
sysfs_remove_group(dev_priv->perf.metrics_kobj, &group_tdl_1);
error_tdl_1:
if (get_sampler_mux_config(dev_priv, mux_regs, mux_lens))
sysfs_remove_group(dev_priv->perf.metrics_kobj, &group_sampler);
error_sampler:
if (get_rasterizer_and_pixel_backend_mux_config(dev_priv, mux_regs, mux_lens))
sysfs_remove_group(dev_priv->perf.metrics_kobj, &group_rasterizer_and_pixel_backend);
error_rasterizer_and_pixel_backend:
if (get_l3_3_mux_config(dev_priv, mux_regs, mux_lens))
sysfs_remove_group(dev_priv->perf.metrics_kobj, &group_l3_3);
error_l3_3:
if (get_l3_2_mux_config(dev_priv, mux_regs, mux_lens))
sysfs_remove_group(dev_priv->perf.metrics_kobj, &group_l3_2);
error_l3_2:
if (get_l3_1_mux_config(dev_priv, mux_regs, mux_lens))
sysfs_remove_group(dev_priv->perf.metrics_kobj, &group_l3_1);
error_l3_1:
if (get_hdc_and_sf_mux_config(dev_priv, mux_regs, mux_lens))
sysfs_remove_group(dev_priv->perf.metrics_kobj, &group_hdc_and_sf);
error_hdc_and_sf:
if (get_compute_l3_cache_mux_config(dev_priv, mux_regs, mux_lens))
sysfs_remove_group(dev_priv->perf.metrics_kobj, &group_compute_l3_cache);
error_compute_l3_cache:
if (get_compute_extended_mux_config(dev_priv, mux_regs, mux_lens))
sysfs_remove_group(dev_priv->perf.metrics_kobj, &group_compute_extended);
error_compute_extended:
if (get_memory_writes_mux_config(dev_priv, mux_regs, mux_lens))
sysfs_remove_group(dev_priv->perf.metrics_kobj, &group_memory_writes);
error_memory_writes:
if (get_memory_reads_mux_config(dev_priv, mux_regs, mux_lens))
sysfs_remove_group(dev_priv->perf.metrics_kobj, &group_memory_reads);
error_memory_reads:
if (get_render_pipe_profile_mux_config(dev_priv, mux_regs, mux_lens))
sysfs_remove_group(dev_priv->perf.metrics_kobj, &group_render_pipe_profile);
error_render_pipe_profile:
if (get_compute_basic_mux_config(dev_priv, mux_regs, mux_lens))
sysfs_remove_group(dev_priv->perf.metrics_kobj, &group_compute_basic);
error_compute_basic:
if (get_render_basic_mux_config(dev_priv, mux_regs, mux_lens))
sysfs_remove_group(dev_priv->perf.metrics_kobj, &group_render_basic);
error_render_basic:
return ret;
}
void
i915_perf_unregister_sysfs_sklgt2(struct drm_i915_private *dev_priv)
{
const struct i915_oa_reg *mux_regs[ARRAY_SIZE(dev_priv->perf.oa.mux_regs)];
int mux_lens[ARRAY_SIZE(dev_priv->perf.oa.mux_regs_lens)];
if (get_render_basic_mux_config(dev_priv, mux_regs, mux_lens))
sysfs_remove_group(dev_priv->perf.metrics_kobj, &group_render_basic);
if (get_compute_basic_mux_config(dev_priv, mux_regs, mux_lens))
sysfs_remove_group(dev_priv->perf.metrics_kobj, &group_compute_basic);
if (get_render_pipe_profile_mux_config(dev_priv, mux_regs, mux_lens))
sysfs_remove_group(dev_priv->perf.metrics_kobj, &group_render_pipe_profile);
if (get_memory_reads_mux_config(dev_priv, mux_regs, mux_lens))
sysfs_remove_group(dev_priv->perf.metrics_kobj, &group_memory_reads);
if (get_memory_writes_mux_config(dev_priv, mux_regs, mux_lens))
sysfs_remove_group(dev_priv->perf.metrics_kobj, &group_memory_writes);
if (get_compute_extended_mux_config(dev_priv, mux_regs, mux_lens))
sysfs_remove_group(dev_priv->perf.metrics_kobj, &group_compute_extended);
if (get_compute_l3_cache_mux_config(dev_priv, mux_regs, mux_lens))
sysfs_remove_group(dev_priv->perf.metrics_kobj, &group_compute_l3_cache);
if (get_hdc_and_sf_mux_config(dev_priv, mux_regs, mux_lens))
sysfs_remove_group(dev_priv->perf.metrics_kobj, &group_hdc_and_sf);
if (get_l3_1_mux_config(dev_priv, mux_regs, mux_lens))
sysfs_remove_group(dev_priv->perf.metrics_kobj, &group_l3_1);
if (get_l3_2_mux_config(dev_priv, mux_regs, mux_lens))
sysfs_remove_group(dev_priv->perf.metrics_kobj, &group_l3_2);
if (get_l3_3_mux_config(dev_priv, mux_regs, mux_lens))
sysfs_remove_group(dev_priv->perf.metrics_kobj, &group_l3_3);
if (get_rasterizer_and_pixel_backend_mux_config(dev_priv, mux_regs, mux_lens))
sysfs_remove_group(dev_priv->perf.metrics_kobj, &group_rasterizer_and_pixel_backend);
if (get_sampler_mux_config(dev_priv, mux_regs, mux_lens))
sysfs_remove_group(dev_priv->perf.metrics_kobj, &group_sampler);
if (get_tdl_1_mux_config(dev_priv, mux_regs, mux_lens))
sysfs_remove_group(dev_priv->perf.metrics_kobj, &group_tdl_1);
if (get_tdl_2_mux_config(dev_priv, mux_regs, mux_lens))
sysfs_remove_group(dev_priv->perf.metrics_kobj, &group_tdl_2);
if (get_compute_extra_mux_config(dev_priv, mux_regs, mux_lens))
sysfs_remove_group(dev_priv->perf.metrics_kobj, &group_compute_extra);
if (get_vme_pipe_mux_config(dev_priv, mux_regs, mux_lens))
sysfs_remove_group(dev_priv->perf.metrics_kobj, &group_vme_pipe);
if (get_test_oa_mux_config(dev_priv, mux_regs, mux_lens))
sysfs_remove_group(dev_priv->perf.metrics_kobj, &group_test_oa);
}
