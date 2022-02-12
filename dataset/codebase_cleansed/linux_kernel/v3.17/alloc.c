uint8_t bch_inc_gen(struct cache *ca, struct bucket *b)
{
uint8_t ret = ++b->gen;
ca->set->need_gc = max(ca->set->need_gc, bucket_gc_gen(b));
WARN_ON_ONCE(ca->set->need_gc > BUCKET_GC_GEN_MAX);
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
return bucket_gc_gen(b) < BUCKET_GC_GEN_MAX;
}
bool bch_can_invalidate_bucket(struct cache *ca, struct bucket *b)
{
BUG_ON(!ca->set->gc_mark_valid);
return (!GC_MARK(b) ||
GC_MARK(b) == GC_MARK_RECLAIMABLE) &&
!atomic_read(&b->pin) &&
can_inc_bucket_gen(b);
}
void __bch_invalidate_one_bucket(struct cache *ca, struct bucket *b)
{
lockdep_assert_held(&ca->set->bucket_lock);
BUG_ON(GC_MARK(b) && GC_MARK(b) != GC_MARK_RECLAIMABLE);
if (GC_SECTORS_USED(b))
trace_bcache_invalidate(ca, b - ca->buckets);
bch_inc_gen(ca, b);
b->prio = INITIAL_PRIO;
atomic_inc(&b->pin);
}
static void bch_invalidate_one_bucket(struct cache *ca, struct bucket *b)
{
__bch_invalidate_one_bucket(ca, b);
fifo_push(&ca->free_inc, b - ca->buckets);
}
static void invalidate_buckets_lru(struct cache *ca)
{
struct bucket *b;
ssize_t i;
ca->heap.used = 0;
for_each_bucket(b, ca) {
if (!bch_can_invalidate_bucket(ca, b))
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
bch_invalidate_one_bucket(ca, b);
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
if (bch_can_invalidate_bucket(ca, b))
bch_invalidate_one_bucket(ca, b);
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
if (bch_can_invalidate_bucket(ca, b))
bch_invalidate_one_bucket(ca, b);
if (++checked >= ca->sb.nbuckets / 2) {
ca->invalidate_needs_gc = 1;
wake_up_gc(ca->set);
return;
}
}
}
static void invalidate_buckets(struct cache *ca)
{
BUG_ON(ca->invalidate_needs_gc);
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
}
static int bch_allocator_push(struct cache *ca, long bucket)
{
unsigned i;
if (fifo_push(&ca->free[RESERVE_PRIO], bucket))
return true;
for (i = 0; i < RESERVE_NR; i++)
if (fifo_push(&ca->free[i], bucket))
return true;
return false;
}
static int bch_allocator_thread(void *arg)
{
struct cache *ca = arg;
mutex_lock(&ca->set->bucket_lock);
while (1) {
while (!fifo_empty(&ca->free_inc)) {
long bucket;
fifo_pop(&ca->free_inc, bucket);
if (ca->discard) {
mutex_unlock(&ca->set->bucket_lock);
blkdev_issue_discard(ca->bdev,
bucket_to_sector(ca->set, bucket),
ca->sb.bucket_size, GFP_KERNEL, 0);
mutex_lock(&ca->set->bucket_lock);
}
allocator_wait(ca, bch_allocator_push(ca, bucket));
wake_up(&ca->set->btree_cache_wait);
wake_up(&ca->set->bucket_wait);
}
retry_invalidate:
allocator_wait(ca, ca->set->gc_mark_valid &&
!ca->invalidate_needs_gc);
invalidate_buckets(ca);
allocator_wait(ca, !atomic_read(&ca->set->prio_blocked));
if (CACHE_SYNC(&ca->set->sb)) {
if (!fifo_full(&ca->free_inc))
goto retry_invalidate;
bch_prio_write(ca);
}
}
}
long bch_bucket_alloc(struct cache *ca, unsigned reserve, bool wait)
{
DEFINE_WAIT(w);
struct bucket *b;
long r;
if (fifo_pop(&ca->free[RESERVE_NONE], r) ||
fifo_pop(&ca->free[reserve], r))
goto out;
if (!wait) {
trace_bcache_alloc_fail(ca, reserve);
return -1;
}
do {
prepare_to_wait(&ca->set->bucket_wait, &w,
TASK_UNINTERRUPTIBLE);
mutex_unlock(&ca->set->bucket_lock);
schedule();
mutex_lock(&ca->set->bucket_lock);
} while (!fifo_pop(&ca->free[RESERVE_NONE], r) &&
!fifo_pop(&ca->free[reserve], r));
finish_wait(&ca->set->bucket_wait, &w);
out:
wake_up_process(ca->alloc_thread);
trace_bcache_alloc(ca, reserve);
if (expensive_debug_checks(ca->set)) {
size_t iter;
long i;
unsigned j;
for (iter = 0; iter < prio_buckets(ca) * 2; iter++)
BUG_ON(ca->prio_buckets[iter] == (uint64_t) r);
for (j = 0; j < RESERVE_NR; j++)
fifo_for_each(i, &ca->free[j], iter)
BUG_ON(i == r);
fifo_for_each(i, &ca->free_inc, iter)
BUG_ON(i == r);
}
b = ca->buckets + r;
BUG_ON(atomic_read(&b->pin) != 1);
SET_GC_SECTORS_USED(b, ca->sb.bucket_size);
if (reserve <= RESERVE_PRIO) {
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
void __bch_bucket_free(struct cache *ca, struct bucket *b)
{
SET_GC_MARK(b, 0);
SET_GC_SECTORS_USED(b, 0);
}
void bch_bucket_free(struct cache_set *c, struct bkey *k)
{
unsigned i;
for (i = 0; i < KEY_PTRS(k); i++)
__bch_bucket_free(PTR_CACHE(c, k, i),
PTR_BUCKET(c, k, i));
}
int __bch_bucket_alloc_set(struct cache_set *c, unsigned reserve,
struct bkey *k, int n, bool wait)
{
int i;
lockdep_assert_held(&c->bucket_lock);
BUG_ON(!n || n > c->caches_loaded || n > 8);
bkey_init(k);
for (i = 0; i < n; i++) {
struct cache *ca = c->cache_by_alloc[i];
long b = bch_bucket_alloc(ca, reserve, wait);
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
int bch_bucket_alloc_set(struct cache_set *c, unsigned reserve,
struct bkey *k, int n, bool wait)
{
int ret;
mutex_lock(&c->bucket_lock);
ret = __bch_bucket_alloc_set(c, reserve, k, n, wait);
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
? RESERVE_MOVINGGC
: RESERVE_NONE;
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
