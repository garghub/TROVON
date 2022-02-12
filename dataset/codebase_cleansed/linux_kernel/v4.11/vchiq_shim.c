const VCHI_MESSAGE_DRIVER_T *
vchi_mphi_message_driver_func_table(void)
{
return NULL;
}
const VCHI_CONNECTION_API_T *
single_get_func_table(void)
{
return NULL;
}
VCHI_CONNECTION_T *vchi_create_connection(
const VCHI_CONNECTION_API_T *function_table,
const VCHI_MESSAGE_DRIVER_T *low_level)
{
(void)function_table;
(void)low_level;
return NULL;
}
int32_t vchi_msg_peek(VCHI_SERVICE_HANDLE_T handle,
void **data,
uint32_t *msg_size,
VCHI_FLAGS_T flags)
{
SHIM_SERVICE_T *service = (SHIM_SERVICE_T *)handle;
VCHIQ_HEADER_T *header;
WARN_ON((flags != VCHI_FLAGS_NONE) &&
(flags != VCHI_FLAGS_BLOCK_UNTIL_OP_COMPLETE));
if (flags == VCHI_FLAGS_NONE)
if (vchiu_queue_is_empty(&service->queue))
return -1;
header = vchiu_queue_peek(&service->queue);
*data = header->data;
*msg_size = header->size;
return 0;
}
int32_t vchi_msg_remove(VCHI_SERVICE_HANDLE_T handle)
{
SHIM_SERVICE_T *service = (SHIM_SERVICE_T *)handle;
VCHIQ_HEADER_T *header;
header = vchiu_queue_pop(&service->queue);
vchiq_release_message(service->handle, header);
return 0;
}
static
int32_t vchi_msg_queue(VCHI_SERVICE_HANDLE_T handle,
ssize_t (*copy_callback)(void *context, void *dest,
size_t offset, size_t maxsize),
void *context,
uint32_t data_size)
{
SHIM_SERVICE_T *service = (SHIM_SERVICE_T *)handle;
VCHIQ_STATUS_T status;
while (1) {
status = vchiq_queue_message(service->handle,
copy_callback,
context,
data_size);
if (status != VCHIQ_RETRY)
break;
msleep(1);
}
return vchiq_status_to_vchi(status);
}
static ssize_t
vchi_queue_kernel_message_callback(void *context,
void *dest,
size_t offset,
size_t maxsize)
{
memcpy(dest, context + offset, maxsize);
return maxsize;
}
int
vchi_queue_kernel_message(VCHI_SERVICE_HANDLE_T handle,
void *data,
unsigned int size)
{
return vchi_msg_queue(handle,
vchi_queue_kernel_message_callback,
data,
size);
}
static ssize_t
vchi_queue_user_message_callback(void *context,
void *dest,
size_t offset,
size_t maxsize)
{
struct vchi_queue_user_message_context *copycontext = context;
if (copy_from_user(dest, copycontext->data + offset, maxsize))
return -EFAULT;
return maxsize;
}
int
vchi_queue_user_message(VCHI_SERVICE_HANDLE_T handle,
void __user *data,
unsigned int size)
{
struct vchi_queue_user_message_context copycontext = {
.data = data
};
return vchi_msg_queue(handle,
vchi_queue_user_message_callback,
&copycontext,
size);
}
int32_t vchi_bulk_queue_receive(VCHI_SERVICE_HANDLE_T handle,
void *data_dst,
uint32_t data_size,
VCHI_FLAGS_T flags,
void *bulk_handle)
{
SHIM_SERVICE_T *service = (SHIM_SERVICE_T *)handle;
VCHIQ_BULK_MODE_T mode;
VCHIQ_STATUS_T status;
switch ((int)flags) {
case VCHI_FLAGS_CALLBACK_WHEN_OP_COMPLETE
| VCHI_FLAGS_BLOCK_UNTIL_QUEUED:
WARN_ON(!service->callback);
mode = VCHIQ_BULK_MODE_CALLBACK;
break;
case VCHI_FLAGS_BLOCK_UNTIL_OP_COMPLETE:
mode = VCHIQ_BULK_MODE_BLOCKING;
break;
case VCHI_FLAGS_BLOCK_UNTIL_QUEUED:
case VCHI_FLAGS_NONE:
mode = VCHIQ_BULK_MODE_NOCALLBACK;
break;
default:
WARN(1, "unsupported message\n");
return vchiq_status_to_vchi(VCHIQ_ERROR);
}
while (1) {
status = vchiq_bulk_receive(service->handle, data_dst,
data_size, bulk_handle, mode);
if (status != VCHIQ_RETRY)
break;
msleep(1);
}
return vchiq_status_to_vchi(status);
}
int32_t vchi_bulk_queue_transmit(VCHI_SERVICE_HANDLE_T handle,
const void *data_src,
uint32_t data_size,
VCHI_FLAGS_T flags,
void *bulk_handle)
{
SHIM_SERVICE_T *service = (SHIM_SERVICE_T *)handle;
VCHIQ_BULK_MODE_T mode;
VCHIQ_STATUS_T status;
switch ((int)flags) {
case VCHI_FLAGS_CALLBACK_WHEN_OP_COMPLETE
| VCHI_FLAGS_BLOCK_UNTIL_QUEUED:
WARN_ON(!service->callback);
mode = VCHIQ_BULK_MODE_CALLBACK;
break;
case VCHI_FLAGS_BLOCK_UNTIL_DATA_READ:
case VCHI_FLAGS_BLOCK_UNTIL_OP_COMPLETE:
mode = VCHIQ_BULK_MODE_BLOCKING;
break;
case VCHI_FLAGS_BLOCK_UNTIL_QUEUED:
case VCHI_FLAGS_NONE:
mode = VCHIQ_BULK_MODE_NOCALLBACK;
break;
default:
WARN(1, "unsupported message\n");
return vchiq_status_to_vchi(VCHIQ_ERROR);
}
while (1) {
status = vchiq_bulk_transmit(service->handle, data_src,
data_size, bulk_handle, mode);
if (status != VCHIQ_RETRY)
break;
msleep(1);
}
return vchiq_status_to_vchi(status);
}
int32_t vchi_msg_dequeue(VCHI_SERVICE_HANDLE_T handle,
void *data,
uint32_t max_data_size_to_read,
uint32_t *actual_msg_size,
VCHI_FLAGS_T flags)
{
SHIM_SERVICE_T *service = (SHIM_SERVICE_T *)handle;
VCHIQ_HEADER_T *header;
WARN_ON((flags != VCHI_FLAGS_NONE) &&
(flags != VCHI_FLAGS_BLOCK_UNTIL_OP_COMPLETE));
if (flags == VCHI_FLAGS_NONE)
if (vchiu_queue_is_empty(&service->queue))
return -1;
header = vchiu_queue_pop(&service->queue);
memcpy(data, header->data, header->size < max_data_size_to_read ?
header->size : max_data_size_to_read);
*actual_msg_size = header->size;
vchiq_release_message(service->handle, header);
return 0;
}
int32_t vchi_held_msg_release(VCHI_HELD_MSG_T *message)
{
vchiq_release_message((VCHIQ_SERVICE_HANDLE_T)(long)message->service,
(VCHIQ_HEADER_T *)message->message);
return 0;
}
int32_t vchi_msg_hold(VCHI_SERVICE_HANDLE_T handle,
void **data,
uint32_t *msg_size,
VCHI_FLAGS_T flags,
VCHI_HELD_MSG_T *message_handle)
{
SHIM_SERVICE_T *service = (SHIM_SERVICE_T *)handle;
VCHIQ_HEADER_T *header;
WARN_ON((flags != VCHI_FLAGS_NONE) &&
(flags != VCHI_FLAGS_BLOCK_UNTIL_OP_COMPLETE));
if (flags == VCHI_FLAGS_NONE)
if (vchiu_queue_is_empty(&service->queue))
return -1;
header = vchiu_queue_pop(&service->queue);
*data = header->data;
*msg_size = header->size;
message_handle->service =
(struct opaque_vchi_service_t *)(long)service->handle;
message_handle->message = header;
return 0;
}
int32_t vchi_initialise(VCHI_INSTANCE_T *instance_handle)
{
VCHIQ_INSTANCE_T instance;
VCHIQ_STATUS_T status;
status = vchiq_initialise(&instance);
*instance_handle = (VCHI_INSTANCE_T)instance;
return vchiq_status_to_vchi(status);
}
int32_t vchi_connect(VCHI_CONNECTION_T **connections,
const uint32_t num_connections,
VCHI_INSTANCE_T instance_handle)
{
VCHIQ_INSTANCE_T instance = (VCHIQ_INSTANCE_T)instance_handle;
(void)connections;
(void)num_connections;
return vchiq_connect(instance);
}
int32_t vchi_disconnect(VCHI_INSTANCE_T instance_handle)
{
VCHIQ_INSTANCE_T instance = (VCHIQ_INSTANCE_T)instance_handle;
return vchiq_status_to_vchi(vchiq_shutdown(instance));
}
static VCHIQ_STATUS_T shim_callback(VCHIQ_REASON_T reason,
VCHIQ_HEADER_T *header, VCHIQ_SERVICE_HANDLE_T handle, void *bulk_user)
{
SHIM_SERVICE_T *service =
(SHIM_SERVICE_T *)VCHIQ_GET_SERVICE_USERDATA(handle);
if (!service->callback)
goto release;
switch (reason) {
case VCHIQ_MESSAGE_AVAILABLE:
vchiu_queue_push(&service->queue, header);
service->callback(service->callback_param,
VCHI_CALLBACK_MSG_AVAILABLE, NULL);
goto done;
break;
case VCHIQ_BULK_TRANSMIT_DONE:
service->callback(service->callback_param,
VCHI_CALLBACK_BULK_SENT, bulk_user);
break;
case VCHIQ_BULK_RECEIVE_DONE:
service->callback(service->callback_param,
VCHI_CALLBACK_BULK_RECEIVED, bulk_user);
break;
case VCHIQ_SERVICE_CLOSED:
service->callback(service->callback_param,
VCHI_CALLBACK_SERVICE_CLOSED, NULL);
break;
case VCHIQ_SERVICE_OPENED:
break;
case VCHIQ_BULK_TRANSMIT_ABORTED:
service->callback(service->callback_param,
VCHI_CALLBACK_BULK_TRANSMIT_ABORTED,
bulk_user);
break;
case VCHIQ_BULK_RECEIVE_ABORTED:
service->callback(service->callback_param,
VCHI_CALLBACK_BULK_RECEIVE_ABORTED,
bulk_user);
break;
default:
WARN(1, "not supported\n");
break;
}
release:
vchiq_release_message(service->handle, header);
done:
return VCHIQ_SUCCESS;
}
static SHIM_SERVICE_T *service_alloc(VCHIQ_INSTANCE_T instance,
SERVICE_CREATION_T *setup)
{
SHIM_SERVICE_T *service = kzalloc(sizeof(SHIM_SERVICE_T), GFP_KERNEL);
(void)instance;
if (service) {
if (vchiu_queue_init(&service->queue, 64)) {
service->callback = setup->callback;
service->callback_param = setup->callback_param;
} else {
kfree(service);
service = NULL;
}
}
return service;
}
static void service_free(SHIM_SERVICE_T *service)
{
if (service) {
vchiu_queue_delete(&service->queue);
kfree(service);
}
}
int32_t vchi_service_open(VCHI_INSTANCE_T instance_handle,
SERVICE_CREATION_T *setup,
VCHI_SERVICE_HANDLE_T *handle)
{
VCHIQ_INSTANCE_T instance = (VCHIQ_INSTANCE_T)instance_handle;
SHIM_SERVICE_T *service = service_alloc(instance, setup);
*handle = (VCHI_SERVICE_HANDLE_T)service;
if (service) {
VCHIQ_SERVICE_PARAMS_T params;
VCHIQ_STATUS_T status;
memset(&params, 0, sizeof(params));
params.fourcc = setup->service_id;
params.callback = shim_callback;
params.userdata = service;
params.version = setup->version.version;
params.version_min = setup->version.version_min;
status = vchiq_open_service(instance, &params,
&service->handle);
if (status != VCHIQ_SUCCESS) {
service_free(service);
service = NULL;
*handle = NULL;
}
}
return (service != NULL) ? 0 : -1;
}
int32_t vchi_service_create(VCHI_INSTANCE_T instance_handle,
SERVICE_CREATION_T *setup,
VCHI_SERVICE_HANDLE_T *handle)
{
VCHIQ_INSTANCE_T instance = (VCHIQ_INSTANCE_T)instance_handle;
SHIM_SERVICE_T *service = service_alloc(instance, setup);
*handle = (VCHI_SERVICE_HANDLE_T)service;
if (service) {
VCHIQ_SERVICE_PARAMS_T params;
VCHIQ_STATUS_T status;
memset(&params, 0, sizeof(params));
params.fourcc = setup->service_id;
params.callback = shim_callback;
params.userdata = service;
params.version = setup->version.version;
params.version_min = setup->version.version_min;
status = vchiq_add_service(instance, &params, &service->handle);
if (status != VCHIQ_SUCCESS) {
service_free(service);
service = NULL;
*handle = NULL;
}
}
return (service != NULL) ? 0 : -1;
}
int32_t vchi_service_close(const VCHI_SERVICE_HANDLE_T handle)
{
int32_t ret = -1;
SHIM_SERVICE_T *service = (SHIM_SERVICE_T *)handle;
if (service) {
VCHIQ_STATUS_T status = vchiq_close_service(service->handle);
if (status == VCHIQ_SUCCESS) {
service_free(service);
service = NULL;
}
ret = vchiq_status_to_vchi(status);
}
return ret;
}
int32_t vchi_service_destroy(const VCHI_SERVICE_HANDLE_T handle)
{
int32_t ret = -1;
SHIM_SERVICE_T *service = (SHIM_SERVICE_T *)handle;
if (service) {
VCHIQ_STATUS_T status = vchiq_remove_service(service->handle);
if (status == VCHIQ_SUCCESS) {
service_free(service);
service = NULL;
}
ret = vchiq_status_to_vchi(status);
}
return ret;
}
int32_t vchi_service_set_option(const VCHI_SERVICE_HANDLE_T handle,
VCHI_SERVICE_OPTION_T option,
int value)
{
int32_t ret = -1;
SHIM_SERVICE_T *service = (SHIM_SERVICE_T *)handle;
VCHIQ_SERVICE_OPTION_T vchiq_option;
switch (option) {
case VCHI_SERVICE_OPTION_TRACE:
vchiq_option = VCHIQ_SERVICE_OPTION_TRACE;
break;
case VCHI_SERVICE_OPTION_SYNCHRONOUS:
vchiq_option = VCHIQ_SERVICE_OPTION_SYNCHRONOUS;
break;
default:
service = NULL;
break;
}
if (service) {
VCHIQ_STATUS_T status =
vchiq_set_service_option(service->handle,
vchiq_option,
value);
ret = vchiq_status_to_vchi(status);
}
return ret;
}
int32_t vchi_get_peer_version(const VCHI_SERVICE_HANDLE_T handle, short *peer_version)
{
int32_t ret = -1;
SHIM_SERVICE_T *service = (SHIM_SERVICE_T *)handle;
if (service)
{
VCHIQ_STATUS_T status;
status = vchiq_get_peer_version(service->handle, peer_version);
ret = vchiq_status_to_vchi(status);
}
return ret;
}
uint32_t
vchi_readbuf_uint32(const void *_ptr)
{
const unsigned char *ptr = _ptr;
return ptr[0] | (ptr[1] << 8) | (ptr[2] << 16) | (ptr[3] << 24);
}
void
vchi_writebuf_uint32(void *_ptr, uint32_t value)
{
unsigned char *ptr = _ptr;
ptr[0] = (unsigned char)((value >> 0) & 0xFF);
ptr[1] = (unsigned char)((value >> 8) & 0xFF);
ptr[2] = (unsigned char)((value >> 16) & 0xFF);
ptr[3] = (unsigned char)((value >> 24) & 0xFF);
}
uint16_t
vchi_readbuf_uint16(const void *_ptr)
{
const unsigned char *ptr = _ptr;
return ptr[0] | (ptr[1] << 8);
}
void
vchi_writebuf_uint16(void *_ptr, uint16_t value)
{
unsigned char *ptr = _ptr;
ptr[0] = (value >> 0) & 0xFF;
ptr[1] = (value >> 8) & 0xFF;
}
int32_t vchi_service_use(const VCHI_SERVICE_HANDLE_T handle)
{
int32_t ret = -1;
SHIM_SERVICE_T *service = (SHIM_SERVICE_T *)handle;
if (service)
ret = vchiq_status_to_vchi(vchiq_use_service(service->handle));
return ret;
}
int32_t vchi_service_release(const VCHI_SERVICE_HANDLE_T handle)
{
int32_t ret = -1;
SHIM_SERVICE_T *service = (SHIM_SERVICE_T *)handle;
if (service)
ret = vchiq_status_to_vchi(
vchiq_release_service(service->handle));
return ret;
}
