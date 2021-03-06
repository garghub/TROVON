static VCHIQ_STATUS_T
add_completion(VCHIQ_INSTANCE_T instance, VCHIQ_REASON_T reason,
VCHIQ_HEADER_T *header, USER_SERVICE_T *user_service,
void *bulk_userdata)
{
VCHIQ_COMPLETION_DATA_T *completion;
int insert;
DEBUG_INITIALISE(g_state.local)
insert = instance->completion_insert;
while ((insert - instance->completion_remove) >= MAX_COMPLETIONS) {
DEBUG_TRACE(SERVICE_CALLBACK_LINE);
vchiq_log_trace(vchiq_arm_log_level,
"add_completion - completion queue full");
DEBUG_COUNT(COMPLETION_QUEUE_FULL_COUNT);
if (down_interruptible(&instance->remove_event) != 0) {
vchiq_log_info(vchiq_arm_log_level,
"service_callback interrupted");
return VCHIQ_RETRY;
} else if (instance->closing) {
vchiq_log_info(vchiq_arm_log_level,
"service_callback closing");
return VCHIQ_SUCCESS;
}
DEBUG_TRACE(SERVICE_CALLBACK_LINE);
}
completion = &instance->completions[insert & (MAX_COMPLETIONS - 1)];
completion->header = header;
completion->reason = reason;
completion->service_userdata = user_service->service;
completion->bulk_userdata = bulk_userdata;
if (reason == VCHIQ_SERVICE_CLOSED) {
lock_service(user_service->service);
if (instance->use_close_delivered)
user_service->close_pending = 1;
}
wmb();
if (reason == VCHIQ_MESSAGE_AVAILABLE)
user_service->message_available_pos = insert;
insert++;
instance->completion_insert = insert;
up(&instance->insert_event);
return VCHIQ_SUCCESS;
}
static VCHIQ_STATUS_T
service_callback(VCHIQ_REASON_T reason, VCHIQ_HEADER_T *header,
VCHIQ_SERVICE_HANDLE_T handle, void *bulk_userdata)
{
USER_SERVICE_T *user_service;
VCHIQ_SERVICE_T *service;
VCHIQ_INSTANCE_T instance;
bool skip_completion = false;
DEBUG_INITIALISE(g_state.local)
DEBUG_TRACE(SERVICE_CALLBACK_LINE);
service = handle_to_service(handle);
BUG_ON(!service);
user_service = (USER_SERVICE_T *)service->base.userdata;
instance = user_service->instance;
if (!instance || instance->closing)
return VCHIQ_SUCCESS;
vchiq_log_trace(vchiq_arm_log_level,
"service_callback - service %lx(%d,%p), reason %d, header %lx, "
"instance %lx, bulk_userdata %lx",
(unsigned long)user_service,
service->localport, user_service->userdata,
reason, (unsigned long)header,
(unsigned long)instance, (unsigned long)bulk_userdata);
if (header && user_service->is_vchi) {
spin_lock(&msg_queue_spinlock);
while (user_service->msg_insert ==
(user_service->msg_remove + MSG_QUEUE_SIZE)) {
spin_unlock(&msg_queue_spinlock);
DEBUG_TRACE(SERVICE_CALLBACK_LINE);
DEBUG_COUNT(MSG_QUEUE_FULL_COUNT);
vchiq_log_trace(vchiq_arm_log_level,
"service_callback - msg queue full");
if ((user_service->message_available_pos -
instance->completion_remove) < 0) {
VCHIQ_STATUS_T status;
vchiq_log_info(vchiq_arm_log_level,
"Inserting extra MESSAGE_AVAILABLE");
DEBUG_TRACE(SERVICE_CALLBACK_LINE);
status = add_completion(instance, reason,
NULL, user_service, bulk_userdata);
if (status != VCHIQ_SUCCESS) {
DEBUG_TRACE(SERVICE_CALLBACK_LINE);
return status;
}
}
DEBUG_TRACE(SERVICE_CALLBACK_LINE);
if (down_interruptible(&user_service->remove_event)
!= 0) {
vchiq_log_info(vchiq_arm_log_level,
"service_callback interrupted");
DEBUG_TRACE(SERVICE_CALLBACK_LINE);
return VCHIQ_RETRY;
} else if (instance->closing) {
vchiq_log_info(vchiq_arm_log_level,
"service_callback closing");
DEBUG_TRACE(SERVICE_CALLBACK_LINE);
return VCHIQ_ERROR;
}
DEBUG_TRACE(SERVICE_CALLBACK_LINE);
spin_lock(&msg_queue_spinlock);
}
user_service->msg_queue[user_service->msg_insert &
(MSG_QUEUE_SIZE - 1)] = header;
user_service->msg_insert++;
if (((user_service->message_available_pos -
instance->completion_remove) >= 0) ||
user_service->dequeue_pending) {
user_service->dequeue_pending = 0;
skip_completion = true;
}
spin_unlock(&msg_queue_spinlock);
up(&user_service->insert_event);
header = NULL;
}
DEBUG_TRACE(SERVICE_CALLBACK_LINE);
if (skip_completion)
return VCHIQ_SUCCESS;
return add_completion(instance, reason, header, user_service,
bulk_userdata);
}
static void
user_service_free(void *userdata)
{
kfree(userdata);
}
static void close_delivered(USER_SERVICE_T *user_service)
{
vchiq_log_info(vchiq_arm_log_level,
"close_delivered(handle=%x)",
user_service->service->handle);
if (user_service->close_pending) {
unlock_service(user_service->service);
up(&user_service->close_event);
user_service->close_pending = 0;
}
}
static ssize_t
vchiq_ioc_copy_element_data(
void *context,
void *dest,
size_t offset,
size_t maxsize)
{
long res;
size_t bytes_this_round;
struct vchiq_io_copy_callback_context *copy_context =
(struct vchiq_io_copy_callback_context *)context;
if (offset != copy_context->current_offset)
return 0;
if (!copy_context->elements_to_go)
return 0;
while (1) {
bytes_this_round = min(copy_context->current_element->size -
copy_context->current_element_offset,
maxsize);
if (bytes_this_round)
break;
copy_context->elements_to_go--;
copy_context->current_element++;
copy_context->current_element_offset = 0;
if (!copy_context->elements_to_go)
return 0;
}
res = copy_from_user(dest,
copy_context->current_element->data +
copy_context->current_element_offset,
bytes_this_round);
if (res != 0)
return -EFAULT;
copy_context->current_element_offset += bytes_this_round;
copy_context->current_offset += bytes_this_round;
if (copy_context->current_element_offset ==
copy_context->current_element->size) {
copy_context->elements_to_go--;
copy_context->current_element++;
copy_context->current_element_offset = 0;
}
return bytes_this_round;
}
static VCHIQ_STATUS_T
vchiq_ioc_queue_message(VCHIQ_SERVICE_HANDLE_T handle,
struct vchiq_element *elements,
unsigned long count)
{
struct vchiq_io_copy_callback_context context;
unsigned long i;
size_t total_size = 0;
context.current_element = elements;
context.current_element_offset = 0;
context.elements_to_go = count;
context.current_offset = 0;
for (i = 0; i < count; i++) {
if (!elements[i].data && elements[i].size != 0)
return -EFAULT;
total_size += elements[i].size;
}
return vchiq_queue_message(handle, vchiq_ioc_copy_element_data,
&context, total_size);
}
static long
vchiq_ioctl(struct file *file, unsigned int cmd, unsigned long arg)
{
VCHIQ_INSTANCE_T instance = file->private_data;
VCHIQ_STATUS_T status = VCHIQ_SUCCESS;
VCHIQ_SERVICE_T *service = NULL;
long ret = 0;
int i, rc;
DEBUG_INITIALISE(g_state.local)
vchiq_log_trace(vchiq_arm_log_level,
"vchiq_ioctl - instance %pK, cmd %s, arg %lx",
instance,
((_IOC_TYPE(cmd) == VCHIQ_IOC_MAGIC) &&
(_IOC_NR(cmd) <= VCHIQ_IOC_MAX)) ?
ioctl_names[_IOC_NR(cmd)] : "<invalid>", arg);
switch (cmd) {
case VCHIQ_IOC_SHUTDOWN:
if (!instance->connected)
break;
i = 0;
while ((service = next_service_by_instance(instance->state,
instance, &i)) != NULL) {
status = vchiq_remove_service(service->handle);
unlock_service(service);
if (status != VCHIQ_SUCCESS)
break;
}
service = NULL;
if (status == VCHIQ_SUCCESS) {
instance->closing = 1;
up(&instance->insert_event);
}
break;
case VCHIQ_IOC_CONNECT:
if (instance->connected) {
ret = -EINVAL;
break;
}
rc = mutex_lock_killable(&instance->state->mutex);
if (rc != 0) {
vchiq_log_error(vchiq_arm_log_level,
"vchiq: connect: could not lock mutex for "
"state %d: %d",
instance->state->id, rc);
ret = -EINTR;
break;
}
status = vchiq_connect_internal(instance->state, instance);
mutex_unlock(&instance->state->mutex);
if (status == VCHIQ_SUCCESS)
instance->connected = 1;
else
vchiq_log_error(vchiq_arm_log_level,
"vchiq: could not connect: %d", status);
break;
case VCHIQ_IOC_CREATE_SERVICE: {
VCHIQ_CREATE_SERVICE_T args;
USER_SERVICE_T *user_service = NULL;
void *userdata;
int srvstate;
if (copy_from_user
(&args, (const void __user *)arg,
sizeof(args)) != 0) {
ret = -EFAULT;
break;
}
user_service = kmalloc(sizeof(USER_SERVICE_T), GFP_KERNEL);
if (!user_service) {
ret = -ENOMEM;
break;
}
if (args.is_open) {
if (!instance->connected) {
ret = -ENOTCONN;
kfree(user_service);
break;
}
srvstate = VCHIQ_SRVSTATE_OPENING;
} else {
srvstate =
instance->connected ?
VCHIQ_SRVSTATE_LISTENING :
VCHIQ_SRVSTATE_HIDDEN;
}
userdata = args.params.userdata;
args.params.callback = service_callback;
args.params.userdata = user_service;
service = vchiq_add_service_internal(
instance->state,
&args.params, srvstate,
instance, user_service_free);
if (service != NULL) {
user_service->service = service;
user_service->userdata = userdata;
user_service->instance = instance;
user_service->is_vchi = (args.is_vchi != 0);
user_service->dequeue_pending = 0;
user_service->close_pending = 0;
user_service->message_available_pos =
instance->completion_remove - 1;
user_service->msg_insert = 0;
user_service->msg_remove = 0;
sema_init(&user_service->insert_event, 0);
sema_init(&user_service->remove_event, 0);
sema_init(&user_service->close_event, 0);
if (args.is_open) {
status = vchiq_open_service_internal
(service, instance->pid);
if (status != VCHIQ_SUCCESS) {
vchiq_remove_service(service->handle);
service = NULL;
ret = (status == VCHIQ_RETRY) ?
-EINTR : -EIO;
break;
}
}
if (copy_to_user((void __user *)
&(((VCHIQ_CREATE_SERVICE_T __user *)
arg)->handle),
(const void *)&service->handle,
sizeof(service->handle)) != 0) {
ret = -EFAULT;
vchiq_remove_service(service->handle);
}
service = NULL;
} else {
ret = -EEXIST;
kfree(user_service);
}
} break;
case VCHIQ_IOC_CLOSE_SERVICE: {
VCHIQ_SERVICE_HANDLE_T handle = (VCHIQ_SERVICE_HANDLE_T)arg;
service = find_service_for_instance(instance, handle);
if (service != NULL) {
USER_SERVICE_T *user_service =
(USER_SERVICE_T *)service->base.userdata;
if (!user_service->close_pending) {
status = vchiq_close_service(service->handle);
if (status != VCHIQ_SUCCESS)
break;
}
if (user_service->close_pending &&
down_interruptible(&user_service->close_event))
status = VCHIQ_RETRY;
}
else
ret = -EINVAL;
} break;
case VCHIQ_IOC_REMOVE_SERVICE: {
VCHIQ_SERVICE_HANDLE_T handle = (VCHIQ_SERVICE_HANDLE_T)arg;
service = find_service_for_instance(instance, handle);
if (service != NULL) {
USER_SERVICE_T *user_service =
(USER_SERVICE_T *)service->base.userdata;
if (!user_service->close_pending) {
status = vchiq_remove_service(service->handle);
if (status != VCHIQ_SUCCESS)
break;
}
if (user_service->close_pending &&
down_interruptible(&user_service->close_event))
status = VCHIQ_RETRY;
}
else
ret = -EINVAL;
} break;
case VCHIQ_IOC_USE_SERVICE:
case VCHIQ_IOC_RELEASE_SERVICE: {
VCHIQ_SERVICE_HANDLE_T handle = (VCHIQ_SERVICE_HANDLE_T)arg;
service = find_service_for_instance(instance, handle);
if (service != NULL) {
status = (cmd == VCHIQ_IOC_USE_SERVICE) ?
vchiq_use_service_internal(service) :
vchiq_release_service_internal(service);
if (status != VCHIQ_SUCCESS) {
vchiq_log_error(vchiq_susp_log_level,
"%s: cmd %s returned error %d for "
"service %c%c%c%c:%03d",
__func__,
(cmd == VCHIQ_IOC_USE_SERVICE) ?
"VCHIQ_IOC_USE_SERVICE" :
"VCHIQ_IOC_RELEASE_SERVICE",
status,
VCHIQ_FOURCC_AS_4CHARS(
service->base.fourcc),
service->client_id);
ret = -EINVAL;
}
} else
ret = -EINVAL;
} break;
case VCHIQ_IOC_QUEUE_MESSAGE: {
VCHIQ_QUEUE_MESSAGE_T args;
if (copy_from_user
(&args, (const void __user *)arg,
sizeof(args)) != 0) {
ret = -EFAULT;
break;
}
service = find_service_for_instance(instance, args.handle);
if ((service != NULL) && (args.count <= MAX_ELEMENTS)) {
struct vchiq_element elements[MAX_ELEMENTS];
if (copy_from_user(elements, args.elements,
args.count * sizeof(struct vchiq_element)) == 0)
status = vchiq_ioc_queue_message
(args.handle,
elements, args.count);
else
ret = -EFAULT;
} else {
ret = -EINVAL;
}
} break;
case VCHIQ_IOC_QUEUE_BULK_TRANSMIT:
case VCHIQ_IOC_QUEUE_BULK_RECEIVE: {
VCHIQ_QUEUE_BULK_TRANSFER_T args;
struct bulk_waiter_node *waiter = NULL;
VCHIQ_BULK_DIR_T dir =
(cmd == VCHIQ_IOC_QUEUE_BULK_TRANSMIT) ?
VCHIQ_BULK_TRANSMIT : VCHIQ_BULK_RECEIVE;
if (copy_from_user
(&args, (const void __user *)arg,
sizeof(args)) != 0) {
ret = -EFAULT;
break;
}
service = find_service_for_instance(instance, args.handle);
if (!service) {
ret = -EINVAL;
break;
}
if (args.mode == VCHIQ_BULK_MODE_BLOCKING) {
waiter = kzalloc(sizeof(struct bulk_waiter_node),
GFP_KERNEL);
if (!waiter) {
ret = -ENOMEM;
break;
}
args.userdata = &waiter->bulk_waiter;
} else if (args.mode == VCHIQ_BULK_MODE_WAITING) {
struct list_head *pos;
mutex_lock(&instance->bulk_waiter_list_mutex);
list_for_each(pos, &instance->bulk_waiter_list) {
if (list_entry(pos, struct bulk_waiter_node,
list)->pid == current->pid) {
waiter = list_entry(pos,
struct bulk_waiter_node,
list);
list_del(pos);
break;
}
}
mutex_unlock(&instance->bulk_waiter_list_mutex);
if (!waiter) {
vchiq_log_error(vchiq_arm_log_level,
"no bulk_waiter found for pid %d",
current->pid);
ret = -ESRCH;
break;
}
vchiq_log_info(vchiq_arm_log_level,
"found bulk_waiter %pK for pid %d", waiter,
current->pid);
args.userdata = &waiter->bulk_waiter;
}
status = vchiq_bulk_transfer
(args.handle,
VCHI_MEM_HANDLE_INVALID,
args.data, args.size,
args.userdata, args.mode,
dir);
if (!waiter)
break;
if ((status != VCHIQ_RETRY) || fatal_signal_pending(current) ||
!waiter->bulk_waiter.bulk) {
if (waiter->bulk_waiter.bulk) {
spin_lock(&bulk_waiter_spinlock);
waiter->bulk_waiter.bulk->userdata = NULL;
spin_unlock(&bulk_waiter_spinlock);
}
kfree(waiter);
} else {
const VCHIQ_BULK_MODE_T mode_waiting =
VCHIQ_BULK_MODE_WAITING;
waiter->pid = current->pid;
mutex_lock(&instance->bulk_waiter_list_mutex);
list_add(&waiter->list, &instance->bulk_waiter_list);
mutex_unlock(&instance->bulk_waiter_list_mutex);
vchiq_log_info(vchiq_arm_log_level,
"saved bulk_waiter %pK for pid %d",
waiter, current->pid);
if (copy_to_user((void __user *)
&(((VCHIQ_QUEUE_BULK_TRANSFER_T __user *)
arg)->mode),
(const void *)&mode_waiting,
sizeof(mode_waiting)) != 0)
ret = -EFAULT;
}
} break;
case VCHIQ_IOC_AWAIT_COMPLETION: {
VCHIQ_AWAIT_COMPLETION_T args;
DEBUG_TRACE(AWAIT_COMPLETION_LINE);
if (!instance->connected) {
ret = -ENOTCONN;
break;
}
if (copy_from_user(&args, (const void __user *)arg,
sizeof(args)) != 0) {
ret = -EFAULT;
break;
}
mutex_lock(&instance->completion_mutex);
DEBUG_TRACE(AWAIT_COMPLETION_LINE);
while ((instance->completion_remove ==
instance->completion_insert)
&& !instance->closing) {
int rc;
DEBUG_TRACE(AWAIT_COMPLETION_LINE);
mutex_unlock(&instance->completion_mutex);
rc = down_interruptible(&instance->insert_event);
mutex_lock(&instance->completion_mutex);
if (rc != 0) {
DEBUG_TRACE(AWAIT_COMPLETION_LINE);
vchiq_log_info(vchiq_arm_log_level,
"AWAIT_COMPLETION interrupted");
ret = -EINTR;
break;
}
}
DEBUG_TRACE(AWAIT_COMPLETION_LINE);
if (ret == 0) {
int msgbufcount = args.msgbufcount;
int remove = instance->completion_remove;
for (ret = 0; ret < args.count; ret++) {
VCHIQ_COMPLETION_DATA_T *completion;
VCHIQ_SERVICE_T *service;
USER_SERVICE_T *user_service;
VCHIQ_HEADER_T *header;
if (remove == instance->completion_insert)
break;
completion = &instance->completions[
remove & (MAX_COMPLETIONS - 1)];
rmb();
service = completion->service_userdata;
user_service = service->base.userdata;
completion->service_userdata =
user_service->userdata;
header = completion->header;
if (header) {
void __user *msgbuf;
int msglen;
msglen = header->size +
sizeof(VCHIQ_HEADER_T);
if (args.msgbufsize < msglen) {
vchiq_log_error(
vchiq_arm_log_level,
"header %pK: msgbufsize %x < msglen %x",
header, args.msgbufsize,
msglen);
WARN(1, "invalid message "
"size\n");
if (ret == 0)
ret = -EMSGSIZE;
break;
}
if (msgbufcount <= 0)
break;
msgbufcount--;
if (copy_from_user(&msgbuf,
(const void __user *)
&args.msgbufs[msgbufcount],
sizeof(msgbuf)) != 0) {
if (ret == 0)
ret = -EFAULT;
break;
}
if (copy_to_user(msgbuf, header,
msglen) != 0) {
if (ret == 0)
ret = -EFAULT;
break;
}
vchiq_release_message(service->handle,
header);
completion->header = msgbuf;
}
if ((completion->reason ==
VCHIQ_SERVICE_CLOSED) &&
!instance->use_close_delivered)
unlock_service(service);
if (copy_to_user((void __user *)(
(size_t)args.buf +
ret * sizeof(VCHIQ_COMPLETION_DATA_T)),
completion,
sizeof(VCHIQ_COMPLETION_DATA_T)) != 0) {
if (ret == 0)
ret = -EFAULT;
break;
}
mb();
remove++;
instance->completion_remove = remove;
}
if (msgbufcount != args.msgbufcount) {
if (copy_to_user((void __user *)
&((VCHIQ_AWAIT_COMPLETION_T *)arg)->
msgbufcount,
&msgbufcount,
sizeof(msgbufcount)) != 0) {
ret = -EFAULT;
}
}
}
if (ret != 0)
up(&instance->remove_event);
mutex_unlock(&instance->completion_mutex);
DEBUG_TRACE(AWAIT_COMPLETION_LINE);
} break;
case VCHIQ_IOC_DEQUEUE_MESSAGE: {
VCHIQ_DEQUEUE_MESSAGE_T args;
USER_SERVICE_T *user_service;
VCHIQ_HEADER_T *header;
DEBUG_TRACE(DEQUEUE_MESSAGE_LINE);
if (copy_from_user
(&args, (const void __user *)arg,
sizeof(args)) != 0) {
ret = -EFAULT;
break;
}
service = find_service_for_instance(instance, args.handle);
if (!service) {
ret = -EINVAL;
break;
}
user_service = (USER_SERVICE_T *)service->base.userdata;
if (user_service->is_vchi == 0) {
ret = -EINVAL;
break;
}
spin_lock(&msg_queue_spinlock);
if (user_service->msg_remove == user_service->msg_insert) {
if (!args.blocking) {
spin_unlock(&msg_queue_spinlock);
DEBUG_TRACE(DEQUEUE_MESSAGE_LINE);
ret = -EWOULDBLOCK;
break;
}
user_service->dequeue_pending = 1;
do {
spin_unlock(&msg_queue_spinlock);
DEBUG_TRACE(DEQUEUE_MESSAGE_LINE);
if (down_interruptible(
&user_service->insert_event) != 0) {
vchiq_log_info(vchiq_arm_log_level,
"DEQUEUE_MESSAGE interrupted");
ret = -EINTR;
break;
}
spin_lock(&msg_queue_spinlock);
} while (user_service->msg_remove ==
user_service->msg_insert);
if (ret)
break;
}
BUG_ON((int)(user_service->msg_insert -
user_service->msg_remove) < 0);
header = user_service->msg_queue[user_service->msg_remove &
(MSG_QUEUE_SIZE - 1)];
user_service->msg_remove++;
spin_unlock(&msg_queue_spinlock);
up(&user_service->remove_event);
if (header == NULL)
ret = -ENOTCONN;
else if (header->size <= args.bufsize) {
if ((args.buf == NULL) ||
(copy_to_user((void __user *)args.buf,
header->data,
header->size) == 0)) {
ret = header->size;
vchiq_release_message(
service->handle,
header);
} else
ret = -EFAULT;
} else {
vchiq_log_error(vchiq_arm_log_level,
"header %pK: bufsize %x < size %x",
header, args.bufsize, header->size);
WARN(1, "invalid size\n");
ret = -EMSGSIZE;
}
DEBUG_TRACE(DEQUEUE_MESSAGE_LINE);
} break;
case VCHIQ_IOC_GET_CLIENT_ID: {
VCHIQ_SERVICE_HANDLE_T handle = (VCHIQ_SERVICE_HANDLE_T)arg;
ret = vchiq_get_client_id(handle);
} break;
case VCHIQ_IOC_GET_CONFIG: {
VCHIQ_GET_CONFIG_T args;
VCHIQ_CONFIG_T config;
if (copy_from_user(&args, (const void __user *)arg,
sizeof(args)) != 0) {
ret = -EFAULT;
break;
}
if (args.config_size > sizeof(config)) {
ret = -EINVAL;
break;
}
status = vchiq_get_config(instance, args.config_size, &config);
if (status == VCHIQ_SUCCESS) {
if (copy_to_user((void __user *)args.pconfig,
&config, args.config_size) != 0) {
ret = -EFAULT;
break;
}
}
} break;
case VCHIQ_IOC_SET_SERVICE_OPTION: {
VCHIQ_SET_SERVICE_OPTION_T args;
if (copy_from_user(
&args, (const void __user *)arg,
sizeof(args)) != 0) {
ret = -EFAULT;
break;
}
service = find_service_for_instance(instance, args.handle);
if (!service) {
ret = -EINVAL;
break;
}
status = vchiq_set_service_option(
args.handle, args.option, args.value);
} break;
#if defined(CONFIG_BCM2835_VCHIQ_SUPPORT_MEMDUMP)
case VCHIQ_IOC_DUMP_PHYS_MEM: {
VCHIQ_DUMP_MEM_T args;
if (copy_from_user
(&args, (const void __user *)arg,
sizeof(args)) != 0) {
ret = -EFAULT;
break;
}
dump_phys_mem(args.virt_addr, args.num_bytes);
} break;
#endif
case VCHIQ_IOC_LIB_VERSION: {
unsigned int lib_version = (unsigned int)arg;
if (lib_version < VCHIQ_VERSION_MIN)
ret = -EINVAL;
else if (lib_version >= VCHIQ_VERSION_CLOSE_DELIVERED)
instance->use_close_delivered = 1;
} break;
case VCHIQ_IOC_CLOSE_DELIVERED: {
VCHIQ_SERVICE_HANDLE_T handle = (VCHIQ_SERVICE_HANDLE_T)arg;
service = find_closed_service_for_instance(instance, handle);
if (service != NULL) {
USER_SERVICE_T *user_service =
(USER_SERVICE_T *)service->base.userdata;
close_delivered(user_service);
}
else
ret = -EINVAL;
} break;
default:
ret = -ENOTTY;
break;
}
if (service)
unlock_service(service);
if (ret == 0) {
if (status == VCHIQ_ERROR)
ret = -EIO;
else if (status == VCHIQ_RETRY)
ret = -EINTR;
}
if ((status == VCHIQ_SUCCESS) && (ret < 0) && (ret != -EINTR) &&
(ret != -EWOULDBLOCK))
vchiq_log_info(vchiq_arm_log_level,
" ioctl instance %lx, cmd %s -> status %d, %ld",
(unsigned long)instance,
(_IOC_NR(cmd) <= VCHIQ_IOC_MAX) ?
ioctl_names[_IOC_NR(cmd)] :
"<invalid>",
status, ret);
else
vchiq_log_trace(vchiq_arm_log_level,
" ioctl instance %lx, cmd %s -> status %d, %ld",
(unsigned long)instance,
(_IOC_NR(cmd) <= VCHIQ_IOC_MAX) ?
ioctl_names[_IOC_NR(cmd)] :
"<invalid>",
status, ret);
return ret;
}
static long
vchiq_compat_ioctl_create_service(
struct file *file,
unsigned int cmd,
unsigned long arg)
{
VCHIQ_CREATE_SERVICE_T __user *args;
struct vchiq_create_service32 __user *ptrargs32 =
(struct vchiq_create_service32 __user *)arg;
struct vchiq_create_service32 args32;
long ret;
args = compat_alloc_user_space(sizeof(*args));
if (!args)
return -EFAULT;
if (copy_from_user(&args32,
(struct vchiq_create_service32 __user *)arg,
sizeof(args32)))
return -EFAULT;
if (put_user(args32.params.fourcc, &args->params.fourcc) ||
put_user(compat_ptr(args32.params.callback),
&args->params.callback) ||
put_user(compat_ptr(args32.params.userdata),
&args->params.userdata) ||
put_user(args32.params.version, &args->params.version) ||
put_user(args32.params.version_min,
&args->params.version_min) ||
put_user(args32.is_open, &args->is_open) ||
put_user(args32.is_vchi, &args->is_vchi) ||
put_user(args32.handle, &args->handle))
return -EFAULT;
ret = vchiq_ioctl(file, VCHIQ_IOC_CREATE_SERVICE, (unsigned long)args);
if (ret < 0)
return ret;
if (get_user(args32.handle, &args->handle))
return -EFAULT;
if (copy_to_user(&ptrargs32->handle,
&args32.handle,
sizeof(args32.handle)))
return -EFAULT;
return 0;
}
static long
vchiq_compat_ioctl_queue_message(struct file *file,
unsigned int cmd,
unsigned long arg)
{
VCHIQ_QUEUE_MESSAGE_T *args;
struct vchiq_element *elements;
struct vchiq_queue_message32 args32;
unsigned int count;
if (copy_from_user(&args32,
(struct vchiq_queue_message32 __user *)arg,
sizeof(args32)))
return -EFAULT;
args = compat_alloc_user_space(sizeof(*args) +
(sizeof(*elements) * MAX_ELEMENTS));
if (!args)
return -EFAULT;
if (put_user(args32.handle, &args->handle) ||
put_user(args32.count, &args->count) ||
put_user(compat_ptr(args32.elements), &args->elements))
return -EFAULT;
if (args32.count > MAX_ELEMENTS)
return -EINVAL;
if (args32.elements && args32.count) {
struct vchiq_element32 tempelement32[MAX_ELEMENTS];
elements = (struct vchiq_element __user *)(args + 1);
if (copy_from_user(&tempelement32,
compat_ptr(args32.elements),
sizeof(tempelement32)))
return -EFAULT;
for (count = 0; count < args32.count; count++) {
if (put_user(compat_ptr(tempelement32[count].data),
&elements[count].data) ||
put_user(tempelement32[count].size,
&elements[count].size))
return -EFAULT;
}
if (put_user(elements, &args->elements))
return -EFAULT;
}
return vchiq_ioctl(file, VCHIQ_IOC_QUEUE_MESSAGE, (unsigned long)args);
}
static long
vchiq_compat_ioctl_queue_bulk(struct file *file,
unsigned int cmd,
unsigned long arg)
{
VCHIQ_QUEUE_BULK_TRANSFER_T *args;
struct vchiq_queue_bulk_transfer32 args32;
struct vchiq_queue_bulk_transfer32 *ptrargs32 =
(struct vchiq_queue_bulk_transfer32 *)arg;
long ret;
args = compat_alloc_user_space(sizeof(*args));
if (!args)
return -EFAULT;
if (copy_from_user(&args32,
(struct vchiq_queue_bulk_transfer32 __user *)arg,
sizeof(args32)))
return -EFAULT;
if (put_user(args32.handle, &args->handle) ||
put_user(compat_ptr(args32.data), &args->data) ||
put_user(args32.size, &args->size) ||
put_user(compat_ptr(args32.userdata), &args->userdata) ||
put_user(args32.mode, &args->mode))
return -EFAULT;
if (cmd == VCHIQ_IOC_QUEUE_BULK_TRANSMIT32)
cmd = VCHIQ_IOC_QUEUE_BULK_TRANSMIT;
else
cmd = VCHIQ_IOC_QUEUE_BULK_RECEIVE;
ret = vchiq_ioctl(file, cmd, (unsigned long)args);
if (ret < 0)
return ret;
if (get_user(args32.mode, &args->mode))
return -EFAULT;
if (copy_to_user(&ptrargs32->mode,
&args32.mode,
sizeof(args32.mode)))
return -EFAULT;
return 0;
}
static long
vchiq_compat_ioctl_await_completion(struct file *file,
unsigned int cmd,
unsigned long arg)
{
VCHIQ_AWAIT_COMPLETION_T *args;
VCHIQ_COMPLETION_DATA_T *completion;
VCHIQ_COMPLETION_DATA_T completiontemp;
struct vchiq_await_completion32 args32;
struct vchiq_completion_data32 completion32;
unsigned int *msgbufcount32;
compat_uptr_t msgbuf32;
void *msgbuf;
void **msgbufptr;
long ret;
args = compat_alloc_user_space(sizeof(*args) +
sizeof(*completion) +
sizeof(*msgbufptr));
if (!args)
return -EFAULT;
completion = (VCHIQ_COMPLETION_DATA_T *)(args + 1);
msgbufptr = (void __user **)(completion + 1);
if (copy_from_user(&args32,
(struct vchiq_completion_data32 *)arg,
sizeof(args32)))
return -EFAULT;
if (put_user(args32.count, &args->count) ||
put_user(compat_ptr(args32.buf), &args->buf) ||
put_user(args32.msgbufsize, &args->msgbufsize) ||
put_user(args32.msgbufcount, &args->msgbufcount) ||
put_user(compat_ptr(args32.msgbufs), &args->msgbufs))
return -EFAULT;
if (!args32.count || !args32.buf || !args32.msgbufcount)
return vchiq_ioctl(file,
VCHIQ_IOC_AWAIT_COMPLETION,
(unsigned long)args);
if (copy_from_user(&msgbuf32,
compat_ptr(args32.msgbufs) +
(sizeof(compat_uptr_t) *
(args32.msgbufcount - 1)),
sizeof(msgbuf32)))
return -EFAULT;
msgbuf = compat_ptr(msgbuf32);
if (copy_to_user(msgbufptr,
&msgbuf,
sizeof(msgbuf)))
return -EFAULT;
if (copy_to_user(&args->msgbufs,
&msgbufptr,
sizeof(msgbufptr)))
return -EFAULT;
if (put_user(1U, &args->count) ||
put_user(completion, &args->buf) ||
put_user(1U, &args->msgbufcount))
return -EFAULT;
ret = vchiq_ioctl(file,
VCHIQ_IOC_AWAIT_COMPLETION,
(unsigned long)args);
if (ret <= 0)
return ret;
if (copy_from_user(&completiontemp, completion, sizeof(*completion)))
return -EFAULT;
completion32.reason = completiontemp.reason;
completion32.header = ptr_to_compat(completiontemp.header);
completion32.service_userdata =
ptr_to_compat(completiontemp.service_userdata);
completion32.bulk_userdata =
ptr_to_compat(completiontemp.bulk_userdata);
if (copy_to_user(compat_ptr(args32.buf),
&completion32,
sizeof(completion32)))
return -EFAULT;
args32.msgbufcount--;
msgbufcount32 =
&((struct vchiq_await_completion32 __user *)arg)->msgbufcount;
if (copy_to_user(msgbufcount32,
&args32.msgbufcount,
sizeof(args32.msgbufcount)))
return -EFAULT;
return 1;
}
static long
vchiq_compat_ioctl_dequeue_message(struct file *file,
unsigned int cmd,
unsigned long arg)
{
VCHIQ_DEQUEUE_MESSAGE_T *args;
struct vchiq_dequeue_message32 args32;
args = compat_alloc_user_space(sizeof(*args));
if (!args)
return -EFAULT;
if (copy_from_user(&args32,
(struct vchiq_dequeue_message32 *)arg,
sizeof(args32)))
return -EFAULT;
if (put_user(args32.handle, &args->handle) ||
put_user(args32.blocking, &args->blocking) ||
put_user(args32.bufsize, &args->bufsize) ||
put_user(compat_ptr(args32.buf), &args->buf))
return -EFAULT;
return vchiq_ioctl(file, VCHIQ_IOC_DEQUEUE_MESSAGE,
(unsigned long)args);
}
static long
vchiq_compat_ioctl_get_config(struct file *file,
unsigned int cmd,
unsigned long arg)
{
VCHIQ_GET_CONFIG_T *args;
struct vchiq_get_config32 args32;
args = compat_alloc_user_space(sizeof(*args));
if (!args)
return -EFAULT;
if (copy_from_user(&args32,
(struct vchiq_get_config32 *)arg,
sizeof(args32)))
return -EFAULT;
if (put_user(args32.config_size, &args->config_size) ||
put_user(compat_ptr(args32.pconfig), &args->pconfig))
return -EFAULT;
return vchiq_ioctl(file, VCHIQ_IOC_GET_CONFIG, (unsigned long)args);
}
static long
vchiq_compat_ioctl_dump_phys_mem(struct file *file,
unsigned int cmd,
unsigned long arg)
{
VCHIQ_DUMP_MEM_T *args;
struct vchiq_dump_mem32 args32;
args = compat_alloc_user_space(sizeof(*args));
if (!args)
return -EFAULT;
if (copy_from_user(&args32,
(struct vchiq_dump_mem32 *)arg,
sizeof(args32)))
return -EFAULT;
if (put_user(compat_ptr(args32.virt_addr), &args->virt_addr) ||
put_user(args32.num_bytes, &args->num_bytes))
return -EFAULT;
return vchiq_ioctl(file, VCHIQ_IOC_DUMP_PHYS_MEM, (unsigned long)args);
}
static long
vchiq_compat_ioctl(struct file *file, unsigned int cmd, unsigned long arg)
{
switch (cmd) {
case VCHIQ_IOC_CREATE_SERVICE32:
return vchiq_compat_ioctl_create_service(file, cmd, arg);
case VCHIQ_IOC_QUEUE_MESSAGE32:
return vchiq_compat_ioctl_queue_message(file, cmd, arg);
case VCHIQ_IOC_QUEUE_BULK_TRANSMIT32:
case VCHIQ_IOC_QUEUE_BULK_RECEIVE32:
return vchiq_compat_ioctl_queue_bulk(file, cmd, arg);
case VCHIQ_IOC_AWAIT_COMPLETION32:
return vchiq_compat_ioctl_await_completion(file, cmd, arg);
case VCHIQ_IOC_DEQUEUE_MESSAGE32:
return vchiq_compat_ioctl_dequeue_message(file, cmd, arg);
case VCHIQ_IOC_GET_CONFIG32:
return vchiq_compat_ioctl_get_config(file, cmd, arg);
#if defined(CONFIG_BCM2835_VCHIQ_SUPPORT_MEMDUMP)
case VCHIQ_IOC_DUMP_PHYS_MEM32:
return vchiq_compat_ioctl_dump_phys_mem(file, cmd, arg);
#endif
default:
return vchiq_ioctl(file, cmd, arg);
}
}
static int
vchiq_open(struct inode *inode, struct file *file)
{
int dev = iminor(inode) & 0x0f;
vchiq_log_info(vchiq_arm_log_level, "vchiq_open");
switch (dev) {
case VCHIQ_MINOR: {
int ret;
VCHIQ_STATE_T *state = vchiq_get_state();
VCHIQ_INSTANCE_T instance;
if (!state) {
vchiq_log_error(vchiq_arm_log_level,
"vchiq has no connection to VideoCore");
return -ENOTCONN;
}
instance = kzalloc(sizeof(*instance), GFP_KERNEL);
if (!instance)
return -ENOMEM;
instance->state = state;
instance->pid = current->tgid;
ret = vchiq_debugfs_add_instance(instance);
if (ret != 0) {
kfree(instance);
return ret;
}
sema_init(&instance->insert_event, 0);
sema_init(&instance->remove_event, 0);
mutex_init(&instance->completion_mutex);
mutex_init(&instance->bulk_waiter_list_mutex);
INIT_LIST_HEAD(&instance->bulk_waiter_list);
file->private_data = instance;
} break;
default:
vchiq_log_error(vchiq_arm_log_level,
"Unknown minor device: %d", dev);
return -ENXIO;
}
return 0;
}
static int
vchiq_release(struct inode *inode, struct file *file)
{
int dev = iminor(inode) & 0x0f;
int ret = 0;
switch (dev) {
case VCHIQ_MINOR: {
VCHIQ_INSTANCE_T instance = file->private_data;
VCHIQ_STATE_T *state = vchiq_get_state();
VCHIQ_SERVICE_T *service;
int i;
vchiq_log_info(vchiq_arm_log_level,
"vchiq_release: instance=%lx",
(unsigned long)instance);
if (!state) {
ret = -EPERM;
goto out;
}
vchiq_use_internal(instance->state, NULL,
USE_TYPE_VCHIQ);
mutex_lock(&instance->completion_mutex);
instance->closing = 1;
up(&instance->insert_event);
mutex_unlock(&instance->completion_mutex);
up(&instance->remove_event);
i = 0;
while ((service = next_service_by_instance(state, instance,
&i)) != NULL) {
USER_SERVICE_T *user_service = service->base.userdata;
up(&user_service->remove_event);
vchiq_terminate_service_internal(service);
unlock_service(service);
}
i = 0;
while ((service = next_service_by_instance(state, instance, &i))
!= NULL) {
USER_SERVICE_T *user_service = service->base.userdata;
down(&service->remove_event);
BUG_ON(service->srvstate != VCHIQ_SRVSTATE_FREE);
spin_lock(&msg_queue_spinlock);
while (user_service->msg_remove !=
user_service->msg_insert) {
VCHIQ_HEADER_T *header = user_service->
msg_queue[user_service->msg_remove &
(MSG_QUEUE_SIZE - 1)];
user_service->msg_remove++;
spin_unlock(&msg_queue_spinlock);
if (header)
vchiq_release_message(
service->handle,
header);
spin_lock(&msg_queue_spinlock);
}
spin_unlock(&msg_queue_spinlock);
unlock_service(service);
}
while (instance->completion_remove !=
instance->completion_insert) {
VCHIQ_COMPLETION_DATA_T *completion;
VCHIQ_SERVICE_T *service;
completion = &instance->completions[
instance->completion_remove &
(MAX_COMPLETIONS - 1)];
service = completion->service_userdata;
if (completion->reason == VCHIQ_SERVICE_CLOSED)
{
USER_SERVICE_T *user_service =
service->base.userdata;
if (instance->use_close_delivered)
up(&user_service->close_event);
unlock_service(service);
}
instance->completion_remove++;
}
vchiq_release_internal(instance->state, NULL);
{
struct list_head *pos, *next;
list_for_each_safe(pos, next,
&instance->bulk_waiter_list) {
struct bulk_waiter_node *waiter;
waiter = list_entry(pos,
struct bulk_waiter_node,
list);
list_del(pos);
vchiq_log_info(vchiq_arm_log_level,
"bulk_waiter - cleaned up %pK for pid %d",
waiter, waiter->pid);
kfree(waiter);
}
}
vchiq_debugfs_remove_instance(instance);
kfree(instance);
file->private_data = NULL;
} break;
default:
vchiq_log_error(vchiq_arm_log_level,
"Unknown minor device: %d", dev);
ret = -ENXIO;
}
out:
return ret;
}
void
vchiq_dump(void *dump_context, const char *str, int len)
{
DUMP_CONTEXT_T *context = (DUMP_CONTEXT_T *)dump_context;
if (context->actual < context->space) {
int copy_bytes;
if (context->offset > 0) {
int skip_bytes = min(len, (int)context->offset);
str += skip_bytes;
len -= skip_bytes;
context->offset -= skip_bytes;
if (context->offset > 0)
return;
}
copy_bytes = min(len, (int)(context->space - context->actual));
if (copy_bytes == 0)
return;
if (copy_to_user(context->buf + context->actual, str,
copy_bytes))
context->actual = -EFAULT;
context->actual += copy_bytes;
len -= copy_bytes;
if ((len == 0) && (str[copy_bytes - 1] == '\0')) {
char cr = '\n';
if (copy_to_user(context->buf + context->actual - 1,
&cr, 1))
context->actual = -EFAULT;
}
}
}
void
vchiq_dump_platform_instances(void *dump_context)
{
VCHIQ_STATE_T *state = vchiq_get_state();
char buf[80];
int len;
int i;
for (i = 0; i < state->unused_service; i++) {
VCHIQ_SERVICE_T *service = state->services[i];
VCHIQ_INSTANCE_T instance;
if (service && (service->base.callback == service_callback)) {
instance = service->instance;
if (instance)
instance->mark = 0;
}
}
for (i = 0; i < state->unused_service; i++) {
VCHIQ_SERVICE_T *service = state->services[i];
VCHIQ_INSTANCE_T instance;
if (service && (service->base.callback == service_callback)) {
instance = service->instance;
if (instance && !instance->mark) {
len = snprintf(buf, sizeof(buf),
"Instance %pK: pid %d,%s completions %d/%d",
instance, instance->pid,
instance->connected ? " connected, " :
"",
instance->completion_insert -
instance->completion_remove,
MAX_COMPLETIONS);
vchiq_dump(dump_context, buf, len + 1);
instance->mark = 1;
}
}
}
}
void
vchiq_dump_platform_service_state(void *dump_context, VCHIQ_SERVICE_T *service)
{
USER_SERVICE_T *user_service = (USER_SERVICE_T *)service->base.userdata;
char buf[80];
int len;
len = snprintf(buf, sizeof(buf), " instance %pK", service->instance);
if ((service->base.callback == service_callback) &&
user_service->is_vchi) {
len += snprintf(buf + len, sizeof(buf) - len,
", %d/%d messages",
user_service->msg_insert - user_service->msg_remove,
MSG_QUEUE_SIZE);
if (user_service->dequeue_pending)
len += snprintf(buf + len, sizeof(buf) - len,
" (dequeue pending)");
}
vchiq_dump(dump_context, buf, len + 1);
}
static void
dump_phys_mem(void *virt_addr, u32 num_bytes)
{
int rc;
u8 *end_virt_addr = virt_addr + num_bytes;
int num_pages;
int offset;
int end_offset;
int page_idx;
int prev_idx;
struct page *page;
struct page **pages;
u8 *kmapped_virt_ptr;
virt_addr = (void *)((unsigned long)virt_addr & ~0x0fuL);
end_virt_addr = (void *)(((unsigned long)end_virt_addr + 15uL) &
~0x0fuL);
offset = (int)(long)virt_addr & (PAGE_SIZE - 1);
end_offset = (int)(long)end_virt_addr & (PAGE_SIZE - 1);
num_pages = DIV_ROUND_UP(offset + num_bytes, PAGE_SIZE);
pages = kmalloc(sizeof(struct page *) * num_pages, GFP_KERNEL);
if (!pages) {
vchiq_log_error(vchiq_arm_log_level,
"Unable to allocation memory for %d pages\n",
num_pages);
return;
}
down_read(&current->mm->mmap_sem);
rc = get_user_pages(
(unsigned long)virt_addr,
num_pages,
0,
pages,
NULL);
up_read(&current->mm->mmap_sem);
prev_idx = -1;
page = NULL;
if (rc < 0) {
vchiq_log_error(vchiq_arm_log_level,
"Failed to get user pages: %d\n", rc);
goto out;
}
while (offset < end_offset) {
int page_offset = offset % PAGE_SIZE;
page_idx = offset / PAGE_SIZE;
if (page_idx != prev_idx) {
if (page != NULL)
kunmap(page);
page = pages[page_idx];
kmapped_virt_ptr = kmap(page);
prev_idx = page_idx;
}
if (vchiq_arm_log_level >= VCHIQ_LOG_TRACE)
vchiq_log_dump_mem("ph",
(u32)(unsigned long)&kmapped_virt_ptr[
page_offset],
&kmapped_virt_ptr[page_offset], 16);
offset += 16;
}
out:
if (page != NULL)
kunmap(page);
for (page_idx = 0; page_idx < num_pages; page_idx++)
put_page(pages[page_idx]);
kfree(pages);
}
static ssize_t
vchiq_read(struct file *file, char __user *buf,
size_t count, loff_t *ppos)
{
DUMP_CONTEXT_T context;
context.buf = buf;
context.actual = 0;
context.space = count;
context.offset = *ppos;
vchiq_dump_state(&context, &g_state);
*ppos += context.actual;
return context.actual;
}
VCHIQ_STATE_T *
vchiq_get_state(void)
{
if (g_state.remote == NULL)
printk(KERN_ERR "%s: g_state.remote == NULL\n", __func__);
else if (g_state.remote->initialised != 1)
printk(KERN_NOTICE "%s: g_state.remote->initialised != 1 (%d)\n",
__func__, g_state.remote->initialised);
return ((g_state.remote != NULL) &&
(g_state.remote->initialised == 1)) ? &g_state : NULL;
}
int
vchiq_videocore_wanted(VCHIQ_STATE_T *state)
{
VCHIQ_ARM_STATE_T *arm_state = vchiq_platform_get_arm_state(state);
if (!arm_state)
return 1;
else if (arm_state->blocked_count)
return 1;
else if (!arm_state->videocore_use_count)
if (arm_state->resume_blocked)
return 0;
else
return vchiq_platform_videocore_wanted(state);
else
return 1;
}
static VCHIQ_STATUS_T
vchiq_keepalive_vchiq_callback(VCHIQ_REASON_T reason,
VCHIQ_HEADER_T *header,
VCHIQ_SERVICE_HANDLE_T service_user,
void *bulk_user)
{
vchiq_log_error(vchiq_susp_log_level,
"%s callback reason %d", __func__, reason);
return 0;
}
static int
vchiq_keepalive_thread_func(void *v)
{
VCHIQ_STATE_T *state = (VCHIQ_STATE_T *) v;
VCHIQ_ARM_STATE_T *arm_state = vchiq_platform_get_arm_state(state);
VCHIQ_STATUS_T status;
VCHIQ_INSTANCE_T instance;
VCHIQ_SERVICE_HANDLE_T ka_handle;
VCHIQ_SERVICE_PARAMS_T params = {
.fourcc = VCHIQ_MAKE_FOURCC('K', 'E', 'E', 'P'),
.callback = vchiq_keepalive_vchiq_callback,
.version = KEEPALIVE_VER,
.version_min = KEEPALIVE_VER_MIN
};
status = vchiq_initialise(&instance);
if (status != VCHIQ_SUCCESS) {
vchiq_log_error(vchiq_susp_log_level,
"%s vchiq_initialise failed %d", __func__, status);
goto exit;
}
status = vchiq_connect(instance);
if (status != VCHIQ_SUCCESS) {
vchiq_log_error(vchiq_susp_log_level,
"%s vchiq_connect failed %d", __func__, status);
goto shutdown;
}
status = vchiq_add_service(instance, &params, &ka_handle);
if (status != VCHIQ_SUCCESS) {
vchiq_log_error(vchiq_susp_log_level,
"%s vchiq_open_service failed %d", __func__, status);
goto shutdown;
}
while (1) {
long rc = 0, uc = 0;
if (wait_for_completion_interruptible(&arm_state->ka_evt)
!= 0) {
vchiq_log_error(vchiq_susp_log_level,
"%s interrupted", __func__);
flush_signals(current);
continue;
}
rc = atomic_xchg(&arm_state->ka_release_count, 0);
uc = atomic_xchg(&arm_state->ka_use_count, 0);
while (uc--) {
atomic_inc(&arm_state->ka_use_ack_count);
status = vchiq_use_service(ka_handle);
if (status != VCHIQ_SUCCESS) {
vchiq_log_error(vchiq_susp_log_level,
"%s vchiq_use_service error %d",
__func__, status);
}
}
while (rc--) {
status = vchiq_release_service(ka_handle);
if (status != VCHIQ_SUCCESS) {
vchiq_log_error(vchiq_susp_log_level,
"%s vchiq_release_service error %d",
__func__, status);
}
}
}
shutdown:
vchiq_shutdown(instance);
exit:
return 0;
}
VCHIQ_STATUS_T
vchiq_arm_init_state(VCHIQ_STATE_T *state, VCHIQ_ARM_STATE_T *arm_state)
{
if (arm_state) {
rwlock_init(&arm_state->susp_res_lock);
init_completion(&arm_state->ka_evt);
atomic_set(&arm_state->ka_use_count, 0);
atomic_set(&arm_state->ka_use_ack_count, 0);
atomic_set(&arm_state->ka_release_count, 0);
init_completion(&arm_state->vc_suspend_complete);
init_completion(&arm_state->vc_resume_complete);
set_resume_state(arm_state, VC_RESUME_RESUMED);
init_completion(&arm_state->resume_blocker);
complete_all(&arm_state->resume_blocker);
init_completion(&arm_state->blocked_blocker);
complete_all(&arm_state->blocked_blocker);
arm_state->suspend_timer_timeout = SUSPEND_TIMER_TIMEOUT_MS;
arm_state->suspend_timer_running = 0;
setup_timer(&arm_state->suspend_timer, suspend_timer_callback,
(unsigned long)(state));
arm_state->first_connect = 0;
}
return VCHIQ_SUCCESS;
}
void
set_suspend_state(VCHIQ_ARM_STATE_T *arm_state,
enum vc_suspend_status new_state)
{
arm_state->vc_suspend_state = new_state;
switch (new_state) {
case VC_SUSPEND_FORCE_CANCELED:
complete_all(&arm_state->vc_suspend_complete);
break;
case VC_SUSPEND_REJECTED:
complete_all(&arm_state->vc_suspend_complete);
break;
case VC_SUSPEND_FAILED:
complete_all(&arm_state->vc_suspend_complete);
arm_state->vc_resume_state = VC_RESUME_RESUMED;
complete_all(&arm_state->vc_resume_complete);
break;
case VC_SUSPEND_IDLE:
reinit_completion(&arm_state->vc_suspend_complete);
break;
case VC_SUSPEND_REQUESTED:
break;
case VC_SUSPEND_IN_PROGRESS:
set_resume_state(arm_state, VC_RESUME_IDLE);
break;
case VC_SUSPEND_SUSPENDED:
complete_all(&arm_state->vc_suspend_complete);
break;
default:
BUG();
break;
}
}
void
set_resume_state(VCHIQ_ARM_STATE_T *arm_state,
enum vc_resume_status new_state)
{
arm_state->vc_resume_state = new_state;
switch (new_state) {
case VC_RESUME_FAILED:
break;
case VC_RESUME_IDLE:
reinit_completion(&arm_state->vc_resume_complete);
break;
case VC_RESUME_REQUESTED:
break;
case VC_RESUME_IN_PROGRESS:
break;
case VC_RESUME_RESUMED:
complete_all(&arm_state->vc_resume_complete);
set_suspend_state(arm_state, VC_SUSPEND_IDLE);
break;
default:
BUG();
break;
}
}
inline void
start_suspend_timer(VCHIQ_ARM_STATE_T *arm_state)
{
del_timer(&arm_state->suspend_timer);
arm_state->suspend_timer.expires = jiffies +
msecs_to_jiffies(arm_state->
suspend_timer_timeout);
add_timer(&arm_state->suspend_timer);
arm_state->suspend_timer_running = 1;
}
static inline void
stop_suspend_timer(VCHIQ_ARM_STATE_T *arm_state)
{
if (arm_state->suspend_timer_running) {
del_timer(&arm_state->suspend_timer);
arm_state->suspend_timer_running = 0;
}
}
static inline int
need_resume(VCHIQ_STATE_T *state)
{
VCHIQ_ARM_STATE_T *arm_state = vchiq_platform_get_arm_state(state);
return (arm_state->vc_suspend_state > VC_SUSPEND_IDLE) &&
(arm_state->vc_resume_state < VC_RESUME_REQUESTED) &&
vchiq_videocore_wanted(state);
}
static int
block_resume(VCHIQ_ARM_STATE_T *arm_state)
{
int status = VCHIQ_SUCCESS;
const unsigned long timeout_val =
msecs_to_jiffies(FORCE_SUSPEND_TIMEOUT_MS);
int resume_count = 0;
if (arm_state->blocked_count) {
reinit_completion(&arm_state->blocked_blocker);
write_unlock_bh(&arm_state->susp_res_lock);
vchiq_log_info(vchiq_susp_log_level, "%s wait for previously "
"blocked clients", __func__);
if (wait_for_completion_interruptible_timeout(
&arm_state->blocked_blocker, timeout_val)
<= 0) {
vchiq_log_error(vchiq_susp_log_level, "%s wait for "
"previously blocked clients failed", __func__);
status = VCHIQ_ERROR;
write_lock_bh(&arm_state->susp_res_lock);
goto out;
}
vchiq_log_info(vchiq_susp_log_level, "%s previously blocked "
"clients resumed", __func__);
write_lock_bh(&arm_state->susp_res_lock);
}
while (arm_state->vc_resume_state != VC_RESUME_RESUMED &&
arm_state->vc_resume_state > VC_RESUME_IDLE) {
if (resume_count > 1) {
status = VCHIQ_ERROR;
vchiq_log_error(vchiq_susp_log_level, "%s waited too "
"many times for resume", __func__);
goto out;
}
write_unlock_bh(&arm_state->susp_res_lock);
vchiq_log_info(vchiq_susp_log_level, "%s wait for resume",
__func__);
if (wait_for_completion_interruptible_timeout(
&arm_state->vc_resume_complete, timeout_val)
<= 0) {
vchiq_log_error(vchiq_susp_log_level, "%s wait for "
"resume failed (%s)", __func__,
resume_state_names[arm_state->vc_resume_state +
VC_RESUME_NUM_OFFSET]);
status = VCHIQ_ERROR;
write_lock_bh(&arm_state->susp_res_lock);
goto out;
}
vchiq_log_info(vchiq_susp_log_level, "%s resumed", __func__);
write_lock_bh(&arm_state->susp_res_lock);
resume_count++;
}
reinit_completion(&arm_state->resume_blocker);
arm_state->resume_blocked = 1;
out:
return status;
}
static inline void
unblock_resume(VCHIQ_ARM_STATE_T *arm_state)
{
complete_all(&arm_state->resume_blocker);
arm_state->resume_blocked = 0;
}
VCHIQ_STATUS_T
vchiq_arm_vcsuspend(VCHIQ_STATE_T *state)
{
VCHIQ_STATUS_T status = VCHIQ_ERROR;
VCHIQ_ARM_STATE_T *arm_state = vchiq_platform_get_arm_state(state);
if (!arm_state)
goto out;
vchiq_log_trace(vchiq_susp_log_level, "%s", __func__);
status = VCHIQ_SUCCESS;
switch (arm_state->vc_suspend_state) {
case VC_SUSPEND_REQUESTED:
vchiq_log_info(vchiq_susp_log_level, "%s: suspend already "
"requested", __func__);
break;
case VC_SUSPEND_IN_PROGRESS:
vchiq_log_info(vchiq_susp_log_level, "%s: suspend already in "
"progress", __func__);
break;
default:
vchiq_log_error(vchiq_susp_log_level,
"%s unexpected suspend state %s", __func__,
suspend_state_names[arm_state->vc_suspend_state +
VC_SUSPEND_NUM_OFFSET]);
case VC_SUSPEND_REJECTED:
case VC_SUSPEND_FAILED:
set_suspend_state(arm_state, VC_SUSPEND_IDLE);
case VC_SUSPEND_IDLE:
vchiq_log_info(vchiq_susp_log_level,
"%s: suspending", __func__);
set_suspend_state(arm_state, VC_SUSPEND_REQUESTED);
request_poll(state, NULL, 0);
break;
}
out:
vchiq_log_trace(vchiq_susp_log_level, "%s exit %d", __func__, status);
return status;
}
void
vchiq_platform_check_suspend(VCHIQ_STATE_T *state)
{
VCHIQ_ARM_STATE_T *arm_state = vchiq_platform_get_arm_state(state);
int susp = 0;
if (!arm_state)
goto out;
vchiq_log_trace(vchiq_susp_log_level, "%s", __func__);
write_lock_bh(&arm_state->susp_res_lock);
if (arm_state->vc_suspend_state == VC_SUSPEND_REQUESTED &&
arm_state->vc_resume_state == VC_RESUME_RESUMED) {
set_suspend_state(arm_state, VC_SUSPEND_IN_PROGRESS);
susp = 1;
}
write_unlock_bh(&arm_state->susp_res_lock);
if (susp)
vchiq_platform_suspend(state);
out:
vchiq_log_trace(vchiq_susp_log_level, "%s exit", __func__);
return;
}
static void
output_timeout_error(VCHIQ_STATE_T *state)
{
VCHIQ_ARM_STATE_T *arm_state = vchiq_platform_get_arm_state(state);
char err[50] = "";
int vc_use_count = arm_state->videocore_use_count;
int active_services = state->unused_service;
int i;
if (!arm_state->videocore_use_count) {
snprintf(err, sizeof(err), " Videocore usecount is 0");
goto output_msg;
}
for (i = 0; i < active_services; i++) {
VCHIQ_SERVICE_T *service_ptr = state->services[i];
if (service_ptr && service_ptr->service_use_count &&
(service_ptr->srvstate != VCHIQ_SRVSTATE_FREE)) {
snprintf(err, sizeof(err), " %c%c%c%c(%d) service has "
"use count %d%s", VCHIQ_FOURCC_AS_4CHARS(
service_ptr->base.fourcc),
service_ptr->client_id,
service_ptr->service_use_count,
service_ptr->service_use_count ==
vc_use_count ? "" : " (+ more)");
break;
}
}
output_msg:
vchiq_log_error(vchiq_susp_log_level,
"timed out waiting for vc suspend (%d).%s",
arm_state->autosuspend_override, err);
}
VCHIQ_STATUS_T
vchiq_arm_force_suspend(VCHIQ_STATE_T *state)
{
VCHIQ_ARM_STATE_T *arm_state = vchiq_platform_get_arm_state(state);
VCHIQ_STATUS_T status = VCHIQ_ERROR;
long rc = 0;
int repeat = -1;
if (!arm_state)
goto out;
vchiq_log_trace(vchiq_susp_log_level, "%s", __func__);
write_lock_bh(&arm_state->susp_res_lock);
status = block_resume(arm_state);
if (status != VCHIQ_SUCCESS)
goto unlock;
if (arm_state->vc_suspend_state == VC_SUSPEND_SUSPENDED) {
vchiq_log_info(vchiq_susp_log_level, "%s already suspended",
__func__);
status = VCHIQ_SUCCESS;
goto unlock;
} else if (arm_state->vc_suspend_state <= VC_SUSPEND_IDLE) {
stop_suspend_timer(arm_state);
if (!vchiq_videocore_wanted(state)) {
vchiq_log_info(vchiq_susp_log_level, "%s videocore "
"idle, initiating suspend", __func__);
status = vchiq_arm_vcsuspend(state);
} else if (arm_state->autosuspend_override <
FORCE_SUSPEND_FAIL_MAX) {
vchiq_log_info(vchiq_susp_log_level, "%s letting "
"videocore go idle", __func__);
status = VCHIQ_SUCCESS;
} else {
vchiq_log_warning(vchiq_susp_log_level, "%s failed too "
"many times - attempting suspend", __func__);
status = vchiq_arm_vcsuspend(state);
}
} else {
vchiq_log_info(vchiq_susp_log_level, "%s videocore suspend "
"in progress - wait for completion", __func__);
status = VCHIQ_SUCCESS;
}
if (status != VCHIQ_SUCCESS)
goto unblock_resume;
do {
write_unlock_bh(&arm_state->susp_res_lock);
rc = wait_for_completion_interruptible_timeout(
&arm_state->vc_suspend_complete,
msecs_to_jiffies(FORCE_SUSPEND_TIMEOUT_MS));
write_lock_bh(&arm_state->susp_res_lock);
if (rc < 0) {
vchiq_log_warning(vchiq_susp_log_level, "%s "
"interrupted waiting for suspend", __func__);
status = VCHIQ_ERROR;
goto unblock_resume;
} else if (rc == 0) {
if (arm_state->vc_suspend_state > VC_SUSPEND_IDLE) {
if (repeat < 0) {
repeat = 1;
continue;
}
}
arm_state->autosuspend_override++;
output_timeout_error(state);
status = VCHIQ_RETRY;
goto unblock_resume;
}
} while (0 < (repeat--));
if (arm_state->vc_suspend_state != VC_SUSPEND_SUSPENDED) {
status = VCHIQ_RETRY;
vchiq_log_error(vchiq_susp_log_level,
"%s videocore suspend failed (state %s)", __func__,
suspend_state_names[arm_state->vc_suspend_state +
VC_SUSPEND_NUM_OFFSET]);
if (arm_state->vc_suspend_state < VC_SUSPEND_IDLE)
set_suspend_state(arm_state, VC_SUSPEND_IDLE);
goto unblock_resume;
}
goto unlock;
unblock_resume:
unblock_resume(arm_state);
unlock:
write_unlock_bh(&arm_state->susp_res_lock);
out:
vchiq_log_trace(vchiq_susp_log_level, "%s exit %d", __func__, status);
return status;
}
void
vchiq_check_suspend(VCHIQ_STATE_T *state)
{
VCHIQ_ARM_STATE_T *arm_state = vchiq_platform_get_arm_state(state);
if (!arm_state)
goto out;
vchiq_log_trace(vchiq_susp_log_level, "%s", __func__);
write_lock_bh(&arm_state->susp_res_lock);
if (arm_state->vc_suspend_state != VC_SUSPEND_SUSPENDED &&
arm_state->first_connect &&
!vchiq_videocore_wanted(state)) {
vchiq_arm_vcsuspend(state);
}
write_unlock_bh(&arm_state->susp_res_lock);
out:
vchiq_log_trace(vchiq_susp_log_level, "%s exit", __func__);
return;
}
int
vchiq_arm_allow_resume(VCHIQ_STATE_T *state)
{
VCHIQ_ARM_STATE_T *arm_state = vchiq_platform_get_arm_state(state);
int resume = 0;
int ret = -1;
if (!arm_state)
goto out;
vchiq_log_trace(vchiq_susp_log_level, "%s", __func__);
write_lock_bh(&arm_state->susp_res_lock);
unblock_resume(arm_state);
resume = vchiq_check_resume(state);
write_unlock_bh(&arm_state->susp_res_lock);
if (resume) {
if (wait_for_completion_interruptible(
&arm_state->vc_resume_complete) < 0) {
vchiq_log_error(vchiq_susp_log_level,
"%s interrupted", __func__);
goto out;
}
}
read_lock_bh(&arm_state->susp_res_lock);
if (arm_state->vc_suspend_state == VC_SUSPEND_SUSPENDED) {
vchiq_log_info(vchiq_susp_log_level,
"%s: Videocore remains suspended", __func__);
} else {
vchiq_log_info(vchiq_susp_log_level,
"%s: Videocore resumed", __func__);
ret = 0;
}
read_unlock_bh(&arm_state->susp_res_lock);
out:
vchiq_log_trace(vchiq_susp_log_level, "%s exit %d", __func__, ret);
return ret;
}
int
vchiq_check_resume(VCHIQ_STATE_T *state)
{
VCHIQ_ARM_STATE_T *arm_state = vchiq_platform_get_arm_state(state);
int resume = 0;
if (!arm_state)
goto out;
vchiq_log_trace(vchiq_susp_log_level, "%s", __func__);
if (need_resume(state)) {
set_resume_state(arm_state, VC_RESUME_REQUESTED);
request_poll(state, NULL, 0);
resume = 1;
}
out:
vchiq_log_trace(vchiq_susp_log_level, "%s exit", __func__);
return resume;
}
VCHIQ_STATUS_T
vchiq_use_internal(VCHIQ_STATE_T *state, VCHIQ_SERVICE_T *service,
enum USE_TYPE_E use_type)
{
VCHIQ_ARM_STATE_T *arm_state = vchiq_platform_get_arm_state(state);
VCHIQ_STATUS_T ret = VCHIQ_SUCCESS;
char entity[16];
int *entity_uc;
int local_uc, local_entity_uc;
if (!arm_state)
goto out;
vchiq_log_trace(vchiq_susp_log_level, "%s", __func__);
if (use_type == USE_TYPE_VCHIQ) {
sprintf(entity, "VCHIQ: ");
entity_uc = &arm_state->peer_use_count;
} else if (service) {
sprintf(entity, "%c%c%c%c:%03d",
VCHIQ_FOURCC_AS_4CHARS(service->base.fourcc),
service->client_id);
entity_uc = &service->service_use_count;
} else {
vchiq_log_error(vchiq_susp_log_level, "%s null service "
"ptr", __func__);
ret = VCHIQ_ERROR;
goto out;
}
write_lock_bh(&arm_state->susp_res_lock);
while (arm_state->resume_blocked) {
if (arm_state->resume_blocked && arm_state->vc_suspend_state ==
VC_SUSPEND_IDLE) {
set_suspend_state(arm_state, VC_SUSPEND_FORCE_CANCELED);
break;
}
if (!try_wait_for_completion(&arm_state->resume_blocker)) {
arm_state->blocked_count++;
write_unlock_bh(&arm_state->susp_res_lock);
vchiq_log_info(vchiq_susp_log_level, "%s %s resume "
"blocked - waiting...", __func__, entity);
if (wait_for_completion_killable(
&arm_state->resume_blocker) != 0) {
vchiq_log_error(vchiq_susp_log_level, "%s %s "
"wait for resume blocker interrupted",
__func__, entity);
ret = VCHIQ_ERROR;
write_lock_bh(&arm_state->susp_res_lock);
arm_state->blocked_count--;
write_unlock_bh(&arm_state->susp_res_lock);
goto out;
}
vchiq_log_info(vchiq_susp_log_level, "%s %s resume "
"unblocked", __func__, entity);
write_lock_bh(&arm_state->susp_res_lock);
if (--arm_state->blocked_count == 0)
complete_all(&arm_state->blocked_blocker);
}
}
stop_suspend_timer(arm_state);
local_uc = ++arm_state->videocore_use_count;
local_entity_uc = ++(*entity_uc);
if (arm_state->vc_suspend_state <= VC_SUSPEND_REQUESTED)
set_suspend_state(arm_state, VC_SUSPEND_IDLE);
if ((use_type != USE_TYPE_SERVICE_NO_RESUME) && need_resume(state)) {
set_resume_state(arm_state, VC_RESUME_REQUESTED);
vchiq_log_info(vchiq_susp_log_level,
"%s %s count %d, state count %d",
__func__, entity, local_entity_uc, local_uc);
request_poll(state, NULL, 0);
} else
vchiq_log_trace(vchiq_susp_log_level,
"%s %s count %d, state count %d",
__func__, entity, *entity_uc, local_uc);
write_unlock_bh(&arm_state->susp_res_lock);
if (!try_wait_for_completion(&arm_state->vc_resume_complete)) {
vchiq_log_info(vchiq_susp_log_level, "%s %s wait for resume",
__func__, entity);
if (wait_for_completion_killable(
&arm_state->vc_resume_complete) != 0) {
vchiq_log_error(vchiq_susp_log_level, "%s %s wait for "
"resume interrupted", __func__, entity);
ret = VCHIQ_ERROR;
goto out;
}
vchiq_log_info(vchiq_susp_log_level, "%s %s resumed", __func__,
entity);
}
if (ret == VCHIQ_SUCCESS) {
VCHIQ_STATUS_T status = VCHIQ_SUCCESS;
long ack_cnt = atomic_xchg(&arm_state->ka_use_ack_count, 0);
while (ack_cnt && (status == VCHIQ_SUCCESS)) {
status = vchiq_send_remote_use_active(state);
if (status == VCHIQ_SUCCESS)
ack_cnt--;
else
atomic_add(ack_cnt,
&arm_state->ka_use_ack_count);
}
}
out:
vchiq_log_trace(vchiq_susp_log_level, "%s exit %d", __func__, ret);
return ret;
}
VCHIQ_STATUS_T
vchiq_release_internal(VCHIQ_STATE_T *state, VCHIQ_SERVICE_T *service)
{
VCHIQ_ARM_STATE_T *arm_state = vchiq_platform_get_arm_state(state);
VCHIQ_STATUS_T ret = VCHIQ_SUCCESS;
char entity[16];
int *entity_uc;
int local_uc, local_entity_uc;
if (!arm_state)
goto out;
vchiq_log_trace(vchiq_susp_log_level, "%s", __func__);
if (service) {
sprintf(entity, "%c%c%c%c:%03d",
VCHIQ_FOURCC_AS_4CHARS(service->base.fourcc),
service->client_id);
entity_uc = &service->service_use_count;
} else {
sprintf(entity, "PEER: ");
entity_uc = &arm_state->peer_use_count;
}
write_lock_bh(&arm_state->susp_res_lock);
if (!arm_state->videocore_use_count || !(*entity_uc)) {
WARN_ON(!arm_state->videocore_use_count);
WARN_ON(!(*entity_uc));
ret = VCHIQ_ERROR;
goto unlock;
}
local_uc = --arm_state->videocore_use_count;
local_entity_uc = --(*entity_uc);
if (!vchiq_videocore_wanted(state)) {
if (vchiq_platform_use_suspend_timer() &&
!arm_state->resume_blocked) {
start_suspend_timer(arm_state);
} else {
vchiq_log_info(vchiq_susp_log_level,
"%s %s count %d, state count %d - suspending",
__func__, entity, *entity_uc,
arm_state->videocore_use_count);
vchiq_arm_vcsuspend(state);
}
} else
vchiq_log_trace(vchiq_susp_log_level,
"%s %s count %d, state count %d",
__func__, entity, *entity_uc,
arm_state->videocore_use_count);
unlock:
write_unlock_bh(&arm_state->susp_res_lock);
out:
vchiq_log_trace(vchiq_susp_log_level, "%s exit %d", __func__, ret);
return ret;
}
void
vchiq_on_remote_use(VCHIQ_STATE_T *state)
{
VCHIQ_ARM_STATE_T *arm_state = vchiq_platform_get_arm_state(state);
vchiq_log_trace(vchiq_susp_log_level, "%s", __func__);
atomic_inc(&arm_state->ka_use_count);
complete(&arm_state->ka_evt);
}
void
vchiq_on_remote_release(VCHIQ_STATE_T *state)
{
VCHIQ_ARM_STATE_T *arm_state = vchiq_platform_get_arm_state(state);
vchiq_log_trace(vchiq_susp_log_level, "%s", __func__);
atomic_inc(&arm_state->ka_release_count);
complete(&arm_state->ka_evt);
}
VCHIQ_STATUS_T
vchiq_use_service_internal(VCHIQ_SERVICE_T *service)
{
return vchiq_use_internal(service->state, service, USE_TYPE_SERVICE);
}
VCHIQ_STATUS_T
vchiq_release_service_internal(VCHIQ_SERVICE_T *service)
{
return vchiq_release_internal(service->state, service);
}
VCHIQ_DEBUGFS_NODE_T *
vchiq_instance_get_debugfs_node(VCHIQ_INSTANCE_T instance)
{
return &instance->debugfs_node;
}
int
vchiq_instance_get_use_count(VCHIQ_INSTANCE_T instance)
{
VCHIQ_SERVICE_T *service;
int use_count = 0, i;
i = 0;
while ((service = next_service_by_instance(instance->state,
instance, &i)) != NULL) {
use_count += service->service_use_count;
unlock_service(service);
}
return use_count;
}
int
vchiq_instance_get_pid(VCHIQ_INSTANCE_T instance)
{
return instance->pid;
}
int
vchiq_instance_get_trace(VCHIQ_INSTANCE_T instance)
{
return instance->trace;
}
void
vchiq_instance_set_trace(VCHIQ_INSTANCE_T instance, int trace)
{
VCHIQ_SERVICE_T *service;
int i;
i = 0;
while ((service = next_service_by_instance(instance->state,
instance, &i)) != NULL) {
service->trace = trace;
unlock_service(service);
}
instance->trace = (trace != 0);
}
static void suspend_timer_callback(unsigned long context)
{
VCHIQ_STATE_T *state = (VCHIQ_STATE_T *)context;
VCHIQ_ARM_STATE_T *arm_state = vchiq_platform_get_arm_state(state);
if (!arm_state)
goto out;
vchiq_log_info(vchiq_susp_log_level,
"%s - suspend timer expired - check suspend", __func__);
vchiq_check_suspend(state);
out:
return;
}
VCHIQ_STATUS_T
vchiq_use_service_no_resume(VCHIQ_SERVICE_HANDLE_T handle)
{
VCHIQ_STATUS_T ret = VCHIQ_ERROR;
VCHIQ_SERVICE_T *service = find_service_by_handle(handle);
if (service) {
ret = vchiq_use_internal(service->state, service,
USE_TYPE_SERVICE_NO_RESUME);
unlock_service(service);
}
return ret;
}
VCHIQ_STATUS_T
vchiq_use_service(VCHIQ_SERVICE_HANDLE_T handle)
{
VCHIQ_STATUS_T ret = VCHIQ_ERROR;
VCHIQ_SERVICE_T *service = find_service_by_handle(handle);
if (service) {
ret = vchiq_use_internal(service->state, service,
USE_TYPE_SERVICE);
unlock_service(service);
}
return ret;
}
VCHIQ_STATUS_T
vchiq_release_service(VCHIQ_SERVICE_HANDLE_T handle)
{
VCHIQ_STATUS_T ret = VCHIQ_ERROR;
VCHIQ_SERVICE_T *service = find_service_by_handle(handle);
if (service) {
ret = vchiq_release_internal(service->state, service);
unlock_service(service);
}
return ret;
}
void
vchiq_dump_service_use_state(VCHIQ_STATE_T *state)
{
VCHIQ_ARM_STATE_T *arm_state = vchiq_platform_get_arm_state(state);
int i, j = 0;
static const int local_max_services = 64;
int only_nonzero = 0;
static const char *nz = "<-- preventing suspend";
enum vc_suspend_status vc_suspend_state;
enum vc_resume_status vc_resume_state;
int peer_count;
int vc_use_count;
int active_services;
struct service_data_struct {
int fourcc;
int clientid;
int use_count;
} service_data[local_max_services];
if (!arm_state)
return;
read_lock_bh(&arm_state->susp_res_lock);
vc_suspend_state = arm_state->vc_suspend_state;
vc_resume_state = arm_state->vc_resume_state;
peer_count = arm_state->peer_use_count;
vc_use_count = arm_state->videocore_use_count;
active_services = state->unused_service;
if (active_services > local_max_services)
only_nonzero = 1;
for (i = 0; (i < active_services) && (j < local_max_services); i++) {
VCHIQ_SERVICE_T *service_ptr = state->services[i];
if (!service_ptr)
continue;
if (only_nonzero && !service_ptr->service_use_count)
continue;
if (service_ptr->srvstate == VCHIQ_SRVSTATE_FREE)
continue;
service_data[j].fourcc = service_ptr->base.fourcc;
service_data[j].clientid = service_ptr->client_id;
service_data[j++].use_count = service_ptr->service_use_count;
}
read_unlock_bh(&arm_state->susp_res_lock);
vchiq_log_warning(vchiq_susp_log_level,
"-- Videcore suspend state: %s --",
suspend_state_names[vc_suspend_state + VC_SUSPEND_NUM_OFFSET]);
vchiq_log_warning(vchiq_susp_log_level,
"-- Videcore resume state: %s --",
resume_state_names[vc_resume_state + VC_RESUME_NUM_OFFSET]);
if (only_nonzero)
vchiq_log_warning(vchiq_susp_log_level, "Too many active "
"services (%d). Only dumping up to first %d services "
"with non-zero use-count", active_services,
local_max_services);
for (i = 0; i < j; i++) {
vchiq_log_warning(vchiq_susp_log_level,
"----- %c%c%c%c:%d service count %d %s",
VCHIQ_FOURCC_AS_4CHARS(service_data[i].fourcc),
service_data[i].clientid,
service_data[i].use_count,
service_data[i].use_count ? nz : "");
}
vchiq_log_warning(vchiq_susp_log_level,
"----- VCHIQ use count count %d", peer_count);
vchiq_log_warning(vchiq_susp_log_level,
"--- Overall vchiq instance use count %d", vc_use_count);
vchiq_dump_platform_use_state(state);
}
VCHIQ_STATUS_T
vchiq_check_service(VCHIQ_SERVICE_T *service)
{
VCHIQ_ARM_STATE_T *arm_state;
VCHIQ_STATUS_T ret = VCHIQ_ERROR;
if (!service || !service->state)
goto out;
vchiq_log_trace(vchiq_susp_log_level, "%s", __func__);
arm_state = vchiq_platform_get_arm_state(service->state);
read_lock_bh(&arm_state->susp_res_lock);
if (service->service_use_count)
ret = VCHIQ_SUCCESS;
read_unlock_bh(&arm_state->susp_res_lock);
if (ret == VCHIQ_ERROR) {
vchiq_log_error(vchiq_susp_log_level,
"%s ERROR - %c%c%c%c:%d service count %d, "
"state count %d, videocore suspend state %s", __func__,
VCHIQ_FOURCC_AS_4CHARS(service->base.fourcc),
service->client_id, service->service_use_count,
arm_state->videocore_use_count,
suspend_state_names[arm_state->vc_suspend_state +
VC_SUSPEND_NUM_OFFSET]);
vchiq_dump_service_use_state(service->state);
}
out:
return ret;
}
void vchiq_on_remote_use_active(VCHIQ_STATE_T *state)
{
(void)state;
}
void vchiq_platform_conn_state_changed(VCHIQ_STATE_T *state,
VCHIQ_CONNSTATE_T oldstate, VCHIQ_CONNSTATE_T newstate)
{
VCHIQ_ARM_STATE_T *arm_state = vchiq_platform_get_arm_state(state);
vchiq_log_info(vchiq_susp_log_level, "%d: %s->%s", state->id,
get_conn_state_name(oldstate), get_conn_state_name(newstate));
if (state->conn_state == VCHIQ_CONNSTATE_CONNECTED) {
write_lock_bh(&arm_state->susp_res_lock);
if (!arm_state->first_connect) {
char threadname[16];
arm_state->first_connect = 1;
write_unlock_bh(&arm_state->susp_res_lock);
snprintf(threadname, sizeof(threadname), "vchiq-keep/%d",
state->id);
arm_state->ka_thread = kthread_create(
&vchiq_keepalive_thread_func,
(void *)state,
threadname);
if (IS_ERR(arm_state->ka_thread)) {
vchiq_log_error(vchiq_susp_log_level,
"vchiq: FATAL: couldn't create thread %s",
threadname);
} else {
wake_up_process(arm_state->ka_thread);
}
} else
write_unlock_bh(&arm_state->susp_res_lock);
}
}
static int vchiq_probe(struct platform_device *pdev)
{
struct device_node *fw_node;
struct rpi_firmware *fw;
int err;
fw_node = of_parse_phandle(pdev->dev.of_node, "firmware", 0);
if (!fw_node) {
dev_err(&pdev->dev, "Missing firmware node\n");
return -ENOENT;
}
fw = rpi_firmware_get(fw_node);
of_node_put(fw_node);
if (!fw)
return -EPROBE_DEFER;
platform_set_drvdata(pdev, fw);
err = vchiq_platform_init(pdev, &g_state);
if (err != 0)
goto failed_platform_init;
err = alloc_chrdev_region(&vchiq_devid, VCHIQ_MINOR, 1, DEVICE_NAME);
if (err != 0) {
vchiq_log_error(vchiq_arm_log_level,
"Unable to allocate device number");
goto failed_platform_init;
}
cdev_init(&vchiq_cdev, &vchiq_fops);
vchiq_cdev.owner = THIS_MODULE;
err = cdev_add(&vchiq_cdev, vchiq_devid, 1);
if (err != 0) {
vchiq_log_error(vchiq_arm_log_level,
"Unable to register device");
goto failed_cdev_add;
}
vchiq_class = class_create(THIS_MODULE, DEVICE_NAME);
err = PTR_ERR(vchiq_class);
if (IS_ERR(vchiq_class))
goto failed_class_create;
vchiq_dev = device_create(vchiq_class, NULL,
vchiq_devid, NULL, "vchiq");
err = PTR_ERR(vchiq_dev);
if (IS_ERR(vchiq_dev))
goto failed_device_create;
err = vchiq_debugfs_init();
if (err != 0)
goto failed_debugfs_init;
vchiq_log_info(vchiq_arm_log_level,
"vchiq: initialised - version %d (min %d), device %d.%d",
VCHIQ_VERSION, VCHIQ_VERSION_MIN,
MAJOR(vchiq_devid), MINOR(vchiq_devid));
return 0;
failed_debugfs_init:
device_destroy(vchiq_class, vchiq_devid);
failed_device_create:
class_destroy(vchiq_class);
failed_class_create:
cdev_del(&vchiq_cdev);
failed_cdev_add:
unregister_chrdev_region(vchiq_devid, 1);
failed_platform_init:
vchiq_log_warning(vchiq_arm_log_level, "could not load vchiq");
return err;
}
static int vchiq_remove(struct platform_device *pdev)
{
vchiq_debugfs_deinit();
device_destroy(vchiq_class, vchiq_devid);
class_destroy(vchiq_class);
cdev_del(&vchiq_cdev);
unregister_chrdev_region(vchiq_devid, 1);
return 0;
}
