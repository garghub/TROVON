static inline int dm_bufio_cache_index(struct dm_bufio_client *c)
{
unsigned ret = c->blocks_per_page_bits - 1;
BUG_ON(ret >= ARRAY_SIZE(dm_bufio_caches));
return ret;
}
static void dm_bufio_lock(struct dm_bufio_client *c)
{
mutex_lock_nested(&c->lock, dm_bufio_in_request());
}
static int dm_bufio_trylock(struct dm_bufio_client *c)
{
return mutex_trylock(&c->lock);
}
static void dm_bufio_unlock(struct dm_bufio_client *c)
{
mutex_unlock(&c->lock);
}
static void adjust_total_allocated(enum data_mode data_mode, long diff)
{
static unsigned long * const class_ptr[DATA_MODE_LIMIT] = {
&dm_bufio_allocated_kmem_cache,
&dm_bufio_allocated_get_free_pages,
&dm_bufio_allocated_vmalloc,
};
spin_lock(&param_spinlock);
*class_ptr[data_mode] += diff;
dm_bufio_current_allocated += diff;
if (dm_bufio_current_allocated > dm_bufio_peak_allocated)
dm_bufio_peak_allocated = dm_bufio_current_allocated;
spin_unlock(&param_spinlock);
}
static void __cache_size_refresh(void)
{
BUG_ON(!mutex_is_locked(&dm_bufio_clients_lock));
BUG_ON(dm_bufio_client_count < 0);
dm_bufio_cache_size_latch = ACCESS_ONCE(dm_bufio_cache_size);
if (!dm_bufio_cache_size_latch) {
(void)cmpxchg(&dm_bufio_cache_size, 0,
dm_bufio_default_cache_size);
dm_bufio_cache_size_latch = dm_bufio_default_cache_size;
}
dm_bufio_cache_size_per_client = dm_bufio_cache_size_latch /
(dm_bufio_client_count ? : 1);
}
static void *alloc_buffer_data(struct dm_bufio_client *c, gfp_t gfp_mask,
enum data_mode *data_mode)
{
unsigned noio_flag;
void *ptr;
if (c->block_size <= DM_BUFIO_BLOCK_SIZE_SLAB_LIMIT) {
*data_mode = DATA_MODE_SLAB;
return kmem_cache_alloc(DM_BUFIO_CACHE(c), gfp_mask);
}
if (c->block_size <= DM_BUFIO_BLOCK_SIZE_GFP_LIMIT &&
gfp_mask & __GFP_NORETRY) {
*data_mode = DATA_MODE_GET_FREE_PAGES;
return (void *)__get_free_pages(gfp_mask,
c->pages_per_block_bits);
}
*data_mode = DATA_MODE_VMALLOC;
if (gfp_mask & __GFP_NORETRY)
noio_flag = memalloc_noio_save();
ptr = __vmalloc(c->block_size, gfp_mask | __GFP_HIGHMEM, PAGE_KERNEL);
if (gfp_mask & __GFP_NORETRY)
memalloc_noio_restore(noio_flag);
return ptr;
}
static void free_buffer_data(struct dm_bufio_client *c,
void *data, enum data_mode data_mode)
{
switch (data_mode) {
case DATA_MODE_SLAB:
kmem_cache_free(DM_BUFIO_CACHE(c), data);
break;
case DATA_MODE_GET_FREE_PAGES:
free_pages((unsigned long)data, c->pages_per_block_bits);
break;
case DATA_MODE_VMALLOC:
vfree(data);
break;
default:
DMCRIT("dm_bufio_free_buffer_data: bad data mode: %d",
data_mode);
BUG();
}
}
static struct dm_buffer *alloc_buffer(struct dm_bufio_client *c, gfp_t gfp_mask)
{
struct dm_buffer *b = kmalloc(sizeof(struct dm_buffer) + c->aux_size,
gfp_mask);
if (!b)
return NULL;
b->c = c;
b->data = alloc_buffer_data(c, gfp_mask, &b->data_mode);
if (!b->data) {
kfree(b);
return NULL;
}
adjust_total_allocated(b->data_mode, (long)c->block_size);
return b;
}
static void free_buffer(struct dm_buffer *b)
{
struct dm_bufio_client *c = b->c;
adjust_total_allocated(b->data_mode, -(long)c->block_size);
free_buffer_data(c, b->data, b->data_mode);
kfree(b);
}
static void __link_buffer(struct dm_buffer *b, sector_t block, int dirty)
{
struct dm_bufio_client *c = b->c;
c->n_buffers[dirty]++;
b->block = block;
b->list_mode = dirty;
list_add(&b->lru_list, &c->lru[dirty]);
hlist_add_head(&b->hash_list, &c->cache_hash[DM_BUFIO_HASH(block)]);
b->last_accessed = jiffies;
}
static void __unlink_buffer(struct dm_buffer *b)
{
struct dm_bufio_client *c = b->c;
BUG_ON(!c->n_buffers[b->list_mode]);
c->n_buffers[b->list_mode]--;
hlist_del(&b->hash_list);
list_del(&b->lru_list);
}
static void __relink_lru(struct dm_buffer *b, int dirty)
{
struct dm_bufio_client *c = b->c;
BUG_ON(!c->n_buffers[b->list_mode]);
c->n_buffers[b->list_mode]--;
c->n_buffers[dirty]++;
b->list_mode = dirty;
list_move(&b->lru_list, &c->lru[dirty]);
b->last_accessed = jiffies;
}
static void dmio_complete(unsigned long error, void *context)
{
struct dm_buffer *b = context;
b->bio.bi_end_io(&b->bio, error ? -EIO : 0);
}
static void use_dmio(struct dm_buffer *b, int rw, sector_t block,
bio_end_io_t *end_io)
{
int r;
struct dm_io_request io_req = {
.bi_rw = rw,
.notify.fn = dmio_complete,
.notify.context = b,
.client = b->c->dm_io,
};
struct dm_io_region region = {
.bdev = b->c->bdev,
.sector = block << b->c->sectors_per_block_bits,
.count = b->c->block_size >> SECTOR_SHIFT,
};
if (b->data_mode != DATA_MODE_VMALLOC) {
io_req.mem.type = DM_IO_KMEM;
io_req.mem.ptr.addr = b->data;
} else {
io_req.mem.type = DM_IO_VMA;
io_req.mem.ptr.vma = b->data;
}
b->bio.bi_end_io = end_io;
r = dm_io(&io_req, 1, &region, NULL);
if (r)
end_io(&b->bio, r);
}
static void use_inline_bio(struct dm_buffer *b, int rw, sector_t block,
bio_end_io_t *end_io)
{
char *ptr;
int len;
bio_init(&b->bio);
b->bio.bi_io_vec = b->bio_vec;
b->bio.bi_max_vecs = DM_BUFIO_INLINE_VECS;
b->bio.bi_iter.bi_sector = block << b->c->sectors_per_block_bits;
b->bio.bi_bdev = b->c->bdev;
b->bio.bi_end_io = end_io;
ptr = b->data;
len = b->c->block_size;
if (len >= PAGE_SIZE)
BUG_ON((unsigned long)ptr & (PAGE_SIZE - 1));
else
BUG_ON((unsigned long)ptr & (len - 1));
do {
if (!bio_add_page(&b->bio, virt_to_page(ptr),
len < PAGE_SIZE ? len : PAGE_SIZE,
virt_to_phys(ptr) & (PAGE_SIZE - 1))) {
BUG_ON(b->c->block_size <= PAGE_SIZE);
use_dmio(b, rw, block, end_io);
return;
}
len -= PAGE_SIZE;
ptr += PAGE_SIZE;
} while (len > 0);
submit_bio(rw, &b->bio);
}
static void submit_io(struct dm_buffer *b, int rw, sector_t block,
bio_end_io_t *end_io)
{
if (rw == WRITE && b->c->write_callback)
b->c->write_callback(b);
if (b->c->block_size <= DM_BUFIO_INLINE_VECS * PAGE_SIZE &&
b->data_mode != DATA_MODE_VMALLOC)
use_inline_bio(b, rw, block, end_io);
else
use_dmio(b, rw, block, end_io);
}
static void write_endio(struct bio *bio, int error)
{
struct dm_buffer *b = container_of(bio, struct dm_buffer, bio);
b->write_error = error;
if (unlikely(error)) {
struct dm_bufio_client *c = b->c;
(void)cmpxchg(&c->async_write_error, 0, error);
}
BUG_ON(!test_bit(B_WRITING, &b->state));
smp_mb__before_atomic();
clear_bit(B_WRITING, &b->state);
smp_mb__after_atomic();
wake_up_bit(&b->state, B_WRITING);
}
static void __write_dirty_buffer(struct dm_buffer *b,
struct list_head *write_list)
{
if (!test_bit(B_DIRTY, &b->state))
return;
clear_bit(B_DIRTY, &b->state);
wait_on_bit_lock_io(&b->state, B_WRITING, TASK_UNINTERRUPTIBLE);
if (!write_list)
submit_io(b, WRITE, b->block, write_endio);
else
list_add_tail(&b->write_list, write_list);
}
static void __flush_write_list(struct list_head *write_list)
{
struct blk_plug plug;
blk_start_plug(&plug);
while (!list_empty(write_list)) {
struct dm_buffer *b =
list_entry(write_list->next, struct dm_buffer, write_list);
list_del(&b->write_list);
submit_io(b, WRITE, b->block, write_endio);
dm_bufio_cond_resched();
}
blk_finish_plug(&plug);
}
static void __make_buffer_clean(struct dm_buffer *b)
{
BUG_ON(b->hold_count);
if (!b->state)
return;
wait_on_bit_io(&b->state, B_READING, TASK_UNINTERRUPTIBLE);
__write_dirty_buffer(b, NULL);
wait_on_bit_io(&b->state, B_WRITING, TASK_UNINTERRUPTIBLE);
}
static struct dm_buffer *__get_unclaimed_buffer(struct dm_bufio_client *c)
{
struct dm_buffer *b;
list_for_each_entry_reverse(b, &c->lru[LIST_CLEAN], lru_list) {
BUG_ON(test_bit(B_WRITING, &b->state));
BUG_ON(test_bit(B_DIRTY, &b->state));
if (!b->hold_count) {
__make_buffer_clean(b);
__unlink_buffer(b);
return b;
}
dm_bufio_cond_resched();
}
list_for_each_entry_reverse(b, &c->lru[LIST_DIRTY], lru_list) {
BUG_ON(test_bit(B_READING, &b->state));
if (!b->hold_count) {
__make_buffer_clean(b);
__unlink_buffer(b);
return b;
}
dm_bufio_cond_resched();
}
return NULL;
}
static void __wait_for_free_buffer(struct dm_bufio_client *c)
{
DECLARE_WAITQUEUE(wait, current);
add_wait_queue(&c->free_buffer_wait, &wait);
set_task_state(current, TASK_UNINTERRUPTIBLE);
dm_bufio_unlock(c);
io_schedule();
remove_wait_queue(&c->free_buffer_wait, &wait);
dm_bufio_lock(c);
}
static struct dm_buffer *__alloc_buffer_wait_no_callback(struct dm_bufio_client *c, enum new_flag nf)
{
struct dm_buffer *b;
while (1) {
if (dm_bufio_cache_size_latch != 1) {
b = alloc_buffer(c, GFP_NOIO | __GFP_NORETRY | __GFP_NOMEMALLOC | __GFP_NOWARN);
if (b)
return b;
}
if (nf == NF_PREFETCH)
return NULL;
if (!list_empty(&c->reserved_buffers)) {
b = list_entry(c->reserved_buffers.next,
struct dm_buffer, lru_list);
list_del(&b->lru_list);
c->need_reserved_buffers++;
return b;
}
b = __get_unclaimed_buffer(c);
if (b)
return b;
__wait_for_free_buffer(c);
}
}
static struct dm_buffer *__alloc_buffer_wait(struct dm_bufio_client *c, enum new_flag nf)
{
struct dm_buffer *b = __alloc_buffer_wait_no_callback(c, nf);
if (!b)
return NULL;
if (c->alloc_callback)
c->alloc_callback(b);
return b;
}
static void __free_buffer_wake(struct dm_buffer *b)
{
struct dm_bufio_client *c = b->c;
if (!c->need_reserved_buffers)
free_buffer(b);
else {
list_add(&b->lru_list, &c->reserved_buffers);
c->need_reserved_buffers--;
}
wake_up(&c->free_buffer_wait);
}
static void __write_dirty_buffers_async(struct dm_bufio_client *c, int no_wait,
struct list_head *write_list)
{
struct dm_buffer *b, *tmp;
list_for_each_entry_safe_reverse(b, tmp, &c->lru[LIST_DIRTY], lru_list) {
BUG_ON(test_bit(B_READING, &b->state));
if (!test_bit(B_DIRTY, &b->state) &&
!test_bit(B_WRITING, &b->state)) {
__relink_lru(b, LIST_CLEAN);
continue;
}
if (no_wait && test_bit(B_WRITING, &b->state))
return;
__write_dirty_buffer(b, write_list);
dm_bufio_cond_resched();
}
}
static void __get_memory_limit(struct dm_bufio_client *c,
unsigned long *threshold_buffers,
unsigned long *limit_buffers)
{
unsigned long buffers;
if (ACCESS_ONCE(dm_bufio_cache_size) != dm_bufio_cache_size_latch) {
mutex_lock(&dm_bufio_clients_lock);
__cache_size_refresh();
mutex_unlock(&dm_bufio_clients_lock);
}
buffers = dm_bufio_cache_size_per_client >>
(c->sectors_per_block_bits + SECTOR_SHIFT);
if (buffers < c->minimum_buffers)
buffers = c->minimum_buffers;
*limit_buffers = buffers;
*threshold_buffers = buffers * DM_BUFIO_WRITEBACK_PERCENT / 100;
}
static void __check_watermark(struct dm_bufio_client *c,
struct list_head *write_list)
{
unsigned long threshold_buffers, limit_buffers;
__get_memory_limit(c, &threshold_buffers, &limit_buffers);
while (c->n_buffers[LIST_CLEAN] + c->n_buffers[LIST_DIRTY] >
limit_buffers) {
struct dm_buffer *b = __get_unclaimed_buffer(c);
if (!b)
return;
__free_buffer_wake(b);
dm_bufio_cond_resched();
}
if (c->n_buffers[LIST_DIRTY] > threshold_buffers)
__write_dirty_buffers_async(c, 1, write_list);
}
static struct dm_buffer *__find(struct dm_bufio_client *c, sector_t block)
{
struct dm_buffer *b;
hlist_for_each_entry(b, &c->cache_hash[DM_BUFIO_HASH(block)],
hash_list) {
dm_bufio_cond_resched();
if (b->block == block)
return b;
}
return NULL;
}
static struct dm_buffer *__bufio_new(struct dm_bufio_client *c, sector_t block,
enum new_flag nf, int *need_submit,
struct list_head *write_list)
{
struct dm_buffer *b, *new_b = NULL;
*need_submit = 0;
b = __find(c, block);
if (b)
goto found_buffer;
if (nf == NF_GET)
return NULL;
new_b = __alloc_buffer_wait(c, nf);
if (!new_b)
return NULL;
b = __find(c, block);
if (b) {
__free_buffer_wake(new_b);
goto found_buffer;
}
__check_watermark(c, write_list);
b = new_b;
b->hold_count = 1;
b->read_error = 0;
b->write_error = 0;
__link_buffer(b, block, LIST_CLEAN);
if (nf == NF_FRESH) {
b->state = 0;
return b;
}
b->state = 1 << B_READING;
*need_submit = 1;
return b;
found_buffer:
if (nf == NF_PREFETCH)
return NULL;
if (nf == NF_GET && unlikely(test_bit(B_READING, &b->state)))
return NULL;
b->hold_count++;
__relink_lru(b, test_bit(B_DIRTY, &b->state) ||
test_bit(B_WRITING, &b->state));
return b;
}
static void read_endio(struct bio *bio, int error)
{
struct dm_buffer *b = container_of(bio, struct dm_buffer, bio);
b->read_error = error;
BUG_ON(!test_bit(B_READING, &b->state));
smp_mb__before_atomic();
clear_bit(B_READING, &b->state);
smp_mb__after_atomic();
wake_up_bit(&b->state, B_READING);
}
static void *new_read(struct dm_bufio_client *c, sector_t block,
enum new_flag nf, struct dm_buffer **bp)
{
int need_submit;
struct dm_buffer *b;
LIST_HEAD(write_list);
dm_bufio_lock(c);
b = __bufio_new(c, block, nf, &need_submit, &write_list);
dm_bufio_unlock(c);
__flush_write_list(&write_list);
if (!b)
return b;
if (need_submit)
submit_io(b, READ, b->block, read_endio);
wait_on_bit_io(&b->state, B_READING, TASK_UNINTERRUPTIBLE);
if (b->read_error) {
int error = b->read_error;
dm_bufio_release(b);
return ERR_PTR(error);
}
*bp = b;
return b->data;
}
void *dm_bufio_get(struct dm_bufio_client *c, sector_t block,
struct dm_buffer **bp)
{
return new_read(c, block, NF_GET, bp);
}
void *dm_bufio_read(struct dm_bufio_client *c, sector_t block,
struct dm_buffer **bp)
{
BUG_ON(dm_bufio_in_request());
return new_read(c, block, NF_READ, bp);
}
void *dm_bufio_new(struct dm_bufio_client *c, sector_t block,
struct dm_buffer **bp)
{
BUG_ON(dm_bufio_in_request());
return new_read(c, block, NF_FRESH, bp);
}
void dm_bufio_prefetch(struct dm_bufio_client *c,
sector_t block, unsigned n_blocks)
{
struct blk_plug plug;
LIST_HEAD(write_list);
BUG_ON(dm_bufio_in_request());
blk_start_plug(&plug);
dm_bufio_lock(c);
for (; n_blocks--; block++) {
int need_submit;
struct dm_buffer *b;
b = __bufio_new(c, block, NF_PREFETCH, &need_submit,
&write_list);
if (unlikely(!list_empty(&write_list))) {
dm_bufio_unlock(c);
blk_finish_plug(&plug);
__flush_write_list(&write_list);
blk_start_plug(&plug);
dm_bufio_lock(c);
}
if (unlikely(b != NULL)) {
dm_bufio_unlock(c);
if (need_submit)
submit_io(b, READ, b->block, read_endio);
dm_bufio_release(b);
dm_bufio_cond_resched();
if (!n_blocks)
goto flush_plug;
dm_bufio_lock(c);
}
}
dm_bufio_unlock(c);
flush_plug:
blk_finish_plug(&plug);
}
void dm_bufio_release(struct dm_buffer *b)
{
struct dm_bufio_client *c = b->c;
dm_bufio_lock(c);
BUG_ON(!b->hold_count);
b->hold_count--;
if (!b->hold_count) {
wake_up(&c->free_buffer_wait);
if ((b->read_error || b->write_error) &&
!test_bit(B_READING, &b->state) &&
!test_bit(B_WRITING, &b->state) &&
!test_bit(B_DIRTY, &b->state)) {
__unlink_buffer(b);
__free_buffer_wake(b);
}
}
dm_bufio_unlock(c);
}
void dm_bufio_mark_buffer_dirty(struct dm_buffer *b)
{
struct dm_bufio_client *c = b->c;
dm_bufio_lock(c);
BUG_ON(test_bit(B_READING, &b->state));
if (!test_and_set_bit(B_DIRTY, &b->state))
__relink_lru(b, LIST_DIRTY);
dm_bufio_unlock(c);
}
void dm_bufio_write_dirty_buffers_async(struct dm_bufio_client *c)
{
LIST_HEAD(write_list);
BUG_ON(dm_bufio_in_request());
dm_bufio_lock(c);
__write_dirty_buffers_async(c, 0, &write_list);
dm_bufio_unlock(c);
__flush_write_list(&write_list);
}
int dm_bufio_write_dirty_buffers(struct dm_bufio_client *c)
{
int a, f;
unsigned long buffers_processed = 0;
struct dm_buffer *b, *tmp;
LIST_HEAD(write_list);
dm_bufio_lock(c);
__write_dirty_buffers_async(c, 0, &write_list);
dm_bufio_unlock(c);
__flush_write_list(&write_list);
dm_bufio_lock(c);
again:
list_for_each_entry_safe_reverse(b, tmp, &c->lru[LIST_DIRTY], lru_list) {
int dropped_lock = 0;
if (buffers_processed < c->n_buffers[LIST_DIRTY])
buffers_processed++;
BUG_ON(test_bit(B_READING, &b->state));
if (test_bit(B_WRITING, &b->state)) {
if (buffers_processed < c->n_buffers[LIST_DIRTY]) {
dropped_lock = 1;
b->hold_count++;
dm_bufio_unlock(c);
wait_on_bit_io(&b->state, B_WRITING,
TASK_UNINTERRUPTIBLE);
dm_bufio_lock(c);
b->hold_count--;
} else
wait_on_bit_io(&b->state, B_WRITING,
TASK_UNINTERRUPTIBLE);
}
if (!test_bit(B_DIRTY, &b->state) &&
!test_bit(B_WRITING, &b->state))
__relink_lru(b, LIST_CLEAN);
dm_bufio_cond_resched();
if (dropped_lock)
goto again;
}
wake_up(&c->free_buffer_wait);
dm_bufio_unlock(c);
a = xchg(&c->async_write_error, 0);
f = dm_bufio_issue_flush(c);
if (a)
return a;
return f;
}
int dm_bufio_issue_flush(struct dm_bufio_client *c)
{
struct dm_io_request io_req = {
.bi_rw = WRITE_FLUSH,
.mem.type = DM_IO_KMEM,
.mem.ptr.addr = NULL,
.client = c->dm_io,
};
struct dm_io_region io_reg = {
.bdev = c->bdev,
.sector = 0,
.count = 0,
};
BUG_ON(dm_bufio_in_request());
return dm_io(&io_req, 1, &io_reg, NULL);
}
void dm_bufio_release_move(struct dm_buffer *b, sector_t new_block)
{
struct dm_bufio_client *c = b->c;
struct dm_buffer *new;
BUG_ON(dm_bufio_in_request());
dm_bufio_lock(c);
retry:
new = __find(c, new_block);
if (new) {
if (new->hold_count) {
__wait_for_free_buffer(c);
goto retry;
}
__make_buffer_clean(new);
__unlink_buffer(new);
__free_buffer_wake(new);
}
BUG_ON(!b->hold_count);
BUG_ON(test_bit(B_READING, &b->state));
__write_dirty_buffer(b, NULL);
if (b->hold_count == 1) {
wait_on_bit_io(&b->state, B_WRITING,
TASK_UNINTERRUPTIBLE);
set_bit(B_DIRTY, &b->state);
__unlink_buffer(b);
__link_buffer(b, new_block, LIST_DIRTY);
} else {
sector_t old_block;
wait_on_bit_lock_io(&b->state, B_WRITING,
TASK_UNINTERRUPTIBLE);
old_block = b->block;
__unlink_buffer(b);
__link_buffer(b, new_block, b->list_mode);
submit_io(b, WRITE, new_block, write_endio);
wait_on_bit_io(&b->state, B_WRITING,
TASK_UNINTERRUPTIBLE);
__unlink_buffer(b);
__link_buffer(b, old_block, b->list_mode);
}
dm_bufio_unlock(c);
dm_bufio_release(b);
}
void dm_bufio_forget(struct dm_bufio_client *c, sector_t block)
{
struct dm_buffer *b;
dm_bufio_lock(c);
b = __find(c, block);
if (b && likely(!b->hold_count) && likely(!b->state)) {
__unlink_buffer(b);
__free_buffer_wake(b);
}
dm_bufio_unlock(c);
}
void dm_bufio_set_minimum_buffers(struct dm_bufio_client *c, unsigned n)
{
c->minimum_buffers = n;
}
unsigned dm_bufio_get_block_size(struct dm_bufio_client *c)
{
return c->block_size;
}
sector_t dm_bufio_get_device_size(struct dm_bufio_client *c)
{
return i_size_read(c->bdev->bd_inode) >>
(SECTOR_SHIFT + c->sectors_per_block_bits);
}
sector_t dm_bufio_get_block_number(struct dm_buffer *b)
{
return b->block;
}
void *dm_bufio_get_block_data(struct dm_buffer *b)
{
return b->data;
}
void *dm_bufio_get_aux_data(struct dm_buffer *b)
{
return b + 1;
}
struct dm_bufio_client *dm_bufio_get_client(struct dm_buffer *b)
{
return b->c;
}
static void drop_buffers(struct dm_bufio_client *c)
{
struct dm_buffer *b;
int i;
BUG_ON(dm_bufio_in_request());
dm_bufio_write_dirty_buffers_async(c);
dm_bufio_lock(c);
while ((b = __get_unclaimed_buffer(c)))
__free_buffer_wake(b);
for (i = 0; i < LIST_SIZE; i++)
list_for_each_entry(b, &c->lru[i], lru_list)
DMERR("leaked buffer %llx, hold count %u, list %d",
(unsigned long long)b->block, b->hold_count, i);
for (i = 0; i < LIST_SIZE; i++)
BUG_ON(!list_empty(&c->lru[i]));
dm_bufio_unlock(c);
}
static int __cleanup_old_buffer(struct dm_buffer *b, gfp_t gfp,
unsigned long max_jiffies)
{
if (jiffies - b->last_accessed < max_jiffies)
return 0;
if (!(gfp & __GFP_FS)) {
if (test_bit(B_READING, &b->state) ||
test_bit(B_WRITING, &b->state) ||
test_bit(B_DIRTY, &b->state))
return 0;
}
if (b->hold_count)
return 0;
__make_buffer_clean(b);
__unlink_buffer(b);
__free_buffer_wake(b);
return 1;
}
static long __scan(struct dm_bufio_client *c, unsigned long nr_to_scan,
gfp_t gfp_mask)
{
int l;
struct dm_buffer *b, *tmp;
long freed = 0;
for (l = 0; l < LIST_SIZE; l++) {
list_for_each_entry_safe_reverse(b, tmp, &c->lru[l], lru_list) {
freed += __cleanup_old_buffer(b, gfp_mask, 0);
if (!--nr_to_scan)
return freed;
dm_bufio_cond_resched();
}
}
return freed;
}
static unsigned long
dm_bufio_shrink_scan(struct shrinker *shrink, struct shrink_control *sc)
{
struct dm_bufio_client *c;
unsigned long freed;
c = container_of(shrink, struct dm_bufio_client, shrinker);
if (sc->gfp_mask & __GFP_FS)
dm_bufio_lock(c);
else if (!dm_bufio_trylock(c))
return SHRINK_STOP;
freed = __scan(c, sc->nr_to_scan, sc->gfp_mask);
dm_bufio_unlock(c);
return freed;
}
static unsigned long
dm_bufio_shrink_count(struct shrinker *shrink, struct shrink_control *sc)
{
struct dm_bufio_client *c;
unsigned long count;
c = container_of(shrink, struct dm_bufio_client, shrinker);
if (sc->gfp_mask & __GFP_FS)
dm_bufio_lock(c);
else if (!dm_bufio_trylock(c))
return 0;
count = c->n_buffers[LIST_CLEAN] + c->n_buffers[LIST_DIRTY];
dm_bufio_unlock(c);
return count;
}
struct dm_bufio_client *dm_bufio_client_create(struct block_device *bdev, unsigned block_size,
unsigned reserved_buffers, unsigned aux_size,
void (*alloc_callback)(struct dm_buffer *),
void (*write_callback)(struct dm_buffer *))
{
int r;
struct dm_bufio_client *c;
unsigned i;
BUG_ON(block_size < 1 << SECTOR_SHIFT ||
(block_size & (block_size - 1)));
c = kzalloc(sizeof(*c), GFP_KERNEL);
if (!c) {
r = -ENOMEM;
goto bad_client;
}
c->cache_hash = vmalloc(sizeof(struct hlist_head) << DM_BUFIO_HASH_BITS);
if (!c->cache_hash) {
r = -ENOMEM;
goto bad_hash;
}
c->bdev = bdev;
c->block_size = block_size;
c->sectors_per_block_bits = ffs(block_size) - 1 - SECTOR_SHIFT;
c->pages_per_block_bits = (ffs(block_size) - 1 >= PAGE_SHIFT) ?
ffs(block_size) - 1 - PAGE_SHIFT : 0;
c->blocks_per_page_bits = (ffs(block_size) - 1 < PAGE_SHIFT ?
PAGE_SHIFT - (ffs(block_size) - 1) : 0);
c->aux_size = aux_size;
c->alloc_callback = alloc_callback;
c->write_callback = write_callback;
for (i = 0; i < LIST_SIZE; i++) {
INIT_LIST_HEAD(&c->lru[i]);
c->n_buffers[i] = 0;
}
for (i = 0; i < 1 << DM_BUFIO_HASH_BITS; i++)
INIT_HLIST_HEAD(&c->cache_hash[i]);
mutex_init(&c->lock);
INIT_LIST_HEAD(&c->reserved_buffers);
c->need_reserved_buffers = reserved_buffers;
c->minimum_buffers = DM_BUFIO_MIN_BUFFERS;
init_waitqueue_head(&c->free_buffer_wait);
c->async_write_error = 0;
c->dm_io = dm_io_client_create();
if (IS_ERR(c->dm_io)) {
r = PTR_ERR(c->dm_io);
goto bad_dm_io;
}
mutex_lock(&dm_bufio_clients_lock);
if (c->blocks_per_page_bits) {
if (!DM_BUFIO_CACHE_NAME(c)) {
DM_BUFIO_CACHE_NAME(c) = kasprintf(GFP_KERNEL, "dm_bufio_cache-%u", c->block_size);
if (!DM_BUFIO_CACHE_NAME(c)) {
r = -ENOMEM;
mutex_unlock(&dm_bufio_clients_lock);
goto bad_cache;
}
}
if (!DM_BUFIO_CACHE(c)) {
DM_BUFIO_CACHE(c) = kmem_cache_create(DM_BUFIO_CACHE_NAME(c),
c->block_size,
c->block_size, 0, NULL);
if (!DM_BUFIO_CACHE(c)) {
r = -ENOMEM;
mutex_unlock(&dm_bufio_clients_lock);
goto bad_cache;
}
}
}
mutex_unlock(&dm_bufio_clients_lock);
while (c->need_reserved_buffers) {
struct dm_buffer *b = alloc_buffer(c, GFP_KERNEL);
if (!b) {
r = -ENOMEM;
goto bad_buffer;
}
__free_buffer_wake(b);
}
mutex_lock(&dm_bufio_clients_lock);
dm_bufio_client_count++;
list_add(&c->client_list, &dm_bufio_all_clients);
__cache_size_refresh();
mutex_unlock(&dm_bufio_clients_lock);
c->shrinker.count_objects = dm_bufio_shrink_count;
c->shrinker.scan_objects = dm_bufio_shrink_scan;
c->shrinker.seeks = 1;
c->shrinker.batch = 0;
register_shrinker(&c->shrinker);
return c;
bad_buffer:
bad_cache:
while (!list_empty(&c->reserved_buffers)) {
struct dm_buffer *b = list_entry(c->reserved_buffers.next,
struct dm_buffer, lru_list);
list_del(&b->lru_list);
free_buffer(b);
}
dm_io_client_destroy(c->dm_io);
bad_dm_io:
vfree(c->cache_hash);
bad_hash:
kfree(c);
bad_client:
return ERR_PTR(r);
}
void dm_bufio_client_destroy(struct dm_bufio_client *c)
{
unsigned i;
drop_buffers(c);
unregister_shrinker(&c->shrinker);
mutex_lock(&dm_bufio_clients_lock);
list_del(&c->client_list);
dm_bufio_client_count--;
__cache_size_refresh();
mutex_unlock(&dm_bufio_clients_lock);
for (i = 0; i < 1 << DM_BUFIO_HASH_BITS; i++)
BUG_ON(!hlist_empty(&c->cache_hash[i]));
BUG_ON(c->need_reserved_buffers);
while (!list_empty(&c->reserved_buffers)) {
struct dm_buffer *b = list_entry(c->reserved_buffers.next,
struct dm_buffer, lru_list);
list_del(&b->lru_list);
free_buffer(b);
}
for (i = 0; i < LIST_SIZE; i++)
if (c->n_buffers[i])
DMERR("leaked buffer count %d: %ld", i, c->n_buffers[i]);
for (i = 0; i < LIST_SIZE; i++)
BUG_ON(c->n_buffers[i]);
dm_io_client_destroy(c->dm_io);
vfree(c->cache_hash);
kfree(c);
}
static void cleanup_old_buffers(void)
{
unsigned long max_age = ACCESS_ONCE(dm_bufio_max_age);
struct dm_bufio_client *c;
if (max_age > ULONG_MAX / HZ)
max_age = ULONG_MAX / HZ;
mutex_lock(&dm_bufio_clients_lock);
list_for_each_entry(c, &dm_bufio_all_clients, client_list) {
if (!dm_bufio_trylock(c))
continue;
while (!list_empty(&c->lru[LIST_CLEAN])) {
struct dm_buffer *b;
b = list_entry(c->lru[LIST_CLEAN].prev,
struct dm_buffer, lru_list);
if (!__cleanup_old_buffer(b, 0, max_age * HZ))
break;
dm_bufio_cond_resched();
}
dm_bufio_unlock(c);
dm_bufio_cond_resched();
}
mutex_unlock(&dm_bufio_clients_lock);
}
static void work_fn(struct work_struct *w)
{
cleanup_old_buffers();
queue_delayed_work(dm_bufio_wq, &dm_bufio_work,
DM_BUFIO_WORK_TIMER_SECS * HZ);
}
static int __init dm_bufio_init(void)
{
__u64 mem;
dm_bufio_allocated_kmem_cache = 0;
dm_bufio_allocated_get_free_pages = 0;
dm_bufio_allocated_vmalloc = 0;
dm_bufio_current_allocated = 0;
memset(&dm_bufio_caches, 0, sizeof dm_bufio_caches);
memset(&dm_bufio_cache_names, 0, sizeof dm_bufio_cache_names);
mem = (__u64)((totalram_pages - totalhigh_pages) *
DM_BUFIO_MEMORY_PERCENT / 100) << PAGE_SHIFT;
if (mem > ULONG_MAX)
mem = ULONG_MAX;
#ifdef CONFIG_MMU
if (mem > (VMALLOC_END - VMALLOC_START) * DM_BUFIO_VMALLOC_PERCENT / 100)
mem = (VMALLOC_END - VMALLOC_START) * DM_BUFIO_VMALLOC_PERCENT / 100;
#endif
dm_bufio_default_cache_size = mem;
mutex_lock(&dm_bufio_clients_lock);
__cache_size_refresh();
mutex_unlock(&dm_bufio_clients_lock);
dm_bufio_wq = create_singlethread_workqueue("dm_bufio_cache");
if (!dm_bufio_wq)
return -ENOMEM;
INIT_DELAYED_WORK(&dm_bufio_work, work_fn);
queue_delayed_work(dm_bufio_wq, &dm_bufio_work,
DM_BUFIO_WORK_TIMER_SECS * HZ);
return 0;
}
static void __exit dm_bufio_exit(void)
{
int bug = 0;
int i;
cancel_delayed_work_sync(&dm_bufio_work);
destroy_workqueue(dm_bufio_wq);
for (i = 0; i < ARRAY_SIZE(dm_bufio_caches); i++) {
struct kmem_cache *kc = dm_bufio_caches[i];
if (kc)
kmem_cache_destroy(kc);
}
for (i = 0; i < ARRAY_SIZE(dm_bufio_cache_names); i++)
kfree(dm_bufio_cache_names[i]);
if (dm_bufio_client_count) {
DMCRIT("%s: dm_bufio_client_count leaked: %d",
__func__, dm_bufio_client_count);
bug = 1;
}
if (dm_bufio_current_allocated) {
DMCRIT("%s: dm_bufio_current_allocated leaked: %lu",
__func__, dm_bufio_current_allocated);
bug = 1;
}
if (dm_bufio_allocated_get_free_pages) {
DMCRIT("%s: dm_bufio_allocated_get_free_pages leaked: %lu",
__func__, dm_bufio_allocated_get_free_pages);
bug = 1;
}
if (dm_bufio_allocated_vmalloc) {
DMCRIT("%s: dm_bufio_vmalloc leaked: %lu",
__func__, dm_bufio_allocated_vmalloc);
bug = 1;
}
if (bug)
BUG();
}
