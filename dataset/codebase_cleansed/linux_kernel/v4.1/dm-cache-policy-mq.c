static unsigned next_power(unsigned n, unsigned min)
{
return roundup_pow_of_two(max(n, min));
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
if (bio->bi_iter.bi_sector == from_oblock(t->last_end_oblock) + 1)
t->nr_seq_samples++;
else {
if (t->nr_seq_samples) {
t->nr_seq_samples = 0;
t->nr_rand_samples = 0;
}
t->nr_rand_samples++;
}
t->last_end_oblock = to_oblock(bio_end_sector(bio) - 1);
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
q->nr_elts = 0;
q->current_writeback_sentinels = false;
q->next_writeback = 0;
for (i = 0; i < NR_QUEUE_LEVELS; i++) {
INIT_LIST_HEAD(q->qs + i);
INIT_LIST_HEAD(q->sentinels + i);
INIT_LIST_HEAD(q->sentinels + NR_QUEUE_LEVELS + i);
INIT_LIST_HEAD(q->sentinels + (2 * NR_QUEUE_LEVELS) + i);
}
}
static unsigned queue_size(struct queue *q)
{
return q->nr_elts;
}
static bool queue_empty(struct queue *q)
{
return q->nr_elts == 0;
}
static void queue_push(struct queue *q, unsigned level, struct list_head *elt)
{
q->nr_elts++;
list_add_tail(elt, q->qs + level);
}
static void queue_remove(struct queue *q, struct list_head *elt)
{
q->nr_elts--;
list_del(elt);
}
static bool is_sentinel(struct queue *q, struct list_head *h)
{
return (h >= q->sentinels) && (h < (q->sentinels + NR_SENTINELS));
}
static struct list_head *queue_peek(struct queue *q)
{
unsigned level;
struct list_head *h;
for (level = 0; level < NR_QUEUE_LEVELS; level++)
list_for_each(h, q->qs + level)
if (!is_sentinel(q, h))
return h;
return NULL;
}
static struct list_head *queue_pop(struct queue *q)
{
struct list_head *r = queue_peek(q);
if (r) {
q->nr_elts--;
list_del(r);
}
return r;
}
static struct list_head *queue_pop_old(struct queue *q)
{
unsigned level;
struct list_head *h;
for (level = 0; level < NR_QUEUE_LEVELS; level++)
list_for_each(h, q->qs + level) {
if (is_sentinel(q, h))
break;
q->nr_elts--;
list_del(h);
return h;
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
static struct list_head *writeback_sentinel(struct queue *q, unsigned level)
{
if (q->current_writeback_sentinels)
return q->sentinels + NR_QUEUE_LEVELS + level;
else
return q->sentinels + 2 * NR_QUEUE_LEVELS + level;
}
static void queue_update_writeback_sentinels(struct queue *q)
{
unsigned i;
struct list_head *h;
if (time_after(jiffies, q->next_writeback)) {
for (i = 0; i < NR_QUEUE_LEVELS; i++) {
h = writeback_sentinel(q, i);
list_del(h);
list_add_tail(h, q->qs + i);
}
q->next_writeback = jiffies + WRITEBACK_PERIOD;
q->current_writeback_sentinels = !q->current_writeback_sentinels;
}
}
static void queue_tick(struct queue *q)
{
unsigned i;
for (i = 0; i < NR_QUEUE_LEVELS; i++) {
list_del(q->sentinels + i);
list_add_tail(q->sentinels + i, q->qs + i);
}
}
static void queue_iterate_tick(struct queue *q, iter_fn fn, void *context)
{
unsigned i;
struct list_head *h;
for (i = 0; i < NR_QUEUE_LEVELS; i++) {
list_for_each_prev(h, q->qs + i) {
if (is_sentinel(q, h))
break;
fn(h, context);
}
}
}
static int epool_init(struct entry_pool *ep, unsigned nr_entries)
{
unsigned i;
ep->entries = vzalloc(sizeof(struct entry) * nr_entries);
if (!ep->entries)
return -ENOMEM;
ep->entries_end = ep->entries + nr_entries;
INIT_LIST_HEAD(&ep->free);
for (i = 0; i < nr_entries; i++)
list_add(&ep->entries[i].list, &ep->free);
ep->nr_allocated = 0;
return 0;
}
static void epool_exit(struct entry_pool *ep)
{
vfree(ep->entries);
}
static struct entry *alloc_entry(struct entry_pool *ep)
{
struct entry *e;
if (list_empty(&ep->free))
return NULL;
e = list_entry(list_pop(&ep->free), struct entry, list);
INIT_LIST_HEAD(&e->list);
INIT_HLIST_NODE(&e->hlist);
ep->nr_allocated++;
return e;
}
static struct entry *alloc_particular_entry(struct entry_pool *ep, dm_cblock_t cblock)
{
struct entry *e = ep->entries + from_cblock(cblock);
list_del_init(&e->list);
INIT_HLIST_NODE(&e->hlist);
ep->nr_allocated++;
return e;
}
static void free_entry(struct entry_pool *ep, struct entry *e)
{
BUG_ON(!ep->nr_allocated);
ep->nr_allocated--;
INIT_HLIST_NODE(&e->hlist);
list_add(&e->list, &ep->free);
}
static struct entry *epool_find(struct entry_pool *ep, dm_cblock_t cblock)
{
struct entry *e = ep->entries + from_cblock(cblock);
return !hlist_unhashed(&e->hlist) ? e : NULL;
}
static bool epool_empty(struct entry_pool *ep)
{
return list_empty(&ep->free);
}
static bool in_pool(struct entry_pool *ep, struct entry *e)
{
return e >= ep->entries && e < ep->entries_end;
}
static dm_cblock_t infer_cblock(struct entry_pool *ep, struct entry *e)
{
return to_cblock(e - ep->entries);
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
static bool any_free_cblocks(struct mq_policy *mq)
{
return !epool_empty(&mq->cache_pool);
}
static bool any_clean_cblocks(struct mq_policy *mq)
{
return !queue_empty(&mq->cache_clean);
}
static unsigned queue_level(struct entry *e)
{
return min((unsigned) ilog2(e->hit_count), NR_QUEUE_LEVELS - 1u);
}
static bool in_cache(struct mq_policy *mq, struct entry *e)
{
return in_pool(&mq->cache_pool, e);
}
static void push(struct mq_policy *mq, struct entry *e)
{
hash_insert(mq, e);
if (in_cache(mq, e))
queue_push(e->dirty ? &mq->cache_dirty : &mq->cache_clean,
queue_level(e), &e->list);
else
queue_push(&mq->pre_cache, queue_level(e), &e->list);
}
static void del(struct mq_policy *mq, struct entry *e)
{
if (in_cache(mq, e))
queue_remove(e->dirty ? &mq->cache_dirty : &mq->cache_clean, &e->list);
else
queue_remove(&mq->pre_cache, &e->list);
hash_remove(e);
}
static struct entry *pop(struct mq_policy *mq, struct queue *q)
{
struct entry *e;
struct list_head *h = queue_pop(q);
if (!h)
return NULL;
e = container_of(h, struct entry, list);
hash_remove(e);
return e;
}
static struct entry *pop_old(struct mq_policy *mq, struct queue *q)
{
struct entry *e;
struct list_head *h = queue_pop_old(q);
if (!h)
return NULL;
e = container_of(h, struct entry, list);
hash_remove(e);
return e;
}
static struct entry *peek(struct queue *q)
{
struct list_head *h = queue_peek(q);
return h ? container_of(h, struct entry, list) : NULL;
}
static void check_generation(struct mq_policy *mq)
{
unsigned total = 0, nr = 0, count = 0, level;
struct list_head *head;
struct entry *e;
if ((mq->hit_count >= mq->generation_period) && (epool_empty(&mq->cache_pool))) {
mq->hit_count = 0;
mq->generation++;
for (level = 0; level < NR_QUEUE_LEVELS && count < MAX_TO_AVERAGE; level++) {
head = mq->cache_clean.qs + level;
list_for_each_entry(e, head, list) {
nr++;
total += e->hit_count;
if (++count >= MAX_TO_AVERAGE)
break;
}
head = mq->cache_dirty.qs + level;
list_for_each_entry(e, head, list) {
nr++;
total += e->hit_count;
if (++count >= MAX_TO_AVERAGE)
break;
}
}
}
}
static void requeue(struct mq_policy *mq, struct entry *e)
{
check_generation(mq);
del(mq, e);
push(mq, e);
}
static int demote_cblock(struct mq_policy *mq, dm_oblock_t *oblock)
{
struct entry *demoted = pop(mq, &mq->cache_clean);
if (!demoted)
return -ENOSPC;
*oblock = demoted->oblock;
free_entry(&mq->cache_pool, demoted);
return 0;
}
static unsigned promote_threshold(struct mq_policy *mq)
{
struct entry *e;
if (any_free_cblocks(mq))
return 0;
e = peek(&mq->cache_clean);
if (e)
return e->hit_count;
e = peek(&mq->cache_dirty);
if (e)
return e->hit_count + DISCOURAGE_DEMOTING_DIRTY_THRESHOLD;
return 0;
}
static unsigned adjusted_promote_threshold(struct mq_policy *mq,
bool discarded_oblock, int data_dir)
{
if (data_dir == READ)
return promote_threshold(mq) + mq->read_promote_adjustment;
if (discarded_oblock && (any_free_cblocks(mq) || any_clean_cblocks(mq))) {
return mq->discard_promote_adjustment;
}
return promote_threshold(mq) + mq->write_promote_adjustment;
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
requeue(mq, e);
if (in_cache(mq, e)) {
result->op = POLICY_HIT;
result->cblock = infer_cblock(&mq->cache_pool, e);
}
return 0;
}
static int pre_cache_to_cache(struct mq_policy *mq, struct entry *e,
struct policy_result *result)
{
int r;
struct entry *new_e;
if (epool_empty(&mq->cache_pool)) {
result->op = POLICY_REPLACE;
r = demote_cblock(mq, &result->old_oblock);
if (r) {
result->op = POLICY_MISS;
return 0;
}
} else
result->op = POLICY_NEW;
new_e = alloc_entry(&mq->cache_pool);
BUG_ON(!new_e);
new_e->oblock = e->oblock;
new_e->dirty = false;
new_e->hit_count = e->hit_count;
del(mq, e);
free_entry(&mq->pre_cache_pool, e);
push(mq, new_e);
result->cblock = infer_cblock(&mq->cache_pool, new_e);
return 0;
}
static int pre_cache_entry_found(struct mq_policy *mq, struct entry *e,
bool can_migrate, bool discarded_oblock,
int data_dir, struct policy_result *result)
{
int r = 0;
if (!should_promote(mq, e, discarded_oblock, data_dir)) {
requeue(mq, e);
result->op = POLICY_MISS;
} else if (!can_migrate)
r = -EWOULDBLOCK;
else {
requeue(mq, e);
r = pre_cache_to_cache(mq, e, result);
}
return r;
}
static void insert_in_pre_cache(struct mq_policy *mq,
dm_oblock_t oblock)
{
struct entry *e = alloc_entry(&mq->pre_cache_pool);
if (!e)
e = pop(mq, &mq->pre_cache);
if (unlikely(!e)) {
DMWARN("couldn't pop from pre cache");
return;
}
e->dirty = false;
e->oblock = oblock;
e->hit_count = 1;
push(mq, e);
}
static void insert_in_cache(struct mq_policy *mq, dm_oblock_t oblock,
struct policy_result *result)
{
int r;
struct entry *e;
if (epool_empty(&mq->cache_pool)) {
result->op = POLICY_REPLACE;
r = demote_cblock(mq, &result->old_oblock);
if (unlikely(r)) {
result->op = POLICY_MISS;
insert_in_pre_cache(mq, oblock);
return;
}
e = alloc_entry(&mq->cache_pool);
BUG_ON(!e);
} else {
e = alloc_entry(&mq->cache_pool);
result->op = POLICY_NEW;
}
e->oblock = oblock;
e->dirty = false;
e->hit_count = 1;
push(mq, e);
result->cblock = infer_cblock(&mq->cache_pool, e);
}
static int no_entry_found(struct mq_policy *mq, dm_oblock_t oblock,
bool can_migrate, bool discarded_oblock,
int data_dir, struct policy_result *result)
{
if (adjusted_promote_threshold(mq, discarded_oblock, data_dir) <= 1) {
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
if (e && in_cache(mq, e))
r = cache_entry_found(mq, e, result);
else if (mq->tracker.thresholds[PATTERN_SEQUENTIAL] &&
iot_pattern(&mq->tracker) == PATTERN_SEQUENTIAL)
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
vfree(mq->table);
epool_exit(&mq->cache_pool);
epool_exit(&mq->pre_cache_pool);
kfree(mq);
}
static void update_pre_cache_hits(struct list_head *h, void *context)
{
struct entry *e = container_of(h, struct entry, list);
e->hit_count++;
}
static void update_cache_hits(struct list_head *h, void *context)
{
struct mq_policy *mq = context;
struct entry *e = container_of(h, struct entry, list);
e->hit_count++;
mq->hit_count++;
}
static void copy_tick(struct mq_policy *mq)
{
unsigned long flags, tick;
spin_lock_irqsave(&mq->tick_lock, flags);
tick = mq->tick_protected;
if (tick != mq->tick) {
queue_iterate_tick(&mq->pre_cache, update_pre_cache_hits, mq);
queue_iterate_tick(&mq->cache_dirty, update_cache_hits, mq);
queue_iterate_tick(&mq->cache_clean, update_cache_hits, mq);
mq->tick = tick;
}
queue_tick(&mq->pre_cache);
queue_tick(&mq->cache_dirty);
queue_tick(&mq->cache_clean);
queue_update_writeback_sentinels(&mq->cache_dirty);
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
if (e && in_cache(mq, e)) {
*cblock = infer_cblock(&mq->cache_pool, e);
r = 0;
} else
r = -ENOENT;
mutex_unlock(&mq->lock);
return r;
}
static void __mq_set_clear_dirty(struct mq_policy *mq, dm_oblock_t oblock, bool set)
{
struct entry *e;
e = hash_lookup(mq, oblock);
BUG_ON(!e || !in_cache(mq, e));
del(mq, e);
e->dirty = set;
push(mq, e);
}
static void mq_set_dirty(struct dm_cache_policy *p, dm_oblock_t oblock)
{
struct mq_policy *mq = to_mq_policy(p);
mutex_lock(&mq->lock);
__mq_set_clear_dirty(mq, oblock, true);
mutex_unlock(&mq->lock);
}
static void mq_clear_dirty(struct dm_cache_policy *p, dm_oblock_t oblock)
{
struct mq_policy *mq = to_mq_policy(p);
mutex_lock(&mq->lock);
__mq_set_clear_dirty(mq, oblock, false);
mutex_unlock(&mq->lock);
}
static int mq_load_mapping(struct dm_cache_policy *p,
dm_oblock_t oblock, dm_cblock_t cblock,
uint32_t hint, bool hint_valid)
{
struct mq_policy *mq = to_mq_policy(p);
struct entry *e;
e = alloc_particular_entry(&mq->cache_pool, cblock);
e->oblock = oblock;
e->dirty = false;
e->hit_count = hint_valid ? hint : 1;
push(mq, e);
return 0;
}
static int mq_save_hints(struct mq_policy *mq, struct queue *q,
policy_walk_fn fn, void *context)
{
int r;
unsigned level;
struct list_head *h;
struct entry *e;
for (level = 0; level < NR_QUEUE_LEVELS; level++)
list_for_each(h, q->qs + level) {
if (is_sentinel(q, h))
continue;
e = container_of(h, struct entry, list);
r = fn(context, infer_cblock(&mq->cache_pool, e),
e->oblock, e->hit_count);
if (r)
return r;
}
return 0;
}
static int mq_walk_mappings(struct dm_cache_policy *p, policy_walk_fn fn,
void *context)
{
struct mq_policy *mq = to_mq_policy(p);
int r = 0;
mutex_lock(&mq->lock);
r = mq_save_hints(mq, &mq->cache_clean, fn, context);
if (!r)
r = mq_save_hints(mq, &mq->cache_dirty, fn, context);
mutex_unlock(&mq->lock);
return r;
}
static void __remove_mapping(struct mq_policy *mq, dm_oblock_t oblock)
{
struct entry *e;
e = hash_lookup(mq, oblock);
BUG_ON(!e || !in_cache(mq, e));
del(mq, e);
free_entry(&mq->cache_pool, e);
}
static void mq_remove_mapping(struct dm_cache_policy *p, dm_oblock_t oblock)
{
struct mq_policy *mq = to_mq_policy(p);
mutex_lock(&mq->lock);
__remove_mapping(mq, oblock);
mutex_unlock(&mq->lock);
}
static int __remove_cblock(struct mq_policy *mq, dm_cblock_t cblock)
{
struct entry *e = epool_find(&mq->cache_pool, cblock);
if (!e)
return -ENODATA;
del(mq, e);
free_entry(&mq->cache_pool, e);
return 0;
}
static int mq_remove_cblock(struct dm_cache_policy *p, dm_cblock_t cblock)
{
int r;
struct mq_policy *mq = to_mq_policy(p);
mutex_lock(&mq->lock);
r = __remove_cblock(mq, cblock);
mutex_unlock(&mq->lock);
return r;
}
static bool clean_target_met(struct mq_policy *mq)
{
unsigned nr_clean = from_cblock(mq->cache_size) - queue_size(&mq->cache_dirty);
unsigned target = from_cblock(mq->cache_size) * CLEAN_TARGET_PERCENTAGE / 100;
return nr_clean >= target;
}
static int __mq_writeback_work(struct mq_policy *mq, dm_oblock_t *oblock,
dm_cblock_t *cblock)
{
struct entry *e = pop_old(mq, &mq->cache_dirty);
if (!e && !clean_target_met(mq))
e = pop(mq, &mq->cache_dirty);
if (!e)
return -ENODATA;
*oblock = e->oblock;
*cblock = infer_cblock(&mq->cache_pool, e);
e->dirty = false;
push(mq, e);
return 0;
}
static int mq_writeback_work(struct dm_cache_policy *p, dm_oblock_t *oblock,
dm_cblock_t *cblock)
{
int r;
struct mq_policy *mq = to_mq_policy(p);
mutex_lock(&mq->lock);
r = __mq_writeback_work(mq, oblock, cblock);
mutex_unlock(&mq->lock);
return r;
}
static void __force_mapping(struct mq_policy *mq,
dm_oblock_t current_oblock, dm_oblock_t new_oblock)
{
struct entry *e = hash_lookup(mq, current_oblock);
if (e && in_cache(mq, e)) {
del(mq, e);
e->oblock = new_oblock;
e->dirty = true;
push(mq, e);
}
}
static void mq_force_mapping(struct dm_cache_policy *p,
dm_oblock_t current_oblock, dm_oblock_t new_oblock)
{
struct mq_policy *mq = to_mq_policy(p);
mutex_lock(&mq->lock);
__force_mapping(mq, current_oblock, new_oblock);
mutex_unlock(&mq->lock);
}
static dm_cblock_t mq_residency(struct dm_cache_policy *p)
{
dm_cblock_t r;
struct mq_policy *mq = to_mq_policy(p);
mutex_lock(&mq->lock);
r = to_cblock(mq->cache_pool.nr_allocated);
mutex_unlock(&mq->lock);
return r;
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
unsigned long tmp;
if (kstrtoul(value, 10, &tmp))
return -EINVAL;
if (!strcasecmp(key, "random_threshold")) {
mq->tracker.thresholds[PATTERN_RANDOM] = tmp;
} else if (!strcasecmp(key, "sequential_threshold")) {
mq->tracker.thresholds[PATTERN_SEQUENTIAL] = tmp;
} else if (!strcasecmp(key, "discard_promote_adjustment"))
mq->discard_promote_adjustment = tmp;
else if (!strcasecmp(key, "read_promote_adjustment"))
mq->read_promote_adjustment = tmp;
else if (!strcasecmp(key, "write_promote_adjustment"))
mq->write_promote_adjustment = tmp;
else
return -EINVAL;
return 0;
}
static int mq_emit_config_values(struct dm_cache_policy *p, char *result, unsigned maxlen)
{
ssize_t sz = 0;
struct mq_policy *mq = to_mq_policy(p);
DMEMIT("10 random_threshold %u "
"sequential_threshold %u "
"discard_promote_adjustment %u "
"read_promote_adjustment %u "
"write_promote_adjustment %u",
mq->tracker.thresholds[PATTERN_RANDOM],
mq->tracker.thresholds[PATTERN_SEQUENTIAL],
mq->discard_promote_adjustment,
mq->read_promote_adjustment,
mq->write_promote_adjustment);
return 0;
}
static void init_policy_functions(struct mq_policy *mq)
{
mq->policy.destroy = mq_destroy;
mq->policy.map = mq_map;
mq->policy.lookup = mq_lookup;
mq->policy.set_dirty = mq_set_dirty;
mq->policy.clear_dirty = mq_clear_dirty;
mq->policy.load_mapping = mq_load_mapping;
mq->policy.walk_mappings = mq_walk_mappings;
mq->policy.remove_mapping = mq_remove_mapping;
mq->policy.remove_cblock = mq_remove_cblock;
mq->policy.writeback_work = mq_writeback_work;
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
struct mq_policy *mq = kzalloc(sizeof(*mq), GFP_KERNEL);
if (!mq)
return NULL;
init_policy_functions(mq);
iot_init(&mq->tracker, SEQUENTIAL_THRESHOLD_DEFAULT, RANDOM_THRESHOLD_DEFAULT);
mq->cache_size = cache_size;
if (epool_init(&mq->pre_cache_pool, from_cblock(cache_size))) {
DMERR("couldn't initialize pool of pre-cache entries");
goto bad_pre_cache_init;
}
if (epool_init(&mq->cache_pool, from_cblock(cache_size))) {
DMERR("couldn't initialize pool of cache entries");
goto bad_cache_init;
}
mq->tick_protected = 0;
mq->tick = 0;
mq->hit_count = 0;
mq->generation = 0;
mq->discard_promote_adjustment = DEFAULT_DISCARD_PROMOTE_ADJUSTMENT;
mq->read_promote_adjustment = DEFAULT_READ_PROMOTE_ADJUSTMENT;
mq->write_promote_adjustment = DEFAULT_WRITE_PROMOTE_ADJUSTMENT;
mutex_init(&mq->lock);
spin_lock_init(&mq->tick_lock);
queue_init(&mq->pre_cache);
queue_init(&mq->cache_clean);
queue_init(&mq->cache_dirty);
mq->generation_period = max((unsigned) from_cblock(cache_size), 1024U);
mq->nr_buckets = next_power(from_cblock(cache_size) / 2, 16);
mq->hash_bits = ffs(mq->nr_buckets) - 1;
mq->table = vzalloc(sizeof(*mq->table) * mq->nr_buckets);
if (!mq->table)
goto bad_alloc_table;
return &mq->policy;
bad_alloc_table:
epool_exit(&mq->cache_pool);
bad_cache_init:
epool_exit(&mq->pre_cache_pool);
bad_pre_cache_init:
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
