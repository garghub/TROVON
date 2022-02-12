bool __i915_inject_load_failure(const char *func, int line)
{
if (i915_load_fail_count >= i915.inject_load_failure)
return false;
if (++i915_load_fail_count == i915.inject_load_failure) {
DRM_INFO("Injecting failure at checkpoint %u [%s:%d]\n",
i915.inject_load_failure, func, line);
return true;
}
return false;
}
void
__i915_printk(struct drm_i915_private *dev_priv, const char *level,
const char *fmt, ...)
{
static bool shown_bug_once;
struct device *kdev = dev_priv->drm.dev;
bool is_error = level[1] <= KERN_ERR[1];
bool is_debug = level[1] == KERN_DEBUG[1];
struct va_format vaf;
va_list args;
if (is_debug && !(drm_debug & DRM_UT_DRIVER))
return;
va_start(args, fmt);
vaf.fmt = fmt;
vaf.va = &args;
dev_printk(level, kdev, "[" DRM_NAME ":%ps] %pV",
__builtin_return_address(0), &vaf);
if (is_error && !shown_bug_once) {
dev_notice(kdev, "%s", FDO_BUG_MSG);
shown_bug_once = true;
}
va_end(args);
}
static bool i915_error_injected(struct drm_i915_private *dev_priv)
{
return i915.inject_load_failure &&
i915_load_fail_count == i915.inject_load_failure;
}
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
static void intel_detect_pch(struct drm_device *dev)
{
struct drm_i915_private *dev_priv = to_i915(dev);
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
pch->subsystem_vendor ==
PCI_SUBVENDOR_ID_REDHAT_QUMRANET &&
pch->subsystem_device ==
PCI_SUBDEVICE_ID_QEMU)) {
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
static int i915_getparam(struct drm_device *dev, void *data,
struct drm_file *file_priv)
{
struct drm_i915_private *dev_priv = to_i915(dev);
struct pci_dev *pdev = dev_priv->drm.pdev;
drm_i915_getparam_t *param = data;
int value;
switch (param->param) {
case I915_PARAM_IRQ_ACTIVE:
case I915_PARAM_ALLOW_BATCHBUFFER:
case I915_PARAM_LAST_DISPATCH:
return -ENODEV;
case I915_PARAM_CHIPSET_ID:
value = pdev->device;
break;
case I915_PARAM_REVISION:
value = pdev->revision;
break;
case I915_PARAM_NUM_FENCES_AVAIL:
value = dev_priv->num_fence_regs;
break;
case I915_PARAM_HAS_OVERLAY:
value = dev_priv->overlay ? 1 : 0;
break;
case I915_PARAM_HAS_BSD:
value = intel_engine_initialized(&dev_priv->engine[VCS]);
break;
case I915_PARAM_HAS_BLT:
value = intel_engine_initialized(&dev_priv->engine[BCS]);
break;
case I915_PARAM_HAS_VEBOX:
value = intel_engine_initialized(&dev_priv->engine[VECS]);
break;
case I915_PARAM_HAS_BSD2:
value = intel_engine_initialized(&dev_priv->engine[VCS2]);
break;
case I915_PARAM_HAS_EXEC_CONSTANTS:
value = INTEL_GEN(dev_priv) >= 4;
break;
case I915_PARAM_HAS_LLC:
value = HAS_LLC(dev_priv);
break;
case I915_PARAM_HAS_WT:
value = HAS_WT(dev_priv);
break;
case I915_PARAM_HAS_ALIASING_PPGTT:
value = USES_PPGTT(dev_priv);
break;
case I915_PARAM_HAS_SEMAPHORES:
value = i915.semaphores;
break;
case I915_PARAM_HAS_SECURE_BATCHES:
value = capable(CAP_SYS_ADMIN);
break;
case I915_PARAM_CMD_PARSER_VERSION:
value = i915_cmd_parser_get_version(dev_priv);
break;
case I915_PARAM_SUBSLICE_TOTAL:
value = sseu_subslice_total(&INTEL_INFO(dev_priv)->sseu);
if (!value)
return -ENODEV;
break;
case I915_PARAM_EU_TOTAL:
value = INTEL_INFO(dev_priv)->sseu.eu_total;
if (!value)
return -ENODEV;
break;
case I915_PARAM_HAS_GPU_RESET:
value = i915.enable_hangcheck && intel_has_gpu_reset(dev_priv);
break;
case I915_PARAM_HAS_RESOURCE_STREAMER:
value = HAS_RESOURCE_STREAMER(dev_priv);
break;
case I915_PARAM_HAS_POOLED_EU:
value = HAS_POOLED_EU(dev_priv);
break;
case I915_PARAM_MIN_EU_IN_POOL:
value = INTEL_INFO(dev_priv)->sseu.min_eu_in_pool;
break;
case I915_PARAM_MMAP_GTT_VERSION:
value = i915_gem_mmap_gtt_version();
break;
case I915_PARAM_MMAP_VERSION:
case I915_PARAM_HAS_GEM:
case I915_PARAM_HAS_PAGEFLIPPING:
case I915_PARAM_HAS_EXECBUF2:
case I915_PARAM_HAS_RELAXED_FENCING:
case I915_PARAM_HAS_COHERENT_RINGS:
case I915_PARAM_HAS_RELAXED_DELTA:
case I915_PARAM_HAS_GEN7_SOL_RESET:
case I915_PARAM_HAS_WAIT_TIMEOUT:
case I915_PARAM_HAS_PRIME_VMAP_FLUSH:
case I915_PARAM_HAS_PINNED_BATCHES:
case I915_PARAM_HAS_EXEC_NO_RELOC:
case I915_PARAM_HAS_EXEC_HANDLE_LUT:
case I915_PARAM_HAS_COHERENT_PHYS_GTT:
case I915_PARAM_HAS_EXEC_SOFTPIN:
value = 1;
break;
default:
DRM_DEBUG("Unknown parameter %d\n", param->param);
return -EINVAL;
}
if (put_user(value, param->value))
return -EFAULT;
return 0;
}
static int i915_get_bridge_dev(struct drm_device *dev)
{
struct drm_i915_private *dev_priv = to_i915(dev);
dev_priv->bridge_dev = pci_get_bus_and_slot(0, PCI_DEVFN(0, 0));
if (!dev_priv->bridge_dev) {
DRM_ERROR("bridge device not found\n");
return -1;
}
return 0;
}
static int
intel_alloc_mchbar_resource(struct drm_device *dev)
{
struct drm_i915_private *dev_priv = to_i915(dev);
int reg = INTEL_INFO(dev)->gen >= 4 ? MCHBAR_I965 : MCHBAR_I915;
u32 temp_lo, temp_hi = 0;
u64 mchbar_addr;
int ret;
if (INTEL_INFO(dev)->gen >= 4)
pci_read_config_dword(dev_priv->bridge_dev, reg + 4, &temp_hi);
pci_read_config_dword(dev_priv->bridge_dev, reg, &temp_lo);
mchbar_addr = ((u64)temp_hi << 32) | temp_lo;
#ifdef CONFIG_PNP
if (mchbar_addr &&
pnp_range_reserved(mchbar_addr, mchbar_addr + MCHBAR_SIZE))
return 0;
#endif
dev_priv->mch_res.name = "i915 MCHBAR";
dev_priv->mch_res.flags = IORESOURCE_MEM;
ret = pci_bus_alloc_resource(dev_priv->bridge_dev->bus,
&dev_priv->mch_res,
MCHBAR_SIZE, MCHBAR_SIZE,
PCIBIOS_MIN_MEM,
0, pcibios_align_resource,
dev_priv->bridge_dev);
if (ret) {
DRM_DEBUG_DRIVER("failed bus alloc: %d\n", ret);
dev_priv->mch_res.start = 0;
return ret;
}
if (INTEL_INFO(dev)->gen >= 4)
pci_write_config_dword(dev_priv->bridge_dev, reg + 4,
upper_32_bits(dev_priv->mch_res.start));
pci_write_config_dword(dev_priv->bridge_dev, reg,
lower_32_bits(dev_priv->mch_res.start));
return 0;
}
static void
intel_setup_mchbar(struct drm_device *dev)
{
struct drm_i915_private *dev_priv = to_i915(dev);
int mchbar_reg = INTEL_INFO(dev)->gen >= 4 ? MCHBAR_I965 : MCHBAR_I915;
u32 temp;
bool enabled;
if (IS_VALLEYVIEW(dev) || IS_CHERRYVIEW(dev))
return;
dev_priv->mchbar_need_disable = false;
if (IS_I915G(dev) || IS_I915GM(dev)) {
pci_read_config_dword(dev_priv->bridge_dev, DEVEN, &temp);
enabled = !!(temp & DEVEN_MCHBAR_EN);
} else {
pci_read_config_dword(dev_priv->bridge_dev, mchbar_reg, &temp);
enabled = temp & 1;
}
if (enabled)
return;
if (intel_alloc_mchbar_resource(dev))
return;
dev_priv->mchbar_need_disable = true;
if (IS_I915G(dev) || IS_I915GM(dev)) {
pci_write_config_dword(dev_priv->bridge_dev, DEVEN,
temp | DEVEN_MCHBAR_EN);
} else {
pci_read_config_dword(dev_priv->bridge_dev, mchbar_reg, &temp);
pci_write_config_dword(dev_priv->bridge_dev, mchbar_reg, temp | 1);
}
}
static void
intel_teardown_mchbar(struct drm_device *dev)
{
struct drm_i915_private *dev_priv = to_i915(dev);
int mchbar_reg = INTEL_INFO(dev)->gen >= 4 ? MCHBAR_I965 : MCHBAR_I915;
if (dev_priv->mchbar_need_disable) {
if (IS_I915G(dev) || IS_I915GM(dev)) {
u32 deven_val;
pci_read_config_dword(dev_priv->bridge_dev, DEVEN,
&deven_val);
deven_val &= ~DEVEN_MCHBAR_EN;
pci_write_config_dword(dev_priv->bridge_dev, DEVEN,
deven_val);
} else {
u32 mchbar_val;
pci_read_config_dword(dev_priv->bridge_dev, mchbar_reg,
&mchbar_val);
mchbar_val &= ~1;
pci_write_config_dword(dev_priv->bridge_dev, mchbar_reg,
mchbar_val);
}
}
if (dev_priv->mch_res.start)
release_resource(&dev_priv->mch_res);
}
static unsigned int i915_vga_set_decode(void *cookie, bool state)
{
struct drm_device *dev = cookie;
intel_modeset_vga_set_state(dev, state);
if (state)
return VGA_RSRC_LEGACY_IO | VGA_RSRC_LEGACY_MEM |
VGA_RSRC_NORMAL_IO | VGA_RSRC_NORMAL_MEM;
else
return VGA_RSRC_NORMAL_IO | VGA_RSRC_NORMAL_MEM;
}
static void i915_switcheroo_set_state(struct pci_dev *pdev, enum vga_switcheroo_state state)
{
struct drm_device *dev = pci_get_drvdata(pdev);
pm_message_t pmm = { .event = PM_EVENT_SUSPEND };
if (state == VGA_SWITCHEROO_ON) {
pr_info("switched on\n");
dev->switch_power_state = DRM_SWITCH_POWER_CHANGING;
pci_set_power_state(pdev, PCI_D0);
i915_resume_switcheroo(dev);
dev->switch_power_state = DRM_SWITCH_POWER_ON;
} else {
pr_info("switched off\n");
dev->switch_power_state = DRM_SWITCH_POWER_CHANGING;
i915_suspend_switcheroo(dev, pmm);
dev->switch_power_state = DRM_SWITCH_POWER_OFF;
}
}
static bool i915_switcheroo_can_switch(struct pci_dev *pdev)
{
struct drm_device *dev = pci_get_drvdata(pdev);
return dev->open_count == 0;
}
static void i915_gem_fini(struct drm_device *dev)
{
struct drm_i915_private *dev_priv = to_i915(dev);
if (HAS_HW_CONTEXTS(dev)) {
int reset = intel_gpu_reset(dev_priv, ALL_ENGINES);
WARN_ON(reset && reset != -ENODEV);
}
mutex_lock(&dev->struct_mutex);
i915_gem_cleanup_engines(dev);
i915_gem_context_fini(dev);
mutex_unlock(&dev->struct_mutex);
WARN_ON(!list_empty(&to_i915(dev)->context_list));
}
static int i915_load_modeset_init(struct drm_device *dev)
{
struct drm_i915_private *dev_priv = to_i915(dev);
struct pci_dev *pdev = dev_priv->drm.pdev;
int ret;
if (i915_inject_load_failure())
return -ENODEV;
ret = intel_bios_init(dev_priv);
if (ret)
DRM_INFO("failed to find VBIOS tables\n");
ret = vga_client_register(pdev, dev, NULL, i915_vga_set_decode);
if (ret && ret != -ENODEV)
goto out;
intel_register_dsm_handler();
ret = vga_switcheroo_register_client(pdev, &i915_switcheroo_ops, false);
if (ret)
goto cleanup_vga_client;
intel_update_rawclk(dev_priv);
intel_power_domains_init_hw(dev_priv, false);
intel_csr_ucode_init(dev_priv);
ret = intel_irq_install(dev_priv);
if (ret)
goto cleanup_csr;
intel_setup_gmbus(dev);
intel_modeset_init(dev);
intel_guc_init(dev);
ret = i915_gem_init(dev);
if (ret)
goto cleanup_irq;
intel_modeset_gem_init(dev);
if (INTEL_INFO(dev)->num_pipes == 0)
return 0;
ret = intel_fbdev_init(dev);
if (ret)
goto cleanup_gem;
intel_hpd_init(dev_priv);
drm_kms_helper_poll_init(dev);
return 0;
cleanup_gem:
i915_gem_fini(dev);
cleanup_irq:
intel_guc_fini(dev);
drm_irq_uninstall(dev);
intel_teardown_gmbus(dev);
cleanup_csr:
intel_csr_ucode_fini(dev_priv);
intel_power_domains_fini(dev_priv);
vga_switcheroo_unregister_client(pdev);
cleanup_vga_client:
vga_client_register(pdev, NULL, NULL, NULL);
out:
return ret;
}
static int i915_kick_out_firmware_fb(struct drm_i915_private *dev_priv)
{
struct apertures_struct *ap;
struct pci_dev *pdev = dev_priv->drm.pdev;
struct i915_ggtt *ggtt = &dev_priv->ggtt;
bool primary;
int ret;
ap = alloc_apertures(1);
if (!ap)
return -ENOMEM;
ap->ranges[0].base = ggtt->mappable_base;
ap->ranges[0].size = ggtt->mappable_end;
primary =
pdev->resource[PCI_ROM_RESOURCE].flags & IORESOURCE_ROM_SHADOW;
ret = drm_fb_helper_remove_conflicting_framebuffers(ap, "inteldrmfb", primary);
kfree(ap);
return ret;
}
static int i915_kick_out_firmware_fb(struct drm_i915_private *dev_priv)
{
return 0;
}
static int i915_kick_out_vgacon(struct drm_i915_private *dev_priv)
{
return 0;
}
static int i915_kick_out_vgacon(struct drm_i915_private *dev_priv)
{
return -ENODEV;
}
static int i915_kick_out_vgacon(struct drm_i915_private *dev_priv)
{
int ret = 0;
DRM_INFO("Replacing VGA console driver\n");
console_lock();
if (con_is_bound(&vga_con))
ret = do_take_over_console(&dummy_con, 0, MAX_NR_CONSOLES - 1, 1);
if (ret == 0) {
ret = do_unregister_con_driver(&vga_con);
if (ret == -ENODEV)
ret = 0;
}
console_unlock();
return ret;
}
static void intel_init_dpio(struct drm_i915_private *dev_priv)
{
if (IS_CHERRYVIEW(dev_priv)) {
DPIO_PHY_IOSF_PORT(DPIO_PHY0) = IOSF_PORT_DPIO_2;
DPIO_PHY_IOSF_PORT(DPIO_PHY1) = IOSF_PORT_DPIO;
} else if (IS_VALLEYVIEW(dev_priv)) {
DPIO_PHY_IOSF_PORT(DPIO_PHY0) = IOSF_PORT_DPIO;
}
}
static int i915_workqueues_init(struct drm_i915_private *dev_priv)
{
dev_priv->wq = alloc_ordered_workqueue("i915", 0);
if (dev_priv->wq == NULL)
goto out_err;
dev_priv->hotplug.dp_wq = alloc_ordered_workqueue("i915-dp", 0);
if (dev_priv->hotplug.dp_wq == NULL)
goto out_free_wq;
return 0;
out_free_wq:
destroy_workqueue(dev_priv->wq);
out_err:
DRM_ERROR("Failed to allocate workqueues.\n");
return -ENOMEM;
}
static void i915_workqueues_cleanup(struct drm_i915_private *dev_priv)
{
destroy_workqueue(dev_priv->hotplug.dp_wq);
destroy_workqueue(dev_priv->wq);
}
static int i915_driver_init_early(struct drm_i915_private *dev_priv,
const struct pci_device_id *ent)
{
const struct intel_device_info *match_info =
(struct intel_device_info *)ent->driver_data;
struct intel_device_info *device_info;
int ret = 0;
if (i915_inject_load_failure())
return -ENODEV;
device_info = mkwrite_device_info(dev_priv);
memcpy(device_info, match_info, sizeof(*device_info));
device_info->device_id = dev_priv->drm.pdev->device;
BUG_ON(device_info->gen > sizeof(device_info->gen_mask) * BITS_PER_BYTE);
device_info->gen_mask = BIT(device_info->gen - 1);
spin_lock_init(&dev_priv->irq_lock);
spin_lock_init(&dev_priv->gpu_error.lock);
mutex_init(&dev_priv->backlight_lock);
spin_lock_init(&dev_priv->uncore.lock);
spin_lock_init(&dev_priv->mm.object_stat_lock);
spin_lock_init(&dev_priv->mmio_flip_lock);
mutex_init(&dev_priv->sb_lock);
mutex_init(&dev_priv->modeset_restore_lock);
mutex_init(&dev_priv->av_mutex);
mutex_init(&dev_priv->wm.wm_mutex);
mutex_init(&dev_priv->pps_mutex);
i915_memcpy_init_early(dev_priv);
ret = i915_workqueues_init(dev_priv);
if (ret < 0)
return ret;
ret = intel_gvt_init(dev_priv);
if (ret < 0)
goto err_workqueues;
intel_detect_pch(&dev_priv->drm);
intel_pm_setup(&dev_priv->drm);
intel_init_dpio(dev_priv);
intel_power_domains_init(dev_priv);
intel_irq_init(dev_priv);
intel_init_display_hooks(dev_priv);
intel_init_clock_gating_hooks(dev_priv);
intel_init_audio_hooks(dev_priv);
i915_gem_load_init(&dev_priv->drm);
intel_display_crc_init(dev_priv);
intel_device_info_dump(dev_priv);
if (IS_HSW_EARLY_SDV(dev_priv))
DRM_INFO("This is an early pre-production Haswell machine. "
"It may not be fully functional.\n");
return 0;
err_workqueues:
i915_workqueues_cleanup(dev_priv);
return ret;
}
static void i915_driver_cleanup_early(struct drm_i915_private *dev_priv)
{
i915_gem_load_cleanup(&dev_priv->drm);
i915_workqueues_cleanup(dev_priv);
}
static int i915_mmio_setup(struct drm_device *dev)
{
struct drm_i915_private *dev_priv = to_i915(dev);
struct pci_dev *pdev = dev_priv->drm.pdev;
int mmio_bar;
int mmio_size;
mmio_bar = IS_GEN2(dev) ? 1 : 0;
if (INTEL_INFO(dev)->gen < 5)
mmio_size = 512 * 1024;
else
mmio_size = 2 * 1024 * 1024;
dev_priv->regs = pci_iomap(pdev, mmio_bar, mmio_size);
if (dev_priv->regs == NULL) {
DRM_ERROR("failed to map registers\n");
return -EIO;
}
intel_setup_mchbar(dev);
return 0;
}
static void i915_mmio_cleanup(struct drm_device *dev)
{
struct drm_i915_private *dev_priv = to_i915(dev);
struct pci_dev *pdev = dev_priv->drm.pdev;
intel_teardown_mchbar(dev);
pci_iounmap(pdev, dev_priv->regs);
}
static int i915_driver_init_mmio(struct drm_i915_private *dev_priv)
{
struct drm_device *dev = &dev_priv->drm;
int ret;
if (i915_inject_load_failure())
return -ENODEV;
if (i915_get_bridge_dev(dev))
return -EIO;
ret = i915_mmio_setup(dev);
if (ret < 0)
goto put_bridge;
intel_uncore_init(dev_priv);
return 0;
put_bridge:
pci_dev_put(dev_priv->bridge_dev);
return ret;
}
static void i915_driver_cleanup_mmio(struct drm_i915_private *dev_priv)
{
struct drm_device *dev = &dev_priv->drm;
intel_uncore_fini(dev_priv);
i915_mmio_cleanup(dev);
pci_dev_put(dev_priv->bridge_dev);
}
static void intel_sanitize_options(struct drm_i915_private *dev_priv)
{
i915.enable_execlists =
intel_sanitize_enable_execlists(dev_priv,
i915.enable_execlists);
i915.enable_ppgtt =
intel_sanitize_enable_ppgtt(dev_priv, i915.enable_ppgtt);
DRM_DEBUG_DRIVER("ppgtt mode: %i\n", i915.enable_ppgtt);
i915.semaphores = intel_sanitize_semaphores(dev_priv, i915.semaphores);
DRM_DEBUG_DRIVER("use GPU sempahores? %s\n", yesno(i915.semaphores));
}
static int i915_driver_init_hw(struct drm_i915_private *dev_priv)
{
struct pci_dev *pdev = dev_priv->drm.pdev;
struct drm_device *dev = &dev_priv->drm;
int ret;
if (i915_inject_load_failure())
return -ENODEV;
intel_device_info_runtime_init(dev_priv);
intel_sanitize_options(dev_priv);
ret = i915_ggtt_probe_hw(dev_priv);
if (ret)
return ret;
ret = i915_kick_out_firmware_fb(dev_priv);
if (ret) {
DRM_ERROR("failed to remove conflicting framebuffer drivers\n");
goto out_ggtt;
}
ret = i915_kick_out_vgacon(dev_priv);
if (ret) {
DRM_ERROR("failed to remove conflicting VGA console\n");
goto out_ggtt;
}
ret = i915_ggtt_init_hw(dev_priv);
if (ret)
return ret;
ret = i915_ggtt_enable_hw(dev_priv);
if (ret) {
DRM_ERROR("failed to enable GGTT\n");
goto out_ggtt;
}
pci_set_master(pdev);
if (IS_GEN2(dev)) {
ret = dma_set_coherent_mask(&pdev->dev, DMA_BIT_MASK(30));
if (ret) {
DRM_ERROR("failed to set DMA mask\n");
goto out_ggtt;
}
}
if (IS_BROADWATER(dev) || IS_CRESTLINE(dev)) {
ret = dma_set_coherent_mask(&pdev->dev, DMA_BIT_MASK(32));
if (ret) {
DRM_ERROR("failed to set DMA mask\n");
goto out_ggtt;
}
}
pm_qos_add_request(&dev_priv->pm_qos, PM_QOS_CPU_DMA_LATENCY,
PM_QOS_DEFAULT_VALUE);
intel_uncore_sanitize(dev_priv);
intel_opregion_setup(dev_priv);
i915_gem_load_init_fences(dev_priv);
if (!IS_I945G(dev) && !IS_I945GM(dev)) {
if (pci_enable_msi(pdev) < 0)
DRM_DEBUG_DRIVER("can't enable MSI");
}
return 0;
out_ggtt:
i915_ggtt_cleanup_hw(dev_priv);
return ret;
}
static void i915_driver_cleanup_hw(struct drm_i915_private *dev_priv)
{
struct pci_dev *pdev = dev_priv->drm.pdev;
if (pdev->msi_enabled)
pci_disable_msi(pdev);
pm_qos_remove_request(&dev_priv->pm_qos);
i915_ggtt_cleanup_hw(dev_priv);
}
static void i915_driver_register(struct drm_i915_private *dev_priv)
{
struct drm_device *dev = &dev_priv->drm;
i915_gem_shrinker_init(dev_priv);
if (intel_vgpu_active(dev_priv))
I915_WRITE(vgtif_reg(display_ready), VGT_DRV_DISPLAY_READY);
if (drm_dev_register(dev, 0) == 0) {
i915_debugfs_register(dev_priv);
i915_setup_sysfs(dev_priv);
} else
DRM_ERROR("Failed to register driver for userspace access!\n");
if (INTEL_INFO(dev_priv)->num_pipes) {
intel_opregion_register(dev_priv);
acpi_video_register();
}
if (IS_GEN5(dev_priv))
intel_gpu_ips_init(dev_priv);
i915_audio_component_init(dev_priv);
intel_fbdev_initial_config_async(dev);
}
static void i915_driver_unregister(struct drm_i915_private *dev_priv)
{
i915_audio_component_cleanup(dev_priv);
intel_gpu_ips_teardown();
acpi_video_unregister();
intel_opregion_unregister(dev_priv);
i915_teardown_sysfs(dev_priv);
i915_debugfs_unregister(dev_priv);
drm_dev_unregister(&dev_priv->drm);
i915_gem_shrinker_cleanup(dev_priv);
}
int i915_driver_load(struct pci_dev *pdev, const struct pci_device_id *ent)
{
struct drm_i915_private *dev_priv;
int ret;
if (i915.nuclear_pageflip)
driver.driver_features |= DRIVER_ATOMIC;
ret = -ENOMEM;
dev_priv = kzalloc(sizeof(*dev_priv), GFP_KERNEL);
if (dev_priv)
ret = drm_dev_init(&dev_priv->drm, &driver, &pdev->dev);
if (ret) {
dev_printk(KERN_ERR, &pdev->dev,
"[" DRM_NAME ":%s] allocation failed\n", __func__);
kfree(dev_priv);
return ret;
}
dev_priv->drm.pdev = pdev;
dev_priv->drm.dev_private = dev_priv;
ret = pci_enable_device(pdev);
if (ret)
goto out_free_priv;
pci_set_drvdata(pdev, &dev_priv->drm);
ret = i915_driver_init_early(dev_priv, ent);
if (ret < 0)
goto out_pci_disable;
intel_runtime_pm_get(dev_priv);
ret = i915_driver_init_mmio(dev_priv);
if (ret < 0)
goto out_runtime_pm_put;
ret = i915_driver_init_hw(dev_priv);
if (ret < 0)
goto out_cleanup_mmio;
if (INTEL_INFO(dev_priv)->num_pipes) {
ret = drm_vblank_init(&dev_priv->drm,
INTEL_INFO(dev_priv)->num_pipes);
if (ret)
goto out_cleanup_hw;
}
ret = i915_load_modeset_init(&dev_priv->drm);
if (ret < 0)
goto out_cleanup_vblank;
i915_driver_register(dev_priv);
intel_runtime_pm_enable(dev_priv);
DRM_INFO("Initialized %s %d.%d.%d %s for %s on minor %d\n",
driver.name, driver.major, driver.minor, driver.patchlevel,
driver.date, pci_name(pdev), dev_priv->drm.primary->index);
intel_runtime_pm_put(dev_priv);
return 0;
out_cleanup_vblank:
drm_vblank_cleanup(&dev_priv->drm);
out_cleanup_hw:
i915_driver_cleanup_hw(dev_priv);
out_cleanup_mmio:
i915_driver_cleanup_mmio(dev_priv);
out_runtime_pm_put:
intel_runtime_pm_put(dev_priv);
i915_driver_cleanup_early(dev_priv);
out_pci_disable:
pci_disable_device(pdev);
out_free_priv:
i915_load_error(dev_priv, "Device initialization failed (%d)\n", ret);
drm_dev_unref(&dev_priv->drm);
return ret;
}
void i915_driver_unload(struct drm_device *dev)
{
struct drm_i915_private *dev_priv = to_i915(dev);
struct pci_dev *pdev = dev_priv->drm.pdev;
intel_fbdev_fini(dev);
if (i915_gem_suspend(dev))
DRM_ERROR("failed to idle hardware; continuing to unload!\n");
intel_display_power_get(dev_priv, POWER_DOMAIN_INIT);
i915_driver_unregister(dev_priv);
drm_vblank_cleanup(dev);
intel_modeset_cleanup(dev);
if (dev_priv->vbt.child_dev && dev_priv->vbt.child_dev_num) {
kfree(dev_priv->vbt.child_dev);
dev_priv->vbt.child_dev = NULL;
dev_priv->vbt.child_dev_num = 0;
}
kfree(dev_priv->vbt.sdvo_lvds_vbt_mode);
dev_priv->vbt.sdvo_lvds_vbt_mode = NULL;
kfree(dev_priv->vbt.lfp_lvds_vbt_mode);
dev_priv->vbt.lfp_lvds_vbt_mode = NULL;
vga_switcheroo_unregister_client(pdev);
vga_client_register(pdev, NULL, NULL, NULL);
intel_csr_ucode_fini(dev_priv);
cancel_delayed_work_sync(&dev_priv->gpu_error.hangcheck_work);
i915_destroy_error_state(dev);
drain_workqueue(dev_priv->wq);
intel_guc_fini(dev);
i915_gem_fini(dev);
intel_fbc_cleanup_cfb(dev_priv);
intel_power_domains_fini(dev_priv);
i915_driver_cleanup_hw(dev_priv);
i915_driver_cleanup_mmio(dev_priv);
intel_display_power_put(dev_priv, POWER_DOMAIN_INIT);
i915_driver_cleanup_early(dev_priv);
}
static int i915_driver_open(struct drm_device *dev, struct drm_file *file)
{
int ret;
ret = i915_gem_open(dev, file);
if (ret)
return ret;
return 0;
}
static void i915_driver_lastclose(struct drm_device *dev)
{
intel_fbdev_restore_mode(dev);
vga_switcheroo_process_delayed_switch();
}
static void i915_driver_preclose(struct drm_device *dev, struct drm_file *file)
{
mutex_lock(&dev->struct_mutex);
i915_gem_context_close(dev, file);
i915_gem_release(dev, file);
mutex_unlock(&dev->struct_mutex);
}
static void i915_driver_postclose(struct drm_device *dev, struct drm_file *file)
{
struct drm_i915_file_private *file_priv = file->driver_priv;
kfree(file_priv);
}
static void intel_suspend_encoders(struct drm_i915_private *dev_priv)
{
struct drm_device *dev = &dev_priv->drm;
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
struct drm_i915_private *dev_priv = to_i915(dev);
struct pci_dev *pdev = dev_priv->drm.pdev;
pci_power_t opregion_target_state;
int error;
mutex_lock(&dev_priv->modeset_restore_lock);
dev_priv->modeset_restore = MODESET_SUSPENDED;
mutex_unlock(&dev_priv->modeset_restore_lock);
disable_rpm_wakeref_asserts(dev_priv);
intel_display_set_init_power(dev_priv, true);
drm_kms_helper_poll_disable(dev);
pci_save_state(pdev);
error = i915_gem_suspend(dev);
if (error) {
dev_err(&pdev->dev,
"GEM idle failed, resume might fail\n");
goto out;
}
intel_guc_suspend(dev);
intel_display_suspend(dev);
intel_dp_mst_suspend(dev);
intel_runtime_pm_disable_interrupts(dev_priv);
intel_hpd_cancel_work(dev_priv);
intel_suspend_encoders(dev_priv);
intel_suspend_hw(dev);
i915_gem_suspend_gtt_mappings(dev);
i915_save_state(dev);
opregion_target_state = suspend_to_idle(dev_priv) ? PCI_D1 : PCI_D3cold;
intel_opregion_notify_adapter(dev_priv, opregion_target_state);
intel_uncore_forcewake_reset(dev_priv, false);
intel_opregion_unregister(dev_priv);
intel_fbdev_set_suspend(dev, FBINFO_STATE_SUSPENDED, true);
dev_priv->suspend_count++;
intel_csr_ucode_suspend(dev_priv);
out:
enable_rpm_wakeref_asserts(dev_priv);
return error;
}
static int i915_drm_suspend_late(struct drm_device *dev, bool hibernation)
{
struct drm_i915_private *dev_priv = to_i915(dev);
struct pci_dev *pdev = dev_priv->drm.pdev;
bool fw_csr;
int ret;
disable_rpm_wakeref_asserts(dev_priv);
intel_display_set_init_power(dev_priv, false);
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
pci_disable_device(pdev);
if (!(hibernation && INTEL_INFO(dev_priv)->gen < 6))
pci_set_power_state(pdev, PCI_D3hot);
dev_priv->suspended_to_idle = suspend_to_idle(dev_priv);
out:
enable_rpm_wakeref_asserts(dev_priv);
return ret;
}
int i915_suspend_switcheroo(struct drm_device *dev, pm_message_t state)
{
int error;
if (!dev) {
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
struct drm_i915_private *dev_priv = to_i915(dev);
int ret;
disable_rpm_wakeref_asserts(dev_priv);
intel_sanitize_gt_powersave(dev_priv);
ret = i915_ggtt_enable_hw(dev_priv);
if (ret)
DRM_ERROR("failed to re-enable GGTT\n");
intel_csr_ucode_resume(dev_priv);
i915_gem_resume(dev);
i915_restore_state(dev);
intel_pps_unlock_regs_wa(dev_priv);
intel_opregion_setup(dev_priv);
intel_init_pch_refclk(dev);
drm_mode_config_reset(dev);
intel_runtime_pm_enable_interrupts(dev_priv);
mutex_lock(&dev->struct_mutex);
if (i915_gem_init_hw(dev)) {
DRM_ERROR("failed to re-initialize GPU, declaring wedged!\n");
i915_gem_set_wedged(dev_priv);
}
mutex_unlock(&dev->struct_mutex);
intel_guc_resume(dev);
intel_modeset_init_hw(dev);
spin_lock_irq(&dev_priv->irq_lock);
if (dev_priv->display.hpd_irq_setup)
dev_priv->display.hpd_irq_setup(dev_priv);
spin_unlock_irq(&dev_priv->irq_lock);
intel_dp_mst_resume(dev);
intel_display_resume(dev);
intel_hpd_init(dev_priv);
drm_helper_hpd_irq_event(dev);
intel_opregion_register(dev_priv);
intel_fbdev_set_suspend(dev, FBINFO_STATE_RUNNING, false);
mutex_lock(&dev_priv->modeset_restore_lock);
dev_priv->modeset_restore = MODESET_DONE;
mutex_unlock(&dev_priv->modeset_restore_lock);
intel_opregion_notify_adapter(dev_priv, PCI_D0);
intel_autoenable_gt_powersave(dev_priv);
drm_kms_helper_poll_enable(dev);
enable_rpm_wakeref_asserts(dev_priv);
return 0;
}
static int i915_drm_resume_early(struct drm_device *dev)
{
struct drm_i915_private *dev_priv = to_i915(dev);
struct pci_dev *pdev = dev_priv->drm.pdev;
int ret;
ret = pci_set_power_state(pdev, PCI_D0);
if (ret) {
DRM_ERROR("failed to set PCI D0 power state (%d)\n", ret);
goto out;
}
if (pci_enable_device(pdev)) {
ret = -EIO;
goto out;
}
pci_set_master(pdev);
disable_rpm_wakeref_asserts(dev_priv);
if (IS_VALLEYVIEW(dev_priv) || IS_CHERRYVIEW(dev_priv))
ret = vlv_resume_prepare(dev_priv, false);
if (ret)
DRM_ERROR("Resume prepare failed: %d, continuing anyway\n",
ret);
intel_uncore_early_sanitize(dev_priv, true);
if (IS_BROXTON(dev_priv)) {
if (!dev_priv->suspended_to_idle)
gen9_sanitize_dc_state(dev_priv);
bxt_disable_dc9(dev_priv);
} else if (IS_HASWELL(dev_priv) || IS_BROADWELL(dev_priv)) {
hsw_disable_pc8(dev_priv);
}
intel_uncore_sanitize(dev_priv);
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
void i915_reset(struct drm_i915_private *dev_priv)
{
struct drm_device *dev = &dev_priv->drm;
struct i915_gpu_error *error = &dev_priv->gpu_error;
int ret;
lockdep_assert_held(&dev->struct_mutex);
if (!test_and_clear_bit(I915_RESET_IN_PROGRESS, &error->flags))
return;
__clear_bit(I915_WEDGED, &error->flags);
error->reset_count++;
pr_notice("drm/i915: Resetting chip after gpu hang\n");
ret = intel_gpu_reset(dev_priv, ALL_ENGINES);
if (ret) {
if (ret != -ENODEV)
DRM_ERROR("Failed to reset chip: %i\n", ret);
else
DRM_DEBUG_DRIVER("GPU reset disabled\n");
goto error;
}
i915_gem_reset(dev_priv);
intel_overlay_reset(dev_priv);
ret = i915_gem_init_hw(dev);
if (ret) {
DRM_ERROR("Failed hw init on reset %d\n", ret);
goto error;
}
wakeup:
wake_up_bit(&error->flags, I915_RESET_IN_PROGRESS);
return;
error:
i915_gem_set_wedged(dev_priv);
goto wakeup;
}
static int i915_pm_suspend(struct device *kdev)
{
struct pci_dev *pdev = to_pci_dev(kdev);
struct drm_device *dev = pci_get_drvdata(pdev);
if (!dev) {
dev_err(kdev, "DRM not initialized, aborting suspend.\n");
return -ENODEV;
}
if (dev->switch_power_state == DRM_SWITCH_POWER_OFF)
return 0;
return i915_drm_suspend(dev);
}
static int i915_pm_suspend_late(struct device *kdev)
{
struct drm_device *dev = &kdev_to_i915(kdev)->drm;
if (dev->switch_power_state == DRM_SWITCH_POWER_OFF)
return 0;
return i915_drm_suspend_late(dev, false);
}
static int i915_pm_poweroff_late(struct device *kdev)
{
struct drm_device *dev = &kdev_to_i915(kdev)->drm;
if (dev->switch_power_state == DRM_SWITCH_POWER_OFF)
return 0;
return i915_drm_suspend_late(dev, true);
}
static int i915_pm_resume_early(struct device *kdev)
{
struct drm_device *dev = &kdev_to_i915(kdev)->drm;
if (dev->switch_power_state == DRM_SWITCH_POWER_OFF)
return 0;
return i915_drm_resume_early(dev);
}
static int i915_pm_resume(struct device *kdev)
{
struct drm_device *dev = &kdev_to_i915(kdev)->drm;
if (dev->switch_power_state == DRM_SWITCH_POWER_OFF)
return 0;
return i915_drm_resume(dev);
}
static int i915_pm_freeze(struct device *kdev)
{
int ret;
ret = i915_pm_suspend(kdev);
if (ret)
return ret;
ret = i915_gem_freeze(kdev_to_i915(kdev));
if (ret)
return ret;
return 0;
}
static int i915_pm_freeze_late(struct device *kdev)
{
int ret;
ret = i915_pm_suspend_late(kdev);
if (ret)
return ret;
ret = i915_gem_freeze_late(kdev_to_i915(kdev));
if (ret)
return ret;
return 0;
}
static int i915_pm_thaw_early(struct device *kdev)
{
return i915_pm_resume_early(kdev);
}
static int i915_pm_thaw(struct device *kdev)
{
return i915_pm_resume(kdev);
}
static int i915_pm_restore_early(struct device *kdev)
{
return i915_pm_resume_early(kdev);
}
static int i915_pm_restore(struct device *kdev)
{
return i915_pm_resume(kdev);
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
val = I915_READ(VLV_GTLC_SURVIVABILITY_REG);
val &= ~VLV_GFX_CLK_FORCE_ON_BIT;
if (force_on)
val |= VLV_GFX_CLK_FORCE_ON_BIT;
I915_WRITE(VLV_GTLC_SURVIVABILITY_REG, val);
if (!force_on)
return 0;
err = intel_wait_for_register(dev_priv,
VLV_GTLC_SURVIVABILITY_REG,
VLV_GFX_CLK_STATUS_BIT,
VLV_GFX_CLK_STATUS_BIT,
20);
if (err)
DRM_ERROR("timeout waiting for GFX clock force-on (%08x)\n",
I915_READ(VLV_GTLC_SURVIVABILITY_REG));
return err;
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
err = intel_wait_for_register(dev_priv,
VLV_GTLC_PW_STATUS,
VLV_GTLC_ALLOWWAKEACK,
allow,
1);
if (err)
DRM_ERROR("timeout disabling GT waking\n");
return err;
}
static int vlv_wait_for_gt_wells(struct drm_i915_private *dev_priv,
bool wait_for_on)
{
u32 mask;
u32 val;
int err;
mask = VLV_GTLC_PW_MEDIA_STATUS_MASK | VLV_GTLC_PW_RENDER_STATUS_MASK;
val = wait_for_on ? mask : 0;
if ((I915_READ(VLV_GTLC_PW_STATUS) & mask) == val)
return 0;
DRM_DEBUG_KMS("waiting for GT wells to go %s (%08x)\n",
onoff(wait_for_on),
I915_READ(VLV_GTLC_PW_STATUS));
err = intel_wait_for_register(dev_priv,
VLV_GTLC_PW_STATUS, mask, val,
3);
if (err)
DRM_ERROR("timeout waiting for GT wells to go %s\n",
onoff(wait_for_on));
return err;
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
struct drm_device *dev = &dev_priv->drm;
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
static int intel_runtime_suspend(struct device *kdev)
{
struct pci_dev *pdev = to_pci_dev(kdev);
struct drm_device *dev = pci_get_drvdata(pdev);
struct drm_i915_private *dev_priv = to_i915(dev);
int ret;
if (WARN_ON_ONCE(!(dev_priv->rps.enabled && intel_enable_rc6())))
return -ENODEV;
if (WARN_ON_ONCE(!HAS_RUNTIME_PM(dev)))
return -ENODEV;
DRM_DEBUG_KMS("Suspending device\n");
if (!mutex_trylock(&dev->struct_mutex)) {
DRM_DEBUG_KMS("device lock contention, deffering suspend\n");
pm_runtime_mark_last_busy(kdev);
return -EAGAIN;
}
disable_rpm_wakeref_asserts(dev_priv);
i915_gem_release_all_mmaps(dev_priv);
mutex_unlock(&dev->struct_mutex);
intel_guc_suspend(dev);
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
intel_uncore_forcewake_reset(dev_priv, false);
enable_rpm_wakeref_asserts(dev_priv);
WARN_ON_ONCE(atomic_read(&dev_priv->pm.wakeref_count));
if (intel_uncore_arm_unclaimed_mmio_detection(dev_priv))
DRM_ERROR("Unclaimed access detected prior to suspending\n");
dev_priv->pm.suspended = true;
if (IS_BROADWELL(dev_priv)) {
intel_opregion_notify_adapter(dev_priv, PCI_D3hot);
} else {
intel_opregion_notify_adapter(dev_priv, PCI_D1);
}
assert_forcewakes_inactive(dev_priv);
if (!IS_VALLEYVIEW(dev_priv) || !IS_CHERRYVIEW(dev_priv))
intel_hpd_poll_init(dev_priv);
DRM_DEBUG_KMS("Device suspended\n");
return 0;
}
static int intel_runtime_resume(struct device *kdev)
{
struct pci_dev *pdev = to_pci_dev(kdev);
struct drm_device *dev = pci_get_drvdata(pdev);
struct drm_i915_private *dev_priv = to_i915(dev);
int ret = 0;
if (WARN_ON_ONCE(!HAS_RUNTIME_PM(dev)))
return -ENODEV;
DRM_DEBUG_KMS("Resuming device\n");
WARN_ON_ONCE(atomic_read(&dev_priv->pm.wakeref_count));
disable_rpm_wakeref_asserts(dev_priv);
intel_opregion_notify_adapter(dev_priv, PCI_D0);
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
intel_runtime_pm_enable_interrupts(dev_priv);
if (!IS_VALLEYVIEW(dev_priv) && !IS_CHERRYVIEW(dev_priv))
intel_hpd_init(dev_priv);
enable_rpm_wakeref_asserts(dev_priv);
if (ret)
DRM_ERROR("Runtime resume failed, disabling it (%d)\n", ret);
else
DRM_DEBUG_KMS("Device resumed\n");
return ret;
}
static int
i915_gem_reject_pin_ioctl(struct drm_device *dev, void *data,
struct drm_file *file)
{
return -ENODEV;
}
