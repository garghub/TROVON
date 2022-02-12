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
static inline u32 msg_get_stream_id(u32 msg)
{
return (msg & IPC_STR_ID_MASK) >> IPC_STR_ID_SHIFT;
}
static inline u32 msg_get_notify_reason(u32 msg)
{
return (msg & IPC_STG_TYPE_MASK) >> IPC_STG_TYPE_SHIFT;
}
static inline u32 msg_get_module_operation(u32 msg)
{
return (msg & IPC_MODULE_OPERATION_MASK) >> IPC_MODULE_OPERATION_SHIFT;
}
static inline u32 msg_get_module_id(u32 msg)
{
return (msg & IPC_MODULE_ID_MASK) >> IPC_MODULE_ID_SHIFT;
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
for (i = 0; i < ARRAY_SIZE(tmp); i++)
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
msg = sst_ipc_reply_find_msg(&hsw->ipc, header);
if (msg == NULL) {
trace_ipc_error("error: can't find message header", header);
return -EIO;
}
switch (reply) {
case IPC_GLB_REPLY_PENDING:
trace_ipc_pending_reply("received", header);
msg->pending = true;
hsw->ipc.pending = true;
return 1;
case IPC_GLB_REPLY_SUCCESS:
if (msg->pending) {
trace_ipc_pending_reply("completed", header);
sst_dsp_inbox_read(hsw->dsp, msg->rx_data,
msg->rx_size);
hsw->ipc.pending = false;
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
sst_ipc_tx_msg_reply_complete(&hsw->ipc, msg);
return 1;
}
static int hsw_module_message(struct sst_hsw *hsw, u32 header)
{
u32 operation, module_id;
int handled = 0;
operation = msg_get_module_operation(header);
module_id = msg_get_module_id(header);
dev_dbg(hsw->dev, "received module message header: 0x%8.8x\n",
header);
dev_dbg(hsw->dev, "operation: 0x%8.8x module_id: 0x%8.8x\n",
operation, module_id);
switch (operation) {
case IPC_MODULE_NOTIFICATION:
dev_dbg(hsw->dev, "module notification received");
handled = 1;
break;
default:
handled = hsw_process_reply(hsw, header);
break;
}
return handled;
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
case IPC_GLB_MODULE_OPERATION:
handled = hsw_module_message(hsw, header);
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
struct sst_generic_ipc *ipc = &hsw->ipc;
u32 ipcx, ipcd;
unsigned long flags;
spin_lock_irqsave(&sst->spinlock, flags);
ipcx = sst_dsp_ipc_msg_rx(hsw->dsp);
ipcd = sst_dsp_shim_read_unlocked(sst, SST_IPCD);
if (ipcx & SST_IPCX_DONE) {
hsw_process_reply(hsw, ipcx);
sst_dsp_shim_update_bits_unlocked(sst, SST_IPCX,
SST_IPCX_DONE, 0);
sst_dsp_shim_update_bits_unlocked(sst, SST_IMRX,
SST_IMRX_DONE, 0);
}
if (ipcd & SST_IPCD_BUSY) {
hsw_process_notification(hsw);
sst_dsp_shim_update_bits_unlocked(sst, SST_IPCD,
SST_IPCD_BUSY | SST_IPCD_DONE, SST_IPCD_DONE);
sst_dsp_shim_update_bits_unlocked(sst, SST_IMRX,
SST_IMRX_BUSY, 0);
}
spin_unlock_irqrestore(&sst->spinlock, flags);
queue_kthread_work(&ipc->kworker, &ipc->kwork);
return IRQ_HANDLED;
}
int sst_hsw_fw_get_version(struct sst_hsw *hsw,
struct sst_hsw_ipc_fw_version *version)
{
int ret;
ret = sst_ipc_tx_message_wait(&hsw->ipc,
IPC_GLB_TYPE(IPC_GLB_GET_FW_VERSION),
NULL, 0, version, sizeof(*version));
if (ret < 0)
dev_err(hsw->dev, "error: get version failed\n");
return ret;
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
ret = sst_ipc_tx_message_wait(&hsw->ipc, header, req,
sizeof(*req), NULL, 0);
if (ret < 0) {
dev_err(hsw->dev, "error: set stream volume failed\n");
return ret;
}
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
ret = sst_ipc_tx_message_wait(&hsw->ipc, header, &req,
sizeof(req), NULL, 0);
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
stream->reply.stream_hw_id = INVALID_STREAM_HW_ID;
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
ret = sst_ipc_tx_message_wait(&hsw->ipc, header, &stream->free_req,
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
ret = sst_ipc_tx_message_wait(&hsw->ipc, header, str_req,
sizeof(*str_req), reply, sizeof(*reply));
if (ret < 0) {
dev_err(hsw->dev, "error: stream commit failed\n");
return ret;
}
stream->commited = 1;
trace_hsw_stream_alloc_reply(stream);
return 0;
}
snd_pcm_uframes_t sst_hsw_stream_get_old_position(struct sst_hsw *hsw,
struct sst_hsw_stream *stream)
{
return stream->old_position;
}
void sst_hsw_stream_set_old_position(struct sst_hsw *hsw,
struct sst_hsw_stream *stream, snd_pcm_uframes_t val)
{
stream->old_position = val;
}
bool sst_hsw_stream_get_silence_start(struct sst_hsw *hsw,
struct sst_hsw_stream *stream)
{
return stream->play_silence;
}
void sst_hsw_stream_set_silence_start(struct sst_hsw *hsw,
struct sst_hsw_stream *stream, bool val)
{
stream->play_silence = val;
}
int sst_hsw_mixer_get_info(struct sst_hsw *hsw)
{
struct sst_hsw_ipc_stream_info_reply *reply;
u32 header;
int ret;
reply = &hsw->mixer_info;
header = IPC_GLB_TYPE(IPC_GLB_GET_MIXER_STREAM_INFO);
trace_ipc_request("get global mixer info", 0);
ret = sst_ipc_tx_message_wait(&hsw->ipc, header, NULL, 0,
reply, sizeof(*reply));
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
return sst_ipc_tx_message_wait(&hsw->ipc, header,
NULL, 0, NULL, 0);
else
return sst_ipc_tx_message_nowait(&hsw->ipc, header, NULL, 0);
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
while (stream->running && --tries)
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
int sst_hsw_device_set_config(struct sst_hsw *hsw,
enum sst_hsw_device_id dev, enum sst_hsw_device_mclk mclk,
enum sst_hsw_device_mode mode, u32 clock_divider)
{
struct sst_hsw_ipc_device_config_req config;
u32 header;
int ret;
trace_ipc_request("set device config", dev);
hsw->dx_dev = config.ssp_interface = dev;
hsw->dx_mclk = config.clock_frequency = mclk;
hsw->dx_mode = config.mode = mode;
hsw->dx_clock_divider = config.clock_divider = clock_divider;
if (mode == SST_HSW_DEVICE_TDM_CLOCK_MASTER)
config.channels = 4;
else
config.channels = 2;
trace_hsw_device_config_req(&config);
header = IPC_GLB_TYPE(IPC_GLB_SET_DEVICE_FORMATS);
ret = sst_ipc_tx_message_wait(&hsw->ipc, header, &config,
sizeof(config), NULL, 0);
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
ret = sst_ipc_tx_message_wait(&hsw->ipc, header, &state_,
sizeof(state_), dx, sizeof(*dx));
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
int sst_hsw_dsp_load(struct sst_hsw *hsw)
{
struct sst_dsp *dsp = hsw->dsp;
struct sst_fw *sst_fw, *t;
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
list_for_each_entry_safe_reverse(sst_fw, t, &dsp->fw_list, list) {
ret = sst_fw_reload(sst_fw);
if (ret < 0) {
dev_err(hsw->dev, "error: SST FW reload failed\n");
sst_dsp_dma_put_channel(dsp);
return -ENOMEM;
}
}
ret = sst_block_alloc_scratch(hsw->dsp);
if (ret < 0)
return -EINVAL;
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
sst_ipc_drop_all(&hsw->ipc);
return 0;
}
int sst_hsw_dsp_runtime_sleep(struct sst_hsw *hsw)
{
struct sst_fw *sst_fw, *t;
struct sst_dsp *dsp = hsw->dsp;
list_for_each_entry_safe(sst_fw, t, &dsp->fw_list, list) {
sst_fw_unload(sst_fw);
}
sst_block_free_scratch(dsp);
hsw->boot_complete = false;
sst_dsp_sleep(dsp);
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
sst_hsw_init_module_state(hsw);
ret = wait_event_timeout(hsw->boot_wait, hsw->boot_complete,
msecs_to_jiffies(IPC_BOOT_MSECS));
if (ret == 0) {
dev_err(hsw->dev, "error: audio DSP boot timeout IPCD 0x%x IPCX 0x%x\n",
sst_dsp_shim_read_unlocked(hsw->dsp, SST_IPCD),
sst_dsp_shim_read_unlocked(hsw->dsp, SST_IPCX));
return -EIO;
}
ret = sst_hsw_device_set_config(hsw, hsw->dx_dev, hsw->dx_mclk,
hsw->dx_mode, hsw->dx_clock_divider);
if (ret < 0)
dev_err(dev, "error: SSP re-initialization failed\n");
return ret;
}
struct sst_dsp *sst_hsw_get_dsp(struct sst_hsw *hsw)
{
return hsw->dsp;
}
void sst_hsw_init_module_state(struct sst_hsw *hsw)
{
struct sst_module *module;
enum sst_hsw_module_id id;
for (id = SST_HSW_MODULE_BASE_FW; id < SST_HSW_MAX_MODULE_ID; id++) {
module = sst_module_get_from_id(hsw->dsp, id);
if (module) {
if (id == SST_HSW_MODULE_WAVES)
module->state = SST_MODULE_STATE_INITIALIZED;
else
module->state = SST_MODULE_STATE_ACTIVE;
}
}
}
bool sst_hsw_is_module_loaded(struct sst_hsw *hsw, u32 module_id)
{
struct sst_module *module;
module = sst_module_get_from_id(hsw->dsp, module_id);
if (module == NULL || module->state == SST_MODULE_STATE_UNLOADED)
return false;
else
return true;
}
bool sst_hsw_is_module_active(struct sst_hsw *hsw, u32 module_id)
{
struct sst_module *module;
module = sst_module_get_from_id(hsw->dsp, module_id);
if (module != NULL && module->state == SST_MODULE_STATE_ACTIVE)
return true;
else
return false;
}
void sst_hsw_set_module_enabled_rtd3(struct sst_hsw *hsw, u32 module_id)
{
hsw->enabled_modules_rtd3 |= (1 << module_id);
}
void sst_hsw_set_module_disabled_rtd3(struct sst_hsw *hsw, u32 module_id)
{
hsw->enabled_modules_rtd3 &= ~(1 << module_id);
}
bool sst_hsw_is_module_enabled_rtd3(struct sst_hsw *hsw, u32 module_id)
{
return hsw->enabled_modules_rtd3 & (1 << module_id);
}
void sst_hsw_reset_param_buf(struct sst_hsw *hsw)
{
hsw->param_idx_w = 0;
hsw->param_idx_r = 0;
memset((void *)hsw->param_buf, 0, sizeof(hsw->param_buf));
}
int sst_hsw_store_param_line(struct sst_hsw *hsw, u8 *buf)
{
if (hsw->param_idx_w > WAVES_PARAM_LINES - 1) {
dev_warn(hsw->dev, "warning: param buffer overflow!\n");
return -EPERM;
}
memcpy(hsw->param_buf[hsw->param_idx_w], buf, WAVES_PARAM_COUNT);
hsw->param_idx_w++;
return 0;
}
int sst_hsw_load_param_line(struct sst_hsw *hsw, u8 *buf)
{
u8 id = 0;
while (hsw->param_idx_r < WAVES_PARAM_LINES) {
id = hsw->param_buf[hsw->param_idx_r][0];
hsw->param_idx_r++;
if (buf[0] == id) {
memcpy(buf, hsw->param_buf[hsw->param_idx_r],
WAVES_PARAM_COUNT);
break;
}
}
if (hsw->param_idx_r > WAVES_PARAM_LINES - 1) {
dev_dbg(hsw->dev, "end of buffer, roll to the beginning\n");
hsw->param_idx_r = 0;
return 0;
}
return 0;
}
int sst_hsw_launch_param_buf(struct sst_hsw *hsw)
{
int ret, idx;
if (!sst_hsw_is_module_active(hsw, SST_HSW_MODULE_WAVES)) {
dev_dbg(hsw->dev, "module waves is not active\n");
return 0;
}
for (idx = 0; idx < hsw->param_idx_w; idx++) {
ret = sst_hsw_module_set_param(hsw,
SST_HSW_MODULE_WAVES, 0, hsw->param_buf[idx][0],
WAVES_PARAM_COUNT, hsw->param_buf[idx]);
if (ret < 0)
return ret;
}
return 0;
}
int sst_hsw_module_load(struct sst_hsw *hsw,
u32 module_id, u32 instance_id, char *name)
{
int ret = 0;
const struct firmware *fw = NULL;
struct sst_fw *hsw_sst_fw;
struct sst_module *module;
struct device *dev = hsw->dev;
struct sst_dsp *dsp = hsw->dsp;
dev_dbg(dev, "sst_hsw_module_load id=%d, name='%s'", module_id, name);
module = sst_module_get_from_id(dsp, module_id);
if (module == NULL) {
if (module_id == SST_HSW_MODULE_BASE_FW) {
fw = dsp->pdata->fw;
if (!fw) {
dev_err(dev, "request Base fw failed\n");
return -ENODEV;
}
} else {
ret = request_firmware(&fw, name, dev);
if (ret) {
dev_info(dev, "fw image %s not available(%d)\n",
name, ret);
return ret;
}
}
hsw_sst_fw = sst_fw_new(dsp, fw, hsw);
if (hsw_sst_fw == NULL) {
dev_err(dev, "error: failed to load firmware\n");
ret = -ENOMEM;
goto out;
}
module = sst_module_get_from_id(dsp, module_id);
if (module == NULL) {
dev_err(dev, "error: no module %d in firmware %s\n",
module_id, name);
}
} else
dev_info(dev, "module %d (%s) already loaded\n",
module_id, name);
out:
if (fw && module_id != SST_HSW_MODULE_BASE_FW)
release_firmware(fw);
return ret;
}
int sst_hsw_module_enable(struct sst_hsw *hsw,
u32 module_id, u32 instance_id)
{
int ret;
u32 header = 0;
struct sst_hsw_ipc_module_config config;
struct sst_module *module;
struct sst_module_runtime *runtime;
struct device *dev = hsw->dev;
struct sst_dsp *dsp = hsw->dsp;
if (!sst_hsw_is_module_loaded(hsw, module_id)) {
dev_dbg(dev, "module %d not loaded\n", module_id);
return 0;
}
if (sst_hsw_is_module_active(hsw, module_id)) {
dev_info(dev, "module %d already enabled\n", module_id);
return 0;
}
module = sst_module_get_from_id(dsp, module_id);
if (module == NULL) {
dev_err(dev, "module %d not valid\n", module_id);
return -ENXIO;
}
runtime = sst_module_runtime_get_from_id(module, module_id);
if (runtime == NULL) {
dev_err(dev, "runtime %d not valid", module_id);
return -ENXIO;
}
header = IPC_GLB_TYPE(IPC_GLB_MODULE_OPERATION) |
IPC_MODULE_OPERATION(IPC_MODULE_ENABLE) |
IPC_MODULE_ID(module_id);
dev_dbg(dev, "module enable header: %x\n", header);
config.map.module_entries_count = 1;
config.map.module_entries[0].module_id = module->id;
config.map.module_entries[0].entry_point = module->entry;
config.persistent_mem.offset =
sst_dsp_get_offset(dsp,
runtime->persistent_offset, SST_MEM_DRAM);
config.persistent_mem.size = module->persistent_size;
config.scratch_mem.offset =
sst_dsp_get_offset(dsp,
dsp->scratch_offset, SST_MEM_DRAM);
config.scratch_mem.size = module->scratch_size;
dev_dbg(dev, "mod %d enable p:%d @ %x, s:%d @ %x, ep: %x",
config.map.module_entries[0].module_id,
config.persistent_mem.size,
config.persistent_mem.offset,
config.scratch_mem.size, config.scratch_mem.offset,
config.map.module_entries[0].entry_point);
ret = sst_ipc_tx_message_wait(&hsw->ipc, header,
&config, sizeof(config), NULL, 0);
if (ret < 0)
dev_err(dev, "ipc: module enable failed - %d\n", ret);
else
module->state = SST_MODULE_STATE_ACTIVE;
return ret;
}
int sst_hsw_module_disable(struct sst_hsw *hsw,
u32 module_id, u32 instance_id)
{
int ret;
u32 header;
struct sst_module *module;
struct device *dev = hsw->dev;
struct sst_dsp *dsp = hsw->dsp;
if (!sst_hsw_is_module_loaded(hsw, module_id)) {
dev_dbg(dev, "module %d not loaded\n", module_id);
return 0;
}
if (!sst_hsw_is_module_active(hsw, module_id)) {
dev_info(dev, "module %d already disabled\n", module_id);
return 0;
}
module = sst_module_get_from_id(dsp, module_id);
if (module == NULL) {
dev_err(dev, "module %d not valid\n", module_id);
return -ENXIO;
}
header = IPC_GLB_TYPE(IPC_GLB_MODULE_OPERATION) |
IPC_MODULE_OPERATION(IPC_MODULE_DISABLE) |
IPC_MODULE_ID(module_id);
ret = sst_ipc_tx_message_wait(&hsw->ipc, header, NULL, 0, NULL, 0);
if (ret < 0)
dev_err(dev, "module disable failed - %d\n", ret);
else
module->state = SST_MODULE_STATE_INITIALIZED;
return ret;
}
int sst_hsw_module_set_param(struct sst_hsw *hsw,
u32 module_id, u32 instance_id, u32 parameter_id,
u32 param_size, char *param)
{
int ret;
unsigned char *data = NULL;
u32 header = 0;
u32 payload_size = 0, transfer_parameter_size = 0;
dma_addr_t dma_addr = 0;
struct sst_hsw_transfer_parameter *parameter;
struct device *dev = hsw->dev;
header = IPC_GLB_TYPE(IPC_GLB_MODULE_OPERATION) |
IPC_MODULE_OPERATION(IPC_MODULE_SET_PARAMETER) |
IPC_MODULE_ID(module_id);
dev_dbg(dev, "sst_hsw_module_set_param header=%x\n", header);
payload_size = param_size +
sizeof(struct sst_hsw_transfer_parameter) -
sizeof(struct sst_hsw_transfer_list);
dev_dbg(dev, "parameter size : %d\n", param_size);
dev_dbg(dev, "payload size : %d\n", payload_size);
if (payload_size <= SST_HSW_IPC_MAX_SHORT_PARAMETER_SIZE) {
dev_dbg(dev, "transfer parameter size : %d\n",
transfer_parameter_size);
transfer_parameter_size = ALIGN(payload_size, 4);
dev_dbg(dev, "transfer parameter aligned size : %d\n",
transfer_parameter_size);
parameter = kzalloc(transfer_parameter_size, GFP_KERNEL);
if (parameter == NULL)
return -ENOMEM;
memcpy(parameter->data, param, param_size);
} else {
dev_warn(dev, "transfer parameter size too large!");
return 0;
}
parameter->parameter_id = parameter_id;
parameter->data_size = param_size;
ret = sst_ipc_tx_message_wait(&hsw->ipc, header,
parameter, transfer_parameter_size , NULL, 0);
if (ret < 0)
dev_err(dev, "ipc: module set parameter failed - %d\n", ret);
kfree(parameter);
if (data)
dma_free_coherent(hsw->dsp->dma_dev,
param_size, (void *)data, dma_addr);
return ret;
}
static void hsw_tx_msg(struct sst_generic_ipc *ipc, struct ipc_message *msg)
{
sst_dsp_outbox_write(ipc->dsp, msg->tx_data, msg->tx_size);
sst_dsp_ipc_msg_tx(ipc->dsp, msg->header);
}
static void hsw_shim_dbg(struct sst_generic_ipc *ipc, const char *text)
{
struct sst_dsp *sst = ipc->dsp;
u32 isr, ipcd, imrx, ipcx;
ipcx = sst_dsp_shim_read_unlocked(sst, SST_IPCX);
isr = sst_dsp_shim_read_unlocked(sst, SST_ISRX);
ipcd = sst_dsp_shim_read_unlocked(sst, SST_IPCD);
imrx = sst_dsp_shim_read_unlocked(sst, SST_IMRX);
dev_err(ipc->dev,
"ipc: --%s-- ipcx 0x%8.8x isr 0x%8.8x ipcd 0x%8.8x imrx 0x%8.8x\n",
text, ipcx, isr, ipcd, imrx);
}
static void hsw_tx_data_copy(struct ipc_message *msg, char *tx_data,
size_t tx_size)
{
memcpy(msg->tx_data, tx_data, tx_size);
}
static u64 hsw_reply_msg_match(u64 header, u64 *mask)
{
header &= ~(IPC_STATUS_MASK | IPC_GLB_REPLY_MASK);
*mask = (u64)-1;
return header;
}
static bool hsw_is_dsp_busy(struct sst_dsp *dsp)
{
u64 ipcx;
ipcx = sst_dsp_shim_read_unlocked(dsp, SST_IPCX);
return (ipcx & (SST_IPCX_BUSY | SST_IPCX_DONE));
}
int sst_hsw_dsp_init(struct device *dev, struct sst_pdata *pdata)
{
struct sst_hsw_ipc_fw_version version;
struct sst_hsw *hsw;
struct sst_generic_ipc *ipc;
int ret;
dev_dbg(dev, "initialising Audio DSP IPC\n");
hsw = devm_kzalloc(dev, sizeof(*hsw), GFP_KERNEL);
if (hsw == NULL)
return -ENOMEM;
hsw->dev = dev;
ipc = &hsw->ipc;
ipc->dev = dev;
ipc->ops.tx_msg = hsw_tx_msg;
ipc->ops.shim_dbg = hsw_shim_dbg;
ipc->ops.tx_data_copy = hsw_tx_data_copy;
ipc->ops.reply_msg_match = hsw_reply_msg_match;
ipc->ops.is_dsp_busy = hsw_is_dsp_busy;
ipc->tx_data_max_size = IPC_MAX_MAILBOX_BYTES;
ipc->rx_data_max_size = IPC_MAX_MAILBOX_BYTES;
ret = sst_ipc_init(ipc);
if (ret != 0)
goto ipc_init_err;
INIT_LIST_HEAD(&hsw->stream_list);
init_waitqueue_head(&hsw->boot_wait);
hsw_dev.thread_context = hsw;
hsw->dsp = sst_dsp_new(dev, &hsw_dev, pdata);
if (hsw->dsp == NULL) {
ret = -ENODEV;
goto dsp_new_err;
}
ipc->dsp = hsw->dsp;
hsw->dx_context = dma_alloc_coherent(hsw->dsp->dma_dev,
SST_HSW_DX_CONTEXT_SIZE, &hsw->dx_context_paddr, GFP_KERNEL);
if (hsw->dx_context == NULL) {
ret = -ENOMEM;
goto dma_err;
}
sst_dsp_reset(hsw->dsp);
ret = sst_hsw_module_load(hsw, SST_HSW_MODULE_BASE_FW, 0, "Base");
if (ret < 0)
goto fw_err;
sst_hsw_module_load(hsw, SST_HSW_MODULE_WAVES, 0, "intel/IntcPP01.bin");
ret = sst_block_alloc_scratch(hsw->dsp);
if (ret < 0)
goto boot_err;
sst_hsw_reset_param_buf(hsw);
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
sst_hsw_init_module_state(hsw);
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
sst_fw_free_all(hsw->dsp);
fw_err:
dma_free_coherent(hsw->dsp->dma_dev, SST_HSW_DX_CONTEXT_SIZE,
hsw->dx_context, hsw->dx_context_paddr);
dma_err:
sst_dsp_free(hsw->dsp);
dsp_new_err:
sst_ipc_fini(ipc);
ipc_init_err:
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
sst_ipc_fini(&hsw->ipc);
}
