void intel_detect_pch(struct drm_device *dev)
{
struct drm_i915_private *dev_priv = dev->dev_private;
struct pci_dev *pch = NULL;
if (INTEL_INFO(dev)->num_pipes == 0) {
dev_priv->pch_type = PCH_NOP;
return;
}
while ((pch = pci_get_class(PCI_CLASS_BRIDGE_ISA << 8, pch))) {
if (pch->vendor == PCI_VENDOR_ID_INTEL) {
unsigned short id = pch->device & INTEL_PCH_DEVICE_ID_MASK;
dev_priv->pch_id = id;
if (id == INTEL_PCH_IBX_DEVICE_ID_TYPE) {
dev_priv->pch_type = PCH_IBX;
DRM_DEBUG_KMS("Found Ibex Peak PCH\n");
WARN_ON(!IS_GEN5(dev));
} else if (id == INTEL_PCH_CPT_DEVICE_ID_TYPE) {
dev_priv->pch_type = PCH_CPT;
DRM_DEBUG_KMS("Found CougarPoint PCH\n");
WARN_ON(!(IS_GEN6(dev) || IS_IVYBRIDGE(dev)));
} else if (id == INTEL_PCH_PPT_DEVICE_ID_TYPE) {
dev_priv->pch_type = PCH_CPT;
DRM_DEBUG_KMS("Found PantherPoint PCH\n");
WARN_ON(!(IS_GEN6(dev) || IS_IVYBRIDGE(dev)));
} else if (id == INTEL_PCH_LPT_DEVICE_ID_TYPE) {
dev_priv->pch_type = PCH_LPT;
DRM_DEBUG_KMS("Found LynxPoint PCH\n");
WARN_ON(!IS_HASWELL(dev));
WARN_ON(IS_ULT(dev));
} else if (IS_BROADWELL(dev)) {
dev_priv->pch_type = PCH_LPT;
dev_priv->pch_id =
INTEL_PCH_LPT_LP_DEVICE_ID_TYPE;
DRM_DEBUG_KMS("This is Broadwell, assuming "
"LynxPoint LP PCH\n");
} else if (id == INTEL_PCH_LPT_LP_DEVICE_ID_TYPE) {
dev_priv->pch_type = PCH_LPT;
DRM_DEBUG_KMS("Found LynxPoint LP PCH\n");
WARN_ON(!IS_HASWELL(dev));
WARN_ON(!IS_ULT(dev));
} else
continue;
break;
}
}
if (!pch)
DRM_DEBUG_KMS("No PCH found.\n");
pci_dev_put(pch);
}
bool i915_semaphore_is_enabled(struct drm_device *dev)
{
if (INTEL_INFO(dev)->gen < 6)
return false;
if (i915.semaphores >= 0)
return i915.semaphores;
if (IS_GEN8(dev))
return false;
#ifdef CONFIG_INTEL_IOMMU
if (INTEL_INFO(dev)->gen == 6 && intel_iommu_gfx_mapped)
return false;
#endif
return true;
}
static int i915_drm_freeze(struct drm_device *dev)
{
struct drm_i915_private *dev_priv = dev->dev_private;
struct drm_crtc *crtc;
intel_runtime_pm_get(dev_priv);
mutex_lock(&dev_priv->modeset_restore_lock);
dev_priv->modeset_restore = MODESET_SUSPENDED;
mutex_unlock(&dev_priv->modeset_restore_lock);
intel_display_set_init_power(dev_priv, true);
drm_kms_helper_poll_disable(dev);
pci_save_state(dev->pdev);
if (drm_core_check_feature(dev, DRIVER_MODESET)) {
int error;
error = i915_gem_suspend(dev);
if (error) {
dev_err(&dev->pdev->dev,
"GEM idle failed, resume might fail\n");
return error;
}
drm_irq_uninstall(dev);
dev_priv->enable_hotplug_processing = false;
intel_disable_gt_powersave(dev);
drm_modeset_lock_all(dev);
for_each_crtc(dev, crtc) {
dev_priv->display.crtc_disable(crtc);
}
drm_modeset_unlock_all(dev);
intel_modeset_suspend_hw(dev);
}
i915_gem_suspend_gtt_mappings(dev);
i915_save_state(dev);
intel_opregion_fini(dev);
intel_uncore_fini(dev);
console_lock();
intel_fbdev_set_suspend(dev, FBINFO_STATE_SUSPENDED);
console_unlock();
dev_priv->suspend_count++;
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
void intel_console_resume(struct work_struct *work)
{
struct drm_i915_private *dev_priv =
container_of(work, struct drm_i915_private,
console_resume_work);
struct drm_device *dev = dev_priv->dev;
console_lock();
intel_fbdev_set_suspend(dev, FBINFO_STATE_RUNNING);
console_unlock();
}
static int i915_drm_thaw_early(struct drm_device *dev)
{
struct drm_i915_private *dev_priv = dev->dev_private;
intel_uncore_early_sanitize(dev);
intel_uncore_sanitize(dev);
intel_power_domains_init_hw(dev_priv);
return 0;
}
static int __i915_drm_thaw(struct drm_device *dev, bool restore_gtt_mappings)
{
struct drm_i915_private *dev_priv = dev->dev_private;
if (drm_core_check_feature(dev, DRIVER_MODESET) &&
restore_gtt_mappings) {
mutex_lock(&dev->struct_mutex);
i915_gem_restore_gtt_mappings(dev);
mutex_unlock(&dev->struct_mutex);
}
i915_restore_state(dev);
intel_opregion_setup(dev);
if (drm_core_check_feature(dev, DRIVER_MODESET)) {
intel_init_pch_refclk(dev);
drm_mode_config_reset(dev);
mutex_lock(&dev->struct_mutex);
if (i915_gem_init_hw(dev)) {
DRM_ERROR("failed to re-initialize GPU, declaring wedged!\n");
atomic_set_mask(I915_WEDGED, &dev_priv->gpu_error.reset_counter);
}
mutex_unlock(&dev->struct_mutex);
drm_irq_install(dev, dev->pdev->irq);
intel_modeset_init_hw(dev);
drm_modeset_lock_all(dev);
intel_modeset_setup_hw_state(dev, true);
drm_modeset_unlock_all(dev);
intel_hpd_init(dev);
dev_priv->enable_hotplug_processing = true;
drm_helper_hpd_irq_event(dev);
}
intel_opregion_init(dev);
if (console_trylock()) {
intel_fbdev_set_suspend(dev, FBINFO_STATE_RUNNING);
console_unlock();
} else {
schedule_work(&dev_priv->console_resume_work);
}
mutex_lock(&dev_priv->modeset_restore_lock);
dev_priv->modeset_restore = MODESET_DONE;
mutex_unlock(&dev_priv->modeset_restore_lock);
intel_runtime_pm_put(dev_priv);
return 0;
}
static int i915_drm_thaw(struct drm_device *dev)
{
if (drm_core_check_feature(dev, DRIVER_MODESET))
i915_check_and_clear_faults(dev);
return __i915_drm_thaw(dev, true);
}
static int i915_resume_early(struct drm_device *dev)
{
if (dev->switch_power_state == DRM_SWITCH_POWER_OFF)
return 0;
if (pci_enable_device(dev->pdev))
return -EIO;
pci_set_master(dev->pdev);
return i915_drm_thaw_early(dev);
}
int i915_resume(struct drm_device *dev)
{
struct drm_i915_private *dev_priv = dev->dev_private;
int ret;
ret = __i915_drm_thaw(dev, !dev_priv->opregion.header);
if (ret)
return ret;
drm_kms_helper_poll_enable(dev);
return 0;
}
static int i915_resume_legacy(struct drm_device *dev)
{
i915_resume_early(dev);
i915_resume(dev);
return 0;
}
int i915_reset(struct drm_device *dev)
{
struct drm_i915_private *dev_priv = dev->dev_private;
bool simulated;
int ret;
if (!i915.reset)
return 0;
mutex_lock(&dev->struct_mutex);
i915_gem_reset(dev);
simulated = dev_priv->gpu_error.stop_rings != 0;
ret = intel_gpu_reset(dev);
if (simulated) {
DRM_INFO("Simulated gpu hang, resetting stop_rings\n");
dev_priv->gpu_error.stop_rings = 0;
if (ret == -ENODEV) {
DRM_INFO("Reset not implemented, but ignoring "
"error for simulated gpu hangs\n");
ret = 0;
}
}
if (ret) {
DRM_ERROR("Failed to reset chip: %i\n", ret);
mutex_unlock(&dev->struct_mutex);
return ret;
}
if (drm_core_check_feature(dev, DRIVER_MODESET) ||
!dev_priv->ums.mm_suspended) {
dev_priv->ums.mm_suspended = 0;
ret = i915_gem_init_hw(dev);
mutex_unlock(&dev->struct_mutex);
if (ret) {
DRM_ERROR("Failed hw init on reset %d\n", ret);
return ret;
}
if (INTEL_INFO(dev)->gen > 5)
intel_reset_gt_powersave(dev);
intel_hpd_init(dev);
} else {
mutex_unlock(&dev->struct_mutex);
}
return 0;
}
static int i915_pci_probe(struct pci_dev *pdev, const struct pci_device_id *ent)
{
struct intel_device_info *intel_info =
(struct intel_device_info *) ent->driver_data;
if (IS_PRELIMINARY_HW(intel_info) && !i915.preliminary_hw_support) {
DRM_INFO("This hardware requires preliminary hardware support.\n"
"See CONFIG_DRM_I915_PRELIMINARY_HW_SUPPORT, and/or modparam preliminary_hw_support\n");
return -ENODEV;
}
if (PCI_FUNC(pdev->devfn))
return -ENODEV;
driver.driver_features &= ~(DRIVER_USE_AGP);
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
if (!drm_dev || !drm_dev->dev_private) {
dev_err(dev, "DRM not initialized, aborting suspend.\n");
return -ENODEV;
}
if (drm_dev->switch_power_state == DRM_SWITCH_POWER_OFF)
return 0;
return i915_drm_freeze(drm_dev);
}
static int i915_pm_suspend_late(struct device *dev)
{
struct pci_dev *pdev = to_pci_dev(dev);
struct drm_device *drm_dev = pci_get_drvdata(pdev);
if (drm_dev->switch_power_state == DRM_SWITCH_POWER_OFF)
return 0;
pci_disable_device(pdev);
pci_set_power_state(pdev, PCI_D3hot);
return 0;
}
static int i915_pm_resume_early(struct device *dev)
{
struct pci_dev *pdev = to_pci_dev(dev);
struct drm_device *drm_dev = pci_get_drvdata(pdev);
return i915_resume_early(drm_dev);
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
static int i915_pm_thaw_early(struct device *dev)
{
struct pci_dev *pdev = to_pci_dev(dev);
struct drm_device *drm_dev = pci_get_drvdata(pdev);
return i915_drm_thaw_early(drm_dev);
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
static int hsw_runtime_suspend(struct drm_i915_private *dev_priv)
{
hsw_enable_pc8(dev_priv);
return 0;
}
static int snb_runtime_resume(struct drm_i915_private *dev_priv)
{
struct drm_device *dev = dev_priv->dev;
intel_init_pch_refclk(dev);
return 0;
}
static int hsw_runtime_resume(struct drm_i915_private *dev_priv)
{
hsw_disable_pc8(dev_priv);
return 0;
}
static void vlv_save_gunit_s0ix_state(struct drm_i915_private *dev_priv)
{
struct vlv_s0ix_state *s = &dev_priv->vlv_s0ix_state;
int i;
s->wr_watermark = I915_READ(GEN7_WR_WATERMARK);
s->gfx_prio_ctrl = I915_READ(GEN7_GFX_PRIO_CTRL);
s->arb_mode = I915_READ(ARB_MODE);
s->gfx_pend_tlb0 = I915_READ(GEN7_GFX_PEND_TLB0);
s->gfx_pend_tlb1 = I915_READ(GEN7_GFX_PEND_TLB1);
for (i = 0; i < ARRAY_SIZE(s->lra_limits); i++)
s->lra_limits[i] = I915_READ(GEN7_LRA_LIMITS_BASE + i * 4);
s->media_max_req_count = I915_READ(GEN7_MEDIA_MAX_REQ_COUNT);
s->gfx_max_req_count = I915_READ(GEN7_MEDIA_MAX_REQ_COUNT);
s->render_hwsp = I915_READ(RENDER_HWS_PGA_GEN7);
s->ecochk = I915_READ(GAM_ECOCHK);
s->bsd_hwsp = I915_READ(BSD_HWS_PGA_GEN7);
s->blt_hwsp = I915_READ(BLT_HWS_PGA_GEN7);
s->tlb_rd_addr = I915_READ(GEN7_TLB_RD_ADDR);
s->g3dctl = I915_READ(VLV_G3DCTL);
s->gsckgctl = I915_READ(VLV_GSCKGCTL);
s->mbctl = I915_READ(GEN6_MBCTL);
s->ucgctl1 = I915_READ(GEN6_UCGCTL1);
s->ucgctl3 = I915_READ(GEN6_UCGCTL3);
s->rcgctl1 = I915_READ(GEN6_RCGCTL1);
s->rcgctl2 = I915_READ(GEN6_RCGCTL2);
s->rstctl = I915_READ(GEN6_RSTCTL);
s->misccpctl = I915_READ(GEN7_MISCCPCTL);
s->gfxpause = I915_READ(GEN6_GFXPAUSE);
s->rpdeuhwtc = I915_READ(GEN6_RPDEUHWTC);
s->rpdeuc = I915_READ(GEN6_RPDEUC);
s->ecobus = I915_READ(ECOBUS);
s->pwrdwnupctl = I915_READ(VLV_PWRDWNUPCTL);
s->rp_down_timeout = I915_READ(GEN6_RP_DOWN_TIMEOUT);
s->rp_deucsw = I915_READ(GEN6_RPDEUCSW);
s->rcubmabdtmr = I915_READ(GEN6_RCUBMABDTMR);
s->rcedata = I915_READ(VLV_RCEDATA);
s->spare2gh = I915_READ(VLV_SPAREG2H);
s->gt_imr = I915_READ(GTIMR);
s->gt_ier = I915_READ(GTIER);
s->pm_imr = I915_READ(GEN6_PMIMR);
s->pm_ier = I915_READ(GEN6_PMIER);
for (i = 0; i < ARRAY_SIZE(s->gt_scratch); i++)
s->gt_scratch[i] = I915_READ(GEN7_GT_SCRATCH_BASE + i * 4);
s->tilectl = I915_READ(TILECTL);
s->gt_fifoctl = I915_READ(GTFIFOCTL);
s->gtlc_wake_ctrl = I915_READ(VLV_GTLC_WAKE_CTRL);
s->gtlc_survive = I915_READ(VLV_GTLC_SURVIVABILITY_REG);
s->pmwgicz = I915_READ(VLV_PMWGICZ);
s->gu_ctl0 = I915_READ(VLV_GU_CTL0);
s->gu_ctl1 = I915_READ(VLV_GU_CTL1);
s->clock_gate_dis2 = I915_READ(VLV_GUNIT_CLOCK_GATE2);
}
static void vlv_restore_gunit_s0ix_state(struct drm_i915_private *dev_priv)
{
struct vlv_s0ix_state *s = &dev_priv->vlv_s0ix_state;
u32 val;
int i;
I915_WRITE(GEN7_WR_WATERMARK, s->wr_watermark);
I915_WRITE(GEN7_GFX_PRIO_CTRL, s->gfx_prio_ctrl);
I915_WRITE(ARB_MODE, s->arb_mode | (0xffff << 16));
I915_WRITE(GEN7_GFX_PEND_TLB0, s->gfx_pend_tlb0);
I915_WRITE(GEN7_GFX_PEND_TLB1, s->gfx_pend_tlb1);
for (i = 0; i < ARRAY_SIZE(s->lra_limits); i++)
I915_WRITE(GEN7_LRA_LIMITS_BASE + i * 4, s->lra_limits[i]);
I915_WRITE(GEN7_MEDIA_MAX_REQ_COUNT, s->media_max_req_count);
I915_WRITE(GEN7_MEDIA_MAX_REQ_COUNT, s->gfx_max_req_count);
I915_WRITE(RENDER_HWS_PGA_GEN7, s->render_hwsp);
I915_WRITE(GAM_ECOCHK, s->ecochk);
I915_WRITE(BSD_HWS_PGA_GEN7, s->bsd_hwsp);
I915_WRITE(BLT_HWS_PGA_GEN7, s->blt_hwsp);
I915_WRITE(GEN7_TLB_RD_ADDR, s->tlb_rd_addr);
I915_WRITE(VLV_G3DCTL, s->g3dctl);
I915_WRITE(VLV_GSCKGCTL, s->gsckgctl);
I915_WRITE(GEN6_MBCTL, s->mbctl);
I915_WRITE(GEN6_UCGCTL1, s->ucgctl1);
I915_WRITE(GEN6_UCGCTL3, s->ucgctl3);
I915_WRITE(GEN6_RCGCTL1, s->rcgctl1);
I915_WRITE(GEN6_RCGCTL2, s->rcgctl2);
I915_WRITE(GEN6_RSTCTL, s->rstctl);
I915_WRITE(GEN7_MISCCPCTL, s->misccpctl);
I915_WRITE(GEN6_GFXPAUSE, s->gfxpause);
I915_WRITE(GEN6_RPDEUHWTC, s->rpdeuhwtc);
I915_WRITE(GEN6_RPDEUC, s->rpdeuc);
I915_WRITE(ECOBUS, s->ecobus);
I915_WRITE(VLV_PWRDWNUPCTL, s->pwrdwnupctl);
I915_WRITE(GEN6_RP_DOWN_TIMEOUT,s->rp_down_timeout);
I915_WRITE(GEN6_RPDEUCSW, s->rp_deucsw);
I915_WRITE(GEN6_RCUBMABDTMR, s->rcubmabdtmr);
I915_WRITE(VLV_RCEDATA, s->rcedata);
I915_WRITE(VLV_SPAREG2H, s->spare2gh);
I915_WRITE(GTIMR, s->gt_imr);
I915_WRITE(GTIER, s->gt_ier);
I915_WRITE(GEN6_PMIMR, s->pm_imr);
I915_WRITE(GEN6_PMIER, s->pm_ier);
for (i = 0; i < ARRAY_SIZE(s->gt_scratch); i++)
I915_WRITE(GEN7_GT_SCRATCH_BASE + i * 4, s->gt_scratch[i]);
I915_WRITE(TILECTL, s->tilectl);
I915_WRITE(GTFIFOCTL, s->gt_fifoctl);
val = I915_READ(VLV_GTLC_WAKE_CTRL);
val &= VLV_GTLC_ALLOWWAKEREQ;
val |= s->gtlc_wake_ctrl & ~VLV_GTLC_ALLOWWAKEREQ;
I915_WRITE(VLV_GTLC_WAKE_CTRL, val);
val = I915_READ(VLV_GTLC_SURVIVABILITY_REG);
val &= VLV_GFX_CLK_FORCE_ON_BIT;
val |= s->gtlc_survive & ~VLV_GFX_CLK_FORCE_ON_BIT;
I915_WRITE(VLV_GTLC_SURVIVABILITY_REG, val);
I915_WRITE(VLV_PMWGICZ, s->pmwgicz);
I915_WRITE(VLV_GU_CTL0, s->gu_ctl0);
I915_WRITE(VLV_GU_CTL1, s->gu_ctl1);
I915_WRITE(VLV_GUNIT_CLOCK_GATE2, s->clock_gate_dis2);
}
int vlv_force_gfx_clock(struct drm_i915_private *dev_priv, bool force_on)
{
u32 val;
int err;
val = I915_READ(VLV_GTLC_SURVIVABILITY_REG);
WARN_ON(!!(val & VLV_GFX_CLK_FORCE_ON_BIT) == force_on);
#define COND (I915_READ(VLV_GTLC_SURVIVABILITY_REG) & VLV_GFX_CLK_STATUS_BIT)
if (force_on) {
err = wait_for(!COND, 20);
if (err) {
DRM_ERROR("timeout waiting for GFX clock force-off (%08x)\n",
I915_READ(VLV_GTLC_SURVIVABILITY_REG));
return err;
}
}
val = I915_READ(VLV_GTLC_SURVIVABILITY_REG);
val &= ~VLV_GFX_CLK_FORCE_ON_BIT;
if (force_on)
val |= VLV_GFX_CLK_FORCE_ON_BIT;
I915_WRITE(VLV_GTLC_SURVIVABILITY_REG, val);
if (!force_on)
return 0;
err = wait_for(COND, 20);
if (err)
DRM_ERROR("timeout waiting for GFX clock force-on (%08x)\n",
I915_READ(VLV_GTLC_SURVIVABILITY_REG));
return err;
#undef COND
}
static int vlv_allow_gt_wake(struct drm_i915_private *dev_priv, bool allow)
{
u32 val;
int err = 0;
val = I915_READ(VLV_GTLC_WAKE_CTRL);
val &= ~VLV_GTLC_ALLOWWAKEREQ;
if (allow)
val |= VLV_GTLC_ALLOWWAKEREQ;
I915_WRITE(VLV_GTLC_WAKE_CTRL, val);
POSTING_READ(VLV_GTLC_WAKE_CTRL);
#define COND (!!(I915_READ(VLV_GTLC_PW_STATUS) & VLV_GTLC_ALLOWWAKEACK) == \
allow)
err = wait_for(COND, 1);
if (err)
DRM_ERROR("timeout disabling GT waking\n");
return err;
#undef COND
}
static int vlv_wait_for_gt_wells(struct drm_i915_private *dev_priv,
bool wait_for_on)
{
u32 mask;
u32 val;
int err;
mask = VLV_GTLC_PW_MEDIA_STATUS_MASK | VLV_GTLC_PW_RENDER_STATUS_MASK;
val = wait_for_on ? mask : 0;
#define COND ((I915_READ(VLV_GTLC_PW_STATUS) & mask) == val)
if (COND)
return 0;
DRM_DEBUG_KMS("waiting for GT wells to go %s (%08x)\n",
wait_for_on ? "on" : "off",
I915_READ(VLV_GTLC_PW_STATUS));
err = wait_for(COND, 3);
if (err)
DRM_ERROR("timeout waiting for GT wells to go %s\n",
wait_for_on ? "on" : "off");
return err;
#undef COND
}
static void vlv_check_no_gt_access(struct drm_i915_private *dev_priv)
{
if (!(I915_READ(VLV_GTLC_PW_STATUS) & VLV_GTLC_ALLOWWAKEERR))
return;
DRM_ERROR("GT register access while GT waking disabled\n");
I915_WRITE(VLV_GTLC_PW_STATUS, VLV_GTLC_ALLOWWAKEERR);
}
static int vlv_runtime_suspend(struct drm_i915_private *dev_priv)
{
u32 mask;
int err;
(void)vlv_wait_for_gt_wells(dev_priv, false);
mask = VLV_GTLC_RENDER_CTX_EXISTS | VLV_GTLC_MEDIA_CTX_EXISTS;
WARN_ON((I915_READ(VLV_GTLC_WAKE_CTRL) & mask) != mask);
vlv_check_no_gt_access(dev_priv);
err = vlv_force_gfx_clock(dev_priv, true);
if (err)
goto err1;
err = vlv_allow_gt_wake(dev_priv, false);
if (err)
goto err2;
vlv_save_gunit_s0ix_state(dev_priv);
err = vlv_force_gfx_clock(dev_priv, false);
if (err)
goto err2;
return 0;
err2:
vlv_allow_gt_wake(dev_priv, true);
err1:
vlv_force_gfx_clock(dev_priv, false);
return err;
}
static int vlv_runtime_resume(struct drm_i915_private *dev_priv)
{
struct drm_device *dev = dev_priv->dev;
int err;
int ret;
ret = vlv_force_gfx_clock(dev_priv, true);
vlv_restore_gunit_s0ix_state(dev_priv);
err = vlv_allow_gt_wake(dev_priv, true);
if (!ret)
ret = err;
err = vlv_force_gfx_clock(dev_priv, false);
if (!ret)
ret = err;
vlv_check_no_gt_access(dev_priv);
intel_init_clock_gating(dev);
i915_gem_restore_fences(dev);
return ret;
}
static int intel_runtime_suspend(struct device *device)
{
struct pci_dev *pdev = to_pci_dev(device);
struct drm_device *dev = pci_get_drvdata(pdev);
struct drm_i915_private *dev_priv = dev->dev_private;
int ret;
if (WARN_ON_ONCE(!(dev_priv->rps.enabled && intel_enable_rc6(dev))))
return -ENODEV;
WARN_ON(!HAS_RUNTIME_PM(dev));
assert_force_wake_inactive(dev_priv);
DRM_DEBUG_KMS("Suspending device\n");
if (!mutex_trylock(&dev->struct_mutex)) {
DRM_DEBUG_KMS("device lock contention, deffering suspend\n");
pm_runtime_mark_last_busy(device);
return -EAGAIN;
}
i915_gem_release_all_mmaps(dev_priv);
mutex_unlock(&dev->struct_mutex);
cancel_work_sync(&dev_priv->rps.work);
intel_runtime_pm_disable_interrupts(dev);
if (IS_GEN6(dev)) {
ret = 0;
} else if (IS_HASWELL(dev) || IS_BROADWELL(dev)) {
ret = hsw_runtime_suspend(dev_priv);
} else if (IS_VALLEYVIEW(dev)) {
ret = vlv_runtime_suspend(dev_priv);
} else {
ret = -ENODEV;
WARN_ON(1);
}
if (ret) {
DRM_ERROR("Runtime suspend failed, disabling it (%d)\n", ret);
intel_runtime_pm_restore_interrupts(dev);
return ret;
}
del_timer_sync(&dev_priv->gpu_error.hangcheck_timer);
dev_priv->pm.suspended = true;
intel_opregion_notify_adapter(dev, PCI_D1);
DRM_DEBUG_KMS("Device suspended\n");
return 0;
}
static int intel_runtime_resume(struct device *device)
{
struct pci_dev *pdev = to_pci_dev(device);
struct drm_device *dev = pci_get_drvdata(pdev);
struct drm_i915_private *dev_priv = dev->dev_private;
int ret;
WARN_ON(!HAS_RUNTIME_PM(dev));
DRM_DEBUG_KMS("Resuming device\n");
intel_opregion_notify_adapter(dev, PCI_D0);
dev_priv->pm.suspended = false;
if (IS_GEN6(dev)) {
ret = snb_runtime_resume(dev_priv);
} else if (IS_HASWELL(dev) || IS_BROADWELL(dev)) {
ret = hsw_runtime_resume(dev_priv);
} else if (IS_VALLEYVIEW(dev)) {
ret = vlv_runtime_resume(dev_priv);
} else {
WARN_ON(1);
ret = -ENODEV;
}
i915_gem_init_swizzling(dev);
gen6_update_ring_freq(dev);
intel_runtime_pm_restore_interrupts(dev);
intel_reset_gt_powersave(dev);
if (ret)
DRM_ERROR("Runtime resume failed, disabling it (%d)\n", ret);
else
DRM_DEBUG_KMS("Device resumed\n");
return ret;
}
static int __init i915_init(void)
{
driver.num_ioctls = i915_max_ioctl;
#if defined(CONFIG_DRM_I915_KMS)
if (i915.modeset != 0)
driver.driver_features |= DRIVER_MODESET;
#endif
if (i915.modeset == 1)
driver.driver_features |= DRIVER_MODESET;
#ifdef CONFIG_VGA_CONSOLE
if (vgacon_text_force() && i915.modeset == -1)
driver.driver_features &= ~DRIVER_MODESET;
#endif
if (!(driver.driver_features & DRIVER_MODESET)) {
driver.get_vblank_timestamp = NULL;
#ifndef CONFIG_DRM_I915_UMS
DRM_DEBUG_DRIVER("KMS and UMS disabled.\n");
return 0;
#endif
}
return drm_pci_init(&driver, &i915_pci_driver);
}
static void __exit i915_exit(void)
{
#ifndef CONFIG_DRM_I915_UMS
if (!(driver.driver_features & DRIVER_MODESET))
return;
#endif
drm_pci_exit(&driver, &i915_pci_driver);
}
