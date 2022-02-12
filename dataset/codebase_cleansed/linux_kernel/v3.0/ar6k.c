void AR6KFreeIOPacket(struct ar6k_device *pDev, struct htc_packet *pPacket)
{
LOCK_AR6K(pDev);
HTC_PACKET_ENQUEUE(&pDev->RegisterIOList,pPacket);
UNLOCK_AR6K(pDev);
}
struct htc_packet *AR6KAllocIOPacket(struct ar6k_device *pDev)
{
struct htc_packet *pPacket;
LOCK_AR6K(pDev);
pPacket = HTC_PACKET_DEQUEUE(&pDev->RegisterIOList);
UNLOCK_AR6K(pDev);
return pPacket;
}
void DevCleanup(struct ar6k_device *pDev)
{
DevCleanupGMbox(pDev);
if (pDev->HifAttached) {
HIFDetachHTC(pDev->HIFDevice);
pDev->HifAttached = false;
}
DevCleanupVirtualScatterSupport(pDev);
if (A_IS_MUTEX_VALID(&pDev->Lock)) {
A_MUTEX_DELETE(&pDev->Lock);
}
}
int DevSetup(struct ar6k_device *pDev)
{
u32 blocksizes[AR6K_MAILBOXES];
int status = 0;
int i;
HTC_CALLBACKS htcCallbacks;
do {
DL_LIST_INIT(&pDev->ScatterReqHead);
INIT_HTC_PACKET_QUEUE(&pDev->RegisterIOList);
A_MUTEX_INIT(&pDev->Lock);
A_MEMZERO(&htcCallbacks, sizeof(HTC_CALLBACKS));
htcCallbacks.rwCompletionHandler = DevRWCompletionHandler;
htcCallbacks.dsrHandler = DevDsrHandler;
htcCallbacks.context = pDev;
status = HIFAttachHTC(pDev->HIFDevice, &htcCallbacks);
if (status) {
break;
}
pDev->HifAttached = true;
status = HIFConfigureDevice(pDev->HIFDevice, HIF_DEVICE_GET_MBOX_ADDR,
&pDev->MailBoxInfo, sizeof(pDev->MailBoxInfo));
if (status) {
A_ASSERT(false);
break;
}
for (i = 0; i < AR6K_MAX_REG_IO_BUFFERS; i++) {
struct htc_packet *pIOPacket;
pIOPacket = &pDev->RegIOBuffers[i].HtcPacket;
SET_HTC_PACKET_INFO_RX_REFILL(pIOPacket,
pDev,
pDev->RegIOBuffers[i].Buffer,
AR6K_REG_IO_BUFFER_SIZE,
0);
AR6KFreeIOPacket(pDev,pIOPacket);
}
status = HIFConfigureDevice(pDev->HIFDevice, HIF_DEVICE_GET_MBOX_BLOCK_SIZE,
blocksizes, sizeof(blocksizes));
if (status) {
A_ASSERT(false);
break;
}
pDev->BlockSize = blocksizes[MAILBOX_FOR_BLOCK_SIZE];
A_ASSERT((pDev->BlockSize & (pDev->BlockSize - 1)) == 0);
pDev->BlockMask = pDev->BlockSize - 1;
AR_DEBUG_PRINTF(ATH_DEBUG_TRC,("BlockSize: %d, MailboxAddress:0x%X \n",
pDev->BlockSize, pDev->MailBoxInfo.MboxAddresses[HTC_MAILBOX]));
pDev->GetPendingEventsFunc = NULL;
HIFConfigureDevice(pDev->HIFDevice,
HIF_DEVICE_GET_PENDING_EVENTS_FUNC,
&pDev->GetPendingEventsFunc,
sizeof(pDev->GetPendingEventsFunc));
pDev->HifIRQProcessingMode = HIF_DEVICE_IRQ_ASYNC_SYNC;
HIFConfigureDevice(pDev->HIFDevice,
HIF_DEVICE_GET_IRQ_PROC_MODE,
&pDev->HifIRQProcessingMode,
sizeof(pDev->HifIRQProcessingMode));
switch (pDev->HifIRQProcessingMode) {
case HIF_DEVICE_IRQ_SYNC_ONLY:
AR_DEBUG_PRINTF(ATH_DEBUG_WARN,("HIF Interrupt processing is SYNC ONLY\n"));
HIFConfigureDevice(pDev->HIFDevice,
HIF_DEVICE_GET_IRQ_YIELD_PARAMS,
&pDev->HifIRQYieldParams,
sizeof(pDev->HifIRQYieldParams));
if (pDev->HifIRQYieldParams.RecvPacketYieldCount > 0) {
AR_DEBUG_PRINTF(ATH_DEBUG_WARN,
("HIF requests that DSR yield per %d RECV packets \n",
pDev->HifIRQYieldParams.RecvPacketYieldCount));
pDev->DSRCanYield = true;
}
break;
case HIF_DEVICE_IRQ_ASYNC_SYNC:
AR_DEBUG_PRINTF(ATH_DEBUG_TRC,("HIF Interrupt processing is ASYNC and SYNC\n"));
break;
default:
A_ASSERT(false);
}
pDev->HifMaskUmaskRecvEvent = NULL;
HIFConfigureDevice(pDev->HIFDevice,
HIF_DEVICE_GET_RECV_EVENT_MASK_UNMASK_FUNC,
&pDev->HifMaskUmaskRecvEvent,
sizeof(pDev->HifMaskUmaskRecvEvent));
AR_DEBUG_PRINTF(ATH_DEBUG_TRC,("HIF special overrides : 0x%lX , 0x%lX\n",
(unsigned long)pDev->GetPendingEventsFunc, (unsigned long)pDev->HifMaskUmaskRecvEvent));
status = DevDisableInterrupts(pDev);
if (status) {
break;
}
status = DevSetupGMbox(pDev);
} while (false);
if (status) {
if (pDev->HifAttached) {
HIFDetachHTC(pDev->HIFDevice);
pDev->HifAttached = false;
}
}
return status;
}
int DevEnableInterrupts(struct ar6k_device *pDev)
{
int status;
struct ar6k_irq_enable_registers regs;
LOCK_AR6K(pDev);
pDev->IrqEnableRegisters.int_status_enable = INT_STATUS_ENABLE_ERROR_SET(0x01) |
INT_STATUS_ENABLE_CPU_SET(0x01) |
INT_STATUS_ENABLE_COUNTER_SET(0x01);
if (NULL == pDev->GetPendingEventsFunc) {
pDev->IrqEnableRegisters.int_status_enable |= INT_STATUS_ENABLE_MBOX_DATA_SET(0x01);
} else {
pDev->IrqEnableRegisters.int_status_enable &= ~INT_STATUS_ENABLE_MBOX_DATA_SET(0x01);
}
pDev->IrqEnableRegisters.cpu_int_status_enable = CPU_INT_STATUS_ENABLE_BIT_SET(0x00);
pDev->IrqEnableRegisters.error_status_enable =
ERROR_STATUS_ENABLE_RX_UNDERFLOW_SET(0x01) |
ERROR_STATUS_ENABLE_TX_OVERFLOW_SET(0x01);
pDev->IrqEnableRegisters.counter_int_status_enable =
COUNTER_INT_STATUS_ENABLE_BIT_SET(AR6K_TARGET_DEBUG_INTR_MASK);
memcpy(&regs,&pDev->IrqEnableRegisters,AR6K_IRQ_ENABLE_REGS_SIZE);
UNLOCK_AR6K(pDev);
status = HIFReadWrite(pDev->HIFDevice,
INT_STATUS_ENABLE_ADDRESS,
&regs.int_status_enable,
AR6K_IRQ_ENABLE_REGS_SIZE,
HIF_WR_SYNC_BYTE_INC,
NULL);
if (status) {
AR_DEBUG_PRINTF(ATH_DEBUG_ERR,
("Failed to update interrupt control registers err: %d\n", status));
}
return status;
}
int DevDisableInterrupts(struct ar6k_device *pDev)
{
struct ar6k_irq_enable_registers regs;
LOCK_AR6K(pDev);
pDev->IrqEnableRegisters.int_status_enable = 0;
pDev->IrqEnableRegisters.cpu_int_status_enable = 0;
pDev->IrqEnableRegisters.error_status_enable = 0;
pDev->IrqEnableRegisters.counter_int_status_enable = 0;
memcpy(&regs,&pDev->IrqEnableRegisters,AR6K_IRQ_ENABLE_REGS_SIZE);
UNLOCK_AR6K(pDev);
return HIFReadWrite(pDev->HIFDevice,
INT_STATUS_ENABLE_ADDRESS,
&regs.int_status_enable,
AR6K_IRQ_ENABLE_REGS_SIZE,
HIF_WR_SYNC_BYTE_INC,
NULL);
}
int DevUnmaskInterrupts(struct ar6k_device *pDev)
{
int IntStatus = 0;
DevDisableInterrupts(pDev);
#ifdef THREAD_X
IntStatus = DevEnableInterrupts(pDev);
HIFUnMaskInterrupt(pDev->HIFDevice);
#else
HIFUnMaskInterrupt(pDev->HIFDevice);
IntStatus = DevEnableInterrupts(pDev);
#endif
return IntStatus;
}
int DevMaskInterrupts(struct ar6k_device *pDev)
{
HIFMaskInterrupt(pDev->HIFDevice);
return DevDisableInterrupts(pDev);
}
static void DevDoEnableDisableRecvAsyncHandler(void *Context, struct htc_packet *pPacket)
{
struct ar6k_device *pDev = (struct ar6k_device *)Context;
AR_DEBUG_PRINTF(ATH_DEBUG_IRQ,("+DevDoEnableDisableRecvAsyncHandler: (dev: 0x%lX)\n", (unsigned long)pDev));
if (pPacket->Status) {
AR_DEBUG_PRINTF(ATH_DEBUG_ERR,
(" Failed to disable receiver, status:%d \n", pPacket->Status));
}
AR6KFreeIOPacket(pDev,pPacket);
AR_DEBUG_PRINTF(ATH_DEBUG_IRQ,("-DevDoEnableDisableRecvAsyncHandler \n"));
}
static int DevDoEnableDisableRecvOverride(struct ar6k_device *pDev, bool EnableRecv, bool AsyncMode)
{
int status = 0;
struct htc_packet *pIOPacket = NULL;
AR_DEBUG_PRINTF(ATH_DEBUG_TRC,("DevDoEnableDisableRecvOverride: Enable:%d Mode:%d\n",
EnableRecv,AsyncMode));
do {
if (AsyncMode) {
pIOPacket = AR6KAllocIOPacket(pDev);
if (NULL == pIOPacket) {
status = A_NO_MEMORY;
A_ASSERT(false);
break;
}
pIOPacket->Completion = DevDoEnableDisableRecvAsyncHandler;
pIOPacket->pContext = pDev;
status = pDev->HifMaskUmaskRecvEvent(pDev->HIFDevice,
EnableRecv ? HIF_UNMASK_RECV : HIF_MASK_RECV,
pIOPacket);
break;
}
status = pDev->HifMaskUmaskRecvEvent(pDev->HIFDevice,
EnableRecv ? HIF_UNMASK_RECV : HIF_MASK_RECV,
NULL);
} while (false);
if (status && (pIOPacket != NULL)) {
AR6KFreeIOPacket(pDev,pIOPacket);
}
return status;
}
static int DevDoEnableDisableRecvNormal(struct ar6k_device *pDev, bool EnableRecv, bool AsyncMode)
{
int status = 0;
struct htc_packet *pIOPacket = NULL;
struct ar6k_irq_enable_registers regs;
LOCK_AR6K(pDev);
if (EnableRecv) {
pDev->IrqEnableRegisters.int_status_enable |= INT_STATUS_ENABLE_MBOX_DATA_SET(0x01);
} else {
pDev->IrqEnableRegisters.int_status_enable &= ~INT_STATUS_ENABLE_MBOX_DATA_SET(0x01);
}
memcpy(&regs,&pDev->IrqEnableRegisters,AR6K_IRQ_ENABLE_REGS_SIZE);
UNLOCK_AR6K(pDev);
do {
if (AsyncMode) {
pIOPacket = AR6KAllocIOPacket(pDev);
if (NULL == pIOPacket) {
status = A_NO_MEMORY;
A_ASSERT(false);
break;
}
memcpy(pIOPacket->pBuffer,&regs,AR6K_IRQ_ENABLE_REGS_SIZE);
pIOPacket->Completion = DevDoEnableDisableRecvAsyncHandler;
pIOPacket->pContext = pDev;
HIFReadWrite(pDev->HIFDevice,
INT_STATUS_ENABLE_ADDRESS,
pIOPacket->pBuffer,
AR6K_IRQ_ENABLE_REGS_SIZE,
HIF_WR_ASYNC_BYTE_INC,
pIOPacket);
break;
}
status = HIFReadWrite(pDev->HIFDevice,
INT_STATUS_ENABLE_ADDRESS,
&regs.int_status_enable,
AR6K_IRQ_ENABLE_REGS_SIZE,
HIF_WR_SYNC_BYTE_INC,
NULL);
} while (false);
if (status && (pIOPacket != NULL)) {
AR6KFreeIOPacket(pDev,pIOPacket);
}
return status;
}
int DevStopRecv(struct ar6k_device *pDev, bool AsyncMode)
{
if (NULL == pDev->HifMaskUmaskRecvEvent) {
return DevDoEnableDisableRecvNormal(pDev,false,AsyncMode);
} else {
return DevDoEnableDisableRecvOverride(pDev,false,AsyncMode);
}
}
int DevEnableRecv(struct ar6k_device *pDev, bool AsyncMode)
{
if (NULL == pDev->HifMaskUmaskRecvEvent) {
return DevDoEnableDisableRecvNormal(pDev,true,AsyncMode);
} else {
return DevDoEnableDisableRecvOverride(pDev,true,AsyncMode);
}
}
int DevWaitForPendingRecv(struct ar6k_device *pDev,u32 TimeoutInMs,bool *pbIsRecvPending)
{
int status = 0;
u8 host_int_status = 0x0;
u32 counter = 0x0;
if(TimeoutInMs < 100)
{
TimeoutInMs = 100;
}
counter = TimeoutInMs / 100;
do
{
status = HIFReadWrite(pDev->HIFDevice,
HOST_INT_STATUS_ADDRESS,
&host_int_status,
sizeof(u8),
HIF_RD_SYNC_BYTE_INC,
NULL);
if (status)
{
AR_DEBUG_PRINTF(ATH_LOG_ERR,("DevWaitForPendingRecv:Read HOST_INT_STATUS_ADDRESS Failed 0x%X\n",status));
break;
}
host_int_status = !status ? (host_int_status & (1 << 0)):0;
if(!host_int_status)
{
status = 0;
*pbIsRecvPending = false;
break;
}
else
{
*pbIsRecvPending = true;
}
A_MDELAY(100);
counter--;
}while(counter);
return status;
}
void DevDumpRegisters(struct ar6k_device *pDev,
struct ar6k_irq_proc_registers *pIrqProcRegs,
struct ar6k_irq_enable_registers *pIrqEnableRegs)
{
AR_DEBUG_PRINTF(ATH_DEBUG_ANY, ("\n<------- Register Table -------->\n"));
if (pIrqProcRegs != NULL) {
AR_DEBUG_PRINTF(ATH_DEBUG_ANY,
("Host Int Status: 0x%x\n",pIrqProcRegs->host_int_status));
AR_DEBUG_PRINTF(ATH_DEBUG_ANY,
("CPU Int Status: 0x%x\n",pIrqProcRegs->cpu_int_status));
AR_DEBUG_PRINTF(ATH_DEBUG_ANY,
("Error Int Status: 0x%x\n",pIrqProcRegs->error_int_status));
AR_DEBUG_PRINTF(ATH_DEBUG_ANY,
("Counter Int Status: 0x%x\n",pIrqProcRegs->counter_int_status));
AR_DEBUG_PRINTF(ATH_DEBUG_ANY,
("Mbox Frame: 0x%x\n",pIrqProcRegs->mbox_frame));
AR_DEBUG_PRINTF(ATH_DEBUG_ANY,
("Rx Lookahead Valid: 0x%x\n",pIrqProcRegs->rx_lookahead_valid));
AR_DEBUG_PRINTF(ATH_DEBUG_ANY,
("Rx Lookahead 0: 0x%x\n",pIrqProcRegs->rx_lookahead[0]));
AR_DEBUG_PRINTF(ATH_DEBUG_ANY,
("Rx Lookahead 1: 0x%x\n",pIrqProcRegs->rx_lookahead[1]));
if (pDev->MailBoxInfo.GMboxAddress != 0) {
AR_DEBUG_PRINTF(ATH_DEBUG_ANY,
("GMBOX Host Int Status 2: 0x%x\n",pIrqProcRegs->host_int_status2));
AR_DEBUG_PRINTF(ATH_DEBUG_ANY,
("GMBOX RX Avail: 0x%x\n",pIrqProcRegs->gmbox_rx_avail));
AR_DEBUG_PRINTF(ATH_DEBUG_ANY,
("GMBOX lookahead alias 0: 0x%x\n",pIrqProcRegs->rx_gmbox_lookahead_alias[0]));
AR_DEBUG_PRINTF(ATH_DEBUG_ANY,
("GMBOX lookahead alias 1: 0x%x\n",pIrqProcRegs->rx_gmbox_lookahead_alias[1]));
}
}
if (pIrqEnableRegs != NULL) {
AR_DEBUG_PRINTF(ATH_DEBUG_ANY,
("Int Status Enable: 0x%x\n",pIrqEnableRegs->int_status_enable));
AR_DEBUG_PRINTF(ATH_DEBUG_ANY,
("Counter Int Status Enable: 0x%x\n",pIrqEnableRegs->counter_int_status_enable));
}
AR_DEBUG_PRINTF(ATH_DEBUG_ANY, ("<------------------------------->\n"));
}
static struct hif_scatter_req *DevAllocScatterReq(struct hif_device *Context)
{
struct dl_list *pItem;
struct ar6k_device *pDev = (struct ar6k_device *)Context;
LOCK_AR6K(pDev);
pItem = DL_ListRemoveItemFromHead(&pDev->ScatterReqHead);
UNLOCK_AR6K(pDev);
if (pItem != NULL) {
return A_CONTAINING_STRUCT(pItem, struct hif_scatter_req, ListLink);
}
return NULL;
}
static void DevFreeScatterReq(struct hif_device *Context, struct hif_scatter_req *pReq)
{
struct ar6k_device *pDev = (struct ar6k_device *)Context;
LOCK_AR6K(pDev);
DL_ListInsertTail(&pDev->ScatterReqHead, &pReq->ListLink);
UNLOCK_AR6K(pDev);
}
int DevCopyScatterListToFromDMABuffer(struct hif_scatter_req *pReq, bool FromDMA)
{
u8 *pDMABuffer = NULL;
int i, remaining;
u32 length;
pDMABuffer = pReq->pScatterBounceBuffer;
if (pDMABuffer == NULL) {
A_ASSERT(false);
return A_EINVAL;
}
remaining = (int)pReq->TotalLength;
for (i = 0; i < pReq->ValidScatterEntries; i++) {
length = min((int)pReq->ScatterList[i].Length, remaining);
if (length != (int)pReq->ScatterList[i].Length) {
A_ASSERT(false);
return A_EINVAL;
}
if (FromDMA) {
memcpy(pReq->ScatterList[i].pBuffer, pDMABuffer , length);
} else {
memcpy(pDMABuffer, pReq->ScatterList[i].pBuffer, length);
}
pDMABuffer += length;
remaining -= length;
}
return 0;
}
static void DevReadWriteScatterAsyncHandler(void *Context, struct htc_packet *pPacket)
{
struct ar6k_device *pDev = (struct ar6k_device *)Context;
struct hif_scatter_req *pReq = (struct hif_scatter_req *)pPacket->pPktContext;
AR_DEBUG_PRINTF(ATH_DEBUG_RECV,("+DevReadWriteScatterAsyncHandler: (dev: 0x%lX)\n", (unsigned long)pDev));
pReq->CompletionStatus = pPacket->Status;
AR6KFreeIOPacket(pDev,pPacket);
pReq->CompletionRoutine(pReq);
AR_DEBUG_PRINTF(ATH_DEBUG_RECV,("-DevReadWriteScatterAsyncHandler \n"));
}
static int DevReadWriteScatter(struct hif_device *Context, struct hif_scatter_req *pReq)
{
struct ar6k_device *pDev = (struct ar6k_device *)Context;
int status = 0;
struct htc_packet *pIOPacket = NULL;
u32 request = pReq->Request;
do {
if (pReq->TotalLength > AR6K_MAX_TRANSFER_SIZE_PER_SCATTER) {
AR_DEBUG_PRINTF(ATH_DEBUG_ERR,
("Invalid length: %d \n", pReq->TotalLength));
break;
}
if (pReq->TotalLength == 0) {
A_ASSERT(false);
break;
}
if (request & HIF_ASYNCHRONOUS) {
pIOPacket = AR6KAllocIOPacket(pDev);
if (NULL == pIOPacket) {
status = A_NO_MEMORY;
break;
}
pIOPacket->pPktContext = pReq;
pIOPacket->Completion = DevReadWriteScatterAsyncHandler;
pIOPacket->pContext = pDev;
}
if (request & HIF_WRITE) {
if (pReq->Address == pDev->MailBoxInfo.MboxProp[HTC_MAILBOX].ExtendedAddress) {
pReq->Address += pDev->MailBoxInfo.MboxProp[HTC_MAILBOX].ExtendedSize - pReq->TotalLength;
}
}
status = HIFReadWrite(pDev->HIFDevice,
pReq->Address,
DEV_GET_VIRT_DMA_INFO(pReq)->pVirtDmaBuffer,
pReq->TotalLength,
request,
(request & HIF_ASYNCHRONOUS) ? pIOPacket : NULL);
} while (false);
if ((status != A_PENDING) && status && (request & HIF_ASYNCHRONOUS)) {
if (pIOPacket != NULL) {
AR6KFreeIOPacket(pDev,pIOPacket);
}
pReq->CompletionStatus = status;
pReq->CompletionRoutine(pReq);
status = 0;
}
return status;
}
static void DevCleanupVirtualScatterSupport(struct ar6k_device *pDev)
{
struct hif_scatter_req *pReq;
while (1) {
pReq = DevAllocScatterReq((struct hif_device *)pDev);
if (NULL == pReq) {
break;
}
kfree(pReq);
}
}
static int DevSetupVirtualScatterSupport(struct ar6k_device *pDev)
{
int status = 0;
int bufferSize, sgreqSize;
int i;
struct dev_scatter_dma_virtual_info *pVirtualInfo;
struct hif_scatter_req *pReq;
bufferSize = sizeof(struct dev_scatter_dma_virtual_info) +
2 * (A_GET_CACHE_LINE_BYTES()) + AR6K_MAX_TRANSFER_SIZE_PER_SCATTER;
sgreqSize = sizeof(struct hif_scatter_req) +
(AR6K_SCATTER_ENTRIES_PER_REQ - 1) * (sizeof(struct hif_scatter_item));
for (i = 0; i < AR6K_SCATTER_REQS; i++) {
pReq = (struct hif_scatter_req *)A_MALLOC(sgreqSize + bufferSize);
if (NULL == pReq) {
status = A_NO_MEMORY;
break;
}
A_MEMZERO(pReq, sgreqSize);
pVirtualInfo = (struct dev_scatter_dma_virtual_info *)((u8 *)pReq + sgreqSize);
A_MEMZERO(pVirtualInfo, sizeof(struct dev_scatter_dma_virtual_info));
pVirtualInfo->pVirtDmaBuffer = &pVirtualInfo->DataArea[0];
pVirtualInfo->pVirtDmaBuffer = A_ALIGN_TO_CACHE_LINE(pVirtualInfo->pVirtDmaBuffer);
pReq->HIFPrivate[0] = pVirtualInfo;
pReq->ScatterMethod = HIF_SCATTER_DMA_BOUNCE;
pReq->pScatterBounceBuffer = pVirtualInfo->pVirtDmaBuffer;
DevFreeScatterReq((struct hif_device *)pDev,pReq);
}
if (status) {
DevCleanupVirtualScatterSupport(pDev);
} else {
pDev->HifScatterInfo.pAllocateReqFunc = DevAllocScatterReq;
pDev->HifScatterInfo.pFreeReqFunc = DevFreeScatterReq;
pDev->HifScatterInfo.pReadWriteScatterFunc = DevReadWriteScatter;
if (pDev->MailBoxInfo.MboxBusIFType == MBOX_BUS_IF_SPI) {
AR_DEBUG_PRINTF(ATH_DEBUG_WARN, ("AR6K: SPI bus requires RX scatter limits\n"));
pDev->HifScatterInfo.MaxScatterEntries = AR6K_MIN_SCATTER_ENTRIES_PER_REQ;
pDev->HifScatterInfo.MaxTransferSizePerScatterReq = AR6K_MIN_TRANSFER_SIZE_PER_SCATTER;
} else {
pDev->HifScatterInfo.MaxScatterEntries = AR6K_SCATTER_ENTRIES_PER_REQ;
pDev->HifScatterInfo.MaxTransferSizePerScatterReq = AR6K_MAX_TRANSFER_SIZE_PER_SCATTER;
}
pDev->ScatterIsVirtual = true;
}
return status;
}
int DevCleanupMsgBundling(struct ar6k_device *pDev)
{
if(NULL != pDev)
{
DevCleanupVirtualScatterSupport(pDev);
}
return 0;
}
int DevSetupMsgBundling(struct ar6k_device *pDev, int MaxMsgsPerTransfer)
{
int status;
if (pDev->MailBoxInfo.Flags & HIF_MBOX_FLAG_NO_BUNDLING) {
AR_DEBUG_PRINTF(ATH_DEBUG_WARN, ("HIF requires bundling disabled\n"));
return A_ENOTSUP;
}
status = HIFConfigureDevice(pDev->HIFDevice,
HIF_CONFIGURE_QUERY_SCATTER_REQUEST_SUPPORT,
&pDev->HifScatterInfo,
sizeof(pDev->HifScatterInfo));
if (status) {
AR_DEBUG_PRINTF(ATH_DEBUG_WARN,
("AR6K: ** HIF layer does not support scatter requests (%d) \n",status));
status = DevSetupVirtualScatterSupport(pDev);
if (!status) {
AR_DEBUG_PRINTF(ATH_DEBUG_ANY,
("AR6K: virtual scatter transfers enabled (max scatter items:%d: maxlen:%d) \n",
DEV_GET_MAX_MSG_PER_BUNDLE(pDev), DEV_GET_MAX_BUNDLE_LENGTH(pDev)));
}
} else {
AR_DEBUG_PRINTF(ATH_DEBUG_ANY,
("AR6K: HIF layer supports scatter requests (max scatter items:%d: maxlen:%d) \n",
DEV_GET_MAX_MSG_PER_BUNDLE(pDev), DEV_GET_MAX_BUNDLE_LENGTH(pDev)));
}
if (!status) {
pDev->MaxRecvBundleSize = pDev->HifScatterInfo.MaxTransferSizePerScatterReq;
if (pDev->MailBoxInfo.MboxBusIFType == MBOX_BUS_IF_SPI) {
AR_DEBUG_PRINTF(ATH_DEBUG_WARN, ("AR6K : SPI bus requires TX bundling disabled\n"));
pDev->MaxSendBundleSize = 0;
} else {
if (pDev->MailBoxInfo.MboxProp[0].ExtendedAddress != 0) {
pDev->MaxSendBundleSize = pDev->MailBoxInfo.MboxProp[0].ExtendedSize;
} else {
pDev->MaxSendBundleSize = AR6K_LEGACY_MAX_WRITE_LENGTH;
}
if (pDev->MaxSendBundleSize > pDev->HifScatterInfo.MaxTransferSizePerScatterReq) {
pDev->MaxSendBundleSize = pDev->HifScatterInfo.MaxTransferSizePerScatterReq;
}
}
AR_DEBUG_PRINTF(ATH_DEBUG_ANY,
("AR6K: max recv: %d max send: %d \n",
DEV_GET_MAX_BUNDLE_RECV_LENGTH(pDev), DEV_GET_MAX_BUNDLE_SEND_LENGTH(pDev)));
}
return status;
}
int DevSubmitScatterRequest(struct ar6k_device *pDev, struct hif_scatter_req *pScatterReq, bool Read, bool Async)
{
int status;
if (Read) {
pScatterReq->Request = (Async) ? HIF_RD_ASYNC_BLOCK_FIX : HIF_RD_SYNC_BLOCK_FIX;
pScatterReq->Address = pDev->MailBoxInfo.MboxAddresses[HTC_MAILBOX];
A_ASSERT(pScatterReq->TotalLength <= (u32)DEV_GET_MAX_BUNDLE_RECV_LENGTH(pDev));
} else {
u32 mailboxWidth;
pScatterReq->Request = (Async) ? HIF_WR_ASYNC_BLOCK_INC : HIF_WR_SYNC_BLOCK_INC;
A_ASSERT(pScatterReq->TotalLength <= (u32)DEV_GET_MAX_BUNDLE_SEND_LENGTH(pDev));
if (pScatterReq->TotalLength > AR6K_LEGACY_MAX_WRITE_LENGTH) {
pScatterReq->Address = pDev->MailBoxInfo.MboxProp[HTC_MAILBOX].ExtendedAddress;
mailboxWidth = pDev->MailBoxInfo.MboxProp[HTC_MAILBOX].ExtendedSize;
} else {
pScatterReq->Address = pDev->MailBoxInfo.MboxAddresses[HTC_MAILBOX];
mailboxWidth = AR6K_LEGACY_MAX_WRITE_LENGTH;
}
if (!pDev->ScatterIsVirtual) {
pScatterReq->Address += (mailboxWidth - pScatterReq->TotalLength);
}
}
AR_DEBUG_PRINTF(ATH_DEBUG_RECV | ATH_DEBUG_SEND,
("DevSubmitScatterRequest, Entries: %d, Total Length: %d Mbox:0x%X (mode: %s : %s)\n",
pScatterReq->ValidScatterEntries,
pScatterReq->TotalLength,
pScatterReq->Address,
Async ? "ASYNC" : "SYNC",
(Read) ? "RD" : "WR"));
status = DEV_PREPARE_SCATTER_OPERATION(pScatterReq);
if (status) {
if (Async) {
pScatterReq->CompletionStatus = status;
pScatterReq->CompletionRoutine(pScatterReq);
return 0;
}
return status;
}
status = pDev->HifScatterInfo.pReadWriteScatterFunc(pDev->ScatterIsVirtual ? pDev : pDev->HIFDevice,
pScatterReq);
if (!Async) {
pScatterReq->CompletionStatus = status;
DEV_FINISH_SCATTER_OPERATION(pScatterReq);
} else {
if (status == A_PENDING) {
status = 0;
}
}
return status;
}
static void AssembleBufferList(struct buffer_proc_list *pList)
{
u8 *pBuffer = g_Buffer;
#if BUFFER_PROC_LIST_DEPTH < 4
#error "Buffer processing list depth is not deep enough!!"
#endif
PUSH_BUFF_PROC_ENTRY(pList,BUFFER1,pBuffer);
PUSH_BUFF_PROC_ENTRY(pList,BUFFER2,pBuffer);
PUSH_BUFF_PROC_ENTRY(pList,BUFFER3,pBuffer);
PUSH_BUFF_PROC_ENTRY(pList,BUFFER4,pBuffer);
}
static void InitBuffers(bool Zero)
{
u16 *pBuffer16 = (u16 *)g_Buffer;
int i;
for (i = 0; i < (TOTAL_BYTES / 2) ; i++) {
if (!Zero) {
pBuffer16[i] = (u16)i;
} else {
pBuffer16[i] = 0;
}
}
}
static bool CheckOneBuffer(u16 *pBuffer16, int Length)
{
int i;
u16 startCount;
bool success = true;
startCount = pBuffer16[0];
startCount = ~startCount;
for (i = 0; i < (Length / 2) ; i++,startCount++) {
if ((u16)pBuffer16[i] != (u16)~startCount) {
success = false;
AR_DEBUG_PRINTF(ATH_DEBUG_ERR, ("Invalid Data Got:0x%X, Expecting:0x%X (offset:%d, total:%d) \n",
pBuffer16[i], ((u16)~startCount), i, Length));
AR_DEBUG_PRINTF(ATH_DEBUG_ERR, ("0x%X 0x%X 0x%X 0x%X \n",
pBuffer16[i], pBuffer16[i + 1], pBuffer16[i + 2],pBuffer16[i+3]));
break;
}
}
return success;
}
static bool CheckBuffers(void)
{
int i;
bool success = true;
struct buffer_proc_list checkList[BUFFER_PROC_LIST_DEPTH];
AssembleBufferList(checkList);
for (i = 0; i < BUFFER_PROC_LIST_DEPTH ; i++) {
success = CheckOneBuffer((u16 *)checkList[i].pBuffer, checkList[i].length);
if (!success) {
AR_DEBUG_PRINTF(ATH_DEBUG_ERR, ("Buffer : 0x%X, Length:%d failed verify \n",
(u32)checkList[i].pBuffer, checkList[i].length));
break;
}
}
return success;
}
static u16 GetEndMarker(void)
{
u8 *pBuffer;
struct buffer_proc_list checkList[BUFFER_PROC_LIST_DEPTH];
InitBuffers(FILL_COUNTING);
AssembleBufferList(checkList);
pBuffer = &(checkList[BUFFER_PROC_LIST_DEPTH - 1].pBuffer[(checkList[BUFFER_PROC_LIST_DEPTH - 1].length) - 2]);
return (u16)pBuffer[0] | ((u16)pBuffer[1] << 8);
}
static int SendBuffers(struct ar6k_device *pDev, int mbox)
{
int status = 0;
u32 request = HIF_WR_SYNC_BLOCK_INC;
struct buffer_proc_list sendList[BUFFER_PROC_LIST_DEPTH];
int i;
int totalBytes = 0;
int paddedLength;
int totalwPadding = 0;
AR_DEBUG_PRINTF(ATH_PRINT_OUT_ZONE, ("Sending buffers on mailbox : %d \n",mbox));
InitBuffers(FILL_COUNTING);
AssembleBufferList(sendList);
for (i = 0; i < BUFFER_PROC_LIST_DEPTH; i++) {
paddedLength = (sendList[i].length + (g_BlockSizes[mbox] - 1)) &
(~(g_BlockSizes[mbox] - 1));
status = HIFReadWrite(pDev->HIFDevice,
g_MailboxAddrs[mbox],
sendList[i].pBuffer,
paddedLength,
request,
NULL);
if (status) {
break;
}
totalBytes += sendList[i].length;
totalwPadding += paddedLength;
}
AR_DEBUG_PRINTF(ATH_PRINT_OUT_ZONE, ("Sent %d bytes (%d padded bytes) to mailbox : %d \n",totalBytes,totalwPadding,mbox));
return status;
}
static int GetCredits(struct ar6k_device *pDev, int mbox, int *pCredits)
{
int status = 0;
int timeout = TEST_CREDITS_RECV_TIMEOUT;
u8 credits = 0;
u32 address;
while (true) {
address = COUNT_DEC_ADDRESS + (AR6K_MAILBOXES + mbox) * 4;
status = HIFReadWrite(pDev->HIFDevice, address, &credits, sizeof(credits),
HIF_RD_SYNC_BYTE_FIX, NULL);
if (status) {
AR_DEBUG_PRINTF(ATH_DEBUG_ERR,
("Unable to decrement the command credit count register (mbox=%d)\n",mbox));
status = A_ERROR;
break;
}
if (credits) {
break;
}
timeout--;
if (timeout <= 0) {
AR_DEBUG_PRINTF(ATH_DEBUG_ERR,
(" Timeout reading credit registers (mbox=%d, address:0x%X) \n",mbox,address));
status = A_ERROR;
break;
}
A_MDELAY(1000);
}
if (status == 0) {
*pCredits = credits;
}
return status;
}
static int RecvBuffers(struct ar6k_device *pDev, int mbox)
{
int status = 0;
u32 request = HIF_RD_SYNC_BLOCK_INC;
struct buffer_proc_list recvList[BUFFER_PROC_LIST_DEPTH];
int curBuffer;
int credits;
int i;
int totalBytes = 0;
int paddedLength;
int totalwPadding = 0;
AR_DEBUG_PRINTF(ATH_PRINT_OUT_ZONE, ("Waiting for buffers on mailbox : %d \n",mbox));
InitBuffers(FILL_ZERO);
AssembleBufferList(recvList);
curBuffer = 0;
while (curBuffer < BUFFER_PROC_LIST_DEPTH) {
status = GetCredits(pDev, mbox, &credits);
if (status) {
break;
}
AR_DEBUG_PRINTF(ATH_PRINT_OUT_ZONE, ("Got %d messages on mailbox : %d \n",credits, mbox));
for (i = 0; i < credits; i++) {
A_ASSERT(curBuffer < BUFFER_PROC_LIST_DEPTH);
paddedLength = (recvList[curBuffer].length + (g_BlockSizes[mbox] - 1)) &
(~(g_BlockSizes[mbox] - 1));
status = HIFReadWrite(pDev->HIFDevice,
g_MailboxAddrs[mbox],
recvList[curBuffer].pBuffer,
paddedLength,
request,
NULL);
if (status) {
AR_DEBUG_PRINTF(ATH_DEBUG_ERR, ("Failed to read %d bytes on mailbox:%d : address:0x%X \n",
recvList[curBuffer].length, mbox, g_MailboxAddrs[mbox]));
break;
}
totalwPadding += paddedLength;
totalBytes += recvList[curBuffer].length;
curBuffer++;
}
if (status) {
break;
}
credits = 0;
}
if (totalBytes != TEST_BYTES) {
A_ASSERT(false);
} else {
AR_DEBUG_PRINTF(ATH_PRINT_OUT_ZONE, ("Got all buffers on mbox:%d total recv :%d (w/Padding : %d) \n",
mbox, totalBytes, totalwPadding));
}
return status;
}
static int DoOneMboxHWTest(struct ar6k_device *pDev, int mbox)
{
int status;
do {
status = SendBuffers(pDev,mbox);
if (status) {
AR_DEBUG_PRINTF(ATH_DEBUG_ERR, ("Sending buffers Failed : %d mbox:%d\n",status,mbox));
break;
}
status = RecvBuffers(pDev, mbox);
if (status) {
AR_DEBUG_PRINTF(ATH_DEBUG_ERR, ("Recv buffers Failed : %d mbox:%d\n",status,mbox));
break;
}
if (!CheckBuffers()) {
AR_DEBUG_PRINTF(ATH_DEBUG_ERR, ("Buffer Verify Failed : mbox:%d\n",mbox));
status = A_ERROR;
break;
}
AR_DEBUG_PRINTF(ATH_PRINT_OUT_ZONE, (" Send/Recv success! mailbox : %d \n",mbox));
} while (false);
return status;
}
int DoMboxHWTest(struct ar6k_device *pDev)
{
int i;
int status;
int credits = 0;
u8 params[4];
int numBufs;
int bufferSize;
u16 temp;
AR_DEBUG_PRINTF(ATH_PRINT_OUT_ZONE, (" DoMboxHWTest START - \n"));
do {
status = HIFConfigureDevice(pDev->HIFDevice, HIF_DEVICE_GET_MBOX_ADDR,
g_MailboxAddrs, sizeof(g_MailboxAddrs));
if (status) {
A_ASSERT(false);
break;
}
status = HIFConfigureDevice(pDev->HIFDevice, HIF_DEVICE_GET_MBOX_BLOCK_SIZE,
g_BlockSizes, sizeof(g_BlockSizes));
if (status) {
A_ASSERT(false);
break;
}
g_BlockSizes[0] = g_BlockSizes[1];
AR_DEBUG_PRINTF(ATH_PRINT_OUT_ZONE, ("Block Size to use: %d \n",g_BlockSizes[0]));
if (g_BlockSizes[1] > BUFFER_BLOCK_PAD) {
AR_DEBUG_PRINTF(ATH_PRINT_OUT_ZONE, ("%d Block size is too large for buffer pad %d\n",
g_BlockSizes[1], BUFFER_BLOCK_PAD));
break;
}
AR_DEBUG_PRINTF(ATH_PRINT_OUT_ZONE, ("Waiting for target.... \n"));
status = GetCredits(pDev, 0, &credits);
if (status) {
AR_DEBUG_PRINTF(ATH_DEBUG_ERR, ("Failed to wait for target ready \n"));
break;
}
AR_DEBUG_PRINTF(ATH_PRINT_OUT_ZONE, ("Target is ready ...\n"));
status = HIFReadWrite(pDev->HIFDevice,
SCRATCH_ADDRESS,
params,
4,
HIF_RD_SYNC_BYTE_INC,
NULL);
if (status) {
AR_DEBUG_PRINTF(ATH_DEBUG_ERR, ("Failed to wait get parameters \n"));
break;
}
numBufs = params[0];
bufferSize = (int)(((u16)params[2] << 8) | (u16)params[1]);
AR_DEBUG_PRINTF(ATH_PRINT_OUT_ZONE,
("Target parameters: bufs per mailbox:%d, buffer size:%d bytes (total space: %d, minimum required space (w/padding): %d) \n",
numBufs, bufferSize, (numBufs * bufferSize), TOTAL_BYTES));
if ((numBufs * bufferSize) < TOTAL_BYTES) {
AR_DEBUG_PRINTF(ATH_DEBUG_ERR, ("Not Enough buffer space to run test! need:%d, got:%d \n",
TOTAL_BYTES, (numBufs*bufferSize)));
status = A_ERROR;
break;
}
temp = GetEndMarker();
status = HIFReadWrite(pDev->HIFDevice,
SCRATCH_ADDRESS + 4,
(u8 *)&temp,
2,
HIF_WR_SYNC_BYTE_INC,
NULL);
if (status) {
AR_DEBUG_PRINTF(ATH_DEBUG_ERR, ("Failed to write end marker \n"));
break;
}
AR_DEBUG_PRINTF(ATH_PRINT_OUT_ZONE, ("End Marker: 0x%X \n",temp));
temp = (u16)g_BlockSizes[1];
temp = temp - 1;
status = HIFReadWrite(pDev->HIFDevice,
SCRATCH_ADDRESS + 6,
(u8 *)&temp,
2,
HIF_WR_SYNC_BYTE_INC,
NULL);
if (status) {
AR_DEBUG_PRINTF(ATH_DEBUG_ERR, ("Failed to write block mask \n"));
break;
}
AR_DEBUG_PRINTF(ATH_PRINT_OUT_ZONE, ("Set Block Mask: 0x%X \n",temp));
for (i = 0; i < AR6K_MAILBOXES; i++) {
status = DoOneMboxHWTest(pDev, i);
if (status) {
break;
}
}
} while (false);
if (status == 0) {
AR_DEBUG_PRINTF(ATH_PRINT_OUT_ZONE, (" DoMboxHWTest DONE - SUCCESS! - \n"));
} else {
AR_DEBUG_PRINTF(ATH_PRINT_OUT_ZONE, (" DoMboxHWTest DONE - FAILED! - \n"));
}
return A_ERROR;
}
