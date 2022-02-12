static u32 head_hashfn(struct rhashtable *ht,
const struct bucket_table *tbl,
const struct rhash_head *he)
{
return rht_head_hashfn(ht, tbl, he, ht->p);
}
int lockdep_rht_mutex_is_held(struct rhashtable *ht)
{
return (debug_locks) ? lockdep_is_held(&ht->mutex) : 1;
}
int lockdep_rht_bucket_is_held(const struct bucket_table *tbl, u32 hash)
{
spinlock_t *lock = rht_bucket_lock(tbl, hash);
return (debug_locks) ? lockdep_is_held(lock) : 1;
}
static int alloc_bucket_locks(struct rhashtable *ht, struct bucket_table *tbl,
gfp_t gfp)
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
if (size * sizeof(spinlock_t) > PAGE_SIZE &&
gfp == GFP_KERNEL)
tbl->locks = vmalloc(size * sizeof(spinlock_t));
else
#endif
tbl->locks = kmalloc_array(size, sizeof(spinlock_t),
gfp);
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
static void bucket_table_free_rcu(struct rcu_head *head)
{
bucket_table_free(container_of(head, struct bucket_table, rcu));
}
static struct bucket_table *bucket_table_alloc(struct rhashtable *ht,
size_t nbuckets,
gfp_t gfp)
{
struct bucket_table *tbl = NULL;
size_t size;
int i;
size = sizeof(*tbl) + nbuckets * sizeof(tbl->buckets[0]);
if (size <= (PAGE_SIZE << PAGE_ALLOC_COSTLY_ORDER) ||
gfp != GFP_KERNEL)
tbl = kzalloc(size, gfp | __GFP_NOWARN | __GFP_NORETRY);
if (tbl == NULL && gfp == GFP_KERNEL)
tbl = vzalloc(size);
if (tbl == NULL)
return NULL;
tbl->size = nbuckets;
if (alloc_bucket_locks(ht, tbl, gfp) < 0) {
bucket_table_free(tbl);
return NULL;
}
INIT_LIST_HEAD(&tbl->walkers);
get_random_bytes(&tbl->hash_rnd, sizeof(tbl->hash_rnd));
for (i = 0; i < nbuckets; i++)
INIT_RHT_NULLS_HEAD(tbl->buckets[i], ht, i);
return tbl;
}
static struct bucket_table *rhashtable_last_table(struct rhashtable *ht,
struct bucket_table *tbl)
{
struct bucket_table *new_tbl;
do {
new_tbl = tbl;
tbl = rht_dereference_rcu(tbl->future_tbl, ht);
} while (tbl);
return new_tbl;
}
static int rhashtable_rehash_one(struct rhashtable *ht, unsigned int old_hash)
{
struct bucket_table *old_tbl = rht_dereference(ht->tbl, ht);
struct bucket_table *new_tbl = rhashtable_last_table(ht,
rht_dereference_rcu(old_tbl->future_tbl, ht));
struct rhash_head __rcu **pprev = &old_tbl->buckets[old_hash];
int err = -ENOENT;
struct rhash_head *head, *next, *entry;
spinlock_t *new_bucket_lock;
unsigned int new_hash;
rht_for_each(entry, old_tbl, old_hash) {
err = 0;
next = rht_dereference_bucket(entry->next, old_tbl, old_hash);
if (rht_is_a_nulls(next))
break;
pprev = &entry->next;
}
if (err)
goto out;
new_hash = head_hashfn(ht, new_tbl, entry);
new_bucket_lock = rht_bucket_lock(new_tbl, new_hash);
spin_lock_nested(new_bucket_lock, SINGLE_DEPTH_NESTING);
head = rht_dereference_bucket(new_tbl->buckets[new_hash],
new_tbl, new_hash);
RCU_INIT_POINTER(entry->next, head);
rcu_assign_pointer(new_tbl->buckets[new_hash], entry);
spin_unlock(new_bucket_lock);
rcu_assign_pointer(*pprev, next);
out:
return err;
}
static void rhashtable_rehash_chain(struct rhashtable *ht,
unsigned int old_hash)
{
struct bucket_table *old_tbl = rht_dereference(ht->tbl, ht);
spinlock_t *old_bucket_lock;
old_bucket_lock = rht_bucket_lock(old_tbl, old_hash);
spin_lock_bh(old_bucket_lock);
while (!rhashtable_rehash_one(ht, old_hash))
;
old_tbl->rehash++;
spin_unlock_bh(old_bucket_lock);
}
static int rhashtable_rehash_attach(struct rhashtable *ht,
struct bucket_table *old_tbl,
struct bucket_table *new_tbl)
{
spin_lock_bh(old_tbl->locks);
if (rcu_access_pointer(old_tbl->future_tbl)) {
spin_unlock_bh(old_tbl->locks);
return -EEXIST;
}
rcu_assign_pointer(old_tbl->future_tbl, new_tbl);
smp_wmb();
spin_unlock_bh(old_tbl->locks);
return 0;
}
static int rhashtable_rehash_table(struct rhashtable *ht)
{
struct bucket_table *old_tbl = rht_dereference(ht->tbl, ht);
struct bucket_table *new_tbl;
struct rhashtable_walker *walker;
unsigned int old_hash;
new_tbl = rht_dereference(old_tbl->future_tbl, ht);
if (!new_tbl)
return 0;
for (old_hash = 0; old_hash < old_tbl->size; old_hash++)
rhashtable_rehash_chain(ht, old_hash);
rcu_assign_pointer(ht->tbl, new_tbl);
spin_lock(&ht->lock);
list_for_each_entry(walker, &old_tbl->walkers, list)
walker->tbl = NULL;
spin_unlock(&ht->lock);
call_rcu(&old_tbl->rcu, bucket_table_free_rcu);
return rht_dereference(new_tbl->future_tbl, ht) ? -EAGAIN : 0;
}
static int rhashtable_expand(struct rhashtable *ht)
{
struct bucket_table *new_tbl, *old_tbl = rht_dereference(ht->tbl, ht);
int err;
ASSERT_RHT_MUTEX(ht);
old_tbl = rhashtable_last_table(ht, old_tbl);
new_tbl = bucket_table_alloc(ht, old_tbl->size * 2, GFP_KERNEL);
if (new_tbl == NULL)
return -ENOMEM;
err = rhashtable_rehash_attach(ht, old_tbl, new_tbl);
if (err)
bucket_table_free(new_tbl);
return err;
}
static int rhashtable_shrink(struct rhashtable *ht)
{
struct bucket_table *new_tbl, *old_tbl = rht_dereference(ht->tbl, ht);
unsigned int size;
int err;
ASSERT_RHT_MUTEX(ht);
size = roundup_pow_of_two(atomic_read(&ht->nelems) * 3 / 2);
if (size < ht->p.min_size)
size = ht->p.min_size;
if (old_tbl->size <= size)
return 0;
if (rht_dereference(old_tbl->future_tbl, ht))
return -EEXIST;
new_tbl = bucket_table_alloc(ht, size, GFP_KERNEL);
if (new_tbl == NULL)
return -ENOMEM;
err = rhashtable_rehash_attach(ht, old_tbl, new_tbl);
if (err)
bucket_table_free(new_tbl);
return err;
}
static void rht_deferred_worker(struct work_struct *work)
{
struct rhashtable *ht;
struct bucket_table *tbl;
int err = 0;
ht = container_of(work, struct rhashtable, run_work);
mutex_lock(&ht->mutex);
tbl = rht_dereference(ht->tbl, ht);
tbl = rhashtable_last_table(ht, tbl);
if (rht_grow_above_75(ht, tbl))
rhashtable_expand(ht);
else if (ht->p.automatic_shrinking && rht_shrink_below_30(ht, tbl))
rhashtable_shrink(ht);
err = rhashtable_rehash_table(ht);
mutex_unlock(&ht->mutex);
if (err)
schedule_work(&ht->run_work);
}
static bool rhashtable_check_elasticity(struct rhashtable *ht,
struct bucket_table *tbl,
unsigned int hash)
{
unsigned int elasticity = ht->elasticity;
struct rhash_head *head;
rht_for_each(head, tbl, hash)
if (!--elasticity)
return true;
return false;
}
int rhashtable_insert_rehash(struct rhashtable *ht)
{
struct bucket_table *old_tbl;
struct bucket_table *new_tbl;
struct bucket_table *tbl;
unsigned int size;
int err;
old_tbl = rht_dereference_rcu(ht->tbl, ht);
tbl = rhashtable_last_table(ht, old_tbl);
size = tbl->size;
if (rht_grow_above_75(ht, tbl))
size *= 2;
else if (old_tbl != tbl)
return -EBUSY;
new_tbl = bucket_table_alloc(ht, size, GFP_ATOMIC);
if (new_tbl == NULL) {
schedule_work(&ht->run_work);
return -ENOMEM;
}
err = rhashtable_rehash_attach(ht, tbl, new_tbl);
if (err) {
bucket_table_free(new_tbl);
if (err == -EEXIST)
err = 0;
} else
schedule_work(&ht->run_work);
return err;
}
int rhashtable_insert_slow(struct rhashtable *ht, const void *key,
struct rhash_head *obj,
struct bucket_table *tbl)
{
struct rhash_head *head;
unsigned int hash;
int err;
tbl = rhashtable_last_table(ht, tbl);
hash = head_hashfn(ht, tbl, obj);
spin_lock_nested(rht_bucket_lock(tbl, hash), SINGLE_DEPTH_NESTING);
err = -EEXIST;
if (key && rhashtable_lookup_fast(ht, key, ht->p))
goto exit;
err = -E2BIG;
if (unlikely(rht_grow_above_max(ht, tbl)))
goto exit;
err = -EAGAIN;
if (rhashtable_check_elasticity(ht, tbl, hash) ||
rht_grow_above_100(ht, tbl))
goto exit;
err = 0;
head = rht_dereference_bucket(tbl->buckets[hash], tbl, hash);
RCU_INIT_POINTER(obj->next, head);
rcu_assign_pointer(tbl->buckets[hash], obj);
atomic_inc(&ht->nelems);
exit:
spin_unlock(rht_bucket_lock(tbl, hash));
return err;
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
mutex_lock(&ht->mutex);
iter->walker->tbl = rht_dereference(ht->tbl, ht);
list_add(&iter->walker->list, &iter->walker->tbl->walkers);
mutex_unlock(&ht->mutex);
return 0;
}
void rhashtable_walk_exit(struct rhashtable_iter *iter)
{
mutex_lock(&iter->ht->mutex);
if (iter->walker->tbl)
list_del(&iter->walker->list);
mutex_unlock(&iter->ht->mutex);
kfree(iter->walker);
}
int rhashtable_walk_start(struct rhashtable_iter *iter)
__acquires(RCU)
{
struct rhashtable *ht = iter->ht;
mutex_lock(&ht->mutex);
if (iter->walker->tbl)
list_del(&iter->walker->list);
rcu_read_lock();
mutex_unlock(&ht->mutex);
if (!iter->walker->tbl) {
iter->walker->tbl = rht_dereference_rcu(ht->tbl, ht);
return -EAGAIN;
}
return 0;
}
void *rhashtable_walk_next(struct rhashtable_iter *iter)
{
struct bucket_table *tbl = iter->walker->tbl;
struct rhashtable *ht = iter->ht;
struct rhash_head *p = iter->p;
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
return rht_obj(ht, p);
}
iter->skip = 0;
}
iter->p = NULL;
smp_rmb();
iter->walker->tbl = rht_dereference_rcu(tbl->future_tbl, ht);
if (iter->walker->tbl) {
iter->slot = 0;
iter->skip = 0;
return ERR_PTR(-EAGAIN);
}
return NULL;
}
void rhashtable_walk_stop(struct rhashtable_iter *iter)
__releases(RCU)
{
struct rhashtable *ht;
struct bucket_table *tbl = iter->walker->tbl;
if (!tbl)
goto out;
ht = iter->ht;
spin_lock(&ht->lock);
if (tbl->rehash < tbl->size)
list_add(&iter->walker->list, &tbl->walkers);
else
iter->walker->tbl = NULL;
spin_unlock(&ht->lock);
iter->p = NULL;
out:
rcu_read_unlock();
}
static size_t rounded_hashtable_size(const struct rhashtable_params *params)
{
return max(roundup_pow_of_two(params->nelem_hint * 4 / 3),
(unsigned long)params->min_size);
}
static u32 rhashtable_jhash2(const void *key, u32 length, u32 seed)
{
return jhash2(key, length, seed);
}
int rhashtable_init(struct rhashtable *ht,
const struct rhashtable_params *params)
{
struct bucket_table *tbl;
size_t size;
size = HASH_DEFAULT_SIZE;
if ((!params->key_len && !params->obj_hashfn) ||
(params->obj_hashfn && !params->obj_cmpfn))
return -EINVAL;
if (params->nulls_base && params->nulls_base < (1U << RHT_BASE_SHIFT))
return -EINVAL;
if (params->nelem_hint)
size = rounded_hashtable_size(params);
memset(ht, 0, sizeof(*ht));
mutex_init(&ht->mutex);
spin_lock_init(&ht->lock);
memcpy(&ht->p, params, sizeof(*params));
if (params->min_size)
ht->p.min_size = roundup_pow_of_two(params->min_size);
if (params->max_size)
ht->p.max_size = rounddown_pow_of_two(params->max_size);
if (params->insecure_max_entries)
ht->p.insecure_max_entries =
rounddown_pow_of_two(params->insecure_max_entries);
else
ht->p.insecure_max_entries = ht->p.max_size * 2;
ht->p.min_size = max(ht->p.min_size, HASH_MIN_SIZE);
if (!params->insecure_elasticity)
ht->elasticity = 16;
if (params->locks_mul)
ht->p.locks_mul = roundup_pow_of_two(params->locks_mul);
else
ht->p.locks_mul = BUCKET_LOCKS_PER_CPU;
ht->key_len = ht->p.key_len;
if (!params->hashfn) {
ht->p.hashfn = jhash;
if (!(ht->key_len & (sizeof(u32) - 1))) {
ht->key_len /= sizeof(u32);
ht->p.hashfn = rhashtable_jhash2;
}
}
tbl = bucket_table_alloc(ht, size, GFP_KERNEL);
if (tbl == NULL)
return -ENOMEM;
atomic_set(&ht->nelems, 0);
RCU_INIT_POINTER(ht->tbl, tbl);
INIT_WORK(&ht->run_work, rht_deferred_worker);
return 0;
}
void rhashtable_free_and_destroy(struct rhashtable *ht,
void (*free_fn)(void *ptr, void *arg),
void *arg)
{
const struct bucket_table *tbl;
unsigned int i;
cancel_work_sync(&ht->run_work);
mutex_lock(&ht->mutex);
tbl = rht_dereference(ht->tbl, ht);
if (free_fn) {
for (i = 0; i < tbl->size; i++) {
struct rhash_head *pos, *next;
for (pos = rht_dereference(tbl->buckets[i], ht),
next = !rht_is_a_nulls(pos) ?
rht_dereference(pos->next, ht) : NULL;
!rht_is_a_nulls(pos);
pos = next,
next = !rht_is_a_nulls(pos) ?
rht_dereference(pos->next, ht) : NULL)
free_fn(rht_obj(ht, pos), arg);
}
}
bucket_table_free(tbl);
mutex_unlock(&ht->mutex);
}
void rhashtable_destroy(struct rhashtable *ht)
{
return rhashtable_free_and_destroy(ht, NULL, NULL);
}
