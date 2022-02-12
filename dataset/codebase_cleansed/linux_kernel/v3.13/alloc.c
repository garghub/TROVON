uint8_t bch_inc_gen(struct cache *ca, struct bucket *b)
{
uint8_t ret = ++b->gen;
ca->set->need_gc = max(ca->set->need_gc, bucket_gc_gen(b));
WARN_ON_ONCE(ca->set->need_gc > BUCKET_GC_GEN_MAX);
if (CACHE_SYNC(&ca->set->sb)) {
ca->need_save_prio = max(ca->need_save_prio,
bucket_disk_gen(b));
WARN_ON_ONCE(ca->need_save_prio > BUCKET_DISK_GEN_MAX);
}
return ret;
}
void bch_rescale_priorities(struct cache_set *c, int sectors)
{
struct cache *ca;
struct bucket *b;
unsigned next = c->nbuckets * c->sb.bucket_size / 1024;
unsigned i;
int r;
atomic_sub(sectors, &c->rescale);
do {
r = atomic_read(&c->rescale);
if (r >= 0)
return;
} while (atomic_cmpxchg(&c->rescale, r, r + next) != r);
mutex_lock(&c->bucket_lock);
c->min_prio = USHRT_MAX;
for_each_cache(ca, c, i)
for_each_bucket(b, ca)
if (b->prio &&
b->prio != BTREE_PRIO &&
!atomic_read(&b->pin)) {
b->prio--;
c->min_prio = min(c->min_prio, b->prio);
}
mutex_unlock(&c->bucket_lock);
}
static inline bool can_inc_bucket_gen(struct bucket *b)
{
return bucket_gc_gen(b) < BUCKET_GC_GEN_MAX &&
bucket_disk_gen(b) < BUCKET_DISK_GEN_MAX;
}
bool bch_bucket_add_unused(struct cache *ca, struct bucket *b)
{
BUG_ON(GC_MARK(b) || GC_SECTORS_USED(b));
if (fifo_used(&ca->free) > ca->watermark[WATERMARK_MOVINGGC] &&
CACHE_REPLACEMENT(&ca->sb) == CACHE_REPLACEMENT_FIFO)
return false;
b->prio = 0;
if (can_inc_bucket_gen(b) &&
fifo_push(&ca->unused, b - ca->buckets)) {
atomic_inc(&b->pin);
return true;
}
return false;
}
static bool can_invalidate_bucket(struct cache *ca, struct bucket *b)
{
return GC_MARK(b) == GC_MARK_RECLAIMABLE &&
!atomic_read(&b->pin) &&
can_inc_bucket_gen(b);
}
static void invalidate_one_bucket(struct cache *ca, struct bucket *b)
{
bch_inc_gen(ca, b);
b->prio = INITIAL_PRIO;
atomic_inc(&b->pin);
fifo_push(&ca->free_inc, b - ca->buckets);
}
static void invalidate_buckets_lru(struct cache *ca)
{
struct bucket *b;
ssize_t i;
ca->heap.used = 0;
for_each_bucket(b, ca) {
if (fifo_full(&ca->unused))
return;
if (!can_invalidate_bucket(ca, b))
continue;
if (!GC_SECTORS_USED(b) &&
bch_bucket_add_unused(ca, b))
continue;
if (!heap_full(&ca->heap))
heap_add(&ca->heap, b, bucket_max_cmp);
else if (bucket_max_cmp(b, heap_peek(&ca->heap))) {
ca->heap.data[0] = b;
heap_sift(&ca->heap, 0, bucket_max_cmp);
}
}
for (i = ca->heap.used / 2 - 1; i >= 0; --i)
heap_sift(&ca->heap, i, bucket_min_cmp);
while (!fifo_full(&ca->free_inc)) {
if (!heap_pop(&ca->heap, b, bucket_min_cmp)) {
ca->invalidate_needs_gc = 1;
wake_up_gc(ca->set);
return;
}
invalidate_one_bucket(ca, b);
}
}
static void invalidate_buckets_fifo(struct cache *ca)
{
struct bucket *b;
size_t checked = 0;
while (!fifo_full(&ca->free_inc)) {
if (ca->fifo_last_bucket < ca->sb.first_bucket ||
ca->fifo_last_bucket >= ca->sb.nbuckets)
ca->fifo_last_bucket = ca->sb.first_bucket;
b = ca->buckets + ca->fifo_last_bucket++;
if (can_invalidate_bucket(ca, b))
invalidate_one_bucket(ca, b);
if (++checked >= ca->sb.nbuckets) {
ca->invalidate_needs_gc = 1;
wake_up_gc(ca->set);
return;
}
}
}
static void invalidate_buckets_random(struct cache *ca)
{
struct bucket *b;
size_t checked = 0;
while (!fifo_full(&ca->free_inc)) {
size_t n;
get_random_bytes(&n, sizeof(n));
n %= (size_t) (ca->sb.nbuckets - ca->sb.first_bucket);
n += ca->sb.first_bucket;
b = ca->buckets + n;
if (can_invalidate_bucket(ca, b))
invalidate_one_bucket(ca, b);
if (++checked >= ca->sb.nbuckets / 2) {
ca->invalidate_needs_gc = 1;
wake_up_gc(ca->set);
return;
}
}
}
static void invalidate_buckets(struct cache *ca)
{
if (ca->invalidate_needs_gc)
return;
switch (CACHE_REPLACEMENT(&ca->sb)) {
case CACHE_REPLACEMENT_LRU:
invalidate_buckets_lru(ca);
break;
case CACHE_REPLACEMENT_FIFO:
invalidate_buckets_fifo(ca);
break;
case CACHE_REPLACEMENT_RANDOM:
invalidate_buckets_random(ca);
break;
}
trace_bcache_alloc_invalidate(ca);
}
static int bch_allocator_thread(void *arg)
{
struct cache *ca = arg;
mutex_lock(&ca->set->bucket_lock);
while (1) {
while (1) {
long bucket;
if ((!atomic_read(&ca->set->prio_blocked) ||
!CACHE_SYNC(&ca->set->sb)) &&
!fifo_empty(&ca->unused))
fifo_pop(&ca->unused, bucket);
else if (!fifo_empty(&ca->free_inc))
fifo_pop(&ca->free_inc, bucket);
else
break;
if (ca->discard) {
mutex_unlock(&ca->set->bucket_lock);
blkdev_issue_discard(ca->bdev,
bucket_to_sector(ca->set, bucket),
ca->sb.block_size, GFP_KERNEL, 0);
mutex_lock(&ca->set->bucket_lock);
}
allocator_wait(ca, !fifo_full(&ca->free));
fifo_push(&ca->free, bucket);
wake_up(&ca->set->bucket_wait);
}
allocator_wait(ca, ca->set->gc_mark_valid &&
(ca->need_save_prio > 64 ||
!ca->invalidate_needs_gc));
invalidate_buckets(ca);
allocator_wait(ca, !atomic_read(&ca->set->prio_blocked));
if (CACHE_SYNC(&ca->set->sb) &&
(!fifo_empty(&ca->free_inc) ||
ca->need_save_prio > 64))
bch_prio_write(ca);
}
}
long bch_bucket_alloc(struct cache *ca, unsigned watermark, bool wait)
{
DEFINE_WAIT(w);
struct bucket *b;
long r;
if (fifo_used(&ca->free) > ca->watermark[watermark]) {
fifo_pop(&ca->free, r);
goto out;
}
if (!wait)
return -1;
while (1) {
if (fifo_used(&ca->free) > ca->watermark[watermark]) {
fifo_pop(&ca->free, r);
break;
}
prepare_to_wait(&ca->set->bucket_wait, &w,
TASK_UNINTERRUPTIBLE);
mutex_unlock(&ca->set->bucket_lock);
schedule();
mutex_lock(&ca->set->bucket_lock);
}
finish_wait(&ca->set->bucket_wait, &w);
out:
wake_up_process(ca->alloc_thread);
if (expensive_debug_checks(ca->set)) {
size_t iter;
long i;
for (iter = 0; iter < prio_buckets(ca) * 2; iter++)
BUG_ON(ca->prio_buckets[iter] == (uint64_t) r);
fifo_for_each(i, &ca->free, iter)
BUG_ON(i == r);
fifo_for_each(i, &ca->free_inc, iter)
BUG_ON(i == r);
fifo_for_each(i, &ca->unused, iter)
BUG_ON(i == r);
}
b = ca->buckets + r;
BUG_ON(atomic_read(&b->pin) != 1);
SET_GC_SECTORS_USED(b, ca->sb.bucket_size);
if (watermark <= WATERMARK_METADATA) {
SET_GC_MARK(b, GC_MARK_METADATA);
SET_GC_MOVE(b, 0);
b->prio = BTREE_PRIO;
} else {
SET_GC_MARK(b, GC_MARK_RECLAIMABLE);
SET_GC_MOVE(b, 0);
b->prio = INITIAL_PRIO;
}
return r;
}
void bch_bucket_free(struct cache_set *c, struct bkey *k)
{
unsigned i;
for (i = 0; i < KEY_PTRS(k); i++) {
struct bucket *b = PTR_BUCKET(c, k, i);
SET_GC_MARK(b, GC_MARK_RECLAIMABLE);
SET_GC_SECTORS_USED(b, 0);
bch_bucket_add_unused(PTR_CACHE(c, k, i), b);
}
}
int __bch_bucket_alloc_set(struct cache_set *c, unsigned watermark,
struct bkey *k, int n, bool wait)
{
int i;
lockdep_assert_held(&c->bucket_lock);
BUG_ON(!n || n > c->caches_loaded || n > 8);
bkey_init(k);
for (i = 0; i < n; i++) {
struct cache *ca = c->cache_by_alloc[i];
long b = bch_bucket_alloc(ca, watermark, wait);
if (b == -1)
goto err;
k->ptr[i] = PTR(ca->buckets[b].gen,
bucket_to_sector(c, b),
ca->sb.nr_this_dev);
SET_KEY_PTRS(k, i + 1);
}
return 0;
err:
bch_bucket_free(c, k);
bkey_put(c, k);
return -1;
}
int bch_bucket_alloc_set(struct cache_set *c, unsigned watermark,
struct bkey *k, int n, bool wait)
{
int ret;
mutex_lock(&c->bucket_lock);
ret = __bch_bucket_alloc_set(c, watermark, k, n, wait);
mutex_unlock(&c->bucket_lock);
return ret;
}
static struct open_bucket *pick_data_bucket(struct cache_set *c,
const struct bkey *search,
unsigned write_point,
struct bkey *alloc)
{
struct open_bucket *ret, *ret_task = NULL;
list_for_each_entry_reverse(ret, &c->data_buckets, list)
if (!bkey_cmp(&ret->key, search))
goto found;
else if (ret->last_write_point == write_point)
ret_task = ret;
ret = ret_task ?: list_first_entry(&c->data_buckets,
struct open_bucket, list);
found:
if (!ret->sectors_free && KEY_PTRS(alloc)) {
ret->sectors_free = c->sb.bucket_size;
bkey_copy(&ret->key, alloc);
bkey_init(alloc);
}
if (!ret->sectors_free)
ret = NULL;
return ret;
}
bool bch_alloc_sectors(struct cache_set *c, struct bkey *k, unsigned sectors,
unsigned write_point, unsigned write_prio, bool wait)
{
struct open_bucket *b;
BKEY_PADDED(key) alloc;
unsigned i;
bkey_init(&alloc.key);
spin_lock(&c->data_bucket_lock);
while (!(b = pick_data_bucket(c, k, write_point, &alloc.key))) {
unsigned watermark = write_prio
? WATERMARK_MOVINGGC
: WATERMARK_NONE;
spin_unlock(&c->data_bucket_lock);
if (bch_bucket_alloc_set(c, watermark, &alloc.key, 1, wait))
return false;
spin_lock(&c->data_bucket_lock);
}
if (KEY_PTRS(&alloc.key))
bkey_put(c, &alloc.key);
for (i = 0; i < KEY_PTRS(&b->key); i++)
EBUG_ON(ptr_stale(c, &b->key, i));
for (i = 0; i < KEY_PTRS(&b->key); i++)
k->ptr[i] = b->key.ptr[i];
sectors = min(sectors, b->sectors_free);
SET_KEY_OFFSET(k, KEY_OFFSET(k) + sectors);
SET_KEY_SIZE(k, sectors);
SET_KEY_PTRS(k, KEY_PTRS(&b->key));
list_move_tail(&b->list, &c->data_buckets);
bkey_copy_key(&b->key, k);
b->last_write_point = write_point;
b->sectors_free -= sectors;
for (i = 0; i < KEY_PTRS(&b->key); i++) {
SET_PTR_OFFSET(&b->key, i, PTR_OFFSET(&b->key, i) + sectors);
atomic_long_add(sectors,
&PTR_CACHE(c, &b->key, i)->sectors_written);
}
if (b->sectors_free < c->sb.block_size)
b->sectors_free = 0;
if (b->sectors_free)
for (i = 0; i < KEY_PTRS(&b->key); i++)
atomic_inc(&PTR_BUCKET(c, &b->key, i)->pin);
spin_unlock(&c->data_bucket_lock);
return true;
}
void bch_open_buckets_free(struct cache_set *c)
{
struct open_bucket *b;
while (!list_empty(&c->data_buckets)) {
b = list_first_entry(&c->data_buckets,
struct open_bucket, list);
list_del(&b->list);
kfree(b);
}
}
int bch_open_buckets_alloc(struct cache_set *c)
{
int i;
spin_lock_init(&c->data_bucket_lock);
for (i = 0; i < 6; i++) {
struct open_bucket *b = kzalloc(sizeof(*b), GFP_KERNEL);
if (!b)
return -ENOMEM;
list_add(&b->list, &c->data_buckets);
}
return 0;
}
int bch_cache_allocator_start(struct cache *ca)
{
struct task_struct *k = kthread_run(bch_allocator_thread,
ca, "bcache_allocator");
if (IS_ERR(k))
return PTR_ERR(k);
ca->alloc_thread = k;
return 0;
}
int bch_cache_allocator_init(struct cache *ca)
{
ca->watermark[WATERMARK_PRIO] = 0;
ca->watermark[WATERMARK_METADATA] = prio_buckets(ca);
ca->watermark[WATERMARK_MOVINGGC] = 8 +
ca->watermark[WATERMARK_METADATA];
ca->watermark[WATERMARK_NONE] = ca->free.size / 2 +
ca->watermark[WATERMARK_MOVINGGC];
return 0;
}
