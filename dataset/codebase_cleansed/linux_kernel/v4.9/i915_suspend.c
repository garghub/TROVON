static void i915_save_display(struct drm_device *dev)
{
struct drm_i915_private *dev_priv = to_i915(dev);
if (INTEL_INFO(dev)->gen <= 4)
dev_priv->regfile.saveDSPARB = I915_READ(DSPARB);
if (HAS_FBC(dev) && INTEL_INFO(dev)->gen <= 4 && !IS_G4X(dev))
dev_priv->regfile.saveFBC_CONTROL = I915_READ(FBC_CONTROL);
}
static void i915_restore_display(struct drm_device *dev)
{
struct drm_i915_private *dev_priv = to_i915(dev);
if (INTEL_INFO(dev)->gen <= 4)
I915_WRITE(DSPARB, dev_priv->regfile.saveDSPARB);
intel_fbc_global_disable(dev_priv);
if (HAS_FBC(dev) && INTEL_INFO(dev)->gen <= 4 && !IS_G4X(dev))
I915_WRITE(FBC_CONTROL, dev_priv->regfile.saveFBC_CONTROL);
i915_redisable_vga(dev);
}
int i915_save_state(struct drm_device *dev)
{
struct drm_i915_private *dev_priv = to_i915(dev);
struct pci_dev *pdev = dev_priv->drm.pdev;
int i;
mutex_lock(&dev->struct_mutex);
i915_save_display(dev);
if (IS_GEN4(dev))
pci_read_config_word(pdev, GCDGMBUS,
&dev_priv->regfile.saveGCDGMBUS);
if (INTEL_INFO(dev)->gen < 7)
dev_priv->regfile.saveCACHE_MODE_0 = I915_READ(CACHE_MODE_0);
dev_priv->regfile.saveMI_ARB_STATE = I915_READ(MI_ARB_STATE);
if (IS_GEN2(dev_priv) && IS_MOBILE(dev_priv)) {
for (i = 0; i < 7; i++) {
dev_priv->regfile.saveSWF0[i] = I915_READ(SWF0(i));
dev_priv->regfile.saveSWF1[i] = I915_READ(SWF1(i));
}
for (i = 0; i < 3; i++)
dev_priv->regfile.saveSWF3[i] = I915_READ(SWF3(i));
} else if (IS_GEN2(dev_priv)) {
for (i = 0; i < 7; i++)
dev_priv->regfile.saveSWF1[i] = I915_READ(SWF1(i));
} else if (HAS_GMCH_DISPLAY(dev_priv)) {
for (i = 0; i < 16; i++) {
dev_priv->regfile.saveSWF0[i] = I915_READ(SWF0(i));
dev_priv->regfile.saveSWF1[i] = I915_READ(SWF1(i));
}
for (i = 0; i < 3; i++)
dev_priv->regfile.saveSWF3[i] = I915_READ(SWF3(i));
}
mutex_unlock(&dev->struct_mutex);
return 0;
}
int i915_restore_state(struct drm_device *dev)
{
struct drm_i915_private *dev_priv = to_i915(dev);
struct pci_dev *pdev = dev_priv->drm.pdev;
int i;
mutex_lock(&dev->struct_mutex);
i915_gem_restore_fences(dev);
if (IS_GEN4(dev))
pci_write_config_word(pdev, GCDGMBUS,
dev_priv->regfile.saveGCDGMBUS);
i915_restore_display(dev);
if (INTEL_INFO(dev)->gen < 7)
I915_WRITE(CACHE_MODE_0, dev_priv->regfile.saveCACHE_MODE_0 |
0xffff0000);
I915_WRITE(MI_ARB_STATE, dev_priv->regfile.saveMI_ARB_STATE | 0xffff0000);
if (IS_GEN2(dev_priv) && IS_MOBILE(dev_priv)) {
for (i = 0; i < 7; i++) {
I915_WRITE(SWF0(i), dev_priv->regfile.saveSWF0[i]);
I915_WRITE(SWF1(i), dev_priv->regfile.saveSWF1[i]);
}
for (i = 0; i < 3; i++)
I915_WRITE(SWF3(i), dev_priv->regfile.saveSWF3[i]);
} else if (IS_GEN2(dev_priv)) {
for (i = 0; i < 7; i++)
I915_WRITE(SWF1(i), dev_priv->regfile.saveSWF1[i]);
} else if (HAS_GMCH_DISPLAY(dev_priv)) {
for (i = 0; i < 16; i++) {
I915_WRITE(SWF0(i), dev_priv->regfile.saveSWF0[i]);
I915_WRITE(SWF1(i), dev_priv->regfile.saveSWF1[i]);
}
for (i = 0; i < 3; i++)
I915_WRITE(SWF3(i), dev_priv->regfile.saveSWF3[i]);
}
mutex_unlock(&dev->struct_mutex);
intel_i2c_reset(dev);
return 0;
}
