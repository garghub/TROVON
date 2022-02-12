static inline u32 msg_get_global_type(u32 msg)
{
return (msg & IPC_GLB_TYPE_MASK) >> IPC_GLB_TYPE_SHIFT;
}
static inline u32 msg_get_global_reply(u32 msg)
{
return (msg & IPC_GLB_REPLY_MASK) >> IPC_GLB_REPLY_SHIFT;
}
static inline u32 msg_get_stream_type(u32 msg)
{
return (msg & IPC_STR_TYPE_MASK) >> IPC_STR_TYPE_SHIFT;
}
static inline u32 msg_get_stage_type(u32 msg)
{
return (msg & IPC_STG_TYPE_MASK) >> IPC_STG_TYPE_SHIFT;
}
static inline u32 msg_set_stage_type(u32 msg, u32 type)
{
return (msg & ~IPC_STG_TYPE_MASK) +
(type << IPC_STG_TYPE_SHIFT);
}
static inline u32 msg_get_stream_id(u32 msg)
{
return (msg & IPC_STR_ID_MASK) >> IPC_STR_ID_SHIFT;
}
static inline u32 msg_get_notify_reason(u32 msg)
{
return (msg & IPC_STG_TYPE_MASK) >> IPC_STG_TYPE_SHIFT;
}
u32 create_channel_map(enum sst_hsw_channel_config config)
{
switch (config) {
case SST_HSW_CHANNEL_CONFIG_MONO:
return (0xFFFFFFF0 | SST_HSW_CHANNEL_CENTER);
case SST_HSW_CHANNEL_CONFIG_STEREO:
return (0xFFFFFF00 | SST_HSW_CHANNEL_LEFT
| (SST_HSW_CHANNEL_RIGHT << 4));
case SST_HSW_CHANNEL_CONFIG_2_POINT_1:
return (0xFFFFF000 | SST_HSW_CHANNEL_LEFT
| (SST_HSW_CHANNEL_RIGHT << 4)
| (SST_HSW_CHANNEL_LFE << 8 ));
case SST_HSW_CHANNEL_CONFIG_3_POINT_0:
return (0xFFFFF000 | SST_HSW_CHANNEL_LEFT
| (SST_HSW_CHANNEL_CENTER << 4)
| (SST_HSW_CHANNEL_RIGHT << 8));
case SST_HSW_CHANNEL_CONFIG_3_POINT_1:
return (0xFFFF0000 | SST_HSW_CHANNEL_LEFT
| (SST_HSW_CHANNEL_CENTER << 4)
| (SST_HSW_CHANNEL_RIGHT << 8)
| (SST_HSW_CHANNEL_LFE << 12));
case SST_HSW_CHANNEL_CONFIG_QUATRO:
return (0xFFFF0000 | SST_HSW_CHANNEL_LEFT
| (SST_HSW_CHANNEL_RIGHT << 4)
| (SST_HSW_CHANNEL_LEFT_SURROUND << 8)
| (SST_HSW_CHANNEL_RIGHT_SURROUND << 12));
case SST_HSW_CHANNEL_CONFIG_4_POINT_0:
return (0xFFFF0000 | SST_HSW_CHANNEL_LEFT
| (SST_HSW_CHANNEL_CENTER << 4)
| (SST_HSW_CHANNEL_RIGHT << 8)
| (SST_HSW_CHANNEL_CENTER_SURROUND << 12));
case SST_HSW_CHANNEL_CONFIG_5_POINT_0:
return (0xFFF00000 | SST_HSW_CHANNEL_LEFT
| (SST_HSW_CHANNEL_CENTER << 4)
| (SST_HSW_CHANNEL_RIGHT << 8)
| (SST_HSW_CHANNEL_LEFT_SURROUND << 12)
| (SST_HSW_CHANNEL_RIGHT_SURROUND << 16));
case SST_HSW_CHANNEL_CONFIG_5_POINT_1:
return (0xFF000000 | SST_HSW_CHANNEL_CENTER
| (SST_HSW_CHANNEL_LEFT << 4)
| (SST_HSW_CHANNEL_RIGHT << 8)
| (SST_HSW_CHANNEL_LEFT_SURROUND << 12)
| (SST_HSW_CHANNEL_RIGHT_SURROUND << 16)
| (SST_HSW_CHANNEL_LFE << 20));
case SST_HSW_CHANNEL_CONFIG_DUAL_MONO:
return (0xFFFFFF00 | SST_HSW_CHANNEL_LEFT
| (SST_HSW_CHANNEL_LEFT << 4));
default:
return 0xFFFFFFFF;
}
}
static struct sst_hsw_stream *get_stream_by_id(struct sst_hsw *hsw,
int stream_id)
{
struct sst_hsw_stream *stream;
list_for_each_entry(stream, &hsw->stream_list, node) {
if (stream->reply.stream_hw_id == stream_id)
return stream;
}
return NULL;
}
static void ipc_shim_dbg(struct sst_hsw *hsw, const char *text)
{
struct sst_dsp *sst = hsw->dsp;
u32 isr, ipcd, imrx, ipcx;
ipcx = sst_dsp_shim_read_unlocked(sst, SST_IPCX);
isr = sst_dsp_shim_read_unlocked(sst, SST_ISRX);
ipcd = sst_dsp_shim_read_unlocked(sst, SST_IPCD);
imrx = sst_dsp_shim_read_unlocked(sst, SST_IMRX);
dev_err(hsw->dev, "ipc: --%s-- ipcx 0x%8.8x isr 0x%8.8x ipcd 0x%8.8x imrx 0x%8.8x\n",
text, ipcx, isr, ipcd, imrx);
}
static struct ipc_message *msg_get_empty(struct sst_hsw *hsw)
{
struct ipc_message *msg = NULL;
if (!list_empty(&hsw->empty_list)) {
msg = list_first_entry(&hsw->empty_list, struct ipc_message,
list);
list_del(&msg->list);
}
return msg;
}
static void ipc_tx_msgs(struct kthread_work *work)
{
struct sst_hsw *hsw =
container_of(work, struct sst_hsw, kwork);
struct ipc_message *msg;
unsigned long flags;
u32 ipcx;
spin_lock_irqsave(&hsw->dsp->spinlock, flags);
if (list_empty(&hsw->tx_list) || hsw->pending) {
spin_unlock_irqrestore(&hsw->dsp->spinlock, flags);
return;
}
ipcx = sst_dsp_shim_read_unlocked(hsw->dsp, SST_IPCX);
if (ipcx & (SST_IPCX_BUSY | SST_IPCX_DONE)) {
spin_unlock_irqrestore(&hsw->dsp->spinlock, flags);
return;
}
msg = list_first_entry(&hsw->tx_list, struct ipc_message, list);
list_move(&msg->list, &hsw->rx_list);
sst_dsp_outbox_write(hsw->dsp, msg->tx_data, msg->tx_size);
sst_dsp_ipc_msg_tx(hsw->dsp, msg->header | SST_IPCX_BUSY);
spin_unlock_irqrestore(&hsw->dsp->spinlock, flags);
}
static void tx_msg_reply_complete(struct sst_hsw *hsw, struct ipc_message *msg)
{
msg->complete = true;
trace_ipc_reply("completed", msg->header);
if (!msg->wait)
list_add_tail(&msg->list, &hsw->empty_list);
else
wake_up(&msg->waitq);
}
static int tx_wait_done(struct sst_hsw *hsw, struct ipc_message *msg,
void *rx_data)
{
unsigned long flags;
int ret;
ret = wait_event_timeout(msg->waitq, msg->complete,
msecs_to_jiffies(IPC_TIMEOUT_MSECS));
spin_lock_irqsave(&hsw->dsp->spinlock, flags);
if (ret == 0) {
ipc_shim_dbg(hsw, "message timeout");
trace_ipc_error("error message timeout for", msg->header);
list_del(&msg->list);
ret = -ETIMEDOUT;
} else {
if (msg->rx_size)
memcpy(rx_data, msg->rx_data, msg->rx_size);
ret = msg->errno;
}
list_add_tail(&msg->list, &hsw->empty_list);
spin_unlock_irqrestore(&hsw->dsp->spinlock, flags);
return ret;
}
static int ipc_tx_message(struct sst_hsw *hsw, u32 header, void *tx_data,
size_t tx_bytes, void *rx_data, size_t rx_bytes, int wait)
{
struct ipc_message *msg;
unsigned long flags;
spin_lock_irqsave(&hsw->dsp->spinlock, flags);
msg = msg_get_empty(hsw);
if (msg == NULL) {
spin_unlock_irqrestore(&hsw->dsp->spinlock, flags);
return -EBUSY;
}
if (tx_bytes)
memcpy(msg->tx_data, tx_data, tx_bytes);
msg->header = header;
msg->tx_size = tx_bytes;
msg->rx_size = rx_bytes;
msg->wait = wait;
msg->errno = 0;
msg->pending = false;
msg->complete = false;
list_add_tail(&msg->list, &hsw->tx_list);
spin_unlock_irqrestore(&hsw->dsp->spinlock, flags);
queue_kthread_work(&hsw->kworker, &hsw->kwork);
if (wait)
return tx_wait_done(hsw, msg, rx_data);
else
return 0;
}
static inline int ipc_tx_message_wait(struct sst_hsw *hsw, u32 header,
void *tx_data, size_t tx_bytes, void *rx_data, size_t rx_bytes)
{
return ipc_tx_message(hsw, header, tx_data, tx_bytes, rx_data,
rx_bytes, 1);
}
static inline int ipc_tx_message_nowait(struct sst_hsw *hsw, u32 header,
void *tx_data, size_t tx_bytes)
{
return ipc_tx_message(hsw, header, tx_data, tx_bytes, NULL, 0, 0);
}
static void hsw_fw_ready(struct sst_hsw *hsw, u32 header)
{
struct sst_hsw_ipc_fw_ready fw_ready;
u32 offset;
u8 fw_info[IPC_MAX_MAILBOX_BYTES - 5 * sizeof(u32)];
char *tmp[5], *pinfo;
int i = 0;
offset = (header & 0x1FFFFFFF) << 3;
dev_dbg(hsw->dev, "ipc: DSP is ready 0x%8.8x offset %d\n",
header, offset);
sst_dsp_read(hsw->dsp, &fw_ready, offset, sizeof(fw_ready));
sst_dsp_mailbox_init(hsw->dsp, fw_ready.inbox_offset,
fw_ready.inbox_size, fw_ready.outbox_offset,
fw_ready.outbox_size);
hsw->boot_complete = true;
wake_up(&hsw->boot_wait);
dev_dbg(hsw->dev, " mailbox upstream 0x%x - size 0x%x\n",
fw_ready.inbox_offset, fw_ready.inbox_size);
dev_dbg(hsw->dev, " mailbox downstream 0x%x - size 0x%x\n",
fw_ready.outbox_offset, fw_ready.outbox_size);
if (fw_ready.fw_info_size < sizeof(fw_ready.fw_info)) {
fw_ready.fw_info[fw_ready.fw_info_size] = 0;
dev_dbg(hsw->dev, " Firmware info: %s \n", fw_ready.fw_info);
memcpy(fw_info, fw_ready.fw_info, fw_ready.fw_info_size);
pinfo = &fw_info[0];
for (i = 0; i < sizeof(tmp) / sizeof(char *); i++)
tmp[i] = strsep(&pinfo, " ");
dev_info(hsw->dev, "FW loaded, mailbox readback FW info: type %s, - "
"version: %s.%s, build %s, source commit id: %s\n",
tmp[0], tmp[1], tmp[2], tmp[3], tmp[4]);
}
}
static void hsw_notification_work(struct work_struct *work)
{
struct sst_hsw_stream *stream = container_of(work,
struct sst_hsw_stream, notify_work);
struct sst_hsw_ipc_stream_glitch_position *glitch = &stream->glitch;
struct sst_hsw_ipc_stream_get_position *pos = &stream->rpos;
struct sst_hsw *hsw = stream->hsw;
u32 reason;
reason = msg_get_notify_reason(stream->header);
switch (reason) {
case IPC_STG_GLITCH:
trace_ipc_notification("DSP stream under/overrun",
stream->reply.stream_hw_id);
sst_dsp_inbox_read(hsw->dsp, glitch, sizeof(*glitch));
dev_err(hsw->dev, "glitch %d pos 0x%x write pos 0x%x\n",
glitch->glitch_type, glitch->present_pos,
glitch->write_pos);
break;
case IPC_POSITION_CHANGED:
trace_ipc_notification("DSP stream position changed for",
stream->reply.stream_hw_id);
sst_dsp_inbox_read(hsw->dsp, pos, sizeof(*pos));
if (stream->notify_position)
stream->notify_position(stream, stream->pdata);
break;
default:
dev_err(hsw->dev, "error: unknown notification 0x%x\n",
stream->header);
break;
}
sst_dsp_shim_update_bits(hsw->dsp, SST_IPCD,
SST_IPCD_BUSY | SST_IPCD_DONE, SST_IPCD_DONE);
sst_dsp_shim_update_bits(hsw->dsp, SST_IMRX, SST_IMRX_BUSY, 0);
}
static struct ipc_message *reply_find_msg(struct sst_hsw *hsw, u32 header)
{
struct ipc_message *msg;
header &= ~(IPC_STATUS_MASK | IPC_GLB_REPLY_MASK);
if (list_empty(&hsw->rx_list)) {
dev_err(hsw->dev, "error: rx list empty but received 0x%x\n",
header);
return NULL;
}
list_for_each_entry(msg, &hsw->rx_list, list) {
if (msg->header == header)
return msg;
}
return NULL;
}
static void hsw_stream_update(struct sst_hsw *hsw, struct ipc_message *msg)
{
struct sst_hsw_stream *stream;
u32 header = msg->header & ~(IPC_STATUS_MASK | IPC_GLB_REPLY_MASK);
u32 stream_id = msg_get_stream_id(header);
u32 stream_msg = msg_get_stream_type(header);
stream = get_stream_by_id(hsw, stream_id);
if (stream == NULL)
return;
switch (stream_msg) {
case IPC_STR_STAGE_MESSAGE:
case IPC_STR_NOTIFICATION:
break;
case IPC_STR_RESET:
trace_ipc_notification("stream reset", stream->reply.stream_hw_id);
break;
case IPC_STR_PAUSE:
stream->running = false;
trace_ipc_notification("stream paused",
stream->reply.stream_hw_id);
break;
case IPC_STR_RESUME:
stream->running = true;
trace_ipc_notification("stream running",
stream->reply.stream_hw_id);
break;
}
}
static int hsw_process_reply(struct sst_hsw *hsw, u32 header)
{
struct ipc_message *msg;
u32 reply = msg_get_global_reply(header);
trace_ipc_reply("processing -->", header);
msg = reply_find_msg(hsw, header);
if (msg == NULL) {
trace_ipc_error("error: can't find message header", header);
return -EIO;
}
switch (reply) {
case IPC_GLB_REPLY_PENDING:
trace_ipc_pending_reply("received", header);
msg->pending = true;
hsw->pending = true;
return 1;
case IPC_GLB_REPLY_SUCCESS:
if (msg->pending) {
trace_ipc_pending_reply("completed", header);
sst_dsp_inbox_read(hsw->dsp, msg->rx_data,
msg->rx_size);
hsw->pending = false;
} else {
sst_dsp_outbox_read(hsw->dsp, msg->rx_data,
msg->rx_size);
}
break;
case IPC_GLB_REPLY_UNKNOWN_MESSAGE_TYPE:
trace_ipc_error("error: unknown message type", header);
msg->errno = -EBADMSG;
break;
case IPC_GLB_REPLY_OUT_OF_RESOURCES:
trace_ipc_error("error: out of resources", header);
msg->errno = -ENOMEM;
break;
case IPC_GLB_REPLY_BUSY:
trace_ipc_error("error: reply busy", header);
msg->errno = -EBUSY;
break;
case IPC_GLB_REPLY_FAILURE:
trace_ipc_error("error: reply failure", header);
msg->errno = -EINVAL;
break;
case IPC_GLB_REPLY_STAGE_UNINITIALIZED:
trace_ipc_error("error: stage uninitialized", header);
msg->errno = -EINVAL;
break;
case IPC_GLB_REPLY_NOT_FOUND:
trace_ipc_error("error: reply not found", header);
msg->errno = -EINVAL;
break;
case IPC_GLB_REPLY_SOURCE_NOT_STARTED:
trace_ipc_error("error: source not started", header);
msg->errno = -EINVAL;
break;
case IPC_GLB_REPLY_INVALID_REQUEST:
trace_ipc_error("error: invalid request", header);
msg->errno = -EINVAL;
break;
case IPC_GLB_REPLY_ERROR_INVALID_PARAM:
trace_ipc_error("error: invalid parameter", header);
msg->errno = -EINVAL;
break;
default:
trace_ipc_error("error: unknown reply", header);
msg->errno = -EINVAL;
break;
}
if (msg_get_global_type(header) == IPC_GLB_STREAM_MESSAGE)
hsw_stream_update(hsw, msg);
list_del(&msg->list);
tx_msg_reply_complete(hsw, msg);
return 1;
}
static int hsw_stream_message(struct sst_hsw *hsw, u32 header)
{
u32 stream_msg, stream_id, stage_type;
struct sst_hsw_stream *stream;
int handled = 0;
stream_msg = msg_get_stream_type(header);
stream_id = msg_get_stream_id(header);
stage_type = msg_get_stage_type(header);
stream = get_stream_by_id(hsw, stream_id);
if (stream == NULL)
return handled;
stream->header = header;
switch (stream_msg) {
case IPC_STR_STAGE_MESSAGE:
dev_err(hsw->dev, "error: stage msg not implemented 0x%8.8x\n",
header);
break;
case IPC_STR_NOTIFICATION:
schedule_work(&stream->notify_work);
break;
default:
handled = hsw_process_reply(hsw, header);
break;
}
return handled;
}
static int hsw_log_message(struct sst_hsw *hsw, u32 header)
{
u32 operation = (header & IPC_LOG_OP_MASK) >> IPC_LOG_OP_SHIFT;
struct sst_hsw_log_stream *stream = &hsw->log_stream;
int ret = 1;
if (operation != IPC_DEBUG_REQUEST_LOG_DUMP) {
dev_err(hsw->dev,
"error: log msg not implemented 0x%8.8x\n", header);
return 0;
}
mutex_lock(&stream->rw_mutex);
stream->last_pos = stream->curr_pos;
sst_dsp_inbox_read(
hsw->dsp, &stream->curr_pos, sizeof(stream->curr_pos));
mutex_unlock(&stream->rw_mutex);
schedule_work(&stream->notify_work);
return ret;
}
static int hsw_process_notification(struct sst_hsw *hsw)
{
struct sst_dsp *sst = hsw->dsp;
u32 type, header;
int handled = 1;
header = sst_dsp_shim_read_unlocked(sst, SST_IPCD);
type = msg_get_global_type(header);
trace_ipc_request("processing -->", header);
if (!hsw->boot_complete && header & IPC_FW_READY) {
hsw_fw_ready(hsw, header);
return handled;
}
switch (type) {
case IPC_GLB_GET_FW_VERSION:
case IPC_GLB_ALLOCATE_STREAM:
case IPC_GLB_FREE_STREAM:
case IPC_GLB_GET_FW_CAPABILITIES:
case IPC_GLB_REQUEST_DUMP:
case IPC_GLB_GET_DEVICE_FORMATS:
case IPC_GLB_SET_DEVICE_FORMATS:
case IPC_GLB_ENTER_DX_STATE:
case IPC_GLB_GET_MIXER_STREAM_INFO:
case IPC_GLB_MAX_IPC_MESSAGE_TYPE:
case IPC_GLB_RESTORE_CONTEXT:
case IPC_GLB_SHORT_REPLY:
dev_err(hsw->dev, "error: message type %d header 0x%x\n",
type, header);
break;
case IPC_GLB_STREAM_MESSAGE:
handled = hsw_stream_message(hsw, header);
break;
case IPC_GLB_DEBUG_LOG_MESSAGE:
handled = hsw_log_message(hsw, header);
break;
default:
dev_err(hsw->dev, "error: unexpected type %d hdr 0x%8.8x\n",
type, header);
break;
}
return handled;
}
static irqreturn_t hsw_irq_thread(int irq, void *context)
{
struct sst_dsp *sst = (struct sst_dsp *) context;
struct sst_hsw *hsw = sst_dsp_get_thread_context(sst);
u32 ipcx, ipcd;
int handled;
unsigned long flags;
spin_lock_irqsave(&sst->spinlock, flags);
ipcx = sst_dsp_ipc_msg_rx(hsw->dsp);
ipcd = sst_dsp_shim_read_unlocked(sst, SST_IPCD);
if (ipcx & SST_IPCX_DONE) {
handled = hsw_process_reply(hsw, ipcx);
if (handled > 0) {
sst_dsp_shim_update_bits_unlocked(sst, SST_IPCX,
SST_IPCX_DONE, 0);
sst_dsp_shim_update_bits_unlocked(sst, SST_IMRX,
SST_IMRX_DONE, 0);
}
}
if (ipcd & SST_IPCD_BUSY) {
handled = hsw_process_notification(hsw);
if (handled > 0) {
sst_dsp_shim_update_bits_unlocked(sst, SST_IPCD,
SST_IPCD_BUSY | SST_IPCD_DONE, SST_IPCD_DONE);
sst_dsp_shim_update_bits_unlocked(sst, SST_IMRX,
SST_IMRX_BUSY, 0);
}
}
spin_unlock_irqrestore(&sst->spinlock, flags);
queue_kthread_work(&hsw->kworker, &hsw->kwork);
return IRQ_HANDLED;
}
int sst_hsw_fw_get_version(struct sst_hsw *hsw,
struct sst_hsw_ipc_fw_version *version)
{
int ret;
ret = ipc_tx_message_wait(hsw, IPC_GLB_TYPE(IPC_GLB_GET_FW_VERSION),
NULL, 0, version, sizeof(*version));
if (ret < 0)
dev_err(hsw->dev, "error: get version failed\n");
return ret;
}
int sst_hsw_stream_mute(struct sst_hsw *hsw, struct sst_hsw_stream *stream,
u32 stage_id, u32 channel)
{
int ret;
ret = sst_hsw_stream_get_volume(hsw, stream, stage_id, channel,
&stream->mute_volume[channel]);
if (ret < 0)
return ret;
ret = sst_hsw_stream_set_volume(hsw, stream, stage_id, channel, 0);
if (ret < 0) {
dev_err(hsw->dev, "error: can't unmute stream %d channel %d\n",
stream->reply.stream_hw_id, channel);
return ret;
}
stream->mute[channel] = 1;
return 0;
}
int sst_hsw_stream_unmute(struct sst_hsw *hsw, struct sst_hsw_stream *stream,
u32 stage_id, u32 channel)
{
int ret;
stream->mute[channel] = 0;
ret = sst_hsw_stream_set_volume(hsw, stream, stage_id, channel,
stream->mute_volume[channel]);
if (ret < 0) {
dev_err(hsw->dev, "error: can't unmute stream %d channel %d\n",
stream->reply.stream_hw_id, channel);
return ret;
}
return 0;
}
int sst_hsw_stream_get_volume(struct sst_hsw *hsw, struct sst_hsw_stream *stream,
u32 stage_id, u32 channel, u32 *volume)
{
if (channel > 1)
return -EINVAL;
sst_dsp_read(hsw->dsp, volume,
stream->reply.volume_register_address[channel],
sizeof(*volume));
return 0;
}
int sst_hsw_stream_set_volume_curve(struct sst_hsw *hsw,
struct sst_hsw_stream *stream, u64 curve_duration,
enum sst_hsw_volume_curve curve)
{
stream->vol_req.curve_duration = curve_duration;
stream->vol_req.curve_type = curve;
return 0;
}
int sst_hsw_stream_set_volume(struct sst_hsw *hsw,
struct sst_hsw_stream *stream, u32 stage_id, u32 channel, u32 volume)
{
struct sst_hsw_ipc_volume_req *req;
u32 header;
int ret;
trace_ipc_request("set stream volume", stream->reply.stream_hw_id);
if (channel >= 2 && channel != SST_HSW_CHANNELS_ALL)
return -EINVAL;
header = IPC_GLB_TYPE(IPC_GLB_STREAM_MESSAGE) |
IPC_STR_TYPE(IPC_STR_STAGE_MESSAGE);
header |= (stream->reply.stream_hw_id << IPC_STR_ID_SHIFT);
header |= (IPC_STG_SET_VOLUME << IPC_STG_TYPE_SHIFT);
header |= (stage_id << IPC_STG_ID_SHIFT);
req = &stream->vol_req;
req->target_volume = volume;
if (channel == SST_HSW_CHANNELS_ALL) {
if (hsw->mute[0] && hsw->mute[1]) {
hsw->mute_volume[0] = hsw->mute_volume[1] = volume;
return 0;
} else if (hsw->mute[0])
req->channel = 1;
else if (hsw->mute[1])
req->channel = 0;
else
req->channel = SST_HSW_CHANNELS_ALL;
} else {
if (hsw->mute[channel]) {
hsw->mute_volume[channel] = volume;
return 0;
}
req->channel = channel;
}
ret = ipc_tx_message_wait(hsw, header, req, sizeof(*req), NULL, 0);
if (ret < 0) {
dev_err(hsw->dev, "error: set stream volume failed\n");
return ret;
}
return 0;
}
int sst_hsw_mixer_mute(struct sst_hsw *hsw, u32 stage_id, u32 channel)
{
int ret;
ret = sst_hsw_mixer_get_volume(hsw, stage_id, channel,
&hsw->mute_volume[channel]);
if (ret < 0)
return ret;
ret = sst_hsw_mixer_set_volume(hsw, stage_id, channel, 0);
if (ret < 0) {
dev_err(hsw->dev, "error: failed to unmute mixer channel %d\n",
channel);
return ret;
}
hsw->mute[channel] = 1;
return 0;
}
int sst_hsw_mixer_unmute(struct sst_hsw *hsw, u32 stage_id, u32 channel)
{
int ret;
ret = sst_hsw_mixer_set_volume(hsw, stage_id, channel,
hsw->mixer_info.volume_register_address[channel]);
if (ret < 0) {
dev_err(hsw->dev, "error: failed to unmute mixer channel %d\n",
channel);
return ret;
}
hsw->mute[channel] = 0;
return 0;
}
int sst_hsw_mixer_get_volume(struct sst_hsw *hsw, u32 stage_id, u32 channel,
u32 *volume)
{
if (channel > 1)
return -EINVAL;
sst_dsp_read(hsw->dsp, volume,
hsw->mixer_info.volume_register_address[channel],
sizeof(*volume));
return 0;
}
int sst_hsw_mixer_set_volume_curve(struct sst_hsw *hsw,
u64 curve_duration, enum sst_hsw_volume_curve curve)
{
hsw->curve_duration = curve_duration;
hsw->curve_type = curve;
return 0;
}
int sst_hsw_mixer_set_volume(struct sst_hsw *hsw, u32 stage_id, u32 channel,
u32 volume)
{
struct sst_hsw_ipc_volume_req req;
u32 header;
int ret;
trace_ipc_request("set mixer volume", volume);
if (channel >= 2 && channel != SST_HSW_CHANNELS_ALL)
return -EINVAL;
if (channel == SST_HSW_CHANNELS_ALL) {
if (hsw->mute[0] && hsw->mute[1]) {
hsw->mute_volume[0] = hsw->mute_volume[1] = volume;
return 0;
} else if (hsw->mute[0])
req.channel = 1;
else if (hsw->mute[1])
req.channel = 0;
else
req.channel = SST_HSW_CHANNELS_ALL;
} else {
if (hsw->mute[channel]) {
hsw->mute_volume[channel] = volume;
return 0;
}
req.channel = channel;
}
header = IPC_GLB_TYPE(IPC_GLB_STREAM_MESSAGE) |
IPC_STR_TYPE(IPC_STR_STAGE_MESSAGE);
header |= (hsw->mixer_info.mixer_hw_id << IPC_STR_ID_SHIFT);
header |= (IPC_STG_SET_VOLUME << IPC_STG_TYPE_SHIFT);
header |= (stage_id << IPC_STG_ID_SHIFT);
req.curve_duration = hsw->curve_duration;
req.curve_type = hsw->curve_type;
req.target_volume = volume;
ret = ipc_tx_message_wait(hsw, header, &req, sizeof(req), NULL, 0);
if (ret < 0) {
dev_err(hsw->dev, "error: set mixer volume failed\n");
return ret;
}
return 0;
}
struct sst_hsw_stream *sst_hsw_stream_new(struct sst_hsw *hsw, int id,
u32 (*notify_position)(struct sst_hsw_stream *stream, void *data),
void *data)
{
struct sst_hsw_stream *stream;
struct sst_dsp *sst = hsw->dsp;
unsigned long flags;
stream = kzalloc(sizeof(*stream), GFP_KERNEL);
if (stream == NULL)
return NULL;
spin_lock_irqsave(&sst->spinlock, flags);
list_add(&stream->node, &hsw->stream_list);
stream->notify_position = notify_position;
stream->pdata = data;
stream->hsw = hsw;
stream->host_id = id;
INIT_WORK(&stream->notify_work, hsw_notification_work);
spin_unlock_irqrestore(&sst->spinlock, flags);
return stream;
}
int sst_hsw_stream_free(struct sst_hsw *hsw, struct sst_hsw_stream *stream)
{
u32 header;
int ret = 0;
struct sst_dsp *sst = hsw->dsp;
unsigned long flags;
if (!stream) {
dev_warn(hsw->dev, "warning: stream is NULL, no stream to free, ignore it.\n");
return 0;
}
if (!stream->commited)
goto out;
trace_ipc_request("stream free", stream->host_id);
stream->free_req.stream_id = stream->reply.stream_hw_id;
header = IPC_GLB_TYPE(IPC_GLB_FREE_STREAM);
ret = ipc_tx_message_wait(hsw, header, &stream->free_req,
sizeof(stream->free_req), NULL, 0);
if (ret < 0) {
dev_err(hsw->dev, "error: free stream %d failed\n",
stream->free_req.stream_id);
return -EAGAIN;
}
trace_hsw_stream_free_req(stream, &stream->free_req);
out:
cancel_work_sync(&stream->notify_work);
spin_lock_irqsave(&sst->spinlock, flags);
list_del(&stream->node);
kfree(stream);
spin_unlock_irqrestore(&sst->spinlock, flags);
return ret;
}
int sst_hsw_stream_set_bits(struct sst_hsw *hsw,
struct sst_hsw_stream *stream, enum sst_hsw_bitdepth bits)
{
if (stream->commited) {
dev_err(hsw->dev, "error: stream committed for set bits\n");
return -EINVAL;
}
stream->request.format.bitdepth = bits;
return 0;
}
int sst_hsw_stream_set_channels(struct sst_hsw *hsw,
struct sst_hsw_stream *stream, int channels)
{
if (stream->commited) {
dev_err(hsw->dev, "error: stream committed for set channels\n");
return -EINVAL;
}
stream->request.format.ch_num = channels;
return 0;
}
int sst_hsw_stream_set_rate(struct sst_hsw *hsw,
struct sst_hsw_stream *stream, int rate)
{
if (stream->commited) {
dev_err(hsw->dev, "error: stream committed for set rate\n");
return -EINVAL;
}
stream->request.format.frequency = rate;
return 0;
}
int sst_hsw_stream_set_map_config(struct sst_hsw *hsw,
struct sst_hsw_stream *stream, u32 map,
enum sst_hsw_channel_config config)
{
if (stream->commited) {
dev_err(hsw->dev, "error: stream committed for set map\n");
return -EINVAL;
}
stream->request.format.map = map;
stream->request.format.config = config;
return 0;
}
int sst_hsw_stream_set_style(struct sst_hsw *hsw,
struct sst_hsw_stream *stream, enum sst_hsw_interleaving style)
{
if (stream->commited) {
dev_err(hsw->dev, "error: stream committed for set style\n");
return -EINVAL;
}
stream->request.format.style = style;
return 0;
}
int sst_hsw_stream_set_valid(struct sst_hsw *hsw,
struct sst_hsw_stream *stream, u32 bits)
{
if (stream->commited) {
dev_err(hsw->dev, "error: stream committed for set valid bits\n");
return -EINVAL;
}
stream->request.format.valid_bit = bits;
return 0;
}
int sst_hsw_stream_format(struct sst_hsw *hsw, struct sst_hsw_stream *stream,
enum sst_hsw_stream_path_id path_id,
enum sst_hsw_stream_type stream_type,
enum sst_hsw_stream_format format_id)
{
if (stream->commited) {
dev_err(hsw->dev, "error: stream committed for set format\n");
return -EINVAL;
}
stream->request.path_id = path_id;
stream->request.stream_type = stream_type;
stream->request.format_id = format_id;
trace_hsw_stream_alloc_request(stream, &stream->request);
return 0;
}
int sst_hsw_stream_buffer(struct sst_hsw *hsw, struct sst_hsw_stream *stream,
u32 ring_pt_address, u32 num_pages,
u32 ring_size, u32 ring_offset, u32 ring_first_pfn)
{
if (stream->commited) {
dev_err(hsw->dev, "error: stream committed for buffer\n");
return -EINVAL;
}
stream->request.ringinfo.ring_pt_address = ring_pt_address;
stream->request.ringinfo.num_pages = num_pages;
stream->request.ringinfo.ring_size = ring_size;
stream->request.ringinfo.ring_offset = ring_offset;
stream->request.ringinfo.ring_first_pfn = ring_first_pfn;
trace_hsw_stream_buffer(stream);
return 0;
}
int sst_hsw_stream_set_module_info(struct sst_hsw *hsw,
struct sst_hsw_stream *stream, struct sst_module_runtime *runtime)
{
struct sst_hsw_module_map *map = &stream->request.map;
struct sst_dsp *dsp = sst_hsw_get_dsp(hsw);
struct sst_module *module = runtime->module;
if (stream->commited) {
dev_err(hsw->dev, "error: stream committed for set module\n");
return -EINVAL;
}
map->module_entries_count = 1;
map->module_entries[0].module_id = module->id;
map->module_entries[0].entry_point = module->entry;
stream->request.persistent_mem.offset =
sst_dsp_get_offset(dsp, runtime->persistent_offset, SST_MEM_DRAM);
stream->request.persistent_mem.size = module->persistent_size;
stream->request.scratch_mem.offset =
sst_dsp_get_offset(dsp, dsp->scratch_offset, SST_MEM_DRAM);
stream->request.scratch_mem.size = dsp->scratch_size;
dev_dbg(hsw->dev, "module %d runtime %d using:\n", module->id,
runtime->id);
dev_dbg(hsw->dev, " persistent offset 0x%x bytes 0x%x\n",
stream->request.persistent_mem.offset,
stream->request.persistent_mem.size);
dev_dbg(hsw->dev, " scratch offset 0x%x bytes 0x%x\n",
stream->request.scratch_mem.offset,
stream->request.scratch_mem.size);
return 0;
}
int sst_hsw_stream_commit(struct sst_hsw *hsw, struct sst_hsw_stream *stream)
{
struct sst_hsw_ipc_stream_alloc_req *str_req = &stream->request;
struct sst_hsw_ipc_stream_alloc_reply *reply = &stream->reply;
u32 header;
int ret;
if (!stream) {
dev_warn(hsw->dev, "warning: stream is NULL, no stream to commit, ignore it.\n");
return 0;
}
if (stream->commited) {
dev_warn(hsw->dev, "warning: stream is already committed, ignore it.\n");
return 0;
}
trace_ipc_request("stream alloc", stream->host_id);
header = IPC_GLB_TYPE(IPC_GLB_ALLOCATE_STREAM);
ret = ipc_tx_message_wait(hsw, header, str_req, sizeof(*str_req),
reply, sizeof(*reply));
if (ret < 0) {
dev_err(hsw->dev, "error: stream commit failed\n");
return ret;
}
stream->commited = 1;
trace_hsw_stream_alloc_reply(stream);
return 0;
}
int sst_hsw_stream_get_hw_id(struct sst_hsw *hsw,
struct sst_hsw_stream *stream)
{
return stream->reply.stream_hw_id;
}
int sst_hsw_stream_get_mixer_id(struct sst_hsw *hsw,
struct sst_hsw_stream *stream)
{
return stream->reply.mixer_hw_id;
}
u32 sst_hsw_stream_get_read_reg(struct sst_hsw *hsw,
struct sst_hsw_stream *stream)
{
return stream->reply.read_position_register_address;
}
u32 sst_hsw_stream_get_pointer_reg(struct sst_hsw *hsw,
struct sst_hsw_stream *stream)
{
return stream->reply.presentation_position_register_address;
}
u32 sst_hsw_stream_get_peak_reg(struct sst_hsw *hsw,
struct sst_hsw_stream *stream, u32 channel)
{
if (channel >= 2)
return 0;
return stream->reply.peak_meter_register_address[channel];
}
u32 sst_hsw_stream_get_vol_reg(struct sst_hsw *hsw,
struct sst_hsw_stream *stream, u32 channel)
{
if (channel >= 2)
return 0;
return stream->reply.volume_register_address[channel];
}
int sst_hsw_mixer_get_info(struct sst_hsw *hsw)
{
struct sst_hsw_ipc_stream_info_reply *reply;
u32 header;
int ret;
reply = &hsw->mixer_info;
header = IPC_GLB_TYPE(IPC_GLB_GET_MIXER_STREAM_INFO);
trace_ipc_request("get global mixer info", 0);
ret = ipc_tx_message_wait(hsw, header, NULL, 0, reply, sizeof(*reply));
if (ret < 0) {
dev_err(hsw->dev, "error: get stream info failed\n");
return ret;
}
trace_hsw_mixer_info_reply(reply);
return 0;
}
static int sst_hsw_stream_operations(struct sst_hsw *hsw, int type,
int stream_id, int wait)
{
u32 header;
header = IPC_GLB_TYPE(IPC_GLB_STREAM_MESSAGE) | IPC_STR_TYPE(type);
header |= (stream_id << IPC_STR_ID_SHIFT);
if (wait)
return ipc_tx_message_wait(hsw, header, NULL, 0, NULL, 0);
else
return ipc_tx_message_nowait(hsw, header, NULL, 0);
}
int sst_hsw_stream_pause(struct sst_hsw *hsw, struct sst_hsw_stream *stream,
int wait)
{
int ret;
if (!stream) {
dev_warn(hsw->dev, "warning: stream is NULL, no stream to pause, ignore it.\n");
return 0;
}
trace_ipc_request("stream pause", stream->reply.stream_hw_id);
ret = sst_hsw_stream_operations(hsw, IPC_STR_PAUSE,
stream->reply.stream_hw_id, wait);
if (ret < 0)
dev_err(hsw->dev, "error: failed to pause stream %d\n",
stream->reply.stream_hw_id);
return ret;
}
int sst_hsw_stream_resume(struct sst_hsw *hsw, struct sst_hsw_stream *stream,
int wait)
{
int ret;
if (!stream) {
dev_warn(hsw->dev, "warning: stream is NULL, no stream to resume, ignore it.\n");
return 0;
}
trace_ipc_request("stream resume", stream->reply.stream_hw_id);
ret = sst_hsw_stream_operations(hsw, IPC_STR_RESUME,
stream->reply.stream_hw_id, wait);
if (ret < 0)
dev_err(hsw->dev, "error: failed to resume stream %d\n",
stream->reply.stream_hw_id);
return ret;
}
int sst_hsw_stream_reset(struct sst_hsw *hsw, struct sst_hsw_stream *stream)
{
int ret, tries = 10;
if (!stream) {
dev_warn(hsw->dev, "warning: stream is NULL, no stream to reset, ignore it.\n");
return 0;
}
if (!stream->commited)
return 0;
while (stream->running && tries--)
msleep(1);
if (!tries) {
dev_err(hsw->dev, "error: reset stream %d still running\n",
stream->reply.stream_hw_id);
return -EINVAL;
}
trace_ipc_request("stream reset", stream->reply.stream_hw_id);
ret = sst_hsw_stream_operations(hsw, IPC_STR_RESET,
stream->reply.stream_hw_id, 1);
if (ret < 0)
dev_err(hsw->dev, "error: failed to reset stream %d\n",
stream->reply.stream_hw_id);
return ret;
}
u32 sst_hsw_get_dsp_position(struct sst_hsw *hsw,
struct sst_hsw_stream *stream)
{
u32 rpos;
sst_dsp_read(hsw->dsp, &rpos,
stream->reply.read_position_register_address, sizeof(rpos));
return rpos;
}
u64 sst_hsw_get_dsp_presentation_position(struct sst_hsw *hsw,
struct sst_hsw_stream *stream)
{
u64 ppos;
sst_dsp_read(hsw->dsp, &ppos,
stream->reply.presentation_position_register_address,
sizeof(ppos));
return ppos;
}
int sst_hsw_stream_set_write_position(struct sst_hsw *hsw,
struct sst_hsw_stream *stream, u32 stage_id, u32 position)
{
u32 header;
int ret;
trace_stream_write_position(stream->reply.stream_hw_id, position);
header = IPC_GLB_TYPE(IPC_GLB_STREAM_MESSAGE) |
IPC_STR_TYPE(IPC_STR_STAGE_MESSAGE);
header |= (stream->reply.stream_hw_id << IPC_STR_ID_SHIFT);
header |= (IPC_STG_SET_WRITE_POSITION << IPC_STG_TYPE_SHIFT);
header |= (stage_id << IPC_STG_ID_SHIFT);
stream->wpos.position = position;
ret = ipc_tx_message_nowait(hsw, header, &stream->wpos,
sizeof(stream->wpos));
if (ret < 0)
dev_err(hsw->dev, "error: stream %d set position %d failed\n",
stream->reply.stream_hw_id, position);
return ret;
}
int sst_hsw_device_set_config(struct sst_hsw *hsw,
enum sst_hsw_device_id dev, enum sst_hsw_device_mclk mclk,
enum sst_hsw_device_mode mode, u32 clock_divider)
{
struct sst_hsw_ipc_device_config_req config;
u32 header;
int ret;
trace_ipc_request("set device config", dev);
config.ssp_interface = dev;
config.clock_frequency = mclk;
config.mode = mode;
config.clock_divider = clock_divider;
if (mode == SST_HSW_DEVICE_TDM_CLOCK_MASTER)
config.channels = 4;
else
config.channels = 2;
trace_hsw_device_config_req(&config);
header = IPC_GLB_TYPE(IPC_GLB_SET_DEVICE_FORMATS);
ret = ipc_tx_message_wait(hsw, header, &config, sizeof(config),
NULL, 0);
if (ret < 0)
dev_err(hsw->dev, "error: set device formats failed\n");
return ret;
}
int sst_hsw_dx_set_state(struct sst_hsw *hsw,
enum sst_hsw_dx_state state, struct sst_hsw_ipc_dx_reply *dx)
{
u32 header, state_;
int ret, item;
header = IPC_GLB_TYPE(IPC_GLB_ENTER_DX_STATE);
state_ = state;
trace_ipc_request("PM enter Dx state", state);
ret = ipc_tx_message_wait(hsw, header, &state_, sizeof(state_),
dx, sizeof(*dx));
if (ret < 0) {
dev_err(hsw->dev, "ipc: error set dx state %d failed\n", state);
return ret;
}
for (item = 0; item < dx->entries_no; item++) {
dev_dbg(hsw->dev,
"Item[%d] offset[%x] - size[%x] - source[%x]\n",
item, dx->mem_info[item].offset,
dx->mem_info[item].size,
dx->mem_info[item].source);
}
dev_dbg(hsw->dev, "ipc: got %d entry numbers for state %d\n",
dx->entries_no, state);
return ret;
}
struct sst_module_runtime *sst_hsw_runtime_module_create(struct sst_hsw *hsw,
int mod_id, int offset)
{
struct sst_dsp *dsp = hsw->dsp;
struct sst_module *module;
struct sst_module_runtime *runtime;
int err;
module = sst_module_get_from_id(dsp, mod_id);
if (module == NULL) {
dev_err(dsp->dev, "error: failed to get module %d for pcm\n",
mod_id);
return NULL;
}
runtime = sst_module_runtime_new(module, mod_id, NULL);
if (runtime == NULL) {
dev_err(dsp->dev, "error: failed to create module %d runtime\n",
mod_id);
return NULL;
}
err = sst_module_runtime_alloc_blocks(runtime, offset);
if (err < 0) {
dev_err(dsp->dev, "error: failed to alloc blocks for module %d runtime\n",
mod_id);
sst_module_runtime_free(runtime);
return NULL;
}
dev_dbg(dsp->dev, "runtime id %d created for module %d\n", runtime->id,
mod_id);
return runtime;
}
void sst_hsw_runtime_module_free(struct sst_module_runtime *runtime)
{
sst_module_runtime_free_blocks(runtime);
sst_module_runtime_free(runtime);
}
static int sst_hsw_dx_state_dump(struct sst_hsw *hsw)
{
struct sst_dsp *sst = hsw->dsp;
u32 item, offset, size;
int ret = 0;
trace_ipc_request("PM state dump. Items #", SST_HSW_MAX_DX_REGIONS);
if (hsw->dx.entries_no > SST_HSW_MAX_DX_REGIONS) {
dev_err(hsw->dev,
"error: number of FW context regions greater than %d\n",
SST_HSW_MAX_DX_REGIONS);
memset(&hsw->dx, 0, sizeof(hsw->dx));
return -EINVAL;
}
ret = sst_dsp_dma_get_channel(sst, 0);
if (ret < 0) {
dev_err(hsw->dev, "error: cant allocate dma channel %d\n", ret);
return ret;
}
sst_dsp_shim_update_bits(sst, SST_HMDC,
SST_HMDC_HDDA_E0_ALLCH | SST_HMDC_HDDA_E1_ALLCH,
SST_HMDC_HDDA_E0_ALLCH | SST_HMDC_HDDA_E1_ALLCH);
for (item = 0; item < hsw->dx.entries_no; item++) {
if (hsw->dx.mem_info[item].source == SST_HSW_DX_TYPE_MEMORY_DUMP
&& hsw->dx.mem_info[item].offset > DSP_DRAM_ADDR_OFFSET
&& hsw->dx.mem_info[item].offset <
DSP_DRAM_ADDR_OFFSET + SST_HSW_DX_CONTEXT_SIZE) {
offset = hsw->dx.mem_info[item].offset
- DSP_DRAM_ADDR_OFFSET;
size = (hsw->dx.mem_info[item].size + 3) & (~3);
ret = sst_dsp_dma_copyfrom(sst, hsw->dx_context_paddr + offset,
sst->addr.lpe_base + offset, size);
if (ret < 0) {
dev_err(hsw->dev,
"error: FW context dump failed\n");
memset(&hsw->dx, 0, sizeof(hsw->dx));
goto out;
}
}
}
out:
sst_dsp_dma_put_channel(sst);
return ret;
}
static int sst_hsw_dx_state_restore(struct sst_hsw *hsw)
{
struct sst_dsp *sst = hsw->dsp;
u32 item, offset, size;
int ret;
for (item = 0; item < hsw->dx.entries_no; item++) {
if (hsw->dx.mem_info[item].source == SST_HSW_DX_TYPE_MEMORY_DUMP
&& hsw->dx.mem_info[item].offset > DSP_DRAM_ADDR_OFFSET
&& hsw->dx.mem_info[item].offset <
DSP_DRAM_ADDR_OFFSET + SST_HSW_DX_CONTEXT_SIZE) {
offset = hsw->dx.mem_info[item].offset
- DSP_DRAM_ADDR_OFFSET;
size = (hsw->dx.mem_info[item].size + 3) & (~3);
ret = sst_dsp_dma_copyto(sst, sst->addr.lpe_base + offset,
hsw->dx_context_paddr + offset, size);
if (ret < 0) {
dev_err(hsw->dev,
"error: FW context restore failed\n");
return ret;
}
}
}
return 0;
}
static void sst_hsw_drop_all(struct sst_hsw *hsw)
{
struct ipc_message *msg, *tmp;
unsigned long flags;
int tx_drop_cnt = 0, rx_drop_cnt = 0;
spin_lock_irqsave(&hsw->dsp->spinlock, flags);
list_for_each_entry_safe(msg, tmp, &hsw->tx_list, list) {
list_move(&msg->list, &hsw->empty_list);
tx_drop_cnt++;
}
list_for_each_entry_safe(msg, tmp, &hsw->rx_list, list) {
list_move(&msg->list, &hsw->empty_list);
rx_drop_cnt++;
}
spin_unlock_irqrestore(&hsw->dsp->spinlock, flags);
if (tx_drop_cnt || rx_drop_cnt)
dev_err(hsw->dev, "dropped IPC msg RX=%d, TX=%d\n",
tx_drop_cnt, rx_drop_cnt);
}
int sst_hsw_dsp_load(struct sst_hsw *hsw)
{
struct sst_dsp *dsp = hsw->dsp;
int ret;
dev_dbg(hsw->dev, "loading audio DSP....");
ret = sst_dsp_wake(dsp);
if (ret < 0) {
dev_err(hsw->dev, "error: failed to wake audio DSP\n");
return -ENODEV;
}
ret = sst_dsp_dma_get_channel(dsp, 0);
if (ret < 0) {
dev_err(hsw->dev, "error: cant allocate dma channel %d\n", ret);
return ret;
}
ret = sst_fw_reload(hsw->sst_fw);
if (ret < 0) {
dev_err(hsw->dev, "error: SST FW reload failed\n");
sst_dsp_dma_put_channel(dsp);
return -ENOMEM;
}
sst_dsp_dma_put_channel(dsp);
return 0;
}
static int sst_hsw_dsp_restore(struct sst_hsw *hsw)
{
struct sst_dsp *dsp = hsw->dsp;
int ret;
dev_dbg(hsw->dev, "restoring audio DSP....");
ret = sst_dsp_dma_get_channel(dsp, 0);
if (ret < 0) {
dev_err(hsw->dev, "error: cant allocate dma channel %d\n", ret);
return ret;
}
ret = sst_hsw_dx_state_restore(hsw);
if (ret < 0) {
dev_err(hsw->dev, "error: SST FW context restore failed\n");
sst_dsp_dma_put_channel(dsp);
return -ENOMEM;
}
sst_dsp_dma_put_channel(dsp);
sst_dsp_boot(dsp);
return ret;
}
int sst_hsw_dsp_runtime_suspend(struct sst_hsw *hsw)
{
int ret;
dev_dbg(hsw->dev, "audio dsp runtime suspend\n");
ret = sst_hsw_dx_set_state(hsw, SST_HSW_DX_STATE_D3, &hsw->dx);
if (ret < 0)
return ret;
sst_dsp_stall(hsw->dsp);
ret = sst_hsw_dx_state_dump(hsw);
if (ret < 0)
return ret;
sst_hsw_drop_all(hsw);
return 0;
}
int sst_hsw_dsp_runtime_sleep(struct sst_hsw *hsw)
{
sst_fw_unload(hsw->sst_fw);
sst_block_free_scratch(hsw->dsp);
hsw->boot_complete = false;
sst_dsp_sleep(hsw->dsp);
return 0;
}
int sst_hsw_dsp_runtime_resume(struct sst_hsw *hsw)
{
struct device *dev = hsw->dev;
int ret;
dev_dbg(dev, "audio dsp runtime resume\n");
if (hsw->boot_complete)
return 1;
ret = sst_hsw_dsp_restore(hsw);
if (ret < 0)
dev_err(dev, "error: audio DSP boot failure\n");
ret = wait_event_timeout(hsw->boot_wait, hsw->boot_complete,
msecs_to_jiffies(IPC_BOOT_MSECS));
if (ret == 0) {
dev_err(hsw->dev, "error: audio DSP boot timeout IPCD 0x%x IPCX 0x%x\n",
sst_dsp_shim_read_unlocked(hsw->dsp, SST_IPCD),
sst_dsp_shim_read_unlocked(hsw->dsp, SST_IPCX));
return -EIO;
}
ret = sst_hsw_device_set_config(hsw, SST_HSW_DEVICE_SSP_0,
SST_HSW_DEVICE_MCLK_FREQ_24_MHZ,
SST_HSW_DEVICE_CLOCK_MASTER, 9);
if (ret < 0)
dev_err(dev, "error: SSP re-initialization failed\n");
return ret;
}
static int msg_empty_list_init(struct sst_hsw *hsw)
{
int i;
hsw->msg = kzalloc(sizeof(struct ipc_message) *
IPC_EMPTY_LIST_SIZE, GFP_KERNEL);
if (hsw->msg == NULL)
return -ENOMEM;
for (i = 0; i < IPC_EMPTY_LIST_SIZE; i++) {
init_waitqueue_head(&hsw->msg[i].waitq);
list_add(&hsw->msg[i].list, &hsw->empty_list);
}
return 0;
}
struct sst_dsp *sst_hsw_get_dsp(struct sst_hsw *hsw)
{
return hsw->dsp;
}
int sst_hsw_dsp_init(struct device *dev, struct sst_pdata *pdata)
{
struct sst_hsw_ipc_fw_version version;
struct sst_hsw *hsw;
int ret;
dev_dbg(dev, "initialising Audio DSP IPC\n");
hsw = devm_kzalloc(dev, sizeof(*hsw), GFP_KERNEL);
if (hsw == NULL)
return -ENOMEM;
hsw->dev = dev;
INIT_LIST_HEAD(&hsw->stream_list);
INIT_LIST_HEAD(&hsw->tx_list);
INIT_LIST_HEAD(&hsw->rx_list);
INIT_LIST_HEAD(&hsw->empty_list);
init_waitqueue_head(&hsw->boot_wait);
init_waitqueue_head(&hsw->wait_txq);
ret = msg_empty_list_init(hsw);
if (ret < 0)
return -ENOMEM;
init_kthread_worker(&hsw->kworker);
hsw->tx_thread = kthread_run(kthread_worker_fn,
&hsw->kworker, "%s",
dev_name(hsw->dev));
if (IS_ERR(hsw->tx_thread)) {
ret = PTR_ERR(hsw->tx_thread);
dev_err(hsw->dev, "error: failed to create message TX task\n");
goto err_free_msg;
}
init_kthread_work(&hsw->kwork, ipc_tx_msgs);
hsw_dev.thread_context = hsw;
hsw->dsp = sst_dsp_new(dev, &hsw_dev, pdata);
if (hsw->dsp == NULL) {
ret = -ENODEV;
goto dsp_err;
}
hsw->dx_context = dma_alloc_coherent(hsw->dsp->dma_dev,
SST_HSW_DX_CONTEXT_SIZE, &hsw->dx_context_paddr, GFP_KERNEL);
if (hsw->dx_context == NULL) {
ret = -ENOMEM;
goto dma_err;
}
sst_dsp_reset(hsw->dsp);
hsw->sst_fw = sst_fw_new(hsw->dsp, pdata->fw, hsw);
if (hsw->sst_fw == NULL) {
ret = -ENODEV;
dev_err(dev, "error: failed to load firmware\n");
goto fw_err;
}
sst_dsp_boot(hsw->dsp);
ret = wait_event_timeout(hsw->boot_wait, hsw->boot_complete,
msecs_to_jiffies(IPC_BOOT_MSECS));
if (ret == 0) {
ret = -EIO;
dev_err(hsw->dev, "error: audio DSP boot timeout IPCD 0x%x IPCX 0x%x\n",
sst_dsp_shim_read_unlocked(hsw->dsp, SST_IPCD),
sst_dsp_shim_read_unlocked(hsw->dsp, SST_IPCX));
goto boot_err;
}
sst_hsw_fw_get_version(hsw, &version);
ret = sst_hsw_mixer_get_info(hsw);
if (ret < 0) {
dev_err(hsw->dev, "error: failed to get stream info\n");
goto boot_err;
}
pdata->dsp = hsw;
return 0;
boot_err:
sst_dsp_reset(hsw->dsp);
sst_fw_free(hsw->sst_fw);
fw_err:
dma_free_coherent(hsw->dsp->dma_dev, SST_HSW_DX_CONTEXT_SIZE,
hsw->dx_context, hsw->dx_context_paddr);
dma_err:
sst_dsp_free(hsw->dsp);
dsp_err:
kthread_stop(hsw->tx_thread);
err_free_msg:
kfree(hsw->msg);
return ret;
}
void sst_hsw_dsp_free(struct device *dev, struct sst_pdata *pdata)
{
struct sst_hsw *hsw = pdata->dsp;
sst_dsp_reset(hsw->dsp);
sst_fw_free_all(hsw->dsp);
dma_free_coherent(hsw->dsp->dma_dev, SST_HSW_DX_CONTEXT_SIZE,
hsw->dx_context, hsw->dx_context_paddr);
sst_dsp_free(hsw->dsp);
kfree(hsw->scratch);
kthread_stop(hsw->tx_thread);
kfree(hsw->msg);
}
