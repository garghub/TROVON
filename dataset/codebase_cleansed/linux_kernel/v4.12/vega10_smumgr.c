static bool vega10_is_smc_ram_running(struct pp_smumgr *smumgr)
{
uint32_t mp1_fw_flags, reg;
reg = soc15_get_register_offset(NBIF_HWID, 0,
mmPCIE_INDEX2_BASE_IDX, mmPCIE_INDEX2);
cgs_write_register(smumgr->device, reg,
(MP1_Public | (smnMP1_FIRMWARE_FLAGS & 0xffffffff)));
reg = soc15_get_register_offset(NBIF_HWID, 0,
mmPCIE_DATA2_BASE_IDX, mmPCIE_DATA2);
mp1_fw_flags = cgs_read_register(smumgr->device, reg);
if (mp1_fw_flags & MP1_FIRMWARE_FLAGS__INTERRUPTS_ENABLED_MASK)
return true;
return false;
}
static uint32_t vega10_wait_for_response(struct pp_smumgr *smumgr)
{
uint32_t reg;
if (!vega10_is_smc_ram_running(smumgr))
return -EINVAL;
reg = soc15_get_register_offset(MP1_HWID, 0,
mmMP1_SMN_C2PMSG_90_BASE_IDX, mmMP1_SMN_C2PMSG_90);
smum_wait_for_register_unequal(smumgr, reg,
0, MP1_C2PMSG_90__CONTENT_MASK);
return cgs_read_register(smumgr->device, reg);
}
int vega10_send_msg_to_smc_without_waiting(struct pp_smumgr *smumgr,
uint16_t msg)
{
uint32_t reg;
if (!vega10_is_smc_ram_running(smumgr))
return -EINVAL;
reg = soc15_get_register_offset(MP1_HWID, 0,
mmMP1_SMN_C2PMSG_66_BASE_IDX, mmMP1_SMN_C2PMSG_66);
cgs_write_register(smumgr->device, reg, msg);
return 0;
}
int vega10_send_msg_to_smc(struct pp_smumgr *smumgr, uint16_t msg)
{
uint32_t reg;
if (!vega10_is_smc_ram_running(smumgr))
return -EINVAL;
vega10_wait_for_response(smumgr);
reg = soc15_get_register_offset(MP1_HWID, 0,
mmMP1_SMN_C2PMSG_90_BASE_IDX, mmMP1_SMN_C2PMSG_90);
cgs_write_register(smumgr->device, reg, 0);
vega10_send_msg_to_smc_without_waiting(smumgr, msg);
if (vega10_wait_for_response(smumgr) != 1)
pr_err("Failed to send message: 0x%x\n", msg);
return 0;
}
int vega10_send_msg_to_smc_with_parameter(struct pp_smumgr *smumgr,
uint16_t msg, uint32_t parameter)
{
uint32_t reg;
if (!vega10_is_smc_ram_running(smumgr))
return -EINVAL;
vega10_wait_for_response(smumgr);
reg = soc15_get_register_offset(MP1_HWID, 0,
mmMP1_SMN_C2PMSG_90_BASE_IDX, mmMP1_SMN_C2PMSG_90);
cgs_write_register(smumgr->device, reg, 0);
reg = soc15_get_register_offset(MP1_HWID, 0,
mmMP1_SMN_C2PMSG_82_BASE_IDX, mmMP1_SMN_C2PMSG_82);
cgs_write_register(smumgr->device, reg, parameter);
vega10_send_msg_to_smc_without_waiting(smumgr, msg);
if (vega10_wait_for_response(smumgr) != 1)
pr_err("Failed to send message: 0x%x\n", msg);
return 0;
}
int vega10_send_msg_to_smc_with_parameter_without_waiting(
struct pp_smumgr *smumgr, uint16_t msg, uint32_t parameter)
{
uint32_t reg;
reg = soc15_get_register_offset(MP1_HWID, 0,
mmMP1_SMN_C2PMSG_82_BASE_IDX, mmMP1_SMN_C2PMSG_82);
cgs_write_register(smumgr->device, reg, parameter);
return vega10_send_msg_to_smc_without_waiting(smumgr, msg);
}
int vega10_read_arg_from_smc(struct pp_smumgr *smumgr, uint32_t *arg)
{
uint32_t reg;
reg = soc15_get_register_offset(MP1_HWID, 0,
mmMP1_SMN_C2PMSG_82_BASE_IDX, mmMP1_SMN_C2PMSG_82);
*arg = cgs_read_register(smumgr->device, reg);
return 0;
}
int vega10_copy_table_from_smc(struct pp_smumgr *smumgr,
uint8_t *table, int16_t table_id)
{
struct vega10_smumgr *priv =
(struct vega10_smumgr *)(smumgr->backend);
PP_ASSERT_WITH_CODE(table_id < MAX_SMU_TABLE,
"Invalid SMU Table ID!", return -EINVAL);
PP_ASSERT_WITH_CODE(priv->smu_tables.entry[table_id].version != 0,
"Invalid SMU Table version!", return -EINVAL);
PP_ASSERT_WITH_CODE(priv->smu_tables.entry[table_id].size != 0,
"Invalid SMU Table Length!", return -EINVAL);
PP_ASSERT_WITH_CODE(vega10_send_msg_to_smc_with_parameter(smumgr,
PPSMC_MSG_SetDriverDramAddrHigh,
priv->smu_tables.entry[table_id].table_addr_high) == 0,
"[CopyTableFromSMC] Attempt to Set Dram Addr High Failed!", return -EINVAL);
PP_ASSERT_WITH_CODE(vega10_send_msg_to_smc_with_parameter(smumgr,
PPSMC_MSG_SetDriverDramAddrLow,
priv->smu_tables.entry[table_id].table_addr_low) == 0,
"[CopyTableFromSMC] Attempt to Set Dram Addr Low Failed!",
return -EINVAL);
PP_ASSERT_WITH_CODE(vega10_send_msg_to_smc_with_parameter(smumgr,
PPSMC_MSG_TransferTableSmu2Dram,
priv->smu_tables.entry[table_id].table_id) == 0,
"[CopyTableFromSMC] Attempt to Transfer Table From SMU Failed!",
return -EINVAL);
memcpy(table, priv->smu_tables.entry[table_id].table,
priv->smu_tables.entry[table_id].size);
return 0;
}
int vega10_copy_table_to_smc(struct pp_smumgr *smumgr,
uint8_t *table, int16_t table_id)
{
struct vega10_smumgr *priv =
(struct vega10_smumgr *)(smumgr->backend);
PP_ASSERT_WITH_CODE(table_id < MAX_SMU_TABLE,
"Invalid SMU Table ID!", return -EINVAL);
PP_ASSERT_WITH_CODE(priv->smu_tables.entry[table_id].version != 0,
"Invalid SMU Table version!", return -EINVAL);
PP_ASSERT_WITH_CODE(priv->smu_tables.entry[table_id].size != 0,
"Invalid SMU Table Length!", return -EINVAL);
memcpy(priv->smu_tables.entry[table_id].table, table,
priv->smu_tables.entry[table_id].size);
PP_ASSERT_WITH_CODE(vega10_send_msg_to_smc_with_parameter(smumgr,
PPSMC_MSG_SetDriverDramAddrHigh,
priv->smu_tables.entry[table_id].table_addr_high) == 0,
"[CopyTableToSMC] Attempt to Set Dram Addr High Failed!",
return -EINVAL;);
PP_ASSERT_WITH_CODE(vega10_send_msg_to_smc_with_parameter(smumgr,
PPSMC_MSG_SetDriverDramAddrLow,
priv->smu_tables.entry[table_id].table_addr_low) == 0,
"[CopyTableToSMC] Attempt to Set Dram Addr Low Failed!",
return -EINVAL);
PP_ASSERT_WITH_CODE(vega10_send_msg_to_smc_with_parameter(smumgr,
PPSMC_MSG_TransferTableDram2Smu,
priv->smu_tables.entry[table_id].table_id) == 0,
"[CopyTableToSMC] Attempt to Transfer Table To SMU Failed!",
return -EINVAL);
return 0;
}
int vega10_save_vft_table(struct pp_smumgr *smumgr, uint8_t *avfs_table)
{
PP_ASSERT_WITH_CODE(avfs_table,
"No access to SMC AVFS Table",
return -EINVAL);
return vega10_copy_table_from_smc(smumgr, avfs_table, AVFSTABLE);
}
int vega10_restore_vft_table(struct pp_smumgr *smumgr, uint8_t *avfs_table)
{
PP_ASSERT_WITH_CODE(avfs_table,
"No access to SMC AVFS Table",
return -EINVAL);
return vega10_copy_table_to_smc(smumgr, avfs_table, AVFSTABLE);
}
int vega10_enable_smc_features(struct pp_smumgr *smumgr,
bool enable, uint32_t feature_mask)
{
int msg = enable ? PPSMC_MSG_EnableSmuFeatures :
PPSMC_MSG_DisableSmuFeatures;
return vega10_send_msg_to_smc_with_parameter(smumgr,
msg, feature_mask);
}
int vega10_get_smc_features(struct pp_smumgr *smumgr,
uint32_t *features_enabled)
{
if (features_enabled == NULL)
return -EINVAL;
if (!vega10_send_msg_to_smc(smumgr,
PPSMC_MSG_GetEnabledSmuFeatures)) {
vega10_read_arg_from_smc(smumgr, features_enabled);
return 0;
}
return -EINVAL;
}
int vega10_set_tools_address(struct pp_smumgr *smumgr)
{
struct vega10_smumgr *priv =
(struct vega10_smumgr *)(smumgr->backend);
if (priv->smu_tables.entry[TOOLSTABLE].table_addr_high ||
priv->smu_tables.entry[TOOLSTABLE].table_addr_low) {
if (!vega10_send_msg_to_smc_with_parameter(smumgr,
PPSMC_MSG_SetToolsDramAddrHigh,
priv->smu_tables.entry[TOOLSTABLE].table_addr_high))
vega10_send_msg_to_smc_with_parameter(smumgr,
PPSMC_MSG_SetToolsDramAddrLow,
priv->smu_tables.entry[TOOLSTABLE].table_addr_low);
}
return 0;
}
static int vega10_verify_smc_interface(struct pp_smumgr *smumgr)
{
uint32_t smc_driver_if_version;
PP_ASSERT_WITH_CODE(!vega10_send_msg_to_smc(smumgr,
PPSMC_MSG_GetDriverIfVersion),
"Attempt to get SMC IF Version Number Failed!",
return -EINVAL);
vega10_read_arg_from_smc(smumgr, &smc_driver_if_version);
if (smc_driver_if_version != SMU9_DRIVER_IF_VERSION) {
pr_err("Your firmware(0x%x) doesn't match \
SMU9_DRIVER_IF_VERSION(0x%x). \
Please update your firmware!\n",
smc_driver_if_version, SMU9_DRIVER_IF_VERSION);
return -EINVAL;
}
return 0;
}
static int vega10_smu_init(struct pp_smumgr *smumgr)
{
struct vega10_smumgr *priv;
uint64_t mc_addr;
void *kaddr = NULL;
unsigned long handle, tools_size;
int ret;
struct cgs_firmware_info info = {0};
ret = cgs_get_firmware_info(smumgr->device,
smu7_convert_fw_type_to_cgs(UCODE_ID_SMU),
&info);
if (ret || !info.kptr)
return -EINVAL;
priv = kzalloc(sizeof(struct vega10_smumgr), GFP_KERNEL);
if (!priv)
return -ENOMEM;
smumgr->backend = priv;
smu_allocate_memory(smumgr->device,
sizeof(PPTable_t),
CGS_GPU_MEM_TYPE__VISIBLE_CONTIG_FB,
PAGE_SIZE,
&mc_addr,
&kaddr,
&handle);
PP_ASSERT_WITH_CODE(kaddr,
"[vega10_smu_init] Out of memory for pptable.",
kfree(smumgr->backend);
cgs_free_gpu_mem(smumgr->device,
(cgs_handle_t)handle);
return -EINVAL);
priv->smu_tables.entry[PPTABLE].version = 0x01;
priv->smu_tables.entry[PPTABLE].size = sizeof(PPTable_t);
priv->smu_tables.entry[PPTABLE].table_id = TABLE_PPTABLE;
priv->smu_tables.entry[PPTABLE].table_addr_high =
smu_upper_32_bits(mc_addr);
priv->smu_tables.entry[PPTABLE].table_addr_low =
smu_lower_32_bits(mc_addr);
priv->smu_tables.entry[PPTABLE].table = kaddr;
priv->smu_tables.entry[PPTABLE].handle = handle;
smu_allocate_memory(smumgr->device,
sizeof(Watermarks_t),
CGS_GPU_MEM_TYPE__VISIBLE_CONTIG_FB,
PAGE_SIZE,
&mc_addr,
&kaddr,
&handle);
PP_ASSERT_WITH_CODE(kaddr,
"[vega10_smu_init] Out of memory for wmtable.",
kfree(smumgr->backend);
cgs_free_gpu_mem(smumgr->device,
(cgs_handle_t)priv->smu_tables.entry[PPTABLE].handle);
cgs_free_gpu_mem(smumgr->device,
(cgs_handle_t)handle);
return -EINVAL);
priv->smu_tables.entry[WMTABLE].version = 0x01;
priv->smu_tables.entry[WMTABLE].size = sizeof(Watermarks_t);
priv->smu_tables.entry[WMTABLE].table_id = TABLE_WATERMARKS;
priv->smu_tables.entry[WMTABLE].table_addr_high =
smu_upper_32_bits(mc_addr);
priv->smu_tables.entry[WMTABLE].table_addr_low =
smu_lower_32_bits(mc_addr);
priv->smu_tables.entry[WMTABLE].table = kaddr;
priv->smu_tables.entry[WMTABLE].handle = handle;
smu_allocate_memory(smumgr->device,
sizeof(AvfsTable_t),
CGS_GPU_MEM_TYPE__VISIBLE_CONTIG_FB,
PAGE_SIZE,
&mc_addr,
&kaddr,
&handle);
PP_ASSERT_WITH_CODE(kaddr,
"[vega10_smu_init] Out of memory for avfs table.",
kfree(smumgr->backend);
cgs_free_gpu_mem(smumgr->device,
(cgs_handle_t)priv->smu_tables.entry[PPTABLE].handle);
cgs_free_gpu_mem(smumgr->device,
(cgs_handle_t)priv->smu_tables.entry[WMTABLE].handle);
cgs_free_gpu_mem(smumgr->device,
(cgs_handle_t)handle);
return -EINVAL);
priv->smu_tables.entry[AVFSTABLE].version = 0x01;
priv->smu_tables.entry[AVFSTABLE].size = sizeof(AvfsTable_t);
priv->smu_tables.entry[AVFSTABLE].table_id = TABLE_AVFS;
priv->smu_tables.entry[AVFSTABLE].table_addr_high =
smu_upper_32_bits(mc_addr);
priv->smu_tables.entry[AVFSTABLE].table_addr_low =
smu_lower_32_bits(mc_addr);
priv->smu_tables.entry[AVFSTABLE].table = kaddr;
priv->smu_tables.entry[AVFSTABLE].handle = handle;
tools_size = 0x19000;
if (tools_size) {
smu_allocate_memory(smumgr->device,
tools_size,
CGS_GPU_MEM_TYPE__VISIBLE_CONTIG_FB,
PAGE_SIZE,
&mc_addr,
&kaddr,
&handle);
if (kaddr) {
priv->smu_tables.entry[TOOLSTABLE].version = 0x01;
priv->smu_tables.entry[TOOLSTABLE].size = tools_size;
priv->smu_tables.entry[TOOLSTABLE].table_id = TABLE_PMSTATUSLOG;
priv->smu_tables.entry[TOOLSTABLE].table_addr_high =
smu_upper_32_bits(mc_addr);
priv->smu_tables.entry[TOOLSTABLE].table_addr_low =
smu_lower_32_bits(mc_addr);
priv->smu_tables.entry[TOOLSTABLE].table = kaddr;
priv->smu_tables.entry[TOOLSTABLE].handle = handle;
vega10_set_tools_address(smumgr);
}
}
smu_allocate_memory(smumgr->device,
sizeof(AvfsFuseOverride_t),
CGS_GPU_MEM_TYPE__VISIBLE_CONTIG_FB,
PAGE_SIZE,
&mc_addr,
&kaddr,
&handle);
PP_ASSERT_WITH_CODE(kaddr,
"[vega10_smu_init] Out of memory for avfs fuse table.",
kfree(smumgr->backend);
cgs_free_gpu_mem(smumgr->device,
(cgs_handle_t)priv->smu_tables.entry[PPTABLE].handle);
cgs_free_gpu_mem(smumgr->device,
(cgs_handle_t)priv->smu_tables.entry[WMTABLE].handle);
cgs_free_gpu_mem(smumgr->device,
(cgs_handle_t)priv->smu_tables.entry[AVFSTABLE].handle);
cgs_free_gpu_mem(smumgr->device,
(cgs_handle_t)priv->smu_tables.entry[TOOLSTABLE].handle);
cgs_free_gpu_mem(smumgr->device,
(cgs_handle_t)handle);
return -EINVAL);
priv->smu_tables.entry[AVFSFUSETABLE].version = 0x01;
priv->smu_tables.entry[AVFSFUSETABLE].size = sizeof(AvfsFuseOverride_t);
priv->smu_tables.entry[AVFSFUSETABLE].table_id = TABLE_AVFS_FUSE_OVERRIDE;
priv->smu_tables.entry[AVFSFUSETABLE].table_addr_high =
smu_upper_32_bits(mc_addr);
priv->smu_tables.entry[AVFSFUSETABLE].table_addr_low =
smu_lower_32_bits(mc_addr);
priv->smu_tables.entry[AVFSFUSETABLE].table = kaddr;
priv->smu_tables.entry[AVFSFUSETABLE].handle = handle;
return 0;
}
static int vega10_smu_fini(struct pp_smumgr *smumgr)
{
struct vega10_smumgr *priv =
(struct vega10_smumgr *)(smumgr->backend);
if (priv) {
cgs_free_gpu_mem(smumgr->device,
(cgs_handle_t)priv->smu_tables.entry[PPTABLE].handle);
cgs_free_gpu_mem(smumgr->device,
(cgs_handle_t)priv->smu_tables.entry[WMTABLE].handle);
cgs_free_gpu_mem(smumgr->device,
(cgs_handle_t)priv->smu_tables.entry[AVFSTABLE].handle);
if (priv->smu_tables.entry[TOOLSTABLE].table)
cgs_free_gpu_mem(smumgr->device,
(cgs_handle_t)priv->smu_tables.entry[TOOLSTABLE].handle);
cgs_free_gpu_mem(smumgr->device,
(cgs_handle_t)priv->smu_tables.entry[AVFSFUSETABLE].handle);
kfree(smumgr->backend);
smumgr->backend = NULL;
}
return 0;
}
static int vega10_start_smu(struct pp_smumgr *smumgr)
{
PP_ASSERT_WITH_CODE(!vega10_verify_smc_interface(smumgr),
"Failed to verify SMC interface!",
return -EINVAL);
return 0;
}
