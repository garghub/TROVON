static enum intel_pch intel_virt_detect_pch(struct drm_device *dev)
{
enum intel_pch ret = PCH_NOP;
if (IS_GEN5(dev)) {
ret = PCH_IBX;
DRM_DEBUG_KMS("Assuming Ibex Peak PCH\n");
} else if (IS_GEN6(dev) || IS_IVYBRIDGE(dev)) {
ret = PCH_CPT;
DRM_DEBUG_KMS("Assuming CouarPoint PCH\n");
} else if (IS_HASWELL(dev) || IS_BROADWELL(dev)) {
ret = PCH_LPT;
DRM_DEBUG_KMS("Assuming LynxPoint PCH\n");
} else if (IS_SKYLAKE(dev) || IS_KABYLAKE(dev)) {
ret = PCH_SPT;
DRM_DEBUG_KMS("Assuming SunrisePoint PCH\n");
}
return ret;
}
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
WARN_ON(!IS_HASWELL(dev) && !IS_BROADWELL(dev));
WARN_ON(IS_HSW_ULT(dev) || IS_BDW_ULT(dev));
} else if (id == INTEL_PCH_LPT_LP_DEVICE_ID_TYPE) {
dev_priv->pch_type = PCH_LPT;
DRM_DEBUG_KMS("Found LynxPoint LP PCH\n");
WARN_ON(!IS_HASWELL(dev) && !IS_BROADWELL(dev));
WARN_ON(!IS_HSW_ULT(dev) && !IS_BDW_ULT(dev));
} else if (id == INTEL_PCH_SPT_DEVICE_ID_TYPE) {
dev_priv->pch_type = PCH_SPT;
DRM_DEBUG_KMS("Found SunrisePoint PCH\n");
WARN_ON(!IS_SKYLAKE(dev) &&
!IS_KABYLAKE(dev));
} else if (id == INTEL_PCH_SPT_LP_DEVICE_ID_TYPE) {
dev_priv->pch_type = PCH_SPT;
DRM_DEBUG_KMS("Found SunrisePoint LP PCH\n");
WARN_ON(!IS_SKYLAKE(dev) &&
!IS_KABYLAKE(dev));
} else if (id == INTEL_PCH_KBP_DEVICE_ID_TYPE) {
dev_priv->pch_type = PCH_KBP;
DRM_DEBUG_KMS("Found KabyPoint PCH\n");
WARN_ON(!IS_KABYLAKE(dev));
} else if ((id == INTEL_PCH_P2X_DEVICE_ID_TYPE) ||
(id == INTEL_PCH_P3X_DEVICE_ID_TYPE) ||
((id == INTEL_PCH_QEMU_DEVICE_ID_TYPE) &&
pch->subsystem_vendor == 0x1af4 &&
pch->subsystem_device == 0x1100)) {
dev_priv->pch_type = intel_virt_detect_pch(dev);
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
if (i915.enable_execlists)
return false;
if (IS_GEN8(dev))
return false;
#ifdef CONFIG_INTEL_IOMMU
if (INTEL_INFO(dev)->gen == 6 && intel_iommu_gfx_mapped)
return false;
#endif
return true;
}
static void intel_suspend_encoders(struct drm_i915_private *dev_priv)
{
struct drm_device *dev = dev_priv->dev;
struct intel_encoder *encoder;
drm_modeset_lock_all(dev);
for_each_intel_encoder(dev, encoder)
if (encoder->suspend)
encoder->suspend(encoder);
drm_modeset_unlock_all(dev);
}
static bool suspend_to_idle(struct drm_i915_private *dev_priv)
{
#if IS_ENABLED(CONFIG_ACPI_SLEEP)
if (acpi_target_system_state() < ACPI_STATE_S3)
return true;
#endif
return false;
}
static int i915_drm_suspend(struct drm_device *dev)
{
struct drm_i915_private *dev_priv = dev->dev_private;
pci_power_t opregion_target_state;
int error;
mutex_lock(&dev_priv->modeset_restore_lock);
dev_priv->modeset_restore = MODESET_SUSPENDED;
mutex_unlock(&dev_priv->modeset_restore_lock);
disable_rpm_wakeref_asserts(dev_priv);
intel_display_set_init_power(dev_priv, true);
drm_kms_helper_poll_disable(dev);
pci_save_state(dev->pdev);
error = i915_gem_suspend(dev);
if (error) {
dev_err(&dev->pdev->dev,
"GEM idle failed, resume might fail\n");
goto out;
}
intel_guc_suspend(dev);
intel_suspend_gt_powersave(dev);
intel_display_suspend(dev);
intel_dp_mst_suspend(dev);
intel_runtime_pm_disable_interrupts(dev_priv);
intel_hpd_cancel_work(dev_priv);
intel_suspend_encoders(dev_priv);
intel_suspend_hw(dev);
i915_gem_suspend_gtt_mappings(dev);
i915_save_state(dev);
opregion_target_state = suspend_to_idle(dev_priv) ? PCI_D1 : PCI_D3cold;
intel_opregion_notify_adapter(dev, opregion_target_state);
intel_uncore_forcewake_reset(dev, false);
intel_opregion_fini(dev);
intel_fbdev_set_suspend(dev, FBINFO_STATE_SUSPENDED, true);
dev_priv->suspend_count++;
intel_display_set_init_power(dev_priv, false);
intel_csr_ucode_suspend(dev_priv);
out:
enable_rpm_wakeref_asserts(dev_priv);
return error;
}
static int i915_drm_suspend_late(struct drm_device *drm_dev, bool hibernation)
{
struct drm_i915_private *dev_priv = drm_dev->dev_private;
bool fw_csr;
int ret;
disable_rpm_wakeref_asserts(dev_priv);
fw_csr = !IS_BROXTON(dev_priv) &&
suspend_to_idle(dev_priv) && dev_priv->csr.dmc_payload;
if (!fw_csr)
intel_power_domains_suspend(dev_priv);
ret = 0;
if (IS_BROXTON(dev_priv))
bxt_enable_dc9(dev_priv);
else if (IS_HASWELL(dev_priv) || IS_BROADWELL(dev_priv))
hsw_enable_pc8(dev_priv);
else if (IS_VALLEYVIEW(dev_priv) || IS_CHERRYVIEW(dev_priv))
ret = vlv_suspend_complete(dev_priv);
if (ret) {
DRM_ERROR("Suspend complete failed: %d\n", ret);
if (!fw_csr)
intel_power_domains_init_hw(dev_priv, true);
goto out;
}
pci_disable_device(drm_dev->pdev);
if (!(hibernation && INTEL_INFO(dev_priv)->gen < 6))
pci_set_power_state(drm_dev->pdev, PCI_D3hot);
dev_priv->suspended_to_idle = suspend_to_idle(dev_priv);
out:
enable_rpm_wakeref_asserts(dev_priv);
return ret;
}
int i915_suspend_switcheroo(struct drm_device *dev, pm_message_t state)
{
int error;
if (!dev || !dev->dev_private) {
DRM_ERROR("dev: %p\n", dev);
DRM_ERROR("DRM not initialized, aborting suspend.\n");
return -ENODEV;
}
if (WARN_ON_ONCE(state.event != PM_EVENT_SUSPEND &&
state.event != PM_EVENT_FREEZE))
return -EINVAL;
if (dev->switch_power_state == DRM_SWITCH_POWER_OFF)
return 0;
error = i915_drm_suspend(dev);
if (error)
return error;
return i915_drm_suspend_late(dev, false);
}
static int i915_drm_resume(struct drm_device *dev)
{
struct drm_i915_private *dev_priv = dev->dev_private;
int ret;
disable_rpm_wakeref_asserts(dev_priv);
ret = i915_ggtt_enable_hw(dev);
if (ret)
DRM_ERROR("failed to re-enable GGTT\n");
intel_csr_ucode_resume(dev_priv);
mutex_lock(&dev->struct_mutex);
i915_gem_restore_gtt_mappings(dev);
mutex_unlock(&dev->struct_mutex);
i915_restore_state(dev);
intel_opregion_setup(dev);
intel_init_pch_refclk(dev);
drm_mode_config_reset(dev);
intel_runtime_pm_enable_interrupts(dev_priv);
mutex_lock(&dev->struct_mutex);
if (i915_gem_init_hw(dev)) {
DRM_ERROR("failed to re-initialize GPU, declaring wedged!\n");
atomic_or(I915_WEDGED, &dev_priv->gpu_error.reset_counter);
}
mutex_unlock(&dev->struct_mutex);
intel_guc_resume(dev);
intel_modeset_init_hw(dev);
spin_lock_irq(&dev_priv->irq_lock);
if (dev_priv->display.hpd_irq_setup)
dev_priv->display.hpd_irq_setup(dev);
spin_unlock_irq(&dev_priv->irq_lock);
intel_dp_mst_resume(dev);
intel_display_resume(dev);
intel_hpd_init(dev_priv);
drm_helper_hpd_irq_event(dev);
intel_opregion_init(dev);
intel_fbdev_set_suspend(dev, FBINFO_STATE_RUNNING, false);
mutex_lock(&dev_priv->modeset_restore_lock);
dev_priv->modeset_restore = MODESET_DONE;
mutex_unlock(&dev_priv->modeset_restore_lock);
intel_opregion_notify_adapter(dev, PCI_D0);
drm_kms_helper_poll_enable(dev);
enable_rpm_wakeref_asserts(dev_priv);
return 0;
}
static int i915_drm_resume_early(struct drm_device *dev)
{
struct drm_i915_private *dev_priv = dev->dev_private;
int ret;
ret = pci_set_power_state(dev->pdev, PCI_D0);
if (ret) {
DRM_ERROR("failed to set PCI D0 power state (%d)\n", ret);
goto out;
}
if (pci_enable_device(dev->pdev)) {
ret = -EIO;
goto out;
}
pci_set_master(dev->pdev);
disable_rpm_wakeref_asserts(dev_priv);
if (IS_VALLEYVIEW(dev_priv) || IS_CHERRYVIEW(dev_priv))
ret = vlv_resume_prepare(dev_priv, false);
if (ret)
DRM_ERROR("Resume prepare failed: %d, continuing anyway\n",
ret);
intel_uncore_early_sanitize(dev, true);
if (IS_BROXTON(dev)) {
if (!dev_priv->suspended_to_idle)
gen9_sanitize_dc_state(dev_priv);
bxt_disable_dc9(dev_priv);
} else if (IS_HASWELL(dev_priv) || IS_BROADWELL(dev_priv)) {
hsw_disable_pc8(dev_priv);
}
intel_uncore_sanitize(dev);
if (IS_BROXTON(dev_priv) ||
!(dev_priv->suspended_to_idle && dev_priv->csr.dmc_payload))
intel_power_domains_init_hw(dev_priv, true);
enable_rpm_wakeref_asserts(dev_priv);
out:
dev_priv->suspended_to_idle = false;
return ret;
}
int i915_resume_switcheroo(struct drm_device *dev)
{
int ret;
if (dev->switch_power_state == DRM_SWITCH_POWER_OFF)
return 0;
ret = i915_drm_resume_early(dev);
if (ret)
return ret;
return i915_drm_resume(dev);
}
int i915_reset(struct drm_device *dev)
{
struct drm_i915_private *dev_priv = dev->dev_private;
struct i915_gpu_error *error = &dev_priv->gpu_error;
unsigned reset_counter;
int ret;
intel_reset_gt_powersave(dev);
mutex_lock(&dev->struct_mutex);
atomic_andnot(I915_WEDGED, &error->reset_counter);
reset_counter = atomic_inc_return(&error->reset_counter);
if (WARN_ON(__i915_reset_in_progress(reset_counter))) {
ret = -EIO;
goto error;
}
i915_gem_reset(dev);
ret = intel_gpu_reset(dev, ALL_ENGINES);
if (error->stop_rings != 0) {
DRM_INFO("Simulated gpu hang, resetting stop_rings\n");
error->stop_rings = 0;
if (ret == -ENODEV) {
DRM_INFO("Reset not implemented, but ignoring "
"error for simulated gpu hangs\n");
ret = 0;
}
}
if (i915_stop_ring_allow_warn(dev_priv))
pr_notice("drm/i915: Resetting chip after gpu hang\n");
if (ret) {
if (ret != -ENODEV)
DRM_ERROR("Failed to reset chip: %i\n", ret);
else
DRM_DEBUG_DRIVER("GPU reset disabled\n");
goto error;
}
intel_overlay_reset(dev_priv);
ret = i915_gem_init_hw(dev);
if (ret) {
DRM_ERROR("Failed hw init on reset %d\n", ret);
goto error;
}
mutex_unlock(&dev->struct_mutex);
if (INTEL_INFO(dev)->gen > 5)
intel_enable_gt_powersave(dev);
return 0;
error:
atomic_or(I915_WEDGED, &error->reset_counter);
mutex_unlock(&dev->struct_mutex);
return ret;
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
if (IS_ENABLED(CONFIG_VGA_ARB) && IS_ENABLED(CONFIG_VGA_SWITCHEROO) &&
apple_gmux_present() && pdev != vga_default_device() &&
!vga_switcheroo_handler_flags())
return -EPROBE_DEFER;
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
return i915_drm_suspend(drm_dev);
}
static int i915_pm_suspend_late(struct device *dev)
{
struct drm_device *drm_dev = dev_to_i915(dev)->dev;
if (drm_dev->switch_power_state == DRM_SWITCH_POWER_OFF)
return 0;
return i915_drm_suspend_late(drm_dev, false);
}
static int i915_pm_poweroff_late(struct device *dev)
{
struct drm_device *drm_dev = dev_to_i915(dev)->dev;
if (drm_dev->switch_power_state == DRM_SWITCH_POWER_OFF)
return 0;
return i915_drm_suspend_late(drm_dev, true);
}
static int i915_pm_resume_early(struct device *dev)
{
struct drm_device *drm_dev = dev_to_i915(dev)->dev;
if (drm_dev->switch_power_state == DRM_SWITCH_POWER_OFF)
return 0;
return i915_drm_resume_early(drm_dev);
}
static int i915_pm_resume(struct device *dev)
{
struct drm_device *drm_dev = dev_to_i915(dev)->dev;
if (drm_dev->switch_power_state == DRM_SWITCH_POWER_OFF)
return 0;
return i915_drm_resume(drm_dev);
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
s->lra_limits[i] = I915_READ(GEN7_LRA_LIMITS(i));
s->media_max_req_count = I915_READ(GEN7_MEDIA_MAX_REQ_COUNT);
s->gfx_max_req_count = I915_READ(GEN7_GFX_MAX_REQ_COUNT);
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
s->gt_scratch[i] = I915_READ(GEN7_GT_SCRATCH(i));
s->tilectl = I915_READ(TILECTL);
s->gt_fifoctl = I915_READ(GTFIFOCTL);
s->gtlc_wake_ctrl = I915_READ(VLV_GTLC_WAKE_CTRL);
s->gtlc_survive = I915_READ(VLV_GTLC_SURVIVABILITY_REG);
s->pmwgicz = I915_READ(VLV_PMWGICZ);
s->gu_ctl0 = I915_READ(VLV_GU_CTL0);
s->gu_ctl1 = I915_READ(VLV_GU_CTL1);
s->pcbr = I915_READ(VLV_PCBR);
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
I915_WRITE(GEN7_LRA_LIMITS(i), s->lra_limits[i]);
I915_WRITE(GEN7_MEDIA_MAX_REQ_COUNT, s->media_max_req_count);
I915_WRITE(GEN7_GFX_MAX_REQ_COUNT, s->gfx_max_req_count);
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
I915_WRITE(GEN7_GT_SCRATCH(i), s->gt_scratch[i]);
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
I915_WRITE(VLV_PCBR, s->pcbr);
I915_WRITE(VLV_GUNIT_CLOCK_GATE2, s->clock_gate_dis2);
}
int vlv_force_gfx_clock(struct drm_i915_private *dev_priv, bool force_on)
{
u32 val;
int err;
#define COND (I915_READ(VLV_GTLC_SURVIVABILITY_REG) & VLV_GFX_CLK_STATUS_BIT)
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
onoff(wait_for_on),
I915_READ(VLV_GTLC_PW_STATUS));
err = wait_for(COND, 3);
if (err)
DRM_ERROR("timeout waiting for GT wells to go %s\n",
onoff(wait_for_on));
return err;
#undef COND
}
static void vlv_check_no_gt_access(struct drm_i915_private *dev_priv)
{
if (!(I915_READ(VLV_GTLC_PW_STATUS) & VLV_GTLC_ALLOWWAKEERR))
return;
DRM_DEBUG_DRIVER("GT register access while GT waking disabled\n");
I915_WRITE(VLV_GTLC_PW_STATUS, VLV_GTLC_ALLOWWAKEERR);
}
static int vlv_suspend_complete(struct drm_i915_private *dev_priv)
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
if (!IS_CHERRYVIEW(dev_priv))
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
static int vlv_resume_prepare(struct drm_i915_private *dev_priv,
bool rpm_resume)
{
struct drm_device *dev = dev_priv->dev;
int err;
int ret;
ret = vlv_force_gfx_clock(dev_priv, true);
if (!IS_CHERRYVIEW(dev_priv))
vlv_restore_gunit_s0ix_state(dev_priv);
err = vlv_allow_gt_wake(dev_priv, true);
if (!ret)
ret = err;
err = vlv_force_gfx_clock(dev_priv, false);
if (!ret)
ret = err;
vlv_check_no_gt_access(dev_priv);
if (rpm_resume) {
intel_init_clock_gating(dev);
i915_gem_restore_fences(dev);
}
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
if (WARN_ON_ONCE(!HAS_RUNTIME_PM(dev)))
return -ENODEV;
DRM_DEBUG_KMS("Suspending device\n");
if (!mutex_trylock(&dev->struct_mutex)) {
DRM_DEBUG_KMS("device lock contention, deffering suspend\n");
pm_runtime_mark_last_busy(device);
return -EAGAIN;
}
disable_rpm_wakeref_asserts(dev_priv);
i915_gem_release_all_mmaps(dev_priv);
mutex_unlock(&dev->struct_mutex);
cancel_delayed_work_sync(&dev_priv->gpu_error.hangcheck_work);
intel_guc_suspend(dev);
intel_suspend_gt_powersave(dev);
intel_runtime_pm_disable_interrupts(dev_priv);
ret = 0;
if (IS_BROXTON(dev_priv)) {
bxt_display_core_uninit(dev_priv);
bxt_enable_dc9(dev_priv);
} else if (IS_HASWELL(dev_priv) || IS_BROADWELL(dev_priv)) {
hsw_enable_pc8(dev_priv);
} else if (IS_VALLEYVIEW(dev_priv) || IS_CHERRYVIEW(dev_priv)) {
ret = vlv_suspend_complete(dev_priv);
}
if (ret) {
DRM_ERROR("Runtime suspend failed, disabling it (%d)\n", ret);
intel_runtime_pm_enable_interrupts(dev_priv);
enable_rpm_wakeref_asserts(dev_priv);
return ret;
}
intel_uncore_forcewake_reset(dev, false);
enable_rpm_wakeref_asserts(dev_priv);
WARN_ON_ONCE(atomic_read(&dev_priv->pm.wakeref_count));
if (intel_uncore_arm_unclaimed_mmio_detection(dev_priv))
DRM_ERROR("Unclaimed access detected prior to suspending\n");
dev_priv->pm.suspended = true;
if (IS_BROADWELL(dev)) {
intel_opregion_notify_adapter(dev, PCI_D3hot);
} else {
intel_opregion_notify_adapter(dev, PCI_D1);
}
assert_forcewakes_inactive(dev_priv);
DRM_DEBUG_KMS("Device suspended\n");
return 0;
}
static int intel_runtime_resume(struct device *device)
{
struct pci_dev *pdev = to_pci_dev(device);
struct drm_device *dev = pci_get_drvdata(pdev);
struct drm_i915_private *dev_priv = dev->dev_private;
int ret = 0;
if (WARN_ON_ONCE(!HAS_RUNTIME_PM(dev)))
return -ENODEV;
DRM_DEBUG_KMS("Resuming device\n");
WARN_ON_ONCE(atomic_read(&dev_priv->pm.wakeref_count));
disable_rpm_wakeref_asserts(dev_priv);
intel_opregion_notify_adapter(dev, PCI_D0);
dev_priv->pm.suspended = false;
if (intel_uncore_unclaimed_mmio(dev_priv))
DRM_DEBUG_DRIVER("Unclaimed access during suspend, bios?\n");
intel_guc_resume(dev);
if (IS_GEN6(dev_priv))
intel_init_pch_refclk(dev);
if (IS_BROXTON(dev)) {
bxt_disable_dc9(dev_priv);
bxt_display_core_init(dev_priv, true);
if (dev_priv->csr.dmc_payload &&
(dev_priv->csr.allowed_dc_mask & DC_STATE_EN_UPTO_DC5))
gen9_enable_dc5(dev_priv);
} else if (IS_HASWELL(dev_priv) || IS_BROADWELL(dev_priv)) {
hsw_disable_pc8(dev_priv);
} else if (IS_VALLEYVIEW(dev_priv) || IS_CHERRYVIEW(dev_priv)) {
ret = vlv_resume_prepare(dev_priv, true);
}
i915_gem_init_swizzling(dev);
gen6_update_ring_freq(dev);
intel_runtime_pm_enable_interrupts(dev_priv);
if (!IS_VALLEYVIEW(dev_priv) && !IS_CHERRYVIEW(dev_priv))
intel_hpd_init(dev_priv);
intel_enable_gt_powersave(dev);
enable_rpm_wakeref_asserts(dev_priv);
if (ret)
DRM_ERROR("Runtime resume failed, disabling it (%d)\n", ret);
else
DRM_DEBUG_KMS("Device resumed\n");
return ret;
}
static int __init i915_init(void)
{
driver.num_ioctls = i915_max_ioctl;
if (i915.modeset == 0)
driver.driver_features &= ~DRIVER_MODESET;
if (vgacon_text_force() && i915.modeset == -1)
driver.driver_features &= ~DRIVER_MODESET;
if (!(driver.driver_features & DRIVER_MODESET)) {
DRM_DEBUG_DRIVER("KMS and UMS disabled.\n");
return 0;
}
if (i915.nuclear_pageflip)
driver.driver_features |= DRIVER_ATOMIC;
return drm_pci_init(&driver, &i915_pci_driver);
}
static void __exit i915_exit(void)
{
if (!(driver.driver_features & DRIVER_MODESET))
return;
drm_pci_exit(&driver, &i915_pci_driver);
}
