int DevRWCompletionHandler(void *context, int status)
{
struct htc_packet *pPacket = (struct htc_packet *)context;
AR_DEBUG_PRINTF(ATH_DEBUG_RECV,
("+DevRWCompletionHandler (Pkt:0x%lX) , Status: %d \n",
(unsigned long)pPacket,
status));
COMPLETE_HTC_PACKET(pPacket,status);
AR_DEBUG_PRINTF(ATH_DEBUG_RECV,
("-DevRWCompletionHandler\n"));
return 0;
}
int DevPollMboxMsgRecv(struct ar6k_device *pDev,
u32 *pLookAhead,
int TimeoutMS)
{
int status = 0;
int timeout = TimeoutMS/DELAY_PER_INTERVAL_MS;
A_ASSERT(timeout > 0);
AR_DEBUG_PRINTF(ATH_DEBUG_RECV,("+DevPollMboxMsgRecv \n"));
while (true) {
if (pDev->GetPendingEventsFunc != NULL) {
struct hif_pending_events_info events;
#ifdef THREAD_X
events.Polling =1;
#endif
status = pDev->GetPendingEventsFunc(pDev->HIFDevice,
&events,
NULL);
if (status)
{
AR_DEBUG_PRINTF(ATH_DEBUG_ERR,("Failed to get pending events \n"));
break;
}
if (events.Events & HIF_RECV_MSG_AVAIL)
{
*pLookAhead = events.LookAhead;
break;
}
} else {
status = HIFReadWrite(pDev->HIFDevice,
HOST_INT_STATUS_ADDRESS,
(u8 *)&pDev->IrqProcRegisters,
AR6K_IRQ_PROC_REGS_SIZE,
HIF_RD_SYNC_BYTE_INC,
NULL);
if (status){
AR_DEBUG_PRINTF(ATH_DEBUG_ERR,("Failed to read register table \n"));
break;
}
if (pDev->IrqProcRegisters.host_int_status & (1 << HTC_MAILBOX)) {
if (pDev->IrqProcRegisters.rx_lookahead_valid & (1 << HTC_MAILBOX))
{
*pLookAhead = pDev->IrqProcRegisters.rx_lookahead[HTC_MAILBOX];
break;
}
}
}
timeout--;
if (timeout <= 0) {
AR_DEBUG_PRINTF(ATH_DEBUG_ERR, (" Timeout waiting for recv message \n"));
status = A_ERROR;
if ( pDev->IrqProcRegisters.counter_int_status & AR6K_TARGET_DEBUG_INTR_MASK) {
DevServiceDebugInterrupt(pDev);
}
break;
}
A_MDELAY(DELAY_PER_INTERVAL_MS);
AR_DEBUG_PRINTF(ATH_DEBUG_RECV,(" Retry Mbox Poll : %d \n",timeout));
}
AR_DEBUG_PRINTF(ATH_DEBUG_RECV,("-DevPollMboxMsgRecv \n"));
return status;
}
static int DevServiceCPUInterrupt(struct ar6k_device *pDev)
{
int status;
u8 cpu_int_status;
u8 regBuffer[4];
AR_DEBUG_PRINTF(ATH_DEBUG_IRQ, ("CPU Interrupt\n"));
cpu_int_status = pDev->IrqProcRegisters.cpu_int_status &
pDev->IrqEnableRegisters.cpu_int_status_enable;
A_ASSERT(cpu_int_status);
AR_DEBUG_PRINTF(ATH_DEBUG_IRQ,
("Valid interrupt source(s) in CPU_INT_STATUS: 0x%x\n",
cpu_int_status));
pDev->IrqProcRegisters.cpu_int_status &= ~cpu_int_status;
regBuffer[0] = cpu_int_status;
regBuffer[1] = 0;
regBuffer[2] = 0;
regBuffer[3] = 0;
status = HIFReadWrite(pDev->HIFDevice,
CPU_INT_STATUS_ADDRESS,
regBuffer,
4,
HIF_WR_SYNC_BYTE_FIX,
NULL);
A_ASSERT(status == 0);
return status;
}
static int DevServiceErrorInterrupt(struct ar6k_device *pDev)
{
int status;
u8 error_int_status;
u8 regBuffer[4];
AR_DEBUG_PRINTF(ATH_DEBUG_IRQ, ("Error Interrupt\n"));
error_int_status = pDev->IrqProcRegisters.error_int_status & 0x0F;
A_ASSERT(error_int_status);
AR_DEBUG_PRINTF(ATH_DEBUG_IRQ,
("Valid interrupt source(s) in ERROR_INT_STATUS: 0x%x\n",
error_int_status));
if (ERROR_INT_STATUS_WAKEUP_GET(error_int_status)) {
AR_DEBUG_PRINTF(ATH_DEBUG_IRQ, ("Error : Wakeup\n"));
}
if (ERROR_INT_STATUS_RX_UNDERFLOW_GET(error_int_status)) {
AR_DEBUG_PRINTF(ATH_DEBUG_ERR, ("Error : Rx Underflow\n"));
}
if (ERROR_INT_STATUS_TX_OVERFLOW_GET(error_int_status)) {
AR_DEBUG_PRINTF(ATH_DEBUG_ERR, ("Error : Tx Overflow\n"));
}
pDev->IrqProcRegisters.error_int_status &= ~error_int_status;
regBuffer[0] = error_int_status;
regBuffer[1] = 0;
regBuffer[2] = 0;
regBuffer[3] = 0;
status = HIFReadWrite(pDev->HIFDevice,
ERROR_INT_STATUS_ADDRESS,
regBuffer,
4,
HIF_WR_SYNC_BYTE_FIX,
NULL);
A_ASSERT(status == 0);
return status;
}
static int DevServiceDebugInterrupt(struct ar6k_device *pDev)
{
u32 dummy;
int status;
AR_DEBUG_PRINTF(ATH_DEBUG_ERR, ("Target debug interrupt\n"));
if (pDev->TargetFailureCallback != NULL) {
pDev->TargetFailureCallback(pDev->HTCContext);
}
if (pDev->GMboxEnabled) {
DevNotifyGMboxTargetFailure(pDev);
}
status = HIFReadWrite(pDev->HIFDevice,
COUNT_DEC_ADDRESS,
(u8 *)&dummy,
4,
HIF_RD_SYNC_BYTE_INC,
NULL);
A_ASSERT(status == 0);
return status;
}
static int DevServiceCounterInterrupt(struct ar6k_device *pDev)
{
u8 counter_int_status;
AR_DEBUG_PRINTF(ATH_DEBUG_IRQ, ("Counter Interrupt\n"));
counter_int_status = pDev->IrqProcRegisters.counter_int_status &
pDev->IrqEnableRegisters.counter_int_status_enable;
AR_DEBUG_PRINTF(ATH_DEBUG_IRQ,
("Valid interrupt source(s) in COUNTER_INT_STATUS: 0x%x\n",
counter_int_status));
if (counter_int_status & AR6K_TARGET_DEBUG_INTR_MASK) {
return DevServiceDebugInterrupt(pDev);
}
return 0;
}
static void DevGetEventAsyncHandler(void *Context, struct htc_packet *pPacket)
{
struct ar6k_device *pDev = (struct ar6k_device *)Context;
u32 lookAhead = 0;
bool otherInts = false;
AR_DEBUG_PRINTF(ATH_DEBUG_IRQ,("+DevGetEventAsyncHandler: (dev: 0x%lX)\n", (unsigned long)pDev));
do {
if (pPacket->Status) {
AR_DEBUG_PRINTF(ATH_DEBUG_ERR,
(" GetEvents I/O request failed, status:%d \n", pPacket->Status));
break;
}
if (pDev->GetPendingEventsFunc != NULL) {
struct hif_pending_events_info *pEvents = (struct hif_pending_events_info *)pPacket->pBuffer;
if (pEvents->Events & HIF_RECV_MSG_AVAIL) {
lookAhead = pEvents->LookAhead;
if (0 == lookAhead) {
AR_DEBUG_PRINTF(ATH_DEBUG_ERR,(" DevGetEventAsyncHandler1, lookAhead is zero! \n"));
}
}
if (pEvents->Events & HIF_OTHER_EVENTS) {
otherInts = true;
}
} else {
struct ar6k_irq_proc_registers *pReg = (struct ar6k_irq_proc_registers *)pPacket->pBuffer;
u8 host_int_status;
host_int_status = pReg->host_int_status & pDev->IrqEnableRegisters.int_status_enable;
if (host_int_status & (1 << HTC_MAILBOX)) {
host_int_status &= ~(1 << HTC_MAILBOX);
if (pReg->rx_lookahead_valid & (1 << HTC_MAILBOX)) {
lookAhead = pReg->rx_lookahead[HTC_MAILBOX];
if (0 == lookAhead) {
AR_DEBUG_PRINTF(ATH_DEBUG_ERR,(" DevGetEventAsyncHandler2, lookAhead is zero! \n"));
}
}
}
if (host_int_status) {
otherInts = true;
}
}
if (otherInts || (lookAhead == 0)) {
AR_DEBUG_PRINTF(ATH_DEBUG_IRQ,
(" Acking interrupt from DevGetEventAsyncHandler (otherints:%d, lookahead:0x%X)\n",
otherInts, lookAhead));
HIFAckInterrupt(pDev->HIFDevice);
} else {
int fetched = 0;
int status;
AR_DEBUG_PRINTF(ATH_DEBUG_IRQ,
(" DevGetEventAsyncHandler : detected another message, lookahead :0x%X \n",
lookAhead));
status = pDev->MessagePendingCallback(pDev->HTCContext, &lookAhead, 1, NULL, &fetched);
if (!status && !fetched) {
AR_DEBUG_PRINTF(ATH_DEBUG_IRQ,("MessagePendingCallback did not pull any messages, force-ack \n"));
DevAsyncIrqProcessComplete(pDev);
}
}
} while (false);
AR6KFreeIOPacket(pDev,pPacket);
AR_DEBUG_PRINTF(ATH_DEBUG_IRQ,("-DevGetEventAsyncHandler \n"));
}
int DevCheckPendingRecvMsgsAsync(void *context)
{
struct ar6k_device *pDev = (struct ar6k_device *)context;
int status = 0;
struct htc_packet *pIOPacket;
AR_DEBUG_PRINTF(ATH_DEBUG_IRQ,("+DevCheckPendingRecvMsgsAsync: (dev: 0x%lX)\n", (unsigned long)pDev));
do {
if (HIF_DEVICE_IRQ_SYNC_ONLY == pDev->HifIRQProcessingMode) {
break;
}
if (pDev->RecheckIRQStatusCnt == 0) {
AR_DEBUG_PRINTF(ATH_DEBUG_IRQ,("Bypassing IRQ Status re-check, re-acking HIF interrupts\n"));
HIFAckInterrupt(pDev->HIFDevice);
break;
}
pIOPacket = AR6KAllocIOPacket(pDev);
if (NULL == pIOPacket) {
status = A_NO_MEMORY;
A_ASSERT(false);
break;
}
pIOPacket->Completion = DevGetEventAsyncHandler;
pIOPacket->pContext = pDev;
if (pDev->GetPendingEventsFunc) {
status = pDev->GetPendingEventsFunc(pDev->HIFDevice,
(struct hif_pending_events_info *)pIOPacket->pBuffer,
pIOPacket);
} else {
status = HIFReadWrite(pDev->HIFDevice,
HOST_INT_STATUS_ADDRESS,
pIOPacket->pBuffer,
AR6K_IRQ_PROC_REGS_SIZE,
HIF_RD_ASYNC_BYTE_INC,
pIOPacket);
}
AR_DEBUG_PRINTF(ATH_DEBUG_IRQ,(" Async IO issued to get interrupt status...\n"));
} while (false);
AR_DEBUG_PRINTF(ATH_DEBUG_IRQ,("-DevCheckPendingRecvMsgsAsync \n"));
return status;
}
void DevAsyncIrqProcessComplete(struct ar6k_device *pDev)
{
AR_DEBUG_PRINTF(ATH_DEBUG_IRQ,("DevAsyncIrqProcessComplete - forcing HIF IRQ ACK \n"));
HIFAckInterrupt(pDev->HIFDevice);
}
static int ProcessPendingIRQs(struct ar6k_device *pDev, bool *pDone, bool *pASyncProcessing)
{
int status = 0;
u8 host_int_status = 0;
u32 lookAhead = 0;
AR_DEBUG_PRINTF(ATH_DEBUG_IRQ,("+ProcessPendingIRQs: (dev: 0x%lX)\n", (unsigned long)pDev));
do {
if (pDev->IrqEnableRegisters.int_status_enable == 0) {
break;
}
if (pDev->GetPendingEventsFunc != NULL) {
struct hif_pending_events_info events;
#ifdef THREAD_X
events.Polling= 0;
#endif
status = pDev->GetPendingEventsFunc(pDev->HIFDevice,
&events,
NULL);
if (status) {
break;
}
if (events.Events & HIF_RECV_MSG_AVAIL) {
lookAhead = events.LookAhead;
if (0 == lookAhead) {
AR_DEBUG_PRINTF(ATH_DEBUG_ERR,(" ProcessPendingIRQs1 lookAhead is zero! \n"));
}
}
if (!(events.Events & HIF_OTHER_EVENTS) ||
!(pDev->IrqEnableRegisters.int_status_enable & OTHER_INTS_ENABLED)) {
break;
}
}
#ifdef CONFIG_MMC_SDHCI_S3C
pDev->IrqProcRegisters.host_int_status = 0;
pDev->IrqProcRegisters.rx_lookahead_valid = 0;
pDev->IrqProcRegisters.host_int_status2 = 0;
pDev->IrqProcRegisters.rx_lookahead[0] = 0;
pDev->IrqProcRegisters.rx_lookahead[1] = 0xaaa5555;
#endif
status = HIFReadWrite(pDev->HIFDevice,
HOST_INT_STATUS_ADDRESS,
(u8 *)&pDev->IrqProcRegisters,
AR6K_IRQ_PROC_REGS_SIZE,
HIF_RD_SYNC_BYTE_INC,
NULL);
if (status) {
break;
}
#ifdef ATH_DEBUG_MODULE
if (AR_DEBUG_LVL_CHECK(ATH_DEBUG_IRQ)) {
DevDumpRegisters(pDev,
&pDev->IrqProcRegisters,
&pDev->IrqEnableRegisters);
}
#endif
host_int_status = pDev->IrqProcRegisters.host_int_status &
pDev->IrqEnableRegisters.int_status_enable;
if (NULL == pDev->GetPendingEventsFunc) {
if (host_int_status & (1 << HTC_MAILBOX)) {
host_int_status &= ~(1 << HTC_MAILBOX);
if (pDev->IrqProcRegisters.rx_lookahead_valid & (1 << HTC_MAILBOX)) {
lookAhead = pDev->IrqProcRegisters.rx_lookahead[HTC_MAILBOX];
if (0 == lookAhead) {
AR_DEBUG_PRINTF(ATH_DEBUG_ERR,(" ProcessPendingIRQs2, lookAhead is zero! \n"));
}
}
}
} else {
host_int_status &= ~(1 << HTC_MAILBOX);
}
if (pDev->GMboxEnabled) {
status = DevCheckGMboxInterrupts(pDev);
}
} while (false);
do {
if (status) {
break;
}
if ((0 == host_int_status) && (0 == lookAhead)) {
*pDone = true;
break;
}
if (lookAhead != 0) {
int fetched = 0;
AR_DEBUG_PRINTF(ATH_DEBUG_IRQ,("Pending mailbox message, LookAhead: 0x%X\n",lookAhead));
status = pDev->MessagePendingCallback(pDev->HTCContext, &lookAhead, 1, pASyncProcessing, &fetched);
if (status) {
break;
}
if (!fetched) {
*pASyncProcessing = false;
pDev->RecheckIRQStatusCnt = 0;
}
}
AR_DEBUG_PRINTF(ATH_DEBUG_IRQ,
(" Valid interrupt source(s) for OTHER interrupts: 0x%x\n",
host_int_status));
if (HOST_INT_STATUS_CPU_GET(host_int_status)) {
status = DevServiceCPUInterrupt(pDev);
if (status){
break;
}
}
if (HOST_INT_STATUS_ERROR_GET(host_int_status)) {
status = DevServiceErrorInterrupt(pDev);
if (status){
break;
}
}
if (HOST_INT_STATUS_COUNTER_GET(host_int_status)) {
status = DevServiceCounterInterrupt(pDev);
if (status){
break;
}
}
} while (false);
if (!(*pASyncProcessing) && (pDev->RecheckIRQStatusCnt == 0) && (pDev->GetPendingEventsFunc == NULL)) {
AR_DEBUG_PRINTF(ATH_DEBUG_IRQ,("Bypassing IRQ Status re-check, forcing done \n"));
*pDone = true;
}
AR_DEBUG_PRINTF(ATH_DEBUG_IRQ,("-ProcessPendingIRQs: (done:%d, async:%d) status=%d \n",
*pDone, *pASyncProcessing, status));
return status;
}
int DevDsrHandler(void *context)
{
struct ar6k_device *pDev = (struct ar6k_device *)context;
int status = 0;
bool done = false;
bool asyncProc = false;
AR_DEBUG_PRINTF(ATH_DEBUG_IRQ,("+DevDsrHandler: (dev: 0x%lX)\n", (unsigned long)pDev));
pDev->CurrentDSRRecvCount = 0;
pDev->RecheckIRQStatusCnt = 0;
while (!done) {
status = ProcessPendingIRQs(pDev, &done, &asyncProc);
if (status) {
break;
}
if (HIF_DEVICE_IRQ_SYNC_ONLY == pDev->HifIRQProcessingMode) {
asyncProc = false;
if (pDev->DSRCanYield && DEV_CHECK_RECV_YIELD(pDev)) {
break;
}
}
if (asyncProc) {
break;
}
}
if (!status && !asyncProc) {
if (pDev->DSRCanYield) {
AR_DEBUG_PRINTF(ATH_DEBUG_IRQ,(" Yield in effect (cur RX count: %d) \n", pDev->CurrentDSRRecvCount));
} else {
AR_DEBUG_PRINTF(ATH_DEBUG_IRQ,(" Acking interrupt from DevDsrHandler \n"));
HIFAckInterrupt(pDev->HIFDevice);
}
}
AR_DEBUG_PRINTF(ATH_DEBUG_IRQ,("-DevDsrHandler \n"));
return status;
}
void DumpAR6KDevState(struct ar6k_device *pDev)
{
int status;
struct ar6k_irq_enable_registers regs;
struct ar6k_irq_proc_registers procRegs;
LOCK_AR6K(pDev);
memcpy(&regs,&pDev->IrqEnableRegisters,AR6K_IRQ_ENABLE_REGS_SIZE);
UNLOCK_AR6K(pDev);
status = HIFReadWrite(pDev->HIFDevice,
HOST_INT_STATUS_ADDRESS,
(u8 *)&procRegs,
AR6K_IRQ_PROC_REGS_SIZE,
HIF_RD_SYNC_BYTE_INC,
NULL);
if (status) {
AR_DEBUG_PRINTF(ATH_DEBUG_ERR,
("DumpAR6KDevState : Failed to read register table (%d) \n",status));
return;
}
DevDumpRegisters(pDev,&procRegs,&regs);
if (pDev->GMboxInfo.pStateDumpCallback != NULL) {
pDev->GMboxInfo.pStateDumpCallback(pDev->GMboxInfo.pProtocolContext);
}
HIFConfigureDevice(pDev->HIFDevice,HIF_DEVICE_DEBUG_BUS_STATE,NULL,0);
}
