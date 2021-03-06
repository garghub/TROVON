unsigned int aac_response_normal(struct aac_queue * q)
{
struct aac_dev * dev = q->dev;
struct aac_entry *entry;
struct hw_fib * hwfib;
struct fib * fib;
int consumed = 0;
unsigned long flags, mflags;
spin_lock_irqsave(q->lock, flags);
while(aac_consumer_get(dev, q, &entry))
{
int fast;
u32 index = le32_to_cpu(entry->addr);
fast = index & 0x01;
fib = &dev->fibs[index >> 2];
hwfib = fib->hw_fib_va;
aac_consumer_free(dev, q, HostNormRespQueue);
dev->queues->queue[AdapNormCmdQueue].numpending--;
if (unlikely(fib->flags & FIB_CONTEXT_FLAG_TIMED_OUT)) {
spin_unlock_irqrestore(q->lock, flags);
aac_fib_complete(fib);
aac_fib_free(fib);
spin_lock_irqsave(q->lock, flags);
continue;
}
spin_unlock_irqrestore(q->lock, flags);
if (fast) {
*(__le32 *)hwfib->data = cpu_to_le32(ST_OK);
hwfib->header.XferState |= cpu_to_le32(AdapterProcessed);
fib->flags |= FIB_CONTEXT_FLAG_FASTRESP;
}
FIB_COUNTER_INCREMENT(aac_config.FibRecved);
if (hwfib->header.Command == cpu_to_le16(NuFileSystem))
{
__le32 *pstatus = (__le32 *)hwfib->data;
if (*pstatus & cpu_to_le32(0xffff0000))
*pstatus = cpu_to_le32(ST_OK);
}
if (hwfib->header.XferState & cpu_to_le32(NoResponseExpected | Async))
{
if (hwfib->header.XferState & cpu_to_le32(NoResponseExpected))
FIB_COUNTER_INCREMENT(aac_config.NoResponseRecved);
else
FIB_COUNTER_INCREMENT(aac_config.AsyncRecved);
fib->flags &= FIB_CONTEXT_FLAG_FASTRESP;
fib->callback(fib->callback_data, fib);
} else {
unsigned long flagv;
spin_lock_irqsave(&fib->event_lock, flagv);
if (!fib->done) {
fib->done = 1;
up(&fib->event_wait);
}
spin_unlock_irqrestore(&fib->event_lock, flagv);
spin_lock_irqsave(&dev->manage_lock, mflags);
dev->management_fib_count--;
spin_unlock_irqrestore(&dev->manage_lock, mflags);
FIB_COUNTER_INCREMENT(aac_config.NormalRecved);
if (fib->done == 2) {
spin_lock_irqsave(&fib->event_lock, flagv);
fib->done = 0;
spin_unlock_irqrestore(&fib->event_lock, flagv);
aac_fib_complete(fib);
aac_fib_free(fib);
}
}
consumed++;
spin_lock_irqsave(q->lock, flags);
}
if (consumed > aac_config.peak_fibs)
aac_config.peak_fibs = consumed;
if (consumed == 0)
aac_config.zero_fibs++;
spin_unlock_irqrestore(q->lock, flags);
return 0;
}
unsigned int aac_command_normal(struct aac_queue *q)
{
struct aac_dev * dev = q->dev;
struct aac_entry *entry;
unsigned long flags;
spin_lock_irqsave(q->lock, flags);
while(aac_consumer_get(dev, q, &entry))
{
struct fib fibctx;
struct hw_fib * hw_fib;
u32 index;
struct fib *fib = &fibctx;
index = le32_to_cpu(entry->addr) / sizeof(struct hw_fib);
hw_fib = &dev->aif_base_va[index];
if (dev->aif_thread)
if((fib = kmalloc(sizeof(struct fib), GFP_ATOMIC)) == NULL)
fib = &fibctx;
memset(fib, 0, sizeof(struct fib));
INIT_LIST_HEAD(&fib->fiblink);
fib->type = FSAFS_NTC_FIB_CONTEXT;
fib->size = sizeof(struct fib);
fib->hw_fib_va = hw_fib;
fib->data = hw_fib->data;
fib->dev = dev;
if (dev->aif_thread && fib != &fibctx) {
list_add_tail(&fib->fiblink, &q->cmdq);
aac_consumer_free(dev, q, HostNormCmdQueue);
wake_up_interruptible(&q->cmdready);
} else {
aac_consumer_free(dev, q, HostNormCmdQueue);
spin_unlock_irqrestore(q->lock, flags);
*(__le32 *)hw_fib->data = cpu_to_le32(ST_OK);
aac_fib_adapter_complete(fib, sizeof(u32));
spin_lock_irqsave(q->lock, flags);
}
}
spin_unlock_irqrestore(q->lock, flags);
return 0;
}
static void aac_aif_callback(void *context, struct fib * fibptr)
{
struct fib *fibctx;
struct aac_dev *dev;
struct aac_aifcmd *cmd;
int status;
fibctx = (struct fib *)context;
BUG_ON(fibptr == NULL);
dev = fibptr->dev;
if (fibptr->hw_fib_va->header.XferState &
cpu_to_le32(NoMoreAifDataAvailable)) {
aac_fib_complete(fibptr);
aac_fib_free(fibptr);
return;
}
aac_intr_normal(dev, 0, 1, 0, fibptr->hw_fib_va);
aac_fib_init(fibctx);
cmd = (struct aac_aifcmd *) fib_data(fibctx);
cmd->command = cpu_to_le32(AifReqEvent);
status = aac_fib_send(AifRequest,
fibctx,
sizeof(struct hw_fib)-sizeof(struct aac_fibhdr),
FsaNormal,
0, 1,
(fib_callback)aac_aif_callback, fibctx);
}
unsigned int aac_intr_normal(struct aac_dev *dev, u32 index,
int isAif, int isFastResponse, struct hw_fib *aif_fib)
{
unsigned long mflags;
dprintk((KERN_INFO "aac_intr_normal(%p,%x)\n", dev, index));
if (isAif == 1) {
struct hw_fib * hw_fib;
struct fib * fib;
struct aac_queue *q = &dev->queues->queue[HostNormCmdQueue];
unsigned long flags;
if ((!dev->aif_thread)
|| (!(fib = kzalloc(sizeof(struct fib),GFP_ATOMIC))))
return 1;
if (!(hw_fib = kzalloc(sizeof(struct hw_fib),GFP_ATOMIC))) {
kfree (fib);
return 1;
}
if (aif_fib != NULL) {
memcpy(hw_fib, aif_fib, sizeof(struct hw_fib));
} else {
memcpy(hw_fib,
(struct hw_fib *)(((uintptr_t)(dev->regs.sa)) +
index), sizeof(struct hw_fib));
}
INIT_LIST_HEAD(&fib->fiblink);
fib->type = FSAFS_NTC_FIB_CONTEXT;
fib->size = sizeof(struct fib);
fib->hw_fib_va = hw_fib;
fib->data = hw_fib->data;
fib->dev = dev;
spin_lock_irqsave(q->lock, flags);
list_add_tail(&fib->fiblink, &q->cmdq);
wake_up_interruptible(&q->cmdready);
spin_unlock_irqrestore(q->lock, flags);
return 1;
} else if (isAif == 2) {
struct fib *fibctx;
struct aac_aifcmd *cmd;
fibctx = aac_fib_alloc(dev);
if (!fibctx)
return 1;
aac_fib_init(fibctx);
cmd = (struct aac_aifcmd *) fib_data(fibctx);
cmd->command = cpu_to_le32(AifReqEvent);
return aac_fib_send(AifRequest,
fibctx,
sizeof(struct hw_fib)-sizeof(struct aac_fibhdr),
FsaNormal,
0, 1,
(fib_callback)aac_aif_callback, fibctx);
} else {
struct fib *fib = &dev->fibs[index];
struct hw_fib * hwfib = fib->hw_fib_va;
dev->queues->queue[AdapNormCmdQueue].numpending--;
if (unlikely(fib->flags & FIB_CONTEXT_FLAG_TIMED_OUT)) {
aac_fib_complete(fib);
aac_fib_free(fib);
return 0;
}
if (isFastResponse) {
*(__le32 *)hwfib->data = cpu_to_le32(ST_OK);
hwfib->header.XferState |= cpu_to_le32(AdapterProcessed);
fib->flags |= FIB_CONTEXT_FLAG_FASTRESP;
}
FIB_COUNTER_INCREMENT(aac_config.FibRecved);
if (hwfib->header.Command == cpu_to_le16(NuFileSystem))
{
__le32 *pstatus = (__le32 *)hwfib->data;
if (*pstatus & cpu_to_le32(0xffff0000))
*pstatus = cpu_to_le32(ST_OK);
}
if (hwfib->header.XferState & cpu_to_le32(NoResponseExpected | Async))
{
if (hwfib->header.XferState & cpu_to_le32(NoResponseExpected))
FIB_COUNTER_INCREMENT(aac_config.NoResponseRecved);
else
FIB_COUNTER_INCREMENT(aac_config.AsyncRecved);
fib->flags &= FIB_CONTEXT_FLAG_FASTRESP;
fib->callback(fib->callback_data, fib);
} else {
unsigned long flagv;
dprintk((KERN_INFO "event_wait up\n"));
spin_lock_irqsave(&fib->event_lock, flagv);
if (!fib->done) {
fib->done = 1;
up(&fib->event_wait);
}
spin_unlock_irqrestore(&fib->event_lock, flagv);
spin_lock_irqsave(&dev->manage_lock, mflags);
dev->management_fib_count--;
spin_unlock_irqrestore(&dev->manage_lock, mflags);
FIB_COUNTER_INCREMENT(aac_config.NormalRecved);
if (fib->done == 2) {
spin_lock_irqsave(&fib->event_lock, flagv);
fib->done = 0;
spin_unlock_irqrestore(&fib->event_lock, flagv);
aac_fib_complete(fib);
aac_fib_free(fib);
}
}
return 0;
}
}
