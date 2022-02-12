static inline bool amdgpu_has_atpx(void) { return false; }
int amdgpu_driver_unload_kms(struct drm_device *dev)
{
struct amdgpu_device *adev = dev->dev_private;
if (adev == NULL)
return 0;
if (adev->rmmio == NULL)
goto done_free;
pm_runtime_get_sync(dev->dev);
amdgpu_amdkfd_device_fini(adev);
amdgpu_acpi_fini(adev);
amdgpu_device_fini(adev);
done_free:
kfree(adev);
dev->dev_private = NULL;
return 0;
}
int amdgpu_driver_load_kms(struct drm_device *dev, unsigned long flags)
{
struct amdgpu_device *adev;
int r, acpi_status;
adev = kzalloc(sizeof(struct amdgpu_device), GFP_KERNEL);
if (adev == NULL) {
return -ENOMEM;
}
dev->dev_private = (void *)adev;
if ((amdgpu_runtime_pm != 0) &&
amdgpu_has_atpx() &&
((flags & AMD_IS_APU) == 0))
flags |= AMD_IS_PX;
r = amdgpu_device_init(adev, dev, dev->pdev, flags);
if (r) {
dev_err(&dev->pdev->dev, "Fatal error during GPU init\n");
goto out;
}
if (!r) {
acpi_status = amdgpu_acpi_init(adev);
if (acpi_status)
dev_dbg(&dev->pdev->dev,
"Error during ACPI methods call\n");
}
amdgpu_amdkfd_load_interface(adev);
amdgpu_amdkfd_device_probe(adev);
amdgpu_amdkfd_device_init(adev);
if (amdgpu_device_is_px(dev)) {
pm_runtime_use_autosuspend(dev->dev);
pm_runtime_set_autosuspend_delay(dev->dev, 5000);
pm_runtime_set_active(dev->dev);
pm_runtime_allow(dev->dev);
pm_runtime_mark_last_busy(dev->dev);
pm_runtime_put_autosuspend(dev->dev);
}
out:
if (r)
amdgpu_driver_unload_kms(dev);
return r;
}
static int amdgpu_info_ioctl(struct drm_device *dev, void *data, struct drm_file *filp)
{
struct amdgpu_device *adev = dev->dev_private;
struct drm_amdgpu_info *info = data;
struct amdgpu_mode_info *minfo = &adev->mode_info;
void __user *out = (void __user *)(long)info->return_pointer;
uint32_t size = info->return_size;
struct drm_crtc *crtc;
uint32_t ui32 = 0;
uint64_t ui64 = 0;
int i, found;
if (!info->return_size || !info->return_pointer)
return -EINVAL;
switch (info->query) {
case AMDGPU_INFO_ACCEL_WORKING:
ui32 = adev->accel_working;
return copy_to_user(out, &ui32, min(size, 4u)) ? -EFAULT : 0;
case AMDGPU_INFO_CRTC_FROM_ID:
for (i = 0, found = 0; i < adev->mode_info.num_crtc; i++) {
crtc = (struct drm_crtc *)minfo->crtcs[i];
if (crtc && crtc->base.id == info->mode_crtc.id) {
struct amdgpu_crtc *amdgpu_crtc = to_amdgpu_crtc(crtc);
ui32 = amdgpu_crtc->crtc_id;
found = 1;
break;
}
}
if (!found) {
DRM_DEBUG_KMS("unknown crtc id %d\n", info->mode_crtc.id);
return -EINVAL;
}
return copy_to_user(out, &ui32, min(size, 4u)) ? -EFAULT : 0;
case AMDGPU_INFO_HW_IP_INFO: {
struct drm_amdgpu_info_hw_ip ip = {};
enum amd_ip_block_type type;
uint32_t ring_mask = 0;
uint32_t ib_start_alignment = 0;
uint32_t ib_size_alignment = 0;
if (info->query_hw_ip.ip_instance >= AMDGPU_HW_IP_INSTANCE_MAX_COUNT)
return -EINVAL;
switch (info->query_hw_ip.type) {
case AMDGPU_HW_IP_GFX:
type = AMD_IP_BLOCK_TYPE_GFX;
for (i = 0; i < adev->gfx.num_gfx_rings; i++)
ring_mask |= ((adev->gfx.gfx_ring[i].ready ? 1 : 0) << i);
ib_start_alignment = AMDGPU_GPU_PAGE_SIZE;
ib_size_alignment = 8;
break;
case AMDGPU_HW_IP_COMPUTE:
type = AMD_IP_BLOCK_TYPE_GFX;
for (i = 0; i < adev->gfx.num_compute_rings; i++)
ring_mask |= ((adev->gfx.compute_ring[i].ready ? 1 : 0) << i);
ib_start_alignment = AMDGPU_GPU_PAGE_SIZE;
ib_size_alignment = 8;
break;
case AMDGPU_HW_IP_DMA:
type = AMD_IP_BLOCK_TYPE_SDMA;
for (i = 0; i < adev->sdma.num_instances; i++)
ring_mask |= ((adev->sdma.instance[i].ring.ready ? 1 : 0) << i);
ib_start_alignment = AMDGPU_GPU_PAGE_SIZE;
ib_size_alignment = 1;
break;
case AMDGPU_HW_IP_UVD:
type = AMD_IP_BLOCK_TYPE_UVD;
ring_mask = adev->uvd.ring.ready ? 1 : 0;
ib_start_alignment = AMDGPU_GPU_PAGE_SIZE;
ib_size_alignment = 8;
break;
case AMDGPU_HW_IP_VCE:
type = AMD_IP_BLOCK_TYPE_VCE;
for (i = 0; i < AMDGPU_MAX_VCE_RINGS; i++)
ring_mask |= ((adev->vce.ring[i].ready ? 1 : 0) << i);
ib_start_alignment = AMDGPU_GPU_PAGE_SIZE;
ib_size_alignment = 8;
break;
default:
return -EINVAL;
}
for (i = 0; i < adev->num_ip_blocks; i++) {
if (adev->ip_blocks[i].type == type &&
adev->ip_block_status[i].valid) {
ip.hw_ip_version_major = adev->ip_blocks[i].major;
ip.hw_ip_version_minor = adev->ip_blocks[i].minor;
ip.capabilities_flags = 0;
ip.available_rings = ring_mask;
ip.ib_start_alignment = ib_start_alignment;
ip.ib_size_alignment = ib_size_alignment;
break;
}
}
return copy_to_user(out, &ip,
min((size_t)size, sizeof(ip))) ? -EFAULT : 0;
}
case AMDGPU_INFO_HW_IP_COUNT: {
enum amd_ip_block_type type;
uint32_t count = 0;
switch (info->query_hw_ip.type) {
case AMDGPU_HW_IP_GFX:
type = AMD_IP_BLOCK_TYPE_GFX;
break;
case AMDGPU_HW_IP_COMPUTE:
type = AMD_IP_BLOCK_TYPE_GFX;
break;
case AMDGPU_HW_IP_DMA:
type = AMD_IP_BLOCK_TYPE_SDMA;
break;
case AMDGPU_HW_IP_UVD:
type = AMD_IP_BLOCK_TYPE_UVD;
break;
case AMDGPU_HW_IP_VCE:
type = AMD_IP_BLOCK_TYPE_VCE;
break;
default:
return -EINVAL;
}
for (i = 0; i < adev->num_ip_blocks; i++)
if (adev->ip_blocks[i].type == type &&
adev->ip_block_status[i].valid &&
count < AMDGPU_HW_IP_INSTANCE_MAX_COUNT)
count++;
return copy_to_user(out, &count, min(size, 4u)) ? -EFAULT : 0;
}
case AMDGPU_INFO_TIMESTAMP:
ui64 = amdgpu_asic_get_gpu_clock_counter(adev);
return copy_to_user(out, &ui64, min(size, 8u)) ? -EFAULT : 0;
case AMDGPU_INFO_FW_VERSION: {
struct drm_amdgpu_info_firmware fw_info;
if (info->query_fw.ip_instance != 0)
return -EINVAL;
switch (info->query_fw.fw_type) {
case AMDGPU_INFO_FW_VCE:
fw_info.ver = adev->vce.fw_version;
fw_info.feature = adev->vce.fb_version;
break;
case AMDGPU_INFO_FW_UVD:
fw_info.ver = 0;
fw_info.feature = 0;
break;
case AMDGPU_INFO_FW_GMC:
fw_info.ver = adev->mc.fw_version;
fw_info.feature = 0;
break;
case AMDGPU_INFO_FW_GFX_ME:
fw_info.ver = adev->gfx.me_fw_version;
fw_info.feature = adev->gfx.me_feature_version;
break;
case AMDGPU_INFO_FW_GFX_PFP:
fw_info.ver = adev->gfx.pfp_fw_version;
fw_info.feature = adev->gfx.pfp_feature_version;
break;
case AMDGPU_INFO_FW_GFX_CE:
fw_info.ver = adev->gfx.ce_fw_version;
fw_info.feature = adev->gfx.ce_feature_version;
break;
case AMDGPU_INFO_FW_GFX_RLC:
fw_info.ver = adev->gfx.rlc_fw_version;
fw_info.feature = adev->gfx.rlc_feature_version;
break;
case AMDGPU_INFO_FW_GFX_MEC:
if (info->query_fw.index == 0) {
fw_info.ver = adev->gfx.mec_fw_version;
fw_info.feature = adev->gfx.mec_feature_version;
} else if (info->query_fw.index == 1) {
fw_info.ver = adev->gfx.mec2_fw_version;
fw_info.feature = adev->gfx.mec2_feature_version;
} else
return -EINVAL;
break;
case AMDGPU_INFO_FW_SMC:
fw_info.ver = adev->pm.fw_version;
fw_info.feature = 0;
break;
case AMDGPU_INFO_FW_SDMA:
if (info->query_fw.index >= adev->sdma.num_instances)
return -EINVAL;
fw_info.ver = adev->sdma.instance[info->query_fw.index].fw_version;
fw_info.feature = adev->sdma.instance[info->query_fw.index].feature_version;
break;
default:
return -EINVAL;
}
return copy_to_user(out, &fw_info,
min((size_t)size, sizeof(fw_info))) ? -EFAULT : 0;
}
case AMDGPU_INFO_NUM_BYTES_MOVED:
ui64 = atomic64_read(&adev->num_bytes_moved);
return copy_to_user(out, &ui64, min(size, 8u)) ? -EFAULT : 0;
case AMDGPU_INFO_VRAM_USAGE:
ui64 = atomic64_read(&adev->vram_usage);
return copy_to_user(out, &ui64, min(size, 8u)) ? -EFAULT : 0;
case AMDGPU_INFO_VIS_VRAM_USAGE:
ui64 = atomic64_read(&adev->vram_vis_usage);
return copy_to_user(out, &ui64, min(size, 8u)) ? -EFAULT : 0;
case AMDGPU_INFO_GTT_USAGE:
ui64 = atomic64_read(&adev->gtt_usage);
return copy_to_user(out, &ui64, min(size, 8u)) ? -EFAULT : 0;
case AMDGPU_INFO_GDS_CONFIG: {
struct drm_amdgpu_info_gds gds_info;
memset(&gds_info, 0, sizeof(gds_info));
gds_info.gds_gfx_partition_size = adev->gds.mem.gfx_partition_size >> AMDGPU_GDS_SHIFT;
gds_info.compute_partition_size = adev->gds.mem.cs_partition_size >> AMDGPU_GDS_SHIFT;
gds_info.gds_total_size = adev->gds.mem.total_size >> AMDGPU_GDS_SHIFT;
gds_info.gws_per_gfx_partition = adev->gds.gws.gfx_partition_size >> AMDGPU_GWS_SHIFT;
gds_info.gws_per_compute_partition = adev->gds.gws.cs_partition_size >> AMDGPU_GWS_SHIFT;
gds_info.oa_per_gfx_partition = adev->gds.oa.gfx_partition_size >> AMDGPU_OA_SHIFT;
gds_info.oa_per_compute_partition = adev->gds.oa.cs_partition_size >> AMDGPU_OA_SHIFT;
return copy_to_user(out, &gds_info,
min((size_t)size, sizeof(gds_info))) ? -EFAULT : 0;
}
case AMDGPU_INFO_VRAM_GTT: {
struct drm_amdgpu_info_vram_gtt vram_gtt;
vram_gtt.vram_size = adev->mc.real_vram_size;
vram_gtt.vram_cpu_accessible_size = adev->mc.visible_vram_size;
vram_gtt.vram_cpu_accessible_size -= adev->vram_pin_size;
vram_gtt.gtt_size = adev->mc.gtt_size;
vram_gtt.gtt_size -= adev->gart_pin_size;
return copy_to_user(out, &vram_gtt,
min((size_t)size, sizeof(vram_gtt))) ? -EFAULT : 0;
}
case AMDGPU_INFO_READ_MMR_REG: {
unsigned n, alloc_size;
uint32_t *regs;
unsigned se_num = (info->read_mmr_reg.instance >>
AMDGPU_INFO_MMR_SE_INDEX_SHIFT) &
AMDGPU_INFO_MMR_SE_INDEX_MASK;
unsigned sh_num = (info->read_mmr_reg.instance >>
AMDGPU_INFO_MMR_SH_INDEX_SHIFT) &
AMDGPU_INFO_MMR_SH_INDEX_MASK;
if (se_num == AMDGPU_INFO_MMR_SE_INDEX_MASK)
se_num = 0xffffffff;
if (sh_num == AMDGPU_INFO_MMR_SH_INDEX_MASK)
sh_num = 0xffffffff;
regs = kmalloc_array(info->read_mmr_reg.count, sizeof(*regs), GFP_KERNEL);
if (!regs)
return -ENOMEM;
alloc_size = info->read_mmr_reg.count * sizeof(*regs);
for (i = 0; i < info->read_mmr_reg.count; i++)
if (amdgpu_asic_read_register(adev, se_num, sh_num,
info->read_mmr_reg.dword_offset + i,
&regs[i])) {
DRM_DEBUG_KMS("unallowed offset %#x\n",
info->read_mmr_reg.dword_offset + i);
kfree(regs);
return -EFAULT;
}
n = copy_to_user(out, regs, min(size, alloc_size));
kfree(regs);
return n ? -EFAULT : 0;
}
case AMDGPU_INFO_DEV_INFO: {
struct drm_amdgpu_info_device dev_info = {};
struct amdgpu_cu_info cu_info;
dev_info.device_id = dev->pdev->device;
dev_info.chip_rev = adev->rev_id;
dev_info.external_rev = adev->external_rev_id;
dev_info.pci_rev = dev->pdev->revision;
dev_info.family = adev->family;
dev_info.num_shader_engines = adev->gfx.config.max_shader_engines;
dev_info.num_shader_arrays_per_engine = adev->gfx.config.max_sh_per_se;
dev_info.gpu_counter_freq = amdgpu_asic_get_xclk(adev) * 10;
if (adev->pm.dpm_enabled) {
dev_info.max_engine_clock =
adev->pm.dpm.dyn_state.max_clock_voltage_on_ac.sclk * 10;
dev_info.max_memory_clock =
adev->pm.dpm.dyn_state.max_clock_voltage_on_ac.mclk * 10;
} else {
dev_info.max_engine_clock = adev->pm.default_sclk * 10;
dev_info.max_memory_clock = adev->pm.default_mclk * 10;
}
dev_info.enabled_rb_pipes_mask = adev->gfx.config.backend_enable_mask;
dev_info.num_rb_pipes = adev->gfx.config.max_backends_per_se *
adev->gfx.config.max_shader_engines;
dev_info.num_hw_gfx_contexts = adev->gfx.config.max_hw_contexts;
dev_info._pad = 0;
dev_info.ids_flags = 0;
if (adev->flags & AMD_IS_APU)
dev_info.ids_flags |= AMDGPU_IDS_FLAGS_FUSION;
dev_info.virtual_address_offset = AMDGPU_VA_RESERVED_SIZE;
dev_info.virtual_address_max = (uint64_t)adev->vm_manager.max_pfn * AMDGPU_GPU_PAGE_SIZE;
dev_info.virtual_address_alignment = max((int)PAGE_SIZE, AMDGPU_GPU_PAGE_SIZE);
dev_info.pte_fragment_size = (1 << AMDGPU_LOG2_PAGES_PER_FRAG) *
AMDGPU_GPU_PAGE_SIZE;
dev_info.gart_page_size = AMDGPU_GPU_PAGE_SIZE;
amdgpu_asic_get_cu_info(adev, &cu_info);
dev_info.cu_active_number = cu_info.number;
dev_info.cu_ao_mask = cu_info.ao_cu_mask;
dev_info.ce_ram_size = adev->gfx.ce_ram_size;
memcpy(&dev_info.cu_bitmap[0], &cu_info.bitmap[0], sizeof(cu_info.bitmap));
dev_info.vram_type = adev->mc.vram_type;
dev_info.vram_bit_width = adev->mc.vram_width;
dev_info.vce_harvest_config = adev->vce.harvest_config;
return copy_to_user(out, &dev_info,
min((size_t)size, sizeof(dev_info))) ? -EFAULT : 0;
}
default:
DRM_DEBUG_KMS("Invalid request %d\n", info->query);
return -EINVAL;
}
return 0;
}
void amdgpu_driver_lastclose_kms(struct drm_device *dev)
{
struct amdgpu_device *adev = dev->dev_private;
amdgpu_fbdev_restore_mode(adev);
vga_switcheroo_process_delayed_switch();
}
int amdgpu_driver_open_kms(struct drm_device *dev, struct drm_file *file_priv)
{
struct amdgpu_device *adev = dev->dev_private;
struct amdgpu_fpriv *fpriv;
int r;
file_priv->driver_priv = NULL;
r = pm_runtime_get_sync(dev->dev);
if (r < 0)
return r;
fpriv = kzalloc(sizeof(*fpriv), GFP_KERNEL);
if (unlikely(!fpriv))
return -ENOMEM;
r = amdgpu_vm_init(adev, &fpriv->vm);
if (r)
goto error_free;
mutex_init(&fpriv->bo_list_lock);
idr_init(&fpriv->bo_list_handles);
amdgpu_ctx_mgr_init(&fpriv->ctx_mgr);
file_priv->driver_priv = fpriv;
pm_runtime_mark_last_busy(dev->dev);
pm_runtime_put_autosuspend(dev->dev);
return 0;
error_free:
kfree(fpriv);
return r;
}
void amdgpu_driver_postclose_kms(struct drm_device *dev,
struct drm_file *file_priv)
{
struct amdgpu_device *adev = dev->dev_private;
struct amdgpu_fpriv *fpriv = file_priv->driver_priv;
struct amdgpu_bo_list *list;
int handle;
if (!fpriv)
return;
amdgpu_ctx_mgr_fini(&fpriv->ctx_mgr);
amdgpu_vm_fini(adev, &fpriv->vm);
idr_for_each_entry(&fpriv->bo_list_handles, list, handle)
amdgpu_bo_list_free(list);
idr_destroy(&fpriv->bo_list_handles);
mutex_destroy(&fpriv->bo_list_lock);
kfree(fpriv);
file_priv->driver_priv = NULL;
}
void amdgpu_driver_preclose_kms(struct drm_device *dev,
struct drm_file *file_priv)
{
struct amdgpu_device *adev = dev->dev_private;
amdgpu_uvd_free_handles(adev, file_priv);
amdgpu_vce_free_handles(adev, file_priv);
}
u32 amdgpu_get_vblank_counter_kms(struct drm_device *dev, unsigned int pipe)
{
struct amdgpu_device *adev = dev->dev_private;
int vpos, hpos, stat;
u32 count;
if (pipe >= adev->mode_info.num_crtc) {
DRM_ERROR("Invalid crtc %u\n", pipe);
return -EINVAL;
}
if (adev->mode_info.crtcs[pipe]) {
do {
count = amdgpu_display_vblank_get_counter(adev, pipe);
stat = amdgpu_get_crtc_scanoutpos(
dev, pipe, GET_DISTANCE_TO_VBLANKSTART,
&vpos, &hpos, NULL, NULL,
&adev->mode_info.crtcs[pipe]->base.hwmode);
} while (count != amdgpu_display_vblank_get_counter(adev, pipe));
if (((stat & (DRM_SCANOUTPOS_VALID | DRM_SCANOUTPOS_ACCURATE)) !=
(DRM_SCANOUTPOS_VALID | DRM_SCANOUTPOS_ACCURATE))) {
DRM_DEBUG_VBL("Query failed! stat %d\n", stat);
} else {
DRM_DEBUG_VBL("crtc %d: dist from vblank start %d\n",
pipe, vpos);
if (vpos >= 0)
count++;
}
} else {
count = amdgpu_display_vblank_get_counter(adev, pipe);
DRM_DEBUG_VBL("NULL mode info! Returned count may be wrong.\n");
}
return count;
}
int amdgpu_enable_vblank_kms(struct drm_device *dev, unsigned int pipe)
{
struct amdgpu_device *adev = dev->dev_private;
int idx = amdgpu_crtc_idx_to_irq_type(adev, pipe);
return amdgpu_irq_get(adev, &adev->crtc_irq, idx);
}
void amdgpu_disable_vblank_kms(struct drm_device *dev, unsigned int pipe)
{
struct amdgpu_device *adev = dev->dev_private;
int idx = amdgpu_crtc_idx_to_irq_type(adev, pipe);
amdgpu_irq_put(adev, &adev->crtc_irq, idx);
}
int amdgpu_get_vblank_timestamp_kms(struct drm_device *dev, unsigned int pipe,
int *max_error,
struct timeval *vblank_time,
unsigned flags)
{
struct drm_crtc *crtc;
struct amdgpu_device *adev = dev->dev_private;
if (pipe >= dev->num_crtcs) {
DRM_ERROR("Invalid crtc %u\n", pipe);
return -EINVAL;
}
crtc = &adev->mode_info.crtcs[pipe]->base;
return drm_calc_vbltimestamp_from_scanoutpos(dev, pipe, max_error,
vblank_time, flags,
&crtc->hwmode);
}
