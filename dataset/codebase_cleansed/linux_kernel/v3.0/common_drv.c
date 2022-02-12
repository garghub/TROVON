int ar6000_SetAddressWindowRegister(struct hif_device *hifDevice, u32 RegisterAddr, u32 Address)
{
int status;
u8 addrValue[4];
s32 i;
for (i = 1; i <= 3; i++) {
addrValue[0] = ((u8 *)&Address)[i];
addrValue[1] = addrValue[0];
addrValue[2] = addrValue[0];
addrValue[3] = addrValue[0];
status = HIFReadWrite(hifDevice,
RegisterAddr+i,
addrValue,
4,
HIF_WR_SYNC_BYTE_FIX,
NULL);
if (status) {
break;
}
}
if (status) {
AR_DEBUG_PRINTF(ATH_LOG_ERR, ("Cannot write initial bytes of 0x%x to window reg: 0x%X \n",
Address, RegisterAddr));
return status;
}
status = HIFReadWrite(hifDevice,
RegisterAddr,
(u8 *)(&Address),
4,
HIF_WR_SYNC_BYTE_INC,
NULL);
if (status) {
AR_DEBUG_PRINTF(ATH_LOG_ERR, ("Cannot write 0x%x to window reg: 0x%X \n",
Address, RegisterAddr));
return status;
}
return 0;
}
int ar6000_SetAddressWindowRegister(struct hif_device *hifDevice, u32 RegisterAddr, u32 Address)
{
int status;
status = HIFReadWrite(hifDevice,
RegisterAddr+1,
((u8 *)(&Address))+1,
sizeof(u32)-1,
HIF_WR_SYNC_BYTE_INC,
NULL);
if (status) {
AR_DEBUG_PRINTF(ATH_LOG_ERR, ("Cannot write initial bytes of 0x%x to window reg: 0x%X \n",
RegisterAddr, Address));
return status;
}
status = HIFReadWrite(hifDevice,
RegisterAddr,
(u8 *)(&Address),
sizeof(u8),
HIF_WR_SYNC_BYTE_INC,
NULL);
if (status) {
AR_DEBUG_PRINTF(ATH_LOG_ERR, ("Cannot write 0x%x to window reg: 0x%X \n",
RegisterAddr, Address));
return status;
}
return 0;
}
int
ar6000_ReadRegDiag(struct hif_device *hifDevice, u32 *address, u32 *data)
{
int status;
status = ar6000_SetAddressWindowRegister(hifDevice,
WINDOW_READ_ADDR_ADDRESS,
*address);
if (status) {
return status;
}
status = HIFReadWrite(hifDevice,
WINDOW_DATA_ADDRESS,
(u8 *)data,
sizeof(u32),
HIF_RD_SYNC_BYTE_INC,
NULL);
if (status) {
AR_DEBUG_PRINTF(ATH_LOG_ERR, ("Cannot read from WINDOW_DATA_ADDRESS\n"));
return status;
}
return status;
}
int
ar6000_WriteRegDiag(struct hif_device *hifDevice, u32 *address, u32 *data)
{
int status;
status = HIFReadWrite(hifDevice,
WINDOW_DATA_ADDRESS,
(u8 *)data,
sizeof(u32),
HIF_WR_SYNC_BYTE_INC,
NULL);
if (status) {
AR_DEBUG_PRINTF(ATH_LOG_ERR, ("Cannot write 0x%x to WINDOW_DATA_ADDRESS\n", *data));
return status;
}
return ar6000_SetAddressWindowRegister(hifDevice,
WINDOW_WRITE_ADDR_ADDRESS,
*address);
}
int
ar6000_ReadDataDiag(struct hif_device *hifDevice, u32 address,
u8 *data, u32 length)
{
u32 count;
int status = 0;
for (count = 0; count < length; count += 4, address += 4) {
if ((status = ar6000_ReadRegDiag(hifDevice, &address,
(u32 *)&data[count])) != 0)
{
break;
}
}
return status;
}
int
ar6000_WriteDataDiag(struct hif_device *hifDevice, u32 address,
u8 *data, u32 length)
{
u32 count;
int status = 0;
for (count = 0; count < length; count += 4, address += 4) {
if ((status = ar6000_WriteRegDiag(hifDevice, &address,
(u32 *)&data[count])) != 0)
{
break;
}
}
return status;
}
int
ar6k_ReadTargetRegister(struct hif_device *hifDevice, int regsel, u32 *regval)
{
int status;
u8 vals[4];
u8 register_selection[4];
register_selection[0] = register_selection[1] = register_selection[2] = register_selection[3] = (regsel & 0xff);
status = HIFReadWrite(hifDevice,
CPU_DBG_SEL_ADDRESS,
register_selection,
4,
HIF_WR_SYNC_BYTE_FIX,
NULL);
if (status) {
AR_DEBUG_PRINTF(ATH_LOG_ERR, ("Cannot write CPU_DBG_SEL (%d)\n", regsel));
return status;
}
status = HIFReadWrite(hifDevice,
CPU_DBG_ADDRESS,
(u8 *)vals,
sizeof(vals),
HIF_RD_SYNC_BYTE_INC,
NULL);
if (status) {
AR_DEBUG_PRINTF(ATH_LOG_ERR, ("Cannot read from CPU_DBG_ADDRESS\n"));
return status;
}
*regval = vals[0]<<0 | vals[1]<<8 | vals[2]<<16 | vals[3]<<24;
return status;
}
void
ar6k_FetchTargetRegs(struct hif_device *hifDevice, u32 *targregs)
{
int i;
u32 val;
for (i=0; i<AR6003_FETCH_TARG_REGS_COUNT; i++) {
val=0xffffffff;
(void)ar6k_ReadTargetRegister(hifDevice, i, &val);
targregs[i] = val;
}
}
int ar6000_reset_device(struct hif_device *hifDevice, u32 TargetType, bool waitForCompletion, bool coldReset)
{
int status = 0;
u32 address;
u32 data;
do {
if (coldReset) {
data = RESET_CONTROL_COLD_RST_MASK;
}
else {
data = RESET_CONTROL_MBOX_RST_MASK;
}
if (TargetType == TARGET_TYPE_AR6002) {
address = AR6002_RESET_CONTROL_ADDRESS;
} else if (TargetType == TARGET_TYPE_AR6003) {
address = AR6003_RESET_CONTROL_ADDRESS;
} else {
A_ASSERT(0);
}
status = ar6000_WriteRegDiag(hifDevice, &address, &data);
if (status) {
break;
}
if (!waitForCompletion) {
break;
}
#if 0
(void)_delay_until_target_alive(hifDevice, 2000, TargetType);
if (TargetType == TARGET_TYPE_AR6002) {
address = 0x000040C0;
} else if (TargetType == TARGET_TYPE_AR6003) {
address = 0x000040C0;
} else {
A_ASSERT(0);
}
data = 0;
status = ar6000_ReadRegDiag(hifDevice, &address, &data);
if (status) {
break;
}
AR_DEBUG_PRINTF(ATH_LOG_ERR, ("Reset Cause readback: 0x%X \n",data));
data &= RESET_CAUSE_LAST_MASK;
if (data != 2) {
AR_DEBUG_PRINTF(ATH_LOG_ERR, ("Unable to cold reset the target \n"));
}
#endif
} while (false);
if (status) {
AR_DEBUG_PRINTF(ATH_LOG_ERR, ("Failed to reset target \n"));
}
return 0;
}
void
ar6000_copy_cust_data_from_target(struct hif_device *hifDevice, u32 TargetType)
{
u32 eepHeaderAddr;
u8 AR6003CustDataShadow[AR6003_CUST_DATA_SIZE+4];
s32 i;
if (BMIReadMemory(hifDevice,
HOST_INTEREST_ITEM_ADDRESS(TargetType, hi_board_data),
(u8 *)&eepHeaderAddr,
4)!= 0)
{
AR_DEBUG_PRINTF(ATH_DEBUG_ERR, ("BMIReadMemory for reading board data address failed \n"));
return;
}
if (TargetType == TARGET_TYPE_AR6003) {
eepHeaderAddr += 36;
for (i=0; i<AR6003_CUST_DATA_SIZE+4; i+=4){
if (BMIReadSOCRegister(hifDevice, eepHeaderAddr, (u32 *)&AR6003CustDataShadow[i])!= 0) {
AR_DEBUG_PRINTF(ATH_DEBUG_ERR, ("BMIReadSOCRegister () failed \n"));
return ;
}
eepHeaderAddr +=4;
}
memcpy(custDataAR6003, AR6003CustDataShadow+1, AR6003_CUST_DATA_SIZE);
}
if (TargetType == TARGET_TYPE_AR6002) {
eepHeaderAddr += 64;
for (i=0; i<AR6002_CUST_DATA_SIZE; i+=4){
if (BMIReadSOCRegister(hifDevice, eepHeaderAddr, (u32 *)&custDataAR6002[i])!= 0) {
AR_DEBUG_PRINTF(ATH_DEBUG_ERR, ("BMIReadSOCRegister () failed \n"));
return ;
}
eepHeaderAddr +=4;
}
}
return;
}
u8 *ar6000_get_cust_data_buffer(u32 TargetType)
{
if (TargetType == TARGET_TYPE_AR6003)
return custDataAR6003;
if (TargetType == TARGET_TYPE_AR6002)
return custDataAR6002;
return NULL;
}
void ar6000_dump_target_assert_info(struct hif_device *hifDevice, u32 TargetType)
{
u32 address;
u32 regDumpArea = 0;
int status;
u32 regDumpValues[REGISTER_DUMP_LEN_MAX];
u32 regDumpCount = 0;
u32 i;
do {
address = HOST_INTEREST_ITEM_ADDRESS(TargetType, hi_failure_state);
address = TARG_VTOP(TargetType, address);
if (TargetType == TARGET_TYPE_AR6002) {
regDumpCount = REG_DUMP_COUNT_AR6002;
} else if (TargetType == TARGET_TYPE_AR6003) {
regDumpCount = REG_DUMP_COUNT_AR6003;
} else {
A_ASSERT(0);
}
status = ar6000_ReadRegDiag(hifDevice, &address, &regDumpArea);
if (status) {
AR_DEBUG_PRINTF(ATH_DEBUG_ERR,("AR6K: Failed to get ptr to register dump area \n"));
break;
}
AR_DEBUG_PRINTF(ATH_DEBUG_ERR,("AR6K: Location of register dump data: 0x%X \n",regDumpArea));
if (regDumpArea == 0) {
break;
}
regDumpArea = TARG_VTOP(TargetType, regDumpArea);
status = ar6000_ReadDataDiag(hifDevice,
regDumpArea,
(u8 *)&regDumpValues[0],
regDumpCount * (sizeof(u32)));
if (status) {
AR_DEBUG_PRINTF(ATH_DEBUG_ERR,("AR6K: Failed to get register dump \n"));
break;
}
AR_DEBUG_PRINTF(ATH_DEBUG_ERR,("AR6K: Register Dump: \n"));
for (i = 0; i < regDumpCount; i++) {
AR_DEBUG_PRINTF(ATH_DEBUG_ERR,(" %d : 0x%8.8X \n",i, regDumpValues[i]));
#ifdef UNDER_CE
tgtassertPrintf (ATH_DEBUG_TRC," %d: 0x%8.8X \n",i, regDumpValues[i]);
#endif
}
} while (false);
}
int ar6000_set_htc_params(struct hif_device *hifDevice,
u32 TargetType,
u32 MboxIsrYieldValue,
u8 HtcControlBuffers)
{
int status;
u32 blocksizes[HTC_MAILBOX_NUM_MAX];
do {
status = HIFConfigureDevice(hifDevice, HIF_DEVICE_GET_MBOX_BLOCK_SIZE,
blocksizes, sizeof(blocksizes));
if (status) {
AR_DEBUG_PRINTF(ATH_LOG_ERR,("Failed to get block size info from HIF layer...\n"));
break;
}
A_ASSERT((blocksizes[1] & (blocksizes[1] - 1)) == 0);
if (HtcControlBuffers != 0) {
blocksizes[1] |= ((u32)HtcControlBuffers) << 16;
}
status = BMIWriteMemory(hifDevice,
HOST_INTEREST_ITEM_ADDRESS(TargetType, hi_mbox_io_block_sz),
(u8 *)&blocksizes[1],
4);
if (status) {
AR_DEBUG_PRINTF(ATH_LOG_ERR,("BMIWriteMemory for IO block size failed \n"));
break;
}
AR_DEBUG_PRINTF(ATH_LOG_INF,("Block Size Set: %d (target address:0x%X)\n",
blocksizes[1], HOST_INTEREST_ITEM_ADDRESS(TargetType, hi_mbox_io_block_sz)));
if (MboxIsrYieldValue != 0) {
status = BMIWriteMemory(hifDevice,
HOST_INTEREST_ITEM_ADDRESS(TargetType, hi_mbox_isr_yield_limit),
(u8 *)&MboxIsrYieldValue,
4);
if (status) {
AR_DEBUG_PRINTF(ATH_LOG_ERR,("BMIWriteMemory for yield limit failed \n"));
break;
}
}
} while (false);
return status;
}
void DebugDumpBytes(u8 *buffer, u16 length, char *pDescription)
{
char stream[60];
char byteOffsetStr[10];
u32 i;
u16 offset, count, byteOffset;
A_PRINTF("<---------Dumping %d Bytes : %s ------>\n", length, pDescription);
count = 0;
offset = 0;
byteOffset = 0;
for(i = 0; i < length; i++) {
A_SPRINTF(stream + offset, "%2.2X ", buffer[i]);
count ++;
offset += 3;
if(count == 16) {
count = 0;
offset = 0;
A_SPRINTF(byteOffsetStr,"%4.4X",byteOffset);
A_PRINTF("[%s]: %s\n", byteOffsetStr, stream);
A_MEMZERO(stream, 60);
byteOffset += 16;
}
}
if(offset != 0) {
A_SPRINTF(byteOffsetStr,"%4.4X",byteOffset);
A_PRINTF("[%s]: %s\n", byteOffsetStr, stream);
}
A_PRINTF("<------------------------------------------------->\n");
}
void a_dump_module_debug_info(ATH_DEBUG_MODULE_DBG_INFO *pInfo)
{
int i;
struct ath_debug_mask_description *pDesc;
if (pInfo == NULL) {
return;
}
pDesc = pInfo->pMaskDescriptions;
A_PRINTF("========================================================\n\n");
A_PRINTF("Module Debug Info => Name : %s \n", pInfo->ModuleName);
A_PRINTF(" => Descr. : %s \n", pInfo->ModuleDescription);
A_PRINTF("\n Current mask => 0x%8.8X \n", pInfo->CurrentMask);
A_PRINTF("\n Avail. Debug Masks :\n\n");
for (i = 0; i < pInfo->MaxDescriptions; i++,pDesc++) {
A_PRINTF(" => 0x%8.8X -- %s \n", pDesc->Mask, pDesc->Description);
}
if (0 == i) {
A_PRINTF(" => * none defined * \n");
}
A_PRINTF("\n Standard Debug Masks :\n\n");
A_PRINTF(" => 0x%8.8X -- Errors \n", ATH_DEBUG_ERR);
A_PRINTF(" => 0x%8.8X -- Warnings \n", ATH_DEBUG_WARN);
A_PRINTF(" => 0x%8.8X -- Informational \n", ATH_DEBUG_INFO);
A_PRINTF(" => 0x%8.8X -- Tracing \n", ATH_DEBUG_TRC);
A_PRINTF("\n========================================================\n");
}
static ATH_DEBUG_MODULE_DBG_INFO *FindModule(char *module_name)
{
ATH_DEBUG_MODULE_DBG_INFO *pInfo = g_pModuleInfoHead;
if (!g_ModuleDebugInit) {
return NULL;
}
while (pInfo != NULL) {
if (memcmp(pInfo->ModuleName,module_name,strlen(module_name)) == 0) {
break;
}
pInfo = pInfo->pNext;
}
return pInfo;
}
void a_register_module_debug_info(ATH_DEBUG_MODULE_DBG_INFO *pInfo)
{
if (!g_ModuleDebugInit) {
return;
}
A_MUTEX_LOCK(&g_ModuleListLock);
if (!(pInfo->Flags & ATH_DEBUG_INFO_FLAGS_REGISTERED)) {
if (g_pModuleInfoHead == NULL) {
g_pModuleInfoHead = pInfo;
} else {
pInfo->pNext = g_pModuleInfoHead;
g_pModuleInfoHead = pInfo;
}
pInfo->Flags |= ATH_DEBUG_INFO_FLAGS_REGISTERED;
}
A_MUTEX_UNLOCK(&g_ModuleListLock);
}
void a_dump_module_debug_info_by_name(char *module_name)
{
ATH_DEBUG_MODULE_DBG_INFO *pInfo = g_pModuleInfoHead;
if (!g_ModuleDebugInit) {
return;
}
if (memcmp(module_name,"all",3) == 0) {
while (pInfo != NULL) {
a_dump_module_debug_info(pInfo);
pInfo = pInfo->pNext;
}
return;
}
pInfo = FindModule(module_name);
if (pInfo != NULL) {
a_dump_module_debug_info(pInfo);
}
}
int a_get_module_mask(char *module_name, u32 *pMask)
{
ATH_DEBUG_MODULE_DBG_INFO *pInfo = FindModule(module_name);
if (NULL == pInfo) {
return A_ERROR;
}
*pMask = pInfo->CurrentMask;
return 0;
}
int a_set_module_mask(char *module_name, u32 Mask)
{
ATH_DEBUG_MODULE_DBG_INFO *pInfo = FindModule(module_name);
if (NULL == pInfo) {
return A_ERROR;
}
pInfo->CurrentMask = Mask;
A_PRINTF("Module %s, new mask: 0x%8.8X \n",module_name,pInfo->CurrentMask);
return 0;
}
void a_module_debug_support_init(void)
{
if (g_ModuleDebugInit) {
return;
}
A_MUTEX_INIT(&g_ModuleListLock);
g_pModuleInfoHead = NULL;
g_ModuleDebugInit = true;
A_REGISTER_MODULE_DEBUG_INFO(misc);
}
void a_module_debug_support_cleanup(void)
{
ATH_DEBUG_MODULE_DBG_INFO *pInfo = g_pModuleInfoHead;
ATH_DEBUG_MODULE_DBG_INFO *pCur;
if (!g_ModuleDebugInit) {
return;
}
g_ModuleDebugInit = false;
A_MUTEX_LOCK(&g_ModuleListLock);
while (pInfo != NULL) {
pCur = pInfo;
pInfo = pInfo->pNext;
pCur->pNext = NULL;
pCur->Flags &= ~ATH_DEBUG_INFO_FLAGS_REGISTERED;
}
A_MUTEX_UNLOCK(&g_ModuleListLock);
A_MUTEX_DELETE(&g_ModuleListLock);
g_pModuleInfoHead = NULL;
}
int ar6000_set_hci_bridge_flags(struct hif_device *hifDevice,
u32 TargetType,
u32 Flags)
{
int status = 0;
do {
if (TargetType != TARGET_TYPE_AR6003) {
AR_DEBUG_PRINTF(ATH_DEBUG_WARN, ("Target Type:%d, does not support HCI bridging! \n",
TargetType));
break;
}
status = BMIWriteMemory(hifDevice,
HOST_INTEREST_ITEM_ADDRESS(TargetType, hi_hci_bridge_flags),
(u8 *)&Flags,
4);
} while (false);
return status;
}
