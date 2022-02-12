static unsigned next_power(unsigned n, unsigned min)
{
return roundup_pow_of_two(max(n, min));
}
static unsigned long *alloc_bitset(unsigned nr_entries)
{
size_t s = sizeof(unsigned long) * dm_div_up(nr_entries, BITS_PER_LONG);
return vzalloc(s);
}
static void free_bitset(unsigned long *bits)
{
vfree(bits);
}
static void iot_init(struct io_tracker *t,
int sequential_threshold, int random_threshold)
{
t->pattern = PATTERN_RANDOM;
t->nr_seq_samples = 0;
t->nr_rand_samples = 0;
t->last_end_oblock = 0;
t->thresholds[PATTERN_RANDOM] = random_threshold;
t->thresholds[PATTERN_SEQUENTIAL] = sequential_threshold;
}
static enum io_pattern iot_pattern(struct io_tracker *t)
{
return t->pattern;
}
static void iot_update_stats(struct io_tracker *t, struct bio *bio)
{
if (bio->bi_sector == from_oblock(t->last_end_oblock) + 1)
t->nr_seq_samples++;
else {
if (t->nr_seq_samples) {
t->nr_seq_samples = 0;
t->nr_rand_samples = 0;
}
t->nr_rand_samples++;
}
t->last_end_oblock = to_oblock(bio->bi_sector + bio_sectors(bio) - 1);
}
static void iot_check_for_pattern_switch(struct io_tracker *t)
{
switch (t->pattern) {
case PATTERN_SEQUENTIAL:
if (t->nr_rand_samples >= t->thresholds[PATTERN_RANDOM]) {
t->pattern = PATTERN_RANDOM;
t->nr_seq_samples = t->nr_rand_samples = 0;
}
break;
case PATTERN_RANDOM:
if (t->nr_seq_samples >= t->thresholds[PATTERN_SEQUENTIAL]) {
t->pattern = PATTERN_SEQUENTIAL;
t->nr_seq_samples = t->nr_rand_samples = 0;
}
break;
}
}
static void iot_examine_bio(struct io_tracker *t, struct bio *bio)
{
iot_update_stats(t, bio);
iot_check_for_pattern_switch(t);
}
static void queue_init(struct queue *q)
{
unsigned i;
for (i = 0; i < NR_QUEUE_LEVELS; i++)
INIT_LIST_HEAD(q->qs + i);
}
static void queue_push(struct queue *q, unsigned level, struct list_head *elt)
{
list_add_tail(elt, q->qs + level);
}
static void queue_remove(struct list_head *elt)
{
list_del(elt);
}
static void queue_shift_down(struct queue *q)
{
unsigned level;
for (level = 1; level < NR_QUEUE_LEVELS; level++)
list_splice_init(q->qs + level, q->qs + level - 1);
}
static struct list_head *queue_pop(struct queue *q)
{
unsigned level;
struct list_head *r;
for (level = 0; level < NR_QUEUE_LEVELS; level++)
if (!list_empty(q->qs + level)) {
r = q->qs[level].next;
list_del(r);
if (level == 0 && list_empty(q->qs))
queue_shift_down(q);
return r;
}
return NULL;
}
static struct list_head *list_pop(struct list_head *lh)
{
struct list_head *r = lh->next;
BUG_ON(!r);
list_del_init(r);
return r;
}
static void takeout_queue(struct list_head *lh, struct queue *q)
{
unsigned level;
for (level = 0; level < NR_QUEUE_LEVELS; level++)
list_splice(q->qs + level, lh);
}
static void free_entries(struct mq_policy *mq)
{
struct entry *e, *tmp;
takeout_queue(&mq->free, &mq->pre_cache);
takeout_queue(&mq->free, &mq->cache);
list_for_each_entry_safe(e, tmp, &mq->free, list)
kmem_cache_free(mq_entry_cache, e);
}
static int alloc_entries(struct mq_policy *mq, unsigned elts)
{
unsigned u = mq->nr_entries;
INIT_LIST_HEAD(&mq->free);
mq->nr_entries_allocated = 0;
while (u--) {
struct entry *e = kmem_cache_zalloc(mq_entry_cache, GFP_KERNEL);
if (!e) {
free_entries(mq);
return -ENOMEM;
}
list_add(&e->list, &mq->free);
}
return 0;
}
static void hash_insert(struct mq_policy *mq, struct entry *e)
{
unsigned h = hash_64(from_oblock(e->oblock), mq->hash_bits);
hlist_add_head(&e->hlist, mq->table + h);
}
static struct entry *hash_lookup(struct mq_policy *mq, dm_oblock_t oblock)
{
unsigned h = hash_64(from_oblock(oblock), mq->hash_bits);
struct hlist_head *bucket = mq->table + h;
struct entry *e;
hlist_for_each_entry(e, bucket, hlist)
if (e->oblock == oblock) {
hlist_del(&e->hlist);
hlist_add_head(&e->hlist, bucket);
return e;
}
return NULL;
}
static void hash_remove(struct entry *e)
{
hlist_del(&e->hlist);
}
static struct entry *alloc_entry(struct mq_policy *mq)
{
struct entry *e;
if (mq->nr_entries_allocated >= mq->nr_entries) {
BUG_ON(!list_empty(&mq->free));
return NULL;
}
e = list_entry(list_pop(&mq->free), struct entry, list);
INIT_LIST_HEAD(&e->list);
INIT_HLIST_NODE(&e->hlist);
mq->nr_entries_allocated++;
return e;
}
static void alloc_cblock(struct mq_policy *mq, dm_cblock_t cblock)
{
BUG_ON(from_cblock(cblock) > from_cblock(mq->cache_size));
BUG_ON(test_bit(from_cblock(cblock), mq->allocation_bitset));
set_bit(from_cblock(cblock), mq->allocation_bitset);
mq->nr_cblocks_allocated++;
}
static void free_cblock(struct mq_policy *mq, dm_cblock_t cblock)
{
BUG_ON(from_cblock(cblock) > from_cblock(mq->cache_size));
BUG_ON(!test_bit(from_cblock(cblock), mq->allocation_bitset));
clear_bit(from_cblock(cblock), mq->allocation_bitset);
mq->nr_cblocks_allocated--;
}
static bool any_free_cblocks(struct mq_policy *mq)
{
return mq->nr_cblocks_allocated < from_cblock(mq->cache_size);
}
static int __find_free_cblock(struct mq_policy *mq, unsigned begin, unsigned end,
dm_cblock_t *result, unsigned *last_word)
{
int r = -ENOSPC;
unsigned w;
for (w = begin; w < end; w++) {
if (mq->allocation_bitset[w] != ~0UL) {
*last_word = w;
*result = to_cblock((w * BITS_PER_LONG) + ffz(mq->allocation_bitset[w]));
if (from_cblock(*result) < from_cblock(mq->cache_size))
r = 0;
break;
}
}
return r;
}
static int find_free_cblock(struct mq_policy *mq, dm_cblock_t *result)
{
int r;
if (!any_free_cblocks(mq))
return -ENOSPC;
r = __find_free_cblock(mq, mq->find_free_last_word, mq->find_free_nr_words, result, &mq->find_free_last_word);
if (r == -ENOSPC && mq->find_free_last_word)
r = __find_free_cblock(mq, 0, mq->find_free_last_word, result, &mq->find_free_last_word);
return r;
}
static unsigned queue_level(struct entry *e)
{
return min((unsigned) ilog2(e->hit_count), NR_QUEUE_LEVELS - 1u);
}
static void push(struct mq_policy *mq, struct entry *e)
{
e->tick = mq->tick;
hash_insert(mq, e);
if (e->in_cache) {
alloc_cblock(mq, e->cblock);
queue_push(&mq->cache, queue_level(e), &e->list);
} else
queue_push(&mq->pre_cache, queue_level(e), &e->list);
}
static void del(struct mq_policy *mq, struct entry *e)
{
queue_remove(&e->list);
hash_remove(e);
if (e->in_cache)
free_cblock(mq, e->cblock);
}
static struct entry *pop(struct mq_policy *mq, struct queue *q)
{
struct entry *e = container_of(queue_pop(q), struct entry, list);
if (e) {
hash_remove(e);
if (e->in_cache)
free_cblock(mq, e->cblock);
}
return e;
}
static bool updated_this_tick(struct mq_policy *mq, struct entry *e)
{
return mq->tick == e->tick;
}
static void check_generation(struct mq_policy *mq)
{
unsigned total = 0, nr = 0, count = 0, level;
struct list_head *head;
struct entry *e;
if ((mq->hit_count >= mq->generation_period) &&
(mq->nr_cblocks_allocated == from_cblock(mq->cache_size))) {
mq->hit_count = 0;
mq->generation++;
for (level = 0; level < NR_QUEUE_LEVELS && count < MAX_TO_AVERAGE; level++) {
head = mq->cache.qs + level;
list_for_each_entry(e, head, list) {
nr++;
total += e->hit_count;
if (++count >= MAX_TO_AVERAGE)
break;
}
}
mq->promote_threshold = nr ? total / nr : 1;
if (mq->promote_threshold * nr < total)
mq->promote_threshold++;
}
}
static void requeue_and_update_tick(struct mq_policy *mq, struct entry *e)
{
if (updated_this_tick(mq, e))
return;
e->hit_count++;
mq->hit_count++;
check_generation(mq);
e->generation = mq->generation;
del(mq, e);
push(mq, e);
}
static dm_cblock_t demote_cblock(struct mq_policy *mq, dm_oblock_t *oblock)
{
dm_cblock_t result;
struct entry *demoted = pop(mq, &mq->cache);
BUG_ON(!demoted);
result = demoted->cblock;
*oblock = demoted->oblock;
demoted->in_cache = false;
demoted->hit_count = 1;
push(mq, demoted);
return result;
}
static unsigned adjusted_promote_threshold(struct mq_policy *mq,
bool discarded_oblock, int data_dir)
{
if (discarded_oblock && any_free_cblocks(mq) && data_dir == WRITE)
return DISCARDED_PROMOTE_THRESHOLD;
return data_dir == READ ?
(mq->promote_threshold + READ_PROMOTE_THRESHOLD) :
(mq->promote_threshold + WRITE_PROMOTE_THRESHOLD);
}
static bool should_promote(struct mq_policy *mq, struct entry *e,
bool discarded_oblock, int data_dir)
{
return e->hit_count >=
adjusted_promote_threshold(mq, discarded_oblock, data_dir);
}
static int cache_entry_found(struct mq_policy *mq,
struct entry *e,
struct policy_result *result)
{
requeue_and_update_tick(mq, e);
if (e->in_cache) {
result->op = POLICY_HIT;
result->cblock = e->cblock;
}
return 0;
}
static int pre_cache_to_cache(struct mq_policy *mq, struct entry *e,
struct policy_result *result)
{
dm_cblock_t cblock;
if (find_free_cblock(mq, &cblock) == -ENOSPC) {
result->op = POLICY_REPLACE;
cblock = demote_cblock(mq, &result->old_oblock);
} else
result->op = POLICY_NEW;
result->cblock = e->cblock = cblock;
del(mq, e);
e->in_cache = true;
push(mq, e);
return 0;
}
static int pre_cache_entry_found(struct mq_policy *mq, struct entry *e,
bool can_migrate, bool discarded_oblock,
int data_dir, struct policy_result *result)
{
int r = 0;
bool updated = updated_this_tick(mq, e);
requeue_and_update_tick(mq, e);
if ((!discarded_oblock && updated) ||
!should_promote(mq, e, discarded_oblock, data_dir))
result->op = POLICY_MISS;
else if (!can_migrate)
r = -EWOULDBLOCK;
else
r = pre_cache_to_cache(mq, e, result);
return r;
}
static void insert_in_pre_cache(struct mq_policy *mq,
dm_oblock_t oblock)
{
struct entry *e = alloc_entry(mq);
if (!e)
e = pop(mq, &mq->pre_cache);
if (unlikely(!e)) {
DMWARN("couldn't pop from pre cache");
return;
}
e->in_cache = false;
e->oblock = oblock;
e->hit_count = 1;
e->generation = mq->generation;
push(mq, e);
}
static void insert_in_cache(struct mq_policy *mq, dm_oblock_t oblock,
struct policy_result *result)
{
struct entry *e;
dm_cblock_t cblock;
if (find_free_cblock(mq, &cblock) == -ENOSPC) {
result->op = POLICY_MISS;
insert_in_pre_cache(mq, oblock);
return;
}
e = alloc_entry(mq);
if (unlikely(!e)) {
result->op = POLICY_MISS;
return;
}
e->oblock = oblock;
e->cblock = cblock;
e->in_cache = true;
e->hit_count = 1;
e->generation = mq->generation;
push(mq, e);
result->op = POLICY_NEW;
result->cblock = e->cblock;
}
static int no_entry_found(struct mq_policy *mq, dm_oblock_t oblock,
bool can_migrate, bool discarded_oblock,
int data_dir, struct policy_result *result)
{
if (adjusted_promote_threshold(mq, discarded_oblock, data_dir) == 1) {
if (can_migrate)
insert_in_cache(mq, oblock, result);
else
return -EWOULDBLOCK;
} else {
insert_in_pre_cache(mq, oblock);
result->op = POLICY_MISS;
}
return 0;
}
static int map(struct mq_policy *mq, dm_oblock_t oblock,
bool can_migrate, bool discarded_oblock,
int data_dir, struct policy_result *result)
{
int r = 0;
struct entry *e = hash_lookup(mq, oblock);
if (e && e->in_cache)
r = cache_entry_found(mq, e, result);
else if (iot_pattern(&mq->tracker) == PATTERN_SEQUENTIAL)
result->op = POLICY_MISS;
else if (e)
r = pre_cache_entry_found(mq, e, can_migrate, discarded_oblock,
data_dir, result);
else
r = no_entry_found(mq, oblock, can_migrate, discarded_oblock,
data_dir, result);
if (r == -EWOULDBLOCK)
result->op = POLICY_MISS;
return r;
}
static struct mq_policy *to_mq_policy(struct dm_cache_policy *p)
{
return container_of(p, struct mq_policy, policy);
}
static void mq_destroy(struct dm_cache_policy *p)
{
struct mq_policy *mq = to_mq_policy(p);
free_bitset(mq->allocation_bitset);
kfree(mq->table);
free_entries(mq);
kfree(mq);
}
static void copy_tick(struct mq_policy *mq)
{
unsigned long flags;
spin_lock_irqsave(&mq->tick_lock, flags);
mq->tick = mq->tick_protected;
spin_unlock_irqrestore(&mq->tick_lock, flags);
}
static int mq_map(struct dm_cache_policy *p, dm_oblock_t oblock,
bool can_block, bool can_migrate, bool discarded_oblock,
struct bio *bio, struct policy_result *result)
{
int r;
struct mq_policy *mq = to_mq_policy(p);
result->op = POLICY_MISS;
if (can_block)
mutex_lock(&mq->lock);
else if (!mutex_trylock(&mq->lock))
return -EWOULDBLOCK;
copy_tick(mq);
iot_examine_bio(&mq->tracker, bio);
r = map(mq, oblock, can_migrate, discarded_oblock,
bio_data_dir(bio), result);
mutex_unlock(&mq->lock);
return r;
}
static int mq_lookup(struct dm_cache_policy *p, dm_oblock_t oblock, dm_cblock_t *cblock)
{
int r;
struct mq_policy *mq = to_mq_policy(p);
struct entry *e;
if (!mutex_trylock(&mq->lock))
return -EWOULDBLOCK;
e = hash_lookup(mq, oblock);
if (e && e->in_cache) {
*cblock = e->cblock;
r = 0;
} else
r = -ENOENT;
mutex_unlock(&mq->lock);
return r;
}
static int mq_load_mapping(struct dm_cache_policy *p,
dm_oblock_t oblock, dm_cblock_t cblock,
uint32_t hint, bool hint_valid)
{
struct mq_policy *mq = to_mq_policy(p);
struct entry *e;
e = alloc_entry(mq);
if (!e)
return -ENOMEM;
e->cblock = cblock;
e->oblock = oblock;
e->in_cache = true;
e->hit_count = hint_valid ? hint : 1;
e->generation = mq->generation;
push(mq, e);
return 0;
}
static int mq_walk_mappings(struct dm_cache_policy *p, policy_walk_fn fn,
void *context)
{
struct mq_policy *mq = to_mq_policy(p);
int r = 0;
struct entry *e;
unsigned level;
mutex_lock(&mq->lock);
for (level = 0; level < NR_QUEUE_LEVELS; level++)
list_for_each_entry(e, &mq->cache.qs[level], list) {
r = fn(context, e->cblock, e->oblock, e->hit_count);
if (r)
goto out;
}
out:
mutex_unlock(&mq->lock);
return r;
}
static void mq_remove_mapping(struct dm_cache_policy *p, dm_oblock_t oblock)
{
struct mq_policy *mq = to_mq_policy(p);
struct entry *e;
mutex_lock(&mq->lock);
e = hash_lookup(mq, oblock);
BUG_ON(!e || !e->in_cache);
del(mq, e);
e->in_cache = false;
push(mq, e);
mutex_unlock(&mq->lock);
}
static void force_mapping(struct mq_policy *mq,
dm_oblock_t current_oblock, dm_oblock_t new_oblock)
{
struct entry *e = hash_lookup(mq, current_oblock);
BUG_ON(!e || !e->in_cache);
del(mq, e);
e->oblock = new_oblock;
push(mq, e);
}
static void mq_force_mapping(struct dm_cache_policy *p,
dm_oblock_t current_oblock, dm_oblock_t new_oblock)
{
struct mq_policy *mq = to_mq_policy(p);
mutex_lock(&mq->lock);
force_mapping(mq, current_oblock, new_oblock);
mutex_unlock(&mq->lock);
}
static dm_cblock_t mq_residency(struct dm_cache_policy *p)
{
struct mq_policy *mq = to_mq_policy(p);
return to_cblock(mq->nr_cblocks_allocated);
}
static void mq_tick(struct dm_cache_policy *p)
{
struct mq_policy *mq = to_mq_policy(p);
unsigned long flags;
spin_lock_irqsave(&mq->tick_lock, flags);
mq->tick_protected++;
spin_unlock_irqrestore(&mq->tick_lock, flags);
}
static int mq_set_config_value(struct dm_cache_policy *p,
const char *key, const char *value)
{
struct mq_policy *mq = to_mq_policy(p);
enum io_pattern pattern;
unsigned long tmp;
if (!strcasecmp(key, "random_threshold"))
pattern = PATTERN_RANDOM;
else if (!strcasecmp(key, "sequential_threshold"))
pattern = PATTERN_SEQUENTIAL;
else
return -EINVAL;
if (kstrtoul(value, 10, &tmp))
return -EINVAL;
mq->tracker.thresholds[pattern] = tmp;
return 0;
}
static int mq_emit_config_values(struct dm_cache_policy *p, char *result, unsigned maxlen)
{
ssize_t sz = 0;
struct mq_policy *mq = to_mq_policy(p);
DMEMIT("4 random_threshold %u sequential_threshold %u",
mq->tracker.thresholds[PATTERN_RANDOM],
mq->tracker.thresholds[PATTERN_SEQUENTIAL]);
return 0;
}
static void init_policy_functions(struct mq_policy *mq)
{
mq->policy.destroy = mq_destroy;
mq->policy.map = mq_map;
mq->policy.lookup = mq_lookup;
mq->policy.load_mapping = mq_load_mapping;
mq->policy.walk_mappings = mq_walk_mappings;
mq->policy.remove_mapping = mq_remove_mapping;
mq->policy.writeback_work = NULL;
mq->policy.force_mapping = mq_force_mapping;
mq->policy.residency = mq_residency;
mq->policy.tick = mq_tick;
mq->policy.emit_config_values = mq_emit_config_values;
mq->policy.set_config_value = mq_set_config_value;
}
static struct dm_cache_policy *mq_create(dm_cblock_t cache_size,
sector_t origin_size,
sector_t cache_block_size)
{
int r;
struct mq_policy *mq = kzalloc(sizeof(*mq), GFP_KERNEL);
if (!mq)
return NULL;
init_policy_functions(mq);
iot_init(&mq->tracker, SEQUENTIAL_THRESHOLD_DEFAULT, RANDOM_THRESHOLD_DEFAULT);
mq->cache_size = cache_size;
mq->tick_protected = 0;
mq->tick = 0;
mq->hit_count = 0;
mq->generation = 0;
mq->promote_threshold = 0;
mutex_init(&mq->lock);
spin_lock_init(&mq->tick_lock);
mq->find_free_nr_words = dm_div_up(from_cblock(mq->cache_size), BITS_PER_LONG);
mq->find_free_last_word = 0;
queue_init(&mq->pre_cache);
queue_init(&mq->cache);
mq->generation_period = max((unsigned) from_cblock(cache_size), 1024U);
mq->nr_entries = 2 * from_cblock(cache_size);
r = alloc_entries(mq, mq->nr_entries);
if (r)
goto bad_cache_alloc;
mq->nr_entries_allocated = 0;
mq->nr_cblocks_allocated = 0;
mq->nr_buckets = next_power(from_cblock(cache_size) / 2, 16);
mq->hash_bits = ffs(mq->nr_buckets) - 1;
mq->table = kzalloc(sizeof(*mq->table) * mq->nr_buckets, GFP_KERNEL);
if (!mq->table)
goto bad_alloc_table;
mq->allocation_bitset = alloc_bitset(from_cblock(cache_size));
if (!mq->allocation_bitset)
goto bad_alloc_bitset;
return &mq->policy;
bad_alloc_bitset:
kfree(mq->table);
bad_alloc_table:
free_entries(mq);
bad_cache_alloc:
kfree(mq);
return NULL;
}
static int __init mq_init(void)
{
int r;
mq_entry_cache = kmem_cache_create("dm_mq_policy_cache_entry",
sizeof(struct entry),
__alignof__(struct entry),
0, NULL);
if (!mq_entry_cache)
goto bad;
r = dm_cache_policy_register(&mq_policy_type);
if (r) {
DMERR("register failed %d", r);
goto bad_register_mq;
}
r = dm_cache_policy_register(&default_policy_type);
if (!r) {
DMINFO("version %u.%u.%u loaded",
mq_policy_type.version[0],
mq_policy_type.version[1],
mq_policy_type.version[2]);
return 0;
}
DMERR("register failed (as default) %d", r);
dm_cache_policy_unregister(&mq_policy_type);
bad_register_mq:
kmem_cache_destroy(mq_entry_cache);
bad:
return -ENOMEM;
}
static void __exit mq_exit(void)
{
dm_cache_policy_unregister(&mq_policy_type);
dm_cache_policy_unregister(&default_policy_type);
kmem_cache_destroy(mq_entry_cache);
}
