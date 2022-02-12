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
void i915_setup_sysfs(struct drm_device *dev)
{
int ret;
if (INTEL_INFO(dev)->gen < 6)
return;
ret = sysfs_merge_group(&dev->primary->kdev.kobj, &rc6_attr_group);
if (ret)
DRM_ERROR("sysfs setup failed\n");
}
void i915_teardown_sysfs(struct drm_device *dev)
{
sysfs_unmerge_group(&dev->primary->kdev.kobj, &rc6_attr_group);
}
