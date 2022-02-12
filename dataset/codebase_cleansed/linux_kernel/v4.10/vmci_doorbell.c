int vmci_dbell_get_priv_flags(struct vmci_handle handle, u32 *priv_flags)
{
if (priv_flags == NULL || handle.context == VMCI_INVALID_ID)
return VMCI_ERROR_INVALID_ARGS;
if (handle.context == VMCI_HOST_CONTEXT_ID) {
struct dbell_entry *entry;
struct vmci_resource *resource;
resource = vmci_resource_by_handle(handle,
VMCI_RESOURCE_TYPE_DOORBELL);
if (!resource)
return VMCI_ERROR_NOT_FOUND;
entry = container_of(resource, struct dbell_entry, resource);
*priv_flags = entry->priv_flags;
vmci_resource_put(resource);
} else if (handle.context == VMCI_HYPERVISOR_CONTEXT_ID) {
return VMCI_ERROR_INVALID_ARGS;
} else {
*priv_flags = vmci_context_get_priv_flags(handle.context);
}
return VMCI_SUCCESS;
}
static struct dbell_entry *dbell_index_table_find(u32 idx)
{
u32 bucket = VMCI_DOORBELL_HASH(idx);
struct dbell_entry *dbell;
hlist_for_each_entry(dbell, &vmci_doorbell_it.entries[bucket],
node) {
if (idx == dbell->idx)
return dbell;
}
return NULL;
}
static void dbell_index_table_add(struct dbell_entry *entry)
{
u32 bucket;
u32 new_notify_idx;
vmci_resource_get(&entry->resource);
spin_lock_bh(&vmci_doorbell_it.lock);
if (max_notify_idx < PAGE_SIZE || notify_idx_count < PAGE_SIZE) {
if (last_notify_idx_released < max_notify_idx &&
!dbell_index_table_find(last_notify_idx_released)) {
new_notify_idx = last_notify_idx_released;
last_notify_idx_released = PAGE_SIZE;
} else {
bool reused = false;
new_notify_idx = last_notify_idx_reserved;
if (notify_idx_count + 1 < max_notify_idx) {
do {
if (!dbell_index_table_find
(new_notify_idx)) {
reused = true;
break;
}
new_notify_idx = (new_notify_idx + 1) %
max_notify_idx;
} while (new_notify_idx !=
last_notify_idx_released);
}
if (!reused) {
new_notify_idx = max_notify_idx;
max_notify_idx++;
}
}
} else {
new_notify_idx = (last_notify_idx_reserved + 1) % PAGE_SIZE;
}
last_notify_idx_reserved = new_notify_idx;
notify_idx_count++;
entry->idx = new_notify_idx;
bucket = VMCI_DOORBELL_HASH(entry->idx);
hlist_add_head(&entry->node, &vmci_doorbell_it.entries[bucket]);
spin_unlock_bh(&vmci_doorbell_it.lock);
}
static void dbell_index_table_remove(struct dbell_entry *entry)
{
spin_lock_bh(&vmci_doorbell_it.lock);
hlist_del_init(&entry->node);
notify_idx_count--;
if (entry->idx == max_notify_idx - 1) {
while (max_notify_idx > 0 &&
!dbell_index_table_find(max_notify_idx - 1))
max_notify_idx--;
}
last_notify_idx_released = entry->idx;
spin_unlock_bh(&vmci_doorbell_it.lock);
vmci_resource_put(&entry->resource);
}
static int dbell_link(struct vmci_handle handle, u32 notify_idx)
{
struct vmci_doorbell_link_msg link_msg;
link_msg.hdr.dst = vmci_make_handle(VMCI_HYPERVISOR_CONTEXT_ID,
VMCI_DOORBELL_LINK);
link_msg.hdr.src = VMCI_ANON_SRC_HANDLE;
link_msg.hdr.payload_size = sizeof(link_msg) - VMCI_DG_HEADERSIZE;
link_msg.handle = handle;
link_msg.notify_idx = notify_idx;
return vmci_send_datagram(&link_msg.hdr);
}
static int dbell_unlink(struct vmci_handle handle)
{
struct vmci_doorbell_unlink_msg unlink_msg;
unlink_msg.hdr.dst = vmci_make_handle(VMCI_HYPERVISOR_CONTEXT_ID,
VMCI_DOORBELL_UNLINK);
unlink_msg.hdr.src = VMCI_ANON_SRC_HANDLE;
unlink_msg.hdr.payload_size = sizeof(unlink_msg) - VMCI_DG_HEADERSIZE;
unlink_msg.handle = handle;
return vmci_send_datagram(&unlink_msg.hdr);
}
static int dbell_notify_as_guest(struct vmci_handle handle, u32 priv_flags)
{
struct vmci_doorbell_notify_msg notify_msg;
notify_msg.hdr.dst = vmci_make_handle(VMCI_HYPERVISOR_CONTEXT_ID,
VMCI_DOORBELL_NOTIFY);
notify_msg.hdr.src = VMCI_ANON_SRC_HANDLE;
notify_msg.hdr.payload_size = sizeof(notify_msg) - VMCI_DG_HEADERSIZE;
notify_msg.handle = handle;
return vmci_send_datagram(&notify_msg.hdr);
}
static void dbell_delayed_dispatch(struct work_struct *work)
{
struct dbell_entry *entry = container_of(work,
struct dbell_entry, work);
entry->notify_cb(entry->client_data);
vmci_resource_put(&entry->resource);
}
int vmci_dbell_host_context_notify(u32 src_cid, struct vmci_handle handle)
{
struct dbell_entry *entry;
struct vmci_resource *resource;
if (vmci_handle_is_invalid(handle)) {
pr_devel("Notifying an invalid doorbell (handle=0x%x:0x%x)\n",
handle.context, handle.resource);
return VMCI_ERROR_INVALID_ARGS;
}
resource = vmci_resource_by_handle(handle,
VMCI_RESOURCE_TYPE_DOORBELL);
if (!resource) {
pr_devel("Notifying an unknown doorbell (handle=0x%x:0x%x)\n",
handle.context, handle.resource);
return VMCI_ERROR_NOT_FOUND;
}
entry = container_of(resource, struct dbell_entry, resource);
if (entry->run_delayed) {
schedule_work(&entry->work);
} else {
entry->notify_cb(entry->client_data);
vmci_resource_put(resource);
}
return VMCI_SUCCESS;
}
bool vmci_dbell_register_notification_bitmap(u32 bitmap_ppn)
{
int result;
struct vmci_notify_bm_set_msg bitmap_set_msg;
bitmap_set_msg.hdr.dst = vmci_make_handle(VMCI_HYPERVISOR_CONTEXT_ID,
VMCI_SET_NOTIFY_BITMAP);
bitmap_set_msg.hdr.src = VMCI_ANON_SRC_HANDLE;
bitmap_set_msg.hdr.payload_size = sizeof(bitmap_set_msg) -
VMCI_DG_HEADERSIZE;
bitmap_set_msg.bitmap_ppn = bitmap_ppn;
result = vmci_send_datagram(&bitmap_set_msg.hdr);
if (result != VMCI_SUCCESS) {
pr_devel("Failed to register (PPN=%u) as notification bitmap (error=%d)\n",
bitmap_ppn, result);
return false;
}
return true;
}
static void dbell_fire_entries(u32 notify_idx)
{
u32 bucket = VMCI_DOORBELL_HASH(notify_idx);
struct dbell_entry *dbell;
spin_lock_bh(&vmci_doorbell_it.lock);
hlist_for_each_entry(dbell, &vmci_doorbell_it.entries[bucket], node) {
if (dbell->idx == notify_idx &&
atomic_read(&dbell->active) == 1) {
if (dbell->run_delayed) {
vmci_resource_get(&dbell->resource);
schedule_work(&dbell->work);
} else {
dbell->notify_cb(dbell->client_data);
}
}
}
spin_unlock_bh(&vmci_doorbell_it.lock);
}
void vmci_dbell_scan_notification_entries(u8 *bitmap)
{
u32 idx;
for (idx = 0; idx < max_notify_idx; idx++) {
if (bitmap[idx] & 0x1) {
bitmap[idx] &= ~1;
dbell_fire_entries(idx);
}
}
}
int vmci_doorbell_create(struct vmci_handle *handle,
u32 flags,
u32 priv_flags,
vmci_callback notify_cb, void *client_data)
{
struct dbell_entry *entry;
struct vmci_handle new_handle;
int result;
if (!handle || !notify_cb || flags & ~VMCI_FLAG_DELAYED_CB ||
priv_flags & ~VMCI_PRIVILEGE_ALL_FLAGS)
return VMCI_ERROR_INVALID_ARGS;
entry = kmalloc(sizeof(*entry), GFP_KERNEL);
if (entry == NULL) {
pr_warn("Failed allocating memory for datagram entry\n");
return VMCI_ERROR_NO_MEM;
}
if (vmci_handle_is_invalid(*handle)) {
u32 context_id = vmci_get_context_id();
if (context_id == VMCI_INVALID_ID) {
pr_warn("Failed to get context ID\n");
result = VMCI_ERROR_NO_RESOURCES;
goto free_mem;
}
new_handle = vmci_make_handle(context_id, VMCI_INVALID_ID);
} else {
bool valid_context = false;
if (handle->context == VMCI_HOST_CONTEXT_ID ||
(vmci_guest_code_active() &&
vmci_get_context_id() == handle->context)) {
valid_context = true;
}
if (!valid_context || handle->resource == VMCI_INVALID_ID) {
pr_devel("Invalid argument (handle=0x%x:0x%x)\n",
handle->context, handle->resource);
result = VMCI_ERROR_INVALID_ARGS;
goto free_mem;
}
new_handle = *handle;
}
entry->idx = 0;
INIT_HLIST_NODE(&entry->node);
entry->priv_flags = priv_flags;
INIT_WORK(&entry->work, dbell_delayed_dispatch);
entry->run_delayed = flags & VMCI_FLAG_DELAYED_CB;
entry->notify_cb = notify_cb;
entry->client_data = client_data;
atomic_set(&entry->active, 0);
result = vmci_resource_add(&entry->resource,
VMCI_RESOURCE_TYPE_DOORBELL,
new_handle);
if (result != VMCI_SUCCESS) {
pr_warn("Failed to add new resource (handle=0x%x:0x%x), error: %d\n",
new_handle.context, new_handle.resource, result);
goto free_mem;
}
new_handle = vmci_resource_handle(&entry->resource);
if (vmci_guest_code_active()) {
dbell_index_table_add(entry);
result = dbell_link(new_handle, entry->idx);
if (VMCI_SUCCESS != result)
goto destroy_resource;
atomic_set(&entry->active, 1);
}
*handle = new_handle;
return result;
destroy_resource:
dbell_index_table_remove(entry);
vmci_resource_remove(&entry->resource);
free_mem:
kfree(entry);
return result;
}
int vmci_doorbell_destroy(struct vmci_handle handle)
{
struct dbell_entry *entry;
struct vmci_resource *resource;
if (vmci_handle_is_invalid(handle))
return VMCI_ERROR_INVALID_ARGS;
resource = vmci_resource_by_handle(handle,
VMCI_RESOURCE_TYPE_DOORBELL);
if (!resource) {
pr_devel("Failed to destroy doorbell (handle=0x%x:0x%x)\n",
handle.context, handle.resource);
return VMCI_ERROR_NOT_FOUND;
}
entry = container_of(resource, struct dbell_entry, resource);
if (!hlist_unhashed(&entry->node)) {
int result;
dbell_index_table_remove(entry);
result = dbell_unlink(handle);
if (VMCI_SUCCESS != result) {
pr_devel("Unlink of doorbell (handle=0x%x:0x%x) unknown by hypervisor (error=%d)\n",
handle.context, handle.resource, result);
}
}
vmci_resource_put(&entry->resource);
vmci_resource_remove(&entry->resource);
kfree(entry);
return VMCI_SUCCESS;
}
int vmci_doorbell_notify(struct vmci_handle dst, u32 priv_flags)
{
int retval;
enum vmci_route route;
struct vmci_handle src;
if (vmci_handle_is_invalid(dst) ||
(priv_flags & ~VMCI_PRIVILEGE_ALL_FLAGS))
return VMCI_ERROR_INVALID_ARGS;
src = VMCI_INVALID_HANDLE;
retval = vmci_route(&src, &dst, false, &route);
if (retval < VMCI_SUCCESS)
return retval;
if (VMCI_ROUTE_AS_HOST == route)
return vmci_ctx_notify_dbell(VMCI_HOST_CONTEXT_ID,
dst, priv_flags);
if (VMCI_ROUTE_AS_GUEST == route)
return dbell_notify_as_guest(dst, priv_flags);
pr_warn("Unknown route (%d) for doorbell\n", route);
return VMCI_ERROR_DST_UNREACHABLE;
}
