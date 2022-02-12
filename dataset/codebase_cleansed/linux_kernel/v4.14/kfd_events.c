static uint64_t *page_slots(struct signal_page *page)
{
return page->kernel_address;
}
static bool allocate_free_slot(struct kfd_process *process,
struct signal_page **out_page,
unsigned int *out_slot_index)
{
struct signal_page *page;
list_for_each_entry(page, &process->signal_event_pages, event_pages) {
if (page->free_slots > 0) {
unsigned int slot =
find_first_zero_bit(page->used_slot_bitmap,
SLOTS_PER_PAGE);
__set_bit(slot, page->used_slot_bitmap);
page->free_slots--;
page_slots(page)[slot] = UNSIGNALED_EVENT_SLOT;
*out_page = page;
*out_slot_index = slot;
pr_debug("Allocated event signal slot in page %p, slot %d\n",
page, slot);
return true;
}
}
pr_debug("No free event signal slots were found for process %p\n",
process);
return false;
}
static bool allocate_signal_page(struct file *devkfd, struct kfd_process *p)
{
void *backing_store;
struct signal_page *page;
page = kzalloc(SIGNAL_PAGE_SIZE, GFP_KERNEL);
if (!page)
goto fail_alloc_signal_page;
page->free_slots = SLOTS_PER_PAGE;
backing_store = (void *) __get_free_pages(GFP_KERNEL | __GFP_ZERO,
get_order(KFD_SIGNAL_EVENT_LIMIT * 8));
if (!backing_store)
goto fail_alloc_signal_store;
memset(backing_store, (uint8_t) UNSIGNALED_EVENT_SLOT,
KFD_SIGNAL_EVENT_LIMIT * 8);
page->kernel_address = backing_store;
if (list_empty(&p->signal_event_pages))
page->page_index = 0;
else
page->page_index = list_tail_entry(&p->signal_event_pages,
struct signal_page,
event_pages)->page_index + 1;
pr_debug("Allocated new event signal page at %p, for process %p\n",
page, p);
pr_debug("Page index is %d\n", page->page_index);
list_add(&page->event_pages, &p->signal_event_pages);
return true;
fail_alloc_signal_store:
kfree(page);
fail_alloc_signal_page:
return false;
}
static bool allocate_event_notification_slot(struct file *devkfd,
struct kfd_process *p,
struct signal_page **page,
unsigned int *signal_slot_index)
{
bool ret;
ret = allocate_free_slot(p, page, signal_slot_index);
if (!ret) {
ret = allocate_signal_page(devkfd, p);
if (ret)
ret = allocate_free_slot(p, page, signal_slot_index);
}
return ret;
}
static void release_event_notification_slot(struct signal_page *page,
size_t slot_index)
{
__clear_bit(slot_index, page->used_slot_bitmap);
page->free_slots++;
}
static struct signal_page *lookup_signal_page_by_index(struct kfd_process *p,
unsigned int page_index)
{
struct signal_page *page;
list_for_each_entry(page, &p->signal_event_pages, event_pages)
if (page->page_index == page_index)
return page;
return NULL;
}
static struct kfd_event *lookup_event_by_id(struct kfd_process *p, uint32_t id)
{
struct kfd_event *ev;
hash_for_each_possible(p->events, ev, events, id)
if (ev->event_id == id)
return ev;
return NULL;
}
static u32 make_signal_event_id(struct signal_page *page,
unsigned int signal_slot_index)
{
return page->page_index |
(signal_slot_index << SIGNAL_EVENT_ID_SLOT_SHIFT);
}
static u32 make_nonsignal_event_id(struct kfd_process *p)
{
u32 id;
for (id = p->next_nonsignal_event_id;
id < KFD_LAST_NONSIGNAL_EVENT_ID &&
lookup_event_by_id(p, id);
id++)
;
if (id < KFD_LAST_NONSIGNAL_EVENT_ID) {
p->next_nonsignal_event_id = id + 1;
return id;
}
for (id = KFD_FIRST_NONSIGNAL_EVENT_ID;
id < KFD_LAST_NONSIGNAL_EVENT_ID &&
lookup_event_by_id(p, id);
id++)
;
if (id < KFD_LAST_NONSIGNAL_EVENT_ID) {
p->next_nonsignal_event_id = id + 1;
return id;
}
p->next_nonsignal_event_id = KFD_FIRST_NONSIGNAL_EVENT_ID;
return 0;
}
static struct kfd_event *lookup_event_by_page_slot(struct kfd_process *p,
struct signal_page *page,
unsigned int signal_slot)
{
return lookup_event_by_id(p, make_signal_event_id(page, signal_slot));
}
static int create_signal_event(struct file *devkfd,
struct kfd_process *p,
struct kfd_event *ev)
{
if (p->signal_event_count == KFD_SIGNAL_EVENT_LIMIT) {
if (!p->signal_event_limit_reached) {
pr_warn("Signal event wasn't created because limit was reached\n");
p->signal_event_limit_reached = true;
}
return -ENOMEM;
}
if (!allocate_event_notification_slot(devkfd, p, &ev->signal_page,
&ev->signal_slot_index)) {
pr_warn("Signal event wasn't created because out of kernel memory\n");
return -ENOMEM;
}
p->signal_event_count++;
ev->user_signal_address =
&ev->signal_page->user_address[ev->signal_slot_index];
ev->event_id = make_signal_event_id(ev->signal_page,
ev->signal_slot_index);
pr_debug("Signal event number %zu created with id %d, address %p\n",
p->signal_event_count, ev->event_id,
ev->user_signal_address);
return 0;
}
static int create_other_event(struct kfd_process *p, struct kfd_event *ev)
{
ev->event_id = make_nonsignal_event_id(p);
if (ev->event_id == 0)
return -ENOMEM;
return 0;
}
void kfd_event_init_process(struct kfd_process *p)
{
mutex_init(&p->event_mutex);
hash_init(p->events);
INIT_LIST_HEAD(&p->signal_event_pages);
p->next_nonsignal_event_id = KFD_FIRST_NONSIGNAL_EVENT_ID;
p->signal_event_count = 0;
}
static void destroy_event(struct kfd_process *p, struct kfd_event *ev)
{
if (ev->signal_page) {
release_event_notification_slot(ev->signal_page,
ev->signal_slot_index);
p->signal_event_count--;
}
list_del(&ev->waiters);
hash_del(&ev->events);
kfree(ev);
}
static void destroy_events(struct kfd_process *p)
{
struct kfd_event *ev;
struct hlist_node *tmp;
unsigned int hash_bkt;
hash_for_each_safe(p->events, hash_bkt, tmp, ev, events)
destroy_event(p, ev);
}
static void shutdown_signal_pages(struct kfd_process *p)
{
struct signal_page *page, *tmp;
list_for_each_entry_safe(page, tmp, &p->signal_event_pages,
event_pages) {
free_pages((unsigned long)page->kernel_address,
get_order(KFD_SIGNAL_EVENT_LIMIT * 8));
kfree(page);
}
}
void kfd_event_free_process(struct kfd_process *p)
{
destroy_events(p);
shutdown_signal_pages(p);
}
static bool event_can_be_gpu_signaled(const struct kfd_event *ev)
{
return ev->type == KFD_EVENT_TYPE_SIGNAL ||
ev->type == KFD_EVENT_TYPE_DEBUG;
}
static bool event_can_be_cpu_signaled(const struct kfd_event *ev)
{
return ev->type == KFD_EVENT_TYPE_SIGNAL;
}
int kfd_event_create(struct file *devkfd, struct kfd_process *p,
uint32_t event_type, bool auto_reset, uint32_t node_id,
uint32_t *event_id, uint32_t *event_trigger_data,
uint64_t *event_page_offset, uint32_t *event_slot_index)
{
int ret = 0;
struct kfd_event *ev = kzalloc(sizeof(*ev), GFP_KERNEL);
if (!ev)
return -ENOMEM;
ev->type = event_type;
ev->auto_reset = auto_reset;
ev->signaled = false;
INIT_LIST_HEAD(&ev->waiters);
*event_page_offset = 0;
mutex_lock(&p->event_mutex);
switch (event_type) {
case KFD_EVENT_TYPE_SIGNAL:
case KFD_EVENT_TYPE_DEBUG:
ret = create_signal_event(devkfd, p, ev);
if (!ret) {
*event_page_offset = (ev->signal_page->page_index |
KFD_MMAP_EVENTS_MASK);
*event_page_offset <<= PAGE_SHIFT;
*event_slot_index = ev->signal_slot_index;
}
break;
default:
ret = create_other_event(p, ev);
break;
}
if (!ret) {
hash_add(p->events, &ev->events, ev->event_id);
*event_id = ev->event_id;
*event_trigger_data = ev->event_id;
} else {
kfree(ev);
}
mutex_unlock(&p->event_mutex);
return ret;
}
int kfd_event_destroy(struct kfd_process *p, uint32_t event_id)
{
struct kfd_event *ev;
int ret = 0;
mutex_lock(&p->event_mutex);
ev = lookup_event_by_id(p, event_id);
if (ev)
destroy_event(p, ev);
else
ret = -EINVAL;
mutex_unlock(&p->event_mutex);
return ret;
}
static void set_event(struct kfd_event *ev)
{
struct kfd_event_waiter *waiter;
struct kfd_event_waiter *next;
ev->signaled = !ev->auto_reset || list_empty(&ev->waiters);
list_for_each_entry_safe(waiter, next, &ev->waiters, waiters) {
waiter->activated = true;
list_del_init(&waiter->waiters);
wake_up_process(waiter->sleeping_task);
}
}
int kfd_set_event(struct kfd_process *p, uint32_t event_id)
{
int ret = 0;
struct kfd_event *ev;
mutex_lock(&p->event_mutex);
ev = lookup_event_by_id(p, event_id);
if (ev && event_can_be_cpu_signaled(ev))
set_event(ev);
else
ret = -EINVAL;
mutex_unlock(&p->event_mutex);
return ret;
}
static void reset_event(struct kfd_event *ev)
{
ev->signaled = false;
}
int kfd_reset_event(struct kfd_process *p, uint32_t event_id)
{
int ret = 0;
struct kfd_event *ev;
mutex_lock(&p->event_mutex);
ev = lookup_event_by_id(p, event_id);
if (ev && event_can_be_cpu_signaled(ev))
reset_event(ev);
else
ret = -EINVAL;
mutex_unlock(&p->event_mutex);
return ret;
}
static void acknowledge_signal(struct kfd_process *p, struct kfd_event *ev)
{
page_slots(ev->signal_page)[ev->signal_slot_index] =
UNSIGNALED_EVENT_SLOT;
}
static bool is_slot_signaled(struct signal_page *page, unsigned int index)
{
return page_slots(page)[index] != UNSIGNALED_EVENT_SLOT;
}
static void set_event_from_interrupt(struct kfd_process *p,
struct kfd_event *ev)
{
if (ev && event_can_be_gpu_signaled(ev)) {
acknowledge_signal(p, ev);
set_event(ev);
}
}
void kfd_signal_event_interrupt(unsigned int pasid, uint32_t partial_id,
uint32_t valid_id_bits)
{
struct kfd_event *ev;
struct kfd_process *p = kfd_lookup_process_by_pasid(pasid);
if (!p)
return;
mutex_lock(&p->event_mutex);
if (valid_id_bits >= INTERRUPT_DATA_BITS) {
ev = lookup_event_by_id(p, partial_id);
set_event_from_interrupt(p, ev);
} else {
struct signal_page *page;
unsigned int i;
list_for_each_entry(page, &p->signal_event_pages, event_pages)
for (i = 0; i < SLOTS_PER_PAGE; i++)
if (is_slot_signaled(page, i)) {
ev = lookup_event_by_page_slot(p,
page, i);
set_event_from_interrupt(p, ev);
}
}
mutex_unlock(&p->event_mutex);
mutex_unlock(&p->mutex);
}
static struct kfd_event_waiter *alloc_event_waiters(uint32_t num_events)
{
struct kfd_event_waiter *event_waiters;
uint32_t i;
event_waiters = kmalloc_array(num_events,
sizeof(struct kfd_event_waiter),
GFP_KERNEL);
for (i = 0; (event_waiters) && (i < num_events) ; i++) {
INIT_LIST_HEAD(&event_waiters[i].waiters);
event_waiters[i].sleeping_task = current;
event_waiters[i].activated = false;
}
return event_waiters;
}
static int init_event_waiter(struct kfd_process *p,
struct kfd_event_waiter *waiter,
uint32_t event_id,
uint32_t input_index)
{
struct kfd_event *ev = lookup_event_by_id(p, event_id);
if (!ev)
return -EINVAL;
waiter->event = ev;
waiter->input_index = input_index;
waiter->activated = ev->signaled;
ev->signaled = ev->signaled && !ev->auto_reset;
list_add(&waiter->waiters, &ev->waiters);
return 0;
}
static bool test_event_condition(bool all, uint32_t num_events,
struct kfd_event_waiter *event_waiters)
{
uint32_t i;
uint32_t activated_count = 0;
for (i = 0; i < num_events; i++) {
if (event_waiters[i].activated) {
if (!all)
return true;
activated_count++;
}
}
return activated_count == num_events;
}
static bool copy_signaled_event_data(uint32_t num_events,
struct kfd_event_waiter *event_waiters,
struct kfd_event_data __user *data)
{
struct kfd_hsa_memory_exception_data *src;
struct kfd_hsa_memory_exception_data __user *dst;
struct kfd_event_waiter *waiter;
struct kfd_event *event;
uint32_t i;
for (i = 0; i < num_events; i++) {
waiter = &event_waiters[i];
event = waiter->event;
if (waiter->activated && event->type == KFD_EVENT_TYPE_MEMORY) {
dst = &data[waiter->input_index].memory_exception_data;
src = &event->memory_exception_data;
if (copy_to_user(dst, src,
sizeof(struct kfd_hsa_memory_exception_data)))
return false;
}
}
return true;
}
static long user_timeout_to_jiffies(uint32_t user_timeout_ms)
{
if (user_timeout_ms == KFD_EVENT_TIMEOUT_IMMEDIATE)
return 0;
if (user_timeout_ms == KFD_EVENT_TIMEOUT_INFINITE)
return MAX_SCHEDULE_TIMEOUT;
user_timeout_ms = min_t(uint32_t, user_timeout_ms, 0x7FFFFFFF);
return msecs_to_jiffies(user_timeout_ms) + 1;
}
static void free_waiters(uint32_t num_events, struct kfd_event_waiter *waiters)
{
uint32_t i;
for (i = 0; i < num_events; i++)
list_del(&waiters[i].waiters);
kfree(waiters);
}
int kfd_wait_on_events(struct kfd_process *p,
uint32_t num_events, void __user *data,
bool all, uint32_t user_timeout_ms,
enum kfd_event_wait_result *wait_result)
{
struct kfd_event_data __user *events =
(struct kfd_event_data __user *) data;
uint32_t i;
int ret = 0;
struct kfd_event_waiter *event_waiters = NULL;
long timeout = user_timeout_to_jiffies(user_timeout_ms);
mutex_lock(&p->event_mutex);
event_waiters = alloc_event_waiters(num_events);
if (!event_waiters) {
ret = -ENOMEM;
goto fail;
}
for (i = 0; i < num_events; i++) {
struct kfd_event_data event_data;
if (copy_from_user(&event_data, &events[i],
sizeof(struct kfd_event_data))) {
ret = -EFAULT;
goto fail;
}
ret = init_event_waiter(p, &event_waiters[i],
event_data.event_id, i);
if (ret)
goto fail;
}
mutex_unlock(&p->event_mutex);
while (true) {
if (fatal_signal_pending(current)) {
ret = -EINTR;
break;
}
if (signal_pending(current)) {
ret = -ERESTARTSYS;
break;
}
if (test_event_condition(all, num_events, event_waiters)) {
if (copy_signaled_event_data(num_events,
event_waiters, events))
*wait_result = KFD_WAIT_COMPLETE;
else
*wait_result = KFD_WAIT_ERROR;
break;
}
if (timeout <= 0) {
*wait_result = KFD_WAIT_TIMEOUT;
break;
}
timeout = schedule_timeout_interruptible(timeout);
}
__set_current_state(TASK_RUNNING);
mutex_lock(&p->event_mutex);
free_waiters(num_events, event_waiters);
mutex_unlock(&p->event_mutex);
return ret;
fail:
if (event_waiters)
free_waiters(num_events, event_waiters);
mutex_unlock(&p->event_mutex);
*wait_result = KFD_WAIT_ERROR;
return ret;
}
int kfd_event_mmap(struct kfd_process *p, struct vm_area_struct *vma)
{
unsigned int page_index;
unsigned long pfn;
struct signal_page *page;
if (get_order(KFD_SIGNAL_EVENT_LIMIT * 8) !=
get_order(vma->vm_end - vma->vm_start)) {
pr_err("Event page mmap requested illegal size\n");
return -EINVAL;
}
page_index = vma->vm_pgoff;
page = lookup_signal_page_by_index(p, page_index);
if (!page) {
pr_debug("Signal page could not be found for page_index %u\n",
page_index);
return -EINVAL;
}
pfn = __pa(page->kernel_address);
pfn >>= PAGE_SHIFT;
vma->vm_flags |= VM_IO | VM_DONTCOPY | VM_DONTEXPAND | VM_NORESERVE
| VM_DONTDUMP | VM_PFNMAP;
pr_debug("Mapping signal page\n");
pr_debug(" start user address == 0x%08lx\n", vma->vm_start);
pr_debug(" end user address == 0x%08lx\n", vma->vm_end);
pr_debug(" pfn == 0x%016lX\n", pfn);
pr_debug(" vm_flags == 0x%08lX\n", vma->vm_flags);
pr_debug(" size == 0x%08lX\n",
vma->vm_end - vma->vm_start);
page->user_address = (uint64_t __user *)vma->vm_start;
return remap_pfn_range(vma, vma->vm_start, pfn,
vma->vm_end - vma->vm_start, vma->vm_page_prot);
}
static void lookup_events_by_type_and_signal(struct kfd_process *p,
int type, void *event_data)
{
struct kfd_hsa_memory_exception_data *ev_data;
struct kfd_event *ev;
int bkt;
bool send_signal = true;
ev_data = (struct kfd_hsa_memory_exception_data *) event_data;
hash_for_each(p->events, bkt, ev, events)
if (ev->type == type) {
send_signal = false;
dev_dbg(kfd_device,
"Event found: id %X type %d",
ev->event_id, ev->type);
set_event(ev);
if (ev->type == KFD_EVENT_TYPE_MEMORY && ev_data)
ev->memory_exception_data = *ev_data;
}
if (send_signal) {
if (send_sigterm) {
dev_warn(kfd_device,
"Sending SIGTERM to HSA Process with PID %d ",
p->lead_thread->pid);
send_sig(SIGTERM, p->lead_thread, 0);
} else {
dev_err(kfd_device,
"HSA Process (PID %d) got unhandled exception",
p->lead_thread->pid);
}
}
}
void kfd_signal_iommu_event(struct kfd_dev *dev, unsigned int pasid,
unsigned long address, bool is_write_requested,
bool is_execute_requested)
{
struct kfd_hsa_memory_exception_data memory_exception_data;
struct vm_area_struct *vma;
struct kfd_process *p = kfd_lookup_process_by_pasid(pasid);
if (!p)
return;
memset(&memory_exception_data, 0, sizeof(memory_exception_data));
down_read(&p->mm->mmap_sem);
vma = find_vma(p->mm, address);
memory_exception_data.gpu_id = dev->id;
memory_exception_data.va = address;
memory_exception_data.failure.NotPresent = 1;
memory_exception_data.failure.NoExecute = 0;
memory_exception_data.failure.ReadOnly = 0;
if (vma) {
if (vma->vm_start > address) {
memory_exception_data.failure.NotPresent = 1;
memory_exception_data.failure.NoExecute = 0;
memory_exception_data.failure.ReadOnly = 0;
} else {
memory_exception_data.failure.NotPresent = 0;
if (is_write_requested && !(vma->vm_flags & VM_WRITE))
memory_exception_data.failure.ReadOnly = 1;
else
memory_exception_data.failure.ReadOnly = 0;
if (is_execute_requested && !(vma->vm_flags & VM_EXEC))
memory_exception_data.failure.NoExecute = 1;
else
memory_exception_data.failure.NoExecute = 0;
}
}
up_read(&p->mm->mmap_sem);
mutex_lock(&p->event_mutex);
lookup_events_by_type_and_signal(p, KFD_EVENT_TYPE_MEMORY,
&memory_exception_data);
mutex_unlock(&p->event_mutex);
mutex_unlock(&p->mutex);
}
void kfd_signal_hw_exception_event(unsigned int pasid)
{
struct kfd_process *p = kfd_lookup_process_by_pasid(pasid);
if (!p)
return;
mutex_lock(&p->event_mutex);
lookup_events_by_type_and_signal(p, KFD_EVENT_TYPE_HW_EXCEPTION, NULL);
mutex_unlock(&p->event_mutex);
mutex_unlock(&p->mutex);
}
