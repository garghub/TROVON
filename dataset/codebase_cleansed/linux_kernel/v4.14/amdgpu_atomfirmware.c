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
int amdgpu_atomfirmware_get_vram_width(struct amdgpu_device *adev)
{
struct amdgpu_mode_info *mode_info = &adev->mode_info;
int index = get_index_into_master_table(atom_master_list_of_data_tables_v2_1,
integratedsysteminfo);
u16 data_offset, size;
union igp_info *igp_info;
u8 frev, crev;
if (amdgpu_atom_parse_data_header(mode_info->atom_context, index, &size,
&frev, &crev, &data_offset)) {
igp_info = (union igp_info *)
(mode_info->atom_context->bios + data_offset);
switch (crev) {
case 11:
return igp_info->v11.umachannelnumber * 64;
default:
return 0;
}
}
return 0;
}
int amdgpu_atomfirmware_get_clock_info(struct amdgpu_device *adev)
{
struct amdgpu_mode_info *mode_info = &adev->mode_info;
struct amdgpu_pll *spll = &adev->clock.spll;
struct amdgpu_pll *mpll = &adev->clock.mpll;
uint8_t frev, crev;
uint16_t data_offset;
int ret = -EINVAL, index;
index = get_index_into_master_table(atom_master_list_of_data_tables_v2_1,
firmwareinfo);
if (amdgpu_atom_parse_data_header(mode_info->atom_context, index, NULL,
&frev, &crev, &data_offset)) {
union firmware_info *firmware_info =
(union firmware_info *)(mode_info->atom_context->bios +
data_offset);
adev->clock.default_sclk =
le32_to_cpu(firmware_info->v31.bootup_sclk_in10khz);
adev->clock.default_mclk =
le32_to_cpu(firmware_info->v31.bootup_mclk_in10khz);
adev->pm.current_sclk = adev->clock.default_sclk;
adev->pm.current_mclk = adev->clock.default_mclk;
adev->mode_info.firmware_flags =
le32_to_cpu(firmware_info->v31.firmware_capability);
ret = 0;
}
index = get_index_into_master_table(atom_master_list_of_data_tables_v2_1,
smu_info);
if (amdgpu_atom_parse_data_header(mode_info->atom_context, index, NULL,
&frev, &crev, &data_offset)) {
union smu_info *smu_info =
(union smu_info *)(mode_info->atom_context->bios +
data_offset);
spll->reference_freq = le32_to_cpu(smu_info->v31.core_refclk_10khz);
spll->reference_div = 0;
spll->min_post_div = 1;
spll->max_post_div = 1;
spll->min_ref_div = 2;
spll->max_ref_div = 0xff;
spll->min_feedback_div = 4;
spll->max_feedback_div = 0xff;
spll->best_vco = 0;
ret = 0;
}
index = get_index_into_master_table(atom_master_list_of_data_tables_v2_1,
umc_info);
if (amdgpu_atom_parse_data_header(mode_info->atom_context, index, NULL,
&frev, &crev, &data_offset)) {
union umc_info *umc_info =
(union umc_info *)(mode_info->atom_context->bios +
data_offset);
mpll->reference_freq = le32_to_cpu(umc_info->v31.mem_refclk_10khz);
mpll->reference_div = 0;
mpll->min_post_div = 1;
mpll->max_post_div = 1;
mpll->min_ref_div = 2;
mpll->max_ref_div = 0xff;
mpll->min_feedback_div = 4;
mpll->max_feedback_div = 0xff;
mpll->best_vco = 0;
ret = 0;
}
return ret;
}
