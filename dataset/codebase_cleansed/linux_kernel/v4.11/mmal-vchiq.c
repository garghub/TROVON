static struct mmal_msg_context *get_msg_context(struct vchiq_mmal_instance
*instance)
{
struct mmal_msg_context *msg_context;
msg_context = kmalloc(sizeof(*msg_context), GFP_KERNEL);
memset(msg_context, 0, sizeof(*msg_context));
return msg_context;
}
static void release_msg_context(struct mmal_msg_context *msg_context)
{
kfree(msg_context);
}
static void event_to_host_cb(struct vchiq_mmal_instance *instance,
struct mmal_msg *msg, u32 msg_len)
{
pr_debug("unhandled event\n");
pr_debug("component:%p port type:%d num:%d cmd:0x%x length:%d\n",
msg->u.event_to_host.client_component,
msg->u.event_to_host.port_type,
msg->u.event_to_host.port_num,
msg->u.event_to_host.cmd, msg->u.event_to_host.length);
}
static void buffer_work_cb(struct work_struct *work)
{
struct mmal_msg_context *msg_context = (struct mmal_msg_context *)work;
msg_context->u.bulk.port->buffer_cb(msg_context->u.bulk.instance,
msg_context->u.bulk.port,
msg_context->u.bulk.status,
msg_context->u.bulk.buffer,
msg_context->u.bulk.buffer_used,
msg_context->u.bulk.mmal_flags,
msg_context->u.bulk.dts,
msg_context->u.bulk.pts);
release_msg_context(msg_context);
}
static int bulk_receive(struct vchiq_mmal_instance *instance,
struct mmal_msg *msg,
struct mmal_msg_context *msg_context)
{
unsigned long rd_len;
unsigned long flags = 0;
int ret;
ret = mutex_lock_interruptible(&instance->bulk_mutex);
if (ret != 0)
return ret;
rd_len = msg->u.buffer_from_host.buffer_header.length;
spin_lock_irqsave(&msg_context->u.bulk.port->slock, flags);
if (list_empty(&msg_context->u.bulk.port->buffers)) {
spin_unlock_irqrestore(&msg_context->u.bulk.port->slock, flags);
pr_err("buffer list empty trying to submit bulk receive\n");
mutex_unlock(&instance->bulk_mutex);
return -EINVAL;
}
msg_context->u.bulk.buffer =
list_entry(msg_context->u.bulk.port->buffers.next,
struct mmal_buffer, list);
list_del(&msg_context->u.bulk.buffer->list);
spin_unlock_irqrestore(&msg_context->u.bulk.port->slock, flags);
if (rd_len > msg_context->u.bulk.buffer->buffer_size) {
rd_len = msg_context->u.bulk.buffer->buffer_size;
pr_warn("short read as not enough receive buffer space\n");
}
msg_context->u.bulk.buffer_used = rd_len;
msg_context->u.bulk.mmal_flags =
msg->u.buffer_from_host.buffer_header.flags;
msg_context->u.bulk.dts = msg->u.buffer_from_host.buffer_header.dts;
msg_context->u.bulk.pts = msg->u.buffer_from_host.buffer_header.pts;
__cpuc_flush_dcache_area(msg_context->u.bulk.buffer->buffer, rd_len);
vchi_service_use(instance->handle);
ret = vchi_bulk_queue_receive(instance->handle,
msg_context->u.bulk.buffer->buffer,
(rd_len + 3) & ~3,
VCHI_FLAGS_CALLBACK_WHEN_OP_COMPLETE |
VCHI_FLAGS_BLOCK_UNTIL_QUEUED,
msg_context);
vchi_service_release(instance->handle);
if (ret != 0) {
mutex_unlock(&instance->bulk_mutex);
}
return ret;
}
static int dummy_bulk_receive(struct vchiq_mmal_instance *instance,
struct mmal_msg_context *msg_context)
{
int ret;
ret = mutex_lock_interruptible(&instance->bulk_mutex);
if (ret != 0)
return ret;
msg_context->u.bulk.buffer_used = 0;
vchi_service_use(instance->handle);
ret = vchi_bulk_queue_receive(instance->handle,
instance->bulk_scratch,
8,
VCHI_FLAGS_CALLBACK_WHEN_OP_COMPLETE |
VCHI_FLAGS_BLOCK_UNTIL_QUEUED,
msg_context);
vchi_service_release(instance->handle);
if (ret != 0) {
mutex_unlock(&instance->bulk_mutex);
}
return ret;
}
static int inline_receive(struct vchiq_mmal_instance *instance,
struct mmal_msg *msg,
struct mmal_msg_context *msg_context)
{
unsigned long flags = 0;
spin_lock_irqsave(&msg_context->u.bulk.port->slock, flags);
if (list_empty(&msg_context->u.bulk.port->buffers)) {
spin_unlock_irqrestore(&msg_context->u.bulk.port->slock, flags);
pr_err("buffer list empty trying to receive inline\n");
return -EINVAL;
}
msg_context->u.bulk.buffer =
list_entry(msg_context->u.bulk.port->buffers.next,
struct mmal_buffer, list);
list_del(&msg_context->u.bulk.buffer->list);
spin_unlock_irqrestore(&msg_context->u.bulk.port->slock, flags);
memcpy(msg_context->u.bulk.buffer->buffer,
msg->u.buffer_from_host.short_data,
msg->u.buffer_from_host.payload_in_message);
msg_context->u.bulk.buffer_used =
msg->u.buffer_from_host.payload_in_message;
return 0;
}
static int
buffer_from_host(struct vchiq_mmal_instance *instance,
struct vchiq_mmal_port *port, struct mmal_buffer *buf)
{
struct mmal_msg_context *msg_context;
struct mmal_msg m;
int ret;
pr_debug("instance:%p buffer:%p\n", instance->handle, buf);
if (mutex_lock_interruptible(&instance->bulk_mutex))
return -EINTR;
msg_context = get_msg_context(instance);
if (!msg_context) {
ret = -ENOMEM;
goto unlock;
}
msg_context->u.bulk.instance = instance;
msg_context->u.bulk.port = port;
msg_context->u.bulk.buffer = NULL;
msg_context->u.bulk.buffer_used = 0;
INIT_WORK(&msg_context->u.bulk.work, buffer_work_cb);
memset(&m, 0xbc, sizeof(m));
m.h.type = MMAL_MSG_TYPE_BUFFER_FROM_HOST;
m.h.magic = MMAL_MAGIC;
m.h.context = msg_context;
m.h.status = 0;
m.u.buffer_from_host.drvbuf.magic = MMAL_MAGIC;
m.u.buffer_from_host.drvbuf.component_handle = port->component->handle;
m.u.buffer_from_host.drvbuf.port_handle = port->handle;
m.u.buffer_from_host.drvbuf.client_context = msg_context;
m.u.buffer_from_host.buffer_header.cmd = 0;
m.u.buffer_from_host.buffer_header.data = buf->buffer;
m.u.buffer_from_host.buffer_header.alloc_size = buf->buffer_size;
m.u.buffer_from_host.buffer_header.length = 0;
m.u.buffer_from_host.buffer_header.offset = 0;
m.u.buffer_from_host.buffer_header.flags = 0;
m.u.buffer_from_host.buffer_header.pts = MMAL_TIME_UNKNOWN;
m.u.buffer_from_host.buffer_header.dts = MMAL_TIME_UNKNOWN;
memset(&m.u.buffer_from_host.buffer_header_type_specific, 0,
sizeof(m.u.buffer_from_host.buffer_header_type_specific));
m.u.buffer_from_host.payload_in_message = 0;
vchi_service_use(instance->handle);
ret = vchi_queue_kernel_message(instance->handle,
&m,
sizeof(struct mmal_msg_header) +
sizeof(m.u.buffer_from_host));
if (ret != 0) {
release_msg_context(msg_context);
}
vchi_service_release(instance->handle);
unlock:
mutex_unlock(&instance->bulk_mutex);
return ret;
}
static int port_buffer_from_host(struct vchiq_mmal_instance *instance,
struct vchiq_mmal_port *port)
{
int ret;
struct mmal_buffer *buf;
unsigned long flags = 0;
if (!port->enabled)
return -EINVAL;
spin_lock_irqsave(&port->slock, flags);
if (list_empty(&port->buffers)) {
port->buffer_underflow++;
spin_unlock_irqrestore(&port->slock, flags);
return -ENOSPC;
}
buf = list_entry(port->buffers.next, struct mmal_buffer, list);
spin_unlock_irqrestore(&port->slock, flags);
ret = buffer_from_host(instance, port, buf);
if (ret) {
pr_err("adding buffer header failed\n");
}
return ret;
}
static void buffer_to_host_cb(struct vchiq_mmal_instance *instance,
struct mmal_msg *msg, u32 msg_len)
{
struct mmal_msg_context *msg_context;
pr_debug("buffer_to_host_cb: instance:%p msg:%p msg_len:%d\n",
instance, msg, msg_len);
if (msg->u.buffer_from_host.drvbuf.magic == MMAL_MAGIC) {
msg_context = msg->u.buffer_from_host.drvbuf.client_context;
} else {
pr_err("MMAL_MSG_TYPE_BUFFER_TO_HOST with bad magic\n");
return;
}
if (msg->h.status != MMAL_MSG_STATUS_SUCCESS) {
pr_warn("error %d in reply\n", msg->h.status);
msg_context->u.bulk.status = msg->h.status;
} else if (msg->u.buffer_from_host.buffer_header.length == 0) {
if (msg->u.buffer_from_host.buffer_header.flags &
MMAL_BUFFER_HEADER_FLAG_EOS) {
msg_context->u.bulk.status =
dummy_bulk_receive(instance, msg_context);
if (msg_context->u.bulk.status == 0)
return;
} else {
msg_context->u.bulk.status = 0;
msg_context->u.bulk.buffer_used = 0;
}
} else if (msg->u.buffer_from_host.payload_in_message == 0) {
msg_context->u.bulk.status =
bulk_receive(instance, msg, msg_context);
if (msg_context->u.bulk.status == 0)
return;
pr_err("error %d on bulk submission\n",
msg_context->u.bulk.status);
} else if (msg->u.buffer_from_host.payload_in_message <=
MMAL_VC_SHORT_DATA) {
msg_context->u.bulk.status = inline_receive(instance, msg,
msg_context);
} else {
pr_err("message with invalid short payload\n");
msg_context->u.bulk.status = -EINVAL;
msg_context->u.bulk.buffer_used =
msg->u.buffer_from_host.payload_in_message;
}
port_buffer_from_host(instance, msg_context->u.bulk.port);
schedule_work(&msg_context->u.bulk.work);
}
static void bulk_receive_cb(struct vchiq_mmal_instance *instance,
struct mmal_msg_context *msg_context)
{
mutex_unlock(&msg_context->u.bulk.instance->bulk_mutex);
port_buffer_from_host(msg_context->u.bulk.instance,
msg_context->u.bulk.port);
msg_context->u.bulk.status = 0;
schedule_work(&msg_context->u.bulk.work);
}
static void bulk_abort_cb(struct vchiq_mmal_instance *instance,
struct mmal_msg_context *msg_context)
{
pr_err("%s: bulk ABORTED msg_context:%p\n", __func__, msg_context);
mutex_unlock(&msg_context->u.bulk.instance->bulk_mutex);
port_buffer_from_host(msg_context->u.bulk.instance,
msg_context->u.bulk.port);
msg_context->u.bulk.status = -EINTR;
schedule_work(&msg_context->u.bulk.work);
}
static void service_callback(void *param,
const VCHI_CALLBACK_REASON_T reason,
void *bulk_ctx)
{
struct vchiq_mmal_instance *instance = param;
int status;
u32 msg_len;
struct mmal_msg *msg;
VCHI_HELD_MSG_T msg_handle;
if (!instance) {
pr_err("Message callback passed NULL instance\n");
return;
}
switch (reason) {
case VCHI_CALLBACK_MSG_AVAILABLE:
status = vchi_msg_hold(instance->handle, (void **)&msg,
&msg_len, VCHI_FLAGS_NONE, &msg_handle);
if (status) {
pr_err("Unable to dequeue a message (%d)\n", status);
break;
}
DBG_DUMP_MSG(msg, msg_len, "<<< reply message");
switch (msg->h.type) {
case MMAL_MSG_TYPE_BUFFER_FROM_HOST:
vchi_held_msg_release(&msg_handle);
break;
case MMAL_MSG_TYPE_EVENT_TO_HOST:
event_to_host_cb(instance, msg, msg_len);
vchi_held_msg_release(&msg_handle);
break;
case MMAL_MSG_TYPE_BUFFER_TO_HOST:
buffer_to_host_cb(instance, msg, msg_len);
vchi_held_msg_release(&msg_handle);
break;
default:
if (msg->h.context == NULL) {
pr_err("received message context was null!\n");
vchi_held_msg_release(&msg_handle);
break;
}
msg->h.context->u.sync.msg_handle = msg_handle;
msg->h.context->u.sync.msg = msg;
msg->h.context->u.sync.msg_len = msg_len;
complete(&msg->h.context->u.sync.cmplt);
break;
}
break;
case VCHI_CALLBACK_BULK_RECEIVED:
bulk_receive_cb(instance, bulk_ctx);
break;
case VCHI_CALLBACK_BULK_RECEIVE_ABORTED:
bulk_abort_cb(instance, bulk_ctx);
break;
case VCHI_CALLBACK_SERVICE_CLOSED:
break;
default:
pr_err("Received unhandled message reason %d\n", reason);
break;
}
}
static int send_synchronous_mmal_msg(struct vchiq_mmal_instance *instance,
struct mmal_msg *msg,
unsigned int payload_len,
struct mmal_msg **msg_out,
VCHI_HELD_MSG_T *msg_handle_out)
{
struct mmal_msg_context msg_context;
int ret;
if (payload_len >
(MMAL_MSG_MAX_SIZE - sizeof(struct mmal_msg_header))) {
pr_err("payload length %d exceeds max:%d\n", payload_len,
(MMAL_MSG_MAX_SIZE - sizeof(struct mmal_msg_header)));
return -EINVAL;
}
init_completion(&msg_context.u.sync.cmplt);
msg->h.magic = MMAL_MAGIC;
msg->h.context = &msg_context;
msg->h.status = 0;
DBG_DUMP_MSG(msg, (sizeof(struct mmal_msg_header) + payload_len),
">>> sync message");
vchi_service_use(instance->handle);
ret = vchi_queue_kernel_message(instance->handle,
msg,
sizeof(struct mmal_msg_header) +
payload_len);
vchi_service_release(instance->handle);
if (ret) {
pr_err("error %d queuing message\n", ret);
return ret;
}
ret = wait_for_completion_timeout(&msg_context.u.sync.cmplt, 3 * HZ);
if (ret <= 0) {
pr_err("error %d waiting for sync completion\n", ret);
if (ret == 0)
ret = -ETIME;
return ret;
}
*msg_out = msg_context.u.sync.msg;
*msg_handle_out = msg_context.u.sync.msg_handle;
return 0;
}
static void dump_port_info(struct vchiq_mmal_port *port)
{
pr_debug("port handle:0x%x enabled:%d\n", port->handle, port->enabled);
pr_debug("buffer minimum num:%d size:%d align:%d\n",
port->minimum_buffer.num,
port->minimum_buffer.size, port->minimum_buffer.alignment);
pr_debug("buffer recommended num:%d size:%d align:%d\n",
port->recommended_buffer.num,
port->recommended_buffer.size,
port->recommended_buffer.alignment);
pr_debug("buffer current values num:%d size:%d align:%d\n",
port->current_buffer.num,
port->current_buffer.size, port->current_buffer.alignment);
pr_debug("elementry stream: type:%d encoding:0x%x variant:0x%x\n",
port->format.type,
port->format.encoding, port->format.encoding_variant);
pr_debug(" bitrate:%d flags:0x%x\n",
port->format.bitrate, port->format.flags);
if (port->format.type == MMAL_ES_TYPE_VIDEO) {
pr_debug
("es video format: width:%d height:%d colourspace:0x%x\n",
port->es.video.width, port->es.video.height,
port->es.video.color_space);
pr_debug(" : crop xywh %d,%d,%d,%d\n",
port->es.video.crop.x,
port->es.video.crop.y,
port->es.video.crop.width, port->es.video.crop.height);
pr_debug(" : framerate %d/%d aspect %d/%d\n",
port->es.video.frame_rate.num,
port->es.video.frame_rate.den,
port->es.video.par.num, port->es.video.par.den);
}
}
static void port_to_mmal_msg(struct vchiq_mmal_port *port, struct mmal_port *p)
{
p->type = port->type;
p->index = port->index;
p->index_all = 0;
p->is_enabled = port->enabled;
p->buffer_num_min = port->minimum_buffer.num;
p->buffer_size_min = port->minimum_buffer.size;
p->buffer_alignment_min = port->minimum_buffer.alignment;
p->buffer_num_recommended = port->recommended_buffer.num;
p->buffer_size_recommended = port->recommended_buffer.size;
p->buffer_num = port->current_buffer.num;
p->buffer_size = port->current_buffer.size;
p->userdata = port;
}
static int port_info_set(struct vchiq_mmal_instance *instance,
struct vchiq_mmal_port *port)
{
int ret;
struct mmal_msg m;
struct mmal_msg *rmsg;
VCHI_HELD_MSG_T rmsg_handle;
pr_debug("setting port info port %p\n", port);
if (!port)
return -1;
dump_port_info(port);
m.h.type = MMAL_MSG_TYPE_PORT_INFO_SET;
m.u.port_info_set.component_handle = port->component->handle;
m.u.port_info_set.port_type = port->type;
m.u.port_info_set.port_index = port->index;
port_to_mmal_msg(port, &m.u.port_info_set.port);
m.u.port_info_set.format.type = port->format.type;
m.u.port_info_set.format.encoding = port->format.encoding;
m.u.port_info_set.format.encoding_variant =
port->format.encoding_variant;
m.u.port_info_set.format.bitrate = port->format.bitrate;
m.u.port_info_set.format.flags = port->format.flags;
memcpy(&m.u.port_info_set.es, &port->es,
sizeof(union mmal_es_specific_format));
m.u.port_info_set.format.extradata_size = port->format.extradata_size;
memcpy(&m.u.port_info_set.extradata, port->format.extradata,
port->format.extradata_size);
ret = send_synchronous_mmal_msg(instance, &m,
sizeof(m.u.port_info_set),
&rmsg, &rmsg_handle);
if (ret)
return ret;
if (rmsg->h.type != MMAL_MSG_TYPE_PORT_INFO_SET) {
ret = -EINVAL;
goto release_msg;
}
ret = -rmsg->u.port_info_get_reply.status;
pr_debug("%s:result:%d component:0x%x port:%d\n", __func__, ret,
port->component->handle, port->handle);
release_msg:
vchi_held_msg_release(&rmsg_handle);
return ret;
}
static int port_info_get(struct vchiq_mmal_instance *instance,
struct vchiq_mmal_port *port)
{
int ret;
struct mmal_msg m;
struct mmal_msg *rmsg;
VCHI_HELD_MSG_T rmsg_handle;
m.h.type = MMAL_MSG_TYPE_PORT_INFO_GET;
m.u.port_info_get.component_handle = port->component->handle;
m.u.port_info_get.port_type = port->type;
m.u.port_info_get.index = port->index;
ret = send_synchronous_mmal_msg(instance, &m,
sizeof(m.u.port_info_get),
&rmsg, &rmsg_handle);
if (ret)
return ret;
if (rmsg->h.type != MMAL_MSG_TYPE_PORT_INFO_GET) {
ret = -EINVAL;
goto release_msg;
}
ret = -rmsg->u.port_info_get_reply.status;
if (ret != MMAL_MSG_STATUS_SUCCESS)
goto release_msg;
if (rmsg->u.port_info_get_reply.port.is_enabled == 0)
port->enabled = false;
else
port->enabled = true;
port->handle = rmsg->u.port_info_get_reply.port_handle;
port->type = rmsg->u.port_info_get_reply.port_type;
port->index = rmsg->u.port_info_get_reply.port_index;
port->minimum_buffer.num =
rmsg->u.port_info_get_reply.port.buffer_num_min;
port->minimum_buffer.size =
rmsg->u.port_info_get_reply.port.buffer_size_min;
port->minimum_buffer.alignment =
rmsg->u.port_info_get_reply.port.buffer_alignment_min;
port->recommended_buffer.alignment =
rmsg->u.port_info_get_reply.port.buffer_alignment_min;
port->recommended_buffer.num =
rmsg->u.port_info_get_reply.port.buffer_num_recommended;
port->current_buffer.num = rmsg->u.port_info_get_reply.port.buffer_num;
port->current_buffer.size =
rmsg->u.port_info_get_reply.port.buffer_size;
port->format.type = rmsg->u.port_info_get_reply.format.type;
port->format.encoding = rmsg->u.port_info_get_reply.format.encoding;
port->format.encoding_variant =
rmsg->u.port_info_get_reply.format.encoding_variant;
port->format.bitrate = rmsg->u.port_info_get_reply.format.bitrate;
port->format.flags = rmsg->u.port_info_get_reply.format.flags;
memcpy(&port->es,
&rmsg->u.port_info_get_reply.es,
sizeof(union mmal_es_specific_format));
port->format.es = &port->es;
port->format.extradata_size =
rmsg->u.port_info_get_reply.format.extradata_size;
memcpy(port->format.extradata,
rmsg->u.port_info_get_reply.extradata,
port->format.extradata_size);
pr_debug("received port info\n");
dump_port_info(port);
release_msg:
pr_debug("%s:result:%d component:0x%x port:%d\n",
__func__, ret, port->component->handle, port->handle);
vchi_held_msg_release(&rmsg_handle);
return ret;
}
static int create_component(struct vchiq_mmal_instance *instance,
struct vchiq_mmal_component *component,
const char *name)
{
int ret;
struct mmal_msg m;
struct mmal_msg *rmsg;
VCHI_HELD_MSG_T rmsg_handle;
m.h.type = MMAL_MSG_TYPE_COMPONENT_CREATE;
m.u.component_create.client_component = component;
strncpy(m.u.component_create.name, name,
sizeof(m.u.component_create.name));
ret = send_synchronous_mmal_msg(instance, &m,
sizeof(m.u.component_create),
&rmsg, &rmsg_handle);
if (ret)
return ret;
if (rmsg->h.type != m.h.type) {
ret = -EINVAL;
goto release_msg;
}
ret = -rmsg->u.component_create_reply.status;
if (ret != MMAL_MSG_STATUS_SUCCESS)
goto release_msg;
component->handle = rmsg->u.component_create_reply.component_handle;
component->inputs = rmsg->u.component_create_reply.input_num;
component->outputs = rmsg->u.component_create_reply.output_num;
component->clocks = rmsg->u.component_create_reply.clock_num;
pr_debug("Component handle:0x%x in:%d out:%d clock:%d\n",
component->handle,
component->inputs, component->outputs, component->clocks);
release_msg:
vchi_held_msg_release(&rmsg_handle);
return ret;
}
static int destroy_component(struct vchiq_mmal_instance *instance,
struct vchiq_mmal_component *component)
{
int ret;
struct mmal_msg m;
struct mmal_msg *rmsg;
VCHI_HELD_MSG_T rmsg_handle;
m.h.type = MMAL_MSG_TYPE_COMPONENT_DESTROY;
m.u.component_destroy.component_handle = component->handle;
ret = send_synchronous_mmal_msg(instance, &m,
sizeof(m.u.component_destroy),
&rmsg, &rmsg_handle);
if (ret)
return ret;
if (rmsg->h.type != m.h.type) {
ret = -EINVAL;
goto release_msg;
}
ret = -rmsg->u.component_destroy_reply.status;
release_msg:
vchi_held_msg_release(&rmsg_handle);
return ret;
}
static int enable_component(struct vchiq_mmal_instance *instance,
struct vchiq_mmal_component *component)
{
int ret;
struct mmal_msg m;
struct mmal_msg *rmsg;
VCHI_HELD_MSG_T rmsg_handle;
m.h.type = MMAL_MSG_TYPE_COMPONENT_ENABLE;
m.u.component_enable.component_handle = component->handle;
ret = send_synchronous_mmal_msg(instance, &m,
sizeof(m.u.component_enable),
&rmsg, &rmsg_handle);
if (ret)
return ret;
if (rmsg->h.type != m.h.type) {
ret = -EINVAL;
goto release_msg;
}
ret = -rmsg->u.component_enable_reply.status;
release_msg:
vchi_held_msg_release(&rmsg_handle);
return ret;
}
static int disable_component(struct vchiq_mmal_instance *instance,
struct vchiq_mmal_component *component)
{
int ret;
struct mmal_msg m;
struct mmal_msg *rmsg;
VCHI_HELD_MSG_T rmsg_handle;
m.h.type = MMAL_MSG_TYPE_COMPONENT_DISABLE;
m.u.component_disable.component_handle = component->handle;
ret = send_synchronous_mmal_msg(instance, &m,
sizeof(m.u.component_disable),
&rmsg, &rmsg_handle);
if (ret)
return ret;
if (rmsg->h.type != m.h.type) {
ret = -EINVAL;
goto release_msg;
}
ret = -rmsg->u.component_disable_reply.status;
release_msg:
vchi_held_msg_release(&rmsg_handle);
return ret;
}
static int get_version(struct vchiq_mmal_instance *instance,
u32 *major_out, u32 *minor_out)
{
int ret;
struct mmal_msg m;
struct mmal_msg *rmsg;
VCHI_HELD_MSG_T rmsg_handle;
m.h.type = MMAL_MSG_TYPE_GET_VERSION;
ret = send_synchronous_mmal_msg(instance, &m,
sizeof(m.u.version),
&rmsg, &rmsg_handle);
if (ret)
return ret;
if (rmsg->h.type != m.h.type) {
ret = -EINVAL;
goto release_msg;
}
*major_out = rmsg->u.version.major;
*minor_out = rmsg->u.version.minor;
release_msg:
vchi_held_msg_release(&rmsg_handle);
return ret;
}
static int port_action_port(struct vchiq_mmal_instance *instance,
struct vchiq_mmal_port *port,
enum mmal_msg_port_action_type action_type)
{
int ret;
struct mmal_msg m;
struct mmal_msg *rmsg;
VCHI_HELD_MSG_T rmsg_handle;
m.h.type = MMAL_MSG_TYPE_PORT_ACTION;
m.u.port_action_port.component_handle = port->component->handle;
m.u.port_action_port.port_handle = port->handle;
m.u.port_action_port.action = action_type;
port_to_mmal_msg(port, &m.u.port_action_port.port);
ret = send_synchronous_mmal_msg(instance, &m,
sizeof(m.u.port_action_port),
&rmsg, &rmsg_handle);
if (ret)
return ret;
if (rmsg->h.type != MMAL_MSG_TYPE_PORT_ACTION) {
ret = -EINVAL;
goto release_msg;
}
ret = -rmsg->u.port_action_reply.status;
pr_debug("%s:result:%d component:0x%x port:%d action:%s(%d)\n",
__func__,
ret, port->component->handle, port->handle,
port_action_type_names[action_type], action_type);
release_msg:
vchi_held_msg_release(&rmsg_handle);
return ret;
}
static int port_action_handle(struct vchiq_mmal_instance *instance,
struct vchiq_mmal_port *port,
enum mmal_msg_port_action_type action_type,
u32 connect_component_handle,
u32 connect_port_handle)
{
int ret;
struct mmal_msg m;
struct mmal_msg *rmsg;
VCHI_HELD_MSG_T rmsg_handle;
m.h.type = MMAL_MSG_TYPE_PORT_ACTION;
m.u.port_action_handle.component_handle = port->component->handle;
m.u.port_action_handle.port_handle = port->handle;
m.u.port_action_handle.action = action_type;
m.u.port_action_handle.connect_component_handle =
connect_component_handle;
m.u.port_action_handle.connect_port_handle = connect_port_handle;
ret = send_synchronous_mmal_msg(instance, &m,
sizeof(m.u.port_action_handle),
&rmsg, &rmsg_handle);
if (ret)
return ret;
if (rmsg->h.type != MMAL_MSG_TYPE_PORT_ACTION) {
ret = -EINVAL;
goto release_msg;
}
ret = -rmsg->u.port_action_reply.status;
pr_debug("%s:result:%d component:0x%x port:%d action:%s(%d)" \
" connect component:0x%x connect port:%d\n",
__func__,
ret, port->component->handle, port->handle,
port_action_type_names[action_type],
action_type, connect_component_handle, connect_port_handle);
release_msg:
vchi_held_msg_release(&rmsg_handle);
return ret;
}
static int port_parameter_set(struct vchiq_mmal_instance *instance,
struct vchiq_mmal_port *port,
u32 parameter_id, void *value, u32 value_size)
{
int ret;
struct mmal_msg m;
struct mmal_msg *rmsg;
VCHI_HELD_MSG_T rmsg_handle;
m.h.type = MMAL_MSG_TYPE_PORT_PARAMETER_SET;
m.u.port_parameter_set.component_handle = port->component->handle;
m.u.port_parameter_set.port_handle = port->handle;
m.u.port_parameter_set.id = parameter_id;
m.u.port_parameter_set.size = (2 * sizeof(u32)) + value_size;
memcpy(&m.u.port_parameter_set.value, value, value_size);
ret = send_synchronous_mmal_msg(instance, &m,
(4 * sizeof(u32)) + value_size,
&rmsg, &rmsg_handle);
if (ret)
return ret;
if (rmsg->h.type != MMAL_MSG_TYPE_PORT_PARAMETER_SET) {
ret = -EINVAL;
goto release_msg;
}
ret = -rmsg->u.port_parameter_set_reply.status;
pr_debug("%s:result:%d component:0x%x port:%d parameter:%d\n",
__func__,
ret, port->component->handle, port->handle, parameter_id);
release_msg:
vchi_held_msg_release(&rmsg_handle);
return ret;
}
static int port_parameter_get(struct vchiq_mmal_instance *instance,
struct vchiq_mmal_port *port,
u32 parameter_id, void *value, u32 *value_size)
{
int ret;
struct mmal_msg m;
struct mmal_msg *rmsg;
VCHI_HELD_MSG_T rmsg_handle;
m.h.type = MMAL_MSG_TYPE_PORT_PARAMETER_GET;
m.u.port_parameter_get.component_handle = port->component->handle;
m.u.port_parameter_get.port_handle = port->handle;
m.u.port_parameter_get.id = parameter_id;
m.u.port_parameter_get.size = (2 * sizeof(u32)) + *value_size;
ret = send_synchronous_mmal_msg(instance, &m,
sizeof(struct
mmal_msg_port_parameter_get),
&rmsg, &rmsg_handle);
if (ret)
return ret;
if (rmsg->h.type != MMAL_MSG_TYPE_PORT_PARAMETER_GET) {
pr_err("Incorrect reply type %d\n", rmsg->h.type);
ret = -EINVAL;
goto release_msg;
}
ret = -rmsg->u.port_parameter_get_reply.status;
if (ret) {
memcpy(value, &rmsg->u.port_parameter_get_reply.value,
*value_size);
*value_size = rmsg->u.port_parameter_get_reply.size;
} else
memcpy(value, &rmsg->u.port_parameter_get_reply.value,
rmsg->u.port_parameter_get_reply.size);
pr_debug("%s:result:%d component:0x%x port:%d parameter:%d\n", __func__,
ret, port->component->handle, port->handle, parameter_id);
release_msg:
vchi_held_msg_release(&rmsg_handle);
return ret;
}
static int port_disable(struct vchiq_mmal_instance *instance,
struct vchiq_mmal_port *port)
{
int ret;
struct list_head *q, *buf_head;
unsigned long flags = 0;
if (!port->enabled)
return 0;
port->enabled = false;
ret = port_action_port(instance, port,
MMAL_MSG_PORT_ACTION_TYPE_DISABLE);
if (ret == 0) {
spin_lock_irqsave(&port->slock, flags);
list_for_each_safe(buf_head, q, &port->buffers) {
struct mmal_buffer *mmalbuf;
mmalbuf = list_entry(buf_head, struct mmal_buffer,
list);
list_del(buf_head);
if (port->buffer_cb)
port->buffer_cb(instance,
port, 0, mmalbuf, 0, 0,
MMAL_TIME_UNKNOWN,
MMAL_TIME_UNKNOWN);
}
spin_unlock_irqrestore(&port->slock, flags);
ret = port_info_get(instance, port);
}
return ret;
}
static int port_enable(struct vchiq_mmal_instance *instance,
struct vchiq_mmal_port *port)
{
unsigned int hdr_count;
struct list_head *buf_head;
int ret;
if (port->enabled)
return 0;
if (port->buffer_cb != NULL) {
hdr_count = 0;
list_for_each(buf_head, &port->buffers) {
hdr_count++;
}
if (hdr_count < port->current_buffer.num)
return -ENOSPC;
}
ret = port_action_port(instance, port,
MMAL_MSG_PORT_ACTION_TYPE_ENABLE);
if (ret)
goto done;
port->enabled = true;
if (port->buffer_cb) {
hdr_count = 1;
list_for_each(buf_head, &port->buffers) {
struct mmal_buffer *mmalbuf;
mmalbuf = list_entry(buf_head, struct mmal_buffer,
list);
ret = buffer_from_host(instance, port, mmalbuf);
if (ret)
goto done;
hdr_count++;
if (hdr_count > port->current_buffer.num)
break;
}
}
ret = port_info_get(instance, port);
done:
return ret;
}
int vchiq_mmal_port_set_format(struct vchiq_mmal_instance *instance,
struct vchiq_mmal_port *port)
{
int ret;
if (mutex_lock_interruptible(&instance->vchiq_mutex))
return -EINTR;
ret = port_info_set(instance, port);
if (ret)
goto release_unlock;
ret = port_info_get(instance, port);
release_unlock:
mutex_unlock(&instance->vchiq_mutex);
return ret;
}
int vchiq_mmal_port_parameter_set(struct vchiq_mmal_instance *instance,
struct vchiq_mmal_port *port,
u32 parameter, void *value, u32 value_size)
{
int ret;
if (mutex_lock_interruptible(&instance->vchiq_mutex))
return -EINTR;
ret = port_parameter_set(instance, port, parameter, value, value_size);
mutex_unlock(&instance->vchiq_mutex);
return ret;
}
int vchiq_mmal_port_parameter_get(struct vchiq_mmal_instance *instance,
struct vchiq_mmal_port *port,
u32 parameter, void *value, u32 *value_size)
{
int ret;
if (mutex_lock_interruptible(&instance->vchiq_mutex))
return -EINTR;
ret = port_parameter_get(instance, port, parameter, value, value_size);
mutex_unlock(&instance->vchiq_mutex);
return ret;
}
int vchiq_mmal_port_enable(struct vchiq_mmal_instance *instance,
struct vchiq_mmal_port *port,
vchiq_mmal_buffer_cb buffer_cb)
{
int ret;
if (mutex_lock_interruptible(&instance->vchiq_mutex))
return -EINTR;
if (port->enabled) {
ret = 0;
goto unlock;
}
port->buffer_cb = buffer_cb;
ret = port_enable(instance, port);
unlock:
mutex_unlock(&instance->vchiq_mutex);
return ret;
}
int vchiq_mmal_port_disable(struct vchiq_mmal_instance *instance,
struct vchiq_mmal_port *port)
{
int ret;
if (mutex_lock_interruptible(&instance->vchiq_mutex))
return -EINTR;
if (!port->enabled) {
mutex_unlock(&instance->vchiq_mutex);
return 0;
}
ret = port_disable(instance, port);
mutex_unlock(&instance->vchiq_mutex);
return ret;
}
int vchiq_mmal_port_connect_tunnel(struct vchiq_mmal_instance *instance,
struct vchiq_mmal_port *src,
struct vchiq_mmal_port *dst)
{
int ret;
if (mutex_lock_interruptible(&instance->vchiq_mutex))
return -EINTR;
if (src->connected != NULL) {
ret = port_disable(instance, src);
if (ret) {
pr_err("failed disabling src port(%d)\n", ret);
goto release_unlock;
}
ret = port_action_handle(instance, src,
MMAL_MSG_PORT_ACTION_TYPE_DISCONNECT,
src->connected->component->handle,
src->connected->handle);
if (ret < 0) {
pr_err("failed disconnecting src port\n");
goto release_unlock;
}
src->connected->enabled = false;
src->connected = NULL;
}
if (dst == NULL) {
ret = 0;
pr_debug("not making new connection\n");
goto release_unlock;
}
dst->format.encoding = src->format.encoding;
dst->es.video.width = src->es.video.width;
dst->es.video.height = src->es.video.height;
dst->es.video.crop.x = src->es.video.crop.x;
dst->es.video.crop.y = src->es.video.crop.y;
dst->es.video.crop.width = src->es.video.crop.width;
dst->es.video.crop.height = src->es.video.crop.height;
dst->es.video.frame_rate.num = src->es.video.frame_rate.num;
dst->es.video.frame_rate.den = src->es.video.frame_rate.den;
ret = port_info_set(instance, dst);
if (ret) {
pr_debug("setting port info failed\n");
goto release_unlock;
}
ret = port_info_get(instance, dst);
if (ret) {
pr_debug("read back port info failed\n");
goto release_unlock;
}
ret = port_action_handle(instance, src,
MMAL_MSG_PORT_ACTION_TYPE_CONNECT,
dst->component->handle, dst->handle);
if (ret < 0) {
pr_debug("connecting port %d:%d to %d:%d failed\n",
src->component->handle, src->handle,
dst->component->handle, dst->handle);
goto release_unlock;
}
src->connected = dst;
release_unlock:
mutex_unlock(&instance->vchiq_mutex);
return ret;
}
int vchiq_mmal_submit_buffer(struct vchiq_mmal_instance *instance,
struct vchiq_mmal_port *port,
struct mmal_buffer *buffer)
{
unsigned long flags = 0;
spin_lock_irqsave(&port->slock, flags);
list_add_tail(&buffer->list, &port->buffers);
spin_unlock_irqrestore(&port->slock, flags);
if (port->buffer_underflow) {
port_buffer_from_host(instance, port);
port->buffer_underflow--;
}
return 0;
}
int vchiq_mmal_component_init(struct vchiq_mmal_instance *instance,
const char *name,
struct vchiq_mmal_component **component_out)
{
int ret;
int idx;
struct vchiq_mmal_component *component;
if (mutex_lock_interruptible(&instance->vchiq_mutex))
return -EINTR;
if (instance->component_idx == VCHIQ_MMAL_MAX_COMPONENTS) {
ret = -EINVAL;
goto unlock;
}
component = &instance->component[instance->component_idx];
ret = create_component(instance, component, name);
if (ret < 0)
goto unlock;
component->control.type = MMAL_PORT_TYPE_CONTROL;
component->control.index = 0;
component->control.component = component;
spin_lock_init(&component->control.slock);
INIT_LIST_HEAD(&component->control.buffers);
ret = port_info_get(instance, &component->control);
if (ret < 0)
goto release_component;
for (idx = 0; idx < component->inputs; idx++) {
component->input[idx].type = MMAL_PORT_TYPE_INPUT;
component->input[idx].index = idx;
component->input[idx].component = component;
spin_lock_init(&component->input[idx].slock);
INIT_LIST_HEAD(&component->input[idx].buffers);
ret = port_info_get(instance, &component->input[idx]);
if (ret < 0)
goto release_component;
}
for (idx = 0; idx < component->outputs; idx++) {
component->output[idx].type = MMAL_PORT_TYPE_OUTPUT;
component->output[idx].index = idx;
component->output[idx].component = component;
spin_lock_init(&component->output[idx].slock);
INIT_LIST_HEAD(&component->output[idx].buffers);
ret = port_info_get(instance, &component->output[idx]);
if (ret < 0)
goto release_component;
}
for (idx = 0; idx < component->clocks; idx++) {
component->clock[idx].type = MMAL_PORT_TYPE_CLOCK;
component->clock[idx].index = idx;
component->clock[idx].component = component;
spin_lock_init(&component->clock[idx].slock);
INIT_LIST_HEAD(&component->clock[idx].buffers);
ret = port_info_get(instance, &component->clock[idx]);
if (ret < 0)
goto release_component;
}
instance->component_idx++;
*component_out = component;
mutex_unlock(&instance->vchiq_mutex);
return 0;
release_component:
destroy_component(instance, component);
unlock:
mutex_unlock(&instance->vchiq_mutex);
return ret;
}
int vchiq_mmal_component_finalise(struct vchiq_mmal_instance *instance,
struct vchiq_mmal_component *component)
{
int ret;
if (mutex_lock_interruptible(&instance->vchiq_mutex))
return -EINTR;
if (component->enabled)
ret = disable_component(instance, component);
ret = destroy_component(instance, component);
mutex_unlock(&instance->vchiq_mutex);
return ret;
}
int vchiq_mmal_component_enable(struct vchiq_mmal_instance *instance,
struct vchiq_mmal_component *component)
{
int ret;
if (mutex_lock_interruptible(&instance->vchiq_mutex))
return -EINTR;
if (component->enabled) {
mutex_unlock(&instance->vchiq_mutex);
return 0;
}
ret = enable_component(instance, component);
if (ret == 0)
component->enabled = true;
mutex_unlock(&instance->vchiq_mutex);
return ret;
}
int vchiq_mmal_component_disable(struct vchiq_mmal_instance *instance,
struct vchiq_mmal_component *component)
{
int ret;
if (mutex_lock_interruptible(&instance->vchiq_mutex))
return -EINTR;
if (!component->enabled) {
mutex_unlock(&instance->vchiq_mutex);
return 0;
}
ret = disable_component(instance, component);
if (ret == 0)
component->enabled = false;
mutex_unlock(&instance->vchiq_mutex);
return ret;
}
int vchiq_mmal_version(struct vchiq_mmal_instance *instance,
u32 *major_out, u32 *minor_out)
{
int ret;
if (mutex_lock_interruptible(&instance->vchiq_mutex))
return -EINTR;
ret = get_version(instance, major_out, minor_out);
mutex_unlock(&instance->vchiq_mutex);
return ret;
}
int vchiq_mmal_finalise(struct vchiq_mmal_instance *instance)
{
int status = 0;
if (instance == NULL)
return -EINVAL;
if (mutex_lock_interruptible(&instance->vchiq_mutex))
return -EINTR;
vchi_service_use(instance->handle);
status = vchi_service_close(instance->handle);
if (status != 0)
pr_err("mmal-vchiq: VCHIQ close failed");
mutex_unlock(&instance->vchiq_mutex);
vfree(instance->bulk_scratch);
kfree(instance);
return status;
}
int vchiq_mmal_init(struct vchiq_mmal_instance **out_instance)
{
int status;
struct vchiq_mmal_instance *instance;
static VCHI_CONNECTION_T *vchi_connection;
static VCHI_INSTANCE_T vchi_instance;
SERVICE_CREATION_T params = {
VCHI_VERSION_EX(VC_MMAL_VER, VC_MMAL_MIN_VER),
VC_MMAL_SERVER_NAME,
vchi_connection,
0,
0,
service_callback,
NULL,
1,
1,
0
};
BUILD_BUG_ON(sizeof(struct mmal_msg_header) != 24);
BUILD_BUG_ON(sizeof(struct mmal_msg) > MMAL_MSG_MAX_SIZE);
BUILD_BUG_ON(sizeof(struct mmal_port) != 64);
status = vchi_initialise(&vchi_instance);
if (status) {
pr_err("Failed to initialise VCHI instance (status=%d)\n",
status);
return -EIO;
}
status = vchi_connect(NULL, 0, vchi_instance);
if (status) {
pr_err("Failed to connect VCHI instance (status=%d)\n", status);
return -EIO;
}
instance = kmalloc(sizeof(*instance), GFP_KERNEL);
memset(instance, 0, sizeof(*instance));
mutex_init(&instance->vchiq_mutex);
mutex_init(&instance->bulk_mutex);
instance->bulk_scratch = vmalloc(PAGE_SIZE);
params.callback_param = instance;
status = vchi_service_open(vchi_instance, &params, &instance->handle);
if (status) {
pr_err("Failed to open VCHI service connection (status=%d)\n",
status);
goto err_close_services;
}
vchi_service_release(instance->handle);
*out_instance = instance;
return 0;
err_close_services:
vchi_service_close(instance->handle);
vfree(instance->bulk_scratch);
kfree(instance);
return -ENODEV;
}
