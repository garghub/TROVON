static u32 calc_residency(struct drm_device *dev, const u32 reg)
{
struct drm_i915_private *dev_priv = dev->dev_private;
u64 raw_time;
u64 units = 128ULL, div = 100000ULL, bias = 100ULL;
u32 ret;
if (!intel_enable_rc6(dev))
return 0;
intel_runtime_pm_get(dev_priv);
if (IS_VALLEYVIEW(dev)) {
u32 clk_reg, czcount_30ns;
if (IS_CHERRYVIEW(dev))
clk_reg = CHV_CLK_CTL1;
else
clk_reg = VLV_CLK_CTL2;
czcount_30ns = I915_READ(clk_reg) >> CLK_CTL2_CZCOUNT_30NS_SHIFT;
if (!czcount_30ns) {
WARN(!czcount_30ns, "bogus CZ count value");
ret = 0;
goto out;
}
units = 0;
div = 1000000ULL;
if (IS_CHERRYVIEW(dev)) {
if (czcount_30ns == 1) {
div = 10000000ULL;
units = 3125ULL;
} else {
czcount_30ns += 1;
}
}
if (units == 0)
units = DIV_ROUND_UP_ULL(30ULL * bias,
(u64)czcount_30ns);
if (I915_READ(VLV_COUNTER_CONTROL) & VLV_COUNT_RANGE_HIGH)
units <<= 8;
div = div * bias;
}
raw_time = I915_READ(reg) * units;
ret = DIV_ROUND_UP_ULL(raw_time, div);
out:
intel_runtime_pm_put(dev_priv);
return ret;
}
static ssize_t
show_rc6_mask(struct device *kdev, struct device_attribute *attr, char *buf)
{
struct drm_minor *dminor = dev_to_drm_minor(kdev);
return snprintf(buf, PAGE_SIZE, "%x\n", intel_enable_rc6(dminor->dev));
}
static ssize_t
show_rc6_ms(struct device *kdev, struct device_attribute *attr, char *buf)
{
struct drm_minor *dminor = dev_get_drvdata(kdev);
u32 rc6_residency = calc_residency(dminor->dev, GEN6_GT_GFX_RC6);
return snprintf(buf, PAGE_SIZE, "%u\n", rc6_residency);
}
static ssize_t
show_rc6p_ms(struct device *kdev, struct device_attribute *attr, char *buf)
{
struct drm_minor *dminor = dev_to_drm_minor(kdev);
u32 rc6p_residency = calc_residency(dminor->dev, GEN6_GT_GFX_RC6p);
return snprintf(buf, PAGE_SIZE, "%u\n", rc6p_residency);
}
static ssize_t
show_rc6pp_ms(struct device *kdev, struct device_attribute *attr, char *buf)
{
struct drm_minor *dminor = dev_to_drm_minor(kdev);
u32 rc6pp_residency = calc_residency(dminor->dev, GEN6_GT_GFX_RC6pp);
return snprintf(buf, PAGE_SIZE, "%u\n", rc6pp_residency);
}
static ssize_t
show_media_rc6_ms(struct device *kdev, struct device_attribute *attr, char *buf)
{
struct drm_minor *dminor = dev_get_drvdata(kdev);
u32 rc6_residency = calc_residency(dminor->dev, VLV_GT_MEDIA_RC6);
return snprintf(buf, PAGE_SIZE, "%u\n", rc6_residency);
}
static int l3_access_valid(struct drm_device *dev, loff_t offset)
{
if (!HAS_L3_DPF(dev))
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
struct device *dev = container_of(kobj, struct device, kobj);
struct drm_minor *dminor = dev_to_drm_minor(dev);
struct drm_device *drm_dev = dminor->dev;
struct drm_i915_private *dev_priv = drm_dev->dev_private;
int slice = (int)(uintptr_t)attr->private;
int ret;
count = round_down(count, 4);
ret = l3_access_valid(drm_dev, offset);
if (ret)
return ret;
count = min_t(size_t, GEN7_L3LOG_SIZE - offset, count);
ret = i915_mutex_lock_interruptible(drm_dev);
if (ret)
return ret;
if (dev_priv->l3_parity.remap_info[slice])
memcpy(buf,
dev_priv->l3_parity.remap_info[slice] + (offset/4),
count);
else
memset(buf, 0, count);
mutex_unlock(&drm_dev->struct_mutex);
return count;
}
static ssize_t
i915_l3_write(struct file *filp, struct kobject *kobj,
struct bin_attribute *attr, char *buf,
loff_t offset, size_t count)
{
struct device *dev = container_of(kobj, struct device, kobj);
struct drm_minor *dminor = dev_to_drm_minor(dev);
struct drm_device *drm_dev = dminor->dev;
struct drm_i915_private *dev_priv = drm_dev->dev_private;
struct intel_context *ctx;
u32 *temp = NULL;
int slice = (int)(uintptr_t)attr->private;
int ret;
if (!HAS_HW_CONTEXTS(drm_dev))
return -ENXIO;
ret = l3_access_valid(drm_dev, offset);
if (ret)
return ret;
ret = i915_mutex_lock_interruptible(drm_dev);
if (ret)
return ret;
if (!dev_priv->l3_parity.remap_info[slice]) {
temp = kzalloc(GEN7_L3LOG_SIZE, GFP_KERNEL);
if (!temp) {
mutex_unlock(&drm_dev->struct_mutex);
return -ENOMEM;
}
}
ret = i915_gpu_idle(drm_dev);
if (ret) {
kfree(temp);
mutex_unlock(&drm_dev->struct_mutex);
return ret;
}
if (temp)
dev_priv->l3_parity.remap_info[slice] = temp;
memcpy(dev_priv->l3_parity.remap_info[slice] + (offset/4), buf, count);
list_for_each_entry(ctx, &dev_priv->context_list, link)
ctx->remap_slice |= (1<<slice);
mutex_unlock(&drm_dev->struct_mutex);
return count;
}
static ssize_t gt_act_freq_mhz_show(struct device *kdev,
struct device_attribute *attr, char *buf)
{
struct drm_minor *minor = dev_to_drm_minor(kdev);
struct drm_device *dev = minor->dev;
struct drm_i915_private *dev_priv = dev->dev_private;
int ret;
flush_delayed_work(&dev_priv->rps.delayed_resume_work);
intel_runtime_pm_get(dev_priv);
mutex_lock(&dev_priv->rps.hw_lock);
if (IS_VALLEYVIEW(dev_priv->dev)) {
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
struct drm_minor *minor = dev_to_drm_minor(kdev);
struct drm_device *dev = minor->dev;
struct drm_i915_private *dev_priv = dev->dev_private;
int ret;
flush_delayed_work(&dev_priv->rps.delayed_resume_work);
intel_runtime_pm_get(dev_priv);
mutex_lock(&dev_priv->rps.hw_lock);
ret = intel_gpu_freq(dev_priv, dev_priv->rps.cur_freq);
mutex_unlock(&dev_priv->rps.hw_lock);
intel_runtime_pm_put(dev_priv);
return snprintf(buf, PAGE_SIZE, "%d\n", ret);
}
static ssize_t vlv_rpe_freq_mhz_show(struct device *kdev,
struct device_attribute *attr, char *buf)
{
struct drm_minor *minor = dev_to_drm_minor(kdev);
struct drm_device *dev = minor->dev;
struct drm_i915_private *dev_priv = dev->dev_private;
return snprintf(buf, PAGE_SIZE,
"%d\n",
intel_gpu_freq(dev_priv, dev_priv->rps.efficient_freq));
}
static ssize_t gt_max_freq_mhz_show(struct device *kdev, struct device_attribute *attr, char *buf)
{
struct drm_minor *minor = dev_to_drm_minor(kdev);
struct drm_device *dev = minor->dev;
struct drm_i915_private *dev_priv = dev->dev_private;
int ret;
flush_delayed_work(&dev_priv->rps.delayed_resume_work);
mutex_lock(&dev_priv->rps.hw_lock);
ret = intel_gpu_freq(dev_priv, dev_priv->rps.max_freq_softlimit);
mutex_unlock(&dev_priv->rps.hw_lock);
return snprintf(buf, PAGE_SIZE, "%d\n", ret);
}
static ssize_t gt_max_freq_mhz_store(struct device *kdev,
struct device_attribute *attr,
const char *buf, size_t count)
{
struct drm_minor *minor = dev_to_drm_minor(kdev);
struct drm_device *dev = minor->dev;
struct drm_i915_private *dev_priv = dev->dev_private;
u32 val;
ssize_t ret;
ret = kstrtou32(buf, 0, &val);
if (ret)
return ret;
flush_delayed_work(&dev_priv->rps.delayed_resume_work);
mutex_lock(&dev_priv->rps.hw_lock);
val = intel_freq_opcode(dev_priv, val);
if (val < dev_priv->rps.min_freq ||
val > dev_priv->rps.max_freq ||
val < dev_priv->rps.min_freq_softlimit) {
mutex_unlock(&dev_priv->rps.hw_lock);
return -EINVAL;
}
if (val > dev_priv->rps.rp0_freq)
DRM_DEBUG("User requested overclocking to %d\n",
intel_gpu_freq(dev_priv, val));
dev_priv->rps.max_freq_softlimit = val;
val = clamp_t(int, dev_priv->rps.cur_freq,
dev_priv->rps.min_freq_softlimit,
dev_priv->rps.max_freq_softlimit);
intel_set_rps(dev, val);
mutex_unlock(&dev_priv->rps.hw_lock);
return count;
}
static ssize_t gt_min_freq_mhz_show(struct device *kdev, struct device_attribute *attr, char *buf)
{
struct drm_minor *minor = dev_to_drm_minor(kdev);
struct drm_device *dev = minor->dev;
struct drm_i915_private *dev_priv = dev->dev_private;
int ret;
flush_delayed_work(&dev_priv->rps.delayed_resume_work);
mutex_lock(&dev_priv->rps.hw_lock);
ret = intel_gpu_freq(dev_priv, dev_priv->rps.min_freq_softlimit);
mutex_unlock(&dev_priv->rps.hw_lock);
return snprintf(buf, PAGE_SIZE, "%d\n", ret);
}
static ssize_t gt_min_freq_mhz_store(struct device *kdev,
struct device_attribute *attr,
const char *buf, size_t count)
{
struct drm_minor *minor = dev_to_drm_minor(kdev);
struct drm_device *dev = minor->dev;
struct drm_i915_private *dev_priv = dev->dev_private;
u32 val;
ssize_t ret;
ret = kstrtou32(buf, 0, &val);
if (ret)
return ret;
flush_delayed_work(&dev_priv->rps.delayed_resume_work);
mutex_lock(&dev_priv->rps.hw_lock);
val = intel_freq_opcode(dev_priv, val);
if (val < dev_priv->rps.min_freq ||
val > dev_priv->rps.max_freq ||
val > dev_priv->rps.max_freq_softlimit) {
mutex_unlock(&dev_priv->rps.hw_lock);
return -EINVAL;
}
dev_priv->rps.min_freq_softlimit = val;
val = clamp_t(int, dev_priv->rps.cur_freq,
dev_priv->rps.min_freq_softlimit,
dev_priv->rps.max_freq_softlimit);
intel_set_rps(dev, val);
mutex_unlock(&dev_priv->rps.hw_lock);
return count;
}
static ssize_t gt_rp_mhz_show(struct device *kdev, struct device_attribute *attr, char *buf)
{
struct drm_minor *minor = dev_to_drm_minor(kdev);
struct drm_device *dev = minor->dev;
struct drm_i915_private *dev_priv = dev->dev_private;
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
struct device *kdev = container_of(kobj, struct device, kobj);
struct drm_minor *minor = dev_to_drm_minor(kdev);
struct drm_device *dev = minor->dev;
struct i915_error_state_file_priv error_priv;
struct drm_i915_error_state_buf error_str;
ssize_t ret_count = 0;
int ret;
memset(&error_priv, 0, sizeof(error_priv));
ret = i915_error_state_buf_init(&error_str, to_i915(dev), count, off);
if (ret)
return ret;
error_priv.dev = dev;
i915_error_state_get(dev, &error_priv);
ret = i915_error_state_to_str(&error_str, &error_priv);
if (ret)
goto out;
ret_count = count < error_str.bytes ? count : error_str.bytes;
memcpy(buf, error_str.buf, ret_count);
out:
i915_error_state_put(&error_priv);
i915_error_state_buf_release(&error_str);
return ret ?: ret_count;
}
static ssize_t error_state_write(struct file *file, struct kobject *kobj,
struct bin_attribute *attr, char *buf,
loff_t off, size_t count)
{
struct device *kdev = container_of(kobj, struct device, kobj);
struct drm_minor *minor = dev_to_drm_minor(kdev);
struct drm_device *dev = minor->dev;
int ret;
DRM_DEBUG_DRIVER("Resetting error state\n");
ret = mutex_lock_interruptible(&dev->struct_mutex);
if (ret)
return ret;
i915_destroy_error_state(dev);
mutex_unlock(&dev->struct_mutex);
return count;
}
void i915_setup_sysfs(struct drm_device *dev)
{
int ret;
#ifdef CONFIG_PM
if (HAS_RC6(dev)) {
ret = sysfs_merge_group(&dev->primary->kdev->kobj,
&rc6_attr_group);
if (ret)
DRM_ERROR("RC6 residency sysfs setup failed\n");
}
if (HAS_RC6p(dev)) {
ret = sysfs_merge_group(&dev->primary->kdev->kobj,
&rc6p_attr_group);
if (ret)
DRM_ERROR("RC6p residency sysfs setup failed\n");
}
if (IS_VALLEYVIEW(dev)) {
ret = sysfs_merge_group(&dev->primary->kdev->kobj,
&media_rc6_attr_group);
if (ret)
DRM_ERROR("Media RC6 residency sysfs setup failed\n");
}
#endif
if (HAS_L3_DPF(dev)) {
ret = device_create_bin_file(dev->primary->kdev, &dpf_attrs);
if (ret)
DRM_ERROR("l3 parity sysfs setup failed\n");
if (NUM_L3_SLICES(dev) > 1) {
ret = device_create_bin_file(dev->primary->kdev,
&dpf_attrs_1);
if (ret)
DRM_ERROR("l3 parity slice 1 setup failed\n");
}
}
ret = 0;
if (IS_VALLEYVIEW(dev))
ret = sysfs_create_files(&dev->primary->kdev->kobj, vlv_attrs);
else if (INTEL_INFO(dev)->gen >= 6)
ret = sysfs_create_files(&dev->primary->kdev->kobj, gen6_attrs);
if (ret)
DRM_ERROR("RPS sysfs setup failed\n");
ret = sysfs_create_bin_file(&dev->primary->kdev->kobj,
&error_state_attr);
if (ret)
DRM_ERROR("error_state sysfs setup failed\n");
}
void i915_teardown_sysfs(struct drm_device *dev)
{
sysfs_remove_bin_file(&dev->primary->kdev->kobj, &error_state_attr);
if (IS_VALLEYVIEW(dev))
sysfs_remove_files(&dev->primary->kdev->kobj, vlv_attrs);
else
sysfs_remove_files(&dev->primary->kdev->kobj, gen6_attrs);
device_remove_bin_file(dev->primary->kdev, &dpf_attrs_1);
device_remove_bin_file(dev->primary->kdev, &dpf_attrs);
#ifdef CONFIG_PM
sysfs_unmerge_group(&dev->primary->kdev->kobj, &rc6_attr_group);
sysfs_unmerge_group(&dev->primary->kdev->kobj, &rc6p_attr_group);
#endif
}
