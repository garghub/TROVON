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
get_compute_extended_mux_config(struct drm_i915_private *dev_priv,
const struct i915_oa_reg **regs,
int *lens)
{
int n = 0;
BUILD_BUG_ON(ARRAY_SIZE(dev_priv->perf.oa.mux_regs) < 1);
BUILD_BUG_ON(ARRAY_SIZE(dev_priv->perf.oa.mux_regs_lens) < 1);
regs[n] = mux_config_compute_extended;
lens[n] = ARRAY_SIZE(mux_config_compute_extended);
n++;
return n;
}
static int
get_memory_reads_mux_config(struct drm_i915_private *dev_priv,
const struct i915_oa_reg **regs,
int *lens)
{
int n = 0;
BUILD_BUG_ON(ARRAY_SIZE(dev_priv->perf.oa.mux_regs) < 1);
BUILD_BUG_ON(ARRAY_SIZE(dev_priv->perf.oa.mux_regs_lens) < 1);
regs[n] = mux_config_memory_reads;
lens[n] = ARRAY_SIZE(mux_config_memory_reads);
n++;
return n;
}
static int
get_memory_writes_mux_config(struct drm_i915_private *dev_priv,
const struct i915_oa_reg **regs,
int *lens)
{
int n = 0;
BUILD_BUG_ON(ARRAY_SIZE(dev_priv->perf.oa.mux_regs) < 1);
BUILD_BUG_ON(ARRAY_SIZE(dev_priv->perf.oa.mux_regs_lens) < 1);
regs[n] = mux_config_memory_writes;
lens[n] = ARRAY_SIZE(mux_config_memory_writes);
n++;
return n;
}
static int
get_sampler_balance_mux_config(struct drm_i915_private *dev_priv,
const struct i915_oa_reg **regs,
int *lens)
{
int n = 0;
BUILD_BUG_ON(ARRAY_SIZE(dev_priv->perf.oa.mux_regs) < 1);
BUILD_BUG_ON(ARRAY_SIZE(dev_priv->perf.oa.mux_regs_lens) < 1);
regs[n] = mux_config_sampler_balance;
lens[n] = ARRAY_SIZE(mux_config_sampler_balance);
n++;
return n;
}
int i915_oa_select_metric_set_hsw(struct drm_i915_private *dev_priv)
{
dev_priv->perf.oa.n_mux_configs = 0;
dev_priv->perf.oa.b_counter_regs = NULL;
dev_priv->perf.oa.b_counter_regs_len = 0;
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
case METRIC_SET_ID_SAMPLER_BALANCE:
dev_priv->perf.oa.n_mux_configs =
get_sampler_balance_mux_config(dev_priv,
dev_priv->perf.oa.mux_regs,
dev_priv->perf.oa.mux_regs_lens);
if (dev_priv->perf.oa.n_mux_configs == 0) {
DRM_DEBUG_DRIVER("No suitable MUX config for \"SAMPLER_BALANCE\" metric set\n");
return -EINVAL;
}
dev_priv->perf.oa.b_counter_regs =
b_counter_config_sampler_balance;
dev_priv->perf.oa.b_counter_regs_len =
ARRAY_SIZE(b_counter_config_sampler_balance);
dev_priv->perf.oa.flex_regs =
flex_eu_config_sampler_balance;
dev_priv->perf.oa.flex_regs_len =
ARRAY_SIZE(flex_eu_config_sampler_balance);
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
show_compute_extended_id(struct device *kdev, struct device_attribute *attr, char *buf)
{
return sprintf(buf, "%d\n", METRIC_SET_ID_COMPUTE_EXTENDED);
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
show_sampler_balance_id(struct device *kdev, struct device_attribute *attr, char *buf)
{
return sprintf(buf, "%d\n", METRIC_SET_ID_SAMPLER_BALANCE);
}
int
i915_perf_register_sysfs_hsw(struct drm_i915_private *dev_priv)
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
if (get_compute_extended_mux_config(dev_priv, mux_regs, mux_lens)) {
ret = sysfs_create_group(dev_priv->perf.metrics_kobj, &group_compute_extended);
if (ret)
goto error_compute_extended;
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
if (get_sampler_balance_mux_config(dev_priv, mux_regs, mux_lens)) {
ret = sysfs_create_group(dev_priv->perf.metrics_kobj, &group_sampler_balance);
if (ret)
goto error_sampler_balance;
}
return 0;
error_sampler_balance:
if (get_memory_writes_mux_config(dev_priv, mux_regs, mux_lens))
sysfs_remove_group(dev_priv->perf.metrics_kobj, &group_memory_writes);
error_memory_writes:
if (get_memory_reads_mux_config(dev_priv, mux_regs, mux_lens))
sysfs_remove_group(dev_priv->perf.metrics_kobj, &group_memory_reads);
error_memory_reads:
if (get_compute_extended_mux_config(dev_priv, mux_regs, mux_lens))
sysfs_remove_group(dev_priv->perf.metrics_kobj, &group_compute_extended);
error_compute_extended:
if (get_compute_basic_mux_config(dev_priv, mux_regs, mux_lens))
sysfs_remove_group(dev_priv->perf.metrics_kobj, &group_compute_basic);
error_compute_basic:
if (get_render_basic_mux_config(dev_priv, mux_regs, mux_lens))
sysfs_remove_group(dev_priv->perf.metrics_kobj, &group_render_basic);
error_render_basic:
return ret;
}
void
i915_perf_unregister_sysfs_hsw(struct drm_i915_private *dev_priv)
{
const struct i915_oa_reg *mux_regs[ARRAY_SIZE(dev_priv->perf.oa.mux_regs)];
int mux_lens[ARRAY_SIZE(dev_priv->perf.oa.mux_regs_lens)];
if (get_render_basic_mux_config(dev_priv, mux_regs, mux_lens))
sysfs_remove_group(dev_priv->perf.metrics_kobj, &group_render_basic);
if (get_compute_basic_mux_config(dev_priv, mux_regs, mux_lens))
sysfs_remove_group(dev_priv->perf.metrics_kobj, &group_compute_basic);
if (get_compute_extended_mux_config(dev_priv, mux_regs, mux_lens))
sysfs_remove_group(dev_priv->perf.metrics_kobj, &group_compute_extended);
if (get_memory_reads_mux_config(dev_priv, mux_regs, mux_lens))
sysfs_remove_group(dev_priv->perf.metrics_kobj, &group_memory_reads);
if (get_memory_writes_mux_config(dev_priv, mux_regs, mux_lens))
sysfs_remove_group(dev_priv->perf.metrics_kobj, &group_memory_writes);
if (get_sampler_balance_mux_config(dev_priv, mux_regs, mux_lens))
sysfs_remove_group(dev_priv->perf.metrics_kobj, &group_sampler_balance);
}
