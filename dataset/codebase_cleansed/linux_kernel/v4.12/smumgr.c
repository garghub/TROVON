int smum_early_init(struct pp_instance *handle)
{
struct pp_smumgr *smumgr;
if (handle == NULL)
return -EINVAL;
smumgr = kzalloc(sizeof(struct pp_smumgr), GFP_KERNEL);
if (smumgr == NULL)
return -ENOMEM;
smumgr->device = handle->device;
smumgr->chip_family = handle->chip_family;
smumgr->chip_id = handle->chip_id;
smumgr->usec_timeout = AMD_MAX_USEC_TIMEOUT;
smumgr->reload_fw = 1;
handle->smu_mgr = smumgr;
switch (smumgr->chip_family) {
case AMDGPU_FAMILY_CZ:
smumgr->smumgr_funcs = &cz_smu_funcs;
break;
case AMDGPU_FAMILY_VI:
switch (smumgr->chip_id) {
case CHIP_TOPAZ:
smumgr->smumgr_funcs = &iceland_smu_funcs;
break;
case CHIP_TONGA:
smumgr->smumgr_funcs = &tonga_smu_funcs;
break;
case CHIP_FIJI:
smumgr->smumgr_funcs = &fiji_smu_funcs;
break;
case CHIP_POLARIS11:
case CHIP_POLARIS10:
case CHIP_POLARIS12:
smumgr->smumgr_funcs = &polaris10_smu_funcs;
break;
default:
return -EINVAL;
}
break;
case AMDGPU_FAMILY_AI:
switch (smumgr->chip_id) {
case CHIP_VEGA10:
smumgr->smumgr_funcs = &vega10_smu_funcs;
break;
default:
return -EINVAL;
}
break;
default:
kfree(smumgr);
return -EINVAL;
}
return 0;
}
int smum_thermal_avfs_enable(struct pp_hwmgr *hwmgr,
void *input, void *output, void *storage, int result)
{
if (NULL != hwmgr->smumgr->smumgr_funcs->thermal_avfs_enable)
return hwmgr->smumgr->smumgr_funcs->thermal_avfs_enable(hwmgr);
return 0;
}
int smum_thermal_setup_fan_table(struct pp_hwmgr *hwmgr,
void *input, void *output, void *storage, int result)
{
if (NULL != hwmgr->smumgr->smumgr_funcs->thermal_setup_fan_table)
return hwmgr->smumgr->smumgr_funcs->thermal_setup_fan_table(hwmgr);
return 0;
}
int smum_update_sclk_threshold(struct pp_hwmgr *hwmgr)
{
if (NULL != hwmgr->smumgr->smumgr_funcs->update_sclk_threshold)
return hwmgr->smumgr->smumgr_funcs->update_sclk_threshold(hwmgr);
return 0;
}
int smum_update_smc_table(struct pp_hwmgr *hwmgr, uint32_t type)
{
if (NULL != hwmgr->smumgr->smumgr_funcs->update_smc_table)
return hwmgr->smumgr->smumgr_funcs->update_smc_table(hwmgr, type);
return 0;
}
uint32_t smum_get_offsetof(struct pp_smumgr *smumgr, uint32_t type, uint32_t member)
{
if (NULL != smumgr->smumgr_funcs->get_offsetof)
return smumgr->smumgr_funcs->get_offsetof(type, member);
return 0;
}
int smum_process_firmware_header(struct pp_hwmgr *hwmgr)
{
if (NULL != hwmgr->smumgr->smumgr_funcs->process_firmware_header)
return hwmgr->smumgr->smumgr_funcs->process_firmware_header(hwmgr);
return 0;
}
int smum_get_argument(struct pp_smumgr *smumgr)
{
if (NULL != smumgr->smumgr_funcs->get_argument)
return smumgr->smumgr_funcs->get_argument(smumgr);
return 0;
}
uint32_t smum_get_mac_definition(struct pp_smumgr *smumgr, uint32_t value)
{
if (NULL != smumgr->smumgr_funcs->get_mac_definition)
return smumgr->smumgr_funcs->get_mac_definition(value);
return 0;
}
int smum_download_powerplay_table(struct pp_smumgr *smumgr,
void **table)
{
if (NULL != smumgr->smumgr_funcs->download_pptable_settings)
return smumgr->smumgr_funcs->download_pptable_settings(smumgr,
table);
return 0;
}
int smum_upload_powerplay_table(struct pp_smumgr *smumgr)
{
if (NULL != smumgr->smumgr_funcs->upload_pptable_settings)
return smumgr->smumgr_funcs->upload_pptable_settings(smumgr);
return 0;
}
int smum_send_msg_to_smc(struct pp_smumgr *smumgr, uint16_t msg)
{
if (smumgr == NULL || smumgr->smumgr_funcs->send_msg_to_smc == NULL)
return -EINVAL;
return smumgr->smumgr_funcs->send_msg_to_smc(smumgr, msg);
}
int smum_send_msg_to_smc_with_parameter(struct pp_smumgr *smumgr,
uint16_t msg, uint32_t parameter)
{
if (smumgr == NULL ||
smumgr->smumgr_funcs->send_msg_to_smc_with_parameter == NULL)
return -EINVAL;
return smumgr->smumgr_funcs->send_msg_to_smc_with_parameter(
smumgr, msg, parameter);
}
int smum_wait_on_register(struct pp_smumgr *smumgr,
uint32_t index,
uint32_t value, uint32_t mask)
{
uint32_t i;
uint32_t cur_value;
if (smumgr == NULL || smumgr->device == NULL)
return -EINVAL;
for (i = 0; i < smumgr->usec_timeout; i++) {
cur_value = cgs_read_register(smumgr->device, index);
if ((cur_value & mask) == (value & mask))
break;
udelay(1);
}
if (i == smumgr->usec_timeout)
return -1;
return 0;
}
int smum_wait_for_register_unequal(struct pp_smumgr *smumgr,
uint32_t index,
uint32_t value, uint32_t mask)
{
uint32_t i;
uint32_t cur_value;
if (smumgr == NULL)
return -EINVAL;
for (i = 0; i < smumgr->usec_timeout; i++) {
cur_value = cgs_read_register(smumgr->device,
index);
if ((cur_value & mask) != (value & mask))
break;
udelay(1);
}
if (i == smumgr->usec_timeout)
return -1;
return 0;
}
int smum_wait_on_indirect_register(struct pp_smumgr *smumgr,
uint32_t indirect_port,
uint32_t index,
uint32_t value,
uint32_t mask)
{
if (smumgr == NULL || smumgr->device == NULL)
return -EINVAL;
cgs_write_register(smumgr->device, indirect_port, index);
return smum_wait_on_register(smumgr, indirect_port + 1,
mask, value);
}
void smum_wait_for_indirect_register_unequal(
struct pp_smumgr *smumgr,
uint32_t indirect_port,
uint32_t index,
uint32_t value,
uint32_t mask)
{
if (smumgr == NULL || smumgr->device == NULL)
return;
cgs_write_register(smumgr->device, indirect_port, index);
smum_wait_for_register_unequal(smumgr, indirect_port + 1,
value, mask);
}
int smu_allocate_memory(void *device, uint32_t size,
enum cgs_gpu_mem_type type,
uint32_t byte_align, uint64_t *mc_addr,
void **kptr, void *handle)
{
int ret = 0;
cgs_handle_t cgs_handle;
if (device == NULL || handle == NULL ||
mc_addr == NULL || kptr == NULL)
return -EINVAL;
ret = cgs_alloc_gpu_mem(device, type, size, byte_align,
0, 0, (cgs_handle_t *)handle);
if (ret)
return -ENOMEM;
cgs_handle = *(cgs_handle_t *)handle;
ret = cgs_gmap_gpu_mem(device, cgs_handle, mc_addr);
if (ret)
goto error_gmap;
ret = cgs_kmap_gpu_mem(device, cgs_handle, kptr);
if (ret)
goto error_kmap;
return 0;
error_kmap:
cgs_gunmap_gpu_mem(device, cgs_handle);
error_gmap:
cgs_free_gpu_mem(device, cgs_handle);
return ret;
}
int smu_free_memory(void *device, void *handle)
{
cgs_handle_t cgs_handle = (cgs_handle_t)handle;
if (device == NULL || handle == NULL)
return -EINVAL;
cgs_kunmap_gpu_mem(device, cgs_handle);
cgs_gunmap_gpu_mem(device, cgs_handle);
cgs_free_gpu_mem(device, cgs_handle);
return 0;
}
int smum_init_smc_table(struct pp_hwmgr *hwmgr)
{
if (NULL != hwmgr->smumgr->smumgr_funcs->init_smc_table)
return hwmgr->smumgr->smumgr_funcs->init_smc_table(hwmgr);
return 0;
}
int smum_populate_all_graphic_levels(struct pp_hwmgr *hwmgr)
{
if (NULL != hwmgr->smumgr->smumgr_funcs->populate_all_graphic_levels)
return hwmgr->smumgr->smumgr_funcs->populate_all_graphic_levels(hwmgr);
return 0;
}
int smum_populate_all_memory_levels(struct pp_hwmgr *hwmgr)
{
if (NULL != hwmgr->smumgr->smumgr_funcs->populate_all_memory_levels)
return hwmgr->smumgr->smumgr_funcs->populate_all_memory_levels(hwmgr);
return 0;
}
int smum_initialize_mc_reg_table(struct pp_hwmgr *hwmgr)
{
if (NULL != hwmgr->smumgr->smumgr_funcs->initialize_mc_reg_table)
return hwmgr->smumgr->smumgr_funcs->initialize_mc_reg_table(hwmgr);
return 0;
}
bool smum_is_dpm_running(struct pp_hwmgr *hwmgr)
{
if (NULL != hwmgr->smumgr->smumgr_funcs->is_dpm_running)
return hwmgr->smumgr->smumgr_funcs->is_dpm_running(hwmgr);
return true;
}
int smum_populate_requested_graphic_levels(struct pp_hwmgr *hwmgr,
struct amd_pp_profile *request)
{
if (hwmgr->smumgr->smumgr_funcs->populate_requested_graphic_levels)
return hwmgr->smumgr->smumgr_funcs->populate_requested_graphic_levels(
hwmgr, request);
return 0;
}
