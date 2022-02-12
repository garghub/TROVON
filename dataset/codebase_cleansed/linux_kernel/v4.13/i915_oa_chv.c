static int
get_render_basic_mux_config(struct drm_i915_private *dev_priv,
const struct i915_oa_reg **regs,
int *lens)
{
int n = 0;
BUILD_BUG_ON(ARRAY_SIZE(dev_priv->perf.oa.mux_regs) < 1);
BUILD_BUG_ON(ARRAY_SIZE(dev_priv->perf.oa.mux_regs_lens) < 1);
regs[n] = mux_config_render_basic;
lens[n] = ARRAY_SIZE(mux_config_render_basic);
n++;
return n;
}
static int
get_compute_basic_mux_config(struct drm_i915_private *dev_priv,
const struct i915_oa_reg **regs,
int *lens)
{
int n = 0;
BUILD_BUG_ON(ARRAY_SIZE(dev_priv->perf.oa.mux_regs) < 1);
BUILD_BUG_ON(ARRAY_SIZE(dev_priv->perf.oa.mux_regs_lens) < 1);
regs[n] = mux_config_compute_basic;
lens[n] = ARRAY_SIZE(mux_config_compute_basic);
n++;
return n;
}
static int
get_render_pipe_profile_mux_config(struct drm_i915_private *dev_priv,
const struct i915_oa_reg **regs,
int *lens)
{
int n = 0;
BUILD_BUG_ON(ARRAY_SIZE(dev_priv->perf.oa.mux_regs) < 1);
BUILD_BUG_ON(ARRAY_SIZE(dev_priv->perf.oa.mux_regs_lens) < 1);
regs[n] = mux_config_render_pipe_profile;
lens[n] = ARRAY_SIZE(mux_config_render_pipe_profile);
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
get_l3_4_mux_config(struct drm_i915_private *dev_priv,
const struct i915_oa_reg **regs,
int *lens)
{
int n = 0;
BUILD_BUG_ON(ARRAY_SIZE(dev_priv->perf.oa.mux_regs) < 1);
BUILD_BUG_ON(ARRAY_SIZE(dev_priv->perf.oa.mux_regs_lens) < 1);
regs[n] = mux_config_l3_4;
lens[n] = ARRAY_SIZE(mux_config_l3_4);
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
get_sampler_1_mux_config(struct drm_i915_private *dev_priv,
const struct i915_oa_reg **regs,
int *lens)
{
int n = 0;
BUILD_BUG_ON(ARRAY_SIZE(dev_priv->perf.oa.mux_regs) < 1);
BUILD_BUG_ON(ARRAY_SIZE(dev_priv->perf.oa.mux_regs_lens) < 1);
regs[n] = mux_config_sampler_1;
lens[n] = ARRAY_SIZE(mux_config_sampler_1);
n++;
return n;
}
static int
get_sampler_2_mux_config(struct drm_i915_private *dev_priv,
const struct i915_oa_reg **regs,
int *lens)
{
int n = 0;
BUILD_BUG_ON(ARRAY_SIZE(dev_priv->perf.oa.mux_regs) < 1);
BUILD_BUG_ON(ARRAY_SIZE(dev_priv->perf.oa.mux_regs_lens) < 1);
regs[n] = mux_config_sampler_2;
lens[n] = ARRAY_SIZE(mux_config_sampler_2);
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
int i915_oa_select_metric_set_chv(struct drm_i915_private *dev_priv)
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
case METRIC_SET_ID_L3_4:
dev_priv->perf.oa.n_mux_configs =
get_l3_4_mux_config(dev_priv,
dev_priv->perf.oa.mux_regs,
dev_priv->perf.oa.mux_regs_lens);
if (dev_priv->perf.oa.n_mux_configs == 0) {
DRM_DEBUG_DRIVER("No suitable MUX config for \"L3_4\" metric set\n");
return -EINVAL;
}
dev_priv->perf.oa.b_counter_regs =
b_counter_config_l3_4;
dev_priv->perf.oa.b_counter_regs_len =
ARRAY_SIZE(b_counter_config_l3_4);
dev_priv->perf.oa.flex_regs =
flex_eu_config_l3_4;
dev_priv->perf.oa.flex_regs_len =
ARRAY_SIZE(flex_eu_config_l3_4);
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
case METRIC_SET_ID_SAMPLER_1:
dev_priv->perf.oa.n_mux_configs =
get_sampler_1_mux_config(dev_priv,
dev_priv->perf.oa.mux_regs,
dev_priv->perf.oa.mux_regs_lens);
if (dev_priv->perf.oa.n_mux_configs == 0) {
DRM_DEBUG_DRIVER("No suitable MUX config for \"SAMPLER_1\" metric set\n");
return -EINVAL;
}
dev_priv->perf.oa.b_counter_regs =
b_counter_config_sampler_1;
dev_priv->perf.oa.b_counter_regs_len =
ARRAY_SIZE(b_counter_config_sampler_1);
dev_priv->perf.oa.flex_regs =
flex_eu_config_sampler_1;
dev_priv->perf.oa.flex_regs_len =
ARRAY_SIZE(flex_eu_config_sampler_1);
return 0;
case METRIC_SET_ID_SAMPLER_2:
dev_priv->perf.oa.n_mux_configs =
get_sampler_2_mux_config(dev_priv,
dev_priv->perf.oa.mux_regs,
dev_priv->perf.oa.mux_regs_lens);
if (dev_priv->perf.oa.n_mux_configs == 0) {
DRM_DEBUG_DRIVER("No suitable MUX config for \"SAMPLER_2\" metric set\n");
return -EINVAL;
}
dev_priv->perf.oa.b_counter_regs =
b_counter_config_sampler_2;
dev_priv->perf.oa.b_counter_regs_len =
ARRAY_SIZE(b_counter_config_sampler_2);
dev_priv->perf.oa.flex_regs =
flex_eu_config_sampler_2;
dev_priv->perf.oa.flex_regs_len =
ARRAY_SIZE(flex_eu_config_sampler_2);
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
show_l3_4_id(struct device *kdev, struct device_attribute *attr, char *buf)
{
return sprintf(buf, "%d\n", METRIC_SET_ID_L3_4);
}
static ssize_t
show_rasterizer_and_pixel_backend_id(struct device *kdev, struct device_attribute *attr, char *buf)
{
return sprintf(buf, "%d\n", METRIC_SET_ID_RASTERIZER_AND_PIXEL_BACKEND);
}
static ssize_t
show_sampler_1_id(struct device *kdev, struct device_attribute *attr, char *buf)
{
return sprintf(buf, "%d\n", METRIC_SET_ID_SAMPLER_1);
}
static ssize_t
show_sampler_2_id(struct device *kdev, struct device_attribute *attr, char *buf)
{
return sprintf(buf, "%d\n", METRIC_SET_ID_SAMPLER_2);
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
show_test_oa_id(struct device *kdev, struct device_attribute *attr, char *buf)
{
return sprintf(buf, "%d\n", METRIC_SET_ID_TEST_OA);
}
int
i915_perf_register_sysfs_chv(struct drm_i915_private *dev_priv)
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
if (get_l3_4_mux_config(dev_priv, mux_regs, mux_lens)) {
ret = sysfs_create_group(dev_priv->perf.metrics_kobj, &group_l3_4);
if (ret)
goto error_l3_4;
}
if (get_rasterizer_and_pixel_backend_mux_config(dev_priv, mux_regs, mux_lens)) {
ret = sysfs_create_group(dev_priv->perf.metrics_kobj, &group_rasterizer_and_pixel_backend);
if (ret)
goto error_rasterizer_and_pixel_backend;
}
if (get_sampler_1_mux_config(dev_priv, mux_regs, mux_lens)) {
ret = sysfs_create_group(dev_priv->perf.metrics_kobj, &group_sampler_1);
if (ret)
goto error_sampler_1;
}
if (get_sampler_2_mux_config(dev_priv, mux_regs, mux_lens)) {
ret = sysfs_create_group(dev_priv->perf.metrics_kobj, &group_sampler_2);
if (ret)
goto error_sampler_2;
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
if (get_test_oa_mux_config(dev_priv, mux_regs, mux_lens)) {
ret = sysfs_create_group(dev_priv->perf.metrics_kobj, &group_test_oa);
if (ret)
goto error_test_oa;
}
return 0;
error_test_oa:
if (get_tdl_2_mux_config(dev_priv, mux_regs, mux_lens))
sysfs_remove_group(dev_priv->perf.metrics_kobj, &group_tdl_2);
error_tdl_2:
if (get_tdl_1_mux_config(dev_priv, mux_regs, mux_lens))
sysfs_remove_group(dev_priv->perf.metrics_kobj, &group_tdl_1);
error_tdl_1:
if (get_sampler_2_mux_config(dev_priv, mux_regs, mux_lens))
sysfs_remove_group(dev_priv->perf.metrics_kobj, &group_sampler_2);
error_sampler_2:
if (get_sampler_1_mux_config(dev_priv, mux_regs, mux_lens))
sysfs_remove_group(dev_priv->perf.metrics_kobj, &group_sampler_1);
error_sampler_1:
if (get_rasterizer_and_pixel_backend_mux_config(dev_priv, mux_regs, mux_lens))
sysfs_remove_group(dev_priv->perf.metrics_kobj, &group_rasterizer_and_pixel_backend);
error_rasterizer_and_pixel_backend:
if (get_l3_4_mux_config(dev_priv, mux_regs, mux_lens))
sysfs_remove_group(dev_priv->perf.metrics_kobj, &group_l3_4);
error_l3_4:
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
i915_perf_unregister_sysfs_chv(struct drm_i915_private *dev_priv)
{
const struct i915_oa_reg *mux_regs[ARRAY_SIZE(dev_priv->perf.oa.mux_regs)];
int mux_lens[ARRAY_SIZE(dev_priv->perf.oa.mux_regs_lens)];
if (get_render_basic_mux_config(dev_priv, mux_regs, mux_lens))
sysfs_remove_group(dev_priv->perf.metrics_kobj, &group_render_basic);
if (get_compute_basic_mux_config(dev_priv, mux_regs, mux_lens))
sysfs_remove_group(dev_priv->perf.metrics_kobj, &group_compute_basic);
if (get_render_pipe_profile_mux_config(dev_priv, mux_regs, mux_lens))
sysfs_remove_group(dev_priv->perf.metrics_kobj, &group_render_pipe_profile);
if (get_hdc_and_sf_mux_config(dev_priv, mux_regs, mux_lens))
sysfs_remove_group(dev_priv->perf.metrics_kobj, &group_hdc_and_sf);
if (get_l3_1_mux_config(dev_priv, mux_regs, mux_lens))
sysfs_remove_group(dev_priv->perf.metrics_kobj, &group_l3_1);
if (get_l3_2_mux_config(dev_priv, mux_regs, mux_lens))
sysfs_remove_group(dev_priv->perf.metrics_kobj, &group_l3_2);
if (get_l3_3_mux_config(dev_priv, mux_regs, mux_lens))
sysfs_remove_group(dev_priv->perf.metrics_kobj, &group_l3_3);
if (get_l3_4_mux_config(dev_priv, mux_regs, mux_lens))
sysfs_remove_group(dev_priv->perf.metrics_kobj, &group_l3_4);
if (get_rasterizer_and_pixel_backend_mux_config(dev_priv, mux_regs, mux_lens))
sysfs_remove_group(dev_priv->perf.metrics_kobj, &group_rasterizer_and_pixel_backend);
if (get_sampler_1_mux_config(dev_priv, mux_regs, mux_lens))
sysfs_remove_group(dev_priv->perf.metrics_kobj, &group_sampler_1);
if (get_sampler_2_mux_config(dev_priv, mux_regs, mux_lens))
sysfs_remove_group(dev_priv->perf.metrics_kobj, &group_sampler_2);
if (get_tdl_1_mux_config(dev_priv, mux_regs, mux_lens))
sysfs_remove_group(dev_priv->perf.metrics_kobj, &group_tdl_1);
if (get_tdl_2_mux_config(dev_priv, mux_regs, mux_lens))
sysfs_remove_group(dev_priv->perf.metrics_kobj, &group_tdl_2);
if (get_test_oa_mux_config(dev_priv, mux_regs, mux_lens))
sysfs_remove_group(dev_priv->perf.metrics_kobj, &group_test_oa);
}
