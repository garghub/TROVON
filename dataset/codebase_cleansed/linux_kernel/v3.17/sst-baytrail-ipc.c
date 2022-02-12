static inline u64 sst_byt_header(int msg_id, int data, bool large, int str_id)
{
u64 header;
header = IPC_HEADER_MSG_ID(msg_id) |
IPC_HEADER_STR_ID(str_id) |
IPC_HEADER_LARGE(large) |
IPC_HEADER_DATA(data) |
SST_BYT_IPCX_BUSY;
return header;
}
static inline u16 sst_byt_header_msg_id(u64 header)
{
return header & IPC_HEADER_MSG_ID_MASK;
}
static inline u8 sst_byt_header_str_id(u64 header)
{
return (header >> IPC_HEADER_STR_ID_SHIFT) & IPC_HEADER_STR_ID_MASK;
}
static inline u16 sst_byt_header_data(u64 header)
{
return (header >> IPC_HEADER_DATA_SHIFT) & IPC_HEADER_DATA_MASK;
}
static struct sst_byt_stream *sst_byt_get_stream(struct sst_byt *byt,
int stream_id)
{
struct sst_byt_stream *stream;
list_for_each_entry(stream, &byt->stream_list, node) {
if (stream->str_id == stream_id)
return stream;
}
return NULL;
}
static void sst_byt_ipc_shim_dbg(struct sst_byt *byt, const char *text)
{
struct sst_dsp *sst = byt->dsp;
u64 isr, ipcd, imrx, ipcx;
ipcx = sst_dsp_shim_read64_unlocked(sst, SST_IPCX);
isr = sst_dsp_shim_read64_unlocked(sst, SST_ISRX);
ipcd = sst_dsp_shim_read64_unlocked(sst, SST_IPCD);
imrx = sst_dsp_shim_read64_unlocked(sst, SST_IMRX);
dev_err(byt->dev,
"ipc: --%s-- ipcx 0x%llx isr 0x%llx ipcd 0x%llx imrx 0x%llx\n",
text, ipcx, isr, ipcd, imrx);
}
static struct ipc_message *sst_byt_msg_get_empty(struct sst_byt *byt)
{
struct ipc_message *msg = NULL;
if (!list_empty(&byt->empty_list)) {
msg = list_first_entry(&byt->empty_list,
struct ipc_message, list);
list_del(&msg->list);
}
return msg;
}
static void sst_byt_ipc_tx_msgs(struct kthread_work *work)
{
struct sst_byt *byt =
container_of(work, struct sst_byt, kwork);
struct ipc_message *msg;
u64 ipcx;
unsigned long flags;
spin_lock_irqsave(&byt->dsp->spinlock, flags);
if (list_empty(&byt->tx_list)) {
spin_unlock_irqrestore(&byt->dsp->spinlock, flags);
return;
}
ipcx = sst_dsp_shim_read64_unlocked(byt->dsp, SST_IPCX);
if (ipcx & SST_BYT_IPCX_BUSY) {
spin_unlock_irqrestore(&byt->dsp->spinlock, flags);
return;
}
msg = list_first_entry(&byt->tx_list, struct ipc_message, list);
list_move(&msg->list, &byt->rx_list);
if (msg->header & IPC_HEADER_LARGE(true))
sst_dsp_outbox_write(byt->dsp, msg->tx_data, msg->tx_size);
sst_dsp_shim_write64_unlocked(byt->dsp, SST_IPCX, msg->header);
spin_unlock_irqrestore(&byt->dsp->spinlock, flags);
}
static inline void sst_byt_tx_msg_reply_complete(struct sst_byt *byt,
struct ipc_message *msg)
{
msg->complete = true;
if (!msg->wait)
list_add_tail(&msg->list, &byt->empty_list);
else
wake_up(&msg->waitq);
}
static void sst_byt_drop_all(struct sst_byt *byt)
{
struct ipc_message *msg, *tmp;
unsigned long flags;
spin_lock_irqsave(&byt->dsp->spinlock, flags);
list_for_each_entry_safe(msg, tmp, &byt->tx_list, list) {
list_move(&msg->list, &byt->empty_list);
}
list_for_each_entry_safe(msg, tmp, &byt->rx_list, list) {
list_move(&msg->list, &byt->empty_list);
}
spin_unlock_irqrestore(&byt->dsp->spinlock, flags);
}
static int sst_byt_tx_wait_done(struct sst_byt *byt, struct ipc_message *msg,
void *rx_data)
{
unsigned long flags;
int ret;
ret = wait_event_timeout(msg->waitq, msg->complete,
msecs_to_jiffies(IPC_TIMEOUT_MSECS));
spin_lock_irqsave(&byt->dsp->spinlock, flags);
if (ret == 0) {
list_del(&msg->list);
sst_byt_ipc_shim_dbg(byt, "message timeout");
ret = -ETIMEDOUT;
} else {
if (msg->rx_size)
memcpy(rx_data, msg->rx_data, msg->rx_size);
ret = msg->errno;
}
list_add_tail(&msg->list, &byt->empty_list);
spin_unlock_irqrestore(&byt->dsp->spinlock, flags);
return ret;
}
static int sst_byt_ipc_tx_message(struct sst_byt *byt, u64 header,
void *tx_data, size_t tx_bytes,
void *rx_data, size_t rx_bytes, int wait)
{
unsigned long flags;
struct ipc_message *msg;
spin_lock_irqsave(&byt->dsp->spinlock, flags);
msg = sst_byt_msg_get_empty(byt);
if (msg == NULL) {
spin_unlock_irqrestore(&byt->dsp->spinlock, flags);
return -EBUSY;
}
msg->header = header;
msg->tx_size = tx_bytes;
msg->rx_size = rx_bytes;
msg->wait = wait;
msg->errno = 0;
msg->complete = false;
if (tx_bytes) {
*(u32 *)msg->tx_data = (u32)(header & (u32)-1);
memcpy(msg->tx_data + sizeof(u32), tx_data, tx_bytes);
msg->tx_size += sizeof(u32);
}
list_add_tail(&msg->list, &byt->tx_list);
spin_unlock_irqrestore(&byt->dsp->spinlock, flags);
queue_kthread_work(&byt->kworker, &byt->kwork);
if (wait)
return sst_byt_tx_wait_done(byt, msg, rx_data);
else
return 0;
}
static inline int sst_byt_ipc_tx_msg_wait(struct sst_byt *byt, u64 header,
void *tx_data, size_t tx_bytes,
void *rx_data, size_t rx_bytes)
{
return sst_byt_ipc_tx_message(byt, header, tx_data, tx_bytes,
rx_data, rx_bytes, 1);
}
static inline int sst_byt_ipc_tx_msg_nowait(struct sst_byt *byt, u64 header,
void *tx_data, size_t tx_bytes)
{
return sst_byt_ipc_tx_message(byt, header, tx_data, tx_bytes,
NULL, 0, 0);
}
static struct ipc_message *sst_byt_reply_find_msg(struct sst_byt *byt,
u64 header)
{
struct ipc_message *msg = NULL, *_msg;
u64 mask;
mask = IPC_HEADER_MSG_ID_MASK |
IPC_HEADER_STR_ID_MASK << IPC_HEADER_STR_ID_SHIFT;
header &= mask;
if (list_empty(&byt->rx_list)) {
dev_err(byt->dev,
"ipc: rx list is empty but received 0x%llx\n", header);
goto out;
}
list_for_each_entry(_msg, &byt->rx_list, list) {
if ((_msg->header & mask) == header) {
msg = _msg;
break;
}
}
out:
return msg;
}
static void sst_byt_stream_update(struct sst_byt *byt, struct ipc_message *msg)
{
struct sst_byt_stream *stream;
u64 header = msg->header;
u8 stream_id = sst_byt_header_str_id(header);
u8 stream_msg = sst_byt_header_msg_id(header);
stream = sst_byt_get_stream(byt, stream_id);
if (stream == NULL)
return;
switch (stream_msg) {
case IPC_IA_DROP_STREAM:
case IPC_IA_PAUSE_STREAM:
case IPC_IA_FREE_STREAM:
stream->running = false;
break;
case IPC_IA_START_STREAM:
case IPC_IA_RESUME_STREAM:
stream->running = true;
break;
}
}
static int sst_byt_process_reply(struct sst_byt *byt, u64 header)
{
struct ipc_message *msg;
msg = sst_byt_reply_find_msg(byt, header);
if (msg == NULL)
return 1;
if (header & IPC_HEADER_LARGE(true)) {
msg->rx_size = sst_byt_header_data(header);
sst_dsp_inbox_read(byt->dsp, msg->rx_data, msg->rx_size);
}
sst_byt_stream_update(byt, msg);
list_del(&msg->list);
sst_byt_tx_msg_reply_complete(byt, msg);
return 1;
}
static void sst_byt_fw_ready(struct sst_byt *byt, u64 header)
{
dev_dbg(byt->dev, "ipc: DSP is ready 0x%llX\n", header);
byt->boot_complete = true;
wake_up(&byt->boot_wait);
}
static int sst_byt_process_notification(struct sst_byt *byt,
unsigned long *flags)
{
struct sst_dsp *sst = byt->dsp;
struct sst_byt_stream *stream;
u64 header;
u8 msg_id, stream_id;
int handled = 1;
header = sst_dsp_shim_read64_unlocked(sst, SST_IPCD);
msg_id = sst_byt_header_msg_id(header);
switch (msg_id) {
case IPC_SST_PERIOD_ELAPSED:
stream_id = sst_byt_header_str_id(header);
stream = sst_byt_get_stream(byt, stream_id);
if (stream && stream->running && stream->notify_position) {
spin_unlock_irqrestore(&sst->spinlock, *flags);
stream->notify_position(stream, stream->pdata);
spin_lock_irqsave(&sst->spinlock, *flags);
}
break;
case IPC_IA_FW_INIT_CMPLT:
sst_byt_fw_ready(byt, header);
break;
}
return handled;
}
static irqreturn_t sst_byt_irq_thread(int irq, void *context)
{
struct sst_dsp *sst = (struct sst_dsp *) context;
struct sst_byt *byt = sst_dsp_get_thread_context(sst);
u64 header;
unsigned long flags;
spin_lock_irqsave(&sst->spinlock, flags);
header = sst_dsp_shim_read64_unlocked(sst, SST_IPCD);
if (header & SST_BYT_IPCD_BUSY) {
if (header & IPC_NOTIFICATION) {
sst_byt_process_notification(byt, &flags);
} else {
sst_byt_process_reply(byt, header);
}
sst_dsp_shim_update_bits64_unlocked(sst, SST_IPCD,
SST_BYT_IPCD_DONE | SST_BYT_IPCD_BUSY |
IPC_HEADER_DATA(IPC_HEADER_DATA_MASK),
SST_BYT_IPCD_DONE);
sst_dsp_shim_update_bits64_unlocked(sst, SST_IMRX,
SST_BYT_IMRX_REQUEST, 0);
}
spin_unlock_irqrestore(&sst->spinlock, flags);
queue_kthread_work(&byt->kworker, &byt->kwork);
return IRQ_HANDLED;
}
struct sst_byt_stream *sst_byt_stream_new(struct sst_byt *byt, int id,
u32 (*notify_position)(struct sst_byt_stream *stream, void *data),
void *data)
{
struct sst_byt_stream *stream;
struct sst_dsp *sst = byt->dsp;
unsigned long flags;
stream = kzalloc(sizeof(*stream), GFP_KERNEL);
if (stream == NULL)
return NULL;
spin_lock_irqsave(&sst->spinlock, flags);
list_add(&stream->node, &byt->stream_list);
stream->notify_position = notify_position;
stream->pdata = data;
stream->byt = byt;
stream->str_id = id;
spin_unlock_irqrestore(&sst->spinlock, flags);
return stream;
}
int sst_byt_stream_set_bits(struct sst_byt *byt, struct sst_byt_stream *stream,
int bits)
{
stream->request.pcm_params.pcm_wd_sz = bits;
return 0;
}
int sst_byt_stream_set_channels(struct sst_byt *byt,
struct sst_byt_stream *stream, u8 channels)
{
stream->request.pcm_params.num_chan = channels;
return 0;
}
int sst_byt_stream_set_rate(struct sst_byt *byt, struct sst_byt_stream *stream,
unsigned int rate)
{
stream->request.pcm_params.sfreq = rate;
return 0;
}
int sst_byt_stream_type(struct sst_byt *byt, struct sst_byt_stream *stream,
int codec_type, int stream_type, int operation)
{
stream->request.str_type.codec_type = codec_type;
stream->request.str_type.str_type = stream_type;
stream->request.str_type.operation = operation;
stream->request.str_type.time_slots = 0xc;
return 0;
}
int sst_byt_stream_buffer(struct sst_byt *byt, struct sst_byt_stream *stream,
uint32_t buffer_addr, uint32_t buffer_size)
{
stream->request.frame_info.num_entries = 1;
stream->request.frame_info.ring_buf_info[0].addr = buffer_addr;
stream->request.frame_info.ring_buf_info[0].size = buffer_size;
stream->request.frame_info.frag_size =
stream->request.pcm_params.sfreq *
stream->request.pcm_params.num_chan *
stream->request.pcm_params.pcm_wd_sz / 8 *
4 / 1000;
return 0;
}
int sst_byt_stream_commit(struct sst_byt *byt, struct sst_byt_stream *stream)
{
struct sst_byt_alloc_params *str_req = &stream->request;
struct sst_byt_alloc_response *reply = &stream->reply;
u64 header;
int ret;
header = sst_byt_header(IPC_IA_ALLOC_STREAM,
sizeof(*str_req) + sizeof(u32),
true, stream->str_id);
ret = sst_byt_ipc_tx_msg_wait(byt, header, str_req, sizeof(*str_req),
reply, sizeof(*reply));
if (ret < 0) {
dev_err(byt->dev, "ipc: error stream commit failed\n");
return ret;
}
stream->commited = true;
return 0;
}
int sst_byt_stream_free(struct sst_byt *byt, struct sst_byt_stream *stream)
{
u64 header;
int ret = 0;
struct sst_dsp *sst = byt->dsp;
unsigned long flags;
if (!stream->commited)
goto out;
header = sst_byt_header(IPC_IA_FREE_STREAM, 0, false, stream->str_id);
ret = sst_byt_ipc_tx_msg_wait(byt, header, NULL, 0, NULL, 0);
if (ret < 0) {
dev_err(byt->dev, "ipc: free stream %d failed\n",
stream->str_id);
return -EAGAIN;
}
stream->commited = false;
out:
spin_lock_irqsave(&sst->spinlock, flags);
list_del(&stream->node);
kfree(stream);
spin_unlock_irqrestore(&sst->spinlock, flags);
return ret;
}
static int sst_byt_stream_operations(struct sst_byt *byt, int type,
int stream_id, int wait)
{
u64 header;
header = sst_byt_header(type, 0, false, stream_id);
if (wait)
return sst_byt_ipc_tx_msg_wait(byt, header, NULL, 0, NULL, 0);
else
return sst_byt_ipc_tx_msg_nowait(byt, header, NULL, 0);
}
int sst_byt_stream_start(struct sst_byt *byt, struct sst_byt_stream *stream,
u32 start_offset)
{
struct sst_byt_start_stream_params start_stream;
void *tx_msg;
size_t size;
u64 header;
int ret;
start_stream.byte_offset = start_offset;
header = sst_byt_header(IPC_IA_START_STREAM,
sizeof(start_stream) + sizeof(u32),
true, stream->str_id);
tx_msg = &start_stream;
size = sizeof(start_stream);
ret = sst_byt_ipc_tx_msg_nowait(byt, header, tx_msg, size);
if (ret < 0)
dev_err(byt->dev, "ipc: error failed to start stream %d\n",
stream->str_id);
return ret;
}
int sst_byt_stream_stop(struct sst_byt *byt, struct sst_byt_stream *stream)
{
int ret;
if (!stream->commited)
return 0;
ret = sst_byt_stream_operations(byt, IPC_IA_DROP_STREAM,
stream->str_id, 0);
if (ret < 0)
dev_err(byt->dev, "ipc: error failed to stop stream %d\n",
stream->str_id);
return ret;
}
int sst_byt_stream_pause(struct sst_byt *byt, struct sst_byt_stream *stream)
{
int ret;
ret = sst_byt_stream_operations(byt, IPC_IA_PAUSE_STREAM,
stream->str_id, 0);
if (ret < 0)
dev_err(byt->dev, "ipc: error failed to pause stream %d\n",
stream->str_id);
return ret;
}
int sst_byt_stream_resume(struct sst_byt *byt, struct sst_byt_stream *stream)
{
int ret;
ret = sst_byt_stream_operations(byt, IPC_IA_RESUME_STREAM,
stream->str_id, 0);
if (ret < 0)
dev_err(byt->dev, "ipc: error failed to resume stream %d\n",
stream->str_id);
return ret;
}
int sst_byt_get_dsp_position(struct sst_byt *byt,
struct sst_byt_stream *stream, int buffer_size)
{
struct sst_dsp *sst = byt->dsp;
struct sst_byt_tstamp fw_tstamp;
u8 str_id = stream->str_id;
u32 tstamp_offset;
tstamp_offset = SST_BYT_TIMESTAMP_OFFSET + str_id * sizeof(fw_tstamp);
memcpy_fromio(&fw_tstamp,
sst->addr.lpe + tstamp_offset, sizeof(fw_tstamp));
return do_div(fw_tstamp.ring_buffer_counter, buffer_size);
}
static int msg_empty_list_init(struct sst_byt *byt)
{
struct ipc_message *msg;
int i;
byt->msg = kzalloc(sizeof(*msg) * IPC_EMPTY_LIST_SIZE, GFP_KERNEL);
if (byt->msg == NULL)
return -ENOMEM;
for (i = 0; i < IPC_EMPTY_LIST_SIZE; i++) {
init_waitqueue_head(&byt->msg[i].waitq);
list_add(&byt->msg[i].list, &byt->empty_list);
}
return 0;
}
struct sst_dsp *sst_byt_get_dsp(struct sst_byt *byt)
{
return byt->dsp;
}
int sst_byt_dsp_suspend_late(struct device *dev, struct sst_pdata *pdata)
{
struct sst_byt *byt = pdata->dsp;
dev_dbg(byt->dev, "dsp reset\n");
sst_dsp_reset(byt->dsp);
sst_byt_drop_all(byt);
dev_dbg(byt->dev, "dsp in reset\n");
dev_dbg(byt->dev, "free all blocks and unload fw\n");
sst_fw_unload(byt->fw);
return 0;
}
int sst_byt_dsp_boot(struct device *dev, struct sst_pdata *pdata)
{
struct sst_byt *byt = pdata->dsp;
int ret;
dev_dbg(byt->dev, "reload dsp fw\n");
sst_dsp_reset(byt->dsp);
ret = sst_fw_reload(byt->fw);
if (ret < 0) {
dev_err(dev, "error: failed to reload firmware\n");
return ret;
}
byt->boot_complete = false;
sst_dsp_boot(byt->dsp);
dev_dbg(byt->dev, "dsp booting...\n");
return 0;
}
int sst_byt_dsp_wait_for_ready(struct device *dev, struct sst_pdata *pdata)
{
struct sst_byt *byt = pdata->dsp;
int err;
dev_dbg(byt->dev, "wait for dsp reboot\n");
err = wait_event_timeout(byt->boot_wait, byt->boot_complete,
msecs_to_jiffies(IPC_BOOT_MSECS));
if (err == 0) {
dev_err(byt->dev, "ipc: error DSP boot timeout\n");
return -EIO;
}
dev_dbg(byt->dev, "dsp rebooted\n");
return 0;
}
int sst_byt_dsp_init(struct device *dev, struct sst_pdata *pdata)
{
struct sst_byt *byt;
struct sst_fw *byt_sst_fw;
struct sst_byt_fw_init init;
int err;
dev_dbg(dev, "initialising Byt DSP IPC\n");
byt = devm_kzalloc(dev, sizeof(*byt), GFP_KERNEL);
if (byt == NULL)
return -ENOMEM;
byt->dev = dev;
INIT_LIST_HEAD(&byt->stream_list);
INIT_LIST_HEAD(&byt->tx_list);
INIT_LIST_HEAD(&byt->rx_list);
INIT_LIST_HEAD(&byt->empty_list);
init_waitqueue_head(&byt->boot_wait);
init_waitqueue_head(&byt->wait_txq);
err = msg_empty_list_init(byt);
if (err < 0)
return -ENOMEM;
init_kthread_worker(&byt->kworker);
byt->tx_thread = kthread_run(kthread_worker_fn,
&byt->kworker, "%s",
dev_name(byt->dev));
if (IS_ERR(byt->tx_thread)) {
err = PTR_ERR(byt->tx_thread);
dev_err(byt->dev, "error failed to create message TX task\n");
goto err_free_msg;
}
init_kthread_work(&byt->kwork, sst_byt_ipc_tx_msgs);
byt_dev.thread_context = byt;
byt->dsp = sst_dsp_new(dev, &byt_dev, pdata);
if (byt->dsp == NULL) {
err = -ENODEV;
goto dsp_err;
}
sst_dsp_reset(byt->dsp);
byt_sst_fw = sst_fw_new(byt->dsp, pdata->fw, byt);
if (byt_sst_fw == NULL) {
err = -ENODEV;
dev_err(dev, "error: failed to load firmware\n");
goto fw_err;
}
sst_dsp_boot(byt->dsp);
err = wait_event_timeout(byt->boot_wait, byt->boot_complete,
msecs_to_jiffies(IPC_BOOT_MSECS));
if (err == 0) {
err = -EIO;
dev_err(byt->dev, "ipc: error DSP boot timeout\n");
goto boot_err;
}
sst_dsp_inbox_read(byt->dsp, &init, sizeof(init));
dev_info(byt->dev, "FW version: %02x.%02x.%02x.%02x\n",
init.fw_version.major, init.fw_version.minor,
init.fw_version.build, init.fw_version.type);
dev_info(byt->dev, "Build type: %x\n", init.fw_version.type);
dev_info(byt->dev, "Build date: %s %s\n",
init.build_info.date, init.build_info.time);
pdata->dsp = byt;
byt->fw = byt_sst_fw;
return 0;
boot_err:
sst_dsp_reset(byt->dsp);
sst_fw_free(byt_sst_fw);
fw_err:
sst_dsp_free(byt->dsp);
dsp_err:
kthread_stop(byt->tx_thread);
err_free_msg:
kfree(byt->msg);
return err;
}
void sst_byt_dsp_free(struct device *dev, struct sst_pdata *pdata)
{
struct sst_byt *byt = pdata->dsp;
sst_dsp_reset(byt->dsp);
sst_fw_free_all(byt->dsp);
sst_dsp_free(byt->dsp);
kthread_stop(byt->tx_thread);
kfree(byt->msg);
}
