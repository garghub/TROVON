static int i915_getparam(struct drm_device *dev, void *data,
struct drm_file *file_priv)
{
struct drm_i915_private *dev_priv = dev->dev_private;
drm_i915_getparam_t *param = data;
int value;
switch (param->param) {
case I915_PARAM_IRQ_ACTIVE:
case I915_PARAM_ALLOW_BATCHBUFFER:
case I915_PARAM_LAST_DISPATCH:
return -ENODEV;
case I915_PARAM_CHIPSET_ID:
value = dev->pdev->device;
break;
case I915_PARAM_HAS_GEM:
value = 1;
break;
case I915_PARAM_NUM_FENCES_AVAIL:
value = dev_priv->num_fence_regs - dev_priv->fence_reg_start;
break;
case I915_PARAM_HAS_OVERLAY:
value = dev_priv->overlay ? 1 : 0;
break;
case I915_PARAM_HAS_PAGEFLIPPING:
value = 1;
break;
case I915_PARAM_HAS_EXECBUF2:
value = 1;
break;
case I915_PARAM_HAS_BSD:
value = intel_ring_initialized(&dev_priv->ring[VCS]);
break;
case I915_PARAM_HAS_BLT:
value = intel_ring_initialized(&dev_priv->ring[BCS]);
break;
case I915_PARAM_HAS_VEBOX:
value = intel_ring_initialized(&dev_priv->ring[VECS]);
break;
case I915_PARAM_HAS_BSD2:
value = intel_ring_initialized(&dev_priv->ring[VCS2]);
break;
case I915_PARAM_HAS_RELAXED_FENCING:
value = 1;
break;
case I915_PARAM_HAS_COHERENT_RINGS:
value = 1;
break;
case I915_PARAM_HAS_EXEC_CONSTANTS:
value = INTEL_INFO(dev)->gen >= 4;
break;
case I915_PARAM_HAS_RELAXED_DELTA:
value = 1;
break;
case I915_PARAM_HAS_GEN7_SOL_RESET:
value = 1;
break;
case I915_PARAM_HAS_LLC:
value = HAS_LLC(dev);
break;
case I915_PARAM_HAS_WT:
value = HAS_WT(dev);
break;
case I915_PARAM_HAS_ALIASING_PPGTT:
value = USES_PPGTT(dev);
break;
case I915_PARAM_HAS_WAIT_TIMEOUT:
value = 1;
break;
case I915_PARAM_HAS_SEMAPHORES:
value = i915_semaphore_is_enabled(dev);
break;
case I915_PARAM_HAS_PRIME_VMAP_FLUSH:
value = 1;
break;
case I915_PARAM_HAS_SECURE_BATCHES:
value = capable(CAP_SYS_ADMIN);
break;
case I915_PARAM_HAS_PINNED_BATCHES:
value = 1;
break;
case I915_PARAM_HAS_EXEC_NO_RELOC:
value = 1;
break;
case I915_PARAM_HAS_EXEC_HANDLE_LUT:
value = 1;
break;
case I915_PARAM_CMD_PARSER_VERSION:
value = i915_cmd_parser_get_version();
break;
case I915_PARAM_HAS_COHERENT_PHYS_GTT:
value = 1;
break;
case I915_PARAM_MMAP_VERSION:
value = 1;
break;
default:
DRM_DEBUG("Unknown parameter %d\n", param->param);
return -EINVAL;
}
if (copy_to_user(param->value, &value, sizeof(int))) {
DRM_ERROR("copy_to_user failed\n");
return -EFAULT;
}
return 0;
}
static int i915_setparam(struct drm_device *dev, void *data,
struct drm_file *file_priv)
{
struct drm_i915_private *dev_priv = dev->dev_private;
drm_i915_setparam_t *param = data;
switch (param->param) {
case I915_SETPARAM_USE_MI_BATCHBUFFER_START:
case I915_SETPARAM_TEX_LRU_LOG_GRANULARITY:
case I915_SETPARAM_ALLOW_BATCHBUFFER:
return -ENODEV;
case I915_SETPARAM_NUM_USED_FENCES:
if (param->value > dev_priv->num_fence_regs ||
param->value < 0)
return -EINVAL;
dev_priv->fence_reg_start = param->value;
break;
default:
DRM_DEBUG_DRIVER("unknown parameter %d\n",
param->param);
return -EINVAL;
}
return 0;
}
static int i915_get_bridge_dev(struct drm_device *dev)
{
struct drm_i915_private *dev_priv = dev->dev_private;
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
struct drm_i915_private *dev_priv = dev->dev_private;
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
struct drm_i915_private *dev_priv = dev->dev_private;
int mchbar_reg = INTEL_INFO(dev)->gen >= 4 ? MCHBAR_I965 : MCHBAR_I915;
u32 temp;
bool enabled;
if (IS_VALLEYVIEW(dev))
return;
dev_priv->mchbar_need_disable = false;
if (IS_I915G(dev) || IS_I915GM(dev)) {
pci_read_config_dword(dev_priv->bridge_dev, DEVEN_REG, &temp);
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
pci_write_config_dword(dev_priv->bridge_dev, DEVEN_REG,
temp | DEVEN_MCHBAR_EN);
} else {
pci_read_config_dword(dev_priv->bridge_dev, mchbar_reg, &temp);
pci_write_config_dword(dev_priv->bridge_dev, mchbar_reg, temp | 1);
}
}
static void
intel_teardown_mchbar(struct drm_device *dev)
{
struct drm_i915_private *dev_priv = dev->dev_private;
int mchbar_reg = INTEL_INFO(dev)->gen >= 4 ? MCHBAR_I965 : MCHBAR_I915;
u32 temp;
if (dev_priv->mchbar_need_disable) {
if (IS_I915G(dev) || IS_I915GM(dev)) {
pci_read_config_dword(dev_priv->bridge_dev, DEVEN_REG, &temp);
temp &= ~DEVEN_MCHBAR_EN;
pci_write_config_dword(dev_priv->bridge_dev, DEVEN_REG, temp);
} else {
pci_read_config_dword(dev_priv->bridge_dev, mchbar_reg, &temp);
temp &= ~1;
pci_write_config_dword(dev_priv->bridge_dev, mchbar_reg, temp);
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
pci_set_power_state(dev->pdev, PCI_D0);
i915_resume_legacy(dev);
dev->switch_power_state = DRM_SWITCH_POWER_ON;
} else {
pr_err("switched off\n");
dev->switch_power_state = DRM_SWITCH_POWER_CHANGING;
i915_suspend_legacy(dev, pmm);
dev->switch_power_state = DRM_SWITCH_POWER_OFF;
}
}
static bool i915_switcheroo_can_switch(struct pci_dev *pdev)
{
struct drm_device *dev = pci_get_drvdata(pdev);
return dev->open_count == 0;
}
static int i915_load_modeset_init(struct drm_device *dev)
{
struct drm_i915_private *dev_priv = dev->dev_private;
int ret;
ret = intel_parse_bios(dev);
if (ret)
DRM_INFO("failed to find VBIOS tables\n");
ret = vga_client_register(dev->pdev, dev, NULL, i915_vga_set_decode);
if (ret && ret != -ENODEV)
goto out;
intel_register_dsm_handler();
ret = vga_switcheroo_register_client(dev->pdev, &i915_switcheroo_ops, false);
if (ret)
goto cleanup_vga_client;
ret = i915_gem_init_stolen(dev);
if (ret)
goto cleanup_vga_switcheroo;
intel_power_domains_init_hw(dev_priv);
ret = intel_irq_install(dev_priv);
if (ret)
goto cleanup_gem_stolen;
intel_modeset_init(dev);
ret = i915_gem_init(dev);
if (ret)
goto cleanup_irq;
intel_modeset_gem_init(dev);
dev->vblank_disable_allowed = true;
if (INTEL_INFO(dev)->num_pipes == 0)
return 0;
ret = intel_fbdev_init(dev);
if (ret)
goto cleanup_gem;
intel_hpd_init(dev_priv);
async_schedule(intel_fbdev_initial_config, dev_priv);
drm_kms_helper_poll_init(dev);
return 0;
cleanup_gem:
mutex_lock(&dev->struct_mutex);
i915_gem_cleanup_ringbuffer(dev);
i915_gem_context_fini(dev);
mutex_unlock(&dev->struct_mutex);
cleanup_irq:
drm_irq_uninstall(dev);
cleanup_gem_stolen:
i915_gem_cleanup_stolen(dev);
cleanup_vga_switcheroo:
vga_switcheroo_unregister_client(dev->pdev);
cleanup_vga_client:
vga_client_register(dev->pdev, NULL, NULL, NULL);
out:
return ret;
}
static int i915_kick_out_firmware_fb(struct drm_i915_private *dev_priv)
{
struct apertures_struct *ap;
struct pci_dev *pdev = dev_priv->dev->pdev;
bool primary;
int ret;
ap = alloc_apertures(1);
if (!ap)
return -ENOMEM;
ap->ranges[0].base = dev_priv->gtt.mappable_base;
ap->ranges[0].size = dev_priv->gtt.mappable_end;
primary =
pdev->resource[PCI_ROM_RESOURCE].flags & IORESOURCE_ROM_SHADOW;
ret = remove_conflicting_framebuffers(ap, "inteldrmfb", primary);
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
static void i915_dump_device_info(struct drm_i915_private *dev_priv)
{
const struct intel_device_info *info = &dev_priv->info;
#define PRINT_S(name) "%s"
#define SEP_EMPTY
#define PRINT_FLAG(name) info->name ? #name "," : ""
#define SEP_COMMA ,
DRM_DEBUG_DRIVER("i915 device info: gen=%i, pciid=0x%04x rev=0x%02x flags="
DEV_INFO_FOR_EACH_FLAG(PRINT_S, SEP_EMPTY),
info->gen,
dev_priv->dev->pdev->device,
dev_priv->dev->pdev->revision,
DEV_INFO_FOR_EACH_FLAG(PRINT_FLAG, SEP_COMMA));
#undef PRINT_S
#undef SEP_EMPTY
#undef PRINT_FLAG
#undef SEP_COMMA
}
static void intel_device_info_runtime_init(struct drm_device *dev)
{
struct drm_i915_private *dev_priv = dev->dev_private;
struct intel_device_info *info;
enum pipe pipe;
info = (struct intel_device_info *)&dev_priv->info;
if (IS_VALLEYVIEW(dev) || INTEL_INFO(dev)->gen == 9)
for_each_pipe(dev_priv, pipe)
info->num_sprites[pipe] = 2;
else
for_each_pipe(dev_priv, pipe)
info->num_sprites[pipe] = 1;
if (i915.disable_display) {
DRM_INFO("Display disabled (module parameter)\n");
info->num_pipes = 0;
} else if (info->num_pipes > 0 &&
(INTEL_INFO(dev)->gen == 7 || INTEL_INFO(dev)->gen == 8) &&
!IS_VALLEYVIEW(dev)) {
u32 fuse_strap = I915_READ(FUSE_STRAP);
u32 sfuse_strap = I915_READ(SFUSE_STRAP);
if (fuse_strap & ILK_INTERNAL_DISPLAY_DISABLE ||
sfuse_strap & SFUSE_STRAP_DISPLAY_DISABLED ||
(dev_priv->pch_type == PCH_CPT &&
!(sfuse_strap & SFUSE_STRAP_FUSE_LOCK))) {
DRM_INFO("Display fused off, disabling\n");
info->num_pipes = 0;
}
}
if (IS_CHERRYVIEW(dev)) {
u32 fuse, mask_eu;
fuse = I915_READ(CHV_FUSE_GT);
mask_eu = fuse & (CHV_FGT_EU_DIS_SS0_R0_MASK |
CHV_FGT_EU_DIS_SS0_R1_MASK |
CHV_FGT_EU_DIS_SS1_R0_MASK |
CHV_FGT_EU_DIS_SS1_R1_MASK);
info->eu_total = 16 - hweight32(mask_eu);
}
}
int i915_driver_load(struct drm_device *dev, unsigned long flags)
{
struct drm_i915_private *dev_priv;
struct intel_device_info *info, *device_info;
int ret = 0, mmio_bar, mmio_size;
uint32_t aperture_size;
info = (struct intel_device_info *) flags;
if (info->gen >= 6 && !drm_core_check_feature(dev, DRIVER_MODESET)) {
DRM_INFO("Your hardware requires kernel modesetting (KMS)\n");
DRM_INFO("See CONFIG_DRM_I915_KMS, nomodeset, and i915.modeset parameters\n");
return -ENODEV;
}
if (!drm_core_check_feature(dev, DRIVER_MODESET) && !dev->agp)
return -EINVAL;
dev_priv = kzalloc(sizeof(*dev_priv), GFP_KERNEL);
if (dev_priv == NULL)
return -ENOMEM;
dev->dev_private = dev_priv;
dev_priv->dev = dev;
device_info = (struct intel_device_info *)&dev_priv->info;
memcpy(device_info, info, sizeof(dev_priv->info));
device_info->device_id = dev->pdev->device;
spin_lock_init(&dev_priv->irq_lock);
spin_lock_init(&dev_priv->gpu_error.lock);
mutex_init(&dev_priv->backlight_lock);
spin_lock_init(&dev_priv->uncore.lock);
spin_lock_init(&dev_priv->mm.object_stat_lock);
spin_lock_init(&dev_priv->mmio_flip_lock);
mutex_init(&dev_priv->dpio_lock);
mutex_init(&dev_priv->modeset_restore_lock);
intel_pm_setup(dev);
intel_display_crc_init(dev);
i915_dump_device_info(dev_priv);
if (IS_HSW_EARLY_SDV(dev))
DRM_INFO("This is an early pre-production Haswell machine. "
"It may not be fully functional.\n");
if (i915_get_bridge_dev(dev)) {
ret = -EIO;
goto free_priv;
}
mmio_bar = IS_GEN2(dev) ? 1 : 0;
if (info->gen < 5)
mmio_size = 512*1024;
else
mmio_size = 2*1024*1024;
dev_priv->regs = pci_iomap(dev->pdev, mmio_bar, mmio_size);
if (!dev_priv->regs) {
DRM_ERROR("failed to map registers\n");
ret = -EIO;
goto put_bridge;
}
intel_detect_pch(dev);
intel_uncore_init(dev);
ret = i915_gem_gtt_init(dev);
if (ret)
goto out_regs;
if (drm_core_check_feature(dev, DRIVER_MODESET)) {
ret = i915_kick_out_firmware_fb(dev_priv);
if (ret) {
DRM_ERROR("failed to remove conflicting framebuffer drivers\n");
goto out_gtt;
}
ret = i915_kick_out_vgacon(dev_priv);
if (ret) {
DRM_ERROR("failed to remove conflicting VGA console\n");
goto out_gtt;
}
}
pci_set_master(dev->pdev);
if (IS_GEN2(dev))
dma_set_coherent_mask(&dev->pdev->dev, DMA_BIT_MASK(30));
if (IS_BROADWATER(dev) || IS_CRESTLINE(dev))
dma_set_coherent_mask(&dev->pdev->dev, DMA_BIT_MASK(32));
aperture_size = dev_priv->gtt.mappable_end;
dev_priv->gtt.mappable =
io_mapping_create_wc(dev_priv->gtt.mappable_base,
aperture_size);
if (dev_priv->gtt.mappable == NULL) {
ret = -EIO;
goto out_gtt;
}
dev_priv->gtt.mtrr = arch_phys_wc_add(dev_priv->gtt.mappable_base,
aperture_size);
dev_priv->wq = alloc_ordered_workqueue("i915", 0);
if (dev_priv->wq == NULL) {
DRM_ERROR("Failed to create our workqueue.\n");
ret = -ENOMEM;
goto out_mtrrfree;
}
dev_priv->dp_wq = alloc_ordered_workqueue("i915-dp", 0);
if (dev_priv->dp_wq == NULL) {
DRM_ERROR("Failed to create our dp workqueue.\n");
ret = -ENOMEM;
goto out_freewq;
}
dev_priv->gpu_error.hangcheck_wq =
alloc_ordered_workqueue("i915-hangcheck", 0);
if (dev_priv->gpu_error.hangcheck_wq == NULL) {
DRM_ERROR("Failed to create our hangcheck workqueue.\n");
ret = -ENOMEM;
goto out_freedpwq;
}
intel_irq_init(dev_priv);
intel_uncore_sanitize(dev);
intel_setup_mchbar(dev);
intel_setup_gmbus(dev);
intel_opregion_setup(dev);
intel_setup_bios(dev);
i915_gem_load(dev);
if (!IS_I945G(dev) && !IS_I945GM(dev))
pci_enable_msi(dev->pdev);
intel_device_info_runtime_init(dev);
if (INTEL_INFO(dev)->num_pipes) {
ret = drm_vblank_init(dev, INTEL_INFO(dev)->num_pipes);
if (ret)
goto out_gem_unload;
}
intel_power_domains_init(dev_priv);
if (drm_core_check_feature(dev, DRIVER_MODESET)) {
ret = i915_load_modeset_init(dev);
if (ret < 0) {
DRM_ERROR("failed to init modeset\n");
goto out_power_well;
}
}
i915_setup_sysfs(dev);
if (INTEL_INFO(dev)->num_pipes) {
intel_opregion_init(dev);
acpi_video_register();
}
if (IS_GEN5(dev))
intel_gpu_ips_init(dev_priv);
intel_runtime_pm_enable(dev_priv);
i915_audio_component_init(dev_priv);
return 0;
out_power_well:
intel_power_domains_fini(dev_priv);
drm_vblank_cleanup(dev);
out_gem_unload:
WARN_ON(unregister_oom_notifier(&dev_priv->mm.oom_notifier));
unregister_shrinker(&dev_priv->mm.shrinker);
if (dev->pdev->msi_enabled)
pci_disable_msi(dev->pdev);
intel_teardown_gmbus(dev);
intel_teardown_mchbar(dev);
pm_qos_remove_request(&dev_priv->pm_qos);
destroy_workqueue(dev_priv->gpu_error.hangcheck_wq);
out_freedpwq:
destroy_workqueue(dev_priv->dp_wq);
out_freewq:
destroy_workqueue(dev_priv->wq);
out_mtrrfree:
arch_phys_wc_del(dev_priv->gtt.mtrr);
io_mapping_free(dev_priv->gtt.mappable);
out_gtt:
i915_global_gtt_cleanup(dev);
out_regs:
intel_uncore_fini(dev);
pci_iounmap(dev->pdev, dev_priv->regs);
put_bridge:
pci_dev_put(dev_priv->bridge_dev);
free_priv:
if (dev_priv->slab)
kmem_cache_destroy(dev_priv->slab);
kfree(dev_priv);
return ret;
}
int i915_driver_unload(struct drm_device *dev)
{
struct drm_i915_private *dev_priv = dev->dev_private;
int ret;
i915_audio_component_cleanup(dev_priv);
ret = i915_gem_suspend(dev);
if (ret) {
DRM_ERROR("failed to idle hardware: %d\n", ret);
return ret;
}
intel_power_domains_fini(dev_priv);
intel_gpu_ips_teardown();
i915_teardown_sysfs(dev);
WARN_ON(unregister_oom_notifier(&dev_priv->mm.oom_notifier));
unregister_shrinker(&dev_priv->mm.shrinker);
io_mapping_free(dev_priv->gtt.mappable);
arch_phys_wc_del(dev_priv->gtt.mtrr);
acpi_video_unregister();
if (drm_core_check_feature(dev, DRIVER_MODESET))
intel_fbdev_fini(dev);
drm_vblank_cleanup(dev);
if (drm_core_check_feature(dev, DRIVER_MODESET)) {
intel_modeset_cleanup(dev);
if (dev_priv->vbt.child_dev && dev_priv->vbt.child_dev_num) {
kfree(dev_priv->vbt.child_dev);
dev_priv->vbt.child_dev = NULL;
dev_priv->vbt.child_dev_num = 0;
}
vga_switcheroo_unregister_client(dev->pdev);
vga_client_register(dev->pdev, NULL, NULL, NULL);
}
cancel_delayed_work_sync(&dev_priv->gpu_error.hangcheck_work);
i915_destroy_error_state(dev);
if (dev->pdev->msi_enabled)
pci_disable_msi(dev->pdev);
intel_opregion_fini(dev);
if (drm_core_check_feature(dev, DRIVER_MODESET)) {
flush_workqueue(dev_priv->wq);
mutex_lock(&dev->struct_mutex);
i915_gem_cleanup_ringbuffer(dev);
i915_gem_batch_pool_fini(&dev_priv->mm.batch_pool);
i915_gem_context_fini(dev);
mutex_unlock(&dev->struct_mutex);
i915_gem_cleanup_stolen(dev);
}
intel_teardown_gmbus(dev);
intel_teardown_mchbar(dev);
destroy_workqueue(dev_priv->dp_wq);
destroy_workqueue(dev_priv->wq);
destroy_workqueue(dev_priv->gpu_error.hangcheck_wq);
pm_qos_remove_request(&dev_priv->pm_qos);
i915_global_gtt_cleanup(dev);
intel_uncore_fini(dev);
if (dev_priv->regs != NULL)
pci_iounmap(dev->pdev, dev_priv->regs);
if (dev_priv->slab)
kmem_cache_destroy(dev_priv->slab);
pci_dev_put(dev_priv->bridge_dev);
kfree(dev_priv);
return 0;
}
int i915_driver_open(struct drm_device *dev, struct drm_file *file)
{
int ret;
ret = i915_gem_open(dev, file);
if (ret)
return ret;
return 0;
}
void i915_driver_lastclose(struct drm_device *dev)
{
intel_fbdev_restore_mode(dev);
vga_switcheroo_process_delayed_switch();
}
void i915_driver_preclose(struct drm_device *dev, struct drm_file *file)
{
mutex_lock(&dev->struct_mutex);
i915_gem_context_close(dev, file);
i915_gem_release(dev, file);
mutex_unlock(&dev->struct_mutex);
if (drm_core_check_feature(dev, DRIVER_MODESET))
intel_modeset_preclose(dev, file);
}
void i915_driver_postclose(struct drm_device *dev, struct drm_file *file)
{
struct drm_i915_file_private *file_priv = file->driver_priv;
if (file_priv && file_priv->bsd_ring)
file_priv->bsd_ring = NULL;
kfree(file_priv);
}
static int
i915_gem_reject_pin_ioctl(struct drm_device *dev, void *data,
struct drm_file *file)
{
return -ENODEV;
}
int i915_driver_device_is_agp(struct drm_device *dev)
{
return 1;
}
