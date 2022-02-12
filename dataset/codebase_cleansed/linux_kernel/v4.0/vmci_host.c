bool vmci_host_code_active(void)
{
return vmci_host_device_initialized &&
(!vmci_guest_code_active() ||
atomic_read(&vmci_host_active_users) > 0);
}
static int vmci_host_open(struct inode *inode, struct file *filp)
{
struct vmci_host_dev *vmci_host_dev;
vmci_host_dev = kzalloc(sizeof(struct vmci_host_dev), GFP_KERNEL);
if (vmci_host_dev == NULL)
return -ENOMEM;
vmci_host_dev->ct_type = VMCIOBJ_NOT_SET;
mutex_init(&vmci_host_dev->lock);
filp->private_data = vmci_host_dev;
return 0;
}
static int vmci_host_close(struct inode *inode, struct file *filp)
{
struct vmci_host_dev *vmci_host_dev = filp->private_data;
if (vmci_host_dev->ct_type == VMCIOBJ_CONTEXT) {
vmci_ctx_destroy(vmci_host_dev->context);
vmci_host_dev->context = NULL;
atomic_dec(&vmci_host_active_users);
}
vmci_host_dev->ct_type = VMCIOBJ_NOT_SET;
kfree(vmci_host_dev);
filp->private_data = NULL;
return 0;
}
static unsigned int vmci_host_poll(struct file *filp, poll_table *wait)
{
struct vmci_host_dev *vmci_host_dev = filp->private_data;
struct vmci_ctx *context = vmci_host_dev->context;
unsigned int mask = 0;
if (vmci_host_dev->ct_type == VMCIOBJ_CONTEXT) {
if (wait)
poll_wait(filp, &context->host_context.wait_queue,
wait);
spin_lock(&context->lock);
if (context->pending_datagrams > 0 ||
vmci_handle_arr_get_size(
context->pending_doorbell_array) > 0) {
mask = POLLIN;
}
spin_unlock(&context->lock);
}
return mask;
}
static int drv_cp_harray_to_user(void __user *user_buf_uva,
u64 *user_buf_size,
struct vmci_handle_arr *handle_array,
int *retval)
{
u32 array_size = 0;
struct vmci_handle *handles;
if (handle_array)
array_size = vmci_handle_arr_get_size(handle_array);
if (array_size * sizeof(*handles) > *user_buf_size)
return VMCI_ERROR_MORE_DATA;
*user_buf_size = array_size * sizeof(*handles);
if (*user_buf_size)
*retval = copy_to_user(user_buf_uva,
vmci_handle_arr_get_handles
(handle_array), *user_buf_size);
return VMCI_SUCCESS;
}
static int vmci_host_setup_notify(struct vmci_ctx *context,
unsigned long uva)
{
int retval;
if (context->notify_page) {
pr_devel("%s: Notify mechanism is already set up\n", __func__);
return VMCI_ERROR_DUPLICATE_ENTRY;
}
BUILD_BUG_ON(sizeof(bool) != sizeof(u8));
if (!access_ok(VERIFY_WRITE, (void __user *)uva, sizeof(u8)))
return VMCI_ERROR_GENERIC;
retval = get_user_pages_fast(uva, 1, 1, &context->notify_page);
if (retval != 1) {
context->notify_page = NULL;
return VMCI_ERROR_GENERIC;
}
context->notify = kmap(context->notify_page) + (uva & (PAGE_SIZE - 1));
vmci_ctx_check_signal_notify(context);
return VMCI_SUCCESS;
}
static int vmci_host_get_version(struct vmci_host_dev *vmci_host_dev,
unsigned int cmd, void __user *uptr)
{
if (cmd == IOCTL_VMCI_VERSION2) {
int __user *vptr = uptr;
if (get_user(vmci_host_dev->user_version, vptr))
return -EFAULT;
}
if (vmci_host_dev->user_version > 0 &&
vmci_host_dev->user_version < VMCI_VERSION_HOSTQP) {
return vmci_host_dev->user_version;
}
return VMCI_VERSION;
}
static int vmci_host_do_init_context(struct vmci_host_dev *vmci_host_dev,
const char *ioctl_name,
void __user *uptr)
{
struct vmci_init_blk init_block;
const struct cred *cred;
int retval;
if (copy_from_user(&init_block, uptr, sizeof(init_block))) {
vmci_ioctl_err("error reading init block\n");
return -EFAULT;
}
mutex_lock(&vmci_host_dev->lock);
if (vmci_host_dev->ct_type != VMCIOBJ_NOT_SET) {
vmci_ioctl_err("received VMCI init on initialized handle\n");
retval = -EINVAL;
goto out;
}
if (init_block.flags & ~VMCI_PRIVILEGE_FLAG_RESTRICTED) {
vmci_ioctl_err("unsupported VMCI restriction flag\n");
retval = -EINVAL;
goto out;
}
cred = get_current_cred();
vmci_host_dev->context = vmci_ctx_create(init_block.cid,
init_block.flags, 0,
vmci_host_dev->user_version,
cred);
put_cred(cred);
if (IS_ERR(vmci_host_dev->context)) {
retval = PTR_ERR(vmci_host_dev->context);
vmci_ioctl_err("error initializing context\n");
goto out;
}
init_block.cid = vmci_ctx_get_id(vmci_host_dev->context);
if (copy_to_user(uptr, &init_block, sizeof(init_block))) {
vmci_ctx_destroy(vmci_host_dev->context);
vmci_host_dev->context = NULL;
vmci_ioctl_err("error writing init block\n");
retval = -EFAULT;
goto out;
}
vmci_host_dev->ct_type = VMCIOBJ_CONTEXT;
atomic_inc(&vmci_host_active_users);
retval = 0;
out:
mutex_unlock(&vmci_host_dev->lock);
return retval;
}
static int vmci_host_do_send_datagram(struct vmci_host_dev *vmci_host_dev,
const char *ioctl_name,
void __user *uptr)
{
struct vmci_datagram_snd_rcv_info send_info;
struct vmci_datagram *dg = NULL;
u32 cid;
if (vmci_host_dev->ct_type != VMCIOBJ_CONTEXT) {
vmci_ioctl_err("only valid for contexts\n");
return -EINVAL;
}
if (copy_from_user(&send_info, uptr, sizeof(send_info)))
return -EFAULT;
if (send_info.len > VMCI_MAX_DG_SIZE) {
vmci_ioctl_err("datagram is too big (size=%d)\n",
send_info.len);
return -EINVAL;
}
if (send_info.len < sizeof(*dg)) {
vmci_ioctl_err("datagram is too small (size=%d)\n",
send_info.len);
return -EINVAL;
}
dg = kmalloc(send_info.len, GFP_KERNEL);
if (!dg) {
vmci_ioctl_err(
"cannot allocate memory to dispatch datagram\n");
return -ENOMEM;
}
if (copy_from_user(dg, (void __user *)(uintptr_t)send_info.addr,
send_info.len)) {
vmci_ioctl_err("error getting datagram\n");
kfree(dg);
return -EFAULT;
}
pr_devel("Datagram dst (handle=0x%x:0x%x) src (handle=0x%x:0x%x), payload (size=%llu bytes)\n",
dg->dst.context, dg->dst.resource,
dg->src.context, dg->src.resource,
(unsigned long long)dg->payload_size);
cid = vmci_ctx_get_id(vmci_host_dev->context);
send_info.result = vmci_datagram_dispatch(cid, dg, true);
kfree(dg);
return copy_to_user(uptr, &send_info, sizeof(send_info)) ? -EFAULT : 0;
}
static int vmci_host_do_receive_datagram(struct vmci_host_dev *vmci_host_dev,
const char *ioctl_name,
void __user *uptr)
{
struct vmci_datagram_snd_rcv_info recv_info;
struct vmci_datagram *dg = NULL;
int retval;
size_t size;
if (vmci_host_dev->ct_type != VMCIOBJ_CONTEXT) {
vmci_ioctl_err("only valid for contexts\n");
return -EINVAL;
}
if (copy_from_user(&recv_info, uptr, sizeof(recv_info)))
return -EFAULT;
size = recv_info.len;
recv_info.result = vmci_ctx_dequeue_datagram(vmci_host_dev->context,
&size, &dg);
if (recv_info.result >= VMCI_SUCCESS) {
void __user *ubuf = (void __user *)(uintptr_t)recv_info.addr;
retval = copy_to_user(ubuf, dg, VMCI_DG_SIZE(dg));
kfree(dg);
if (retval != 0)
return -EFAULT;
}
return copy_to_user(uptr, &recv_info, sizeof(recv_info)) ? -EFAULT : 0;
}
static int vmci_host_do_alloc_queuepair(struct vmci_host_dev *vmci_host_dev,
const char *ioctl_name,
void __user *uptr)
{
struct vmci_handle handle;
int vmci_status;
int __user *retptr;
u32 cid;
if (vmci_host_dev->ct_type != VMCIOBJ_CONTEXT) {
vmci_ioctl_err("only valid for contexts\n");
return -EINVAL;
}
cid = vmci_ctx_get_id(vmci_host_dev->context);
if (vmci_host_dev->user_version < VMCI_VERSION_NOVMVM) {
struct vmci_qp_alloc_info_vmvm alloc_info;
struct vmci_qp_alloc_info_vmvm __user *info = uptr;
if (copy_from_user(&alloc_info, uptr, sizeof(alloc_info)))
return -EFAULT;
handle = alloc_info.handle;
retptr = &info->result;
vmci_status = vmci_qp_broker_alloc(alloc_info.handle,
alloc_info.peer,
alloc_info.flags,
VMCI_NO_PRIVILEGE_FLAGS,
alloc_info.produce_size,
alloc_info.consume_size,
NULL,
vmci_host_dev->context);
if (vmci_status == VMCI_SUCCESS)
vmci_status = VMCI_SUCCESS_QUEUEPAIR_CREATE;
} else {
struct vmci_qp_alloc_info alloc_info;
struct vmci_qp_alloc_info __user *info = uptr;
struct vmci_qp_page_store page_store;
if (copy_from_user(&alloc_info, uptr, sizeof(alloc_info)))
return -EFAULT;
handle = alloc_info.handle;
retptr = &info->result;
page_store.pages = alloc_info.ppn_va;
page_store.len = alloc_info.num_ppns;
vmci_status = vmci_qp_broker_alloc(alloc_info.handle,
alloc_info.peer,
alloc_info.flags,
VMCI_NO_PRIVILEGE_FLAGS,
alloc_info.produce_size,
alloc_info.consume_size,
&page_store,
vmci_host_dev->context);
}
if (put_user(vmci_status, retptr)) {
if (vmci_status >= VMCI_SUCCESS) {
vmci_status = vmci_qp_broker_detach(handle,
vmci_host_dev->context);
}
return -EFAULT;
}
return 0;
}
static int vmci_host_do_queuepair_setva(struct vmci_host_dev *vmci_host_dev,
const char *ioctl_name,
void __user *uptr)
{
struct vmci_qp_set_va_info set_va_info;
struct vmci_qp_set_va_info __user *info = uptr;
s32 result;
if (vmci_host_dev->ct_type != VMCIOBJ_CONTEXT) {
vmci_ioctl_err("only valid for contexts\n");
return -EINVAL;
}
if (vmci_host_dev->user_version < VMCI_VERSION_NOVMVM) {
vmci_ioctl_err("is not allowed\n");
return -EINVAL;
}
if (copy_from_user(&set_va_info, uptr, sizeof(set_va_info)))
return -EFAULT;
if (set_va_info.va) {
result = vmci_qp_broker_map(set_va_info.handle,
vmci_host_dev->context,
set_va_info.va);
} else {
result = vmci_qp_broker_unmap(set_va_info.handle,
vmci_host_dev->context, 0);
}
return put_user(result, &info->result) ? -EFAULT : 0;
}
static int vmci_host_do_queuepair_setpf(struct vmci_host_dev *vmci_host_dev,
const char *ioctl_name,
void __user *uptr)
{
struct vmci_qp_page_file_info page_file_info;
struct vmci_qp_page_file_info __user *info = uptr;
s32 result;
if (vmci_host_dev->user_version < VMCI_VERSION_HOSTQP ||
vmci_host_dev->user_version >= VMCI_VERSION_NOVMVM) {
vmci_ioctl_err("not supported on this VMX (version=%d)\n",
vmci_host_dev->user_version);
return -EINVAL;
}
if (vmci_host_dev->ct_type != VMCIOBJ_CONTEXT) {
vmci_ioctl_err("only valid for contexts\n");
return -EINVAL;
}
if (copy_from_user(&page_file_info, uptr, sizeof(*info)))
return -EFAULT;
if (put_user(VMCI_SUCCESS, &info->result)) {
return -EFAULT;
}
result = vmci_qp_broker_set_page_store(page_file_info.handle,
page_file_info.produce_va,
page_file_info.consume_va,
vmci_host_dev->context);
if (result < VMCI_SUCCESS) {
if (put_user(result, &info->result)) {
return -EFAULT;
}
}
return 0;
}
static int vmci_host_do_qp_detach(struct vmci_host_dev *vmci_host_dev,
const char *ioctl_name,
void __user *uptr)
{
struct vmci_qp_dtch_info detach_info;
struct vmci_qp_dtch_info __user *info = uptr;
s32 result;
if (vmci_host_dev->ct_type != VMCIOBJ_CONTEXT) {
vmci_ioctl_err("only valid for contexts\n");
return -EINVAL;
}
if (copy_from_user(&detach_info, uptr, sizeof(detach_info)))
return -EFAULT;
result = vmci_qp_broker_detach(detach_info.handle,
vmci_host_dev->context);
if (result == VMCI_SUCCESS &&
vmci_host_dev->user_version < VMCI_VERSION_NOVMVM) {
result = VMCI_SUCCESS_LAST_DETACH;
}
return put_user(result, &info->result) ? -EFAULT : 0;
}
static int vmci_host_do_ctx_add_notify(struct vmci_host_dev *vmci_host_dev,
const char *ioctl_name,
void __user *uptr)
{
struct vmci_ctx_info ar_info;
struct vmci_ctx_info __user *info = uptr;
s32 result;
u32 cid;
if (vmci_host_dev->ct_type != VMCIOBJ_CONTEXT) {
vmci_ioctl_err("only valid for contexts\n");
return -EINVAL;
}
if (copy_from_user(&ar_info, uptr, sizeof(ar_info)))
return -EFAULT;
cid = vmci_ctx_get_id(vmci_host_dev->context);
result = vmci_ctx_add_notification(cid, ar_info.remote_cid);
return put_user(result, &info->result) ? -EFAULT : 0;
}
static int vmci_host_do_ctx_remove_notify(struct vmci_host_dev *vmci_host_dev,
const char *ioctl_name,
void __user *uptr)
{
struct vmci_ctx_info ar_info;
struct vmci_ctx_info __user *info = uptr;
u32 cid;
int result;
if (vmci_host_dev->ct_type != VMCIOBJ_CONTEXT) {
vmci_ioctl_err("only valid for contexts\n");
return -EINVAL;
}
if (copy_from_user(&ar_info, uptr, sizeof(ar_info)))
return -EFAULT;
cid = vmci_ctx_get_id(vmci_host_dev->context);
result = vmci_ctx_remove_notification(cid,
ar_info.remote_cid);
return put_user(result, &info->result) ? -EFAULT : 0;
}
static int vmci_host_do_ctx_get_cpt_state(struct vmci_host_dev *vmci_host_dev,
const char *ioctl_name,
void __user *uptr)
{
struct vmci_ctx_chkpt_buf_info get_info;
u32 cid;
void *cpt_buf;
int retval;
if (vmci_host_dev->ct_type != VMCIOBJ_CONTEXT) {
vmci_ioctl_err("only valid for contexts\n");
return -EINVAL;
}
if (copy_from_user(&get_info, uptr, sizeof(get_info)))
return -EFAULT;
cid = vmci_ctx_get_id(vmci_host_dev->context);
get_info.result = vmci_ctx_get_chkpt_state(cid, get_info.cpt_type,
&get_info.buf_size, &cpt_buf);
if (get_info.result == VMCI_SUCCESS && get_info.buf_size) {
void __user *ubuf = (void __user *)(uintptr_t)get_info.cpt_buf;
retval = copy_to_user(ubuf, cpt_buf, get_info.buf_size);
kfree(cpt_buf);
if (retval)
return -EFAULT;
}
return copy_to_user(uptr, &get_info, sizeof(get_info)) ? -EFAULT : 0;
}
static int vmci_host_do_ctx_set_cpt_state(struct vmci_host_dev *vmci_host_dev,
const char *ioctl_name,
void __user *uptr)
{
struct vmci_ctx_chkpt_buf_info set_info;
u32 cid;
void *cpt_buf;
int retval;
if (vmci_host_dev->ct_type != VMCIOBJ_CONTEXT) {
vmci_ioctl_err("only valid for contexts\n");
return -EINVAL;
}
if (copy_from_user(&set_info, uptr, sizeof(set_info)))
return -EFAULT;
cpt_buf = kmalloc(set_info.buf_size, GFP_KERNEL);
if (!cpt_buf) {
vmci_ioctl_err(
"cannot allocate memory to set cpt state (type=%d)\n",
set_info.cpt_type);
return -ENOMEM;
}
if (copy_from_user(cpt_buf, (void __user *)(uintptr_t)set_info.cpt_buf,
set_info.buf_size)) {
retval = -EFAULT;
goto out;
}
cid = vmci_ctx_get_id(vmci_host_dev->context);
set_info.result = vmci_ctx_set_chkpt_state(cid, set_info.cpt_type,
set_info.buf_size, cpt_buf);
retval = copy_to_user(uptr, &set_info, sizeof(set_info)) ? -EFAULT : 0;
out:
kfree(cpt_buf);
return retval;
}
static int vmci_host_do_get_context_id(struct vmci_host_dev *vmci_host_dev,
const char *ioctl_name,
void __user *uptr)
{
u32 __user *u32ptr = uptr;
return put_user(VMCI_HOST_CONTEXT_ID, u32ptr) ? -EFAULT : 0;
}
static int vmci_host_do_set_notify(struct vmci_host_dev *vmci_host_dev,
const char *ioctl_name,
void __user *uptr)
{
struct vmci_set_notify_info notify_info;
if (vmci_host_dev->ct_type != VMCIOBJ_CONTEXT) {
vmci_ioctl_err("only valid for contexts\n");
return -EINVAL;
}
if (copy_from_user(&notify_info, uptr, sizeof(notify_info)))
return -EFAULT;
if (notify_info.notify_uva) {
notify_info.result =
vmci_host_setup_notify(vmci_host_dev->context,
notify_info.notify_uva);
} else {
vmci_ctx_unset_notify(vmci_host_dev->context);
notify_info.result = VMCI_SUCCESS;
}
return copy_to_user(uptr, &notify_info, sizeof(notify_info)) ?
-EFAULT : 0;
}
static int vmci_host_do_notify_resource(struct vmci_host_dev *vmci_host_dev,
const char *ioctl_name,
void __user *uptr)
{
struct vmci_dbell_notify_resource_info info;
u32 cid;
if (vmci_host_dev->user_version < VMCI_VERSION_NOTIFY) {
vmci_ioctl_err("invalid for current VMX versions\n");
return -EINVAL;
}
if (vmci_host_dev->ct_type != VMCIOBJ_CONTEXT) {
vmci_ioctl_err("only valid for contexts\n");
return -EINVAL;
}
if (copy_from_user(&info, uptr, sizeof(info)))
return -EFAULT;
cid = vmci_ctx_get_id(vmci_host_dev->context);
switch (info.action) {
case VMCI_NOTIFY_RESOURCE_ACTION_NOTIFY:
if (info.resource == VMCI_NOTIFY_RESOURCE_DOOR_BELL) {
u32 flags = VMCI_NO_PRIVILEGE_FLAGS;
info.result = vmci_ctx_notify_dbell(cid, info.handle,
flags);
} else {
info.result = VMCI_ERROR_UNAVAILABLE;
}
break;
case VMCI_NOTIFY_RESOURCE_ACTION_CREATE:
info.result = vmci_ctx_dbell_create(cid, info.handle);
break;
case VMCI_NOTIFY_RESOURCE_ACTION_DESTROY:
info.result = vmci_ctx_dbell_destroy(cid, info.handle);
break;
default:
vmci_ioctl_err("got unknown action (action=%d)\n",
info.action);
info.result = VMCI_ERROR_INVALID_ARGS;
}
return copy_to_user(uptr, &info, sizeof(info)) ? -EFAULT : 0;
}
static int vmci_host_do_recv_notifications(struct vmci_host_dev *vmci_host_dev,
const char *ioctl_name,
void __user *uptr)
{
struct vmci_ctx_notify_recv_info info;
struct vmci_handle_arr *db_handle_array;
struct vmci_handle_arr *qp_handle_array;
void __user *ubuf;
u32 cid;
int retval = 0;
if (vmci_host_dev->ct_type != VMCIOBJ_CONTEXT) {
vmci_ioctl_err("only valid for contexts\n");
return -EINVAL;
}
if (vmci_host_dev->user_version < VMCI_VERSION_NOTIFY) {
vmci_ioctl_err("not supported for the current vmx version\n");
return -EINVAL;
}
if (copy_from_user(&info, uptr, sizeof(info)))
return -EFAULT;
if ((info.db_handle_buf_size && !info.db_handle_buf_uva) ||
(info.qp_handle_buf_size && !info.qp_handle_buf_uva)) {
return -EINVAL;
}
cid = vmci_ctx_get_id(vmci_host_dev->context);
info.result = vmci_ctx_rcv_notifications_get(cid,
&db_handle_array, &qp_handle_array);
if (info.result != VMCI_SUCCESS)
return copy_to_user(uptr, &info, sizeof(info)) ? -EFAULT : 0;
ubuf = (void __user *)(uintptr_t)info.db_handle_buf_uva;
info.result = drv_cp_harray_to_user(ubuf, &info.db_handle_buf_size,
db_handle_array, &retval);
if (info.result == VMCI_SUCCESS && !retval) {
ubuf = (void __user *)(uintptr_t)info.qp_handle_buf_uva;
info.result = drv_cp_harray_to_user(ubuf,
&info.qp_handle_buf_size,
qp_handle_array, &retval);
}
if (!retval && copy_to_user(uptr, &info, sizeof(info)))
retval = -EFAULT;
vmci_ctx_rcv_notifications_release(cid,
db_handle_array, qp_handle_array,
info.result == VMCI_SUCCESS && !retval);
return retval;
}
static long vmci_host_unlocked_ioctl(struct file *filp,
unsigned int iocmd, unsigned long ioarg)
{
#define VMCI_DO_IOCTL(ioctl_name, ioctl_fn) do { \
char *name = __stringify(IOCTL_VMCI_ ## ioctl_name); \
return vmci_host_do_ ## ioctl_fn( \
vmci_host_dev, name, uptr); \
} while (0)
struct vmci_host_dev *vmci_host_dev = filp->private_data;
void __user *uptr = (void __user *)ioarg;
switch (iocmd) {
case IOCTL_VMCI_INIT_CONTEXT:
VMCI_DO_IOCTL(INIT_CONTEXT, init_context);
case IOCTL_VMCI_DATAGRAM_SEND:
VMCI_DO_IOCTL(DATAGRAM_SEND, send_datagram);
case IOCTL_VMCI_DATAGRAM_RECEIVE:
VMCI_DO_IOCTL(DATAGRAM_RECEIVE, receive_datagram);
case IOCTL_VMCI_QUEUEPAIR_ALLOC:
VMCI_DO_IOCTL(QUEUEPAIR_ALLOC, alloc_queuepair);
case IOCTL_VMCI_QUEUEPAIR_SETVA:
VMCI_DO_IOCTL(QUEUEPAIR_SETVA, queuepair_setva);
case IOCTL_VMCI_QUEUEPAIR_SETPAGEFILE:
VMCI_DO_IOCTL(QUEUEPAIR_SETPAGEFILE, queuepair_setpf);
case IOCTL_VMCI_QUEUEPAIR_DETACH:
VMCI_DO_IOCTL(QUEUEPAIR_DETACH, qp_detach);
case IOCTL_VMCI_CTX_ADD_NOTIFICATION:
VMCI_DO_IOCTL(CTX_ADD_NOTIFICATION, ctx_add_notify);
case IOCTL_VMCI_CTX_REMOVE_NOTIFICATION:
VMCI_DO_IOCTL(CTX_REMOVE_NOTIFICATION, ctx_remove_notify);
case IOCTL_VMCI_CTX_GET_CPT_STATE:
VMCI_DO_IOCTL(CTX_GET_CPT_STATE, ctx_get_cpt_state);
case IOCTL_VMCI_CTX_SET_CPT_STATE:
VMCI_DO_IOCTL(CTX_SET_CPT_STATE, ctx_set_cpt_state);
case IOCTL_VMCI_GET_CONTEXT_ID:
VMCI_DO_IOCTL(GET_CONTEXT_ID, get_context_id);
case IOCTL_VMCI_SET_NOTIFY:
VMCI_DO_IOCTL(SET_NOTIFY, set_notify);
case IOCTL_VMCI_NOTIFY_RESOURCE:
VMCI_DO_IOCTL(NOTIFY_RESOURCE, notify_resource);
case IOCTL_VMCI_NOTIFICATIONS_RECEIVE:
VMCI_DO_IOCTL(NOTIFICATIONS_RECEIVE, recv_notifications);
case IOCTL_VMCI_VERSION:
case IOCTL_VMCI_VERSION2:
return vmci_host_get_version(vmci_host_dev, iocmd, uptr);
default:
pr_devel("%s: Unknown ioctl (iocmd=%d)\n", __func__, iocmd);
return -EINVAL;
}
#undef VMCI_DO_IOCTL
}
int __init vmci_host_init(void)
{
int error;
host_context = vmci_ctx_create(VMCI_HOST_CONTEXT_ID,
VMCI_DEFAULT_PROC_PRIVILEGE_FLAGS,
-1, VMCI_VERSION, NULL);
if (IS_ERR(host_context)) {
error = PTR_ERR(host_context);
pr_warn("Failed to initialize VMCIContext (error%d)\n",
error);
return error;
}
error = misc_register(&vmci_host_miscdev);
if (error) {
pr_warn("Module registration error (name=%s, major=%d, minor=%d, err=%d)\n",
vmci_host_miscdev.name,
MISC_MAJOR, vmci_host_miscdev.minor,
error);
pr_warn("Unable to initialize host personality\n");
vmci_ctx_destroy(host_context);
return error;
}
pr_info("VMCI host device registered (name=%s, major=%d, minor=%d)\n",
vmci_host_miscdev.name, MISC_MAJOR, vmci_host_miscdev.minor);
vmci_host_device_initialized = true;
return 0;
}
void __exit vmci_host_exit(void)
{
int error;
vmci_host_device_initialized = false;
error = misc_deregister(&vmci_host_miscdev);
if (error)
pr_warn("Error unregistering character device: %d\n", error);
vmci_ctx_destroy(host_context);
vmci_qp_broker_exit();
pr_debug("VMCI host driver module unloaded\n");
}
