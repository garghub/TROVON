bool rv_is_smc_ram_running(struct pp_smumgr *smumgr)
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
static uint32_t rv_wait_for_response(struct pp_smumgr *smumgr)
{
uint32_t reg;
if (!rv_is_smc_ram_running(smumgr))
return -EINVAL;
reg = soc15_get_register_offset(MP1_HWID, 0,
mmMP1_SMN_C2PMSG_90_BASE_IDX, mmMP1_SMN_C2PMSG_90);
smum_wait_for_register_unequal(smumgr, reg,
0, MP1_C2PMSG_90__CONTENT_MASK);
return cgs_read_register(smumgr->device, reg);
}
int rv_send_msg_to_smc_without_waiting(struct pp_smumgr *smumgr,
uint16_t msg)
{
uint32_t reg;
if (!rv_is_smc_ram_running(smumgr))
return -EINVAL;
reg = soc15_get_register_offset(MP1_HWID, 0,
mmMP1_SMN_C2PMSG_66_BASE_IDX, mmMP1_SMN_C2PMSG_66);
cgs_write_register(smumgr->device, reg, msg);
return 0;
}
int rv_read_arg_from_smc(struct pp_smumgr *smumgr, uint32_t *arg)
{
uint32_t reg;
reg = soc15_get_register_offset(MP1_HWID, 0,
mmMP1_SMN_C2PMSG_82_BASE_IDX, mmMP1_SMN_C2PMSG_82);
*arg = cgs_read_register(smumgr->device, reg);
return 0;
}
int rv_send_msg_to_smc(struct pp_smumgr *smumgr, uint16_t msg)
{
uint32_t reg;
rv_wait_for_response(smumgr);
reg = soc15_get_register_offset(MP1_HWID, 0,
mmMP1_SMN_C2PMSG_90_BASE_IDX, mmMP1_SMN_C2PMSG_90);
cgs_write_register(smumgr->device, reg, 0);
rv_send_msg_to_smc_without_waiting(smumgr, msg);
if (rv_wait_for_response(smumgr) == 0)
printk("Failed to send Message %x.\n", msg);
return 0;
}
int rv_send_msg_to_smc_with_parameter(struct pp_smumgr *smumgr,
uint16_t msg, uint32_t parameter)
{
uint32_t reg;
rv_wait_for_response(smumgr);
reg = soc15_get_register_offset(MP1_HWID, 0,
mmMP1_SMN_C2PMSG_90_BASE_IDX, mmMP1_SMN_C2PMSG_90);
cgs_write_register(smumgr->device, reg, 0);
reg = soc15_get_register_offset(MP1_HWID, 0,
mmMP1_SMN_C2PMSG_82_BASE_IDX, mmMP1_SMN_C2PMSG_82);
cgs_write_register(smumgr->device, reg, parameter);
rv_send_msg_to_smc_without_waiting(smumgr, msg);
if (rv_wait_for_response(smumgr) == 0)
printk("Failed to send Message %x.\n", msg);
return 0;
}
int rv_copy_table_from_smc(struct pp_smumgr *smumgr,
uint8_t *table, int16_t table_id)
{
struct rv_smumgr *priv =
(struct rv_smumgr *)(smumgr->backend);
PP_ASSERT_WITH_CODE(table_id < MAX_SMU_TABLE,
"Invalid SMU Table ID!", return -EINVAL;);
PP_ASSERT_WITH_CODE(priv->smu_tables.entry[table_id].version != 0,
"Invalid SMU Table version!", return -EINVAL;);
PP_ASSERT_WITH_CODE(priv->smu_tables.entry[table_id].size != 0,
"Invalid SMU Table Length!", return -EINVAL;);
PP_ASSERT_WITH_CODE(rv_send_msg_to_smc_with_parameter(smumgr,
PPSMC_MSG_SetDriverDramAddrHigh,
priv->smu_tables.entry[table_id].table_addr_high) == 0,
"[CopyTableFromSMC] Attempt to Set Dram Addr High Failed!", return -EINVAL;);
PP_ASSERT_WITH_CODE(rv_send_msg_to_smc_with_parameter(smumgr,
PPSMC_MSG_SetDriverDramAddrLow,
priv->smu_tables.entry[table_id].table_addr_low) == 0,
"[CopyTableFromSMC] Attempt to Set Dram Addr Low Failed!",
return -EINVAL;);
PP_ASSERT_WITH_CODE(rv_send_msg_to_smc_with_parameter(smumgr,
PPSMC_MSG_TransferTableSmu2Dram,
priv->smu_tables.entry[table_id].table_id) == 0,
"[CopyTableFromSMC] Attempt to Transfer Table From SMU Failed!",
return -EINVAL;);
memcpy(table, priv->smu_tables.entry[table_id].table,
priv->smu_tables.entry[table_id].size);
return 0;
}
int rv_copy_table_to_smc(struct pp_smumgr *smumgr,
uint8_t *table, int16_t table_id)
{
struct rv_smumgr *priv =
(struct rv_smumgr *)(smumgr->backend);
PP_ASSERT_WITH_CODE(table_id < MAX_SMU_TABLE,
"Invalid SMU Table ID!", return -EINVAL;);
PP_ASSERT_WITH_CODE(priv->smu_tables.entry[table_id].version != 0,
"Invalid SMU Table version!", return -EINVAL;);
PP_ASSERT_WITH_CODE(priv->smu_tables.entry[table_id].size != 0,
"Invalid SMU Table Length!", return -EINVAL;);
memcpy(priv->smu_tables.entry[table_id].table, table,
priv->smu_tables.entry[table_id].size);
PP_ASSERT_WITH_CODE(rv_send_msg_to_smc_with_parameter(smumgr,
PPSMC_MSG_SetDriverDramAddrHigh,
priv->smu_tables.entry[table_id].table_addr_high) == 0,
"[CopyTableToSMC] Attempt to Set Dram Addr High Failed!",
return -EINVAL;);
PP_ASSERT_WITH_CODE(rv_send_msg_to_smc_with_parameter(smumgr,
PPSMC_MSG_SetDriverDramAddrLow,
priv->smu_tables.entry[table_id].table_addr_low) == 0,
"[CopyTableToSMC] Attempt to Set Dram Addr Low Failed!",
return -EINVAL;);
PP_ASSERT_WITH_CODE(rv_send_msg_to_smc_with_parameter(smumgr,
PPSMC_MSG_TransferTableDram2Smu,
priv->smu_tables.entry[table_id].table_id) == 0,
"[CopyTableToSMC] Attempt to Transfer Table To SMU Failed!",
return -EINVAL;);
return 0;
}
static int rv_verify_smc_interface(struct pp_smumgr *smumgr)
{
uint32_t smc_driver_if_version;
PP_ASSERT_WITH_CODE(!rv_send_msg_to_smc(smumgr,
PPSMC_MSG_GetDriverIfVersion),
"Attempt to get SMC IF Version Number Failed!",
return -EINVAL);
PP_ASSERT_WITH_CODE(!rv_read_arg_from_smc(smumgr,
&smc_driver_if_version),
"Attempt to read SMC IF Version Number Failed!",
return -EINVAL);
if (smc_driver_if_version != SMU10_DRIVER_IF_VERSION)
return -EINVAL;
return 0;
}
static int rv_smc_enable_sdma(struct pp_smumgr *smumgr)
{
PP_ASSERT_WITH_CODE(!rv_send_msg_to_smc(smumgr,
PPSMC_MSG_PowerUpSdma),
"Attempt to power up sdma Failed!",
return -EINVAL);
return 0;
}
static int rv_smc_disable_sdma(struct pp_smumgr *smumgr)
{
PP_ASSERT_WITH_CODE(!rv_send_msg_to_smc(smumgr,
PPSMC_MSG_PowerDownSdma),
"Attempt to power down sdma Failed!",
return -EINVAL);
return 0;
}
static int rv_smc_enable_vcn(struct pp_smumgr *smumgr)
{
PP_ASSERT_WITH_CODE(!rv_send_msg_to_smc_with_parameter(smumgr,
PPSMC_MSG_PowerUpVcn, 0),
"Attempt to power up vcn Failed!",
return -EINVAL);
return 0;
}
static int rv_smc_disable_vcn(struct pp_smumgr *smumgr)
{
PP_ASSERT_WITH_CODE(!rv_send_msg_to_smc_with_parameter(smumgr,
PPSMC_MSG_PowerDownVcn, 0),
"Attempt to power down vcn Failed!",
return -EINVAL);
return 0;
}
static int rv_smu_fini(struct pp_smumgr *smumgr)
{
struct rv_smumgr *priv =
(struct rv_smumgr *)(smumgr->backend);
if (priv) {
rv_smc_disable_sdma(smumgr);
rv_smc_disable_vcn(smumgr);
cgs_free_gpu_mem(smumgr->device,
priv->smu_tables.entry[WMTABLE].handle);
cgs_free_gpu_mem(smumgr->device,
priv->smu_tables.entry[CLOCKTABLE].handle);
kfree(smumgr->backend);
smumgr->backend = NULL;
}
return 0;
}
static int rv_start_smu(struct pp_smumgr *smumgr)
{
if (rv_verify_smc_interface(smumgr))
return -EINVAL;
if (rv_smc_enable_sdma(smumgr))
return -EINVAL;
if (rv_smc_enable_vcn(smumgr))
return -EINVAL;
return 0;
}
static int rv_smu_init(struct pp_smumgr *smumgr)
{
struct rv_smumgr *priv;
uint64_t mc_addr;
void *kaddr = NULL;
unsigned long handle;
priv = kzalloc(sizeof(struct rv_smumgr), GFP_KERNEL);
if (!priv)
return -ENOMEM;
smumgr->backend = priv;
smu_allocate_memory(smumgr->device,
sizeof(Watermarks_t),
CGS_GPU_MEM_TYPE__GART_CACHEABLE,
PAGE_SIZE,
&mc_addr,
&kaddr,
&handle);
PP_ASSERT_WITH_CODE(kaddr,
"[rv_smu_init] Out of memory for wmtable.",
kfree(smumgr->backend);
smumgr->backend = NULL;
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
sizeof(DpmClocks_t),
CGS_GPU_MEM_TYPE__GART_CACHEABLE,
PAGE_SIZE,
&mc_addr,
&kaddr,
&handle);
PP_ASSERT_WITH_CODE(kaddr,
"[rv_smu_init] Out of memory for CLOCKTABLE.",
cgs_free_gpu_mem(smumgr->device,
(cgs_handle_t)priv->smu_tables.entry[WMTABLE].handle);
kfree(smumgr->backend);
smumgr->backend = NULL;
return -EINVAL);
priv->smu_tables.entry[CLOCKTABLE].version = 0x01;
priv->smu_tables.entry[CLOCKTABLE].size = sizeof(DpmClocks_t);
priv->smu_tables.entry[CLOCKTABLE].table_id = TABLE_DPMCLOCKS;
priv->smu_tables.entry[CLOCKTABLE].table_addr_high =
smu_upper_32_bits(mc_addr);
priv->smu_tables.entry[CLOCKTABLE].table_addr_low =
smu_lower_32_bits(mc_addr);
priv->smu_tables.entry[CLOCKTABLE].table = kaddr;
priv->smu_tables.entry[CLOCKTABLE].handle = handle;
return 0;
}
