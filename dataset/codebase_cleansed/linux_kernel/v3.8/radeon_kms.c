int radeon_driver_unload_kms(struct drm_device *dev)
{
struct radeon_device *rdev = dev->dev_private;
if (rdev == NULL)
return 0;
radeon_acpi_fini(rdev);
radeon_modeset_fini(rdev);
radeon_device_fini(rdev);
kfree(rdev);
dev->dev_private = NULL;
return 0;
}
int radeon_driver_load_kms(struct drm_device *dev, unsigned long flags)
{
struct radeon_device *rdev;
int r, acpi_status;
rdev = kzalloc(sizeof(struct radeon_device), GFP_KERNEL);
if (rdev == NULL) {
return -ENOMEM;
}
dev->dev_private = (void *)rdev;
if (drm_pci_device_is_agp(dev)) {
flags |= RADEON_IS_AGP;
} else if (pci_is_pcie(dev->pdev)) {
flags |= RADEON_IS_PCIE;
} else {
flags |= RADEON_IS_PCI;
}
r = radeon_device_init(rdev, dev, dev->pdev, flags);
if (r) {
dev_err(&dev->pdev->dev, "Fatal error during GPU init\n");
goto out;
}
r = radeon_modeset_init(rdev);
if (r)
dev_err(&dev->pdev->dev, "Fatal error during modeset init\n");
if (!r) {
acpi_status = radeon_acpi_init(rdev);
if (acpi_status)
dev_dbg(&dev->pdev->dev,
"Error during ACPI methods call\n");
}
out:
if (r)
radeon_driver_unload_kms(dev);
return r;
}
static void radeon_set_filp_rights(struct drm_device *dev,
struct drm_file **owner,
struct drm_file *applier,
uint32_t *value)
{
mutex_lock(&dev->struct_mutex);
if (*value == 1) {
if (!*owner)
*owner = applier;
} else if (*value == 0) {
if (*owner == applier)
*owner = NULL;
}
*value = *owner == applier ? 1 : 0;
mutex_unlock(&dev->struct_mutex);
}
int radeon_info_ioctl(struct drm_device *dev, void *data, struct drm_file *filp)
{
struct radeon_device *rdev = dev->dev_private;
struct drm_radeon_info *info = data;
struct radeon_mode_info *minfo = &rdev->mode_info;
uint32_t value, *value_ptr;
uint64_t value64, *value_ptr64;
struct drm_crtc *crtc;
int i, found;
if (info->request == RADEON_INFO_TIMESTAMP) {
if (rdev->family >= CHIP_R600) {
value_ptr64 = (uint64_t*)((unsigned long)info->value);
if (rdev->family >= CHIP_TAHITI) {
value64 = si_get_gpu_clock(rdev);
} else {
value64 = r600_get_gpu_clock(rdev);
}
if (DRM_COPY_TO_USER(value_ptr64, &value64, sizeof(value64))) {
DRM_ERROR("copy_to_user %s:%u\n", __func__, __LINE__);
return -EFAULT;
}
return 0;
} else {
DRM_DEBUG_KMS("timestamp is r6xx+ only!\n");
return -EINVAL;
}
}
value_ptr = (uint32_t *)((unsigned long)info->value);
if (DRM_COPY_FROM_USER(&value, value_ptr, sizeof(value))) {
DRM_ERROR("copy_from_user %s:%u\n", __func__, __LINE__);
return -EFAULT;
}
switch (info->request) {
case RADEON_INFO_DEVICE_ID:
value = dev->pci_device;
break;
case RADEON_INFO_NUM_GB_PIPES:
value = rdev->num_gb_pipes;
break;
case RADEON_INFO_NUM_Z_PIPES:
value = rdev->num_z_pipes;
break;
case RADEON_INFO_ACCEL_WORKING:
if ((rdev->family >= CHIP_CEDAR) && (rdev->family <= CHIP_HEMLOCK))
value = false;
else
value = rdev->accel_working;
break;
case RADEON_INFO_CRTC_FROM_ID:
for (i = 0, found = 0; i < rdev->num_crtc; i++) {
crtc = (struct drm_crtc *)minfo->crtcs[i];
if (crtc && crtc->base.id == value) {
struct radeon_crtc *radeon_crtc = to_radeon_crtc(crtc);
value = radeon_crtc->crtc_id;
found = 1;
break;
}
}
if (!found) {
DRM_DEBUG_KMS("unknown crtc id %d\n", value);
return -EINVAL;
}
break;
case RADEON_INFO_ACCEL_WORKING2:
value = rdev->accel_working;
break;
case RADEON_INFO_TILING_CONFIG:
if (rdev->family >= CHIP_TAHITI)
value = rdev->config.si.tile_config;
else if (rdev->family >= CHIP_CAYMAN)
value = rdev->config.cayman.tile_config;
else if (rdev->family >= CHIP_CEDAR)
value = rdev->config.evergreen.tile_config;
else if (rdev->family >= CHIP_RV770)
value = rdev->config.rv770.tile_config;
else if (rdev->family >= CHIP_R600)
value = rdev->config.r600.tile_config;
else {
DRM_DEBUG_KMS("tiling config is r6xx+ only!\n");
return -EINVAL;
}
break;
case RADEON_INFO_WANT_HYPERZ:
if (value >= 2) {
DRM_DEBUG_KMS("WANT_HYPERZ: invalid value %d\n", value);
return -EINVAL;
}
radeon_set_filp_rights(dev, &rdev->hyperz_filp, filp, &value);
break;
case RADEON_INFO_WANT_CMASK:
if (value >= 2) {
DRM_DEBUG_KMS("WANT_CMASK: invalid value %d\n", value);
return -EINVAL;
}
radeon_set_filp_rights(dev, &rdev->cmask_filp, filp, &value);
break;
case RADEON_INFO_CLOCK_CRYSTAL_FREQ:
value = rdev->clock.spll.reference_freq * 10;
break;
case RADEON_INFO_NUM_BACKENDS:
if (rdev->family >= CHIP_TAHITI)
value = rdev->config.si.max_backends_per_se *
rdev->config.si.max_shader_engines;
else if (rdev->family >= CHIP_CAYMAN)
value = rdev->config.cayman.max_backends_per_se *
rdev->config.cayman.max_shader_engines;
else if (rdev->family >= CHIP_CEDAR)
value = rdev->config.evergreen.max_backends;
else if (rdev->family >= CHIP_RV770)
value = rdev->config.rv770.max_backends;
else if (rdev->family >= CHIP_R600)
value = rdev->config.r600.max_backends;
else {
return -EINVAL;
}
break;
case RADEON_INFO_NUM_TILE_PIPES:
if (rdev->family >= CHIP_TAHITI)
value = rdev->config.si.max_tile_pipes;
else if (rdev->family >= CHIP_CAYMAN)
value = rdev->config.cayman.max_tile_pipes;
else if (rdev->family >= CHIP_CEDAR)
value = rdev->config.evergreen.max_tile_pipes;
else if (rdev->family >= CHIP_RV770)
value = rdev->config.rv770.max_tile_pipes;
else if (rdev->family >= CHIP_R600)
value = rdev->config.r600.max_tile_pipes;
else {
return -EINVAL;
}
break;
case RADEON_INFO_FUSION_GART_WORKING:
value = 1;
break;
case RADEON_INFO_BACKEND_MAP:
if (rdev->family >= CHIP_TAHITI)
value = rdev->config.si.backend_map;
else if (rdev->family >= CHIP_CAYMAN)
value = rdev->config.cayman.backend_map;
else if (rdev->family >= CHIP_CEDAR)
value = rdev->config.evergreen.backend_map;
else if (rdev->family >= CHIP_RV770)
value = rdev->config.rv770.backend_map;
else if (rdev->family >= CHIP_R600)
value = rdev->config.r600.backend_map;
else {
return -EINVAL;
}
break;
case RADEON_INFO_VA_START:
if (rdev->family < CHIP_CAYMAN)
return -EINVAL;
value = RADEON_VA_RESERVED_SIZE;
break;
case RADEON_INFO_IB_VM_MAX_SIZE:
if (rdev->family < CHIP_CAYMAN)
return -EINVAL;
value = RADEON_IB_VM_MAX_SIZE;
break;
case RADEON_INFO_MAX_PIPES:
if (rdev->family >= CHIP_TAHITI)
value = rdev->config.si.max_cu_per_sh;
else if (rdev->family >= CHIP_CAYMAN)
value = rdev->config.cayman.max_pipes_per_simd;
else if (rdev->family >= CHIP_CEDAR)
value = rdev->config.evergreen.max_pipes;
else if (rdev->family >= CHIP_RV770)
value = rdev->config.rv770.max_pipes;
else if (rdev->family >= CHIP_R600)
value = rdev->config.r600.max_pipes;
else {
return -EINVAL;
}
break;
case RADEON_INFO_MAX_SE:
if (rdev->family >= CHIP_TAHITI)
value = rdev->config.si.max_shader_engines;
else if (rdev->family >= CHIP_CAYMAN)
value = rdev->config.cayman.max_shader_engines;
else if (rdev->family >= CHIP_CEDAR)
value = rdev->config.evergreen.num_ses;
else
value = 1;
break;
case RADEON_INFO_MAX_SH_PER_SE:
if (rdev->family >= CHIP_TAHITI)
value = rdev->config.si.max_sh_per_se;
else
return -EINVAL;
break;
default:
DRM_DEBUG_KMS("Invalid request %d\n", info->request);
return -EINVAL;
}
if (DRM_COPY_TO_USER(value_ptr, &value, sizeof(uint32_t))) {
DRM_ERROR("copy_to_user %s:%u\n", __func__, __LINE__);
return -EFAULT;
}
return 0;
}
int radeon_driver_firstopen_kms(struct drm_device *dev)
{
return 0;
}
void radeon_driver_lastclose_kms(struct drm_device *dev)
{
vga_switcheroo_process_delayed_switch();
}
int radeon_driver_open_kms(struct drm_device *dev, struct drm_file *file_priv)
{
struct radeon_device *rdev = dev->dev_private;
file_priv->driver_priv = NULL;
if (rdev->family >= CHIP_CAYMAN) {
struct radeon_fpriv *fpriv;
struct radeon_bo_va *bo_va;
int r;
fpriv = kzalloc(sizeof(*fpriv), GFP_KERNEL);
if (unlikely(!fpriv)) {
return -ENOMEM;
}
radeon_vm_init(rdev, &fpriv->vm);
bo_va = radeon_vm_bo_add(rdev, &fpriv->vm,
rdev->ring_tmp_bo.bo);
r = radeon_vm_bo_set_addr(rdev, bo_va, RADEON_VA_IB_OFFSET,
RADEON_VM_PAGE_READABLE |
RADEON_VM_PAGE_SNOOPED);
if (r) {
radeon_vm_fini(rdev, &fpriv->vm);
kfree(fpriv);
return r;
}
file_priv->driver_priv = fpriv;
}
return 0;
}
void radeon_driver_postclose_kms(struct drm_device *dev,
struct drm_file *file_priv)
{
struct radeon_device *rdev = dev->dev_private;
if (rdev->family >= CHIP_CAYMAN && file_priv->driver_priv) {
struct radeon_fpriv *fpriv = file_priv->driver_priv;
struct radeon_bo_va *bo_va;
int r;
r = radeon_bo_reserve(rdev->ring_tmp_bo.bo, false);
if (!r) {
bo_va = radeon_vm_bo_find(&fpriv->vm,
rdev->ring_tmp_bo.bo);
if (bo_va)
radeon_vm_bo_rmv(rdev, bo_va);
radeon_bo_unreserve(rdev->ring_tmp_bo.bo);
}
radeon_vm_fini(rdev, &fpriv->vm);
kfree(fpriv);
file_priv->driver_priv = NULL;
}
}
void radeon_driver_preclose_kms(struct drm_device *dev,
struct drm_file *file_priv)
{
struct radeon_device *rdev = dev->dev_private;
if (rdev->hyperz_filp == file_priv)
rdev->hyperz_filp = NULL;
if (rdev->cmask_filp == file_priv)
rdev->cmask_filp = NULL;
}
u32 radeon_get_vblank_counter_kms(struct drm_device *dev, int crtc)
{
struct radeon_device *rdev = dev->dev_private;
if (crtc < 0 || crtc >= rdev->num_crtc) {
DRM_ERROR("Invalid crtc %d\n", crtc);
return -EINVAL;
}
return radeon_get_vblank_counter(rdev, crtc);
}
int radeon_enable_vblank_kms(struct drm_device *dev, int crtc)
{
struct radeon_device *rdev = dev->dev_private;
unsigned long irqflags;
int r;
if (crtc < 0 || crtc >= rdev->num_crtc) {
DRM_ERROR("Invalid crtc %d\n", crtc);
return -EINVAL;
}
spin_lock_irqsave(&rdev->irq.lock, irqflags);
rdev->irq.crtc_vblank_int[crtc] = true;
r = radeon_irq_set(rdev);
spin_unlock_irqrestore(&rdev->irq.lock, irqflags);
return r;
}
void radeon_disable_vblank_kms(struct drm_device *dev, int crtc)
{
struct radeon_device *rdev = dev->dev_private;
unsigned long irqflags;
if (crtc < 0 || crtc >= rdev->num_crtc) {
DRM_ERROR("Invalid crtc %d\n", crtc);
return;
}
spin_lock_irqsave(&rdev->irq.lock, irqflags);
rdev->irq.crtc_vblank_int[crtc] = false;
radeon_irq_set(rdev);
spin_unlock_irqrestore(&rdev->irq.lock, irqflags);
}
int radeon_get_vblank_timestamp_kms(struct drm_device *dev, int crtc,
int *max_error,
struct timeval *vblank_time,
unsigned flags)
{
struct drm_crtc *drmcrtc;
struct radeon_device *rdev = dev->dev_private;
if (crtc < 0 || crtc >= dev->num_crtcs) {
DRM_ERROR("Invalid crtc %d\n", crtc);
return -EINVAL;
}
drmcrtc = &rdev->mode_info.crtcs[crtc]->base;
return drm_calc_vbltimestamp_from_scanoutpos(dev, crtc, max_error,
vblank_time, flags,
drmcrtc);
}
int radeon_dma_ioctl_kms(struct drm_device *dev, void *data,
struct drm_file *file_priv)
{
return -EINVAL;
}
