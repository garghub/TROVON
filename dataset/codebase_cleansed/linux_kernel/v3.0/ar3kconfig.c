static int SendHCICommand(struct ar3k_config_info *pConfig,
u8 *pBuffer,
int Length)
{
struct htc_packet *pPacket = NULL;
int status = 0;
do {
pPacket = (struct htc_packet *)A_MALLOC(sizeof(struct htc_packet));
if (NULL == pPacket) {
status = A_NO_MEMORY;
break;
}
A_MEMZERO(pPacket,sizeof(struct htc_packet));
SET_HTC_PACKET_INFO_TX(pPacket,
NULL,
pBuffer,
Length,
HCI_COMMAND_TYPE,
AR6K_CONTROL_PKT_TAG);
status = HCI_TransportSendPkt(pConfig->pHCIDev,pPacket,true);
} while (false);
if (pPacket != NULL) {
kfree(pPacket);
}
return status;
}
static int RecvHCIEvent(struct ar3k_config_info *pConfig,
u8 *pBuffer,
int *pLength)
{
int status = 0;
struct htc_packet *pRecvPacket = NULL;
do {
pRecvPacket = (struct htc_packet *)A_MALLOC(sizeof(struct htc_packet));
if (NULL == pRecvPacket) {
status = A_NO_MEMORY;
AR_DEBUG_PRINTF(ATH_DEBUG_ERR,("Failed to alloc HTC struct \n"));
break;
}
A_MEMZERO(pRecvPacket,sizeof(struct htc_packet));
SET_HTC_PACKET_INFO_RX_REFILL(pRecvPacket,NULL,pBuffer,*pLength,HCI_EVENT_TYPE);
status = HCI_TransportRecvHCIEventSync(pConfig->pHCIDev,
pRecvPacket,
HCI_EVENT_RESP_TIMEOUTMS);
if (status) {
break;
}
*pLength = pRecvPacket->ActualLength;
} while (false);
if (pRecvPacket != NULL) {
kfree(pRecvPacket);
}
return status;
}
int SendHCICommandWaitCommandComplete(struct ar3k_config_info *pConfig,
u8 *pHCICommand,
int CmdLength,
u8 **ppEventBuffer,
u8 **ppBufferToFree)
{
int status = 0;
u8 *pBuffer = NULL;
u8 *pTemp;
int length;
bool commandComplete = false;
u8 opCodeBytes[2];
do {
length = max(HCI_MAX_EVT_RECV_LENGTH,CmdLength);
length += pConfig->pHCIProps->HeadRoom + pConfig->pHCIProps->TailRoom;
length += pConfig->pHCIProps->IOBlockPad;
pBuffer = (u8 *)A_MALLOC(length);
if (NULL == pBuffer) {
AR_DEBUG_PRINTF(ATH_DEBUG_ERR,("AR3K Config: Failed to allocate bt buffer \n"));
status = A_NO_MEMORY;
break;
}
opCodeBytes[0] = pHCICommand[HCI_CMD_OPCODE_BYTE_LOW_OFFSET];
opCodeBytes[1] = pHCICommand[HCI_CMD_OPCODE_BYTE_HI_OFFSET];
memcpy(pBuffer + pConfig->pHCIProps->HeadRoom,pHCICommand,CmdLength);
status = SendHCICommand(pConfig,
pBuffer + pConfig->pHCIProps->HeadRoom,
CmdLength);
if (status) {
AR_DEBUG_PRINTF(ATH_DEBUG_ERR,("AR3K Config: Failed to send HCI Command (%d) \n", status));
AR_DEBUG_PRINTBUF(pHCICommand,CmdLength,"HCI Bridge Failed HCI Command");
break;
}
A_MEMZERO(pBuffer,length);
status = RecvHCIEvent(pConfig,pBuffer,&length);
if (status) {
AR_DEBUG_PRINTF(ATH_DEBUG_ERR,("AR3K Config: HCI event recv failed \n"));
AR_DEBUG_PRINTBUF(pHCICommand,CmdLength,"HCI Bridge Failed HCI Command");
break;
}
pTemp = pBuffer + pConfig->pHCIProps->HeadRoom;
if (pTemp[0] == HCI_CMD_COMPLETE_EVENT_CODE) {
if ((pTemp[HCI_EVENT_OPCODE_BYTE_LOW] == opCodeBytes[0]) &&
(pTemp[HCI_EVENT_OPCODE_BYTE_HI] == opCodeBytes[1])) {
commandComplete = true;
}
}
if (!commandComplete) {
AR_DEBUG_PRINTF(ATH_DEBUG_ERR,("AR3K Config: Unexpected HCI event : %d \n",pTemp[0]));
AR_DEBUG_PRINTBUF(pTemp,pTemp[1],"Unexpected HCI event");
status = A_ECOMM;
break;
}
if (ppEventBuffer != NULL) {
*ppEventBuffer = pTemp;
if (ppBufferToFree == NULL) {
status = A_EINVAL;
break;
}
*ppBufferToFree = pBuffer;
pBuffer = NULL;
}
} while (false);
if (pBuffer != NULL) {
kfree(pBuffer);
}
return status;
}
static int AR3KConfigureHCIBaud(struct ar3k_config_info *pConfig)
{
int status = 0;
u8 hciBaudChangeCommand[] = {0x0c,0xfc,0x2,0,0};
u16 baudVal;
u8 *pEvent = NULL;
u8 *pBufferToFree = NULL;
do {
if (pConfig->Flags & AR3K_CONFIG_FLAG_SET_AR3K_BAUD) {
baudVal = (u16)(pConfig->AR3KBaudRate / 100);
hciBaudChangeCommand[3] = (u8)baudVal;
hciBaudChangeCommand[4] = (u8)(baudVal >> 8);
status = SendHCICommandWaitCommandComplete(pConfig,
hciBaudChangeCommand,
sizeof(hciBaudChangeCommand),
&pEvent,
&pBufferToFree);
if (status) {
AR_DEBUG_PRINTF(ATH_DEBUG_ERR,("AR3K Config: Baud rate change failed! \n"));
break;
}
if (pEvent[BAUD_CHANGE_COMMAND_STATUS_OFFSET] != 0) {
AR_DEBUG_PRINTF(ATH_DEBUG_ERR,
("AR3K Config: Baud change command event status failed: %d \n",
pEvent[BAUD_CHANGE_COMMAND_STATUS_OFFSET]));
status = A_ECOMM;
break;
}
AR_DEBUG_PRINTF(ATH_DEBUG_ANY,
("AR3K Config: Baud Changed to %d \n",pConfig->AR3KBaudRate));
}
if (pConfig->Flags & AR3K_CONFIG_FLAG_AR3K_BAUD_CHANGE_DELAY) {
A_MDELAY(325);
}
if (pConfig->Flags & AR3K_CONFIG_FLAG_SET_AR6K_SCALE_STEP) {
status = HCI_TransportSetBaudRate(pConfig->pHCIDev, pConfig->AR3KBaudRate);
if (status) {
AR_DEBUG_PRINTF(ATH_DEBUG_ERR,
("AR3K Config: failed to set scale and step values: %d \n", status));
break;
}
AR_DEBUG_PRINTF(ATH_DEBUG_ANY,
("AR3K Config: Baud changed to %d for AR6K\n", pConfig->AR3KBaudRate));
}
} while (false);
if (pBufferToFree != NULL) {
kfree(pBufferToFree);
}
return status;
}
static int AR3KExitMinBoot(struct ar3k_config_info *pConfig)
{
int status;
char exitMinBootCmd[] = {0x25,0xFC,0x0c,0x03,0x00,0x00,0x00,0x00,0x00,0x00,
0x00,0x00,0x00,0x00,0x00};
u8 *pEvent = NULL;
u8 *pBufferToFree = NULL;
status = SendHCICommandWaitCommandComplete(pConfig,
exitMinBootCmd,
sizeof(exitMinBootCmd),
&pEvent,
&pBufferToFree);
if (!status) {
if (pEvent[EXIT_MIN_BOOT_COMMAND_STATUS_OFFSET] != 0) {
AR_DEBUG_PRINTF(ATH_DEBUG_ERR,
("AR3K Config: MinBoot exit command event status failed: %d \n",
pEvent[EXIT_MIN_BOOT_COMMAND_STATUS_OFFSET]));
status = A_ECOMM;
} else {
AR_DEBUG_PRINTF(ATH_DEBUG_INFO,
("AR3K Config: MinBoot Exit Command Complete (Success) \n"));
A_MDELAY(1);
}
} else {
AR_DEBUG_PRINTF(ATH_DEBUG_ERR,("AR3K Config: MinBoot Exit Failed! \n"));
}
if (pBufferToFree != NULL) {
kfree(pBufferToFree);
}
return status;
}
static int AR3KConfigureSendHCIReset(struct ar3k_config_info *pConfig)
{
int status = 0;
u8 hciResetCommand[] = {0x03,0x0c,0x0};
u8 *pEvent = NULL;
u8 *pBufferToFree = NULL;
status = SendHCICommandWaitCommandComplete( pConfig,
hciResetCommand,
sizeof(hciResetCommand),
&pEvent,
&pBufferToFree );
if (status) {
AR_DEBUG_PRINTF(ATH_DEBUG_ERR,("AR3K Config: HCI reset failed! \n"));
}
if (pBufferToFree != NULL) {
kfree(pBufferToFree);
}
return status;
}
static int AR3KEnableTLPM(struct ar3k_config_info *pConfig)
{
int status;
char hostWakeupConfig[] = {0x31,0xFC,0x18,
0x02,0x00,0x00,0x00,
0x01,0x00,0x00,0x00,
TLPM_DEFAULT_IDLE_TIMEOUT_LSB,TLPM_DEFAULT_IDLE_TIMEOUT_MSB,0x00,0x00,
0x00,0x00,0x00,0x00,
TLPM_DEFAULT_WAKEUP_TIMEOUT_MS,0x00,0x00,0x00,
0x00,0x00,0x00,0x00};
char targetWakeupConfig[] = {0x31,0xFC,0x18,
0x04,0x00,0x00,0x00,
0x01,0x00,0x00,0x00,
TLPM_DEFAULT_IDLE_TIMEOUT_LSB,TLPM_DEFAULT_IDLE_TIMEOUT_MSB,0x00,0x00,
0x00,0x00,0x00,0x00,
TLPM_DEFAULT_WAKEUP_TIMEOUT_MS,0x00,0x00,0x00,
0x00,0x00,0x00,0x00};
char hostWakeupEnable[] = {0x31,0xFC,0x4,
0x01,0x00,0x00,0x00};
char targetWakeupEnable[] = {0x31,0xFC,0x4,
0x06,0x00,0x00,0x00};
char sleepEnable[] = {0x4,0xFC,0x1,
0x1};
u8 *pEvent = NULL;
u8 *pBufferToFree = NULL;
if (0 != pConfig->IdleTimeout) {
u8 idle_lsb = pConfig->IdleTimeout & 0xFF;
u8 idle_msb = (pConfig->IdleTimeout & 0xFF00) >> 8;
hostWakeupConfig[11] = targetWakeupConfig[11] = idle_lsb;
hostWakeupConfig[12] = targetWakeupConfig[12] = idle_msb;
}
if (0 != pConfig->WakeupTimeout) {
hostWakeupConfig[19] = targetWakeupConfig[19] = (pConfig->WakeupTimeout & 0xFF);
}
status = SendHCICommandWaitCommandComplete(pConfig,
hostWakeupConfig,
sizeof(hostWakeupConfig),
&pEvent,
&pBufferToFree);
if (pBufferToFree != NULL) {
kfree(pBufferToFree);
}
if (status) {
AR_DEBUG_PRINTF(ATH_DEBUG_ERR,("HostWakeup Config Failed! \n"));
return status;
}
pEvent = NULL;
pBufferToFree = NULL;
status = SendHCICommandWaitCommandComplete(pConfig,
targetWakeupConfig,
sizeof(targetWakeupConfig),
&pEvent,
&pBufferToFree);
if (pBufferToFree != NULL) {
kfree(pBufferToFree);
}
if (status) {
AR_DEBUG_PRINTF(ATH_DEBUG_ERR,("Target Wakeup Config Failed! \n"));
return status;
}
pEvent = NULL;
pBufferToFree = NULL;
status = SendHCICommandWaitCommandComplete(pConfig,
hostWakeupEnable,
sizeof(hostWakeupEnable),
&pEvent,
&pBufferToFree);
if (pBufferToFree != NULL) {
kfree(pBufferToFree);
}
if (status) {
AR_DEBUG_PRINTF(ATH_DEBUG_ERR,("HostWakeup Enable Failed! \n"));
return status;
}
pEvent = NULL;
pBufferToFree = NULL;
status = SendHCICommandWaitCommandComplete(pConfig,
targetWakeupEnable,
sizeof(targetWakeupEnable),
&pEvent,
&pBufferToFree);
if (pBufferToFree != NULL) {
kfree(pBufferToFree);
}
if (status) {
AR_DEBUG_PRINTF(ATH_DEBUG_ERR,("Target Wakeup Enable Failed! \n"));
return status;
}
pEvent = NULL;
pBufferToFree = NULL;
status = SendHCICommandWaitCommandComplete(pConfig,
sleepEnable,
sizeof(sleepEnable),
&pEvent,
&pBufferToFree);
if (pBufferToFree != NULL) {
kfree(pBufferToFree);
}
if (status) {
AR_DEBUG_PRINTF(ATH_DEBUG_ERR,("Sleep Enable Failed! \n"));
}
AR_DEBUG_PRINTF(ATH_DEBUG_ERR,("AR3K Config: Enable TLPM Completed (status = %d) \n",status));
return status;
}
int AR3KConfigure(struct ar3k_config_info *pConfig)
{
int status = 0;
AR_DEBUG_PRINTF(ATH_DEBUG_INFO,("AR3K Config: Configuring AR3K ...\n"));
do {
if ((pConfig->pHCIDev == NULL) || (pConfig->pHCIProps == NULL) || (pConfig->pHIFDevice == NULL)) {
status = A_EINVAL;
break;
}
status = HCI_TransportEnableDisableAsyncRecv(pConfig->pHCIDev,false);
if (status) {
break;
}
if (pConfig->Flags & AR3K_CONFIG_FLAG_FORCE_MINBOOT_EXIT) {
status = AR3KExitMinBoot(pConfig);
if (status) {
break;
}
}
if (0 != AthPSInitialize(pConfig)) {
AR_DEBUG_PRINTF(ATH_DEBUG_ERR,("Patch Download Failed!\n"));
}
AR3KConfigureSendHCIReset(pConfig);
if (pConfig->Flags &
(AR3K_CONFIG_FLAG_SET_AR3K_BAUD | AR3K_CONFIG_FLAG_SET_AR6K_SCALE_STEP)) {
status = AR3KConfigureHCIBaud(pConfig);
if (status) {
break;
}
}
if (pConfig->PwrMgmtEnabled) {
A_MDELAY(200);
AR3KEnableTLPM(pConfig);
}
status = HCI_TransportEnableDisableAsyncRecv(pConfig->pHCIDev,true);
if (status) {
break;
}
} while (false);
AR_DEBUG_PRINTF(ATH_DEBUG_INFO,("AR3K Config: Configuration Complete (status = %d) \n",status));
return status;
}
int AR3KConfigureExit(void *config)
{
int status = 0;
struct ar3k_config_info *pConfig = (struct ar3k_config_info *)config;
AR_DEBUG_PRINTF(ATH_DEBUG_INFO,("AR3K Config: Cleaning up AR3K ...\n"));
do {
if ((pConfig->pHCIDev == NULL) || (pConfig->pHCIProps == NULL) || (pConfig->pHIFDevice == NULL)) {
status = A_EINVAL;
break;
}
status = HCI_TransportEnableDisableAsyncRecv(pConfig->pHCIDev,false);
if (status) {
break;
}
if (pConfig->Flags &
(AR3K_CONFIG_FLAG_SET_AR3K_BAUD | AR3K_CONFIG_FLAG_SET_AR6K_SCALE_STEP)) {
status = AR3KConfigureHCIBaud(pConfig);
if (status) {
break;
}
}
status = HCI_TransportEnableDisableAsyncRecv(pConfig->pHCIDev,true);
if (status) {
break;
}
} while (false);
AR_DEBUG_PRINTF(ATH_DEBUG_INFO,("AR3K Config: Cleanup Complete (status = %d) \n",status));
return status;
}
