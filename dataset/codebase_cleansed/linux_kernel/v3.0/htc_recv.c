static void DoRecvCompletion(struct htc_endpoint *pEndpoint,
struct htc_packet_queue *pQueueToIndicate)
{
do {
if (HTC_QUEUE_EMPTY(pQueueToIndicate)) {
break;
}
if (pEndpoint->EpCallBacks.EpRecvPktMultiple != NULL) {
AR_DEBUG_PRINTF(ATH_DEBUG_RECV, (" HTC calling ep %d, recv multiple callback (%d pkts) \n",
pEndpoint->Id, HTC_PACKET_QUEUE_DEPTH(pQueueToIndicate)));
pEndpoint->EpCallBacks.EpRecvPktMultiple(pEndpoint->EpCallBacks.pContext,
pQueueToIndicate);
INIT_HTC_PACKET_QUEUE(pQueueToIndicate);
} else {
struct htc_packet *pPacket;
do {
pPacket = HTC_PACKET_DEQUEUE(pQueueToIndicate);
AR_DEBUG_PRINTF(ATH_DEBUG_RECV, (" HTC calling ep %d recv callback on packet 0x%lX \n", \
pEndpoint->Id, (unsigned long)(pPacket)));
pEndpoint->EpCallBacks.EpRecv(pEndpoint->EpCallBacks.pContext, pPacket);
} while (!HTC_QUEUE_EMPTY(pQueueToIndicate));
}
} while (false);
}
static INLINE int HTCProcessTrailer(struct htc_target *target,
u8 *pBuffer,
int Length,
u32 *pNextLookAheads,
int *pNumLookAheads,
HTC_ENDPOINT_ID FromEndpoint)
{
HTC_RECORD_HDR *pRecord;
u8 *pRecordBuf;
HTC_LOOKAHEAD_REPORT *pLookAhead;
u8 *pOrigBuffer;
int origLength;
int status;
AR_DEBUG_PRINTF(ATH_DEBUG_RECV, ("+HTCProcessTrailer (length:%d) \n", Length));
if (AR_DEBUG_LVL_CHECK(ATH_DEBUG_RECV)) {
AR_DEBUG_PRINTBUF(pBuffer,Length,"Recv Trailer");
}
pOrigBuffer = pBuffer;
origLength = Length;
status = 0;
while (Length > 0) {
if (Length < sizeof(HTC_RECORD_HDR)) {
status = A_EPROTO;
break;
}
pRecord = (HTC_RECORD_HDR *)pBuffer;
Length -= sizeof(HTC_RECORD_HDR);
pBuffer += sizeof(HTC_RECORD_HDR);
if (pRecord->Length > Length) {
AR_DEBUG_PRINTF(ATH_DEBUG_ERR,
(" invalid record length: %d (id:%d) buffer has: %d bytes left \n",
pRecord->Length, pRecord->RecordID, Length));
status = A_EPROTO;
break;
}
pRecordBuf = pBuffer;
switch (pRecord->RecordID) {
case HTC_RECORD_CREDITS:
AR_DEBUG_ASSERT(pRecord->Length >= sizeof(HTC_CREDIT_REPORT));
HTCProcessCreditRpt(target,
(HTC_CREDIT_REPORT *)pRecordBuf,
pRecord->Length / (sizeof(HTC_CREDIT_REPORT)),
FromEndpoint);
break;
case HTC_RECORD_LOOKAHEAD:
AR_DEBUG_ASSERT(pRecord->Length >= sizeof(HTC_LOOKAHEAD_REPORT));
pLookAhead = (HTC_LOOKAHEAD_REPORT *)pRecordBuf;
if ((pLookAhead->PreValid == ((~pLookAhead->PostValid) & 0xFF)) &&
(pNextLookAheads != NULL)) {
AR_DEBUG_PRINTF(ATH_DEBUG_RECV,
(" LookAhead Report Found (pre valid:0x%X, post valid:0x%X) \n",
pLookAhead->PreValid,
pLookAhead->PostValid));
((u8 *)(&pNextLookAheads[0]))[0] = pLookAhead->LookAhead[0];
((u8 *)(&pNextLookAheads[0]))[1] = pLookAhead->LookAhead[1];
((u8 *)(&pNextLookAheads[0]))[2] = pLookAhead->LookAhead[2];
((u8 *)(&pNextLookAheads[0]))[3] = pLookAhead->LookAhead[3];
#ifdef ATH_DEBUG_MODULE
if (AR_DEBUG_LVL_CHECK(ATH_DEBUG_RECV)) {
DebugDumpBytes((u8 *)pNextLookAheads,4,"Next Look Ahead");
}
#endif
*pNumLookAheads = 1;
}
break;
case HTC_RECORD_LOOKAHEAD_BUNDLE:
AR_DEBUG_ASSERT(pRecord->Length >= sizeof(HTC_BUNDLED_LOOKAHEAD_REPORT));
if (pRecord->Length >= sizeof(HTC_BUNDLED_LOOKAHEAD_REPORT) &&
(pNextLookAheads != NULL)) {
HTC_BUNDLED_LOOKAHEAD_REPORT *pBundledLookAheadRpt;
int i;
pBundledLookAheadRpt = (HTC_BUNDLED_LOOKAHEAD_REPORT *)pRecordBuf;
#ifdef ATH_DEBUG_MODULE
if (AR_DEBUG_LVL_CHECK(ATH_DEBUG_RECV)) {
DebugDumpBytes(pRecordBuf,pRecord->Length,"Bundle LookAhead");
}
#endif
if ((pRecord->Length / (sizeof(HTC_BUNDLED_LOOKAHEAD_REPORT))) >
HTC_HOST_MAX_MSG_PER_BUNDLE) {
A_ASSERT(false);
status = A_EPROTO;
break;
}
for (i = 0; i < (int)(pRecord->Length / (sizeof(HTC_BUNDLED_LOOKAHEAD_REPORT))); i++) {
((u8 *)(&pNextLookAheads[i]))[0] = pBundledLookAheadRpt->LookAhead[0];
((u8 *)(&pNextLookAheads[i]))[1] = pBundledLookAheadRpt->LookAhead[1];
((u8 *)(&pNextLookAheads[i]))[2] = pBundledLookAheadRpt->LookAhead[2];
((u8 *)(&pNextLookAheads[i]))[3] = pBundledLookAheadRpt->LookAhead[3];
pBundledLookAheadRpt++;
}
*pNumLookAheads = i;
}
break;
default:
AR_DEBUG_PRINTF(ATH_DEBUG_ERR, (" unhandled record: id:%d length:%d \n",
pRecord->RecordID, pRecord->Length));
break;
}
if (status) {
break;
}
pBuffer += pRecord->Length;
Length -= pRecord->Length;
}
#ifdef ATH_DEBUG_MODULE
if (status) {
DebugDumpBytes(pOrigBuffer,origLength,"BAD Recv Trailer");
}
#endif
AR_DEBUG_PRINTF(ATH_DEBUG_RECV, ("-HTCProcessTrailer \n"));
return status;
}
static int HTCProcessRecvHeader(struct htc_target *target,
struct htc_packet *pPacket,
u32 *pNextLookAheads,
int *pNumLookAheads)
{
u8 temp;
u8 *pBuf;
int status = 0;
u16 payloadLen;
u32 lookAhead;
pBuf = pPacket->pBuffer;
if (pNumLookAheads != NULL) {
*pNumLookAheads = 0;
}
AR_DEBUG_PRINTF(ATH_DEBUG_RECV, ("+HTCProcessRecvHeader \n"));
if (AR_DEBUG_LVL_CHECK(ATH_DEBUG_RECV)) {
AR_DEBUG_PRINTBUF(pBuf,pPacket->ActualLength,"HTC Recv PKT");
}
do {
payloadLen = A_GET_UINT16_FIELD(pBuf, struct htc_frame_hdr, PayloadLen);
((u8 *)&lookAhead)[0] = pBuf[0];
((u8 *)&lookAhead)[1] = pBuf[1];
((u8 *)&lookAhead)[2] = pBuf[2];
((u8 *)&lookAhead)[3] = pBuf[3];
if (pPacket->PktInfo.AsRx.HTCRxFlags & HTC_RX_PKT_REFRESH_HDR) {
pPacket->PktInfo.AsRx.ExpectedHdr = lookAhead;
pPacket->ActualLength = payloadLen + HTC_HDR_LENGTH;
if (pPacket->ActualLength > pPacket->BufferLength) {
AR_DEBUG_PRINTF(ATH_DEBUG_ERR,
("Refreshed HDR payload length (%d) in bundled RECV is invalid (hdr: 0x%X) \n",
payloadLen, lookAhead));
pPacket->ActualLength = min(pPacket->ActualLength, pPacket->BufferLength);
status = A_EPROTO;
break;
}
if (pPacket->Endpoint != A_GET_UINT8_FIELD(pBuf, struct htc_frame_hdr, EndpointID)) {
AR_DEBUG_PRINTF(ATH_DEBUG_ERR,
("Refreshed HDR endpoint (%d) does not match expected endpoint (%d) \n",
A_GET_UINT8_FIELD(pBuf, struct htc_frame_hdr, EndpointID), pPacket->Endpoint));
status = A_EPROTO;
break;
}
}
if (lookAhead != pPacket->PktInfo.AsRx.ExpectedHdr) {
AR_DEBUG_PRINTF(ATH_DEBUG_ERR,
("HTCProcessRecvHeader, lookahead mismatch! (pPkt:0x%lX flags:0x%X) \n",
(unsigned long)pPacket, pPacket->PktInfo.AsRx.HTCRxFlags));
#ifdef ATH_DEBUG_MODULE
DebugDumpBytes((u8 *)&pPacket->PktInfo.AsRx.ExpectedHdr,4,"Expected Message LookAhead");
DebugDumpBytes(pBuf,sizeof(struct htc_frame_hdr),"Current Frame Header");
#ifdef HTC_CAPTURE_LAST_FRAME
DebugDumpBytes((u8 *)&target->LastFrameHdr,sizeof(struct htc_frame_hdr),"Last Frame Header");
if (target->LastTrailerLength != 0) {
DebugDumpBytes(target->LastTrailer,
target->LastTrailerLength,
"Last trailer");
}
#endif
#endif
status = A_EPROTO;
break;
}
temp = A_GET_UINT8_FIELD(pBuf, struct htc_frame_hdr, Flags);
if (temp & HTC_FLAGS_RECV_TRAILER) {
temp = A_GET_UINT8_FIELD(pBuf, struct htc_frame_hdr, ControlBytes[0]);
if ((temp < sizeof(HTC_RECORD_HDR)) || (temp > payloadLen)) {
AR_DEBUG_PRINTF(ATH_DEBUG_ERR,
("HTCProcessRecvHeader, invalid header (payloadlength should be :%d, CB[0] is:%d) \n",
payloadLen, temp));
status = A_EPROTO;
break;
}
if (pPacket->PktInfo.AsRx.HTCRxFlags & HTC_RX_PKT_IGNORE_LOOKAHEAD) {
pNextLookAheads = NULL;
pNumLookAheads = NULL;
}
status = HTCProcessTrailer(target,
(pBuf + HTC_HDR_LENGTH + payloadLen - temp),
temp,
pNextLookAheads,
pNumLookAheads,
pPacket->Endpoint);
if (status) {
break;
}
#ifdef HTC_CAPTURE_LAST_FRAME
memcpy(target->LastTrailer, (pBuf + HTC_HDR_LENGTH + payloadLen - temp), temp);
target->LastTrailerLength = temp;
#endif
pPacket->ActualLength -= temp;
}
#ifdef HTC_CAPTURE_LAST_FRAME
else {
target->LastTrailerLength = 0;
}
#endif
pPacket->pBuffer += HTC_HDR_LENGTH;
pPacket->ActualLength -= HTC_HDR_LENGTH;
} while (false);
if (status) {
#ifdef ATH_DEBUG_MODULE
DebugDumpBytes(pBuf,pPacket->ActualLength < 256 ? pPacket->ActualLength : 256 ,"BAD HTC Recv PKT");
#endif
} else {
#ifdef HTC_CAPTURE_LAST_FRAME
memcpy(&target->LastFrameHdr,pBuf,sizeof(struct htc_frame_hdr));
#endif
if (AR_DEBUG_LVL_CHECK(ATH_DEBUG_RECV)) {
if (pPacket->ActualLength > 0) {
AR_DEBUG_PRINTBUF(pPacket->pBuffer,pPacket->ActualLength,"HTC - Application Msg");
}
}
}
AR_DEBUG_PRINTF(ATH_DEBUG_RECV, ("-HTCProcessRecvHeader \n"));
return status;
}
static INLINE void HTCAsyncRecvCheckMorePackets(struct htc_target *target,
u32 NextLookAheads[],
int NumLookAheads,
bool CheckMoreMsgs)
{
if (NumLookAheads > 0) {
int nextStatus;
int fetched = 0;
AR_DEBUG_PRINTF(ATH_DEBUG_RECV,
("HTCAsyncRecvCheckMorePackets - num lookaheads were non-zero : %d \n",
NumLookAheads));
REF_IRQ_STATUS_RECHECK(&target->Device);
nextStatus = HTCRecvMessagePendingHandler(target, NextLookAheads, NumLookAheads, NULL, &fetched);
if (A_EPROTO == nextStatus) {
AR_DEBUG_PRINTF(ATH_DEBUG_ERR,
("Next look ahead from recv header was INVALID\n"));
#ifdef ATH_DEBUG_MODULE
DebugDumpBytes((u8 *)NextLookAheads,
NumLookAheads * (sizeof(u32)),
"BAD lookaheads from lookahead report");
#endif
}
if (!nextStatus && !fetched) {
DevAsyncIrqProcessComplete(&target->Device);
}
} else {
if (CheckMoreMsgs) {
AR_DEBUG_PRINTF(ATH_DEBUG_RECV,
("HTCAsyncRecvCheckMorePackets - rechecking for more messages...\n"));
DevCheckPendingRecvMsgsAsync(&target->Device);
} else {
AR_DEBUG_PRINTF(ATH_DEBUG_RECV, ("HTCAsyncRecvCheckMorePackets - no check \n"));
}
}
}
static INLINE void DrainRecvIndicationQueue(struct htc_target *target, struct htc_endpoint *pEndpoint)
{
struct htc_packet_queue recvCompletions;
AR_DEBUG_PRINTF(ATH_DEBUG_RECV, ("+DrainRecvIndicationQueue \n"));
INIT_HTC_PACKET_QUEUE(&recvCompletions);
LOCK_HTC_RX(target);
pEndpoint->RxProcessCount++;
if (pEndpoint->RxProcessCount > 1) {
pEndpoint->RxProcessCount--;
UNLOCK_HTC_RX(target);
return;
}
while (true) {
HTC_PACKET_QUEUE_TRANSFER_TO_TAIL(&recvCompletions, &pEndpoint->RecvIndicationQueue);
if (HTC_QUEUE_EMPTY(&recvCompletions)) {
break;
}
UNLOCK_HTC_RX(target);
AR_DEBUG_PRINTF(ATH_DEBUG_RECV,
("DrainRecvIndicationQueue : completing %d RECV packets \n",
HTC_PACKET_QUEUE_DEPTH(&recvCompletions)));
DO_RCV_COMPLETION(pEndpoint,&recvCompletions);
LOCK_HTC_RX(target);
}
pEndpoint->RxProcessCount = 0;
UNLOCK_HTC_RX(target);
AR_DEBUG_PRINTF(ATH_DEBUG_RECV, ("-DrainRecvIndicationQueue \n"));
}
static INLINE void SetRxPacketIndicationFlags(u32 LookAhead,
struct htc_endpoint *pEndpoint,
struct htc_packet *pPacket)
{
struct htc_frame_hdr *pHdr = (struct htc_frame_hdr *)&LookAhead;
if (pHdr->EndpointID == pPacket->Endpoint) {
if (!HTC_QUEUE_EMPTY(&pEndpoint->RxBuffers)) {
FORCE_MORE_RX_PACKET_INDICATION_FLAG(pPacket);
}
}
}
void HTCRecvCompleteHandler(void *Context, struct htc_packet *pPacket)
{
struct htc_target *target = (struct htc_target *)Context;
struct htc_endpoint *pEndpoint;
u32 nextLookAheads[HTC_HOST_MAX_MSG_PER_BUNDLE];
int numLookAheads = 0;
int status;
bool checkMorePkts = true;
AR_DEBUG_PRINTF(ATH_DEBUG_RECV, ("+HTCRecvCompleteHandler (pkt:0x%lX, status:%d, ep:%d) \n",
(unsigned long)pPacket, pPacket->Status, pPacket->Endpoint));
A_ASSERT(!IS_DEV_IRQ_PROC_SYNC_MODE(&target->Device));
AR_DEBUG_ASSERT(pPacket->Endpoint < ENDPOINT_MAX);
pEndpoint = &target->EndPoint[pPacket->Endpoint];
pPacket->Completion = NULL;
status = pPacket->Status;
do {
if (status) {
AR_DEBUG_PRINTF(ATH_DEBUG_ERR, ("HTCRecvCompleteHandler: request failed (status:%d, ep:%d) \n",
pPacket->Status, pPacket->Endpoint));
break;
}
status = HTCProcessRecvHeader(target,pPacket,nextLookAheads,&numLookAheads);
if (status) {
break;
}
if (pPacket->PktInfo.AsRx.HTCRxFlags & HTC_RX_PKT_IGNORE_LOOKAHEAD) {
checkMorePkts = false;
}
DUMP_RECV_PKT_INFO(pPacket);
LOCK_HTC_RX(target);
SET_MORE_RX_PACKET_INDICATION_FLAG(nextLookAheads,numLookAheads,pEndpoint,pPacket);
HTC_PACKET_ENQUEUE(&pEndpoint->RecvIndicationQueue,pPacket);
HTC_RX_STAT_PROFILE(target,pEndpoint,numLookAheads);
UNLOCK_HTC_RX(target);
HTCAsyncRecvCheckMorePackets(target,nextLookAheads,numLookAheads,checkMorePkts);
} while (false);
if (status) {
AR_DEBUG_PRINTF(ATH_DEBUG_ERR,
("HTCRecvCompleteHandler , message fetch failed (status = %d) \n",
status));
HTC_RECYCLE_RX_PKT(target, pPacket, pEndpoint);
} else {
DrainRecvIndicationQueue(target,pEndpoint);
}
AR_DEBUG_PRINTF(ATH_DEBUG_RECV, ("-HTCRecvCompleteHandler\n"));
}
int HTCWaitforControlMessage(struct htc_target *target, struct htc_packet **ppControlPacket)
{
int status;
u32 lookAhead;
struct htc_packet *pPacket = NULL;
struct htc_frame_hdr *pHdr;
AR_DEBUG_PRINTF(ATH_DEBUG_RECV,("+HTCWaitforControlMessage \n"));
do {
*ppControlPacket = NULL;
status = DevPollMboxMsgRecv(&target->Device,
&lookAhead,
HTC_TARGET_RESPONSE_TIMEOUT);
if (status) {
break;
}
AR_DEBUG_PRINTF(ATH_DEBUG_RECV,
("HTCWaitforControlMessage : lookAhead : 0x%X \n", lookAhead));
pHdr = (struct htc_frame_hdr *)&lookAhead;
if (pHdr->EndpointID != ENDPOINT_0) {
AR_DEBUG_ASSERT(false);
status = A_EPROTO;
break;
}
if (status) {
AR_DEBUG_ASSERT(false);
status = A_EPROTO;
break;
}
pPacket = HTC_ALLOC_CONTROL_RX(target);
if (pPacket == NULL) {
AR_DEBUG_ASSERT(false);
status = A_NO_MEMORY;
break;
}
pPacket->PktInfo.AsRx.HTCRxFlags = 0;
pPacket->PktInfo.AsRx.ExpectedHdr = lookAhead;
pPacket->ActualLength = pHdr->PayloadLen + HTC_HDR_LENGTH;
if (pPacket->ActualLength > pPacket->BufferLength) {
AR_DEBUG_ASSERT(false);
status = A_EPROTO;
break;
}
pPacket->Completion = NULL;
status = HTCIssueRecv(target, pPacket);
if (status) {
break;
}
status = HTCProcessRecvHeader(target,pPacket,NULL,NULL);
pPacket->Status = status;
if (status) {
AR_DEBUG_PRINTF(ATH_DEBUG_ERR,
("HTCWaitforControlMessage, HTCProcessRecvHeader failed (status = %d) \n",
status));
break;
}
*ppControlPacket = pPacket;
} while (false);
if (status) {
if (pPacket != NULL) {
HTC_FREE_CONTROL_RX(target,pPacket);
}
}
AR_DEBUG_PRINTF(ATH_DEBUG_RECV,("-HTCWaitforControlMessage \n"));
return status;
}
static int AllocAndPrepareRxPackets(struct htc_target *target,
u32 LookAheads[],
int Messages,
struct htc_endpoint *pEndpoint,
struct htc_packet_queue *pQueue)
{
int status = 0;
struct htc_packet *pPacket;
struct htc_frame_hdr *pHdr;
int i,j;
int numMessages;
int fullLength;
bool noRecycle;
LOCK_HTC_RX(target);
for (i = 0; i < Messages; i++) {
pHdr = (struct htc_frame_hdr *)&LookAheads[i];
if (pHdr->EndpointID >= ENDPOINT_MAX) {
AR_DEBUG_PRINTF(ATH_DEBUG_ERR,("Invalid Endpoint in look-ahead: %d \n",pHdr->EndpointID));
status = A_EPROTO;
break;
}
if (pHdr->EndpointID != pEndpoint->Id) {
AR_DEBUG_PRINTF(ATH_DEBUG_ERR,("Invalid Endpoint in look-ahead: %d should be : %d (index:%d)\n",
pHdr->EndpointID, pEndpoint->Id, i));
status = A_EPROTO;
break;
}
if (pHdr->PayloadLen > HTC_MAX_PAYLOAD_LENGTH) {
AR_DEBUG_PRINTF(ATH_DEBUG_ERR,("Payload length %d exceeds max HTC : %d !\n",
pHdr->PayloadLen, (u32)HTC_MAX_PAYLOAD_LENGTH));
status = A_EPROTO;
break;
}
if (0 == pEndpoint->ServiceID) {
AR_DEBUG_PRINTF(ATH_DEBUG_ERR,("Endpoint %d is not connected !\n",pHdr->EndpointID));
status = A_EPROTO;
break;
}
if ((pHdr->Flags & HTC_FLAGS_RECV_BUNDLE_CNT_MASK) == 0) {
numMessages = 1;
} else {
numMessages = (pHdr->Flags & HTC_FLAGS_RECV_BUNDLE_CNT_MASK) >> HTC_FLAGS_RECV_BUNDLE_CNT_SHIFT;
numMessages++;
A_ASSERT(numMessages <= target->MaxMsgPerBundle);
INC_HTC_EP_STAT(pEndpoint, RxBundleIndFromHdr, 1);
AR_DEBUG_PRINTF(ATH_DEBUG_RECV,
("HTC header indicates :%d messages can be fetched as a bundle \n",numMessages));
}
fullLength = DEV_CALC_RECV_PADDED_LEN(&target->Device,pHdr->PayloadLen + sizeof(struct htc_frame_hdr));
for (j = 0; j < numMessages; j++) {
noRecycle = false;
if (pEndpoint->EpCallBacks.EpRecvAlloc != NULL) {
UNLOCK_HTC_RX(target);
noRecycle = true;
pPacket = pEndpoint->EpCallBacks.EpRecvAlloc(pEndpoint->EpCallBacks.pContext,
pEndpoint->Id,
fullLength);
LOCK_HTC_RX(target);
} else if ((pEndpoint->EpCallBacks.EpRecvAllocThresh != NULL) &&
(fullLength > pEndpoint->EpCallBacks.RecvAllocThreshold)) {
INC_HTC_EP_STAT(pEndpoint,RxAllocThreshHit,1);
INC_HTC_EP_STAT(pEndpoint,RxAllocThreshBytes,pHdr->PayloadLen);
UNLOCK_HTC_RX(target);
noRecycle = true;
pPacket = pEndpoint->EpCallBacks.EpRecvAllocThresh(pEndpoint->EpCallBacks.pContext,
pEndpoint->Id,
fullLength);
LOCK_HTC_RX(target);
} else {
pPacket = HTC_PACKET_DEQUEUE(&pEndpoint->RxBuffers);
if (NULL == pPacket) {
if (pEndpoint->EpCallBacks.EpRecvRefill != NULL) {
UNLOCK_HTC_RX(target);
pEndpoint->EpCallBacks.EpRecvRefill(pEndpoint->EpCallBacks.pContext,
pEndpoint->Id);
LOCK_HTC_RX(target);
pPacket = HTC_PACKET_DEQUEUE(&pEndpoint->RxBuffers);
}
}
}
if (NULL == pPacket) {
target->RecvStateFlags |= HTC_RECV_WAIT_BUFFERS;
target->EpWaitingForBuffers = pEndpoint->Id;
status = A_NO_RESOURCE;
break;
}
AR_DEBUG_ASSERT(pPacket->Endpoint == pEndpoint->Id);
pPacket->PktInfo.AsRx.HTCRxFlags = 0;
pPacket->PktInfo.AsRx.IndicationFlags = 0;
pPacket->Status = 0;
if (noRecycle) {
pPacket->PktInfo.AsRx.HTCRxFlags |= HTC_RX_PKT_NO_RECYCLE;
}
HTC_PACKET_ENQUEUE(pQueue,pPacket);
if (HTC_STOPPING(target)) {
status = A_ECANCELED;
break;
}
if ((u32)fullLength > pPacket->BufferLength) {
AR_DEBUG_PRINTF(ATH_DEBUG_ERR,
("Payload Length Error : header reports payload of: %d (%d) endpoint buffer size: %d \n",
pHdr->PayloadLen, fullLength, pPacket->BufferLength));
status = A_EPROTO;
break;
}
if (j > 0) {
pPacket->PktInfo.AsRx.HTCRxFlags |= HTC_RX_PKT_REFRESH_HDR;
pPacket->PktInfo.AsRx.ExpectedHdr = 0xFFFFFFFF;
} else {
pPacket->PktInfo.AsRx.ExpectedHdr = LookAheads[i];
}
pPacket->ActualLength = pHdr->PayloadLen + HTC_HDR_LENGTH;
}
if (status) {
if (A_NO_RESOURCE == status) {
status = 0;
}
break;
}
}
UNLOCK_HTC_RX(target);
if (status) {
while (!HTC_QUEUE_EMPTY(pQueue)) {
pPacket = HTC_PACKET_DEQUEUE(pQueue);
HTC_RECYCLE_RX_PKT(target,pPacket,&target->EndPoint[pPacket->Endpoint]);
}
}
return status;
}
static void HTCAsyncRecvScatterCompletion(struct hif_scatter_req *pScatterReq)
{
int i;
struct htc_packet *pPacket;
struct htc_endpoint *pEndpoint;
u32 lookAheads[HTC_HOST_MAX_MSG_PER_BUNDLE];
int numLookAheads = 0;
struct htc_target *target = (struct htc_target *)pScatterReq->Context;
int status;
bool partialBundle = false;
struct htc_packet_queue localRecvQueue;
bool procError = false;
AR_DEBUG_PRINTF(ATH_DEBUG_RECV,("+HTCAsyncRecvScatterCompletion TotLen: %d Entries: %d\n",
pScatterReq->TotalLength, pScatterReq->ValidScatterEntries));
A_ASSERT(!IS_DEV_IRQ_PROC_SYNC_MODE(&target->Device));
if (pScatterReq->CompletionStatus) {
AR_DEBUG_PRINTF(ATH_DEBUG_ERR,("** Recv Scatter Request Failed: %d \n",pScatterReq->CompletionStatus));
}
if (pScatterReq->CallerFlags & HTC_SCATTER_REQ_FLAGS_PARTIAL_BUNDLE) {
partialBundle = true;
}
DEV_FINISH_SCATTER_OPERATION(pScatterReq);
INIT_HTC_PACKET_QUEUE(&localRecvQueue);
pPacket = (struct htc_packet *)pScatterReq->ScatterList[0].pCallerContexts[0];
pEndpoint = &target->EndPoint[pPacket->Endpoint];
for (i = 0; i < pScatterReq->ValidScatterEntries; i++) {
pPacket = (struct htc_packet *)pScatterReq->ScatterList[i].pCallerContexts[0];
A_ASSERT(pPacket != NULL);
numLookAheads = 0;
if (!pScatterReq->CompletionStatus) {
status = HTCProcessRecvHeader(target,pPacket,lookAheads,&numLookAheads);
} else {
status = A_ERROR;
}
if (!status) {
LOCK_HTC_RX(target);
HTC_RX_STAT_PROFILE(target,pEndpoint,numLookAheads);
INC_HTC_EP_STAT(pEndpoint, RxPacketsBundled, 1);
UNLOCK_HTC_RX(target);
if (i == (pScatterReq->ValidScatterEntries - 1)) {
SET_MORE_RX_PACKET_INDICATION_FLAG(lookAheads,numLookAheads,pEndpoint,pPacket);
} else {
FORCE_MORE_RX_PACKET_INDICATION_FLAG(pPacket);
}
DUMP_RECV_PKT_INFO(pPacket);
HTC_PACKET_ENQUEUE(&localRecvQueue,pPacket);
} else {
AR_DEBUG_PRINTF(ATH_DEBUG_ERR,(" Recv packet scatter entry %d failed (out of %d) \n",
i, pScatterReq->ValidScatterEntries));
HTC_RECYCLE_RX_PKT(target, pPacket, pEndpoint);
procError = true;
}
}
DEV_FREE_SCATTER_REQ(&target->Device,pScatterReq);
LOCK_HTC_RX(target);
HTC_PACKET_QUEUE_TRANSFER_TO_TAIL(&pEndpoint->RecvIndicationQueue, &localRecvQueue);
UNLOCK_HTC_RX(target);
if (!procError) {
HTCAsyncRecvCheckMorePackets(target,
lookAheads,
numLookAheads,
partialBundle ? false : true);
}
DrainRecvIndicationQueue(target,pEndpoint);
AR_DEBUG_PRINTF(ATH_DEBUG_RECV,("-HTCAsyncRecvScatterCompletion \n"));
}
static int HTCIssueRecvPacketBundle(struct htc_target *target,
struct htc_packet_queue *pRecvPktQueue,
struct htc_packet_queue *pSyncCompletionQueue,
int *pNumPacketsFetched,
bool PartialBundle)
{
int status = 0;
struct hif_scatter_req *pScatterReq;
int i, totalLength;
int pktsToScatter;
struct htc_packet *pPacket;
bool asyncMode = (pSyncCompletionQueue == NULL) ? true : false;
int scatterSpaceRemaining = DEV_GET_MAX_BUNDLE_RECV_LENGTH(&target->Device);
pktsToScatter = HTC_PACKET_QUEUE_DEPTH(pRecvPktQueue);
pktsToScatter = min(pktsToScatter, target->MaxMsgPerBundle);
if ((HTC_PACKET_QUEUE_DEPTH(pRecvPktQueue) - pktsToScatter) > 0) {
PartialBundle = true;
AR_DEBUG_PRINTF(ATH_DEBUG_WARN,
("HTCIssueRecvPacketBundle : partial bundle detected num:%d , %d \n",
HTC_PACKET_QUEUE_DEPTH(pRecvPktQueue), pktsToScatter));
}
totalLength = 0;
AR_DEBUG_PRINTF(ATH_DEBUG_RECV,("+HTCIssueRecvPacketBundle (Numpackets: %d , actual : %d) \n",
HTC_PACKET_QUEUE_DEPTH(pRecvPktQueue), pktsToScatter));
do {
pScatterReq = DEV_ALLOC_SCATTER_REQ(&target->Device);
if (pScatterReq == NULL) {
break;
}
pScatterReq->CallerFlags = 0;
if (PartialBundle) {
pScatterReq->CallerFlags |= HTC_SCATTER_REQ_FLAGS_PARTIAL_BUNDLE;
}
for (i = 0; i < pktsToScatter; i++) {
int paddedLength;
pPacket = HTC_PACKET_DEQUEUE(pRecvPktQueue);
A_ASSERT(pPacket != NULL);
paddedLength = DEV_CALC_RECV_PADDED_LEN(&target->Device, pPacket->ActualLength);
if ((scatterSpaceRemaining - paddedLength) < 0) {
HTC_PACKET_ENQUEUE_TO_HEAD(pRecvPktQueue,pPacket);
break;
}
scatterSpaceRemaining -= paddedLength;
if (PartialBundle || (i < (pktsToScatter - 1))) {
pPacket->PktInfo.AsRx.HTCRxFlags |= HTC_RX_PKT_IGNORE_LOOKAHEAD;
}
pScatterReq->ScatterList[i].pBuffer = pPacket->pBuffer;
pScatterReq->ScatterList[i].Length = paddedLength;
pPacket->PktInfo.AsRx.HTCRxFlags |= HTC_RX_PKT_PART_OF_BUNDLE;
if (asyncMode) {
pScatterReq->ScatterList[i].pCallerContexts[0] = pPacket;
} else {
HTC_PACKET_ENQUEUE(pSyncCompletionQueue,pPacket);
}
A_ASSERT(pScatterReq->ScatterList[i].Length);
totalLength += pScatterReq->ScatterList[i].Length;
}
pScatterReq->TotalLength = totalLength;
pScatterReq->ValidScatterEntries = i;
if (asyncMode) {
pScatterReq->CompletionRoutine = HTCAsyncRecvScatterCompletion;
pScatterReq->Context = target;
}
status = DevSubmitScatterRequest(&target->Device, pScatterReq, DEV_SCATTER_READ, asyncMode);
if (!status) {
*pNumPacketsFetched = i;
}
if (!asyncMode) {
DEV_FREE_SCATTER_REQ(&target->Device, pScatterReq);
}
} while (false);
AR_DEBUG_PRINTF(ATH_DEBUG_RECV,("-HTCIssueRecvPacketBundle (status:%d) (fetched:%d) \n",
status,*pNumPacketsFetched));
return status;
}
static INLINE void CheckRecvWaterMark(struct htc_endpoint *pEndpoint)
{
if (pEndpoint->EpCallBacks.RecvRefillWaterMark > 0) {
if (HTC_PACKET_QUEUE_DEPTH(&pEndpoint->RxBuffers) < pEndpoint->EpCallBacks.RecvRefillWaterMark) {
pEndpoint->EpCallBacks.EpRecvRefill(pEndpoint->EpCallBacks.pContext,
pEndpoint->Id);
}
}
}
int HTCRecvMessagePendingHandler(void *Context, u32 MsgLookAheads[], int NumLookAheads, bool *pAsyncProc, int *pNumPktsFetched)
{
struct htc_target *target = (struct htc_target *)Context;
int status = 0;
struct htc_packet *pPacket;
struct htc_endpoint *pEndpoint;
bool asyncProc = false;
u32 lookAheads[HTC_HOST_MAX_MSG_PER_BUNDLE];
int pktsFetched;
struct htc_packet_queue recvPktQueue, syncCompletedPktsQueue;
bool partialBundle;
HTC_ENDPOINT_ID id;
int totalFetched = 0;
AR_DEBUG_PRINTF(ATH_DEBUG_RECV,("+HTCRecvMessagePendingHandler NumLookAheads: %d \n",NumLookAheads));
if (pNumPktsFetched != NULL) {
*pNumPktsFetched = 0;
}
if (IS_DEV_IRQ_PROCESSING_ASYNC_ALLOWED(&target->Device)) {
asyncProc = true;
}
if (pAsyncProc != NULL) {
*pAsyncProc = asyncProc;
}
if (NumLookAheads > HTC_HOST_MAX_MSG_PER_BUNDLE) {
A_ASSERT(false);
return A_EPROTO;
}
memcpy(lookAheads, MsgLookAheads, (sizeof(u32)) * NumLookAheads);
while (true) {
INIT_HTC_PACKET_QUEUE(&recvPktQueue);
INIT_HTC_PACKET_QUEUE(&syncCompletedPktsQueue);
if (NumLookAheads > HTC_HOST_MAX_MSG_PER_BUNDLE) {
status = A_EPROTO;
A_ASSERT(false);
break;
}
id = ((struct htc_frame_hdr *)&lookAheads[0])->EndpointID;
pEndpoint = &target->EndPoint[id];
if (id >= ENDPOINT_MAX) {
AR_DEBUG_PRINTF(ATH_DEBUG_ERR,("MsgPend, Invalid Endpoint in look-ahead: %d \n",id));
status = A_EPROTO;
break;
}
status = AllocAndPrepareRxPackets(target,
lookAheads,
NumLookAheads,
pEndpoint,
&recvPktQueue);
if (status) {
break;
}
if (HTC_PACKET_QUEUE_DEPTH(&recvPktQueue) >= 2) {
REF_IRQ_STATUS_RECHECK(&target->Device);
}
totalFetched += HTC_PACKET_QUEUE_DEPTH(&recvPktQueue);
NumLookAheads = 0;
partialBundle = false;
while (!HTC_QUEUE_EMPTY(&recvPktQueue)) {
pktsFetched = 0;
if (target->RecvBundlingEnabled && (HTC_PACKET_QUEUE_DEPTH(&recvPktQueue) > 1)) {
status = HTCIssueRecvPacketBundle(target,
&recvPktQueue,
asyncProc ? NULL : &syncCompletedPktsQueue,
&pktsFetched,
partialBundle);
if (status) {
break;
}
if (HTC_PACKET_QUEUE_DEPTH(&recvPktQueue) != 0) {
partialBundle = true;
}
}
if (0 == pktsFetched) {
pPacket = HTC_PACKET_DEQUEUE(&recvPktQueue);
A_ASSERT(pPacket != NULL);
if (asyncProc) {
pPacket->Completion = HTCRecvCompleteHandler;
pPacket->pContext = target;
} else {
pPacket->Completion = NULL;
}
if (HTC_PACKET_QUEUE_DEPTH(&recvPktQueue) > 0) {
pPacket->PktInfo.AsRx.HTCRxFlags |= HTC_RX_PKT_IGNORE_LOOKAHEAD;
}
status = HTCIssueRecv(target, pPacket);
if (status) {
break;
}
if (!asyncProc) {
HTC_PACKET_ENQUEUE(&syncCompletedPktsQueue,pPacket);
}
}
}
if (!status) {
CheckRecvWaterMark(pEndpoint);
}
if (asyncProc) {
break;
}
if (target->Device.DSRCanYield) {
target->Device.CurrentDSRRecvCount++;
}
while (!HTC_QUEUE_EMPTY(&syncCompletedPktsQueue)) {
struct htc_packet_queue container;
pPacket = HTC_PACKET_DEQUEUE(&syncCompletedPktsQueue);
A_ASSERT(pPacket != NULL);
pEndpoint = &target->EndPoint[pPacket->Endpoint];
NumLookAheads = 0;
status = HTCProcessRecvHeader(target,pPacket,lookAheads,&NumLookAheads);
if (status) {
break;
}
if (HTC_QUEUE_EMPTY(&syncCompletedPktsQueue)) {
SET_MORE_RX_PACKET_INDICATION_FLAG(lookAheads,NumLookAheads,pEndpoint,pPacket);
} else {
FORCE_MORE_RX_PACKET_INDICATION_FLAG(pPacket);
}
HTC_RX_STAT_PROFILE(target,pEndpoint,NumLookAheads);
if (pPacket->PktInfo.AsRx.HTCRxFlags & HTC_RX_PKT_PART_OF_BUNDLE) {
INC_HTC_EP_STAT(pEndpoint, RxPacketsBundled, 1);
}
INIT_HTC_PACKET_QUEUE_AND_ADD(&container,pPacket);
DO_RCV_COMPLETION(pEndpoint,&container);
}
if (status) {
break;
}
if (NumLookAheads == 0) {
break;
}
if (target->Device.DSRCanYield) {
if (DEV_CHECK_RECV_YIELD(&target->Device)) {
break;
}
}
A_CHECK_DRV_TX();
REF_IRQ_STATUS_RECHECK(&target->Device);
}
if (status) {
AR_DEBUG_PRINTF(ATH_DEBUG_ERR,
("Failed to get pending recv messages (%d) \n",status));
while (!HTC_QUEUE_EMPTY(&recvPktQueue)) {
pPacket = HTC_PACKET_DEQUEUE(&recvPktQueue);
HTC_RECYCLE_RX_PKT(target, pPacket, &target->EndPoint[pPacket->Endpoint]);
}
while (!HTC_QUEUE_EMPTY(&syncCompletedPktsQueue)) {
pPacket = HTC_PACKET_DEQUEUE(&syncCompletedPktsQueue);
HTC_RECYCLE_RX_PKT(target, pPacket, &target->EndPoint[pPacket->Endpoint]);
}
if (HTC_STOPPING(target)) {
AR_DEBUG_PRINTF(ATH_DEBUG_WARN,
(" Host is going to stop. blocking receiver for HTCStop.. \n"));
DevStopRecv(&target->Device, asyncProc ? DEV_STOP_RECV_ASYNC : DEV_STOP_RECV_SYNC);
}
}
if (target->RecvStateFlags & HTC_RECV_WAIT_BUFFERS) {
AR_DEBUG_PRINTF(ATH_DEBUG_WARN,
(" Host has no RX buffers, blocking receiver to prevent overrun.. \n"));
DevStopRecv(&target->Device, asyncProc ? DEV_STOP_RECV_ASYNC : DEV_STOP_RECV_SYNC);
}
if (pNumPktsFetched != NULL) {
*pNumPktsFetched = totalFetched;
}
AR_DEBUG_PRINTF(ATH_DEBUG_RECV,("-HTCRecvMessagePendingHandler \n"));
return status;
}
int HTCAddReceivePktMultiple(HTC_HANDLE HTCHandle, struct htc_packet_queue *pPktQueue)
{
struct htc_target *target = GET_HTC_TARGET_FROM_HANDLE(HTCHandle);
struct htc_endpoint *pEndpoint;
bool unblockRecv = false;
int status = 0;
struct htc_packet *pFirstPacket;
pFirstPacket = HTC_GET_PKT_AT_HEAD(pPktQueue);
if (NULL == pFirstPacket) {
A_ASSERT(false);
return A_EINVAL;
}
AR_DEBUG_ASSERT(pFirstPacket->Endpoint < ENDPOINT_MAX);
AR_DEBUG_PRINTF(ATH_DEBUG_RECV,
("+- HTCAddReceivePktMultiple : endPointId: %d, cnt:%d, length: %d\n",
pFirstPacket->Endpoint,
HTC_PACKET_QUEUE_DEPTH(pPktQueue),
pFirstPacket->BufferLength));
do {
pEndpoint = &target->EndPoint[pFirstPacket->Endpoint];
LOCK_HTC_RX(target);
if (HTC_STOPPING(target)) {
struct htc_packet *pPacket;
UNLOCK_HTC_RX(target);
HTC_PACKET_QUEUE_ITERATE_ALLOW_REMOVE(pPktQueue,pPacket) {
pPacket->Status = A_ECANCELED;
} HTC_PACKET_QUEUE_ITERATE_END;
DO_RCV_COMPLETION(pEndpoint,pPktQueue);
break;
}
HTC_PACKET_QUEUE_TRANSFER_TO_TAIL(&pEndpoint->RxBuffers, pPktQueue);
if (target->RecvStateFlags & HTC_RECV_WAIT_BUFFERS) {
if (target->EpWaitingForBuffers == pFirstPacket->Endpoint) {
AR_DEBUG_PRINTF(ATH_DEBUG_RECV,(" receiver was blocked on ep:%d, unblocking.. \n",
target->EpWaitingForBuffers));
target->RecvStateFlags &= ~HTC_RECV_WAIT_BUFFERS;
target->EpWaitingForBuffers = ENDPOINT_MAX;
unblockRecv = true;
}
}
UNLOCK_HTC_RX(target);
if (unblockRecv && !HTC_STOPPING(target)) {
DevEnableRecv(&target->Device,DEV_ENABLE_RECV_SYNC);
}
} while (false);
return status;
}
int HTCAddReceivePkt(HTC_HANDLE HTCHandle, struct htc_packet *pPacket)
{
struct htc_packet_queue queue;
INIT_HTC_PACKET_QUEUE_AND_ADD(&queue,pPacket);
return HTCAddReceivePktMultiple(HTCHandle, &queue);
}
void HTCUnblockRecv(HTC_HANDLE HTCHandle)
{
struct htc_target *target = GET_HTC_TARGET_FROM_HANDLE(HTCHandle);
bool unblockRecv = false;
LOCK_HTC_RX(target);
if (target->RecvStateFlags & HTC_RECV_WAIT_BUFFERS) {
AR_DEBUG_PRINTF(ATH_DEBUG_RECV,("HTCUnblockRx : receiver was blocked on ep:%d, unblocking.. \n",
target->EpWaitingForBuffers));
target->RecvStateFlags &= ~HTC_RECV_WAIT_BUFFERS;
target->EpWaitingForBuffers = ENDPOINT_MAX;
unblockRecv = true;
}
UNLOCK_HTC_RX(target);
if (unblockRecv && !HTC_STOPPING(target)) {
DevEnableRecv(&target->Device,DEV_ENABLE_RECV_ASYNC);
}
}
static void HTCFlushRxQueue(struct htc_target *target, struct htc_endpoint *pEndpoint, struct htc_packet_queue *pQueue)
{
struct htc_packet *pPacket;
struct htc_packet_queue container;
LOCK_HTC_RX(target);
while (1) {
pPacket = HTC_PACKET_DEQUEUE(pQueue);
if (NULL == pPacket) {
break;
}
UNLOCK_HTC_RX(target);
pPacket->Status = A_ECANCELED;
pPacket->ActualLength = 0;
AR_DEBUG_PRINTF(ATH_DEBUG_RECV, (" Flushing RX packet:0x%lX, length:%d, ep:%d \n",
(unsigned long)pPacket, pPacket->BufferLength, pPacket->Endpoint));
INIT_HTC_PACKET_QUEUE_AND_ADD(&container,pPacket);
DO_RCV_COMPLETION(pEndpoint,&container);
LOCK_HTC_RX(target);
}
UNLOCK_HTC_RX(target);
}
static void HTCFlushEndpointRX(struct htc_target *target, struct htc_endpoint *pEndpoint)
{
HTCFlushRxQueue(target,pEndpoint,&pEndpoint->RecvIndicationQueue);
HTCFlushRxQueue(target,pEndpoint,&pEndpoint->RxBuffers);
}
void HTCFlushRecvBuffers(struct htc_target *target)
{
struct htc_endpoint *pEndpoint;
int i;
for (i = ENDPOINT_0; i < ENDPOINT_MAX; i++) {
pEndpoint = &target->EndPoint[i];
if (pEndpoint->ServiceID == 0) {
continue;
}
HTCFlushEndpointRX(target,pEndpoint);
}
}
void HTCEnableRecv(HTC_HANDLE HTCHandle)
{
struct htc_target *target = GET_HTC_TARGET_FROM_HANDLE(HTCHandle);
if (!HTC_STOPPING(target)) {
DevEnableRecv(&target->Device,DEV_ENABLE_RECV_SYNC);
}
}
void HTCDisableRecv(HTC_HANDLE HTCHandle)
{
struct htc_target *target = GET_HTC_TARGET_FROM_HANDLE(HTCHandle);
if (!HTC_STOPPING(target)) {
DevStopRecv(&target->Device,DEV_ENABLE_RECV_SYNC);
}
}
int HTCGetNumRecvBuffers(HTC_HANDLE HTCHandle,
HTC_ENDPOINT_ID Endpoint)
{
struct htc_target *target = GET_HTC_TARGET_FROM_HANDLE(HTCHandle);
return HTC_PACKET_QUEUE_DEPTH(&(target->EndPoint[Endpoint].RxBuffers));
}
int HTCWaitForPendingRecv(HTC_HANDLE HTCHandle,
u32 TimeoutInMs,
bool *pbIsRecvPending)
{
int status = 0;
struct htc_target *target = GET_HTC_TARGET_FROM_HANDLE(HTCHandle);
status = DevWaitForPendingRecv(&target->Device,
TimeoutInMs,
pbIsRecvPending);
return status;
}
