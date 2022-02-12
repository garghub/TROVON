static void qp_free_queue(void *q, u64 size)
{
struct vmci_queue *queue = q;
if (queue) {
u64 i;
for (i = 0; i < DIV_ROUND_UP(size, PAGE_SIZE) + 1; i++) {
dma_free_coherent(&vmci_pdev->dev, PAGE_SIZE,
queue->kernel_if->u.g.vas[i],
queue->kernel_if->u.g.pas[i]);
}
vfree(queue);
}
}
static void *qp_alloc_queue(u64 size, u32 flags)
{
u64 i;
struct vmci_queue *queue;
const size_t num_pages = DIV_ROUND_UP(size, PAGE_SIZE) + 1;
const size_t pas_size = num_pages * sizeof(*queue->kernel_if->u.g.pas);
const size_t vas_size = num_pages * sizeof(*queue->kernel_if->u.g.vas);
const size_t queue_size =
sizeof(*queue) + sizeof(*queue->kernel_if) +
pas_size + vas_size;
queue = vmalloc(queue_size);
if (!queue)
return NULL;
queue->q_header = NULL;
queue->saved_header = NULL;
queue->kernel_if = (struct vmci_queue_kern_if *)(queue + 1);
queue->kernel_if->mutex = NULL;
queue->kernel_if->num_pages = num_pages;
queue->kernel_if->u.g.pas = (dma_addr_t *)(queue->kernel_if + 1);
queue->kernel_if->u.g.vas =
(void **)((u8 *)queue->kernel_if->u.g.pas + pas_size);
queue->kernel_if->host = false;
for (i = 0; i < num_pages; i++) {
queue->kernel_if->u.g.vas[i] =
dma_alloc_coherent(&vmci_pdev->dev, PAGE_SIZE,
&queue->kernel_if->u.g.pas[i],
GFP_KERNEL);
if (!queue->kernel_if->u.g.vas[i]) {
qp_free_queue(queue, i * PAGE_SIZE);
return NULL;
}
}
queue->q_header = queue->kernel_if->u.g.vas[0];
return queue;
}
static int __qp_memcpy_to_queue(struct vmci_queue *queue,
u64 queue_offset,
const void *src,
size_t size,
bool is_iovec)
{
struct vmci_queue_kern_if *kernel_if = queue->kernel_if;
size_t bytes_copied = 0;
while (bytes_copied < size) {
const u64 page_index =
(queue_offset + bytes_copied) / PAGE_SIZE;
const size_t page_offset =
(queue_offset + bytes_copied) & (PAGE_SIZE - 1);
void *va;
size_t to_copy;
if (kernel_if->host)
va = kmap(kernel_if->u.h.page[page_index]);
else
va = kernel_if->u.g.vas[page_index + 1];
if (size - bytes_copied > PAGE_SIZE - page_offset)
to_copy = PAGE_SIZE - page_offset;
else
to_copy = size - bytes_copied;
if (is_iovec) {
struct iovec *iov = (struct iovec *)src;
int err;
err = memcpy_fromiovec((u8 *)va + page_offset,
iov, to_copy);
if (err != 0) {
if (kernel_if->host)
kunmap(kernel_if->u.h.page[page_index]);
return VMCI_ERROR_INVALID_ARGS;
}
} else {
memcpy((u8 *)va + page_offset,
(u8 *)src + bytes_copied, to_copy);
}
bytes_copied += to_copy;
if (kernel_if->host)
kunmap(kernel_if->u.h.page[page_index]);
}
return VMCI_SUCCESS;
}
static int __qp_memcpy_from_queue(void *dest,
const struct vmci_queue *queue,
u64 queue_offset,
size_t size,
bool is_iovec)
{
struct vmci_queue_kern_if *kernel_if = queue->kernel_if;
size_t bytes_copied = 0;
while (bytes_copied < size) {
const u64 page_index =
(queue_offset + bytes_copied) / PAGE_SIZE;
const size_t page_offset =
(queue_offset + bytes_copied) & (PAGE_SIZE - 1);
void *va;
size_t to_copy;
if (kernel_if->host)
va = kmap(kernel_if->u.h.page[page_index]);
else
va = kernel_if->u.g.vas[page_index + 1];
if (size - bytes_copied > PAGE_SIZE - page_offset)
to_copy = PAGE_SIZE - page_offset;
else
to_copy = size - bytes_copied;
if (is_iovec) {
struct msghdr *msg = dest;
int err;
err = memcpy_to_msg(msg, (u8 *)va + page_offset,
to_copy);
if (err != 0) {
if (kernel_if->host)
kunmap(kernel_if->u.h.page[page_index]);
return VMCI_ERROR_INVALID_ARGS;
}
} else {
memcpy((u8 *)dest + bytes_copied,
(u8 *)va + page_offset, to_copy);
}
bytes_copied += to_copy;
if (kernel_if->host)
kunmap(kernel_if->u.h.page[page_index]);
}
return VMCI_SUCCESS;
}
static int qp_alloc_ppn_set(void *prod_q,
u64 num_produce_pages,
void *cons_q,
u64 num_consume_pages, struct ppn_set *ppn_set)
{
u32 *produce_ppns;
u32 *consume_ppns;
struct vmci_queue *produce_q = prod_q;
struct vmci_queue *consume_q = cons_q;
u64 i;
if (!produce_q || !num_produce_pages || !consume_q ||
!num_consume_pages || !ppn_set)
return VMCI_ERROR_INVALID_ARGS;
if (ppn_set->initialized)
return VMCI_ERROR_ALREADY_EXISTS;
produce_ppns =
kmalloc(num_produce_pages * sizeof(*produce_ppns), GFP_KERNEL);
if (!produce_ppns)
return VMCI_ERROR_NO_MEM;
consume_ppns =
kmalloc(num_consume_pages * sizeof(*consume_ppns), GFP_KERNEL);
if (!consume_ppns) {
kfree(produce_ppns);
return VMCI_ERROR_NO_MEM;
}
for (i = 0; i < num_produce_pages; i++) {
unsigned long pfn;
produce_ppns[i] =
produce_q->kernel_if->u.g.pas[i] >> PAGE_SHIFT;
pfn = produce_ppns[i];
if (sizeof(pfn) > sizeof(*produce_ppns)
&& pfn != produce_ppns[i])
goto ppn_error;
}
for (i = 0; i < num_consume_pages; i++) {
unsigned long pfn;
consume_ppns[i] =
consume_q->kernel_if->u.g.pas[i] >> PAGE_SHIFT;
pfn = consume_ppns[i];
if (sizeof(pfn) > sizeof(*consume_ppns)
&& pfn != consume_ppns[i])
goto ppn_error;
}
ppn_set->num_produce_pages = num_produce_pages;
ppn_set->num_consume_pages = num_consume_pages;
ppn_set->produce_ppns = produce_ppns;
ppn_set->consume_ppns = consume_ppns;
ppn_set->initialized = true;
return VMCI_SUCCESS;
ppn_error:
kfree(produce_ppns);
kfree(consume_ppns);
return VMCI_ERROR_INVALID_ARGS;
}
static void qp_free_ppn_set(struct ppn_set *ppn_set)
{
if (ppn_set->initialized) {
kfree(ppn_set->produce_ppns);
kfree(ppn_set->consume_ppns);
}
memset(ppn_set, 0, sizeof(*ppn_set));
}
static int qp_populate_ppn_set(u8 *call_buf, const struct ppn_set *ppn_set)
{
memcpy(call_buf, ppn_set->produce_ppns,
ppn_set->num_produce_pages * sizeof(*ppn_set->produce_ppns));
memcpy(call_buf +
ppn_set->num_produce_pages * sizeof(*ppn_set->produce_ppns),
ppn_set->consume_ppns,
ppn_set->num_consume_pages * sizeof(*ppn_set->consume_ppns));
return VMCI_SUCCESS;
}
static int qp_memcpy_to_queue(struct vmci_queue *queue,
u64 queue_offset,
const void *src, size_t src_offset, size_t size)
{
return __qp_memcpy_to_queue(queue, queue_offset,
(u8 *)src + src_offset, size, false);
}
static int qp_memcpy_from_queue(void *dest,
size_t dest_offset,
const struct vmci_queue *queue,
u64 queue_offset, size_t size)
{
return __qp_memcpy_from_queue((u8 *)dest + dest_offset,
queue, queue_offset, size, false);
}
static int qp_memcpy_to_queue_iov(struct vmci_queue *queue,
u64 queue_offset,
const void *src,
size_t src_offset, size_t size)
{
return __qp_memcpy_to_queue(queue, queue_offset, src, size, true);
}
static int qp_memcpy_from_queue_iov(void *dest,
size_t dest_offset,
const struct vmci_queue *queue,
u64 queue_offset, size_t size)
{
return __qp_memcpy_from_queue(dest, queue, queue_offset, size, true);
}
static struct vmci_queue *qp_host_alloc_queue(u64 size)
{
struct vmci_queue *queue;
const size_t num_pages = DIV_ROUND_UP(size, PAGE_SIZE) + 1;
const size_t queue_size = sizeof(*queue) + sizeof(*(queue->kernel_if));
const size_t queue_page_size =
num_pages * sizeof(*queue->kernel_if->u.h.page);
queue = kzalloc(queue_size + queue_page_size, GFP_KERNEL);
if (queue) {
queue->q_header = NULL;
queue->saved_header = NULL;
queue->kernel_if = (struct vmci_queue_kern_if *)(queue + 1);
queue->kernel_if->host = true;
queue->kernel_if->mutex = NULL;
queue->kernel_if->num_pages = num_pages;
queue->kernel_if->u.h.header_page =
(struct page **)((u8 *)queue + queue_size);
queue->kernel_if->u.h.page =
&queue->kernel_if->u.h.header_page[1];
}
return queue;
}
static void qp_host_free_queue(struct vmci_queue *queue, u64 queue_size)
{
kfree(queue);
}
static void qp_init_queue_mutex(struct vmci_queue *produce_q,
struct vmci_queue *consume_q)
{
if (produce_q->kernel_if->host) {
produce_q->kernel_if->mutex = &produce_q->kernel_if->__mutex;
consume_q->kernel_if->mutex = &produce_q->kernel_if->__mutex;
mutex_init(produce_q->kernel_if->mutex);
}
}
static void qp_cleanup_queue_mutex(struct vmci_queue *produce_q,
struct vmci_queue *consume_q)
{
if (produce_q->kernel_if->host) {
produce_q->kernel_if->mutex = NULL;
consume_q->kernel_if->mutex = NULL;
}
}
static void qp_acquire_queue_mutex(struct vmci_queue *queue)
{
if (queue->kernel_if->host)
mutex_lock(queue->kernel_if->mutex);
}
static void qp_release_queue_mutex(struct vmci_queue *queue)
{
if (queue->kernel_if->host)
mutex_unlock(queue->kernel_if->mutex);
}
static void qp_release_pages(struct page **pages,
u64 num_pages, bool dirty)
{
int i;
for (i = 0; i < num_pages; i++) {
if (dirty)
set_page_dirty(pages[i]);
page_cache_release(pages[i]);
pages[i] = NULL;
}
}
static int qp_host_get_user_memory(u64 produce_uva,
u64 consume_uva,
struct vmci_queue *produce_q,
struct vmci_queue *consume_q)
{
int retval;
int err = VMCI_SUCCESS;
retval = get_user_pages_fast((uintptr_t) produce_uva,
produce_q->kernel_if->num_pages, 1,
produce_q->kernel_if->u.h.header_page);
if (retval < produce_q->kernel_if->num_pages) {
pr_warn("get_user_pages(produce) failed (retval=%d)", retval);
qp_release_pages(produce_q->kernel_if->u.h.header_page,
retval, false);
err = VMCI_ERROR_NO_MEM;
goto out;
}
retval = get_user_pages_fast((uintptr_t) consume_uva,
consume_q->kernel_if->num_pages, 1,
consume_q->kernel_if->u.h.header_page);
if (retval < consume_q->kernel_if->num_pages) {
pr_warn("get_user_pages(consume) failed (retval=%d)", retval);
qp_release_pages(consume_q->kernel_if->u.h.header_page,
retval, false);
qp_release_pages(produce_q->kernel_if->u.h.header_page,
produce_q->kernel_if->num_pages, false);
err = VMCI_ERROR_NO_MEM;
}
out:
return err;
}
static int qp_host_register_user_memory(struct vmci_qp_page_store *page_store,
struct vmci_queue *produce_q,
struct vmci_queue *consume_q)
{
u64 produce_uva;
u64 consume_uva;
produce_uva = page_store->pages;
consume_uva = page_store->pages +
produce_q->kernel_if->num_pages * PAGE_SIZE;
return qp_host_get_user_memory(produce_uva, consume_uva, produce_q,
consume_q);
}
static void qp_host_unregister_user_memory(struct vmci_queue *produce_q,
struct vmci_queue *consume_q)
{
qp_release_pages(produce_q->kernel_if->u.h.header_page,
produce_q->kernel_if->num_pages, true);
memset(produce_q->kernel_if->u.h.header_page, 0,
sizeof(*produce_q->kernel_if->u.h.header_page) *
produce_q->kernel_if->num_pages);
qp_release_pages(consume_q->kernel_if->u.h.header_page,
consume_q->kernel_if->num_pages, true);
memset(consume_q->kernel_if->u.h.header_page, 0,
sizeof(*consume_q->kernel_if->u.h.header_page) *
consume_q->kernel_if->num_pages);
}
static int qp_host_map_queues(struct vmci_queue *produce_q,
struct vmci_queue *consume_q)
{
int result;
if (!produce_q->q_header || !consume_q->q_header) {
struct page *headers[2];
if (produce_q->q_header != consume_q->q_header)
return VMCI_ERROR_QUEUEPAIR_MISMATCH;
if (produce_q->kernel_if->u.h.header_page == NULL ||
*produce_q->kernel_if->u.h.header_page == NULL)
return VMCI_ERROR_UNAVAILABLE;
headers[0] = *produce_q->kernel_if->u.h.header_page;
headers[1] = *consume_q->kernel_if->u.h.header_page;
produce_q->q_header = vmap(headers, 2, VM_MAP, PAGE_KERNEL);
if (produce_q->q_header != NULL) {
consume_q->q_header =
(struct vmci_queue_header *)((u8 *)
produce_q->q_header +
PAGE_SIZE);
result = VMCI_SUCCESS;
} else {
pr_warn("vmap failed\n");
result = VMCI_ERROR_NO_MEM;
}
} else {
result = VMCI_SUCCESS;
}
return result;
}
static int qp_host_unmap_queues(u32 gid,
struct vmci_queue *produce_q,
struct vmci_queue *consume_q)
{
if (produce_q->q_header) {
if (produce_q->q_header < consume_q->q_header)
vunmap(produce_q->q_header);
else
vunmap(consume_q->q_header);
produce_q->q_header = NULL;
consume_q->q_header = NULL;
}
return VMCI_SUCCESS;
}
static struct qp_entry *qp_list_find(struct qp_list *qp_list,
struct vmci_handle handle)
{
struct qp_entry *entry;
if (vmci_handle_is_invalid(handle))
return NULL;
list_for_each_entry(entry, &qp_list->head, list_item) {
if (vmci_handle_is_equal(entry->handle, handle))
return entry;
}
return NULL;
}
static struct qp_guest_endpoint *
qp_guest_handle_to_entry(struct vmci_handle handle)
{
struct qp_guest_endpoint *entry;
struct qp_entry *qp = qp_list_find(&qp_guest_endpoints, handle);
entry = qp ? container_of(
qp, struct qp_guest_endpoint, qp) : NULL;
return entry;
}
static struct qp_broker_entry *
qp_broker_handle_to_entry(struct vmci_handle handle)
{
struct qp_broker_entry *entry;
struct qp_entry *qp = qp_list_find(&qp_broker_list, handle);
entry = qp ? container_of(
qp, struct qp_broker_entry, qp) : NULL;
return entry;
}
static int qp_notify_peer_local(bool attach, struct vmci_handle handle)
{
u32 context_id = vmci_get_context_id();
struct vmci_event_qp ev;
ev.msg.hdr.dst = vmci_make_handle(context_id, VMCI_EVENT_HANDLER);
ev.msg.hdr.src = vmci_make_handle(VMCI_HYPERVISOR_CONTEXT_ID,
VMCI_CONTEXT_RESOURCE_ID);
ev.msg.hdr.payload_size = sizeof(ev) - sizeof(ev.msg.hdr);
ev.msg.event_data.event =
attach ? VMCI_EVENT_QP_PEER_ATTACH : VMCI_EVENT_QP_PEER_DETACH;
ev.payload.peer_id = context_id;
ev.payload.handle = handle;
return vmci_event_dispatch(&ev.msg.hdr);
}
static struct qp_guest_endpoint *
qp_guest_endpoint_create(struct vmci_handle handle,
u32 peer,
u32 flags,
u64 produce_size,
u64 consume_size,
void *produce_q,
void *consume_q)
{
int result;
struct qp_guest_endpoint *entry;
const u64 num_ppns = DIV_ROUND_UP(produce_size, PAGE_SIZE) +
DIV_ROUND_UP(consume_size, PAGE_SIZE) + 2;
if (vmci_handle_is_invalid(handle)) {
u32 context_id = vmci_get_context_id();
handle = vmci_make_handle(context_id, VMCI_INVALID_ID);
}
entry = kzalloc(sizeof(*entry), GFP_KERNEL);
if (entry) {
entry->qp.peer = peer;
entry->qp.flags = flags;
entry->qp.produce_size = produce_size;
entry->qp.consume_size = consume_size;
entry->qp.ref_count = 0;
entry->num_ppns = num_ppns;
entry->produce_q = produce_q;
entry->consume_q = consume_q;
INIT_LIST_HEAD(&entry->qp.list_item);
result = vmci_resource_add(&entry->resource,
VMCI_RESOURCE_TYPE_QPAIR_GUEST,
handle);
entry->qp.handle = vmci_resource_handle(&entry->resource);
if ((result != VMCI_SUCCESS) ||
qp_list_find(&qp_guest_endpoints, entry->qp.handle)) {
pr_warn("Failed to add new resource (handle=0x%x:0x%x), error: %d",
handle.context, handle.resource, result);
kfree(entry);
entry = NULL;
}
}
return entry;
}
static void qp_guest_endpoint_destroy(struct qp_guest_endpoint *entry)
{
qp_free_ppn_set(&entry->ppn_set);
qp_cleanup_queue_mutex(entry->produce_q, entry->consume_q);
qp_free_queue(entry->produce_q, entry->qp.produce_size);
qp_free_queue(entry->consume_q, entry->qp.consume_size);
vmci_resource_remove(&entry->resource);
kfree(entry);
}
static int qp_alloc_hypercall(const struct qp_guest_endpoint *entry)
{
struct vmci_qp_alloc_msg *alloc_msg;
size_t msg_size;
int result;
if (!entry || entry->num_ppns <= 2)
return VMCI_ERROR_INVALID_ARGS;
msg_size = sizeof(*alloc_msg) +
(size_t) entry->num_ppns * sizeof(u32);
alloc_msg = kmalloc(msg_size, GFP_KERNEL);
if (!alloc_msg)
return VMCI_ERROR_NO_MEM;
alloc_msg->hdr.dst = vmci_make_handle(VMCI_HYPERVISOR_CONTEXT_ID,
VMCI_QUEUEPAIR_ALLOC);
alloc_msg->hdr.src = VMCI_ANON_SRC_HANDLE;
alloc_msg->hdr.payload_size = msg_size - VMCI_DG_HEADERSIZE;
alloc_msg->handle = entry->qp.handle;
alloc_msg->peer = entry->qp.peer;
alloc_msg->flags = entry->qp.flags;
alloc_msg->produce_size = entry->qp.produce_size;
alloc_msg->consume_size = entry->qp.consume_size;
alloc_msg->num_ppns = entry->num_ppns;
result = qp_populate_ppn_set((u8 *)alloc_msg + sizeof(*alloc_msg),
&entry->ppn_set);
if (result == VMCI_SUCCESS)
result = vmci_send_datagram(&alloc_msg->hdr);
kfree(alloc_msg);
return result;
}
static int qp_detatch_hypercall(struct vmci_handle handle)
{
struct vmci_qp_detach_msg detach_msg;
detach_msg.hdr.dst = vmci_make_handle(VMCI_HYPERVISOR_CONTEXT_ID,
VMCI_QUEUEPAIR_DETACH);
detach_msg.hdr.src = VMCI_ANON_SRC_HANDLE;
detach_msg.hdr.payload_size = sizeof(handle);
detach_msg.handle = handle;
return vmci_send_datagram(&detach_msg.hdr);
}
static void qp_list_add_entry(struct qp_list *qp_list, struct qp_entry *entry)
{
if (entry)
list_add(&entry->list_item, &qp_list->head);
}
static void qp_list_remove_entry(struct qp_list *qp_list,
struct qp_entry *entry)
{
if (entry)
list_del(&entry->list_item);
}
static int qp_detatch_guest_work(struct vmci_handle handle)
{
int result;
struct qp_guest_endpoint *entry;
u32 ref_count = ~0;
mutex_lock(&qp_guest_endpoints.mutex);
entry = qp_guest_handle_to_entry(handle);
if (!entry) {
mutex_unlock(&qp_guest_endpoints.mutex);
return VMCI_ERROR_NOT_FOUND;
}
if (entry->qp.flags & VMCI_QPFLAG_LOCAL) {
result = VMCI_SUCCESS;
if (entry->qp.ref_count > 1) {
result = qp_notify_peer_local(false, handle);
}
} else {
result = qp_detatch_hypercall(handle);
if (result < VMCI_SUCCESS) {
mutex_unlock(&qp_guest_endpoints.mutex);
return result;
}
}
entry->qp.ref_count--;
if (entry->qp.ref_count == 0)
qp_list_remove_entry(&qp_guest_endpoints, &entry->qp);
if (entry)
ref_count = entry->qp.ref_count;
mutex_unlock(&qp_guest_endpoints.mutex);
if (ref_count == 0)
qp_guest_endpoint_destroy(entry);
return result;
}
static int qp_alloc_guest_work(struct vmci_handle *handle,
struct vmci_queue **produce_q,
u64 produce_size,
struct vmci_queue **consume_q,
u64 consume_size,
u32 peer,
u32 flags,
u32 priv_flags)
{
const u64 num_produce_pages =
DIV_ROUND_UP(produce_size, PAGE_SIZE) + 1;
const u64 num_consume_pages =
DIV_ROUND_UP(consume_size, PAGE_SIZE) + 1;
void *my_produce_q = NULL;
void *my_consume_q = NULL;
int result;
struct qp_guest_endpoint *queue_pair_entry = NULL;
if (priv_flags != VMCI_NO_PRIVILEGE_FLAGS)
return VMCI_ERROR_NO_ACCESS;
mutex_lock(&qp_guest_endpoints.mutex);
queue_pair_entry = qp_guest_handle_to_entry(*handle);
if (queue_pair_entry) {
if (queue_pair_entry->qp.flags & VMCI_QPFLAG_LOCAL) {
if (queue_pair_entry->qp.ref_count > 1) {
pr_devel("Error attempting to attach more than once\n");
result = VMCI_ERROR_UNAVAILABLE;
goto error_keep_entry;
}
if (queue_pair_entry->qp.produce_size != consume_size ||
queue_pair_entry->qp.consume_size !=
produce_size ||
queue_pair_entry->qp.flags !=
(flags & ~VMCI_QPFLAG_ATTACH_ONLY)) {
pr_devel("Error mismatched queue pair in local attach\n");
result = VMCI_ERROR_QUEUEPAIR_MISMATCH;
goto error_keep_entry;
}
result = qp_notify_peer_local(true, *handle);
if (result < VMCI_SUCCESS)
goto error_keep_entry;
my_produce_q = queue_pair_entry->consume_q;
my_consume_q = queue_pair_entry->produce_q;
goto out;
}
result = VMCI_ERROR_ALREADY_EXISTS;
goto error_keep_entry;
}
my_produce_q = qp_alloc_queue(produce_size, flags);
if (!my_produce_q) {
pr_warn("Error allocating pages for produce queue\n");
result = VMCI_ERROR_NO_MEM;
goto error;
}
my_consume_q = qp_alloc_queue(consume_size, flags);
if (!my_consume_q) {
pr_warn("Error allocating pages for consume queue\n");
result = VMCI_ERROR_NO_MEM;
goto error;
}
queue_pair_entry = qp_guest_endpoint_create(*handle, peer, flags,
produce_size, consume_size,
my_produce_q, my_consume_q);
if (!queue_pair_entry) {
pr_warn("Error allocating memory in %s\n", __func__);
result = VMCI_ERROR_NO_MEM;
goto error;
}
result = qp_alloc_ppn_set(my_produce_q, num_produce_pages, my_consume_q,
num_consume_pages,
&queue_pair_entry->ppn_set);
if (result < VMCI_SUCCESS) {
pr_warn("qp_alloc_ppn_set failed\n");
goto error;
}
if (queue_pair_entry->qp.flags & VMCI_QPFLAG_LOCAL) {
u32 context_id = vmci_get_context_id();
if (queue_pair_entry->qp.handle.context != context_id ||
(queue_pair_entry->qp.peer != VMCI_INVALID_ID &&
queue_pair_entry->qp.peer != context_id)) {
result = VMCI_ERROR_NO_ACCESS;
goto error;
}
if (queue_pair_entry->qp.flags & VMCI_QPFLAG_ATTACH_ONLY) {
result = VMCI_ERROR_NOT_FOUND;
goto error;
}
} else {
result = qp_alloc_hypercall(queue_pair_entry);
if (result < VMCI_SUCCESS) {
pr_warn("qp_alloc_hypercall result = %d\n", result);
goto error;
}
}
qp_init_queue_mutex((struct vmci_queue *)my_produce_q,
(struct vmci_queue *)my_consume_q);
qp_list_add_entry(&qp_guest_endpoints, &queue_pair_entry->qp);
out:
queue_pair_entry->qp.ref_count++;
*handle = queue_pair_entry->qp.handle;
*produce_q = (struct vmci_queue *)my_produce_q;
*consume_q = (struct vmci_queue *)my_consume_q;
if ((queue_pair_entry->qp.flags & VMCI_QPFLAG_LOCAL) &&
queue_pair_entry->qp.ref_count == 1) {
vmci_q_header_init((*produce_q)->q_header, *handle);
vmci_q_header_init((*consume_q)->q_header, *handle);
}
mutex_unlock(&qp_guest_endpoints.mutex);
return VMCI_SUCCESS;
error:
mutex_unlock(&qp_guest_endpoints.mutex);
if (queue_pair_entry) {
qp_guest_endpoint_destroy(queue_pair_entry);
} else {
qp_free_queue(my_produce_q, produce_size);
qp_free_queue(my_consume_q, consume_size);
}
return result;
error_keep_entry:
mutex_unlock(&qp_guest_endpoints.mutex);
return result;
}
static int qp_broker_create(struct vmci_handle handle,
u32 peer,
u32 flags,
u32 priv_flags,
u64 produce_size,
u64 consume_size,
struct vmci_qp_page_store *page_store,
struct vmci_ctx *context,
vmci_event_release_cb wakeup_cb,
void *client_data, struct qp_broker_entry **ent)
{
struct qp_broker_entry *entry = NULL;
const u32 context_id = vmci_ctx_get_id(context);
bool is_local = flags & VMCI_QPFLAG_LOCAL;
int result;
u64 guest_produce_size;
u64 guest_consume_size;
if (flags & VMCI_QPFLAG_ATTACH_ONLY)
return VMCI_ERROR_NOT_FOUND;
if (handle.context != context_id && handle.context != peer)
return VMCI_ERROR_NO_ACCESS;
if (VMCI_CONTEXT_IS_VM(context_id) && VMCI_CONTEXT_IS_VM(peer))
return VMCI_ERROR_DST_UNREACHABLE;
if (is_local && peer != VMCI_INVALID_ID && context_id != peer)
return VMCI_ERROR_NO_ACCESS;
entry = kzalloc(sizeof(*entry), GFP_ATOMIC);
if (!entry)
return VMCI_ERROR_NO_MEM;
if (vmci_ctx_get_id(context) == VMCI_HOST_CONTEXT_ID && !is_local) {
guest_produce_size = consume_size;
guest_consume_size = produce_size;
} else {
guest_produce_size = produce_size;
guest_consume_size = consume_size;
}
entry->qp.handle = handle;
entry->qp.peer = peer;
entry->qp.flags = flags;
entry->qp.produce_size = guest_produce_size;
entry->qp.consume_size = guest_consume_size;
entry->qp.ref_count = 1;
entry->create_id = context_id;
entry->attach_id = VMCI_INVALID_ID;
entry->state = VMCIQPB_NEW;
entry->require_trusted_attach =
!!(context->priv_flags & VMCI_PRIVILEGE_FLAG_RESTRICTED);
entry->created_by_trusted =
!!(priv_flags & VMCI_PRIVILEGE_FLAG_TRUSTED);
entry->vmci_page_files = false;
entry->wakeup_cb = wakeup_cb;
entry->client_data = client_data;
entry->produce_q = qp_host_alloc_queue(guest_produce_size);
if (entry->produce_q == NULL) {
result = VMCI_ERROR_NO_MEM;
goto error;
}
entry->consume_q = qp_host_alloc_queue(guest_consume_size);
if (entry->consume_q == NULL) {
result = VMCI_ERROR_NO_MEM;
goto error;
}
qp_init_queue_mutex(entry->produce_q, entry->consume_q);
INIT_LIST_HEAD(&entry->qp.list_item);
if (is_local) {
u8 *tmp;
entry->local_mem = kcalloc(QPE_NUM_PAGES(entry->qp),
PAGE_SIZE, GFP_KERNEL);
if (entry->local_mem == NULL) {
result = VMCI_ERROR_NO_MEM;
goto error;
}
entry->state = VMCIQPB_CREATED_MEM;
entry->produce_q->q_header = entry->local_mem;
tmp = (u8 *)entry->local_mem + PAGE_SIZE *
(DIV_ROUND_UP(entry->qp.produce_size, PAGE_SIZE) + 1);
entry->consume_q->q_header = (struct vmci_queue_header *)tmp;
} else if (page_store) {
result = qp_host_register_user_memory(page_store,
entry->produce_q,
entry->consume_q);
if (result < VMCI_SUCCESS)
goto error;
entry->state = VMCIQPB_CREATED_MEM;
} else {
entry->state = VMCIQPB_CREATED_NO_MEM;
}
qp_list_add_entry(&qp_broker_list, &entry->qp);
if (ent != NULL)
*ent = entry;
result = vmci_resource_add(&entry->resource,
VMCI_RESOURCE_TYPE_QPAIR_HOST,
handle);
if (result != VMCI_SUCCESS) {
pr_warn("Failed to add new resource (handle=0x%x:0x%x), error: %d",
handle.context, handle.resource, result);
goto error;
}
entry->qp.handle = vmci_resource_handle(&entry->resource);
if (is_local) {
vmci_q_header_init(entry->produce_q->q_header,
entry->qp.handle);
vmci_q_header_init(entry->consume_q->q_header,
entry->qp.handle);
}
vmci_ctx_qp_create(context, entry->qp.handle);
return VMCI_SUCCESS;
error:
if (entry != NULL) {
qp_host_free_queue(entry->produce_q, guest_produce_size);
qp_host_free_queue(entry->consume_q, guest_consume_size);
kfree(entry);
}
return result;
}
static int qp_notify_peer(bool attach,
struct vmci_handle handle,
u32 my_id,
u32 peer_id)
{
int rv;
struct vmci_event_qp ev;
if (vmci_handle_is_invalid(handle) || my_id == VMCI_INVALID_ID ||
peer_id == VMCI_INVALID_ID)
return VMCI_ERROR_INVALID_ARGS;
ev.msg.hdr.dst = vmci_make_handle(peer_id, VMCI_EVENT_HANDLER);
ev.msg.hdr.src = vmci_make_handle(VMCI_HYPERVISOR_CONTEXT_ID,
VMCI_CONTEXT_RESOURCE_ID);
ev.msg.hdr.payload_size = sizeof(ev) - sizeof(ev.msg.hdr);
ev.msg.event_data.event = attach ?
VMCI_EVENT_QP_PEER_ATTACH : VMCI_EVENT_QP_PEER_DETACH;
ev.payload.handle = handle;
ev.payload.peer_id = my_id;
rv = vmci_datagram_dispatch(VMCI_HYPERVISOR_CONTEXT_ID,
&ev.msg.hdr, false);
if (rv < VMCI_SUCCESS)
pr_warn("Failed to enqueue queue_pair %s event datagram for context (ID=0x%x)\n",
attach ? "ATTACH" : "DETACH", peer_id);
return rv;
}
static int qp_broker_attach(struct qp_broker_entry *entry,
u32 peer,
u32 flags,
u32 priv_flags,
u64 produce_size,
u64 consume_size,
struct vmci_qp_page_store *page_store,
struct vmci_ctx *context,
vmci_event_release_cb wakeup_cb,
void *client_data,
struct qp_broker_entry **ent)
{
const u32 context_id = vmci_ctx_get_id(context);
bool is_local = flags & VMCI_QPFLAG_LOCAL;
int result;
if (entry->state != VMCIQPB_CREATED_NO_MEM &&
entry->state != VMCIQPB_CREATED_MEM)
return VMCI_ERROR_UNAVAILABLE;
if (is_local) {
if (!(entry->qp.flags & VMCI_QPFLAG_LOCAL) ||
context_id != entry->create_id) {
return VMCI_ERROR_INVALID_ARGS;
}
} else if (context_id == entry->create_id ||
context_id == entry->attach_id) {
return VMCI_ERROR_ALREADY_EXISTS;
}
if (VMCI_CONTEXT_IS_VM(context_id) &&
VMCI_CONTEXT_IS_VM(entry->create_id))
return VMCI_ERROR_DST_UNREACHABLE;
if ((context->priv_flags & VMCI_PRIVILEGE_FLAG_RESTRICTED) &&
!entry->created_by_trusted)
return VMCI_ERROR_NO_ACCESS;
if (entry->require_trusted_attach &&
(!(priv_flags & VMCI_PRIVILEGE_FLAG_TRUSTED)))
return VMCI_ERROR_NO_ACCESS;
if (entry->qp.peer != VMCI_INVALID_ID && entry->qp.peer != context_id)
return VMCI_ERROR_NO_ACCESS;
if (entry->create_id == VMCI_HOST_CONTEXT_ID) {
if (!vmci_ctx_supports_host_qp(context))
return VMCI_ERROR_INVALID_RESOURCE;
} else if (context_id == VMCI_HOST_CONTEXT_ID) {
struct vmci_ctx *create_context;
bool supports_host_qp;
create_context = vmci_ctx_get(entry->create_id);
supports_host_qp = vmci_ctx_supports_host_qp(create_context);
vmci_ctx_put(create_context);
if (!supports_host_qp)
return VMCI_ERROR_INVALID_RESOURCE;
}
if ((entry->qp.flags & ~VMCI_QP_ASYMM) != (flags & ~VMCI_QP_ASYMM_PEER))
return VMCI_ERROR_QUEUEPAIR_MISMATCH;
if (context_id != VMCI_HOST_CONTEXT_ID) {
if (entry->qp.produce_size != produce_size ||
entry->qp.consume_size != consume_size) {
return VMCI_ERROR_QUEUEPAIR_MISMATCH;
}
} else if (entry->qp.produce_size != consume_size ||
entry->qp.consume_size != produce_size) {
return VMCI_ERROR_QUEUEPAIR_MISMATCH;
}
if (context_id != VMCI_HOST_CONTEXT_ID) {
if (entry->state != VMCIQPB_CREATED_NO_MEM)
return VMCI_ERROR_INVALID_ARGS;
if (page_store != NULL) {
result = qp_host_register_user_memory(page_store,
entry->produce_q,
entry->consume_q);
if (result < VMCI_SUCCESS)
return result;
entry->state = VMCIQPB_ATTACHED_MEM;
} else {
entry->state = VMCIQPB_ATTACHED_NO_MEM;
}
} else if (entry->state == VMCIQPB_CREATED_NO_MEM) {
return VMCI_ERROR_UNAVAILABLE;
} else {
entry->state = VMCIQPB_ATTACHED_MEM;
}
if (entry->state == VMCIQPB_ATTACHED_MEM) {
result =
qp_notify_peer(true, entry->qp.handle, context_id,
entry->create_id);
if (result < VMCI_SUCCESS)
pr_warn("Failed to notify peer (ID=0x%x) of attach to queue pair (handle=0x%x:0x%x)\n",
entry->create_id, entry->qp.handle.context,
entry->qp.handle.resource);
}
entry->attach_id = context_id;
entry->qp.ref_count++;
if (wakeup_cb) {
entry->wakeup_cb = wakeup_cb;
entry->client_data = client_data;
}
if (!is_local)
vmci_ctx_qp_create(context, entry->qp.handle);
if (ent != NULL)
*ent = entry;
return VMCI_SUCCESS;
}
static int qp_broker_alloc(struct vmci_handle handle,
u32 peer,
u32 flags,
u32 priv_flags,
u64 produce_size,
u64 consume_size,
struct vmci_qp_page_store *page_store,
struct vmci_ctx *context,
vmci_event_release_cb wakeup_cb,
void *client_data,
struct qp_broker_entry **ent,
bool *swap)
{
const u32 context_id = vmci_ctx_get_id(context);
bool create;
struct qp_broker_entry *entry = NULL;
bool is_local = flags & VMCI_QPFLAG_LOCAL;
int result;
if (vmci_handle_is_invalid(handle) ||
(flags & ~VMCI_QP_ALL_FLAGS) || is_local ||
!(produce_size || consume_size) ||
!context || context_id == VMCI_INVALID_ID ||
handle.context == VMCI_INVALID_ID) {
return VMCI_ERROR_INVALID_ARGS;
}
if (page_store && !VMCI_QP_PAGESTORE_IS_WELLFORMED(page_store))
return VMCI_ERROR_INVALID_ARGS;
mutex_lock(&qp_broker_list.mutex);
if (!is_local && vmci_ctx_qp_exists(context, handle)) {
pr_devel("Context (ID=0x%x) already attached to queue pair (handle=0x%x:0x%x)\n",
context_id, handle.context, handle.resource);
mutex_unlock(&qp_broker_list.mutex);
return VMCI_ERROR_ALREADY_EXISTS;
}
if (handle.resource != VMCI_INVALID_ID)
entry = qp_broker_handle_to_entry(handle);
if (!entry) {
create = true;
result =
qp_broker_create(handle, peer, flags, priv_flags,
produce_size, consume_size, page_store,
context, wakeup_cb, client_data, ent);
} else {
create = false;
result =
qp_broker_attach(entry, peer, flags, priv_flags,
produce_size, consume_size, page_store,
context, wakeup_cb, client_data, ent);
}
mutex_unlock(&qp_broker_list.mutex);
if (swap)
*swap = (context_id == VMCI_HOST_CONTEXT_ID) &&
!(create && is_local);
return result;
}
static int qp_alloc_host_work(struct vmci_handle *handle,
struct vmci_queue **produce_q,
u64 produce_size,
struct vmci_queue **consume_q,
u64 consume_size,
u32 peer,
u32 flags,
u32 priv_flags,
vmci_event_release_cb wakeup_cb,
void *client_data)
{
struct vmci_handle new_handle;
struct vmci_ctx *context;
struct qp_broker_entry *entry;
int result;
bool swap;
if (vmci_handle_is_invalid(*handle)) {
new_handle = vmci_make_handle(
VMCI_HOST_CONTEXT_ID, VMCI_INVALID_ID);
} else
new_handle = *handle;
context = vmci_ctx_get(VMCI_HOST_CONTEXT_ID);
entry = NULL;
result =
qp_broker_alloc(new_handle, peer, flags, priv_flags,
produce_size, consume_size, NULL, context,
wakeup_cb, client_data, &entry, &swap);
if (result == VMCI_SUCCESS) {
if (swap) {
*produce_q = entry->consume_q;
*consume_q = entry->produce_q;
} else {
*produce_q = entry->produce_q;
*consume_q = entry->consume_q;
}
*handle = vmci_resource_handle(&entry->resource);
} else {
*handle = VMCI_INVALID_HANDLE;
pr_devel("queue pair broker failed to alloc (result=%d)\n",
result);
}
vmci_ctx_put(context);
return result;
}
int vmci_qp_alloc(struct vmci_handle *handle,
struct vmci_queue **produce_q,
u64 produce_size,
struct vmci_queue **consume_q,
u64 consume_size,
u32 peer,
u32 flags,
u32 priv_flags,
bool guest_endpoint,
vmci_event_release_cb wakeup_cb,
void *client_data)
{
if (!handle || !produce_q || !consume_q ||
(!produce_size && !consume_size) || (flags & ~VMCI_QP_ALL_FLAGS))
return VMCI_ERROR_INVALID_ARGS;
if (guest_endpoint) {
return qp_alloc_guest_work(handle, produce_q,
produce_size, consume_q,
consume_size, peer,
flags, priv_flags);
} else {
return qp_alloc_host_work(handle, produce_q,
produce_size, consume_q,
consume_size, peer, flags,
priv_flags, wakeup_cb, client_data);
}
}
static int qp_detatch_host_work(struct vmci_handle handle)
{
int result;
struct vmci_ctx *context;
context = vmci_ctx_get(VMCI_HOST_CONTEXT_ID);
result = vmci_qp_broker_detach(handle, context);
vmci_ctx_put(context);
return result;
}
static int qp_detatch(struct vmci_handle handle, bool guest_endpoint)
{
if (vmci_handle_is_invalid(handle))
return VMCI_ERROR_INVALID_ARGS;
if (guest_endpoint)
return qp_detatch_guest_work(handle);
else
return qp_detatch_host_work(handle);
}
static struct qp_entry *qp_list_get_head(struct qp_list *qp_list)
{
if (!list_empty(&qp_list->head)) {
struct qp_entry *entry =
list_first_entry(&qp_list->head, struct qp_entry,
list_item);
return entry;
}
return NULL;
}
void vmci_qp_broker_exit(void)
{
struct qp_entry *entry;
struct qp_broker_entry *be;
mutex_lock(&qp_broker_list.mutex);
while ((entry = qp_list_get_head(&qp_broker_list))) {
be = (struct qp_broker_entry *)entry;
qp_list_remove_entry(&qp_broker_list, entry);
kfree(be);
}
mutex_unlock(&qp_broker_list.mutex);
}
int vmci_qp_broker_alloc(struct vmci_handle handle,
u32 peer,
u32 flags,
u32 priv_flags,
u64 produce_size,
u64 consume_size,
struct vmci_qp_page_store *page_store,
struct vmci_ctx *context)
{
return qp_broker_alloc(handle, peer, flags, priv_flags,
produce_size, consume_size,
page_store, context, NULL, NULL, NULL, NULL);
}
int vmci_qp_broker_set_page_store(struct vmci_handle handle,
u64 produce_uva,
u64 consume_uva,
struct vmci_ctx *context)
{
struct qp_broker_entry *entry;
int result;
const u32 context_id = vmci_ctx_get_id(context);
if (vmci_handle_is_invalid(handle) || !context ||
context_id == VMCI_INVALID_ID)
return VMCI_ERROR_INVALID_ARGS;
if (produce_uva == 0 || consume_uva == 0)
return VMCI_ERROR_INVALID_ARGS;
mutex_lock(&qp_broker_list.mutex);
if (!vmci_ctx_qp_exists(context, handle)) {
pr_warn("Context (ID=0x%x) not attached to queue pair (handle=0x%x:0x%x)\n",
context_id, handle.context, handle.resource);
result = VMCI_ERROR_NOT_FOUND;
goto out;
}
entry = qp_broker_handle_to_entry(handle);
if (!entry) {
result = VMCI_ERROR_NOT_FOUND;
goto out;
}
if (entry->create_id != context_id &&
(entry->create_id != VMCI_HOST_CONTEXT_ID ||
entry->attach_id != context_id)) {
result = VMCI_ERROR_QUEUEPAIR_NOTOWNER;
goto out;
}
if (entry->state != VMCIQPB_CREATED_NO_MEM &&
entry->state != VMCIQPB_ATTACHED_NO_MEM) {
result = VMCI_ERROR_UNAVAILABLE;
goto out;
}
result = qp_host_get_user_memory(produce_uva, consume_uva,
entry->produce_q, entry->consume_q);
if (result < VMCI_SUCCESS)
goto out;
result = qp_host_map_queues(entry->produce_q, entry->consume_q);
if (result < VMCI_SUCCESS) {
qp_host_unregister_user_memory(entry->produce_q,
entry->consume_q);
goto out;
}
if (entry->state == VMCIQPB_CREATED_NO_MEM)
entry->state = VMCIQPB_CREATED_MEM;
else
entry->state = VMCIQPB_ATTACHED_MEM;
entry->vmci_page_files = true;
if (entry->state == VMCIQPB_ATTACHED_MEM) {
result =
qp_notify_peer(true, handle, context_id, entry->create_id);
if (result < VMCI_SUCCESS) {
pr_warn("Failed to notify peer (ID=0x%x) of attach to queue pair (handle=0x%x:0x%x)\n",
entry->create_id, entry->qp.handle.context,
entry->qp.handle.resource);
}
}
result = VMCI_SUCCESS;
out:
mutex_unlock(&qp_broker_list.mutex);
return result;
}
static void qp_reset_saved_headers(struct qp_broker_entry *entry)
{
entry->produce_q->saved_header = NULL;
entry->consume_q->saved_header = NULL;
}
int vmci_qp_broker_detach(struct vmci_handle handle, struct vmci_ctx *context)
{
struct qp_broker_entry *entry;
const u32 context_id = vmci_ctx_get_id(context);
u32 peer_id;
bool is_local = false;
int result;
if (vmci_handle_is_invalid(handle) || !context ||
context_id == VMCI_INVALID_ID) {
return VMCI_ERROR_INVALID_ARGS;
}
mutex_lock(&qp_broker_list.mutex);
if (!vmci_ctx_qp_exists(context, handle)) {
pr_devel("Context (ID=0x%x) not attached to queue pair (handle=0x%x:0x%x)\n",
context_id, handle.context, handle.resource);
result = VMCI_ERROR_NOT_FOUND;
goto out;
}
entry = qp_broker_handle_to_entry(handle);
if (!entry) {
pr_devel("Context (ID=0x%x) reports being attached to queue pair(handle=0x%x:0x%x) that isn't present in broker\n",
context_id, handle.context, handle.resource);
result = VMCI_ERROR_NOT_FOUND;
goto out;
}
if (context_id != entry->create_id && context_id != entry->attach_id) {
result = VMCI_ERROR_QUEUEPAIR_NOTATTACHED;
goto out;
}
if (context_id == entry->create_id) {
peer_id = entry->attach_id;
entry->create_id = VMCI_INVALID_ID;
} else {
peer_id = entry->create_id;
entry->attach_id = VMCI_INVALID_ID;
}
entry->qp.ref_count--;
is_local = entry->qp.flags & VMCI_QPFLAG_LOCAL;
if (context_id != VMCI_HOST_CONTEXT_ID) {
bool headers_mapped;
qp_acquire_queue_mutex(entry->produce_q);
headers_mapped = entry->produce_q->q_header ||
entry->consume_q->q_header;
if (QPBROKERSTATE_HAS_MEM(entry)) {
result =
qp_host_unmap_queues(INVALID_VMCI_GUEST_MEM_ID,
entry->produce_q,
entry->consume_q);
if (result < VMCI_SUCCESS)
pr_warn("Failed to unmap queue headers for queue pair (handle=0x%x:0x%x,result=%d)\n",
handle.context, handle.resource,
result);
if (entry->vmci_page_files)
qp_host_unregister_user_memory(entry->produce_q,
entry->
consume_q);
else
qp_host_unregister_user_memory(entry->produce_q,
entry->
consume_q);
}
if (!headers_mapped)
qp_reset_saved_headers(entry);
qp_release_queue_mutex(entry->produce_q);
if (!headers_mapped && entry->wakeup_cb)
entry->wakeup_cb(entry->client_data);
} else {
if (entry->wakeup_cb) {
entry->wakeup_cb = NULL;
entry->client_data = NULL;
}
}
if (entry->qp.ref_count == 0) {
qp_list_remove_entry(&qp_broker_list, &entry->qp);
if (is_local)
kfree(entry->local_mem);
qp_cleanup_queue_mutex(entry->produce_q, entry->consume_q);
qp_host_free_queue(entry->produce_q, entry->qp.produce_size);
qp_host_free_queue(entry->consume_q, entry->qp.consume_size);
vmci_resource_remove(&entry->resource);
kfree(entry);
vmci_ctx_qp_destroy(context, handle);
} else {
qp_notify_peer(false, handle, context_id, peer_id);
if (context_id == VMCI_HOST_CONTEXT_ID &&
QPBROKERSTATE_HAS_MEM(entry)) {
entry->state = VMCIQPB_SHUTDOWN_MEM;
} else {
entry->state = VMCIQPB_SHUTDOWN_NO_MEM;
}
if (!is_local)
vmci_ctx_qp_destroy(context, handle);
}
result = VMCI_SUCCESS;
out:
mutex_unlock(&qp_broker_list.mutex);
return result;
}
int vmci_qp_broker_map(struct vmci_handle handle,
struct vmci_ctx *context,
u64 guest_mem)
{
struct qp_broker_entry *entry;
const u32 context_id = vmci_ctx_get_id(context);
bool is_local = false;
int result;
if (vmci_handle_is_invalid(handle) || !context ||
context_id == VMCI_INVALID_ID)
return VMCI_ERROR_INVALID_ARGS;
mutex_lock(&qp_broker_list.mutex);
if (!vmci_ctx_qp_exists(context, handle)) {
pr_devel("Context (ID=0x%x) not attached to queue pair (handle=0x%x:0x%x)\n",
context_id, handle.context, handle.resource);
result = VMCI_ERROR_NOT_FOUND;
goto out;
}
entry = qp_broker_handle_to_entry(handle);
if (!entry) {
pr_devel("Context (ID=0x%x) reports being attached to queue pair (handle=0x%x:0x%x) that isn't present in broker\n",
context_id, handle.context, handle.resource);
result = VMCI_ERROR_NOT_FOUND;
goto out;
}
if (context_id != entry->create_id && context_id != entry->attach_id) {
result = VMCI_ERROR_QUEUEPAIR_NOTATTACHED;
goto out;
}
is_local = entry->qp.flags & VMCI_QPFLAG_LOCAL;
result = VMCI_SUCCESS;
if (context_id != VMCI_HOST_CONTEXT_ID) {
struct vmci_qp_page_store page_store;
page_store.pages = guest_mem;
page_store.len = QPE_NUM_PAGES(entry->qp);
qp_acquire_queue_mutex(entry->produce_q);
qp_reset_saved_headers(entry);
result =
qp_host_register_user_memory(&page_store,
entry->produce_q,
entry->consume_q);
qp_release_queue_mutex(entry->produce_q);
if (result == VMCI_SUCCESS) {
entry->state++;
if (entry->wakeup_cb)
entry->wakeup_cb(entry->client_data);
}
}
out:
mutex_unlock(&qp_broker_list.mutex);
return result;
}
static int qp_save_headers(struct qp_broker_entry *entry)
{
int result;
if (entry->produce_q->saved_header != NULL &&
entry->consume_q->saved_header != NULL) {
return VMCI_SUCCESS;
}
if (NULL == entry->produce_q->q_header ||
NULL == entry->consume_q->q_header) {
result = qp_host_map_queues(entry->produce_q, entry->consume_q);
if (result < VMCI_SUCCESS)
return result;
}
memcpy(&entry->saved_produce_q, entry->produce_q->q_header,
sizeof(entry->saved_produce_q));
entry->produce_q->saved_header = &entry->saved_produce_q;
memcpy(&entry->saved_consume_q, entry->consume_q->q_header,
sizeof(entry->saved_consume_q));
entry->consume_q->saved_header = &entry->saved_consume_q;
return VMCI_SUCCESS;
}
int vmci_qp_broker_unmap(struct vmci_handle handle,
struct vmci_ctx *context,
u32 gid)
{
struct qp_broker_entry *entry;
const u32 context_id = vmci_ctx_get_id(context);
bool is_local = false;
int result;
if (vmci_handle_is_invalid(handle) || !context ||
context_id == VMCI_INVALID_ID)
return VMCI_ERROR_INVALID_ARGS;
mutex_lock(&qp_broker_list.mutex);
if (!vmci_ctx_qp_exists(context, handle)) {
pr_devel("Context (ID=0x%x) not attached to queue pair (handle=0x%x:0x%x)\n",
context_id, handle.context, handle.resource);
result = VMCI_ERROR_NOT_FOUND;
goto out;
}
entry = qp_broker_handle_to_entry(handle);
if (!entry) {
pr_devel("Context (ID=0x%x) reports being attached to queue pair (handle=0x%x:0x%x) that isn't present in broker\n",
context_id, handle.context, handle.resource);
result = VMCI_ERROR_NOT_FOUND;
goto out;
}
if (context_id != entry->create_id && context_id != entry->attach_id) {
result = VMCI_ERROR_QUEUEPAIR_NOTATTACHED;
goto out;
}
is_local = entry->qp.flags & VMCI_QPFLAG_LOCAL;
if (context_id != VMCI_HOST_CONTEXT_ID) {
qp_acquire_queue_mutex(entry->produce_q);
result = qp_save_headers(entry);
if (result < VMCI_SUCCESS)
pr_warn("Failed to save queue headers for queue pair (handle=0x%x:0x%x,result=%d)\n",
handle.context, handle.resource, result);
qp_host_unmap_queues(gid, entry->produce_q, entry->consume_q);
qp_host_unregister_user_memory(entry->produce_q,
entry->consume_q);
entry->state--;
qp_release_queue_mutex(entry->produce_q);
}
result = VMCI_SUCCESS;
out:
mutex_unlock(&qp_broker_list.mutex);
return result;
}
void vmci_qp_guest_endpoints_exit(void)
{
struct qp_entry *entry;
struct qp_guest_endpoint *ep;
mutex_lock(&qp_guest_endpoints.mutex);
while ((entry = qp_list_get_head(&qp_guest_endpoints))) {
ep = (struct qp_guest_endpoint *)entry;
if (!(entry->flags & VMCI_QPFLAG_LOCAL))
qp_detatch_hypercall(entry->handle);
entry->ref_count = 0;
qp_list_remove_entry(&qp_guest_endpoints, entry);
qp_guest_endpoint_destroy(ep);
}
mutex_unlock(&qp_guest_endpoints.mutex);
}
static void qp_lock(const struct vmci_qp *qpair)
{
qp_acquire_queue_mutex(qpair->produce_q);
}
static void qp_unlock(const struct vmci_qp *qpair)
{
qp_release_queue_mutex(qpair->produce_q);
}
static int qp_map_queue_headers(struct vmci_queue *produce_q,
struct vmci_queue *consume_q)
{
int result;
if (NULL == produce_q->q_header || NULL == consume_q->q_header) {
result = qp_host_map_queues(produce_q, consume_q);
if (result < VMCI_SUCCESS)
return (produce_q->saved_header &&
consume_q->saved_header) ?
VMCI_ERROR_QUEUEPAIR_NOT_READY :
VMCI_ERROR_QUEUEPAIR_NOTATTACHED;
}
return VMCI_SUCCESS;
}
static int qp_get_queue_headers(const struct vmci_qp *qpair,
struct vmci_queue_header **produce_q_header,
struct vmci_queue_header **consume_q_header)
{
int result;
result = qp_map_queue_headers(qpair->produce_q, qpair->consume_q);
if (result == VMCI_SUCCESS) {
*produce_q_header = qpair->produce_q->q_header;
*consume_q_header = qpair->consume_q->q_header;
} else if (qpair->produce_q->saved_header &&
qpair->consume_q->saved_header) {
*produce_q_header = qpair->produce_q->saved_header;
*consume_q_header = qpair->consume_q->saved_header;
result = VMCI_SUCCESS;
}
return result;
}
static int qp_wakeup_cb(void *client_data)
{
struct vmci_qp *qpair = (struct vmci_qp *)client_data;
qp_lock(qpair);
while (qpair->blocked > 0) {
qpair->blocked--;
qpair->generation++;
wake_up(&qpair->event);
}
qp_unlock(qpair);
return VMCI_SUCCESS;
}
static bool qp_wait_for_ready_queue(struct vmci_qp *qpair)
{
unsigned int generation;
qpair->blocked++;
generation = qpair->generation;
qp_unlock(qpair);
wait_event(qpair->event, generation != qpair->generation);
qp_lock(qpair);
return true;
}
static ssize_t qp_enqueue_locked(struct vmci_queue *produce_q,
struct vmci_queue *consume_q,
const u64 produce_q_size,
const void *buf,
size_t buf_size,
vmci_memcpy_to_queue_func memcpy_to_queue)
{
s64 free_space;
u64 tail;
size_t written;
ssize_t result;
result = qp_map_queue_headers(produce_q, consume_q);
if (unlikely(result != VMCI_SUCCESS))
return result;
free_space = vmci_q_header_free_space(produce_q->q_header,
consume_q->q_header,
produce_q_size);
if (free_space == 0)
return VMCI_ERROR_QUEUEPAIR_NOSPACE;
if (free_space < VMCI_SUCCESS)
return (ssize_t) free_space;
written = (size_t) (free_space > buf_size ? buf_size : free_space);
tail = vmci_q_header_producer_tail(produce_q->q_header);
if (likely(tail + written < produce_q_size)) {
result = memcpy_to_queue(produce_q, tail, buf, 0, written);
} else {
const size_t tmp = (size_t) (produce_q_size - tail);
result = memcpy_to_queue(produce_q, tail, buf, 0, tmp);
if (result >= VMCI_SUCCESS)
result = memcpy_to_queue(produce_q, 0, buf, tmp,
written - tmp);
}
if (result < VMCI_SUCCESS)
return result;
vmci_q_header_add_producer_tail(produce_q->q_header, written,
produce_q_size);
return written;
}
static ssize_t qp_dequeue_locked(struct vmci_queue *produce_q,
struct vmci_queue *consume_q,
const u64 consume_q_size,
void *buf,
size_t buf_size,
vmci_memcpy_from_queue_func memcpy_from_queue,
bool update_consumer)
{
s64 buf_ready;
u64 head;
size_t read;
ssize_t result;
result = qp_map_queue_headers(produce_q, consume_q);
if (unlikely(result != VMCI_SUCCESS))
return result;
buf_ready = vmci_q_header_buf_ready(consume_q->q_header,
produce_q->q_header,
consume_q_size);
if (buf_ready == 0)
return VMCI_ERROR_QUEUEPAIR_NODATA;
if (buf_ready < VMCI_SUCCESS)
return (ssize_t) buf_ready;
read = (size_t) (buf_ready > buf_size ? buf_size : buf_ready);
head = vmci_q_header_consumer_head(produce_q->q_header);
if (likely(head + read < consume_q_size)) {
result = memcpy_from_queue(buf, 0, consume_q, head, read);
} else {
const size_t tmp = (size_t) (consume_q_size - head);
result = memcpy_from_queue(buf, 0, consume_q, head, tmp);
if (result >= VMCI_SUCCESS)
result = memcpy_from_queue(buf, tmp, consume_q, 0,
read - tmp);
}
if (result < VMCI_SUCCESS)
return result;
if (update_consumer)
vmci_q_header_add_consumer_head(produce_q->q_header,
read, consume_q_size);
return read;
}
int vmci_qpair_alloc(struct vmci_qp **qpair,
struct vmci_handle *handle,
u64 produce_qsize,
u64 consume_qsize,
u32 peer,
u32 flags,
u32 priv_flags)
{
struct vmci_qp *my_qpair;
int retval;
struct vmci_handle src = VMCI_INVALID_HANDLE;
struct vmci_handle dst = vmci_make_handle(peer, VMCI_INVALID_ID);
enum vmci_route route;
vmci_event_release_cb wakeup_cb;
void *client_data;
if (produce_qsize + consume_qsize < max(produce_qsize, consume_qsize) ||
produce_qsize + consume_qsize > VMCI_MAX_GUEST_QP_MEMORY)
return VMCI_ERROR_NO_RESOURCES;
retval = vmci_route(&src, &dst, false, &route);
if (retval < VMCI_SUCCESS)
route = vmci_guest_code_active() ?
VMCI_ROUTE_AS_GUEST : VMCI_ROUTE_AS_HOST;
if (flags & (VMCI_QPFLAG_NONBLOCK | VMCI_QPFLAG_PINNED)) {
pr_devel("NONBLOCK OR PINNED set");
return VMCI_ERROR_INVALID_ARGS;
}
my_qpair = kzalloc(sizeof(*my_qpair), GFP_KERNEL);
if (!my_qpair)
return VMCI_ERROR_NO_MEM;
my_qpair->produce_q_size = produce_qsize;
my_qpair->consume_q_size = consume_qsize;
my_qpair->peer = peer;
my_qpair->flags = flags;
my_qpair->priv_flags = priv_flags;
wakeup_cb = NULL;
client_data = NULL;
if (VMCI_ROUTE_AS_HOST == route) {
my_qpair->guest_endpoint = false;
if (!(flags & VMCI_QPFLAG_LOCAL)) {
my_qpair->blocked = 0;
my_qpair->generation = 0;
init_waitqueue_head(&my_qpair->event);
wakeup_cb = qp_wakeup_cb;
client_data = (void *)my_qpair;
}
} else {
my_qpair->guest_endpoint = true;
}
retval = vmci_qp_alloc(handle,
&my_qpair->produce_q,
my_qpair->produce_q_size,
&my_qpair->consume_q,
my_qpair->consume_q_size,
my_qpair->peer,
my_qpair->flags,
my_qpair->priv_flags,
my_qpair->guest_endpoint,
wakeup_cb, client_data);
if (retval < VMCI_SUCCESS) {
kfree(my_qpair);
return retval;
}
*qpair = my_qpair;
my_qpair->handle = *handle;
return retval;
}
int vmci_qpair_detach(struct vmci_qp **qpair)
{
int result;
struct vmci_qp *old_qpair;
if (!qpair || !(*qpair))
return VMCI_ERROR_INVALID_ARGS;
old_qpair = *qpair;
result = qp_detatch(old_qpair->handle, old_qpair->guest_endpoint);
memset(old_qpair, 0, sizeof(*old_qpair));
old_qpair->handle = VMCI_INVALID_HANDLE;
old_qpair->peer = VMCI_INVALID_ID;
kfree(old_qpair);
*qpair = NULL;
return result;
}
int vmci_qpair_get_produce_indexes(const struct vmci_qp *qpair,
u64 *producer_tail,
u64 *consumer_head)
{
struct vmci_queue_header *produce_q_header;
struct vmci_queue_header *consume_q_header;
int result;
if (!qpair)
return VMCI_ERROR_INVALID_ARGS;
qp_lock(qpair);
result =
qp_get_queue_headers(qpair, &produce_q_header, &consume_q_header);
if (result == VMCI_SUCCESS)
vmci_q_header_get_pointers(produce_q_header, consume_q_header,
producer_tail, consumer_head);
qp_unlock(qpair);
if (result == VMCI_SUCCESS &&
((producer_tail && *producer_tail >= qpair->produce_q_size) ||
(consumer_head && *consumer_head >= qpair->produce_q_size)))
return VMCI_ERROR_INVALID_SIZE;
return result;
}
int vmci_qpair_get_consume_indexes(const struct vmci_qp *qpair,
u64 *consumer_tail,
u64 *producer_head)
{
struct vmci_queue_header *produce_q_header;
struct vmci_queue_header *consume_q_header;
int result;
if (!qpair)
return VMCI_ERROR_INVALID_ARGS;
qp_lock(qpair);
result =
qp_get_queue_headers(qpair, &produce_q_header, &consume_q_header);
if (result == VMCI_SUCCESS)
vmci_q_header_get_pointers(consume_q_header, produce_q_header,
consumer_tail, producer_head);
qp_unlock(qpair);
if (result == VMCI_SUCCESS &&
((consumer_tail && *consumer_tail >= qpair->consume_q_size) ||
(producer_head && *producer_head >= qpair->consume_q_size)))
return VMCI_ERROR_INVALID_SIZE;
return result;
}
s64 vmci_qpair_produce_free_space(const struct vmci_qp *qpair)
{
struct vmci_queue_header *produce_q_header;
struct vmci_queue_header *consume_q_header;
s64 result;
if (!qpair)
return VMCI_ERROR_INVALID_ARGS;
qp_lock(qpair);
result =
qp_get_queue_headers(qpair, &produce_q_header, &consume_q_header);
if (result == VMCI_SUCCESS)
result = vmci_q_header_free_space(produce_q_header,
consume_q_header,
qpair->produce_q_size);
else
result = 0;
qp_unlock(qpair);
return result;
}
s64 vmci_qpair_consume_free_space(const struct vmci_qp *qpair)
{
struct vmci_queue_header *produce_q_header;
struct vmci_queue_header *consume_q_header;
s64 result;
if (!qpair)
return VMCI_ERROR_INVALID_ARGS;
qp_lock(qpair);
result =
qp_get_queue_headers(qpair, &produce_q_header, &consume_q_header);
if (result == VMCI_SUCCESS)
result = vmci_q_header_free_space(consume_q_header,
produce_q_header,
qpair->consume_q_size);
else
result = 0;
qp_unlock(qpair);
return result;
}
s64 vmci_qpair_produce_buf_ready(const struct vmci_qp *qpair)
{
struct vmci_queue_header *produce_q_header;
struct vmci_queue_header *consume_q_header;
s64 result;
if (!qpair)
return VMCI_ERROR_INVALID_ARGS;
qp_lock(qpair);
result =
qp_get_queue_headers(qpair, &produce_q_header, &consume_q_header);
if (result == VMCI_SUCCESS)
result = vmci_q_header_buf_ready(produce_q_header,
consume_q_header,
qpair->produce_q_size);
else
result = 0;
qp_unlock(qpair);
return result;
}
s64 vmci_qpair_consume_buf_ready(const struct vmci_qp *qpair)
{
struct vmci_queue_header *produce_q_header;
struct vmci_queue_header *consume_q_header;
s64 result;
if (!qpair)
return VMCI_ERROR_INVALID_ARGS;
qp_lock(qpair);
result =
qp_get_queue_headers(qpair, &produce_q_header, &consume_q_header);
if (result == VMCI_SUCCESS)
result = vmci_q_header_buf_ready(consume_q_header,
produce_q_header,
qpair->consume_q_size);
else
result = 0;
qp_unlock(qpair);
return result;
}
ssize_t vmci_qpair_enqueue(struct vmci_qp *qpair,
const void *buf,
size_t buf_size,
int buf_type)
{
ssize_t result;
if (!qpair || !buf)
return VMCI_ERROR_INVALID_ARGS;
qp_lock(qpair);
do {
result = qp_enqueue_locked(qpair->produce_q,
qpair->consume_q,
qpair->produce_q_size,
buf, buf_size,
qp_memcpy_to_queue);
if (result == VMCI_ERROR_QUEUEPAIR_NOT_READY &&
!qp_wait_for_ready_queue(qpair))
result = VMCI_ERROR_WOULD_BLOCK;
} while (result == VMCI_ERROR_QUEUEPAIR_NOT_READY);
qp_unlock(qpair);
return result;
}
ssize_t vmci_qpair_dequeue(struct vmci_qp *qpair,
void *buf,
size_t buf_size,
int buf_type)
{
ssize_t result;
if (!qpair || !buf)
return VMCI_ERROR_INVALID_ARGS;
qp_lock(qpair);
do {
result = qp_dequeue_locked(qpair->produce_q,
qpair->consume_q,
qpair->consume_q_size,
buf, buf_size,
qp_memcpy_from_queue, true);
if (result == VMCI_ERROR_QUEUEPAIR_NOT_READY &&
!qp_wait_for_ready_queue(qpair))
result = VMCI_ERROR_WOULD_BLOCK;
} while (result == VMCI_ERROR_QUEUEPAIR_NOT_READY);
qp_unlock(qpair);
return result;
}
ssize_t vmci_qpair_peek(struct vmci_qp *qpair,
void *buf,
size_t buf_size,
int buf_type)
{
ssize_t result;
if (!qpair || !buf)
return VMCI_ERROR_INVALID_ARGS;
qp_lock(qpair);
do {
result = qp_dequeue_locked(qpair->produce_q,
qpair->consume_q,
qpair->consume_q_size,
buf, buf_size,
qp_memcpy_from_queue, false);
if (result == VMCI_ERROR_QUEUEPAIR_NOT_READY &&
!qp_wait_for_ready_queue(qpair))
result = VMCI_ERROR_WOULD_BLOCK;
} while (result == VMCI_ERROR_QUEUEPAIR_NOT_READY);
qp_unlock(qpair);
return result;
}
ssize_t vmci_qpair_enquev(struct vmci_qp *qpair,
void *iov,
size_t iov_size,
int buf_type)
{
ssize_t result;
if (!qpair || !iov)
return VMCI_ERROR_INVALID_ARGS;
qp_lock(qpair);
do {
result = qp_enqueue_locked(qpair->produce_q,
qpair->consume_q,
qpair->produce_q_size,
iov, iov_size,
qp_memcpy_to_queue_iov);
if (result == VMCI_ERROR_QUEUEPAIR_NOT_READY &&
!qp_wait_for_ready_queue(qpair))
result = VMCI_ERROR_WOULD_BLOCK;
} while (result == VMCI_ERROR_QUEUEPAIR_NOT_READY);
qp_unlock(qpair);
return result;
}
ssize_t vmci_qpair_dequev(struct vmci_qp *qpair,
struct msghdr *msg,
size_t iov_size,
int buf_type)
{
ssize_t result;
if (!qpair)
return VMCI_ERROR_INVALID_ARGS;
qp_lock(qpair);
do {
result = qp_dequeue_locked(qpair->produce_q,
qpair->consume_q,
qpair->consume_q_size,
msg, iov_size,
qp_memcpy_from_queue_iov,
true);
if (result == VMCI_ERROR_QUEUEPAIR_NOT_READY &&
!qp_wait_for_ready_queue(qpair))
result = VMCI_ERROR_WOULD_BLOCK;
} while (result == VMCI_ERROR_QUEUEPAIR_NOT_READY);
qp_unlock(qpair);
return result;
}
ssize_t vmci_qpair_peekv(struct vmci_qp *qpair,
struct msghdr *msg,
size_t iov_size,
int buf_type)
{
ssize_t result;
if (!qpair)
return VMCI_ERROR_INVALID_ARGS;
qp_lock(qpair);
do {
result = qp_dequeue_locked(qpair->produce_q,
qpair->consume_q,
qpair->consume_q_size,
msg, iov_size,
qp_memcpy_from_queue_iov,
false);
if (result == VMCI_ERROR_QUEUEPAIR_NOT_READY &&
!qp_wait_for_ready_queue(qpair))
result = VMCI_ERROR_WOULD_BLOCK;
} while (result == VMCI_ERROR_QUEUEPAIR_NOT_READY);
qp_unlock(qpair);
return result;
}
