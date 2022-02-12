static void install(struct slot_map *m, int count, unsigned long *map)
{
spin_lock(&m->q.lock);
m->c = m->count = count;
m->map = map;
wake_up_all_locked(&m->q);
spin_unlock(&m->q.lock);
}
static void mark_killed(struct slot_map *m)
{
spin_lock(&m->q.lock);
m->c -= m->count + 1;
spin_unlock(&m->q.lock);
}
static void run_down(struct slot_map *m)
{
DEFINE_WAIT(wait);
spin_lock(&m->q.lock);
if (m->c != -1) {
for (;;) {
if (likely(list_empty(&wait.entry)))
__add_wait_queue_entry_tail(&m->q, &wait);
set_current_state(TASK_UNINTERRUPTIBLE);
if (m->c == -1)
break;
spin_unlock(&m->q.lock);
schedule();
spin_lock(&m->q.lock);
}
__remove_wait_queue(&m->q, &wait);
__set_current_state(TASK_RUNNING);
}
m->map = NULL;
spin_unlock(&m->q.lock);
}
static void put(struct slot_map *m, int slot)
{
int v;
spin_lock(&m->q.lock);
__clear_bit(slot, m->map);
v = ++m->c;
if (unlikely(v == 1))
wake_up_locked(&m->q);
else if (unlikely(v == -1))
wake_up_all_locked(&m->q);
spin_unlock(&m->q.lock);
}
static int wait_for_free(struct slot_map *m)
{
long left = slot_timeout_secs * HZ;
DEFINE_WAIT(wait);
do {
long n = left, t;
if (likely(list_empty(&wait.entry)))
__add_wait_queue_entry_tail_exclusive(&m->q, &wait);
set_current_state(TASK_INTERRUPTIBLE);
if (m->c > 0)
break;
if (m->c < 0) {
if (n > ORANGEFS_BUFMAP_WAIT_TIMEOUT_SECS * HZ)
n = ORANGEFS_BUFMAP_WAIT_TIMEOUT_SECS * HZ;
}
spin_unlock(&m->q.lock);
t = schedule_timeout(n);
spin_lock(&m->q.lock);
if (unlikely(!t) && n != left && m->c < 0)
left = t;
else
left = t + (left - n);
if (unlikely(signal_pending(current)))
left = -EINTR;
} while (left > 0);
if (!list_empty(&wait.entry))
list_del(&wait.entry);
else if (left <= 0 && waitqueue_active(&m->q))
__wake_up_locked_key(&m->q, TASK_INTERRUPTIBLE, NULL);
__set_current_state(TASK_RUNNING);
if (likely(left > 0))
return 0;
return left < 0 ? -EINTR : -ETIMEDOUT;
}
static int get(struct slot_map *m)
{
int res = 0;
spin_lock(&m->q.lock);
if (unlikely(m->c <= 0))
res = wait_for_free(m);
if (likely(!res)) {
m->c--;
res = find_first_zero_bit(m->map, m->count);
__set_bit(res, m->map);
}
spin_unlock(&m->q.lock);
return res;
}
static void
orangefs_bufmap_unmap(struct orangefs_bufmap *bufmap)
{
int i;
for (i = 0; i < bufmap->page_count; i++)
put_page(bufmap->page_array[i]);
}
static void
orangefs_bufmap_free(struct orangefs_bufmap *bufmap)
{
kfree(bufmap->page_array);
kfree(bufmap->desc_array);
kfree(bufmap->buffer_index_array);
kfree(bufmap);
}
int orangefs_bufmap_size_query(void)
{
struct orangefs_bufmap *bufmap;
int size = 0;
spin_lock(&orangefs_bufmap_lock);
bufmap = __orangefs_bufmap;
if (bufmap)
size = bufmap->desc_size;
spin_unlock(&orangefs_bufmap_lock);
return size;
}
int orangefs_bufmap_shift_query(void)
{
struct orangefs_bufmap *bufmap;
int shift = 0;
spin_lock(&orangefs_bufmap_lock);
bufmap = __orangefs_bufmap;
if (bufmap)
shift = bufmap->desc_shift;
spin_unlock(&orangefs_bufmap_lock);
return shift;
}
int orangefs_get_bufmap_init(void)
{
return __orangefs_bufmap ? 1 : 0;
}
static struct orangefs_bufmap *
orangefs_bufmap_alloc(struct ORANGEFS_dev_map_desc *user_desc)
{
struct orangefs_bufmap *bufmap;
bufmap = kzalloc(sizeof(*bufmap), GFP_KERNEL);
if (!bufmap)
goto out;
bufmap->total_size = user_desc->total_size;
bufmap->desc_count = user_desc->count;
bufmap->desc_size = user_desc->size;
bufmap->desc_shift = ilog2(bufmap->desc_size);
bufmap->buffer_index_array =
kzalloc(DIV_ROUND_UP(bufmap->desc_count, BITS_PER_LONG), GFP_KERNEL);
if (!bufmap->buffer_index_array) {
gossip_err("orangefs: could not allocate %d buffer indices\n",
bufmap->desc_count);
goto out_free_bufmap;
}
bufmap->desc_array =
kcalloc(bufmap->desc_count, sizeof(struct orangefs_bufmap_desc),
GFP_KERNEL);
if (!bufmap->desc_array) {
gossip_err("orangefs: could not allocate %d descriptors\n",
bufmap->desc_count);
goto out_free_index_array;
}
bufmap->page_count = bufmap->total_size / PAGE_SIZE;
bufmap->page_array =
kcalloc(bufmap->page_count, sizeof(struct page *), GFP_KERNEL);
if (!bufmap->page_array)
goto out_free_desc_array;
return bufmap;
out_free_desc_array:
kfree(bufmap->desc_array);
out_free_index_array:
kfree(bufmap->buffer_index_array);
out_free_bufmap:
kfree(bufmap);
out:
return NULL;
}
static int
orangefs_bufmap_map(struct orangefs_bufmap *bufmap,
struct ORANGEFS_dev_map_desc *user_desc)
{
int pages_per_desc = bufmap->desc_size / PAGE_SIZE;
int offset = 0, ret, i;
ret = get_user_pages_fast((unsigned long)user_desc->ptr,
bufmap->page_count, 1, bufmap->page_array);
if (ret < 0)
return ret;
if (ret != bufmap->page_count) {
gossip_err("orangefs error: asked for %d pages, only got %d.\n",
bufmap->page_count, ret);
for (i = 0; i < ret; i++) {
SetPageError(bufmap->page_array[i]);
put_page(bufmap->page_array[i]);
}
return -ENOMEM;
}
for (i = 0; i < bufmap->page_count; i++)
flush_dcache_page(bufmap->page_array[i]);
for (offset = 0, i = 0; i < bufmap->desc_count; i++) {
bufmap->desc_array[i].page_array = &bufmap->page_array[offset];
bufmap->desc_array[i].array_count = pages_per_desc;
bufmap->desc_array[i].uaddr =
(user_desc->ptr + (i * pages_per_desc * PAGE_SIZE));
offset += pages_per_desc;
}
return 0;
}
int orangefs_bufmap_initialize(struct ORANGEFS_dev_map_desc *user_desc)
{
struct orangefs_bufmap *bufmap;
int ret = -EINVAL;
gossip_debug(GOSSIP_BUFMAP_DEBUG,
"orangefs_bufmap_initialize: called (ptr ("
"%p) sz (%d) cnt(%d).\n",
user_desc->ptr,
user_desc->size,
user_desc->count);
if (user_desc->total_size < 0 ||
user_desc->size < 0 ||
user_desc->count < 0)
goto out;
if (PAGE_ALIGN((unsigned long)user_desc->ptr) !=
(unsigned long)user_desc->ptr) {
gossip_err("orangefs error: memory alignment (front). %p\n",
user_desc->ptr);
goto out;
}
if (PAGE_ALIGN(((unsigned long)user_desc->ptr + user_desc->total_size))
!= (unsigned long)(user_desc->ptr + user_desc->total_size)) {
gossip_err("orangefs error: memory alignment (back).(%p + %d)\n",
user_desc->ptr,
user_desc->total_size);
goto out;
}
if (user_desc->total_size != (user_desc->size * user_desc->count)) {
gossip_err("orangefs error: user provided an oddly sized buffer: (%d, %d, %d)\n",
user_desc->total_size,
user_desc->size,
user_desc->count);
goto out;
}
if ((user_desc->size % PAGE_SIZE) != 0) {
gossip_err("orangefs error: bufmap size not page size divisible (%d).\n",
user_desc->size);
goto out;
}
ret = -ENOMEM;
bufmap = orangefs_bufmap_alloc(user_desc);
if (!bufmap)
goto out;
ret = orangefs_bufmap_map(bufmap, user_desc);
if (ret)
goto out_free_bufmap;
spin_lock(&orangefs_bufmap_lock);
if (__orangefs_bufmap) {
spin_unlock(&orangefs_bufmap_lock);
gossip_err("orangefs: error: bufmap already initialized.\n");
ret = -EINVAL;
goto out_unmap_bufmap;
}
__orangefs_bufmap = bufmap;
install(&rw_map,
bufmap->desc_count,
bufmap->buffer_index_array);
install(&readdir_map,
ORANGEFS_READDIR_DEFAULT_DESC_COUNT,
bufmap->readdir_index_array);
spin_unlock(&orangefs_bufmap_lock);
gossip_debug(GOSSIP_BUFMAP_DEBUG,
"orangefs_bufmap_initialize: exiting normally\n");
return 0;
out_unmap_bufmap:
orangefs_bufmap_unmap(bufmap);
out_free_bufmap:
orangefs_bufmap_free(bufmap);
out:
return ret;
}
void orangefs_bufmap_finalize(void)
{
struct orangefs_bufmap *bufmap = __orangefs_bufmap;
if (!bufmap)
return;
gossip_debug(GOSSIP_BUFMAP_DEBUG, "orangefs_bufmap_finalize: called\n");
mark_killed(&rw_map);
mark_killed(&readdir_map);
gossip_debug(GOSSIP_BUFMAP_DEBUG,
"orangefs_bufmap_finalize: exiting normally\n");
}
void orangefs_bufmap_run_down(void)
{
struct orangefs_bufmap *bufmap = __orangefs_bufmap;
if (!bufmap)
return;
run_down(&rw_map);
run_down(&readdir_map);
spin_lock(&orangefs_bufmap_lock);
__orangefs_bufmap = NULL;
spin_unlock(&orangefs_bufmap_lock);
orangefs_bufmap_unmap(bufmap);
orangefs_bufmap_free(bufmap);
}
int orangefs_bufmap_get(void)
{
return get(&rw_map);
}
void orangefs_bufmap_put(int buffer_index)
{
put(&rw_map, buffer_index);
}
int orangefs_readdir_index_get(void)
{
return get(&readdir_map);
}
void orangefs_readdir_index_put(int buffer_index)
{
put(&readdir_map, buffer_index);
}
int orangefs_bufmap_copy_from_iovec(struct iov_iter *iter,
int buffer_index,
size_t size)
{
struct orangefs_bufmap_desc *to;
int i;
gossip_debug(GOSSIP_BUFMAP_DEBUG,
"%s: buffer_index:%d: size:%zu:\n",
__func__, buffer_index, size);
to = &__orangefs_bufmap->desc_array[buffer_index];
for (i = 0; size; i++) {
struct page *page = to->page_array[i];
size_t n = size;
if (n > PAGE_SIZE)
n = PAGE_SIZE;
if (copy_page_from_iter(page, 0, n, iter) != n)
return -EFAULT;
size -= n;
}
return 0;
}
int orangefs_bufmap_copy_to_iovec(struct iov_iter *iter,
int buffer_index,
size_t size)
{
struct orangefs_bufmap_desc *from;
int i;
from = &__orangefs_bufmap->desc_array[buffer_index];
gossip_debug(GOSSIP_BUFMAP_DEBUG,
"%s: buffer_index:%d: size:%zu:\n",
__func__, buffer_index, size);
for (i = 0; size; i++) {
struct page *page = from->page_array[i];
size_t n = size;
if (n > PAGE_SIZE)
n = PAGE_SIZE;
n = copy_page_to_iter(page, 0, n, iter);
if (!n)
return -EFAULT;
size -= n;
}
return 0;
}
