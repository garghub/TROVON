static int
iiSetAddress( i2eBordStrPtr pB, int address, delayFunc_t delay )
{
pB->i2eValid = I2E_INCOMPLETE;
if ((unsigned int)address <= 0x100
|| (unsigned int)address >= 0xfff8
|| (address & 0x7)
)
{
I2_COMPLETE(pB, I2EE_BADADDR);
}
pB->i2eBase = address;
pB->i2eData = address + FIFO_DATA;
pB->i2eStatus = address + FIFO_STATUS;
pB->i2ePointer = address + FIFO_PTR;
pB->i2eXMail = address + FIFO_MAIL;
pB->i2eXMask = address + FIFO_MASK;
ii2Safe = address + FIFO_NOP;
pB->i2eDelay = ((delay != (delayFunc_t)NULL) ? delay : (delayFunc_t)ii2Nop);
pB->i2eValid = I2E_MAGIC;
pB->i2eState = II_STATE_COLD;
I2_COMPLETE(pB, I2EE_GOOD);
}
static int
iiReset(i2eBordStrPtr pB)
{
if (pB->i2eValid != I2E_MAGIC)
{
I2_COMPLETE(pB, I2EE_BADMAGIC);
}
outb(0, pB->i2eBase + FIFO_RESET);
iiDelay(pB, 50);
outb(0, pB->i2eBase + FIFO_RESET);
pB->i2eState = II_STATE_RESET;
iiDelayed = 0;
pB->i2eUsingIrq = I2_IRQ_UNDEFINED;
pB->i2eWaitingForEmptyFifo = 0;
pB->i2eOutMailWaiting = 0;
pB->i2eChannelPtr = NULL;
pB->i2eChannelCnt = 0;
pB->i2eLeadoffWord[0] = 0;
pB->i2eFifoInInts = 0;
pB->i2eFifoOutInts = 0;
pB->i2eFatalTrap = NULL;
pB->i2eFatal = 0;
I2_COMPLETE(pB, I2EE_GOOD);
}
static int
iiResetDelay(i2eBordStrPtr pB)
{
if (pB->i2eValid != I2E_MAGIC) {
I2_COMPLETE(pB, I2EE_BADMAGIC);
}
if (pB->i2eState != II_STATE_RESET) {
I2_COMPLETE(pB, I2EE_BADSTATE);
}
iiDelay(pB,2000);
iiDelayed = 1;
I2_COMPLETE(pB, I2EE_GOOD);
}
static int
iiInitialize(i2eBordStrPtr pB)
{
int itemp;
unsigned char c;
unsigned short utemp;
unsigned int ilimit;
if (pB->i2eValid != I2E_MAGIC)
{
I2_COMPLETE(pB, I2EE_BADMAGIC);
}
if (pB->i2eState != II_STATE_RESET || !iiDelayed)
{
I2_COMPLETE(pB, I2EE_BADSTATE);
}
pB->i2eValid = I2E_INCOMPLETE;
for (itemp = 0; itemp < sizeof(porStr); itemp++)
{
if (!I2_HAS_INPUT(pB)) {
pB->i2ePomSize = itemp;
I2_COMPLETE(pB, I2EE_PORM_SHORT);
}
pB->i2ePom.c[itemp] = c = inb(pB->i2eData);
if ( (itemp == POR_1_INDEX && c != POR_MAGIC_1) ||
(itemp == POR_2_INDEX && c != POR_MAGIC_2))
{
pB->i2ePomSize = itemp+1;
I2_COMPLETE(pB, I2EE_BADMAGIC);
}
}
pB->i2ePomSize = itemp;
if (I2_HAS_INPUT(pB))
I2_COMPLETE(pB, I2EE_PORM_LONG);
if (pB->i2ePom.e.porDiag1 & POR_BAD_MAPPER)
{
I2_COMPLETE(pB, I2EE_POSTERR);
}
switch (pB->i2ePom.e.porID & POR_ID_FAMILY)
{
case POR_ID_FII:
pB->i2eFifoStyle = FIFO_II;
pB->i2eFifoSize = 512;
pB->i2eDataWidth16 = false;
pB->i2eMaxIrq = 15;
pB->i2eGoodMap[1] =
pB->i2eGoodMap[2] =
pB->i2eGoodMap[3] =
pB->i2eChannelMap[1] =
pB->i2eChannelMap[2] =
pB->i2eChannelMap[3] = 0;
switch (pB->i2ePom.e.porID & POR_ID_SIZE)
{
case POR_ID_II_4:
pB->i2eGoodMap[0] =
pB->i2eChannelMap[0] = 0x0f;
if (pB->i2ePom.e.porPorts1 != 4)
{
I2_COMPLETE(pB, I2EE_INCONSIST);
}
break;
case POR_ID_II_8:
case POR_ID_II_8R:
pB->i2eGoodMap[0] =
pB->i2eChannelMap[0] = 0xff;
if (pB->i2ePom.e.porPorts1 != 8)
{
I2_COMPLETE(pB, I2EE_INCONSIST);
}
break;
case POR_ID_II_6:
pB->i2eGoodMap[0] =
pB->i2eChannelMap[0] = 0x3f;
if (pB->i2ePom.e.porPorts1 != 6)
{
I2_COMPLETE(pB, I2EE_INCONSIST);
}
break;
}
if (pB->i2ePom.e.porDiag1 & POR_BAD_UART1)
{
pB->i2eGoodMap[0] &= ~0x0f;
}
if (pB->i2ePom.e.porDiag1 & POR_BAD_UART2)
{
pB->i2eGoodMap[0] &= ~0xf0;
}
break;
case POR_ID_FIIEX:
pB->i2eFifoStyle = FIFO_IIEX;
itemp = pB->i2ePom.e.porFifoSize;
if (itemp < 8 || itemp > 15)
{
I2_COMPLETE(pB, I2EE_INCONSIST);
}
pB->i2eFifoSize = (1 << itemp);
ilimit = pB->i2ePom.e.porNumBoxes;
if (ilimit > ABS_MAX_BOXES)
{
ilimit = ABS_MAX_BOXES;
}
utemp = pB->i2ePom.e.porFlags;
if (utemp & POR_CEX4)
{
pB->i2eChannelMap[0] = 0x000f;
} else {
utemp &= POR_BOXES;
for (itemp = 0; itemp < ilimit; itemp++)
{
pB->i2eChannelMap[itemp] =
((utemp & POR_BOX_16) ? 0xffff : 0x00ff);
utemp >>= 1;
}
}
utemp = (pB->i2ePom.e.porPorts2 << 8) + pB->i2ePom.e.porPorts1;
for (itemp = 0; itemp < ilimit; itemp++)
{
pB->i2eGoodMap[itemp] = 0;
if (utemp & 1) pB->i2eGoodMap[itemp] |= 0x000f;
if (utemp & 2) pB->i2eGoodMap[itemp] |= 0x00f0;
if (utemp & 4) pB->i2eGoodMap[itemp] |= 0x0f00;
if (utemp & 8) pB->i2eGoodMap[itemp] |= 0xf000;
utemp >>= 4;
}
switch (pB->i2ePom.e.porBus & (POR_BUS_SLOT16 | POR_BUS_DIP16) )
{
case POR_BUS_SLOT16 | POR_BUS_DIP16:
pB->i2eDataWidth16 = true;
pB->i2eMaxIrq = 15;
break;
case POR_BUS_SLOT16:
pB->i2eDataWidth16 = false;
pB->i2eMaxIrq = 15;
break;
case 0:
case POR_BUS_DIP16:
default:
pB->i2eDataWidth16 = false;
pB->i2eMaxIrq = 7;
break;
}
break;
default:
I2_COMPLETE(pB, I2EE_BAD_FAMILY);
break;
}
pB->i2eFifoRemains = 0;
switch (pB->i2ePom.e.porBus & POR_BUS_TYPE)
{
case POR_BUS_T_ISA:
case POR_BUS_T_UNK:
case POR_BUS_T_MCA:
case POR_BUS_T_EISA:
break;
default:
I2_COMPLETE(pB, I2EE_BADBUS);
}
if (pB->i2eDataWidth16)
{
pB->i2eWriteBuf = iiWriteBuf16;
pB->i2eReadBuf = iiReadBuf16;
pB->i2eWriteWord = iiWriteWord16;
pB->i2eReadWord = iiReadWord16;
} else {
pB->i2eWriteBuf = iiWriteBuf8;
pB->i2eReadBuf = iiReadBuf8;
pB->i2eWriteWord = iiWriteWord8;
pB->i2eReadWord = iiReadWord8;
}
switch(pB->i2eFifoStyle)
{
case FIFO_II:
pB->i2eWaitForTxEmpty = iiWaitForTxEmptyII;
pB->i2eTxMailEmpty = iiTxMailEmptyII;
pB->i2eTrySendMail = iiTrySendMailII;
pB->i2eGetMail = iiGetMailII;
pB->i2eEnableMailIrq = iiEnableMailIrqII;
pB->i2eWriteMask = iiWriteMaskII;
break;
case FIFO_IIEX:
pB->i2eWaitForTxEmpty = iiWaitForTxEmptyIIEX;
pB->i2eTxMailEmpty = iiTxMailEmptyIIEX;
pB->i2eTrySendMail = iiTrySendMailIIEX;
pB->i2eGetMail = iiGetMailIIEX;
pB->i2eEnableMailIrq = iiEnableMailIrqIIEX;
pB->i2eWriteMask = iiWriteMaskIIEX;
break;
default:
I2_COMPLETE(pB, I2EE_INCONSIST);
}
pB->i2eState = II_STATE_READY;
pB->i2eStartMail = iiGetMail(pB);
pB->i2eStartMail = NO_MAIL_HERE;
pB->i2eValid = I2E_MAGIC;
I2_COMPLETE(pB, I2EE_GOOD);
}
static void
ii2DelayTimer(unsigned int mseconds)
{
msleep_interruptible(mseconds);
}
static void
ii2Nop(void)
{
return;
}
static int
iiWriteBuf16(i2eBordStrPtr pB, unsigned char *address, int count)
{
if (pB->i2eValid != I2E_MAGIC)
I2_COMPLETE(pB, I2EE_INVALID);
I2_OUTSW(pB->i2eData, address, count);
I2_COMPLETE(pB, I2EE_GOOD);
}
static int
iiWriteBuf8(i2eBordStrPtr pB, unsigned char *address, int count)
{
if (pB->i2eValid != I2E_MAGIC)
I2_COMPLETE(pB, I2EE_INVALID);
I2_OUTSB(pB->i2eData, address, count);
I2_COMPLETE(pB, I2EE_GOOD);
}
static int
iiReadBuf16(i2eBordStrPtr pB, unsigned char *address, int count)
{
if (pB->i2eValid != I2E_MAGIC)
I2_COMPLETE(pB, I2EE_INVALID);
I2_INSW(pB->i2eData, address, count);
I2_COMPLETE(pB, I2EE_GOOD);
}
static int
iiReadBuf8(i2eBordStrPtr pB, unsigned char *address, int count)
{
if (pB->i2eValid != I2E_MAGIC)
I2_COMPLETE(pB, I2EE_INVALID);
I2_INSB(pB->i2eData, address, count);
I2_COMPLETE(pB, I2EE_GOOD);
}
static unsigned short
iiReadWord16(i2eBordStrPtr pB)
{
return inw(pB->i2eData);
}
static unsigned short
iiReadWord8(i2eBordStrPtr pB)
{
unsigned short urs;
urs = inb(pB->i2eData);
return (inb(pB->i2eData) << 8) | urs;
}
static void
iiWriteWord16(i2eBordStrPtr pB, unsigned short value)
{
outw((int)value, pB->i2eData);
}
static void
iiWriteWord8(i2eBordStrPtr pB, unsigned short value)
{
outb((char)value, pB->i2eData);
outb((char)(value >> 8), pB->i2eData);
}
static int
iiWaitForTxEmptyII(i2eBordStrPtr pB, int mSdelay)
{
unsigned long flags;
int itemp;
for (;;)
{
write_lock_irqsave(&Dl_spinlock, flags);
outb(SEL_COMMAND, pB->i2ePointer);
outb(SEL_CMD_SH, pB->i2ePointer);
itemp = inb(pB->i2eStatus);
outb(SEL_COMMAND, pB->i2ePointer);
outb(SEL_CMD_UNSH, pB->i2ePointer);
if (itemp & ST_IN_EMPTY)
{
I2_UPDATE_FIFO_ROOM(pB);
write_unlock_irqrestore(&Dl_spinlock, flags);
I2_COMPLETE(pB, I2EE_GOOD);
}
write_unlock_irqrestore(&Dl_spinlock, flags);
if (mSdelay-- == 0)
break;
iiDelay(pB, 1);
}
I2_COMPLETE(pB, I2EE_TXE_TIME);
}
static int
iiWaitForTxEmptyIIEX(i2eBordStrPtr pB, int mSdelay)
{
unsigned long flags;
for (;;)
{
write_lock_irqsave(&Dl_spinlock, flags);
if (inb(pB->i2eStatus) & STE_OUT_MT) {
I2_UPDATE_FIFO_ROOM(pB);
write_unlock_irqrestore(&Dl_spinlock, flags);
I2_COMPLETE(pB, I2EE_GOOD);
}
write_unlock_irqrestore(&Dl_spinlock, flags);
if (mSdelay-- == 0)
break;
iiDelay(pB, 1);
}
I2_COMPLETE(pB, I2EE_TXE_TIME);
}
static int
iiTxMailEmptyII(i2eBordStrPtr pB)
{
int port = pB->i2ePointer;
outb(SEL_OUTMAIL, port);
return inb(port) == 0;
}
static int
iiTxMailEmptyIIEX(i2eBordStrPtr pB)
{
return !(inb(pB->i2eStatus) & STE_OUT_MAIL);
}
static int
iiTrySendMailII(i2eBordStrPtr pB, unsigned char mail)
{
int port = pB->i2ePointer;
outb(SEL_OUTMAIL, port);
if (inb(port) == 0) {
outb(SEL_OUTMAIL, port);
outb(mail, port);
return 1;
}
return 0;
}
static int
iiTrySendMailIIEX(i2eBordStrPtr pB, unsigned char mail)
{
if (inb(pB->i2eStatus) & STE_OUT_MAIL)
return 0;
outb(mail, pB->i2eXMail);
return 1;
}
static unsigned short
iiGetMailII(i2eBordStrPtr pB)
{
if (I2_HAS_MAIL(pB)) {
outb(SEL_INMAIL, pB->i2ePointer);
return inb(pB->i2ePointer);
} else {
return NO_MAIL_HERE;
}
}
static unsigned short
iiGetMailIIEX(i2eBordStrPtr pB)
{
if (I2_HAS_MAIL(pB))
return inb(pB->i2eXMail);
else
return NO_MAIL_HERE;
}
static void
iiEnableMailIrqII(i2eBordStrPtr pB)
{
outb(SEL_MASK, pB->i2ePointer);
outb(ST_IN_MAIL, pB->i2ePointer);
}
static void
iiEnableMailIrqIIEX(i2eBordStrPtr pB)
{
outb(MX_IN_MAIL, pB->i2eXMask);
}
static void
iiWriteMaskII(i2eBordStrPtr pB, unsigned char value)
{
outb(SEL_MASK, pB->i2ePointer);
outb(value, pB->i2ePointer);
}
static void
iiWriteMaskIIEX(i2eBordStrPtr pB, unsigned char value)
{
outb(value, pB->i2eXMask);
}
static int
iiDownloadBlock ( i2eBordStrPtr pB, loadHdrStrPtr pSource, int isStandard)
{
int itemp;
int loadedFirst;
if (pB->i2eValid != I2E_MAGIC) return II_DOWN_BADVALID;
switch(pB->i2eState)
{
case II_STATE_READY:
if (pSource->e.loadMagic != MAGIC_LOADFILE)
{
return II_DOWN_BADFILE;
}
pB->i2eToLoad = 1 + pSource->e.loadBlocksMore;
pB->i2eState = II_STATE_LOADING;
pB->i2eLVersion = pSource->e.loadVersion;
pB->i2eLRevision = pSource->e.loadRevision;
pB->i2eLSub = pSource->e.loadSubRevision;
loadedFirst = 1;
break;
case II_STATE_LOADING:
loadedFirst = 0;
break;
default:
return II_DOWN_BADSTATE;
}
if (!iiWaitForTxEmpty(pB, MAX_DLOAD_READ_TIME)) {
return II_DOWN_TIMEOUT;
}
if (!iiWriteBuf(pB, pSource->c, LOADWARE_BLOCK_SIZE)) {
return II_DOWN_BADVALID;
}
if (loadedFirst) {
if (!iiWaitForTxEmpty(pB, MAX_DLOAD_START_TIME)) {
return II_DOWN_TIMEOUT;
}
}
if (--(pB->i2eToLoad)) {
return II_DOWN_CONTINUING;
}
if (!iiWaitForTxEmpty(pB, MAX_DLOAD_READ_TIME)) {
return II_DOWN_TIMEOUT;
}
itemp = MAX_DLOAD_ACK_TIME/10;
while (--itemp) {
if (I2_HAS_INPUT(pB)) {
switch (inb(pB->i2eData)) {
case LOADWARE_OK:
pB->i2eState =
isStandard ? II_STATE_STDLOADED :II_STATE_LOADED;
if (pB->i2ePom.e.porDiag2 & POR_DEBUG_PORT) {
iiDelay(pB, 700);
}
return II_DOWN_GOOD;
case LOADWARE_BAD:
default:
return II_DOWN_BAD;
}
}
iiDelay(pB, 10);
}
pB->i2eState = II_STATE_BADLOAD;
return II_DOWN_TIMEOUT;
}
static int
iiDownloadAll(i2eBordStrPtr pB, loadHdrStrPtr pSource, int isStandard, int size)
{
int status;
if (pB->i2eState != II_STATE_READY) return II_DOWN_BADSTATE;
while (size > 0) {
size -= LOADWARE_BLOCK_SIZE;
status = iiDownloadBlock(pB, pSource++, isStandard);
switch(status)
{
case II_DOWN_GOOD:
return ( (size > 0) ? II_DOWN_OVER : II_DOWN_GOOD);
case II_DOWN_CONTINUING:
break;
default:
return status;
}
}
return II_DOWN_UNDER;
}
