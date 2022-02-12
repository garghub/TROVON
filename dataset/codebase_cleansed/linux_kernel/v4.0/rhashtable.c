static spinlock_t *bucket_lock(const struct bucket_table *tbl, u32 hash)
{
return &tbl->locks[hash & tbl->locks_mask];
}
static void *rht_obj(const struct rhashtable *ht, const struct rhash_head *he)
{
return (void *) he - ht->p.head_offset;
}
static u32 rht_bucket_index(const struct bucket_table *tbl, u32 hash)
{
return hash & (tbl->size - 1);
}
static u32 obj_raw_hashfn(const struct rhashtable *ht, const void *ptr)
{
u32 hash;
if (unlikely(!ht->p.key_len))
hash = ht->p.obj_hashfn(ptr, ht->p.hash_rnd);
else
hash = ht->p.hashfn(ptr + ht->p.key_offset, ht->p.key_len,
ht->p.hash_rnd);
return hash >> HASH_RESERVED_SPACE;
}
static u32 key_hashfn(struct rhashtable *ht, const void *key, u32 len)
{
return ht->p.hashfn(key, len, ht->p.hash_rnd) >> HASH_RESERVED_SPACE;
}
static u32 head_hashfn(const struct rhashtable *ht,
const struct bucket_table *tbl,
const struct rhash_head *he)
{
return rht_bucket_index(tbl, obj_raw_hashfn(ht, rht_obj(ht, he)));
}
static void debug_dump_buckets(const struct rhashtable *ht,
const struct bucket_table *tbl)
{
struct rhash_head *he;
unsigned int i, hash;
for (i = 0; i < tbl->size; i++) {
pr_warn(" [Bucket %d] ", i);
rht_for_each_rcu(he, tbl, i) {
hash = head_hashfn(ht, tbl, he);
pr_cont("[hash = %#x, lock = %p] ",
hash, bucket_lock(tbl, hash));
}
pr_cont("\n");
}
}
static void debug_dump_table(struct rhashtable *ht,
const struct bucket_table *tbl,
unsigned int hash)
{
struct bucket_table *old_tbl, *future_tbl;
pr_emerg("BUG: lock for hash %#x in table %p not held\n",
hash, tbl);
rcu_read_lock();
future_tbl = rht_dereference_rcu(ht->future_tbl, ht);
old_tbl = rht_dereference_rcu(ht->tbl, ht);
if (future_tbl != old_tbl) {
pr_warn("Future table %p (size: %zd)\n",
future_tbl, future_tbl->size);
debug_dump_buckets(ht, future_tbl);
}
pr_warn("Table %p (size: %zd)\n", old_tbl, old_tbl->size);
debug_dump_buckets(ht, old_tbl);
rcu_read_unlock();
}
int lockdep_rht_mutex_is_held(struct rhashtable *ht)
{
return (debug_locks) ? lockdep_is_held(&ht->mutex) : 1;
}
int lockdep_rht_bucket_is_held(const struct bucket_table *tbl, u32 hash)
{
spinlock_t *lock = bucket_lock(tbl, hash);
return (debug_locks) ? lockdep_is_held(lock) : 1;
}
static struct rhash_head __rcu **bucket_tail(struct bucket_table *tbl, u32 n)
{
struct rhash_head __rcu **pprev;
for (pprev = &tbl->buckets[n];
!rht_is_a_nulls(rht_dereference_bucket(*pprev, tbl, n));
pprev = &rht_dereference_bucket(*pprev, tbl, n)->next)
;
return pprev;
}
static int alloc_bucket_locks(struct rhashtable *ht, struct bucket_table *tbl)
{
unsigned int i, size;
#if defined(CONFIG_PROVE_LOCKING)
unsigned int nr_pcpus = 2;
#else
unsigned int nr_pcpus = num_possible_cpus();
#endif
nr_pcpus = min_t(unsigned int, nr_pcpus, 32UL);
size = roundup_pow_of_two(nr_pcpus * ht->p.locks_mul);
size = min_t(unsigned int, size, tbl->size >> 1);
if (sizeof(spinlock_t) != 0) {
#ifdef CONFIG_NUMA
if (size * sizeof(spinlock_t) > PAGE_SIZE)
tbl->locks = vmalloc(size * sizeof(spinlock_t));
else
#endif
tbl->locks = kmalloc_array(size, sizeof(spinlock_t),
GFP_KERNEL);
if (!tbl->locks)
return -ENOMEM;
for (i = 0; i < size; i++)
spin_lock_init(&tbl->locks[i]);
}
tbl->locks_mask = size - 1;
return 0;
}
static void bucket_table_free(const struct bucket_table *tbl)
{
if (tbl)
kvfree(tbl->locks);
kvfree(tbl);
}
static struct bucket_table *bucket_table_alloc(struct rhashtable *ht,
size_t nbuckets)
{
struct bucket_table *tbl = NULL;
size_t size;
int i;
size = sizeof(*tbl) + nbuckets * sizeof(tbl->buckets[0]);
if (size <= (PAGE_SIZE << PAGE_ALLOC_COSTLY_ORDER))
tbl = kzalloc(size, GFP_KERNEL | __GFP_NOWARN | __GFP_NORETRY);
if (tbl == NULL)
tbl = vzalloc(size);
if (tbl == NULL)
return NULL;
tbl->size = nbuckets;
if (alloc_bucket_locks(ht, tbl) < 0) {
bucket_table_free(tbl);
return NULL;
}
for (i = 0; i < nbuckets; i++)
INIT_RHT_NULLS_HEAD(tbl->buckets[i], ht, i);
return tbl;
}
static bool rht_grow_above_75(const struct rhashtable *ht, size_t new_size)
{
return atomic_read(&ht->nelems) > (new_size / 4 * 3) &&
(!ht->p.max_shift || atomic_read(&ht->shift) < ht->p.max_shift);
}
static bool rht_shrink_below_30(const struct rhashtable *ht, size_t new_size)
{
return atomic_read(&ht->nelems) < (new_size * 3 / 10) &&
(atomic_read(&ht->shift) > ht->p.min_shift);
}
static void lock_buckets(struct bucket_table *new_tbl,
struct bucket_table *old_tbl, unsigned int hash)
__acquires(old_bucket_lock)
{
spin_lock_bh(bucket_lock(old_tbl, hash));
if (new_tbl != old_tbl)
spin_lock_bh_nested(bucket_lock(new_tbl, hash),
RHT_LOCK_NESTED);
}
static void unlock_buckets(struct bucket_table *new_tbl,
struct bucket_table *old_tbl, unsigned int hash)
__releases(old_bucket_lock)
{
if (new_tbl != old_tbl)
spin_unlock_bh(bucket_lock(new_tbl, hash));
spin_unlock_bh(bucket_lock(old_tbl, hash));
}
static bool hashtable_chain_unzip(struct rhashtable *ht,
const struct bucket_table *new_tbl,
struct bucket_table *old_tbl,
size_t old_hash)
{
struct rhash_head *he, *p, *next;
unsigned int new_hash, new_hash2;
ASSERT_BUCKET_LOCK(ht, old_tbl, old_hash);
p = rht_dereference_bucket(old_tbl->buckets[old_hash], old_tbl,
old_hash);
if (rht_is_a_nulls(p))
return false;
new_hash = head_hashfn(ht, new_tbl, p);
ASSERT_BUCKET_LOCK(ht, new_tbl, new_hash);
rht_for_each_continue(he, p->next, old_tbl, old_hash) {
new_hash2 = head_hashfn(ht, new_tbl, he);
ASSERT_BUCKET_LOCK(ht, new_tbl, new_hash2);
if (new_hash != new_hash2)
break;
p = he;
}
rcu_assign_pointer(old_tbl->buckets[old_hash], p->next);
INIT_RHT_NULLS_HEAD(next, ht, old_hash);
if (!rht_is_a_nulls(he)) {
rht_for_each_continue(he, he->next, old_tbl, old_hash) {
if (head_hashfn(ht, new_tbl, he) == new_hash) {
next = he;
break;
}
}
}
rcu_assign_pointer(p->next, next);
p = rht_dereference_bucket(old_tbl->buckets[old_hash], old_tbl,
old_hash);
return !rht_is_a_nulls(p);
}
static void link_old_to_new(struct rhashtable *ht, struct bucket_table *new_tbl,
unsigned int new_hash, struct rhash_head *entry)
{
ASSERT_BUCKET_LOCK(ht, new_tbl, new_hash);
rcu_assign_pointer(*bucket_tail(new_tbl, new_hash), entry);
}
int rhashtable_expand(struct rhashtable *ht)
{
struct bucket_table *new_tbl, *old_tbl = rht_dereference(ht->tbl, ht);
struct rhash_head *he;
unsigned int new_hash, old_hash;
bool complete = false;
ASSERT_RHT_MUTEX(ht);
new_tbl = bucket_table_alloc(ht, old_tbl->size * 2);
if (new_tbl == NULL)
return -ENOMEM;
atomic_inc(&ht->shift);
rcu_assign_pointer(ht->future_tbl, new_tbl);
synchronize_rcu();
for (new_hash = 0; new_hash < new_tbl->size; new_hash++) {
old_hash = rht_bucket_index(old_tbl, new_hash);
lock_buckets(new_tbl, old_tbl, new_hash);
rht_for_each(he, old_tbl, old_hash) {
if (head_hashfn(ht, new_tbl, he) == new_hash) {
link_old_to_new(ht, new_tbl, new_hash, he);
break;
}
}
unlock_buckets(new_tbl, old_tbl, new_hash);
cond_resched();
}
while (!complete && !ht->being_destroyed) {
synchronize_rcu();
complete = true;
for (old_hash = 0; old_hash < old_tbl->size; old_hash++) {
lock_buckets(new_tbl, old_tbl, old_hash);
if (hashtable_chain_unzip(ht, new_tbl, old_tbl,
old_hash))
complete = false;
unlock_buckets(new_tbl, old_tbl, old_hash);
cond_resched();
}
}
rcu_assign_pointer(ht->tbl, new_tbl);
synchronize_rcu();
bucket_table_free(old_tbl);
return 0;
}
int rhashtable_shrink(struct rhashtable *ht)
{
struct bucket_table *new_tbl, *tbl = rht_dereference(ht->tbl, ht);
unsigned int new_hash;
ASSERT_RHT_MUTEX(ht);
new_tbl = bucket_table_alloc(ht, tbl->size / 2);
if (new_tbl == NULL)
return -ENOMEM;
rcu_assign_pointer(ht->future_tbl, new_tbl);
synchronize_rcu();
for (new_hash = 0; new_hash < new_tbl->size; new_hash++) {
lock_buckets(new_tbl, tbl, new_hash);
rcu_assign_pointer(*bucket_tail(new_tbl, new_hash),
tbl->buckets[new_hash]);
ASSERT_BUCKET_LOCK(ht, tbl, new_hash + new_tbl->size);
rcu_assign_pointer(*bucket_tail(new_tbl, new_hash),
tbl->buckets[new_hash + new_tbl->size]);
unlock_buckets(new_tbl, tbl, new_hash);
cond_resched();
}
rcu_assign_pointer(ht->tbl, new_tbl);
atomic_dec(&ht->shift);
synchronize_rcu();
bucket_table_free(tbl);
return 0;
}
static void rht_deferred_worker(struct work_struct *work)
{
struct rhashtable *ht;
struct bucket_table *tbl;
struct rhashtable_walker *walker;
ht = container_of(work, struct rhashtable, run_work);
mutex_lock(&ht->mutex);
if (ht->being_destroyed)
goto unlock;
tbl = rht_dereference(ht->tbl, ht);
list_for_each_entry(walker, &ht->walkers, list)
walker->resize = true;
if (rht_grow_above_75(ht, tbl->size))
rhashtable_expand(ht);
else if (rht_shrink_below_30(ht, tbl->size))
rhashtable_shrink(ht);
unlock:
mutex_unlock(&ht->mutex);
}
static void __rhashtable_insert(struct rhashtable *ht, struct rhash_head *obj,
struct bucket_table *tbl,
const struct bucket_table *old_tbl, u32 hash)
{
bool no_resize_running = tbl == old_tbl;
struct rhash_head *head;
hash = rht_bucket_index(tbl, hash);
head = rht_dereference_bucket(tbl->buckets[hash], tbl, hash);
ASSERT_BUCKET_LOCK(ht, tbl, hash);
if (rht_is_a_nulls(head))
INIT_RHT_NULLS_HEAD(obj->next, ht, hash);
else
RCU_INIT_POINTER(obj->next, head);
rcu_assign_pointer(tbl->buckets[hash], obj);
atomic_inc(&ht->nelems);
if (no_resize_running && rht_grow_above_75(ht, tbl->size))
schedule_work(&ht->run_work);
}
void rhashtable_insert(struct rhashtable *ht, struct rhash_head *obj)
{
struct bucket_table *tbl, *old_tbl;
unsigned hash;
rcu_read_lock();
tbl = rht_dereference_rcu(ht->future_tbl, ht);
old_tbl = rht_dereference_rcu(ht->tbl, ht);
hash = obj_raw_hashfn(ht, rht_obj(ht, obj));
lock_buckets(tbl, old_tbl, hash);
__rhashtable_insert(ht, obj, tbl, old_tbl, hash);
unlock_buckets(tbl, old_tbl, hash);
rcu_read_unlock();
}
bool rhashtable_remove(struct rhashtable *ht, struct rhash_head *obj)
{
struct bucket_table *tbl, *new_tbl, *old_tbl;
struct rhash_head __rcu **pprev;
struct rhash_head *he, *he2;
unsigned int hash, new_hash;
bool ret = false;
rcu_read_lock();
old_tbl = rht_dereference_rcu(ht->tbl, ht);
tbl = new_tbl = rht_dereference_rcu(ht->future_tbl, ht);
new_hash = obj_raw_hashfn(ht, rht_obj(ht, obj));
lock_buckets(new_tbl, old_tbl, new_hash);
restart:
hash = rht_bucket_index(tbl, new_hash);
pprev = &tbl->buckets[hash];
rht_for_each(he, tbl, hash) {
if (he != obj) {
pprev = &he->next;
continue;
}
ASSERT_BUCKET_LOCK(ht, tbl, hash);
if (old_tbl->size > new_tbl->size && tbl == old_tbl &&
!rht_is_a_nulls(obj->next) &&
head_hashfn(ht, tbl, obj->next) != hash) {
rcu_assign_pointer(*pprev, (struct rhash_head *) rht_marker(ht, hash));
} else if (unlikely(old_tbl->size < new_tbl->size && tbl == new_tbl)) {
rht_for_each_continue(he2, obj->next, tbl, hash) {
if (head_hashfn(ht, tbl, he2) == hash) {
rcu_assign_pointer(*pprev, he2);
goto found;
}
}
rcu_assign_pointer(*pprev, (struct rhash_head *) rht_marker(ht, hash));
} else {
rcu_assign_pointer(*pprev, obj->next);
}
found:
ret = true;
break;
}
if (tbl != old_tbl) {
tbl = old_tbl;
goto restart;
}
unlock_buckets(new_tbl, old_tbl, new_hash);
if (ret) {
bool no_resize_running = new_tbl == old_tbl;
atomic_dec(&ht->nelems);
if (no_resize_running && rht_shrink_below_30(ht, new_tbl->size))
schedule_work(&ht->run_work);
}
rcu_read_unlock();
return ret;
}
static bool rhashtable_compare(void *ptr, void *arg)
{
struct rhashtable_compare_arg *x = arg;
struct rhashtable *ht = x->ht;
return !memcmp(ptr + ht->p.key_offset, x->key, ht->p.key_len);
}
void *rhashtable_lookup(struct rhashtable *ht, const void *key)
{
struct rhashtable_compare_arg arg = {
.ht = ht,
.key = key,
};
BUG_ON(!ht->p.key_len);
return rhashtable_lookup_compare(ht, key, &rhashtable_compare, &arg);
}
void *rhashtable_lookup_compare(struct rhashtable *ht, const void *key,
bool (*compare)(void *, void *), void *arg)
{
const struct bucket_table *tbl, *old_tbl;
struct rhash_head *he;
u32 hash;
rcu_read_lock();
old_tbl = rht_dereference_rcu(ht->tbl, ht);
tbl = rht_dereference_rcu(ht->future_tbl, ht);
hash = key_hashfn(ht, key, ht->p.key_len);
restart:
rht_for_each_rcu(he, tbl, rht_bucket_index(tbl, hash)) {
if (!compare(rht_obj(ht, he), arg))
continue;
rcu_read_unlock();
return rht_obj(ht, he);
}
if (unlikely(tbl != old_tbl)) {
tbl = old_tbl;
goto restart;
}
rcu_read_unlock();
return NULL;
}
bool rhashtable_lookup_insert(struct rhashtable *ht, struct rhash_head *obj)
{
struct rhashtable_compare_arg arg = {
.ht = ht,
.key = rht_obj(ht, obj) + ht->p.key_offset,
};
BUG_ON(!ht->p.key_len);
return rhashtable_lookup_compare_insert(ht, obj, &rhashtable_compare,
&arg);
}
bool rhashtable_lookup_compare_insert(struct rhashtable *ht,
struct rhash_head *obj,
bool (*compare)(void *, void *),
void *arg)
{
struct bucket_table *new_tbl, *old_tbl;
u32 new_hash;
bool success = true;
BUG_ON(!ht->p.key_len);
rcu_read_lock();
old_tbl = rht_dereference_rcu(ht->tbl, ht);
new_tbl = rht_dereference_rcu(ht->future_tbl, ht);
new_hash = obj_raw_hashfn(ht, rht_obj(ht, obj));
lock_buckets(new_tbl, old_tbl, new_hash);
if (rhashtable_lookup_compare(ht, rht_obj(ht, obj) + ht->p.key_offset,
compare, arg)) {
success = false;
goto exit;
}
__rhashtable_insert(ht, obj, new_tbl, old_tbl, new_hash);
exit:
unlock_buckets(new_tbl, old_tbl, new_hash);
rcu_read_unlock();
return success;
}
int rhashtable_walk_init(struct rhashtable *ht, struct rhashtable_iter *iter)
{
iter->ht = ht;
iter->p = NULL;
iter->slot = 0;
iter->skip = 0;
iter->walker = kmalloc(sizeof(*iter->walker), GFP_KERNEL);
if (!iter->walker)
return -ENOMEM;
INIT_LIST_HEAD(&iter->walker->list);
iter->walker->resize = false;
mutex_lock(&ht->mutex);
list_add(&iter->walker->list, &ht->walkers);
mutex_unlock(&ht->mutex);
return 0;
}
void rhashtable_walk_exit(struct rhashtable_iter *iter)
{
mutex_lock(&iter->ht->mutex);
list_del(&iter->walker->list);
mutex_unlock(&iter->ht->mutex);
kfree(iter->walker);
}
int rhashtable_walk_start(struct rhashtable_iter *iter)
{
rcu_read_lock();
if (iter->walker->resize) {
iter->slot = 0;
iter->skip = 0;
iter->walker->resize = false;
return -EAGAIN;
}
return 0;
}
void *rhashtable_walk_next(struct rhashtable_iter *iter)
{
const struct bucket_table *tbl;
struct rhashtable *ht = iter->ht;
struct rhash_head *p = iter->p;
void *obj = NULL;
tbl = rht_dereference_rcu(ht->tbl, ht);
if (p) {
p = rht_dereference_bucket_rcu(p->next, tbl, iter->slot);
goto next;
}
for (; iter->slot < tbl->size; iter->slot++) {
int skip = iter->skip;
rht_for_each_rcu(p, tbl, iter->slot) {
if (!skip)
break;
skip--;
}
next:
if (!rht_is_a_nulls(p)) {
iter->skip++;
iter->p = p;
obj = rht_obj(ht, p);
goto out;
}
iter->skip = 0;
}
iter->p = NULL;
out:
if (iter->walker->resize) {
iter->p = NULL;
iter->slot = 0;
iter->skip = 0;
iter->walker->resize = false;
return ERR_PTR(-EAGAIN);
}
return obj;
}
void rhashtable_walk_stop(struct rhashtable_iter *iter)
{
rcu_read_unlock();
iter->p = NULL;
}
static size_t rounded_hashtable_size(struct rhashtable_params *params)
{
return max(roundup_pow_of_two(params->nelem_hint * 4 / 3),
1UL << params->min_shift);
}
int rhashtable_init(struct rhashtable *ht, struct rhashtable_params *params)
{
struct bucket_table *tbl;
size_t size;
size = HASH_DEFAULT_SIZE;
if ((params->key_len && !params->hashfn) ||
(!params->key_len && !params->obj_hashfn))
return -EINVAL;
if (params->nulls_base && params->nulls_base < (1U << RHT_BASE_SHIFT))
return -EINVAL;
params->min_shift = max_t(size_t, params->min_shift,
ilog2(HASH_MIN_SIZE));
if (params->nelem_hint)
size = rounded_hashtable_size(params);
memset(ht, 0, sizeof(*ht));
mutex_init(&ht->mutex);
memcpy(&ht->p, params, sizeof(*params));
INIT_LIST_HEAD(&ht->walkers);
if (params->locks_mul)
ht->p.locks_mul = roundup_pow_of_two(params->locks_mul);
else
ht->p.locks_mul = BUCKET_LOCKS_PER_CPU;
tbl = bucket_table_alloc(ht, size);
if (tbl == NULL)
return -ENOMEM;
atomic_set(&ht->nelems, 0);
atomic_set(&ht->shift, ilog2(tbl->size));
RCU_INIT_POINTER(ht->tbl, tbl);
RCU_INIT_POINTER(ht->future_tbl, tbl);
if (!ht->p.hash_rnd)
get_random_bytes(&ht->p.hash_rnd, sizeof(ht->p.hash_rnd));
INIT_WORK(&ht->run_work, rht_deferred_worker);
return 0;
}
void rhashtable_destroy(struct rhashtable *ht)
{
ht->being_destroyed = true;
cancel_work_sync(&ht->run_work);
mutex_lock(&ht->mutex);
bucket_table_free(rht_dereference(ht->tbl, ht));
mutex_unlock(&ht->mutex);
}
