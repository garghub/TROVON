static inline struct drm_i915_private *kdev_minor_to_i915(struct device *kdev)
{
struct drm_minor *minor = dev_get_drvdata(kdev);
return to_i915(minor->dev);
}
static u32 calc_residency(struct drm_i915_private *dev_priv,
i915_reg_t reg)
{
return DIV_ROUND_CLOSEST_ULL(intel_rc6_residency_us(dev_priv, reg),
1000);
}
static ssize_t
show_rc6_mask(struct device *kdev, struct device_attribute *attr, char *buf)
{
return snprintf(buf, PAGE_SIZE, "%x\n", intel_enable_rc6());
}
static ssize_t
show_rc6_ms(struct device *kdev, struct device_attribute *attr, char *buf)
{
struct drm_i915_private *dev_priv = kdev_minor_to_i915(kdev);
u32 rc6_residency = calc_residency(dev_priv, GEN6_GT_GFX_RC6);
return snprintf(buf, PAGE_SIZE, "%u\n", rc6_residency);
}
static ssize_t
show_rc6p_ms(struct device *kdev, struct device_attribute *attr, char *buf)
{
struct drm_i915_private *dev_priv = kdev_minor_to_i915(kdev);
u32 rc6p_residency = calc_residency(dev_priv, GEN6_GT_GFX_RC6p);
return snprintf(buf, PAGE_SIZE, "%u\n", rc6p_residency);
}
static ssize_t
show_rc6pp_ms(struct device *kdev, struct device_attribute *attr, char *buf)
{
struct drm_i915_private *dev_priv = kdev_minor_to_i915(kdev);
u32 rc6pp_residency = calc_residency(dev_priv, GEN6_GT_GFX_RC6pp);
return snprintf(buf, PAGE_SIZE, "%u\n", rc6pp_residency);
}
static ssize_t
show_media_rc6_ms(struct device *kdev, struct device_attribute *attr, char *buf)
{
struct drm_i915_private *dev_priv = kdev_minor_to_i915(kdev);
u32 rc6_residency = calc_residency(dev_priv, VLV_GT_MEDIA_RC6);
return snprintf(buf, PAGE_SIZE, "%u\n", rc6_residency);
}
static int l3_access_valid(struct drm_i915_private *dev_priv, loff_t offset)
{
if (!HAS_L3_DPF(dev_priv))
return -EPERM;
if (offset % 4 != 0)
return -EINVAL;
if (offset >= GEN7_L3LOG_SIZE)
return -ENXIO;
return 0;
}
static ssize_t
i915_l3_read(struct file *filp, struct kobject *kobj,
struct bin_attribute *attr, char *buf,
loff_t offset, size_t count)
{
struct device *kdev = kobj_to_dev(kobj);
struct drm_i915_private *dev_priv = kdev_minor_to_i915(kdev);
struct drm_device *dev = &dev_priv->drm;
int slice = (int)(uintptr_t)attr->private;
int ret;
count = round_down(count, 4);
ret = l3_access_valid(dev_priv, offset);
if (ret)
return ret;
count = min_t(size_t, GEN7_L3LOG_SIZE - offset, count);
ret = i915_mutex_lock_interruptible(dev);
if (ret)
return ret;
if (dev_priv->l3_parity.remap_info[slice])
memcpy(buf,
dev_priv->l3_parity.remap_info[slice] + (offset/4),
count);
else
memset(buf, 0, count);
mutex_unlock(&dev->struct_mutex);
return count;
}
static ssize_t
i915_l3_write(struct file *filp, struct kobject *kobj,
struct bin_attribute *attr, char *buf,
loff_t offset, size_t count)
{
struct device *kdev = kobj_to_dev(kobj);
struct drm_i915_private *dev_priv = kdev_minor_to_i915(kdev);
struct drm_device *dev = &dev_priv->drm;
struct i915_gem_context *ctx;
u32 *temp = NULL;
int slice = (int)(uintptr_t)attr->private;
int ret;
if (!HAS_HW_CONTEXTS(dev_priv))
return -ENXIO;
ret = l3_access_valid(dev_priv, offset);
if (ret)
return ret;
ret = i915_mutex_lock_interruptible(dev);
if (ret)
return ret;
if (!dev_priv->l3_parity.remap_info[slice]) {
temp = kzalloc(GEN7_L3LOG_SIZE, GFP_KERNEL);
if (!temp) {
mutex_unlock(&dev->struct_mutex);
return -ENOMEM;
}
}
if (temp)
dev_priv->l3_parity.remap_info[slice] = temp;
memcpy(dev_priv->l3_parity.remap_info[slice] + (offset/4), buf, count);
list_for_each_entry(ctx, &dev_priv->context_list, link)
ctx->remap_slice |= (1<<slice);
mutex_unlock(&dev->struct_mutex);
return count;
}
static ssize_t gt_act_freq_mhz_show(struct device *kdev,
struct device_attribute *attr, char *buf)
{
struct drm_i915_private *dev_priv = kdev_minor_to_i915(kdev);
int ret;
intel_runtime_pm_get(dev_priv);
mutex_lock(&dev_priv->rps.hw_lock);
if (IS_VALLEYVIEW(dev_priv) || IS_CHERRYVIEW(dev_priv)) {
u32 freq;
freq = vlv_punit_read(dev_priv, PUNIT_REG_GPU_FREQ_STS);
ret = intel_gpu_freq(dev_priv, (freq >> 8) & 0xff);
} else {
u32 rpstat = I915_READ(GEN6_RPSTAT1);
if (IS_GEN9(dev_priv))
ret = (rpstat & GEN9_CAGF_MASK) >> GEN9_CAGF_SHIFT;
else if (IS_HASWELL(dev_priv) || IS_BROADWELL(dev_priv))
ret = (rpstat & HSW_CAGF_MASK) >> HSW_CAGF_SHIFT;
else
ret = (rpstat & GEN6_CAGF_MASK) >> GEN6_CAGF_SHIFT;
ret = intel_gpu_freq(dev_priv, ret);
}
mutex_unlock(&dev_priv->rps.hw_lock);
intel_runtime_pm_put(dev_priv);
return snprintf(buf, PAGE_SIZE, "%d\n", ret);
}
static ssize_t gt_cur_freq_mhz_show(struct device *kdev,
struct device_attribute *attr, char *buf)
{
struct drm_i915_private *dev_priv = kdev_minor_to_i915(kdev);
return snprintf(buf, PAGE_SIZE, "%d\n",
intel_gpu_freq(dev_priv,
dev_priv->rps.cur_freq));
}
static ssize_t gt_boost_freq_mhz_show(struct device *kdev, struct device_attribute *attr, char *buf)
{
struct drm_i915_private *dev_priv = kdev_minor_to_i915(kdev);
return snprintf(buf, PAGE_SIZE, "%d\n",
intel_gpu_freq(dev_priv,
dev_priv->rps.boost_freq));
}
static ssize_t gt_boost_freq_mhz_store(struct device *kdev,
struct device_attribute *attr,
const char *buf, size_t count)
{
struct drm_i915_private *dev_priv = kdev_minor_to_i915(kdev);
u32 val;
ssize_t ret;
ret = kstrtou32(buf, 0, &val);
if (ret)
return ret;
val = intel_freq_opcode(dev_priv, val);
if (val < dev_priv->rps.min_freq || val > dev_priv->rps.max_freq)
return -EINVAL;
mutex_lock(&dev_priv->rps.hw_lock);
dev_priv->rps.boost_freq = val;
mutex_unlock(&dev_priv->rps.hw_lock);
return count;
}
static ssize_t vlv_rpe_freq_mhz_show(struct device *kdev,
struct device_attribute *attr, char *buf)
{
struct drm_i915_private *dev_priv = kdev_minor_to_i915(kdev);
return snprintf(buf, PAGE_SIZE, "%d\n",
intel_gpu_freq(dev_priv,
dev_priv->rps.efficient_freq));
}
static ssize_t gt_max_freq_mhz_show(struct device *kdev, struct device_attribute *attr, char *buf)
{
struct drm_i915_private *dev_priv = kdev_minor_to_i915(kdev);
return snprintf(buf, PAGE_SIZE, "%d\n",
intel_gpu_freq(dev_priv,
dev_priv->rps.max_freq_softlimit));
}
static ssize_t gt_max_freq_mhz_store(struct device *kdev,
struct device_attribute *attr,
const char *buf, size_t count)
{
struct drm_i915_private *dev_priv = kdev_minor_to_i915(kdev);
u32 val;
ssize_t ret;
ret = kstrtou32(buf, 0, &val);
if (ret)
return ret;
intel_runtime_pm_get(dev_priv);
mutex_lock(&dev_priv->rps.hw_lock);
val = intel_freq_opcode(dev_priv, val);
if (val < dev_priv->rps.min_freq ||
val > dev_priv->rps.max_freq ||
val < dev_priv->rps.min_freq_softlimit) {
mutex_unlock(&dev_priv->rps.hw_lock);
intel_runtime_pm_put(dev_priv);
return -EINVAL;
}
if (val > dev_priv->rps.rp0_freq)
DRM_DEBUG("User requested overclocking to %d\n",
intel_gpu_freq(dev_priv, val));
dev_priv->rps.max_freq_softlimit = val;
val = clamp_t(int, dev_priv->rps.cur_freq,
dev_priv->rps.min_freq_softlimit,
dev_priv->rps.max_freq_softlimit);
ret = intel_set_rps(dev_priv, val);
mutex_unlock(&dev_priv->rps.hw_lock);
intel_runtime_pm_put(dev_priv);
return ret ?: count;
}
static ssize_t gt_min_freq_mhz_show(struct device *kdev, struct device_attribute *attr, char *buf)
{
struct drm_i915_private *dev_priv = kdev_minor_to_i915(kdev);
return snprintf(buf, PAGE_SIZE, "%d\n",
intel_gpu_freq(dev_priv,
dev_priv->rps.min_freq_softlimit));
}
static ssize_t gt_min_freq_mhz_store(struct device *kdev,
struct device_attribute *attr,
const char *buf, size_t count)
{
struct drm_i915_private *dev_priv = kdev_minor_to_i915(kdev);
u32 val;
ssize_t ret;
ret = kstrtou32(buf, 0, &val);
if (ret)
return ret;
intel_runtime_pm_get(dev_priv);
mutex_lock(&dev_priv->rps.hw_lock);
val = intel_freq_opcode(dev_priv, val);
if (val < dev_priv->rps.min_freq ||
val > dev_priv->rps.max_freq ||
val > dev_priv->rps.max_freq_softlimit) {
mutex_unlock(&dev_priv->rps.hw_lock);
intel_runtime_pm_put(dev_priv);
return -EINVAL;
}
dev_priv->rps.min_freq_softlimit = val;
val = clamp_t(int, dev_priv->rps.cur_freq,
dev_priv->rps.min_freq_softlimit,
dev_priv->rps.max_freq_softlimit);
ret = intel_set_rps(dev_priv, val);
mutex_unlock(&dev_priv->rps.hw_lock);
intel_runtime_pm_put(dev_priv);
return ret ?: count;
}
static ssize_t gt_rp_mhz_show(struct device *kdev, struct device_attribute *attr, char *buf)
{
struct drm_i915_private *dev_priv = kdev_minor_to_i915(kdev);
u32 val;
if (attr == &dev_attr_gt_RP0_freq_mhz)
val = intel_gpu_freq(dev_priv, dev_priv->rps.rp0_freq);
else if (attr == &dev_attr_gt_RP1_freq_mhz)
val = intel_gpu_freq(dev_priv, dev_priv->rps.rp1_freq);
else if (attr == &dev_attr_gt_RPn_freq_mhz)
val = intel_gpu_freq(dev_priv, dev_priv->rps.min_freq);
else
BUG();
return snprintf(buf, PAGE_SIZE, "%d\n", val);
}
static ssize_t error_state_read(struct file *filp, struct kobject *kobj,
struct bin_attribute *attr, char *buf,
loff_t off, size_t count)
{
struct device *kdev = kobj_to_dev(kobj);
struct drm_i915_private *dev_priv = kdev_minor_to_i915(kdev);
struct drm_i915_error_state_buf error_str;
struct i915_gpu_state *gpu;
ssize_t ret;
ret = i915_error_state_buf_init(&error_str, dev_priv, count, off);
if (ret)
return ret;
gpu = i915_first_error_state(dev_priv);
ret = i915_error_state_to_str(&error_str, gpu);
if (ret)
goto out;
ret = count < error_str.bytes ? count : error_str.bytes;
memcpy(buf, error_str.buf, ret);
out:
i915_gpu_state_put(gpu);
i915_error_state_buf_release(&error_str);
return ret;
}
static ssize_t error_state_write(struct file *file, struct kobject *kobj,
struct bin_attribute *attr, char *buf,
loff_t off, size_t count)
{
struct device *kdev = kobj_to_dev(kobj);
struct drm_i915_private *dev_priv = kdev_minor_to_i915(kdev);
DRM_DEBUG_DRIVER("Resetting error state\n");
i915_reset_error_state(dev_priv);
return count;
}
static void i915_setup_error_capture(struct device *kdev)
{
if (sysfs_create_bin_file(&kdev->kobj, &error_state_attr))
DRM_ERROR("error_state sysfs setup failed\n");
}
static void i915_teardown_error_capture(struct device *kdev)
{
sysfs_remove_bin_file(&kdev->kobj, &error_state_attr);
}
static void i915_setup_error_capture(struct device *kdev) {}
static void i915_teardown_error_capture(struct device *kdev) {}
void i915_setup_sysfs(struct drm_i915_private *dev_priv)
{
struct device *kdev = dev_priv->drm.primary->kdev;
int ret;
#ifdef CONFIG_PM
if (HAS_RC6(dev_priv)) {
ret = sysfs_merge_group(&kdev->kobj,
&rc6_attr_group);
if (ret)
DRM_ERROR("RC6 residency sysfs setup failed\n");
}
if (HAS_RC6p(dev_priv)) {
ret = sysfs_merge_group(&kdev->kobj,
&rc6p_attr_group);
if (ret)
DRM_ERROR("RC6p residency sysfs setup failed\n");
}
if (IS_VALLEYVIEW(dev_priv) || IS_CHERRYVIEW(dev_priv)) {
ret = sysfs_merge_group(&kdev->kobj,
&media_rc6_attr_group);
if (ret)
DRM_ERROR("Media RC6 residency sysfs setup failed\n");
}
#endif
if (HAS_L3_DPF(dev_priv)) {
ret = device_create_bin_file(kdev, &dpf_attrs);
if (ret)
DRM_ERROR("l3 parity sysfs setup failed\n");
if (NUM_L3_SLICES(dev_priv) > 1) {
ret = device_create_bin_file(kdev,
&dpf_attrs_1);
if (ret)
DRM_ERROR("l3 parity slice 1 setup failed\n");
}
}
ret = 0;
if (IS_VALLEYVIEW(dev_priv) || IS_CHERRYVIEW(dev_priv))
ret = sysfs_create_files(&kdev->kobj, vlv_attrs);
else if (INTEL_GEN(dev_priv) >= 6)
ret = sysfs_create_files(&kdev->kobj, gen6_attrs);
if (ret)
DRM_ERROR("RPS sysfs setup failed\n");
i915_setup_error_capture(kdev);
}
void i915_teardown_sysfs(struct drm_i915_private *dev_priv)
{
struct device *kdev = dev_priv->drm.primary->kdev;
i915_teardown_error_capture(kdev);
if (IS_VALLEYVIEW(dev_priv) || IS_CHERRYVIEW(dev_priv))
sysfs_remove_files(&kdev->kobj, vlv_attrs);
else
sysfs_remove_files(&kdev->kobj, gen6_attrs);
device_remove_bin_file(kdev, &dpf_attrs_1);
device_remove_bin_file(kdev, &dpf_attrs);
#ifdef CONFIG_PM
sysfs_unmerge_group(&kdev->kobj, &rc6_attr_group);
sysfs_unmerge_group(&kdev->kobj, &rc6p_attr_group);
#endif
}
