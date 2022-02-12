bool amdgpu_atomfirmware_gpu_supports_virtualization(struct amdgpu_device *adev)
{
int index = get_index_into_master_table(atom_master_list_of_data_tables_v2_1,
firmwareinfo);
uint16_t data_offset;
if (amdgpu_atom_parse_data_header(adev->mode_info.atom_context, index, NULL,
NULL, NULL, &data_offset)) {
struct atom_firmware_info_v3_1 *firmware_info =
(struct atom_firmware_info_v3_1 *)(adev->mode_info.atom_context->bios +
data_offset);
if (le32_to_cpu(firmware_info->firmware_capability) &
ATOM_FIRMWARE_CAP_GPU_VIRTUALIZATION)
return true;
}
return false;
}
void amdgpu_atomfirmware_scratch_regs_init(struct amdgpu_device *adev)
{
int index = get_index_into_master_table(atom_master_list_of_data_tables_v2_1,
firmwareinfo);
uint16_t data_offset;
if (amdgpu_atom_parse_data_header(adev->mode_info.atom_context, index, NULL,
NULL, NULL, &data_offset)) {
struct atom_firmware_info_v3_1 *firmware_info =
(struct atom_firmware_info_v3_1 *)(adev->mode_info.atom_context->bios +
data_offset);
adev->bios_scratch_reg_offset =
le32_to_cpu(firmware_info->bios_scratch_reg_startaddr);
}
}
void amdgpu_atomfirmware_scratch_regs_save(struct amdgpu_device *adev)
{
int i;
for (i = 0; i < AMDGPU_BIOS_NUM_SCRATCH; i++)
adev->bios_scratch[i] = RREG32(adev->bios_scratch_reg_offset + i);
}
void amdgpu_atomfirmware_scratch_regs_restore(struct amdgpu_device *adev)
{
int i;
adev->bios_scratch[7] &= ~ATOM_S7_ASIC_INIT_COMPLETE_MASK;
for (i = 0; i < AMDGPU_BIOS_NUM_SCRATCH; i++)
WREG32(adev->bios_scratch_reg_offset + i, adev->bios_scratch[i]);
}
void amdgpu_atomfirmware_scratch_regs_engine_hung(struct amdgpu_device *adev,
bool hung)
{
u32 tmp = RREG32(adev->bios_scratch_reg_offset + 3);
if (hung)
tmp |= ATOM_S3_ASIC_GUI_ENGINE_HUNG;
else
tmp &= ~ATOM_S3_ASIC_GUI_ENGINE_HUNG;
WREG32(adev->bios_scratch_reg_offset + 3, tmp);
}
int amdgpu_atomfirmware_allocate_fb_scratch(struct amdgpu_device *adev)
{
struct atom_context *ctx = adev->mode_info.atom_context;
int index = get_index_into_master_table(atom_master_list_of_data_tables_v2_1,
vram_usagebyfirmware);
uint16_t data_offset;
int usage_bytes = 0;
if (amdgpu_atom_parse_data_header(ctx, index, NULL, NULL, NULL, &data_offset)) {
struct vram_usagebyfirmware_v2_1 *firmware_usage =
(struct vram_usagebyfirmware_v2_1 *)(ctx->bios + data_offset);
DRM_DEBUG("atom firmware requested %08x %dkb fw %dkb drv\n",
le32_to_cpu(firmware_usage->start_address_in_kb),
le16_to_cpu(firmware_usage->used_by_firmware_in_kb),
le16_to_cpu(firmware_usage->used_by_driver_in_kb));
usage_bytes = le16_to_cpu(firmware_usage->used_by_driver_in_kb) * 1024;
}
ctx->scratch_size_bytes = 0;
if (usage_bytes == 0)
usage_bytes = 20 * 1024;
ctx->scratch = kzalloc(usage_bytes, GFP_KERNEL);
if (!ctx->scratch)
return -ENOMEM;
ctx->scratch_size_bytes = usage_bytes;
return 0;
}
