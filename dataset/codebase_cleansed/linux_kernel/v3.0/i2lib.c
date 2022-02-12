static void
WriteDBGBuf(char *s, unsigned char *src, unsigned short n )
{
char *p = src;
while (*s) {
DBGBuf[I] = *s++;
I = I++ & 0x3fff;
}
while (n--) {
DBGBuf[I] = *p++;
I = I++ & 0x3fff;
}
}
static void
fatality(i2eBordStrPtr pB )
{
int i;
for (i=0;i<sizeof(DBGBuf);i++) {
if ((i%16) == 0)
printk("\n%4x:",i);
printk("%02x ",DBGBuf[i]);
}
printk("\n");
for (i=0;i<sizeof(DBGBuf);i++) {
if ((i%16) == 0)
printk("\n%4x:",i);
if (DBGBuf[i] >= ' ' && DBGBuf[i] <= '~') {
printk(" %c ",DBGBuf[i]);
} else {
printk(" . ");
}
}
printk("\n");
printk("Last index %x\n",I);
}
static inline int
i2Validate ( i2ChanStrPtr pCh )
{
return ((pCh->validity & (CHANNEL_MAGIC_BITS | CHANNEL_SUPPORT))
== (CHANNEL_MAGIC | CHANNEL_SUPPORT));
}
static void iiSendPendingMail_t(unsigned long data)
{
i2eBordStrPtr pB = (i2eBordStrPtr)data;
iiSendPendingMail(pB);
}
static void
iiSendPendingMail(i2eBordStrPtr pB)
{
if (pB->i2eOutMailWaiting && (!pB->i2eWaitingForEmptyFifo) )
{
if (iiTrySendMail(pB, pB->i2eOutMailWaiting))
{
pB->i2eWaitingForEmptyFifo |=
(pB->i2eOutMailWaiting & MB_OUT_STUFFED);
pB->i2eOutMailWaiting = 0;
pB->SendPendingRetry = 0;
} else {
if( ++pB->SendPendingRetry < 16 ) {
setup_timer(&pB->SendPendingTimer,
iiSendPendingMail_t, (unsigned long)pB);
mod_timer(&pB->SendPendingTimer, jiffies + 1);
} else {
printk( KERN_ERR "IP2: iiSendPendingMail unable to queue outbound mail\n" );
}
}
}
}
static int
i2InitChannels ( i2eBordStrPtr pB, int nChannels, i2ChanStrPtr pCh)
{
int index, stuffIndex;
i2ChanStrPtr *ppCh;
if (pB->i2eValid != I2E_MAGIC) {
I2_COMPLETE(pB, I2EE_BADMAGIC);
}
if (pB->i2eState != II_STATE_STDLOADED) {
I2_COMPLETE(pB, I2EE_BADSTATE);
}
rwlock_init(&pB->read_fifo_spinlock);
rwlock_init(&pB->write_fifo_spinlock);
rwlock_init(&pB->Dbuf_spinlock);
rwlock_init(&pB->Bbuf_spinlock);
rwlock_init(&pB->Fbuf_spinlock);
pB->i2eChannelPtr = pCh;
pB->i2eChannelCnt = nChannels;
pB->i2Fbuf_strip = pB->i2Fbuf_stuff = 0;
pB->i2Dbuf_strip = pB->i2Dbuf_stuff = 0;
pB->i2Bbuf_strip = pB->i2Bbuf_stuff = 0;
pB->SendPendingRetry = 0;
memset ( pCh, 0, sizeof (i2ChanStr) * nChannels );
for (index = stuffIndex = 0, ppCh = (i2ChanStrPtr *)(pB->i2Fbuf);
nChannels && index < ABS_MOST_PORTS;
index++)
{
if ( !(pB->i2eChannelMap[index >> 4] & (1 << (index & 0xf)) ) ) {
continue;
}
rwlock_init(&pCh->Ibuf_spinlock);
rwlock_init(&pCh->Obuf_spinlock);
rwlock_init(&pCh->Cbuf_spinlock);
rwlock_init(&pCh->Pbuf_spinlock);
if (pB->i2eGoodMap[index >> 4] & (1 << (index & 0xf)) ) {
pCh->validity = CHANNEL_MAGIC | CHANNEL_SUPPORT;
} else {
pCh->validity = CHANNEL_MAGIC;
}
pCh->pMyBord = pB;
if ( pCh->validity & CHANNEL_SUPPORT ) {
pCh->infl.hd.i2sChannel = index;
pCh->infl.hd.i2sCount = 5;
pCh->infl.hd.i2sType = PTYPE_BYPASS;
pCh->infl.fcmd = 37;
pCh->infl.asof = 0;
pCh->infl.room = IBUF_SIZE - 1;
pCh->whenSendFlow = (IBUF_SIZE/5)*4;
pCh->channelNeeds = NEED_FLOW;
pCh->sinceLastFlow = 0;
stuffIndex++;
*ppCh++ = pCh;
}
pCh->outfl.asof = 0;
pCh->outfl.room = 0;
pCh->Ibuf_stuff = pCh->Ibuf_strip = 0;
pCh->Obuf_stuff = pCh->Obuf_strip = 0;
pCh->Cbuf_stuff = pCh->Cbuf_strip = 0;
memset( &pCh->icount, 0, sizeof (struct async_icount) );
pCh->hotKeyIn = HOT_CLEAR;
pCh->channelOptions = 0;
pCh->bookMarks = 0;
init_waitqueue_head(&pCh->pBookmarkWait);
init_waitqueue_head(&pCh->open_wait);
init_waitqueue_head(&pCh->close_wait);
init_waitqueue_head(&pCh->delta_msr_wait);
pCh->BaudBase = 921600;
pCh->BaudDivisor = 96;
pCh->dataSetIn = 0;
pCh->dataSetOut = 0;
pCh->wopen = 0;
pCh->throttled = 0;
pCh->speed = CBR_9600;
pCh->flags = 0;
pCh->ClosingDelay = 5*HZ/10;
pCh->ClosingWaitTime = 30*HZ;
INIT_WORK(&pCh->tqueue_input, do_input);
INIT_WORK(&pCh->tqueue_status, do_status);
#ifdef IP2DEBUG_TRACE
pCh->trace = ip2trace;
#endif
++pCh;
--nChannels;
}
pB->i2Fbuf_stuff = stuffIndex;
I2_COMPLETE(pB, I2EE_GOOD);
}
static i2ChanStrPtr
i2DeQueueNeeds(i2eBordStrPtr pB, int type)
{
unsigned short queueIndex;
unsigned long flags;
i2ChanStrPtr pCh = NULL;
switch(type) {
case NEED_INLINE:
write_lock_irqsave(&pB->Dbuf_spinlock, flags);
if ( pB->i2Dbuf_stuff != pB->i2Dbuf_strip)
{
queueIndex = pB->i2Dbuf_strip;
pCh = pB->i2Dbuf[queueIndex];
queueIndex++;
if (queueIndex >= CH_QUEUE_SIZE) {
queueIndex = 0;
}
pB->i2Dbuf_strip = queueIndex;
pCh->channelNeeds &= ~NEED_INLINE;
}
write_unlock_irqrestore(&pB->Dbuf_spinlock, flags);
break;
case NEED_BYPASS:
write_lock_irqsave(&pB->Bbuf_spinlock, flags);
if (pB->i2Bbuf_stuff != pB->i2Bbuf_strip)
{
queueIndex = pB->i2Bbuf_strip;
pCh = pB->i2Bbuf[queueIndex];
queueIndex++;
if (queueIndex >= CH_QUEUE_SIZE) {
queueIndex = 0;
}
pB->i2Bbuf_strip = queueIndex;
pCh->channelNeeds &= ~NEED_BYPASS;
}
write_unlock_irqrestore(&pB->Bbuf_spinlock, flags);
break;
case NEED_FLOW:
write_lock_irqsave(&pB->Fbuf_spinlock, flags);
if (pB->i2Fbuf_stuff != pB->i2Fbuf_strip)
{
queueIndex = pB->i2Fbuf_strip;
pCh = pB->i2Fbuf[queueIndex];
queueIndex++;
if (queueIndex >= CH_QUEUE_SIZE) {
queueIndex = 0;
}
pB->i2Fbuf_strip = queueIndex;
pCh->channelNeeds &= ~NEED_FLOW;
}
write_unlock_irqrestore(&pB->Fbuf_spinlock, flags);
break;
default:
printk(KERN_ERR "i2DeQueueNeeds called with bad type:%x\n",type);
break;
}
return pCh;
}
static void
i2QueueNeeds(i2eBordStrPtr pB, i2ChanStrPtr pCh, int type)
{
unsigned short queueIndex;
unsigned long flags;
switch (type) {
case NEED_INLINE:
write_lock_irqsave(&pB->Dbuf_spinlock, flags);
if ( !(pCh->channelNeeds & NEED_INLINE) )
{
pCh->channelNeeds |= NEED_INLINE;
queueIndex = pB->i2Dbuf_stuff;
pB->i2Dbuf[queueIndex++] = pCh;
if (queueIndex >= CH_QUEUE_SIZE)
queueIndex = 0;
pB->i2Dbuf_stuff = queueIndex;
}
write_unlock_irqrestore(&pB->Dbuf_spinlock, flags);
break;
case NEED_BYPASS:
write_lock_irqsave(&pB->Bbuf_spinlock, flags);
if ((type & NEED_BYPASS) && !(pCh->channelNeeds & NEED_BYPASS))
{
pCh->channelNeeds |= NEED_BYPASS;
queueIndex = pB->i2Bbuf_stuff;
pB->i2Bbuf[queueIndex++] = pCh;
if (queueIndex >= CH_QUEUE_SIZE)
queueIndex = 0;
pB->i2Bbuf_stuff = queueIndex;
}
write_unlock_irqrestore(&pB->Bbuf_spinlock, flags);
break;
case NEED_FLOW:
write_lock_irqsave(&pB->Fbuf_spinlock, flags);
if ((type & NEED_FLOW) && !(pCh->channelNeeds & NEED_FLOW))
{
pCh->channelNeeds |= NEED_FLOW;
queueIndex = pB->i2Fbuf_stuff;
pB->i2Fbuf[queueIndex++] = pCh;
if (queueIndex >= CH_QUEUE_SIZE)
queueIndex = 0;
pB->i2Fbuf_stuff = queueIndex;
}
write_unlock_irqrestore(&pB->Fbuf_spinlock, flags);
break;
case NEED_CREDIT:
pCh->channelNeeds |= NEED_CREDIT;
break;
default:
printk(KERN_ERR "i2QueueNeeds called with bad type:%x\n",type);
break;
}
return;
}
static int
i2QueueCommands(int type, i2ChanStrPtr pCh, int timeout, int nCommands,
cmdSyntaxPtr pCs0,...)
{
int totalsize = 0;
int blocksize;
int lastended;
cmdSyntaxPtr *ppCs;
cmdSyntaxPtr pCs;
int count;
int flag;
i2eBordStrPtr pB;
unsigned short maxBlock;
unsigned short maxBuff;
short bufroom;
unsigned short stuffIndex;
unsigned char *pBuf;
unsigned char *pInsert;
unsigned char *pDest, *pSource;
unsigned short channel;
int cnt;
unsigned long flags = 0;
rwlock_t *lock_var_p = NULL;
if ( !i2Validate ( pCh ) ) {
return -1;
}
ip2trace (CHANN, ITRC_QUEUE, ITRC_ENTER, 0 );
pB = pCh->pMyBord;
if (pB->i2eValid != I2E_MAGIC || pB->i2eUsingIrq == I2_IRQ_UNDEFINED)
return -2;
if (pB->i2eFatal) {
if ( pB->i2eFatalTrap ) {
(*(pB)->i2eFatalTrap)(pB);
}
return -3;
}
switch(type)
{
case PTYPE_INLINE:
flag = INL;
maxBlock = MAX_OBUF_BLOCK;
maxBuff = OBUF_SIZE;
pBuf = pCh->Obuf;
break;
case PTYPE_BYPASS:
flag = BYP;
maxBlock = MAX_CBUF_BLOCK;
maxBuff = CBUF_SIZE;
pBuf = pCh->Cbuf;
break;
default:
return -4;
}
totalsize = blocksize = sizeof(i2CmdHeader);
lastended = 0;
ppCs = &pCs0;
for ( count = nCommands; count; count--, ppCs++)
{
pCs = *ppCs;
cnt = pCs->length;
if ((blocksize + cnt > maxBlock) || lastended) {
blocksize = sizeof(i2CmdHeader);
totalsize += sizeof(i2CmdHeader);
}
totalsize += cnt;
blocksize += cnt;
lastended = pCs->flags & END;
}
for (;;) {
if ( !( pCh->flush_flags && i2RetryFlushOutput( pCh ) ) ) {
switch(type) {
case PTYPE_INLINE:
lock_var_p = &pCh->Obuf_spinlock;
write_lock_irqsave(lock_var_p, flags);
stuffIndex = pCh->Obuf_stuff;
bufroom = pCh->Obuf_strip - stuffIndex;
break;
case PTYPE_BYPASS:
lock_var_p = &pCh->Cbuf_spinlock;
write_lock_irqsave(lock_var_p, flags);
stuffIndex = pCh->Cbuf_stuff;
bufroom = pCh->Cbuf_strip - stuffIndex;
break;
default:
return -5;
}
if (--bufroom < 0) {
bufroom += maxBuff;
}
ip2trace (CHANN, ITRC_QUEUE, 2, 1, bufroom );
if (totalsize <= bufroom) {
break;
}
ip2trace(CHANN, ITRC_QUEUE, 3, 1, totalsize);
write_unlock_irqrestore(lock_var_p, flags);
} else
ip2trace(CHANN, ITRC_QUEUE, 3, 1, totalsize);
serviceOutgoingFifo(pB);
if (timeout == 0) {
return 0;
}
if (timeout > 0)
timeout--;
if (!in_interrupt()) {
schedule_timeout_interruptible(1);
} else {
return 0;
}
if (signal_pending(current)) {
return 0;
}
ip2trace (CHANN, ITRC_QUEUE, 4, 0 );
}
channel = pCh->infl.hd.i2sChannel;
pInsert = &pBuf[stuffIndex];
pDest = CMD_OF(pInsert);
for (blocksize = sizeof(i2CmdHeader), count = nCommands,
lastended = 0, ppCs = &pCs0;
count;
count--, ppCs++)
{
pCs = *ppCs;
if (pCs == CMD_BMARK_REQ) {
pCh->bookMarks++;
ip2trace (CHANN, ITRC_DRAIN, 30, 1, pCh->bookMarks );
}
cnt = pCs->length;
if ((blocksize + cnt > maxBlock) || lastended) {
ip2trace (CHANN, ITRC_QUEUE, 5, 0 );
PTYPE_OF(pInsert) = type;
CHANNEL_OF(pInsert) = channel;
CMD_COUNT_OF(pInsert) = blocksize - sizeof(i2CmdHeader);
stuffIndex += blocksize;
if(stuffIndex >= maxBuff) {
stuffIndex = 0;
pInsert = pBuf;
}
pInsert = &pBuf[stuffIndex];
pDest = CMD_OF(pInsert);
blocksize = sizeof(i2CmdHeader);
}
blocksize += cnt;
pSource = pCs->cmd;
while (cnt--) {
*pDest++ = *pSource++;
}
lastended = pCs->flags & END;
}
PTYPE_OF(pInsert) = type;
CHANNEL_OF(pInsert) = channel;
CMD_COUNT_OF(pInsert) = blocksize - sizeof(i2CmdHeader);
stuffIndex += blocksize;
if(stuffIndex >= maxBuff) {
stuffIndex = 0;
pInsert = pBuf;
}
switch(type)
{
case PTYPE_INLINE:
pCh->Obuf_stuff = stuffIndex;
write_unlock_irqrestore(&pCh->Obuf_spinlock, flags);
pB->debugInlineQueued++;
i2QueueNeeds(pB, pCh, NEED_INLINE);
break;
case PTYPE_BYPASS:
pCh->Cbuf_stuff = stuffIndex;
write_unlock_irqrestore(&pCh->Cbuf_spinlock, flags);
pB->debugBypassQueued++;
i2QueueNeeds(pB, pCh, NEED_BYPASS);
break;
}
ip2trace (CHANN, ITRC_QUEUE, ITRC_RETURN, 1, nCommands );
return nCommands;
}
static int
i2GetStatus(i2ChanStrPtr pCh, int resetBits)
{
unsigned short status;
i2eBordStrPtr pB;
ip2trace (CHANN, ITRC_STATUS, ITRC_ENTER, 2, pCh->dataSetIn, resetBits );
if ( !i2Validate ( pCh ) )
return -1;
pB = pCh->pMyBord;
status = pCh->dataSetIn;
if (resetBits)
{
pCh->dataSetIn &= ~(resetBits & (I2_BRK | I2_PAR | I2_FRA | I2_OVR));
pCh->dataSetIn &= ~(I2_DDCD | I2_DCTS | I2_DDSR | I2_DRI);
}
ip2trace (CHANN, ITRC_STATUS, ITRC_RETURN, 1, pCh->dataSetIn );
return status;
}
static int
i2Input(i2ChanStrPtr pCh)
{
int amountToMove;
unsigned short stripIndex;
int count;
unsigned long flags = 0;
ip2trace (CHANN, ITRC_INPUT, ITRC_ENTER, 0);
if ( !i2Validate( pCh ) ) {
count = -1;
goto i2Input_exit;
}
write_lock_irqsave(&pCh->Ibuf_spinlock, flags);
stripIndex = pCh->Ibuf_strip;
count = pCh->Ibuf_stuff - stripIndex;
if ( count == 0 ) {
write_unlock_irqrestore(&pCh->Ibuf_spinlock, flags);
goto i2Input_exit;
}
if ( count < 0 ) {
count += IBUF_SIZE;
}
amountToMove = pCh->pTTY->receive_room;
if (count > amountToMove) {
count = amountToMove;
}
amountToMove = IBUF_SIZE - stripIndex;
if (amountToMove > count) {
amountToMove = count;
}
pCh->pTTY->ldisc->ops->receive_buf( pCh->pTTY,
&(pCh->Ibuf[stripIndex]), NULL, amountToMove );
if (count > amountToMove) {
pCh->pTTY->ldisc->ops->receive_buf( pCh->pTTY,
pCh->Ibuf, NULL, count - amountToMove );
}
stripIndex += count;
if (stripIndex >= IBUF_SIZE) {
stripIndex -= IBUF_SIZE;
}
pCh->Ibuf_strip = stripIndex;
pCh->infl.asof += count;
if ((pCh->sinceLastFlow += count) >= pCh->whenSendFlow) {
pCh->sinceLastFlow -= pCh->whenSendFlow;
write_unlock_irqrestore(&pCh->Ibuf_spinlock, flags);
i2QueueNeeds(pCh->pMyBord, pCh, NEED_FLOW);
} else {
write_unlock_irqrestore(&pCh->Ibuf_spinlock, flags);
}
i2Input_exit:
ip2trace (CHANN, ITRC_INPUT, ITRC_RETURN, 1, count);
return count;
}
static int
i2InputFlush(i2ChanStrPtr pCh)
{
int count;
unsigned long flags;
if ( !i2Validate ( pCh ) )
return -1;
ip2trace (CHANN, ITRC_INPUT, 10, 0);
write_lock_irqsave(&pCh->Ibuf_spinlock, flags);
count = pCh->Ibuf_stuff - pCh->Ibuf_strip;
if (count < 0) {
count += IBUF_SIZE;
}
pCh->Ibuf_strip = pCh->Ibuf_stuff;
pCh->infl.asof += count;
if ( (pCh->sinceLastFlow += count) >= pCh->whenSendFlow )
{
pCh->sinceLastFlow -= pCh->whenSendFlow;
write_unlock_irqrestore(&pCh->Ibuf_spinlock, flags);
i2QueueNeeds(pCh->pMyBord, pCh, NEED_FLOW);
} else {
write_unlock_irqrestore(&pCh->Ibuf_spinlock, flags);
}
ip2trace (CHANN, ITRC_INPUT, 19, 1, count);
return count;
}
static int
i2Output(i2ChanStrPtr pCh, const char *pSource, int count)
{
i2eBordStrPtr pB;
unsigned char *pInsert;
int amountToMove;
int countOriginal = count;
unsigned short channel;
unsigned short stuffIndex;
unsigned long flags;
int bailout = 10;
ip2trace (CHANN, ITRC_OUTPUT, ITRC_ENTER, 2, count, 0 );
if ( !i2Validate ( pCh ) )
return -1;
pB = pCh->pMyBord;
channel = pCh->infl.hd.i2sChannel;
if (pB->i2eFatal) {
if (pB->i2eFatalTrap) {
(*(pB)->i2eFatalTrap)(pB);
}
return -1;
}
while ( count > 0 ) {
read_lock_irqsave(&pCh->Obuf_spinlock, flags);
amountToMove = pCh->Obuf_strip - pCh->Obuf_stuff - 1;
read_unlock_irqrestore(&pCh->Obuf_spinlock, flags);
if (amountToMove < 0) {
amountToMove += OBUF_SIZE;
}
amountToMove -= sizeof (i2DataHeader);
if ( amountToMove > (int)(MAX_OBUF_BLOCK - sizeof(i2DataHeader)) ) {
amountToMove = MAX_OBUF_BLOCK - sizeof(i2DataHeader);
}
if (amountToMove > count) {
amountToMove = count;
}
ip2trace (CHANN, ITRC_OUTPUT, 10, 1, amountToMove );
if ( !(pCh->flush_flags && i2RetryFlushOutput(pCh) )
&& amountToMove > 0 )
{
write_lock_irqsave(&pCh->Obuf_spinlock, flags);
stuffIndex = pCh->Obuf_stuff;
pInsert = &(pCh->Obuf[stuffIndex]);
CHANNEL_OF(pInsert) = channel;
PTYPE_OF(pInsert) = PTYPE_DATA;
TAG_OF(pInsert) = 0;
ID_OF(pInsert) = ID_ORDINARY_DATA;
DATA_COUNT_OF(pInsert) = amountToMove;
memcpy( (char*)(DATA_OF(pInsert)), pSource, amountToMove );
pSource += amountToMove;
pCh->Obuf_char_count += amountToMove;
stuffIndex += amountToMove + sizeof(i2DataHeader);
count -= amountToMove;
if (stuffIndex >= OBUF_SIZE) {
stuffIndex = 0;
}
pCh->Obuf_stuff = stuffIndex;
write_unlock_irqrestore(&pCh->Obuf_spinlock, flags);
ip2trace (CHANN, ITRC_OUTPUT, 13, 1, stuffIndex );
} else {
ip2trace(CHANN, ITRC_OUTPUT, 14, 3,
amountToMove, pB->i2eFifoRemains,
pB->i2eWaitingForEmptyFifo );
i2QueueNeeds(pB, pCh, NEED_INLINE);
if ( pB->i2eWaitingForEmptyFifo ) {
ip2trace (CHANN, ITRC_OUTPUT, 16, 0 );
if (!in_interrupt()) {
ip2trace (CHANN, ITRC_OUTPUT, 61, 0 );
schedule_timeout_interruptible(2);
if (signal_pending(current)) {
break;
}
continue;
} else {
ip2trace (CHANN, ITRC_OUTPUT, 62, 0 );
break;
}
break;
}
else if ( pB->i2eFifoRemains < 32 && !pB->i2eTxMailEmpty ( pB ) )
{
ip2trace (CHANN, ITRC_OUTPUT, 19, 2,
pB->i2eFifoRemains,
pB->i2eTxMailEmpty );
break;
} else if ( pCh->channelNeeds & NEED_CREDIT ) {
ip2trace (CHANN, ITRC_OUTPUT, 22, 0 );
break;
} else if ( --bailout) {
ip2trace (CHANN, ITRC_OUTPUT, 20, 0 );
serviceOutgoingFifo(pB);
} else {
ip2trace (CHANN, ITRC_OUTPUT, 21, 3,
pB->i2eFifoRemains,
pB->i2eOutMailWaiting,
pB->i2eWaitingForEmptyFifo );
break;
}
}
}
i2QueueNeeds(pB, pCh, NEED_INLINE);
if (countOriginal > count) {
ip2trace (CHANN, ITRC_OUTPUT, 17, 2, countOriginal, count );
serviceOutgoingFifo( pB );
}
ip2trace (CHANN, ITRC_OUTPUT, ITRC_RETURN, 2, countOriginal, count );
return countOriginal - count;
}
static inline void
i2FlushOutput(i2ChanStrPtr pCh)
{
ip2trace (CHANN, ITRC_FLUSH, 1, 1, pCh->flush_flags );
if (pCh->flush_flags)
return;
if ( 1 != i2QueueCommands(PTYPE_BYPASS, pCh, 0, 1, CMD_STARTFL) ) {
pCh->flush_flags = STARTFL_FLAG;
ip2trace (CHANN, ITRC_FLUSH, 2, 0 );
} else if ( 1 != i2QueueCommands(PTYPE_INLINE, pCh, 0, 1, CMD_STOPFL) ) {
pCh->flush_flags = STOPFL_FLAG;
ip2trace (CHANN, ITRC_FLUSH, 3, 0 );
}
}
static int
i2RetryFlushOutput(i2ChanStrPtr pCh)
{
int old_flags = pCh->flush_flags;
ip2trace (CHANN, ITRC_FLUSH, 14, 1, old_flags );
pCh->flush_flags = 0;
if ( old_flags & STARTFL_FLAG ) {
if ( 1 == i2QueueCommands(PTYPE_BYPASS, pCh, 0, 1, CMD_STARTFL) ) {
old_flags = STOPFL_FLAG;
} else {
old_flags = STARTFL_FLAG;
}
ip2trace (CHANN, ITRC_FLUSH, 15, 1, old_flags );
}
if ( old_flags & STOPFL_FLAG ) {
if (1 == i2QueueCommands(PTYPE_INLINE, pCh, 0, 1, CMD_STOPFL)) {
old_flags = 0;
}
ip2trace (CHANN, ITRC_FLUSH, 16, 1, old_flags );
}
pCh->flush_flags = old_flags;
ip2trace (CHANN, ITRC_FLUSH, 17, 1, old_flags );
return old_flags;
}
static void
i2DrainWakeup(unsigned long d)
{
i2ChanStrPtr pCh = (i2ChanStrPtr)d;
ip2trace (CHANN, ITRC_DRAIN, 10, 1, pCh->BookmarkTimer.expires );
pCh->BookmarkTimer.expires = 0;
wake_up_interruptible( &pCh->pBookmarkWait );
}
static void
i2DrainOutput(i2ChanStrPtr pCh, int timeout)
{
wait_queue_t wait;
i2eBordStrPtr pB;
ip2trace (CHANN, ITRC_DRAIN, ITRC_ENTER, 1, pCh->BookmarkTimer.expires);
pB = pCh->pMyBord;
if (pB->i2eFatal) {
if (pB->i2eFatalTrap) {
(*(pB)->i2eFatalTrap)(pB);
}
return;
}
if ((timeout > 0) && (pCh->BookmarkTimer.expires == 0 )) {
setup_timer(&pCh->BookmarkTimer, i2DrainWakeup,
(unsigned long)pCh);
ip2trace (CHANN, ITRC_DRAIN, 1, 1, pCh->BookmarkTimer.expires );
mod_timer(&pCh->BookmarkTimer, jiffies + timeout);
}
i2QueueCommands( PTYPE_INLINE, pCh, -1, 1, CMD_BMARK_REQ );
init_waitqueue_entry(&wait, current);
add_wait_queue(&(pCh->pBookmarkWait), &wait);
set_current_state( TASK_INTERRUPTIBLE );
serviceOutgoingFifo( pB );
schedule();
set_current_state( TASK_RUNNING );
remove_wait_queue(&(pCh->pBookmarkWait), &wait);
if ((timeout > 0) && pCh->BookmarkTimer.expires &&
time_before(jiffies, pCh->BookmarkTimer.expires)) {
del_timer( &(pCh->BookmarkTimer) );
pCh->BookmarkTimer.expires = 0;
ip2trace (CHANN, ITRC_DRAIN, 3, 1, pCh->BookmarkTimer.expires );
}
ip2trace (CHANN, ITRC_DRAIN, ITRC_RETURN, 1, pCh->BookmarkTimer.expires );
return;
}
static int
i2OutputFree(i2ChanStrPtr pCh)
{
int amountToMove;
unsigned long flags;
if ( !i2Validate ( pCh ) ) {
return -1;
}
read_lock_irqsave(&pCh->Obuf_spinlock, flags);
amountToMove = pCh->Obuf_strip - pCh->Obuf_stuff - 1;
read_unlock_irqrestore(&pCh->Obuf_spinlock, flags);
if (amountToMove < 0) {
amountToMove += OBUF_SIZE;
}
amountToMove -= sizeof(i2DataHeader);
return (amountToMove < 0) ? 0 : amountToMove;
}
static void
ip2_owake( PTTY tp)
{
i2ChanStrPtr pCh;
if (tp == NULL) return;
pCh = tp->driver_data;
ip2trace (CHANN, ITRC_SICMD, 10, 2, tp->flags,
(1 << TTY_DO_WRITE_WAKEUP) );
tty_wakeup(tp);
}
static inline void
set_baud_params(i2eBordStrPtr pB)
{
int i,j;
i2ChanStrPtr *pCh;
pCh = (i2ChanStrPtr *) pB->i2eChannelPtr;
for (i = 0; i < ABS_MAX_BOXES; i++) {
if (pB->channelBtypes.bid_value[i]) {
if (BID_HAS_654(pB->channelBtypes.bid_value[i])) {
for (j = 0; j < ABS_BIGGEST_BOX; j++) {
if (pCh[i*16+j] == NULL)
break;
(pCh[i*16+j])->BaudBase = 921600;
(pCh[i*16+j])->BaudDivisor = 96;
}
} else {
for (j = 0; j < ABS_BIGGEST_BOX; j++) {
if (pCh[i*16+j] == NULL)
break;
(pCh[i*16+j])->BaudBase = 115200;
(pCh[i*16+j])->BaudDivisor = 12;
}
}
}
}
}
static inline void
i2StripFifo(i2eBordStrPtr pB)
{
i2ChanStrPtr pCh;
int channel;
int count;
unsigned short stuffIndex;
int amountToRead;
unsigned char *pc, *pcLimit;
unsigned char uc;
unsigned char dss_change;
unsigned long bflags,cflags;
while (I2_HAS_INPUT(pB)) {
write_lock_irqsave(&pB->read_fifo_spinlock, bflags);
pB->i2eLeadoffWord[0] = iiReadWord(pB);
switch(PTYPE_OF(pB->i2eLeadoffWord))
{
case PTYPE_DATA:
pB->got_input = 1;
channel = CHANNEL_OF(pB->i2eLeadoffWord);
count = iiReadWord(pB);
if ( ((unsigned int)count) > IBUF_SIZE ) {
pB->i2eFatal = 2;
write_unlock_irqrestore(&pB->read_fifo_spinlock,
bflags);
return;
}
if ((channel >= pB->i2eChannelCnt) ||
(NULL==(pCh = ((i2ChanStrPtr*)pB->i2eChannelPtr)[channel])))
{
iiReadBuf(pB, junkBuffer, count);
write_unlock_irqrestore(&pB->read_fifo_spinlock,
bflags);
break;
}
if(ID_OF(pB->i2eLeadoffWord) == ID_HOT_KEY)
{
pCh->hotKeyIn = iiReadWord(pB) & 0xff;
write_unlock_irqrestore(&pB->read_fifo_spinlock,
bflags);
i2QueueCommands(PTYPE_BYPASS, pCh, 0, 1, CMD_HOTACK);
break;
}
write_lock_irqsave(&pCh->Ibuf_spinlock, cflags);
stuffIndex = pCh->Ibuf_stuff;
amountToRead = IBUF_SIZE - stuffIndex;
if (amountToRead > count)
amountToRead = count;
iiReadBuf(pB, &(pCh->Ibuf[stuffIndex]), amountToRead);
pCh->icount.rx += amountToRead;
stuffIndex += amountToRead;
if (stuffIndex >= IBUF_SIZE) {
if ((amountToRead & 1) && (count > amountToRead)) {
pCh->Ibuf[0] = pCh->Ibuf[IBUF_SIZE];
amountToRead++;
stuffIndex = 1;
} else {
stuffIndex = 0;
}
}
if (count > amountToRead) {
amountToRead = count - amountToRead;
iiReadBuf(pB, &(pCh->Ibuf[stuffIndex]), amountToRead);
pCh->icount.rx += amountToRead;
stuffIndex += amountToRead;
}
pCh->Ibuf_stuff = stuffIndex;
write_unlock_irqrestore(&pCh->Ibuf_spinlock, cflags);
write_unlock_irqrestore(&pB->read_fifo_spinlock,
bflags);
#ifdef USE_IQ
schedule_work(&pCh->tqueue_input);
#else
do_input(&pCh->tqueue_input);
#endif
break;
case PTYPE_STATUS:
ip2trace (ITRC_NO_PORT, ITRC_SFIFO, 4, 0 );
count = CMD_COUNT_OF(pB->i2eLeadoffWord);
iiReadBuf(pB, cmdBuffer, count);
write_unlock_irqrestore(&pB->read_fifo_spinlock,
bflags);
pc = cmdBuffer;
pcLimit = &(cmdBuffer[count]);
while (pc < pcLimit) {
channel = *pc++;
ip2trace (channel, ITRC_SFIFO, 7, 2, channel, *pc );
if (channel < pB->i2eChannelCnt
&&
(pCh = (((i2ChanStrPtr*)pB->i2eChannelPtr)[channel])) != NULL
)
{
dss_change = 0;
switch (uc = *pc++)
{
case STAT_CTS_UP:
if ( !(pCh->dataSetIn & I2_CTS) )
{
pCh->dataSetIn |= I2_DCTS;
pCh->icount.cts++;
dss_change = 1;
}
pCh->dataSetIn |= I2_CTS;
break;
case STAT_CTS_DN:
if ( pCh->dataSetIn & I2_CTS )
{
pCh->dataSetIn |= I2_DCTS;
pCh->icount.cts++;
dss_change = 1;
}
pCh->dataSetIn &= ~I2_CTS;
break;
case STAT_DCD_UP:
ip2trace (channel, ITRC_MODEM, 1, 1, pCh->dataSetIn );
if ( !(pCh->dataSetIn & I2_DCD) )
{
ip2trace (CHANN, ITRC_MODEM, 2, 0 );
pCh->dataSetIn |= I2_DDCD;
pCh->icount.dcd++;
dss_change = 1;
}
pCh->dataSetIn |= I2_DCD;
ip2trace (channel, ITRC_MODEM, 3, 1, pCh->dataSetIn );
break;
case STAT_DCD_DN:
ip2trace (channel, ITRC_MODEM, 4, 1, pCh->dataSetIn );
if ( pCh->dataSetIn & I2_DCD )
{
ip2trace (channel, ITRC_MODEM, 5, 0 );
pCh->dataSetIn |= I2_DDCD;
pCh->icount.dcd++;
dss_change = 1;
}
pCh->dataSetIn &= ~I2_DCD;
ip2trace (channel, ITRC_MODEM, 6, 1, pCh->dataSetIn );
break;
case STAT_DSR_UP:
if ( !(pCh->dataSetIn & I2_DSR) )
{
pCh->dataSetIn |= I2_DDSR;
pCh->icount.dsr++;
dss_change = 1;
}
pCh->dataSetIn |= I2_DSR;
break;
case STAT_DSR_DN:
if ( pCh->dataSetIn & I2_DSR )
{
pCh->dataSetIn |= I2_DDSR;
pCh->icount.dsr++;
dss_change = 1;
}
pCh->dataSetIn &= ~I2_DSR;
break;
case STAT_RI_UP:
if ( !(pCh->dataSetIn & I2_RI) )
{
pCh->dataSetIn |= I2_DRI;
pCh->icount.rng++;
dss_change = 1;
}
pCh->dataSetIn |= I2_RI ;
break;
case STAT_RI_DN:
pCh->dataSetIn &= ~I2_RI ;
break;
case STAT_BRK_DET:
pCh->dataSetIn |= I2_BRK;
pCh->icount.brk++;
dss_change = 1;
break;
case STAT_BMARK:
pCh->bookMarks--;
if (pCh->bookMarks <= 0 ) {
pCh->bookMarks = 0;
wake_up_interruptible( &pCh->pBookmarkWait );
ip2trace (channel, ITRC_DRAIN, 20, 1, pCh->BookmarkTimer.expires );
}
break;
case STAT_FLOW:
pCh->outfl.room =
((flowStatPtr)pc)->room -
(pCh->outfl.asof - ((flowStatPtr)pc)->asof);
ip2trace (channel, ITRC_STFLW, 1, 1, pCh->outfl.room );
if (pCh->channelNeeds & NEED_CREDIT)
{
ip2trace (channel, ITRC_STFLW, 2, 1, pCh->channelNeeds);
pCh->channelNeeds &= ~NEED_CREDIT;
i2QueueNeeds(pB, pCh, NEED_INLINE);
if ( pCh->pTTY )
ip2_owake(pCh->pTTY);
}
ip2trace (channel, ITRC_STFLW, 3, 1, pCh->channelNeeds);
pc += sizeof(flowStat);
break;
case STAT_STATUS:
pCh->channelStatus = *((debugStatPtr)pc);
pc += sizeof(debugStat);
break;
case STAT_TXCNT:
pCh->channelTcount = *((cntStatPtr)pc);
pc += sizeof(cntStat);
break;
case STAT_RXCNT:
pCh->channelRcount = *((cntStatPtr)pc);
pc += sizeof(cntStat);
break;
case STAT_BOXIDS:
pB->channelBtypes = *((bidStatPtr)pc);
pc += sizeof(bidStat);
set_baud_params(pB);
break;
case STAT_HWFAIL:
i2QueueCommands (PTYPE_INLINE, pCh, 0, 1, CMD_HW_TEST);
pCh->channelFail = *((failStatPtr)pc);
pc += sizeof(failStat);
break;
default:
switch (uc & STAT_MOD_ERROR)
{
case STAT_ERROR:
if (uc & STAT_E_PARITY) {
pCh->dataSetIn |= I2_PAR;
pCh->icount.parity++;
}
if (uc & STAT_E_FRAMING){
pCh->dataSetIn |= I2_FRA;
pCh->icount.frame++;
}
if (uc & STAT_E_OVERRUN){
pCh->dataSetIn |= I2_OVR;
pCh->icount.overrun++;
}
break;
case STAT_MODEM:
pCh->dataSetIn = (pCh->dataSetIn
& ~(I2_RI | I2_CTS | I2_DCD | I2_DSR) )
| xlatDss[uc & 0xf];
wake_up_interruptible ( &pCh->dss_now_wait );
default:
break;
}
}
if (dss_change) {
#ifdef USE_IQ
schedule_work(&pCh->tqueue_status);
#else
do_status(&pCh->tqueue_status);
#endif
}
}
else
{
switch (*pc++)
{
case STAT_FLOW:
pc += 4;
break;
default:
break;
}
}
}
break;
default:
ip2trace (ITRC_NO_PORT, ITRC_SFIFO, 5, 1,
PTYPE_OF(pB->i2eLeadoffWord) );
write_unlock_irqrestore(&pB->read_fifo_spinlock,
bflags);
break;
}
}
ip2trace (ITRC_NO_PORT, ITRC_SFIFO, ITRC_RETURN, 0 );
pB->i2eOutMailWaiting |= MB_IN_STRIPPED;
return;
}
static int
i2Write2Fifo(i2eBordStrPtr pB, unsigned char *source, int count,int reserve)
{
int rc = 0;
unsigned long flags;
write_lock_irqsave(&pB->write_fifo_spinlock, flags);
if (!pB->i2eWaitingForEmptyFifo) {
if (pB->i2eFifoRemains > (count+reserve)) {
pB->i2eFifoRemains -= count;
iiWriteBuf(pB, source, count);
pB->i2eOutMailWaiting |= MB_OUT_STUFFED;
rc = count;
}
}
write_unlock_irqrestore(&pB->write_fifo_spinlock, flags);
return rc;
}
static inline void
i2StuffFifoBypass(i2eBordStrPtr pB)
{
i2ChanStrPtr pCh;
unsigned char *pRemove;
unsigned short stripIndex;
unsigned short packetSize;
unsigned short paddedSize;
unsigned short notClogged = 1;
unsigned long flags;
int bailout = 1000;
while ( --bailout && notClogged &&
(NULL != (pCh = i2DeQueueNeeds(pB,NEED_BYPASS))))
{
write_lock_irqsave(&pCh->Cbuf_spinlock, flags);
stripIndex = pCh->Cbuf_strip;
while (stripIndex != pCh->Cbuf_stuff) {
pRemove = &(pCh->Cbuf[stripIndex]);
packetSize = CMD_COUNT_OF(pRemove) + sizeof(i2CmdHeader);
paddedSize = roundup(packetSize, 2);
if (paddedSize > 0) {
if ( 0 == i2Write2Fifo(pB, pRemove, paddedSize,0)) {
notClogged = 0;
i2QueueNeeds(pB, pCh, NEED_BYPASS);
break;
}
}
#ifdef DEBUG_FIFO
WriteDBGBuf("BYPS", pRemove, paddedSize);
#endif
pB->debugBypassCount++;
pRemove += packetSize;
stripIndex += packetSize;
if (stripIndex >= CBUF_SIZE) {
stripIndex = 0;
pRemove = pCh->Cbuf;
}
}
pCh->Cbuf_strip = stripIndex;
write_unlock_irqrestore(&pCh->Cbuf_spinlock, flags);
}
#ifdef IP2DEBUG_TRACE
if ( !bailout ) {
ip2trace (ITRC_NO_PORT, ITRC_ERROR, 1, 0 );
}
#endif
}
static inline void
i2StuffFifoFlow(i2eBordStrPtr pB)
{
i2ChanStrPtr pCh;
unsigned short paddedSize = roundup(sizeof(flowIn), 2);
ip2trace (ITRC_NO_PORT, ITRC_SFLOW, ITRC_ENTER, 2,
pB->i2eFifoRemains, paddedSize );
while ( (NULL != (pCh = i2DeQueueNeeds(pB,NEED_FLOW)))) {
pB->debugFlowCount++;
if ( 0 == i2Write2Fifo(pB,(unsigned char *)&(pCh->infl),paddedSize,0)) {
break;
}
#ifdef DEBUG_FIFO
WriteDBGBuf("FLOW",(unsigned char *) &(pCh->infl), paddedSize);
#endif
}
ip2trace (ITRC_NO_PORT, ITRC_SFLOW, ITRC_RETURN, 0 );
}
static inline void
i2StuffFifoInline(i2eBordStrPtr pB)
{
i2ChanStrPtr pCh;
unsigned char *pRemove;
unsigned short stripIndex;
unsigned short packetSize;
unsigned short paddedSize;
unsigned short notClogged = 1;
unsigned short flowsize;
unsigned long flags;
int bailout = 1000;
int bailout2;
ip2trace (ITRC_NO_PORT, ITRC_SICMD, ITRC_ENTER, 3, pB->i2eFifoRemains,
pB->i2Dbuf_strip, pB->i2Dbuf_stuff );
while ( --bailout && notClogged &&
(NULL != (pCh = i2DeQueueNeeds(pB,NEED_INLINE))) )
{
write_lock_irqsave(&pCh->Obuf_spinlock, flags);
stripIndex = pCh->Obuf_strip;
ip2trace (CHANN, ITRC_SICMD, 3, 2, stripIndex, pCh->Obuf_stuff );
bailout2 = 1000;
while ( --bailout2 && stripIndex != pCh->Obuf_stuff) {
pRemove = &(pCh->Obuf[stripIndex]);
if (PTYPE_OF(pRemove) == PTYPE_DATA) {
flowsize = DATA_COUNT_OF(pRemove);
packetSize = flowsize + sizeof(i2DataHeader);
} else {
flowsize = CMD_COUNT_OF(pRemove);
packetSize = flowsize + sizeof(i2CmdHeader);
}
flowsize = CREDIT_USAGE(flowsize);
paddedSize = roundup(packetSize, 2);
ip2trace (CHANN, ITRC_SICMD, 4, 2, pB->i2eFifoRemains, paddedSize );
ip2trace (CHANN, ITRC_SICMD, 5, 2, pCh->outfl.room, flowsize );
if (pCh->outfl.room <= flowsize) {
i2QueueNeeds(pB, pCh, NEED_CREDIT);
notClogged = 0;
break;
}
if ( (paddedSize > 0)
&& ( 0 == i2Write2Fifo(pB, pRemove, paddedSize, 128))) {
notClogged = 0;
i2QueueNeeds(pB, pCh, NEED_INLINE);
break;
}
#ifdef DEBUG_FIFO
WriteDBGBuf("DATA", pRemove, paddedSize);
#endif
pB->debugInlineCount++;
pCh->icount.tx += flowsize;
pCh->outfl.room -= flowsize;
pCh->outfl.asof += flowsize;
if (PTYPE_OF(pRemove) == PTYPE_DATA) {
pCh->Obuf_char_count -= DATA_COUNT_OF(pRemove);
}
pRemove += packetSize;
stripIndex += packetSize;
ip2trace (CHANN, ITRC_SICMD, 6, 2, stripIndex, pCh->Obuf_strip);
if (stripIndex >= OBUF_SIZE) {
stripIndex = 0;
pRemove = pCh->Obuf;
ip2trace (CHANN, ITRC_SICMD, 7, 1, stripIndex );
}
}
if ( !bailout2 ) {
ip2trace (CHANN, ITRC_ERROR, 3, 0 );
}
pCh->Obuf_strip = stripIndex;
write_unlock_irqrestore(&pCh->Obuf_spinlock, flags);
if ( notClogged )
{
ip2trace (CHANN, ITRC_SICMD, 8, 0 );
if ( pCh->pTTY ) {
ip2_owake(pCh->pTTY);
}
}
}
if ( !bailout ) {
ip2trace (ITRC_NO_PORT, ITRC_ERROR, 4, 0 );
}
ip2trace (ITRC_NO_PORT, ITRC_SICMD, ITRC_RETURN, 1,pB->i2Dbuf_strip);
}
static void
serviceOutgoingFifo(i2eBordStrPtr pB)
{
if ( ! pB->i2eWaitingForEmptyFifo )
{
i2StuffFifoFlow(pB);
i2StuffFifoBypass(pB);
i2StuffFifoInline(pB);
iiSendPendingMail(pB);
}
}
static inline int
i2ServiceBoard ( i2eBordStrPtr pB )
{
unsigned inmail;
unsigned long flags;
if (NO_MAIL_HERE == ( inmail = pB->i2eStartMail ) ) {
inmail = iiGetMail(pB);
}
pB->i2eStartMail = NO_MAIL_HERE;
ip2trace (ITRC_NO_PORT, ITRC_INTR, 2, 1, inmail );
if (inmail != NO_MAIL_HERE) {
if ( inmail & MB_FATAL_ERROR ) {
pB->i2eFatal = 1;
goto exit_i2ServiceBoard;
}
if ( inmail & MB_IN_STUFFED ) {
pB->i2eFifoInInts++;
i2StripFifo(pB);
}
if (inmail & MB_OUT_STRIPPED) {
pB->i2eFifoOutInts++;
write_lock_irqsave(&pB->write_fifo_spinlock, flags);
pB->i2eFifoRemains = pB->i2eFifoSize;
pB->i2eWaitingForEmptyFifo = 0;
write_unlock_irqrestore(&pB->write_fifo_spinlock,
flags);
ip2trace (ITRC_NO_PORT, ITRC_INTR, 30, 1, pB->i2eFifoRemains );
}
serviceOutgoingFifo(pB);
}
ip2trace (ITRC_NO_PORT, ITRC_INTR, 8, 0 );
exit_i2ServiceBoard:
return 0;
}
