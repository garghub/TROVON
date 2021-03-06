int sst_get_block_stream(struct intel_sst_drv *sst_drv_ctx)
{
int i;
for (i = 0; i < MAX_ACTIVE_STREAM; i++) {
if (sst_drv_ctx->alloc_block[i].sst_id == BLOCK_UNINIT) {
sst_drv_ctx->alloc_block[i].ops_block.condition = false;
sst_drv_ctx->alloc_block[i].ops_block.ret_code = 0;
sst_drv_ctx->alloc_block[i].sst_id = 0;
break;
}
}
if (i == MAX_ACTIVE_STREAM) {
pr_err("max alloc_stream reached\n");
i = -EBUSY;
}
return i;
}
int sst_wait_interruptible(struct intel_sst_drv *sst_drv_ctx,
struct sst_block *block)
{
int retval = 0;
if (!wait_event_interruptible(sst_drv_ctx->wait_queue,
block->condition)) {
if (block->ret_code < 0) {
pr_err("stream failed %d\n", block->ret_code);
retval = -EBUSY;
} else {
pr_debug("event up\n");
retval = 0;
}
} else {
pr_err("signal interrupted\n");
retval = -EINTR;
}
return retval;
}
int sst_wait_interruptible_timeout(
struct intel_sst_drv *sst_drv_ctx,
struct sst_block *block, int timeout)
{
int retval = 0;
pr_debug("sst_wait_interruptible_timeout - waiting....\n");
if (wait_event_interruptible_timeout(sst_drv_ctx->wait_queue,
block->condition,
msecs_to_jiffies(timeout))) {
if (block->ret_code < 0)
pr_err("stream failed %d\n", block->ret_code);
else
pr_debug("event up\n");
retval = block->ret_code;
} else {
block->on = false;
pr_err("timeout occurred...\n");
retval = -EBUSY;
}
return retval;
}
int sst_wait_timeout(struct intel_sst_drv *sst_drv_ctx,
struct stream_alloc_block *block)
{
int retval = 0;
pr_debug("waiting for %x, condition %x\n",
block->sst_id, block->ops_block.condition);
if (wait_event_interruptible_timeout(sst_drv_ctx->wait_queue,
block->ops_block.condition,
msecs_to_jiffies(SST_BLOCK_TIMEOUT))) {
pr_debug("Event wake %x\n", block->ops_block.condition);
pr_debug("message ret: %d\n", block->ops_block.ret_code);
retval = block->ops_block.ret_code;
} else {
block->ops_block.on = false;
pr_err("Wait timed-out %x\n", block->ops_block.condition);
retval = -EBUSY;
}
return retval;
}
int sst_create_large_msg(struct ipc_post **arg)
{
struct ipc_post *msg;
msg = kzalloc(sizeof(struct ipc_post), GFP_ATOMIC);
if (!msg) {
pr_err("kzalloc msg failed\n");
return -ENOMEM;
}
msg->mailbox_data = kzalloc(SST_MAILBOX_SIZE, GFP_ATOMIC);
if (!msg->mailbox_data) {
kfree(msg);
pr_err("kzalloc mailbox_data failed");
return -ENOMEM;
}
*arg = msg;
return 0;
}
int sst_create_short_msg(struct ipc_post **arg)
{
struct ipc_post *msg;
msg = kzalloc(sizeof(*msg), GFP_ATOMIC);
if (!msg) {
pr_err("kzalloc msg failed\n");
return -ENOMEM;
}
msg->mailbox_data = NULL;
*arg = msg;
return 0;
}
void sst_clean_stream(struct stream_info *stream)
{
struct sst_stream_bufs *bufs = NULL, *_bufs;
stream->status = STREAM_UN_INIT;
stream->prev = STREAM_UN_INIT;
mutex_lock(&stream->lock);
list_for_each_entry_safe(bufs, _bufs, &stream->bufs, node) {
list_del(&bufs->node);
kfree(bufs);
}
mutex_unlock(&stream->lock);
if (stream->ops != STREAM_OPS_PLAYBACK_DRM)
kfree(stream->decode_ibuf);
}
void sst_wake_up_alloc_block(struct intel_sst_drv *sst_drv_ctx,
u8 sst_id, int status, void *data)
{
int i;
for (i = 0; i < MAX_ACTIVE_STREAM; i++) {
if (sst_id == sst_drv_ctx->alloc_block[i].sst_id) {
sst_drv_ctx->alloc_block[i].ops_block.condition = true;
sst_drv_ctx->alloc_block[i].ops_block.ret_code = status;
sst_drv_ctx->alloc_block[i].ops_block.data = data;
wake_up(&sst_drv_ctx->wait_queue);
break;
}
}
}
int sst_enable_rx_timeslot(int status)
{
int retval = 0;
struct ipc_post *msg = NULL;
if (sst_create_short_msg(&msg)) {
pr_err("mem allocation failed\n");
return -ENOMEM;
}
pr_debug("ipc message sending: ENABLE_RX_TIME_SLOT\n");
sst_fill_header(&msg->header, IPC_IA_ENABLE_RX_TIME_SLOT, 0, 0);
msg->header.part.data = status;
sst_drv_ctx->hs_info_blk.condition = false;
sst_drv_ctx->hs_info_blk.ret_code = 0;
sst_drv_ctx->hs_info_blk.on = true;
spin_lock(&sst_drv_ctx->list_spin_lock);
list_add_tail(&msg->node,
&sst_drv_ctx->ipc_dispatch_list);
spin_unlock(&sst_drv_ctx->list_spin_lock);
sst_post_message(&sst_drv_ctx->ipc_post_msg_wq);
retval = sst_wait_interruptible_timeout(sst_drv_ctx,
&sst_drv_ctx->hs_info_blk, SST_BLOCK_TIMEOUT);
return retval;
}
