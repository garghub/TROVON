static void push_buffer_init(struct push_buffer *pb)
{
*(u32 *)(pb->mapped + pb->size_bytes) = host1x_opcode_restart(0);
}
static void cdma_timeout_cpu_incr(struct host1x_cdma *cdma, u32 getptr,
u32 syncpt_incrs, u32 syncval, u32 nr_slots)
{
struct host1x *host1x = cdma_to_host1x(cdma);
struct push_buffer *pb = &cdma->push_buffer;
unsigned int i;
for (i = 0; i < syncpt_incrs; i++)
host1x_syncpt_incr(cdma->timeout.syncpt);
host1x_syncpt_load(cdma->timeout.syncpt);
while (nr_slots--) {
u32 *p = (u32 *)(pb->mapped + getptr);
*(p++) = HOST1X_OPCODE_NOP;
*(p++) = HOST1X_OPCODE_NOP;
dev_dbg(host1x->dev, "%s: NOP at %pad+%#x\n", __func__,
&pb->phys, getptr);
getptr = (getptr + 8) & (pb->size_bytes - 1);
}
wmb();
}
static void cdma_start(struct host1x_cdma *cdma)
{
struct host1x_channel *ch = cdma_to_channel(cdma);
if (cdma->running)
return;
cdma->last_pos = cdma->push_buffer.pos;
host1x_ch_writel(ch, HOST1X_CHANNEL_DMACTRL_DMASTOP,
HOST1X_CHANNEL_DMACTRL);
host1x_ch_writel(ch, cdma->push_buffer.phys, HOST1X_CHANNEL_DMASTART);
host1x_ch_writel(ch, cdma->push_buffer.pos, HOST1X_CHANNEL_DMAPUT);
host1x_ch_writel(ch, cdma->push_buffer.phys +
cdma->push_buffer.size_bytes + 4,
HOST1X_CHANNEL_DMAEND);
host1x_ch_writel(ch, HOST1X_CHANNEL_DMACTRL_DMASTOP |
HOST1X_CHANNEL_DMACTRL_DMAGETRST |
HOST1X_CHANNEL_DMACTRL_DMAINITGET,
HOST1X_CHANNEL_DMACTRL);
host1x_ch_writel(ch, 0, HOST1X_CHANNEL_DMACTRL);
cdma->running = true;
}
static void cdma_timeout_restart(struct host1x_cdma *cdma, u32 getptr)
{
struct host1x *host1x = cdma_to_host1x(cdma);
struct host1x_channel *ch = cdma_to_channel(cdma);
if (cdma->running)
return;
cdma->last_pos = cdma->push_buffer.pos;
host1x_ch_writel(ch, HOST1X_CHANNEL_DMACTRL_DMASTOP,
HOST1X_CHANNEL_DMACTRL);
host1x_ch_writel(ch, cdma->push_buffer.phys, HOST1X_CHANNEL_DMASTART);
host1x_ch_writel(ch, cdma->push_buffer.phys +
cdma->push_buffer.size_bytes,
HOST1X_CHANNEL_DMAEND);
host1x_ch_writel(ch, getptr, HOST1X_CHANNEL_DMAPUT);
host1x_ch_writel(ch, HOST1X_CHANNEL_DMACTRL_DMASTOP |
HOST1X_CHANNEL_DMACTRL_DMAGETRST |
HOST1X_CHANNEL_DMACTRL_DMAINITGET,
HOST1X_CHANNEL_DMACTRL);
dev_dbg(host1x->dev,
"%s: DMA GET 0x%x, PUT HW 0x%x / shadow 0x%x\n", __func__,
host1x_ch_readl(ch, HOST1X_CHANNEL_DMAGET),
host1x_ch_readl(ch, HOST1X_CHANNEL_DMAPUT),
cdma->last_pos);
host1x_ch_writel(ch, HOST1X_CHANNEL_DMACTRL_DMASTOP,
HOST1X_CHANNEL_DMACTRL);
host1x_ch_writel(ch, cdma->push_buffer.pos, HOST1X_CHANNEL_DMAPUT);
host1x_ch_writel(ch, 0, HOST1X_CHANNEL_DMACTRL);
cdma->running = true;
}
static void cdma_flush(struct host1x_cdma *cdma)
{
struct host1x_channel *ch = cdma_to_channel(cdma);
if (cdma->push_buffer.pos != cdma->last_pos) {
host1x_ch_writel(ch, cdma->push_buffer.pos,
HOST1X_CHANNEL_DMAPUT);
cdma->last_pos = cdma->push_buffer.pos;
}
}
static void cdma_stop(struct host1x_cdma *cdma)
{
struct host1x_channel *ch = cdma_to_channel(cdma);
mutex_lock(&cdma->lock);
if (cdma->running) {
host1x_cdma_wait_locked(cdma, CDMA_EVENT_SYNC_QUEUE_EMPTY);
host1x_ch_writel(ch, HOST1X_CHANNEL_DMACTRL_DMASTOP,
HOST1X_CHANNEL_DMACTRL);
cdma->running = false;
}
mutex_unlock(&cdma->lock);
}
static void cdma_freeze(struct host1x_cdma *cdma)
{
struct host1x *host = cdma_to_host1x(cdma);
struct host1x_channel *ch = cdma_to_channel(cdma);
u32 cmdproc_stop;
if (cdma->torndown && !cdma->running) {
dev_warn(host->dev, "Already torn down\n");
return;
}
dev_dbg(host->dev, "freezing channel (id %d)\n", ch->id);
cmdproc_stop = host1x_sync_readl(host, HOST1X_SYNC_CMDPROC_STOP);
cmdproc_stop |= BIT(ch->id);
host1x_sync_writel(host, cmdproc_stop, HOST1X_SYNC_CMDPROC_STOP);
dev_dbg(host->dev, "%s: DMA GET 0x%x, PUT HW 0x%x / shadow 0x%x\n",
__func__, host1x_ch_readl(ch, HOST1X_CHANNEL_DMAGET),
host1x_ch_readl(ch, HOST1X_CHANNEL_DMAPUT),
cdma->last_pos);
host1x_ch_writel(ch, HOST1X_CHANNEL_DMACTRL_DMASTOP,
HOST1X_CHANNEL_DMACTRL);
host1x_sync_writel(host, BIT(ch->id), HOST1X_SYNC_CH_TEARDOWN);
cdma->running = false;
cdma->torndown = true;
}
static void cdma_resume(struct host1x_cdma *cdma, u32 getptr)
{
struct host1x *host1x = cdma_to_host1x(cdma);
struct host1x_channel *ch = cdma_to_channel(cdma);
u32 cmdproc_stop;
dev_dbg(host1x->dev,
"resuming channel (id %u, DMAGET restart = 0x%x)\n",
ch->id, getptr);
cmdproc_stop = host1x_sync_readl(host1x, HOST1X_SYNC_CMDPROC_STOP);
cmdproc_stop &= ~BIT(ch->id);
host1x_sync_writel(host1x, cmdproc_stop, HOST1X_SYNC_CMDPROC_STOP);
cdma->torndown = false;
cdma_timeout_restart(cdma, getptr);
}
static void cdma_timeout_handler(struct work_struct *work)
{
u32 prev_cmdproc, cmdproc_stop, syncpt_val;
struct host1x_cdma *cdma;
struct host1x *host1x;
struct host1x_channel *ch;
cdma = container_of(to_delayed_work(work), struct host1x_cdma,
timeout.wq);
host1x = cdma_to_host1x(cdma);
ch = cdma_to_channel(cdma);
host1x_debug_dump(cdma_to_host1x(cdma));
mutex_lock(&cdma->lock);
if (!cdma->timeout.client) {
dev_dbg(host1x->dev,
"cdma_timeout: expired, but has no clientid\n");
mutex_unlock(&cdma->lock);
return;
}
prev_cmdproc = host1x_sync_readl(host1x, HOST1X_SYNC_CMDPROC_STOP);
cmdproc_stop = prev_cmdproc | BIT(ch->id);
host1x_sync_writel(host1x, cmdproc_stop, HOST1X_SYNC_CMDPROC_STOP);
dev_dbg(host1x->dev, "cdma_timeout: cmdproc was 0x%x is 0x%x\n",
prev_cmdproc, cmdproc_stop);
syncpt_val = host1x_syncpt_load(cdma->timeout.syncpt);
if ((s32)(syncpt_val - cdma->timeout.syncpt_val) >= 0) {
dev_dbg(host1x->dev,
"cdma_timeout: expired, but buffer had completed\n");
cmdproc_stop = prev_cmdproc & ~(BIT(ch->id));
host1x_sync_writel(host1x, cmdproc_stop,
HOST1X_SYNC_CMDPROC_STOP);
mutex_unlock(&cdma->lock);
return;
}
dev_warn(host1x->dev, "%s: timeout: %u (%s), HW thresh %d, done %d\n",
__func__, cdma->timeout.syncpt->id, cdma->timeout.syncpt->name,
syncpt_val, cdma->timeout.syncpt_val);
host1x_hw_cdma_freeze(host1x, cdma);
host1x_cdma_update_sync_queue(cdma, ch->dev);
mutex_unlock(&cdma->lock);
}
static int cdma_timeout_init(struct host1x_cdma *cdma, unsigned int syncpt)
{
INIT_DELAYED_WORK(&cdma->timeout.wq, cdma_timeout_handler);
cdma->timeout.initialized = true;
return 0;
}
static void cdma_timeout_destroy(struct host1x_cdma *cdma)
{
if (cdma->timeout.initialized)
cancel_delayed_work(&cdma->timeout.wq);
cdma->timeout.initialized = false;
}
