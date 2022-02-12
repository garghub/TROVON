void HTCFreeControlBuffer(struct htc_target *target, struct htc_packet *pPacket, struct htc_packet_queue *pList)
{
LOCK_HTC(target);
HTC_PACKET_ENQUEUE(pList,pPacket);
UNLOCK_HTC(target);
}
struct htc_packet *HTCAllocControlBuffer(struct htc_target *target, struct htc_packet_queue *pList)
{
struct htc_packet *pPacket;
LOCK_HTC(target);
pPacket = HTC_PACKET_DEQUEUE(pList);
UNLOCK_HTC(target);
return pPacket;
}
static void HTCCleanup(struct htc_target *target)
{
s32 i;
DevCleanup(&target->Device);
for (i = 0;i < NUM_CONTROL_BUFFERS;i++) {
if (target->HTCControlBuffers[i].Buffer) {
kfree(target->HTCControlBuffers[i].Buffer);
}
}
if (A_IS_MUTEX_VALID(&target->HTCLock)) {
A_MUTEX_DELETE(&target->HTCLock);
}
if (A_IS_MUTEX_VALID(&target->HTCRxLock)) {
A_MUTEX_DELETE(&target->HTCRxLock);
}
if (A_IS_MUTEX_VALID(&target->HTCTxLock)) {
A_MUTEX_DELETE(&target->HTCTxLock);
}
kfree(target);
}
HTC_HANDLE HTCCreate(void *hif_handle, struct htc_init_info *pInfo)
{
struct htc_target *target = NULL;
int status = 0;
int i;
u32 ctrl_bufsz;
u32 blocksizes[HTC_MAILBOX_NUM_MAX];
AR_DEBUG_PRINTF(ATH_DEBUG_TRC, ("HTCCreate - Enter\n"));
A_REGISTER_MODULE_DEBUG_INFO(htc);
do {
if ((target = (struct htc_target *)A_MALLOC(sizeof(struct htc_target))) == NULL) {
AR_DEBUG_PRINTF(ATH_DEBUG_ERR, ("Unable to allocate memory\n"));
status = A_ERROR;
break;
}
A_MEMZERO(target, sizeof(struct htc_target));
A_MUTEX_INIT(&target->HTCLock);
A_MUTEX_INIT(&target->HTCRxLock);
A_MUTEX_INIT(&target->HTCTxLock);
INIT_HTC_PACKET_QUEUE(&target->ControlBufferTXFreeList);
INIT_HTC_PACKET_QUEUE(&target->ControlBufferRXFreeList);
target->Device.HIFDevice = hif_handle;
target->Device.HTCContext = target;
target->Device.TargetFailureCallback = HTCReportFailure;
target->Device.MessagePendingCallback = HTCRecvMessagePendingHandler;
target->EpWaitingForBuffers = ENDPOINT_MAX;
memcpy(&target->HTCInitInfo,pInfo,sizeof(struct htc_init_info));
ResetEndpointStates(target);
status = DevSetup(&target->Device);
if (status) {
break;
}
status = HIFConfigureDevice(hif_handle, HIF_DEVICE_GET_MBOX_BLOCK_SIZE,
blocksizes, sizeof(blocksizes));
if (status) {
AR_DEBUG_PRINTF(ATH_DEBUG_ERR,("Failed to get block size info from HIF layer...\n"));
break;
}
if (blocksizes[1] > HTC_MAX_CONTROL_MESSAGE_LENGTH) {
ctrl_bufsz = blocksizes[1] + HTC_HDR_LENGTH;
} else {
ctrl_bufsz = HTC_MAX_CONTROL_MESSAGE_LENGTH + HTC_HDR_LENGTH;
}
for (i = 0;i < NUM_CONTROL_BUFFERS;i++) {
target->HTCControlBuffers[i].Buffer = A_MALLOC(ctrl_bufsz);
if (target->HTCControlBuffers[i].Buffer == NULL) {
AR_DEBUG_PRINTF(ATH_DEBUG_ERR, ("Unable to allocate memory\n"));
status = A_ERROR;
break;
}
}
if (status) {
break;
}
for (i = 0; i < NUM_CONTROL_RX_BUFFERS; i++) {
struct htc_packet *pControlPacket;
pControlPacket = &target->HTCControlBuffers[i].HtcPacket;
SET_HTC_PACKET_INFO_RX_REFILL(pControlPacket,
target,
target->HTCControlBuffers[i].Buffer,
ctrl_bufsz,
ENDPOINT_0);
HTC_FREE_CONTROL_RX(target,pControlPacket);
}
for (;i < NUM_CONTROL_BUFFERS;i++) {
struct htc_packet *pControlPacket;
pControlPacket = &target->HTCControlBuffers[i].HtcPacket;
INIT_HTC_PACKET_INFO(pControlPacket,
target->HTCControlBuffers[i].Buffer,
ctrl_bufsz);
HTC_FREE_CONTROL_TX(target,pControlPacket);
}
} while (false);
if (status) {
if (target != NULL) {
HTCCleanup(target);
target = NULL;
}
}
AR_DEBUG_PRINTF(ATH_DEBUG_TRC, ("HTCCreate - Exit\n"));
return target;
}
void HTCDestroy(HTC_HANDLE HTCHandle)
{
struct htc_target *target = GET_HTC_TARGET_FROM_HANDLE(HTCHandle);
AR_DEBUG_PRINTF(ATH_DEBUG_TRC, ("+HTCDestroy .. Destroying :0x%lX \n",(unsigned long)target));
HTCCleanup(target);
AR_DEBUG_PRINTF(ATH_DEBUG_TRC, ("-HTCDestroy \n"));
}
void *HTCGetHifDevice(HTC_HANDLE HTCHandle)
{
struct htc_target *target = GET_HTC_TARGET_FROM_HANDLE(HTCHandle);
return target->Device.HIFDevice;
}
int HTCWaitTarget(HTC_HANDLE HTCHandle)
{
struct htc_target *target = GET_HTC_TARGET_FROM_HANDLE(HTCHandle);
int status;
struct htc_packet *pPacket = NULL;
HTC_READY_EX_MSG *pRdyMsg;
struct htc_service_connect_req connect;
struct htc_service_connect_resp resp;
AR_DEBUG_PRINTF(ATH_DEBUG_TRC, ("HTCWaitTarget - Enter (target:0x%lX) \n", (unsigned long)target));
do {
#ifdef MBOXHW_UNIT_TEST
status = DoMboxHWTest(&target->Device);
if (status) {
break;
}
#endif
status = HTCWaitforControlMessage(target, &pPacket);
if (status) {
AR_DEBUG_PRINTF(ATH_DEBUG_ERR, (" Target Not Available!!\n"));
break;
}
pRdyMsg = (HTC_READY_EX_MSG *)pPacket->pBuffer;
if ((pRdyMsg->Version2_0_Info.MessageID != HTC_MSG_READY_ID) ||
(pPacket->ActualLength < sizeof(HTC_READY_MSG))) {
AR_DEBUG_ASSERT(false);
status = A_EPROTO;
break;
}
if (pRdyMsg->Version2_0_Info.CreditCount == 0 || pRdyMsg->Version2_0_Info.CreditSize == 0) {
AR_DEBUG_ASSERT(false);
status = A_EPROTO;
break;
}
target->TargetCredits = pRdyMsg->Version2_0_Info.CreditCount;
target->TargetCreditSize = pRdyMsg->Version2_0_Info.CreditSize;
AR_DEBUG_PRINTF(ATH_DEBUG_WARN, (" Target Ready: credits: %d credit size: %d\n",
target->TargetCredits, target->TargetCreditSize));
if (pPacket->ActualLength >= sizeof(HTC_READY_EX_MSG)) {
target->HTCTargetVersion = pRdyMsg->HTCVersion;
target->MaxMsgPerBundle = pRdyMsg->MaxMsgsPerHTCBundle;
} else {
target->HTCTargetVersion = HTC_VERSION_2P0;
target->MaxMsgPerBundle = 0;
}
#ifdef HTC_FORCE_LEGACY_2P0
target->HTCTargetVersion = HTC_VERSION_2P0;
target->MaxMsgPerBundle = 0;
#endif
AR_DEBUG_PRINTF(ATH_DEBUG_TRC,
("Using HTC Protocol Version : %s (%d)\n ",
(target->HTCTargetVersion == HTC_VERSION_2P0) ? "2.0" : ">= 2.1",
target->HTCTargetVersion));
if (target->MaxMsgPerBundle > 0) {
target->MaxMsgPerBundle = min(HTC_HOST_MAX_MSG_PER_BUNDLE, target->MaxMsgPerBundle);
if (DevSetupMsgBundling(&target->Device,target->MaxMsgPerBundle)) {
target->MaxMsgPerBundle = 0;
} else {
target->MaxMsgPerBundle = min(DEV_GET_MAX_MSG_PER_BUNDLE(&target->Device),
target->MaxMsgPerBundle);
}
}
if (target->MaxMsgPerBundle > 0) {
AR_DEBUG_PRINTF(ATH_DEBUG_TRC,
(" HTC bundling allowed. Max Msg Per HTC Bundle: %d\n", target->MaxMsgPerBundle));
if (DEV_GET_MAX_BUNDLE_SEND_LENGTH(&target->Device) != 0) {
target->SendBundlingEnabled = true;
}
if (DEV_GET_MAX_BUNDLE_RECV_LENGTH(&target->Device) != 0) {
target->RecvBundlingEnabled = true;
}
if (!DEV_IS_LEN_BLOCK_ALIGNED(&target->Device,target->TargetCreditSize)) {
AR_DEBUG_PRINTF(ATH_DEBUG_WARN, ("*** Credit size: %d is not block aligned! Disabling send bundling \n",
target->TargetCreditSize));
target->SendBundlingEnabled = false;
}
}
A_MEMZERO(&connect,sizeof(connect));
A_MEMZERO(&resp,sizeof(resp));
connect.EpCallbacks.pContext = target;
connect.EpCallbacks.EpTxComplete = HTCControlTxComplete;
connect.EpCallbacks.EpRecv = HTCControlRecv;
connect.EpCallbacks.EpRecvRefill = NULL;
connect.EpCallbacks.EpSendFull = NULL;
connect.MaxSendQueueDepth = NUM_CONTROL_BUFFERS;
connect.ServiceID = HTC_CTRL_RSVD_SVC;
status = HTCConnectService((HTC_HANDLE)target,
&connect,
&resp);
if (!status) {
break;
}
} while (false);
if (pPacket != NULL) {
HTC_FREE_CONTROL_RX(target,pPacket);
}
AR_DEBUG_PRINTF(ATH_DEBUG_TRC, ("HTCWaitTarget - Exit\n"));
return status;
}
int HTCStart(HTC_HANDLE HTCHandle)
{
struct htc_target *target = GET_HTC_TARGET_FROM_HANDLE(HTCHandle);
struct htc_packet *pPacket;
int status;
AR_DEBUG_PRINTF(ATH_DEBUG_TRC, ("HTCStart Enter\n"));
DevDisableInterrupts(&target->Device);
target->OpStateFlags = 0;
target->RecvStateFlags = 0;
while (1) {
pPacket = HTC_ALLOC_CONTROL_RX(target);
if (NULL == pPacket) {
break;
}
HTCAddReceivePkt((HTC_HANDLE)target,pPacket);
}
do {
AR_DEBUG_ASSERT(target->InitCredits != NULL);
AR_DEBUG_ASSERT(target->EpCreditDistributionListHead != NULL);
AR_DEBUG_ASSERT(target->EpCreditDistributionListHead->pNext != NULL);
target->InitCredits(target->pCredDistContext,
target->EpCreditDistributionListHead->pNext,
target->TargetCredits);
#ifdef ATH_DEBUG_MODULE
if (AR_DEBUG_LVL_CHECK(ATH_DEBUG_TRC)) {
DumpCreditDistStates(target);
}
#endif
status = HTCSendSetupComplete(target);
if (status) {
break;
}
status = DevUnmaskInterrupts(&target->Device);
if (status) {
HTCStop(target);
}
} while (false);
AR_DEBUG_PRINTF(ATH_DEBUG_TRC, ("HTCStart Exit\n"));
return status;
}
static void ResetEndpointStates(struct htc_target *target)
{
struct htc_endpoint *pEndpoint;
int i;
for (i = ENDPOINT_0; i < ENDPOINT_MAX; i++) {
pEndpoint = &target->EndPoint[i];
A_MEMZERO(&pEndpoint->CreditDist, sizeof(pEndpoint->CreditDist));
pEndpoint->ServiceID = 0;
pEndpoint->MaxMsgLength = 0;
pEndpoint->MaxTxQueueDepth = 0;
A_MEMZERO(&pEndpoint->EndPointStats,sizeof(pEndpoint->EndPointStats));
INIT_HTC_PACKET_QUEUE(&pEndpoint->RxBuffers);
INIT_HTC_PACKET_QUEUE(&pEndpoint->TxQueue);
INIT_HTC_PACKET_QUEUE(&pEndpoint->RecvIndicationQueue);
pEndpoint->target = target;
}
target->EpCreditDistributionListHead = NULL;
}
void HTCStop(HTC_HANDLE HTCHandle)
{
struct htc_target *target = GET_HTC_TARGET_FROM_HANDLE(HTCHandle);
AR_DEBUG_PRINTF(ATH_DEBUG_TRC, ("+HTCStop \n"));
LOCK_HTC(target);
target->OpStateFlags |= HTC_OP_STATE_STOPPING;
UNLOCK_HTC(target);
DevMaskInterrupts(&target->Device);
#ifdef THREAD_X
A_MDELAY(200);
#endif
HTCFlushSendPkts(target);
HTCFlushRecvBuffers(target);
DevCleanupMsgBundling(&target->Device);
ResetEndpointStates(target);
AR_DEBUG_PRINTF(ATH_DEBUG_TRC, ("-HTCStop \n"));
}
void HTCDumpCreditStates(HTC_HANDLE HTCHandle)
{
struct htc_target *target = GET_HTC_TARGET_FROM_HANDLE(HTCHandle);
LOCK_HTC_TX(target);
DumpCreditDistStates(target);
UNLOCK_HTC_TX(target);
DumpAR6KDevState(&target->Device);
}
static void HTCReportFailure(void *Context)
{
struct htc_target *target = (struct htc_target *)Context;
target->TargetFailure = true;
if (target->HTCInitInfo.TargetFailure != NULL) {
target->HTCInitInfo.TargetFailure(target->HTCInitInfo.pContext, A_ERROR);
}
}
bool HTCGetEndpointStatistics(HTC_HANDLE HTCHandle,
HTC_ENDPOINT_ID Endpoint,
HTC_ENDPOINT_STAT_ACTION Action,
struct htc_endpoint_stats *pStats)
{
struct htc_target *target = GET_HTC_TARGET_FROM_HANDLE(HTCHandle);
bool clearStats = false;
bool sample = false;
switch (Action) {
case HTC_EP_STAT_SAMPLE :
sample = true;
break;
case HTC_EP_STAT_SAMPLE_AND_CLEAR :
sample = true;
clearStats = true;
break;
case HTC_EP_STAT_CLEAR :
clearStats = true;
break;
default:
break;
}
A_ASSERT(Endpoint < ENDPOINT_MAX);
LOCK_HTC_TX(target);
LOCK_HTC_RX(target);
if (sample) {
A_ASSERT(pStats != NULL);
memcpy(pStats, &target->EndPoint[Endpoint].EndPointStats, sizeof(struct htc_endpoint_stats));
}
if (clearStats) {
A_MEMZERO(&target->EndPoint[Endpoint].EndPointStats, sizeof(struct htc_endpoint_stats));
}
UNLOCK_HTC_RX(target);
UNLOCK_HTC_TX(target);
return true;
}
struct ar6k_device *HTCGetAR6KDevice(void *HTCHandle)
{
struct htc_target *target = GET_HTC_TARGET_FROM_HANDLE(HTCHandle);
return &target->Device;
}
