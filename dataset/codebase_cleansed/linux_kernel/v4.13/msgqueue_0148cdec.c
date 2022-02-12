static struct nvkm_msgqueue_queue *
msgqueue_0148cdec_cmd_queue(struct nvkm_msgqueue *queue,
enum msgqueue_msg_priority priority)
{
struct msgqueue_0148cdec *priv = msgqueue_0148cdec(queue);
return &priv->queue[MSGQUEUE_0148CDEC_COMMAND_QUEUE];
}
static void
msgqueue_0148cdec_process_msgs(struct nvkm_msgqueue *queue)
{
struct msgqueue_0148cdec *priv = msgqueue_0148cdec(queue);
struct nvkm_msgqueue_queue *q_queue =
&priv->queue[MSGQUEUE_0148CDEC_MESSAGE_QUEUE];
nvkm_msgqueue_process_msgs(&priv->base, q_queue);
}
static void
init_gen_cmdline(struct nvkm_msgqueue *queue, void *buf)
{
struct {
u32 freq_hz;
u32 falc_trace_size;
u32 falc_trace_dma_base;
u32 falc_trace_dma_idx;
bool secure_mode;
} *args = buf;
args->secure_mode = false;
}
static int
init_callback(struct nvkm_msgqueue *_queue, struct nvkm_msgqueue_hdr *hdr)
{
struct msgqueue_0148cdec *priv = msgqueue_0148cdec(_queue);
struct {
struct nvkm_msgqueue_msg base;
u8 num_queues;
u16 os_debug_entry_point;
struct {
u32 offset;
u16 size;
u8 index;
u8 id;
} queue_info[MSGQUEUE_0148CDEC_NUM_QUEUES];
u16 sw_managed_area_offset;
u16 sw_managed_area_size;
} *init = (void *)hdr;
const struct nvkm_subdev *subdev = _queue->falcon->owner;
int i;
if (init->base.hdr.unit_id != MSGQUEUE_0148CDEC_UNIT_INIT) {
nvkm_error(subdev, "expected message from init unit\n");
return -EINVAL;
}
if (init->base.msg_type != INIT_MSG_INIT) {
nvkm_error(subdev, "expected SEC init msg\n");
return -EINVAL;
}
for (i = 0; i < MSGQUEUE_0148CDEC_NUM_QUEUES; i++) {
u8 id = init->queue_info[i].id;
struct nvkm_msgqueue_queue *queue = &priv->queue[id];
mutex_init(&queue->mutex);
queue->index = init->queue_info[i].index;
queue->offset = init->queue_info[i].offset;
queue->size = init->queue_info[i].size;
if (id == MSGQUEUE_0148CDEC_MESSAGE_QUEUE) {
queue->head_reg = 0xa30 + (queue->index * 8);
queue->tail_reg = 0xa34 + (queue->index * 8);
} else {
queue->head_reg = 0xa00 + (queue->index * 8);
queue->tail_reg = 0xa04 + (queue->index * 8);
}
nvkm_debug(subdev,
"queue %d: index %d, offset 0x%08x, size 0x%08x\n",
id, queue->index, queue->offset, queue->size);
}
complete_all(&_queue->init_done);
return 0;
}
static void
acr_boot_falcon_callback(struct nvkm_msgqueue *priv,
struct nvkm_msgqueue_hdr *hdr)
{
struct acr_bootstrap_falcon_msg {
struct nvkm_msgqueue_msg base;
u32 error_code;
u32 falcon_id;
} *msg = (void *)hdr;
const struct nvkm_subdev *subdev = priv->falcon->owner;
u32 falcon_id = msg->falcon_id;
if (msg->error_code) {
nvkm_error(subdev, "in bootstrap falcon callback:\n");
nvkm_error(subdev, "expected error code 0x%x\n",
msg->error_code);
return;
}
if (falcon_id >= NVKM_SECBOOT_FALCON_END) {
nvkm_error(subdev, "in bootstrap falcon callback:\n");
nvkm_error(subdev, "invalid falcon ID 0x%x\n", falcon_id);
return;
}
nvkm_debug(subdev, "%s booted\n", nvkm_secboot_falcon_name[falcon_id]);
}
static int
acr_boot_falcon(struct nvkm_msgqueue *priv, enum nvkm_secboot_falcon falcon)
{
DECLARE_COMPLETION_ONSTACK(completed);
struct {
struct nvkm_msgqueue_hdr hdr;
u8 cmd_type;
u32 flags;
u32 falcon_id;
} cmd;
memset(&cmd, 0, sizeof(cmd));
cmd.hdr.unit_id = MSGQUEUE_0148CDEC_UNIT_ACR;
cmd.hdr.size = sizeof(cmd);
cmd.cmd_type = ACR_CMD_BOOTSTRAP_FALCON;
cmd.flags = ACR_CMD_BOOTSTRAP_FALCON_FLAGS_RESET_YES;
cmd.falcon_id = falcon;
nvkm_msgqueue_post(priv, MSGQUEUE_MSG_PRIORITY_HIGH, &cmd.hdr,
acr_boot_falcon_callback, &completed, true);
if (!wait_for_completion_timeout(&completed, msecs_to_jiffies(1000)))
return -ETIMEDOUT;
return 0;
}
static void
msgqueue_0148cdec_dtor(struct nvkm_msgqueue *queue)
{
kfree(msgqueue_0148cdec(queue));
}
int
msgqueue_0148cdec_new(struct nvkm_falcon *falcon, const struct nvkm_secboot *sb,
struct nvkm_msgqueue **queue)
{
struct msgqueue_0148cdec *ret;
ret = kzalloc(sizeof(*ret), GFP_KERNEL);
if (!ret)
return -ENOMEM;
*queue = &ret->base;
nvkm_msgqueue_ctor(&msgqueue_0148cdec_func, falcon, &ret->base);
return 0;
}
