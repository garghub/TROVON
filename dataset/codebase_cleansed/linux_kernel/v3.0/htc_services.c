void HTCControlTxComplete(void *Context, struct htc_packet *pPacket)
{
AR_DEBUG_ASSERT(false);
}
void HTCControlRecv(void *Context, struct htc_packet *pPacket)
{
AR_DEBUG_ASSERT(pPacket->Endpoint == ENDPOINT_0);
if (pPacket->Status == A_ECANCELED) {
HTC_FREE_CONTROL_RX((struct htc_target*)Context,pPacket);
return;
}
if (pPacket->ActualLength > 0) {
AR_DEBUG_PRINTF(ATH_DEBUG_ERR,
("HTCControlRecv, got message with length:%d \n",
pPacket->ActualLength + (u32)HTC_HDR_LENGTH));
#ifdef ATH_DEBUG_MODULE
DebugDumpBytes(pPacket->pBuffer - HTC_HDR_LENGTH,
pPacket->ActualLength + HTC_HDR_LENGTH,
"Unexpected ENDPOINT 0 Message");
#endif
}
HTC_RECYCLE_RX_PKT((struct htc_target*)Context,pPacket,&((struct htc_target*)Context)->EndPoint[0]);
}
int HTCSendSetupComplete(struct htc_target *target)
{
struct htc_packet *pSendPacket = NULL;
int status;
do {
pSendPacket = HTC_ALLOC_CONTROL_TX(target);
if (NULL == pSendPacket) {
status = A_NO_MEMORY;
break;
}
if (target->HTCTargetVersion >= HTC_VERSION_2P1) {
HTC_SETUP_COMPLETE_EX_MSG *pSetupCompleteEx;
u32 setupFlags = 0;
pSetupCompleteEx = (HTC_SETUP_COMPLETE_EX_MSG *)pSendPacket->pBuffer;
A_MEMZERO(pSetupCompleteEx, sizeof(HTC_SETUP_COMPLETE_EX_MSG));
pSetupCompleteEx->MessageID = HTC_MSG_SETUP_COMPLETE_EX_ID;
if (target->MaxMsgPerBundle > 0) {
setupFlags |= HTC_SETUP_COMPLETE_FLAGS_ENABLE_BUNDLE_RECV;
pSetupCompleteEx->MaxMsgsPerBundledRecv = target->MaxMsgPerBundle;
}
memcpy(&pSetupCompleteEx->SetupFlags, &setupFlags, sizeof(pSetupCompleteEx->SetupFlags));
SET_HTC_PACKET_INFO_TX(pSendPacket,
NULL,
(u8 *)pSetupCompleteEx,
sizeof(HTC_SETUP_COMPLETE_EX_MSG),
ENDPOINT_0,
HTC_SERVICE_TX_PACKET_TAG);
} else {
HTC_SETUP_COMPLETE_MSG *pSetupComplete;
pSetupComplete = (HTC_SETUP_COMPLETE_MSG *)pSendPacket->pBuffer;
A_MEMZERO(pSetupComplete, sizeof(HTC_SETUP_COMPLETE_MSG));
pSetupComplete->MessageID = HTC_MSG_SETUP_COMPLETE_ID;
SET_HTC_PACKET_INFO_TX(pSendPacket,
NULL,
(u8 *)pSetupComplete,
sizeof(HTC_SETUP_COMPLETE_MSG),
ENDPOINT_0,
HTC_SERVICE_TX_PACKET_TAG);
}
pSendPacket->Completion = NULL;
HTC_PREPARE_SEND_PKT(pSendPacket,0,0,0);
status = HTCIssueSend(target,pSendPacket);
} while (false);
if (pSendPacket != NULL) {
HTC_FREE_CONTROL_TX(target,pSendPacket);
}
return status;
}
int HTCConnectService(HTC_HANDLE HTCHandle,
struct htc_service_connect_req *pConnectReq,
struct htc_service_connect_resp *pConnectResp)
{
struct htc_target *target = GET_HTC_TARGET_FROM_HANDLE(HTCHandle);
int status = 0;
struct htc_packet *pRecvPacket = NULL;
struct htc_packet *pSendPacket = NULL;
HTC_CONNECT_SERVICE_RESPONSE_MSG *pResponseMsg;
HTC_CONNECT_SERVICE_MSG *pConnectMsg;
HTC_ENDPOINT_ID assignedEndpoint = ENDPOINT_MAX;
struct htc_endpoint *pEndpoint;
unsigned int maxMsgSize = 0;
AR_DEBUG_PRINTF(ATH_DEBUG_TRC, ("+HTCConnectService, target:0x%lX SvcID:0x%X \n",
(unsigned long)target, pConnectReq->ServiceID));
do {
AR_DEBUG_ASSERT(pConnectReq->ServiceID != 0);
if (HTC_CTRL_RSVD_SVC == pConnectReq->ServiceID) {
assignedEndpoint = ENDPOINT_0;
maxMsgSize = HTC_MAX_CONTROL_MESSAGE_LENGTH;
} else {
pSendPacket = HTC_ALLOC_CONTROL_TX(target);
if (NULL == pSendPacket) {
AR_DEBUG_ASSERT(false);
status = A_NO_MEMORY;
break;
}
pConnectMsg = (HTC_CONNECT_SERVICE_MSG *)pSendPacket->pBuffer;
AR_DEBUG_ASSERT(pConnectMsg != NULL);
A_MEMZERO(pConnectMsg,sizeof(HTC_CONNECT_SERVICE_MSG));
pConnectMsg->MessageID = HTC_MSG_CONNECT_SERVICE_ID;
pConnectMsg->ServiceID = pConnectReq->ServiceID;
pConnectMsg->ConnectionFlags = pConnectReq->ConnectionFlags;
if ((pConnectReq->pMetaData != NULL) &&
(pConnectReq->MetaDataLength <= HTC_SERVICE_META_DATA_MAX_LENGTH)) {
memcpy((u8 *)pConnectMsg + sizeof(HTC_CONNECT_SERVICE_MSG),
pConnectReq->pMetaData,
pConnectReq->MetaDataLength);
pConnectMsg->ServiceMetaLength = pConnectReq->MetaDataLength;
}
SET_HTC_PACKET_INFO_TX(pSendPacket,
NULL,
(u8 *)pConnectMsg,
sizeof(HTC_CONNECT_SERVICE_MSG) + pConnectMsg->ServiceMetaLength,
ENDPOINT_0,
HTC_SERVICE_TX_PACKET_TAG);
pSendPacket->Completion = NULL;
HTC_PREPARE_SEND_PKT(pSendPacket,0,0,0);
status = HTCIssueSend(target,pSendPacket);
if (status) {
break;
}
status = HTCWaitforControlMessage(target, &pRecvPacket);
if (status) {
break;
}
pResponseMsg = (HTC_CONNECT_SERVICE_RESPONSE_MSG *)pRecvPacket->pBuffer;
if ((pResponseMsg->MessageID != HTC_MSG_CONNECT_SERVICE_RESPONSE_ID) ||
(pRecvPacket->ActualLength < sizeof(HTC_CONNECT_SERVICE_RESPONSE_MSG))) {
AR_DEBUG_ASSERT(false);
status = A_EPROTO;
break;
}
pConnectResp->ConnectRespCode = pResponseMsg->Status;
if (pResponseMsg->Status != HTC_SERVICE_SUCCESS) {
AR_DEBUG_PRINTF(ATH_DEBUG_ERR,
(" Target failed service 0x%X connect request (status:%d)\n",
pResponseMsg->ServiceID, pResponseMsg->Status));
status = A_EPROTO;
break;
}
assignedEndpoint = (HTC_ENDPOINT_ID) pResponseMsg->EndpointID;
maxMsgSize = pResponseMsg->MaxMsgSize;
if ((pConnectResp->pMetaData != NULL) &&
(pResponseMsg->ServiceMetaLength > 0) &&
(pResponseMsg->ServiceMetaLength <= HTC_SERVICE_META_DATA_MAX_LENGTH)) {
int copyLength = min((int)pConnectResp->BufferLength, (int)pResponseMsg->ServiceMetaLength);
memcpy(pConnectResp->pMetaData,
((u8 *)pResponseMsg) + sizeof(HTC_CONNECT_SERVICE_RESPONSE_MSG),
copyLength);
pConnectResp->ActualLength = copyLength;
}
}
status = A_EPROTO;
if (assignedEndpoint >= ENDPOINT_MAX) {
AR_DEBUG_ASSERT(false);
break;
}
if (0 == maxMsgSize) {
AR_DEBUG_ASSERT(false);
break;
}
pEndpoint = &target->EndPoint[assignedEndpoint];
pEndpoint->Id = assignedEndpoint;
if (pEndpoint->ServiceID != 0) {
AR_DEBUG_ASSERT(false);
break;
}
pConnectResp->Endpoint = assignedEndpoint;
pConnectResp->MaxMsgLength = maxMsgSize;
pEndpoint->ServiceID = pConnectReq->ServiceID;
pEndpoint->MaxTxQueueDepth = pConnectReq->MaxSendQueueDepth;
pEndpoint->MaxMsgLength = maxMsgSize;
pEndpoint->EpCallBacks = pConnectReq->EpCallbacks;
pEndpoint->CreditDist.ServiceID = pConnectReq->ServiceID;
pEndpoint->CreditDist.pHTCReserved = pEndpoint;
pEndpoint->CreditDist.Endpoint = assignedEndpoint;
pEndpoint->CreditDist.TxCreditSize = target->TargetCreditSize;
if (pConnectReq->MaxSendMsgSize != 0) {
if (pConnectReq->MaxSendMsgSize > maxMsgSize) {
AR_DEBUG_ASSERT(false);
break;
}
pEndpoint->CreditDist.TxCreditsPerMaxMsg = pConnectReq->MaxSendMsgSize / target->TargetCreditSize;
} else {
pEndpoint->CreditDist.TxCreditsPerMaxMsg = maxMsgSize / target->TargetCreditSize;
}
if (0 == pEndpoint->CreditDist.TxCreditsPerMaxMsg) {
pEndpoint->CreditDist.TxCreditsPerMaxMsg = 1;
}
pEndpoint->LocalConnectionFlags = pConnectReq->LocalConnectionFlags;
status = 0;
} while (false);
if (pSendPacket != NULL) {
HTC_FREE_CONTROL_TX(target,pSendPacket);
}
if (pRecvPacket != NULL) {
HTC_FREE_CONTROL_RX(target,pRecvPacket);
}
AR_DEBUG_PRINTF(ATH_DEBUG_TRC, ("-HTCConnectService \n"));
return status;
}
static void AddToEndpointDistList(struct htc_target *target, struct htc_endpoint_credit_dist *pEpDist)
{
struct htc_endpoint_credit_dist *pCurEntry,*pLastEntry;
if (NULL == target->EpCreditDistributionListHead) {
target->EpCreditDistributionListHead = pEpDist;
pEpDist->pNext = NULL;
pEpDist->pPrev = NULL;
return;
}
pCurEntry = target->EpCreditDistributionListHead;
while (pCurEntry) {
pLastEntry = pCurEntry;
pCurEntry = pCurEntry->pNext;
}
pLastEntry->pNext = pEpDist;
pEpDist->pPrev = pLastEntry;
pEpDist->pNext = NULL;
}
static void HTCDefaultCreditInit(void *Context,
struct htc_endpoint_credit_dist *pEPList,
int TotalCredits)
{
struct htc_endpoint_credit_dist *pCurEpDist;
int totalEps = 0;
int creditsPerEndpoint;
pCurEpDist = pEPList;
while (pCurEpDist != NULL) {
pCurEpDist = pCurEpDist->pNext;
totalEps++;
}
creditsPerEndpoint = TotalCredits/totalEps;
pCurEpDist = pEPList;
while (pCurEpDist != NULL) {
if (creditsPerEndpoint < pCurEpDist->TxCreditsPerMaxMsg) {
AR_DEBUG_ASSERT(false);
break;
}
pCurEpDist->TxCreditsMin = pCurEpDist->TxCreditsPerMaxMsg;
pCurEpDist->TxCreditsNorm = 0xFFFF;
pCurEpDist->TxCredits = creditsPerEndpoint;
pCurEpDist->TxCreditsAssigned = creditsPerEndpoint;
pCurEpDist = pCurEpDist->pNext;
}
}
void HTCDefaultCreditDist(void *Context,
struct htc_endpoint_credit_dist *pEPDistList,
HTC_CREDIT_DIST_REASON Reason)
{
struct htc_endpoint_credit_dist *pCurEpDist;
if (Reason == HTC_CREDIT_DIST_SEND_COMPLETE) {
pCurEpDist = pEPDistList;
while (pCurEpDist != NULL) {
if (pCurEpDist->TxCreditsToDist > 0) {
pCurEpDist->TxCredits += pCurEpDist->TxCreditsToDist;
pCurEpDist->TxCreditsToDist = 0;
}
pCurEpDist = pCurEpDist->pNext;
}
}
}
void HTCSetCreditDistribution(HTC_HANDLE HTCHandle,
void *pCreditDistContext,
HTC_CREDIT_DIST_CALLBACK CreditDistFunc,
HTC_CREDIT_INIT_CALLBACK CreditInitFunc,
HTC_SERVICE_ID ServicePriorityOrder[],
int ListLength)
{
struct htc_target *target = GET_HTC_TARGET_FROM_HANDLE(HTCHandle);
int i;
int ep;
if (CreditInitFunc != NULL) {
target->InitCredits = CreditInitFunc;
AR_DEBUG_ASSERT(CreditDistFunc != NULL);
target->DistributeCredits = CreditDistFunc;
target->pCredDistContext = pCreditDistContext;
} else {
AR_DEBUG_ASSERT(CreditDistFunc == NULL);
target->InitCredits = HTCDefaultCreditInit;
target->DistributeCredits = HTCDefaultCreditDist;
target->pCredDistContext = target;
}
AddToEndpointDistList(target, &target->EndPoint[ENDPOINT_0].CreditDist);
for (i = 0; i < ListLength; i++) {
for (ep = ENDPOINT_1; ep < ENDPOINT_MAX; ep++) {
if (target->EndPoint[ep].ServiceID == ServicePriorityOrder[i]) {
AddToEndpointDistList(target, &target->EndPoint[ep].CreditDist);
break;
}
}
AR_DEBUG_ASSERT(ep < ENDPOINT_MAX);
}
}
