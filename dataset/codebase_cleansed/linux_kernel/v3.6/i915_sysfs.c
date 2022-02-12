static u32 calc_residency(struct drm_device *dev, const u32 reg)
{
struct drm_i915_private *dev_priv = dev->dev_private;
u64 raw_time;
if (!intel_enable_rc6(dev))
return 0;
raw_time = I915_READ(reg) * 128ULL;
return DIV_ROUND_UP_ULL(raw_time, 100000);
}
static ssize_t
show_rc6_mask(struct device *dev, struct device_attribute *attr, char *buf)
{
struct drm_minor *dminor = container_of(dev, struct drm_minor, kdev);
return snprintf(buf, PAGE_SIZE, "%x", intel_enable_rc6(dminor->dev));
}
static ssize_t
show_rc6_ms(struct device *dev, struct device_attribute *attr, char *buf)
{
struct drm_minor *dminor = container_of(dev, struct drm_minor, kdev);
u32 rc6_residency = calc_residency(dminor->dev, GEN6_GT_GFX_RC6);
return snprintf(buf, PAGE_SIZE, "%u", rc6_residency);
}
static ssize_t
show_rc6p_ms(struct device *dev, struct device_attribute *attr, char *buf)
{
struct drm_minor *dminor = container_of(dev, struct drm_minor, kdev);
u32 rc6p_residency = calc_residency(dminor->dev, GEN6_GT_GFX_RC6p);
return snprintf(buf, PAGE_SIZE, "%u", rc6p_residency);
}
static ssize_t
show_rc6pp_ms(struct device *dev, struct device_attribute *attr, char *buf)
{
struct drm_minor *dminor = container_of(dev, struct drm_minor, kdev);
u32 rc6pp_residency = calc_residency(dminor->dev, GEN6_GT_GFX_RC6pp);
return snprintf(buf, PAGE_SIZE, "%u", rc6pp_residency);
}
static int l3_access_valid(struct drm_device *dev, loff_t offset)
{
if (!IS_IVYBRIDGE(dev))
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
struct drm_minor *dminor = container_of(dev, struct drm_minor, kdev);
struct drm_device *drm_dev = dminor->dev;
struct drm_i915_private *dev_priv = drm_dev->dev_private;
uint32_t misccpctl;
int i, ret;
ret = l3_access_valid(drm_dev, offset);
if (ret)
return ret;
ret = i915_mutex_lock_interruptible(drm_dev);
if (ret)
return ret;
misccpctl = I915_READ(GEN7_MISCCPCTL);
I915_WRITE(GEN7_MISCCPCTL, misccpctl & ~GEN7_DOP_CLOCK_GATE_ENABLE);
for (i = offset; count >= 4 && i < GEN7_L3LOG_SIZE; i += 4, count -= 4)
*((uint32_t *)(&buf[i])) = I915_READ(GEN7_L3LOG_BASE + i);
I915_WRITE(GEN7_MISCCPCTL, misccpctl);
mutex_unlock(&drm_dev->struct_mutex);
return i - offset;
}
static ssize_t
i915_l3_write(struct file *filp, struct kobject *kobj,
struct bin_attribute *attr, char *buf,
loff_t offset, size_t count)
{
struct device *dev = container_of(kobj, struct device, kobj);
struct drm_minor *dminor = container_of(dev, struct drm_minor, kdev);
struct drm_device *drm_dev = dminor->dev;
struct drm_i915_private *dev_priv = drm_dev->dev_private;
u32 *temp = NULL;
int ret;
ret = l3_access_valid(drm_dev, offset);
if (ret)
return ret;
ret = i915_mutex_lock_interruptible(drm_dev);
if (ret)
return ret;
if (!dev_priv->mm.l3_remap_info) {
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
dev_priv->mm.l3_remap_info = temp;
memcpy(dev_priv->mm.l3_remap_info + (offset/4),
buf + (offset/4),
count);
i915_gem_l3_remap(drm_dev);
mutex_unlock(&drm_dev->struct_mutex);
return count;
}
void i915_setup_sysfs(struct drm_device *dev)
{
int ret;
if (INTEL_INFO(dev)->gen >= 6) {
ret = sysfs_merge_group(&dev->primary->kdev.kobj,
&rc6_attr_group);
if (ret)
DRM_ERROR("RC6 residency sysfs setup failed\n");
}
if (IS_IVYBRIDGE(dev)) {
ret = device_create_bin_file(&dev->primary->kdev, &dpf_attrs);
if (ret)
DRM_ERROR("l3 parity sysfs setup failed\n");
}
}
void i915_teardown_sysfs(struct drm_device *dev)
{
device_remove_bin_file(&dev->primary->kdev, &dpf_attrs);
sysfs_unmerge_group(&dev->primary->kdev.kobj, &rc6_attr_group);
}
void i915_setup_sysfs(struct drm_device *dev)
{
return;
}
void i915_teardown_sysfs(struct drm_device *dev)
{
return;
}
