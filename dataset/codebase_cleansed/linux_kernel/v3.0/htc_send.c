static void DoSendCompletion(struct htc_endpoint *pEndpoint,
struct htc_packet_queue *pQueueToIndicate)
{
do {
if (HTC_QUEUE_EMPTY(pQueueToIndicate)) {
break;
}
if (pEndpoint->EpCallBacks.EpTxCompleteMultiple != NULL) {
AR_DEBUG_PRINTF(ATH_DEBUG_SEND, (" HTC calling ep %d, send complete multiple callback (%d pkts) \n",
pEndpoint->Id, HTC_PACKET_QUEUE_DEPTH(pQueueToIndicate)));
pEndpoint->EpCallBacks.EpTxCompleteMultiple(pEndpoint->EpCallBacks.pContext,
pQueueToIndicate);
INIT_HTC_PACKET_QUEUE(pQueueToIndicate);
} else {
struct htc_packet *pPacket;
do {
pPacket = HTC_PACKET_DEQUEUE(pQueueToIndicate);
AR_DEBUG_PRINTF(ATH_DEBUG_SEND, (" HTC calling ep %d send complete callback on packet 0x%lX \n", \
pEndpoint->Id, (unsigned long)(pPacket)));
pEndpoint->EpCallBacks.EpTxComplete(pEndpoint->EpCallBacks.pContext, pPacket);
} while (!HTC_QUEUE_EMPTY(pQueueToIndicate));
}
} while (false);
}
static INLINE void CompleteSentPacket(struct htc_target *target, struct htc_endpoint *pEndpoint, struct htc_packet *pPacket)
{
pPacket->Completion = NULL;
if (pPacket->Status) {
AR_DEBUG_PRINTF(ATH_DEBUG_ERR,
("CompleteSentPacket: request failed (status:%d, ep:%d, length:%d creds:%d) \n",
pPacket->Status, pPacket->Endpoint, pPacket->ActualLength, pPacket->PktInfo.AsTx.CreditsUsed));
LOCK_HTC_TX(target);
pEndpoint->CreditDist.TxCreditsToDist += pPacket->PktInfo.AsTx.CreditsUsed;
pEndpoint->CreditDist.TxQueueDepth = HTC_PACKET_QUEUE_DEPTH(&pEndpoint->TxQueue);
DO_DISTRIBUTION(target,
HTC_CREDIT_DIST_SEND_COMPLETE,
"Send Complete",
target->EpCreditDistributionListHead->pNext);
UNLOCK_HTC_TX(target);
}
pPacket->pBuffer += HTC_HDR_LENGTH;
}
static void HTCSendPktCompletionHandler(void *Context, struct htc_packet *pPacket)
{
struct htc_target *target = (struct htc_target *)Context;
struct htc_endpoint *pEndpoint = &target->EndPoint[pPacket->Endpoint];
struct htc_packet_queue container;
CompleteSentPacket(target,pEndpoint,pPacket);
INIT_HTC_PACKET_QUEUE_AND_ADD(&container,pPacket);
DO_EP_TX_COMPLETION(pEndpoint,&container);
}
int HTCIssueSend(struct htc_target *target, struct htc_packet *pPacket)
{
int status;
bool sync = false;
if (pPacket->Completion == NULL) {
sync = true;
}
AR_DEBUG_PRINTF(ATH_DEBUG_SEND,
("+-HTCIssueSend: transmit length : %d (%s) \n",
pPacket->ActualLength + (u32)HTC_HDR_LENGTH,
sync ? "SYNC" : "ASYNC" ));
status = DevSendPacket(&target->Device,
pPacket,
pPacket->ActualLength + HTC_HDR_LENGTH);
if (sync) {
pPacket->pBuffer += HTC_HDR_LENGTH;
}
return status;
}
static INLINE void GetHTCSendPackets(struct htc_target *target,
struct htc_endpoint *pEndpoint,
struct htc_packet_queue *pQueue)
{
int creditsRequired;
int remainder;
u8 sendFlags;
struct htc_packet *pPacket;
unsigned int transferLength;
AR_DEBUG_PRINTF(ATH_DEBUG_SEND,("+GetHTCSendPackets \n"));
while (true) {
sendFlags = 0;
pPacket = HTC_GET_PKT_AT_HEAD(&pEndpoint->TxQueue);
if (pPacket == NULL) {
break;
}
AR_DEBUG_PRINTF(ATH_DEBUG_SEND,(" Got head packet:0x%lX , Queue Depth: %d\n",
(unsigned long)pPacket, HTC_PACKET_QUEUE_DEPTH(&pEndpoint->TxQueue)));
transferLength = DEV_CALC_SEND_PADDED_LEN(&target->Device, pPacket->ActualLength + HTC_HDR_LENGTH);
if (transferLength <= target->TargetCreditSize) {
creditsRequired = 1;
} else {
creditsRequired = transferLength / target->TargetCreditSize;
remainder = transferLength % target->TargetCreditSize;
if (remainder) {
creditsRequired++;
}
}
AR_DEBUG_PRINTF(ATH_DEBUG_SEND,(" Creds Required:%d Got:%d\n",
creditsRequired, pEndpoint->CreditDist.TxCredits));
if (pEndpoint->CreditDist.TxCredits < creditsRequired) {
if (pPacket->Endpoint == ENDPOINT_0) {
break;
}
pEndpoint->CreditDist.TxCreditsSeek =
creditsRequired - pEndpoint->CreditDist.TxCredits;
DO_DISTRIBUTION(target,
HTC_CREDIT_DIST_SEEK_CREDITS,
"Seek Credits",
&pEndpoint->CreditDist);
pEndpoint->CreditDist.TxCreditsSeek = 0;
if (pEndpoint->CreditDist.TxCredits < creditsRequired) {
AR_DEBUG_PRINTF(ATH_DEBUG_SEND,
(" Not enough credits for ep %d leaving packet in queue..\n",
pPacket->Endpoint));
break;
}
}
pEndpoint->CreditDist.TxCredits -= creditsRequired;
INC_HTC_EP_STAT(pEndpoint, TxCreditsConsummed, creditsRequired);
if (pEndpoint->CreditDist.TxCredits < pEndpoint->CreditDist.TxCreditsPerMaxMsg) {
pEndpoint->CreditDist.TxCreditsSeek =
pEndpoint->CreditDist.TxCreditsPerMaxMsg - pEndpoint->CreditDist.TxCredits;
DO_DISTRIBUTION(target,
HTC_CREDIT_DIST_SEEK_CREDITS,
"Seek Credits",
&pEndpoint->CreditDist);
pEndpoint->CreditDist.TxCreditsSeek = 0;
if (pEndpoint->CreditDist.TxCredits < pEndpoint->CreditDist.TxCreditsPerMaxMsg) {
sendFlags |= HTC_FLAGS_NEED_CREDIT_UPDATE;
INC_HTC_EP_STAT(pEndpoint, TxCreditLowIndications, 1);
AR_DEBUG_PRINTF(ATH_DEBUG_SEND,(" Host Needs Credits \n"));
}
}
pPacket = HTC_PACKET_DEQUEUE(&pEndpoint->TxQueue);
pPacket->PktInfo.AsTx.CreditsUsed = creditsRequired;
pPacket->Completion = HTCSendPktCompletionHandler;
pPacket->pContext = target;
INC_HTC_EP_STAT(pEndpoint, TxIssued, 1);
pPacket->PktInfo.AsTx.SendFlags = sendFlags;
pPacket->PktInfo.AsTx.SeqNo = pEndpoint->SeqNo;
pEndpoint->SeqNo++;
HTC_PACKET_ENQUEUE(pQueue,pPacket);
}
AR_DEBUG_PRINTF(ATH_DEBUG_SEND,("-GetHTCSendPackets \n"));
}
static void HTCAsyncSendScatterCompletion(struct hif_scatter_req *pScatterReq)
{
int i;
struct htc_packet *pPacket;
struct htc_endpoint *pEndpoint = (struct htc_endpoint *)pScatterReq->Context;
struct htc_target *target = (struct htc_target *)pEndpoint->target;
int status = 0;
struct htc_packet_queue sendCompletes;
INIT_HTC_PACKET_QUEUE(&sendCompletes);
AR_DEBUG_PRINTF(ATH_DEBUG_SEND,("+HTCAsyncSendScatterCompletion TotLen: %d Entries: %d\n",
pScatterReq->TotalLength, pScatterReq->ValidScatterEntries));
DEV_FINISH_SCATTER_OPERATION(pScatterReq);
if (pScatterReq->CompletionStatus) {
AR_DEBUG_PRINTF(ATH_DEBUG_ERR,("** Send Scatter Request Failed: %d \n",pScatterReq->CompletionStatus));
status = A_ERROR;
}
for (i = 0; i < pScatterReq->ValidScatterEntries; i++) {
pPacket = (struct htc_packet *)(pScatterReq->ScatterList[i].pCallerContexts[0]);
A_ASSERT(pPacket != NULL);
pPacket->Status = status;
CompleteSentPacket(target,pEndpoint,pPacket);
HTC_PACKET_ENQUEUE(&sendCompletes, pPacket);
}
DEV_FREE_SCATTER_REQ(&target->Device,pScatterReq);
DO_EP_TX_COMPLETION(pEndpoint,&sendCompletes);
AR_DEBUG_PRINTF(ATH_DEBUG_SEND,("-HTCAsyncSendScatterCompletion \n"));
}
static void HTCIssueSendBundle(struct htc_endpoint *pEndpoint,
struct htc_packet_queue *pQueue,
int *pBundlesSent,
int *pTotalBundlesPkts)
{
int pktsToScatter;
unsigned int scatterSpaceRemaining;
struct hif_scatter_req *pScatterReq = NULL;
int i, packetsInScatterReq;
unsigned int transferLength;
struct htc_packet *pPacket;
bool done = false;
int bundlesSent = 0;
int totalPktsInBundle = 0;
struct htc_target *target = pEndpoint->target;
int creditRemainder = 0;
int creditPad;
AR_DEBUG_PRINTF(ATH_DEBUG_SEND,("+HTCIssueSendBundle \n"));
while (!done) {
pktsToScatter = HTC_PACKET_QUEUE_DEPTH(pQueue);
pktsToScatter = min(pktsToScatter, target->MaxMsgPerBundle);
if (pktsToScatter < HTC_MIN_HTC_MSGS_TO_BUNDLE) {
break;
}
pScatterReq = DEV_ALLOC_SCATTER_REQ(&target->Device);
if (pScatterReq == NULL) {
AR_DEBUG_PRINTF(ATH_DEBUG_SEND,(" No more scatter resources \n"));
break;
}
AR_DEBUG_PRINTF(ATH_DEBUG_SEND,(" pkts to scatter: %d \n", pktsToScatter));
pScatterReq->TotalLength = 0;
pScatterReq->ValidScatterEntries = 0;
packetsInScatterReq = 0;
scatterSpaceRemaining = DEV_GET_MAX_BUNDLE_SEND_LENGTH(&target->Device);
for (i = 0; i < pktsToScatter; i++) {
pScatterReq->ScatterList[i].pCallerContexts[0] = NULL;
pPacket = HTC_GET_PKT_AT_HEAD(pQueue);
if (pPacket == NULL) {
A_ASSERT(false);
break;
}
creditPad = 0;
transferLength = DEV_CALC_SEND_PADDED_LEN(&target->Device,
pPacket->ActualLength + HTC_HDR_LENGTH);
creditRemainder = transferLength % target->TargetCreditSize;
if (creditRemainder != 0) {
if (pEndpoint->LocalConnectionFlags & HTC_LOCAL_CONN_FLAGS_ENABLE_SEND_BUNDLE_PADDING) {
if (transferLength < target->TargetCreditSize) {
creditPad = target->TargetCreditSize - transferLength;
} else {
creditPad = creditRemainder;
}
if ((creditPad > 0) && (creditPad <= 255)) {
transferLength += creditPad;
} else {
pPacket = NULL;
}
} else {
pPacket = NULL;
}
}
if (NULL == pPacket) {
done = true;
break;
}
if (scatterSpaceRemaining < transferLength) {
break;
}
scatterSpaceRemaining -= transferLength;
pPacket = HTC_PACKET_DEQUEUE(pQueue);
pScatterReq->ScatterList[i].pCallerContexts[0] = pPacket;
HTC_PREPARE_SEND_PKT(pPacket,
pPacket->PktInfo.AsTx.SendFlags | HTC_FLAGS_SEND_BUNDLE,
creditPad,
pPacket->PktInfo.AsTx.SeqNo);
pScatterReq->ScatterList[i].pBuffer = pPacket->pBuffer;
pScatterReq->ScatterList[i].Length = transferLength;
A_ASSERT(transferLength);
pScatterReq->TotalLength += transferLength;
pScatterReq->ValidScatterEntries++;
packetsInScatterReq++;
AR_DEBUG_PRINTF(ATH_DEBUG_SEND,(" %d, Adding packet : 0x%lX, len:%d (remaining space:%d) \n",
i, (unsigned long)pPacket,transferLength,scatterSpaceRemaining));
}
if (packetsInScatterReq >= HTC_MIN_HTC_MSGS_TO_BUNDLE) {
pScatterReq->CompletionRoutine = HTCAsyncSendScatterCompletion;
pScatterReq->Context = pEndpoint;
bundlesSent++;
totalPktsInBundle += packetsInScatterReq;
packetsInScatterReq = 0;
AR_DEBUG_PRINTF(ATH_DEBUG_SEND,(" Send Scatter total bytes: %d , entries: %d\n",
pScatterReq->TotalLength,pScatterReq->ValidScatterEntries));
DevSubmitScatterRequest(&target->Device, pScatterReq, DEV_SCATTER_WRITE, DEV_SCATTER_ASYNC);
pScatterReq = NULL;
continue;
}
if (pScatterReq != NULL) {
if (packetsInScatterReq > 0) {
for (i = (packetsInScatterReq - 1); i >= 0; i--) {
pPacket = (struct htc_packet *)(pScatterReq->ScatterList[i].pCallerContexts[0]);
if (pPacket != NULL) {
HTC_UNPREPARE_SEND_PKT(pPacket);
HTC_PACKET_ENQUEUE_TO_HEAD(pQueue,pPacket);
}
}
}
DEV_FREE_SCATTER_REQ(&target->Device,pScatterReq);
}
break;
}
*pBundlesSent = bundlesSent;
*pTotalBundlesPkts = totalPktsInBundle;
AR_DEBUG_PRINTF(ATH_DEBUG_SEND,("-HTCIssueSendBundle (sent:%d) \n",bundlesSent));
return;
}
static HTC_SEND_QUEUE_RESULT HTCTrySend(struct htc_target *target,
struct htc_endpoint *pEndpoint,
struct htc_packet_queue *pCallersSendQueue)
{
struct htc_packet_queue sendQueue;
struct htc_packet *pPacket;
int bundlesSent;
int pktsInBundles;
int overflow;
HTC_SEND_QUEUE_RESULT result = HTC_SEND_QUEUE_OK;
AR_DEBUG_PRINTF(ATH_DEBUG_SEND,("+HTCTrySend (Queue:0x%lX Depth:%d)\n",
(unsigned long)pCallersSendQueue,
(pCallersSendQueue == NULL) ? 0 : HTC_PACKET_QUEUE_DEPTH(pCallersSendQueue)));
INIT_HTC_PACKET_QUEUE(&sendQueue);
do {
if (NULL == pCallersSendQueue) {
break;
}
if (HTC_QUEUE_EMPTY(pCallersSendQueue)) {
result = HTC_SEND_QUEUE_DROP;
break;
}
if (HTC_PACKET_QUEUE_DEPTH(&pEndpoint->TxQueue) >= pEndpoint->MaxTxQueueDepth) {
overflow = HTC_PACKET_QUEUE_DEPTH(pCallersSendQueue);
} else {
overflow = HTC_PACKET_QUEUE_DEPTH(&pEndpoint->TxQueue);
overflow += HTC_PACKET_QUEUE_DEPTH(pCallersSendQueue);
overflow -= pEndpoint->MaxTxQueueDepth;
}
if (overflow > 0) {
AR_DEBUG_PRINTF(ATH_DEBUG_SEND,
(" Endpoint %d, TX queue will overflow :%d , Tx Depth:%d, Max:%d \n",
pEndpoint->Id, overflow, HTC_PACKET_QUEUE_DEPTH(&pEndpoint->TxQueue), pEndpoint->MaxTxQueueDepth));
}
if ((overflow <= 0) || (pEndpoint->EpCallBacks.EpSendFull == NULL)) {
HTC_PACKET_QUEUE_TRANSFER_TO_TAIL(&sendQueue, pCallersSendQueue);
} else {
int i;
int goodPkts = HTC_PACKET_QUEUE_DEPTH(pCallersSendQueue) - overflow;
A_ASSERT(goodPkts >= 0);
for (i = 0; i < goodPkts; i++) {
pPacket = HTC_PACKET_DEQUEUE(pCallersSendQueue);
A_ASSERT(pPacket != NULL);
HTC_PACKET_ENQUEUE(&sendQueue,pPacket);
}
ITERATE_OVER_LIST_ALLOW_REMOVE(&pCallersSendQueue->QueueHead, pPacket, struct htc_packet, ListLink) {
AR_DEBUG_PRINTF(ATH_DEBUG_SEND, (" Indicating overflowed TX packet: 0x%lX \n",
(unsigned long)pPacket));
if (pEndpoint->EpCallBacks.EpSendFull(pEndpoint->EpCallBacks.pContext,
pPacket) == HTC_SEND_FULL_DROP) {
INC_HTC_EP_STAT(pEndpoint, TxDropped, 1);
} else {
HTC_PACKET_REMOVE(pCallersSendQueue, pPacket);
HTC_PACKET_ENQUEUE(&sendQueue,pPacket);
}
} ITERATE_END;
if (HTC_QUEUE_EMPTY(&sendQueue)) {
result = HTC_SEND_QUEUE_DROP;
break;
}
}
} while (false);
if (result != HTC_SEND_QUEUE_OK) {
AR_DEBUG_PRINTF(ATH_DEBUG_SEND,("-HTCTrySend: \n"));
return result;
}
LOCK_HTC_TX(target);
if (!HTC_QUEUE_EMPTY(&sendQueue)) {
HTC_PACKET_QUEUE_TRANSFER_TO_TAIL(&pEndpoint->TxQueue,&sendQueue);
A_ASSERT(HTC_QUEUE_EMPTY(&sendQueue));
INIT_HTC_PACKET_QUEUE(&sendQueue);
}
pEndpoint->TxProcessCount++;
if (pEndpoint->TxProcessCount > 1) {
pEndpoint->TxProcessCount--;
UNLOCK_HTC_TX(target);
AR_DEBUG_PRINTF(ATH_DEBUG_SEND,("-HTCTrySend (busy) \n"));
return HTC_SEND_QUEUE_OK;
}
while (true) {
if (HTC_PACKET_QUEUE_DEPTH(&pEndpoint->TxQueue) == 0) {
break;
}
GetHTCSendPackets(target, pEndpoint, &sendQueue);
if (HTC_PACKET_QUEUE_DEPTH(&sendQueue) == 0) {
break;
}
UNLOCK_HTC_TX(target);
bundlesSent = 0;
pktsInBundles = 0;
while (true) {
if ((target->SendBundlingEnabled) &&
(HTC_PACKET_QUEUE_DEPTH(&sendQueue) >= HTC_MIN_HTC_MSGS_TO_BUNDLE)) {
int temp1,temp2;
HTCIssueSendBundle(pEndpoint, &sendQueue, &temp1, &temp2);
bundlesSent += temp1;
pktsInBundles += temp2;
}
pPacket = HTC_PACKET_DEQUEUE(&sendQueue);
if (NULL == pPacket) {
break;
}
HTC_PREPARE_SEND_PKT(pPacket,
pPacket->PktInfo.AsTx.SendFlags,
0,
pPacket->PktInfo.AsTx.SeqNo);
HTCIssueSend(target, pPacket);
}
LOCK_HTC_TX(target);
INC_HTC_EP_STAT(pEndpoint, TxBundles, bundlesSent);
INC_HTC_EP_STAT(pEndpoint, TxPacketsBundled, pktsInBundles);
}
pEndpoint->TxProcessCount = 0;
UNLOCK_HTC_TX(target);
AR_DEBUG_PRINTF(ATH_DEBUG_SEND,("-HTCTrySend: \n"));
return HTC_SEND_QUEUE_OK;
}
int HTCSendPktsMultiple(HTC_HANDLE HTCHandle, struct htc_packet_queue *pPktQueue)
{
struct htc_target *target = GET_HTC_TARGET_FROM_HANDLE(HTCHandle);
struct htc_endpoint *pEndpoint;
struct htc_packet *pPacket;
AR_DEBUG_PRINTF(ATH_DEBUG_SEND, ("+HTCSendPktsMultiple: Queue: 0x%lX, Pkts %d \n",
(unsigned long)pPktQueue, HTC_PACKET_QUEUE_DEPTH(pPktQueue)));
pPacket = HTC_GET_PKT_AT_HEAD(pPktQueue);
if (NULL == pPacket) {
AR_DEBUG_PRINTF(ATH_DEBUG_SEND, ("-HTCSendPktsMultiple \n"));
return A_EINVAL;
}
AR_DEBUG_ASSERT(pPacket->Endpoint < ENDPOINT_MAX);
pEndpoint = &target->EndPoint[pPacket->Endpoint];
HTCTrySend(target, pEndpoint, pPktQueue);
if (!HTC_QUEUE_EMPTY(pPktQueue)) {
HTC_PACKET_QUEUE_ITERATE_ALLOW_REMOVE(pPktQueue,pPacket) {
if (HTC_STOPPING(target)) {
pPacket->Status = A_ECANCELED;
} else {
pPacket->Status = A_NO_RESOURCE;
}
} HTC_PACKET_QUEUE_ITERATE_END;
DO_EP_TX_COMPLETION(pEndpoint,pPktQueue);
}
AR_DEBUG_PRINTF(ATH_DEBUG_SEND, ("-HTCSendPktsMultiple \n"));
return 0;
}
int HTCSendPkt(HTC_HANDLE HTCHandle, struct htc_packet *pPacket)
{
struct htc_packet_queue queue;
AR_DEBUG_PRINTF(ATH_DEBUG_SEND,
("+-HTCSendPkt: Enter endPointId: %d, buffer: 0x%lX, length: %d \n",
pPacket->Endpoint, (unsigned long)pPacket->pBuffer, pPacket->ActualLength));
INIT_HTC_PACKET_QUEUE_AND_ADD(&queue,pPacket);
return HTCSendPktsMultiple(HTCHandle, &queue);
}
static INLINE void HTCCheckEndpointTxQueues(struct htc_target *target)
{
struct htc_endpoint *pEndpoint;
struct htc_endpoint_credit_dist *pDistItem;
AR_DEBUG_PRINTF(ATH_DEBUG_SEND, ("+HTCCheckEndpointTxQueues \n"));
pDistItem = target->EpCreditDistributionListHead;
while (pDistItem != NULL) {
pEndpoint = (struct htc_endpoint *)pDistItem->pHTCReserved;
if (HTC_PACKET_QUEUE_DEPTH(&pEndpoint->TxQueue) > 0) {
AR_DEBUG_PRINTF(ATH_DEBUG_SEND, (" Ep %d has %d credits and %d Packets in TX Queue \n",
pDistItem->Endpoint, pEndpoint->CreditDist.TxCredits, HTC_PACKET_QUEUE_DEPTH(&pEndpoint->TxQueue)));
HTCTrySend(target, pEndpoint, NULL);
}
pDistItem = pDistItem->pNext;
}
AR_DEBUG_PRINTF(ATH_DEBUG_SEND, ("-HTCCheckEndpointTxQueues \n"));
}
void HTCProcessCreditRpt(struct htc_target *target, HTC_CREDIT_REPORT *pRpt, int NumEntries, HTC_ENDPOINT_ID FromEndpoint)
{
int i;
struct htc_endpoint *pEndpoint;
int totalCredits = 0;
bool doDist = false;
AR_DEBUG_PRINTF(ATH_DEBUG_SEND, ("+HTCProcessCreditRpt, Credit Report Entries:%d \n", NumEntries));
LOCK_HTC_TX(target);
for (i = 0; i < NumEntries; i++, pRpt++) {
if (pRpt->EndpointID >= ENDPOINT_MAX) {
AR_DEBUG_ASSERT(false);
break;
}
pEndpoint = &target->EndPoint[pRpt->EndpointID];
AR_DEBUG_PRINTF(ATH_DEBUG_SEND, (" Endpoint %d got %d credits \n",
pRpt->EndpointID, pRpt->Credits));
INC_HTC_EP_STAT(pEndpoint, TxCreditRpts, 1);
INC_HTC_EP_STAT(pEndpoint, TxCreditsReturned, pRpt->Credits);
if (FromEndpoint == pRpt->EndpointID) {
INC_HTC_EP_STAT(pEndpoint, TxCreditsFromRx, pRpt->Credits);
INC_HTC_EP_STAT(pEndpoint, TxCreditRptsFromRx, 1);
} else if (FromEndpoint == ENDPOINT_0) {
INC_HTC_EP_STAT(pEndpoint, TxCreditsFromEp0, pRpt->Credits);
INC_HTC_EP_STAT(pEndpoint, TxCreditRptsFromEp0, 1);
} else {
INC_HTC_EP_STAT(pEndpoint, TxCreditsFromOther, pRpt->Credits);
INC_HTC_EP_STAT(pEndpoint, TxCreditRptsFromOther, 1);
}
if (ENDPOINT_0 == pRpt->EndpointID) {
pEndpoint->CreditDist.TxCredits += pRpt->Credits;
} else {
pEndpoint->CreditDist.TxCreditsToDist += pRpt->Credits;
doDist = true;
}
pEndpoint->CreditDist.TxQueueDepth = HTC_PACKET_QUEUE_DEPTH(&pEndpoint->TxQueue);
totalCredits += pRpt->Credits;
}
AR_DEBUG_PRINTF(ATH_DEBUG_SEND, (" Report indicated %d credits to distribute \n", totalCredits));
if (doDist) {
DO_DISTRIBUTION(target,
HTC_CREDIT_DIST_SEND_COMPLETE,
"Send Complete",
target->EpCreditDistributionListHead->pNext);
}
UNLOCK_HTC_TX(target);
if (totalCredits) {
HTCCheckEndpointTxQueues(target);
}
AR_DEBUG_PRINTF(ATH_DEBUG_SEND, ("-HTCProcessCreditRpt \n"));
}
static void HTCFlushEndpointTX(struct htc_target *target, struct htc_endpoint *pEndpoint, HTC_TX_TAG Tag)
{
struct htc_packet *pPacket;
struct htc_packet_queue discardQueue;
struct htc_packet_queue container;
INIT_HTC_PACKET_QUEUE(&discardQueue);
LOCK_HTC_TX(target);
ITERATE_OVER_LIST_ALLOW_REMOVE(&pEndpoint->TxQueue.QueueHead, pPacket, struct htc_packet, ListLink) {
if ((HTC_TX_PACKET_TAG_ALL == Tag) || (Tag == pPacket->PktInfo.AsTx.Tag)) {
HTC_PACKET_REMOVE(&pEndpoint->TxQueue, pPacket);
HTC_PACKET_ENQUEUE(&discardQueue, pPacket);
}
} ITERATE_END;
UNLOCK_HTC_TX(target);
while (1) {
pPacket = HTC_PACKET_DEQUEUE(&discardQueue);
if (NULL == pPacket) {
break;
}
pPacket->Status = A_ECANCELED;
AR_DEBUG_PRINTF(ATH_DEBUG_TRC, (" Flushing TX packet:0x%lX, length:%d, ep:%d tag:0x%X \n",
(unsigned long)pPacket, pPacket->ActualLength, pPacket->Endpoint, pPacket->PktInfo.AsTx.Tag));
INIT_HTC_PACKET_QUEUE_AND_ADD(&container,pPacket);
DO_EP_TX_COMPLETION(pEndpoint,&container);
}
}
void DumpCreditDist(struct htc_endpoint_credit_dist *pEPDist)
{
AR_DEBUG_PRINTF(ATH_DEBUG_ANY, ("--- EP : %d ServiceID: 0x%X --------------\n",
pEPDist->Endpoint, pEPDist->ServiceID));
AR_DEBUG_PRINTF(ATH_DEBUG_ANY, (" this:0x%lX next:0x%lX prev:0x%lX\n",
(unsigned long)pEPDist, (unsigned long)pEPDist->pNext, (unsigned long)pEPDist->pPrev));
AR_DEBUG_PRINTF(ATH_DEBUG_ANY, (" DistFlags : 0x%X \n", pEPDist->DistFlags));
AR_DEBUG_PRINTF(ATH_DEBUG_ANY, (" TxCreditsNorm : %d \n", pEPDist->TxCreditsNorm));
AR_DEBUG_PRINTF(ATH_DEBUG_ANY, (" TxCreditsMin : %d \n", pEPDist->TxCreditsMin));
AR_DEBUG_PRINTF(ATH_DEBUG_ANY, (" TxCredits : %d \n", pEPDist->TxCredits));
AR_DEBUG_PRINTF(ATH_DEBUG_ANY, (" TxCreditsAssigned : %d \n", pEPDist->TxCreditsAssigned));
AR_DEBUG_PRINTF(ATH_DEBUG_ANY, (" TxCreditsSeek : %d \n", pEPDist->TxCreditsSeek));
AR_DEBUG_PRINTF(ATH_DEBUG_ANY, (" TxCreditSize : %d \n", pEPDist->TxCreditSize));
AR_DEBUG_PRINTF(ATH_DEBUG_ANY, (" TxCreditsPerMaxMsg : %d \n", pEPDist->TxCreditsPerMaxMsg));
AR_DEBUG_PRINTF(ATH_DEBUG_ANY, (" TxCreditsToDist : %d \n", pEPDist->TxCreditsToDist));
AR_DEBUG_PRINTF(ATH_DEBUG_ANY, (" TxQueueDepth : %d \n",
HTC_PACKET_QUEUE_DEPTH(&((struct htc_endpoint *)pEPDist->pHTCReserved)->TxQueue)));
AR_DEBUG_PRINTF(ATH_DEBUG_ANY, ("----------------------------------------------------\n"));
}
void DumpCreditDistStates(struct htc_target *target)
{
struct htc_endpoint_credit_dist *pEPList = target->EpCreditDistributionListHead;
while (pEPList != NULL) {
DumpCreditDist(pEPList);
pEPList = pEPList->pNext;
}
if (target->DistributeCredits != NULL) {
DO_DISTRIBUTION(target,
HTC_DUMP_CREDIT_STATE,
"Dump State",
NULL);
}
}
void HTCFlushSendPkts(struct htc_target *target)
{
struct htc_endpoint *pEndpoint;
int i;
if (AR_DEBUG_LVL_CHECK(ATH_DEBUG_TRC)) {
DumpCreditDistStates(target);
}
for (i = ENDPOINT_0; i < ENDPOINT_MAX; i++) {
pEndpoint = &target->EndPoint[i];
if (pEndpoint->ServiceID == 0) {
continue;
}
HTCFlushEndpointTX(target,pEndpoint,HTC_TX_PACKET_TAG_ALL);
}
}
void HTCFlushEndpoint(HTC_HANDLE HTCHandle, HTC_ENDPOINT_ID Endpoint, HTC_TX_TAG Tag)
{
struct htc_target *target = GET_HTC_TARGET_FROM_HANDLE(HTCHandle);
struct htc_endpoint *pEndpoint = &target->EndPoint[Endpoint];
if (pEndpoint->ServiceID == 0) {
AR_DEBUG_ASSERT(false);
return;
}
HTCFlushEndpointTX(target, pEndpoint, Tag);
}
void HTCIndicateActivityChange(HTC_HANDLE HTCHandle,
HTC_ENDPOINT_ID Endpoint,
bool Active)
{
struct htc_target *target = GET_HTC_TARGET_FROM_HANDLE(HTCHandle);
struct htc_endpoint *pEndpoint = &target->EndPoint[Endpoint];
bool doDist = false;
if (pEndpoint->ServiceID == 0) {
AR_DEBUG_ASSERT(false);
return;
}
LOCK_HTC_TX(target);
if (Active) {
if (!(pEndpoint->CreditDist.DistFlags & HTC_EP_ACTIVE)) {
pEndpoint->CreditDist.DistFlags |= HTC_EP_ACTIVE;
doDist = true;
}
} else {
if (pEndpoint->CreditDist.DistFlags & HTC_EP_ACTIVE) {
pEndpoint->CreditDist.DistFlags &= ~HTC_EP_ACTIVE;
doDist = true;
}
}
if (doDist) {
pEndpoint->CreditDist.TxQueueDepth = HTC_PACKET_QUEUE_DEPTH(&pEndpoint->TxQueue);
DO_DISTRIBUTION(target,
HTC_CREDIT_DIST_ACTIVITY_CHANGE,
"Activity Change",
target->EpCreditDistributionListHead->pNext);
}
UNLOCK_HTC_TX(target);
if (doDist && !Active) {
HTCCheckEndpointTxQueues(target);
}
}
bool HTCIsEndpointActive(HTC_HANDLE HTCHandle,
HTC_ENDPOINT_ID Endpoint)
{
struct htc_target *target = GET_HTC_TARGET_FROM_HANDLE(HTCHandle);
struct htc_endpoint *pEndpoint = &target->EndPoint[Endpoint];
if (pEndpoint->ServiceID == 0) {
return false;
}
if (pEndpoint->CreditDist.DistFlags & HTC_EP_ACTIVE) {
return true;
}
return false;
}
