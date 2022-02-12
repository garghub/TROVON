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
dev_priv->num_pch_pll = 2;
DRM_DEBUG_KMS("Found Ibex Peak PCH\n");
} else if (id == INTEL_PCH_CPT_DEVICE_ID_TYPE) {
dev_priv->pch_type = PCH_CPT;
dev_priv->num_pch_pll = 2;
DRM_DEBUG_KMS("Found CougarPoint PCH\n");
} else if (id == INTEL_PCH_PPT_DEVICE_ID_TYPE) {
dev_priv->pch_type = PCH_CPT;
dev_priv->num_pch_pll = 2;
DRM_DEBUG_KMS("Found PatherPoint PCH\n");
} else if (id == INTEL_PCH_LPT_DEVICE_ID_TYPE) {
dev_priv->pch_type = PCH_LPT;
dev_priv->num_pch_pll = 0;
DRM_DEBUG_KMS("Found LynxPoint PCH\n");
}
BUG_ON(dev_priv->num_pch_pll > I915_NUM_PLLS);
}
pci_dev_put(pch);
}
}
bool i915_semaphore_is_enabled(struct drm_device *dev)
{
if (INTEL_INFO(dev)->gen < 6)
return 0;
if (i915_semaphores >= 0)
return i915_semaphores;
#ifdef CONFIG_INTEL_IOMMU
if (INTEL_INFO(dev)->gen == 6 && intel_iommu_gfx_mapped)
return false;
#endif
return 1;
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
intel_modeset_disable(dev);
drm_irq_uninstall(dev);
}
i915_save_state(dev);
intel_opregion_fini(dev);
dev_priv->modeset_on_lid = 0;
console_lock();
intel_fbdev_set_suspend(dev, 1);
console_unlock();
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
if (HAS_PCH_IBX(dev) || HAS_PCH_CPT(dev))
ironlake_init_pch_refclk(dev);
mutex_lock(&dev->struct_mutex);
dev_priv->mm.suspended = 0;
error = i915_gem_init_hw(dev);
mutex_unlock(&dev->struct_mutex);
intel_modeset_init_hw(dev);
intel_modeset_setup_hw_state(dev);
drm_mode_config_reset(dev);
drm_irq_install(dev);
}
intel_opregion_init(dev);
dev_priv->modeset_on_lid = 0;
console_lock();
intel_fbdev_set_suspend(dev, 0);
console_unlock();
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
static int i8xx_do_reset(struct drm_device *dev)
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
return (gdrst & GRDOM_RESET_ENABLE) == 0;
}
static int i965_do_reset(struct drm_device *dev)
{
int ret;
u8 gdrst;
pci_read_config_byte(dev->pdev, I965_GDRST, &gdrst);
pci_write_config_byte(dev->pdev, I965_GDRST,
gdrst | GRDOM_RENDER |
GRDOM_RESET_ENABLE);
ret = wait_for(i965_reset_complete(dev), 500);
if (ret)
return ret;
pci_read_config_byte(dev->pdev, I965_GDRST, &gdrst);
pci_write_config_byte(dev->pdev, I965_GDRST,
gdrst | GRDOM_MEDIA |
GRDOM_RESET_ENABLE);
return wait_for(i965_reset_complete(dev), 500);
}
static int ironlake_do_reset(struct drm_device *dev)
{
struct drm_i915_private *dev_priv = dev->dev_private;
u32 gdrst;
int ret;
gdrst = I915_READ(MCHBAR_MIRROR_BASE + ILK_GDSR);
I915_WRITE(MCHBAR_MIRROR_BASE + ILK_GDSR,
gdrst | GRDOM_RENDER | GRDOM_RESET_ENABLE);
ret = wait_for(I915_READ(MCHBAR_MIRROR_BASE + ILK_GDSR) & 0x1, 500);
if (ret)
return ret;
gdrst = I915_READ(MCHBAR_MIRROR_BASE + ILK_GDSR);
I915_WRITE(MCHBAR_MIRROR_BASE + ILK_GDSR,
gdrst | GRDOM_MEDIA | GRDOM_RESET_ENABLE);
return wait_for(I915_READ(MCHBAR_MIRROR_BASE + ILK_GDSR) & 0x1, 500);
}
static int gen6_do_reset(struct drm_device *dev)
{
struct drm_i915_private *dev_priv = dev->dev_private;
int ret;
unsigned long irqflags;
spin_lock_irqsave(&dev_priv->gt_lock, irqflags);
I915_WRITE_NOTRACE(GEN6_GDRST, GEN6_GRDOM_FULL);
ret = wait_for((I915_READ_NOTRACE(GEN6_GDRST) & GEN6_GRDOM_FULL) == 0, 500);
if (dev_priv->forcewake_count)
dev_priv->gt.force_wake_get(dev_priv);
else
dev_priv->gt.force_wake_put(dev_priv);
dev_priv->gt_fifo_count = I915_READ_NOTRACE(GT_FIFO_FREE_ENTRIES);
spin_unlock_irqrestore(&dev_priv->gt_lock, irqflags);
return ret;
}
int intel_gpu_reset(struct drm_device *dev)
{
struct drm_i915_private *dev_priv = dev->dev_private;
int ret = -ENODEV;
switch (INTEL_INFO(dev)->gen) {
case 7:
case 6:
ret = gen6_do_reset(dev);
break;
case 5:
ret = ironlake_do_reset(dev);
break;
case 4:
ret = i965_do_reset(dev);
break;
case 2:
ret = i8xx_do_reset(dev);
break;
}
if (dev_priv->stop_rings) {
DRM_DEBUG("Simulated gpu hang, resetting stop_rings\n");
dev_priv->stop_rings = 0;
if (ret == -ENODEV) {
DRM_ERROR("Reset not implemented, but ignoring "
"error for simulated gpu hangs\n");
ret = 0;
}
}
return ret;
}
int i915_reset(struct drm_device *dev)
{
drm_i915_private_t *dev_priv = dev->dev_private;
int ret;
if (!i915_try_reset)
return 0;
mutex_lock(&dev->struct_mutex);
i915_gem_reset(dev);
ret = -ENODEV;
if (get_seconds() - dev_priv->last_gpu_reset < 5)
DRM_ERROR("GPU hanging too fast, declaring wedged!\n");
else
ret = intel_gpu_reset(dev);
dev_priv->last_gpu_reset = get_seconds();
if (ret) {
DRM_ERROR("Failed to reset chip.\n");
mutex_unlock(&dev->struct_mutex);
return ret;
}
if (drm_core_check_feature(dev, DRIVER_MODESET) ||
!dev_priv->mm.suspended) {
struct intel_ring_buffer *ring;
int i;
dev_priv->mm.suspended = 0;
i915_gem_init_swizzling(dev);
for_each_ring(ring, dev_priv, i)
ring->init(ring);
i915_gem_context_init(dev);
i915_gem_init_ppgtt(dev);
mutex_unlock(&dev->struct_mutex);
drm_irq_uninstall(dev);
drm_irq_install(dev);
} else {
mutex_unlock(&dev->struct_mutex);
}
return 0;
}
static int __devinit
i915_pci_probe(struct pci_dev *pdev, const struct pci_device_id *ent)
{
struct intel_device_info *intel_info =
(struct intel_device_info *) ent->driver_data;
if (intel_info->is_haswell || intel_info->is_valleyview)
if(!i915_preliminary_hw_support) {
DRM_ERROR("Preliminary hardware support disabled\n");
return -ENODEV;
}
if (PCI_FUNC(pdev->devfn))
return -ENODEV;
if (intel_info->gen != 3) {
driver.driver_features &=
~(DRIVER_USE_AGP | DRIVER_REQUIRE_AGP);
} else if (!intel_agp_enabled) {
DRM_ERROR("drm/i915 can't work without intel_agp module!\n");
return -ENODEV;
}
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
static bool IS_DISPLAYREG(u32 reg)
{
if (reg >= VLV_DISPLAY_BASE)
return false;
if (reg >= RENDER_RING_BASE &&
reg < RENDER_RING_BASE + 0xff)
return false;
if (reg >= GEN6_BSD_RING_BASE &&
reg < GEN6_BSD_RING_BASE + 0xff)
return false;
if (reg >= BLT_RING_BASE &&
reg < BLT_RING_BASE + 0xff)
return false;
if (reg == PGTBL_ER)
return false;
if (reg >= IPEIR_I965 &&
reg < HWSTAM)
return false;
if (reg == MI_MODE)
return false;
if (reg == GFX_MODE_GEN7)
return false;
if (reg == RENDER_HWS_PGA_GEN7 ||
reg == BSD_HWS_PGA_GEN7 ||
reg == BLT_HWS_PGA_GEN7)
return false;
if (reg == GEN6_BSD_SLEEP_PSMI_CONTROL ||
reg == GEN6_BSD_RNCID)
return false;
if (reg == GEN6_BLITTER_ECOSKPD)
return false;
if (reg >= 0x4000c &&
reg <= 0x4002c)
return false;
if (reg >= 0x4f000 &&
reg <= 0x4f08f)
return false;
if (reg >= 0x4f100 &&
reg <= 0x4f11f)
return false;
if (reg >= VLV_MASTER_IER &&
reg <= GEN6_PMIER)
return false;
if (reg >= FENCE_REG_SANDYBRIDGE_0 &&
reg < (FENCE_REG_SANDYBRIDGE_0 + (16*8)))
return false;
if (reg >= VLV_IIR_RW &&
reg <= VLV_ISR)
return false;
if (reg == FORCEWAKE_VLV ||
reg == FORCEWAKE_ACK_VLV)
return false;
if (reg == GEN6_GDRST)
return false;
return true;
}
int i915_reg_read_ioctl(struct drm_device *dev,
void *data, struct drm_file *file)
{
struct drm_i915_private *dev_priv = dev->dev_private;
struct drm_i915_reg_read *reg = data;
struct register_whitelist const *entry = whitelist;
int i;
for (i = 0; i < ARRAY_SIZE(whitelist); i++, entry++) {
if (entry->offset == reg->offset &&
(1 << INTEL_INFO(dev)->gen & entry->gen_bitmask))
break;
}
if (i == ARRAY_SIZE(whitelist))
return -EINVAL;
switch (entry->size) {
case 8:
reg->val = I915_READ64(reg->offset);
break;
case 4:
reg->val = I915_READ(reg->offset);
break;
case 2:
reg->val = I915_READ16(reg->offset);
break;
case 1:
reg->val = I915_READ8(reg->offset);
break;
default:
WARN_ON(1);
return -EINVAL;
}
return 0;
}
