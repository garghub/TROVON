static unsigned int vmci_resource_hash(struct vmci_handle handle)
{
return hash_32(handle.resource, VMCI_RESOURCE_HASH_BITS);
}
static struct vmci_resource *vmci_resource_lookup(struct vmci_handle handle,
enum vmci_resource_type type)
{
struct vmci_resource *r, *resource = NULL;
unsigned int idx = vmci_resource_hash(handle);
rcu_read_lock();
hlist_for_each_entry_rcu(r,
&vmci_resource_table.entries[idx], node) {
u32 cid = r->handle.context;
u32 rid = r->handle.resource;
if (r->type == type &&
rid == handle.resource &&
(cid == handle.context || cid == VMCI_INVALID_ID)) {
resource = r;
break;
}
}
rcu_read_unlock();
return resource;
}
static u32 vmci_resource_find_id(u32 context_id,
enum vmci_resource_type resource_type)
{
static u32 resource_id = VMCI_RESERVED_RESOURCE_ID_MAX + 1;
u32 old_rid = resource_id;
u32 current_rid;
do {
struct vmci_handle handle;
current_rid = resource_id;
resource_id++;
if (unlikely(resource_id == VMCI_INVALID_ID)) {
resource_id = VMCI_RESERVED_RESOURCE_ID_MAX + 1;
}
handle = vmci_make_handle(context_id, current_rid);
if (!vmci_resource_lookup(handle, resource_type))
return current_rid;
} while (resource_id != old_rid);
return VMCI_INVALID_ID;
}
int vmci_resource_add(struct vmci_resource *resource,
enum vmci_resource_type resource_type,
struct vmci_handle handle)
{
unsigned int idx;
int result;
spin_lock(&vmci_resource_table.lock);
if (handle.resource == VMCI_INVALID_ID) {
handle.resource = vmci_resource_find_id(handle.context,
resource_type);
if (handle.resource == VMCI_INVALID_ID) {
result = VMCI_ERROR_NO_HANDLE;
goto out;
}
} else if (vmci_resource_lookup(handle, resource_type)) {
result = VMCI_ERROR_ALREADY_EXISTS;
goto out;
}
resource->handle = handle;
resource->type = resource_type;
INIT_HLIST_NODE(&resource->node);
kref_init(&resource->kref);
init_completion(&resource->done);
idx = vmci_resource_hash(resource->handle);
hlist_add_head_rcu(&resource->node, &vmci_resource_table.entries[idx]);
result = VMCI_SUCCESS;
out:
spin_unlock(&vmci_resource_table.lock);
return result;
}
void vmci_resource_remove(struct vmci_resource *resource)
{
struct vmci_handle handle = resource->handle;
unsigned int idx = vmci_resource_hash(handle);
struct vmci_resource *r;
spin_lock(&vmci_resource_table.lock);
hlist_for_each_entry(r, &vmci_resource_table.entries[idx], node) {
if (vmci_handle_is_equal(r->handle, resource->handle)) {
hlist_del_init_rcu(&r->node);
break;
}
}
spin_unlock(&vmci_resource_table.lock);
synchronize_rcu();
vmci_resource_put(resource);
wait_for_completion(&resource->done);
}
struct vmci_resource *
vmci_resource_by_handle(struct vmci_handle resource_handle,
enum vmci_resource_type resource_type)
{
struct vmci_resource *r, *resource = NULL;
rcu_read_lock();
r = vmci_resource_lookup(resource_handle, resource_type);
if (r &&
(resource_type == r->type ||
resource_type == VMCI_RESOURCE_TYPE_ANY)) {
resource = vmci_resource_get(r);
}
rcu_read_unlock();
return resource;
}
struct vmci_resource *vmci_resource_get(struct vmci_resource *resource)
{
kref_get(&resource->kref);
return resource;
}
static void vmci_release_resource(struct kref *kref)
{
struct vmci_resource *resource =
container_of(kref, struct vmci_resource, kref);
WARN_ON(!hlist_unhashed(&resource->node));
complete(&resource->done);
}
int vmci_resource_put(struct vmci_resource *resource)
{
return kref_put(&resource->kref, vmci_release_resource) ?
VMCI_SUCCESS_ENTRY_DEAD : VMCI_SUCCESS;
}
struct vmci_handle vmci_resource_handle(struct vmci_resource *resource)
{
return resource->handle;
}
