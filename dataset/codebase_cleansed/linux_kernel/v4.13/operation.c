static int gb_operation_get_active(struct gb_operation *operation)
{
struct gb_connection *connection = operation->connection;
unsigned long flags;
spin_lock_irqsave(&connection->lock, flags);
switch (connection->state) {
case GB_CONNECTION_STATE_ENABLED:
break;
case GB_CONNECTION_STATE_ENABLED_TX:
if (gb_operation_is_incoming(operation))
goto err_unlock;
break;
case GB_CONNECTION_STATE_DISCONNECTING:
if (!gb_operation_is_core(operation))
goto err_unlock;
break;
default:
goto err_unlock;
}
if (operation->active++ == 0)
list_add_tail(&operation->links, &connection->operations);
trace_gb_operation_get_active(operation);
spin_unlock_irqrestore(&connection->lock, flags);
return 0;
err_unlock:
spin_unlock_irqrestore(&connection->lock, flags);
return -ENOTCONN;
}
static void gb_operation_put_active(struct gb_operation *operation)
{
struct gb_connection *connection = operation->connection;
unsigned long flags;
spin_lock_irqsave(&connection->lock, flags);
trace_gb_operation_put_active(operation);
if (--operation->active == 0) {
list_del(&operation->links);
if (atomic_read(&operation->waiters))
wake_up(&gb_operation_cancellation_queue);
}
spin_unlock_irqrestore(&connection->lock, flags);
}
static bool gb_operation_is_active(struct gb_operation *operation)
{
struct gb_connection *connection = operation->connection;
unsigned long flags;
bool ret;
spin_lock_irqsave(&connection->lock, flags);
ret = operation->active;
spin_unlock_irqrestore(&connection->lock, flags);
return ret;
}
static bool gb_operation_result_set(struct gb_operation *operation, int result)
{
unsigned long flags;
int prev;
if (result == -EINPROGRESS) {
spin_lock_irqsave(&gb_operations_lock, flags);
prev = operation->errno;
if (prev == -EBADR)
operation->errno = result;
else
operation->errno = -EILSEQ;
spin_unlock_irqrestore(&gb_operations_lock, flags);
WARN_ON(prev != -EBADR);
return true;
}
if (WARN_ON(result == -EBADR))
result = -EILSEQ;
spin_lock_irqsave(&gb_operations_lock, flags);
prev = operation->errno;
if (prev == -EINPROGRESS)
operation->errno = result;
spin_unlock_irqrestore(&gb_operations_lock, flags);
return prev == -EINPROGRESS;
}
int gb_operation_result(struct gb_operation *operation)
{
int result = operation->errno;
WARN_ON(result == -EBADR);
WARN_ON(result == -EINPROGRESS);
return result;
}
static struct gb_operation *
gb_operation_find_outgoing(struct gb_connection *connection, u16 operation_id)
{
struct gb_operation *operation;
unsigned long flags;
bool found = false;
spin_lock_irqsave(&connection->lock, flags);
list_for_each_entry(operation, &connection->operations, links)
if (operation->id == operation_id &&
!gb_operation_is_incoming(operation)) {
gb_operation_get(operation);
found = true;
break;
}
spin_unlock_irqrestore(&connection->lock, flags);
return found ? operation : NULL;
}
static int gb_message_send(struct gb_message *message, gfp_t gfp)
{
struct gb_connection *connection = message->operation->connection;
trace_gb_message_send(message);
return connection->hd->driver->message_send(connection->hd,
connection->hd_cport_id,
message,
gfp);
}
static void gb_message_cancel(struct gb_message *message)
{
struct gb_host_device *hd = message->operation->connection->hd;
hd->driver->message_cancel(message);
}
static void gb_operation_request_handle(struct gb_operation *operation)
{
struct gb_connection *connection = operation->connection;
int status;
int ret;
if (connection->handler) {
status = connection->handler(operation);
} else {
dev_err(&connection->hd->dev,
"%s: unexpected incoming request of type 0x%02x\n",
connection->name, operation->type);
status = -EPROTONOSUPPORT;
}
ret = gb_operation_response_send(operation, status);
if (ret) {
dev_err(&connection->hd->dev,
"%s: failed to send response %d for type 0x%02x: %d\n",
connection->name, status, operation->type, ret);
return;
}
}
static void gb_operation_work(struct work_struct *work)
{
struct gb_operation *operation;
int ret;
operation = container_of(work, struct gb_operation, work);
if (gb_operation_is_incoming(operation)) {
gb_operation_request_handle(operation);
} else {
ret = del_timer_sync(&operation->timer);
if (!ret) {
if (gb_operation_result(operation) == -ETIMEDOUT)
gb_message_cancel(operation->request);
}
operation->callback(operation);
}
gb_operation_put_active(operation);
gb_operation_put(operation);
}
static void gb_operation_timeout(unsigned long arg)
{
struct gb_operation *operation = (void *)arg;
if (gb_operation_result_set(operation, -ETIMEDOUT)) {
queue_work(gb_operation_completion_wq, &operation->work);
}
}
static void gb_operation_message_init(struct gb_host_device *hd,
struct gb_message *message, u16 operation_id,
size_t payload_size, u8 type)
{
struct gb_operation_msg_hdr *header;
header = message->buffer;
message->header = header;
message->payload = payload_size ? header + 1 : NULL;
message->payload_size = payload_size;
if (type != GB_REQUEST_TYPE_INVALID) {
u16 message_size = (u16)(sizeof(*header) + payload_size);
header->size = cpu_to_le16(message_size);
header->operation_id = 0;
header->type = type;
header->result = 0;
}
}
static struct gb_message *
gb_operation_message_alloc(struct gb_host_device *hd, u8 type,
size_t payload_size, gfp_t gfp_flags)
{
struct gb_message *message;
struct gb_operation_msg_hdr *header;
size_t message_size = payload_size + sizeof(*header);
if (message_size > hd->buffer_size_max) {
dev_warn(&hd->dev, "requested message size too big (%zu > %zu)\n",
message_size, hd->buffer_size_max);
return NULL;
}
message = kmem_cache_zalloc(gb_message_cache, gfp_flags);
if (!message)
return NULL;
message->buffer = kzalloc(message_size, gfp_flags);
if (!message->buffer)
goto err_free_message;
gb_operation_message_init(hd, message, 0, payload_size, type);
return message;
err_free_message:
kmem_cache_free(gb_message_cache, message);
return NULL;
}
static void gb_operation_message_free(struct gb_message *message)
{
kfree(message->buffer);
kmem_cache_free(gb_message_cache, message);
}
static int gb_operation_status_map(u8 status)
{
switch (status) {
case GB_OP_SUCCESS:
return 0;
case GB_OP_INTERRUPTED:
return -EINTR;
case GB_OP_TIMEOUT:
return -ETIMEDOUT;
case GB_OP_NO_MEMORY:
return -ENOMEM;
case GB_OP_PROTOCOL_BAD:
return -EPROTONOSUPPORT;
case GB_OP_OVERFLOW:
return -EMSGSIZE;
case GB_OP_INVALID:
return -EINVAL;
case GB_OP_RETRY:
return -EAGAIN;
case GB_OP_NONEXISTENT:
return -ENODEV;
case GB_OP_MALFUNCTION:
return -EILSEQ;
case GB_OP_UNKNOWN_ERROR:
default:
return -EIO;
}
}
static u8 gb_operation_errno_map(int errno)
{
switch (errno) {
case 0:
return GB_OP_SUCCESS;
case -EINTR:
return GB_OP_INTERRUPTED;
case -ETIMEDOUT:
return GB_OP_TIMEOUT;
case -ENOMEM:
return GB_OP_NO_MEMORY;
case -EPROTONOSUPPORT:
return GB_OP_PROTOCOL_BAD;
case -EMSGSIZE:
return GB_OP_OVERFLOW;
case -EINVAL:
return GB_OP_INVALID;
case -EAGAIN:
return GB_OP_RETRY;
case -EILSEQ:
return GB_OP_MALFUNCTION;
case -ENODEV:
return GB_OP_NONEXISTENT;
case -EIO:
default:
return GB_OP_UNKNOWN_ERROR;
}
}
bool gb_operation_response_alloc(struct gb_operation *operation,
size_t response_size, gfp_t gfp)
{
struct gb_host_device *hd = operation->connection->hd;
struct gb_operation_msg_hdr *request_header;
struct gb_message *response;
u8 type;
type = operation->type | GB_MESSAGE_TYPE_RESPONSE;
response = gb_operation_message_alloc(hd, type, response_size, gfp);
if (!response)
return false;
response->operation = operation;
request_header = operation->request->header;
response->header->operation_id = request_header->operation_id;
operation->response = response;
return true;
}
static struct gb_operation *
gb_operation_create_common(struct gb_connection *connection, u8 type,
size_t request_size, size_t response_size,
unsigned long op_flags, gfp_t gfp_flags)
{
struct gb_host_device *hd = connection->hd;
struct gb_operation *operation;
operation = kmem_cache_zalloc(gb_operation_cache, gfp_flags);
if (!operation)
return NULL;
operation->connection = connection;
operation->request = gb_operation_message_alloc(hd, type, request_size,
gfp_flags);
if (!operation->request)
goto err_cache;
operation->request->operation = operation;
if (!(op_flags & GB_OPERATION_FLAG_INCOMING)) {
if (!gb_operation_response_alloc(operation, response_size,
gfp_flags)) {
goto err_request;
}
setup_timer(&operation->timer, gb_operation_timeout,
(unsigned long)operation);
}
operation->flags = op_flags;
operation->type = type;
operation->errno = -EBADR;
INIT_WORK(&operation->work, gb_operation_work);
init_completion(&operation->completion);
kref_init(&operation->kref);
atomic_set(&operation->waiters, 0);
return operation;
err_request:
gb_operation_message_free(operation->request);
err_cache:
kmem_cache_free(gb_operation_cache, operation);
return NULL;
}
struct gb_operation *
gb_operation_create_flags(struct gb_connection *connection,
u8 type, size_t request_size,
size_t response_size, unsigned long flags,
gfp_t gfp)
{
struct gb_operation *operation;
if (WARN_ON_ONCE(type == GB_REQUEST_TYPE_INVALID))
return NULL;
if (WARN_ON_ONCE(type & GB_MESSAGE_TYPE_RESPONSE))
type &= ~GB_MESSAGE_TYPE_RESPONSE;
if (WARN_ON_ONCE(flags & ~GB_OPERATION_FLAG_USER_MASK))
flags &= GB_OPERATION_FLAG_USER_MASK;
operation = gb_operation_create_common(connection, type,
request_size, response_size,
flags, gfp);
if (operation)
trace_gb_operation_create(operation);
return operation;
}
struct gb_operation *
gb_operation_create_core(struct gb_connection *connection,
u8 type, size_t request_size,
size_t response_size, unsigned long flags,
gfp_t gfp)
{
struct gb_operation *operation;
flags |= GB_OPERATION_FLAG_CORE;
operation = gb_operation_create_common(connection, type,
request_size, response_size,
flags, gfp);
if (operation)
trace_gb_operation_create_core(operation);
return operation;
}
size_t gb_operation_get_payload_size_max(struct gb_connection *connection)
{
struct gb_host_device *hd = connection->hd;
return hd->buffer_size_max - sizeof(struct gb_operation_msg_hdr);
}
static struct gb_operation *
gb_operation_create_incoming(struct gb_connection *connection, u16 id,
u8 type, void *data, size_t size)
{
struct gb_operation *operation;
size_t request_size;
unsigned long flags = GB_OPERATION_FLAG_INCOMING;
request_size = size - sizeof(struct gb_operation_msg_hdr);
if (!id)
flags |= GB_OPERATION_FLAG_UNIDIRECTIONAL;
operation = gb_operation_create_common(connection, type,
request_size,
GB_REQUEST_TYPE_INVALID,
flags, GFP_ATOMIC);
if (!operation)
return NULL;
operation->id = id;
memcpy(operation->request->header, data, size);
trace_gb_operation_create_incoming(operation);
return operation;
}
void gb_operation_get(struct gb_operation *operation)
{
kref_get(&operation->kref);
}
static void _gb_operation_destroy(struct kref *kref)
{
struct gb_operation *operation;
operation = container_of(kref, struct gb_operation, kref);
trace_gb_operation_destroy(operation);
if (operation->response)
gb_operation_message_free(operation->response);
gb_operation_message_free(operation->request);
kmem_cache_free(gb_operation_cache, operation);
}
void gb_operation_put(struct gb_operation *operation)
{
if (WARN_ON(!operation))
return;
kref_put(&operation->kref, _gb_operation_destroy);
}
static void gb_operation_sync_callback(struct gb_operation *operation)
{
complete(&operation->completion);
}
int gb_operation_request_send(struct gb_operation *operation,
gb_operation_callback callback,
unsigned int timeout,
gfp_t gfp)
{
struct gb_connection *connection = operation->connection;
struct gb_operation_msg_hdr *header;
unsigned int cycle;
int ret;
if (gb_connection_is_offloaded(connection))
return -EBUSY;
if (!callback)
return -EINVAL;
operation->callback = callback;
if (gb_operation_is_unidirectional(operation)) {
operation->id = 0;
} else {
cycle = (unsigned int)atomic_inc_return(&connection->op_cycle);
operation->id = (u16)(cycle % U16_MAX + 1);
}
header = operation->request->header;
header->operation_id = cpu_to_le16(operation->id);
gb_operation_result_set(operation, -EINPROGRESS);
gb_operation_get(operation);
ret = gb_operation_get_active(operation);
if (ret)
goto err_put;
ret = gb_message_send(operation->request, gfp);
if (ret)
goto err_put_active;
if (timeout) {
operation->timer.expires = jiffies + msecs_to_jiffies(timeout);
add_timer(&operation->timer);
}
return 0;
err_put_active:
gb_operation_put_active(operation);
err_put:
gb_operation_put(operation);
return ret;
}
int gb_operation_request_send_sync_timeout(struct gb_operation *operation,
unsigned int timeout)
{
int ret;
ret = gb_operation_request_send(operation, gb_operation_sync_callback,
timeout, GFP_KERNEL);
if (ret)
return ret;
ret = wait_for_completion_interruptible(&operation->completion);
if (ret < 0) {
gb_operation_cancel(operation, -ECANCELED);
}
return gb_operation_result(operation);
}
static int gb_operation_response_send(struct gb_operation *operation,
int errno)
{
struct gb_connection *connection = operation->connection;
int ret;
if (!operation->response &&
!gb_operation_is_unidirectional(operation)) {
if (!gb_operation_response_alloc(operation, 0, GFP_KERNEL))
return -ENOMEM;
}
if (!gb_operation_result_set(operation, errno)) {
dev_err(&connection->hd->dev, "request result already set\n");
return -EIO;
}
if (gb_operation_is_unidirectional(operation))
return 0;
gb_operation_get(operation);
ret = gb_operation_get_active(operation);
if (ret)
goto err_put;
operation->response->header->result = gb_operation_errno_map(errno);
ret = gb_message_send(operation->response, GFP_KERNEL);
if (ret)
goto err_put_active;
return 0;
err_put_active:
gb_operation_put_active(operation);
err_put:
gb_operation_put(operation);
return ret;
}
void greybus_message_sent(struct gb_host_device *hd,
struct gb_message *message, int status)
{
struct gb_operation *operation = message->operation;
struct gb_connection *connection = operation->connection;
if (message == operation->response) {
if (status) {
dev_err(&connection->hd->dev,
"%s: error sending response 0x%02x: %d\n",
connection->name, operation->type, status);
}
gb_operation_put_active(operation);
gb_operation_put(operation);
} else if (status || gb_operation_is_unidirectional(operation)) {
if (gb_operation_result_set(operation, status)) {
queue_work(gb_operation_completion_wq,
&operation->work);
}
}
}
static void gb_connection_recv_request(struct gb_connection *connection,
const struct gb_operation_msg_hdr *header,
void *data, size_t size)
{
struct gb_operation *operation;
u16 operation_id;
u8 type;
int ret;
operation_id = le16_to_cpu(header->operation_id);
type = header->type;
operation = gb_operation_create_incoming(connection, operation_id,
type, data, size);
if (!operation) {
dev_err(&connection->hd->dev,
"%s: can't create incoming operation\n",
connection->name);
return;
}
ret = gb_operation_get_active(operation);
if (ret) {
gb_operation_put(operation);
return;
}
trace_gb_message_recv_request(operation->request);
if (gb_operation_result_set(operation, -EINPROGRESS))
queue_work(connection->wq, &operation->work);
}
static void gb_connection_recv_response(struct gb_connection *connection,
const struct gb_operation_msg_hdr *header,
void *data, size_t size)
{
struct gb_operation *operation;
struct gb_message *message;
size_t message_size;
u16 operation_id;
int errno;
operation_id = le16_to_cpu(header->operation_id);
if (!operation_id) {
dev_err_ratelimited(&connection->hd->dev,
"%s: invalid response id 0 received\n",
connection->name);
return;
}
operation = gb_operation_find_outgoing(connection, operation_id);
if (!operation) {
dev_err_ratelimited(&connection->hd->dev,
"%s: unexpected response id 0x%04x received\n",
connection->name, operation_id);
return;
}
errno = gb_operation_status_map(header->result);
message = operation->response;
message_size = sizeof(*header) + message->payload_size;
if (!errno && size > message_size) {
dev_err_ratelimited(&connection->hd->dev,
"%s: malformed response 0x%02x received (%zu > %zu)\n",
connection->name, header->type,
size, message_size);
errno = -EMSGSIZE;
} else if (!errno && size < message_size) {
if (gb_operation_short_response_allowed(operation)) {
message->payload_size = size - sizeof(*header);
} else {
dev_err_ratelimited(&connection->hd->dev,
"%s: short response 0x%02x received (%zu < %zu)\n",
connection->name, header->type,
size, message_size);
errno = -EMSGSIZE;
}
}
if (errno)
size = sizeof(*header);
if (gb_operation_result_set(operation, errno)) {
memcpy(message->buffer, data, size);
trace_gb_message_recv_response(message);
queue_work(gb_operation_completion_wq, &operation->work);
}
gb_operation_put(operation);
}
void gb_connection_recv(struct gb_connection *connection,
void *data, size_t size)
{
struct gb_operation_msg_hdr header;
struct device *dev = &connection->hd->dev;
size_t msg_size;
if (connection->state == GB_CONNECTION_STATE_DISABLED ||
gb_connection_is_offloaded(connection)) {
dev_warn_ratelimited(dev, "%s: dropping %zu received bytes\n",
connection->name, size);
return;
}
if (size < sizeof(header)) {
dev_err_ratelimited(dev, "%s: short message received\n",
connection->name);
return;
}
memcpy(&header, data, sizeof(header));
msg_size = le16_to_cpu(header.size);
if (size < msg_size) {
dev_err_ratelimited(dev,
"%s: incomplete message 0x%04x of type 0x%02x received (%zu < %zu)\n",
connection->name,
le16_to_cpu(header.operation_id),
header.type, size, msg_size);
return;
}
if (header.type & GB_MESSAGE_TYPE_RESPONSE) {
gb_connection_recv_response(connection, &header, data,
msg_size);
} else {
gb_connection_recv_request(connection, &header, data,
msg_size);
}
}
void gb_operation_cancel(struct gb_operation *operation, int errno)
{
if (WARN_ON(gb_operation_is_incoming(operation)))
return;
if (gb_operation_result_set(operation, errno)) {
gb_message_cancel(operation->request);
queue_work(gb_operation_completion_wq, &operation->work);
}
trace_gb_message_cancel_outgoing(operation->request);
atomic_inc(&operation->waiters);
wait_event(gb_operation_cancellation_queue,
!gb_operation_is_active(operation));
atomic_dec(&operation->waiters);
}
void gb_operation_cancel_incoming(struct gb_operation *operation, int errno)
{
if (WARN_ON(!gb_operation_is_incoming(operation)))
return;
if (!gb_operation_is_unidirectional(operation)) {
flush_work(&operation->work);
if (!gb_operation_result_set(operation, errno))
gb_message_cancel(operation->response);
}
trace_gb_message_cancel_incoming(operation->response);
atomic_inc(&operation->waiters);
wait_event(gb_operation_cancellation_queue,
!gb_operation_is_active(operation));
atomic_dec(&operation->waiters);
}
int gb_operation_sync_timeout(struct gb_connection *connection, int type,
void *request, int request_size,
void *response, int response_size,
unsigned int timeout)
{
struct gb_operation *operation;
int ret;
if ((response_size && !response) ||
(request_size && !request))
return -EINVAL;
operation = gb_operation_create(connection, type,
request_size, response_size,
GFP_KERNEL);
if (!operation)
return -ENOMEM;
if (request_size)
memcpy(operation->request->payload, request, request_size);
ret = gb_operation_request_send_sync_timeout(operation, timeout);
if (ret) {
dev_err(&connection->hd->dev,
"%s: synchronous operation id 0x%04x of type 0x%02x failed: %d\n",
connection->name, operation->id, type, ret);
} else {
if (response_size) {
memcpy(response, operation->response->payload,
response_size);
}
}
gb_operation_put(operation);
return ret;
}
int gb_operation_unidirectional_timeout(struct gb_connection *connection,
int type, void *request, int request_size,
unsigned int timeout)
{
struct gb_operation *operation;
int ret;
if (request_size && !request)
return -EINVAL;
operation = gb_operation_create_flags(connection, type,
request_size, 0,
GB_OPERATION_FLAG_UNIDIRECTIONAL,
GFP_KERNEL);
if (!operation)
return -ENOMEM;
if (request_size)
memcpy(operation->request->payload, request, request_size);
ret = gb_operation_request_send_sync_timeout(operation, timeout);
if (ret) {
dev_err(&connection->hd->dev,
"%s: unidirectional operation of type 0x%02x failed: %d\n",
connection->name, type, ret);
}
gb_operation_put(operation);
return ret;
}
int __init gb_operation_init(void)
{
gb_message_cache = kmem_cache_create("gb_message_cache",
sizeof(struct gb_message), 0, 0, NULL);
if (!gb_message_cache)
return -ENOMEM;
gb_operation_cache = kmem_cache_create("gb_operation_cache",
sizeof(struct gb_operation), 0, 0, NULL);
if (!gb_operation_cache)
goto err_destroy_message_cache;
gb_operation_completion_wq = alloc_workqueue("greybus_completion",
0, 0);
if (!gb_operation_completion_wq)
goto err_destroy_operation_cache;
return 0;
err_destroy_operation_cache:
kmem_cache_destroy(gb_operation_cache);
gb_operation_cache = NULL;
err_destroy_message_cache:
kmem_cache_destroy(gb_message_cache);
gb_message_cache = NULL;
return -ENOMEM;
}
void gb_operation_exit(void)
{
destroy_workqueue(gb_operation_completion_wq);
gb_operation_completion_wq = NULL;
kmem_cache_destroy(gb_operation_cache);
gb_operation_cache = NULL;
kmem_cache_destroy(gb_message_cache);
gb_message_cache = NULL;
}
