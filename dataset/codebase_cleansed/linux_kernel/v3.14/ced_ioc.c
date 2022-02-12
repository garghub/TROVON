static void FlushOutBuff(DEVICE_EXTENSION *pdx)
{
dev_dbg(&pdx->interface->dev, "%s currentState=%d", __func__,
pdx->sCurrentState);
if (pdx->sCurrentState == U14ERR_TIME)
return;
spin_lock_irq(&pdx->charOutLock);
pdx->dwNumOutput = 0;
pdx->dwOutBuffGet = 0;
pdx->dwOutBuffPut = 0;
spin_unlock_irq(&pdx->charOutLock);
}
static void FlushInBuff(DEVICE_EXTENSION *pdx)
{
dev_dbg(&pdx->interface->dev, "%s currentState=%d", __func__,
pdx->sCurrentState);
if (pdx->sCurrentState == U14ERR_TIME)
return;
spin_lock_irq(&pdx->charInLock);
pdx->dwNumInput = 0;
pdx->dwInBuffGet = 0;
pdx->dwInBuffPut = 0;
spin_unlock_irq(&pdx->charInLock);
}
static int PutChars(DEVICE_EXTENSION *pdx, const char *pCh,
unsigned int uCount)
{
int iReturn;
spin_lock_irq(&pdx->charOutLock);
if ((OUTBUF_SZ - pdx->dwNumOutput) >= uCount) {
unsigned int u;
for (u = 0; u < uCount; u++) {
pdx->outputBuffer[pdx->dwOutBuffPut++] = pCh[u];
if (pdx->dwOutBuffPut >= OUTBUF_SZ)
pdx->dwOutBuffPut = 0;
}
pdx->dwNumOutput += uCount;
spin_unlock_irq(&pdx->charOutLock);
iReturn = SendChars(pdx);
} else {
iReturn = U14ERR_NOOUT;
spin_unlock_irq(&pdx->charOutLock);
}
return iReturn;
}
int SendString(DEVICE_EXTENSION *pdx, const char __user *pData,
unsigned int n)
{
int iReturn = U14ERR_NOERROR;
char buffer[OUTBUF_SZ + 1];
if (n > OUTBUF_SZ)
return U14ERR_NOOUT;
if (copy_from_user(buffer, pData, n))
return -EFAULT;
buffer[n] = 0;
mutex_lock(&pdx->io_mutex);
if (n > 0) {
dev_dbg(&pdx->interface->dev, "%s n=%d>%s<", __func__, n,
buffer);
iReturn = PutChars(pdx, buffer, n);
}
Allowi(pdx);
mutex_unlock(&pdx->io_mutex);
return iReturn;
}
int SendChar(DEVICE_EXTENSION *pdx, char c)
{
int iReturn;
mutex_lock(&pdx->io_mutex);
iReturn = PutChars(pdx, &c, 1);
dev_dbg(&pdx->interface->dev, "SendChar >%c< (0x%02x)", c, c);
Allowi(pdx);
mutex_unlock(&pdx->io_mutex);
return iReturn;
}
int Get1401State(DEVICE_EXTENSION *pdx, __u32 *state, __u32 *error)
{
int nGot;
dev_dbg(&pdx->interface->dev, "Get1401State() entry");
*state = 0xFFFFFFFF;
nGot = usb_control_msg(pdx->udev, usb_rcvctrlpipe(pdx->udev, 0),
GET_STATUS, (D_TO_H | VENDOR | DEVREQ), 0, 0,
pdx->statBuf, sizeof(pdx->statBuf), HZ);
if (nGot != sizeof(pdx->statBuf)) {
dev_err(&pdx->interface->dev,
"Get1401State() FAILED, return code %d", nGot);
pdx->sCurrentState = U14ERR_TIME;
*state = 0;
*error = 0;
} else {
int nDevice;
dev_dbg(&pdx->interface->dev,
"Get1401State() Success, state: 0x%x, 0x%x",
pdx->statBuf[0], pdx->statBuf[1]);
*state = pdx->statBuf[0];
*error = pdx->statBuf[1];
nDevice = pdx->udev->descriptor.bcdDevice >> 8;
switch (nDevice) {
case 0:
pdx->sCurrentState = U14ERR_U1401;
break;
default:
if ((nDevice >= 1) && (nDevice <= 23))
pdx->sCurrentState = (short)(nDevice + 6);
else
pdx->sCurrentState = U14ERR_ILL;
break;
}
}
return pdx->sCurrentState >= 0 ? U14ERR_NOERROR : pdx->sCurrentState;
}
int ReadWrite_Cancel(DEVICE_EXTENSION *pdx)
{
dev_dbg(&pdx->interface->dev, "ReadWrite_Cancel entry %d",
pdx->bStagedUrbPending);
#ifdef NOT_WRITTEN_YET
int ntStatus = STATUS_SUCCESS;
bool bResult = false;
unsigned int i;
spin_lock_irq(&pdx->stagedLock);
if (pdx->bStagedUrbPending) {
dev_info(&pdx->interface - dev,
"ReadWrite_Cancel about to cancel Urb");
USB_ASSERT(pdx->pStagedIrp != NULL);
spin_unlock_irq(&pdx->stagedLock);
bResult = IoCancelIrp(pdx->pStagedIrp);
if (bResult) {
LARGE_INTEGER timeout;
timeout.QuadPart = -10000000;
dev_info(&pdx->interface - dev,
"ReadWrite_Cancel about to wait till done");
ntStatus =
KeWaitForSingleObject(&pdx->StagingDoneEvent,
Executive, KernelMode, FALSE,
&timeout);
} else {
dev_info(&pdx->interface - dev,
"ReadWrite_Cancel, cancellation failed");
ntStatus = U14ERR_FAIL;
}
USB_KdPrint(DBGLVL_DEFAULT,
("ReadWrite_Cancel ntStatus = 0x%x decimal %d\n",
ntStatus, ntStatus));
} else
spin_unlock_irq(&pdx->stagedLock);
dev_info(&pdx->interface - dev, "ReadWrite_Cancel done");
return ntStatus;
#else
return U14ERR_NOERROR;
#endif
}
static int InSelfTest(DEVICE_EXTENSION *pdx, unsigned int *pState)
{
unsigned int state, error;
int iReturn = Get1401State(pdx, &state, &error);
if (iReturn == U14ERR_NOERROR)
iReturn = (state == (unsigned int)-1) ||
((state & 0xff) == 0x80);
*pState = state;
return iReturn;
}
bool Is1401(DEVICE_EXTENSION *pdx)
{
int iReturn;
dev_dbg(&pdx->interface->dev, "%s", __func__);
ced_draw_down(pdx);
FlushInBuff(pdx);
FlushOutBuff(pdx);
iReturn = usb_lock_device_for_reset(pdx->udev, pdx->interface);
mutex_unlock(&pdx->io_mutex);
if (iReturn >= 0) {
iReturn = usb_reset_device(pdx->udev);
usb_unlock_device(pdx->udev);
}
mutex_lock(&pdx->io_mutex);
pdx->dwDMAFlag = MODE_CHAR;
if (iReturn == 0) {
unsigned int state;
iReturn = InSelfTest(pdx, &state);
if (iReturn > 0) {
unsigned long ulTimeOut = jiffies + 30 * HZ;
while ((iReturn > 0) && time_before(jiffies, ulTimeOut)) {
schedule();
iReturn = InSelfTest(pdx, &state);
}
}
if (iReturn == 0)
iReturn = state == 0;
} else
iReturn = 0;
pdx->bForceReset = false;
return iReturn > 0;
}
bool QuickCheck(DEVICE_EXTENSION *pdx, bool bTestBuff, bool bCanReset)
{
bool bRet = false;
bool bShortTest;
bShortTest = ((pdx->dwDMAFlag == MODE_CHAR) &&
(!pdx->bForceReset) &&
(pdx->sCurrentState >= U14ERR_STD));
dev_dbg(&pdx->interface->dev,
"%s DMAFlag:%d, state:%d, force:%d, testBuff:%d, short:%d",
__func__, pdx->dwDMAFlag, pdx->sCurrentState, pdx->bForceReset,
bTestBuff, bShortTest);
if ((bTestBuff) &&
(pdx->dwNumInput || pdx->dwNumOutput)) {
bShortTest = false;
dev_dbg(&pdx->interface->dev,
"%s will reset as buffers not empty", __func__);
}
if (bShortTest || !bCanReset) {
unsigned int state, error;
dev_dbg(&pdx->interface->dev, "%s->Get1401State", __func__);
if (Get1401State(pdx, &state, &error) == U14ERR_NOERROR) {
if ((state & 0xFF) == 0)
bRet = true;
}
}
if (!bRet && bCanReset) {
dev_info(&pdx->interface->dev, "%s->Is1401 %d %d %d %d",
__func__, bShortTest, pdx->sCurrentState, bTestBuff,
pdx->bForceReset);
bRet = Is1401(pdx);
}
return bRet;
}
int Reset1401(DEVICE_EXTENSION *pdx)
{
mutex_lock(&pdx->io_mutex);
dev_dbg(&pdx->interface->dev, "ABout to call QuickCheck");
QuickCheck(pdx, true, true);
mutex_unlock(&pdx->io_mutex);
return U14ERR_NOERROR;
}
int GetChar(DEVICE_EXTENSION *pdx)
{
int iReturn = U14ERR_NOIN;
mutex_lock(&pdx->io_mutex);
dev_dbg(&pdx->interface->dev, "GetChar");
Allowi(pdx);
SendChars(pdx);
spin_lock_irq(&pdx->charInLock);
if (pdx->dwNumInput > 0) {
iReturn = pdx->inputBuffer[pdx->dwInBuffGet++];
if (pdx->dwInBuffGet >= INBUF_SZ)
pdx->dwInBuffGet = 0;
pdx->dwNumInput--;
} else
iReturn = U14ERR_NOIN;
spin_unlock_irq(&pdx->charInLock);
Allowi(pdx);
mutex_unlock(&pdx->io_mutex);
return iReturn;
}
int GetString(DEVICE_EXTENSION *pdx, char __user *pUser, int n)
{
int nAvailable;
int iReturn = U14ERR_NOIN;
if (n <= 0)
return -ENOMEM;
mutex_lock(&pdx->io_mutex);
Allowi(pdx);
SendChars(pdx);
spin_lock_irq(&pdx->charInLock);
nAvailable = pdx->dwNumInput;
if (nAvailable > n)
nAvailable = n;
if (nAvailable > 0) {
char buffer[INBUF_SZ + 1];
int nGot = 0;
int nCopyToUser;
char cData;
do {
cData = pdx->inputBuffer[pdx->dwInBuffGet++];
if (cData == CR_CHAR)
cData = (char)0;
if (pdx->dwInBuffGet >= INBUF_SZ)
pdx->dwInBuffGet = 0;
buffer[nGot++] = cData;
} while ((nGot < nAvailable) && cData);
nCopyToUser = nGot;
if (cData) {
buffer[nGot] = (char)0;
if (nGot < n)
++nCopyToUser;
}
pdx->dwNumInput -= nGot;
spin_unlock_irq(&pdx->charInLock);
dev_dbg(&pdx->interface->dev,
"GetString read %d characters >%s<", nGot, buffer);
if (copy_to_user(pUser, buffer, nCopyToUser))
iReturn = -EFAULT;
else
iReturn = nGot;
} else
spin_unlock_irq(&pdx->charInLock);
Allowi(pdx);
mutex_unlock(&pdx->io_mutex);
return iReturn;
}
int Stat1401(DEVICE_EXTENSION *pdx)
{
int iReturn;
mutex_lock(&pdx->io_mutex);
Allowi(pdx);
SendChars(pdx);
iReturn = pdx->dwNumInput;
mutex_unlock(&pdx->io_mutex);
return iReturn;
}
int LineCount(DEVICE_EXTENSION *pdx)
{
int iReturn = 0;
mutex_lock(&pdx->io_mutex);
Allowi(pdx);
SendChars(pdx);
spin_lock_irq(&pdx->charInLock);
if (pdx->dwNumInput > 0) {
unsigned int dwIndex = pdx->dwInBuffGet;
unsigned int dwEnd = pdx->dwInBuffPut;
do {
if (pdx->inputBuffer[dwIndex++] == CR_CHAR)
++iReturn;
if (dwIndex >= INBUF_SZ)
dwIndex = 0;
} while (dwIndex != dwEnd);
}
spin_unlock_irq(&pdx->charInLock);
dev_dbg(&pdx->interface->dev, "LineCount returned %d", iReturn);
mutex_unlock(&pdx->io_mutex);
return iReturn;
}
int GetOutBufSpace(DEVICE_EXTENSION *pdx)
{
int iReturn;
mutex_lock(&pdx->io_mutex);
SendChars(pdx);
iReturn = (int)(OUTBUF_SZ - pdx->dwNumOutput);
dev_dbg(&pdx->interface->dev, "OutBufSpace %d", iReturn);
mutex_unlock(&pdx->io_mutex);
return iReturn;
}
int ClearArea(DEVICE_EXTENSION *pdx, int nArea)
{
int iReturn = U14ERR_NOERROR;
if ((nArea < 0) || (nArea >= MAX_TRANSAREAS)) {
iReturn = U14ERR_BADAREA;
dev_err(&pdx->interface->dev, "%s Attempt to clear area %d",
__func__, nArea);
} else {
TRANSAREA *pTA = &pdx->rTransDef[nArea];
if (!pTA->bUsed)
iReturn = U14ERR_NOTSET;
else {
struct page **pPages = NULL;
int nPages = 0;
int np;
dev_dbg(&pdx->interface->dev, "%s area %d", __func__,
nArea);
spin_lock_irq(&pdx->stagedLock);
if ((pdx->StagedId == nArea)
&& (pdx->dwDMAFlag > MODE_CHAR)) {
iReturn = U14ERR_UNLOCKFAIL;
dev_err(&pdx->interface->dev,
"%s call on area %d while active",
__func__, nArea);
} else {
pPages = pTA->pPages;
nPages = pTA->nPages;
if (pTA->dwEventSz)
wake_up_interruptible(&pTA->wqEvent);
if (pdx->bXFerWaiting
&& (pdx->rDMAInfo.wIdent == nArea))
pdx->bXFerWaiting = false;
memset(pTA, 0,
sizeof(TRANSAREA) -
sizeof(wait_queue_head_t));
}
spin_unlock_irq(&pdx->stagedLock);
if (pPages) {
dev_dbg(&pdx->interface->dev, "%s nPages=%d",
__func__, nPages);
for (np = 0; np < nPages; ++np) {
if (pPages[np]) {
SetPageDirty(pPages[np]);
page_cache_release(pPages[np]);
}
}
kfree(pPages);
dev_dbg(&pdx->interface->dev,
"%s kfree(pPages) done", __func__);
}
}
}
return iReturn;
}
static int SetArea(DEVICE_EXTENSION *pdx, int nArea, char __user *puBuf,
unsigned int dwLength, bool bCircular, bool bCircToHost)
{
unsigned long ulStart = ((unsigned long)puBuf) & PAGE_MASK;
unsigned int ulOffset = ((unsigned long)puBuf) & (PAGE_SIZE - 1);
int len = (dwLength + ulOffset + PAGE_SIZE - 1) >> PAGE_SHIFT;
TRANSAREA *pTA = &pdx->rTransDef[nArea];
struct page **pPages = NULL;
int nPages = 0;
int iReturn = ClearArea(pdx, nArea);
if ((iReturn != U14ERR_NOTSET) &&
(iReturn != U14ERR_NOERROR))
return iReturn;
if (!access_ok(VERIFY_WRITE, puBuf, dwLength))
return -EFAULT;
pPages = kmalloc(len * sizeof(struct page *), GFP_KERNEL);
if (!pPages) {
iReturn = U14ERR_NOMEMORY;
goto error;
}
dev_dbg(&pdx->interface->dev, "%s %p, length=%06x, circular %d",
__func__, puBuf, dwLength, bCircular);
nPages = get_user_pages_fast(ulStart, len, 1, pPages);
dev_dbg(&pdx->interface->dev, "%s nPages = %d", __func__, nPages);
if (nPages > 0) {
spin_lock_irq(&pdx->stagedLock);
pTA->lpvBuff = puBuf;
pTA->dwBaseOffset = ulOffset;
pTA->dwLength = dwLength;
pTA->pPages = pPages;
pTA->nPages = nPages;
pTA->bCircular = bCircular;
pTA->bCircToHost = bCircToHost;
pTA->aBlocks[0].dwOffset = 0;
pTA->aBlocks[0].dwSize = 0;
pTA->aBlocks[1].dwOffset = 0;
pTA->aBlocks[1].dwSize = 0;
pTA->bUsed = true;
spin_unlock_irq(&pdx->stagedLock);
iReturn = U14ERR_NOERROR;
} else {
iReturn = U14ERR_LOCKFAIL;
goto error;
}
return iReturn;
error:
kfree(pPages);
return iReturn;
}
int SetTransfer(DEVICE_EXTENSION *pdx, TRANSFERDESC __user *pTD)
{
int iReturn;
TRANSFERDESC td;
if (copy_from_user(&td, pTD, sizeof(td)))
return -EFAULT;
mutex_lock(&pdx->io_mutex);
dev_dbg(&pdx->interface->dev, "%s area:%d, size:%08x", __func__,
td.wAreaNum, td.dwLength);
iReturn =
SetArea(pdx, td.wAreaNum,
(char __user *)((unsigned long)td.lpvBuff), td.dwLength,
false, false);
mutex_unlock(&pdx->io_mutex);
return iReturn;
}
int UnsetTransfer(DEVICE_EXTENSION *pdx, int nArea)
{
int iReturn;
mutex_lock(&pdx->io_mutex);
iReturn = ClearArea(pdx, nArea);
mutex_unlock(&pdx->io_mutex);
return iReturn;
}
int SetEvent(DEVICE_EXTENSION *pdx, TRANSFEREVENT __user *pTE)
{
int iReturn = U14ERR_NOERROR;
TRANSFEREVENT te;
if (copy_from_user(&te, pTE, sizeof(te)))
return -EFAULT;
if (te.wAreaNum >= MAX_TRANSAREAS)
return U14ERR_BADAREA;
else {
TRANSAREA *pTA = &pdx->rTransDef[te.wAreaNum];
mutex_lock(&pdx->io_mutex);
spin_lock_irq(&pdx->stagedLock);
if (pTA->bUsed) {
pTA->dwEventSt = te.dwStart;
pTA->dwEventSz = te.dwLength;
pTA->bEventToHost = te.wFlags & 1;
pTA->iWakeUp = 0;
} else
iReturn = U14ERR_NOTSET;
spin_unlock_irq(&pdx->stagedLock);
mutex_unlock(&pdx->io_mutex);
}
return iReturn ==
U14ERR_NOERROR ? (te.iSetEvent ? 1 : U14ERR_NOERROR) : iReturn;
}
int WaitEvent(DEVICE_EXTENSION *pdx, int nArea, int msTimeOut)
{
int iReturn;
if ((unsigned)nArea >= MAX_TRANSAREAS)
return U14ERR_BADAREA;
else {
int iWait;
TRANSAREA *pTA = &pdx->rTransDef[nArea];
msTimeOut = (msTimeOut * HZ + 999) / 1000;
mutex_lock(&pdx->io_mutex);
if (!pTA->bUsed || !pTA->dwEventSz)
return U14ERR_NOTSET;
mutex_unlock(&pdx->io_mutex);
if (msTimeOut)
iWait =
wait_event_interruptible_timeout(pTA->wqEvent,
pTA->iWakeUp
|| !pTA->bUsed,
msTimeOut);
else
iWait =
wait_event_interruptible(pTA->wqEvent, pTA->iWakeUp
|| !pTA->bUsed);
if (iWait)
iReturn = -ERESTARTSYS;
else
iReturn = pTA->iWakeUp;
spin_lock_irq(&pdx->stagedLock);
pTA->iWakeUp = 0;
spin_unlock_irq(&pdx->stagedLock);
}
return iReturn;
}
int TestEvent(DEVICE_EXTENSION *pdx, int nArea)
{
int iReturn;
if ((unsigned)nArea >= MAX_TRANSAREAS)
iReturn = U14ERR_BADAREA;
else {
TRANSAREA *pTA = &pdx->rTransDef[nArea];
mutex_lock(&pdx->io_mutex);
spin_lock_irq(&pdx->stagedLock);
iReturn = pTA->iWakeUp;
pTA->iWakeUp = 0;
spin_unlock_irq(&pdx->stagedLock);
mutex_unlock(&pdx->io_mutex);
}
return iReturn;
}
int GetTransfer(DEVICE_EXTENSION *pdx, TGET_TX_BLOCK __user *pTX)
{
int iReturn = U14ERR_NOERROR;
unsigned int dwIdent;
mutex_lock(&pdx->io_mutex);
dwIdent = pdx->StagedId;
if (dwIdent >= MAX_TRANSAREAS)
iReturn = U14ERR_BADAREA;
else {
TGET_TX_BLOCK *tx;
tx = kzalloc(sizeof(*tx), GFP_KERNEL);
if (!tx) {
mutex_unlock(&pdx->io_mutex);
return -ENOMEM;
}
tx->size = pdx->rTransDef[dwIdent].dwLength;
tx->linear = (long long)((long)pdx->rTransDef[dwIdent].lpvBuff);
tx->avail = GET_TX_MAXENTRIES;
tx->used = 1;
tx->entries[0].physical =
(long long)(tx->linear + pdx->StagedOffset);
tx->entries[0].size = tx->size;
if (copy_to_user(pTX, tx, sizeof(*tx)))
iReturn = -EFAULT;
kfree(tx);
}
mutex_unlock(&pdx->io_mutex);
return iReturn;
}
int KillIO1401(DEVICE_EXTENSION *pdx)
{
dev_dbg(&pdx->interface->dev, "%s", __func__);
mutex_lock(&pdx->io_mutex);
FlushOutBuff(pdx);
FlushInBuff(pdx);
mutex_unlock(&pdx->io_mutex);
return U14ERR_NOERROR;
}
int BlkTransState(DEVICE_EXTENSION *pdx)
{
int iReturn = pdx->dwDMAFlag != MODE_CHAR;
dev_dbg(&pdx->interface->dev, "%s = %d", __func__, iReturn);
return iReturn;
}
int StateOf1401(DEVICE_EXTENSION *pdx)
{
int iReturn;
mutex_lock(&pdx->io_mutex);
QuickCheck(pdx, false, false);
iReturn = pdx->sCurrentState;
mutex_unlock(&pdx->io_mutex);
dev_dbg(&pdx->interface->dev, "%s = %d", __func__, iReturn);
return iReturn;
}
int StartSelfTest(DEVICE_EXTENSION *pdx)
{
int nGot;
mutex_lock(&pdx->io_mutex);
dev_dbg(&pdx->interface->dev, "%s", __func__);
ced_draw_down(pdx);
FlushInBuff(pdx);
FlushOutBuff(pdx);
pdx->dwDMAFlag = MODE_CHAR;
nGot = usb_control_msg(pdx->udev, usb_rcvctrlpipe(pdx->udev, 0),
DB_SELFTEST, (H_TO_D | VENDOR | DEVREQ),
0, 0, NULL, 0, HZ);
pdx->ulSelfTestTime = jiffies + HZ * 30;
mutex_unlock(&pdx->io_mutex);
if (nGot < 0)
dev_err(&pdx->interface->dev, "%s err=%d", __func__, nGot);
return nGot < 0 ? U14ERR_FAIL : U14ERR_NOERROR;
}
int CheckSelfTest(DEVICE_EXTENSION *pdx, TGET_SELFTEST __user *pGST)
{
unsigned int state, error;
int iReturn;
TGET_SELFTEST gst;
memset(&gst, 0, sizeof(gst));
mutex_lock(&pdx->io_mutex);
dev_dbg(&pdx->interface->dev, "%s", __func__);
iReturn = Get1401State(pdx, &state, &error);
if (iReturn == U14ERR_NOERROR)
iReturn = Get1401State(pdx, &state, &error);
if (iReturn != U14ERR_NOERROR) {
dev_err(&pdx->interface->dev,
"%s Get1401State=%d, assuming still testing", __func__,
iReturn);
state = 0x80;
error = 0;
iReturn = U14ERR_NOERROR;
}
if ((state == -1) && (error == -1)) {
dev_err(&pdx->interface->dev,
"%s Get1401State failed, assuming still testing",
__func__);
state = 0x80;
error = 0;
}
if ((state & 0xFF) == 0x80) {
if (state & 0x00FF0000) {
gst.code = (state & 0x00FF0000) >> 16;
gst.x = error & 0x0000FFFF;
gst.y = (error & 0xFFFF0000) >> 16;
dev_dbg(&pdx->interface->dev, "Self-test error code %d",
gst.code);
} else {
unsigned long ulNow = jiffies;
if (time_after(ulNow, pdx->ulSelfTestTime)) {
gst.code = -2;
dev_dbg(&pdx->interface->dev,
"Self-test timed-out");
} else
dev_dbg(&pdx->interface->dev,
"Self-test on-going");
}
} else {
gst.code = -1;
dev_dbg(&pdx->interface->dev, "Self-test done");
}
if (gst.code < 0) {
if ((pdx->nPipes == 4) && (pdx->s1401Type <= TYPEPOWER))
Is1401(pdx);
else
QuickCheck(pdx, true, true);
}
mutex_unlock(&pdx->io_mutex);
if (copy_to_user(pGST, &gst, sizeof(gst)))
return -EFAULT;
return iReturn;
}
int TypeOf1401(DEVICE_EXTENSION *pdx)
{
int iReturn = TYPEUNKNOWN;
mutex_lock(&pdx->io_mutex);
dev_dbg(&pdx->interface->dev, "%s", __func__);
switch (pdx->s1401Type) {
case TYPE1401:
iReturn = U14ERR_STD;
break;
case TYPEPLUS:
iReturn = U14ERR_PLUS;
break;
case TYPEU1401:
iReturn = U14ERR_U1401;
break;
default:
if ((pdx->s1401Type >= TYPEPOWER) && (pdx->s1401Type <= 25))
iReturn = pdx->s1401Type + 4;
else
iReturn = TYPEUNKNOWN;
}
dev_dbg(&pdx->interface->dev, "%s %d", __func__, iReturn);
mutex_unlock(&pdx->io_mutex);
return iReturn;
}
int TransferFlags(DEVICE_EXTENSION *pdx)
{
int iReturn = U14TF_MULTIA | U14TF_DIAG |
U14TF_NOTIFY | U14TF_CIRCTH;
dev_dbg(&pdx->interface->dev, "%s", __func__);
mutex_lock(&pdx->io_mutex);
if (pdx->bIsUSB2)
iReturn |= U14TF_USB2;
mutex_unlock(&pdx->io_mutex);
return iReturn;
}
static int DbgCmd1401(DEVICE_EXTENSION *pdx, unsigned char cmd,
unsigned int data)
{
int iReturn;
dev_dbg(&pdx->interface->dev, "%s entry", __func__);
iReturn = usb_control_msg(pdx->udev, usb_sndctrlpipe(pdx->udev, 0), cmd,
(H_TO_D | VENDOR | DEVREQ),
(unsigned short)data,
(unsigned short)(data >> 16), NULL, 0, HZ);
if (iReturn < 0)
dev_err(&pdx->interface->dev, "%s fail code=%d", __func__,
iReturn);
return iReturn;
}
int DbgPeek(DEVICE_EXTENSION *pdx, TDBGBLOCK __user *pDB)
{
int iReturn;
TDBGBLOCK db;
if (copy_from_user(&db, pDB, sizeof(db)))
return -EFAULT;
mutex_lock(&pdx->io_mutex);
dev_dbg(&pdx->interface->dev, "%s @ %08x", __func__, db.iAddr);
iReturn = DbgCmd1401(pdx, DB_SETADD, db.iAddr);
if (iReturn == U14ERR_NOERROR)
iReturn = DbgCmd1401(pdx, DB_WIDTH, db.iWidth);
if (iReturn == U14ERR_NOERROR)
iReturn = DbgCmd1401(pdx, DB_REPEATS, db.iRepeats);
if (iReturn == U14ERR_NOERROR)
iReturn = DbgCmd1401(pdx, DB_PEEK, 0);
mutex_unlock(&pdx->io_mutex);
return iReturn;
}
int DbgPoke(DEVICE_EXTENSION *pdx, TDBGBLOCK __user *pDB)
{
int iReturn;
TDBGBLOCK db;
if (copy_from_user(&db, pDB, sizeof(db)))
return -EFAULT;
mutex_lock(&pdx->io_mutex);
dev_dbg(&pdx->interface->dev, "%s @ %08x", __func__, db.iAddr);
iReturn = DbgCmd1401(pdx, DB_SETADD, db.iAddr);
if (iReturn == U14ERR_NOERROR)
iReturn = DbgCmd1401(pdx, DB_WIDTH, db.iWidth);
if (iReturn == U14ERR_NOERROR)
iReturn = DbgCmd1401(pdx, DB_REPEATS, db.iRepeats);
if (iReturn == U14ERR_NOERROR)
iReturn = DbgCmd1401(pdx, DB_POKE, db.iData);
mutex_unlock(&pdx->io_mutex);
return iReturn;
}
int DbgRampData(DEVICE_EXTENSION *pdx, TDBGBLOCK __user *pDB)
{
int iReturn;
TDBGBLOCK db;
if (copy_from_user(&db, pDB, sizeof(db)))
return -EFAULT;
mutex_lock(&pdx->io_mutex);
dev_dbg(&pdx->interface->dev, "%s @ %08x", __func__, db.iAddr);
iReturn = DbgCmd1401(pdx, DB_SETADD, db.iAddr);
if (iReturn == U14ERR_NOERROR)
iReturn = DbgCmd1401(pdx, DB_SETDEF, db.iDefault);
if (iReturn == U14ERR_NOERROR)
iReturn = DbgCmd1401(pdx, DB_SETMASK, db.iMask);
if (iReturn == U14ERR_NOERROR)
iReturn = DbgCmd1401(pdx, DB_WIDTH, db.iWidth);
if (iReturn == U14ERR_NOERROR)
iReturn = DbgCmd1401(pdx, DB_REPEATS, db.iRepeats);
if (iReturn == U14ERR_NOERROR)
iReturn = DbgCmd1401(pdx, DB_RAMPD, 0);
mutex_unlock(&pdx->io_mutex);
return iReturn;
}
int DbgRampAddr(DEVICE_EXTENSION *pdx, TDBGBLOCK __user *pDB)
{
int iReturn;
TDBGBLOCK db;
if (copy_from_user(&db, pDB, sizeof(db)))
return -EFAULT;
mutex_lock(&pdx->io_mutex);
dev_dbg(&pdx->interface->dev, "%s", __func__);
iReturn = DbgCmd1401(pdx, DB_SETDEF, db.iDefault);
if (iReturn == U14ERR_NOERROR)
iReturn = DbgCmd1401(pdx, DB_SETMASK, db.iMask);
if (iReturn == U14ERR_NOERROR)
iReturn = DbgCmd1401(pdx, DB_WIDTH, db.iWidth);
if (iReturn == U14ERR_NOERROR)
iReturn = DbgCmd1401(pdx, DB_REPEATS, db.iRepeats);
if (iReturn == U14ERR_NOERROR)
iReturn = DbgCmd1401(pdx, DB_RAMPA, 0);
mutex_unlock(&pdx->io_mutex);
return iReturn;
}
int DbgGetData(DEVICE_EXTENSION *pdx, TDBGBLOCK __user *pDB)
{
int iReturn;
TDBGBLOCK db;
memset(&db, 0, sizeof(db));
mutex_lock(&pdx->io_mutex);
dev_dbg(&pdx->interface->dev, "%s", __func__);
iReturn = usb_control_msg(pdx->udev, usb_rcvctrlpipe(pdx->udev, 0),
DB_DATA, (D_TO_H | VENDOR | DEVREQ), 0, 0,
&db.iData, sizeof(db.iData), HZ);
if (iReturn == sizeof(db.iData)) {
if (copy_to_user(pDB, &db, sizeof(db)))
iReturn = -EFAULT;
else
iReturn = U14ERR_NOERROR;
} else
dev_err(&pdx->interface->dev, "%s failed, code %d", __func__,
iReturn);
mutex_unlock(&pdx->io_mutex);
return iReturn;
}
int DbgStopLoop(DEVICE_EXTENSION *pdx)
{
int iReturn;
unsigned int uState, uErr;
mutex_lock(&pdx->io_mutex);
dev_dbg(&pdx->interface->dev, "%s", __func__);
iReturn = Get1401State(pdx, &uState, &uErr);
mutex_unlock(&pdx->io_mutex);
return iReturn;
}
int SetCircular(DEVICE_EXTENSION *pdx, TRANSFERDESC __user *pTD)
{
int iReturn;
bool bToHost;
TRANSFERDESC td;
if (copy_from_user(&td, pTD, sizeof(td)))
return -EFAULT;
mutex_lock(&pdx->io_mutex);
dev_dbg(&pdx->interface->dev, "%s area:%d, size:%08x", __func__,
td.wAreaNum, td.dwLength);
bToHost = td.eSize != 0;
iReturn =
SetArea(pdx, td.wAreaNum,
(char __user *)((unsigned long)td.lpvBuff), td.dwLength,
true, bToHost);
mutex_unlock(&pdx->io_mutex);
return iReturn;
}
int GetCircBlock(DEVICE_EXTENSION *pdx, TCIRCBLOCK __user *pCB)
{
int iReturn = U14ERR_NOERROR;
unsigned int nArea;
TCIRCBLOCK cb;
dev_dbg(&pdx->interface->dev, "%s", __func__);
if (copy_from_user(&cb, pCB, sizeof(cb)))
return -EFAULT;
mutex_lock(&pdx->io_mutex);
nArea = cb.nArea;
cb.dwOffset = 0;
cb.dwSize = 0;
if (nArea < MAX_TRANSAREAS) {
TRANSAREA *pArea = &pdx->rTransDef[nArea];
spin_lock_irq(&pdx->stagedLock);
if ((pArea->bUsed) && (pArea->bCircular) &&
(pArea->bCircToHost)) {
if (pArea->aBlocks[0].dwSize > 0) {
cb.dwOffset = pArea->aBlocks[0].dwOffset;
cb.dwSize = pArea->aBlocks[0].dwSize;
dev_dbg(&pdx->interface->dev,
"%s return block 0: %d bytes at %d",
__func__, cb.dwSize, cb.dwOffset);
}
} else
iReturn = U14ERR_NOTSET;
spin_unlock_irq(&pdx->stagedLock);
} else
iReturn = U14ERR_BADAREA;
if (copy_to_user(pCB, &cb, sizeof(cb)))
iReturn = -EFAULT;
mutex_unlock(&pdx->io_mutex);
return iReturn;
}
int FreeCircBlock(DEVICE_EXTENSION *pdx, TCIRCBLOCK __user *pCB)
{
int iReturn = U14ERR_NOERROR;
unsigned int nArea, uStart, uSize;
TCIRCBLOCK cb;
dev_dbg(&pdx->interface->dev, "%s", __func__);
if (copy_from_user(&cb, pCB, sizeof(cb)))
return -EFAULT;
mutex_lock(&pdx->io_mutex);
nArea = cb.nArea;
uStart = cb.dwOffset;
uSize = cb.dwSize;
cb.dwOffset = 0;
cb.dwSize = 0;
if (nArea < MAX_TRANSAREAS) {
TRANSAREA *pArea = &pdx->rTransDef[nArea];
spin_lock_irq(&pdx->stagedLock);
if ((pArea->bUsed) && (pArea->bCircular) &&
(pArea->bCircToHost)) {
bool bWaiting = false;
if ((pArea->aBlocks[0].dwSize >= uSize) &&
(pArea->aBlocks[0].dwOffset == uStart)) {
pArea->aBlocks[0].dwSize -= uSize;
pArea->aBlocks[0].dwOffset += uSize;
if (pArea->aBlocks[0].dwSize == 0) {
if (pArea->aBlocks[1].dwSize) {
pArea->aBlocks[0] = pArea->aBlocks[1];
pArea->aBlocks[1].dwSize = 0;
pArea->aBlocks[1].dwOffset = 0;
} else
pArea->aBlocks[0].dwOffset = 0;
}
dev_dbg(&pdx->interface->dev,
"%s free %d bytes at %d, return %d bytes at %d, wait=%d",
__func__, uSize, uStart,
pArea->aBlocks[0].dwSize,
pArea->aBlocks[0].dwOffset,
pdx->bXFerWaiting);
if (pArea->aBlocks[0].dwSize > 0) {
cb.dwOffset =
pArea->aBlocks[0].dwOffset;
cb.dwSize = pArea->aBlocks[0].dwSize;
}
bWaiting = pdx->bXFerWaiting;
if (bWaiting && pdx->bStagedUrbPending) {
dev_err(&pdx->interface->dev,
"%s ERROR: waiting xfer and staged Urb pending!",
__func__);
bWaiting = false;
}
} else {
dev_err(&pdx->interface->dev,
"%s ERROR: freeing %d bytes at %d, block 0 is %d bytes at %d",
__func__, uSize, uStart,
pArea->aBlocks[0].dwSize,
pArea->aBlocks[0].dwOffset);
iReturn = U14ERR_NOMEMORY;
}
if (bWaiting) {
int RWMStat =
ReadWriteMem(pdx, !pdx->rDMAInfo.bOutWard,
pdx->rDMAInfo.wIdent,
pdx->rDMAInfo.dwOffset,
pdx->rDMAInfo.dwSize);
if (RWMStat != U14ERR_NOERROR)
dev_err(&pdx->interface->dev,
"%s rw setup failed %d",
__func__, RWMStat);
}
} else
iReturn = U14ERR_NOTSET;
spin_unlock_irq(&pdx->stagedLock);
} else
iReturn = U14ERR_BADAREA;
if (copy_to_user(pCB, &cb, sizeof(cb)))
iReturn = -EFAULT;
mutex_unlock(&pdx->io_mutex);
return iReturn;
}
