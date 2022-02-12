int lockdep_rht_mutex_is_held(const struct rhashtable *ht)
{
return ht->p.mutex_is_held(ht->p.parent);
}
static void *rht_obj(const struct rhashtable *ht, const struct rhash_head *he)
{
return (void *) he - ht->p.head_offset;
}
static u32 __hashfn(const struct rhashtable *ht, const void *key,
u32 len, u32 hsize)
{
u32 h;
h = ht->p.hashfn(key, len, ht->p.hash_rnd);
return h & (hsize - 1);
}
u32 rhashtable_hashfn(const struct rhashtable *ht, const void *key, u32 len)
{
struct bucket_table *tbl = rht_dereference_rcu(ht->tbl, ht);
return __hashfn(ht, key, len, tbl->size);
}
static u32 obj_hashfn(const struct rhashtable *ht, const void *ptr, u32 hsize)
{
if (unlikely(!ht->p.key_len)) {
u32 h;
h = ht->p.obj_hashfn(ptr, ht->p.hash_rnd);
return h & (hsize - 1);
}
return __hashfn(ht, ptr + ht->p.key_offset, ht->p.key_len, hsize);
}
u32 rhashtable_obj_hashfn(const struct rhashtable *ht, void *ptr)
{
struct bucket_table *tbl = rht_dereference_rcu(ht->tbl, ht);
return obj_hashfn(ht, ptr, tbl->size);
}
static u32 head_hashfn(const struct rhashtable *ht,
const struct rhash_head *he, u32 hsize)
{
return obj_hashfn(ht, rht_obj(ht, he), hsize);
}
static struct bucket_table *bucket_table_alloc(size_t nbuckets)
{
struct bucket_table *tbl;
size_t size;
size = sizeof(*tbl) + nbuckets * sizeof(tbl->buckets[0]);
tbl = kzalloc(size, GFP_KERNEL | __GFP_NOWARN);
if (tbl == NULL)
tbl = vzalloc(size);
if (tbl == NULL)
return NULL;
tbl->size = nbuckets;
return tbl;
}
static void bucket_table_free(const struct bucket_table *tbl)
{
kvfree(tbl);
}
bool rht_grow_above_75(const struct rhashtable *ht, size_t new_size)
{
return ht->nelems > (new_size / 4 * 3);
}
bool rht_shrink_below_30(const struct rhashtable *ht, size_t new_size)
{
return ht->nelems < (new_size * 3 / 10);
}
static void hashtable_chain_unzip(const struct rhashtable *ht,
const struct bucket_table *new_tbl,
struct bucket_table *old_tbl, size_t n)
{
struct rhash_head *he, *p, *next;
unsigned int h;
p = rht_dereference(old_tbl->buckets[n], ht);
if (!p)
return;
h = head_hashfn(ht, p, new_tbl->size);
rht_for_each(he, p->next, ht) {
if (head_hashfn(ht, he, new_tbl->size) != h)
break;
p = he;
}
RCU_INIT_POINTER(old_tbl->buckets[n], p->next);
next = NULL;
if (he) {
rht_for_each(he, he->next, ht) {
if (head_hashfn(ht, he, new_tbl->size) == h) {
next = he;
break;
}
}
}
RCU_INIT_POINTER(p->next, next);
}
int rhashtable_expand(struct rhashtable *ht)
{
struct bucket_table *new_tbl, *old_tbl = rht_dereference(ht->tbl, ht);
struct rhash_head *he;
unsigned int i, h;
bool complete;
ASSERT_RHT_MUTEX(ht);
if (ht->p.max_shift && ht->shift >= ht->p.max_shift)
return 0;
new_tbl = bucket_table_alloc(old_tbl->size * 2);
if (new_tbl == NULL)
return -ENOMEM;
ht->shift++;
for (i = 0; i < new_tbl->size; i++) {
h = i & (old_tbl->size - 1);
rht_for_each(he, old_tbl->buckets[h], ht) {
if (head_hashfn(ht, he, new_tbl->size) == i) {
RCU_INIT_POINTER(new_tbl->buckets[i], he);
break;
}
}
}
rcu_assign_pointer(ht->tbl, new_tbl);
do {
synchronize_rcu();
complete = true;
for (i = 0; i < old_tbl->size; i++) {
hashtable_chain_unzip(ht, new_tbl, old_tbl, i);
if (old_tbl->buckets[i] != NULL)
complete = false;
}
} while (!complete);
bucket_table_free(old_tbl);
return 0;
}
int rhashtable_shrink(struct rhashtable *ht)
{
struct bucket_table *ntbl, *tbl = rht_dereference(ht->tbl, ht);
struct rhash_head __rcu **pprev;
unsigned int i;
ASSERT_RHT_MUTEX(ht);
if (ht->shift <= ht->p.min_shift)
return 0;
ntbl = bucket_table_alloc(tbl->size / 2);
if (ntbl == NULL)
return -ENOMEM;
ht->shift--;
for (i = 0; i < ntbl->size; i++) {
ntbl->buckets[i] = tbl->buckets[i];
for (pprev = &ntbl->buckets[i]; *pprev != NULL;
pprev = &rht_dereference(*pprev, ht)->next)
;
RCU_INIT_POINTER(*pprev, tbl->buckets[i + ntbl->size]);
}
rcu_assign_pointer(ht->tbl, ntbl);
synchronize_rcu();
bucket_table_free(tbl);
return 0;
}
void rhashtable_insert(struct rhashtable *ht, struct rhash_head *obj)
{
struct bucket_table *tbl = rht_dereference(ht->tbl, ht);
u32 hash;
ASSERT_RHT_MUTEX(ht);
hash = head_hashfn(ht, obj, tbl->size);
RCU_INIT_POINTER(obj->next, tbl->buckets[hash]);
rcu_assign_pointer(tbl->buckets[hash], obj);
ht->nelems++;
if (ht->p.grow_decision && ht->p.grow_decision(ht, tbl->size))
rhashtable_expand(ht);
}
void rhashtable_remove_pprev(struct rhashtable *ht, struct rhash_head *obj,
struct rhash_head __rcu **pprev)
{
struct bucket_table *tbl = rht_dereference(ht->tbl, ht);
ASSERT_RHT_MUTEX(ht);
RCU_INIT_POINTER(*pprev, obj->next);
ht->nelems--;
if (ht->p.shrink_decision &&
ht->p.shrink_decision(ht, tbl->size))
rhashtable_shrink(ht);
}
bool rhashtable_remove(struct rhashtable *ht, struct rhash_head *obj)
{
struct bucket_table *tbl = rht_dereference(ht->tbl, ht);
struct rhash_head __rcu **pprev;
struct rhash_head *he;
u32 h;
ASSERT_RHT_MUTEX(ht);
h = head_hashfn(ht, obj, tbl->size);
pprev = &tbl->buckets[h];
rht_for_each(he, tbl->buckets[h], ht) {
if (he != obj) {
pprev = &he->next;
continue;
}
rhashtable_remove_pprev(ht, he, pprev);
return true;
}
return false;
}
void *rhashtable_lookup(const struct rhashtable *ht, const void *key)
{
const struct bucket_table *tbl = rht_dereference_rcu(ht->tbl, ht);
struct rhash_head *he;
u32 h;
BUG_ON(!ht->p.key_len);
h = __hashfn(ht, key, ht->p.key_len, tbl->size);
rht_for_each_rcu(he, tbl->buckets[h], ht) {
if (memcmp(rht_obj(ht, he) + ht->p.key_offset, key,
ht->p.key_len))
continue;
return (void *) he - ht->p.head_offset;
}
return NULL;
}
void *rhashtable_lookup_compare(const struct rhashtable *ht, u32 hash,
bool (*compare)(void *, void *), void *arg)
{
const struct bucket_table *tbl = rht_dereference_rcu(ht->tbl, ht);
struct rhash_head *he;
if (unlikely(hash >= tbl->size))
return NULL;
rht_for_each_rcu(he, tbl->buckets[hash], ht) {
if (!compare(rht_obj(ht, he), arg))
continue;
return (void *) he - ht->p.head_offset;
}
return NULL;
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
params->min_shift = max_t(size_t, params->min_shift,
ilog2(HASH_MIN_SIZE));
if (params->nelem_hint)
size = rounded_hashtable_size(params);
tbl = bucket_table_alloc(size);
if (tbl == NULL)
return -ENOMEM;
memset(ht, 0, sizeof(*ht));
ht->shift = ilog2(tbl->size);
memcpy(&ht->p, params, sizeof(*params));
RCU_INIT_POINTER(ht->tbl, tbl);
if (!ht->p.hash_rnd)
get_random_bytes(&ht->p.hash_rnd, sizeof(ht->p.hash_rnd));
return 0;
}
void rhashtable_destroy(const struct rhashtable *ht)
{
bucket_table_free(ht->tbl);
}
static int test_mutex_is_held(void *parent)
{
return 1;
}
static int __init test_rht_lookup(struct rhashtable *ht)
{
unsigned int i;
for (i = 0; i < TEST_ENTRIES * 2; i++) {
struct test_obj *obj;
bool expected = !(i % 2);
u32 key = i;
obj = rhashtable_lookup(ht, &key);
if (expected && !obj) {
pr_warn("Test failed: Could not find key %u\n", key);
return -ENOENT;
} else if (!expected && obj) {
pr_warn("Test failed: Unexpected entry found for key %u\n",
key);
return -EEXIST;
} else if (expected && obj) {
if (obj->ptr != TEST_PTR || obj->value != i) {
pr_warn("Test failed: Lookup value mismatch %p!=%p, %u!=%u\n",
obj->ptr, TEST_PTR, obj->value, i);
return -EINVAL;
}
}
}
return 0;
}
static void test_bucket_stats(struct rhashtable *ht, bool quiet)
{
unsigned int cnt, rcu_cnt, i, total = 0;
struct test_obj *obj;
struct bucket_table *tbl;
tbl = rht_dereference_rcu(ht->tbl, ht);
for (i = 0; i < tbl->size; i++) {
rcu_cnt = cnt = 0;
if (!quiet)
pr_info(" [%#4x/%zu]", i, tbl->size);
rht_for_each_entry_rcu(obj, tbl->buckets[i], node) {
cnt++;
total++;
if (!quiet)
pr_cont(" [%p],", obj);
}
rht_for_each_entry_rcu(obj, tbl->buckets[i], node)
rcu_cnt++;
if (rcu_cnt != cnt)
pr_warn("Test failed: Chain count mismach %d != %d",
cnt, rcu_cnt);
if (!quiet)
pr_cont("\n [%#x] first element: %p, chain length: %u\n",
i, tbl->buckets[i], cnt);
}
pr_info(" Traversal complete: counted=%u, nelems=%zu, entries=%d\n",
total, ht->nelems, TEST_ENTRIES);
if (total != ht->nelems || total != TEST_ENTRIES)
pr_warn("Test failed: Total count mismatch ^^^");
}
static int __init test_rhashtable(struct rhashtable *ht)
{
struct bucket_table *tbl;
struct test_obj *obj, *next;
int err;
unsigned int i;
pr_info(" Adding %d keys\n", TEST_ENTRIES);
for (i = 0; i < TEST_ENTRIES; i++) {
struct test_obj *obj;
obj = kzalloc(sizeof(*obj), GFP_KERNEL);
if (!obj) {
err = -ENOMEM;
goto error;
}
obj->ptr = TEST_PTR;
obj->value = i * 2;
rhashtable_insert(ht, &obj->node);
}
rcu_read_lock();
test_bucket_stats(ht, true);
test_rht_lookup(ht);
rcu_read_unlock();
for (i = 0; i < TEST_NEXPANDS; i++) {
pr_info(" Table expansion iteration %u...\n", i);
rhashtable_expand(ht);
rcu_read_lock();
pr_info(" Verifying lookups...\n");
test_rht_lookup(ht);
rcu_read_unlock();
}
for (i = 0; i < TEST_NEXPANDS; i++) {
pr_info(" Table shrinkage iteration %u...\n", i);
rhashtable_shrink(ht);
rcu_read_lock();
pr_info(" Verifying lookups...\n");
test_rht_lookup(ht);
rcu_read_unlock();
}
rcu_read_lock();
test_bucket_stats(ht, true);
rcu_read_unlock();
pr_info(" Deleting %d keys\n", TEST_ENTRIES);
for (i = 0; i < TEST_ENTRIES; i++) {
u32 key = i * 2;
obj = rhashtable_lookup(ht, &key);
BUG_ON(!obj);
rhashtable_remove(ht, &obj->node);
kfree(obj);
}
return 0;
error:
tbl = rht_dereference_rcu(ht->tbl, ht);
for (i = 0; i < tbl->size; i++)
rht_for_each_entry_safe(obj, next, tbl->buckets[i], ht, node)
kfree(obj);
return err;
}
static int __init test_rht_init(void)
{
struct rhashtable ht;
struct rhashtable_params params = {
.nelem_hint = TEST_HT_SIZE,
.head_offset = offsetof(struct test_obj, node),
.key_offset = offsetof(struct test_obj, value),
.key_len = sizeof(int),
.hashfn = jhash,
#ifdef CONFIG_PROVE_LOCKING
.mutex_is_held = &test_mutex_is_held,
#endif
.grow_decision = rht_grow_above_75,
.shrink_decision = rht_shrink_below_30,
};
int err;
pr_info("Running resizable hashtable tests...\n");
err = rhashtable_init(&ht, &params);
if (err < 0) {
pr_warn("Test failed: Unable to initialize hashtable: %d\n",
err);
return err;
}
err = test_rhashtable(&ht);
rhashtable_destroy(&ht);
return err;
}
