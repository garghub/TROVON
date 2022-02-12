static void DevGMboxIRQActionAsyncHandler(void *Context, struct htc_packet *pPacket)
{
struct ar6k_device *pDev = (struct ar6k_device *)Context;
AR_DEBUG_PRINTF(ATH_DEBUG_IRQ,("+DevGMboxIRQActionAsyncHandler: (dev: 0x%lX)\n", (unsigned long)pDev));
if (pPacket->Status) {
AR_DEBUG_PRINTF(ATH_DEBUG_ERR,
("IRQAction Operation (%d) failed! status:%d \n", pPacket->PktInfo.AsRx.HTCRxFlags,pPacket->Status));
}
AR6KFreeIOPacket(pDev,pPacket);
AR_DEBUG_PRINTF(ATH_DEBUG_IRQ,("-DevGMboxIRQActionAsyncHandler \n"));
}
static int DevGMboxCounterEnableDisable(struct ar6k_device *pDev, GMBOX_IRQ_ACTION_TYPE IrqAction, bool AsyncMode)
{
int status = 0;
struct ar6k_irq_enable_registers regs;
struct htc_packet *pIOPacket = NULL;
LOCK_AR6K(pDev);
if (GMBOX_CREDIT_IRQ_ENABLE == IrqAction) {
pDev->GMboxInfo.CreditCountIRQEnabled = true;
pDev->IrqEnableRegisters.counter_int_status_enable |=
COUNTER_INT_STATUS_ENABLE_BIT_SET(1 << AR6K_GMBOX_CREDIT_COUNTER);
pDev->IrqEnableRegisters.int_status_enable |= INT_STATUS_ENABLE_COUNTER_SET(0x01);
} else {
pDev->GMboxInfo.CreditCountIRQEnabled = false;
pDev->IrqEnableRegisters.counter_int_status_enable &=
~(COUNTER_INT_STATUS_ENABLE_BIT_SET(1 << AR6K_GMBOX_CREDIT_COUNTER));
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
memcpy(pIOPacket->pBuffer,&pDev->IrqEnableRegisters,AR6K_IRQ_ENABLE_REGS_SIZE);
pIOPacket->Completion = DevGMboxIRQActionAsyncHandler;
pIOPacket->pContext = pDev;
pIOPacket->PktInfo.AsRx.HTCRxFlags = IrqAction;
HIFReadWrite(pDev->HIFDevice,
INT_STATUS_ENABLE_ADDRESS,
pIOPacket->pBuffer,
AR6K_IRQ_ENABLE_REGS_SIZE,
HIF_WR_ASYNC_BYTE_INC,
pIOPacket);
pIOPacket = NULL;
break;
}
status = HIFReadWrite(pDev->HIFDevice,
INT_STATUS_ENABLE_ADDRESS,
&regs.int_status_enable,
AR6K_IRQ_ENABLE_REGS_SIZE,
HIF_WR_SYNC_BYTE_INC,
NULL);
} while (false);
if (status) {
AR_DEBUG_PRINTF(ATH_DEBUG_ERR,
(" IRQAction Operation (%d) failed! status:%d \n", IrqAction, status));
} else {
if (!AsyncMode) {
AR_DEBUG_PRINTF(ATH_DEBUG_IRQ,
(" IRQAction Operation (%d) success \n", IrqAction));
}
}
if (pIOPacket != NULL) {
AR6KFreeIOPacket(pDev,pIOPacket);
}
return status;
}
int DevGMboxIRQAction(struct ar6k_device *pDev, GMBOX_IRQ_ACTION_TYPE IrqAction, bool AsyncMode)
{
int status = 0;
struct htc_packet *pIOPacket = NULL;
u8 GMboxIntControl[4];
if (GMBOX_CREDIT_IRQ_ENABLE == IrqAction) {
return DevGMboxCounterEnableDisable(pDev, GMBOX_CREDIT_IRQ_ENABLE, AsyncMode);
} else if(GMBOX_CREDIT_IRQ_DISABLE == IrqAction) {
return DevGMboxCounterEnableDisable(pDev, GMBOX_CREDIT_IRQ_DISABLE, AsyncMode);
}
if (GMBOX_DISABLE_ALL == IrqAction) {
DevGMboxCounterEnableDisable(pDev, GMBOX_CREDIT_IRQ_DISABLE, AsyncMode);
}
LOCK_AR6K(pDev);
switch (IrqAction) {
case GMBOX_DISABLE_ALL:
pDev->GMboxControlRegisters.int_status_enable = 0;
break;
case GMBOX_ERRORS_IRQ_ENABLE:
pDev->GMboxControlRegisters.int_status_enable |= GMBOX_INT_STATUS_TX_OVERFLOW |
GMBOX_INT_STATUS_RX_OVERFLOW;
break;
case GMBOX_RECV_IRQ_ENABLE:
pDev->GMboxControlRegisters.int_status_enable |= GMBOX_INT_STATUS_RX_DATA;
break;
case GMBOX_RECV_IRQ_DISABLE:
pDev->GMboxControlRegisters.int_status_enable &= ~GMBOX_INT_STATUS_RX_DATA;
break;
case GMBOX_ACTION_NONE:
default:
A_ASSERT(false);
break;
}
GMboxIntControl[0] = pDev->GMboxControlRegisters.int_status_enable;
GMboxIntControl[1] = GMboxIntControl[0];
GMboxIntControl[2] = GMboxIntControl[0];
GMboxIntControl[3] = GMboxIntControl[0];
UNLOCK_AR6K(pDev);
do {
if (AsyncMode) {
pIOPacket = AR6KAllocIOPacket(pDev);
if (NULL == pIOPacket) {
status = A_NO_MEMORY;
A_ASSERT(false);
break;
}
memcpy(pIOPacket->pBuffer,GMboxIntControl,sizeof(GMboxIntControl));
pIOPacket->Completion = DevGMboxIRQActionAsyncHandler;
pIOPacket->pContext = pDev;
pIOPacket->PktInfo.AsRx.HTCRxFlags = IrqAction;
HIFReadWrite(pDev->HIFDevice,
GMBOX_INT_STATUS_ENABLE_REG,
pIOPacket->pBuffer,
sizeof(GMboxIntControl),
HIF_WR_ASYNC_BYTE_FIX,
pIOPacket);
pIOPacket = NULL;
break;
}
status = HIFReadWrite(pDev->HIFDevice,
GMBOX_INT_STATUS_ENABLE_REG,
GMboxIntControl,
sizeof(GMboxIntControl),
HIF_WR_SYNC_BYTE_FIX,
NULL);
} while (false);
if (status) {
AR_DEBUG_PRINTF(ATH_DEBUG_ERR,
(" IRQAction Operation (%d) failed! status:%d \n", IrqAction, status));
} else {
if (!AsyncMode) {
AR_DEBUG_PRINTF(ATH_DEBUG_IRQ,
(" IRQAction Operation (%d) success \n", IrqAction));
}
}
if (pIOPacket != NULL) {
AR6KFreeIOPacket(pDev,pIOPacket);
}
return status;
}
void DevCleanupGMbox(struct ar6k_device *pDev)
{
if (pDev->GMboxEnabled) {
pDev->GMboxEnabled = false;
GMboxProtocolUninstall(pDev);
}
}
int DevSetupGMbox(struct ar6k_device *pDev)
{
int status = 0;
u8 muxControl[4];
do {
if (0 == pDev->MailBoxInfo.GMboxAddress) {
break;
}
AR_DEBUG_PRINTF(ATH_DEBUG_ANY,(" GMBOX Advertised: Address:0x%X , size:%d \n",
pDev->MailBoxInfo.GMboxAddress, pDev->MailBoxInfo.GMboxSize));
status = DevGMboxIRQAction(pDev, GMBOX_DISABLE_ALL, PROC_IO_SYNC);
if (status) {
break;
}
muxControl[0] = GMBOX_LA_MUX_OVERRIDE_2_3;
muxControl[1] = GMBOX_LA_MUX_OVERRIDE_2_3;
muxControl[2] = GMBOX_LA_MUX_OVERRIDE_2_3;
muxControl[3] = GMBOX_LA_MUX_OVERRIDE_2_3;
status = HIFReadWrite(pDev->HIFDevice,
GMBOX_LOOKAHEAD_MUX_REG,
muxControl,
sizeof(muxControl),
HIF_WR_SYNC_BYTE_FIX,
NULL);
if (status) {
break;
}
status = GMboxProtocolInstall(pDev);
if (status) {
break;
}
pDev->GMboxEnabled = true;
} while (false);
return status;
}
int DevCheckGMboxInterrupts(struct ar6k_device *pDev)
{
int status = 0;
u8 counter_int_status;
int credits;
u8 host_int_status2;
AR_DEBUG_PRINTF(ATH_DEBUG_IRQ, ("+DevCheckGMboxInterrupts \n"));
do {
host_int_status2 = pDev->IrqProcRegisters.host_int_status2 &
pDev->GMboxControlRegisters.int_status_enable;
if (host_int_status2 & GMBOX_INT_STATUS_TX_OVERFLOW) {
AR_DEBUG_PRINTF(ATH_DEBUG_ERR, ("GMBOX : TX Overflow \n"));
status = A_ECOMM;
}
if (host_int_status2 & GMBOX_INT_STATUS_RX_OVERFLOW) {
AR_DEBUG_PRINTF(ATH_DEBUG_ERR, ("GMBOX : RX Overflow \n"));
status = A_ECOMM;
}
if (status) {
if (pDev->GMboxInfo.pTargetFailureCallback != NULL) {
pDev->GMboxInfo.pTargetFailureCallback(pDev->GMboxInfo.pProtocolContext, status);
}
break;
}
if (host_int_status2 & GMBOX_INT_STATUS_RX_DATA) {
if (pDev->IrqProcRegisters.gmbox_rx_avail > 0) {
A_ASSERT(pDev->GMboxInfo.pMessagePendingCallBack != NULL);
status = pDev->GMboxInfo.pMessagePendingCallBack(
pDev->GMboxInfo.pProtocolContext,
(u8 *)&pDev->IrqProcRegisters.rx_gmbox_lookahead_alias[0],
pDev->IrqProcRegisters.gmbox_rx_avail);
}
}
if (status) {
break;
}
counter_int_status = pDev->IrqProcRegisters.counter_int_status &
pDev->IrqEnableRegisters.counter_int_status_enable;
if (counter_int_status & (COUNTER_INT_STATUS_ENABLE_BIT_SET(1 << AR6K_GMBOX_CREDIT_COUNTER))) {
status = DevGMboxReadCreditCounter(pDev, PROC_IO_SYNC, &credits);
if (status) {
break;
}
A_ASSERT(pDev->GMboxInfo.pCreditsPendingCallback != NULL);
status = pDev->GMboxInfo.pCreditsPendingCallback(pDev->GMboxInfo.pProtocolContext,
credits,
pDev->GMboxInfo.CreditCountIRQEnabled);
}
} while (false);
AR_DEBUG_PRINTF(ATH_DEBUG_IRQ, ("-DevCheckGMboxInterrupts (%d) \n",status));
return status;
}
int DevGMboxWrite(struct ar6k_device *pDev, struct htc_packet *pPacket, u32 WriteLength)
{
u32 paddedLength;
bool sync = (pPacket->Completion == NULL) ? true : false;
int status;
u32 address;
paddedLength = DEV_CALC_SEND_PADDED_LEN(pDev, WriteLength);
AR_DEBUG_PRINTF(ATH_DEBUG_SEND,
("DevGMboxWrite, Padded Length: %d Mbox:0x%X (mode:%s)\n",
WriteLength,
pDev->MailBoxInfo.GMboxAddress,
sync ? "SYNC" : "ASYNC"));
address = pDev->MailBoxInfo.GMboxAddress + pDev->MailBoxInfo.GMboxSize - paddedLength;
status = HIFReadWrite(pDev->HIFDevice,
address,
pPacket->pBuffer,
paddedLength,
sync ? HIF_WR_SYNC_BLOCK_INC : HIF_WR_ASYNC_BLOCK_INC,
sync ? NULL : pPacket);
if (sync) {
pPacket->Status = status;
} else {
if (status == A_PENDING) {
status = 0;
}
}
return status;
}
int DevGMboxRead(struct ar6k_device *pDev, struct htc_packet *pPacket, u32 ReadLength)
{
u32 paddedLength;
int status;
bool sync = (pPacket->Completion == NULL) ? true : false;
paddedLength = DEV_CALC_RECV_PADDED_LEN(pDev, ReadLength);
if (paddedLength > pPacket->BufferLength) {
A_ASSERT(false);
AR_DEBUG_PRINTF(ATH_DEBUG_ERR,
("DevGMboxRead, Not enough space for padlen:%d recvlen:%d bufferlen:%d \n",
paddedLength,ReadLength,pPacket->BufferLength));
if (pPacket->Completion != NULL) {
COMPLETE_HTC_PACKET(pPacket,A_EINVAL);
return 0;
}
return A_EINVAL;
}
AR_DEBUG_PRINTF(ATH_DEBUG_RECV,
("DevGMboxRead (0x%lX : hdr:0x%X) Padded Length: %d Mbox:0x%X (mode:%s)\n",
(unsigned long)pPacket, pPacket->PktInfo.AsRx.ExpectedHdr,
paddedLength,
pDev->MailBoxInfo.GMboxAddress,
sync ? "SYNC" : "ASYNC"));
status = HIFReadWrite(pDev->HIFDevice,
pDev->MailBoxInfo.GMboxAddress,
pPacket->pBuffer,
paddedLength,
sync ? HIF_RD_SYNC_BLOCK_FIX : HIF_RD_ASYNC_BLOCK_FIX,
sync ? NULL : pPacket);
if (sync) {
pPacket->Status = status;
}
return status;
}
static int ProcessCreditCounterReadBuffer(u8 *pBuffer, int Length)
{
int credits = 0;
if (AR_DEBUG_LVL_CHECK(ATH_DEBUG_RECV)) {
DebugDumpBytes(pBuffer, Length, "GMBOX Credit read buffer");
}
while (Length) {
if (*pBuffer != 0) {
credits++;
}
Length--;
pBuffer++;
}
return credits;
}
static void DevGMboxReadCreditsAsyncHandler(void *Context, struct htc_packet *pPacket)
{
struct ar6k_device *pDev = (struct ar6k_device *)Context;
AR_DEBUG_PRINTF(ATH_DEBUG_IRQ,("+DevGMboxReadCreditsAsyncHandler: (dev: 0x%lX)\n", (unsigned long)pDev));
if (pPacket->Status) {
AR_DEBUG_PRINTF(ATH_DEBUG_ERR,
("Read Credit Operation failed! status:%d \n", pPacket->Status));
} else {
int credits = 0;
credits = ProcessCreditCounterReadBuffer(pPacket->pBuffer, AR6K_REG_IO_BUFFER_SIZE);
pDev->GMboxInfo.pCreditsPendingCallback(pDev->GMboxInfo.pProtocolContext,
credits,
pDev->GMboxInfo.CreditCountIRQEnabled);
}
AR6KFreeIOPacket(pDev,pPacket);
AR_DEBUG_PRINTF(ATH_DEBUG_IRQ,("-DevGMboxReadCreditsAsyncHandler \n"));
}
int DevGMboxReadCreditCounter(struct ar6k_device *pDev, bool AsyncMode, int *pCredits)
{
int status = 0;
struct htc_packet *pIOPacket = NULL;
AR_DEBUG_PRINTF(ATH_DEBUG_SEND,("+DevGMboxReadCreditCounter (%s) \n", AsyncMode ? "ASYNC" : "SYNC"));
do {
pIOPacket = AR6KAllocIOPacket(pDev);
if (NULL == pIOPacket) {
status = A_NO_MEMORY;
A_ASSERT(false);
break;
}
A_MEMZERO(pIOPacket->pBuffer,AR6K_REG_IO_BUFFER_SIZE);
if (AsyncMode) {
pIOPacket->Completion = DevGMboxReadCreditsAsyncHandler;
pIOPacket->pContext = pDev;
HIFReadWrite(pDev->HIFDevice,
AR6K_GMBOX_CREDIT_DEC_ADDRESS,
pIOPacket->pBuffer,
AR6K_REG_IO_BUFFER_SIZE,
HIF_RD_ASYNC_BYTE_FIX,
pIOPacket);
pIOPacket = NULL;
break;
}
pIOPacket->Completion = NULL;
status = HIFReadWrite(pDev->HIFDevice,
AR6K_GMBOX_CREDIT_DEC_ADDRESS,
pIOPacket->pBuffer,
AR6K_REG_IO_BUFFER_SIZE,
HIF_RD_SYNC_BYTE_FIX,
NULL);
} while (false);
if (status) {
AR_DEBUG_PRINTF(ATH_DEBUG_ERR,
(" DevGMboxReadCreditCounter failed! status:%d \n", status));
}
if (pIOPacket != NULL) {
if (!status) {
*pCredits = ProcessCreditCounterReadBuffer(pIOPacket->pBuffer, AR6K_REG_IO_BUFFER_SIZE);
}
AR6KFreeIOPacket(pDev,pIOPacket);
}
AR_DEBUG_PRINTF(ATH_DEBUG_SEND,("-DevGMboxReadCreditCounter (%s) (%d) \n",
AsyncMode ? "ASYNC" : "SYNC", status));
return status;
}
int DevGMboxReadCreditSize(struct ar6k_device *pDev, int *pCreditSize)
{
int status;
u8 buffer[4];
status = HIFReadWrite(pDev->HIFDevice,
AR6K_GMBOX_CREDIT_SIZE_ADDRESS,
buffer,
sizeof(buffer),
HIF_RD_SYNC_BYTE_FIX,
NULL);
if (!status) {
if (buffer[0] == 0) {
*pCreditSize = 256;
} else {
*pCreditSize = buffer[0];
}
}
return status;
}
void DevNotifyGMboxTargetFailure(struct ar6k_device *pDev)
{
if (pDev->GMboxInfo.pTargetFailureCallback != NULL) {
pDev->GMboxInfo.pTargetFailureCallback(pDev->GMboxInfo.pProtocolContext, A_HARDWARE);
}
}
int DevGMboxRecvLookAheadPeek(struct ar6k_device *pDev, u8 *pLookAheadBuffer, int *pLookAheadBytes)
{
int status = 0;
struct ar6k_irq_proc_registers procRegs;
int maxCopy;
do {
if (*pLookAheadBytes > sizeof(procRegs.rx_gmbox_lookahead_alias)) {
A_ASSERT(false);
status = A_EINVAL;
break;
}
maxCopy = *pLookAheadBytes;
*pLookAheadBytes = 0;
status = HIFReadWrite(pDev->HIFDevice,
HOST_INT_STATUS_ADDRESS,
(u8 *)&procRegs,
AR6K_IRQ_PROC_REGS_SIZE,
HIF_RD_SYNC_BYTE_INC,
NULL);
if (status) {
AR_DEBUG_PRINTF(ATH_DEBUG_ERR,
("DevGMboxRecvLookAheadPeek : Failed to read register table (%d) \n",status));
break;
}
if (procRegs.gmbox_rx_avail > 0) {
int bytes = procRegs.gmbox_rx_avail > maxCopy ? maxCopy : procRegs.gmbox_rx_avail;
memcpy(pLookAheadBuffer,&procRegs.rx_gmbox_lookahead_alias[0],bytes);
*pLookAheadBytes = bytes;
}
} while (false);
return status;
}
int DevGMboxSetTargetInterrupt(struct ar6k_device *pDev, int Signal, int AckTimeoutMS)
{
int status = 0;
int i;
u8 buffer[4];
A_MEMZERO(buffer, sizeof(buffer));
do {
if (Signal >= MBOX_SIG_HCI_BRIDGE_MAX) {
status = A_EINVAL;
break;
}
buffer[3] = (1 << Signal);
status = HIFReadWrite(pDev->HIFDevice,
INT_WLAN_ADDRESS,
buffer,
sizeof(buffer),
HIF_WR_SYNC_BYTE_FIX,
NULL);
if (status) {
break;
}
} while (false);
if (!status) {
while (AckTimeoutMS) {
status = HIFReadWrite(pDev->HIFDevice,
INT_WLAN_ADDRESS,
buffer,
sizeof(buffer),
HIF_RD_SYNC_BYTE_FIX,
NULL);
if (status) {
break;
}
for (i = 0; i < sizeof(buffer); i++) {
if (buffer[i] & (1 << Signal)) {
break;
}
}
if (i >= sizeof(buffer)) {
break;
}
AckTimeoutMS--;
A_MDELAY(1);
}
if (0 == AckTimeoutMS) {
AR_DEBUG_PRINTF(ATH_DEBUG_ERR,
("DevGMboxSetTargetInterrupt : Ack Timed-out (sig:%d) \n",Signal));
status = A_ERROR;
}
}
return status;
}
