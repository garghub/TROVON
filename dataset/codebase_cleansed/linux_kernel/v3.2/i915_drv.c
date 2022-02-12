void intel_detect_pch(struct drm_device *dev)
{
struct drm_i915_private *dev_priv = dev->dev_private;
struct pci_dev *pch;
pch = pci_get_class(PCI_CLASS_BRIDGE_ISA << 8, NULL);
if (pch) {
if (pch->vendor == PCI_VENDOR_ID_INTEL) {
int id;
id = pch->device & INTEL_PCH_DEVICE_ID_MASK;
if (id == INTEL_PCH_IBX_DEVICE_ID_TYPE) {
dev_priv->pch_type = PCH_IBX;
DRM_DEBUG_KMS("Found Ibex Peak PCH\n");
} else if (id == INTEL_PCH_CPT_DEVICE_ID_TYPE) {
dev_priv->pch_type = PCH_CPT;
DRM_DEBUG_KMS("Found CougarPoint PCH\n");
} else if (id == INTEL_PCH_PPT_DEVICE_ID_TYPE) {
dev_priv->pch_type = PCH_CPT;
DRM_DEBUG_KMS("Found PatherPoint PCH\n");
}
}
pci_dev_put(pch);
}
}
void __gen6_gt_force_wake_get(struct drm_i915_private *dev_priv)
{
int count;
count = 0;
while (count++ < 50 && (I915_READ_NOTRACE(FORCEWAKE_ACK) & 1))
udelay(10);
I915_WRITE_NOTRACE(FORCEWAKE, 1);
POSTING_READ(FORCEWAKE);
count = 0;
while (count++ < 50 && (I915_READ_NOTRACE(FORCEWAKE_ACK) & 1) == 0)
udelay(10);
}
void __gen6_gt_force_wake_mt_get(struct drm_i915_private *dev_priv)
{
int count;
count = 0;
while (count++ < 50 && (I915_READ_NOTRACE(FORCEWAKE_MT_ACK) & 1))
udelay(10);
I915_WRITE_NOTRACE(FORCEWAKE_MT, (1<<16) | 1);
POSTING_READ(FORCEWAKE_MT);
count = 0;
while (count++ < 50 && (I915_READ_NOTRACE(FORCEWAKE_MT_ACK) & 1) == 0)
udelay(10);
}
void gen6_gt_force_wake_get(struct drm_i915_private *dev_priv)
{
WARN_ON(!mutex_is_locked(&dev_priv->dev->struct_mutex));
if (atomic_add_return(1, &dev_priv->forcewake_count) == 1)
dev_priv->display.force_wake_get(dev_priv);
}
void __gen6_gt_force_wake_put(struct drm_i915_private *dev_priv)
{
I915_WRITE_NOTRACE(FORCEWAKE, 0);
POSTING_READ(FORCEWAKE);
}
void __gen6_gt_force_wake_mt_put(struct drm_i915_private *dev_priv)
{
I915_WRITE_NOTRACE(FORCEWAKE_MT, (1<<16) | 0);
POSTING_READ(FORCEWAKE_MT);
}
void gen6_gt_force_wake_put(struct drm_i915_private *dev_priv)
{
WARN_ON(!mutex_is_locked(&dev_priv->dev->struct_mutex));
if (atomic_dec_and_test(&dev_priv->forcewake_count))
dev_priv->display.force_wake_put(dev_priv);
}
void __gen6_gt_wait_for_fifo(struct drm_i915_private *dev_priv)
{
if (dev_priv->gt_fifo_count < GT_FIFO_NUM_RESERVED_ENTRIES) {
int loop = 500;
u32 fifo = I915_READ_NOTRACE(GT_FIFO_FREE_ENTRIES);
while (fifo <= GT_FIFO_NUM_RESERVED_ENTRIES && loop--) {
udelay(10);
fifo = I915_READ_NOTRACE(GT_FIFO_FREE_ENTRIES);
}
WARN_ON(loop < 0 && fifo <= GT_FIFO_NUM_RESERVED_ENTRIES);
dev_priv->gt_fifo_count = fifo;
}
dev_priv->gt_fifo_count--;
}
static int i915_drm_freeze(struct drm_device *dev)
{
struct drm_i915_private *dev_priv = dev->dev_private;
drm_kms_helper_poll_disable(dev);
pci_save_state(dev->pdev);
if (drm_core_check_feature(dev, DRIVER_MODESET)) {
int error = i915_gem_idle(dev);
if (error) {
dev_err(&dev->pdev->dev,
"GEM idle failed, resume might fail\n");
return error;
}
drm_irq_uninstall(dev);
}
i915_save_state(dev);
intel_opregion_fini(dev);
dev_priv->modeset_on_lid = 0;
return 0;
}
int i915_suspend(struct drm_device *dev, pm_message_t state)
{
int error;
if (!dev || !dev->dev_private) {
DRM_ERROR("dev: %p\n", dev);
DRM_ERROR("DRM not initialized, aborting suspend.\n");
return -ENODEV;
}
if (state.event == PM_EVENT_PRETHAW)
return 0;
if (dev->switch_power_state == DRM_SWITCH_POWER_OFF)
return 0;
error = i915_drm_freeze(dev);
if (error)
return error;
if (state.event == PM_EVENT_SUSPEND) {
pci_disable_device(dev->pdev);
pci_set_power_state(dev->pdev, PCI_D3hot);
}
return 0;
}
static int i915_drm_thaw(struct drm_device *dev)
{
struct drm_i915_private *dev_priv = dev->dev_private;
int error = 0;
if (drm_core_check_feature(dev, DRIVER_MODESET)) {
mutex_lock(&dev->struct_mutex);
i915_gem_restore_gtt_mappings(dev);
mutex_unlock(&dev->struct_mutex);
}
i915_restore_state(dev);
intel_opregion_setup(dev);
if (drm_core_check_feature(dev, DRIVER_MODESET)) {
mutex_lock(&dev->struct_mutex);
dev_priv->mm.suspended = 0;
error = i915_gem_init_ringbuffer(dev);
mutex_unlock(&dev->struct_mutex);
if (HAS_PCH_SPLIT(dev))
ironlake_init_pch_refclk(dev);
drm_mode_config_reset(dev);
drm_irq_install(dev);
drm_helper_resume_force_mode(dev);
if (IS_IRONLAKE_M(dev))
ironlake_enable_rc6(dev);
}
intel_opregion_init(dev);
dev_priv->modeset_on_lid = 0;
return error;
}
int i915_resume(struct drm_device *dev)
{
int ret;
if (dev->switch_power_state == DRM_SWITCH_POWER_OFF)
return 0;
if (pci_enable_device(dev->pdev))
return -EIO;
pci_set_master(dev->pdev);
ret = i915_drm_thaw(dev);
if (ret)
return ret;
drm_kms_helper_poll_enable(dev);
return 0;
}
static int i8xx_do_reset(struct drm_device *dev, u8 flags)
{
struct drm_i915_private *dev_priv = dev->dev_private;
if (IS_I85X(dev))
return -ENODEV;
I915_WRITE(D_STATE, I915_READ(D_STATE) | DSTATE_GFX_RESET_I830);
POSTING_READ(D_STATE);
if (IS_I830(dev) || IS_845G(dev)) {
I915_WRITE(DEBUG_RESET_I830,
DEBUG_RESET_DISPLAY |
DEBUG_RESET_RENDER |
DEBUG_RESET_FULL);
POSTING_READ(DEBUG_RESET_I830);
msleep(1);
I915_WRITE(DEBUG_RESET_I830, 0);
POSTING_READ(DEBUG_RESET_I830);
}
msleep(1);
I915_WRITE(D_STATE, I915_READ(D_STATE) & ~DSTATE_GFX_RESET_I830);
POSTING_READ(D_STATE);
return 0;
}
static int i965_reset_complete(struct drm_device *dev)
{
u8 gdrst;
pci_read_config_byte(dev->pdev, I965_GDRST, &gdrst);
return gdrst & 0x1;
}
static int i965_do_reset(struct drm_device *dev, u8 flags)
{
u8 gdrst;
pci_read_config_byte(dev->pdev, I965_GDRST, &gdrst);
pci_write_config_byte(dev->pdev, I965_GDRST, gdrst | flags | 0x1);
return wait_for(i965_reset_complete(dev), 500);
}
static int ironlake_do_reset(struct drm_device *dev, u8 flags)
{
struct drm_i915_private *dev_priv = dev->dev_private;
u32 gdrst = I915_READ(MCHBAR_MIRROR_BASE + ILK_GDSR);
I915_WRITE(MCHBAR_MIRROR_BASE + ILK_GDSR, gdrst | flags | 0x1);
return wait_for(I915_READ(MCHBAR_MIRROR_BASE + ILK_GDSR) & 0x1, 500);
}
static int gen6_do_reset(struct drm_device *dev, u8 flags)
{
struct drm_i915_private *dev_priv = dev->dev_private;
I915_WRITE(GEN6_GDRST, GEN6_GRDOM_FULL);
return wait_for((I915_READ(GEN6_GDRST) & GEN6_GRDOM_FULL) == 0, 500);
}
int i915_reset(struct drm_device *dev, u8 flags)
{
drm_i915_private_t *dev_priv = dev->dev_private;
bool need_display = true;
int ret;
if (!i915_try_reset)
return 0;
if (!mutex_trylock(&dev->struct_mutex))
return -EBUSY;
i915_gem_reset(dev);
ret = -ENODEV;
if (get_seconds() - dev_priv->last_gpu_reset < 5) {
DRM_ERROR("GPU hanging too fast, declaring wedged!\n");
} else switch (INTEL_INFO(dev)->gen) {
case 7:
case 6:
ret = gen6_do_reset(dev, flags);
if (atomic_read(&dev_priv->forcewake_count))
__gen6_gt_force_wake_get(dev_priv);
break;
case 5:
ret = ironlake_do_reset(dev, flags);
break;
case 4:
ret = i965_do_reset(dev, flags);
break;
case 2:
ret = i8xx_do_reset(dev, flags);
break;
}
dev_priv->last_gpu_reset = get_seconds();
if (ret) {
DRM_ERROR("Failed to reset chip.\n");
mutex_unlock(&dev->struct_mutex);
return ret;
}
if (drm_core_check_feature(dev, DRIVER_MODESET) ||
!dev_priv->mm.suspended) {
dev_priv->mm.suspended = 0;
dev_priv->ring[RCS].init(&dev_priv->ring[RCS]);
if (HAS_BSD(dev))
dev_priv->ring[VCS].init(&dev_priv->ring[VCS]);
if (HAS_BLT(dev))
dev_priv->ring[BCS].init(&dev_priv->ring[BCS]);
mutex_unlock(&dev->struct_mutex);
drm_irq_uninstall(dev);
drm_mode_config_reset(dev);
drm_irq_install(dev);
mutex_lock(&dev->struct_mutex);
}
mutex_unlock(&dev->struct_mutex);
if (need_display) {
mutex_lock(&dev->mode_config.mutex);
drm_helper_resume_force_mode(dev);
mutex_unlock(&dev->mode_config.mutex);
}
return 0;
}
static int __devinit
i915_pci_probe(struct pci_dev *pdev, const struct pci_device_id *ent)
{
if (PCI_FUNC(pdev->devfn))
return -ENODEV;
return drm_get_pci_dev(pdev, ent, &driver);
}
static void
i915_pci_remove(struct pci_dev *pdev)
{
struct drm_device *dev = pci_get_drvdata(pdev);
drm_put_dev(dev);
}
static int i915_pm_suspend(struct device *dev)
{
struct pci_dev *pdev = to_pci_dev(dev);
struct drm_device *drm_dev = pci_get_drvdata(pdev);
int error;
if (!drm_dev || !drm_dev->dev_private) {
dev_err(dev, "DRM not initialized, aborting suspend.\n");
return -ENODEV;
}
if (drm_dev->switch_power_state == DRM_SWITCH_POWER_OFF)
return 0;
error = i915_drm_freeze(drm_dev);
if (error)
return error;
pci_disable_device(pdev);
pci_set_power_state(pdev, PCI_D3hot);
return 0;
}
static int i915_pm_resume(struct device *dev)
{
struct pci_dev *pdev = to_pci_dev(dev);
struct drm_device *drm_dev = pci_get_drvdata(pdev);
return i915_resume(drm_dev);
}
static int i915_pm_freeze(struct device *dev)
{
struct pci_dev *pdev = to_pci_dev(dev);
struct drm_device *drm_dev = pci_get_drvdata(pdev);
if (!drm_dev || !drm_dev->dev_private) {
dev_err(dev, "DRM not initialized, aborting suspend.\n");
return -ENODEV;
}
return i915_drm_freeze(drm_dev);
}
static int i915_pm_thaw(struct device *dev)
{
struct pci_dev *pdev = to_pci_dev(dev);
struct drm_device *drm_dev = pci_get_drvdata(pdev);
return i915_drm_thaw(drm_dev);
}
static int i915_pm_poweroff(struct device *dev)
{
struct pci_dev *pdev = to_pci_dev(dev);
struct drm_device *drm_dev = pci_get_drvdata(pdev);
return i915_drm_freeze(drm_dev);
}
static int __init i915_init(void)
{
if (!intel_agp_enabled) {
DRM_ERROR("drm/i915 can't work without intel_agp module!\n");
return -ENODEV;
}
driver.num_ioctls = i915_max_ioctl;
#if defined(CONFIG_DRM_I915_KMS)
if (i915_modeset != 0)
driver.driver_features |= DRIVER_MODESET;
#endif
if (i915_modeset == 1)
driver.driver_features |= DRIVER_MODESET;
#ifdef CONFIG_VGA_CONSOLE
if (vgacon_text_force() && i915_modeset == -1)
driver.driver_features &= ~DRIVER_MODESET;
#endif
if (!(driver.driver_features & DRIVER_MODESET))
driver.get_vblank_timestamp = NULL;
return drm_pci_init(&driver, &i915_pci_driver);
}
static void __exit i915_exit(void)
{
drm_pci_exit(&driver, &i915_pci_driver);
}
