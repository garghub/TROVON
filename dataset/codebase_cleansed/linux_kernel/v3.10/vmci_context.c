static void ctx_signal_notify(struct vmci_ctx *context)
{
*context->notify = true;
}
static void ctx_clear_notify(struct vmci_ctx *context)
{
*context->notify = false;
}
static void ctx_clear_notify_call(struct vmci_ctx *context)
{
if (context->pending_datagrams == 0 &&
vmci_handle_arr_get_size(context->pending_doorbell_array) == 0)
ctx_clear_notify(context);
}
void vmci_ctx_check_signal_notify(struct vmci_ctx *context)
{
spin_lock(&context->lock);
if (context->pending_datagrams)
ctx_signal_notify(context);
spin_unlock(&context->lock);
}
struct vmci_ctx *vmci_ctx_create(u32 cid, u32 priv_flags,
uintptr_t event_hnd,
int user_version,
const struct cred *cred)
{
struct vmci_ctx *context;
int error;
if (cid == VMCI_INVALID_ID) {
pr_devel("Invalid context ID for VMCI context\n");
error = -EINVAL;
goto err_out;
}
if (priv_flags & ~VMCI_PRIVILEGE_ALL_FLAGS) {
pr_devel("Invalid flag (flags=0x%x) for VMCI context\n",
priv_flags);
error = -EINVAL;
goto err_out;
}
if (user_version == 0) {
pr_devel("Invalid suer_version %d\n", user_version);
error = -EINVAL;
goto err_out;
}
context = kzalloc(sizeof(*context), GFP_KERNEL);
if (!context) {
pr_warn("Failed to allocate memory for VMCI context\n");
error = -EINVAL;
goto err_out;
}
kref_init(&context->kref);
spin_lock_init(&context->lock);
INIT_LIST_HEAD(&context->list_item);
INIT_LIST_HEAD(&context->datagram_queue);
INIT_LIST_HEAD(&context->notifier_list);
init_waitqueue_head(&context->host_context.wait_queue);
context->queue_pair_array = vmci_handle_arr_create(0);
if (!context->queue_pair_array) {
error = -ENOMEM;
goto err_free_ctx;
}
context->doorbell_array = vmci_handle_arr_create(0);
if (!context->doorbell_array) {
error = -ENOMEM;
goto err_free_qp_array;
}
context->pending_doorbell_array = vmci_handle_arr_create(0);
if (!context->pending_doorbell_array) {
error = -ENOMEM;
goto err_free_db_array;
}
context->user_version = user_version;
context->priv_flags = priv_flags;
if (cred)
context->cred = get_cred(cred);
context->notify = &ctx_dummy_notify;
context->notify_page = NULL;
spin_lock(&ctx_list.lock);
while (vmci_ctx_exists(cid)) {
cid = max(cid, VMCI_RESERVED_CID_LIMIT - 1) + 1;
if (cid == VMCI_INVALID_ID)
cid = VMCI_RESERVED_CID_LIMIT;
}
context->cid = cid;
list_add_tail_rcu(&context->list_item, &ctx_list.head);
spin_unlock(&ctx_list.lock);
return context;
err_free_db_array:
vmci_handle_arr_destroy(context->doorbell_array);
err_free_qp_array:
vmci_handle_arr_destroy(context->queue_pair_array);
err_free_ctx:
kfree(context);
err_out:
return ERR_PTR(error);
}
void vmci_ctx_destroy(struct vmci_ctx *context)
{
spin_lock(&ctx_list.lock);
list_del_rcu(&context->list_item);
spin_unlock(&ctx_list.lock);
synchronize_rcu();
vmci_ctx_put(context);
}
static int ctx_fire_notification(u32 context_id, u32 priv_flags)
{
u32 i, array_size;
struct vmci_ctx *sub_ctx;
struct vmci_handle_arr *subscriber_array;
struct vmci_handle context_handle =
vmci_make_handle(context_id, VMCI_EVENT_HANDLER);
subscriber_array = vmci_handle_arr_create(0);
if (subscriber_array == NULL)
return VMCI_ERROR_NO_MEM;
rcu_read_lock();
list_for_each_entry_rcu(sub_ctx, &ctx_list.head, list_item) {
struct vmci_handle_list *node;
if (vmci_deny_interaction(priv_flags, sub_ctx->priv_flags))
continue;
list_for_each_entry_rcu(node, &sub_ctx->notifier_list, node) {
if (!vmci_handle_is_equal(node->handle, context_handle))
continue;
vmci_handle_arr_append_entry(&subscriber_array,
vmci_make_handle(sub_ctx->cid,
VMCI_EVENT_HANDLER));
}
}
rcu_read_unlock();
array_size = vmci_handle_arr_get_size(subscriber_array);
for (i = 0; i < array_size; i++) {
int result;
struct vmci_event_ctx ev;
ev.msg.hdr.dst = vmci_handle_arr_get_entry(subscriber_array, i);
ev.msg.hdr.src = vmci_make_handle(VMCI_HYPERVISOR_CONTEXT_ID,
VMCI_CONTEXT_RESOURCE_ID);
ev.msg.hdr.payload_size = sizeof(ev) - sizeof(ev.msg.hdr);
ev.msg.event_data.event = VMCI_EVENT_CTX_REMOVED;
ev.payload.context_id = context_id;
result = vmci_datagram_dispatch(VMCI_HYPERVISOR_CONTEXT_ID,
&ev.msg.hdr, false);
if (result < VMCI_SUCCESS) {
pr_devel("Failed to enqueue event datagram (type=%d) for context (ID=0x%x)\n",
ev.msg.event_data.event,
ev.msg.hdr.dst.context);
}
}
vmci_handle_arr_destroy(subscriber_array);
return VMCI_SUCCESS;
}
int vmci_ctx_pending_datagrams(u32 cid, u32 *pending)
{
struct vmci_ctx *context;
context = vmci_ctx_get(cid);
if (context == NULL)
return VMCI_ERROR_INVALID_ARGS;
spin_lock(&context->lock);
if (pending)
*pending = context->pending_datagrams;
spin_unlock(&context->lock);
vmci_ctx_put(context);
return VMCI_SUCCESS;
}
int vmci_ctx_enqueue_datagram(u32 cid, struct vmci_datagram *dg)
{
struct vmci_datagram_queue_entry *dq_entry;
struct vmci_ctx *context;
struct vmci_handle dg_src;
size_t vmci_dg_size;
vmci_dg_size = VMCI_DG_SIZE(dg);
if (vmci_dg_size > VMCI_MAX_DG_SIZE) {
pr_devel("Datagram too large (bytes=%Zu)\n", vmci_dg_size);
return VMCI_ERROR_INVALID_ARGS;
}
context = vmci_ctx_get(cid);
if (!context) {
pr_devel("Invalid context (ID=0x%x)\n", cid);
return VMCI_ERROR_INVALID_ARGS;
}
dq_entry = kmalloc(sizeof(*dq_entry), GFP_KERNEL);
if (dq_entry == NULL) {
pr_warn("Failed to allocate memory for datagram\n");
vmci_ctx_put(context);
return VMCI_ERROR_NO_MEM;
}
dq_entry->dg = dg;
dq_entry->dg_size = vmci_dg_size;
dg_src = dg->src;
INIT_LIST_HEAD(&dq_entry->list_item);
spin_lock(&context->lock);
if (context->datagram_queue_size + vmci_dg_size >=
VMCI_MAX_DATAGRAM_QUEUE_SIZE &&
(!vmci_handle_is_equal(dg_src,
vmci_make_handle
(VMCI_HYPERVISOR_CONTEXT_ID,
VMCI_CONTEXT_RESOURCE_ID)) ||
context->datagram_queue_size + vmci_dg_size >=
VMCI_MAX_DATAGRAM_AND_EVENT_QUEUE_SIZE)) {
spin_unlock(&context->lock);
vmci_ctx_put(context);
kfree(dq_entry);
pr_devel("Context (ID=0x%x) receive queue is full\n", cid);
return VMCI_ERROR_NO_RESOURCES;
}
list_add(&dq_entry->list_item, &context->datagram_queue);
context->pending_datagrams++;
context->datagram_queue_size += vmci_dg_size;
ctx_signal_notify(context);
wake_up(&context->host_context.wait_queue);
spin_unlock(&context->lock);
vmci_ctx_put(context);
return vmci_dg_size;
}
bool vmci_ctx_exists(u32 cid)
{
struct vmci_ctx *context;
bool exists = false;
rcu_read_lock();
list_for_each_entry_rcu(context, &ctx_list.head, list_item) {
if (context->cid == cid) {
exists = true;
break;
}
}
rcu_read_unlock();
return exists;
}
struct vmci_ctx *vmci_ctx_get(u32 cid)
{
struct vmci_ctx *c, *context = NULL;
if (cid == VMCI_INVALID_ID)
return NULL;
rcu_read_lock();
list_for_each_entry_rcu(c, &ctx_list.head, list_item) {
if (c->cid == cid) {
context = c;
kref_get(&context->kref);
break;
}
}
rcu_read_unlock();
return context;
}
static void ctx_free_ctx(struct kref *kref)
{
struct vmci_ctx *context = container_of(kref, struct vmci_ctx, kref);
struct vmci_datagram_queue_entry *dq_entry, *dq_entry_tmp;
struct vmci_handle temp_handle;
struct vmci_handle_list *notifier, *tmp;
ctx_fire_notification(context->cid, context->priv_flags);
temp_handle = vmci_handle_arr_get_entry(context->queue_pair_array, 0);
while (!vmci_handle_is_equal(temp_handle, VMCI_INVALID_HANDLE)) {
if (vmci_qp_broker_detach(temp_handle,
context) < VMCI_SUCCESS) {
vmci_handle_arr_remove_entry(context->queue_pair_array,
temp_handle);
}
temp_handle =
vmci_handle_arr_get_entry(context->queue_pair_array, 0);
}
list_for_each_entry_safe(dq_entry, dq_entry_tmp,
&context->datagram_queue, list_item) {
WARN_ON(dq_entry->dg_size != VMCI_DG_SIZE(dq_entry->dg));
list_del(&dq_entry->list_item);
kfree(dq_entry->dg);
kfree(dq_entry);
}
list_for_each_entry_safe(notifier, tmp,
&context->notifier_list, node) {
list_del(&notifier->node);
kfree(notifier);
}
vmci_handle_arr_destroy(context->queue_pair_array);
vmci_handle_arr_destroy(context->doorbell_array);
vmci_handle_arr_destroy(context->pending_doorbell_array);
vmci_ctx_unset_notify(context);
if (context->cred)
put_cred(context->cred);
kfree(context);
}
void vmci_ctx_put(struct vmci_ctx *context)
{
kref_put(&context->kref, ctx_free_ctx);
}
int vmci_ctx_dequeue_datagram(struct vmci_ctx *context,
size_t *max_size,
struct vmci_datagram **dg)
{
struct vmci_datagram_queue_entry *dq_entry;
struct list_head *list_item;
int rv;
spin_lock(&context->lock);
if (context->pending_datagrams == 0) {
ctx_clear_notify_call(context);
spin_unlock(&context->lock);
pr_devel("No datagrams pending\n");
return VMCI_ERROR_NO_MORE_DATAGRAMS;
}
list_item = context->datagram_queue.next;
dq_entry =
list_entry(list_item, struct vmci_datagram_queue_entry, list_item);
if (*max_size < dq_entry->dg_size) {
*max_size = dq_entry->dg_size;
spin_unlock(&context->lock);
pr_devel("Caller's buffer should be at least (size=%u bytes)\n",
(u32) *max_size);
return VMCI_ERROR_NO_MEM;
}
list_del(list_item);
context->pending_datagrams--;
context->datagram_queue_size -= dq_entry->dg_size;
if (context->pending_datagrams == 0) {
ctx_clear_notify_call(context);
rv = VMCI_SUCCESS;
} else {
struct vmci_datagram_queue_entry *next_entry;
list_item = context->datagram_queue.next;
next_entry =
list_entry(list_item, struct vmci_datagram_queue_entry,
list_item);
rv = (int)next_entry->dg_size;
}
spin_unlock(&context->lock);
*dg = dq_entry->dg;
dq_entry->dg = NULL;
kfree(dq_entry);
return rv;
}
void vmci_ctx_unset_notify(struct vmci_ctx *context)
{
struct page *notify_page;
spin_lock(&context->lock);
notify_page = context->notify_page;
context->notify = &ctx_dummy_notify;
context->notify_page = NULL;
spin_unlock(&context->lock);
if (notify_page) {
kunmap(notify_page);
put_page(notify_page);
}
}
int vmci_ctx_add_notification(u32 context_id, u32 remote_cid)
{
struct vmci_ctx *context;
struct vmci_handle_list *notifier, *n;
int result;
bool exists = false;
context = vmci_ctx_get(context_id);
if (!context)
return VMCI_ERROR_NOT_FOUND;
if (VMCI_CONTEXT_IS_VM(context_id) && VMCI_CONTEXT_IS_VM(remote_cid)) {
pr_devel("Context removed notifications for other VMs not supported (src=0x%x, remote=0x%x)\n",
context_id, remote_cid);
result = VMCI_ERROR_DST_UNREACHABLE;
goto out;
}
if (context->priv_flags & VMCI_PRIVILEGE_FLAG_RESTRICTED) {
result = VMCI_ERROR_NO_ACCESS;
goto out;
}
notifier = kmalloc(sizeof(struct vmci_handle_list), GFP_KERNEL);
if (!notifier) {
result = VMCI_ERROR_NO_MEM;
goto out;
}
INIT_LIST_HEAD(&notifier->node);
notifier->handle = vmci_make_handle(remote_cid, VMCI_EVENT_HANDLER);
spin_lock(&context->lock);
list_for_each_entry(n, &context->notifier_list, node) {
if (vmci_handle_is_equal(n->handle, notifier->handle)) {
exists = true;
break;
}
}
if (exists) {
kfree(notifier);
result = VMCI_ERROR_ALREADY_EXISTS;
} else {
list_add_tail_rcu(&notifier->node, &context->notifier_list);
context->n_notifiers++;
result = VMCI_SUCCESS;
}
spin_unlock(&context->lock);
out:
vmci_ctx_put(context);
return result;
}
int vmci_ctx_remove_notification(u32 context_id, u32 remote_cid)
{
struct vmci_ctx *context;
struct vmci_handle_list *notifier, *tmp;
struct vmci_handle handle;
bool found = false;
context = vmci_ctx_get(context_id);
if (!context)
return VMCI_ERROR_NOT_FOUND;
handle = vmci_make_handle(remote_cid, VMCI_EVENT_HANDLER);
spin_lock(&context->lock);
list_for_each_entry_safe(notifier, tmp,
&context->notifier_list, node) {
if (vmci_handle_is_equal(notifier->handle, handle)) {
list_del_rcu(&notifier->node);
context->n_notifiers--;
found = true;
break;
}
}
spin_unlock(&context->lock);
if (found) {
synchronize_rcu();
kfree(notifier);
}
vmci_ctx_put(context);
return found ? VMCI_SUCCESS : VMCI_ERROR_NOT_FOUND;
}
static int vmci_ctx_get_chkpt_notifiers(struct vmci_ctx *context,
u32 *buf_size, void **pbuf)
{
u32 *notifiers;
size_t data_size;
struct vmci_handle_list *entry;
int i = 0;
if (context->n_notifiers == 0) {
*buf_size = 0;
*pbuf = NULL;
return VMCI_SUCCESS;
}
data_size = context->n_notifiers * sizeof(*notifiers);
if (*buf_size < data_size) {
*buf_size = data_size;
return VMCI_ERROR_MORE_DATA;
}
notifiers = kmalloc(data_size, GFP_ATOMIC);
if (!notifiers)
return VMCI_ERROR_NO_MEM;
list_for_each_entry(entry, &context->notifier_list, node)
notifiers[i++] = entry->handle.context;
*buf_size = data_size;
*pbuf = notifiers;
return VMCI_SUCCESS;
}
static int vmci_ctx_get_chkpt_doorbells(struct vmci_ctx *context,
u32 *buf_size, void **pbuf)
{
struct dbell_cpt_state *dbells;
size_t n_doorbells;
int i;
n_doorbells = vmci_handle_arr_get_size(context->doorbell_array);
if (n_doorbells > 0) {
size_t data_size = n_doorbells * sizeof(*dbells);
if (*buf_size < data_size) {
*buf_size = data_size;
return VMCI_ERROR_MORE_DATA;
}
dbells = kmalloc(data_size, GFP_ATOMIC);
if (!dbells)
return VMCI_ERROR_NO_MEM;
for (i = 0; i < n_doorbells; i++)
dbells[i].handle = vmci_handle_arr_get_entry(
context->doorbell_array, i);
*buf_size = data_size;
*pbuf = dbells;
} else {
*buf_size = 0;
*pbuf = NULL;
}
return VMCI_SUCCESS;
}
int vmci_ctx_get_chkpt_state(u32 context_id,
u32 cpt_type,
u32 *buf_size,
void **pbuf)
{
struct vmci_ctx *context;
int result;
context = vmci_ctx_get(context_id);
if (!context)
return VMCI_ERROR_NOT_FOUND;
spin_lock(&context->lock);
switch (cpt_type) {
case VMCI_NOTIFICATION_CPT_STATE:
result = vmci_ctx_get_chkpt_notifiers(context, buf_size, pbuf);
break;
case VMCI_WELLKNOWN_CPT_STATE:
*buf_size = 0;
*pbuf = NULL;
result = VMCI_SUCCESS;
break;
case VMCI_DOORBELL_CPT_STATE:
result = vmci_ctx_get_chkpt_doorbells(context, buf_size, pbuf);
break;
default:
pr_devel("Invalid cpt state (type=%d)\n", cpt_type);
result = VMCI_ERROR_INVALID_ARGS;
break;
}
spin_unlock(&context->lock);
vmci_ctx_put(context);
return result;
}
int vmci_ctx_set_chkpt_state(u32 context_id,
u32 cpt_type,
u32 buf_size,
void *cpt_buf)
{
u32 i;
u32 current_id;
int result = VMCI_SUCCESS;
u32 num_ids = buf_size / sizeof(u32);
if (cpt_type == VMCI_WELLKNOWN_CPT_STATE && num_ids > 0) {
pr_warn("Attempt to restore checkpoint with obsolete wellknown handles\n");
return VMCI_ERROR_OBSOLETE;
}
if (cpt_type != VMCI_NOTIFICATION_CPT_STATE) {
pr_devel("Invalid cpt state (type=%d)\n", cpt_type);
return VMCI_ERROR_INVALID_ARGS;
}
for (i = 0; i < num_ids && result == VMCI_SUCCESS; i++) {
current_id = ((u32 *)cpt_buf)[i];
result = vmci_ctx_add_notification(context_id, current_id);
if (result != VMCI_SUCCESS)
break;
}
if (result != VMCI_SUCCESS)
pr_devel("Failed to set cpt state (type=%d) (error=%d)\n",
cpt_type, result);
return result;
}
int vmci_ctx_rcv_notifications_get(u32 context_id,
struct vmci_handle_arr **db_handle_array,
struct vmci_handle_arr **qp_handle_array)
{
struct vmci_ctx *context;
int result = VMCI_SUCCESS;
context = vmci_ctx_get(context_id);
if (context == NULL)
return VMCI_ERROR_NOT_FOUND;
spin_lock(&context->lock);
*db_handle_array = context->pending_doorbell_array;
context->pending_doorbell_array = vmci_handle_arr_create(0);
if (!context->pending_doorbell_array) {
context->pending_doorbell_array = *db_handle_array;
*db_handle_array = NULL;
result = VMCI_ERROR_NO_MEM;
}
*qp_handle_array = NULL;
spin_unlock(&context->lock);
vmci_ctx_put(context);
return result;
}
void vmci_ctx_rcv_notifications_release(u32 context_id,
struct vmci_handle_arr *db_handle_array,
struct vmci_handle_arr *qp_handle_array,
bool success)
{
struct vmci_ctx *context = vmci_ctx_get(context_id);
spin_lock(&context->lock);
if (!success) {
struct vmci_handle handle;
handle = vmci_handle_arr_remove_tail(
context->pending_doorbell_array);
while (!vmci_handle_is_invalid(handle)) {
if (!vmci_handle_arr_has_entry(db_handle_array,
handle)) {
vmci_handle_arr_append_entry(
&db_handle_array, handle);
}
handle = vmci_handle_arr_remove_tail(
context->pending_doorbell_array);
}
vmci_handle_arr_destroy(context->pending_doorbell_array);
context->pending_doorbell_array = db_handle_array;
db_handle_array = NULL;
} else {
ctx_clear_notify_call(context);
}
spin_unlock(&context->lock);
vmci_ctx_put(context);
if (db_handle_array)
vmci_handle_arr_destroy(db_handle_array);
if (qp_handle_array)
vmci_handle_arr_destroy(qp_handle_array);
}
int vmci_ctx_dbell_create(u32 context_id, struct vmci_handle handle)
{
struct vmci_ctx *context;
int result;
if (context_id == VMCI_INVALID_ID || vmci_handle_is_invalid(handle))
return VMCI_ERROR_INVALID_ARGS;
context = vmci_ctx_get(context_id);
if (context == NULL)
return VMCI_ERROR_NOT_FOUND;
spin_lock(&context->lock);
if (!vmci_handle_arr_has_entry(context->doorbell_array, handle)) {
vmci_handle_arr_append_entry(&context->doorbell_array, handle);
result = VMCI_SUCCESS;
} else {
result = VMCI_ERROR_DUPLICATE_ENTRY;
}
spin_unlock(&context->lock);
vmci_ctx_put(context);
return result;
}
int vmci_ctx_dbell_destroy(u32 context_id, struct vmci_handle handle)
{
struct vmci_ctx *context;
struct vmci_handle removed_handle;
if (context_id == VMCI_INVALID_ID || vmci_handle_is_invalid(handle))
return VMCI_ERROR_INVALID_ARGS;
context = vmci_ctx_get(context_id);
if (context == NULL)
return VMCI_ERROR_NOT_FOUND;
spin_lock(&context->lock);
removed_handle =
vmci_handle_arr_remove_entry(context->doorbell_array, handle);
vmci_handle_arr_remove_entry(context->pending_doorbell_array, handle);
spin_unlock(&context->lock);
vmci_ctx_put(context);
return vmci_handle_is_invalid(removed_handle) ?
VMCI_ERROR_NOT_FOUND : VMCI_SUCCESS;
}
int vmci_ctx_dbell_destroy_all(u32 context_id)
{
struct vmci_ctx *context;
struct vmci_handle handle;
if (context_id == VMCI_INVALID_ID)
return VMCI_ERROR_INVALID_ARGS;
context = vmci_ctx_get(context_id);
if (context == NULL)
return VMCI_ERROR_NOT_FOUND;
spin_lock(&context->lock);
do {
struct vmci_handle_arr *arr = context->doorbell_array;
handle = vmci_handle_arr_remove_tail(arr);
} while (!vmci_handle_is_invalid(handle));
do {
struct vmci_handle_arr *arr = context->pending_doorbell_array;
handle = vmci_handle_arr_remove_tail(arr);
} while (!vmci_handle_is_invalid(handle));
spin_unlock(&context->lock);
vmci_ctx_put(context);
return VMCI_SUCCESS;
}
int vmci_ctx_notify_dbell(u32 src_cid,
struct vmci_handle handle,
u32 src_priv_flags)
{
struct vmci_ctx *dst_context;
int result;
if (vmci_handle_is_invalid(handle))
return VMCI_ERROR_INVALID_ARGS;
dst_context = vmci_ctx_get(handle.context);
if (!dst_context) {
pr_devel("Invalid context (ID=0x%x)\n", handle.context);
return VMCI_ERROR_NOT_FOUND;
}
if (src_cid != handle.context) {
u32 dst_priv_flags;
if (VMCI_CONTEXT_IS_VM(src_cid) &&
VMCI_CONTEXT_IS_VM(handle.context)) {
pr_devel("Doorbell notification from VM to VM not supported (src=0x%x, dst=0x%x)\n",
src_cid, handle.context);
result = VMCI_ERROR_DST_UNREACHABLE;
goto out;
}
result = vmci_dbell_get_priv_flags(handle, &dst_priv_flags);
if (result < VMCI_SUCCESS) {
pr_warn("Failed to get privilege flags for destination (handle=0x%x:0x%x)\n",
handle.context, handle.resource);
goto out;
}
if (src_cid != VMCI_HOST_CONTEXT_ID ||
src_priv_flags == VMCI_NO_PRIVILEGE_FLAGS) {
src_priv_flags = vmci_context_get_priv_flags(src_cid);
}
if (vmci_deny_interaction(src_priv_flags, dst_priv_flags)) {
result = VMCI_ERROR_NO_ACCESS;
goto out;
}
}
if (handle.context == VMCI_HOST_CONTEXT_ID) {
result = vmci_dbell_host_context_notify(src_cid, handle);
} else {
spin_lock(&dst_context->lock);
if (!vmci_handle_arr_has_entry(dst_context->doorbell_array,
handle)) {
result = VMCI_ERROR_NOT_FOUND;
} else {
if (!vmci_handle_arr_has_entry(
dst_context->pending_doorbell_array,
handle)) {
vmci_handle_arr_append_entry(
&dst_context->pending_doorbell_array,
handle);
ctx_signal_notify(dst_context);
wake_up(&dst_context->host_context.wait_queue);
}
result = VMCI_SUCCESS;
}
spin_unlock(&dst_context->lock);
}
out:
vmci_ctx_put(dst_context);
return result;
}
bool vmci_ctx_supports_host_qp(struct vmci_ctx *context)
{
return context && context->user_version >= VMCI_VERSION_HOSTQP;
}
int vmci_ctx_qp_create(struct vmci_ctx *context, struct vmci_handle handle)
{
int result;
if (context == NULL || vmci_handle_is_invalid(handle))
return VMCI_ERROR_INVALID_ARGS;
if (!vmci_handle_arr_has_entry(context->queue_pair_array, handle)) {
vmci_handle_arr_append_entry(&context->queue_pair_array,
handle);
result = VMCI_SUCCESS;
} else {
result = VMCI_ERROR_DUPLICATE_ENTRY;
}
return result;
}
int vmci_ctx_qp_destroy(struct vmci_ctx *context, struct vmci_handle handle)
{
struct vmci_handle hndl;
if (context == NULL || vmci_handle_is_invalid(handle))
return VMCI_ERROR_INVALID_ARGS;
hndl = vmci_handle_arr_remove_entry(context->queue_pair_array, handle);
return vmci_handle_is_invalid(hndl) ?
VMCI_ERROR_NOT_FOUND : VMCI_SUCCESS;
}
bool vmci_ctx_qp_exists(struct vmci_ctx *context, struct vmci_handle handle)
{
if (context == NULL || vmci_handle_is_invalid(handle))
return false;
return vmci_handle_arr_has_entry(context->queue_pair_array, handle);
}
u32 vmci_context_get_priv_flags(u32 context_id)
{
if (vmci_host_code_active()) {
u32 flags;
struct vmci_ctx *context;
context = vmci_ctx_get(context_id);
if (!context)
return VMCI_LEAST_PRIVILEGE_FLAGS;
flags = context->priv_flags;
vmci_ctx_put(context);
return flags;
}
return VMCI_NO_PRIVILEGE_FLAGS;
}
bool vmci_is_context_owner(u32 context_id, kuid_t uid)
{
bool is_owner = false;
if (vmci_host_code_active()) {
struct vmci_ctx *context = vmci_ctx_get(context_id);
if (context) {
if (context->cred)
is_owner = uid_eq(context->cred->uid, uid);
vmci_ctx_put(context);
}
}
return is_owner;
}
